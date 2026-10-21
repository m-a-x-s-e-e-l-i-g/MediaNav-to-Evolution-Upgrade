"""Pin paired-device storage paths and interpret original copy/reload bytes.

No executable is written or run natively. API hooks are explicit fixtures.
The eight-loop variant exists only in interpreter memory to expose overlap.
"""
import json
import re

from inspect_bt_playback import ROOT, source
from inspect_wave_queue import BytesVM, STOP

OBJECT, SHARED, MANAGER, STACK = 0x41000000, 0x42000000, 0x43000000, 0x68000000
CONVERT = 0xf0000100


class PairVM(BytesVM):
    def __init__(self, pe, ranges, overrides=None):
        super().__init__(pe, ranges)
        self.overrides = overrides or {}

    def word(self, pc):
        original = super().word(pc)
        return self.overrides.get(pc, original)

    def plain(self, word):
        if word >> 26 == 0xa:  # SLTI: signed comparison.
            rs, rt, imm = (word >> 21) & 31, (word >> 16) & 31, word & 65535
            a = self.reg[rs]
            if a >= 0x80000000:
                a -= 0x100000000
            if imm >= 0x8000:
                imm -= 0x10000
            self.reg[rt] = int(a < imm)
            self.reg[0] = 0
        else:
            super().plain(word)


def data(vm, at, n):
    return bytes(vm.read(at + i, 1) for i in range(n))


def put(vm, at, raw):
    for i, b in enumerate(raw):
        vm.write(at + i, b, 1)


def abi(vm, va, arg):
    saved = {r: 0x12340000 + r for r in (*range(16, 24), 30)}
    for r, value in saved.items():
        vm.reg[r] = value
    vm.reg[4], vm.reg[29], vm.reg[31] = arg, STACK, STOP
    vm.run(va, {STOP}, limit=10000)
    assert vm.reg[29] == STACK
    assert all(vm.reg[r] == value for r, value in saved.items())


def copy_case(pe, count, unsafe=False):
    word = int.from_bytes(pe.get_data(0x1108ac - pe.OPTIONAL_HEADER.ImageBase, 4), "little")
    assert word & 65535 == 5 and word >> 26 == 0xb
    vm = PairVM(pe, [(0x110708, 0x1108f0)], {0x1108ac: (word & 0xffff0000) | 8} if unsafe else {})
    vm.write(OBJECT + 0x26c, count)
    # Fields immediately after the name bank must survive a normal list copy.
    before = bytes([0xa5]) * (0x5e0 - 0x5a8)
    put(vm, OBJECT + 0x5a8, before)
    records = []
    for index in range(count):
        record = bytearray(64)
        record[0] = int(index == count - 1)
        record[4:8] = (index + 1).to_bytes(4, "little")
        name = f"Device{index + 1}".encode()
        record[12:12 + len(name)] = name
        records.append(bytes(record))
        put(vm, SHARED + index * 64, record)
    reads, converted = [], []

    def shared(machine):
        assert machine.reg[4] == OBJECT + 4
        offset = machine.reg[5]
        assert offset % 64 == 0 and offset // 64 < count
        reads.append(offset // 64)
        return SHARED + offset

    def convert(machine):
        assert machine.reg[4:6] == [65001, 8] and machine.reg[7] == 50
        output = machine.read(machine.reg[29] + 0x10)
        assert machine.read(machine.reg[29] + 0x14) == 50
        # All fixtures are ASCII + zero padding; exact fixed-length UTF-16 result.
        text = data(machine, machine.reg[6], 50).decode("utf-8")
        put(machine, output, text.encode("utf-16le"))
        converted.append(output - OBJECT)
        return 50

    vm.write(0x185088, CONVERT)
    vm.hooks.update({0x11afcc: shared, CONVERT: convert})
    abi(vm, 0x110708, OBJECT)
    loaded = min(count, 8 if unsafe else 5)
    if not unsafe:
        for i in range(loaded):
            assert data(vm, OBJECT + 0x270 + i * 64, 64) == records[i]
        after = data(vm, OBJECT + 0x5a8, len(before))
        # The connected shared-record pointer at +5c0 is deliberately updated.
        assert after[:0x18] == before[:0x18] and after[0x1c:] == before[0x1c:]
        expected = count - 1 if 0 < count <= 5 else 0xffffffff
        assert vm.read(OBJECT + 0x5a4) == expected
    damaged = [hex(0x5a8 + i) for i, (a, b) in enumerate(zip(before, data(vm, OBJECT + 0x5a8, len(before))))
               if a != b and not 0x18 <= i < 0x1c]
    if unsafe:
        assert damaged, "A loop-only expansion must reproduce adjacent-field damage"
    return dict(received_count=count, loop_bound=8 if unsafe else 5,
                fetched_indices=sorted(set(reads)), converted_offsets=[hex(x) for x in converted],
                connected_index=hex(vm.read(OBJECT + 0x5a4)), adjacent_changed_bytes=len(damaged),
                first_adjacent_change=damaged[0] if damaged else None,
                abi_preserved=True, native_execution=False)


def reload_case(pe, count):
    vm = PairVM(pe, [(0x3307c, 0x33194)])
    vm.write(0x20e1e8, MANAGER)
    vm.reg[5] = 0  # Ordinary reload, no optional reordering branch.
    records = []
    for i in range(count):
        raw = bytearray(104)
        raw[:4] = (i + 1).to_bytes(4, "little")
        records.append(bytes(raw))
    loaded, ipc, requested = [], [], []

    def read_db(machine):
        requested.append(machine.reg[5])
        assert machine.reg[4] == OBJECT + 0x20 and machine.reg[5] == 5
        # Existing initializer clears exactly five slots. Short read leaves zero tail.
        put(machine, machine.reg[4], b"".join(records[:5]))
        return 1

    def init_address(machine):
        put(machine, machine.reg[4], bytes(8))
        return 0

    def equal_address(machine):
        return int(data(machine, machine.reg[4], 8) == data(machine, machine.reg[5], 8))

    def publish_record(machine):
        assert machine.reg[4] == OBJECT
        index = machine.reg[5]
        assert machine.reg[6] == OBJECT + 0x20 + (index - 1) * 104
        loaded.append(index)
        return 0

    def publish_count(machine):
        ipc.append(machine.reg[4:8].copy())
        return 0

    vm.hooks.update({0x3ac50: init_address, 0x7a8a8: read_db,
                     0x3ac90: equal_address, 0x32f00: publish_record, 0x337dc: publish_count})
    abi(vm, 0x3307c, OBJECT)
    expected = min(count, 5)
    assert loaded == list(range(1, expected + 1))
    assert vm.read(MANAGER + 0x14, 1) == vm.read(MANAGER + 0x15, 1) == expected
    assert ipc == [[2, 0x4010702, expected, expected]]
    return dict(database_records=count, requested_records=requested[0],
                published_records=expected, published_indices=loaded, abi_preserved=True,
                scope="Original reload bytes, nonzero contiguous BDADDRs, successful read hook; not live database I/O")


def passkey_case(pe, count, state):
    vm = PairVM(pe, [(0x318d4, 0x319d0)])
    vm.write(OBJECT + 4, count, 1)
    vm.write(0x20e1e8, MANAGER)
    vm.write(MANAGER + 0x278, state)
    vm.hooks.update({0x8a7c0: lambda _: 0, 0x34264: lambda _: 0})
    abi(vm, 0x318d4, OBJECT)
    accepted = count < 8 and state in (2, 4, 5, 14, 15)
    assert vm.reg[2] == int(accepted)
    return dict(paired_count=count, state=state, accepted=accepted, abi_preserved=True)


def related_gates():
    p = ROOT / "analysis/decompiled/705md/AppMain.exe/decompiled.c"
    result, current = [], None
    for i, line in enumerate(p.read_text(encoding="utf-8").splitlines(), 1):
        m = re.match(r"/\* ([0-9a-f]{8}) ", line)
        if m:
            current = m[1]
        if re.search(r"0x26c.*[<>=] [458]|[458] [<>=].*0x26c|5 < \(int\)uVar21", line):
            result.append(dict(function="0x" + current, line=i, text=line.strip(),
                               status="Classify full caller before changing; four may be page size"))
    return result


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    find = lambda name: next(m for m in modules if m["origin"] == "705md" and m["name"] == name)
    blue, blue_pe = source(find("Blue.exe"), [0x23c5c, 0x303b8, 0x31768, 0x318d4,
        0x31b40, 0x31c84, 0x32f00, 0x3307c, 0x344f4, 0x3453c, 0x3459c, 0x345ec,
        0x7a3d8, 0x7a4d0, 0x7a63c, 0x7a738, 0x7a7f8, 0x7a8a8, 0x7a974,
        0x7aa40, 0x7ab4c, 0x7ac28], {})
    app, app_pe = source(find("AppMain.exe"), [0x204dc, 0xb9570, 0xb9c1c, 0xcfcb8,
        0xd0794, 0xd10d8, 0xd2738, 0xd3dc0, 0x110708, 0x1109d4, 0x113d40,
        0x121630, 0x13120c], {})
    copy = [copy_case(app_pe, n) for n in range(10)]
    unsafe = [copy_case(app_pe, n, True) for n in (6, 7, 8)]
    reload = [reload_case(blue_pe, n) for n in range(9)]
    passkeys = [passkey_case(blue_pe, count, state) for count in range(10) for state in (0, 2, 4, 5, 14, 15, 16)]
    guards = []
    for name, pe, va, op, imm in [
        ("pair-cap", blue_pe, 0x30568, 0xb, 8),
        ("passkey-cap", blue_pe, 0x318e4, 0xb, 8),
        ("reload-read", blue_pe, 0x330a4, 9, 5),
        ("reload-loop", blue_pe, 0x33138, 0xa, 5),
        ("delete-read", blue_pe, 0x7aa8c, 9, 5),
        ("delete-write", blue_pe, 0x7ab20, 9, 5),
        ("app-copy", app_pe, 0x1108ac, 0xb, 5),
        ("app-total-clamp", app_pe, 0xd07dc, 9, 5),
        ("media-bound", blue_pe, 0x345c0, 0xa, 0x500),
    ]:
        raw = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, 4)
        word = int.from_bytes(raw, "little")
        assert word >> 26 == op and word & 65535 == imm
        guards.append(dict(name=name, va=hex(va), raw_hex=raw.hex(), immediate=imm))
    assert 0x208 == 5 * 104 and 0x140 == 5 * 64 and 500 == 5 * 100
    assert 0x270 + 5 * 64 == 0x3b0 and 0x3b0 + 5 * 100 == 0x5a4
    assert 0x3b0 + 8 * 100 == 0x6d0 and 0x20 + 8 * 104 == 0x360
    evidence = dict(status="investigation passed; eight-device patch not implemented",
        native_execution=False, firmware_written=False, target_pairs=8,
        sources=[blue, app], original_copy_cases=copy, memory_only_unsafe_expansion_cases=unsafe,
        original_reload_cases=reload, original_passkey_cases=passkeys,
        instruction_guards=guards, caller_candidates=related_gates(),
        layouts=dict(private_database_record_bytes=104, private_slots=5,
            private_start="0x20", private_end="0x228", eight_slot_end="0x360",
            app_record_start="0x270", app_record_end="0x3b0", app_record_bytes=64,
            app_name_start="0x3b0", app_name_end="0x5a4", app_name_bytes=100,
            delete_frame_bytes=0x298, delete_record_start=0x78,
            delete_stack_cookie="0x280", delete_saved_return="0x294",
            eight_delete_record_end="0x3b8"),
        remaining=["Relocate/expand Blue private database bank without damaging parent fields",
            "Adapt reload/reorder/delete together; preserve stack ABI and unwind metadata",
            "Expand AppMain paired records and resolve converted-name cache overlap",
            "Classify all pair/full-list/page gates and reconnect-attempt limit",
            "Review media-list strict upper bound: setter rejects one-based index eight",
            "Verify unit stack capacity and pair/reboot/select/delete/reconnect with eight devices",
            "Produce and independently extract a combined candidate after byte-level regression proof"])
    out = ROOT / "analysis/firmware/bt-pairing"
    out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(evidence, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=evidence["status"], source_ranges=sum(len(s["ranges"]) for s in evidence["sources"]),
        original_copy_cases=len(copy), original_reload_cases=len(reload), unsafe_overlap_cases=len(unsafe),
        passkey_cases=len(passkeys), instruction_guards=len(guards),
        report=str(out / "contracts.json")), indent=2))


if __name__ == "__main__":
    main()
