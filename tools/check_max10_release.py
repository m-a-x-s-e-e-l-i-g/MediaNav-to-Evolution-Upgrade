"""Verify complete MAX10 inventory, exact source snapshots and device status."""
import ast
import hashlib
import json
from pathlib import Path
from release_payload import ROOT, plan_at

def main():
    release=ROOT/'releases/7.0.6.MAX10'
    plan=plan_at(ROOT/'src/patches/max10.json')
    manifest=json.loads((release/'build-manifest.json').read_bytes())
    old=json.loads((ROOT/'releases/7.0.6.MAX04/build-manifest.json').read_bytes())
    before={r['path']:r for r in old['verification']['members']}
    after={r['path']:r for r in manifest['verification']['members']}
    assert len(before)==len(after)==len(plan['members'])==1918 and before.keys()==after.keys()
    assert plan['released_lgu_sha256']==manifest['verification']['lgu_sha256']
    for row in plan['members']:
        a,b=before[row['path']],after[row['path']]
        assert (row['before_bytes'],row['before_sha256'])==(a['bytes'],a['sha256'])
        assert (row['after_bytes'],row['after_sha256'])==(b['bytes'],b['sha256'])
    changes={r['path'] for r in plan['changes']}
    assert changes=={name for name in before if before[name]['sha256']!=after[name]['sha256']}
    pins=json.loads((release/'source-manifest.json').read_bytes())['files']
    for row in pins:
        raw=(ROOT/row['path']).read_bytes()
        assert len(raw)==row['bytes'] and hashlib.sha256(raw).hexdigest()==row['sha256'],row['path']
        ast.parse(raw.decode('utf-8-sig'),feature_version=(3,12))
    for name,digest in manifest['source_pins'].items():
        path=release/'build-sources/workspace-tools'/Path(name.replace('\\','/')).name
        assert hashlib.sha256(path.read_bytes()).hexdigest()==digest,name
    status=json.loads((release/'device-status.json').read_bytes())
    assert status['installation_reported_by_user'] and status['bluetooth_album_art']=='OPEN: MAX10 physical test failed'
    assert (release/'SHA256SUMS.txt').read_text().strip()==plan['released_lgu_sha256']+'  upgrade.lgu'
    assert manifest['output_members']==1918 and manifest['unchanged_from_MAX09']==1916
    assert manifest['audio_title_UI_bytes_equal_MAX09'] and manifest['appmain_byte_identical_MAX09']
    print(json.dumps(dict(complete_members=1918,changed_since_MAX04=len(changes),
                          source_snapshots_verified=len(pins),album_art='OPEN - car test failed'),indent=2))

if __name__=='__main__':main()
