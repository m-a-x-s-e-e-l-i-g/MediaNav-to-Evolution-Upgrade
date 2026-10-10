"""Pinned in-place startup audio retry; no extra sections, threads or reconnects.

Preserve native frames/unwind and all prior Blue patches. Retries are confined to
one Open call; ambiguous handles and partially prepared output remain owned for
the existing close path. Firmware is never executed natively by this tool.
"""
import hashlib
import re
import struct
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent / "python-libs"))
import pefile
from patch_bt_playback import REGS

INPUT_HASH = "86db75416ce9196412a3c46c1036da3aa151eacc409f7c22db3461e81fe3308a"


def assemble(text, start, end):
    lines, labels, pc = [], {}, start
    for line in text.splitlines():
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        if line.endswith(":"):
            labels[line[:-1]] = pc
        else:
            lines.append((pc, line))
            pc += 4
    assert pc <= end, f"{hex(start)} needs {pc-start} bytes, capacity {end-start}"
    words = []
    number = lambda value: labels[value] if value in labels else int(value, 0)
    for pc, line in lines:
        op, *args = [p for p in re.split(r"[\s,()]+", line) if p]
        r = lambda value: REGS[value]
        if op == "nop":
            word = 0
        elif op == "move":
            word = r(args[1]) << 21 | r(args[0]) << 11 | 0x25
        elif op in ("addu", "sltu"):
            word = r(args[1]) << 21 | r(args[2]) << 16 | r(args[0]) << 11 | {"addu": 0x21, "sltu": 0x2b}[op]
        elif op in ("sll", "srl"):
            word = r(args[1]) << 16 | r(args[0]) << 11 | number(args[2]) << 6 | int(op == "srl") * 2
        elif op == "multu":
            word = r(args[0]) << 21 | r(args[1]) << 16 | 0x19
        elif op == "mflo":
            word = r(args[0]) << 11 | 0x12
        elif op in ("addiu", "andi", "ori", "sltiu"):
            imm = number(args[2])
            assert -32768 <= imm <= 65535
            word = {"addiu": 9, "andi": 12, "ori": 13, "sltiu": 11}[op] << 26 | r(args[1]) << 21 | r(args[0]) << 16 | (imm & 65535)
        elif op == "lui":
            word = 15 << 26 | r(args[0]) << 16 | number(args[1])
        elif op in ("lw", "sw", "lbu", "lhu", "sb", "sh"):
            imm = number(args[1])
            assert -32768 <= imm <= 32767
            word = {"lw": 35, "sw": 43, "lbu": 36, "lhu": 37, "sb": 40, "sh": 41}[op] << 26 | r(args[2]) << 21 | r(args[0]) << 16 | (imm & 65535)
        elif op in ("beqz", "bnez", "b", "beq", "bne"):
            dest = number(args[-1])
            delta = (dest - pc - 4) // 4
            assert dest % 4 == 0 and -32768 <= delta <= 32767
            rs = 0 if op == "b" else r(args[0])
            rt = r(args[1]) if op in ("beq", "bne") else 0
            word = (5 if op in ("bnez", "bne") else 4) << 26 | rs << 21 | rt << 16 | (delta & 65535)
        elif op == "jal":
            dest = number(args[0])
            assert dest % 4 == 0 and dest >> 28 == (pc + 4) >> 28
            word = 3 << 26 | (dest >> 2 & 0x3ffffff)
        elif op == "jalr":
            word = r(args[0]) << 21 | 31 << 11 | 9
        else:
            raise ValueError(line)
        words.append(word)
    used = len(words) * 4
    return b"".join(struct.pack("<I", w) for w in words) + bytes(end-start-used), dict(
        start=start, end=end, used_bytes=used, labels=labels, assembly=text)


OPEN = """
    move s1, zero
    beqz a0, return_keep
    nop
    lw s0, 0(a0)
    beqz s0, return_keep
    nop
    addiu s5, s0, 8
    lw t0, 0(s5)
    bnez t0, return_keep          # Existing wave owner stays intact.
    nop
    lw t0, 0xc(s0)
    bnez t0, return_keep          # A previous failed opening still owns its worker.
    nop
    lw t0, 0x10(s0)
    beqz t0, return_keep
    nop
    addiu a0, s0, 0x339
    addiu a1, s0, 0x33a
    jal 0x193b4
    addiu a2, s0, 0x33c
    addiu t0, zero, 1
    sh t0, 0x20(sp)
    lbu t2, 0x339(s0)
    sh t2, 0x22(sp)
    lhu t3, 0x33c(s0)
    sw t3, 0x24(sp)
    lbu t0, 0x33a(s0)
    sh t0, 0x2e(sp)
    srl t1, t0, 3
    multu t1, t2
    nop
    nop
    mflo t1
    sh t1, 0x2c(sp)
    nop
    multu t1, t3
    nop
    nop
    mflo t0
    sw t0, 0x28(sp)
    sh zero, 0x30(sp)
    sb zero, 4(s0)
    sb zero, 5(s0)
    addiu s4, zero, 2
thread_attempt:
    sw zero, 0x18(sp)            # Thread ID is not reused after failed creation.
    sw zero, 0x10(sp)
    addiu t0, sp, 0x18
    sw t0, 0x14(sp)
    move a0, zero
    move a1, zero
    lui a2, 2
    addiu a2, a2, 0x6400
    jal 0x8a7f0
    move a3, zero
    sw v0, 0xc(s0)
    bnez v0, thread_created
    nop
    addiu s4, s4, -1
    beqz s4, return_keep
    nop
    lui t0, 0x11
    lw t0, 0x10(t0)
    jalr t0
    addiu a0, zero, 25
    b thread_attempt
    nop
thread_created:
    lw t0, 0x18(sp)
    beqz t0, return_keep          # No callback destination: retain worker for Close.
    nop
    lui t0, 0x11
    lw t0, 0x5c(t0)
    move a0, v0
    jalr t0
    move a1, zero                # Priority failure remains nonfatal.
    lui t0, 0x11
    lw s2, 0xf98(t0)
    lw t0, 0x24(t0)
    move a0, s2
    jalr t0
    addiu a1, zero, -1
    bnez v0, return_keep         # Do not open or release a semaphore we did not acquire.
    nop
    lui t0, 0x11
    lw t1, 0xfa0(t0)
    addiu t1, t1, 1
    sw t1, 0xfa0(t0)
    addiu s4, zero, 2
wave_attempt:
    lw t0, 0(s5)
    beqz t0, wave_go
    nop
    addiu t0, zero, 1           # A late owner must not be replaced by this retry.
    sw t0, 0x1c(sp)
    b release
    nop
wave_go:
    lui t0, 2
    sw t0, 0x14(sp)
    sw zero, 0x10(sp)
    lw a3, 0x18(sp)
    addiu a2, sp, 0x20
    addiu a1, zero, -1
    jal 0x8a880
    move a0, s5
    sw v0, 0x1c(sp)              # Preserve thread ID separately from MMRESULT.
    beqz v0, release
    nop
    lw t0, 0(s5)
    bnez t0, release             # Ambiguous failure with a handle: no retry/overwrite.
    nop
    addiu s4, s4, -1
    beqz s4, release
    nop
    lui t0, 0x11
    lw t0, 0x10(t0)
    jalr t0
    addiu a0, zero, 25           # One bounded wait; same worker and callback ID.
    b wave_attempt
    nop
release:
    lui t0, 0x11
    lw t0, 0x58(t0)
    move a0, s2
    addiu a1, zero, 1
    jalr t0
    move a2, zero
    beqz v0, return_keep
    nop
    lw t0, 0x1c(sp)
    bnez t0, return_keep
    nop
    lw t0, 0(s5)
    beqz t0, return_keep
    nop
    lw s2, 0x10(s0)
    addiu s3, s0, 0x10
    addiu s4, zero, 25
headers:
    sw s2, 0(s3)
    addiu t0, zero, 25600
    sw t0, 4(s3)
    sw zero, 0xc(s3)
    sw zero, 0x10(s3)
    addiu s2, s2, 25600
    addiu s3, s3, 32
    addiu s4, s4, -1
    bnez s4, headers
    nop
    addiu s3, s0, 0x10
    addiu s4, zero, 25
prepare:
    lw a0, 0(s5)
    move a1, s3
    jal 0x8a870
    addiu a2, zero, 32
    bnez v0, return_keep         # Prepared/partially prepared output remains owned.
    nop
    addiu s3, s3, 32
    addiu s4, s4, -1
    bnez s4, prepare
    nop
    addiu s1, zero, 1
    sb s1, 4(s0)                # Ready only after all 25 preparations succeeded.
return_keep:
    b 0x26a64
    nop
"""

START = """
    move s1, a0
    lw s0, 0(s1)
    addiu a2, sp, 0x12
    addiu a1, sp, 0x11
    jal 0x193b4
    addiu a0, sp, 0x10
    lw t0, 8(s0)
    beqz t0, fail
    nop
    lbu t0, 4(s0)
    beqz t0, fail                # A partial preparation is not ready.
    nop
    lbu t0, 0x339(s0)
    lbu t1, 0x10(sp)
    bne t0, t1, reconfigure
    lbu t0, 0x33a(s0)
    lbu t1, 0x11(sp)
    bne t0, t1, reconfigure
    lhu t0, 0x33c(s0)
    lhu t1, 0x12(sp)
    beq t0, t1, ready
    nop
reconfigure:
    jal 0x26a8c
    move a0, s1
    jal 0x266a4
    move a0, s1
    beqz v0, fail
    nop
ready:
    addiu t0, zero, 2
    lw a0, 8(s0)
    sb t0, 4(s0)
    jal 0x8a830
    sb zero, 0x338(s0)
    addiu v0, zero, 1
    b 0x26d14
    nop
fail:
    move v0, zero
    b 0x26d14
    nop
"""

FILTER_START = """
    lbu t0, 0(s2)
    beq t0, t6, already
    nop
    bne t0, t5, 0x25be8
    nop
    lw t2, 0(s6)
    addiu t0, s7, 0x1c
    sll t1, t0, 2
    lw t2, 0x1c(t2)
    addu a0, t1, s4
    jalr t2
    move s3, s1
    move s5, v0
    addiu t5, zero, 2
    beqz v0, 0x25be8
    addiu t6, zero, 3
    sb t6, 0(s2)
already:
    b 0x25be8
    move s3, s1
"""


def patch(raw):
    assert hashlib.sha256(raw).hexdigest() == INPUT_HASH, "Unexpected cumulative Blue base"
    pe = pefile.PE(data=raw)
    assert pe.OPTIONAL_HEADER.ImageBase == 0x10000 and pe.FILE_HEADER.Machine == 0x166
    assert pe.OPTIONAL_HEADER.CheckSum == 0 and pe.OPTIONAL_HEADER.DATA_DIRECTORY[5].Size == 0
    ranges, recipes = [], []
    for start, end, text in ((0x266c4, 0x26a64, OPEN), (0x26c78, 0x26d14, START),
                             (0x25db8, 0x25e04, FILTER_START),
                             (0x1aebc, 0x1aee4, "b 0x1aee4\nnop"),
                             (0x1aeec, 0x1aef0, "sltu t1, zero, v0"),
                             (0x26d20, 0x26d24, "nop")):
        data, recipe = assemble(text, start, end)
        at = pe.get_offset_from_rva(start-pe.OPTIONAL_HEADER.ImageBase)
        before = raw[at:at+len(data)]
        ranges.append(dict(start=start, end=end, offset=at, before_hex=before.hex(), after_hex=data.hex()))
        recipes.append(recipe)
    output = bytearray(raw)
    for row in ranges:
        at = row["offset"]
        output[at:at+row["end"]-row["start"]] = bytes.fromhex(row["after_hex"])
    result = bytes(output)
    out_pe = pefile.PE(data=result)
    assert len(raw) == len(result)
    assert pe.FILE_HEADER.__pack__() == out_pe.FILE_HEADER.__pack__()
    assert pe.OPTIONAL_HEADER.__pack__() == out_pe.OPTIONAL_HEADER.__pack__()
    for a, b in zip(pe.sections, out_pe.sections):
        assert a.__pack__() == b.__pack__()
        if a.Name.rstrip(b"\0") != b".text":
            assert a.get_data() == b.get_data()
    return result, dict(input_sha256=INPUT_HASH, output_sha256=hashlib.sha256(result).hexdigest(),
                        attempts_per_api=2, retry_sleep_ms=25,
                        changed_bytes=sum(a!=b for a,b in zip(raw,result)), edits=ranges,
                        assembly=recipes, native_executed=False)
