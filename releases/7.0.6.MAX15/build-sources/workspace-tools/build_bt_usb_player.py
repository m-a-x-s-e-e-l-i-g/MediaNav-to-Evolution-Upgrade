"""Use USB player presentation with retained Bluetooth commands and artwork ownership."""
import json
import shutil
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REPO = ROOT / 'sources/MediaNav-usb-seek-timing'
sys.path.insert(0, str(ROOT / 'tools/python-libs'))
sys.path.insert(0, str(REPO / 'tools'))
import pefile
from patch_usb_seek_completion import assemble
from patch_shared_mapping_checks import reloc_records
import patch_bt_cover_install as container
from build_home_theme import sha
from inspect_av_layouts import trace

BASELINE = REPO / 'build/maxmade-7.0.6.MAX12-settings-local-02'
OUT = ROOT / 'build/bt-usb-player-development-01'
APP = Path('upgrade/Storage Card/System/AppMain.exe')
APP_SHA = '9ac4bee249ed0b5813f40f8094ab5faabcca7bcce1905b6e1f3ccfb05315daf2'
BASE = 0x10000
RECT = (27, 98, 278, 278)


def frame_source():
    # Borrow the same cached no-album HBITMAP as native USB. Never delete it.
    # Existing foreground/popup drawing remains in the outer cover painter.
    return '''
addiu sp, sp, -0x48
sw ra, 0x44(sp)
sw s0, 0x40(sp)
sw s1, 0x3c(sp)
sw s2, 0x38(sp)
sw s3, 0x34(sp)
sw s4, 0x30(sp)
move s0, a0
addiu a0, s0, 4
move a1, zero
jal 0x13d098
nop
addiu a0, s0, 4
jal 0x13d164
nop
move s4, zero
lw s1, 0x28(s0)
beqz s1, done
nop
la t0, 0x186538
lw a0, 0(t0)
beqz a0, done
nop
jal 0x13dde0
addiu a1, zero, 117
beqz v0, done
nop
move s2, v0
move a0, zero
jal 0x223000
nop
beqz v0, done
nop
move s3, v0
move a0, s3
jal 0x223100
move a1, s2
beqz v0, delete_dc
nop
addiu t0, zero, -1
beq v0, t0, delete_dc
nop
move s2, v0
move a0, s1
addiu a1, zero, 27
addiu a2, zero, 98
addiu a3, zero, 278
addiu t0, zero, 278
sw t0, 0x10(sp)
sw s3, 0x14(sp)
sw zero, 0x18(sp)
sw zero, 0x1c(sp)
sw t0, 0x20(sp)
sw t0, 0x24(sp)
la t0, 0xcc0020
sw t0, 0x28(sp)
la t9, 0x185250
lw t9, 0(t9)
jalr t9
nop
move a0, s3
jal 0x223100
move a1, s2
delete_dc:
move a0, s3
jal 0x223200
nop
done:
move v0, s4
lw s4, 0x30(sp)
lw s3, 0x34(sp)
lw s2, 0x38(sp)
lw s1, 0x3c(sp)
lw s0, 0x40(sp)
lw ra, 0x44(sp)
jr ra
addiu sp, sp, 0x48
'''


def patch(raw):
    assert sha(raw) == APP_SHA
    pe = pefile.PE(data=raw)
    out = bytearray(raw)
    edits = []

    def write(at, before, after, purpose):
        off = pe.get_offset_from_rva(at - BASE)
        assert raw[off:off + len(before)] == before, hex(at)
        out[off:off + len(after)] = after
        assert len(before) == len(after)
        edits.append(dict(address=at, offset=off, before_hex=before.hex(),
                          after_hex=after.hex(), purpose=purpose))

    def immediate(at, old, new, purpose):
        word = struct.unpack('<I', pe.get_data(at - BASE, 4))[0]
        assert word & 65535 == old and word >> 26 in (9, 13, 35), hex(at)
        write(at, struct.pack('<I', word), struct.pack('<I', word & 0xffff0000 | new), purpose)

    for at, old, new in ((0x3b38c,163,361),(0x3b394,132,105),(0x3b39c,474,412),
                         (0x3b448,474,412),(0x3b44c,163,361),(0x3b45c,185,158),
                         (0x3b460,45,40),(0x3b4cc,14,12),(0x3b4c8,0x40,0x38),
                         (0x3b424,0x801,0x821),(0x3b4e4,0x801,0x821),
                         (0x3b4fc,118,361),(0x3b504,256,293),(0x3b508,190,139),
                         (0x3b51c,158,119),(0x3b540,307,499),(0x3b54c,187,136),
                         (0x3b55c,159,120),(0x3b57c,493,634),(0x3b590,160,122)):
        immediate(at, old, new, 'USB geometry, fonts, left alignment and exact USB resource binding')

    # Use the reviewed current draw/refresh assembly as an exact byte guard.
    old_recipe = json.loads((ROOT / 'build/max08-native-development-02/recipe.json').read_bytes())['AppMain.exe']
    draw = next(f for f in old_recipe['functions'] if f['address'] == 0x235000)
    code = draw['recipe']['source_assembly']
    replacements = [('addiu a1, zero, 24', 'addiu a1, zero, 27'),
                    ('addiu a2, zero, 116', 'addiu a2, zero, 98'),
                    ('addiu a3, zero, 128', 'addiu a3, zero, 278'),
                    ('addiu t0, zero, 128', 'addiu t0, zero, 278')]
    previous, _, _ = assemble(code, 0x235000, 0x1000)
    for before, after in replacements:
        assert code.count(before) == 1
        code = code.replace(before, after)
    candidate, _, _ = assemble(code, 0x235000, 0x1000)
    for i in range(0, len(candidate), 4):
        if candidate[i:i+4] != previous[i:i+4]:
            write(0x235000+i, previous[i:i+4], candidate[i:i+4], 'Received cover uses USB artwork slot')
    assert pe.get_data(0x235000-BASE, len(previous)) == previous

    # All successful/stale/partial-blit refreshes copy the whole new artwork slot.
    import layout_bt_cover_native as layout
    refresh_row = layout.rewrite('AppMain.exe', next(r for r in layout.originals('AppMain.exe') if r['address']==0x236000))
    refresh_raw = refresh_row['raw']
    assert pe.get_data(0x236000-BASE, len(refresh_raw)) == refresh_raw
    instructions = []
    for i in range(0, len(refresh_raw), 4):
        word = struct.unpack_from('<I', refresh_raw, i)[0]
        if word >> 16 == 0x2408 and word & 65535 in (24,116,128):
            old = word & 65535
            new = {24:27,116:98,128:278}[old]
            immediate(0x236000+i, old, new, 'Refresh copies the USB artwork rectangle')
            instructions.append(old)
    assert instructions == [24,116,128,128]

    # Image wrappers are already installed; pin their exact semantic bindings.
    from bt_cover_art_image import CREATE_DC, SELECT, DELETE_DC
    code = frame_source().replace('0x223000', hex(CREATE_DC)).replace('0x223100', hex(SELECT)).replace('0x223200', hex(DELETE_DC))
    frame, frame_recipe, new_relocations = assemble(code, 0x340000, 0x1000)
    write(0x340000, pe.get_data(0x340000-BASE, 0x1000), frame, 'Native USB no-album resource instead of Album art caption')
    # SRCCOPY is a literal, not a relocated image pointer.
    pc = 0x340000
    excluded = set()
    for line in frame_recipe['source_assembly'].splitlines():
        line = line.split('#')[0].strip()
        if not line or line.endswith(':'): continue
        if line.startswith('la '):
            if int(line.rsplit(',',1)[1].strip(),0) == 0xcc0020: excluded.update((pc-BASE,pc-BASE+4))
            pc += 8
        else: pc += 4
    new_relocations = [r for r in new_relocations if r[0] not in excluded]
    pd = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows = list(struct.iter_unpack('<5I', pe.get_data(pd.VirtualAddress, pd.Size)))
    index = next(i for i,r in enumerate(rows) if r[0] == 0x340000)
    row = rows[index]
    assert row[4] == 0x34001c
    newrow = (row[0], row[0]+frame_recipe['used_bytes'], *row[2:])
    write(BASE+pd.VirtualAddress+index*20, struct.pack('<5I',*row), struct.pack('<5I',*newrow), 'Updated fallback painter unwind range')
    records = [r for r in reloc_records(pe) if not 0x340000-BASE <= r[0] < 0x341000-BASE]
    records += new_relocations
    rd = pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    table = container.relocation_table(records)
    section = pe.sections[-1]
    at = rd.VirtualAddress - section.VirtualAddress
    assert at+len(table) <= section.SizeOfRawData
    off = pe.get_offset_from_rva(rd.VirtualAddress)
    before = raw[off:section.PointerToRawData+section.SizeOfRawData]
    replacement = table + bytes(len(before)-len(table))
    write(BASE+rd.VirtualAddress, before, replacement, 'Fallback painter relocation records; all other records retained')
    head = rd.get_file_offset()
    out[head+4:head+8] = struct.pack('<I',len(table))
    vs = max(section.Misc_VirtualSize, at+len(table))
    struct.pack_into('<I',out,section.get_field_absolute_offset('Misc_VirtualSize'),vs)
    checksum = pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I',out,checksum,0)
    struct.pack_into('<I',out,checksum,pefile.PE(data=bytes(out)).generate_checksum())
    result = bytes(out)
    assert len(result) == len(raw)
    allowed = {i for e in edits for i in range(e['offset'],e['offset']+len(bytes.fromhex(e['after_hex'])))}
    allowed |= set(range(checksum,checksum+4)) | set(range(head+4,head+8)) | set(range(section.get_field_absolute_offset('Misc_VirtualSize'),section.get_field_absolute_offset('Misc_VirtualSize')+4))
    assert all(a==b or i in allowed for i,(a,b) in enumerate(zip(raw,result)))
    return result, dict(input_sha256=sha(raw),sha256=sha(result),edits=edits,
                        artwork=dict(address=0x340000,text_va=0x341000,rectangle=list(RECT)),
                        frame=frame_recipe,frame_relocations=new_relocations,
                        native_execution=False,hardware_tested=False)


def build():
    assert not OUT.exists()
    previous = {r['path']:r['after'] for r in json.loads((BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918
    for name,row in previous.items(): assert sha((BASELINE/'payload'/name).read_bytes()) == row['sha256']
    raw = (BASELINE/'payload'/APP).read_bytes()
    candidate, recipe = patch(raw)
    shutil.copytree(BASELINE/'payload', OUT/'payload')
    (OUT/'payload'/APP).write_bytes(candidate)
    members=[]
    for name,row in sorted(previous.items()):
        content=(OUT/'payload'/name).read_bytes()
        if name != APP.as_posix(): assert sha(content)==row['sha256']
        members.append(dict(path=name,bytes=len(content),sha256=sha(content)))
    (OUT/'recipe.json').write_text(json.dumps(recipe,indent=2)+'\n')
    (OUT/'manifest.json').write_text(json.dumps(dict(baseline='7.0.6.MAX12',members=members,
        changed_members=[APP.as_posix()],retained_members=1917,hardware_tested=False,native_executed=False),indent=2)+'\n')
    return dict(output=str(OUT),app_sha256=sha(candidate),members=len(members))


if __name__=='__main__': print(json.dumps(build(),indent=2))
