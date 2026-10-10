"""Execute unwired ownership MIPS bytes against explicit atomic/API fixtures.

Separate contexts share protocol memory. This is not a Windows CE scheduler,
memory-ordering measurement, integrated worker fix, or hardware test.
"""
import argparse
import hashlib
import json
from pathlib import Path
from types import FunctionType

from inspect_bt_pairing import put
import patch_usb_lifecycle_protocol as p
from verify_media_responsiveness import call, parsed
from verify_usb_catalog_readiness import TraceVM
from verify_usb_catalog_recovery import Scan
from verify_usb_input_safety import relocated
from verify_usb_shuffle_lifecycle import Fixture as Native, PLAY, USB, SYSTEM

OUT, CALLBACK, CONTEXT = 0x55000000, 0xf2000010, 0x55000100


class ProtocolVM(TraceVM):
    def plain(self, word):
        self.visited.append(self.pc)
        if self.inject is not None and self.pc == self.inject_at:
            fn, self.inject = self.inject, None
            fn()
        super().plain(word)


class Fixture:
    def __init__(self, raw, delta):
        self.raw, self.delta = raw, delta
        self.mem, self.events, self.callbacks = {}, [], []
        self.callback = lambda m: 0
        self.m = self.machine('owner')
        put(self.m, p.STATE+delta, bytes(p.STATE_BYTES))
        put(self.m, OUT, bytes(16))
        self.m.write(p.STATE+delta-4, 0xa55aa55a)
        self.m.write(p.STATE+delta+p.STATE_BYTES, 0xa55aa55a)

    def machine(self, name):
        m = ProtocolVM(self.raw, [(a, a+n) for a, n, *_ in p.HELPERS], self.delta)
        m.visited, m.inject, m.inject_at = [], None, None
        m.mem = self.mem; m.name = name
        m.write(0x2f1c4+self.delta, 0xf2000000)
        m.write(0x2f1b8+self.delta, 0xf2000004)
        m.hooks.update({0xf2000000: self.compare_exchange,
                        0xf2000004: self.exchange, CALLBACK: self.publish})
        return m

    def compare_exchange(self, m):
        at, value, expected = m.reg[4:7]
        assert at == p.STATE+self.delta and value == 1 and expected == 0
        old = m.read(at)
        if old == expected: m.write(at, value)
        self.events.append(dict(context=m.name, api='InterlockedCompareExchange', old=old))
        Scan.clobber(m)
        return old

    def exchange(self, m):
        at, value = m.reg[4:6]
        assert at == p.STATE+self.delta and value == 0 and m.read(at) == 1
        m.write(at, value)
        self.events.append(dict(context=m.name, api='InterlockedExchange', old=1))
        Scan.clobber(m)
        return 1

    def publish(self, m):
        assert m.reg[4] == CONTEXT and m.read(p.STATE+self.delta) == 1
        self.callbacks.append(self.snapshot())
        result = self.callback(m)
        Scan.clobber(m)
        return result

    def invoke(self, at, args=(), other=False):
        m = self.machine('request') if other else self.m
        context = dict(call.__globals__, STACK=0x69000000 if other else 0x68000000)
        result = FunctionType(call.__code__, context, argdefs=call.__defaults__)(
            m, at+self.delta, list(args))
        assert m.read(p.STATE+self.delta-4) == 0xa55aa55a
        assert m.read(p.STATE+self.delta+p.STATE_BYTES) == 0xa55aa55a
        return result

    def snapshot(self):
        return {name: self.m.read(p.STATE+self.delta+4*i) for i, name in enumerate(p.FIELDS)}

    def set(self, name, value):
        self.m.write(p.STATE+self.delta+4*p.FIELDS.index(name), value)

    def submit(self, kind): return self.invoke(p.SUBMIT, [kind])
    def claim(self, kind):
        result = self.invoke(p.CLAIM, [kind, OUT])
        return result, self.m.read(OUT)
    def finish(self, token, callback=CALLBACK):
        return self.invoke(p.FINISH, [token, callback, CONTEXT])


def verify(raw):
    written, recipe = p.patch(raw)
    traces = []
    def record(name, f, **extra):
        assert f.snapshot()['lock'] == 0
        traces.append(dict(name=name, delta=hex(f.delta), state=f.snapshot(),
                           callbacks=len(f.callbacks), atomics=f.events, **extra))

    for delta in (0, 0x1000, 0x10000, 0x123000):
        moved = relocated(written, delta) if delta else written
        for active in range(4):
            for newer in range(4):
                f = Fixture(moved, delta)
                assert f.submit(active) == p.OK
                status, token = f.claim(active); assert status == p.OK and token == 1
                assert f.submit(newer) == p.OK
                assert f.claim(newer)[0] == p.BUSY
                stale = newer == p.RESET or newer == active
                assert f.finish(token) == (p.STALE if stale else p.OK)
                assert len(f.callbacks) == int(not stale)
                assert f.snapshot()['active_token'] == 0
                assert f.claim(newer)[0] == p.OK
                assert f.finish(f.m.read(OUT), 0) == p.OK
                record('new request while owned', f, active=active, newer=newer)

        for kind in range(4):
            f = Fixture(moved, delta)
            for _ in range(8): assert f.submit(kind) == p.OK
            assert f.snapshot()['pending_mask'] == 1 << kind
            status, token = f.claim(kind); assert status == p.OK
            assert f.snapshot()['active_seq'] == 8
            assert f.finish(token) == p.OK
            assert f.claim(kind)[0] == p.NOT_PENDING
            assert f.finish(token) == p.STALE and len(f.callbacks) == 1
            record('coalescing and duplicate completion', f, kind=kind)

            f = Fixture(moved, delta)
            assert f.submit(kind) == p.OK
            status, token = f.claim(kind); assert status == p.OK
            assert f.finish(token+1) == p.STALE
            assert f.snapshot()['active_token'] == token
            assert f.finish(token) == p.OK
            assert f.submit(kind) == p.OK
            assert f.claim(kind)[0] == p.OK
            newer_token = f.m.read(OUT); assert newer_token == token+1
            assert f.finish(token) == p.STALE and f.snapshot()['active_token'] == newer_token
            assert f.finish(newer_token) == p.OK
            record('wrong and older tokens never drain newer owner', f, kind=kind)

            f = Fixture(moved, delta)
            assert f.submit(kind) == p.OK
            _, token = f.claim(kind)
            assert f.invoke(p.CLOSE) == p.DRAINING
            assert f.submit(kind) == p.CLOSED and f.claim(kind)[0] == p.CLOSED
            assert f.finish(token) == p.STALE and not f.callbacks
            assert f.snapshot()['active_token'] == 0
            assert f.invoke(p.CLOSE) == p.OK
            record('close then drain', f, kind=kind)

            for newer in range(4):
                f = Fixture(moved, delta)
                assert f.submit(kind) == p.OK
                _, token = f.claim(kind)
                deferred = []
                def interleave(m):
                    before = f.snapshot()
                    assert f.invoke(p.SUBMIT, [newer], other=True) == p.BUSY
                    assert f.invoke(p.CLOSE, other=True) == p.BUSY
                    assert f.invoke(p.FINISH, [token, 0, 0], other=True) == p.BUSY
                    assert f.snapshot() == before
                    deferred.append(newer)  # Caller-owned retry, not a native queue.
                    return 0
                f.callback = interleave
                assert f.finish(token) == p.OK and len(f.callbacks) == 1
                assert f.submit(deferred.pop()) == p.OK
                assert f.claim(newer)[0] == p.OK
                assert f.finish(f.m.read(OUT), 0) == p.OK
                record('publication protected through callback; caller retries BUSY', f,
                       kind=kind, newer=newer)

        # Counter exhaustion closes the protocol rather than wrapping into an old lease.
        for field in ('media', 'next_token', 'seq_reset', 'seq_normal', 'seq_boot', 'seq_shuffle'):
            for initial in (0xfffffffe, 0xffffffff):
                f = Fixture(moved, delta)
                if field == 'next_token':
                    f.set(field, initial); assert f.submit(p.NORMAL) == p.OK
                    result, token = f.claim(p.NORMAL)
                    if initial == 0xfffffffe:
                        assert result == p.OK and token == 0xffffffff
                        assert f.finish(token) == p.OK
                        assert f.submit(p.NORMAL) == p.OK
                        result, _ = f.claim(p.NORMAL)
                else:
                    f.set(field, initial)
                    kind = p.RESET if field == 'media' else p.FIELDS.index(field)-8
                    result = f.submit(kind)
                    if initial == 0xfffffffe:
                        assert result == p.OK and f.snapshot()[field] == 0xffffffff
                        result = f.submit(kind)
                assert result == p.EXHAUSTED and f.snapshot()['closed'] == 1
                assert f.snapshot()[field] == 0xffffffff
                assert f.submit(p.NORMAL) == p.CLOSED
                record('counter saturation', f, field=field, initial=hex(initial))

        f = Fixture(moved, delta)
        for kind in (p.NORMAL, p.BOOT, p.SHUFFLE, p.RESET, p.NORMAL, p.BOOT, p.SHUFFLE):
            assert f.submit(kind) == p.OK
        assert f.snapshot()['pending_mask'] == 15
        for kind in (p.NORMAL, p.BOOT, p.SHUFFLE): assert f.claim(kind)[0] == p.BUSY
        for kind in range(4):
            assert f.claim(kind)[0] == p.OK
            assert f.finish(f.m.read(OUT), 0) == p.OK
        assert f.snapshot()['pending_mask'] == 0
        record('reset priority then all three worker kinds', f)

        f = Fixture(moved, delta)
        assert f.submit(p.SHUFFLE) == p.OK
        _, token = f.claim(p.SHUFFLE)
        f.callback = lambda m: 9
        assert f.finish(token) == p.CALLBACK_FAILED
        assert f.snapshot()['active_token'] == 0
        record('callback failure drains owner', f)

        f = Fixture(moved, delta)
        before = f.snapshot()
        for at, args in ((p.SUBMIT, [4]), (p.SUBMIT, [0xffffffff]),
                         (p.CLAIM, [4, OUT]), (p.CLAIM, [0, 0]), (p.CLAIM, [0, OUT+1]),
                         (p.FINISH, [0, CALLBACK, CONTEXT]), (p.FINISH, [1, CALLBACK+1, CONTEXT])):
            assert f.invoke(at, args) == p.INVALID and f.snapshot() == before
        f.set('lock', 1); before = f.snapshot()
        for at, args in ((p.SUBMIT, [0]), (p.CLAIM, [0, OUT]),
                         (p.FINISH, [1, 0, 0]), (p.CLOSE, [])):
            count = len(f.events)
            assert f.invoke(at, args) == p.BUSY and f.snapshot() == before
            assert len(f.events) == count+1  # One CAS, no release/spin/wait.
        f.set('lock', 0)
        record('invalid inputs and gate contention', f)

        # Link primitive ownership to the real reset instructions from PR-42.
        f = Fixture(moved, delta)
        native = Native(moved, delta)
        native.invoke(0x1ddb0, [USB, 1])
        native.control.write(PLAY+0xe4c, 4)
        native.control.write(PLAY+0xe5c, 0x30108+delta)
        assert f.submit(p.SHUFFLE) == p.OK
        _, token = f.claim(p.SHUFFLE)
        assert f.submit(p.RESET) == p.OK
        assert f.finish(token) == p.STALE and not f.callbacks
        assert native.snapshot()['count'] == 4  # Deferred reset has not run yet.
        assert f.claim(p.RESET)[0] == p.OK
        reset_token = f.m.read(OUT)
        def reset(m):
            native.invoke(0x1db80, [USB])
            native.invoke(0x12e80, [native.control.read(SYSTEM+0x48)])
            return 0
        f.callback = reset
        assert f.finish(reset_token) == p.OK
        after = native.snapshot()
        assert after['count'] == after['pointer'] == after['enabled'] == 0
        record('leased callback executes actual USB/artwork/catalog reset', f, reset=after)

        # Inject a request before every reached non-control instruction, including
        # branch delay slots and atomic call wrappers. The callback is a fixture;
        # all ownership checks, stores, gate acquisition/release are MIPS bytes.
        probe = Fixture(moved, delta)
        assert probe.submit(p.SHUFFLE) == p.OK
        _, token = probe.claim(p.SHUFFLE)
        probe.m.visited.clear()
        assert probe.finish(token) == p.OK
        points = sorted(set(probe.m.visited))
        for at in points:
            f = Fixture(moved, delta)
            assert f.submit(p.SHUFFLE) == p.OK
            _, token = f.claim(p.SHUFFLE)
            injection = []
            def request():
                before = f.snapshot()
                published = len(f.callbacks)
                status = f.invoke(p.SUBMIT, [p.RESET], other=True)
                injection.append(dict(status=status, lock=before['lock'], published=published))
                assert status == (p.BUSY if before['lock'] else p.OK)
                if status == p.BUSY: assert f.snapshot() == before
            f.m.inject_at, f.m.inject = at, request
            status = f.finish(token)
            assert len(injection) == 1
            arrived = injection[0]
            stale = arrived['status'] == p.OK and not arrived['published']
            assert status == (p.STALE if stale else p.OK)
            assert len(f.callbacks) == int(not stale)
            if arrived['status'] == p.BUSY:
                assert f.submit(p.RESET) == p.OK  # Explicit caller retry after publication.
            assert f.snapshot()['active_token'] == 0
            assert f.snapshot()['pending_mask'] == 1
            record('reset at completion instruction boundary', f, at=hex(at), arrival=arrived)

        for kind in range(4):
            f = Fixture(moved, delta)
            assert f.submit(kind) == p.OK
            _, token = f.claim(kind)
            f.set(p.FIELDS[8+kind], 0xffffffff)
            assert f.submit(kind) == p.EXHAUSTED
            assert f.finish(token) == p.STALE and not f.callbacks
            assert f.snapshot()['active_token'] == 0
            record('exhaustion invalidates and drains existing owner', f, kind=kind)

    assert p.patch(raw)[0] == written
    old, new = parsed(raw), parsed(written)
    assert old.get_data(0x1000, 0x15000) == new.get_data(0x1000, 0x15000)
    assert [(s.VirtualAddress, s.SizeOfRawData, s.Characteristics) for s in old.sections] == [
        (s.VirtualAddress, s.SizeOfRawData, s.Characteristics) for s in new.sections]
    imports_directory = old.OPTIONAL_HEADER.DATA_DIRECTORY[1]
    assert (imports_directory.VirtualAddress, imports_directory.Size) == (
        new.OPTIONAL_HEADER.DATA_DIRECTORY[1].VirtualAddress,
        new.OPTIONAL_HEADER.DATA_DIRECTORY[1].Size)
    assert old.get_data(imports_directory.VirtualAddress, imports_directory.Size) == new.get_data(
        imports_directory.VirtualAddress, imports_directory.Size)
    imports = {i.address: i.ordinal for d in old.DIRECTORY_ENTRY_IMPORT for i in d.imports}
    assert imports[0x2f1c4] == 1492 and imports[0x2f1b8] == 12
    return dict(cases=len(traces), candidate_sha256=recipe['sha256'], patch=recipe,
                traces=traces, native_executed=False, hardware_tested=False,
                limits=['Unwired helpers: existing worker/reset call sites remain unchanged',
                        'Atomic imports and scheduling are fixtures; no CE memory-ordering proof',
                        'BUSY inputs are retained/retried by the test caller; native adapter not implemented',
                        'One process-local state block; no per-object lifecycle, thread join or shutdown receipt',
                        'Reset callback executes real reset instructions with filesystem/status/API fixtures',
                        'Callback requires valid aligned executable address and must return; no exception recovery',
                        'Active-token drain does not prove a native thread has exited'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', required=True, type=Path)
    parser.add_argument('--report', required=True, type=Path)
    args = parser.parse_args()
    raw = args.input.read_bytes()
    report = verify(raw)
    assert args.input.read_bytes() == raw
    report['verifier_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    report['patcher_sha256'] = hashlib.sha256(Path(p.__file__).read_bytes()).hexdigest()
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_bytes((json.dumps(report, indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=report['cases'], candidate_sha256=report['candidate_sha256'])))
