"""Full MAX08 from exact complete MAX07, independent LGU decode/readback."""
from datetime import datetime,timezone
import json
import shutil
import struct
from types import FunctionType
import zipfile

import patch_max08_successor as p
import pefile
import build_review_update as container
from build_max05_candidate import tree

REVISION='7.0.6.MAX08'
BASELINE=p.REPO/'build/maxmade-7.0.6.MAX07-local-01'
STAGE=p.REPO/'build/maxmade-7.0.6.MAX08-local-01'
DELIVERY=p.ROOT/'build/maxmade-7.0.6.MAX08'
ARCHIVE=p.ROOT/'build/maxmade-7.0.6.MAX08.zip'
BASE_LGU_SHA='167c4c3328ee77a1fc30adaf400b04b6dc114a6cd460af8e02c6fb2445397451'


def write(path,value):path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')


def inspect(name,raw,candidate,recipe):
    assert recipe['input_sha256']==p.sha(raw) and recipe['sha256']==p.sha(candidate)
    old,new=pefile.PE(data=raw),pefile.PE(data=candidate)
    imports=lambda q:[(d.dll,i.name,i.ordinal,i.address) for d in q.DIRECTORY_ENTRY_IMPORT for i in d.imports]
    assert imports(old)==imports(new)
    assert old.OPTIONAL_HEADER.AddressOfEntryPoint==new.OPTIONAL_HEADER.AddressOfEntryPoint
    assert new.OPTIONAL_HEADER.CheckSum==new.generate_checksum()
    assert new.get_overlay_data_start_offset() is None
    assert not any(s.Characteristics&0x20000000 and s.Characteristics&0x80000000 for s in new.sections)
    def rows(q):
        d=q.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        return list(struct.iter_unpack('<5I',q.get_data(d.VirtualAddress,d.Size)))
    original,newrows=rows(old),rows(new)
    assert [r[0] for r in original]==[r[0] for r in newrows]
    assert all(a[1]<=b[0] for a,b in zip(newrows,newrows[1:]))
    if name=='Blue.exe':
        allowed={i for e in recipe['edits'] for i in range(e['offset'],e['offset']+len(bytes.fromhex(e['before_hex'])))}
        allowed.update(range(old.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),old.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')+4))
        assert len(raw)==len(candidate) and all(a==b or i in allowed for i,(a,b) in enumerate(zip(raw,candidate)))
        assert original==newrows
    else:
        changed={0x235000,0x340000}
        assert all(a==b for a,b in zip(original,newrows) if a[0] not in changed)
        # Every original section retains all bytes except the reviewed draw
        # helper. The last RX section rebuilds its exception/relocation tables.
        for s in old.sections[:-1]:
            a,b=s.get_data(),new.get_data(s.VirtualAddress,s.SizeOfRawData)
            for i,(x,y) in enumerate(zip(a,b)):
                if x!=y: assert 0x235000<=p.BASE+s.VirtualAddress+i<0x236000
        assert old.sections[-1].get_data()[:0x1000]==new.sections[-1].get_data()[:0x1000]
    return dict(imports_equal=True,entrypoint_equal=True,permissions_valid=True,
                checksum_valid=True,original_function_starts_preserved=True)


def build():
    for path in (STAGE,DELIVERY,ARCHIVE):assert not path.exists(),str(path)
    original_lgu=(BASELINE/'upgrade.lgu').read_bytes();assert p.sha(original_lgu)==BASE_LGU_SHA
    previous={r['path']:r['after'] for r in json.loads((BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918;tree(BASELINE/'roundtrip',previous);tree(BASELINE/'payload',previous)
    recipe=json.loads((p.OUT/'recipe.json').read_bytes())
    evidence=json.loads((p.OUT/'verification.json').read_bytes())
    replacements={container.VERSION_PATH:REVISION.encode('ascii')}
    inspections={}
    for name,fn in (('Blue.exe',p.blue),('AppMain.exe',p.app)):
        raw=(BASELINE/'roundtrip'/p.SYSTEM/name).read_bytes()
        candidate=(p.OUT/name).read_bytes();expected,_=fn(raw)
        assert candidate==expected
        assert evidence['blue_sha256' if name=='Blue.exe' else 'app_sha256']==p.sha(candidate)
        inspections[name]=inspect(name,raw,candidate,recipe[name])
        replacements[(p.SYSTEM/name).as_posix()]=candidate
    assert len(evidence['native_text'])>=7 and len(evidence['artwork'])>=6 and evidence['rebases']==4
    assert evidence['hardware_tested'] is False
    members=[dict(path=name,before=old,after=dict(bytes=len(replacements[name]),sha256=p.sha(replacements[name])) if name in replacements else old)
             for name,old in sorted(previous.items())]
    expected={r['path']:r['after'] for r in members}
    changed=[r['path'] for r in members if r['before']!=r['after']]
    assert changed==sorted(replacements)
    STAGE.mkdir(parents=True)
    for name in expected:
        dest=STAGE/'payload'/name;dest.parent.mkdir(parents=True,exist_ok=True)
        dest.write_bytes(replacements[name] if name in replacements else (BASELINE/'roundtrip'/name).read_bytes())
    tree(STAGE/'payload',expected)
    writer,extractor=(p.ROOT/'tools/vendor/lgu-favremod'/n for n in ('dir2lgu.exe','lgu2dir.exe'))
    for tool,pin in ((writer,container.WRITER_HASH),(extractor,container.EXTRACTOR_HASH)):
        assert p.sha(tool.read_bytes())==pin and pefile.PE(str(tool)).FILE_HEADER.Machine==0x14c
    writer_run=container.run_pc_tool(writer,['-p','m1',REVISION,STAGE/'payload',STAGE/'upgrade.lgu'],STAGE/'dir2lgu.log')
    key=bytes.fromhex(json.loads((p.REPO/'src/container/lgu0.json').read_bytes())['xor_hex'])
    independent=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    verification=independent(STAGE/'upgrade.lgu',expected,REVISION)
    extractor_run=container.run_pc_tool(extractor,[STAGE/'upgrade.lgu',STAGE/'roundtrip'],STAGE/'lgu2dir.log')
    tree(STAGE/'roundtrip',expected);tree(STAGE/'payload',expected);tree(BASELINE/'roundtrip',previous)
    assert (BASELINE/'upgrade.lgu').read_bytes()==original_lgu
    report=dict(revision=REVISION,generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='FULL MAX07 SUCCESSOR - LOCAL CAR TEST CANDIDATE',baseline_revision='7.0.6.MAX07',
                baseline_lgu_sha256=BASE_LGU_SHA,output_members=1918,unchanged_from_MAX07=1915,
                changed_members=changed,missing_members=[],added_members=[],baseline_unchanged=True,
                max07_audio_and_button_fix_retained=True,os_boot_mcu_navigation_and_settings_equal_MAX07=True,
                native_text_cases=len(evidence['native_text']),artwork_cases=len(evidence['artwork']),
                rebases=4,inspections=inspections,verification=verification,
                pc_extractor_matches=1918,hardware_tested=False,flashed=False,published=False,
                native_executed=False,phone_cover_support_verified=False,
                experimental_text_receiver_and_poll_unbound=True,
                source_pins={str(path.relative_to(p.ROOT)):p.sha(path.read_bytes()) for path in
                             (p.ROOT/'tools/patch_max08_successor.py',p.ROOT/'tools/verify_max08_successor.py',__import__('pathlib').Path(__file__))},
                evidence_sha256=p.sha((p.OUT/'verification.json').read_bytes()),
                writer=writer_run,extractor=extractor_run,limits=evidence['limits'])
    write(STAGE/'build-manifest.json',report)
    write(STAGE/'member-plan.json',dict(members=members,member_count=1918,retained_members=1915,
                                      changed_members=changed,missing_members=[],added_members=[]))
    write(STAGE/'native-recipes.json',recipe)
    DELIVERY.mkdir(parents=True)
    for name in ('upgrade.lgu','build-manifest.json','member-plan.json','native-recipes.json'):
        shutil.copyfile(STAGE/name,DELIVERY/name)
    for name in ('verification.json','player-placeholder.png','player-fixture-cover.png'):
        shutil.copyfile(p.OUT/name,DELIVERY/name)
    (DELIVERY/'README.md').write_text('''# MAXmade 7.0.6.MAX08 — car test candidate

Complete successor to MAX07: all 1,918 payload files included, with 1,915
byte-for-byte unchanged. Only Blue.exe, AppMain.exe and Version_Info.txt change.
MAX07's working button text and PCM/audio changes are retained exactly.

Bluetooth titles now use the native metadata route from the last mostly working
7.0.5MD/MAX05 path. The experimental strict receiver and retry/poll route are
unbound. Native failure/status protection remains, and empty album/artist fields
now advance the final handler correctly instead of losing an already read title.
This restores native compatibility; the exact phone-side regression is not yet
proven and the previous rare missing-title case may remain.

Artwork drawing no longer mistakes an allocated but hidden popup for a visible
popup. The player draws its background, placeholder/cover, then visible popup
controls. The “Album art” square should now appear even without a cover download.
Actual Android cover delivery is still unverified. The PNGs are fixture previews,
not device screenshots or proof that Spotify artwork was received.

Use your existing MediaNav update procedure with upgrade.lgu at the USB root.
Confirm version 7.0.6.MAX08 after installing, then check:

1. BT Player: the Album art square on the left and current song title.
2. Several track skips, another music app, pause/resume and Bluetooth reconnect.
3. Longer Bluetooth playback: check that audio remains smooth.
4. Radio presets/options and BT options: selected text remains visible.
5. An actual popup: controls remain above the artwork; dismissing it restores art.

Offline native-instruction and relocation checks passed. The full LGU was
independently decoded and all 1,918 files matched a separate extractor readback.
Physical installation, title recovery and phone artwork still need your car test.
Boot/logo customization is outside this regression build; boot files are unchanged.
''',encoding='utf-8')
    (DELIVERY/'SHA256SUMS.txt').write_text(''.join(p.sha(f.read_bytes())+'  '+f.name+'\n' for f in sorted(DELIVERY.iterdir()) if f.is_file()),encoding='ascii')
    with zipfile.ZipFile(ARCHIVE,'w',compression=zipfile.ZIP_DEFLATED) as z:
        for path in sorted(DELIVERY.iterdir()):z.write(path,REVISION+'/'+path.name)
    with zipfile.ZipFile(ARCHIVE) as z:
        assert z.testzip() is None
        assert p.sha(z.read(REVISION+'/upgrade.lgu'))==verification['lgu_sha256']
    return dict(lgu=str(DELIVERY/'upgrade.lgu'),zip=str(ARCHIVE),sha256=verification['lgu_sha256'],
                members=1918,unchanged=1915,hardware_tested=False)


if __name__=='__main__':print(json.dumps(build(),indent=2))
