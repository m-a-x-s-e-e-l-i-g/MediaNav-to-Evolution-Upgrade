"""Full MAX19 successor; change only CmnDll, Settings AppMain and version."""
import argparse,json,shutil
from pathlib import Path
from debug_image import Image,sha
from debug_runtime20 import build_core
from debug_clients20 import build_client
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max19-debugging-package-01'
ORIGINAL=ROOT/'build/max18-navigation-launch-development-01'
BASE_SHA='a6c0178bd2c6298bb9fbc99df5dd6e19a40ef5b1026412b974805cc251689922'
REVISION='7.0.6.MAX20'


def build(out):
    assert not out.exists(),'Use a fresh output directory'
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    originals={r['path']:r['after'] for r in json.loads((ORIGINAL/'member-plan.json').read_bytes())['members']}
    assert sha((ORIGINAL/'upgrade.lgu').read_bytes())=='d474cd4e80d12c868837eb71d0251b6089cc3d0c4cc3a1163fd098bd96fd58d1'
    tree(BASE/'payload',previous);out.mkdir(parents=True)
    shutil.copytree(BASE/'payload',out/'payload');expected=dict(previous)
    system='upgrade/Storage Card/System/'
    for name in ['CmnDll.dll','AppMain.exe']:
        raw=(ORIGINAL/'payload'/system/name).read_bytes();pin=originals[system+name]['sha256']
        if name=='CmnDll.dll':
            i=Image(raw,pin);runtime=build_core(i);candidate,recipe=i.finish();write(out/'runtime.json',runtime)
        else:candidate,recipe=build_client(raw,pin,name)
        (out/name).write_bytes(candidate);write(out/(name+'.json'),recipe)
        (out/'payload'/system/name).write_bytes(candidate)
        expected[system+name]=dict(bytes=len(candidate),sha256=sha(candidate))
    for name in ['Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe']:
        shutil.copyfile(BASE/'payload'/system/name,out/name)
        shutil.copyfile(BASE/(name+'.json'),out/(name+'.json'))
    version=system+'Version_Info.txt';(out/'payload'/version).write_bytes(REVISION.encode('ascii'))
    expected[version]=dict(bytes=len(REVISION),sha256=sha(REVISION.encode('ascii')))
    tree(out/'payload',expected);tree(BASE/'payload',previous)
    changed=sorted(k for k in expected if expected[k]!=previous[k]);assert len(changed)==3
    write(out/'member-plan.json',dict(member_count=1919,prior_paths_retained=1919,retained_members=1916,
        changed_members=changed,added_members=[],missing_members=[],
        members=[dict(path=k,before=previous[k],after=expected[k]) for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,
        changed_members=changed,native_executed=False,car_tested=False,full_previous_payload_retained=True))
    print(out)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();build(a.output.resolve())
