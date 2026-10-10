"""Recheck a prior text-bug claim against actual MAX03 comparator instructions."""
import json
from pathlib import Path
import pefile
from verify_ui_english import UiVM, STACK
from inspect_wave_queue import STOP

ROOT = Path(__file__).resolve().parents[1]


def main():
    path = ROOT / "build/maxmade-7.0.6.MAX03/roundtrip/upgrade/Storage Card/System/AppMain.exe"
    raw = path.read_bytes()
    pe = pefile.PE(data=raw)
    assert int.from_bytes(pe.get_data(0x13974c - pe.OPTIONAL_HEADER.ImageBase, 4), "little") == 0x2405010e
    results = []
    for limit in (128, 270):
        cases = [([65] * (limit + 1) + [0], [65] * (limit + 1) + [0], 0)]
        for position in range(limit + 1):
            old = [65] * (limit + 1) + [0]
            new = old.copy()
            new[position] = 66
            cases.append((old, new, int(position < limit)))
        cases.extend([([0], [0], 0), ([65, 0], [0], 1), ([0, 65, 0], [0, 66, 0], 0)])
        for old, new, expected in cases:
            vm = UiVM(pe, [(0x1381c8, 0x13822c)])
            for ptr, units in ((0x41000000, old), (0x42000000, new)):
                for i, unit in enumerate(units):
                    vm.write(ptr + 2 * i, unit, 2)
            vm.reg[4:7] = [0x41000000, limit, 0x42000000]
            vm.reg[29], vm.reg[31] = STACK, STOP
            vm.run(0x1381c8, {STOP})
            assert vm.reg[2] == expected, (limit, expected)
            assert vm.reg[29] == STACK and vm.reg[31] == STOP
        results.append(dict(capacity=limit, cases=len(cases), full_capacity_changes_detected=True))
    result = dict(checks=results, total_cases=sum(r["cases"] for r in results),
                  conclusion="APP-03 withdrawn: the comparator honors caller capacity; the extended setter passes 270, not 128",
                  native_execution=False)
    out = ROOT / "analysis/firmware/appmain-text-compare-recheck.json"
    out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
