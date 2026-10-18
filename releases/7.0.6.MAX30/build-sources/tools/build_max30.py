"""Complete MAX29 successor; reduce logging without altering client operations."""
import argparse,json,shutil
from pathlib import Path
from debug_image import Image,sha
from debug_runtime30 import build_core
from navigation_probe30 import build as build_navigation
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max29-boot-recovery-development-10'
ORIGINAL=ROOT/'build/max18-navigation-launch-development-01'
BASE_SHA='6129795e87cda564aaf741ad228633edbea092a223cff877c1086959722139c2'
REVISION='7.0.6.MAX30'


def build(out):
    assert not out.exists() and sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    previous={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    original={r['path']:r['after']for r in json.loads((ORIGINAL/'member-plan.json').read_bytes())['members']}
    tree(BASE/'payload',previous);out.mkdir(parents=True);shutil.copytree(BASE/'payload',out/'payload');expected=dict(previous)
    for n in ['AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe','CmnDll.dll','UpgradeManager.exe','dboot.exe','NK.bin','Recovery.exe']:
        for suffix in ['', '.json']:shutil.copyfile(BASE/(n+suffix),out/(n+suffix))
    shutil.copytree(BASE/'nng',out/'nng')
    path='upgrade/Storage Card/System/CmnDll.dll'
    i=Image((ORIGINAL/'payload'/path).read_bytes(),original[path]['sha256']);runtime=build_core(i);b,r=i.finish()
    write(out/'runtime.json',runtime);(out/'CmnDll.dll').write_bytes(b);write(out/'CmnDll.dll.json',r)
    (out/'payload'/path).write_bytes(b);expected[path]=dict(bytes=len(b),sha256=sha(b))
    path='upgrade/Storage Card4/NNG/nngnavi.exe'
    raw=(ROOT/'build/max23-source-budget-development-03/payload'/path).read_bytes()
    b,r=build_navigation(raw,'d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9')
    (out/'nng/nngnavi.exe').write_bytes(b);write(out/'nng/nngnavi.exe.json',r)
    (out/'payload'/path).write_bytes(b);expected[path]=dict(bytes=len(b),sha256=sha(b))
    path='upgrade/Storage Card/System/Version_Info.txt';b=REVISION.encode('ascii')
    (out/'payload'/path).write_bytes(b);expected[path]=dict(bytes=len(b),sha256=sha(b))
    tree(out/'payload',expected);changed=sorted(k for k in expected if expected[k]!=previous[k]);assert len(changed)==3
    write(out/'member-plan.json',dict(member_count=len(expected),prior_paths_retained=len(previous),retained_members=len(expected)-3,
        changed_members=changed,added_members=[],missing_members=[],members=[dict(path=k,before=previous[k],after=expected[k])for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,changed_members=changed,
        full_previous_payload_retained=True,car_tested=False,boot_recovery_bytes_unchanged=True,
        inherits_unverified_MAX29_boot_changes=True,settings_switch_unchanged=True))
    print(out,flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();build(a.output.resolve())
