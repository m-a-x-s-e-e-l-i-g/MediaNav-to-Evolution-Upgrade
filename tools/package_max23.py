"""Full MAX19 successor, independently decoded and separately PC-extracted."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from debug_image import sha
from build_max23 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import tree,write


GUIDE="# MAXmade 7.0.6.MAX23 — Bluetooth source-switch settling budget\n\nComplete successor to MAX22: all 1,919 payload paths retained, 1,916 byte-exact.\nAppMain.exe, CmnDll.dll and Version_Info.txt change. Existing Settings redraw,\nsaved debugging On/Off, unique log sessions, artwork, Bluetooth, navigation,\nUSB, volume and manager behavior are retained. Kernel/MCU/DBoot remain exact.\n\n## Source-switch change\n\nA2DPPlay previously issued a successful Bluetooth play request, performed native\nsource lookup/logging, slept 200 ms and then slept another 200 ms in the shared\nfade helper. MAX23 counts elapsed work toward the same settling windows:\n200 ms before the playback continuation, 400 ms before the fade IPC. Scheduling\nor logging work between these points no longer adds another full delay.\nThe native play command, UI notifications and fade IPC stay in their original\norder. The separate source-selection 200 ms, navigation/audio 50 ms, overlay\n500 ms and other audio paths retain their native waits.\n\nThe timestamp belongs to this invocation's unused stack word; no shared mutable\ntimer or background request can supply a stale deadline. GetTickCount unsigned\nsubtraction handles wraparound. Failed play requests, absent timestamps and\nother fade callers keep the original waits. A shortened request is bounded\nbetween 0 and the original 200 ms. Logging remains available with requested\nremaining milliseconds in event 134/135 results.\n\nThis is a limited optimization, not a claim that the 650 ms synchronization\nbudget disappeared. Interpreter examples with 10/30/100 ms of intervening work\nremove exactly that added time; scheduler lateness also counts toward the second\nwait. The supplied older car logs do not measure MAX23. Actual speed/audio,\nphone/navigation interruption and repeated rapid switching need a car check.\nA successful command return is used only as the start of a retained time budget;\nit is not treated as proof that the hardware is ready.\n\n## Car check\n\nConfirm version 7.0.6.MAX23. Compare repeated FM-to-Bluetooth and back switches\nwith MAX22, with debugging On and Off. Test a phone already playing, paused\nplayback, absent/disconnected phone, USB, navigation prompts and phone calls.\nListen for missing audio, a clipped beginning or clicks. Confirm Settings rows\nand toggles are visible immediately, and saved debugging returns after restart.\nAllow two seconds after a debugging toggle before switching off the car.\nCollect every USB log chunk; sessions remain until you delete them. Low free\nspace stops logging without deletion. Analyze using:\npython analyze_debug_logs.py PATH_TO_LOGS --output summary.json\n\n## Verification and preservation\n\nWritten MIPS tests compare the full native A2DPPlay/fade path in MAX22 and MAX23,\nincluding success/failure, logging On/Off, intervening work, scheduler delays,\nrelocated code, tick wrap, caller ownership, stack/register/error preservation.\nInherited Settings rendering, persistent config, non-overwriting files, bitmap\nlifetimes, navigation and source jump-table tests are also retained. Full LGU\nverification uses an independent decoder and separately pinned PC extractor,\ncomplete payload hashes, frozen source pins and ZIP CRC checks.\n\nNo firmware executes natively on the PC. Native CE scheduling/audio/display and\nthe car acceptance check remain outstanding. Prior complete packages and sources\nremain available. Private owner logs are excluded. No device flash or public\npublication is performed by the builder.\n"


def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max23.py','debug_clients23.py','debug_metrics23.py','debug_runtime23.py',
        'verify_max23.py','verify_redraw22.py','verify_settings22.py','verify_persistence22.py','verify_metrics23.py',
        'analyze_debug_logs22.py','source_budget23.py','verify_source23.py','package_max23.py']]
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
    delivery=ROOT/'build/maxmade-7.0.6.MAX23';archive=ROOT/'build/maxmade-7.0.6.MAX23.zip'
    assert not delivery.exists() and not archive.exists() and not (stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after'] for r in plan['members']}
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(previous)==set(expected) and len(expected)==1919
    tree(BASE/'payload',previous);tree(BASE/'roundtrip',previous);tree(stage/'payload',expected)
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    print('Packing full MAX23; all 1,919 prior paths retained.',flush=True)
    writer_result=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    keypath=ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json';key=bytes.fromhex(json.loads(keypath.read_bytes())['xor_hex'])
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=verify(stage/'upgrade.lgu',expected,REVISION)
    print('Independent LGU decoding passed; extracting with pinned PC tool.',flush=True)
    extract_result=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log')
    tree(stage/'roundtrip',expected);tree(stage/'payload',expected);tree(BASE/'payload',previous)
    files=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes()) for p in files}
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1919,
        exact_previous_members=1916,changed_members=plan['changed_members'],added_members=[],missing_members=[],
        writer=writer_result,extractor=extract_result,container_verification=result,byte_verification=proof,
        source_pins=pins,native_executed=False,car_tested=False,flashed=False,published=False)
    write(stage/'build-manifest.json',manifest)
    shutil.copytree(ROOT/'build/maxmade-7.0.6.MAX22',delivery)
    for name in ['upgrade.lgu','build-manifest.json','member-plan.json','verification.json','runtime.json']:
        shutil.copyfile(stage/name,delivery/name)
    for name in ['analyze_debug_logs21.py','analyze_debug_logs_legacy.py']:
        shutil.copyfile(ROOT/'tools'/name,delivery/name)
    shutil.copyfile(ROOT/'tools/analyze_debug_logs22.py',delivery/'analyze_debug_logs22.py')
    shutil.copyfile(ROOT/'tools/analyze_debug_logs22.py',delivery/'analyze_debug_logs.py')
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for path in files:
        target=delivery/'build-sources'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,target);assert sha(target.read_bytes())==pins[path.relative_to(ROOT).as_posix()]
    evidence=delivery/'source-switch-evidence';evidence.mkdir()
    for path in stage.glob('*.json'):shutil.copyfile(path,evidence/path.name)
    earlier={p.relative_to(ROOT/'build/maxmade-7.0.6.MAX22').as_posix() for p in (ROOT/'build/maxmade-7.0.6.MAX22').rglob('*') if p.is_file()}
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
        bytes=result['bytes'],members=1919,prior_paths_retained=1919,byte_exact_previous_members=1916,
        checks=proof['cases'],source_files=len(pins),delivery_files=len(paths),car_test_pending=True)
    write(stage/'package-verification.json',summary);return summary


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);a=p.parse_args();print(json.dumps(package(a.stage),indent=2))

