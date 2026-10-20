"""Check complete MAX32 inventory, source pins and separated hardware evidence."""
import argparse
import ast
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
RELEASE = ROOT/'releases/7.0.6.MAX32'
LGU_SHA = '2c657ec6056b003681a5c4c77ee3f1b4a6c0cf5e7a5bd8c7ce3b4ab92d1998bb'
BLUE_SHA = 'e6d63ab65a0c06a2da0a14cfec60f9e98cd2db134b9dd84c2d7942bfbf0890db'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def read(name):
    return json.loads((RELEASE/name).read_bytes())


def main(lgu=None):
    manifest = read('build-manifest.json')
    prior = json.loads((ROOT/'releases/7.0.6.MAX31/build-manifest.json').read_bytes())
    container = manifest['container_verification']
    assert manifest['revision']==container['content']=='7.0.6.MAX32'
    assert container['lgu_sha256']==LGU_SHA
    assert container['header_crc_valid'] and container['member_crc_sizes_hashes_valid']
    assert manifest['baseline_lgu_sha256']==prior['container_verification']['lgu_sha256']
    before = {r['path']:r for r in prior['container_verification']['members']}
    after = {r['path']:r for r in container['members']}
    assert len(before)==len(after)==1920 and before.keys()==after.keys()
    changes = {n for n in before if before[n]['sha256']!=after[n]['sha256']}
    expected = {'upgrade/Storage Card/System/'+n for n in ['Blue.exe','CmnDll.dll','Version_Info.txt']}
    assert changes==expected==set(manifest['changed_members'])
    assert manifest['previous_paths_retained']==1920 and manifest['exact_previous_members']==1917
    assert not manifest['added_members'] and not manifest['missing_members']
    assert after['upgrade/Storage Card/System/Blue.exe']['sha256']==BLUE_SHA
    revision = after['upgrade/Storage Card/System/Version_Info.txt']
    assert (revision['bytes'],revision['sha256'])==(len(b'7.0.6.MAX32'),sha(b'7.0.6.MAX32'))
    comparison = read('public-baseline-comparison.json')
    assert comparison['baseline']=='7.0.6.MAX31' and comparison['unchanged_members']==1917
    assert comparison['retained_paths']==1920 and not comparison['missing_members']
    assert not comparison['added_members'] and {r['path'] for r in comparison['changes']}==changes
    for row in comparison['changes']:
        a,b = before[row['path']],after[row['path']]
        assert (row['before_bytes'],row['before_sha256'])==(a['bytes'],a['sha256'])
        assert (row['after_bytes'],row['after_sha256'])==(b['bytes'],b['sha256']) and row['reason']
    plan = read('member-plan.json')
    assert plan['member_count']==plan['prior_paths_retained']==1920 and plan['retained_members']==1917
    assert not plan['missing_members'] and not plan['added_members']
    assert {r['path']:(r['after']['bytes'],r['after']['sha256']) for r in plan['members']}=={
        n:(r['bytes'],r['sha256']) for n,r in after.items()}
    proof = read('verification.json')
    assert proof==manifest['byte_verification'] and proof['passed']
    assert proof['actual_written_packet_cases']==len(proof['packet_traces'])==20
    assert proof['missing_edit_negative_cases']==6 and proof['relocation_preservation_cases']==3
    assert not proof['full_rebased_execution_verified'] and not proof['physical_test']
    assert proof['inherited_limit'] and proof['exact_previous_members']==1917
    assert proof['unchanged_boot_updater_MCU_and_navigation'] and proof['diagnostic_behavior_unchanged']
    cmn = read('CmnDll.dll.json')
    assert cmn['revision_only_from_MAX31'] and cmn['before_sha256']==before['upgrade/Storage Card/System/CmnDll.dll']['sha256']
    assert cmn['output_sha256']==after['upgrade/Storage Card/System/CmnDll.dll']['sha256']
    assert read('runtime.json')['measurements_revision']==32
    pins = manifest['source_pins']
    rows = read('source-manifest.json')['files']
    assert len(pins)==len(rows)>=115 and prior['source_pins'].keys()<=pins.keys()
    assert {r['path'] for r in rows}=={'releases/7.0.6.MAX32/build-sources/'+n for n in pins}
    for row in rows:
        path = ROOT/row['path']
        raw = path.read_bytes()
        assert len(raw)==row['bytes'] and sha(raw)==row['sha256'],row['path']
        if path.suffix=='.py':
            ast.parse(raw.decode('utf-8-sig'),feature_version=(3,12))
    for name,digest in pins.items():
        assert sha((RELEASE/'build-sources'/name).read_bytes())==digest,name
    package = read('package-verification.json')
    assert package['passed'] and package['lgu_sha256']==LGU_SHA
    assert package['lgu_bytes']==container['bytes'] and package['member_count']==1920
    assert package['independent_LGU_decode'] and package['independent_PC_roundtrip']
    assert package['source_pins']==len(pins) and package['physical_test_pending']
    status = read('device-status.json')
    assert status['release_authorized_by_owner'] and status['release_lgu_sha256']==LGU_SHA
    assert not status['car_tested'] and not status['complete_MAX32_car_test']
    assert status['physical_test_pending'] and not status['installation_reported_by_user']
    assert status['contributor_iphone_artwork_reported_working'] and status['contributor_tested_blue_sha256']==BLUE_SHA
    assert not status['intermittent_missing_cover_after_skip_resolved']
    assert not status['maintainer_iphone_car_verified'] and not status['full_rebased_GET_execution_verified']
    assert not status['dboot_quick_reboot_car_verified'] and not status['broader_compatibility_verified']
    assert not status['rollback_verified'] and (ROOT/status['test_device']).is_file()
    assert (RELEASE/'SHA256SUMS.txt').read_text().strip()==LGU_SHA+'  upgrade.lgu'
    if lgu:
        assert lgu.stat().st_size==container['bytes'] and sha(lgu.read_bytes())==LGU_SHA
    print(json.dumps(dict(release='7.0.6.MAX32',members=1920,exact_MAX31_members=1917,
                          changed_members=sorted(changes),source_pins=len(pins),
                          complete_release_car_test=False,lgu_bytes_checked=bool(lgu)),indent=2))


if __name__=='__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--lgu',type=Path)
    main(parser.parse_args().lgu)
