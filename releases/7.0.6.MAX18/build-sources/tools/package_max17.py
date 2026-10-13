"""Package full MAX16 successor with six resource-only volume HUD changes."""
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
from build_volume_theme import OUT as DESIGN, ROOT

BASE = ROOT / 'build/max16-navigation-development-01'
BASE_DELIVERY = ROOT / 'build/maxmade-7.0.6.MAX16'
BASE_SHA = 'c168d08524b745120e4500af0d4835c5cb68d0517037f698c4e2851295d45949'
STAGE = ROOT / 'build/max17-volume-development-01'
DELIVERY = ROOT / 'build/maxmade-7.0.6.MAX17'
ARCHIVE = ROOT / 'build/maxmade-7.0.6.MAX17.zip'
REVISION = '7.0.6.MAX17'


def source_files():
    # Include transitive local Python helpers for reproducible offline checks.
    pending = [Path(__file__), ROOT / 'tools/build_volume_theme.py', ROOT / 'tools/verify_volume_theme.py']
    found = set()
    while pending:
        path = pending.pop()
        if path in found:
            continue
        found.add(path)
        syntax = ast.parse(path.read_text(encoding='utf-8-sig'))
        for node in ast.walk(syntax):
            modules = [node.module] if isinstance(node, ast.ImportFrom) else (
                [n.name for n in node.names] if isinstance(node, ast.Import) else [])
            for module in modules:
                if module:
                    candidate = ROOT / 'tools' / (module.split('.')[0] + '.py')
                    if candidate.is_file():
                        pending.append(candidate)
    return sorted(found)


def build():
    for path in (STAGE, DELIVERY, ARCHIVE):
        assert not path.exists(), f'Fresh output required: {path}'
    previous = {r['path']: r['after'] for r in json.loads((BASE / 'member-plan.json').read_bytes())['members']}
    assert len(previous) == 1919
    for path in (BASE / 'upgrade.lgu', BASE_DELIVERY / 'upgrade.lgu'):
        assert sha(path.read_bytes()) == BASE_SHA
    tree(BASE / 'payload', previous)
    tree(BASE / 'roundtrip', previous)
    design = json.loads((DESIGN / 'manifest.json').read_bytes())
    proof = json.loads((DESIGN / 'verification.json').read_bytes())
    assert proof['passed'] and proof['changed_bitmaps'] == design['changed_assets'] == 6
    shutil.copytree(BASE / 'payload', STAGE / 'payload')
    expected = dict(previous)
    for row in design['assets']:
        name = row['path']
        assert name in previous and previous[name]['sha256'] == row['before_sha256']
        raw = (DESIGN / 'overlay' / name).read_bytes()
        assert sha(raw) == row['after_sha256'] and len(raw) == previous[name]['bytes']
        if row['changed']:
            (STAGE / 'payload' / name).write_bytes(raw)
            expected[name] = dict(bytes=len(raw), sha256=sha(raw))
    (STAGE / 'payload' / container.VERSION_PATH).write_bytes(REVISION.encode('ascii'))
    expected[container.VERSION_PATH] = dict(bytes=len(REVISION), sha256=sha(REVISION.encode('ascii')))
    changed = sorted(n for n in expected if expected[n] != previous[n])
    assert len(changed) == 7 and set(previous) == set(expected)
    assert all(n == container.VERSION_PATH or n.endswith(('etc_volume_bg.bmp', 'etc_volume_bar.bmp')) for n in changed)
    tree(STAGE / 'payload', expected)
    writer, extractor = (ROOT / 'tools/vendor/lgu-favremod' / n for n in ('dir2lgu.exe', 'lgu2dir.exe'))
    for tool, pin in ((writer, container.WRITER_HASH), (extractor, container.EXTRACTOR_HASH)):
        assert sha(tool.read_bytes()) == pin
        pc = pefile.PE(str(tool))
        assert pc.FILE_HEADER.Machine == 0x14c
        pc.close()
    print('Packing complete MAX17: all 1,919 MAX16 paths retained.', flush=True)
    writer_run = container.run_pc_tool(writer, ['-p', 'm1', REVISION, STAGE / 'payload', STAGE / 'upgrade.lgu'], STAGE / 'dir2lgu.log')
    key_path = ROOT / 'sources/MediaNav-usb-seek-timing/src/container/lgu0.json'
    key = bytes.fromhex(json.loads(key_path.read_bytes())['xor_hex'])
    verify = FunctionType(container.verify_package.__code__, dict(container.verify_package.__globals__, xor_key=lambda: key))
    result = verify(STAGE / 'upgrade.lgu', expected, REVISION)
    print('Independent LGU decoding passed; separate PC extraction next.', flush=True)
    extractor_run = container.run_pc_tool(extractor, [STAGE / 'upgrade.lgu', STAGE / 'roundtrip'], STAGE / 'lgu2dir.log')
    tree(STAGE / 'roundtrip', expected)
    tree(STAGE / 'payload', expected)
    tree(BASE / 'payload', previous)
    tree(BASE / 'roundtrip', previous)
    for path in (BASE / 'upgrade.lgu', BASE_DELIVERY / 'upgrade.lgu'):
        assert sha(path.read_bytes()) == BASE_SHA
    files = [*source_files(), key_path, DESIGN / 'manifest.json', DESIGN / 'verification.json', DESIGN / 'native-paint-traces.json']
    pins = {p.relative_to(ROOT).as_posix(): sha(p.read_bytes()) for p in files}
    manifest = dict(revision=REVISION, generated_utc=datetime.now(timezone.utc).isoformat(),
        baseline_revision='7.0.6.MAX16', baseline_lgu_sha256=BASE_SHA,
        stable_revision='7.0.6.MAX15', output_members=1919, prior_paths_retained=1919,
        unchanged_from_MAX16=1912, changed_members=changed, added_members=[], missing_members=[],
        baseline_unchanged=True, all_executables_byte_exact_MAX16=True,
        bluetooth_fixes_and_nav_skin_unchanged=True, native_icons_fonts_and_text_colors_unchanged=True,
        volume_design=design, volume_verification=proof, verification=result,
        writer=writer_run, extractor=extractor_run, source_pins=pins,
        native_executed=False, hardware_tested=False, published=False, flashed=False,
        maps_licenses_user_data_added=False)
    write(STAGE / 'build-manifest.json', manifest)
    write(STAGE / 'member-plan.json', dict(members=[dict(path=n, before=previous[n], after=expected[n]) for n in sorted(expected)],
        member_count=1919, prior_paths_retained=1919, retained_members=1912,
        changed_members=changed, added_members=[], missing_members=[]))
    # Retain the previous candidate's Nav documentation, proofs and source snapshot.
    shutil.copytree(BASE_DELIVERY, DELIVERY)
    for name in ('upgrade.lgu', 'build-manifest.json', 'member-plan.json'):
        shutil.copyfile(STAGE / name, DELIVERY / name)
    for path in files:
        target = DELIVERY / 'build-sources' / path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
        assert sha(target.read_bytes()) == pins[path.relative_to(ROOT).as_posix()]
    shutil.copyfile(DESIGN / 'verification.json', DELIVERY / 'volume-verification.json')
    shutil.copyfile(DESIGN / 'manifest.json', DELIVERY / 'volume-manifest.json')
    shutil.copytree(DESIGN / 'overlay', DELIVERY / 'build-sources/volume-overlay')
    shutil.copytree(DESIGN / 'previews', DELIVERY / 'previews/volume')
    (DELIVERY / 'README.md').write_text('''# MAXmade 7.0.6.MAX17 — full volume UI test build

The volume popup now uses a restrained charcoal panel in dark mode, a matching
light panel in light mode, rounded amber level segments and a numeric divider.
The M0 fallback theme is also covered. Native numbers, speaker/mute/call/Nav/TA
icons, popup geometry, timers and audio behavior remain unchanged.

Full MAX16 successor: all 1,919 previous paths retained, 1,912 byte-exact. Only
six volume background/bar BMPs and Version_Info change. Every executable is
exact MAX16; the car-tested MAX15 Bluetooth artwork/title/audio fixes and MAX16
Nav skin are retained. No maps, licenses or private user files are added.

Independent BMP decoding and contract checks cover headers, dimensions,
palette capacity, row padding and transparency masks. Offline interpretation
of the actual immutable MicomManager MIPS paint bytes covers all 32 levels in
three theme banks and 150 context/theme/boundary/mute cases. Native drawing,
font rendering and hardware operation still need car testing. PC previews use
actual decoded resources/captured layout with an approximate Tahoma font.

The full LGU passes independent member/header/CRC/hash decoding, separate
pinned PC extraction and complete payload checks. The ZIP passes CRC checks.
MAX15 remains the stable public release; MAX17 is a local test candidate.
MAX16's navigation redesign is also still awaiting owner testing.

Use your established installation procedure and confirm 7.0.6.MAX17. While
stationary, test volume up/down through 00–31, mute/unmute, both themes and
radio/Bluetooth/USB. Check call, navigation and traffic volume contexts when
available. Also test the inherited Nav redesign and working Bluetooth covers,
titles, playback state and audio. MAX15, MAX16 and your backup are unchanged.
''', encoding='utf-8')
    checksum_paths = sorted(p for p in DELIVERY.rglob('*') if p.is_file() and p.name != 'SHA256SUMS.txt')
    sums = ''.join(sha(p.read_bytes()) + '  ' + p.relative_to(DELIVERY).as_posix() + '\n' for p in checksum_paths)
    (DELIVERY / 'SHA256SUMS.txt').write_text(sums, encoding='ascii')
    for line in sums.splitlines():
        digest, name = line.split('  ', 1)
        assert sha((DELIVERY / name).read_bytes()) == digest
    with zipfile.ZipFile(ARCHIVE, 'w', compression=zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(DELIVERY.rglob('*')):
            if path.is_file():
                archive.write(path, REVISION + '/' + path.relative_to(DELIVERY).as_posix())
    with zipfile.ZipFile(ARCHIVE) as archive:
        assert archive.testzip() is None
        assert sha(archive.read(REVISION + '/upgrade.lgu')) == result['lgu_sha256']
        assert all('btsnoop' not in n.lower() and 'backup-inventory' not in n.lower() for n in archive.namelist())
    summary = dict(passed=True, lgu=str(DELIVERY / 'upgrade.lgu'), zip=str(ARCHIVE), bytes=result['bytes'],
        sha256=result['lgu_sha256'], members=1919, prior_paths_retained=1919, retained_exact=1912,
        changed_volume_bitmaps=6, unchanged_executables=True, inherited_nav_unchanged=True,
        delivery_checksums_verified=len(checksum_paths), source_pins_verified=len(pins),
        zip_crc_and_embedded_lgu_hash_verified=True, car_test_pending=True)
    write(STAGE / 'verification.json', summary)
    return summary


if __name__ == '__main__':
    print(json.dumps(build(), indent=2))
