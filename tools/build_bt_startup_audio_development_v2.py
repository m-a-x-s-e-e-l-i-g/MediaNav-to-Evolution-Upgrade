"""Build a complete cumulative internal development with startup audio recovery."""
import hashlib
import json
from datetime import datetime,timezone
from pathlib import Path
from patch_bt_startup_audio_v2 import patch
from verify_bt_startup_audio_v2 import verify
from build_bt_eight_test import verify as pairing_verify

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/bt-startup-audio-development-01'
OUT=ROOT/'build/bt-startup-audio-development-02'
PROOF=ROOT/'analysis/firmware/bt-startup-audio-development-v2.json'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
BLUE='upgrade/Storage Card/System/Blue.exe'
APP='upgrade/Storage Card/System/AppMain.exe'

def sha(raw):return hashlib.sha256(raw).hexdigest()

def main():
    assert not OUT.exists() and not PROOF.exists(),'Preserve finished and interrupted artifacts'
    old_manifest=(BASE/'manifest.json').read_bytes();previous=json.loads(old_manifest)
    for name,digest in previous['tools'].items():
        assert sha((ROOT/'tools'/name).read_bytes())==digest
    old_proof=(ROOT/previous['proof']['path']).read_bytes()
    assert sha(old_proof)==previous['proof']['sha256']
    released=json.loads((RELEASE/'build-manifest.json').read_bytes())
    public_members={r['path']:r for r in released['verification']['members']}
    lgu_hash=sha((RELEASE/'upgrade.lgu').read_bytes())
    assert lgu_hash==released['verification']['lgu_sha256']
    before={}
    for row in previous['members']:
        name=row['path'];assert name.startswith('upgrade/') and '..' not in Path(name).parts
        raw=(BASE/'payload'/name).read_bytes()
        assert len(raw)==row['bytes'] and sha(raw)==row['sha256']
        before[name]=raw
    assert len(before)==1918 and set(before)==set(public_members)
    after=before.copy();after[BLUE],recipe=patch(before[BLUE],previous['recipes']['bluetooth_startup'])
    print('Prior member/tool/proof/LGU pins passed; writing all 1,918 files',flush=True)
    for name,raw in after.items():
        path=OUT/'payload'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(raw)
    readback={p.relative_to(OUT/'payload').as_posix():p.read_bytes()
              for p in (OUT/'payload').rglob('*') if p.is_file()}
    assert readback==after
    print('Checking actual written Blue: structure, startup/failure/ownership and retained playback',flush=True)
    original=(ROOT/'build/usb-option-snapshot-development-01/payload'/BLUE).read_bytes()
    revised=verify(original,before[BLUE],readback[BLUE],recipe,json.loads(old_proof))
    checks=dict(structure=revised['structure'],behavior=revised,playback=revised['retained_playback'])
    print('Startup/audio checks passed; checking matched Bluetooth storage/GUI/ACK/HFP pair',flush=True)
    pairing=pairing_verify(readback[BLUE],readback[APP])
    pairing_count=sum(len(value) for value in pairing.values())
    assert pairing_count==824
    changed=[name for name in before if before[name]!=readback[name]]
    assert changed==[BLUE] and len(before)-len(changed)==1917
    # AppMain/MgrUSB/all prior fixes remain byte-identical, retaining their
    # completed evidence by exact prior member/manifest/proof hashes.
    carried=dict(previous_manifest_sha256=sha(old_manifest),proof=previous['proof'],
        reason='Only Blue startup/open/start/START-case/status bytes changed; 1,917 prior files and retained Blue PCM/callback/close/storage ranges preserved',
        app_sha256=sha(readback[APP]),previous_tools=previous['tools'])
    tool_names=('patch_bt_startup_audio_v2.py','verify_bt_startup_audio_v2.py','build_bt_startup_audio_development_v2.py')
    dependency_names=('patch_bt_startup_audio.py','verify_bt_startup_audio.py','build_bt_startup_audio_development.py','audit_bt_startup_silence.py','audit_bt_stream_start.py','inspect_wave_queue.py',
        'inspect_bt_lifecycle.py','inspect_bt_playback.py','verify_bt_patch.py','patch_bt_playback.py','build_bt_eight_test.py')
    pins={name:sha((ROOT/'tools'/name).read_bytes()) for name in tool_names+dependency_names}
    proof=dict(recipe=recipe,new_checks=checks,retained_pairing=pairing,
        retained_pairing_cases=pairing_count,carried=carried,tools=pins,
        native_executed=False,hardware_tested=False,native_timing_measured=False)
    PROOF.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    recipes=previous['recipes'].copy();recipes['bluetooth_startup']=recipe['active_recipe'];recipes['bluetooth_startup_revision']=recipe
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
        kind='Complete cumulative internal development; not an LGU/release',
        previous_release='7.0.6.MAX03',previous_lgu_sha256=lgu_hash,
        previous_development=BASE.name,carried_forward_manifest_sha256=sha(old_manifest),
        previous_members=1918,output_members=1918,missing_members=[],added_members=[],
        changed_from_development=changed,unchanged_from_development=1917,recipes=recipes,
        new_behavior_cases=checks['behavior']['cases'],new_structure_cases=checks['structure']['cases'],
        playback=checks['playback'],retained_pairing_cases=pairing_count,carried=carried,
        proof=dict(path=PROOF.relative_to(ROOT).as_posix(),sha256=sha(PROOF.read_bytes())),tools=pins,
        native_executed=False,hardware_tested=False,native_loader_tested=False,
        installation_ready=False,release_built=False,version_bumped=False,
        members=[dict(path=name,bytes=len(raw),sha256=sha(raw),
                      previous_development_sha256=sha(before[name]),previous_release_sha256=public_members[name]['sha256'])
                 for name,raw in sorted(readback.items())])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text('# Bluetooth startup audio development\n\n'
        'Complete cumulative staging: all 1,918 previous files/fixes retained. Only Blue.exe changes. '
        'One 25-ms retry for a failed thread creation and one for a failed audio-device opening, '
        'within the same opening and without creating a second live worker. Original source routing and peer start notifications remain intact. Existing/ambiguous '
        'handles and partial preparations remain owned for the existing Close path. A missing or '
        'incomplete output cannot become locally started. Normal successful opening adds no delay.\n\n'
        'Actual MIPS bytes checked after write/readback, including native startup notifications and '
        'three-filter dispatch with SBC/sink lifecycle fixtures. Pairing and retained delay/queue '
        'checks passed. Native CE driver/scheduling/loading and the rare physical-unit incident '
        'still need testing. Version is unchanged; no LGU/release/publication. '
        'See analysis/bt-startup-audio-development.md.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu_hash
    assert all((BASE/'payload'/name).read_bytes()==raw for name,raw in before.items())
    assert all(sha((OUT/'payload'/row['path']).read_bytes())==row['sha256'] for row in result['members'])
    print(json.dumps(dict(output=str(OUT),members=1918,changed=changed,
        blue_bytes=len(readback[BLUE]),blue_sha256=sha(readback[BLUE]),
        behavior_cases=checks['behavior']['cases'],structure_cases=checks['structure']['cases'],
        playback=checks['playback'],pairing_cases=pairing_count,release_built=False),indent=2),flush=True)

if __name__=='__main__':main()

