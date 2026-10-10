"""Copy only the metadata fields consumed by each existing snapshot site."""
import hashlib
import struct

import pefile

BASE_SHA = 'f947c2d231b255019b95f17f57299dcaa6159bee0dd6242ecec52475258370b9'
# start, old destination, source field, bytes actually retained
SITES = (
    (0x19e50, 0x18, 0xe40, 4),
    (0x19f88, 0x18, 0x410, 520),
    (0x19fa8, 0xe60, 0x410, 520),
    (0x19fe4, 0x18, 0xe40, 4),
    (0x1a020, 0x18, 0x208, 520),
    (0x1a040, 0x18, 0xe40, 4),
    (0x1a07c, 0xe60, 0, 520),
    (0x1a17c, 0x18, 0xe40, 4),
    (0x1a1dc, 0x18, 0x410, 520),
    (0x1a1fc, 0xe60, 0x410, 520),
    (0x1a238, 0x18, 0xe40, 4),
    (0x1a274, 0x18, 0x208, 520),
    (0x1a294, 0x18, 0xe40, 4),
    (0x1a2d0, 0xe60, 0, 520),
)


def block(destination, field, count):
    return struct.pack('<4I', 0x27a40000 | destination,
                       0x24060000 | count, 0x0c00959a,
                       0x26050000 | field)


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR36 compact-frame candidate')
    pe = pefile.PE(data=raw)
    out, edits = bytearray(raw), []
    for at, destination, field, count in SITES:
        offset = pe.get_offset_from_rva(at-0x10000)
        before = struct.pack('<4I', 0x27a40000 | destination,
                             0x24060e44, 0x0c00959a, 0x02002825)
        if raw[offset:offset+16] != before:
            raise ValueError('Unreviewed metadata snapshot instructions')
        after = block(destination+field, field, count)
        out[offset:offset+16] = after
        edits.append(dict(va=hex(at), offset=offset, bytes=16,
                          before_hex=before.hex(), after_hex=after.hex(),
                          field_offset=field, snapshot_bytes=count))
    return bytes(out), dict(base_sha256=BASE_SHA,
                            sha256=hashlib.sha256(out).hexdigest(), edits=edits,
                            original_snapshot_bytes=3652,
                            largest_snapshot_bytes=520, snapshot_sites=len(SITES),
                            native_executed=False, hardware_tested=False)
