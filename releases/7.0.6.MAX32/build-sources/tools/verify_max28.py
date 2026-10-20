"""Inherited MAX27 behavior plus native installer recovery regressions."""
import argparse,json
from pathlib import Path
from verify_max26 import verify as prior
from verify_iphone27 import targeted,analyzer_cases
from verify_updater_recovery28 import verify as installer
from package_max16 import write


def verify(root):
    prior(root,revision=28)
    return finish(root)


def finish(root):
    old=json.loads((root/'verification.json').read_bytes())
    assert old['passed']and old['cases']>=571
    recovery=installer(root)
    checks=old['checks']+targeted(root)+analyzer_cases(root)+recovery['checks']
    checks.append('MAX28 stopped installer has an independent desktop escape; no automatic format or resume')
    write(root/'verification.json',dict(passed=True,cases=len(checks),checks=checks,car_tested=False,
        limits=old['limits']+[recovery['limits'],'Recovery UI does not protect failures before the new updater runs or repair an already stopped older updater.']))
    print('PASS',len(checks),'combined checks')


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args();verify(a.build.resolve())
