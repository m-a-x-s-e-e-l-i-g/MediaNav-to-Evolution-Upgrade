"""Reject failed/empty final Bluetooth metadata before replacing current text.

In-place native repair on exact MAX05 Blue.exe. Cleanup and continuation state
still execute. Does not implement missing-notification or request retry recovery.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import pefile

from patch_bt_cover_attribute import BASE_SHA


def branch(op,rs,rt,site,target):
    delta=(target-site-4)//4
    assert -32768<=delta<=32767 and target%4==0
    return op<<26|rs<<21|rt<<16|(delta&65535)


EDITS = [
    # Two aligned DWORD stores replace eight byte stores to the zero UID local.
    # Reuse the freed instructions to check result/supplier as one aligned DWORD.
    (0x1fa9c,0xa3a00140,0xafa00140),
    (0x1faa4,0xa3a00141,0xafa00144),
    (0x1faa8,0xa3a00142,0x8e080014),
    (0x1faac,0xa3a00143,0x3c090011),
    (0x1fab0,0xa3a00144,0x35298000),
    (0x1fab4,0xa3a00145,branch(5,8,9,0x1fab4,0x1fca4)),
    (0x1fab8,0xa3a00146,0x24170001),
    (0x1fabc,0xa3a00147,0),
    # Empty and undecodable final attribute lists must not overwrite text with
    # the freshly zeroed 260-byte local. Use the existing exact cleanup path.
    (0x1fb28,0x11000057,branch(4,8,0,0x1fb28,0x1fca4)),
    (0x1fb6c,0x10400046,branch(4,2,0,0x1fb6c,0x1fca4)),
]


def patch(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:
        raise ValueError('Expected exact complete MAX05 Blue.exe')
    pe=pefile.PE(data=raw);out=bytearray(raw);records=[]
    for site,before,after in EDITS:
        at=pe.get_offset_from_rva(site-pe.OPTIONAL_HEADER.ImageBase)
        old,new=struct.pack('<I',before),struct.pack('<I',after)
        assert raw[at:at+4]==old,hex(site)
        out[at:at+4]=new
        records.append(dict(address=hex(site),offset=at,before_hex=old.hex(),after_hex=new.hex()))
    out=bytes(out)
    assert len(out)==len(raw)
    return out,dict(schema=1,before_sha256=BASE_SHA,after_sha256=hashlib.sha256(out).hexdigest(),
                    edits=records,changed_bytes=sum(x!=y for x,y in zip(raw,out)),
                    file_size_preserved=True,headers_relocations_unchanged=True,
                    hardware_tested=False,lgu_built=False)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for field in ('input','output','recipe'):p.add_argument('--'+field,type=Path,required=True)
    a=p.parse_args()
    if a.output.exists() or a.recipe.exists():raise FileExistsError('Use fresh output paths')
    out,recipe=patch(a.input.read_bytes())
    for path in (a.output,a.recipe):path.parent.mkdir(parents=True,exist_ok=True)
    a.output.write_bytes(out);a.recipe.write_bytes((json.dumps(recipe,indent=2)+'\n').encode())
    print(json.dumps(dict(edits=len(recipe['edits']),changed_bytes=recipe['changed_bytes'],lgu_ready=False)))
