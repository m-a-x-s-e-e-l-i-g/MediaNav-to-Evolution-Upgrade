"""Native ordinary-text request/confirmation ownership component.

Chain existing artwork bridges; bind scope-3 mask-127 requests to their actual
factory allocation. Interim pointer tags retain parent/generation identity.
Owned four-byte ACKs get side tags; a guarded profile entry checks the actual
pending confirmation before advancing it. Application dispatch is not wired.
All state access requires serialized CSR segment-zero callbacks.
"""
import hashlib
import struct
import pefile
import bt_cover_art_metadata as metadata
import bt_cover_art_metadata_ticket as ticket
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

CAPTURE,RESPONSE,POST,CLAIM,INVALIDATE,FRESH=0x286800,0x286c00,0x287400,0x287c00,0x288400,0x288800
ACK_BUILD,ACK_PROFILE=0x288c00,0x289400
STATE,INTERIM_END,SIZE,TAGS=0x294200,224,416,16
# serial0,parent4,destination8,peer12,UID16..23,current_parent24,current_serial28,
# tags32..223: interim pointer, parent pointer, serial. Serial never wraps.
# ACK tags224..415: four-byte request pointer, parent pointer, serial. Preserve
# these through invalidation until the profile consumes each queued request.
ROOT_POINTER=0x20e1e8


def fresh():return f'''
# FRESH(UID,peer,destination) uses the original selected-row calculation.
# Do not impose a guessed row-count limit on the native manager's index.
la t0, {hex(ROOT_POINTER)}
lw t0, 0(t0)
beqz t0, no
nop
lw t0, 0x26c(t0)
beqz t0, no
nop
lhu t1, 0x60(t0)
bne t1, a2, no
nop
lbu t1, 0x5e(t0)
sll t2, t1, 4
sll t1, t1, 3
addu t1, t1, t2
addu t1, t1, t0
lbu t2, 0x6d(t1)
addiu t3, zero, 2
bne t2, t3, no
nop
lbu t2, 0x6c(t1)
bne t2, a1, no
nop
addiu t0, t0, 0x235
move t1, a0
addiu t2, zero, 8
uid:
lbu t3, 0(t0)
lbu t4, 0(t1)
bne t3, t4, no
nop
addiu t0, t0, 1
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, uid
nop
addiu v0, zero, 1
jr ra
nop
no:
move v0, zero
jr ra
nop
'''


def capture():return f'''
{frame(0x40,['s0','s1','s2','s3','s4','s5'])}
move s0, a0
move s1, a1
move s2, a2
jal {hex(ticket.CAPTURE)}
nop
move s3, v0
jal {hex(ticket.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, done
nop
beqz s3, done
nop
addiu t0, zero, 3
bne s1, t0, done
nop
addiu s4, s2, -6
lhu t0, 0(s4)
addiu t1, zero, 0x20c
bne t0, t1, done
nop
lw t0, 16(s4)
addiu t1, zero, 127
bne t0, t1, done
nop
move a0, s2
move a1, s0
lhu a2, 2(s4)
jal {hex(FRESH)}
nop
beqz v0, done
nop
la s5, {hex(STATE)}
lw t0, 0(s5)
addiu t1, zero, -1
beq t0, t1, saturated
nop
addiu t0, t0, 1
sw t0, 0(s5)
sw s3, 4(s5)
lhu t0, 2(s4)
sw t0, 8(s5)
sw s0, 12(s5)
addiu t0, s5, 16
move t1, s2
addiu t2, zero, 8
uid:
lbu t3, 0(t1)
sb t3, 0(t0)
addiu t0, t0, 1
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, uid
nop
b done
nop
saturated:
sw zero, 4(s5)
done:
move v0, s3
{end(0x40,['s0','s1','s2','s3','s4','s5'])}
'''


def response():return f'''
{frame(0x40,['s0','s1','s2','s3','s4','s5'])}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
move s4, zero
# A single/start packet needs count byte 13. Native length <=12 takes the
# existing error/final path without reading source bytes. Bound every borrowed
# pointer before reading kind byte 10; complete/continuation empty bodies remain.
sltiu t0, s2, 13
bnez t0, checked
nop
beqz s3, short
nop
addu t0, s3, s2
sltu t0, t0, s3
bnez t0, short
nop
ori t0, zero, 0xffff
sltu t0, t0, s2
bnez t0, short
nop
addiu t0, zero, 13
bne s2, t0, checked
nop
lbu t0, 10(s3)
andi t0, t0, 3
sltiu t0, t0, 2
beqz t0, checked
nop
short:
addiu s2, zero, 12
checked:
jal {hex(ticket.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, invoke
nop
beqz s1, invoke
nop
la t0, {hex(STATE)}
lw t1, 4(t0)
beqz t1, invoke
nop
lw t2, 16(s1)
bne t1, t2, invoke
nop
addiu a0, t0, 16
lw a1, 12(t0)
lw a2, 8(t0)
jal {hex(FRESH)}
nop
beqz v0, invoke
nop
la t0, {hex(STATE)}
lw t1, 4(t0)
lw t2, 0(t0)
sw t1, 24(t0)
sw t2, 28(t0)
addiu s4, zero, 1
invoke:
move a0, s0
move a1, s1
move a2, s2
move a3, s3
jal {hex(metadata.RESPONSE)}
nop
move s5, v0
beqz s4, done
nop
la t0, {hex(STATE)}
sw zero, 24(t0)
sw zero, 28(t0)
done:
move v0, s5
{end(0x40,['s0','s1','s2','s3','s4','s5'])}
'''


def post():return f'''
{frame(0x30,['s0','s1','s2'])}
move s0, a0
move s1, a1
jal {hex(ticket.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, invoke
nop
la s2, {hex(STATE)}
lw t0, 24(s2)
beqz t0, invoke
nop
lw t1, 4(s2)
bne t0, t1, invoke
nop
lw t0, 28(s2)
lw t1, 0(s2)
bne t0, t1, invoke
nop
lw t0, 8(s2)
bne t0, s0, invoke
nop
addiu t0, s2, 32
addiu t1, s2, {INTERIM_END}
move t2, zero
scan:
lw t3, 0(t0)
beq t3, s1, full
nop
bnez t3, next
nop
bnez t2, next
nop
move t2, t0
next:
addiu t0, t0, 12
bne t0, t1, scan
nop
beqz t2, full
nop
sw s1, 0(t2)
lw t0, 24(s2)
sw t0, 4(t2)
lw t0, 28(s2)
sw t0, 8(t2)
b invoke
nop
full:
# No untagged fragment may borrow the latest request. Native posting remains.
sw zero, 4(s2)
invoke:
move a0, s0
move a1, s1
jal {hex(metadata.INTERIM_POST)}
nop
{end(0x30,['s0','s1','s2'])}
'''


def claim():return f'''
{frame(0x30,['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
beqz s0, no
nop
sltiu t0, s1, 2
beqz t0, no
nop
jal {hex(ticket.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, no
nop
la s2, {hex(STATE)}
lw t0, 8(s2)
bne t0, v0, no
nop
beqz s1, interim
nop
lw t0, 4(s2)
beqz t0, no
nop
bne t0, s0, no
nop
# Final identity drains even if live track/peer validation now refuses it.
sw zero, 4(s2)
lw s3, 0(s2)
lhu t0, 0(s0)
ori t1, zero, 0x820d
bne t0, t1, no
nop
b check
nop
interim:
addiu t0, s2, 32
addiu t1, s2, {INTERIM_END}
find:
lw t2, 0(t0)
beq t2, s0, found
nop
addiu t0, t0, 12
bne t0, t1, find
nop
b no
nop
found:
lw t1, 4(t0)
lw s3, 8(t0)
sw zero, 0(t0)
sw zero, 4(t0)
sw zero, 8(t0)
lw t0, 4(s2)
beqz t0, no
nop
bne t0, t1, no
nop
lw t0, 0(s2)
bne t0, s3, no
nop
lhu t0, 0(s0)
ori t1, zero, 0x8224
bne t0, t1, no
nop
check:
beqz s3, no
nop
lbu t0, 3(s0)
addiu t1, zero, 3
bne t0, t1, no
nop
lbu t0, 2(s0)
lw t1, 12(s2)
bne t0, t1, no
nop
addiu t0, s0, 4
addiu t1, s2, 16
addiu t2, zero, 8
uid:
lbu t3, 0(t0)
lbu t4, 0(t1)
bne t3, t4, no
nop
addiu t0, t0, 1
addiu t1, t1, 1
addiu t2, t2, -1
bnez t2, uid
nop
addiu a0, s0, 4
lw a1, 12(s2)
lw a2, 8(s2)
jal {hex(FRESH)}
nop
beqz v0, no
nop
move v0, s3
b done
nop
no:
move v0, zero
done:
{end(0x30,['s0','s1','s2','s3'])}
'''


def invalidate():return f'''
{frame(0x18,[])}
jal {hex(ticket.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, no
nop
la t0, {hex(STATE)}
sw zero, 4(t0)
sw zero, 24(t0)
sw zero, 28(t0)
addiu t0, t0, 32
la t1, {hex(STATE+INTERIM_END)}
clear:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, clear
nop
addiu v0, zero, 1
b done
nop
no:
move v0, zero
done:
{end(0x18,[])}
'''


def ack_build():return f'''
{frame(0x40,['s0','s1','s2','s3','s4','s5'])}
move s0, a0
move s1, a1
move s2, a2
sltiu t0, s1, 2
beqz t0, no
nop
jal {hex(ticket.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, no
nop
la s5, {hex(STATE)}
lw t0, 8(s5)
bne t0, v0, no
nop
lw t0, 4(s5)
beqz t0, no
nop
lw t0, 0(s5)
beqz s2, no
nop
bne t0, s2, no
nop
addiu a0, s0, 4
lw a1, 12(s5)
lw a2, 8(s5)
jal {hex(FRESH)}
nop
beqz v0, no
nop
addiu s3, s5, {INTERIM_END}
addiu t0, s5, {SIZE}
scan:
lw t1, 0(s3)
beqz t1, allocate
nop
addiu s3, s3, 12
bne s3, t0, scan
nop
b no
nop
allocate:
addiu a0, zero, 4
jal 0x85b70
nop
beqz v0, no
nop
move s4, v0
addiu t0, zero, 0x20d
sh t0, 0(s4)
lw t0, 12(s5)
sb t0, 2(s4)
sb s1, 3(s4)
sw s4, 0(s3)
lw t0, 4(s5)
sw t0, 4(s3)
sw s2, 8(s3)
move a0, s4
jal 0x78bd4
nop
addiu v0, zero, 1
b done
nop
no:
move v0, zero
done:
{end(0x40,['s0','s1','s2','s3','s4','s5'])}
'''


def ack_profile():return f'''
{frame(0x40,['s0','s1','s2','s3','s4'])}
move s0, a0
jal {hex(ticket.CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, legacy
nop
lw s1, 12(s0)
la s2, {hex(STATE)}
addiu t0, s2, {INTERIM_END}
addiu t1, s2, {SIZE}
find:
lw t2, 0(t0)
beq t2, s1, found
nop
addiu t0, t0, 12
bne t0, t1, find
nop
b legacy
nop
found:
lw s3, 4(t0)
lw s4, 8(t0)
sw zero, 0(t0)
sw zero, 4(t0)
sw zero, 8(t0)
lw t0, 4(s2)
beqz t0, no
nop
bne t0, s3, no
nop
lw t0, 0(s2)
bne t0, s4, no
nop
lbu t0, 2(s1)
lw t1, 12(s2)
bne t0, t1, no
nop
addiu a0, s2, 16
lw a1, 12(s2)
lw a2, 8(s2)
jal {hex(FRESH)}
nop
beqz v0, no
nop
addiu a0, s0, 0x7c
addiu a1, zero, 0x10
lbu a2, 2(s1)
jal 0x8186c
nop
beqz v0, no
nop
lw t0, 0xf0(v0)
beqz t0, no
nop
lw t1, 16(t0)
bne t1, s3, no
nop
lhu t1, 0x18(t0)
lw t2, 8(s2)
bne t1, t2, no
nop
legacy:
move a0, s0
jal 0x52260
nop
b done
nop
no:
move v0, zero
done:
{end(0x40,['s0','s1','s2','s3','s4'])}
'''


def assembled():
    rows=[]
    for name,at,n,code in (('text_capture',CAPTURE,0x400,capture()),
                           ('text_response_parent',RESPONSE,0x800,response()),
                           ('text_interim_tag',POST,0x800,post()),
                           ('text_claim',CLAIM,0x800,claim()),
                           ('text_invalidate',INVALIDATE,0x400,invalidate()),
                           ('text_fresh_track',FRESH,0x400,fresh()),
                           ('text_ack_build',ACK_BUILD,0x800,ack_build()),
                           ('text_ack_profile',ACK_PROFILE,0x800,ack_profile())):
        raw,recipe,relocations=assemble(code,at,n)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    return rows


def sites(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw);result={}
    for at,before,after in ((ticket.SITE,ticket.FACTORY,CAPTURE),
                            (metadata.RESPONSE_SITE,metadata.ORIGINAL_RESPONSE,RESPONSE),
                            (metadata.POST_SITE,metadata.ORIGINAL_POST,POST)):
        assert pe.get_data(at-pe.OPTIONAL_HEADER.ImageBase,4)==struct.pack('<I',(3<<26)|(before>>2))
        result[at]=(3<<26)|(after>>2)
    return result
