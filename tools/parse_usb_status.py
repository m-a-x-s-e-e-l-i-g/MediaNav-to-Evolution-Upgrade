"""Decode an offline 7.0.5.MD USB status dump; does not connect to or control a unit."""
import argparse
import json
from pathlib import Path
import struct

SIZE=0xe56
TEXT_BYTES=0x208
TEXT_FIELDS={"unknown_text_region_1":0x6,"title":0x20e,"artist":0x416,"album":0x61e,
             "unknown_text_region_5":0x826,"path":0xa2e,"filename":0xc36}
DWORD_FIELDS={"play_item_index":0xe3e,"repeat_mode_raw":0xe42,"shuffle_raw":0xe46,
              "play_state_raw":0xe4a,"cover_bitmap_handle_raw":0xe4e,"unknown_last_dword":0xe52}


def decode(data):
    if len(data)!=SIZE:raise ValueError(f"Expected exactly {SIZE} bytes, received {len(data)}")
    result={"schema":"MediaNav-7.0.5.MD-static-v1", "scope":"Partial static reconstruction; no runtime confirmation",
            "current_time":{"minutes":data[0],"seconds":data[1],"hours":data[2]},
            "total_time":{"minutes":data[3],"seconds":data[4],"hours":data[5]}}
    for name,offset in TEXT_FIELDS.items():
        raw=data[offset:offset+TEXT_BYTES]
        end=next((i for i in range(0,len(raw),2) if raw[i:i+2]==b"\0\0"),len(raw))
        result[name]=raw[:end].decode("utf-16le",errors="replace")
    result.update({name:struct.unpack_from("<I",data,offset)[0] for name,offset in DWORD_FIELDS.items()})
    result["cover_bitmap_note"]="Process-local GDI handle; not image bytes or a portable pointer"
    return result


def main():
    parser=argparse.ArgumentParser();parser.add_argument("dump",type=Path);args=parser.parse_args()
    print(json.dumps(decode(args.dump.read_bytes()),ensure_ascii=False,indent=2))


if __name__=="__main__":main()
