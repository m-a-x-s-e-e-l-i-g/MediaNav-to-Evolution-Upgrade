"""Verify synthetic .cerom metadata and shared-RVA bytes against original NK records."""
import hashlib
import json
import struct
from pathlib import Path
import pefile
from analyze_firmware import nk_info

ROOT=Path(__file__).resolve().parents[1]


def main():
    source=(ROOT/"extracted/705md/upgrade/Storage Card/NK.bin").read_bytes()
    records=nk_info(source)["records"]
    base=min(int(r["address"],16) for r in records)
    end=max(int(r["address"],16)+r["size"] for r in records)
    flat=bytearray(end-base)
    for r in records:
        offset=int(r["address"],16)-base
        flat[offset:offset+r["size"]]=source[r["file_offset"]:r["file_offset"]+r["size"]]
    def read(va,size):
        if not base<=va<=va+size<=end:raise ValueError("Source address outside image")
        return bytes(flat[va-base:va-base+size])
    hdr_va=struct.unpack_from("<I",flat,0x44)[0]
    hdr=struct.unpack("<17I2HI2I",read(hdr_va,84))
    modules,checks=[],[]
    for index in range(hdr[4]):
        toc=struct.unpack("<8I",read(hdr_va+84+index*32,32))
        attrs,time_lo,time_hi,file_size,name_va,e32_va,o32_va,load_va=toc
        name=read(name_va,min(256,end-name_va)).split(bytes([0]),1)[0].decode("ascii")
        e32=read(e32_va,0x6c);count=struct.unpack_from("<H",e32)[0]
        vsize=struct.unpack_from("<I",e32,0x14)[0]
        original=[struct.unpack("<6I",read(o32_va+i*24,24)) for i in range(count)]
        pe=pefile.PE(str(ROOT/"extracted/705md-rom/fs/Windows"/name))
        section=next(s for s in pe.sections if s.Name.rstrip(bytes([0]))==b".cerom")
        blob=section.get_data()[:section.Misc_VirtualSize]
        magic,version,header_size,n,obj_size,toc_offset=struct.unpack_from("<6I",blob)
        if (magic,version,header_size,obj_size)!=(0x31524543,1,24,44):raise ValueError((name,"unknown CEROM metadata"))
        expected_toc=(e32_va,o32_va,name_va,load_va,file_size,attrs,time_lo,time_hi,vsize)
        if struct.unpack_from("<9I",blob,toc_offset)!=expected_toc:raise ValueError((name,"TOC differs"))
        if n not in (0,count):raise ValueError((name,"object count differs"))
        for i in range(n):
            entry=struct.unpack_from("<11I",blob,header_size+i*obj_size)
            if entry[:6]!=original[i]:raise ValueError((name,i,"o32 original metadata differs"))
            sv,rva,psize,dataptr,realaddr,flags=original[i]
            if sum(o[1]==rva for o in original)<2 or not psize:continue
            if flags&0x2000:raise ValueError("Compressed alias requires separate LZX result lookup")
            raw=read(dataptr,psize)
            shadow=bool(entry[6])
            extracted=blob[entry[7]:entry[7]+entry[8]] if shadow else pe.get_data(rva,psize)
            if extracted!=raw:raise ValueError((name,i,"alias bytes differ"))
            checks.append(dict(module=name,section_index=i,rva=hex(rva),source_va=hex(dataptr),
                               source_bytes=psize,storage=".cerom shadow" if shadow else "PE primary",
                               sha256=hashlib.sha256(raw).hexdigest(),matched=True))
        modules.append(dict(name=name,original_objects=count,cerom_objects=n,toc_matched=True))
        pe.close()
    result=dict(source_nk_sha256=hashlib.sha256(source).hexdigest(),scope="Independent validation of extractor extension metadata and noncompressed shared-RVA payloads; no runtime relocation proof",
                modules_with_verified_toc=len(modules),shared_rva_records_matched=len(checks),modules=modules,checks=checks)
    (ROOT/"analysis/705md-rom-alias-verification.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(modules_with_verified_toc=len(modules),shared_rva_records_matched=len(checks),checks=checks),indent=2))


if __name__=="__main__":main()
