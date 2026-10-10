"""Use one bounded, locked repeat/shuffle snapshot for the USB options refresh."""
import copy
import hashlib
import struct
import pefile
from patch_usb_reliability import assemble
from patch_updater_copy_safety import frame,end
from patch_shared_mapping_checks import reloc_records

INPUT_SHA='996e318850e1f0da0d1969fae96f9b1f8b808d9e47c32f649cd9d329f646cd46'
BASE=0x10000
HOOK,HOOK_END=0x4f838,0x4f938

def patch(raw,previous):
    assert hashlib.sha256(raw).hexdigest()==INPUT_SHA
    p=pefile.PE(data=raw);out=bytearray(raw);start=previous['code_va']+0x2200;cap=0x400
    edits=[]
    def edit(off,b,reason):
        edits.append(dict(offset=off,bytes=len(b),before_hex=bytes(out[off:off+len(b)]).hex(),after_hex=b.hex(),reason=reason))
        out[off:off+len(b)]=b
    code=f'''
{frame(0x40,['s0','s1'])}
move s0, a0
la t0, 0x186ce8
lw s1, 0(t0)
beqz s1, fail
nop
lw a1, 0xc4(s1)
beqz a1, fail
nop
addiu a1, a1, 0xe42
addiu a0, sp, 0x20
jal {hex(previous['code_va']+0x200)}
addiu a2, zero, 8
beqz v0, fail
nop
lw t0, 0x20(sp)
lw t1, 0x24(sp)
'''
    fields=((0xf14,0),(0x1484,1),(0x1f64,3),(0x19f4,2),(0x24d4,'off'),(0x2a44,'on'))
    for idx,(offset,value) in enumerate(fields):
        if value=='off':code+='sltiu t2, t1, 1\n'
        elif value=='on':code+='sltu t2, zero, t1\n'
        else:code+=f'addiu t2, t0, {-value}\nsltiu t2, t2, 1\n'
        code+=f'''lw t3, {hex(offset)}(s0)
beq t3, t2, same_{idx}
nop
sw t2, {hex(offset)}(s0)
same_{idx}:
'''
    code+=f'''
lw t0, 0x7c(s1)
addiu t1, zero, 2
bne t0, t1, done
nop
addiu t0, zero, 3
sw t0, 0x7c(s1)
done:
addiu v0, zero, 1
b return
nop
fail:
move v0, zero
return:
{end(0x40,['s0','s1'])}
'''
    encoded,r,added=assemble(code,start,cap)
    code_off=p.get_offset_from_rva(start-BASE)
    assert not any(raw[code_off:code_off+cap]),'Helper must occupy unused zero padding'
    edit(code_off,encoded,'Private eight-byte snapshot, unlocked conditional flag updates and completion state')
    hook,h,hook_reloc=assemble(f'jal {hex(start)}\nmove a0, s1\nb {hex(HOOK_END)}\nnop',HOOK,HOOK_END-HOOK)
    edit(p.get_offset_from_rva(HOOK-BASE),hook,'Replace repeated shared reads; retain original entry, earlier UI calls and epilogue')
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    old_rows=list(struct.iter_unpack('<5I',p.get_data(d.VirtualAddress,d.Size)))
    row=(start,start+r['used_bytes'],0,0,start+16)
    assert old_rows[-1][1]<=start
    new_rows=old_rows+[row]
    pdata=b''.join(struct.pack('<5I',*v) for v in new_rows)
    pdata_off=p.get_offset_from_rva(d.VirtualAddress)
    assert not any(raw[pdata_off+d.Size:pdata_off+len(pdata)])
    edit(pdata_off,pdata,'Keep every exception row and append the helper row')
    edit(d.get_file_offset()+4,struct.pack('<I',len(pdata)),'Extended exception table size; same location')
    added+=hook_reloc
    for j,v in enumerate(row):
        if v:added.append((d.VirtualAddress+d.Size+j*4,3,None))
    original=reloc_records(p)
    records=sorted([v for v in original if not HOOK-BASE<=v[0]<HOOK_END-BASE]+added)
    assert len({v[0] for v in records})==len(records)
    pages={}
    for at,kind,companion in records:
        page=at&~4095;pages.setdefault(page,[]).append(kind<<12|at-page)
        if kind==4:pages[page].append(companion)
    table=bytearray()
    for page,values in sorted(pages.items()):
        if len(values)%2:values.append(0)
        table+=struct.pack('<II',page,len(values)*2+8)+struct.pack('<'+'H'*len(values),*values)
    rd=p.OPTIONAL_HEADER.DATA_DIRECTORY[5];reloc_off=p.get_offset_from_rva(rd.VirtualAddress)
    section=next(s for s in p.sections if s.VirtualAddress<=rd.VirtualAddress<s.VirtualAddress+s.Misc_VirtualSize)
    assert reloc_off+len(table)<=section.PointerToRawData+section.SizeOfRawData
    assert not any(raw[reloc_off+rd.Size:reloc_off+len(table)])
    edit(reloc_off,bytes(table),'Keep other relocations and add hook/helper/exception references')
    edit(rd.get_file_offset()+4,struct.pack('<I',len(table)),'Extended relocation table size; same location')
    ar=copy.deepcopy(previous);ar['helper_rows'].append(row);ar['routines'].append(r)
    ar['sha256']=hashlib.sha256(out).hexdigest()
    recipe=dict(input_sha256=INPUT_SHA,output_sha256=ar['sha256'],start=start,capacity=cap,used_bytes=r['used_bytes'],
        original_entry=0x4f754,hook=HOOK,hook_end=HOOK_END,frame_bytes=0x40,prolog_bytes=16,
        snapshot_bytes=8,snapshot_offset=0xe42,helper_row=row,relocations_added=added,
        assembly=code,edits=edits,consumer_recipe=ar,native_executed=False)
    return bytes(out),recipe
