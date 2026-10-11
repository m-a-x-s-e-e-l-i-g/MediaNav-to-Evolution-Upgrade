"""Native Blue body-ownership handoff and GUI-side artwork publication.

The serialized controller detaches its completed body into one owned descriptor.
Only the GUI copies bytes to the mapping. Messages carry no pointers; a 500 ms
window timer also drains the slot if its optional wakeup could not be posted.
No executable is written. Window destruction must join the original CSR thread
before retiring the pending descriptor and closing the mapping.
"""
import hashlib
import struct

import pefile

import bt_cover_art_controller as controller
import bt_cover_art_lifecycle as lifecycle
import bt_cover_art_timers as timers
import bt_cover_art_transfer as transfer
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

CONFIG=transfer.CONFIGS['Blue.exe']
HANDOFF=lifecycle.IMAGE_CALLBACK
RETIRE,DRAIN,HEARTBEAT,GUI_INIT,GUI_BEGIN,WINDOW_PROC,GUI_END=(
    0x280000,0x280400,0x280c00,0x281000,0x281800,0x281c00,0x282400)
PENDING,HWND,ALIVE,DISPLAY_TOKEN,DISPLAY_INCARNATION=(0x282800,0x282804,0x282808,0x28280c,0x282810)
JOINED,JOIN_WAIT,JOIN_SITE,THREAD_HANDLE=0x282814,0x283000,0x24150,0x110274
STATE_SIZE,DESCRIPTOR_SIZE=24,16
MESSAGE,TIMER,INTERVAL=0x82f1,0x4d41,500
ORIGINAL_WINDOW=0x33d34
REGISTER_HI,REGISTER_LO=0x34000,0x3400c
POST_MESSAGE,SET_TIMER,KILL_TIMER=0x1100ac,0x11000c,0x110008
FREE=0x85bb8


def entry(name):return CONFIG.base+transfer.OFFSETS[name]


def oscall(iat):return f'la t0, {hex(iat)}\nlw t9, 0(t0)\njalr t9\nnop'


def handoff():
    # a0 controller owner, channel, track, borrowed body, encoded length.
    # Successful CAS transfers ownership; never dereference the descriptor after
    # it. The GUI may consume/free it before PostMessage returns.
    return f'''
{frame(0x40,['s0','s1','s2','s3','s4','s5'])}
move s0, a0
move s1, a3
lw s2, 0x50(sp)
beqz s0, bad
nop
lw t0, {controller.OFFSET+8}(s0)
bne t0, a1, bad
nop
lw t0, {controller.OFFSET+12}(s0)
bne t0, a2, bad
nop
lw t0, {controller.OFFSET+64}(s0)
bne t0, s1, bad
nop
lw t0, {controller.OFFSET+72}(s0)
bne t0, s2, bad
nop
beqz s1, bad
nop
sltiu t0, s2, 4
bnez t0, bad
nop
la t0, {hex(transfer.MAX_IMAGE+1)}
sltu t0, s2, t0
beqz t0, bad
nop
addu t0, s1, s2
sltu t0, s1, t0
beqz t0, bad
nop
move a0, s0
jal {hex(timers.CONTEXT)}
nop
beqz v0, bad
nop
la t0, {hex(ALIVE)}
lw t0, 0(t0)
addiu t1, zero, 1
bne t0, t1, bad
nop
la t0, {hex(HWND)}
lw s5, 0(t0)
beqz s5, bad
nop
la t0, {hex(PENDING)}
lw t0, 0(t0)
bnez t0, bad
nop
jal {hex(controller.MALLOC)}
addiu a0, zero, {DESCRIPTOR_SIZE}
move s3, v0
beqz s3, bad
nop
jal {hex(timers.CLOCK)}
nop
move a1, v0
la a0, {hex(CONFIG.state)}
jal {hex(entry('token'))}
nop
beqz v0, descriptor_failed
nop
sw v0, 0(s3)
la t0, {hex(CONFIG.state)}
lw t0, 16(t0)
sw t0, 4(s3)
sw s1, 8(s3)
sw s2, 12(s3)
# Detach BEFORE publishing the descriptor. Once visible to the GUI, the
# controller must never free or read this body again, even on rapid cancellation.
sw zero, {controller.OFFSET+64}(s0)
la a0, {hex(PENDING)}
move a1, s3
move a2, zero
{transfer.api(CONFIG,'compare')}
bnez v0, restore_body
nop
# Only a pointer-free wakeup is posted. The armed GUI timer owns fallback retry.
move a0, s5
ori a1, zero, {MESSAGE}
move a2, zero
move a3, zero
{oscall(POST_MESSAGE)}
addiu v0, zero, 1
b done
nop
restore_body:
sw s1, {controller.OFFSET+64}(s0)
descriptor_failed:
jal {hex(FREE)}
move a0, s3
bad:
move v0, zero
done:
{end(0x40,['s0','s1','s2','s3','s4','s5'])}
'''


def retire():
    # GUI only, a0 descriptor read from the slot. Clear the slot before freeing;
    # no incoming window message carries an old descriptor pointer.
    return f'''
{frame(0x20,['s0'])}
move s0, a0
beqz s0, bad
nop
la a0, {hex(PENDING)}
move a1, zero
move a2, s0
{transfer.api(CONFIG,'compare')}
bne v0, s0, bad
nop
lw a0, 8(s0)
sw zero, 8(s0)
jal {hex(FREE)}
nop
jal {hex(FREE)}
move a0, s0
addiu v0, zero, 1
b done
nop
bad:
move v0, zero
done:
{end(0x20,['s0'])}
'''


def drain():
    return f'''
{frame(0x30,['s0','s1'])}
la t0, {hex(ALIVE)}
lw t0, 0(t0)
addiu t1, zero, 1
bne t0, t1, bad
nop
la t0, {hex(PENDING)}
lw s0, 0(t0)
beqz s0, bad
nop
jal {hex(timers.CLOCK)}
nop
la a0, {hex(CONFIG.state)}
lw a1, 0(s0)
move a2, v0
lw a3, 4(s0)
jal {hex(entry('touch'))}
nop
beqz v0, rejected
nop
lw t0, 4(s0)
sw t0, 0x10(sp)
la a0, {hex(CONFIG.state)}
lw a1, 0(s0)
lw a2, 8(s0)
lw a3, 12(s0)
jal {hex(entry('publish'))}
nop
move s1, v0
addiu t0, zero, 2
beq v0, t0, done
nop
beqz v0, rejected
nop
lw t0, 0(s0)
la t1, {hex(DISPLAY_TOKEN)}
sw t0, 0(t1)
lw t0, 4(s0)
sw t0, 4(t1)
b release
nop
rejected:
move s1, zero
release:
jal {hex(RETIRE)}
move a0, s0
done:
move v0, s1
b finish
nop
bad:
move v0, zero
finish:
{end(0x30,['s0','s1'])}
'''


def heartbeat():
    return f'''
{frame(0x20,['s0'])}
jal {hex(DRAIN)}
nop
la t0, {hex(ALIVE)}
lw t0, 0(t0)
addiu t1, zero, 1
bne t0, t1, done
nop
la t0, {hex(DISPLAY_TOKEN)}
lw s0, 0(t0)
beqz s0, done
nop
jal {hex(timers.CLOCK)}
nop
la a0, {hex(CONFIG.state)}
move a1, s0
move a2, v0
la t0, {hex(DISPLAY_INCARNATION)}
lw a3, 0(t0)
jal {hex(entry('touch'))}
nop
bnez v0, done
nop
la t0, {hex(DISPLAY_TOKEN)}
sw zero, 0(t0)
sw zero, 4(t0)
done:
move v0, zero
{end(0x20,['s0'])}
'''


def gui_init():
    return f'''
{frame(0x20,['s0'])}
move s0, a0
beqz s0, bad
nop
la t0, {hex(ALIVE)}
lw t0, 0(t0)
bnez t0, bad
nop
la t0, {hex(PENDING)}
lw t0, 0(t0)
bnez t0, bad
nop
la a0, {hex(CONFIG.state)}
jal {hex(entry('init'))}
nop
beqz v0, bad
nop
move a0, s0
ori a1, zero, {TIMER}
addiu a2, zero, {INTERVAL}
move a3, zero
{oscall(SET_TIMER)}
beqz v0, close
nop
la t0, {hex(HWND)}
sw s0, 0(t0)
la t0, {hex(ALIVE)}
addiu t1, zero, 1
sw t1, 0(t0)
la t0, {hex(DISPLAY_TOKEN)}
sw zero, 0(t0)
sw zero, 4(t0)
addiu v0, zero, 1
b done
nop
close:
la a0, {hex(CONFIG.state)}
jal {hex(entry('close'))}
nop
bad:
move v0, zero
done:
{end(0x20,['s0'])}
'''


def gui_begin():
    # Stop producers before the original WM_DESTROY joins the CSR thread.
    return f'''
{frame(0x20,['s0'])}
la t0, {hex(JOINED)}
lw t3, 0(t0)
sw zero, 0(t0)
la t1, {hex(THREAD_HANDLE)}
lw t1, 0(t1)
addiu t2, zero, -1
bne t1, t2, active_thread
nop
addiu t2, zero, 2
beq t3, t2, uncertain_thread
nop
addiu t1, zero, 1
sw t1, 0(t0)
b active_thread
nop
uncertain_thread:
# Original StopBtMain may have closed the handle even after a failed wait.
# Its invalid-handle sentinel must not erase the uncertainty on a later destroy.
sw t3, 0(t0)
active_thread:
la t0, {hex(ALIVE)}
lw s0, 0(t0)
sw zero, 0(t0)
la t0, {hex(DISPLAY_TOKEN)}
sw zero, 0(t0)
sw zero, 4(t0)
la a0, {hex(CONFIG.state)}
jal {hex(entry('invalidate'))}
nop
beqz s0, done
nop
la t0, {hex(HWND)}
lw a0, 0(t0)
ori a1, zero, {TIMER}
{oscall(KILL_TIMER)}
done:
move v0, zero
{end(0x20,['s0'])}
'''


def gui_end():
    return f'''
{frame(0x20,[])}
la t0, {hex(JOINED)}
lw t0, 0(t0)
addiu t1, zero, 1
bne t0, t1, done
nop
la t0, {hex(PENDING)}
lw a0, 0(t0)
jal {hex(RETIRE)}
nop
la a0, {hex(CONFIG.state)}
jal {hex(entry('close'))}
nop
la t0, {hex(HWND)}
sw zero, 0(t0)
done:
move v0, zero
{end(0x20,[])}
'''


def join_wait():
    # Preserve the original indefinite WaitForSingleObject and return value.
    # Do not treat a returned WAIT_FAILED/WAIT_TIMEOUT as a joined CSR thread.
    return f'''
{frame(0x20,['s0'])}
{oscall(CONFIG.api['wait'])}
move s0, v0
la t0, {hex(JOINED)}
addiu t1, zero, 2
bnez v0, record
nop
addiu t1, zero, 1
record:
sw t1, 0(t0)
move v0, s0
{end(0x20,['s0'])}
'''


def window():
    return f'''
{frame(0x40,['s0','s1','s2','s3','s4'])}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
ori t0, zero, {MESSAGE}
beq s1, t0, artwork
nop
addiu t0, zero, 0x113
bne s1, t0, creation
nop
ori t0, zero, {TIMER}
beq s2, t0, artwork
nop
creation:
addiu t0, zero, 1
bne s1, t0, destruction
nop
jal {hex(GUI_INIT)}
move a0, s0
b invoke
nop
destruction:
addiu t0, zero, 2
bne s1, t0, invoke
nop
jal {hex(GUI_BEGIN)}
nop
invoke:
move a0, s0
move a1, s1
move a2, s2
jal {hex(ORIGINAL_WINDOW)}
move a3, s3
move s4, v0
addiu t0, zero, 2
bne s1, t0, original_result
nop
# Cleanup requires a checked successful original StopBtMain thread wait.
jal {hex(GUI_END)}
nop
original_result:
move v0, s4
b done
nop
artwork:
# Wakeups and timer ticks carry no body pointers. Never forward them to the
# legacy dispatcher, including ticks left queued after WM_DESTROY.
jal {hex(HEARTBEAT)}
nop
move v0, zero
done:
{end(0x40,['s0','s1','s2','s3','s4'])}
'''


def assembled():
    rows=lifecycle.assembled()+transfer.assembled('Blue.exe')
    clear=f'''{frame(0x20,[])}
la a0, {hex(CONFIG.state)}
jal {hex(entry('invalidate'))}
nop
{end(0x20,[])}'''
    specs=(('image_handoff',HANDOFF,0x1000,handoff()),
           ('image_clear_authority',controller.CLEAR,0x100,clear),
           ('image_retire',RETIRE,0x400,retire()),('image_gui_drain',DRAIN,0x800,drain()),
           ('image_gui_heartbeat',HEARTBEAT,0x400,heartbeat()),
           ('image_gui_init',GUI_INIT,0x800,gui_init()),('image_gui_begin_shutdown',GUI_BEGIN,0x400,gui_begin()),
           ('image_window_proc',WINDOW_PROC,0x800,window()),('image_gui_end_shutdown',GUI_END,0x400,gui_end()),
           ('image_join_wait',JOIN_WAIT,0x400,join_wait()))
    replaced={at for _,at,_,_ in specs}
    rows=[r for r in rows if r['address'] not in replaced]
    for name,at,size,source in specs:
        raw,recipe,relocations=assemble(source,at,size)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    ordered=sorted(rows,key=lambda r:r['address'])
    assert all(a['address']+len(a['raw'])<=b['address'] for a,b in zip(ordered,ordered[1:])), 'Overlapping helpers'
    return rows


def contracts(raw):
    if hashlib.sha256(raw).hexdigest()!=CONFIG.sha256:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase
    pinned={REGISTER_HI:0x3c090003,REGISTER_LO:0x25283d34,JOIN_SITE:0x0100f809}
    for at,word in pinned.items():assert pe.get_data(at-base,4)==struct.pack('<I',word)
    assert pe.get_data(JOIN_SITE+4-base,4)==struct.pack('<I',0x2405ffff)
    imports={i.address:i for d in pe.DIRECTORY_ENTRY_IMPORT if d.dll.lower()==b'coredll.dll' for i in d.imports}
    extra=[]
    for at,ordinal in ((POST_MESSAGE,865),(SET_TIMER,875),(KILL_TIMER,876),(0x11019c,1041),(0x110198,1018)):
        assert imports[at].ordinal==ordinal
        extra.append(dict(iat=hex(at),ordinal=ordinal))
    assert pe.get_data(controller.MALLOC-base,16)==bytes.fromhex('1100083c9c01088d0800000100000000')
    assert pe.get_data(0x8ad6c-base,16)==bytes.fromhex('1100083c9801088d0800000100000000')
    sites=lifecycle.sites(raw)
    sites.update({REGISTER_HI:0x3c090000|(WINDOW_PROC>>16),
                  REGISTER_LO:0x25280000|(WINDOW_PROC&0xffff),JOIN_SITE:(3<<26)|(JOIN_WAIT>>2)})
    return dict(blue_sha256=CONFIG.sha256,window_registration={hex(k):hex(v) for k,v in sites.items()},
                imports=extra,transfer=transfer.contracts('Blue.exe',raw),
                descriptor_bytes=DESCRIPTOR_SIZE,gui_period_ms=INTERVAL,pending_jobs=1)
