"""Interpret bounded SDP helpers and the original discovery callback.

Allocator/posting, SDP profile-field parsers and list cleanup are explicit
fixtures. No physical SDP delivery, executable or LGU is claimed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct

import pefile

import bt_cover_art_discovery as d
from bt_cover_art_client import ArtworkError
from bt_cover_art_session import parse_service
from inspect_bt_lifecycle import SliceVM
from inspect_bt_pairing import data, put
from verify_bt_cover_owner import Image
from verify_bt_cover_csr_bridge import VM
from verify_media_responsiveness import call, STACK
from inspect_wave_queue import STOP

ROOT = Path(__file__).resolve().parents[1]
INPUT, OUTPUT, LIST, RECORD = 0x41000000, 0x42000000, 0x43000000, 0x43001000
PEER, CONFIG, CONTEXT = 0x44000000, 0x44001000, 0x44002000


def uint(value, width=2):
    return bytes([8 | {1: 0, 2: 1, 4: 2, 8: 3, 16: 4}[width]]) + value.to_bytes(width, 'big')


def uuid(value, width=2):
    if width == 16:
        return b'\x1c' + value.to_bytes(4, 'big') + bytes.fromhex('00001000800000805f9b34fb')
    return bytes([0x18 | {2: 1, 4: 2}[width]]) + value.to_bytes(width, 'big')


def seq(raw, length_width=None):
    width = length_width or (1 if len(raw) < 256 else 2)
    return bytes([0x35 + {1: 0, 2: 1, 4: 2}[width]]) + len(raw).to_bytes(width, 'big') + raw


def protocols(psm=0x1001, left=2, right=2, transport=8, psm_width=2, extra=b''):
    return seq(seq(uuid(0x100, left)+uint(psm, psm_width)+extra)+seq(uuid(transport, right)))


def service(value):
    return seq(uint(1)+seq(uuid(0x110c))+uint(9)+seq(seq(uuid(0x110e)+uint(0x106)))+
               uint(0x311)+uint(0x100)+uint(13)+value)


def expected(value):
    try:
        result = parse_service(service(value))
        return result.psm if result else 0
    except ArtworkError:
        return 0


class Fixture(VM):
    def __init__(self, original, helpers):
        self.allowed = [(STACK-0x1000, STACK+0x80)]
        self.readonly = []
        self.reads, self.writes, self.posts = [], [], []
        self.events = []
        self.alloc_fail = False
        self.heap = {}
        self.next_heap = 0x45000000
        self.csr_freed = False
        super().__init__(Image(original, helpers), [(0x58cbc, 0x5902c), (d.ORIGINAL, 0x5861c),
            (0x688d8, 0x688f4), (0x688f4, 0x68944),
            (0x66cd0, 0x66d6c), (0x66d6c, 0x66f30), (0x669e4, 0x66a78),
            (0x68b94, 0x68bfc)]+[(r['address'], r['address']+len(r['raw'])) for r in helpers])
        self.map(OUTPUT, bytes([0xa5])*16)
        self.map(d.QUEUE, struct.pack('<H', 20))
        self.hooks.update({0x8ad7c: self.allocate, 0x84ec8: self.post, 0x85758: self.copy})

    def map(self, pointer, raw, readonly=False):
        self.allowed.append((pointer, pointer+len(raw)))
        for i, byte in enumerate(raw):
            SliceVM.write(self, pointer+i, byte, 1)
        if readonly:
            self.readonly.append((pointer, pointer+len(raw)))

    def permitted(self, at, size):
        return any(lo <= at and at+size <= hi for lo, hi in self.allowed)

    def read(self, at, size=4):
        assert self.permitted(at, size), ('Read beyond allocation', hex(at), size)
        if self.csr_freed:
            assert not LIST <= at < RECORD+0x10000, 'Borrowed result used after native cleanup'
        self.reads.append((at, size))
        return super().read(at, size)

    def write(self, at, value, size=4):
        assert self.permitted(at, size), ('Write beyond allocation', hex(at), size)
        assert not any(lo < at+size and at < hi for lo, hi in self.readonly), 'Borrowed input changed'
        self.writes.append((at, size))
        super().write(at, value, size)

    def copy(self, m):
        dst, src, size = m.reg[4:7]
        put(m, dst, data(m, src, size))
        return dst

    def allocate(self, m):
        assert m.reg[4] == d.MESSAGE_SIZE
        if self.alloc_fail:
            self.events.append('allocation_failed')
            return 0
        pointer = self.next_heap
        self.next_heap += 0x100
        self.map(pointer, bytes([0xa5])*d.MESSAGE_SIZE)
        self.heap[pointer] = True
        self.events.append('allocated')
        return pointer

    def post(self, m):
        queue, event, pointer = m.reg[4:7]
        assert self.heap[pointer]
        assert (queue, event) == (20, d.CLASS)
        assert not self.csr_freed
        self.posts.append(data(m, pointer, d.MESSAGE_SIZE))
        self.events.append('posted_before_sdp_free')
        # Emulate ownership transfer to the queue. The later task owns/frees it.
        self.heap[pointer] = False
        return 0

    def sdp(self, value, count=1, record_type=2, prefix=b'', duplicate=False):
        def node(aid, raw):
            body = bytes(10)+uint(aid)+raw
            out = bytearray(struct.pack('<H', len(body))+body)
            struct.pack_into('<H', out, 4, aid)
            return bytes(out)
        nodes = (node(0x100, prefix) if prefix else b'') + node(13, value)
        if duplicate:
            nodes += node(13, value)
        start = 0x1a if record_type == 2 else 0x26
        record = bytearray(start)+nodes
        struct.pack_into('<HH', record, 0x12, count+int(bool(prefix))+int(duplicate), record_type)
        self.map(RECORD, record, True)
        self.map(LIST, struct.pack('<IHHI', RECORD, len(record), 0, 0), True)
        return record

    def peer(self, version=0x106, features=0x100, security=0x80):
        self.map(PEER, bytes(0x130))
        self.map(CONFIG, bytes(0xb0))
        put(self, PEER+8, bytes.fromhex('4433221188776655'))
        self.write(PEER+0x10, 7, 1)
        self.write(PEER+0xc8, version, 2)
        self.write(PEER+0xca, features, 2)
        self.write(PEER+0x11c, CONFIG)
        self.write(CONFIG+0x9a, security, 2)

    def callback(self, value, enabled=True, target=True, version=0x106, features=0x100,
                 security=0x80, result=0, supplier=12, alloc_fail=False):
        self.sdp(value)
        self.peer(version, features, security)
        self.map(CONTEXT, bytes(0x90))
        self.write(CONTEXT+0x20, 1, 1)
        self.write(CONTEXT+0x78, 0x106, 2)
        self.write(PEER+0x60, 1, 1)
        self.alloc_fail = alloc_fail
        if enabled:
            self.patches[d.SITE] = (3 << 26) | (d.WRAP >> 2)
        def find(m):
            assert (m.reg[4], m.reg[5]) == (CONTEXT+0x7c, 8)
            assert data(m, m.reg[6], 8) == bytes.fromhex('4433221188776655')
            return PEER
        def clear(m):
            put(m, m.reg[4], bytes(20))
            return 0
        def profile(m):
            m.write(m.reg[6], version, 2)
            return 1
        def feature(m):
            assert m.reg[6] == 0x311
            m.write(m.reg[7], features)
            return 1
        def identify(m):
            m.write(m.reg[6], 0x110c if target else 0x110e)
            m.write(m.reg[7], 0, 2)
            return 1
        def cleanup(m):
            assert m.read(m.reg[4]) == LIST
            assert m.reg[5] == 0x68d8c
            self.events.append('original_sdp_cleanup')
            self.csr_freed = True
            m.write(m.reg[4], 0)
            return 0
        self.hooks.update({0x68d28: find, 0x78c34: clear, 0x582e4: profile, 0x67edc: feature,
                           0x67f4c: lambda m: 0, 0x66a78: identify, 0x689a8: cleanup})
        ret = call(self, 0x58cbc, [CONTEXT, LIST, 0x11223344, 0x55667788], [result, supplier], limit=40000)
        assert self.csr_freed
        assert self.read(CONTEXT+0x20, 1) == 0
        assert self.read(PEER+0x60, 1) == 2
        assert not any(self.heap.values()), 'Optional message leaked before posting'
        return dict(return_value=ret, peer=data(self, PEER, 0x130).hex(),
                    context=data(self, CONTEXT, 0x90).hex())


def verify(raw):
    recipe = d.hook_recipe(raw)
    original, helpers = pefile.PE(data=raw), d.assembled()
    parser_cases, reader_cases, extract_cases, callback_cases = [], 0, [], []
    values = []
    for left in (2, 4, 16):
        for right in (2, 4, 16):
            for length_width in (1, 2, 4):
                values += [(f'uuid-{left}-{right}-length-{length_width}', seq(protocols(left=left, right=right), length_width))]
    values += [('browsing_then_art', seq(protocols(psm=0x1b, transport=0x17)+protocols())),
               ('art_then_browsing', seq(protocols()+protocols(psm=0x1b, transport=0x17))),
               ('empty', seq(b'')), ('duplicate', seq(protocols()+protocols())),
               ('different_candidates', seq(protocols()+protocols(psm=0x1003))),
               ('wrong_psm_width', seq(protocols(psm_width=4))),
               ('extra_parameter', seq(protocols(extra=uint(1)))),
               ('bad_uuid_base', seq(protocols(left=16).replace(bytes.fromhex('5f9b34fb'), b'BAD!'))),
               ('non_sequence_descriptor', seq(seq(uint(1)+seq(uuid(8)))))]
    for psm in (0, 1, 0xfff, 0x1000, 0x1001, 0x1002, 0x1003, 0x10ff, 0x1101, 0xffff):
        values += [(f'psm-{psm:04x}', seq(protocols(psm)))]
    full = seq(protocols(left=16, right=16))
    values += [(f'truncated-{i}', full[:i]) for i in range(len(full))]
    nested = uint(1)
    for depth in range(12):
        nested = seq(nested)
        values += [(f'nesting-{depth+1}', nested)]
    values += [('node_budget', seq(b'\x00'*513)), ('max_input', seq(b'\x00'*4092)),
               ('oversize_input', seq(b'\x00'*4097)), ('length_overflow', bytes.fromhex('37ffffffff'))]
    rng = random.Random(0x705)
    values += [(f'mutation-{i}', bytes(bytearray(full[:at])+bytes([value])+full[at+1:]))
               for i, (at, value) in enumerate((rng.randrange(len(full)), rng.randrange(256)) for _ in range(300))]
    for name, value in values:
        m = Fixture(original, helpers)
        if value:
            m.map(INPUT, value, True)
        result = call(m, d.PSM, [INPUT, len(value)], limit=100000)
        assert result == expected(value), (name, hex(result), hex(expected(value)))
        assert data(m, OUTPUT, 16) == bytes([0xa5])*16
        parser_cases.append(dict(case=name, bytes=len(value), psm=result, steps=m.steps))
    # Every possible DE tag, including malformed and unsupported width pairs.
    for tag in range(256):
        for size in (0, 1, 2, 4, 8, 16, 20):
            payload = bytes([tag])+bytes(size)
            m = Fixture(original, helpers)
            m.map(INPUT, payload, True)
            before = data(m, OUTPUT, 16)
            result = call(m, d.READ, [INPUT, INPUT+len(payload), OUTPUT])
            if not result:
                assert data(m, OUTPUT, 16) == before
            else:
                kind, width, pointer = struct.unpack('<III', data(m, OUTPUT, 12))
                assert kind < 9 and pointer+width == result <= INPUT+len(payload)
                assert data(m, OUTPUT+12, 4) == before[12:]
            reader_cases += 1
    for label, cursor, end, out in [('null', 0, 1, OUTPUT), ('equal', INPUT, INPUT, OUTPUT),
            ('reversed', INPUT, INPUT-1, OUTPUT), ('null_out', INPUT, INPUT+1, 0),
            ('unaligned_out', INPUT, INPUT+1, OUTPUT+1), ('wrapped_out', INPUT, INPUT+1, 0xfffffffc)]:
        m = Fixture(original, helpers)
        m.map(INPUT, b'\x00', True)
        assert call(m, d.READ, [cursor, end, out]) == 0, label
        reader_cases += 1
    for record_type in (2, 4):
        for prefix in (b'', seq(uuid(1))):
            for duplicate in (False, True):
                m = Fixture(original, helpers)
                m.sdp(full, record_type=record_type, prefix=prefix, duplicate=duplicate)
                result = call(m, d.EXTRACT, [LIST, 0, OUTPUT])
                assert bool(result) == (not duplicate)
                if result:
                    assert m.read(OUTPUT, 2) == len(full)
                    assert data(m, result, len(full)) == full
                extract_cases.append(dict(type=record_type, prefix=bool(prefix), duplicate=duplicate, accepted=bool(result)))
    native_layout_cases = 0
    # Cross-check the actual retained CSR getters against the constructed
    # borrowed representation; only memcpy is a fixture here.
    for record_type in (2, 4):
        for prefix in (b'', seq(uuid(1)), b'odd'):
            m = Fixture(original, helpers)
            m.sdp(full, record_type=record_type, prefix=prefix)
            assert call(m, 0x66cd0, [LIST, 0, OUTPUT]) == 1
            assert m.read(OUTPUT) == 1+int(bool(prefix))
            assert call(m, 0x669e4, [LIST, 0, OUTPUT+4]) == 1
            assert m.read(OUTPUT+4, 2) == record_type
            pointer = call(m, 0x66d6c, [LIST, 0, int(bool(prefix)), OUTPUT+8])
            assert pointer == RECORD+m.read(OUTPUT+8, 2)
            assert data(m, pointer+12, 3) == uint(13)
            assert data(m, pointer+15, len(full)) == full
            extracted = call(m, d.EXTRACT, [LIST, 0, OUTPUT+12])
            assert extracted == pointer+15
            assert m.read(OUTPUT+12, 2) == len(full)
            native_layout_cases += 1
    # Claimed node or record lengths never authorize a read beyond their bounds.
    for mutation in ('short_record', 'short_node', 'long_node', 'bad_type', 'too_many', 'bad_aid', 'odd_node'):
        m = Fixture(original, helpers)
        record = bytearray(m.sdp(full))
        m.readonly.clear()
        if mutation == 'short_record': m.write(LIST+4, 20, 2)
        if mutation == 'short_node': m.write(RECORD+0x1a, 12, 2)
        if mutation == 'long_node': m.write(RECORD+0x1a, 0xffff, 2)
        if mutation == 'bad_type': m.write(RECORD+0x14, 3, 2)
        if mutation == 'too_many': m.write(RECORD+0x12, 33, 2)
        if mutation == 'bad_aid': m.write(RECORD+0x1a+14, 12, 1)
        if mutation == 'odd_node': m.write(LIST, RECORD+1)
        assert call(m, d.EXTRACT, [LIST, 0, OUTPUT]) == 0, mutation
        assert data(m, OUTPUT, 16) == bytes([0xa5])*16
        extract_cases.append(dict(case=mutation, accepted=False))
    m = Fixture(original, helpers)
    m.sdp(full)
    m.readonly.clear()
    high_record = bytearray(26)
    struct.pack_into('<HH', high_record, 0x12, 1, 4)
    m.map(0xffffffe0, high_record, True)
    m.write(LIST, 0xffffffe0)
    m.write(LIST+4, len(high_record), 2)
    assert call(m, d.EXTRACT, [LIST, 0, OUTPUT]) == 0
    extract_cases.append(dict(case='long_header_pointer_wrap', accepted=False))
    for target in (False, True):
        for version, features in ((0x104, 0x100), (0x106, 0), (0x106, 0x100)):
            for security in (0, 0x80, 0xffff):
                for alloc_fail in (False, True):
                    outputs = []
                    for enabled in (False, True):
                        m = Fixture(original, helpers)
                        outputs.append(m.callback(full, enabled, target, version, features, security,
                                                  alloc_fail=alloc_fail))
                        should_post = enabled and target and version >= 0x106 and features&0x100 and not alloc_fail
                        assert len(m.posts) == int(bool(should_post))
                        if should_post:
                            expected_message = struct.pack('<HHIIHHHHI', 1, 7, 0x11223344, 0x55667788,
                                                           0x1001, security, version, features, 0)
                            assert m.posts == [expected_message]
                            assert m.events.index('posted_before_sdp_free') < m.events.index('original_sdp_cleanup')
                        if enabled:
                            callback_cases.append(dict(target=target, version=version, features=features,
                                                       security=security, allocation_failed=alloc_fail,
                                                       posts=len(m.posts), events=m.events, steps=m.steps))
                    assert outputs[0] == outputs[1], 'Original callback output/peer state changed'
    wrapper_cases = []
    # Execute the original six-argument parser through WRAP with both text
    # outputs present. This checks its relocated fifth/sixth arguments and
    # original return, even though 58cbc does not consume that return value.
    for fail_optional in (False, True):
        outputs = []
        for entry in (d.ORIGINAL, d.WRAP):
            m = Fixture(original, helpers)
            m.sdp(full)
            m.peer()
            m.map(INPUT, b'ProviderService', True)
            m.alloc_fail = fail_optional
            def legacy_allocate(v):
                size = v.reg[4]
                assert size in (8, 9)
                ptr = v.next_heap
                v.next_heap += 0x100
                v.map(ptr, bytes([0xa5])*size)
                return ptr
            def version(v):
                v.write(v.reg[6], 0x106, 2)
                return 1
            def feature(v):
                v.write(v.reg[7], 0x100)
                return 1
            def text(v):
                provider = v.reg[6] == 0x102
                assert provider or v.reg[6] == 0x100
                v.write(v.reg[7], INPUT if provider else INPUT+8)
                v.write(v.read(v.reg[29]+0x10), 8 if provider else 7, 2)
                return 1
            m.hooks.update({0x85b70: legacy_allocate, 0x582e4: version, 0x67edc: feature, 0x67f4c: text})
            saved = {r:0x12340000+r for r in (*range(16, 24), 28, 30)}
            saved[18] = PEER
            for r, v in saved.items(): m.reg[r] = v
            m.reg[4:8] = [LIST, 0, PEER+0xc8, PEER+0xca]
            m.reg[29], m.reg[31] = STACK, STOP
            m.write(STACK+0x10, OUTPUT)
            m.write(STACK+0x14, OUTPUT+4)
            m.write(STACK-0x500, 0xa55aa55a)
            m.write(STACK+0x30, 0xa55aa55a)
            m.run(entry, {STOP}, limit=20000)
            assert all(m.reg[r] == v for r,v in saved.items())
            assert (m.reg[29],m.reg[31]) == (STACK,STOP)
            assert m.read(STACK-0x500) == m.read(STACK+0x30) == 0xa55aa55a
            provider, name = m.read(OUTPUT), m.read(OUTPUT+4)
            assert data(m, provider, 9) == b'Provider\x00'
            assert data(m, name, 8) == b'Service\x00'
            outputs.append(dict(return_value=m.reg[2], provider=provider, name=name,
                                peer=data(m, PEER, 0x130).hex()))
            assert len(m.posts) == int(entry == d.WRAP and not fail_optional)
        assert outputs[0] == outputs[1]
        wrapper_cases.append(dict(optional_allocation_failed=fail_optional, original_result=outputs[0]))
    for result, supplier in ((1, 12), (0, 11), (0xffff, 0xffff)):
        m = Fixture(original, helpers)
        m.callback(full, result=result, supplier=supplier)
        assert not m.posts
        callback_cases.append(dict(case='failed_sdp', result=result, supplier=supplier, posts=0))
    for case in ('queue_unavailable', 'missing_configuration', 'old_version', 'missing_feature'):
        m = Fixture(original, helpers)
        m.sdp(full)
        m.peer()
        if case == 'queue_unavailable': m.write(d.QUEUE, 0xffff, 2)
        if case == 'missing_configuration': m.write(PEER+0x11c, 0)
        if case == 'old_version': m.write(PEER+0xc8, 0x105, 2)
        if case == 'missing_feature': m.write(PEER+0xca, 0, 2)
        assert call(m, d.CAPTURE, [LIST, 0, PEER]) == 0
        assert not m.heap and not m.posts
        extract_cases.append(dict(case=case, accepted=False))
    return dict(parser_cases=len(parser_cases), reader_cases=reader_cases, extraction_cases=len(extract_cases),
                native_callback_comparisons=len(callback_cases)-3, failed_sdp_cases=3,
                native_layout_cases=native_layout_cases, six_argument_wrapper_comparisons=len(wrapper_cases),
                wrappers=wrapper_cases, traces=parser_cases,
                extractions=extract_cases, callbacks=callback_cases, hook=recipe,
                helpers=[{k:v for k,v in r.items() if k != 'raw'} for r in helpers],
                executable_written=False, lgu_built=False, hardware_tested=False,
                limits=['MIPS interpretation at fixture addresses; no PE layout/loading/unwind proof',
                        'Original discovery callback and original target/controller field parser execute',
                        'SDP list construction, profile/feature/text field extraction and native cleanup are fixtures',
                        'Input allocation extents belong to the retained CSR result producer',
                        'Private capability messages need a task consumer and current-peer generation binding',
                        'CE image decoding and owned AppMain publication remain unfinished'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_discovery.py', 'verify_bt_cover_discovery.py', 'bt_cover_art_task.py',
                              'bt_cover_art_session.py', 'verify_bt_cover_csr_bridge.py', 'verify_bt_cover_owner.py',
                              'inspect_bt_lifecycle.py', 'inspect_bt_pairing.py', 'inspect_wave_queue.py',
                              'verify_media_responsiveness.py', 'patch_usb_seek_completion.py',
                              'patch_usb_folders.py', 'patch_usb_reliability.py', 'patch_updater_copy_safety.py',
                              'verify_bt_cover_attribute.py', 'patch_bt_cover_attribute.py',
                              'bt_cover_art_client.py')})


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    if args.report.exists():
        raise FileExistsError('Use a fresh report')
    result = verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_bytes((json.dumps(result, indent=2)+'\n').encode())
    print(json.dumps({k:v for k,v in result.items() if k.endswith('cases') or k.endswith('comparisons')}, indent=2))
