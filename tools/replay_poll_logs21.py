"""Feed captured call results/timings through the emitted MAX21 poll wrapper.

The native publication call is an explicit fixture, not replayed hardware.
"""
import argparse,json
from pathlib import Path
from verify_max21 import fixture,call
from package_max16 import write


def replay(root,path):
    samples=[]
    for line in path.read_bytes().decode('utf-16-le',errors='replace').splitlines():
        c=line.split('\t',6)
        if len(c)!=7:continue
        try:ms,module,event,duration,result,level=map(int,c[:6])
        except ValueError:continue
        if module==3 and event==301:samples.append((ms,duration,result))
    raw=(root/'Blue.exe').read_bytes();recipe=json.loads((root/'Blue.exe.json').read_bytes())
    poll=next(r for r in recipe['events'] if r['event']==301)
    m,last,tick,records=fixture(raw,1,0);clock=[];value=[0]
    target=next(m.read(s.address) for d in m.pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.ordinal==535)
    m.hooks[target]=lambda v:clock.pop(0)
    def native(v):last[0]=1234;v.reg[3]=0;return value[0]
    m.hooks[poll['clone']]=native
    for ms,duration,result in samples:
        clock[:]=[(ms-duration)&0xffffffff,ms];value[0]=result
        assert call(m,poll['wrapper'])==[result,0] and last[0]==1234 and not clock
    significant=[r for r in records if r[1]==301]
    summaries=[r for r in records if r[1]==302]
    expected=[r for r in samples if r[2]!=0 or r[1]>=16]
    assert [(r[2],r[3]) for r in significant]==[(duration,result) for ms,duration,result in expected]
    return dict(passed=True,captured_calls=len(samples),old_poll_records=2*len(samples),
                new_poll_records=len(records),periodic_summaries=len(summaries),
                significant_calls_retained=len(significant),
                reduction_percent=round(100*(1-len(records)/(2*len(samples))),2),
                actual_logger_MIPS_interpreted=True,native_publication_is_fixture=True,
                measured_car_CPU_or_latency_improvement=False)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);p.add_argument('--log',type=Path,required=True);p.add_argument('--output',type=Path);a=p.parse_args()
    r=replay(a.build,a.log)
    if a.output:write(a.output,r)
    print(json.dumps(r,indent=2))
