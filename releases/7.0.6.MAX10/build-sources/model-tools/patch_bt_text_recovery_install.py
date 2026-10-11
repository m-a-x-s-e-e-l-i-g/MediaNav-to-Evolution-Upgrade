"""Install owned text reception, bounded recovery and quiescent profile shutdown.

Blue.exe only; retain every existing artwork helper byte and state allocation.
Map the new writable state into unused space in the existing RW section. This
constructs a local candidate, not an LGU or a device installation.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import pefile
import bt_text_metadata_stream as stream
import bt_text_metadata_owner as owner
import bt_text_metadata_receive as receive
import bt_text_metadata_disconnect as disconnect
import bt_text_metadata_shutdown as shutdown
import bt_text_metadata_retry as retry
import layout_bt_cover_native as layout
import patch_bt_cover_install as cover
from patch_usb_seek_completion import assemble

ROOT=Path(__file__).resolve().parents[1]
BASE_CANDIDATE_SHA='062e951bd6b49a3f9e21175476e6947b115d79803003d3c63ccda5dd9d3b9b22'
STATE=((stream.STATE,stream.SIZE,0x300480,'streaming text'),
       (owner.STATE,owner.SIZE,0x300600,'text request ownership'),
       (receive.STATE,receive.SIZE,0x300800,'text receiver'),
       (retry.STATE,retry.SIZE,0x300840,'bounded text recovery'))


def mapped(value):
    for old,n,new,_ in STATE:
        if old<=value<=old+n:return new+value-old
    return layout.mapped('Blue.exe',value)


def helpers():
    result=[]
    for row in stream.assembled()+owner.assembled()+receive.assembled()+disconnect.assembled()+shutdown.assembled()+retry.assembled():
        pc=row['address'];lines=[];changes=[]
        for source in row['recipe']['source_assembly'].splitlines():
            line=source.split('#',1)[0].strip()
            if not line:continue
            if line.endswith(':'):lines.append(line);continue
            match=re.fullmatch(r'(la\s+\w+,\s*|j(?:al)?\s+)(0x[0-9a-fA-F]+|[0-9]+)',line)
            if match:
                before=int(match[2],0);after=mapped(before)
                if before!=after:
                    changes.append(dict(address=pc,bytes=8 if line.startswith('la ') else 4,
                                        before=before,after=after))
                    line=match[1]+hex(after)
            lines.append(line);pc+=8 if line.startswith('la ') else 4
        raw,recipe,relocations=assemble('\n'.join(lines),row['address'],len(row['raw']))
        assert recipe['used_bytes']==row['recipe']['used_bytes']
        allowed={c['address']-row['address']+i for c in changes for i in range(c['bytes'])}
        assert all(a==b or i in allowed for i,(a,b) in enumerate(zip(row['raw'],raw)))
        result.append(dict(name=row['name'],address=row['address'],raw=raw,recipe=recipe,
                           relocations=relocations,operand_changes=changes))
    result.sort(key=lambda r:r['address'])
    assert len(result)==27 and all(a['address']+len(a['raw'])<=b['address'] for a,b in zip(result,result[1:]))
    return result


def patch(raw):
    baseline,base_recipe=cover.patch('Blue.exe',raw)
    assert cover.sha(baseline)==BASE_CANDIDATE_SHA,'Retained artwork constructor changed'
    base=pefile.PE(data=baseline);native=pefile.PE(data=raw)
    assert base.FILE_HEADER.Characteristics&1 and base.OPTIONAL_HEADER.DATA_DIRECTORY[5].Size==0
    sections=base.sections[-3:];x,d,m=sections
    assert [s.Name.rstrip(b'\0') for s in sections]==[b'.mxartx',b'.mxartd',b'.mxartm']
    assert [s.Characteristics for s in sections]==[0x60000020,0xc0000040,0x40000040]
    assert d.VirtualAddress+0x10000==layout.DATA_BASE and d.Misc_VirtualSize==layout.DATA_SIZE
    rows=helpers();start=x.VirtualAddress+0x10000;old_end=start+x.Misc_VirtualSize
    assert rows[0]['address']>=old_end
    end=max(r['address']+len(r['raw']) for r in rows);assert end<=layout.DATA_BASE
    code=bytearray(base.get_data(x.VirtualAddress,x.Misc_VirtualSize));code.extend(bytes(end-old_end))
    for row in rows:code[row['address']-start:row['address']-start+len(row['raw'])]=row['raw']
    bank=base.get_data(d.VirtualAddress,d.Misc_VirtualSize)
    for old,n,new,_ in STATE:
        assert layout.DATA_BASE<=new and new+n<=layout.DATA_BASE+layout.DATA_SIZE
        assert bank[new-layout.DATA_BASE:new-layout.DATA_BASE+n]==bytes(n)
        assert all(new+n<=other or other+size<=new for _,size,other,_ in layout.STATE['Blue.exe'])
    assert all(a[2]+a[1]<=b[2] for a,b in zip(STATE,STATE[1:]))
    directory=base.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    functions=list(struct.iter_unpack('<5I',base.get_data(directory.VirtualAddress,directory.Size)))
    added=[(r['address'],r['address']+r['recipe']['used_bytes'],0,0,layout.prolog_end(r)) for r in rows]
    functions=sorted(functions+added)
    assert all(a[1]<=b[0] for a,b in zip(functions,functions[1:]))
    meta=b''.join(struct.pack('<5I',*r) for r in functions)
    out=bytearray(baseline[:x.PointerToRawData]);hooks=[]
    base_hooks={r['address']:r['after'] for r in base_recipe['hooks']}
    for at,after in sorted(retry.sites(raw).items()):
        expected=base_hooks.get(at,struct.unpack('<I',native.get_data(at-0x10000,4))[0])
        off=base.get_offset_from_rva(at-0x10000)
        assert struct.unpack_from('<I',out,off)[0]==expected
        struct.pack_into('<I',out,off,after);hooks.append(dict(address=at,before=expected,after=after))
    section_rows=[]
    for s,contents in zip(sections,(bytes(code),bank,meta)):
        position=len(out);n=cover.align(len(contents),base.OPTIONAL_HEADER.FileAlignment)
        struct.pack_into('<I',out,s.get_field_absolute_offset('Misc_VirtualSize'),len(contents))
        struct.pack_into('<I',out,s.get_field_absolute_offset('SizeOfRawData'),n)
        struct.pack_into('<I',out,s.get_field_absolute_offset('PointerToRawData'),position)
        out.extend(contents);out.extend(bytes(n-len(contents)))
        section_rows.append(dict(name=s.Name.rstrip(b'\0').decode(),virtual_bytes=len(contents),raw_bytes=n,
                                 raw_offset=position,sha256=cover.sha(contents)))
    for name,value in (('SizeOfCode',base.OPTIONAL_HEADER.SizeOfCode+section_rows[0]['raw_bytes']-x.SizeOfRawData),
                       ('SizeOfInitializedData',base.OPTIONAL_HEADER.SizeOfInitializedData+section_rows[2]['raw_bytes']-m.SizeOfRawData),
                       ('SizeOfImage',cover.align(m.VirtualAddress+len(meta),base.OPTIONAL_HEADER.SectionAlignment))):
        struct.pack_into('<I',out,base.OPTIONAL_HEADER.get_field_absolute_offset(name),value)
    struct.pack_into('<II',out,directory.get_file_offset(),directory.VirtualAddress,len(meta))
    struct.pack_into('<I',out,base.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),0)
    checked=pefile.PE(data=bytes(out))
    struct.pack_into('<I',out,base.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),checked.generate_checksum())
    checked=pefile.PE(data=bytes(out))
    assert checked.get_overlay_data_start_offset() is None
    assert checked.get_data(x.VirtualAddress,x.Misc_VirtualSize)==base.get_data(x.VirtualAddress,x.Misc_VirtualSize)
    assert checked.get_data(d.VirtualAddress,d.Misc_VirtualSize)==bank
    assert checked.OPTIONAL_HEADER.AddressOfEntryPoint==base.OPTIONAL_HEADER.AddressOfEntryPoint
    return bytes(out),dict(before_sha256=cover.sha(raw),retained_artwork_candidate_sha256=cover.sha(baseline),
                           candidate_sha256=cover.sha(out),candidate_bytes=len(out),hooks=hooks,
                           new_helpers=[{k:v for k,v in r.items() if k not in ('raw','relocations')} for r in rows],
                           state_remaps=STATE,sections=section_rows,new_function_rows=len(added),
                           hardware_tested=False,native_executed=False,lgu_built=False,published=False,
                           limits=['Existing artwork code/state bytes remain exact; only reviewed native callback bindings change',
                                   'Installed recovery/shutdown verification and complete LGU packaging remain required'])


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('input','output','report'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args()
    for path in (a.output,a.report):
        if path.exists():raise FileExistsError('Use fresh output paths')
        if not path.resolve().is_relative_to(ROOT/'build'):raise ValueError('Outputs must stay in ignored build directory')
    raw,report=patch(a.input.read_bytes());a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_bytes(raw)
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_bytes((json.dumps(report,indent=2)+'\n').encode())
    print(json.dumps(dict(bytes=len(raw),sha256=report['candidate_sha256'],new_helpers=report['new_function_rows']),indent=2))
