"""Interpret the separate owner and original CSR ACK/disconnect/free constructors.

Allocations, posting and the synchronous protocol consumer remain fixtures.
Tracks each incoming envelope/payload and outgoing primitive, rejects double free,
use after free and writes outside owner/heap/stack. No executable is changed.
"""
import argparse
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_owner as owner
from patch_bt_cover_attribute import BASE_SHA
from inspect_bt_lifecycle import SliceVM
from inspect_bt_pairing import data, put
from verify_bt_cover_csr_bridge import VM
from verify_media_responsiveness import call, STACK

ROOT = Path(__file__).resolve().parents[1]
STATE, PEER, SENTINEL = 0x41000000, 0x42000000, 0x43000000
CID, OLD_CID = 0x400040, 0x400030
PEER_BYTES = bytes.fromhex('4433221188776655')
NATIVE_RANGES = [(0x50c04, 0x50c48), (0x50cd4, 0x50d08), (0x77f48, 0x78070)]


class Image:
    def __init__(self, original, helpers):
        self.original, self.helpers = original, helpers
        self.OPTIONAL_HEADER = original.OPTIONAL_HEADER

    def get_data(self, rva, size):
        address = rva+self.OPTIONAL_HEADER.ImageBase
        for row in self.helpers:
            offset = address-row['address']
            if 0 <= offset and offset+size <= len(row['raw']):
                return row['raw'][offset:offset+size]
        return self.original.get_data(rva, size)


class Fixture(VM):
    def __init__(self, original, helpers, accept=True):
        self.heap = {}
        self.next_heap = 0x44000000
        self.operations, self.delivered, self.posted = [], [], []
        self.accept = accept
        self.allowed = [(STATE-4, STATE+owner.SIZE+4), (PEER, PEER+8),
                        (SENTINEL, SENTINEL+0x180), (STACK-0x600, STACK+0x80)]
        super().__init__(Image(original, helpers), NATIVE_RANGES+
                         [(r['address'], r['address']+len(r['raw'])) for r in helpers])
        put(self, STATE-4, bytes.fromhex('a55aa55a')+bytes(owner.SIZE)+bytes.fromhex('a55aa55a'))
        put(self, PEER, PEER_BYTES)
        for offset in range(0x180):  # Existing AVRCP peer, immutable after setup.
            SliceVM.write(self, SENTINEL+offset, 0x9d, 1)
        self.hooks.update({0x85b70: self.allocate, 0x85bb8: self.free,
                           0x782a8: self.post, owner.NOTIFY: self.notify,
                           0x7a38c: self.other_contents})

    def permitted(self, at, size):
        for lo, (n, live) in self.heap.items():
            if lo <= at and at+size <= lo+n:
                assert live, ('Use after free', hex(at))
                return True
        return any(lo <= at and at+size <= hi for lo, hi in self.allowed)

    def read(self, at, size=4):
        assert self.permitted(at, size), ('Read outside fixture', hex(at), size)
        return super().read(at, size)

    def plain(self, word):
        if word >> 26 == 0 and word & 63 == 0x2a:
            rs, rt, rd = (word >> 21)&31, (word >> 16)&31, (word >> 11)&31
            signed = lambda value: value if value < 0x80000000 else value-0x100000000
            self.reg[rd] = int(signed(self.reg[rs]) < signed(self.reg[rt]))
            self.reg[0] = 0
        else:
            super().plain(word)

    def write(self, at, value, size=4):
        assert self.permitted(at, size), ('Write outside fixture', hex(at), size)
        assert not SENTINEL <= at < SENTINEL+0x180, 'Existing AVRCP peer touched'
        super().write(at, value, size)

    def new(self, raw):
        address = self.next_heap
        self.next_heap += max(0x100, ((len(raw)+255)//256)*256)
        self.heap[address] = (len(raw), True)
        put(self, address, raw)
        return address

    def allocate(self, m):
        size = m.reg[4]
        assert size in (8, 12), ('Unexpected native allocation', size)
        return self.new(bytes([0xcc])*size)

    def free(self, m):
        pointer = m.reg[4]
        if pointer:
            assert pointer in self.heap and self.heap[pointer][1], ('Double/invalid free', hex(pointer))
            size, _ = self.heap[pointer]
            self.heap[pointer] = (size, False)
            self.operations.append(('free', pointer))
        return 0

    def post(self, m):
        pointer = m.reg[4]
        primitive, cid = m.read(pointer, 2), m.read(pointer+4)
        assert primitive in (0x22e, 0x10c)
        if primitive == 0x10c:
            assert m.read(pointer+8, 2) == 0
        self.operations.append(('ack' if primitive == 0x22e else 'disconnect', cid))
        self.posted.append(pointer)
        # Posting transfers ownership; the fixture CM immediately consumes it.
        self.free(m)
        return 0

    def notify(self, m):
        state, event, pointer, size = m.reg[4:8]
        assert state == STATE and event in (1, 2, 3, 4)
        raw = data(m, pointer, size) if size else b''
        if event != 2:
            assert pointer == size == 0
        self.operations.append(('notify', event))
        self.delivered.append((event, raw))  # Owned copy before buffer free.
        return int(self.accept)

    def other_contents(self, m):
        self.operations.append(('generic_contents', m.reg[4]))
        return 0  # Non-DataIND fixtures have no nested allocations.

    def arm(self, psm=0x1001, peer=PEER):
        return call(self, owner.ARM, [STATE, peer, psm])

    def stop(self):
        call(self, owner.STOP, [STATE])

    def message(self, kind, cid=CID, psm=0x1001, mtu=1024, result=0, supplier=12,
                payload=b'\xa0\x00\x03', peer=PEER_BYTES, event=0x104, pointer=None, length=None):
        body = self.new(bytes(0x20))
        self.write(body, kind, 2)
        self.write(body+4, cid)
        source = None
        if kind == 0x8201:
            self.write(body+8, psm, 2)
            self.write(body+10, mtu, 2)
            put(self, body+16, peer)
            self.write(body+24, result, 2)
            self.write(body+26, supplier, 2)
        elif kind == 0x8205:
            source = self.new(payload) if payload else None
            self.write(body+8, len(payload) if length is None else length, 2)
            self.write(body+12, (source or 0) if pointer is None else pointer)
        elif kind == 0x8204:
            self.write(body+10, result, 2)
        call(self, owner.DISPATCH, [STATE, event, body])
        assert not self.heap[body][1], 'Message envelope leaked'
        if source is not None and pointer is None:
            assert not self.heap[source][1], 'Receive payload leaked'
        assert self.read(STATE-4) == self.read(STATE+owner.SIZE) == 0x5aa55aa5
        assert data(self, SENTINEL, 0x180) == bytes([0x9d])*0x180
        return source

    def assert_drained(self):
        assert all(not live for _, live in self.heap.values()), 'Allocated fixture object leaked'


def verify(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    original, helpers = pefile.PE(data=raw), owner.assembled()
    traces = []

    def fresh(accept=True):
        return Fixture(original, helpers, accept)

    def record(name, m):
        m.assert_drained()
        traces.append(dict(case=name, phase=m.read(STATE), cid=hex(m.read(STATE+4)),
                           steps=m.steps, notifications=[event for event, _ in m.delivered],
                           operations=[(kind, hex(value)) for kind, value in m.operations]))

    for psm in (0, 0x17, 0x1b, 0xfff, 0x1000, 0x1001, 0x1003, 0x1101, 0xffff, 0x10001):
        m = fresh()
        valid = psm in (0x1001, 0x1003)
        assert bool(m.arm(psm)) == valid
        if valid:
            initial = data(m, STATE, owner.SIZE)
            assert not m.arm(0x1003) and data(m, STATE, owner.SIZE) == initial
            m.stop()
            assert m.read(STATE) == owner.CANCELLED and not m.arm()
            m.message(0x8201, psm=psm, result=1)
            assert m.read(STATE) == owner.IDLE
        record('arm_psm_'+hex(psm), m)
    for phase in (owner.OPENING, owner.ACTIVE, owner.CLOSING, owner.CANCELLED):
        m = fresh()
        m.write(STATE, phase)
        before = data(m, STATE, owner.SIZE)
        assert not m.arm() and data(m, STATE, owner.SIZE) == before
        record('refuse_busy_'+str(phase), m)
    for peer in (0, PEER+1):
        m = fresh()
        assert not m.arm(peer=peer)
        record('refuse_peer_'+hex(peer), m)

    for accept in (False, True):
        for cancelled in (False, True):
            for mtu in (0, 254, 255, 1024, 65535):
                m = fresh(accept)
                assert m.arm()
                if cancelled: m.stop()
                m.message(0x8201, mtu=mtu)
                active = accept and not cancelled and mtu >= 255
                assert m.read(STATE) == (owner.ACTIVE if active else owner.CLOSING)
                assert sum(kind == 'disconnect' for kind, _ in m.operations) == int(not active)
                m.message(0x8201, mtu=mtu)  # Duplicate CFM cannot cause a second close.
                m.stop(); m.stop()
                assert sum(kind == 'disconnect' for kind, _ in m.operations) == 1
                assert not m.arm()
                m.message(0x8206, cid=OLD_CID)
                assert m.read(STATE) == owner.CLOSING
                m.message(0x8206)
                assert m.read(STATE) == owner.IDLE and m.read(STATE+4) == 0
                m.message(0x8206)  # Duplicate close doesn't publish twice.
                assert sum(event == 3 for event, _ in m.delivered) == 1
                assert m.arm(0x1003)
                record(f'open_close_{accept}_{cancelled}_{mtu}', m)

    for result, supplier in ((1, 12), (0, 11), (0x800a, 0x11)):
        for cancelled in (False, True):
            m = fresh()
            assert m.arm()
            if cancelled: m.stop()
            m.message(0x8201, result=result, supplier=supplier)
            assert m.read(STATE) == owner.IDLE and m.delivered == [(4, b'')]
            assert not any(kind == 'disconnect' for kind, _ in m.operations)
            record(f'connect_failure_{result}_{supplier}_{cancelled}', m)
    for phase in (owner.IDLE, owner.OPENING, owner.ACTIVE, owner.CLOSING, owner.CANCELLED):
        for mismatch in ('psm', 'peer'):
            m = fresh()
            m.write(STATE, phase); m.write(STATE+4, CID if phase in (2, 3) else 0)
            m.write(STATE+8, 0x1001, 2); put(m, STATE+12, PEER_BYTES)
            before = data(m, STATE, owner.SIZE)
            m.message(0x8201, cid=OLD_CID, psm=0x1003 if mismatch == 'psm' else 0x1001,
                      peer=bytes(8) if mismatch == 'peer' else PEER_BYTES)
            assert data(m, STATE, owner.SIZE) == before and not m.delivered
            assert ('disconnect', OLD_CID) in m.operations
            record(f'orphan_{phase}_{mismatch}', m)

    for phase in range(5):
        for cid in (CID, OLD_CID):
            for length in (0, 1, 3, 8192, 8193):
                for accept in (False, True):
                    m = fresh(accept)
                    m.write(STATE, phase); m.write(STATE+4, CID)
                    source = m.message(0x8205, cid=cid, payload=b'x'*length)
                    expected = phase == owner.ACTIVE and cid == CID and 0 < length <= 8192
                    assert bool(m.delivered) == expected
                    if expected:
                        assert m.delivered == [(2, b'x'*length)]
                        assert m.operations.index(('notify', 2)) < m.operations.index(('free', source))
                    assert sum(kind == 'ack' for kind, _ in m.operations) == 1
                    close = phase == owner.ACTIVE and cid == CID and (length > 8192 or length and not accept)
                    assert sum(kind == 'disconnect' for kind, _ in m.operations) == int(bool(close))
                    record(f'rx_{phase}_{cid}_{length}_{accept}', m)
    m = fresh()
    m.write(STATE, owner.ACTIVE); m.write(STATE+4, CID)
    m.message(0x8205, payload=b'', length=1)
    assert m.read(STATE) == owner.CLOSING
    record('null_rx_payload_closes', m)

    for phase in range(5):
        for cid in (CID, OLD_CID):
            for result in (0, 1):
                m = fresh()
                m.write(STATE, phase); m.write(STATE+4, CID)
                m.message(0x8204, cid=cid, result=result)
                close = phase == owner.ACTIVE and cid == CID and result != 0
                assert sum(kind == 'disconnect' for kind, _ in m.operations) == int(close)
                record(f'tx_cfm_{phase}_{cid}_{result}', m)
    for event, kind in ((0x104, 0x820a), (0x104, 0x8202), (0x999, 1)):
        m = fresh()
        m.message(kind, event=event)
        assert not m.delivered
        record(f'other_{event}_{kind}', m)
    m = fresh()
    call(m, owner.DISPATCH, [STATE, 0x104, 0])
    record('null_envelope', m)

    return dict(cases=len(traces), traces=traces, binary_input_sha256=BASE_SHA,
                helpers=[dict(address=hex(r['address']), purpose=r['purpose'],
                              used_bytes=r['recipe']['used_bytes'], assembly=r['recipe'],
                              bytes_hex=r['raw'].hex(), relocation_recipe=r['relocations']) for r in helpers],
                original_slices=[dict(start=hex(lo), end=hex(hi), sha256=hashlib.sha256(
                    original.get_data(lo-original.OPTIONAL_HEADER.ImageBase, hi-lo)).hexdigest())
                    for lo, hi in NATIVE_RANGES],
                firmware_patched=False, native_executed=False, task_registered=False, lgu_built=False,
                limits=['New owner instructions and original ACK/disconnect/CM-content cleanup slices are interpreted',
                        'Allocator, CM posting, generic non-DataIND destructor and consumer notifications are fixtures',
                        'Trusted complete primitive layouts, one serialized queue and one outstanding connect are required',
                        'ARM records a submitted connect; no outgoing connect constructor or task hooks installed',
                        'STOP retains storage while opening/closing; a stalled open deliberately prevents reuse',
                        'No owner destruction before task shutdown/drain; no OBEX parser, TX ownership, timers or AppMain wiring',
                        'Preferred-image-base interpretation only; export addresses are not selected PE placements'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_owner.py', 'verify_bt_cover_owner.py', 'verify_bt_cover_csr_bridge.py',
                              'verify_bt_cover_attribute.py', 'patch_bt_cover_attribute.py',
                              'patch_usb_seek_completion.py', 'patch_usb_folders.py', 'patch_usb_reliability.py',
                              'patch_updater_copy_safety.py', 'inspect_wave_queue.py', 'inspect_bt_lifecycle.py',
                              'verify_media_responsiveness.py')})


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    if args.report.exists():
        raise FileExistsError('Use a fresh report')
    result = verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'], firmware_patched=False, task_registered=False), indent=2))
