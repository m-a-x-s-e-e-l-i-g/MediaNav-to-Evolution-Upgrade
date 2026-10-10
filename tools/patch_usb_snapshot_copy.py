"""Optimize the existing locked snapshot helper in place; never execute firmware."""
import copy
import hashlib
import re
import struct
import pefile
from patch_usb_reliability import assemble
from patch_updater_copy_safety import frame,end
from patch_bt_playback import REGS
from patch_shared_mapping_checks import reloc_records

INPUT_SHA='a3be9c0512fc883c22868da0aa62fba48c0c095e9cef2a2c66279043bbf228b7'
BASE=0x10000
CAPACITY=0x100

def patch(raw,previous):
    assert hashlib.sha256(raw).hexdigest()==INPUT_SHA
    p=pefile.PE(data=raw);out=bytearray(raw)
    start=previous['code_va']+0x200
    code=f'''
{frame(0x30,['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
beqz s1, fail
move s2, a2
jal {hex(previous['code_va'])}
move a0, zero
beqz v0, fail
move s3, v0
# Retain the previous forward-byte behavior for a destructive overlap.
sltu t0, s1, s0
beqz t0, select_words
subu t1, s0, s1
sltu t0, t1, s2
bnez t0, bytes
nop
select_words:
or t0, s0, s1
andi t0, t0, 3
bnez t0, unaligned_words
sltiu t0, s2, 4
aligned_words:
bnez t0, bytes
nop
lw t0, 0(s1)
sw t0, 0(s0)
addiu s1, s1, 4
addiu s2, s2, -4
sltiu t0, s2, 4
b aligned_words
addiu s0, s0, 4
unaligned_words:
bnez t0, bytes
nop
lwr t0, 0(s1)
lwl t0, 3(s1)
swr t0, 0(s0)
swl t0, 3(s0)
addiu s1, s1, 4
addiu s2, s2, -4
sltiu t0, s2, 4
b unaligned_words
addiu s0, s0, 4
bytes:
beqz s2, done
nop
lbu t0, 0(s1)
sb t0, 0(s0)
addiu s1, s1, 1
addiu s2, s2, -1
b bytes
addiu s0, s0, 1
done:
jal {hex(previous['code_va']+0x100)}
move a0, s3
b return
addiu v0, zero, 1
fail:
move v0, zero
return:
{end(0x30,['s0','s1','s2','s3'])}
'''
    lines=[];custom=[];pc=start
    for line in code.splitlines():
        line=line.split('#',1)[0].strip()
        if not line:continue
        if line.endswith(':'):lines.append(line);continue
        op=line.split()[0]
        if op in ('lwl','lwr','swl','swr'):custom.append((pc,line));lines.append('nop')
        else:lines.append(line)
        pc+=4
    encoded,r,new_reloc=assemble('\n'.join(lines),start,CAPACITY);encoded=bytearray(encoded)
    for at,line in custom:
        op,rt,imm,rs=[v for v in re.split(r'[\s,()]+',line) if v]
        word=({'lwl':0x22,'lwr':0x26,'swl':0x2a,'swr':0x2e}[op]<<26)|(REGS[rs]<<21)|(REGS[rt]<<16)|(int(imm,0)&65535)
        struct.pack_into('<I',encoded,at-start,word)
    r['assembly']=code
    edits=[]
    def edit(off,b,reason):
        edits.append(dict(offset=off,bytes=len(b),before_hex=bytes(out[off:off+len(b)]).hex(),after_hex=b.hex(),reason=reason))
        out[off:off+len(b)]=b
    edit(p.get_offset_from_rva(start-BASE),bytes(encoded),'Four-byte copy with byte tail and forward-overlap fallback')
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    pdata=p.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',pdata,i) for i in range(0,len(pdata),20)]
    idx=next(i for i,row in enumerate(rows) if row[0]==start)
    assert rows[idx][2:]==(0,0,start+24)
    edit(p.get_offset_from_rva(d.VirtualAddress)+idx*20+4,struct.pack('<I',start+r['used_bytes']),'Updated helper function end; same frame/prolog')
    old_reloc=reloc_records(p)
    records=sorted([row for row in old_reloc if not start-BASE<=row[0]<start-BASE+CAPACITY]+new_reloc)
    assert len({row[0] for row in records})==len(records)
    pages={}
    for at,kind,companion in records:
        page=at&~4095;pages.setdefault(page,[]).append(kind<<12|at-page)
        if kind==4:pages[page].append(companion)
    table=bytearray()
    for page,values in sorted(pages.items()):
        if len(values)%2:values.append(0)
        table+=struct.pack('<II',page,len(values)*2+8)+struct.pack('<'+'H'*len(values),*values)
    rd=p.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    assert len(table)==rd.Size,'Do not move or resize existing relocation metadata'
    edit(p.get_offset_from_rva(rd.VirtualAddress),bytes(table),'Relocate both moved lock/unlock calls; retain every other record')
    updated=copy.deepcopy(previous)
    for row in updated['helper_rows']:
        if row[0]==start:row[1]=start+r['used_bytes']
    ridx=next(i for i,row in enumerate(updated['routines']) if int(row['start'],16)==start)
    updated['routines'][ridx]=r
    updated['sha256']=hashlib.sha256(out).hexdigest()
    recipe=dict(input_sha256=INPUT_SHA,output_sha256=updated['sha256'],start=start,capacity=CAPACITY,
        used_bytes=r['used_bytes'],assembly=code,edits=edits,relocations_added=new_reloc,
        original_helper_row=rows[idx],consumer_recipe=updated,native_executed=False)
    return bytes(out),recipe
