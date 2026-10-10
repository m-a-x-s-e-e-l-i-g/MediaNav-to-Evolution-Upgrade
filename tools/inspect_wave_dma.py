"""Bounded output-prime/pump interpretation; mixer, HAL and scheduling are fixtures."""
import hashlib
import itertools
import json
from pathlib import Path

from inspect_bt_playback import ROOT, source
from inspect_wave_queue import BytesVM, STOP
from inspect_wave_streams import SPECS as STREAM_SPECS

DEVICE, BUFFER, CHANNEL = 0x4e000000, 0x4f000000, 0x12345678
SPECS = {
    "wavedev2_i2s.dll": dict(start=0xc0947e50,pump=0xc094791c,next=0xc0948554,
        activate=0xc09485a0,hw_start=0xc0948440,thread=0xc0947a28,init=0xc09483c0,
        mixer=0xc0942ae0,memset=0xc09490f0,hal_next=0xc0948c38,hal_activate=0xc0948c48,
        quantum=4096,channel_offset=0x1c),
    "wavedev2_i2s2.dll": dict(start=0xc0957f4c,pump=0xc0957a18,next=0xc0958608,
        activate=0xc0958654,hw_start=0xc095852c,thread=0xc0957b24,init=0xc09584ac,
        mixer=0xc0952b48,memset=0xc0958e8c,hal_next=0xc09589d4,hal_activate=0xc09589e4,
        quantum=256,channel_offset=0x18),
}
HAL_HASHES={"ceddk.dll":"9db6404163f5280080d8bfe50b1f7d413de189de0536e7dd79b403f1cab50731",
            "k.ceddk.dll":"ccbbe9983bca33cb3d2b548fda266168fb6c3164039a5f9a82417aa9398b2aff"}


def prime(pe,spec,lengths,activate_result=1,start_result=1,already_active=False):
    spans=[(spec["start"],spec["start"]+116),(spec["pump"],spec["pump"]+144),
           (spec["next"],spec["next"]+76),(spec["activate"],spec["activate"]+80)]
    vm=BytesVM(pe,spans); vm.reg[4]=DEVICE; vm.reg[29]=0x6d000000
    vm.write(DEVICE+0x84,int(already_active))
    vm.write(DEVICE+0xc8+spec["channel_offset"],CHANNEL)
    events=[]; count=0
    def get_buffer(machine):
        nonlocal count
        assert machine.reg[4]==CHANNEL
        result=BUFFER+count*8192; count+=1
        events.append(dict(kind="next_buffer",address=hex(result)))
        return result
    def render(machine):
        index=(machine.reg[5]-BUFFER)//8192; length=lengths[index]
        assert machine.reg[4]==DEVICE+0x50 and machine.reg[6]-machine.reg[5]==spec["quantum"]
        events.append(dict(kind="render",capacity=spec["quantum"],bytes=length,address=hex(machine.reg[5])))
        return machine.reg[5]+length
    def activate(machine):
        assert machine.reg[4]==CHANNEL
        events.append(dict(kind="activate",address=hex(machine.reg[5]),bytes=machine.reg[6],result=activate_result))
        return activate_result
    def start(machine):
        assert machine.reg[4]==DEVICE+0xc8 and machine.reg[5]==2
        events.append(dict(kind="hardware_start",result=start_result))
        return start_result
    vm.hooks[spec["hal_next"]]=get_buffer
    vm.hooks[spec["mixer"]]=render
    vm.hooks[spec["hal_activate"]]=activate
    vm.hooks[spec["hw_start"]]=start
    def zero(machine):
        assert machine.reg[5]==0 and machine.reg[6]==8
        for i in range(8): machine.write(machine.reg[4]+i,0,1)
        return machine.reg[4]
    vm.hooks[spec["memset"]]=zero
    vm.run(spec["start"],{STOP})
    assert vm.reg[2]==1
    if already_active:
        assert not events and vm.read(DEVICE+0x84)==1
    else:
        assert count==2
        assert vm.read(DEVICE+0x84)==int(sum(lengths)!=0)
        assert sum(e["kind"]=="activate" for e in events)==sum(n!=0 for n in lengths)
        assert sum(e["kind"]=="hardware_start" for e in events)==int(sum(lengths)!=0)
    return dict(render_lengths=list(lengths),injected_activate_return=activate_result,
                injected_start_return=start_result,already_active=already_active,return_value=vm.reg[2],
                active_after=vm.read(DEVICE+0x84),events=events)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources,cases=[],[]
    for name,spec in SPECS.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert module["sha256"]==STREAM_SPECS[name]["sha256"]
        item,pe=source(module,[spec[k] for k in ("start","pump","next","activate","hw_start","thread","init","mixer")],{})
        sources.append(item)
        for lengths in itertools.product((0,4,spec["quantum"]//2,spec["quantum"]),repeat=2):
            for activate_result,start_result in itertools.product((0,1),repeat=2):
                cases.append(dict(module=name,**prime(pe,spec,lengths,activate_result,start_result)))
        cases.append(dict(module=name,**prime(pe,spec,(0,0),already_active=True)))
    for name,digest in HAL_HASHES.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        assert module["sha256"]==digest
        base=0x40230000 if name=="ceddk.dll" else 0xc0420000
        item,_=source(module,[base+v for v in (0x3994,0x3a2c,0x3c98,0x3e68,0x3f24,0x3f84)],{})
        sources.append(item)
    durations=[]
    # PCM-duration scenarios, not tests of device configuration or measured delay.
    for name,rates in (("wavedev2_i2s.dll",(44100,48000)),("wavedev2_i2s2.dll",(8000,))):
        quantum=SPECS[name]["quantum"]
        for rate in rates:
            durations.append(dict(module=name,rate=rate,channels=2,bits=16,bytes_per_fragment=quantum,
                one_fragment_pcm_ms=quantum*1000/(rate*4),two_full_fragments_pcm_ms=quantum*2000/(rate*4)))
    evidence=dict(sources=sources,producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        interpreter_sha256=hashlib.sha256((ROOT/"tools/inspect_bt_lifecycle.py").read_bytes()).hexdigest(),
        wave_queue_helper_sha256=hashlib.sha256((ROOT/"tools/inspect_wave_queue.py").read_bytes()).hexdigest(),
        wave_stream_helper_sha256=hashlib.sha256((ROOT/"tools/inspect_wave_streams.py").read_bytes()).hexdigest(),
        checks=dict(original_ranges=sum(len(s["ranges"]) for s in sources),prime_cases=len(cases)),
        native_execution=False,cases=cases,pcm_duration_scenarios=durations,
        hal_scope="Statically reviewed/pinned, not interpreted; channel/descriptor/register allocation and hardware are unmodeled",
        limitations=["Mixer renderer, next-buffer choice, activation and hardware-start returns are explicit fixtures",
          "No proof injected FALSE activation is reachable after ordinary valid local HAL buffer selection",
          "Two primer calls are not proof that both fragments contain audio or of total pipeline capacity",
          "PCM durations are scenarios, not audible unit latency; exact driver/device/mixer selection remains open",
          "Interrupt loop and HAL descriptor ownership are statically followed, not scheduling-emulated"])
    out=ROOT/"analysis/firmware/wave-dma";out.mkdir(parents=True,exist_ok=True)
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
    print(json.dumps(dict(status="passed",**evidence["checks"],pcm_duration_scenarios=durations),indent=2))


if __name__=="__main__":main()
