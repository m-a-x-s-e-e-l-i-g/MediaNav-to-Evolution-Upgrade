"""Correct shared-mapping result checks; do not change startup policy or IPC."""
import hashlib
import struct
import pefile

BASE_SHA = '236ef346d273b3529a3318b17219b8135eb8bb5184bd34178337e8a72df5902c'
EDITS = (
    (0x135e4, 0x8e0800ac, 0x00404021, 'USB: test MapViewOfFile result instead of iPod pointer'),
    (0x13b3c, 0x8e0800f8, 0x00404021, 'DAB EPG: test MapViewOfFile result instead of mapping handle'),
    (0x13b54, 0x24040000, 0x8e0400f8, 'DAB EPG: close the real mapping handle on failed view'),
)

# Full replacement spans reconstructed from draft_app_pairing, app_ack,
# app_safe_copy, patch_label_scan and patch_media_responsiveness recipes.
# These contain image addresses, object offsets and protocol constants; only
# the explicitly reviewed image references below receive relocations.
SPANS = (
    (0x20618,0x2061c),(0x20650,0x20654),(0x2077c,0x20780),
    (0xb9634,0xb9638),(0xb966c,0xb9670),(0xb9754,0xb9758),(0xb9c78,0xb9c7c),
    (0xd064c,0xd0650),(0xd0684,0xd06ac),(0xd06b8,0xd06bc),(0xd06e8,0xd0708),
    (0xd07c8,0xd07cc),(0xd07dc,0xd07e0),(0xd28f0,0xd28f4),
    (0xd2970,0xd2974),(0xd2eb0,0xd2eb4),(0xd2ee0,0xd2ee4),
    (0x110730,0x1108c4),(0x1109fc,0x110b14),(0x111d98,0x111df0),
    (0x115988,0x1159c8),(0x115e60,0x115ed0),(0x11b4bc,0x11b4c0),
    (0x11b4e4,0x11b5a8),(0x11d26c,0x11d27c),(0x11e0cc,0x11e0d0),
    (0x11f9a4,0x11f9a8),(0x11f9b0,0x11f9d8),(0x11fa60,0x11fb0c),
    (0x1216a8,0x1216ac),(0x132b7c,0x132c3c),(0x132d38,0x132ec8),
    (0x1397e8,0x139880),(0x139964,0x139a34),
    (0x13e654,0x13e668),(0x13e674,0x13e678),
)
HIGHS = {0x110a70:0x6828, 0x110a9c:0x5088, 0x115e60:0x6ce8,
         0x11b53c:0x5020, 0x11fa78:0x4be4, 0x132b7c:0x7be4}
LOWS = (0x110a74,0x110aa0,0x115e64,0x11b540,
        0x11fa60,0x11fa6c,0x11fa80,0x11fa84,0x11fa98,
        0x132b80,0x132bc4,0x132bd4,0x132bf4,0x132c14,0x132c24,
        0x132dd4,0x132df4,0x132e04)


def reloc_records(pe):
    d = pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    raw = pe.get_data(d.VirtualAddress, d.Size)
    records = []; pos = 0
    while pos < len(raw):
        page, size = struct.unpack_from('<II', raw, pos)
        assert size >= 8 and size % 4 == 0
        vals = struct.unpack_from('<' + str((size - 8) // 2) + 'H', raw, pos + 8)
        i = 0
        while i < len(vals):
            value = vals[i]; i += 1; kind = value >> 12
            companion = None
            if kind == 4: companion = vals[i]; i += 1
            if kind: records.append((page + (value & 4095), kind, companion))
        pos += size
    assert pos == len(raw)
    return records


def repair_relocations(pe, raw):
    base = pe.OPTIONAL_HEADER.ImageBase
    inside = lambda rva: any(a <= base + rva < b for a, b in SPANS)
    old = reloc_records(pe)
    removed = [r for r in old if inside(r[0])]
    kept = [r for r in old if not inside(r[0])]
    added = [(va - base, 4, low) for va, low in HIGHS.items()]
    added += [(va - base, 2, None) for va in LOWS]
    for a, b in SPANS:
        for va in range(a, b, 4):
            word = int.from_bytes(pe.get_data(va - base, 4), 'little')
            if word >> 26 in (2, 3): added.append((va - base, 5, None))
    for va in HIGHS:
        assert int.from_bytes(pe.get_data(va - base, 4), 'little') >> 26 == 15
    assert len({at for at, _, _ in kept + added}) == len(kept + added)
    pages = {}
    for at, kind, companion in sorted(kept + added):
        page = at & ~4095
        pages.setdefault(page, []).append((kind << 12) | (at - page))
        if kind == 4: pages[page].append(companion)
    rebuilt = bytearray()
    for page, values in sorted(pages.items()):
        if len(values) % 2: values.append(0)
        rebuilt.extend(struct.pack('<II', page, 8 + len(values) * 2))
        rebuilt.extend(struct.pack('<' + str(len(values)) + 'H', *values))
    d = pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    assert len(rebuilt) <= d.Size
    offset = pe.get_offset_from_rva(d.VirtualAddress)
    edits = [dict(va=hex(base + d.VirtualAddress), offset=hex(offset), bytes=d.Size,
                  before_hex=raw[offset:offset + d.Size].hex(),
                  after_hex=(bytes(rebuilt) + bytes(d.Size - len(rebuilt))).hex(),
                  reason='Replace inherited relocation entries inside reviewed application edits')]
    field = d.get_file_offset() + 4
    edits.append(dict(va=None, offset=hex(field), bytes=4,
                      before_hex=raw[field:field + 4].hex(),
                      after_hex=struct.pack('<I', len(rebuilt)).hex(), reason='Relocation directory size'))
    return edits, dict(removed_records=len(removed), added_records=len(added),
                       unchanged_records=len(kept), reviewed_spans=SPANS,
                       new_relocations=added, high_companions=HIGHS,
                       low_instruction_addresses=LOWS)


def patch(raw):
    assert hashlib.sha256(raw).hexdigest() == BASE_SHA
    pe = pefile.PE(data=raw)
    out = bytearray(raw)
    edits = []
    for va, old, new, reason in EDITS:
        offset = pe.get_offset_from_rva(va - pe.OPTIONAL_HEADER.ImageBase)
        assert struct.unpack_from('<I', raw, offset)[0] == old
        struct.pack_into('<I', out, offset, new)
        edits.append(dict(va=hex(va), offset=hex(offset), bytes=4,
                          before_hex=struct.pack('<I', old).hex(),
                          after_hex=struct.pack('<I', new).hex(), reason=reason))
    result = bytes(out)
    relocation_edits, relocation_recipe = repair_relocations(pe, result)
    for edit in relocation_edits:
        at = int(edit['offset'], 16); n = edit['bytes']
        assert out[at:at+n].hex() == edit['before_hex']
        out[at:at+n] = bytes.fromhex(edit['after_hex'])
    edits += relocation_edits
    result = bytes(out)
    return result, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(result).hexdigest(),
                        edits=edits, relocation_repair=relocation_recipe,
                        imports_sections_pdata_unchanged=True,
                        outer_startup_failure_policy_unchanged=True, native_executed=False)
