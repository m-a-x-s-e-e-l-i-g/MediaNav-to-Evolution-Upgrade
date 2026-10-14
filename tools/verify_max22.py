"""Inherited diagnostics plus regression tests through actual native rendering."""
import argparse,json
from pathlib import Path
import verify_max19 as legacy
from verify_max20 import Fixture,VM
from package_max16 import write


def main():
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args()
    legacy.Fixture=Fixture;legacy.VM=VM
    from verify_clients21 import client_cases
    from verify_settings22 import settings_cases
    from verify_persistence22 import regression_cases
    from verify_metrics22 import targeted
    from verify_max21 import native_lifetime_cases
    from verify_redraw22 import native_label_cases
    cases=[]
    for name,fn in [('runtime/writer',legacy.core_cases),('PE integrity',legacy.image_checks),
                    ('event ABI',client_cases),('immediate Settings',settings_cases),
                    ('source table',legacy.switch_table_cases),('navigation',legacy.inherited_cases),
                    ('persistence/files',regression_cases),('phase metrics',targeted),
                    ('native artwork lifetime',native_lifetime_cases),('native label rendering',native_label_cases)]:
        print('Checking '+name,flush=True);cases+=fn(a.build)
    f=Fixture(a.build);f.init();f.vm.write(legacy.SHARED+0x2c,0x2222)
    f.call(f.A['status'],[2]);args=next(args for ordinal,args in f.calls if ordinal==250)
    assert args[:3]==[0x2222,0,0];cases.append('background writer status requests non-erasing repaint')
    result=dict(passed=True,cases=len(cases),checks=cases,firmware_executed_natively=False,
                limits=['Actual label MIPS executes with explicit GDI/background/text boundaries; native display and timing still need car testing.'])
    write(a.build/'verification.json',result);print('Passed '+str(len(cases))+' checks')


if __name__=='__main__':main()
