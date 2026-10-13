"""Reproduce full MAX18 from historical MAX04 and public 4.1.0 inputs.

Existing MAX15 constructors reproduce the baseline. Eight guarded member
changes and one independently checked skin addition then produce MAX18.
No native firmware runs; every output byte is checked against the release.
"""
import argparse
import io
import json
from pathlib import Path
import struct
import tempfile
import urllib.request
import zipfile
import zlib

import release_payload as payload

ROOT = payload.ROOT
PLAN = ROOT / 'src/patches/max18.json'


def load_plan():
    plan = payload.plan_at(PLAN)
    assert len(plan['members']) == 1918 and len(plan['additions']) == 1
    addition = plan['additions'][0]
    payload.member(addition['path'])
    assert addition['path'] == plan['navigation']['source_member']
    assert addition['path'] not in {r['path'] for r in plan['members']}
    names = [r['path'] for r in plan['navigation']['changed_members']]
    assert len(names) == len(set(n.casefold() for n in names)) == 274
    for row in plan['navigation']['changed_members']:
        payload.member(row['path'])
        assert payload.member(row['asset']).is_relative_to('src/ui/max18/navigation')
    return plan


def prepare_baseline(plan, destination):
    if destination.exists():
        raise FileExistsError(f'Use a fresh input directory: {destination}')
    old = payload.plan_at(ROOT / plan['baseline_plan'])
    assert old['released_lgu_sha256'] == plan['baseline_lgu_sha256']
    destination.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='max18-input-', dir=destination.parent) as tmp:
        root = Path(tmp)
        payload.prepare(old, root / 'max04')
        payload.reproduce(old, root / 'max04', root / 'max15')
        (root / 'max15/payload').rename(destination)


def prepare_navigation(plan, destination):
    if destination.exists():
        raise FileExistsError(f'Use a fresh navigation input: {destination}')
    nav = plan['navigation']
    with urllib.request.urlopen(nav['source_lgu_url'], timeout=120) as response:
        raw = response.read()
    assert payload.sha(raw) == nav['source_lgu_sha256'], 'Public 4.1.0 input changed'
    assert raw[:4] == b'LGU0' and struct.unpack_from('<Q', raw, 12)[0] == len(raw)
    # This pinned original 4.1.0 container stores the encoded-body CRC.
    # Modern MAXmade containers use the decoded-body convention instead.
    assert zlib.crc32(raw[1024:]) == struct.unpack_from('<I', raw, 24)[0], 'Reference LGU CRC mismatch'
    key = bytes.fromhex(json.loads((ROOT / 'src/container/lgu0.json').read_bytes())['xor_hex'])
    assert len(key) == 1024
    data = bytearray(raw[1024:])
    for index, value in enumerate(key):
        data[index::1024] = data[index::1024].translate(bytes(n ^ value for n in range(256)))
    with zipfile.ZipFile(io.BytesIO(data)) as archive:
        entries = archive.infolist()
        names = [str(payload.member(e.filename.replace('\\', '/'))) for e in entries]
        assert len(names) == len(set(n.casefold() for n in names))
        entry = entries[names.index(nav['source_member'])]
        result = archive.read(entry, pwd=b'I_LOVE_LG^^')
    assert payload.sha(result) == nav['source_archive_sha256'], 'Navigation input changed'
    destination.parent.mkdir(parents=True, exist_ok=True)
    # Exclusive creation prevents a concurrent run from replacing another input.
    with destination.open('xb') as output:
        output.write(result)


def build_navigation(plan, source, output):
    nav = plan['navigation']
    assert payload.sha(source.read_bytes()) == nav['source_archive_sha256'], 'Navigation source changed'
    edits = {}
    with zipfile.ZipFile(source) as archive:
        assert archive.testzip() is None
        names = archive.namelist()
        assert len(names) == nav['members'] == len(set(n.casefold() for n in names))
        for name in names:
            payload.member(name.rstrip('/'))
        for row in nav['changed_members']:
            assert payload.sha(archive.read(row['path'])) == row['before_sha256']
            raw = (ROOT / row['asset']).read_bytes()
            assert payload.sha(raw) == row['after_sha256'], row['asset']
            edits[row['path']] = raw
        with zipfile.ZipFile(output, 'w') as result:
            result.comment = archive.comment
            for entry in archive.infolist():
                result.writestr(entry, edits.get(entry.filename, archive.read(entry.filename)))
    with zipfile.ZipFile(source) as original, zipfile.ZipFile(output) as result:
        assert result.testzip() is None and result.namelist() == original.namelist()
        for name in result.namelist():
            assert result.read(name) == edits.get(name, original.read(name)), name
    row = plan['additions'][0]
    assert output.stat().st_size == row['after_bytes']
    assert payload.sha(output.read_bytes()) == row['after_sha256'], 'Rebuilt skin differs from tested archive'


def reproduce(plan, baseline, source_navigation, destination):
    if destination.exists():
        raise FileExistsError(f'Use a fresh output directory: {destination}')
    destination.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='max18-payload-', dir=destination.parent) as tmp:
        root = Path(tmp)
        build_navigation(plan, source_navigation, root / 'navigation.zip')
        payload.reproduce(plan, baseline, root / 'result')
        target = root / 'result/payload' / plan['additions'][0]['path']
        target.parent.mkdir(parents=True, exist_ok=True)
        (root / 'navigation.zip').rename(target)
        expected = {r['path']: r for r in plan['members'] + plan['additions']}
        actual = {p.relative_to(root / 'result/payload').as_posix(): p
                  for p in (root / 'result/payload').rglob('*') if p.is_file()}
        assert actual.keys() == expected.keys() and len(actual) == 1919
        for name, path in actual.items():
            raw = path.read_bytes()
            assert len(raw) == expected[name]['after_bytes'] and payload.sha(raw) == expected[name]['after_sha256'], name
        report = {'revision': plan['revision'], 'members_verified': 1919,
                  'prior_paths_retained': 1918, 'changed_members': len(plan['changes']),
                  'added_members': [plan['additions'][0]['path']], 'missing_members': [],
                  'native_executed': False, 'payload_matches_tested_release': True,
                  'edit_plan_sha256': payload.sha(PLAN.read_bytes())}
        (root / 'result/reproduction.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
        (root / 'result').rename(destination)
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--prepare-input', type=Path)
    parser.add_argument('--prepare-nav', type=Path)
    parser.add_argument('--baseline', type=Path)
    parser.add_argument('--navigation', type=Path)
    parser.add_argument('--out', type=Path)
    args = parser.parse_args()
    plan = load_plan()
    if args.prepare_input and not (args.prepare_nav or args.baseline or args.navigation or args.out):
        prepare_baseline(plan, args.prepare_input)
        print(json.dumps({'prepared_MAX15_payload': str(args.prepare_input), 'members': 1918}))
    elif args.prepare_nav and not (args.prepare_input or args.baseline or args.navigation or args.out):
        prepare_navigation(plan, args.prepare_nav)
        print(json.dumps({'prepared_public_navigation_input': str(args.prepare_nav)}))
    elif args.baseline and args.navigation and args.out and not (args.prepare_input or args.prepare_nav):
        print(json.dumps(reproduce(plan, args.baseline, args.navigation, args.out), indent=2))
    else:
        parser.error('Use one preparation operation, or --baseline with --navigation and --out')


if __name__ == '__main__':
    main()
