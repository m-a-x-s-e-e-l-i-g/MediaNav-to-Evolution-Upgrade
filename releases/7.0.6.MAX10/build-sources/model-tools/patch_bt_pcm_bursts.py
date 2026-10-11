"""Allow bounded PCM bursts without changing MAX05's fast restart threshold.

Use eight of the existing 25 headers instead of four. No additional allocation,
block-size change, startup delay, thread, codec or wave driver change.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import pefile
from patch_bt_cover_attribute import BASE_SHA

SITE=0x26f24
BEFORE,AFTER=0x2d090004,0x2d090008


def patch(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:
        raise ValueError('Expected exact complete MAX05 Blue.exe')
    pe=pefile.PE(data=raw);at=pe.get_offset_from_rva(SITE-pe.OPTIONAL_HEADER.ImageBase)
    assert raw[at:at+4]==struct.pack('<I',BEFORE)
    assert pe.get_data(0x26ef4-pe.OPTIONAL_HEADER.ImageBase,4)==bytes.fromhex('0200092d')
    out=bytearray(raw);out[at:at+4]=struct.pack('<I',AFTER);out=bytes(out)
    assert [i for i,(a,b) in enumerate(zip(raw,out)) if a!=b]==[at]
    return out,dict(schema=1,before_sha256=BASE_SHA,after_sha256=hashlib.sha256(out).hexdigest(),
                    edits=[dict(address=hex(SITE),offset=at,before_hex=struct.pack('<I',BEFORE).hex(),
                                after_hex=struct.pack('<I',AFTER).hex())],changed_bytes=1,
                    block_bytes=4096,restart_buffers=2,queue_limit=8,available_headers=25,
                    allocation_size_unchanged=True,headers_relocations_unchanged=True,
                    hardware_tested=False,lgu_built=False)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for field in ('input','output','recipe'):p.add_argument('--'+field,type=Path,required=True)
    a=p.parse_args()
    if a.output.exists() or a.recipe.exists():raise FileExistsError('Use fresh output paths')
    out,recipe=patch(a.input.read_bytes())
    for path in (a.output,a.recipe):path.parent.mkdir(parents=True,exist_ok=True)
    a.output.write_bytes(out);a.recipe.write_bytes((json.dumps(recipe,indent=2)+'\n').encode())
    print(json.dumps(recipe,indent=2))
