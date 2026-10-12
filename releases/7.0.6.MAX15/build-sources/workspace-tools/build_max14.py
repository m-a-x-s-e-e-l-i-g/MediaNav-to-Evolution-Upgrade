"""Full MAX13 successor: native BT state binding, light resources, cover diagnostics.

No CE program is executed. Device-specific decoder failure remains unproven.
"""
import json
import shutil
import struct
import sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]
REPO = ROOT/'sources/MediaNav-usb-seek-timing'
sys.path.insert(0,str(ROOT/'tools/python-libs'))
sys.path.insert(1,str(REPO/'tools'))
sys.path.insert(0,str(ROOT/'tools'))
import pefile
from PIL import Image
from build_home_theme import sha,encode_like,verify,KEY
from patch_usb_seek_completion import assemble
from patch_shared_mapping_checks import reloc_records
from patch_bt_cover_install import relocation_table
from patch_updater_copy_safety import frame,end
import layout_bt_cover_native as layout
import bt_cover_art_image as imaging
import bt_cover_art_app_lifetime as lifetime
from build_bt_usb_player import frame_source

BASE=0x10000
BASELINE=REPO/'build/maxmade-7.0.6.MAX13-player-local-01'
OUT=ROOT/'build/max14-development-02'
APP=Path('upgrade/Storage Card/System/AppMain.exe')
SYSTEM=Path('upgrade/Storage Card/System')
APP_SHA='cda45d91c1b269d6b6d9d5d23373eacf74f5d34ee832d79178ef88050d5903c0'
STATE=0x300080
STAGE=0x3000a0
CAPTURE,ICON,RECOVER,DIAGNOSTIC=0x341000,0x341300,0x341500,0x341700
STRINGS=0x341c00
LIGHT_BG=(239,243,246)
INK=(28,38,45)
CATALOG=json.loads((ROOT/'analysis/firmware/appmain-startup-contracts.json').read_bytes())['resources']

def oscall(iat):return f'la t9, {hex(iat)}\nlw t9, 0(t9)\njalr t9\nnop'

def capture_source():
    # Executed by the native Blue message manager. No UI access across threads:
    # only publish the scalar status and enqueue a window message.
    regs=['v0','v1','a1','a2','a3','t1','t2','t3','t4','t5','t6','t7','t8','t9']
    stores='\n'.join(f'sw {r}, {0x10+4*i}(sp)' for i,r in enumerate(regs))
    loads='\n'.join(f'lw {r}, {0x10+4*i}(sp)' for i,r in enumerate(regs))
    return f'''addiu sp, sp, -0x60
sw ra, 0x58(sp)
{stores}
lw a0, 8(s2)
lui t0, 0x307
ori t0, t0, 0x801
beq a0, t0, playing
nop
lui t0, 0x307
ori t0, t0, 0x901
beq a0, t0, paused
nop
lui t0, 0x301
ori t0, t0, 0x806
bne a0, t0, done
nop
move t1, zero
b store
nop
playing:
addiu t1, zero, 1
b store
nop
paused:
addiu t1, zero, 2
store:
la t0, {hex(STATE)}
sw t1, 0(t0)
la t0, 0x188270
lw t0, 0(t0)
beqz t0, done
nop
lw a0, 0x50(t0)
beqz a0, done
nop
ori a1, zero, 0x82f3
move a2, zero
move a3, zero
{oscall(0x185040)}
done:
{loads}
lw ra, 0x58(sp)
lui t0, 0x307
lw a0, 8(s2)
jr ra
addiu sp, sp, 0x60'''

def icon_source():
    # a0=redraw requested. The original BT command/event identity is unchanged.
    return f'''{frame(0x28,['s0','s1','s2'])}
move s2, a0
la t0, 0x188270
lw s0, 0(t0)
beqz s0, done
nop
lw t0, 0x50(s0)
beqz t0, done
nop
addiu s0, s0, 0x1458
lw t0, 0x28(s0)
addiu t1, zero, 120
beq t0, t1, choose
nop
addiu t1, zero, 121
bne t0, t1, done
nop
choose:
addiu s1, zero, 120
la t1, {hex(STATE)}
lw t1, 0(t1)
addiu t2, zero, 1
bne t1, t2, selected
nop
addiu s1, zero, 121
selected:
beq s1, t0, done
nop
move a0, s0
jal 0x139104
move a1, s1
beqz s2, done
nop
jal 0x139020
move a0, s0
done:
move v0, zero
{end(0x28,['s0','s1','s2'])}'''

def recover_source():
    # Called only from the GUI window handler. Retry an unstarted worker at
    # most 3 times per HWND, at least 1 second apart. Existing START/REAP keep
    # the priority, suspended creation, generation, and nonblocking join gates.
    return f'''{frame(0x28,['s0','s1'])}
la t0, 0x188270
lw s0, 0(t0)
beqz s0, done
nop
lw s1, 0x50(s0)
beqz s1, done
nop
la t0, 0x300020
lw t0, 12(t0)
bnez t0, done
nop
la t0, {hex(STATE)}
lw t1, 4(t0)
beq t1, s1, existing
nop
sw s1, 4(t0)
sw zero, 8(t0)
sw zero, 12(t0)
existing:
lw t1, 8(t0)
sltiu t2, t1, 3
beqz t2, done
nop
{oscall(0x185000)}
la t0, {hex(STATE)}
lw t1, 8(t0)
beqz t1, attempt
nop
lw t2, 12(t0)
subu t2, v0, t2
sltiu t2, t2, 1000
bnez t2, done
nop
attempt:
sw v0, 12(t0)
addiu t1, t1, 1
sw t1, 8(t0)
move a0, s1
jal 0x238000
move a1, s0
done:
move v0, zero
{end(0x28,['s0','s1'])}'''

CAPTIONS=['Cover starting (S0)','Waiting for cover (S1)',
          'Worker stopped (S2)','Checking cover (D1)',
          'Decoder failed (D2)','Decode failed (D3)',
          'Image info failed (D4)','Drawing failed (D5)',
          'Bitmap failed (D6)','Selection failed (D7)',
          'Rendering failed (D8)','Cover decoded (D9)']

def diagnostic_source():
    # a0=dialog. Temporary car-test caption appears only without a displayed
    # bitmap; it never covers a popup or any playback/metadata widget.
    return f'''{frame(0x50,['s0','s1','s2','s3','s4'])}
move s0, a0
lw s1, 0x28(s0)
beqz s1, done
nop
la t0, 0x300020
lw t1, 20(t0)
bnez t1, done
nop
move s4, zero
lw t1, 12(t0)
beqz t1, chosen
nop
addiu s4, zero, 2
lw t1, 40(t0)
bnez t1, chosen
nop
addiu s4, zero, 1
la t1, {hex(STAGE)}
lw t1, 0(t1)
beqz t1, chosen
nop
sltiu t2, t1, 10
beqz t2, chosen
nop
addiu s4, t1, 2
chosen:
sll s4, s4, 6
la t0, {hex(STRINGS)}
addu s4, s4, t0
move a0, s1
la a1, 0x687c88
la t0, 0x186538
lw t0, 0(t0)
beqz t0, color
nop
lw t0, 0x6d8(t0)
addiu t1, zero, 3
bne t0, t1, color
nop
la a1, 0x2d261c
color:
{oscall(0x185240)}
move s2, v0
move a0, s1
addiu a1, zero, 1
{oscall(0x185284)}
move s3, v0
addiu t0, zero, 31
sw t0, 0x20(sp)
addiu t0, zero, 325
sw t0, 0x24(sp)
addiu t0, zero, 301
sw t0, 0x28(sp)
addiu t0, zero, 373
sw t0, 0x2c(sp)
move a0, s1
move a1, s4
addiu a2, zero, -1
addiu a3, sp, 0x20
addiu t0, zero, 0x25
sw t0, 0x10(sp)
{oscall(0x18509c)}
move a0, s1
move a1, s3
{oscall(0x185284)}
move a0, s1
move a1, s2
{oscall(0x185240)}
done:
move v0, zero
{end(0x50,['s0','s1','s2','s3','s4'])}'''

def light_label_source(state,replay):
    return f'''addiu sp, sp, -0x10
sw t0, 0(sp)
sw t1, 4(sp)
sw t2, 8(sp)
lw t3, 0(t2)
la t0, 0x186538
lw t0, 0(t0)
beqz t0, done
nop
lw t1, 0x6d8(t0)
addiu t0, zero, 3
beq t1, t0, light
nop
# Preserve the existing dark M1 policy exactly.
bnez t3, done
nop
addiu t0, zero, 1
bne t1, t0, done
nop
addiu t0, zero, 1
beq {state}, t0, dark_active
nop
addiu t0, zero, 3
bne {state}, t0, done
nop
dark_active:
lw t1, 0x28(s1)
sltiu t0, t1, {len(CATALOG)}
beqz t0, done
nop
la t0, 0x33f800
addu t0, t0, t1
lbu t0, 0(t0)
beqz t0, done
nop
lui t3, 0xff
ori t3, t3, 0xffff
b done
nop
light:
lw t1, 0x28(s1)
addiu t0, zero, -1
beq t1, t0, bare_semantic
nop
sltiu t0, t1, {len(CATALOG)}
beqz t0, done
nop
la t0, 0x33fa00
addu t0, t0, t1
lbu t0, 0(t0)
beqz t0, done
nop
addiu t0, zero, 1
beq {state}, t0, white
nop
addiu t0, zero, 3
beq {state}, t0, white
nop
b bare_label
nop
bare_semantic:
# Preserve colored warning/status text on transparent native controls.
andi t0, t3, 0xff
srl t1, t3, 8
andi t1, t1, 0xff
bne t0, t1, done
nop
srl t1, t3, 16
andi t1, t1, 0xff
bne t0, t1, done
nop
bare_label:
addiu t0, zero, 2
beq {state}, t0, gray
nop
lui t3, 0x2d
ori t3, t3, 0x261c
b done
nop
gray:
lui t3, 0x72
ori t3, t3, 0x685f
b done
nop
white:
lui t3, 0xff
ori t3, t3, 0xffff
done:
lw t0, 0(sp)
lw t1, 4(sp)
lw t2, 8(sp)
{replay}
jr ra
addiu sp, sp, 0x10'''

def decoder_source():
    # Retain MAX13 decoder behavior, instrument each failure boundary without
    # borrowing source bytes after return or changing COM/GDI ownership.
    original=next(r for r in layout.originals('AppMain.exe') if r['address']==imaging.DECODE)
    row=layout.rewrite('AppMain.exe',original)
    source=row['recipe']['source_assembly']
    def mark(n):return f'la t0, {hex(STAGE)}\naddiu t9, zero, {n}\nsw t9, 0(t0)\n'
    source=source.replace('jal 0x220000',mark(1)+'jal 0x220000',1)
    source=source.replace('la a0, 0x14cab4',mark(2)+'la a0, 0x14cab4',1)
    source=source.replace('move a0, s2\nmove a1, s0',mark(3)+'move a0, s2\nmove a1, s0',1)
    source=source.replace('move a0, s3\naddiu a1, sp, 0x70',mark(4)+'move a0, s3\naddiu a1, sp, 0x70',1)
    source=source.replace(f'jal {hex(imaging.CREATE_DC)}',mark(5)+f'jal {hex(imaging.CREATE_DC)}',1)
    source=source.replace('move a0, s4\naddiu a1, sp, 0x40',mark(6)+'move a0, s4\naddiu a1, sp, 0x40',1)
    source=source.replace('move a0, s4\njal '+hex(imaging.SELECT),mark(7)+'move a0, s4\njal '+hex(imaging.SELECT),1)
    source=source.replace('move a0, s3\nmove a1, s4',mark(8)+'move a0, s3\nmove a1, s4',1)
    source=source.replace('result:\nmove v0, s5', 'result:\nbeqz s5, returned\nnop\n'+mark(9)+'returned:\nmove v0, s5',1)
    return row,source

def patch(raw,light_paths):
    assert sha(raw)==APP_SHA
    pe=pefile.PE(data=raw);out=bytearray(raw);edits=[];replaced=[];additions=[];newrel=[];routines=[]
    def write(va,data,reason):
        offset=pe.get_offset_from_rva(va-BASE)
        before=raw[offset:offset+len(data)];assert len(before)==len(data)
        edits.append(dict(offset=offset,before_hex=before.hex(),after_hex=data.hex(),reason=reason))
        out[offset:offset+len(data)]=data
    def routine(va,cap,source,reason,existing=False,prolog=None):
        encoded,recipe,rel=assemble(source,va,cap)
        # The assembler treats all LA operands as pointers; exclude COLORREFs.
        pc=va;excluded=set()
        for ln in recipe['source_assembly'].splitlines():
            ln=ln.split('#',1)[0].strip()
            if not ln or ln.endswith(':'):continue
            if ln.startswith('la '):
                value=int(ln.rsplit(',',1)[1].strip(),0)
                if value in (0x687c88,0x2d261c,0xcc0020):excluded.update((pc-BASE,pc-BASE+4))
                pc+=8
            else:pc+=4
        rel=[r for r in rel if r[0] not in excluded]
        write(va,encoded,reason);replaced.append((va-BASE,va-BASE+cap));newrel.extend(rel)
        row=dict(address=va,capacity=cap,recipe=recipe,relocations=rel,name=reason)
        routines.append(row)
        temp=dict(address=va,raw=encoded,recipe=recipe)
        pdata=(va,va+recipe['used_bytes'],0,0,prolog or layout.prolog_end(temp))
        additions.append((pdata,existing))
        return row
    assert pe.get_data(0x11cb8c-BASE,8)==struct.pack('<II',0x3c080307,0x8e440008)
    routine(CAPTURE,0x300,capture_source(),'Capture native Bluetooth playing/paused state',prolog=CAPTURE+4)
    # Exception prolog includes contiguous callee save only. RA is saved next.
    additions[-1]=((CAPTURE,CAPTURE+routines[-1]['recipe']['used_bytes'],0,0,CAPTURE+8),False)
    branch,_,rel=assemble(f'jal {hex(CAPTURE)}\nnop',0x11cb8c,8)
    write(0x11cb8c,branch,'Retained Blue manager dispatch plus scalar state publication')
    replaced.append((0x11cb8c-BASE,0x11cb94-BASE));newrel+=rel
    routine(ICON,0x200,icon_source(),'Select USB play or pause image for the native BT button')
    routine(RECOVER,0x200,recover_source(),'Bounded GUI retry of a worker that never started')
    routine(DIAGNOSTIC,0x500,diagnostic_source(),'Temporary cover-stage caption without popups or accepted bitmap')
    # Compact bank: every caption fits 32 UTF16 chars, no metadata overlap.
    text=bytearray(0x400)
    for i,s in enumerate(CAPTIONS):
        value=(s+'\0').encode('utf-16-le');assert len(value)<=64
        text[i*64:i*64+len(value)]=value
    write(STRINGS,bytes(text),'Read-only bounded diagnostic strings')
    native,decode=decoder_source()
    assert pe.get_data(imaging.DECODE-BASE,0x1000)==native['raw']
    routine(imaging.DECODE,0x1000,decode,'Retained decoder with stage stores',existing=True)
    row=layout.rewrite('AppMain.exe',next(r for r in layout.originals('AppMain.exe') if r['address']==lifetime.WND))
    assert pe.get_data(lifetime.WND-BASE,0x800)==row['raw']
    source=row['recipe']['source_assembly']
    source=source.replace('legacy:\nmove a0, s0',f'''legacy:
addiu t0, zero, 15
bne s1, t0, state_update
nop
jal {hex(RECOVER)}
nop
state_update:
ori t0, zero, 0x82f3
beq s1, t0, redraw_icon
nop
jal {hex(ICON)}
move a0, zero
b original
nop
redraw_icon:
jal {hex(ICON)}
addiu a0, zero, 1
move s4, zero
b done
nop
original:
move a0, s0''',1)
    routine(lifetime.WND,0x800,source,'GUI-only playback refresh and bounded late artwork startup',existing=True)
    refresh=layout.rewrite('AppMain.exe',next(r for r in layout.originals('AppMain.exe') if r['address']==0x236000))
    source=refresh['recipe']['source_assembly']
    for old,new in ((24,27),(116,98),(128,278)):
        source=source.replace(f'addiu t0, zero, {old}',f'addiu t0, zero, {new}')
    assert assemble(source,0x236000,0x800)[0]==pe.get_data(0x236000-BASE,0x800)
    source=source.replace('beqz s1, done\nnop',f'''bnez s1, status_changed
nop
la t0, {hex(STAGE)}
lw t1, 0(t0)
la t0, 0x300020
lw t2, 40(t0)
sll t2, t2, 8
or t1, t1, t2
lw t2, 12(t0)
sll t2, t2, 16
or t1, t1, t2
la t0, {hex(STATE)}
lw t2, 16(t0)
beq t1, t2, done
nop
sw t1, 16(t0)
addiu s1, zero, 1
status_changed:
''',1)
    routine(0x236000,0x800,source,'Refresh temporary cover status on stage changes only',existing=True)
    # Set state before children render. Keep fallback bitmap ownership intact.
    fsource=frame_source().replace('move s0, a0\naddiu a0, s0, 4',f'move s0, a0\njal {hex(ICON)}\nmove a0, zero\naddiu a0, s0, 4',1)
    fsource=fsource.replace('done:\nmove v0, s4',f'done:\njal {hex(DIAGNOSTIC)}\nmove a0, s0\nmove v0, s4',1)
    for a,b in ((0x223000,imaging.CREATE_DC),(0x223100,imaging.SELECT),(0x223200,imaging.DELETE_DC)):
        fsource=fsource.replace(hex(a),hex(b))
    routine(0x340000,0x1000,fsource,'Retained USB fallback with live playback selection and cover status',existing=True)
    from patch_selected_label_contrast import HOOKS
    for i,(_,state,replay) in enumerate(HOOKS):
        routine(0x33f000+i*0x200,0x200,light_label_source(state,replay),'Shared dark/light label contrast',existing=True,prolog=0x33f000+i*0x200+4)
    names={p.split('/Img/M1/',1)[1].replace('/','\\').lower() for p in light_paths}
    table=bytearray(0x200)
    for r in CATALOG:
        if r['filename'].lower() in names and ('_btn' in r['filename'] or r['filename'].endswith('_press.bmp') or 'changekey_' in r['filename']):table[r['id']]=1
    assert pe.get_data(0x33fa00-BASE,0x200)==bytes(0x200)
    write(0x33fa00,bytes(table),'Light redesigned resource membership, separate from retained dark table')
    assert pe.get_data(STATE-BASE,0x100)==bytes(0x100)
    pd=pe.OPTIONAL_HEADER.DATA_DIRECTORY[3];rd=pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    rows=list(struct.iter_unpack('<5I',pe.get_data(pd.VirtualAddress,pd.Size)))
    for row,exists in additions:
        if exists:
            index=next(i for i,r in enumerate(rows) if r[0]==row[0]);rows[index]=row
        else:assert not any(r[0]==row[0] for r in rows);rows.append(row)
    rows.sort();assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    records=[r for r in reloc_records(pe) if not pd.VirtualAddress<=r[0]<pd.VirtualAddress+pd.Size and not any(a<=r[0]<b for a,b in replaced)]
    records+=newrel
    for i,row in enumerate(rows):
        for j,value in enumerate(row):
            if value:records.append((pd.VirtualAddress+i*20+j*4,3,None))
    pdata=b''.join(struct.pack('<5I',*r) for r in rows)
    rva=pd.VirtualAddress+len(pdata)
    reloc=relocation_table(records)
    sec=pe.sections[-1];start=sec.PointerToRawData
    at=pe.get_offset_from_rva(pd.VirtualAddress)
    tail=pdata+reloc;newsize=(at-start+len(tail)+511)&~511
    assert len(raw)==start+sec.SizeOfRawData
    out[at:]=tail+bytes(start+newsize-at-len(tail))
    for directory,value,size in ((pd,pd.VirtualAddress,len(pdata)),(rd,rva,len(reloc))):
        struct.pack_into('<II',out,directory.get_file_offset(),value,size)
    vs=at-start+len(tail)
    struct.pack_into('<I',out,sec.get_field_absolute_offset('Misc_VirtualSize'),vs)
    struct.pack_into('<I',out,sec.get_field_absolute_offset('SizeOfRawData'),newsize)
    struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfImage'),(sec.VirtualAddress+vs+4095)&~4095)
    struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfCode'),pe.OPTIONAL_HEADER.SizeOfCode+newsize-sec.SizeOfRawData)
    checksum=pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I',out,checksum,0)
    struct.pack_into('<I',out,checksum,pefile.PE(data=bytes(out)).generate_checksum())
    result=bytes(out)
    return result,dict(input_sha256=sha(raw),sha256=sha(result),routines=routines,edits=edits,
        helpers=[0x33f000+i*0x200 for i in range(3)],lookup_va=0x33f800,light_lookup_va=0x33fa00,
        playback_state_va=STATE,decoder_stage_va=STAGE,captions=CAPTIONS,
        native_executed=False,hardware_tested=False,artwork_root_cause_confirmed=False)

def light_image(dark,name):
    # Preserve authored topology and state banks. Invert only neutral material;
    # active black faces and function colors remain intentional dark accents.
    button='_btn' in name or name.endswith('_press.bmp') or 'changekey_' in name
    banks=2 if name in ('phone_dial_btn_call.bmp','phone_keyboard_search_results_list_down_btn.bmp') else 1
    fw=dark.width//(4*banks) if button else dark.width
    pixels=[]
    for i,rgb in enumerate(dark.getdata()):
        if rgb==KEY:pixels.append(KEY);continue
        x=i%dark.width;state=(x//fw)%4 if button else 0
        hi,lo=max(rgb),min(rgb)
        if button and state in (1,3):
            # Keyless surrounding canvas becomes light; black face stays black.
            if all(abs(rgb[k]-(12,17,20)[k])<3 for k in range(3)):pixels.append(LIGHT_BG)
            else:pixels.append(rgb)
        elif hi-lo>50 and hi>65:
            pixels.append(tuple(round(c*.74) for c in rgb))
        elif hi>=165:
            amount=min(1,(hi-165)/80)
            pixels.append(tuple(round(170*(1-amount)+INK[k]*amount) for k in range(3)))
        else:
            # Quiet frame, rim, separators and neutral music-note silhouette.
            amount=min(1,max(0,(hi-20)/95))
            pixels.append(tuple(round(LIGHT_BG[k]-(LIGHT_BG[k]-142)*amount) for k in range(3)))
    output=Image.new('RGB',dark.size);output.putdata(pixels);return output

def encode_light(before,painted):
    from parse_bmp_image import parse_bmp,reference_rgb
    meta=parse_bmp(before)
    if meta['bpp']==8:
        after=encode_like(before,painted);return after,verify(before,after)
    # One native light radio arrow is true-color. Preserve its 24-bit contract
    # rather than replacing it with an indexed resource.
    assert meta['bpp']==24 and meta['compression']==0
    original=Image.frombytes('RGB',painted.size,reference_rgb(before,meta))
    out=bytearray(before)
    for y in range(meta['height']):
        row=y if meta['top_down'] else meta['height']-1-y
        at=meta['pixel_offset']+row*meta['pixel_stride']
        for x in range(meta['width']):
            rgb=KEY if original.getpixel((x,y))==KEY else painted.getpixel((x,y))
            if rgb==KEY and original.getpixel((x,y))!=KEY:rgb=(255,255,1)
            out[at+3*x:at+3*x+3]=bytes(rgb[::-1])
    after=bytes(out);assert parse_bmp(after)==meta and before[:54]==after[:54]
    from io import BytesIO
    decoded=Image.open(BytesIO(after)).convert('RGB')
    assert decoded.tobytes()==reference_rgb(after,meta)
    assert [c==KEY for c in original.getdata()]==[c==KEY for c in decoded.getdata()]
    return after,dict(header_and_file_size_preserved=True,transparency_mask_preserved=True,
                      independent_decoder_matches=True,bpp=24,width=meta['width'],height=meta['height'])

def build():
    assert not OUT.exists()
    previous={r['path']:r['after'] for r in json.loads((BASELINE/'member-plan.json').read_bytes())['members']}
    assert len(previous)==1918
    for name,row in previous.items():assert sha((BASELINE/'payload'/name).read_bytes())==row['sha256']
    paths=json.loads((ROOT/'analysis/firmware/max14-light-resource-plan.json').read_bytes())
    raw=(BASELINE/'payload'/APP).read_bytes();candidate,recipe=patch(raw,paths)
    shutil.copytree(BASELINE/'payload',OUT/'payload');(OUT/'payload'/APP).write_bytes(candidate)
    assets=[]
    for name in paths:
        light=name.replace('/Img/M1/','/Img/M1_INV/')
        before=(BASELINE/'payload'/light).read_bytes()
        painted=light_image(Image.open(BASELINE/'payload'/name).convert('RGB'),Path(name).name)
        after,contract=encode_light(before,painted)
        (OUT/'payload'/light).write_bytes(after)
        assets.append(dict(path=light,before_sha256=sha(before),sha256=sha(after),contract=contract))
    members=[];changed=[]
    for name,row in sorted(previous.items()):
        content=(OUT/'payload'/name).read_bytes();members.append(dict(path=name,bytes=len(content),sha256=sha(content)))
        if sha(content)!=row['sha256']:changed.append(name)
    assert set(changed)=={APP.as_posix()}|{r['path'] for r in assets}
    (OUT/'recipe.json').write_text(json.dumps(recipe,indent=2)+'\n')
    (OUT/'light-assets.json').write_text(json.dumps(assets,indent=2)+'\n')
    (OUT/'manifest.json').write_text(json.dumps(dict(baseline='7.0.6.MAX13',members=members,changed_members=changed,retained_members=1918-len(changed),native_executed=False,hardware_tested=False),indent=2)+'\n')
    return dict(output=str(OUT),app_sha256=sha(candidate),light_images=len(assets),members=len(members))

if __name__=='__main__':print(json.dumps(build(),indent=2))
