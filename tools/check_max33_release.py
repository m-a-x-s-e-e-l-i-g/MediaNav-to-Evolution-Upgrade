"""Portable MAX33 candidate inventory/source/evidence check; optional LGU hash."""
import argparse,ast,hashlib,json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1];RELEASE=ROOT/'releases/7.0.6.MAX33'
def sha(b):return hashlib.sha256(b).hexdigest()
def read(name):return json.loads((RELEASE/name).read_bytes())
def main(lgu=None):
    m=read('build-manifest.json');c=m['container_verification'];p=read('member-plan.json');proof=read('verification.json')
    prior=json.loads((ROOT/'releases/7.0.6.MAX32/build-manifest.json').read_bytes())['container_verification']
    assert m['revision']==c['content']=='7.0.6.MAX33' and m['baseline_lgu_sha256']==prior['lgu_sha256']
    assert c['header_crc_valid']and c['member_crc_sizes_hashes_valid']
    before={r['path']:r for r in prior['members']};after={r['path']:r for r in c['members']}
    assert len(before)==1920 and len(after)==1921 and before.keys()<=after.keys()
    changed={n for n in before if before[n]['sha256']!=after[n]['sha256']}
    assert changed==set(m['changed_members'])==set(p['changed_members'])=={'upgrade/Storage Card/'+n for n in ['Recovery.exe','System/UpgradeManager.exe','System/Version_Info.txt','System/CmnDll.dll']}
    assert set(after)-set(before)==set(m['added_members'])=={'upgrade/Storage Card/InstallResume.exe'}
    assert p['retained_members']==m['exact_previous_members']==1916 and not p['missing_members']
    assert after['upgrade/Storage Card/System/Version_Info.txt']['sha256']==sha(b'7.0.6.MAX33')
    assert {r['path']:(r['after']['bytes'],r['after']['sha256'])for r in p['members']}=={n:(r['bytes'],r['sha256'])for n,r in after.items()}
    assert proof==m['byte_verification'] and proof['passed'] and not proof['physical_tested']
    wp=read('installer-resume-evidence/worker-verification.json');np=read('installer-resume-evidence/native-verification.json')
    assert wp['passed']and np['passed']and proof['cases']==wp['cases']+np['cases']==len(proof['checks'])
    assert not wp['physical_tested'] and not np['physical_tested']
    for name,digest in m['source_pins'].items():
        raw=(RELEASE/'build-sources'/name).read_bytes();assert sha(raw)==digest,name
        if name.endswith('.py'):ast.parse(raw.decode('utf-8-sig'),feature_version=(3,12))
    engine=read('installer-resume-evidence/engine/build.json');menu=read('installer-resume-evidence/menu/build.json')
    assert engine['exe_sha256']==after['upgrade/Storage Card/InstallResume.exe']['sha256']
    assert menu['exe_sha256']==after['upgrade/Storage Card/Recovery.exe']['sha256']
    assert engine['manifest_members']==1920 and engine['manifest_sha256']==sha((RELEASE/'installer-resume-evidence/engine/manifest.h').read_bytes())
    assert sha((RELEASE/'installer-resume-evidence/engine/install_resume33.c').read_bytes())==m['source_pins']['tools/install_resume33.c']
    assert sha((RELEASE/'installer-resume-evidence/menu/recovery33.c').read_bytes())==m['source_pins']['tools/recovery33.c']
    status=read('device-status.json');assert status['candidate_only']and not status['published']and not status['car_tested']and not status['universal_recovery_guarantee']
    assert not m['car_tested']and not m['published']and not m['universal_recovery_guarantee']
    assert (RELEASE/'SHA256SUMS.txt').read_text().strip()==c['lgu_sha256']+'  upgrade.lgu'
    if lgu:assert lgu.stat().st_size==c['bytes']and sha(lgu.read_bytes())==c['lgu_sha256']
    print(json.dumps(dict(candidate='7.0.6.MAX33',members=1921,exact_MAX32_members=1916,cases=proof['cases'],source_pins=len(m['source_pins']),physical_tested=False,published=False,lgu_checked=bool(lgu)),indent=2))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--lgu',type=Path);main(p.parse_args().lgu)
