"""Complete cumulative payload: stop failed AppMain static initialization."""
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path
from patch_startup_failure import patch
from verify_startup_failure import verify, structure
from verify_shared_mapping_checks import verify as verify_mapping, relocation_contracts
from audit_appmain_relocation_runtime import check as check_ipc
from verify_media_responsiveness import verify_touch, verify_performance
from verify_appmain_label_scan import verify as verify_arabic
from build_bt_eight_test import verify as verify_pairing

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/shared-mapping-development-01'
OUT=ROOT/'build/startup-failure-development-01'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
PROOF=ROOT/'analysis/firmware/startup-failure-development.json'
APP='upgrade/Storage Card/System/AppMain.exe'
BLUE='upgrade/Storage Card/System/Blue.exe'
USB='upgrade/Storage Card/System/MgrUSB.exe'

def sha(raw):return hashlib.sha256(raw).hexdigest()

def main():
    assert not OUT.exists() and not PROOF.exists(), 'Preserve previous builds and proofs'
    previous_bytes=(BASE/'manifest.json').read_bytes();previous=json.loads(previous_bytes)
    for name,digest in previous['tools'].items():
        assert sha((ROOT/'tools'/name).read_bytes())==digest
    assert sha((ROOT/previous['proof']['path']).read_bytes())==previous['proof']['sha256']
    audits={}
    for name,tool in (('appmain-relocation-runtime-audit','audit_appmain_relocation_runtime.py'),
                      ('usb-save-notification-state-audit','audit_usb_save_notification_state.py')):
        path=ROOT/'analysis/firmware'/f'{name}.json';raw=path.read_bytes();audit=json.loads(raw)
        assert sha((ROOT/'tools'/tool).read_bytes())==audit['tool_sha256']
        audits[name]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(raw),cases=audit['cases'],output_sha256=audit['output_sha256'])
    release=json.loads((RELEASE/'build-manifest.json').read_bytes())
    released={r['path']:r for r in release['verification']['members']}
    lgu_sha=sha((RELEASE/'upgrade.lgu').read_bytes())
    assert lgu_sha==release['verification']['lgu_sha256']
    before={}
    for row in previous['members']:
        name=row['path'];assert name.startswith('upgrade/') and '..' not in Path(name).parts
        raw=(BASE/'payload'/name).read_bytes()
        assert len(raw)==row['bytes'] and sha(raw)==row['sha256'];before[name]=raw
    assert len(before)==1918 and set(before)==set(released)
    assert audits['appmain-relocation-runtime-audit']['output_sha256']==sha(before[APP])
    assert audits['usb-save-notification-state-audit']['output_sha256']==sha(before[USB])
    after=before.copy();after[APP],recipe=patch(before[APP])
    for name,raw in after.items():
        target=OUT/'payload'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(raw)
    readback={p.relative_to(OUT/'payload').as_posix():p.read_bytes() for p in (OUT/'payload').rglob('*') if p.is_file()}
    assert readback==after
    print('All 1,918 files read back; testing startup failures and healthy CRT traversal',flush=True)
    checks=dict(startup=verify(before[APP],readback[APP]),structure=structure(before[APP],readback[APP],recipe))
    assert checks['startup']['cases']==157
    print('158 startup/structure cases passed; testing retained mapping and IPC behavior',flush=True)
    mapping_base=(ROOT/'build/usb-save-feedback-development-01/payload'/APP).read_bytes()
    ipc=[check_ipc(readback[APP],delta,kind,mode,scenario) for delta in (0,0x10000,0x120000,0x500000)
         for kind in (1,2) for mode in (1,2) for scenario in ('success','error','timeout','retry','disabled','invalid')]
    retained=dict(mapping=verify_mapping(mapping_base,readback[APP]),relocation=relocation_contracts(readback[APP]),ipc=dict(cases=len(ipc),traces=ipc))
    print('Retained mapping/IPC passed; testing Bluetooth, touch and text processing',flush=True)
    old_app=(ROOT/'build/updater-copy-safety-development-02/payload'/APP).read_bytes()
    original=(ROOT/'extracted/705md'/APP).read_bytes()
    pairing=verify_pairing(readback[BLUE],readback[APP])
    retained.update(pairing=pairing,touch=verify_touch(old_app,readback[APP]),
                    hebrew=verify_performance(old_app,readback[APP],exhaustive=False),
                    arabic=verify_arabic(original,readback[APP],exhaustive=False))
    assert retained['mapping']['cases']==124 and len(ipc)==96
    assert retained['relocation']['execution_cases']==96 and retained['relocation']['instruction_cases']==1872
    unchanged=dict(usb_sha256=sha(readback[USB]),previous_proof=previous['proof'],
                   inherited_evidence=previous['unchanged_usb_evidence'],additional_audits=audits,
                   unchanged_usb_proofs_rerun=False)
    proof=dict(recipe=recipe,checks=checks,retained_readback_checks=retained,unchanged_usb_evidence=unchanged,
               native_executed=False,hardware_tested=False,native_loader_tested=False)
    PROOF.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    changed=[p for p in before if before[p]!=readback[p]];assert changed==[APP]
    modified=[p for p in readback if sha(readback[p])!=released[p]['sha256']];assert len(modified)==6
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
        kind='Full cumulative development; not an installable update or release',previous_release='7.0.6.MAX03',
        previous_lgu_sha256=lgu_sha,previous_development=BASE.name,carried_forward_manifest_sha256=sha(previous_bytes),
        previous_members=1918,output_members=1918,missing_members=[],added_members=[],changed_from_development=changed,
        unchanged_from_development=1917,modified_from_published_release=modified,unchanged_from_published_release=1912,
        recipe=recipe,readback_checks=checks,retained_readback_checks=retained,new_behavior_cases=158,
        retained_pairing_cases=sum(len(v) for v in pairing.values()),unchanged_usb_evidence=unchanged,
        proof=dict(path=PROOF.relative_to(ROOT).as_posix(),sha256=sha(PROOF.read_bytes())),
        tools={n:sha((ROOT/'tools'/n).read_bytes()) for n in ('patch_startup_failure.py','verify_startup_failure.py','build_startup_failure_development.py')},
        native_executed=False,hardware_tested=False,installation_ready=False,native_loader_tested=False,
        release_built=False,version_bumped=False,concurrency_fixed=False,automatic_restart_implemented=False,
        members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),previous_release_sha256=released[p]['sha256'],previous_development_sha256=sha(before[p])) for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text('# AppMain startup failure development\n\n'
        'Complete cumulative payload: all 1,918 previous files and improvements retained. Only AppMain changes. '
        'Mapping or allocation failure now stops the static-initializer sequence, clears unpublished globals, '
        'cleans partially acquired mappings and requests termination of AppMain. Healthy startup is preserved. '
        'No automatic unit restart is implemented.\n\n'
        '158 startup/structure cases pass on interpreted written bytes, alongside retained mapping, relocation, '
        'IPC, Bluetooth, touch and text checks. Other static constructors and CE APIs use fixtures. '
        'MgrUSB is byte-identical; its prior proofs were retained, not rerun.\n\n'
        'No LGU, version bump or release. Native loading, process teardown, unit behavior and installation '
        'remain unverified. Shared USB snapshot/cover ownership remains open. '
        'See analysis/startup-failure-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu_sha
    assert all((BASE/'payload'/p).read_bytes()==raw for p,raw in before.items())
    print(json.dumps(dict(output=str(OUT),members=1918,app_sha256=sha(readback[APP]),new_behavior_cases=158,
        retained_mapping_cases=124,retained_ipc_cases=96,retained_pairing_cases=result['retained_pairing_cases'],
        retained_touch_cases=retained['touch']['cases'],retained_hebrew_cases=retained['hebrew']['mixed_cases'],
        retained_arabic_cases=retained['arabic']['multi_unit_cases'],release_built=False),indent=2),flush=True)

if __name__=='__main__':main()
