"""Complete cumulative development staging, independently read back; no release."""
import hashlib
import json
from datetime import datetime,timezone
from pathlib import Path
from patch_usb_input_safety import patch
from verify_usb_input_safety import verify
from verify_media_responsiveness import verify_usb

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/media-responsiveness-development-01'
OUT=ROOT/'build/usb-input-safety-development-01'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
SYSTEM='upgrade/Storage Card/System/'
PROOF=ROOT/'analysis/firmware/usb-input-safety-development.json'


def sha(raw):return hashlib.sha256(raw).hexdigest()


def main():
    assert not OUT.exists(),'Existing builds are never overwritten'
    manifest_raw=(BASE/'manifest.json').read_bytes();manifest=json.loads(manifest_raw)
    published=json.loads((RELEASE/'build-manifest.json').read_text(encoding='utf-8'))
    lgu_sha=sha((RELEASE/'upgrade.lgu').read_bytes())
    assert lgu_sha==published['verification']['lgu_sha256']
    before={}
    for row in manifest['members']:
        name=row['path'];assert name.startswith('upgrade/') and '..' not in Path(name).parts
        raw=(BASE/'payload'/name).read_bytes()
        assert len(raw)==row['bytes'] and sha(raw)==row['sha256']
        before[name]=raw
    assert len(before)==1918 and set(before)=={row['path'] for row in published['verification']['members']}
    name=SYSTEM+'MgrUSB.exe';new,recipe=patch(before[name])
    # Undo every reviewed code/table edit and require the exact input bytes.
    restored=bytearray(new)
    for edit in [*recipe['edits'],recipe['relocations']]:
        at=int(edit['offset'],16);size=edit['bytes']
        assert new[at:at+size].hex()==edit['after_hex']
        restored[at:at+size]=bytes.fromhex(edit['before_hex'])
    assert bytes(restored)==before[name]
    proof=json.loads(PROOF.read_text(encoding='utf-8'));assert recipe==proof['recipe']
    after=before.copy();after[name]=new
    for path,raw in after.items():
        destination=OUT/'payload'/path
        destination.parent.mkdir(parents=True,exist_ok=True);destination.write_bytes(raw)
    readback={p.relative_to(OUT/'payload').as_posix():p.read_bytes()
              for p in (OUT/'payload').rglob('*') if p.is_file()}
    assert readback==after and set(readback)==set(before)
    checks=verify(readback[name]);assert checks==proof['checks']
    original=(ROOT/'extracted/705md/upgrade/Storage Card/System/MgrUSB.exe').read_bytes()
    previous_resume=verify_usb(original,readback[name])
    assert previous_resume['cases']==25
    assert [p for p in before if before[p]!=readback[p]]==[name]
    release_members={r['path']:r for r in published['verification']['members']}
    modified=[p for p in readback if sha(readback[p])!=release_members[p]['sha256']]
    assert len(modified)==6
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='Complete cumulative development payload, not an installable update or release',
                previous_release='7.0.6.MAX03',previous_lgu_sha256=lgu_sha,
                carried_forward_manifest_sha256=sha(manifest_raw),
                previous_members=1918,output_members=len(readback),missing_members=[],added_members=[],
                changed_from_development=[name],unchanged_from_development=1917,
                modified_from_published_release=modified,unchanged_from_published_release=1912,
                recipe=recipe,readback_checks=checks,previous_usb_resume_checks=previous_resume,
                proof=dict(path=str(PROOF.relative_to(ROOT)),sha256=sha(PROOF.read_bytes())),
                tools={p:sha((ROOT/'tools'/p).read_bytes()) for p in
                       ('patch_usb_input_safety.py','verify_usb_input_safety.py','build_usb_input_safety_development.py')},
                native_executed=False,hardware_tested=False,installation_ready=False,
                release_built=False,version_bumped=False,transactional_saves=False,
                members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),
                              previous_release_sha256=release_members[p]['sha256'],
                              previous_development_sha256=sha(before[p])) for p in sorted(readback)])
    (OUT/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (OUT/'README.md').write_text(
        '# USB input safety development\n\n'
        'Complete cumulative staging: all 1,918 MAX03 paths and every earlier Bluetooth/audio/navigation, English UI, installer, touch and menu improvement are retained. Only MgrUSB changes versus media-responsiveness-development-01. No LGU, ZIP release or new version.\n\n'
        'Resume writes check exact counts and close results; the loader closes once, terminates all text slots and rejects failed file-attribute calls. This is not transactional saving or protection against a power cut. Some existing save callers ignore failure.\n\n'
        'Status text copies use whole UTF16 units. Ordinary ID3v2.4 frame and extended-header sizes, frame containment and final-frame dispatch are corrected. Unsupported frame transforms are skipped; the original encoding converter, cover-art and ASF parsing remain separate work.\n\n'
        'Playlist paths are bounded, short suffixes checked and missing files/directories rejected. Actual M3U/PLS/WPL reader checks pass. Existing playlist line splitting, drive/URL/dot-component handling and order are not redesigned.\n\n'
        'Not an installable update. Native CE loader/storage/display and the carried-forward installer prototype need hardware validation. See analysis/usb-input-safety-development.md and manifest.json.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==lgu_sha
    assert all((BASE/'payload'/p).read_bytes()==raw for p,raw in before.items())
    print(json.dumps(dict(output=str(OUT),members=1918,unchanged_from_development=1917,
                          usb_sha256=sha(new),checks=checks,previous_resume_cases=25,
                          release_built=False),indent=2))


if __name__=='__main__':main()
