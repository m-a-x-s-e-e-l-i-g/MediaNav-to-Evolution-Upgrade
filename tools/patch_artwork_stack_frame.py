"""Remove the obsolete metadata-sized gap from the renderer's stack frame."""
import hashlib
import struct

import pefile

BASE_SHA = '63ed1347b94e101bfd90d2fc37e7dbc4cb8ed5d5f8dce04715e9e56592048a32'
OLD_FRAME, FRAME, INFO = 0xf18, 0xd8, 0x70
SHRINK = OLD_FRAME-FRAME
SLOTS = ((0x1a31c, 0xf10), (0x1a320, 0xef8), (0x1a324, 0xefc),
         (0x1a328, 0xf00), (0x1a32c, 0xf04), (0x1a330, 0xf08),
         (0x1a334, 0xf0c), (0x1a344, 0xef0), (0x1a5e0, 0xef0),
         (0x1a5e4, 0xef8), (0x1a5e8, 0xefc), (0x1a5ec, 0xf00),
         (0x1a5f0, 0xf04), (0x1a5f4, 0xf08), (0x1a5f8, 0xf0c),
         (0x1a5fc, 0xf10))
CHANGES = ((0x1a318, -OLD_FRAME, -FRAME), (0x1a608, OLD_FRAME, FRAME),
           (0x1a3e0, 0xeb0, INFO)) + tuple((at, old, old-SHRINK) for at, old in SLOTS)


def stack_inventory(pe):
    result = []
    for at in range(0x1a318, 0x1a60c, 4):
        word = struct.unpack('<I', pe.get_data(at-0x10000, 4))[0]
        if ((word >> 21) & 31) == 29:
            result.append(dict(va=hex(at), word=hex(word), immediate=word & 0xffff))
    return result


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR35 graphics-guard candidate')
    pe = pefile.PE(data=raw)
    large = {int(row['va'], 16) for row in stack_inventory(pe)
             if row['immediate'] > 0x100}
    assert large == {at for at, _, _ in CHANGES}, 'Unreviewed large stack reference'
    assert FRAME % 8 == INFO % 8 == 0
    assert INFO+64 == FRAME-0x28  # ImageInfo ends directly before the cookie.
    out, edits = bytearray(raw), []
    for at, old, new in CHANGES:
        off = pe.get_offset_from_rva(at-0x10000)
        word = struct.unpack_from('<I', raw, off)[0]
        if word & 0xffff != old & 0xffff:
            raise ValueError('Unexpected stack operand')
        assert ((word >> 21) & 31) == 29
        changed = struct.pack('<I', (word & 0xffff0000) | (new & 0xffff))
        out[off:off+4] = changed
        edits.append(dict(va=hex(at), offset=off, bytes=4,
                          before_hex=raw[off:off+4].hex(), after_hex=changed.hex()))
    restored = bytearray(out)
    for e in edits:
        restored[e['offset']:e['offset']+4] = bytes.fromhex(e['before_hex'])
    if restored != raw:
        raise ValueError('Undeclared changes')
    return bytes(out), dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(out).hexdigest(),
                            edits=edits, frame_before=OLD_FRAME, frame_after=FRAME,
                            reserved_stack_bytes_removed=SHRINK, image_info_bytes=64,
                            image_info_offset=INFO, frame_cookie_offset=-0x28,
                            before_stack_inventory=stack_inventory(pe),
                            after_stack_inventory=stack_inventory(pefile.PE(data=bytes(out))),
                            native_executed=False, hardware_tested=False)
