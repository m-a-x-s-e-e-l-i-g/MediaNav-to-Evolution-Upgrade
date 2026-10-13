"""Check MAX18 complete inventory, source snapshots and separate car feedback."""
import ast
import json
from pathlib import Path

from release_max18_payload import ROOT, load_plan
from release_payload import sha


def main():
    release = ROOT / 'releases/7.0.6.MAX18'
    plan = load_plan()
    manifest = json.loads((release / 'build-manifest.json').read_bytes())
    before = json.loads((ROOT / 'releases/7.0.6.MAX15/build-manifest.json').read_bytes())
    old = {r['path']: r for r in before['verification']['members']}
    new = {r['path']: r for r in manifest['verification']['members']}
    assert len(old) == 1918 and len(new) == 1919 and old.keys() <= new.keys()
    assert len(plan['members']) == 1918 and len(plan['changes']) == 8
    assert new.keys() - old.keys() == {plan['additions'][0]['path']}
    assert plan['baseline_lgu_sha256'] == before['verification']['lgu_sha256']
    assert plan['released_lgu_sha256'] == manifest['verification']['lgu_sha256'] == 'd474cd4e80d12c868837eb71d0251b6089cc3d0c4cc3a1163fd098bd96fd58d1'
    for row in plan['members']:
        a, b = old[row['path']], new[row['path']]
        assert (row['before_bytes'], row['before_sha256']) == (a['bytes'], a['sha256'])
        assert (row['after_bytes'], row['after_sha256']) == (b['bytes'], b['sha256'])
    for row in plan['additions']:
        assert (row['after_bytes'], row['after_sha256']) == (new[row['path']]['bytes'], new[row['path']]['sha256'])
    assert {r['path'] for r in plan['changes']} == {n for n in old if old[n]['sha256'] != new[n]['sha256']}
    for row in plan['changes']:
        if 'asset' in row:
            assert sha((ROOT / row['asset']).read_bytes()) == new[row['path']]['sha256']
    for row in plan['navigation']['changed_members']:
        assert sha((ROOT / row['asset']).read_bytes()) == row['after_sha256']
    pins = json.loads((release / 'source-manifest.json').read_bytes())['files']
    for row in pins:
        raw = (ROOT / row['path']).read_bytes()
        assert len(raw) == row['bytes'] and sha(raw) == row['sha256'], row['path']
        if Path(row['path']).suffix == '.py':
            ast.parse(raw.decode('utf-8-sig'), feature_version=(3, 12))
    for name, pin in manifest['source_pins'].items():
        assert sha((release / 'build-sources' / name).read_bytes()) == pin, name
    status = json.loads((release / 'device-status.json').read_bytes())
    assert status['installation_reported_by_user'] and status['release_authorized_by_owner']
    assert status['revision'] == plan['revision'] and status['release_lgu_sha256'] == plan['released_lgu_sha256']
    assert not status['broader_device_compatibility_verified'] and not status['rollback_verified']
    assert (ROOT / status['test_device']).is_file()
    assert (release / 'SHA256SUMS.txt').read_text().strip() == plan['released_lgu_sha256'] + '  upgrade.lgu'
    for name in ('navigation-verification.json', 'volume-verification.json',
                 'navigation-launch-verification.json', 'packaging-verification.json'):
        assert json.loads((release / name).read_bytes())['passed'], name
    assert manifest['all_other_executables_and_resources_byte_exact_MAX17']
    print(json.dumps({'complete_members': 1919, 'prior_MAX15_paths_retained': 1918,
                      'source_snapshots': len(pins), 'nav_resources': 274,
                      'car_test': 'Owner tested MAX18 and approved publication on 2026-10-13'}, indent=2))


if __name__ == '__main__':
    main()
