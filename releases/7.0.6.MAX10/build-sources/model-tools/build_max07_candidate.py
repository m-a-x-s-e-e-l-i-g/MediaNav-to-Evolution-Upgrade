"""Build and independently extract a complete MAX07 from exact latest MAX06.

Only reviewed AppMain/Blue and matching version text change. Nothing is flashed,
published or run as firmware. Require current hash-bound verification reports.
"""
from datetime import datetime,timezone
import hashlib
import json
from pathlib import Path
import shutil
import struct
from types import FunctionType
import zipfile
import pefile
import build_review_update as container
from build_max05_candidate import tree
from build_maxmade_update import version_model
import patch_max07_bluetooth as bt

ROOT=Path(__file__).resolve().parents[1]
HOST=ROOT.parents[1]
BASELINE=ROOT/'build/maxmade-7.0.6.MAX06-artwork-text-local-01'
REVISION='7.0.6.MAX07'
BASE_LGU_SHA='b506bbf0f9edd27a755977dd5f1c17ee0ac8b265632e58b4ae5487f0271d6f15'
BLUE='upgrade/Storage Card/System/Blue.exe'
APP='upgrade/Storage Card/System/AppMain.exe'
VERSION=container.VERSION_PATH
BT=ROOT/'build/max07-bluetooth-development-03'
UI=HOST/'build/max07-app-development-03'
ART=ROOT/'build/max07-artwork-verification-01'
OUT=ROOT/'build/maxmade-7.0.6.MAX07-local-01'
DELIVERY=HOST/'build/maxmade-7.0.6.MAX07'


def sha(raw):return hashlib.sha256(raw).hexdigest()
def write(path,value):path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')
def read(path):return json.loads(path.read_bytes())


def preserved_app(original,candidate,recipe):
    assert recipe['input_sha256']==sha(original) and recipe['sha256']==sha(candidate)
    rolled=bytearray(candidate[:len(original)])
    for edit in reversed(recipe['edits']):
        start=edit['offset'];old=bytes.fromhex(edit['before_hex'])
        rolled[start:start+len(old)]=old
    assert bytes(rolled)==original,'MAX06 AppMain rollback mismatch'
    old,new=pefile.PE(data=original),pefile.PE(data=candidate)
    for s in old.sections:
        if s.Name.rstrip(b'\0') in (b'.rsrc',b'.mxartd'):
            assert s.get_data()==new.get_data(s.VirtualAddress,s.SizeOfRawData)
    imports=lambda p:[(d.dll,i.name,i.ordinal,i.address) for d in p.DIRECTORY_ENTRY_IMPORT for i in d.imports]
    assert imports(old)==imports(new)
    def rows(p):
        d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        return list(struct.iter_unpack('<5I',p.get_data(d.VirtualAddress,d.Size)))
    assert set(rows(old))<=set(rows(new))
    assert all(a[1]<=b[0] for a,b in zip(rows(new),rows(new)[1:]))
    assert new.OPTIONAL_HEADER.CheckSum==new.generate_checksum()
    assert new.OPTIONAL_HEADER.AddressOfEntryPoint==old.OPTIONAL_HEADER.AddressOfEntryPoint
    assert new.get_overlay_data_start_offset() is None
    return dict(exact_MAX06_rollback=True,resources_preserved=True,imports_preserved=True,original_functions_preserved=True)


def build():
    for directory in (OUT,DELIVERY):
        if directory.exists():raise FileExistsError('Use fresh complete release output: '+str(directory))
    base_lgu=(BASELINE/'upgrade.lgu').read_bytes()
    assert (len(base_lgu),sha(base_lgu))==(37389607,BASE_LGU_SHA)
    previous={r['path']:r['after'] for r in read(BASELINE/'member-plan.json')['members']}
    assert len(previous)==1918;tree(BASELINE/'payload',previous)
    original_blue=(BASELINE/'payload'/BLUE).read_bytes()
    blue=(BT/'Blue.exe').read_bytes();expected,blue_recipe=bt.patch(original_blue)
    assert blue==expected
    bp=read(BT/'verification.json');assert bp['candidate_sha256']==sha(blue) and not bp['hardware_tested']
    assert bp['audio']['cases']==17 and len(bp['transport'])==5
    assert bp['receiver']['executed_candidate_sha256']==sha(blue)
    app=(UI/'AppMain.exe').read_bytes();app_recipe=read(UI/'recipe.json');up=read(UI/'verification.json')
    assert up['candidate_sha256']==sha(app) and up['label_helpers_lookup_and_hooks_exact']
    assert up['resource_profile_state_painter_cases']==14752 and up['semantic_layout_boundary_cases']==5516
    assert up['artwork_constant_and_pointer_rebases']==4
    old_evidence=HOST/'build/max07-app-development-02/verification.json'
    assert up['retained_behavior_evidence_sha256']==sha(old_evidence.read_bytes())
    app_inspection=preserved_app((BASELINE/'payload'/APP).read_bytes(),app,app_recipe)
    ap=read(ART/'verification.json')
    assert ap['app_sha256']==sha(app) and ap['blue_sha256']==sha(blue) and ap['cases']==8
    for proof in (bp,up,ap):assert not proof['hardware_tested']
    replacements={APP:app,BLUE:blue,VERSION:REVISION.encode('ascii')}
    rows=[dict(path=name,before=old,after=dict(bytes=len(replacements[name]),sha256=sha(replacements[name])) if name in replacements else old)
          for name,old in sorted(previous.items())]
    changed=[r['path'] for r in rows if r['before']!=r['after']]
    assert changed==sorted(replacements)
    expected={r['path']:r['after'] for r in rows}
    OUT.mkdir(parents=True)
    for name in expected:
        dest=OUT/'payload'/name;dest.parent.mkdir(parents=True,exist_ok=True)
        dest.write_bytes(replacements[name] if name in replacements else (BASELINE/'payload'/name).read_bytes())
    tree(OUT/'payload',expected)
    tools=HOST/'tools/vendor/lgu-favremod'
    writer,extractor=(tools/n for n in ('dir2lgu.exe','lgu2dir.exe'))
    for tool,pin in ((writer,container.WRITER_HASH),(extractor,container.EXTRACTOR_HASH)):
        assert sha(tool.read_bytes())==pin and pefile.PE(str(tool)).FILE_HEADER.Machine==0x14c
    runs=[container.run_pc_tool(writer,['-p','m1',REVISION,OUT/'payload',OUT/'upgrade.lgu'],OUT/'dir2lgu.log')]
    key=bytes.fromhex(read(ROOT/'src/container/lgu0.json')['xor_hex']);assert len(key)==1024
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    verification=verify(OUT/'upgrade.lgu',expected,REVISION)
    runs.append(container.run_pc_tool(extractor,[OUT/'upgrade.lgu',OUT/'roundtrip'],OUT/'lgu2dir.log'))
    tree(OUT/'roundtrip',expected);tree(OUT/'payload',expected);tree(BASELINE/'payload',previous)
    assert (BASELINE/'upgrade.lgu').read_bytes()==base_lgu
    recognition=version_model(REVISION)
    recognition.extend(dict(current=v,offered=REVISION,ordinary_update_offered=REVISION>v,native_installation_tested=False)
                       for v in ('7.0.6.MAX04','7.0.6.MAX05','7.0.6.MAX06'))
    assert all(r['ordinary_update_offered'] for r in recognition)
    pins={str(p.relative_to(HOST)):sha(p.read_bytes()) for p in (
        Path(__file__),ROOT/'tools/patch_max07_bluetooth.py',ROOT/'tools/max07_bt_helpers.py',
        ROOT/'tools/verify_max07_bluetooth.py',ROOT/'tools/verify_max07_audio.py',ROOT/'tools/verify_max07_artwork.py',
        HOST/'tools/patch_max07_labels.py',HOST/'tools/max07_artwork_frame.py',HOST/'tools/build_max07_app.py')}
    report=dict(revision=REVISION,generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='FULL MAX06 SUCCESSOR - LOCAL HARDWARE TEST CANDIDATE',baseline_revision='7.0.6.MAX06',
                baseline_lgu_sha256=BASE_LGU_SHA,baseline_download='11 October 2026 00:02 Europe/Amsterdam',
                output_members=1918,unchanged_from_MAX06=1915,changed_members=changed,missing_members=[],added_members=[],
                baseline_unchanged=True,previous_changes_retained=True,app_inspection=app_inspection,
                os_boot_mcu_navigation_and_settings_equal_to_MAX06=True,
                published=False,flashed=False,hardware_tested=False,installation_tested=False,native_executed=False,
                shared_label_checks=20722,bluetooth_checks=bp['cases'],artwork_checks=ap['cases'],
                pcm_block_bytes=4096,initial_restart_blocks=2,adaptive_restart_blocks=[2,4,6,8],burst_ceiling_blocks=22,
                artwork_rectangle=[24,116,128,128],phone_cover_support_verified=False,
                verification=verification,pc_extractor_matches=1918,version_recognition_model=recognition,
                source_pins=pins,evidence_sha256={str(p.relative_to(HOST)):sha(p.read_bytes()) for p in
                    (BT/'verification.json',UI/'verification.json',ART/'verification.json')},
                writer=runs[0],extractor=runs[1],
                limits=['Native instruction and container checks are offline; physical repair is not confirmed',
                        'Phone AVRCP cover server and actual Bluetooth scheduling/audio need unit testing',
                        'Queue saturation beyond 22 blocks still refuses excess PCM rather than overwriting owned buffers'])
    write(OUT/'build-manifest.json',report)
    write(OUT/'member-plan.json',dict(members=rows,member_count=1918,retained_members=1915,changed_members=changed,
                                      missing_members=[],added_members=[]))
    write(OUT/'native-recipes.json',dict(Blue=blue_recipe,AppMain=app_recipe))
    DELIVERY.mkdir(parents=True)
    for name in ('upgrade.lgu','build-manifest.json','member-plan.json','native-recipes.json'):
        shutil.copyfile(OUT/name,DELIVERY/name)
    for name,source in (('bluetooth-verification.json',BT/'verification.json'),('labels-verification.json',UI/'verification.json'),
                        ('artwork-verification.json',ART/'verification.json'),('player-placeholder.png',ART/'player-placeholder.png'),
                        ('player-fixture-cover.png',ART/'player-fixture-cover.png')):
        shutil.copyfile(source,DELIVERY/name)
    readme='''# MAXmade 7.0.6.MAX07 — test build

Complete successor to the MAX06 package downloaded on 11 October at 00:02.
All 1,918 previous payload files are present. Blue, AppMain and the version
text change; 1,915 files remain byte-for-byte identical to MAX06.

## Bluetooth

- Recover missing titles without depending on successful notification registration.
- Refresh titles when notification registration is unavailable, without restarting artwork downloads.
- Absorb larger PCM bursts; increase restart reserve after stream underflow while keeping fast initial startup.
- Honour the native artwork transport security policy, including its zero value.

## Interface

- Shared selected/pressed button text remains readable after late refreshes, including radio presets/options and Bluetooth options.
- The Bluetooth Player shows an “Album art” placeholder to the left of the title. Accepted covers replace it. Cover support on this phone is still unverified.

## Test

Use your existing MediaNav update procedure with upgrade.lgu at the USB root.
Confirm 7.0.6.MAX07 after installation. Test Spotify title changes, longer
Bluetooth playback, pause/resume and reconnect; check radio/BT selected labels
and the artwork area. Compare the stuttering with MAX06 and 7.0.5MD.

Offline instruction checks and complete independent LGU extraction passed.
The four reported issues still need confirmation on your MediaNav. The PNGs
show the native drawing path with fixture controls/fonts and a sample cover;
they are not device screenshots or proof of phone artwork delivery.
'''
    (DELIVERY/'README.md').write_text(readme,encoding='utf-8')
    sums=''.join(sha(p.read_bytes())+'  '+p.name+'\n' for p in sorted(DELIVERY.iterdir()) if p.is_file())
    (DELIVERY/'SHA256SUMS.txt').write_text(sums,encoding='ascii')
    archive=HOST/'build/maxmade-7.0.6.MAX07.zip'
    if archive.exists():raise FileExistsError('Archive already exists')
    with zipfile.ZipFile(archive,'w',compression=zipfile.ZIP_DEFLATED) as z:
        for path in sorted(DELIVERY.iterdir()):z.write(path,REVISION+'/'+path.name)
    with zipfile.ZipFile(archive) as z:
        assert z.testzip() is None
        assert sha(z.read(REVISION+'/upgrade.lgu'))==verification['lgu_sha256']
    assert sha((DELIVERY/'upgrade.lgu').read_bytes())==verification['lgu_sha256']
    return dict(lgu=str(DELIVERY/'upgrade.lgu'),zip=str(archive),lgu_sha256=verification['lgu_sha256'],
                members=1918,unchanged=1915,hardware_tested=False)


if __name__=='__main__':print(json.dumps(build(),indent=2))
