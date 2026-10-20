"""Patch the full MAX31 LGU for iPhone final cover-art packets; no firmware is run."""
import argparse
import hashlib
import io
from pathlib import Path
import struct
import zipfile
import lgu_repack as L

BASE_SHA = '521e9192c1dea4ae4d64d5346db0cc441c638e6156b7227af8a64eac162979b3'
BASE_BLUE_SHA = '8dfb6f7c3be0bdf2c2f6e15f19e5cd44712ca508d1f01d43b0fb4d5829b492a0'
PATCHED_BLUE_SHA = 'e6d63ab65a0c06a2da0a14cfec60f9e98cd2db134b9dd84c2d7942bfbf0890db'
BLUE = 'upgrade/Storage Card/System/Blue.exe'
VER = 'upgrade/Storage Card/System/Version_Info.txt'
BASE_VERSION = '7.0.6.MAX31'
NOP = bytes(4)
EDITS = [(0x12feb4, 0x15150043, 'repeated Length header must match'),
         (0x12fee4, 0x11000037, 'final packet needs End-of-Body'),
         (0x12fefc, 0x16950031, 'collected bytes must equal declared Length')]
COPY_SHIFT = 0x198cd0 - 0x12fed0


def sha(data):
    return hashlib.sha256(data).hexdigest()


def fix_checksum(data):
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    checksum = pe + 4 + 20 + 64
    struct.pack_into('<I', data, checksum, L.pe_checksum(bytes(data), checksum))


def patch_blue(original):
    if sha(original) != BASE_BLUE_SHA:
        raise ValueError('Blue.exe is not the MAX31 baseline')
    blue = bytearray(original)
    for shift in (0, COPY_SHIFT):
        for offset, word, _ in EDITS:
            at = offset + shift
            if struct.unpack_from('<I', blue, at)[0] != word:
                raise ValueError(f'Unexpected instruction at file offset {at:#x}')
            blue[at:at+4] = NOP
    fix_checksum(blue)
    if sha(blue) != PATCHED_BLUE_SHA:
        raise ValueError('Unexpected patched Blue.exe hash')
    return bytes(blue)


def patch_package(raw, version=None):
    if sha(raw) != BASE_SHA:
        raise ValueError('Source is not the exact published MAX31 upgrade.lgu')
    if version is not None:
        L.version_bytes(version)
    z = L.unpack(raw)
    with zipfile.ZipFile(io.BytesIO(z)) as archive:
        replace = {BLUE: patch_blue(L.read_member(archive, BLUE))}
    if version is not None:
        replace[VER] = L.version_bytes(version)
    return L.pack(raw, L.rebuild(z, replace), version)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--version', help='optional maintainer-selected package label')
    args = parser.parse_args()
    if args.output.exists():
        parser.error('Output already exists; choose a new path')
    result = patch_package(args.source.read_bytes(), args.version)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open('xb') as output:
        output.write(result)
    print(f'{args.output} {sha(result)}')


if __name__ == '__main__':
    main()
