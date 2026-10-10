"""Check MGR dispatch constants and selected caller selectors against source PE bytes."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]


def read(pe, va, size):
    data = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, size)
    if len(data) != size:
        raise ValueError(f"Missing bytes at {va:#x}")
    return data


def immediate(pe, va):
    word = struct.unpack("<I", read(pe, va, 4))[0]
    if word >> 26 != 9 or (word >> 21) & 31:
        raise ValueError(f"Expected ADDIU register,$zero,immediate at {va:#x}")
    return word & 0xffff


def main():
    path = ROOT / "extracted/705md-rom/fs/Windows/DRVMGR.dll"
    pe = pefile.PE(str(path))
    guard = struct.unpack("<I", read(pe, 0xc09a1964, 4))[0]
    if guard >> 26 != 11 or (guard >> 21) & 31 != 5:
        raise ValueError("MGR command-count guard changed")
    count = guard & 0xffff
    table_va = 0xc09a1990
    offsets = struct.unpack(f"<{count}h", read(pe, table_va, count * 2))
    selectors = [immediate(pe, va) for va in (0xc09a14e0, 0xc09a14ec, 0xc09a14f8, 0xc09a1504)]
    if struct.unpack("<I", read(pe, 0xc09a194c, 4))[0] != 0x27bdffd8:
        raise ValueError("MGR stack frame changed")
    gpio_output_loads = []
    for va in (0xc09a1a00, 0xc09a1a30, 0xc09a1a70):
        if struct.unpack("<I", read(pe, va, 4))[0] != 0x8fab0040:
            raise ValueError("MGR GPIO output argument changed")
        gpio_output_loads.append(dict(va=hex(va), instruction_hex=read(pe, va, 4).hex(),
                                      load_stack_offset=64, entry_stack_offset=24, o32_argument=7))
    calls = []
    for origin, module, va, expectation in (
        ("705md", "Blue.exe", 0x33ce4, "Bluetooth reinitialize/destroy reset helper"),
        ("705md", "MicomManager.exe", 0x1eac8, "Conditional manager reset helper"),
        ("remove-md", "Blue.exe", 0x2c564, "Downgrade Bluetooth reset helper"),
    ):
        source = ROOT / "extracted" / origin / "upgrade/Storage Card/System" / module
        caller = pefile.PE(str(source))
        selector = immediate(caller, va)
        calls.append(dict(origin=origin, module=module, source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
                          immediate_va=hex(va), instruction_hex=read(caller, va, 4).hex(), selector=selector,
                          selector_hex=hex(selector), ioctl=0, context=expectation,
                          supported_by_examined_rom_reset_helper=selector in selectors))
        caller.close()
    result = dict(scope="Static call/driver contract evidence; active unit binaries and physical GPIO wiring unresolved",
                  driver_sha256=hashlib.sha256(path.read_bytes()).hexdigest(),
                  ioctl_count_guard_va="0xc09a1964", ioctl_count=count,
                  dispatch_table_va=hex(table_va), dispatch_table_hex=read(pe, table_va, count * 2).hex(),
                  dispatch=[dict(code=index, code_hex=hex(index), handler_va=hex(table_va + offset)) for index, offset in enumerate(offsets)],
                  reset_selectors=selectors, selected_calls=calls,
                  gpio_output_contract={"code": 1, "stack_frame_size": 40, "pointer_loads": gpio_output_loads,
                                        "standard_stream_argument_name": "pdwActualOut",
                                        "stored_values": [0, 255],
                                        "note": "Pin status goes into seventh argument, not fifth pBufOut; no NULL guard"},
                  memory_allocation_codes={"0x15": "Outside examined dispatch range; callers initialize output to zero and fall back",
                                           "0x16": "Outside examined dispatch range"})
    pe.close()
    (ROOT / "analysis/firmware/mgr-driver-contracts.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
