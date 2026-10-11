"""Check all eight track-UID bytes before deciding a UID is empty.

The original notification and final metadata handlers compare only byte zero
with their eight-byte zero locals, dropping nonzero UIDs with a zero first byte.
Two guarded immediate edits; request, publication and allocation paths retained.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import pefile
from patch_bt_cover_attribute import BASE_SHA

SITES=(0x1fae4,0x20084)


def patch(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw);out=bytearray(raw);rows=[]
    for site in SITES:
        off=pe.get_offset_from_rva(site-pe.OPTIONAL_HEADER.ImageBase)
        assert struct.unpack_from('<I',raw,off)[0]==0x24060001,hex(site)
        struct.pack_into('<I',out,off,0x24060008)
        rows.append(dict(address=hex(site),offset=off,before_hex='01000624',after_hex='08000624'))
    out=bytes(out)
    return out,dict(before_sha256=BASE_SHA,after_sha256=hashlib.sha256(out).hexdigest(),edits=rows,
                    changed_bytes=2,file_size_preserved=True,frame_and_headers_unchanged=True,
                    lgu_built=False,hardware_tested=False)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('input','output','report'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args()
    if a.output.exists() or a.report.exists():raise FileExistsError('Use fresh output paths')
    raw,r=patch(a.input.read_bytes());a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_bytes(raw)
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode())
    print(json.dumps(dict(edits=len(r['edits']),changed_bytes=2,lgu_built=False)))
