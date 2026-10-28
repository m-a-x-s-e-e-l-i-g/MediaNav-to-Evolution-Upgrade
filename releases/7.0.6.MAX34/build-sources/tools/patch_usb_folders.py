"""Bounded next/previous folder selection, with per-entry cancellation checks."""
import hashlib
import re
import struct
import pefile
from patch_usb_reliability import assemble,BASE,DATA,DATA_SIZE
from patch_updater_copy_safety import frame,end
from patch_bt_playback import REGS

BASE_SHA='3b1aabd180c9cc5a681f2e0146535e8cef83f1df564aa0bc1f9f0703f61f4fce'
ITER,CHECK=0x3ca00,0x3cd00

def folder_assemble(code,start,capacity):
    lines=[];custom=[];labels={};pc=start
    for line in code.splitlines():
        line=line.split('#',1)[0].strip()
        if not line:continue
        if line.endswith(':'):labels[line[:-1]]=pc;lines.append(line);continue
        if line.split()[0] in ('lh','bltz','blez','mult'):custom.append((pc,line));lines.append('nop')
        else:lines.append(line)
        pc+=8 if line.startswith('la ') else 4
    raw,recipe,rel=assemble('\n'.join(lines),start,capacity);out=bytearray(raw)
    for at,line in custom:
        op,*args=[p for p in re.split(r'[\s,()]+',line) if p]
        if op=='lh':
            rt,imm,rs=args;imm=int(imm,0);assert -32768<=imm<=32767
            word=(0x21<<26)|(REGS[rs]<<21)|(REGS[rt]<<16)|(imm&65535)
        elif op=='mult':word=(REGS[args[0]]<<21)|(REGS[args[1]]<<16)|0x18
        else:
            dest=labels[args[1]];delta=(dest-at-4)//4;assert -32768<=delta<=32767
            word=((1 if op=='bltz' else 6)<<26)|(REGS[args[0]]<<21)|(delta&65535)
        struct.pack_into('<I',out,at-start,word)
    recipe['source_assembly']=code
    return bytes(out),recipe,rel

def iterator():
    regs=['s0','s1','s2','s3','s4','s5','s6','s7'];n=0x50
    step=f'''move a0, s0
move a1, s2
move a2, s7
jal {hex(CHECK)}
move a3, s6
addiu s6, s6, 1
beqz v0, failed
nop'''
    return f'''
{frame(n,regs)}
move s0, a0
move s1, a1
move s5, a2
move s6, zero
beqz s0, failed
nop
lh s2, 0x2750(s0)
blez s2, failed
nop
sltiu t0, s2, 5001
beqz t0, failed
nop
lw s7, 0x38(s0)
beqz s7, failed
nop
la t0, 0x275c4
beq s7, t0, failed
nop
move s3, zero
find:
{step}
sll t0, s3, 1
addu t0, t0, s0
lh t1, 0x40(t0)
beq t1, s1, found
nop
addiu s3, s3, 1
sltu t0, s3, s2
bnez t0, find
nop
# Original unknown-current fallback: start from table position zero.
move s3, zero
found:
move s4, s2
select:
{step}
addu s3, s3, s5
bltz s3, wrap_back
nop
sltu t0, s3, s2
bnez t0, load
nop
b load
move s3, zero
wrap_back:
addiu s3, s2, -1
load:
sll t0, s3, 1
addu t0, t0, s0
lh t2, 0x40(t0)
move t3, t2
addiu t0, zero, -1
beq t3, t0, root
nop
sltiu t0, t3, 5000
beqz t0, skip
nop
b record
nop
root:
move t3, zero
record:
addiu t0, zero, 0x220
mult t3, t0
mflo t0
addu t0, t0, s7
lh t1, 0x214(t0)
blez t1, skip
nop
sltiu t0, t1, 5001
beqz t0, skip
nop
b done
move v0, t2
skip:
beq t2, s1, no_playable
nop
addiu s4, s4, -1
bnez s4, select
nop
# No playable folder after one full cycle; preserve requested current ID.
no_playable:
b done
move v0, s1
failed:
move v0, zero
done:
{end(n,regs)}
''',n,regs

def check():
    regs=['s0','s1','s2','s3'];n=0x28
    return f'''
{frame(n,regs)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
jal 0x231a4
nop
beqz v0, failed
nop
lw t0, 0x18(v0)
bnez t0, failed
nop
jal 0x3e780
move a0, s3
jal 0x231a4
nop
beqz v0, failed
nop
lw t0, 0x18(v0)
bnez t0, failed
nop
lh t0, 0x2750(s0)
bne t0, s1, failed
nop
lw t0, 0x38(s0)
bne t0, s2, failed
nop
b done
addiu v0, zero, 1
failed:
move v0, zero
done:
{end(n,regs)}
''',n,regs

def patch(raw):
    assert hashlib.sha256(raw).hexdigest()==BASE_SHA
    p=pefile.PE(data=raw);out=bytearray(raw);edits=[];newrel=[];helpers=[]
    def block(at,cap,code,why):
        new,r,rel=folder_assemble(code,at,cap);off=p.get_offset_from_rva(at-BASE)
        edits.append(dict(va=hex(at),offset=hex(off),bytes=cap,before_hex=raw[off:off+cap].hex(),
                          after_hex=new.hex(),reason=why,assembly=r))
        out[off:off+cap]=new;newrel.extend(rel);return r
    assert not any(p.get_data(ITER-BASE,0x400))
    for at,cap,fn in ((ITER,0x300,iterator),(CHECK,0x100,check)):
        code,n,regs=fn();r=block(at,cap,code,'Bounded folder traversal' if at==ITER else 'Cancellation and snapshot checks around batched yield')
        helpers.append((at,at+r['used_bytes'],0,0,at+(len(regs)+2)*4))
    for at,direction in ((0x14720,1),(0x14884,-1)):
        block(at,16,f'la t9, {hex(ITER)}\njr t9\naddiu a2, zero, {direction}','Tail redirect without original frame')
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=p.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    for at,finish in ((0x14720,0x14884),(0x14884,0x149e0)):
        i=next(i for i,row in enumerate(rows) if row[0]==at)
        assert rows[i][1]==finish and rows[i][2:4]==(0,0);rows[i]=(*rows[i][:4],at)
    rows=sorted(rows+helpers);assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    combined=b''.join(struct.pack('<5I',*r) for r in rows)
    assert d.VirtualAddress==DATA+0x1000-BASE and len(combined)<0x2000
    off=p.get_offset_from_rva(d.VirtualAddress)
    edits.append(dict(va=hex(BASE+d.VirtualAddress),offset=hex(off),bytes=len(combined),
        before_hex=raw[off:off+len(combined)].hex(),after_hex=combined.hex(),reason='Combined exception rows'))
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
        added_pdata_rows=2,traversal_limit_per_phase=5000,native_executed=False,installation_ready=False)
