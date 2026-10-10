"""Stop static initialization before publishing an incomplete shared-memory object.

MIPS byte construction only. Existing termination API, no device/file writes.
"""
import hashlib
import struct
import pefile
from patch_usb_reliability import assemble
from patch_updater_copy_safety import frame, end
from patch_shared_mapping_checks import reloc_records

BASE = 0x10000
BASE_SHA = '1ff9fd6c5d4029745182da69af453eef43d27b94565ca3fa567021055a49c589'
TEXT, SIZE = 0x1c3000, 0x1000
CHECK, FAIL, MESSAGE, TITLE = TEXT, TEXT+0x100, TEXT+0x500, TEXT+0x600

CHECK_CODE = f'''
{frame(0x20,['s0'])}
move s0, a0
jal 0x13234
nop
bnez v0, done
nop
jal {hex(FAIL)}
move a0, s0
done:
{end(0x20,['s0'])}
'''

FAIL_CODE = f'''
{frame(0x40,['s0','s1','s2','s3'])}
move s0, a0
la t0, 0x186ce8
sw zero, 0(t0)
la t0, 0x186308
sw zero, 0(t0)
bnez s0, clean
nop
move a0, zero
la a1, {hex(MESSAGE)}
la a2, {hex(TITLE)}
jal 0x13ff38
move a3, zero
b terminate
nop
clean:
addiu s1, s0, 0xa0
addiu s2, zero, 14
next_pair:
lw s3, 4(s1)
beqz s3, close_handle
nop
jal 0x13ff28
move a0, s3
beqz v0, close_handle
nop
sw zero, 4(s1)
close_handle:
lw s3, 0(s1)
beqz s3, next
nop
la t8, 0x185028
lw t9, 0(t8)
jalr t9
move a0, s3
beqz v0, next
nop
sw zero, 0(s1)
next:
addiu s2, s2, -1
bnez s2, next_pair
addiu s1, s1, 8
jal 0x1402e0
move a0, s0
terminate:
addiu a0, zero, 0x42
jal 0x140108
addiu a1, zero, 1
la t8, 0x18503c
lw t9, 0(t8)
jalr t9
addiu a0, zero, 1000
b terminate
nop
'''


def patch(raw):
    assert hashlib.sha256(raw).hexdigest() == BASE_SHA
    p=pefile.PE(data=raw)
    assert p.OPTIONAL_HEADER.ImageBase == BASE and p.FILE_HEADER.Machine == 0x166
    assert p.OPTIONAL_HEADER.SizeOfImage == TEXT-BASE
    out=bytearray(raw); body=bytearray(SIZE); edits=[]; rel=[]; rows=[]; routines=[]
    for at,cap,code,prolog in ((CHECK,0x100,CHECK_CODE,12),(FAIL,0x400,FAIL_CODE,24)):
        new,recipe,added=assemble(code,at,cap)
        body[at-TEXT:at-TEXT+cap]=new; rel.extend(added); routines.append(recipe)
        rows.append((at,at+recipe['used_bytes'],0,0,at+prolog))
    for at,value in ((MESSAGE,'MediaNav could not start: not enough memory. Restart the unit.'),
                     (TITLE,'MediaNav startup')):
        encoded=(value+'\0').encode('utf-16-le');assert len(encoded)<=0x100
        body[at-TEXT:at-TEXT+len(encoded)]=encoded
    def edit(offset,new,reason,va=None):
        before=bytes(out[offset:offset+len(new)])
        edits.append(dict(va=hex(va) if va is not None else None,offset=hex(offset),bytes=len(new),
                          before_hex=before.hex(),after_hex=new.hex(),reason=reason))
        out[offset:offset+len(new)]=new
    assert int.from_bytes(p.get_data(0x14111c-BASE,4),'little') == (3<<26)|(0x13234>>2)
    new,_,r=assemble(f'jal {hex(CHECK)}',0x14111c,4)
    edit(p.get_offset_from_rva(0x14111c-BASE),new,'Check mapping initializer result before registry reads/publication',0x14111c);rel+=r
    assert p.get_data(0x1411b0-BASE,20).hex() == '258800001800083c086371ae03000010e86c11ad'
    new,_,r=assemble(f'move a0, zero\njal {hex(FAIL)}\nnop\nb 0x1411b4\nnop',0x1411b0,20)
    edit(p.get_offset_from_rva(0x1411b0-BASE),new,'Allocation failure uses startup stop; never publishes NULL',0x1411b0);rel+=r
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];old=p.get_data(d.VirtualAddress,d.Size)
    previous=[struct.unpack_from('<5I',old,i) for i in range(0,len(old),20)]
    combined=sorted(previous+rows)
    assert all(a[1]<=b[0] for a,b in zip(combined,combined[1:]))
    new=b''.join(struct.pack('<5I',*row) for row in combined)
    section=next(s for s in p.sections if s.VirtualAddress<=d.VirtualAddress<s.VirtualAddress+s.SizeOfRawData)
    assert len(new)<=section.SizeOfRawData-(d.VirtualAddress-section.VirtualAddress)
    edit(p.get_offset_from_rva(d.VirtualAddress),new,'Retain all exception rows and add helper prologs',BASE+d.VirtualAddress)
    edit(d.get_file_offset()+4,struct.pack('<I',len(new)),'Exception directory size')
    for i,row in enumerate(combined):
        if row not in previous:
            for j,value in enumerate(row):
                if value:rel.append((d.VirtualAddress+i*20+j*4,3,None))
    # No existing exception row moves: helpers sort after all original code.
    assert combined[:len(previous)]==previous
    removed_spans=[(0x14111c-BASE,0x141120-BASE),(0x1411b0-BASE,0x1411c4-BASE)]
    records=[r for r in reloc_records(p) if not any(a<=r[0]<b for a,b in removed_spans)] + rel
    records.sort();assert len({at for at,_,_ in records})==len(records)
    pages={}
    for at,kind,companion in records:
        page=at&~4095;pages.setdefault(page,[]).append((kind<<12)|(at-page))
        if kind==4:pages[page].append(companion)
    new=bytearray()
    for page,values in sorted(pages.items()):
        if len(values)%2:values.append(0)
        new.extend(struct.pack('<II',page,8+len(values)*2)+struct.pack('<'+'H'*len(values),*values))
    rd=p.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    section=next(s for s in p.sections if s.VirtualAddress<=rd.VirtualAddress<s.VirtualAddress+s.SizeOfRawData)
    assert len(new)<=section.SizeOfRawData-(rd.VirtualAddress-section.VirtualAddress)
    cap=max(len(new),rd.Size)
    edit(p.get_offset_from_rva(rd.VirtualAddress),bytes(new)+bytes(cap-len(new)),'Retain relocations outside two hooks and add helper references',BASE+rd.VirtualAddress)
    edit(rd.get_file_offset()+4,struct.pack('<I',len(new)),'Relocation directory size')
    header=p.sections[-1].get_file_offset()+40
    assert header+40<=p.OPTIONAL_HEADER.SizeOfHeaders and not any(raw[header:header+40])
    alignment=p.OPTIONAL_HEADER.FileAlignment;offset=(len(out)+alignment-1)//alignment*alignment
    edit(header,struct.pack('<8s8I',b'.mxboot',SIZE,TEXT-BASE,SIZE,offset,0,0,0,0x60000020),'Read/execute startup helper section')
    edit(p.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),struct.pack('<H',6),'Section count')
    for key,value in (('SizeOfImage',TEXT+SIZE-BASE),('SizeOfCode',p.OPTIONAL_HEADER.SizeOfCode+SIZE)):
        edit(p.OPTIONAL_HEADER.get_field_absolute_offset(key),struct.pack('<I',value),key)
    out.extend(bytes(offset-len(out)));out.extend(body)
    result=bytes(out)
    return result,dict(base_sha256=BASE_SHA,sha256=hashlib.sha256(result).hexdigest(),
        original_bytes=len(raw),new_section_file_offset=offset,edits=edits,routines=routines,
        added_pdata_rows=rows,relocation_records=len(records),new_imports=False,
        failure_terminates_only_current_process=True,current_process_handle=0x42,
        termination_return_fallback='Sleep(1000), then retry termination; never continue initialization',
        native_executed=False,installation_ready=False)
