"""Verify full MAX15 plan, cumulative source pins and owner hardware feedback."""
import ast
import hashlib
import json
from pathlib import Path
from release_payload import ROOT,plan_at

def main():
    release=ROOT/'releases/7.0.6.MAX15'
    plan=plan_at(ROOT/'src/patches/max15.json')
    manifest=json.loads((release/'build-manifest.json').read_bytes())
    baseline=json.loads((ROOT/'releases/7.0.6.MAX04/build-manifest.json').read_bytes())
    before={r['path']:r for r in baseline['verification']['members']}
    after={r['path']:r for r in manifest['verification']['members']}
    assert before.keys()==after.keys() and len(plan['members'])==len(after)==1918
    assert plan['released_lgu_sha256']==manifest['verification']['lgu_sha256']=='ee416cfd77687448b94d046b79049793353cd40288a1675bfcf5a15504c28a98'
    for row in plan['members']:
        a,b=before[row['path']],after[row['path']]
        assert (row['before_bytes'],row['before_sha256'])==(a['bytes'],a['sha256'])
        assert (row['after_bytes'],row['after_sha256'])==(b['bytes'],b['sha256'])
    assert {r['path'] for r in plan['changes']}=={n for n in before if before[n]['sha256']!=after[n]['sha256']}
    for row in plan['changes']:
        if 'asset' in row:
            raw=(ROOT/row['asset']).read_bytes()
            assert hashlib.sha256(raw).hexdigest()==after[row['path']]['sha256']
    pins=json.loads((release/'source-manifest.json').read_bytes())['files']
    for row in pins:
        raw=(ROOT/row['path']).read_bytes()
        assert len(raw)==row['bytes'] and hashlib.sha256(raw).hexdigest()==row['sha256'],row['path']
        ast.parse(raw.decode('utf-8-sig'),feature_version=(3,12))
    for name,pin in manifest['source_pins'].items():
        snap=release/'build-sources/workspace-tools'/Path(name.replace('\\','/')).name
        assert hashlib.sha256(snap.read_bytes()).hexdigest()==pin
    status=json.loads((release/'device-status.json').read_bytes())
    assert status['installation_reported_by_user'] and status['bluetooth_album_art']=='CONFIRMED WORKING: owner car test MAX15'
    assert not status['broader_device_compatibility_verified']
    assert (ROOT/status['test_device']).is_file()
    assert (release/'SHA256SUMS.txt').read_text().strip()==plan['released_lgu_sha256']+'  upgrade.lgu'
    assert manifest['output_members']==1918 and manifest['unchanged_from_MAX14']==1916
    proof=json.loads((release/'verification.json').read_bytes())
    assert proof['max14_S0_reproduced'] and proof['window_create_to_display_pass'] and len(proof['artwork'])==17
    assert len(proof['window_startup_faults'])==6
    print(json.dumps(dict(complete_members=1918,changed_since_MAX04=len(plan['changes']),
        exact_source_dependencies=len(pins),album_art='Owner confirmed working in car MAX15'),indent=2))

if __name__=='__main__':main()
