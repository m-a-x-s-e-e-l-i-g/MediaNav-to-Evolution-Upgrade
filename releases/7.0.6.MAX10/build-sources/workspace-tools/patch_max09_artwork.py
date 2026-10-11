"""Exact MAX08 successor: accept the copied native zero artwork policy.

Only the redundant selection refusal changes. Native OPEN already passes the
same zero policy through. Keep every title/audio/UI byte and all PE tables.
"""
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPO = ROOT / 'sources/MediaNav-usb-seek-timing'
sys.path.insert(0, str(REPO / 'tools'))
import pefile
import layout_bt_cover_native as layout
import bt_cover_art_lifecycle as lifecycle

BASE = 0x10000
SYSTEM = Path('upgrade/Storage Card/System')
PREVIOUS = REPO / 'build/maxmade-7.0.6.MAX08-local-01/roundtrip'
NATIVE = REPO / 'build/maxmade-7.0.6.MAX05-local/payload'
OUT = ROOT / 'build/max09-artwork-development-01'
PINS = {'Blue.exe': '6c3ce798ea642b2d5e112b0bae19f9044f2e48b7d6c39e1b3a0b4906266079fb',
        'AppMain.exe': '49d4a9a2e3d746c4e5e0a9a7d1f92baa51e53d7dd65a7e5f25636d6cf89a3350'}

def sha(raw): return hashlib.sha256(raw).hexdigest()

def blue(raw):
    assert sha(raw) == PINS['Blue.exe']
    pe = pefile.PE(data=raw)
    row = next(r for r in layout.plan('Blue.exe', (NATIVE/SYSTEM/'Blue.exe').read_bytes())['helpers']
               if r['address'] == lifecycle.RAW_RESOLVE)
    assert pe.get_data(row['address']-BASE, len(row['raw'])) == row['raw']
    words = list(struct.iter_unpack('<I', row['raw']))
    # lhu t0, 0x1e(sp); beqz t0, bad; nop, immediately after peer MATCH.
    matches = [i for i in range(len(words)-2) if words[i][0] == 0x97a8001e
               and words[i+1][0] >> 16 == 0x1100 and words[i+2][0] == 0]
    assert len(matches) == 1
    at = row['address'] + 4*(matches[0]+1)
    offset = pe.get_offset_from_rva(at-BASE)
    out = bytearray(raw)
    before = raw[offset:offset+4]
    out[offset:offset+4] = bytes(4)
    check = pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I', out, check, 0)
    struct.pack_into('<I', out, check, pefile.PE(data=bytes(out)).generate_checksum())
    result = bytes(out)
    allowed = set(range(offset, offset+4)) | set(range(check, check+4))
    assert len(raw) == len(result)
    assert all(a == b or i in allowed for i,(a,b) in enumerate(zip(raw,result)))
    return result, dict(input_sha256=sha(raw), sha256=sha(result),
                        edits=[dict(address=at, offset=offset, before_hex=before.hex(),
                                    after_hex='00000000', purpose='Pass copied zero policy to existing native OPEN')],
                        audio_title_UI_and_all_other_bytes_equal_MAX08=True,
                        hardware_tested=False)

def app(raw):
    assert sha(raw) == PINS['AppMain.exe']
    return raw, dict(input_sha256=sha(raw), sha256=sha(raw), edits=[],
                     byte_identical_MAX08=True, hardware_tested=False)

def build():
    OUT.mkdir(parents=True, exist_ok=False)
    report = {}
    for name, fn in (('Blue.exe',blue),('AppMain.exe',app)):
        result, recipe = fn((PREVIOUS/SYSTEM/name).read_bytes())
        (OUT/name).write_bytes(result)
        report[name] = recipe
    (OUT/'recipe.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    return dict(output=str(OUT),modules={n:r['sha256'] for n,r in report.items()})

if __name__ == '__main__': print(json.dumps(build(),indent=2))
