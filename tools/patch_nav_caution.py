"""Default the MediaNav recurring Nav caution to accepted; no CE execution.

Only nine original MIPS instructions and the PE checksum change. The existing
dialog/launch handlers, Nav executable, legal files and skin remain intact.
"""
from pathlib import Path
import json
import struct
import pefile
from build_home_theme import sha

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / 'build/max17-volume-development-01/payload'
OUT = ROOT / 'build/nav-caution-development-01'
APP = 'upgrade/Storage Card/System/AppMain.exe'
PIN = '7df16aebf6f2aec99b60fb341c28552dfc4b9a2b73183d0fdc41cdd81a506c95'
RESETS = (0xb162c, 0xc34f0, 0xe59b0, 0xe5c60)


def patch(raw):
    assert sha(raw) == PIN
    pe = pefile.PE(data=raw)
    out = bytearray(raw)
    # Keep the exact constructor frame/control initializers and dialog ID 0x55.
    # Allocation failure already leaves s0=0: branch straight to its publication.
    changes = [
        (0x13000, '1d000012', 0x1200001e, 'Preserve null allocation path after constructor tail rewrite'),
        (0x13060, '5c1600ae', 0xae0802c0, 'Keep native caution dialog ID 0x55, storing it earlier'),
        (0x13070, '02000010', 0x24080001, 'Initialize recurring-warning acceptance to exact Boolean 1'),
        (0x13074, 'c00208ae', 0xae08165c, 'Store acceptance without changing other caution state fields'),
        (0x13078, '25800000', 0, 'Keep successful object pointer; failure branches past this slot'),
    ] + [(va, '5c1640ac', 0, 'Retain warning acceptance across native Nav stop/restart') for va in RESETS]
    edits = []
    for va, expected, word, reason in changes:
        offset = pe.get_offset_from_rva(va - pe.OPTIONAL_HEADER.ImageBase)
        before = raw[offset:offset + 4]
        assert before.hex() == expected, hex(va)
        after = struct.pack('<I', word)
        out[offset:offset + 4] = after
        edits.append(dict(address=va, offset=offset, before_hex=expected, after_hex=after.hex(), reason=reason))
    checksum = pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I', out, checksum, 0)
    check = pefile.PE(data=bytes(out))
    struct.pack_into('<I', out, checksum, check.generate_checksum())
    check.close()
    allowed = {i for e in edits for i in range(e['offset'], e['offset'] + 4)} | set(range(checksum, checksum + 4))
    assert len(raw) == len(out)
    assert all(a == b or i in allowed for i, (a, b) in enumerate(zip(raw, out)))
    after_pe = pefile.PE(data=bytes(out))
    assert after_pe.verify_checksum()
    for index in (1, 3, 5, 12):
        directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[index]
        assert pe.get_data(directory.VirtualAddress, directory.Size) == after_pe.get_data(directory.VirtualAddress, directory.Size)
    assert pe.OPTIONAL_HEADER.SizeOfImage == after_pe.OPTIONAL_HEADER.SizeOfImage
    assert [(s.Name,s.VirtualAddress,s.Misc_VirtualSize,s.SizeOfRawData,s.Characteristics) for s in pe.sections] == [
        (s.Name,s.VirtualAddress,s.Misc_VirtualSize,s.SizeOfRawData,s.Characteristics) for s in after_pe.sections]
    after_pe.close(); pe.close()
    result = bytes(out)
    return result, dict(before_sha256=sha(raw), after_sha256=sha(result), bytes=len(result),
        edits=edits, instruction_count=9, checksum_offset=checksum,
        imports_unwind_relocations_sections_unchanged=True, native_executed=False, hardware_tested=False)


if __name__ == '__main__':
    assert not OUT.exists(), 'Keep previous candidates immutable'
    raw, recipe = patch((BASE / APP).read_bytes())
    path = OUT / 'payload' / APP
    path.parent.mkdir(parents=True)
    path.write_bytes(raw)
    (OUT / 'recipe.json').write_text(json.dumps(recipe, indent=2) + '\n')
    print(json.dumps(recipe, indent=2))
