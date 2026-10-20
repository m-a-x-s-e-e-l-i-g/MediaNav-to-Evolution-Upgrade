"""Cumulative development: encoded tag text and recoverable resume storage.

Never execute firmware natively. Added MIPS code/imports/pdata/relocations need CE tests.
"""
import hashlib
import struct
import pefile
from patch_usb_input_safety import encode
from patch_updater_copy_safety import frame, end

BASE_SHA='4e89e6dc0cf0130ae1320a19f9c06937f4a256896393ac8667ca1aa477a5ec5a'
BASE=0x10000
TEXT,TEXT_SIZE,DATA,DATA_SIZE=0x3c000,0x5000,0x41000,0x9000
DECODE,LEGACY,SAVE,READ,LOAD=TEXT,TEXT+0x1000,TEXT+0x1100,TEXT+0x2800,TEXT+0x3800
CACHE_HELP=TEXT+0x2000
GENRE_HELP=LEGACY+0x40
EXTRA_IAT=DATA+0x200
CODEPAGES=[1252]*32
for i in (0,31):CODEPAGES[i]=1256
for i in (7,20,22,23):CODEPAGES[i]=1251
for i in (9,11,15,16,17,18,19):CODEPAGES[i]=1250
for i,cp in ((10,1254),(13,932),(14,1253),(21,1255)):CODEPAGES[i]=cp


def api(name,delay='nop'):
    at={'open':0x2f034,'read':0x2f058,'write':0x2f098,'close':0x2f038,
        'size':0x2f064,'attrs':0x2f05c,'mutex':0x2f0cc,'wait':0x2f048,
        'release':0x2f0c4,'flush':EXTRA_IAT,'move':EXTRA_IAT+4,'delete':EXTRA_IAT+8,
        'convert':0x2f030,'lead':0x2f108,'last':0x2f020}[name]
    return f'la t8, {hex(at)}\nlw t9, 0(t8)\njalr t9\n{delay}'


def decoder():
    regs=['s0','s1','s2','s3','s4','s5','s6','s7']
    code=f'''
{frame(0x60,regs)}
move s0, a3
move s1, a2
move s2, a1
move s4, a0
move s6, zero
move s7, zero
beqz s1, done
nop
move a0, s1
move a1, zero
jal 0x253dc
addiu a2, zero, 400
beqz s2, done
nop
beqz s0, done
nop
sltiu t0, s0, 260
beqz t0, done
nop
sltiu t0, s4, 256
beqz t0, generic
nop
sltiu t0, s4, 4
beqz t0, bad_encoding
nop
sltiu t0, s0, 258
bnez t0, bounded
nop
addiu s0, zero, 257
addiu s7, zero, 1
bounded:
sw s0, 0x20(sp)
move s3, s4
beqz s3, latin
nop
addiu t0, zero, 2
beq s3, t0, utf16
addiu t6, zero, 1
addiu t0, zero, 3
beq s3, t0, utf8bom
nop
b bom16
nop
generic:
addiu s3, zero, -1
sw s0, 0x20(sp)
sltiu t0, s0, 2
bnez t0, generic_locale
nop
lbu t0, 0(s2)
lbu t1, 1(s2)
sll t1, t1, 8
or t0, t0, t1
ori t1, zero, 0xfeff
beq t0, t1, bom16
nop
ori t1, zero, 0xfffe
beq t0, t1, bom16
nop
b utf8bom
nop
bom16:
sltiu t0, s0, 2
bnez t0, finish
nop
lbu t0, 0(s2)
lbu t1, 1(s2)
sll t1, t1, 8
or t0, t0, t1
ori t1, zero, 0xfeff
beq t0, t1, little
move t6, zero
ori t1, zero, 0xfffe
bne t0, t1, finish
addiu t6, zero, 1
little:
addiu s2, s2, 2
addiu s0, s0, -2
b utf16
nop
latin:
beqz s0, finish
nop
sltiu t0, s6, 199
beqz t0, finish
nop
lbu t0, 0(s2)
beqz t0, finish
nop
sll t1, s6, 1
addu t1, t1, s1
sh t0, 0(t1)
addiu s6, s6, 1
addiu s2, s2, 1
b latin
addiu s0, s0, -1
utf16:
move t7, zero
u16loop:
sltiu t0, s0, 2
bnez t0, u16end
nop
sltiu t0, s6, 199
beqz t0, u16end
nop
lbu t0, 0(s2)
lbu t1, 1(s2)
beqz t6, u16le
nop
sll t0, t0, 8
b u16unit
or t0, t0, t1
u16le:
sll t1, t1, 8
or t0, t0, t1
u16unit:
beqz t0, u16end
nop
ori t2, zero, 0xdc00
subu t3, t0, t2
sltiu t3, t3, 0x400
beqz t7, u16first
nop
beqz t3, invalid
move t7, zero
b u16write
nop
u16first:
bnez t3, invalid
nop
ori t2, zero, 0xd800
subu t2, t0, t2
sltiu t7, t2, 0x400
u16write:
sll t1, s6, 1
addu t1, t1, s1
sh t0, 0(t1)
addiu s6, s6, 1
addiu s2, s2, 2
b u16loop
addiu s0, s0, -2
u16end:
beqz t7, finish
nop
b finish
addiu s6, s6, -1
utf8bom:
sltiu t0, s0, 3
bnez t0, encoding_route
nop
lbu t0, 0(s2)
addiu t0, t0, -0xef
bnez t0, encoding_route
nop
lbu t0, 1(s2)
addiu t0, t0, -0xbb
bnez t0, encoding_route
nop
lbu t0, 2(s2)
addiu t0, t0, -0xbf
bnez t0, encoding_route
nop
addiu s2, s2, 3
addiu s0, s0, -3
# A full UTF8 BOM is authoritative even for a locale-dependent legacy tag.
addiu s3, zero, 3
encoding_route:
addiu t0, zero, -1
beq s3, t0, generic_locale
nop
b try_utf8
nop
generic_locale:
jal 0x24ca4
move a0, s4
lw t0, 4(s4)
sw t0, 0x24(sp)
addiu t1, zero, 2
beq t0, t1, korean_scan
nop
addiu t1, zero, 28
bne t0, t1, try_utf8
nop
korean_scan:
move s6, zero
leadloop:
sltu t0, s6, s0
beqz t0, locale_fallback
nop
addu t0, s2, s6
lbu a1, 0(t0)
addiu a0, zero, 949
{api('lead')}
bnez v0, try_korean
nop
b leadloop
addiu s6, s6, 1
try_korean:
b query
addiu s5, zero, 949
try_utf8:
ori s5, zero, 65001
query:
beqz s0, finish
move s6, zero
move a0, s5
addiu a1, zero, 8
move a2, s2
move a3, s0
sw zero, 0x10(sp)
sw zero, 0x14(sp)
{api('convert')}
beqz v0, query_failed
nop
sltiu t0, v0, 200
bnez t0, convert
move s6, v0
addiu s7, zero, 1
trim:
addiu s0, s0, -1
b query
nop
query_failed:
bnez s7, trim
nop
addiu t0, zero, 949
beq s5, t0, try_utf8
nop
addiu t0, zero, -1
bne s3, t0, invalid
nop
locale_fallback:
lw t0, 0x24(sp)
sltiu t1, t0, 32
beqz t1, default_cp
nop
sll t0, t0, 2
la t1, {hex(DATA+0x300)}
addu t0, t0, t1
lw s5, 0(t0)
b query_locale
nop
default_cp:
addiu s5, zero, 1252
query_locale:
addiu s3, zero, -2
b query
nop
convert:
move a0, s5
addiu a1, zero, 8
move a2, s2
move a3, s0
sw s1, 0x10(sp)
sw s6, 0x14(sp)
{api('convert')}
beqz v0, invalid
nop
b finish
move s6, v0
invalid:
move s6, zero
b finish
nop
bad_encoding:
move s4, zero
sw zero, 0x20(sp)
sw s2, 0x28(sp)
finish:
sll t0, s6, 1
addu t0, t0, s1
sh zero, 0(t0)
sltiu t0, s4, 4
beqz t0, done
nop
# Raw source is one of the four proven mutable 260-byte tag slots.
# s2 may have advanced: restore source and actual cached length saved below.
lw t1, 0x28(sp)
beqz t1, done
nop
lw t2, 0x20(sp)
sb t2, 257(t1)
srl t2, t2, 8
sb t2, 258(t1)
ori t2, s4, 0x80
sb t2, 259(t1)
done:
move v0, s1
{end(0x60,regs)}
'''
    # Preserve the raw buffer before any BOM stripping/byte loop. For UTF8,
    # update cached byte length after trimming relative to the original prefix.
    code=code.replace('sw s0, 0x20(sp)\nmove s3, s4',
                      'sw s0, 0x20(sp)\nsw s2, 0x28(sp)\nmove s3, s4')
    code=code.replace('addiu s0, s0, -1\nb query',
                      'addiu s0, s0, -1\nlw t0, 0x20(sp)\naddiu t0, t0, -1\nsw t0, 0x20(sp)\nb query')
    return code,0x60,regs


CACHE=f'''
jal 0x209e0
addiu a0, fp, 0x10
move s0, s1
addiu s4, s1, 0x820
move s2, zero
addiu s3, zero, 4
cache_loop:
lw t0, 0xe40(s1)
and t0, t0, s3
beqz t0, cache_next
nop
move a0, s0
move a1, zero
jal 0x253dc
addiu a2, zero, 0x208
addiu a0, fp, 0x10
move a1, s4
move a2, s0
addiu a3, zero, 259
lbu t0, 259(s4)
addiu t1, t0, -0x80
sltiu t2, t1, 5
beqz t2, cache_decode
nop
lbu a3, 257(s4)
lbu t0, 258(s4)
sll t0, t0, 8
or a3, a3, t0
addiu t0, zero, 4
beq t1, t0, cache_decode
nop
move a0, t1
cache_decode:
jal {hex(DECODE)}
nop
cache_next:
addiu s2, s2, 1
addiu s0, s0, 0x208
addiu s4, s4, 0x104
addiu t0, zero, 3
beq s2, t0, genre
srl s3, s3, 1
sltiu t0, s2, 4
bnez t0, cache_loop
nop
b cache_done
nop
genre:
b cache_loop
addiu s3, zero, 16
cache_done:
jal 0x209d0
addiu a0, fp, 0x10
b 0x1941c
nop
'''


def assemble(code,start,capacity):
    lines=[];relocs=[];pc=start
    for line in code.splitlines():
        line=line.split('#',1)[0].strip()
        if not line:continue
        if line.endswith(':'):lines.append(line);continue
        if line.startswith('la '):
            reg,value=line[3:].split(',');value=int(value.strip(),0);reg=reg.strip()
            high=((value+0x8000)>>16)&65535;low=value&65535
            lines += [f'lui {reg}, {high}',f'addiu {reg}, {reg}, {low if low<32768 else low-65536}']
            relocs += [(pc-BASE,4,low),(pc+4-BASE,2,None)];pc+=8
        else:
            lines.append(line)
            if line.startswith('jal '):relocs.append((pc-BASE,5,None))
            pc+=4
    raw,recipe=encode('\n'.join(lines),start,start+capacity)
    recipe['source_assembly']=code
    return raw,recipe,relocs


def filenames(temp,backup):
    """s1 canonical path; two local 260-unit buffers. Nonempty, bounded source."""
    return f'''
beqz s1, cleanup
nop
move t0, zero
move t1, s1
names_loop:
lhu t4, 0(t1)
beqz t4, names_end
nop
sltiu t5, t0, 254
beqz t5, cleanup
nop
sll t5, t0, 1
addiu t2, sp, {temp}
addu t2, t2, t5
addiu t3, sp, {backup}
addu t3, t3, t5
sh t4, 0(t2)
sh t4, 0(t3)
addiu t1, t1, 2
b names_loop
addiu t0, t0, 1
names_end:
beqz t0, cleanup
nop
sll t5, t0, 1
addiu t2, sp, {temp}
addu t2, t2, t5
addiu t3, sp, {backup}
addu t3, t3, t5
addiu t4, zero, 46
sh t4, 0(t2)
sh t4, 0(t3)
addiu t4, zero, 110
sh t4, 2(t2)
addiu t4, zero, 101
sh t4, 4(t2)
addiu t4, zero, 119
sh t4, 6(t2)
sh zero, 8(t2)
addiu t4, zero, 98
sh t4, 2(t3)
addiu t4, zero, 97
sh t4, 4(t3)
addiu t4, zero, 107
sh t4, 6(t3)
sh zero, 8(t3)
'''


def lock():
    return f'''
move a0, zero
move a1, zero
la a2, {hex(DATA+0x400)}
{api('mutex')}
beqz v0, cleanup
move s6, v0
move a0, s6
move a1, zero
{api('wait')}
beqz v0, acquired
nop
addiu t0, zero, 128
bne v0, t0, cleanup
nop
acquired:
addiu s7, zero, 1
'''


def unlock():
    return f'''
cleanup:
beqz s7, close_mutex
nop
move a0, s6
{api('release')}
bnez v0, close_mutex
nop
move s5, zero
close_mutex:
beqz s6, done
nop
move a0, s6
{api('close')}
bnez v0, done
nop
move s5, zero
done:
move v0, s5
'''


def storage():
    regs=['s0','s1','s2','s3','s4','s5','s6','s7']
    n=0x1e80;tmp,bak=0x1940,0x1b48
    save=f'''
{frame(n,regs)}
move s0, a0
move s1, a1
move s5, zero
move s6, zero
move s7, zero
{filenames(tmp,bak)}
{lock()}
jal 0x231a4
nop
addiu t0, zero, 1
sw t0, 0x1c(v0)
addiu s2, sp, 0x40
addiu s3, sp, 0xcc0
move a0, s2
addiu a1, s0, 0xe64
jal 0x25668
addiu a2, zero, 3180
addiu t0, zero, 1
move t2, zero
checksum:
addu t1, s2, t0
lbu t1, 0(t1)
addu t2, t2, t1
addiu t0, t0, 1
sltiu t1, t0, 3180
bnez t1, checksum
andi t2, t2, 255
sb t2, 0(s2)
move a0, zero
move a1, s2
jal 0x1ab50
addiu a2, zero, 3180
beqz v0, cleanup
nop
addiu a0, sp, {tmp}
lui a1, 0x4000
move a2, zero
move a3, zero
addiu t0, zero, 2
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{api('open')}
move s4, v0
addiu t0, zero, -1
beq s4, t0, cleanup
nop
sw zero, 0x24(sp)
move a0, s4
move a1, s2
addiu a2, zero, 3180
addiu a3, sp, 0x24
sw zero, 0x10(sp)
{api('write')}
beqz v0, close_write
nop
lw t0, 0x24(sp)
addiu t1, zero, 3180
bne t0, t1, close_write
nop
move a0, s4
{api('flush')}
sltu s5, zero, v0
close_write:
move a0, s4
{api('close')}
beqz v0, write_bad
nop
beqz s5, cleanup
nop
move s5, zero
addiu a0, sp, {tmp}
jal {hex(READ)}
move a1, s3
beqz v0, cleanup
nop
move t0, zero
compare:
addu t1, s2, t0
addu t2, s3, t0
lbu t1, 0(t1)
lbu t2, 0(t2)
bne t1, t2, cleanup
nop
addiu t0, t0, 1
sltiu t1, t0, 3180
bnez t1, compare
nop
move a0, s1
jal {hex(READ)}
move a1, s3
bnez v0, rotate
nop
addiu t0, zero, 1
beq v1, t0, publish
nop
addiu t0, zero, 2
bne v1, t0, cleanup
nop
addiu a0, sp, {bak}
jal {hex(READ)}
move a1, s3
beqz v0, cleanup
nop
move a0, s1
{api('delete')}
beqz v0, cleanup
nop
b publish
nop
rotate:
addiu a0, sp, {bak}
{api('delete')}
bnez v0, rotate_move
nop
{api('last')}
addiu t0, zero, 2
beq v0, t0, rotate_move
nop
addiu t0, zero, 3
bne v0, t0, cleanup
nop
rotate_move:
move a0, s1
addiu a1, sp, {bak}
{api('move')}
beqz v0, cleanup
nop
publish:
addiu a0, sp, {tmp}
move a1, s1
{api('move')}
b cleanup
sltu s5, zero, v0
write_bad:
move s5, zero
{unlock()}
{end(n,regs)}
'''
    # Never publish a partial/invalid read to the destination. v1: missing=1,
    # malformed=2, API/close failure=3. Snapshot body uses original checksum.
    rr=['s0','s1','s2','s3','s4'];rn=0xce0
    read=f'''
{frame(rn,rr)}
move s0, a0
move s1, a1
move s3, zero
addiu s4, zero, 3
move a0, s0
lui a1, 0x8000
addiu a2, zero, 1
move a3, zero
addiu t0, zero, 3
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{api('open')}
move s2, v0
addiu t0, zero, -1
bne s2, t0, size
nop
{api('last')}
addiu t0, zero, 2
beq v0, t0, missing
nop
addiu t0, zero, 3
bne v0, t0, done
nop
missing:
b done
addiu s4, zero, 1
size:
sw zero, 0x28(sp)
move a0, s2
addiu a1, sp, 0x28
{api('size')}
addiu t0, zero, -1
beq v0, t0, close
nop
addiu s4, zero, 2
lw t0, 0x28(sp)
bnez t0, close
nop
addiu t0, zero, 3180
bne v0, t0, close
nop
addiu s4, zero, 3
sw zero, 0x24(sp)
sw zero, 0x10(sp)
move a0, s2
addiu a1, sp, 0x40
addiu a2, zero, 3180
addiu a3, sp, 0x24
{api('read')}
beqz v0, close
nop
lw t0, 0x24(sp)
addiu t1, zero, 3180
bne t0, t1, close
nop
addiu s4, zero, 2
move a0, zero
addiu a1, sp, 0x40
jal 0x1ab50
addiu a2, zero, 3180
sltu s3, zero, v0
close:
move a0, s2
{api('close')}
bnez v0, closed
nop
move s3, zero
addiu s4, zero, 3
closed:
beqz s3, done
nop
move a0, s1
addiu a1, sp, 0x40
jal 0x25668
addiu a2, zero, 3180
move s4, zero
done:
move v0, s3
move v1, s4
{end(rn,rr)}
'''
    # Keep native hidden-file/folder validation and six-slot termination in the
    # previous fixed loader. The verified read and native load share this lock.
    ln=0x500
    load=f'''
{frame(ln,regs)}
move s0, a0
move s1, a1
move s5, zero
move s6, zero
move s7, zero
addiu s2, s0, 0xe64
move a0, s2
move a1, zero
jal 0x253dc
addiu a2, zero, 3180
{filenames(0x40,0x248)}
{lock()}
move a0, s1
jal {hex(READ)}
move a1, s2
beqz v0, backup
nop
move a0, s0
jal 0x1be50
move a1, s1
bnez v0, success
nop
backup:
addiu a0, sp, 0x248
jal {hex(READ)}
move a1, s2
beqz v0, failed
nop
move a0, s0
jal 0x1be50
addiu a1, sp, 0x248
beqz v0, failed
nop
success:
b cleanup
addiu s5, zero, 1
failed:
move a0, s2
move a1, zero
jal 0x253dc
addiu a2, zero, 3180
{unlock()}
beqz s5, clear_failure
nop
b load_done
nop
clear_failure:
move a0, s2
move a1, zero
jal 0x253dc
addiu a2, zero, 3180
load_done:
move v0, s5
{end(ln,regs)}
'''
    return [(SAVE,CACHE_HELP-SAVE,save,n,regs),(READ,LOAD-READ,read,rn,rr),
            (LOAD,TEXT+TEXT_SIZE-LOAD,load,ln,regs)]


def patch(raw):
    assert hashlib.sha256(raw).hexdigest()==BASE_SHA
    pe=pefile.PE(data=raw);out=bytearray(raw);text=bytearray(TEXT_SIZE);dat=bytearray(DATA_SIZE)
    assert pe.FILE_HEADER.Machine==0x166 and pe.OPTIONAL_HEADER.ImageBase==BASE
    assert pe.FILE_HEADER.NumberOfSections==5
    recipes=[];edits=[];newrel=[];newpdata=[]
    def routine(at,capacity,code,stack,regs):
        new,r,rel=assemble(code,at,capacity)
        text[at-TEXT:at-TEXT+capacity]=new;recipes.append(r);newrel.extend(rel)
        newpdata.append((at,at+r['used_bytes'],0,0,at+(2+len(regs))*4 if stack else at))
    def block(at,endva,code,reason):
        new,r,rel=assemble(code,at,endva-at);offset=pe.get_offset_from_rva(at-BASE)
        edits.append(dict(va=hex(at),offset=hex(offset),bytes=len(new),before_hex=raw[offset:offset+len(new)].hex(),
                          after_hex=new.hex(),reason=reason,assembly=r))
        out[offset:offset+len(new)]=new;newrel.extend(rel)
    code,stack,regs=decoder();routine(DECODE,0x1000,code,stack,regs)
    # A leaf tail transfer preserves the caller's RA; J carries MIPS jump relocation.
    legacy,r,rel=assemble('sb a3, 257(a1)\nsb zero, 258(a1)\naddiu t0, zero, 0x84\nsb t0, 259(a1)\nnop',LEGACY,0x100)
    legacy=bytearray(legacy);struct.pack_into('<I',legacy,16,(2<<26)|(DECODE>>2))
    text[LEGACY-TEXT:LEGACY-TEXT+0x100]=legacy
    recipes.append(dict(start=hex(LEGACY),end=hex(LEGACY+0x100),used_bytes=24,
                        source_assembly='cache ID3v1 byte length / marker 0x84; j DECODE; nop'))
    newrel.append((LEGACY+16-BASE,5,None));newpdata.append((LEGACY,LEGACY+24,0,0,LEGACY))
    routine(GENRE_HELP,0x40,'sb zero, 0xb2c(a0)\nsb zero, 0xc2f(a0)\nlw t0, 0xe40(a0)\n'
            'ori t0, t0, 16\njr ra\nsw t0, 0xe40(a0)',0,[])
    block(0x17734,0x17740,f'jal {hex(GENRE_HELP)}\nmove a0, s2\nnop',
          'Clear obsolete raw genre provenance when ID3v1 selects a Unicode table genre')
    # All direct calls to the shared decoder are inventoried, not guessed.
    oldword=(3<<26)|(0x24e04>>2);calls=[]
    section=pe.sections[0];original_text=section.get_data()
    for i in range(0,len(original_text)-3,4):
        if struct.unpack_from('<I',original_text,i)[0]==oldword:calls.append(BASE+section.VirtualAddress+i)
    expected=[0x175c8,0x17634,0x176a4,0x1807c,0x180e8,0x18170,0x181dc,
              0x19364,0x1939c,0x193d0,0x19408]
    assert calls==expected,calls
    for at in calls[:7]:
        destination=LEGACY if at in (0x175c8,0x17634,0x176a4) else DECODE
        block(at,at+4,f'jal {hex(destination)}','Use bounded decoder, with declared encoding for ID3v2')
    for at in (0x18080,0x180ec,0x18174,0x181e0):
        block(at,at+4,'lbu a0, 0(s5)','Respect the explicit ID3 frame encoding byte')
    block(0x1bf48,0x1bf4c,'sltu s0, zero, v0','Normalize nonzero ReadFile BOOL in retained native loader')
    block(0x1bf4c,0x1bf64,'beqz s0, 0x1c100\nnop\nbeqz v0, 0x1c130\nlw t0, 0x20(sp)\n'
          'bne t0, s5, 0x1c0dc\naddiu a2, zero, 3180',
          'Require both read and close success in retained native loader')
    cr=['s0','s1','s2','s3','s4','fp']
    cache=CACHE.replace('b 0x1941c\nnop','')
    # A v1 genre comes from the native Unicode lookup table, with no raw tag.
    cache=cache.replace('move a0, s0\nmove a1, zero',
                        'lbu t0, 0(s4)\nlbu t1, 259(s4)\n' 
                        'or t0, t0, t1\nbeqz t0, cache_next\nnop\n'
                        'move a0, s0\nmove a1, zero')
    routine(CACHE_HELP,READ-CACHE_HELP,frame(0x60,cr)+'\nmove fp, sp\nmove s1, a0\n'+cache+'\n'+end(0x60,cr),0x60,cr)
    block(0x19328,0x1941c,f'jal {hex(CACHE_HELP)}\nmove a0, s1\nb 0x1941c\nnop',
          'Preserve encoding and exact raw byte length during cached tag reconversion')
    # The storage routines are added below in the same cumulative construction.
    storage_routines=storage()
    for args in storage_routines:routine(*args)
    targets={0x1be50:(LOAD,[0x1ea58,0x1eb30,0x1fed0,0x20118]),
             0x1c17c:(SAVE,[0x1c9c8,0x1ea80,0x20c3c,0x224b4]),
             0x1c2e8:(SAVE,[0x226b8])}
    for old,(destination,expected_sites) in targets.items():
        sites=[BASE+section.VirtualAddress+i for i in range(0,len(original_text)-3,4)
               if struct.unpack_from('<I',original_text,i)[0]==(3<<26)|(old>>2)]
        assert sites==expected_sites,(hex(old),sites)
        for at in sites:block(at,at+4,f'jal {hex(destination)}','Verified temp/backup resume storage')
    mutex=("MediaNavMAX_USBResume\0").encode('utf-16-le')
    dat[0x400:0x400+len(mutex)]=mutex
    struct.pack_into('<32I',dat,0x300,*CODEPAGES)
    # Add a second COREDLL descriptor for the three verified ROM ordinals.
    descriptors=bytearray()
    for desc in pe.DIRECTORY_ENTRY_IMPORT:descriptors.extend(desc.struct.__pack__())
    descriptors.extend(struct.pack('<5I',DATA+0x240-BASE,0,0,DATA+0x180-BASE,EXTRA_IAT-BASE))
    descriptors.extend(bytes(20));dat[0:len(descriptors)]=descriptors
    dat[0x180:0x18c]=b'COREDLL.dll\0'
    for off in (0x200,0x240):struct.pack_into('<4I',dat,off,0x800000af,0x800000a3,0x800000a5,0)
    imp=pe.OPTIONAL_HEADER.DATA_DIRECTORY[1]
    struct.pack_into('<II',out,imp.get_file_offset(),DATA-BASE,len(descriptors))
    # Copy ordered exception rows; absolute VA fields receive relocation entries.
    d=pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    old=pe.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',old,i) for i in range(0,len(old),20)]+newpdata
    rows.sort();assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    combined=b''.join(struct.pack('<5I',*r) for r in rows);dat[0x1000:0x1000+len(combined)]=combined
    for i,row in enumerate(rows):
        for j,v in enumerate(row):
            if v:newrel.append((DATA+0x1000+i*20+j*4-BASE,3,None))
    struct.pack_into('<II',out,d.get_file_offset(),DATA+0x1000-BASE,len(combined))
    # Keep old relocations outside replaced ranges; parse raw HIGHADJ pairs.
    rd=pe.OPTIONAL_HEADER.DATA_DIRECTORY[5];oldrel=pe.get_data(rd.VirtualAddress,rd.Size)
    rel=[];pos=0;spans=[(int(e['va'],16)-BASE,int(e['va'],16)-BASE+e['bytes']) for e in edits]
    while pos<len(oldrel):
        page,n=struct.unpack_from('<II',oldrel,pos);vals=struct.unpack_from('<'+str((n-8)//2)+'H',oldrel,pos+8);i=0
        while i<len(vals):
            v=vals[i];kind=v>>12;at=page+(v&4095);i+=1;extra=None
            if kind==4:extra=vals[i];i+=1
            if kind and not any(a<=at<b for a,b in spans):rel.append((at,kind,extra))
        pos+=n
    rel+=newrel;rel.sort();assert len({a for a,_,_ in rel})==len(rel)
    pages={}
    for at,kind,extra in rel:
        page=at&~4095;pages.setdefault(page,[]).append((kind<<12)|(at-page))
        if kind==4:pages[page].append(extra)
    rebuilt=bytearray()
    for page,vals in sorted(pages.items()):
        if len(vals)%2:vals.append(0)
        rebuilt.extend(struct.pack('<II',page,8+2*len(vals))+struct.pack('<'+str(len(vals))+'H',*vals))
    assert 0x3000+len(rebuilt)<=DATA_SIZE
    dat[0x3000:0x3000+len(rebuilt)]=rebuilt
    struct.pack_into('<II',out,rd.get_file_offset(),DATA+0x3000-BASE,len(rebuilt))
    # Two section headers fit within unchanged SizeOfHeaders.
    header=pe.sections[-1].get_file_offset()+40;assert header+80<=pe.OPTIONAL_HEADER.SizeOfHeaders
    assert not any(raw[header:header+80])
    alignment=pe.OPTIONAL_HEADER.FileAlignment;offset=(len(out)+alignment-1)//alignment*alignment
    out.extend(bytes(offset-len(out)))
    for i,(name,at,contents,flags) in enumerate(((b'.maxusb',TEXT,text,0x60000020),(b'.maxud',DATA,dat,0xc0000040))):
        struct.pack_into('<8s8I',out,header+i*40,name,len(contents),at-BASE,len(contents),offset,0,0,0,flags)
        out.extend(contents);offset+=len(contents)
    struct.pack_into('<H',out,pe.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),7)
    for key,value in (('SizeOfImage',DATA+DATA_SIZE-BASE),('SizeOfCode',pe.OPTIONAL_HEADER.SizeOfCode+TEXT_SIZE),
                      ('SizeOfInitializedData',pe.OPTIONAL_HEADER.SizeOfInitializedData+DATA_SIZE)):
        struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset(key),value)
    result=bytes(out)
    return result,dict(base_sha256=BASE_SHA,sha256=hashlib.sha256(result).hexdigest(),edits=edits,routines=recipes,
                       added_pdata_rows=len(newpdata),relocation_entries=len(rel),decoder_calls=calls,
                       original_bytes=len(raw),native_executed=False,installation_ready=False)
