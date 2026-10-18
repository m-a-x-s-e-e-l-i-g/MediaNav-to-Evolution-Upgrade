"""Changed logging MIPS plus current feature regressions and unchanged boot proof."""
import argparse,json
from pathlib import Path
from verify_max29 import inherited
from verify_quiet_logging30 import verify as quiet
from debug_image import sha
from build_max30 import BASE


def combine(root):
    old=json.loads((BASE/'boot-recovery-verification.json').read_bytes())
    for name in ['NK.bin','UpgradeManager.exe','dboot.exe','Recovery.exe']:
        assert sha((BASE/name).read_bytes())==sha((root/name).read_bytes()),name
    boot=dict(old,reused_from=str(BASE),unchanged_boot_members_verified=True)
    (root/'boot-recovery-verification.json').write_text(json.dumps(boot,indent=2)+'\n')
    results=[json.loads((root/n).read_bytes())for n in ['inherited-verification.json','quiet-logging-verification.json','boot-recovery-verification.json']]
    assert all(r['passed']for r in results)
    checks=[c for r in results for c in r['checks']]
    result=dict(passed=True,cases=len(checks),checks=checks,car_tested=False,limits=[
        'Written MIPS executes with explicit CE/filesystem/time/process fixtures; physical overhead and recovery remain unvalidated.',
        'Full queue, lock contention, USB failure and total rate limit can still lose diagnostics.',
        'Unchanged MAX29 boot recovery proof is reused; MAX30 inherits its pending bench-acceptance requirement.'])
    (root/'verification.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS',len(checks),'MAX30 checks',flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);p.add_argument('--inherited-only',action='store_true');p.add_argument('--combine-only',action='store_true');a=p.parse_args();root=a.build.resolve()
    if a.combine_only:combine(root)
    else:
        inherited(root,revision=30)
        if not a.inherited_only:quiet(root);combine(root)
