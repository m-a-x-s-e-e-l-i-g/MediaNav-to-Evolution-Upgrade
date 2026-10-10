"""Bounded offline ID3/ASF metadata inspection; never emulate unchecked native reads."""
import argparse
import hashlib
import json
import struct
import uuid
from pathlib import Path

ASF_HEADER=uuid.UUID("75b22630-668e-11cf-a6d9-00aa0062ce6c").bytes_le
ASF_CONTENT=uuid.UUID("75b22633-668e-11cf-a6d9-00aa0062ce6c").bytes_le
ASF_EXTENDED=uuid.UUID("d2d0a440-e307-11d2-97f0-00a0c95ea850").bytes_le
MAX=32*1024*1024


def syncsafe(raw):
    if any(b&128 for b in raw):raise ValueError("invalid synchsafe integer")
    value=0
    for b in raw:value=value*128+b
    return value


def text(payload):
    if not payload:return ""
    enc=payload[0];data=payload[1:]
    codec={0:"latin1",1:"utf-16",2:"utf-16be",3:"utf-8"}.get(enc)
    if codec is None:raise ValueError("unknown ID3 text encoding")
    return data.decode(codec,errors="replace").split("\0")[0]


def parse_id3(raw):
    if len(raw)<10 or raw[:3]!=b"ID3":raise ValueError("missing ID3 header")
    version=raw[3];flags=raw[5];length=syncsafe(raw[6:10])
    if version not in (2,3,4) or raw[4]==255:raise ValueError("unsupported ID3 version")
    if length>MAX or len(raw)<10+length:raise ValueError("truncated/oversize ID3 body")
    data=raw[10:10+length]
    if version<4 and flags&128:data=data.replace(b"\xff\0",b"\xff")
    cursor=0
    if flags&64:
        if version==2:raise ValueError("compressed v2.2 tag not supported")
        if len(data)<4:raise ValueError("short extended header")
        cursor=int.from_bytes(data[:4],"big")+4 if version==3 else syncsafe(data[:4])
        if cursor<4 or cursor>len(data):raise ValueError("invalid extended header size")
    frames=[];header=6 if version==2 else 10
    while cursor<len(data) and data[cursor]!=0:
        if len(frames)>=5000 or cursor+header>len(data):raise ValueError("invalid frame count/header")
        start=cursor;remaining=len(data)-start
        ident=data[cursor:cursor+(3 if version==2 else 4)].decode("ascii")
        if not all(c.isupper() or c.isdigit() for c in ident):raise ValueError("invalid frame ID")
        size_bytes=data[cursor+3:cursor+6] if version==2 else data[cursor+4:cursor+8]
        length=syncsafe(size_bytes) if version==4 else int.from_bytes(size_bytes,"big")
        native_length=int.from_bytes(size_bytes,"big")
        cursor+=header;end=cursor+length
        if not length or end>len(data):raise ValueError("truncated/empty frame")
        payload=data[cursor:end]
        frame_flags=0 if version==2 else int.from_bytes(data[start+8:start+10],"big")
        frame=dict(id=ident,bytes=length,flags=hex(frame_flags),sha256=hashlib.sha256(payload).hexdigest(),
            native_big_endian_length=native_length,
            native_unflagged_bounds=dict(preheader_remaining=remaining,
                check_passes=native_length<=remaining,
                remaining_after_header_and_payload=(remaining-header-native_length)&0xffffffff,
                final_frame_skipped=remaining==header+native_length))
        if ident.startswith("T") and frame_flags==0:
            frame["reference_text"]=text(payload)
        frames.append(frame);cursor=end
    return dict(format="ID3",version=version,flags=hex(flags),tag_body_bytes=syncsafe(raw[6:10]),
        frames=frames,padding_bytes=len(data)-cursor,binary_execution=False,
        footer_not_validated=version==4 and bool(flags&16),
        meaning="Bounded core reference parser; native size/bounds projection only covers unflagged frames",
        limitations=["Compression, grouping, per-frame unsynchronisation, CRC and footer validation are not implemented",
            "Text from flagged frames is not decoded; encoding errors are replaced, not treated as native behavior"])


def take(raw,cursor,length,end):
    if length<0 or cursor+length>end:raise ValueError("truncated ASF field")
    return raw[cursor:cursor+length],cursor+length


def parse_asf(raw):
    if len(raw)<30 or raw[:16]!=ASF_HEADER:raise ValueError("missing ASF header")
    total,count=struct.unpack_from("<QI",raw,16)
    if total<30 or total>MAX or total>len(raw) or count>4096:raise ValueError("invalid ASF header size/count")
    cursor=30;objects=[]
    for _ in range(count):
        if cursor+24>total:raise ValueError("truncated ASF object")
        guid=raw[cursor:cursor+16];length=struct.unpack_from("<Q",raw,cursor+16)[0]
        if length<24 or cursor+length>total:raise ValueError("invalid ASF object size")
        end=cursor+length;body=cursor+24
        obj=dict(guid=str(uuid.UUID(bytes_le=guid)),bytes=length)
        if guid==ASF_CONTENT:
            header,body=take(raw,body,10,end);lengths=struct.unpack("<5H",header)
            metadata={}
            for name,size in zip(["title","author","copyright","description","rating"],lengths):
                value,body=take(raw,body,size,end)
                if size%2:raise ValueError("odd UTF16 content length")
                metadata[name]=value.decode("utf-16le",errors="replace").rstrip("\0")
            obj["content"]=metadata
        elif guid==ASF_EXTENDED:
            header,body=take(raw,body,2,end);entries=struct.unpack("<H",header)[0]
            if entries>4096:raise ValueError("too many descriptors")
            desc=[]
            for _ in range(entries):
                header,body=take(raw,body,2,end);name_length=struct.unpack("<H",header)[0]
                name,body=take(raw,body,name_length,end)
                if name_length%2:raise ValueError("odd UTF16 descriptor name")
                header,body=take(raw,body,4,end);kind,value_length=struct.unpack("<HH",header)
                value,body=take(raw,body,value_length,end)
                entry=dict(name=name.decode("utf-16le",errors="replace").rstrip("\0"),type=kind,
                    bytes=value_length,native_name_read_bytes=min(name_length,100),
                    native_name_copy_bytes=name_length,native_name_destination_bytes=256,
                    native_name_overruns_destination=name_length>256)
                if kind==0:
                    if value_length%2:raise ValueError("odd UTF16 descriptor value")
                    entry["text"]=value.decode("utf-16le",errors="replace").rstrip("\0")
                desc.append(entry)
            obj["descriptors"]=desc
        objects.append(obj);cursor=end
    return dict(format="ASF",header_bytes=total,object_count=count,native_count_allowed=1<=count<=16,
        objects=objects,binary_execution=False,meaning="Bounded reference layout, not the native short-read/stack behavior")


def self_test():
    def syn(n):return bytes((n>>s)&127 for s in (21,14,7,0))
    def tag(v,payload,padding=b""):
        frame=b"TIT2"+(syn(len(payload)) if v==4 else len(payload).to_bytes(4,"big"))+b"\0\0"+payload
        return b"ID3"+bytes([v,0,0])+syn(len(frame+padding))+frame+padding
    parsed=parse_id3(tag(3,b"\3Titel"));assert parsed["frames"][0]["reference_text"]=="Titel"
    assert parsed["frames"][0]["native_unflagged_bounds"]["final_frame_skipped"]
    parsed=parse_id3(tag(4,b"\3"+b"A"*127,b"\0"*16));f=parsed["frames"][0]
    assert f["bytes"]==128 and f["native_big_endian_length"]==256
    assert not f["native_unflagged_bounds"]["check_passes"]
    utf=b"\1"+"\ufeffTitel".encode("utf-16le")
    assert parse_id3(tag(3,utf,b"\0"*8))["frames"][0]["reference_text"]=="Titel"
    assert parse_id3(tag(3,b"\2"+"Titel".encode("utf-16be")))["frames"][0]["reference_text"]=="Titel"
    name=("WM/AlbumTitle\0").encode("utf-16le");value="Album\0".encode("utf-16le")
    body=struct.pack("<HH",1,len(name))+name+struct.pack("<HH",0,len(value))+value
    obj=ASF_EXTENDED+struct.pack("<Q",24+len(body))+body
    raw=ASF_HEADER+struct.pack("<QI2B",30+len(obj),1,1,2)+obj
    parsed=parse_asf(raw);assert parsed["objects"][0]["descriptors"][0]["text"]=="Album"
    rejected=0
    for bad,reader in [(tag(3,b"\3T")[:-1],parse_id3),(b"ID3\4\0\0\xff\0\0\0",parse_id3),
            (raw[:-1],parse_asf),(ASF_HEADER+struct.pack("<QI2B",29,1,1,2),parse_asf)]:
        try:reader(bad)
        except ValueError:rejected+=1
        else:raise AssertionError("invalid input accepted")
    return dict(status="passed",id3_fixtures=4,asf_fixtures=1,rejected_inputs=rejected)


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument("path",nargs="?");ap.add_argument("--self-test",action="store_true")
    args=ap.parse_args()
    if args.self_test:result=self_test()
    elif args.path:
        with Path(args.path).open("rb") as stream:raw=stream.read(MAX+1)
        result=parse_id3(raw) if raw.startswith(b"ID3") else parse_asf(raw)
    else:ap.error("provide a local media file or --self-test")
    print(json.dumps(result,indent=2,ensure_ascii=True))


if __name__=="__main__":main()
