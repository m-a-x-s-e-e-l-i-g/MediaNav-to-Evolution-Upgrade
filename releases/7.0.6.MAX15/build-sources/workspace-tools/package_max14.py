"""Pack full MAX14; independently decode and extract all 1918 payload members."""
from datetime import datetime,timezone
from types import FunctionType
from pathlib import Path
import json
import shutil
import zipfile
import build_max14 as p
import build_review_update as container
from build_max05_candidate import tree
import pefile
from audit_max14_image import audit

REVISION='7.0.6.MAX14'
STAGE=p.REPO/'build/maxmade-7.0.6.MAX14-light-player-local-01'
DELIVERY=p.ROOT/'build/maxmade-7.0.6.MAX14'
ARCHIVE=p.ROOT/'build/maxmade-7.0.6.MAX14.zip'
BASE_LGU_SHA='9071547168cb5961f7b35e51600a2644da8bbe1f231cd6ab7101d3401cb5a693'

def write(path,value):path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')

def build():
    for path in (STAGE,DELIVERY,ARCHIVE):assert not path.exists(),str(path)
    previous={r['path']:r['after'] for r in json.loads((p.BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918 and p.sha((p.BASELINE/'upgrade.lgu').read_bytes())==BASE_LGU_SHA
    tree(p.BASELINE/'payload',previous);tree(p.BASELINE/'roundtrip',previous)
    proof=json.loads((p.OUT/'verification.json').read_bytes())
    image_audit=audit()
    assert image_audit['app_sha256']==proof['app_sha256']
    assert len(proof['artwork'])==17 and proof['light_asset_contracts']==361 and proof['previews']==6
    assert len(proof['playback']['installed_binding_cases'])==44 and len(proof['labels']['rebases'])==3
    assert proof['labels']['catalog_profile_state_painter_color_cases']>170000
    assert not proof['hardware_tested'] and not proof['native_executed']
    report=json.loads((p.OUT/'manifest.json').read_bytes())
    expected={r['path']:dict(bytes=r['bytes'],sha256=r['sha256']) for r in report['members']}
    assert set(expected)==set(previous) and expected[p.APP.as_posix()]['sha256']==proof['app_sha256']
    tree(p.OUT/'payload',expected)
    shutil.copytree(p.OUT/'payload',STAGE/'payload')
    (STAGE/'payload'/container.VERSION_PATH).write_bytes(REVISION.encode('ascii'))
    expected[container.VERSION_PATH]=dict(bytes=len(REVISION),sha256=p.sha(REVISION.encode('ascii')))
    changed=[name for name in sorted(expected) if expected[name]!=previous[name]]
    assert len(changed)==363 and set(changed)=={p.APP.as_posix(),container.VERSION_PATH}|{r['path'] for r in json.loads((p.OUT/'light-assets.json').read_bytes())}
    tree(STAGE/'payload',expected)
    writer,extractor=(p.ROOT/'tools/vendor/lgu-favremod'/name for name in ('dir2lgu.exe','lgu2dir.exe'))
    for tool,pin in ((writer,container.WRITER_HASH),(extractor,container.EXTRACTOR_HASH)):
        assert p.sha(tool.read_bytes())==pin and pefile.PE(str(tool)).FILE_HEADER.Machine==0x14c
    print('Packing all 1918 MAX14 members.',flush=True)
    writer_run=container.run_pc_tool(writer,['-p','m1',REVISION,STAGE/'payload',STAGE/'upgrade.lgu'],STAGE/'dir2lgu.log')
    key=bytes.fromhex(json.loads((p.REPO/'src/container/lgu0.json').read_bytes())['xor_hex'])
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=verify(STAGE/'upgrade.lgu',expected,REVISION)
    print('Independent LGU decoder passed. Checking separate extractor.',flush=True)
    extractor_run=container.run_pc_tool(extractor,[STAGE/'upgrade.lgu',STAGE/'roundtrip'],STAGE/'lgu2dir.log')
    tree(STAGE/'roundtrip',expected);tree(STAGE/'payload',expected);tree(p.BASELINE/'payload',previous)
    assert p.sha((p.BASELINE/'upgrade.lgu').read_bytes())==BASE_LGU_SHA
    unchanged=[n for n in expected if expected[n]==previous[n]]
    assert len(unchanged)==1555
    manifest=dict(revision=REVISION,kind='FULL LOCAL LIGHT THEME AND BLUETOOTH PLAYER TEST CANDIDATE',
        generated_utc=datetime.now(timezone.utc).isoformat(),baseline_revision='7.0.6.MAX13',baseline_lgu_sha256=BASE_LGU_SHA,
        output_members=1918,unchanged_from_MAX13=1555,changed_members=changed,missing_members=[],added_members=[],baseline_unchanged=True,
        Blue_MgrUSB_dark_resources_and_navigation_byte_exact_MAX13=True,
        artwork_status='MAX13 car failure confirmed. Received covers validated. MAX14 adds bounded worker-start recovery and temporary decoder-stage feedback; real cover display remains unresolved until car test.',
        hardware_tested=False,native_executed=False,published=False,flashed=False,
        verification=result,player_verification=proof,image_audit=image_audit,writer=writer_run,extractor=extractor_run,
        source_pins={str(path.relative_to(p.ROOT)):p.sha(path.read_bytes()) for path in
                     (p.ROOT/'tools/build_max14.py',p.ROOT/'tools/verify_max14.py',p.ROOT/'tools/audit_max14_image.py',Path(__file__))})
    write(STAGE/'build-manifest.json',manifest)
    write(STAGE/'member-plan.json',dict(members=[dict(path=n,before=previous[n],after=expected[n]) for n in sorted(expected)],
                                      member_count=1918,retained_members=1555,changed_members=changed,missing_members=[],added_members=[]))
    DELIVERY.mkdir()
    for name in ('upgrade.lgu','build-manifest.json','member-plan.json'):shutil.copyfile(STAGE/name,DELIVERY/name)
    for name in ('verification.json','recipe.json','light-assets.json','image-audit.json'):shutil.copyfile(p.OUT/name,DELIVERY/name)
    shutil.copytree(p.OUT/'previews',DELIVERY/'previews')
    shutil.copyfile(p.ROOT/'analysis/firmware/max13-artwork-redacted.json',DELIVERY/'phone-capture-findings.json')
    (DELIVERY/'README.md').write_text('''# MAXmade 7.0.6.MAX14 — complete local car-test candidate

Complete MAX13 successor. All 1,918 payload paths retained: 1,555 files exact
MAX13; AppMain, Version_Info and 361 light-theme BMPs change. Dark resources,
Blue.exe, MgrUSB, navigation, maps and the prior audio/title fixes are retained.
No navigation skin archive or new maps are installed.

Bluetooth now follows native playing/paused notifications: pause while playing,
play while paused/stopped. A pointer-free window message updates the native
Bluetooth button on the GUI thread. USB/iPod commands and constructors remain.

The light theme stays light. Home, Settings, Radio, Phone and Media use matching
redesigned surfaces and function accents, black selected faces, white selected
text and dark normal labels. Native BMP formats, transparency masks, geometry,
state banks and touch positions remain. There are 360 indexed BMPs and one
native 24-bit light radio arrow; their individual formats remain intact.

ALBUM ART IS STILL AN OPEN ISSUE. The MAX13 capture contains three complete,
valid 200x200 JPEG covers. Its acquisition/publisher and the MAX14 worker,
decoder and GUI path pass offline replay with explicit CE/COM/GDI fixtures.
That does not prove decoding or display on the physical MediaNav.

MAX14 retries an artwork worker that did not start at most three times per
window, one second apart, retaining nonblocking join/priority/ownership checks.
This is a recovery experiment, not a confirmed explanation of the car failure.
The empty slot now reports a temporary cover stage; successful artwork hides it.
Report the exact message after a track skip and Bluetooth reconnect:

- S0: worker not started; S1: worker live, waiting for a copied cover.
- S2: worker exited with a COM/allocation/wait failure.
- D1: encoded-image checks; D2: imaging factory; D3: JPEG image creation.
- D4: image information/dimensions; D5: drawing DC; D6: bitmap creation.
- D7: bitmap selection; D8: image rendering/cleanup; D9: decoded, awaiting display.

Captions identify the last attempted stage, not a precise HRESULT. An additional
phone snoop cannot reveal which CE/GDI call failed. Private received covers and
raw phone protocol/metadata are excluded from this archive.

Offline checks cover native notifications, all shared label resource/profile/
state combinations, relocated images, three actual captured covers, injected
decoder failures, popup order, stale/disconnected covers and worker lifetimes.
Previews are native-resource reconstructions with sample state and PC fonts,
not screenshots from a car. No firmware executable was run on the PC.

The full LGU is independently decoded and all 1,918 files must match a separate
PC extractor. This is a local test candidate, not a published GitHub release.
Use the established unit-specific installation procedure and confirm MAX14.
Check light/dark selection, settings/radio labels, play/pause, next/previous,
titles, smooth audio, phone popups and the exact cover-stage message.

Album-art issue: https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/48
''',encoding='utf-8')
    (DELIVERY/'SHA256SUMS.txt').write_text(''.join(p.sha(path.read_bytes())+'  '+path.relative_to(DELIVERY).as_posix()+'\n'
        for path in sorted(DELIVERY.rglob('*')) if path.is_file() and path.name!='SHA256SUMS.txt'),encoding='ascii')
    with zipfile.ZipFile(ARCHIVE,'w',compression=zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(DELIVERY.rglob('*')):
            if path.is_file():archive.write(path,REVISION+'/'+path.relative_to(DELIVERY).as_posix())
    with zipfile.ZipFile(ARCHIVE) as archive:
        assert archive.testzip() is None
        assert p.sha(archive.read(REVISION+'/upgrade.lgu'))==result['lgu_sha256']
        assert all(not any(term in n.lower() for term in ('btsnoop','cover-0.jpg','cover-1.jpg','cover-2.jpg','protocols-local')) for n in archive.namelist())
    return dict(lgu=str(DELIVERY/'upgrade.lgu'),zip=str(ARCHIVE),sha256=result['lgu_sha256'],members=1918,retained=1555)

if __name__=='__main__':print(json.dumps(build(),indent=2))
