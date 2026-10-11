"""MAX07 metadata fallback and adaptive low-latency PCM reserve.

New helpers run on existing native ownership threads. Metadata polling is
serialized on the AVRCP scheduler and bounded to one pending empty-title query.
PCM reserve increases only after a real started-stream queue drain.
"""
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

INIT, PROFILE, WAKE, ARM, DROP, CAPTURE = (0x290000, 0x290800, 0x291000, 0x292000, 0x292800, 0x292c00)
THRESHOLD, UNDERFLOW, START = 0x293000, 0x293400, 0x293800
REQUEST = 0x293c00
STATE, AUDIO = 0x300880, 0x3008c0
# STATE: profile0, alive4, timer8, token12, queued request16; remaining reserved.
# AUDIO: weak native context0, restart threshold4, observed drains8.
CURRENT, SET_TIMER, CANCEL_TIMER = 0x85130, 0x85418, 0x85008
PERIOD_US = 2000000


def init():
    return f'''
{frame(0x20,['s0','s1'])}
move s0, a0
jal 0x3b9b8
nop
move s1, v0
la t0, {hex(STATE)}
lw t1, 0(s0)
sw t1, 0(t0)
addiu t1, zero, 1
sw t1, 4(t0)
sw zero, 8(t0)
sw zero, 16(t0)
move v0, s1
{end(0x20,['s0','s1'])}
'''


def profile():
    return f'''
{frame(0x20,['s0'])}
jal 0x3bcc0
nop
move s0, v0
jal {hex(ARM)}
nop
move v0, s0
{end(0x20,['s0'])}
'''


def arm():
    return f'''
{frame(0x20,[])}
la t0, {hex(STATE)}
lw t1, 4(t0)
addiu t2, zero, 1
bne t1, t2, no
nop
lw t1, 8(t0)
bnez t1, no
nop
lw t1, 0(t0)
beqz t1, no
nop
jal {hex(CURRENT)}
nop
sltiu t0, v0, 0x800
beqz t0, no
nop
la t0, 0x218656
lhu t0, 0(t0)
bne v0, t0, no
nop
la t0, 0x20e36c
lw t0, 0(t0)
beqz t0, no
nop
lhu t1, 0x54(t0)
sltiu t1, t1, 99
beqz t1, no
nop
lw t1, 0x28(t0)
la t2, 0xfffffff
beq t1, t2, no
nop
la t0, {hex(STATE)}
lw t1, 12(t0)
ori t2, zero, 0xffff
beq t1, t2, no
nop
addiu a2, t1, 1
sw a2, 12(t0)
la a0, {PERIOD_US}
la a1, {hex(WAKE)}
la a3, {hex(STATE)}
jal {hex(SET_TIMER)}
nop
la t0, {hex(STATE)}
sw v0, 8(t0)
b done
nop
no:
move v0, zero
done:
{end(0x20,[])}
'''


def wake():
    return f'''
{frame(0x40,['s0','s1','s2','s3'])}
la s0, {hex(STATE)}
bne a1, s0, done
nop
lw t0, 12(s0)
bne t0, a0, done
nop
lw t0, 4(s0)
addiu t1, zero, 1
bne t0, t1, done
nop
lw t0, 8(s0)
beqz t0, done
nop
sw zero, 8(s0)
jal {hex(CURRENT)}
nop
la t0, 0x218656
lhu t0, 0(t0)
bne v0, t0, done
nop
jal 0x274800
nop
beqz v0, rearm
nop
lw t0, 16(s0)
bnez t0, rearm
nop
la t0, 0x300600
lw t0, 4(t0)
bnez t0, rearm
nop
la t0, 0x300840
lw t0, 20(t0)
bnez t0, rearm
nop
la t0, 0x20e1e8
lw t0, 0(t0)
beqz t0, rearm
nop
lw s1, 0x26c(t0)
beqz s1, rearm
nop
lbu t0, 0xee(s1)
beqz t0, eligible
nop
lbu t0, 0x20c(s1)
bnez t0, rearm
nop
eligible:
lbu t0, 0x5e(s1)
sll t1, t0, 4
sll t0, t0, 3
addu t0, t0, t1
addu s2, s1, t0
lbu t0, 0x6d(s2)
addiu t1, zero, 2
bne t0, t1, rearm
nop
lw a0, 0(s0)
beqz a0, rearm
nop
addiu a0, a0, 0x7c
addiu a1, zero, 16
lbu a2, 0x6c(s2)
jal 0x8186c
nop
beqz v0, rearm
nop
lbu t0, 0x1e(v0)
addiu t1, zero, 3
bne t0, t1, rearm
nop
addiu a0, zero, 20
jal 0x8ad7c
nop
beqz v0, rearm
nop
move s3, v0
sw zero, 0(s3)
sw zero, 4(s3)
sw zero, 8(s3)
sw zero, 12(s3)
sw zero, 16(s3)
addiu t0, zero, 0x20c
sh t0, 0(s3)
lhu t0, 0x60(s1)
sh t0, 2(s3)
lbu t0, 0x6c(s2)
sb t0, 4(s3)
addiu t0, zero, 3
sb t0, 5(s3)
addiu a0, s3, 6
addiu a1, s1, 0x235
jal 0x85758
addiu a2, zero, 8
lhu t0, 0x246(s1)
sh t0, 14(s3)
addiu t0, zero, 127
sw t0, 16(s3)
sw s3, 16(s0)
jal 0x78bd4
move a0, s3
rearm:
jal {hex(ARM)}
nop
done:
move v0, zero
{end(0x40,['s0','s1','s2','s3'])}
'''


def capture():
    return f'''
{frame(0x20,['s0'])}
la t0, {hex(STATE)}
lw t1, 16(t0)
beqz t1, invoke
nop
addiu t1, t1, 6
bne t1, a2, invoke
nop
sw zero, 16(t0)
invoke:
jal 0x28bc00
nop
move s0, v0
move v0, s0
{end(0x20,['s0'])}
'''


def request():
    # Internal polls repeat native text only. They must not cancel/restart an
    # artwork transfer every two seconds when notifications are unavailable.
    return f'''
{frame(0x30,['s0','s1','s2'])}
move s0, a0
lw s1, 12(s0)
move s2, zero
la t0, {hex(STATE)}
lw t1, 16(t0)
bne t1, s1, external
nop
lw t1, 4(t0)
addiu t2, zero, 1
bne t1, t2, retire
nop
lw t1, 0(t0)
bne t1, s0, retire
nop
jal 0x274800
nop
beqz v0, retire
nop
addiu a0, s1, 6
lbu a1, 4(s1)
jal 0x288800
lhu a2, 2(s1)
beqz v0, retire
nop
addiu a0, s0, 0x7c
addiu a1, zero, 16
jal 0x8186c
lbu a2, 4(s1)
beqz v0, retire
nop
lbu t0, 0x1e(v0)
addiu t1, zero, 3
bne t0, t1, retire
nop
move a0, s0
jal 0x53728
nop
move s2, v0
retire:
la t0, {hex(STATE)}
sw zero, 16(t0)
b done
nop
external:
move a0, s0
jal 0x28e000
nop
move s2, v0
done:
move v0, s2
{end(0x30,['s0','s1','s2'])}
'''


def drop():
    return f'''
{frame(0x20,['s0'])}
move s0, a0
la t0, {hex(STATE)}
sw zero, 4(t0)
sw zero, 0(t0)
sw zero, 16(t0)
lw a0, 8(t0)
sw zero, 8(t0)
beqz a0, native
nop
move a1, zero
move a2, zero
jal {hex(CANCEL_TIMER)}
nop
native:
jal 0x28f400
move a0, s0
{end(0x20,['s0'])}
'''


def threshold():
    # Leaf call from the lock-held PCM process; do not clobber saved input.
    return f'''
la t0, {hex(AUDIO)}
lw t1, 0(t0)
bne t1, s0, initial
nop
lw t1, 4(t0)
sltiu t2, t1, 2
bnez t2, initial
nop
sltiu t2, t1, 9
beqz t2, initial
nop
b compare
nop
initial:
addiu t1, zero, 2
sw s0, 0(t0)
sw t1, 4(t0)
sw zero, 8(t0)
compare:
lbu t0, 5(s0)
sltu v0, t0, t1
jr ra
nop
'''


def underflow():
    # a0 and t3 already name the live native context. Paused/stopped resets
    # and duplicate acknowledgements never count as a started-stream drain.
    return f'''
lbu t0, 4(a0)
addiu t1, zero, 2
bne t0, t1, done
nop
lbu t0, 0x338(a0)
beqz t0, done
nop
la t0, {hex(AUDIO)}
lw t1, 0(t0)
bne t1, a0, done
nop
lw t1, 4(t0)
addiu t1, t1, 2
sltiu t2, t1, 9
bnez t2, store
nop
addiu t1, zero, 8
store:
sw t1, 4(t0)
lw t1, 8(t0)
addiu t1, t1, 1
sw t1, 8(t0)
done:
jr ra
nop
'''


def start():
    return f'''
{frame(0x18,[])}
la t0, {hex(AUDIO)}
sw s0, 0(t0)
addiu t1, zero, 2
sw t1, 4(t0)
sw zero, 8(t0)
jal 0x8a830
nop
{end(0x18,[])}
'''


def assembled():
    result = []
    for name, at, cap, fn in (
        ('metadata_poll_init', INIT, 0x400, init), ('metadata_poll_profile', PROFILE, 0x400, profile),
        ('metadata_poll_wakeup', WAKE, 0x1000, wake), ('metadata_poll_arm', ARM, 0x800, arm),
        ('metadata_poll_shutdown', DROP, 0x400, drop), ('metadata_poll_capture', CAPTURE, 0x400, capture),
        ('pcm_restart_reserve', THRESHOLD, 0x400, threshold), ('pcm_drain_adaptation', UNDERFLOW, 0x400, underflow),
        ('pcm_start_reserve_reset', START, 0x400, start),
        ('metadata_poll_request', REQUEST, 0x800, request)):
        raw, recipe, relocations = assemble(fn(), at, cap)
        result.append(dict(name=name, address=at, raw=raw, recipe=recipe, relocations=relocations))
    return result
