"""Interpret SC -> CM -> DM -> serialized HCI key replies from original bytes.

File APIs, scheduler delivery, heap primitives and diagnostic logging are fixtures.
No firmware executes natively and no executable/LGU is emitted. Keys are synthetic.
"""
from collections import Counter
import hashlib
import json
import pefile

from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import abi, put, data
from verify_bt_key_store import Keys, KeyVM, Witness, records, CONTEXT, REQUEST, CM_QUEUE
from verify_bt_database_io import HEADER
from draft_bt_key_iterator import blue_key_iterator

HOLDER, CM = 0x50000000, 0x51000000
HCI_HOLDER, HCI_CONTEXT, TRANSPORT, TX_API = 0x52000000, 0x53000000, 0x55000000, 0xf0070010
DM_QUEUE, HCI_QUEUE = 0x218642, 0x218654
CM_ID, DM_ID, HCI_ID = 0x323, 0x324, 0x325  # Explicit unique scheduler fixture IDs.
CACHE, COMMANDS, ACL, SECURITY = 0x2172bc, 0x217224, 0x2172a0, 0x217284
FUNCTIONS = [0x8a230, 0x8a470, 0xbcf14, 0xca440, 0xce478, 0xefd2c, 0xf26d4,
             0x85758, 0x91bd4, 0x91acc, 0xac9a4, 0xbd738, 0xbd6e0,
             0xb4ee0, 0xb4728, 0xb46bc, 0xb852c, 0xb4910, 0xb47c8,
             0xb4e10, 0xb4a2c, 0xab4b4, 0xab5a0, 0xafdfc, 0xafd60,
             0x911a4, 0x9040c, 0x8f804, 0x91820, 0xb443c, 0xe98ac, 0x8ac24,
             0xe96f4, 0xe91ec, 0xe8b9c, 0x833e4, 0xe887c, 0x82a50, 0x82b44, 0xe88b0]
LEAVES = {0xb726c: 0x18, 0xa3704: 0x1c, 0x9ad38: 0x2c, 0x9ad64: 0x34,
          0xb4594: 0x118, 0xba49c: 0x80, 0xba670: 0x50}
TABLES = {0x10e87c: 0x118, 0x10d4b4: 0x40, 0x10d7f8: 84 * 8, 0x10dbf0: 0x38,
          0x10efb8: 88}


class StackVM(KeyVM):
    def __init__(self, pe, ranges):
        super().__init__(pe, ranges)
        self.freed = {}; self.entries = Counter()
        self.begins = {a for a, _ in ranges}
    def word(self, pc):
        if pc in self.begins: self.entries[hex(pc)] += 1
        return super().word(pc)
    def read(self, at, size=4):
        if self.native_access and any(at < p + n and at + size > p for p, n in self.freed.items()):
            raise Witness(dict(kind="freed-read", address=hex(at), pc=hex(self.pc), bytes=size))
        return super().read(at, size)
    def write(self, at, value, size=4):
        if self.native_access and any(at < p + n and at + size > p for p, n in self.freed.items()):
            raise Witness(dict(kind="freed-write", address=hex(at), pc=hex(self.pc), bytes=size))
        super().write(at, value, size)


class Stack(Keys):
    def __init__(self, pe, contents, ranges, mode=4, flags=0, fail=None, credits=1):
        super().__init__(pe, contents)
        old = self.vm; self.vm = StackVM(pe, [*old.ranges, *ranges])
        self.vm.mem, self.vm.hooks = old.mem, old.hooks
        self.queue = []; self.packets = []; self.frees = []; self.delivered = []; self.transmitted = []
        self.allocation_failure = fail
        vm = self.vm
        vm.write(CM_QUEUE, CM_ID, 2); vm.write(DM_QUEUE, DM_ID, 2); vm.write(HCI_QUEUE, HCI_ID, 2)
        vm.write(HOLDER, CM); put(vm, CM, bytes(0x5b8))
        vm.write(CACHE, 0); put(vm, COMMANDS, bytes(12)); vm.write(ACL, 0)
        vm.write(SECURITY, flags, 2); vm.write(SECURITY + 2, mode, 1)
        vm.write(0x110eac, credits, 2); vm.write(0x110ea4, 0x4321)
        vm.write(HCI_HOLDER, HCI_CONTEXT); put(vm, HCI_CONTEXT, bytes(0x20))
        vm.write(0x2172b4, TRANSPORT); vm.write(TRANSPORT + 0xc, TX_API)
        for at, n in TABLES.items(): put(vm, at, pe.get_data(at - pe.OPTIONAL_HEADER.ImageBase, n))
        vm.hooks.update({0x84ec8: self.enqueue, 0x84ee8: self.receive,
                         0x85bb8: self.free, 0x8ac04: self.copy_checked,
                         0x3a750: self.zero_checked, 0xa2190: self.log, TX_API: self.transmit})
        # These wrappers/checks now execute their original bytes instead of inherited hooks.
        for at in (0x85758, 0x8ac24): vm.hooks.pop(at, None)
    def copy_checked(self, vm):
        at, origin, n = vm.reg[4:7]
        if not at and n: raise Witness(dict(kind="API-null-copy", pc=hex(vm.pc), bytes=n))
        return self.memcpy(vm)
    def zero_checked(self, vm):
        if not vm.reg[4] and vm.reg[6]:
            raise Witness(dict(kind="API-null-memset", pc=hex(vm.pc), bytes=vm.reg[6]))
        return self.memset(vm)
    def log(self, vm):
        assert vm.reg[4] == 0x10d788 and vm.reg[5] == 0x101
        return 0
    def free(self, vm):
        at = vm.reg[4]
        if not at: self.frees.append(dict(pointer="0x0", bytes=0)); return 0
        allocation = next((a for a in self.allocations if int(a["pointer"], 16) == at), None)
        assert allocation is not None and at not in vm.freed, (hex(at), "invalid/double free")
        self.frees.append(dict(pointer=hex(at), bytes=allocation["bytes"]))
        vm.freed[at] = allocation["bytes"]
        return 0
    def enqueue(self, vm):
        destination, cls, pointer = vm.reg[4:7]
        assert (destination, cls) in ((CM_ID, 0x104), (DM_ID, 4), (HCI_ID, 0x600))
        if destination == HCI_ID and pointer == 0:
            entry = dict(destination=destination, class_id=hex(cls), primitive=None, pointer="0x0", wake=True)
            self.queue.append(entry); self.enqueued.append(entry)
            return 0
        primitive = vm.read(pointer, 2)
        assert primitive == {(CM_ID, 0x104): 0x205, (DM_ID, 4): 0x388, (HCI_ID, 0x600): 7}[destination, cls]
        entry = dict(destination=destination, class_id=hex(cls), primitive=hex(primitive), pointer=hex(pointer))
        if primitive in (0x205, 0x388):
            entry["payload_hex"] = data(vm, pointer, 24 if primitive == 0x205 else 28).hex()
            key = vm.read(pointer + (0x10 if primitive == 0x205 else 0x18))
            entry["key_pointer"] = hex(key)
            entry["key_payload_hex"] = data(vm, key, 16 if primitive == 0x205 else 18).hex() if key else None
        else:
            n, packet = vm.read(pointer + 2, 2), vm.read(pointer + 4)
            entry.update(packet_bytes=n, packet_pointer=hex(packet), packet_hex=data(vm, packet, n).hex())
            self.packets.append(entry)
        self.queue.append(entry); self.enqueued.append(entry)
        return 0
    def transmit(self, vm):
        descriptor = vm.reg[4]
        payload, n = vm.read(descriptor + 4), vm.read(descriptor + 8)
        assert vm.read(descriptor + 0x14, 1) == 5 and vm.read(descriptor + 0x15, 1) == 1
        assert vm.read(descriptor + 0xc) == 0
        self.transmitted.append(dict(descriptor=hex(descriptor), payload=hex(payload), bytes=n,
                                     packet_hex=data(vm, payload, n).hex(), fields_14_15=[5, 1]))
        return 0
    def receive(self, vm):
        entry = self.queue.pop(0)
        vm.write(vm.reg[4], int(entry["class_id"], 16), 2)
        vm.write(vm.reg[5], int(entry["pointer"], 16))
        self.delivered.append(entry)
        return 1
    def cached(self):
        result, seen, at = [], set(), self.vm.read(CACHE)
        while at:
            assert at not in seen and len(seen) < 100
            seen.add(at); key = self.vm.read(at + 0x1c)
            result.append(dict(pointer=hex(at), address_hex=data(self.vm, at + 8, 8).hex(),
                               key_type=self.vm.read(key, 2) if key else None,
                               key_hex=data(self.vm, key + 2, 16).hex() if key else None))
            at = self.vm.read(at)
        return result
    def reply(self, target, policy=0):
        vm = self.vm
        start = len(self.enqueued); freed = len(self.frees)
        put(vm, REQUEST, bytes(20)); put(vm, REQUEST + 4, target[:8])
        vm.write(REQUEST + 0x10, policy, 1); vm.write(CONTEXT + 0x1c, REQUEST)
        self.call(0xc5c48)
        assert len(self.queue) == 1 and self.queue[0]["destination"] == CM_ID
        self.call(0xbcf14, HOLDER)
        assert len(self.queue) == 1 and self.queue[0]["destination"] == DM_ID
        self.call(0x91bd4, HOLDER)
        assert len(self.queue) == 1 and self.queue[0]["destination"] == HCI_ID
        hci = self.queue.pop(0)
        assert len(self.enqueued) == start + 3 and not self.handles
        sc, dm = self.enqueued[start:start + 2]
        raw = bytes.fromhex(hci["packet_hex"])
        assert raw[3:9] == target[:3] + target[4:5] + target[6:8]
        assert int.from_bytes(raw[:2], "little") in (0x40b, 0x40c)
        positive = raw[:2] == b"\x0b\x04"
        assert raw[2] == (22 if positive else 6) and len(raw) == (25 if positive else 9)
        if positive: assert raw[9:] == target[10:26]
        freed_now = self.frees[freed:]
        freed_ptrs = {x["pointer"] for x in freed_now}
        assert sc["pointer"] in freed_ptrs and dm["pointer"] in freed_ptrs and dm["key_pointer"] in freed_ptrs
        assert sc["key_pointer"] == "0x0" or sc["key_pointer"] in freed_ptrs
        assert vm.read(int(sc["pointer"], 16) + 0x10) == 0
        return dict(sc=sc, dm=dm, hci=hci, positive=positive,
                    cm_cached_type=vm.read(CM + 0xe8, 1), free_calls=freed_now,
                    cache=self.cached(), abi_preserved=True)


def registrations(pe, ranges):
    vm = StackVM(pe, ranges); found = []
    def register(machine):
        at, init, deinit, handler = machine.reg[4:8]
        name_at = machine.read(machine.reg[29] + 0x10)
        name = pe.get_data(name_at - pe.OPTIONAL_HEADER.ImageBase, 64).split(b"\0", 1)[0].decode()
        assert machine.read(machine.reg[29] + 0x14) == HOLDER
        assert machine.read(machine.reg[29] + 0x18, 2) == 0
        found.append(dict(queue_global=hex(at), init=hex(init), deinit=hex(deinit), handler=hex(handler),
                          name=name, name_va=hex(name_at), name_hex=(name.encode() + b"\0").hex()))
        return 0
    vm.hooks[0x8517c] = register
    abi(vm, 0x8a230, HOLDER); abi(vm, 0x8a470, HOLDER)
    selected = {row["name"]: row for row in found}
    assert (selected["CSR_BT_CM"]["queue_global"], selected["CSR_BT_CM"]["handler"]) == (hex(CM_QUEUE), "0xbcf14")
    assert (selected["CSR_BT_DM"]["queue_global"], selected["CSR_BT_DM"]["handler"]) == (hex(DM_QUEUE), "0x91bd4")
    assert (selected["CSR_HCI"]["queue_global"], selected["CSR_HCI"]["handler"]) == (hex(HCI_QUEUE), "0xe96f4")
    return dict(tasks=found, abi_preserved=True, scheduler_registration_leaf_is_fixture=True)


def hci_delivery(pe, ranges, count, deferred=False, transport_present=True, negative=False):
    recs = [r[:0x65] + bytes([1 if negative else 5]) + r[0x66:] for r in records(count)]
    f = Stack(pe, HEADER + b"".join(recs), ranges)
    vm = f.vm
    if not transport_present: vm.write(TRANSPORT + 0xc, 0)
    vm.write(HCI_CONTEXT, int(not deferred), 1)
    traces = []
    for rec in recs:
        trace = f.reply(rec); traces.append(trace)
        f.queue.append(trace["hci"])
        f.call(0xe96f4, HCI_HOLDER)
        assert not f.queue
        if deferred: assert trace["hci"]["pointer"] not in {x["pointer"] for x in f.frees}
    block_count = 0; block = vm.read(HCI_CONTEXT + 0x14)
    while block:
        block_count += 1; assert block_count < 10
        block = vm.read(block + 4)
    if deferred:
        assert not f.transmitted and block_count == (count + 9) // 10
        f.call(0xe88b0, HCI_CONTEXT)
        assert len(f.queue) == 1 and f.queue[0]["wake"]
        for _ in range(count + 1): f.call(0xe96f4, HCI_HOLDER)
        assert not f.queue and vm.read(HCI_CONTEXT + 0x14) == 0 and vm.read(HCI_CONTEXT + 0x18, 1) == 0
    expected = [t["hci"]["packet_hex"] for t in traces] if transport_present else []
    assert [t["packet_hex"] for t in f.transmitted] == expected
    assert all(t["hci"]["pointer"] in {x["pointer"] for x in f.frees} for t in traces)
    assert vm.read(HCI_CONTEXT + 0x1c) == 0
    return dict(records=count, deferred=deferred, transport_present=transport_present,
                negative=negative, deferred_blocks=block_count, transmissions=f.transmitted,
                native_entries=dict(vm.entries), envelope_freed=True, abi_preserved=True,
                retained_transport_allocations=[a for a in f.allocations if int(a["pointer"], 16) not in vm.freed],
                scope="Original HCI dispatcher/state table/deferred queue/transport adapter, transmit callback is fixture; no controller ACK")


def main():
    module = next(m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
                  if m["origin"] == "705md" and m["name"] == "Blue.exe")
    sources, original = source(module, [*FUNCTIONS, *LEAVES], LEAVES)
    ranges = [(int(r["va"], 16), int(r["va"], 16) + r["bytes"]) for r in sources["ranges"]]
    raw = (ROOT / module["path"]).read_bytes(); candidate, patch = blue_key_iterator(raw)
    variants = {"original": original, "iterator": pefile.PE(data=candidate)}
    table_evidence = []
    for at, n in TABLES.items():
        b = original.get_data(at - original.OPTIONAL_HEADER.ImageBase, n)
        assert len(b) == n
        table_evidence.append(dict(va=hex(at), bytes=n, raw_hex=b.hex(), sha256=hashlib.sha256(b).hexdigest()))
    assert original.get_dword_at_rva(0x10e890 - original.OPTIONAL_HEADER.ImageBase) == 0xce478
    assert original.get_dword_at_rva(0x10d4d4 - original.OPTIONAL_HEADER.ImageBase) == 0xac9a4
    assert original.get_dword_at_rva(0x10efd4 - original.OPTIONAL_HEADER.ImageBase) == 0xe887c
    assert original.get_dword_at_rva(0x10f000 - original.OPTIONAL_HEADER.ImageBase) == 0xe91ec
    route = registrations(original, ranges)
    cold = []; serial = []; policies = []; inherited = []
    for label, pe in variants.items():
        recs = records(8)
        for i in range(9):
            f = Stack(pe, HEADER + b"".join(recs), ranges)
            target = recs[i] if i < 8 else records(9)[8]
            trace = f.reply(target)
            assert trace["positive"] == (i < 8 and target[0x65] in (0, 3, 4, 5))
            cold.append(dict(variant=label, index=i, trace=trace, native_entries=dict(f.vm.entries)))
        for count in (8, 16):
            recs = [r[:0x65] + b"\x05" + r[0x66:] for r in records(count)]
            f = Stack(pe, HEADER + b"".join(recs), ranges)
            traces = [f.reply(r) for r in recs]
            assert all(t["positive"] for t in traces) and len(f.cached()) == count
            again = [f.reply(r) for r in reversed(recs)]
            assert all(t["positive"] for t in again) and len(f.cached()) == count
            serial.append(dict(variant=label, records=count, first=traces, repeat_reverse=again,
                               native_entries=dict(f.vm.entries), scope="Native dynamic DM key cache, not physical controller storage"))
    for key_type in (*range(8), 0xfe):
        target = records(1)[0][:0x65] + bytes([key_type]) + records(1)[0][0x66:]
        for mode, flags in ((0, 0), (4, 0), (4, 0x2400)):
            f = Stack(variants["iterator"], HEADER + target, ranges, mode, flags)
            trace = f.reply(target)
            positive = key_type in (3, 4, 5) or key_type == 0 and (mode != 4 or flags & 0x2400 == 0)
            assert trace["positive"] == positive, (key_type, mode, flags, trace["positive"])
            policies.append(dict(key_type=key_type, mode_fixture=mode, flags_fixture=hex(flags), trace=trace))
    for old_type in (0, 3, 4, 5):
        target = records(1)[0][:0x65] + bytes([old_type]) + records(1)[0][0x66:]
        f = Stack(variants["iterator"], HEADER + target, ranges)
        first = f.reply(target); assert first["positive"]
        changed = bytearray(target); changed[0x65] = 6; changed[10:26] = bytes(range(16))
        f.contents = bytearray(HEADER + changed)
        second = f.reply(changed); assert second["positive"] and second["cache"][0]["key_type"] == old_type
        inherited.append(dict(old_type=old_type, first=first, changed_type=second))
    failures = []
    target = records(1)[0][:0x65] + b"\x05" + records(1)[0][0x66:]
    for fail in range(11):
        f = Stack(variants["iterator"], HEADER + target, ranges, fail=fail)
        try:
            f.reply(target)
            raise AssertionError("Unchecked allocation failure should reach a witness")
        except Witness as error:
            assert error.event["kind"] in ("low-write", "API-null-copy", "API-null-memset")
            failures.append(dict(allocation_index=fail, witness=error.event, allocations=f.allocations,
                                 freed=f.frees, queued=f.queue, open_handles=list(f.handles),
                                 abi_returned=False, api_fault_is_fixture=error.event["kind"].startswith("API-")))
    delivery = [dict(variant=label, trace=hci_delivery(pe, ranges, n, deferred))
                for label, pe in variants.items() for n in (1, 8, 16) for deferred in (False, True)]
    delivery += [dict(variant=label, trace=hci_delivery(pe, ranges, 1, deferred, negative=True))
                 for label, pe in variants.items() for deferred in (False, True)]
    absent = [hci_delivery(variants["iterator"], ranges, 1, deferred, transport_present=False)
              for deferred in (False, True)]
    hci_failures = []
    for deferred in (False, True):
        f = Stack(variants["iterator"], HEADER + target, ranges, fail=11)
        reply = f.reply(target); f.queue.append(reply["hci"])
        f.vm.write(HCI_CONTEXT, int(not deferred), 1)
        try:
            f.call(0xe96f4, HCI_HOLDER)
            raise AssertionError("HCI NULL allocation should reach native low store")
        except Witness as error:
            assert error.event["kind"] == "low-write"
            hci_failures.append(dict(deferred=deferred, witness=error.event,
                                     allocations=f.allocations, freed=f.frees, abi_returned=False))
    read_fault_pairs = []
    recs = [r[:0x65] + b"\x05" + r[0x66:] for r in records(8)]
    for i in range(8):
        pair = {}
        for label, pe in variants.items():
            f = Stack(pe, HEADER + b"".join(recs), ranges); f.faults[0] = (False, 104)
            trace = f.reply(recs[i]); assert trace["positive"] == (label == "original")
            pair[label] = dict(trace=trace, file_events=f.events)
        read_fault_pairs.append(dict(index=i, traces=pair))
    deps = ["verify_bt_key_stack.py", "verify_bt_key_store.py", "draft_bt_key_iterator.py", "draft_bt_list_ack.py",
            "verify_bt_database_io.py", "verify_bt_pairing_storage.py", "verify_bt_pairing_ui.py",
            "draft_bt_pairing_storage.py", "draft_bt_database_io.py", "patch_bt_playback.py",
            "inspect_bt_pairing.py", "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="SC/CM/DM key response reaches original HCI serializer, deferred dispatcher and transport callback",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  sources=sources, tables=table_evidence, registrations=route, iterator_patch=patch,
                  cold_reply_cases=cold, serial_cache_cases=serial, policy_cases=policies,
                  inherited_type_cases=inherited, allocation_failure_cases=failures,
                  hci_delivery_cases=delivery, absent_transport_cases=absent,
                  hci_allocation_failure_cases=hci_failures, read_fault_pairs=read_fault_pairs,
                  fixtures=dict(cm_instance_bytes="0x5b8", queue_ids=[CM_ID, DM_ID, HCI_ID],
                                cache_head=0, acl_head=0, command_queue_head=0, command_credits=1,
                                security_mode_default=4, security_flags_default=0, cookie="0x4321"),
                  limitations=["Scheduler registration/delivery, file APIs, heap memcpy/memset/free and logging are explicit fixtures",
                               "HCI transmit callback is fixture; no whole-stack init, physical transport driver, controller completion, radio authentication or hardware boot",
                               "Dynamic DM cache supports eight/sixteen in fixture; this is not controller capacity or concurrent link proof",
                               "Command/outstanding/cache/transmit-payload retention is intentional at this boundary; completion/shutdown/lifetime remain open",
                               "Absent transport callback returns silently with retained descriptor/payload; full registration/lifetime/recovery remains open",
                               "Security modes and ACL-list absence are fixture states, not the unit's measured configuration",
                               "Allocation failure witnesses expose original unchecked paths; API NULL witnesses stop at fixture boundary",
                               "Global cache/command/cursor scheduling concurrency and native heap failure recovery remain open",
                               "Pairing prototype remains separate from App safe-copy and MAX02; combined LGU build disabled"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps})
    out = ROOT / "analysis/firmware/bt-key-stack"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], cold=len(cold), serial=len(serial),
                         policy=len(policies), inherited=len(inherited), failures=len(failures),
                         hci_delivery=len(delivery), absent_transport=len(absent),
                         hci_failures=len(hci_failures), read_fault_pairs=len(read_fault_pairs)), indent=2))


if __name__ == "__main__": main()
