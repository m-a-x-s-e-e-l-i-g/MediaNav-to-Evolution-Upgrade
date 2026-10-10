"""Extract constant MAIN_Config schema construction from original MIPS instructions.

Bounded static constant propagation for thirteen known version branches only.
Does not load or run SSE and does not generate installable audio configurations.
"""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
WIDTHS={3:4,4:4,5:2,6:2,7:1,8:1}


def signed16(n):return n-65536 if n&32768 else n


def extract_count(pe,version):
    base=pe.OPTIONAL_HEADER.ImageBase
    displacement=struct.unpack("<b",pe.get_data(0x10025e50-base+version-1,1))[0]
    pc=0x10025e50+displacement
    known={0:0,17:57,13:50,14:56,15:36}
    # Each table target sets s1 then joins 10025ebc; account for the branch delay slot.
    for _ in range(3):
        if pc==0x10025ebc:return known[17]
        word=struct.unpack("<I",pe.get_data(pc-base,4))[0]
        op=word>>26;rs=(word>>21)&31;rt=(word>>16)&31;rd=(word>>11)&31
        if op==4 and rs==rt==0:
            if pc+4+signed16(word&65535)*4!=0x10025ebc:raise ValueError("Unexpected count branch")
        elif op==9 and rs in known:known[rt]=(known[rs]+signed16(word&65535))&0xffffffff
        elif op==0 and (word&63)==37 and (rs==0 or rt==0):known[rd]=known[rt if rs==0 else rs]
        else:raise ValueError(f"Unexpected count instruction {pc:#x}")
        pc+=4
        if op==4:
            delay=struct.unpack("<I",pe.get_data(pc-base,4))[0]
            dop=delay>>26;drs=(delay>>21)&31;drt=(delay>>16)&31;drd=(delay>>11)&31
            if dop==9 and drs in known:known[drt]=(known[drs]+signed16(delay&65535))&0xffffffff
            elif dop==0 and (delay&63)==37 and (drs==0 or drt==0):known[drd]=known[drt if drs==0 else drs]
            else:raise ValueError("Unexpected count delay slot")
            return known[17]
    raise ValueError("Count path exceeded bound")


def extract_template(pe,start,count):
    base=pe.OPTIONAL_HEADER.ImageBase
    # Constants established before the second version-switch (10025ec4..ee4).
    known={0:0,10:3,11:6,13:50,14:56,15:36,19:228}
    offsets={};types={};stores=[];pc=start;pending=None
    for _ in range(256):
        if pc==0x100264c0:break  # Parser call; no dynamic operation is followed.
        raw=pe.get_data(pc-base,4)
        word=struct.unpack("<I",raw)[0]
        op=word>>26;rs=(word>>21)&31;rt=(word>>16)&31;rd=(word>>11)&31
        imm=signed16(word&65535)
        branch=None
        if word==0:pass
        elif op==9:
            if rs in known:known[rt]=(known[rs]+imm)&0xffffffff
            else:known.pop(rt,None)
        elif op==0 and (word&63)in (33,37) and (rs==0 or rt==0):
            src=rt if rs==0 else rs
            if src in known:known[rd]=known[src]
            else:known.pop(rd,None)
        elif op==35 and pc==0x100264a8:
            # The common epilogue loads the parser's dynamic context argument.
            # It contributes no schema literal; invalidate the loaded register.
            known.pop(rt,None)
        elif op in (40,43):
            if rs==29:
                if rt not in known:raise ValueError(f"Unknown template store at {pc:#x}")
                value=known[rt]
                if op==43 and 0x20<=imm<0x104:
                    if imm%4:raise ValueError("Unaligned field-vector store")
                    offsets[(imm-0x20)//4]=value
                elif op==40 and 0x288<=imm<0x2c1:
                    types[imm-0x288]=value&255
                stores.append(dict(va=hex(pc),width=1 if op==40 else 4,stack_offset=hex(imm),value=hex(value)))
            # A non-stack store in version >=9 sets a separate reference flag.
        elif op==4 and rs==0 and rt==0:
            branch=pc+4+imm*4
        else:raise ValueError(f"Unexpected template opcode at {pc:#x}: {word:08x}")
        known[0]=0
        next_pc=pc+4
        if pending is not None:next_pc=pending;pending=None
        if branch is not None:
            if next_pc!=pc+4:raise ValueError("Branch in a delay slot")
            pending=branch
        pc=next_pc
    else:raise ValueError("Template branch exceeded static bound")
    if any(i not in offsets or i not in types for i in range(count)):
        raise ValueError("Incomplete scalar template")
    fields=[dict(index=i,bsd_datatype=types[i],width_bytes=WIDTHS[types[i]],
                 destination_offset=(-1 if offsets[i]==0xffffffff else offsets[i]))for i in range(count)]
    return dict(fields=fields,payload_bytes=sum(f["width_bytes"]for f in fields),constant_stores=stores)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    m=next(x for x in modules if x["origin"]=="705md"and x["name"]=="sse_int.dll")
    path=ROOT/m["path"];digest=hashlib.sha256(path.read_bytes()).hexdigest()
    if digest!=m["sha256"]:raise ValueError("Source hash mismatch")
    pe=pefile.PE(str(path));base=pe.OPTIONAL_HEADER.ImageBase
    displacements=struct.unpack("<13h",pe.get_data(0x10025eec-base,26))
    counts=[extract_count(pe,version)for version in range(1,14)]
    if counts!=[29,36,37,38,41,46,50,51,52,53,54,56,57]:raise ValueError("Version count evidence changed")
    versions=[]
    for version,(offset,count)in enumerate(zip(displacements,counts),1):
        target=0x10025eec+offset
        versions.append(dict(version=version,target_va=hex(target),field_count=count,
                             **extract_template(pe,target,count)))
    raw=pe.get_data(0x10025d7c-base,0x10026500-0x10025d7c)
    result=dict(source_sha256=digest,source_start_va="0x10025d7c",source_end_va_exclusive="0x10026500",
                raw_hex=raw.hex(),raw_sha256=hashlib.sha256(raw).hexdigest(),
                scope="Static scalar field schemas; field semantics and live config contents remain separate",
                versions=versions)
    (ROOT/"analysis/firmware/sse-main-config-templates.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps([{k:v[k]for k in ("version","target_va","field_count","payload_bytes")}for v in versions],indent=2))


if __name__=="__main__":main()
