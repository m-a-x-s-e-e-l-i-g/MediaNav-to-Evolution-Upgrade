"""Package a complete local MAX33 candidate; no release/publication/device write."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import pefile
import build_review_update as container
from build_max33 import ROOT,BASE,BASE_SHA,REVISION
from debug_image import sha
from package_max16 import tree,write

GUIDE='''# MAXmade 7.0.6.MAX33 — resumable application installer candidate

Local test candidate, not a published release. No physical car validation yet.
The current public MAX32 download is unchanged.

## What changes

After extraction, the native updater installs a verified copy of the independent
InstallResume.exe worker and Recovery.exe before settings processing. A healthy
install keeps the existing native settings migration. Its application-copy phase
then delegates to the worker, which copies from retained internal staging.

Application blocks are checked against the compiled package manifest, written to
a temporary, flushed and read back before publication. Two alternating checked
progress slots record copy and verification progress every 256 KiB. A package
receipt permits automatic resume on the next boot, without replaying settings
formatting. Version_Info is installed last, after separate application verification.
The native updater requires child success AND the completion receipt, matching
version, removed stage and removed pending receipt before normal startup.

For an ambiguous settings checkpoint, the error screen has two separate actions:
Repair / resume update, and Open recovery desktop. Recovery offers explicit repair
or Windows CE. An existing worker transaction resumes automatically once per boot;
software errors open recovery with auto-retry suppressed. Explicit repair preserves
the settings currently present and the old TFAT backup; it cannot prove those
settings were fully restored before the original interruption.

Only the exact known stopped updater may be quiesced. A delegated parent is held,
never killed; active firmware work, running applications, mismatched active boot
components and foreign receipts block the worker. The worker does not flash the
kernel or MCU and has no settings-format action.

Known public source members are removed only after commit. Cleanup is resumable
even after source deletion has begun. Unknown extras and settings backups are
retained; nonempty directories are never recursively removed. Housekeeping errors
may leave public source files behind without blocking a verified installation.
The boot-attempt marker stays until the existing native readiness path clears it.

## Scope and limits

This protects the application transaction once the new updater/recovery/worker
are available. It does not retroactively protect the first legacy extraction,
kernel/self replacement, MCU flashing, native healthy settings migration or every
native maintenance/wait path. The worker's parent wait requires the child to exit;
a hung CE storage call is not cured by journaling. Sudden power loss can still
damage TFAT metadata or storage. This is not a universal anti-brick guarantee.
Offline MIPS/API fixtures do not test CE loading, actual screen rendering, car
power/watchdog behavior, real flash durability or registry/MCU compatibility.

Do not use this candidate as an untested repair for issue #59's already-installed
MAX30. His separately supplied pinned completion kit is unchanged.

## Full payload retained

All 1,920 MAX32 members remain: 1,916 exact, four changed, one added = 1,921.
Changed: UpgradeManager.exe, Recovery.exe, Version_Info.txt and the diagnostic
revision/checksum in CmnDll.dll. Added: InstallResume.exe. Kernel, DBoot, MCU,
Blue.exe including the contributor iPhone fix, navigation and all media/resources
are byte-identical to MAX32. Every previous delivery file is retained as well.

## Physical acceptance test

Use stable power and leave the USB connected through both normal install stages.
Do not deliberately remove power, corrupt files or erase markers to provoke recovery
in the daily car. Fault injection belongs on a recoverable bench unit.

1. Check the offered version is MAX33, allow the complete install, then confirm
   Settings > System > System version shows 7.0.6.MAX33.
2. Confirm normal startup, radio/Bluetooth/USB, navigation and saved settings.
3. Enter Windows CE via the normal DBoot route and return to MediaNav; check that
   a healthy session does not create a false unfinished-installation prompt.
4. Check USB logging still starts when enabled and older log sessions remain.
5. On a recoverable bench: interrupt only the application transaction, restart,
   verify automatic progress resume and final byte receipts; separately test the
   explicit Repair action and independent Windows CE action after a copy failure.

The LGU has independent Python verification and separate native-tool extraction.
See installer-resume-evidence for tests, manifests, source pins and generated C
headers. Full-payload tests accelerate hashes; native SHA boundaries and actual
native chunk publication are tested separately. Reused baseline helper evidence
is accepted only with exact instruction-byte comparisons.
'''

def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max33.py','installer_resume33.py','install_resume33.c','recovery33.c','verify_installer33.py','verify_installer33_native.py','package_max33.py']];seen=set()
    while pending:
        p=pending.pop()
        if p in seen:continue
        seen.add(p)
        if p.suffix!='.py':continue
        for node in ast.walk(ast.parse(p.read_text(encoding='utf-8-sig'))):
            names=[node.module]if isinstance(node,ast.ImportFrom)else[a.name for a in node.names]if isinstance(node,ast.Import)else[]
            for name in names:
                if name:
                    q=ROOT/'tools'/(name.split('.')[0]+'.py')
                    if q.is_file():pending.append(q)
    seen.add(ROOT/'tools/issue56_repair.c');return sorted(seen)

def package(stage):
    delivery=ROOT/'build/maxmade-7.0.6.MAX33';archive=ROOT/'build/maxmade-7.0.6.MAX33.zip';old=ROOT/'build/maxmade-7.0.6.MAX32'
    assert not delivery.exists()and not archive.exists()and not(stage/'upgrade.lgu').exists()
    proofs=[json.loads((stage/n).read_bytes())for n in ['worker-verification.json','native-verification.json']];assert all(p['passed']for p in proofs)
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after']for r in plan['members']};prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(prior)<=set(expected)and len(expected)==1921 and plan['retained_members']==1916
    tree(stage/'payload',expected);tree(BASE/'payload',prior);assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    for name,folder in [('install_resume33.c','engine'),('recovery33.c','menu')]:assert (ROOT/'tools'/name).read_bytes()==(stage/folder/name).read_bytes()
    for path in plan['changed_members']+plan['added_members']:
        if path.lower().endswith(('.exe','.dll')):
            p=pefile.PE(str(stage/'payload'/path));assert p.FILE_HEADER.Machine==0x166 and p.OPTIONAL_HEADER.Subsystem==9
            assert p.verify_checksum(),path
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    w=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    key=bytes.fromhex(json.loads((ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json').read_bytes())['xor_hex'])
    fn=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key));result=fn(stage/'upgrade.lgu',expected,REVISION)
    e=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log');tree(stage/'roundtrip',expected)
    paths=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes())for p in paths}
    proof=dict(passed=True,cases=sum(p['cases']for p in proofs),checks=[c for p in proofs for c in p['checks']],physical_tested=False)
    write(stage/'verification.json',proof)
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1920,exact_previous_members=1916,changed_members=plan['changed_members'],added_members=plan['added_members'],missing_members=[],writer=w,extractor=e,container_verification=result,byte_verification=proof,source_pins=pins,car_tested=False,published=False,universal_recovery_guarantee=False)
    write(stage/'build-manifest.json',manifest);shutil.copytree(old,delivery)
    for n in ['upgrade.lgu','build-manifest.json','member-plan.json','verification.json','runtime.json']:shutil.copyfile(stage/n,delivery/n)
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for p in paths:
        dest=delivery/'build-sources'/p.relative_to(ROOT);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(p,dest)
    evidence=delivery/'installer-resume-evidence';evidence.mkdir()
    for n in ['development.json','UpgradeManager.exe.json','worker-verification.json','native-verification.json']:shutil.copyfile(stage/n,evidence/n)
    for folder in ['engine','menu']:
        dest=evidence/folder;dest.mkdir()
        for p in (stage/folder).iterdir():
            if p.is_file()and p.suffix in ['.json','.h','.c','.ld']:shutil.copyfile(p,dest/p.name)
    assert {p.relative_to(old)for p in old.rglob('*')if p.is_file()}<={p.relative_to(delivery)for p in delivery.rglob('*')if p.is_file()}
    sums=''.join(sha(p.read_bytes())+'  '+p.relative_to(delivery).as_posix()+'\n'for p in sorted(delivery.rglob('*'))if p.is_file()and p.name!='SHA256SUMS.txt');(delivery/'SHA256SUMS.txt').write_text(sums,encoding='utf-8')
    for row in sums.splitlines():digest,n=row.split('  ',1);assert sha((delivery/n).read_bytes())==digest
    with zipfile.ZipFile(archive,'x',zipfile.ZIP_DEFLATED)as z:
        for p in sorted(delivery.rglob('*')):
            if p.is_file():z.write(p,REVISION+'/'+p.relative_to(delivery).as_posix())
    with zipfile.ZipFile(archive)as z:assert z.testzip()is None and sha(z.read(REVISION+'/upgrade.lgu'))==result['lgu_sha256']
    summary=dict(passed=True,lgu=str(delivery/'upgrade.lgu'),sha256=result['lgu_sha256'],bytes=result['bytes'],members=1921,exact_previous_members=1916,checks=proof['cases'],source_files=len(pins),car_test_pending=True)
    write(stage/'package-verification.json',summary);print(json.dumps(summary,indent=2),flush=True);return summary

def finalize_metadata(stage):
    """Replace inherited root metadata with MAX33 status, retaining its history."""
    delivery=ROOT/'build/maxmade-7.0.6.MAX33';archive=ROOT/'build/maxmade-7.0.6.MAX33.zip'
    m=json.loads((stage/'build-manifest.json').read_bytes());c=m['container_verification']
    assert sha((delivery/'upgrade.lgu').read_bytes())==c['lgu_sha256']
    history=delivery/'installer-resume-evidence/inherited-MAX32';history.mkdir(exist_ok=True)
    shutil.copyfile(ROOT/'build/max30-quieter-logging-development-03/UpgradeManager.exe.json',delivery/'installer-resume-evidence/baseline-updater-recipe.json')
    names=['device-status.json','package-verification.json','public-baseline-comparison.json','source-manifest.json','CmnDll.dll.json','REPORTER-TEST-PLAN.md']
    for name in names:
        if not(history/name).exists():shutil.copyfile(delivery/name,history/name)
    write(delivery/'device-status.json',dict(revision=REVISION,candidate_only=True,published=False,car_tested=False,physical_test_pending=True,universal_recovery_guarantee=False,lgu_sha256=c['lgu_sha256'],first_legacy_stage_protected=False,application_resume_verified_offline=True))
    shutil.copyfile(stage/'package-verification.json',delivery/'package-verification.json')
    write(delivery/'public-baseline-comparison.json',dict(baseline='7.0.6.MAX32',retained_paths=1920,unchanged_members=1916,changed_members=m['changed_members'],added_members=m['added_members'],missing_members=[]))
    plan=json.loads((stage/'member-plan.json').read_bytes());cmn=next(r for r in plan['members']if r['path'].endswith('/CmnDll.dll'))
    write(delivery/'CmnDll.dll.json',dict(revision_only_from_MAX32=True,before_sha256=cmn['before']['sha256'],output_sha256=cmn['after']['sha256']))
    (delivery/'REPORTER-TEST-PLAN.md').write_text(GUIDE[GUIDE.index('## Physical acceptance test'):],encoding='utf-8')
    paths=dependencies();m['source_pins']={p.relative_to(ROOT).as_posix():sha(p.read_bytes())for p in paths}
    for p in paths:
        q=delivery/'build-sources'/p.relative_to(ROOT);q.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(p,q)
    write(stage/'build-manifest.json',m);write(delivery/'build-manifest.json',m)
    write(delivery/'source-manifest.json',dict(files=[dict(path='build-sources/'+n,bytes=(delivery/'build-sources'/n).stat().st_size,sha256=h)for n,h in m['source_pins'].items()]))
    sums=''.join(sha(p.read_bytes())+'  '+p.relative_to(delivery).as_posix()+'\n'for p in sorted(delivery.rglob('*'))if p.is_file()and p.name!='SHA256SUMS.txt');(delivery/'SHA256SUMS.txt').write_text(sums,encoding='utf-8')
    for row in sums.splitlines():h,n=row.split('  ',1);assert sha((delivery/n).read_bytes())==h
    temp=archive.with_suffix('.verified.zip');assert not temp.exists()
    with zipfile.ZipFile(temp,'x',zipfile.ZIP_DEFLATED)as z:
        for p in sorted(delivery.rglob('*')):
            if p.is_file():z.write(p,REVISION+'/'+p.relative_to(delivery).as_posix())
    with zipfile.ZipFile(temp)as z:assert z.testzip()is None and sha(z.read(REVISION+'/upgrade.lgu'))==c['lgu_sha256']
    temp.replace(archive)
    print('MAX33 metadata/source pins/archive verified',flush=True)

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);stage=p.parse_args().stage.resolve();package(stage);finalize_metadata(stage)
