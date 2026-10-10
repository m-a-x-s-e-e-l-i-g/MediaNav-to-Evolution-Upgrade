"""Interpret original audio-driver init/deinit/retry control flow offline.

PSC setup, object constructors, DMA allocation/init and OS outcomes are explicit
fixtures. Original DMA IRQ-number leaf is linked, with first-low-read stopping.
No native driver, interrupt, scheduling, hardware or unit-memory execution.
"""
import hashlib
import itertools
import json
from pathlib import Path

from inspect_bt_playback import ROOT,source
from inspect_wave_queue import BytesVM,STOP
from inspect_wave_streams import SPECS as STREAMS
from inspect_wave_dma import HAL_HASHES

DEVICE,OUT,IN,VT_OUT,VT_IN=0x57000000,0x57001000,0x57001100,0x57002000,0x57002100
EVENT,THREAD,HANDLER=0x1111,0x2222,0x3333
HOOKS=0x58000000
SPECS={
    "wavedev2_i2s.dll":dict(base=0xc0940000,global_ptr=0xc094a140,
        init=0x7f78,factory=0x8128,init_export=0x20ac,deinit_export=0x20c8,
        deinit=0x7630,leaf=0x81a4,dma=0x83c0,irq=0x8340,thread=0x7ec4,
        hardware=0x8940,min_rate=0x7d14,registry=0x7818,registry_write=0x78a0,
        finish=0x71c0,alloc=0x8bf8,dma_init=0x8be8,hw_intr=0x8bd8,
        connect=0x8bc8,interrupt_init=0x8b68,create_thread=0x8b58,free_chain=0x8b18,
        debug=0x8ab8,new=0x9080,constructor=0x7ddc,object_bytes=0xec,
        output_offset=0xe0,input_offset=0xe4,quantum=4096),
    "wavedev2_i2s2.dll":dict(base=0xc0950000,global_ptr=0xc095a13c,
        init=0x8074,factory=0x8224,init_export=0x210c,deinit_export=0x2128,
        deinit=0x772c,leaf=0x8600,dma=0x84ac,irq=0x842c,thread=0x7fc0,
        hardware=0x878c,min_rate=0x7e10,registry=0x7914,registry_write=0x799c,
        finish=0x72bc,alloc=0x8994,dma_init=0x8984,hw_intr=0x8974,
        connect=0x8964,interrupt_init=0x8904,create_thread=0x88f4,free_chain=0x88b4,
        debug=0x8854,new=0x8e1c,constructor=0x7ed8,object_bytes=0xe8,
        output_offset=0xdc,input_offset=0xe0,quantum=256)}


class LowRead(Exception):
    def __init__(self,at,size,pc):self.record=dict(address=hex(at),bytes=size,pc=hex(pc))


class LifetimeVM(BytesVM):
    def __init__(self,*args,**kwargs):
        super().__init__(*args,**kwargs);self.executing=False

    def read(self,at,size=4):
        if self.executing and at<0x10000:raise LowRead(at,size,self.pc)
        return super().read(at,size)

    def run(self,*args,**kwargs):
        self.executing=True
        try:return super().run(*args,**kwargs)
        finally:self.executing=False


class Driver:
    def __init__(self,pe,spec,hal_pe,hal_base):
        self.pe,self.spec,self.hal_pe,self.hal_base=pe,spec,hal_pe,hal_base
        self.mem,self.events={},[]
        self.allocated=[OUT,IN];self.inited=[1,1];self.alloc_index=0;self.init_index=0
        self.connect=0x44;self.event=EVENT;self.interrupt_init=1;self.thread=THREAD
        self.priority=1;self.hardware=1;self.chain_release=1;self.new_result=DEVICE
        self.ranges=[(spec["base"]+spec[k],spec["base"]+spec[k]+size) for k,size in
            (("init",432),("factory",124),("init_export",28),("deinit_export",32),
             ("deinit",84),("leaf",8),("dma",128),("irq",128),("thread",180))]
        vm=self.vm();vm.write(VT_OUT+0x18,HOOKS);vm.write(VT_IN+0x18,HOOKS)
        vm.write(DEVICE+0x20,VT_OUT);vm.write(DEVICE+0x50,VT_IN)
        vm.write(OUT+0xc,0);vm.write(IN+0xc,1)

    def record(self,kind,result,machine=None):
        item=dict(kind=kind,result=result)
        if machine:item["args"]=list(machine.reg[4:8])
        self.events.append(item);return result

    def vm(self):
        s=self.spec;b=s["base"];vm=LifetimeVM(self.pe,self.ranges,self.mem)
        def alloc(machine):
            result=self.allocated[self.alloc_index];self.alloc_index+=1
            return self.record("dma_alloc",result,machine)
        def init(machine):
            result=self.inited[self.init_index];self.init_index+=1
            return self.record("dma_init",result,machine)
        def hw_intr(machine):
            nested=LifetimeVM(self.hal_pe,[(self.hal_base+0x4198,self.hal_base+0x41a8)],self.mem)
            nested.reg[4]=machine.reg[4];nested.reg[29]=0x6c000000
            nested.run(self.hal_base+0x4198,{STOP})
            return self.record("dma_irq_number",nested.reg[2],machine)
        def registry(machine):return self.record("registry_read",machine.reg[6],machine)
        def object_new(machine):
            assert machine.reg[4]==s["object_bytes"]
            return self.record("object_new",self.new_result,machine)
        hooks={"alloc":alloc,"dma_init":init,"hw_intr":hw_intr,
            "hardware":lambda m:self.record("psc_setup",self.hardware,m),
            "min_rate":lambda m:self.record("min_rate_read",0,m),"registry":registry,
            "registry_write":lambda m:self.record("registry_write",0,m),
            "finish":lambda m:self.record("finish_setup",0,m),
            "connect":lambda m:self.record("interrupt_connect",self.connect,m),
            "interrupt_init":lambda m:self.record("interrupt_initialize",self.interrupt_init,m),
            "create_thread":lambda m:self.record("create_thread",self.thread,m),
            "free_chain":lambda m:self.record("free_chain",self.chain_release,m),
            "debug":lambda m:self.record("debug",0,m),"new":object_new,
            "constructor":lambda m:self.record("constructor_fixture",DEVICE,m)}
        for key,hook in hooks.items():vm.hooks[b+s[key]]=hook
        vm.hooks[HOOKS]=lambda m:self.record("set_sample_rate",1,m)
        vm.write(b+0xa058,HOOKS+4);vm.hooks[HOOKS+4]=lambda m:self.record("create_event",self.event,m)
        vm.write(b+0xa04c,HOOKS+8);vm.hooks[HOOKS+8]=lambda m:self.record("set_priority",self.priority,m)
        return vm

    def call(self,key,*args):
        vm=self.vm();vm.reg[4:8]=list(args)+[0]*(4-len(args))
        vm.run(self.spec["base"]+self.spec[key],{STOP})
        return vm.reg[2]

    def state(self):
        vm=self.vm();s=self.spec
        return dict(global_device=vm.read(s["global_ptr"]),initialized=vm.read(DEVICE+0x18),
            output_channel=vm.read(DEVICE+s["output_offset"]),input_channel=vm.read(DEVICE+s["input_offset"]),
            sysintr=vm.read(DEVICE+0xac),chain=vm.read(DEVICE+0xb0),
            event=vm.read(DEVICE+0xb4),thread=vm.read(DEVICE+0xb8))


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources,pes,hals=[],{},{}
    for name,digest in HAL_HASHES.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert module["sha256"]==digest
        base=0x40230000 if name=="ceddk.dll" else 0xc0420000
        item,pe=source(module,[base+0x4198],{base+0x4198:16})
        sources.append(item);hals[name]=(pe,base)
    import_records=[]
    for name,s in SPECS.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert module["sha256"]==STREAMS[name]["sha256"]
        keys=("init","factory","init_export","deinit_export","deinit","leaf","dma","irq","thread")
        vas=[s["base"]+s[k] for k in keys]
        item,pe=source(module,vas,{s["base"]+s["leaf"]:8});sources.append(item);pes[name]=pe
        imports=[dict(dll=entry.dll.decode(),name=imp.name.decode() if imp.name else f"ordinal:{imp.ordinal}")
            for entry in pe.DIRECTORY_ENTRY_IMPORT for imp in entry.imports]
        assert not any(i["name"]=="HalFreeDMAChannel" for i in imports)
        import_records.append(dict(module=name,imports=imports,has_hal_free_import=False,
            scope="Direct PE import inventory, not proof no indirect resolution exists anywhere"))
    initialization,deinit,retries,linked=[],[],[],[]
    for name,s in SPECS.items():
        pe=pes[name];hp,hb=hals["k.ceddk.dll"]
        for allocated,inited,connect,event,irq,thread,priority in itertools.product(
            ((OUT,IN),(0,IN),(OUT,0)),((1,1),(0,1),(1,0),(0,0)),
            (0,0x44),(0,EVENT),(0,1),(0,THREAD),(0,1)):
            d=Driver(pe,s,hp,hb);d.allocated=list(allocated);d.inited=list(inited)
            d.connect,d.event,d.interrupt_init,d.thread,d.priority=connect,event,irq,thread,priority
            low=None
            try:result=d.call("init",DEVICE,0x12345678)
            except LowRead as error:low=error.record;result=None
            if not all(allocated):
                assert low and low["address"]=="0xc"
                assert not any(e["kind"]=="interrupt_connect" for e in d.events)
            else:
                assert low is None and result==int(bool(event and thread))
                assert d.state()["initialized"]==result
                if event:assert any(e["kind"]=="interrupt_initialize" for e in d.events)
                if not event:assert not any(e["kind"]=="create_thread" for e in d.events)
            initialization.append(dict(module=name,allocated=list(allocated),dma_init_returns=list(inited),
                connect_return=connect,event_return=event,interrupt_initialize_return=irq,
                thread_return=thread,priority_return=priority,result=result,first_low_read=low,
                state=d.state(),events=d.events))
        for initialized,chain,release in itertools.product((0,1),(0,HANDLER),(0,1)):
            d=Driver(pe,s,hp,hb);vm=d.vm();vm.write(s["global_ptr"],DEVICE)
            vm.write(DEVICE+0x18,initialized);vm.write(DEVICE+0xb0,chain)
            vm.write(DEVICE+0xb4,EVENT);vm.write(DEVICE+0xb8,THREAD)
            vm.write(DEVICE+0xac,0x44);vm.write(DEVICE+s["output_offset"],OUT)
            vm.write(DEVICE+s["input_offset"],IN);d.chain_release=release
            before=d.state();assert d.call("deinit_export")==1;after=d.state()
            assert after==dict(before,chain=0)
            assert [e["kind"] for e in d.events]==(["free_chain"] if chain else [])
            deinit.append(dict(module=name,chain_release_return=release,before=before,after=after,events=d.events))
        for failure in ("psc","event","thread","none","new"):
            d=Driver(pe,s,hp,hb)
            if failure=="psc":d.hardware=0
            if failure=="event":d.event=0
            if failure=="thread":d.thread=0
            if failure=="new":d.new_result=0
            first=d.call("init_export",0x12345678);before=d.state();before_events=len(d.events)
            second=d.call("init_export",0x12345678);after=d.state()
            expected=int(failure=="none")
            assert first==expected
            assert second==(0 if failure=="new" else 1)
            if failure!="new":assert after==before and len(d.events)==before_events
            retries.append(dict(module=name,injected_first_failure=failure,first_result=first,
                retry_result=second,after_first=before,after_retry=after,
                retry_events=d.events[before_events:],events=d.events))
        d=Driver(pe,s,hp,hb);assert d.call("init_export",0x12345678)==1
        d.vm().write(DEVICE+0xb0,HANDLER)
        before=d.state();assert d.call("deinit_export")==1;after=d.state()
        before_events=len(d.events);assert d.call("init_export",0x12345678)==1
        assert d.state()==after==dict(before,chain=0) and len(d.events)==before_events
        linked.append(dict(module=name,before_deinit=before,after_deinit=after,
            after_reinit=d.state(),events=d.events))
        # The user-DDK and kernel-DDK IRQ leaf independently agree on ordinary slots.
        for hn,(p,b) in hals.items():
            for slot in range(16):
                vm=LifetimeVM(p,[(b+0x4198,b+0x41a8)]);vm.write(OUT+0xc,slot)
                vm.reg[4]=OUT;vm.run(b+0x4198,{STOP});assert vm.reg[2]==0xa0+slot
    evidence=dict(sources=sources,imports=import_records,
        producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        dependency_sha256={n:hashlib.sha256((ROOT/"tools"/n).read_bytes()).hexdigest()
            for n in ("inspect_wave_queue.py","inspect_bt_lifecycle.py","inspect_wave_dma.py","inspect_wave_streams.py")},
        checks=dict(original_ranges=sum(len(s["ranges"]) for s in sources),
            initialization_cases=len(initialization),deinit_cases=len(deinit),retry_sequences=len(retries),
            init_deinit_reinit_sequences=len(linked),dma_irq_leaf_cases=64),
        initialization=initialization,deinit=deinit,retry=retries,linked=linked,native_execution=False,
        limitations=["PSC/constructor/registry/format-setters/finish and OS/DMA alloc/init outcomes are fixtures",
            "NULL DMA cases stop at first original IRQ-leaf read at 0xc; no native fault aftermath",
            "Injected DMA init FALSE is a caller-contract case, not proof valid selector fails normally",
            "No live IRQ thread, handler scheduler, device-manager unload or process/kernel cleanup",
            "No actual unit deinit incidence, handle leak or failure-frequency measurement"])
    out=ROOT/"analysis/firmware/wave-lifetime";out.mkdir(parents=True,exist_ok=True)
    (out/"contracts.json").write_text(json.dumps(evidence,indent=2),encoding="utf-8")
    lines=[]
    for item in sources:
        ranges=[(int(r["va"],16),int(r["va"],16)+r["bytes"]) for r in item["ranges"]]
        lines.append(f"; {item['module']} {item['sha256']}\n")
        for line in (ROOT/"analysis/disassembly/rom"/(item["module"]+".asm")).read_text(encoding="utf-8").splitlines(keepends=True):
            try:at=int(line[:8],16)
            except ValueError:continue
            if any(lo<=at<hi for lo,hi in ranges):lines.append(line)
    (out/"reviewed-paths.asm").write_text("".join(lines),encoding="utf-8")
    print(json.dumps(dict(status="passed",**evidence["checks"]),indent=2))


if __name__=="__main__":main()
