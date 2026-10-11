"""Native owned text assembly, one final publication and exact payload cleanup.

Chain real request/continuation ownership and bounded streaming assembly.
Keep original non-scope-3 handlers. Ordinary replies publish only at a valid
final; failure/stale replies preserve text. Deadline/lifecycle/PE binding open.
"""
import hashlib
import struct
import pefile
import bt_text_metadata_owner as owner
import bt_text_metadata_stream as stream
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

FINAL,INTERIM,RECEIVE,RESET=0x289c00,0x289d00,0x28a000,0x28b000
STATE,SIZE=0x294400,32
# generation0, phase4 (idle0, assembling1, refused2), count8, frames12,
# successful_generation16, failed_generation20, reserved24/28.
FINAL_SITE,INTERIM_SITE,PROFILE_TABLE=0x20d1c,0x20d2c,0x101eb4
REGS=['s0','s1','s2','s3','s4','s5','s6','s7']


def reset():return f'''
la t0, {hex(STATE)}
sw a0, 0(t0)
sw zero, 4(t0)
sw zero, 8(t0)
sw zero, 12(t0)
sw zero, 24(t0)
sw zero, 28(t0)
addiu v0, zero, 1
jr ra
nop
'''


def receive():return f'''
{frame(0x60,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
lbu t0, 3(s2)
addiu t1, zero, 3
bne t0, t1, legacy
nop
move a0, s2
move a1, s3
jal {hex(owner.CLAIM)}
nop
move s4, v0
beqz s4, cleanup
nop
la t0, {hex(STATE)}
lw t1, 0(t0)
beq t1, s4, current
nop
move a0, s4
jal {hex(RESET)}
nop
current:
beqz s3, packet
nop
lw t0, 20(s2)
la t1, 0x118000
bne t0, t1, bad
nop
packet:
lw s5, 16(s2)
lhu s6, 14(s2)
sltiu t0, s6, 13
bnez t0, bad
nop
beqz s5, bad
nop
addu t0, s5, s6
sltu t0, t0, s5
bnez t0, bad
nop
lbu t0, 3(s5)
addiu t1, zero, 9
beq t0, t1, ctype
nop
addiu t1, zero, 12
bne t0, t1, bad
nop
ctype:
lbu t0, 9(s5)
addiu t1, zero, 0x20
bne t0, t1, bad
nop
lbu t0, 11(s5)
lbu t1, 12(s5)
sll t0, t0, 8
or t0, t0, t1
addiu t1, s6, -13
bne t0, t1, bad
nop
lbu s7, 10(s5)
andi s7, s7, 3
beqz s3, intermediate
nop
addiu t0, zero, 3
beq s7, t0, continuation
nop
bnez s7, bad
nop
b first
nop
intermediate:
addiu t0, zero, 2
beq s7, t0, continuation
nop
addiu t0, zero, 1
bne s7, t0, bad
nop
first:
sltiu t0, s6, 14
bnez t0, bad
nop
la t0, {hex(STATE)}
lw t1, 4(t0)
bnez t1, bad
nop
lbu t1, 13(s5)
lbu t2, 12(s2)
bne t1, t2, bad
nop
move a0, t1
sw t1, 8(t0)
jal {hex(stream.RESET)}
nop
beqz v0, bad
nop
la t0, {hex(STATE)}
addiu t1, zero, 1
sw t1, 4(t0)
addiu t2, zero, 14
b offset
nop
continuation:
la t0, {hex(STATE)}
lw t1, 4(t0)
addiu t2, zero, 1
bne t1, t2, bad
nop
lw t1, 8(t0)
lbu t2, 12(s2)
bne t1, t2, bad
nop
addiu t2, zero, 13
offset:
beqz s3, interim_offset
nop
lhu t0, 24(s2)
b check_offset
nop
interim_offset:
lhu t0, 20(s2)
check_offset:
bne t0, t2, bad
nop
addu s5, s5, t2
subu s6, s6, t2
# Empty start/final fragments are valid. Empty continuation intermediates
# cannot advance the bounded stream and must not keep an ACK loop alive.
addiu t0, zero, 2
bne s7, t0, forward
nop
beqz s6, bad
nop
forward:
beqz s3, cancel_flag
nop
b append
nop
cancel_flag:
lbu t0, 0x248(s1)
beqz t0, bad
nop
append:
move a0, s5
move a1, s6
jal {hex(stream.APPEND)}
nop
beqz v0, bad
nop
la t0, {hex(STATE)}
lw t1, 12(t0)
addiu t1, t1, 1
sw t1, 12(t0)
bnez s3, finish
nop
move a0, s2
addiu a1, zero, 1
move a2, s4
jal {hex(owner.ACK_BUILD)}
nop
beqz v0, mark
nop
b cleanup
nop
finish:
jal {hex(stream.FINISH)}
nop
beqz v0, bad
nop
move s5, v0
la t0, {hex(owner.STATE)}
lw t1, 0(t0)
bne t1, s4, cleanup
nop
addiu a0, s2, 4
lw a1, 12(t0)
lw a2, 8(t0)
jal {hex(owner.FRESH)}
nop
beqz v0, bad
nop
la t0, {hex(owner.ROOT_POINTER)}
lw t0, 0(t0)
lw s6, 0x26c(t0)
# Match the retained eight-byte UID repair: entirely zero UIDs do not replace
# the browse UID; a nonzero byte in any position updates both original slots.
move t0, zero
addiu t1, s2, 4
addiu t2, zero, 8
uid:
lbu t3, 0(t1)
or t0, t0, t3
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, uid
nop
beqz t0, publish
nop
addiu a0, s6, 0x235
addiu a1, s2, 4
addiu a2, zero, 8
jal 0x85758
nop
addiu a0, s6, 0x219
addiu a1, s2, 4
addiu a2, zero, 8
jal 0x85758
nop
publish:
addiu a0, s6, 0xee
move a1, s5
addiu a2, zero, 260
jal 0x85758
nop
move a0, s0
addiu a1, zero, 1
jal 0x1eb50
nop
la t0, {hex(STATE)}
sw s4, 16(t0)
b cleanup
nop
bad:
la t0, {hex(STATE)}
lw t1, 4(t0)
addiu t2, zero, 2
beq t1, t2, cleanup
nop
sw t2, 4(t0)
sw s4, 20(t0)
bnez s3, cleanup
nop
move a0, s2
move a1, zero
move a2, s4
jal {hex(owner.ACK_BUILD)}
nop
b cleanup
nop
mark:
la t0, {hex(STATE)}
addiu t1, zero, 2
sw t1, 4(t0)
sw s4, 20(t0)
cleanup:
lw a0, 16(s2)
jal 0x85bb8
nop
sw zero, 16(s2)
beqz s3, done
nop
beqz s4, done
nop
la t0, {hex(owner.STATE)}
lw t1, 0(t0)
bne t1, s4, done
nop
addiu t0, zero, 1
sb t0, 0x248(s1)
la t0, {hex(STATE)}
lw t1, 0(t0)
bne t1, s4, done
nop
sw zero, 4(t0)
done:
move v0, zero
{end(0x60,REGS)}
legacy:
move a0, s0
move a1, s1
move a2, s2
beqz s3, legacy_interim
nop
jal 0x1fa44
nop
b done
nop
legacy_interim:
jal 0x1fce8
nop
b done
nop
'''


def assembled():
    rows=[]
    for name,at,n,code in (('text_final',FINAL,0x100,f'addiu a3, zero, 1\nla t9, {hex(RECEIVE)}\njr t9\nnop'),
                           ('text_interim',INTERIM,0x100,f'move a3, zero\nla t9, {hex(RECEIVE)}\njr t9\nnop'),
                           ('text_receive',RECEIVE,0x1000,receive()),
                           ('text_receive_reset',RESET,0x400,reset())):
        raw,recipe,relocations=assemble(code,at,n)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    return rows


def sites(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase
    result=owner.sites(raw)
    for at,before,after in ((FINAL_SITE,0x1fa44,FINAL),(INTERIM_SITE,0x1fce8,INTERIM)):
        assert pe.get_data(at-base,8)==struct.pack('<II',(3<<26)|(before>>2),0x02003025)
        result[at]=(3<<26)|(after>>2)
    assert pe.get_data(PROFILE_TABLE-base,4)==struct.pack('<I',0x52260)
    result[PROFILE_TABLE]=owner.ACK_PROFILE
    return result
