"""Cover retry, rounded cover corners and a native 278x278 cover bitmap.

Starts from the upgrade.lgu produced by patch_cover_final_packet.py and changes only
Blue.exe (bounded retry hooks) and AppMain.exe (278 px decode, key-colour corner mask,
TransparentImage paint). Pass --version to relabel. Needs pefile (tools/requirements.txt).
"""
import argparse, hashlib, io, struct, sys, zipfile
from pathlib import Path
import pefile
sys.path.insert(0, str(Path(__file__).resolve().parent))
import lgu_repack as L
import cover_corner_mask as mask
import cover_retry_patch as retry

# SHA-256 of the package produced by patch_cover_final_packet.py (checked before patching).
BASE_SHA = "9b504fa4c67b6ce7874f6e5bb0eb973b81fd5f2712975d3649f2e871d865c4a2"
SYS = "upgrade\\Storage Card\\System\\"
BLUE, APP, VER = (SYS + n for n in ("Blue.exe", "AppMain.exe", "Version_Info.txt"))
EDGE_OLD, EDGE_NEW = 0x240800c8, 0x24080000 | mask.EDGE
KEY_HI, KEY_LO = 0x3c0800ff, 0x250800ff            # lui t0,0xff ; addiu t0,t0,0xff = COLORREF 0x00FF00FF
TRANSPARENT_IMAGE_IAT = 0x524c                      # StretchBlt IAT low half was 0x5250
MASK_CAVE, WRAPPER_HOOK = 0x388d10, 0x388268


def sha(b):
    return hashlib.sha256(b).hexdigest()


class Pe:
    def __init__(self, data):
        self.data = bytearray(data)
        self.pe = pefile.PE(data=bytes(data))
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.cs = self.pe.OPTIONAL_HEADER.get_field_absolute_offset("CheckSum")

    def off(self, va):
        return self.pe.get_offset_from_rva(va - self.base)

    def word(self, va):
        return struct.unpack_from("<I", self.data, self.off(va))[0]

    def put(self, va, new, old=None):
        o = self.off(va)
        if old is not None:
            assert struct.unpack_from("<I", self.data, o)[0] == old, hex(va)
        struct.pack_into("<I", self.data, o, new)

    def cave(self, va, blob):
        o = self.off(va)
        assert not any(self.data[o:o + len(blob)]), f"cave {va:#x} is not empty"
        self.data[o:o + len(blob)] = blob

    def finish(self):
        struct.pack_into("<I", self.data, self.cs, L.pe_checksum(bytes(self.data), self.cs))
        return bytes(self.data)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source", type=Path)
    ap.add_argument("output", type=Path)
    ap.add_argument("--version", help="optional new package version label")
    a = ap.parse_args()
    raw = a.source.read_bytes()
    assert sha(raw) == BASE_SHA, "source is not the expected upgrade.lgu"
    z = bytes(L.xor(raw[1024:]))
    zf = zipfile.ZipFile(io.BytesIO(z))
    get = lambda n: zf.read(n, pwd=L.PW)

    # Blue.exe: add the retry code in a free gap and hook the two decision points.
    blue = Pe(get(BLUE))
    blob, labels, jump_a, jump_b = retry.build()
    blue.cave(retry.CAVE, blob)
    blue.put(retry.HOOK_A, struct.unpack("<I", jump_a)[0], retry.WORD_A)
    blue.put(retry.HOOK_B, struct.unpack("<I", jump_b)[0], retry.WORD_B)

    # AppMain.exe: decode and paint the cover at 278x278, with masked corners.
    app = Pe(get(APP))
    for va in (0x387ec0, 0x387f60, 0x2221c0, 0x222260):      # decoder DIB size and draw rectangle
        app.put(va, EDGE_NEW, EDGE_OLD)
    app.put(0x23515c, EDGE_NEW, EDGE_OLD)                     # paint: source size = 278
    app.put(0x235168, KEY_HI, 0x3c0800cc)                     # paint: key colour instead of SRCCOPY
    app.put(0x23516c, KEY_LO, 0x25080020)
    app.put(0x235178, 0x25080000 | TRANSPARENT_IMAGE_IAT, 0x25085250)
    mblob, entries = mask.build(MASK_CAVE)
    app.cave(MASK_CAVE, mblob)
    app.put(WRAPPER_HOOK, (3 << 26) | (entries["post"] >> 2), 0x0040b025)   # move s6,v0 -> jal post

    replace = {BLUE: blue.finish(), APP: app.finish()}
    if a.version:
        replace[VER] = a.version.encode("ascii")
    new = L.rebuild(z, replace)
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_bytes(L.pack(raw, new, a.version))
    print(a.output, sha(a.output.read_bytes()))


if __name__ == "__main__":
    main()
