"""Bluetooth dialog artwork overlay using retained native draw and repaint paths.

Requires the worker's live-window state. Native startup, timer creation and
shutdown remain external bindings. This module writes no executable.
"""
import hashlib
import struct

import pefile

import bt_cover_art_image as image
import bt_cover_art_worker as worker
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

DRAW,REFRESH,WND=0x235000,0x236000,0x236800
LEGACY_DRAW,LEGACY_WND,BLIT=0x134e1c,0x3c904,0x13d220
BT_GLOBAL,VTABLE_SLOT=0x188270,0x150c44
STRETCH=0x185250
TIMER=0x4d42
RECT=(24,116,128,128)


def current():
    return f'''
{worker.oscall(worker.CLOCK)}
la a0, {hex(worker.CONFIG.state)}
lw a1, 24(s0)
move a2, v0
lw a3, 28(s0)
jal {hex(worker.entry('fresh'))}
nop
'''


def draw():
    # Preserve the original virtual function's result. Paint only after its
    # background/children pass, never above the original popup child hierarchy.
    return f'''
{frame(0x60,['s0','s1','s2','s3','s4','s5','s6','s7'])}
move s1, a0
jal {hex(LEGACY_DRAW)}
nop
move s7, v0
la s0, {hex(worker.STATE)}
lw t0, 64(s0)
bne t0, s1, done
nop
lw t0, 12(s0)
addiu t1, zero, 1
bne t0, t1, done
nop
lw t0, 0x50(s1)
lw t1, 0(s0)
beqz t0, done
nop
bne t0, t1, done
nop
lw t0, 0x78(s1)
bnez t0, done
nop
lw s2, 0x28(s1)
beqz s2, done
nop
lw s3, 20(s0)
beqz s3, done
nop
{current()}
beqz v0, stale
nop
jal {hex(image.CREATE_DC)}
move a0, zero
move s4, v0
beqz s4, done
nop
move a0, s4
jal {hex(image.SELECT)}
move a1, s3
move s5, v0
beqz s5, delete_dc
nop
addiu t0, zero, -1
beq s5, t0, delete_dc
nop
move s6, zero
{current()}
beqz v0, restore
nop
addiu a0, s2, 0
addiu a1, zero, {RECT[0]}
addiu a2, zero, {RECT[1]}
addiu a3, zero, {RECT[2]}
addiu t0, zero, {RECT[3]}
sw t0, 0x10(sp)
sw s4, 0x14(sp)
sw zero, 0x18(sp)
sw zero, 0x1c(sp)
addiu t0, zero, 200
sw t0, 0x20(sp)
sw t0, 0x24(sp)
la t0, 0xcc0020
sw t0, 0x28(sp)
{worker.oscall(STRETCH)}
move s6, v0
restore:
move a0, s4
jal {hex(image.SELECT)}
move a1, s5
# Deleting this private DC releases its selection even if restoration failed.
# Valid-object DC destruction is the retained GDI contract, as for the decoder.
move a0, s4
jal {hex(image.DELETE_DC)}
nop
{current()}
beqz v0, stale
nop
bnez s6, done
nop
# A failed blit may have changed part of the cached rectangle. Restore the
# normal background/children pass rather than keeping a partial cover.
jal {hex(LEGACY_DRAW)}
move a0, s1
b done
nop
delete_dc:
jal {hex(image.DELETE_DC)}
move a0, s4
b done
nop
stale:
jal {hex(worker.CLEAR)}
nop
# If invalidation happened during StretchBlt, remove that cached image before
# the caller copies this buffer to the screen.
jal {hex(LEGACY_DRAW)}
move a0, s1
done:
move v0, s7
{end(0x60,['s0','s1','s2','s3','s4','s5','s6','s7'])}
'''


def refresh():
    # GUI only, on pointer-free result wakeup or the future private timer.
    return f'''
{frame(0x38,['s0','s1'])}
jal {hex(worker.TAKE)}
nop
move s1, v0
beqz s1, done
nop
la t0, {hex(worker.STATE)}
lw s0, 64(t0)
beqz s0, done
nop
jal {hex(DRAW)}
move a0, s0
addiu t0, zero, {RECT[0]}
sw t0, 0x10(sp)
addiu t0, zero, {RECT[1]}
sw t0, 0x14(sp)
addiu t0, zero, {RECT[2]}
sw t0, 0x18(sp)
addiu t0, zero, {RECT[3]}
sw t0, 0x1c(sp)
addiu a0, s0, 4
addiu a1, sp, 0x10
jal {hex(BLIT)}
addiu a2, zero, 1
done:
move v0, s1
{end(0x38,['s0','s1'])}
'''


def wnd():
    return f'''
{frame(0x30,['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
la t0, {hex(worker.STATE)}
lw t1, 0(t0)
bne t1, s0, legacy
nop
beqz s0, legacy
nop
ori t1, zero, {worker.MESSAGE}
bne s1, t1, timer
nop
bnez s2, legacy
nop
bnez s3, legacy
nop
b refresh
nop
timer:
addiu t1, zero, 0x113
bne s1, t1, paint
nop
ori t1, zero, {TIMER}
bne s2, t1, legacy
nop
refresh:
jal {hex(REFRESH)}
nop
move v0, zero
b done
nop
paint:
addiu t1, zero, 15
bne s1, t1, legacy
nop
la t0, {hex(worker.STATE)}
lw a0, 64(t0)
beqz a0, legacy
nop
jal {hex(DRAW)}
nop
legacy:
move a0, s0
move a1, s1
move a2, s2
jal {hex(LEGACY_WND)}
move a3, s3
done:
{end(0x30,['s0','s1','s2','s3'])}
'''


def assembled():
    rows=worker.assembled()
    for name,at,cap,source in (('app_image_draw',DRAW,0x1000,draw()),
                               ('app_image_refresh',REFRESH,0x800,refresh()),
                               ('app_image_window',WND,0x800,wnd())):
        raw,recipe,relocations=assemble(source,at,cap)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    ordered=sorted(rows,key=lambda r:r['address'])
    assert all(a['address']+len(a['raw'])<=b['address'] for a,b in zip(ordered,ordered[1:]))
    return rows


def contracts(raw):
    contract=worker.contracts(raw)
    pe=pefile.PE(data=raw)
    def read(at,n):return pe.get_data(at-pe.OPTIONAL_HEADER.ImageBase,n)
    assert struct.unpack('<I',read(VTABLE_SLOT,4))[0]==LEGACY_DRAW
    assert struct.unpack('<I',read(0x3c81c,4))[0]==0x3c080004
    assert struct.unpack('<I',read(0x3c824,4))[0]==0x2506c904
    imports={i.address:(d.dll.lower(),i) for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
    dll,i=imports[STRETCH];assert dll==b'coredll.dll' and i.ordinal==905
    return dict(worker=contract,dialog_global=hex(BT_GLOBAL),vtable_slot=hex(VTABLE_SLOT),
                rectangle=dict(zip(('x','y','width','height'),RECT)),stretch_iat=hex(STRETCH),stretch_ordinal=905,
                retained={hex(at):dict(bytes=n,sha256=hashlib.sha256(read(at,n)).hexdigest())
                          for at,n in ((LEGACY_DRAW,0x64),(LEGACY_WND,0x30),(BLIT,0xcc),(0x134d28,0xf4))},
                registration=[dict(address=hex(at),before=read(at,4).hex()) for at in (0x3c81c,0x3c824)],
                existing_controls_moved=0,dialog_size_changed=False,private_timer=hex(TIMER))
