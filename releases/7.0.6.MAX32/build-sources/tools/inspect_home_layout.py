"""Recover home control geometry by bounded interpretation of original MIPS.

CE, language lookup and GUI construction use explicit fixtures. This records
original instruction behavior, not a running firmware or GDI rendering test.
"""
import hashlib
import json
from pathlib import Path

import pefile
from verify_ui_english import UiVM, strings
from inspect_wave_queue import STOP

ROOT = Path(__file__).resolve().parents[1]
SYSTEM = ROOT / "extracted/705md/upgrade/Storage Card/System"
APP_SHA = "6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8"
OBJECT, STATUS, RES, MAIN, PHONE, STACK = (
    0x41000000, 0x42000000, 0x43000000, 0x44000000, 0x45000000, 0x68000000)


def trace(ui_type, eco, map_layout, resource_profile, smartphone=False, raw=None):
    if raw is None:
        raw = (SYSTEM / "AppMain.exe").read_bytes()
        assert hashlib.sha256(raw).hexdigest() == APP_SHA
    pe = pefile.PE(data=raw)
    vm = UiVM(pe, [(0x21c50, 0x225c0), (0x23a0c, 0x23f0c)])
    for address, size in [(OBJECT, 0x4000), (STATUS, 0x3000), (RES, 0x800),
                          (MAIN, 0x100), (PHONE, 0x1000), (STACK-0x500, 0x600)]:
        for at in range(address, address+size, 4):
            vm.write(at, 0)
    vm.write(0x186538, RES)
    vm.write(0x187b38, STATUS)
    vm.write(0x186ce8, MAIN)
    vm.write(0x187be4, MAIN)
    vm.write(0x186100, 0)
    vm.write(RES+0x6d8, resource_profile)
    vm.write(MAIN+0xa8, PHONE)
    vm.write(MAIN+0xa4, PHONE)
    vm.write(PHONE+0x6bc, int(smartphone))
    language = strings(SYSTEM / "data/LangDllEng.dll")
    records = {}

    def reg_get(m):
        name = m.text(m.reg[6])
        return {"UI_TYPE": ui_type, "HMI_ECO_CNF": eco}.get(name, m.reg[7])

    def label(m):
        ident = m.reg[5]
        if ident not in language:
            raise ValueError(f"Unmapped English string id {ident:x}")
        return 0x50000000 + ident*0x400

    def signed(value):
        return value if value < 0x80000000 else value-0x100000000

    def words(address):
        return [signed(vm.read(address+i*4)) for i in range(4)]

    def control(m, is_button):
        _, obj, image_id, area = m.reg[4:8]
        rect = words(area)
        for index, value in enumerate(rect):
            m.write(obj+8+index*4, value & 0xffffffff)
        m.write(obj+0x2c, 0x183)
        record = dict(object_offset=hex(obj-OBJECT), image_id=image_id,
                      rect=rect, kind="button" if is_button else "image")
        if is_button:
            args = [m.read(m.reg[29]+0x10+i*4) for i in range(9)]
            event, font, text_ptr, text_area, colors, flags = args[:6]
            text = language.get((text_ptr-0x50000000)//0x400, "") if text_ptr >= 0x50000000 else m.text(text_ptr)
            relative = words(text_area) if text_area else [0, 0, rect[2], rect[3]]
            label_rect = [rect[0]+relative[0], rect[1]+relative[1], *relative[2:]]
            for index, value in enumerate(label_rect):
                m.write(obj+0x53c+index*4, value & 0xffffffff)
            record.update(event=event, font_index=font, text=text, label_rect=label_rect,
                          colors=words(colors) if colors else None, text_flags=flags)
        else:
            record["frame_count"] = m.read(m.reg[29]+0x10)
        records[obj] = record
        return 0

    def label_rect(m):
        obj, area = m.reg[4:6]
        original = words(obj+8)
        relative = words(area) if area else [0, 0, original[2], original[3]]
        rect = [original[0]+relative[0], original[1]+relative[1], *relative[2:]]
        for index, value in enumerate(rect):
            m.write(obj+0x53c+index*4, value & 0xffffffff)
        if obj in records:
            records[obj]["label_rect"] = rect
        return 0

    def choose_image(m):
        if m.reg[4] in records:
            records[m.reg[4]]["image_id"] = m.reg[5]
        return 0

    def choose_text(m):
        control_obj = m.reg[4]-0x74
        ident = (m.reg[5]-0x50000000)//0x400
        if control_obj in records and ident in language:
            records[control_obj]["text"] = language[ident]
        return 0

    vm.hooks = {
        0x137a68: reg_get, 0x13dde0: lambda m: 1,
        0x14638: lambda m: 1, 0x1f8e0: lambda m: 1, 0x1fa44: label,
        0x13d488: lambda m: control(m, True),
        0x13d2ec: lambda m: control(m, False),
        0x138e90: lambda m: 0, 0x13ee10: label_rect,
        0x139104: choose_image, 0x139668: choose_text, 0x139020: lambda m: 0,
        0xd936c: lambda m: 0,
        0x13ff08: lambda m: 0,  # Compiler security-cookie fixture.
    }
    # Imported SetTimer is a fixture, not a timer/thread on the host or device.
    for descriptor in pe.DIRECTORY_ENTRY_IMPORT:
        for symbol in descriptor.imports:
            # Resolve ordinal via the preserved coredll export table.
            if symbol.name == b"SetTimer":
                vm.hooks[vm.read(symbol.address)] = lambda m: 1
    core = pefile.PE(str(ROOT / "extracted/705md-rom/fs/Windows/coredll.dll"))
    timer_ord = next(s.ordinal for s in core.DIRECTORY_ENTRY_EXPORT.symbols if s.name == b"SetTimer")
    for descriptor in pe.DIRECTORY_ENTRY_IMPORT:
        if descriptor.dll.lower() == b"coredll.dll":
            for symbol in descriptor.imports:
                if symbol.ordinal == timer_ord:
                    vm.hooks[vm.read(symbol.address)] = lambda m: 1
    for entry, arg in [(0x21c50, None), (0x23a0c, map_layout)]:
        vm.reg[4], vm.reg[5], vm.reg[29], vm.reg[31] = OBJECT, arg or 0, STACK, STOP
        vm.run(entry, {STOP}, limit=12000)
        assert vm.reg[29] == STACK
    catalog = json.loads((ROOT / "analysis/firmware/appmain-startup-contracts.json").read_text())["resources"]
    for obj, record in records.items():
        record["rect"] = words(obj+8)
        if record["kind"] == "button":
            record["label_rect"] = words(obj+0x53c)
        record["filename"] = catalog[record["image_id"]]["filename"]
    return dict(ui_type=ui_type, eco=eco, map_layout=map_layout,
                resource_profile=resource_profile, smartphone=smartphone,
                controls=list(records.values()), native_execution=False)


def main():
    scenarios = [trace(ui, eco, layout, profile, smart)
                 for ui, profile in [(0, 0), (1, 1), (1, 3)]
                 for eco in (0, 1) for layout in (0, 1) for smart in (False, True)]
    ordinary = scenarios[8]
    by_id = {r["image_id"]: r for r in ordinary["controls"]}
    assert by_id[0x2a]["rect"] == [76, 114, 210, 137]
    assert by_id[0x2b]["rect"] == [295, 114, 210, 137]
    assert by_id[0x2c]["rect"] == [514, 114, 210, 137]
    assert by_id[0x30]["rect"] == [76, 262, 210, 137]
    assert by_id[0x31]["rect"] == [295, 262, 210, 137]
    assert by_id[0x32]["rect"] == [514, 262, 210, 137]
    assert by_id[0x2a]["label_rect"] == [90, 203, 180, 35]
    assert by_id[0x2a]["colors"] == [0xffffff, 0, 0x75787a, 0]
    result = dict(app_sha256=APP_SHA, instruction_entries=["0x21c50", "0x23a0c"],
                  scenarios=scenarios, native_execution=False, hardware_tested=False,
                  limitations=["GUI constructors, registry, language and timers are fixtures",
                               "Native fonts/transparency/rendering remain unverified"])
    target = ROOT / "analysis/firmware/home-layout.json"
    target.write_text(json.dumps(result, indent=2)+"\n", encoding="utf-8")
    print(json.dumps(dict(scenarios=len(scenarios), ordinary_home=ordinary, output=str(target)), indent=2))


if __name__ == "__main__":
    main()
