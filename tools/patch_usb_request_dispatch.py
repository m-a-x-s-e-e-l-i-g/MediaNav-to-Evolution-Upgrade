"""Unwired bounded request dispatcher; no original worker body is launched.

Queue -> bound pending records -> one selected lease -> token-checked completion
-> retired records. Caller owns allocation/reclamation and retry scheduling.
"""
import hashlib
from types import FunctionType

import pefile

import patch_usb_completion_event as engine
import patch_usb_lifecycle_protocol as core
import patch_usb_deferred_requests as queue
import patch_usb_request_binding as binding
from patch_updater_copy_safety import frame, end

BASE_SHA = '77f231539594951d308892866d9cbceafe53c3504b7aa54c3ce342ba5e838f64'
STATE, STATE_BYTES = 0x9a880, 40
WAKE, RETIRE, COLLECT, COMPLETE, PUMP = 0x4c180, 0x4c280, 0x4b640, 0x4c820, 0x4cc50
BUDGET, MORE = 8, 13
FIELDS = ('lock', 'inbox', 'active', 'retired', 'pending_reset', 'pending_normal',
          'pending_boot', 'pending_shuffle', 'last_wake_failed', 'active_token')
REGS = [f's{i}' for i in range(8)]


def gate():
    return f'''
la s0, {hex(STATE)}
move a0, s0
addiu a1, zero, 1
move a2, zero
{core.api(0x2f1c4)}
bnez v0, busy
nop
'''


def exits():
    return f'''
release:
move a0, s0
move a1, zero
{core.api(0x2f1b8)}
b done
nop
busy:
addiu s6, zero, {core.BUSY}
b done
nop
invalid:
addiu s6, zero, {core.INVALID}
done:
move v0, s6
{end(0x50, REGS)}
'''


HELPERS = (
    (WAKE, 0x80, f'''
{frame(0x20, [])}
la t0, {hex(queue.QUEUE)}
lw a0, 20(t0)
beqz a0, good
nop
jal 0x2522c
addiu a1, zero, 3
sltiu v0, v0, 1
b store
nop
good:
move v0, zero
store:
la t0, {hex(STATE)}
sw v0, 32(t0)
{end(0x20, [])}
''', 'Signal after bounded backlog/completion; preserve observable wake failure', 8),
    (RETIRE, 0x100, f'''
la t0, {hex(STATE)}
lw t1, 12(t0)
sw t1, 0(a0)
sw a0, 12(t0)
jr ra
nop
''', 'Link a no-longer-active record for caller reclamation; dispatcher gate required', 0),
    (COLLECT, 0x140, f'''
{frame(0x50, REGS)}
move s1, a0
beqz s1, invalid
nop
andi t0, s1, 3
bnez t0, invalid
nop
{gate()}
lw t0, 12(s0)
beqz t0, empty
nop
lw t1, 0(t0)
sw t1, 12(s0)
sw zero, 0(t0)
sw t0, 0(s1)
move s6, zero
b release
nop
empty:
addiu s6, zero, {core.NOT_PENDING}
b release
nop
{exits()}
''', 'Transfer one retired record to caller; busy/empty leave output untouched', 40),
    (COMPLETE, 0x2e0, f'''
{frame(0x50, REGS)}
move s1, a0
move s2, a1
move s3, a2
move s4, a3
beqz s1, invalid
nop
andi t0, s1, 3
bnez t0, invalid
nop
beqz s2, invalid
nop
andi t0, s3, 3
bnez t0, invalid
nop
{gate()}
lw t0, 8(s0)
bne t0, s1, stale
nop
lw t0, 36(s0)
bne t0, s2, stale
nop
lw t0, 28(s1)
bne t0, s2, stale
nop
move a0, s1
move a1, s3
jal {hex(binding.FINISH_RECORD)}
move a2, s4
move s6, v0
lw t0, 24(s1)
addiu t1, zero, {binding.FINISHED}
bne t0, t1, release
nop
sw zero, 8(s0)
sw zero, 36(s0)
jal {hex(RETIRE)}
move a0, s1
jal {hex(WAKE)}
nop
b release
nop
stale:
addiu s6, zero, {core.STALE}
b release
nop
{exits()}
''', 'Complete only matching active pointer/token; retire once and wake pending work', 40),
    (PUMP, 0x3b0, f'''
{frame(0x50, REGS)}
move s1, a0
beqz s1, invalid
nop
andi t0, s1, 3
bnez t0, invalid
nop
la t0, {hex(queue.QUEUE)}
lw t0, 16(t0)
beqz t0, invalid
nop
{gate()}
addiu s2, zero, {BUDGET}
drain:
lw s3, 4(s0)
bnez s3, bind
nop
jal {hex(queue.POP)}
addiu a0, sp, 0x10
beqz v0, popped
nop
addiu t0, zero, {core.NOT_PENDING}
beq v0, t0, choose
nop
move s6, v0
b release
nop
popped:
lw s3, 0x10(sp)
sw s3, 4(s0)
bind:
jal {hex(binding.BIND)}
move a0, s3
beqz v0, bound
nop
addiu t0, zero, {core.BUSY}
beq v0, t0, held
nop
jal {hex(RETIRE)}
move a0, s3
b consumed
nop
bound:
lw t0, 4(s3)
sll t0, t0, 2
addiu s4, s0, 16
addu s4, s4, t0
lw s5, 0(s4)
sw s3, 0(s4)
beqz s5, consumed
nop
addiu t0, zero, {core.STALE}
sw t0, 28(s5)
addiu a0, s5, 24
addiu a1, zero, {binding.DROPPED}
{core.api(0x2f1b8)}
jal {hex(RETIRE)}
move a0, s5
consumed:
sw zero, 4(s0)
addiu s2, s2, -1
bnez s2, drain
nop
jal {hex(WAKE)}
nop
addiu s6, zero, {MORE}
b release
nop
choose:
lw t0, 8(s0)
bnez t0, held
nop
move s7, zero
candidate:
sll t0, s7, 2
addiu s4, s0, 16
addu s4, s4, t0
lw s3, 0(s4)
beqz s3, next
nop
move a0, s3
jal {hex(binding.CLAIM_RECORD)}
addiu a1, sp, 0x14
beqz v0, selected
nop
addiu t0, zero, {core.BUSY}
beq v0, t0, held
nop
sw zero, 0(s4)
jal {hex(RETIRE)}
move a0, s3
next:
addiu s7, s7, 1
sltiu t0, s7, 4
bnez t0, candidate
nop
addiu s6, zero, {core.NOT_PENDING}
b release
nop
selected:
sw zero, 0(s4)
sw s3, 8(s0)
lw t0, 0x14(sp)
sw t0, 36(s0)
sw t0, 4(s1)
sw s3, 0(s1)
move s6, zero
b release
nop
held:
addiu s6, zero, {core.BUSY}
b release
nop
{exits()}
''', 'Bind up to eight queued requests, coalesce pending records, then select one exact lease', 40),
)


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR-45 request-binding prototype')
    pe = pefile.PE(data=raw)
    section = pe.get_section_by_rva(STATE-engine.BASE)
    if (not section or not section.Characteristics & 0x80000000 or
            pe.get_data(STATE-engine.BASE, STATE_BYTES) != bytes(STATE_BYTES)):
        raise ValueError('Dispatcher state requires writable zero bytes')
    context = dict(engine.patch.__globals__, BASE_SHA=BASE_SHA, HELPERS=HELPERS, SITES=())
    result, report = FunctionType(engine.patch.__code__, context)(raw)
    report.update(prototype_only=True, dispatcher_va=hex(STATE), dispatcher_bytes=STATE_BYTES,
                  drain_budget=BUDGET, existing_entry_sites_changed=False,
                  allocation_implemented=False, original_worker_hooks_implemented=False,
                  retry_scheduler_implemented=False, native_shutdown_implemented=False)
    return result, report
