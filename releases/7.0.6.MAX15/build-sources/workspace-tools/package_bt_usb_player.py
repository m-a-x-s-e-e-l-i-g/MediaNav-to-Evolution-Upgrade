"""Full MAX13 successor; independent LGU decoder plus PC extractor readback."""
from datetime import datetime, timezone
from types import FunctionType
from pathlib import Path
import json
import shutil
import zipfile
import build_bt_usb_player as p
import build_review_update as container
from build_max05_candidate import tree
import pefile

REVISION='7.0.6.MAX13'
STAGE=p.REPO/'build/maxmade-7.0.6.MAX13-player-local-01'
DELIVERY=p.ROOT/'build/maxmade-7.0.6.MAX13'
ARCHIVE=p.ROOT/'build/maxmade-7.0.6.MAX13.zip'
BASE_LGU_SHA='d755fa908a29851da12dacaa5a79fc5a387bea01d46bb6a9772af6d024abac0e'


def write(path,value):path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')


def build():
    for path in (STAGE,DELIVERY,ARCHIVE):assert not path.exists(),str(path)
    previous={r['path']:r['after'] for r in json.loads((p.BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918
    assert p.sha((p.BASELINE/'upgrade.lgu').read_bytes())==BASE_LGU_SHA
    tree(p.BASELINE/'payload',previous);tree(p.BASELINE/'roundtrip',previous)
    report=json.loads((p.OUT/'manifest.json').read_bytes())
    proof=json.loads((p.OUT/'verification.json').read_bytes())
    assert len(proof['geometry'])==4 and len(proof['title_cases'])==3 and len(proof['artwork'])==12 and len(proof['rebases'])==3
    assert not proof['hardware_tested'] and not proof['native_executed']
    expected={r['path']:dict(bytes=r['bytes'],sha256=r['sha256']) for r in report['members']}
    assert set(expected)==set(previous)
    assert expected[p.APP.as_posix()]['sha256']==proof['app_sha256']
    tree(p.OUT/'payload',expected)
    shutil.copytree(p.OUT/'payload',STAGE/'payload')
    (STAGE/'payload'/container.VERSION_PATH).write_bytes(REVISION.encode('ascii'))
    expected[container.VERSION_PATH]=dict(bytes=len(REVISION),sha256=p.sha(REVISION.encode('ascii')))
    changed=[name for name in sorted(expected) if expected[name]!=previous[name]]
    assert changed==sorted([p.APP.as_posix(),container.VERSION_PATH])
    tree(STAGE/'payload',expected)
    writer,extractor=(p.ROOT/'tools/vendor/lgu-favremod'/name for name in ('dir2lgu.exe','lgu2dir.exe'))
    for tool,pin in ((writer,container.WRITER_HASH),(extractor,container.EXTRACTOR_HASH)):
        assert p.sha(tool.read_bytes())==pin and pefile.PE(str(tool)).FILE_HEADER.Machine==0x14c
    print('Complete MAX12 payload retained; packing MAX13.',flush=True)
    writer_run=container.run_pc_tool(writer,['-p','m1',REVISION,STAGE/'payload',STAGE/'upgrade.lgu'],STAGE/'dir2lgu.log')
    key=bytes.fromhex(json.loads((p.REPO/'src/container/lgu0.json').read_bytes())['xor_hex'])
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=verify(STAGE/'upgrade.lgu',expected,REVISION)
    print('Independent LGU decode passed; checking separate extractor.',flush=True)
    extractor_run=container.run_pc_tool(extractor,[STAGE/'upgrade.lgu',STAGE/'roundtrip'],STAGE/'lgu2dir.log')
    tree(STAGE/'roundtrip',expected);tree(STAGE/'payload',expected);tree(p.BASELINE/'payload',previous)
    assert p.sha((p.BASELINE/'upgrade.lgu').read_bytes())==BASE_LGU_SHA
    manifest=dict(revision=REVISION,kind='FULL LOCAL BLUETOOTH PLAYER CAR TEST CANDIDATE',
        generated_utc=datetime.now(timezone.utc).isoformat(),baseline_revision='7.0.6.MAX12',
        baseline_lgu_sha256=BASE_LGU_SHA,output_members=1918,unchanged_from_MAX12=1916,
        changed_members=changed,missing_members=[],added_members=[],baseline_unchanged=True,
        Blue_MgrUSB_navigation_resources_and_Settings_byte_exact_MAX12=True,
        artwork_status='Acquisition correction inherited from MAX11; real cover receipt still unconfirmed',
        hardware_tested=False,native_executed=False,published=False,flashed=False,
        verification=result,player_verification=proof,writer=writer_run,extractor=extractor_run,
        source_pins={str(path.relative_to(p.ROOT)):p.sha(path.read_bytes()) for path in
                     (p.ROOT/'tools/build_bt_usb_player.py',p.ROOT/'tools/verify_bt_usb_player.py',Path(__file__))})
    write(STAGE/'build-manifest.json',manifest)
    write(STAGE/'member-plan.json',dict(members=[dict(path=name,before=previous[name],after=expected[name]) for name in sorted(expected)],
        member_count=1918,retained_members=1916,changed_members=changed,missing_members=[],added_members=[]))
    DELIVERY.mkdir()
    for name in ('upgrade.lgu','build-manifest.json','member-plan.json'):shutil.copyfile(STAGE/name,DELIVERY/name)
    for name in ('verification.json','recipe.json'):shutil.copyfile(p.OUT/name,DELIVERY/name)
    shutil.copytree(p.OUT/'previews',DELIVERY/'previews')
    (DELIVERY/'README.md').write_text('''# MAXmade 7.0.6.MAX13 — unified player candidate

Complete successor to local MAX12: all 1,918 payload files retained. Only
AppMain.exe and Version_Info.txt change; the other 1,916 files are exact MAX12.
Includes MAX12 Settings and MAX11 artwork handshake correction.

Bluetooth now uses the USB player's 278 x 278 artwork position, title/artist
positions and fonts, and the same previous/play/pause/next image resources.
Bluetooth source/menu labels, commands and widget identities remain native.
USB and iPod stay unchanged. Without a received cover, Bluetooth shows the same
native no-album music-note resource as USB. Received covers, stale-cover cleanup
and refresh copies all use the larger slot. Popup content still draws last.
No USB filesystem, seeking or time display is wired to Bluetooth: those require
separate verified Bluetooth position/seek support. No map update is included.

Four UI-profile constructor checks, three initial/skipped/unicode metadata
cases, twelve artwork/popup/GDI cleanup cases and three relocations passed.
Phone/CE/GDI calls remain fixtures; previews use host fonts/sample metadata
and the artwork example is a fixture, not a phone download or car screenshot.
Offline checks do not prove real cover receipt. Album art remains issue #48:
https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/48

The LGU was independently decoded and its 1,918 files matched a separate PC
extractor readback. MAX13 is a local test candidate, not a public release.
Use the existing unit-specific MAXmade installation procedure and confirm
7.0.6.MAX13. Check the larger layout, play/pause icons, previous/next buttons,
titles and artists after track skips, source changes, reconnects and phone
popups; confirm audio remains smooth. Verify real covers belong to the current
track. The Nav reference theme is not included pending installed archive checks.
''',encoding='utf-8')
    (DELIVERY/'SHA256SUMS.txt').write_text(''.join(p.sha(path.read_bytes())+'  '+path.relative_to(DELIVERY).as_posix()+'\n'
        for path in sorted(DELIVERY.rglob('*')) if path.is_file() and path.name!='SHA256SUMS.txt'),encoding='ascii')
    with zipfile.ZipFile(ARCHIVE,'w',compression=zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(DELIVERY.rglob('*')):
            if path.is_file():archive.write(path,REVISION+'/'+path.relative_to(DELIVERY).as_posix())
    with zipfile.ZipFile(ARCHIVE) as archive:
        assert archive.testzip() is None
        assert p.sha(archive.read(REVISION+'/upgrade.lgu'))==result['lgu_sha256']
    return dict(lgu=str(DELIVERY/'upgrade.lgu'),zip=str(ARCHIVE),sha256=result['lgu_sha256'],members=1918,retained=1916)


if __name__=='__main__':print(json.dumps(build(),indent=2))
