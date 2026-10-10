"""Run original updater paint bytes with explicit GDI failure fixtures.

No native CE code, device access, pixels, flash operation or firmware edit.
The fixture proves control flow after API failures, not a photographed colour.
"""
import hashlib
import json
from pathlib import Path

import pefile
from inspect_wave_queue import STOP
from verify_ui_english import UiVM, strings

ROOT = Path(__file__).resolve().parents[1]
SYSTEM = ROOT / "extracted/705md/upgrade/Storage Card/System"
SOURCE = SYSTEM / "UpgradeManager.exe"
EXPECTED = "4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87"
STACK, OBJECT, DISPLAY = 0x68000000, 0x46000000, 0x44000000


def paint(raw, theme, phase, language, failure):
    vm = UiVM(pefile.PE(data=raw), [(0x18e88, 0x19714)])
    vm.reg[4], vm.reg[5], vm.reg[29], vm.reg[31] = OBJECT, DISPLAY, STACK, STOP
    saved = {r: 0x12340000 + r for r in range(16, 24)}
    saved[30] = 0x1234001e
    for r, value in saved.items():
        vm.reg[r] = value
    vm.write(0x38ef8, theme)
    vm.write(0x3784c, phase)
    vm.write(0x3780c, language)
    vm.write(OBJECT + 0x618, 0)
    vm.write(OBJECT + 0x620, 0)
    table = strings(SYSTEM / "data" / ("LangDllAra.dll" if language == 0 else "LangDllEng.dll"))
    for ident, at in [(1210, 0x37eac), (1211, 0x37ca4)]:
        for i, byte in enumerate((table[ident] + "\0").encode("utf-16-le")):
            vm.write(at + i, byte, 1)
    events, resources, handles = [], [], 0x5000

    def allocate():
        nonlocal handles
        handles += 1
        return handles

    def load(m):
        path = m.text(m.reg[4])
        background = path.endswith("etc_bg.bmp")
        relative = path.split("\\system\\", 1)[1].replace("\\", "/")
        assert (SYSTEM / relative).is_file(), path
        fails = failure == "both_missing" or failure == ("background_missing" if background else "gauge_missing")
        handle = 0 if fails else allocate()
        resources.append(handle)
        events.append(dict(api="SHLoadDIBitmap", path=path, result=handle))
        return handle

    def select(m):
        events.append(dict(api="SelectObject", dc=m.reg[4], object=m.reg[5]))
        return 0 if m.reg[5] == 0 else 0x6000

    def blit(m):
        width, height = m.reg[7], m.read(m.reg[29] + 0x10)
        # For resource-failure cases we only check continuation after null
        # handles; CE's resulting bitmap pixels are deliberately not modeled.
        result = int(failure != "blit_failure")
        events.append(dict(api="BitBlt", dc=m.reg[4], width=width, height=height, result=result))
        return result

    def draw(m):
        events.append(dict(api="DrawTextW", text=m.text(m.reg[5]), flags=m.read(m.reg[29] + 0x10)))
        return 1

    def zero(m):
        for i in range(m.reg[6]):
            m.write(m.reg[4] + i, m.reg[5] & 255, 1)
        return m.reg[4]

    def format_font(m):
        assert m.text(m.reg[5]) == "Tahoma"
        for i, byte in enumerate("Tahoma\0".encode("utf-16-le")):
            m.write(m.reg[4] + i, byte, 1)
        return 6

    vm.hooks = {
        0x2a390: load, 0x2a370: lambda m: allocate(),
        0x2a4d0: lambda m: allocate(), 0x2a380: select,
        0x2a3a0: blit, 0x2b68c: zero, 0x2a3f0: format_font,
        0x2a400: draw, 0x2a1f0: lambda m: allocate(),
        0x2a3b0: lambda m: 1, 0x2a1d0: lambda m: 1,
        0x2a3d0: lambda m: 1, 0x2a3e0: lambda m: 0,
        0x2a4f0: lambda m: 0,
    }
    vm.run(0x18e88, {STOP})
    assert vm.reg[29] == STACK and all(vm.reg[r] == value for r, value in saved.items())
    assert len(resources) == 2
    texts = [e for e in events if e["api"] == "DrawTextW"]
    assert [e["text"] for e in texts] == [table[1210], table[1211]]
    assert all(e["flags"] == (0x20001 if language == 0 else 1) for e in texts)
    blits = [e for e in events if e["api"] == "BitBlt"]
    assert blits[-1]["dc"] == DISPLAY and blits[-1]["width"] == 800 and blits[-1]["height"] == 480
    gauge_count = sum(e["width"] == 36 for e in blits)
    assert (gauge_count == 0) == (phase == 3000)
    return dict(theme=theme, phase=phase, language=language, failure=failure,
                gauge_blits=gauge_count, events=events)


def main():
    raw = SOURCE.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == EXPECTED
    cases = [paint(raw, ui, phase, language, failure)
             for ui in range(3) for phase in range(3000, 3007)
             for language in (0, 2)
             for failure in ("none", "background_missing", "gauge_missing", "both_missing", "blit_failure")]
    report = dict(source=str(SOURCE.relative_to(ROOT)), sha256=EXPECTED,
                  tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
                  limits="Actual MIPS paint control flow; explicit API fixtures. No CE renderer, photograph matching, storage or flash simulation.",
                  cases=len(cases), traces=cases)
    out = ROOT / "analysis/issue-upgrade-stalls/progress-screen-traces.json"
    out.write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
    print(f"PASS: {len(cases)} original-byte paint cases; null bitmap and failed blit paths continue without error feedback.")


if __name__ == "__main__":
    main()
