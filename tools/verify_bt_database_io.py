"""Link patched magic/bulk/wrapper MIPS bytes to explicit file-API fixtures.

This is a byte interpreter with an in-memory file, not Windows CE execution.
Partial writes may already mutate a prefix; recognition is not atomic rollback.
"""
import hashlib
import json
import struct
import re
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, MANAGER, STACK, data, put, abi
from verify_bt_pairing_storage import StorageVM, RANGES, records, COOKIE
from draft_bt_pairing_storage import draft_blue_storage, BANK, PAIRS, RECORD_BYTES

READ_API, WRITE_API, HEADER = 0xf0020010, 0xf0020020, b"\x02\x00\xff\xff"
IO_RANGES = [*RANGES, (0x7a3d8, 0x7a4d0), (0x7a8a8, 0x7a974), (0x7a974, 0x7aa40),
             (0x860ac, 0x860f8), (0x860f8, 0x86144), (0x3ac90, 0x3accc),
             (0x7a4d0, 0x7a63c), (0x7a63c, 0x7a738), (0x7a738, 0x7a7f8),
             (0x7ab4c, 0x7ac28), (0xc26cc, 0xc2810), (0x7998c, 0x799b4)]


class IOVM(StorageVM):
    def plain(self, word):
        if word >> 26 == 0x29:
            rs, rt = (word >> 21) & 31, (word >> 16) & 31
            offset = word & 0xffff
            if offset & 0x8000: offset -= 0x10000
            self.write((self.reg[rs] + offset) & 0xffffffff, self.reg[rt] & 0xffff, 2)
        elif word >> 26 == 0 and word & 63 == 2:
            rt, rd, shift = (word >> 16) & 31, (word >> 11) & 31, (word >> 6) & 31
            self.reg[rd] = self.reg[rt] >> shift
        elif word >> 26 == 0 and word & 63 == 0x1b:
            rs, rt = (word >> 21) & 31, (word >> 16) & 31
            assert self.reg[rt] != 0
            self.lo, self.hi = divmod(self.reg[rs], self.reg[rt])
        else:
            super().plain(word)
        self.reg[0] = 0


class Database:
    def __init__(self, pe, contents):
        self.vm = IOVM(pe, IO_RANGES)
        self.contents = bytearray(contents)
        self.handles, self.next_handle, self.events = {}, 0x1000, []
        self.read_bool = True; self.write_bool = True
        self.header_read_bool = True; self.header_write_bool = True
        self.read_reported = None; self.write_reported = None
        self.header_read_reported = None
        self.read_overrides = {}
        self.bulk_open_fail = False; self.seek_fail = False
        self.vm.write(0x110114, READ_API); self.vm.write(0x110000, WRITE_API)
        self.vm.write(0x110ea4, COOKIE); self.vm.write(0x20e1e8, MANAGER)
        self.vm.hooks.update({0x85f84: self.open, 0x86144: self.seek,
            0x86088: self.close, READ_API: self.read, WRITE_API: self.write,
            0x3a750: self.memset, 0x85758: self.memcpy, 0x3ac50: self.empty_address,
            0x32f00: self.publish, 0x337dc: self.ipc,
            0x8ac24: self.cookie})
        self.published, self.messages = [], []

    def open(self, vm):
        assert vm.reg[4] == 0x1039f0 and vm.reg[5] in (0x80000000, 0x40000000)
        bulk = any(e["kind"] == "read" and e["requested"] == 4 for e in self.events)
        if bulk and self.bulk_open_fail:
            self.events.append(dict(kind="open-failed", access=vm.reg[5])); return 0xffffffff
        handle = self.next_handle; self.next_handle += 1
        self.handles[handle] = dict(position=0, access=vm.reg[5])
        self.events.append(dict(kind="open", handle=handle, access=vm.reg[5]))
        return handle

    def close(self, vm):
        handle = vm.reg[4]
        valid = handle in self.handles
        self.handles.pop(handle, None)
        self.events.append(dict(kind="close", handle=hex(handle), valid=valid))
        # Force callers to retain required status before calling CloseHandle.
        vm.reg[3] = 0xdeadc0de
        return int(valid)

    def seek(self, vm):
        assert vm.reg[4] in self.handles and vm.reg[6] == 0
        if self.seek_fail:
            self.events.append(dict(kind="seek-failed")); return 0xffff
        self.handles[vm.reg[4]]["position"] = vm.reg[5]
        self.events.append(dict(kind="seek", position=vm.reg[5])); return 0

    def read(self, vm):
        handle, destination, requested, out_count = vm.reg[4:8]
        assert handle in self.handles and self.handles[handle]["access"] == 0x80000000
        assert vm.read(vm.reg[29] + 0x10) == 0
        assert out_count == vm.reg[29] + 0x18
        position = self.handles[handle]["position"]
        header = position == 0 and requested == 4
        ok = self.header_read_bool if header else self.read_bool
        override = self.header_read_reported if header else self.read_reported
        if not header and requested in self.read_overrides:
            ok, override = self.read_overrides[requested]
        available = bytes(self.contents[position:position + requested])
        reported = len(available) if override is None else override
        transferred = min(len(available), requested, reported)
        put(vm, destination, available[:transferred]); vm.write(out_count, reported)
        self.handles[handle]["position"] += transferred
        self.events.append(dict(kind="read", position=position, requested=requested,
                                bool=ok, reported=reported, transferred=transferred))
        return int(ok)

    def write(self, vm):
        handle, source_ptr, requested, out_count = vm.reg[4:8]
        assert handle in self.handles and self.handles[handle]["access"] == 0x40000000
        assert vm.read(vm.reg[29] + 0x10) == 0 and out_count == vm.reg[29] + 0x18
        position = self.handles[handle]["position"]
        header = position == 0 and requested == 4
        ok = self.header_write_bool if header else self.write_bool
        reported = requested if header or self.write_reported is None else self.write_reported
        transferred = min(requested, reported)
        payload = data(vm, source_ptr, transferred)
        if position + transferred > len(self.contents):
            self.contents.extend(bytes(position + transferred - len(self.contents)))
        self.contents[position:position + transferred] = payload
        self.handles[handle]["position"] += transferred
        vm.write(out_count, reported)
        self.events.append(dict(kind="write", position=position, requested=requested,
                                bool=ok, reported=reported, transferred=transferred))
        return int(ok)

    def memset(self, vm):
        at, value, n = vm.reg[4:7]
        put(vm, at, bytes([value & 255]) * n); return at

    def empty_address(self, vm):
        put(vm, vm.reg[4], bytes(8)); return 0

    def memcpy(self, vm):
        at, source_ptr, n = vm.reg[4:7]
        put(vm, at, data(vm, source_ptr, n)); return at

    def publish(self, vm):
        assert vm.reg[4] == OBJECT and vm.reg[5] == len(self.published) + 1
        self.published.append(data(vm, vm.reg[6], RECORD_BYTES)); return 0

    def ipc(self, vm):
        self.messages.append(vm.reg[4:8].copy()); return 0

    def cookie(self, vm):
        assert vm.reg[4] == COOKIE; return 0

    def call(self, address, arg=OBJECT, second=PAIRS):
        self.vm.reg[5] = second
        abi(self.vm, address, arg)
        assert not self.handles, "Opened handle leaked"
        return self.vm.reg[2]


def csr_caller_case(pe, records_before, write_ok, reported):
    """Original SC caller chained to patched lookup/writer, with string/queue API fixtures.

    SD registration is not labeled GUI pairing success. Its asynchronous receiver
    and radio state are not executed here.
    """
    db = Database(pe, HEADER + b"".join(records(records_before)))
    context, event = 0x46000000, 0x47000000
    target = records(1)[0][:8] if records_before < PAIRS else bytes.fromhex("efcdab8944002211")
    put(db.vm, context, bytes(0x124)); put(db.vm, context + 0x44, target)
    put(db.vm, context + 0x4d, b"CSR name\0"); put(db.vm, context + 0x110, bytes(range(16)))
    db.vm.write(context + 0x40, 0xabcdef01)
    db.vm.write(context + 0x81, 1, 1); db.vm.write(context + 0x120, 1, 1)
    db.vm.write(0x218648, 0x321, 2)
    db.write_bool, db.write_reported = write_ok, reported

    def allocate(vm):
        assert vm.reg[4] == 0x24
        db.events.append(dict(kind="allocate-message", bytes=0x24)); return event

    def copy_name(vm):
        at, origin, bound = vm.reg[4:7]
        assert at == vm.reg[29] + 0x2a and origin == context + 0x4d and bound == 0x33
        put(vm, at, data(vm, origin, bound)); return at

    def trim_name(vm):
        assert vm.reg[4] == vm.reg[29] + 0x2a and vm.reg[5] == 0x32
        vm.write(vm.reg[4] + 0x32, 0, 1); return 0

    def enqueue(vm):
        assert vm.reg[4:7] == [0x321, 0x11e, event]
        payload = data(vm, event, 0x24)
        assert payload[:2] == b"\x11\0" and payload[4:12] == target
        assert payload[12:16] == bytes.fromhex("01efcdab")
        assert payload[16:20] == (5).to_bytes(4, "little")
        db.events.append(dict(kind="enqueue-sd-registration", payload_hex=payload.hex())); return 0

    db.vm.hooks.update({0x85b70: allocate, 0x835b8: copy_name,
                       0x83540: trim_name, 0x84ec8: enqueue})
    db.call(0xc26cc, context)
    kinds = [e["kind"] for e in db.events]
    assert kinds.count("enqueue-sd-registration") == 1
    if records_before == PAIRS:
        assert not any(e["kind"] == "write" for e in db.events)
        assert bytes(db.contents) == HEADER + b"".join(records(PAIRS))
    else:
        assert kinds.index("enqueue-sd-registration") < kinds.index("write")
        if write_ok and reported == 104:
            saved = bytes(db.contents[4:108])
            assert saved[:8] == target and saved[8:10] == b"\x01\x10"
            assert saved[10:26] == bytes(range(16)) and saved[26:35] == b"CSR name\0"
            assert saved[0x50:0x54] == bytes.fromhex("01efcdab") and saved[0x64:0x66] == b"\x01\x01"
    return dict(kind="original-csr-caller-enqueues-before-persistence", records=records_before,
                write_bool=write_ok, write_reported=reported,
                trace=db.events, caller_propagates_persistence_status=False,
                scope="Original SC construction/SD enqueue order with patched database chain; no GUI/radio success assertion")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    src, _ = source(module, [0x7a3d8, 0x7a8a8, 0x7a974, 0x860ac, 0x860f8, 0x85f84,
        0x86144, 0x86088, 0x3307c, 0x7aa40, 0x7a4d0, 0x7a63c, 0x7a738, 0x7ab4c,
        0x3ac90, 0xc26cc, 0x7998c, 0x8a230, 0xbb04c, 0xbdaa0, 0x2f5f0], {0x3ac90: 0x3c})
    raw = (ROOT / module["path"]).read_bytes()
    patched, patch = draft_blue_storage(raw)
    pe = pefile.PE(data=patched)
    checks = []
    payload = b"".join(records(PAIRS))
    for writer in (False, True):
        for size, count in ((0, 5), (1, 4), (2, 3), (104, 2)):
            for ok in (False, True):
                db = Database(pe, HEADER + payload)
                handle = 0x1234
                db.handles[handle] = dict(position=4, access=0x40000000 if writer else 0x80000000)
                db.read_bool = db.write_bool = ok
                put(db.vm, OBJECT, payload)
                db.vm.reg[5:8] = [size, count, handle]
                abi(db.vm, 0x860ac if writer else 0x860f8, OBJECT)
                assert db.vm.reg[2:4] == [size * count, int(ok)]
                checks.append(dict(kind="wrapper-byte-count-abi-and-bool", writer=writer,
                                   item_size=size, items=count, returned_bytes=size * count, api_bool=ok))
    for n in range(PAIRS + 1):
        db = Database(pe, HEADER + payload[:n * RECORD_BYTES])
        put(db.vm, OBJECT + BANK, bytes([0xa5]) * (PAIRS * RECORD_BYTES))
        assert db.call(0x3307c, second=0) == 1
        assert db.published == records(n)
        assert db.messages == [[2, 0x4010702, n, n]]
        assert data(db.vm, OBJECT + BANK + n * RECORD_BYTES, (PAIRS - n) * RECORD_BYTES) == bytes((PAIRS - n) * RECORD_BYTES)
        assert not any(e["kind"] == "write" for e in db.events)
        checks.append(dict(kind="whole-short-database-reload", records=n, success=True))
    for ok in (False, True):
        for actual in (0, 1, 103, 104, 105, 520, 728, 831, 832, 833, 936, 0xffffffff):
            db = Database(pe, HEADER + payload)
            db.read_bool, db.read_reported = ok, actual
            expected = ok and actual <= len(payload) and actual % RECORD_BYTES == 0
            assert db.call(0x7a8a8) == int(expected)
            checks.append(dict(kind="bulk-read-status", api_bool=ok, reported=actual, accepted=expected))
        for actual in (0, 1, 103, 104, 520, 831, 832, 833, 0xffffffff):
            db = Database(pe, HEADER + payload)
            db.write_bool, db.write_reported = ok, actual
            put(db.vm, OBJECT, payload)
            expected = ok and actual == len(payload)
            assert db.call(0x7a974) == int(expected)
            if expected:
                assert bytes(db.contents) == HEADER + payload
            checks.append(dict(kind="bulk-write-status", api_bool=ok, reported=actual, accepted=expected,
                               rollback_proven=False))
    # Real chained delete body -> bulk helper -> magic -> wrapper -> API.
    for ok, actual in ((False, 0), (False, 104), (True, 1), (True, 105), (True, 831), (True, 833)):
        db = Database(pe, HEADER + payload)
        db.read_bool, db.read_reported = ok, actual
        before = bytes(db.contents)
        db.call(0x7aa40, arg=3)
        assert bytes(db.contents) == before and not any(e["kind"] == "write" for e in db.events)
        checks.append(dict(kind="delete-refuses-invalid-read", api_bool=ok, reported=actual, no_write=True))
    for index in range(PAIRS):
        db = Database(pe, HEADER + payload)
        db.call(0x7aa40, arg=index)
        remaining = records(PAIRS)[:index] + records(PAIRS)[index + 1:] + [bytes(RECORD_BYTES)]
        assert bytes(db.contents) == HEADER + b"".join(remaining)
        checks.append(dict(kind="delete-with-native-io-chain", index=index, exact_payload=True))
    for ok, reported in ((False, 0), (False, 4)):
        db = Database(pe, HEADER + payload)
        db.header_read_bool, db.header_read_reported = ok, reported
        before = bytes(db.contents)
        assert db.call(0x7a3d8) == 0
        assert bytes(db.contents) == before and not any(e["kind"] == "write" for e in db.events)
        checks.append(dict(kind="header-read-error-no-rewrite", reported=reported, no_write=True))
    for writer in (False, True):
        for fault in ("bulk_open_fail", "seek_fail"):
            db = Database(pe, HEADER + payload)
            setattr(db, fault, True)
            put(db.vm, OBJECT, payload)
            assert db.call(0x7a974 if writer else 0x7a8a8) == 0
            assert not any(e["kind"] == "write" for e in db.events)
            checks.append(dict(kind="bulk-open-seek-error", writer=writer, fault=fault, no_write=True))
    # Interpret the actual BDADDR leaf: byte 5 is padding, not address data.
    address, destination = 0x44000000, 0x45000000
    for index in range(PAIRS):
        for mode in (0, 1):
            db = Database(pe, HEADER + payload)
            target = bytearray(records(PAIRS)[index][:8]); target[5] = 0xa5
            put(db.vm, address, target)
            assert db.call(0x7a4d0, address, mode) == index
            assert not any(e["kind"] == "write" for e in db.events)
            checks.append(dict(kind="native-find-padding-ignored", index=index, mode=mode))
        db = Database(pe, HEADER + payload)
        put(db.vm, address, target)
        assert db.call(0x7a63c, address, destination) == 1
        assert data(db.vm, destination, RECORD_BYTES) == records(PAIRS)[index]
        checks.append(dict(kind="native-record-lookup", index=index, exact_payload=True))
    missing = bytes.fromhex("efcdab8944002211")
    for n in range(PAIRS + 1):
        for mode in (0, 1):
            db = Database(pe, HEADER + payload[:n * RECORD_BYTES])
            put(db.vm, address, missing)
            expected = n if mode == 0 else 0xffffffff
            assert db.call(0x7a4d0, address, mode) == expected
            checks.append(dict(kind="native-find-clean-eof", records=n, mode=mode, result=hex(expected)))
        db = Database(pe, HEADER + payload[:n * RECORD_BYTES])
        put(db.vm, address, missing)
        assert db.call(0x7a63c, address, destination) == 0
        checks.append(dict(kind="native-lookup-missing", records=n))
    for hole in range(PAIRS):
        items = records(PAIRS); items[hole] = bytes(RECORD_BYTES)
        db = Database(pe, HEADER + b"".join(items))
        put(db.vm, address, missing)
        assert db.call(0x7a4d0, address, 0) == hole
        checks.append(dict(kind="native-find-first-empty", index=hole))
    for routine in (0x7a4d0, 0x7a63c, 0x7a738, 0x7ab4c):
        for fault in ("header_read_bool", "bulk_open_fail", "seek_fail"):
            db = Database(pe, HEADER + payload)
            setattr(db, fault, False if fault == "header_read_bool" else True)
            put(db.vm, address, records(1)[0])
            before = bytes(db.contents)
            second = 0 if routine == 0x7a4d0 else destination if routine == 0x7a63c else address
            result = db.call(routine, address, second)
            if routine == 0x7a4d0: assert result == 0xffffffff
            if routine in (0x7a63c, 0x7a738): assert result == 0
            assert bytes(db.contents) == before and not any(e["kind"] == "write" for e in db.events)
            checks.append(dict(kind="native-record-path-header-open-seek-failure", routine=hex(routine), fault=fault, no_write=True))
    # A hole is only usable after a complete scan; a truncated tail cannot be EOF.
    for tail in (1, 103):
        for routine in (0x7a4d0, 0x7a738):
            db = Database(pe, HEADER + bytes(RECORD_BYTES) + payload[:RECORD_BYTES + tail])
            put(db.vm, address, missing + bytes(RECORD_BYTES - 8))
            before = bytes(db.contents)
            result = db.call(routine, address, 0 if routine == 0x7a4d0 else address)
            assert result == (0xffffffff if routine == 0x7a4d0 else 0)
            assert bytes(db.contents) == before and not any(e["kind"] == "write" for e in db.events)
            checks.append(dict(kind="native-hole-scan-rejects-truncated-tail", routine=hex(routine), tail=tail, no_write=True))
    for ok, reported in ((False, 0), (False, 104), (True, 1), (True, 103), (True, 105)):
        for routine in (0x7a4d0, 0x7a63c, 0x7a738, 0x7ab4c):
            db = Database(pe, HEADER + payload)
            db.read_overrides[104] = (ok, reported)
            put(db.vm, address, records(PAIRS)[0])
            before = bytes(db.contents)
            result = db.call(routine, address, destination if routine == 0x7a63c else address)
            if routine == 0x7a4d0: assert result == 0xffffffff
            if routine in (0x7a63c, 0x7a738): assert result == 0
            assert bytes(db.contents) == before and not any(e["kind"] == "write" for e in db.events)
            checks.append(dict(kind="record-path-rejects-scan-error", routine=hex(routine),
                               api_bool=ok, reported=reported, no_write=True))
    # Writer input deliberately aliases address and whole record, as CSR callers do.
    replacement = bytearray(records(1)[0]); replacement[8:] = bytes([0x69]) * (RECORD_BYTES - 8)
    for index in range(PAIRS):
        item = bytearray(replacement); item[:8] = records(PAIRS)[index][:8]
        db = Database(pe, HEADER + payload)
        put(db.vm, address, item)
        assert db.call(0x7a738, address, address) == 1
        expected = bytearray(HEADER + payload)
        expected[4 + index * RECORD_BYTES:4 + (index + 1) * RECORD_BYTES] = item
        assert bytes(db.contents) == bytes(expected)
        writes = [e for e in db.events if e["kind"] == "write"]
        assert len(writes) == 1 and writes[0]["position"] == 4 + index * RECORD_BYTES and writes[0]["requested"] == 104
        checks.append(dict(kind="native-record-update", index=index, aliased_input=True, exact_payload=True))
    new_item = bytearray(replacement); new_item[:8] = missing
    for n in range(PAIRS + 1):
        for cold in (False, True) if n == 0 else (False,):
            original = b"" if cold else HEADER + payload[:n * RECORD_BYTES]
            db = Database(pe, original)
            put(db.vm, address, new_item)
            assert db.call(0x7a738, address, address) == int(n < PAIRS)
            expected = HEADER + payload[:n * RECORD_BYTES] + (bytes(new_item) if n < PAIRS else b"")
            assert bytes(db.contents) == expected
            if n == PAIRS: assert not any(e["kind"] == "write" for e in db.events)
            checks.append(dict(kind="native-record-append-capacity", records=n, cold_database=cold,
                               accepted=n < PAIRS, exact_payload=True))
    for hole in range(PAIRS):
        items = records(PAIRS); items[hole] = bytes(RECORD_BYTES)
        db = Database(pe, HEADER + b"".join(items)); put(db.vm, address, new_item)
        assert db.call(0x7a738, address, address) == 1
        items[hole] = bytes(new_item)
        assert bytes(db.contents) == HEADER + b"".join(items)
        checks.append(dict(kind="native-record-reuse-hole", index=hole, exact_payload=True))
    for ok in (False, True):
        for reported in (0, 1, 103, 104, 105, 0xffffffff):
            db = Database(pe, HEADER + payload); put(db.vm, address, replacement)
            db.write_bool, db.write_reported = ok, reported
            assert db.call(0x7a738, address, address) == int(ok and reported == 104)
            checks.append(dict(kind="native-record-write-status", api_bool=ok, reported=reported,
                               accepted=ok and reported == 104, rollback_proven=False))
    # Higher deletion now scans, reads, compacts and writes once, without pre-zeroing.
    for n in range(1, PAIRS + 1):
        for index in range(n):
            db = Database(pe, HEADER + payload[:n * RECORD_BYTES])
            put(db.vm, address, records(n)[index][:8])
            db.call(0x7ab4c, address)
            items = records(n); del items[index]
            items += [bytes(RECORD_BYTES)] * (PAIRS - len(items))
            assert bytes(db.contents) == HEADER + b"".join(items)
            writes = [e for e in db.events if e["kind"] == "write"]
            assert len(writes) == 1 and writes[0]["position"] == 4 and writes[0]["requested"] == 832
            checks.append(dict(kind="native-higher-delete-single-write", records=n, index=index, exact_payload=True))
    for ok, reported in ((False, 0), (False, 832), (True, 1), (True, 831), (True, 833)):
        db = Database(pe, HEADER + payload); put(db.vm, address, records(1)[0][:8])
        db.read_overrides[832] = (ok, reported)
        before = bytes(db.contents); db.call(0x7ab4c, address)
        assert bytes(db.contents) == before and not any(e["kind"] == "write" for e in db.events)
        checks.append(dict(kind="native-higher-delete-bulk-failure", api_bool=ok, reported=reported, no_write=True))
    db = Database(pe, HEADER + payload); put(db.vm, address, missing)
    before = bytes(db.contents); db.call(0x7ab4c, address)
    assert bytes(db.contents) == before and not any(e["kind"] == "write" for e in db.events)
    checks.append(dict(kind="native-higher-delete-missing", no_write=True))
    for n, ok, reported in ((0, True, 104), (5, True, 104), (5, False, 104),
                            (5, True, 1), (8, True, 104)):
        checks.append(csr_caller_case(pe, n, ok, reported))
    out = ROOT / "analysis/firmware/bt-database-io-draft"
    out.mkdir(parents=True, exist_ok=True)
    dependencies = ["verify_bt_database_io.py", "draft_bt_database_io.py", "draft_bt_pairing_storage.py",
        "verify_bt_pairing_storage.py", "inspect_bt_pairing.py", "inspect_bt_playback.py",
        "inspect_wave_queue.py", "inspect_bt_lifecycle.py", "patch_bt_playback.py"]
    # Preserve direct caller locations as navigation, without claiming those
    # whole routines or indirect call paths have been validated.
    caller_index = json.loads((ROOT / "analysis/functions/705md/Blue.exe.json").read_text(encoding="utf-8"))["functions"]
    targets = {0x860ac, 0x860f8, 0x7a738, 0x7ab4c, 0x7a63c, 0x7a4d0, 0x7a974}
    edges = []
    original_pe = pefile.PE(data=raw)
    for line in (ROOT / "analysis/disassembly/Blue.exe.asm").read_text(encoding="utf-8").splitlines():
        match = re.match(r"([0-9a-f]{8})\s+jal\s+0x([0-9a-f]+)", line)
        if not match or int(match[2], 16) not in targets: continue
        va, target = int(match[1], 16), int(match[2], 16)
        word = int.from_bytes(original_pe.get_data(va - original_pe.OPTIONAL_HEADER.ImageBase, 4), "little")
        assert word >> 26 == 3 and ((word & 0x3ffffff) << 2) == target
        owner = next((f["begin_va"] for f in caller_index if int(f["begin_va"], 16) <= va < int(f["end_va"], 16)), None)
        edges.append(dict(va=hex(va), target=hex(target), caller=owner, scope="Original direct JAL; caller status propagation not proved"))
    assert {e["caller"] for e in edges if e["target"] == "0x7a974"} == {"0x3307c", "0x7aa40"}
    table_va = 0x10e480
    table = original_pe.get_data(table_va - original_pe.OPTIONAL_HEADER.ImageBase, 4 * 0x12 * 4)
    sd_receivers = [struct.unpack_from("<I", table, (state * 0x12 + 0x11) * 4)[0] for state in range(4)]
    assert sd_receivers == [0xbdaa0] * 4
    result = dict(status="coupled database-I/O draft checks passed; no unit test or complete update",
        native_execution=False, executable_written=False, build_allowed=False,
        sources=src, patch_sha256=patch["draft_sha256"], checks=checks, original_direct_caller_edges=edges,
        sd_registration_dispatch=dict(table_va=hex(table_va), original_hex=table.hex(),
            sha256=hashlib.sha256(table).hexdigest(), type="0x11", class_id="0x11e",
            receiver_task="CSR_BT_SD", receiver_by_state=[hex(a) for a in sd_receivers],
            scope="Pinned original table plus registration/dispatch source; receiver not interpreted"),
        limitations=["Partial writes may mutate the live-file prefix; atomic replacement/recovery not implemented",
            "File-open/seek/close and ReadFile/WriteFile are explicit in-memory API fixtures",
            "Cold database initialization retains original magic-helper behavior; atomic header creation not implemented",
            "Record writer returns persistence status, but existing callers ignore it; higher deletion remains void",
            "Original SC caller enqueues SD device registration before writing; full asynchronous radio/GUI flow not interpreted",
            "Name-cache aliases, full UI/connection state paths and physical unit remain open"],
        dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], checks=len(checks), direct_caller_edges=len(edges),
                         report=str(out / "contracts.json")), indent=2))


if __name__ == "__main__":
    main()
