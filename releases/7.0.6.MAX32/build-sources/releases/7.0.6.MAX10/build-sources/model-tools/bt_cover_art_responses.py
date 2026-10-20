"""Bounded MIPS OBEX response parsers, for interpretation only.

CONNECT writes cid32/peer_mopl32 to a disjoint eight-byte output on success.
GET owns no allocation: caller supplies a serialized collection context (32 bytes):
body pointer, capacity, used, declared size, have-declared, frames, cid, reserved.
GET returns 1=continue, 2=complete, -1=invalid; invalid leaves context/body intact.
Completion is collected bytes, not decoded or published artwork. No task hook,
deadlines, metadata correlation, OS decoder or executable installation is added.
"""
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end
from bt_cover_art_client import TARGET, MAX_IMAGE

HEADER, CONNECT, GET = 0x248000, 0x249000, 0x24a000
CONTEXT_SIZE = 32


def u16(dest, pointer, offset=0):
    return f'''lbu {dest}, {offset}({pointer})
sll {dest}, {dest}, 8
lbu t9, {offset+1}({pointer})
or {dest}, {dest}, t9'''


def u32(dest, pointer, offset=0):
    return f'''lbu {dest}, {offset}({pointer})
sll {dest}, {dest}, 8
lbu t9, {offset+1}({pointer})
or {dest}, {dest}, t9
sll {dest}, {dest}, 8
lbu t9, {offset+2}({pointer})
or {dest}, {dest}, t9
sll {dest}, {dest}, 8
lbu t9, {offset+3}({pointer})
or {dest}, {dest}, t9'''


def overlap(lo1, hi1, lo2, hi2, label):
    return f'''sltu t0, {lo1}, {hi2}
beqz t0, {label}
nop
sltu t0, {lo2}, {hi1}
bnez t0, failed
nop
{label}:'''


# Internal leaf: caller proves a mapped, nonwrapping readable range.
# Returns the complete header size, or zero. t0..t9/v0 are scratch.
HEADER_CODE = f'''
beqz a1, invalid
nop
lbu t0, 0(a0)
srl t0, t0, 6
sltiu t1, t0, 2
beqz t1, fixed
nop
sltiu t1, a1, 3
bnez t1, invalid
nop
{u16('v0', 'a0', 1)}
sltiu t1, v0, 3
bnez t1, invalid
nop
sltu t1, a1, v0
bnez t1, invalid
nop
bnez t0, done
nop
addiu t1, v0, -3
beqz t1, done
nop
andi t1, t1, 1
bnez t1, invalid
nop
addu t1, a0, v0
lbu t2, -1(t1)
lbu t3, -2(t1)
or t2, t2, t3
bnez t2, invalid
nop
b done
nop
fixed:
addiu v0, zero, 2
addiu t1, zero, 2
beq t0, t1, fixed_size
nop
addiu v0, zero, 5
fixed_size:
sltu t1, a1, v0
bnez t1, invalid
nop
done:
jr ra
nop
invalid:
jr ra
move v0, zero
'''

CREGS = ['s0', 's1', 's2', 's3', 's4', 's5', 's6', 's7']
target_check = '\n'.join(f'lbu t0, {i+3}(s3)\naddiu t1, zero, {b}\nbne t0, t1, failed\nnop'
                         for i, b in enumerate(TARGET))
CONNECT_CODE = f'''
{frame(0x40, CREGS)}
move s0, a0
move s1, a1
move s2, a2
beqz s0, failed
nop
beqz s2, failed
nop
andi t0, s2, 3
bnez t0, failed
nop
sltiu t0, s1, 7
bnez t0, failed
nop
sltiu t0, s1, 1025
beqz t0, failed
nop
addu s1, s0, s1
sltu t0, s1, s0
bnez t0, failed
nop
addiu t1, s2, 8
sltu t0, t1, s2
bnez t0, failed
nop
{overlap('s0', 's1', 's2', 't1', 'disjoint')}
{u16('t0', 's0', 1)}
subu t1, s1, s0
bne t0, t1, failed
nop
lbu t0, 0(s0)
addiu t1, zero, 0xa0
bne t0, t1, failed
nop
lbu t0, 3(s0)
sltiu t0, t0, 0x15
bnez t0, failed
nop
lbu t0, 4(s0)
bnez t0, failed
nop
{u16('s6', 's0', 5)}
sltiu t0, s6, 255
bnez t0, failed
nop
addiu s3, s0, 7
move s4, zero
move s5, zero
move s7, zero
next:
beq s3, s1, finish
nop
move a0, s3
subu a1, s1, s3
jal {hex(HEADER)}
nop
beqz v0, failed
nop
lbu t0, 0(s3)
addiu t1, zero, 0xcb
beq t0, t1, identity
nop
addiu t1, zero, 0x4a
bne t0, t1, advance
nop
andi t0, s4, 2
bnez t0, failed
nop
ori s4, s4, 2
addiu t0, zero, 19
bne v0, t0, failed
nop
{target_check}
b advance
nop
identity:
andi t0, s4, 1
bnez t0, failed
nop
ori s4, s4, 1
{u32('s5', 's3', 1)}
advance:
addu s3, s3, v0
b next
nop
finish:
andi t0, s4, 1
beqz t0, failed
nop
sw s5, 0(s2)
sw s6, 4(s2)
addiu v0, zero, 1
b done
nop
failed:
addiu v0, zero, -1
done:
{end(0x40, CREGS)}
'''

GET_CODE = f'''
{frame(0x60, CREGS)}
move s0, a0
move s1, a1
move s2, a2
beqz s0, failed
nop
andi t0, s0, 3
bnez t0, failed
nop
addiu t2, s0, 32
sltu t0, t2, s0
bnez t0, failed
nop
beqz s1, failed
nop
sltiu t0, s2, 3
bnez t0, failed
nop
sltiu t0, s2, 1025
beqz t0, failed
nop
addu s2, s1, s2
sltu t0, s2, s1
bnez t0, failed
nop
{overlap('s0', 't2', 's1', 's2', 'context_packet_disjoint')}
lw t3, 0(s0)
beqz t3, failed
nop
lw t4, 4(s0)
beqz t4, failed
nop
la t0, {MAX_IMAGE+1}
sltu t0, t4, t0
beqz t0, failed
nop
addu t4, t3, t4
sltu t0, t4, t3
bnez t0, failed
nop
{overlap('t3', 't4', 's0', 't2', 'body_context_disjoint')}
{overlap('t3', 't4', 's1', 's2', 'body_packet_disjoint')}
lw s4, 8(s0)
lw t0, 4(s0)
sltu t0, t0, s4
bnez t0, failed
nop
lw s5, 12(s0)
lw s6, 16(s0)
sltiu t0, s6, 2
beqz t0, failed
nop
beqz s6, no_declared
nop
lw t0, 4(s0)
sltu t0, t0, s5
bnez t0, failed
nop
no_declared:
lw t0, 20(s0)
sltiu t0, t0, 1024
beqz t0, failed
nop
{u16('t0', 's1', 1)}
subu t1, s2, s1
bne t0, t1, failed
nop
lbu t0, 0(s1)
addiu t1, zero, 0x90
beq t0, t1, opcode_valid
nop
addiu t1, zero, 0xa0
bne t0, t1, failed
nop
opcode_valid:
addiu s3, s1, 3
move s7, zero
validate_next:
beq s3, s2, validated
nop
move a0, s3
subu a1, s2, s3
jal {hex(HEADER)}
nop
beqz v0, failed
nop
lbu t0, 0(s3)
addiu t1, zero, 0xcb
beq t0, t1, identity
nop
addiu t1, zero, 0xc3
beq t0, t1, declared
nop
addiu t1, zero, 0x48
beq t0, t1, body
nop
addiu t1, zero, 0x49
bne t0, t1, advance
nop
body:
andi t0, s7, 1
bnez t0, failed
nop
lbu t0, 0(s3)
andi t0, t0, 1
or s7, s7, t0
addiu t0, v0, -3
addu s4, s4, t0
lw t0, 4(s0)
sltu t0, t0, s4
bnez t0, failed
nop
b advance
nop
identity:
andi t0, s7, 2
bnez t0, failed
nop
ori s7, s7, 2
{u32('t0', 's3', 1)}
lw t1, 24(s0)
bne t0, t1, failed
nop
b advance
nop
declared:
{u32('t0', 's3', 1)}
lw t1, 4(s0)
sltu t1, t1, t0
bnez t1, failed
nop
beqz s6, new_length
nop
bne t0, s5, failed
nop
new_length:
move s5, t0
addiu s6, zero, 1
advance:
addu s3, s3, v0
b validate_next
nop
validated:
andi t0, s7, 1
lbu t1, 0(s1)
addiu t2, zero, 0xa0
bne t1, t2, continuing
nop
beqz t0, failed
nop
beqz s4, failed
nop
beqz s6, copy_begin
nop
bne s4, s5, failed
nop
b copy_begin
nop
continuing:
bnez t0, failed
nop
copy_begin:
# Full validation precedes all context/body writes; input is disjoint and stable.
lw t0, 0(s0)
lw t1, 8(s0)
addu s7, t0, t1
sw s4, 8(s0)
sw s5, 12(s0)
sw s6, 16(s0)
lw t0, 20(s0)
addiu t0, t0, 1
sw t0, 20(s0)
addiu s3, s1, 3
copy_next:
beq s3, s2, finish
nop
move a0, s3
subu a1, s2, s3
jal {hex(HEADER)}
nop
addu s4, s3, v0
lbu t0, 0(s3)
addiu t1, zero, 0x48
beq t0, t1, copy_body
nop
addiu t1, zero, 0x49
bne t0, t1, copy_advance
nop
copy_body:
addiu t0, s3, 3
copy_bytes:
beq t0, s4, copy_advance
nop
lbu t1, 0(t0)
sb t1, 0(s7)
addiu t0, t0, 1
addiu s7, s7, 1
b copy_bytes
nop
copy_advance:
move s3, s4
b copy_next
nop
finish:
lbu t0, 0(s1)
addiu t1, zero, 0xa0
addiu v0, zero, 1
bne t0, t1, done
nop
addiu v0, zero, 2
b done
nop
failed:
addiu v0, zero, -1
done:
{end(0x60, CREGS)}
'''

HELPERS = ((HEADER, 0x400, HEADER_CODE, 'Internal bounded Unicode/bytes/fixed header validation'),
           (CONNECT, 0x1000, CONNECT_CODE, 'Validate BIP handshake; atomically return CID and peer packet limit'),
           (GET, 0x1000, GET_CODE, 'Validate complete response then append owned body bytes; no mutation on error'))


def assembled():
    result = []
    for address, capacity, code, purpose in HELPERS:
        raw, recipe, relocations = assemble(code, address, capacity)
        result.append(dict(address=address, raw=raw, recipe=recipe,
                           relocations=relocations, purpose=purpose))
    return result
