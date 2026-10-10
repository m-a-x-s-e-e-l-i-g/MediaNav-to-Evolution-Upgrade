"""Check graphics context/selection and safely dispose a failed album render."""
import hashlib
import struct

import pefile

from patch_shared_mapping_checks import reloc_records
from patch_usb_seek_completion import assemble

BASE_SHA = '17429970a90f6286b5850cbb9cb61b6e07d219c003beb748f70f5d4ee5cf4fa4'
SITE, CAPACITY = 0x1a4a0, 0xa0
CODE = '''
move s3, v0
move a1, s0
jal 0x251ac
move a0, s4
beqz v0, restore_failed
nop
bltz s3, failed
nop
lw a0, 0x20(sp)
lw a1, 0x2c(sp)
jal 0x3c800
lw a2, 0x30(sp)
b 0x1a540
nop
failed:
jal 0x2516c
move a0, s5
b 0x1a540
move s5, zero
restore_failed:
jal 0x2518c
move a0, s4
jal 0x2516c
move a0, s5
b 0x1a548
move s5, zero
context_gate:
beqz s4, 0x1a548
nop
addiu a2, zero, 0x28
addiu a1, zero, 0
addiu a0, sp, 0x28
addiu s0, zero, 0x28
jal 0x253dc
nop
b 0x1a408
nop
selection_gate:
beqz s0, failed
nop
jal 0x2519c
nop
b 0x1a484
nop
'''
SITES = (
    (SITE, CAPACITY, CODE),
    (0x1a3f4, 0x14, 'jal 0x1a500\nnop\nnop\nnop\nnop'),
    (0x1a47c, 4, 'jal 0x1a528'),
)



def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR34 artwork draw candidate')
    pe = pefile.PE(data=raw)
    out, edits, added, assemblies = bytearray(raw), [], [], []

    def edit(off, value, reason):
        before = raw[off:off+len(value)]
        if len(before) != len(value):
            raise ValueError('Edit outside existing file')
        if any(off < e['offset']+e['bytes'] and e['offset'] < off+len(value) for e in edits):
            raise ValueError('Overlapping edits')
        out[off:off+len(value)] = value
        edits.append(dict(offset=off, bytes=len(value), before_hex=before.hex(),
                          after_hex=value.hex(), reason=reason))

    for at, capacity, code in SITES:
        new, assembly, records = assemble(code, at, capacity)
        edit(pe.get_offset_from_rva(at-0x10000), new, 'Checked GDI owner path at '+hex(at))
        assemblies.append(dict(site=hex(at), **assembly))
        added.extend(records)
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    spans = [(e['offset'], e['offset']+e['bytes']) for e in edits]
    kept = [r for r in reloc_records(pe)
            if not any(a <= pe.get_offset_from_rva(r[0]) < b for a, b in spans)]
    records = sorted(kept+added)
    if len({r[0] for r in records}) != len(records):
        raise ValueError('Duplicate relocations')
    pages = {}
    for at, kind, companion in records:
        page = at & ~4095
        pages.setdefault(page, []).append((kind << 12) | (at-page))
        if kind == 4:
            pages[page].append(companion)
    table = bytearray()
    for page, values in sorted(pages.items()):
        if len(values) % 2:
            values.append(0)
        table.extend(struct.pack('<II', page, 8+len(values)*2))
        table.extend(struct.pack('<'+'H'*len(values), *values))
    section = pe.get_section_by_rva(directory.VirtualAddress)
    size = max(len(table), directory.Size)
    if section is None or directory.VirtualAddress+size > section.VirtualAddress+section.SizeOfRawData:
        raise ValueError('Relocation table exceeds section capacity')
    if len(table) > directory.Size and any(pe.get_data(directory.VirtualAddress+directory.Size,
                                                      len(table)-directory.Size)):
        raise ValueError('Occupied relocation expansion')
    edit(pe.get_offset_from_rva(directory.VirtualAddress),
         bytes(table)+bytes(max(0, directory.Size-len(table))), 'Update existing MIPS relocations')
    edit(directory.get_file_offset()+4, struct.pack('<I', len(table)), 'Relocation directory size')
    restored = bytearray(out)
    for e in edits:
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    if restored != raw:
        raise ValueError('Undeclared changes')
    return bytes(out), dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(out).hexdigest(),
                            assemblies=assemblies, edits=edits,
                            native_executed=False, hardware_tested=False)
