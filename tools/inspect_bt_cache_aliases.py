"""Conservative, bounded MIPS address-provenance inventory for CBtData.

This is a candidate analysis, not proof of absence of indirect cache readers.
Branch delays execute, both conditional edges are followed unless constant;
computed jumps, unknown instructions and arbitrary callees stay explicit gaps.
"""
from collections import deque, Counter
import hashlib
import json
import struct
import re
import pefile
from inspect_bt_playback import ROOT, source
from draft_bt_pairing_storage import APP_HASH

# (base, offset), where offset=None means any offset. None value means unknown.
Z = ("constant", 0)
OBJ = ("CBtData", 0)
MGR = ("manager", 0)
STACK = ("stack", 0)
LOADS = {0x20: 1, 0x21: 2, 0x22: 4, 0x23: 4, 0x24: 1, 0x25: 2, 0x26: 4, 0x30: 4}
STORES = {0x28: 1, 0x29: 2, 0x2a: 4, 0x2b: 4, 0x2e: 4, 0x38: 4}
CALLER = (*range(2, 16), 24, 25, 31)
LEAVES = {0x1108f0: 0x6c, 0x11095c: 0x78, 0x113720: 0xb0}


def join(a, b):
    if a == b: return a
    if a is None or b is None: return None
    if a[0] == b[0] and a[0] != "constant": return (a[0], None)
    return None


def number(value):
    return value[1] if value is not None and value[0] == "constant" else None


def add(a, b, subtract=False):
    av, bv = number(a), number(b)
    if av is not None and bv is not None: return ("constant", (av - bv if subtract else av + bv) & 0xffffffff)
    if a is not None and a[0] != "constant":
        if subtract and b is not None and a[0] == b[0]:
            return None if a[1] is None or b[1] is None else ("constant", (a[1] - b[1]) & 0xffffffff)
        return (a[0], None if a[1] is None or bv is None else a[1] - bv if subtract else a[1] + bv)
    if not subtract and b is not None and b[0] != "constant": return add(b, a)
    return None


def show(value):
    return None if value is None else dict(base=value[0], offset=value[1])


class Audit:
    def __init__(self, pe):
        self.pe, self.base = pe, pe.OPTIONAL_HEADER.ImageBase
        self.events, self.gaps = {}, {}
        self.imports = {i.address: dict(dll=d.dll.decode("ascii"), name=i.name.decode("ascii") if i.name else None,
                                       ordinal=i.ordinal, iat=hex(i.address))
                        for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}

    def word(self, pc): return struct.unpack("<I", self.pe.get_data(pc - self.base, 4))[0]

    def event(self, owner, pc, kind, value, **extra):
        if value is None or value[0] != "CBtData": return
        rec = dict(function=hex(owner), va=hex(pc), word=hex(self.word(pc)),
                   kind=kind, pointer=show(value), **extra)
        key = json.dumps(rec, sort_keys=True)
        self.events[key] = rec

    def gap(self, owner, pc, kind, **extra):
        rec = dict(function=hex(owner), va=hex(pc), word=hex(self.word(pc)), kind=kind, **extra)
        self.gaps[json.dumps(rec, sort_keys=True)] = rec

    def plain(self, owner, pc, regs, locals_):
        w = self.word(pc); op, rs, rt, rd, fn = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, w & 63
        imm = w & 65535; signed = imm if imm < 32768 else imm - 65536
        old = regs.copy()
        if op == 15: regs[rt] = ("constant", imm << 16)
        elif op in (8, 9): regs[rt] = add(old[rs], ("constant", signed))
        elif op in (0xc, 0xd, 0xe):
            val = number(old[rs])
            regs[rt] = None if val is None else ("constant", val & imm if op == 0xc else val | imm if op == 0xd else val ^ imm)
        elif op in (0xa, 0xb): regs[rt] = None
        elif op in LOADS:
            address = add(old[rs], ("constant", signed))
            self.event(owner, pc, "load", address, bytes=LOADS[op])
            val = number(address)
            if val == 0x187be4: regs[rt] = MGR
            elif val == 0x186560: regs[rt] = OBJ
            elif val in self.imports: regs[rt] = ("import", val)
            elif address == ("manager", 0xa0): regs[rt] = OBJ
            elif address is not None and address[0] == "stack": regs[rt] = locals_.get(address[1])
            else: regs[rt] = None
        elif op in STORES:
            address = add(old[rs], ("constant", signed))
            self.event(owner, pc, "store", address, bytes=STORES[op])
            if address is not None and address[0] == "stack" and address[1] is not None:
                locals_[address[1]] = old[rt] if op == 0x2b else None
            elif old[rt] is not None and old[rt][0] == "CBtData":
                self.event(owner, pc, "pointer-store-escape", old[rt], destination=show(address))
            if op == 0x38: regs[rt] = None
        elif op == 0:
            if fn in (0x20, 0x21): regs[rd] = add(old[rs], old[rt])
            elif fn in (0x22, 0x23): regs[rd] = add(old[rs], old[rt], True)
            elif fn in (0x24, 0x25, 0x26):
                if old[rs] == Z and fn in (0x25, 0x26): regs[rd] = old[rt]
                elif old[rt] == Z and fn in (0x25, 0x26): regs[rd] = old[rs]
                else:
                    a, b = number(old[rs]), number(old[rt])
                    regs[rd] = None if a is None or b is None else ("constant", a & b if fn == 0x24 else a | b if fn == 0x25 else a ^ b)
            elif fn in (0, 2, 3):
                a, shift = number(old[rt]), (w >> 6) & 31
                if a is None: regs[rd] = None
                elif fn == 0: regs[rd] = ("constant", (a << shift) & 0xffffffff)
                elif fn == 2: regs[rd] = ("constant", a >> shift)
                else: regs[rd] = ("constant", ((a if a < 0x80000000 else a - 0x100000000) >> shift) & 0xffffffff)
            elif fn in (4, 6, 7, 0x10, 0x12, 0x27, 0x2a, 0x2b): regs[rd] = None
            elif fn in (0x11, 0x13, 0x18, 0x19, 0x1a, 0x1b, 0xf): pass
            else:
                self.gap(owner, pc, "unknown-special-instruction")
                for r in range(1, 32): regs[r] = None
        elif op in (0x10, 0x11, 0x12, 0x31, 0x35, 0x39, 0x3d):
            self.gap(owner, pc, "coprocessor-unmodeled")
            if op in (0x10, 0x11, 0x12) and rs in (0, 2): regs[rt] = None
        else:
            self.gap(owner, pc, "unknown-instruction")
            for r in range(1, 32): regs[r] = None
        # Address formation is separate from the load/store event and includes
        # pointers passed onward; exact cache starts are inventoried explicitly.
        for r in range(1, 32):
            if regs[r] != old[r]: self.event(owner, pc, "derived-address", regs[r], register=r)
        regs[0] = Z

    def run(self, owner, end):
        regs = [None] * 32; regs[0], regs[29] = Z, STACK
        # Method-region seeds are assumptions, not discovered whole-program
        # types. Singleton getter has no this argument; unwind entries excluded.
        if 0x110010 <= owner < 0x113ec4 and owner not in (0x1103a4, 0x110240, 0x110274, 0x110448, 0x11057c, 0x1105b0): regs[4] = OBJ
        if owner == 0x114518: regs[4] = MGR
        states, queue = {owner: (regs, {})}, deque([owner])
        reached, steps = set(), 0
        def push(target, regs, local):
            if not owner <= target < end or target & 3:
                if target != end: self.gap(owner, max(owner, min(end - 4, target)), "edge-outside-range", target=hex(target))
                return
            if target not in states:
                states[target] = (regs.copy(), local.copy()); queue.append(target); return
            before_r, before_l = states[target]
            after_r = [join(a, b) for a, b in zip(before_r, regs)]
            after_l = {k: join(v, local.get(k)) for k, v in before_l.items()}
            if after_r != before_r or after_l != before_l:
                states[target] = (after_r, after_l); queue.append(target)
        while queue:
            pc = queue.popleft(); current_r, current_l = states[pc]
            r, local = current_r.copy(), current_l.copy(); reached.add(pc); steps += 1
            assert steps < 100000, (hex(owner), "provenance convergence failed")
            w = self.word(pc); op, rs, rt, fn = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 63
            control = op in (1, 2, 3, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or op == 0 and fn in (8, 9)
            if not control:
                self.plain(owner, pc, r, local); push(pc + 4, r, local); continue
            if pc + 4 >= end:
                self.gap(owner, pc, "delay-outside-range"); continue
            if op in (3,) or op == 0 and fn == 9:
                target = ((pc + 4) & 0xf0000000) | ((w & 0x3ffffff) << 2) if op == 3 else number(r[rs])
                imported = self.imports.get(r[rs][1]) if op == 0 and r[rs] is not None and r[rs][0] == "import" else None
                r[31] = ("constant", pc + 8)
                self.plain(owner, pc + 4, r, local); reached.add(pc + 4)
                for reg in range(4, 8): self.event(owner, pc, "call-argument", r[reg], register=reg,
                                                target=None if target is None else hex(target), imported_target=imported)
                sp = r[29]
                for off in (0x10, 0x14, 0x18):
                    val = local.get(sp[1] + off) if sp is not None and sp[0] == "stack" and sp[1] is not None else None
                    self.event(owner, pc, "stack-call-argument", val, stack_offset=off,
                               target=None if target is None else hex(target), imported_target=imported)
                saved_this = r[4]
                for reg in CALLER: r[reg] = None
                if target == 0x1103a4: r[2] = OBJ
                elif target == 0x110010: r[2] = saved_this
                elif target == 0x1402f0 and number(saved_this) == 0x15947c: r[2] = OBJ
                if target is None and imported is None: self.gap(owner, pc, "unresolved-call-target")
                # Callees may write the outgoing argument/home area.
                if sp is not None and sp[0] == "stack" and sp[1] is not None:
                    for off in range(0, 0x20, 4): local.pop(sp[1] + off, None)
                push(pc + 8, r, local); continue
            if op in (2,) or op == 0 and fn == 8:
                target = ((pc + 4) & 0xf0000000) | ((w & 0x3ffffff) << 2) if op == 2 else number(r[rs])
                self.plain(owner, pc + 4, r, local); reached.add(pc + 4)
                if op == 0 and rs == 31:
                    self.event(owner, pc, "return-pointer", r[2]); continue
                if target is None: self.gap(owner, pc, "unresolved-computed-jump"); continue
                push(target, r, local); continue
            if op in (0x14, 0x15, 0x16, 0x17) or op == 1 and rt not in (0, 1):
                self.gap(owner, pc, "branch-kind-unmodeled"); continue
            offset = w & 65535
            if offset >= 32768: offset -= 65536
            a, b = number(r[rs]), number(r[rt]); taken = None
            if op in (4, 5) and a is not None and b is not None: taken = (a == b) == (op == 4)
            if op in (1, 6, 7) and a is not None:
                a = a if a < 0x80000000 else a - 0x100000000
                taken = (a < 0 if rt == 0 else a >= 0) if op == 1 else a <= 0 if op == 6 else a > 0
            self.plain(owner, pc + 4, r, local); reached.add(pc + 4)
            if taken is not False: push(pc + 4 + offset * 4, r, local)
            if taken is not True: push(pc + 8, r, local)
        return dict(function=hex(owner), end=hex(end), instructions_reached=len(reached), abstract_transfers=steps)


def cache_candidate(event):
    off = event["pointer"]["offset"]
    return off is None or off < 0x5a4 and off + event.get("bytes", 1) > 0x3b0


def main():
    module = next(m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8")) if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    raw = (ROOT / module["path"]).read_bytes(); assert hashlib.sha256(raw).hexdigest() == APP_HASH
    pe = pefile.PE(data=raw)
    funcs = json.loads((ROOT / "analysis/functions/705md/AppMain.exe.json").read_text(encoding="utf-8"))["functions"]
    ranges = {int(f["begin_va"], 16): int(f["end_va"], 16) for f in funcs}
    for start, size in LEAVES.items():
        assert start not in ranges and not any(a <= start < b for a, b in ranges.items())
        ranges[start] = start + size
    audit = Audit(pe)
    coverage = [audit.run(start, end) for start, end in sorted(ranges.items())]
    events = sorted(audit.events.values(), key=lambda e: (int(e["function"], 16), int(e["va"], 16), e["kind"]))
    candidates = [e for e in events if cache_candidate(e)]
    exact = [e for e in candidates if e["pointer"]["offset"] is not None]
    uncertain = [e for e in candidates if e["pointer"]["offset"] is None]
    owners = sorted({int(e["function"], 16) for e in exact} | {0x1103a4, 0x114518})
    src, _ = source(module, owners, LEAVES)
    result = dict(status="Conservative address candidates; negative whole-program alias proof not established",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  source=src, pdata_ranges=len(funcs), added_reviewed_leaf_ranges=LEAVES,
                  cache_start="0x3b0", cache_end="0x5a4", object_allocation_bytes=0x15947c,
                  coverage=coverage, exact_cache_events=exact, uncertain_offset_cache_candidates=uncertain,
                  all_object_events=events, analysis_gaps=list(audit.gaps.values()),
                  scope=["Original bytes only; method-entry seeds and recognized singleton/global/constructor provenance",
                         "Both conditional edges, architectural branch delays, exact stack spill recovery and ABI-clobbered caller registers",
                         "Offset widening to unknown preserves CBtData provenance; unknown offsets are explicit candidates"],
                  limitations=["No negative alias claim: computed jumps/calls, unsupported instructions and arbitrary return values are gaps",
                               "No interprocedural memory model, complete this-type inference or object-loaded-pointer taint",
                               "All pdata functions plus three reviewed leaves; other non-pdata/indirect-only code may be absent",
                               "CFG merged states/candidate events overapproximate; instructions and native traces must confirm semantics",
                               "Subobject/Unwind entries do not prove object identity; method-region entry seeds are assumptions",
                               "Original count/index invariants and allocation success not proved by this inventory"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in
                                ("inspect_bt_cache_aliases.py", "inspect_bt_playback.py", "draft_bt_pairing_storage.py")})
    out = ROOT / "analysis/firmware/bt-cache-aliases"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(functions=len(coverage), exact_events=len(exact), uncertain_events=len(uncertain),
                         gaps=dict(Counter(g["kind"] for g in audit.gaps.values())),
                         exact=exact), indent=2))


if __name__ == "__main__": main()
