"""Cancel a pending graph transition before waiting for a confirmed stop.

Exact MAX33 input; retain native completed-state Pause -> Stop ordering, the
five-second bound, caller failure gates, and ownership until confirmed stopped.
"""
import hashlib
import struct
import pefile
from patch_usb_graph_state import transition as previous_transition
from patch_usb_folders import folder_assemble
from patch_shared_mapping_checks import reloc_records

PIN='6783bad9aef974545de7da2b44514c42e96a30a8c031ac3f88573dad9858fda3'
BASE=0x10000
POLL=0x40000
CAPACITY=0x300


def replace_once(text,old,new):
    assert text.count(old)==1,old
    return text.replace(old,new)


def transition():
    code=previous_transition()
    code=replace_once(code,'beq v0, t0, wait\nnop\nlui t0, 4',
        'beq v0, t0, pending\nnop\nlui t0, 4')
    # s6 tracks the command issued, rather than the observed state. This also
    # prevents a late Running observation from undoing a requested Stop.
    code=replace_once(code,'addiu t2, zero, 0x20\nb command\nnop\npaused:',
        'addiu t2, zero, 0x24\nbeq s6, t2, wait\nnop\naddiu t2, zero, 0x20\nb command\nnop\npaused:')
    code=replace_once(code,'command:\nbeq t0, s6, wait\nnop\nmove s6, t0',
        'command:\nbeq t2, s6, wait\nnop\naddiu s7, zero, 6\nlw t0, 4(s0)\nbne t0, s3, failed\nnop\nmove s6, t2')
    # Pending does not mean ready. A stop request must be allowed to cancel an
    # uncued pause. RealPause may request Pause once, but never revives a graph
    # whose pending target is already Stopped.
    code=replace_once(code,'invalid:\naddiu s7, zero, 5',
        '''pending:
addiu t2, zero, 0x24
addiu t0, zero, 1
bne s1, t0, command
nop
lw t0, 0x20(sp)
beqz t0, wait
nop
addiu t2, zero, 0x20
b command
nop
invalid:
addiu s7, zero, 5''')
    return code


def patch(raw):
    assert hashlib.sha256(raw).hexdigest()==PIN,'Expected exact MAX33 MgrUSB.exe'
    p=pefile.PE(data=raw);out=bytearray(raw);edits=[]
    def edit(va,data,why):
        off=p.get_offset_from_rva(va-BASE);old=bytes(out[off:off+len(data)])
        assert len(old)==len(data)
        out[off:off+len(data)]=data
        edits.append(dict(va=hex(va),offset=off,bytes=len(data),before_hex=old.hex(),after_hex=data.hex(),reason=why))
    old,old_recipe,_=folder_assemble(previous_transition(),POLL,0x600)
    previous_used=old_recipe['used_bytes']
    assert p.get_data(POLL-BASE,previous_used)==old[:previous_used]
    assert not any(p.get_data(POLL-BASE+previous_used,CAPACITY-previous_used))
    new,recipe,rel=folder_assemble(transition(),POLL,CAPACITY)
    edit(POLL,new,'Allow pending pause cancellation; confirm completion before state/ownership changes')
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows=[struct.unpack_from('<5I',p.get_data(d.VirtualAddress,d.Size),i)for i in range(0,d.Size,20)]
    row=next(r for r in rows if r[0]==POLL);assert row[1]==POLL+previous_used
    replacement=(row[0],POLL+recipe['used_bytes'],*row[2:])
    rows=[replacement if r==row else r for r in rows]
    assert all(a[1]<=b[0]for a,b in zip(rows,rows[1:]))
    # Only the end-address field changes. Its existing HIGHLOW relocation stays.
    index=next(i for i,r in enumerate(rows)if r[0]==POLL)
    edit(BASE+d.VirtualAddress+index*20+4,struct.pack('<I',replacement[1]),'Exact transition exception range')
    previous=reloc_records(p)
    kept=[r for r in previous if not POLL-BASE<=r[0]<POLL-BASE+CAPACITY]
    combined=sorted(kept+rel);assert len({r[0]for r in combined})==len(combined)
    pages={}
    for at,kind,companion in combined:
        page=at&~4095;pages.setdefault(page,[]).append((kind<<12)|(at-page))
        if kind==4:pages[page].append(companion)
    table=bytearray()
    for page,values in sorted(pages.items()):
        if len(values)%2:values.append(0)
        table.extend(struct.pack('<II',page,8+len(values)*2));table.extend(struct.pack('<'+'H'*len(values),*values))
    rd=p.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    assert len(table)<=rd.Size or not any(p.get_data(rd.VirtualAddress+rd.Size,len(table)-rd.Size))
    edit(BASE+rd.VirtualAddress,bytes(table)+bytes(max(0,rd.Size-len(table))),'Rebuild exact MIPS relocation records')
    off=rd.get_file_offset()+4
    edit(BASE+p.get_rva_from_offset(off),struct.pack('<I',len(table)),'Relocation directory size')
    checksum=p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    # Recalculate after every code/table edit; checksum is an explicitly recorded edit.
    struct.pack_into('<I',out,checksum,0)
    value=pefile.PE(data=bytes(out)).generate_checksum()
    out[checksum:checksum+4]=raw[checksum:checksum+4]
    edit(BASE+p.get_rva_from_offset(checksum),struct.pack('<I',value),'PE checksum')
    restored=bytearray(out)
    for e in reversed(edits):restored[e['offset']:e['offset']+e['bytes']]=bytes.fromhex(e['before_hex'])
    assert restored==raw
    result=bytes(out);assert len(result)==len(raw)and pefile.PE(data=result).verify_checksum()
    assert reloc_records(pefile.PE(data=result))==combined
    return result,dict(input_sha256=PIN,output_sha256=hashlib.sha256(result).hexdigest(),
        edits=edits,assembly=recipe,previous_pdata=row,pdata=replacement,
        timeout_ms=5000,max_polls=1001,native_executed=False,car_tested=False)
