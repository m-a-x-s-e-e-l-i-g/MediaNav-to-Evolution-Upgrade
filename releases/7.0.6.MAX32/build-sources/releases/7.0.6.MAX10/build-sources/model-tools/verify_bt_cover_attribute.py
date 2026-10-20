"""Execute native request serializer and header helpers; allocation/transport remain fixtures."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import pefile

from inspect_wave_queue import BytesVM, STOP
from inspect_bt_pairing import put, data
from verify_media_responsiveness import call
from patch_bt_cover_attribute import patch, BASE_SHA, SITE

ROOT = Path(__file__).resolve().parents[1]
CTX, OUTPUT = 0x41000000, 0x42000000
RANGES = [(0x6f568, 0x6f6c4), (0x6b1a4, 0x6b1cc), (0x6b1cc, 0x6b1dc), (0x6b1dc, 0x6b21c)]


class SerializerVM(BytesVM):
    def plain(self, word):
        rs, rt, rd = (word >> 21)&31, (word >> 16)&31, (word >> 11)&31
        if word >> 26 == 0 and word&63 in (2, 4):
            if word&63 == 2:
                self.reg[rd] = self.reg[rt] >> ((word >> 6)&31)
            else:
                self.reg[rd] = (self.reg[rt] << (self.reg[rs]&31))&0xffffffff
            self.reg[0] = 0
        else:
            super().plain(word)


def serialize(pe, label, mask):
    vm = SerializerVM(pe, RANGES)
    vm.write(CTX+0x1f, label, 1)
    captured, allocation = [], []
    def allocate(v):
        n = v.reg[4]
        assert n == 22+4*mask.bit_count()
        allocation.append(n)
        put(v, OUTPUT-8, b'LEFTSAFE'+bytes([0xcc])*n+b'RIGHTSAFE')
        return OUTPUT
    def clear(v):
        assert (v.reg[4], v.reg[5], v.reg[6]) == (OUTPUT+13, 0, 8)
        put(v, v.reg[4], bytes(v.reg[6]))
        return v.reg[4]
    def send(v):
        assert v.reg[4] == CTX and v.reg[6] == OUTPUT
        assert v.reg[5] == allocation[0]
        captured.append(data(v, OUTPUT, v.reg[5]))
        return 0
    vm.hooks.update({0x85734: lambda v: v.reg[4].bit_count(),
                     0x85b70: allocate, 0x6a858: lambda v: 0,
                     0x3a750: clear, 0x6ae68: send})
    call(vm, 0x6f568, [CTX, 0x1234, mask])
    assert len(captured) == 1 and len(allocation) == 1
    assert data(vm, OUTPUT-8, 8) == b'LEFTSAFE'
    assert data(vm, OUTPUT+allocation[0], 9) == b'RIGHTSAFE'
    return captured[0]


def expected(mask, label):
    ids = [i for i in range(8, 0, -1) if mask & (1 << (i-1))]
    payload = bytes(8)+bytes([len(ids)])+b''.join(i.to_bytes(4, 'big') for i in ids)
    return bytes([label << 4])+bytes.fromhex('110e0148000019582000')+len(payload).to_bytes(2, 'big')+payload


def verify(before, candidate, recipe):
    rebuilt, checked = patch(before)
    assert candidate == rebuilt and recipe == checked
    pe = pefile.PE(data=before)
    assert pe.get_data(SITE-pe.OPTIONAL_HEADER.ImageBase, 4) == struct.pack('<I', 0x2de80007)
    cases, traces, unchanged, original_defects = 0, [], 0, 0
    old, new = pefile.PE(data=before), pefile.PE(data=candidate)
    for label in (0, 1, 3, 15):
        for mask in range(256):
            a, b = serialize(old, label, mask), serialize(new, label, mask)
            assert b == expected(mask, label), (label, hex(mask), b.hex())
            if not mask & 128:
                assert a == b
                unchanged += 1
            else:
                assert a != b and int.from_bytes(a[22:26], 'big') == 0xcccccccc
                original_defects += 1
            if mask in (0, 1, 7, 127, 128, 129, 255):
                traces.append(dict(transaction_label=label, mask=hex(mask), previous=a.hex(), candidate=b.hex()))
            cases += 1
    return dict(cases=cases, instruction_executions=cases*2, unchanged_legacy_requests=unchanged,
        original_attribute8_defects=original_defects, traces=traces, recipe=recipe,
        binary_input_sha256=BASE_SHA, candidate_sha256=recipe['sha256'],
        firmware_executed=False, hardware_tested=False, feature_enabled=False,
        limits=['Actual serializer/header MIPS instructions at the existing preferred base with four transaction labels',
                'Bit count, successful allocator, clear, diagnostic logger and transport send are fixtures',
                'Only masks 0..255; other masks, allocation failure and complete stack dispatch are unverified',
                'Relocated loading is not covered; existing lower-stack JALs are not rebased by the retained PE table',
                'No metadata request/receiver, version advertisement, SDP, BIP, UI or firmware integration'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--candidate', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    before, candidate = args.input.read_bytes(), args.candidate.read_bytes()
    _, recipe = patch(before)
    result = verify(before, candidate, recipe)
    result['source_pins'] = {n: hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in
        ('patch_bt_cover_attribute.py', 'verify_bt_cover_attribute.py', 'inspect_wave_queue.py',
         'inspect_bt_lifecycle.py', 'inspect_bt_pairing.py', 'verify_media_responsiveness.py',
         'verify_usb_input_safety.py')}
    if args.report.exists():
        raise FileExistsError('Use a fresh report')
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({k: result[k] for k in ('cases', 'unchanged_legacy_requests',
                                          'original_attribute8_defects', 'candidate_sha256')}, indent=2))
