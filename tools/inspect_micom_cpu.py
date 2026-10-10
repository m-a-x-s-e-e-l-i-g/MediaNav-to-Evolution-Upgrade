"""Candidate RL78/78K0R-family recursive decoding; CPU identification is not proof."""
from pathlib import Path
import sys
import json
import struct
import hashlib
from collections import Counter

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/"sources/rl78dec"))
from rl78dec import decoder, decompile_image


def main():
    out=ROOT/"analysis/firmware";out.mkdir(exist_ok=True)
    image=(out/"micom-image.bin").read_bytes()
    vectors=[dict(offset=hex(i),target=hex(struct.unpack_from("<H",image,i)[0])) for i in range(0,0x80,2)]
    callt=[dict(offset=hex(i),target=hex(struct.unpack_from("<H",image,i)[0])) for i in range(0x80,0xc0,2)]
    # CALLT targets are separate roots: upstream recursive decoder follows direct calls only.
    roots=sorted({int(v["target"],16) for v in vectors+callt if 0<int(v["target"],16)<len(image) and v["target"]!="0xffff"})
    program=decompile_image(image,roots)
    (out/"rl78-candidates.c").write_text(program.listing(),encoding="utf-8")
    listing=[]
    for ea,ins in sorted(program.insns.items()):
        operands=[]
        for op in ins.ops:
            operands.append({slot:getattr(op,slot) for slot in op.__slots__ if getattr(op,slot) is not None})
        listing.append(dict(address=hex(ea),bytes=ins.raw.hex(),size=ins.size,mnemonic=ins.mnem,operands=operands))
    (out/"rl78-instructions.json").write_text(json.dumps(listing,indent=2),encoding="utf-8")
    covered={i for ea,ins in program.insns.items() for i in range(ea,ea+ins.size)}
    failed=[]
    for ea,ins in program.insns.items():
        for how,target in decoder._succ(ins):
            if target is not None and 0<=target<len(image) and target not in program.insns:
                failed.append(dict(source=hex(ea),target=hex(target),edge=how))
    result=dict(flat_sha256=hashlib.sha256(image).hexdigest(),architecture_assumption="RL78-compatible/78K0R family candidate",
                exact_cpu_identified=False,scope="Decoder candidates; invalid paths and indirect transfers remain unresolved",
                vector_table=vectors,callt_table=callt,roots=[hex(r) for r in roots],
                decoded_instructions=len(program.insns),covered_bytes=len(covered),image_bytes=len(image),
                functions=len(program.funcs),mnemonics=dict(Counter(ins.mnem for ins in program.insns.values())),
                unresolved_in_image_edges=failed)
    (out/"micom-cpu-candidates.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps({k:v for k,v in result.items() if k not in ("vector_table","callt_table","mnemonics","unresolved_in_image_edges")},indent=2))
    print("Unresolved edges:",len(failed))


if __name__=="__main__":main()
