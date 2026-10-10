"""Preserve offline USB/JACM serial evidence and check independently reconstructed layouts."""
import hashlib
import json
import re
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
SOURCES = {
    "USBware2.dll": "ca083a856a7aa6b7a74792f9775e534a84583c01a48760a09a51266c4136eaab",
    "jacmdev.dll": "60dc6104d7d117c835b864d7bcdf2ada0a7b8c42cad7556eade17055bd508b23",
    "jacminit.exe": "9b182b70fdd2caa207043f8672cce23a0014bb8e172722904d8061305b9888ff",
}
FUNCTIONS = {
    "USBware2.dll": [0xc08246fc,0xc082a364,0xc082a3e0,0xc082a41c,0xc082a460,
        0xc082a5b4,0xc082a920,0xc082a970,0xc082ab4c,0xc082ac58,0xc082b0fc,
        0xc082b368,0xc082b4ec,0xc082b5bc,0xc082b5e0,0xc082b604,0xc082b628,
        0xc082b70c,0xc082b79c,0xc082be44,0xc082c0bc,0xc082c2e8,0xc082c3bc,
        0xc082c81c,0xc082ca1c,0xc083385c,0xc0833a44,0xc0834550,0xc0834a84,
        0xc08356f8,0xc0835800,0xc083582c,0xc08364f8],
    "jacmdev.dll": [0xc084191c,0xc0841d54,0xc0841fe0,0xc08423f4,0xc08425f4,
        0xc084266c,0xc0843180,0xc0843800,0xc0843c48,0xc0843f04,0xc084409c,
        0xc0844894,0xc084583c,0xc0845b18,0xc0845e54],
    "jacminit.exe": [0x1151c],
}


def main():
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources = []; pes = {}
    for name, digest in SOURCES.items():
        module = next(m for m in modules if m["origin"] == "rom" and m["name"] == name)
        path = ROOT/module["path"]
        assert hashlib.sha256(path.read_bytes()).hexdigest() == digest, "Source changed"
        pe = pefile.PE(str(path)); pes[name] = pe
        index = json.loads((ROOT/"analysis/functions/rom"/(name+".json")).read_text(encoding="utf-8"))
        functions = {int(f["begin_va"],16):f for f in index["functions"]}
        ranges = [(va, int(functions[va]["end_va"],16)-va, "Original .pdata function") for va in FUNCTIONS[name]]
        if name == "USBware2.dll":
            ranges += [(0xc08390d8,12,"Default function configuration"),
                       (0xc0839164,28,"Function initializer and USB-to-COM callbacks")]
        if name == "jacmdev.dll":
            ranges += [(0xc0841400,64,"Leaf registration: v0 returns the existing serial object"),
                       (0xc0841440,16,"Leaf unregister"),
                       (0xc08470ec,20,"Reverse callbacks and global object"),
                       (0xc084103c,0xd0,"Serial implementation vtable"),
                       (0xc0841114,120,"Serial PDD wrapper table")]
        evidence = []
        for va, size, role in ranges:
            raw = pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase,size)
            assert len(raw) == size, "Truncated original bytes"
            evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),
                                 sha256=hashlib.sha256(raw).hexdigest()))
        sources.append(dict(name=name,sha256=digest,evidence=evidence))
    pe = pes["USBware2.dll"]; base = pe.OPTIONAL_HEADER.ImageBase
    assert struct.unpack("<3I",pe.get_data(0xc08390d8-base,12)) == (6,1,0)
    assert struct.unpack("<2I",pe.get_data(0xc0839164-base,8)) == (6,0xc082c81c)
    callbacks = struct.unpack("<3I",pe.get_data(0xc0839174-base,12))
    assert callbacks == (0xc082a460,0xc082a5b4,0xc082a920)
    # Independent descriptor argument model, following zero allocation + flag branches.
    flags = 0x1f
    args = dict(subclass=0,protocol=0,interrupt_endpoint=0,bulk_pair=1,
                split_interface=0,functional_descriptor=0,vendor_variant=int(bool(flags&1)))
    if not flags&0x10: args["interrupt_endpoint"] = 1
    if not flags&2:
        args["subclass"] = 2; args["protocol"] = 0xff if flags&8 else 1
    if not flags&4: args["functional_descriptor"] = 0xc082ca1c
    assert args == dict(subclass=0,protocol=0,interrupt_endpoint=0,bulk_pair=1,
                       split_interface=0,functional_descriptor=0,vendor_variant=1)
    descriptor = dict(interfaces=1,interface_class=[255,255,255],bulk_endpoints=2,
                      interrupt_endpoints=0,cdc_functional_descriptor=False,
                      max_packet_full_speed=64,max_packet_high_speed=512)
    registry = (ROOT/"analysis/firmware/boot-registry/default.validated.reg").read_text(encoding="utf-16")
    blocks = re.split(r"(?=\[HKEY)",registry)
    selected = [b for b in blocks if any(k in b for k in (
        "BuiltIn\\jacmdev]","BuiltIn\\jacmdev\\Unimodem]","Comm\\Ras\\Init]",
        "Comm\\Ras\\Init\\RasEntry\\Entry1]","[HKEY_CURRENT_USER\\ControlPanel\\Comm]"))]
    assert len(selected) == 5
    assert '"Index"=dword:00000005' in registry and '"dwfOptions"=hex:08,02' in registry
    ring_models = []
    for capacity in (2048,4096):
        for read,write,requested in ((0,100,30),(capacity-10,20,25),(50,50,80)):
            available = (write-read)%capacity
            copied = min(available,capacity-read,requested)
            after = (read+copied)%capacity
            assert (write-after)%capacity == available-copied
            ring_models.append(dict(capacity=capacity,read=read,write=write,requested=requested,
                                    available=available,contiguous_copy=copied,read_after=after))
    result = dict(binary_execution=False,sources=sources,default_flags=flags,
        descriptor_arguments=args,default_descriptor_model=descriptor,
        usb_to_serial_callbacks=[hex(x) for x in callbacks],registry_blocks=selected,
        rx_buffer_count=10,ring_models=ring_models,
        request_handlers={hex(k):hex(v) for k,v in {0x20:0xc082be44,0x21:0xc082c0bc,
                            0x22:0xc082c2e8,0x23:0xc082c3bc}.items()},
        static_observations=[
            dict(module="USBware2.dll",va="0xc082c0bc",issue="GET_LINE_CODING reads 7 uninitialized stack bytes after no-op callback returns success"),
            dict(module="USBware2.dll",va="0xc0833a44",issue="Allocation failure still writes local_10[3], a NULL dereference on that branch"),
            dict(module="jacmdev.dll",va="0xc084427c",issue="COM_Read ignores CeSafeCopyMemory result and advances consumed-byte counters"),
            dict(module="jacminit.exe",va="0x1191c",issue="Boot dwfOptions is 2 bytes, scratch DWORD is not initialized before query/copy")],
        unknown=["Active unit role and enumeration", "Host driver compatibility", "PPP/authentication and replication service",
                 "Runtime consequences of static observations", "Complete IRQ/DMA and detach lifetime"])
    (ROOT/"analysis/firmware/usb-serial-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(source_modules=len(sources),evidence_ranges=sum(len(s["evidence"]) for s in sources),
                         ring_models=len(ring_models),descriptor=descriptor),indent=2))


if __name__ == "__main__": main()
