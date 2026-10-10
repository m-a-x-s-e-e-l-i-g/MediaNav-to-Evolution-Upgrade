"""Differential byte-interpreter checks and instruction counts; no native timing.

Actual original/repaired instructions run in a bounded interpreter. CRT copies
and cookie validation are explicit hooks. No GDI, scheduler or native firmware.
"""
import hashlib
import json
import random
import struct
from pathlib import Path
import pefile
from inspect_bt_playback import ROOT
from inspect_wave_queue import STOP
from verify_bt_database_io import IOVM
from patch_appmain_label_scan import APP_SHA, patch_label_scan

TEXT, STACK, COOKIE = 0x47000000, 0x68000000, 0x1234abcd
RANGES = [(0x139918, 0x139a64), (0x1398a0, 0x139918)]


class TextVM(IOVM):
    def __init__(self, pe):
        super().__init__(pe, RANGES)
        # Decode once; exhaustive tests still fetch the actual instruction words.
        self.words = {va: struct.unpack("<I", pe.get_data(va - self.base, 4))[0]
                      for lo, hi in RANGES for va in range(lo, hi, 4)}
        self.text_end = TEXT
        self.text_reads = 0

    def word(self, pc):
        assert pc in self.words, hex(pc)
        return self.words[pc]

    def read(self, at, size=4):
        if TEXT <= at < TEXT + 0x10000:
            assert size == 2 and at % 2 == 0 and at <= self.text_end, "Read after first NUL"
            self.text_reads += 1
        if all(at + i in self.mem for i in range(size)):
            return super().read(at, size)
        rva = at - self.base
        if 0 <= rva < self.pe.OPTIONAL_HEADER.SizeOfImage:
            raw = self.pe.get_data(rva, size)
            assert len(raw) == size
            return int.from_bytes(raw, "little")
        raise AssertionError(f"Uninitialized fixture read {at:x}/{size}")


def fixture(vm, units, null=False, snapshot=False):
    assert 0 in units
    vm.mem.clear(); vm.reg[:] = [0] * 32
    vm.text_reads = 0; vm.steps = 0
    vm.text_end = TEXT + 2 * units.index(0)
    for i, unit in enumerate(units): vm.write(TEXT + 2 * i, unit, 2)
    vm.write(0x1853f4, COOKIE)
    # Sentinels cover stack above/below the frame and the caller's argument area.
    for at in (STACK - 0x28c, STACK, STACK + 0x10): vm.write(at, 0xa55aa55a)
    saved = {i: 0x12340000 + i for i in (*range(16, 24), 28, 30)}
    for i, value in saved.items(): vm.reg[i] = value
    vm.reg[4:8] = [0x41000000, 0 if null else TEXT, 0x1111, 0x2222]
    vm.reg[29], vm.reg[31] = STACK, STOP
    calls = []

    def cookie(m):
        assert m.reg[4] == COOKIE
        calls.append("cookie")
        # A caller-saved clobber must not erase the boolean in s0.
        m.reg[3] = 0xdeadbeef
        return 0xc0de

    def memset(m):
        at, val, n = m.reg[4:7]
        assert (at, val, n) == (STACK - 0x288 + 0x5a, 0, 0x206)
        for i in range(n): m.write(at + i, val, 1)
        calls.append("memset"); return at

    def printf(m):
        at, n, fmt, src = m.reg[4:8]
        assert (at, n, fmt, src) == (STACK - 0x288 + 0x58, 0x103, 0x14f640, TEXT)
        # This copy is never read by the original decision loop. Hook cost is
        # deliberately excluded from both instruction/read benchmarks.
        text = units[:units.index(0)][:n]
        for i, u in enumerate(text): m.write(at + 2 * i, u, 2)
        calls.append("_snwprintf"); return len(text)

    def memcpy(m):
        at, src, n = m.reg[4:7]
        assert (at, src, n) == (STACK - 0x288 + 0x10, 0x151c44, 66)
        raw = m.pe.get_data(src - m.base, n)
        for i, b in enumerate(raw): m.write(at + i, b, 1)
        calls.append("memcpy"); return at

    vm.hooks = {0x140298: cookie, 0x140de4: memset, 0x140320: printf, 0x140e24: memcpy}
    before = dict(vm.mem) if snapshot else None
    vm.run(0x139918, {STOP}, limit=4000000)
    assert vm.reg[29] == STACK and vm.reg[31] == STOP
    assert all(vm.reg[i] == value for i, value in saved.items())
    assert calls.count("cookie") == 1
    assert all(vm.read(at) == 0xa55aa55a for at in (STACK - 0x28c, STACK, STACK + 0x10))
    if before is not None:
        assert all(STACK - 0x288 <= at < STACK or before.get(at) == val
                   for at, val in vm.mem.items()), "Write outside private frame"
    return dict(result=vm.reg[2], instructions=vm.steps, text_unit_reads=vm.text_reads,
                crt_calls=calls[:-1], cookie_checked=True, abi_preserved=True)


def verify(original, candidate, exhaustive=True):
    assert hashlib.sha256(original).hexdigest() == APP_SHA
    a, b = TextVM(pefile.PE(data=original)), TextVM(pefile.PE(data=candidate))
    # Prologue, NULL handling, cookie/return and epilogue are unchanged.
    for lo, hi in ((0x139918, 0x139964), (0x139a34, 0x139a64)):
        assert a.pe.get_data(lo - a.base, hi - lo) == b.pe.get_data(lo - b.base, hi - lo)
    positives = 0
    for unit in range(65536) if exhaustive else ():
        old, new = fixture(a, [unit, 0]), fixture(b, [unit, 0])
        expected = int(0x600 <= unit < 0x700)
        assert old["result"] == new["result"] == expected
        positives += expected
        if unit and unit % 16384 == 0:
            print(f"UTF16 differential checks: {unit}/65536 passed", flush=True)
    if exhaustive: print("All 65536 UTF16 checks passed; checking mixed/long strings", flush=True)
    cases = [[0], [0, 0x600, 0], [65, 0, 0x600, 0],
             [0x590, 0x5ff, 0], [0xd800, 0xdc00, 0xffff, 0],
             [65, 0x600, 66, 0], [0x6ff, 65, 0]]
    for n in (1, 32, 128, 270):
        for unit in (0x600, 0x6ff):
            for position in (0, n // 2, n - 1):
                units = [65] * n + [0]; units[position] = unit; cases.append(units)
        # For rejected units the boolean and control flow do not depend on
        # their position; one case per range/length avoids redundant O(n^2) runs.
        for unit in (0x700, 0x590, 0xdfff):
            cases.append([65] * (n - 1) + [unit, 0])
    cases.append([65] * 400 + [0])
    rng = random.Random(70504)
    for _ in range(128):
        cases.append([rng.randrange(1, 65536) for _ in range(rng.randrange(1, 80))] + [0])
    for units in cases:
        old, new = fixture(a, units, snapshot=True), fixture(b, units, snapshot=True)
        expected = int(any(0x600 <= u < 0x700 for u in units[:units.index(0)]))
        assert old["result"] == new["result"] == expected
        assert new["crt_calls"] == []
    for vm in (a, b): assert fixture(vm, [0], null=True, snapshot=True)["result"] == 0
    benchmarks = []
    for n in (0, 8, 32, 128, 270):
        units = [65] * n + [0]
        benchmarks.append(dict(length=n, original=fixture(a, units), repaired=fixture(b, units)))
    assert all(row["repaired"]["text_unit_reads"] == row["length"] + 1 for row in benchmarks)
    return dict(exhaustive_utf16_cases=65536 if exhaustive else 0, positive_units=positives,
                multi_unit_cases=len(cases), null_pointer_cases=2, benchmarks=benchmarks,
                native_execution=False, unit_tested=False,
                measurement="Interpreted instruction and source-read counts, CRT hook internals excluded; no wall-clock or screen timing")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    raw = (ROOT / module["path"]).read_bytes(); candidate, recipe = patch_label_scan(raw)
    result = verify(raw, candidate)
    out = ROOT / "analysis/firmware/appmain-label-scan"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(dict(source=module["path"], patch=recipe,
        checks=result), indent=2), encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__": main()
