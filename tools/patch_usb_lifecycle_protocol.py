"""Unwired MIPS ownership prototype. No existing worker or reset entry is changed.

BUSY is not acceptance: the caller must retain and retry its request. The gate
protects protocol state and the completion callback, not the long-running scan.
"""
import hashlib
from types import FunctionType

import pefile

import patch_usb_completion_event as engine
from patch_updater_copy_safety import frame, end

BASE_SHA = 'a9f0bf2266932d5574abd67c0a6444a27ada6e80064d6ee334db93e14e6d7ec8'
STATE, STATE_BYTES = 0x9a820, 52
TRY, UNLOCK, SUBMIT, CLAIM, FINISH, CLOSE = (
    0x4b400, 0x4b480, 0x4b500, 0x4b780, 0x4ba80, 0x4bd80)
RESET, NORMAL, BOOT, SHUFFLE = range(4)
OK, BUSY, CLOSED, INVALID, EXHAUSTED, STALE, NOT_PENDING, CALLBACK_FAILED, DRAINING = range(9)
FIELDS = ('lock', 'media', 'next_token', 'active_token', 'active_media',
          'active_kind', 'active_seq', 'pending_mask', 'seq_reset', 'seq_normal',
          'seq_boot', 'seq_shuffle', 'closed')
REGS = ['s0', 's1', 's2', 's3', 's4', 's7']


def api(iat):
    return f'la t8, {hex(iat)}\nlw t9, 0(t8)\njalr t9\nnop'


def entry():
    return frame(0x40, REGS)


def exits():
    # All paths holding the gate exit through unlocked; pre-gate errors do not.
    return f'''
busy:
addiu s7, zero, {BUSY}
b done
nop
invalid:
addiu s7, zero, {INVALID}
b done
nop
closed:
addiu s7, zero, {CLOSED}
b unlocked
nop
exhausted:
addiu t0, zero, 1
sw t0, 48(s0)
addiu s7, zero, {EXHAUSTED}
unlocked:
jal {hex(UNLOCK)}
nop
done:
move v0, s7
{end(0x40, REGS)}
'''


def mask():
    return '''
addiu s3, zero, 1
move t0, s1
mask_loop:
beqz t0, mask_done
nop
addu s3, s3, s3
b mask_loop
addiu t0, t0, -1
mask_done:
sll t0, s1, 2
addiu s4, s0, 32
addu s4, s4, t0
'''


HELPERS = (
    (TRY, 0x80, f'''
{frame(0x20, [])}
la a0, {hex(STATE)}
addiu a1, zero, 1
move a2, zero
{api(0x2f1c4)}
{end(0x20, [])}
''', 'Single compare-exchange; no spin or wait', 8),
    (UNLOCK, 0x80, f'''
{frame(0x20, [])}
la a0, {hex(STATE)}
move a1, zero
{api(0x2f1b8)}
{end(0x20, [])}
''', 'Release gate using imported InterlockedExchange', 8),
    (SUBMIT, 0x280, f'''
{entry()}
move s1, a0
sltiu t0, s1, 4
beqz t0, invalid
nop
jal {hex(TRY)}
nop
bnez v0, busy
nop
la s0, {hex(STATE)}
lw t0, 48(s0)
bnez t0, closed
nop
{mask()}
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
b accepted
nop
ordinary:
lw t2, 28(s0)
or t2, t2, s3
accepted:
addiu t1, t1, 1
sw t1, 0(s4)
sw t2, 28(s0)
move s7, zero
b unlocked
nop
{exits()}
''', 'Accept and coalesce requests; reset invalidates the media generation', 32),
    (CLAIM, 0x300, f'''
{entry()}
move s1, a0
move s2, a1
sltiu t0, s1, 4
beqz t0, invalid
nop
beqz s2, invalid
nop
andi t0, s2, 3
bnez t0, invalid
nop
jal {hex(TRY)}
nop
bnez v0, busy
nop
la s0, {hex(STATE)}
lw t0, 48(s0)
bnez t0, closed
nop
lw t0, 12(s0)
bnez t0, occupied
nop
{mask()}
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
lw t0, 4(s0)
sw t0, 16(s0)
sw s1, 20(s0)
lw t0, 0(s4)
sw t0, 24(s0)
subu t2, t2, s3
sw t2, 28(s0)
sw t1, 0(s2)
move s7, zero
b unlocked
nop
occupied:
addiu s7, zero, {BUSY}
b unlocked
nop
missing:
addiu s7, zero, {NOT_PENDING}
b unlocked
nop
{exits()}
''', 'One owner; reset has priority; nonwrapping lease token', 32),
    (FINISH, 0x300, f'''
{entry()}
move s1, a0
move s2, a1
move s3, a2
beqz s1, invalid
nop
andi t0, s2, 3
bnez t0, invalid
nop
jal {hex(TRY)}
nop
bnez v0, busy
nop
la s0, {hex(STATE)}
lw t0, 12(s0)
bne t0, s1, wrong_owner
nop
lw t0, 48(s0)
bnez t0, stale_owner
nop
lw t0, 4(s0)
lw t1, 16(s0)
bne t0, t1, stale_owner
nop
lw t0, 20(s0)
sll t0, t0, 2
addu t0, t0, s0
lw t0, 32(t0)
lw t1, 24(s0)
bne t0, t1, stale_owner
nop
move s7, zero
beqz s2, drain
nop
move t9, s2
jalr t9
move a0, s3
beqz v0, drain
nop
addiu s7, zero, {CALLBACK_FAILED}
b drain
nop
stale_owner:
addiu s7, zero, {STALE}
drain:
sw zero, 12(s0)
b unlocked
nop
wrong_owner:
addiu s7, zero, {STALE}
b unlocked
nop
{exits()}
''', 'Validate owner and generation through publication callback; stale owner drains', 32),
    (CLOSE, 0x180, f'''
{entry()}
jal {hex(TRY)}
nop
bnez v0, busy
nop
la s0, {hex(STATE)}
addiu t0, zero, 1
sw t0, 48(s0)
sw zero, 28(s0)
move s7, zero
lw t0, 12(s0)
beqz t0, unlocked
nop
addiu s7, zero, {DRAINING}
b unlocked
nop
{exits()}
''', 'Close rejects further claims; active owner must drain separately', 32),
)


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR-40 catalog-recovery output')
    pe = pefile.PE(data=raw)
    section = pe.get_section_by_rva(STATE-engine.BASE)
    if (not section or not section.Characteristics & 0x80000000 or
            pe.get_data(STATE-engine.BASE, STATE_BYTES) != bytes(STATE_BYTES)):
        raise ValueError('Protocol state must be zero in an existing writable section')
    context = dict(engine.patch.__globals__, BASE_SHA=BASE_SHA, HELPERS=HELPERS, SITES=())
    result, report = FunctionType(engine.patch.__code__, context)(raw)
    report.update(prototype_only=True, existing_entry_sites_changed=False,
                  state_va=hex(STATE), state_bytes=STATE_BYTES,
                  busy_requests_accepted=False, caller_retry_adapter_implemented=False)
    return result, report
