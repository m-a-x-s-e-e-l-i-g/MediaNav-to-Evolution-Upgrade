"""Native artwork metadata request, fragmented replies and owned task cleanup.

Composes the controller, timers and exact request/confirmation identity bridge.
Original AVRCP parsing and continuation constructors remain in use. A bounded
256-byte assembly buffer accepts only the requested attribute-8 response, then
hands it to the controller's strict attribute parser. No PE/LGU is written.
Selected-peer discovery, GUI publication and executable placement remain open.
All profile/task callbacks must serialize in CSR segment zero; no reentrancy.
"""
import hashlib
import struct

import pefile

import bt_cover_art_controller as controller
import bt_cover_art_metadata_ticket as ticket
import bt_cover_art_task as task
import bt_cover_art_timers as timers
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

RESPONSE, INTERIM_POST, APPEND = 0x262000, 0x262400, 0x262800
SET_PEER, REQUEST, RECEIVE = 0x263000, 0x263400, 0x263800
RESET, SHUTDOWN = 0x264400, 0x264600
HANDLE = 0x265800
RESPONSE_SITE, POST_SITE = 0x712a0, 0x52b68
ORIGINAL_RESPONSE, ORIGINAL_POST, CONTENT_FREE = 0x708cc, 0x56ad4, 0x78a0c
# Extend the ticket slot, without changing its existing 32-byte ABI.
# phase32,count36,used40,frames44,interim48,current_parent52,owner56,peer60.
# peer is 0x100 | peer_id; zero means no selected-peer binding.
BUFFER, CAPACITY, STATIC_SIZE = ticket.SLOT+64, 256, 320
REGS = ['s0', 's1', 's2', 's3']

RESPONSE_CODE = f'''
{frame(0x30, REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
jal {hex(ticket.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, invoke
nop
la t0, {hex(ticket.SLOT)}
lw t1, 16(t0)
addiu t2, zero, 2
bne t1, t2, invoke
nop
lw t1, 0x10(s1)
lw t2, 4(t0)
bne t1, t2, invoke
nop
# Parent confirmation identity exists only during this synchronous parser call.
sw t1, 52(t0)
# Guard only the exact artwork response before the original parser allocates or
# reads count byte 13. The native parser reads that byte for single/start frames
# even when length is exactly 13; legacy metadata remains byte-for-byte intact.
sltiu t0, s2, 13
bnez t0, invoke
nop
beqz s3, bad_length
nop
addu t0, s3, s2
sltu t0, t0, s3
bnez t0, bad_length
nop
sltiu t0, s2, {CAPACITY+14}
beqz t0, bad_length
nop
addiu t0, zero, 13
bne s2, t0, invoke
nop
lbu t0, 10(s3)
andi t0, t0, 3
sltiu t0, t0, 2
beqz t0, invoke
nop
bad_length:
# Reuse the original short-response error/final-post path (no payload access).
addiu s2, zero, 12
invoke:
move a0, s0
move a1, s1
move a2, s2
move a3, s3
jal {hex(ORIGINAL_RESPONSE)}
nop
la t0, {hex(ticket.SLOT)}
sw zero, 52(t0)
{end(0x30, REGS)}
'''

INTERIM_CODE = f'''
{frame(0x20, ['s0', 's1'])}
move s0, a0
move s1, a1
la t0, {hex(ticket.SLOT)}
lw t1, 52(t0)
beqz t1, post
nop
lw t2, 4(t0)
bne t1, t2, post
nop
la t1, {hex(task.QUEUE)}
lhu t1, 0(t1)
bne t1, s0, post
nop
lw t1, 48(t0)
bnez t1, duplicate
nop
sw s1, 48(t0)
b post
nop
duplicate:
# Retain the first identity, fail closed, and let the native final reply drain.
sw zero, 28(t0)
post:
move a0, s0
move a1, s1
jal {hex(ORIGINAL_POST)}
nop
{end(0x20, ['s0', 's1'])}
'''

RESET_CODE = f'''
la t0, {hex(ticket.SLOT+32)}
la t1, {hex(ticket.SLOT+52)}
reset:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, reset
nop
la t0, {hex(BUFFER)}
la t1, {hex(BUFFER+CAPACITY)}
buffer:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, buffer
nop
addiu v0, zero, 1
jr ra
nop
'''

SET_PEER_CODE = f'''
{frame(0x20, ['s0', 's1'])}
move s0, a0
move s1, a1
sltiu t0, s1, 256
beqz t0, refused
nop
jal {hex(timers.CONTEXT)}
nop
beqz v0, refused
nop
la t0, {hex(ticket.SLOT)}
ori s1, s1, 0x100
lw t1, 16(t0)
beqz t1, bind
nop
lw t1, 56(t0)
bne t1, s0, refused
nop
lw t1, 60(t0)
bne t1, s1, refused
nop
bind:
sw s0, 56(t0)
sw s1, 60(t0)
addiu v0, zero, 1
b done
nop
refused:
move v0, zero
done:
{end(0x20, ['s0', 's1'])}
'''

REQUEST_CODE = f'''
{frame(0x30, REGS)}
move s0, a0
move s1, a1
move s2, a2
jal {hex(timers.CONTEXT)}
nop
beqz v0, refused
nop
la t0, {hex(ticket.SLOT)}
lw t1, 16(t0)
bnez t1, refused
nop
lw t1, 56(t0)
bne t1, s0, refused
nop
lw t1, 60(t0)
andi t1, t1, 0x100
beqz t1, refused
nop
lw t1, {controller.OFFSET}(s0)
addiu t2, zero, {controller.META}
bne t1, t2, refused
nop
lw t1, 0(s0)
addiu t2, zero, {controller.owner.ACTIVE}
bne t1, t2, refused
nop
lw t1, {controller.OFFSET+8}(s0)
bne t1, s1, refused
nop
lw t1, {controller.OFFSET+12}(s0)
bne t1, s2, refused
nop
addiu a0, zero, 20
jal {hex(controller.MALLOC)}
nop
beqz v0, refused
nop
move s3, v0
sw zero, 0(s3)
sw zero, 4(s3)
sw zero, 8(s3)
sw zero, 12(s3)
sw zero, 16(s3)
addiu t0, zero, 0x20c
sh t0, 0(s3)
lhu t0, 22(s0)
sh t0, 2(s3)
la t0, {hex(ticket.SLOT)}
lw t0, 60(t0)
sb t0, 4(s3)
addiu t0, zero, 3
sb t0, 5(s3)
addiu t0, zero, 128
sw t0, 16(s3)
jal {hex(RESET)}
nop
move a0, s3
move a1, s1
move a2, s2
jal {hex(ticket.BEGIN)}
nop
beqz v0, release
nop
move a0, s3
jal 0x78bd4
nop
addiu v0, zero, 1
b done
nop
release:
move a0, s3
jal 0x85bb8
nop
refused:
move v0, zero
done:
{end(0x30, REGS)}
'''

# APPEND(msg,is_final) validates all headers and limits before copying anything.
# The final controller parser rejects duplicate/malformed attributes and handles.
APPEND_CODE = f'''
{frame(0x30, REGS)}
move s0, a0
move s1, a1
la s3, {hex(ticket.SLOT)}
lbu t0, 2(s0)
lw t1, 20(s3)
bne t0, t1, refused
nop
lbu t0, 3(s0)
addiu t1, zero, 3
bne t0, t1, refused
nop
beqz s1, interim
nop
lhu t0, 20(s0)
ori t1, zero, 0x8000
bne t0, t1, refused
nop
lhu t0, 22(s0)
addiu t1, zero, 0x11
bne t0, t1, refused
nop
lhu t3, 24(s0)
b payload
nop
interim:
lhu t3, 20(s0)
payload:
lw s2, 16(s0)
beqz s2, refused
nop
lhu t2, 14(s0)
sltiu t0, t2, 13
bnez t0, refused
nop
addu t0, s2, t2
sltu t0, t0, s2
bnez t0, refused
nop
lbu t0, 9(s2)
addiu t1, zero, 0x20
bne t0, t1, refused
nop
lbu t0, 11(s2)
lbu t1, 12(s2)
sll t0, t0, 8
or t0, t0, t1
addiu t0, t0, 13
bne t0, t2, refused
nop
lbu t0, 10(s2)
andi t0, t0, 3
beqz s1, nonfinal
nop
beqz t0, first
nop
addiu t1, zero, 3
bne t0, t1, refused
nop
b later
nop
nonfinal:
addiu t1, zero, 1
beq t0, t1, first
nop
addiu t1, zero, 2
bne t0, t1, refused
nop
b later
nop
first:
lw t0, 32(s3)
bnez t0, refused
nop
addiu t0, zero, 14
bne t3, t0, refused
nop
sltiu t0, t2, 14
bnez t0, refused
nop
lbu t0, 13(s2)
lbu t1, 12(s0)
bne t0, t1, refused
nop
sltiu t1, t0, 2
beqz t1, refused
nop
sw t0, 0x10(sp)
b bounds
nop
later:
lw t0, 32(s3)
addiu t1, zero, 1
bne t0, t1, refused
nop
addiu t0, zero, 13
bne t3, t0, refused
nop
lbu t0, 12(s0)
lw t1, 36(s3)
bne t0, t1, refused
nop
sw t0, 0x10(sp)
bounds:
lw t0, 44(s3)
sltiu t1, t0, 32
beqz t1, refused
nop
subu t2, t2, t3
lw t1, 40(s3)
addu t0, t1, t2
sltiu t0, t0, {CAPACITY}
beqz t0, refused
nop
# All checks finished. Commit count and append only the attribute bytes.
lw t0, 0x10(sp)
sw t0, 36(s3)
la t0, {hex(BUFFER)}
lw t3, 0x10(sp)
sb t3, 0(t0)
addiu t0, t0, 1
addu t0, t0, t1
lhu t3, 20(s0)
beqz s1, offset
nop
lhu t3, 24(s0)
offset:
addu s2, s2, t3
addu t3, t1, t2
sw t3, 40(s3)
beqz t2, committed
nop
copy:
lbu t3, 0(s2)
sb t3, 0(t0)
addiu s2, s2, 1
addiu t0, t0, 1
addiu t2, t2, -1
bnez t2, copy
nop
committed:
lw t0, 44(s3)
addiu t0, t0, 1
sw t0, 44(s3)
addiu t0, s1, 1
sw t0, 32(s3)
addiu v0, zero, 1
b done
nop
refused:
move v0, zero
done:
{end(0x30, REGS)}
'''

RECEIVE_CODE = f'''
{frame(0x40, REGS)}
move s0, a0
move s1, a1
move a0, s0
jal {hex(timers.CONTEXT)}
nop
beqz v0, done
nop
la s2, {hex(ticket.SLOT)}
lhu t0, 0(s1)
ori t1, zero, 0x8224
beq t0, t1, interim
nop
ori t1, zero, 0x820d
bne t0, t1, done
nop
lw t0, 4(s2)
bne t0, s1, done
nop
lw t0, 28(s2)
beqz t0, drain_final
nop
move a0, s1
addiu a1, zero, 1
jal {hex(APPEND)}
nop
bnez v0, drain_final
nop
jal {hex(ticket.INVALIDATE)}
nop
move a0, s0
jal {hex(controller.CANCEL)}
nop
drain_final:
move a0, s1
addiu a1, sp, 0x18
jal {hex(ticket.TAKE)}
nop
addiu t0, zero, 1
bne v0, t0, done
nop
lw t0, 40(s2)
addiu t0, t0, 1
sw t0, 0x10(sp)
move a0, s0
lw a1, 0x18(sp)
lw a2, 0x1c(sp)
la a3, {hex(BUFFER)}
jal {hex(controller.METADATA)}
nop
b done
nop
interim:
lw t0, 48(s2)
bne t0, s1, done
nop
sw zero, 48(s2)
move s3, zero
lw t0, 28(s2)
beqz t0, acknowledge
nop
move a0, s1
move a1, zero
jal {hex(APPEND)}
nop
move s3, v0
bnez v0, acknowledge
nop
jal {hex(ticket.INVALIDATE)}
nop
move a0, s0
jal {hex(controller.CANCEL)}
nop
acknowledge:
addiu a0, zero, 4
jal {hex(controller.MALLOC)}
nop
beqz v0, ack_failed
nop
sw zero, 0(v0)
addiu t0, zero, 0x20d
sh t0, 0(v0)
lw t0, 20(s2)
sb t0, 2(v0)
sb s3, 3(v0)
move a0, v0
jal 0x78bd4
nop
b done
nop
ack_failed:
jal {hex(ticket.INVALIDATE)}
nop
move a0, s0
jal {hex(controller.CANCEL)}
nop
done:
move v0, zero
{end(0x40, REGS)}
'''

# Quiescent drain: no continuation ACK or new request may post during shutdown.
SHUTDOWN_CODE = f'''
{frame(0x20, ['s0'])}
move s0, a0
jal {hex(ticket.INVALIDATE)}
nop
move a0, s0
move a1, zero
jal {hex(ticket.TAKE)}
nop
la t0, {hex(ticket.SLOT)}
lw t1, 48(t0)
bne t1, s0, done
nop
sw zero, 48(t0)
done:
move v0, zero
{end(0x20, ['s0'])}
'''


def assembled():
    rows = timers.assembled()+ticket.assembled()
    rows = [r for r in rows if r['address'] not in (controller.DISPOSE, task.HANDLE, task.DEINIT)]
    dispose = controller.DISPOSE_CODE.replace('addiu s1, s0,',
        f'jal {hex(ticket.INVALIDATE)}\nnop\nmove a0, s0\njal {hex(timers.STOP_TIMER)}\nnop\naddiu s1, s0,', 1)
    handle = task.HANDLE_CODE.replace('lw s0, 0(a0)',
        f'lw s0, 0(a0)\nmove a0, s0\njal {hex(timers.PUMP)}\nnop', 1)
    handle = handle.replace('beqz s0, dispatch', '''addiu t0, zero, 0x11b
beq s2, t0, metadata
nop
beqz s0, dispatch''', 1)
    handle = handle.replace('done:\nmove v0, zero', f'''b done
nop
metadata:
move a0, s0
move a1, s1
jal {hex(RECEIVE)}
nop
addiu a0, zero, 0x11b
move a1, s1
jal {hex(CONTENT_FREE)}
nop
move a0, s1
jal 0x85bb8
nop
done:
move a0, s0
jal {hex(timers.PUMP)}
nop
move v0, zero''')
    deinit = task.DEINIT_CODE.replace('bne a0, t0, envelope', '''addiu t1, zero, 0x11b
beq a0, t1, metadata
nop
bne a0, t0, envelope''', 1)
    deinit = deinit.replace('envelope:\n', f'''b envelope
nop
metadata:
move a0, s1
jal {hex(SHUTDOWN)}
nop
addiu a0, zero, 0x11b
move a1, s1
jal {hex(CONTENT_FREE)}
nop
envelope:
''', 1)
    deinit = deinit.replace('drained:\n', f'''drained:
lw a0, 0(s0)
jal {hex(controller.DISPOSE)}
nop
# A pending result identity is retained, but no freed owner pointer is retained.
la t0, {hex(ticket.SLOT)}
sw zero, 56(t0)
sw zero, 60(t0)
''', 1)
    specs = [
        (RESPONSE, 0x400, RESPONSE_CODE, 'Bind original parser callbacks to the exact retained parent confirmation'),
        (INTERIM_POST, 0x400, INTERIM_CODE, 'Capture actual continuation allocation before native result posting'),
        (APPEND, 0x800, APPEND_CODE, 'Validate fragment layout and commit at most 255 attribute bytes in 32 replies'),
        (SET_PEER, 0x400, SET_PEER_CODE, 'Bind an explicitly selected peer in the owning queue; refuse pending-peer replacement'),
        (REQUEST, 0x400, REQUEST_CODE, 'Allocate and arm attribute-8-only request before native profile posting'),
        (RECEIVE, 0xc00, RECEIVE_CODE, 'Handle native continuation ACKs and final metadata controller delivery'),
        (RESET, 0x200, RESET_CODE, 'Reset bounded assembly only before a new request is armed'),
        (SHUTDOWN, 0x200, SHUTDOWN_CODE, 'Drain exact result identities without posting during global shutdown'),
        (controller.REQUEST_METADATA, 0x100, f'la t9, {hex(REQUEST)}\njr t9\nnop', 'Bind controller request callback to native metadata allocation/post'),
        (controller.DISPOSE, 0x1000, dispose, 'Invalidate pending metadata before cancelling timer and releasing image'),
        (HANDLE, 0x800, handle, 'Owning task dispatch including metadata content and envelope cleanup'),
        (task.HANDLE, 0x400, f'la t9, {hex(HANDLE)}\njr t9\nnop', 'Task handler forwards to extended metadata-aware dispatch'),
        (task.DEINIT, 0x400, deinit, 'Quiescent metadata drain, native content cleanup and owner release')]
    for at, capacity, code, purpose in specs:
        raw, recipe, relocations = assemble(code, at, capacity)
        rows.append(dict(address=at, raw=raw, recipe=recipe, relocations=relocations, purpose=purpose))
    return rows


def sites(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    pe = pefile.PE(data=raw)
    result = {ticket.SITE: ticket.site_word(raw)}
    for at, original, replacement, delay in (
        (RESPONSE_SITE, ORIGINAL_RESPONSE, RESPONSE, 0x02602025),
        (POST_SITE, ORIGINAL_POST, INTERIM_POST, 0x02402825)):
        assert pe.get_data(at-pe.OPTIONAL_HEADER.ImageBase, 8) == struct.pack('<II', (3<<26)|(original>>2), delay)
        result[at] = (3<<26)|(replacement>>2)
    return result
