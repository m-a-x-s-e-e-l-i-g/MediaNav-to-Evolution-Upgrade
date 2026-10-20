"""Rounded-corner key-colour mask for the 278x278 24-bit Bluetooth cover DIB.

POST (called from the decoder wrapper) copies the result and runs MASK. MASKBITS(a0=bits) paints the four corner quarter-discs with the key colour
(R255,G0,B255); the cover painter then draws the bitmap with TransparentImage,
so the screen background shows through on every colour profile. MASK(a0=HBITMAP)
validates the DIB section (278x278, 24 bpp) before calling MASKBITS.
"""
import math
from mips_mini import assemble

EDGE, RADIUS, STRIDE = 278, 16, 836
GETOBJECT_IAT = 0x185078


def widths(radius=RADIUS):
    out = []
    for r in range(radius):
        dy = radius - (r + 0.5)
        edge = radius - math.sqrt(radius * radius - dy * dy)
        out.append(max(0, math.ceil(edge - 0.5)))
    return out


def source(table_at):
    return f"""
post:
move s6, v0
addiu sp, sp, -0x20
sw ra, 0x1c(sp)
beqz v0, post_done
nop
jal mask
move a0, v0
post_done:
lw ra, 0x1c(sp)
addiu sp, sp, 0x20
jr ra
nop
mask:
addiu sp, sp, -0xb0
sw ra, 0xac(sp)
addiu a1, zero, 0x54
addiu a2, sp, 0x20
lui t8, 0x18
addiu t8, t8, {GETOBJECT_IAT & 0xffff}
lw t9, 0(t8)
jalr t9
nop
sltiu t0, v0, 0x54
bnez t0, out
nop
lw t0, 0x24(sp)
addiu t1, zero, {EDGE}
bne t0, t1, out
nop
lw t0, 0x28(sp)
bne t0, t1, out
nop
lhu t0, 0x32(sp)
addiu t1, zero, 24
bne t0, t1, out
nop
lw a0, 0x34(sp)
beqz a0, out
nop
jal maskbits
nop
out:
lw ra, 0xac(sp)
addiu sp, sp, 0xb0
jr ra
nop
maskbits:
move a1, a0
la t0, {(EDGE - 1) * STRIDE}
addu a2, a0, t0
la a3, {table_at}
addiu t9, zero, {RADIUS}
rows:
lbu t1, 0(a3)
move t2, zero
cols:
sltu t3, t2, t1
beqz t3, rowdone
nop
sll t4, t2, 1
addu t4, t4, t2
addiu t5, zero, 255
addu t6, a1, t4
sb t5, 0(t6)
sb zero, 1(t6)
sb t5, 2(t6)
addu t6, a2, t4
sb t5, 0(t6)
sb zero, 1(t6)
sb t5, 2(t6)
addiu t7, zero, {(EDGE - 1) * 3}
subu t7, t7, t4
addu t6, a1, t7
sb t5, 0(t6)
sb zero, 1(t6)
sb t5, 2(t6)
addu t6, a2, t7
sb t5, 0(t6)
sb zero, 1(t6)
sb t5, 2(t6)
addiu t2, t2, 1
beq zero, zero, cols
nop
rowdone:
addiu a1, a1, {STRIDE}
addiu a2, a2, -{STRIDE}
addiu a3, a3, 1
addiu t9, t9, -1
bnez t9, rows
nop
jr ra
nop
"""


def build(at):
    """Place post/mask/maskbits and the width table at `at`; return (blob, entries)."""
    probe, _ = assemble(source(0), at)
    table_at = at + len(probe)
    code, labels = assemble(source(table_at), at)
    assert len(code) == len(probe)
    blob = code + bytes(widths())
    return blob, dict(post=labels["post"], mask=labels["mask"], maskbits=labels["maskbits"],
                      table=table_at, size=len(blob))
