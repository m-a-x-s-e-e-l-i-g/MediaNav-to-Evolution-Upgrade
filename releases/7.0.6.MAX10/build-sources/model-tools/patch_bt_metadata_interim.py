"""Keep the legacy interim metadata loop progressing and reject failed reads.

Five guarded in-place instruction edits; preserve frame, allocation, ACK and
payload cleanup. Does not implement full text fragment assembly or retries.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import pefile
from patch_bt_cover_attribute import BASE_SHA
from patch_bt_metadata_status import branch

EDITS=[
    # The original ignores 79160's result. Move its next LW into our delay slot,
    # and move the title branch over one instruction. Existing ADDIU t0,2 is a
    # valid delay slot on both paths; the title path overwrites t0 before use.
    (0x1fdd4,0x8fa4002c,branch(4,2,0,0x1fdd4,0x1ff04)),
    (0x1fdd8,0x10960027,0x8fa4002c),
    (0x1fddc,0,branch(4,4,22,0x1fddc,0x1fe78)),
    # Empty ID 2/3 fields advance the byte-sized attribute counter. Otherwise
    # the failed walker keeps the same empty field and loops forever.
    (0x1fe00,0x11200035,branch(4,9,0,0x1fe00,0x1fed0)),
    (0x1fe40,0x11200025,branch(4,9,0,0x1fe40,0x1fed0)),
]


def patch(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw);out=bytearray(raw);records=[]
    for site,before,after in EDITS:
        off=pe.get_offset_from_rva(site-pe.OPTIONAL_HEADER.ImageBase)
        assert struct.unpack_from('<I',raw,off)[0]==before,hex(site)
        struct.pack_into('<I',out,off,after)
        records.append(dict(address=hex(site),offset=off,before_hex=struct.pack('<I',before).hex(),
                            after_hex=struct.pack('<I',after).hex()))
    out=bytes(out)
    return out,dict(before_sha256=BASE_SHA,after_sha256=hashlib.sha256(out).hexdigest(),edits=records,
                    changed_bytes=sum(a!=b for a,b in zip(raw,out)),file_size_preserved=True,
                    frame_and_headers_unchanged=True,lgu_built=False,hardware_tested=False)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for n in ('input','output','report'):p.add_argument('--'+n,type=Path,required=True)
    a=p.parse_args()
    if a.output.exists() or a.report.exists():raise FileExistsError('Use fresh outputs')
    raw,r=patch(a.input.read_bytes())
    a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_bytes(raw)
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode())
    print(json.dumps(dict(edits=len(r['edits']),changed_bytes=r['changed_bytes'],lgu_built=False)))
