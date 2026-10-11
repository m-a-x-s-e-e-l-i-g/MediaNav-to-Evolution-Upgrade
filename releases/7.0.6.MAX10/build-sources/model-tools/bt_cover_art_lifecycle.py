"""Native source wakeups and live audio gating for the artwork task.

Source commands run on the Windows GUI thread. Their wrapper posts a flat owned
wakeup through the retained CSR external-thread route, without touching selected
peer/task state. The serialized artwork pump reads actual audio-focus/output
flags, cancels inactive work, and refreshes selection once after source resume.
No executable or LGU is written. Global shutdown must quiesce GUI producers.
"""
import hashlib
import struct

import pefile

import bt_cover_art_binding as binding
import bt_cover_art_controller as controller
import bt_cover_art_discovery as discovery
import bt_cover_art_selection as selection
import bt_cover_art_task as task
import bt_cover_art_timers as timers
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

GATE, WAKE, GUI, DISCONNECT = 0x274800, 0x274a00, 0x274c00, 0x275000
RAW_RESOLVE, TICK = 0x275400, 0x276400
BOUNDARY = 0x276c00
IMAGE_CALLBACK = 0x277000
STATE = 0x269410
MANAGER_GLOBAL, SCHEDULER_GLOBAL = 0x20e1e8, 0x20e36c
GUI_SITE, ORIGINAL_GUI = 0x316d0, 0x2efe0
DISCONNECT_TABLE, ORIGINAL_DISCONNECT = 0x101efc, 0x51b74
SOURCE_PRIMITIVE, DISCONNECT_PRIMITIVE = 3, 4


def gate():
    # The original PCM route reads these same shared bytes via 18220/18260.
    # Avoid a shared pointer dereference until manager/A2DP storage exists.
    return f"""
la t0, {hex(MANAGER_GLOBAL)}
lw t0, 0(t0)
beqz t0, bad
nop
lw t0, 0x268(t0)
beqz t0, bad
nop
lbu t1, 0x11c(t0)
addiu t2, zero, 1
bne t1, t2, bad
nop
lbu t1, 0x11d(t0)
bne t1, t2, bad
nop
addiu v0, zero, 1
jr ra
nop
bad:
move v0, zero
jr ra
nop
"""


def wake():
    # a0 primitive3/4. Called on GUI or CSR threads. Never call CURRENT_QUEUE
    # here and never write serialized selection/task state from the GUI thread.
    return f"""
{frame(0x20, ['s0', 's1'])}
move s0, a0
sltiu t0, s0, {SOURCE_PRIMITIVE}
bnez t0, bad
nop
sltiu t0, s0, {DISCONNECT_PRIMITIVE+1}
beqz t0, bad
nop
la t0, {hex(task.QUEUE)}
lhu s1, 0(t0)
sltiu t0, s1, 0x800
beqz t0, bad
nop
la t0, {hex(SCHEDULER_GLOBAL)}
lw t0, 0(t0)
beqz t0, bad
nop
lbu t1, 0x68(t0)
beqz t1, bad
nop
lhu t1, 0x66(t0)
sltu t1, s1, t1
beqz t1, bad
nop
jal {hex(selection.MALLOC)}
addiu a0, zero, 24
beqz v0, bad
nop
sw zero, 0(v0)
sh s0, 0(v0)
sw zero, 4(v0)
sw zero, 8(v0)
sw zero, 12(v0)
sw zero, 16(v0)
sw zero, 20(v0)
move a0, s1
addiu a1, zero, {discovery.CLASS}
jal {hex(selection.POST)}
move a2, v0
addiu v0, zero, 1
b done
nop
bad:
move v0, zero
done:
{end(0x20, ['s0', 's1'])}
"""


def gui():
    # Native dispatcher retains its parent input until this wrapper returns.
    return f"""
{frame(0x30, ['s0', 's1'])}
move s0, zero
beqz a1, invoke
nop
lw s0, 8(a1)
invoke:
jal {hex(ORIGINAL_GUI)}
nop
move s1, v0
# Original source start/play, source stop, streaming start and streaming stop.
la t0, 0x1070502
subu t0, s0, t0
sltiu t0, t0, 4
beqz t0, done
nop
jal {hex(WAKE)}
addiu a0, zero, {SOURCE_PRIMITIVE}
done:
move v0, s1
{end(0x30, ['s0', 's1'])}
"""


def disconnected():
    return f"""
{frame(0x20, ['s0'])}
jal {hex(ORIGINAL_DISCONNECT)}
nop
move s0, v0
jal {hex(WAKE)}
addiu a0, zero, {DISCONNECT_PRIMITIVE}
move v0, s0
{end(0x20, ['s0'])}
"""


def tick():
    # CSR owning queue only. GUI wakeup messages contain no mutable authority:
    # always observe the current actual flags, not a queued historical value.
    return f"""
{frame(0x20, ['s0'])}
move s0, a0
jal {hex(timers.CONTEXT)}
nop
beqz v0, bad
nop
jal {hex(GATE)}
nop
la t0, {hex(STATE)}
lw t1, 0(t0)
sw v0, 0(t0)
addiu t2, zero, 2
beq t1, t2, accepted
nop
beq t1, v0, accepted
nop
beqz v0, accepted
nop
# Resume creates a new selection generation even without a new notification.
# Retain the last native peer/CID/UID values; RESOLVE must validate them again.
la t0, {hex(selection.SNAPSHOT)}
lw t1, 0(t0)
beqz t1, accepted
nop
la t1, {hex(selection.SERIAL)}
lw t2, 0(t1)
addiu t3, zero, -1
beq t2, t3, exhausted
nop
addiu t2, t2, 1
sw t2, 0(t1)
sw t2, 0(t0)
b accepted
nop
exhausted:
sw zero, 0(t0)
accepted:
addiu v0, zero, 1
b done
nop
bad:
move v0, zero
done:
{end(0x20, ['s0'])}
"""


def boundary():
    # A queued source command is a boundary even if OFF/ON happened before the
    # artwork task ran. It can cancel/refresh, but cannot select a historical peer.
    return f"""
{frame(0x20, ['s0'])}
move s0, a0
jal {hex(timers.CONTEXT)}
nop
beqz v0, done
nop
lw t0, {controller.OFFSET}(s0)
beqz t0, generation
nop
addiu t1, zero, {controller.FAILED}
beq t0, t1, generation
nop
move a0, s0
jal {hex(controller.CANCEL)}
nop
generation:
la t0, {hex(selection.SNAPSHOT)}
lw t1, 0(t0)
beqz t1, observed
nop
la t1, {hex(selection.SERIAL)}
lw t2, 0(t1)
addiu t3, zero, -1
beq t2, t3, exhausted
nop
addiu t2, t2, 1
sw t2, 0(t1)
sw t2, 0(t0)
b observed
nop
exhausted:
sw zero, 0(t0)
observed:
jal {hex(GATE)}
nop
la t0, {hex(STATE)}
sw v0, 0(t0)
done:
move v0, zero
{end(0x20, ['s0'])}
"""


def publish():
    # Interpreter callback boundary: the decoder/GUI implementation must also
    # recheck publication identity after decoding and at the eventual UI paint.
    return f"""
{frame(0x50, ['s0', 's1', 's2', 's3'])}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
jal {hex(timers.CONTEXT)}
nop
beqz v0, bad
nop
lw t0, 0(s0)
addiu t1, zero, {controller.owner.ACTIVE}
bne t0, t1, bad
nop
lw t0, {controller.OFFSET}(s0)
addiu t1, zero, {controller.READY}
bne t0, t1, bad
nop
lw t0, {controller.OFFSET+36}(s0)
addiu t1, zero, 1
bne t0, t1, bad
nop
jal {hex(GATE)}
nop
beqz v0, bad
nop
jal {hex(selection.RESOLVE)}
addiu a0, sp, 0x10
beqz v0, bad
nop
la t0, {hex(binding.BIND)}
lw t0, 4(t0)
bne t0, v0, bad
nop
lw t0, {controller.OFFSET+8}(s0)
bne t0, s1, bad
nop
lw t0, {controller.OFFSET+12}(s0)
bne t0, s2, bad
nop
lw t0, 0x60(sp)
sw t0, 0x10(sp)
move a0, s0
move a1, s1
move a2, s2
jal {hex(IMAGE_CALLBACK)}
move a3, s3
b done
nop
bad:
move v0, zero
done:
{end(0x50, ['s0', 's1', 's2', 's3'])}
"""


def assembled():
    rows=binding.assembled()
    resolved=next(r for r in rows if r['address']==selection.RESOLVE)
    raw_resolve=resolved['recipe']['source_assembly']
    init=next(r['recipe']['source_assembly'] for r in rows if r['address']==task.INIT)
    # Initialize after the recoverable owned allocation has been accepted.
    needle='sw s1, 0(s0)'
    assert init.count(needle)==1
    init=init.replace(needle,f'''{needle}
la t0, {hex(STATE)}
addiu t1, zero, 2
sw t1, 0(t0)''',1)
    deinit=next(r['recipe']['source_assembly'] for r in rows if r['address']==task.DEINIT)
    needle='move s0, a0\n'
    assert deinit.count(needle)==1
    deinit=deinit.replace(needle,needle+f'''la t0, {hex(STATE)}
addiu t1, zero, 2
sw t1, 0(t0)
''',1)
    pump=next(r['recipe']['source_assembly'] for r in rows if r['address']==binding.PUMP)
    needle='move a0, s0\njal '+hex(binding.ACTION)
    assert pump.count(needle)==1
    pump=pump.replace(needle,f'''move a0, s0
jal {hex(TICK)}
nop
{needle}''',1)
    handle=next(r['recipe']['source_assembly'] for r in rows if r['address']==selection.metadata.HANDLE)
    needle='lw s0, 0(a0)\nmove a0, s0\njal '+hex(timers.PUMP)+'\nnop'
    assert handle.count(needle)==1
    handle=handle.replace(needle,'lw s0, 0(a0)',1)
    needle='beqz s1, done\nnop'
    assert handle.count(needle)==1
    handle=handle.replace(needle,needle+f'''
addiu t0, zero, {discovery.CLASS}
bne s2, t0, pre_pump
nop
lhu t0, 0(s1)
addiu t1, zero, {SOURCE_PRIMITIVE}
beq t0, t1, private
nop
pre_pump:
move a0, s0
jal {hex(timers.PUMP)}
nop''',1)
    needle='private:\n'
    assert handle.count(needle)==1
    handle=handle.replace(needle,needle+f'''lhu t0, 0(s1)
addiu t1, zero, {SOURCE_PRIMITIVE}
bne t0, t1, private_release
nop
move a0, s0
jal {hex(BOUNDARY)}
nop
private_release:
''',1)
    wrapper=f"""
{frame(0x20, ['s0'])}
move s0, a0
jal {hex(GATE)}
nop
beqz v0, bad
nop
jal {hex(RAW_RESOLVE)}
move a0, s0
b done
nop
bad:
move v0, zero
done:
{end(0x20, ['s0'])}
"""
    replace={selection.RESOLVE,task.INIT,task.DEINIT,binding.PUMP,selection.metadata.HANDLE}
    rows=[r for r in rows if r['address'] not in replace]
    for name,at,capacity,source in (
            ('source_gate',GATE,0x200,gate()),('source_wake',WAKE,0x200,wake()),
            ('source_gui',GUI,0x400,gui()),('source_disconnect',DISCONNECT,0x400,disconnected()),
            ('source_raw_resolve',RAW_RESOLVE,0x1000,raw_resolve),('source_tick',TICK,0x800,tick()),
            ('source_boundary',BOUNDARY,0x400,boundary()),
            ('source_publish_guard',controller.PUBLISH,0x100,publish()),
            ('source_resolve',selection.RESOLVE,0x1000,wrapper),
            ('source_init',task.INIT,0x400,init),('source_deinit',task.DEINIT,0x400,deinit),
            ('source_pump',binding.PUMP,0x400,pump),
            ('source_handle',selection.metadata.HANDLE,0x800,handle)):
        raw,recipe,relocations=assemble(source,at,capacity)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    ordered=sorted(rows,key=lambda r:r['address'])
    for a,b in zip(ordered,ordered[1:]):
        assert a['address']+len(a['raw'])<=b['address'], 'Overlapping helper placements'
    return rows


def sites(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw)
    base=pe.OPTIONAL_HEADER.ImageBase
    assert pe.get_data(GUI_SITE-base,8)==struct.pack('<II',(3<<26)|(ORIGINAL_GUI>>2),0)
    assert pe.get_data(DISCONNECT_TABLE-base,4)==struct.pack('<I',ORIGINAL_DISCONNECT)
    result=selection.sites(raw)
    result.update({GUI_SITE:(3<<26)|(GUI>>2),DISCONNECT_TABLE:DISCONNECT})
    return result
