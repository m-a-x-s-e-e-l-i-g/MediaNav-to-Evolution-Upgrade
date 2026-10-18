"""Full MAX26 successor, independently decoded and separately PC-extracted."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import build_review_update as container
from debug_image import sha
from build_max27 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import tree,write


GUIDE="""# MAXmade 7.0.6.MAX27 - iPhone cover negotiation candidate

Full MAX26 successor. All 1,919 firmware paths retained, 1,914 byte-identical.
Changes: Blue.exe, AppMain.exe, NNG, diagnostic version/checksum in CmnDll.dll
and Version_Info.txt. Prior fixes, resources, kernel/firmware/DBoot retained.

## What the owner's logs established

The iPhone-labelled connections report remote features 0x00d1 (no cover-art
bit); no iPhone image transfer or decoding is recorded. The Android-labelled
connections report 0x01d1, complete image transfers and 40 successful bitmap
decodes. A historical Cover decoded (D9) fallback is not current-image proof.

MAX27 corrects a local interoperability gap: the native controller SDP record
previously omitted our implemented GetLinkedThumbnail feature. Its reviewed
controller record now advertises AVRCP 1.6 with the CT thumbnail bit 0x0200.
The native target-role advertisement, record allocation, sizes, strings,
AVCTP parameters, audio/metadata commands and all remote capability/endpoint
checks remain unchanged. No unsupported remote bit is forced. This is a tested
local correction and an iPhone candidate, not a confirmed iPhone repair.

The stale D9 fallback now says Waiting for current cover. New low-volume events
350/351 distinguish worker handoff and GUI bitmap ownership/clear. Local
advertisement event 967 says whether the guarded record change was applied.
None of these records alone proves a visible correct-track image.

## Physical test - parked, with USB logging On

1. Install the complete LGU normally and confirm MAX27 in Version Info.
2. Use the iPhone alone, reconnect Bluetooth, open the Bluetooth music screen
   and play Spotify. Wait 20 seconds and skip two tracks, waiting 15 seconds
   after each. Note blank/current/stale artwork and the exact fallback caption.
3. If the old capability still appears in logs, pairing-service caches might
   need refreshing: remove and re-pair this car connection on both ends once,
   then repeat. Re-pairing is a diagnostic option, not an established cause.
4. Disconnect iPhone and repeat briefly with Android to check existing artwork,
   audio, title and playback controls. Clearly label each phone interval.
5. Retain every log session/chunk and share privately. Existing native debug
   text may contain titles, phone identities or locations.

Navigation measurements remain available. If testing navigation, keep one
fixed audio source and perform route start/cancel/Home cycles separately from
phone switching; wait between actions and include a short timeline.

## Performance findings and corrected measurement

The owner's logs show native NNG repaint requests up to 3.917 seconds and
other window handlers up to 4.293 seconds; these are overlapping handler spans,
not additive CPU time. Global free RAM bottoms at 34.9 MiB; native pool pages
reach 75.12 MiB then fall to 13.34 MiB by the final retained observation.
That recovery does not establish a persistent navigation leak. One artwork
decode span is 988ms; individual image drawing reaches 275ms. Source requests
reach 1.373 seconds. These are optimization leads; no new navigation timing,
route-cache eviction, decoder, freshness or audio wait policy is changed here.

MAX26 incorrectly read a native cache-size field while cache mode was off;
the native constructor leaves that field uninitialized. Discard those old
cache-byte values. Page accounting remains usable. MAX27 checks cache mode
before reading size and reports zero for the inactive cache without reading
its uninitialized slot. The included analyzer masks MAX26 cache values as
unknown. Native page accounting is still not a complete process working set.

## Verification and limits

Native SDP formatter and written-MIPS tests cover target/CT roles, legacy and
current versions, strings, debug off/on, malformed/short records, result/error
preservation, native GUI acceptance/rejection cleanup, low-volume events and
cache-disabled uninitialized memory. Original Blue is fixed-base; tests do
not pretend its original native code is relocatable. The added leaf is also
checked independently at alternate bases. All inherited regressions are
required. LGU is independently decoded and separately extracted and every
payload path/hash is checked. Physical iOS behavior, visible pixels, CE
scheduling and actual logging/performance overhead remain car-test pending.

Analyze all chunks with:
python analyze_debug_logs.py PATH_TO_LOGS --output summary.json
"""


def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max27.py','navigation_probe27.py','debug_runtime27.py','iphone_cover27.py','artwork_acceptance27.py',
        'verify_max27.py','verify_iphone27.py','analyze_debug_logs27.py','package_max27.py']]
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
    delivery=ROOT/'build/maxmade-7.0.6.MAX27';archive=ROOT/'build/maxmade-7.0.6.MAX27.zip'
    assert not delivery.exists() and not archive.exists() and not (stage/'upgrade.lgu').exists()
    proof=json.loads((stage/'verification.json').read_bytes())
    # A failed newer test must not leave an inherited interim result
    # eligible for packaging. Only the complete MAX27 combined suite qualifies.
    assert proof['passed'] and proof['cases']>=658
    assert 'MAX27 analyzer invalidates historical MAX26 cache bytes and separates handoff, GUI ownership and local advertisement' in proof['checks']
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after'] for r in plan['members']}
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert set(previous)==set(expected) and len(expected)==1919
    tree(BASE/'payload',previous);tree(BASE/'roundtrip',previous);tree(stage/'payload',expected)
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    print('Packing full MAX27; all 1,919 prior paths retained.',flush=True)
    writer_result=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    keypath=ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json';key=bytes.fromhex(json.loads(keypath.read_bytes())['xor_hex'])
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=verify(stage/'upgrade.lgu',expected,REVISION)
    print('Independent LGU decoding passed; extracting with pinned PC tool.',flush=True)
    extract_result=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log')
    tree(stage/'roundtrip',expected);tree(stage/'payload',expected);tree(BASE/'payload',previous)
    files=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes()) for p in files}
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1919,
        exact_previous_members=1914,changed_members=plan['changed_members'],added_members=[],missing_members=[],
        writer=writer_result,extractor=extract_result,container_verification=result,byte_verification=proof,
        source_pins=pins,native_executed=False,car_tested=False,flashed=False,published=False)
    write(stage/'build-manifest.json',manifest)
    shutil.copytree(ROOT/'build/maxmade-7.0.6.MAX26',delivery)
    for name in ['upgrade.lgu','build-manifest.json','member-plan.json','verification.json','runtime.json']:
        shutil.copyfile(stage/name,delivery/name)
    for name in ['analyze_debug_logs21.py','analyze_debug_logs_legacy.py']:
        shutil.copyfile(ROOT/'tools'/name,delivery/name)
    shutil.copyfile(ROOT/'tools/analyze_debug_logs22.py',delivery/'analyze_debug_logs22.py')
    shutil.copyfile(ROOT/'tools/analyze_debug_logs24.py',delivery/'analyze_debug_logs24.py')
    shutil.copyfile(ROOT/'tools/analyze_debug_logs25.py',delivery/'analyze_debug_logs25.py')
    shutil.copyfile(ROOT/'tools/analyze_debug_logs26.py',delivery/'analyze_debug_logs26.py')
    shutil.copyfile(ROOT/'tools/analyze_debug_logs27.py',delivery/'analyze_debug_logs27.py')
    shutil.copyfile(ROOT/'tools/analyze_debug_logs27.py',delivery/'analyze_debug_logs.py')
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    shutil.copyfile(ROOT/'analysis/issue52-reporter-test-plan.md',delivery/'REPORTER-TEST-PLAN.md')
    for path in files:
        target=delivery/'build-sources'/path.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,target);assert sha(target.read_bytes())==pins[path.relative_to(ROOT).as_posix()]
    evidence=delivery/'iphone-negotiation-evidence';evidence.mkdir()
    for path in stage.glob('*.json'):shutil.copyfile(path,evidence/path.name)
    for path in (stage/'nng').glob('*.json'):shutil.copyfile(path,evidence/path.name)
    earlier={p.relative_to(ROOT/'build/maxmade-7.0.6.MAX26').as_posix() for p in (ROOT/'build/maxmade-7.0.6.MAX26').rglob('*') if p.is_file()}
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
        bytes=result['bytes'],members=1919,prior_paths_retained=1919,byte_exact_previous_members=1914,
        checks=proof['cases'],source_files=len(pins),delivery_files=len(paths),car_test_pending=True)
    write(stage/'package-verification.json',summary);return summary


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);a=p.parse_args();print(json.dumps(package(a.stage),indent=2))
