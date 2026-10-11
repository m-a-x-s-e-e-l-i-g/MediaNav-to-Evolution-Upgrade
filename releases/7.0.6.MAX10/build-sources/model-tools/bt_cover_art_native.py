"""Import-free MIPS cover-art codecs. Assembled helpers, not a patched CE executable.

Callers own mapped buffer bounds, event serialization, transport and decoder lifetime.
No firmware hooks, allocator, global storage, loader tables or OS calls are added here.
"""
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end
from bt_cover_art_client import TARGET

BASE = 0x46000000  # Interpreter/export address only; not a selected PE code cave.
ATTRIBUTES, CONNECT, THUMBNAIL = BASE, BASE+0x1000, BASE+0x2000


def bounds(pointer, size, scratch, failed='failed'):
    return f'''
beqz {pointer}, {failed}
nop
addiu {scratch}, {pointer}, {size}
sltu t9, {scratch}, {pointer}
bnez t9, {failed}
nop
'''


def stores(raw):
    return '\n'.join(('sb zero, %d(a0)' % i if not value else
                      'addiu t0, zero, %d\nsb t0, %d(a0)' % (value, i)) for i, value in enumerate(raw))


CONNECT_CODE = f'''
sltiu t0, a1, 26
bnez t0, failed
nop
{bounds('a0', 26, 't8')}
{stores(bytes.fromhex('80001a15000400460013')+TARGET)}
jr ra
addiu v0, zero, 26
failed:
jr ra
move v0, zero
'''


THUMBNAIL_CODE = f'''
sltiu t0, a1, 43
bnez t0, failed
nop
{bounds('a0', 43, 't8')}
{bounds('a3', 8, 't7')}
# Require disjoint buffers before any output write.
sltu t0, a0, t7
beqz t0, validate
nop
sltu t0, a3, t8
bnez t0, failed
nop
validate:
lbu t0, 7(a3)
bnez t0, failed
nop
move t1, a3
addiu t2, zero, 7
digits:
lbu t0, 0(t1)
addiu t0, t0, -48
sltiu t0, t0, 10
beqz t0, failed
nop
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, digits
nop
{stores(bytes.fromhex('83002bcb00000001420010')+b'x-bt/img-thm\0'+bytes.fromhex('300013')+bytes(16))}
srl t0, a2, 24
sb t0, 4(a0)
srl t0, a2, 16
sb t0, 5(a0)
srl t0, a2, 8
sb t0, 6(a0)
sb a2, 7(a0)
addiu t1, a0, 28
addiu t2, zero, 7
encode:
lbu t0, 0(a3)
sb t0, 0(t1)
addiu a3, a3, 1
addiu t1, t1, 2
addiu t2, t2, -1
bnez t2, encode
nop
jr ra
addiu v0, zero, 43
failed:
jr ra
move v0, zero
'''


REGS = ['s0', 's1', 's2', 's3', 's4', 's5', 's6']
ATTRIBUTE_CODE = f'''
{frame(0x40, REGS)}
move s0, a0
move s1, a1
move s5, a2
move s6, a3
beqz s0, failed
nop
beqz s1, failed
nop
sltiu t0, s1, 1025
beqz t0, failed
nop
addu t8, s0, s1
sltu t0, t8, s0
bnez t0, failed
nop
sltiu t0, s6, 8
bnez t0, failed
nop
{bounds('s5', 8, 't7')}
sltu t0, s0, t7
beqz t0, begin
nop
sltu t0, s5, t8
bnez t0, failed
nop
begin:
lbu s2, 0(s0)
sltiu t0, s2, 9
beqz t0, failed
nop
addiu s0, s0, 1
addiu s1, s1, -1
move s3, zero
move s4, zero
attribute:
beqz s2, finish
nop
sltiu t0, s1, 8
bnez t0, failed
nop
lbu t0, 0(s0)
lbu t1, 1(s0)
or t0, t0, t1
lbu t1, 2(s0)
or t0, t0, t1
bnez t0, failed
nop
lbu t4, 3(s0)
beqz t4, failed
nop
sltiu t0, t4, 9
beqz t0, failed
nop
# A bounded shift without assembler-dependent SLLV expansion.
addiu t1, t4, -1
addiu t2, zero, 1
mask:
beqz t1, masked
nop
addu t2, t2, t2
addiu t1, t1, -1
b mask
nop
masked:
and t0, s3, t2
bnez t0, failed
nop
or s3, s3, t2
lbu t5, 4(s0)
sll t5, t5, 8
lbu t0, 5(s0)
or t5, t5, t0
lbu t6, 6(s0)
sll t6, t6, 8
lbu t0, 7(s0)
or t6, t6, t0
addiu s0, s0, 8
addiu s1, s1, -8
sltu t0, s1, t6
bnez t0, failed
nop
addiu t0, zero, 8
bne t4, t0, next
nop
addiu t0, zero, 7
bne t6, t0, failed
nop
addiu t0, zero, 3
beq t5, t0, handle
nop
addiu t0, zero, 106
bne t5, t0, failed
nop
handle:
move t1, s0
addiu t2, zero, 7
validate_digits:
lbu t0, 0(t1)
addiu t0, t0, -48
sltiu t0, t0, 10
beqz t0, failed
nop
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, validate_digits
nop
move s4, s0
next:
addu s0, s0, t6
subu s1, s1, t6
addiu s2, s2, -1
b attribute
nop
finish:
bnez s1, failed
nop
beqz s4, missing
nop
move t1, s5
addiu t2, zero, 7
copy:
lbu t0, 0(s4)
sb t0, 0(t1)
addiu s4, s4, 1
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, copy
nop
sb zero, 0(t1)
b done
addiu v0, zero, 1
missing:
b done
move v0, zero
failed:
addiu v0, zero, -1
done:
{end(0x40, REGS)}
'''

HELPERS = ((ATTRIBUTES, 0x800, ATTRIBUTE_CODE, 'Extract current attribute 8; 1=found, 0=absent, -1=invalid'),
           (CONNECT, 0x400, CONNECT_CODE, 'Bounded OBEX CONNECT; output length or zero'),
           (THUMBNAIL, 0x500, THUMBNAIL_CODE, 'Bounded thumbnail GET; output length or zero'))


def assembled():
    result = []
    for address, capacity, code, purpose in HELPERS:
        raw, recipe, relocations = assemble(code, address, capacity)
        if relocations:
            raise ValueError('Codec helpers must have no absolute pointers or relocations')
        result.append(dict(address=address, capacity=capacity, raw=raw, recipe=recipe, purpose=purpose))
    return result
