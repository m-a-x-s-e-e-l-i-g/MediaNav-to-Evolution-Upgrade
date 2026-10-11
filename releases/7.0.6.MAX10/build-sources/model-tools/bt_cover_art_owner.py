"""Separate MIPS artwork channel owner; interpreter exports, not an installed task.

One serialized scheduler owner, one outstanding connect, no reopen until completion.
Only CM queue messages belonging to this owner may enter DISPATCH. RX bytes are
borrowed by NOTIFY synchronously; that callback must copy before returning.
No outgoing connect, OBEX parser, timer, JPEG decoder or GUI wiring is installed.
"""
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

BASE = 0x240000
ARM, STOP, DISPATCH, NOTIFY = BASE, BASE+0x200, BASE+0x400, BASE+0x1000
SIZE = 0x20
IDLE, OPENING, ACTIVE, CLOSING, CANCELLED = range(5)
# State: phase32 +0, CID32 +4, PSM16 +8, MTU16 +10, peer64 +12.
# Remaining bytes reserved/zero. Caller retains storage until task drain completes.
# Notification: (state, event, borrowed_data, size), events opened=1/RX=2/closed=3/error=4.
# Open/RX callback returns nonzero to continue, zero to request closure.

ARM_CODE = f'''
beqz a0, refused
nop
beqz a1, refused
nop
andi t0, a0, 3
bnez t0, refused
nop
andi t0, a1, 3
bnez t0, refused
nop
lw t0, 0(a0)
bnez t0, refused
nop
sltiu t0, a2, 0x1001
bnez t0, refused
nop
srl t0, a2, 16
bnez t0, refused
nop
andi t0, a2, 0x101
addiu t1, zero, 1
bne t0, t1, refused
nop
lw t0, 0(a1)
lw t1, 4(a1)
sw t0, 12(a0)
sw t1, 16(a0)
sh a2, 8(a0)
sh zero, 10(a0)
sw zero, 4(a0)
addiu t0, zero, 1
sw t0, 0(a0)
jr ra
addiu v0, zero, 1
refused:
jr ra
move v0, zero
'''

STOP_CODE = f'''
{frame(0x20, ['s0'])}
move s0, a0
beqz s0, stopped
nop
lw t0, 0(s0)
addiu t1, zero, 1
beq t0, t1, abandon
nop
addiu t1, zero, 2
bne t0, t1, stopped
nop
addiu t0, zero, 3
sw t0, 0(s0)
lw a0, 4(s0)
move a1, zero
jal 0x50c04
nop
move a0, v0
jal 0x782a8
nop
b stopped
nop
abandon:
addiu t0, zero, 4
sw t0, 0(s0)
stopped:
move v0, zero
{end(0x20, ['s0'])}
'''

DISPATCH_CODE = f'''
{frame(0x38, ['s0', 's1', 's2', 's3'])}
move s0, a0
move s1, a2
move s2, a1
beqz s1, done
nop
addiu t0, zero, 0x104
bne s2, t0, free_message
nop
beqz s0, contents
nop
lhu t0, 0(s1)
ori t1, zero, 0x8201
beq t0, t1, connected
nop
ori t1, zero, 0x8205
beq t0, t1, received
nop
ori t1, zero, 0x8206
beq t0, t1, disconnected
nop
ori t1, zero, 0x8204
bne t0, t1, contents
nop
# DataCFM failures stop only this active CID; no pending TX storage here.
lw t0, 0(s0)
addiu t1, zero, 2
bne t0, t1, contents
nop
lw t0, 4(s0)
lw t1, 4(s1)
bne t0, t1, contents
nop
lhu t0, 10(s1)
beqz t0, contents
nop
b stop_channel
nop
connected:
# A duplicate CFM for the live CID must not disconnect that CID.
lw t0, 0(s0)
addiu t1, zero, 2
beq t0, t1, check_duplicate
nop
addiu t1, zero, 3
bne t0, t1, check_pending
nop
check_duplicate:
lw t0, 4(s0)
lw t1, 4(s1)
beq t0, t1, contents
nop
b orphan
nop
check_pending:
lw s3, 0(s0)
addiu t0, zero, 1
beq s3, t0, match_peer
nop
addiu t0, zero, 4
bne s3, t0, orphan
nop
match_peer:
lhu t0, 8(s0)
lhu t1, 8(s1)
bne t0, t1, orphan
nop
lw t0, 12(s0)
lw t1, 16(s1)
bne t0, t1, orphan
nop
lw t0, 16(s0)
lw t1, 20(s1)
bne t0, t1, orphan
nop
lhu t0, 24(s1)
bnez t0, connect_failed
nop
lhu t0, 26(s1)
addiu t1, zero, 12
bne t0, t1, connect_failed
nop
lw t0, 4(s1)
beqz t0, connect_failed
nop
sw t0, 4(s0)
lhu t0, 10(s1)
sh t0, 10(s0)
addiu t1, zero, 4
beq s3, t1, close_new
nop
sltiu t1, t0, 255
bnez t1, close_new
nop
addiu t0, zero, 2
sw t0, 0(s0)
move a0, s0
addiu a1, zero, 1
move a2, zero
move a3, zero
jal {hex(NOTIFY)}
nop
bnez v0, contents
nop
b stop_channel
nop
close_new:
addiu t0, zero, 2
sw t0, 0(s0)
b stop_channel
nop
connect_failed:
sw zero, 0(s0)
sw zero, 4(s0)
sh zero, 10(s0)
move a0, s0
addiu a1, zero, 4
move a2, zero
move a3, zero
jal {hex(NOTIFY)}
nop
b contents
nop
orphan:
lhu t0, 24(s1)
bnez t0, contents
nop
lhu t0, 26(s1)
addiu t1, zero, 12
bne t0, t1, contents
nop
lw a0, 4(s1)
beqz a0, contents
nop
move a1, zero
jal 0x50c04
nop
move a0, v0
jal 0x782a8
nop
b contents
nop
received:
# ACK every delivered DataIND once, including stale/closing channels.
lw a0, 4(s1)
jal 0x50cd4
nop
move a0, v0
jal 0x782a8
nop
lw t0, 0(s0)
addiu t1, zero, 2
bne t0, t1, contents
nop
lw t0, 4(s0)
lw t1, 4(s1)
bne t0, t1, contents
nop
lhu a3, 8(s1)
sltiu t0, a3, 8193
beqz t0, stop_channel
nop
beqz a3, contents
nop
lw a2, 12(s1)
beqz a2, stop_channel
nop
addu t0, a2, a3
sltu t0, t0, a2
bnez t0, stop_channel
nop
move a0, s0
addiu a1, zero, 2
jal {hex(NOTIFY)}
nop
bnez v0, contents
nop
b stop_channel
nop
disconnected:
lw t0, 0(s0)
addiu t1, zero, 2
beq t0, t1, match_cid
nop
addiu t1, zero, 3
bne t0, t1, contents
nop
match_cid:
lw t0, 4(s0)
lw t1, 4(s1)
bne t0, t1, contents
nop
sw zero, 0(s0)
sw zero, 4(s0)
sh zero, 10(s0)
move a0, s0
addiu a1, zero, 3
move a2, zero
move a3, zero
jal {hex(NOTIFY)}
nop
b contents
nop
stop_channel:
move a0, s0
jal {hex(STOP)}
nop
contents:
move a0, s2
move a1, s1
jal 0x77f48
nop
free_message:
move a0, s1
jal 0x85bb8
nop
done:
move v0, zero
{end(0x38, ['s0', 's1', 's2', 's3'])}
'''

HELPERS = ((ARM, 0x200, ARM_CODE, 'Arm a single submitted outgoing connect; return accepted/refused'),
           (STOP, 0x200, STOP_CODE, 'Cancel pending open or request a single active-channel disconnect'),
           (DISPATCH, 0xc00, DISPATCH_CODE, 'Consume an owner CM message; ACK, borrow/copy, free contents and envelope'))


def assembled():
    rows = []
    for address, capacity, code, purpose in HELPERS:
        raw, recipe, relocations = assemble(code, address, capacity)
        rows.append(dict(address=address, raw=raw, recipe=recipe,
                         relocations=relocations, purpose=purpose))
    return rows
