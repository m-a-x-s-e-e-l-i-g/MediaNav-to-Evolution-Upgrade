"""Full MAX30 successor; all MAX29 delivery and payload paths are retained."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from build_max30 import ROOT,BASE,BASE_SHA,REVISION
from debug_image import sha
from package_max16 import tree,write
from package_max29 import dependencies as previous_dependencies,GUIDE as RECOVERY_GUIDE

GUIDE="""# MAXmade 7.0.6.MAX30 - quieter diagnostics candidate

Complete successor to MAX29. All 1,920 payload paths retained; 1,917 files exact.
Only CmnDll.dll, NNG nngnavi.exe and Version_Info.txt change. The On/Off Settings
control, artwork/MICOM/source-switch client bytes and recovery executables are
unchanged. This inherits MAX29's unvalidated ROM boot changes: bench validation
is still required before public release. No physical speedup is claimed.

## Quieter logging

- GPS: RMC/GGA/GSA fix/talker/acceptance changes remain immediate. GGA satellite
  count-only changes wait for the 30-second per-kind heartbeat. GSV zero/nonzero
  visibility changes remain immediate; nonzero count and fragment-acceptance
  chatter wait for the heartbeat. VTG/other sentence metadata is omitted.
  The native GPS input, parser and returned values are unchanged. No coordinates
  are added. Historical detailed MAX24/27 builds and default builder paths remain.
- Navigation: omit only empty UI categories. Count actual activity even when its
  measured duration is zero. Keep every five-second RAM/native-pool sample,
  action start/end and before/after memory observations, plus slow-call summaries.
- Native debug text: retain the first exact bounded normalized message and repeat
  it at most once per ten seconds while unchanged. A changed message, adapter or
  level emits immediately when admission is available. Long/truncated messages
  are not deduplicated. All original CE debug calls still receive every message.
- Event 906 (module 1) reports the saturating cumulative count of deliberately
  suppressed native repetitions at the existing ten-second writer sample.
  It is separate from event 901 dropped-record counts. The total is shared across
  native messages, not a per-message error count or a severity classifier.
- Routine GPS/UI/RAM/artwork-poll summaries can fill at most 224 of 256 queue
  entries and use the first 96 of the existing 128-record/s shared rate budget.
  This reserves 32 slots and 32 records/s against routine telemetry flooding for
  native text and unclassified/startup/source/artwork/MICOM/action diagnostics.
  Unknown native text gets reserved admission because its severity is unknown.
  No spinning, blocking producer waits or producer USB writes are added. Full
  queues, contention, critical traffic itself and the global cap can still drop
  diagnostics. Suppression counters are not evidence that every error was saved.

Use build-sources/tools/analyze_debug_logs30.py with Python to analyze new or old
logs. Missing UI categories are not recorded zero-activity intervals; compact
GPS sampling does not mean the receiver was silent between observations.

See quiet-logging-evidence for actual MIPS tests and optional recorded-metadata
replay. Replay measures retained record counts, not CPU usage or car timing.
All earlier hardware-acceptance limits (iPhone artwork, GPS/RVC, navigation and
boot recovery) remain. The prior independent issue56 repair kit targets its own
pinned kernel/payload and is not replaced or silently upgraded by this package.

## Inherited recovery design and hardware limits

The following MAX29 notes describe the unchanged inherited boot/recovery bytes.

"""+RECOVERY_GUIDE

def dependencies():
    seen=set(previous_dependencies());pending=[ROOT/'tools'/n for n in ['debug_runtime30.py','navigation_probe30.py','build_max30.py','verify_quiet_logging30.py','verify_max30.py','analyze_debug_logs30.py','replay_quiet_logging30.py','package_max30.py']]
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
    delivery=ROOT/'build/maxmade-7.0.6.MAX30';archive=ROOT/'build/maxmade-7.0.6.MAX30.zip'
    assert not delivery.exists()and not archive.exists()and not(stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after']for r in plan['members']}
    prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(prior)==set(expected)and len(expected)==1920 and plan['retained_members']==1917
    tree(stage/'payload',expected);tree(BASE/'payload',prior);assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    w=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    key=bytes.fromhex(json.loads((ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json').read_bytes())['xor_hex'])
    fn=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=fn(stage/'upgrade.lgu',expected,REVISION)
    e=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log');tree(stage/'roundtrip',expected)
    paths=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes())for p in paths}
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1920,exact_previous_members=1917,
        changed_members=plan['changed_members'],added_members=plan['added_members'],missing_members=[],writer=w,extractor=e,
        container_verification=result,byte_verification=proof,source_pins=pins,car_tested=False,flashed=False,published=False,
        NK_ROM_launcher_changed=False,inherits_MAX29_boot_candidate=True,bootloader_and_MCU_unchanged=True,universal_recovery_guarantee=False)
    write(stage/'build-manifest.json',manifest)
    old=ROOT/'build/maxmade-7.0.6.MAX29';shutil.copytree(old,delivery)
    for n in ['upgrade.lgu','build-manifest.json','member-plan.json']:shutil.copyfile(stage/n,delivery/n)
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for p in paths:
        dest=delivery/'build-sources'/p.relative_to(ROOT);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(p,dest)
    evidence=delivery/'quiet-logging-evidence';evidence.mkdir()
    for n in ['CmnDll.dll.json','runtime.json','boot-recovery-verification.json','inherited-verification.json','quiet-logging-verification.json','recorded-metadata-replay.json','verification.json']:
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
         exact_previous_members=1917,checks=proof['cases'],source_files=len(pins),car_test_pending=True)
    write(stage/'package-verification.json',summary);print(json.dumps(summary,indent=2));return summary

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);a=p.parse_args();package(a.stage.resolve())
