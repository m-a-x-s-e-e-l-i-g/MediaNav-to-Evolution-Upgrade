"""Package a complete MAX17 successor with default Nav warning acceptance."""
import ast
from datetime import datetime, timezone
from pathlib import Path
from types import FunctionType
import json
import shutil
import zipfile
import pefile
import build_review_update as container
from package_max16 import tree, sha, write
from patch_nav_caution import ROOT, OUT as DESIGN, APP, patch

BASE = ROOT / 'build/max17-volume-development-01'
BASE_DELIVERY = ROOT / 'build/maxmade-7.0.6.MAX17'
BASE_SHA = '8c541820c53c56533524ad37f4a5bd7f148f4ff1fdd6faf8bfa9b9cfbc3620ed'
STAGE = ROOT / 'build/max18-navigation-launch-development-01'
DELIVERY = ROOT / 'build/maxmade-7.0.6.MAX18'
ARCHIVE = ROOT / 'build/maxmade-7.0.6.MAX18.zip'
REVISION = '7.0.6.MAX18'


def source_files():
    pending = [Path(__file__), ROOT / 'tools/patch_nav_caution.py', ROOT / 'tools/verify_nav_caution.py']
    found = set()
    while pending:
        path = pending.pop()
        if path in found: continue
        found.add(path)
        for node in ast.walk(ast.parse(path.read_text(encoding='utf-8-sig'))):
            modules = [node.module] if isinstance(node, ast.ImportFrom) else (
                [n.name for n in node.names] if isinstance(node, ast.Import) else [])
            for module in modules:
                if module:
                    candidate = ROOT / 'tools' / (module.split('.')[0] + '.py')
                    if candidate.is_file(): pending.append(candidate)
    return sorted(found)


def build():
    for path in (STAGE, DELIVERY, ARCHIVE):
        assert not path.exists(), f'Fresh output required: {path}'
    previous = {r['path']: r['after'] for r in json.loads((BASE / 'member-plan.json').read_bytes())['members']}
    assert len(previous) == 1919
    for path in (BASE / 'upgrade.lgu', BASE_DELIVERY / 'upgrade.lgu'):
        assert sha(path.read_bytes()) == BASE_SHA
    tree(BASE / 'payload', previous); tree(BASE / 'roundtrip', previous)
    proof = json.loads((DESIGN / 'verification.json').read_bytes())
    assert proof['passed'] and proof['nine_instructions_only']
    candidate, recipe = patch((BASE / 'payload' / APP).read_bytes())
    assert candidate == (DESIGN / 'payload' / APP).read_bytes()
    assert sha(candidate) == proof['output_sha256']
    shutil.copytree(BASE / 'payload', STAGE / 'payload')
    (STAGE / 'payload' / APP).write_bytes(candidate)
    (STAGE / 'payload' / container.VERSION_PATH).write_bytes(REVISION.encode('ascii'))
    expected = dict(previous)
    expected[APP] = dict(bytes=len(candidate), sha256=sha(candidate))
    expected[container.VERSION_PATH] = dict(bytes=len(REVISION), sha256=sha(REVISION.encode('ascii')))
    changed = sorted(n for n in expected if expected[n] != previous[n])
    assert changed == sorted([APP, container.VERSION_PATH]) and set(previous) == set(expected)
    tree(STAGE / 'payload', expected)
    writer, extractor = (ROOT / 'tools/vendor/lgu-favremod' / n for n in ('dir2lgu.exe', 'lgu2dir.exe'))
    for tool, pin in ((writer, container.WRITER_HASH), (extractor, container.EXTRACTOR_HASH)):
        assert sha(tool.read_bytes()) == pin
        pc = pefile.PE(str(tool)); assert pc.FILE_HEADER.Machine == 0x14c; pc.close()
    print('Packing complete MAX18: all 1,919 MAX17 paths retained.', flush=True)
    writer_run = container.run_pc_tool(writer, ['-p', 'm1', REVISION, STAGE / 'payload', STAGE / 'upgrade.lgu'], STAGE / 'dir2lgu.log')
    key_path = ROOT / 'sources/MediaNav-usb-seek-timing/src/container/lgu0.json'
    key = bytes.fromhex(json.loads(key_path.read_bytes())['xor_hex'])
    verify = FunctionType(container.verify_package.__code__, dict(container.verify_package.__globals__, xor_key=lambda: key))
    result = verify(STAGE / 'upgrade.lgu', expected, REVISION)
    print('Independent LGU decoding passed; separate PC extraction next.', flush=True)
    extractor_run = container.run_pc_tool(extractor, [STAGE / 'upgrade.lgu', STAGE / 'roundtrip'], STAGE / 'lgu2dir.log')
    tree(STAGE / 'roundtrip', expected); tree(STAGE / 'payload', expected)
    tree(BASE / 'payload', previous); tree(BASE / 'roundtrip', previous)
    for path in (BASE / 'upgrade.lgu', BASE_DELIVERY / 'upgrade.lgu'):
        assert sha(path.read_bytes()) == BASE_SHA
    files = [*source_files(), key_path, DESIGN / 'recipe.json', DESIGN / 'verification.json']
    pins = {p.relative_to(ROOT).as_posix(): sha(p.read_bytes()) for p in files}
    manifest = dict(revision=REVISION, generated_utc=datetime.now(timezone.utc).isoformat(),
        baseline_revision='7.0.6.MAX17', baseline_lgu_sha256=BASE_SHA, stable_revision='7.0.6.MAX15',
        output_members=1919, prior_paths_retained=1919, unchanged_from_MAX17=1917,
        changed_members=changed, added_members=[], missing_members=[], baseline_unchanged=True,
        navigation_caution=recipe, navigation_caution_verification=proof,
        all_other_executables_and_resources_byte_exact_MAX17=True,
        prior_Bluetooth_helpers_and_UI_exact=True, navigation_engine_and_skin_unchanged=True,
        writer=writer_run, extractor=extractor_run, verification=result, source_pins=pins,
        native_executed=False, hardware_tested=False, published=False, flashed=False,
        maps_licenses_user_data_added=False)
    write(STAGE / 'build-manifest.json', manifest)
    write(STAGE / 'member-plan.json', dict(members=[dict(path=n, before=previous[n], after=expected[n]) for n in sorted(expected)],
        member_count=1919, prior_paths_retained=1919, retained_members=1917,
        changed_members=changed, added_members=[], missing_members=[]))
    shutil.copytree(BASE_DELIVERY, DELIVERY)
    for name in ('upgrade.lgu', 'build-manifest.json', 'member-plan.json'):
        shutil.copyfile(STAGE / name, DELIVERY / name)
    for path in files:
        target = DELIVERY / 'build-sources' / path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
        assert sha(target.read_bytes()) == pins[path.relative_to(ROOT).as_posix()]
    shutil.copyfile(DESIGN / 'verification.json', DELIVERY / 'navigation-launch-verification.json')
    shutil.copyfile(DESIGN / 'recipe.json', DELIVERY / 'navigation-launch-recipe.json')
    (DELIVERY / 'README.md').write_text('''# MAXmade 7.0.6.MAX18 — direct navigation launch test build

Navigation and Map open through their normal launch handlers without the
recurring MediaNav caution/Agree screen. Acceptance defaults to Boolean 1 on
app startup and remains set across native navigation stop/restart paths.
Only nine original MIPS instructions and AppMain's PE checksum change.
The caution dialog/control initialization and native ID remain intact.

Complete MAX17 successor: every one of its 1,919 paths is retained; 1,917 are
byte-exact. Only AppMain.exe and Version_Info.txt change. All previous Bluetooth
artwork/title/audio/playback fixes, light/dark UI, MAX17 volume design and MAX16
navigation skin are retained. Nav executable, legal/license files, routes,
startup error handling and all other executables/resources remain unchanged.

Offline actual-byte interpretation checks construction, existing singleton,
allocation failure, normal Navigation/Map accepted paths and four acceptance
reset sites at three image rebases. Original warning paths are reproduced;
normal candidate paths launch directly. Imports, unwind metadata, relocation
table, sections and the previous Bluetooth helpers are unchanged.
This does not reproduce actual CE/Nav IPC, hardware display or guidance.

The full LGU passes independent member/header/CRC/hash decoding and separate
pinned PC extraction with complete payload hashes. The ZIP passes CRC checks.
MAX15 remains the public stable release. MAX18 is a local test candidate.

Use your established installation procedure and confirm 7.0.6.MAX18. While
stationary, test Navigation and Map after a full cold boot, then return Home
and open them again. Test a later ignition cycle. Confirm no Agree screen,
route calculation, GPS position, route guidance and returning to media work.
Also check the inherited Nav/volume design, Bluetooth covers/titles/audio,
play/pause and both themes. Nav rendering and MAX17 volume still need car
testing. Previous packages and the device backup remain unchanged.
''', encoding='utf-8')
    paths = sorted(p for p in DELIVERY.rglob('*') if p.is_file() and p.name != 'SHA256SUMS.txt')
    sums = ''.join(sha(p.read_bytes()) + '  ' + p.relative_to(DELIVERY).as_posix() + '\n' for p in paths)
    (DELIVERY / 'SHA256SUMS.txt').write_text(sums, encoding='ascii')
    for line in sums.splitlines():
        digest, name = line.split('  ', 1); assert sha((DELIVERY / name).read_bytes()) == digest
    with zipfile.ZipFile(ARCHIVE, 'w', compression=zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(DELIVERY.rglob('*')):
            if path.is_file(): archive.write(path, REVISION + '/' + path.relative_to(DELIVERY).as_posix())
    with zipfile.ZipFile(ARCHIVE) as archive:
        assert archive.testzip() is None
        assert sha(archive.read(REVISION + '/upgrade.lgu')) == result['lgu_sha256']
        assert all('btsnoop' not in n.lower() and 'backup-inventory' not in n.lower() for n in archive.namelist())
    summary = dict(passed=True, lgu=str(DELIVERY / 'upgrade.lgu'), zip=str(ARCHIVE), bytes=result['bytes'],
        sha256=result['lgu_sha256'], members=1919, prior_paths_retained=1919, retained_exact=1917,
        changed_instructions=9, prior_Bluetooth_helpers_and_UI_exact=True,
        navigation_engine_and_skin_unchanged=True, delivery_checksums_verified=len(paths),
        source_pins_verified=len(pins), zip_crc_and_embedded_lgu_hash_verified=True, car_test_pending=True)
    write(STAGE / 'verification.json', summary)
    return summary


if __name__ == '__main__':
    print(json.dumps(build(),indent=2))
