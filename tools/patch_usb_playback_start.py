"""Bounded cleanup after failed COM Run; route ordinary play to its error path."""
import hashlib
import struct

import pefile

from patch_shared_mapping_checks import reloc_records
from patch_usb_seek_completion import assemble

BASE = 0x10000
BASE_SHA = '0998774c8997bf694c2be7dbdf2710dcc08e989ee3774190d3da91370210dc10'
CLEANUP, GATE = 0x40400, 0x405C0

HELPERS = (
    (CLEANUP, 0x1C0, """
addiu sp, sp, -0x20
sw ra, 0x1c(sp)
sw s0, 0x18(sp)
la t0, 0x2f96c
sw zero, 0(t0)
lw t0, 4(s1)
beqz t0, missing_control
nop
jal 0x40600
move a0, s1
beqz zero, canceled
move s0, v0
missing_control:
move s0, zero
canceled:
jal 0x231a4
nop
lw a0, 0x3c(v0)
beqz a0, after_timer
nop
jal 0x2517c
addiu a1, zero, 1000
after_timer:
beqz s0, finish
nop
jal 0x231a4
nop
lw a0, 0x4c(v0)
beqz a0, finish
nop
addiu a1, zero, 3
jal 0x1ae54
addiu a0, a0, 8
addiu a3, zero, 0
addiu a2, zero, 0x66
addiu a1, zero, 0x15
addiu a0, zero, 5
jal 0x23580
sw zero, 0x10(sp)
finish:
lw s0, 0x18(sp)
lw ra, 0x1c(sp)
addiu sp, sp, 0x20
la t9, 0x114c4
jr t9
nop
""", 'Failed COM start invalidates readiness, attempts bounded teardown and cancels progress; stopped UI requires confirmed cleanup'),
    (GATE, 0x40, """
beqz v0, failed
nop
la t9, 0x1c9fc
jr t9
nop
failed:
la t9, 0x1ca98
jr t9
nop
""", 'Ordinary play follows existing error handling after failed manager start'),
)
SITES = ((0x11540, 4, 'jal 0x40400'), (0x1C918, 4, 'jal 0x405c0'))


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected the exact PR-29 seek-completion candidate')
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
    for at, cap, code, reason in HELPERS:
        if pe.get_data(at-BASE, cap) != bytes(cap):
            raise ValueError('Occupied playback-start helper space')
        if any(at < r[1] and r[0] < at+cap for r in original_rows):
            raise ValueError('Helper overlaps a previous function')
        recipe = block(at, cap, code, reason)
        added_rows.append((at, at+recipe['used_bytes'], 0, 0, at+(12 if at == CLEANUP else 0)))
    for at, cap, code in SITES:
        block(at, cap, code, 'Check playback start at '+hex(at))
    rows = sorted(original_rows+added_rows)
    if any(a[1] > b[0] for a, b in zip(rows, rows[1:])):
        raise ValueError('Overlapping exception rows')
    table = b''.join(struct.pack('<5I', *row) for row in rows)
    capacity(directory.VirtualAddress, len(table))
    if any(pe.get_data(directory.VirtualAddress+directory.Size, len(table)-directory.Size)):
        raise ValueError('Occupied exception-table expansion')
    edit(BASE+directory.VirtualAddress, table, 'Add framed cleanup and leaf result-gate rows')
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
         'Updated playback-start relocations')
    edit_offset(directory.get_file_offset()+4, struct.pack('<I', len(table)), 'Relocation-table size')
    result = bytes(out)
    restored = bytearray(result)
    for e in edits:
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    if restored != raw: raise ValueError('Undeclared changed bytes')
    return result, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits, added_pdata_rows=added_rows,
                        native_executed=False, hardware_tested=False)
