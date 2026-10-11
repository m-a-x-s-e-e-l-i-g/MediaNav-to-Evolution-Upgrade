"""Exact MAX07 successor: native text compatibility and popup-safe artwork.

Firmware is never executed on this host. Retain complete MAX07 binaries and
modify reviewed bindings/drawing functions only. Dormant text helper bytes stay
present, but ordinary metadata no longer passes through the experimental owner,
strict receiver or poll/retry scheduler. Native status/interim/UID safeguards stay.
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
import patch_bt_cover_install as cover
import layout_bt_cover_native as layout
import bt_cover_art_app_paint as paint
from patch_usb_seek_completion import assemble
from patch_shared_mapping_checks import reloc_records
import max07_artwork_frame

BASE = 0x10000
SYSTEM = Path('upgrade/Storage Card/System')
PREVIOUS = REPO / 'build/maxmade-7.0.6.MAX07-local-01/roundtrip'
NATIVE = REPO / 'build/maxmade-7.0.6.MAX05-local/payload'
OUT = ROOT / 'build/max08-native-development-02'
PINS = {'Blue.exe': '8a0d0273ad65cd3e3f0eea55821bd1ab4456740f7026040b5e354cfd38a3b091',
        'AppMain.exe': '28290d357badd7b8c0765d4bd5645946eff81a37a8cec2979cb031f01f97dad7'}


def sha(raw): return hashlib.sha256(raw).hexdigest()


def checksum(out, pe):
    at = pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I', out, at, 0)
    struct.pack_into('<I', out, at, pefile.PE(data=bytes(out)).generate_checksum())


def blue(raw):
    assert sha(raw) == PINS['Blue.exe']
    p = pefile.PE(data=raw)
    compatible, _ = cover.patch('Blue.exe', (NATIVE / SYSTEM / 'Blue.exe').read_bytes())
    assert sha(compatible) == '062e951bd6b49a3f9e21175476e6947b115d79803003d3c63ccda5dd9d3b9b22'
    native = pefile.PE(data=compatible)
    out = bytearray(raw)
    edits = []
    sites = {
        0x5374c: 'Native confirmation factory with retained artwork capture',
        0x712a0: 'Native metadata parser with artwork-only response bridge',
        0x52b68: 'Native interim posting with artwork-only identity tracking',
        0x20d1c: 'Native final text handler rather than experimental strict receiver',
        0x20d2c: 'Native interim text handler rather than experimental strict receiver',
        0x101eb4: 'Native continuation request dispatcher',
        0x101eb0: 'Native track request with retained artwork selection',
        0x24670: 'Native AVRCP task initialization; remove experimental poll arming',
        0x2467c: 'Native AVRCP task initialization',
        0x24660: 'Native AVRCP profile processing',
        0x24664: 'Native AVRCP profile processing',
        0x2466c: 'Retained artwork teardown without experimental text scheduler',
        0x24678: 'Retained artwork teardown',
        0x51ba0: 'Retained native disconnect lookup',
    }
    for at, reason in sites.items():
        off = p.get_offset_from_rva(at - BASE)
        before, after = raw[off:off+4], native.get_data(at - BASE, 4)
        assert len(after) == 4
        if before == after: continue
        out[off:off+4] = after
        edits.append(dict(address=hex(at), offset=off, before_hex=before.hex(),
                          after_hex=after.hex(), reason=reason))
    # Native handlers must advance the attribute counter for an empty album or
    # artist. Otherwise the next walker failure discards an already valid title.
    # Match the retained interim progress fix; leave failure/status guards intact.
    for at in (0x1fba0,0x1fbe0):
        off=p.get_offset_from_rva(at-BASE)
        before=bytes(out[off:off+4])
        word=struct.unpack('<I',before)[0]
        assert word>>26==4 and ((word>>21)&31)==9 and ((word>>16)&31)==0
        old_target=at+4+struct.unpack('<h',before[:2])[0]*4
        assert old_target==0x1fc78
        after=struct.pack('<I',(4<<26)|(9<<21)|((0x1fc70-at-4)//4 & 65535))
        out[off:off+4]=after
        edits.append(dict(address=hex(at),offset=off,before_hex=before.hex(),after_hex=after.hex(),
                          reason='Advance native final counter past empty optional album/artist'))
    checksum(out, p)
    result = bytes(out)
    q = pefile.PE(data=result)
    # MAX07 PCM routines, source focus, queue sizing and artwork CM policy stay.
    for lo, hi in ((0x264c0,0x26500), (0x26cc0,0x26d08), (0x26ee0,0x26f28),
                   (0x293000,0x293c00), (0x246400,0x246800), (0x1fce8,0x1ff40)):
        assert p.get_data(lo-BASE,hi-lo) == q.get_data(lo-BASE,hi-lo)
    for at in (0x1fab4,0x1fb28,0x1fb6c):assert p.get_data(at-BASE,4)==q.get_data(at-BASE,4)
    for at in sites: assert q.get_data(at-BASE,4) == native.get_data(at-BASE,4)
    return result, dict(input_sha256=sha(raw), sha256=sha(result), edits=edits,
                       compatibility_reference_sha256=sha(compatible),
                       text_route='retained native handlers, experimental ownership/stream/retry/poll unbound',
                       max07_audio_exact=True, native_status_interim_uid_safeguards_exact=True,
                       empty_optional_fields_advance=True,
                       hardware_tested=False)


def app(raw):
    assert sha(raw) == PINS['AppMain.exe']
    p = pefile.PE(data=raw)
    section = p.sections[-1]
    assert section.Name.rstrip(b'\0') == b'.mxlabel'
    assert section.PointerToRawData + section.SizeOfRawData == len(raw)
    out, edits = bytearray(raw), []
    frame_at, text_at = 0x340000, 0x341000
    # Separate background/main children from popup foreground. A popup object
    # exists even while hidden: native 13d164 decides which controls are visible.
    source = max07_artwork_frame.source(text_at)
    source = source.replace('jal 0x134e1c\nnop\nmove s4, v0',
                            'addiu a0, s0, 4\nmove a1, zero\njal 0x13d098\nnop\n'
                            'addiu a0, s0, 4\njal 0x13d164\nnop\nmove s4, zero')
    assert 'lw t0, 0x78(s0)\nbnez t0, done\nnop' in source
    source = source.replace('lw t0, 0x78(s0)\nbnez t0, done\nnop\n','')
    original_draw = layout.rewrite('AppMain.exe', next(r for r in layout.originals('AppMain.exe')
                                                      if r['address'] == paint.DRAW))
    draw_source = original_draw['recipe']['source_assembly'].replace('jal 0x134e1c', 'jal 0x340000')
    assert 'lw t0, 0x78(s1)\nbnez t0, done\nnop' in draw_source
    draw_source = draw_source.replace('lw t0, 0x78(s1)\nbnez t0, done\nnop\n','')
    assert 'done:\nmove v0, s7' in draw_source
    draw_source = draw_source.replace('done:\nmove v0, s7', '''done:
lw a0, 0x78(s1)
beqz a0, foreground
nop
jal 0x13d164
addiu a0, a0, 4
foreground:
lw t0, 0(s1)
lw t0, 0x2c(t0)
jalr t0
move a0, s1''')
    functions = []
    for name, at, code in (('popup_safe_artwork_frame', frame_at, source),
                           ('popup_safe_cover_draw', paint.DRAW, draw_source)):
        encoded, recipe, rel = assemble(code, at, 0x1000)
        # SRCCOPY is a literal raster operation, never an image-base pointer.
        pc, excluded = at, set()
        for line in recipe['source_assembly'].splitlines():
            line = line.split('#')[0].strip()
            if not line or line.endswith(':'): continue
            if line.startswith('la '):
                if int(line.rsplit(',',1)[1].strip(),0) == 0xcc0020: excluded.update((pc-BASE,pc-BASE+4))
                pc += 8
            else: pc += 4
        rel = [r for r in rel if r[0] not in excluded]
        offset = p.get_offset_from_rva(at-BASE)
        before = bytes(out[offset:offset+len(encoded)])
        out[offset:offset+len(encoded)] = encoded
        edits.append(dict(address=hex(at), offset=offset, before_hex=before.hex(),
                          after_hex=encoded.hex(), reason=name))
        functions.append(dict(name=name,address=at,raw=encoded,recipe=recipe,relocations=rel))
    directory = p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows = list(struct.iter_unpack('<5I',p.get_data(directory.VirtualAddress,directory.Size)))
    for f in functions:
        old = next(r for r in rows if r[0] == f['address'])
        rows[rows.index(old)] = (old[0],old[0]+f['recipe']['used_bytes'],old[2],old[3],old[4])
    assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    records = reloc_records(p)
    old_meta = (directory.VirtualAddress, directory.VirtualAddress+directory.Size)
    records = [r for r in records if not (old_meta[0]<=r[0]<old_meta[1]) and
               not any(f['address']-BASE<=r[0]<f['address']-BASE+0x1000 for f in functions)]
    records += [r for f in functions for r in f['relocations']]
    for i,row in enumerate(rows):
        records += [(directory.VirtualAddress+i*20+j*4,3,None) for j,v in enumerate(row) if v]
    meta = b''.join(struct.pack('<5I',*r) for r in rows)
    metadata_offset = directory.VirtualAddress-section.VirtualAddress
    assert metadata_offset == 0x3000
    body = bytearray(out[section.PointerToRawData:section.PointerToRawData+metadata_offset])
    body.extend(meta)
    rel_offset = len(body)
    relocation_table = cover.relocation_table(records)
    body.extend(relocation_table)
    virtual_bytes = len(body)
    raw_bytes = cover.align(virtual_bytes,p.OPTIONAL_HEADER.FileAlignment)
    body.extend(bytes(raw_bytes-len(body)))
    out = out[:section.PointerToRawData]+body
    struct.pack_into('<I',out,section.get_field_absolute_offset('Misc_VirtualSize'),virtual_bytes)
    struct.pack_into('<I',out,section.get_field_absolute_offset('SizeOfRawData'),raw_bytes)
    struct.pack_into('<II',out,p.OPTIONAL_HEADER.DATA_DIRECTORY[5].get_file_offset(),
                     section.VirtualAddress+rel_offset,len(relocation_table))
    for field,value in (
        ('SizeOfCode',p.OPTIONAL_HEADER.SizeOfCode+raw_bytes-section.SizeOfRawData),
        ('SizeOfImage',cover.align(section.VirtualAddress+virtual_bytes,p.OPTIONAL_HEADER.SectionAlignment))):
        struct.pack_into('<I',out,p.OPTIONAL_HEADER.get_field_absolute_offset(field),value)
    checksum(out,p)
    result = bytes(out)
    q = pefile.PE(data=result)
    for at,size in ((0x33f000,0x800),(0x33f800,0x800)):
        assert p.get_data(at-BASE,size) == q.get_data(at-BASE,size), 'MAX07 label helper/lookup changed'
    for at in (0x13ed30,0x13ed54,0x13f29c,0x150c44,0x3c81c,0x3c824):
        assert p.get_data(at-BASE,8) == q.get_data(at-BASE,8)
    assert q.OPTIONAL_HEADER.CheckSum == q.generate_checksum()
    assert q.get_overlay_data_start_offset() is None
    return result, dict(input_sha256=sha(raw),sha256=sha(result),edits=edits,
                       functions=[{k:v for k,v in f.items() if k!='raw'} for f in functions],
                       artwork=dict(address=frame_at,text_va=text_at,rectangle=[24,116,128,128]),
                       max07_label_helpers_lookup_hooks_exact=True,
                       popup_allocation_no_longer_suppresses_artwork=True,
                       popup_foreground_drawn_last=True,hardware_tested=False)


def build():
    OUT.mkdir(parents=True,exist_ok=False)
    report = {}
    for name,fn in (('Blue.exe',blue),('AppMain.exe',app)):
        original = (PREVIOUS/SYSTEM/name).read_bytes()
        result,recipe = fn(original)
        (OUT/name).write_bytes(result)
        report[name] = recipe
    (OUT/'recipe.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    return dict(output=str(OUT),modules={n:r['sha256'] for n,r in report.items()})


if __name__=='__main__': print(json.dumps(build(),indent=2))
