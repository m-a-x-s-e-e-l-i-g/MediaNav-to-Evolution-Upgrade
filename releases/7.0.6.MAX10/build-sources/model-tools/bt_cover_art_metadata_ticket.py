"""Native request-to-confirmation correlation prototype for artwork metadata.

Arm one allocated AVRCP 0x20c request before posting. A bridge at the original
request handler's CFM factory call captures that request's actual 0x820d result
allocation. Invalidation retains pending identity until its result is drained;
an old reply therefore cannot borrow a newer channel/track ticket. No result
payload is decoded here, no controller hook or PE is installed, no request posts.
The one static slot requires serialized task/profile callbacks in CSR segment 0.
"""
import hashlib
import struct
import pefile

import bt_cover_art_task as task
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

BEGIN, CAPTURE, TAKE, INVALIDATE = 0x260000, 0x260400, 0x260800, 0x260c00
SLOT, SIZE = 0x261000, 32
SITE, FACTORY, CURRENT_QUEUE = 0x5374c, 0x52a5c, 0x85130
# slot: request0, confirmation4, channel8, track12, phase16, peer20, scope24, valid28.
# phase: idle0, armed1, captured2. Never release identity by timing out alone.


def context():
    return f'''jal {hex(CURRENT_QUEUE)}
nop
sltiu t1, v0, 0x800
beqz t1, refused
nop
la t0, {hex(task.QUEUE)}
lhu t0, 0(t0)
ori t1, zero, 0xffff
beq t0, t1, refused
nop
bne v0, t0, refused
nop'''


BEGIN_CODE = f'''
{frame(0x30, ['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
move s2, a2
beqz s0, refused
nop
andi t0, s0, 3
bnez t0, refused
nop
addiu t0, s0, 20
sltu t0, t0, s0
bnez t0, refused
nop
beqz s1, refused
nop
beqz s2, refused
nop
{context()}
la s3, {hex(SLOT)}
lw t1, 16(s3)
bnez t1, refused
nop
lhu t1, 0(s0)
addiu t2, zero, 0x20c
bne t1, t2, refused
nop
lhu t1, 2(s0)
bne t1, t0, refused
nop
lbu t1, 5(s0)
addiu t2, zero, 3
bne t1, t2, refused
nop
lw t1, 16(s0)
addiu t2, zero, 128
bne t1, t2, refused
nop
# No read of the raw UID is needed: factory input pointer identifies this request.
sw s0, 0(s3)
sw zero, 4(s3)
sw s1, 8(s3)
sw s2, 12(s3)
addiu t0, zero, 1
sw t0, 16(s3)
sw t0, 28(s3)
lbu t0, 4(s0)
sw t0, 20(s3)
addiu t0, zero, 3
sw t0, 24(s3)
addiu v0, zero, 1
b done
nop
refused:
move v0, zero
done:
{end(0x30, ['s0','s1','s2','s3'])}
'''

CAPTURE_CODE = f'''
{frame(0x30, ['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
move s2, a2
jal {hex(FACTORY)}
nop
move s3, v0
jal {hex(CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, done
nop
la t0, {hex(SLOT)}
lw t1, 16(t0)
addiu t2, zero, 1
bne t1, t2, done
nop
lw t1, 0(t0)
addiu t1, t1, 6
bne t1, s2, done
nop
beqz s3, done
nop
# Capture identity even after invalidation; drain its eventual reply before reuse.
sw s3, 4(t0)
sw zero, 0(t0)
addiu t1, zero, 2
sw t1, 16(t0)
lw t1, 20(t0)
bne t1, s0, invalid
nop
lw t1, 24(t0)
beq t1, s1, done
nop
invalid:
sw zero, 28(t0)
done:
move v0, s3
{end(0x30, ['s0','s1','s2','s3'])}
'''

TAKE_CODE = f'''
{frame(0x20, ['s0','s1'])}
move s0, a0
move s1, a1
{context()}
la t0, {hex(SLOT)}
lw t1, 16(t0)
addiu t2, zero, 2
bne t1, t2, refused
nop
lw t1, 4(t0)
bne t1, s0, refused
nop
lw t1, 28(t0)
beqz t1, discarded
nop
beqz s1, refused
nop
andi t1, s1, 3
bnez t1, refused
nop
addiu t1, s1, 8
sltu t2, t1, s1
bnez t2, refused
nop
# Output cannot overlap the slot or its 28-byte confirmation object.
addiu t2, t0, {SIZE}
sltu t2, s1, t2
beqz t2, check_message
nop
sltu t2, t0, t1
bnez t2, refused
nop
check_message:
addiu t2, s0, 28
sltu t3, s1, t2
beqz t3, copy
nop
sltu t3, s0, t1
bnez t3, refused
nop
copy:
lw t1, 8(t0)
lw t2, 12(t0)
sw t1, 0(s1)
sw t2, 4(s1)
addiu v0, zero, 1
b clear
nop
discarded:
addiu v0, zero, 2
clear:
addiu t1, t0, {SIZE}
loop:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, loop
nop
b done
nop
refused:
move v0, zero
done:
{end(0x20, ['s0','s1'])}
'''

INVALIDATE_CODE = f'''
{frame(0x18, [])}
{context()}
la t0, {hex(SLOT)}
sw zero, 28(t0)
addiu v0, zero, 1
b done
nop
refused:
move v0, zero
done:
{end(0x18, [])}
'''


def assembled():
    rows=[]
    for at, code, purpose in (
        (BEGIN, BEGIN_CODE, 'Arm one attribute-8 request and its channel/track ticket before posting'),
        (CAPTURE, CAPTURE_CODE, 'Preserve original CFM constructor and capture only the armed request allocation'),
        (TAKE, TAKE_CODE, 'Drain exact confirmation identity; return live ticket or expired-result discard'),
        (INVALIDATE, INVALIDATE_CODE, 'Invalidate ticket while retaining queued/inflight request identity')):
        raw, recipe, relocations=assemble(code,at,0x400)
        rows.append(dict(address=at,raw=raw,recipe=recipe,relocations=relocations,purpose=purpose))
    return rows


def site_word(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:
        raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    pe=pefile.PE(data=raw)
    old=(3<<26)|(FACTORY>>2)
    assert pe.get_data(SITE-pe.OPTIONAL_HEADER.ImageBase,4)==struct.pack('<I',old)
    # Its original delay slot still forms the UID pointer from the same request.
    assert pe.get_data(SITE+4-pe.OPTIONAL_HEADER.ImageBase,4)==struct.pack('<I',0x26460006)
    return (3<<26)|(CAPTURE>>2)
