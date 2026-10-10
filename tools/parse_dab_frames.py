"""Decode offline DAB mode-0 frames and CRCs; never open or write a device."""
import argparse
import json
from pathlib import Path


def crc_mpeg2(data):
    """MgrDAB 0x15cf4: init FFFFFFFF, MSB first, polynomial 04C11DB7, no xorout."""
    crc = 0xffffffff
    for byte in data:
        crc ^= byte << 24
        for _ in range(8):
            crc = ((crc << 1) ^ (0x04c11db7 if crc & 0x80000000 else 0)) & 0xffffffff
    return crc


def parse_frames(data):
    records = []
    pos = 0
    while pos < len(data):
        start = data.find(b"\x55\xaa", pos)
        if start < 0:
            records.append(dict(offset=pos, kind="trailing", bytes=len(data)-pos, hex=data[pos:].hex()))
            break
        if start > pos:
            records.append(dict(offset=pos, kind="noise", bytes=start-pos, hex=data[pos:start].hex()))
        if len(data)-start < 6:
            records.append(dict(offset=start, kind="truncated_header", hex=data[start:].hex()))
            break
        sequence, command, segment, length = data[start+2:start+6]
        end = start+length+8
        if end > len(data):
            records.append(dict(offset=start, kind="truncated_frame", expected_bytes=length+8,
                                available_bytes=len(data)-start))
            break
        actual = int.from_bytes(data[end-2:end], "big")
        expected = sum(data[start+2:end-2]) & 0xffff
        records.append(dict(offset=start, kind="frame", sequence=sequence, command=hex(command),
                            segment=hex(segment), segment_number=segment & 0x3f,
                            first=bool(segment & 0x80), last=bool(segment & 0x40),
                            checksum_ok=actual == expected, checksum=actual, expected_checksum=expected,
                            firmware_checksum_index_wrap=length >= 250,
                            payload_hex=data[start+6:end-2].hex()))
        pos = end
    return records


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("capture", type=Path)
    parser.add_argument("--crc", action="store_true", help="Compute firmware CRC instead of interpreting frames")
    args = parser.parse_args()
    data = args.capture.read_bytes()
    print(json.dumps(dict(bytes=len(data), crc_mpeg2=f"{crc_mpeg2(data):08x}") if args.crc else parse_frames(data), indent=2))


if __name__ == "__main__":
    main()
