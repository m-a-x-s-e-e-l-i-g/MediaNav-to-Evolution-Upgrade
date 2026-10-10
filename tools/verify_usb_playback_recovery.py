"""Connected playback/loader instruction fixtures; COM, catalog and OS are supplied.

No Windows CE, codec, audio, concurrent scheduling or native timing execution.
"""
from collections import Counter
import hashlib
import itertools
import struct
from types import FunctionType

import pefile

from inspect_bt_pairing import put
from inspect_wave_queue import STOP
from verify_media_responsiveness import STACK, call
from verify_usb_playback_start import Playback, SLOTS
from verify_usb_graph_init import Initialization
from verify_usb_graph_state import OBJECT, CONTROL, AUDIO, INSTANCE, VTABLE, API, E_FAIL, INTERMEDIATE
from verify_usb_seek_timing import TimingVM, SEEK, UI, UNIT
from verify_usb_input_safety import relocated
from patch_usb_playback_recovery import BASE, BASE_SHA, HELPERS, SITES, STOP_STATUS, INITIAL_SEEK, RELOAD_GATE, RELOAD_SEEK, POSITION_INIT, POSITION_RESULT


class RecoveryVM(TimingVM):
    def word(self, pc):
        if pc == getattr(self, 'load_entry', None): self.load_observer.append('native')
        return super().word(pc)


class Recovery(Playback):
    """Actual Stop, resume, ordinary play, LoadFile, teardown and construction.

    Metadata/catalog, COM creation/render/query methods and OS calls remain
    explicit fixtures. A successful RenderFile response seeds new position zero.
    The optional old LoadFile fixture is retained only for the previous suite.
    """
    def __init__(self, raw, native_load=True, **kwargs):
        seek_hr = kwargs.pop('seek_hr', 0)
        self.missing_position_output = kwargs.pop('missing_position_output', False)
        self.seek_results = list(seek_hr) if isinstance(seek_hr, tuple) else [seek_hr]
        super().__init__(raw, seek_hr=self.seek_results[0], **kwargs)
        self.vm.ranges.extend((a+self.delta, a+n+self.delta) for a, n, *_ in HELPERS)
        self.vm.native_markers[0x1111C+self.delta] = 'native_manager_seek'
        self.vm.native_markers[0x1C6E0+self.delta] = 'native_play_entry'
        self.status_proofs, self.metadata_calls = [], 0
        self.native_load, self.inserted = native_load, 1
        self.position_after_reload = None
        if not native_load: return
        previous = self.vm
        self.vm = RecoveryVM(previous.pe, previous.ranges)
        self.vm.__dict__.update(previous.__dict__)
        m, d = self.vm, self.delta
        m.load_entry, m.load_observer = 0x12264+d, self.load_calls
        for a, b in ((0x11054, 0x1111C), (0x11F78, 0x12264), (0x12264, 0x12444)):
            m.ranges.append((a+d, b+d))
        del m.hooks[0x11054+d]; del m.hooks[0x12264+d]
        self.fail, self.hr, self.creator_output, self.query_success = None, E_FAIL, True, 0
        self.refs = self.owned
        self.pointers = {off: m.read(OBJECT+off) for off in SLOTS}
        self.acquisitions, self.creations, self.notify_windows = [], 0, 0
        self.lock_depth, self.locks = 0, []
        self.render_calls, self.path_checks = 0, 0
        put(m, VTABLE+0x100, bytes(0x80))
        m.write(self.pointers[0x10], VTABLE+0x100)
        m.write(VTABLE+0x100+8, API+8)
        m.write(VTABLE+0x100, API+0x800); m.hooks[API+0x800] = self.query
        m.write(VTABLE+0x100+0x34, API+0x804); m.hooks[API+0x804] = self.render_file
        m.write(VTABLE+0x34, API+0x808); m.hooks[API+0x808] = self.notify_window
        m.write(OBJECT+0x1C, 0x7777)
        m.write(0x2F1E0+d, API+0x80C); m.hooks[API+0x80C] = self.create
        m.hooks.update({0x209E0+d: self.lock, 0x209D0+d: self.unlock, 0x24B90+d: self.valid_path})

    def publish(self, m):
        self.status_proofs.append(dict(state=m.read(UI+0x2922), queries=self.index,
                                       cached=m.read(OBJECT+0x24), references=sum(self.owned.values())))
        return super().publish(m)

    def metadata_supported(self, m):
        self.metadata_calls += 1
        return super().metadata_supported(m)

    def set_position(self, m):
        self.seek_hr = self.seek_results[min(len(self.targets), len(self.seek_results)-1)]
        return super().set_position(m)

    def get_position(self, m):
        if not self.missing_position_output: return super().get_position(m)
        result = self.output(m, ((0, None),), 0, 'GetCurrentPosition')
        self.position_index += 1
        return result

    def com_run(self, m):
        result = super().com_run(m)
        if not result & 0x80000000 and getattr(self, 'creations', 0) and self.position_after_reload is not None:
            self.current = self.position_after_reload
        return result

    def registry(self, m):
        name = m.text(m.reg[6])
        assert name in ('CallState', 'Inserted'), name
        result = self.bt_call if name == 'CallState' else self.inserted
        self.clobber(m); return result

    def acquire(self, m, off): return Initialization.acquire(self, m, off)
    def create(self, m): return Initialization.create(self, m)
    def query(self, m): return Initialization.query(self, m)
    def lock(self, m): return Initialization.lock(self, m)
    def unlock(self, m): return Initialization.unlock(self, m)

    def render_file(self, m):
        assert m.reg[4] == self.pointers[0x10] and m.reg[6] == 0
        assert m.text(m.reg[5]) == '\\MD\\Music\\Track.mp3'
        self.render_calls += 1
        self.events.append(dict(api='RenderFile'))
        result = self.hr if self.fail == 'render' else 0
        if result >= 0 and not result & 0x80000000: self.current = 0
        self.clobber(m); return result

    def notify_window(self, m):
        assert m.reg[4:8] == [self.pointers[8], 0x7777, 0x8001, 0]
        self.notify_windows += 1; self.events.append(dict(api='SetNotifyWindow'))
        self.clobber(m); return self.hr if self.fail == 'notify' else 0

    def valid_path(self, m):
        assert m.text(m.reg[5]) == '\\MD\\Music\\Track.mp3'
        self.path_checks += 1; self.clobber(m); return 1

    def invoke(self, name, virtual_pause=0, error_processing=1, resume_notify=0, resume_update=1):
        if name == 'stop': return call(self.vm, 0x1AF28+self.delta, [UI], limit=300000)
        if name in ('run', 'timer'): return super().invoke(name)
        m = self.vm
        saved = {r: 0x12340000+r for r in (*range(16, 24), 28, 30)}
        for r, value in saved.items(): m.reg[r] = value
        m.reg[4:8] = [UI, 0, 1, virtual_pause] if name == 'play' else [UI, resume_notify, resume_update, 0]
        m.reg[29], m.reg[31] = STACK, STOP
        m.write(STACK+0x10, error_processing)
        m.write(STACK-0x4000, 0xA55AA55A); m.write(STACK+0x40, 0xA55AA55A)
        cookies = self.cookie_checks()
        plays = sum(e['api'] == 'native_play_entry' for e in self.events)
        m.run((0x1C6E0 if name == 'play' else 0x1CD94)+self.delta, {STOP}, limit=400000)
        assert m.reg[29] == STACK and m.reg[31] == STOP
        assert all(m.reg[r] == value for r, value in saved.items()), 'Caller registers changed'
        assert m.read(STACK-0x4000) == m.read(STACK+0x40) == 0xA55AA55A
        # Every actual play entry checks its cookie, even without loading.
        assert self.cookie_checks()-cookies == sum(e['api'] == 'native_play_entry' for e in self.events)-plays
        if self.native_load: assert self.lock_depth == 0
        return m.reg[2]

    def snapshot(self):
        result = dict(super().snapshot(), position=self.current, status_proofs=self.status_proofs.copy(),
                      metadata_calls=self.metadata_calls,
                      seek_attempts=[e['value'] for e in self.events if e['api'] == 'native_manager_seek'])
        if self.native_load:
            result.update(creations=self.creations, acquisitions=len(self.acquisitions),
                          render_calls=self.render_calls, notify_windows=self.notify_windows,
                          locks=self.locks.copy(), path_checks=self.path_checks)
        return result


def baseline(previous):
    traces = []
    g = Recovery(previous, samples=((E_FAIL, 2),))
    g.vm.write(UI+0x2922, 1); g.vm.write(OBJECT+0x24, 2)
    assert g.invoke('stop') == 0 and g.vm.read(UI+0x2922) == 3 and g.vm.read(OBJECT+0x24) == 2
    assert sum(g.owned.values()) == 6
    traces.append(dict(name='failed Stop publishes stopped before confirmation', **g.snapshot()))
    g = Recovery(previous, seek_hr=E_FAIL)
    g.invoke('resume')
    assert g.current == 42*UNIT and g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 37
    traces.append(dict(name='failed resume seek leaves stale requested progress', **g.snapshot()))
    for samples, expected in ((((E_FAIL, 2), (0, 0)), 1), (((E_FAIL, 2),), 0)):
        g = Recovery(previous, samples=samples)
        assert g.invoke('play') == expected
        assert g.metadata_calls == 1 and g.load_calls == ['native']
        assert g.creations == expected and bool(g.released) == bool(expected)
        assert sum(g.owned.values()) == 6
        traces.append(dict(name='actual loader recovers or refuses after initial failed Stop', result=expected, **g.snapshot()))
    for config in ({'position': ((0, None),)}, {'position': ((0, -UNIT),)}, {'duration': ((0, None),)}):
        g = Recovery(previous, **config)
        assert g.run_timing('position') == 0
        traces.append(dict(name='previous getter treats unavailable or negative output as zero', config=config, **g.snapshot()))
    g = Recovery(previous, run_hr=E_FAIL); g.fail = 'render'
    g.invoke('resume')
    assert [e['value'] for e in g.events if e['api'] == 'native_manager_seek'].count(37) == 2
    traces.append(dict(name='previous failed native reload still calls resume seek', **g.snapshot()))
    return traces


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
    assert set(before) <= set(after) and len(after) == len(before)+6
    assert after == sorted(after) and all(x[1] <= y[0] for x, y in zip(after, after[1:]))
    assert set(map(tuple, recipe['added_pdata_rows'])) == set(after)-set(before)
    for row in before:
        if 0x3C000 <= row[0] < 0x40F00:
            assert a.get_data(row[0]-BASE, row[1]-row[0]) == b.get_data(row[0]-BASE, row[1]-row[0])
    for at, n, _, _, prologue in HELPERS:
        assert a.get_data(at-BASE, n) == bytes(n)
        assert not any(at < r[1] and r[0] < at+n for r in before)
        assert any(r[0] == at and r[4] == at+prologue for r in after)
        if prologue:
            words = struct.unpack('<'+'I'*(prologue//4), b.get_data(at-BASE, prologue))
            assert words[:2] == (0x27BDFFE0, 0xAFBF001C)
            if prologue == 12: assert words[2] == 0xAFB00018
    for source, target in ((0x1AF9C, 0x1AFA4), (0x1CED8, 0x1CEEC), (0x11284, 0x11258)):
        owner = next(r for r in before if r[0] <= source < r[1])
        assert owner[0] <= target < owner[1]
    for at, n, _ in SITES: assert a.get_data(at+n-BASE, 4) == b.get_data(at+n-BASE, 4)
    for lo, hi in ((0x1AF28, 0x1AF38), (0x1AFA4, 0x1AFBC),
                   (0x1CD94, 0x1CDB0), (0x1CF18, 0x1CF38),
                   (0x11230, 0x11248), (0x1135C, 0x1137C)):
        assert a.get_data(lo-BASE, hi-lo) == b.get_data(lo-BASE, hi-lo)
    # Original resume has no +14 stack access. Its +18 saved-register slot and
    # +10 outgoing fifth argument stay separate from the new saved request.
    for (word,) in struct.iter_unpack('<I', a.get_data(0x1CD94-BASE, 0x1CF38-0x1CD94)):
        if (word >> 21)&31 == 29 and word & 0xFFFF == 0x14:
            assert word >> 26 not in (0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B, 0x2E)
    for delta in (0x1000, 0x10000, 0x123000):
        assert rows(pefile.PE(data=relocated(candidate, delta))) == [tuple(x+delta if x else 0 for x in r) for r in after]
    return dict(cases=1, exact_reversal=True, prior_helper_bodies_and_exception_rows_preserved=True,
                sections_imports_entry_preserved=True, original_prologues_epilogues_preserved=True,
                own_frame_exits=True, previously_unused_request_slot=True, complete_helper_prologues=True,
                three_alternate_load_bases=True)


def functional_snapshot(g):
    result = g.snapshot()
    # Publication must move after verified Stop; test that ordering separately.
    del result['status_proofs']
    return result


def verify(previous, candidate, recipe):
    checks, traces = structure(previous, candidate, recipe), baseline(previous)
    def record(name, g, result=None, **extra): traces.append(dict(name=name, result=result, **g.snapshot(), **extra))
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        raw = relocated(candidate, delta) if delta else candidate
        for name, hr in itertools.product(('stop', 'play', 'resume', 'timer'), (0, 1)):
            pair = []
            for content in (old, raw):
                g = Recovery(content, delta=delta, run_hr=hr)
                pair.append((g.invoke(name), functional_snapshot(g)))
            assert pair[0] == pair[1], (name, hr, delta, pair)
            record('healthy connected controller/loader behavior retained', g, pair[1][0], caller=name, base_delta=delta)
        for state, samples in itertools.product((0, 1, 2, 3),
                   (((0, 0),), ((0, 2), (0, 1), (0, 0)), ((INTERMEDIATE, 0), (0, 0)))):
            g = Recovery(raw, delta=delta, samples=samples)
            g.vm.write(UI+0x2922, state); g.vm.write(OBJECT+0x24, 2)
            assert g.invoke('stop') == 1 and g.vm.read(UI+0x2922) == g.vm.read(OBJECT+0x24) == 3
            assert g.status_proofs == [dict(state=3, queries=len(samples), cached=3, references=6)]
            assert not g.active_timers and sum(g.owned.values()) == 6 and not g.released
            record('stopped publication follows confirmed manager completion', g, 1, previous_state=state, base_delta=delta)
        failures = {'error': ((E_FAIL, 0),), 'pending': ((INTERMEDIATE, 0),),
                    'missing_output': ((0, None),), 'invalid_state': ((0, 3),),
                    'pause_error': ((0, 2),), 'stop_error': ((0, 1),),
                    'unchanged_running': ((0, 2),), 'lost_control': ((0, 2),)}
        for state, (failure, samples) in itertools.product((1, 2), failures.items()):
            g = Recovery(raw, delta=delta, samples=samples)
            g.vm.write(UI+0x2922, state); g.vm.write(OBJECT+0x24, 2)
            if failure in ('pause_error', 'stop_error'): g.action_hr = E_FAIL
            if failure == 'lost_control': g.mutate = 'during_get'
            assert g.invoke('stop') == 0 and g.vm.read(UI+0x2922) == state
            assert g.vm.read(OBJECT+0x24) == 2 and not g.published and not g.vm.progress_writes
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 37
            assert not g.active_timers and sum(g.owned.values()) == 6 and not g.released and g.index <= 1001
            record('failed Stop preserves last status and display without releasing', g, 0,
                   previous_state=state, failure=failure, base_delta=delta)
        for actual, hr, notify, update in itertools.product((0, 1, 42), (E_FAIL, 0x80004001), (0, 1), (0, 1)):
            g = Recovery(raw, delta=delta, seek_hr=hr, position=((0, actual*UNIT),))
            g.invoke('resume', resume_notify=notify, resume_update=update)
            assert g.run_calls == 1 and not g.load_calls and g.active_timers == {1000}
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == actual
            assert g.vm.read(STACK-0x30+0x14) == 37
            assert [e['value'] for e in g.events if e['api'] == 'native_manager_seek'] == [37]
            assert g.targets == [37*UNIT] and g.position_index == 1
            record('failed resume seek refreshes checked current progress without reloading', g,
                   actual_seconds=actual, hr=hr, notify=notify, update=update, base_delta=delta)
        for failure in ('position_error', 'position_missing', 'negative_position', 'duration_error', 'missing_seeker'):
            kwargs = {'position': ((E_FAIL, None),)} if failure == 'position_error' else (
                     {'position': ((0, None),)} if failure == 'position_missing' else (
                     {'position': ((0, -UNIT),)} if failure == 'negative_position' else (
                     {'duration': ((E_FAIL, None),)} if failure == 'duration_error' else {})))
            g = Recovery(raw, delta=delta, seek_hr=E_FAIL, **kwargs)
            if failure == 'missing_seeker': g.owned[SEEK] -= 1; g.vm.write(OBJECT+0xC, 0)
            g.invoke('resume')
            assert g.run_calls == 1 and not g.vm.progress_writes
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 37
            record('unconfirmed resume progress preserves previous values', g, failure=failure, base_delta=delta)
        for position, expected in ((0, 0), (1, 0), (8_499_999, 0), (8_500_000, 1),
                                   (42*UNIT, 42), (300*UNIT, 300), (400*UNIT, 300)):
            pair = []
            for content in (old, raw):
                g = Recovery(content, delta=delta, position=((0, position),))
                pair.append((g.run_timing('position'), functional_snapshot(g)))
            assert pair[0] == pair[1] and pair[1][0] == expected
            record('valid position zero/rounding/clamp unchanged', g, expected, queried_position=position, base_delta=delta)
        for config in ({'position': ((0, None),)}, {'position': ((1, None),)},
                       {'position': ((0, -1),)}, {'position': ((0, -(1 << 63)),)},
                       {'duration': ((0, None),)}, {'duration': ((1, None),)}):
            g = Recovery(raw, delta=delta, **config)
            assert g.run_timing('position') == 0xFFFFFFFF and g.divisions == 0
            record('unwritten/negative query output rejected before conversion', g, -1, config=config, base_delta=delta)
        for seek_hr in (0, E_FAIL):
            g = Recovery(raw, delta=delta, run_hr=(E_FAIL, 0), seek_hr=seek_hr)
            g.invoke('resume')
            assert g.run_calls == 2 and g.creations == 1 and g.load_calls == ['native']
            assert g.targets[-1] == 37*UNIT and sum(g.owned.values()) == 6
            assert g.active_timers == {1000} and g.vm.read(0x2F96C+delta) == 1
            if seek_hr == E_FAIL:
                assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 0
                assert any(p['state'] == 1 for p in g.status_proofs)
            record('native reload preserves requested timestamp despite failed initial seek refresh', g,
                   seek_hr=seek_hr, base_delta=delta)
        for failure in ('position_error', 'position_missing', 'duration_missing'):
            config = {'position': ((E_FAIL, None),)} if failure == 'position_error' else (
                     {'missing_position_output': True} if failure == 'position_missing' else
                     {'duration': ((0, 300*UNIT), (0, 300*UNIT), (0, 300*UNIT), (0, 300*UNIT), (0, None))})
            g = Recovery(raw, delta=delta, run_hr=(E_FAIL, 0), seek_hr=(0, 0, E_FAIL), **config)
            g.position_after_reload = 9*UNIT
            g.vm.write(UI+0x2940, 29)
            g.vm.progress_writes.clear()
            g.invoke('resume')
            assert g.run_calls == 2 and g.targets[-1] == 37*UNIT and g.active_timers == {1000}
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 29
            assert not g.vm.progress_writes  # Unavailable progress is never published.
            record('unknown progress after fresh reload retains display and synchronizes cache', g,
                   failure=failure, base_delta=delta)
        for stage in ('create', 'render', 'control', 'event', 'seeking', 'audio', 'position', 'notify'):
            g = Recovery(raw, delta=delta, run_hr=E_FAIL); g.fail = stage
            g.invoke('resume')
            assert g.run_calls == 1 and g.creations == 1 and sum(g.owned.values()) == 0
            assert [e['value'] for e in g.events if e['api'] == 'native_manager_seek'].count(37) == 1
            assert g.vm.read(0x2F96C+delta) == 0 and not g.active_timers
            record('failed native reload skips subsequent resume seek', g, failure=stage, base_delta=delta)
        for samples, expected in ((((E_FAIL, 2), (0, 0)), 1), (((E_FAIL, 2),), 0)):
            pair = []
            for content in (old, raw):
                g = Recovery(content, delta=delta, samples=samples)
                result = g.invoke('play')
                pair.append((result, {k: g.snapshot()[k] for k in (
                    'run_calls', 'readiness', 'graph_flag', 'cached_state', 'play_state', 'active',
                    'slots', 'outstanding_references', 'released', 'active_timers', 'load_calls',
                    'creations', 'acquisitions', 'render_calls', 'locks', 'metadata_calls')}))
                assert result == expected
            assert pair[0] == pair[1]
            assert g.status_proofs[0]['state'] == 1
            record('actual LoadFile retry/refusal after failed Stop retained', g, expected, base_delta=delta)
        g = Recovery(raw, delta=delta)
        g.inserted = 0; before = g.vm.read(UI+0x2922)
        g.invoke('resume')
        assert not g.run_calls and not g.targets and g.vm.read(UI+0x2922) == before
        record('removed-device resume rejection unchanged', g, base_delta=delta)
    return dict(cases=len(traces)+checks['cases'], structure=checks, traces=traces,
                limits='Actual MIPS controllers, LoadFile, graph construction/retry, Stop and seek getters; explicit metadata/catalog/COM/OS responses. No native CE, codec, audio, concurrency, unwind or measured performance. Stop still cancels timers; existing pending-error status/auto-next policy remains.')


def retained(state, initialization, timing, completion, start, candidate,
             init_recipe, timing_recipe, completion_recipe, start_recipe, recipe):
    import verify_usb_graph_init as init_prior
    import verify_usb_seek_timing as timing_prior
    import verify_usb_seek_completion as completion_prior
    import verify_usb_playback_start as start_prior
    steps = [(state, initialization, init_recipe, init_prior.structure),
             (initialization, timing, timing_recipe, timing_prior.structure),
             (timing, completion, completion_recipe, completion_prior.structure),
             (completion, start, start_recipe, start_prior.structure),
             (start, candidate, recipe, structure)]
    def cumulative(first):
        def check(previous, written, _recipe):
            assert previous == steps[first][0] and written == candidate
            checks = [fn(a, b, edits) for a, b, edits, fn in steps[first:]]
            return dict(cases=sum(c['cases'] for c in checks), stages=checks)
        return check
    class RetainedPlayback(Recovery):
        def __init__(self, *args, **kwargs): super().__init__(*args, native_load=False, **kwargs)
        def snapshot(self): return Playback.snapshot(self)
    class RetainedSeeking(completion_prior.Seeking):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.vm.ranges.extend((a+self.delta, a+n+self.delta) for a, n, *_ in HELPERS)
    class RetainedTiming(RetainedSeeking):
        def __init__(self, *args, **kwargs): super().__init__(*args, follow_position=False, **kwargs)
        def snapshot(self):
            result = timing_prior.Timing.snapshot(self)
            result['progress_writes'] = [w['value'] for w in self.vm.progress_writes]
            return result
    native_timing = FunctionType(timing_prior.native_helper_checks.__code__,
                                dict(timing_prior.native_helper_checks.__globals__, Timing=RetainedTiming),
                                'retained_native_timing_checks')
    suites = {}
    for name, module, first, before, edits, replacements in (
        ('start', start_prior, 3, completion, start_recipe, {'Playback': RetainedPlayback}),
        ('completion', completion_prior, 2, timing, completion_recipe, {'Seeking': RetainedSeeking}),
        ('timing', timing_prior, 1, initialization, timing_recipe,
         {'Timing': RetainedTiming, 'native_helper_checks': native_timing}),
        ('initialization', init_prior, 0, state, init_recipe, {})):
        namespace = dict(module.verify.__globals__, structure=cumulative(first), **replacements)
        fn = FunctionType(module.verify.__code__, namespace, 'verify_retained_'+name)
        print('Retained USB '+name, flush=True); suites[name] = fn(before, candidate, edits)
    return suites


def retained_graph_state(original, candidate, recipe):
    import verify_usb_graph_state as prior
    class RetainedGraph(prior.Graph):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.vm.ranges.extend((a+self.delta, a+n+self.delta) for a, n, *_ in HELPERS)
    caller = FunctionType(prior.caller_failure_return.__code__,
                          dict(prior.caller_failure_return.__globals__, Graph=RetainedGraph),
                          'retained_caller_failure_return', prior.caller_failure_return.__defaults__)
    # The old Stop leaf promised a tail call directly to the clock setter.
    # This candidate deliberately replaces it with confirmed status publication.
    # Replace its 12 leaf/caller cases with full-owner cases; retain all other
    # graph-state cases and the unmodified cumulative structure verification.
    gates = tuple(g for g in prior.GATES if 0x1AF9C not in g[1])
    assert len(gates) == len(prior.GATES)-1
    namespace = dict(prior.verify.__globals__, Graph=RetainedGraph,
                     caller_failure_return=caller, GATES=gates)
    fn = FunctionType(prior.verify.__code__, namespace, 'verify_retained_graph_state')
    result = fn(original, candidate, recipe)
    replacements = []
    for delta in (0, 0x1000, 0x10000, 0x123000):
        raw = relocated(candidate, delta) if delta else candidate
        for state, samples, expected in ((1, ((0, 0),), 1),
                                         (1, ((E_FAIL, 2),), 0),
                                         (2, ((INTERMEDIATE, 0),), 0)):
            g = Recovery(raw, delta=delta, samples=samples)
            g.vm.write(UI+0x2922, state)
            assert g.invoke('stop') == expected
            assert g.vm.read(UI+0x2922) == (3 if expected else state)
            assert bool(g.published) == bool(expected)
            assert sum(g.owned.values()) == 6 and not g.released
            replacements.append(dict(name='full Stop owner replaces old clock-only leaf contract',
                                     base_delta=delta, expected=expected, **g.snapshot()))
    assert len(replacements) == 12
    result['cases'] += len(replacements)
    result['replacement_stop_owner_cases'] = replacements
    result['superseded_stop_leaf_cases'] = 12
    return result
