"""Verify full MAX30 inventory, frozen build sources and later owner feedback."""
import argparse
import ast
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
RELEASE = ROOT / 'releases/7.0.6.MAX30'
LGU_SHA = '5e649714c20503cd9fb738d54aa836577d73714f888b05d718c06a2acc6550d7'


def read(name):
    return json.loads((RELEASE / name).read_bytes())


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main(lgu=None):
    manifest = read('build-manifest.json')
    container = manifest['container_verification']
    assert container['lgu_sha256'] == LGU_SHA and container['bytes'] == 52306828
    assert container['header_crc_valid'] and container['member_crc_sizes_hashes_valid']
    assert container['content'] == '7.0.6.MAX30'
    new = {r['path']: r for r in container['members']}
    old = {r['path']: r for r in json.loads(
        (ROOT / 'releases/7.0.6.MAX18/build-manifest.json').read_bytes())['verification']['members']}
    assert len(old) == 1919 and len(new) == 1920 and old.keys() <= new.keys()
    assert new.keys() - old.keys() == {'upgrade/Storage Card/Recovery.exe'}
    comparison = read('public-baseline-comparison.json')
    changed = {n for n in old if old[n]['sha256'] != new[n]['sha256']}
    assert len(changed) == 12 and comparison['unchanged_members'] == 1907
    assert {r['path'] for r in comparison['changes']} == changed
    assert comparison['missing_members'] == [] and comparison['retained_paths'] == 1919
    for row in comparison['changes']:
        a, b = old[row['path']], new[row['path']]
        assert (row['before_bytes'], row['before_sha256']) == (a['bytes'], a['sha256'])
        assert (row['after_bytes'], row['after_sha256']) == (b['bytes'], b['sha256'])
        assert row['reason']
    plan = read('member-plan.json')
    assert plan['member_count'] == 1920 and plan['retained_members'] == 1917
    assert plan['prior_paths_retained'] == 1920 and not plan['missing_members']
    assert {r['path']: (r['after']['bytes'], r['after']['sha256']) for r in plan['members']} == {
        n: (v['bytes'], v['sha256']) for n, v in new.items()}
    rows = read('source-manifest.json')['files']
    assert len(rows) == len(manifest['source_pins']) == 110
    assert {r['path'] for r in rows} == {
        'releases/7.0.6.MAX30/build-sources/' + n for n in manifest['source_pins']}
    for row in rows:
        path = ROOT / row['path']
        assert path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], row['path']
        if path.suffix == '.py':
            ast.parse(path.read_text(encoding='utf-8-sig'), feature_version=(3, 12))
    for name, pin in manifest['source_pins'].items():
        assert sha(RELEASE / 'build-sources' / name) == pin, name
    assert read('verification.json')['passed'] and read('verification.json')['cases'] == 996
    for name in ['package-verification.json', 'final-delivery-verification.json',
                 'boot-recovery-verification.json', 'quiet-logging-verification.json',
                 'final-runtime-regression.json']:
        assert read(name)['passed'], name
    status = read('device-status.json')
    assert status['revision'] == '7.0.6.MAX30' and status['release_lgu_sha256'] == LGU_SHA
    assert status['installation_reported_by_user'] and status['release_authorized_by_owner']
    assert status['reported_starting_version'] == '7.0.6.MAX26'
    assert not status['iphone_artwork_car_verified']
    assert not status['recovery_fault_injection_car_verified']
    assert not status['broader_device_compatibility_verified'] and not status['rollback_verified']
    assert (ROOT / status['test_device']).is_file()
    assert (RELEASE / 'SHA256SUMS.txt').read_text().strip() == LGU_SHA + '  upgrade.lgu'
    if lgu:
        assert lgu.stat().st_size == 52306828 and sha(lgu) == LGU_SHA
    print(json.dumps(dict(release='7.0.6.MAX30',members=len(new),prior_public_paths_retained=len(old),
                          changed_since_MAX18=len(changed),frozen_sources=len(rows),
                          owner_test='MAX26 to MAX30; general approval',iphone_artwork='untested',
                          lgu_bytes_verified=bool(lgu)),indent=2))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--lgu', type=Path)
    main(parser.parse_args().lgu)
