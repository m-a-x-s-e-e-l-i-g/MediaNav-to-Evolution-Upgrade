"""Actual MIPS tests for lower-volume polling and call-site measurement contracts."""
import argparse,json,struct
from pathlib import Path
import pefile
import verify_max19 as legacy
from verify_max20 import Fixture,VM,regression_cases
from package_max16 import write
from debug_runtime20 import MAGIC

STACK=legacy.STACK
STOP=legacy.STOP


def fixture(raw,on=1,duration=7):
    m=VM(raw);last=[77];tick=[5000];records=[]
    for d in m.pe.DIRECTORY_ENTRY_IMPORT:
        for s in d.imports:
            target=0xf4000000+len(m.hooks)*16;m.write(s.address,target)
            if s.ordinal==516:fn=lambda v:last[0]
            elif s.ordinal==517:fn=lambda v:last.__setitem__(0,v.reg[4]) or 0
            elif s.ordinal==535:
                def clock(v):r=tick[0];tick[0]+=duration;return r
                fn=clock
            elif s.ordinal==88:
                def memory(v):
                    assert v.read(v.reg[4])==32
                    for j,value in enumerate([32,50,0,104857600,0,0,0,0]):v.write(v.reg[4]+j*4,value)
                    last[0]=88;return 0
                fn=memory
            elif s.ordinal==10:
                def increment(v):r=(v.read(v.reg[4])+1)&0xffffffff;v.write(v.reg[4],r);last[0]=10;return r
                fn=increment
            elif s.name==b'DbgDebugPrint':
                def dbg(v):
                    if v.reg[4]==MAGIC+3:return on
                    if v.reg[4]==MAGIC+4:
                        records.append((v.reg[5],v.reg[6],v.reg[7],v.read(v.reg[29]+16)))
                        return 1
                    return 1
                fn=dbg
            else:fn=lambda v:0
            m.hooks[target]=fn
    return m,last,tick,records


def call(m,at,args=(11,22,33,44),extra=tuple(range(100,109)),native_target=None):
    m.reg[4:8]=list(args);m.reg[29]=STACK;m.reg[31]=STOP
    for j,v in enumerate(extra):m.write(STACK+16+4*j,v)
    for r in range(16,24):m.reg[r]=0xaaaa0000+r
    if native_target is not None:
        reg,value=native_target;m.reg[reg]=value
    m.run(at,{STOP},100000)
    assert m.reg[29]==STACK and m.reg[31]==STOP
    assert all(m.reg[r]==0xaaaa0000+r for r in range(16,24))
    return m.reg[2:4]


def targeted(root):
    cases=[];app=(root/'AppMain.exe').read_bytes();recipe=json.loads((root/'AppMain.exe.json').read_bytes())
    metrics=recipe['metrics'];source=(Path(__file__).resolve().parents[1]/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System/AppMain.exe').read_bytes()
    original=pefile.PE(data=source);p=pefile.PE(data=app)
    for row in metrics['calls']:
        # Original delay-slot operands, including stack stores, stay exact.
        assert p.get_data(row['site']-p.OPTIONAL_HEADER.ImageBase+4,4)==original.get_data(row['original_site']-original.OPTIONAL_HEADER.ImageBase+4,4)
        assert int.from_bytes(p.get_data(row['site']-p.OPTIONAL_HEADER.ImageBase,4),'little')==(3<<26)|((row['wrapper']>>2)&0x3ffffff)
    cases.append('all phase call sites keep original delay slots and point to intended wrappers')
    rows={r['wrapper']:r for r in metrics['calls']}.values()
    for row in rows:
        for on in [0,1]:
            m,last,tick,records=fixture(app,on);target=row['target'] or 0xf5000000
            def native(v):
                assert v.reg[4:8]==[11,22,33,44]
                assert [v.read(v.reg[29]+16+j*4) for j in range(9)]==list(range(100,109))
                assert last[0]==77;last[0]=1234;v.reg[3]=0x4321
                return 0x1234
            m.hooks[target]=native
            reg={'t0':8,'t1':9,'t9':25}.get(row['target_register'])
            result=call(m,row['wrapper'],native_target=(reg,target) if reg is not None else None)
            assert result==[0x1234,0x4321] and last[0]==1234
            assert len(records)==on
            if on:
                assert records[0][1]==row['event'] and records[0][3]==(11 if row['result_is_argument0'] else 0x1234)
                if row['counter_offset'] is not None:assert m.read(metrics['state_va']+row['counter_offset'])==1
            else:
                assert tick[0]==5000 and m.read(metrics['state_va'])==0 and m.read(metrics['state_va']+4)==0
            cases.append(row['label']+' original arguments, target, v0/v1, error and ABI on='+str(on))
    # Failed GDI calls must not increase successful-operation counters.
    for row in [r for r in rows if r['counter_offset'] is not None]:
        m,last,tick,records=fixture(app);m.hooks[row['target']]=lambda v:0
        call(m,row['wrapper']);assert m.read(metrics['state_va']+row['counter_offset'])==0
        assert records[0][3]==0;cases.append(row['label']+' failed call is recorded without increasing counter')
    m,last,tick,records=fixture(app);call(m,metrics['memory_helper'],[902,0,0,0])
    assert records==[(1,902,104857600,50),(1,904,0,0)]
    cases.append('artwork memory and bitmap counts encode global RAM and counters distinctly')
    blue=(root/'Blue.exe').read_bytes();br=json.loads((root/'Blue.exe.json').read_bytes())
    poll=next(r for r in br['events'] if r['event']==301)
    for on,result,duration,expected in [(0,0,5,0),(1,0,5,0),(1,1,5,1),(1,2,5,1),(1,0,25,1)]:
        m,last,tick,records=fixture(blue,on,duration)
        def native(v):last[0]=1234;v.reg[3]=123;return result
        m.hooks[poll['clone']]=native
        assert call(m,poll['wrapper'])==[result,123] and last[0]==1234
        assert len(records)==expected
        if expected:assert records[0][1]==301 and records[0][3]==result
        cases.append('poll idle/changed/retry/slow/disabled '+str((on,result,duration)))
    m,last,tick,records=fixture(blue,1,1)
    def idle(v):v.reg[3]=0;return 0
    m.hooks[poll['clone']]=idle
    for n in range(120):
        tick[0]=5000+n*500;call(m,poll['wrapper'])
    assert len(records)==5 and all(r[1]==302 for r in records)
    assert sum(r[2] for r in records)==101 and all(r[3]==1 for r in records)
    cases.append('120 idle polls become five periodic summaries instead of 240 records')
    # MAX20 persistence/writer/Settings operate unchanged. Cmn emitted instructions
    # are byte-exact; only one UTF16 header character and checksum may change.
    before=(Path(__file__).resolve().parents[1]/'build/max20-debugging-development-04/CmnDll.dll').read_bytes()
    after=(root/'CmnDll.dll').read_bytes();cp=pefile.PE(data=after)
    differences=[n for n,(a,b) in enumerate(zip(before,after)) if a!=b]
    cs=cp.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    text='\ufeffMAXmade 7.0.6.MAX20 diagnostics'.encode('utf-16-le');at=before.index(text)+text.index('0'.encode('utf-16-le'),len('\ufeffMAXmade 7.0.6.MAX2'.encode('utf-16-le')))
    assert len(before)==len(after) and all(n==at or cs<=n<cs+4 for n in differences)
    cases.append('entire MAX20 runtime remains byte-exact except diagnostic version and PE checksum')
    from analyze_debug_logs21 import analyze
    sample=root/'metrics-fixture-logs';sample.mkdir(exist_ok=True)
    lines=['\ufeffMAXmade 7.0.6.MAX21 diagnostics','ms\tmodule\tevent\tduration_ms\tresult\tlevel\tmessage','session\t2026-10-14T00:00:00.000\t0',
           '10\t3\t302\t20\t5\t0\t','11\t1\t902\t104857600\t50\t0\t','12\t1\t904\t5\t4\t0\t','13\t1\t325\t206\t0\t0\t']
    path=sample/'debug-fixture.log';path.write_bytes(('\r\n'.join(lines)+'\r\n').encode('utf-16-le'))
    s=analyze([path])['sessions'][0]
    assert len(s['timings'])==1 and s['timings'][0]['event']==325
    assert s['artwork_poll_summaries'][0]['poll_count']==20 and s['artwork_bitmap_counters'][0]['deleted']==4
    assert s['artwork_memory_snapshots'][0]['free_bytes']==104857600
    cases.append('analyzer separates counters, memory and measured durations')
    return cases


def native_lifetime_cases(root):
    """Execute original ownership bodies through new wrappers, not just stubs."""
    cases=[];app=(root/'AppMain.exe').read_bytes()
    for success in [0,1]:
        m,last,tick,records=fixture(app);deleted=[]
        for at in range(STACK-0x300,STACK+0x80,4):m.write(at,0)
        m.write(0x300034,0x7777);m.write(0x300038,4);m.write(0x30003c,5)
        def delete(v):deleted.append(v.reg[4]);return success
        m.hooks[0x140138]=delete
        call(m,0x233800)
        assert deleted==[0x7777] and all(m.read(0x300034+j*4)==0 for j in range(3))
        assert m.read(0x214d04)==success and records[-1][1:]==(327,7,success)
        cases.append('native GUI bitmap retirement remains unchanged and records delete result '+str(success))
    baseline=Path(__file__).resolve().parents[1]/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System/Blue.exe'
    candidate=(root/'Blue.exe').read_bytes()
    for pending,pointer,fresh,publish in [(0,0,0,0),(1,0,0,0),(1,1,0,0),(1,1,1,1),(1,1,1,2)]:
        results=[]
        for raw in [baseline.read_bytes(),candidate]:
            m,last,tick,records=fixture(raw);desc=0x65030000
            m.write(0x300448,pending);m.write(0x300440,desc if pointer else 0)
            for j,value in enumerate([77,88,99,100]):m.write(desc+j*4,value)
            actions=[]
            m.hooks[0x25a000]=lambda v:5000
            m.hooks[0x27bc00]=lambda v:fresh
            m.hooks[0x279800]=lambda v:publish
            def release(v):
                actions.append(v.reg[4]);m.write(0x300448,0);m.write(0x300440,0);return 0
            m.hooks[0x280000]=release
            result=call(m,0x280400)
            results.append((result[0],m.read(0x300448),m.read(0x300440),m.read(0x30044c),m.read(0x300450),actions))
        assert results[0]==results[1]
        cases.append('actual native Blue publication/ack/retry/cleanup parity '+str((pending,pointer,fresh,publish)))
    return cases


def main():
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args()
    legacy.Fixture=Fixture;legacy.VM=VM
    from verify_clients21 import client_cases
    from verify_settings20 import settings_cases
    cases=[]
    for name,fn in [('runtime/writer',legacy.core_cases),('PE integrity',legacy.image_checks),
                    ('inherited event ABI',client_cases),('Settings',settings_cases),
                    ('inline source switch',legacy.switch_table_cases),('navigation',legacy.inherited_cases),
                    ('persistence and file preservation',regression_cases),('new performance metrics',targeted),
                    ('native artwork lifetime',native_lifetime_cases)]:
        print('Checking '+name,flush=True);cases+=fn(a.build)
    result=dict(passed=True,cases=len(cases),checks=cases,firmware_executed_natively=False,
                limits=['CE APIs, memory totals, clocks and filesystem are explicit fixtures; car performance and memory ownership remain unverified.'])
    write(a.build/'verification.json',result);print('Passed '+str(len(cases))+' checks')


if __name__=='__main__':main()
