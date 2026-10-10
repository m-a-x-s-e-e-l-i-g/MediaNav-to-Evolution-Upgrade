"""Static initial-data pointer candidates and explicit timer registrations.

No MCU execution. Pointer bindings describe initializer values, not mutable RAM
at runtime. Only straight-line canonical load sequences are matched.
"""
from pathlib import Path
import hashlib
import json
import struct
from inspect_micom_flow import decoder, traverse, stats, export_listing, ROOT

SRC=0x6ec2
END=0x758e
DEST=0xfe3d2


def rom_at(ram, width=1):
    if not DEST <= ram or ram+width > DEST+(END-SRC): return None
    return SRC+ram-DEST


def word(image, ram):
    at=rom_at(ram,2)
    return struct.unpack_from("<H",image,at)[0] if at is not None else None


def window_index(insns):
    # Incoming branches, non-fallthrough gaps and all earlier calls terminate
    # the window. An alternative path may have different register definitions.
    incoming=set()
    for i in insns.values():
        if i.mnem in ("br","bc","bnc","bz","bnz","bh","bnh","bt","bf","btclr"):
            t=decoder.target_of(i)
            if t is not None:incoming.add(t)
        if i.mnem in ("skc","sknc","skz","sknz","skh","sknh"):
            nxt=insns.get(i.ea+i.size)
            if nxt:incoming.add(nxt.ea+nxt.size)
    return incoming,{i.ea+i.size:i for i in insns.values()}


def backward_window(index, ea):
    incoming,ends=index
    window=[]
    while len(window)<24:
        if ea in incoming: break
        i=ends.get(ea)
        if i is None or i.mnem in ("call","callt","br","ret","reti","retb","brk","brk1","stop","halt", "skc","sknc","skz","sknz","skh","sknh"):
            break
        window.append(i)
        ea=i.ea
    return list(reversed(window))


def is_reg(op,name): return op.mode=="reg" and op.reg==name


def match_object(image, window, call):
    # Canonical global pointer load -> alias -> high-byte load -> CS -> lowword.
    for ix,ins in enumerate(window):
        if ins.mnem!="movw" or len(ins.ops)!=2: continue
        dst,src=ins.ops
        if dst.mode!="reg" or src.mode!="mem" or src.es: continue
        ptr=word(image,src.addr)
        if ptr is None or not ptr: continue
        base=dst.reg
        high=None;cs_source=None;low=None;loaded_reg=None
        for j in window[ix+1:]:
            if len(j.ops)!=2: continue
            a,b=j.ops
            if j.mnem=="movw" and a.mode=="reg" and b.mode=="reg" and b.reg==base and low is None:
                base=a.reg
            elif j.mnem=="mov" and is_reg(a,"a") and b.mode=="ind" and not b.es and b.base_reg==base:
                high=(j.ea,b.disp)
            elif j.mnem=="mov" and is_reg(a,"cs") and is_reg(b,"a") and high:
                cs_source=high
            elif j.mnem=="movw" and a.mode=="reg" and b.mode=="ind" and not b.es and b.base_reg==base and cs_source and b.disp+2==cs_source[1]:
                low=(j.ea,b.disp);loaded_reg=a.reg
            elif j.mnem=="movw" and a.mode=="reg" and b.mode=="reg" and b.reg==loaded_reg and low:
                loaded_reg=a.reg
        if low is None or cs_source is None or call.ops[0].reg!=loaded_reg: continue
        slot=0xf0000+ptr+low[1]
        at=rom_at(slot,4)
        if at is None:continue
        raw=image[at:at+4]
        target=int.from_bytes(raw[:3],"little")
        if raw[3] or raw[2]>=0x10 or not 0<target<len(image):continue
        return dict(kind="initial RAM object pointer",call=hex(call.ea),global_ram=hex(src.addr),
                    global_rom=hex(rom_at(src.addr,2)),initial_pointer=hex(ptr),field_offset=hex(low[1]),
                    slot_ram=hex(slot),slot_rom=hex(at),slot_bytes=raw.hex(),target=hex(target),
                    evidence=[dict(address=hex(i.ea),bytes=i.raw.hex()) for i in window[ix:]]+[dict(address=hex(call.ea),bytes=call.raw.hex())],
                    runtime_target_proven=False)
    return None


def match_timer(window,call):
    if len(window)<3:return None
    lo,hi,clear=window[-3:]
    if (lo.mnem=="movw" and len(lo.ops)==2 and is_reg(lo.ops[0],"ax") and lo.ops[1].mode=="imm"
        and hi.mnem=="mov" and len(hi.ops)==2 and is_reg(hi.ops[0],"c") and hi.ops[1].mode=="imm"
        and clear.mnem=="clrb" and is_reg(clear.ops[0],"b")):
        target=lo.ops[1].value|(hi.ops[1].value<<16)
        if target<0x40000 and target:
            return dict(kind="explicit timer callback",call=hex(call.ea),target=hex(target),
                        evidence=[dict(address=hex(i.ea),bytes=i.raw.hex()) for i in (lo,hi,clear,call)],
                        runtime_callback_proven=False)
    return None


def verify_object_binding(image,binding):
    # Guard against an apparent pointer load whose call register was overwritten
    # by later argument preparation. Audit the original instruction sequence.
    ins=[decoder.decode_one(image,int(e["address"],16)) for e in binding["evidence"]]
    offset=int(binding["field_offset"],16)
    positions=[j for j,i in enumerate(ins[:-1]) if i.mnem=="movw" and len(i.ops)==2
               and i.ops[1].mode=="ind" and i.ops[1].disp==offset]
    assert positions
    j=positions[-1]
    high,cs,low=ins[j-2:j+1]
    assert high.mnem=="mov" and is_reg(high.ops[0],"a")
    assert high.ops[1].mode=="ind" and high.ops[1].base_reg==low.ops[1].base_reg and high.ops[1].disp==offset+2
    assert cs.mnem=="mov" and is_reg(cs.ops[0],"cs") and is_reg(cs.ops[1],"a")
    live={low.ops[0].reg}
    halves={"a":"ax","x":"ax","b":"bc","c":"bc","d":"de","e":"de","h":"hl","l":"hl"}
    writes={"mov","clrw","clrb","pop","incw","decw","addw","subw","inc","dec","onew","oneb",
            "and","or","xor","add","sub","shrw","shlw","sarw","xch","xchw"}
    for i in ins[j+1:-1]:
        if i.mnem=="movw" and len(i.ops)==2 and i.ops[0].mode=="reg":
            a,b=i.ops;valid=b.mode=="reg" and b.reg in live
            live.discard(a.reg)
            if valid:live.add(a.reg)
        elif i.ops and i.ops[0].mode=="reg" and i.mnem in writes:
            live.discard(halves.get(i.ops[0].reg,i.ops[0].reg))
        assert not(i.mnem=="mov" and i.ops and is_reg(i.ops[0],"cs")),binding["call"]
    assert ins[-1].ops[0].reg in live,binding["call"]


def main():
    source=ROOT/"analysis/firmware"
    image=(source/"micom-image.bin").read_bytes()
    prior=json.loads((source/"flow-tables/micom-cpu-candidates.json").read_text(encoding="utf-8"))
    assert hashlib.sha256(image).hexdigest()==prior["flat_sha256"]
    boot={0x3f6:"4100",0x3f8:"36c26e",0x3fb:"34d2e3",0x400:"118b",0x402:"99",0x403:"a7",0x404:"a5",0x406:"448e75",0x409:"dff5"}
    for at,raw in boot.items():assert image[at:at+len(bytes.fromhex(raw))].hex()==raw
    initial=image[SRC:END]
    roots={int(a,16) for a in prior["roots"]}
    original=set(roots)
    bindings={};rounds=[]
    for n in range(12):
        insns,edges,gaps=traverse(image,sorted(roots))
        windows=window_index(insns)
        added=set()
        for ea,ins in sorted(insns.items()):
            target=decoder.target_of(ins)
            if ins.mnem!="call":continue
            if target is None:
                binding=match_object(image,backward_window(windows,ea),ins)
            elif target==0x7dea:
                binding=match_timer(backward_window(windows,ea),ins)
            else:continue
            if binding:
                binding["discovery_round"]=n
                bindings.setdefault((binding["kind"],ea,binding["target"]),binding)
                t=int(binding["target"],16)
                if t not in roots:added.add(t)
        rounds.append(dict(round=n,instructions=len(insns),new_roots=[hex(a) for a in sorted(added)]))
        if not added:break
        roots|=added
    else:raise RuntimeError("Pointer closure round limit exceeded; no complete export")
    old=json.loads((source/"flow-tables/rl78-instructions.json").read_text(encoding="utf-8"))
    assert all(insns[int(i["address"],16)].raw.hex()==i["bytes"] for i in old)
    audited=0
    for binding in bindings.values():
        if binding["kind"]=="initial RAM object pointer":
            verify_object_binding(image,binding)
            audited+=1
    result=dict(flat_sha256=prior["flat_sha256"],exact_cpu_identified=False,binary_execution=False,
                roots=[hex(a) for a in sorted(roots)],initial_root_count=len(original),
                architecture_assumption=prior["architecture_assumption"],
                initializer=dict(rom_start=hex(SRC),rom_end_exclusive=hex(END),ram_start=hex(DEST),ram_end_exclusive=hex(DEST+len(initial)),
                                 bytes=len(initial),sha256=hashlib.sha256(initial).hexdigest(),preimages={hex(a):b for a,b in boot.items()}),
                initial_ram_pointer_bindings=list(bindings.values()),rounds=rounds,
                binding_audit=dict(object_sequences_checked=audited,scope="Adjacent high-byte/CS/lowword and preserved call-register provenance"),
                candidate=stats(insns,edges,gaps),edges=edges,
                producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
                limitations=["Only initial data values; writes and hardware state may change any runtime target",
                    "Strict straight-line object-load patterns and three-instruction timer construction only",
                    "Matched incoming branches terminate windows; entry/resume transfers remain unmodelled",
                    "Callsites remain unresolved runtime boundaries; seeded candidates are not exact reachability",
                    "Candidate CPU semantics, zero-fill and stack ABI need chip validation"])
    out=source/"flow-startup"
    export_listing(out,image,insns,{int(i["address"],16) for i in old})
    (out/"initial-ram.bin").write_bytes(initial)
    (out/"micom-cpu-candidates.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(instructions=len(insns),new_instructions=len(insns)-len(old),roots=len(roots),bindings=len(bindings),rounds=rounds,
                         overlaps=len(result["candidate"]["overlaps"]),boundaries=len(gaps)),indent=2))


if __name__=="__main__":main()
