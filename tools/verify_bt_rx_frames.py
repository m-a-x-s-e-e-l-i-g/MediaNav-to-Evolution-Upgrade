"""Original BCSP SLIP/header/CRC and H4 serial RX through DM_HCI.

Serial API, cold link state, scheduler/file/heap boundaries are explicit fixtures.
Only bounded MIPS interpretation; no native firmware or executable/LGU output.
"""
import hashlib
import json
import struct
import pefile

from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import put, data
from verify_bt_hci_completion import Completion, EventVM, event, synthetic
from verify_bt_hci_completion import FUNCTIONS as HC_FUNCTIONS, LEAVES as HC_LEAVES, TABLES as HC_TABLES
from verify_bt_transport import FUNCTIONS as TX_FUNCTIONS, LEAVES as TX_LEAVES
from verify_bt_transport import BCSP_CONTEXT, BCSP_HEAD, H4_CONTEXT, SELECTOR
from verify_bt_key_stack import FUNCTIONS as KEY_FUNCTIONS, LEAVES as KEY_LEAVES
from verify_bt_key_store import Witness
from draft_bt_transport_cleanup import blue_transport_cleanup

INPUT = 0x58000000
H4_RX = 0x2185e0  # Receive assembly context; distinct from TX context 218560.
FUNCTIONS = [0x7e4d0, 0x7e208, 0x7e1d4, 0x83414, 0x7f598, 0x7f39c,
             0x809f0, 0x8079c, 0x8139c]
LEAVES = {0x7e0e8: 0x50, 0x7e138: 0x9c, 0x7f950: 0x40, 0x80c34: 0x30}
TABLES = {0x10c62c: 512, 0x80838: 24}


class FrameVM(EventVM):
    def bounds(self, at, size, kind):
        if self.native_access:
            for allocation in self.heap_bounds:
                start, length = int(allocation["pointer"], 16), allocation["bytes"]
                if start and start <= at < start + 0x10000 and at + size > start + length:
                    raise Witness(dict(kind="heap-out-of-bounds-" + kind, address=hex(at),
                                       offset=at - start, length=length, bytes=size, pc=hex(self.pc)))
    def read(self, at, size=4):
        self.bounds(at, size, "read")
        return super().read(at, size)
    def write(self, at, value, size=4):
        self.bounds(at, size, "write")
        return super().write(at, value, size)


class Frames(Completion):
    def __init__(self, pe, ranges, recs, protocol=1, limit=None, seq=0):
        self.protocol = protocol
        super().__init__(pe, ranges, recs)
        self.vm.__class__ = FrameVM
        self.vm.heap_bounds = self.allocations
        self.stream = bytearray(); self.stream_at = 0; self.serial_reads = []; self.read_limit = limit
        self.vm.hooks[0x87600] = self.serial_read
        for at, n in TABLES.items(): put(self.vm, at, pe.get_data(at - pe.OPTIONAL_HEADER.ImageBase, n))
        self.vm.write(BCSP_CONTEXT + 0x938, 1)  # SLIP initialized, before first C0.
        self.vm.write(BCSP_CONTEXT + 0x1155, seq, 1)  # Explicit expected reliable sequence fixture.
        put(self.vm, H4_RX, bytes(0x4c))
        self.vm.write(H4_RX + 0x30, H4_RX + 0x21)
        self.vm.write(H4_RX + 0x3e, 1, 2)
        self.vm.write(H4_RX + 0x48, 0x777)
        self.vm.write(0x20e328, 5)  # Ready H4DS link state fixture; power negotiation is not run.
        self.vm.write(0x20e343, 1, 1)  # Native 80c34's receiving-ready state fixture.
    def initialize(self):
        self.vm.write(SELECTOR, self.protocol, 2)
        return super().initialize()
    def serial_read(self, vm):
        handle, requested, destination = vm.reg[4:7]
        assert handle == 0x777
        n = min(requested, len(self.stream) - self.stream_at)
        if self.read_limit is not None: n = min(n, self.read_limit)
        payload = bytes(self.stream[self.stream_at:self.stream_at + n])
        put(vm, destination, payload); self.stream_at += n
        self.serial_reads.append(dict(requested=requested, returned=n, destination=hex(destination),
                                      bytes_hex=payload.hex()))
        return n
    def prepare(self, recs):
        for rec in recs: self.deliver(rec)
        if self.protocol == 7:
            for _ in recs: self.call(0x7ef18, H4_CONTEXT)
        else:
            # Native TX ring release/pump with explicit parsed peer ACK fixtures.
            for _ in range(len(recs) + 1):
                old, new = self.vm.read(BCSP_CONTEXT + 0xd8), self.vm.read(BCSP_CONTEXT + 0xd4)
                if old == new and not self.queued(BCSP_HEAD): break
                self.vm.write(BCSP_CONTEXT + 0x1157, new, 1)
                self.call(0x7d070); self.call(0x7d74c)
            assert not self.queued(BCSP_HEAD)
    def drain_events(self):
        while self.queue:
            assert self.queue[0]["primitive"] == "0x8007"
            self.call(0x9197c)
    def hci_events(self):
        return [e for e in self.events if e.get("primitive") == "0x8007" and e.get("class_id") == "0x600"]
    def bcsp(self, wire, chunk=None):
        feeds = []; position = 0
        while position < len(wire):
            part = wire[position:] if chunk is None else wire[position:position + chunk]
            put(self.vm, INPUT, part)
            self.vm.event_guards = [(INPUT, len(part))]
            consumed = self.call(0x7e4d0, INPUT, len(part))
            assert 0 < consumed <= len(part)
            feeds.append(dict(input_hex=part.hex(), consumed=consumed,
                              slip_state=self.vm.read(BCSP_CONTEXT + 0x938),
                              decoded_bytes=self.vm.read(BCSP_CONTEXT + 0x93c)))
            position += consumed
            self.drain_events()
        return feeds
    def h4(self, wire, steps=None):
        self.stream.extend(wire)
        if steps is None: steps = max(32, len(self.stream) * 2 + 16)
        for _ in range(steps):
            before = self.stream_at
            self.call(0x7f598)
            self.drain_events()
            if before == self.stream_at: break
        else: raise AssertionError("H4 RX service bound")
        return dict(consumed=self.stream_at, offered=len(self.stream), reads=list(self.serial_reads),
                    read_state=self.vm.read(H4_RX + 0x20, 1),
                    accumulated=self.vm.read(H4_RX + 0x2e, 2),
                    payload_length=self.vm.read(H4_RX + 0x34, 2),
                    payload_pointer=hex(self.vm.read(H4_RX + 0x38)))


def reflected_crc(payload):
    value = 0xffff
    for b in payload:
        value ^= b
        for _ in range(8): value = (value >> 1) ^ (0x8408 if value & 1 else 0)
    return int(f"{value:016b}"[::-1], 2)


def slip(raw):
    encoded = bytearray(b"\xc0")
    for b in raw: encoded.extend(b"\xdb\xdc" if b == 0xc0 else b"\xdb\xdd" if b == 0xdb else bytes([b]))
    return bytes(encoded + b"\xc0")


def bcsp_frame(payload, seq=0, crc=True, declared=None):
    n = len(payload) if declared is None else declared
    header = bytearray([0x80 | (0x40 if crc else 0) | seq, 5 | ((n & 15) << 4), n >> 4])
    header.append((0xff - sum(header)) & 255)
    raw = bytes(header) + payload
    return raw + (reflected_crc(raw).to_bytes(2, "big") if crc else b"")


def normal(pe, ranges, protocol, count, chunk, crc, seq):
    recs = synthetic(count)
    # Exercise both escaped octets in real HCI BDADDR fields.
    recs = [b"\xc0\xdb" + r[2:] for r in recs]
    f = Frames(pe, ranges, recs, protocol, chunk, seq); f.prepare(recs)
    allocation_start = len(f.allocations)
    packets = [event("complete", 0x40b, r) for r in recs]
    if protocol == 1:
        wire = b"".join(slip(bcsp_frame(p, (seq + i) & 7, crc)) for i, p in enumerate(packets))
        trace = f.bcsp(wire, chunk)
        assert f.vm.read(BCSP_CONTEXT + 0x1155, 1) == (seq + count) & 7
    else:
        wire = b"".join(b"\x04" + p for p in packets)
        trace = f.h4(wire)
        assert trace["consumed"] == len(wire) and trace["read_state"] == 0
    assert not f.outstanding() and len(f.hci_events()) == count
    assert [e["packet_hex"] for e in f.hci_events()] == [p.hex() for p in packets]
    rx_allocations = f.allocations[allocation_start:]
    assert all(int(a["pointer"], 16) in f.vm.freed for a in rx_allocations)
    return dict(protocol=protocol, records=count, chunk=chunk, crc=crc if protocol == 1 else None,
                expected_seq=seq if protocol == 1 else None, wire_hex=wire.hex(), trace=trace,
                events=f.hci_events(), remaining=f.outstanding(), rx_allocations=rx_allocations,
                rx_allocations_freed=True, native_entries=dict(f.vm.entries), abi_preserved=True)


def probe(pe, ranges, protocol, name, wire, limit=None):
    rec = synthetic(1)[0]; f = Frames(pe, ranges, [rec], protocol, limit); f.prepare([rec])
    witness = None; trace = None
    try: trace = f.bcsp(wire, limit) if protocol == 1 else f.h4(wire)
    except Witness as error: witness = error.event
    return dict(protocol=protocol, name=name, wire_hex=wire.hex(), trace=trace, witness=witness,
                events=f.hci_events(), remaining=f.outstanding(), serial_reads=f.serial_reads,
                rx_state=dict(h4=f.vm.read(H4_RX + 0x20, 1),
                              allocated_payload=hex(f.vm.read(H4_RX + 0x38)),
                              slip=f.vm.read(BCSP_CONTEXT + 0x938),
                              sequence=f.vm.read(BCSP_CONTEXT + 0x1155, 1)),
                native_entries=dict(f.vm.entries))


def check_probe(result):
    """Pin the original parser behavior, including fault and waiting outcomes."""
    protocol, name = result["protocol"], result["name"]
    witness = result["witness"]
    if name == "inner-short":
        assert witness and (witness["kind"], witness["pc"], witness["offset"], witness["length"], witness["bytes"]) == (
            "heap-out-of-bounds-read", "0xb919c", 4, 3, 1)
        assert len(result["events"]) == len(result["remaining"]) == 1
        outcome = "short-event-reaches-decoder-read"
    elif protocol == 1:
        assert witness is None
        if name == "inner-declared-255":
            assert len(result["events"]) == 1 and not result["remaining"]
            outcome = "inner-length-mismatch-accepted"
        elif name == "zero-event-length":
            assert len(result["events"]) == len(result["remaining"]) == 1
            outcome = "event-published-command-retained"
        else:
            assert not result["events"] and len(result["remaining"]) == 1
            outcome = "outer-frame-rejected"
        assert result["rx_state"]["sequence"] == (1 if result["events"] else 0)
    else:
        assert witness is None and not result["events"] and len(result["remaining"]) == 1
        assert result["rx_state"]["h4"] == 1 and result["rx_state"]["allocated_payload"] != "0x0"
        outcome = "body-wait-under-ready-state-fixture"
    result["expected_outcome"] = outcome
    result["expectation_checked"] = True


def recover_bcsp(pe, ranges, name, wire, chunk):
    rec = synthetic(1)[0]; f = Frames(pe, ranges, [rec], 1); f.prepare([rec])
    before = f.outstanding()
    rejected = f.bcsp(wire, chunk)
    assert f.outstanding() == before and not f.hci_events()
    assert f.vm.read(BCSP_CONTEXT + 0x1155, 1) == 0
    raw = event("complete", 0x40b, rec)
    recovered = f.bcsp(slip(bcsp_frame(raw)), chunk)
    assert not f.outstanding() and len(f.hci_events()) == 1
    assert f.hci_events()[0]["packet_hex"] == raw.hex()
    assert f.vm.read(BCSP_CONTEXT + 0x1155, 1) == 1
    return dict(protocol=1, name=name, chunk=chunk, rejected=rejected, recovered=recovered,
                events=f.hci_events(), native_entries=dict(f.vm.entries), abi_preserved=True)


def resume_h4(pe, ranges, chunk):
    rec = synthetic(1)[0]; f = Frames(pe, ranges, [rec], 7, chunk); f.prepare([rec])
    raw = event("complete", 0x40b, rec); before = f.outstanding()
    partial = f.h4(b"\x04" + raw[:6])
    assert not f.hci_events() and f.outstanding() == before
    pointer = f.vm.read(H4_RX + 0x38)
    assert pointer and f.vm.read(H4_RX + 0x20, 1) == 1
    resumed = f.h4(raw[6:])
    assert resumed["consumed"] == resumed["offered"] == len(raw) + 1
    assert not f.outstanding() and len(f.hci_events()) == 1
    assert f.hci_events()[0]["packet_hex"] == raw.hex()
    assert f.vm.read(H4_RX + 0x20, 1) == 0 and f.vm.read(H4_RX + 0x38) == 0
    assert pointer in f.vm.freed
    return dict(protocol=7, chunk=chunk, partial=partial, resumed=resumed,
                events=f.hci_events(), partial_buffer_freed=True,
                native_entries=dict(f.vm.entries), abi_preserved=True)


def duplicate_bcsp(pe, ranges, chunk):
    recs = synthetic(2); f = Frames(pe, ranges, recs, 1); f.prepare(recs)
    before = f.outstanding(); raw = event("complete", 0x40b, recs[0])
    wire = slip(bcsp_frame(raw, seq=0))
    first = f.bcsp(wire, chunk)
    assert f.outstanding() == before[1:] and len(f.hci_events()) == 1
    frees = len(f.frees); duplicate = f.bcsp(wire, chunk)
    assert f.outstanding() == before[1:] and len(f.hci_events()) == 1 and len(f.frees) == frees
    assert f.vm.read(BCSP_CONTEXT + 0x1155, 1) == 1
    final = f.bcsp(slip(bcsp_frame(event("complete", 0x40b, recs[1]), seq=1)), chunk)
    assert not f.outstanding() and len(f.hci_events()) == 2
    return dict(protocol=1, chunk=chunk, first=first, duplicate=duplicate, final=final,
                duplicate_not_delivered=True, events=f.hci_events(),
                native_entries=dict(f.vm.entries), abi_preserved=True)


def main():
    module = next(m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
                  if m["origin"] == "705md" and m["name"] == "Blue.exe")
    leaves = {**KEY_LEAVES, **TX_LEAVES, **HC_LEAVES, **LEAVES}
    sources, pe = source(module, list(dict.fromkeys([*KEY_FUNCTIONS, *TX_FUNCTIONS, *HC_FUNCTIONS, *FUNCTIONS, *leaves])), leaves)
    ranges = [(int(r["va"], 16), int(r["va"], 16) + r["bytes"]) for r in sources["ranges"]]
    fixed, patch = blue_transport_cleanup((ROOT / module["path"]).read_bytes())
    variants = {"original": pe, "cleanup": pefile.PE(data=fixed)}
    # Independent bitwise check of every original reflected CRC table entry.
    table = pe.get_data(0x10c62c - pe.OPTIONAL_HEADER.ImageBase, 512)
    for i in range(256):
        value = i
        for _ in range(8): value = (value >> 1) ^ (0x8408 if value & 1 else 0)
        assert struct.unpack_from("<H", table, i * 2)[0] == value
    cases = [dict(variant=label, trace=normal(p, ranges, 1, n, chunk, crc, seq))
             for label, p in variants.items() for n in (1, 8) for chunk in (None, 1, 7)
             for crc in (False, True) for seq in (0, 6)]
    cases += [dict(variant=label, trace=normal(p, ranges, 7, n, chunk, False, 0))
              for label, p in variants.items() for n in (1, 8) for chunk in (None, 1, 7)]
    raw = event("complete", 0x40b, synthetic(1)[0]); frame = bcsp_frame(raw)
    wires = [("header-checksum", slip(bytes([frame[0] ^ 1]) + frame[1:])),
             ("crc-error", slip(frame[:-1] + bytes([frame[-1] ^ 1]))),
             ("outer-short", slip(bcsp_frame(raw, declared=len(raw) + 1))),
             ("outer-long", slip(bcsp_frame(raw, declared=len(raw) - 1))),
             ("unexpected-sequence", slip(bcsp_frame(raw, seq=1))),
             ("inner-short", slip(bcsp_frame(raw[:3]))),
             ("inner-declared-255", slip(bcsp_frame(raw[:1] + b"\xff" + raw[2:]))),
             ("zero-event-length", slip(bcsp_frame(raw[:1] + b"\x00" + raw[2:]))),
             ("invalid-slip-escape", b"\xc0\xdb\x00\xc0")]
    probes = [probe(pe, ranges, 1, name, wire) for name, wire in wires]
    probes += [probe(pe, ranges, 7, name, wire) for name, wire in
               (("inner-short", b"\x04\x0e\x01\x01"),
                ("body-truncated", b"\x04" + raw[:6]),
                ("inner-declared-255", b"\x04" + raw[:1] + b"\xff" + raw[2:]),
                ("zero-event-length-next-packet", b"\x04\x0e\x00\x04" + raw))]
    for result in probes: check_probe(result)
    rejected = [w for w in wires if w[0] in ("header-checksum", "crc-error", "outer-short", "outer-long",
                                           "unexpected-sequence", "invalid-slip-escape")]
    recoveries = [dict(variant=label, trace=recover_bcsp(p, ranges, name, wire, chunk))
                  for label, p in variants.items() for name, wire in rejected for chunk in (None, 1)]
    recoveries += [dict(variant=label, trace=resume_h4(p, ranges, chunk))
                   for label, p in variants.items() for chunk in (None, 1, 7)]
    duplicates = [dict(variant=label, trace=duplicate_bcsp(p, ranges, chunk))
                  for label, p in variants.items() for chunk in (None, 1)]
    deps = ["verify_bt_rx_frames.py", "verify_bt_hci_completion.py", "verify_bt_transport.py",
            "draft_bt_transport_cleanup.py", "verify_bt_key_stack.py", "verify_bt_key_store.py",
            "draft_bt_key_iterator.py", "draft_bt_list_ack.py", "verify_bt_database_io.py",
            "verify_bt_pairing_storage.py", "verify_bt_pairing_ui.py", "draft_bt_pairing_storage.py",
            "draft_bt_database_io.py", "patch_bt_playback.py", "inspect_bt_pairing.py",
            "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Native BCSP SLIP/header/CRC and H4 RX framing through key-command completion",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  sources=sources, data=[dict(va=hex(at), bytes=n, raw_hex=pe.get_data(at - pe.OPTIONAL_HEADER.ImageBase, n).hex())
                                        for at, n in TABLES.items()], crc_entries_checked=256,
                  cases=cases, probes=probes, recoveries=recoveries, duplicates=duplicates,
                  cleanup_sha256=patch["draft_sha256"],
                  limitations=["Cold BCSP/H4 link/ready/parser state and lower serial reads are fixtures, not whole boot/power negotiation",
                               "BCSP TX ACKs are explicit parsed peer fixtures; RX SLIP/header/CRC/sequence run original bytes",
                               "Frame data is synthetic controller/UART traffic; radio injection or physical reachability is not established",
                               "Only HCI event traffic and key-command completion are coupled; ACL/SCO/other H4DS messages remain open",
                               "Scheduler order, allocation and file APIs are fixtures; heap bounds enforce requested sizes, not CE padding semantics",
                               "Resend/timers/concurrency/real serial driver/controller/unit and joint pairing release remain open"],
                  specifications=["https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Core-54/out/en/host-controller-interface/uart-transport-layer.html",
                                  "https://www.bluetooth.com/wp-content/uploads/Files/Specification/HTML/Core-54/out/en/host-controller-interface/three-wire-uart-transport-layer.html"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps})
    out = ROOT / "analysis/firmware/bt-rx-frames"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], cases=len(cases), probes=len(probes),
                         recoveries=len(recoveries), duplicates=len(duplicates),
                         outcomes=[dict(protocol=c["protocol"], name=c["name"], outcome=c["expected_outcome"], witness=c["witness"],
                                        events=len(c["events"]), state=c["rx_state"]) for c in probes]), indent=2))


if __name__ == "__main__": main()
