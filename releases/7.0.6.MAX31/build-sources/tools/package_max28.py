"""Package a full MAX27 successor and independently verify all payload members."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from debug_image import sha
from build_max28 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import tree,write
from package_max27 import dependencies as old_dependencies

GUIDE='''# MAXmade 7.0.6.MAX28 - installer recovery desktop candidate

Complete MAX27 successor: all 1,919 payload paths retained, 1,916 byte-identical.
Only UpgradeManager, diagnostic revision/checksum in CmnDll and Version_Info
change. Bluetooth artwork, navigation, kernel, MCU firmware, DBoot, resources
and prior improvements remain as in MAX27.

When the installer stops with a retained-files error, it keeps the error/code/
path and displays an Open recovery desktop button. Tap it to start the existing
ROM Windows CE Explorer directly. DBoot and completed installation are not
required. The updater is hidden only after successful process creation; it
remains alive for existing monitor handling. Process/thread handles are closed.
If launch fails, an error dialog appears and the button remains available.
No formatting, checkpoint deletion, automatic resume or additional reboot is
triggered by the button. The existing backup/copy/readback guards remain.

This is for future installation failures after the patched updater has started.
An older updater already stuck on error 5001 cannot acquire this fix through
an unavailable normal update interface. It first needs an independent recovery
entry, such as an already-supported USB kernel boot. Do not mistake this LGU
for the separate conditional USB desktop recovery NK.bin.

Offline tests cover native error repaint, touch routing, launcher arguments,
failed launch/retry, handles, unchanged files, original safe copy/error cases
and inherited MAX27 regressions. Real CE display/Explorer/touch and interrupted
installation on a recoverable bench unit still need validation before public
release. No software guarantees recovery from every power, NAND, kernel,
bootloader or MCU failure. Cases before this updater runs remain outside it.

For ordinary installation use the existing full-update procedure and confirm
MAX28 afterwards. Preserve radio code and backups. For an unexpected error use
the desktop action to preserve/inspect internal state; do not format storage,
delete the checkpoint or manually start other software as an automatic repair.
If USB is absent in the desktop, the unit's USB activation/mount path must be
established before copying; desktop entry alone does not prove backup success.

The iPhone artwork change inherited from MAX27 still requires physical iPhone
acceptance. Do not equate these installer changes with a confirmed cover fix.
'''


def dependencies():
    seen=set(old_dependencies());pending=[ROOT/'tools'/n for n in
        ['build_max28.py','debug_runtime28.py','updater_recovery28.py','verify_updater_recovery28.py',
         'verify_updater_copy_safety.py','verify_max28.py','package_max28.py']]
    while pending:
        path=pending.pop()
        if path in seen:continue
        seen.add(path)
        for node in ast.walk(ast.parse(path.read_text(encoding='utf-8-sig'))):
            names=[node.module]if isinstance(node,ast.ImportFrom)else[a.name for a in node.names]if isinstance(node,ast.Import)else[]
            for name in names:
                if name:
                    p=ROOT/'tools'/(name.split('.')[0]+'.py')
                    if p.is_file():pending.append(p)
    return sorted(seen)


def package(stage):
    stage=stage.resolve();delivery=ROOT/'build/maxmade-7.0.6.MAX28';archive=ROOT/'build/maxmade-7.0.6.MAX28.zip'
    assert not delivery.exists()and not archive.exists()and not(stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes())
    assert proof['passed']and 'MAX28 stopped installer has an independent desktop escape; no automatic format or resume'in proof['checks']
    plan=json.loads((stage/'member-plan.json').read_bytes())
    expected={r['path']:r['after']for r in plan['members']}
    prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(prior)==set(expected)and len(expected)==1919 and plan['retained_members']==1916
    tree(BASE/'payload',prior);tree(stage/'payload',expected)
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    w=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    key=bytes.fromhex(json.loads((ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json').read_bytes())['xor_hex'])
    fn=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=fn(stage/'upgrade.lgu',expected,REVISION)
    e=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log')
    tree(stage/'roundtrip',expected);tree(stage/'payload',expected);tree(BASE/'payload',prior)
    files=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes())for p in files}
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1919,
        exact_previous_members=1916,changed_members=plan['changed_members'],missing_members=[],
        writer=w,extractor=e,container_verification=result,byte_verification=proof,source_pins=pins,
        native_executed=False,car_tested=False,flashed=False,published=False)
    write(stage/'build-manifest.json',manifest)
    old=ROOT/'build/maxmade-7.0.6.MAX27';shutil.copytree(old,delivery)
    for name in ['upgrade.lgu','build-manifest.json','member-plan.json']:shutil.copyfile(stage/name,delivery/name)
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for path in files:
        dest=delivery/'build-sources'/path.relative_to(ROOT);dest.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,dest)
    evidence=delivery/'installer-recovery-evidence';evidence.mkdir()
    for name in ['UpgradeManager.exe.json','updater-recovery-verification.json','verification.json']:
        shutil.copyfile(stage/name,evidence/name)
    before={p.relative_to(old)for p in old.rglob('*')if p.is_file()}
    assert before<={p.relative_to(delivery)for p in delivery.rglob('*')if p.is_file()}
    paths=sorted(p for p in delivery.rglob('*')if p.is_file()and p.name!='SHA256SUMS.txt')
    sums=''.join(sha(p.read_bytes())+'  '+p.relative_to(delivery).as_posix()+'\n'for p in paths)
    (delivery/'SHA256SUMS.txt').write_text(sums,encoding='ascii')
    for line in sums.splitlines():digest,name=line.split('  ',1);assert sha((delivery/name).read_bytes())==digest
    with zipfile.ZipFile(archive,'x',zipfile.ZIP_DEFLATED)as z:
        for p in sorted(delivery.rglob('*')):
            if p.is_file():z.write(p,REVISION+'/'+p.relative_to(delivery).as_posix())
    with zipfile.ZipFile(archive)as z:
        assert z.testzip()is None and sha(z.read(REVISION+'/upgrade.lgu'))==result['lgu_sha256']
    summary=dict(passed=True,lgu=str(delivery/'upgrade.lgu'),sha256=result['lgu_sha256'],bytes=result['bytes'],
        members=1919,exact_previous_members=1916,checks=proof['cases'],source_files=len(pins),car_test_pending=True)
    write(stage/'package-verification.json',summary);return summary


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);a=p.parse_args();print(json.dumps(package(a.stage),indent=2))
