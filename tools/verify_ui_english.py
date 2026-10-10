"""Interpret actual language-loader/draw bytes with explicit CE/GDI API fixtures."""
from pathlib import Path
import pefile
from verify_bt_database_io import IOVM
from inspect_wave_queue import STOP
from patch_ui_english import patch, LABELS

ROOT = Path(__file__).resolve().parents[1]
SYSTEM = ROOT / "build/maxmade-7.0.6.MAX03/roundtrip/upgrade/Storage Card/System"
STACK = 0x68000000
IDS = (1205, 1206, 1207, 1208, 1209, 1210, 1211, 1434)
BUFFERS = (0x388d4, 0x386cc, 0x384c4, 0x382bc, 0x380b4, 0x37eac, 0x37ca4, 0x37a9c)


def strings(path):
    pe = pefile.PE(str(path))
    result = {}
    for typ in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        if typ.id != 6:
            continue
        for block in typ.directory.entries:
            for language in block.directory.entries:
                d = language.data.struct
                raw = pe.get_data(d.OffsetToData, d.Size)
                off = 0
                for i in range(16):
                    n = int.from_bytes(raw[off:off + 2], "little")
                    off += 2
                    text = raw[off:off + 2 * n].decode("utf-16-le")
                    off += 2 * n
                    if text:
                        result[16 * (block.id - 1) + i] = text
    return result


class UiVM(IOVM):
    def read(self, at, size=4):
        if all(at + i in self.mem for i in range(size)):
            return super().read(at, size)
        if 0 <= at - self.base < self.pe.OPTIONAL_HEADER.SizeOfImage:
            raw = self.pe.get_data(at - self.base, size)
            assert len(raw) == size
            return int.from_bytes(raw, "little")
        raise AssertionError(f"Read outside initialized memory: {at:x}")

    def text(self, at):
        units = []
        for _ in range(512):
            unit = self.read(at, 2)
            if not unit:
                return bytes().join(u.to_bytes(2, "little") for u in units).decode("utf-16-le")
            units.append(unit)
            at += 2
        raise AssertionError("Unterminated text")


def loader(raw, requested, current=32, fail=False):
    pe = pefile.PE(data=raw)
    vm = UiVM(pe, [(0x14d58, 0x14eb0)])
    vm.write(0x3780c, current)
    vm.reg[4], vm.reg[29], vm.reg[31] = requested & 0xffffffff, STACK, STOP
    saved = {r: 0x12340000 + r for r in (16, 17, 18)}
    for r, value in saved.items():
        vm.reg[r] = value
    events = []
    english = strings(SYSTEM / "data/LangDllEng.dll")
    loaded = {}

    def load(m):
        path = m.text(m.reg[4])
        events.append(("load", path))
        if fail:
            return 0
        assert path == "\\Storage Card\\system\\data\\LangDllEng.dll"
        return 0x5555

    def get(m):
        handle, ident, destination, capacity = m.reg[4:8]
        assert handle == 0x5555 and ident in IDS and capacity == 0x104
        text = english[ident]
        assert len(text) < capacity
        for i, value in enumerate((text + "\0").encode("utf-16-le")):
            m.write(destination + i, value, 1)
        loaded[ident] = m.text(destination)
        events.append(("string", ident))
        return len(text)

    def free(m):
        assert m.reg[4] == 0x5555
        events.append(("free", 0x5555))
        return 1

    vm.hooks = {0x2a350: load, 0x2a210: get, 0xf0010040: free}
    vm.write(0x370fc, 0xf0010040)
    before = dict(vm.mem)
    vm.run(0x14d58, {STOP})
    assert vm.reg[29] == STACK and vm.reg[31] == STOP
    assert all(vm.reg[r] == v for r, v in saved.items())
    for at, value in vm.mem.items():
        assert (before.get(at) == value or STACK - 0x20 <= at < STACK or
                0x3780c <= at < 0x37810 or
                any(buf <= at < buf + 0x208 for buf in BUFFERS)), hex(at)
    return vm, loaded, events


def draw_cancel(raw):
    vm = UiVM(pefile.PE(data=raw), [(0x123bc, 0x123d8)])
    vm.reg[29], vm.reg[19], vm.reg[23], vm.reg[22] = STACK, 0x4444, 0x14178, 5
    captured = []

    def draw(m):
        captured.append((m.text(m.reg[5]), m.reg[6], m.reg[7], m.read(STACK + 0x10)))
        return 1

    vm.hooks = {0x12778: draw}
    vm.run(0x123bc, {0x123d8})
    assert len(captured) == 1
    return captured[0]


def draw_progress(vm):
    # Execute the actual RTL/LTR dispatch, carrying language state and loaded text.
    vm.ranges = [(0x190f8, 0x19160)]
    vm.reg[29], vm.reg[9], vm.reg[10] = STACK, 0x103, 3 << 16
    vm.reg[18], vm.reg[19], vm.reg[20] = 0x4444, 31, 21
    captured = []

    def draw(m):
        captured.append((m.text(m.reg[5]), m.read(STACK + 0x10)))
        return 1

    vm.hooks = {0x2a400: draw}
    vm.run(0x190f8, {0x19160})
    assert len(captured) == 1
    return captured[0]


def verify(originals, candidates):
    original = originals["UpgradeManager.exe"]
    candidate = candidates["UpgradeManager.exe"]
    cases = list(range(32)) + [32, 33, 256, 0x7fffffff, 0x80000000, 0xffffffff]
    english = strings(SYSTEM / "data/LangDllEng.dll")
    checks = 0
    for requested in cases:
        for current in (0, 2, 32):
            vm, loaded, events = loader(candidate, requested, current)
            if current == 2:
                assert events == [] and loaded == {}
            else:
                assert vm.read(0x3780c) == 2
                assert loaded == {ident: english[ident] for ident in IDS}
                assert len(events) == 10
                warning, flags = draw_progress(vm)
                assert warning == english[1211] and flags == 1, "English/LTR progress text"
            checks += 1
    failed, loaded, events = loader(candidate, 0, fail=True)
    assert loaded == {} and len(events) == 1 and failed.read(0x3780c) == 2
    # The same failure-state behavior already existed: report it, do not claim recovery.
    old, loaded_old, events_old = loader(original, 2, fail=True)
    assert loaded_old == {} and len(events_old) == 1 and old.read(0x3780c) == 2
    original_english, old_text, _ = loader(original, 2)
    _, new_text, _ = loader(candidate, 0)
    assert old_text == new_text
    assert draw_progress(original_english) == (english[1211], 1)
    original_english.write(0x3780c, 0)
    assert draw_progress(original_english) == (english[1211], 0x20001)
    assert draw_cancel(originals["dmenu.exe"]) == ("Annuler", 7, 0x14178, 5)
    assert draw_cancel(candidates["dmenu.exe"]) == ("Cancel", 6, 0x14178, 5)
    text_checks = 0
    for name, pairs in LABELS.items():
        for old_text, new_text in pairs:
            old = (old_text + "\0").encode("utf-16-le")
            at = originals[name].index(old)
            new = (new_text + "\0").encode("utf-16-le")
            assert candidates[name][at:at + len(old)] == new.ljust(len(old), b"\0")
            text_checks += 1
    return dict(language_loader_cases=checks, utf16_translation_slots=text_checks,
                explicit_cancel_draw_cases=2, english_warning_ltr_cases=checks * 2 // 3 + 1,
                load_failure_cases=2, original_english_text_matches=True,
                abi_preserved=True, firmware_native_execution=False, hardware_tested=False,
                caveats=["CE library/GDI APIs are fixtures, not a native rendering test",
                         "Library-load failure caches the selected language as in the original",
                         "Screens rendered by the previously installed updater are outside this change"])


if __name__ == "__main__":
    import json
    originals = {name: (SYSTEM / name).read_bytes() for name in LABELS}
    candidates = {name: patch(name, raw)[0] for name, raw in originals.items()}
    print(json.dumps(verify(originals, candidates), indent=2))
