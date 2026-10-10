"""Stage every previous member, then verify the written bytes. No LGU/release."""
import hashlib
import json
from datetime import datetime,timezone
from pathlib import Path
from patch_usb_reliability import patch
from verify_usb_reliability import verify

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/usb-input-safety-development-01'
OUT=ROOT/'build/usb-reliability-development-01'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
PROOF=ROOT/'analysis/firmware/usb-reliability-development.json'
USB='upgrade/Storage Card/System/MgrUSB.exe'


def sha(raw):return hashlib.sha256(raw).hexdigest()


def main():
    assert not OUT.exists(),'Never overwrite existing development builds'
    manifest_raw=(BASE/'manifest.json').read_bytes();manifest=json.loads(manifest_raw)
    for name,digest in manifest['tools'].items():assert sha((ROOT/'tools'/name).read_bytes())==digest
    assert sha((ROOT/manifest['proof']['path']).read_bytes())==manifest['proof']['sha256']
    published=json.loads((RELEASE/'build-manifest.json').read_text(encoding='utf-8'))
    lgu_sha=sha((RELEASE/'upgrade.lgu').read_bytes())
    assert lgu_sha==published['verification']['lgu_sha256']
    previous={r['path']:r for r in published['verification']['members']}
    before={}
    for row in manifest['members']:
        name=row['path'];assert name.startswith('upgrade/') and '..' not in Path(name).parts
        raw=(BASE/'payload'/name).read_bytes()
        assert len(raw)==row['bytes'] and sha(raw)==row['sha256'];before[name]=raw
    assert len(before)==1918 and set(before)==set(previous)
    new,recipe=patch(before[USB]);after=before.copy();after[USB]=new
    for path,raw in after.items():
        destination=OUT/'payload'/path
        destination.parent.mkdir(parents=True,exist_ok=True);destination.write_bytes(raw)
    readback={p.relative_to(OUT/'payload').as_posix():p.read_bytes()
              for p in (OUT/'payload').rglob('*') if p.is_file()}
    assert readback==after and set(readback)==set(before)
    checks=verify(readback[USB],recipe)
    proof=dict(recipe=recipe,checks=checks,native_executed=False,hardware_tested=False)
    PROOF.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    changed=[p for p in readback if before[p]!=readback[p]];assert changed==[USB]
    modified=[p for p in readback if sha(readback[p])!=previous[p]['sha256']];assert len(modified)==6
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='Complete cumulative development payload; no installable update or release',
                previous_release='7.0.6.MAX03',previous_lgu_sha256=lgu_sha,
                carried_forward_manifest_sha256=sha(manifest_raw),
                previous_members=1918,output_members=1918,missing_members=[],added_members=[],
                changed_from_development=changed,unchanged_from_development=1917,
                modified_from_published_release=modified,unchanged_from_published_release=1912,
                recipe=recipe,readback_checks=checks,
                proof=dict(path=str(PROOF.relative_to(ROOT)),sha256=sha(PROOF.read_bytes())),
                tools={p:sha((ROOT/'tools'/p).read_bytes()) for p in
                       ('patch_usb_reliability.py','verify_usb_reliability.py','build_usb_reliability_development.py')},
                native_executed=False,hardware_tested=False,installation_ready=False,
                release_built=False,version_bumped=False,
                physical_power_cut_tested=False,
                members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),
                              previous_release_sha256=previous[p]['sha256'],
                              previous_development_sha256=sha(before[p])) for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text(
        '# USB title encoding and recoverable playback state\n\n'
        'Complete cumulative development: all 1,918 previous paths and earlier Bluetooth/audio/navigation, '
        'English UI, installer, touch, menu and USB repairs are retained. Only MgrUSB changes versus '
        'usb-input-safety-development-01. No LGU, ZIP release or version bump.\n\n'
        'ID3 text uses its declared Latin1 / UTF16 / UTF16BE / UTF8 encoding. Full BOMs and byte boundaries '
        'are checked, and encoding plus raw length survives language-change cache conversion. '
        'Legacy ID3v1 fallback and its table-based genre are retained.\n\n'
        'Resume saves write a .new file, flush/close, read back and compare every byte before rotating '
        'the prior validated state to .bak. Loading prefers the canonical file and falls back to .bak; '
        'uncommitted .new files are never loaded. The original 3,180-byte format remains compatible.\n\n'
        'This adds synchronous I/O; it does not establish faster playback or physical power-cut durability. '
        'Some existing save callers still ignore errors. Native CE loader/unwind, code pages, filesystem, '
        'locking, display, timing and carried-forward installer behavior need hardware testing. '
        'Not an installable update. See analysis/usb-reliability-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu_sha
    assert all((BASE/'payload'/p).read_bytes()==raw for p,raw in before.items())
    print(json.dumps(dict(output=str(OUT),members=1918,unchanged_from_development=1917,
                          usb_sha256=sha(new),new_cases=sum(checks[n]['cases'] for n in
                          ('encodings','cached','id3_parser','persistence')),
                          retained_resume_cases=checks['previous_resume']['cases'],release_built=False),indent=2))


if __name__=='__main__':main()
