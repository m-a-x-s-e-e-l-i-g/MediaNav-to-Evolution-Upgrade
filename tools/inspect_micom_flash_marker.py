"""Offline evidence for the 3f400 MCU marker; never executes MCU code.

Initial-RAM pointers are initializer candidates, not live device bindings.
The selector table is extracted from a bounded subtract/skip/branch sequence.
"""
from pathlib import Path
import hashlib
import json
import struct
import pefile
from functools import reduce
from operator import xor
from micom_protocol import parse_capture
from inspect_micom_flow import ROOT, decoder, operand, record
from inspect_micom_startup import rom_at

IMAGE_HASH = "4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512"
RANGES = ((0x191f, 0x1993), (0x1993, 0x19bd), (0x18bd0, 0x18c19),
          (0x190c9, 0x19188), (0x19474, 0x194a7), (0x19664, 0x196a9),
          (0x1e867, 0x1e98a), (0x1ed78, 0x1edd0),
          (0x1611c, 0x1619d), (0x163c6, 0x163ef),
          (0x164c7, 0x16606), (0x168f9, 0x1690e),
          (0x19269, 0x19474), (0x1e7ca, 0x1e867),
          (0x154a0, 0x15550), (0x1567a, 0x15743), (0x16976, 0x1697d))


def binding(image, global_address, field):
    global_rom = rom_at(global_address, 2)
    pointer = struct.unpack_from("<H", image, global_rom)[0]
    slot_ram = 0xf0000 + pointer + field
    slot_rom = rom_at(slot_ram, 4)
    raw = image[slot_rom:slot_rom + 4]
    assert len(raw) == 4 and raw[3] == 0 and raw[2] < 0x10
    return dict(global_ram=hex(global_address), global_rom=hex(global_rom),
                initial_pointer=hex(pointer), field=hex(field), slot_ram=hex(slot_ram),
                slot_rom=hex(slot_rom), bytes=raw.hex(), target=hex(int.from_bytes(raw[:3], "little")),
                live_binding_verified=False)


def guard(insns, address, mnemonic, operands):
    ins = insns[address]
    assert (ins.mnem, [operand(o) for o in ins.ops]) == (mnemonic, operands), hex(address)
    return record(ins)


def selectors(insns):
    """Reconstruct case labels by cumulative subtraction; no branch execution."""
    guard(insns, 0x1e887, "cmpw", ["AX", "#0x0"])
    guard(insns, 0x1e88a, "skz", [])
    guard(insns, 0x1e88c, "br", ["0x1e987"])
    guard(insns, 0x1e883, "movw", ["DE", "#0x1"])
    guard(insns, 0x1e88f, "movw", ["AX", "BC"])
    labels, total, ea = {}, 0, 0x1e890
    while ea < 0x1e984:
        sub = insns[ea]
        assert sub.mnem == "subw" and operand(sub.ops[0]) == "AX"
        if sub.ops[1].mode == "imm": amount = sub.ops[1].value
        else:
            assert operand(sub.ops[1]) == "DE"
            amount = 1
        total += amount
        skip = insns[ea + sub.size]
        assert skip.mnem == "sknz"
        branch = insns[skip.ea + skip.size]
        assert branch.mnem == "br"
        assert total not in labels and total <= 0xffff
        labels[total] = branch.ops[0].addr
        ea = branch.ea + branch.size
    assert ea == 0x1e984
    assert labels[0xfe] == 0x1ed78 and labels[0xff] == 0x1ed9b
    return {hex(key): hex(value) for key, value in sorted(labels.items())}


def manager1_commands(insns):
    """Cumulative 8-bit case labels, including FC..FF and wrap to zero."""
    labels, total, ea = {}, 0, 0x16125
    while ea < 0x1619a:
        op = insns[ea]
        if op.mnem == "sub":
            assert operand(op.ops[0]) == "A" and op.ops[1].mode == "imm"
            total = (total + op.ops[1].value) & 255
        else:
            assert (op.mnem, [operand(o) for o in op.ops]) == ("dec", ["A"])
            total = (total + 1) & 255
        following = insns[ea + op.size]
        if following.mnem == "sknz":
            branch = insns[following.ea + following.size]
            assert branch.mnem == "br"
        else:
            assert following.mnem == "bz"
            branch = following
        labels[total] = branch.ops[0].addr
        ea = branch.ea + branch.size
    assert ea == 0x1619a
    assert labels[0] == 0x164c7 and labels[7] == 0x163c6 and labels[0xfd] == 0x168f9
    return {hex(k): hex(v) for k, v in sorted(labels.items())}


def property_cases(insns, start, end):
    labels, total, ea = {}, 0, start
    while ea < end:
        sub = insns[ea]
        assert sub.mnem == "subw" and operand(sub.ops[0]) == "AX"
        if sub.ops[1].mode == "imm": amount = sub.ops[1].value
        else:
            assert operand(sub.ops[1]) == "DE"
            amount = 1
        total += amount
        following = insns[sub.ea + sub.size]
        if following.mnem == "sknz":
            branch = insns[following.ea + following.size]
            assert branch.mnem == "br"
        else:
            assert following.mnem == "bz"
            branch = following
        assert total not in labels and total <= 0xffff
        labels[total] = branch.ops[0].addr
        ea = branch.ea + branch.size
    assert ea == end
    return {hex(k): hex(v) for k, v in sorted(labels.items())}


def ce_evidence():
    path = ROOT / "extracted/705md/upgrade/Storage Card/System/MicomManager.exe"
    raw = path.read_bytes()
    digest = hashlib.sha256(raw).hexdigest()
    assert digest == "c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824"
    pe = pefile.PE(data=raw)
    rows = []
    for start, end, role in (
        (0x14db0, 0x14f8c, "SendWriteCmd: A6 wait means success"),
        (0x15158, 0x152c8, "SendCommandEx: event wait means success"),
        (0x25cac, 0x25e1c, "A6 receive signals shared event"),
        (0x241ec, 0x2421c, "Timer state5 sends manager1 type1 command0"),
        (0x242b8, 0x242d8, "Timer state6 transitions to state5 interval1000"),
        (0x24100, 0x2410c, "Save timer state and schedule interval"),
    ):
        data = pe.get_data(start - pe.OPTIONAL_HEADER.ImageBase, end - start)
        assert len(data) == end - start
        rows.append(dict(start_va=hex(start), end_va=hex(end), role=role,
                         bytes=data.hex(), sha256=hashlib.sha256(data).hexdigest()))
    # Actual MIPS instructions at the command0 send, including its delay slot.
    for address, expected in ((0x241f8, "00000724"), (0x241fc, "01000624"),
                              (0x24200, "01000524"), (0x2420c, "5654000c"),
                              (0x242b8, "05000824"), (0x242c0, "e8030524")):
        assert pe.get_data(address-pe.OPTIONAL_HEADER.ImageBase, 4).hex() == expected, hex(address)
    return dict(path=str(path.relative_to(ROOT)), sha256=digest, ranges=rows,
                native_execution=False)


def frame_fixtures():
    rows = []
    for role, manager, kind, command, data in (
        ("CE timer command0", 1, 1, 0, b""),
        ("MCU commandFD alternative", 1, 1, 253, b""),
        ("CE command7 payloadLSB1", 1, 1, 7, b"\x01"),
        ("Normal manager0 command6", 0, 2, 6, b""),
        ("Read manager0 parameter42 length1", 0, 5, 1, b"\x42\x00\x00\x00"),
        ("Derived read42 zero-length reply", 0, 13, 1, b""),
    ):
        body = bytes([0xaa, (manager << 4) | kind, command, len(data)]) + data
        raw = body + bytes([reduce(xor, body, 0)])
        parsed = parse_capture(raw)
        assert len(parsed) == 1 and parsed[0]["checksum_valid"]
        assert parsed[0]["manager_nibble"] == manager and parsed[0]["command"] == command
        rows.append(dict(role=role, bytes=raw.hex(), sent_to_device=False))
    return rows


def main():
    image = (ROOT / "analysis/firmware/micom-image.bin").read_bytes()
    assert hashlib.sha256(image).hexdigest() == IMAGE_HASH
    out = ROOT / "analysis/firmware/flash-marker"
    out.mkdir(exist_ok=True)
    insns = {}
    for start, end in RANGES:
        ea = start
        while ea < end:
            ins = decoder.decode_one(image, ea)
            assert ins is not None and ins.mnem != ".db" and ins.size > 0
            insns[ea] = ins
            ea += ins.size
        assert ea == end, (hex(start), hex(end), hex(ea))
    write = binding(image, 0xfe41e, 0x10)
    assert write["bytes"] == "67e80100" and write["target"] == "0x1e867"
    labels = selectors(insns)
    command_labels = manager1_commands(insns)
    guard(insns, 0x19275, "movw", ["DE", "#0x1"])
    guard(insns, 0x1939a, "movw", ["DE", "#0x1"])
    property_set = property_cases(insns, 0x1927f, 0x192b0)
    property_get = property_cases(insns, 0x193a4, 0x193cb)
    assert property_set["0x42"] == "0x1934b" and property_get["0x42"] == "0x19406"
    witnesses = [guard(insns, *args) for args in (
        (0x19671, "cmp0", ["ES:0xf400"]),
        (0x19677, "mov", ["[HL+0x1]", "#0x0"]),
        (0x1967a, "clr1", ["0xfe830.7"]),
        (0x19681, "onew", ["BC"]),
        (0x19696, "movw", ["AX", "#0xfe"]),
        (0x19699, "clrw", ["BC"]),
        (0x196a0, "call", ["DE"]),
        (0x196a2, "addw", ["SP", "#0x4"]),
        (0x196a4, "onew", ["BC"]),
        (0x1ed88, "movw", ["AX", "#0xfd"]),
        (0x1ed8b, "call", ["0x191f"]),
        (0x193a, "call", ["0x14f5"]),
        (0x19b5, "call", ["0x135b"]),
        (0x19b9, "call", ["0x1873"]),
        (0x19154, "cmp", ["ES:0xf400", "#0xff"]),
        (0x19159, "sknz", []),
        (0x1915b, "set1", ["0xfe830.7"]),
        (0x164ce, "bf", ["A.0", "0x164e7"]),
        (0x164fb, "movw", ["AX", "#0x6"]),
        (0x164fe, "call", ["DE"]),
        (0x16500, "pop", ["AX"]),
        (0x16906, "movw", ["AX", "#0x6"]),
        (0x16909, "call", ["DE"]),
        (0x16976, "onew", ["BC"]),
        (0x165bc, "set1", ["0xfe1eb.0"]),
        (0x163de, "movw", ["AX", "#0x42"]),
        (0x1935b, "mov", ["[HL+0x1]", "#0xfd"]),
        (0x1936d, "onew", ["AX"]),
        (0x1936e, "incw", ["AX"]),
        (0x1936f, "call", ["DE"]),
        (0x19371, "pop", ["AX"]),
        (0x1e854, "call", ["0x135b"]),
        (0x1e7d1, "mov", ["[HL+0xb]", "#0x1"]),
        (0x1e858, "br", ["0x1e85e"]),
        (0x1e85e, "mov", ["A", "[HL+0xb]"]),
        (0x154a5, "mov", ["[HL+0x1]", "#0xa6"]),
        (0x156bf, "call", ["DE"]),
        (0x156c2, "call", ["0x154a0"]),
        (0x1573b, "call", ["DE"]),
        (0x1573f, "call", ["0x154a0"]),
        (0x15699, "sub", ["A", "#0x2"]),
        (0x1569b, "sknc", []),
        (0x1569d, "call", ["0x154a0"]),
        (0x19392, "mov", ["[HL+0x3]", "#0x0"]),
        (0x1940e, "mov", ["C", "A"]),
        (0x19412, "mov", ["[DE]", "A"]),
        (0x19413, "br", ["0x1946b"]),
        (0x1946b, "mov", ["A", "[HL+0x3]"]),
        (0x156f5, "mov", ["A", "C"]),
        (0x156fa, "push", ["AX"]),
        (0x15706, "call", ["0x154b7"]),
    )]
    # Every possible marker byte, including noncanonical programmed values.
    states = [dict(byte=value, ulc_requests_erase=value != 255,
                   command6_requests_write=value != 0,
                   startup_bit7=value == 255,
                   timer_uses_counter=value == 255) for value in range(256)]
    assert states[0] == dict(byte=0, ulc_requests_erase=True,
                            command6_requests_write=False, startup_bit7=False,
                            timer_uses_counter=False)
    assert states[255]["command6_requests_write"] and not states[255]["ulc_requests_erase"]
    result = dict(scope="Static marker paths; no device/flash/native execution",
        image_sha256=IMAGE_HASH,
        producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        marker_address="0x3f400", block=253, block_bytes=1024,
        snapshot_block_all_ff=all(b == 255 for b in image[0x3f400:0x3f800]),
        initial_write_binding=write, initial_timer_action_binding=binding(image, 0xfe400, 0xc),
        parameter_dispatch=labels, parameter_highword_required=0,
        property_set_dispatch=property_set, property_get_dispatch=property_get,
        manager1_command_dispatch=command_labels,
        initial_control_binding=binding(image, 0xfe400, 0x18),
        initial_property_write_binding=binding(image, 0xfe400, 0x10),
        initial_parameter_control_binding=binding(image, 0xfe41e, 0xc),
        boot_command=dict(manager=1, type=1, command=0,
                          marker_write_when_ram_bit0_clear="0xfe1eb.0",
                          marker_write_before_bit0_set=True),
        later_control_field_rebinding=dict(slot_ram="0xfe716", field="0x18",
                                          code="0x165c0", new_target="0x17316",
                                          initializer_binding_is_immutable=False),
        marker_write_command=dict(manager=1, type=1, command=253),
        marker_flag_command=dict(manager=1, type=1, command=7,
                                 parameter="0x42", sets_ram_bit_from_payload_lsb=True,
                                 requests_erase_if_bit_set=True,
                                 parameter_control_discards_erase_result=True),
        normal_type2_and_type6_ack=dict(value="a6", conditional_on_handler_result=False,
                                      handler_may_never_return=True,
                                      delivery_or_device_effect_verified=False),
        normal_type1_ack=dict(value="a6", handler_return_bytes=[0, 1],
                             successful_flash_verified=False),
        ce_evidence=ce_evidence(),
        offline_frames=frame_fixtures(),
        marker_getter=dict(manager=0, parameter="0x42", target="0x1938a",
                           writes_payload_bit7=True, returns_length=0,
                           wire_reply_payload_length=0,
                           ce_wakes_then_returns_zero_length=True,
                           active_device_binding_verified=False),
        normal_command=6, write_parameter="0xfe", payload="00", payload_length=1,
        write_request_tag="0xfd", write_request_flags=0,
        derived_library_address=hex(253 << 10), derived_padded_chunk="00ffffff",
        caller_discards_write_result=True, caller_returns_bc=1,
        caller_clears_bit_before_write="0xfe830.7",
        ulc_entry_discards_erase_result=True,
        timer_interval_argument=30000, timer_waits_until_counter=6,
        timer_ticks_duration_verified=False,
        witnesses=witnesses, ranges=[dict(start=hex(a), end=hex(b), bytes=image[a:b].hex()) for a,b in RANGES],
        marker_byte_projection=states,
        limitations=["Initializer target may change at runtime",
                     "Selector names and physical meaning of marker remain unknown",
                     "Flash helper/hidden ROM may reject or interrupt operations",
                     "Firmware image is not a readback of the installed marker",
                     "The MCU marker is not the CE staging marker or navigation error",
                     "Decoder lengths do not prove exact chip or all instruction semantics"])
    (out / "contracts.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    (out / "micom-image.bin").write_bytes(image)
    (out / "rl78-instructions.json").write_text(json.dumps([record(i) for _, i in sorted(insns.items())], indent=2), encoding="utf-8")
    (out / "micom-cpu-candidates.json").write_text(json.dumps(dict(roots=[hex(a) for a,b in RANGES]), indent=2), encoding="utf-8")
    (out / "marker-paths.asm").write_text("\n".join(
        f"{ea:05x} {i.raw.hex():12} {i.mnem:8} "+", ".join(operand(o) for o in i.ops)
        for ea,i in sorted(insns.items()))+"\n", encoding="utf-8")
    print(json.dumps(dict(instructions=len(insns), selector_cases=len(labels),
                         marker_byte_cases=len(states), parameter_fe_target=labels["0xfe"],
                         marker=result["marker_address"], native_execution=False), indent=2))


if __name__ == "__main__": main()
