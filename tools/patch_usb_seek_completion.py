"""Check saved-resume, held and IPC seek results; exact PR-28 input only."""
import hashlib
import re
import struct

import pefile

from patch_shared_mapping_checks import reloc_records
from patch_usb_folders import folder_assemble
from patch_bt_playback import REGS

BASE = 0x10000
BASE_SHA = 'c88c6d682d8fdc00146fb1b8cd628d4376f1b58f8d5517aa01d456cc634ed36f'


def assemble(code, start, capacity):
    # Preserve the packed-field merge stores and historical assembler bytes.
    lines, custom, pc = [], [], start
    for line in code.splitlines():
        line = line.split('#', 1)[0].strip()
        if not line: continue
        if line.endswith(':'): lines.append(line); continue
        if line.split()[0] in ('lwl', 'lwr', 'swl', 'swr'):
            custom.append((pc, line)); lines.append('nop')
        else: lines.append(line)
        pc += 8 if line.startswith('la ') else 4
    raw, recipe, relocations = folder_assemble('\n'.join(lines), start, capacity)
    out = bytearray(raw)
    for at, line in custom:
        op, rt, imm, rs = [p for p in re.split(r'[\s,()]+', line) if p]
        imm = int(imm, 0); assert -32768 <= imm <= 32767
        opcode = dict(lwl=0x22, lwr=0x26, swl=0x2A, swr=0x2E)[op]
        word = (opcode << 26) | (REGS[rs] << 21) | (REGS[rt] << 16) | (imm & 65535)
        struct.pack_into('<I', out, at-start, word)
    recipe['assembly'] = code
    return bytes(out), recipe, relocations


def leave():
    return 'lw ra, 0x1c(sp)\naddiu sp, sp, 0x20'


def jump(at):
    return f'la t9, {hex(at)}\njr t9\nnop'


# s1 is UI in both owners; s3 is the saved-position pointer in resume,
# while s0/s2 are the desired middle/end position in the held owner.
# Return-address comparisons are relocated along with the caller instructions.
HELPERS = (
    (0x40300, 0x300, f'''
addiu sp, sp, -0x20
sw ra, 0x1c(sp)
la t0, 0x1bc9c
beq ra, t0, resume
nop
blez v0, held_failed
nop
la t0, 0x1d948
bne ra, t0, held_middle
nop
addiu a1, zero, 1
jal 0x19760
move a0, s1
move a1, s2
beqz zero, display
nop
held_middle:
move a1, s0
display:
move a0, s1
{leave()}
{jump(0x19864)}
held_failed:
{leave()}
{jump(0x1DAB0)}
resume:
blez v0, resume_failed
nop
beqz zero, resume_done
nop
resume_failed:
jal 0x1144c
nop
jal 0x11230
move a0, v0
bltz v0, unknown_position
nop
swl v0, 3(s3)
swr v0, 0(s3)
beqz zero, resume_done
nop
unknown_position:
swl zero, 3(s3)
swr zero, 0(s3)
resume_done:
lwl a1, 3(s3)
lwr a1, 0(s3)
{leave()}
jr ra
nop
''', 'Resume uses confirmed position or explicit zero fallback; failed held seek exits its owner'),
    (0x40B80, 0x50, f'''
addiu sp, sp, -0x20
sw ra, 0x1c(sp)
blez v0, done
nop
jal 0x231a4
nop
lw a0, 0x4c(v0)
jal 0x1dd5c
move a1, s0
done:
{leave()}
{jump(0x21028)}
''', 'IPC publishes requested progress only after successful seek'),
)
SITES = (
    (0x1BC94, 8, 'jal 0x40300\nnop'),
    (0x1D920, 12, 'nop\nnop\nnop'),
    (0x1D940, 8, 'jal 0x40300\nnop'),
    (0x1DA8C, 8, 'jal 0x40300\nnop'),
    (0x21748, 20, '\n'.join(['nop']*5)),
    (0x21780, 4, 'jal 0x40b80'),
)


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected the exact PR-28 seek-timing candidate')
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
            raise ValueError('Occupied seek-result helper space')
        if any(at < r[1] and r[0] < at+cap for r in original_rows):
            raise ValueError('Helper overlaps a previous function')
        recipe = block(at, cap, code, reason)
        added_rows.append((at, at+recipe['used_bytes'], 0, 0, at+8))
    for at, cap, code in SITES:
        block(at, cap, code, 'Check seek result at '+hex(at))
    rows = sorted(original_rows+added_rows)
    if any(a[1] > b[0] for a, b in zip(rows, rows[1:])):
        raise ValueError('Overlapping exception rows')
    table = b''.join(struct.pack('<5I', *row) for row in rows)
    capacity(directory.VirtualAddress, len(table))
    if any(pe.get_data(directory.VirtualAddress+directory.Size, len(table)-directory.Size)):
        raise ValueError('Occupied exception-table expansion')
    edit(BASE+directory.VirtualAddress, table, 'Add two framed exception rows')
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
         'Updated seek-result relocations')
    edit_offset(directory.get_file_offset()+4, struct.pack('<I', len(table)), 'Relocation-table size')
    result = bytes(out)
    restored = bytearray(result)
    for e in edits:
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    if restored != raw: raise ValueError('Undeclared changed bytes')
    return result, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits, added_pdata_rows=added_rows,
                        native_executed=False, hardware_tested=False)
