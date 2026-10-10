"""Pinned cumulative artwork/playlist development. No native firmware execution."""
import hashlib
import struct
import pefile
from patch_usb_reliability import assemble,BASE,DATA,DATA_SIZE
from patch_updater_copy_safety import frame,end

BASE_SHA='9b2a87dbbef6e9e6d11fa66bd92a687331e7b5fd51104e5588dad157cf623518'
ART,PIXELS,LINE=0x3d800,0x3c800,0x3ea00
EOF_IAT,ERROR_IAT=DATA+0x20c,DATA+0x210


def stream_api(at):
    return f'la t8, {hex(at)}\nlw t9, 0(t8)\njalr t9\nnop'


def artwork():
    regs=['s0','s1','s2','s3','s4','s5'];n=0x40
    # Fifth argument is the existing source tag object's allocated image buffer.
    return f'''
{frame(n,regs)}
move s0, a0
move s1, a1
move s2, a2
lw s3, 0x50(sp)
move s4, zero
beqz s1, done
nop
beqz s3, done
nop
sltiu t0, s2, 6
bnez t0, done
nop
lbu s5, 0(s1)
sltiu t0, s5, 4
beqz t0, done
nop
addiu t0, zero, 2
beq a3, t0, pic
nop
# APIC: bounded MIME terminator, then type, then encoded description.
addiu t0, zero, 1
mime_scan:
sltu t1, t0, s2
beqz t1, done
nop
addu t1, s1, t0
lbu t1, 0(t1)
beqz t1, mime_end
nop
b mime_scan
addiu t0, t0, 1
mime_end:
sltiu t1, t0, 8
bnez t1, done
nop
# Lower-case image/ prefix (case-insensitive ASCII only).
{''.join(f'lbu t1, {i+1}(s1)\nori t1, t1, 32\naddiu t2, zero, {ord(c)}\nbne t1, t2, done\nnop\n' for i,c in enumerate('image/'))}
addiu a0, s1, 7
addiu a1, t0, -7
addiu t3, t0, 2
b format
nop
pic:
 lbu t0, 1(s1)
 addiu t1, zero, 45
 bne t0, t1, pic_format
 nop
 lbu t0, 2(s1)
 bne t0, t1, pic_format
 nop
 lbu t0, 3(s1)
 addiu t1, zero, 62
 beq t0, t1, done
 nop
pic_format:
addiu a0, s1, 1
addiu a1, zero, 3
addiu t3, zero, 5
format:
# Exact known MIME subtype / PIC identifiers. Unknown image types retain code 0;
# their byte signatures may still be accepted by a registered native decoder.
sltiu t0, a1, 3
bnez t0, description
nop
lbu t0, 0(a0)
lbu t1, 1(a0)
lbu t2, 2(a0)
ori t0, t0, 32
ori t1, t1, 32
ori t2, t2, 32
addiu t4, zero, 3
bne a1, t4, jpeg
nop
addiu t4, zero, 106
bne t0, t4, png
nop
addiu t4, zero, 112
bne t1, t4, unknown
nop
addiu t4, zero, 103
bne t2, t4, unknown
nop
b description
addiu s4, zero, 16
png:
addiu t4, zero, 112
bne t0, t4, bmp
nop
addiu t4, zero, 110
bne t1, t4, unknown
nop
addiu t4, zero, 103
bne t2, t4, unknown
nop
b description
addiu s4, zero, 23
bmp:
addiu t4, zero, 98
bne t0, t4, gif
nop
addiu t4, zero, 109
bne t1, t4, unknown
nop
addiu t4, zero, 112
bne t2, t4, unknown
nop
b description
addiu s4, zero, 21
gif:
addiu t4, zero, 103
bne t0, t4, unknown
nop
addiu t4, zero, 105
bne t1, t4, unknown
nop
addiu t4, zero, 102
bne t2, t4, unknown
nop
b description
addiu s4, zero, 22
jpeg:
addiu t4, zero, 4
bne a1, t4, unknown
nop
addiu t4, zero, 106
bne t0, t4, unknown
nop
addiu t4, zero, 112
bne t1, t4, unknown
nop
addiu t4, zero, 101
bne t2, t4, unknown
nop
lbu t0, 3(a0)
ori t0, t0, 32
addiu t4, zero, 103
bne t0, t4, unknown
nop
addiu s4, zero, 18
unknown:
description:
# type is byte preceding t3. Require a complete description terminator and data.
sltu t0, t3, s2
beqz t0, done
nop
addu t0, s1, t3
lbu t1, -1(t0)
sltiu t1, t1, 21
beqz t1, done
nop
addiu t0, zero, 1
beq s5, t0, wide_description
nop
addiu t0, zero, 2
beq s5, t0, wide_description
nop
byte_description:
sltu t0, t3, s2
beqz t0, done
nop
addu t0, s1, t3
lbu t0, 0(t0)
addiu t3, t3, 1
bnez t0, byte_description
nop
b image
nop
wide_description:
subu t0, s2, t3
sltiu t0, t0, 2
bnez t0, done
nop
addu t0, s1, t3
lbu t1, 0(t0)
lbu t2, 1(t0)
or t0, t1, t2
addiu t3, t3, 2
bnez t0, wide_description
nop
image:
subu s2, s2, t3
beqz s2, done
nop
lui t0, 0x80
sltu t0, t0, s2
bnez t0, done
nop
addu a1, s1, t3
move a0, s3
jal 0x25668
move a2, s2
sw s4, 0xc30(s0)
sw s2, 0xc34(s0)
lw t0, 0xe40(s0)
ori t0, t0, 8
sw t0, 0xe40(s0)
addiu v0, zero, 1
b finished
nop
done:
move v0, zero
finished:
{end(n,regs)}
''',n,regs


PIXEL_CODE='''
move v0, zero
beqz a0, done
nop
beqz a1, done
nop
beqz a2, done
nop
or t0, a1, a2
srl t0, t0, 31
bnez t0, done
nop
addu t6, a1, a1
addu t6, t6, a1
subu t6, zero, t6
andi t6, t6, 3
row:
move t5, a1
pixel:
lbu t0, 0(a0)
addiu t0, t0, -8
sltiu t0, t0, 8
beqz t0, next
nop
lbu t0, 1(a0)
sltiu t0, t0, 4
beqz t0, next
nop
lbu t0, 2(a0)
sltiu t0, t0, 8
beqz t0, next
nop
sb zero, 0(a0)
sb zero, 1(a0)
sb zero, 2(a0)
addiu v0, v0, 1
next:
addiu t5, t5, -1
bnez t5, pixel
addiu a0, a0, 3
addiu a2, a2, -1
bnez a2, row
addu a0, a0, t6
done:
jr ra
nop
'''


def lines():
    regs=['s0','s1','s2','s3','s4'];n=0x180
    return f'''
{frame(n,regs)}
move s0, a0
move s1, a1
move s2, a2
beqz s0, done
nop
beqz s1, done
nop
sltiu t0, s2, 2
bnez t0, done
nop
sltiu t0, s2, 261
beqz t0, done
nop
sb zero, 0(s1)
lw t0, 8(s0)
beqz t0, done
nop
lw s3, 4(s0)
again:
move a0, s1
move a1, s2
jal 0x258fc
move a2, s3
beqz v0, done
sb zero, 0x20(sp)
addu t0, s1, s2
sb zero, -1(t0)
move s4, zero
length:
addu t0, s1, s4
lbu t0, 0(t0)
beqz t0, measured
nop
b length
addiu s4, s4, 1
measured:
beqz s4, complete
nop
addu t0, s1, s4
lbu t0, -1(t0)
addiu t1, zero, 10
beq t0, t1, complete
nop
addiu t0, s2, -1
bne s4, t0, complete
nop
# Two-byte lookahead preserves a valid full buffer followed by EOF/LF/CRLF.
addiu a0, sp, 0x30
addiu a1, zero, 3
jal 0x258fc
move a2, s3
beqz v0, peek_end
nop
lbu t0, 0x30(sp)
addiu t1, zero, 10
beq t0, t1, complete
nop
addiu t1, zero, 13
bne t0, t1, peek_bad
nop
lbu t0, 0x31(sp)
beqz t0, complete
nop
addiu t1, zero, 10
beq t0, t1, complete
nop
peek_bad:
lbu t0, 0x31(sp)
addiu t1, zero, 10
beq t0, t1, again
nop
beqz t0, done
nop
drain:
addiu a0, sp, 0x30
addiu a1, zero, 260
jal 0x258fc
move a2, s3
beqz v0, done
nop
move t0, zero
drain_length:
addiu t1, sp, 0x30
addu t1, t1, t0
lbu t1, 0(t1)
beqz t1, drain_end
nop
addiu t2, zero, 10
beq t1, t2, again
nop
b drain_length
addiu t0, t0, 1
drain_end:
sltiu t1, t0, 259
bnez t1, done
nop
b drain
nop
peek_end:
move a0, s3
{stream_api(ERROR_IAT)}
bnez v0, done
nop
move a0, s3
{stream_api(EOF_IAT)}
beqz v0, done
nop
complete:
# Strip at most two terminal CR/LF bytes, preserving the original line policy.
addiu t4, zero, 2
strip:
beqz s4, bom
nop
addu t0, s1, s4
lbu t1, -1(t0)
addiu t2, zero, 10
beq t1, t2, stripped
nop
addiu t2, zero, 13
bne t1, t2, bom
nop
stripped:
sb zero, -1(t0)
addiu s4, s4, -1
addiu t4, t4, -1
bnez t4, strip
nop
bom:
sltiu t0, s4, 3
bnez t0, success
nop
lbu t0, 0(s1)
addiu t1, zero, 239
bne t0, t1, success
nop
lbu t0, 1(s1)
addiu t1, zero, 187
bne t0, t1, success
nop
lbu t0, 2(s1)
addiu t1, zero, 191
bne t0, t1, success
nop
move t0, zero
addiu s4, s4, -3
bom_copy:
addu t1, s1, t0
lbu t2, 3(t1)
sb t2, 0(t1)
bne t0, s4, bom_copy
addiu t0, t0, 1
success:
b finished
addiu v0, zero, 1
done:
beqz s1, cleared
nop
sltiu t0, s2, 2
bnez t0, cleared
nop
sltiu t0, s2, 261
beqz t0, cleared
nop
sb zero, 0(s1)
cleared:
move v0, zero
finished:
{end(n,regs)}
''',n,regs


def patch(raw):
    assert hashlib.sha256(raw).hexdigest()==BASE_SHA
    p=pefile.PE(data=raw);out=bytearray(raw);edits=[];newrel=[];newrows=[]
    def block(at,cap,code,why):
        new,r,rel=assemble(code,at,cap);off=p.get_offset_from_rva(at-BASE)
        edits.append(dict(va=hex(at),offset=hex(off),bytes=cap,before_hex=raw[off:off+cap].hex(),
                          after_hex=new.hex(),reason=why,assembly=r))
        out[off:off+cap]=new;newrel.extend(rel);return r
    for address,cap,(code,stack,regs) in ((ART,0x800,artwork()),(PIXELS,0x600,(PIXEL_CODE,0,[])),(LINE,0x800,lines())):
        off=p.get_offset_from_rva(address-BASE);assert not any(raw[off:off+cap])
        r=block(address,cap,code,'Bounded artwork/playlist helper in existing unused code space')
        newrows.append((address,address+r['used_bytes'],0,0,address+(2+len(regs))*4 if stack else address))
    block(0x17ef4,0x1803c-0x17ef4,
          f'move a0, s6\nmove a1, s5\nmove a2, s4\nlw t0, 0x24(fp)\nlw t0, 0xe44(t0)\n'
          f'sw t0, 0x10(sp)\njal {hex(ART)}\nlw a3, 0x1c(fp)\nb 0x18218\nnop',
          'Replace unbounded MIME/description copy with frame-contained APIC/PIC parsing')
    block(0x1a38c,0x1a3a8-0x1a38c,
          'lw a2, 0xc38(s2)\nbeqz a2, 0x1a55c\nnop\nlui t0, 0x80\n'
          'sltu t0, t0, a2\nbnez t0, 0x1a55c\nnop',
          'Remove 3,652-byte metadata copy used only for cover length; validate actual size')
    block(0x1a3bc,4,'nop','Keep validated actual cover byte count as decoder stream length')
    block(0x1a4ac,0x1a540-0x1a4ac,
          f'lw a0, 0x20(sp)\nlw a1, 0x2c(sp)\njal {hex(PIXELS)}\nlw a2, 0x30(sp)\nb 0x1a540\nnop',
          'Correct DIB row padding and inline three-byte pixel stores')
    calls=[];s=p.sections[0];body=s.get_data();word=(3<<26)|(0x15e4c>>2)
    for i in range(0,len(body)-3,4):
        if struct.unpack_from('<I',body,i)[0]==word:calls.append(BASE+s.VirtualAddress+i)
    assert calls==[0x15c68,0x15dc0,0x16658,0x16820,0x1698c,0x16c38]
    for at in calls:block(at,4,f'jal {hex(LINE)}','Read whole bounded playlist lines; strip UTF8 BOM')
    for at in (DATA+0x200,DATA+0x240):
        off=p.get_offset_from_rva(at-BASE)
        assert struct.unpack_from('<4I',raw,off)==(0x800000af,0x800000a3,0x800000a5,0)
        new=struct.pack('<6I',0x800000af,0x800000a3,0x800000a5,0x80000465,0x80000466,0)
        edits.append(dict(va=hex(at),offset=hex(off),bytes=len(new),before_hex=raw[off:off+len(new)].hex(),
                          after_hex=new.hex(),reason='Verified COREDLL feof/ferror imports distinguish EOF from read failure'))
        out[off:off+len(new)]=new
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=p.get_data(d.VirtualAddress,d.Size)
    oldrows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    rows=sorted(oldrows+newrows);assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    combined=b''.join(struct.pack('<5I',*r) for r in rows)
    assert d.VirtualAddress==DATA+0x1000-BASE and len(combined)<0x2000
    off=p.get_offset_from_rva(d.VirtualAddress)
    edits.append(dict(va=hex(BASE+d.VirtualAddress),offset=hex(off),bytes=len(combined),
                      before_hex=raw[off:off+len(combined)].hex(),after_hex=combined.hex(),reason='Combined exception rows'))
    out[off:off+len(combined)]=combined
    struct.pack_into('<I',out,d.get_file_offset()+4,len(combined))
    for i,row in enumerate(rows):
        for j,v in enumerate(row):
            if v:newrel.append((d.VirtualAddress+i*20+j*4,3,None))
    # Preserve HIGHADJ companion words; rebuild relocations after code/pdata edits.
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
                       added_pdata_rows=3,playlist_calls=calls,native_executed=False,installation_ready=False)
