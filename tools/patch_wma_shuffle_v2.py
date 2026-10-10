"""Update WMA C++ IP-to-unwind-state mapping for the rewritten body."""
import hashlib
import struct
import pefile
from patch_wma_shuffle import patch as first_patch

def patch(original):
    raw,recipe=first_patch(original);out=bytearray(raw);p=pefile.PE(data=raw)
    edits=recipe['edits'];newrel=[]
    assert p.get_data(0x28b88-0x10000,40)==struct.pack('<10I',0x19930522,1,0x28b80,0,0,54,0x28bb0,0,1,0xffffffd0)
    assert p.get_data(0x28b80-0x10000,8)==struct.pack('<2I',0xffffffff,0x18f54)
    # The context is constructed by the retained call at 18320 and destroyed by
    # the retained call at 18f0c. State zero uses the existing destructor funclet.
    for at,new,why in [(0x28b9c,struct.pack('<I',2),'Two valid WMA context-unwind IP ranges'),
         (0x28bb0,struct.pack('<4I',0x18328,0,0x18f0c,0xffffffff)+bytes(54*8-16),
          'Context owns state zero throughout new WMA body; no stale old API IPs')]:
        off=p.get_offset_from_rva(at-0x10000)
        edits.append(dict(va=hex(at),offset=hex(off),bytes=len(new),before_hex=original[off:off+len(new)].hex(),
                          after_hex=new.hex(),reason=why))
        out[off:off+len(new)]=new
    newrel=[(0x28bb0-0x10000,3,None),(0x28bb8-0x10000,3,None)]
    rd=p.OPTIONAL_HEADER.DATA_DIRECTORY[5];old=p.get_data(rd.VirtualAddress,rd.Size)
    rel=[];pos=0
    while pos<len(old):
        page,n=struct.unpack_from('<II',old,pos);vals=struct.unpack_from('<'+str((n-8)//2)+'H',old,pos+8);i=0
        while i<len(vals):
            v=vals[i];i+=1;kind=v>>12;at=page+(v&4095);extra=None
            if kind==4:extra=vals[i];i+=1
            if kind and not 0x28bb0-0x10000<=at<0x28bb0-0x10000+54*8:rel.append((at,kind,extra))
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
    edit=next(e for e in edits if e['reason']=='Combined MIPS relocations')
    off=int(edit['offset'],16);cap=edit['bytes'];assert len(table)<=cap
    new=bytes(table)+bytes(cap-len(table));out[off:off+cap]=new;edit['after_hex']=new.hex()
    struct.pack_into('<I',out,rd.get_file_offset()+4,len(table))
    result=bytes(out);recipe.update(sha256=hashlib.sha256(result).hexdigest(),
        asf_exception_mapping=dict(original_entries=54,new_entries=2,context_construct_call='0x18320',
                                   destructor_call='0x18f0c',cleanup_funclet='0x18f54',frame_unchanged=True))
    return result,recipe
