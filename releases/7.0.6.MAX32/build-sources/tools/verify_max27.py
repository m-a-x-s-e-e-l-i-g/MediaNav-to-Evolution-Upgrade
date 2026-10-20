import argparse,json
from pathlib import Path
from verify_max26 import verify as prior
from verify_iphone27 import targeted,analyzer_cases
from package_max16 import write


def verify(root):
    prior(root,revision=27)
    inherited=json.loads((root/'verification.json').read_bytes())
    checks=inherited['checks']+targeted(root)+analyzer_cases(root)
    write(root/'verification.json',dict(passed=True,cases=len(checks),checks=checks,
        firmware_executed_natively=False,limits=inherited['limits']+[
        'Local CT advertisement correction is proven offline; iPhone remote service behavior and visible pixels require car testing.',
        'The old MAX26 cache field is not valid memory evidence when caching is disabled.']))
    print('Passed',len(checks),'combined checks',flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args();verify(a.build.resolve())
