"""Actual start/controller instructions; explicit COM, catalog, file and OS fixtures.

No native CE, scheduling, decoding, audio, unwind or elapsed-time measurement.
"""
from collections import Counter
import hashlib
import itertools
import struct
from types import FunctionType

import pefile

from inspect_bt_pairing import put, data
from inspect_wave_queue import STOP
from verify_media_responsiveness import STACK, call
from verify_usb_seek_completion import Seeking
from verify_usb_seek_timing import UI, UNIT, SEEK, SEEK_TABLE, signed
from verify_usb_graph_state import OBJECT, CONTROL, AUDIO, INSTANCE, API, VTABLE, E_FAIL, INTERMEDIATE
from verify_usb_input_safety import relocated
from patch_usb_playback_start import BASE, BASE_SHA, CLEANUP, GATE, HELPERS, SITES

SLOTS = (4, 8, 0xC, 0x10, 0x14, 0x18)
LIBRARY, FOLDERS, ENTRIES = 0x52000000, 0x53000000, 0x54000000
STACK_COOKIE = 0xABCD


class Playback(Seeking):
    """Execute manager Run, real status/timers, play, remainPlay and timer 1007.

    Ordinary play uses explicit catalog/metadata/LoadFile API responses. Graph
    initialization internals are tested by the retained initialization suite.
    No actual file, decoder or filter implementation is emulated here.
    """
    def __init__(self, raw, run_hr=0, **kwargs):
        super().__init__(raw, **kwargs)
        self.run_hrs = list(run_hr) if isinstance(run_hr, tuple) else [run_hr]
        self.run_calls, self.timeline = 0, []
        self.active_timers, self.started_timers = {1000}, []
        self.supported, self.load_result, self.bt_call = True, 1, 0
        self.fail_mutation = None
        m, d = self.vm, self.delta
        for a, b in ((0x114A0, 0x11568), (0x113E8, 0x1144C), (0x1C568, 0x1C66C), (0x1AE54, 0x1AF28),
                     (0x1AF28, 0x1AFBC), (0x1A60C, 0x1A69C),
                     (0x1B17C, 0x1B1C0), (0x1AC58, 0x1ACCC),
                     (0x1ED94, 0x1EDB0), (0x1C6E0, 0x1CD94),
                     (0x1CD94, 0x1CF38), (0x20340, 0x205D0), (0x25510, 0x25558)):
            m.ranges.append((a+d, b+d))
        m.ranges.extend((a+d, a+n+d) for a, n, *_ in HELPERS)
        del m.hooks[0x1AE54+d]
        # Execute the real cookie comparison instead of the inherited fixture
        # which called this address a free. Valid CE cookies have zero high16.
        del m.hooks[0x25510+d]
        m.native_markers[0x25510+d] = 'native_stack_cookie_check'
        m.write(0x2F960+d, STACK_COOKIE)
        m.hooks[0x25B1C+d] = self.cookie_failure
        m.hooks.update({at+d: fn for at, fn in (
            (0x251EC, self.set_timer), (0x237B4, self.fade),
            (0x13350, self.path), (0x13334, self.kind), (0x1B760, self.metadata_supported),
            (0x1A7D0, self.save_index), (0x19C94, self.select), (0x12604, self.registry),
            (0x14DB0, self.library), (0x132FC, self.folder), (0x146EC, self.library_index),
            (0x12EBC, self.count))})
        m.write(VTABLE+0x1C, API+0x700); m.hooks[API+0x700] = self.com_run
        m.write(SEEK_TABLE+8, API+8)
        self.owned = Counter(m.read(OBJECT+off) for off in SLOTS if m.read(OBJECT+off))
        m.write(OBJECT+0x24, 0)
        m.write(INSTANCE+0x30, 1); m.write(INSTANCE+0x48, LIBRARY)
        put(m, LIBRARY, bytes(0x40)); put(m, FOLDERS, bytes(0x40)); put(m, ENTRIES, bytes(0x220))
        m.write(FOLDERS+0x38, ENTRIES)
        m.write(ENTRIES+0x212, 2, 2); m.write(ENTRIES+0x214, 0, 2)
        m.write(UI+0x1AD4, 0)
        self.library_count = 2

    def com_run(self, m):
        assert m.reg[4] == CONTROL
        result = self.run_hrs[min(self.run_calls, len(self.run_hrs)-1)]
        self.run_calls += 1
        self.timeline.append(dict(api='Run', hr=result))
        if self.fail_mutation == 'control_after_run': m.write(OBJECT+4, 0)
        self.clobber(m); return result

    @staticmethod
    def cookie_failure(m): raise AssertionError('Native stack cookie rejected')

    def cookie_checks(self):
        return sum(e['api'] == 'native_stack_cookie_check' for e in self.events)

    def mute(self, m):
        assert m.reg[4] == AUDIO and signed(m.reg[5]) in (0, -10000)
        self.events.append(dict(api='Volume', value=signed(m.reg[5])))
        if self.mutate == 'after_mute' and signed(m.reg[5]) == -10000: m.write(OBJECT+4, 0)
        self.clobber(m); return self.mute_hr

    def release(self, m):
        pointer = m.reg[4]
        assert self.owned[pointer] > 0, 'Release without owned reference'
        self.owned[pointer] -= 1; self.released.append(pointer)
        self.timeline.append(dict(api='Release', pointer=pointer))
        self.clobber(m); return self.owned[pointer]

    def publish(self, m):
        assert m.reg[4:8] == [0x9900, UI+0x1AD8, 0, 0xE56]
        self.published.append(data(m, m.reg[5], m.reg[7]).hex())
        self.timeline.append(dict(api='Publish', state=m.read(UI+0x2922),
                                  position=m.read(UI+0xE7C), display=m.read(UI+0x2940)))
        self.clobber(m); return 1

    def notify(self, m):
        args = m.reg[4:8].copy(); self.notifications.append(args)
        ptr = m.read(m.reg[29]+0x10)
        self.timeline.append(dict(api='Notify', args=args, payload=m.read(ptr) if args[3] == 4 else None))
        self.clobber(m); return 1

    def kill_timer(self, m):
        assert m.reg[4] == 0x6666
        timer = m.reg[5]; self.timer_ids.append(timer); self.active_timers.discard(timer)
        self.timeline.append(dict(api='KillTimer', timer=timer))
        self.clobber(m); return 1

    def set_timer(self, m):
        assert m.reg[4:8] == [0x6666, 1000, 500, 0]
        self.started_timers.append(1000); self.active_timers.add(1000)
        self.timeline.append(dict(api='SetTimer', timer=1000))
        self.clobber(m); return 1000

    def fade(self, m):
        assert m.reg[4:8] == [5, 3, 0x8B, 4] and m.read(m.read(m.reg[29]+0x10)) == 0
        self.timeline.append(dict(api='FadeRequest'))
        self.clobber(m); return 1

    def path(self, m):
        assert m.reg[4] == LIBRARY
        put(m, m.reg[6], '\\MD\\Music\\Track.mp3\0'.encode('utf-16le'))
        self.clobber(m); return 1

    def kind(self, m):
        assert m.reg[4] == LIBRARY
        self.clobber(m); return 1

    def metadata_supported(self, m):
        assert m.reg[4] == UI
        self.clobber(m); return int(self.supported)

    def load(self, m):
        assert m.reg[4] == OBJECT and m.text(m.reg[5]) == '\\MD\\Music\\Track.mp3' and m.reg[6] == 1
        self.load_calls.append(self.load_result)
        if self.load_result == 1:
            # Explicit response: retained initialization tests cover construction.
            m.write(OBJECT+0x24, 0); m.write(0x2F96C+self.delta, 1); m.write(INSTANCE+0x28, 1)
            if not m.read(OBJECT+4):
                for off, ptr in zip(SLOTS, (CONTROL, CONTROL+0x100, SEEK, CONTROL+0x140, AUDIO, CONTROL+0x160)):
                    m.write(OBJECT+off, ptr); self.owned[ptr] += 1
        self.clobber(m); return self.load_result

    def save_index(self, m):
        assert m.reg[4] == UI
        self.clobber(m); return 1

    def select(self, m):
        assert m.reg[4] == UI
        m.write(UI+0x2916, m.reg[5]); self.clobber(m); return 1

    def registry(self, m):
        name = m.text(m.reg[6])
        assert name in ('CallState', 'Inserted'), name
        self.clobber(m); return self.bt_call if name == 'CallState' else 1

    def library(self, m): self.clobber(m); return FOLDERS
    def folder(self, m):
        assert m.reg[4] == FOLDERS
        self.clobber(m); return 0
    def library_index(self, m):
        assert m.reg[4] == FOLDERS
        self.clobber(m); return 0
    def count(self, m):
        assert m.reg[4] == LIBRARY
        self.clobber(m); return self.library_count

    def invoke(self, name, virtual_pause=0, error_processing=1):
        if name == 'run': return call(self.vm, 0x114A0+self.delta, [OBJECT], limit=200000)
        if name == 'timer': return call(self.vm, 0x20340+self.delta, [UI-8, 1007], limit=200000)
        # Ordinary play and the reload fallback own a 0x1098-byte frame.
        m = self.vm
        saved = {r: 0x12340000+r for r in (*range(16, 24), 28, 30)}
        for r, value in saved.items(): m.reg[r] = value
        m.reg[4:8] = [UI, 0, 1, virtual_pause]
        m.reg[29], m.reg[31] = STACK, STOP
        m.write(STACK+0x10, error_processing)
        m.write(STACK-0x4000, 0xA55AA55A); m.write(STACK+0x40, 0xA55AA55A)
        m.run((0x1C6E0 if name == 'play' else 0x1CD94)+self.delta, {STOP}, limit=300000)
        assert m.reg[29] == STACK and m.reg[31] == STOP
        assert all(m.reg[r] == value for r, value in saved.items()), 'Caller registers changed'
        assert m.read(STACK-0x4000) == m.read(STACK+0x40) == 0xA55AA55A
        assert self.cookie_checks() == int(name == 'play' or bool(self.load_calls))
        return m.reg[2]

    def snapshot(self):
        result = super().snapshot()
        del result['cookie_frees']
        return dict(result, cookie_checks=self.cookie_checks(), run_calls=self.run_calls,
                    readiness=self.vm.read(0x2F96C+self.delta),
                    graph_flag=self.vm.read(INSTANCE+0x28), cached_state=self.vm.read(OBJECT+0x24),
                    play_state=self.vm.read(UI+0x2922), active=self.vm.read(UI+0x1AD4),
                    slots=[self.vm.read(OBJECT+off) for off in SLOTS],
                    outstanding_references=sum(self.owned.values()), released=len(self.released),
                    active_timers=sorted(self.active_timers), started_timers=self.started_timers.copy(),
                    timeline=self.timeline.copy(), transition=self.summary())


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
    for at, n, *_ in HELPERS:
        assert a.get_data(at-BASE, n) == bytes(n)
        assert not any(at < r[1] and r[0] < at+n for r in before)
        assert any(r[0] == at and r[4] == at+(12 if at == CLEANUP else 0) for r in after)
    assert struct.unpack('<3I', b.get_data(CLEANUP-BASE, 12)) == (0x27BDFFE0, 0xAFBF001C, 0xAFB00018)
    for source, targets in ((0x11540, (0x114C4,)), (0x1C918, (0x1C9FC, 0x1CA98))):
        owner = next(r for r in before if r[0] <= source < r[1])
        assert all(owner[0] <= t < owner[1] for t in targets)
    for at, n, _ in SITES: assert a.get_data(at+n-BASE, 4) == b.get_data(at+n-BASE, 4)
    for delta in (0x1000, 0x10000, 0x123000):
        assert rows(pefile.PE(data=relocated(candidate, delta))) == [tuple(x+delta if x else 0 for x in r) for r in after]
    return dict(cases=1, exact_reversal=True, prior_helper_bodies_and_exception_rows_preserved=True,
                sections_imports_entry_preserved=True, own_frame_exits=True,
                framed_cleanup_and_leaf_gate=True, three_alternate_load_bases=True)


def verify(previous, candidate, recipe):
    checks, traces = structure(previous, candidate, recipe), []
    def record(name, g, result, **extra): traces.append(dict(name=name, result=result, **g.snapshot(), **extra))
    g = Playback(previous, run_hr=E_FAIL)
    assert g.invoke('run') == 0 and g.run_calls == 1 and not g.released
    assert g.vm.read(0x2F96C) == 1 and g.active_timers == {1000}
    record('previous failed COM start leaves readiness and progress polling', g, 0)
    g = Playback(previous, run_hr=E_FAIL)
    assert g.invoke('play') == 1 and g.vm.read(UI+0x1AD4) == 1 and g.active_timers == {1000}
    record('previous ordinary play ignores failed start', g, 1)
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        raw = relocated(candidate, delta) if delta else candidate
        for name, hr in itertools.product(('run', 'play', 'timer', 'resume'), (0, 1, 0x40237)):
            pairs = []
            for content in (old, raw):
                g = Playback(content, delta=delta, run_hr=hr)
                pairs.append((g.invoke(name), g.snapshot()))
            assert pairs[0] == pairs[1], (name, hr, delta, pairs)
            record('healthy and nonnegative starts unchanged', g, pairs[1][0], caller=name, hr=hr, base_delta=delta)
        for hr, samples in itertools.product((E_FAIL, 0x80070005, 0xFFFFFFFF),
                                             (((0, 0),), ((0, 2), (0, 1), (0, 0)))):
            g = Playback(raw, delta=delta, run_hr=hr, samples=samples)
            assert g.invoke('run') == 0 and g.run_calls == 1 and len(g.released) == 6
            assert sum(g.owned.values()) == 0 and not any(g.vm.read(OBJECT+off) for off in SLOTS)
            assert g.vm.read(0x2F96C+delta) == g.vm.read(INSTANCE+0x28) == 0
            assert g.vm.read(UI+0x2922) == 3 and g.active_timers == set()
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 37
            publish = next(i for i, e in enumerate(g.timeline) if e['api'] == 'Publish')
            assert all(i < publish for i, e in enumerate(g.timeline) if e['api'] == 'Release')
            record('failed start releases only confirmed stopped graph', g, 0, hr=hr, base_delta=delta)
        failures = {'error': ((E_FAIL, 0),), 'missing_output': ((0, None),),
                    'invalid_state': ((0, 3),), 'pending': ((INTERMEDIATE, 0),),
                    'unchanged_running': ((0, 2),), 'unknown_success': ((1, 0),),
                    'command_error': ((0, 2),), 'during_get': ((0, 2),),
                    'control_after_run': ((0, 0),)}
        for failure, samples in failures.items():
            g = Playback(raw, delta=delta, run_hr=E_FAIL, samples=samples)
            if failure == 'command_error': g.action_hr = E_FAIL
            if failure == 'during_get': g.mutate = failure
            if failure == 'control_after_run': g.fail_mutation = failure
            assert g.invoke('run') == 0 and not g.released and sum(g.owned.values()) == 6
            assert g.vm.read(0x2F96C+delta) == 0 and g.vm.read(INSTANCE+0x28) == 1
            assert g.vm.read(UI+0x2922) == 2 and not g.published and not g.notifications
            assert not g.active_timers and g.index <= 1001
            record('unconfirmed cleanup retains references and avoids stopped publication', g, 0,
                   failure=failure, base_delta=delta)
        for name, samples in itertools.product(('play', 'timer'), (((0, 0),), ((E_FAIL, 0),))):
            g = Playback(raw, delta=delta, run_hr=E_FAIL, samples=samples)
            # Ordinary Stop uses the same responses. A failed initial Stop is an
            # existing separate limitation; these traces still execute the caller.
            result = g.invoke(name)
            if name == 'play': assert result == 0
            assert g.run_calls == 1 and not g.active_timers
            if name == 'play':
                assert g.vm.read(UI+0x1AD4) == 0 and g.cookie_checks() == 1
                assert any(n[2] == 0x71 for n in g.notifications) and any(n[2] == 0x6E for n in g.notifications)
                assert g.vm.read(UI+0x2922) == 1  # Existing pending-error/skip policy.
            record('actual caller failure follows existing error policy', g, g.vm.reg[2], caller=name, base_delta=delta)
        for field in ('window', 'ui', 'mapping', 'audio'):
            g = Playback(raw, delta=delta, run_hr=E_FAIL)
            if field == 'audio':
                pointer = g.vm.read(OBJECT+0x14); g.owned[pointer] -= 1; g.vm.write(OBJECT+0x14, 0)
            else: g.vm.write(INSTANCE+{'window': 0x3C, 'ui': 0x4C, 'mapping': 0x40}[field], 0)
            assert g.invoke('run') == 0 and sum(g.owned.values()) == 0
            assert len(g.released) == (5 if field == 'audio' else 6)
            assert bool(g.active_timers) == (field == 'window')
            assert bool(g.published) == (field not in ('ui', 'mapping'))
            record('optional missing handle/interface does not invent ownership', g, 0, missing=field, base_delta=delta)
        for ready, cached, control in itertools.product((0, 1), (0, 1, 2, 3), (0, 1)):
            pairs = []
            for content in (old, raw):
                g = Playback(content, delta=delta)
                g.vm.write(0x2F96C+delta, ready); g.vm.write(OBJECT+0x24, cached)
                if not control:
                    g.owned[CONTROL] -= 1; g.vm.write(OBJECT+4, 0)
                pairs.append((g.invoke('run'), g.snapshot()))
            assert pairs[0] == pairs[1]
            record('existing cached/missing-control decisions unchanged', g, pairs[1][0], base_delta=delta)
        # Actual reload fallback must keep the saved timestamp before reloading.
        g = Playback(raw, delta=delta, run_hr=(E_FAIL, 0))
        g.invoke('resume')
        assert g.run_calls == 2 and g.load_calls == [1] and g.active_timers == {1000}
        assert g.targets[-1] == 37*UNIT and g.vm.read(0x2F96C+delta) == 1
        record('failed remainPlay reloads and restores saved timestamp', g, g.vm.reg[2], base_delta=delta)
        for failure in ('pause_error', 'stop_error', 'clock_wrap', 'poll_cap'):
            samples = ((0, 1),) if failure == 'stop_error' else ((0, 2), (0, 1), (0, 0))
            g = Playback(raw, delta=delta, run_hr=E_FAIL, samples=samples)
            if failure in ('pause_error', 'stop_error'): g.action_hr = E_FAIL
            if failure == 'clock_wrap': g.clock = 0xFFFFFFFD
            if failure == 'poll_cap': g.samples = [(INTERMEDIATE, 0)]; g.sleep_ms = 0
            assert g.invoke('run') == 0
            assert bool(g.released) == (failure == 'clock_wrap') and not g.active_timers
            if failure == 'poll_cap': assert g.index == 1001
            record('bounded cleanup command/clock boundaries', g, 0, failure=failure, base_delta=delta)
        g = Playback(raw, delta=delta, run_hr=E_FAIL)
        old_pointer = g.vm.read(OBJECT+0x18); g.owned[old_pointer] -= 1
        g.vm.write(OBJECT+0x18, SEEK); g.owned[SEEK] += 1
        assert g.invoke('run') == 0 and g.released.count(SEEK) == 2 and sum(g.owned.values()) == 0
        record('two separately owned aliases released exactly twice', g, 0, base_delta=delta)
        g = Playback(raw, delta=delta, run_hr=E_FAIL)
        assert g.invoke('play', error_processing=0) == 0
        assert any(n[2] == 0x76 for n in g.notifications) and not any(n[2] in (0x71, 0x73) for n in g.notifications)
        assert not g.active_timers
        record('non-auto-skip owner reports existing error notification', g, 0, base_delta=delta)
        for failure in ('unsupported', 'load_error', 'removed', 'call_blocked', 'timer_blocked'):
            pairs = []
            for content in (old, raw):
                g = Playback(content, delta=delta)
                if failure == 'unsupported': g.supported = False
                if failure == 'load_error': g.load_result = 3
                if failure == 'removed': g.vm.write(INSTANCE+0x30, 0)
                if failure == 'call_blocked': g.bt_call = 1; g.vm.write(UI+0x1AD0, 2)
                if failure == 'timer_blocked': g.vm.write(UI+0x1AD0, 1)
                name = 'timer' if failure == 'timer_blocked' else 'play'
                pairs.append((g.invoke(name), g.snapshot()))
            assert pairs[0] == pairs[1] and not g.run_calls
            record('pre-start rejections and blocked playback unchanged', g, pairs[1][0], failure=failure, base_delta=delta)
    return dict(cases=len(traces)+checks['cases'], structure=checks, traces=traces,
                limits='Actual MIPS with explicit COM/catalog/LoadFile/OS responses; no native CE, codec, audio, concurrency, unwind or performance validation. Existing pending-error UI policy and pre-start Stop handling remain.')


def retained(state, initialization, timing, completion, candidate, init_recipe,
             timing_recipe, completion_recipe, recipe):
    """Isolated existing behavior suites with explicit cumulative structure checks."""
    import verify_usb_graph_init as init_prior
    import verify_usb_seek_timing as timing_prior
    import verify_usb_seek_completion as completion_prior
    steps = [(state, initialization, init_recipe, init_prior.structure),
             (initialization, timing, timing_recipe, timing_prior.structure),
             (timing, completion, completion_recipe, completion_prior.structure),
             (completion, candidate, recipe, structure)]
    def cumulative(start):
        def check(previous, written, _recipe):
            assert previous == steps[start][0] and written == candidate
            checks = [fn(before, after, edits) for before, after, edits, fn in steps[start:]]
            return dict(cases=sum(c['cases'] for c in checks), stages=checks)
        return check
    class RetainedSeeking(Seeking):
        def __init__(self, *args, **kwargs): super().__init__(*args, follow_position=False, **kwargs)
        def snapshot(self):
            result = timing_prior.Timing.snapshot(self)
            result['progress_writes'] = [w['value'] for w in self.vm.progress_writes]
            return result
    suites = {}
    for name, module, start, before, edits, replacements in (
        ('completion', completion_prior, 2, timing, completion_recipe, {}),
        ('timing', timing_prior, 1, initialization, timing_recipe, {'Timing': RetainedSeeking}),
        ('initialization', init_prior, 0, state, init_recipe, {})):
        namespace = dict(module.verify.__globals__, structure=cumulative(start), **replacements)
        fn = FunctionType(module.verify.__code__, namespace, 'verify_retained_'+name)
        print('Retained USB '+name, flush=True)
        suites[name] = fn(before, candidate, edits)
    return suites
