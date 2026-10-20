"""Full MAX29 candidate, retaining every MAX28 payload and delivery path."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from build_max29 import ROOT,BASE,BASE_SHA,REVISION
from debug_image import sha
from package_max16 import tree,write
from package_max28 import dependencies as previous_dependencies

GUIDE='''# MAXmade 7.0.6.MAX29 - boot and installer recovery candidate

All 1,919 MAX28 payload paths retained, plus Recovery.exe: 1,920 files total.
1,914 previous members remain exact. Changes: ROM ULC_launcher inside NK.bin,
DBoot and UpgradeManager startup/launch guards, diagnostic revision/checksum,
Version_Info and the new independent recovery menu. Bootloader and MCU unchanged.

THIS IS A BENCH-VALIDATION CANDIDATE, NOT A HARDWARE-VERIFIED RELEASE.
NK.bin changes. Do not use the owner's only working car to deliberately induce
installation failures. Ordinary successful startup does not validate recovery.

## What changes

The ROM launcher marks startup before it launches even an older DBoot or updater.
It tries DBoot, then UpgradeManager if loading DBoot fails. An unresolved startup
marker goes directly to the recovery menu. If that executable is missing or
cannot load, it requests Windows Explorer from ROM. Normal-startup marker writes
have bounded retries; a failed write selects the ROM desktop. Recovery/desktop
selection does not require creating or writing that marker.

DBoot and UpgradeManager mark/flush startup before their original CRT entry.
Marker creation failure opens independent recovery instead of proceeding into
installation. DBoot's missing-file or failed ShellExecute path also requests
recovery directly. The existing DBoot gesture and StartWinCE path remain.

The native ready-timer transition clears the startup marker only without an
installer error or an active first-stage update. A crash, hang or unexpected exit before readiness leaves it
for the ROM launcher to recognize on the next restart. Installer retained-files
errors automatically open recovery after painting their error screen. The MAX28
Open recovery desktop button remains available if automatic launch fails.

The recovery menu can open Windows CE or allow normal startup on the next
restart. It never starts another installer over an existing one. It does not
format storage, reset settings, clear scan_done_flag.bin, copy firmware or
kill another process. Cancel stays in the menu. A failed desktop request keeps
the menu available for retry.

The first update stage marks itself before changing boot files. It prepares and
reads back a temporary NK/updater, verifies the current file's backup, renames
the old live file into that backup path (retaining running-EXE rename semantics),
then publishes and reads back the replacement. A software-detected publication
failure restores the old bytes and stops before MCU dispatch. Staged boot files
are consumed only after verified publication; failed cleanup also stops.
Only the verified boot-file boundary clears the marker for the expected update
restart. The next boot's guarded application installation marks startup again.
These are checked file operations, not atomic power-loss-safe boot slots.

An unresolved installation still needs repair. For file replacement from USB,
restart into recovery first, so the old updater is not still running. A repair
tool must support the exact MAX29 kernel/payload; the earlier issue56 kit pins
the older kernel and is intentionally not presented as a MAX29 repair kit.

## Validation and limits

See boot-recovery-evidence and build-manifest.json for the actual case count.
Tests exercise written MIPS code/compiled PE, native ROM selection and bounded
marker failures, missing/unloadable executables, entry gating, DBoot fallback,
automatic error recovery, unchanged copy/paint/touch paths, ready flag ordering,
recovery menu choices and retained application regressions. APIs/filesystems
are fixtures. Full LGU and separate PC extraction check all files and hashes.

Real ROM loading, additional helper unwind behavior, mount timing, marker
durability, display/foreground windows, USB availability, MICOM power handling,
normal boot/update flow and interrupted installation still need bench tests.
The ROM marker is closed; application entry guards additionally flush it.
Close/flush/rename are not a power-loss guarantee.

Protection requires the new ROM launcher/guards to have been installed. Code
before their installation, a broken/nonbooting CE kernel, failed storage, MCU,
bootloader or power interruption during flashing remains outside this software
guarantee. No finite software patch proves that every unit can never lock out.
If even ROM Explorer cannot be created, process launch has no proven software
fallback. This candidate does not retroactively repair an already-stopped old
updater. No new OS kernel functionality, driver or MCU code is patched.

The iPhone artwork and other inherited feature candidates retain their existing
physical-acceptance limits. No maps, private backups or logs are added.
'''

def dependencies():
    seen=set(previous_dependencies());pending=[ROOT/'tools'/n for n in ['boot_recovery29.py','build_max29.py','verify_boot_recovery29.py','verify_max29.py','package_max29.py']]
    while pending:
        p=pending.pop()
        if p in seen:continue
        seen.add(p)
        for node in ast.walk(ast.parse(p.read_text(encoding='utf-8-sig'))):
            names=[node.module]if isinstance(node,ast.ImportFrom)else[a.name for a in node.names]if isinstance(node,ast.Import)else[]
            for name in names:
                if name:
                    candidate=ROOT/'tools'/(name.split('.')[0]+'.py')
                    if candidate.is_file():pending.append(candidate)
    seen.add(ROOT/'tools/recovery29.c');return sorted(seen)

def package(stage):
    delivery=ROOT/'build/maxmade-7.0.6.MAX29';archive=ROOT/'build/maxmade-7.0.6.MAX29.zip'
    assert not delivery.exists()and not archive.exists()and not(stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after']for r in plan['members']}
    prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(prior)<set(expected)and len(expected)==1920 and plan['retained_members']==1914
    tree(stage/'payload',expected);tree(BASE/'payload',prior);assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    w=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    key=bytes.fromhex(json.loads((ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json').read_bytes())['xor_hex'])
    fn=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=fn(stage/'upgrade.lgu',expected,REVISION)
    e=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log');tree(stage/'roundtrip',expected)
    paths=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes())for p in paths}
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1919,exact_previous_members=1914,
        changed_members=plan['changed_members'],added_members=plan['added_members'],missing_members=[],writer=w,extractor=e,
        container_verification=result,byte_verification=proof,source_pins=pins,car_tested=False,flashed=False,published=False,
        NK_ROM_launcher_changed=True,bootloader_and_MCU_unchanged=True,universal_recovery_guarantee=False)
    write(stage/'build-manifest.json',manifest)
    old=ROOT/'build/maxmade-7.0.6.MAX28';shutil.copytree(old,delivery)
    for n in ['upgrade.lgu','build-manifest.json','member-plan.json']:shutil.copyfile(stage/n,delivery/n)
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for p in paths:
        dest=delivery/'build-sources'/p.relative_to(ROOT);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(p,dest)
    evidence=delivery/'boot-recovery-evidence';evidence.mkdir()
    for n in ['NK.bin.json','dboot.exe.json','UpgradeManager.exe.json','Recovery.exe.json','boot-recovery-verification.json','inherited-verification.json','verification.json']:
        shutil.copyfile(stage/n,evidence/n)
    before={p.relative_to(old)for p in old.rglob('*')if p.is_file()};after={p.relative_to(delivery)for p in delivery.rglob('*')if p.is_file()};assert before<=after
    sums=''.join(sha(p.read_bytes())+'  '+p.relative_to(delivery).as_posix()+'\n'for p in sorted(delivery.rglob('*'))if p.is_file()and p.name!='SHA256SUMS.txt')
    (delivery/'SHA256SUMS.txt').write_text(sums,encoding='utf-8')
    for row in sums.splitlines():digest,n=row.split('  ',1);assert sha((delivery/n).read_bytes())==digest
    with zipfile.ZipFile(archive,'x',zipfile.ZIP_DEFLATED)as z:
        for p in sorted(delivery.rglob('*')):
            if p.is_file():z.write(p,REVISION+'/'+p.relative_to(delivery).as_posix())
    with zipfile.ZipFile(archive)as z:assert z.testzip()is None and sha(z.read(REVISION+'/upgrade.lgu'))==result['lgu_sha256']
    summary=dict(passed=True,lgu=str(delivery/'upgrade.lgu'),sha256=result['lgu_sha256'],bytes=result['bytes'],members=1920,
         exact_previous_members=1914,checks=proof['cases'],source_files=len(pins),car_test_pending=True)
    write(stage/'package-verification.json',summary);print(json.dumps(summary,indent=2));return summary

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);a=p.parse_args();package(a.stage.resolve())
