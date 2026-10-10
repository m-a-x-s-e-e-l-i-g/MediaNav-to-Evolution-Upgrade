"""Read a local USBMusicResume.dat copy; no device access or native execution."""
import argparse
import json
import struct
from pathlib import Path

SIZE=0xc6c
TEXT={0x1c:"filename",0x224:"full_path",0x42c:"title",0x634:"album",0x83c:"artist",0xa44:"folder"}
WORDS={0x4:"directory_count",0x8:"directory_parent_lookup_using_track_index",0xc:"track_count",
    0x10:"track_index",0x14:"media_type",0x18:"position_seconds",0xc4c:"repeat",0xc50:"shuffle",
    0xc64:"file_size_low",0xc68:"volume_serial"}


def verify(raw):
    return len(raw)==SIZE and sum(raw[1:])!=0 and sum(raw[1:])%256==raw[0]


def parse(raw,allow_trailing=False):
    if len(raw)<SIZE or (len(raw)!=SIZE and not allow_trailing): raise ValueError("expected 3180 bytes")
    payload=raw[:SIZE]
    if not verify(payload): raise ValueError("invalid checksum or all-zero body")
    fields={name:struct.unpack_from("<I",payload,offset)[0] for offset,name in WORDS.items()}
    fields["disk_free_bytes"]=struct.unpack_from("<Q",payload,0xc54)[0]
    fields["disk_total_bytes"]=struct.unpack_from("<Q",payload,0xc5c)[0]
    strings={}
    for offset,name in TEXT.items():
        data=payload[offset:offset+520]
        terminated=any(data[i:i+2]==b"\0\0" for i in range(0,520,2))
        forced=name=="full_path"
        if forced: data=data[:518]+b"\0\0"
        end=next((i for i in range(0,520,2) if data[i:i+2]==b"\0\0"),520)
        strings[name]=dict(text=data[:end].decode("utf-16le",errors="surrogatepass"),
            original_terminated=terminated,loader_forces_last_unit_to_zero=forced)
    return dict(size=SIZE,trailing_bytes=len(raw)-SIZE,checksum=payload[0],fields=fields,strings=strings,
        unknown_header_hex=payload[1:4].hex(),binary_execution=False)


def fixture():
    raw=bytearray(SIZE)
    for offset,name in TEXT.items():
        value={"full_path":"\\MD\\Muziek\\Track.mp3","folder":"Muziek","filename":"Track.mp3"}.get(name,name)
        encoded=value.encode("utf-16le");raw[offset:offset+len(encoded)]=encoded
    struct.pack_into("<I",raw,0x10,4999)
    struct.pack_into("<II",raw,0xc4c,2,1)
    struct.pack_into("<QQII",raw,0xc54,2**40,2**41,123456,0x12345678)
    raw[0]=sum(raw[1:])%256
    return bytes(raw)


def self_test():
    raw=fixture(); parsed=parse(raw)
    assert parsed["fields"]["track_index"]==4999 and parsed["fields"]["disk_free_bytes"]==2**40
    assert parsed["strings"]["full_path"]["text"]=="\\MD\\Muziek\\Track.mp3"
    for i in range(SIZE):
        bad=bytearray(raw);bad[i]=(bad[i]+1)%256
        assert not verify(bad)
    rejected=0
    for bad in [raw[:-1],raw+b"tail",bytes(SIZE)]:
        try:parse(bad)
        except ValueError:rejected+=1
        else:raise AssertionError("invalid input accepted")
    assert parse(raw+b"tail",True)["trailing_bytes"]==4
    wrap=bytearray(SIZE);wrap[1]=255;wrap[2]=1;assert verify(wrap)
    collision=bytearray(raw);collision[1]=(collision[1]+1)%256;collision[2]=(collision[2]-1)%256
    assert verify(collision) and collision!=raw
    missing=bytearray(raw);missing[0x224:0x42c]=b"A\0"*260;missing[0]=sum(missing[1:])%256
    forced=parse(missing)["strings"]["full_path"]
    assert not forced["original_terminated"] and len(forced["text"])==259
    return dict(status="passed",single_byte_mutations=SIZE,rejected_inputs=rejected,
        trailing_prefix_cases=1,modulo_wrap_cases=1,checksum_collision_cases=1,forced_terminator_cases=1)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("path",nargs="?");parser.add_argument("--self-test",action="store_true")
    parser.add_argument("--allow-trailing",action="store_true",help="model native 3180-byte prefix read")
    args=parser.parse_args()
    if args.self_test: result=self_test()
    elif args.path: result=parse(Path(args.path).read_bytes(),args.allow_trailing)
    else: parser.error("provide a local path or --self-test")
    print(json.dumps(result,indent=2,ensure_ascii=True))


if __name__=="__main__":main()
