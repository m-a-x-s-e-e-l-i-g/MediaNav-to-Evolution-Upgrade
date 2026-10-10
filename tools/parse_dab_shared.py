"""Decode known fields of offline DAB shared-memory snapshots; no live access."""
import argparse
import json
import struct
from pathlib import Path

SIZES = dict(station=0x66c,presets=0x4d14,scan=0x714c,epg=0x19cc)


def text_field(data,offset,size):
    raw = data[offset:offset+size]
    end = next((i for i in range(0,len(raw)-1,2) if raw[i:i+2]==b"\0\0"),len(raw))
    try:
        text = raw[:end].decode("utf-16le")
        valid = True
    except UnicodeDecodeError:
        text,valid = None,False
    return dict(text=text,utf16_valid=valid,terminated=end<len(raw),raw_hex=raw.hex())


def station_record(data):
    if len(data) != 0x66c:
        raise ValueError("Station record must be 1644 bytes")
    return dict(ensemble_label=text_field(data,0,0x22),station_label=text_field(data,0x24,0x22),
                pty=struct.unpack_from("<I",data,0x22c)[0],frequency_id=text_field(data,0x230,10),
                dls=text_field(data,0x244,0x102),eid=struct.unpack_from("<H",data,0x654)[0],
                sid=struct.unpack_from("<I",data,0x658)[0],frequency_raw=struct.unpack_from("<I",data,0x65c)[0],
                subchannel_id=data[0x660],channel_index=struct.unpack_from("<i",data,0x664)[0],
                raw_hex=data.hex())


def scan_record(data):
    return dict(eid=struct.unpack_from("<H",data)[0],sid=struct.unpack_from("<I",data,4)[0],
                subchannel_id=data[8],station_label=text_field(data,0xa,0x22),
                ensemble_label=text_field(data,0x2c,0x22),pty=struct.unpack_from("<I",data,0x50)[0],
                frequency_id=text_field(data,0x54,10),frequency_raw=struct.unpack_from("<I",data,0x60)[0],
                channel_index=data[0x64],unresolved_source_bytes={hex(i):data[i]for i in range(0x65,0x6a)},
                duplicate_source_pty=struct.unpack_from("<I",data,0x6c)[0],
                source_offset_14=data[0x70],raw_hex=data.hex())


def parse_snapshot(data,kind,limit=20):
    if len(data) != SIZES[kind]:
        raise ValueError(f"Expected {SIZES[kind]} bytes for {kind}, got {len(data)}")
    if limit < 0:
        raise ValueError("Negative display limit")
    if kind == "station":
        return station_record(data)
    if kind == "presets":
        selection = struct.unpack_from("<i",data,0x4d10)[0]
        return dict(selected_index=selection,selection_in_documented_range=-1<=selection<12,
                    records=[station_record(data[i*0x66c:(i+1)*0x66c])for i in range(12)])
    count_offset,stride,capacity = (0x7148,0x74,250) if kind=="scan" else (0x19c8,0x42,100)
    count = struct.unpack_from("<i",data,count_offset)[0]
    if not 0 <= count <= capacity:
        return dict(raw_count=count,count_valid=False,capacity=capacity,records=[])
    records=[]
    for i in range(min(count,limit)):
        raw=data[i*stride:(i+1)*stride]
        record=scan_record(raw) if kind=="scan" else dict(
            unresolved_words=[struct.unpack_from("<H",raw,j)[0]for j in (0,2,6,8,10)],
            label=text_field(raw,16,50),raw_hex=raw.hex())
        records.append(record)
    return dict(raw_count=count,count_valid=True,capacity=capacity,displayed_records=len(records),
                omitted_records=count-len(records),records=records)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("kind",choices=SIZES)
    parser.add_argument("snapshot",type=Path)
    parser.add_argument("--limit",type=int,default=20)
    args=parser.parse_args()
    print(json.dumps(parse_snapshot(args.snapshot.read_bytes(),args.kind,args.limit),indent=2,ensure_ascii=False))


if __name__=="__main__":main()
