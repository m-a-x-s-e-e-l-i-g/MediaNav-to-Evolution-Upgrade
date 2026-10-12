"""Pack a complete MAX11 successor with the verified Settings skin."""
import json
import shutil
import sys
import zipfile
from datetime import datetime, timezone
from pathlib import Path
from types import FunctionType
import pefile
from build_max12_settings import ROOT, OUT, BASELINE, APP, sha
import build_review_update as container

REPO = ROOT / 'sources/MediaNav-usb-seek-timing'
sys.path.append(str(REPO / 'tools'))
from build_max05_candidate import tree

REVISION = '7.0.6.MAX12'
STAGE = REPO / 'build/maxmade-7.0.6.MAX12-settings-local-02'
DELIVERY = ROOT / 'build/maxmade-7.0.6.MAX12'
ARCHIVE = ROOT / 'build/maxmade-7.0.6.MAX12.zip'
BASE_LGU_SHA = '01092bd400affa41eb35a170102e1ce82f17170a6dc27d0a999698e052c20853'


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')


def build():
    for target in (STAGE, DELIVERY, ARCHIVE):
        assert not target.exists(), str(target)
    original = (BASELINE / 'upgrade.lgu').read_bytes()
    assert sha(original) == BASE_LGU_SHA
    previous = {r['path']: r['after'] for r in json.loads((BASELINE / 'member-plan.json').read_bytes())['members']}
    tree(BASELINE / 'payload', previous)
    tree(BASELINE / 'roundtrip', previous)
    report = json.loads((OUT / 'manifest.json').read_bytes())
    proof = json.loads((OUT / 'verification.json').read_bytes())
    expected = {r['path']: dict(bytes=r['bytes'], sha256=r['sha256']) for r in report['members']}
    assert set(expected) == set(previous) and len(expected) == 1918
    assert proof['asset_contracts_verified'] == 90 and proof['catalog_profile_state_painter_cases'] == 14752
    assert not proof['hardware_tested'] and proof['app_sha256'] == expected[APP.as_posix()]['sha256']
    tree(OUT / 'payload', expected)
    shutil.copytree(OUT / 'payload', STAGE / 'payload')
    (STAGE / 'payload' / container.VERSION_PATH).write_bytes(REVISION.encode('ascii'))
    expected[container.VERSION_PATH] = dict(bytes=len(REVISION), sha256=sha(REVISION.encode('ascii')))
    changed = [n for n in sorted(expected) if expected[n] != previous[n]]
    assert APP.as_posix() in changed and len(changed) == 92
    assert expected['upgrade/Storage Card/System/Blue.exe'] == previous['upgrade/Storage Card/System/Blue.exe']
    assert expected['upgrade/Storage Card4/NNG/nngnavi.exe'] == previous['upgrade/Storage Card4/NNG/nngnavi.exe']
    tree(STAGE / 'payload', expected)
    writer, extractor = (ROOT / 'tools/vendor/lgu-favremod' / n for n in ('dir2lgu.exe', 'lgu2dir.exe'))
    for tool, pin in ((writer, container.WRITER_HASH), (extractor, container.EXTRACTOR_HASH)):
        assert sha(tool.read_bytes()) == pin and pefile.PE(str(tool)).FILE_HEADER.Machine == 0x14c
    print('Complete 1,918-member Settings payload verified; packing.', flush=True)
    writer_run = container.run_pc_tool(writer, ['-p', 'm1', REVISION, STAGE / 'payload', STAGE / 'upgrade.lgu'], STAGE / 'dir2lgu.log')
    key = bytes.fromhex(json.loads((REPO / 'src/container/lgu0.json').read_bytes())['xor_hex'])
    independent = FunctionType(container.verify_package.__code__, dict(container.verify_package.__globals__, xor_key=lambda: key))
    verification = independent(STAGE / 'upgrade.lgu', expected, REVISION)
    print('Independent decode passed; comparing separate extractor.', flush=True)
    extractor_run = container.run_pc_tool(extractor, [STAGE / 'upgrade.lgu', STAGE / 'roundtrip'], STAGE / 'lgu2dir.log')
    tree(STAGE / 'roundtrip', expected)
    tree(STAGE / 'payload', expected)
    tree(BASELINE / 'roundtrip', previous)
    assert (BASELINE / 'upgrade.lgu').read_bytes() == original
    manifest = dict(revision=REVISION, kind='FULL LOCAL SETTINGS CAR TEST CANDIDATE',
                    generated_utc=datetime.now(timezone.utc).isoformat(), baseline_revision='7.0.6.MAX11',
                    baseline_lgu_sha256=BASE_LGU_SHA, output_members=1918, unchanged_from_MAX11=1918-len(changed),
                    changed_members=changed, missing_members=[], added_members=[], baseline_unchanged=True,
                    changed_images=90, selected_label_table_only=True, blue_byte_identical_MAX11=True,
                    navigation_executable_byte_identical_MAX11=True,
                    navigation_skin_included=False, navigation_blocker=report['navigation_blocker'],
                    album_art_status='MAX10 physically failed; MAX11 inherited correction not car-tested',
                    hardware_tested=False, native_executed=False, flashed=False, published=False,
                    constructor_geometry_events_labels_fonts_identical=True,
                    verification=verification, painter_verification=proof,
                    source_pins={str(path.relative_to(ROOT)): sha(path.read_bytes()) for path in
                                 (ROOT/'tools/build_max12_settings.py', ROOT/'tools/inspect_settings_layouts.py',
                                  ROOT/'tools/verify_max12_settings.py', Path(__file__))},
                    writer=writer_run, extractor=extractor_run)
    write(STAGE / 'build-manifest.json', manifest)
    write(STAGE / 'member-plan.json', dict(members=[dict(path=n, before=previous[n], after=expected[n]) for n in sorted(expected)],
                                          changed_members=changed, member_count=1918, missing_members=[], added_members=[]))
    DELIVERY.mkdir()
    for name in ('upgrade.lgu', 'build-manifest.json', 'member-plan.json'):
        shutil.copyfile(STAGE / name, DELIVERY / name)
    for name in ('verification.json', 'label-recipe.json', 'settings-layouts.json'):
        shutil.copyfile(OUT / name, DELIVERY / name)
    shutil.copyfile(OUT / 'previews/comparison.png', DELIVERY / 'settings-comparison.png')
    (DELIVERY / 'README.md').write_text('''# MAXmade 7.0.6.MAX12 — Settings candidate

Complete successor to the full MAX11 candidate. All 1,918 payload members are
included; 1,826 remain byte-identical. Settings now follows the approved
Bluetooth/radio style: charcoal surfaces, black active buttons, amber outlines
matching the Settings home icon, and readable text. Native layout, font choices,
labels, events, resource dimensions, palette sizes and transparency are retained.

90 indexed BMPs change: all 80 M1 Settings images, its background, pairing input
boxes and eight shared confirmation-dialog resources. Shared popup styling is
also visible when other screens use those dialogs. AppMain changes only 51
membership bytes in the existing selected-text lookup plus its PE checksum;
every instruction, import, relocation, audio/title/artwork helper remains intact.
All Bluetooth/radio image files and the whole Blue.exe are identical to MAX11.
M0/inverse image sets and their foreground policy remain unchanged.

Offline checks: 16 constructor snapshots preserve geometry/labels/events/fonts;
14,752 actual painter/profile/state cases and semantic-color checks pass. Native
BMP headers, dimensions, transparency, padding and independent decoding pass.
The complete LGU is independently decoded and separately extracted with all
1,918 hashes matching. No firmware was executed or installed during these checks.
Preview images use native resources and constructor positions with sample state
and PC Tahoma metrics; they are not car screenshots or runtime rendering proof.

Navigation redesign is pending the installed Storage Card4/NNG/data.zip and any
branding.zip or custom skin. These are absent from the available MAX11 package.
The older 4.1.0 reference archive is not substituted for your installed skin.
nngnavi.exe remains unchanged. This candidate does not claim to redesign Nav.

MAX11's latest album-art response correction is inherited. It is not yet proven
in the car; the album-art issue remains open. MAX08 audio/title improvements and
the approved MAX07 selected-label fixes are retained. MAX10 is still the public
release; MAX12 is a local car-test candidate, not a published successor release.

Use the established full update procedure, with upgrade.lgu at the USB root.
Check Audio, Display, Bluetooth and System Settings, sliders, balance/fader,
pairing code keys, language selection, clock/units and confirmations. Selected,
pressed and disabled labels should remain readable; ensure every control still
responds at its original location. Also check BT/FM selected buttons and audio.
Only inspect factory-reset/remote-start controls: no reset/start is needed for
visual validation. Physical rendering and behavior await car testing.
''', encoding='utf-8')
    (DELIVERY / 'SHA256SUMS.txt').write_text(''.join(sha(p.read_bytes())+'  '+p.name+'\n' for p in sorted(DELIVERY.iterdir()) if p.is_file()), encoding='ascii')
    with zipfile.ZipFile(ARCHIVE, 'w', compression=zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(DELIVERY.iterdir()): archive.write(path, REVISION+'/'+path.name)
    with zipfile.ZipFile(ARCHIVE) as archive:
        assert archive.testzip() is None
        assert sha(archive.read(REVISION+'/upgrade.lgu')) == verification['lgu_sha256']
    return dict(lgu=str(DELIVERY/'upgrade.lgu'), zip=str(ARCHIVE), members=1918,
                changed=len(changed), sha256=verification['lgu_sha256'], navigation_pending=True)


if __name__ == '__main__': print(json.dumps(build(), indent=2))
