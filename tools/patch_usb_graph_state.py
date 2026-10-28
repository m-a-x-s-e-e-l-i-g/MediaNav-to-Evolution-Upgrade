"""MAX04 USB graph-state repair; pinned input, declared edits and reversible recipe.

Only instruction/API-fixture validation is available. No native execution or LGU.
"""
import hashlib
import struct

import pefile

from patch_usb_folders import folder_assemble as assemble
from patch_updater_copy_safety import frame, end

BASE = 0x10000
BASE_SHA = "cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c"
POLL, TEARDOWN, RENDER_INIT, MESSAGE = 0x40000, 0x40600, 0x40800, 0x40E00
TIMEOUT_MS, MAX_POLLS = 5000, 1001
REGISTERS = ["s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7"]
GATES = (
    (0x40900, (0x1AF9C,), 0x19864, 0x1AFA4, "Stop position update"),
    (0x40940, (0x1B398,), 0x1B300, 0x1B3A0, "Seek timers"),
    (0x40980, (0x1C650,), 0x23580, 0x1C658, "Stop completion notification"),
    (0x409C0, (0x1D8D0, 0x1DA34), 0x1144C, 0x1DAB0, "Held seek"),
    (0x40A00, (0x2176C,), 0x1144C, 0x21028, "IPC seek"),
    (0x40A40, (0x22424,), 0x1144C, 0x226C0, "Window seek"),
)


def imported(at, delay="nop"):
    return f"la t8, {hex(at)}\nlw t9, 0(t8)\njalr t9\n{delay}"


def transition():
    """a0=manager, a1=mode (Stop=0, RealPause=1, Pause=2), a2=reset-position.

    v0 is a BOOL; v1 is a diagnostic reason. State is committed only after a
    completed GetState result. Pending state output is never accepted as ready.
    """
    return f"""
{frame(0x60, REGISTERS)}
move s0, a0
move s1, a1
move s2, a2
addiu s7, zero, 1
sw zero, 0x24(sp)
beqz s0, failed
nop
lw s3, 4(s0)
beqz s3, failed
nop
lw t0, 0x24(s0)
sw t0, 0x28(sp)
lw a0, 0x14(s0)
beqz a0, clock
nop
lw t0, 0(a0)
lw t9, 0x1c(t0)
jalr t9
addiu a1, zero, -10000
clock:
{imported(0x2f00c)}
move s4, v0
move s5, zero
addiu s6, zero, -1
poll:
addiu s7, zero, 3
sltiu t0, s5, {MAX_POLLS}
beqz t0, failed
nop
{imported(0x2f00c)}
subu t0, v0, s4
sltiu t0, t0, {TIMEOUT_MS}
beqz t0, failed
nop
addiu s7, zero, 6
lw t0, 4(s0)
bne t0, s3, failed
nop
addiu t0, zero, -1
sw t0, 0x20(sp)
move a0, s3
move a1, zero
addiu a2, sp, 0x20
lw t0, 0(a0)
lw t9, 0x28(t0)
jalr t9
nop
sw v0, 0x24(sp)
addiu s7, zero, 2
bltz v0, failed
nop
beqz v0, completed
nop
lui t0, 4
ori t0, t0, 0x237
beq v0, t0, wait
nop
lui t0, 4
ori t0, t0, 0x268
bne v0, t0, failed
nop
lw t0, 0x20(sp)
addiu t1, zero, 1
bne t0, t1, invalid
nop
completed:
addiu s7, zero, 6
lw t0, 4(s0)
bne t0, s3, failed
nop
lw t0, 0x20(sp)
beqz t0, success
nop
addiu t1, zero, 1
beq t0, t1, paused
nop
addiu t1, zero, 2
bne t0, t1, invalid
nop
addiu t2, zero, 0x20
b command
nop
paused:
addiu t1, zero, 1
beq s1, t1, success
nop
addiu t2, zero, 0x24
command:
beq t0, s6, wait
nop
move s6, t0
move a0, s3
lw t0, 0(a0)
addu t0, t0, t2
lw t9, 0(t0)
jalr t9
nop
sw v0, 0x24(sp)
addiu s7, zero, 4
bltz v0, failed
nop
wait:
addiu s5, s5, 1
{imported(0x2f008, 'addiu a0, zero, 5')}
b poll
nop
invalid:
addiu s7, zero, 5
b failed
nop
success:
bnez s1, cache_pause
nop
addiu t0, zero, 3
sw t0, 0x24(s0)
beqz s2, done_success
nop
move a0, s0
jal 0x1111c
move a1, zero
b done_success
nop
cache_pause:
# Preserve valid already-stopped/no-graph UI state for a confirmed no-op.
# A running-to-paused/stopped transition still records the original pause UI state.
lw t0, 0x28(sp)
addiu t1, zero, 2
beq t0, t1, write_pause
nop
lw t0, 0x20(sp)
bnez t0, write_pause
nop
addiu t0, zero, -1
bne s6, t0, write_pause
nop
b done_success
nop
write_pause:
addiu t0, zero, 1
sw t0, 0x24(s0)
done_success:
addiu v0, zero, 1
move v1, zero
b finish
nop
failed:
la a0, {hex(MESSAGE)}
move a1, s1
move a2, s7
lw a3, 0x24(sp)
jal 0x2511c
nop
move v0, zero
move v1, s7
finish:
{end(0x60, REGISTERS)}
"""


def teardown():
    # Partial initialization with no control interface has never run through
    # this manager's Run path. Retain that original partial-object cleanup.
    code = f"""
{frame(0x20, ['s0'])}
move s0, a0
lw t0, 4(s0)
beqz t0, release
nop
move a0, s0
move a1, zero
jal {hex(POLL)}
addiu a2, zero, 1
beqz v0, finish
nop
release:
"""
    for offset in (0x14, 0xC, 8, 4, 0x18, 0x10):
        code += f"""
lw a0, {offset}(s0)
beqz a0, skip_{offset}
nop
lw t0, 0(a0)
lw t9, 8(t0)
jalr t9
nop
sw zero, {offset}(s0)
skip_{offset}:
"""
    return code + f"""
jal 0x231a4
nop
sw zero, 0x28(v0)
addiu v0, zero, 1
finish:
{end(0x20, ['s0'])}
"""


def render_init():
    return f"""
{frame(0x20, ['s0'])}
move s0, a0
lw t0, 0x10(s0)
beqz t0, initialize
nop
jal {hex(TEARDOWN)}
move a0, s0
beqz v0, finish
nop
initialize:
jal 0x11054
move a0, s0
finish:
{end(0x20, ['s0'])}
"""


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError("Expected the exact MAX04 MgrUSB.exe")
    pe = pefile.PE(data=raw)
    out, edits, relocations, added_rows = bytearray(raw), [], [], []

    def edit(at, new, reason, assembly=None):
        off = pe.get_offset_from_rva(at - BASE)
        old = raw[off:off + len(new)]
        edits.append(dict(va=hex(at), offset=off, bytes=len(new),
                          before_hex=old.hex(), after_hex=new.hex(), reason=reason,
                          **({"assembly": assembly} if assembly else {})))
        out[off:off + len(new)] = new

    def block(at, capacity, code, reason, helper=False, leaf=False):
        new, recipe, rel = assemble(code, at, capacity)
        if helper:
            if any(pe.get_data(at - BASE, capacity)):
                raise ValueError("Occupied helper space")
            regs = REGISTERS if at == POLL else ["s0"]
            added_rows.append((at, at + recipe["used_bytes"], 0, 0,
                               at if leaf else at + 8 + 4 * len(regs)))
        edit(at, new, reason, recipe)
        relocations.extend(rel)

    block(POLL, 0x600, transition(), "Nonblocking, checked graph-state polling", True)
    block(TEARDOWN, 0x200, teardown(), "Retain interfaces after an unconfirmed stop", True)
    block(RENDER_INIT, 0x100, render_init(), "Refuse replacement when teardown fails", True)
    for at, sites, success, failure, label in GATES:
        block(at, 0x40, f"""
beqz v0, failed
nop
la t9, {hex(success)}
jr t9
nop
failed:
la t9, {hex(failure)}
jr t9
nop
""", label + " requires a successful transition", helper=True, leaf=True)
        for site in sites:
            block(site, 4, f"jal {hex(at)}", label + " failure propagation")
    message = "USB graph transition failed: pause=%u reason=%u hr=%08x\r\n\0"
    if any(pe.get_data(MESSAGE - BASE, len(message) * 2)):
        raise ValueError("Occupied diagnostic text space")
    edit(MESSAGE, message.encode("utf-16-le"), "One diagnostic per failed transition")

    # Retain the original routine entries, stack frames and epilogues.
    block(0x11594, 0x1175C - 0x11594, f"""
move s0, a0
move s2, a1
la t0, 0x2f96c
lw t0, 0(t0)
beqz t0, unavailable
move s1, zero
move a0, s0
move a1, zero
jal {hex(POLL)}
move a2, s2
move s1, v0
unavailable:
b 0x1175c
nop
""", "Stop commits cached state only after an observed completed stop")
    for start, stop in ((0x117B4, 0x118EC), (0x1193C, 0x11A84)):
        mode = 1 if start == 0x117B4 else 2
        block(start, stop - start, f"""
move s1, a0
move s0, zero
lw t0, 4(s1)
beqz t0, finish
nop
lw t0, 0x24(s1)
sltiu t1, t0, 4
beqz t1, finish
nop
move a0, s1
addiu a1, zero, {mode}
jal {hex(POLL)}
move a2, zero
move s0, v0
finish:
b {hex(stop)}
nop
""", "Confirm Pause/RealPause completion, including valid already-paused/stopped calls")
    block(0x11E88, 0x11F60 - 0x11E88,
          f"jal {hex(TEARDOWN)}\nnop\nb 0x11f60\nnop",
          "Propagate teardown failure without releasing interfaces")
    block(0x11F68, 8, "nop\nnop", "Preserve teardown BOOL and graph flag on failure")
    block(0x11F90, 0x11FAC - 0x11F90,
          f"move s0, a1\njal {hex(RENDER_INIT)}\nmove a0, s1",
          "Do not initialize another graph while the current graph is retained")
    # Detach skips this failure gate when the original graph flag was already zero.
    block(0x20BE8, 4, "beqz a0, 0x20c08", "Bypass teardown-result gate when no graph was active")
    block(0x20C00, 0x28, """
beqz v0, 0x20e88
move s1, v0
jal 0x231a4
nop
lw a0, 0x38(v0)
beqz a0, 0x20c44
nop
lw a0, 4(v0)
beqz a0, 0x20c44
nop
""", "Failed detach does not save or publish normal cleanup completion")

    # Grow current tables within checked zero padding. Preserve earlier rows
    # and relocations outside explicitly replaced instruction/table spans.
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows = [struct.unpack_from("<5I", pe.get_data(directory.VirtualAddress, directory.Size), i)
            for i in range(0, directory.Size, 20)]
    rows = sorted(rows + added_rows)
    if any(a[1] > b[0] for a, b in zip(rows, rows[1:])):
        raise ValueError("Overlapping function-table rows")
    table = b"".join(struct.pack("<5I", *row) for row in rows)
    if any(pe.get_data(directory.VirtualAddress + directory.Size, len(table) - directory.Size)):
        raise ValueError("Occupied function-table expansion")
    edit(BASE + directory.VirtualAddress, table, "Add helper exception rows")
    size_offset = directory.get_file_offset() + 4
    edits.append(dict(offset=size_offset, bytes=4, before_hex=raw[size_offset:size_offset+4].hex(),
                      after_hex=struct.pack("<I", len(table)).hex(), reason="Function-table size"))
    struct.pack_into("<I", out, size_offset, len(table))
    for i, row in enumerate(rows):
        for j, value in enumerate(row):
            if value:
                relocations.append((directory.VirtualAddress + i * 20 + j * 4, 3, None))
    spans = [(row["offset"], row["offset"] + row["bytes"]) for row in edits]
    rd = pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    old = pe.get_data(rd.VirtualAddress, rd.Size)
    pos, previous = 0, []
    while pos < len(old):
        page, n = struct.unpack_from("<II", old, pos)
        vals = struct.unpack_from("<" + "H" * ((n - 8) // 2), old, pos + 8)
        i = 0
        while i < len(vals):
            value = vals[i]; i += 1
            kind, at, extra = value >> 12, page + (value & 4095), None
            if kind == 4:
                extra = vals[i]; i += 1
            if kind:
                off = pe.get_offset_from_rva(at)
                if not any(a <= off < b for a, b in spans):
                    previous.append((at, kind, extra))
        pos += n
    combined = sorted(previous + relocations)
    if len({r[0] for r in combined}) != len(combined):
        raise ValueError("Duplicate relocations")
    pages = {}
    for at, kind, extra in combined:
        page = at & ~4095
        pages.setdefault(page, []).append((kind << 12) | (at - page))
        if kind == 4:
            pages[page].append(extra)
    new = bytearray()
    for page, values in sorted(pages.items()):
        if len(values) % 2:
            values.append(0)
        new.extend(struct.pack("<II", page, 8 + 2 * len(values)))
        new.extend(struct.pack("<" + "H" * len(values), *values))
    if len(new) > rd.Size and any(pe.get_data(rd.VirtualAddress + rd.Size, len(new) - rd.Size)):
        raise ValueError("Occupied relocation-table expansion")
    capacity = max(rd.Size, len(new))
    edit(BASE + rd.VirtualAddress, bytes(new) + bytes(capacity - len(new)), "Updated MIPS relocations")
    size_offset = rd.get_file_offset() + 4
    edits.append(dict(offset=size_offset, bytes=4, before_hex=raw[size_offset:size_offset+4].hex(),
                      after_hex=struct.pack("<I", len(new)).hex(), reason="Relocation-table size"))
    struct.pack_into("<I", out, size_offset, len(new))
    result = bytes(out)
    restored = bytearray(result)
    for row in edits:
        restored[row["offset"]:row["offset"]+row["bytes"]] = bytes.fromhex(row["before_hex"])
    if restored != raw:
        raise ValueError("Undeclared changed bytes")
    return result, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits, added_pdata_rows=added_rows,
                        timeout_ms=TIMEOUT_MS, max_polls=MAX_POLLS,
                        native_executed=False, hardware_tested=False)
