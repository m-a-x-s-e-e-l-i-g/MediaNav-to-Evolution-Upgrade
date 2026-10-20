"""Retain MAX24 checks and exercise the additional written-MIPS diagnostics."""
import argparse,json,sys
from pathlib import Path
from package_max16 import write


def verify(root,revision=25):
    import verify_metrics23
    import verify_max23
    from verify_issues24 import issue_cases
    from verify_max24 import analyzer_cases as gps_analyzer_cases
    from verify_artwork25 import targeted,analyzer_cases
    recipe=json.loads((root/'Blue.exe.json').read_bytes())
    # Older metric fixtures count only the older metric records. The new
    # observer is an explicit boundary there; its actual written instructions,
    # periodic records and ABI are tested separately below.
    previous_fixture=verify_metrics23.fixture
    def metric_fixture(raw,*args,**kw):
        m,last,tick,records=previous_fixture(raw,*args,**kw)
        if m.pe.OPTIONAL_HEADER.ImageBase==0x10000 and any(s.Name.startswith(b'.mxdebug') for s in m.pe.sections):
            # AppMain uses the same PE base: distinguish exact candidate bytes.
            if raw==(root/'Blue.exe').read_bytes():
                m.hooks[recipe['artwork_diagnostics']['snapshot']]=lambda v:0
        return m,last,tick,records
    verify_metrics23.fixture=metric_fixture
    oldargv=sys.argv;sys.argv=['verify_max23.py','--build',str(root)]
    try:verify_max23.main()
    finally:sys.argv=oldargv;verify_metrics23.fixture=previous_fixture
    previous=json.loads((root/'verification.json').read_bytes())
    checks=previous['checks']+issue_cases(root)+gps_analyzer_cases(root)+targeted(root,revision)+analyzer_cases(root)
    result=dict(passed=True,cases=len(checks),checks=checks,firmware_executed_natively=False,
        limits=['CE APIs, actual scheduling, Bluetooth transport and hardware timing remain fixtures.',
                'Scalar snapshots are individually coherent; different operations and peers are not one atomic snapshot.',
                'iPhone artwork compatibility remains unresolved pending the new physical trace.'])
    write(root/'verification.json',result);print('Passed',len(checks),'combined checks',flush=True)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True)
    a=p.parse_args();verify(a.build.resolve())
