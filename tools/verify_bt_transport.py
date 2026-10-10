"""Original transport selection/registration/ownership with synthetic key traffic.

Native MIPS bytes are interpreted; hardware writes, scheduler background kicks,
configuration application and power-state/timer boundaries are explicit fixtures.
No native execution or executable/LGU output.
"""
import hashlib
import json
import pefile

from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import abi, put, data
from verify_bt_key_stack import Stack, FUNCTIONS as KEY_FUNCTIONS, LEAVES as KEY_LEAVES
from verify_bt_key_stack import HOLDER, HCI_HOLDER, HCI_CONTEXT
from verify_bt_key_store import records, Witness
from verify_bt_database_io import HEADER
from draft_bt_key_iterator import blue_key_iterator
from draft_bt_transport_cleanup import blue_transport_cleanup

TM_HOLDER = 0x56000000
BCSP_CONTEXT, BCSP_HEAD = 0x2173e0, 0x20e314
H4_CONTEXT, H4_HEAD = 0x218560, 0x218564
SELECTOR, TM_INIT, TRANSPORT_GLOBAL = 0x110e80, 0x21721c, 0x2172b4
FUNCTIONS = [0x244c8, 0x7cb40, 0x7e980, 0x830f0, 0xe8fa8,
             0x7ca5c, 0x7d74c, 0x7ccb0, 0x7dad8, 0x83304, 0x7d7cc,
             0x7d070, 0x7dabc, 0x7d6e0, 0x7d674, 0x7cbf4, 0x7ddd4, 0x7d7f0, 0x7d860, 0x7d828,
             0x7e8b0, 0x7ee48, 0x7f230, 0x80704, 0x7ef18,
             0x7edd4, 0x7f8a8, 0x7eb5c, 0x829d8]
LEAVES = {0x83980: 12, 0x8145c: 0x1c, 0x83444: 0x1c,
          0x829fc: 0x34, 0x829b4: 0x24, 0x82a30: 0x20}
DATA = {0x110e28: 44, 0x110e54: 44, 0x110e80: 2, 0x110e50: 4, 0x110e7c: 4}


class Transport(Stack):
    def __init__(self, pe, contents, ranges, selector=1, previous=0, write_limit=None):
        super().__init__(pe, contents, ranges)
        self.registrations = []; self.background = []; self.writes = []
        self.write_limit = write_limit
        vm = self.vm
        for at, n in DATA.items(): put(vm, at, pe.get_data(at - pe.OPTIONAL_HEADER.ImageBase, n))
        if selector is not None: vm.write(SELECTOR, selector, 2)
        vm.write(TM_INIT, previous)
        vm.write(TRANSPORT_GLOBAL, 0)  # Explicit cold loader fixture before native registration.
        put(vm, BCSP_CONTEXT, bytes(0x1170)); vm.write(BCSP_HEAD, 0)
        put(vm, H4_CONTEXT, bytes(0xc8)); vm.write(H4_CONTEXT, 1, 1)
        vm.hooks.update({0x8517c: self.register, 0x841e8: self.kick,
                         0x85354: self.unregister_background, 0x85008: self.cancel_timer,
                         0x805e4: self.write_bytes,
                         0x7f91c: self.power_state})
        for at in (0x83998, 0x8398c, 0x839a4, 0x839b0, 0x2e644, 0x7b7bc): vm.hooks[at] = lambda m: 0
    def register(self, vm):
        name_at = vm.read(vm.reg[29] + 0x10)
        name = vm.pe.get_data(name_at - vm.base, 64).split(b"\0", 1)[0].decode()
        self.registrations.append(dict(name=name, queue_global=hex(vm.reg[4]), init=hex(vm.reg[5]),
                                       handler=hex(vm.reg[7]), segment=vm.read(vm.reg[29] + 0x18, 2)))
        return 0
    def kick(self, vm):
        assert vm.reg[4] == 0  # Explicit absent/zero scheduler background ID fixture.
        self.background.append(dict(kind="kick", id=vm.reg[4])); return 0
    def unregister_background(self, vm):
        self.background.append(dict(kind="unregister", id=vm.reg[4])); return 0
    def cancel_timer(self, vm):
        assert vm.reg[4:7] == [0, 0, 0]
        self.background.append(dict(kind="cancel-zero-timer")); return 0
    def power_state(self, vm): return 0
    def write_bytes(self, vm):
        at, requested, payload = vm.reg[4:7]
        assert payload in (0, 1) and requested <= 258
        n = requested if self.write_limit is None else min(requested, self.write_limit)
        self.writes.append(dict(payload=bool(payload), requested=requested, returned=n,
                                bytes_hex=data(vm, at, n).hex()))
        return n
    def free(self, vm):
        at = vm.reg[4]
        if at and (at in vm.freed or not any(int(a["pointer"], 16) == at for a in self.allocations)):
            raise Witness(dict(kind="invalid-free", pointer=hex(at), pc=hex(vm.pc),
                               previously_freed=at in vm.freed))
        return super().free(vm)
    def initialize(self):
        self.call(0x244c8, HOLDER)
        callback = self.vm.read(TM_INIT)
        registered = next(r for r in self.registrations if r["name"] == "CSR_TM_BLUECORE")
        assert registered["init"] == hex(callback)
        if callback not in (0x7cb40, 0x7e980): return registered
        self.call(callback, TM_HOLDER)
        obj = self.vm.read(TRANSPORT_GLOBAL)
        assert obj == (0x110e28 if callback == 0x7cb40 else 0x110e54)
        assert self.vm.read(obj + 0x10) == 0xe8f14
        assert self.vm.read(self.vm.read(TM_HOLDER) + 0x20) == obj
        return registered
    def deliver(self, rec):
        trace = self.reply(rec)
        self.queue.append(trace["hci"]); self.vm.write(HCI_CONTEXT, 1, 1)
        self.call(0xe96f4, HCI_HOLDER)
        assert not self.queue
        return trace
    def queued(self, head):
        found = []; seen = set(); at = self.vm.read(head)
        while at:
            assert at not in seen and len(seen) < 100
            seen.add(at); ptr, n = self.vm.read(at + 4), self.vm.read(at + 8)
            found.append(dict(descriptor=hex(at), pointer=hex(ptr), bytes=n, packet_hex=data(self.vm, ptr, n).hex()))
            at = self.vm.read(at)
        return found


def synthetic(count):
    return [r[:0x65] + b"\x05" + r[0x66:] for r in records(count)]


def selection(pe, ranges, selector, previous=0):
    f = Transport(pe, HEADER, ranges, selector, previous)
    registered = f.initialize()
    selected = f.vm.read(SELECTOR, 2)
    expected = {1: 0x7cb40, 7: 0x7e980}.get(selected, previous)
    assert f.vm.read(TM_INIT) == expected
    return dict(selector=selected, source_default=selector is None, previous=hex(previous),
                registered=registered, constructor=hex(expected),
                transport_object=hex(f.vm.read(TRANSPORT_GLOBAL)),
                native_entries=dict(f.vm.entries), abi_preserved=True)


def bcsp(pe, ranges, count, start=0):
    recs = synthetic(count); f = Transport(pe, HEADER + b"".join(recs), ranges, None)
    f.initialize(); vm = f.vm
    for offset in (0xd4, 0xd8, 0xdc): vm.write(BCSP_CONTEXT + offset, start)
    replies = [f.deliver(rec) for rec in recs]
    assert (vm.read(BCSP_CONTEXT + 0xd4) - vm.read(BCSP_CONTEXT + 0xd8)) & 7 == min(4, count)
    assert len(f.queued(BCSP_HEAD)) == max(0, count - 4)
    acknowledgments = []; wire_order = []
    while len(wire_order) < count:
        oldest, newest = vm.read(BCSP_CONTEXT + 0xd8), vm.read(BCSP_CONTEXT + 0xd4)
        accepted = (newest - oldest) & 7
        assert 0 < accepted <= 4
        ptrs = []
        for i in range(accepted):
            slot = BCSP_CONTEXT + 0x18 + ((oldest + i) & 7) * 24
            ptr, n = vm.read(slot), vm.read(slot + 4)
            ptrs.append(hex(ptr)); wire_order.append(data(vm, ptr, n).hex())
        vm.write(BCSP_CONTEXT + 0x1157, newest, 1)  # Explicit parsed remote ACK fixture.
        f.call(0x7d070, HOLDER)
        assert vm.read(BCSP_CONTEXT + 0xd8) == newest
        assert all(p in {x["pointer"] for x in f.frees} for p in ptrs)
        acknowledgments.append(dict(next_sequence=newest, payloads_freed=ptrs))
        for _ in range(min(4, len(f.queued(BCSP_HEAD)))): f.call(0x7d74c, HOLDER)
    assert wire_order == [r["hci"]["packet_hex"] for r in replies]
    assert not f.queued(BCSP_HEAD)
    freed_before = len(f.frees); f.call(0x7d070, HOLDER)
    assert len(f.frees) == freed_before
    return dict(records=count, initial_sequence=start, acknowledgments=acknowledgments,
                command_order=wire_order, native_entries=dict(vm.entries), abi_preserved=True,
                duplicate_final_ack_no_free=True,
                scope="Native callback/FIFO/four-entry reliable window/ACK payload cleanup; parsed ACK and background service are fixtures, no framing or wire write")


def h4(pe, ranges, count, limit=None, stalled=False, negative=False):
    recs = synthetic(count)
    if negative: recs = [r[:0x65] + b"\x01" + r[0x66:] for r in recs]
    f = Transport(pe, HEADER + b"".join(recs), ranges, 7, write_limit=limit)
    f.initialize(); replies = [f.deliver(rec) for rec in recs]
    assert len(f.queued(H4_HEAD)) == count
    if stalled: f.write_limit = 0
    calls = 0
    while f.vm.read(H4_HEAD) or f.vm.read(H4_CONTEXT + 8):
        f.call(0x7ef18, H4_CONTEXT); calls += 1
        assert calls <= count * 40
        if stalled:
            assert calls == 1 and not any(e["returned"] for e in f.writes)
            assert f.vm.read(H4_CONTEXT + 8) != 0
            f.write_limit = limit; stalled = False
    sent = b"".join(bytes.fromhex(w["bytes_hex"]) for w in f.writes)
    expected = b"".join(b"\x01" + bytes.fromhex(r["hci"]["packet_hex"]) for r in replies)
    assert sent == expected
    payloads = {r["hci"]["packet_pointer"] for r in replies}
    assert payloads <= {e["pointer"] for e in f.frees}
    return dict(records=count, write_limit=limit, negative=negative, calls=calls, writes=f.writes,
                sent_hex=sent.hex(), payloads_freed=True, native_entries=dict(f.vm.entries), abi_preserved=True,
                scope="Native H4 command FIFO/header/partial-write bookkeeping; lower send API and power/backoff boundary are fixtures")


def shutdown(pe, ranges, protocol, count, repaired=False, active=False):
    recs = synthetic(count); f = Transport(pe, HEADER + b"".join(recs), ranges, protocol)
    f.initialize(); replies = [f.deliver(r) for r in recs]
    if active:
        assert protocol == 7 and count > 0
        f.write_limit = 7; f.call(0x7ef18, H4_CONTEXT)
        assert f.vm.read(H4_CONTEXT + 8) != 0
        assert len(f.queued(H4_HEAD)) == count - 1
    witness = None; repeat_witness = None
    try:
        if protocol == 1: f.call(0x7d674, HOLDER)
        else: f.call(0x7eb5c, HOLDER)
    except Witness as error: witness = error.event
    if protocol == 7 and count > int(active) and not repaired:
        assert witness == dict(kind="invalid-free", pointer="0x218564", pc="0x829ec", previously_freed=False)
    else:
        assert witness is None
        head = BCSP_HEAD if protocol == 1 else H4_HEAD
        assert f.vm.read(head) == 0
        payloads = {r["hci"]["packet_pointer"] for r in replies}
        assert payloads <= {e["pointer"] for e in f.frees}
        before = len(f.frees)
        try: f.call(0x7d674 if protocol == 1 else 0x7eb5c, HOLDER)
        except Witness as error: repeat_witness = error.event
        if protocol == 1 and count and not repaired:
            assert repeat_witness and repeat_witness["kind"] == "invalid-free"
            assert repeat_witness["previously_freed"] and repeat_witness["pc"] == "0x7dac8"
        else:
            assert repeat_witness is None and len(f.frees) == before + (1 if protocol == 1 else 0)
    return dict(protocol=protocol, records=count, active=active, witness=witness, free_calls=f.frees,
                repeat_witness=repeat_witness, repeat_abi_preserved=witness is None and repeat_witness is None,
                remaining_queue=f.queued(BCSP_HEAD if protocol == 1 else H4_HEAD),
                native_entries=dict(f.vm.entries), abi_preserved=witness is None)


def main():
    module = next(m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
                  if m["origin"] == "705md" and m["name"] == "Blue.exe")
    leaves = {**KEY_LEAVES, **LEAVES}
    sources, original = source(module, list(dict.fromkeys([*KEY_FUNCTIONS, *FUNCTIONS, *leaves])), leaves)
    ranges = [(int(r["va"], 16), int(r["va"], 16) + r["bytes"]) for r in sources["ranges"]]
    raw = (ROOT / module["path"]).read_bytes()
    iterator, _ = blue_key_iterator(raw); fixed, patch = blue_transport_cleanup(raw)
    variants = {"original": original, "iterator": pefile.PE(data=iterator), "cleanup": pefile.PE(data=fixed)}
    d = original.get_data(SELECTOR - original.OPTIONAL_HEADER.ImageBase, 2)
    assert d == b"\x01\0"
    funcs = json.loads((ROOT / "analysis/functions/705md/Blue.exe.json").read_text(encoding="utf-8"))["functions"]
    callers = {target: [(f["begin_va"], c["va"]) for f in funcs for c in f.get("direct_calls", [])
                        if c["target_va"] == target] for target in ("0x7d6e0", "0x829d8")}
    assert callers == {"0x7d6e0": [("0x7d674", "0x7d6ac")], "0x829d8": [("0x7eb5c", "0x7ebe8")]}
    data_evidence = [dict(va=hex(at), bytes=n, raw_hex=original.get_data(at - original.OPTIONAL_HEADER.ImageBase, n).hex())
                     for at, n in DATA.items()]
    selections = [selection(original, ranges, s, old) for s in (None, 1, 7, 0, 2, 0xff) for old in (0, 0x7cb40)]
    bcsp_cases = [dict(variant=label, trace=bcsp(pe, ranges, n, start)) for label, pe in variants.items()
                  for n in (1, 4, 8, 16) for start in (0, 6)]
    h4_cases = [dict(variant=label, trace=h4(pe, ranges, n, limit, stall)) for label, pe in variants.items()
                for n in (1, 8) for limit in (None, 1, 7) for stall in (False, True)]
    h4_cases += [dict(variant=label, trace=h4(pe, ranges, n, limit, negative=True))
                 for label, pe in variants.items() for n in (1, 8) for limit in (None, 7)]
    shut = [dict(variant=label, trace=shutdown(pe, ranges, protocol, n, label == "cleanup"))
            for label, pe in variants.items() for protocol in (1, 7) for n in (0, 1, 4, 8, 16)]
    shut += [dict(variant=label, trace=shutdown(pe, ranges, 7, n, label == "cleanup", active=True))
             for label, pe in variants.items() for n in (1, 8)]
    deps = ["verify_bt_transport.py", "draft_bt_transport_cleanup.py", "verify_bt_key_stack.py",
            "verify_bt_key_store.py", "draft_bt_key_iterator.py", "draft_bt_list_ack.py",
            "verify_bt_database_io.py", "verify_bt_pairing_storage.py", "verify_bt_pairing_ui.py",
            "draft_bt_pairing_storage.py", "draft_bt_database_io.py", "patch_bt_playback.py",
            "inspect_bt_pairing.py", "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Original BCSP/H4 selection, registration, key-packet ownership and separate cleanup repairs",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  sources=sources, data=data_evidence, callers=callers, cleanup_patch=patch,
                  selection_cases=selections, bcsp_cases=bcsp_cases, h4_cases=h4_cases, shutdown_cases=shut,
                  limitations=["Config application, scheduler registration/background/timer and low serial-send/power boundaries are fixtures",
                               "Original file default selects BCSP; commandline/unit overrides and whole stack boot are not measured",
                               "BCSP parsed ACK and service order are fixtures; framing/CRC/resend/serial transmission remain open",
                               "H4 lower-write counts are fixtures; malformed counts, power management and full receive parser remain open",
                               "Native free calls are captured by a strict allocator fixture; actual CE invalid-free outcome is not claimed",
                               "Two original direct cleanup callers inventoried; computed/indirect entry and concurrency lifetime remain open",
                               "Command completion/security profile/radio and controller behavior remain unverified",
                               "Cleanup prototype stays separate from App safe-copy and MAX02, no combined LGU"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps})
    out = ROOT / "analysis/firmware/bt-transport"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], selection=len(selections), bcsp=len(bcsp_cases),
                         h4=len(h4_cases), shutdown=len(shut), blue_sha256=patch["draft_sha256"]), indent=2))


if __name__ == "__main__": main()
