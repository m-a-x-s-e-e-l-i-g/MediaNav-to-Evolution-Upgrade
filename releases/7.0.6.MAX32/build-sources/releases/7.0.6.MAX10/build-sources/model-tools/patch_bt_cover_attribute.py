"""Experimental native attribute-8 serialization support; no feature advertisement or UI hook."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import pefile

BASE_SHA = '2b1eb3adee76a7867d1fd9d0a6c376f41d2b7a42cf4b54834e9ebc153854ed51'
SITE = 0x6f680


def patch(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected the exact MAX04/MAX05 Blue.exe; other inputs refused')
    pe = pefile.PE(data=raw)
    offset = pe.get_offset_from_rva(SITE-pe.OPTIONAL_HEADER.ImageBase)
    word = struct.unpack_from('<I', raw, offset)[0]
    if word != 0x2de80007:
        raise ValueError('Unexpected attribute-loop instruction')
    candidate = bytearray(raw)
    struct.pack_into('<I', candidate, offset, 0x2de80008)
    candidate = bytes(candidate)
    if [i for i, (a, b) in enumerate(zip(raw, candidate)) if a != b] != [offset]:
        raise ValueError('Undeclared binary edits')
    return candidate, dict(base_sha256=BASE_SHA, sha256=hashlib.sha256(candidate).hexdigest(),
        site=hex(SITE), offset=offset, before=hex(word), after='0x2de80008', changed_bytes=1,
        feature_enabled=False, requests_changed=False, avrcp_version_changed=False,
        image_transport_added=False, ui_changed=False, hardware_tested=False, native_executed=False)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--recipe', type=Path, required=True)
    args = parser.parse_args()
    if args.output.resolve() == args.input.resolve() or args.recipe.resolve() == args.input.resolve():
        raise ValueError('Input must never be overwritten')
    if args.output.exists() or args.recipe.exists() or args.output.resolve() == args.recipe.resolve():
        raise FileExistsError('Use distinct fresh output/recipe paths')
    before = args.input.read_bytes()
    candidate, recipe = patch(before)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.recipe.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(candidate)
    args.recipe.write_text(json.dumps(recipe, indent=2)+'\n', encoding='utf-8')
    if args.input.read_bytes() != before or args.output.read_bytes() != candidate:
        raise ValueError('Input/output changed while writing')
    print(json.dumps(recipe, indent=2))
