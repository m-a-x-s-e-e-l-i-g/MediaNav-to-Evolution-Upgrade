"""Interpret the memory-only relocated eight-record Blue storage draft.

OS/database calls are fixtures. This is not a live database or native firmware
test, and does not authorize using the draft in a flashable package.
"""
import hashlib
import json
import struct
import math
import re
import pefile

from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import PairVM, OBJECT, MANAGER, STACK, data, put, abi
from inspect_wave_queue import STOP
from draft_bt_pairing_storage import draft_blue_storage, draft_app_pairing, BANK, PAIRS, RECORD_BYTES, DELETE_FRAME

COOKIE, ADDRESS, META = 0x1234abcd, 0x44000000, 0x45000000
RANGES = [(0x31768, 0x317f0), (0x31c84, 0x31dcc), (0x3307c, 0x33194),
          (0x7aa40, 0x7ab4c), (0x3459c, 0x345ec), (0x8ab84, 0x8ac04)]


class StorageVM(PairVM):
    def plain(self, word):
        op, rs, rt, fn = word >> 26, (word >> 21) & 31, (word >> 16) & 31, word & 63
        rd = (word >> 11) & 31
        if op == 0 and fn in (0x18, 0x19):
            a, b = self.reg[rs], self.reg[rt]
            if fn == 0x18:
                if a >= 0x80000000: a -= 0x100000000
                if b >= 0x80000000: b -= 0x100000000
            value = (a * b) & 0xffffffffffffffff
            self.hi, self.lo = value >> 32, value & 0xffffffff
        elif op == 0 and fn == 0x12:
            self.reg[rd] = self.lo
        elif op == 0 and fn == 0x2a:
            signed = lambda x: x if x < 0x80000000 else x - 0x100000000
            self.reg[rd] = int(signed(self.reg[rs]) < signed(self.reg[rt]))
        else:
            super().plain(word)
        self.reg[0] = 0

    def run(self, start, stops, limit=10000):
        self.pc = start
        initial = self.steps
        while self.pc not in stops:
            assert self.steps - initial < limit
            pc, word = self.pc, self.word(self.pc)
            op, rs, rt, fn = word >> 26, (word >> 21) & 31, (word >> 16) & 31, word & 63
            control = op in (1, 2, 3, 4, 5, 6, 7) or (op == 0 and fn in (8, 9))
            if not control:
                self.plain(word); self.pc += 4; self.steps += 1
                continue
            hook = None
            if op in (1, 4, 5, 6, 7):
                offset = word & 65535
                if offset >= 32768: offset -= 65536
                value = self.reg[rs]
                if value >= 0x80000000: value -= 0x100000000
                if op == 1:
                    assert rt in (0, 1), "Only reviewed BLTZ/BGEZ are supported"
                    taken = (value < 0) if rt == 0 else (value >= 0)
                elif op in (4, 5):
                    taken = (self.reg[rs] == self.reg[rt]) == (op == 4)
                else:
                    assert rt == 0
                    taken = value <= 0 if op == 6 else value > 0
                target = pc + 4 + offset * 4 if taken else pc + 8
            elif op == 0:
                target = self.reg[rs]
                if fn == 9:
                    self.reg[(word >> 11) & 31] = pc + 8
                    hook = self.hooks.get(target)
                    assert hook is not None or self.internal_call(target), hex(target)
            else:
                target = ((pc + 4) & 0xf0000000) | ((word & 0x3ffffff) << 2)
                if op == 3:
                    self.reg[31] = pc + 8
                    hook = self.hooks.get(target)
                    assert hook is not None or self.internal_call(target), hex(target)
            self.pc = pc + 4
            self.plain(self.word(pc + 4))
            self.steps += 2
            if hook is not None:
                self.reg[2] = hook(self) & 0xffffffff
                self.pc = pc + 8
            else:
                self.pc = target
        return self.pc


def records(n):
    result = []
    for i in range(n):
        raw = bytearray(RECORD_BYTES)
        raw[:8] = (i + 1).to_bytes(8, "little")
        name = f"Device{i + 1}".encode()
        raw[0x1a:0x1a + len(name)] = name
        raw[0x50:0x54] = (0x200 + i).to_bytes(4, "little")
        # Payload beyond BDADDR/name must survive every move, not just the address.
        raw[0x58:] = bytes([0x30 + i]) * (RECORD_BYTES - 0x58)
        result.append(bytes(raw))
    return result


class Fixture:
    def __init__(self, pe, db):
        self.vm = StorageVM(pe, RANGES)
        self.db = list(db) + [bytes(RECORD_BYTES)] * (PAIRS - len(db))
        self.writes, self.published, self.ipc, self.cookies = [], [], [], []
        self.read_result = 1
        vm = self.vm
        vm.write(0x20e1e8, MANAGER)
        vm.write(0x110ea4, COOKIE)
        self.fields = bytes([0xa5]) * (0x2f0 - 0x228)
        put(vm, OBJECT + 0x228, self.fields)

        def memset(machine):
            at, value, n = machine.reg[4:7]
            put(machine, at, bytes([value & 255]) * n)
            return at

        def memcpy(machine):
            at, src, n = machine.reg[4:7]
            put(machine, at, data(machine, src, n))
            return at

        def read_db(machine):
            assert machine.reg[5] == PAIRS
            if not self.read_result:
                return 0
            put(machine, machine.reg[4], b"".join(self.db))
            return 1

        def write_db(machine):
            assert machine.reg[5] == PAIRS
            raw = data(machine, machine.reg[4], PAIRS * RECORD_BYTES)
            self.db = [raw[i * RECORD_BYTES:(i + 1) * RECORD_BYTES] for i in range(PAIRS)]
            self.writes.append([int.from_bytes(r[:8], "little") for r in self.db])
            return 1

        def lookup(machine):
            address = data(machine, machine.reg[4], 8)
            match = next((r for r in self.db if r[:8] == address), None)
            if match is None: return 0
            put(machine, machine.reg[5], match)
            return 1

        def address_init(machine):
            put(machine, machine.reg[4], bytes(8)); return 0

        def compare(machine):
            return int(data(machine, machine.reg[4], 8) == data(machine, machine.reg[5], 8))

        def publish(machine):
            at = machine.reg[6]
            self.published.append(data(machine, at, RECORD_BYTES))
            assert machine.reg[4] == OBJECT and machine.reg[5] == len(self.published)
            return 0

        def cookie(machine):
            assert machine.reg[4] == COOKIE, "Cookie overwritten or wrong frame-relative location"
            self.cookies.append(machine.reg[4]); return 0

        vm.hooks.update({0x3a750: memset, 0x8ac14: memset, 0x85758: memcpy,
            0x7a8a8: read_db, 0x7a974: write_db, 0x7a63c: lookup,
            0x3ac50: address_init, 0x3ac90: compare, 0x32f00: publish,
            0x337dc: lambda machine: self.ipc.append(machine.reg[4:8].copy()) or 0,
            0x8ac24: cookie})

    def unchanged_fields(self):
        assert data(self.vm, OBJECT + 0x228, len(self.fields)) == self.fields

    def reload(self, address=0):
        self.published.clear(); self.vm.reg[5] = address
        abi(self.vm, 0x3307c, OBJECT)
        self.unchanged_fields()
        return self.published


def app_copy(pe, n, connected):
    vm = StorageVM(pe, [(0x110708, 0x1108f0)])
    vm.write(OBJECT + 0x26c, n)
    # The tail of the former name cache and all adjacent status fields must stay intact.
    tail = bytes([0x77]) * (0x5a4 - 0x470)
    fields = bytes([0xa5]) * (0x5e0 - 0x5a8)
    put(vm, OBJECT + 0x470, tail); put(vm, OBJECT + 0x5a8, fields)
    shared = 0x47000000
    raw_records, reads = [], []
    names = ["Telefoon", "Émile", "Müller", "Ελένη", "日本語", "Žofie", "Телефон", "Device8"]
    for i in range(n):
        raw = bytearray(64)
        raw[0] = int(i == connected)
        raw[4:8] = (i + 1).to_bytes(4, "little")
        name = names[i % len(names)].encode("utf-8")
        raw[12:12 + len(name)] = name
        raw[62:] = bytes([0x30 + i]) * 2
        raw_records.append(bytes(raw)); put(vm, shared + i * 64, raw)

    def read_shared(machine):
        assert machine.reg[4] == OBJECT + 4 and machine.reg[5] % 64 == 0
        index = machine.reg[5] // 64
        assert index < n
        reads.append(index)
        return shared + index * 64

    vm.hooks[0x11afcc] = read_shared
    # No conversion hook: an accidental remaining call must fail closed.
    vm.write(0x185088, 0xf0000100)
    abi(vm, 0x110708, OBJECT)
    assert sorted(set(reads)) == list(range(min(n, PAIRS)))
    for i in range(PAIRS):
        expected = raw_records[i] if i < n else bytes(64)
        assert data(vm, OBJECT + 0x270 + i * 64, 64) == expected
    assert data(vm, OBJECT + 0x470, len(tail)) == tail
    after = data(vm, OBJECT + 0x5a8, len(fields))
    assert after[:0x18] == fields[:0x18] and after[0x1c:] == fields[0x1c:]
    expected_index = connected if connected is not None and connected < PAIRS else 0xffffffff
    assert vm.read(OBJECT + 0x5a4) == expected_index
    if connected is not None and connected < PAIRS:
        assert vm.read(OBJECT + 0x5c0) == shared + connected * 64
    return dict(received_count=n, connected_index=connected, loaded_records=min(n, PAIRS),
                exact_utf8_payload=True, adjacent_fields_preserved=True, abi_preserved=True)


def page_count(pe, count, old_page):
    vm = StorageVM(pe, [(0xd0794, 0xd0840)])
    dialog = 0x46000000
    vm.write(0x187be4, MANAGER); vm.write(MANAGER + 0xa0, OBJECT)
    vm.write(OBJECT + 0x26c, count); vm.write(dialog + 0x63bc, old_page)

    def double_value(lo, hi):
        return struct.unpack("<d", struct.pack("<II", lo, hi))[0]

    def return_double(machine, value):
        lo, hi = struct.unpack("<II", struct.pack("<d", float(value)))
        machine.reg[3] = hi
        return lo

    vm.hooks.update({
        0x140df4: lambda m: return_double(m, m.reg[4]),
        0x140e04: lambda m: return_double(m, double_value(m.reg[4], m.reg[5]) * double_value(m.reg[6], m.reg[7])),
        0x140360: lambda m: return_double(m, math.ceil(double_value(m.reg[4], m.reg[5]))),
        0x140e14: lambda m: int(double_value(m.reg[4], m.reg[5]))})
    abi(vm, 0xd0794, dialog)
    shown = min(max(count, 0), PAIRS)
    assert vm.read(dialog + 0x63c4) == shown
    assert vm.read(dialog + 0x63c0) == (shown + 3) // 4
    assert vm.read(dialog + 0x63bc) == (0 if count < 5 else old_page)
    return dict(received_count=count, shown_records=shown, pages=(shown + 3) // 4,
                page_after=vm.read(dialog + 0x63bc), physical_rows=4, abi_preserved=True)


def cache_references():
    result, class_forms = [], []
    for line in (ROOT / "analysis/disassembly/AppMain.exe.asm").read_text(encoding="utf-8").splitlines():
        match = re.match(r"([0-9a-f]{8})  ", line)
        if not match or not re.search(r"(?<![0-9a-f-])0x3b0(?![0-9a-f])", line.split(";")[0]):
            continue
        va = int(match[1], 16)
        result.append(dict(va=hex(va), text=line, class_region=0x110010 <= va < 0x114518))
        if 0x110010 <= va < 0x114518:
            class_forms.append(va)
    assert class_forms == [0x1100a4, 0x110754, 0x113d6c]
    return dict(direct_immediate_references=result,
        class_cache_address_forms=[hex(v) for v in class_forms],
        classification="Constructor zero, list-copy destination, reset zero; no additional direct +3b0 forms",
        limitation="Direct immediate references do not prove absence of aliases, folded offsets or indirect readers")


def io_status_case(pe, writer, actual_bytes):
    start, end = (0x7a974, 0x7aa40) if writer else (0x7a8a8, 0x7a974)
    vm = StorageVM(pe, [(start, end)])
    transfers = []

    def transfer(machine):
        assert machine.reg[4:8] == [OBJECT, 1, PAIRS * RECORD_BYTES, 0x1234]
        transfers.append(actual_bytes)
        return actual_bytes

    vm.hooks.update({0x7a3d8: lambda _: 1, 0x85f84: lambda _: 0x1234,
                     0x86144: lambda _: 0, 0x86088: lambda _: 0,
                     (0x860ac if writer else 0x860f8): transfer})
    vm.reg[5] = PAIRS
    abi(vm, start, OBJECT)
    assert vm.reg[2] == 1 and transfers == [actual_bytes]
    return dict(operation="write" if writer else "read", requested_bytes=PAIRS * RECORD_BYTES,
                returned_transfer_bytes=actual_bytes, reported_success=vm.reg[2],
                finding="Bulk helper ignores the transfer byte count after successful open/seek",
                scope="Original bulk helper bytes; successful magic/open/seek and explicit transfer-count hook")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    evidence, original_pe = source(module, [0x2e6f4, 0x32e90, 0x31768, 0x31c84, 0x3307c,
        0x7aa40, 0x7ab4c, 0x3459c, 0x8ab84, 0x8abd8, 0x7a8a8, 0x7a974, 0x860ac, 0x860f8], {})
    raw = (ROOT / module["path"]).read_bytes()
    draft, patch = draft_blue_storage(raw)
    pe = pefile.PE(data=draft)
    traces = []
    for n in range(PAIRS + 1):
        original = records(n)
        f = Fixture(pe, original)
        assert f.reload() == original
        assert f.ipc[-1] == [2, 0x4010702, n, n]
        traces.append(dict(kind="reload", records=n, exact_payload=True))
        for index in range(n):
            f = Fixture(pe, original)
            put(f.vm, OBJECT + BANK, b"".join(f.db))
            put(f.vm, ADDRESS, original[index][:8])
            expected = [original[index]] + original[:index] + original[index + 1:]
            assert f.reload(ADDRESS) == expected
            assert f.db[:n] == expected
            assert all(r == bytes(RECORD_BYTES) for r in f.db[n:])
            traces.append(dict(kind="move-to-front-and-reload", records=n, selected_index=index, exact_payload=True))
            f = Fixture(pe, original)
            # The actual delete caller zeros the selected record before compacting.
            f.db[index] = bytes(RECORD_BYTES)
            abi(f.vm, 0x7aa40, index)
            expected = original[:index] + original[index + 1:]
            assert f.db[:n - 1] == expected
            assert all(r == bytes(RECORD_BYTES) for r in f.db[n - 1:])
            assert f.cookies == [COOKIE] and len(f.writes) == 1
            assert f.reload() == expected
            traces.append(dict(kind="delete-and-reload", records=n, deleted_index=index, exact_payload=True,
                               cookie_checked=True, frame_restored=True))
    # Actual initialized-bank bytes must not touch either old flags or following memory.
    failures = []
    for index in (0, 3, 7):
        f = Fixture(pe, records(8))
        f.read_result = 0
        before = f.db.copy()
        abi(f.vm, 0x7aa40, index)
        assert f.db == before and not f.writes and f.cookies == [COOKIE]
        failures.append(dict(kind="failed-read-no-write", index=index))
    for index in (8, 9, 0x7fffffff, 0xffffffff):
        f = Fixture(pe, records(8))
        before = f.db.copy()
        abi(f.vm, 0x7aa40, index)
        assert f.db == before and not f.writes and f.cookies == [COOKIE]
        failures.append(dict(kind="invalid-index-no-write", index=hex(index)))
    f = Fixture(pe, [])
    put(f.vm, OBJECT + BANK, bytes([0x77]) * (PAIRS * RECORD_BYTES))
    f.vm.write(OBJECT + BANK + PAIRS * RECORD_BYTES, 0x99887766)
    abi(f.vm, 0x31768, OBJECT)
    assert data(f.vm, OBJECT + BANK, PAIRS * RECORD_BYTES) == bytes(PAIRS * RECORD_BYTES)
    assert f.vm.read(OBJECT + BANK + PAIRS * RECORD_BYTES) == 0x99887766
    # Unchanged GS metadata uses offset -24 relative to caller SP for both frames.
    metadata = original_pe.get_data(0x10f1e4 - original_pe.OPTIONAL_HEADER.ImageBase, 4)
    assert struct.unpack("<i", metadata)[0] == -24
    for frame in (0x298, DELETE_FRAME):
        vm = StorageVM(pe, RANGES)
        vm.write(META, 0xffffffe8)
        vm.write(STACK - frame + frame - 24, COOKIE)
        vm.hooks[0x8ac24] = lambda machine: 0 if machine.reg[4] == COOKIE else (_ for _ in ()).throw(AssertionError("Wrong unwind cookie"))
        vm.reg[4:7] = [STACK, 0, META]
        vm.run(0x8ab84, {STOP})
        assert vm.reg[29] == STACK
    app_module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    app_source, _ = source(app_module, [0x204dc, 0xb9570, 0xb9c1c, 0xcfcb8, 0xd0794,
        0xd2738, 0x110010, 0x110708, 0x1109d4, 0x111d84, 0x113d40, 0x11589c, 0x13120c], {})
    app_draft, app_patch = draft_app_pairing((ROOT / app_module["path"]).read_bytes())
    app_pe = pefile.PE(data=app_draft)
    app_traces = [app_copy(app_pe, n, connected) for n in range(PAIRS + 1)
                  for connected in [None, *range(n)]]
    pages = [page_count(app_pe, count, page) for count in range(10) for page in (0, 1)]
    io_status = [io_status_case(original_pe, writer, actual) for writer in (False, True)
                 for actual in (0, 1, 103, 104, 520, 831, 832)]
    short_database_migration = []
    for existing_records in (0, 1, 5, 7):
        old = records(8)
        f = Fixture(pe, old)
        put(f.vm, OBJECT + BANK, b"".join(old))

        def short_read(machine, n=existing_records):
            put(machine, machine.reg[4], b"".join(old[:n]))
            return 1  # Successful complete short read; the coupled I/O proof checks the real helper.

        f.vm.hooks[0x7a8a8] = short_read
        assert f.reload() == old[:existing_records]
        assert data(f.vm, OBJECT + BANK + existing_records * RECORD_BYTES,
                    (PAIRS - existing_records) * RECORD_BYTES) == bytes((PAIRS - existing_records) * RECORD_BYTES)
        short_database_migration.append(dict(file_records=existing_records, published_records=existing_records,
                               discarded_stale_records=8 - existing_records,
                               status="stale tail cleared before short reload in current memory draft"))
    out = ROOT / "analysis/firmware/bt-pairing-storage-draft"
    out.mkdir(parents=True, exist_ok=True)
    dependencies = ["verify_bt_pairing_storage.py", "draft_bt_pairing_storage.py", "inspect_bt_pairing.py",
                    "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py", "patch_bt_playback.py",
                    "draft_bt_database_io.py"]
    result = dict(status="storage draft offline checks passed; not a complete pairing update",
        native_execution=False, executable_written=False, build_allowed=False, source=evidence,
        patch=patch, traces=traces, failure_traces=failures, initialized_bank_bytes=PAIRS * RECORD_BYTES,
        app_source=app_source, app_patch=app_patch, app_copy_traces=app_traces, app_page_traces=pages,
        name_cache_audit=cache_references(),
        original_bulk_io_status_traces=io_status, short_database_migration_traces=short_database_migration,
        release_blockers=["Record-level storage paths have a separate coupled proof; higher callers still ignore persistence status",
                          "Atomic short-write/header recovery and interrupted-write handling remain open",
                          "Audit indirect name-cache consumers and full UI/connection state paths"],
        unwind_cookie_original_and_expanded_frames=True,
        dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], traces=len(traces), failure_traces=len(failures),
                         changed_instructions=patch["changed_instruction_words"],
                         changed_bytes=patch["changed_bytes"], app_copy_cases=len(app_traces),
                         app_page_cases=len(pages), app_changed_bytes=app_patch["changed_bytes"],
                         reproduced_io_status_cases=len(io_status), short_database_migration_cases=len(short_database_migration),
                         report=str(out / "contracts.json")), indent=2))


if __name__ == "__main__":
    main()
