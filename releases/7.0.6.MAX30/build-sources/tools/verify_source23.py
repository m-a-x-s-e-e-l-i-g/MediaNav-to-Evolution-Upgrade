"""Execute candidate and predecessor native playback/fade paths against clocks.

CE, IPC and GUI calls are explicit boundaries; no hardware speed is inferred.
"""
import json,struct
from pathlib import Path
from verify_max21 import fixture,call,STACK
from verify_max20 import VM
from verify_usb_input_safety import relocated
from package_max16 import write

ROOT=Path(__file__).resolve().parents[1]


def clock_vm(raw,on=0,now=5000,delta=0):
    if delta:
        p=VM(raw).pe;data=bytearray(relocated(raw,delta))
        struct.pack_into('<I',data,p.OPTIONAL_HEADER.get_field_absolute_offset('ImageBase'),p.OPTIONAL_HEADER.ImageBase+delta)
        raw=bytes(data)
    m,last,_,records=fixture(raw,on);clock=[now];sleeps=[];m.sleep_ends=[]
    for at in range(STACK-0x500,STACK+0x100,4):m.write(at,0)
    for d in m.pe.DIRECTORY_ENTRY_IMPORT:
        for s in d.imports:
            if s.ordinal==535:m.hooks[m.read(s.address)]=lambda v:clock[0]&0xffffffff
            if s.ordinal==496:
                def sleep(v):
                    assert v.reg[4]<=200
                    sleeps.append(v.reg[4]);clock[0]+=v.reg[4];m.sleep_ends.append(clock[0]);last[0]=321;v.reg[3]=0x4321
                    return 0x1234
                m.hooks[m.read(s.address)]=sleep
    return m,last,records,clock,sleeps


def native_trace(raw,on,overhead,success,now=5000,delta=0,between=0):
    m,last,records,clock,sleeps=clock_vm(raw,on,now,delta)
    mgr,system,dialog,shared=0x62000000,0x63000000,0x64000000,0x65000000
    for at,size in [(mgr,0xb0),(system,0x3000),(dialog,0x2714),(shared,0x100),(0x66000000,0x700)]:
        for k in range(0,size,4):m.write(at+k,0)
    def addr(va):return va+delta
    m.write(addr(0x188270),dialog);m.write(addr(0x187b38),system)
    m.write(addr(0x186ce8),shared);m.write(shared+4,0x2222)
    m.write(mgr+0xa8,0x66000000);m.write(mgr+0xa4,0x67000000)
    m.write(system+0xac,1);m.write(system+0x88,4)
    operations=[];stamp=[]
    def play(v):
        assert v.reg[4:8]==[0x67000000,1,0x01070502,0]
        operations.append(('play',clock[0]));clock[0]+=10
        stamp.append(clock[0]);last[0]=123;v.reg[3]=456
        return 0 if success else 0xffffffff
    m.hooks[addr(0x11b464)]=play
    m.hooks[addr(0x13fef8)]=lambda v:operations.append(('window post',v.reg[5])) or 1
    for d in m.pe.DIRECTORY_ENTRY_IMPORT:
        for s in d.imports:
            target=m.read(s.address)
            if s.name==b'DbgDebugPrint':
                prior=m.hooks[target]
                def dbg(v,prior=prior):
                    if v.reg[4]&0xffffff00==0x4d584400:return prior(v)
                    operations.append(('native log',clock[0]));clock[0]+=overhead
                    return 0
                m.hooks[target]=dbg
            if s.name==b'IpcSendMsg':
                def ipc(v):
                    assert v.reg[4:8]==[21,3,0x8b,4]
                    assert v.read(v.read(v.reg[29]+16))==0
                    operations.append(('fade',clock[0]));clock[0]+=11
                    return 1
                m.hooks[target]=ipc
    if between:
        prior=m.hooks[next(m.read(s.address) for d in m.pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.ordinal==496)]
        target=next(m.read(s.address) for d in m.pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.ordinal==496)
        def sleep_with_scheduler(v):
            result=prior(v)
            if len(sleeps)==1:clock[0]+=between
            return result
        m.hooks[target]=sleep_with_scheduler
    call(m,addr(0x115594),[mgr,22,33,44])
    assert m.read(mgr+8)==1 and m.read(0x66000000+0x650)==1
    assert [x[0] for x in operations].count('play')==1
    assert [x[0] for x in operations].count('fade')==1
    fade=next(t for op,t in operations if op=='fade')
    assert m.sleep_ends[0]-stamp[0]>=200,'First continuation retains 200 ms window'
    assert fade-stamp[0]>=400,'Fade must not precede retained 400 ms settling window'
    return dict(operations=operations,sleeps=sleeps,post_request_to_fade_ms=fade-stamp[0],
                records=records,total_ms=clock[0]-now)


def source_cases(root):
    cases=[];results=[];raw=(root/'AppMain.exe').read_bytes()
    prior=(ROOT/'build/max22-settings-development-03/AppMain.exe').read_bytes()
    recipe=json.loads((root/'AppMain.exe.json').read_bytes());budget=recipe['metrics']['source_budget']
    for on in (0,1):
        for overhead in (0,10,30,100,250):
            for success in (False,True):
                a=native_trace(prior,on,overhead,success)
                b=native_trace(raw,on,overhead,success)
                assert [op for op,_ in a['operations']]==[op for op,_ in b['operations']]
                if success:
                    assert b['post_request_to_fade_ms']==400
                    assert b['total_ms']<=a['total_ms']
                else:assert a==b,'Failed play requests retain original sequence and waits'
                label=f'native play/fade order, minimum elapsed window, on={on}, work={overhead}, success={success}'
                cases.append(label);results.append(dict(case=label,previous=a,candidate=b))
    for delta in (0x10000,0x123000):
        for now in (5000,0xfffffff0):
            for between in (0,70,250):
                trace=native_trace(raw,1,30,True,now,delta,between)
                assert trace['post_request_to_fade_ms']>=400
                assert trace['post_request_to_fade_ms']<=max(400,200+between)
                cases.append(f'native relocated play/fade with tick wrap and scheduler elapsed {delta:x}/{now:x}/{between}')
    for on in (0,1):
        for caller in (0x115728,0x1154b4,0x777777):
            for start in (0,4800,4900,5000,0xfffffff0):
                m,last,records,clock,sleeps=clock_vm(raw,on)
                m.write(STACK+0x20,caller);m.write(STACK+0x3c,start)
                native=m.read(0x18503c)
                at=next(r['wrapper'] for r in budget['waits'] if r['event']==135)
                extra=list(range(100,109));extra[4]=caller
                assert call(m,at,[200,22,33,44],extra=extra,native_target=(8,native))==[0x1234,0x4321]
                expected=min(200,max(0,400-((5000-start)&0xffffffff))) if caller==0x115728 and start else 200
                assert sleeps==[expected]
                assert last[0]==321
                cases.append(f'fade caller ownership and absent timestamp fallback {on}/{caller:x}/{start:x}')
    # The stamp helper must keep native arguments/results/errors and all ABI state.
    for result in (0,1,0xffffffff):
        m,last,records,clock,sleeps=clock_vm(raw)
        def request(v):
            assert v.reg[4:8]==[11,22,33,44]
            assert [v.read(v.reg[29]+16+j*4) for j in range(9)]==list(range(100,109))
            assert last[0]==77;last[0]=123;v.reg[3]=456
            return result
        m.hooks[0x11b464]=request
        assert call(m,budget['stamp_wrapper'])==[result,456] and last[0]==123
        assert m.read(STACK+0x14)==(5000 if result==0 else 0)
        cases.append(f'stamp native arguments, v0/v1, LastError and stack ABI result={result:x}')
    from debug_image import sha
    write(root/'source-budget-verification.json',dict(passed=True,cases=len(cases),checks=cases,
          app_sha256=sha(raw),previous_app_sha256=sha(prior),
          native_trace_comparisons=results,minimum_settling_window_ms=400,
          limits='Interpreter clocks and explicit CE/IPC/GUI boundaries; real audio and speed require car testing.'))
    return cases


if __name__=='__main__':
    import argparse
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True)
    a=p.parse_args();print('Passed',len(source_cases(a.build)),'source checks')
