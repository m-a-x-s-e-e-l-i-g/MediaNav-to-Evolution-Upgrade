"""Interpret original DDMA mapping/unmapping and repeated allocator calls offline.

VirtualAlloc/Copy/Free and page size are explicit fixtures. No native firmware,
real address reservation, hardware mapping or allocator-pressure measurement.
"""
import hashlib
import itertools
import json
from pathlib import Path

from inspect_bt_playback import ROOT, source
from inspect_dma_hal import HAL, HalVM, LowTarget, CH, MAP
from inspect_wave_dma import HAL_HASHES
from inspect_wave_queue import STOP, HASHES


class MappingVM(HalVM):
    def plain(self, word):
        if word >> 26 == 0 and word & 63 == 0x27:
            rs,rt,rd=(word>>21)&31,(word>>16)&31,(word>>11)&31
            self.reg[rd]=~(self.reg[rs]|self.reg[rt])&0xffffffff
            self.reg[0]=0
        else:super().plain(word)


class Mapper:
    def __init__(self, pe, base, mem=None, page_size=4096):
        self.pe, self.base = pe, base
        self.mem = {} if mem is None else mem
        self.page_size = page_size
        self.events, self.reservations = [], {}
        self.attempt = 0
        self.alloc_failures, self.copy_failures = set(), set()
        self.release_result = 1

    def vm(self):
        vm = MappingVM(self.pe, [(self.base+0x2360,self.base+0x2444),
                             (self.base+0x2444,self.base+0x2478)], self.mem)
        vm.reg[29] = 0x6b000000
        vm.write(0x5b04,self.page_size)

        def allocate(machine):
            args=list(machine.reg[4:8]); assert args[0]==0 and args[2:]==[0x2000,1]
            index=self.attempt; self.attempt+=1
            out=0 if index in self.alloc_failures else MAP+index*0x10000
            if out:self.reservations[out]=dict(size=args[1],mapped=False)
            self.events.append(dict(kind="virtual_alloc",attempt=index,args=args,result=out))
            return out

        def copy(machine):
            args=list(machine.reg[4:8]); assert args[0] in self.reservations
            index=self.attempt-1; result=int(index not in self.copy_failures)
            if result:self.reservations[args[0]].update(mapped=True,source=args[1],flags=args[3])
            self.events.append(dict(kind="virtual_copy",attempt=index,args=args,result=result))
            return result

        def release(machine):
            args=list(machine.reg[4:7]); assert args[1:]==[0,0x8000]
            result=int(bool(self.release_result) and args[0] in self.reservations)
            if result:self.reservations.pop(args[0])
            self.events.append(dict(kind="virtual_free",args=args,result=result))
            return result

        vm.hooks[self.base+0x6948]=allocate
        vm.hooks[self.base+0x6938]=copy
        vm.hooks[self.base+0x6928]=release
        return vm

    def call(self, offset, *args):
        vm=self.vm(); vm.reg[4:8]=list(args)+[0]*(4-len(args))
        vm.run(self.base+offset,{STOP})
        return vm.reg[2]


class MappedHAL(HAL):
    def __init__(self,pe,base,core):
        self.mapper=Mapper(pe,base)
        self.local_attempt=0
        super().__init__(pe,base,core)
        # HAL's constructor initializes explicit descriptor fixtures. Discard
        # that setup mapping before the separately recorded allocator sequence.
        self.mapper.events.clear();self.mapper.reservations.clear();self.mapper.attempt=0
        self.events.clear()

    def vm(self):
        vm=super().vm()
        self.mapper.mem=self.mem

        def mapping(machine):
            return self.mapper.call(0x2360,*machine.reg[4:8])

        def local_alloc(machine):
            assert machine.reg[4:6]==[0x40,0x88]
            if self.fail_local_alloc:return 0
            out=CH+self.local_attempt*256;self.local_attempt+=1
            for i in range(0x88):machine.write(out+i,0,1)
            self.events.append(dict(kind="local_alloc",address=hex(out)))
            return out

        vm.hooks[self.base+0x2360]=mapping
        vm.hooks[self.base+0x69b8]=local_alloc
        return vm


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources,pes=[],{}
    for name,digest in HAL_HASHES.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert module["sha256"]==digest
        base=0x40230000 if name=="ceddk.dll" else 0xc0420000
        item,pe=source(module,[base+x for x in (0x2360,0x2444,0x326c,0x35d8,0x3778)],{})
        sources.append(item);pes[name]=(pe,base)
    module=next(m for m in modules if m["origin"]=="rom" and m["name"]=="coredll.dll")
    assert module["sha256"]==HASHES["coredll.dll"]
    item,core=source(module,[0x4002afd0],{});sources.append(item)
    mappings,unmaps,sequences=[],[],[]
    for name,(pe,base) in pes.items():
        for page,low,high,length,cache,outcome,release in itertools.product(
            (4096,65536),(0,0x14002000,0x14002001,0x14002fff,0xfffffffe),
            (0,1,0x100),(0,1,0x1010,0xfffff000,0xffffffff),(0,1),
            ("success","alloc_failure","copy_failure"),(0,1)):
            fixture=Mapper(pe,base,page_size=page);fixture.release_result=release
            if outcome=="alloc_failure":fixture.alloc_failures={0}
            if outcome=="copy_failure":fixture.copy_failures={0}
            result=fixture.call(0x2360,low,high,length,cache)
            offset=low&(page-1)
            size=((page+offset+length-1)&0xffffffff)&(~(page-1)&0xffffffff)
            expected=MAP+offset if outcome=="success" else 0
            assert result==expected
            assert fixture.events[0]["args"]==[0,size,0x2000,1]
            if outcome!="alloc_failure":
                physical=((high<<24)|((low&(~(page-1)&0xffffffff))>>8))&0xffffffff
                assert fixture.events[1]["args"]==[MAP,physical,size,0x404 if cache else 0x604]
            assert sum(e["kind"]=="virtual_free" for e in fixture.events)==int(outcome=="copy_failure")
            assert bool(fixture.reservations)==(outcome=="success" or (outcome=="copy_failure" and not release))
            mappings.append(dict(module=name,page_size=page,physical_low=low,physical_high=high,
                requested_bytes=length,cache=cache,injected_outcome=outcome,release_return=release,
                result=result,offset=offset,aligned_size=size,events=fixture.events,
                remaining_reservations=fixture.reservations))
        for page,offset,release in itertools.product((4096,65536),(0,1,0xfff,0x1000,0xffff),(0,1)):
            fixture=Mapper(pe,base,page_size=page);fixture.release_result=release
            aligned=(MAP+offset)&(~(page-1)&0xffffffff)
            fixture.reservations[aligned]=dict(size=page,mapped=True)
            fixture.call(0x2444,MAP+offset,0x1234)
            assert fixture.events==[dict(kind="virtual_free",args=[aligned,0,0x8000],result=release)]
            unmaps.append(dict(module=name,page_size=page,pointer=MAP+offset,
                ignored_length=0x1234,release_return=release,events=fixture.events,
                remaining_reservations=fixture.reservations))
        for count,failure,release,heap_failure in (
            (1,None,1,False),(2,None,1,False),(16,None,1,False),
            (2,"alloc",1,False),(2,"copy",1,False),(2,"copy",0,False),
            (1,None,1,True)):
            fixture=MappedHAL(pe,base,core);fixture.mapper.release_result=release
            fixture.fail_local_alloc=heap_failure
            if failure=="alloc":fixture.mapper.alloc_failures={1}
            if failure=="copy":fixture.mapper.copy_failures={1}
            channels=[];low_target=None
            for _ in range(count):
                try:channel=fixture.call("allocate")
                except LowTarget as error:low_target=error.record;break
                if channel:channels.append(channel)
            # Exercise original allocator/free pair before HalInitDmaChannel;
            # physical-buffer ownership is covered separately in dma-hal.
            for channel in channels:fixture.call("free",channel)
            expected_live=(count if failure is None else 1+int(failure=="copy" and not release))
            assert len(fixture.mapper.reservations)==expected_live
            assert fixture.mapper.attempt==count
            assert bool(low_target)==(failure is not None)
            assert len(channels)==(1 if failure else 0 if heap_failure else count)
            assert sum(e["kind"]=="virtual_free" for e in fixture.mapper.events)==int(failure=="copy")
            global_map=fixture.vm().read(base+0x845c)
            assert global_map==(0 if failure else MAP+(count-1)*0x10000)
            sequences.append(dict(module=name,attempts=count,second_mapping_failure=failure,
                release_return=release,heap_failure=heap_failure,channels=channels,
                latest_global_mapping=global_map,first_low_target=low_target,
                remaining_reservations=fixture.mapper.reservations,
                mapping_events=fixture.mapper.events,channel_events=fixture.events,
                scope="Original config/mapper/allocator/free instructions; OS, mutex and MMIO fixtures; no physical init"))
    evidence=dict(sources=sources,
        producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        dependency_sha256={name:hashlib.sha256((ROOT/"tools"/name).read_bytes()).hexdigest()
            for name in ("inspect_dma_hal.py","inspect_wave_queue.py","inspect_bt_lifecycle.py","inspect_wave_dma.py")},
        checks=dict(original_ranges=sum(len(s["ranges"]) for s in sources),
            mapping_cases=len(mappings),unmap_cases=len(unmaps),allocator_free_sequences=len(sequences)),
        mapping=mappings,unmap=unmaps,sequences=sequences,native_execution=False,
        limitations=["Page size and VirtualAlloc/Copy/Free outcomes are fixtures, not current unit values",
            "Arithmetic overflow/zero-size cases witness API arguments; mocks do not establish OS acceptance",
            "Repeated allocator/free pairs have no physical channel initialization or real mutex-slot tracking",
            "Fixture reservations are not a measured unit leak or memory-pressure incident",
            "Complete kernel memory manager and process/module unload cleanup remain open"])
    out=ROOT/"analysis/firmware/dma-mapping";out.mkdir(parents=True,exist_ok=True)
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
