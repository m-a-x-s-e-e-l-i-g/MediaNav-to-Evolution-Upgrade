"""Resolve late black foregrounds on MAX04's dark M1 button sprites.

Three leaf hooks cover the shared primary, alternate and list-number painters.
No native execution. Original payload, imports, state arrays and layout persist.
"""
import hashlib
import json
import struct
from pathlib import Path
import pefile
from patch_usb_reliability import assemble
from patch_shared_mapping_checks import reloc_records

ROOT = Path(__file__).resolve().parents[1]
RELEASE = ROOT/'build/maxmade-7.0.6.MAX04'
APP = 'upgrade/Storage Card/System/AppMain.exe'
INPUT_SHA = 'b34676225ad428426b417cec33c30f7e18e56aeeb6e438900c01dc022225fcd9'
BASE = 0x10000
HOOKS = [(0x13ed30, 't5', 'lw t6, 0x56c(s1)'),
         (0x13ed54, 't5', 'sw t3, 0x320(s1)'),
         (0x13f29c, 't4', 'addiu t5, zero, 1')]

def sha(raw): return hashlib.sha256(raw).hexdigest()

def resources():
    catalog=json.loads((ROOT/'analysis/firmware/appmain-startup-contracts.json').read_text())['resources']
    skin=json.loads((ROOT/'build/av-theme-development-09/manifest.json').read_text())
    names={r['path'].split('/Img/M1/',1)[1].replace('/', '\\').lower()
           for r in skin['changed_images'] if '_btn' in Path(r['path']).name.lower()
           or r['path'].lower().endswith('_press.bmp')}
    # Home resources are included in the approved complete release separately.
    manifest=json.loads((RELEASE/'staging-manifest.json').read_text())
    before=manifest['previous_member_hashes']
    after=manifest['members']
    for name,row in after.items():
        if '/Img/M1/' in name and ('_btn' in Path(name).name.lower() or name.lower().endswith('_press.bmp')) and row['sha256']!=before[name]:
            names.add(name.split('/Img/M1/',1)[1].replace('/', '\\').lower())
    ids={r['id']:r['filename'] for r in catalog if r['filename'].lower() in names}
    # Five shipped sprites have no AppMain catalog entry (baked icons only).
    uncatalogued=names-set(n.lower() for n in ids.values())
    assert uncatalogued=={'media\\media_like_empty_btn.bmp','media\\media_dislike_empty_btn.bmp',
        'phone\\phone_softkey_carspeaker_btn.bmp','media\\media_control_2_play_btn.bmp',
        'media\\media_control_2_pause_btn.bmp'}
    return catalog,ids

def patch(raw):
    assert sha(raw)==INPUT_SHA
    p=pefile.PE(data=raw);assert p.OPTIONAL_HEADER.ImageBase==BASE
    out=bytearray(raw);edits=[]
    catalog,ids=resources()
    va=BASE+p.OPTIONAL_HEADER.SizeOfImage
    body=bytearray(0x1000)
    # One byte per catalog ID: constant-time membership; signed/large IDs fail closed.
    map_va=va+0x800
    for ident in ids: body[0x800+ident]=1
    assert len(catalog)<0x800
    relocs=reloc_records(p);original_relocs=relocs[:];routines=[];new_rows=[]
    def edit(off,data,reason):
        edits.append(dict(offset=off,before_hex=bytes(out[off:off+len(data)]).hex(),after_hex=data.hex(),reason=reason))
        out[off:off+len(data)]=data
    for n,(hook,state,replay) in enumerate(HOOKS):
        target=va+n*0x200
        code=f'''addiu sp, sp, -0x10
sw t0, 0(sp)
sw t1, 4(sp)
sw t2, 8(sp)
lw t3, 0(t2)
bnez t3, done
nop
addiu t0, zero, 1
beq {state}, t0, active
nop
addiu t0, zero, 3
bne {state}, t0, done
nop
active:
la t0, 0x186538
lw t0, 0(t0)
beqz t0, done
nop
lw t1, 0x6d8(t0)
addiu t0, zero, 1
bne t1, t0, done
nop
lw t1, 0x28(s1)
sltiu t0, t1, {len(catalog)}
beqz t0, done
nop
la t0, {hex(map_va)}
addu t0, t0, t1
lbu t0, 0(t0)
beqz t0, done
nop
lui t3, 0xff
ori t3, t3, 0xffff
done:
lw t0, 0(sp)
lw t1, 4(sp)
lw t2, 8(sp)
{replay}
jr ra
addiu sp, sp, 0x10'''
        encoded,recipe,r=assemble(code,target,0x200)
        body[n*0x200:(n+1)*0x200]=encoded
        relocs+=r;routines.append(recipe)
        new_rows.append((target,target+recipe['used_bytes'],0,0,target+16))
        off=p.get_offset_from_rva(hook-BASE)
        original=p.get_data(hook-BASE,8)
        assert int.from_bytes(original[:4],'little')==0x8d4b0000
        assert not any(hook-BASE<=a<hook-BASE+8 for a,_,_ in original_relocs)
        hook_bytes,_,r=assemble(f'jal {hex(target)}\nnop',hook,8)
        edit(off,hook_bytes,'Shared foreground resolution after runtime color refresh')
        relocs+=r
    # Extend existing sorted pdata into its verified zero padding. No moved rows.
    pd=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows=[struct.unpack_from('<5I',p.get_data(pd.VirtualAddress,pd.Size),i) for i in range(0,pd.Size,20)]
    assert rows==sorted(rows) and rows[-1][1]<=new_rows[0][0]
    at=p.get_offset_from_rva(pd.VirtualAddress+pd.Size)
    extension=b''.join(struct.pack('<5I',*r) for r in new_rows)
    assert not any(raw[at:at+len(extension)])
    assert pd.VirtualAddress+pd.Size+len(extension)<=p.OPTIONAL_HEADER.DATA_DIRECTORY[5].VirtualAddress
    edit(at,extension,'Append three leaf unwind records')
    edit(pd.get_file_offset()+4,struct.pack('<I',pd.Size+len(extension)),'Exception directory size')
    for n,row in enumerate(new_rows):
        for j,v in enumerate(row):
            if v:relocs.append((pd.VirtualAddress+pd.Size+n*20+j*4,3,None))
    # Re-encode the unchanged original relocation records plus helper/hook rows.
    pages={}
    assert len({a for a,_,_ in relocs})==len(relocs)
    for a,k,c in sorted(relocs):
        pages.setdefault(a&~4095,[]).append((k<<12)|(a&4095))
        if k==4:pages[a&~4095].append(c)
    encoded=bytearray()
    for page,values in sorted(pages.items()):
        if len(values)%2:values.append(0)
        encoded+=struct.pack('<II',page,8+len(values)*2)+struct.pack('<'+'H'*len(values),*values)
    rd=p.OPTIONAL_HEADER.DATA_DIRECTORY[5];off=p.get_offset_from_rva(rd.VirtualAddress)
    section=p.get_section_by_rva(rd.VirtualAddress)
    assert off+len(encoded)<=section.PointerToRawData+section.SizeOfRawData
    assert not any(raw[off+rd.Size:off+len(encoded)])
    edit(off,bytes(encoded),'Original relocations plus leaf hooks and unwind records')
    edit(rd.get_file_offset()+4,struct.pack('<I',len(encoded)),'Relocation directory size')
    header=p.sections[-1].get_file_offset()+40
    assert header+40<=p.OPTIONAL_HEADER.SizeOfHeaders and not any(raw[header:header+40])
    ptr=(len(out)+0x1ff)&~0x1ff
    edit(header,struct.pack('<8s8I',b'.mxlabel',0x1000,va-BASE,0x1000,ptr,0,0,0,0x60000020),'Read-only executable label helper section')
    edit(p.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),struct.pack('<H',len(p.sections)+1),'Section count')
    for name,value in [('SizeOfImage',va-BASE+0x1000),('SizeOfCode',p.OPTIONAL_HEADER.SizeOfCode+0x1000)]:
        edit(p.OPTIONAL_HEADER.get_field_absolute_offset(name),struct.pack('<I',value),name)
    out+=bytes(ptr-len(out))+body
    result=bytes(out);q=pefile.PE(data=result)
    assert set(original_relocs)<=set(reloc_records(q))
    # Rollback of every explained edit restores the full cumulative executable.
    rollback=bytearray(result[:len(raw)])
    for e in reversed(edits): rollback[e['offset']:e['offset']+len(bytes.fromhex(e['before_hex']))]=bytes.fromhex(e['before_hex'])
    assert bytes(rollback)==raw
    return result,dict(input_sha256=sha(raw),sha256=sha(result),edits=edits,routines=routines,
        helpers=[r[0] for r in new_rows],helper_rows=new_rows,resource_count=len(catalog),
        protected_resources=ids,lookup_va=map_va,added_relocations=len(relocs)-len(original_relocs),
        original_relocations_preserved=True,rollback_matches_complete_MAX04=True,
        native_executed=False,hardware_tested=False)
