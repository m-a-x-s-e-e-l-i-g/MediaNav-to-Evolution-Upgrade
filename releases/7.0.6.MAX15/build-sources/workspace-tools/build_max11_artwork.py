"""Build a complete MAX11 successor with a capture-backed artwork gate correction."""
from datetime import datetime, timezone
from pathlib import Path
from types import FunctionType
import json
import shutil
import zipfile
import patch_max11_artwork as p
import build_review_update as container
from build_max05_candidate import tree
from build_max08_successor import inspect
import pefile

REVISION='7.0.6.MAX11'
BASELINE=p.REPO/'build/maxmade-7.0.6.MAX10-local-01'
STAGE=p.REPO/'build/maxmade-7.0.6.MAX11-local-01'
DELIVERY=p.ROOT/'build/maxmade-7.0.6.MAX11'
ARCHIVE=p.ROOT/'build/maxmade-7.0.6.MAX11.zip'
BASE_LGU_SHA='87f61836ceb3ddf733ecb0d2e9fc4a2ea8e7a0ab5a3c07a3b15b0f59c601243f'

def write(path,value): path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')

def build():
    for path in (STAGE,DELIVERY,ARCHIVE): assert not path.exists(),str(path)
    prior_lgu=(BASELINE/'upgrade.lgu').read_bytes();assert p.sha(prior_lgu)==BASE_LGU_SHA
    previous={r['path']:r['after'] for r in json.loads((BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918
    tree(BASELINE/'roundtrip',previous);tree(BASELINE/'payload',previous)
    recipes=json.loads((p.OUT/'recipe.json').read_bytes())
    evidence=json.loads((p.OUT/'verification.json').read_bytes())
    assert len(evidence['artwork'])==11 and len(evidence['native_text'])==2
    assert evidence['audio_title_UI_bytes_equal_MAX10'] and not evidence['hardware_tested']
    assert evidence['trace_evidence']['obex_version']==0x10
    assert evidence['trace_evidence']['image_connect_successes']==12
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
                kind='FULL MAX10 SUCCESSOR - LOCAL CAR TEST CANDIDATE',baseline_revision='7.0.6.MAX10',
                baseline_lgu_sha256=BASE_LGU_SHA,output_members=1918,unchanged_from_MAX10=1916,
                changed_members=changed,missing_members=[],added_members=[],baseline_unchanged=True,
                audio_title_UI_bytes_equal_MAX10=True,appmain_byte_identical_MAX10=True,
                physical_feedback=dict(MAX08_audio_and_titles='SOLVED by user',MAX10_artwork='placeholder only - failed',
                                       phone='Nothing Phone (1), Android 15, Spotify; AVRCP developer setting 1.6',
                                       phone_captured_CONNECT='OBEX 1.0 success, connection ID 1, packet size 1024',
                                       MAX11_artwork='not tested'),
                native_text_cases=2,artwork_cases=11,inspections=inspections,verification=verification,
                pc_extractor_matches=1918,hardware_tested=False,flashed=False,published=False,
                native_executed=False,phone_cover_server_advertisement_verified=True,
                trace_evidence=evidence['trace_evidence'],
                source_pins={str(path.relative_to(p.ROOT)):p.sha(path.read_bytes()) for path in
                             (p.ROOT/'tools/patch_max11_artwork.py',p.ROOT/'tools/verify_max11_artwork.py',Path(__file__))},
                evidence_sha256=p.sha((p.OUT/'verification.json').read_bytes()),
                writer=writer_run,extractor=extractor_run,limits=evidence['limits'])
    write(STAGE/'build-manifest.json',report)
    write(STAGE/'member-plan.json',dict(members=members,member_count=1918,retained_members=1916,
                                      changed_members=changed,missing_members=[],added_members=[]))
    write(STAGE/'native-recipes.json',recipes)
    DELIVERY.mkdir(parents=True)
    for name in ('upgrade.lgu','build-manifest.json','member-plan.json','native-recipes.json'):
        shutil.copyfile(STAGE/name,DELIVERY/name)
    for name in ('verification.json','cover-captured_1.0-fixture.png','cover-existing_1.5-fixture.png'):
        shutil.copyfile(p.OUT/name,DELIVERY/name)
    (DELIVERY/'README.md').write_text("# MAXmade 7.0.6.MAX11 — artwork car test candidate\n\nComplete successor to published MAX10: all 1,918 payload files are included;\n1,916 are byte-for-byte unchanged. Only Blue.exe and Version_Info.txt change.\nAudio/title/UI code and the whole AppMain.exe are preserved exactly.\nMAX10 is published and user-tested as the best version so far; its Bluetooth\nalbum art still fails after track skips and reconnect. Issue 48 remains open:\nhttps://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/48\n\nThe new full phone trace shows the image endpoint now opening. The phone returns\n12 successful OBEX CONNECT replies, with version 1.0, connection ID 1, size 1024\nand the expected cover-art WHO UUID. MAX10's installed response parser requires\nat least OBEX 1.5 and rejects that successful Android reply. No attribute-8 cover\nrequest or image GET follows in the trace.\n\nMAX11 accepts OBEX reply version 1.0 or later, retaining success code, bounded\nheader length, flags, WHO identity, unique connection ID, size and ownership\nchecks. Only one parser instruction plus PE checksum changes in Blue.exe.\nThe MAX10 SDP/discovery correction and all preceding improvements remain.\n\nOffline comparison replays the exact captured CONNECT reply: MAX10 fails;\nMAX11 proceeds to the cover-handle request. Eleven artwork cases exercise both\nthat response and the previous 1.5 response, and refusal of old version, error,\nflags, invalid size, wrong WHO, missing/duplicate ID and mismatched length.\nTwo native title/GUI reader cases pass. Actual captured SDP and CONNECT bytes\nare used; subsequent handle/image responses, CE and GDI remain fixtures.\nFixture paintings are not proof of actual Nothing/Spotify image delivery.\n\nUse the existing MediaNav update procedure with upgrade.lgu at the USB root.\nConfirm 7.0.6.MAX11 after installation. Reconnect Bluetooth and play a Spotify\ntrack with visible artwork on the phone. Check the left square, then skip tracks\nand test reconnect/source changes. Confirm each cover belongs to the current\ntrack and audio/titles remain good. If still blank, another full HCI capture can\nshow the next acquisition stage. No phone setting change is requested.\n\nLGU independently decoded and compared with separate PC extractor readback;\nall 1,918 files matched. Raw phone trace/song metadata are not bundled.\nMAX11 is a local test candidate, not a new public release. Album art stays OPEN\nuntil physically verified across track changes and reconnect.\n",encoding='utf-8')
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
