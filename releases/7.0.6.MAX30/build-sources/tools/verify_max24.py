"""Run inherited MAX23 checks, then native Micom failure and NNG observer tests."""
import argparse,json,subprocess,sys
from pathlib import Path
from verify_issues24 import issue_cases
from package_max16 import write


def analyzer_cases(root):
    from analyze_debug_logs24 import analyze
    folder=root/'issue-fixture-logs';folder.mkdir(exist_ok=True)
    lines=['\ufeffMAXmade 7.0.6.MAX24 diagnostics','ms\tmodule\tevent\tduration_ms\tresult\tlevel\tmessage',
           'session\t2026-10-15T00:00:00.000\t0',
           f'100\t4\t{0x80000000|403}\t1024\t1\t0\t',
           '130\t4\t403\t30\t0\t0\t',
           f'200\t8\t940\t{0x524d43}\t{0x474e56ff}\t0\t',
           f'201\t8\t941\t{0x524d43}\t0\t0\t',
           f'300\t8\t940\t{0x474741}\t{0x47503000}\t0\t',
           f'301\t8\t941\t{0x474741}\t1\t0\t',
           f'400\t8\t940\t{0x475356}\t{0x4750ff0c}\t0\t',
           f'401\t8\t941\t{0x475356}\t1\t0\t']
    path=folder/'debug-issue-fixture.log';path.write_bytes(('\r\n'.join(lines)+'\r\n').encode('utf-16-le'))
    s=analyze([path])['sessions'][0]
    assert len(s['timings'])==1 and s['timings'][0]['event']==403
    rvc=s['service_actions'][0]
    assert rvc['test_write_blocked'] and rvc['requested_enabled'] and not rvc['write_acknowledged']
    rmc,gga,gsv=s['gps_observations']
    assert rmc['talker']=='GN' and rmc['raw_status']=='V' and not rmc['native_parser_accepted']
    assert gga['satellites_used_reported']==0 and gga['raw_status']=='0' and gga['native_parser_accepted']
    assert gsv['satellites_visible_reported']==12
    write(root/'issue-fixture-analysis.json',s)
    return ['analyzer separates GPS metadata from timings, visible/used satellites and native acceptance',
            'analyzer distinguishes requested RVC state, test-mode block and failed acknowledgement']


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args();root=a.build.resolve()
    subprocess.run([sys.executable,str(Path(__file__).with_name('verify_max23.py')),'--build',str(root)],check=True)
    inherited=json.loads((root/'verification.json').read_bytes())
    checks=inherited['checks']+issue_cases(root)+analyzer_cases(root)
    write(root/'verification.json',dict(passed=True,cases=len(checks),checks=checks,
        firmware_executed_natively=False,limits=['CE, UART and NMEA-parser boundaries are explicit fixtures.',
        'Micom and NNG retain their original fixed-base executable policy.',
        'Actual reporter-unit GPS/RVC resolution is unconfirmed until physical testing.']))
    print('Passed',len(checks),'combined checks',flush=True)
