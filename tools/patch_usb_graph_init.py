"""Clean failed graph acquisition; exact PR-26 input and reversible MIPS edits."""
import hashlib
import struct

import pefile

from patch_shared_mapping_checks import reloc_records
from patch_usb_folders import folder_assemble as assemble
from patch_usb_graph_state import BASE, TEARDOWN
from patch_updater_copy_safety import frame, end

BASE_SHA = "b508cfa1a697d829fb335e3df42828a5ea514c67d2acd7fbae00546a55b7d3d5"
CLEANUP, CAPACITY = 0x40B00, 0x100

# Called from the original RenderFile epilogue with s0=result, s1=manager.
# +0x14 in its stack frame records successful creation, not just an existing
# graph. Thus a refused replacement never attempts teardown a second time.
CODE = f"""
{frame(0x20, ['s0'])}
addiu t0, zero, 1
beq s0, t0, done
nop
lw t0, 0x34(sp)
beqz t0, done
nop
jal {hex(TEARDOWN)}
move a0, s1
done:
move v0, s0
{end(0x20, ['s0'])}
"""


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError("Expected the exact PR-26 graph-state candidate")
    pe = pefile.PE(data=raw)
    out, edits, added_relocations = bytearray(raw), [], []

    def edit_offset(off, new, reason, **extra):
        old = raw[off:off+len(new)]
        if len(old) != len(new):
            raise ValueError("Edit outside existing file")
        edits.append(dict(offset=off, bytes=len(new), before_hex=old.hex(),
                          after_hex=new.hex(), reason=reason, **extra))
        out[off:off+len(new)] = new

    def edit(at, new, reason, **extra):
        edit_offset(pe.get_offset_from_rva(at-BASE), new, reason, va=hex(at), **extra)

    def block(at, cap, code, reason):
        new, recipe, relocations = assemble(code, at, cap)
        edit(at, new, reason, assembly=recipe)
        added_relocations.extend(relocations)
        return recipe

    if any(pe.get_data(CLEANUP-BASE, CAPACITY)):
        raise ValueError("Occupied cleanup helper space")
    recipe = block(CLEANUP, CAPACITY, CODE, "Clean failed new acquisition; preserve original result")
    block(0x11F9C, 4, "sw v0, 0x14(sp)", "Record whether a new graph was created")
    block(0x12248, 4, f"jal {hex(CLEANUP)}", "All RenderFile results pass through cleanup")
    added_rows = [(CLEANUP, CLEANUP+recipe['used_bytes'], 0, 0, CLEANUP+12)]
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    previous_rows = [struct.unpack_from('<5I', pe.get_data(directory.VirtualAddress, directory.Size), i)
                     for i in range(0, directory.Size, 20)]
    rows = sorted(previous_rows+added_rows)
    if any(a[1] > b[0] for a, b in zip(rows, rows[1:])):
        raise ValueError("Overlapping function-table rows")
    table = b''.join(struct.pack('<5I', *row) for row in rows)
    if any(pe.get_data(directory.VirtualAddress+directory.Size, len(table)-directory.Size)):
        raise ValueError("Occupied function-table expansion")
    edit(BASE+directory.VirtualAddress, table, "Add cleanup exception row")
    edit_offset(directory.get_file_offset()+4, struct.pack('<I', len(table)), "Function-table size")
    for i, row in enumerate(rows):
        for j, value in enumerate(row):
            if value:
                added_relocations.append((directory.VirtualAddress+i*20+j*4, 3, None))
    spans = [(e['offset'], e['offset']+e['bytes']) for e in edits]
    previous = [r for r in reloc_records(pe)
                if not any(a <= pe.get_offset_from_rva(r[0]) < b for a, b in spans)]
    combined = sorted(previous+added_relocations)
    if len({r[0] for r in combined}) != len(combined):
        raise ValueError("Duplicate relocations")
    pages = {}
    for at, kind, companion in combined:
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
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    if len(table) > directory.Size and any(pe.get_data(directory.VirtualAddress+directory.Size,
                                                      len(table)-directory.Size)):
        raise ValueError("Occupied relocation-table expansion")
    edit(BASE+directory.VirtualAddress, bytes(table)+bytes(max(0, directory.Size-len(table))),
         "Updated MIPS relocations")
    edit_offset(directory.get_file_offset()+4, struct.pack('<I', len(table)), "Relocation-table size")
    result = bytes(out)
    restored = bytearray(result)
    for e in edits:
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    if restored != raw:
        raise ValueError("Undeclared changed bytes")
    return result, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits, added_pdata_rows=added_rows,
                        native_executed=False, hardware_tested=False)


def cumulative_recipe(original, candidate, state_recipe, init_recipe):
    """Disjoint exact-byte differences for the retained verifier's reversal check.

    Individual stage recipes retain their assembly, preconditions and reasons.
    """
    if len(original) != len(candidate):
        raise ValueError("Unexpected size change")
    edits, i = [], 0
    while i < len(original):
        if original[i] == candidate[i]:
            i += 1
            continue
        start = i
        while i < len(original) and original[i] != candidate[i]:
            i += 1
        edits.append(dict(offset=start, bytes=i-start, before_hex=original[start:i].hex(),
                          after_hex=candidate[start:i].hex(), reason="Cumulative graph-state/init edits"))
    return dict(edits=edits, added_pdata_rows=state_recipe['added_pdata_rows']+init_recipe['added_pdata_rows'])
