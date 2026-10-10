"""Capture static ROM wave-device registration, PSC and DMA evidence."""
import hashlib
import json
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]


def pcm_format_accepted(tag,channels,bits,rate):
    return tag==1 and 1<=channels<=2 and bits in (8,16) and 100<=rate<=192000


def i2s2_hardware_rate_result(requested,list_empty=True):
    """Leaf-helper result, not the whole wave-open return value."""
    return (8000 if requested==8000 else 0)if list_empty else 1


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    ranges={
        "wavedev2_i2s.dll":[(0xc09420ac,0xc094284c),(0xc09428b4,0xc09429e0),
                            (0xc0942d00,0xc0942e28),(0xc09432d4,0xc0943384),
                            (0xc0947b48,0xc0947cdc),(0xc0947ddc,0xc09489ec),
                            (0xc09489ec,0xc0948a98),(0xc0941c88,0xc0941cc8)],
        "wavedev2_i2s2.dll":[(0xc095210c,0xc09528ac),(0xc095291c,0xc09529d4),
                             (0xc09533a0,0xc0953490),(0xc0958074,0xc0958834),
                             (0xc0951d7c,0xc0951dbc)],
        "audevman.dll":[(0xc0411d2c,0xc0411e84),(0xc04124b4,0xc04127dc),
                         (0xc041308c,0xc04130fc),(0xc04137d0,0xc0413eec)],
        "waveapi.dll":[(0xc03f29f8,0xc03f2a7c),(0xc03f51b0,0xc03f53e0)]}
    sources={};evidence=[]
    for name,blocks in ranges.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        path=ROOT/module["path"];digest=hashlib.sha256(path.read_bytes()).hexdigest()
        if digest!=module["sha256"]:raise ValueError("Inventory source hash mismatch")
        sources[name]=digest;pe=pefile.PE(str(path));base=pe.OPTIONAL_HEADER.ImageBase
        for start,end in blocks:
            raw=pe.get_data(start-base,end-start)
            if len(raw)!=end-start:raise ValueError("Incomplete binary evidence")
            evidence.append(dict(module=name,start_va=hex(start),end_va_exclusive=hex(end),
                                 raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    reg=ROOT/"analysis/firmware/boot-registry/default.validated.reg"
    text=reg.read_text(encoding="utf-16");registry_sections={}
    for name in ("WaveDevI2S","WaveDevI2S2"):
        key="[HKEY_LOCAL_MACHINE\\Drivers\\BuiltIn\\"+name+"]"
        section=text.split(key,1)[1].split("\n[",1)[0].strip()
        registry_sections[name]=section
    assert pcm_format_accepted(1,1,16,48000)
    assert pcm_format_accepted(1,1,16,8000)
    assert not pcm_format_accepted(1,3,16,8000)
    assert not pcm_format_accepted(1,1,24,8000)
    assert i2s2_hardware_rate_result(8000)==8000
    assert i2s2_hardware_rate_result(48000)==0
    assert i2s2_hardware_rate_result(48000,False)==1
    result=dict(source_hashes=sources,evidence=evidence,
                boot_registry_sha256=hashlib.sha256(reg.read_bytes()).hexdigest(),
                boot_registry_sections=registry_sections,
                drivers=[dict(name="wavedev2_i2s.dll",registry_index=0,registry_order=0,
                              psc_logical_number=2,mmio_physical="0x10a02000",mmio_bytes=32,
                              dma_transmit_selector=12,dma_receive_selector=13,
                              initial_psc_configuration="0xf41d34f0",hardware_rate_initial=48000),
                         dict(name="wavedev2_i2s2.dll",registry_index=1,registry_order=1,
                              psc_logical_number=0,mmio_physical="0x10a00000",mmio_bytes=32,
                              dma_transmit_selector=18,dma_receive_selector=19,
                              initial_psc_configuration="0xf42c60f0",hardware_rate_accepted=8000)],
                wave_device_count_per_driver=dict(input=1,output=1),
                pcm_validator=dict(format_tag=1,channels=[1,2],bits=[8,16],min_rate=100,max_rate=192000,
                                   scope="Common PCM-format validator, not a guarantee hardware rate setup succeeds"),
                wave_ioctl="0x1d000c",wave_ioctl_input_bytes=20,
                power_ioctls=["0x321000","0x321004","0x321008","0x32100c"],
                mixer_ioctl="0x80000100",required_caller_trust=2,
                device_registration="Dynamic notification order; separate input/output arrays append devices and can be reordered",
                open_points=["Actual unit device ID order and audmSet*DeviceId callers",
                             "Physical codec, microphone and Bluetooth-chip wiring",
                             "All input/output mixing/resampling kernels and coefficients",
                             "CEDDK DMA mapping and hardware-state behavior"])
    (ROOT/"analysis/firmware/wave-driver-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps({"source_hashes":sources,"drivers":result["drivers"],"offline_contract_checks":"passed"},indent=2))


if __name__=="__main__":main()
