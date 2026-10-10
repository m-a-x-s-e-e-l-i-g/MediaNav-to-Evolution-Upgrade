"""Static bootnotification/state-dispatch witnesses; no firmware execution."""
from pathlib import Path
import hashlib
import json
import struct
from functools import reduce
from operator import xor
import pefile
from inspect_micom_flow import ROOT, decoder, operand, record
from inspect_micom_flash_marker import IMAGE_HASH, binding, guard
from micom_protocol import parse_capture

RANGES = ((0x15c96, 0x15cad), (0x15e92, 0x15fc2),
          (0x165bc, 0x16606), (0x166f3, 0x1670f),
          (0x172b7, 0x172e1), (0x17316, 0x174cf), (0x154b7, 0x15550))
CE_HASH = "c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824"


def ce_bytes():
    path = ROOT / "extracted/705md/upgrade/Storage Card/System/MicomManager.exe"
    raw = path.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == CE_HASH
    pe = pefile.PE(data=raw)
    result = []
    for start, end, role in (
        (0x1f444, 0x1f4f4, "Bootstatus WORD load and stop timer before further reads"),
        (0x21d50, 0x21d70, "Type2 command0 accepted only when powerstate field24 is zero"),
        (0x21748, 0x21790, "OnCommand type gate"),
        (0x241ec, 0x2421c, "Periodic manager1 command0"),
    ):
        data = pe.get_data(start - pe.OPTIONAL_HEADER.ImageBase, end - start)
        assert len(data) == end - start
        result.append(dict(start=hex(start), end=hex(end), role=role,
                           bytes=data.hex(), sha256=hashlib.sha256(data).hexdigest()))
    for address, expected in (
        (0x1f4a8, "04000896"), (0x1f4ac, "84003226"),
        (0x1f4b0, "000048a6"), (0x1f4c0, "1bc0000c"),
        (0x1f4c4, "380020ae"), (0x21d50, "2400288e"),
        (0x21d60, "117d000c"),
    ):
        assert pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, 4).hex() == expected, hex(address)
    return dict(path=str(path.relative_to(ROOT)), sha256=CE_HASH, ranges=result)


def boot_frame(word):
    assert 0 <= word <= 0xffff
    body = b"\xaa\x12\x00\x02" + struct.pack("<H", word)
    return body + bytes([reduce(xor, body, 0)])


def main():
    image = (ROOT / "analysis/firmware/micom-image.bin").read_bytes()
    assert hashlib.sha256(image).hexdigest() == IMAGE_HASH
    out = ROOT / "analysis/firmware/boot-notifications"
    out.mkdir(exist_ok=True)
    insns = {}
    for start, end in RANGES:
        ea = start
        while ea < end:
            i = decoder.decode_one(image, ea)
            assert i and i.size > 0 and i.mnem != ".db"
            insns[ea] = i
            ea += i.size
        assert ea == end, (hex(start), hex(end), hex(ea))
    initial = binding(image, 0xfe402, 0x18)
    assert initial["target"] == "0x172b7"
    # Exact byte encodings scanned across the available flat image, then tied
    # to the decoded witnesses. This does not discover stores through aliases.
    pointer_stores = [ea for ea in range(len(image)) if image.startswith(bytes.fromhex("bf16e7"), ea)]
    segment_stores = [ea for ea in range(len(image)) if image.startswith(bytes.fromhex("cf18e701"), ea)]
    assert pointer_stores == [0x15ea6, 0x15f29, 0x165c3, 0x16702]
    assert segment_stores == [0x15ea9, 0x15f2c, 0x165c6, 0x16705]
    witnesses = [guard(insns, *args) for args in (
        (0x15ea3, "movw", ["AX", "#0x72b7"]),
        (0x15ea6, "movw", ["0xfe716", "AX"]),
        (0x15ea9, "mov", ["0xfe718", "#0x1"]),
        (0x15f26, "movw", ["AX", "#0x72b7"]),
        (0x15f29, "movw", ["0xfe716", "AX"]),
        (0x166ff, "movw", ["AX", "#0x72b7"]),
        (0x16702, "movw", ["0xfe716", "AX"]),
        (0x165c0, "movw", ["AX", "#0x7316"]),
        (0x165c3, "movw", ["0xfe716", "AX"]),
        (0x165c6, "mov", ["0xfe718", "#0x1"]),
        (0x165cd, "movw", ["DE", "#0xe6f4"]),
        (0x165da, "call", ["DE"]),
        (0x1731f, "cmp", ["0xfe1ea", "#0x3"]),
        (0x17323, "bz", ["0x17329"]),
        (0x17325, "clrw", ["BC"]),
        (0x173bf, "mov", ["[HL+0x1]", "#0x2"]),
        (0x173c2, "br", ["0x174ae"]),
        (0x174b8, "movw", ["AX", "[HL+0xa]"]),
        (0x174bf, "push", ["AX"]),
        (0x174c0, "onew", ["AX"]),
        (0x174c1, "incw", ["AX"]),
        (0x174c2, "push", ["AX"]),
        (0x174c3, "onew", ["AX"]),
        (0x174c4, "call", ["0x154b7"]),
    )]
    # Exhaustive packed-WORD/XOR arithmetic; this is not an MCU simulation.
    for value in range(65536):
        raw = boot_frame(value)
        assert len(raw) == 7 and int.from_bytes(raw[4:6], "little") == value
        assert reduce(xor, raw, 0) == 0
    frames = []
    for value in (0, 1, 3, 0x17, 0x100, 0xff00, 0xffff):
        raw = boot_frame(value)
        parsed = parse_capture(raw)
        assert len(parsed) == 1 and parsed[0]["checksum_valid"]
        assert (parsed[0]["manager_nibble"], parsed[0]["type_nibble"], parsed[0]["command"],
                parsed[0]["payload_bytes"]) == (1, 2, 0, 2)
        frames.append(dict(word=hex(value), hex=raw.hex(), device_observation=False))
    result = dict(scope="Static bootnotification and mutable dispatch; no device execution",
        image_sha256=IMAGE_HASH, producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        initial_control_binding=initial, rebind_slot="0xfe716", rebind_segment_slot="0xfe718",
        direct_store_encoding_audit=dict(pointer_stores=[hex(ea) for ea in pointer_stores],
                                        segment_stores=[hex(ea) for ea in segment_stores],
                                        indirect_or_other_encodings_exhausted=False),
        control_targets=["0x172b7", "0x17316"],
        rebinds=[dict(code="0x15ea3", role="init", target="0x172b7"),
                 dict(code="0x15f26", role="non-init branch", target="0x172b7"),
                 dict(code="0x166ff", role="manager1 commandFE", target="0x172b7"),
                 dict(code="0x165c0", role="manager1 command0 later path", target="0x17316")],
        notification=dict(manager=1, type=2, command=0, length=2,
                          source_ram="0xfe6f4", word_little_endian=True,
                          requires_mcu_state="0xfe1ea == 3", flash_status_field=False),
        ce=dict(handler="0x21748", accepted_only_if_field24_zero=True,
                boot_init="0x1f444", stores_payload_word_at="this+0x84",
                clears_timer_state="this+0x38", timer_stop="0x3006c",
                flash_readback_before_timer_stop=False),
        exhaustive_word_cases=65536, frame_fixtures=frames, witnesses=witnesses,
        ce_evidence=ce_bytes(), ranges=[dict(start=hex(a), end=hex(b), bytes=image[a:b].hex()) for a,b in RANGES],
        limitations=["Readback/capture of unit state unavailable", "State names remain candidate interpretations",
                     "Other indirect writes or aliases may exist outside followed paths",
                     "Decoder lengths do not prove complete semantics or exact chip",
                     "No claim that the whole CE boot-init body is understood"])
    (out / "contracts.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    (out / "micom-image.bin").write_bytes(image)
    (out / "rl78-instructions.json").write_text(json.dumps([record(i) for _,i in sorted(insns.items())], indent=2), encoding="utf-8")
    (out / "micom-cpu-candidates.json").write_text(json.dumps(dict(roots=["0x15e92", "0x172b7", "0x17316"]), indent=2), encoding="utf-8")
    (out / "boot-paths.asm").write_text("\n".join(
        f"{ea:05x} {i.raw.hex():12} {i.mnem:8} "+", ".join(operand(o) for o in i.ops)
        for ea,i in sorted(insns.items()))+"\n", encoding="utf-8")
    print(json.dumps(dict(instructions=len(insns), word_cases=65536, rebinds=4,
                         frame_fixtures=len(frames), native_execution=False), indent=2))


if __name__ == "__main__": main()
