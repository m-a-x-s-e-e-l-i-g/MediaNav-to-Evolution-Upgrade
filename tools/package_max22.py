"""Full MAX19 successor, independently decoded and separately PC-extracted."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from debug_image import sha
from build_max22 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import tree,write


GUIDE="# MAXmade 7.0.6.MAX22 — immediate Settings redraw\n\nFull MAX21 successor: all 1,919 payload paths retained, 1,916 byte-exact.\nOnly AppMain.exe, CmnDll.dll and Version_Info.txt change. Blue and the other\ninstrumented managers, resources, navigation, DBoot, kernel and MCU input remain.\n\n## Settings correction\n\nMAX20/21's full-window erasure could clear native cached controls without\nredrawing them. Debugging now uses the original immediate control-drawing path.\nThe status label enables the native background-restoration flag, so old text is\ncleared only within its own rectangle. Both rows are presented through the\nnative rectangle-blit path, including cached-surface mode. Native paint finishes\nbefore the two rows are refreshed. Hidden parent presentation stays subject to\nthe original native guards. Toggle draws immediately; writer state changes use\na non-erasing notification. No Version Info detour should be necessary.\n\nThe saved On/Off setting, asynchronous writer, unique CREATE_NEW log files,\nlower-volume poll summaries and MAX21 artwork/RAM diagnostics are retained.\nAllow two seconds after toggling before switching off the car. Log files remain\non external USB until you delete them; low space stops logging without deletion.\n\n## New log findings\n\nThe supplied MAX21 captures have 1,435 valid records. All 11 tracked artwork\nbitmap creations have successful deletion records; no failed create/delete or\naccumulating bitmap imbalance is visible. A broader memory leak is not ruled out\nby these shorter captures. Main-capture RAM settles around 94–95 MiB free after\nstartup. Artwork drawing is the largest decoder stage, up to 68 ms; total decode\nis up to 114 ms. IPC calls are mostly 10–30 ms.\n\nFM-to-Bluetooth switches take up to 906 ms. Native code has a 200 ms source wait,\na 50 ms navigation/audio wait, a 200 ms playback wait and a further 200 ms fade\nwait on the observed path. MAX22 adds timings for the nested waits and fade IPC.\nTheir synchronization/order is retained; replacing them needs a validated native\nreadiness condition. No faster audio transition is claimed for this release.\n\nThe early Navigation Not ready messages precede completed navigation startup;\nDAB destination failures still coincide with ACC OFF. They remain logged. The\nrestart capture logs managers and AppMain before menu interaction, supporting\nrestoration of the saved debugging setting. The 18-drop counter in the warm\ncapture is already present initially and stays constant; the restart has zero.\n\n## Car verification\n\nConfirm 7.0.6.MAX22 after the established full-update procedure. Open Settings\ndirectly: the options and Debugging rows should appear immediately. Toggle\nseveral times, change other settings, switch pages/themes and check Version Info\nand return. Text should update immediately without overlap. Also check live\nUSB waiting/active/off transitions without navigating away.\n\nCheck music, artwork, navigation and source switches with debugging On and Off.\nCollect a longer continuous capture with the same track versus track changes,\nplus FM/Bluetooth switches and shutdown. The added wait timings establish the\nunmeasured part of the transition. Copy all log chunks and run:\npython analyze_debug_logs.py PATH_TO_LOGS --output summary.json\n\n## Validation boundary\n\nActual label-renderer and rectangle-present MIPS instructions are exercised with\nexplicit background/text/BitBlt GDI boundaries in normal and cached modes. The\ntransparent-label fixture reproduces old glyph remnants; native opaque restore\nclears them. Other written-byte fixtures cover first-page/toggle draw requests,\nthemes, post-paint ordering/ABI, all phase calls, persistent configuration,\nnon-overwriting files, polling, native bitmap lifetimes and navigation.\nActual screen behavior and timings still need the car check. Source/backup and\nprevious releases are retained; raw owner logs are excluded from the package.\n"


def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max22.py','debug_clients22.py','debug_metrics22.py','debug_runtime22.py',
        'verify_max22.py','verify_redraw22.py','verify_settings22.py','verify_persistence22.py','verify_metrics22.py',
        'analyze_debug_logs22.py','prepare_debug22.py','prepare_verify22.py','prepare_package22.py','package_max22.py']]
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
    delivery=ROOT/'build/maxmade-7.0.6.MAX22';archive=ROOT/'build/maxmade-7.0.6.MAX22.zip'
    assert not delivery.exists() and not archive.exists() and not (stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after'] for r in plan['members']}
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(previous)==set(expected) and len(expected)==1919
    tree(BASE/'payload',previous);tree(BASE/'roundtrip',previous);tree(stage/'payload',expected)
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    print('Packing full MAX22; all 1,919 prior paths retained.',flush=True)
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
    shutil.copytree(ROOT/'build/maxmade-7.0.6.MAX21',delivery)
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
    evidence=delivery/'settings-redraw-evidence';evidence.mkdir()
    for path in stage.glob('*.json'):shutil.copyfile(path,evidence/path.name)
    earlier={p.relative_to(ROOT/'build/maxmade-7.0.6.MAX21').as_posix() for p in (ROOT/'build/maxmade-7.0.6.MAX21').rglob('*') if p.is_file()}
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
