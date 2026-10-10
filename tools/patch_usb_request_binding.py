"""Unwired 40-byte request binding/claim/completion adapter.

Bind records while holding the ownership gate; claim only their exact identity.
The queue's first 32 bytes remain compatible, but old unbound ADMITTED records
cannot claim. Allocation, retry scheduling and real worker hooks remain absent.
"""
import hashlib
from types import FunctionType

import patch_usb_completion_event as engine
import patch_usb_lifecycle_protocol as core
import patch_usb_deferred_requests as queue
from patch_updater_copy_safety import frame, end

BASE_SHA = 'dbb3f81de76e2b102d6973fff1393bb3124c20cde5c241f69ef69c8a1ce6e3ae'
BIND, CLAIM_RECORD, FINISH_RECORD = 0x4a880, 0x4ac00, 0x4be50
RECORD_BYTES = 40
BOUND, CLAIMED, CLAIMING, FINISHING, FINISHED, DROPPED = range(6, 12)
ALREADY_OWNED = 10  # Status domain, distinct from record receipts.
REGS = [f's{i}' for i in range(8)]


def reserve(expected, transition, repeated):
    return f'''
addiu s5, s2, 24
{queue.read_atomic('s5')}
addiu t0, zero, {repeated}
beq v0, t0, repeated
nop
addiu t0, zero, {queue.REJECTED}
beq v0, t0, cached
nop
addiu t0, zero, {DROPPED}
beq v0, t0, cached
nop
addiu t0, zero, {transition}
beq v0, t0, busy
nop
addiu t0, zero, {expected}
bne v0, t0, invalid
nop
move a0, s5
addiu a1, zero, {transition}
addiu a2, zero, {expected}
{core.api(0x2f1c4)}
addiu t0, zero, {expected}
bne v0, t0, busy
nop
jal {hex(core.TRY)}
nop
bnez v0, retry
nop
la s0, {hex(core.STATE)}
lw t0, 48(s0)
bnez t0, closed
nop
{core.mask()}
'''


def exits(retry_receipt, repeated_status):
    return f'''
closed:
addiu s7, zero, {core.CLOSED}
b rejected
nop
exhausted:
addiu t0, zero, 1
sw t0, 48(s0)
addiu s7, zero, {core.EXHAUSTED}
rejected:
sw s7, 28(s2)
addiu s6, zero, {queue.REJECTED}
publish_unlock:
move a0, s5
move a1, s6
{core.api(0x2f1b8)}
jal {hex(core.UNLOCK)}
nop
b done
nop
retry:
move a0, s5
addiu a1, zero, {retry_receipt}
{core.api(0x2f1b8)}
busy:
addiu s7, zero, {core.BUSY}
b done
nop
cached:
lw s7, 28(s2)
b done
nop
repeated:
addiu s7, zero, {repeated_status}
b done
nop
invalid:
addiu s7, zero, {core.INVALID}
done:
move v0, s7
{end(0x50, REGS)}
'''


def validate():
    return '''
move s2, a0
beqz s2, invalid
nop
andi t0, s2, 3
bnez t0, invalid
nop
lw s1, 4(s2)
sltiu t0, s1, 4
beqz t0, invalid
nop
'''


HELPERS = (
    (BIND, 0x380, f'''
{frame(0x50, REGS)}
{validate()}
{reserve(queue.DEQUEUED, queue.SUBMITTING, BOUND)}
lw t1, 0(s4)
addiu t0, zero, -1
beq t1, t0, exhausted
nop
bnez s1, ordinary
nop
lw t2, 4(s0)
beq t2, t0, exhausted
nop
addiu t2, t2, 1
sw t2, 4(s0)
move t2, s3
b bound
nop
ordinary:
lw t2, 28(s0)
or t2, t2, s3
bound:
addiu t1, t1, 1
sw t1, 0(s4)
sw t2, 28(s0)
lw t0, 4(s0)
sw t0, 32(s2)
sw t1, 36(s2)
move s7, zero
addiu s6, zero, {BOUND}
b publish_unlock
nop
{exits(queue.DEQUEUED, core.OK)}
''', 'Bind payload to the generation/sequence allocated under the ownership gate', 40),
    (CLAIM_RECORD, 0x380, f'''
{frame(0x50, REGS)}
move s6, a1
beqz s6, invalid
nop
andi t0, s6, 3
bnez t0, invalid
nop
{validate()}
subu t0, s6, s2
sltiu t0, t0, 40
bnez t0, invalid
nop
{reserve(BOUND, CLAIMING, CLAIMED)}
lw t0, 32(s2)
lw t1, 4(s0)
bne t0, t1, stale
nop
lw t0, 36(s2)
beqz t0, invalid_binding
nop
lw t1, 0(s4)
bne t0, t1, stale
nop
lw t0, 12(s0)
bnez t0, occupied
nop
lw t2, 28(s0)
and t0, t2, s3
beqz t0, missing
nop
beqz s1, ready
nop
andi t0, t2, 1
bnez t0, occupied
nop
ready:
lw t1, 8(s0)
addiu t0, zero, -1
beq t1, t0, exhausted
nop
addiu t1, t1, 1
sw t1, 8(s0)
sw t1, 12(s0)
lw t0, 32(s2)
sw t0, 16(s0)
sw s1, 20(s0)
lw t0, 36(s2)
sw t0, 24(s0)
subu t2, t2, s3
sw t2, 28(s0)
sw t1, 28(s2)
sw t1, 0(s6)
move s7, zero
addiu s6, zero, {CLAIMED}
b publish_unlock
nop
occupied:
addiu s7, zero, {core.BUSY}
addiu s6, zero, {BOUND}
b publish_unlock
nop
stale:
addiu s7, zero, {core.STALE}
b dropped
nop
missing:
addiu s7, zero, {core.NOT_PENDING}
dropped:
sw s7, 28(s2)
addiu s6, zero, {DROPPED}
b publish_unlock
nop
invalid_binding:
addiu s7, zero, {core.INVALID}
b rejected
nop
{exits(BOUND, ALREADY_OWNED)}
''', 'Claim only the exact bound payload; stale records cannot consume newer pending work', 40),
    (FINISH_RECORD, 0x1b0, f'''
{frame(0x40, ['s0', 's1', 's2', 's3', 's4'])}
move s0, a0
move s1, a1
move s2, a2
beqz s0, invalid
nop
andi t0, s0, 3
bnez t0, invalid
nop
andi t0, s1, 3
bnez t0, invalid
nop
addiu s3, s0, 24
{queue.read_atomic('s3')}
addiu t0, zero, {FINISHED}
beq v0, t0, cached
nop
addiu t0, zero, {FINISHING}
beq v0, t0, busy
nop
addiu t0, zero, {CLAIMED}
bne v0, t0, invalid
nop
move a0, s3
addiu a1, zero, {FINISHING}
addiu a2, zero, {CLAIMED}
{core.api(0x2f1c4)}
addiu t0, zero, {CLAIMED}
bne v0, t0, busy
nop
lw a0, 28(s0)
beqz a0, bad_token
nop
move a1, s1
jal {hex(core.FINISH)}
move a2, s2
move s4, v0
addiu t0, zero, {core.BUSY}
beq v0, t0, retry
nop
sw s4, 28(s0)
b receipt
addiu a1, zero, {FINISHED}
retry:
addiu a1, zero, {CLAIMED}
receipt:
move a0, s3
{core.api(0x2f1b8)}
b done
move v0, s4
bad_token:
addiu s4, zero, {core.INVALID}
b retry
nop
cached:
b done
lw v0, 28(s0)
busy:
b done
addiu v0, zero, {core.BUSY}
invalid:
addiu v0, zero, {core.INVALID}
done:
{end(0x40, ['s0', 's1', 's2', 's3', 's4'])}
''', 'Finish the stored lease once; BUSY retains it and completed retries return cached status', 28),
)


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR-44 deferred-request prototype')
    context = dict(engine.patch.__globals__, BASE_SHA=BASE_SHA, HELPERS=HELPERS, SITES=())
    result, report = FunctionType(engine.patch.__code__, context)(raw)
    report.update(prototype_only=True, record_bytes=RECORD_BYTES,
                  exact_payload_binding_implemented=True,
                  existing_entry_sites_changed=False, worker_dispatch_implemented=False,
                  native_shutdown_implemented=False, allocation_implemented=False)
    return result, report
