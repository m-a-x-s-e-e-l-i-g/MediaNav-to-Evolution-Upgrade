"""Execute the issue #74 candidate instructions using the original MAX33 files."""

import argparse
from pathlib import Path
import struct

import pefile
from unicorn import Uc, UC_ARCH_MIPS, UC_HOOK_CODE, UC_MODE_LITTLE_ENDIAN, UC_MODE_MIPS32
from unicorn.mips_const import (
    UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_PC,
    UC_MIPS_REG_RA, UC_MIPS_REG_S0, UC_MIPS_REG_T3, UC_MIPS_REG_V0,
)

from patch_issue74 import PATCHES, patch


def machine(raw, start, size):
    image = pefile.PE(data=raw)
    vm = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
    page = start & ~0xFFF
    vm.mem_map(page, 0x1000)
    vm.mem_write(start, image.get_data(start - image.OPTIONAL_HEADER.ImageBase, size))
    return vm


def route(raw, start, size, register, value, destinations):
    vm = machine(raw, start, size)
    if register == UC_MIPS_REG_S0:
        vm.mem_map(0x10000000, 0x1000)
        vm.mem_write(0x10000000, bytes((0, 2, value, 2)))
        value = 0x10000000
    vm.reg_write(register, value)

    def stop_at_destination(emulator, address, _size, _data):
        if address in destinations:
            emulator.emu_stop()

    vm.hook_add(UC_HOOK_CODE, stop_at_destination)
    vm.emu_start(start, 0, count=24)
    return vm.reg_read(UC_MIPS_REG_PC)


def verify_eco(original, candidate):
    destinations = dict(zip("dfgi", (0x1CDBC, 0x1CD80, 0x1CD50, 0x1CC98)))
    old = dict(zip("eghj", destinations.values()))
    ignored = 0x1CE18
    for message in "abcdefghijz":
        for binary, expected in ((original, old), (candidate, destinations)):
            assert route(binary, 0x1CC60, 0x1C0, UC_MIPS_REG_S0, ord(message),
                         {*destinations.values(), ignored}) == expected.get(message, ignored)

    native_dsi = dict(zip("abcd", (0x22CB4, 0x22930, 0x228D8, 0x22858)))
    ignored = 0x22CD0
    for message in "abcdfgi":
        for binary in (original, candidate):
            expected = native_dsi.get(message, ignored)
            if binary is candidate and message == "d":
                expected = ignored
            assert route(binary, 0x22828, 0x4B0, UC_MIPS_REG_T3, ord(message),
                         {*native_dsi.values(), ignored}) == expected


def verify_cover(original, candidate):
    record = bytearray(82)
    record[:11] = bytes.fromhex("09 00 01 35 06 19 11 0e 19 11 0f")
    record[0x37:0x4A] = bytes.fromhex(
        "09 00 09 35 08 35 06 19 11 0e 09 01 04 09 03 11 09 00 41"
    )
    for raw, feature in ((original, 0x0241), (candidate, 0x03C1)):
        for size, role, invalid_header, expected in (
            (82, 2, False, 1), (81, 2, False, 0), (82, 1, False, 0), (82, 2, True, 0)
        ):
            vm = machine(raw, 0x323200, 0x234)
            address = 0x10000000
            vm.mem_map(address, 0x1000)
            before = bytes(record) if not invalid_header else b"\x00" + bytes(record[1:])
            vm.mem_write(address, before)
            vm.reg_write(UC_MIPS_REG_A0, address)
            vm.reg_write(UC_MIPS_REG_A1, size)
            vm.reg_write(UC_MIPS_REG_A2, role)
            vm.reg_write(UC_MIPS_REG_RA, 0x323500)
            vm.emu_start(0x323200, 0x323500, count=256)
            assert vm.reg_read(UC_MIPS_REG_PC) == 0x323500
            assert vm.reg_read(UC_MIPS_REG_V0) == expected
            after = bytearray(before)
            if expected:
                after[0x43] = 6
                struct.pack_into(">H", after, 0x48, feature)
            assert vm.mem_read(address, len(after)) == after


def verify(input_folder):
    for mode, check in (("eco", verify_eco), ("android-cover", verify_cover)):
        name, _, edits = PATCHES[mode]
        original = (input_folder / name).read_bytes()
        candidate = patch(original, mode)
        image = pefile.PE(data=candidate)
        assert image.verify_checksum() and len(candidate) == len(original)
        allowed = {image.OPTIONAL_HEADER.get_field_absolute_offset("CheckSum")}
        allowed.update(image.get_offset_from_rva(va - image.OPTIONAL_HEADER.ImageBase)
                       for va, _, _ in edits)
        assert all((offset & ~3) in allowed for offset, (old, new) in
                   enumerate(zip(original, candidate)) if old != new)
        try:
            patch(candidate, mode)
        except ValueError:
            pass
        else:
            raise AssertionError("Already patched input accepted")
        check(original, candidate)
        print(f"{mode}: native instruction, checksum and input guard checks passed")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("system_folder", type=Path)
    verify(parser.parse_args().system_folder)
