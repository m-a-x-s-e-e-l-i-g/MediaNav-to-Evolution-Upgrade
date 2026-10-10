"""Interpret OEM stream ownership paths; hardware/render scheduling is a fixture."""
import hashlib
import json
import struct
from pathlib import Path

from inspect_bt_playback import ROOT, source
from inspect_wave_queue import BytesVM, WaveFixture, STOP, CTX, HASHES

OBJECT, DEVICE, DEVICE_VTABLE, START_DMA = 0x4a000000, 0x4a001000, 0x4a002000, 0x4a003000
CALLBACK, FIRST_HEADER, DATA = 0x4a003004, 0x4b000000, 0x4c000000
SPECS = {
    "wavedev2_i2s.dll": dict(sha256="fec5ab038cf274c4cf74a6553f9a81328bba7100c8ec9b17438658a7fae9d67c",
        delta=0, tables=[0xc0941194, 0xc09411e0, 0xc0941224, 0xc0941268, 0xc09412ac, 0xc09412f0, 0xc0941334, 0xc0941508],
        pcm_table=0xc0941334, factory=0xc09433d4, allocator=0xc0949080,
        device_table=0xc0941ca8, dispatcher=0xc0942138),
    "wavedev2_i2s2.dll": dict(sha256="eb9b1d5625e0be967f139a4fe1d3e67799bd71d0af1e5bdf7c55b6d1f347a009",
        delta=0x1010c, tables=[0xc0951194, 0xc09512d4, 0xc0951318, 0xc095135c, 0xc09513a0, 0xc09513e4, 0xc0951428, 0xc09515fc],
        pcm_table=0xc0951428, factory=0xc09534e0, allocator=0xc0958e1c,
        device_table=0xc0951d9c, dispatcher=0xc0952198),
}
# Values beyond 15 entries in the special/base tables are data, not more methods.
BASE_FUNCTIONS = [0xc09438e4, 0xc09439b0, 0xc0943e94, 0xc09445d8, 0xc0943e88,
                  0xc0943e44, 0xc0943630, 0xc0943698, 0xc0944234, 0xc0943888,
                  0xc0943ff0, 0xc0944be4, 0xc094457c, 0xc0943740, 0xc0943d40,
                  0xc09435fc, 0xc09435dc, 0xc0943878, 0xc09435b8]


class Stream:
    def __init__(self, pe, spec, mem=None, completion=None):
        self.pe, self.spec = pe, spec
        self.delta = spec["delta"]
        self.events, self.completion = [], completion
        self.mem = mem if mem is not None else {}
        self.ranges = [(0xc09438e4, 0xc09439b0), (0xc09439b0, 0xc0943ab8),
                       (0xc0943e44, 0xc0943e88), (0xc0943e88, 0xc0943e94), (0xc0943e94, 0xc0943f40),
                       (0xc09445d8, 0xc0944628), (0xc0943630, 0xc0943664),
                       (0xc0943698, 0xc09436cc), (0xc0944234, 0xc094429c),
                       (0xc0943888, 0xc09438e4)]
        self.ranges = [(a+self.delta, b+self.delta) for a,b in self.ranges]
        vm = self.vm()
        table = spec["pcm_table"]
        for i,w in enumerate(struct.unpack("<17I", pe.get_data(table-pe.OPTIONAL_HEADER.ImageBase, 68))):
            vm.write(table+i*4, w)
        vm.write(OBJECT, table); vm.write(OBJECT+0xc, 1)
        vm.write(OBJECT+0x50, DEVICE); vm.write(DEVICE, DEVICE_VTABLE)
        vm.write(DEVICE_VTABLE+0x10, START_DMA)
        vm.write(OBJECT+0x18, 0x12340000); vm.write(OBJECT+0x1c, CALLBACK)
        vm.write(OBJECT+0x20, 0x56780000)

    def vm(self):
        vm = BytesVM(self.pe, self.ranges, self.mem)
        vm.reg[29] = 0x6c000000
        def start(machine):
            self.events.append(dict(kind="device_start", device=hex(machine.reg[4])))
            return 1
        def callback(machine):
            header = machine.reg[7]
            event = dict(kind="callback", message=hex(machine.reg[5]), header=hex(header),
                         head=hex(machine.read(OBJECT+0x38)), current=hex(machine.read(OBJECT+0x3c)),
                         flags=machine.read(header+0x10) if header else None)
            self.events.append(event)
            if self.completion is not None: self.completion(machine)
            return 0
        vm.hooks[START_DMA], vm.hooks[CALLBACK] = start, callback
        return vm

    def call(self, base_va, *args):
        vm = self.vm(); vm.reg[4:8] = list(args)+[0]*(4-len(args))
        vm.run(base_va+self.delta, {STOP})
        return vm.reg[2]

    def header(self, index, flags=2, length=25600):
        hdr=FIRST_HEADER+index*64; vm=self.vm()
        vm.write(hdr, DATA+index*25600); vm.write(hdr+4, length)
        vm.write(hdr+0x10, flags); vm.write(hdr+0x14, 0)
        return hdr


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources, tables, flags, drains, resets, loop_cases, factories, playback_controls = [], [], [], [], [], [], [], []
    pes={}
    for name,spec in SPECS.items():
        m=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert m["sha256"]==spec["sha256"]
        delta=spec["delta"]
        vas=[va+delta for va in BASE_FUNCTIONS]+[spec["factory"],spec["dispatcher"]]
        leaf={0xc0943e88+delta:12, 0xc09435dc+delta:24, 0xc0943878+delta:16, 0xc09435b8+delta:20}
        item,pe=source(m,vas,leaf); sources.append(item); pes[name]=pe
        for i,table in enumerate(spec["tables"]):
            n=15 if i in (0,7) else 17
            raw=pe.get_data(table-pe.OPTIONAL_HEADER.ImageBase,n*4)
            targets=struct.unpack("<"+"I"*n,raw)
            assert targets[0x30//4]==0xc09438e4+delta
            if i not in (0,): assert targets[8//4]==0xc0944234+delta
            if i in (2,3,4,5,6): assert targets[0x18//4]==0xc09445d8+delta
            if i in (2,3,4,5,6,7): assert targets[0x24//4]==0xc0943630+delta
            tables.append(dict(module=name,va=hex(table),bytes=len(raw),raw_hex=raw.hex(),
                               role="stream",sha256=hashlib.sha256(raw).hexdigest(),targets=[hex(t) for t in targets]))
        table=spec["device_table"]
        raw=pe.get_data(table-pe.OPTIONAL_HEADER.ImageBase,32); targets=struct.unpack("<8I",raw)
        assert targets[0x14//4]==spec["factory"]
        tables.append(dict(module=name,va=hex(table),bytes=len(raw),raw_hex=raw.hex(),role="output_device",
                           sha256=hashlib.sha256(raw).hexdigest(),targets=[hex(t) for t in targets]))
        for tag in (1,0x164,0x3000):
            for channels in (1,2,3):
                for bits in (8,16,24):
                    for allocation_failure in (False,True):
                        constructor=0xc09435b8+delta
                        vm=BytesVM(pe,[(spec["factory"],spec["factory"]+484),(constructor,constructor+20)])
                        descriptor,fmt=0x4d000000,0x4d001000
                        vm.write(descriptor+4,fmt); vm.write(fmt,tag,2)
                        vm.write(fmt+2,channels,2); vm.write(fmt+14,bits,2)
                        allocations=[]
                        def allocate(machine):
                            allocations.append(machine.reg[4])
                            return 0 if allocation_failure else OBJECT
                        vm.hooks[spec["allocator"]]=allocate
                        vm.reg[4:6]=[DEVICE,descriptor]; vm.run(spec["factory"],{STOP})
                        expected=None
                        if tag==0x3000: expected=spec["tables"][0]
                        elif tag==0x164: expected=spec["tables"][2]
                        elif bits in (8,16) and channels in (1,2):
                            expected=spec["tables"][3+(2 if bits==16 else 0)+(channels-1)]
                        assert vm.reg[2]==(OBJECT if expected and not allocation_failure else 0)
                        assert allocations==([0x694 if tag==0x3000 else 0x94] if expected else [])
                        if vm.reg[2]: assert vm.read(OBJECT)==expected
                        factories.append(dict(module=name,tag=hex(tag),channels=channels,bits=bits,
                            allocation_failure=allocation_failure,table=hex(expected) if vm.reg[2] else None,
                            allocation_bytes=allocations))
        for flag in range(32):
            s=Stream(pe,spec); h=s.header(0,flags=flag)
            result=s.call(0xc09438e4,OBJECT,h)
            assert result==(0 if flag&2 else 0x22)
            if flag&2:
                assert s.vm().read(h+0x10)==((flag&~1)|0x10)
                assert s.vm().read(OBJECT+0x44)==DATA and s.vm().read(OBJECT+0x48)==DATA+25600
            flags.append(dict(module=name,input_flags=flag,result=result))
        for count in (0,1,2,25):
            s=Stream(pe,spec); headers=[s.header(i) for i in range(count)]
            for h in headers: assert s.call(0xc09438e4,OBJECT,h)==0
            assert s.call(0xc0944234,OBJECT)==(0x21 if count else 0)
            s.events.clear()
            for i,h in enumerate(headers):
                result=s.call(0xc09439b0,OBJECT)
                assert result==(DATA+(i+1)*25600 if i+1<count else 0)
                event=s.events[-1]
                assert event["kind"]=="callback" and event["header"]==hex(h)
                assert event["flags"]==3 and event["head"]!=hex(h)
            assert s.vm().read(OBJECT+0x38)==0 and s.vm().read(OBJECT+0x3c)==0
            drained=list(s.events)
            assert s.call(0xc0944234,OBJECT)==0
            drains.append(dict(module=name,headers=count,completion_events=drained,close_result=0))
            s=Stream(pe,spec); headers=[s.header(i) for i in range(count)]
            for h in headers: assert s.call(0xc09438e4,OBJECT,h)==0
            assert s.call(0xc09445d8,OBJECT)==0
            callbacks=[e for e in s.events if e["kind"]=="callback"]
            assert [e["header"] for e in callbacks]==[hex(h) for h in headers]
            assert all(e["flags"]==3 for e in callbacks)
            assert s.vm().read(OBJECT+0x38)==0 and s.vm().read(OBJECT+0x3c)==0
            assert s.vm().read(OBJECT+0xc)==1 and s.vm().read(OBJECT+0x10)==1
            resets.append(dict(module=name,headers=count,completion_events=callbacks,refcount_after=1,
                               running_after=1,device_start_calls=sum(e["kind"]=="device_start" for e in s.events)))
        for repeats in (2,3,0xffffffff):
            s=Stream(pe,spec); h=s.header(0,flags=2|4|8); s.vm().write(h+0x14,repeats)
            assert s.call(0xc09438e4,OBJECT,h)==0
            assert s.call(0xc09439b0,OBJECT)==DATA and not s.events
            assert s.vm().read(OBJECT+0x54)==(repeats if repeats==0xffffffff else repeats-1)
            assert s.vm().read(h+0x10)&0x10
            loop_cases.append(dict(module=name,repeats=hex(repeats),completion_deferred=True))
        s=Stream(pe,spec); h=s.header(0)
        assert s.call(0xc09438e4,OBJECT,h)==0 and not s.events
        assert s.call(0xc0943e44,OBJECT)==0 and len(s.events)==1
        assert s.call(0xc0943e88,OBJECT)==0
        assert s.call(0xc09438e4,OBJECT,s.header(1))==0 and len(s.events)==1
        playback_controls.append(dict(module=name,queued_while_paused_starts=0,restart_starts=1,
                                      subsequent_paused_enqueue_starts=0))
    # Connect the actual first OEM queue/advance/callback instructions to WAM and
    # coredll using the same caller/proxy memory. Hardware consumption is scheduled
    # explicitly by invoking advance, not simulated as DMA or audible playback.
    for name in ("waveapi.dll","coredll.dll"):
        m=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert m["sha256"]==HASHES[name]
        item,pe=source(m,[0xc03fa2f0,0xc03f2aa4,0xc03f10b0,0xc03f1000] if name=="waveapi.dll"
                       else [0x4009ea98,0x4009e854],{})
        sources.append(item); pes[name]=pe
    w=WaveFixture(pes["waveapi.dll"],pes["coredll.dll"],header_count=2)
    def completed(machine):
        if machine.reg[5]==0x3bd:
            w.call(0xc03f10b0,tuple(machine.reg[4:8]),(machine.read(machine.reg[29]+0x10),))
    s=Stream(pes["wavedev2_i2s.dll"],SPECS["wavedev2_i2s.dll"],w.mem,completed)
    s.vm().write(OBJECT+0x18,0x41000000)  # WAM stream from inspect_wave_queue fixture.
    # Each WAM invocation creates its own VM; override its driver method.
    w.driver=lambda machine: s.call(0xc09438e4,OBJECT,machine.reg[7])
    for i in range(2): assert w.write(CTX+0x10+i*32)==0
    assert s.call(0xc09439b0,OBJECT)!=0
    assert len(w.runtime_queue)==1 and not w.app_queue
    w.drain_proxy()
    assert len(w.app_queue)==1 and w.app_queue[0]["header"]==CTX+0x10
    assert w.vm.read(CTX+0x20)==3 and w.vm.read(0x41000000+0x58)==1
    linked=dict(driver_events=s.events,runtime_events=w.events,
                returned_original_header=hex(w.app_queue[0]["header"]),wam_pending=1,
                remaining_oem_current=hex(s.vm().read(OBJECT+0x3c)),
                scope="Two submitted proxies; first advanced via explicit consumption fixture; Blue message not processed")
    evidence=dict(sources=sources,vtables=tables,producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        interpreter_sha256=hashlib.sha256((ROOT/"tools/inspect_bt_lifecycle.py").read_bytes()).hexdigest(),
        wave_queue_helper_sha256=hashlib.sha256((ROOT/"tools/inspect_wave_queue.py").read_bytes()).hexdigest(),
        checks=dict(original_ranges=sum(len(s["ranges"]) for s in sources),vtables=len(tables),
                    enqueue_flag_cases=len(flags),drain_and_close_cases=len(drains),reset_cases=len(resets),
                    loop_completion_cases=len(loop_cases),factory_selection_cases=len(factories),
                    pause_restart_cases=len(playback_controls),linked_oem_wam_core_traces=1),
        flag_cases=flags,drain_cases=drains,reset_cases=resets,loop_cases=loop_cases,
        factory_cases=factories,playback_controls=playback_controls,linked_trace=linked,
        native_execution=False,limitations=["DMA/device start is mocked; advance is an explicit consumption trigger",
          "No actual unit device selection, scheduler, mixer, physical playback or hardware latency measurement",
          "Resampler/render kernels are statically pinned, not interpreted; all loop transitions remain open",
          "Injected queue failures and complete runtime object lifetime remain separate investigations"])
    out=ROOT/"analysis/firmware/wave-streams"; out.mkdir(parents=True,exist_ok=True)
    (out/"contracts.json").write_text(json.dumps(evidence,indent=2),encoding="utf-8")
    lines=[]
    for item in sources:
        ranges=[(int(r["va"],16),int(r["va"],16)+r["bytes"]) for r in item["ranges"]]
        lines.append(f"; {item['module']} {item['sha256']}\n")
        for line in (ROOT/"analysis/disassembly/rom"/(item["module"]+".asm")).read_text(encoding="utf-8").splitlines(keepends=True):
            try: va=int(line[:8],16)
            except ValueError: continue
            if any(lo<=va<hi for lo,hi in ranges): lines.append(line)
    (out/"reviewed-paths.asm").write_text("".join(lines),encoding="utf-8")
    print(json.dumps(dict(status="passed",**evidence["checks"]),indent=2))


if __name__=="__main__":main()
