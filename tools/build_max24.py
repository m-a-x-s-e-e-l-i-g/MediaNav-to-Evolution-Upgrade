"""Complete MAX23 successor for Micom/RVC failure guards and GPS observation."""
import argparse,json,shutil
from pathlib import Path
from debug_image import Image,sha
from debug_runtime24 import build_core
from micom_diag24 import build as build_micom
from gps_probe24 import build as build_gps
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max23-source-budget-development-03'
ORIGINAL=ROOT/'build/max18-navigation-launch-development-01'
BASE_SHA='b753379d1d911c7b211813fa41079423774235270e8698862872240b38a69ee7'
REVISION='7.0.6.MAX24'


def build(out):
    assert not out.exists(),'Choose a fresh directory'
    assert sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    previous={r['path']:r['after'] for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    original={r['path']:r['after'] for r in json.loads((ORIGINAL/'member-plan.json').read_bytes())['members']}
    tree(BASE/'payload',previous);out.mkdir(parents=True)
    shutil.copytree(BASE/'payload',out/'payload');expected=dict(previous)
    system='upgrade/Storage Card/System/'
    for name in ['AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe']:
        shutil.copyfile(BASE/name,out/name);shutil.copyfile(BASE/(name+'.json'),out/(name+'.json'))
    for path in [system+'CmnDll.dll',system+'MicomManager.exe','upgrade/Storage Card4/NNG/nngnavi.exe']:
        name=Path(path).name
        source=ORIGINAL if name!='nngnavi.exe' else BASE
        raw=(source/'payload'/path).read_bytes();pin=(original if source==ORIGINAL else previous)[path]['sha256']
        if name=='CmnDll.dll':
            i=Image(raw,pin);runtime=build_core(i);candidate,recipe=i.finish();write(out/'runtime.json',runtime)
        elif name=='MicomManager.exe':candidate,recipe=build_micom(raw,pin)
        else:candidate,recipe=build_gps(raw,pin)
        target=out if name!='nngnavi.exe' else out/'nng';target.mkdir(exist_ok=True)
        (target/name).write_bytes(candidate);write(target/(name+'.json'),recipe)
        (out/'payload'/path).write_bytes(candidate)
        expected[path]=dict(bytes=len(candidate),sha256=sha(candidate))
    version=system+'Version_Info.txt';value=REVISION.encode('ascii')
    (out/'payload'/version).write_bytes(value);expected[version]=dict(bytes=len(value),sha256=sha(value))
    tree(out/'payload',expected);tree(BASE/'payload',previous)
    changed=sorted(k for k in expected if expected[k]!=previous[k]);assert len(changed)==4
    write(out/'member-plan.json',dict(member_count=len(expected),prior_paths_retained=len(previous),
        retained_members=len(expected)-len(changed),changed_members=changed,added_members=[],missing_members=[],
        members=[dict(path=k,before=previous[k],after=expected[k]) for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,
        changed_members=changed,native_executed=False,car_tested=False,full_previous_payload_retained=True,
        issues=[53,54],logs_gps_coordinates=False,changes_mcu_commands=False))
    print(out,flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();build(a.output.resolve())
