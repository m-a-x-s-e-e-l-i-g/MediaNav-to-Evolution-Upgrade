"""Inventory the build-selected PSR blocks referenced by Blue.exe's bootstrap code."""
from pathlib import Path
import json
import hashlib
import struct
import re
import pefile

ROOT=Path(__file__).resolve().parents[1]


def main():
    binary=ROOT/"extracted/705md/upgrade/Storage Card/System/Blue.exe"
    data=binary.read_bytes();pe=pefile.PE(data=data);base=pe.OPTIONAL_HEADER.ImageBase
    table_va=0x103a14
    table=pe.get_data(table_va-base,21*12)
    blocks={}
    def block_at(va):
        if hex(va) in blocks:return hex(va)
        offset=pe.get_offset_from_rva(va-base);end=data.index(bytes([0]),offset)
        raw=data[offset:end];text=raw.decode("ascii")
        entries=[];unknown=[]
        for line in text.splitlines():
            match=re.fullmatch(r"&([0-9A-Fa-f]{4})=([0-9A-Fa-f ]*)",line)
            if match:
                words=[int(w,16) for w in match[2].split()]
                assert all(0<=w<=65535 for w in words)
                entries.append(dict(key="0x"+match[1].lower(),words=len(words),data_sha256=hashlib.sha256(struct.pack("<"+"H"*len(words),*words)).hexdigest()))
            elif line:unknown.append(line[:160])
        blocks[hex(va)]=dict(file_offset=hex(offset),bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest(),records=entries,unparsed_lines=unknown)
        return hex(va)
    rows=[]
    for index in range(21):
        build,padding,pointer,flag=struct.unpack_from("<HHII",table,index*12)
        rows.append(dict(index=index,build_selector=build,build_selector_hex=hex(build),padding=padding,block_va=block_at(pointer),flag_raw=flag))
    # Additional literals manually traced in the same bootstrap selector function.
    for va in (0x103b1c,0x10c4bc,0x10c4c8,0x10c4d4):block_at(va)
    result=dict(binary_sha256=hashlib.sha256(data).hexdigest(),scope="Static PSR data and build-selection table; not an identified physical Bluetooth chip or executed patch",
                selector_function_va="0x7c1a8",table_va=hex(table_va),stride=12,count=21,rows=rows,blocks=blocks,
                unresolved="PS-key meanings, code payload ISA, bootstrap transport and active unit build")
    (ROOT/"analysis/firmware/bt-bootstrap.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print("Bluetooth bootstrap:",len(rows),"build selectors;",len(blocks),"referenced literal blocks;",
          sum(len(b['records']) for b in blocks.values()),"key records;",
          sum(len(b['unparsed_lines']) for b in blocks.values()),"unparsed lines")
    print("Build selectors:",[r["build_selector_hex"] for r in rows])


if __name__=="__main__":main()
