"""Bounded offline ACT3/RAC3 inspection. Never executes or replaces firmware."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT = ROOT / "extracted/705md/upgrade/Storage Card/System/font/msgothic.ac3"


class InvalidFont(ValueError):
    pass


class Reader:
    def __init__(self, data):
        self.data, self.pos = data, 0

    def take(self, size):
        if size < 0 or size > len(self.data) - self.pos:
            raise InvalidFont("truncated field")
        value = self.data[self.pos:self.pos + size]
        self.pos += size
        return value

    def numbers(self, fmt):
        return struct.unpack(fmt, self.take(struct.calcsize(fmt)))

    def integer(self, size=4):
        return int.from_bytes(self.take(size), "big")


def rac3(data, expected_size):
    r = Reader(data)
    magic, compressed, uncompressed = r.numbers(">III")
    if magic != 0x52414303 or compressed > len(data) or compressed < 16:
        raise InvalidFont("invalid RAC3 header")
    if uncompressed != expected_size or uncompressed > 32 * 1024 * 1024:
        raise InvalidFont("RAC3 output size mismatch or limit")
    r = Reader(data[:compressed]); r.pos = 12
    count = r.integer()
    lengths = list(r.take(count))
    if not count or any(n == 0 for n in lengths):
        raise InvalidFont("empty dictionary token")
    width = r.integer(1)
    if width > 4:
        raise InvalidFont("unsupported dictionary offset width")
    if width:
        offsets = [r.integer(width) for _ in range(count)]
    else:
        offsets = []; total = 0
        for length in lengths:
            offsets.append(total); total += length
    string_size = r.integer()
    strings = r.take(string_size)
    tokens = []
    for start, length in zip(offsets, lengths):
        if start + length > string_size:
            raise InvalidFont("token outside dictionary")
        tokens.append(strings[start:start + length])
    groups = r.integer(1)
    if not 1 <= groups <= 32:
        raise InvalidFont("invalid Huffman group count")
    bits = list(r.take(groups))
    first = [r.integer() for _ in bits]
    last = [r.integer() for _ in bits]
    codes = {}; token_index = 0
    for length, lo, hi in zip(bits, first, last):
        if not 1 <= length <= 32 or lo > hi or hi >= 1 << length:
            raise InvalidFont("invalid Huffman range")
        for code in range(lo, hi + 1):
            if token_index >= count or (length, code) in codes:
                raise InvalidFont("Huffman dictionary mismatch")
            codes[length, code] = token_index; token_index += 1
    if token_index != count:
        raise InvalidFont("unused dictionary tokens")
    intervals = r.integer()
    marks = [r.integer() for _ in range(intervals)]
    deltas = list(r.take(intervals))
    stream = r.integer()
    if stream < r.pos * 8 or stream > compressed * 8:
        raise InvalidFont("invalid bitstream offset")
    if any(mark < stream or mark >= compressed * 8 for mark in marks):
        raise InvalidFont("invalid random access mark")
    bitpos = stream
    output = bytearray()
    boundaries = {}
    while len(output) < uncompressed:
        boundaries[bitpos] = len(output)
        code = 0
        for length in range(1, max(bits) + 1):
            if bitpos >= compressed * 8:
                raise InvalidFont("truncated Huffman code")
            code = (code << 1) | ((data[bitpos // 8] >> (7 - bitpos % 8)) & 1)
            bitpos += 1
            index = codes.get((length, code))
            if index is not None:
                token = tokens[index]
                if len(token) > uncompressed - len(output):
                    raise InvalidFont("decoded token exceeds output size")
                output.extend(token)
                break
        else:
            raise InvalidFont("unknown Huffman code")
    # Independently supplied access indices must match every sequential boundary.
    if intervals != (uncompressed + 127) // 128:
        raise InvalidFont("fixture interval differs from 128 bytes")
    for i, (mark, delta) in enumerate(zip(marks, deltas)):
        if boundaries.get(mark) != i * 128 - delta:
            raise InvalidFont(f"access index mismatch at interval {i}")
    return bytes(output), dict(compressed_bytes=compressed, output_bytes=uncompressed,
        token_count=count, token_length_min=min(lengths), token_length_max=max(lengths),
        dictionary_bytes=string_size, offset_width=width, huffman_lengths=bits,
        bitstream_offset=stream, final_bit=bitpos, interval_bytes=128,
        verified_intervals=intervals, sha256=hashlib.sha256(output).hexdigest())


def inspect(path, destination=None):
    data = path.read_bytes(); r = Reader(data)
    magic, version, count = r.numbers(">4sII")
    if magic != b"ttcf" or count > 256:
        raise InvalidFont("invalid TTC header")
    faces = []; act_offset = None
    for start in [r.integer() for _ in range(count)]:
        f = Reader(data); f.pos = start
        scaler, tables, _, _, _ = f.numbers(">IHHHH")
        entries = []
        for _ in range(tables):
            tag, checksum, offset, size = f.numbers(">4sIII")
            tag = tag.decode("ascii")
            entries.append(dict(tag=tag, checksum=hex(checksum), offset=offset,
                                length=size, within_physical_file=offset + size <= len(data)))
            if tag == "act3":
                if act_offset is not None and act_offset != offset:
                    raise InvalidFont("multiple ACT3 descriptors")
                act_offset = offset
        name = next(t for t in entries if t["tag"] == "name")
        n = Reader(data[name["offset"]:name["offset"] + name["length"]])
        _, records, strings = n.numbers(">HHH"); names = {}
        for _ in range(records):
            platform, encoding, language, ident, size, offset = n.numbers(">6H")
            if platform == 3 and language == 0x409 and ident in (1, 2, 4, 6):
                raw = n.data[strings + offset:strings + offset + size]
                if len(raw) != size: raise InvalidFont("name outside table")
                names[str(ident)] = raw.decode("utf-16-be")
        faces.append(dict(offset=start, scaler=hex(scaler), names=names, tables=entries))
    if act_offset is None:
        raise InvalidFont("missing ACT3 descriptor")
    a = Reader(data); a.pos = act_offset
    length, comp, uncomp, glyf_start, glyf_end, entries = a.numbers(">HIIIIH")
    if comp != len(data) or act_offset + length > len(data) or length < 20 + 14 * entries:
        raise InvalidFont("invalid ACT3 sizes")
    blocks = []
    for _ in range(entries):
        start, size, physical, compressed = a.numbers(">IIIH")
        blocks.append(dict(virtual_start=start, virtual_length=size,
                           physical_start=physical, compressed_flag=compressed))
    virtual_size = max(b["virtual_start"] + b["virtual_length"] for b in blocks)
    if virtual_size > 32 * 1024 * 1024:
        raise InvalidFont("virtual output limit")
    reconstructed = bytearray(virtual_size)
    for i, block in enumerate(blocks):
        physical, size = block["physical_start"], block["virtual_length"]
        if block["compressed_flag"]:
            output, metadata = rac3(data[physical:act_offset], size)
            block["rac3"] = metadata
        else:
            output = data[physical:physical + size]
            if len(output) != size: raise InvalidFont("truncated raw block")
        reconstructed[block["virtual_start"]:block["virtual_start"] + size] = output
        if destination:
            destination.mkdir(parents=True, exist_ok=True)
            (destination / f"block-{i}.bin").write_bytes(output)
    checksums = []
    for face in faces:
        for table in face["tables"]:
            if table["tag"] in ("EBDT", "glyf", "loca", "cmap"):
                raw = reconstructed[table["offset"]:table["offset"] + table["length"]]
                raw += bytes((-len(raw)) % 4)
                value = sum(x[0] for x in struct.iter_unpack(">I", raw)) & 0xffffffff
                checksums.append(dict(face=face["names"].get("1"), tag=table["tag"],
                    computed=hex(value), declared=table["checksum"], matches=hex(value)==table["checksum"]))
    result = dict(source=str(path.relative_to(ROOT)) if path.is_relative_to(ROOT) else str(path),
        sha256=hashlib.sha256(data).hexdigest(), binary_execution=False,
        physical_bytes=len(data), ttc_version=hex(version), faces=faces,
        act3=dict(offset=act_offset, descriptor_bytes=length, compressed_bytes=comp,
                  declared_uncompressed_bytes=uncomp, glyf_start=glyf_start, glyf_end=glyf_end),
        blocks=blocks, checksums=checksums, virtual_bytes=len(reconstructed),
        virtual_sha256=hashlib.sha256(reconstructed).hexdigest(),
        limitations=["RAC3 decoded; CTF glyph transformation not reversed",
                     "Virtual bytes are not an installable reconstructed TrueType font",
                     "ACT3 declared uncompressed size differs from mapped end by 16 bytes",
                     "No native font engine or Windows CE execution"])
    if destination:
        (destination / "virtual-font.bin").write_bytes(reconstructed)
        (destination / "manifest.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    return result


def self_test():
    # One dictionary token, one-bit code, 128 output bytes and one access marker.
    prefix = struct.pack(">III", 0x52414303, 62, 128)
    dictionary = struct.pack(">I", 1) + bytes([1, 0]) + struct.pack(">I", 1) + b"A"
    huffman = bytes([1, 1]) + struct.pack(">II", 0, 0)
    index = struct.pack(">II", 1, 46*8) + bytes([0]) + struct.pack(">I", 46*8)
    valid = prefix + dictionary + huffman + index + bytes(16)
    assert len(valid) == 62
    decoded, meta = rac3(valid, 128)
    assert decoded == b"A" * 128 and meta["verified_intervals"] == 1
    cases = [(valid[:-1], 128), (bytes(4)+valid[4:], 128), (valid, 127),
             (valid[:24]+bytes([0])+valid[25:], 128),
             (valid[:37]+struct.pack(">I", 46*8+1)+valid[41:], 128)]
    for data, size in cases:
        try: rac3(data, size)
        except InvalidFont: pass
        else: raise AssertionError("invalid fixture accepted")
    return dict(valid_fixtures=1, rejected_fixtures=len(cases))


def main():
    parser = argparse.ArgumentParser(__doc__)
    parser.add_argument("path", nargs="?", type=Path, default=DEFAULT)
    parser.add_argument("--output", type=Path)
    parser.add_argument("--self-test", action="store_true")
    args = parser.parse_args()
    if args.self_test:
        print(json.dumps(self_test())); return
    result = inspect(args.path, args.output)
    print(json.dumps({k: result[k] for k in ("sha256", "physical_bytes", "act3", "blocks", "virtual_bytes")}, indent=2))


if __name__ == "__main__":
    main()
