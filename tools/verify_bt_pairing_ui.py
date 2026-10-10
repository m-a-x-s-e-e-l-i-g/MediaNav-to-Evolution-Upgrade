"""Follow patched paired-record copy into the original four-row name renderer.

This interprets MIPS bytes with explicit Unicode/control API fixtures. It does
not render pixels, run CE, prove all cache aliases, or authorize an LGU build.
"""
import hashlib
import json
import struct
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, MANAGER, data, put, abi
from verify_bt_database_io import IOVM
from draft_bt_pairing_storage import draft_app_pairing, PAIRS

COOKIE, DIALOG, COORDINATOR, STATE = 0x1234abcd, 0x48000000, 0x49000000, 0x4a000000
SHARED, VTABLE, CONTROL_API, CONVERT_API, DEBUG_API = 0x4b000000, 0x4c000000, 0xf0030010, 0xf0030020, 0xf0030030
NAMES = ["Telefoon", "Émile", "Müller", "Ελένη", "日本語", "Žofie", "Телефон", "Device8"]


class UIVM(IOVM):
    def plain(self, word):
        op, rs, rt, rd, fn = word >> 26, (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, word & 63
        if op == 0 and fn == 0x26:
            self.reg[rd] = self.reg[rs] ^ self.reg[rt]
        elif op == 0x21:
            offset = word & 0xffff
            if offset & 0x8000: offset -= 0x10000
            value = self.read((self.reg[rs] + offset) & 0xffffffff, 2)
            self.reg[rt] = value if value < 0x8000 else (value - 0x10000) & 0xffffffff
        else:
            super().plain(word)
        self.reg[0] = 0


def wide(vm, address):
    values = []
    for offset in range(0, 520, 2):
        unit = vm.read(address + offset, 2)
        if not unit: return b"".join(struct.pack("<H", u) for u in values).decode("utf-16le")
        values.append(unit)
    raise AssertionError("Fixture text has no terminator within label bound")


def case(pe, count, page, connected, draw=0, connected_status=0, click=None, after_click=None, names=None):
    names = NAMES if names is None else names
    vm = UIVM(pe, [(0x110708, 0x1108f0), (0xcfcb8, 0xd0794),
                  (0xcf77c, 0xcfcb8), (0xd0b60, 0xd0d5c), (0xd0f24, 0xd10d8),
                  (0x11afcc, 0x11b044), (0xd08b0, 0xd0b60)])
    vm.write(0x187be4, MANAGER); vm.write(MANAGER + 0xa0, OBJECT)
    vm.write(MANAGER + 0xa4, COORDINATOR); vm.write(MANAGER + 0xa8, STATE)
    vm.write(OBJECT + 0x26c, count); vm.write(OBJECT + 0x5a4, 0xffffffff)
    vm.write(OBJECT + 0xc, SHARED)
    vm.write(STATE + 0x618, int(connected is not None)); vm.write(STATE + 0x10, 2)
    vm.write(STATE + 0x6b8, 1); vm.write(COORDINATOR + 0x20, 0)
    vm.write(DIALOG + 0x63bc, page); vm.write(DIALOG + 0x63c4, count)
    vm.write(DIALOG + 0x63c0, (count + 3) // 4)
    vm.write(OBJECT + 0x20, 1234)
    vm.write(DIALOG, VTABLE)
    vm.write(0x1853f4, COOKIE); vm.write(0x185088, CONVERT_API); vm.write(0x1852bc, DEBUG_API)
    # The computed switch reads signed halfword offsets from the PE, not from RAM fixtures.
    put(vm, 0xcf7d0, pe.get_data(0xcf7d0 - pe.OPTIONAL_HEADER.ImageBase, 24))
    for offset in (0, 0x1c, 0x20, 0x24, 0x30): vm.write(VTABLE + offset, CONTROL_API)
    for row in range(4):
        vm.write(DIALOG + 0x61c + row * 0x890, VTABLE)
        vm.write(DIALOG + 0x586c + row * 0x74, VTABLE)
    vm.write(DIALOG + 0x4a9c, VTABLE)
    for offset in (0x5a3c, 0x5ab0, 0x5b24): vm.write(DIALOG + offset, VTABLE)
    records = []
    for index in range(count):
        record = bytearray(64)
        record[0] = int(index == connected)
        record[2] = connected_status if index == connected else 0
        record[4:8] = (index + 1).to_bytes(4, "little")
        name = names[index].encode("utf-8")
        record[12:12 + len(name)] = name
        records.append(bytes(record)); put(vm, SHARED + index * 64, record)
    labels, conversions, controls, popups = [], [], [], []
    resource = 0x4d000000
    put(vm, resource, "Fixture\0".encode("utf-16le"))

    def memset(machine):
        at, value, size = machine.reg[4:7]
        put(machine, at, bytes([value & 255]) * size); return at

    def convert(machine):
        codepage, flags, origin, size = machine.reg[4:8]
        assert (codepage, flags, size) == (65001, 8, 50)
        index = (origin - OBJECT - 0x27c) // 64
        assert origin == OBJECT + 0x27c + index * 64 and 0 <= index < count
        destination, capacity = machine.read(machine.reg[29] + 0x10), machine.read(machine.reg[29] + 0x14)
        assert capacity == 50 and destination == machine.reg[29] + 0x80
        text = data(machine, origin, size).decode("utf-8")
        encoded = text.encode("utf-16le"); assert len(encoded) <= capacity * 2
        put(machine, destination, encoded)
        conversions.append(dict(record=index, source=hex(origin), text=text.split("\0")[0]))
        return len(encoded) // 2

    def label(machine):
        destination, origin = machine.reg[4:6]
        labels.append(dict(destination=hex(destination), text=wide(machine, origin)))
        return 0

    def control(machine):
        controls.append(machine.reg[4:7].copy()); return 0

    def cookie(machine):
        assert machine.reg[4] == COOKIE; return 0

    def format_text(machine):
        assert machine.reg[5] == 0x103
        raw_format = pe.get_data(machine.reg[6] - pe.OPTIONAL_HEADER.ImageBase, 32)
        format_units = [raw_format[n:n + 2] for n in range(0, len(raw_format), 2)]
        format_text = b"".join(format_units[:format_units.index(b"\0\0")]).decode("utf-16le")
        if format_text == "%d/%d":
            # Native page-controls pass the current page and total as printf arguments.
            assert 1 <= machine.reg[7] <= 2
            text = f"{machine.reg[7]}/{machine.read(machine.reg[29] + 0x10)}"
        else:
            assert format_text == "%s", format_text
            text = wide(machine, machine.reg[7])
        put(machine, machine.reg[4], (text + "\0").encode("utf-16le")); return len(text)

    def popup(machine):
        assert machine.reg[4] == DIALOG and machine.reg[7] == 0
        assert machine.read(machine.reg[29] + 0x10) == machine.read(machine.reg[29] + 0x14) == 1
        descriptor = machine.reg[6]
        popups.append(dict(command=hex(machine.read(descriptor + 0x1c)),
                           parameter=machine.read(descriptor + 0x20),
                           timeout_ms=machine.read(descriptor + 0x14),
                           descriptor_hex=data(machine, descriptor, 0x30).hex()))
        return 0

    vm.hooks.update({0x140de4: memset, CONVERT_API: convert,
                     DEBUG_API: lambda _: 0, 0x139104: lambda _: 0, 0x139668: label,
                     CONTROL_API: control, 0x139020: lambda _: 0,
                     0x13d220: lambda _: 0,
                     0x1f8e0: lambda _: resource, 0x1fa44: lambda _: resource,
                     0x140320: format_text, 0x12e48: lambda _: resource,
                     0x135778: popup,
                     0x1392c0: lambda _: 0, 0x140298: cookie})
    abi(vm, 0x110708, OBJECT)
    before = data(vm, OBJECT + 0x270, PAIRS * 64)
    vm.reg[5] = draw
    abi(vm, 0xcfcb8, DIALOG)
    assert data(vm, OBJECT + 0x270, PAIRS * 64) == before
    expected_indices = list(range(page * 4, min(count, page * 4 + 4)))
    assert [c["record"] for c in conversions] == expected_indices
    for row, index in enumerate(expected_indices):
        target = hex(DIALOG + 0x690 + row * 0x890)
        assert [l["text"] for l in labels if l["destination"] == target] == [names[index]]
    page_label = hex(DIALOG + 0x5b24)
    assert [l["text"] for l in labels if l["destination"] == page_label] == [f"{page + 1}/{(count + 3) // 4}"]
    for offset in (0x5a68, 0x5adc, 0x5b50):
        assert bool(vm.read(DIALOG + offset) & 0x80) == (count > 4)
    if connected is not None:
        assert vm.read(OBJECT + 0x5a4) == connected
        assert vm.read(OBJECT + 0x5c0) == SHARED + connected * 64
    click_result = None
    if click is not None:
        event, argument = click
        old_page = vm.read(DIALOG + 0x63bc)
        old_names = len(conversions)
        vm.reg[5:7] = [event, argument]
        abi(vm, 0xcf77c, DIALOG)
        if event in (0x3f1, 0x3f2):
            pages = (count + 3) // 4
            new_page = old_page if argument == 5 else (old_page + (-1 if event == 0x3f1 else 1)) % pages
            assert vm.read(DIALOG + 0x63bc) == new_page
            expected_after = [] if argument == 5 else list(range(new_page * 4, min(count, new_page * 4 + 4)))
            assert [c["record"] for c in conversions[old_names:]] == expected_after
            assert not popups
            if argument != 5:
                assert [l["text"] for l in labels if l["destination"] == page_label][-1] == f"{new_page + 1}/{pages}"
            click_result = dict(event=hex(event), argument=argument, page_after=new_page, redraw_indices=expected_after)
        else:
            deleting = 0x3ed <= event <= 0x3f0
            row = event - (0x3ed if deleting else 0x3e9)
            index = page * 4 + row
            assert 0 <= index < count and connected is None
            assert len(popups) == 1
            expected_command = "0x1010701" if deleting else "0x1010804"
            expected_parameter = index + 1 if deleting else (1234 << 16) | (index + 1)
            assert popups[0]["command"] == expected_command and popups[0]["parameter"] == expected_parameter
            if not deleting:
                assert vm.read(STATE + 0x620) == index and vm.read(STATE + 0x624) == 1
                assert popups[0]["timeout_ms"] == 30000
            click_result = dict(event=hex(event), action="delete" if deleting else "connect",
                                selected_index=index, popup=popups[0], radio_execution=False)
        assert data(vm, OBJECT + 0x270, PAIRS * 64) == before
    confirmation = after_click(vm, click_result) if after_click is not None else None
    return dict(count=count, page=page, connected=connected, draw=draw, connected_status=connected_status,
                rendered_indices=expected_indices,
                labels=labels, conversions=conversions, control_calls=controls,
                click=click_result, confirmation=confirmation,
                exact_names=True, records_unchanged=True, abi_preserved=True,
                scope="Patched copy plus original renderer; explicit converter/widget/drawing API fixtures")


def active_scan(pe, connected):
    vm = UIVM(pe, [(0x111d84, 0x111e08), (0x11afcc, 0x11b044)])
    vm.write(OBJECT + 0xc, SHARED)
    vm.write(OBJECT + 0x5c0, 0xdeadbeef); vm.write(OBJECT + 0x5a4, 0xffffffff)
    for index in range(PAIRS):
        record = bytearray(64)
        record[0] = int(index == connected)
        put(vm, SHARED + index * 64, record)
    abi(vm, 0x111d84, OBJECT)
    return dict(connected=connected, result_pointer=hex(vm.read(OBJECT + 0x5c0)),
                result_index=hex(vm.read(OBJECT + 0x5a4)), abi_preserved=True,
                scope="Actual active scan and shared-pointer helper; valid mapped eight-slot fixture")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    src, _ = source(module, [0x110708, 0xcfcb8, 0x1109d4, 0x11095c, 0xd3dc0,
                            0xcf77c, 0xd0b60, 0xd0f24, 0xd08b0], {0x11095c: 0x78})
    # Include sources for native shared-pointer lookup and the newly found rescan cap.
    extra_src, _ = source(module, [0x111d84, 0x11afcc], {})
    raw = (ROOT / module["path"]).read_bytes()
    patched, patch = draft_app_pairing(raw)
    pe = pefile.PE(data=patched)
    original_pe = pefile.PE(data=raw)
    checks = [case(pe, count, page, connected) for count in range(1, PAIRS + 1)
              for page in range((count + 3) // 4) for connected in (None, *range(count))]
    checks += [case(pe, PAIRS, page, connected, 1, state) for page in (0, 1)
               for connected in range(PAIRS) for state in (0, 4, 7)]
    checks += [case(pe, count, index // 4, None, click=(base + index % 4, 2))
               for count in range(1, PAIRS + 1) for index in range(count) for base in (0x3e9, 0x3ed)]
    checks += [case(pe, count, page, None, click=(event, argument)) for count in range(1, PAIRS + 1)
               for page in range((count + 3) // 4) for event in (0x3f1, 0x3f2) for argument in (2, 5)]
    scan_traces = []
    for connected in (None, *range(PAIRS)):
        baseline, repaired = active_scan(original_pe, connected), active_scan(pe, connected)
        for trace, limit in ((baseline, 5), (repaired, PAIRS)):
            found = connected is not None and connected < limit
            assert trace["result_pointer"] == hex(SHARED + connected * 64 if found else 0xdeadbeef)
            assert trace["result_index"] == hex(connected if found else 0xffffffff)
        scan_traces.append(dict(original=baseline, draft=repaired))
    out = ROOT / "analysis/firmware/bt-pairing-ui-draft"
    out.mkdir(parents=True, exist_ok=True)
    dependencies = ["verify_bt_pairing_ui.py", "verify_bt_database_io.py", "verify_bt_pairing_storage.py",
                    "draft_bt_pairing_storage.py", "draft_bt_database_io.py", "patch_bt_playback.py",
                    "inspect_bt_pairing.py", "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="paired-copy to four-row renderer fixture checks passed",
                  native_execution=False, unit_tested=False, build_allowed=False,
                  source=src, extra_source=extra_src, patch_sha256=patch["draft_sha256"], checks=checks,
                  active_rescan_traces=scan_traces,
                  limitations=["Unicode conversion and widget APIs are explicit fixtures; no pixels or native CE",
                               "Selection/deletion popup indices and page-button redraws covered; popup confirmation and radio execution remain open",
                               "Concrete nonempty valid UTF-8 names; empty-name/address fallback and empty list not exercised",
                               "Not proof of absence of indirect name-cache aliases or full GUI behavior"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], checks=len(checks), report=str(out / "contracts.json")), indent=2))


if __name__ == "__main__":
    main()
