"""Actual duration/seek/controller instructions with explicit COM/OS responses."""
import hashlib
import itertools
import struct
from types import FunctionType

import pefile

from inspect_bt_pairing import put
from inspect_wave_queue import STOP
from verify_media_responsiveness import STACK
from verify_usb_playback_recovery import Recovery
from verify_usb_seek_timing import UNIT, UI
from verify_usb_graph_state import E_FAIL
from verify_usb_input_safety import relocated
from patch_usb_duration_output import BASE, BASE_SHA, HELPERS, SITES


class Duration(Recovery):
    def __init__(self, *args, **kwargs):
        self.low_only = kwargs.pop('low_only', False)
        super().__init__(*args, **kwargs)
        self.vm.ranges.extend((a+self.delta, a+n+self.delta) for a, n, *_ in HELPERS)

    def get_duration(self, m):
        if not self.low_only: return super().get_duration(m)
        hr, value = self.duration[min(self.duration_index, len(self.duration)-1)]
        assert value is not None
        m.write(m.reg[5], value & 0xFFFFFFFF)
        self.events.append(dict(api='GetDuration', hr=hr, value=value, low_only=True))
        self.duration_index += 1
        self.clobber(m)
        return hr

    def poison(self, value):
        # Both owners place their duration output at the same caller-SP offset.
        self.vm.write(STACK-0x10, value & 0xFFFFFFFF)
        self.vm.write(STACK-0xC, (value >> 32) & 0xFFFFFFFF)

    def run_dispatched(self, kind, requested=90):
        # Execute the actual window cookie initialization/check. Older dispatch
        # fixtures supplied an owned-buffer value in this cookie slot.
        m, delta = self.vm, self.delta
        saved = {r: 0x12340000+r for r in (*range(16, 24), 28, 30)}
        for r, value in saved.items(): m.reg[r] = value
        m.reg[29], m.reg[31] = STACK, STOP
        m.write(STACK-0x2000, 0xA55AA55A); m.write(STACK+0x40, 0xA55AA55A)
        begin, prologue, arm = ((0x20EAC, 0x20EC0, 0x21704) if kind == 'ipc'
                                else (0x21D00, 0x21D38, 0x223D4))
        cookies = self.cookie_checks()
        m.run(begin+delta, {prologue+delta})
        request = UI+0x2F00
        m.write(request, requested); m.reg[17] = 1
        if kind == 'ipc': m.write(m.reg[29]+0x40, request)
        else: m.reg[16] = request
        m.run(arm+delta, {STOP}, limit=20000)
        assert m.reg[29] == STACK and m.reg[31] == STOP
        assert all(m.reg[r] == value for r, value in saved.items())
        assert m.read(STACK-0x2000) == m.read(STACK+0x40) == 0xA55AA55A
        assert not self.freed and self.cookie_checks()-cookies == int(kind == 'window')
        return m.reg[2]


def structure(previous, candidate, recipe):
    assert hashlib.sha256(previous).hexdigest() == BASE_SHA
    a, b = pefile.PE(data=previous), pefile.PE(data=candidate)
    assert len(previous) == len(candidate)
    assert [s.__pack__() for s in a.sections] == [s.__pack__() for s in b.sections]
    assert a.OPTIONAL_HEADER.AddressOfEntryPoint == b.OPTIONAL_HEADER.AddressOfEntryPoint
    imports = lambda p: [(d.dll, [(i.name, i.ordinal) for i in d.imports]) for d in p.DIRECTORY_ENTRY_IMPORT]
    assert imports(a) == imports(b)
    restored, touched = bytearray(candidate), set()
    for e in recipe['edits']:
        span = set(range(e['offset'], e['offset']+e['bytes']))
        assert not touched & span; touched |= span
        assert candidate[e['offset']:e['offset']+e['bytes']] == bytes.fromhex(e['after_hex'])
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    assert restored == previous
    def rows(p):
        d = p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        return [struct.unpack_from('<5I', p.get_data(d.VirtualAddress, d.Size), i) for i in range(0, d.Size, 20)]
    before, after = rows(a), rows(b)
    assert set(before) <= set(after) and len(after) == len(before)+2
    assert after == sorted(after) and all(x[1] <= y[0] for x, y in zip(after, after[1:]))
    assert set(map(tuple, recipe['added_pdata_rows'])) == set(after)-set(before)
    for row in before:
        if 0x3C000 <= row[0] < 0x40F00:
            assert a.get_data(row[0]-BASE, row[1]-row[0]) == b.get_data(row[0]-BASE, row[1]-row[0])
    for at, n, _, _, prologue in HELPERS:
        assert a.get_data(at-BASE, n) == bytes(n)
        assert not any(at < r[1] and r[0] < at+n for r in before)
        assert any(r[0] == at and r[4] == at+prologue for r in after)
        if prologue: assert b.get_data(at-BASE, prologue) == bytes.fromhex('e0ffbd271c00bfaf')
    for at, n, _ in SITES: assert a.get_data(at+n-BASE, 4) == b.get_data(at+n-BASE, 4)
    for lo, hi in ((0x1111C, 0x11138), (0x11218, 0x11230),
                   (0x1137C, 0x11398), (0x113D4, 0x113E0)):
        assert a.get_data(lo-BASE, hi-lo) == b.get_data(lo-BASE, hi-lo)
    owner = next(r for r in before if r[0] <= 0x11180 < r[1])
    assert owner[0] <= 0x111EC < owner[1]
    for delta in (0x1000, 0x10000, 0x123000):
        assert rows(pefile.PE(data=relocated(candidate, delta))) == [tuple(x+delta if x else 0 for x in r) for r in after]
    return dict(cases=1, exact_reversal=True, prior_helper_bodies_and_exception_rows_preserved=True,
                sections_imports_entry_preserved=True, original_prologues_epilogues_preserved=True,
                complete_helper_prologue=True, own_frame_fallback=True, alternate_load_bases=3)


def baseline(previous):
    traces = []
    for name, value, expected in (('duration', None, 7), ('seek', None, 1), ('seek', -UNIT, 1)):
        g = Duration(previous, duration=((0, value),)); g.poison(7*UNIT)
        assert g.run_timing(name, 42) == expected
        if name == 'seek': assert g.targets == ([68_500_000] if value is None else [0])
        traces.append(dict(name='old unwritten/negative duration consumed', owner=name, value=value,
                           result=expected, snapshot=g.snapshot()))
    return traces


def verify(previous, candidate, recipe):
    checks, traces = structure(previous, candidate, recipe), baseline(previous)
    def record(name, g, result=None, **extra):
        traces.append(dict(name=name, result=result, snapshot=g.snapshot(), **extra))
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        raw = relocated(candidate, delta) if delta else candidate
        for value in (0, 1, 9_999, 10_000, UNIT-1, UNIT, 7*UNIT, 300*UNIT+8_500_000):
            pair = []
            for content in (old, raw):
                g = Duration(content, delta=delta, duration=((0, value),)); g.poison(99*UNIT)
                pair.append((g.run_timing('duration'), g.snapshot()))
            assert pair[0] == pair[1]
            record('valid duration conversion unchanged', g, pair[1][0], value=value, base_delta=delta)
        for value, requested, hr in itertools.product((0, 1, 1_499_999, 1_500_000, 2*UNIT, 300*UNIT),
                                                      (0, 1, 42, 300, 400, 0xFFFFFFFF), (0, E_FAIL)):
            pair = []
            for content in (old, raw):
                g = Duration(content, delta=delta, duration=((0, value),), seek_hr=hr); g.poison(99*UNIT)
                pair.append((g.run_timing('seek', requested), g.snapshot()))
            assert pair[0] == pair[1]
            record('valid seek bounds/result unchanged', g, pair[1][0], value=value,
                   requested=requested, seek_hr=hr, base_delta=delta)
        for value, poison in itertools.product((None, -1, -UNIT, -(1 << 63)), (0, 7*UNIT, 300*UNIT, -1)):
            g = Duration(raw, delta=delta, duration=((0, value),)); g.poison(poison)
            assert g.run_timing('duration') == 0xFFFFFFFF and not g.divisions
            record('unavailable duration rejects stale stack and negative output', g, -1,
                   value=value, poison=poison, base_delta=delta)
            for requested in (0, 42, 0xFFFFFFFF):
                g = Duration(raw, delta=delta, duration=((0, value),)); g.poison(poison)
                assert g.run_timing('seek', requested) == 1
                assert g.targets == [(42*UNIT if requested == 42 else 0)]
                record('unknown bound retains existing nonnegative unbounded-seek fallback', g, 1,
                       value=value, poison=poison, requested=requested, base_delta=delta)
        for value, hr in itertools.product((None, 0, 7*UNIT, -UNIT), (E_FAIL, 0x80004001, 0x80070057)):
            for name in ('duration', 'seek'):
                pair = []
                for content in (old, raw):
                    g = Duration(content, delta=delta, duration=((hr, value),)); g.poison(99*UNIT)
                    pair.append((g.run_timing(name, 42), g.snapshot()))
                assert pair[0] == pair[1]
                record('failed HRESULT behavior unchanged', g, pair[1][0], owner=name,
                       value=value, hr=hr, base_delta=delta)
        for name in ('duration', 'seek'):
            g = Duration(raw, delta=delta, low_only=True); g.poison(0)
            result = g.run_timing(name, 42)
            assert result == (0xFFFFFFFF if name == 'duration' else 1)
            assert g.targets == ([] if name == 'duration' else [42*UNIT])
            record('unwritten high DWORD stays unavailable', g, result, owner=name, base_delta=delta)
            g = Duration(raw, delta=delta, interface=False)
            assert g.run_timing(name, 42) == 0xFFFFFFFF and not g.duration_index and not g.targets
            record('missing interface rejection unchanged', g, -1, owner=name, base_delta=delta)
        for value in (None, -UNIT):
            g = Duration(raw, delta=delta, duration=((0, value),)); g.poison(7*UNIT)
            g.vm.write(UI+0x2930, 1); g.run_timing('held')
            assert not g.targets and g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 37
            record('held seek rejects unavailable duration without clock changes', g,
                   value=value, base_delta=delta)
            for kind in ('ipc', 'window'):
                g = Duration(raw, delta=delta, duration=((0, value),)); g.poison(7*UNIT)
                assert g.run_dispatched(kind) == 1 and not g.targets
                assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 37
                record('dispatched seek rejects unavailable duration', g,
                       kind=kind, value=value, base_delta=delta)
    return dict(cases=checks['cases']+len(traces), structure=checks, traces=traces,
                limits='Actual MIPS duration/seek/controller paths; COM/OS supplied. No CE, codec, audio, concurrency, unwind or native performance. Sentinel cannot detect every partial output write.')


def retained(state, initialization, timing, completion, start, recovery, candidate,
             init_recipe, timing_recipe, completion_recipe, start_recipe, recovery_recipe, recipe):
    import verify_usb_playback_recovery as prior
    def cumulative(previous, written, edits):
        assert written == candidate
        a, b = prior.structure(previous, recovery, edits), structure(recovery, written, recipe)
        return dict(cases=a['cases']+b['cases'], stages=[a, b])
    namespace = dict(prior.retained.__globals__, Recovery=Duration,
                     HELPERS=prior.HELPERS+HELPERS, structure=cumulative)
    fn = FunctionType(prior.retained.__code__, namespace, 'retained_duration_stages')
    suites = fn(state, initialization, timing, completion, start, candidate,
                init_recipe, timing_recipe, completion_recipe, start_recipe, recovery_recipe)
    recovery_verify = FunctionType(prior.verify.__code__,
                                  dict(prior.verify.__globals__, Recovery=Duration, structure=cumulative),
                                  'retained_recovery_checks')
    print('Retained USB recovery', flush=True)
    suites['recovery'] = recovery_verify(start, candidate, recovery_recipe)
    return suites


def retained_graph_state(original, candidate, recipe):
    import verify_usb_playback_recovery as prior
    fn = FunctionType(prior.retained_graph_state.__code__,
                      dict(prior.retained_graph_state.__globals__, Recovery=Duration,
                           HELPERS=prior.HELPERS+HELPERS), 'retained_duration_graph_state')
    return fn(original, candidate, recipe)
