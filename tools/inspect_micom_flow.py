"""Offline candidate MCU traversal with full conditional-skip edges.

Leaves vendor decoder and prior exports unchanged. This explores possible paths
under an ISA assumption, without execution or claims about the physical MCU.
"""
from pathlib import Path
from collections import Counter
import hashlib
import json
import struct
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "sources/rl78dec"))
from rl78dec import decoder, isa

MANUAL = "https://www.renesas.com/en/document/mas/78k0r-microcontrollers-users-manual-instructions"
LIMIT = 40000


def successors(image, ins, conservative=True):
    if ins.mnem in isa.SKIP:
        next_ea = ins.ea + ins.size
        following = decoder.decode_one(image, next_ea)
        out = [("skip_false", next_ea)]
        if following is not None and following.size and following.mnem != ".db":
            out.append(("skip_true", next_ea + following.size))
        return out
    if conservative and ins.mnem in ("brk1", ".db", "halt"):
        return []  # trap/resume/invalid semantics deliberately left unresolved
    if ins.mnem == "callt":
        slot = ins.ops[0].addr
        target = struct.unpack_from("<H", image, slot)[0] if 0 <= slot < len(image)-1 else None
        return [("callt", target), ("fall", ins.ea + ins.size)]
    return decoder._succ(ins)


def traverse(image, roots, conservative=True):
    insns, edges, gaps = {}, [], []
    seen, work = set(), list(roots)
    while work:
        ea = work.pop()
        if ea in seen:
            continue
        seen.add(ea)
        if len(seen) > LIMIT:
            raise RuntimeError("Candidate traversal limit exceeded")
        ins = decoder.decode_one(image, ea)
        if ins is None or not ins.size:
            gaps.append(dict(address=hex(ea), reason="decode failure or outside image"))
            continue
        insns[ea] = ins
        if ins.mnem in ("call", "br") and decoder.target_of(ins) is None:
            gaps.append(dict(address=hex(ea), reason="indirect transfer", mnemonic=ins.mnem))
        if conservative and ins.mnem in ("brk1", ".db", "halt"):
            gaps.append(dict(address=hex(ea), reason="trap/resume/invalid boundary", mnemonic=ins.mnem))
        if ins.mnem in isa.SKIP:
            following = decoder.decode_one(image, ea + ins.size)
            if following is None or not following.size or following.mnem == ".db":
                gaps.append(dict(address=hex(ea), reason="unknown skipped instruction length"))
        for kind, target in successors(image, ins, conservative):
            edges.append(dict(source=hex(ea), target=hex(target) if target is not None else None, kind=kind))
            if target is not None and 0 <= target < len(image):
                work.append(target)
            else:
                gaps.append(dict(address=hex(ea), target=hex(target) if target is not None else None,
                                 reason="out-of-image or unknown edge", kind=kind))
    return insns, edges, gaps


def operand(op):
    prefix = "ES:" if op.es else ""
    if op.mode == "reg": return op.reg.upper()
    if op.mode == "imm": return "#" + hex(op.value)
    if op.mode in ("mem", "near", "far", "callt"): return prefix + hex(op.addr)
    if op.mode in ("ind", "idx16"): return prefix + "[" + op.base_reg.upper() + ("+" + hex(op.disp) if op.disp else "") + "]"
    if op.mode == "hloff": return prefix + "[HL+" + op.base_reg.upper() + "]"
    if op.mode == "bit":
        base = op.reg.upper() if op.base == "reg" else (hex(op.addr) if op.base == "mem" else "["+op.base_reg.upper()+"]")
        return prefix + base + "." + str(op.bit)
    return json.dumps({s:getattr(op,s) for s in op.__slots__})


def record(ins):
    return dict(address=hex(ins.ea), bytes=ins.raw.hex(), size=ins.size, mnemonic=ins.mnem,
                operands=[{s:getattr(op,s) for s in op.__slots__ if getattr(op,s) is not None} for op in ins.ops])


def stats(insns, edges, gaps):
    owners, overlaps = {}, []
    for ea, ins in sorted(insns.items()):
        for byte in range(ea, ea + ins.size):
            if byte in owners:
                overlaps.append(dict(byte=hex(byte), first=hex(owners[byte]), second=hex(ea)))
            else:
                owners[byte] = ea
    return dict(instructions=len(insns), covered_bytes=len(owners),
                mnemonics=dict(Counter(i.mnem for i in insns.values())),
                overlaps=overlaps, unresolved_boundaries=gaps,
                unresolved_in_image_edges=[e for e in edges if e["target"] is not None and int(e["target"],16)<0x40000 and int(e["target"],16) not in insns])


def verify_skip_lengths():
    # Concrete instruction boundary checks, including an ES-prefixed load.
    cases = tuple(op+suffix for op in ("61c8","61d8","61e8","61f8","61e3","61f3")
                  for suffix in ("00d7", "ee0000d7", "fc001000d7", "118c00d7"))
    for raw in cases:
        image = bytes.fromhex(raw)
        ins = decoder.decode_one(image, 0)
        edges = successors(image, ins)
        assert edges == [("skip_false", 2), ("skip_true", len(image)-1)], (raw, edges)
    return len(cases)


def export_listing(out, image, insns, old_addresses):
    out.mkdir(exist_ok=True)
    (out/"rl78-instructions.json").write_text(json.dumps([record(i) for _,i in sorted(insns.items())],indent=2),encoding="utf-8")
    (out/"micom-image.bin").write_bytes(image)
    lines = ["; Candidate ISA; not device execution. + indicates absent in comparison list."]
    for ea,ins in sorted(insns.items()):
        lines.append(f"{ea:05x} {'+' if ea not in old_addresses else ' '} {ins.raw.hex():12} {ins.mnem:8} " + ", ".join(operand(o) for o in ins.ops))
    (out/"rl78-flow.asm").write_text("\n".join(lines)+"\n",encoding="utf-8")


def main():
    source = ROOT / "analysis/firmware"
    out = source / "flow-expanded"
    out.mkdir(exist_ok=True)
    image = (source / "micom-image.bin").read_bytes()
    previous = json.loads((source / "micom-cpu-candidates.json").read_text(encoding="utf-8"))
    assert hashlib.sha256(image).hexdigest() == previous["flat_sha256"]
    roots = [int(a,16) for a in previous["roots"]]
    baseline = json.loads((source / "rl78-instructions.json").read_text(encoding="utf-8"))
    legacy, _ = decoder.decode(image, roots)
    assert {int(i["address"],16):i["bytes"] for i in baseline} == {ea:i.raw.hex() for ea,i in legacy.items()}
    permissive, pe, pg = traverse(image, roots, conservative=False)
    assert all(permissive[ea].raw == ins.raw for ea,ins in legacy.items())
    insns, edges, gaps = traverse(image, roots)
    added = sorted(set(insns)-set(legacy))
    skipped = []
    for ea,ins in sorted(insns.items()):
        if ins.mnem not in isa.SKIP: continue
        following = decoder.decode_one(image, ea + ins.size)
        skipped.append(dict(address=hex(ea), instruction=ins.mnem, bytes=ins.raw.hex(),
                            next_address=hex(ea+ins.size), next_bytes=following.raw.hex() if following else None,
                            skip_target=hex(ea+ins.size+following.size) if following and following.mnem!=".db" else None,
                            target_missing_from_baseline=bool(following and ea+ins.size+following.size not in legacy)))
    result = dict(flat_sha256=previous["flat_sha256"], architecture_assumption=previous["architecture_assumption"],
                  exact_cpu_identified=False, binary_execution=False, roots=previous["roots"], manual=MANUAL,
                  source_decoder_sha256=hashlib.sha256((ROOT/"sources/rl78dec/rl78dec/decoder.py").read_bytes()).hexdigest(),
                  producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), skip_length_fixtures=verify_skip_lengths(),
                  baseline_instructions=len(legacy), permissive_baseline_superset=True,
                  permissive=stats(permissive,pe,pg), conservative=stats(insns,edges,gaps),
                  conservative_new_instructions=len(added), conservative_removed_baseline=[hex(ea) for ea in sorted(set(legacy)-set(insns))],
                  conditional_skips=skipped, edges=edges,
                  limitations=["Candidate ISA and vector table assumptions; exact chip unknown", "Indirect targets and hardware-driven reachability unresolved",
                               "BRK1/HALT/.db terminate conservative traversal; permissive variant preserves prior fallthrough behavior",
                               "All overlaps reported; no priority heuristic silently discards them", "Extra candidate instructions do not measure understood firmware"])
    (out/"micom-cpu-candidates.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    export_listing(out,image,insns,set(legacy))
    # Explicit non-null slots only. Runtime indices and total table extents are
    # unproven; do not scan arbitrary ROM words as function addresses.
    tables = []
    for slot in [0x64b6]+list(range(0x64ee,0x6506,4)):
        raw = image[slot:slot+4]
        assert raw[3] == 0 and raw[2] < 0x10
        target = int.from_bytes(raw[:3],"little")
        assert 0 < target < len(image)
        tables.append(dict(slot=hex(slot),bytes=raw.hex(),target=hex(target),
                           caller="0x8ecc" if slot==0x64b6 else "0x8da2",
                           index_bound_proven=False, runtime_selection_proven=False))
    extra_roots = sorted(set(roots)|{int(t["target"],16) for t in tables})
    ti,te,tg = traverse(image,extra_roots)
    assert all(ti[ea].raw==i.raw for ea,i in insns.items())
    table_out=source/"flow-tables"
    export_listing(table_out,image,ti,set(insns))
    table_result=dict(flat_sha256=previous["flat_sha256"],architecture_assumption=previous["architecture_assumption"],
                      exact_cpu_identified=False,binary_execution=False,roots=[hex(r) for r in extra_roots],
                      explicit_candidate_slots=tables,baseline="flow-expanded",new_instructions=len(set(ti)-set(insns)),
                      candidate=stats(ti,te,tg),edges=te,producer_sha256=result["producer_sha256"],
                      limitations=result["limitations"]+["Table roots are hypotheses; table bounds and actual callback selection unresolved"])
    (table_out/"micom-cpu-candidates.json").write_text(json.dumps(table_result,indent=2),encoding="utf-8")
    print(json.dumps(dict(baseline=len(legacy), permissive=len(permissive), conservative=len(insns), new=len(added),
                         removed=len(result["conservative_removed_baseline"]), skips=len(skipped),
                         previously_missing_skip_targets=sum(s["target_missing_from_baseline"] for s in skipped),
                         overlaps=len(result["conservative"]["overlaps"]), boundaries=len(gaps),
                         table_candidates=len(ti),table_new=table_result["new_instructions"]),indent=2))


if __name__ == "__main__": main()
