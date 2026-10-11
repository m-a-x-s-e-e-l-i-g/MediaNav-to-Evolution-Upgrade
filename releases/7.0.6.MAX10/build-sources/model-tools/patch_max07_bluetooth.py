"""Compose guarded Bluetooth feedback corrections onto exact complete MAX06.

Retain all previous code/state except explicitly explained instructions. Extend
the existing RX section; retain the RW/RO virtual addresses and native PE ABI.
"""
import hashlib
import json
import struct
from pathlib import Path

import pefile
import max07_bt_helpers as helpers
import layout_bt_cover_native as layout
import bt_cover_art_task as task
import patch_bt_text_recovery_install as text_install
from patch_usb_seek_completion import assemble

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'build/maxmade-7.0.6.MAX06-artwork-text-local-01/payload/upgrade/Storage Card/System/Blue.exe'
INPUT_SHA = 'cb779597e8bc72b0c3fc2d7137cd7e75629cf66643f234ea3376de5901ab1df0'
BASE = 0x10000


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def patch(raw):
    assert sha(raw) == INPUT_SHA, 'Expected exact latest full MAX06 Blue'
    pe = pefile.PE(data=raw)
    assert pe.FILE_HEADER.Characteristics & 1 and pe.OPTIONAL_HEADER.DATA_DIRECTORY[5].Size == 0
    x, d, m = pe.sections[-3:]
    assert [s.Name.rstrip(b'\0') for s in (x, d, m)] == [b'.mxartx', b'.mxartd', b'.mxartm']
    rows = helpers.assembled()
    assert rows[0]['address'] >= x.VirtualAddress + BASE + x.Misc_VirtualSize
    end = max(r['address'] + len(r['raw']) for r in rows)
    assert end < BASE + d.VirtualAddress
    code = bytearray(pe.get_data(x.VirtualAddress, x.Misc_VirtualSize))
    code.extend(bytes(end - BASE - x.VirtualAddress - len(code)))
    bank = pe.get_data(d.VirtualAddress, d.Misc_VirtualSize)
    assert bank[helpers.STATE - BASE - d.VirtualAddress:helpers.AUDIO - BASE - d.VirtualAddress + 32] == bytes(96)
    edits = []
    prefix = bytearray(raw[:x.PointerToRawData])

    def edit(at, encoded, reason):
        if x.VirtualAddress + BASE <= at < x.VirtualAddress + BASE + x.Misc_VirtualSize:
            offset = at - BASE - x.VirtualAddress
            before = bytes(code[offset:offset + len(encoded)])
            code[offset:offset + len(encoded)] = encoded
        else:
            offset = pe.get_offset_from_rva(at - BASE)
            before = bytes(prefix[offset:offset + len(encoded)])
            prefix[offset:offset + len(encoded)] = encoded
        edits.append(dict(address=hex(at), before_hex=before.hex(), after_hex=encoded.hex(), reason=reason))

    def word(at, before, after, reason):
        assert pe.get_data(at - BASE, 4) == struct.pack('<I', before), hex(at)
        edit(at, struct.pack('<I', after), reason)

    # CSR scheduler bindings retain native profile initialization/handling/drop.
    for high, low, high_reg, destination_reg, old, new in (
        (0x24670, 0x2467c, 8, 5, 0x3b9b8, helpers.INIT),
        (0x24660, 0x24664, 9, 7, 0x3bcc0, helpers.PROFILE),
        (0x2466c, 0x24678, 10, 6, 0x28f400, helpers.DROP)):
        old_high = (old + 0x8000) >> 16
        new_high = (new + 0x8000) >> 16
        word(high, 0x3c000000 | high_reg << 16 | old_high,
             0x3c000000 | high_reg << 16 | new_high, 'Bounded metadata poll scheduler binding')
        word(low, 0x24000000 | high_reg << 21 | destination_reg << 16 | (old & 65535),
             0x24000000 | high_reg << 21 | destination_reg << 16 | (new & 65535),
             'Bounded metadata poll scheduler binding')
    word(0x5374c, (3 << 26) | (0x28bc00 >> 2), (3 << 26) | (helpers.CAPTURE >> 2),
         'Retire owned poll request when the native confirmation factory consumes it')
    word(0x101eb0, 0x28e000, helpers.REQUEST,
         'Consume internal current-track polls without restarting artwork selection')

    # A real connected track event may fetch text even if another notification
    # in the registration group failed. Native request producer checks connection.
    site = 0x200c0
    # Locate the original conditional gate precisely rather than guess its word.
    segment = pe.get_data(site - BASE, 40)
    candidates = [(site + i, struct.unpack_from('<I', segment, i)[0]) for i in range(0, len(segment), 4)
                  if struct.unpack_from('<I', segment, i)[0] >> 26 == 4]
    assert len(candidates) == 1
    at, before = candidates[0]
    assert ((before >> 21) & 31) == 8 and ((before >> 16) & 31) == 0
    word(at, before, 0, 'Track events no longer depend on overall notification registration success')

    # Retry freshness already checks selected connected peer/UID/destination.
    check_row = next(r for r in text_install.helpers() if r['name'] == 'retry_check')
    old = check_row['raw']
    assert pe.get_data(check_row['address'] - BASE, len(old)) == old
    source = check_row['recipe']['source_assembly']
    assert 'bnez t0, done' in source
    revised = source.replace('bnez t0, done', 'b done')
    encoded, _, _ = assemble(revised, check_row['address'], len(old))
    edit(check_row['address'], encoded, 'Connected empty-title recovery independent of notification group status')

    # Mirror native browsing: pass the copied security policy, including zero,
    # unchanged to the CM. Keep range, PSM, ERTM and owner checks intact.
    open_row = next(layout.rewrite('Blue.exe', r) for r in layout.originals('Blue.exe') if r['address'] == task.OPEN)
    assert pe.get_data(open_row['address'] - BASE, len(open_row['raw'])) == open_row['raw']
    source = open_row['recipe']['source_assembly']
    assert source.count('beqz s3, refused') == 1
    encoded, _, _ = assemble(source.replace('beqz s3, refused', 'nop'), open_row['address'], len(open_row['raw']))
    edit(open_row['address'], encoded, 'Honor copied native security policy including its valid zero value')

    # Preserve 4 KiB ownership and two-block fast startup. Increase reserve only
    # after a started-stream drain; bounded burst capacity uses 22 existing slots.
    before = pe.get_data(0x26ef0 - BASE, 16)
    assert before == bytes.fromhex('050008920200092d0700201500000000')
    encoded, _, _ = assemble(f'jal {hex(helpers.THRESHOLD)}\nnop\nbnez v0, 0x26f18\nnop', 0x26ef0, 16)
    edit(0x26ef0, encoded, 'Adaptive restart reserve keeps initial two-block startup')
    word(0x26f24, 0x2d090008, 0x2d090016, 'Accept bursts in 22 of 25 slots, retaining three slots across two-block restart')
    assert pe.get_data(0x264d0 - BASE, 24) == struct.pack('<6I', 0xa1600338, (3 << 26) | (0x8a830 >> 2), 0x8d640008, 0, 0, 0)
    encoded, _, _ = assemble(f'jal {hex(helpers.UNDERFLOW)}\nmove a0, t3\nsb zero, 0x338(t3)\njal 0x8a830\nlw a0, 8(t3)\nnop', 0x264d0, 24)
    edit(0x264d0, encoded, 'Observe genuine live-stream drain before native pause')
    word(0x26cf4, (3 << 26) | (0x8a830 >> 2), (3 << 26) | (helpers.START >> 2),
         'Reset adaptive reserve on a normal source start, preserving native pause')

    for row in rows:
        at = row['address'] - BASE - x.VirtualAddress
        assert not any(code[at:at + len(row['raw'])])
        code[at:at + len(row['raw'])] = row['raw']
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    functions = list(struct.iter_unpack('<5I', pe.get_data(directory.VirtualAddress, directory.Size)))
    added = [(r['address'], r['address'] + r['recipe']['used_bytes'], 0, 0, layout.prolog_end(r)) for r in rows]
    functions = sorted(functions + added)
    assert all(a[1] <= b[0] for a, b in zip(functions, functions[1:]))
    metadata = b''.join(struct.pack('<5I', *r) for r in functions)
    output = prefix
    sections = []
    for section, contents in zip((x, d, m), (bytes(code), bank, metadata)):
        position = len(output)
        size = (len(contents) + 511) // 512 * 512
        struct.pack_into('<I', output, section.get_field_absolute_offset('Misc_VirtualSize'), len(contents))
        struct.pack_into('<I', output, section.get_field_absolute_offset('SizeOfRawData'), size)
        struct.pack_into('<I', output, section.get_field_absolute_offset('PointerToRawData'), position)
        output.extend(contents)
        output.extend(bytes(size - len(contents)))
        sections.append(dict(name=section.Name.rstrip(b'\0').decode(), sha256=sha(contents), bytes=len(contents)))
    for name, value in (
        ('SizeOfCode', pe.OPTIONAL_HEADER.SizeOfCode + ((len(code) + 511) // 512 * 512) - x.SizeOfRawData),
        ('SizeOfInitializedData', pe.OPTIONAL_HEADER.SizeOfInitializedData + ((len(metadata) + 511) // 512 * 512) - m.SizeOfRawData),
        ('SizeOfImage', (m.VirtualAddress + len(metadata) + 4095) // 4096 * 4096)):
        struct.pack_into('<I', output, pe.OPTIONAL_HEADER.get_field_absolute_offset(name), value)
    struct.pack_into('<II', output, directory.get_file_offset(), directory.VirtualAddress, len(metadata))
    checksum = pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I', output, checksum, 0)
    struct.pack_into('<I', output, checksum, pefile.PE(data=bytes(output)).generate_checksum())
    result = bytes(output)
    q = pefile.PE(data=result)
    assert q.OPTIONAL_HEADER.CheckSum == q.generate_checksum()
    assert q.get_overlay_data_start_offset() is None
    assert q.OPTIONAL_HEADER.AddressOfEntryPoint == pe.OPTIONAL_HEADER.AddressOfEntryPoint
    return result, dict(input_sha256=sha(raw), sha256=sha(result), edits=edits, sections=sections,
                        helpers=[{k: v for k, v in r.items() if k not in ('raw','relocations')} for r in rows],
                        new_functions=added, baseline='MAX06', native_executed=False, hardware_tested=False)


if __name__ == '__main__':
    result, report = patch(SOURCE.read_bytes())
    output = ROOT / 'build/max07-bluetooth-development-01'
    output.mkdir(exist_ok=False)
    (output / 'Blue.exe').write_bytes(result)
    (output / 'recipe.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(sha256=sha(result), bytes=len(result), new_helpers=len(report['helpers'])), indent=2))
