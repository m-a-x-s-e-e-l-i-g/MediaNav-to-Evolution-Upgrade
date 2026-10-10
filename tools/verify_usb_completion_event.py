"""Actual DirectShow event owner and progress wrappers; explicit COM/OS fixtures."""
from collections import Counter
import hashlib
import itertools
import struct
from types import FunctionType

import pefile

from inspect_bt_pairing import put
from verify_media_responsiveness import call
from verify_usb_duration_output import Duration
from verify_usb_graph_state import OBJECT, INSTANCE, API, VTABLE, E_FAIL
from verify_usb_seek_timing import UI, UNIT
from verify_usb_input_safety import relocated
from patch_usb_completion_event import BASE, BASE_SHA, HELPERS, SITES


class CompletionEvent(Duration):
    def __init__(self, raw, queue=((1, 0, 0),), free_hr=0, **kwargs):
        super().__init__(raw, follow_position=False, **kwargs)
        self.clock = 1000
        self.queue, self.queue_index = list(queue), 0
        self.pending_event, self.event_frees, self.free_hr = None, [], free_hr
        m, d = self.vm, self.delta
        m.ranges.extend((a+d, b+d) for a, b in ((0x11AB0, 0x11E20),
                                             (0x1DD78, 0x1DD94), (0x1ACCC, 0x1AD38),
                                             (0x407B0, 0x407E0)))
        self.event_object = m.read(OBJECT+8)
        table = VTABLE+0x200
        put(m, table, bytes(0x40)); m.write(self.event_object, table)
        m.write(table+0x20, API+0x900); m.hooks[API+0x900] = self.get_event
        m.write(table+0x30, API+0x904); m.hooks[API+0x904] = self.free_event

    def get_event(self, m):
        assert m.reg[4] == self.event_object and m.read(m.reg[29]+0x10) == 0
        assert self.pending_event is None
        if self.queue_index == len(self.queue):
            self.events.append(dict(api='GetEvent', hr=E_FAIL))
            self.clobber(m); return E_FAIL
        event = self.queue[self.queue_index]; self.queue_index += 1
        self.pending_event = event
        for pointer, value in zip(m.reg[5:8], event): m.write(pointer, value & 0xFFFFFFFF)
        self.events.append(dict(api='GetEvent', event=event, hr=0))
        self.clobber(m); return 0

    def free_event(self, m):
        assert m.reg[4] == self.event_object
        event = tuple(m.reg[5:8])
        assert event == tuple(value & 0xFFFFFFFF for value in self.pending_event)
        self.event_frees.append(event); self.pending_event = None
        self.events.append(dict(api='FreeEventParams', event=event, hr=self.free_hr))
        self.clobber(m); return self.free_hr

    def sleep(self, m):
        assert m.reg[4] == 100
        self.events.append(dict(api='Sleep', ms=100))
        self.clock = (self.clock+100) & 0xFFFFFFFF
        self.clobber(m); return 0

    def run_event(self):
        result = call(self.vm, 0x11AB0+self.delta, [OBJECT], limit=200000)
        assert self.pending_event is None
        assert len(self.event_frees) == self.queue_index
        return result

    def event_snapshot(self):
        return dict(result_fields=self.snapshot(), event_frees=self.event_frees.copy(),
                    api_counts=dict(Counter(e['api'] for e in self.events)),
                    progress=[w['value'] for w in self.vm.progress_writes],
                    clock_bytes=bytes(self.vm.read(UI+0x1AD8+i, 1) for i in range(3)).hex(),
                    event_timestamp=self.vm.read(INSTANCE+0x2C), steps=self.vm.steps)


def reproduce(previous):
    traces = []
    for name, config in (
        ('healthy completion repeats duration query', {}),
        ('failed initial position is written to display', {'position': ((E_FAIL, None), (0, 42*UNIT))}),
        ('second duration query invalidates previously checked result',
         {'duration': ((0, 300*UNIT), (0, 300*UNIT), (0, 300*UNIT), (E_FAIL, None))}),
    ):
        g = CompletionEvent(previous, **config)
        assert g.run_event() == 0
        snapshot = g.event_snapshot()
        if not config: assert g.duration_index == 4 and snapshot['progress'] == [42, 300]
        else:
            assert 0 in snapshot['progress']
            assert any(e['api'] == 'native_progress_set' and e['value'] == 0xFFFFFFFF for e in g.events)
        traces.append(dict(name=name, **snapshot))
    return dict(cases=len(traces), traces=traces, native_executed=False, hardware_tested=False,
                limits='Full MIPS event owner/progress/publication wrappers; COM queue, time and IPC are explicit fixtures. No native CE, audio, concurrency, unwind or elapsed-time measurement.')


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
    assert set(before) <= set(after) and len(after) == len(before)+1
    assert after == sorted(after) and all(x[1] <= y[0] for x, y in zip(after, after[1:]))
    assert set(map(tuple, recipe['added_pdata_rows'])) == set(after)-set(before)
    for row in before:
        if 0x3C000 <= row[0] < 0x40F00:
            assert a.get_data(row[0]-BASE, row[1]-row[0]) == b.get_data(row[0]-BASE, row[1]-row[0])
    for at, n, _, _, prologue in HELPERS:
        assert not prologue and a.get_data(at-BASE, n) == bytes(n)
        assert not any(at < r[1] and r[0] < at+n for r in before)
        assert any(r[0] == at and r[4] == at for r in after)
    for at, n, _ in SITES: assert a.get_data(at+n-BASE, 4) == b.get_data(at+n-BASE, 4)
    for lo, hi in ((0x11AB0, 0x11AE0), (0x11D9C, 0x11E20)):
        assert a.get_data(lo-BASE, hi-lo) == b.get_data(lo-BASE, hi-lo)
    owner = next(r for r in before if r[0] <= 0x11CF4 < r[1])
    assert owner[0] <= 0x11D08 < owner[1]
    for delta in (0x1000, 0x10000, 0x123000):
        assert rows(pefile.PE(data=relocated(candidate, delta))) == [tuple(x+delta if x else 0 for x in r) for r in after]
    return dict(cases=1, exact_reversal=True, prior_helper_bodies_and_exception_rows_preserved=True,
                sections_imports_entry_preserved=True, original_owner_frame_and_event_cleanup_preserved=True,
                own_frame_fallback=True, alternate_load_bases=3)


def equivalent(g):
    result = g.event_snapshot()
    del result['steps']; result['api_counts'].pop('GetDuration', None)
    del result['result_fields']['duration_queries']
    del result['result_fields']['divisions']
    result['result_fields']['progress_writes'] = [w['value'] for w in result['result_fields']['progress_writes']]
    return result


def verify(previous, candidate, recipe):
    checks, baseline = structure(previous, candidate, recipe), reproduce(previous)
    traces = []
    def record(name, g, result=None, **extra):
        traces.append(dict(name=name, result=result, snapshot=g.event_snapshot(), **extra))
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        raw = relocated(candidate, delta) if delta else candidate
        for pos, duration in itertools.product((0, 1, UNIT, 42*UNIT, 400*UNIT), (0, 7*UNIT, 300*UNIT)):
            pairs, queries, divisions = [], [], []
            for content in (old, raw):
                g = CompletionEvent(content, delta=delta, position=((0, pos),), duration=((0, duration),))
                result = g.run_event(); pairs.append((result, equivalent(g))); queries.append(g.duration_index)
                divisions.append(g.divisions)
            assert pairs[0] == pairs[1]
            assert queries[0]-queries[1] == int(bool(g.published))
            assert divisions[0]-divisions[1] == queries[0]-queries[1]
            assert len(g.event_frees) == 1 and sum(g.owned.values()) == 6 and not g.released
            record('healthy completion unchanged with one checked duration query', g, result,
                   position=pos, duration=duration, duration_queries_before=queries[0],
                   duration_queries_after=queries[1], base_delta=delta)
        for code, free_hr in itertools.product((0, 2, 3, 6, 7, 10, 0x49, 123, 0xFFFFFFFF), (0, E_FAIL)):
            pairs = []
            for content in (old, raw):
                g = CompletionEvent(content, delta=delta, queue=((code, -1, 0x12345678),), free_hr=free_hr)
                result = g.run_event(); pairs.append((result, equivalent(g)))
            assert pairs[0] == pairs[1] and result == free_hr
            assert not g.duration_index and not g.position_index
            record('non-completion event ownership/logging/return unchanged', g, result,
                   code=code, free_hr=free_hr, base_delta=delta)
        for active, param2, repeat, age in itertools.product((0, 1), (0, 1), (0, 1), (0, 299, 300, 500)):
            pairs, queries = [], []
            for content in (old, raw):
                g = CompletionEvent(content, delta=delta, queue=((1, 0, param2),))
                g.vm.write(INSTANCE+0x28, active); g.vm.write(INSTANCE+8, repeat)
                g.vm.write(INSTANCE+0x2C, (1000-age) & 0xFFFFFFFF)
                result = g.run_event(); pairs.append((result, equivalent(g))); queries.append(g.duration_index)
            assert pairs[0] == pairs[1] and queries[0]-queries[1] == int(bool(g.published))
            record('completion guard/repeat/debounce policy unchanged', g, result,
                   active=active, param2=param2, repeat=repeat, age=age, base_delta=delta)
        for hr, value in ((E_FAIL, None), (0, None), (0, -UNIT)):
            g = CompletionEvent(raw, delta=delta, position=((hr, value),))
            assert g.run_event() == 0 and not g.vm.progress_writes and not g.published
            assert g.vm.read(UI+0x2940) == 37 and g.position_index == 2
            assert any(n[0:3] == [5, 5, 0x6C] for n in g.notifications)
            record('unavailable positions retain display and completion notification', g,
                   hr=hr, value=value, base_delta=delta)
            g = CompletionEvent(raw, delta=delta, position=((hr, value), (0, 42*UNIT)))
            assert g.run_event() == 0 and [w['value'] for w in g.vm.progress_writes] == [300]
            record('first unavailable position does not fabricate zero before recovery', g,
                   hr=hr, value=value, base_delta=delta)
        g = CompletionEvent(raw, delta=delta,
                            duration=((0, 300*UNIT), (0, 300*UNIT), (0, 300*UNIT), (E_FAIL, None)))
        assert g.run_event() == 0 and g.duration_index == 3
        assert [w['value'] for w in g.vm.progress_writes] == [42, 300]
        assert g.published and len(g.event_frees) == 1
        record('checked duration is reused instead of consuming a second failing query', g, base_delta=delta)
        g = CompletionEvent(raw, delta=delta, queue=((2, 0, 0), (1, 0, 0), (3, -1, 5), (1, 0, 0)))
        assert g.run_event() == 0 and len(g.event_frees) == 4 and g.duration_index == 3
        record('mixed queue drains with exact parameter frees and retained debounce', g, base_delta=delta)
        for absent in (False, True):
            pairs = []
            for content in (old, raw):
                g = CompletionEvent(content, delta=delta, queue=())
                if absent: g.owned[g.event_object] -= 1; g.vm.write(OBJECT+8, 0)
                result = g.run_event(); pairs.append((result, equivalent(g)))
            assert pairs[0] == pairs[1] and result == 0 and not g.event_frees
            record('empty queue or missing event interface unchanged', g, result, absent=absent, base_delta=delta)
    return dict(cases=checks['cases']+baseline['cases']+len(traces), structure=checks,
                baseline=baseline, traces=traces, limits=baseline['limits'])


class RetainedDuration(Duration):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.vm.ranges.extend((at+self.delta, at+n+self.delta) for at, n, *_ in HELPERS)


def retained(state, initialization, timing, completion, start, recovery, duration, candidate,
             init_recipe, timing_recipe, completion_recipe, start_recipe, recovery_recipe,
             duration_recipe, recipe):
    import verify_usb_duration_output as prior
    def cumulative(previous, written, edits):
        assert written == candidate
        a, b = prior.structure(previous, duration, edits), structure(duration, written, recipe)
        return dict(cases=a['cases']+b['cases'], stages=[a, b])
    namespace = dict(prior.retained.__globals__, Duration=RetainedDuration,
                     HELPERS=prior.HELPERS+HELPERS, structure=cumulative)
    fn = FunctionType(prior.retained.__code__, namespace, 'retained_event_stages')
    suites = fn(state, initialization, timing, completion, start, recovery, candidate,
                init_recipe, timing_recipe, completion_recipe, start_recipe, recovery_recipe, duration_recipe)
    duration_verify = FunctionType(prior.verify.__code__,
                                  dict(prior.verify.__globals__, Duration=RetainedDuration, structure=cumulative),
                                  'retained_duration_checks')
    print('Retained USB duration', flush=True)
    suites['duration'] = duration_verify(recovery, candidate, duration_recipe)
    return suites


def retained_graph_state(original, candidate, recipe):
    import verify_usb_duration_output as prior
    fn = FunctionType(prior.retained_graph_state.__code__,
                      dict(prior.retained_graph_state.__globals__, Duration=RetainedDuration,
                           HELPERS=prior.HELPERS+HELPERS), 'retained_event_graph_state')
    return fn(original, candidate, recipe)
