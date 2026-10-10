"""Execute dispatcher bytes with queue, binding, ownership and callback fixtures.

No original long worker bodies, live allocation, native retry timer or CE thread
shutdown. Record retirement is not proof of a native thread's exit.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import random
from types import FunctionType, SimpleNamespace

import patch_usb_request_dispatch as p
import patch_usb_request_binding as binding
import patch_usb_deferred_requests as queue
import patch_usb_lifecycle_protocol as core
import verify_usb_request_binding as previous
from verify_media_responsiveness import call
from verify_usb_input_safety import relocated
from verify_usb_catalog_recovery import Scan

OUT, CALLBACK = previous.OUT, previous.CALLBACK


class Fixture(previous.Fixture):
    def __init__(self, raw, delta):
        self.collected = set()
        super().__init__(raw, delta)
        self.m.write(p.STATE+delta-4, 0xa55aa55a)
        self.m.write(p.STATE+delta+p.STATE_BYTES, 0xa55aa55a)

    def machine(self, name):
        m = super().machine(name)
        m.ranges.extend((a+self.delta, a+n+self.delta) for a, n, *_ in p.HELPERS)
        return m

    def compare_exchange(self, m):
        if m.reg[4] == p.STATE+self.delta:
            assert m.reg[5:7] == [1, 0]
            old = m.read(m.reg[4])
            if old == 0: m.write(m.reg[4], 1)
            self.atomics.append(dict(context=m.name, operation='dispatcher_gate', old=old))
            Scan.clobber(m); return old
        return super().compare_exchange(m)

    def exchange(self, m):
        if m.reg[4] == p.STATE+self.delta:
            assert m.reg[5] == 0 and m.read(m.reg[4]) == 1
            m.write(m.reg[4], 0)
            self.atomics.append(dict(context=m.name, operation='dispatcher_release', old=1))
            Scan.clobber(m); return 1
        return super().exchange(m)

    def invoke(self, at, args=(), name='control', m=None):
        m = m or (self.m if name == 'control' else self.machine(name))
        stack = dict(control=0x68000000, producer=0x68100000, consumer=0x68200000)[name]
        result = FunctionType(call.__code__, dict(call.__globals__, STACK=stack),
                              argdefs=call.__defaults__)(m, at+self.delta, list(args))
        q = queue.QUEUE+self.delta
        assert m.read(q-4) == m.read(q+queue.QUEUE_BYTES) == 0xa55aa55a
        for n in self.nodes: assert m.read(n-4) == m.read(n+40) == 0xa55aa55a
        return result

    def node(self, index, kind=None, args=None):
        n = super().node(index, kind, args)
        self.collected.discard(n)
        return n

    def dispatch(self):
        s = p.STATE+self.delta
        return {name: self.m.read(s+4*i) for i, name in enumerate(p.FIELDS)}

    def submit(self, index, kind):
        n = self.node(index, kind=kind)
        assert self.invoke(queue.PUSH, [n], name='producer') in (core.OK, queue.WAKE_FAILED)
        return n

    def pump(self):
        self.m.write(OUT, 0xdeadbeef)
        self.m.write(OUT+4, 0xdeadbeef)
        status = self.invoke(p.PUMP, [OUT])
        node = self.m.read(OUT)
        if status == core.OK:
            assert node == self.dispatch()['active']
            assert self.m.read(node+24) == binding.CLAIMED
            assert self.m.read(node+28) == self.dispatch()['active_token'] == self.state()['active_token']
            assert self.m.read(OUT+4) == self.dispatch()['active_token']
            return status, node
        assert node == self.m.read(OUT+4) == 0xdeadbeef
        return status, None

    def complete(self, node, token=None, callback=CALLBACK):
        token = self.dispatch()['active_token'] if token is None else token
        return self.invoke(p.COMPLETE, [node, token, callback, node])

    def collect(self, poison=True):
        self.m.write(OUT, 0xdeadbeef)
        status = self.invoke(p.COLLECT, [OUT], name='consumer')
        node = self.m.read(OUT)
        if status == core.OK:
            assert node in self.nodes and node not in self.collected
            assert self.m.read(node) == 0
            assert self.m.read(node+24) in (binding.DROPPED, binding.FINISHED, queue.REJECTED)
            self.collected.add(node)
            if poison:
                self.retired.add(node)
                for i in range(40): self.mem.pop(node+i)
            return status, node
        assert node == 0xdeadbeef
        return status, None

    def accounting(self):
        d, s = self.dispatch(), self.state()
        assert d['lock'] == s['lock'] == 0
        owned = [n for n in (d['inbox'], d['active'], *(d['pending_'+k] for k in ('reset', 'normal', 'boot', 'shuffle'))) if n]
        retired, n = [], d['retired']
        while n:
            assert n in self.nodes and n not in retired and n not in self.collected
            retired.append(n); n = self.m.read(n)
        assert len(owned+retired) == len(set(owned+retired))
        queued = [n for n in self.nodes-self.collected if self.m.read(n+24) == queue.QUEUED]
        private = [n for n in self.nodes-self.collected if self.m.read(n+24) == queue.NEW]
        assert set(owned+retired+queued+private) == self.nodes-self.collected
        if d['active']:
            n = d['active']
            assert self.m.read(n+24) == binding.CLAIMED
            assert d['active_token'] == s['active_token'] == self.m.read(n+28)
        else: assert d['active_token'] == 0 and s['active_token'] == 0
        return dict(owned=list(map(hex, owned)), retired=list(map(hex, retired)),
                    queued=list(map(hex, queued)), private=list(map(hex, private)),
                    collected=sorted(map(hex, self.collected)))


def verify(raw):
    prior = binding.patch(queue.patch(core.patch(raw)[0])[0])[0]
    written, recipe = p.patch(prior)
    traces = []
    def record(name, f, **extra):
        ledger = f.accounting()
        s = p.STATE+f.delta
        assert f.m.read(s-4) == f.m.read(s+p.STATE_BYTES) == 0xa55aa55a
        traces.append(dict(name=name, delta=hex(f.delta), dispatcher=f.dispatch(), state=f.state(),
                           ledger=ledger, callbacks=f.callbacks, signals=f.signals,
                           atomics=dict(calls=len(f.atomics), operations=dict(Counter(e['operation'] for e in f.atomics)),
                                        sha256=hashlib.sha256(json.dumps(f.atomics, sort_keys=True).encode()).hexdigest()), **extra))

    def settle(f):
        selected, collected = [], []
        for _ in range(100):
            status, n = f.pump()
            if status == core.OK:
                selected.append(n)
                assert f.complete(n) == core.OK
            elif status == core.NOT_PENDING: break
            else: assert status == p.MORE, status
        else: raise AssertionError('Unbounded dispatcher drain')
        while True:
            status, n = f.collect()
            if status != core.OK:
                assert status == core.NOT_PENDING; break
            collected.append(n)
        f.accounting()
        return selected, collected

    for delta in (0, 0x1000, 0x10000, 0x123000):
        moved = relocated(written, delta) if delta else written
        for kind in range(4):
            f = Fixture(moved, delta); n = f.submit(0, kind)
            assert f.pump() == (core.OK, n)
            token = f.dispatch()['active_token']
            assert f.complete(n) == core.OK
            assert f.complete(n, token) == core.STALE and len(f.callbacks) == 1
            assert f.collect() == (core.OK, n) and f.collect()[0] == core.NOT_PENDING
            assert f.pump()[0] == core.NOT_PENDING
            record('select complete retire collect once', f, kind=kind)

            f = Fixture(moved, delta)
            nodes = [f.submit(i, kind) for i in range(6)]
            assert f.pump() == (core.OK, nodes[-1])
            assert f.state()[core.FIELDS[8+kind]] == 6
            assert f.complete(nodes[-1]) == core.OK
            _, collected = settle(f)
            assert set(collected) == set(nodes) and len(f.callbacks) == 1
            record('coalesce to latest payload and reclaim every record', f, kind=kind)

            for newer in range(4):
                f = Fixture(moved, delta); old = f.submit(0, kind)
                assert f.pump() == (core.OK, old)
                token = f.dispatch()['active_token']
                new = f.submit(1, newer)
                assert f.pump()[0] == core.BUSY and f.dispatch()['active'] == old
                stale = newer == core.RESET or newer == kind
                assert f.complete(old, token) == (core.STALE if stale else core.OK)
                assert len(f.callbacks) == int(not stale)
                assert f.pump() == (core.OK, new) and f.complete(new) == core.OK
                _, collected = settle(f)
                assert set(collected) == {old, new}
                record('active work invalidated by accepted pending request', f, kind=kind, newer=newer)

        f = Fixture(moved, delta)
        nodes = [f.submit(i, kind) for i, kind in enumerate((core.NORMAL, core.BOOT, core.SHUFFLE,
                                                            core.RESET, core.NORMAL, core.BOOT, core.SHUFFLE))]
        selected, collected = settle(f)
        assert selected == [nodes[3], nodes[4], nodes[5], nodes[6]]
        assert set(collected) == set(nodes)
        record('reset priority invalidates earlier-generation records', f, selected=list(map(hex, selected)))

        for count in (8, 9, 16, 32):
            f = Fixture(moved, delta); nodes = [f.submit(i, core.NORMAL) for i in range(count)]
            assert f.pump()[0] == p.MORE
            assert f.state()['seq_normal'] == 8 and not f.dispatch()['active']
            selected, collected = settle(f)
            assert selected == [nodes[-1]] and set(collected) == set(nodes)
            record('bounded drain budget retains backlog', f, count=count)

        f = Fixture(moved, delta); n = f.submit(0, core.NORMAL)
        s = core.STATE+delta; f.m.write(s, 1)
        assert f.pump()[0] == core.BUSY and f.dispatch()['inbox'] == n
        assert f.m.read(n+24) == queue.DEQUEUED
        f.m.write(s, 0); assert f.pump() == (core.OK, n)
        token = f.dispatch()['active_token']; f.m.write(s, 1)
        assert f.complete(n, token) == core.BUSY and f.dispatch()['active'] == n
        f.m.write(s, 0); assert f.complete(n, token) == core.OK
        settle(f); record('busy core retains inbox and active completion', f)

        f = Fixture(moved, delta); old = f.submit(0, core.NORMAL)
        assert f.pump() == (core.OK, old); token = f.dispatch()['active_token']
        f.wake_ok = False
        new = f.submit(1, core.SHUFFLE)
        assert f.complete(old, token) == core.OK and f.dispatch()['last_wake_failed'] == 1
        assert f.collect() == (core.OK, old)
        f.wake_ok = True; assert f.pump() == (core.OK, new) and f.complete(new) == core.OK
        settle(f); record('wake failure retains pending work for caller retry', f)

        f = Fixture(moved, delta); n = f.submit(0, core.SHUFFLE)
        assert f.pump() == (core.OK, n); old_token = f.dispatch()['active_token']
        assert f.complete(n) == core.OK and f.collect() == (core.OK, n)
        assert f.complete(n, old_token) == core.STALE  # Must not dereference freed body.
        reused = f.submit(0, core.NORMAL); assert reused == n
        assert f.pump() == (core.OK, n); new_token = f.dispatch()['active_token']
        assert new_token == old_token+1
        before = f.dispatch()
        assert f.complete(n, old_token) == core.STALE and f.dispatch() == before
        assert f.complete(n, new_token) == core.OK
        settle(f); record('old completion cannot act on reused node address', f)

        for active in (False, True):
            f = Fixture(moved, delta); old = f.submit(0, core.NORMAL)
            if active: assert f.pump() == (core.OK, old)
            new = f.submit(1, core.SHUFFLE)
            assert f.invoke(core.CLOSE) == (core.DRAINING if active else core.OK)
            if active:
                assert f.pump()[0] == core.BUSY
                assert f.complete(old) == core.STALE
            assert f.pump()[0] == core.NOT_PENDING
            _, collected = settle(f); assert set(collected) == {old, new} and not f.callbacks
            record('closed ownership drains and retires queued pending active records', f, active=active)

        f = Fixture(moved, delta); n = f.submit(0, core.NORMAL)
        assert f.pump() == (core.OK, n); token = f.dispatch()['active_token']
        f.callback = lambda m: 7
        assert f.complete(n, token) == core.CALLBACK_FAILED
        assert f.complete(n, token) == core.STALE and len(f.callbacks) == 1
        settle(f); record('callback failure retires once without rerunning', f)

        # Each selected context keeps its own lease token. Seeded mixed workloads
        # exercise scheduling/coalescing; no probability/frequency claim is made.
        for seed in range(8):
            f = Fixture(moved, delta); rng = random.Random(seed); index = 0
            for _ in range(40):
                if rng.randrange(3) or not f.dispatch()['active']:
                    f.submit(index, rng.randrange(4)); index += 1
                status, n = f.pump()
                assert status in (core.OK, core.BUSY, core.NOT_PENDING, p.MORE)
                if f.dispatch()['active'] and rng.randrange(2):
                    n = f.dispatch()['active']
                    assert f.complete(n) in (core.OK, core.STALE)
                f.accounting()
            if f.dispatch()['active']: assert f.complete(f.dispatch()['active']) in (core.OK, core.STALE)
            _, collected = settle(f)
            assert len(collected) == index
            record('seeded mixed request lifecycle accounting', f, seed=seed, records=index)

        # Admit from a producer while completion publishes. PUMP/COLLECT reentry
        # must return promptly, while PUSH remains independent of dispatcher gate.
        f = Fixture(moved, delta); old = f.submit(0, core.NORMAL)
        assert f.pump() == (core.OK, old)
        posted = []
        def during_callback(m):
            posted.append(f.submit(1, core.RESET))
            before = f.dispatch()
            assert f.invoke(p.PUMP, [OUT], name='producer') == core.BUSY
            assert f.invoke(p.COLLECT, [OUT], name='consumer') == core.BUSY
            assert f.dispatch() == before
            return 0
        f.callback = during_callback
        assert f.complete(old) == core.OK and len(posted) == 1
        f.callback = lambda m: 0
        assert f.pump() == (core.OK, posted[0]) and f.complete(posted[0]) == core.OK
        settle(f); record('producer allowed but dispatch reentry deferred during publication', f)

        # Queue a second same-kind record, dispatch and collect while a producer
        # is paused. A producer that has published its link must not access its
        # record after another context retires/collects it.
        probe = Fixture(moved, delta); n = probe.node(0, kind=core.NORMAL)
        a = probe.machine('control')
        assert probe.invoke(queue.PUSH, [n], m=a) == core.OK
        for at in sorted(set(a.visited)):
            f = Fixture(moved, delta)
            first, second = f.node(0, kind=core.NORMAL), f.node(1, kind=core.NORMAL)
            a = f.machine('control'); a.inject_at = at
            interim = []
            def producer_interleave():
                assert f.invoke(queue.PUSH, [second], name='producer') == core.OK
                status = f.invoke(p.PUMP, [OUT+4], name='consumer')
                interim.append(status)
                assert status in (core.OK, core.BUSY, core.NOT_PENDING)
                f.collect()
            a.inject = producer_interleave
            assert f.invoke(queue.PUSH, [first], m=a) == core.OK
            assert a.inject is None and len(interim) == 1
            for _ in range(20):
                status, n = f.pump()
                if f.dispatch()['active']:
                    assert f.complete(f.dispatch()['active']) in (core.OK, core.STALE)
                elif status == core.NOT_PENDING: break
                else: assert status == p.MORE
            else: raise AssertionError('Producer interleave did not drain')
            while f.collect()[0] == core.OK: pass
            assert f.collected == {first, second}
            record('producer boundary with dispatch and immediate reclamation', f, at=hex(at), interim=interim[0])

        probe = Fixture(moved, delta); n = probe.submit(0, core.NORMAL)
        a = probe.machine('control')
        assert probe.invoke(p.PUMP, [OUT], m=a) == core.OK
        for at in sorted(set(a.visited)):
            f = Fixture(moved, delta); first = f.submit(0, core.NORMAL)
            a = f.machine('control'); a.inject_at = at
            posted = []
            a.inject = lambda: posted.append(f.submit(1, core.RESET))
            status = f.invoke(p.PUMP, [OUT], m=a)
            assert a.inject is None and len(posted) == 1 and status in (core.OK, core.BUSY), (hex(at), status)
            if status == core.BUSY:
                # POP can conservatively report an in-progress link using an
                # older snapshot; the next bounded call sees the published link.
                assert f.pump()[0] == core.OK
            active = f.dispatch()['active']
            if active == first:
                assert f.pump()[0] == core.BUSY
                assert f.complete(first) == core.STALE
            else:
                assert active == posted[0] and f.complete(active) == core.OK
            settle(f)
            assert f.collected == {first, posted[0]}
            record('producer arrival at pump instruction boundary', f, at=hex(at))

        probe = Fixture(moved, delta); n = probe.submit(0, core.NORMAL)
        assert probe.pump() == (core.OK, n)
        token = probe.dispatch()['active_token']; a = probe.machine('control')
        assert probe.invoke(p.COMPLETE, [n, token, CALLBACK, n], m=a) == core.OK
        for at in sorted(set(a.visited)):
            f = Fixture(moved, delta); n = f.submit(0, core.NORMAL)
            assert f.pump() == (core.OK, n)
            token = f.dispatch()['active_token']; a = f.machine('control'); a.inject_at = at
            collected = []
            a.inject = lambda: collected.append(f.collect()[0])
            assert f.invoke(p.COMPLETE, [n, token, CALLBACK, n], m=a) == core.OK
            assert a.inject is None and len(collected) == 1
            assert collected[0] in (core.OK, core.BUSY, core.NOT_PENDING)
            if collected[0] != core.OK: assert f.collect() == (core.OK, n)
            assert f.collected == {n} and len(f.callbacks) == 1
            record('collection at completion instruction boundary', f, at=hex(at), interim=collected[0])

    proxy = SimpleNamespace(**vars(binding))
    proxy.patch = lambda source: p.patch(binding.patch(source)[0])
    kept = FunctionType(previous.verify.__code__, dict(previous.verify.__globals__, p=proxy))(raw)
    old = json.loads((Path(__file__).resolve().parents[1]/'analysis/firmware/usb-request-binding.json').read_bytes())
    # Frozen JSON represents bound-pair tuples as arrays; compare in that format.
    assert old['cases'] == kept['cases'] == 3356 and old['traces'] == json.loads(json.dumps(kept['traces']))
    assert kept['retained_queue_cases'] == 1336 and kept['retained_ownership_cases'] == 540
    assert p.patch(prior)[0] == written
    return dict(cases=len(traces), candidate_sha256=recipe['sha256'], patch=recipe, traces=traces,
                retained_binding_cases=3356, retained_queue_cases=1336, retained_ownership_cases=540,
                native_executed=False, hardware_tested=False,
                limits=['Unwired dispatcher selects a lease; it does not launch original worker bodies or prepare private catalogs',
                        'Caller allocation/pool, retry scheduler and native worker/producer shutdown remain absent',
                        'Dispatcher must exclusively own admission/claim/completion; producers only enqueue immutable 40-byte records',
                        'Completion caller retains pointer plus expected token; node must not be reused before collection/receiver release',
                        'Retired records are available for caller reclamation; retirement is not proof of a native thread exit',
                        'Atomic/event operations, callbacks and CPU scheduling are fixtures, not CE timing/memory-ordering proof',
                        'Failed wake is recorded; progress still requires a real retry/polling fallback'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', required=True, type=Path)
    parser.add_argument('--report', required=True, type=Path)
    args = parser.parse_args()
    raw = args.input.read_bytes(); report = verify(raw)
    assert args.input.read_bytes() == raw
    report['verifier_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    report['patcher_sha256'] = hashlib.sha256(Path(p.__file__).read_bytes()).hexdigest()
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_bytes((json.dumps(report, indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=report['cases'], retained_binding_cases=3356,
                         retained_queue_cases=1336, retained_ownership_cases=540,
                         candidate_sha256=report['candidate_sha256'])))
