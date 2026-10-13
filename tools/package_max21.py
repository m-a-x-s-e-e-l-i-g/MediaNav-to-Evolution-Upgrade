"""Full MAX19 successor, independently decoded and separately PC-extracted."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from debug_image import sha
from build_max21 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import tree,write


GUIDE="# MAXmade 7.0.6.MAX21 â€” measured performance and lower log volume\n\nFull MAX20 successor. All 1,919 firmware paths remain; 1,915 are byte-exact.\nOnly AppMain.exe, Blue.exe, CmnDll.dll and Version_Info.txt change. CmnDll's\nruntime instructions are byte-exact to MAX20: only its diagnostic header and\nPE checksum change. The saved Debugging setting, background repaint and\nnon-overwriting session files from MAX20 are retained.\n\n## What changes\n\nThe frequent Blue artwork check still runs on its original schedule and follows\nthe original publication/retry path. Idle checks no longer write begin/end pairs.\nA ten-second summary reports poll count and maximum elapsed call time. Nonzero\nresults (publication/retry) and calls taking at least 16 ms are still recorded.\nThe existing native error/debug text is not filtered. In the instruction fixture,\n120 idle checks produce five summaries rather than 240 records.\n\nSource switching now measures each of the three conditional 200 ms wait sites,\nsynchronous IPC sends (including retries), IPC gets and IPC posts. Arguments,\ndelay slots, native waits, manager readiness and audio behavior are retained.\nThese measurements establish where the aggregate 859 ms delay is spent; this\nbuild does not claim faster source switching or shorten waits.\n\nArtwork measurements separate JPEG validation, factory creation, image-from-\nbuffer, image information, bitmap allocation, image drawing and object release.\nThere are global RAM snapshots before/after decoding and counters for successful\nartwork bitmap creation/deletion while debugging is enabled. Failed allocation\nor deletion has an explicit raw result. These counts are not a complete inventory\nof handles predating logging or operations occurring while debugging is Off.\nRAM snapshots are OS totals, not per-process allocation ownership.\n\nThe MAX19 capture showed about 9.4 MiB of memory growth during playback, followed\nby about 18.9 MiB released during shutdown/disconnection. That does not establish\nor rule out a leak. Native bitmap ownership/cleanup stays unchanged while the\nnew trace helps identify missing deletions versus other retained resources.\n\n## Use and comparison\n\nInstall the full LGU using the established procedure and confirm 7.0.6.MAX21.\nSettings > System > page 2 > Debugging enables external USB captures in\nMAXmade/logs/. Allow two seconds after changing the setting before cutting power.\nSessions use CREATE_NEW names and remain until owner deletion; USB full stops\nlogging without deleting earlier files. Config uses the two small internal-card\nslots from MAX20. No log data is written to internal cards.\n\nCapture the following separately with logging continuously On:\n\n1. Five minutes playing the same Bluetooth track without interaction.\n2. Five minutes with repeated Bluetooth track/artwork changes.\n3. Several FM/Bluetooth/USB source switches and Settings page changes.\n4. The end of playback and shutdown/disconnection.\n\nCheck media/artwork/navigation and Settings with debugging both On and Off.\nThe inherited MAX20 fixes still need cold-ignition and real screen confirmation.\nCopy the entire logs folder and run:\npython analyze_debug_logs.py PATH_TO_LOGS --output summary.json\nThe updated analyzer separates poll counts and memory/bitmap snapshots from\nelapsed timings. It also accepts surviving MAX19 and MAX20 logs.\n\n## Verification boundary\n\nActual emitted MIPS instructions are interpreted with explicit CE/clock/file/GDI\nfixtures. Arguments, dynamic call targets, original delay slots, v0/v1, LastError,\nnonvolatile registers, rebasing and inherited functionality are checked.\nThe package is independently decoded and separately extracted by pinned PC\ntools. Actual overhead, source responsiveness, bitmap failure rates and sustained\nRAM behavior still require the car capture. No leak or car performance fix is\nclaimed from offline measurements. Original releases and backup remain intact.\n"


def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max21.py','debug_metrics21.py','debug_runtime21.py','debug_clients21.py',
        'verify_max21.py','verify_clients21.py','analyze_debug_logs21.py','analyze_debug_logs_legacy.py',
        'prepare_debug21.py','prepare_verify21.py','replay_poll_logs21.py','prepare_package21.py','package_max21.py']]
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
    delivery=ROOT/'build/maxmade-7.0.6.MAX21';archive=ROOT/'build/maxmade-7.0.6.MAX21.zip'
    assert not delivery.exists() and not archive.exists() and not (stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after'] for r in plan['members']}
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(previous)==set(expected) and len(expected)==1919
    tree(BASE/'payload',previous);tree(BASE/'roundtrip',previous);tree(stage/'payload',expected)
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    print('Packing full MAX21; all 1,919 prior paths retained.',flush=True)
    writer_result=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    keypath=ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json';key=bytes.fromhex(json.loads(keypath.read_bytes())['xor_hex'])
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=verify(stage/'upgrade.lgu',expected,REVISION)
    print('Independent LGU decoding passed; extracting with pinned PC tool.',flush=True)
    extract_result=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log')
    tree(stage/'roundtrip',expected);tree(stage/'payload',expected);tree(BASE/'payload',previous)
    files=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes()) for p in files}
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1919,
        exact_previous_members=1915,changed_members=plan['changed_members'],added_members=[],missing_members=[],
        writer=writer_result,extractor=extract_result,container_verification=result,byte_verification=proof,
        source_pins=pins,native_executed=False,car_tested=False,flashed=False,published=False)
    write(stage/'build-manifest.json',manifest)
    shutil.copytree(ROOT/'build/maxmade-7.0.6.MAX20',delivery)
    for name in ['upgrade.lgu','build-manifest.json','member-plan.json','verification.json','runtime.json']:
        shutil.copyfile(stage/name,delivery/name)
    for name in ['analyze_debug_logs21.py','analyze_debug_logs_legacy.py']:
        shutil.copyfile(ROOT/'tools'/name,delivery/name)
    shutil.copyfile(ROOT/'tools/analyze_debug_logs21.py',delivery/'analyze_debug_logs.py')
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for path in files:
        target=delivery/'build-sources'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,target);assert sha(target.read_bytes())==pins[path.relative_to(ROOT).as_posix()]
    evidence=delivery/'metrics-evidence';evidence.mkdir()
    for path in stage.glob('*.json'):shutil.copyfile(path,evidence/path.name)
    earlier={p.relative_to(ROOT/'build/maxmade-7.0.6.MAX20').as_posix() for p in (ROOT/'build/maxmade-7.0.6.MAX20').rglob('*') if p.is_file()}
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
        bytes=result['bytes'],members=1919,prior_paths_retained=1919,byte_exact_previous_members=1915,
        checks=proof['cases'],source_files=len(pins),delivery_files=len(paths),car_test_pending=True)
    write(stage/'package-verification.json',summary);return summary


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);a=p.parse_args();print(json.dumps(package(a.stage),indent=2))
