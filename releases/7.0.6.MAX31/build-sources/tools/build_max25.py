"""Complete MAX24 successor with read-only Bluetooth artwork diagnostics."""
import argparse,json,shutil
from pathlib import Path
from debug_image import Image,sha
from debug_runtime25 import build_core
from artwork_probe25 import build as build_blue
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max24-micom-gps-development-03'
ORIGINAL=ROOT/'build/max18-navigation-launch-development-01'
BASE_SHA='268ff9abd6ce262bce7e347228bfe5c705c460e61f6dcdf35b33e87312b31d83'
REVISION='7.0.6.MAX25'


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
    for name in ['CmnDll.dll','Blue.exe']:
        path=system+name;raw=(ORIGINAL/'payload'/path).read_bytes();pin=original[path]['sha256']
        if name=='CmnDll.dll':
            i=Image(raw,pin);runtime=build_core(i);candidate,recipe=i.finish();write(out/'runtime.json',runtime)
        else:candidate,recipe=build_blue(raw,pin)
        (out/name).write_bytes(candidate);write(out/(name+'.json'),recipe)
        (out/'payload'/path).write_bytes(candidate)
        expected[path]=dict(bytes=len(candidate),sha256=sha(candidate))
    version=system+'Version_Info.txt';value=REVISION.encode('ascii')
    (out/'payload'/version).write_bytes(value);expected[version]=dict(bytes=len(value),sha256=sha(value))
    tree(out/'payload',expected);tree(BASE/'payload',previous)
    changed=sorted(k for k in expected if expected[k]!=previous[k]);assert len(changed)==3
    write(out/'member-plan.json',dict(member_count=len(expected),prior_paths_retained=len(previous),
        retained_members=len(expected)-len(changed),changed_members=changed,added_members=[],missing_members=[],
        members=[dict(path=k,before=previous[k],after=expected[k]) for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,
        changed_members=changed,native_executed=False,car_tested=False,full_previous_payload_retained=True,
        changes_bluetooth_protocol=False,logs_image_bytes=False,logs_device_addresses=False))
    print(out,flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();build(a.output.resolve())
