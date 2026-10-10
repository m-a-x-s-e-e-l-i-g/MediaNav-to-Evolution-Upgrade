"""Full cumulative staging and written-file verification; no LGU or release."""
import hashlib
import json
from datetime import datetime,timezone
from pathlib import Path
from patch_artwork_playlist import patch
from verify_artwork_playlist import verify,structure,regressions

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/usb-reliability-development-01'
OUT=ROOT/'build/artwork-playlist-development-01'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
PROOF=ROOT/'analysis/firmware/artwork-playlist-development.json'
USB='upgrade/Storage Card/System/MgrUSB.exe'


def sha(b):return hashlib.sha256(b).hexdigest()


def main():
    assert not OUT.exists(),'Prior development builds are never overwritten'
    original_manifest=(BASE/'manifest.json').read_bytes();base=json.loads(original_manifest)
    for name,digest in base['tools'].items():assert sha((ROOT/'tools'/name).read_bytes())==digest
    assert sha((ROOT/base['proof']['path']).read_bytes())==base['proof']['sha256']
    release=json.loads((RELEASE/'build-manifest.json').read_text(encoding='utf-8'))
    lgu_sha=sha((RELEASE/'upgrade.lgu').read_bytes());assert lgu_sha==release['verification']['lgu_sha256']
    released={r['path']:r for r in release['verification']['members']}
    before={}
    for row in base['members']:
        path=row['path'];assert path.startswith('upgrade/') and '..' not in Path(path).parts
        b=(BASE/'payload'/path).read_bytes();assert len(b)==row['bytes'] and sha(b)==row['sha256']
        before[path]=b
    assert len(before)==1918 and set(before)==set(released)
    after=before.copy();after[USB],recipe=patch(before[USB])
    for path,b in after.items():
        destination=OUT/'payload'/path;destination.parent.mkdir(parents=True,exist_ok=True);destination.write_bytes(b)
    readback={p.relative_to(OUT/'payload').as_posix():p.read_bytes()
              for p in (OUT/'payload').rglob('*') if p.is_file()}
    assert readback==after
    checks=verify(readback[USB]);checks['structure']=structure(readback[USB],recipe)
    retained=regressions(readback[USB])
    proof=dict(recipe=recipe,checks=checks,retained_checks=retained,native_executed=False,hardware_tested=False)
    PROOF.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    changed=[p for p in before if before[p]!=readback[p]];assert changed==[USB]
    modified=[p for p in readback if sha(readback[p])!=released[p]['sha256']];assert len(modified)==6
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='Complete cumulative development; not an installable update or release',
                previous_release='7.0.6.MAX03',previous_lgu_sha256=lgu_sha,
                carried_forward_manifest_sha256=sha(original_manifest),
                previous_members=1918,output_members=1918,missing_members=[],added_members=[],
                changed_from_development=changed,unchanged_from_development=1917,
                modified_from_published_release=modified,unchanged_from_published_release=1912,
                recipe=recipe,readback_checks=checks,retained_checks=retained,
                proof=dict(path=str(PROOF.relative_to(ROOT)),sha256=sha(PROOF.read_bytes())),
                tools={name:sha((ROOT/'tools'/name).read_bytes()) for name in
                       ('patch_artwork_playlist.py','verify_artwork_playlist.py','build_artwork_playlist_development.py')},
                native_executed=False,hardware_tested=False,installation_ready=False,
                release_built=False,version_bumped=False,native_timing_measured=False,
                members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),
                              previous_release_sha256=released[p]['sha256'],
                              previous_development_sha256=sha(before[p])) for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text(
        '# Artwork and playlist development\n\n'
        'All 1,918 previous paths and earlier improvements are retained. Only MgrUSB changes versus '
        'usb-reliability-development-01. No LGU, version bump or release.\n\n'
        'APIC/PIC artwork is bounded to the frame and 8 MiB buffer; encoded descriptions are skipped correctly. '
        'The image decoder receives the actual artwork length. Bitmap row padding is corrected, three-byte '
        'pixel changes are inlined, and a redundant 3,652-byte metadata copy is removed.\n\n'
        'Playlist readers skip oversized physical lines, preserve full-buffer EOF/CRLF boundaries, distinguish '
        'read failure from EOF, and remove leading UTF8 BOMs. Existing path policy, sorting and playlist limits remain.\n\n'
        '376 new written-byte checks and 728 retained checks pass. The representative bitmap loop uses about '
        '23 percent fewer interpreted instructions; native elapsed time is not measured. Native CE loader, '
        'imaging/CRT/display and the carried-forward installer/storage changes still need hardware testing. '
        'Not an installable update. See analysis/artwork-playlist-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu_sha
    assert all((BASE/'payload'/p).read_bytes()==b for p,b in before.items())
    print(json.dumps(dict(output=str(OUT),members=1918,unchanged_from_development=1917,
                          usb_sha256=sha(readback[USB]),new_cases=376,retained_cases=728,release_built=False),indent=2))


if __name__=='__main__':main()
