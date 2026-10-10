"""Full cumulative saved-mode validation build and written-byte verification."""
import hashlib
import json
from datetime import datetime,timezone
from pathlib import Path
from patch_usb_resume_modes import patch
from verify_usb_resume_modes import verify,structure
from verify_usb_folders import verify as folders_verify,retained_sorting,ITER,CHECK,parsed
import struct
from verify_wma_shuffle_v2 import verify as wma_verify
from verify_artwork_playlist import verify as artwork_verify,regressions

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/usb-folders-development-01'
OUT=ROOT/'build/usb-resume-modes-development-01'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
PROOF=ROOT/'analysis/firmware/usb-resume-modes-development.json'
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
    print('Full payload written and read back; running saved-mode checks',flush=True)
    checks=verify(readback[USB]);checks['structure']=structure(readback[USB],recipe)
    print('Saved-mode checks passed; running retained folder checks',flush=True)
    folders=folders_verify(readback[USB])
    previous_pe=parsed(before[USB]);current_pe=parsed(readback[USB])
    for start,end in [(0x14720,0x14730),(0x14884,0x14894),(ITER,ITER+0x300),(CHECK,CHECK+0x100)]:
        assert previous_pe.get_data(start-0x10000,end-start)==current_pe.get_data(start-0x10000,end-start)
    d=current_pe.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=current_pe.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    assert (ITER,ITER+440,0,0,ITER+40) in rows and (CHECK,CHECK+168,0,0,CHECK+24) in rows
    assert all(next(r for r in rows if r[0]==n)[4]==n for n in (0x14720,0x14884))
    folders['structure']=dict(cases=1,previous_folder_code_and_exception_rows_preserved=True,
        all_relocated_exception_rows_checked_by_current_structure=True)
    print('Folder checks passed; running retained sorting checks',flush=True)
    sorting=retained_sorting(readback[USB])
    print('Sorting checks passed; running retained WMA/artwork/USB checks',flush=True)
    retained=dict(folders=folders,sorting=sorting,wma=wma_verify(readback[USB]),artwork=artwork_verify(readback[USB]),earlier=regressions(readback[USB]))
    new_cases=sum(c.get('cases',0) for c in checks.values())
    retained_cases=sum(c.get('cases',0) for c in folders.values())+sum(c.get('cases',0) for c in sorting.values())+sum(c.get('cases',0) for c in retained['wma'].values())+sum(c.get('cases',0) for c in retained['artwork'].values())+728
    assert retained_cases==6196 and new_cases==66190
    proof=dict(recipe=recipe,checks=checks,retained_checks=retained,native_executed=False,hardware_tested=False)
    PROOF.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    changed=[p for p in before if before[p]!=readback[p]];assert changed==[USB]
    modified=[p for p in readback if sha(readback[p])!=released[p]['sha256']];assert len(modified)==6
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),kind='Complete cumulative development; not an installable update or release',
        previous_release='7.0.6.MAX03',previous_lgu_sha256=lgu_sha,carried_forward_manifest_sha256=sha(manifest),
        previous_development='usb-folders-development-01',previous_members=1918,output_members=1918,
        missing_members=[],added_members=[],changed_from_development=changed,unchanged_from_development=1917,
        modified_from_published_release=modified,unchanged_from_published_release=1912,
        recipe=recipe,readback_checks=checks,retained_checks=retained,new_cases=new_cases,retained_cases=retained_cases,
        proof=dict(path=str(PROOF.relative_to(ROOT)),sha256=sha(PROOF.read_bytes())),
        tools={name:sha((ROOT/'tools'/name).read_bytes()) for name in ('patch_usb_resume_modes.py','verify_usb_resume_modes.py','build_usb_resume_modes_development.py')},
        native_executed=False,hardware_tested=False,installation_ready=False,release_built=False,version_bumped=False,
        native_timing_measured=False,
        members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),previous_release_sha256=released[p]['sha256'],
                      previous_development_sha256=sha(before[p])) for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text('# USB saved repeat/shuffle development\n\nAll 1,918 previous paths and improvements retained. '
        'Only MgrUSB changes versus usb-folders-development-01. No LGU, version bump or release.\n\n'
        'Saved repeat values 0–3 and shuffle values 0–1 are retained exactly. Other DWORD values '
        'become off when published into playback and shared fields. The saved bytes and checksum '
        'remain unchanged. Primary/backup file loading and failure behavior are retained. '
        'The three existing attach/resume call-site slices execute the checked loader and new guard.\n\n'
        f'{new_cases} new + {retained_cases} retained written-byte cases pass. The retained sorting workload '
        'reuses its verified original baseline and reruns the current workload. Filesystem operations '
        'use fixtures. Native loading/unwind, hardware playback and full installation remain unverified. '
        'This guard validates saved settings; other IPC setters and thread snapshots are separate. '
        'See analysis/usb-resume-modes-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu_sha
    assert all((BASE/'payload'/p).read_bytes()==b for p,b in before.items())
    print(json.dumps(dict(output=str(OUT),members=1918,usb_sha256=sha(readback[USB]),new_cases=new_cases,
                          retained_cases=retained_cases,release_built=False),indent=2),flush=True)

if __name__=='__main__':main()
