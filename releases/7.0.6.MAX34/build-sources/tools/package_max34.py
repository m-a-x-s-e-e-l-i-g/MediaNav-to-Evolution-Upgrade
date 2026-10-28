"""Package a full local MAX34 USB candidate with independent LGU roundtrip."""
import argparse,ast,json,shutil,zipfile
from pathlib import Path
from types import FunctionType
import pefile
import build_review_update as container
from build_max34 import ROOT,BASE,BASE_SHA,REVISION
from package_max16 import sha,tree,write
from patch_usb_transition34 import patch

GUIDE='''# MAXmade 7.0.6.MAX34 — USB track transition candidate

Local candidate; USB audio still needs physical car confirmation. MAX33 remains
the public download. Complete MAX33 successor, with every prior payload path.

## USB correction

A pending DirectShow pause can now be cancelled by Stop. Completion must still
be confirmed before state publication, seeking, interface release or a new graph.
Preserve the native completed Running -> Pause -> Stop sequence. Stop/Pause are
issued at most once per transition stage; a stale Running response cannot undo
an issued Stop. The five-second bound, failed-HRESULT checks, pointer guards,
failure cleanup and ownership on an unconfirmed stop stay active.

This corrects the reproducible issue66 guard failure; COM/codec/time calls in
the offline checks are simulated. Native MP3 decoding and audible playback have
not been tested. No claim that every USB/folder-player feature is now proven.
Temperature, profile/theme changes and Bluetooth liveness remain unresolved.

## Installation and inherited behavior

This is the complete update, not a USB patch kit. Use the normal full-update
procedure with stable power and leave USB inserted through installation.
The existing resumable installer is regenerated for this exact payload and uses
MAX34 progress/receipt names, keeping MAX33 metadata separate. Its native healthy
settings migration and recovery algorithm stay the same. All prior features,
kernel, MCU input, DBoot, Bluetooth, navigation, UI assets and settings behavior
are retained. MAX33's first-stage, storage and hardware limitations still apply.

Changed payload: MgrUSB.exe; installer UpgradeManager.exe/Recovery.exe/
InstallResume.exe for the new package identity; diagnostic header/checksum;
Version_Info.txt. There are 1,921 members, six changed and 1,915 byte-exact.
No maps, licenses or private settings are supplied.

## Stationary car acceptance

1. Confirm 7.0.6.MAX34 after the complete install. Start with Debugging Off.
2. Resume a track, pick another from the list, then select the first again.
   Include the reporter's originals, 44.1 kHz/no-cover and small-JPG files.
3. Next/previous track, next/previous folder, end-of-track auto advance,
   pause/play, seeking, source switch away/back and USB unplug/reinsert.
4. Repeat a short test with Debugging On. Turn it Off, wait for Logging off,
   then retain the entire MAXmade/logs folder and identify what was playing.
5. Confirm normal radio/Bluetooth/navigation and saved settings still work.

Report actual audible playback and any unsupported-format popup, delay or
stuck UI. Logs alone do not confirm audio. Do not use clear/virgin/profile
configuration buttons to try to fix temperature or theme behavior.
'''


def dependencies():
    pending=[ROOT/'tools'/n for n in ['build_max34.py','installer_resume34.py','install_resume34.c',
        'recovery34.c','verify_installer34.py','verify_installer34_native.py','package_max34.py',
        'verify_usb_transition34.py','patch_usb_transition34.py','check_max34_release.py']]
    seen=set()
    while pending:
        p=pending.pop()
        if p in seen:continue
        seen.add(p)
        if p.suffix!='.py':continue
        for node in ast.walk(ast.parse(p.read_text(encoding='utf-8-sig'))):
            names=[node.module]if isinstance(node,ast.ImportFrom)else[a.name for a in node.names]if isinstance(node,ast.Import)else[]
            for name in names:
                if name:
                    q=ROOT/'tools'/(name.split('.')[0]+'.py')
                    if q.is_file():pending.append(q)
    seen.add(ROOT/'tools/issue56_repair.c');return sorted(seen)


def package(stage,usb_proof):
    delivery=ROOT/'build/maxmade-7.0.6.MAX34';archive=ROOT/'build/maxmade-7.0.6.MAX34.zip'
    old=ROOT/'build/maxmade-7.0.6.MAX33'
    assert not delivery.exists()and not archive.exists()and not(stage/'upgrade.lgu').exists()
    plan=json.loads((stage/'member-plan.json').read_bytes());expected={r['path']:r['after']for r in plan['members']}
    prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    assert len(expected)==1921 and set(expected)==set(prior)and plan['retained_members']==1915
    tree(stage/'payload',expected);tree(BASE/'payload',prior);assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    candidate,recipe=patch((BASE/'payload/upgrade/Storage Card/System/MgrUSB.exe').read_bytes())
    assert sha(candidate)==expected['upgrade/Storage Card/System/MgrUSB.exe']['sha256']
    proofs=[json.loads(p.read_bytes())for p in [usb_proof,stage/'worker-verification.json',stage/'native-verification.json']]
    assert all(p['passed']for p in proofs)and proofs[0]['cases']>=174
    assert proofs[0]['input_sha256']==recipe['input_sha256']and proofs[0]['output_sha256']==sha(candidate)
    for name in plan['changed_members']:
        if name.lower().endswith(('.exe','.dll')):
            p=pefile.PE(str(stage/'payload'/name));assert p.FILE_HEADER.Machine==0x166 and p.OPTIONAL_HEADER.Subsystem==9 and p.verify_checksum()
    for name,folder in [('install_resume34.c','engine'),('recovery34.c','menu')]:
        assert (ROOT/'tools'/name).read_bytes()==(stage/folder/name).read_bytes()
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ['dir2lgu.exe','lgu2dir.exe'])
    assert sha(writer.read_bytes())==container.WRITER_HASH and sha(extractor.read_bytes())==container.EXTRACTOR_HASH
    w=container.run_pc_tool(writer,['-p','m1',REVISION,stage/'payload',stage/'upgrade.lgu'],stage/'dir2lgu.log')
    key=bytes.fromhex(json.loads((ROOT/'sources/MediaNav-usb-seek-timing/src/container/lgu0.json').read_bytes())['xor_hex'])
    fn=FunctionType(container.verify_package.__code__,dict(container.verify_package.__globals__,xor_key=lambda:key))
    verification=fn(stage/'upgrade.lgu',expected,REVISION)
    e=container.run_pc_tool(extractor,[stage/'upgrade.lgu',stage/'roundtrip'],stage/'lgu2dir.log');tree(stage/'roundtrip',expected)
    sources=dependencies();pins={p.relative_to(ROOT).as_posix():sha(p.read_bytes())for p in sources}
    proof=dict(passed=True,cases=sum(p['cases']for p in proofs),usb_cases=proofs[0]['cases'],physical_tested=False,
        checks=[c for p in proofs for c in p['checks']])
    manifest=dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,previous_paths_retained=1921,exact_previous_members=1915,
        changed_members=plan['changed_members'],added_members=[],missing_members=[],writer=w,extractor=e,
        container_verification=verification,byte_verification=proof,source_pins=pins,car_tested=False,published=False)
    write(stage/'verification.json',proof);write(stage/'build-manifest.json',manifest)
    shutil.copytree(old,delivery)
    history=delivery/'usb-transition-evidence/inherited-MAX33';history.mkdir(parents=True)
    for n in ['build-manifest.json','verification.json','member-plan.json','runtime.json','device-status.json',
        'package-verification.json','public-baseline-comparison.json','source-manifest.json','README.md','REPORTER-TEST-PLAN.md','CmnDll.dll.json']:
        if (delivery/n).is_file():shutil.copyfile(delivery/n,history/n)
    for n in ['upgrade.lgu','build-manifest.json','verification.json','member-plan.json','runtime.json']:
        shutil.copyfile(stage/n,delivery/n)
    (delivery/'README.md').write_text(GUIDE,encoding='utf-8')
    (delivery/'REPORTER-TEST-PLAN.md').write_text(GUIDE[GUIDE.index('## Stationary car acceptance'):],encoding='utf-8')
    evidence=delivery/'usb-transition-evidence'
    for n in ['development.json','MgrUSB.exe.json','UpgradeManager.exe.json','worker-verification.json','native-verification.json']:
        shutil.copyfile(stage/n,evidence/n)
    shutil.copyfile(usb_proof,evidence/'usb-verification.json')
    for folder in ['engine','menu']:
        dest=evidence/folder;dest.mkdir()
        for p in (stage/folder).iterdir():
            if p.is_file()and p.suffix in ['.json','.h','.c','.ld']:shutil.copyfile(p,dest/p.name)
    for p in sources:
        dest=delivery/'build-sources'/p.relative_to(ROOT);dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(p,dest)
    status=dict(revision=REVISION,candidate_only=True,published=False,car_tested=False,usb_hardware_confirmation_pending=True,
        temperature_theme_unresolved=True,lgu_sha256=verification['lgu_sha256'])
    write(delivery/'device-status.json',status)
    write(delivery/'public-baseline-comparison.json',dict(baseline='7.0.6.MAX33',retained_paths=1921,unchanged_members=1915,changed_members=plan['changed_members'],added_members=[],missing_members=[]))
    cmn=next(r for r in plan['members']if r['path'].endswith('/CmnDll.dll'))
    write(delivery/'CmnDll.dll.json',dict(revision_only_from_MAX33=True,before_sha256=cmn['before']['sha256'],output_sha256=cmn['after']['sha256']))
    write(delivery/'source-manifest.json',dict(files=[dict(path='build-sources/'+n,sha256=h,bytes=(delivery/'build-sources'/n).stat().st_size)for n,h in pins.items()]))
    summary=dict(passed=True,revision=REVISION,lgu=str(delivery/'upgrade.lgu'),sha256=verification['lgu_sha256'],bytes=verification['bytes'],
        members=1921,exact_previous_members=1915,checks=proof['cases'],source_files=len(pins),car_test_pending=True,published=False)
    write(stage/'package-verification.json',summary);write(delivery/'package-verification.json',summary)
    assert {p.relative_to(old)for p in old.rglob('*')if p.is_file()}<={p.relative_to(delivery)for p in delivery.rglob('*')if p.is_file()}
    sums=''.join(sha(p.read_bytes())+'  '+p.relative_to(delivery).as_posix()+'\n'for p in sorted(delivery.rglob('*'))if p.is_file()and p.name!='SHA256SUMS.txt')
    (delivery/'SHA256SUMS.txt').write_text(sums,encoding='utf-8')
    for row in sums.splitlines():h,n=row.split('  ',1);assert sha((delivery/n).read_bytes())==h
    with zipfile.ZipFile(archive,'x',zipfile.ZIP_DEFLATED)as z:
        for p in sorted(delivery.rglob('*')):
            if p.is_file():z.write(p,REVISION+'/'+p.relative_to(delivery).as_posix())
    with zipfile.ZipFile(archive)as z:assert z.testzip()is None and sha(z.read(REVISION+'/upgrade.lgu'))==verification['lgu_sha256']
    print(json.dumps(summary,indent=2),flush=True);return summary


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);p.add_argument('--usb-proof',type=Path,required=True);a=p.parse_args()
    package(a.stage.resolve(),a.usb_proof.resolve())
