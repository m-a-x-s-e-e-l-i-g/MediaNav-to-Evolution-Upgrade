"""Report save failures and skip writes after failed loads; retain dispatch contract."""
import hashlib
import struct
import pefile
from patch_usb_reliability import assemble,BASE,DATA,DATA_SIZE
from patch_updater_copy_safety import frame,end
from patch_usb_reliability import SAVE,LOAD

BASE_SHA='8c5ee4cec945284936557058da63804f2b3cc0402a814ecf14866329596b163e'
WATCH,RESET,NOTE=0x3c500,0x3c680,0x41800
MESSAGES=('USB playback position save or cleanup failed (caller %08x).',
          'USB playback modes reset: resume load failed; no save attempted.')

WATCH_CODE=f'''
{frame(0x30,['s0','s1'])}
move s1, ra
jal {hex(SAVE)}
nop
move s0, v0
bnez s0, done
nop
addiu a0, zero, 5
addiu a1, zero, 3
la a2, {hex(NOTE)}
jal 0x23aac
move a3, s1
done:
move v0, s0
{end(0x30,['s0','s1'])}
'''
RESET_CODE=f'''
{frame(0x30,['s0','s1'])}
addiu s0, a0, 8
jal 0x231a4
addiu s1, zero, 2
lw t0, 0x38(v0)
bnez t0, modes
nop
move a0, s0
la a1, 0x29d88
jal {hex(LOAD)}
nop
move s1, v0
modes:
move a0, s0
move a1, zero
jal 0x1b5b0
move a2, zero
move a0, s0
jal 0x1b544
move a1, zero
beqz s1, load_failed
addiu t0, zero, 2
beq s1, t0, success
nop
move a0, s0
la a1, 0x29d88
jal {hex(WATCH)}
nop
b done
move s1, v0
load_failed:
addiu a0, zero, 5
addiu a1, zero, 3
la a2, {hex(NOTE+0x100)}
jal 0x23aac
nop
b done
move s1, zero
success:
addiu s1, zero, 1
done:
move v0, s1
{end(0x30,['s0','s1'])}
'''

def patch(raw):
    assert hashlib.sha256(raw).hexdigest()==BASE_SHA
    p=pefile.PE(data=raw);out=bytearray(raw);edits=[];newrel=[]
    def block(at,cap,code,why):
        new,r,rel=assemble(code,at,cap);off=p.get_offset_from_rva(at-BASE)
        edits.append(dict(va=hex(at),offset=hex(off),bytes=cap,before_hex=raw[off:off+cap].hex(),
                          after_hex=new.hex(),reason=why,assembly=r))
        out[off:off+cap]=new;newrel.extend(rel);return r
    added=[]
    for at,cap,code,prolog in [(WATCH,0x180,WATCH_CODE,16),(RESET,0x180,RESET_CODE,16)]:
        assert not any(p.get_data(at-BASE,cap))
        r=block(at,cap,code,'Checked save outcome wrapper or guarded reset')
        added.append((at,at+r['used_bytes'],0,0,at+prolog))
    assert not any(p.get_data(NOTE-BASE,0x200))
    strings=b''.join((s+'\0').encode('utf-16-le').ljust(0x100,b'\0') for s in MESSAGES)
    assert len(strings)==0x200
    off=p.get_offset_from_rva(NOTE-BASE)
    edits.append(dict(va=hex(NOTE),offset=hex(off),bytes=0x200,before_hex=raw[off:off+0x200].hex(),
                      after_hex=strings.hex(),reason='English failure diagnostics using the existing logger'))
    out[off:off+0x200]=strings
    for at in (0x1c9c8,0x20c3c,0x224b4,0x226b8):
        assert struct.unpack('<I',p.get_data(at-BASE,4))[0]==(3<<26)|(SAVE>>2)
        block(at,4,f'jal {hex(WATCH)}','Report save failure; retain playback/removal continuation')
    block(0x1e9fc,16,f'la t9, {hex(RESET)}\njr t9\nnop','Guard reset save after LOAD failure; retain active mode reset')
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=p.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    assert any(row[0]==0x1e9fc and row[1]==0x1ea9c for row in rows)
    rows=sorted([(a,b,h,v,a if a==0x1e9fc else pro) for a,b,h,v,pro in rows]+added)
    assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    combined=b''.join(struct.pack('<5I',*r) for r in rows)
    assert d.VirtualAddress==DATA+0x1000-BASE and len(combined)<0x2000
    off=p.get_offset_from_rva(d.VirtualAddress)
    edits.append(dict(va=hex(BASE+d.VirtualAddress),offset=hex(off),bytes=len(combined),
        before_hex=raw[off:off+len(combined)].hex(),after_hex=combined.hex(),reason='Combined exception rows plus wrappers and guarded reset'))
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
        added_pdata_rows=2,save_algorithm_unchanged=True,no_extra_save_attempts=True,
        native_executed=False,installation_ready=False)
