"""Check native Draw status before processing/publishing an album bitmap."""
import hashlib
import struct

import pefile

from patch_shared_mapping_checks import reloc_records
from patch_usb_seek_completion import assemble

BASE_SHA = '390c9858832add05a16b3a0760383080f1ce9bfc34359c8538ddb9f7d00557c8'
SITE, CAPACITY = 0x1a4a0, 0xa0
CODE = '''
move s3, v0
move a1, s0
jal 0x251ac
move a0, s4
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
'''


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR33 completion-event candidate')
    pe = pefile.PE(data=raw)
    new, assembly, added = assemble(CODE, SITE, CAPACITY)
    out, edits = bytearray(raw), []

    def edit(off, value, reason):
        before = raw[off:off+len(value)]
        if len(before) != len(value):
            raise ValueError('Edit outside existing file')
        if any(off < e['offset']+e['bytes'] and e['offset'] < off+len(value) for e in edits):
            raise ValueError('Overlapping edits')
        out[off:off+len(value)] = value
        edits.append(dict(offset=off, bytes=len(value), before_hex=before.hex(),
                          after_hex=value.hex(), reason=reason))

    edit(pe.get_offset_from_rva(SITE-0x10000), new, 'Retain Draw HRESULT across bitmap deselection; reject failed draw')
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
                            site=hex(SITE), assembly=assembly, edits=edits,
                            native_executed=False, hardware_tested=False)
