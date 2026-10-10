"""Validate saved modes at publication; leave saved bytes/checksum untouched."""
import hashlib
import re
import struct
import pefile
from patch_usb_reliability import assemble,BASE,DATA,DATA_SIZE
from patch_bt_playback import REGS

BASE_SHA='f57cbfa38453cfac5c25a0d8db4376da5fa46a9ed838caa05985f5840512a6ba'
RESTORE=0x3fd80

def mode_assemble(code,start,capacity):
    lines=[];custom=[];pc=start
    for line in code.splitlines():
        line=line.split('#',1)[0].strip()
        if not line:continue
        if line.endswith(':'):lines.append(line);continue
        if line.split()[0] in ('lwl','lwr','swl','swr'):custom.append((pc,line));lines.append('nop')
        else:lines.append(line)
        pc+=8 if line.startswith('la ') else 4
    raw,recipe,rel=assemble('\n'.join(lines),start,capacity);out=bytearray(raw)
    for at,line in custom:
        op,rt,imm,rs=[p for p in re.split(r'[\s,()]+',line) if p]
        imm=int(imm,0);assert -32768<=imm<=32767
        word=({'lwl':0x22,'lwr':0x26,'swl':0x2a,'swr':0x2e}[op]<<26)|(REGS[rs]<<21)|(REGS[rt]<<16)|(imm&65535)
        struct.pack_into('<I',out,at-start,word)
    recipe['source_assembly']=code
    return bytes(out),recipe,rel

CODE='''
addiu t0, a0, 0x1ab0
lwl t1, 3(t0)
lwr t1, 0(t0)
sltiu t2, t1, 4
bnez t2, repeat_valid
nop
move t1, zero
repeat_valid:
swl t1, 0x291d(a0)
swr t1, 0x291a(a0)
sw t1, 0x2934(a0)
addiu t0, a0, 0x1ab4
lwl t1, 3(t0)
lwr t1, 0(t0)
sltiu t2, t1, 2
bnez t2, shuffle_valid
nop
move t1, zero
shuffle_valid:
swl t1, 0x2921(a0)
swr t1, 0x291e(a0)
sw t1, 0x2938(a0)
jr ra
nop
'''

def patch(raw):
    assert hashlib.sha256(raw).hexdigest()==BASE_SHA
    p=pefile.PE(data=raw);out=bytearray(raw);edits=[];newrel=[]
    def block(at,cap,code,why):
        new,r,rel=mode_assemble(code,at,cap);off=p.get_offset_from_rva(at-BASE)
        edits.append(dict(va=hex(at),offset=hex(off),bytes=cap,before_hex=raw[off:off+cap].hex(),
                          after_hex=new.hex(),reason=why,assembly=r))
        out[off:off+cap]=new;newrel.extend(rel);return r
    assert not any(p.get_data(RESTORE-BASE,0x180))
    helper=block(RESTORE,0x180,CODE,'Preserve valid saved repeat/shuffle; invalid DWORD values publish off')
    block(0x1abac,16,f'la t9, {hex(RESTORE)}\njr t9\nnop','Tail redirect original saved-mode publication; no stack frame')
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=p.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    assert not any(row[0]<=0x1abac<row[1] for row in rows)
    rows=sorted(rows+[(RESTORE,RESTORE+helper['used_bytes'],0,0,RESTORE)])
    assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    combined=b''.join(struct.pack('<5I',*r) for r in rows)
    assert d.VirtualAddress==DATA+0x1000-BASE and len(combined)<0x2000
    off=p.get_offset_from_rva(d.VirtualAddress)
    edits.append(dict(va=hex(BASE+d.VirtualAddress),offset=hex(off),bytes=len(combined),
        before_hex=raw[off:off+len(combined)].hex(),after_hex=combined.hex(),reason='Combined exception rows plus frame-free helper'))
    out[off:off+len(combined)]=combined;struct.pack_into('<I',out,d.get_file_offset()+4,len(combined))
    for i,row in enumerate(rows):
        for j,v in enumerate(row):
            if v:newrel.append((d.VirtualAddress+i*20+j*4,3,None))
    rd=p.OPTIONAL_HEADER.DATA_DIRECTORY[5];old=p.get_data(rd.VirtualAddress,rd.Size)
    spans=[(int(e['va'],16)-BASE,int(e['va'],16)-BASE+e['bytes']) for e in edits]
    rel=[];pos=0
    while pos<len(old):
        page,n=struct.unpack_from('<II',old,pos);vals=struct.unpack_from('<'+str((n-8)//2)+'H',old,pos+8);i=0
        while i<len(vals):
            v=vals[i];i+=1;kind=v>>12;at=page+(v&4095);extra=None
            if kind==4:extra=vals[i];i+=1
            if kind and not any(a<=at<b for a,b in spans):rel.append((at,kind,extra))
        pos+=n
    rel+=newrel;rel.sort();assert len({a for a,_,_ in rel})==len(rel)
    pages={}
    for at,kind,extra in rel:
        page=at&~4095;pages.setdefault(page,[]).append((kind<<12)|(at-page))
        if kind==4:pages[page].append(extra)
    table=bytearray()
    for page,vals in sorted(pages.items()):
        if len(vals)%2:vals.append(0)
        table.extend(struct.pack('<II',page,8+len(vals)*2)+struct.pack('<'+str(len(vals))+'H',*vals))
    assert rd.VirtualAddress==DATA+0x3000-BASE and len(table)<=DATA_SIZE-0x3000
    cap=max(rd.Size,len(table));new=bytes(table)+bytes(cap-len(table));off=p.get_offset_from_rva(rd.VirtualAddress)
    edits.append(dict(va=hex(BASE+rd.VirtualAddress),offset=hex(off),bytes=cap,
        before_hex=raw[off:off+cap].hex(),after_hex=new.hex(),reason='Combined MIPS relocations'))
    out[off:off+cap]=new;struct.pack_into('<I',out,rd.get_file_offset()+4,len(table))
    result=bytes(out)
    return result,dict(base_sha256=BASE_SHA,sha256=hashlib.sha256(result).hexdigest(),edits=edits,
        added_pdata_rows=1,leaf_no_calls_or_stack=True,saved_blob_unchanged=True,
        native_executed=False,installation_ready=False)
