"""Reject invalid USB timing and clamp negative absolute seeks; exact PR-27 input."""
import hashlib
import struct

import pefile

from patch_shared_mapping_checks import reloc_records
from patch_usb_folders import folder_assemble as assemble

BASE = 0x10000
BASE_SHA = '82792cb54bfb7de6d3ccd07f68fdf6357a7772122bd3d8be6dc5578c574720ea'
CAPACITY = 0x40


def escape(at):
    return f'la t9, {hex(at)}\njr t9\nnop'


def held_position(zero_target):
    return f'''
bltz v0, failed
nop
lw t0, 0xe60(s1)
beqz t0, zero_factor
nop
jr ra
nop
zero_factor:
{escape(zero_target)}
failed:
{escape(0x1DAB0)}
'''


def dispatched_time(failure):
    return f'''
bltz s2, failed
nop
bltz v0, failed
nop
jr ra
nop
failed:
{escape(failure)}
'''


HELPERS = (
    (0x40C00, '''
bltz v0, failed
nop
bltz s1, failed
nop
lw a1, 0x14(sp)
jr ra
nop
failed:
''' + escape(0x11258), 'Reject failed or negative duration in position getter'),
    (0x40C40, '''
lw t0, 0x1c(sp)
bltz t0, negative
nop
done:
lw a0, 0xc(s0)
jr ra
nop
negative:
sw zero, 0x18(sp)
beqz zero, done
sw zero, 0x1c(sp)
''', 'Clamp negative absolute seek target to zero'),
    (0x40C80, '''
bltz v0, failed
nop
''' + escape(0x1144C) + '\nfailed:\n' + escape(0x1DAB0),
     'Abort held seek on failed duration; otherwise call original manager getter'),
    (0x40CC0, held_position(0x1D910), 'Check held forward position; preserve repeat-factor branch'),
    (0x40D00, held_position(0x1DA64), 'Check held backward position; preserve repeat-factor branch'),
    (0x40D40, dispatched_time(0x21028), 'IPC seek rejects failed duration or position'),
    (0x40D80, dispatched_time(0x226C0), 'Window seek rejects failed duration or position'),
    (0x40DC0, '''
bltz v0, failed
nop
lw t0, 0x14(sp)
bltz t0, failed
nop
jr ra
nop
failed:
''' + escape(0x11390), 'Duration getter rejects failed HRESULT and negative output'),
)
SITES = (
    (0x112BC, 4, 'jal 0x40c00'),
    (0x111EC, 4, 'jal 0x40c40'),
    (0x1D8E0, 4, 'jal 0x40c80'),
    (0x1D8F0, 8, 'jal 0x40cc0\nnop'),
    (0x1DA44, 8, 'jal 0x40d00\nnop'),
    (0x21728, 4, 'jal 0x40d40'),
    (0x223F4, 4, 'jal 0x40d80'),
    (0x113AC, 4, 'jal 0x40dc0'),
)


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected the exact PR-27 graph-initialization candidate')
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

    added_rows = []
    for at, code, reason in HELPERS:
        if pe.get_data(at-BASE, CAPACITY) != bytes(CAPACITY):
            raise ValueError('Occupied timing helper space')
        recipe = block(at, CAPACITY, code, reason)
        added_rows.append((at, at+recipe['used_bytes'], 0, 0, at))
    for at, cap, code in SITES:
        block(at, cap, code, 'Guard timing caller at '+hex(at))
    displacement = (0x1B470-0x1B3F8-4)//4
    edit(0x1B3F8, struct.pack('<I', (1 << 26) | (2 << 21) | (displacement & 65535)),
         'Skip progress publication after a failed position query')
    displacement = (0x1B530-0x1B4B4-4)//4
    edit(0x1B4B4, struct.pack('<I', (6 << 26) | (2 << 21) | (displacement & 65535)),
         'Failed seek returns -1; skip cached/displayed progress and publication')
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    original_rows = [struct.unpack_from('<5I', pe.get_data(directory.VirtualAddress, directory.Size), i)
                     for i in range(0, directory.Size, 20)]
    rows = sorted(original_rows+added_rows)
    if any(a[1] > b[0] for a, b in zip(rows, rows[1:])):
        raise ValueError('Overlapping exception rows')
    table = b''.join(struct.pack('<5I', *row) for row in rows)
    capacity(directory.VirtualAddress, len(table))
    if any(pe.get_data(directory.VirtualAddress+directory.Size, len(table)-directory.Size)):
        raise ValueError('Occupied exception-table expansion')
    edit(BASE+directory.VirtualAddress, table, 'Add eight leaf exception rows')
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
         'Updated timing relocations')
    edit_offset(directory.get_file_offset()+4, struct.pack('<I', len(table)), 'Relocation-table size')
    result = bytes(out)
    restored = bytearray(result)
    for e in edits:
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    if restored != raw: raise ValueError('Undeclared changed bytes')
    return result, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits, added_pdata_rows=added_rows,
                        native_executed=False, hardware_tested=False)
