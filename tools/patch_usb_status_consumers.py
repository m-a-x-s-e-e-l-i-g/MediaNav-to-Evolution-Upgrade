"""Coordinated USB cover access and bounded local text snapshots, MIPS bytes only."""
import hashlib
import struct
import re
import pefile
from patch_usb_reliability import assemble
from patch_updater_copy_safety import frame,end
from patch_shared_mapping_checks import reloc_records
from patch_bt_playback import REGS

APP_SHA='935dabf375402934109a69611860985048d21b0b7c56a1cf1f3533cf1f8eb3c8'
USB_SHA='04cdba62cd70a3fe02fc9f0f1c7ddfec79868e2ad500f93173a9e8b8243ff315'
NAME='MAXmade_USB_Status_v1'

class Image:
    def __init__(self,raw,kind):
        assert hashlib.sha256(raw).hexdigest()==(APP_SHA if kind=='app' else USB_SHA)
        self.raw=raw;self.p=pefile.PE(data=raw);self.out=bytearray(raw);self.kind=kind
        self.text=0x10000+self.p.OPTIONAL_HEADER.SizeOfImage;self.rw=self.text+0x50000
        self.body=bytearray(0x50000);self.state=bytearray(0x1000);self.cursor=0
        self.reloc=reloc_records(self.p);self.rows=[];self.edits=[];self.routines=[];self.clones=[]
        self.create=self.rw+0x100;self.release=self.rw+0x104;self.name=self.text+0x2000
        self.track=self.rw+0x200;self.fallback=self.rw+0x204
        b=(NAME+'\0').encode('utf-16-le');self.body[0x2000:0x2000+len(b)]=b
        self.wait=0x1850a0 if kind=='app' else 0x2f048
        self.close=0x185028 if kind=='app' else self.import_at(553)
    def import_at(self,ordinal):
        return next(s.address for d in self.p.DIRECTORY_ENTRY_IMPORT if d.dll.lower()==b'coredll.dll'
                    for s in d.imports if s.ordinal==ordinal)
    def edit(self,va,new,reason):
        off=self.p.get_offset_from_rva(va-0x10000);self.file_edit(off,new,reason,va)
    def file_edit(self,off,new,reason,va=None):
        self.edits.append(dict(offset=off,va=va,bytes=len(new),before_hex=bytes(self.out[off:off+len(new)]).hex(),after_hex=new.hex(),reason=reason))
        self.out[off:off+len(new)]=new
    def routine(self,at,cap,code,prolog):
        lines=[];custom=[];pc=at
        for line in code.splitlines():
            line=line.strip()
            if not line:continue
            if line.endswith(':'):lines.append(line);continue
            op=line.split()[0]
            if op in ('lwl','lwr','swl','swr','j','blez'):
                custom.append((pc,line));lines.append('nop')
            else:lines.append(line)
            pc+=8 if op=='la' else 4
        b,r,rel=assemble('\n'.join(lines),at,cap);b=bytearray(b)
        for pc,line in custom:
            if line.startswith('blez '):
                reg,label=line[5:].split(',');dst=int(r['labels'][label.strip()],16)
                word=(6<<26)|(REGS[reg.strip()]<<21)|(((dst-pc-4)//4)&65535)
                struct.pack_into('<I',b,pc-at,word);continue
            if line.startswith('j '):
                word=(2<<26)|((int(line[2:],0)>>2)&0x3ffffff)
                struct.pack_into('<I',b,pc-at,word);rel.append((pc-0x10000,5,None));continue
            op,rt,imm,rs=[x for x in re.split(r'[\s,()]+',line) if x]
            word=({'lwl':0x22,'lwr':0x26,'swl':0x2a,'swr':0x2e}[op]<<26)|(REGS[rs]<<21)|(REGS[rt]<<16)|(int(imm,0)&65535)
            struct.pack_into('<I',b,pc-at,word)
        r['assembly']=code;self.body[at-self.text:at-self.text+cap]=b
        self.reloc+=rel;self.rows.append((at,at+r['used_bytes'],0,0,at+prolog));self.routines.append(r)
    def hook(self,at,code,size=8):
        jump=code.startswith('j ')
        b,_,rel=assemble('jal '+code[2:] if jump else code,at,size)
        if jump:b=((int.from_bytes(b[:4],'little')&0x3ffffff)|(2<<26)).to_bytes(4,'little')+b[4:]
        self.edit(at,b,'Reviewed consumer/writer hook')
        self.reloc=[r for r in self.reloc if not at-0x10000<=r[0]<at-0x10000+size]+rel
    def redirect(self,at,target):
        self.hook(at,f'j {hex(target)}\nnop')
    def clone(self,start,target):
        d=self.p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        rows=[struct.unpack_from('<5I',self.p.get_data(d.VirtualAddress,d.Size),i) for i in range(0,d.Size,20)]
        row=next((r for r in rows if r[0]==start),None)
        if start==0x1386e8 and row is None:row=(start,0x13878c,0,0,start)
        assert row is not None
        endva=(row[1]+3)&~3
        raw=bytearray(self.p.get_data(start-0x10000,endva-start));shift=target-start
        # Relative branches retain their offsets. Absolute intra-function jumps follow the clone.
        for i in range(0,len(raw),4):
            word=int.from_bytes(raw[i:i+4],'little');op=word>>26
            if op in (2,3):
                dst=((start+i+4)&0xf0000000)|((word&0x3ffffff)<<2)
                if start<=dst<endva:
                    raw[i:i+4]=((op<<26)|((dst+shift)>>2&0x3ffffff)).to_bytes(4,'little')
        self.body[target-self.text:target-self.text+len(raw)]=raw
        for at,kind,companion in reloc_records(self.p):
            if start-0x10000<=at<endva-0x10000:self.reloc.append((at+shift,kind,companion))
        self.rows.append((target,target+len(raw),row[2],row[3],target+row[4]-start))
        # This text function has only the original GS cookie handler, whose data
        # describes unchanged stack offsets, not moved instruction scopes.
        assert row[2]==row[3]==0 or (start==0x4dcc8 and row[2:4]==(0x140db8,0x183200))
        self.clones.append(dict(original=start,start=target,bytes=len(raw),original_prolog=row[4]))
        return len(raw)
    def finish(self):
        p=self.p;directory=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        old=[struct.unpack_from('<5I',p.get_data(directory.VirtualAddress,directory.Size),i) for i in range(0,directory.Size,20)]
        redirects={e['va'] for e in self.edits if e['bytes']==8}
        rows=[(a,b,0,0,a) if a in redirects else (a,b,c,d,e) for a,b,c,d,e in old]+self.rows
        rows.sort();assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
        pdata=0x3000
        for i,row in enumerate(rows):
            self.body[pdata+i*20:pdata+(i+1)*20]=struct.pack('<5I',*row)
            for j,v in enumerate(row):
                if v:self.reloc.append((self.text-0x10000+pdata+i*20+j*4,3,None))
        # Original rows also stay physically intact; original relocation records remain valid.
        self.file_edit(directory.get_file_offset(),struct.pack('<II',self.text-0x10000+pdata,len(rows)*20),'Exception directory relocated to cumulative rows')
        pages={}
        records=sorted(self.reloc);assert len({a for a,_,_ in records})==len(records)
        for at,kind,c in records:
            page=at&~4095;pages.setdefault(page,[]).append(kind<<12|at-page)
            if kind==4:pages[page].append(c)
        encoded=bytearray()
        for page,values in sorted(pages.items()):
            if len(values)%2:values.append(0)
            encoded+=struct.pack('<II',page,len(values)*2+8)+struct.pack('<'+'H'*len(values),*values)
        reloc_at=(pdata+len(rows)*20+0xfff)&~0xfff
        self.body[reloc_at:reloc_at+len(encoded)]=encoded
        rd=p.OPTIONAL_HEADER.DATA_DIRECTORY[5]
        self.file_edit(rd.get_file_offset(),struct.pack('<II',self.text-0x10000+reloc_at,len(encoded)),'Cumulative relocation directory')
        # Preserve every existing import/IAT. Add one descriptor for the two mutex APIs.
        descriptors=b''.join(d.struct.__pack__() for d in p.DIRECTORY_ENTRY_IMPORT)
        n=len(descriptors);assert n+40<=0x100
        self.state[:n]=descriptors
        self.state[n:n+20]=struct.pack('<5I',self.rw-0x10000+0x120,0,0,self.rw-0x10000+0x140,self.rw-0x10000+0x100)
        for off in (0x100,0x120):self.state[off:off+12]=struct.pack('<III',0x80000000|555,0x80000000|556,0)
        self.state[0x140:0x14c]=b'COREDLL.dll\0'
        imp=p.OPTIONAL_HEADER.DATA_DIRECTORY[1]
        self.file_edit(imp.get_file_offset(),struct.pack('<II',self.rw-0x10000,n+40),'Old imports plus CreateMutexW/ReleaseMutex')
        size=(reloc_at+len(encoded)+0xfff)&~0xfff;assert size<=0x50000
        header=p.sections[-1].get_file_offset()+40;assert header+80<=p.OPTIONAL_HEADER.SizeOfHeaders
        assert not any(self.raw[header:header+80])
        off=(len(self.out)+0x1ff)&~0x1ff
        sections=[(b'.mxusb',size,self.text-0x10000,size,off,0x60000020),
                  (b'.mxstate',0x1000,self.rw-0x10000,0x1000,off+size,0xc0000040)]
        for i,(name,vs,rva,rawsize,ptr,flags) in enumerate(sections):
            self.file_edit(header+i*40,struct.pack('<8s8I',name,vs,rva,rawsize,ptr,0,0,0,flags),'New code/metadata or mutex IAT/state section')
        self.file_edit(p.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),struct.pack('<H',len(p.sections)+2),'Section count')
        for key,val in [('SizeOfImage',self.rw+0x1000-0x10000),('SizeOfCode',p.OPTIONAL_HEADER.SizeOfCode+size),
                        ('SizeOfInitializedData',p.OPTIONAL_HEADER.SizeOfInitializedData+0x1000)]:
            self.file_edit(p.OPTIONAL_HEADER.get_field_absolute_offset(key),struct.pack('<I',val),key)
        self.out+=bytes(off-len(self.out))+self.body[:size]+self.state
        out=bytes(self.out)
        return out,dict(sha256=hashlib.sha256(out).hexdigest(),input_sha256=hashlib.sha256(self.raw).hexdigest(),
            edits=self.edits,routines=self.routines,clones=self.clones,helper_rows=self.rows,
            code_va=self.text,state_va=self.rw,code_raw_offset=off,code_bytes=size,
            mutex_name=NAME,new_import_ordinals=[555,556],native_executed=False)

def common(i):
    lock,unlock,copy=i.text,i.text+0x100,i.text+0x200
    i.routine(lock,0x100,f'''{frame(0x28,['s0','s1'])}
move s1, a0
move a0, zero
move a1, zero
la a2, {hex(i.name)}
la t8, {hex(i.create)}
lw t9, 0(t8)
jalr t9
nop
beqz v0, fail
move s0, v0
move a0, s0
la t8, {hex(i.wait)}
lw t9, 0(t8)
jalr t9
move a1, s1
beqz v0, owned
addiu t0, zero, 0x80
beq v0, t0, owned
nop
la t8, {hex(i.close)}
lw t9, 0(t8)
jalr t9
move a0, s0
fail:
move s0, zero
owned:
move v0, s0
{end(0x28,['s0','s1'])}''',16)
    i.routine(unlock,0x100,f'''{frame(0x20,['s0'])}
move s0, a0
la t8, {hex(i.release)}
lw t9, 0(t8)
jalr t9
nop
la t8, {hex(i.close)}
lw t9, 0(t8)
jalr t9
move a0, s0
{end(0x20,['s0'])}''',12)
    if i.kind=='app':
        i.routine(copy,0x100,f'''{frame(0x30,['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
beqz s1, fail
move s2, a2
jal {hex(lock)}
move a0, zero
beqz v0, fail
move s3, v0
next:
beqz s2, done
nop
lbu t0, 0(s1)
sb t0, 0(s0)
addiu s1, s1, 1
addiu s2, s2, -1
b next
addiu s0, s0, 1
done:
jal {hex(unlock)}
move a0, s3
b return
addiu v0, zero, 1
fail:
move v0, zero
return:
{end(0x30,['s0','s1','s2','s3'])}''',24)
    return lock,unlock,copy

def app(raw):
    i=Image(raw,'app');lock,unlock,copy=common(i)
    title,text,setcover,draw,clip,reset=[i.text+n for n in (0x300,0x600,0x800,0xa00,0xc00,0xe00)]
    ct,cd,cc,cr=[i.text+n for n in (0x1000,0x1600,0x1a00,0x1c00)]
    for old,new in ((0x4dcc8,ct),(0x138860,cd),(0x138ba4,cc),(0x1386e8,cr)):i.clone(old,new)
    i.routine(title,0x300,f'''{frame(0x250,['s0','s1','s2','s3'])}
la t0, 0x186ce8
lw t0, 0(t0)
beqz t0, done
nop
lw a1, 0xc4(t0)
beqz a1, done
nop
addiu a1, a1, 0x20e
addiu a0, sp, 0x20
jal {hex(copy)}
addiu a2, zero, 0x208
beqz v0, done
nop
sh zero, 0x226(sp)
addiu s0, sp, 0x20
move t0, s0
move s1, zero
length:
lhu t1, 0(t0)
beqz t1, suffix
nop
addiu s1, s1, 1
b length
addiu t0, t0, 2
suffix:
sltiu t0, s1, 5
bnez t0, display
nop
addiu t0, s1, -4
sll t0, t0, 1
addu s2, s0, t0
move a0, s2
la a1, 0x14eae4
jal 0x140310
nop
beqz v0, strip
nop
move a0, s2
la a1, 0x14eaf0
jal 0x140310
nop
bnez v0, display
nop
strip:
sh zero, 0(s2)
display:
la t0, 0x187b38
lw s3, 0(t0)
addiu a0, s3, 0xc4
move a1, s0
addiu a2, zero, 6
lw t0, 0xac(s3)
blez t0, standard
nop
sll t0, t0, 2
addiu t1, s3, 0x84
addu t0, t0, t1
lw t0, 0(t0)
addiu t1, zero, 2
bne t0, t1, standard
nop
jal 0xe5f58
nop
b done
nop
standard:
jal 0xe6464
nop
done:
{end(0x250,['s0','s1','s2','s3'])}''',24)
    sanitize='\n'.join(f'sh zero, {hex(0x20+n+0x206)}(sp)' for n in (6,0x20e,0x416,0x61e,0x826,0xa2e,0xc36))
    i.routine(text,0x200,f'''{frame(0xea0,['s0','s1','s2'])}
move s0, a0
move s1, a1
move s2, a2
addiu a0, sp, 0x20
jal {hex(copy)}
addiu a2, zero, 0xe56
beqz v0, done
nop
{sanitize}
move a0, s0
addiu a1, sp, 0x20
jal {hex(ct)}
move a2, s2
done:
{end(0xea0,['s0','s1','s2'])}''',20)
    i.routine(setcover,0x200,f'''{frame(0x50,['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
jal {hex(lock)}
move a0, zero
beqz v0, done
move s2, v0
move s3, zero
beqz s1, fallback
nop
addiu t0, s1, 0xe4e
lwl s3, 3(t0)
lwr s3, 0(t0)
la t0, {hex(i.fallback)}
sw zero, 0(t0)
bnez s3, get
nop
fallback:
la t0, 0x186538
lw a0, 0(t0)
beqz a0, missing
nop
jal 0x13dde0
addiu a1, zero, 0x75
move s3, v0
la t0, {hex(i.fallback)}
sw s3, 0(t0)
get:
beqz s3, missing
nop
move a0, s3
addiu a1, zero, 24
jal 0x140048
addiu a2, sp, 0x20
addiu t0, zero, 24
beq v0, t0, assign
nop
missing:
move s3, zero
sw zero, 0x24(sp)
sw zero, 0x28(sp)
assign:
la t0, 0x186538
lw t0, 0(t0)
bnez t0, assign_api
nop
sw zero, 0x3c(s0)
sw zero, 0x34(s0)
sw zero, 0x38(s0)
lui t0, 0xffff
ori t0, t0, 0xf7ff
lw t1, 0x2c(s0)
and t1, t1, t0
sw t1, 0x2c(s0)
b track
nop
assign_api:
move a0, s0
move a1, s3
lw a2, 0x24(sp)
jal 0x138d60
lw a3, 0x28(sp)
track:
la t0, {hex(i.track)}
sw s0, 0(t0)
jal {hex(unlock)}
move a0, s2
done:
{end(0x50,['s0','s1','s2','s3'])}''',24)
    for target,original in ((draw,cd),(clip,cc)):
        i.routine(target,0x200,f'''la t8, {hex(i.track)}
lw t9, 0(t8)
beq a0, t9, guarded
nop
j {hex(original)}
nop
guarded:
{frame(0x60,['s0','s1','s2','s3','s4'])}
move s0, a0
move s1, a1
move s2, a2
jal {hex(lock)}
move a0, zero
beqz v0, fail
move s3, v0
la t0, 0x186ce8
lw t0, 0(t0)
beqz t0, skip
nop
lw t0, 0xc4(t0)
beqz t0, skip
nop
addiu t0, t0, 0xe4e
lwl t1, 3(t0)
lwr t1, 0(t0)
bnez t1, compare
nop
la t0, {hex(i.fallback)}
lw t1, 0(t0)
compare:
lw t0, 0x3c(s0)
beqz t0, skip
nop
bne t0, t1, skip
nop
move a0, t0
addiu a1, zero, 24
jal 0x140048
addiu a2, sp, 0x20
addiu t0, zero, 24
bne v0, t0, skip
nop
move a0, s0
move a1, s1
jal {hex(original)}
move a2, s2
b release
move s4, v0
skip:
move s4, zero
release:
jal {hex(unlock)}
move a0, s3
b done
move v0, s4
fail:
move v0, zero
done:
{end(0x60,['s0','s1','s2','s3','s4'])}''',0)
        row=i.rows.pop();guarded=target+28
        i.rows.extend([(target,guarded,0,0,target),(guarded,row[1],0,0,guarded+28)])
    i.routine(reset,0x100,f'''la t0, {hex(i.track)}
lw t1, 0(t0)
bne a0, t1, original
nop
sw zero, 0(t0)
la t0, {hex(i.fallback)}
sw zero, 0(t0)
original:
j {hex(cr)}
nop''',0)
    for at,target in ((0x1def8,title),(0x4dcc8,text),(0x138860,draw),(0x138ba4,clip),(0x1386e8,reset)):i.redirect(at,target)
    i.hook(0x4e268,f'''move s1, a0
move s2, a2
jal {hex(setcover)}
addiu a0, s1, 0x8e0
addiu s3, s1, 0x8e0''',0x80)
    return i.finish()

def usb(raw):
    i=Image(raw,'usb');lock,unlock,_=common(i)
    writer,delete,clone,install=[i.text+n for n in (0x300,0x500,0x700,0x800)]
    i.clone(0x24094,clone)
    i.routine(writer,0x200,f'''{frame(0x40,['s0','s1','s2','s3','s4','s5'])}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
jal {hex(lock)}
addiu a0, zero, -1
beqz v0, fail
move s4, v0
move a0, s0
move a1, s1
move a2, s2
jal {hex(clone)}
move a3, s3
move s5, v0
jal {hex(unlock)}
move a0, s4
b done
move v0, s5
fail:
move v0, zero
done:
{end(0x40,['s0','s1','s2','s3','s4','s5'])}''',32)
    i.routine(delete,0x200,f'''{frame(0x40,['s0','s1','s2','s3'])}
move s0, a0
move s3, a1
jal {hex(lock)}
addiu a0, zero, -1
beqz v0, fail
move s1, v0
lwl t0, 3(s3)
lwr t0, 0(s3)
bne t0, s0, published
nop
swl zero, 3(s3)
swr zero, 0(s3)
published:
jal 0x231a4
nop
beqz v0, destroy
nop
lw t0, 0x40(v0)
beqz t0, destroy
nop
lw t0, 8(t0)
beqz t0, destroy
nop
addiu t0, t0, 0xe4e
lwl t1, 3(t0)
lwr t1, 0(t0)
bne t1, s0, destroy
nop
swl zero, 3(t0)
swr zero, 0(t0)
destroy:
jal 0x2516c
move a0, s0
move s2, v0
jal {hex(unlock)}
move a0, s1
b done
move v0, s2
fail:
move v0, zero
done:
{end(0x40,['s0','s1','s2','s3'])}''',24)
    i.routine(install,0x200,f'''{frame(0x30,['s0','s1','s2'])}
move s0, a0
move s1, a1
jal {hex(lock)}
addiu a0, zero, -1
beqz v0, done
move s2, v0
swl s1, 3(s0)
swr s1, 0(s0)
jal {hex(unlock)}
move a0, s2
done:
jal 0x231a4
nop
{end(0x30,['s0','s1','s2'])}''',20)
    i.redirect(0x24094,writer)
    # These four sites release the CPlayControl cover, not unrelated GDI objects.
    sites=[]
    for a,b in ((0x19508,0x19564),(0x1a570,0x1a594),(0x1a60c,0x1a69c),(0x1ad84,0x1ae54)):
        for at in range(a,b,4):
            if int.from_bytes(i.p.get_data(at-0x10000,4),'little')==(3<<26)|(0x2516c>>2):sites.append(at)
    assert len(sites)==4
    for at in sites:i.hook(at,f'jal {hex(delete)}\nmove a1, s0',8)
    for at in (0x19540,0x19544,0x1a63c,0x1a644,0x1adb4,0x1adbc):
        word=int.from_bytes(i.p.get_data(at-0x10000,4),'little')
        assert word>>26 in (0x2a,0x2e) and (word>>16)&31==0
        i.hook(at,'nop',4)
    i.hook(0x1a590,f'move a1, s5\njal {hex(install)}\nmove a0, s0',12)
    out,r=i.finish();r['cover_delete_sites']=sites
    return out,r
