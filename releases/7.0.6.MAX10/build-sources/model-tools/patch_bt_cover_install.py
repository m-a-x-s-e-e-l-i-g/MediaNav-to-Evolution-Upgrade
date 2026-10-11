"""Construct separate artwork candidate PEs from exact retained MAX05 modules.

Compose feedback repairs, native hooks, RX helpers, RW state and read-only
exception/relocation metadata. Does not install firmware or build an LGU.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

import pefile

import layout_bt_cover_native as layout
import bt_cover_art_publisher as publisher
import bt_cover_art_app_lifetime as lifetime
import bt_cover_art_app_paint as paint
import bt_cover_art_task as task
import bt_cover_art_csr_bridge as query
from patch_shared_mapping_checks import reloc_records
from stage_artwork_feedback_inputs import compose
from patch_ui_runtime_labels import patch as labels
from patch_aha_disable import patch as aha
from patch_bt_metadata_status import patch as metadata
from patch_bt_metadata_interim import patch as interim
from patch_bt_metadata_uid_width import patch as uid_width
from patch_bt_pcm_bursts import patch as bursts
from patch_bt_cover_attribute import patch as attribute

ROOT=Path(__file__).resolve().parents[1]


def sha(raw):return hashlib.sha256(raw).hexdigest()


def align(value,n):
    assert n and n&(n-1)==0
    return (value+n-1)&-n


def relocation_table(records):
    records=sorted(records)
    assert len({r[0] for r in records})==len(records),'Duplicate relocation locations'
    groups={}
    for rva,kind,companion in records:
        assert kind in (1,2,3,4,5) and rva>=0
        entry=kind<<12|rva&4095
        items=groups.setdefault(rva&~4095,[]);items.append(entry)
        if kind==4:
            assert companion is not None and 0<=companion<=65535
            items.append(companion)
        else:assert companion is None
    out=bytearray()
    for page,items in sorted(groups.items()):
        if len(items)&1:items.append(0)
        out.extend(struct.pack('<II',page,8+len(items)*2))
        out.extend(struct.pack('<'+'H'*len(items),*items))
    return bytes(out)


def bindings(module,raw):
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase
    if module=='Blue.exe':
        after={int(at,16):int(word,16) for at,word in publisher.contracts(raw)['window_registration'].items()}
        after[task.SITE]=task.bridge(raw)
        query.bridge(raw)
        after[query.SITE]=(3<<26)|(layout.mapped(module,query.ENTRY)>>2)
    elif module=='AppMain.exe':
        # ADDIU sign-extends the low half: the new window procedure ends in A000.
        # Its LUI must include the carry, and HIGHADJ's companion must follow it.
        after={0x3c81c:0x3c080000|((lifetime.WND+0x8000)>>16),
               0x3c824:0x25060000|(lifetime.WND&65535),paint.VTABLE_SLOT:paint.DRAW}
    else:raise ValueError(module)
    return [dict(address=at,before=struct.unpack('<I',pe.get_data(at-base,4))[0],after=word)
            for at,word in sorted(after.items())]


def patch(module,raw):
    p=layout.plan(module,raw);pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase
    assert pe.FILE_HEADER.Machine==0x166 and base==layout.IMAGE_BASE
    assert pe.get_overlay_data_start_offset() is None and pe.OPTIONAL_HEADER.DATA_DIRECTORY[4].Size==0
    fixes=([('metadata-final-status',metadata),('metadata-interim-progress',interim),('metadata-uid-width',uid_width),
            ('pcm-burst-reserve',bursts),('attribute-8',attribute)]
           if module=='Blue.exe' else [('active-labels',labels),('aha-gate',aha)])
    repaired,feedback=compose(raw,fixes);out=bytearray(repaired)
    feedback_offsets={i for i,(a,b) in enumerate(zip(raw,repaired)) if a!=b}
    hooks=bindings(module,raw)
    for row in hooks:
        off=pe.get_offset_from_rva(row['address']-base)
        assert struct.unpack_from('<I',out,off)[0]==row['before']
        assert not feedback_offsets.intersection(range(off,off+4)),'Feedback/native hook overlap'
        struct.pack_into('<I',out,off,row['after'])

    directory=pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    previous=list(struct.iter_unpack('<5I',pe.get_data(directory.VirtualAddress,directory.Size)))
    functions=sorted(previous+p['pdata'])
    assert all(a[1]<=b[0] for a,b in zip(functions,functions[1:]))
    functions_raw=b''.join(struct.pack('<5I',*r) for r in functions)
    meta_address=layout.DATA_BASE+layout.DATA_SIZE
    meta=bytearray(functions_raw)
    rel_before=reloc_records(pe)
    rel_added=[];rel_removed=[];rel_combined=[]
    if module=='AppMain.exe':
        replaced={0x3c81c-base,0x3c824-base,paint.VTABLE_SLOT-base}
        rel_removed=[r for r in rel_before if r[0] in replaced]
        assert {r[0] for r in rel_removed}==replaced
        assert [r[1] for r in sorted(rel_removed)]==[4,2,3]
        rel_added=[r for helper in p['helpers'] for r in helper['relocations']]
        rel_added += [(0x3c81c-base,4,lifetime.WND&65535),(0x3c824-base,2,None),
                      (paint.VTABLE_SLOT-base,3,None)]
        # The copied exception directory contains absolute image addresses.
        for i,row in enumerate(functions):
            for j,value in enumerate(row):
                if value:
                    assert base<=value<meta_address
                    rel_added.append((meta_address-base+i*20+j*4,3,None))
        rel_combined=[r for r in rel_before if r[0] not in replaced]+rel_added
        rel_offset=align(len(meta),4);meta.extend(bytes(rel_offset-len(meta)))
        rel_raw=relocation_table(rel_combined);meta.extend(rel_raw)
    else:
        assert pe.FILE_HEADER.Characteristics&1 and not rel_before
        assert pe.OPTIONAL_HEADER.DATA_DIRECTORY[5].Size==0
        rel_offset=0;rel_raw=b''

    header=pe.sections[-1].get_file_offset()+40
    assert header+120<=pe.OPTIONAL_HEADER.SizeOfHeaders and not any(raw[header:header+120])
    file_align=pe.OPTIONAL_HEADER.FileAlignment;section_align=pe.OPTIONAL_HEADER.SectionAlignment
    added=[];position=align(len(out),file_align);out.extend(bytes(position-len(out)))
    for i,(name,address,contents,flags) in enumerate(((b'.mxartx',p['code_address'],p['code'],0x60000020),
                                                   (b'.mxartd',p['data_address'],p['data'],0xc0000040),
                                                   (b'.mxartm',meta_address,bytes(meta),0x40000040))):
        n=align(len(contents),file_align)
        struct.pack_into('<8s8I',out,header+40*i,name,len(contents),address-base,n,position,0,0,0,flags)
        added.append(dict(name=name.decode(),address=address,virtual_bytes=len(contents),raw_offset=position,
                          raw_bytes=n,flags=hex(flags),sha256=sha(contents)))
        out.extend(contents);out.extend(bytes(n-len(contents)));position+=n
    struct.pack_into('<H',out,pe.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),len(pe.sections)+3)
    for field,value in (('SizeOfImage',align(meta_address+len(meta)-base,section_align)),
                        ('SizeOfCode',pe.OPTIONAL_HEADER.SizeOfCode+added[0]['raw_bytes']),
                        ('SizeOfInitializedData',pe.OPTIONAL_HEADER.SizeOfInitializedData+added[1]['raw_bytes']+added[2]['raw_bytes'])):
        struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset(field),value)
    struct.pack_into('<II',out,directory.get_file_offset(),meta_address-base,len(functions_raw))
    if rel_raw:
        struct.pack_into('<II',out,pe.OPTIONAL_HEADER.DATA_DIRECTORY[5].get_file_offset(),meta_address-base+rel_offset,len(rel_raw))
    struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),0)
    checked=pefile.PE(data=bytes(out))
    struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),checked.generate_checksum())
    checked=pefile.PE(data=bytes(out))
    assert len(checked.sections)==len(pe.sections)+3 and checked.OPTIONAL_HEADER.ImageBase==base
    assert checked.OPTIONAL_HEADER.AddressOfEntryPoint==pe.OPTIONAL_HEADER.AddressOfEntryPoint
    assert reloc_records(checked)==sorted(rel_combined)
    return bytes(out),dict(module=module,before_sha256=sha(raw),after_sha256=sha(out),before_bytes=len(raw),
                           after_bytes=len(out),feedback=feedback,hooks=hooks,sections=added,
                           added_function_rows=len(p['pdata']),retained_function_rows=len(previous),
                           relocation_records_before=len(rel_before),relocation_records_after=len(rel_combined),
                           relocation_records_added=len(rel_added),relocation_records_removed=rel_removed,
                           image_size=checked.OPTIONAL_HEADER.SizeOfImage,checksum=checked.OPTIONAL_HEADER.CheckSum,
                           native_executed=False,hardware_tested=False,lgu_built=False,published=False,
                           limits=['Actual Windows CE loader, unwind, codec, scheduling and device screen require testing',
                                   'Only exact original MAX05 inputs are accepted; feedback and native edits are composed without overlaps',
                                   'Bootloader, OS/MCU images, navigation and retained process entry points are unchanged',
                                   'Full remapped instruction integration and complete LGU packing/readback remain required'])


if __name__=='__main__':
    a=argparse.ArgumentParser(description=__doc__)
    a.add_argument('--module',choices=('Blue.exe','AppMain.exe'),required=True)
    a.add_argument('--input',type=Path,required=True);a.add_argument('--output',type=Path,required=True)
    a.add_argument('--report',type=Path,required=True);args=a.parse_args()
    for path in (args.output,args.report):
        if path.exists():raise FileExistsError('Use fresh output paths')
        if not path.resolve().is_relative_to(ROOT/'build'):raise ValueError('Outputs must stay in ignored build directory')
    result,report=patch(args.module,args.input.read_bytes())
    args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_bytes(result)
    args.report.parent.mkdir(parents=True,exist_ok=True);args.report.write_bytes((json.dumps(report,indent=2)+'\n').encode())
    print(json.dumps(dict(module=args.module,bytes=len(result),sha256=sha(result),lgu_built=False),indent=2))
