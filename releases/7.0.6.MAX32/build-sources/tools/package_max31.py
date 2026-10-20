"""Full MAX30 successor; retain every payload and delivery path."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from build_max31 import ROOT,BASE,BASE_SHA,REVISION
from debug_image import sha
from package_max16 import tree,write
from package_max30 import dependencies as previous_dependencies

GUIDE='''# MAXmade 7.0.6.MAX31 - DBoot desktop recovery correction

Complete MAX30 successor. The owner's MAX30 report showed an intentional
Windows CE session being classified as an unfinished MediaNav startup.

- The ROM launcher recognizes the existing one-shot StartWinCE request before
  selecting recovery from a leftover startup marker.
- DBoot keeps its normal registry/GPIO setup. Only its explicit native CE choice
  clears the startup-attempt marker; install receipts/scan checkpoints remain.
- Recovery's desktop action enters DBoot with a dedicated desktop-only command,
  retaining the failure marker and skipping updater launch. Missing DBoot falls
  back to ROM Explorer. The menu wording no longer treats the marker alone as
  proof of an incomplete installation.
- Actual installer-error handling, first-stage verification, normal readiness
  clearing, all application/navigation/artwork changes and quieter logs remain.

This corrects verified control flow. Real CE desktop power stability and the
complete CE-to-MediaNav round trip still require the owner's car test. There is
no new reboot/format action or MCU/bootloader change. Known maintenance/formatting
and stalled-update limitations remain; this is not universal anti-brick recovery.
The iPhone cover change remains physically unverified.

## Owner test

Install the complete upgrade.lgu normally, keeping power/USB connected until
finished. Confirm 7.0.6.MAX31 in System version. Then:

1. Use the ordinary DBoot gesture and confirm Windows CE.
2. Check that the desktop opens without the erroneous recovery prompt and stays
   open. Keep any observed restart timing separate from the prompt result.
3. Use the normal desktop restart shortcut to return to MediaNav. Check that the
   recovery prompt does not appear, then repeat this round trip once.
4. Check ordinary startup, music/navigation and automatic USB logging afterward.

Do not remove system files or interrupt installation to force recovery.
The release LGU and original logs/backups are not overwritten by this build.

## Evidence

All 1,920 MAX30 payload paths remain. NK.bin, dboot.exe, Recovery.exe,
CmnDll.dll (diagnostic revision/checksum only) and Version_Info.txt change;
1,915 files remain byte-exact. The updater and MCU images are exact MAX30.

The ROM image retains its layout and 114 checksums. Only ULC_launcher startup
selection plus an inert former PDB debug locator change. Tests execute written
MIPS for the boot choices, native DBoot initialization/desktop entry, marker
semantics and retained installer errors. Unchanged application/quiet-log evidence
is reused only after exact-byte checks, apart from the diagnostic header/checksum.
Build manifests, source pins and independent full LGU extraction are included.
No physical test, public release or device write is claimed by packaging.
'''

def dependencies():
    seen=set(previous_dependencies());pending=[ROOT/'tools'/n for n in [
        'boot_recovery31.py','recovery31.c','build_max31.py','verify_boot_recovery31.py','package_max31.py']]
    while pending:
        p=pending.pop()
        if p in seen:continue
        seen.add(p)
        if p.suffix!='.py':continue
        for node in ast.walk(ast.parse(p.read_text(encoding='utf-8-sig'))):
            names=[node.module]if isinstance(node,ast.ImportFrom)else[a.name for a in node.names]if isinstance(node,ast.Import)else[]
            for name in names:
                if name:
                    candidate=ROOT/'tools'/(name.split('.')[0]+'.py')
                    if candidate.is_file():pending.append(candidate)
    return sorted(seen)

def package(stage):
    delivery=ROOT/'build/maxmade-7.0.6.MAX31';archive=ROOT/'build/maxmade-7.0.6.MAX31.zip'
    assert not delivery.exists()and not archive.exists()and not(stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after']for r in plan['members']}
    prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(prior)==set(expected)and len(expected)==1920 and plan['retained_members']==1915
    tree(stage/'payload',expected);tree(BASE/'payload',prior);assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    w=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    key=bytes.fromhex(json.loads((ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json').read_bytes())['xor_hex'])
    fn=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=fn(stage/'upgrade.lgu',expected,REVISION)
    e=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log');tree(stage/'roundtrip',expected)
    paths=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes())for p in paths}
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1920,exact_previous_members=1915,
        changed_members=plan['changed_members'],added_members=[],missing_members=[],writer=w,extractor=e,
        container_verification=result,byte_verification=proof,source_pins=pins,car_tested=False,published=False,
        native_DBooT_desktop_init_retained=True,updater_and_MCU_unchanged=True,universal_recovery_guarantee=False)
    write(stage/'build-manifest.json',manifest)
    old=ROOT/'build/maxmade-7.0.6.MAX30';shutil.copytree(old,delivery)
    for n in ['upgrade.lgu','build-manifest.json','member-plan.json','verification.json','runtime.json']:shutil.copyfile(stage/n,delivery/n)
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for p in paths:
        dest=delivery/'build-sources'/p.relative_to(ROOT);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(p,dest)
    evidence=delivery/'dboot-recovery-evidence';evidence.mkdir()
    for n in ['NK.bin.json','dboot.exe.json','Recovery.exe.json','CmnDll.dll.json','boot-recovery-verification.json','inherited-verification.json','verification.json']:
        shutil.copyfile(stage/n,evidence/n)
    assert {p.relative_to(old)for p in old.rglob('*')if p.is_file()}<={p.relative_to(delivery)for p in delivery.rglob('*')if p.is_file()}
    sums=''.join(sha(p.read_bytes())+'  '+p.relative_to(delivery).as_posix()+'\n'for p in sorted(delivery.rglob('*'))if p.is_file()and p.name!='SHA256SUMS.txt')
    (delivery/'SHA256SUMS.txt').write_text(sums,encoding='utf-8')
    for row in sums.splitlines():digest,n=row.split('  ',1);assert sha((delivery/n).read_bytes())==digest
    with zipfile.ZipFile(archive,'x',zipfile.ZIP_DEFLATED)as z:
        for p in sorted(delivery.rglob('*')):
            if p.is_file():z.write(p,REVISION+'/'+p.relative_to(delivery).as_posix())
    with zipfile.ZipFile(archive)as z:assert z.testzip()is None and sha(z.read(REVISION+'/upgrade.lgu'))==result['lgu_sha256']
    summary=dict(passed=True,lgu=str(delivery/'upgrade.lgu'),sha256=result['lgu_sha256'],bytes=result['bytes'],members=1920,
        exact_previous_members=1915,checks=proof['cases'],source_files=len(pins),car_test_pending=True)
    write(stage/'package-verification.json',summary);print(json.dumps(summary,indent=2),flush=True)
    return summary

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);package(p.parse_args().stage.resolve())
