"""Build a full successor release from cumulative fixes plus approved skin."""
import argparse
import json
import zipfile
from datetime import datetime,timezone
from pathlib import Path
import pefile
from integrate_approved_skin import ROOT,BASE,APP,sha,read_manifest,audit_development,overlay_app,verify_home,verify_av,artwork
from build_review_update import VERSION_PATH,NAV_PATH,NAV_HASH,WRITER_HASH,EXTRACTOR_HASH,run_pc_tool,verify_package,relative
from build_maxmade_update import version_model
from check_source_menu_buttons import check as check_source_menus
from verify_usb_option_snapshot import verify as verify_options
from verify_usb_status_consumers import verify as verify_consumers
from audit_usb_cover_callers import verify as verify_cover_callers
from verify_media_responsiveness import verify_touch

BLUE='upgrade/Storage Card/System/Blue.exe'
USB='upgrade/Storage Card/System/MgrUSB.exe'

def write_json(path,value):path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')

def prepare(args,out):
    development=args.development.resolve();skin=args.skin.resolve();release=args.previous.resolve()
    assert development.is_dir() and skin.is_dir() and release.is_dir()
    dev,history=audit_development(development)
    previous=read_manifest(release/'build-manifest.json')
    public={r['path']:r for r in previous['verification']['members']}
    assert previous['revision']=='7.0.6.MAX03' and len(public)==1918
    assert sha((release/'upgrade.lgu').read_bytes())==previous['verification']['lgu_sha256']==dev['previous_lgu_sha256']
    assert {r['path'] for r in dev['members']}==set(public)
    assert all(r['previous_release_sha256']==public[r['path']]['sha256'] for r in dev['members'])
    print('Complete prior release, current files, fix history, tools and evidence pins verified',flush=True)
    images,skin_source=artwork(skin,dev)
    before=(development/'payload'/APP).read_bytes();combined,color_recipe=overlay_app(before,skin)
    assert color_recipe['color_instruction_changed_bytes']==280 and len(color_recipe['edits'])==138
    expected={r['path']:dict(r) for r in dev['members']};changes=[]
    overrides={APP:combined,VERSION_PATH:args.revision.encode('ascii')}
    overrides.update({r['path']:(skin/'payload'/r['path']).read_bytes() for r in images})
    out.mkdir(parents=True,exist_ok=False)
    for name,row in expected.items():
        name=relative(name);raw=overrides.get(name)
        if raw is None:raw=(development/'payload'/name).read_bytes()
        path=out/'payload'/name
        assert len(str(path))<240
        path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(raw)
        assert path.read_bytes()==raw,name
        if sha(raw)!=row['sha256']:changes.append(dict(path=name,before_sha256=row['sha256'],after_sha256=sha(raw)))
        expected[name]=dict(bytes=len(raw),sha256=sha(raw))
    assert len(changes)==273
    assert {p.relative_to(out/'payload').as_posix() for p in (out/'payload').rglob('*') if p.is_file()}==set(public)
    assert sha((out/'payload'/BLUE).read_bytes())==next(r['sha256'] for r in dev['members'] if r['path']==BLUE)
    assert sha((out/'payload'/USB).read_bytes())==next(r['sha256'] for r in dev['members'] if r['path']==USB)
    assert sha((out/'payload'/NAV_PATH).read_bytes())==NAV_HASH==public[NAV_PATH]['sha256']
    print('Wrote all 1,918 files; retained bugfix code, 280 approved color bytes and 30 relocation moves',flush=True)
    actual=(out/'payload'/APP).read_bytes()
    home=verify_home(before,actual)
    print('Combined AppMain: all 24 home layout cases passed',flush=True)
    av=verify_av(before,actual)
    menus=check_source_menus(out/'payload')
    print('All 106 AV constructor cases and eight source-menu image states passed',flush=True)
    # Retest functional callers in the combined written executable. Entire Blue
    # and MgrUSB files retain their pinned cumulative checks by identical hashes.
    recipes=dev['recipes'];option=recipes['option']
    old_option=(ROOT/'build/usb-snapshot-copy-development-02/payload'/APP).read_bytes()
    old_option_recipe=read_manifest(ROOT/'build/usb-snapshot-copy-development-02/manifest.json')['recipes']['app']
    print('Checking retained repeat/shuffle snapshot, text/cover consumers and touch-release',flush=True)
    options=verify_options(old_option,actual,old_option_recipe,recipes['app'],option)
    old_consumers=(ROOT/'build/startup-failure-development-01/payload'/APP).read_bytes()
    usb=(out/'payload'/USB).read_bytes()
    consumers=verify_consumers(old_consumers,actual,usb,recipes['app'],recipes['usb'])
    callers=verify_cover_callers(actual,usb,recipes['app'],recipes['usb'])
    touch=verify_touch((ROOT/'build/updater-copy-safety-development-02/payload'/APP).read_bytes(),actual)
    retained=dict(option_snapshot=options,usb_consumers=consumers,cover_callers=callers,touch_release=touch,
                  unchanged_blue_sha256=sha((out/'payload'/BLUE).read_bytes()),unchanged_mgrusb_sha256=sha(usb),
                  all_other_bugfix_bytes_recovered_by_exact_color_overlay_reversal=True)
    proof=dict(development=development.name,skin=skin.name,history=history,skin_source=skin_source,
               color_overlay=color_recipe,home=home,av=av,source_menus=menus,retained=retained,
               artwork=images,native_executed=False,hardware_tested=False)
    write_json(out/'integration-proof.json',proof)
    write_json(out/'staging-manifest.json',dict(revision=args.revision,previous_release=previous['revision'],
        previous_release_manifest_sha256=sha((release/'build-manifest.json').read_bytes()),
        previous_lgu_sha256=previous['verification']['lgu_sha256'],development=development.name,
        development_manifest_sha256=sha((development/'manifest.json').read_bytes()),skin=skin.name,
        skin_manifest_sha256=sha((skin/'manifest.json').read_bytes()),members=expected,
        changed_from_development=changes,unchanged_from_development=1645,missing_members=[],added_members=[],
        integration_proof_sha256=sha((out/'integration-proof.json').read_bytes()),
        tools={name:sha((ROOT/'tools'/name).read_bytes()) for name in ('build_cumulative_maxmade_update.py','integrate_approved_skin.py','check_source_menu_buttons.py','maxmade_release_readme.md')},
        previous_member_hashes={n:r['sha256'] for n,r in public.items()},native_executed=False,hardware_tested=False))
    print('Combined skin/bugfix staging passed all checks',flush=True)

def release_notes(revision):
    return (ROOT/'tools/maxmade_release_readme.md').read_text(encoding='utf-8').format(revision=revision)


def package(args,out):
    staging=read_manifest(out/'staging-manifest.json')
    assert staging['revision']==args.revision and len(staging['members'])==1918
    assert sha((out/'integration-proof.json').read_bytes())==staging['integration_proof_sha256']
    for name,digest in staging['tools'].items():
        source=out/staging.get('tool_sources',{}).get(name,'') if name in staging.get('tool_sources',{}) else ROOT/'tools'/name
        assert sha(source.read_bytes())==digest
    expected=staging['members']
    if args.screenshots:
        import shutil
        (out/'screenshots').mkdir(exist_ok=True)
        for photo in args.screenshots.glob('*.jpg'):shutil.copy2(photo,out/'screenshots'/photo.name)
    assert {p.name for p in (out/'screenshots').glob('*.jpg')}=={f'{screen}-{state}.jpg' for screen in ('home','radio','media','phone') for state in ('before','after')},'Supply eight before/after previews with --screenshots'
    for name,row in expected.items():
        raw=(out/'payload'/name).read_bytes();assert len(raw)==row['bytes'] and sha(raw)==row['sha256'],name
    assert {p.relative_to(out/'payload').as_posix() for p in (out/'payload').rglob('*') if p.is_file()}==set(expected)
    recognition=version_model(args.revision)
    recognition.append(dict(current='7.0.6.MAX03',offered=args.revision,ordinary_update_offered=args.revision>'7.0.6.MAX03',native_installation_tested=False))
    assert all(row['ordinary_update_offered'] for row in recognition)
    writer,extractor=(ROOT/'tools/vendor/lgu-favremod'/n for n in ('dir2lgu.exe','lgu2dir.exe'))
    assert sha(writer.read_bytes())==WRITER_HASH and sha(extractor.read_bytes())==EXTRACTOR_HASH
    assert all(pefile.PE(str(t)).FILE_HEADER.Machine==0x14c for t in (writer,extractor))
    assert not (out/'upgrade.lgu').exists() and not Path(str(out)+'.zip').exists()
    writer_run=run_pc_tool(writer,['-p','m1',args.revision,out/'payload',out/'upgrade.lgu'],out/'dir2lgu.log')
    verification=verify_package(out/'upgrade.lgu',expected,args.revision)
    extractor_run=run_pc_tool(extractor,[out/'upgrade.lgu',out/'roundtrip'],out/'lgu2dir.log')
    extracted={relative(p.relative_to(out/'roundtrip').as_posix()):p for p in (out/'roundtrip').rglob('*') if p.is_file()}
    assert set(extracted)==set(expected)
    for name,path in extracted.items():
        raw=path.read_bytes();assert len(raw)==expected[name]['bytes'] and sha(raw)==expected[name]['sha256'],name
    assert (out/'roundtrip'/VERSION_PATH).read_bytes()==args.revision.encode('ascii')
    for run in (writer_run,extractor_run):run.pop('command',None)
    previous=staging['previous_member_hashes']
    changed=[dict(path=n,before_sha256=previous[n],after_sha256=r['sha256']) for n,r in expected.items() if previous[n]!=r['sha256']]
    assert len(changed)==279 and len(expected)-len(changed)==1639
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),revision=args.revision,
        candidate_kind='EXPERIMENTAL FULL UPDATE',build_complete=True,installation_tested=False,
        recommended_public_update=False,flashed=False,native_execution=False,
        previous_release='7.0.6.MAX03',previous_lgu_sha256=staging['previous_lgu_sha256'],
        source_development=staging['development'],approved_skin=staging['skin'],output_members=1918,
        missing_previous_members=[],added_members=[],changed_previous_members=changed,unchanged_previous_members=1639,
        staging_manifest_sha256=sha((out/'staging-manifest.json').read_bytes()),
        integration_proof_sha256=staging['integration_proof_sha256'],tools=staging['tools'],
        header_and_displayed_version_match=True,version_recognition_model=recognition,
        includes_complete_prior_os_boot_mcu_payload=True,navigation_executable_unchanged=True,
        writer=writer_run,extractor=extractor_run,verification=verification,pc_extractor_matches=1918,
        limitations=['Byte/container validation does not prove native installation or recovery',
                     'M1 artwork approved; other profile contrast and runtime loading require unit review',
                     'All full-update hardware compatibility restrictions remain in force'])
    write_json(out/'build-manifest.json',result)
    (out/'README.md').write_text(release_notes(args.revision),encoding='utf-8')
    (out/'SHA256SUMS.txt').write_text(f"{verification['lgu_sha256']}  upgrade.lgu\n",encoding='ascii')
    deliver=('upgrade.lgu','README.md','SHA256SUMS.txt','build-manifest.json','staging-manifest.json','integration-proof.json')
    archive=Path(str(out)+'.zip')
    with zipfile.ZipFile(archive,'w',compression=zipfile.ZIP_DEFLATED) as zipped:
        for name in deliver:zipped.write(out/name,name)
        for image in sorted((out/'screenshots').glob('*.jpg')):zipped.write(image,image.relative_to(out).as_posix())
    with zipfile.ZipFile(archive) as zipped:
        assert zipped.testzip() is None and set(zipped.namelist())==set(deliver)|{image.relative_to(out).as_posix() for image in (out/'screenshots').glob('*.jpg')}
        assert all(zipped.read(name)==(out/name).read_bytes() for name in deliver)
    print(json.dumps(dict(status='full-release-roundtrip-passed',revision=args.revision,members=1918,
        changed_from_MAX03=len(changed),unchanged_from_MAX03=1639,lgu_sha256=verification['lgu_sha256'],
        lgu_bytes=verification['bytes'],zip=archive.relative_to(ROOT).as_posix(),hardware_tested=False),indent=2),flush=True)

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--development',type=Path,required=True)
    parser.add_argument('--skin',type=Path,required=True)
    parser.add_argument('--previous',type=Path,required=True)
    parser.add_argument('--revision',required=True)
    parser.add_argument('--package-only',action='store_true')
    parser.add_argument('--stage-only',action='store_true')
    parser.add_argument('--screenshots',type=Path,help='Directory containing the eight verified before/after JPG previews')
    args=parser.parse_args();version_model(args.revision)
    assert not (args.package_only and args.stage_only)
    out=ROOT/'build'/f'maxmade-{args.revision}'
    if not args.package_only:prepare(args,out)
    if not args.stage_only:package(args,out)
