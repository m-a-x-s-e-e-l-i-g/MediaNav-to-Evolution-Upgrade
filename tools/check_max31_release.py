"""Verify complete MAX31 payload records, frozen sources and honest test status."""
import argparse
import ast
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
RELEASE = ROOT / 'releases/7.0.6.MAX31'
LGU_SHA = '521e9192c1dea4ae4d64d5346db0cc441c638e6156b7227af8a64eac162979b3'


def read(name):
    return json.loads((RELEASE / name).read_bytes())


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main(lgu=None):
    manifest = read('build-manifest.json')
    container = manifest['container_verification']
    assert container['lgu_sha256'] == LGU_SHA and container['bytes'] == 52310420
    assert container['header_crc_valid'] and container['member_crc_sizes_hashes_valid']
    assert container['content'] == '7.0.6.MAX31'
    old_manifest = json.loads((ROOT / 'releases/7.0.6.MAX30/build-manifest.json').read_bytes())
    assert manifest['baseline_lgu_sha256'] == old_manifest['container_verification']['lgu_sha256']
    old = {r['path']: r for r in old_manifest['container_verification']['members']}
    new = {r['path']: r for r in container['members']}
    assert len(old) == len(new) == 1920 and old.keys() == new.keys()
    changed = {n for n in old if old[n]['sha256'] != new[n]['sha256']}
    assert changed == {
        'upgrade/Storage Card/NK.bin', 'upgrade/Storage Card/Recovery.exe',
        'upgrade/Storage Card/System/dboot.exe', 'upgrade/Storage Card/System/CmnDll.dll',
        'upgrade/Storage Card/System/Version_Info.txt'}
    assert manifest['previous_paths_retained'] == 1920 and manifest['exact_previous_members'] == 1915
    assert set(manifest['changed_members']) == changed
    assert not manifest['added_members'] and not manifest['missing_members']
    comparison = read('public-baseline-comparison.json')
    assert comparison['baseline'] == '7.0.6.MAX30' and comparison['unchanged_members'] == 1915
    assert comparison['retained_paths'] == 1920 and not comparison['missing_members']
    assert not comparison['added_members'] and {r['path'] for r in comparison['changes']} == changed
    for row in comparison['changes']:
        a, b = old[row['path']], new[row['path']]
        assert (row['before_bytes'], row['before_sha256']) == (a['bytes'], a['sha256'])
        assert (row['after_bytes'], row['after_sha256']) == (b['bytes'], b['sha256'])
        assert row['reason']
    plan = read('member-plan.json')
    assert plan['member_count'] == plan['prior_paths_retained'] == 1920
    assert plan['retained_members'] == 1915 and not plan['missing_members'] and not plan['added_members']
    assert {r['path']: (r['after']['bytes'], r['after']['sha256']) for r in plan['members']} == {
        n: (v['bytes'], v['sha256']) for n, v in new.items()}
    rows = read('source-manifest.json')['files']
    assert len(rows) == len(manifest['source_pins']) == 115
    assert {r['path'] for r in rows} == {
        'releases/7.0.6.MAX31/build-sources/' + n for n in manifest['source_pins']}
    for row in rows:
        path = ROOT / row['path']
        assert path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], row['path']
        if path.suffix == '.py':
            ast.parse(path.read_text(encoding='utf-8-sig'), feature_version=(3, 12))
    for name, pin in manifest['source_pins'].items():
        assert sha(RELEASE / 'build-sources' / name) == pin, name
    assert read('verification.json')['passed'] and read('verification.json')['cases'] == 1137
    assert read('boot-recovery-verification.json')['cases'] == 439
    assert read('inherited-verification.json')['cases'] == 698
    for name in ['package-verification.json', 'final-delivery-verification.json',
                 'boot-recovery-verification.json', 'inherited-verification.json']:
        assert read(name)['passed'], name
    delivery = read('final-delivery-verification.json')
    assert delivery['lgu_sha256'] == LGU_SHA and delivery['lgu_bytes'] == 52310420
    assert delivery['source_pins'] == 115 and delivery['physical_test_pending']
    status = read('device-status.json')
    assert status['revision'] == '7.0.6.MAX31' and status['release_lgu_sha256'] == LGU_SHA
    assert status['release_authorized_by_owner'] and not status['installation_reported_by_user']
    assert not status['car_tested'] and status['physical_test_pending']
    for key in ['dboot_recovery_car_verified', 'quick_reboot_car_verified', 'iphone_artwork_car_verified',
                'recovery_fault_injection_car_verified', 'broader_device_compatibility_verified', 'rollback_verified']:
        assert not status[key], key
    assert (ROOT / status['test_device']).is_file()
    assert (RELEASE / 'SHA256SUMS.txt').read_text().strip() == LGU_SHA + '  upgrade.lgu'
    if lgu:
        assert lgu.stat().st_size == 52310420 and sha(lgu) == LGU_SHA
    print(json.dumps(dict(release='7.0.6.MAX31', members=len(new), retained_paths=len(old),
                          changed_since_MAX30=len(changed), frozen_sources=len(rows),
                          physical_test_pending=True, lgu_bytes_verified=bool(lgu)), indent=2))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--lgu', type=Path)
    main(parser.parse_args().lgu)
