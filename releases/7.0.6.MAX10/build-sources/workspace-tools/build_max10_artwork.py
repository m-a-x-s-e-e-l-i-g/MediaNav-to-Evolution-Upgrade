"""Build a complete MAX10 successor with a capture-backed artwork gate correction."""
from datetime import datetime, timezone
from pathlib import Path
from types import FunctionType
import json
import shutil
import zipfile
import patch_max10_artwork as p
import build_review_update as container
from build_max05_candidate import tree
from build_max08_successor import inspect
import pefile

REVISION='7.0.6.MAX10'
BASELINE=p.REPO/'build/maxmade-7.0.6.MAX09-local-01'
STAGE=p.REPO/'build/maxmade-7.0.6.MAX10-local-01'
DELIVERY=p.ROOT/'build/maxmade-7.0.6.MAX10'
ARCHIVE=p.ROOT/'build/maxmade-7.0.6.MAX10.zip'
BASE_LGU_SHA='a1a12fc87864a0612ef53c512795001fe9f0feac6ba94ed633124a0f3aa04476'

def write(path,value): path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')

def build():
    for path in (STAGE,DELIVERY,ARCHIVE): assert not path.exists(),str(path)
    prior_lgu=(BASELINE/'upgrade.lgu').read_bytes();assert p.sha(prior_lgu)==BASE_LGU_SHA
    previous={r['path']:r['after'] for r in json.loads((BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918
    tree(BASELINE/'roundtrip',previous);tree(BASELINE/'payload',previous)
    recipes=json.loads((p.OUT/'recipe.json').read_bytes())
    evidence=json.loads((p.OUT/'verification.json').read_bytes())
    assert len(evidence['artwork'])==7 and len(evidence['native_text'])==2
    assert evidence['audio_title_UI_bytes_equal_MAX09'] and not evidence['hardware_tested']
    assert evidence['trace_evidence']['version']==0x104 and evidence['trace_evidence']['features']==0x1d1
    assert evidence['trace_evidence']['psm']==0x1001
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
    print('Full payload verified; building LGU.',flush=True)
    writer_run=container.run_pc_tool(writer,['-p','m1',REVISION,STAGE/'payload',STAGE/'upgrade.lgu'],STAGE/'dir2lgu.log')
    key=bytes.fromhex(json.loads((p.REPO/'src/container/lgu0.json').read_bytes())['xor_hex'])
    independent=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    verification=independent(STAGE/'upgrade.lgu',expected,REVISION)
    print('Independent LGU decode passed; checking separate extractor readback.',flush=True)
    extractor_run=container.run_pc_tool(extractor,[STAGE/'upgrade.lgu',STAGE/'roundtrip'],STAGE/'lgu2dir.log')
    tree(STAGE/'roundtrip',expected);tree(STAGE/'payload',expected);tree(BASELINE/'roundtrip',previous)
    assert (BASELINE/'upgrade.lgu').read_bytes()==prior_lgu
    report=dict(revision=REVISION,generated_utc=datetime.now(timezone.utc).isoformat(),
                kind='FULL MAX09 SUCCESSOR - LOCAL CAR TEST CANDIDATE',baseline_revision='7.0.6.MAX09',
                baseline_lgu_sha256=BASE_LGU_SHA,output_members=1918,unchanged_from_MAX09=1916,
                changed_members=changed,missing_members=[],added_members=[],baseline_unchanged=True,
                audio_title_UI_bytes_equal_MAX09=True,appmain_byte_identical_MAX09=True,
                physical_feedback=dict(MAX08_audio_and_titles='SOLVED by user',MAX09_artwork='placeholder only - failed',
                                       phone='Nothing Phone (1), Android 15, Spotify; AVRCP developer setting 1.6',
                                       phone_captured_profile='1.4 with cover feature and OBEX PSM 0x1001',
                                       MAX10_artwork='not tested'),
                native_text_cases=2,artwork_cases=7,inspections=inspections,verification=verification,
                pc_extractor_matches=1918,hardware_tested=False,flashed=False,published=False,
                native_executed=False,phone_cover_server_advertisement_verified=True,
                trace_evidence=evidence['trace_evidence'],
                source_pins={str(path.relative_to(p.ROOT)):p.sha(path.read_bytes()) for path in
                             (p.ROOT/'tools/patch_max10_artwork.py',p.ROOT/'tools/verify_max10_artwork.py',Path(__file__))},
                evidence_sha256=p.sha((p.OUT/'verification.json').read_bytes()),
                writer=writer_run,extractor=extractor_run,limits=evidence['limits'])
    write(STAGE/'build-manifest.json',report)
    write(STAGE/'member-plan.json',dict(members=members,member_count=1918,retained_members=1916,
                                      changed_members=changed,missing_members=[],added_members=[]))
    write(STAGE/'native-recipes.json',recipes)
    DELIVERY.mkdir(parents=True)
    for name in ('upgrade.lgu','build-manifest.json','member-plan.json','native-recipes.json'):
        shutil.copyfile(STAGE/name,DELIVERY/name)
    for name in ('verification.json','cover-0104-00-fixture.png','cover-0104-80-fixture.png','cover-0106-00-fixture.png'):
        shutil.copyfile(p.OUT/name,DELIVERY/name)
    (DELIVERY/'README.md').write_text('''# MAXmade 7.0.6.MAX10 — artwork car test candidate

Complete successor to MAX09: all 1,918 payload files included; 1,916 are
byte-for-byte unchanged. Only Blue.exe and Version_Info.txt change.
MAX09 audio, title and UI code and the whole AppMain.exe are preserved exactly.
The user confirmed MAX08 Bluetooth audio and titles solved. MAX09 artwork still
showed only the placeholder. MAX10 actual cover display has not been car tested.

The supplied full phone HCI capture contains a concrete advertisement mismatch:
Nothing Phone (1), Android 15, Spotify, AVRCP developer setting 1.6, advertises
profile version 1.4 to this MediaNav, alongside the cover feature (0x01d1 includes
bit 0x0100) and an OBEX image endpoint on PSM 0x1001. MAX09 rejects versions below
1.6 before opening that endpoint. The capture contains 13 ordinary metadata
requests/replies, but no attribute-8 cover-handle request or PSM 0x1001 connection.
The reason for the phone advertising 1.4 is not established by this capture.

MAX10 accepts version 1.4 or later only with the existing explicit cover feature
and valid, unambiguous OBEX endpoint checks. Peer identity, current source,
transport policy and image ownership checks remain. One instruction and the PE
checksum change in Blue.exe. No phone setting change is requested.

Offline tests replay the exact captured SDP values through installed discovery
code: MAX09 rejects; MAX10 opens the artwork path. Seven artwork cases cover the
captured advertisement, zero/nonzero native policies, normal 1.6, and refusal of
missing cover capability, older version or absent OBEX endpoint. Two native
title/publication/GUI-reader cases pass for initial and skipped tracks.
Subsequent cover handle, OBEX image responses, CE and GDI remain fixtures.
Fixture PNG previews are not device photos or proof of phone image delivery.

Use the existing MediaNav update procedure with upgrade.lgu at the USB root.
Confirm version 7.0.6.MAX10 after installation. Reconnect Bluetooth, play a track
with visible Spotify artwork on the phone, and check the left square. Skip several
tracks; check covers match the current song. Also test a source change/reconnect
and confirm audio and titles remain good. If still blank, a new full HCI capture
will show whether the image connection, handle request or image transfer fails.

LGU independently decoded and compared with a separate extractor readback:
all 1,918 files matched. Raw phone trace and song metadata are not bundled.
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
