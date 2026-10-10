"""Read-only flash-library witnesses and bounded arithmetic projections.

No native execution, serial access or flash access. Hidden chip ROM and installed
boot mapping remain unknown. The caller's buffer/capacity offsets are checked
separately; hidden-ROM compliance with that buffer contract is not simulated.
"""
from pathlib import Path
import hashlib
import json
from inspect_micom_flow import ROOT, decoder, record, operand

IMAGE_HASH = "4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512"
FX3_URL = "https://www.renesas.com/en/document/mah/78k0rfx3-users-manual-hardware"
TYPE03_URL = "https://www.renesas.com/ja/document/apn/78k0r-microcontrollers-flash-programming-library-type03-application-note"


def block_address(tag):
    assert 0 <= tag <= 255
    return tag << 10


def write_arguments(address, words, rom_upper_bound):
    """Projection of 351's local checks, not ROM return codes."""
    if not 1 <= words <= 64 or address & 3:
        return False
    return address + words * 4 - 1 <= rom_upper_bound


def chunks(tag, payload, capacity):
    """Bounded one-block projection with an explicitly supplied buffer size."""
    assert 0 < len(payload) <= 1024 and 4 <= capacity <= 256 and capacity % 4 == 0
    out = []
    for offset in range(0, len(payload), capacity):
        part = payload[offset:offset + capacity]
        data = part + b"\xff" * ((-len(part)) % 4)
        address = block_address(tag) + offset
        assert write_arguments(address, len(data) // 4, 0x3ffff)
        out.append(dict(address=hex(address), consumed=len(part), words=len(data)//4,
                        padding=len(data)-len(part), sha256=hashlib.sha256(data).hexdigest()))
    return out


def buffer_layout(image):
    """Bounded straight-line symbolic witness for 1519..1523 and 161d..1620.

    Only register/address arithmetic in these known sequences is projected.
    No call, native code, memory bus or chip-ROM is executed.
    """
    init_addresses = (0x1519, 0x151a, 0x151b, 0x151c, 0x151e, 0x151f, 0x1520, 0x1523)
    read_addresses = (0x161d, 0x161e, 0x1620)
    init = [decoder.decode_one(image, ea) for ea in init_addresses]
    read = [decoder.decode_one(image, ea) for ea in read_addresses]
    assert [(i.mnem, [operand(o) for o in i.ops]) for i in init] == [
        ("clrb", ["X"]), ("oneb", ["A"]), ("inc", ["H"]),
        ("movw", ["[HL+0x14]", "AX"]), ("dec", ["H"]),
        ("movw", ["AX", "HL"]), ("addw", ["AX", "#0x14"]), ("call", ["0x131e"])]
    assert [(i.mnem, [operand(o) for o in i.ops]) for i in read] == [
        ("inc", ["H"]), ("movw", ["AX", "[HL+0x14]"]), ("dec", ["H"])]
    gh = json.loads((ROOT / "analysis/firmware/flow-update/ghidra-rl78-instructions.json").read_text(encoding="utf-8"))
    indexed = {int(i["address"], 16): i for i in gh}
    for ins in init+read:
        assert indexed[ins.ea]["bytes"] == ins.raw.hex(), hex(ins.ea)
    witnesses = []
    for frame_base in (0xbfba, 0xc000, 0xd0ef, 0xe080, 0xfe00, 0xfeef, 0xff00):
        hl, x, a = frame_base, None, None
        mem = {}
        for ins in init:
            if ins.mnem == "clrb": x = 0
            elif ins.mnem == "oneb": a = 1
            elif ins.mnem == "inc": hl = (((hl >> 8)+1)&255)*256+(hl&255)
            elif ins.mnem == "dec": hl = (((hl >> 8)-1)&255)*256+(hl&255)
            elif ins.mnem == "movw" and ins.ops[0].mode == "ind":
                capacity_address = (hl + ins.ops[0].disp) & 0xffff
                mem[capacity_address] = x | (a << 8)
            elif ins.mnem == "movw": x, a = hl & 255, hl >> 8
            elif ins.mnem == "addw":
                ax = ((x | (a << 8)) + ins.ops[1].value) & 0xffff
                x, a = ax & 255, ax >> 8
            elif ins.mnem == "call": buffer_address = x | (a << 8)
            else: raise AssertionError(ins.mnem)
        assert hl == frame_base and mem[capacity_address] == 256
        assert (capacity_address - frame_base) & 0xffff == 0x114
        assert (buffer_address - frame_base) & 0xffff == 0x14
        # Explicit clock-byte write and full data-buffer fill do not touch the
        # size word. This tests the previous false aliasing hypothesis.
        frame = bytearray(0x11c)
        frame[0x114:0x116] = mem[capacity_address].to_bytes(2, "little")
        frame[0x14] = image[0xd8]
        assert int.from_bytes(frame[0x114:0x116], "little") == 256
        frame[0x14:0x114] = bytes(range(256))
        assert int.from_bytes(frame[0x114:0x116], "little") == 256
        witnesses.append(dict(frame_base=hex(frame_base), capacity_address=hex(capacity_address),
            buffer_address=hex(buffer_address), capacity_word=256))
    return dict(capacity_offset="0x114", capacity_word=256, buffer_offset="0x14",
        buffer_end_exclusive="0x114", init_and_capacity_not_aliased=True,
        independent_instruction_lengths=11,
        instruction_witnesses=[record(i) for i in init+read], arithmetic_fixtures=witnesses)


def main():
    image = (ROOT / "analysis/firmware/micom-image.bin").read_bytes()
    assert hashlib.sha256(image).hexdigest() == IMAGE_HASH
    preimages = {
        0xda: "5208", 0xde: "5203", 0xe2: "5206", 0x164: "fcf8ff0e",
        0x19e: "bf0408", 0x1a9: "118fd800", 0x1ad: "9b",
        0x283: "ff", 0x293: "cf030803", 0x2a6: "cf030807", 0x2b5: "510a",
        0x2eb: "361403", 0x2f1: "523d", 0x2fa: "cefc0f", 0x300: "61ca",
        0x31f: "520c", 0x325: "fcf8ff0e", 0x335: "cec0a5",
        0x338: "cec40c", 0x33b: "cec4f3", 0x33e: "cec40c",
        0x348: "11af0000", 0x34f: "61cb", 0x352: "5404", 0x36b: "4c41",
        0x1316: "717abe", 0x151c: "bc14", 0x15cd: "510a", 0x15cf: "fd7106",
        0x161e: "ac14", 0x1702: "5102", 0x1711: "fc510300",
        0x1754: "fce20000", 0x17de: "fc840200", 0x17ee: "fc830200",
        0x1519: "f0e187bc149717041400fc1e1300", 0x161d: "87ac1497",
    }
    for ea, raw in preimages.items():
        assert image[ea:ea+len(bytes.fromhex(raw))].hex() == raw, hex(ea)
    layout = buffer_layout(image)
    ranges = []
    for label, start, end in (("library", 0xda, 0x3c7), ("math helpers", 0x650, 0x6ab),
                              ("FLMD init", 0x1316, 0x1357), ("program loop", 0x14f5, 0x183a)):
        data = image[start:end]
        ranges.append(dict(label=label, start=hex(start), end_exclusive=hex(end),
                           bytes=data.hex(), sha256=hashlib.sha256(data).hexdigest()))
    template = []
    ea = 0x314
    while ea < 0x351:
        ins = decoder.decode_one(image, ea)
        assert ins and ins.size and ins.mnem != ".db"
        template.append(ins)
        ea += ins.size
    assert ea == 0x351 and sum(i.size for i in template) == 61
    # Validate relative relocation and unchanged absolute calls at four model RAM
    # destinations. These are fixtures, not recovered installed stack addresses.
    relocation_fixtures = []
    for dest in (0xfbfba, 0xfc000, 0xfd000, 0xfe000):
        relocated = bytearray(0x100000)
        relocated[dest:dest+61] = image[0x314:0x351]
        delta = dest - 0x314
        for original in template:
            ins = decoder.decode_one(relocated, original.ea+delta)
            assert ins.raw == original.raw and ins.size == original.size and ins.mnem == original.mnem
            if ins.mnem == "bz":
                assert decoder.target_of(ins) == 0x335 + delta
            if ins.mnem == "call":
                assert decoder.target_of(ins) == decoder.target_of(original)
        relocation_fixtures.append(hex(dest))
    addresses = [block_address(t) for t in range(256)]
    assert addresses == list(range(0, 0x40000, 1024))
    assert addresses[8] == 0x2000 and addresses[15]+1023 == 0x3fff
    # All lengths for the caller's recovered capacity verify padding/conservation.
    cases = 0
    for length in range(1, 1025):
        payload = bytes(i & 255 for i in range(length))
        plan = chunks(8, payload, 256)
        assert sum(p["consumed"] for p in plan) == length
        assert sum(p["padding"] for p in plan) == (-length) % 4
        assert sum(p["words"]*4 for p in plan) == (length+3)//4*4
        cases += 1
    assert not write_arguments(0x2000, 0, 0x3ffff)
    assert not write_arguments(0x2000, 65, 0x3ffff)
    assert not write_arguments(0x2001, 1, 0x3ffff)
    assert not write_arguments(0x3fffc, 2, 0x3ffff)
    assert write_arguments(0x3fffc, 1, 0x3ffff)
    out = ROOT / "analysis/firmware/flash-library"
    out.mkdir(exist_ok=True)
    result = dict(flat_sha256=IMAGE_HASH, binary_execution=False, exact_cpu_identified=False,
        preimages={hex(a):v for a,v in preimages.items()}, source_ranges=ranges,
        ram_template=dict(source_start="0x314", bytes=image[0x314:0x351].hex(),
            instructions=[record(i) for i in template], size=61,
            relocated_fixture_destinations=relocation_fixtures,
            relative_branch_source="0x32a", relative_branch_target="0x335",
            absolute_calls=["0x212", "0xefff8", "0x238"],
            success_tail="protected fffc4=0c, clear fffbe.7, RB0, read ES0:0, CS0, BR AX"),
        logical_address_mapping=[dict(tag=t,start=hex(a),end_inclusive=hex(a+1023)) for t,a in enumerate(addresses)],
        library_command_candidates={"0x8":"blank check", "0x3":"erase", "0x4":"write", "0x6":"internal verify"},
        api_candidates={"0x189":"FSL_Init", "0x18d":"FSL_Init_cont", "0x114":"FSL_ModeCheck",
            "0xda":"FSL_BlankCheck", "0xde":"FSL_Erase", "0xe2":"FSL_IVerify", "0x351":"FSL_Write",
            "0x284":"FSL_InvertBootFlag", "0x2e1":"FSL_SwapBootCluster",
            "0x283":"FSL_ForceReset", "0x3a3":"FSL_SwapActiveBootCluster"},
        hidden_rom=dict(entry="0xefff8", metadata=["0xeffd0", "0xeffd1", "0xeffe2", "0xeffe3", "0xeffe4"],
                        available_in_image=False),
        buffer_initialization=dict(initial_word="0x0100", capacity_frame_offset="0x114",
            init_buffer_frame_offset="0x14", caller_layout=layout,
            clock_parameter_byte=hex(image[0xd8]), writes_first_byte_before_hidden_init=True,
            first_byte_write_aliases_capacity=False, hidden_rom_buffer_contract_verified=False),
        model_checks=dict(all_tags=256, all_one_block_lengths=cases, write_boundary_cases=5,
            caller_capacity=256, physical_write_success_proven=False,
            zero_frame=chunks(8, bytes(1024), 256)),
        reference=dict(url=FX3_URL, doc="R01UH0007EJ0600 Rev6", pages=[128,1159,1174,1176,1177,1178],
            pdf_sha256="5fea7faf79e9aa3dbf2d5fde05635a330692ba8ddd07cf80de0569d9f224a80a"),
        library_reference=dict(url=TYPE03_URL, doc="R01AN0005JJ0100 Rev1", pages=[35,36,39,41,46,47,59,60,61,62,63,64],
            pdf_sha256="d388a78e7c096800fdf1cb6705bb014552508827b78d146035a659a7a4f22827",
            abi=dict(return_register="C", write_address="AX/BC", write_word_count="stack"),
            exact_library_revision_identified=False),
        limitations=["logical library address does not identify physical boot half on an installed unit",
            "API/ABI matches Type03 documentation; exact library revision and hidden ROM unresolved",
            "caller capacity is 256; hidden-ROM adherence to its passed buffer contract is not unit-verified",
            "no live registers, FLMD0 wiring, shield window, boot flag or reset observation"],
        producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    (out/"contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    (out/"micom-image.bin").write_bytes(image)
    (out/"micom-cpu-candidates.json").write_text(json.dumps(dict(roots=["0x314"],
        exact_cpu_identified=False, binary_execution=False)),encoding="utf-8")
    (out/"rl78-instructions.json").write_text(json.dumps([record(i) for i in template],indent=2),encoding="utf-8")
    listing = ["; 61-byte RAM template, source coordinates; ISA candidate, not executed"]
    listing += [f"{i.ea:05x} {i.raw.hex():12} {i.mnem:8} "+", ".join(operand(o) for o in i.ops) for i in template]
    (out/"ram-template.asm").write_text("\n".join(listing)+"\n",encoding="utf-8")
    print(json.dumps(dict(preimages=len(preimages),ranges=len(ranges),template_instructions=len(template),
        relocation_fixtures=len(relocation_fixtures),tag_cases=256,length_cases=cases,
        buffer_layout_fixtures=len(layout["arithmetic_fixtures"]),independent_layout_lengths=11,
        unit_execution=False),indent=2))


if __name__ == "__main__":
    main()
