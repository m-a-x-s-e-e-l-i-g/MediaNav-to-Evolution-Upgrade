"""Owned AppMain artwork snapshot/decode worker and GUI bitmap acceptance.

Worker entry requires an initialized mapping, live window generation, stop event
and confirmed lower thread priority before launch. Creation, window hooks and
paint remain external bindings. No executable is written by these helpers.
"""
import hashlib

import pefile

import bt_cover_art_image as image
import bt_cover_art_transfer as transfer
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

CONFIG=transfer.CONFIGS['AppMain.exe']
THREAD,STEP,TAKE,CLEAR=0x230000,0x231000,0x233000,0x233800
STATE,SIZE=0x234000,80
# GUI: hwnd0, stop event4, thread8, alive12, atomic result slot16,
# owned displayed bitmap20/token24/mapping incarnation28, window incarnation44.
# Worker: attempted token32/incarnation36, exit status40, ticket48[12], buffer60,
# confirmed-priority flag68, captured window incarnation72. Dialog64/reserved76.
PENDING,DISPLAY=STATE+16,STATE+20
TICKET=STATE+48
MESSAGE,PERIOD=0x82f2,200
MALLOC,FREE,CO_INIT,CO_UNINIT=0x1851d0,0x1851cc,0x1853ec,0x1853e4
CLOCK,POST_MESSAGE=0x185000,0x185040
REGS=['s0','s1','s2','s3','s4','s5','s6','s7']


def entry(name):return CONFIG.base+transfer.OFFSETS[name]


def oscall(iat):return f'la t0, {hex(iat)}\nlw t9, 0(t0)\njalr t9\nnop'


def live(label='bad'):
    return f'''
la s0, {hex(STATE)}
lw t0, 12(s0)
addiu t1, zero, 1
bne t0, t1, {label}
nop
lw t0, 68(s0)
bne t0, t1, {label}
nop
beqz s1, {label}
nop
lw t0, 44(s0)
bne t0, s1, {label}
nop
lw t0, 72(s0)
bne t0, s1, {label}
nop
'''


def fresh():
    return f'''
{oscall(CLOCK)}
la a0, {hex(CONFIG.state)}
lw a1, 48(s0)
move a2, v0
lw a3, 56(s0)
jal {hex(entry('fresh'))}
nop
'''


def step():
    # a0 captured window incarnation, serialized worker only. No GUI objects or
    # borrowed Blue pointers are used. GUI may consume the descriptor immediately
    # after slot CAS; only worker-owned ticket fields are read after that point.
    return f'''
{frame(0x40,REGS)}
move s1, a0
{live()}
lw s2, 60(s0)
beqz s2, bad
nop
lw t0, 16(s0)
bnez t0, bad
nop
{oscall(CLOCK)}
la a0, {hex(CONFIG.state)}
lw a1, 32(s0)
move a2, v0
lw a3, 36(s0)
jal {hex(entry('fresh'))}
nop
bnez v0, bad
nop
{oscall(CLOCK)}
sw v0, 0x10(sp)
la a0, {hex(CONFIG.state)}
move a1, s2
la a2, {hex(image.MAX_IMAGE)}
addiu a3, s0, 48
jal {hex(entry('copy'))}
nop
addiu t0, zero, 1
bne v0, t0, bad
nop
{fresh()}
beqz v0, bad
nop
move a0, s2
lw a1, 52(s0)
jal {hex(image.DECODE)}
nop
move s3, v0
beqz s3, attempted
nop
{live('delete_bitmap')}
{fresh()}
beqz v0, delete_bitmap
nop
addiu a0, zero, 16
{oscall(MALLOC)}
move s4, v0
beqz s4, delete_bitmap
nop
lw t0, 48(s0)
sw t0, 0(s4)
lw t0, 56(s0)
sw t0, 4(s4)
sw s3, 8(s4)
sw s1, 12(s4)
la a0, {hex(PENDING)}
move a1, s4
move a2, zero
{transfer.api(CONFIG,'compare')}
bnez v0, delete_descriptor
nop
# The result now belongs to the GUI slot, even if PostMessage fails. Never
# access its descriptor or bitmap after the successful CAS.
lw t0, 48(s0)
sw t0, 32(s0)
lw t0, 56(s0)
sw t0, 36(s0)
lw a0, 0(s0)
beqz a0, accepted
nop
ori a1, zero, {MESSAGE}
move a2, zero
move a3, zero
{oscall(POST_MESSAGE)}
accepted:
addiu v0, zero, 1
b done
nop
delete_descriptor:
move a0, s4
{oscall(FREE)}
delete_bitmap:
jal {hex(image.DELETE_OBJECT)}
move a0, s3
b bad
nop
attempted:
# A failed decode is not retried continuously for the same immutable generation.
lw t0, 48(s0)
sw t0, 32(s0)
lw t0, 56(s0)
sw t0, 36(s0)
bad:
move v0, zero
done:
{end(0x40,REGS)}
'''


def thread():
    # a0 must be the persistent worker state. Caller sets priority before
    # resuming this entry and never closes the mapping/event until actual join.
    return f'''
{frame(0x30,['s0','s1','s2'])}
la s0, {hex(STATE)}
bne a0, s0, refused
nop
lw t0, 12(s0)
addiu t1, zero, 1
bne t0, t1, refused
nop
lw t0, 68(s0)
bne t0, t1, refused
nop
lw s1, 44(s0)
beqz s1, refused
nop
lw t0, 4(s0)
beqz t0, refused
nop
lw t0, 60(s0)
bnez t0, refused
nop
sw s1, 72(s0)
sw zero, 32(s0)
sw zero, 36(s0)
sw zero, 40(s0)
move a0, zero
move a1, zero
{oscall(CO_INIT)}
sltiu t0, v0, 2
beqz t0, com_failed
nop
la a0, {hex(image.MAX_IMAGE)}
{oscall(MALLOC)}
move s2, v0
beqz s2, allocation_failed
nop
sw s2, 60(s0)
loop:
lw t0, 12(s0)
addiu t1, zero, 1
bne t0, t1, cleanup
nop
lw t0, 44(s0)
bne t0, s1, cleanup
nop
lw a0, 4(s0)
move a1, zero
{transfer.api(CONFIG,'wait')}
beqz v0, cleanup
nop
addiu t0, zero, 258
bne v0, t0, wait_failed
nop
jal {hex(STEP)}
move a0, s1
lw a0, 4(s0)
addiu a1, zero, {PERIOD}
{transfer.api(CONFIG,'wait')}
beqz v0, cleanup
nop
addiu t0, zero, 258
beq v0, t0, loop
nop
wait_failed:
addiu t0, zero, 3
sw t0, 40(s0)
cleanup:
sw zero, 60(s0)
move a0, s2
{oscall(FREE)}
b uninitialize
nop
allocation_failed:
addiu t0, zero, 2
sw t0, 40(s0)
uninitialize:
{oscall(CO_UNINIT)}
b result
nop
com_failed:
addiu t0, zero, 1
sw t0, 40(s0)
result:
lw v0, 40(s0)
b done
nop
refused:
addiu v0, zero, 4
done:
{end(0x30,['s0','s1','s2'])}
'''


def clear():
    # GUI thread only. Bitmap is always unselected when stored in DISPLAY.
    return f'''
{frame(0x20,[])}
la t0, {hex(DISPLAY)}
lw a0, 0(t0)
sw zero, 0(t0)
sw zero, 4(t0)
sw zero, 8(t0)
beqz a0, done
nop
jal {hex(image.DELETE_OBJECT)}
nop
addiu v0, zero, 1
b finish
nop
done:
move v0, zero
finish:
{end(0x20,[])}
'''


def take():
    # GUI thread only. Return 1 if the displayed handle changed (including clear).
    # Timer/wakeup binding must repaint then. Freshness is also required at paint.
    return f'''
{frame(0x40,['s0','s1','s2','s3','s4','s5','s6'])}
la s0, {hex(STATE)}
move s6, zero
lw t0, 20(s0)
beqz t0, slot
nop
lw t0, 12(s0)
addiu t1, zero, 1
bne t0, t1, clear_old
nop
{oscall(CLOCK)}
la a0, {hex(CONFIG.state)}
lw a1, 24(s0)
move a2, v0
lw a3, 28(s0)
jal {hex(entry('fresh'))}
nop
bnez v0, slot
nop
clear_old:
jal {hex(CLEAR)}
nop
move s6, v0
slot:
la a0, {hex(PENDING)}
move a1, zero
{transfer.api(CONFIG,'exchange')}
move s1, v0
beqz s1, result
nop
lw s2, 0(s1)
lw s3, 4(s1)
lw s4, 8(s1)
lw s5, 12(s1)
move a0, s1
{oscall(FREE)}
beqz s4, result
nop
lw t0, 12(s0)
addiu t1, zero, 1
bne t0, t1, reject
nop
lw t0, 44(s0)
bne t0, s5, reject
nop
{oscall(CLOCK)}
la a0, {hex(CONFIG.state)}
move a1, s2
move a2, v0
move a3, s3
jal {hex(entry('fresh'))}
nop
beqz v0, reject
nop
jal {hex(CLEAR)}
nop
sw s4, 20(s0)
sw s2, 24(s0)
sw s3, 28(s0)
addiu s6, zero, 1
b result
nop
reject:
jal {hex(image.DELETE_OBJECT)}
move a0, s4
result:
move v0, s6
{end(0x40,['s0','s1','s2','s3','s4','s5','s6'])}
'''


def assembled():
    rows=image.assembled()+transfer.assembled('AppMain.exe')
    for name,at,capacity,source in (('app_image_thread',THREAD,0x1000,thread()),
                                  ('app_image_step',STEP,0x2000,step()),
                                  ('app_image_take',TAKE,0x800,take()),('app_image_clear',CLEAR,0x400,clear())):
        raw,recipe,relocations=assemble(source,at,capacity)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    ordered=sorted(rows,key=lambda r:r['address'])
    assert all(a['address']+len(a['raw'])<=b['address'] for a,b in zip(ordered,ordered[1:])), 'Overlapping helpers'
    return rows


def contracts(raw):
    if hashlib.sha256(raw).hexdigest()!=CONFIG.sha256:raise ValueError('Expected exact retained MAX05 AppMain.exe')
    pe=pefile.PE(data=raw)
    imports={i.address:(d.dll.lower(),i) for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
    rows=[]
    for at,ordinal in ((MALLOC,1041),(FREE,1018),(CLOCK,535),(POST_MESSAGE,865)):
        dll,i=imports[at];assert dll==b'coredll.dll' and i.ordinal==ordinal
        rows.append(dict(iat=hex(at),ordinal=ordinal))
    for at,name in ((CO_INIT,b'CoInitializeEx'),(CO_UNINIT,b'CoUninitialize')):
        dll,i=imports[at];assert dll==b'ole32.dll' and i.name==name
        rows.append(dict(iat=hex(at),name=name.decode('ascii')))
    return dict(appmain_sha256=CONFIG.sha256,imports=rows,transfer=transfer.contracts('AppMain.exe',raw),
                image=image.contracts(raw),worker_period_ms=PERIOD,encoded_capacity=image.MAX_IMAGE,
                pending_results=1,displayed_bitmaps=1)
