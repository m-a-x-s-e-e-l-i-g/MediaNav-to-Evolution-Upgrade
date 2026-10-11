"""Serialized CSR timer binding for the native artwork controller.

No executable is written. GetTickCount's self-contained MIPS stub is pinned to
the original 705md ROM export; its kernel trap remains an OS call. CSR TimerSet,
TimerCancel and current-queue functions are original Blue.exe entry points.
All public wrappers require the owning CSR queue. One 100 ms wakeup is retained
only during a pending operation; disposal cancels it before releasing storage.
The scheduler itself still orders timers using its original wall-clock source.
"""
import bt_cover_art_controller as controller
import bt_cover_art_task as task
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

CLOCK, CONTEXT, STOP_TIMER = 0x25a000, 0x25a100, 0x25a200
ARM, WAKEUP, PUMP = 0x25a400, 0x25a800, 0x25ac00
RAW_PREPARE, RAW_SELECT, RAW_METADATA = 0x25b000, 0x25c000, 0x25d000
SET_TIMER, CANCEL_TIMER, CURRENT_QUEUE = 0x85418, 0x85008, 0x85130
GET_TICK_TRAP = 0xffffbb86
PERIOD_MS, PERIOD_US = 100, 100000
ID, TOKEN = controller.OFFSET+48, controller.OFFSET+52
REGS = ['s0', 's1', 's2', 's3']
CORE_CONTRACT = dict(
    sha256='1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c',
    export='GetTickCount', ordinal=535, rva=0x1b03c, bytes=32,
    bytes_hex='e8ffbd271000bfaf86bb082409f80001000000001000bf8f0800e0031800bd27',
    kernel_trap=hex(GET_TICK_TRAP))

# Exact original self-contained ROM export, with no absolute DLL address/import.
CLOCK_CODE = '''
addiu sp, sp, -0x18
sw ra, 0x10(sp)
addiu t0, zero, -0x447a
jalr t0
nop
lw ra, 0x10(sp)
jr ra
addiu sp, sp, 0x18
'''

CONTEXT_CODE = f'''
{frame(0x20, ['s0'])}
move s0, a0
beqz s0, refused
nop
jal {hex(CURRENT_QUEUE)}
nop
lhu t0, 22(s0)
ori t1, zero, 0xffff
beq t0, t1, refused
nop
bne v0, t0, refused
nop
addiu v0, zero, 1
b done
nop
refused:
move v0, zero
done:
{end(0x20, ['s0'])}
'''

STOP_CODE = f'''
{frame(0x20, ['s0'])}
move s0, a0
beqz s0, absent
nop
lw a0, {ID}(s0)
sw zero, {ID}(s0)
beqz a0, absent
nop
move a1, zero
move a2, zero
jal {hex(CANCEL_TIMER)}
nop
b done
nop
absent:
addiu v0, zero, 1
done:
{end(0x20, ['s0'])}
'''

ARM_CODE = f'''
{frame(0x20, ['s0'])}
move s0, a0
jal {hex(CONTEXT)}
nop
beqz v0, refused
nop
lw t0, {controller.OFFSET}(s0)
beqz t0, inactive
nop
addiu t1, zero, {controller.READY}
beq t0, t1, inactive
nop
addiu t1, zero, {controller.FAILED}
beq t0, t1, inactive
nop
lw t0, {ID}(s0)
bnez t0, accepted
nop
# Timer IDs use the segment's shared 28-bit serial. Preempt its zero-ID wrap
# before posting; a returned zero cannot safely identify a node for cancellation.
la t0, 0x20e36c
lw t0, 0(t0)
lhu t1, 22(s0)
srl t1, t1, 11
andi t1, t1, 0xf
sll t2, t1, 6
sll t3, t1, 5
addu t2, t2, t3
sll t3, t1, 4
addu t2, t2, t3
addu t0, t0, t2
# Original TimerSet invokes the fatal handler above 99 timers. Do not add a
# timer to a saturated scheduler (its current callback may still be counted).
lhu t1, 0x54(t0)
sltiu t1, t1, 99
beqz t1, exhausted
nop
lw t0, 0x28(t0)
la t1, 0xfffffff
beq t0, t1, exhausted
nop
lw t0, {TOKEN}(s0)
ori t1, zero, 0xffff
sltu t1, t0, t1
beqz t1, exhausted
nop
addiu a2, t0, 1
sw a2, {TOKEN}(s0)
la a0, {PERIOD_US}
la a1, {hex(WAKEUP)}
move a3, s0
jal {hex(SET_TIMER)}
nop
beqz v0, exhausted
nop
sw v0, {ID}(s0)
accepted:
addiu v0, zero, 1
b done
nop
inactive:
move a0, s0
jal {hex(STOP_TIMER)}
nop
b done
nop
exhausted:
move a0, s0
jal {hex(controller.CANCEL)}
nop
refused:
move v0, zero
done:
{end(0x20, ['s0'])}
'''

PUMP_CODE = f'''
{frame(0x20, ['s0', 's1'])}
move s0, a0
jal {hex(CONTEXT)}
nop
beqz v0, refused
nop
jal {hex(CLOCK)}
nop
move a1, v0
move a0, s0
jal {hex(controller.TICK)}
nop
move s1, v0
move a0, s0
jal {hex(controller.FLUSH)}
nop
move a0, s0
jal {hex(ARM)}
nop
and v0, v0, s1
b done
nop
refused:
move v0, zero
done:
{end(0x20, ['s0', 's1'])}
'''

WAKE_CODE = f'''
{frame(0x20, ['s0', 's1'])}
move s0, a1
move s1, a0
move a0, s0
jal {hex(CONTEXT)}
nop
beqz v0, done
nop
lw t0, {ID}(s0)
beqz t0, done
nop
lw t0, {TOKEN}(s0)
bne t0, s1, done
nop
# The scheduler already unlinked this timer. Clear before any cancellation.
sw zero, {ID}(s0)
move a0, s0
jal {hex(PUMP)}
nop
done:
move v0, zero
{end(0x20, ['s0', 's1'])}
'''


def wrapper(target, metadata=False):
    """Use current clock, retain ABI arguments, then schedule/cancel the wakeup."""
    fifth = 'lw t0, 0x50(sp)\nsw t0, 0x10(sp)\n' if metadata else ''
    # PREPARE/SELECT expect now as a3. METADATA expects its payload pointer there.
    args = 'move a3, s3' if metadata else 'move a3, v0'
    pre_tick = f'''move a0, s0
move a1, v0
jal {hex(controller.TICK)}
nop
beqz v0, refused
nop
''' if metadata else ''
    return f'''
{frame(0x40, REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
jal {hex(CONTEXT)}
nop
beqz v0, refused
nop
jal {hex(CLOCK)}
nop
{pre_tick}move a0, s0
move a1, s1
move a2, s2
{args}
{fifth}jal {hex(target)}
nop
move s1, v0
move a0, s0
jal {hex(ARM)}
nop
# Rejected stale metadata must not cancel the live session or its timer.
and v0, v0, s1
b done
nop
refused:
move v0, zero
done:
{end(0x40, REGS)}
'''


def assembled():
    rows = controller.assembled()
    replaced = {controller.PREPARE, controller.SELECT, controller.METADATA,
                controller.DISPOSE, task.HANDLE}
    rows = [row for row in rows if row['address'] not in replaced]
    dispose = controller.DISPOSE_CODE.replace('addiu s1, s0,',
        f'move a0, s0\njal {hex(STOP_TIMER)}\nnop\naddiu s1, s0,', 1)
    handle = task.HANDLE_CODE.replace('lw s0, 0(a0)',
        f'lw s0, 0(a0)\nmove a0, s0\njal {hex(PUMP)}\nnop', 1)
    handle = handle.replace('done:\nmove v0, zero',
        f'done:\nmove a0, s0\njal {hex(PUMP)}\nnop\nmove v0, zero')
    specs = [
        (CLOCK, 0x100, CLOCK_CODE, 'Exact 705md GetTickCount ROM stub; kernel OS trap'),
        (CONTEXT, 0x100, CONTEXT_CODE, 'Require serialized owning CSR queue'),
        (STOP_TIMER, 0x200, STOP_CODE, 'Unlink pending timer before any owner/body release'),
        (ARM, 0x400, ARM_CODE, 'Keep one 100 ms CSR wakeup during a pending operation'),
        (WAKEUP, 0x400, WAKE_CODE, 'Match live callback token, refresh clock and rearm if pending'),
        (PUMP, 0x400, PUMP_CODE, 'Refresh monotonic tick before deadlines, deferred sends and timers'),
        (RAW_PREPARE, 0x1000, controller.PREPARE_CODE, 'Retained controller preparation'),
        (RAW_SELECT, 0x1000, controller.SELECT_CODE, 'Retained controller track selection'),
        (RAW_METADATA, 0x1000, controller.METADATA_CODE, 'Retained bounded metadata acceptance'),
        (controller.PREPARE, 0x1000, wrapper(RAW_PREPARE), 'Prepare using real current clock, then arm'),
        (controller.SELECT, 0x1000, wrapper(RAW_SELECT), 'Select using real current clock, then arm'),
        (controller.METADATA, 0x1000, wrapper(RAW_METADATA, True), 'Check current deadline before metadata copying'),
        (controller.DISPOSE, 0x1000, dispose, 'Cancel timer before image/body disposal'),
        (task.HANDLE, 0x400, handle, 'Refresh deadlines before event dispatch and pump after cleanup')]
    for at, capacity, code, purpose in specs:
        raw, recipe, relocations = assemble(code, at, capacity)
        rows.append(dict(address=at, raw=raw, recipe=recipe, relocations=relocations, purpose=purpose))
    clock = next(row['raw'] for row in rows if row['address'] == CLOCK)
    assert clock[:CORE_CONTRACT['bytes']].hex() == CORE_CONTRACT['bytes_hex'], 'ROM GetTickCount instruction pin changed'
    return rows
