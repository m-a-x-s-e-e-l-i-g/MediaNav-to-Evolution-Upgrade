"""Bounded recovery of required catalog buffers before USB scan dispatch."""
import hashlib
import struct
from types import FunctionType

import pefile
import patch_usb_completion_event as layout
from patch_updater_copy_safety import frame

BASE_SHA = '5f34249de2ec66a9cc3f22a6dc35e063eefc885faee58b3b12d8a5e56a29c234'
GATE, ALLOCATE, COUNTERS = 0x4b000, 0x4b200, 0x9a800
RETRY_LIMIT = 2


def restore(regs):
    return '\n'.join([f'lw {reg}, {0x28-i*4}(sp)' for i, reg in enumerate(regs)] +
                     ['lw ra, 0x2c(sp)', 'addiu sp, sp, 0x30'])


def jump(at):
    return f'la t9, {hex(at)}\njr t9\nnop'


def canceled():
    return 'jal 0x231a4\nnop\nlw t0, 0x18(v0)\nbnez t0, canceled\nnop'


def gate():
    body = [frame(0x30, ['s0', 's1']), 'move s0, a0', 'addiu s1, zero, 1',
            canceled(), 'beqz s0, failed\nnop']
    for i, (slot, size) in enumerate((('addiu a0, s0, 0x18', 0x284880),
                                     ('addiu a0, s0, 0x38', 0x298100),
                                     ('la a0, 0x2fea0', 0x298100))):
        body += [canceled(), slot, f'lui a1, {size >> 16}\nori a1, a1, {size & 65535}',
                 f'la a2, {hex(COUNTERS+4*i)}', f'jal {hex(ALLOCATE)}\nnop',
                 f'bnez v0, next_{i}\nnop\nmove s1, zero\nnext_{i}:']
    body += [canceled(), 'beqz s1, failed\nnop', 'move a0, s0', restore(['s0', 's1']),
             'addiu t0, sp, 0x28\njr ra\nnop',
             'failed:', 'jal 0x231a4\nnop\nlw t0, 0x38(v0)\nbeqz t0, canceled\nnop',
             restore(['s0', 's1']),
             'bnez s5, notify\nnop\nbnez s0, notify\nnop', jump(0x1f31c),
             'notify:', jump(0x1f274), 'canceled:', restore(['s0', 's1']), jump(0x1f31c)]
    return '\n'.join(body)


ALLOCATOR = f'''
{frame(0x30, ['s0', 's1', 's2'])}
move s0, a0
move s1, a1
move s2, a2
lw v0, 0(s0)
bnez v0, done
nop
lw t0, 0(s2)
sltiu t1, t0, {RETRY_LIMIT}
beqz t1, done
nop
la t1, 0x2fe98
lw t1, 0(t1)
sltiu t1, t1, 100
beqz t1, done
nop
addiu t0, t0, 1
sw t0, 0(s2)
jal 0x12844
move a0, s1
beqz v0, done
move s2, v0
move a0, s2
move a1, zero
jal 0x253dc
move a2, s1
move v0, s2
sw v0, 0(s0)
done:
{restore(['s0', 's1', 's2'])}
jr ra
nop
'''
HELPERS = ((GATE, 0x200, gate(), 'Required catalog storage and cancellation checked before root insertion', 16),
           (ALLOCATE, 0x100, ALLOCATOR, 'Retry missing storage at most twice per buffer per process; clear only new buffers', 20))
SITES = ((0x1efd4, 8, f'jal {hex(GATE)}\nlw a0, 0x48(v0)'),)


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR38 catalog-initialization candidate')
    pe = pefile.PE(data=raw)
    assert pe.get_data(0x1efd4-0x10000, 8) == struct.pack('<2I', 0x8c440048, 0x27a80028)
    assert pe.get_data(COUNTERS-0x10000, 12) == bytes(12), 'Occupied recovery counters'
    fn = FunctionType(layout.patch.__code__, dict(layout.patch.__globals__, BASE_SHA=BASE_SHA,
                      HELPERS=HELPERS, SITES=SITES), 'patch_required_catalog_storage')
    candidate, recipe = fn(raw)
    recipe.update(counter_va=hex(COUNTERS), counter_bytes=12, retries_per_buffer_per_process=RETRY_LIMIT,
                  allocator_tracking_guard=100, playlist_buffer_unchanged=True)
    return candidate, recipe
