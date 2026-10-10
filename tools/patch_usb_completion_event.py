"""Checked completion progress and one duration snapshot; pinned PR-32 input."""
import hashlib
import struct

import pefile

from patch_shared_mapping_checks import reloc_records
from patch_usb_seek_completion import assemble

BASE = 0x10000
BASE_SHA = '0e4ffb0cb8ce2480a8ecfc178f05d2fdcbde6ef6b67c9554efc8d211ad0fb19f'
PROGRESS_GATE = 0x407B0
HELPERS = ((PROGRESS_GATE, 0x30, """
bltz s0, unavailable
nop
la t9, 0x231a4
jr t9
nop
unavailable:
la t9, 0x11d08
jr t9
nop
""", 'Unavailable first progress skips the clock setter through the event owner; valid zero is preserved', 0),)
SITES = (
    (0x11CF4, 4, 'jal 0x407b0'),
    (0x11D38, 8, 'nop\nnop'),
)

def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected the exact PR-32 duration-output candidate')
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
            raise ValueError('Occupied completion-event helper space')
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
    edit(BASE+directory.VirtualAddress, table, 'Add completion-event helper row')
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
         'Updated duration-output relocations')
    edit_offset(directory.get_file_offset()+4, struct.pack('<I', len(table)), 'Relocation-table size')
    result = bytes(out)
    restored = bytearray(result)
    for e in edits:
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    if restored != raw: raise ValueError('Undeclared changed bytes')
    return result, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits, added_pdata_rows=added_rows,
                        native_executed=False, hardware_tested=False)
