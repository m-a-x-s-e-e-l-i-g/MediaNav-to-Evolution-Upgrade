"""Tolerate the iPhone's final cover-art GET packet.

Starts from the published upgrade.lgu and changes only Blue.exe's cover-art
GET validator (three branch-to-failed instructions become nops). All other
members are carried over byte for byte. Pass --version to relabel the package.
No PC executable is needed.
"""
import argparse, hashlib, io, struct, sys, zipfile
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
import lgu_repack as L

BASE_SHA = "521e9192c1dea4ae4d64d5346db0cc441c638e6156b7227af8a64eac162979b3"
BLUE = r"upgrade\Storage Card\System\Blue.exe"
VER = r"upgrade\Storage Card\System\Version_Info.txt"
NOP = bytes(4)
# (offset, expected word, meaning); the validator exists twice in the published image.
EDITS = [(0x12feb4, 0x15150043, "repeated Length header must match"),
         (0x12fee4, 0x11000037, "final packet needs End-of-Body"),
         (0x12fefc, 0x16950031, "collected bytes must equal declared Length")]
COPY_SHIFT = 0x198cd0 - 0x12fed0


def sha(b):
    return hashlib.sha256(b).hexdigest()


def fix_checksum(data):
    pe = struct.unpack_from("<I", data, 0x3c)[0]
    cs = pe + 4 + 20 + 64
    struct.pack_into("<I", data, cs, L.pe_checksum(bytes(data), cs))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source", type=Path)
    ap.add_argument("output", type=Path)
    ap.add_argument("--version", help="optional new package version label")
    a = ap.parse_args()
    raw = a.source.read_bytes()
    assert sha(raw) == BASE_SHA, "source is not the expected published upgrade.lgu"
    z = bytes(L.xor(raw[1024:]))
    members = {n: zipfile.ZipFile(io.BytesIO(z)).read(n, pwd=L.PW) for n in (BLUE,)}
    blue = bytearray(members[BLUE])
    # Turn the three rejecting branches into no-ops in both copies of the validator.
    for base in (0, COPY_SHIFT):
        for off, word, _ in EDITS:
            at = off + base
            assert struct.unpack_from("<I", blue, at)[0] == word, hex(at)
            blue[at:at + 4] = NOP
    fix_checksum(blue)
    replace = {BLUE: bytes(blue)}
    if a.version:
        replace[VER] = a.version.encode("ascii")
    new = L.rebuild(z, replace)
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_bytes(L.pack(raw, new, a.version))
    print(a.output, sha(a.output.read_bytes()))


if __name__ == "__main__":
    main()
