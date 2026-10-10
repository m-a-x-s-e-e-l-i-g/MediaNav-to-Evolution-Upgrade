"""Execute bound-record helpers, race schedules and frozen queue/ownership tests.

Native MIPS bytes with atomic/callback fixtures, not CE or device execution.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
from types import FunctionType, SimpleNamespace

from inspect_bt_pairing import put, data
import patch_usb_request_binding as p
import patch_usb_deferred_requests as queue
import patch_usb_lifecycle_protocol as core
import verify_usb_deferred_requests as previous
from verify_media_responsiveness import call
from verify_usb_catalog_recovery import Scan, USB
from verify_usb_input_safety import relocated

NODE, OUT, CALLBACK = previous.NODE, previous.OUT, 0xf4000000


class Machine(previous.Machine):
    def write(self, at, value, size=4):
        assert not any(a <= at < a+40 or at <= a < at+size for a in self.retired), 'Retired binding accessed'
        super().write(at, value, size)


class Fixture(previous.Fixture):
    def __init__(self, raw, delta):
        self.callbacks = []
        self.callback = lambda m: 0
        super().__init__(raw, delta)

    def machine(self, name):
        m = Machine(self.raw, [(a, a+n) for a, n, *_ in (*queue.HELPERS, *core.HELPERS, *p.HELPERS)], self.delta)
        m.mem, m.retired, m.name = self.mem, self.retired, name
        m.visited, m.inject, m.inject_at = [], None, None
        m.write(0x2f1c4+self.delta, 0xf3000000)
        m.write(0x2f1b8+self.delta, 0xf3000004)
        m.hooks.update({0xf3000000: self.compare_exchange, 0xf3000004: self.exchange,
                        0x2522c+self.delta: self.signal, CALLBACK: self.publish})
        return m

    def compare_exchange(self, m):
        at, value, expected = m.reg[4:7]
        q, s = queue.QUEUE+self.delta, core.STATE+self.delta
        assert (expected == 0 and value == 0 and (at in (q, q+8) or at in self.nodes or at-24 in self.nodes) or
                expected == 0 and value == 1 and (at in (q+12, s) or at-24 in self.nodes) or
                (expected, value) in ((2, 3), (6, 8), (7, 9)) and at-24 in self.nodes), (hex(at), value, expected)
        old = m.read(at)
        if old == expected: m.write(at, value)
        self.atomics.append(dict(context=m.name, operation='compare_exchange', at=hex(at), old=old, value=value))
        Scan.clobber(m)
        return old

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
        n = NODE+index*0x40
        self.retired.discard(n); self.nodes.add(n)
        values = [0, index % 4 if kind is None else kind,
                  *(args if args is not None else (USB, 0xabcd0000+index, index % 2)), index, 0, 0, 0, 0]
        put(self.m, n, b''.join(v.to_bytes(4, 'little') for v in values))
        self.m.write(n-4, 0xa55aa55a); self.m.write(n+40, 0xa55aa55a)
        return n

    def ready(self, index, kind):
        n = self.node(index, kind=kind)
        assert self.invoke(queue.PUSH, [n]) == core.OK
        assert self.pop() == (core.OK, n)
        return n

    def publish(self, m):
        n, s = m.reg[4], core.STATE+self.delta
        assert n in self.nodes and m.read(s) == 1 and m.read(n+24) == p.FINISHING
        assert m.read(s+16) == m.read(n+32) and m.read(s+24) == m.read(n+36)
        assert m.read(s+20) == m.read(n+4)
        self.callbacks.append(dict(node=hex(n), args=[m.read(n+8+4*i) for i in range(3)],
                                   media=m.read(n+32), sequence=m.read(n+36)))
        result = self.callback(m)
        Scan.clobber(m)
        return result

    def state(self):
        s = core.STATE+self.delta
        return {name: self.m.read(s+4*i) for i, name in enumerate(core.FIELDS)}

    def bound(self, n): return (self.m.read(n+32), self.m.read(n+36))
    def bind(self, n): return self.invoke(p.BIND, [n])
    def claim(self, n):
        self.m.write(OUT, 0xdeadbeef)
        status = self.invoke(p.CLAIM_RECORD, [n, OUT])
        token = self.m.read(OUT)
        if status != core.OK: assert token == 0xdeadbeef
        return status, token if status == core.OK else None
    def finish(self, n, callback=CALLBACK): return self.invoke(p.FINISH_RECORD, [n, callback, n])


def verify(raw):
    prior = queue.patch(core.patch(raw)[0])[0]
    written, recipe = p.patch(prior)
    traces = []
    def record(name, f, **extra):
        assert f.state()['lock'] == f.snapshot()['consumer_busy'] == 0
        traces.append(dict(name=name, delta=hex(f.delta), state=f.state(), callbacks=f.callbacks,
                           nodes=[dict(node=hex(n), payload=f.payload(n), receipt=f.m.read(n+24),
                                       result_or_token=f.m.read(n+28), binding=f.bound(n)) for n in sorted(f.nodes)],
                           atomics=dict(calls=len(f.atomics), operations=dict(Counter(e['operation'] for e in f.atomics)),
                                        sha256=hashlib.sha256(json.dumps(f.atomics, sort_keys=True).encode()).hexdigest()), **extra))

    for delta in (0, 0x1000, 0x10000, 0x123000):
        moved = relocated(written, delta) if delta else written
        for kind in range(4):
            f = Fixture(moved, delta); n = f.ready(0, kind); payload = f.payload(n)
            assert f.bind(n) == core.OK and f.bound(n) == (int(kind == core.RESET), 1)
            for _ in range(3): assert f.bind(n) == core.OK
            assert f.bound(n)[1] == f.state()[core.FIELDS[8+kind]] == 1
            status, token = f.claim(n); assert status == core.OK and token == 1
            assert f.claim(n)[0] == p.ALREADY_OWNED
            assert f.finish(n) == core.OK
            for _ in range(3): assert f.finish(n) == core.OK
            assert len(f.callbacks) == 1 and f.payload(n) == payload and f.state()['active_token'] == 0
            record('bound claim completion idempotency', f, kind=kind)

            for newer in range(4):
                for active in (False, True):
                    f = Fixture(moved, delta); old = f.ready(0, kind); new = f.ready(1, newer)
                    assert f.bind(old) == core.OK
                    if active: assert f.claim(old)[0] == core.OK
                    assert f.bind(new) == core.OK
                    before = f.state(); stale = newer == core.RESET or kind == newer
                    if active:
                        assert f.finish(old) == (core.STALE if stale else core.OK)
                        assert len(f.callbacks) == int(not stale)
                    elif stale:
                        assert f.claim(old)[0] == core.STALE
                        assert f.m.read(old+24) == p.DROPPED
                        assert f.state() == before  # Did not consume the newer request.
                    else:
                        assert f.claim(old)[0] == core.OK
                        assert f.finish(old, 0) == core.OK
                    assert f.claim(new)[0] == core.OK
                    assert f.finish(new) == core.OK
                    assert f.callbacks[-1]['node'] == hex(new)
                    record('new payload never claimed by older record', f, kind=kind, newer=newer, active=active)

            # Legacy unbound submission still invalidates an older bound identity.
            f = Fixture(moved, delta); n = f.ready(0, kind)
            assert f.bind(n) == core.OK and f.invoke(core.SUBMIT, [kind]) == core.OK
            before = f.state(); assert f.claim(n)[0] == core.STALE and f.state() == before
            assert f.invoke(core.CLAIM, [kind, OUT]) == core.OK
            assert f.invoke(core.FINISH, [f.m.read(OUT), 0, 0]) == core.OK
            record('legacy submission invalidates bound record', f, kind=kind)

            f = Fixture(moved, delta); n = f.ready(0, kind)
            s = core.STATE+delta; f.m.write(s, 1)
            assert f.bind(n) == core.BUSY and f.m.read(n+24) == queue.DEQUEUED
            assert f.bound(n) == (0, 0)
            f.m.write(s, 0); assert f.bind(n) == core.OK
            f.m.write(s, 1)
            assert f.claim(n)[0] == core.BUSY and f.m.read(n+24) == p.BOUND
            f.m.write(s, 0); assert f.claim(n)[0] == core.OK
            token = f.m.read(n+28); f.m.write(s, 1)
            assert f.finish(n) == core.BUSY and f.m.read(n+24) == p.CLAIMED and f.m.read(n+28) == token
            f.m.write(s, 0); assert f.finish(n) == core.OK
            record('busy binding claiming and finishing retain record', f, kind=kind)

            for stage in ('bind', 'claim', 'finish'):
                f = Fixture(moved, delta); n = f.ready(0, kind)
                if stage != 'bind': assert f.bind(n) == core.OK
                if stage == 'finish': assert f.claim(n)[0] == core.OK
                assert f.invoke(core.CLOSE) == (core.DRAINING if stage == 'finish' else core.OK)
                result = f.bind(n) if stage == 'bind' else f.claim(n)[0] if stage == 'claim' else f.finish(n)
                assert result == (core.STALE if stage == 'finish' else core.CLOSED)
                assert not f.callbacks and f.state()['active_token'] == 0
                record('close rejects or drains bound record', f, kind=kind, stage=stage)

            for stage in ('bind', 'claim'):
                f = Fixture(moved, delta); n = f.ready(0, kind)
                if stage == 'bind': f.m.write(s+32+4*kind, 0xffffffff)
                else:
                    assert f.bind(n) == core.OK
                    f.m.write(s+8, 0xffffffff)
                result = f.bind(n) if stage == 'bind' else f.claim(n)[0]
                assert result == core.EXHAUSTED and f.state()['closed'] == 1
                assert f.m.read(n+24) == queue.REJECTED
                record('saturation rejects bound record', f, kind=kind, stage=stage)

        f = Fixture(moved, delta); n = f.ready(0, core.NORMAL)
        assert f.invoke(queue.ACCEPT, [n]) == core.OK
        assert f.claim(n)[0] == core.INVALID and not f.state()['active_token']
        record('unbound admission cannot claim a payload', f)

        f = Fixture(moved, delta); n = f.ready(0, core.NORMAL)
        assert f.bind(n) == core.OK
        before = f.state()
        for out in (0, OUT+1, *(n+i for i in range(0, 40, 4))):
            assert f.invoke(p.CLAIM_RECORD, [n, out]) == core.INVALID
            assert f.state() == before and f.m.read(n+24) == p.BOUND
        f.m.write(n+36, 0)
        assert f.claim(n)[0] == core.INVALID and not f.state()['active_token']
        record('invalid output alias and zero binding rejected', f)

        f = Fixture(moved, delta); n = f.ready(0, core.NORMAL)
        assert f.bind(n) == core.OK and f.claim(n)[0] == core.OK
        assert f.finish(n, CALLBACK+1) == core.INVALID and f.m.read(n+24) == p.CLAIMED
        f.callback = lambda m: 1
        assert f.finish(n) == core.CALLBACK_FAILED
        assert f.finish(n) == core.CALLBACK_FAILED and len(f.callbacks) == 1
        record('callback failure cached without duplicate publication', f)

        # Probe all reached non-control instruction boundaries in each adapter,
        # including the core gate wrappers and branch delay slots.
        for operation in ('bind', 'claim', 'finish'):
            probe = Fixture(moved, delta); n = probe.ready(0, core.SHUFFLE)
            if operation != 'bind': assert probe.bind(n) == core.OK
            if operation == 'finish': assert probe.claim(n)[0] == core.OK
            a = probe.machine('control')
            entry, args = {'bind': (p.BIND, [n]), 'claim': (p.CLAIM_RECORD, [n, OUT]),
                           'finish': (p.FINISH_RECORD, [n, CALLBACK, n])}[operation]
            assert probe.invoke(entry, args, m=a) == core.OK
            for at in sorted(set(a.visited)):
                f = Fixture(moved, delta); n = f.ready(0, core.SHUFFLE); newer = f.ready(1, core.RESET)
                if operation != 'bind': assert f.bind(n) == core.OK
                if operation == 'finish': assert f.claim(n)[0] == core.OK
                a = f.machine('control'); a.inject_at = at
                arrivals = []
                def reset():
                    before = f.state(); published = len(f.callbacks)
                    status = f.invoke(p.BIND, [newer], name='producer')
                    assert status == (core.BUSY if before['lock'] else core.OK)
                    arrivals.append(dict(status=status, published=published, locked=before['lock']))
                a.inject = reset
                status = f.invoke(entry, args, m=a)
                assert a.inject is None and len(arrivals) == 1
                arrival = arrivals[0]
                if operation == 'bind':
                    assert status == core.OK
                    if arrival['status'] == core.BUSY: assert f.bind(newer) == core.OK
                    if f.bound(n)[0] == f.state()['media']:
                        assert f.claim(n)[0] == core.BUSY  # Reset is pending first.
                    else: assert f.claim(n)[0] == core.STALE
                elif operation == 'claim':
                    assert status in (core.OK, core.STALE)
                    if arrival['status'] == core.BUSY: assert f.bind(newer) == core.OK
                    if status == core.OK: assert f.finish(n) == core.STALE
                else:
                    stale = arrival['status'] == core.OK and not arrival['published']
                    assert status == (core.STALE if stale else core.OK)
                    assert len(f.callbacks) == int(not stale)
                    if arrival['status'] == core.BUSY: assert f.bind(newer) == core.OK
                # A post-reset admission may be waiting behind the pending reset;
                # that lease cannot execute before the reset has finished.
                assert f.claim(newer)[0] == core.OK
                assert f.finish(newer, 0) == core.OK
                if operation == 'bind' and f.bound(n)[0] == f.state()['media']:
                    assert f.claim(n)[0] == core.OK
                    assert f.finish(n, 0) == core.OK
                record('reset at adapter instruction boundary', f, operation=operation, at=hex(at), arrival=arrival)

            # Two callers acting on the same record must not allocate a second
            # generation/sequence, lease or publication. The second token output
            # is separate so a winning caller cannot overwrite the first output.
            probe = Fixture(moved, delta); n = probe.ready(0, core.SHUFFLE)
            if operation != 'bind': assert probe.bind(n) == core.OK
            if operation == 'finish': assert probe.claim(n)[0] == core.OK
            a = probe.machine('control')
            assert probe.invoke(entry, args, m=a) == core.OK
            for at in sorted(set(a.visited)):
                f = Fixture(moved, delta); n = f.ready(0, core.SHUFFLE)
                if operation != 'bind': assert f.bind(n) == core.OK
                if operation == 'finish': assert f.claim(n)[0] == core.OK
                a = f.machine('control'); a.inject_at = at
                duplicate = []
                other_args = [n, OUT+4] if operation == 'claim' else args
                a.inject = lambda: duplicate.append(f.invoke(entry, other_args, name='producer'))
                status = f.invoke(entry, args, m=a)
                assert a.inject is None and len(duplicate) == 1
                allowed = (core.OK, core.BUSY, p.ALREADY_OWNED) if operation == 'claim' else (core.OK, core.BUSY)
                assert status in allowed and duplicate[0] in allowed, (
                    operation, hex(at), status, duplicate[0], f.m.read(n+24), f.state())
                if operation == 'bind':
                    assert f.bind(n) == core.OK
                    assert f.bound(n) == (0, 1) and f.state()['seq_shuffle'] == 1
                    assert f.claim(n)[0] == core.OK
                    assert f.finish(n, 0) == core.OK
                elif operation == 'claim':
                    assert f.m.read(n+24) == p.CLAIMED and f.state()['next_token'] == 1
                    assert f.finish(n, 0) == core.OK
                else:
                    assert f.finish(n) == core.OK and len(f.callbacks) == 1
                    assert f.m.read(n+24) == p.FINISHED and f.state()['active_token'] == 0
                record('duplicate caller at adapter instruction boundary', f, operation=operation,
                       at=hex(at), status=status, duplicate_status=duplicate[0])

    proxy = SimpleNamespace(**vars(queue))
    proxy.patch = lambda source: p.patch(queue.patch(source)[0])
    kept = FunctionType(previous.verify.__code__, dict(previous.verify.__globals__, p=proxy),
                         argdefs=previous.verify.__defaults__)(raw)
    old = json.loads((Path(__file__).resolve().parents[1]/'analysis/firmware/usb-deferred-requests.json').read_bytes())
    assert old['cases'] == kept['cases'] == 1336 and old['traces'] == kept['traces']
    assert old['retained_trace_sha256'] == kept['retained_trace_sha256'] and kept['retained_cases'] == 540
    assert p.patch(prior)[0] == written
    return dict(cases=len(traces), candidate_sha256=recipe['sha256'], patch=recipe, traces=traces,
                retained_queue_cases=1336, retained_ownership_cases=540,
                native_executed=False, hardware_tested=False,
                limits=['Unwired 40-byte records; allocation/pool, retry scheduler and real worker/reset hooks remain absent',
                        'Queue/admission defaults still accept 32-byte records; BIND/CLAIM_RECORD require private live 40-byte records',
                        'Callback must publish already-prepared results and return; original long worker bodies are not dispatched here',
                        'Callback failure can follow partial external writes; cached failure is not rollback',
                        'Atomic operations, callbacks and CPU scheduling are fixtures, not CE memory-ordering or timing proof',
                        'Bound receipt alone is not a lease or a thread-exit receipt; records must remain live until their owner drains'])


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
    print(json.dumps(dict(cases=report['cases'], retained_queue_cases=1336, retained_ownership_cases=540,
                         candidate_sha256=report['candidate_sha256'])))
