from verify_max21 import fixture,call,STACK,STOP
from verify_max20 import VM
from pathlib import Path
import json,struct,pefile

def targeted(root):
    cases=[];app=(root/'AppMain.exe').read_bytes();recipe=json.loads((root/'AppMain.exe.json').read_bytes())
    metrics=recipe['metrics'];source=(Path(__file__).resolve().parents[1]/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System/AppMain.exe').read_bytes()
    original=pefile.PE(data=source);p=pefile.PE(data=app)
    for row in metrics['calls']:
        # Original delay-slot operands, including stack stores, stay exact.
        assert p.get_data(row['site']-p.OPTIONAL_HEADER.ImageBase+4,4)==original.get_data(row['original_site']-original.OPTIONAL_HEADER.ImageBase+4,4)
        assert int.from_bytes(p.get_data(row['site']-p.OPTIONAL_HEADER.ImageBase,4),'little')==(3<<26)|((recipe['metrics'].get('source_budget',{}).get('site_wrappers',{}).get(str(row['site']),row['wrapper'])>>2)&0x3ffffff)
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
    r=next(r for r in json.loads((root/'CmnDll.dll.json').read_bytes())['routines'] if r['address']==json.loads((root/'runtime.json').read_bytes())['addresses']['status'])
    status_begin=cp.get_offset_from_rva(r['address']-cp.OPTIONAL_HEADER.ImageBase);status_end=status_begin+r['bytes']
    runtime=json.loads((root/'runtime.json').read_bytes())
    if runtime.get('quiet_logging'):
        from verify_quiet_logging30 import runtime_scope
        runtime_scope(root)
        cases.append('MAX30 logger changes only reviewed quiet routines/header/tables; remaining runtime/imports/state exact')
    else:
        assert len(before)==len(after) and all(n==at or cs<=n<cs+4 or status_begin<=n<status_end for n in differences)
        cases.append('MAX20 runtime differs only in diagnostics header, status notification and checksum')
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
