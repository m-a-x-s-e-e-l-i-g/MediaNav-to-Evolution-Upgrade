"""Full MAX19 successor, independently decoded and separately PC-extracted."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from debug_image import sha
from build_max24 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import tree,write


GUIDE="# MAXmade 7.0.6.MAX24 — Micom/RVC and GPS diagnostic candidate\n\nFull MAX23 successor: all 1,919 previous payload paths retained; 1,915 byte-exact.\nChanges: MicomManager.exe, nngnavi.exe, CmnDll.dll diagnostic header and version.\nAppMain, Bluetooth/audio/artwork, Settings redraw, source-switch optimization,\nUSB managers, resources, maps/licenses/user saves and all previous improvements\nare retained. Kernel, DBoot and firmware.hex inputs stay byte-exact.\n\n## Purpose and limits\n\nThis is a targeted reporter test for GitHub issues #52/#53/#54 on a 2014 Captur\noriginally running 4.0.6. It contains two verified native failure-path guards:\n\n- Native RVC/GPS-fitted buttons previously left their local bit toggled even when\n  the native write returned failure. MAX24 restores that bit before native redraw\n  on failure; successful commands and the native retry policy remain unchanged.\n- Both service-window creation paths previously passed NULL into the native\n  window creator after failed allocation. MAX24 stops that call and reports the\n  allocation error instead. The observed reporter restart is not yet attributed\n  to allocation failure; a successful allocation keeps the original behavior.\n\nDSI_Config sends a CAN-configuration request; it is not a generic Save button.\nThe 3746 and 3748 service entries select different native paths. 3748 requests\npower state 2 and then a separate service screen. MAX24 records those paths and\nretains their power policy rather than changing a service code blindly.\n\nGPS diagnosis is read-only: observe sentences already passed into NNG's existing\nNMEA dispatcher. No additional COM4 handle is opened, and no GPS receiver\nconfiguration, date, maps, home address, routing or navigation save is changed.\nLogs include talker (GP/GN/etc), raw RMC validity, GGA fix/satellites used, GSA\nmode, GSV satellites visible and native parser acceptance. No coordinates or raw\nsentence text are copied by this observer. Unchanged observations are sampled\nroughly every five seconds per bucket; marker/acceptance changes emit sooner.\nRaw status and parser acceptance do not independently certify a valid GPS fix.\n\nMicom structured events 400-406 capture entry, native command duration/return,\nrequested RVC/GPS bits and test-write blocking. Missing end events may result\nfrom rotation, dropped records or power loss; they do not alone prove a crash.\n\n## Reporter procedure\n\nUse REPORTER-TEST-PLAN.md. Enable Debugging in Settings with a USB stick inserted,\nwait for Logging active, and capture navigation first, then one service-menu\nattempt. Reboot normally and confirm RVC state only if its write succeeds.\nKeep every log chunk. Share logs privately; existing native diagnostics may\ncontain device details even though the new GPS observer omits coordinates.\n\nDo not treat the candidate as a confirmed GPS or camera fix for the reporter.\nThe user-visible result, installed camera and receiver behavior need that unit's\nphysical test. The added logs are intended to choose a narrow follow-up fix.\n\n## Validation\n\nWritten-MIPS tests reproduce the predecessor's stale RVC/GPS bits after rejected\nwrites and native low-address stores after NULL allocations; candidate branches\nrestore the bit and avoid the invalid call. Success paths, native command bytes,\narguments/stack/registers/v0/v1/LastError and delay slots remain covered. GPS\nfixtures cover every GGA truncation, bounded scanning, metadata/throttling,\nbackend load/symbol failures and concurrent-resolution no-wait behavior.\nInherited MAX23 tests retain Settings, persistence, log uniqueness, Bluetooth,\nartwork, navigation and source-switch coverage. Both Micom and NNG preserve\nstock RELOCS_STRIPPED/fixed-base policy; no native firmware runs on the PC.\n\nThe full LGU is independently decoded, separately extracted by the pinned PC\ntool, and compared by complete member hashes. ZIP CRC and source pins are\nverified. Prior full delivery files are retained. No owner's maps, navigation\nhistory, phonebook, GPS locations or raw car logs are included in this package.\n\nAnalyze logs with:\npython analyze_debug_logs.py PATH_TO_LOGS --output summary.json\n"


def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max24.py','micom_diag24.py','gps_probe24.py','debug_runtime24.py',
        'verify_max24.py','verify_max23.py','verify_issues24.py','analyze_debug_logs24.py','package_max24.py']]
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
    delivery=ROOT/'build/maxmade-7.0.6.MAX24';archive=ROOT/'build/maxmade-7.0.6.MAX24.zip'
    assert not delivery.exists() and not archive.exists() and not (stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes());assert proof['passed']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after'] for r in plan['members']}
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(previous)==set(expected) and len(expected)==1919
    tree(BASE/'payload',previous);tree(BASE/'roundtrip',previous);tree(stage/'payload',expected)
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    print('Packing full MAX24; all 1,919 prior paths retained.',flush=True)
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
    shutil.copytree(ROOT/'build/maxmade-7.0.6.MAX23',delivery)
    for name in ['upgrade.lgu','build-manifest.json','member-plan.json','verification.json','runtime.json']:
        shutil.copyfile(stage/name,delivery/name)
    for name in ['analyze_debug_logs21.py','analyze_debug_logs_legacy.py']:
        shutil.copyfile(ROOT/'tools'/name,delivery/name)
    shutil.copyfile(ROOT/'tools/analyze_debug_logs22.py',delivery/'analyze_debug_logs22.py')
    shutil.copyfile(ROOT/'tools/analyze_debug_logs24.py',delivery/'analyze_debug_logs24.py')
    shutil.copyfile(ROOT/'tools/analyze_debug_logs24.py',delivery/'analyze_debug_logs.py')
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    shutil.copyfile(ROOT/'analysis/issue52-reporter-test-plan.md',delivery/'REPORTER-TEST-PLAN.md')
    for path in files:
        target=delivery/'build-sources'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,target);assert sha(target.read_bytes())==pins[path.relative_to(ROOT).as_posix()]
    evidence=delivery/'micom-gps-evidence';evidence.mkdir()
    for path in stage.glob('*.json'):shutil.copyfile(path,evidence/path.name)
    for path in (stage/'nng').glob('*.json'):shutil.copyfile(path,evidence/path.name)
    earlier={p.relative_to(ROOT/'build/maxmade-7.0.6.MAX23').as_posix() for p in (ROOT/'build/maxmade-7.0.6.MAX23').rglob('*') if p.is_file()}
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

