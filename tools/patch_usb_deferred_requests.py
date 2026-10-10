"""Unwired intrusive request FIFO for the USB ownership integration.

One-time initialization before producers start. Caller supplies a private live
32-byte record; it remains queue-owned until POP returns it. No allocation or
blocking retry. BUSY/EMPTY pops do not imply lost requests. No existing hooks.
"""
import hashlib
from types import FunctionType

import pefile

import patch_usb_completion_event as engine
from patch_usb_lifecycle_protocol import OK, BUSY, INVALID, NOT_PENDING, api
from patch_usb_lifecycle_protocol import SUBMIT
from patch_updater_copy_safety import frame, end

BASE_SHA = '2ec74e90a8b89388d210c4bbe08e465fa39e97379b0059c02d550ca5b15ee0e8'
QUEUE, QUEUE_BYTES = 0x9a860, 24
INIT, APPEND, PUSH, POP = 0x4c100, 0x4c200, 0x4c380, 0x4c600
ACCEPT = 0x4cb00
NEW, QUEUED, DEQUEUED = 0, 1, 2
SUBMITTING, ADMITTED, REJECTED = 3, 4, 5
WAKE_FAILED = 9  # Accepted: caller must not enqueue the same record again.
REGS = ['s0', 's1', 's2', 's3', 's4', 's5', 's7']


def read_atomic(pointer):
    return f'move a0, {pointer}\nmove a1, zero\nmove a2, zero\n{api(0x2f1c4)}'


HELPERS = (
    (INIT, 0x100, f'''
{frame(0x30, ['s0', 's1'])}
move s1, a0
la s0, {hex(QUEUE)}
lw t0, 16(s0)
bnez t0, invalid
nop
addiu t0, s0, 8
sw t0, 0(s0)
sw t0, 4(s0)
sw zero, 8(s0)
sw zero, 12(s0)
sw s1, 20(s0)
addiu a0, s0, 16
addiu a1, zero, 1
{api(0x2f1b8)}
b done
move v0, zero
invalid:
addiu v0, zero, {INVALID}
done:
{end(0x30, ['s0', 's1'])}
''', 'Initialize queue before any producer/consumer starts; repeated init refuses', 16),
    (APPEND, 0x180, f'''
{frame(0x30, ['s0', 's1'])}
move s1, a0
sw zero, 0(s1)
la a0, {hex(QUEUE)}
move a1, s1
{api(0x2f1b8)}
move s0, v0
move a0, s0
move a1, s1
{api(0x2f1b8)}
move v0, zero
{end(0x30, ['s0', 's1'])}
''', 'Exchange head then publish predecessor link; private node or consumer stub only', 16),
    (PUSH, 0x280, f'''
{frame(0x40, REGS)}
move s1, a0
beqz s1, invalid
nop
andi t0, s1, 3
bnez t0, invalid
nop
la s0, {hex(QUEUE)}
addiu t0, s0, 8
beq s1, t0, invalid
nop
lw t0, 16(s0)
beqz t0, invalid
nop
lw t0, 4(s1)
sltiu t0, t0, 4
beqz t0, invalid
nop
addiu a0, s1, 24
addiu a1, zero, {QUEUED}
move a2, zero
{api(0x2f1c4)}
bnez v0, invalid
nop
jal {hex(APPEND)}
move a0, s1
lw a0, 20(s0)
beqz a0, accepted
nop
jal 0x2522c
addiu a1, zero, 3
beqz v0, wake_failed
nop
accepted:
move v0, zero
b done
nop
wake_failed:
addiu v0, zero, {WAKE_FAILED}
b done
nop
invalid:
addiu v0, zero, {INVALID}
done:
{end(0x40, REGS)}
''', 'Retain complete caller-owned request; reject duplicate posting; wake after linking', 36),
    (POP, 0x500, f'''
{frame(0x40, REGS)}
move s4, a0
beqz s4, invalid
nop
andi t0, s4, 3
bnez t0, invalid
nop
la s0, {hex(QUEUE)}
lw t0, 16(s0)
beqz t0, invalid
nop
addiu a0, s0, 12
addiu a1, zero, 1
move a2, zero
{api(0x2f1c4)}
bnez v0, busy
nop
lw s1, 4(s0)
addiu s3, s0, 8
{read_atomic('s1')}
move s2, v0
bne s1, s3, real_tail
nop
bnez s2, skip_stub
nop
{read_atomic('s0')}
bne v0, s3, pending_link
nop
addiu s7, zero, {NOT_PENDING}
b release
nop
skip_stub:
sw s2, 4(s0)
move s1, s2
{read_atomic('s1')}
move s2, v0
real_tail:
bnez s2, deliver
nop
{read_atomic('s0')}
bne s1, v0, pending_link
nop
jal {hex(APPEND)}
move a0, s3
{read_atomic('s1')}
move s2, v0
beqz s2, pending_link
nop
deliver:
sw s2, 4(s0)
addiu a0, s1, 24
addiu a1, zero, {DEQUEUED}
{api(0x2f1b8)}
sw s1, 0(s4)
move s7, zero
b release
nop
pending_link:
addiu s7, zero, {BUSY}
release:
addiu a0, s0, 12
move a1, zero
{api(0x2f1b8)}
move v0, s7
b done
nop
busy:
addiu v0, zero, {BUSY}
b done
nop
invalid:
addiu v0, zero, {INVALID}
done:
{end(0x40, REGS)}
''', 'Serialized try-only consumer; pending links return BUSY; delivered records can retire', 36),
    (ACCEPT, 0x280, f'''
{frame(0x30, ['s0', 's1', 's2'])}
move s0, a0
beqz s0, invalid
nop
andi t0, s0, 3
bnez t0, invalid
nop
lw t0, 4(s0)
sltiu t0, t0, 4
beqz t0, invalid
nop
addiu s2, s0, 24
{read_atomic('s2')}
addiu t0, zero, {ADMITTED}
beq v0, t0, accepted
nop
addiu t0, zero, {REJECTED}
beq v0, t0, rejected
nop
addiu t0, zero, {SUBMITTING}
beq v0, t0, busy
nop
addiu t0, zero, {DEQUEUED}
bne v0, t0, invalid
nop
move a0, s2
addiu a1, zero, {SUBMITTING}
addiu a2, zero, {DEQUEUED}
{api(0x2f1c4)}
addiu t0, zero, {DEQUEUED}
bne v0, t0, busy
nop
jal {hex(SUBMIT)}
lw a0, 4(s0)
move s1, v0
addiu t0, zero, {BUSY}
beq v0, t0, retry
nop
beqz v0, admitted
nop
sw s1, 28(s0)
b receipt
addiu a1, zero, {REJECTED}
admitted:
b receipt
addiu a1, zero, {ADMITTED}
retry:
addiu a1, zero, {DEQUEUED}
receipt:
move a0, s2
{api(0x2f1b8)}
b done
move v0, s1
accepted:
b done
move v0, zero
rejected:
b done
lw v0, 28(s0)
busy:
b done
addiu v0, zero, {BUSY}
invalid:
addiu v0, zero, {INVALID}
done:
{end(0x30, ['s0', 's1', 's2'])}
''', 'Admit dequeued request exactly once; ownership BUSY preserves it for retry', 20),
)


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR-43 ownership prototype')
    pe = pefile.PE(data=raw)
    section = pe.get_section_by_rva(QUEUE-engine.BASE)
    if (not section or not section.Characteristics & 0x80000000 or
            pe.get_data(QUEUE-engine.BASE, QUEUE_BYTES) != bytes(QUEUE_BYTES)):
        raise ValueError('Queue state requires existing writable zero bytes')
    context = dict(engine.patch.__globals__, BASE_SHA=BASE_SHA, HELPERS=HELPERS, SITES=())
    result, report = FunctionType(engine.patch.__code__, context)(raw)
    report.update(prototype_only=True, existing_entry_sites_changed=False,
                  queue_va=hex(QUEUE), queue_bytes=QUEUE_BYTES,
                  allocation_implemented=False, receiver_admission_implemented=True,
                  record_lease_binding_implemented=False, worker_dispatch_implemented=False,
                  native_shutdown_implemented=False)
    return result, report
