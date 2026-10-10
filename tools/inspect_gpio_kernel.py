"""Extract NK GPIO/OAL evidence using original realaddr mappings in validated CER1 records."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]


def main():
    path = ROOT / "extracted/705md-rom/fs/Windows/nk.exe"
    pe = pefile.PE(str(path))
    cer = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".cerom").get_data()
    magic, version, header_size, count, entry_size, _ = struct.unpack_from("<6I", cer)
    if (magic, version, header_size, entry_size) != (0x31524543, 1, 24, 44):
        raise ValueError("Unexpected CER1 format")
    sections = [struct.unpack_from("<11I", cer, header_size + i * entry_size) for i in range(count)]

    def read_real(va, size):
        for virtual_size, rva, stored_size, source, real, flags, shadow, offset, shadow_size, _, _ in sections:
            # Initialized bytes only; never invent zero-filled RAM values.
            if real <= va and va + size <= real + stored_size:
                delta = va - real
                data = cer[offset + delta:offset + delta + size] if shadow else pe.get_data(rva + delta, size)
                if len(data) != size:
                    raise ValueError("Truncated initialized section")
                return data
        raise ValueError(f"No initialized source bytes for {va:#x}")

    def words(va, count):
        return struct.unpack(f"<{count}I", read_real(va, count * 4))

    def label(va):
        value = bytearray()
        for i in range(0, 512, 2):
            byte = read_real(va + i, 2)
            if byte == b"\0\0":
                return value.decode("utf-16le")
            value.extend(byte)
        raise ValueError("Unterminated platform label")

    dispatch_va = 0x80101174
    dispatch = words(dispatch_va, 3)
    if dispatch != (0x01032c87, 0, 0x80107424):
        raise ValueError("GPIO IOCTL dispatch changed")
    if words(0x80107424, 2) != (0x10a0004d, 0x240e0001):
        raise ValueError("GPIO handler entry changed")
    oal_dispatch = []
    for index in range(128):
        va = 0x80101150 + index * 12
        code, flags, handler = words(va, 3)
        if handler == 0:
            if (code, flags) != (0, 0):
                raise ValueError("Unexpected OAL sentinel")
            break
        read_real(handler, 4)
        oal_dispatch.append(dict(index=index, real_va=hex(va), code=hex(code), flags=flags,
                                  handler_real_va=hex(handler), raw_hex=read_real(va, 12).hex()))
    else:
        raise ValueError("OAL dispatch sentinel absent")
    bank_base = words(0x8112b238, 1)[0]
    entries = []
    for index in range(128):
        va = 0x8112b23c + index * 16
        pin, name, irq_enabled, config = words(va, 4)
        if pin == 0xffffffff:
            sentinel = dict(real_va=hex(va), raw_hex=read_real(va, 16).hex())
            break
        if pin >= 128:
            raise ValueError("Unexpected platform GPIO pin")
        entries.append(dict(index=index, real_va=hex(va), pin=pin, pin_hex=hex(pin), label=label(name),
                            irq_enabled=irq_enabled, config=config, config_hex=hex(config),
                            raw_hex=read_real(va, 16).hex(), configuration_register=hex(bank_base + 0x1000 + pin * 4)))
    else:
        raise ValueError("Platform GPIO sentinel absent")
    result = dict(scope="Static NK OAL GPIO contract, realaddr-aware initialized data; physical wiring remains unverified",
                  source_sha256=hashlib.sha256(path.read_bytes()).hexdigest(),
                  ioctl=hex(dispatch[0]), dispatch_real_va=hex(dispatch_va), dispatch_raw_hex=read_real(dispatch_va, 12).hex(),
                  oal_dispatch=oal_dispatch,
                  custom_handler_bytes=[dict(start_real_va=hex(start), size=size, raw_hex=read_real(start, size).hex())
                                        for start, size in [(0x80105e00, 0xd8), (0x80105ed8, 0x124),
                                                            (0x80105ffc, 0x38), (0x80106034, 0x38),
                                                            (0x8010606c, 0x70), (0x801060dc, 0x190),
                                                            (0x8010626c, 0x124), (0x80106390, 0x60)]],
                  handler_real_va=hex(dispatch[2]), handler_size=0x13c, handler_raw_hex=read_real(dispatch[2], 0x13c).hex(),
                  bank_base_pointer_real_va="0x8112b238", bank_base_pointer_raw_hex=read_real(0x8112b238, 4).hex(),
                  uncached_register_base=hex(bank_base), kseg1_physical_candidate=hex(bank_base & 0x1fffffff),
                  record_size=16, used_input_fields=[0, 4, 8], unused_input_field=12,
                  pin_bank="pin >> 5", pin_mask="1 << (pin & 31)",
                  platform_entries=entries, sentinel=sentinel,
                  caveats=["Input NULL or input length <16 returns TRUE without processing",
                           "Subcode 8 and all unrecognized subcodes share the configuration-read fallback",
                           "Output pointers, output length, bytes-returned pointer and pin range lack checks in this handler",
                           "ROM table labels are manufacturer labels, not a measurement of active signals"])
    target = ROOT / "analysis/firmware/gpio-kernel-contracts.json"
    target.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps({"platform_entries": len(entries), "oal_entries": len(oal_dispatch), "base": hex(bank_base)}, indent=2))


if __name__ == "__main__":
    main()
