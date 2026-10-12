"""Package full MAX15, independently decode and separately extract every member."""
from datetime import datetime,timezone
from types import FunctionType
import json
import shutil
import zipfile
import build_max15 as p
import build_review_update as container
from build_max05_candidate import tree
from verify_max15 import audit,api_contract

REVISION='7.0.6.MAX15'
STAGE=p.REPO/'build/maxmade-7.0.6.MAX15-cover-start-local-01'
DELIVERY=p.ROOT/'build/maxmade-7.0.6.MAX15'
ARCHIVE=p.ROOT/'build/maxmade-7.0.6.MAX15.zip'

def write(path,value):path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')

def build():
    for path in (STAGE,DELIVERY,ARCHIVE):assert not path.exists(),str(path)
    previous={r['path']:r['after'] for r in json.loads((p.BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918 and p.sha((p.BASELINE/'upgrade.lgu').read_bytes())==p.BASE_LGU_SHA
    tree(p.BASELINE/'payload',previous);tree(p.BASELINE/'roundtrip',previous)
    proof=json.loads((p.OUT/'verification.json').read_bytes())
    recipe=json.loads((p.OUT/'recipe.json').read_bytes());raw=(p.OUT/'payload'/p.APP).read_bytes()
    assert raw==p.patch((p.BASELINE/'payload'/p.APP).read_bytes())[0]
    assert p.sha(raw)==proof['app_sha256'] and audit(raw,recipe)==proof['audit']
    native_contract=api_contract(raw)
    assert proof['max14_S0_reproduced'] and proof['window_create_to_display_pass']
    assert len(proof['artwork'])==17 and len(proof['window_startup_faults'])==6
    assert not proof['hardware_tested'] and not proof['native_executed']
    expected=dict(previous)
    expected[p.APP.as_posix()]=dict(bytes=len(raw),sha256=p.sha(raw))
    tree(p.OUT/'payload',expected)
    shutil.copytree(p.OUT/'payload',STAGE/'payload')
    (STAGE/'payload'/container.VERSION_PATH).write_bytes(REVISION.encode('ascii'))
    expected[container.VERSION_PATH]=dict(bytes=len(REVISION),sha256=p.sha(REVISION.encode('ascii')))
    changed=[name for name in sorted(expected) if expected[name]!=previous[name]]
    assert set(changed)=={p.APP.as_posix(),container.VERSION_PATH}
    tree(STAGE/'payload',expected)
    writer,extractor=(p.ROOT/'tools/vendor/lgu-favremod'/name for name in ('dir2lgu.exe','lgu2dir.exe'))
    for tool,pin in ((writer,container.WRITER_HASH),(extractor,container.EXTRACTOR_HASH)):
        assert p.sha(tool.read_bytes())==pin and p.pefile.PE(str(tool)).FILE_HEADER.Machine==0x14c
    print('Packing complete 1918-member MAX15 successor.',flush=True)
    writer_run=container.run_pc_tool(writer,['-p','m1',REVISION,STAGE/'payload',STAGE/'upgrade.lgu'],STAGE/'dir2lgu.log')
    key=bytes.fromhex(json.loads((p.REPO/'src/container/lgu0.json').read_bytes())['xor_hex'])
    verify=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    result=verify(STAGE/'upgrade.lgu',expected,REVISION)
    print('Independent decode passed; checking separate extractor.',flush=True)
    extractor_run=container.run_pc_tool(extractor,[STAGE/'upgrade.lgu',STAGE/'roundtrip'],STAGE/'lgu2dir.log')
    tree(STAGE/'roundtrip',expected);tree(STAGE/'payload',expected)
    tree(p.BASELINE/'payload',previous);tree(p.BASELINE/'roundtrip',previous)
    assert p.sha((p.BASELINE/'upgrade.lgu').read_bytes())==p.BASE_LGU_SHA
    manifest=dict(revision=REVISION,generated_utc=datetime.now(timezone.utc).isoformat(),
        baseline_revision='7.0.6.MAX14',baseline_lgu_sha256=p.BASE_LGU_SHA,output_members=1918,
        unchanged_from_MAX14=1916,changed_members=changed,missing_members=[],added_members=[],baseline_unchanged=True,
        Blue_MgrUSB_all_resources_navigation_byte_exact_MAX14=True,
        artwork_status='MAX14 car failure S0. Incorrect -1 thread priority rejected by actual unit kernel instructions; MAX15 uses CE priority 4. Cover display awaits car test.',
        hardware_tested=False,native_executed=False,published=False,flashed=False,
        verification=result,player_verification=proof,native_priority_contract=native_contract,writer=writer_run,extractor=extractor_run,
        source_pins={str(path.relative_to(p.ROOT)):p.sha(path.read_bytes()) for path in
                     (p.ROOT/'tools/build_max15.py',p.ROOT/'tools/verify_max15.py',p.ROOT/'tools/package_max15.py')})
    write(STAGE/'build-manifest.json',manifest)
    write(STAGE/'member-plan.json',dict(members=[dict(path=n,before=previous[n],after=expected[n]) for n in sorted(expected)],
        member_count=1918,retained_members=1916,changed_members=changed,missing_members=[],added_members=[]))
    DELIVERY.mkdir()
    for name in ('upgrade.lgu','build-manifest.json','member-plan.json'):shutil.copyfile(STAGE/name,DELIVERY/name)
    for name in ('verification.json','recipe.json'):shutil.copyfile(p.OUT/name,DELIVERY/name)
    source_dir=DELIVERY/'build-sources';source_dir.mkdir()
    for name in ('build_max15.py','verify_max15.py','package_max15.py'):shutil.copyfile(p.ROOT/'tools'/name,source_dir/name)
    (DELIVERY/'README.md').write_text('''# MAXmade 7.0.6.MAX15 — full local cover-start candidate

Full MAX14 successor: 1,918 payload members, 1,916 byte-exact MAX14. Only
AppMain.exe and Version_Info change. All light/dark resources, playback controls,
Bluetooth audio/title fixes, Blue.exe, USB/iPod, navigation and maps are retained.

Owner's physical MAX14 test reports Cover starting (S0) and no album cover.
The worker requested SetThreadPriority(-1), a desktop Windows constant. This
unit's CE kernel validates an unsigned range 0..7 and rejects -1 with error 87.
MAX15 requests 4, mapped by the actual unit priority table to below-normal 252.
Suspended startup, confirmed priority, nonblocking join and owned-image lifetime
checks remain. No decoder work runs in the audio callback or GUI handler.

The actual kernel instructions reproduce MAX14 S0 in offline interpretation.
MAX15's installed window-create path reaches worker/image/GUI display with
explicit CE scheduling and COM/GDI fixtures. Three real received covers and
startup/decoder/staleness/disconnect/popup/ownership failures are checked.
This is not hardware proof. ALBUM ART REMAINS AN OPEN ISSUE UNTIL CAR TESTING.

The empty slot keeps S0/S1/S2 and D1..D9 diagnostics and now distinguishes:
S3 startup blocked (window, mapping, event, join or thread creation), S4 timer
failed, S5 priority failed, S6 resume failed. Displayed codes are paint snapshots.
A successful accepted cover removes the caption.

Install through your established unit-specific procedure and confirm MAX15.
Check cover after a track change/reconnect, smooth audio and titles, play/pause,
source switching, popups and both themes. If still empty, report the exact code.

All payload names/hashes pass independent LGU decoding and a separate pinned
PC extractor. ZIP CRC and embedded LGU hash pass. Source/verification artifacts
are included; raw phone logs and received cover images are excluded.
Local candidate only: no CE executable run, car flash or GitHub publication.

Open artwork issue: https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/48
''',encoding='utf-8')
    (DELIVERY/'SHA256SUMS.txt').write_text(''.join(p.sha(path.read_bytes())+'  '+path.relative_to(DELIVERY).as_posix()+'\n'
        for path in sorted(DELIVERY.rglob('*')) if path.is_file() and path.name!='SHA256SUMS.txt'),encoding='ascii')
    with zipfile.ZipFile(ARCHIVE,'w',compression=zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(DELIVERY.rglob('*')):
            if path.is_file():archive.write(path,REVISION+'/'+path.relative_to(DELIVERY).as_posix())
    with zipfile.ZipFile(ARCHIVE) as archive:
        assert archive.testzip() is None and p.sha(archive.read(REVISION+'/upgrade.lgu'))==result['lgu_sha256']
        assert all(not any(term in n.lower() for term in ('btsnoop','cover-0.jpg','cover-1.jpg','cover-2.jpg','protocols-local')) for n in archive.namelist())
    return dict(lgu=str(DELIVERY/'upgrade.lgu'),zip=str(ARCHIVE),sha256=result['lgu_sha256'],members=1918,retained=1916)

if __name__=='__main__':print(json.dumps(build(),indent=2))
