"""Native MIPS artwork session controller and interpreted task adapters.

Embeds 160 bytes after task/framer state; a checked handle allocates at most one
128 KiB body. All entries use the owning task's serialized context. Clock samples
are unsigned millisecond ticks, provided by an external binding. Metadata and GUI
callbacks are explicit unresolved integration boundaries, not installed calls.
No PE is written. Callback functions must not reenter; image bytes are borrowed.
"""
import bt_cover_art_task as task
import bt_cover_art_owner as owner
import bt_cover_art_framer as framer
import bt_cover_art_responses as responses
import bt_cover_art_native as codecs
from bt_cover_art_client import MAX_IMAGE
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

PREPARE, CONNECTED, PROCESS, METADATA = 0x250000, 0x251000, 0x252000, 0x253000
SELECT, TICK, FLUSH, CANCEL, DISPOSE = 0x254000, 0x255000, 0x256000, 0x257000, 0x258000
REQUEST_METADATA, PUBLISH, CLEAR = 0x259000, 0x259100, 0x259200
CONNECT_CODEC, GET_CODEC, ATTRIBUTE_CODEC = 0x24f000, 0x24f400, 0x24f800
OFFSET, SIZE = task.SIZE, 160
TASK_SIZE = OFFSET+SIZE
MALLOC = 0x8ad7c  # Same allocator used by 0x85b70; skip its 0x85f50 fatal wrapper.
OFF, OPENING, CONNECT, META, GET, READY, FAILED = range(7)
# Embedded fields: phase0 owner4 channel8 track12 now16 started20 timeout24
# queued_len28 awaiting_response32 published36 obex_cid40 obex_mopl44 spare48/52
# handle56[8], collection64[32], tx96[64]. Generation counters never wrap/reuse.
REGS = ['s0','s1','s2','s3']


def fail_return(register='s0'):
    return f'''failed:
move a0, {register}
jal {hex(CANCEL)}
nop
refused:
move v0, zero
b done
nop'''


DISPOSE_CODE = f'''
{frame(0x30, ['s0','s1'])}
move s0, a0
beqz s0, done
nop
addiu s1, s0, {OFFSET}
lw t0, 36(s1)
sw zero, 36(s1)
beqz t0, release
nop
move a0, s0
lw a1, 8(s1)
lw a2, 12(s1)
jal {hex(CLEAR)}
nop
release:
lw a0, 64(s1)
sw zero, 64(s1)
beqz a0, cleared
nop
jal 0x85bb8
nop
cleared:
sw zero, 0(s1)
sw zero, 28(s1)
sw zero, 32(s1)
sw zero, 40(s1)
sw zero, 44(s1)
addiu t0, s1, 64
addiu t1, s1, 96
zero_collection:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, zero_collection
nop
done:
addiu v0, zero, 1
{end(0x30, ['s0','s1'])}
'''

CANCEL_CODE = f'''
{frame(0x20, ['s0'])}
move s0, a0
beqz s0, done
nop
jal {hex(DISPOSE)}
nop
addiu t0, zero, {FAILED}
sw t0, {OFFSET}(s0)
move a0, s0
jal {hex(owner.STOP)}
nop
done:
move v0, zero
{end(0x20, ['s0'])}
'''

PREPARE_CODE = f'''
{frame(0x30, REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
beqz s0, refused
nop
beqz s1, refused
nop
beqz s2, refused
nop
lw t0, 0(s0)
bnez t0, refused
nop
lw t0, 24(s0)
addiu t1, zero, 2
bne t0, t1, refused
nop
lw t0, {OFFSET}(s0)
bnez t0, refused
nop
lw t0, {OFFSET+8}(s0)
sltu t0, t0, s1
beqz t0, refused
nop
move a0, s0
jal {hex(DISPOSE)}
nop
addiu t0, s0, {OFFSET}
addiu t1, zero, {OPENING}
sw t1, 0(t0)
sw s0, 4(t0)
sw s1, 8(t0)
sw s2, 12(t0)
sw s3, 16(t0)
sw s3, 20(t0)
addiu t1, zero, 2000
sw t1, 24(t0)
addiu v0, zero, 1
b done
nop
refused:
move v0, zero
done:
{end(0x30, REGS)}
'''

TICK_CODE = f'''
{frame(0x20, ['s0'])}
move s0, a0
beqz s0, refused
nop
addiu t0, s0, {OFFSET}
lw t1, 0(t0)
addiu t2, zero, {FAILED}
beq t1, t2, refused
nop
beqz t1, update
nop
lw t2, 16(t0)
subu t2, a1, t2
lui t3, 0x8000
sltu t2, t2, t3
beqz t2, failed
nop
addiu t2, zero, {READY}
beq t1, t2, update
nop
lw t2, 20(t0)
subu t2, a1, t2
lw t3, 24(t0)
sltu t2, t2, t3
beqz t2, failed
nop
update:
sw a1, 16(t0)
addiu v0, zero, 1
b done
nop
{fail_return()}
done:
{end(0x20, ['s0'])}
'''

CONNECTED_CODE = f'''
{frame(0x30, ['s0','s1'])}
move s0, a0
beqz s0, refused
nop
lw t0, 0(s0)
addiu t1, zero, {owner.ACTIVE}
bne t0, t1, failed
nop
addiu s1, s0, {OFFSET}
lw t0, 0(s1)
addiu t1, zero, {OPENING}
bne t0, t1, failed
nop
lw a1, 16(s1)
jal {hex(TICK)}
nop
beqz v0, refused
nop
addiu a0, s1, 96
addiu a1, zero, 64
jal {hex(CONNECT_CODEC)}
nop
beqz v0, failed
nop
sw v0, 28(s1)
sw zero, 32(s1)
addiu t0, zero, {CONNECT}
sw t0, 0(s1)
lw t0, 16(s1)
sw t0, 20(s1)
addiu t0, zero, 2000
sw t0, 24(s1)
addiu v0, zero, 1
b done
nop
{fail_return()}
done:
{end(0x30, ['s0','s1'])}
'''

FLUSH_CODE = f'''
{frame(0x30, ['s0','s1'])}
move s0, a0
beqz s0, refused
nop
addiu s1, s0, {OFFSET}
lw t0, 0(s1)
beqz t0, success
nop
addiu t1, zero, {FAILED}
beq t0, t1, refused
nop
lw t1, 0(s0)
addiu t2, zero, {owner.CLOSING}
beq t1, t2, failed
nop
addiu t2, zero, {owner.CANCELLED}
beq t1, t2, failed
nop
lw a1, 16(s1)
move a0, s0
jal {hex(TICK)}
nop
beqz v0, refused
nop
lw a2, 28(s1)
beqz a2, success
nop
lw t0, 0(s0)
addiu t1, zero, {owner.ACTIVE}
bne t0, t1, failed
nop
lhu t0, 28(s0)
bnez t0, success
nop
move a0, s0
addiu a1, s1, 96
jal {hex(task.SEND)}
nop
beqz v0, failed
nop
sw zero, 28(s1)
addiu t0, zero, 1
sw t0, 32(s1)
success:
addiu v0, zero, 1
b done
nop
{fail_return()}
done:
{end(0x30, ['s0','s1'])}
'''

PROCESS_CODE = f'''
{frame(0x40, REGS)}
move s0, a0
move s2, a1
move s3, a2
beqz s0, refused
nop
lw t0, 0(s0)
addiu t1, zero, {owner.ACTIVE}
bne t0, t1, failed
nop
addiu s1, s0, {OFFSET}
lw a1, 16(s1)
jal {hex(TICK)}
nop
beqz v0, refused
nop
lw t0, 32(s1)
beqz t0, failed
nop
lw t0, 28(s1)
bnez t0, failed
nop
lw t0, 0(s1)
addiu t1, zero, {CONNECT}
beq t0, t1, handshake
nop
addiu t1, zero, {GET}
bne t0, t1, failed
nop
addiu a0, s1, 64
move a1, s2
move a2, s3
jal {hex(responses.GET)}
nop
addiu t0, zero, 1
beq v0, t0, continuing
nop
addiu t0, zero, 2
bne v0, t0, failed
nop
sw zero, 32(s1)
addiu t0, zero, {READY}
sw t0, 0(s1)
addiu t0, zero, 1
sw t0, 36(s1)
move a0, s0
lw a1, 8(s1)
lw a2, 12(s1)
lw a3, 64(s1)
lw t0, 72(s1)
sw t0, 0x10(sp)
jal {hex(PUBLISH)}
nop
beqz v0, failed
nop
b success
nop
continuing:
# Continuations retain the original ten-second transfer start/deadline.
addiu t0, zero, 0x83
sb t0, 96(s1)
sb zero, 97(s1)
addiu t0, zero, 8
sb t0, 98(s1)
addiu t0, zero, 0xcb
sb t0, 99(s1)
lw t0, 40(s1)
srl t1, t0, 24
sb t1, 100(s1)
srl t1, t0, 16
sb t1, 101(s1)
srl t1, t0, 8
sb t1, 102(s1)
sb t0, 103(s1)
addiu t0, zero, 8
sw t0, 28(s1)
sw zero, 32(s1)
b success
nop
handshake:
move a0, s2
move a1, s3
addiu a2, s1, 40
jal {hex(responses.CONNECT)}
nop
addiu t0, zero, 1
bne v0, t0, failed
nop
sw zero, 32(s1)
addiu t0, zero, {META}
sw t0, 0(s1)
lw t0, 16(s1)
sw t0, 20(s1)
addiu t0, zero, 3000
sw t0, 24(s1)
move a0, s0
lw a1, 8(s1)
lw a2, 12(s1)
jal {hex(REQUEST_METADATA)}
nop
beqz v0, failed
nop
success:
addiu v0, zero, 1
b done
nop
{fail_return()}
done:
{end(0x40, REGS)}
'''

METADATA_CODE = f'''
{frame(0x40, REGS)}
move s0, a0
move s2, a3
lw s3, 0x50(sp)
beqz s0, refused
nop
lw t0, 0(s0)
addiu t1, zero, {owner.ACTIVE}
bne t0, t1, refused
nop
addiu s1, s0, {OFFSET}
lw t0, 0(s1)
addiu t1, zero, {META}
bne t0, t1, refused
nop
lw t0, 8(s1)
bne a1, t0, refused
nop
lw t0, 12(s1)
bne a2, t0, refused
nop
lw a1, 16(s1)
jal {hex(TICK)}
nop
beqz v0, refused
nop
move a0, s2
move a1, s3
addiu a2, s1, 56
addiu a3, zero, 8
jal {hex(ATTRIBUTE_CODEC)}
nop
beqz v0, no_art
nop
addiu t0, zero, 1
bne v0, t0, failed
nop
la a0, {MAX_IMAGE}
jal {hex(MALLOC)}
nop
beqz v0, failed
nop
sw v0, 64(s1)
la t0, {MAX_IMAGE}
sw t0, 68(s1)
sw zero, 72(s1)
sw zero, 76(s1)
sw zero, 80(s1)
sw zero, 84(s1)
lw t0, 40(s1)
sw t0, 88(s1)
sw zero, 92(s1)
addiu a0, s1, 96
addiu a1, zero, 64
lw a2, 40(s1)
addiu a3, s1, 56
jal {hex(GET_CODEC)}
nop
beqz v0, failed
nop
lw t0, 44(s1)
sltu t0, t0, v0
bnez t0, failed
nop
sw v0, 28(s1)
sw zero, 32(s1)
lw t0, 16(s1)
sw t0, 20(s1)
addiu t0, zero, 10000
sw t0, 24(s1)
addiu t0, zero, {GET}
sw t0, 0(s1)
b success
nop
no_art:
addiu t0, zero, {READY}
sw t0, 0(s1)
sw zero, 32(s1)
success:
addiu v0, zero, 1
b done
nop
{fail_return()}
done:
{end(0x40, REGS)}
'''

SELECT_CODE = f'''
{frame(0x40, REGS)}
move s0, a0
move s2, a2
move s3, a3
beqz s0, refused
nop
addiu s1, s0, {OFFSET}
lw t0, 0(s1)
beqz t0, refused
nop
addiu t1, zero, {FAILED}
beq t0, t1, refused
nop
lw t0, 8(s1)
bne a1, t0, refused
nop
lw t0, 12(s1)
beq s2, t0, success
nop
sltu t0, t0, s2
beqz t0, refused
nop
lw t0, 0(s1)
addiu t1, zero, {READY}
beq t0, t1, refresh
nop
addiu t1, zero, {META}
beq t0, t1, refresh
nop
move a0, s0
jal {hex(CANCEL)}
nop
sw s2, 12(s1)
b refused
nop
refresh:
move a0, s0
move a1, s3
jal {hex(TICK)}
nop
beqz v0, refused
nop
move a0, s0
jal {hex(DISPOSE)}
nop
sw s2, 12(s1)
sw s3, 16(s1)
sw s3, 20(s1)
# DISPOSE clears wire identity; restore it across a successful track refresh.
lw t0, 0x18(sp)
sw t0, 40(s1)
lw t0, 0x1c(sp)
sw t0, 44(s1)
addiu t0, zero, 3000
sw t0, 24(s1)
addiu t0, zero, {META}
sw t0, 0(s1)
move a0, s0
lw a1, 8(s1)
move a2, s2
jal {hex(REQUEST_METADATA)}
nop
beqz v0, failed
nop
success:
addiu v0, zero, 1
b done
nop
{fail_return()}
done:
{end(0x40, REGS)}
'''
# Save the BIP identity before DISPOSE clears it; locals do not overlap saved regs.
SELECT_CODE = SELECT_CODE.replace('refresh:\n', 'refresh:\nlw t0, 40(s1)\nsw t0, 0x18(sp)\nlw t0, 44(s1)\nsw t0, 0x1c(sp)\n')

NOTIFY_CODE = f'''
addiu t0, zero, 2
beq a1, t0, receive
nop
sw zero, {owner.SIZE}(a0)
addiu t0, zero, 1
bne a1, t0, closed
nop
la t9, {hex(CONNECTED)}
jr t9
nop
closed:
la t9, {hex(DISPOSE)}
jr t9
nop
receive:
addiu a0, a0, {owner.SIZE}
move a1, a2
move a2, a3
la t9, {hex(framer.ENTRY)}
jr t9
nop
'''
PACKET_CODE = f'''
addiu a0, a0, -{owner.SIZE}
la t9, {hex(PROCESS)}
jr t9
nop
'''

HELPERS = ((PREPARE, PREPARE_CODE, 'Prepare a strictly newer channel/track generation before opening'),
           (CONNECTED, CONNECTED_CODE, 'Queue BIP CONNECT on accepted channel; two-second deadline'),
           (PROCESS, PROCESS_CODE, 'Native handshake/GET transitions, continuations and borrowed image publication'),
           (METADATA, METADATA_CODE, 'Accept matching fresh attribute-8 ticket and queue thumbnail GET'),
           (SELECT, SELECT_CODE, 'Refresh idle track metadata; cancel mid-transfer and invalidate old generation'),
           (TICK, TICK_CODE, 'Unsigned millisecond deadlines, wrap handling and clock-reversal rejection'),
           (FLUSH, FLUSH_CODE, 'Send queued packet only when native transport credit is available'),
           (CANCEL, CANCEL_CODE, 'Invalidate, clear/free body and request channel cancellation'),
           (DISPOSE, DISPOSE_CODE, 'Clear published image before releasing body; preserve generation history'))


def assembled():
    rows=[]
    specs=[(at,0x1000,code,purpose) for at,code,purpose in HELPERS]
    specs += [(owner.NOTIFY,0x100,NOTIFY_CODE,'Controller lifecycle and receive adapter'),
              (framer.PACKET,0x100,PACKET_CODE,'Native packet consumer adapter'),
              (CONNECT_CODEC,0x400,codecs.CONNECT_CODE,'Relocated bounded CONNECT codec'),
              (GET_CODEC,0x400,codecs.THUMBNAIL_CODE,'Relocated bounded thumbnail GET codec'),
              (ATTRIBUTE_CODEC,0x800,codecs.ATTRIBUTE_CODE,'Relocated bounded attribute-8 parser'),
              (task.INIT,0x400,task.INIT_CODE.replace(str(task.SIZE),str(TASK_SIZE)).replace('jal 0x85b70',f'jal {hex(MALLOC)}'),
               'Extended zeroed task allocation; original registration constructor'),
              (task.SEND,0x400,task.SEND_CODE.replace('jal 0x85b70',f'jal {hex(MALLOC)}'),
               'Retain copied send and context checks; recoverable allocation for the new copy'),
              (task.HANDLE,0x400,task.HANDLE_CODE.replace('done:\nmove v0, zero',
                   f'done:\nmove a0, s0\njal {hex(FLUSH)}\nnop\nmove v0, zero'),
               'Retain original dispatch and pump deferred sends after callbacks'),
              (task.DEINIT,0x400,task.DEINIT_CODE.replace('drained:\n',
                   f'drained:\nlw a0, 0(s0)\njal {hex(DISPOSE)}\nnop\n'),
               'Quiescent task drain; dispose body before owner allocation')]
    for at,capacity,code,purpose in specs:
        raw,recipe,relocations=assemble(code,at,capacity)
        rows.append(dict(address=at,raw=raw,recipe=recipe,relocations=relocations,purpose=purpose))
    return rows
