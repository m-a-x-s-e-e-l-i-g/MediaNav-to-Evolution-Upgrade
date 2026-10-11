"""Carry shared selected-label correction onto the exact cumulative MAX06 AppMain.

Keep every MAX06 section and artwork helper. Add read-only leaf helpers and
copied exception/relocation directories in a fresh section; no old PE is shipped.
"""
import hashlib
import json
import struct
from pathlib import Path

import pefile
import patch_selected_label_contrast as labels
import max07_artwork_frame as artwork_frame
from patch_usb_reliability import assemble
from patch_shared_mapping_checks import reloc_records

ROOT = Path(__file__).resolve().parents[1]
MAX06 = ROOT / 'sources/MediaNav-usb-seek-timing/build/maxmade-7.0.6.MAX06-artwork-text-local-01'
INPUT_SHA = 'e1248c8021b30ea4361358a7c0689b1aa6f5c6de5043278122efae8fe332bb5c'
BASE = 0x10000


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def align(value, size):
    return (value + size - 1) // size * size


def encode_relocations(records):
    pages = {}
    assert len({r[0] for r in records}) == len(records)
    for at, kind, companion in sorted(records):
        pages.setdefault(at & ~4095, []).append((kind << 12) | (at & 4095))
        if kind == 4:
            pages[at & ~4095].append(companion)
    result = bytearray()
    for page, values in sorted(pages.items()):
        if len(values) % 2:
            values.append(0)
        result.extend(struct.pack('<II', page, 8 + len(values) * 2))
        result.extend(struct.pack('<' + 'H' * len(values), *values))
    return bytes(result)


def patch(raw, visible_artwork=False):
    assert sha(raw) == INPUT_SHA, 'Expected latest complete MAX06 AppMain'
    original = pefile.PE(data=raw)
    assert original.OPTIONAL_HEADER.ImageBase == BASE
    assert original.get_overlay_data_start_offset() is None
    # Reuse verified foreground policy and instructions, reassemble for MAX06.
    old = (labels.RELEASE / 'payload' / labels.APP).read_bytes()
    _, template = labels.patch(old)
    catalog, ids = labels.resources()
    start = BASE + align(original.OPTIONAL_HEADER.SizeOfImage, original.OPTIONAL_HEADER.SectionAlignment)
    lookup = start + 0x800
    body = bytearray(0x3000 if visible_artwork else 0x1000)
    for ident in ids:
        body[0x800 + ident] = 1
    records = reloc_records(original)
    previous_records = list(records)
    additions, routines, targets = [], [], []
    out, edits = bytearray(raw), []

    def edit(offset, data, reason):
        edits.append(dict(offset=offset, before_hex=bytes(out[offset:offset + len(data)]).hex(),
                          after_hex=data.hex(), reason=reason))
        out[offset:offset + len(data)] = data

    for index, ((site, state, replay), old_recipe) in enumerate(zip(labels.HOOKS, template['routines'])):
        target = start + index * 0x200
        source = old_recipe['source_assembly'].replace(hex(template['lookup_va']), hex(lookup))
        encoded, recipe, relocations = assemble(source, target, 0x200)
        body[index * 0x200:(index + 1) * 0x200] = encoded
        targets.append(target)
        routines.append(recipe)
        additions.append((target, target + recipe['used_bytes'], 0, 0, target + 16))
        records.extend(relocations)
        offset = original.get_offset_from_rva(site - BASE)
        assert original.get_data(site - BASE, 8) == pefile.PE(data=old).get_data(site - BASE, 8)
        assert not any(site - BASE <= at < site - BASE + 8 for at, _, _ in previous_records)
        branch, _, relocations = assemble(f'jal {hex(target)}\nnop', site, 8)
        edit(offset, branch, 'Resolve late black foreground on selected themed controls')
        records.extend(relocations)

    artwork = None
    if visible_artwork:
        target, text = start + 0x1000, start + 0x2000
        encoded, recipe, relocations = assemble(artwork_frame.source(text), target, 0x1000)
        body[0x1000:0x2000] = encoded
        caption = 'Album art\0'.encode('utf-16-le')
        body[0x2000:0x2000 + len(caption)] = caption
        records.extend(relocations)
        additions.append((target, target + recipe['used_bytes'], 0, 0, target + 28))
        # Retain the full MAX06 overlay and replace only its three calls to the
        # original background draw. Stale/failed cover cleanup also restores
        # the placeholder. Existing JAL relocation locations remain valid.
        old_call = struct.pack('<I', (3 << 26) | (0x134e1c >> 2))
        sites = [0x235000 + i for i in range(0, 0x1000, 4)
                 if original.get_data(0x235000 - BASE + i, 4) == old_call]
        assert len(sites) == 3
        for site in sites:
            assert (site - BASE, 5, None) in previous_records
            edit(original.get_offset_from_rva(site - BASE),
                 struct.pack('<I', (3 << 26) | (target >> 2)),
                 'Show native artwork placeholder after background and stale-cover cleanup')
        artwork = dict(address=target, text_va=text, sites=sites, recipe=recipe,
                       rectangle=[24,116,128,128], caption='Album art')

    pdata = original.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    existing_rows = list(struct.iter_unpack('<5I', original.get_data(pdata.VirtualAddress, pdata.Size)))
    rows = sorted(existing_rows + additions)
    assert all(a[1] <= b[0] for a, b in zip(rows, rows[1:]))
    pdata_offset = len(body)
    body.extend(b''.join(struct.pack('<5I', *row) for row in rows))
    for index, row in enumerate(rows):
        for field, value in enumerate(row):
            if value:
                records.append((start - BASE + pdata_offset + index * 20 + field * 4, 3, None))
    reloc_offset = align(len(body), 4)
    body.extend(bytes(reloc_offset - len(body)))
    encoded_relocs = encode_relocations(records)
    body.extend(encoded_relocs)
    virtual_size = len(body)
    raw_size = align(virtual_size, original.OPTIONAL_HEADER.FileAlignment)
    body.extend(bytes(raw_size - len(body)))
    new_header = original.sections[-1].get_file_offset() + 40
    assert new_header + 40 <= original.OPTIONAL_HEADER.SizeOfHeaders
    assert not any(raw[new_header:new_header + 40])
    pointer = align(len(raw), original.OPTIONAL_HEADER.FileAlignment)
    edit(new_header, struct.pack('<8s8I', b'.mxlabel', virtual_size, start - BASE, raw_size, pointer,
                                 0, 0, 0, 0x60000020), 'Read-only label helpers and loader metadata')
    edit(original.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),
         struct.pack('<H', len(original.sections) + 1), 'Added section count')
    for name, value in (('SizeOfImage', align(start - BASE + virtual_size, original.OPTIONAL_HEADER.SectionAlignment)),
                        ('SizeOfCode', original.OPTIONAL_HEADER.SizeOfCode + raw_size)):
        edit(original.OPTIONAL_HEADER.get_field_absolute_offset(name), struct.pack('<I', value), name)
    edit(pdata.get_file_offset(), struct.pack('<II', start - BASE + pdata_offset, len(rows) * 20),
         'Sorted exception directory retains all MAX06 function rows')
    edit(original.OPTIONAL_HEADER.DATA_DIRECTORY[5].get_file_offset(),
         struct.pack('<II', start - BASE + reloc_offset, len(encoded_relocs)), 'Retained plus added relocations')
    checksum_at = original.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    edit(checksum_at, bytes(4), 'Checksum prepared for final image')
    out.extend(bytes(pointer - len(out)))
    out.extend(body)
    edit(checksum_at, struct.pack('<I', pefile.PE(data=bytes(out)).generate_checksum()), 'Final PE checksum')
    result = bytes(out)
    candidate = pefile.PE(data=result)
    assert candidate.OPTIONAL_HEADER.CheckSum == candidate.generate_checksum()
    assert set(previous_records) <= set(reloc_records(candidate))
    for section in original.sections:
        assert result[section.PointerToRawData:section.PointerToRawData + section.SizeOfRawData] == \
               raw[section.PointerToRawData:section.PointerToRawData + section.SizeOfRawData] or section.Name.rstrip(b'\0') in (b'.text', b'.mxartx')
    rollback = bytearray(result[:len(raw)])
    for change in reversed(edits):
        offset = change['offset']
        before = bytes.fromhex(change['before_hex'])
        rollback[offset:offset + len(before)] = before
    assert rollback == raw
    return result, dict(input_sha256=sha(raw), sha256=sha(result), edits=edits, routines=routines,
                        helpers=targets, helper_rows=additions, resource_count=len(catalog),
                        protected_resources=ids, lookup_va=lookup,
                        added_relocations=len(records) - len(previous_records),
                        original_relocations_preserved=True, rollback_matches_complete_MAX06=True,
                        artwork=artwork, baseline='7.0.6.MAX06', native_executed=False, hardware_tested=False)


if __name__ == '__main__':
    import verify_selected_label_contrast as proof
    original = (MAX06 / 'payload' / labels.APP).read_bytes()
    candidate, recipe = patch(original)
    verified = proof.verify(original, candidate, recipe)
    destination = ROOT / 'build/max07-labels-development-01'
    destination.mkdir(exist_ok=False)
    (destination / 'AppMain.exe').write_bytes(candidate)
    (destination / 'recipe.json').write_text(json.dumps(recipe, indent=2) + '\n', encoding='utf-8')
    (destination / 'verification.json').write_text(json.dumps(verified, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(sha256=sha(candidate), bytes=len(candidate), baseline='MAX06', verification=verified), indent=2))
