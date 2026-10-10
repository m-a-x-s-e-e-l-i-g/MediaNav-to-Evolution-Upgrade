"""Bounded PNG metadata reader: chunk CRC, text/profile decompression and field sizes.

Does not decode IDAT, validate ICC internals, interpret XMP or execute ROM code.
"""
import argparse
import hashlib
import json
import struct
import zlib
from pathlib import Path
from parse_png_image import SIGNATURE

MAX_BYTES=32*1024*1024
MAX_METADATA=1024*1024
MAX_TOTAL_TEXT_PROFILE=8*1024*1024


def keyword(raw):
    if not 1<=len(raw)<=79 or raw[:1]==b" " or raw[-1:]==b" " or b"  " in raw:raise ValueError("invalid PNG keyword")
    if any(not (32<=b<=126 or 161<=b<=255) for b in raw):raise ValueError("invalid keyword character")
    return raw.decode("latin-1")


def split_keyword(data):
    name,sep,rest=data.partition(b"\0")
    if not sep:raise ValueError("missing keyword separator")
    return keyword(name),rest


def inflate_bounded(data):
    stream=zlib.decompressobj();out=stream.decompress(data,MAX_METADATA+1)
    if len(out)>MAX_METADATA or not stream.eof or stream.unused_data or stream.unconsumed_tail:raise ValueError("invalid/oversize compressed metadata")
    return out


def chunks(raw):
    if len(raw)>MAX_BYTES or raw[:8]!=SIGNATURE:raise ValueError("missing/oversize PNG")
    at=8;result=[]
    while at<len(raw):
        if len(result)>=5000 or at+12>len(raw):raise ValueError("invalid chunk header")
        size,kind=struct.unpack_from(">I4s",raw,at);end=at+12+size
        if size>0x7fffffff or end>len(raw):raise ValueError("invalid chunk extent")
        data=raw[at+8:end-4]
        if zlib.crc32(kind+data)!=struct.unpack_from(">I",raw,end-4)[0]:raise ValueError("CRC mismatch")
        if not all(65<=b<=90 or 97<=b<=122 for b in kind):raise ValueError("invalid chunk type")
        result.append((kind,data,at));at=end
        if kind==b"IEND":
            if size or at!=len(raw):raise ValueError("invalid IEND/trailing data")
            break
    if not result or result[0][0]!=b"IHDR" or len(result[0][1])!=13 or result[-1][0]!=b"IEND":raise ValueError("missing PNG framing")
    if sum(k==b"IHDR" for k,_,_ in result)!=1:raise ValueError("duplicate IHDR")
    return result


def parse_metadata(raw):
    entries=[];text=[];counts={};header=None;palette_count=0;total_text_profile=0
    for kind,data,at in chunks(raw):
        name=kind.decode("ascii");counts[name]=counts.get(name,0)+1
        if name=="IHDR":header=struct.unpack(">IIBBBBB",data);continue
        if name=="PLTE":
            if not data or len(data)%3 or len(data)>768:raise ValueError("invalid PLTE")
            palette_count=len(data)//3;continue
        item=dict(type=name,bytes=len(data),offset=at,sha256=hashlib.sha256(data).hexdigest())
        if name in ["tEXt","zTXt"]:
            key,rest=split_keyword(data)
            if name=="zTXt":
                if not rest or rest[0]!=0:raise ValueError("unsupported zTXt compression")
                rest=inflate_bounded(rest[1:])
            if len(rest)>MAX_METADATA or b"\0" in rest:raise ValueError("invalid/oversize PNG text")
            total_text_profile+=len(rest)
            if total_text_profile>MAX_TOTAL_TEXT_PROFILE:raise ValueError("total text/profile budget exceeded")
            value=rest.decode("latin-1");item.update(keyword=key,text=value);text.append(dict(keyword=key,text=value,type=name))
        elif name=="iTXt":
            key,rest=split_keyword(data)
            if len(rest)<2 or rest[0] not in [0,1] or rest[1]!=0:raise ValueError("unsupported iTXt compression")
            flag=rest[0];language,sep,rest=rest[2:].partition(b"\0")
            if not sep:raise ValueError("missing iTXt language separator")
            translated,sep,value=rest.partition(b"\0")
            if not sep:raise ValueError("missing translated keyword separator")
            if flag:value=inflate_bounded(value)
            if len(value)>MAX_METADATA or b"\0" in value:raise ValueError("invalid iTXt text")
            total_text_profile+=len(value)
            if total_text_profile>MAX_TOTAL_TEXT_PROFILE:raise ValueError("total text/profile budget exceeded")
            item.update(keyword=key,language=language.decode("ascii"),translated_keyword=translated.decode("utf-8"),
                text=value.decode("utf-8"),compressed=bool(flag));text.append({k:item[k] for k in ["keyword","text","type"]})
        elif name=="iCCP":
            key,rest=split_keyword(data)
            if not rest or rest[0]!=0:raise ValueError("unsupported iCCP compression")
            profile=inflate_bounded(rest[1:]);total_text_profile+=len(profile)
            if total_text_profile>MAX_TOTAL_TEXT_PROFILE:raise ValueError("total text/profile budget exceeded")
            item.update(profile_name=key,profile_bytes=len(profile),profile_sha256=hashlib.sha256(profile).hexdigest(),icc_internals_validated=False)
        elif name=="pHYs":
            if len(data)!=9:raise ValueError("invalid pHYs size")
            x,y,unit=struct.unpack(">IIB",data)
            if unit not in [0,1]:raise ValueError("invalid pHYs unit")
            item.update(x=x,y=y,unit=unit)
            if unit:item.update(dpi_x=x*254/10000,dpi_y=y*254/10000)
        elif name=="cHRM":
            if len(data)!=32:raise ValueError("invalid cHRM size")
            item["scaled_coordinates"]=list(struct.unpack(">8I",data))
        elif name=="gAMA":
            if len(data)!=4 or not int.from_bytes(data,"big"):raise ValueError("invalid gamma")
            item["gamma_times_100000"]=int.from_bytes(data,"big")
        elif name=="sRGB":
            if len(data)!=1 or data[0]>3:raise ValueError("invalid sRGB intent")
            item["rendering_intent"]=data[0]
        elif name=="sBIT":
            expected={0:1,2:3,3:3,4:2,6:4}.get(header[3]);maximum=8 if header[3]==3 else header[2]
            if len(data)!=expected or any(not 1<=v<=maximum for v in data):raise ValueError("invalid sBIT")
            item["significant_bits"]=list(data)
        elif name=="hIST":
            if not palette_count or len(data)!=palette_count*2:raise ValueError("invalid hIST size")
            item["frequencies"]=list(struct.unpack(">"+"H"*palette_count,data))
        elif name=="sPLT":
            key,rest=split_keyword(data)
            if not rest or rest[0] not in [8,16]:raise ValueError("invalid sPLT depth")
            size=6 if rest[0]==8 else 10
            if len(rest)<1+size or (len(rest)-1)%size:raise ValueError("invalid sPLT entries")
            item.update(palette_name=key,sample_depth=rest[0],entries=(len(rest)-1)//size)
        elif name=="tIME":
            if len(data)!=7:raise ValueError("invalid tIME size")
            year,month,day,hour,minute,second=struct.unpack(">H5B",data)
            if not 1<=month<=12 or not 1<=day<=31 or hour>23 or minute>59 or second>60:raise ValueError("invalid tIME fields")
            item.update(year=year,month=month,day=day,hour=hour,minute=minute,second=second)
        else:continue
        entries.append(item)
    return dict(binary_execution=False,source_sha256=hashlib.sha256(raw).hexdigest(),chunk_counts=counts,metadata=entries,text=text,
        limitations=["IDAT and full PNG acceptance are not validated by this metadata reader",
            "ICC internals, XMP semantics and color transforms are not interpreted",
            "tIME checks field ranges but not complete calendar validity; keyword/text APIs are stricter than the native routines"])


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument("path");args=ap.parse_args()
    with Path(args.path).open("rb") as stream:raw=stream.read(MAX_BYTES+1)
    print(json.dumps(parse_metadata(raw),indent=2,ensure_ascii=False))


if __name__=="__main__":main()
