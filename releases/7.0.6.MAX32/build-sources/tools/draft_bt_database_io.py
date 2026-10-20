"""Pinned in-memory fixes for Blue's database storage and transfer status.

Keep the old fread/fwrite byte-count ABI; additionally return API BOOL in v1.
Bulk callers use both, accepting whole short reads and requiring full writes.
Record scans fail closed; higher deletion compacts without a preliminary write.
Partial writes are recognized, not rolled back. Existing callers can ignore status.
"""
import re
import struct
from patch_bt_playback import assemble, REGS


def assemble_io(code, start, end):
    """Extend the existing encoder locally without changing playback tooling."""
    labels, custom, lines, pc = {}, [], [], start
    supported_extra = {"beq", "bne", "jalr", "jr", "multu", "divu", "mflo", "mfhi", "or", "lhu", "srl"}
    for line in code.splitlines():
        line = line.split("#", 1)[0].strip()
        if not line: continue
        if line.endswith(":"):
            labels[line[:-1]] = pc
            lines.append(line); continue
        op = line.split()[0]
        if op in supported_extra:
            custom.append((pc, line)); lines.append("nop")
        else:
            lines.append(line)
        pc += 4
    raw, manifest = assemble("\n".join(lines), start, end)
    raw = bytearray(raw)
    for pc, line in custom:
        op, *args = [p for p in re.split(r"[\s,()]+", line) if p]
        r = lambda name: REGS[name]
        if op in ("beq", "bne"):
            target = labels[args[2]] if args[2] in labels else int(args[2], 0)
            delta = (target - pc - 4) // 4
            assert target % 4 == 0 and -32768 <= delta <= 32767
            word = ((4 if op == "beq" else 5) << 26) | (r(args[0]) << 21) | (r(args[1]) << 16) | (delta & 65535)
        elif op in ("jalr", "jr"):
            word = (r(args[0]) << 21) | ((31 << 11) | 9 if op == "jalr" else 8)
        elif op in ("multu", "divu"):
            word = (r(args[0]) << 21) | (r(args[1]) << 16) | (0x19 if op == "multu" else 0x1b)
        elif op in ("mflo", "mfhi"):
            word = (r(args[0]) << 11) | (0x12 if op == "mflo" else 0x10)
        elif op == "lhu":
            imm = int(args[1], 0); assert -32768 <= imm <= 32767
            word = (0x25 << 26) | (r(args[2]) << 21) | (r(args[0]) << 16) | (imm & 65535)
        elif op == "srl":
            shift = int(args[2], 0); assert 0 <= shift < 32
            word = (r(args[1]) << 16) | (r(args[0]) << 11) | (shift << 6) | 2
        else:
            word = (r(args[1]) << 21) | (r(args[2]) << 16) | (r(args[0]) << 11) | 0x25
        struct.pack_into("<I", raw, pc - start, word)
    manifest["assembly"] = code
    return bytes(raw), manifest


def wrapper(iat):
    return f"""
        multu a1, a2
        move a1, a0
        move a0, a3
        lui t1, 0x11
        sw zero, 0x18(sp)
        lw t0, {iat}(t1)
        addiu a3, sp, 0x18
        mflo a2
        jalr t0
        sw zero, 0x10(sp)
        move v1, v0
        lw v0, 0x18(sp)
        lw ra, 0x20(sp)
        jr ra
        addiu sp, sp, 0x28
    """


MAGIC = """
    lui t0, 0x10
    addiu s2, t0, 0x39f0
    lui a1, 0x8000
    jal 0x85f84
    move a0, s2
    lui s4, 0xffff
    ori s4, s4, 2
    addiu s5, zero, -1
    addiu s6, zero, 4
    move s3, v0
    beq s3, s5, initialize
    addiu s1, zero, 1
    move a3, s3
    addiu a2, zero, 4
    addiu a1, zero, 1
    addiu a0, sp, 0x10
    jal 0x860f8
    sw zero, 0x10(sp)
    move s0, v0
    sltu s1, zero, v1
    jal 0x86088
    move a0, s3
    beqz s1, failed
    lw t0, 0x10(sp)
    bne s0, s6, initialize
    nop
    beq t0, s4, done
    nop
initialize:
    lui a1, 0x4000
    jal 0x85f84
    move a0, s2
    move s0, v0
    beq s0, s5, failed
    move a3, s0
    addiu a2, zero, 4
    addiu a1, zero, 1
    addiu a0, sp, 0x10
    jal 0x860ac
    sw s4, 0x10(sp)
    jal 0x86088
    move a0, s0
failed:
    move s1, zero
done:
    move v0, s1
"""


def bulk(writer):
    validation = """
        bne v0, s0, failed
        sltu s0, zero, v1
        b close
        nop
    """ if writer else """
        beqz v1, failed
        sltu t0, s0, v0
        bnez t0, failed
        addiu t0, zero, 0x68
        divu v0, t0
        mfhi t0
        sltiu s0, t0, 1
        b close
        nop
    """
    seek = """
        srl t0, s0, 8
        addiu t1, zero, 0x68
        multu t0, t1
        mflo a1
        addiu a1, a1, 4
        move a0, s1
        jal 0x86144
        move a2, zero
    """ if writer else """
        addiu a1, zero, 4
        jal 0x86144
        move a2, zero
    """
    # Writer count/index token: low byte is count, upper bits are first slot.
    # The only new caller passes one record at a checked index 0..7; existing
    # bulk callers still pass eight, which denotes eight records at index zero.
    count = "andi s0, s0, 0xff" if writer else ""
    return f"""
        move s0, a1
        addiu s1, zero, -1
        jal 0x7a3d8
        move s2, a0
        beqz v0, failed
        lui t0, 0x10
        addiu a0, t0, 0x39f0
        jal 0x85f84
        lui a1, {hex(0x4000 if writer else 0x8000)}
        move s1, v0
        addiu t0, zero, -1
        beq s1, t0, failed
        move a0, s1
        {seek}
        andi t0, v0, 0xffff
        bnez t0, failed
        addiu t0, zero, 0x68
        {count}
        multu s0, t0
        mflo s0
        move a0, s2
        addiu a1, zero, 1
        move a2, s0
        jal {hex(0x860ac if writer else 0x860f8)}
        move a3, s1
        {validation}
failed:
        move s0, zero
close:
        jal 0x86088
        move a0, s1
    """


FIND_INDEX = """
    addiu s0, zero, -1
    move s1, s0
    move s2, zero
    jal 0x7a3d8
    addiu s4, zero, -1
    beqz v0, close
    lui t0, 0x10
    addiu a0, t0, 0x39f0
    jal 0x85f84
    lui a1, 0x8000
    move s4, v0
    beq s4, s0, close
    move a0, s4
    addiu a1, zero, 4
    jal 0x86144
    move a2, zero
    andi t0, v0, 0xffff
    bnez t0, close
    addiu s6, zero, 0x68
next_record:
    addiu a0, sp, 0x10
    move a1, zero
    jal 0x3a750
    move a2, s6
    addiu a0, sp, 0x10
    addiu a1, zero, 1
    move a2, s6
    jal 0x860f8
    move a3, s4
    beqz v1, close
    nop
    bne v0, s6, end_of_file
    nop
    addiu a0, sp, 0x10
    jal 0x3ac90
    move a1, s3
    bnez v0, found
    nop
    bnez s5, advance
    nop
    bne s1, s0, advance
    nop
    lw t0, 0x10(sp)
    lbu t1, 0x14(sp)
    lhu t2, 0x16(sp)
    or t0, t0, t1
    or t0, t0, t2
    bnez t0, advance
    nop
    move s1, s2
advance:
    b next_record
    addiu s2, s2, 1
end_of_file:
    bnez v0, close
    nop
    bnez s5, finish_candidate
    nop
    bne s1, s0, finish_candidate
    nop
    move s1, s2
finish_candidate:
    b close
    move s0, s1
found:
    move s0, s2
close:
    jal 0x86088
    move a0, s4
"""

LOOKUP_RECORD = """
    move s2, a1
    jal 0x7a3d8
    move s3, a0
    beqz v0, failed
    nop
    lui t0, 0x10
    addiu a0, t0, 0x39f0
    jal 0x85f84
    lui a1, 0x8000
    move s1, v0
    addiu t0, zero, -1
    beq s1, t0, failed
    move a0, s1
    addiu a1, zero, 4
    jal 0x86144
    move a2, zero
    andi t0, v0, 0xffff
    bnez t0, failed_close
    addiu s4, zero, 0x68
next_record:
    move a0, s2
    addiu a1, zero, 1
    move a2, s4
    jal 0x860f8
    move a3, s1
    beqz v1, failed_close
    nop
    bne v0, s4, failed_close
    move a1, s3
    jal 0x3ac90
    move a0, s2
    beqz v0, next_record
    nop
    b close
    addiu s0, zero, 1
failed_close:
    move s0, zero
close:
    jal 0x86088
    move a0, s1
    b 0x7a714
    nop
failed:
    move s0, zero
"""

RECORD_WRITE = """
    move s2, a1
    jal 0x7a3d8
    move s0, a0
    move a0, s0
    jal 0x7a4d0
    move a1, zero
    sltiu t0, v0, 8
    beqz t0, failed
    move s1, v0
    sll a1, s1, 8
    ori a1, a1, 1
    jal 0x7a974
    move a0, s2
    b 0x7a7dc
    nop
failed:
    move v0, zero
"""

DELETE_ADDRESS = """
    sltiu t0, s0, 8
    beqz t0, 0x7ac08
    nop
    jal 0x7aa40
    move a0, s0
    b 0x7ac08
    nop
"""

CONNECT_LOOKUP = """
    lui t0, 0x11
    addiu a1, t0, 0xefc
    jal 0x7a63c
    move a0, s0
    beqz v0, failed
    nop
    jal 0x14174
    nop
    move a1, s0
    jal 0x16f68
    move a0, v0
    bnez v0, 0x2f7a4
    nop
failed:
    move a0, s2
    jal 0x332b0
    move a1, zero
    jal 0x31f58
    move a0, s2
    move a2, v0
    lui a1, 0x401
    ori a1, a1, 0x504
    jal 0x33390
    addiu a0, zero, 2
    jal 0x8a7c0
    move a0, s4
    lui a0, 0x10
    jal 0x34264
    addiu a0, a0, -0xffc
    b 0x2f84c
    nop
"""


def apply_database_io(raw, pe, out, edits):
    specs = [
        (0x2f728, 0x2f7a4, CONNECT_LOOKUP, "Reject failed key-record lookup before connection; retain original failure reset/notification"),
        (0x860bc, 0x860f8, wrapper("0"), "Preserve fwrite byte-count return and expose WriteFile BOOL in v1"),
        (0x86108, 0x86144, wrapper("0x114"), "Preserve fread byte-count return and expose ReadFile BOOL in v1"),
        (0x7a3fc, 0x7a4a8, MAGIC, "Reject header ReadFile failure without rewriting the database magic"),
        (0x7a8bc, 0x7a958, bulk(False), "Require successful read of zero or more complete bounded 104-byte records"),
        (0x7a988, 0x7aa24, bulk(True), "Require successful write of exactly all requested record bytes"),
        (0x7a508, 0x7a608, FIND_INDEX, "Distinguish clean EOF from scan errors; never choose slot zero after an I/O failure"),
        (0x7a658, 0x7a714, LOOKUP_RECORD, "Require API success and a complete record before BDADDR lookup"),
        (0x7a750, 0x7a7dc, RECORD_WRITE, "Reject bad/full scans; use checked offset writer and return its persistence status"),
        (0x7ab9c, 0x7ac08, DELETE_ADDRESS, "Remove preliminary empty-record write; compact only after a valid bounded lookup"),
    ]
    for start, end, code, reason in specs:
        replacement, manifest = assemble_io(code, start, end)
        offset = pe.get_offset_from_rva(start - pe.OPTIONAL_HEADER.ImageBase)
        assert all(not (int(e["offset"], 16) < offset + len(replacement) and
                        offset < int(e["offset"], 16) + e.get("bytes", 4)) for e in edits)
        out[offset:offset + len(replacement)] = replacement
        edits.append(dict(va=hex(start), offset=hex(offset), bytes=len(replacement),
                          before_hex=raw[offset:offset + len(replacement)].hex(), after_hex=replacement.hex(),
                          reason=reason, assembly=manifest))
