"""Preserve original navigation-content/error contracts. No firmware execution or license patch."""
import hashlib
import json
import struct
from pathlib import Path
from inspect_bt_playback import source

ROOT=Path(__file__).resolve().parents[1]
NAV_HASH="d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9"


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module=next(m for m in modules if m["origin"]=="corruption-fix" and m["name"]=="nngnavi.exe")
    assert module["sha256"]==NAV_HASH
    addresses=[0x3a48f4,0x3a4f38,0x3a61a8,0x3a4570,0x3a3cc8,0x3a5904,0x3a6844,0x4f8e48,0x4fae54]
    evidence,pe=source(module,addresses,{})
    base=pe.OPTIONAL_HEADER.ImageBase
    preimages={0x4faeac:0x15280003,0x4faeb4:0x10000295,0x4faeb8:0x24020000,
        0x4fb908:0x24020001,0x4f8ea8:0x1440000a}
    for va,word in preimages.items():assert struct.unpack("<I",pe.get_data(va-base,4))[0]==word
    tables=[]
    for va in [0x96b3a0,0x900638,0x900650,0x900668]:
        raw=pe.get_data(va-base,24);assert len(raw)==24
        tables.append(dict(va=hex(va),bytes=24,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest(),
            values=[hex(n) for n in struct.unpack("<6I",raw)]))
    ptrs,magics,minimum,maximum=[struct.unpack("<6I",bytes.fromhex(t["raw_hex"])) for t in tables]
    patterns=[]
    for va in ptrs:
        raw=pe.get_data(va-base,48);end=next(i for i in range(0,len(raw),2) if raw[i:i+2]==b"\0\0")
        raw=raw[:end+2];pattern=raw[:-2].decode("utf-16le")
        patterns.append(dict(va=hex(va),pattern=pattern,raw_hex=raw.hex()))
    assert [p["pattern"] for p in patterns]==["*.fbl","*.fjv","*.fpa","*.fsp","*.ftr","*.fda"]
    assert magics==(0x07067619,0xa618ab04,0x4536abc6,0xd6d3bb98,0xd6c3abb1,0x26b3afb1)
    assert minimum==(700,1,1,1,1,1) and maximum==(900,200,200,200,200,200)
    categories=[dict(index=i,pattern=p["pattern"],magic=hex(magics[i]),magic_le=struct.pack("<I",magics[i]).hex(),
        minimum_format_version=minimum[i],maximum_format_version=maximum[i],
        accepted_vector_begin_offset=hex(0x18+i*12),accepted_vector_end_offset=hex(0x1c+i*12),
        outdated_count_offset=hex(0xa8+i*4),license_reject_count_offset=hex(0xc0+i*4)) for i,p in enumerate(patterns)]
    actual=[]
    suffixes={p["pattern"][1:] for p in patterns}
    for origin in ["705md","remove-md","corruption-fix"]:
        for path in (ROOT/"extracted"/origin).rglob("*"):
            if path.is_file() and path.suffix.lower() in suffixes:actual.append(str(path.relative_to(ROOT)))
    result=dict(binary_execution=False,binary_changed=False,source=evidence,tables=tables,pattern_strings=patterns,
        checks=dict(original_ranges=len(addresses),exact_instruction_preimages=len(preimages),categories=len(categories),
            real_content_files_in_available_payloads=len(actual)),categories=categories,available_content_files=actual,
        corruption_dialog=dict(caller="0x4f8e48",call_va="0x4f8ea0",callee="0x4fae54",branch_va="0x4f8ea8",
            string_va="0x948c90",show_va="0x4f8ec4",exit_request_va="0x4f8ecc",
            manager_global_va="0x984374",manager_begin_offset="0x18",manager_end_offset="0x1c",
            zero_return_condition="On normal return: first accepted-content vector has begin == end",
            normal_nonempty_return=1,empty_return=0,
            rejected_record_loads_note="Individual later load failures do not change this routine's final success return"),
        content_scan=dict(callback="0x3a61a8",reader="0x3a5904",cache="mapmanagerizr",cache_reader="0x3a4570",
            cache_validation="0x3a3cc8",append="0x3a6844",header_read_bytes=2048,
            header_magic_offset=0,header_format_version_offset=4,license_interface_slot="+0x1c",
            distinctions="Version bounds and distributor decision gate append; this is not a replacement license validator"),
        limitations=["Only the provided navi-fix binary is available, not the current unit executable or same-version original",
            "No real map/content files are present in the available payloads; no unit content header was validated",
            "The matching user-visible text on the installed engine may follow a different branch",
            "Cache serialization, stream implementation, distributor internals and full section parsing remain open",
            "No navigation checks were patched and no files were written outside analysis outputs"])
    out=ROOT/"analysis/firmware/navigation-content-contracts.json"
    out.write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"],corruption_condition=result["corruption_dialog"]["zero_return_condition"]),indent=2))


if __name__=="__main__":main()
