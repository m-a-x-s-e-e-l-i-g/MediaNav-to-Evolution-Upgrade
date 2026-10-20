"""Full unchanged-feature regressions plus the changed boot/installer paths."""
import argparse,json,shutil
from pathlib import Path
from verify_max26 import verify as previous
from verify_iphone27 import targeted,analyzer_cases
from verify_boot_recovery29 import verify as boot

def inherited(root,revision=29):
    view=root/'inherited-view';view.mkdir(exist_ok=False)
    # Old generic EXE-overlay checks assume each EXE is a MAX18 client.
    # Changed boot executables and the new standalone menu have dedicated tests.
    for name in ['AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe','CmnDll.dll']:
        for suffix in ['', '.json']:shutil.copyfile(root/(name+suffix),view/(name+suffix))
    shutil.copyfile(root/'runtime.json',view/'runtime.json')
    for name in ['nng','payload']:shutil.copytree(root/name,view/name)
    previous(view,revision=revision)
    r=json.loads((view/'verification.json').read_bytes());checks=r['checks']+targeted(root)+analyzer_cases(root)
    result=dict(passed=True,cases=len(checks),checks=checks,limits=r['limits'],
        scope='Actual current application/runtime binaries; changed boot EXEs checked by separate boot suite, not old overlay-only verifier.')
    (root/'inherited-verification.json').write_text(json.dumps(result,indent=2)+'\n');return result

def combine(root):
    a=json.loads((root/'inherited-verification.json').read_bytes());b=json.loads((root/'boot-recovery-verification.json').read_bytes())
    assert a['passed']and b['passed'];checks=a['checks']+b['checks']
    r=dict(passed=True,cases=len(checks),checks=checks,car_tested=False,limits=a['limits']+[b['limits']])
    (root/'verification.json').write_text(json.dumps(r,indent=2)+'\n');print('PASS',len(checks),'MAX29 checks',flush=True);return r

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);p.add_argument('--inherited-only',action='store_true');p.add_argument('--combine-only',action='store_true');a=p.parse_args();root=a.build.resolve()
    if a.combine_only:combine(root)
    else:
        inherited(root)
        if not a.inherited_only:boot(root);combine(root)
