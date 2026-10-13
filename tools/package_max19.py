"""Full MAX18 successor, independently decoded and separately PC-extracted."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from debug_image import sha
from build_max19 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import tree,write


GUIDE='''# MAXmade 7.0.6.MAX19 — USB diagnostics test build

Complete MAX18 successor. All 1,919 payload paths retained; 1,911 byte-exact.
Only seven application/library binaries and Version_Info.txt change. Navigation
engine/skin, images, fonts, DBoot, kernel, MCU input and all previous fixes remain.

## Use

Open Settings > System > page 2. Tap "Debugging: Off" to enable it.
The row becomes "Debugging: On". Logging is off by default. The choice is saved
through a dedicated registry value and RegFlushKey by the background worker.
Check that it remains enabled after a later ignition cycle; physical persistence
has not yet been verified. The item keeps the original conditional Eco slot.

With a readable/writable USB stick mounted at the native \\MD path, logs start
automatically in MAXmade/logs/. Without a stick, the status is "Waiting for USB".
It detects later insertion/removal. USB/full/write/thread/configuration errors
are shown in the status line. Tap again to turn it off. Allow the pending records
to finish and the status to change to "Logging off" before copying the files.

There are eight rotating debug-0.log through debug-7.log files, each at most
4 MiB. An open starts only with at least 16 MiB free. These eight names are
owned by the logger; they are overwritten as it rotates. No log fallback writes
to the four internal Storage Cards. The configuration is the only persisted
internal setting. No PCM, artwork image payloads or packet dumps are logged.

## Measurements

- AppMain lifecycle, media manager initialization, source-switch requests and
  overlay restoration. Existing 600/200/500 ms waits are retained.
- Navigation launch, USB scanning/sorting/file rendering/folder changes.
- Bluetooth audio-start request, artwork publication and decoding.
- Screen paints of at least 16 ms. Actual first audible sound, full hardware
  source completion and navigation-engine internals are not established here.
- OS memory samples every ten seconds: free physical bytes and reported load.
  This build does not report per-process CPU utilization.
- Emitted debug strings and NKDbgPrintfW messages from AppMain, Blue, MgrUSB,
  MicomManager, MgrIpod and MgrDAB, plus the shared library. Existing native
  log filters remain; this does not activate every dormant vendor debug branch.

Records use the device millisecond clock, module/event IDs, elapsed interval,
raw return value, level and bounded text. A session header records device calendar
time and its start tick. Calendar time can be unset. A raw return/IPC delivery
does not establish successful playback or settled hardware.

The shared queue has 256 records of 544 bytes and a 128-record/second cap.
Producers use a zero-duration mutex attempt and never write or wait for USB.
The independent writer uses confirmed CE thread priority 4, releases the queue
before I/O and flushes periodically. Records can be dropped under load or lost
on abrupt power loss; drop counters are sampled. Logging has a small observer
cost. Real USB-driver contention and actual performance require car testing.

## Car test

Use the established full-update procedure and confirm 7.0.6.MAX19. First check
the original media/navigation functionality with debugging off. Enable without
USB and confirm the waiting status, insert the stick and confirm logging active.
Try source switches, Bluetooth track changes/artwork, USB scan/playback, both
themes and Settings page navigation. Turn it off and inspect MAXmade/logs/.
Then enable again, allow the setting to save, and test a cold ignition cycle
with USB inserted. Compare responsiveness/audio with logging off versus on.
Run at least 30 seconds per capture to include memory/drop samples.

Copy the whole logs folder for analysis before a later long session overwrites
its oldest chunks. Logs contain emitted native text and device/media context;
they are local diagnostic data and are excluded from this release.

Python analysis: python analyze_debug_logs.py PATH_TO_LOGS --output summary.json
It groups sessions, lists slowest measured spans, RAM samples and partial lines.
Missing end events can also result from rotation, lost records or power loss;
they are not automatically classified as a crash or hang.

## Verification and scope

Written MIPS instructions are interpreted with explicit OS/filesystem/GDI
fixtures. Native loading, touch, real audio, USB timing, registry durability
and sustained operation have not been tested on the physical device.
This is a local test build; MAX18 remains the owner-tested baseline.
The package does not prove rollback/recovery. Original builds and backup are
untouched. Preview images use native resources and PC Tahoma/sample state.
'''


def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max19.py','debug_image.py','debug_runtime.py','debug_clients.py',
        'verify_max19.py','analyze_debug_logs.py','preview_debug_settings.py','package_max19.py']]
    seen=set()
    while pending:
        path=pending.pop()
        if path in seen:continue
        seen.add(path)
        for node in ast.walk(ast.parse(path.read_text(encoding='utf-8-sig'))):
            mods=[node.module] if isinstance(node,ast.ImportFrom) else [a.name for a in node.names] if isinstance(node,ast.Import) else []
            for mod in mods:
                if mod:
                    p=ROOT/'tools'/(mod.split('.')[0]+'.py')
                    if p.is_file():pending.append(p)
    return sorted(seen)


def package(stage):
    stage=stage.resolve()
    delivery=ROOT/'build/maxmade-7.0.6.MAX19';archive=ROOT/'build/maxmade-7.0.6.MAX19.zip'
    assert not delivery.exists() and not archive.exists() and not (stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after'] for r in plan['members']}
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(previous)==set(expected) and len(expected)==1919
    tree(BASE/'payload',previous);tree(BASE/'roundtrip',previous);tree(stage/'payload',expected)
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    print('Packing full MAX19; all 1,919 prior paths retained.',flush=True)
    writer_result=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    keypath=ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json';key=bytes.fromhex(json.loads(keypath.read_bytes())['xor_hex'])
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=verify(stage/'upgrade.lgu',expected,REVISION)
    print('Independent LGU decoding passed; extracting with pinned PC tool.',flush=True)
    extract_result=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log')
    tree(stage/'roundtrip',expected);tree(stage/'payload',expected);tree(BASE/'payload',previous)
    files=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes()) for p in files}
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1919,
        exact_previous_members=1911,changed_members=plan['changed_members'],added_members=[],missing_members=[],
        writer=writer_result,extractor=extract_result,container_verification=result,byte_verification=proof,
        source_pins=pins,native_executed=False,car_tested=False,flashed=False,published=False)
    write(stage/'build-manifest.json',manifest)
    shutil.copytree(ROOT/'build/maxmade-7.0.6.MAX18',delivery)
    for name in ['upgrade.lgu','build-manifest.json','member-plan.json','verification.json','runtime.json']:
        shutil.copyfile(stage/name,delivery/name)
    for name in ['analyze_debug_logs.py']:
        shutil.copyfile(ROOT/'tools'/name,delivery/name)
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for path in files:
        target=delivery/'build-sources'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,target);assert sha(target.read_bytes())==pins[path.relative_to(ROOT).as_posix()]
    evidence=delivery/'debugging-evidence';evidence.mkdir()
    for path in stage.glob('*.json'):shutil.copyfile(path,evidence/path.name)
    previews=ROOT/'build/max19-debugging-previews-01'
    shutil.copytree(previews,delivery/'previews/debugging')
    earlier={p.relative_to(ROOT/'build/maxmade-7.0.6.MAX18').as_posix() for p in (ROOT/'build/maxmade-7.0.6.MAX18').rglob('*') if p.is_file()}
    after={p.relative_to(delivery).as_posix() for p in delivery.rglob('*') if p.is_file()}
    assert earlier<=after,'Previous delivery files must also remain available'
    paths=sorted(p for p in delivery.rglob('*') if p.is_file() and p.name!='SHA256SUMS.txt')
    sums=''.join(sha(p.read_bytes())+'  '+p.relative_to(delivery).as_posix()+'\n' for p in paths)
    (delivery/'SHA256SUMS.txt').write_text(sums,encoding='ascii')
    for line in sums.splitlines():digest,name=line.split('  ',1);assert sha((delivery/name).read_bytes())==digest
    with zipfile.ZipFile(archive,'w',zipfile.ZIP_DEFLATED) as z:
        for path in sorted(delivery.rglob('*')):
            if path.is_file():z.write(path,REVISION+'/'+path.relative_to(delivery).as_posix())
    with zipfile.ZipFile(archive) as z:
        assert z.testzip() is None and sha(z.read(REVISION+'/upgrade.lgu'))==result['lgu_sha256']
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    summary=dict(passed=True,lgu=str(delivery/'upgrade.lgu'),zip=str(archive),sha256=result['lgu_sha256'],
        bytes=result['bytes'],members=1919,prior_paths_retained=1919,byte_exact_previous_members=1911,
        checks=proof['cases'],source_files=len(pins),delivery_files=len(paths),car_test_pending=True)
    write(stage/'package-verification.json',summary);return summary


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);a=p.parse_args();print(json.dumps(package(a.stage),indent=2))
