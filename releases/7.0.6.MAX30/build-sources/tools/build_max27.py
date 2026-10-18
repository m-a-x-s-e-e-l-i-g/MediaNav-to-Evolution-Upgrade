"""Complete MAX26 successor: CT cover capability, acceptance evidence and corrected RAM probe."""
import argparse,json,shutil
from pathlib import Path
from debug_image import Image,sha
from debug_runtime27 import build_core
from navigation_probe27 import build as build_navigation
from iphone_cover27 import build as build_blue
from artwork_acceptance27 import build as build_app
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max26-navigation-measurements-development-02'
ORIGINAL=ROOT/'build/max18-navigation-launch-development-01'
BASE_SHA='864142e7e69f3d6c5085a9e0fe6833076bf28c7867e653491923b181c04fb933'
REVISION='7.0.6.MAX27'


def build(out):
    assert not out.exists(),'Choose a fresh directory'
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    original={r['path']:r['after'] for r in json.loads((ORIGINAL/'member-plan.json').read_bytes())['members']}
    tree(BASE/'payload',previous);out.mkdir(parents=True)
    shutil.copytree(BASE/'payload',out/'payload');expected=dict(previous)
    for name in ['AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe','CmnDll.dll']:
        shutil.copyfile(BASE/name,out/name)
        shutil.copyfile(BASE/(name+'.json'),out/(name+'.json'))
    shutil.copytree(BASE/'nng',out/'nng')
    system='upgrade/Storage Card/System/'
    path=system+'CmnDll.dll';raw=(ORIGINAL/'payload'/path).read_bytes()
    i=Image(raw,original[path]['sha256']);runtime=build_core(i);candidate,recipe=i.finish()
    write(out/'runtime.json',runtime);(out/'CmnDll.dll').write_bytes(candidate)
    write(out/'CmnDll.dll.json',recipe);(out/'payload'/path).write_bytes(candidate)
    expected[path]=dict(bytes=len(candidate),sha256=sha(candidate))
    for name,fn in [('Blue.exe',build_blue),('AppMain.exe',build_app)]:
        path=system+name;candidate,recipe=fn((ORIGINAL/'payload'/path).read_bytes(),original[path]['sha256'])
        (out/name).write_bytes(candidate);write(out/(name+'.json'),recipe)
        (out/'payload'/path).write_bytes(candidate);expected[path]=dict(bytes=len(candidate),sha256=sha(candidate))
    path='upgrade/Storage Card4/NNG/nngnavi.exe'
    raw=(ROOT/'build/max23-source-budget-development-03/payload'/path).read_bytes()
    candidate,recipe=build_navigation(raw,'d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9')
    (out/'nng/nngnavi.exe').write_bytes(candidate);write(out/'nng/nngnavi.exe.json',recipe)
    (out/'payload'/path).write_bytes(candidate);expected[path]=dict(bytes=len(candidate),sha256=sha(candidate))
    version=system+'Version_Info.txt';value=REVISION.encode('ascii')
    (out/'payload'/version).write_bytes(value);expected[version]=dict(bytes=len(value),sha256=sha(value))
    tree(out/'payload',expected);tree(BASE/'payload',previous)
    changed=sorted(k for k in expected if expected[k]!=previous[k]);assert len(changed)==5
    write(out/'member-plan.json',dict(member_count=len(expected),prior_paths_retained=len(previous),
        retained_members=len(expected)-len(changed),changed_members=changed,added_members=[],missing_members=[],
        members=[dict(path=k,before=previous[k],after=expected[k]) for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,
        changed_members=changed,native_executed=False,car_tested=False,full_previous_payload_retained=True,
        changes_bluetooth_protocol=True,changes_remote_capabilities=False,logs_image_bytes=False,logs_device_addresses=False))
    print(out,flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();build(a.output.resolve())
