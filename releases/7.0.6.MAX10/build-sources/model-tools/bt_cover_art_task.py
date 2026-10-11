"""Native CSR artwork task lifecycle and outgoing transport, for interpretation.

Registers one additional scheduler task after the existing PAC task. Uses a
CM-assigned local PSM, separately discovered remote PSM, original ERTM/config
builders, copied transmit buffers and echoed per-send contexts. No PE is written.
Discovery, native OBEX state, deadlines and GUI publication are still absent.
"""
import hashlib
import struct

import pefile

import bt_cover_art_owner as owner
import bt_cover_art_framer as framer
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

REGISTER, INIT, HANDLE, DEINIT = 0x245000, 0x245400, 0x245800, 0x245c00
OPEN, SEND = 0x246400, 0x246800
QUEUE, NAME = 0x247000, 0x247010
SITE, REGISTRY = 0x246f8, 0x8517c
SIZE = owner.SIZE+framer.SIZE
# Owner reserved tail: local_psm16 +20, queue16 +22, registration32 +24,
# tx_busy16 +28, tx_serial16 +30. Framer starts at +32.
# Registration: 1=pending, 2=ready, 3=disabled. No retry on registration failure.
# Scheduler callbacks take pointer-to-owner storage. DEINIT is global scheduler
# shutdown only; it must never be used as a runtime channel-cancellation API.

REGISTER_CODE = f'''
{frame(0x30, ['s0', 's1'])}
lw t0, 0x40(sp)
lw s0, 0x44(sp)
lhu s1, 0x48(sp)
sw t0, 0x10(sp)
sw s0, 0x14(sp)
sh s1, 0x18(sp)
jal {hex(REGISTRY)}
nop
# Keep the original task untouched; add the cover task to segment zero only.
la a0, {hex(QUEUE)}
la a1, {hex(INIT)}
la a2, {hex(DEINIT)}
la a3, {hex(HANDLE)}
la t0, {hex(NAME)}
sw t0, 0x10(sp)
sw s0, 0x14(sp)
sh s1, 0x18(sp)
jal {hex(REGISTRY)}
nop
{end(0x30, ['s0', 's1'])}
'''

INIT_CODE = f'''
{frame(0x20, ['s0', 's1'])}
move s0, a0
sw zero, 0(s0)
addiu a0, zero, {SIZE}
jal 0x85b70
nop
beqz v0, done
nop
move s1, v0
move t0, v0
addiu t1, v0, {SIZE}
clear:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, clear
nop
sw s1, 0(s0)
la t0, {hex(QUEUE)}
lhu a0, 0(t0)
sh a0, 22(s1)
ori t0, zero, 0xffff
beq a0, t0, disabled
nop
addiu t0, zero, 1
sw t0, 24(s1)
move a1, zero
addiu a2, zero, 1
move a3, zero
sh zero, 0x10(sp)
jal 0x5063c
nop
move a0, v0
jal 0x782a8
nop
b done
nop
disabled:
addiu t0, zero, 3
sw t0, 24(s1)
done:
move v0, zero
{end(0x20, ['s0', 's1'])}
'''

HANDLE_CODE = f'''
{frame(0x30, ['s0', 's1', 's2'])}
lw s0, 0(a0)
sh zero, 0x10(sp)
sw zero, 0x14(sp)
addiu a0, sp, 0x10
addiu a1, sp, 0x14
jal 0x84ee8
nop
beqz v0, done
nop
lw s1, 0x14(sp)
lhu s2, 0x10(sp)
beqz s1, done
nop
beqz s0, dispatch
nop
addiu t0, zero, 0x104
bne s2, t0, dispatch
nop
lhu t0, 0(s1)
ori t1, zero, 0x8200
beq t0, t1, registered
nop
ori t1, zero, 0x8204
beq t0, t1, sent
nop
ori t1, zero, 0x8206
bne t0, t1, dispatch
nop
lw t0, 4(s0)
lw t1, 4(s1)
bne t0, t1, dispatch
nop
sh zero, 28(s0)
b dispatch
nop
registered:
lw t0, 24(s0)
addiu t1, zero, 1
bne t0, t1, discard
nop
lhu t0, 6(s1)
bnez t0, reg_failed
nop
lhu t0, 8(s1)
addiu t1, zero, 12
bne t0, t1, reg_failed
nop
lhu t0, 2(s1)
sltiu t1, t0, 0x1001
bnez t1, reg_failed
nop
andi t1, t0, 0x101
addiu t2, zero, 1
bne t1, t2, reg_failed
nop
sh t0, 20(s0)
addiu t0, zero, 2
sw t0, 24(s0)
b discard
nop
reg_failed:
sh zero, 20(s0)
addiu t0, zero, 3
sw t0, 24(s0)
b discard
nop
sent:
# Late/duplicate confirmations cannot consume a newer outstanding send.
lhu t0, 28(s0)
beqz t0, discard
nop
lw t0, 4(s0)
lw t1, 4(s1)
bne t0, t1, discard
nop
lhu t0, 30(s0)
lhu t1, 8(s1)
bne t0, t1, discard
nop
sh zero, 28(s0)
lhu t0, 12(s1)
addiu t1, zero, 12
beq t0, t1, dispatch
nop
move a0, s0
jal {hex(owner.STOP)}
nop
b discard
nop
dispatch:
move a0, s0
move a1, s2
move a2, s1
jal {hex(owner.DISPATCH)}
nop
b done
nop
discard:
move a0, s2
move a1, s1
jal 0x77f48
nop
move a0, s1
jal 0x85bb8
nop
done:
move v0, zero
{end(0x30, ['s0', 's1', 's2'])}
'''

DEINIT_CODE = f'''
{frame(0x30, ['s0', 's1'])}
move s0, a0
drain:
sh zero, 0x10(sp)
sw zero, 0x14(sp)
addiu a0, sp, 0x10
addiu a1, sp, 0x14
jal 0x84ee8
nop
beqz v0, drained
nop
lw s1, 0x14(sp)
beqz s1, drain
nop
lhu a0, 0x10(sp)
addiu t0, zero, 0x104
bne a0, t0, envelope
nop
move a1, s1
jal 0x77f48
nop
envelope:
move a0, s1
jal 0x85bb8
nop
b drain
nop
drained:
lw a0, 0(s0)
sw zero, 0(s0)
jal 0x85bb8
nop
move v0, zero
{end(0x30, ['s0', 's1'])}
'''

OPEN_CODE = f'''
{frame(0x50, ['s0', 's1', 's2', 's3'])}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
beqz s0, refused
nop
beqz s1, refused
nop
lw t0, 24(s0)
addiu t1, zero, 2
bne t0, t1, refused
nop
lw t0, 0(s0)
bnez t0, refused
nop
sltiu t0, s2, 0x1001
bnez t0, refused
nop
srl t0, s2, 16
bnez t0, refused
nop
andi t0, s2, 0x101
addiu t1, zero, 1
bne t0, t1, refused
nop
# Security must be supplied from the established stack policy, not invented.
beqz s3, refused
nop
srl t0, s3, 16
bnez t0, refused
nop
move a0, s0
move a1, s1
lhu a2, 20(s0)
jal {hex(owner.ARM)}
nop
beqz v0, refused
nop
sh zero, 28(s0)
# Original browsing helper creates mode=3 (ERTM), window=1, MTU=1024.
addiu a0, zero, 1024
jal 0x55fb8
nop
sw v0, 0x24(sp)
sh zero, 0x28(sp)
sh s3, 0x2c(sp)
sw zero, 0x20(sp)
ori t0, zero, 0xffff
sh t0, 0x1c(sp)
sh zero, 0x18(sp)
addiu t0, zero, 1024
sh t0, 0x14(sp)
sh s2, 0x10(sp)
lhu a0, 22(s0)
lw a1, 12(s0)
lw a2, 16(s0)
lhu a3, 20(s0)
jal 0x50820
nop
move a0, v0
jal 0x782a8
nop
addiu v0, zero, 1
b done
nop
refused:
move v0, zero
done:
{end(0x50, ['s0', 's1', 's2', 's3'])}
'''

SEND_CODE = f'''
{frame(0x40, ['s0', 's1', 's2', 's3'])}
move s0, a0
move s1, a1
move s2, a2
beqz s0, refused
nop
beqz s1, refused
nop
lw t0, 0(s0)
addiu t1, zero, 2
bne t0, t1, refused
nop
lw t0, 24(s0)
bne t0, t1, refused
nop
lw t0, 4(s0)
beqz t0, refused
nop
lhu t0, 28(s0)
bnez t0, refused
nop
sltiu t0, s2, 3
bnez t0, refused
nop
sltiu t0, s2, 1025
beqz t0, refused
nop
lhu t0, 10(s0)
sltu t0, t0, s2
bnez t0, refused
nop
addu t0, s1, s2
sltu t0, t0, s1
bnez t0, refused
nop
lbu t0, 1(s1)
lbu t1, 2(s1)
sll t0, t0, 8
or t0, t0, t1
bne t0, s2, refused
nop
lhu t0, 30(s0)
ori t1, zero, 0xffff
beq t0, t1, exhausted
nop
move a0, s2
jal 0x85b70
nop
beqz v0, refused
nop
move s3, v0
move t0, v0
move t1, s1
move t2, s2
copy:
lbu t3, 0(t1)
sb t3, 0(t0)
addiu t0, t0, 1
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, copy
nop
lhu a3, 30(s0)
addiu a3, a3, 1
sh a3, 30(s0)
addiu t0, zero, 1
sh t0, 28(s0)
lw a0, 4(s0)
move a1, s2
move a2, s3
jal 0x50c48
nop
move a0, v0
jal 0x782a8
nop
addiu v0, zero, 1
b done
nop
exhausted:
move a0, s0
jal {hex(owner.STOP)}
nop
refused:
move v0, zero
done:
{end(0x40, ['s0', 's1', 's2', 's3'])}
'''

HELPERS = ((REGISTER, 0x400, REGISTER_CODE, 'Preserve PAC registration, append artwork task in both passes'),
           (INIT, 0x400, INIT_CODE, 'Allocate/zero owner and request a dynamic local PSM'),
           (HANDLE, 0x400, HANDLE_CODE, 'Fetch owned messages, process registration and echoed TX contexts'),
           (DEINIT, 0x400, DEINIT_CODE, 'Global scheduler shutdown: drain/free without posting into stopped CM'),
           (OPEN, 0x400, OPEN_CODE, 'Use separate local/remote PSMs and owned ERTM configuration'),
           (SEND, 0x400, SEND_CODE, 'Copy one bounded OBEX packet and transfer its mblk to CM'))


def assembled():
    rows = []
    for address, capacity, code, purpose in HELPERS:
        raw, recipe, relocations = assemble(code, address, capacity)
        rows.append(dict(address=address, raw=raw, recipe=recipe, relocations=relocations, purpose=purpose))
    return rows


def bridge(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact retained MAX04/MAX05 Blue.exe')
    pe = pefile.PE(data=raw)
    assert pe.get_data(SITE-pe.OPTIONAL_HEADER.ImageBase, 4) == struct.pack('<I', 0x0c02145f)
    return 0x0c000000 | (REGISTER >> 2)


def initial_data():
    return {QUEUE: b'\xff\xff', NAME: b'CSR_MAX_COVER\0'}
