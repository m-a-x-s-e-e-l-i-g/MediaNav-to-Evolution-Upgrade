"""Consume native selected-track snapshots in the serialized artwork task.

No peer/profile pointer is retained by the task. Resolve the live selected peer
before every pump, cancel stale work before sending, and wait for original close
and metadata-result drains before reopening. Each selection gets at most one
opening attempt; repeated failures do not create a scheduler retry loop.
Interpreter helpers only: source transitions, PE placement and GUI remain open.
"""
import bt_cover_art_controller as controller
import bt_cover_art_metadata as metadata
import bt_cover_art_metadata_ticket as ticket
import bt_cover_art_selection as selection
import bt_cover_art_task as task
import bt_cover_art_timers as timers
import bt_cover_art_discovery as discovery
import bt_cover_art_owner as owner
import bt_cover_art_framer as framer
import bt_cover_art_responses as responses
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

ACTION, PUMP = 0x273400, 0x274400
BIND, SIZE = 0x269500, 48
# attempt_serial0, covered_serial4, birth8, nativeCID12, peerID16, UID64+20,
# capabilities64+28. Remaining words zero/reserved. Cleared by task DEINIT.


def action():
    regs = ['s0', 's1', 's2', 's3', 's4', 's5']
    o=controller.OFFSET
    return f"""
{frame(0x70, regs)}
move s0, a0
jal {hex(timers.CONTEXT)}
nop
beqz v0, refused
nop
la s1, {hex(BIND)}
addiu s2, sp, 0x10
addiu s3, s0, {o}
move a0, s2
jal {hex(selection.RESOLVE)}
nop
beqz v0, absent
nop
move s4, v0
lw t0, 24(s0)
addiu t1, zero, 2
bne t0, t1, refused
nop
lw t0, 0(s3)
beqz t0, idle
nop
addiu t1, zero, {controller.FAILED}
beq t0, t1, idle
nop
# Existing session must still belong to the same native peer incarnation,
# control connection and currently advertised cover-channel capabilities.
lw t0, 20(s2)
lw t1, 8(s1)
bne t0, t1, changed
nop
lw t0, 24(s2)
lw t1, 12(s1)
bne t0, t1, changed
nop
lhu t0, 2(s2)
lw t1, 16(s1)
bne t0, t1, changed
nop
lw t0, 12(s2)
lw t1, 28(s1)
bne t0, t1, changed
nop
lw t0, 16(s2)
lw t1, 32(s1)
bne t0, t1, changed
nop
lw t0, 4(s1)
sltu t0, t0, s4
beqz t0, accepted
nop
# Same-UID requests coalesce while transfer is pending. Once READY, a newer
# legacy request refreshes even a repeated zero UID, without self-triggering.
lw t0, 0(s3)
addiu t1, zero, {controller.READY}
beq t0, t1, refresh
nop
lw t0, 32(s2)
lw t1, 20(s1)
bne t0, t1, changed
nop
lw t0, 36(s2)
lw t1, 24(s1)
bne t0, t1, changed
nop
b accepted
nop
refresh:
la t0, {hex(ticket.SLOT)}
lw t0, 16(t0)
bnez t0, refused
nop
lw s5, 12(s3)
addiu s5, s5, 1
beqz s5, changed
nop
sw s4, 0(s1)
move a0, s0
lw a1, 8(s3)
jal {hex(controller.SELECT)}
move a2, s5
beqz v0, refused
nop
b store
nop
idle:
lw t0, 0(s0)
bnez t0, refused
nop
lw t0, 0(s1)
beq t0, s4, refused
nop
la t0, {hex(ticket.SLOT)}
lw t0, 16(t0)
bnez t0, refused
nop
lw s5, 8(s3)
addiu s5, s5, 1
beqz s5, refused
nop
# Mark before side effects, including a failed optional request/open.
sw s4, 0(s1)
move a0, s0
jal {hex(controller.DISPOSE)}
nop
move a0, s0
jal {hex(metadata.SET_PEER)}
lhu a1, 2(s2)
beqz v0, failed
nop
move a0, s0
move a1, s5
jal {hex(controller.PREPARE)}
addiu a2, zero, 1
beqz v0, failed
nop
move a0, s0
addiu a1, s2, 4
lhu a2, 12(s2)
jal {hex(task.OPEN)}
lhu a3, 14(s2)
beqz v0, failed
nop
store:
sw s4, 4(s1)
lw t0, 20(s2)
sw t0, 8(s1)
lw t0, 24(s2)
sw t0, 12(s1)
lhu t0, 2(s2)
sw t0, 16(s1)
lw t0, 32(s2)
sw t0, 20(s1)
lw t0, 36(s2)
sw t0, 24(s1)
lw t0, 12(s2)
sw t0, 28(s1)
lw t0, 16(s2)
sw t0, 32(s1)
accepted:
addiu v0, zero, 1
b done
nop
absent:
lw t0, 0(s3)
beqz t0, refused
nop
addiu t1, zero, {controller.FAILED}
beq t0, t1, refused
nop
changed:
# A changed identity may reopen after the CM close and old metadata ticket
# drain. A protocol failure on the same selection does not repeat its attempt.
sw zero, 0(s1)
failed:
move a0, s0
jal {hex(controller.CANCEL)}
nop
refused:
move v0, zero
done:
{end(0x70, regs)}
"""


def assembled():
    rows=selection.assembled()
    present={r['address'] for r in rows}
    for r in owner.assembled()+[framer.assembled()]+task.assembled()+responses.assembled():
        if r['address'] not in present:
            rows.append(r)
            present.add(r['address'])
    # Reuse exact previously composed handler/DEINIT assembly, adding only the
    # private flat-value envelope path and binding-state lifetime cleanup.
    handle=next(r['recipe']['source_assembly'] for r in rows if r['address']==metadata.HANDLE)
    needle='addiu t0, zero, 0x11b\nbeq s2, t0, metadata'
    assert handle.count(needle)==1
    handle=handle.replace(needle,f'''addiu t0, zero, {discovery.CLASS}
beq s2, t0, private
nop
{needle}''',1)
    needle='metadata:\nmove a0, s0'
    assert handle.count(needle)==1
    handle=handle.replace(needle,'''private:
# Every private message owns only its envelope. Selection is resolved from live
# serialized state, so stale queued messages cannot resurrect old peer pointers.
move a0, s1
jal 0x85bb8
nop
b done
nop
metadata:
move a0, s0''',1)
    deinit=next(r['recipe']['source_assembly'] for r in rows if r['address']==task.DEINIT)
    needle='move s0, a0\ndrain:'
    assert deinit.count(needle)==1
    deinit=deinit.replace(needle,f'''move s0, a0
la t0, {hex(BIND)}
addiu t1, t0, {SIZE}
clear_binding:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, clear_binding
nop
drain:''',1)
    pump=timers.PUMP_CODE.replace('jal '+hex(timers.CLOCK),f'''move a0, s0
jal {hex(ACTION)}
nop
jal {hex(timers.CLOCK)}''',1)
    assert pump!=timers.PUMP_CODE
    replaced={metadata.HANDLE,task.DEINIT,timers.PUMP}
    rows=[r for r in rows if r['address'] not in replaced]
    for name,at,capacity,source in (
            ('selected_action',ACTION,0x1000,action()),
            ('selected_pump',PUMP,0x400,pump),
            ('selected_handle',metadata.HANDLE,0x800,handle),
            ('selected_deinit',task.DEINIT,0x400,deinit),
            ('selected_pump_forward',timers.PUMP,0x400,f'la t9, {hex(PUMP)}\njr t9\nnop')):
        raw,recipe,relocations=assemble(source,at,capacity)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    ordered=sorted(rows,key=lambda r:r['address'])
    for a,b in zip(ordered,ordered[1:]):
        assert a['address']+len(a['raw'])<=b['address'], 'Overlapping helper placements'
    return rows
