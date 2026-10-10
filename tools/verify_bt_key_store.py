"""SC host key persistence, cold-fixture responses and native cursor faults.

Actual MIPS database/SC construction/queue adapters are interpreted. File APIs,
allocator/string calls and scheduler boundary remain explicit fixtures. Keys
are synthetic; no live secrets, native execution, executable or LGU output.
"""
import hashlib
import json
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import abi, put, data
from verify_bt_database_io import Database, HEADER
from verify_bt_pairing_ui import UIVM
from draft_bt_list_ack import blue_ack
from draft_bt_key_iterator import blue_key_iterator

CONTEXT, REQUEST, INPUT = 0x46000000, 0x47000000, 0x48000000
CURSOR, CM_QUEUE, SD_QUEUE, DEST = 0x20e304, 0x21862e, 0x218648, 0x323
EXTRA = [(0xbb80c, 0xbbd68), (0x7a7f8, 0x7a8a8), (0x7ac28, 0x7acb0), (0xc2810, 0xc2858),
         (0xc2638, 0xc26cc), (0xc3bbc, 0xc3d30), (0xc5c48, 0xc5cec),
         (0xc2604, 0xc2638), (0x857bc, 0x85818), (0xcd000, 0xcd07c),
         (0xcd07c, 0xcd0a4), (0xcd0a4, 0xcd0cc), (0x782a8, 0x782d0),
         (0xcd1f8, 0xcd218)]


class Witness(Exception):
    def __init__(self, event): self.event = event


class KeyVM(UIVM):
    def __init__(self, pe, ranges):
        super().__init__(pe, ranges); self.native_access = False
    def read(self, at, size=4):
        if self.native_access and at < 0x10000:
            raise Witness(dict(kind="low-read", address=hex(at), pc=hex(self.pc), bytes=size))
        return super().read(at, size)
    def write(self, at, value, size=4):
        if self.native_access and at < 0x10000:
            raise Witness(dict(kind="low-write", address=hex(at), pc=hex(self.pc), bytes=size))
        super().write(at, value, size)


def records(n):
    values = []
    for i in range(n):
        raw = bytearray(104)
        raw[:4] = (0x112200 + i).to_bytes(4, "little")
        raw[4] = 0x40 + i; raw[6:8] = (0x1200 + i).to_bytes(2, "little")
        raw[8:10] = b"\x01\x10"
        raw[10:26] = bytes((3 + i * 29 + j * 7) & 255 for j in range(16))
        name = f"Synthetic{i + 1}".encode(); raw[26:26 + len(name)] = name
        for j in range(5): raw[0x50 + j * 4:0x54 + j * 4] = (0xabcdef00 + i * 16 + j).to_bytes(4, "little")
        raw[0x64:0x66] = bytes([1, i % 6])
        values.append(bytes(raw))
    return values


class Keys(Database):
    def __init__(self, pe, contents):
        super().__init__(pe, contents)
        old = self.vm; self.vm = KeyVM(pe, [*old.ranges, *EXTRA])
        self.vm.mem, self.vm.hooks = old.mem, old.hooks
        self.allocations, self.enqueued, self.iter_reads = [], [], 0
        self.faults = {}; self.allocation_failure = None
        self.vm.write(CM_QUEUE, DEST, 2); self.vm.write(SD_QUEUE, DEST, 2)
        self.vm.write(CURSOR, 0)  # Explicit zero-initialized loader fixture.
        put(self.vm, 0xbb84c, pe.get_data(0xbb84c - pe.OPTIONAL_HEADER.ImageBase, 68))
        self.vm.hooks.update({0x85b70: self.allocate, 0x835b8: self.copy_name,
                             0x83540: self.trim_name, 0x84ec8: self.enqueue,
                             0x8ac04: self.memcpy})
    def allocate(self, vm):
        n = vm.reg[4]; index = len(self.allocations)
        at = 0 if index == self.allocation_failure else 0x60000000 + index * 0x10000
        self.allocations.append(dict(pointer=hex(at), bytes=n))
        if at: put(vm, at, bytes([0xa5]) * n)
        return at
    def copy_name(self, vm):
        at, origin, n = vm.reg[4:7]
        assert n == 51
        put(vm, at, data(vm, origin, n)); return at
    def trim_name(self, vm):
        assert vm.reg[5] == 50
        vm.write(vm.reg[4] + 50, 0, 1); return 0
    def enqueue(self, vm):
        destination, cls, pointer = vm.reg[4:7]
        assert destination == DEST and cls in (0x102, 0x104, 0x11e)
        prim = vm.read(pointer, 2)
        length = {0x205: 24, 0x8007: 20, 0x8008: 24, 0x11: 36}[prim]
        entry = dict(destination=destination, class_id=hex(cls), primitive=hex(prim),
                     payload_hex=data(vm, pointer, length).hex())
        if prim == 0x205:
            n = vm.read(pointer + 0xd, 1); key = vm.read(pointer + 0x10)
            entry.update(key_type=vm.read(pointer + 0xc, 1), key_bytes=n,
                         synthetic_key_hex=data(vm, key, n).hex() if n else None,
                         key_pointer=hex(key))
        elif prim in (0x8007, 0x8008):
            count_at, pointer_at = (4, 8) if prim == 0x8007 else (8, 12)
            count, array = vm.read(pointer + count_at), vm.read(pointer + pointer_at)
            entry.update(count=count, records_hex=data(vm, array, count * 84).hex() if count else "")
            if prim == 0x8008: entry["total"] = vm.read(pointer + 4)
        self.enqueued.append(entry); return 0
    def read(self, vm):
        handle = vm.reg[4]
        if handle not in self.handles:
            raise Witness(dict(kind="invalid-handle-read", handle=hex(handle), pc=hex(vm.pc)))
        request = vm.reg[6]
        old = self.read_overrides.get(104)
        if request == 104:
            fault = self.faults.get(self.iter_reads); self.iter_reads += 1
            if fault is not None: self.read_overrides[104] = fault
        try: return super().read(vm)
        finally:
            if old is None: self.read_overrides.pop(104, None)
            else: self.read_overrides[104] = old
    def call(self, address, arg=CONTEXT, second=0):
        self.vm.reg[5] = second; self.vm.native_access = True
        try: abi(self.vm, address, arg)
        finally: self.vm.native_access = False
        return self.vm.reg[2]


def persist_eight(pe):
    f = Keys(pe, HEADER); steps = []
    for i, rec in enumerate(records(9)):
        vm = f.vm; put(vm, CONTEXT, bytes(0x124))
        put(vm, CONTEXT + 0x44, rec[:8]); put(vm, CONTEXT + 0x110, rec[10:26])
        put(vm, CONTEXT + 0x4d, rec[26:77]); vm.write(CONTEXT + 0x40, int.from_bytes(rec[0x50:0x54], "little"))
        vm.write(CONTEXT + 0x81, rec[0x64], 1); vm.write(CONTEXT + 0x120, rec[0x65], 1)
        before = bytes(f.contents); event_start = len(f.events); queue_start = len(f.enqueued)
        f.call(0xc26cc)
        new = bytes(f.contents)
        if i < 8:
            assert len(new) == 4 + (i + 1) * 104
            saved = new[4 + i * 104:4 + (i + 1) * 104]
            assert saved[:26] == rec[:26] and saved[26:77] == rec[26:77]
            assert saved[0x50:0x54] == rec[0x50:0x54] and saved[0x64:0x66] == rec[0x64:0x66]
        else: assert new == before and not any(e["kind"] == "write" for e in f.events[event_start:])
        assert len(f.enqueued) - queue_start == 1 and not f.handles
        steps.append(dict(index=i, persisted=i < 8, queued_sd_registration=True,
                          file_events=f.events[event_start:], payload_sha256=hashlib.sha256(new).hexdigest()))
    return bytes(f.contents), steps


def key_response(pe, contents, index, policy=0, read_fault=None, legacy_read=False):
    f = Keys(pe, contents); raw_records = [contents[i:i + 104] for i in range(4, len(contents), 104)]
    target = raw_records[index] if index < len(raw_records) else records(index + 1)[index]
    put(f.vm, REQUEST, bytes(20)); put(f.vm, REQUEST + 4, target[:8])
    f.vm.write(REQUEST + 0x10, policy, 1); f.vm.write(CONTEXT + 0x1c, REQUEST)
    if read_fault: f.faults[0] = read_fault
    f.call(0xc5c48)
    assert len(f.enqueued) == 1 and not f.handles
    response = f.enqueued[0]
    read_ok = read_fault is None or read_fault[1] == 104 and (read_fault[0] or legacy_read)
    found = index < len(raw_records) and read_ok
    accepted = found and (policy == 0 or policy == 1 and target[0x65] == 5)
    assert response["primitive"] == "0x205" and response["class_id"] == "0x104"
    assert bytes.fromhex(response["payload_hex"])[4:12] == target[:8]
    assert response["key_bytes"] == (16 if accepted else 0)
    assert response["key_type"] == (target[0x65] if accepted else 0xfe)
    assert response["synthetic_key_hex"] == (target[10:26].hex() if accepted else None)
    return dict(index=index, policy=policy, accepted=accepted, read_fault=read_fault, legacy_read=legacy_read, response=response,
                file_events=f.events, abi_preserved=True, cold_fixture=True,
                scope="Fresh VM/file snapshot, native SC lookup/key response/CM queue adapter, no hardware restart or CM receiver")


def enumeration(pe, count, request_bytes, sparse=False, fault=None, fail_allocation=None):
    recs = records(count)
    if sparse:
        special = bytearray(104); special[:4] = (0xffffff).to_bytes(4, "little")
        special[4] = 0xff; special[6:8] = b"\xff\xff"
        recs = [bytes(104), bytes(special), *[item for rec in recs for item in (rec, bytes(104))]]
    f = Keys(pe, HEADER + b"".join(recs)); f.allocation_failure = fail_allocation
    f.vm.write(CONTEXT + 0x1c, REQUEST); f.vm.write(REQUEST + 2, DEST, 2)
    f.vm.write(REQUEST, 0xa, 2)
    f.vm.write(REQUEST + 4, request_bytes)
    if fault: f.faults[fault[0]] = fault[1:]
    witness = None
    try: f.call(0xbb80c)
    except Witness as error: witness = error.event
    packets = f.enqueued
    if fault is None and fail_allocation is None:
        assert witness is None and not f.handles and f.vm.read(CURSOR) == 0
        assert packets[-1]["primitive"] == "0x8008" and packets[-1]["total"] == count
        batch = max(1, request_bytes // 84)
        assert len(packets) == count // batch + 1
        assert [p["count"] for p in packets] == [batch] * (count // batch) + [count % batch]
        flattened = b"".join(bytes.fromhex(p["records_hex"]) for p in packets)
        for i, rec in enumerate(records(count)):
            output = flattened[i * 84:(i + 1) * 84]
            assert output[:8] == rec[:8] and output[8:59] == rec[26:77]
            assert output[60:80] == rec[0x50:0x64] and output[80] == rec[0x64]
    return dict(count=count, requested_bytes=request_bytes, sparse=sparse, fault=fault,
                allocations=f.allocations, allocation_failure=fail_allocation, packets=packets,
                witness=witness, file_events=f.events, cursor=hex(f.vm.read(CURSOR)),
                open_handles=list(f.handles), abi_preserved=witness is None,
                scope="Native iterator/metadata conversion/chunk message; allocator/name/file/scheduler APIs are fixtures; 84-byte metadata is not link-key export")


def cursor_case(pe, mode, repaired=False):
    f = Keys(pe, HEADER + b"".join(records(1 if mode in ("seek", "restart") else 0)))
    if mode == "seek": f.seek_fail = True
    if mode == "open": f.bulk_open_fail = True
    if mode == "header": f.header_read_bool = False
    first = f.call(0x7ac28, INPUT); before = len(f.events); witness = None; followup = None
    first_handles, first_cursor = list(f.handles), hex(f.vm.read(CURSOR))
    try:
        followup = f.call(0x7ac28, INPUT) if mode == "restart" else f.call(0xc2810, CONTEXT)
    except Witness as error: witness = error.event
    if mode == "seek": assert len(first_handles) == int(not repaired) and first == 0
    if mode == "restart": assert len(f.handles) == (1 if repaired else 2)
    return dict(mode=mode, first_return=first, followup_return=followup, witness=witness,
                file_events=f.events, followup_events=f.events[before:], first_cursor=first_cursor,
                first_open_handles=first_handles, cursor=hex(f.vm.read(CURSOR)),
                open_handles=list(f.handles), finding=("Failed seek closed; restart drained old handle" if repaired else
                "Seek failure leaves cursor open until follow-up drain; restart loses previous handle") if mode in ("seek", "restart") else
                "Zero/invalid cursor follow-up", abi_preserved=witness is None)


def restart_case(pe, count, consumed, fault=None):
    f = Keys(pe, HEADER + b"".join(records(count)))
    assert f.call(0x7ac28, INPUT) == 1
    for _ in range(consumed - 1): assert f.call(0x7a7f8, INPUT) == 1
    old_handles = list(f.handles); assert len(old_handles) == 1
    if fault is not None: f.faults[f.iter_reads] = fault
    assert f.call(0x7ac28, INPUT) == 1
    assert data(f.vm, INPUT, 104) == records(1)[0]
    assert len(f.handles) == 1 and all(handle not in f.handles for handle in old_handles)
    events_before_cleanup = list(f.events)
    f.call(0xc2810); assert not f.handles and f.vm.read(CURSOR) == 0
    before = len(f.events); f.call(0xc2810); assert len(f.events) == before
    return dict(count=count, consumed=consumed, drain_read_fault=fault,
                old_handles=old_handles, events_before_cleanup=events_before_cleanup,
                final_cursor=0, open_handles=[], first_record_restored=True, repeated_cleanup_no_io=True, abi_preserved=True)


def ignored_enumeration_response(pe, primitive, receiver_present):
    vm = KeyVM(pe, [(0x2320c, 0x235ec)])
    table = pe.get_data(0x2325c - pe.OPTIONAL_HEADER.ImageBase, 52)
    put(vm, 0x2325c, table); put(vm, REQUEST, bytes([0xa5]) * 24)
    vm.write(REQUEST, primitive, 2)
    before = data(vm, REQUEST, 24)
    target = 0x2325c + int.from_bytes(table[(primitive - 0x8000) * 2:(primitive - 0x8000 + 1) * 2], "little", signed=True)
    assert target == 0x235d4
    vm.reg[5:7] = [int(receiver_present), REQUEST]; vm.native_access = True
    try: abi(vm, 0x2320c, CONTEXT)
    finally: vm.native_access = False
    assert data(vm, REQUEST, 24) == before and not vm.hooks
    return dict(primitive=hex(primitive), receiver_present=receiver_present, jump_target=hex(target),
                api_calls=0, payload_unchanged=True, abi_preserved=True,
                scope="Original SC apphandler table/epilogue executes; cases ignore these responses, no scheduler delivery proof")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    raw = (ROOT / module["path"]).read_bytes(); ack, ack_patch = blue_ack(raw)
    candidate, patch = blue_key_iterator(raw)
    variants = {"original": pefile.PE(data=raw), "ack": pefile.PE(data=ack), "iterator": pefile.PE(data=candidate)}
    saved, persistence = persist_eight(variants["iterator"])
    cold = [dict(variant=label, trace=key_response(pe, saved, i)) for label, pe in variants.items() for i in range(9)]
    policy = [key_response(variants["iterator"], HEADER + b"".join(records(8)), i, mode)
              for i in range(8) for mode in (0, 1, 2, 0xff)]
    bad_reads = [key_response(variants["iterator"], saved, i, read_fault=fault) for i in (0, 7)
                 for fault in ((False, 104), (False, 0), (True, 103), (True, 105))]
    key_fault_pairs = [dict(before=key_response(variants["original"], saved, i, read_fault=(False, 104), legacy_read=True),
                           repaired=key_response(variants["iterator"], saved, i, read_fault=(False, 104))) for i in range(8)]
    larger_host = [dict(variant=label, count=n, trace=key_response(pe, HEADER + b"".join(records(n)), n - 1))
                   for label, pe in variants.items() for n in (9, 16)]
    enumerated = [dict(variant=label, trace=enumeration(pe, n, request_bytes, sparse))
                  for label, pe in variants.items() for n in (0, 1, 5, 8, 9, 16)
                  for request_bytes in (0, 83, 84, 168, 672, 756) for sparse in (False, True)]
    faults = []
    for failure_at in (0, 3, 7):
        for ok, n in ((False, 104), (False, 0), (True, 103), (True, 105)):
            before = enumeration(variants["ack"], 8, 168, fault=(failure_at, ok, n))
            repaired = enumeration(variants["iterator"], 8, 168, fault=(failure_at, ok, n))
            assert repaired["witness"] is None and not repaired["open_handles"] and repaired["cursor"] == "0x0"
            assert repaired["packets"][-1]["total"] == failure_at
            assert before["packets"][-1]["total"] == (8 if not ok and n == 104 else failure_at)
            faults.append(dict(before=before, repaired=repaired))
    cursor = [dict(variant=label, trace=cursor_case(pe, mode, label == "iterator")) for label, pe in variants.items()
              for mode in ("empty", "open", "header", "seek", "restart")]
    for pair in cursor:
        t = pair["trace"]
        if pair["variant"] == "iterator" and t["mode"] in ("empty", "open", "header"):
            assert t["witness"] is None and not t["open_handles"] and not t["followup_events"]
        elif pair["variant"] == "ack" and t["mode"] in ("empty", "header"):
            assert t["witness"] and t["witness"]["kind"] == "invalid-handle-read"
    restarts = [restart_case(variants["iterator"], n, consumed, fault) for n in (1, 5, 8)
                for consumed in (1, n) for fault in (None, (False, 104), (False, 0), (True, 103))]
    ignored = [dict(variant=label, trace=ignored_enumeration_response(pe, prim, receiver))
               for label, pe in variants.items() for prim in (0x8007, 0x8008) for receiver in (False, True)]
    alloc_failure = enumeration(variants["iterator"], 1, 84, fail_allocation=1)
    assert alloc_failure["witness"] == dict(kind="low-write", address="0x0", pc="0xc3c9c", bytes=2)
    # Native key policy accepts a matched record with marker/length zero; no new
    # interpretation of these fields is imposed without following all writers.
    empty_key = bytearray(records(1)[0]); empty_key[8:10] = b"\0\0"; empty_key[10:26] = bytes(16)
    marker = key_response(variants["iterator"], HEADER + empty_key, 0)
    assert marker["accepted"] and marker["response"]["synthetic_key_hex"] == bytes(16).hex()
    addresses = list(dict.fromkeys([a for a, _ in EXTRA] + [0x7a3d8, 0x7a63c, 0x7a738, 0xc26cc, 0x7998c, 0xbb80c, 0xbbd68, 0x85f84, 0x2320c]))
    sources, original = source(module, addresses, {0xc2604: 0x34})
    # Native primitive-to-handler route: SC type a is the enumeration caller.
    table = original.get_data(0xbb84c - original.OPTIONAL_HEADER.ImageBase, 68)
    assert 0xbb84c + int.from_bytes(table[20:22], "little", signed=True) == 0xbbbc4
    cursor_rva = CURSOR - original.OPTIONAL_HEADER.ImageBase
    cursor_section = next(s for s in original.sections if s.VirtualAddress <= cursor_rva < s.VirtualAddress + s.Misc_VirtualSize)
    assert cursor_rva - cursor_section.VirtualAddress >= cursor_section.SizeOfRawData
    assert original.get_data(cursor_rva, 4) == b""
    cursor_storage = dict(va=hex(CURSOR), section=cursor_section.Name.rstrip(b"\0").decode(),
                          rva=hex(cursor_rva), virtual_bytes=cursor_section.Misc_VirtualSize,
                          raw_bytes=cursor_section.SizeOfRawData, file_bytes_present=False,
                          initial_fixture_value=0, scope="Virtual .data tail; zero initialization is an explicit loader fixture, not four source-file bytes")
    deps = ["verify_bt_key_store.py", "draft_bt_key_iterator.py", "draft_bt_list_ack.py", "verify_bt_database_io.py",
            "verify_bt_pairing_storage.py", "verify_bt_pairing_ui.py", "draft_bt_pairing_storage.py", "draft_bt_database_io.py",
            "patch_bt_playback.py", "inspect_bt_pairing.py", "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Native SC host-key persistence/response and chunk enumeration traced; separate iterator BOOL/cursor repair",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  sources=sources, ack_patch=ack_patch, iterator_patch=patch, persistence_cases=persistence,
                  cold_key_cases=cold, key_policy_cases=policy, key_read_fault_cases=bad_reads,
                  key_read_fault_pairs=key_fault_pairs, larger_host_lookup_cases=larger_host,
                  enumeration_cases=enumerated, iterator_read_fault_pairs=faults, cursor_cases=cursor,
                  restart_cleanup_cases=restarts, cursor_storage=cursor_storage,
                  ignored_app_response_cases=ignored,
                  enumeration_allocation_failure=alloc_failure, key_marker_counterexample=marker,
                  sc_enumeration_route=dict(type="0xa", table_va="0xbb84c", table_hex=table.hex(), receiver="0xc3bbc"),
                  limitations=["Cold fixture uses saved file bytes in fresh VM; no hardware boot, radio authentication or controller-capacity proof",
                               "Scheduler/CM receiver, allocator/string and file APIs are hooks; send adapter and message constructors are native",
                               "SC key policy tests type field; matched record marker/key-length are not validated by this handler",
                               "Enumeration still conflates read failure with clean EOF and emits normal partial total; complete error propagation open",
                               "Restart drains global iterator serially; concurrent cursor owners, ReadFile blocking and cancellation/lifetime remain open",
                               "Enumerator message/data allocation failure is unchecked; native low-store witness retained",
                               "SC caller registers with SD before persistence and does not report ninth/refused write; atomic recovery remains open",
                               "Separate iterator prototype not merged with prior base/ACK, App safe-copy or MAX02; LGU build disabled"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps})
    out = ROOT / "analysis/firmware/bt-key-store"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], persisted=sum(c["persisted"] for c in persistence),
                         cold_keys=len(cold), key_policy=len(policy), key_read_faults=len(bad_reads),
                         enumeration=len(enumerated), read_fault_pairs=len(faults), cursor=len(cursor),
                         restart_cleanup=len(restarts), key_read_fault_pairs=len(key_fault_pairs), larger_host=len(larger_host),
                         ignored_app_responses=len(ignored),
                         blue_sha256=patch["draft_sha256"]), indent=2))


if __name__ == "__main__": main()
