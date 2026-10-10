"""Decode local MICOM ULC transfer captures; never open a device or transmit."""
import argparse
import hashlib
import json
from pathlib import Path

PREFIX = b"ULC"
PAYLOAD_SIZE = 1024
FRAME_SIZE = 1030


def encode_frame(flags, tag, payload):
    """Build bytes offline for inspection, using the recovered additive checksum."""
    if not 0 <= flags <= 255 or not 0 <= tag <= 255 or len(payload) != PAYLOAD_SIZE:
        raise ValueError("Expected byte flags/tag and exactly 1024 payload bytes")
    body = bytes((0xa0 | flags, tag)) + payload
    return PREFIX + body + bytes((sum(body) & 255,))


def parse_capture(data):
    records = []
    offset = 0
    while offset < len(data):
        start = data.find(PREFIX, offset)
        if start == -1:
            tail = data[offset:]
            partial = 2 if tail.endswith(b"UL") else 1 if tail.endswith(b"U") else 0
            if len(tail) > partial:
                records.append(dict(offset=offset, kind="unframed_bytes", hex=tail[:-partial].hex() if partial else tail.hex()))
            if partial:
                records.append(dict(offset=len(data)-partial, kind="truncated_prefix", hex=tail[-partial:].hex()))
            break
        if start > offset:
            records.append(dict(offset=offset, kind="unframed_bytes", hex=data[offset:start].hex()))
        if len(data)-start < FRAME_SIZE:
            records.append(dict(offset=start, kind="truncated_ULC", expected_bytes=FRAME_SIZE, hex=data[start:].hex()))
            break
        frame = data[start:start+FRAME_SIZE]
        expected = sum(frame[3:-1]) & 255
        records.append(dict(offset=start, kind="ULC", type_byte=frame[3],
                            known_type=frame[3] in (0xa0, 0xa1, 0xa4), tag=frame[4],
                            payload_hex=frame[5:-1].hex(), payload_sha256=hashlib.sha256(frame[5:-1]).hexdigest(),
                            checksum=frame[-1], expected_checksum=expected, checksum_valid=frame[-1] == expected))
        # Consume fixed length even on checksum failure or ULC inside the payload.
        offset = start+FRAME_SIZE
    return records


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("capture", type=Path)
    args = parser.parse_args()
    print(json.dumps(dict(scope="Offline fixed-length ULC framing; wire tags are not confirmed flash addresses",
                          records=parse_capture(args.capture.read_bytes())), indent=2))


if __name__ == "__main__":
    main()
