"""Checked native AppMain artwork worker startup and nonblocking window shutdown.

Create the worker suspended, confirm its priority, then resume. Retain all worker
storage until an actual successful join. This module writes no executable.
"""
import struct

import pefile

import bt_cover_art_app_paint as paint
import bt_cover_art_worker as worker
import bt_cover_art_transfer as transfer
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

START,STOP,REAP,WND=0x238000,0x239000,0x239800,0x23a000
CREATE_THREAD,CREATE_EVENT,PRIORITY,RESUME=0x185094,0x1850a8,0x18512c,0x1850f8
SET_TIMER,KILL_TIMER,EVENT_MODIFY=0x185008,0x185004,0x1850bc
EVENT_SET,BELOW_NORMAL,CREATE_SUSPENDED=3,-1,4


def reap():
    # GUI thread only; ALIVE must already be zero. Never wait for the decoder
    # on this thread. A pending/failed join retains handles and mapping storage.
    return f'''
{frame(0x28,['s0','s1'])}
la s0, {hex(worker.STATE)}
lw t0, 12(s0)
bnez t0, pending
nop
lw s1, 8(s0)
beqz s1, joined
nop
move a0, s1
move a1, zero
{transfer.api(worker.CONFIG,'wait')}
bnez v0, pending
nop
lw t0, 60(s0)
bnez t0, pending
nop
sw zero, 8(s0)
move a0, s1
{transfer.api(worker.CONFIG,'close')}
joined:
lw t0, 60(s0)
bnez t0, pending
nop
jal {hex(worker.TAKE)}
nop
jal {hex(worker.CLEAR)}
nop
lw a0, 4(s0)
sw zero, 4(s0)
beqz a0, mapping
nop
{transfer.api(worker.CONFIG,'close')}
mapping:
la a0, {hex(worker.CONFIG.state)}
jal {hex(worker.entry('close'))}
nop
sw zero, 68(s0)
sw zero, 72(s0)
sw zero, 32(s0)
sw zero, 36(s0)
addiu v0, zero, 1
b done
nop
pending:
move v0, zero
done:
{end(0x28,['s0','s1'])}
'''


def stop():
    return f'''
{frame(0x28,['s0','s1'])}
la s0, {hex(worker.STATE)}
sw zero, 12(s0)
lw s1, 0(s0)
lw a1, 76(s0)
sw zero, 76(s0)
beqz a1, wake
nop
move a0, s1
{worker.oscall(KILL_TIMER)}
wake:
lw a0, 4(s0)
beqz a0, clear
nop
addiu a1, zero, {EVENT_SET}
{worker.oscall(EVENT_MODIFY)}
# Event failure is harmless to ownership: the worker also polls ALIVE after
# its bounded wait. No resource is retired without a successful join.
clear:
sw zero, 0(s0)
sw zero, 64(s0)
jal {hex(worker.TAKE)}
nop
jal {hex(REAP)}
nop
{end(0x28,['s0','s1'])}
'''


def start():
    # a0 hwnd, a1 the retained Bluetooth dialog. The legacy WM_CREATE runs first.
    return f'''
{frame(0x38,['s0','s1','s2','s3'])}
move s1, a0
move s2, a1
beqz s1, refused
nop
beqz s2, refused
nop
la t0, {hex(paint.BT_GLOBAL)}
lw t0, 0(t0)
bne t0, s2, refused
nop
la s0, {hex(worker.STATE)}
lw t0, 12(s0)
beqz t0, prepare
nop
lw t0, 0(s0)
bne t0, s1, refused
nop
lw t0, 64(s0)
bne t0, s2, refused
nop
addiu v0, zero, 1
b done
nop
prepare:
jal {hex(REAP)}
nop
beqz v0, refused
nop
lw s3, 44(s0)
addiu t0, zero, -1
beq s3, t0, refused
nop
la a0, {hex(worker.CONFIG.state)}
jal {hex(worker.entry('init'))}
nop
beqz v0, refused
nop
move a0, zero
addiu a1, zero, 1
move a2, zero
move a3, zero
{worker.oscall(CREATE_EVENT)}
sw v0, 4(s0)
beqz v0, failed
nop
move a0, s1
ori a1, zero, {paint.TIMER}
addiu a2, zero, {worker.PERIOD}
move a3, zero
{worker.oscall(SET_TIMER)}
beqz v0, failed
nop
sw v0, 76(s0)
sw s1, 0(s0)
sw s2, 64(s0)
ori t0, zero, {paint.TIMER}
bne v0, t0, failed
nop
addiu s3, s3, 1
sw s3, 44(s0)
addiu t0, zero, 1
sw t0, 12(s0)
sw zero, 40(s0)
move a0, zero
move a1, zero
la a2, {hex(worker.THREAD)}
la a3, {hex(worker.STATE)}
addiu t0, zero, {CREATE_SUSPENDED}
sw t0, 0x10(sp)
sw zero, 0x14(sp)
{worker.oscall(CREATE_THREAD)}
sw v0, 8(s0)
beqz v0, failed
nop
move a0, v0
addiu a1, zero, {BELOW_NORMAL}
{worker.oscall(PRIORITY)}
beqz v0, priority_failed
nop
addiu t0, zero, 1
sw t0, 68(s0)
lw a0, 8(s0)
{worker.oscall(RESUME)}
addiu t0, zero, 1
bne v0, t0, failed
nop
addiu v0, zero, 1
b done
nop
priority_failed:
# Resume only to let the entry refuse work and exit. Priority flag remains zero.
sw zero, 12(s0)
lw a0, 8(s0)
{worker.oscall(RESUME)}
failed:
jal {hex(STOP)}
nop
refused:
move v0, zero
done:
{end(0x38,['s0','s1','s2','s3'])}
'''


def wnd():
    return f'''
{frame(0x38,['s0','s1','s2','s3','s4'])}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
addiu t0, zero, 2
bne s1, t0, legacy
nop
la t0, {hex(worker.STATE)}
lw t0, 0(t0)
bne s0, t0, legacy
nop
jal {hex(STOP)}
nop
legacy:
move a0, s0
move a1, s1
move a2, s2
jal {hex(paint.WND)}
move a3, s3
move s4, v0
addiu t0, zero, 1
bne s1, t0, done
nop
addiu t0, zero, -1
beq s4, t0, done
nop
la t0, {hex(paint.BT_GLOBAL)}
lw a1, 0(t0)
jal {hex(START)}
move a0, s0
done:
move v0, s4
{end(0x38,['s0','s1','s2','s3','s4'])}
'''


def assembled():
    rows=paint.assembled()
    for name,at,cap,code in (('app_image_start',START,0x1000,start()),('app_image_stop',STOP,0x800,stop()),
                            ('app_image_reap',REAP,0x800,reap()),('app_image_lifetime_window',WND,0x800,wnd())):
        raw,recipe,relocations=assemble(code,at,cap)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    ordered=sorted(rows,key=lambda r:r['address'])
    assert all(a['address']+len(a['raw'])<=b['address'] for a,b in zip(ordered,ordered[1:]))
    return rows


def contracts(raw):
    contract=paint.contracts(raw);pe=pefile.PE(data=raw)
    imports={i.address:(d.dll.lower(),i) for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
    rows=[]
    for at,ordinal in ((CREATE_THREAD,492),(CREATE_EVENT,495),(PRIORITY,514),(RESUME,500),
                       (SET_TIMER,875),(KILL_TIMER,876),(EVENT_MODIFY,494)):
        dll,i=imports[at];assert dll==b'coredll.dll' and i.ordinal==ordinal
        rows.append(dict(iat=hex(at),ordinal=ordinal))
    # Pin the existing EventModify thunk and native signal operation value.
    def read(at,n):return pe.get_data(at-pe.OPTIONAL_HEADER.ImageBase,n)
    assert read(0x1400f8,16)==struct.pack('<IIII',0x3c080018,0x8d0850bc,0x01000008,0)
    assert read(0xe2148,8)==struct.pack('<II',0x0c05003e,0x24050003)
    return dict(paint=contract,imports=rows,join_timeout_ms=0,create_suspended=CREATE_SUSPENDED,
                requested_priority=BELOW_NORMAL,event_set=EVENT_SET,window_generations_wrap=False,
                signal_pin=dict(address=hex(0xe2148),before=read(0xe2148,8).hex()))
