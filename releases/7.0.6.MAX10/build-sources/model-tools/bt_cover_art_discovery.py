"""Bounded native SDP extraction before the original borrowed result is freed.

Assembled interpreter helpers only. No executable/LGU is written. The private
capability message consumer, peer selection and PE placement remain separate.
"""
import hashlib
import struct

import pefile

from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end
from bt_cover_art_task import QUEUE

READ, UUID, WALK = 0x266000, 0x266400, 0x266800
PSM, EXTRACT, CAPTURE, WRAP = 0x267000, 0x268000, 0x268800, 0x269000
SITE, ORIGINAL = 0x58de4, 0x584bc
CLASS, PRIMITIVE, MESSAGE_SIZE = 0x7f40, 1, 24


def reader():
    # a0 cursor, a1 end, a2 three DWORD output (kind, width, value pointer).
    # Validate complete input before writing the output. No pointer arithmetic
    # may wrap; the caller owns an aligned twelve-byte output allocation.
    return """
move v0, zero
beqz a0, done
nop
beqz a2, done
nop
andi t0, a2, 3
bnez t0, done
nop
addiu t0, a2, 12
sltu t0, t0, a2
bnez t0, done
nop
sltu t0, a0, a1
beqz t0, done
nop
lbu t0, 0(a0)
addiu t1, a0, 1
srl t2, t0, 3
andi t3, t0, 7
sltiu t0, t2, 9
beqz t0, done
nop
beqz t2, nil
nop
sltiu t0, t2, 3
bnez t0, integer
nop
addiu t0, zero, 3
beq t2, t0, uuid_width
nop
addiu t0, zero, 5
beq t2, t0, boolean
nop
sltiu t0, t3, 5
bnez t0, done
nop
b variable
nop
integer:
sltiu t0, t3, 5
beqz t0, done
nop
b fixed
nop
uuid_width:
addiu t0, zero, 1
beq t3, t0, fixed
nop
addiu t0, zero, 2
beq t3, t0, fixed
nop
addiu t0, zero, 4
bne t3, t0, done
nop
b fixed
nop
boolean:
bnez t3, done
nop
fixed:
addiu t4, zero, 1
fixed_shift:
beqz t3, bounded
nop
sll t4, t4, 1
b fixed_shift
addiu t3, t3, -1
b bounded
nop
nil:
bnez t3, done
nop
b bounded
move t4, zero
variable:
addiu t3, t3, -5
addiu t5, zero, 1
length_shift:
beqz t3, length_ready
nop
sll t5, t5, 1
b length_shift
addiu t3, t3, -1
length_ready:
subu t6, a1, t1
sltu t0, t6, t5
bnez t0, done
move t4, zero
length_loop:
lbu t0, 0(t1)
sll t4, t4, 8
or t4, t4, t0
addiu t1, t1, 1
addiu t5, t5, -1
bnez t5, length_loop
nop
bounded:
sltiu t0, t4, 4097
beqz t0, done
nop
subu t6, a1, t1
sltu t0, t6, t4
bnez t0, done
nop
sw t2, 0(a2)
sw t4, 4(a2)
sw t1, 8(a2)
addu v0, t1, t4
done:
jr ra
nop
"""


def uuid():
    # a0 is a validated READ result. Zero means not a supported nonzero UUID.
    base = bytes.fromhex('00001000800000805f9b34fb')
    checks = ''.join(f'lbu t0, {i+4}(t2)\naddiu t0, t0, {-b}\nbnez t0, done\nnop\n'
                     for i, b in enumerate(base))
    return f"""
move v0, zero
lw t0, 0(a0)
addiu t1, zero, 3
bne t0, t1, done
nop
lw t1, 4(a0)
lw t2, 8(a0)
addiu t0, zero, 16
bne t1, t0, scalar
nop
{checks}
addiu t1, zero, 4
scalar:
addiu t0, zero, 2
beq t1, t0, decode
nop
addiu t0, zero, 4
bne t1, t0, done
nop
decode:
lbu t0, 0(t2)
sll v0, v0, 8
or v0, v0, t0
addiu t2, t2, 1
addiu t1, t1, -1
bnez t1, decode
nop
done:
jr ra
nop
"""


def walker():
    regs = ['s0', 's1', 's2', 's3', 's4']
    return f"""
{frame(0x50, regs)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
sltiu t0, s3, 9
beqz t0, bad
nop
lw t0, 0(s2)
beqz t0, bad
nop
addiu t0, t0, -1
sw t0, 0(s2)
addiu a2, sp, 0x20
jal {hex(READ)}
nop
beqz v0, bad
nop
move s4, v0
lw t0, 0x20(sp)
addiu t1, zero, 6
beq t0, t1, children
nop
addiu t1, zero, 7
bne t0, t1, good
nop
children:
lw s0, 0x28(sp)
child_loop:
beq s0, s4, good
nop
move a0, s0
move a1, s4
move a2, s2
jal {hex(WALK)}
addiu a3, s3, 1
beqz v0, bad
nop
b child_loop
move s0, v0
good:
b finish
move v0, s4
bad:
move v0, zero
finish:
{end(0x50, regs)}
"""


def parser():
    regs = ['s0', 's1', 's2', 's3', 's4', 's5', 's6', 's7']
    # Generic WALK rejects malformed nested data, >512 nodes and depth >8.
    # Then inspect exactly two descriptors: L2CAP(UUID 100, uint16 PSM),
    # OBEX(UUID 8). All browsing/non-OBEX lists are ignored.
    return f"""
{frame(0x90, regs)}
move s0, a0
beqz s0, bad
nop
beqz a1, bad
nop
sltiu t0, a1, 4097
beqz t0, bad
nop
addu s1, a0, a1
sltu t0, s1, a0
bnez t0, bad
nop
addiu t0, zero, 512
sw t0, 0x30(sp)
move a1, s1
addiu a2, sp, 0x30
jal {hex(WALK)}
move a3, zero
bne v0, s1, bad
nop
move a0, s0
move a1, s1
jal {hex(READ)}
addiu a2, sp, 0x20
lw t0, 0x20(sp)
addiu t1, zero, 6
bne t0, t1, bad
nop
lw s0, 0x28(sp)
move s2, zero
lists:
beq s0, s1, good
nop
move a0, s0
move a1, s1
jal {hex(READ)}
addiu a2, sp, 0x20
beqz v0, bad
nop
move s7, v0
lw t0, 0x20(sp)
addiu t1, zero, 6
bne t0, t1, bad
nop
lw s0, 0x28(sp)
move s3, s7
move s6, zero
move s4, zero
move s5, zero
descriptors:
beq s0, s3, inspect
nop
move a0, s0
move a1, s3
jal {hex(READ)}
addiu a2, sp, 0x20
beqz v0, bad
nop
lw t0, 0x20(sp)
addiu t1, zero, 6
bne t0, t1, bad
nop
bnez s6, second
nop
b remember
move s4, s0
second:
addiu t0, zero, 1
bne s6, t0, remember
nop
move s5, s0
remember:
move s0, v0
b descriptors
addiu s6, s6, 1
inspect:
addiu t0, zero, 2
bne s6, t0, next_list
nop
move a0, s4
move a1, s3
jal {hex(READ)}
addiu a2, sp, 0x20
sw v0, 0x34(sp)
lw a0, 0x28(sp)
beq a0, v0, next_list
nop
move a1, v0
jal {hex(READ)}
addiu a2, sp, 0x20
sw v0, 0x38(sp)
jal {hex(UUID)}
addiu a0, sp, 0x20
addiu t0, zero, 0x100
bne v0, t0, next_list
nop
move a0, s5
move a1, s3
jal {hex(READ)}
addiu a2, sp, 0x20
sw v0, 0x3c(sp)
lw a0, 0x28(sp)
beq a0, v0, next_list
nop
move a1, v0
jal {hex(READ)}
addiu a2, sp, 0x20
move s6, v0
jal {hex(UUID)}
addiu a0, sp, 0x20
addiu t0, zero, 8
bne v0, t0, next_list
nop
lw t0, 0x3c(sp)
bne s6, t0, bad
nop
lw a0, 0x38(sp)
lw a1, 0x34(sp)
beq a0, a1, bad
nop
jal {hex(READ)}
addiu a2, sp, 0x20
lw t0, 0x34(sp)
bne v0, t0, bad
nop
lw t0, 0x20(sp)
addiu t1, zero, 1
bne t0, t1, bad
nop
lw t0, 0x24(sp)
addiu t1, zero, 2
bne t0, t1, bad
nop
lw t0, 0x28(sp)
lbu s6, 0(t0)
lbu t0, 1(t0)
sll s6, s6, 8
or s6, s6, t0
sltiu t0, s6, 0x1001
bnez t0, bad
nop
andi t0, s6, 0x101
addiu t1, zero, 1
bne t0, t1, bad
nop
bnez s2, bad
nop
move s2, s6
next_list:
b lists
move s0, s7
good:
b finish
move v0, s2
bad:
move v0, zero
finish:
{end(0x90, regs)}
"""


def extractor():
    regs = ['s0', 's1', 's2', 's3', 's4', 's5', 's6', 's7']
    # Mirror the retained CSR list/node layout, but bound the list walk and each
    # node against the recorded allocation length before dereferencing payload.
    # Original 66d6c advances lengths without these independent bounds.
    return f"""
{frame(0x60, regs)}
move s0, a0
move s1, a1
move s2, a2
move s3, zero
move s4, zero
beqz s0, bad
nop
beqz s2, bad
nop
andi t0, s2, 1
bnez t0, bad
nop
addiu t0, s2, 2
sltu t0, t0, s2
bnez t0, bad
nop
sltiu t0, s1, 32
beqz t0, bad
nop
records:
andi t0, s0, 3
bnez t0, bad
nop
addiu t0, s0, 12
sltu t0, t0, s0
bnez t0, bad
nop
beqz s1, selected
nop
lw s0, 8(s0)
beqz s0, bad
nop
b records
addiu s1, s1, -1
selected:
lhu s7, 4(s0)
lw s0, 0(s0)
beqz s0, bad
nop
andi t0, s0, 1
bnez t0, bad
nop
sltiu t0, s7, 26
bnez t0, bad
nop
addu s7, s0, s7
sltu t0, s7, s0
bnez t0, bad
nop
lhu s5, 0x12(s0)
sltiu t0, s5, 33
beqz t0, bad
nop
lhu t0, 0x14(s0)
addiu t1, zero, 2
beq t0, t1, short_header
nop
addiu t1, zero, 4
bne t0, t1, bad
nop
subu t0, s7, s0
sltiu t0, t0, 38
bnez t0, bad
nop
addiu s0, s0, 0x26
b header_bounds
nop
short_header:
addiu s0, s0, 0x1a
header_bounds:
sltu t0, s7, s0
bnez t0, bad
nop
move s6, zero
nodes:
beq s6, s5, finish
nop
subu t0, s7, s0
sltiu t1, t0, 2
bnez t1, bad
nop
lbu t1, 0(s0)
lbu t2, 1(s0)
sll t2, t2, 8
or t1, t1, t2
sltiu t2, t1, 10
bnez t2, bad
nop
addiu t2, t1, 2
sltu t3, t0, t2
bnez t3, bad
nop
addu s1, s0, t2
lbu t2, 4(s0)
lbu t3, 5(s0)
sll t3, t3, 8
or t2, t2, t3
addiu t3, zero, 13
bne t2, t3, next_node
nop
bnez s3, bad
nop
sltiu t2, t1, 14
bnez t2, bad
nop
sltiu t2, t1, 4110
beqz t2, bad
nop
lbu t2, 12(s0)
addiu t3, zero, 9
bne t2, t3, bad
nop
lbu t2, 13(s0)
bnez t2, bad
nop
lbu t2, 14(s0)
addiu t3, zero, 13
bne t2, t3, bad
nop
addiu s4, t1, -13
addiu s3, s0, 15
next_node:
move s0, s1
b nodes
addiu s6, s6, 1
bad:
move s3, zero
move s4, zero
finish:
beqz s3, returning
nop
sh s4, 0(s2)
returning:
move v0, s3
{end(0x60, regs)}
"""


def capture():
    regs = ['s0', 's1', 's2', 's3', 's4']
    # Copy capabilities, BDADDR and peer ID into one owned queue message.
    # Reuse the current peer's browsing security policy, never SDP pointers.
    return f"""
{frame(0x50, regs)}
move s0, a0
move s1, a1
move s2, a2
beqz s2, bad
nop
lhu t0, 0xc8(s2)
sltiu t0, t0, 0x106
bnez t0, bad
nop
lhu t0, 0xca(s2)
andi t0, t0, 0x100
beqz t0, bad
nop
lw t0, 0x11c(s2)
beqz t0, bad
nop
lhu s4, 0x9a(t0)
la t0, {hex(QUEUE)}
lhu t0, 0(t0)
ori t1, zero, 0xffff
beq t0, t1, bad
nop
sh t0, 0x24(sp)
move a0, s0
move a1, s1
jal {hex(EXTRACT)}
addiu a2, sp, 0x20
beqz v0, bad
nop
move a0, v0
jal {hex(PSM)}
lhu a1, 0x20(sp)
beqz v0, bad
nop
move s3, v0
jal 0x8ad7c
addiu a0, zero, {MESSAGE_SIZE}
beqz v0, bad
nop
move s0, v0
sw zero, 0(s0)
sw zero, 4(s0)
sw zero, 8(s0)
sw zero, 12(s0)
sw zero, 16(s0)
sw zero, 20(s0)
addiu t0, zero, {PRIMITIVE}
sh t0, 0(s0)
lbu t0, 0x10(s2)
sh t0, 2(s0)
lw t0, 8(s2)
sw t0, 4(s0)
lw t0, 12(s2)
sw t0, 8(s0)
sh s3, 12(s0)
sh s4, 14(s0)
lhu t0, 0xc8(s2)
sh t0, 16(s0)
lhu t0, 0xca(s2)
sh t0, 18(s0)
lhu a0, 0x24(sp)
addiu a1, zero, {CLASS}
jal 0x84ec8
move a2, s0
b finish
addiu v0, zero, 1
bad:
move v0, zero
finish:
{end(0x50, regs)}
"""


def wrapper():
    regs = ['s0', 's1', 's2', 's3', 's4', 's5']
    return f"""
{frame(0x50, regs)}
move s4, s2
move s0, a0
move s1, a1
move s2, a2
move s3, a3
lw t0, 0x60(sp)
sw t0, 0x10(sp)
lw t0, 0x64(sp)
sw t0, 0x14(sp)
jal {hex(ORIGINAL)}
nop
move s5, v0
move a0, s0
move a1, s1
jal {hex(CAPTURE)}
move a2, s4
move v0, s5
{end(0x50, regs)}
"""


def assembled():
    rows = []
    for name, at, size, source in (
        ('read', READ, 0x400, reader()), ('uuid', UUID, 0x400, uuid()),
        ('walk', WALK, 0x800, walker()), ('psm', PSM, 0x1000, parser()),
        ('extract', EXTRACT, 0x800, extractor()), ('capture', CAPTURE, 0x800, capture()),
        ('wrap', WRAP, 0x400, wrapper())):
        raw, recipe, relocations = assemble(source, at, size)
        rows.append(dict(name=name, address=at, raw=raw, recipe=recipe, relocations=relocations))
    return rows


def hook_recipe(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe = pefile.PE(data=raw)
    before = pe.get_data(SITE-pe.OPTIONAL_HEADER.ImageBase, 8)
    if before != struct.pack('<II', (3 << 26) | (ORIGINAL >> 2), 0xafaA0010):
        raise ValueError('Unexpected TG-only native SDP parser call/delay slot')
    return dict(site=hex(SITE), before_hex=before.hex(),
                interpreter_after_hex=struct.pack('<I', (3 << 26) | (WRAP >> 2)).hex(),
                executable_written=False)
