"""Place artwork helper code and writable state in separate future PE sections.

Reassemble reviewed pointer operands; do not patch arbitrary matching bytes.
Original helper address spans are interpreter placements. No PE or LGU is written.
"""
from dataclasses import dataclass
from functools import lru_cache
import hashlib
import re
import struct

import pefile

import bt_cover_art_publisher as publisher
import bt_cover_art_app_lifetime as lifetime
import bt_cover_art_task as task
import bt_cover_art_transfer as transfer
import bt_cover_art_csr_bridge as query
from patch_usb_seek_completion import assemble

DATA_BASE,DATA_SIZE=0x300000,0x1000
IMAGE_BASE=0x10000
# old start, bytes, installed start, role. Strings remain read-only in RX holes.
STATE={
 'Blue.exe':((0x247000,2,0x300000,'scheduler queue'),
             (0x261000,320,0x300020,'metadata ticket and collector'),
             (0x269400,0x130,0x300200,'peer birth and selected-track binding'),
             (0x27f000,24,0x300400,'mapping context'),
             (0x282800,24,0x300440,'GUI publisher lifetime')),
 'AppMain.exe':((0x229000,24,0x300000,'mapping context'),
                (0x234000,80,0x300020,'worker and GUI bitmap lifetime'))}
CODE_MOVES={'Blue.exe':((0x230000,0x1000,0x233000,'SDP query bridge'),),'AppMain.exe':()}
# These LA operands are capacities, not pointers. They happen to fall inside the
# legacy image's numeric VA range and must never receive image-base relocations.
CONSTANTS={0x20000:'encoded capacity',0x20001:'encoded capacity bound',0x20040:'mapping size',
           0x20041:'mapping size bound',0xcc0020:'SRCCOPY raster operation',
           0x3141424d:'mapping magic',0x1070502:'retained GUI command',0xfffffff:'channel serial bound'}


def mapped(module,value):
    # Clear loops also materialize a one-past-end pointer to the same allocation.
    for old,size,new,_ in STATE[module]:
        if old<=value<=old+size:return new+value-old
    for old,size,new,_ in CODE_MOVES[module]:
        if old<=value<old+size:return new+value-old
    return value


@lru_cache(maxsize=2)
def originals(module):
    if module=='Blue.exe':
        raw,recipe,relocations=assemble(query.CODE,query.ENTRY,0x100)
        return publisher.assembled()+[dict(name='SDP query bridge',address=query.ENTRY,raw=raw,
                                          recipe=recipe,relocations=relocations)]
    if module=='AppMain.exe':return lifetime.assembled()
    raise ValueError(module)


def immutable(module):
    c=transfer.CONFIGS[module]
    result={at:raw for at,raw in transfer.initial_data(module).items() if at!=c.state}
    if module=='Blue.exe':result[task.NAME]=task.initial_data()[task.NAME]
    return result


def rewrite(module,row):
    start=mapped(module,row['address']);pc=start
    lines,changes,constant_sites=[],[],[]
    for source in row['recipe']['source_assembly'].splitlines():
        line=source.split('#',1)[0].strip()
        if not line:continue
        if line.endswith(':'):lines.append(line);continue
        m=re.fullmatch(r'(la\s+\w+,\s*|j(?:al)?\s+)(0x[0-9a-fA-F]+|[0-9]+)',line)
        if m:
            value=int(m[2],0);installed=mapped(module,value)
            if installed!=value:
                changes.append(dict(address=pc,bytes=8 if line.startswith('la ') else 4,
                                    before=value,after=installed,operand=line))
                line=m[1]+hex(installed)
            if line.startswith('la ') and value in CONSTANTS:
                assert installed==value
                constant_sites.append(dict(address=pc,value=value,role=CONSTANTS[value]))
        lines.append(line);pc+=8 if line.startswith('la ') else 4
    raw,recipe,relocations=assemble('\n'.join(lines),start,len(row['raw']))
    assert recipe['used_bytes']==row['recipe']['used_bytes']
    # Every changed instruction must be part of an explicitly reviewed address
    # operand; control flow, ABI, arithmetic and object offsets stay byte-exact.
    allowed={r['address']-start+i for r in changes for i in range(0,r['bytes'],4)}
    changed=[]
    for off in range(0,len(raw),4):
        if raw[off:off+4]!=row['raw'][off:off+4]:
            assert off in allowed,('Unexpected instruction change',row.get('name'),hex(start+off))
            changed.append(start+off)
    excluded={r['address']+i for r in constant_sites for i in (0,4)}
    # The assembler records every LA/JAL. Keep image pointers only: external
    # kernel traps and numerical capacities/ROP values are not image addresses.
    retained=[]
    source_by_pc={}
    pc=start
    for line in lines:
        if line.endswith(':'):continue
        if line.startswith('la '):
            value=int(line.rsplit(',',1)[1].strip(),0)
            source_by_pc[pc]=value;source_by_pc[pc+4]=value
        elif line.startswith(('jal ','j ')):source_by_pc[pc]=int(line.split()[1],0)
        pc+=8 if line.startswith('la ') else 4
    spans=[(IMAGE_BASE,0x233000 if module=='Blue.exe' else 0x215000)]
    spans += [(mapped(module,r['address']),mapped(module,r['address'])+len(r['raw'])) for r in originals(module)]
    spans += [(at,at+len(b)) for at,b in immutable(module).items()]
    spans += [(DATA_BASE,DATA_BASE+DATA_SIZE)]
    for at,kind,companion in relocations:
        # The shared assembler returns relocation locations as image RVAs.
        va=at+IMAGE_BASE;value=source_by_pc[va]
        if va not in excluded and any(lo<=value<hi for lo,hi in spans):retained.append((at,kind,companion))
        else:assert value in CONSTANTS,('Unreviewed address/constant',row.get('name'),hex(value))
    return dict(name=row.get('name',row.get('purpose',hex(row['address']))),address=start,
                old_address=row['address'],raw=raw,recipe=recipe,relocations=retained,
                operand_changes=changes,changed_instructions=changed,constant_sites=constant_sites)


def prolog_end(row):
    # MIPS runtime-function prologs generated by frame(): stack allocation,
    # return address and saved register stores. Tail/leaf helpers have no frame.
    at=row['address'];limit=row['recipe']['used_bytes'];pos=0
    if limit>=4 and int.from_bytes(row['raw'][:4],'little')>>16==0x27bd:
        assert int.from_bytes(row['raw'][:4],'little')&0x8000
        pos=4
        while pos<limit:
            w=int.from_bytes(row['raw'][pos:pos+4],'little')
            if w>>26!=0x2b or (w>>21)&31!=29 or (w>>16)&31 not in (*range(16,24),28,30,31):break
            pos+=4
        assert pos>=8,'Framed helper without saved return address'
    return at+pos


def plan(module,raw):
    if module=='Blue.exe':publisher.contracts(raw);query.bridge(raw)
    elif module=='AppMain.exe':lifetime.contracts(raw)
    else:raise ValueError(module)
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase;assert base==IMAGE_BASE
    assert pe.OPTIONAL_HEADER.SectionAlignment==0x1000
    # One RX code bank, one RW state bank and one read-only metadata bank.
    table_end=pe.sections[-1].get_file_offset()+40
    assert table_end+3*40<=pe.sections[0].PointerToRawData,'Insufficient section headers'
    rows=sorted((rewrite(module,r) for r in originals(module)),key=lambda r:r['address'])
    assert all(a['address']+len(a['raw'])<=b['address'] for a,b in zip(rows,rows[1:]))
    lo=min(r['address'] for r in rows);hi=max(r['address']+len(r['raw']) for r in rows)
    assert lo>=base+pe.OPTIONAL_HEADER.SizeOfImage
    assert hi<=DATA_BASE
    code=bytearray(hi-lo);state=bytearray(DATA_SIZE)
    for r in rows:code[r['address']-lo:r['address']-lo+len(r['raw'])]=r['raw']
    for at,b in immutable(module).items():
        assert lo<=at and at+len(b)<=hi
        assert not any(r['address']<=at<r['address']+len(r['raw']) for r in rows)
        code[at-lo:at-lo+len(b)]=b
    if module=='Blue.exe':state[:2]=b'\xff\xff'
    for old,n,new,_ in STATE[module]:
        assert DATA_BASE<=new and new+n<=DATA_BASE+DATA_SIZE
        assert not any(r['address']<=old<r['address']+len(r['raw']) for r in rows)
    pdata=[(r['address'],r['address']+r['recipe']['used_bytes'],0,0,prolog_end(r)) for r in rows]
    assert all(begin<=prolog<=end for begin,end,_,_,prolog in pdata)
    return dict(module=module,source_sha256=hashlib.sha256(raw).hexdigest(),code_address=lo,code=bytes(code),
                data_address=DATA_BASE,data=bytes(state),helpers=rows,pdata=pdata,
                state_remaps=STATE[module],code_moves=CODE_MOVES[module],section_headers_available=(pe.sections[0].PointerToRawData-table_end)//40,
                permissions=dict(code='read/execute',state='read/write',metadata='read'),
                executable_written=False,lgu_built=False)
