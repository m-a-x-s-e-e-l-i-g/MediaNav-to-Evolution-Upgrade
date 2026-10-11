"""Build the full MAX09 successor from the verified complete MAX08 release."""
from datetime import datetime, timezone
from pathlib import Path
from types import FunctionType
import json
import shutil
import zipfile
import patch_max09_artwork as p
import build_review_update as container
from build_max05_candidate import tree
from build_max08_successor import inspect
import pefile

REVISION='7.0.6.MAX09'
BASELINE=p.REPO/'build/maxmade-7.0.6.MAX08-local-01'
STAGE=p.REPO/'build/maxmade-7.0.6.MAX09-local-01'
DELIVERY=p.ROOT/'build/maxmade-7.0.6.MAX09'
ARCHIVE=p.ROOT/'build/maxmade-7.0.6.MAX09.zip'
BASE_LGU_SHA='fce81897d1f68b6be765c13405685e9baa98d1dc5e21b65dadfe31cda67a101f'

def write(path,value): path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')

def build():
    for path in (STAGE,DELIVERY,ARCHIVE): assert not path.exists(),str(path)
    prior_lgu=(BASELINE/'upgrade.lgu').read_bytes();assert p.sha(prior_lgu)==BASE_LGU_SHA
    previous={r['path']:r['after'] for r in json.loads((BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918
    tree(BASELINE/'roundtrip',previous);tree(BASELINE/'payload',previous)
    recipes=json.loads((p.OUT/'recipe.json').read_bytes())
    evidence=json.loads((p.OUT/'verification.json').read_bytes())
    assert len(evidence['artwork'])==5 and len(evidence['native_text'])==2
    assert evidence['audio_title_UI_bytes_equal_MAX08'] and not evidence['hardware_tested']
    replacements={container.VERSION_PATH:REVISION.encode('ascii')}
    inspections={}
    for name,fn in (('Blue.exe',p.blue),('AppMain.exe',p.app)):
        raw=(p.PREVIOUS/p.SYSTEM/name).read_bytes()
        candidate=(p.OUT/name).read_bytes();assert candidate==fn(raw)[0]
        assert evidence['blue_sha256' if name=='Blue.exe' else 'app_sha256']==p.sha(candidate)
        inspections[name]=inspect(name,raw,candidate,recipes[name])
        if candidate!=raw: replacements[(p.SYSTEM/name).as_posix()]=candidate
    members=[dict(path=name,before=old,after=dict(bytes=len(replacements[name]),sha256=p.sha(replacements[name]))
                  if name in replacements else old) for name,old in sorted(previous.items())]
    expected={r['path']:r['after'] for r in members}
    changed=[r['path'] for r in members if r['before']!=r['after']]
    assert changed==sorted(replacements) and len(changed)==2
    STAGE.mkdir(parents=True)
    for name in expected:
        dest=STAGE/'payload'/name;dest.parent.mkdir(parents=True,exist_ok=True)
        dest.write_bytes(replacements[name] if name in replacements else (p.PREVIOUS/name).read_bytes())
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
    assert (BASELINE/'upgrade.lgu').read_bytes()==prior_lgu
    report=dict(revision=REVISION,generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='FULL MAX08 SUCCESSOR - LOCAL CAR TEST CANDIDATE',baseline_revision='7.0.6.MAX08',
                baseline_lgu_sha256=BASE_LGU_SHA,output_members=1918,unchanged_from_MAX08=1916,
                changed_members=changed,missing_members=[],added_members=[],baseline_unchanged=True,
                audio_title_UI_bytes_equal_MAX08=True,appmain_byte_identical_MAX08=True,
                physical_feedback=dict(MAX08_audio_and_titles='SOLVED by user',MAX08_artwork='placeholder only',
                                       phone='Nothing Phone (1), Android 15, AVRCP 1.6',MAX09_artwork='not tested'),
                native_text_cases=2,artwork_cases=5,inspections=inspections,verification=verification,
                pc_extractor_matches=1918,hardware_tested=False,flashed=False,published=False,
                native_executed=False,phone_cover_server_advertisement_verified=False,
                source_pins={str(path.relative_to(p.ROOT)):p.sha(path.read_bytes()) for path in
                             (p.ROOT/'tools/patch_max09_artwork.py',p.ROOT/'tools/verify_max09_artwork.py',Path(__file__))},
                evidence_sha256=p.sha((p.OUT/'verification.json').read_bytes()),
                writer=writer_run,extractor=extractor_run,limits=evidence['limits'])
    write(STAGE/'build-manifest.json',report)
    write(STAGE/'member-plan.json',dict(members=members,member_count=1918,retained_members=1916,
                                      changed_members=changed,missing_members=[],added_members=[]))
    write(STAGE/'native-recipes.json',recipes)
    DELIVERY.mkdir(parents=True)
    for name in ('upgrade.lgu','build-manifest.json','member-plan.json','native-recipes.json'):
        shutil.copyfile(STAGE/name,DELIVERY/name)
    for name in ('verification.json','cover-policy-00-fixture.png','cover-policy-80-fixture.png'):
        shutil.copyfile(p.OUT/name,DELIVERY/name)
    (DELIVERY/'README.md').write_text('''# MAXmade 7.0.6.MAX09 — artwork car test candidate

Complete successor to MAX08: all 1,918 payload files included; 1,916 are
byte-for-byte unchanged. Only Blue.exe and Version_Info.txt change.
MAX08 audio, titles, buttons and the whole AppMain.exe are preserved exactly.
The user confirmed MAX08 Bluetooth audio and titles solved, but no album cover.
Phone: Nothing Phone (1), Android 15, Spotify, Bluetooth AVRCP already set to 1.6.

Fix: the selected-peer artwork resolver still refused a copied zero transport
policy before reaching OPEN, although OPEN already accepts and passes it through
to the native stack. MAX09 removes that redundant refusal; it does not invent or
replace a security policy. Peer identity, capabilities, source and PSM checks stay.

Offline comparison reproduces MAX08 refusing that selection. MAX09 exercises
discovery capture, native selection, BIP connection, attribute-8 cover handle,
OBEX image transfer, owned publication, JPEG decoder worker and popup-aware
painting for zero and nonzero policies. Unsupported versions/capabilities remain
refused. Native title publication and the GUI reader also pass after track skip.
SDP and Bluetooth/OBEX responses, CE and GDI are fixtures. These PNG previews
are not photos of the device and do not establish Nothing/Spotify interoperability.

Use the existing MediaNav update procedure with upgrade.lgu at the USB root.
Confirm version 7.0.6.MAX09 after installation. Play a track with visible Spotify
artwork on the phone; check for the actual cover in the left square. Skip several
tracks, then test Bluetooth reconnect and a source change. Check that each cover
belongs to the current track and that title/audio behavior remains good.

Your phone is already set to AVRCP 1.6; no version-setting change is requested.
AOSP also enables its cover-art server separately from that setting. The actual
phone server advertisement and policy have not been captured. If the square
stays empty, a phone Bluetooth trace is needed to distinguish missing capability
advertisement, connection rejection, absent handle, or an image/decoder failure.
Reference: https://android.googlesource.com/platform/packages/modules/Bluetooth/+/c55eb6ca1009267198d679835ecbcbdcc4d11621/android/app/src/com/android/bluetooth/avrcp/AvrcpTargetService.java

LGU independently decoded and compared with a separate extractor readback:
all 1,918 files matched. Actual cover display in the car remains unverified.
''',encoding='utf-8')
    (DELIVERY/'SHA256SUMS.txt').write_text(''.join(p.sha(f.read_bytes())+'  '+f.name+'\n'
                                              for f in sorted(DELIVERY.iterdir()) if f.is_file()),encoding='ascii')
    with zipfile.ZipFile(ARCHIVE,'w',compression=zipfile.ZIP_DEFLATED) as z:
        for path in sorted(DELIVERY.iterdir()): z.write(path,REVISION+'/'+path.name)
    with zipfile.ZipFile(ARCHIVE) as z:
        assert z.testzip() is None
        assert p.sha(z.read(REVISION+'/upgrade.lgu'))==verification['lgu_sha256']
    return dict(lgu=str(DELIVERY/'upgrade.lgu'),zip=str(ARCHIVE),sha256=verification['lgu_sha256'],
                members=1918,unchanged=1916,hardware_tested=False)

if __name__=='__main__': print(json.dumps(build(),indent=2))
