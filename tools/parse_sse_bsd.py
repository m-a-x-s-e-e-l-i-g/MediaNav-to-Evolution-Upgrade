"""Strict offline structural reader for the SSE BSD container, based on MIPS code.

Does not call SSE, modify firmware or interpret module-specific configuration values.
Real unit BSD files are absent; structural fixtures are synthetic.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

MARKER=0x0a0d0a00
MAGICS={bytes.fromhex("00010203"):"<",bytes.fromhex("00012203"):"<",
        bytes.fromhex("03020100"):">",bytes.fromhex("03220100"):">"}
WIDTHS={1:8,2:4,3:4,4:4,5:2,6:2,7:1,8:1,9:1,11:1,
        12:4,13:4,14:4,15:2,16:2,17:1,18:1}


class BsdError(ValueError):
    pass


class Reader:
    def __init__(self,data,endian):
        self.data=data;self.endian=endian;self.pos=0

    def take(self,n):
        if n<0 or n>len(self.data)-self.pos:
            raise BsdError(f"Truncated/bounded read at {self.pos:#x}, requested {n}")
        v=self.data[self.pos:self.pos+n];self.pos+=n
        return v

    def word(self):
        return struct.unpack(self.endian+"I",self.take(4))[0]


def parse_bsd(data):
    data=bytes(data)
    if len(data)<84 or data[:4]not in MAGICS:
        raise BsdError("Unsupported or truncated 84-byte BSD header")
    endian=MAGICS[data[:4]];r=Reader(data,endian)
    header=r.take(84)
    words=struct.unpack(endian+"5I",header[:20])
    version=words[2]
    if version>>24<=1:
        raise BsdError("BSD format-version high byte must exceed one")
    if r.word()!=0x02000000 or r.word()!=0:
        raise BsdError("Unexpected initial BSD tags")
    records=[]
    while r.pos<len(data):
        start=r.pos
        if r.word()!=MARKER:
            raise BsdError(f"Bad record marker at {start:#x}")
        name_len=r.word();ignored_word=r.word()
        metadata=[r.word()for _ in range(7)]
        payload_len=r.word();header_checksum=r.word()
        if name_len>=0xab:
            raise BsdError("Name exceeds the followed caller's 170-byte maximum")
        name_raw=r.take(name_len)
        normalized=struct.pack("<9I",name_len,0,*metadata)
        expected=(MARKER+payload_len+sum(normalized)+sum(name_raw))&0xffffffff
        if header_checksum!=expected:
            raise BsdError(f"Bad record-header checksum at {start:#x}")
        try:name=name_raw.split(b"\0")[0].decode("ascii")
        except UnicodeDecodeError as error:raise BsdError("Non-ASCII record name")from error
        datatype=metadata[1];dims=metadata[4:7]
        if datatype==10:
            raise BsdError("Datatype 10 is explicitly unsupported by the followed skip helper")
        if datatype not in WIDTHS:
            raise BsdError(f"Unknown BSD datatype {datatype}")
        schema=None;schema_checksum=None
        if datatype==11:
            schema_len=r.word();schema=r.take(schema_len)
            schema_checksum=r.take(1)[0]
            calculated=(sum(struct.pack("<I",schema_len))+sum(schema))&0xff
            if schema_checksum!=calculated:
                raise BsdError("Bad struct-schema byte checksum")
        payload_offset=r.pos
        payload=r.take(payload_len)
        if r.word()!=MARKER:
            raise BsdError(f"Bad payload trailer at {r.pos-4:#x}")
        trailer_checksum=r.word()
        calculated=(sum(payload)+(schema_checksum or 0))&0xffffffff
        if trailer_checksum!=calculated:
            raise BsdError(f"Bad payload checksum at {payload_offset:#x}")
        product=dims[0]
        for dimension in dims[1:]:
            if dimension==0:break
            product*=dimension
        dimension_size_consistent=(datatype==11 or product*WIDTHS[datatype]==payload_len)
        records.append(dict(offset=start,name=name,name_length=name_len,ignored_word=ignored_word,
                            metadata_words=metadata,struct_version=metadata[0],datatype=datatype,
                            dimensions=dims,payload_offset=payload_offset,payload_bytes=payload_len,
                            dimension_size_consistent=dimension_size_consistent,
                            schema_hex=None if schema is None else schema.hex(),
                            payload_sha256=hashlib.sha256(payload).hexdigest(),
                            header_checksum=hex(header_checksum),payload_checksum=hex(trailer_checksum)))
    return dict(endian="little"if endian=="<"else"big",header_words=words,
                format_version_word=hex(version),header_name=header[20:84].split(b"\0")[0].decode("ascii",errors="replace"),
                records=records)


def fixture(endian="<",structured=False):
    """Synthetic transport fixture, not a usable MediaNav audio configuration."""
    pack=lambda *v:struct.pack(endian+"I"*len(v),*v)
    name=b"SSE_TEST_Synthetic"
    payload=struct.pack(endian+"2h",-123,456)
    metadata=[1,11 if structured else 5,0,0,1 if structured else 2,0,0]
    header=pack(0x03020100,0,0x02000000,0,0)+b"offline fixture\0".ljust(64,b"\0")
    checksum=(MARKER+len(payload)+sum(struct.pack("<9I",len(name),0,*metadata))+sum(name))&0xffffffff
    prefix=pack(MARKER,len(name),0,*metadata,len(payload),checksum)+name
    schema=bytes([5,5]);schema_sum=(2+sum(schema))&0xff
    descriptor=pack(2)+schema+bytes([schema_sum])if structured else b""
    trailer=pack(MARKER,sum(payload)+(schema_sum if structured else 0))
    return header+pack(0x02000000,0)+prefix+descriptor+payload+trailer


def self_test():
    checks=0
    for endian in ("<",">"):
        for structured in (False,True):
            data=fixture(endian,structured);result=parse_bsd(data)
            assert len(result["records"])==1
            assert result["records"][0]["dimension_size_consistent"]
            for end in (1,83,91,len(data)-1):
                try:parse_bsd(data[:end])
                except BsdError:pass
                else:raise AssertionError("Truncation accepted")
            changed=bytearray(data);changed[-1]^=1
            try:parse_bsd(changed)
            except BsdError:pass
            else:raise AssertionError("Bad checksum accepted")
            checks+=1
    return checks


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument("path",nargs="?",type=Path)
    p.add_argument("--self-test",action="store_true");args=p.parse_args()
    if args.self_test:print(json.dumps({"synthetic_endian_and_schema_cases":self_test()}))
    if args.path:print(json.dumps(parse_bsd(args.path.read_bytes()),indent=2))
    elif not args.self_test:p.error("Supply a BSD file or --self-test")


if __name__=="__main__":main()
