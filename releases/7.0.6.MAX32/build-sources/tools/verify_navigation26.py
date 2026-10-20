"""Execute actual added MIPS and native allocator code; CE APIs are fixtures."""
import argparse,json,struct
from pathlib import Path
import pefile
from verify_issues24 import gps_fixture
from verify_max21 import call
from package_max16 import write


def targeted(root):
    raw=(root/'nng/nngnavi.exe').read_bytes()
    recipe=json.loads((root/'nng/nngnavi.exe.json').read_bytes())
    nav=recipe['navigation_measurements'];D=nav['state_va'];checks=[]
    def fixture(on=1,load_ok=True,cached=True):
        m,last,clock,records,loads=gps_fixture(raw,on,load_ok)
        if cached:m.write(nav['backend_pointer'],0xf6000010)
        return m,last,clock,records,loads
    # Every native wrapper forwards 13 args and result registers/error; debug
    # calls deliberately clobber volatile registers via the explicit CE boundary.
    for row in nav['hooks']:
        for on in (0,1):
            m,last,clock,records,loads=fixture(on)
            manager=0x62000000;args=[manager,22,33,44]
            m.write(manager,100);m.write(manager+12,1);m.write(manager+0x14,8192)
            def native(v):
                assert v.reg[4:8]==args,(row['label'],v.reg[4:8])
                assert [v.read(v.reg[29]+16+j*4) for j in range(9)]==list(range(100,109))
                assert last[0]==77;last[0]=1234;clock[0]+=37;v.reg[3]=0x4321
                for r in [4,5,6,7,8,9,10,11,12,13,14,15,24,25]:v.reg[r]=0xeeeeeeee
                return 0x1234
            m.hooks[row['clone']]=native
            assert call(m,row['wrapper'],args)==[0x1234,0x4321] and last[0]==1234
            assert not loads
            if not on:
                assert not records and m.read(D+0x1c)==0 and m.read(D+0x40)==0
            elif row['kind']=='action':
                ends=[r for r in records if r[1]==row['event']]
                assert ends==[(8,row['event'],37,0)]
                assert [r for r in records if r[1] in (1040,1041)]==[(8,1040,row['event'],104857600),(8,1041,row['event'],104857600)]
            elif row['kind']=='pool':assert m.read(D+0x10)==100 and m.read(D+0x14)==8192 and not records
            elif row['kind']=='ui':assert m.read(D+0x40+(1 if row['entry']==0x254140 else row['category'])*16)==1
            elif row['kind']=='periodic':assert len(records)==(4 if nav.get('compact_empty_ui')else 12)
            checks.append(f"NNG {row['label']} 13 arguments, result/error/nonvolatile preservation, enabled={on}")
    # Lazy backend unavailable: native work continues, no forced dependency or
    # repeated allocation/loader attempts from the page allocator observer.
    for row in nav['hooks']:
        m,last,clock,records,loads=fixture(load_ok=False,cached=False)
        m.hooks[row['clone']]=lambda v:0x1234
        assert call(m,row['wrapper'])==[0x1234,0] and last[0]==77 and not records
        assert loads==([] if row['kind']=='pool' else ['load'])
        checks.append('NNG backend unavailable retains native behavior: '+row['label'])
    # No false zero before an allocator has been observed.
    m,last,clock,records,loads=fixture();call(m,nav['memory'],[0,0,0,0])
    assert not any(r[1]==1022 for r in records) and (8,1023,0,0) in records
    checks.append('NNG unobserved allocator is unknown, not zero pages')
    # Actual native commit/release bodies, including commit refusal and a
    # VirtualFree failure that native accounting does not check.
    for release in (False,True):
        row=next(r for r in nav['hooks'] if r['entry']==(0x242f8 if release else 0x241b0))
        for success in (False,True):
            outcomes=[]
            for observed in (False,True):
                m,last,clock,records,loads=fixture();manager=0x62000000
                for off,val in enumerate([10,0,0,0,0,0,0,0,0x63000000]):m.write(manager+off*4,val)
                m.write(0x983f1c,1000)
                calls=[]
                for d in m.pe.DIRECTORY_ENTRY_IMPORT:
                    for imp in d.imports:
                        if imp.ordinal in (524,525):
                            def api(v,ordinal=imp.ordinal):
                                calls.append((ordinal,tuple(v.reg[4:8])))
                                last[0]=1234;v.reg[3]=0x4321
                                return (0x63004000 if success else 0) if ordinal==524 else int(success)
                            m.hooks[m.read(imp.address)]=api
                if not release and not success:
                    m.hooks[0x240d8]=lambda v:1000
                out=call(m,row['wrapper'] if observed else row['clone'],[manager,0x4000,3,44])
                outcomes.append((out,last[0],m.read(manager),m.read(0x983f1c),calls))
                if observed:
                    expected=7 if release else 13 if success else 10
                    assert m.read(D+0x10)==expected and m.read(D+0x1c)==1
            assert outcomes[0]==outcomes[1],outcomes
            checks.append(f'native GTMC accounting matches unwrapped native code release={release} CE success={success}')
    # Private scalar copies survive invalidation of borrowed memory; no periodic
    # pointer lifetime assumed. Peak remains the observed lower bound.
    m,last,clock,records,loads=fixture();manager=0x62000000;m.write(manager+12,1)
    for pages,cache in [(100,4096),(300,0),(120,8192)]:
        m.write(manager,pages);m.write(manager+0x14,cache);call(m,nav['pool_capture'],[manager,0,0,0])
    del m.mem[manager];del m.mem[manager+0x14]
    call(m,nav['memory'],[1041,1001,0,0])
    assert (8,1022,120,8192) in records and (8,1023,300,1) in records
    checks.append('NNG memory snapshots use private latest scalars and observed peak, no borrowed pointer')
    # Written aggregation and throttle at exact boundary, including tick wrap.
    for start in (5000,0xffffff00):
        m,last,clock,records,loads=fixture();clock[0]=start
        call(m,nav['periodic']);records.clear()
        for c in range(4):
            for duration in (0,49,50,100):call(m,nav['update'],[c,duration,0,0])
        clock[0]=(start+4999)&0xffffffff;call(m,nav['periodic']);assert not records
        clock[0]=(start+5000)&0xffffffff;call(m,nav['periodic'])
        for c in range(4):
            assert (8,1010+c*2,4,199) in records and (8,1011+c*2,100,2) in records
            assert m.read(D+0x40+c*16)==0
        checks.append(f'NNG interval count/total/max/slow threshold, reset and 5-second throttle tick={start:x}')
    # Nonspinning shared lock contention, no partial reads or resets.
    for helper,args in [(nav['update'],[0,100,0,0]),(nav['pool_capture'],[0x62000000,0,0,0]),
                        (nav['periodic'],[0,0,0,0]),(nav['memory'],[0,0,0,0])]:
        m,last,clock,records,loads=fixture();m.write(D,1)
        call(m,helper,args)
        assert m.read(D)==1 and m.read(D+0x1c)==0 and not any(1010<=r[1]<=1017 or r[1]in(1022,1023) for r in records)
        checks.append('NNG locked helper returns without spinning or changing locked state '+hex(helper))
    # Real native WndProc forwarding and category selection. Never copy message
    # parameters into logs, including sentinels resembling locations/pointers.
    row=next(r for r in nav['hooks'] if r['entry']==0x254140)
    for message,cat in [(15,0),(0x201,1),(0x202,1),(0x113,1)]:
        m,last,clock,records,loads=fixture();m.write(0x9825e0,0x62000000)
        def dispatch(v):
            assert v.reg[4:8]==[0x62000000,0x12345678,message,0xdeadbeef]
            assert v.read(v.reg[29]+16)==0xcafef00d
            clock[0]+=75;last[0]=2345;return 0x9876
        m.hooks[0x254170]=dispatch
        assert call(m,row['wrapper'],[0x12345678,message,0xdeadbeef,0xcafef00d])[0]==0x9876 and last[0]==2345
        assert m.read(D+0x40+cat*16)==1 and m.read(D+0x48+cat*16)==75 and not records
        checks.append(f'NNG native WndProc forwarded unchanged, scalar category only message={message:x}')
    # Exact successor invariant: existing artwork bytes untouched, fixed base.
    import build_max26
    br=json.loads((root/'Blue.exe.json').read_bytes())
    if 'iphone_advertisement'not in br:
        assert (root/'Blue.exe').read_bytes()==(build_max26.BASE/'Blue.exe').read_bytes()
    else:
        assert br['iphone_advertisement']['entry']==0x5861c and br['iphone_advertisement']['target_role_unchanged']
    p=pefile.PE(data=raw);assert p.FILE_HEADER.Characteristics&1 and p.verify_checksum()
    checks.append('NNG fixed-base checksum and explicit Blue successor scope validated')
    return checks


def analyzer_cases(root):
    from analyze_debug_logs26 import analyze
    d=root/'navigation-analyzer-fixture';d.mkdir(exist_ok=True)
    header=['MAXmade 7.0.6.MAX26 diagnostics','session\ttest\t0']
    rows=[(10,0x800003e8,0,0),(11,1040,1000,100000000),(12,1000,37,0),
          (13,1041,1000,80000000),(14,1020,80000000,134217728),(15,1023,0,0),
          (16,1022,123,8192),(17,1023,150,1),(18,1010,4,199),(19,1011,100,2),
          (20,1012,0,0),(21,0x800003e9,0,0)]
    for filename,data in [('debug-1.log',rows[6:]),('debug-0.log',rows[:6])]:
        lines=header+[f'{ms}\t8\t{event}\t{v}\t{r}\t0\t' for ms,event,v,r in data]
        (d/filename).write_text('\n'.join(lines)+'\n',encoding='utf-16')
    s=analyze(list(reversed(sorted(d.glob('*.log')))))['sessions'][0];n=s['navigation_measurements']
    assert n['action_timings'][0]['max_ms']==37 and n['action_timings'][0]['unmatched_begin_count']==0
    assert n['action_timings'][1]['unmatched_begin_count']==1
    assert n['gtmc_availability'][0]['available'] is False and n['gtmc_availability'][1]['observed_peak_pages']==150
    assert n['latest_observed_gtmc'][0]['accounted_bytes']==123*4096
    assert n['ui_intervals'][0]['mean_handler_ms']==49.75 and n['ui_intervals'][2]['mean_handler_ms'] is None
    assert all(r['event']<1000 for r in s['timings']) and '1000' not in s['begins_without_matching_end_count']
    assert n['action_ram'][0]['available_physical_bytes']==100000000
    return ['navigation analyzer separates timings from scalar RAM, preserves unknown and pending actions, orders rotation chunks by boot milliseconds']


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args()
    checks=targeted(a.build)+analyzer_cases(a.build)
    write(a.build/'navigation-verification.json',dict(passed=True,cases=len(checks),checks=checks))
    print('Passed',len(checks),'navigation checks',flush=True)
