"""Offline ROM imaging factory, memory-stream and built-in codec evidence."""
import hashlib
import json
import struct
import uuid
from pathlib import Path
import pefile
from inspect_usb_metadata import IMAGING_HASH

ROOT=Path(__file__).resolve().parents[1]


def seek(size,pos,move,origin):
    if origin==2:return size
    if origin==1:move+=pos
    elif origin!=0:return None
    return move if 0<=move<=size else None


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    m=next(m for m in modules if m["origin"]=="rom" and m["name"]=="imaging.dll")
    p=ROOT/m["path"];assert hashlib.sha256(p.read_bytes()).hexdigest()==IMAGING_HASH
    pe=pefile.PE(str(p));base=pe.OPTIONAL_HEADER.ImageBase
    get=lambda va,n:pe.get_data(va-base,n)
    funcs=json.loads((ROOT/"analysis/functions/rom/imaging.dll.json").read_text(encoding="utf-8"))["functions"]
    by_va={int(f["begin_va"],16):f["bytes"] for f in funcs}
    addresses=[0x40486fb8,0x40487070,0x40487180,0x40487244,0x40487c08,0x40487844,0x40487ad8,
        0x40487bbc,0x40488000,0x4048887c,0x40488f6c,0x4048a094,0x4048a700,0x4048a7a0,
        0x4048a864,0x4048a928,0x4048af24,0x4048b58c,0x4048b6f0,0x4048b798,0x4048b998,
        0x4048ba3c,0x4048f8d0,0x4048f9b0,0x404964f0,0x404996d8,0x4049d180,0x404a1fcc]
    ranges=[(a,by_va[a],"pdata") for a in addresses]+[(0x404a13f4,8,"bounded leaf span"),(0x404a3c98,8,"bounded leaf span"),
        (0x40481160,16,"IStream IID")]
    vtables={}
    for va,n,name in [(0x404810e0,17,"factory"),(0x40481170,15,"memory_stream"),(0x40481664,10,"image")]:
        vtables[name]=dict(va=hex(va),slots=[hex(x) for x in struct.unpack(f"<{n}I",get(va,n*4))])
        ranges.append((va,n*4,"vtable"))
    assert vtables["factory"]["slots"][5]=="0x40487c08"
    assert vtables["image"]["slots"][4]=="0x4048b6f0"
    assert vtables["image"]["slots"][6]=="0x4048b798"
    assert str(uuid.UUID(bytes_le=get(0x40481160,16)))=="0000000c-0000-0000-c000-000000000046"
    strings={};resource_blocks=[]
    wanted=set(range(2010,2014))|set(range(2020,2024))|set(range(2030,2034))|set(range(2070,2074))
    for typ in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        if typ.id!=6:continue
        for block in typ.directory.entries:
            entry=block.directory.entries[0].data.struct
            raw=pe.get_data(entry.OffsetToData,entry.Size);cursor=0;found=[]
            for i in range(16):
                size=struct.unpack_from("<H",raw,cursor)[0];cursor+=2
                ident=(block.id-1)*16+i;value=raw[cursor:cursor+size*2].decode("utf-16le");cursor+=size*2
                if ident in wanted:strings[ident]=value;found.append(ident)
            if found:
                resource_blocks.append(dict(block_id=block.id,rva=hex(entry.OffsetToData),bytes=len(raw),
                    ids=found,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    codecs=[]
    for va,label in [(0x404bd240,"BMP"),(0x404bd20c,"JPEG"),(0x404bd1d8,"GIF"),(0x404bd1a4,"PNG")]:
        vals=struct.unpack("<13I",get(va,52));ranges.append((va,52,"builtin codec descriptor"))
        patterns=get(vals[10],vals[8]*vals[9]);masks=get(vals[11],len(patterns))
        ranges.extend([(vals[0],16,"codec CLSID"),(vals[1],16,"format GUID"),
            (vals[10],len(patterns),"signature patterns"),(vals[11],len(masks),"signature masks")])
        codecs.append(dict(name=label,descriptor_va=hex(va),clsid=str(uuid.UUID(bytes_le=get(vals[0],16))),
            format_guid=str(uuid.UUID(bytes_le=get(vals[1],16))),
            descriptions=[strings[i] for i in vals[2:6]],version=vals[6],stored_flags=hex(vals[7]),
            effective_flags=hex(vals[7]|2|0x10000),pattern_count=vals[8],pattern_bytes=vals[9],
            patterns=[patterns[i*vals[9]:(i+1)*vals[9]].hex() for i in range(vals[8])],
            masks=[masks[i*vals[9]:(i+1)*vals[9]].hex() for i in range(vals[8])],factory_va=hex(vals[12])))
    assert [c["name"] for c in sorted(codecs,key=lambda x:x["descriptor_va"])]==["PNG","GIF","JPEG","BMP"]
    assert all(c["effective_flags"]=="0x10006" for c in codecs)
    def classify(raw):
        # All local masks are ff. Native list is PNG,JPEG,GIF,BMP; signatures are disjoint.
        for name in ["PNG","JPEG","GIF","BMP"]:
            codec=next(c for c in codecs if c["name"]==name)
            if any(raw.startswith(bytes.fromhex(s)) for s in codec["patterns"]):return name
        return None
    signature_cases=0;alternate_gif=0
    for codec in codecs:
        for pattern in codec["patterns"]:
            raw=bytes.fromhex(pattern);assert classify(raw)==codec["name"]
            for n in range(len(raw)):assert classify(raw[:n]) is None
            for index in range(len(raw)):
                for byte in range(256):
                    changed=raw[:index]+bytes([byte])+raw[index+1:];got=classify(changed)
                    expected=byte==raw[index] or codec["name"]=="GIF" and changed in [b"GIF89a",b"GIF87a"]
                    assert (got==codec["name"])==expected
                    alternate_gif+=byte!=raw[index] and got=="GIF"
                    signature_cases+=1
    assert alternate_gif==2
    read_cases=0;seek_cases=0;end_offset_mismatches=0;examples=[]
    for size in range(33):
        for position in range(size+1):
            for count in range(36):
                amount=min(count,size-position);assert amount>=0 and position+amount<=size
                read_cases+=1
            for origin in [0,1,2,3]:
                for move in range(-34,35):
                    result=seek(size,position,move,origin)
                    assert result is None or 0<=result<=size
                    if origin==2:
                        assert result==size
                        end_offset_mismatches+=move!=0
                    seek_cases+=1
    for move in [-9,-1,0,1,9]:
        examples.append(dict(size=100,position=20,move=move,origin=2,native_position=seek(100,20,move,2),
            standard_end_relative_position=100+move))
    evidence=[]
    for va,size,boundary in ranges:
        raw=get(va,size);assert len(raw)==size
        evidence.append(dict(va=hex(va),bytes=size,boundary=boundary,raw_hex=raw.hex(),
            sha256=hashlib.sha256(raw).hexdigest()))
    result=dict(binary_execution=False,source=dict(module=m["name"],path=m["path"],sha256=IMAGING_HASH,
        ranges=evidence,resource_blocks=resource_blocks),vtables=vtables,builtin_codecs=codecs,
        builtin_selection_order=["PNG","JPEG","GIF","BMP"],max_builtin_signature_bytes=8,
        buffer_disposal_to_internal_action={"0":0,"1":1,"2":3,"3":4},
        internal_disposal_actions={"0":"retain caller ownership","1":"LocalFree","2":"VirtualFree",
            "3":"CoTaskMemFree","4":"UnmapViewOfFile"},
        stream_fields={"refcount":4,"busy_guard":8,"buffer_pointer":12,"size":16,"position":20,
            "disposal":24,"mapping_handle":28,"auxiliary_allocation":32},
        image_fields={"refcount":4,"busy_guard":12,"decoder":16,"retained_stream":20,
            "cached_bitmap":24,"flags":28},
        seek_end_examples=examples,read_short_hresult=0,checks=dict(preserved_ranges=len(evidence),
            resource_blocks=len(resource_blocks),codec_descriptors=len(codecs),vtable_count=len(vtables),
            signature_mutations=signature_cases,gif_version_alternatives=alternate_gif,
            bounded_stream_reads=read_cases,bounded_stream_seeks=seek_cases,
            ignored_end_displacements=end_offset_mismatches),
        limitations=["Models use bounded valid stream sizes/positions; no image or native codec is executed",
            "The seek model captures logical offsets without emulating all uint64 wrap/carry edge cases",
            "Mutable registry codecs, loaded-unit settings and all pixel decoders remain outside this pass",
            "Resource strings use the first PE resource language; no runtime language resolution is simulated"])
    (ROOT/"analysis/firmware/imaging-factory-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"]),indent=2))


if __name__=="__main__":main()
