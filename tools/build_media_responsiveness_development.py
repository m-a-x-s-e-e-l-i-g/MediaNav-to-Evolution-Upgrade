"""Write and verify the full cumulative internal development payload; no LGU/release."""
import argparse
import hashlib
import json
import re
from datetime import datetime,timezone
from pathlib import Path
import pefile
from patch_media_responsiveness import patch_app,patch_usb
from verify_media_responsiveness import verify
from verify_appmain_label_scan import verify as verify_arabic
from inspect_media_performance import inspect as inspect_performance

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/updater-copy-safety-development-02'
RELEASE=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
SYSTEM='upgrade/Storage Card/System/'
PROOF=ROOT/'analysis/firmware/media-responsiveness-development.json'


def sha(raw):return hashlib.sha256(raw).hexdigest()


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--output',default='media-responsiveness-development-01')
    args=parser.parse_args()
    assert re.fullmatch(r'media-responsiveness-development-[0-9]{2}',args.output)
    out=ROOT/'build'/args.output
    assert not out.exists(),'Existing development builds are never overwritten'
    manifest=json.loads((BASE/'manifest.json').read_text(encoding='utf-8'))
    previous=json.loads((RELEASE/'build-manifest.json').read_text(encoding='utf-8'))
    release_sha=sha((RELEASE/'upgrade.lgu').read_bytes())
    assert release_sha==previous['verification']['lgu_sha256']
    before={}
    for row in manifest['members']:
        name=row['path'];assert name.startswith('upgrade/') and '..' not in Path(name).parts
        raw=(BASE/'payload'/name).read_bytes();assert len(raw)==row['bytes'] and sha(raw)==row['sha256']
        before[name]=raw
    assert len(before)==1918 and set(before)=={r['path'] for r in previous['verification']['members']}
    after=before.copy();recipes={}
    for name,patch in (('AppMain.exe',patch_app),('MgrUSB.exe',patch_usb)):
        old=before[SYSTEM+name];new,recipe=patch(old)
        restored=bytearray(new)
        for edit in recipe['edits']:
            at=int(edit['offset'],16);n=edit['bytes']
            assert new[at:at+n].hex()==edit['after_hex']
            restored[at:at+n]=bytes.fromhex(edit['before_hex'])
        assert bytes(restored)==old,'Unexpected change outside reviewed ranges'
        a,b=pefile.PE(data=old),pefile.PE(data=new)
        assert old[:a.OPTIONAL_HEADER.SizeOfHeaders]==new[:b.OPTIONAL_HEADER.SizeOfHeaders]
        for x,y in zip(a.sections,b.sections):
            assert x.__pack__()==y.__pack__()
            if x.Name.rstrip(b'\0')!=b'.text':assert x.get_data()==y.get_data()
        assert len(old)==len(new)
        after[SYSTEM+name]=new;recipes[name]=recipe
    proof=json.loads(PROOF.read_text(encoding='utf-8'))
    assert proof['app_recipe']==recipes['AppMain.exe'] and proof['usb_recipe']==recipes['MgrUSB.exe']
    assert proof['checks']['performance']['exhaustive_utf16_cases']==65536
    for name,raw in after.items():
        p=out/'payload'/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(raw)
    readback={p.relative_to(out/'payload').as_posix():p.read_bytes() for p in (out/'payload').rglob('*') if p.is_file()}
    assert readback==after and set(readback)==set(before)
    app,usb=readback[SYSTEM+'AppMain.exe'],readback[SYSTEM+'MgrUSB.exe']
    checks=verify(before[SYSTEM+'AppMain.exe'],app,before[SYSTEM+'MgrUSB.exe'],usb,exhaustive=False)
    assert checks['performance']['benchmarks']==proof['checks']['performance']['benchmarks']
    original=(ROOT/'extracted/705md/upgrade/Storage Card/System/AppMain.exe').read_bytes()
    arabic=verify_arabic(original,app,exhaustive=False)
    performance=inspect_performance(app)
    changed=[p for p in before if before[p]!=readback[p]]
    assert set(changed)=={SYSTEM+'AppMain.exe',SYSTEM+'MgrUSB.exe'}
    published={r['path']:r for r in previous['verification']['members']}
    modified=[p for p in readback if sha(readback[p])!=published[p]['sha256']]
    assert len(modified)==6
    assert readback[SYSTEM+'Version_Info.txt']==before[SYSTEM+'Version_Info.txt']
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='Complete cumulative internal development payload, not an installable update or release',
                previous_release='7.0.6.MAX03',previous_lgu_sha256=release_sha,
                carried_forward_manifest_sha256=sha((BASE/'manifest.json').read_bytes()),
                previous_members=1918,output_members=len(readback),missing_members=[],added_members=[],
                changed_from_development=changed,unchanged_from_development=1916,
                modified_from_published_release=modified,unchanged_from_published_release=1912,
                recipes=recipes,readback_checks=checks,previous_arabic_scan_checks=arabic,
                exhaustive_hebrew_evidence=dict(path=str(PROOF.relative_to(ROOT)),sha256=sha(PROOF.read_bytes()),
                                                checks=proof['checks']['performance']),
                performance_audit=performance,
                tools={name:sha((ROOT/'tools'/name).read_bytes()) for name in
                       ('patch_media_responsiveness.py','verify_media_responsiveness.py',
                        'build_media_responsiveness_development.py','inspect_media_performance.py')},
                native_executed=False,hardware_tested=False,installation_ready=False,
                release_built=False,version_bumped=False,
                members=[dict(path=p,bytes=len(readback[p]),sha256=sha(readback[p]),
                              previous_release_sha256=published[p]['sha256'],
                              previous_development_sha256=sha(before[p])) for p in sorted(readback)])
    (out/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (out/'README.md').write_text(
        '# Media responsiveness development\n\n'
        'Complete cumulative staging: all 1,918 previous-release files, existing Bluetooth/audio/navigation fixes, English UI and installer copy-safety prototype are retained. AppMain and MgrUSB gain the USB resume, outside-release cancellation and menu text-scan changes. No LGU, ZIP release or new version is created.\n\n'
        'This directory is not an installable update. The carried-forward updater requires native CE loader/storage/display validation; see analysis/updater-copy-safety-development.md. Do not install the full prototype staging on a unit.\n\n'
        'Readback checks exercise actual MIPS bytes with explicit OS/GUI/file/graph fixtures. They do not emulate native touch-driver event order, scheduling, audio focus or elapsed-time performance. Menu text processing does less work; actual menu speed is unmeasured. Startup/source-switch waits remain unchanged pending readiness and unit timing evidence.\n\n'
        'See analysis/media-responsiveness-development.md for implementation, evidence and planned hardware checks.\n',encoding='utf-8')
    assert sha((RELEASE/'upgrade.lgu').read_bytes())==release_sha
    assert all((BASE/'payload'/p).read_bytes()==raw for p,raw in before.items())
    print(json.dumps(dict(output=str(out),members=len(readback),changed_from_development=changed,
                          touch_cases=checks['touch']['cases'],usb_cases=checks['usb_resume']['cases'],
                          exhaustive_utf16_cases=65536,mixed_utf16_cases=checks['performance']['mixed_cases'],
                          startup_cases=performance['startup_cases'],release_built=False,
                          app_sha256=sha(app),usb_sha256=sha(usb)),indent=2))


if __name__=='__main__':main()
