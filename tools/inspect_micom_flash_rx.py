"""Candidate chain from normal AA5 dispatch to ULC receive/programming code."""
from pathlib import Path
import hashlib
import json
import struct
from inspect_micom_flow import ROOT,traverse,stats,export_listing,decoder
from inspect_micom_startup import rom_at


def main():
    source=ROOT/"analysis/firmware"
    image=(source/"micom-image.bin").read_bytes()
    prior=json.loads((source/"flow-startup/micom-cpu-candidates.json").read_text(encoding="utf-8"))
    assert hashlib.sha256(image).hexdigest()==prior["flat_sha256"]
    global_ram=0xfe402
    pointer=struct.unpack_from("<H",image,rom_at(global_ram,2))[0]
    slot_ram=0xf0000+pointer+0xc
    slot_rom=rom_at(slot_ram,4)
    raw=image[slot_rom:slot_rom+4]
    target=int.from_bytes(raw[:3],"little")
    assert pointer==0xe6fe and target==0x1611c and raw.hex()=="1c610100"
    preimages={0x1567d:"317e",0x1567f:"0400e4",0x1568d:"790c00",0x15695:"61ea",
               0x16123:"8c42",0x16125:"2cfc",0x16150:"2c03",0x16154:"ee2b05",
               0x166a6:"fc931900",0x18c6:"4c55",0x18d3:"4c4c",0x18e6:"4c43",
               0x19c0:"300304",0x19d0:"440204",0x19dc:"0e03",0x19de:"9c03",0x19ea:"70",
               0x19fe:"318e",0x1a0f:"fc1f1900",0x1739:"adda",0x17ba:"fc830200",0x283:"ff",0x1988:"effe"}
    for ea,expected in preimages.items():
        assert image[ea:ea+len(bytes.fromhex(expected))].hex()==expected,(hex(ea),expected,image[ea:ea+4].hex())
    # Dispatch arithmetic is eight-bit: five wraps past FC, FD, FE, FF, 0, 1, 2.
    assert ((5-0xfc-1-1-1-1-1-1-3)&255)==0
    roots=[int(a,16) for a in prior["roots"]]+[target]
    insns,edges,gaps=traverse(image,roots)
    old=json.loads((source/"flow-startup/rl78-instructions.json").read_text(encoding="utf-8"))
    assert all(insns[int(i["address"],16)].raw.hex()==i["bytes"] for i in old)
    ranges=[]
    for label,start,end in (("ring consumer",0x1527c,0x15410),("normal frame dispatcher",0x155f0,0x1577c),
                            ("command switch",0x1611c,0x1619d),("command five",0x16682,0x166ad),
                            ("ULC framing and replies",0x183a,0x191f),("block wrapper",0x191f,0x1993),
                            ("ULC loop",0x1993,0x1a24),("programming routine",0x14f5,0x183a)):
        b=image[start:end]
        ranges.append(dict(label=label,start=hex(start),end_exclusive=hex(end),bytes=b.hex(),sha256=hashlib.sha256(b).hexdigest()))
    result=dict(flat_sha256=prior["flat_sha256"],architecture_assumption=prior["architecture_assumption"],
                exact_cpu_identified=False,binary_execution=False,roots=[hex(a) for a in sorted(set(roots))],
                additional_route=dict(frame="aa110500be",manager=1,type=1,command=5,dispatch_call="0x15695",
                    global_ram=hex(global_ram),global_rom=hex(rom_at(global_ram,2)),initial_pointer=hex(pointer),
                    field_offset="0xc",slot_ram=hex(slot_ram),slot_rom=hex(slot_rom),slot_bytes=raw.hex(),target=hex(target),
                    command_five_branch="0x16682",direct_update_call="0x166a6",update_entry="0x1993",runtime_selection_proven=False),
                preimages={hex(a):b for a,b in preimages.items()},source_ranges=ranges,
                candidate=stats(insns,edges,gaps),edges=edges,
                producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
                limitations=["Initial RAM route binding under candidate ISA, not installed-unit state",
                    "Programming helper/status meanings, physical addresses and BRK1 vector/reset effect unresolved",
                    "Flag one/four paths call further helpers after programming; no simple reboot-only assumption",
                    "UART waits and native stack/heap effects not executed"])
    out=source/"flow-update"
    export_listing(out,image,insns,{int(i["address"],16) for i in old})
    (out/"micom-cpu-candidates.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(instructions=len(insns),added=len(insns)-len(old),source_ranges=len(ranges),preimages=len(preimages),
                         overlaps=len(result["candidate"]["overlaps"]),boundaries=len(gaps)),indent=2))


if __name__=="__main__":main()
