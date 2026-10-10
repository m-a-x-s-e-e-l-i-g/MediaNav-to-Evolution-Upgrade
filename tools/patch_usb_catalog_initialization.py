"""Initialize the directory pointer before the constructor's first reset."""
import hashlib
import struct

import pefile

BASE_SHA = '7c1af7ce3d3a4c75dab75f4df7eb6fe1b5b016034f61f083678382b702ec0a71'
SITE, WORD = 0x14b50, 0xae400038  # sw zero, 0x38(s2), in the reset call delay slot


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact PR37 metadata-copy candidate')
    pe = pefile.PE(data=raw)
    offset = pe.get_offset_from_rva(SITE-0x10000)
    if raw[offset:offset+4] != bytes(4):
        raise ValueError('Expected reviewed reset-call delay slot')
    assert pe.get_data(SITE-4-0x10000, 4) == struct.pack('<I', 0x0c004b87)
    out = bytearray(raw)
    out[offset:offset+4] = struct.pack('<I', WORD)
    edit = dict(va=hex(SITE), offset=offset, bytes=4,
                before_hex=raw[offset:offset+4].hex(), after_hex=out[offset:offset+4].hex())
    return bytes(out), dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(out).hexdigest(),
                            edits=[edit], native_executed=False, hardware_tested=False)
