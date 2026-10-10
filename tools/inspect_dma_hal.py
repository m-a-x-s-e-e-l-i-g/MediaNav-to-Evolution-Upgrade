"""Interpret original CE DDMA control instructions with explicit OS/MMIO fixtures.

No native firmware, DMA or MMIO execution. Failed descriptor/mapping allocation
stops at the first low virtual target, rather than pretending the unit succeeds.
"""
import hashlib
import itertools
import json
import struct
from pathlib import Path

from inspect_bt_playback import ROOT, source
from inspect_wave_queue import BytesVM, STOP, HASHES as WAVE_HASHES
from inspect_wave_dma import HAL_HASHES, SPECS as DRIVER_SPECS
from inspect_wave_streams import SPECS as STREAM_SPECS

CH, PCM, DESC, REGS, MAP = 0x51000000, 0x52000000, 0x53000000, 0x54000000, 0x55000000
PHYS_PCM, PHYS_DESC = 0x02000000, 0x03000000
HOOKS = 0x56000000
OFFSETS = {"config": (0x326c,0x35d8), "allocate": (0x35d8,0x3724),
           "free": (0x3778,0x3818), "init": (0x3a2c,0x3c98),
           "next": (0x3c98,0x3e68), "activate": (0x3e68,0x3f24),
           "start": (0x3f24,0x3f84), "stop": (0x3f84,0x4058),
           "check": (0x4058,0x40fc), "ack": (0x40fc,0x4154)}
VALID_SELECTORS = [0,1,4,5,12,13,14,15,18,19,20,21,23,24]


class LowTarget(Exception):
    def __init__(self, kind, at, value, pc):
        self.record=dict(kind=kind,address=hex(at),value=hex(value),pc=hex(pc))


class HalVM(BytesVM):
    def __init__(self,*args,**kwargs):
        super().__init__(*args,**kwargs)
        self.executing=False

    def write(self,at,value,size=4):
        if self.executing and at<0x10000: raise LowTarget("low_data_store",at,value,self.pc)
        super().write(at,value,size)

    def plain(self,w):
        op,rs,rt=w>>26,(w>>21)&31,(w>>16)&31
        signed=lambda n: n if n<0x80000000 else n-0x100000000
        if op==0 and w&63 in (2,0x2a):
            rd=(w>>11)&31
            self.reg[rd]=(self.reg[rt]>>((w>>6)&31) if w&63==2
                          else int(signed(self.reg[rs])<signed(self.reg[rt])))
            self.reg[0]=0
        elif op==0xa:
            imm=w&65535; imm=imm if imm<32768 else imm-65536
            self.reg[rt]=int(signed(self.reg[rs])<imm); self.reg[0]=0
        else: super().plain(w)

    def run(self,*args,**kwargs):
        self.executing=True
        try: return super().run(*args,**kwargs)
        finally: self.executing=False


class HAL:
    def __init__(self,pe,base,core_pe,selector=12,quantum=4096):
        self.pe,self.base,self.core_pe,self.quantum=pe,base,core_pe,quantum
        self.mem,self.ports,self.events,self.allocations={},{},[],{}
        self.fail_allocations=set();self.mapping_result=MAP
        self.status_sequence=None;self.wait_result=0;self.mutex_attempt=0;self.busy_channels=0
        self.fail_mutex_at=None;self.fail_local_alloc=False;self.phys_attempt=0
        self.ranges=[(base+a,base+b) for a,b in OFFSETS.values()]
        vm=self.vm()
        raw=pe.get_data(base+0x80f4-pe.OPTIONAL_HEADER.ImageBase,0x36c)
        for i,b in enumerate(raw): vm.write(base+0x80f4+i,b,1)
        self.call("config")
        self.runtime_config=[[vm.read(base+0x813c+i*32+j*4) for j in range(8)] for i in range(25)]
        assert [i for i,r in enumerate(self.runtime_config) if r[0]]==VALID_SELECTORS
        vm.write(CH+0x18,base+0x813c+selector*32)
        vm.write(CH+0x60,self.runtime_config[selector][7]); vm.write(CH+0x24,REGS)
        vm.write(CH+0x28,PCM); vm.write(CH+0x2c,PCM+quantum)
        vm.write(CH+0x40,DESC); vm.write(CH+0x44,DESC+64)
        vm.write(CH+0x48,PHYS_DESC); vm.write(CH+0x50,PHYS_DESC+64)
        vm.write(CH+0x84,PHYS_DESC); vm.write(CH+0x58,1);vm.write(CH+0x5c,1)
        vm.write(CH+0x10,quantum);vm.write(CH+0x14,0xabcd)
        self.ports.update({REGS:1,REGS+4:PHYS_DESC,REGS+0x14:1,DESC:0,DESC+64:0})
        self.events.clear()

    def vm(self):
        vm=HalVM(self.pe,self.ranges,self.mem);vm.reg[29]=0x6e000000
        def read_port(machine):
            at=machine.reg[4]
            if at==REGS+0x14 and self.status_sequence is not None:
                values=self.status_sequence
                value=values.pop(0) if len(values)>1 else values[0]
            else:value=self.ports.get(at,0)
            self.events.append(dict(kind="read_port",address=hex(at),value=hex(value)))
            return value
        def write_port(machine):
            at,value=machine.reg[4:6]
            if at<0x10000:raise LowTarget("low_port_write",at,value,machine.pc)
            self.ports[at]=value
            self.events.append(dict(kind="write_port",address=hex(at),value=hex(value)))
            return 0
        vm.hooks[self.base+0x2bbc]=read_port;vm.hooks[self.base+0x2be8]=write_port
        vm.hooks[self.base+0x6978]=lambda _vm:self.events.append(dict(kind="debug_log")) or 0
        vm.hooks[self.base+0x3994]=lambda _vm:self.events.append(dict(kind="diagnostic_dump")) or 0
        vm.hooks[self.base+0x6a48]=lambda machine:self.events.append(dict(kind="cache_sync",flags=machine.reg[4])) or 0
        def mapping(machine):
            assert machine.reg[4:8]==[0x14002000,0,0x1010,0]
            self.events.append(dict(kind="map",result=hex(self.mapping_result)))
            return self.mapping_result
        vm.hooks[self.base+0x2360]=mapping
        def phys_alloc(machine):
            index=self.phys_attempt; self.phys_attempt+=1
            virtual,physical=(PCM,PHYS_PCM) if index==0 else (DESC,PHYS_DESC)
            if index in self.fail_allocations: virtual=physical=0
            out=machine.read(machine.reg[29]+0x10)
            assert machine.reg[5:8]==[0x204,0x20,0]
            machine.write(out,physical)
            if virtual:self.allocations[virtual]=machine.reg[4]
            self.events.append(dict(kind="phys_alloc",index=index,bytes=machine.reg[4],result=hex(virtual)))
            return virtual
        vm.hooks[self.base+0x6a28]=phys_alloc
        def local_alloc(machine):
            assert machine.reg[4:6]==[0x40,0x88]
            if self.fail_local_alloc:return 0
            for i in range(0x88): machine.write(CH+i,0,1)
            self.events.append(dict(kind="local_alloc",address=hex(CH)))
            return CH
        vm.hooks[self.base+0x69b8]=local_alloc
        vm.hooks[self.base+0x6998]=lambda machine:self.events.append(dict(kind="local_free",address=hex(machine.reg[4]))) or 0
        def create_mutex(machine):
            index=self.mutex_attempt;self.mutex_attempt+=1
            self.events.append(dict(kind="mutex_create",slot=index))
            return 0 if self.fail_mutex_at==index else 0xa000+index
        def last_error(_machine):return 0xb7 if self.mutex_attempt<=self.busy_channels else 0
        def wait(machine):
            self.events.append(dict(kind="wait",timeout=hex(machine.reg[5]),result=hex(self.wait_result)))
            return self.wait_result
        def close(machine):
            self.events.append(dict(kind="close_handle",handle=hex(machine.reg[4])))
            return 1
        for offset,hook,iat in [(0,wait,0x8058),(4,create_mutex,0x805c),(8,close,0x8060),
                               (12,lambda machine:self.events.append(dict(kind="release_mutex",handle=hex(machine.reg[4]))) or 1,0x8068),
                               (16,last_error,0x8028)]:
            vm.write(self.base+iat,HOOKS+offset);vm.hooks[HOOKS+offset]=hook
        def free_phys(machine):
            core=BytesVM(self.core_pe,[(0x4002afd0,0x4002affc)])
            core.reg[4]=machine.reg[4]; core.reg[29]=0x6f000000
            def release(m):
                assert m.reg[4]==0x42 and m.reg[6:8]==[0,0x8000]
                at=m.reg[5]; was_base=at in self.allocations
                if was_base: self.allocations.pop(at)
                self.events.append(dict(kind="free_phys",address=hex(at),allocation_base=was_base,
                                        syscall_flags=hex(m.reg[7]),result=int(was_base)))
                return int(was_base)
            core.hooks[0xffffb3d6]=release
            core.run(0x4002afd0,{STOP});return core.reg[2]
        vm.hooks[self.base+0x6a38]=free_phys
        return vm

    def call(self,name,*args,limit=5000):
        vm=self.vm();vm.reg[4:8]=[x&0xffffffff for x in args]+[0]*(4-len(args))
        vm.run(self.base+OFFSETS[name][0],{STOP},limit=limit)
        return vm.reg[2]


def choice(current,status,direction,own_a,own_b):
    if current not in (0,1):return 0
    if status&1 or not direction:return 1-current if (own_a if current==0 else own_b) else current
    return 1-current if not (own_b if current==0 else own_a) else current


def driver_init(pe,spec,allocs,inits):
    begin=spec["init"];vm=BytesVM(pe,[(begin,begin+128)])
    vm.reg[4]=CH;vm.reg[29]=0x70000000
    second=spec["quantum"]==256
    vm.write(CH+(0x1c if second else 0x20),spec["quantum"])
    events=[];allocated=iter(allocs);initialized=iter(inits)
    def alloc(_vm):
        out=next(allocated);events.append(dict(kind="channel_alloc",result=hex(out)));return out
    def init(machine):
        out=next(initialized);events.append(dict(kind="channel_init",selector=machine.reg[5],result=out));return out
    vm.hooks[0xc0958994 if second else 0xc0948bf8]=alloc
    vm.hooks[0xc0958984 if second else 0xc0948be8]=init
    vm.run(begin,{STOP})
    expected=int(all(allocs));assert vm.reg[2]==expected
    return dict(allocation_returns=[hex(x) for x in allocs],init_returns=list(inits),
                return_value=expected,events=events,free_calls_in_slice=0)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources,pes=[],{}
    for name,digest in HAL_HASHES.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert module["sha256"]==digest
        base=0x40230000 if name=="ceddk.dll" else 0xc0420000
        vas=[base+a for a,_ in OFFSETS.values()]+[base+0x3994]
        item,pe=source(module,vas,{base+0x40fc:0x58});sources.append(item);pes[name]=(pe,base)
    module=next(m for m in modules if m["origin"]=="rom" and m["name"]=="coredll.dll")
    assert module["sha256"]==WAVE_HASHES["coredll.dll"]
    item,core=source(module,[0x4002af98,0x4002afd0,0x4002ae6c],{});sources.append(item)
    release_equivalence=[]
    for api_result in (0,1):
        calls=[]
        for start,args in ((0x4002afd0,[PCM]),(0x4002ae6c,[PCM,0,0x8000])):
            vm=BytesVM(core,[(0x4002afd0,0x4002affc),(0x4002ae6c,0x4002ae98)])
            vm.reg[4:8]=args+[0]*(4-len(args))
            def syscall(machine):calls.append(list(machine.reg[4:8]));return api_result
            vm.hooks[0xffffb3d6]=syscall;vm.run(start,{STOP})
            assert vm.reg[2]==api_result
        assert calls[0]==calls[1]==[0x42,PCM,0,0x8000]
        release_equivalence.append(dict(injected_syscall_return=api_result,identical_syscall_arguments=calls[0]))
    selections,activations,interrupts,acks,stops,inits,frees,channels,configs=[],[],[],[],[],[],[],[],[]
    sequential=[]
    for name,(pe,base) in pes.items():
        h=HAL(pe,base,core)
        configs.append(dict(module=name,valid_selectors=VALID_SELECTORS,rows=h.runtime_config,
            initial_raw_hex=pe.get_data(base+0x813c-pe.OPTIONAL_HEADER.ImageBase,800).hex(),
            interpretation="Original config initializer executed with mocked mapping; file table starts zero"))
        for selector,cached,live,status,own_a,own_b in itertools.product((0,1,12,13),(0,1,2),(0,1,2),(0,1),(0,1),(0,1)):
            h=HAL(pe,base,core,selector=selector);vm=h.vm()
            identities=(PHYS_DESC,PHYS_DESC+64,0xf00d)
            vm.write(CH+0x84,identities[cached]);h.ports[REGS+4]=identities[live]
            h.ports[REGS+0x14]=status;h.ports[DESC]=own_a<<31;h.ports[DESC+64]=own_b<<31
            chosen=h.call("next",CH)
            active=live if selector in (0,1) else cached
            index=choice(active,status,int(selector in (1,13)),own_a,own_b)
            assert chosen==(PCM if index==0 else PCM+h.quantum)
            assert vm.read(CH+(0x58 if index==0 else 0x5c))==0
            assert vm.read(CH+(0x5c if index==0 else 0x58))==1
            selections.append(dict(module=name,selector=selector,cached=cached,live=live,status=status,
                                   own_a=own_a,own_b=own_b,chosen=index,still_bit31_set=bool((own_a,own_b)[index])))
        for address,length,owned in itertools.product((PCM,PCM+4096,PCM+4),(0,4,256,4096,4097,0xffffffff),(0,1)):
            h=HAL(pe,base,core);h.ports[DESC]=h.ports[DESC+64]=owned<<31
            result=h.call("activate",CH,address,length);valid=address in (PCM,PCM+4096)
            assert result==int(valid)
            writes=[e for e in h.events if e["kind"]=="write_port"]
            assert len(writes)==(3 if valid else 0)
            if valid:
                desc=DESC if address==PCM else DESC+64
                assert h.ports[desc+4]==length and h.ports[desc]&0x80000000
            activations.append(dict(module=name,address=hex(address),length=length,owned_before=owned,result=result,
                                    exceeds_capacity=length>4096))
        for status,a,b,ma,mb in itertools.product((0,1),(0,1),(0,1),(0,1,2),(0,1,2)):
            h=HAL(pe,base,core);vm=h.vm();h.ports[REGS+0x14]=status
            h.ports[DESC]=a<<31;h.ports[DESC+64]=b<<31;vm.write(CH+0x58,ma);vm.write(CH+0x5c,mb)
            result=h.call("check",CH)
            expected=0 if status else int(ma==1 and not a)|(int(mb==1 and not b)<<1)
            assert result==expected
            interrupts.append(dict(module=name,status=status,own_a=a,own_b=b,marker_a=ma,marker_b=mb,result=result))
        for reason,current in itertools.product((0,1,2,3,0xffffffff),(0,1,2)):
            h=HAL(pe,base,core);vm=h.vm();vm.write(CH+0x84,(PHYS_DESC,PHYS_DESC+64,0xf00d)[current])
            assert h.call("ack",CH,reason)==1
            expected=PHYS_DESC+64 if reason==1 or (reason!=2 and current==0) else PHYS_DESC
            assert vm.read(CH+0x84)==expected
            assert vm.read(CH+0x58)==(2 if reason==1 else 1)
            assert vm.read(CH+0x5c)==(2 if reason==2 else 1)
            acks.append(dict(module=name,reason=hex(reason),cached_before=current,cached_after=hex(expected)))
        for zeros in (0,1,4,32,None):
            h=HAL(pe,base,core);h.status_sequence=[0] if zeros is None else [0]*zeros+[1]
            h.ports[DESC]=h.ports[DESC+64]=0x80000004
            try:
                result=h.call("stop",CH,limit=2000)
                assert zeros is not None and result==1
                assert h.ports[DESC]==h.ports[DESC+64]==4 and h.vm().read(CH+0x58)==h.vm().read(CH+0x5c)==0
                outcome="returned"
            except AssertionError as e:
                assert zeros is None and str(e)=="Slice step limit"
                assert h.ports[DESC]&0x80000000 and h.vm().read(CH+0x58)==1
                outcome="bounded_interpreter_limit_not_firmware_timeout"
            polls=sum(e["kind"]=="read_port" and e["address"]==hex(REGS+0x14) for e in h.events)
            stops.append(dict(module=name,zero_status_reads=zeros,outcome=outcome,status_polls=polls,
                               control_enable_cleared=not bool(h.ports[REGS]&1)))
        for selector,q,failed_pcm,failed_desc in itertools.product(range(-1,26),(256,4096),(False,True),(False,True)):
            h=HAL(pe,base,core,quantum=q);h.events.clear();h.fail_allocations={i for i,v in enumerate((failed_pcm,failed_desc)) if v}
            low=None
            try:result=h.call("init",CH,selector,q,1)
            except LowTarget as e:low=e.record;result=None
            valid=selector in VALID_SELECTORS or selector==-1
            if not valid:assert result==0 and h.phys_attempt==0
            elif failed_desc:assert low and h.phys_attempt==2
            else:
                assert result==1 and h.phys_attempt==2
                assert h.vm().read(CH+0x28)==(0 if failed_pcm else PCM)
            inits.append(dict(module=name,selector=selector,quantum=q,failed_pcm=failed_pcm,failed_descriptor=failed_desc,
                result=result,first_low_target=low,allocations=list(h.allocations),events=list(h.events)))
        for q,wait in itertools.product((256,4096),(0,0x102,0xffffffff,0x80)):
            h=HAL(pe,base,core,quantum=q);h.allocations={PCM:q*2,DESC:128};h.wait_result=wait
            h.call("free",CH)
            events=[e for e in h.events if e["kind"]=="free_phys"]
            assert [e["address"] for e in events]==([hex(PCM),hex(PCM+q)] if wait==0 else [])
            assert DESC in h.allocations
            frees.append(dict(module=name,quantum=q,wait_return=hex(wait),free_phys_calls=events,
                remaining_allocations=[hex(x) for x in h.allocations],events=list(h.events),
                ledger_scope="Fixture releases only original allocation base; complete kernel release semantics not interpreted"))
        for busy,local_fail,mutex_fail,wait in [(0,False,None,0),(15,False,None,0),(16,False,None,0),
             (0,True,None,0),(0,False,0,0),(3,False,3,0),(0,False,None,0xffffffff)]:
            h=HAL(pe,base,core);h.events.clear();h.busy_channels=busy;h.fail_local_alloc=local_fail
            h.fail_mutex_at=mutex_fail;h.wait_result=wait
            result=h.call("allocate")
            expected=CH if busy<16 and not local_fail and mutex_fail is None else 0
            assert result==expected
            channels.append(dict(module=name,busy_channels=busy,local_alloc_failure=local_fail,mutex_failure_at=mutex_fail,
                                 wait_return=hex(wait),result=hex(result),events=list(h.events)))
        h=HAL(pe,base,core);h.events.clear();h.mapping_result=0
        try:h.call("config");raise AssertionError("Mapping failure not detected by fixture")
        except LowTarget as e:channels.append(dict(module=name,mapping_failure=True,first_low_target=e.record,events=list(h.events)))
        h=HAL(pe,base,core);vm=h.vm();vm.write(CH+0x58,0);vm.write(CH+0x5c,0)
        first=h.call("next",CH);assert first==PCM
        assert h.call("activate",CH,first,4096)==1
        second=h.call("next",CH);assert second==PCM+4096
        assert h.call("activate",CH,second,4096)==1
        third=h.call("next",CH);assert third==second and h.ports[DESC+64]&0x80000000
        h.ports[REGS+0x14]=0;h.ports[DESC]&=0x7fffffff
        assert h.call("check",CH)==1 and h.call("ack",CH,1)==1
        after_ack=h.call("next",CH);assert after_ack==PCM
        sequential.append(dict(module=name,first=hex(first),second=hex(second),third_without_hardware_advance=hex(third),
            after_injected_descriptor_completion_and_ack=hex(after_ack),events=list(h.events),
            scope="One descriptor bit was cleared by a register fixture; no physical completion or IRQ scheduler"))
    driver_cases=[]
    for name,spec in DRIVER_SPECS.items():
        m=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert m["sha256"]==STREAM_SPECS[name]["sha256"]
        item,pe=source(m,[spec["init"]],{});sources.append(item)
        for allocated,inited in itertools.product(((CH,CH+256),(0,CH+256),(CH,0)),((0,0),(0,1),(1,0),(1,1))):
            driver_cases.append(dict(module=name,**driver_init(pe,spec,allocated,inited)))
    evidence=dict(sources=sources,producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        interpreter_sha256=hashlib.sha256((ROOT/"tools/inspect_bt_lifecycle.py").read_bytes()).hexdigest(),
        queue_helper_sha256=hashlib.sha256((ROOT/"tools/inspect_wave_queue.py").read_bytes()).hexdigest(),
        dma_helper_sha256=hashlib.sha256((ROOT/"tools/inspect_wave_dma.py").read_bytes()).hexdigest(),
        checks=dict(original_ranges=sum(len(s["ranges"]) for s in sources),runtime_config_initializers=len(configs),
          selection_cases=len(selections),activation_cases=len(activations),irq_check_cases=len(interrupts),
          ack_cases=len(acks),stop_cases=len(stops),init_allocation_cases=len(inits),free_cases=len(frees),
          channel_allocator_cases=len(channels),driver_init_cases=len(driver_cases),sequential_descriptor_traces=len(sequential),
          free_virtual_release_equivalence=len(release_equivalence)),
        configs=configs,selections=selections,activations=activations,interrupts=interrupts,acks=acks,stops=stops,
        initialization=inits,free=frees,channel_allocation=channels,driver_init=driver_cases,sequential=sequential,
        free_virtual_release_equivalence=release_equivalence,
        public_contracts=["https://learn.microsoft.com/en-us/previous-versions/ms913491(v=msdn.10)"],
        native_execution=False,limitations=["OS allocations/mutexes/mapping, MMIO reads/writes and cache synchronization are fixtures",
          "No hardware descriptor ownership, physical samples, actual unit memory pressure or allocator failure incidence",
          "Low-target traces stop at first attempt; no claim firmware continues successfully after a fault",
          "Kernel physical-release semantics and complete outer driver unwind/cleanup remain open",
          "Negative selector is a local range-check witness; ordinary audio wrappers use positive 12/13/18/19"])
    out=ROOT/"analysis/firmware/dma-hal";out.mkdir(parents=True,exist_ok=True)
    (out/"contracts.json").write_text(json.dumps(evidence,indent=2),encoding="utf-8")
    lines=[]
    for s in sources:
        ranges=[(int(r["va"],16),int(r["va"],16)+r["bytes"]) for r in s["ranges"]]
        lines.append(f"; {s['module']} {s['sha256']}\n")
        for line in (ROOT/"analysis/disassembly/rom"/(s["module"]+".asm")).read_text(encoding="utf-8").splitlines(keepends=True):
            try:va=int(line[:8],16)
            except ValueError:continue
            if any(lo<=va<hi for lo,hi in ranges):lines.append(line)
    (out/"reviewed-paths.asm").write_text("".join(lines),encoding="utf-8")
    print(json.dumps(dict(status="passed",**evidence["checks"]),indent=2))


if __name__=="__main__":main()
