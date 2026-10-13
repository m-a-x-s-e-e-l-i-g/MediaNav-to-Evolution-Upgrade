"""Create a fresh, fully inherited MAX19 diagnostics development payload."""
import argparse,json,shutil
from pathlib import Path
from debug_image import Image,sha
from debug_runtime import build_core
from debug_clients import build_client
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max18-navigation-launch-development-01'
BASE_SHA='d474cd4e80d12c868837eb71d0251b6089cc3d0c4cc3a1163fd098bd96fd58d1'
VERSION='upgrade/Storage Card/System/Version_Info.txt'
REVISION='7.0.6.MAX19'
BINARIES=['CmnDll.dll','AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe']


def build(out,base=BASE):
    assert not out.exists(),'Use a fresh output directory'
    assert sha((base/'upgrade.lgu').read_bytes())==BASE_SHA
    previous={r['path']:r['after'] for r in json.loads((base/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1919;tree(base/'payload',previous)
    out.mkdir(parents=True);expected=dict(previous);recipes={}
    system='upgrade/Storage Card/System/'
    for name in BINARIES:
        raw=(base/'payload'/system/name).read_bytes();pin=previous[system+name]['sha256']
        if name=='CmnDll.dll':
            image=Image(raw,pin);runtime=build_core(image);candidate,recipe=image.finish();write(out/'runtime.json',runtime)
        else:candidate,recipe=build_client(raw,pin,name)
        (out/name).write_bytes(candidate);write(out/(name+'.json'),recipe)
        expected[system+name]=dict(bytes=len(candidate),sha256=sha(candidate));recipes[name]=recipe
    shutil.copytree(base/'payload',out/'payload')
    for name in BINARIES:shutil.copyfile(out/name,out/'payload'/system/name)
    (out/'payload'/VERSION).write_bytes(REVISION.encode('ascii'))
    expected[VERSION]=dict(bytes=len(REVISION),sha256=sha(REVISION.encode('ascii')))
    tree(out/'payload',expected);tree(base/'payload',previous)
    changed=sorted(k for k in expected if expected[k]!=previous[k]);assert len(changed)==8
    write(out/'member-plan.json',dict(member_count=1919,prior_paths_retained=1919,retained_members=1911,
        changed_members=changed,added_members=[],missing_members=[],
        members=[dict(path=k,before=previous[k],after=expected[k]) for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,changed_members=changed,
        full_previous_payload_retained=True,all_images_navigation_kernel_MCU_byte_exact=True,
        native_executed=False,car_tested=False,recipes={k:sha((out/(k+'.json')).read_bytes()) for k in recipes}))
    return out


def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--baseline',type=Path,default=BASE);a=p.parse_args()
    print(build(a.output,a.baseline))

if __name__=='__main__':main()
