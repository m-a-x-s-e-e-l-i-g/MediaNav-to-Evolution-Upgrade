"""MIPS OBEX stream framing with owned storage and a synchronous packet consumer.

Export addresses are interpreter placements. State is a zeroed, exclusive 1,028
byte buffer, not a PE/global allocation. No stack/CSR callbacks are installed.
"""
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end
import bt_cover_art_owner as owner

ENTRY, PACKET = 0x242000, 0x244000
SIZE = 1028  # used32, packet[1024]
REGS = ['s0', 's1', 's2', 's3', 's4', 's5']
CODE = f'''
{frame(0x38, REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, zero
beqz s0, invalid_state
nop
andi t0, s0, 3
bnez t0, invalid_state
nop
addiu t0, s0, 1028
sltu t1, t0, s0
bnez t1, invalid_state
nop
sltiu t1, s2, 8193
beqz t1, failed
nop
lw t1, 0(s0)
sltiu t1, t1, 1024
beqz t1, failed
nop
beqz s2, success
nop
beqz s1, failed
nop
addu t1, s1, s2
sltu t2, t1, s1
bnez t2, failed
nop
# Source must not overlap the owner packet or used count.
sltu t2, s1, t0
beqz t2, next
nop
sltu t2, s0, t1
bnez t2, failed
nop
next:
lw s4, 0(s0)
sltiu t0, s4, 1024
beqz t0, failed
nop
beqz s2, success
nop
sltiu t0, s4, 3
beqz t0, length
nop
addiu s5, zero, 3
b copy
nop
length:
lbu t0, 5(s0)
lbu t1, 6(s0)
sll t0, t0, 8
or s5, t0, t1
sltiu t0, s5, 3
bnez t0, failed
nop
sltiu t0, s5, 1025
beqz t0, failed
nop
sltu t0, s4, s5
beqz t0, failed
nop
copy:
subu t0, s5, s4
sltu t1, s2, t0
beqz t1, copy_ready
nop
move t0, s2
copy_ready:
subu s2, s2, t0
addu t1, s0, s4
addiu t1, t1, 4
addu s4, s4, t0
copy_byte:
lbu t2, 0(s1)
sb t2, 0(t1)
addiu s1, s1, 1
addiu t1, t1, 1
addiu t0, t0, -1
bnez t0, copy_byte
nop
sw s4, 0(s0)
# A just-completed 3-byte header may itself be an empty packet.
sltiu t0, s4, 3
bnez t0, next
nop
lbu t0, 5(s0)
lbu t1, 6(s0)
sll t0, t0, 8
or s5, t0, t1
sltiu t0, s5, 3
bnez t0, failed
nop
sltiu t0, s5, 1025
beqz t0, failed
nop
bne s4, s5, next
nop
sltiu t0, s3, 8
beqz t0, failed
nop
addiu s3, s3, 1
move a0, s0
addiu a1, s0, 4
move a2, s5
jal {hex(PACKET)}
nop
sw zero, 0(s0)
beqz v0, failed
nop
b next
nop
success:
addiu v0, zero, 1
b done
nop
failed:
sw zero, 0(s0)
invalid_state:
move v0, zero
done:
{end(0x38, REGS)}
'''


def assembled():
    raw, recipe, relocations = assemble(CODE, ENTRY, 0x600)
    return dict(address=ENTRY, raw=raw, recipe=recipe, relocations=relocations)


def owner_adapter():
    """Place framing after the 32-byte channel state; lifecycle clears partial RX."""
    code = f'''
addiu t0, zero, 2
beq a1, t0, receive
nop
sw zero, {owner.SIZE}(a0)
jr ra
addiu v0, zero, 1
receive:
addiu a0, a0, {owner.SIZE}
move a1, a2
move a2, a3
la t9, {hex(ENTRY)}
jr t9
nop
'''
    raw, recipe, relocations = assemble(code, owner.NOTIFY, 0x100)
    return dict(address=owner.NOTIFY, raw=raw, recipe=recipe, relocations=relocations)
