"""Interpret native artwork requests, original metadata parser and continuations.

Original request/factory/pending/result, response parser, continuation request and
payload destructor instructions execute. Peer/list lookup, profile timers, wire
delivery and JPEG/GUI publication are fixtures. No device or PE is modified.
"""
import argparse
from collections import deque
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_controller as controller
import bt_cover_art_metadata as metadata
import bt_cover_art_metadata_ticket as ticket
import bt_cover_art_task as task
from patch_bt_cover_attribute import BASE_SHA
from verify_bt_cover_metadata_ticket import MetadataFixture, PROFILE
from verify_bt_cover_controller import CHANNEL, TRACK, attributes, jpeg
from verify_bt_cover_responses import handshake
from verify_media_responsiveness import call
from inspect_bt_pairing import data, put

ROOT = Path(__file__).resolve().parents[1]
NATIVE = [(0x708cc, 0x70a64), (0x52aec, 0x52b90), (0x6a54c, 0x6a5b8),
          (0x52260, 0x522cc), (0x6f854, 0x6f970), (0x6b518, 0x6b580),
          (0x78a0c, 0x78bd4), (0x78bd4, 0x78bfc)]


@lru_cache(maxsize=1)
def assembled():
    return metadata.assembled()


def reply(kind=0, body=None, count=1, ctype=9):
    body = attributes()[1:] if body is None else body
    payload = (bytes([count])+body) if kind in (0, 1) else body
    prefix = bytearray.fromhex('00110e09480000195820000000')
    prefix[3], prefix[10] = ctype, kind
    prefix[11:13] = len(payload).to_bytes(2, 'big')
    return bytes(prefix)+payload


class IntegratedFixture(MetadataFixture):
    def __init__(self, original, enabled=True, success=True, bind=True):
        self.fail_metadata_alloc = None
        super().__init__(original, enabled=enabled, success=success)
        replaced = {r['address'] for r in assembled()}
        self.pe.helpers = [r for r in self.pe.helpers if r['address'] not in replaced]+assembled()
        self.ranges += NATIVE+[(r['address'], r['address']+len(r['raw'])) for r in assembled()]
        self.allowed += [(ticket.SLOT, ticket.SLOT+metadata.STATIC_SIZE)]
        put(self, ticket.SLOT, bytes(metadata.STATIC_SIZE))
        self.hooks.pop(controller.REQUEST_METADATA)
        self.hooks.update({0x78bfc: self.copy, 0x6a858: self.profile_timer,
                           0x6ae68: self.wire, 0x84ec8: self.profile_post})
        self.profile_requests, self.acks, self.continuations, self.profile_timers = deque(), [], [], []
        self.cfms, self.fragments = [], []
        self.fail_metadata_alloc = None
        if enabled:
            self.patches.update(metadata.sites(original.__data__))
        self.write(0x218656, 12, 2)
        self.enter_queue()
        if bind:
            assert call(self, metadata.SET_PEER, [self.state, 3])

    def allocate(self, m):
        if m.reg[4] == self.fail_metadata_alloc and metadata.REQUEST <= m.pc < metadata.RECEIVE+0xc00:
            self.fail_metadata_alloc = None
            return 0
        return super().allocate(m)

    def copy(self, m):
        pointer, source, size = m.reg[4:7]
        put(m, pointer, data(m, source, size))
        return pointer

    def profile_timer(self, m):
        context, pending, duration = m.reg[4:7]
        assert context == self.peer+0x18 and pending in self.pending and duration == 200000
        self.profile_timers.append(pending)
        return 0

    def wire(self, m):
        peer, length, pointer = m.reg[4:7]
        assert peer == self.peer and length == 14
        raw = data(m, pointer, length)
        assert raw[9] in (0x40, 0x41) and raw[13] == 0x20
        self.continuations.append(raw.hex())
        self.reg[4] = pointer
        self.free(self)
        return 0

    def profile_post(self, m):
        queue, event, pointer = m.reg[4:7]
        assert event == 0x11b
        primitive = m.read(pointer, 2)
        if primitive in (0x20c, 0x20d):
            assert queue == 12
            self.profile_requests.append(pointer)
            if primitive == 0x20c:
                self.metadata_requests.append((m.read(ticket.SLOT+8), m.read(ticket.SLOT+12)))
                assert data(m, pointer+6, 8) == bytes(8)
                assert m.read(pointer+14, 2) == 0
                assert m.read(pointer+16) == 128
            else:
                self.acks.append(dict(peer=m.read(pointer+2, 1), proceed=m.read(pointer+3, 1)))
            return 0
        assert primitive in (0x820d, 0x8224)
        row = dict(queue=queue, event=event, pointer=pointer, bytes_hex=data(m, pointer, 28 if primitive == 0x820d else 24).hex())
        if primitive == 0x820d:
            self.results.append(row)
            self.cfms.append(pointer)
        else:
            self.fragments.append(row)
        if queue == self.queue_id:
            self.messages.append((event, pointer))
        return 0

    def profile(self):
        self.enter_queue(12)
        while self.profile_requests:
            request = self.profile_requests.popleft()
            self.write(PROFILE+0xc, request)
            at = 0x53728 if self.read(request, 2) == 0x20c else 0x52260
            call(self, at, [PROFILE], limit=30000)
            self.reg[4] = request
            self.free(self)

    def start(self):
        assert self.prepare()
        assert self.open()
        self.connected()
        self.receive(handshake())
        self.credit()
        assert self.phase == controller.META
        assert self.metadata_requests == [(CHANNEL, TRACK)]
        self.profile()
        assert len(self.pending) == 1

    def response(self, raw, handle=True):
        self.enter_queue(12)
        source = self.new(raw)
        call(self, metadata.RESPONSE, [self.peer, self.pending[0], len(raw), source], limit=30000)
        self.reg[4] = source
        self.free(self)
        assert not self.read(ticket.SLOT+52)
        if handle:
            self.handle()

    def cleanup_result(self, pointer):
        self.enter_queue()
        call(self, metadata.SHUTDOWN, [pointer])
        call(self, metadata.CONTENT_FREE, [0x11b, pointer])
        self.reg[4] = pointer
        self.free(self)

    def deinit(self):
        assert not self.profile_requests and not self.pending
        self.reg[4] = self.peer
        self.free(self)
        # Native task DEINIT drains queued 0x11b contents and envelopes itself.
        super(MetadataFixture, self).deinit()
        assert data(self, ticket.SLOT, 32) == bytes(32)
        assert not self.read(ticket.SLOT+48)
        assert not self.read(ticket.SLOT+56) and not self.read(ticket.SLOT+60)


def verify(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    original = pefile.PE(data=raw)
    traces, comparisons = [], []

    def record(name, m):
        row = dict(case=name, phase=m.phase, requests=list(m.metadata_requests),
                   acks=m.acks, continuations=m.continuations,
                   fragments=len(m.fragments), finals=len(m.results), images=len(m.images),
                   bytes_assembled=m.read(ticket.SLOT+40), frames=m.read(ticket.SLOT+44))
        m.deinit()
        row['steps'] = m.steps
        traces.append(row)

    m = IntegratedFixture(original)
    m.start(); m.response(reply())
    assert m.phase == controller.GET and not m.pending and not m.acks
    assert m.requests[-1]['bytes_hex'].startswith('83')
    m.finish_image()
    assert m.visible == (CHANNEL, TRACK, jpeg())
    record('native_single_metadata_through_image_transfer', m)

    body = attributes()[1:]
    for split in range(len(body)+1):
        m = IntegratedFixture(original); m.start()
        m.response(reply(1, body[:split])); m.profile()
        assert m.acks == [dict(peer=3, proceed=1)]
        assert m.phase == controller.META
        m.response(reply(3, body[split:]))
        assert m.phase == controller.GET and m.read(ticket.SLOT+40) == len(body)
        assert m.read(ticket.SLOT+44) == 2
        record('native_fragmented_split_'+str(split), m)

    m = IntegratedFixture(original); m.start()
    m.response(reply(1, b'')); m.profile()
    for byte in body:
        m.response(reply(2, bytes([byte]))); m.profile()
    m.response(reply(3, b''))
    assert m.phase == controller.GET and m.read(ticket.SLOT+44) == len(body)+2
    assert all(r['proceed'] == 1 for r in m.acks)
    record('native_byte_fragments_with_original_continuation_requests', m)

    for raw_reply in (b'', b'x'*12, reply(0, b'')[:13], reply(1, b'')[:13], reply(0, b'x'*256)):
        m = IntegratedFixture(original); m.start(); m.response(raw_reply)
        assert m.phase == controller.FAILED and not m.field(64) and not m.pending
        record('native_short_or_oversize_guard_'+raw_reply.hex()[:32], m)

    m = IntegratedFixture(original); m.start()
    m.response(reply(1, b'')); m.profile()
    for _ in range(31):
        m.response(reply(2, b'')); m.profile()
    assert m.read(ticket.SLOT+44) == 32 and m.phase == controller.META
    m.response(reply(3, body))
    assert m.phase == controller.FAILED and not m.field(64)
    record('actual_32_fragment_budget_cannot_be_extended', m)

    m = IntegratedFixture(original); m.start()
    m.response(reply(1, body[:4]), handle=False)
    first = m.read(ticket.SLOT+48)
    m.response(reply(2, body[4:8]), handle=False)
    assert m.read(ticket.SLOT+48) == first and not m.read(ticket.SLOT+28)
    m.handle(); m.handle(); m.profile()
    assert m.acks == [dict(peer=3, proceed=0)]
    m.response(reply(3, body[8:]))
    assert m.phase == controller.META and not m.field(64)
    # An invalidated duplicate sequence cannot publish; the existing deadline
    # closes its session, while native final identity has already drained.
    m.due(3100)
    assert m.phase == controller.FAILED
    record('duplicate_native_interim_identity_fails_closed', m)

    for field, value, size in ((2, 4, 1), (3, 2, 1), (24, 13, 2)):
        m = IntegratedFixture(original); m.start(); m.response(reply(), handle=False)
        final = m.cfms[-1]; m.write(final+field, value, size)
        m.handle()
        assert m.phase == controller.FAILED and not m.field(64)
        record('native_final_header_mismatch_'+str(field), m)

    for raw_reply in (reply(body=b'', count=0), reply(1, b'', count=0)):
        m = IntegratedFixture(original); m.start(); m.response(raw_reply)
        if m.pending:
            m.profile(); m.response(reply(3, b''))
        assert m.phase == controller.READY and not m.field(64)
        record('native_no_art_'+str(raw_reply[10]), m)

    for ctype in (8, 10, 0, 15):
        m = IntegratedFixture(original); m.start(); m.response(reply(ctype=ctype))
        assert m.phase == controller.FAILED and not m.field(64)
        record('native_failed_final_status_'+str(ctype), m)

    malformed = [reply(3), reply(2), reply(count=2), reply(body=b'x'*256)]
    r = bytearray(reply()); r[9] = 0x21; malformed.append(bytes(r))
    r = bytearray(reply()); r[12] += 1; malformed.append(bytes(r))
    for index, r in enumerate(malformed):
        m = IntegratedFixture(original); m.start(); before=data(m, metadata.BUFFER, metadata.CAPACITY)
        m.response(r)
        assert m.phase == controller.FAILED and not m.field(64)
        assert data(m, metadata.BUFFER, metadata.CAPACITY) == before
        if m.pending:
            m.profile(); m.response(reply(3, b''))
        record('malformed_fragment_atomic_rejection_'+str(index), m)

    for mode in ('timer', 'track', 'disconnect'):
        m = IntegratedFixture(original); m.start(); m.response(reply(1, body[:6])); m.profile()
        if mode == 'timer': m.due(3100)
        elif mode == 'track': assert not m.select()
        else: m.enqueue(0x8206); m.handle()
        assert not m.read(ticket.SLOT+28) and m.read(ticket.SLOT+16) == 2
        # Invalidation retains the exact final identity through continuation/abort.
        m.response(reply(2, body[6:9])); m.profile()
        assert m.acks[-1] == dict(peer=3, proceed=0)
        assert bytes.fromhex(m.continuations[-1])[9] == 0x41
        m.response(reply(3, body[9:]))
        assert not m.field(64) and not m.read(ticket.SLOT+16)
        record('expired_identity_drains_'+mode, m)

    for capacity, frames in ((255, 0), (0, 32)):
        m = IntegratedFixture(original); m.start(); m.response(reply(1, b'')); m.profile()
        m.write(ticket.SLOT+40, capacity); m.write(ticket.SLOT+44, frames)
        before = data(m, metadata.BUFFER, metadata.CAPACITY)
        m.response(reply(2, b'x'))
        assert m.phase == controller.FAILED and m.acks[-1]['proceed'] == 0
        assert data(m, metadata.BUFFER, metadata.CAPACITY) == before
        m.profile(); m.response(reply(3, b''))
        record('bounded_fragment_limit_'+str(capacity)+'_'+str(frames), m)

    for alloc in (20, 4):
        m = IntegratedFixture(original)
        if alloc == 20:
            m.fail_metadata_alloc = alloc
            assert m.prepare(); assert m.open(); m.connected(); m.receive(handshake())
            assert m.phase == controller.FAILED and not m.profile_requests
        else:
            m.start(); m.fail_metadata_alloc = alloc
            m.response(reply(1, body[:5]))
            assert m.phase == controller.FAILED and not m.acks
            # Native profile timeout supplies the retained error confirmation.
            cfm = m.finish(); assert cfm == m.cfms[-1]
            m.handle()
        record('recoverable_metadata_allocation_failure_'+str(alloc), m)

    m = IntegratedFixture(original, success=False)
    assert m.prepare(); assert m.open(); m.connected(); m.receive(handshake()); m.profile(); m.handle()
    assert m.phase == controller.FAILED and not m.pending
    record('native_peer_lookup_failure_drains_and_cancels', m)

    m = IntegratedFixture(original, bind=False)
    assert m.prepare(); assert m.open(); m.connected(); m.receive(handshake())
    assert m.phase == controller.FAILED and not m.profile_requests
    record('no_selected_peer_refuses_native_request', m)

    m = IntegratedFixture(original); m.start()
    before = data(m, ticket.SLOT, metadata.STATIC_SIZE)
    m.enter_queue(12)
    assert not call(m, metadata.SET_PEER, [m.state, 4])
    assert data(m, ticket.SLOT, metadata.STATIC_SIZE) == before
    m.enter_queue()
    assert not call(m, metadata.SET_PEER, [m.state, 4])
    assert not call(m, metadata.SET_PEER, [m.state, 256])
    m.response(reply()); record('foreign_or_pending_peer_rebind_refused', m)

    m = IntegratedFixture(original); m.start(); m.response(reply(), handle=False)
    assert len(m.messages) == 1
    posted_before = len(m.profile_requests)
    record('shutdown_drains_final_payload_without_controller_or_post', m)
    assert len(m.profile_requests) == posted_before == 0

    m = IntegratedFixture(original); m.start(); m.response(reply(1, body[:4]), handle=False)
    # Profile shutdown/timeout posts the final before the artwork task drain.
    m.finish()
    assert len(m.messages) == 2 and not m.acks
    record('shutdown_drains_interim_and_final_without_ack', m)
    assert not m.acks and not m.profile_requests

    # Original seven-attribute route receives byte-identical interim/final replies.
    for fragmented in (False, True):
        sides=[]
        for enabled in (False, True):
            m=IntegratedFixture(original, enabled=enabled)
            p=m.request(queue=7, mask=127); m.execute(p)
            raw_packets=[reply()] if not fragmented else [reply(1, body[:5]), reply(3, body[5:])]
            for r in raw_packets:
                source=m.new(r); m.enter_queue(12)
                call(m, metadata.RESPONSE if enabled else metadata.ORIGINAL_RESPONSE,
                     [m.peer, m.pending[0], len(r), source], limit=30000)
                m.reg[4]=source; m.free(m)
            objects=m.fragments+m.results
            sides.append([dict(queue=r['queue'], bytes_hex=r['bytes_hex'],
                               payload=data(m, m.read(r['pointer']+16), m.read(r['pointer']+14, 2)).hex()) for r in objects])
            for r in objects: m.cleanup_result(r['pointer'])
            assert not m.read(ticket.SLOT+16)
            record('legacy_'+str(fragmented)+'_'+str(enabled), m)
        assert sides[0] == sides[1]
        comparisons.append(dict(fragmented=fragmented, original=sides[0], integrated=sides[1]))

    names=['bt_cover_art_metadata.py', 'verify_bt_cover_metadata.py',
           'bt_cover_art_metadata_ticket.py', 'bt_cover_art_timers.py', 'bt_cover_art_controller.py']
    return dict(schema=1, baseline_sha256=BASE_SHA, cases=len(traces), traces=traces,
                legacy_comparisons=comparisons,
                sites={hex(k):hex(v) for k,v in metadata.sites(raw).items()},
                helpers=[dict(address=hex(r['address']), bytes=len(r['raw']), sha256=hashlib.sha256(r['raw']).hexdigest(), purpose=r['purpose']) for r in assembled()],
                limits=['MIPS interpretation, not native execution, emulation, a Bluetooth connection or hardware testing',
                        'Original profile lookup/list operations, profile timer scheduling, wire delivery, selected peer and OS allocation remain fixtures',
                        'Controller request, actual metadata parser/factories, native continuation command, deadline rejection and task content cleanup are connected',
                        'Static slot is serialized in CSR segment zero; profile shutdown must quiesce before artwork owner release',
                        'Attribute-8 serializer loop patch is separately verified and still required on firmware',
                        'Native discovery/security/track hooks, CE JPEG publication and PE placement/relocation/unwind remain missing; no LGU is produced'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__ == '__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args=parser.parse_args()
    if args.report.exists(): raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_bytes((json.dumps(result, indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=result['cases'], legacy_comparisons=len(result['legacy_comparisons']),
                          native_metadata_bound=True, lgu_ready=False), indent=2))
