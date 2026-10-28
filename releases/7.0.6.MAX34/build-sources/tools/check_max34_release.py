"""Check MAX34 candidate inventory, frozen sources and evidence without firmware."""
import argparse,ast,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]

def sha(b):return hashlib.sha256(b).hexdigest()

def check(release,lgu=None):
    read=lambda n:json.loads((release/n).read_bytes())
    m=read('build-manifest.json');p=read('member-plan.json');c=m['container_verification']
    baseline=json.loads((release.parent/'7.0.6.MAX33/build-manifest.json').read_bytes())['container_verification']
    before={r['path']:r for r in baseline['members']};after={r['path']:r for r in c['members']}
    assert m['revision']==c['content']=='7.0.6.MAX34'and m['baseline_lgu_sha256']==baseline['lgu_sha256']
    assert len(before)==len(after)==1921 and set(before)==set(after)
    changed={n for n in before if before[n]['sha256']!=after[n]['sha256']}
    expected={'upgrade/Storage Card/'+n for n in ['InstallResume.exe','Recovery.exe','System/UpgradeManager.exe',
        'System/MgrUSB.exe','System/CmnDll.dll','System/Version_Info.txt']}
    assert changed==expected==set(p['changed_members'])==set(m['changed_members'])
    assert p['retained_members']==m['exact_previous_members']==1915 and not p['missing_members']and not p['added_members']
    assert after['upgrade/Storage Card/System/Version_Info.txt']['sha256']==sha(b'7.0.6.MAX34')
    assert {r['path']:(r['after']['bytes'],r['after']['sha256'])for r in p['members']}=={n:(r['bytes'],r['sha256'])for n,r in after.items()}
    assert c['header_crc_valid']and c['member_crc_sizes_hashes_valid']
    proof=read('verification.json');usb=read('usb-transition-evidence/usb-verification.json')
    worker=read('usb-transition-evidence/worker-verification.json');native=read('usb-transition-evidence/native-verification.json')
    assert proof==m['byte_verification']and all(v['passed']for v in [proof,usb,worker,native])
    assert proof['cases']==usb['cases']+worker['cases']+native['cases']==len(proof['checks'])
    assert usb['cases']>=182 and usb['input_sha256']==before['upgrade/Storage Card/System/MgrUSB.exe']['sha256']
    assert usb['output_sha256']==after['upgrade/Storage Card/System/MgrUSB.exe']['sha256']
    assert not m['published']and not m['car_tested']and not proof['physical_tested']
    status=read('device-status.json');assert status['candidate_only']and not status['published']and not status['car_tested']
    for name,digest in m['source_pins'].items():
        raw=(release/'build-sources'/name).read_bytes();assert sha(raw)==digest,name
        if name.endswith('.py'):ast.parse(raw.decode('utf-8-sig'),feature_version=(3,12))
    for folder,name,path in [('engine','install_resume34.c','InstallResume.exe'),('menu','recovery34.c','Recovery.exe')]:
        info=read('usb-transition-evidence/'+folder+'/build.json')
        assert info['exe_sha256']==after['upgrade/Storage Card/'+path]['sha256']
        assert sha((release/'usb-transition-evidence'/folder/name).read_bytes())==m['source_pins']['tools/'+name]
    for row in (release/'SHA256SUMS.txt').read_text(encoding='utf-8').splitlines():
        digest,name=row.split('  ',1)
        if name=='upgrade.lgu'and not(release/name).exists():continue
        assert sha((release/name).read_bytes())==digest,name
    if lgu:assert lgu.stat().st_size==c['bytes']and sha(lgu.read_bytes())==c['lgu_sha256']
    summary=dict(passed=True,revision=m['revision'],members=1921,byte_exact_MAX33_members=1915,
        checks=proof['cases'],source_pins=len(m['source_pins']),car_tested=False,lgu_checked=bool(lgu))
    print(json.dumps(summary,indent=2));return summary

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--release',type=Path,default=ROOT/'releases/7.0.6.MAX34');p.add_argument('--lgu',type=Path);a=p.parse_args()
    check(a.release,a.lgu)
