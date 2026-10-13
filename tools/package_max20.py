"""Full MAX19 successor, independently decoded and separately PC-extracted."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from debug_image import sha
from build_max20 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import tree,write


GUIDE='# MAXmade 7.0.6.MAX20 — debugging fixes\n\nFull MAX19 successor: all 1,919 firmware paths retained, 1,916 byte-exact.\nOnly CmnDll.dll, AppMain.exe and Version_Info.txt change. Every previous\nmedia/navigation fix, image, font, kernel, DBoot and MCU input is inherited.\n\nSettings > System > page 2 > Debugging: On/Off now saves to two validated\n16-byte files in \\Storage Card2\\MAXmade\\debug-0.cfg and debug-1.cfg.\nThe background worker writes the inactive file, flushes, closes and reads it\nback before accepting the save. At boot the newest valid file wins. A damaged\ninactive file leaves the older valid setting available. MAX19\'s registry value\nis used only to migrate when neither file is valid. Both On and Off are saved.\nAllow two seconds after changing the setting before switching off the car.\nA failed save is reported as "Setting could not be saved" and retried.\n\nSettings redraw uses the native page/background paint. It no longer draws the\nnew status directly over old glyphs. Status changes request a full repaint.\n\nUSB logs remain in MAXmade/logs/ on the external native \\MD mount. Every new\nchunk has a date/time, session-start tick and counter in its filename. Creation\nuses CREATE_NEW: even a wrong clock or duplicate filename cannot overwrite an\nexisting file. MAX19\'s debug-0.log through debug-7.log are also preserved.\nFiles split at 4 MiB; all sessions/chunks stay saved until you delete them.\nBelow 16 MiB free, logging stops and shows USB full. No files are automatically\ndeleted. Collision retries are bounded per worker iteration.\n\nThe original bounded shared queue, native error capture, timings, RAM/drop\nsamples, periodic flush, late USB detection and disabled fast path remain.\nLogs can still lose buffered records at abrupt power loss; this is separate\nfrom preserving existing sessions. Logs never fall back to internal cards.\nOnly the small setting files are written there. Logs contain native diagnostic\ntext and media/device context; inspect them before sharing.\n\n## Car verification\n\n1. Install the complete update using the established procedure and confirm\n   7.0.6.MAX20. Test existing music/navigation with debugging Off.\n2. Enable debugging, wait two seconds and turn the car fully off. Restart with\n   USB inserted: Debugging should still be On and logging should start.\n3. Toggle On/Off repeatedly in light/dark themes and leave/return to Settings.\n   The status should show one clean line. Save Off and check another restart.\n4. Capture two ignition sessions and more than eight chunks. Earlier files,\n   including MAX19 logs, must remain unchanged. Try USB removal/reinsertion.\n\nCopy the entire logs folder and run:\npython analyze_debug_logs.py PATH_TO_LOGS --output summary.json\nExisting tools understand the new debug-*.log names. A raw result or missing\nend event is not proof of completed hardware action or a crash.\n\nWritten MIPS instructions are tested in explicit OS/filesystem/GDI fixtures.\nNative storage durability, touchscreen repaint and sustained car operation\nstill require the physical checks above. This is a local test candidate.\nPrevious releases and the supplied four-card backup remain untouched.\n'


def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max20.py','debug_image.py','debug_config20.py','debug_runtime20.py','debug_clients20.py',
        'verify_max20.py','verify_settings20.py','analyze_debug_logs.py','prepare_debug20.py','prepare_package20.py','package_max20.py']]
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
    delivery=ROOT/'build/maxmade-7.0.6.MAX20';archive=ROOT/'build/maxmade-7.0.6.MAX20.zip'
    assert not delivery.exists() and not archive.exists() and not (stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after'] for r in plan['members']}
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(previous)==set(expected) and len(expected)==1919
    tree(BASE/'payload',previous);tree(BASE/'roundtrip',previous);tree(stage/'payload',expected)
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    print('Packing full MAX20; all 1,919 prior paths retained.',flush=True)
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
    shutil.copytree(ROOT/'build/maxmade-7.0.6.MAX19',delivery)
    for name in ['upgrade.lgu','build-manifest.json','member-plan.json','verification.json','runtime.json']:
        shutil.copyfile(stage/name,delivery/name)
    for name in ['analyze_debug_logs.py']:
        shutil.copyfile(ROOT/'tools'/name,delivery/name)
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    for path in files:
        target=delivery/'build-sources'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,target);assert sha(target.read_bytes())==pins[path.relative_to(ROOT).as_posix()]
    evidence=delivery/'debugging-fixes-evidence';evidence.mkdir()
    for path in stage.glob('*.json'):shutil.copyfile(path,evidence/path.name)
    earlier={p.relative_to(ROOT/'build/maxmade-7.0.6.MAX19').as_posix() for p in (ROOT/'build/maxmade-7.0.6.MAX19').rglob('*') if p.is_file()}
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
