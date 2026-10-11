"""Build a complete local artwork and text-recovery test LGU; never publish or flash.

Require the exact complete MAX05 baseline, deterministic candidate PEs and a
current installed-byte verification report. MAX06 sorts after installed MAX05.
"""
import argparse
from datetime import datetime,timezone
import hashlib
import json
from pathlib import Path
from types import FunctionType

import pefile
import build_review_update as container
from build_maxmade_update import version_model
from build_max05_candidate import tree,VERSION
from stage_artwork_feedback_inputs import ROOT,BLUE,APP,LGU_SHA,expected_members
from patch_bt_cover_install import patch as artwork_patch
from patch_bt_text_recovery_install import patch as text_patch

REVISION='7.0.6.MAX06'
LGU_BYTES=37230937


def sha(raw):return hashlib.sha256(raw).hexdigest()


def write_json(path,value):path.write_bytes((json.dumps(value,indent=2)+'\n').encode())


def build(baseline,baseline_lgu,blue,app,evidence,dispatch_evidence,uid_evidence,out,pc_tools):
    baseline,baseline_lgu,out=baseline.resolve(),baseline_lgu.resolve(),out.resolve()
    if out.exists():raise FileExistsError('Use a fresh output')
    if not out.is_relative_to(ROOT/'build') or out==ROOT/'build':
        raise ValueError('Output must be a fresh child of ignored build')
    for path in (baseline,baseline_lgu,blue.resolve(),app.resolve(),evidence.resolve(),dispatch_evidence.resolve(),uid_evidence.resolve(),pc_tools.resolve()):
        if path.is_relative_to(out) or out.is_relative_to(path):raise ValueError('Input/output overlap')
    original_lgu=baseline_lgu.read_bytes()
    if (len(original_lgu),sha(original_lgu))!=(LGU_BYTES,LGU_SHA):raise ValueError('Unpinned original MAX05 LGU')
    previous=expected_members();tree(baseline,previous)
    writer,extractor=(pc_tools.resolve()/n for n in ('dir2lgu.exe','lgu2dir.exe'))
    for tool,pin in ((writer,container.WRITER_HASH),(extractor,container.EXTRACTOR_HASH)):
        if sha(tool.read_bytes())!=pin or pefile.PE(str(tool)).FILE_HEADER.Machine!=0x14c:
            raise ValueError('Unpinned PC container tool: '+tool.name)
    recognition=version_model(REVISION)
    recognition += [dict(current=v,offered=REVISION,ordinary_update_offered=REVISION>v,
                         native_installation_tested=False) for v in ('7.0.6.MAX04','7.0.6.MAX05')]
    assert all(r['ordinary_update_offered'] for r in recognition)
    proof=json.loads(evidence.read_bytes())
    assert proof['cases']==36 and not proof['hardware_tested']
    assert len(proof['text_traces'])==9 and len(proof['artwork_traces'])==6
    assert len(proof['retry_traces'])==16 and len(proof['shutdown_traces'])==5
    assert proof['inspection']['helpers']==117 and proof['inspection']['new_helpers']==27
    for name,pin in proof['source_pins'].items():
        if sha((ROOT/'tools'/name).read_bytes())!=pin:raise ValueError('Stale integration evidence: '+name)
    dispatch=json.loads(dispatch_evidence.read_bytes())
    assert dispatch['cases']==4 and not dispatch['hardware_tested']
    assert dispatch['candidate_sha256']==proof['inspection']['candidate_sha256']
    for name,pin in dispatch['source_pins'].items():
        if sha((ROOT/'tools'/name).read_bytes())!=pin:raise ValueError('Stale native dispatch evidence: '+name)
    replacements={VERSION:REVISION.encode('ascii')};recipes={}
    for member,path in ((BLUE,blue),(APP,app)):
        original=(baseline/member).read_bytes()
        if member==BLUE:
            expected,recipe=text_patch(original)
            _,artwork_recipe=artwork_patch('Blue.exe',original)
            recipe['feedback']=artwork_recipe['feedback']
        else:expected,recipe=artwork_patch('AppMain.exe',original)
        actual=path.read_bytes()
        if actual!=expected:raise ValueError('Candidate differs from reviewed composition: '+member)
        assert (proof['inspection']['candidate_sha256'] if member==BLUE else proof['app_candidate_sha256'])==sha(actual)
        replacements[member]=actual;recipes[member]=recipe
    interim_path=ROOT/'analysis/firmware/bt-metadata-interim.json'
    interim=json.loads(interim_path.read_bytes())
    assert interim['cases']==96 and interim['fragmented_after']['stalled_cases']==0
    assert interim['recipe']==next(r['recipe'] for r in recipes[BLUE]['feedback']['components']
                                  if r['component']=='metadata-interim-progress')
    for name,pin in interim['source_pins'].items():
        if sha((ROOT/'tools'/name).read_bytes())!=pin:raise ValueError('Stale interim evidence: '+name)
    uid_path=uid_evidence
    uid=json.loads(uid_path.read_bytes())
    assert uid['cases']==114 and uid['installed_candidate_executed']
    assert uid['candidate_sha256']==sha(replacements[BLUE])
    assert uid['recipe']==next(r['recipe'] for r in recipes[BLUE]['feedback']['components']
                              if r['component']=='metadata-uid-width')
    for name,pin in uid['source_pins'].items():
        if sha((ROOT/'tools'/name).read_bytes())!=pin:raise ValueError('Stale UID evidence: '+name)
    rows=[dict(path=name,before=old,after=(dict(bytes=len(replacements[name]),sha256=sha(replacements[name]))
              if name in replacements else old)) for name,old in sorted(previous.items())]
    changed=[r['path'] for r in rows if r['before']!=r['after']]
    assert changed==sorted((APP,BLUE,VERSION))
    expected={r['path']:r['after'] for r in rows};out.mkdir(parents=True)
    for name in expected:
        target=out/'payload'/name;target.parent.mkdir(parents=True,exist_ok=True)
        target.write_bytes(replacements[name] if name in replacements else (baseline/name).read_bytes())
    tree(out/'payload',expected)
    write_json(out/'member-plan.json',dict(member_count=len(rows),members=rows,changed_members=changed,
                                        retained_members=1915,missing_members=[],added_members=[]))
    write_json(out/'native-recipes.json',recipes)
    (out/'installed-byte-verification.json').write_bytes(evidence.read_bytes())
    (out/'native-dispatch-verification.json').write_bytes(dispatch_evidence.read_bytes())
    (out/'interim-metadata-verification.json').write_bytes(interim_path.read_bytes())
    (out/'uid-metadata-verification.json').write_bytes(uid_path.read_bytes())
    runs=[container.run_pc_tool(writer,['-p','m1',REVISION,out/'payload',out/'upgrade.lgu'],out/'dir2lgu.log')]
    key=bytes.fromhex(json.loads((ROOT/'src/container/lgu0.json').read_bytes())['xor_hex'])
    assert len(key)==1024
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    verification=verify(out/'upgrade.lgu',expected,REVISION)
    runs.append(container.run_pc_tool(extractor,[out/'upgrade.lgu',out/'roundtrip'],out/'lgu2dir.log'))
    tree(out/'roundtrip',expected);tree(out/'payload',expected);tree(baseline,previous)
    assert baseline_lgu.read_bytes()==original_lgu
    for run in runs:run.pop('command',None)
    sources=('build_bt_text_recovery_candidate.py','patch_bt_text_recovery_install.py',
             'verify_bt_text_recovery_install.py','verify_bt_text_recovery_dispatch.py','bt_text_metadata_retry.py','bt_text_metadata_shutdown.py',
             'patch_bt_cover_install.py','verify_bt_cover_install.py',
             'layout_bt_cover_native.py','stage_artwork_feedback_inputs.py','build_review_update.py',
             'build_maxmade_update.py','build_max05_candidate.py','release_payload.py')
    report=dict(generated_utc=datetime.now(timezone.utc).isoformat(),revision=REVISION,
                candidate_kind='LOCAL FULL ARTWORK AND TEXT RECOVERY TEST CANDIDATE',published=False,flashed=False,
                hardware_tested=False,installation_tested=False,native_executed=False,
                previous_revision='7.0.6.MAX05',previous_lgu_sha256=LGU_SHA,original_lgu_unchanged=True,
                output_members=len(expected),changed_from_max05=changed,unchanged_from_max05=1915,
                missing_members=[],added_members=[],artwork_helpers_in_lgu=True,text_recovery_helpers_in_lgu=True,
                owned_streaming_text=True,max_text_retries=2,retry_delays_ms=[500,1500],
                native_quiescent_shutdown_checked=True,
                retained_max05_usb_runtime=True,os_boot_mcu_navigation_settings_unchanged_from_max05=True,
                integration_cases=proof['cases'],native_dispatch_cases=dispatch['cases'],
                native_dispatch_evidence_sha256=sha(dispatch_evidence.read_bytes()),integration_evidence_sha256=sha(evidence.read_bytes()),
                integration_evidence_reused_by_source_and_binary_hashes=True,
                interim_metadata_cases=interim['cases'],interim_metadata_evidence_sha256=sha(interim_path.read_bytes()),
                uid_metadata_cases=uid['cases'],uid_metadata_evidence_sha256=sha(uid_path.read_bytes()),
                version_recognition_model=recognition,header_and_displayed_version_match=True,
                writer=runs[0],extractor=runs[1],verification=verification,pc_extractor_matches=1918,
                source_pins={n:sha((ROOT/'tools'/n).read_bytes()) for n in sources},
                member_plan_sha256=sha((out/'member-plan.json').read_bytes()),
                limitations=['Container/readback and instruction fixtures do not prove device installation or runtime',
                             'Actual CE loader/unwind, phone artwork support, codec and scheduling need hardware testing',
                             'PCM reserve and failed-metadata repair do not establish complete stutter or No Title recovery',
                             'Full package retains OS/boot/MCU update files and settings from MAX05'])
    write_json(out/'build-manifest.json',report)
    (out/'SHA256SUMS.txt').write_bytes((verification['lgu_sha256']+'  upgrade.lgu\n').encode('ascii'))
    return report


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('baseline','baseline-lgu','blue','app','evidence','dispatch-evidence','uid-evidence','out','pc-tools'):
        p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();r=build(a.baseline,a.baseline_lgu,a.blue,a.app,a.evidence,a.dispatch_evidence,a.uid_evidence,a.out,a.pc_tools)
    print(json.dumps(dict(revision=r['revision'],members=r['output_members'],retained=r['unchanged_from_max05'],
                          changed=r['changed_from_max05'],sha256=r['verification']['lgu_sha256'],
                          bytes=r['verification']['bytes'],published=False,hardware_tested=False),indent=2))
