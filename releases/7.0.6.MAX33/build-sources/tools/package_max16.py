"""Package a complete MAX15 successor with the verified installed Nav skin.

Only a version file changes; data.zip is added. No CE executable is run.
"""
from datetime import datetime, timezone
from pathlib import Path
from types import FunctionType
import hashlib
import json
import shutil
import zipfile

import pefile
import build_review_update as container
from apply_navigation_theme import apply

ROOT = Path(__file__).resolve().parents[1]
REPO = ROOT / 'sources/MediaNav-usb-seek-timing'
BASELINE = REPO / 'build/maxmade-7.0.6.MAX15-cover-start-local-01'
BASE_DELIVERY = ROOT / 'build/maxmade-7.0.6.MAX15'
BASE_SHA = 'ee416cfd77687448b94d046b79049793353cd40288a1675bfcf5a15504c28a98'
NAV_SOURCE_SHA = '862ff497fcab8ec80a87a0b9e494f6f6bbb5ea1b33dea063d794a97f7cd7a548'
NAV_SHA = '845461490d03b88b108c2e8e2680c5c62000e010749676303cf1dddad72ea5a8'
INSTALLED_NAV = Path('C:/Users/maxom/Downloads/MediaNav Backup/Storage Card4/NNG/data.zip')
NAV_DEVELOPMENT = ROOT / 'build/navigation-reference-development-06'
NAV_PROOF = ROOT / 'build/device-backup-analysis-01/nav-validation/verification.json'
NAV_PATH = 'upgrade/Storage Card4/NNG/data.zip'
REVISION = '7.0.6.MAX16'
STAGE = ROOT / 'build/max16-navigation-development-01'
DELIVERY = ROOT / 'build/maxmade-7.0.6.MAX16'
ARCHIVE = ROOT / 'build/maxmade-7.0.6.MAX16.zip'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')


def tree(directory, expected):
    files = {p.relative_to(directory).as_posix(): p for p in directory.rglob('*') if p.is_file()}
    assert set(files) == set(expected), 'Missing or extra full-payload members'
    for name, path in files.items():
        assert container.relative(name) == name
        raw = path.read_bytes()
        assert dict(bytes=len(raw), sha256=sha(raw)) == expected[name], name


def build():
    for path in (STAGE, DELIVERY, ARCHIVE):
        assert not path.exists(), f'Fresh output required: {path}'
    previous = {r['path']: r['after'] for r in json.loads((BASELINE / 'member-plan.json').read_bytes())['members']}
    assert len(previous) == 1918 and NAV_PATH not in previous
    for path in (BASELINE / 'upgrade.lgu', BASE_DELIVERY / 'upgrade.lgu'):
        assert sha(path.read_bytes()) == BASE_SHA
    tree(BASELINE / 'payload', previous)
    tree(BASELINE / 'roundtrip', previous)
    proof = json.loads(NAV_PROOF.read_bytes())
    assert proof['passed'] and proof['source_sha256'] == NAV_SOURCE_SHA and proof['candidate_sha256'] == NAV_SHA
    assert proof['checks']['independent_rewritten_bitmap_checks'] == 271
    assert proof['checks']['exact_untouched_members'] == 1647
    assert sha(INSTALLED_NAV.read_bytes()) == NAV_SOURCE_SHA
    backup_proof = json.loads((ROOT / 'build/device-backup-analysis-01/verification.json').read_bytes())
    assert backup_proof['packaged_card_files_exact'] == 1917 and backup_proof['backup_content_unchanged']

    shutil.copytree(BASELINE / 'payload', STAGE / 'payload')
    nav = STAGE / 'payload' / NAV_PATH
    nav_result = apply(INSTALLED_NAV, NAV_DEVELOPMENT, nav)
    assert nav_result['output_sha256'] == NAV_SHA and nav_result['changed_members'] == 274
    (STAGE / 'payload' / container.VERSION_PATH).write_bytes(REVISION.encode('ascii'))
    expected = dict(previous)
    expected[container.VERSION_PATH] = dict(bytes=len(REVISION), sha256=sha(REVISION.encode('ascii')))
    expected[NAV_PATH] = dict(bytes=nav.stat().st_size, sha256=sha(nav.read_bytes()))
    changed = [n for n in previous if previous[n] != expected[n]]
    added = sorted(set(expected) - set(previous))
    assert changed == [container.VERSION_PATH] and added == [NAV_PATH]
    assert set(previous) <= set(expected) and len(expected) == 1919
    tree(STAGE / 'payload', expected)

    writer, extractor = (ROOT / 'tools/vendor/lgu-favremod' / n for n in ('dir2lgu.exe', 'lgu2dir.exe'))
    for tool, pin in ((writer, container.WRITER_HASH), (extractor, container.EXTRACTOR_HASH)):
        assert sha(tool.read_bytes()) == pin
        pc = pefile.PE(str(tool))
        assert pc.FILE_HEADER.Machine == 0x14c
        pc.close()
    print('Packing complete MAX16: 1918 previous paths retained, one Nav skin added.', flush=True)
    writer_run = container.run_pc_tool(writer, ['-p', 'm1', REVISION, STAGE / 'payload', STAGE / 'upgrade.lgu'], STAGE / 'dir2lgu.log')
    key_path = REPO / 'src/container/lgu0.json'
    key = bytes.fromhex(json.loads(key_path.read_bytes())['xor_hex'])
    verify = FunctionType(container.verify_package.__code__, dict(container.verify_package.__globals__, xor_key=lambda: key))
    result = verify(STAGE / 'upgrade.lgu', expected, REVISION)
    print('Independent LGU decoding passed; running separate PC extractor.', flush=True)
    extractor_run = container.run_pc_tool(extractor, [STAGE / 'upgrade.lgu', STAGE / 'roundtrip'], STAGE / 'lgu2dir.log')
    tree(STAGE / 'roundtrip', expected)
    tree(STAGE / 'payload', expected)
    tree(BASELINE / 'payload', previous)
    tree(BASELINE / 'roundtrip', previous)
    assert sha((BASELINE / 'upgrade.lgu').read_bytes()) == BASE_SHA
    assert sha((BASE_DELIVERY / 'upgrade.lgu').read_bytes()) == BASE_SHA
    assert sha(INSTALLED_NAV.read_bytes()) == NAV_SOURCE_SHA

    files = [Path(__file__), ROOT / 'tools/build_review_update.py', ROOT / 'tools/inspect_updater_zip.py',
             ROOT / 'tools/inspect_bt_playback.py', ROOT / 'tools/apply_navigation_theme.py',
             ROOT / 'tools/build_navigation_reference_theme.py', ROOT / 'tools/nng_rl_bitmap.py',
             ROOT / 'tools/verify_navigation_reference_theme.py', key_path,
             NAV_DEVELOPMENT / 'manifest.json', NAV_PROOF]
    source_pins = {str(p.relative_to(ROOT)).replace('\\', '/'): sha(p.read_bytes()) for p in files}
    manifest = dict(revision=REVISION, generated_utc=datetime.now(timezone.utc).isoformat(),
        baseline_revision='7.0.6.MAX15', baseline_lgu_sha256=BASE_SHA,
        baseline_owner_feedback='Owner installed MAX15 and confirmed Bluetooth album art works; MAX15 is the public stable release.',
        output_members=len(expected), prior_paths_retained=len(previous), unchanged_from_MAX15=1917,
        changed_members=changed, added_members=added, missing_members=[], baseline_unchanged=True,
        all_executables_and_existing_resources_byte_exact_MAX15=True,
        nav_engine_unchanged=True, navigation=dict(installed_source_sha256=NAV_SOURCE_SHA,
            engine_version='9.4.6.398870', installed_contracts_exact=421, archived_members=1921,
            changed_members=274, unchanged_members=1647, application=nav_result, independent_verification=proof),
        maps_licenses_user_data_added=False, native_executed=False, hardware_tested=False,
        published=False, flashed=False, verification=result, writer=writer_run, extractor=extractor_run,
        source_pins=source_pins)
    write(STAGE / 'build-manifest.json', manifest)
    write(STAGE / 'member-plan.json', dict(members=[dict(path=n, before=previous.get(n), after=expected[n]) for n in sorted(expected)],
        member_count=len(expected), prior_paths_retained=len(previous), retained_members=1917,
        changed_members=changed, added_members=added, missing_members=[]))
    DELIVERY.mkdir()
    for name in ('upgrade.lgu', 'build-manifest.json', 'member-plan.json'):
        shutil.copyfile(STAGE / name, DELIVERY / name)
    shutil.copyfile(NAV_PROOF, DELIVERY / 'navigation-verification.json')
    shutil.copyfile(NAV_DEVELOPMENT / 'manifest.json', DELIVERY / 'navigation-manifest.json')
    shutil.copyfile(ROOT / 'build/device-backup-analysis-01/navigation-compatibility.json', DELIVERY / 'navigation-compatibility.json')
    sources = DELIVERY / 'build-sources'
    sources.mkdir()
    for path in files:
        # Preserve paths so identical filenames cannot collide in a source snapshot.
        target = sources / path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(path, target)
    shutil.copytree(NAV_DEVELOPMENT / 'overlay', sources / 'navigation-overlay')
    previews = DELIVERY / 'previews'
    shutil.copytree(NAV_DEVELOPMENT / 'previews', previews)
    (DELIVERY / 'README.md').write_text('''# MAXmade 7.0.6.MAX16 — full navigation test build

All 1,918 MAX15 payload paths are retained. Version_Info changes to MAX16 and
Storage Card4/NNG/data.zip is added, bringing the full payload to 1,919 files.
All existing executables and resources are exact MAX15, including the working
Bluetooth album-art/audio/title fixes, media player, Settings and both themes.

The navigation redesign uses the actual installed skin contracts: charcoal
surfaces, gray normal controls, black selected faces and coral accent outlines.
271 bitmaps and three color-only text files change. Native layouts, scripts,
callbacks, fonts, road schemes and safety symbols remain exact. Engine stays
9.4.6.398870. No maps, licenses, saved routes or phonebook files are added.

The owner's backed-up skin matches the original reference byte-for-byte; all
421 dependencies match and no branding/optional skin override is present.
Independent bitmap, alpha, archive inheritance, full LGU decoding and separate
PC extraction checks pass. Previews use decoded resources and sample PC fonts,
not native car rendering. MAX16 has not yet been tested in the car.

Use your established installation procedure and confirm version 7.0.6.MAX16.
Test Nav home, destinations, keyboard, settings, list selections, dialogs and
map controls. Check route calculation/guidance and day/night presentation while
stationary. Also check Bluetooth covers/titles/audio and normal media controls.
The original MAX15 release and the device backup remain unchanged.

This is a local full test build; it has not been published as a stable release.
''', encoding='utf-8')
    (DELIVERY / 'SHA256SUMS.txt').write_text(''.join(sha(p.read_bytes()) + '  ' + p.relative_to(DELIVERY).as_posix() + '\n'
        for p in sorted(DELIVERY.rglob('*')) if p.is_file() and p.name != 'SHA256SUMS.txt'), encoding='ascii')
    with zipfile.ZipFile(ARCHIVE, 'w', compression=zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(DELIVERY.rglob('*')):
            if path.is_file():
                archive.write(path, REVISION + '/' + path.relative_to(DELIVERY).as_posix())
    with zipfile.ZipFile(ARCHIVE) as archive:
        assert archive.testzip() is None
        assert sha(archive.read(REVISION + '/upgrade.lgu')) == result['lgu_sha256']
        assert all('btsnoop' not in n.lower() and 'backup-inventory' not in n.lower() for n in archive.namelist())
    summary = dict(lgu=str(DELIVERY / 'upgrade.lgu'), zip=str(ARCHIVE), bytes=result['bytes'],
        sha256=result['lgu_sha256'], members=1919, prior_paths_retained=1918, retained_exact=1917,
        unchanged_applications=True, navigation_verified=True, car_test_pending=True)
    write(STAGE / 'verification.json', summary)
    return summary


if __name__ == '__main__':
    print(json.dumps(build(), indent=2))
