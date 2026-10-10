"""Pinned cumulative WMA/shuffle development. No native CE execution."""
import hashlib
import struct
import pefile
from patch_usb_reliability import assemble, BASE, DATA, DATA_SIZE
from patch_updater_copy_safety import frame, end

BASE_SHA='491c49894eb6f49e0f4dda55c588203d957f1746809a726de368af2d52cdebf9'
EXACT,SEEK,FIELD,GATE,YIELD,BUILD,WRAP,READY=0x3ce00,0x3d580,0x3e200,0x3e600,0x3e780,0x3f200,0x3fa80,0x3fc00

def api(at):return f'la t8, {hex(at)}\nlw t9, 0(t8)\njalr t9\nnop'

def exact():
    regs=['s0','s1'];n=0x30
    return f'''
{frame(n,regs)}
move s0, a0
move s1, a2
lw t0, 4(s0)
lw t1, 8(s0)
sltu t2, t1, t0
bnez t2, bad
nop
subu t1, t1, t0
sltu t2, t1, s1
bnez t2, bad
nop
sltiu t2, s1, 261
beqz t2, bad
nop
beqz s1, good
nop
lw a0, 0(s0)
addiu a3, sp, 0x20
sw zero, 0x20(sp)
sw zero, 0x10(sp)
{api(0x2f058)}
beqz v0, bad
nop
lw t0, 0x20(sp)
bne t0, s1, bad
nop
lw t0, 4(s0)
addu t0, t0, s1
sw t0, 4(s0)
good:
b done
addiu v0, zero, 1
bad:
move v0, zero
done:
{end(n,regs)}
''',n,regs

def seek():
    regs=['s0','s1'];n=0x30
    return f'''
{frame(n,regs)}
move s0, a0
move s1, a1
lw t0, 4(s0)
lw t1, 8(s0)
sltu t2, s1, t0
bnez t2, bad
nop
sltu t2, t1, s1
bnez t2, bad
nop
beq s1, t0, good
nop
lw a0, 0(s0)
move a2, zero
move a3, zero
{api(0x2f060)}
bne v0, s1, bad
nop
sw s1, 4(s0)
good:
b done
addiu v0, zero, 1
bad:
move v0, zero
done:
{end(n,regs)}
''',n,regs

def field():
    # a0 stream, a1 output UTF16[260], a2 full field byte length.
    # Preserve the existing 30-unit WMA display limit, using complete units.
    regs=['s0','s1','s2','s3'];n=0x70
    return f'''
{frame(n,regs)}
move s0, a0
move s1, a1
move s2, a2
andi t0, s2, 1
bnez t0, bad
nop
lw s3, 4(s0)
addu s3, s3, s2
lw t0, 8(s0)
sltu t0, t0, s3
bnez t0, bad
nop
move a0, s1
move a1, zero
jal 0x253dc
addiu a2, zero, 62
sltiu t0, s2, 61
bnez t0, bounded
move a2, s2
addiu a2, zero, 60
bounded:
move a0, s0
jal {hex(EXACT)}
move a1, s1
beqz v0, bad
nop
move a0, s0
jal {hex(SEEK)}
move a1, s3
beqz v0, bad
nop
# If a long field is cut between surrogate units, omit the dangling high half.
sltiu t0, s2, 61
bnez t0, good
nop
lhu t0, 58(s1)
andi t0, t0, 0xfc00
ori t1, zero, 0xd800
bne t0, t1, good
nop
sh zero, 58(s1)
good:
b done
addiu v0, zero, 1
bad:
move v0, zero
done:
{end(n,regs)}
''',n,regs

def reader():
    # Keep the original 0x2b8 frame, FP, cookie, Unicode context and EH cleanup.
    # Stream state is at fp+48; separate local GUID/length scratch at fp+60.
    def read(n):return f'addiu a0, fp, 0x48\naddiu a1, fp, 0x80\njal {hex(EXACT)}\naddiu a2, zero, {n}\nbeqz v0, fail\nnop'
    def skip():return f'addiu a0, fp, 0x48\njal {hex(SEEK)}\nnop\nbeqz v0, fail\nnop'
    def value(off,length,flag):return f'''
addiu a0, fp, 0x48
addiu a1, s2, {hex(off)}
jal {hex(FIELD)}
{length}
beqz v0, fail
nop
addiu a0, fp, 0x28
addiu a1, s2, {hex(off)}
jal 0x24c44
addiu a2, zero, 0x103
beqz v0, valid_{flag}
nop
lw t0, 0xe40(s2)
ori t0, t0, {flag}
sw t0, 0xe40(s2)
valid_{flag}:
'''
    return f'''
move a0, s2
move a1, zero
jal 0x253dc
addiu a2, zero, 0xe44
addiu t0, zero, 3
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
move a0, s0
lui a1, 0x8000
addiu a2, zero, 1
move a3, zero
{api(0x2f034)}
move s1, v0
addiu t0, zero, -1
beq s1, t0, 0x18f08
nop
sw s1, 0x48(fp)
sw zero, 0x4c(fp)
move a0, s1
move a1, zero
{api(0x2f064)}
addiu t0, zero, -1
beq v0, t0, fail
nop
sltiu t0, v0, 30
bnez t0, fail
nop
sw v0, 0x50(fp)
{read(30)}
addiu a0, fp, 0x80
la a1, 0x2884c
jal 0x2594c
addiu a2, zero, 16
bnez v0, fail
nop
lw t0, 0x94(fp)
bnez t0, fail
nop
lw s5, 0x90(fp)
sltiu t0, s5, 30
bnez t0, fail
nop
srl t0, s5, 31
bnez t0, fail
nop
lw t0, 0x50(fp)
sltu t0, t0, s5
bnez t0, fail
nop
lw s3, 0x98(fp)
beqz s3, fail
nop
sltiu t0, s3, 17
beqz t0, fail
nop
lbu t0, 0x9c(fp)
addiu t1, zero, 1
bne t0, t1, fail
nop
lbu t0, 0x9d(fp)
addiu t1, zero, 2
bne t0, t1, fail
nop
sw s5, 0x50(fp)
child:
{read(24)}
lw t0, 0x94(fp)
bnez t0, fail
nop
lw t0, 0x90(fp)
sltiu t1, t0, 24
bnez t1, fail
nop
lw t1, 0x4c(fp)
addiu t1, t1, -24
subu t2, s5, t1
sltu t2, t2, t0
bnez t2, fail
nop
addu s4, t1, t0
sw s4, 0x50(fp)
addiu a0, fp, 0x60
addiu a1, fp, 0x80
jal 0x25668
addiu a2, zero, 16
addiu a0, fp, 0x60
la a1, 0x2886c
jal 0x2594c
addiu a2, zero, 16
beqz v0, content
nop
addiu a0, fp, 0x60
la a1, 0x2885c
jal 0x2594c
addiu a2, zero, 16
bnez v0, next
nop
# Extended description: no copied descriptor-name array or unbounded wcsicmp.
{read(2)}
lhu s6, 0x80(fp)
descriptor:
beqz s6, next
nop
{read(2)}
lhu t0, 0x80(fp)
andi t1, t0, 1
bnez t1, fail
move s7, zero
addiu t1, zero, 26
beq t0, t1, name
nop
addiu t1, zero, 28
beq t0, t1, name
nop
lw a1, 0x4c(fp)
addu a1, a1, t0
{skip()}
b value_header
nop
name:
sw t0, 0x70(fp)
sh zero, 0x9a(fp)
move a2, t0
addiu a0, fp, 0x48
jal {hex(EXACT)}
addiu a1, fp, 0x80
beqz v0, fail
nop
lw t0, 0x70(fp)
addiu t1, zero, 28
bne t0, t1, compare_name
nop
lhu t0, 0x9a(fp)
bnez t0, value_header
nop
compare_name:
addiu a0, fp, 0x80
la a1, 0x28b60
jal 0x255b8
nop
sltiu s7, v0, 1
value_header:
{read(4)}
lhu t0, 0x80(fp)
lhu t1, 0x82(fp)
beqz s7, skip_value
nop
bnez t0, skip_value
nop
{value(0x208,'lhu a2, 0x82(fp)',2)}
b descriptor_done
nop
skip_value:
lw a1, 0x4c(fp)
addu a1, a1, t1
{skip()}
descriptor_done:
b descriptor
addiu s6, s6, -1
content:
{read(10)}
addiu a0, fp, 0x60
addiu a1, fp, 0x80
jal 0x25668
addiu a2, zero, 10
{value(0x410,'lhu a2, 0x60(fp)',1)}
{value(0x618,'lhu a2, 0x62(fp)',4)}
lhu t0, 0x64(fp)
lhu t1, 0x66(fp)
lhu t2, 0x68(fp)
addu t0, t0, t1
addu t0, t0, t2
lw a1, 0x4c(fp)
addu a1, a1, t0
{skip()}
next:
move a1, s4
{skip()}
addiu s3, s3, -1
sw s5, 0x50(fp)
bnez s3, child
nop
b close
nop
fail:
move a0, s2
move a1, zero
jal 0x253dc
addiu a2, zero, 0xe44
close:
lw t0, 0xe40(s2)
ori t0, t0, 0x80
sw t0, 0xe40(s2)
move a0, s1
{api(0x2f038)}
b 0x18f08
nop
'''

def gate():
    regs=[];n=0x28
    # Forward all seven MIPS arguments before invoking the existing pool body.
    return f'''
{frame(n,regs)}
beqz a0, bad
nop
beqz a1, bad
nop
sltiu t0, a2, 5000
beqz t0, bad
nop
sltiu t0, a3, 5000
beqz t0, bad
nop
sltu t0, a3, a2
bnez t0, bad
nop
lw t0, 0x40(sp)
addiu t1, zero, -1
beq t0, t1, valid
nop
sltu t1, t0, a2
bnez t1, bad
nop
sltu t1, a3, t0
bnez t1, bad
nop
valid:
sw t0, 0x18(sp)
lw t0, 0x3c(sp)
sw t0, 0x14(sp)
lw t0, 0x38(sp)
jal 0x198e4
sw t0, 0x10(sp)
b done
nop
bad:
addiu v0, zero, -1
done:
{end(n,regs)}
''',n,regs

def yields():
    regs=[];n=0x20
    # Same cancellation tests every track; Sleep(1) once per 32, Sleep(0) otherwise.
    return f'''
{frame(n,regs)}
andi t0, a0, 31
sltiu a0, t0, 1
{api(0x2f008)}
{end(n,regs)}
''',n,regs

def builder():
    regs=['s0','s1','s2','s3','s4','s5','s6','s7'];n=0x50
    return f'''
{frame(n,regs)}
move s0, a0
sw zero, 0xe5c(s0)
sw zero, 0xe4c(s0)
sw zero, 0xe58(s0)
sw zero, 0xe50(s0)
sw zero, 0xe54(s0)
move s4, zero
sw zero, 0x20(sp)
la s2, 0x30108
jal 0x231a4
nop
lw a0, 0x48(v0)
# Unaligned current-track field, loaded as bytes without reading neighbors.
lbu a1, 0x2916(s0)
lbu t0, 0x2917(s0)
sll t0, t0, 8
or a1, a1, t0
lbu t0, 0x2918(s0)
sll t0, t0, 16
or a1, a1, t0
lbu t0, 0x2919(s0)
sll t0, t0, 24
jal 0x132fc
or a1, a1, t0
move s6, v0
move s5, s6
loop:
sltiu t0, s5, 5000
beqz t0, failed
nop
lw t0, 0x20(sp)
addiu t0, t0, 1
sltiu t1, t0, 5001
beqz t1, failed
nop
sw t0, 0x20(sp)
jal 0x231a4
nop
lw t0, 0x18(v0)
bnez t0, failed
nop
lbu t0, 0x291e(s0)
addiu t1, zero, 1
bne t0, t1, failed
nop
# Publication remains empty until the complete, bounded list succeeds.
lw a0, 0x48(v0)
jal 0x12f10
move a1, s5
move s1, v0
jal 0x231a4
nop
lw a0, 0x48(v0)
jal 0x12f48
move a1, s5
move s7, v0
beqz s7, failed
nop
sltiu t0, s7, 5001
beqz t0, failed
nop
addu t0, s4, s7
sltiu t1, t0, 5001
beqz t1, failed
nop
addiu a3, s7, -1
addu a3, a3, s1
sw s1, 0xe50(s0)
sw a3, 0xe54(s0)
move a0, s0
sll t0, s4, 2
addu a1, s2, t0
move a2, s1
addiu t0, zero, -1
bne s5, s6, no_anchor
nop
lbu t0, 0x2916(s0)
lbu t1, 0x2917(s0)
sll t1, t1, 8
or t0, t0, t1
lbu t1, 0x2918(s0)
sll t1, t1, 16
or t0, t0, t1
lbu t1, 0x2919(s0)
sll t1, t1, 24
or t0, t0, t1
no_anchor:
sw t0, 0x18(sp)
addiu t0, zero, 1
sw t0, 0x10(sp)
jal {hex(GATE)}
sw t0, 0x14(sp)
bnez v0, failed
nop
addu s4, s4, s7
jal 0x231a4
nop
lw a0, 0x48(v0)
jal 0x14720
move a1, s5
move s5, v0
bne s5, s6, loop
nop
# Re-check cancellation after the final folder-iterator call.
jal 0x231a4
nop
lw t0, 0x18(v0)
bnez t0, failed
nop
lbu t0, 0x291e(s0)
addiu t1, zero, 1
bne t0, t1, failed
nop
sw s4, 0xe4c(s0)
sw s2, 0xe5c(s0)
b done
move v0, zero
failed:
sw zero, 0xe58(s0)
sw zero, 0xe4c(s0)
sw zero, 0xe5c(s0)
sw zero, 0xe50(s0)
sw zero, 0xe54(s0)
addiu v0, zero, -1
done:
{end(n,regs)}
''',n,regs

def wrapper():
    regs=['s0','s1'];n=0x30
    def flag(value):return ''.join(f'sb {value}, {hex(off)}(s0)\n' for off in (0x291e,0x291f,0x2920,0x2921,0x1ab4,0x1ab5,0x1ab6,0x1ab7))
    return f'''
{frame(n,regs)}
move s0, a0
move s1, zero
sltiu t0, a1, 2
beqz t0, off
nop
beqz a1, off
nop
addiu t0, zero, 1
sb t0, 0x291e(s0)
sb zero, 0x291f(s0)
sb zero, 0x2920(s0)
sb zero, 0x2921(s0)
jal {hex(BUILD)}
move a0, s0
move s1, v0
bnez v0, off
nop
addiu t0, zero, 1
sw t0, 0x2938(s0)
sb t0, 0x1ab4(s0)
sb zero, 0x1ab5(s0)
sb zero, 0x1ab6(s0)
sb zero, 0x1ab7(s0)
b publish
nop
off:
{flag('zero')}
sw zero, 0x2938(s0)
sw zero, 0xe58(s0)
sw zero, 0xe4c(s0)
sw zero, 0xe5c(s0)
sw zero, 0xe50(s0)
sw zero, 0xe54(s0)
publish:
# Existing shared-status writer, once after the outcome is known. No new lock.
jal 0x231a4
nop
lw a0, 0x40(v0)
beqz a0, done
nop
addiu a1, s0, 0x1ad8
move a2, zero
jal 0x24094
addiu a3, zero, 0xe56
done:
move v0, s1
{end(n,regs)}
''',n,regs

def ready():
    return '''
move v0, zero
lbu t0, 0x291e(a0)
addiu t1, zero, 1
bne t0, t1, done
nop
lbu t0, 0x291f(a0)
lbu t1, 0x2920(a0)
or t0, t0, t1
lbu t1, 0x2921(a0)
or t0, t0, t1
bnez t0, done
nop
lw t0, 0xe5c(a0)
beqz t0, done
nop
lw t0, 0xe4c(a0)
beqz t0, done
nop
sltiu t1, t0, 5001
beqz t1, done
nop
lw t1, 0xe58(a0)
sltu v0, t1, t0
done:
jr ra
nop
''',0,[]

def patch(raw):
    assert hashlib.sha256(raw).hexdigest()==BASE_SHA
    p=pefile.PE(data=raw);out=bytearray(raw);edits=[];newrel=[];newrows=[]
    def block(at,cap,code,why):
        new,r,rel=assemble(code,at,cap);off=p.get_offset_from_rva(at-BASE)
        edits.append(dict(va=hex(at),offset=hex(off),bytes=cap,before_hex=raw[off:off+cap].hex(),
                          after_hex=new.hex(),reason=why,assembly=r))
        out[off:off+cap]=new;newrel.extend(rel);return r
    for at,cap,(code,n,regs) in ((EXACT,0x200,exact()),(SEEK,0x200,seek()),(FIELD,0x400,field()),
        (GATE,0x180,gate()),(YIELD,0x80,yields()),(BUILD,0x600,builder()),(WRAP,0x180,wrapper()),(READY,0x180,ready())):
        off=p.get_offset_from_rva(at-BASE);assert not any(raw[off:off+cap]),hex(at)
        r=block(at,cap,code,'Bounded WMA/shuffle helper in unused existing code space')
        newrows.append((at,at+r['used_bytes'],0,0,at+(2+len(regs))*4 if n else at))
    block(0x18328,0x18f08-0x18328,reader(),'Bound WMA reads to the containing ASF header/child and require exact read/seek success')
    # Tail jumps enter routines whose unwind rows describe their own new frames.
    for old,target in ((0x19af8,BUILD),(0x1b5b0,WRAP)):
        r=block(old,8,f'la t9, {hex(target)}','Tail redirect to checked shuffle routine')
        # LA is eight bytes; use two original following instructions for JR.
        block(old+8,8,'jr t9\nnop','Tail redirect (no old frame is entered)')
    # Preserve the random-selection algorithm; check cancellation each iteration.
    block(0x19950,0x14,f'move a0, s2\naddu s5, s2, s7\njal {hex(YIELD)}\nsw s5, 0(s4)\nnop',
          'Batch fill-loop timed yields while preserving per-track cancellation')
    block(0x19a80,12,f'jal {hex(YIELD)}\nmove a0, s3\nnop','Batch selection-loop timed yields')
    for at,obj,reg in ((0x19598,'s0','t1'),(0x1cf60,'s0','t0'),(0x1d338,'s1','t1'),
                       (0x1d55c,'s1','t1'),(0x1d7b4,'s0','t0')):
        block(at,12,f'jal {hex(READY)}\nmove a0, {obj}\nmove {reg}, v0',
              'Track selectors only use complete shuffle lists with valid count/cursor')
    # A few direct callers also use the pool outside the full-list builder.
    word=(3<<26)|(0x198e4>>2);calls=[];s=p.sections[0];body=s.get_data()
    for i in range(0,len(body)-3,4):
        at=BASE+s.VirtualAddress+i
        if struct.unpack_from('<I',body,i)[0]==word and not any(int(e['va'],16)<=at<int(e['va'],16)+e['bytes'] for e in edits):
            calls.append(at);block(at,4,f'jal {hex(GATE)}','Check every remaining direct shuffle-pool caller')
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=p.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    for old in (0x19af8,0x1b5b0):
        idx=next(i for i,r in enumerate(rows) if r[0]==old)
        assert rows[idx][2:4]==(0,0)
        rows[idx]=(*rows[idx][:4],old)
    rows=sorted(rows+newrows);assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
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
        table.extend(struct.pack('<II',page,8+2*len(vals))+struct.pack('<'+str(len(vals))+'H',*vals))
    assert rd.VirtualAddress==DATA+0x3000-BASE and len(table)<=DATA_SIZE-0x3000
    cap=max(rd.Size,len(table));new=bytes(table)+bytes(cap-len(table));off=p.get_offset_from_rva(rd.VirtualAddress)
    edits.append(dict(va=hex(BASE+rd.VirtualAddress),offset=hex(off),bytes=cap,
                      before_hex=raw[off:off+cap].hex(),after_hex=new.hex(),reason='Combined MIPS relocations'))
    out[off:off+cap]=new;struct.pack_into('<I',out,rd.get_file_offset()+4,len(table))
    result=bytes(out)
    return result,dict(base_sha256=BASE_SHA,sha256=hashlib.sha256(result).hexdigest(),edits=edits,
                       added_pdata_rows=8,pool_guard_calls=calls,native_executed=False,installation_ready=False)
