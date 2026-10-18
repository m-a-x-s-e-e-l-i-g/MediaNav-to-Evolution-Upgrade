"""Full inherited MAX25 suite plus actual written navigation instrumentation."""
import argparse,json
from pathlib import Path
from package_max16 import write
from verify_max25 import verify as prior
from verify_navigation26 import targeted,analyzer_cases


def verify(root,revision=26):
    prior(root,revision=revision)
    inherited=json.loads((root/'verification.json').read_bytes())
    assert inherited['passed'] and inherited['cases']>=526
    extra=targeted(root)+analyzer_cases(root);checks=inherited['checks']+extra
    write(root/'navigation-verification.json',dict(passed=True,cases=len(extra),checks=extra))
    write(root/'verification.json',dict(passed=True,cases=len(checks),checks=checks,
        firmware_executed_natively=False,limits=inherited['limits']+[
        'Navigation CE memory, scheduling and real action costs require car testing.',
        'GTMC is native accounting and observed peak, not process working set; disabled intervals and contention omit observations.',
        'Request handlers and UI intervals are not route completion, FPS or end-to-end interaction latency.']))
    print('Passed',len(checks),'combined checks',flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args();verify(a.build.resolve())
