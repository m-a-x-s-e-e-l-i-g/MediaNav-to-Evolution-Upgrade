"""Tiny MIPS32 little-endian assembler for reviewed in-place patches."""
import re, struct

REG = {n: i for i, n in enumerate(
    "zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra".split())}
R = lambda x: REG[x.strip().lstrip("$")]


def imm16(v):
    assert -32768 <= v <= 65535, v
    return v & 0xffff


def assemble(code, start):
    """Return (bytes, labels). One instruction per line; `la` expands to lui+addiu."""
    lines, labels, pc = [], {}, start
    for raw in code.splitlines():
        line = raw.split("#", 1)[0].strip()
        if not line:
            continue
        if line.endswith(":"):
            labels[line[:-1]] = pc
            continue
        lines.append((pc, line))
        pc += 8 if line.startswith("la ") else 4
    out = bytearray()

    def word(w):
        out.extend(struct.pack("<I", w & 0xffffffff))

    def target(x):
        return labels[x] if x in labels else int(x, 0)

    for pc, line in lines:
        op, _, rest = line.partition(" ")
        a = [t for t in re.split(r"[\s,()]+", rest) if t]
        if op == "nop":
            word(0)
        elif op == "move":
            word((R(a[1]) << 21) | (R(a[0]) << 11) | 0x21)
        elif op in ("addu", "subu", "or", "and", "sltu"):
            f = {"addu": 0x21, "subu": 0x23, "or": 0x25, "and": 0x24, "sltu": 0x2b}[op]
            word((R(a[1]) << 21) | (R(a[2]) << 16) | (R(a[0]) << 11) | f)
        elif op in ("sll", "srl"):
            word((R(a[1]) << 16) | (R(a[0]) << 11) | (int(a[2], 0) << 6) | (0 if op == "sll" else 2))
        elif op in ("addiu", "andi", "ori", "sltiu"):
            o = dict(addiu=9, andi=12, ori=13, sltiu=11)[op]
            word((o << 26) | (R(a[1]) << 21) | (R(a[0]) << 16) | imm16(int(a[2], 0)))
        elif op == "lui":
            word((15 << 26) | (R(a[0]) << 16) | imm16(int(a[1], 0)))
        elif op in ("lw", "sw", "lbu", "lhu", "sb", "sh"):
            o = dict(lw=35, sw=43, lbu=36, lhu=37, sb=40, sh=41)[op]
            word((o << 26) | (R(a[2]) << 21) | (R(a[0]) << 16) | imm16(int(a[1], 0)))
        elif op in ("beq", "bne"):
            d = (target(a[2]) - pc - 4) // 4
            assert -32768 <= d <= 32767
            word(((4 if op == "beq" else 5) << 26) | (R(a[0]) << 21) | (R(a[1]) << 16) | (d & 0xffff))
        elif op in ("beqz", "bnez"):
            d = (target(a[1]) - pc - 4) // 4
            assert -32768 <= d <= 32767
            word(((4 if op == "beqz" else 5) << 26) | (R(a[0]) << 21) | (d & 0xffff))
        elif op in ("j", "jal"):
            t = target(a[0])
            word(((2 if op == "j" else 3) << 26) | ((t >> 2) & 0x3ffffff))
        elif op == "jr":
            word((R(a[0]) << 21) | 8)
        elif op == "jalr":
            word((R(a[0]) << 21) | (31 << 11) | 9)
        elif op == "la":
            t = target(a[1])
            hi = ((t + 0x8000) >> 16) & 0xffff
            word((15 << 26) | (R(a[0]) << 16) | hi)
            word((9 << 26) | (R(a[0]) << 21) | (R(a[0]) << 16) | (t & 0xffff))
        else:
            raise ValueError(line)
    return bytes(out), labels
