"""Bounded delayed recovery for failed/empty current-track text replies.

Two retries (500 ms, then 1500 ms) after native final drain. Internal requests
retain their retry budget and do not restart artwork selection. Queued request
identity survives cancellation until the profile consumes it. CSR segment zero
only; no native pending allocation is freed by these helpers.
"""
import hashlib
import struct
import pefile
from patch_bt_cover_attribute import BASE_SHA
import bt_text_metadata_owner as owner
import bt_text_metadata_receive as receive
import bt_text_metadata_disconnect as disconnect
import bt_text_metadata_shutdown as shutdown
import bt_cover_art_selection as selection
import bt_cover_art_timers as timers
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

CAPTURE,CHECK,ARM,WAKE,PROFILE,FINAL,STOP,DISCONNECT,DROP=(
    0x28bc00,0x28c400,0x28cc00,0x28d400,0x28e000,0x28e800,0x28ec00,0x28f000,0x28f400)
STATE,SIZE,MAX_RETRIES=0x294500,40,2
# current generation0, reserved4, attempts8, timer12, token16,
# queued request20, queued birth generation24, reserved28..39.


def stop():return f'''
{frame(0x18,[])}
la t0, {hex(STATE)}
sw zero, 0(t0)
lw a0, 12(t0)
sw zero, 12(t0)
beqz a0, done
nop
move a1, zero
move a2, zero
jal {hex(timers.CANCEL_TIMER)}
nop
done:
move v0, zero
{end(0x18,[])}
'''


def check():return f'''
{frame(0x20,['s0','s1'])}
move s0, a0
move s1, a1
beqz s0, no
nop
jal {hex(timers.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, no
nop
la t0, {hex(STATE)}
lw t1, 0(t0)
bne t1, s0, no
nop
lw t1, 20(t0)
bne t1, s1, no
nop
la t0, {hex(owner.STATE)}
lw t1, 0(t0)
bne t1, s0, no
nop
lw t1, 4(t0)
bnez t1, no
nop
addiu a0, t0, 16
lw a1, 12(t0)
lw a2, 8(t0)
jal {hex(owner.FRESH)}
nop
beqz v0, no
nop
la t0, {hex(owner.ROOT_POINTER)}
lw t0, 0(t0)
lw v0, 0x26c(t0)
# Same native metadata-request gate as notification handler 200c0.
lbu t0, 0x20c(v0)
bnez t0, done
nop
no:
move v0, zero
done:
{end(0x20,['s0','s1'])}
'''


def capture():return f'''
{frame(0x30,['s0','s1','s2','s3'])}
addiu s0, a2, -6
la t0, {hex(owner.STATE)}
lw s1, 0(t0)
jal {hex(owner.CAPTURE)}
nop
move s2, v0
la t0, {hex(owner.STATE)}
lw s3, 0(t0)
addiu t1, zero, -1
beq s3, t1, exhausted
nop
beq s3, s1, done
nop
la t0, {hex(STATE)}
lw t1, 20(t0)
beq t1, s0, internal
nop
jal {hex(STOP)}
nop
la t0, {hex(STATE)}
sw zero, 8(t0)
internal:
sw s3, 0(t0)
b done
nop
exhausted:
jal {hex(STOP)}
nop
done:
move v0, s2
{end(0x30,['s0','s1','s2','s3'])}
'''


def arm():return f'''
{frame(0x30,['s0','s1'])}
move s0, a0
move a1, zero
jal {hex(CHECK)}
nop
beqz v0, no
nop
move s1, v0
la t0, {hex(STATE)}
lw t1, 12(t0)
bnez t1, no
nop
lw t1, 8(t0)
sltiu t1, t1, {MAX_RETRIES}
beqz t1, no
nop
la t0, {hex(receive.STATE)}
lw t1, 20(t0)
beq t1, s0, eligible
nop
lw t1, 16(t0)
bne t1, s0, no
nop
lbu t1, 0xee(s1)
bnez t1, no
nop
eligible:
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
lw t1, 16(t0)
ori t2, zero, 0xffff
sltu t2, t1, t2
beqz t2, no
nop
addiu a2, t1, 1
sw a2, 16(t0)
la a0, 500000
lw t1, 8(t0)
beqz t1, set
nop
la a0, 1500000
set:
la a1, {hex(WAKE)}
la a3, {hex(STATE)}
jal {hex(timers.SET_TIMER)}
nop
beqz v0, no
nop
la t0, {hex(STATE)}
sw v0, 12(t0)
addiu v0, zero, 1
b done
nop
no:
move v0, zero
done:
{end(0x30,['s0','s1'])}
'''


def wake():return f'''
{frame(0x40,['s0','s1','s2','s3'])}
move s0, a0
la t0, {hex(STATE)}
bne a1, t0, done
nop
jal {hex(timers.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, done
nop
la t0, {hex(STATE)}
lw t1, 16(t0)
bne t1, s0, done
nop
lw t1, 12(t0)
beqz t1, done
nop
sw zero, 12(t0)
lw s1, 0(t0)
move a0, s1
move a1, zero
jal {hex(CHECK)}
nop
beqz v0, cancel
nop
move s2, v0
la t0, {hex(selection.PROFILE_QUEUE)}
lhu t0, 0(t0)
sltiu t0, t0, 0x800
beqz t0, cancel
nop
la t0, {hex(STATE)}
lw t1, 8(t0)
sltiu t2, t1, {MAX_RETRIES}
beqz t2, done
nop
addiu t1, t1, 1
sw t1, 8(t0)
jal 0x85b70
addiu a0, zero, 20
beqz v0, retry_allocation
nop
move s3, v0
sw zero, 0(s3)
sw zero, 4(s3)
sw zero, 8(s3)
sw zero, 12(s3)
sw zero, 16(s3)
addiu t0, zero, 0x20c
sh t0, 0(s3)
la t0, {hex(owner.STATE)}
lw t1, 8(t0)
sh t1, 2(s3)
lw t1, 12(t0)
sb t1, 4(s3)
addiu t1, zero, 3
sb t1, 5(s3)
addiu t0, t0, 16
addiu t1, s3, 6
addiu t2, zero, 8
uid:
lbu t3, 0(t0)
sb t3, 0(t1)
addiu t0, t0, 1
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, uid
nop
lhu t0, 0x246(s2)
sh t0, 14(s3)
addiu t0, zero, 127
sw t0, 16(s3)
la t0, {hex(STATE)}
sw s3, 20(t0)
sw s1, 24(t0)
move a0, s3
jal 0x78bd4
nop
b done
nop
retry_allocation:
move a0, s1
jal {hex(ARM)}
nop
b done
nop
cancel:
jal {hex(STOP)}
nop
done:
move v0, zero
{end(0x40,['s0','s1','s2','s3'])}
'''


def profile():return f'''
{frame(0x40,['s0','s1','s2','s3'])}
move s0, a0
lw s1, 12(s0)
la t0, {hex(STATE)}
lw t1, 20(t0)
bne t1, s1, external
nop
move s2, zero
lw a0, 24(t0)
move a1, s1
jal {hex(CHECK)}
nop
beqz v0, retire
nop
addiu a0, s0, 0x7c
addiu a1, zero, 0x10
lbu a2, 4(s1)
jal 0x8186c
nop
beqz v0, retire
nop
lbu t0, 0x1e(v0)
addiu t1, zero, 3
bne t0, t1, retire
nop
# Internal retry retains artwork selection; only ordinary metadata is repeated.
move a0, s0
jal {hex(selection.ORIGINAL_REQUEST)}
nop
move s2, v0
retire:
la t0, {hex(STATE)}
sw zero, 20(t0)
sw zero, 24(t0)
la t0, {hex(owner.STATE)}
lw a0, 0(t0)
jal {hex(ARM)}
nop
move v0, s2
b done
nop
external:
move a0, s0
jal {hex(selection.REQUEST)}
nop
done:
{end(0x40,['s0','s1','s2','s3'])}
'''


def final():return f'''
{frame(0x30,['s0','s1','s2'])}
move s0, zero
la t0, {hex(owner.STATE)}
lw t1, 4(t0)
bne t1, a2, invoke
nop
lw s0, 0(t0)
invoke:
jal {hex(receive.FINAL)}
nop
move s1, v0
beqz s0, done
nop
move a0, s0
jal {hex(ARM)}
nop
done:
move v0, s1
{end(0x30,['s0','s1','s2'])}
'''


def disconnected():return f'''
{frame(0x20,['s0'])}
jal {hex(disconnect.LOOKUP)}
nop
move s0, v0
beqz s0, done
nop
la t0, {hex(owner.STATE)}
lw t0, 12(t0)
lbu t1, 0x10(s0)
bne t0, t1, done
nop
jal {hex(STOP)}
nop
done:
move v0, s0
{end(0x20,['s0'])}
'''


def drop():return f'''
{frame(0x20,['s0','s1'])}
move s0, a0
jal {hex(STOP)}
nop
move a0, s0
jal {hex(shutdown.DROP)}
nop
move s1, v0
la t0, {hex(STATE)}
sw zero, 20(t0)
sw zero, 24(t0)
move v0, s1
{end(0x20,['s0','s1'])}
'''


def assembled():
    rows=[]
    for name,at,n,fn in (('retry_capture',CAPTURE,0x600,capture),('retry_check',CHECK,0x600,check),
                         ('retry_arm',ARM,0x800,arm),('retry_wakeup',WAKE,0xc00,wake),
                         ('retry_profile',PROFILE,0x800,profile),('retry_final',FINAL,0x400,final),
                         ('retry_stop',STOP,0x400,stop),('retry_disconnect',DISCONNECT,0x400,disconnected),
                         ('retry_profile_shutdown',DROP,0x400,drop)):
        raw,recipe,relocations=assemble(fn(),at,n)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    return rows


def sites(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    p=pefile.PE(data=raw)
    assert p.get_data(selection.REQUEST_TABLE-p.OPTIONAL_HEADER.ImageBase,4)==struct.pack('<I',selection.ORIGINAL_REQUEST)
    result=receive.sites(raw)|disconnect.sites(raw)|shutdown.sites(raw)
    result[0x5374c]=(3<<26)|(CAPTURE>>2)
    result[receive.FINAL_SITE]=(3<<26)|(FINAL>>2)
    result[disconnect.SITE]=(3<<26)|(DISCONNECT>>2)
    result[selection.REQUEST_TABLE]=PROFILE
    result[selection.DROP_HIGH]=0x3c0a0000|((DROP+0x8000)>>16)
    result[selection.DROP_LOW]=0x25460000|(DROP&65535)
    return result
