"""Offline decoder for the COM2 framing recovered from 7.0.5.MD MicomManager.

No serial-device opening or transmission. AB carries ULC status; A6 is a normal
acknowledgement without a verified flash result. This parser preserves raw bytes.
"""
import argparse
import json
from pathlib import Path
from functools import reduce
from operator import xor


def parse_capture(data: bytes):
    records=[]
    offset=0
    while offset<len(data):
        marker=data[offset]
        if marker==0xaa:
            if len(data)-offset<4:
                records.append(dict(offset=offset,kind="truncated_header",hex=data[offset:].hex()));break
            length=data[offset+3]
            end=offset+length+5
            if end>len(data):
                records.append(dict(offset=offset,kind="truncated_frame",expected_bytes=length+5,hex=data[offset:].hex()));break
            frame=data[offset:end]
            expected=reduce(xor,frame[:-1],0)
            records.append(dict(offset=offset,kind="AA",manager_nibble=frame[1]>>4,
                                type_nibble=frame[1]&15,command=frame[2],payload_hex=frame[4:-1].hex(),
                                payload_bytes=length,checksum=frame[-1],expected_checksum=expected,
                                checksum_valid=frame[-1]==expected,hex=frame.hex()))
            # Preserve declared framing even on checksum failure. Do not invent resynchronization.
            offset=end
        elif marker==0xab:
            if offset+2>len(data):
                records.append(dict(offset=offset,kind="truncated_AB",hex=data[offset:].hex()));break
            records.append(dict(offset=offset,kind="AB",value=data[offset+1],hex=data[offset:offset+2].hex()))
            offset+=2
        elif marker==0xa6:
            records.append(dict(offset=offset,kind="A6",hex="a6"));offset+=1
        else:
            start=offset
            while offset<len(data) and data[offset] not in (0xaa,0xab,0xa6):offset+=1
            records.append(dict(offset=start,kind="unframed_bytes",hex=data[start:offset].hex()))
    return records


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("capture",type=Path,help="Local raw-byte capture")
    args=parser.parse_args()
    print(json.dumps({"scope":"Offline 7.0.5.MD framing; no command semantics or device validation",
                      "records":parse_capture(args.capture.read_bytes())},indent=2))


if __name__=="__main__":main()
