"""Produce one issue #74 test binary from an exact MAX33 input."""

import argparse
import hashlib
from pathlib import Path
import struct

import pefile


PATCHES = {
    "eco": (
        "MicomManager.exe",
        "b93cb55a66c843e1bb5ea34fd58642e451e6b07afcf9f8ccd1fbc762d627e629",
        (
            (0x1CC68, 0x240A0065, 0x240A0064),  # Two-byte value
            (0x1CC74, 0x24080067, 0x24080066),  # Trip
            (0x1CC80, 0x240B0068, 0x240B0067),  # Coaching
            (0x1CC8C, 0x2409006A, 0x24090069),  # Combined
            (0x22850, 0x1571011F, 0x1000011F),  # 4.x uses 'd' for Eco data
        ),
    ),
    "android-cover": (
        "Blue.exe",
        "e6d63ab65a0c06a2da0a14cfec60f9e98cd2db134b9dd84c2d7942bfbf0890db",
        (
            (0x32340C, 0x35080002, 0x35080003),
            (0x323410, 0xA0880048, 0x10000003),  # Branch to the padding
            (0x323414, 0x24020001, 0xA0880048),  # Store in delay slot
            (0x323420, 0, 0x90880049),
            (0x323424, 0, 0x35080080),
            (0x323428, 0, 0xA0880049),
            (0x32342C, 0, 0x03E00008),
            (0x323430, 0, 0x24020001),  # Return success in delay slot
        ),
    ),
}


def patch(raw, mode):
    name, digest, edits = PATCHES[mode]
    if hashlib.sha256(raw).hexdigest() != digest:
        raise ValueError(f"Expected the exact MAX33 {name} (SHA-256 {digest}).")
    image = pefile.PE(data=raw)
    output = bytearray(raw)
    for address, original, replacement in edits:
        offset = image.get_offset_from_rva(address - image.OPTIONAL_HEADER.ImageBase)
        if struct.unpack_from("<I", raw, offset)[0] != original:
            raise ValueError(f"Unexpected instruction at {address:#x}.")
        struct.pack_into("<I", output, offset, replacement)
    checksum_offset = image.OPTIONAL_HEADER.get_field_absolute_offset("CheckSum")
    checksum = pefile.PE(data=bytes(output)).generate_checksum()
    struct.pack_into("<I", output, checksum_offset, checksum)
    return bytes(output)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("mode", choices=PATCHES)
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    try:
        result = patch(args.input.read_bytes(), args.mode)
        with args.output.open("xb") as output:
            output.write(result)
    except (OSError, ValueError) as error:
        parser.exit(1, f"{error}\n")
    print(f"{hashlib.sha256(result).hexdigest()}  {args.output}")


if __name__ == "__main__":
    main()
