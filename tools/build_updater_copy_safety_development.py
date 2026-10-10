"""Stage all previous release files plus English UI and installer prototype.

No LGU, version bump, ZIP release, publication or unit operation.
"""
import argparse
import hashlib
import json
import re
import struct
from datetime import datetime, timezone
from pathlib import Path

import pefile
from patch_updater_copy_safety import patch
from patch_ui_english import LABELS
from verify_ui_english import verify as verify_language
from verify_updater_copy_safety import verify as verify_copy

ROOT=Path(__file__).resolve().parents[1]
PREVIOUS=ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade'
BASE=ROOT/'build/maxmade-7.0.6.MAX03/roundtrip'
ENGLISH=ROOT/'build/ui-english-development-01'
SYSTEM='upgrade/Storage Card/System/'


def sha(raw):return hashlib.sha256(raw).hexdigest()


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--output',default='updater-copy-safety-development-02')
    args=parser.parse_args()
    assert re.fullmatch(r'updater-copy-safety-development-[0-9]{2}',args.output),'Output must be a simple internal development directory name'
    out=ROOT/'build'/args.output
    assert not out.exists(),'Existing development staging is never overwritten'
    previous=json.loads((PREVIOUS/'build-manifest.json').read_text(encoding='utf-8'))
    assert sha((PREVIOUS/'upgrade.lgu').read_bytes())==previous['verification']['lgu_sha256']
    before={}
    for row in previous['verification']['members']:
        name=row['path'];assert name.startswith('upgrade/') and '..' not in Path(name).parts
        b=(BASE/name).read_bytes();assert len(b)==row['bytes'] and sha(b)==row['sha256']
        before[name]=b
    english=json.loads((ENGLISH/'manifest.json').read_text(encoding='utf-8'))
    development={}
    for row in english['members']:
        name=row['path'];b=(ENGLISH/'payload'/name).read_bytes()
        assert sha(b)==row['sha256'] and len(b)==row['bytes']
        development[name]=b
    assert len(before)==1918 and set(development)==set(before)
    original=development[SYSTEM+'UpgradeManager.exe']
    candidate,recipe=patch(original)
    pe,checked=pefile.PE(data=original),pefile.PE(data=candidate)
    for a,b in zip(pe.sections,checked.sections):
        assert a.get_file_offset()==b.get_file_offset()
        if a.Name.rstrip(b'\0')!=b'.text':assert a.get_data()==b.get_data()
        assert (a.VirtualAddress,a.Misc_VirtualSize,a.PointerToRawData,a.SizeOfRawData,a.Characteristics)==(b.VirtualAddress,b.Misc_VirtualSize,b.PointerToRawData,b.SizeOfRawData,b.Characteristics)
    # Independently restore every reviewed text edit and the changed header;
    # every original file byte must then match the pinned English input.
    restored=bytearray(candidate[:len(original)])
    for edit in recipe['edits']:
        offset=pe.get_offset_from_rva(int(edit['va'],16)-pe.OPTIONAL_HEADER.ImageBase)
        assert int.from_bytes(candidate[offset:offset+4],'little')==int(edit['after'],16)
        struct.pack_into('<I',restored,offset,int(edit['before'],16))
    progress=next(r for r in recipe['routines'] if 'before_hex' in r)
    offset=pe.get_offset_from_rva(int(progress['start'],16)-pe.OPTIONAL_HEADER.ImageBase)
    restored[offset:offset+len(bytes.fromhex(progress['before_hex']))]=bytes.fromhex(progress['before_hex'])
    restored[:pe.OPTIONAL_HEADER.SizeOfHeaders]=original[:pe.OPTIONAL_HEADER.SizeOfHeaders]
    assert bytes(restored)==original,'Unreviewed original body-byte change'
    development[SYSTEM+'UpgradeManager.exe']=candidate
    for name,raw in development.items():
        p=out/'payload'/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(raw)
    after={p.relative_to(out/'payload').as_posix():p.read_bytes() for p in (out/'payload').rglob('*') if p.is_file()}
    assert set(after)==set(before) and after==development
    readback=after[SYSTEM+'UpgradeManager.exe']
    copy_checks=verify_copy(readback)
    originals={name:before[SYSTEM+name] for name in LABELS}
    changes={name:after[SYSTEM+name] for name in LABELS}
    language_checks=verify_language(originals,changes)
    modified=[name for name in before if before[name]!=after[name]]
    assert set(modified)=={SYSTEM+name for name in LABELS}
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='Internal full-payload development staging, not a release or installable update',
                previous_release='7.0.6.MAX03',previous_lgu_sha256=previous['verification']['lgu_sha256'],
                previous_members=1918,output_members=len(after),missing_members=[],added_members=[],
                unchanged_members=len(after)-len(modified),modified_members=modified,
                release_built=False,version_bumped=False,native_executed=False,hardware_tested=False,
                installation_ready=False,installer_recipe=recipe,
                copy_checks=copy_checks,language_checks=language_checks,
                members=[dict(path=name,bytes=len(after[name]),previous_sha256=sha(before[name]),sha256=sha(after[name]),changed=name in modified) for name in sorted(after)])
    (out/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    (out/'README.md').write_text(
        '# Installer copy-safety development staging\n\n'
        'All 1,918 previous 7.0.6.MAX03 members are retained. Existing Bluetooth/audio/navigation changes and English UI development work are included. Only four files differ from the published release.\n\n'
        'The updater now checks copies and reads their bytes back, keeps staging and settings backups until completion, commits the version file last, and shows a persistent English error screen without external images. Missing staging receipts, unavailable volume directories and ambiguous settings-scan checkpoints pause installation.\n\n'
        'This is an internal prototype, not an LGU or release. Do not install/copy these files onto a unit. Two additional PE sections and expanded function-unwind metadata require native CE-loader testing. Byte-interpreter/API fixtures are not hardware tests. No version has been bumped or release published.\n\n'
        'This does not establish a fix for GitHub issues 7 or 15. Original OS/MCU flash behavior remains. Readback is not proof of NAND durability or rollback. Ambiguous settings checkpoints need recovery assessment; they do not automatically resume. The old destructive navigation-predelete is skipped, so obsolete files may remain. Existing formatter return semantics still require further repair.\n',encoding='utf-8')
    assert sha((PREVIOUS/'upgrade.lgu').read_bytes())==result['previous_lgu_sha256']
    print(json.dumps(dict(previous_members=1918,output_members=len(after),unchanged_members=result['unchanged_members'],modified_members=modified,copy_cases=copy_checks['cases'],english_checks=language_checks,release_built=False),indent=2))


if __name__=='__main__':main()
