"""Read three confirmed UTF-8 metadata fields from an offline BlueEarth snapshot."""
import argparse
import json
from pathlib import Path

SIZE=0x13d620
META=0xcf0e8
META_SIZE=0x104


def decode(data):
    if len(data)!=SIZE:raise ValueError(f"Expected a full BlueEarth snapshot of {SIZE} bytes, received {len(data)}")
    block=data[META:META+META_SIZE]
    fields={name:block[offset:offset+50].split(bytes([0]),1)[0].decode("utf-8",errors="replace")
            for name,offset in (("title",0),("album",50),("artist",100))}
    return dict(schema="MediaNav-7.0.5.MD-BlueEarth-static-v1",scope="Partial static reconstruction; no live validation",
                **fields,unknown_metadata_tail_hex=block[150:].hex())


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument("dump",type=Path);args=parser.parse_args()
    print(json.dumps(decode(args.dump.read_bytes()),ensure_ascii=False,indent=2))


if __name__=="__main__":main()
