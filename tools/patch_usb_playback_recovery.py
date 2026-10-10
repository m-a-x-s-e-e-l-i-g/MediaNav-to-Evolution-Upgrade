"""Confirmed Stop publication and checked resume/reload seeks; pinned PR-30 input."""
import hashlib
import struct

import pefile

from patch_shared_mapping_checks import reloc_records
from patch_usb_seek_completion import assemble

BASE = 0x10000
BASE_SHA = 'ad4f40460a7a70f203eb5f3c91a87e303a5d94c7c691197eeb205001e7349b09'
STOP_STATUS, INITIAL_SEEK, RELOAD_GATE, RELOAD_SEEK = 0x40740, 0x40A80, 0x40B40, 0x404C0
POSITION_INIT, POSITION_RESULT = 0x40B68, 0x40520

HELPERS = (
    (STOP_STATUS, 0xC0, """
addiu sp, sp, -0x20
sw ra, 0x1c(sp)
beqz s0, finish
nop
addiu a1, zero, 3
jal 0x1ae54
move a0, s1
addiu a1, zero, 0
jal 0x19864
move a0, s1
finish:
lw ra, 0x1c(sp)
addiu sp, sp, 0x20
la t9, 0x1afa4
jr t9
nop
""", 'Stop publishes stopped status and resets display only after positive manager completion', 8),
    (INITIAL_SEEK, 0x80, """
addiu sp, sp, -0x20
sw ra, 0x1c(sp)
lwl t0, 3(s1)
lwr t0, 0(s1)
sw t0, 0x34(sp)
blez v0, refresh
nop
beqz zero, done
nop
refresh:
jal 0x1b3b0
move a0, s2
done:
lw ra, 0x1c(sp)
addiu sp, sp, 0x20
la t9, 0x1144c
jr t9
nop
""", 'Resume refreshes confirmed progress after failed seek and preserves the requested reload position in its unused +14 stack slot', 8),
    (RELOAD_GATE, 0x28, """
blez v0, failed
nop
la t9, 0x1144c
jr t9
nop
failed:
la t9, 0x1ceec
jr t9
nop
""", 'Failed ordinary-play reload skips its subsequent seek through the resume owner', 0),
    (RELOAD_SEEK, 0x60, """
addiu sp, sp, -0x20
sw ra, 0x1c(sp)
sw s0, 0x18(sp)
jal 0x1111c
nop
move s0, v0
blez v0, refresh
nop
beqz zero, done
nop
refresh:
jal 0x1b3b0
move a0, s2
lw t0, 0x2940(s2)
swl t0, 0xe7f(s2)
swr t0, 0xe7c(s2)
done:
move v0, s0
lw s0, 0x18(sp)
lw ra, 0x1c(sp)
addiu sp, sp, 0x20
jr ra
nop
""", 'After failed reload seeking, refresh checked progress and align cached resume time to the retained display if the getter also fails', 12),
    (POSITION_INIT, 0x18, """
addiu t0, zero, -1
sw t0, 0x10(sp)
sw t0, 0x14(sp)
jr ra
sw t0, 0x1c(sp)
""", 'Initialize position and duration high DWORDs to unavailable in the getter owner frame', 0),
    (POSITION_RESULT, 0xA0, """
bltz v0, failed
nop
lw t0, 0x14(sp)
bltz t0, failed
nop
jr ra
nop
failed:
la t9, 0x11258
jr t9
nop
""", 'Reject failed HRESULT, unwritten or negative current position through the getter owner', 0),
)
SITES = (
    (0x11264, 8, 'jal 0x40b68\nnop'),
    (0x11270, 4, 'nop'),
    (0x11284, 8, 'jal 0x40520\nnop'),
    (0x1AF74, 12, 'nop\nnop\nnop'),
    (0x1AF9C, 4, 'jal 0x40740'),
    (0x1CE7C, 4, 'jal 0x40a80'),
    (0x1CEC0, 4, 'lw s0, 0x14(sp)'),
    (0x1CECC, 4, 'nop'),
    (0x1CED8, 4, 'jal 0x40b40'),
    (0x1CEE4, 4, 'jal 0x404c0'),
)

def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected the exact PR-30 playback-start candidate')
    pe = pefile.PE(data=raw)
    out, edits, relocations = bytearray(raw), [], []

    def capacity(rva, size):
        section = pe.get_section_by_rva(rva)
        if section is None or not (section.VirtualAddress <= rva and
                rva+size <= section.VirtualAddress+section.SizeOfRawData):
            raise ValueError('Edit exceeds existing section raw capacity')

    def edit_offset(off, new, reason, **extra):
        old = raw[off:off+len(new)]
        if len(old) != len(new): raise ValueError('Edit outside existing file')
        if any(off < e['offset']+e['bytes'] and e['offset'] < off+len(new) for e in edits):
            raise ValueError('Overlapping edits')
        out[off:off+len(new)] = new
        edits.append(dict(offset=off, bytes=len(new), before_hex=old.hex(),
                          after_hex=new.hex(), reason=reason, **extra))

    def edit(at, new, reason, **extra):
        capacity(at-BASE, len(new))
        edit_offset(pe.get_offset_from_rva(at-BASE), new, reason, va=hex(at), **extra)

    def block(at, cap, code, reason):
        new, recipe, added = assemble(code, at, cap)
        edit(at, new, reason, assembly=recipe)
        relocations.extend(added)
        return recipe

    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    original_rows = [struct.unpack_from('<5I', pe.get_data(directory.VirtualAddress, directory.Size), i)
                     for i in range(0, directory.Size, 20)]
    added_rows = []
    for at, cap, code, reason, prologue in HELPERS:
        if pe.get_data(at-BASE, cap) != bytes(cap):
            raise ValueError('Occupied playback-recovery helper space')
        if any(at < r[1] and r[0] < at+cap for r in original_rows):
            raise ValueError('Helper overlaps a previous function')
        recipe = block(at, cap, code, reason)
        added_rows.append((at, at+recipe['used_bytes'], 0, 0, at+prologue))
    for at, cap, code in SITES:
        block(at, cap, code, 'Check playback recovery at '+hex(at))
    rows = sorted(original_rows+added_rows)
    if any(a[1] > b[0] for a, b in zip(rows, rows[1:])):
        raise ValueError('Overlapping exception rows')
    table = b''.join(struct.pack('<5I', *row) for row in rows)
    capacity(directory.VirtualAddress, len(table))
    if any(pe.get_data(directory.VirtualAddress+directory.Size, len(table)-directory.Size)):
        raise ValueError('Occupied exception-table expansion')
    edit(BASE+directory.VirtualAddress, table, 'Add Stop/resume helper rows')
    edit_offset(directory.get_file_offset()+4, struct.pack('<I', len(table)), 'Exception-table size')
    for i, row in enumerate(rows):
        for j, value in enumerate(row):
            if value: relocations.append((directory.VirtualAddress+i*20+j*4, 3, None))
    spans = [(e['offset'], e['offset']+e['bytes']) for e in edits]
    previous = [r for r in reloc_records(pe)
                if not any(a <= pe.get_offset_from_rva(r[0]) < b for a, b in spans)]
    combined = sorted(previous+relocations)
    if len({r[0] for r in combined}) != len(combined): raise ValueError('Duplicate relocations')
    pages = {}
    for at, kind, companion in combined:
        page = at & ~4095
        pages.setdefault(page, []).append((kind << 12) | (at-page))
        if kind == 4: pages[page].append(companion)
    table = bytearray()
    for page, values in sorted(pages.items()):
        if len(values) % 2: values.append(0)
        table.extend(struct.pack('<II', page, 8+len(values)*2))
        table.extend(struct.pack('<'+'H'*len(values), *values))
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    capacity(directory.VirtualAddress, max(len(table), directory.Size))
    if len(table) > directory.Size and any(pe.get_data(directory.VirtualAddress+directory.Size,
                                                       len(table)-directory.Size)):
        raise ValueError('Occupied relocation-table expansion')
    edit(BASE+directory.VirtualAddress, bytes(table)+bytes(max(0, directory.Size-len(table))),
         'Updated playback-recovery relocations')
    edit_offset(directory.get_file_offset()+4, struct.pack('<I', len(table)), 'Relocation-table size')
    result = bytes(out)
    restored = bytearray(result)
    for e in edits:
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    if restored != raw: raise ValueError('Undeclared changed bytes')
    return result, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits, added_pdata_rows=added_rows,
                        native_executed=False, hardware_tested=False)
