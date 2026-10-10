"""Execute native request FIFO bytes under controlled producer/consumer schedules.

Atomic/event operations are fixtures. No CE scheduler, allocation, worker/reset
dispatch, thread cancellation or hardware installation is implemented here.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
from types import FunctionType, SimpleNamespace

from inspect_bt_pairing import put, data
import patch_usb_deferred_requests as p
import patch_usb_lifecycle_protocol as ownership
import verify_usb_lifecycle_protocol as retained
from verify_media_responsiveness import call
from verify_usb_catalog_readiness import TraceVM
from verify_usb_catalog_recovery import Scan, USB, SYSTEM
from verify_usb_input_safety import relocated
from verify_usb_shuffle_lifecycle import Fixture as Native
from verify_usb_scan_coordination import NORMAL, BOOT

NODE, OUT, EVENT = 0x56000000, 0x55000000, 0x7010


class Machine(TraceVM):
    def plain(self, word):
        self.visited.append(self.pc)
        if self.inject is not None and self.pc == self.inject_at:
            fn, self.inject = self.inject, None
            fn()
        super().plain(word)

    def write(self, at, value, size=4):
        assert not any(a <= at < a+32 or at <= a < at+size for a in self.retired), 'Write to retired node'
        super().write(at, value, size)


class Fixture:
    def __init__(self, raw, delta, event=EVENT):
        self.raw, self.delta = raw, delta
        self.mem, self.nodes, self.retired = {}, set(), set()
        self.events, self.signals, self.atomics, self.wake_ok = set(), [], [], True
        self.m = self.machine('control')
        put(self.m, p.QUEUE+delta, bytes(p.QUEUE_BYTES))
        self.m.write(p.QUEUE+delta-4, 0xa55aa55a)
        self.m.write(p.QUEUE+delta+p.QUEUE_BYTES, 0xa55aa55a)
        put(self.m, OUT, bytes(12))
        assert self.invoke(p.INIT, [event]) == p.OK

    def machine(self, name):
        m = Machine(self.raw, [(a, a+n) for a, n, *_ in (*p.HELPERS, *ownership.HELPERS)], self.delta)
        m.mem, m.retired, m.name = self.mem, self.retired, name
        m.visited, m.inject, m.inject_at = [], None, None
        m.write(0x2f1c4+self.delta, 0xf3000000)
        m.write(0x2f1b8+self.delta, 0xf3000004)
        m.hooks.update({0xf3000000: self.compare_exchange,
                        0xf3000004: self.exchange, 0x2522c+self.delta: self.signal})
        return m

    def compare_exchange(self, m):
        at, value, expected = m.reg[4:7]
        q = p.QUEUE+self.delta
        assert (expected == 0 and value == 0 and
                (at in (q, q+8) or at in self.nodes or at-24 in self.nodes) or
                expected == 0 and value == 1 and
                (at in (q+12, ownership.STATE+self.delta) or at-24 in self.nodes) or
                expected == p.DEQUEUED and value == p.SUBMITTING and at-24 in self.nodes), (hex(at), value, expected)
        old = m.read(at)
        if old == expected: m.write(at, value)
        self.atomics.append(dict(context=m.name, operation='compare_exchange', at=hex(at), old=old, value=value))
        Scan.clobber(m)
        return old

    def exchange(self, m):
        at, value = m.reg[4:6]
        q = p.QUEUE+self.delta
        assert at in (q, q+8, q+12, q+16, ownership.STATE+self.delta) or at in self.nodes or at-24 in self.nodes
        old = m.read(at); m.write(at, value)
        self.atomics.append(dict(context=m.name, operation='exchange', at=hex(at), old=old, value=value))
        Scan.clobber(m)
        return old

    def signal(self, m):
        assert m.reg[4:6] == [EVENT, 3]
        self.signals.append(dict(context=m.name, result=self.wake_ok))
        if self.wake_ok: self.events.add(EVENT)
        Scan.clobber(m)
        return int(self.wake_ok)

    def invoke(self, at, args=(), name='control', m=None):
        m = m or (self.m if name == 'control' else self.machine(name))
        stack = dict(control=0x68000000, producer=0x68100000, consumer=0x68200000)[name]
        context = dict(call.__globals__, STACK=stack)
        result = FunctionType(call.__code__, context, argdefs=call.__defaults__)(m, at+self.delta, list(args))
        q = p.QUEUE+self.delta
        assert m.read(q-4) == m.read(q+p.QUEUE_BYTES) == 0xa55aa55a
        for node in self.nodes:
            assert m.read(node-4) == m.read(node+32) == 0xa55aa55a
        return result

    def node(self, index, kind=None, args=None):
        at = NODE+index*0x40
        self.retired.discard(at); self.nodes.add(at)
        values = [0, index % 4 if kind is None else kind,
                  *(args if args is not None else (USB, 0xabcd0000+index, index % 2)), index, 0, 0]
        assert len(values) == 8
        put(self.m, at, b''.join(v.to_bytes(4, 'little') for v in values))
        self.m.write(at-4, 0xa55aa55a); self.m.write(at+32, 0xa55aa55a)
        return at

    def payload(self, node): return data(self.m, node+4, 20).hex()

    def pop(self, retire=False, name='consumer'):
        sentinel = 0xdeadbeef
        self.m.write(OUT, sentinel)
        status = self.invoke(p.POP, [OUT], name=name)
        node = self.m.read(OUT)
        if status == p.OK:
            assert node in self.nodes and node not in self.retired
            assert self.m.read(node+24) == p.DEQUEUED
            if retire:
                self.retired.add(node)
                for i in range(32): self.mem.pop(node+i)
        else: assert node == sentinel
        return status, node if status == p.OK else None

    def snapshot(self):
        q = p.QUEUE+self.delta
        return dict(head=hex(self.m.read(q)), tail=hex(self.m.read(q+4)),
                    stub_next=hex(self.m.read(q+8)), consumer_busy=self.m.read(q+12))


def verify(raw, full_atomics=False):
    core, _ = ownership.patch(raw)
    written, recipe = p.patch(core)
    traces = []
    def record(name, f, **extra):
        assert f.snapshot()['consumer_busy'] == 0
        atomics = f.atomics if full_atomics else dict(
            calls=len(f.atomics), operations=dict(Counter(e['operation'] for e in f.atomics)),
            sha256=hashlib.sha256(json.dumps(f.atomics, sort_keys=True).encode()).hexdigest())
        traces.append(dict(name=name, delta=hex(f.delta), queue=f.snapshot(),
                           signals=f.signals, atomics=atomics, **extra))

    for delta in (0, 0x1000, 0x10000, 0x123000):
        moved = relocated(written, delta) if delta else written
        for count in (1, 2, 4, 8, 32):
            f = Fixture(moved, delta)
            nodes = [f.node(i) for i in range(count)]
            expected = [f.payload(n) for n in nodes]
            for n in nodes: assert f.invoke(p.PUSH, [n], name='producer') == p.OK
            actual = []
            for n, payload in zip(nodes, expected):
                status, out = f.pop(); assert status == p.OK and out == n
                actual.append(f.payload(out)); assert actual[-1] == payload
                f.retired.add(out)
                for i in range(32): f.mem.pop(out+i)
            assert f.pop()[0] == p.NOT_PENDING
            assert f.m.read(p.QUEUE+delta) == f.m.read(p.QUEUE+delta+4) == p.QUEUE+delta+8
            record('FIFO payload and retirement', f, count=count, payloads=actual)

        f = Fixture(moved, delta)
        for i in range(20):
            n = f.node(0, kind=i % 4, args=(USB, i, 1))
            before = f.payload(n)
            assert f.invoke(p.PUSH, [n]) == p.OK
            assert f.pop() == (p.OK, n) and f.payload(n) == before
            f.retired.add(n)
        assert f.pop()[0] == p.NOT_PENDING
        record('returned node reused after transfer', f)

        for event, wake_ok in ((0, True), (EVENT, False)):
            f = Fixture(moved, delta, event=event); f.wake_ok = wake_ok
            n = f.node(0)
            assert f.invoke(p.PUSH, [n]) == (p.OK if wake_ok else p.WAKE_FAILED)
            assert f.pop(retire=True) == (p.OK, n)
            assert f.pop()[0] == p.NOT_PENDING
            record('poll-only or failed wake retains accepted record', f, event=event, wake_ok=wake_ok)

        f = Fixture(moved, delta)
        before = f.snapshot()
        assert f.invoke(p.INIT, [EVENT]) == p.INVALID and f.snapshot() == before
        for args in ([0], [NODE+1], [p.QUEUE+delta+8]): assert f.invoke(p.PUSH, args) == p.INVALID
        n = f.node(0, kind=4)
        assert f.invoke(p.PUSH, [n]) == p.INVALID and f.m.read(n+24) == p.NEW
        n = f.node(0)
        assert f.invoke(p.PUSH, [n]) == p.OK
        state, payload = f.snapshot(), f.payload(n)
        assert f.invoke(p.PUSH, [n]) == p.INVALID
        assert f.snapshot() == state and f.payload(n) == payload
        f.m.write(p.QUEUE+delta+12, 1)
        assert f.pop()[0] == p.BUSY
        f.m.write(p.QUEUE+delta+12, 0)
        for args in ([0], [OUT+1]): assert f.invoke(p.POP, args) == p.INVALID
        assert f.pop(retire=True) == (p.OK, n)
        record('invalid input duplicate post and second consumer', f)

        # A paused producer can leave a link gap. A later completed producer must
        # not disappear, reorder ahead of it, or make POP spin waiting for it.
        probe = Fixture(moved, delta); n = probe.node(0)
        producer = probe.machine('producer')
        assert probe.invoke(p.PUSH, [n], name='producer', m=producer) == p.OK
        push_points = sorted(set(producer.visited))
        for at in push_points:
            f = Fixture(moved, delta)
            first, second = f.node(0), f.node(1)
            a = f.machine('control')
            interleaved = []
            def concurrent():
                assert f.invoke(p.PUSH, [second], name='producer') == p.OK
                outputs = []
                for _ in range(3):
                    status, node = f.pop(retire=True)
                    if status == p.OK: outputs.append(node)
                    else: break
                interleaved.append(dict(status=status, outputs=outputs))
            a.inject_at, a.inject = at, concurrent
            assert f.invoke(p.PUSH, [first], m=a) == p.OK
            assert len(interleaved) == 1
            outputs = interleaved[0]['outputs'].copy()
            while True:
                status, node = f.pop(retire=True)
                if status != p.OK: break
                outputs.append(node)
            assert status == p.NOT_PENDING and sorted(outputs) == [first, second]
            head_exchanges = [e['value'] for e in f.atomics if e['operation'] == 'exchange' and
                              e['at'] == hex(p.QUEUE+delta) and e['value'] in (first, second)]
            assert outputs == head_exchanges
            record('producer boundary with second producer and consumer', f,
                   at=hex(at), interim=interleaved[0], outputs=list(map(hex, outputs)))

        # Pause POP at every reached instruction; an intervening PUSH must not
        # access the node already returned to the consumer on the previous pop.
        probe = Fixture(moved, delta); n = probe.node(0)
        assert probe.invoke(p.PUSH, [n]) == p.OK
        consumer = probe.machine('consumer')
        assert probe.invoke(p.POP, [OUT], name='consumer', m=consumer) == p.OK
        pop_points = sorted(set(consumer.visited))
        for at in pop_points:
            f = Fixture(moved, delta)
            first, second = f.node(0), f.node(1)
            assert f.invoke(p.PUSH, [first]) == p.OK
            c = f.machine('consumer'); c.inject_at = at
            c.inject = lambda: f.invoke(p.PUSH, [second], name='producer')
            status = f.invoke(p.POP, [OUT], name='consumer', m=c)
            assert c.inject is None and status in (p.OK, p.BUSY), (hex(at), status)
            if status == p.BUSY:
                assert f.pop() == (p.OK, first)
            else:
                assert f.m.read(OUT) == first
            f.retired.add(first)
            for i in range(32): f.mem.pop(first+i)
            assert f.pop(retire=True) == (p.OK, second)
            assert f.pop()[0] == p.NOT_PENDING
            record('consumer boundary with intervening producer', f, at=hex(at), first_status=status)

        # Real event-woken worker argument loads, captured before their long body.
        native = Native(moved, delta)
        native.control.write(SYSTEM+0xc, 1)
        native.invoke(0x1ddb0, [USB, 1])
        native.control.write(USB+0x2926, 37)
        f = Fixture(moved, delta)
        expected = []
        for index, (kind, signal, worker, body, arity) in enumerate((
                (ownership.NORMAL, 0x22f80, 0x22b40, 0x1ef48, 3),
                (ownership.BOOT, 0x22fac, 0x22bd8, 0x1fd6c, 2),
                (ownership.SHUFFLE, 0x22f54, 0x22a8c, 0x1dd94, 3))):
            native.invoke(signal, [])
            m = native.machine('capture')
            native.prime(m, 0x68400000, [])
            m.run(worker+delta, {body+delta})
            args = m.reg[4:4+arity]+[0]*(3-arity)
            expected.append(args)
            n = f.node(index, kind=kind, args=args)
            assert f.invoke(p.PUSH, [n]) == p.OK
        assert expected == [[USB, 1, 0], [USB, 1, 0], [USB, 37, 0]]
        for index, args in enumerate(expected):
            status, n = f.pop(); assert status == p.OK and n == NODE+index*0x40
            assert [f.m.read(n+8+4*i) for i in range(3)] == args
        assert f.pop()[0] == p.NOT_PENDING
        record('real worker argument loads retained', f, args=expected)

        for kind in range(4):
            f = Fixture(moved, delta)
            n = f.node(0, kind=kind); payload = f.payload(n)
            assert f.invoke(p.ACCEPT, [n]) == p.INVALID
            assert f.invoke(p.PUSH, [n]) == p.OK
            assert f.invoke(p.ACCEPT, [n]) == p.INVALID  # Still queue-owned.
            assert f.pop() == (p.OK, n)
            state = ownership.STATE+delta
            f.m.write(state, 1)
            for _ in range(4):
                assert f.invoke(p.ACCEPT, [n]) == p.BUSY
                assert f.m.read(n+24) == p.DEQUEUED and f.payload(n) == payload
            f.m.write(state, 0)
            assert f.invoke(p.ACCEPT, [n]) == p.OK
            seq = f.m.read(state+32+4*kind); assert seq == 1
            assert f.m.read(n+24) == p.ADMITTED
            for _ in range(4): assert f.invoke(p.ACCEPT, [n]) == p.OK
            assert f.m.read(state+32+4*kind) == seq and f.payload(n) == payload
            assert f.invoke(ownership.CLAIM, [kind, OUT+4]) == p.OK
            token = f.m.read(OUT+4)
            assert f.invoke(ownership.FINISH, [token, 0, 0]) == p.OK
            record('native admission retries BUSY exactly once', f, kind=kind, token=token)

            for exhausted in (False, True):
                f = Fixture(moved, delta)
                n = f.node(0, kind=kind)
                assert f.invoke(p.PUSH, [n]) == p.OK and f.pop() == (p.OK, n)
                if exhausted: f.m.write(state+32+4*kind, 0xffffffff)
                else: f.m.write(state+48, 1)
                expected_status = ownership.EXHAUSTED if exhausted else ownership.CLOSED
                assert f.invoke(p.ACCEPT, [n]) == expected_status
                assert f.m.read(n+24) == p.REJECTED and f.m.read(n+28) == expected_status
                assert f.invoke(p.ACCEPT, [n]) == expected_status
                record('native admission records terminal rejection', f, kind=kind, exhausted=exhausted)

        probe = Fixture(moved, delta)
        n = probe.node(0, kind=ownership.SHUFFLE)
        assert probe.invoke(p.PUSH, [n]) == p.OK and probe.pop() == (p.OK, n)
        a = probe.machine('control')
        assert probe.invoke(p.ACCEPT, [n], m=a) == p.OK
        for at in sorted(set(a.visited)):
            f = Fixture(moved, delta)
            n = f.node(0, kind=ownership.SHUFFLE)
            assert f.invoke(p.PUSH, [n]) == p.OK and f.pop() == (p.OK, n)
            a = f.machine('control'); a.inject_at = at
            concurrent = []
            a.inject = lambda: concurrent.append(f.invoke(p.ACCEPT, [n], name='producer'))
            assert f.invoke(p.ACCEPT, [n], m=a) in (p.OK, p.BUSY)
            assert a.inject is None and concurrent[0] in (p.OK, p.BUSY)
            assert f.invoke(p.ACCEPT, [n]) == p.OK
            assert f.m.read(ownership.STATE+delta+44) == 1
            record('concurrent admission at instruction boundary', f, at=hex(at), other_status=concurrent[0])

    # Frozen PR-43 tests execute against the added queue binary; compare all old
    # traces rather than assuming unused extra helpers preserve prior behaviour.
    before = retained.verify(raw)
    proxy = SimpleNamespace(**vars(ownership))
    proxy.patch = lambda source: p.patch(ownership.patch(source)[0])
    after = FunctionType(retained.verify.__code__, dict(retained.verify.__globals__, p=proxy))(raw)
    assert before['traces'] == after['traces'] and before['cases'] == after['cases'] == 540
    assert p.patch(core)[0] == written
    return dict(cases=len(traces), candidate_sha256=recipe['sha256'], patch=recipe,
                traces=traces, retained_cases=540,
                retained_trace_sha256=hashlib.sha256(json.dumps(after['traces'], sort_keys=True).encode()).hexdigest(),
                native_executed=False, hardware_tested=False,
                limits=['Unwired queue/admission; caller allocation/pool, retry scheduler and worker/reset dispatch remain to implement',
                        'Caller supplies immutable live 32-byte nodes; memory remains owned by queue until POP returns',
                        'Producers may not be terminated between head exchange and predecessor-link publication',
                        'POP can return BUSY until a paused producer resumes; there is no native retry timer yet',
                        'Wake failure reports accepted ownership; caller must not repost or free that node',
                        'One-time initialization precedes producers; no concurrent initialization or shutdown proof',
                        'Atomic/event operations and CPU scheduling are fixtures; no CE ordering or timing measurement',
                        'Real worker parameter loads execute; long scan/shuffle bodies are not dispatched by this queue'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', required=True, type=Path)
    parser.add_argument('--report', required=True, type=Path)
    parser.add_argument('--full-atomics', action='store_true', help='Include every atomic fixture call instead of its count/digest')
    args = parser.parse_args()
    raw = args.input.read_bytes(); report = verify(raw, args.full_atomics)
    assert args.input.read_bytes() == raw
    report['verifier_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    report['patcher_sha256'] = hashlib.sha256(Path(p.__file__).read_bytes()).hexdigest()
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_bytes((json.dumps(report, indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=report['cases'], retained_cases=540,
                         candidate_sha256=report['candidate_sha256'])))
