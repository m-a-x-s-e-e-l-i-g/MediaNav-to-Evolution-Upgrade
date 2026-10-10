"""Offline partial decoding of MediaNav SPP ring snapshots and B6 B6 frames."""
import argparse
import json
import struct
from pathlib import Path

COUNT = 500
STRIDE = 0x408
TAIL = COUNT * STRIDE
SIZE = TAIL + 8


def checksum(frame):
    if len(frame) < 10:
        raise ValueError("Frame is shorter than its observed 10-byte header")
    length = struct.unpack_from("<H", frame, 2)[0]
    if length != len(frame):
        raise ValueError("Declared frame length differs from supplied bytes")
    total = sum(struct.unpack_from("<H", frame, offset)[0]
                for offset in range(0, length - 1, 2) if offset != 8)
    if length % 2: total += frame[-1]
    return -total & 0xffff


def frames(data):
    result = []
    offset = 0
    while offset < len(data):
        start = data.find(bytes([0xb6, 0xb6]), offset)
        if start < 0:
            result.append(dict(offset=offset, kind="unframed", bytes_hex=data[offset:].hex()))
            break
        if start > offset:
            result.append(dict(offset=offset, kind="unframed", bytes_hex=data[offset:start].hex()))
        if len(data) - start < 10:
            result.append(dict(offset=start, kind="truncated_header", bytes_hex=data[start:].hex()))
            break
        length, sequence, command, stored = struct.unpack_from("<4H", data, start + 2)
        if length < 10 or length > 50000:
            result.append(dict(offset=start, kind="invalid_length", declared_length=length))
            offset = start + 1
            continue
        if start + length > len(data):
            result.append(dict(offset=start, kind="truncated_frame", declared_length=length,
                               available=len(data)-start, bytes_hex=data[start:].hex()))
            break
        frame = data[start:start + length]
        expected = checksum(frame)
        result.append(dict(offset=start, kind="frame", length=length, sequence_raw=sequence,
                           response_flag=bool(sequence & 0x8000), sequence_low15=sequence & 0x7fff,
                           command=command, command_passes_observed_limit=command < 0x10b,
                           stored_checksum=stored, expected_checksum=expected, checksum_ok=stored==expected,
                           payload_hex=frame[10:].hex()))
        offset = start + length
    return result


def ring(data):
    if len(data) != SIZE: raise ValueError(f"Expected {SIZE} bytes for a full SPP mapping")
    read, write, counter, unknown = struct.unpack_from("<4H", data, TAIL)
    records = []
    for index in range(COUNT):
        service, length = struct.unpack_from("<2I", data, index * STRIDE)
        if length == 0: continue
        valid = length <= 1024
        raw = data[index * STRIDE + 8:(index + 1) * STRIDE]
        records.append(dict(index=index, service_id=service, declared_length=length,
                            within_slot_capacity=valid, payload_hex=raw[:length if valid else 1024].hex()))
    return dict(read_index=read, write_index=write, counter_mod500=counter, unknown_tail_word=unknown,
                indices_in_range=read < COUNT and write < COUNT,
                note="All nonzero-length slots, including stale records. Count wraps at 500. Equal indices alone do not distinguish empty from full. No live synchronization.",
                records=records)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("dump", type=Path)
    parser.add_argument("--ring", action="store_true", help="Decode mapping slots instead of a concatenated wire stream")
    args = parser.parse_args()
    data = args.dump.read_bytes()
    print(json.dumps(ring(data) if args.ring else frames(data), indent=2))


if __name__ == "__main__": main()
