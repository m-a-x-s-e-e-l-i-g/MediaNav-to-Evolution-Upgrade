"""Capture real legacy track requests on the original AVRCP scheduler.

The ordinary handler runs first and keeps its result. Only its existing scope-3,
0x7f current-track request supplies a selected peer/CID/UID snapshot. Messages
carry values, never borrowed peer/profile pointers. RESOLVE synchronously checks
the live native peer and copied lifetime identity before committing capabilities.
No PE/LGU is written; artwork-task actions and source transitions remain open.
"""
import hashlib
import struct

import pefile

import bt_cover_art_discovery as discovery
import bt_cover_art_metadata as metadata
import bt_cover_art_peer_identity as identity
import bt_cover_art_task as task
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

DROP, REQUEST, RESOLVE = 0x271400, 0x271800, 0x272400
PROFILE, SERIAL, SNAPSHOT = 0x269404, 0x269408, 0x269440
# Snapshot: serial32, peer_birth32, native_CID32, peer_ID32, BDADDR64, UID64.
SNAPSHOT_SIZE = 32
PRIMITIVE, MESSAGE_SIZE = 2, 32
REQUEST_TABLE, ORIGINAL_REQUEST = 0x101eb0, 0x53728
ORIGINAL_DROP, DROP_HIGH, DROP_LOW = 0x3bb6c, 0x2466c, 0x24678
PROFILE_QUEUE, CURRENT_QUEUE, MALLOC, POST = 0x218656, 0x85130, 0x8ad7c, 0x84ec8


def request():
    regs = ['s0', 's1', 's2', 's3', 's4', 's5']
    return f"""
{frame(0x50, regs)}
move s0, a0
jal {hex(ORIGINAL_REQUEST)}
nop
move s5, v0
# The parent dispatcher still owns the request until this wrapper returns.
beqz s0, done
nop
lw s1, 0xc(s0)
beqz s1, done
nop
lhu t0, 0(s1)
addiu t1, zero, 0x20c
bne t0, t1, done
nop
lbu t0, 5(s1)
addiu t1, zero, 3
bne t0, t1, done
nop
lw t0, 16(s1)
addiu t1, zero, 0x7f
bne t0, t1, done
nop
la t0, {hex(task.QUEUE)}
lhu t0, 0(t0)
lhu t1, 2(s1)
beq t0, t1, done
nop
jal {hex(CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, done
nop
la t0, {hex(PROFILE_QUEUE)}
lhu t0, 0(t0)
bne v0, t0, done
nop
addiu a0, s0, 0x7c
addiu a1, zero, 16
jal 0x8186c
lbu a2, 4(s1)
beqz v0, done
nop
move s2, v0
lw t0, 0x120(s2)
beqz t0, done
nop
lw t0, 0x18(s2)
beqz t0, done
nop
lbu t0, 0x1e(s2)
addiu t1, zero, 3
bne t0, t1, done
nop
# All readers/writers serialize on CSR segment zero. SERIAL never resets,
# including profile teardown; saturation disables optional selection capture.
la t0, {hex(SERIAL)}
lw t1, 0(t0)
addiu t2, zero, -1
beq t1, t2, exhausted
nop
addiu s3, t1, 1
sw s3, 0(t0)
la t0, {hex(PROFILE)}
sw s0, 0(t0)
la s4, {hex(SNAPSHOT)}
sw s3, 0(s4)
lw t0, 0x120(s2)
sw t0, 4(s4)
lw t0, 0x18(s2)
sw t0, 8(s4)
lbu t0, 4(s1)
sw t0, 12(s4)
lw t0, 8(s2)
sw t0, 16(s4)
lw t0, 12(s2)
sw t0, 20(s4)
addiu a0, s4, 24
addiu a1, s1, 6
jal 0x85758
addiu a2, zero, 8
# Snapshot survives optional post allocation failure; capabilities can arrive
# later via SDP. No optional message may be posted before task registration.
la t0, {hex(task.QUEUE)}
lhu t0, 0(t0)
sltiu t0, t0, 0x800
beqz t0, done
nop
jal {hex(MALLOC)}
addiu a0, zero, {MESSAGE_SIZE}
beqz v0, done
nop
move s1, v0
addiu t0, zero, {PRIMITIVE}
sh t0, 0(s1)
lw t0, 12(s4)
sh t0, 2(s1)
lw t0, 16(s4)
sw t0, 4(s1)
lw t0, 20(s4)
sw t0, 8(s1)
sw zero, 12(s1)
sw zero, 16(s1)
lw t0, 0x12c(s2)
addiu t1, zero, 1
bne t0, t1, no_capabilities
nop
lw t0, 0x124(s2)
sw t0, 12(s1)
lw t0, 0x128(s2)
sw t0, 16(s1)
no_capabilities:
lw t0, 4(s4)
sw t0, 20(s1)
lw t0, 8(s4)
sw t0, 24(s1)
sw s3, 28(s1)
la t0, {hex(task.QUEUE)}
lhu a0, 0(t0)
addiu a1, zero, {discovery.CLASS}
jal {hex(POST)}
move a2, s1
b done
nop
exhausted:
la t0, {hex(PROFILE)}
sw zero, 0(t0)
la t0, {hex(SNAPSHOT)}
sw zero, 0(t0)
done:
move v0, s5
{end(0x50, regs)}
"""


def drop():
    # Scheduler-wide quiescent shutdown, as required by the original DEINIT.
    # Clear the weak profile reference BEFORE native peer/profile destruction.
    return f"""
la t0, {hex(PROFILE)}
sw zero, 0(t0)
la t0, {hex(SNAPSHOT)}
sw zero, 0(t0)
sw zero, 4(t0)
sw zero, 8(t0)
sw zero, 12(t0)
sw zero, 16(t0)
sw zero, 20(t0)
sw zero, 24(t0)
sw zero, 28(t0)
la t9, {hex(ORIGINAL_DROP)}
jr t9
nop
"""


def resolve():
    # a0 writable output40: cap24, controlCID32, selectionSerial32, UID64.
    # Returns serial on success. Output remains untouched on any refusal.
    regs = ['s0', 's1', 's2', 's3']
    return f"""
{frame(0x50, regs)}
move s0, a0
beqz s0, bad
nop
andi t0, s0, 3
bnez t0, bad
nop
addiu t0, s0, 40
sltu t0, t0, s0
bnez t0, bad
nop
jal {hex(CURRENT_QUEUE)}
nop
sltiu t0, v0, 0x800
beqz t0, bad
nop
la t0, {hex(task.QUEUE)}
lhu t0, 0(t0)
bne t0, v0, bad
nop
la t0, {hex(PROFILE)}
lw s1, 0(t0)
beqz s1, bad
nop
la s2, {hex(SNAPSHOT)}
lw s3, 0(s2)
beqz s3, bad
nop
addiu a0, s1, 0x7c
addiu a1, zero, 16
jal 0x8186c
lw a2, 12(s2)
beqz v0, bad
nop
lw t0, 0x120(v0)
lw t1, 4(s2)
bne t0, t1, bad
nop
lw t0, 8(v0)
lw t1, 16(s2)
bne t0, t1, bad
nop
lw t0, 12(v0)
lw t1, 20(s2)
bne t0, t1, bad
nop
# Build an aligned local capability copy; MATCH checks CID/state/birth/caps.
addiu t0, zero, {discovery.PRIMITIVE}
sh t0, 0x10(sp)
lw t0, 12(s2)
sh t0, 0x12(sp)
lw t0, 16(s2)
sw t0, 0x14(sp)
lw t0, 20(s2)
sw t0, 0x18(sp)
lw t0, 0x124(v0)
sw t0, 0x1c(sp)
lw t0, 0x128(v0)
sw t0, 0x20(sp)
lw t0, 4(s2)
sw t0, 0x24(sp)
move a0, s1
addiu a1, sp, 0x10
lw a2, 12(s2)
jal {hex(identity.MATCH)}
lw a3, 8(s2)
beqz v0, bad
nop
# Retain OPEN's existing security policy. Do not silently weaken it to zero.
lhu t0, 0x1e(sp)
beqz t0, bad
nop
move a0, s0
addiu a1, sp, 0x10
jal 0x85758
addiu a2, zero, 24
lw t0, 8(s2)
sw t0, 24(s0)
sw s3, 28(s0)
lw t0, 24(s2)
sw t0, 32(s0)
lw t0, 28(s2)
sw t0, 36(s0)
move v0, s3
b done
nop
bad:
move v0, zero
done:
{end(0x50, regs)}
"""


def assembled():
    rows = metadata.assembled()+identity.assembled()
    assert len({r['address'] for r in rows}) == len(rows)
    for name, at, capacity, source in (
            ('selection_drop', DROP, 0x400, drop()),
            ('selection_request', REQUEST, 0xc00, request()),
            ('selection_resolve', RESOLVE, 0x1000, resolve())):
        raw, recipe, relocations = assemble(source, at, capacity)
        rows.append(dict(name=name, address=at, raw=raw, recipe=recipe, relocations=relocations))
    ordered = sorted(rows, key=lambda r:r['address'])
    for a,b in zip(ordered,ordered[1:]):
        assert a['address']+len(a['raw'])<=b['address'], 'Overlapping helper placements'
    return rows


def sites(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe = pefile.PE(data=raw)
    base = pe.OPTIONAL_HEADER.ImageBase
    expected = {REQUEST_TABLE: ORIGINAL_REQUEST, DROP_HIGH: 0x3c0a0004,
                DROP_LOW: 0x2546bb6c}
    for at, word in expected.items():
        if pe.get_data(at-base, 4) != struct.pack('<I', word):
            raise ValueError(f'Unexpected original selected request/deinit binding at {at:x}')
    result = metadata.sites(raw) | identity.sites(raw)
    result.update({REQUEST_TABLE: REQUEST, DROP_HIGH: 0x3c0a0000 | (DROP >> 16),
                   DROP_LOW: 0x25460000 | (DROP & 0xffff)})
    return result
