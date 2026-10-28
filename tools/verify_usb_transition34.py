"""Run packaged USB instructions with stateful COM, time and ownership fixtures.

The renderer/codec and CE APIs are simulated. These checks do not prove car audio.
"""
import argparse,hashlib,itertools,json,struct
from pathlib import Path
import pefile
from patch_usb_transition34 import patch,POLL,CAPACITY
from patch_shared_mapping_checks import reloc_records
from verify_usb_graph_state import (Graph,INTERMEDIATE,E_FAIL,CANT_CUE,OBJECT,
    INSTANCE,CONTROL,VTABLE,API,GATES)
from verify_usb_graph_init import Initialization
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put
from verify_media_responsiveness import call


class Pending(Graph):
    def __init__(self,raw,pending_state=1,command_completes=True,**kwargs):
        super().__init__(raw,**kwargs)
        self.pending_state=pending_state;self.command_completes=command_completes
    def get_state(self,m):
        commands=self.summary()['commands']
        if not commands or not self.command_completes:self.samples=[(INTERMEDIATE,self.pending_state)]
        elif commands[-1]=='Stop':self.samples=[(0,0)]
        else:self.samples=[(0,1)]
        return super().get_state(m)


class Player(Initialization):
    def __init__(self,raw,debug=False,**kwargs):
        super().__init__(raw,**kwargs);self.pending=False;self.debug=debug;self.debug_events=[]
        # Run actual MAX33 timing wrappers/clones; simulate only their external APIs.
        p=self.vm.pe;d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        # The instrumentation preserves the caller's nine stack argument slots,
        # including unused arguments. They are readable memory on CE.
        put(self.vm,0x67fff000,bytes(0x2000))
        rows=[struct.unpack_from('<5I',p.get_data(d.VirtualAddress,d.Size),i)for i in range(0,d.Size,20)]
        self.vm.ranges.extend((r[0],r[1])for r in rows)
        self.vm.hooks[0x2511c+self.delta]=self.log
        self.vm.write(VTABLE+0x1c,API+0x200);self.vm.hooks[API+0x200]=self.start
        # External media-status notification after Run; no audio is simulated.
        self.vm.hooks[0x1ed94+self.delta]=lambda m:0
        for desc in p.DIRECTORY_ENTRY_IMPORT:
            for imp in desc.imports:
                if imp.ordinal in (516,517):
                    target=0xf0700000+imp.ordinal*4
                    self.vm.write(imp.address,target);self.vm.hooks[target]=lambda m:0
                elif imp.name==b'DbgDebugPrint':
                    target=0xf0704000;self.vm.write(imp.address,target);self.vm.hooks[target]=self.diagnostic
    def diagnostic(self,m):
        op=m.reg[4]&255;self.debug_events.append(op)
        self.clobber(m);return int(self.debug)if op==3 else 0
    def get_state(self,m):
        if self.pending:self.samples=[(INTERMEDIATE,1)]
        return super().get_state(m)
    def stop(self,m):
        result=super().stop(m)
        if not result&0x80000000:self.pending=False;self.samples=[(0,0)]
        return result
    def mute(self,m):
        assert m.reg[4]==self.pointers[0x14]and m.reg[5]in (0,(-10000)&0xffffffff)
        self.events.append(dict(api='Unmute'if m.reg[5]==0 else'Mute'));self.clobber(m);return 0
    def start(self,m):
        assert m.reg[4]==CONTROL
        self.events.append(dict(api='Run'));self.clobber(m);return 0
    def run_play(self):
        return call(self.vm,0x114a0+self.delta,[OBJECT],limit=200000)


def verify(original,candidate,recipe):
    checks=[]
    def record(name,g=None):
        checks.append(dict(name=name,**(g.summary()if g else {})))
    old=Pending(original);assert old.run('stop')==0
    assert old.summary()['commands']==[]and old.clock==5000
    record('Exact MAX33 reproduces timeout without issuing Stop',old)
    for delta in (0,0x1000,0x10000,0x123000):
        raw=relocated(candidate,delta)if delta else candidate
        for mode,state in itertools.product(('stop','pause','real_pause'),(0,1,2)):
            g=Pending(raw,pending_state=state,delta=delta)
            result=g.run(mode)
            if mode=='real_pause'and state==0:
                assert result==0 and g.clock==5000 and not g.summary()['commands']
            else:
                assert result==1 and g.summary()['commands']==(['Pause']if mode=='real_pause'else['Stop'])
                assert g.clock==5 and not g.logs
            record(f'pending target {state} {mode} base+{delta:x}',g)
        for mode in ('stop','pause','real_pause'):
            g=Pending(raw,delta=delta,command_completes=False)
            assert g.run(mode)==0 and g.logs[-1][2]==3 and g.clock==5000
            assert len(g.summary()['commands'])==1 and not g.released and not g.seeks
            assert g.vm.read(OBJECT+0x24)==2
            record(f'command never completes: bounded {mode} base+{delta:x}',g)
            g=Pending(raw,delta=delta,action_hr=E_FAIL)
            assert g.run(mode)==0 and g.logs[-1][2]==4 and not g.released and not g.seeks
            record(f'command HRESULT failure retains state {mode} base+{delta:x}',g)
            for samples in (((E_FAIL,0),),((0,99),),((0,None),),((123,0),)):
                g=Graph(raw,samples=samples,delta=delta)
                assert g.run(mode)==0 and not g.released and not g.seeks
                record(f'invalid/failed GetState {samples} {mode} base+{delta:x}',g)
        for mode,samples,commands in [
            ('stop',((0,2),(0,1),(0,0)),['Pause','Stop']),
            ('pause',((0,2),(0,1),(0,0)),['Pause','Stop']),
            ('real_pause',((0,2),(0,1)),['Pause']),
            ('stop',((CANT_CUE,1),(0,0)),['Stop']),
            ('real_pause',((CANT_CUE,1),),[])]:
            g=Graph(raw,samples=samples,delta=delta);assert g.run(mode)==1
            assert g.summary()['commands']==commands
            record(f'completed native ordering {mode} {samples} base+{delta:x}',g)
        # Once Stop was sent, a stale Running result must not send Pause again.
        g=Graph(raw,samples=((INTERMEDIATE,1),(0,2),(INTERMEDIATE,0),(0,0)),delta=delta)
        assert g.run('stop')==1 and g.summary()['commands']==['Stop']
        record(f'late running observation cannot undo Stop base+{delta:x}',g)
        for mutation in ('during_get','after_mute'):
            g=Graph(raw,delta=delta,mutate=mutation)
            assert g.run('stop')==0 and not g.released and not g.seeks
            record(f'control pointer changed {mutation} base+{delta:x}',g)
            g=Pending(raw,delta=delta,mutate=mutation)
            assert g.run('stop')==0 and not g.summary()['commands']
            assert not g.released and not g.seeks and g.logs[-1][2]==6
            record(f'pending command refuses changed control {mutation} base+{delta:x}',g)
        # Later seek/input patches add helpers to these historical callers.
        # Keep their exact packaged instructions; the complete LoadFile path is
        # executed below instead of substituting the older caller fixture.
        before=pefile.PE(data=relocated(original,delta)if delta else original)
        after=pefile.PE(data=raw)
        for lo,hi in [(0x40300,0x40e00),(0x11e7c,0x12444),(0x1d880,0x1dacc),(0x20be4,0x20e88)]:
            assert before.get_data(lo-0x10000,hi-lo)==after.get_data(lo-0x10000,hi-lo)
            record(f'preserve packaged caller/cleanup instructions {lo:x}..{hi:x} base+{delta:x}')
        for debug in (False,True):
            g=Player(raw,delta=delta,debug=debug)
            assert g.run_load()==1 and g.live()==6
            assert g.run_play()==1 and g.vm.read(OBJECT+0x24)==2
            # Each new track enters with an uncued previous graph, as in issue66.
            for track in range(8):
                g.pending=True
                assert g.run_load()==1 and g.live()==6
                assert g.run_play()==1 and g.vm.read(OBJECT+0x24)==2
                assert len(g.released)==6*(track+1) and not g.lock_depth
            assert g.summary()['commands']==['Stop']*8
            if debug:assert 4 in g.debug_events
            record(f'eight track selections release/recreate graph, debugging={debug}, base+{delta:x}',g)
            g.fail='render';g.pending=True
            assert g.run_load()==3 and g.live()==0
            g.fail=None;assert g.run_load()==1 and g.live()==6
            record(f'actual decoder failure remains failure; next retry works, debugging={debug}, base+{delta:x}',g)
    a,b=pefile.PE(data=original),pefile.PE(data=candidate)
    assert a.OPTIONAL_HEADER.SizeOfImage==b.OPTIONAL_HEADER.SizeOfImage
    assert [s.__pack__()for s in a.sections]==[s.__pack__()for s in b.sections]
    assert len(reloc_records(a))==len(reloc_records(b))
    record('No binary growth, added imports, data allocation or loader sections')
    return dict(passed=True,cases=len(checks),checks=checks,car_tested=False,
        input_sha256=hashlib.sha256(original).hexdigest(),output_sha256=hashlib.sha256(candidate).hexdigest(),
        limits='Actual packaged MIPS entry/wrapper/LoadFile/teardown instructions; simulated COM/registry/clock/diagnostic APIs. No codec execution or physical audio proof.')


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--baseline',type=Path,required=True);p.add_argument('--out',type=Path,required=True);a=p.parse_args()
    raw=a.baseline.read_bytes();candidate,recipe=patch(raw);report=verify(raw,candidate,recipe)
    a.out.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in report.items()if k!='checks'},indent=2))
