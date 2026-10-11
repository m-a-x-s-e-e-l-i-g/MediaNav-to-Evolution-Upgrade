"""Native bounded streaming assembly of ordinary UTF-8 Bluetooth text metadata.

Keep only the three 49-byte display prefixes while consuming complete declared
attribute values. No per-fragment heap allocation and no string-header clamping.
This component is not connected to the native request/reply owner yet.
"""
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

RESET,APPEND,UTF8,FINISH=0x284000,0x284400,0x285400,0x286400
STATE,SIZE=0x294000,320
# count0, parsed4, header_used8, remaining12, id16, copied20, seen24,
# bad28, total32, max_bytes36, header40, text48..307, lengths308..319.
TEXT=STATE+48


def reset():return f'''
la t0, {hex(STATE)}
la t1, {hex(STATE+SIZE)}
clear:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, clear
nop
la t0, {hex(STATE)}
addiu t1, a0, -1
sltiu t1, t1, 7
beqz t1, bad
nop
sw a0, 0(t0)
# At most count * (8-byte header + 65535-byte declared string).
sll t1, a0, 16
sll t2, a0, 3
addu t1, t1, t2
subu t1, t1, a0
sw t1, 36(t0)
addiu v0, zero, 1
jr ra
nop
bad:
addiu t1, zero, 1
sw t1, 28(t0)
move v0, zero
jr ra
nop
'''


def append():return f'''
{frame(0x50,['s0','s1','s2','s3','s4','s5','s6'])}
la s0, {hex(STATE)}
move s1, a0
move s2, a1
lw t0, 28(s0)
bnez t0, refused
nop
lw t0, 0(s0)
addiu t0, t0, -1
sltiu t0, t0, 7
beqz t0, bad
nop
ori t0, zero, 0xffff
sltu t0, t0, s2
bnez t0, bad
nop
beqz s2, checked_pointer
nop
beqz s1, bad
nop
addu t0, s1, s2
sltu t0, t0, s1
bnez t0, bad
nop
checked_pointer:
lw t0, 32(s0)
addu t1, t0, s2
sltu t2, t1, t0
bnez t2, bad
nop
lw t0, 36(s0)
sltu t0, t0, t1
bnez t0, bad
nop
sw t1, 32(s0)
loop:
lw t0, 12(s0)
bnez t0, body
nop
lw t0, 8(s0)
addiu t1, zero, 8
beq t0, t1, complete
nop
sltiu t1, t0, 8
beqz t1, bad
nop
beqz s2, accepted
nop
lw t1, 4(s0)
lw t2, 0(s0)
sltu t1, t1, t2
beqz t1, bad
nop
addiu t1, s0, 40
addu t1, t1, t0
lbu t2, 0(s1)
sb t2, 0(t1)
addiu s1, s1, 1
addiu s2, s2, -1
addiu t0, t0, 1
sw t0, 8(s0)
addiu t1, zero, 8
bne t0, t1, loop
nop
# Decode all eight header bytes only after they have been assembled.
lbu t0, 40(s0)
sll t0, t0, 24
lbu t1, 41(s0)
sll t1, t1, 16
or t0, t0, t1
lbu t1, 42(s0)
sll t1, t1, 8
or t0, t0, t1
lbu t1, 43(s0)
or s3, t0, t1
addiu t0, s3, -1
sltiu t1, t0, 7
beqz t1, bad
nop
addiu t1, zero, 1
beqz t0, bit_ready
nop
bit:
sll t1, t1, 1
addiu t0, t0, -1
bnez t0, bit
nop
bit_ready:
lw t2, 24(s0)
and t3, t2, t1
bnez t3, bad
nop
or t2, t2, t1
sw t2, 24(s0)
sltiu t1, s3, 4
beqz t1, length
nop
lbu t1, 44(s0)
sll t1, t1, 8
lbu t2, 45(s0)
or t1, t1, t2
addiu t2, zero, 106
bne t1, t2, bad
nop
length:
lbu t1, 46(s0)
sll t1, t1, 8
lbu t2, 47(s0)
or t1, t1, t2
sw t1, 12(s0)
sw s3, 16(s0)
sw zero, 20(s0)
sltiu t2, s3, 4
beqz t2, loop
nop
addiu t0, s3, -1
sll t0, t0, 2
addiu t0, t0, 308
addu t0, t0, s0
sw t1, 0(t0)
b loop
nop
body:
beqz s2, accepted
nop
move s4, s2
sltu t1, t0, s4
beqz t1, chunk
nop
move s4, t0
chunk:
lw s3, 16(s0)
sltiu t1, s3, 4
beqz t1, advance
nop
beqz s3, bad
nop
lw t1, 20(s0)
sltiu t2, t1, 50
beqz t2, bad
nop
addiu t2, zero, 49
subu t2, t2, t1
move s6, s4
sltu t3, t2, s6
beqz t3, copy_size
nop
move s6, t2
copy_size:
addiu s5, s0, 48
addiu t2, zero, 1
beq s3, t2, destination
nop
addiu t2, zero, 2
bne s3, t2, album
nop
addiu s5, s5, 100
b destination
nop
album:
addiu s5, s5, 50
destination:
addu s5, s5, t1
move t2, s1
move t3, s6
beqz t3, copied
nop
copy:
lbu t4, 0(t2)
sb t4, 0(s5)
addiu t2, t2, 1
addiu s5, s5, 1
addiu t3, t3, -1
bnez t3, copy
nop
copied:
addu t1, t1, s6
sw t1, 20(s0)
advance:
addu s1, s1, s4
subu s2, s2, s4
lw t0, 12(s0)
subu t0, t0, s4
sw t0, 12(s0)
b loop
nop
complete:
lw t0, 4(s0)
addiu t0, t0, 1
lw t1, 0(s0)
sltu t2, t1, t0
bnez t2, bad
nop
sw t0, 4(s0)
sw zero, 8(s0)
b loop
nop
accepted:
addiu v0, zero, 1
b done
nop
bad:
addiu t0, zero, 1
sw t0, 28(s0)
refused:
move v0, zero
done:
{end(0x50,['s0','s1','s2','s3','s4','s5','s6'])}
'''


def utf8():return f'''
{frame(0x40,['s0','s1','s2','s3','s4','s5'])}
move s0, a0
move s1, a1
move s2, a0
outer:
lbu s4, 0(s2)
beqz s4, valid
nop
sltiu t0, s4, 0x80
bnez t0, ascii
nop
sltiu t0, s4, 0xc2
bnez t0, bad
nop
sltiu t0, s4, 0xf5
beqz t0, bad
nop
move s3, s2
addiu s5, zero, 1
sltiu t0, s4, 0xe0
bnez t0, lead
nop
addiu s5, zero, 2
sltiu t0, s4, 0xf0
bnez t0, lead
nop
addiu s5, zero, 3
lead:
addiu s2, s2, 1
continuation:
lbu t0, 0(s2)
beqz t0, clipped
nop
sltiu t1, t0, 0x80
bnez t1, bad
nop
sltiu t1, t0, 0xc0
beqz t1, bad
nop
addiu t1, s3, 1
bne s2, t1, next
nop
addiu t1, zero, 0xe0
bne s4, t1, surrogate
nop
sltiu t1, t0, 0xa0
bnez t1, bad
nop
surrogate:
addiu t1, zero, 0xed
bne s4, t1, four_min
nop
sltiu t1, t0, 0xa0
beqz t1, bad
nop
four_min:
addiu t1, zero, 0xf0
bne s4, t1, four_max
nop
sltiu t1, t0, 0x90
bnez t1, bad
nop
four_max:
addiu t1, zero, 0xf4
bne s4, t1, next
nop
sltiu t1, t0, 0x90
beqz t1, bad
nop
next:
addiu s2, s2, 1
addiu s5, s5, -1
bnez s5, continuation
nop
b outer
nop
ascii:
addiu s2, s2, 1
b outer
nop
clipped:
subu t0, s2, s0
addiu t1, zero, 49
bne t0, t1, bad
nop
sltiu t0, s1, 50
bnez t0, bad
nop
# Only a genuine display-prefix truncation may trim an unfinished code point.
sb zero, 0(s3)
valid:
addiu v0, zero, 1
b done
nop
bad:
move v0, zero
done:
{end(0x40,['s0','s1','s2','s3','s4','s5'])}
'''


def finish():return f'''
{frame(0x30,['s0','s1'])}
la s0, {hex(STATE)}
lw t0, 28(s0)
bnez t0, refused
nop
lw t0, 0(s0)
addiu t1, t0, -1
sltiu t1, t1, 7
beqz t1, bad
nop
lw t1, 4(s0)
bne t0, t1, bad
nop
lw t0, 8(s0)
bnez t0, bad
nop
lw t0, 12(s0)
bnez t0, bad
nop
lw t0, 24(s0)
andi t0, t0, 1
beqz t0, bad
nop
move s1, zero
field:
addiu a0, s0, 48
beqz s1, pointer
nop
addiu t0, zero, 1
bne s1, t0, album
nop
addiu a0, a0, 100
b pointer
nop
album:
addiu a0, a0, 50
pointer:
sll t0, s1, 2
addiu t0, t0, 308
addu t0, t0, s0
lw a1, 0(t0)
jal {hex(UTF8)}
nop
beqz v0, bad
nop
addiu s1, s1, 1
sltiu t0, s1, 3
bnez t0, field
nop
addiu v0, s0, 48
b done
nop
bad:
addiu t0, zero, 1
sw t0, 28(s0)
refused:
move v0, zero
done:
{end(0x30,['s0','s1'])}
'''


def assembled():
    rows=[]
    for name,at,n,source in (('text_stream_reset',RESET,0x200,reset()),
                             ('text_stream_append',APPEND,0x1000,append()),
                             ('text_utf8_prefix',UTF8,0x1000,utf8()),
                             ('text_stream_finish',FINISH,0x400,finish())):
        raw,recipe,relocations=assemble(source,at,n)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    return rows
