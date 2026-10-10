"""Full cumulative internal payload, preserving all previous member/proof hashes."""
import hashlib
import json
from pathlib import Path
from datetime import datetime,timezone
from patch_usb_snapshot_copy import patch
from verify_usb_snapshot_copy import verify,structure
from verify_usb_status_consumers import verify as consumers_verify
from audit_usb_cover_callers import verify as callers_verify
from verify_startup_failure import verify as startup_verify
from verify_shared_mapping_checks import verify as mapping_verify,relocation_contracts
from audit_appmain_relocation_runtime import check as ipc_check
from build_bt_eight_test import verify as pairing_verify
from verify_media_responsiveness import verify_touch,verify_performance
from verify_appmain_label_scan import verify as arabic_verify

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/usb-status-consumers-development-01'
OUT=ROOT/'build/usb-snapshot-copy-development-02'
PROOF=ROOT/'analysis/firmware/usb-snapshot-copy-development.json'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
APP='upgrade/Storage Card/System/AppMain.exe'
USB='upgrade/Storage Card/System/MgrUSB.exe'
BLUE='upgrade/Storage Card/System/Blue.exe'
def sha(b):return hashlib.sha256(b).hexdigest()

def main():
    assert not OUT.exists() and not PROOF.exists(),'Do not overwrite previous outputs or proofs'
    previous_bytes=(BASE/'manifest.json').read_bytes();previous=json.loads(previous_bytes)
    for n,h in previous['tools'].items():assert sha((ROOT/'tools'/n).read_bytes())==h
    prior_proof_bytes=(ROOT/previous['proof']['path']).read_bytes()
    assert sha(prior_proof_bytes)==previous['proof']['sha256']
    prior_proof=json.loads(prior_proof_bytes)
    audit_path=ROOT/'analysis/firmware/usb-cover-callers-audit.json'
    audit_bytes=audit_path.read_bytes();audit=json.loads(audit_bytes)
    assert sha((ROOT/'tools/audit_usb_cover_callers.py').read_bytes())==audit['tool_sha256']
    released=json.loads((RELEASE/'build-manifest.json').read_bytes())
    release_members={r['path']:r for r in released['verification']['members']}
    lgu=sha((RELEASE/'upgrade.lgu').read_bytes());assert lgu==released['verification']['lgu_sha256']
    before={}
    for row in previous['members']:
        name=row['path'];assert name.startswith('upgrade/') and '..' not in Path(name).parts
        b=(BASE/'payload'/name).read_bytes();assert len(b)==row['bytes'] and sha(b)==row['sha256'];before[name]=b
    assert len(before)==1918 and set(before)==set(release_members)
    assert audit['app_sha256']==sha(before[APP]) and audit['usb_sha256']==sha(before[USB])
    after=before.copy();after[APP],r=patch(before[APP],previous['recipes']['app'])
    ar=r['consumer_recipe'];ur=previous['recipes']['usb']
    for name,b in after.items():
        p=OUT/'payload'/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(b)
    readback={p.relative_to(OUT/'payload').as_posix():p.read_bytes() for p in (OUT/'payload').rglob('*') if p.is_file()}
    assert readback==after
    print('All 1,918 files written/read back; checking bounded copy/overlap/relocations',flush=True)
    new=dict(copy=verify(before[APP],readback[APP],previous['recipes']['app'],ar),
        structure=structure(before[APP],readback[APP],r))
    print('Snapshot copy passed; checking complete text/cover consumers and original callers',flush=True)
    original_consumers=(ROOT/'build/startup-failure-development-01/payload'/APP).read_bytes()
    assert sha(original_consumers)==previous['recipes']['app']['input_sha256']
    consumer=consumers_verify(original_consumers,readback[APP],readback[USB],ar,ur)
    callers=callers_verify(readback[APP],readback[USB],ar,ur)
    print('Consumer/caller checks passed; checking retained startup/mapping/Bluetooth/UI',flush=True)
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
    changed=[p for p in before if before[p]!=readback[p]];assert changed==[APP]
    assert before[USB]==readback[USB]
    carried_usb=dict(rerun=False,reason='MgrUSB is byte-identical; prior hash-pinned 72,494-case behavior proof retained',
        usb_sha256=sha(readback[USB]),proof=previous['proof'],checks=prior_proof['retained_usb'])
    proof=dict(recipe=r,new_checks=new,retained_consumers=consumer,retained_callers=callers,
        retained_app=app_checks,carried_usb=carried_usb,native_executed=False,hardware_tested=False,native_timing_measured=False)
    PROOF.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
        kind='Complete cumulative internal development; not an installable release',previous_release='7.0.6.MAX03',
        previous_lgu_sha256=lgu,previous_development=BASE.name,carried_forward_manifest_sha256=sha(previous_bytes),
        previous_members=1918,output_members=1918,missing_members=[],added_members=[],changed_from_development=changed,
        unchanged_from_development=1917,recipes=dict(copy=r,app=ar,usb=ur),
        new_behavior_cases=new['copy']['cases']+new['structure']['cases'],
        retained_consumers=consumer['cases'],retained_callers=callers['cases'],retained_app=app_checks,
        retained_usb=carried_usb,previous_cover_audit=dict(path=audit_path.relative_to(ROOT).as_posix(),sha256=sha(audit_bytes)),
        proof=dict(path=PROOF.relative_to(ROOT).as_posix(),sha256=sha(PROOF.read_bytes())),
        tools={n:sha((ROOT/'tools'/n).read_bytes()) for n in ('patch_usb_snapshot_copy.py','verify_usb_snapshot_copy.py','build_usb_snapshot_copy_development.py')},
        native_executed=False,hardware_tested=False,native_loader_tested=False,installation_ready=False,
        release_built=False,version_bumped=False,general_status_concurrency_fixed=False,
        members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),previous_development_sha256=sha(before[p]),
            previous_release_sha256=release_members[p]['sha256']) for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text('# USB snapshot copy development\n\n'
        'Complete cumulative staging: all 1,918 prior files and fixes retained. Only AppMain changes. '
        'The locked USB snapshot helper copies four bytes at a time, uses aligned loads/stores where possible, '
        'and retains byte tails and the old forward-copy behavior for destructive overlap. '
        'Source/destination bounds, zero/NULL/failure/abandoned mutex behavior and stack/register ABI are checked '
        'with actual MIPS bytes at four image bases. Consumers, cover callers and AppMain regressions rerun. '
        'MgrUSB is byte-identical; its earlier hash-pinned regression proof is carried, not rerun.\n\n'
        'Instruction counts are interpreter measurements, not native timing. Native CE loading, rendering, '
        'GDI ownership and performance remain to be tested. No LGU, version bump or release. '
        'See analysis/usb-snapshot-copy-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu
    assert all((BASE/'payload'/p).read_bytes()==b for p,b in before.items())
    print(json.dumps(dict(output=str(OUT),members=1918,new_behavior_cases=result['new_behavior_cases'],
        retained_consumers=consumer['cases'],retained_callers=callers['cases'],app_sha256=sha(readback[APP]),
        benchmarks=new['copy']['benchmarks'],release_built=False),indent=2),flush=True)

if __name__=='__main__':main()
