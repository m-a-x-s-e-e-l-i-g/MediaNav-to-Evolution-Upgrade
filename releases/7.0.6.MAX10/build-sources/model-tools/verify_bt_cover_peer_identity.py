"""Interpret original peer creation/destruction with appended artwork identity.

MIPS list linking, peer initialization, lookup, destructor and unlink/free paths
execute. Heap, memset, timer cancellation and posting are fixtures. No PE/LGU
or selected-phone producer/consumer installation is claimed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

import pefile

import bt_cover_art_peer_identity as identity
import bt_cover_art_discovery as discovery
from verify_bt_cover_discovery import Fixture, OUTPUT, INPUT, PEER, CONTEXT, LIST, seq, protocols
from verify_media_responsiveness import call
from inspect_bt_pairing import data, put

ROOT = Path(__file__).resolve().parents[1]
MESSAGE, CID = 0x46000000, 0x400030
NATIVE = [(0x5699c, 0x56ad4), (0x8145c, 0x81478), (0x814a0, 0x8151c),
          (0x8151c, 0x81598), (0x81598, 0x8161c), (0x567dc, 0x56854),
          (0x56894, 0x568b0), (0x57cd8, 0x57d90), (0x6aa30, 0x6aaa8), (0x8186c, 0x818ac), (0x818e8, 0x81940)]


class Lifetime(Fixture):
    def __init__(self, original, helpers, enabled=True, serial=0):
        super().__init__(original, helpers)
        self.ranges += NATIVE
        self.blocks, self.allocations, self.frees, self.cancelled = {}, [], [], []
        self.next_peer = 0x47000000
        self.map(CONTEXT, bytes(0x9c))
        self.map(identity.COUNTER, struct.pack('<I', serial))
        self.map(INPUT, bytes.fromhex('4433221188776655'), True)
        self.hooks.update({0x85b70: self.allocate_original, 0x85bb8: self.release,
                           0x3a750: self.fill, 0x85008: self.cancel})
        if enabled:
            self.patches.update(identity.sites(original.__data__))
        call(self, 0x8145c, [CONTEXT+0x7c, 0, 0, 0x567dc])

    def read(self, at, size=4):
        for pointer, (n, live) in self.blocks.items():
            if pointer-4 <= at < pointer+n+4:
                assert live or at in (pointer-4, pointer+n), ('Freed allocation read', hex(at))
        return super().read(at, size)

    def write(self, at, value, size=4):
        for pointer, (n, live) in self.blocks.items():
            if pointer-4 <= at < pointer+n+4:
                assert live, ('Freed allocation write', hex(at))
                assert pointer <= at and at+size <= pointer+n, ('Heap guard write', hex(at), size)
        return super().write(at, value, size)

    def block(self, pointer, n):
        # Reuse deliberately, including exactly the same address after free.
        if pointer in self.blocks:
            old_n, live = self.blocks.pop(pointer)
            assert not live
            self.allowed = [(lo,hi) for lo,hi in self.allowed if (lo,hi) != (pointer-4,pointer+old_n+4)]
        self.map(pointer-4, bytes.fromhex('5aa55aa5')+bytes([0xcd])*n+bytes.fromhex('5aa55aa5'))
        self.blocks[pointer] = (n, True)
        return pointer

    def allocate_original(self, m):
        n = m.reg[4]
        assert n in (identity.PREFIX, identity.SIZE, 16), n
        if n == 16:
            pointer = self.next_heap
            self.next_heap += 0x100
        else:
            pointer = self.next_peer
            self.next_peer += 0x1000
        self.allocations.append(dict(pointer=hex(pointer), bytes=n))
        return self.block(pointer, n)

    def fill(self, m):
        pointer, value, size = m.reg[4:7]
        put(m, pointer, bytes([value & 255])*size)
        return pointer

    def cancel(self, m):
        assert m.reg[5:7] == [0, 0]
        self.cancelled.append(m.reg[4])
        return 0

    def release(self, m):
        pointer = m.reg[4]
        if not pointer:
            return 0
        n, live = self.blocks[pointer]
        assert live, 'Double free'
        assert self.read(pointer-4) == self.read(pointer+n) == 0xa55aa55a
        self.blocks[pointer] = (n, False)
        self.frees.append(hex(pointer))
        return 0

    def create(self):
        return call(self, 0x5699c, [CONTEXT, INPUT])

    def destroy(self, pointer):
        call(self, 0x81598, [CONTEXT+0x7c, pointer])
        assert not self.blocks[pointer][1]

    def ready(self, pointer):
        self.write(pointer+0xc8, 0x106, 2)
        self.write(pointer+0xca, 0x100, 2)
        self.write(pointer+0x18, CID)
        self.write(pointer+0x1e, 3, 1)
        self.write(CONTEXT+0x9a, 0x80, 2)

    def capture(self, pointer, value=None, fail=False):
        self.sdp(seq(protocols()) if value is None else value)
        self.alloc_fail = fail
        result = call(self, discovery.CAPTURE, [LIST, 0, pointer], limit=40000)
        assert not any(self.heap.values()), 'Message not transferred'
        return result

    def saved_message(self, raw=None):
        raw = self.posts[-1] if raw is None else raw
        self.map(MESSAGE, raw)
        return MESSAGE


def verify(raw):
    pe, helpers = pefile.PE(data=raw), identity.assembled()
    sites = identity.sites(raw)
    constructor_cases, reuse_cases, capture_cases, match_cases = [], [], [], []
    for count in (1, 2, 4, 7):
        for nested in (False, True):
            sides = []
            for enabled in (False, True):
                m = Lifetime(pe, helpers, enabled)
                peers = [m.create() for _ in range(count)]
                assert [m.read(p+0x10, 1) for p in peers] == list(range(count))
                assert m.read(CONTEXT+0x84) == count
                if enabled:
                    for i, pointer in enumerate(peers):
                        assert m.read(pointer+0x120) == i+1
                        assert data(m, pointer+0x124, 12) == bytes(12)
                prefixes = [data(m, p, identity.PREFIX).hex() for p in peers]
                if nested:
                    # Native queue/list builders plus one owned buffer in each
                    # peer's outgoing control queue; original destructor frees it.
                    for p in peers:
                        node = call(m, 0x8151c, [p+0x24, 16])
                        payload = m.next_heap
                        m.next_heap += 0x100
                        m.block(payload, 5)
                        m.write(node+12, payload)
                for pointer in peers[::2]+peers[1::2]:
                    m.destroy(pointer)
                assert m.read(CONTEXT+0x7c) == m.read(CONTEXT+0x80) == m.read(CONTEXT+0x84) == 0
                assert all(not live for _,live in m.blocks.values())
                sides.append(dict(prefixes=prefixes, allocations=m.allocations, frees=m.frees,
                                  cancelled=m.cancelled, serial=m.read(identity.COUNTER), steps=m.steps))
            assert sides[0]['prefixes'] == sides[1]['prefixes']
            assert sides[0]['frees'] == sides[1]['frees']
            assert sides[0]['cancelled'] == sides[1]['cancelled']
            assert sides[0]['serial'] == 0 and sides[1]['serial'] == count
            for a,b in zip(sides[0]['allocations'],sides[1]['allocations']):
                assert a['pointer'] == b['pointer']
                assert b['bytes'] == (identity.SIZE if a['bytes'] == identity.PREFIX else a['bytes'])
            constructor_cases.append(dict(peers=count, nested=nested, previous=sides[0], candidate=sides[1]))
    for serial in (0, 1, 0xfffffffe, 0xffffffff):
        m = Lifetime(pe, helpers, serial=serial)
        first = m.create()
        a = m.read(first+0x120)
        m.destroy(first)
        m.next_peer = first
        second = m.create()
        b = m.read(second+0x120)
        assert first == second and m.read(second+0x10,1) == 0
        if serial < 0xfffffffe:
            assert (a,b) == (serial+1,serial+2)
        elif serial == 0xfffffffe:
            assert (a,b) == (0xffffffff,0)
        else:
            assert (a,b) == (0,0)
        m.ready(second)
        accepted = m.capture(second)
        assert accepted == int(bool(b))
        if not b:
            assert not m.posts and data(m,second+0x120,16) == bytes(16)
        m.destroy(second)
        reuse_cases.append(dict(initial_serial=serial, first=a, second=b, same_allocation_address=True,
                                peer_id_reused=True, optional_capture=bool(accepted), final_serial=m.read(identity.COUNTER)))
    for case in ('valid', 'failed_optional_allocation', 'duplicate_channel', 'unsupported_version', 'missing_feature'):
        m = Lifetime(pe, helpers)
        peer = m.create()
        m.ready(peer)
        assert m.capture(peer) == 1
        first_message = m.posts[-1]
        assert struct.unpack_from('<I',first_message,20)[0] == m.read(peer+0x120)
        prefix = data(m,peer,identity.PREFIX)
        if case == 'unsupported_version': m.write(peer+0xc8,0x105,2)
        if case == 'missing_feature': m.write(peer+0xca,0,2)
        prefix = data(m,peer,identity.PREFIX)
        value = seq(protocols()+protocols()) if case == 'duplicate_channel' else None
        result = m.capture(peer,value,case == 'failed_optional_allocation')
        assert data(m,peer,identity.PREFIX) == prefix
        valid = case in ('valid','failed_optional_allocation')
        assert m.read(peer+0x12c) == int(valid)
        if valid:
            assert data(m,peer+0x124,8) == bytes.fromhex('0110800006010001')
        else:
            assert data(m,peer+0x124,12) == bytes(12)
        assert result == int(case == 'valid')
        capture_cases.append(dict(case=case, posted=bool(result), stored_capabilities=valid))
    for case in ('valid', 'unselected', 'wrong_cid', 'disconnected', 'wrong_birth', 'wrong_address',
                 'wrong_psm', 'wrong_security', 'wrong_version', 'wrong_features', 'bad_primitive',
                 'missing_capabilities', 'zero_birth', 'invalid_capability_flag', 'zero_selected_cid',
                 'selected_id_overflow', 'peer_absent'):
        m = Lifetime(pe,helpers)
        peer = m.create()
        m.ready(peer)
        assert m.capture(peer)
        msg = m.saved_message()
        selected, cid = 0, CID
        if case == 'unselected': selected = 1
        if case == 'wrong_cid': cid += 1
        if case == 'disconnected': m.write(peer+0x1e,4,1)
        if case == 'wrong_birth': m.write(msg+20,2)
        if case == 'wrong_address': m.write(msg+8,m.read(msg+8)^1)
        if case == 'wrong_psm': m.write(msg+12,0x1003,2)
        if case == 'wrong_security': m.write(msg+14,0,2)
        if case == 'wrong_version': m.write(msg+16,0x105,2)
        if case == 'wrong_features': m.write(msg+18,0,2)
        if case == 'bad_primitive': m.write(msg,2,2)
        if case == 'missing_capabilities': m.write(peer+0x12c,0)
        if case == 'zero_birth': m.write(peer+0x120,0)
        if case == 'invalid_capability_flag': m.write(peer+0x12c,2)
        if case == 'zero_selected_cid': cid = 0
        if case == 'selected_id_overflow': selected = 256
        if case == 'peer_absent': m.destroy(peer)
        before = data(m,CONTEXT,0x9c)
        peer_before = data(m,peer,identity.SIZE) if m.blocks[peer][1] else None
        result = call(m,identity.MATCH,[CONTEXT,msg,selected,cid])
        assert result == (peer if case == 'valid' else 0),case
        assert data(m,CONTEXT,0x9c) == before
        if peer_before is not None: assert data(m,peer,identity.SIZE) == peer_before
        match_cases.append(dict(case=case, accepted=bool(result), steps=m.steps))
    # An old queued message cannot be promoted after native unlink/free and
    # exact address/peer-ID/BDADDR/CID reuse. Native list lookup executes.
    m = Lifetime(pe,helpers)
    first = m.create()
    m.ready(first)
    assert m.capture(first)
    old = m.posts[-1]
    old_generation = m.read(first+0x120)
    m.destroy(first)
    m.next_peer = first
    replacement = m.create()
    m.ready(replacement)
    assert m.capture(replacement)
    new = m.posts[-1]
    assert call(m,identity.MATCH,[CONTEXT,m.saved_message(old),0,CID]) == 0
    assert call(m,identity.MATCH,[CONTEXT,m.saved_message(new),0,CID]) == replacement
    match_cases.append(dict(case='native_free_and_exact_reuse', old_generation=old_generation,
                            new_generation=m.read(replacement+0x120), old_accepted=False, new_accepted=True))
    return dict(constructor_comparisons=len(constructor_cases), reuse_cases=len(reuse_cases),
                capture_cases=len(capture_cases), match_cases=len(match_cases), constructors=constructor_cases,
                reuses=reuse_cases, captures=capture_cases, matches=match_cases,
                sites={hex(k):hex(v) for k,v in sites.items()},
                helpers=[{k:v for k,v in r.items() if k!='raw'} for r in helpers],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Appended peer storage and counter addresses are interpreter placements',
                        'Allocator, memset, timer cancellation, SDP input and posting are fixtures',
                        'Actual original peer/list initialization, unlink, destructor and lookup instructions execute',
                        'Native constructor retains the original fatal allocation contract; sixteen extra bytes per peer',
                        'MATCH returns a borrowed peer only for synchronous use in serialized CSR segment zero',
                        'Actual selected-phone events, control-CID snapshots and artwork-task consumption remain unwired',
                        'Full disconnect/source/track integration, executable placement and image publication remain open'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                    ('bt_cover_art_peer_identity.py','verify_bt_cover_peer_identity.py','bt_cover_art_discovery.py',
                     'verify_bt_cover_discovery.py','verify_bt_cover_csr_bridge.py','verify_bt_cover_attribute.py',
                     'verify_media_responsiveness.py','inspect_bt_lifecycle.py','inspect_wave_queue.py',
                     'inspect_bt_pairing.py','patch_bt_cover_attribute.py','patch_usb_seek_completion.py',
                     'patch_usb_folders.py','patch_usb_reliability.py','patch_updater_copy_safety.py')})


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--report',type=Path,required=True)
    args = parser.parse_args()
    if args.report.exists(): raise FileExistsError('Use a fresh report')
    result = verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'))
    print(json.dumps({k:v for k,v in result.items() if k.endswith('cases') or k.endswith('comparisons')},indent=2))
