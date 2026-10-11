"""Native per-peer artwork identity, appended to the retained CSR allocation.

No PE/LGU is written. Preserve the original 0x120-byte peer prefix and list
ownership. A non-reused birth serial rejects capabilities from a freed/reused
peer object; control-CID and selected-phone integration remain necessary.
"""
import hashlib
import struct

import pefile

import bt_cover_art_discovery as discovery
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

ALLOCATE, CAPTURE, MATCH = 0x270000, 0x270400, 0x270c00
COUNTER = 0x269400
SITE, ORIGINAL_ALLOCATE = 0x569c4, 0x814a0
PREFIX, SIZE = 0x120, 0x130
# Appended fields: generation32+120, PSM16+124, security16+126,
# version16+128, features16+12a, capabilities_valid32+12c.
# COUNTER belongs exclusively to serialized CSR segment zero. Never reset while
# any peer or posted message can survive; saturating it disables optional artwork.


def allocator():
    regs = ['s0', 's1']
    return f"""
{frame(0x30, regs)}
move s0, a0
move s1, a1
addiu t0, zero, {PREFIX}
bne s1, t0, original
nop
addiu a1, zero, {SIZE}
jal {hex(ORIGINAL_ALLOCATE)}
nop
beqz v0, done
nop
sw zero, 0x120(v0)
sw zero, 0x124(v0)
sw zero, 0x128(v0)
sw zero, 0x12c(v0)
la t0, {hex(COUNTER)}
lw t1, 0(t0)
addiu t2, zero, -1
beq t1, t2, done
nop
addiu t1, t1, 1
sw t1, 0(t0)
sw t1, 0x120(v0)
b done
nop
original:
move a0, s0
jal {hex(ORIGINAL_ALLOCATE)}
move a1, s1
done:
{end(0x30, regs)}
"""


def capture():
    code = discovery.capture()
    needle = 'beqz s2, bad\nnop\n'
    assert code.count(needle) == 1
    code = code.replace(needle, needle+"""lw t0, 0x120(s2)
beqz t0, bad
nop
# A new discovery result supersedes the previous optional capabilities.
sw zero, 0x124(s2)
sw zero, 0x128(s2)
sw zero, 0x12c(s2)
""", 1)
    needle = 'move s3, v0\njal 0x8ad7c'
    assert needle in code
    code = code.replace(needle, """move s3, v0
sh s3, 0x124(s2)
sh s4, 0x126(s2)
lhu t0, 0xc8(s2)
sh t0, 0x128(s2)
lhu t0, 0xca(s2)
sh t0, 0x12a(s2)
addiu t0, zero, 1
sw t0, 0x12c(s2)
jal 0x8ad7c""", 1)
    needle = 'sw zero, 20(s0)'
    assert needle in code
    code = code.replace(needle, 'lw t0, 0x120(s2)\nsw t0, 20(s0)', 1)
    return code


def matcher():
    regs = ['s0', 's1', 's2', 's3']
    # a0 borrowed live profile, a1 owned 24-byte capability message,
    # a2 selected peer ID, a3 selected native control CID. Called only in
    # serialized CSR segment zero. Return a borrowed peer for synchronous use.
    return f"""
{frame(0x30, regs)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
beqz s0, bad
nop
beqz s1, bad
nop
beqz s3, bad
nop
sltiu t0, s2, 256
beqz t0, bad
nop
lhu t0, 0(s1)
addiu t1, zero, {discovery.PRIMITIVE}
bne t0, t1, bad
nop
lhu t0, 2(s1)
bne t0, s2, bad
nop
addiu a0, s0, 0x7c
addiu a1, zero, 16
jal 0x8186c
move a2, s2
beqz v0, bad
nop
lw t0, 0x120(v0)
beqz t0, bad
nop
lw t1, 20(s1)
bne t0, t1, bad
nop
lw t0, 8(v0)
lw t1, 4(s1)
bne t0, t1, bad
nop
lw t0, 12(v0)
lw t1, 8(s1)
bne t0, t1, bad
nop
lw t0, 0x18(v0)
bne t0, s3, bad
nop
lbu t0, 0x1e(v0)
addiu t1, zero, 3
bne t0, t1, bad
nop
lw t0, 0x12c(v0)
addiu t1, zero, 1
bne t0, t1, bad
nop
lw t0, 0x124(v0)
lw t1, 12(s1)
bne t0, t1, bad
nop
lw t0, 0x128(v0)
lw t1, 16(s1)
bne t0, t1, bad
nop
b done
nop
bad:
move v0, zero
done:
{end(0x30, regs)}
"""


def assembled():
    rows = discovery.assembled()
    rows = [r for r in rows if r['address'] != discovery.CAPTURE]
    for name, address, capacity, source in (
            ('peer_allocate', ALLOCATE, 0x400, allocator()),
            ('peer_capture', CAPTURE, 0x800, capture()),
            ('peer_match', MATCH, 0x800, matcher()),
            ('capture_forward', discovery.CAPTURE, 0x800, f'la t9, {hex(CAPTURE)}\njr t9\nnop')):
        raw, recipe, relocations = assemble(source, address, capacity)
        rows.append(dict(name=name, address=address, raw=raw, recipe=recipe, relocations=relocations))
    return rows


def sites(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe = pefile.PE(data=raw)
    before = pe.get_data(SITE-pe.OPTIONAL_HEADER.ImageBase, 8)
    if before != struct.pack('<II', (3 << 26) | (ORIGINAL_ALLOCATE >> 2), 0x02002025):
        raise ValueError('Unexpected retained peer allocator call/delay slot')
    discovery.hook_recipe(raw)
    return {SITE: (3 << 26) | (ALLOCATE >> 2),
            discovery.SITE: (3 << 26) | (discovery.WRAP >> 2)}
