"""Full cumulative payload with bounded USB text and coordinated cover access."""
import hashlib
import json
from pathlib import Path
from datetime import datetime,timezone
from patch_usb_status_consumers import app,usb
from verify_usb_status_consumers import verify,structure
from verify_usb_status_retained import verify as retained_usb
from verify_startup_failure import verify as startup_verify
from verify_shared_mapping_checks import verify as mapping_verify,relocation_contracts
from audit_appmain_relocation_runtime import check as ipc_check
from build_bt_eight_test import verify as pairing_verify
from verify_media_responsiveness import verify_touch,verify_performance
from verify_appmain_label_scan import verify as arabic_verify

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/startup-failure-development-01'
OUT=ROOT/'build/usb-status-consumers-development-01'
PROOF=ROOT/'analysis/firmware/usb-status-consumers-development.json'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
APP='upgrade/Storage Card/System/AppMain.exe'
USB='upgrade/Storage Card/System/MgrUSB.exe'
BLUE='upgrade/Storage Card/System/Blue.exe'
def sha(b):return hashlib.sha256(b).hexdigest()

def main():
    assert not OUT.exists() and not PROOF.exists(),'Preserve completed builds and proofs'
    previous_bytes=(BASE/'manifest.json').read_bytes();previous=json.loads(previous_bytes)
    for n,h in previous['tools'].items():assert sha((ROOT/'tools'/n).read_bytes())==h
    assert sha((ROOT/previous['proof']['path']).read_bytes())==previous['proof']['sha256']
    audit_path=ROOT/'analysis/firmware/usb-status-reader-audit.json';audit_bytes=audit_path.read_bytes();audit=json.loads(audit_bytes)
    assert sha((ROOT/'tools/audit_usb_status_readers.py').read_bytes())==audit['tool_sha256']
    released=json.loads((RELEASE/'build-manifest.json').read_bytes())
    members={r['path']:r for r in released['verification']['members']}
    lgu=sha((RELEASE/'upgrade.lgu').read_bytes());assert lgu==released['verification']['lgu_sha256']
    before={}
    for row in previous['members']:
        name=row['path'];assert name.startswith('upgrade/') and '..' not in Path(name).parts
        b=(BASE/'payload'/name).read_bytes();assert len(b)==row['bytes'] and sha(b)==row['sha256'];before[name]=b
    assert len(before)==1918 and set(before)==set(members) and audit['output_sha256']==sha(before[APP])
    after=before.copy();after[APP],ar=app(before[APP]);after[USB],ur=usb(before[USB])
    for name,b in after.items():
        p=OUT/'payload'/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(b)
    readback={p.relative_to(OUT/'payload').as_posix():p.read_bytes() for p in (OUT/'payload').rglob('*') if p.is_file()}
    assert readback==after
    print('All 1,918 files written/read back; checking text and coordinated cover paths',flush=True)
    new=dict(behavior=verify(before[APP],readback[APP],readback[USB],ar,ur),
             app_structure=structure(before[APP],readback[APP],ar),usb_structure=structure(before[USB],readback[USB],ur))
    print('New consumer/cover checks passed; checking retained USB behavior',flush=True)
    usb_checks=retained_usb(readback[USB])
    print('Retained USB passed; checking startup, mappings and Bluetooth/UI',flush=True)
    shared_app=(ROOT/'build/shared-mapping-development-01/payload'/APP).read_bytes()
    mapping_app=(ROOT/'build/usb-save-feedback-development-01/payload'/APP).read_bytes()
    old_app=(ROOT/'build/updater-copy-safety-development-02/payload'/APP).read_bytes()
    original=(ROOT/'extracted/705md'/APP).read_bytes()
    ipc=[ipc_check(readback[APP],delta,kind,mode,scenario) for delta in (0,0x10000,0x120000,0x500000)
         for kind in (1,2) for mode in (1,2) for scenario in ('success','error','timeout','retry','disabled','invalid')]
    app_checks=dict(startup=startup_verify(shared_app,readback[APP]),mapping=mapping_verify(mapping_app,readback[APP]),
        relocation=relocation_contracts(readback[APP]),ipc=dict(cases=len(ipc),traces=ipc),
        pairing=pairing_verify(readback[BLUE],readback[APP]),touch=verify_touch(old_app,readback[APP]),
        hebrew=verify_performance(old_app,readback[APP],exhaustive=False),arabic=arabic_verify(original,readback[APP],exhaustive=False))
    changed=[p for p in before if before[p]!=readback[p]];assert set(changed)=={APP,USB}
    proof=dict(recipes=dict(app=ar,usb=ur),new_checks=new,retained_usb=usb_checks,retained_app=app_checks,
               native_executed=False,hardware_tested=False,native_loader_tested=False)
    PROOF.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
        kind='Complete cumulative development; not an installable update or release',previous_release='7.0.6.MAX03',
        previous_lgu_sha256=lgu,previous_development=BASE.name,carried_forward_manifest_sha256=sha(previous_bytes),
        previous_members=1918,output_members=1918,missing_members=[],added_members=[],changed_from_development=changed,
        unchanged_from_development=1916,recipes=dict(app=ar,usb=ur),new_behavior_cases=new['behavior']['cases']+2,
        retained_usb=usb_checks,retained_app=app_checks,
        original_reader_audit=dict(path=audit_path.relative_to(ROOT).as_posix(),sha256=sha(audit_bytes)),
        proof=dict(path=PROOF.relative_to(ROOT).as_posix(),sha256=sha(PROOF.read_bytes())),
        tools={n:sha((ROOT/'tools'/n).read_bytes()) for n in ('patch_usb_status_consumers.py','verify_usb_status_consumers.py',
                   'verify_usb_status_retained.py','build_usb_status_consumers_development.py')},
        native_executed=False,hardware_tested=False,native_loader_tested=False,installation_ready=False,
        release_built=False,version_bumped=False,general_status_concurrency_fixed=False,
        members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),previous_development_sha256=sha(before[p]),
                      previous_release_sha256=members[p]['sha256']) for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text('# USB text and cover consumers development\n\n'
        'All 1,918 previous files and fixes retained. AppMain and MgrUSB change together. '
        'USB title/artist consumers use bounded, terminated local snapshots. Cover publication, local handle '
        'installation/deletion, acquisition and both paint paths share a named mutex. Deleted handles are '
        'invalidated before freeing; stale or invalid cached handles are skipped. Other widgets keep a short '
        'unlocked dispatch path. Native GDI/CE scheduling and loading remain to be tested.\n\n'
        'New and retained USB/startup/Bluetooth/UI checks pass on read-back bytes. OS/GDI/filesystem/scheduling '
        'use fixtures. Other direct status readers and uncoordinated local metadata construction remain outside '
        'this scope. No LGU, version bump or release. See analysis/usb-status-consumers-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu
    assert all((BASE/'payload'/p).read_bytes()==b for p,b in before.items())
    print(json.dumps(dict(output=str(OUT),members=1918,new_behavior_cases=result['new_behavior_cases'],
        app_sha256=sha(readback[APP]),usb_sha256=sha(readback[USB]),release_built=False),indent=2),flush=True)

if __name__=='__main__':main()
