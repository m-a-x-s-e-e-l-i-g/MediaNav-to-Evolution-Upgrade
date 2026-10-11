"""Disable AppMain's AHA feature gate on the exact complete MAX05 baseline.

Keep registry reads, other source flags, resources, layout and all control flow.
Only the AHA_EN result store changes to store zero. No package is built here.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

import pefile

BASE_SHA = 'b34676225ad428426b417cec33c30f7e18e56aeeb6e438900c01dc022225fcd9'
SITE, BEFORE, AFTER = 0xd4974, 0xae422460, 0xae402460


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact complete MAX05 AppMain.exe')
    pe=pefile.PE(data=raw)
    at=pe.get_offset_from_rva(SITE-pe.OPTIONAL_HEADER.ImageBase)
    # This is the delay slot of the following RES_EN read, after AHA_EN returned.
    context=struct.pack('<IIIIIII', 0x3c080017, 0x24070000, 0x250612c8,
                        0x02202825, 0x02602025, 0x0c04de9a, BEFORE)
    assert raw[at-24:at+4] == context
    out=bytearray(raw); out[at:at+4]=struct.pack('<I',AFTER); out=bytes(out)
    assert len(out)==len(raw)
    assert [i for i,(a,b) in enumerate(zip(raw,out)) if a!=b] == [at+2]
    return out,dict(schema=1, before_sha256=BASE_SHA, after_sha256=hashlib.sha256(out).hexdigest(),
                    edits=[dict(address=hex(SITE), offset=at, before_hex=struct.pack('<I',BEFORE).hex(),
                                after_hex=struct.pack('<I',AFTER).hex(), bytes=4,
                                purpose='Store AHA feature disabled regardless of AHA_EN registry value')],
                    changed_bytes=1, file_size_preserved=True, branches_calls_headers_relocations_unchanged=True,
                    hardware_tested=False, lgu_built=False)


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--recipe',type=Path,required=True)
    args=parser.parse_args()
    if args.output.exists() or args.recipe.exists(): raise FileExistsError('Use fresh output paths')
    out, recipe=patch(args.input.read_bytes())
    for p in (args.output,args.recipe):p.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_bytes(out)
    args.recipe.write_bytes((json.dumps(recipe,indent=2)+'\n').encode())
    print(json.dumps(recipe,indent=2))
