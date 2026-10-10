"""Interpret registered RX/mblk/DM_HCI and key-command completion bytes.

Synthetic controller events, allocator/file/scheduler/serial boundaries only.
No firmware execution, executable output or build authorization.
"""
import hashlib
import json
import pefile

from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import put, data
from verify_bt_transport import Transport, FUNCTIONS as TX_FUNCTIONS, LEAVES as TX_LEAVES
from verify_bt_key_stack import FUNCTIONS as KEY_FUNCTIONS, LEAVES as KEY_LEAVES, StackVM, COMMANDS
from verify_bt_key_store import Witness, records
from verify_bt_database_io import HEADER
from draft_bt_transport_cleanup import blue_transport_cleanup

DM_HCI_ID = 0x326
RX_DESCRIPTOR, RX_PAYLOAD = 0x57000000, 0x57100000
FUNCTIONS = [0xe8f14, 0xe8c0c, 0xe8708, 0x824a0, 0x82378, 0xead88,
             0x81c7c, 0x819ac, 0x81940, 0x824e8, 0x82530, 0x82630,
             0x9197c, 0xb44bc, 0xb917c, 0x8f6e0, 0x8f99c, 0x907a0,
             0x90838, 0xb3ce8, 0xb3fb4, 0xe9980]
LEAVES = {0x81df0: 0x28, 0xb924c: 0x2c, 0xbae4c: 0x54}
TABLES = {0x10c904: 24, 0x10da98: 43 * 8, 0x10d338: 16 * 4, 0x10e3b0: 26 * 8,
          0xe8c5c: 24, 0xb401c: 56}


class EventVM(StackVM):
    def read(self, at, size=4):
        if self.native_access:
            for start, length in self.event_guards:
                if start <= at < start + 0x1000 and at + size > start + length:
                    raise Witness(dict(kind="event-out-of-bounds-read", address=hex(at),
                                       offset=at - start, length=length, bytes=size, pc=hex(self.pc)))
        return super().read(at, size)


class Completion(Transport):
    def __init__(self, pe, ranges, recs):
        super().__init__(pe, HEADER + b"".join(recs), ranges, selector=7)
        self.vm.__class__ = EventVM
        self.vm.event_guards = []
        for at, n in TABLES.items(): put(self.vm, at, pe.get_data(at - pe.OPTIONAL_HEADER.ImageBase, n))
        self.vm.write(0x2172b0, 0x53000000)
        self.vm.write(0x53000002, DM_HCI_ID, 2)
        self.vm.write(0x218640, DM_HCI_ID, 2)
        self.events = []
        self.initialize()
    def enqueue(self, vm):
        if vm.reg[4:6] != [DM_HCI_ID, 0x600]: return super().enqueue(vm)
        pointer = vm.reg[6]
        assert vm.read(pointer, 2) == 0x8007
        length, payload = vm.read(pointer + 2, 2), vm.read(pointer + 4)
        event = dict(destination=DM_HCI_ID, class_id="0x600", primitive="0x8007",
                     pointer=hex(pointer), packet_pointer=hex(payload), packet_bytes=length,
                     packet_hex=data(vm, payload, length).hex())
        vm.event_guards.append((payload, length))
        self.events.append(event); self.queue.append(event); self.enqueued.append(event)
        return 0
    def outstanding(self, offset=4):
        at = self.vm.read(COMMANDS + offset); out = []; seen = set()
        while at:
            assert at not in seen
            seen.add(at); command = self.vm.read(at + 4)
            out.append(dict(node=hex(at), command=hex(command), opcode=hex(self.vm.read(command, 2))))
            at = self.vm.read(at)
        return out
    def inject(self, raw):
        assert not self.queue
        put(self.vm, RX_DESCRIPTOR, bytes(16)); put(self.vm, RX_PAYLOAD, raw)
        self.vm.event_guards = [(RX_PAYLOAD, len(raw))]
        self.vm.write(RX_DESCRIPTOR, RX_PAYLOAD); self.vm.write(RX_DESCRIPTOR + 4, len(raw))
        self.vm.write(RX_DESCRIPTOR + 12, 5, 1)
        # Use the callback written by the original native transport constructor.
        obj = self.vm.read(0x2172b4); callback = self.vm.read(obj + 0x10)
        assert callback == 0xe8f14
        self.call(callback, RX_DESCRIPTOR)
        if self.queue:
            assert len(self.queue) == 1 and self.queue[0]["destination"] == DM_HCI_ID
            assert self.queue[0]["packet_hex"] == raw.hex()
            self.call(0x9197c)
        assert not self.queue
        return self.events[-1] if self.events else None


def synthetic(n):
    out = []
    for rec in records(n):
        b = bytearray(rec); b[0x65] = 5; out.append(bytes(b))
    return out


def event(kind, opcode, rec, status=0, credit=1, declared=None):
    if kind == "complete":
        address = rec[:3] + rec[4:5] + rec[6:8]
        # Link Key Request Negative Reply is deliberately generic in the native
        # converter table, but the controller fixture still includes its BDADDR.
        body = bytes([credit]) + opcode.to_bytes(2, "little") + bytes([status]) + address
        raw = bytes([0x0e, len(body)]) + body
    else:
        body = bytes([status, credit]) + opcode.to_bytes(2, "little")
        raw = bytes([0x0f, len(body)]) + body
    if declared is not None: raw = raw[:1] + bytes([declared]) + raw[2:]
    return raw


def trace(pe, ranges, count, kind, status, credit, negative=False):
    recs = synthetic(count); f = Completion(pe, ranges, recs)
    targets = recs if not negative else [bytes([r[0] ^ 0x80]) + r[1:] for r in recs]
    replies = [f.deliver(r) for r in targets]
    for _ in range(count): f.call(0x7ef18, 0x218560)
    assert len(f.outstanding()) == count and not f.outstanding(0)
    assert not f.vm.read(0x218564) and not f.vm.read(0x218568)
    original = f.outstanding(); steps = []
    opcode = 0x40c if negative else 0x40b
    for i, rec in enumerate(targets):
        start = len(f.allocations); before = len(f.frees)
        f.inject(event(kind, opcode, rec, status, credit))
        assert len(f.outstanding()) == count - i - 1 and not f.outstanding(8)
        assert f.vm.read(0x110eac, 2) == credit
        new = f.allocations[start:]
        assert all(int(a["pointer"], 16) in f.vm.freed for a in new)
        assert original[i]["node"] in {e["pointer"] for e in f.frees[before:]}
        assert original[i]["command"] in {e["pointer"] for e in f.frees[before:]}
        steps.append(dict(remaining=count - i - 1, credit=credit, event=f.events[-1],
                          freed=f.frees[before:], rx_allocations=new))
    # An extra response with no outstanding command must be harmless to ownership.
    before = len(f.frees); f.inject(event(kind, opcode, targets[-1], status, credit))
    assert not f.outstanding()
    return dict(records=count, kind=kind, status=status, credit=credit, negative=negative,
                steps=steps, duplicate_empty_free_calls=f.frees[before:],
                retained_key_cache=len(f.cached()), native_entries=dict(f.vm.entries), abi_preserved=True)


def malformed(pe, ranges, raw):
    rec = synthetic(1)[0]; f = Completion(pe, ranges, [rec]); f.deliver(rec)
    f.call(0x7ef18, 0x218560)
    witness = None
    try: f.inject(raw)
    except Witness as error: witness = error.event
    return dict(input_hex=raw.hex(), witness=witness, remaining=f.outstanding(),
                credit=f.vm.read(0x110eac, 2), native_entries=dict(f.vm.entries))


def allocation_fault(pe, ranges, index):
    rec = synthetic(1)[0]; f = Completion(pe, ranges, [rec]); f.deliver(rec)
    f.call(0x7ef18, 0x218560); before = f.outstanding()
    f.allocation_failure = len(f.allocations) + index
    witness = None
    try: f.inject(event("complete", 0x40b, rec))
    except Witness as error: witness = error.event
    expected = [("API-null-copy", "0x85774"), ("API-null-copy", "0x85774"),
                ("low-write", "0xe8de8"), ("low-write", "0xe8740"),
                ("API-null-memset", "0xb44f4"), ("low-write", "0xbae78")]
    assert witness and (witness["kind"], witness["pc"]) == expected[index]
    assert f.outstanding() == before
    return dict(allocation_index=index, witness=witness, remaining=f.outstanding(),
                allocations=f.allocations, free_calls=f.frees, native_entries=dict(f.vm.entries))


def correlation(pe, ranges, mixed=False):
    recs = synthetic(2); f = Completion(pe, ranges, recs)
    targets = [recs[0], bytes([recs[1][0] ^ 0x80]) + recs[1][1:]] if mixed else recs
    for rec in targets: f.deliver(rec)
    for _ in targets: f.call(0x7ef18, 0x218560)
    before = f.outstanding(); snapshots = []
    # Unknown opcode restores the supplied credit but removes neither command.
    f.inject(event("complete", 0x40f, recs[0], credit=4))
    assert f.outstanding() == before and f.vm.read(0x110eac, 2) == 4
    snapshots.append(dict(kind="unknown-opcode", remaining=f.outstanding()))
    if mixed:
        f.inject(event("complete", 0x40c, targets[1]))
        assert f.outstanding() == before[:1]
        snapshots.append(dict(kind="negative-first", remaining=f.outstanding()))
        f.inject(event("complete", 0x40b, targets[0]))
    else:
        f.inject(event("complete", 0x40b, targets[1]))
        assert f.outstanding() == before[1:]
        snapshots.append(dict(kind="second-address-removes-first-opcode-match", remaining=f.outstanding()))
        f.inject(event("complete", 0x40b, targets[1]))
    assert not f.outstanding()
    snapshots.append(dict(kind="final", remaining=[]))
    return dict(mixed_opcodes=mixed, before=before, snapshots=snapshots,
                events=f.events, abi_preserved=True, native_entries=dict(f.vm.entries))


def main():
    module = next(m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
                  if m["origin"] == "705md" and m["name"] == "Blue.exe")
    leaves = {**KEY_LEAVES, **TX_LEAVES, **LEAVES}
    sources, pe = source(module, list(dict.fromkeys([*KEY_FUNCTIONS, *TX_FUNCTIONS, *FUNCTIONS, *leaves])), leaves)
    ranges = [(int(r["va"], 16), int(r["va"], 16) + r["bytes"]) for r in sources["ranges"]]
    raw = (ROOT / module["path"]).read_bytes(); fixed, patch = blue_transport_cleanup(raw)
    variants = {"original": pe, "cleanup": pefile.PE(data=fixed)}
    cases = [dict(variant=label, trace=trace(p, ranges, n, kind, status, credit, negative))
             for label, p in variants.items() for n in (1, 8, 16)
             for kind in ("complete", "status") for status in (0, 1, 0x11)
             for credit in (0, 1, 4) for negative in (False, True)]
    rec = synthetic(1)[0]; full = event("complete", 0x40b, rec)
    malformed_cases = [malformed(pe, ranges, raw) for raw in
                       (b"", full[:1], full[:2], full[:3], full[:5], full[:6], full[:9],
                        event("status", 0x40b, rec)[:5],
                        event("complete", 0x40b, rec, declared=0),
                        event("complete", 0x40b, rec, declared=255))]
    expected_pc = [None, "0x81df0", "0xb9190", "0xb919c", "0xb91b0", "0xbae4c",
                   "0xbae68", "0xb9260", None, None]
    assert [(c["witness"]["pc"] if c["witness"] else None) for c in malformed_cases] == expected_pc
    assert len(malformed_cases[8]["remaining"]) == 1 and not malformed_cases[9]["remaining"]
    faults = [allocation_fault(pe, ranges, i) for i in range(6)]
    correlations = [dict(variant=label, trace=correlation(p, ranges, mixed))
                    for label, p in variants.items() for mixed in (False, True)]
    deps = ["verify_bt_hci_completion.py", "verify_bt_transport.py", "draft_bt_transport_cleanup.py",
            "verify_bt_key_stack.py", "verify_bt_key_store.py", "draft_bt_key_iterator.py", "draft_bt_list_ack.py",
            "verify_bt_database_io.py", "verify_bt_pairing_storage.py", "verify_bt_pairing_ui.py",
            "draft_bt_pairing_storage.py", "draft_bt_database_io.py", "patch_bt_playback.py",
            "inspect_bt_pairing.py", "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Original registered RX, native mblk, DM_HCI decoding and key-command completion",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  sources=sources, data=[dict(va=hex(at), bytes=n, raw_hex=pe.get_data(at - pe.OPTIONAL_HEADER.ImageBase, n).hex())
                                        for at, n in TABLES.items()], cases=cases, malformed_cases=malformed_cases,
                  allocation_faults=faults, correlation_cases=correlations,
                  transport_cleanup_sha256=patch["draft_sha256"],
                  specification="https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Core-54/out/en/host-controller-interface/host-controller-interface-functional-specification.html",
                  limitations=["Controller events and callback staging descriptor are synthetic; UART/BCSP/H4 frame parser is not run",
                               "HCI context destination and cold DM command/cache state are fixtures, not whole stack boot",
                               "Command Status injections for Link Key replies test native branches, not normal controller conformance",
                               "Serial writes, scheduler, file and allocator boundaries remain inherited explicit fixtures",
                               "Payload bounds witnesses prove host instruction behavior for injected packets, not reachable radio exploitation",
                               "Same-opcode address reversal/duplicate matches FIFO in the fixture; actual controller order remains unverified",
                               "Concurrency, remaining auth/profile consumers and unit/controller remain open",
                               "No joint App integration or new executable/LGU; MAX02 unchanged"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps})
    out = ROOT / "analysis/firmware/bt-hci-completion"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], cases=len(cases), malformed=len(malformed_cases),
                         allocation_faults=len(faults), correlations=len(correlations),
                         witnesses=[c["witness"] for c in malformed_cases]), indent=2))


if __name__ == "__main__": main()
