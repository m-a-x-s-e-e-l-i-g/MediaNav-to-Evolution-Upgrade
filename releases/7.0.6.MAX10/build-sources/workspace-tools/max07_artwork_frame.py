"""Always-visible artwork area in the native Bluetooth Player.

Called in place of the legacy background pass inside the retained MAX06 cover
overlay, so accepted covers still use the existing freshness and lifetime rules.
GDI state is restored and the popup child hierarchy is never covered.
"""


def oscall(iat):
    return f'la t9, {hex(iat)}\nlw t9, 0(t9)\njalr t9\nnop'


def source(text):
    return f'''
addiu sp, sp, -0x48
sw ra, 0x44(sp)
sw s0, 0x40(sp)
sw s1, 0x3c(sp)
sw s2, 0x38(sp)
sw s3, 0x34(sp)
sw s4, 0x30(sp)
move s0, a0
jal 0x134e1c
nop
move s4, v0
lw t0, 0x78(s0)
bnez t0, done
nop
lw s1, 0x28(s0)
beqz s1, done
nop
# GRAY_BRUSH outlines the 128px destination; BLACK_BRUSH fills its interior.
addiu a0, zero, 2
{oscall(0x1850dc)}
beqz v0, done
nop
move a2, v0
addiu t0, zero, 24
sw t0, 0x18(sp)
addiu t0, zero, 116
sw t0, 0x1c(sp)
addiu t0, zero, 152
sw t0, 0x20(sp)
addiu t0, zero, 244
sw t0, 0x24(sp)
move a0, s1
addiu a1, sp, 0x18
{oscall(0x1850f0)}
addiu a0, zero, 4
{oscall(0x1850dc)}
beqz v0, done
nop
move a2, v0
addiu t0, zero, 25
sw t0, 0x18(sp)
addiu t0, zero, 117
sw t0, 0x1c(sp)
addiu t0, zero, 151
sw t0, 0x20(sp)
addiu t0, zero, 243
sw t0, 0x24(sp)
move a0, s1
addiu a1, sp, 0x18
{oscall(0x1850f0)}
move a0, s1
lui a1, 0xaa
ori a1, a1, 0xaaaa
{oscall(0x185240)}
move s2, v0
move a0, s1
addiu a1, zero, 1
{oscall(0x185284)}
move s3, v0
move a0, s1
la a1, {hex(text)}
addiu a2, zero, 9
addiu a3, sp, 0x18
addiu t0, zero, 0x25
sw t0, 0x10(sp)
{oscall(0x18509c)}
move a0, s1
move a1, s3
{oscall(0x185284)}
move a0, s1
move a1, s2
{oscall(0x185240)}
done:
move v0, s4
lw s4, 0x30(sp)
lw s3, 0x34(sp)
lw s2, 0x38(sp)
lw s1, 0x3c(sp)
lw s0, 0x40(sp)
lw ra, 0x44(sp)
jr ra
addiu sp, sp, 0x48
'''
