"""Full cumulative staging, readback verification and retained byte suites."""
import hashlib
import json
from datetime import datetime,timezone
from pathlib import Path
from patch_usb_sorting import patch
from verify_usb_sorting import verify,structure
from verify_wma_shuffle_v2 import verify as wma_verify
from verify_artwork_playlist import verify as artwork_verify,regressions

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/wma-shuffle-development-02'
OUT=ROOT/'build/usb-sorting-development-01'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
PROOF=ROOT/'analysis/firmware/usb-sorting-development.json'
USB='upgrade/Storage Card/System/MgrUSB.exe'
def sha(b):return hashlib.sha256(b).hexdigest()

def main():
    assert not OUT.exists(),'Prior development builds are never overwritten'
    manifest=(BASE/'manifest.json').read_bytes();base=json.loads(manifest)
    for name,digest in base['tools'].items():assert sha((ROOT/'tools'/name).read_bytes())==digest
    assert sha((ROOT/base['proof']['path']).read_bytes())==base['proof']['sha256']
    release=json.loads((RELEASE/'build-manifest.json').read_text(encoding='utf-8'))
    lgu_sha=sha((RELEASE/'upgrade.lgu').read_bytes());assert lgu_sha==release['verification']['lgu_sha256']
    released={r['path']:r for r in release['verification']['members']};before={}
    for row in base['members']:
        path=row['path'];assert path.startswith('upgrade/') and '..' not in Path(path).parts
        b=(BASE/'payload'/path).read_bytes();assert len(b)==row['bytes'] and sha(b)==row['sha256'];before[path]=b
    assert len(before)==1918 and set(before)==set(released)
    after=before.copy();after[USB],recipe=patch(before[USB])
    for path,b in after.items():
        destination=OUT/'payload'/path;destination.parent.mkdir(parents=True,exist_ok=True);destination.write_bytes(b)
    readback={p.relative_to(OUT/'payload').as_posix():p.read_bytes() for p in (OUT/'payload').rglob('*') if p.is_file()}
    assert readback==after
    print('Full payload written and read back; running sorting checks',flush=True)
    checks=verify(readback[USB]);checks['structure']=structure(readback[USB],recipe)
    print(json.dumps(checks['performance']),flush=True)
    print('Sorting checks passed; running all retained WMA/artwork/USB checks',flush=True)
    retained=dict(wma=wma_verify(readback[USB]),artwork=artwork_verify(readback[USB]),earlier=regressions(readback[USB]))
    new_cases=sum(c.get('cases',0) for c in checks.values())
    retained_cases=sum(c.get('cases',0) for c in retained['wma'].values())+sum(c.get('cases',0) for c in retained['artwork'].values())+728
    assert retained_cases==1488
    proof=dict(recipe=recipe,checks=checks,retained_checks=retained,native_executed=False,hardware_tested=False)
    PROOF.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    changed=[p for p in before if before[p]!=readback[p]];assert changed==[USB]
    modified=[p for p in readback if sha(readback[p])!=released[p]['sha256']];assert len(modified)==6
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),kind='Complete cumulative development; not an installable update or release',
        previous_release='7.0.6.MAX03',previous_lgu_sha256=lgu_sha,carried_forward_manifest_sha256=sha(manifest),
        previous_development='wma-shuffle-development-02',previous_members=1918,output_members=1918,
        missing_members=[],added_members=[],changed_from_development=changed,unchanged_from_development=1917,
        modified_from_published_release=modified,unchanged_from_published_release=1912,
        recipe=recipe,readback_checks=checks,retained_checks=retained,new_cases=new_cases,retained_cases=retained_cases,
        proof=dict(path=str(PROOF.relative_to(ROOT)),sha256=sha(PROOF.read_bytes())),
        tools={name:sha((ROOT/'tools'/name).read_bytes()) for name in ('patch_usb_sorting.py','verify_usb_sorting.py','build_usb_sorting_development.py')},
        native_executed=False,hardware_tested=False,installation_ready=False,release_built=False,version_bumped=False,
        native_timing_measured=False,
        members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),previous_release_sha256=released[p]['sha256'],
                      previous_development_sha256=sha(before[p])) for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text('# USB sorting development\n\nAll 1,918 previous paths and earlier improvements retained. '
        'Only MgrUSB changes versus wma-shuffle-development-02. No LGU, version bump or release.\n\n'
        'Filename comparison stops at the first difference and uses the original mapping function only for those '
        'two characters. Original case/accent/raw-unit tie breaks and signed table lookup are retained. '
        'No persistent cache or catalog lifecycle changes. Temporary comparator frame: 2,112 -> 80 bytes; '
        'no two 1,040-byte key buffers.\n\n'
        f'{new_cases} new and {retained_cases} retained written-byte cases pass. Sort API algorithm is a host fixture; '
        'CE loading/unwind, scheduler/concurrency, device timing and full installation remain unverified. '
        'See analysis/usb-sorting-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu_sha
    assert all((BASE/'payload'/p).read_bytes()==b for p,b in before.items())
    print(json.dumps(dict(output=str(OUT),members=1918,usb_sha256=sha(readback[USB]),new_cases=new_cases,
                          retained_cases=retained_cases,release_built=False),indent=2),flush=True)

if __name__=='__main__':main()
