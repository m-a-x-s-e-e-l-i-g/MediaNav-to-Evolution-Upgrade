"""Full MAX27 successor with a desktop escape on stopped installer errors."""
import argparse,json,shutil
from pathlib import Path
from debug_image import Image,sha
from debug_runtime28 import build_core
from updater_recovery28 import build as build_updater
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max27-iphone-cover-development-03'
ORIGINAL=ROOT/'build/max18-navigation-launch-development-01'
BASE_SHA='3448b2e0150b3aecd9bf3cd76fbd181b98afd2bbda1fd9ff6b64f2c26947d8eb'
REVISION='7.0.6.MAX28'


def build(out):
    assert not out.exists()
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    original={r['path']:r['after']for r in json.loads((ORIGINAL/'member-plan.json').read_bytes())['members']}
    tree(BASE/'payload',prior);out.mkdir(parents=True)
    shutil.copytree(BASE/'payload',out/'payload');expected=dict(prior)
    for name in ['AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe','CmnDll.dll']:
        for suffix in ['', '.json']:shutil.copyfile(BASE/(name+suffix),out/(name+suffix))
    shutil.copytree(BASE/'nng',out/'nng')
    system='upgrade/Storage Card/System/'
    path=system+'CmnDll.dll';i=Image((ORIGINAL/'payload'/path).read_bytes(),original[path]['sha256'])
    runtime=build_core(i);candidate,recipe=i.finish()
    for name,value in [('runtime.json',runtime),('CmnDll.dll.json',recipe)]:write(out/name,value)
    (out/'CmnDll.dll').write_bytes(candidate);(out/'payload'/path).write_bytes(candidate)
    expected[path]=dict(bytes=len(candidate),sha256=sha(candidate))
    path=system+'UpgradeManager.exe';candidate,recipe=build_updater((BASE/'payload'/path).read_bytes())
    (out/'UpgradeManager.exe').write_bytes(candidate);write(out/'UpgradeManager.exe.json',recipe)
    (out/'payload'/path).write_bytes(candidate);expected[path]=dict(bytes=len(candidate),sha256=sha(candidate))
    path=system+'Version_Info.txt';value=REVISION.encode('ascii')
    (out/'payload'/path).write_bytes(value);expected[path]=dict(bytes=len(value),sha256=sha(value))
    tree(out/'payload',expected);tree(BASE/'payload',prior)
    changed=sorted(k for k in expected if expected[k]!=prior[k]);assert len(changed)==3
    write(out/'member-plan.json',dict(member_count=len(expected),prior_paths_retained=len(prior),
        retained_members=len(expected)-len(changed),changed_members=changed,added_members=[],missing_members=[],
        members=[dict(path=k,before=prior[k],after=expected[k])for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,
        full_previous_payload_retained=True,changed_members=changed,car_tested=False,
        automatic_clean_install=False,requires_dboot_for_error_escape=False))
    print(out)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();build(a.output.resolve())
