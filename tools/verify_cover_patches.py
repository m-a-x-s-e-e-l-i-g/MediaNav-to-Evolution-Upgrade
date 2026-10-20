"""Verify the cover-art patch packages against the published upgrade.lgu.

Checks (all on written bytes): which members changed, that every changed byte lies
in a reviewed address range, PE checksums, and execution fixtures for the three
changes (final-packet validator, retry decisions, corner mask) in the repo's MIPS
interpreter. Needs pefile and capstone (tools/requirements.txt).

    python tools/verify_cover_patches.py PUBLISHED.lgu STEP1.lgu STEP2.lgu
"""
import argparse, io, struct, sys, zipfile, zlib
from pathlib import Path
from types import SimpleNamespace
import pefile

ROOT = Path(__file__).resolve().parents[1]
MODEL = ROOT / "releases/7.0.6.MAX10/build-sources"
sys.path[:0] = [str(ROOT / "tools"), str(MODEL / "model-tools"), str(MODEL / "workspace-tools")]
import lgu_repack as L
import cover_corner_mask as mask
import cover_retry_patch as retry
from inspect_bt_lifecycle import SliceVM
import verify_media_responsiveness as vmr

SYS = "upgrade\\Storage Card\\System\\"
PUBLISHED_SHA = "521e9192c1dea4ae4d64d5346db0cc441c638e6156b7227af8a64eac162979b3"
# Reviewed address ranges (virtual addresses), see docs/cover-art-iphone-fixes.md.
BLUE_STEP1_FILE = [(o + s, 4) for s in (0, 0x198cd0 - 0x12fed0) for o in (0x12feb4, 0x12fee4, 0x12fefc)]
BLUE_STEP2 = [(retry.HOOK_A, 4), (retry.HOOK_B, 4), (retry.CAVE, 0x400)]
APP_STEP2 = [(0x387ec0, 4), (0x387f60, 4), (0x2221c0, 4), (0x222260, 4), (0x23515c, 4),
             (0x235168, 8), (0x235178, 4), (0x388268, 4), (0x388d10, 0x200)]


def load(path):
    raw = Path(path).read_bytes()
    assert raw[:4] == b"LGU0" and struct.unpack_from("<Q", raw, 12)[0] == len(raw)
    z = bytes(L.xor(raw[1024:]))
    assert zlib.crc32(z) == struct.unpack_from("<I", raw, 24)[0], "payload CRC"
    zf = zipfile.ZipFile(io.BytesIO(z))
    members = {}
    for i in zf.infolist():
        data = zf.read(i, pwd=L.PW)
        assert zlib.crc32(data) & 0xffffffff == i.CRC, i.filename
        members[i.filename] = data
    return raw, members


def diff_vas(old, new, ranges, name):
    """Every differing byte must lie inside `ranges` (VA, length), ignoring the PE checksum."""
    pe = pefile.PE(data=new)
    base = pe.OPTIONAL_HEADER.ImageBase
    cs = pe.OPTIONAL_HEADER.get_field_absolute_offset("CheckSum")
    assert len(old) == len(new)
    bad = []
    for o in (i for i in range(len(old)) if old[i] != new[i]):
        if cs <= o < cs + 4:
            continue
        va = base + pe.get_rva_from_offset(o)
        if not any(lo <= va < lo + n for lo, n in ranges):
            bad.append(hex(va))
    assert not bad, f"{name}: unreviewed changes at {bad[:5]}"
    assert pe.generate_checksum() == pe.OPTIONAL_HEADER.CheckSum, f"{name}: PE checksum"


class PeImage:
    def __init__(self, data):
        self.pe = pefile.PE(data=data)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.data = data
    OPTIONAL_HEADER = SimpleNamespace(ImageBase=0)

    def get_data(self, rva, n):
        o = self.pe.get_offset_from_rva(rva - self.base)
        return self.data[o:o + n]


def fixture_retry(blue):
    img = PeImage(blue)
    BIND, CTRL = 0x300300, 0x500000

    class VM(SliceVM):
        def word(s, pc):
            return struct.unpack("<I", img.get_data(pc, 4))[0]
        def internal_call(s, va):
            return retry.CAVE <= va < retry.CAVE + 0x400
    labels = retry.build()[1]

    def run(entry, t0, s4, bind, state=0, published=0, now=1000):
        vm = VM(img, {})
        vm.hooks[retry.CLOCK] = lambda m: now
        for k, v in bind.items():
            SliceVM.write(vm, BIND + k, v, 4)
        SliceVM.write(vm, CTRL, state, 4)
        SliceVM.write(vm, CTRL + 36, published, 4)
        vm.reg[8], vm.reg[17], vm.reg[20], vm.reg[19], vm.reg[29] = t0, BIND, s4, CTRL, 0x7f000000
        stops = {retry.RESUME_A, retry.REFUSED, retry.NORMAL_B, retry.ACCEPTED, retry.REFRESH}
        vm.run(labels[entry], stops, limit=5000)
        return vm.pc, vm.read(BIND + 40)
    R = retry
    cases = [("cavea", 4, 5, {}, 0, 0, 1000, R.RESUME_A, 0),                    # new attempt passes through
             ("cavea", 5, 5, {44: 5}, 0, 0, 1000, R.REFUSED, 0),                # first failure: stamp and wait
             ("cavea", 5, 5, {44: 5, 36: 1000}, 0, 0, 2000, R.REFUSED, 0),      # too soon
             ("cavea", 5, 5, {44: 5, 36: 1000}, 0, 0, 2600, R.RESUME_A, 1),     # due: retry
             ("cavea", 5, 5, {44: 5, 36: 1000, 40: 3}, 0, 0, 9000, R.REFUSED, 3),  # budget spent
             ("caveb", 1, 5, {}, 0, 0, 1000, R.NORMAL_B, 0),
             ("caveb", 0, 5, {44: 5}, 3, 0, 1000, R.ACCEPTED, 0),               # not READY
             ("caveb", 0, 5, {44: 5}, 5, 1, 1000, R.ACCEPTED, 0),               # cover published
             ("caveb", 0, 5, {44: 5, 36: 1000}, 5, 0, 2600, R.REFRESH, 1),      # READY, no cover: ask again
             ("caveb", 0, 5, {44: 5, 36: 1000, 40: 3}, 5, 0, 9000, R.ACCEPTED, 3)]
    for entry, t0, s4, bind, state, pub, now, want_pc, want_n in cases:
        pc, n = run(entry, t0, s4, bind, state, pub, now)
        assert (pc, n) == (want_pc, want_n), (entry, hex(pc), n)
    return len(cases)


def fixture_mask(app):
    img = PeImage(app)
    at = 0x388d10
    blob, e = mask.build(at)
    assert img.get_data(at, len(blob)) == blob, "written bytes differ from the reviewed routine"
    BITS, N = 0x50000000, mask.EDGE * mask.STRIDE

    class VM(SliceVM):
        def word(s, pc):
            return struct.unpack("<I", img.get_data(pc, 4))[0]
        def internal_call(s, va):
            return at <= va < at + len(blob)
        def write(s, a, v, size=4):
            assert BITS <= a < BITS + N or a >= 0x7000000, ("stray write", hex(a))
            super().write(a, v, size)
    vm = VM(img, {})
    for i, b in enumerate(blob):
        SliceVM.write(vm, at + i, b, 1)
    for i in range(N):
        SliceVM.write(vm, BITS + i, 0x55, 1)
    vmr.call(vm, e["maskbits"], [BITS], limit=200000)
    w = mask.widths()
    want = {(row, col) for r in range(mask.RADIUS) for x in range(w[r])
            for row in (r, mask.EDGE - 1 - r) for col in (x, mask.EDGE - 1 - x)}
    got = set()
    for row in range(mask.EDGE):
        for col in range(mask.EDGE):
            px = [vm.read(BITS + row * mask.STRIDE + col * 3 + k, 1) for k in range(3)]
            if px == [255, 0, 255]:
                got.add((row, col))
            else:
                assert px == [0x55] * 3
    assert got == want
    for row in range(mask.EDGE):
        assert all(vm.read(BITS + row * mask.STRIDE + k, 1) == 0x55 for k in (834, 835))
    return len(got)


def fixture_final_packet():
    """Strict vs patched GET validator on iPhone-style packets (assembled reviewed model)."""
    import bt_cover_art_responses as native
    import bt_cover_art_client as host
    import verify_bt_cover_responses as v
    orig = [dict(r) for r in native.assembled()]

    def edited(raw):
        raw = bytearray(raw)
        i = raw.find(struct.pack("<III", 0x32e80001, 0x92290000, 0x240a00a0))
        j = raw.find(struct.pack("<II", 0x8e090004, 0x0128482b))
        assert i >= 0 and j >= 0
        for at in (i + 20, i + 44, j + 24):
            raw[at:at + 4] = bytes(4)
        return bytes(raw)
    patched = [dict(r, raw=edited(r["raw"])) if r["address"] == native.GET else dict(r) for r in orig]

    def run(rows, pkts):
        v.helpers = lambda: rows
        state, body, out = [v.BODY, host.MAX_IMAGE, 0, 0, 0, 0, v.CID, 0], b"", []
        for p in pkts:
            vm = v.VM(p, state, body)
            st = vmr.call(vm, native.GET, [v.OUTPUT, v.INPUT, len(p)], limit=200000)
            out.append(st)
            if st not in (1, 2):
                break
            state = [v.BODY, host.MAX_IMAGE] + [vm.read(v.OUTPUT + o) for o in (8, 12, 16, 20, 24, 28)]
            body = v.data(vm, v.BODY, state[2])
        return out
    img = bytes(range(256)) * 6
    first = v.packet(0x90, v.fixed(0xcb, v.CID) + v.fixed(0xc3, len(img)) + v.sequence(0x48, img[:1000]))
    bad = 0xffffffff
    cases = [("valid final", [first, v.packet(0xa0, v.sequence(0x49, img[1000:]))], [1, 2], [1, 2]),
             ("final as plain Body", [first, v.packet(0xa0, v.sequence(0x48, img[1000:]))], [1, bad], [1, 2]),
             ("Length differs", [v.packet(0x90, v.fixed(0xcb, v.CID) + v.fixed(0xc3, len(img) + 37) + v.sequence(0x48, img[:1000])),
                                 v.packet(0xa0, v.sequence(0x49, img[1000:]))], [1, bad], [1, 2]),
             ("repeated Length", [first, v.packet(0xa0, v.fixed(0xc3, len(img) + 5) + v.sequence(0x49, img[1000:]))], [1, bad], [1, 2]),
             ("wrong connection id", [v.packet(0x90, v.fixed(0xcb, v.CID + 1) + v.sequence(0x48, img[:1000]))], [bad], [bad]),
             ("error opcode", [v.packet(0xc4, b"")], [bad], [bad])]
    for name, pk, strict, fixed in cases:
        assert run(orig, pk) == strict, (name, "published")
        assert run(patched, pk) == fixed, (name, "patched")
    return len(cases)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("published"), ap.add_argument("step1"), ap.add_argument("step2")
    a = ap.parse_args()
    base_raw, base = load(a.published)
    import hashlib
    assert hashlib.sha256(base_raw).hexdigest() == PUBLISHED_SHA, "not the published package"
    _, s1 = load(a.step1)
    _, s2 = load(a.step2)
    blue, app = SYS + "Blue.exe", SYS + "AppMain.exe"
    for label, m, expect in (("step1", s1, {blue}), ("step2", s2, {blue, app})):
        assert list(m) == list(base)
        assert {n for n in m if m[n] != base[n]} == expect, label
    pe = pefile.PE(data=base[blue])
    b1 = [(pe.OPTIONAL_HEADER.ImageBase + pe.get_rva_from_offset(o), n) for o, n in BLUE_STEP1_FILE]
    diff_vas(base[blue], s1[blue], b1, "step1 Blue.exe")
    diff_vas(base[blue], s2[blue], b1 + BLUE_STEP2, "step2 Blue.exe")
    diff_vas(base[app], s2[app], APP_STEP2, "step2 AppMain.exe")
    assert {n for n in s2 if s2[n] != s1[n]} == {blue, app}
    print("members/address ranges/checksums ok")
    print("final-packet fixtures:", fixture_final_packet())
    print("retry fixtures:", fixture_retry(s2[blue]))
    print("corner mask pixels per cover:", fixture_mask(s2[app]))


if __name__ == "__main__":
    main()
