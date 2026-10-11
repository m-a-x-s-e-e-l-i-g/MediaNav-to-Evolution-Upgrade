"""Pin AppMain's existing memory-image route and preserve its exact disassembly.

Static evidence only. Does not execute COM, decode images or modify AppMain.
"""
import argparse
import hashlib
import json
from pathlib import Path
import uuid

import capstone
import pefile

ROOT = Path(__file__).resolve().parents[1]
APP_SHA = 'b34676225ad428426b417cec33c30f7e18e56aeeb6e438900c01dc022225fcd9'
ORIGINAL_SHA = '6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8'
RANGES = ((0x1029b4, 0x102d28, 'QByteArray -> Imaging factory -> GDI bitmap'),
          (0x102d98, 0x102e6c, 'Eight-byte PNG signature classifier'),
          (0xea698, 0xea990, 'QString/QByteArray copies and bitmap cache insertion'))


def inspect(raw, original_raw):
    if hashlib.sha256(raw).hexdigest() != APP_SHA or hashlib.sha256(original_raw).hexdigest() != ORIGINAL_SHA:
        raise ValueError('Expected exact MAX05 and original 705 AppMain.exe')
    pe, original = pefile.PE(data=raw), pefile.PE(data=original_raw)
    rows = []
    decoder = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
    for lo, hi, purpose in RANGES:
        chunk = pe.get_data(lo-pe.OPTIONAL_HEADER.ImageBase, hi-lo)
        assert chunk == original.get_data(lo-original.OPTIONAL_HEADER.ImageBase, hi-lo)
        # The first function contains a 16-byte relative switch table. Keep it
        # explicitly as data rather than stopping or pretending it is code.
        blocks = [(lo, hi)] if lo != 0x1029b4 else [(lo, 0x102a94), (0x102aa4, hi)]
        instructions = []
        for begin, finish in blocks:
            decoded = list(decoder.disasm(pe.get_data(begin-pe.OPTIONAL_HEADER.ImageBase, finish-begin), begin))
            assert sum(i.size for i in decoded) == finish-begin, 'Incomplete instruction decode'
            instructions += [dict(address=hex(i.address), bytes=i.bytes.hex(),
                                  mnemonic=i.mnemonic, operands=i.op_str) for i in decoded]
        rows.append(dict(start=hex(lo), end=hex(hi), purpose=purpose, sha256=hashlib.sha256(chunk).hexdigest(),
                         retained_from_705=True, instructions=instructions,
                         inline_table_hex=pe.get_data(0x102a94-pe.OPTIONAL_HEADER.ImageBase, 16).hex()
                         if lo == 0x1029b4 else None))
    guids = {}
    for name, address in (('factory_iid', 0x14caa4), ('factory_clsid', 0x14cab4)):
        guids[name] = str(uuid.UUID(bytes_le=pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase, 16)))
    assert guids == dict(factory_iid='327abda7-072b-11d3-9d7b-0000f81ef32e',
                         factory_clsid='327abda8-072b-11d3-9d7b-0000f81ef32e')
    return dict(appmain_sha256=APP_SHA, original_sha256=ORIGINAL_SHA, guids=guids, ranges=rows,
                observations=['AppMain already instantiates the same Imaging factory as the USB artwork route',
                              '0x102adc calls CreateImageFromBuffer with disposal value zero and the QByteArray size',
                              'GetImageInfo at 0x102af8 is followed by dimension checks without an HRESULT check',
                              '0x102c90 calls Draw; its HRESULT is not checked before returning the bitmap',
                              'Factory Release at 0x102cb0 precedes QByteArray destruction at 0x102ce0',
                              'No matching IImage Release appears in this function; borrowed stream/source lifetime must be corrected',
                              'The classifier reads eight signature bytes; it is not a JPEG validity or short-input guard',
                              'The cache caller makes Qt copies, inserts bitmaps and evicts after 100 entries; do not use it blindly for live-track ownership'],
                next_contract=['Owned checked JPEG bytes bounded to 128 KiB, with source retained until IImage Release',
                               'Checked COM/image-info/draw/DC/selection results and exact 200x200 thumbnail bounds',
                               'Decode outside the CSR receive callback; publish to AppMain with fresh connection/track identity',
                               'Dialog owns one GDI bitmap, replaced/cleared/destroyed on its GUI thread',
                               'Keep legacy text mapping and existing controls unchanged'],
                firmware_patched=False, image_decoded=False, hardware_tested=False,
                limits=['Static original/retained bytes only; no native COM, GUI paint or JPEG decoder execution',
                        'Missing release is a local instruction observation, not measured unit leak behavior',
                        'No new image IPC, dialog control or GUI publication code is installed'],
                source_pins={'inspect_bt_cover_ui_route.py':hashlib.sha256(Path(__file__).read_bytes()).hexdigest()})


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--original', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    if args.report.exists():
        raise FileExistsError('Use a fresh report')
    result = inspect(args.input.read_bytes(), args.original.read_bytes())
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(ranges=len(result['ranges']), guids=result['guids'], firmware_patched=False), indent=2))
