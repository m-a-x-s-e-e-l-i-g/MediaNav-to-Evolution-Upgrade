"""Seek-result MIPS fixtures; COM/files/dispatch entry states are simulated."""
import hashlib
import itertools
import struct
from types import FunctionType

import pefile

from inspect_bt_pairing import put, data
from inspect_wave_queue import STOP
from verify_media_responsiveness import Resume, STACK, COOKIE, call, rematch
from verify_usb_seek_timing import Timing, UI, UNIT, signed
from verify_usb_graph_state import OBJECT, INSTANCE, API, E_FAIL
from verify_usb_input_safety import relocated
from patch_usb_seek_completion import BASE, BASE_SHA, HELPERS, SITES


class Seeking(Timing):
    """Actual callers, setters and UI wrappers; explicit file/COM responses.

    Successful COM seeks update the position fixture; failed COM seeks do not.
    Caller return, stack, cleanup, native timers and notifications still execute.
    Codec/load internals and the end controller are separate API fixtures here.
    """
    def __init__(self, raw, follow_position=True, **kwargs):
        super().__init__(raw, **kwargs)
        self.follow_position = follow_position
        self.current = self.position[0][1]
        self.handles, self.cookie_frees, self.load_calls = set(), [], []
        self.graph_ok = self.disk_ok = self.file_ok = self.info_ok = True
        self.free_bytes, self.total, self.serial, self.size = 2**32+123, 2**33, 0x12345678, 123456
        m, d = self.vm, self.delta
        m.ranges.extend((a+d, b+d) for a, b in ((0x1BA3C, 0x1BE50), (0x1A69C, 0x1A7D0)))
        m.ranges.extend((at+d, at+cap+d) for at, cap, *_ in HELPERS)
        put(m, UI+0x1088, '\\MD\\Music\\Track.mp3\0'.encode('utf-16le'))
        m.write(UI+0xE78, 1)
        put(m, UI+0x1AB8, struct.pack('<QQII', self.free_bytes, self.total, self.size, self.serial))
        m.write(INSTANCE+0x74, 0xFFFFFFFF); m.write(0x2F960+d, COOKIE)
        m.hooks.update({at+d: fn for at, fn in (
            (0x253BC, self.length), (0x25668, self.copy), (0x253DC, self.zero),
            (0x253CC, self.format), (0x251FC, self.compare), (0x251DC, self.disk),
            (0x19254, self.metadata), (0x12264, self.load), (0x25510, self.free_owned),
            (0x197E4, self.no_more_work), (0x1A318, self.no_more_work),
            (0x1AE54, self.no_more_work), (0x1DC00, self.no_more_work),
            (0x1A9E4, self.no_more_work), (0x1B670, self.no_more_work))})
        for i, (iat, fn) in enumerate(((0x2F034, self.open), (0x2F084, self.info),
                                      (0x2F038, self.close), (0x2F020, self.attributes))):
            token = API+0x400+i*4; m.write(iat+d, token); m.hooks[token] = fn

    def set_position(self, m):
        result = super().set_position(m)
        self.events[-1]['hr'] = result
        if signed(result) >= 0 and self.follow_position: self.current = self.targets[-1]
        return result

    def get_position(self, m):
        if not self.follow_position: return super().get_position(m)
        hr, _ = self.position[min(self.position_index, len(self.position)-1)]
        responses = ((hr, self.current),)
        result = self.output(m, responses, 0, 'GetCurrentPosition')
        self.position_index += 1
        return result

    def pure(self, m, fn):
        result = fn(m); self.clobber(m); return result

    def length(self, m): return self.pure(m, lambda v: len(v.text(v.reg[4])))
    def copy(self, m): return self.pure(m, lambda v: Resume.copy(self, v))
    def zero(self, m): return self.pure(m, lambda v: Resume.zero(self, v))
    def format(self, m): return self.pure(m, lambda v: Resume.format(self, v))
    def compare(self, m): return self.pure(m, lambda v: Resume.compare(self, v))

    def disk(self, m):
        assert m.text(m.reg[4]) == 'MD'
        if self.disk_ok:
            for ptr, value in zip(m.reg[5:8], (self.free_bytes, self.total, self.free_bytes)):
                put(m, ptr, struct.pack('<Q', value))
        self.clobber(m); return int(self.disk_ok)

    def open(self, m):
        assert m.reg[5:8] == [0x80000000, 1, 0] and m.read(m.reg[29]+0x10) == 3
        assert m.text(m.reg[4]) == '\\MD\\Music\\Track.mp3'
        result = 0x7777 if self.file_ok else 0xFFFFFFFF
        if self.file_ok: self.handles.add(result)
        self.clobber(m); return result

    def info(self, m):
        assert m.reg[4] in self.handles
        if self.info_ok:
            put(m, m.reg[5], bytes(52)); m.write(m.reg[5]+0x1C, self.serial); m.write(m.reg[5]+0x24, self.size)
        self.clobber(m); return int(self.info_ok)

    def close(self, m):
        assert m.reg[4] in self.handles
        self.handles.remove(m.reg[4]); self.clobber(m); return 1

    def attributes(self, m): self.clobber(m); return 2
    def metadata(self, m): self.clobber(m); return 0

    def load(self, m):
        assert m.reg[4] == OBJECT and m.text(m.reg[5]) == '\\MD\\Music\\Track.mp3' and m.reg[6] == 1
        self.load_calls.append(bool(self.graph_ok)); self.clobber(m); return int(self.graph_ok)

    def free_owned(self, m):
        if m.reg[4] == COOKIE:
            self.cookie_frees.append(COOKIE); self.clobber(m); return 0
        return super().free(m)

    def run_resume(self, requested=90):
        m = self.vm; m.write(UI+0xE7C, requested)
        saved = {r: 0x12340000+r for r in (*range(16, 24), 28, 30)}
        for r, value in saved.items(): m.reg[r] = value
        m.reg[4:8] = [UI, 0, 0, 0]; m.reg[29], m.reg[31] = STACK, STOP
        # The real resume frame is 0x470, with nested helpers below that frame.
        m.write(STACK-0x2000, 0xA55AA55A); m.write(STACK+0x40, 0xA55AA55A)
        m.run(0x1BA3C+self.delta, {STOP}, limit=30000)
        assert m.reg[29] == STACK and m.reg[31] == STOP
        assert all(m.reg[r] == value for r, value in saved.items())
        assert m.read(STACK-0x2000) == m.read(STACK+0x40) == 0xA55AA55A
        assert not self.handles and self.cookie_frees == [COOKIE]
        return m.reg[2]

    def release_without_play(self, play_state=2, blocked=0):
        # Execute the original release cleanup. Its playing/resume branch is a
        # separate controller and is deliberately not substituted as success.
        assert play_state != 1 or blocked
        m = self.vm
        m.ranges.append((0x1D1B0+self.delta, 0x1D23C+self.delta))
        del m.hooks[0x1D1B0+self.delta]
        put(m, UI+0x2922, struct.pack('<I', play_state)); m.write(UI+0x1AD0, blocked)
        return call(m, 0x1D1B0+self.delta, [UI])

    def snapshot(self):
        return dict(super().snapshot(), timer_ids=self.timer_ids.copy(),
                    seek_mode=self.vm.read(UI+0x2930), repeat_factor=self.vm.read(UI+0xE60),
                    ready=self.vm.read(UI+0x292A), cookie_frees=self.cookie_frees.copy(),
                    load_calls=self.load_calls.copy(), outstanding_handles=len(self.handles))


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
    assert len(after) == len(before)+2 and set(before) <= set(after)
    assert after == sorted(after) and all(x[1] <= y[0] for x, y in zip(after, after[1:]))
    assert set(map(tuple, recipe['added_pdata_rows'])) == set(after)-set(before)
    for row in before:
        if 0x3C000 <= row[0] < 0x40F00:
            assert a.get_data(row[0]-BASE, row[1]-row[0]) == b.get_data(row[0]-BASE, row[1]-row[0])
    for at, cap, *_ in HELPERS:
        assert a.get_data(at-BASE, cap) == bytes(cap)
        assert not any(at < r[1] and r[0] < at+cap for r in before)
        assert any(r[0] == at and r[4] == at+8 for r in after)
    for source, target in ((0x1D940, 0x1DAB0), (0x1DA8C, 0x1DAB0), (0x21780, 0x21028)):
        owner = next(r for r in before if r[0] <= source < r[1])
        assert owner[0] <= target < owner[1]
    for at, cap, _ in SITES:
        assert a.get_data(at+cap-BASE, 4) == b.get_data(at+cap-BASE, 4)
    assert a.get_data(0x40E00-BASE, 0x200) == b.get_data(0x40E00-BASE, 0x200)
    for index in (3, 5):
        d = b.OPTIONAL_HEADER.DATA_DIRECTORY[index]; s = b.get_section_by_rva(d.VirtualAddress)
        assert d.VirtualAddress+d.Size <= s.VirtualAddress+s.SizeOfRawData
    return dict(cases=1, exact_reversal=True, prior_function_bodies_preserved=True,
                prior_exception_rows_preserved=True, sections_imports_entry_preserved=True,
                own_frame_error_exits=True, framed_helpers=True)


def reproduce(previous):
    traces = []
    g = Seeking(previous, seek_hr=E_FAIL)
    assert g.run_resume() == 1 and g.vm.read(UI+0x2940) == 90 and g.position_index == 0
    traces.append(dict(name='failed saved resume publishes requested time', **g.snapshot()))
    for position in (42*UNIT, 299*UNIT):
        g = Seeking(previous, seek_hr=E_FAIL, position=((0, position),))
        g.vm.write(UI+0x2930, 1); g.run_timing('held')
        assert g.vm.progress_writes
        if position == 299*UNIT: assert g.notifications and g.end_actions and g.vm.read(UI+0x2930) == 0
        traces.append(dict(name='failed held seek updates progress or completes', position=position, **g.snapshot()))
    g = Seeking(previous, seek_hr=E_FAIL)
    assert g.run_dispatched('ipc') == 1 and g.vm.read(UI+0x2940) == 90
    assert next(e['api'] for e in g.events if e['api'] in ('native_progress_set', 'SetPositions')) == 'native_progress_set'
    traces.append(dict(name='IPC publishes before seek failure is known', **g.snapshot()))
    return traces


def parity_snapshot(g):
    # Notification/seek ordering changes intentionally; compare stored values,
    # API counts, ownership and state. Separate assertions check the new order.
    result = g.snapshot()
    result['progress_writes'] = [w['value'] for w in g.vm.progress_writes]
    return result


def retained_resume_identity(original, candidate):
    """Replace the historical zero-return seek stub with actual setter bytes.

    Preserve the 17 identity decisions, three saved-position cases and five
    library rematches from the published suite. A successful native manager
    seek returns 1; the historical substitute incorrectly returned 0.
    """
    cases = (
        ('unchanged', {}, 1, 1), ('added small file', {'free_bytes': 2**32+100}, 0, 1),
        ('removed file', {'free_bytes': 2**32+500}, 0, 1), ('free high DWORD', {'free_bytes': 2**31}, 0, 1),
        ('nearly full', {'free_bytes': 0}, 0, 1), ('other volume', {'serial': 99}, 0, 0),
        ('same capacity other volume', {'serial': 99, 'free_bytes': 2**32+100}, 0, 0),
        ('changed file size', {'size': 123457}, 0, 0), ('file removed', {'file_ok': False}, 0, 0),
        ('file-info error', {'info_ok': False}, 0, 0), ('disk API error', {'disk_ok': False}, 0, 0),
        ('capacity low DWORD', {'total': 2**33+1}, 0, 0), ('capacity high DWORD', {'total': 2**34}, 0, 0),
        ('graph rejects file', {'graph_ok': False}, 0, 0),
        ('changed free and graph rejection', {'free_bytes': 0, 'graph_ok': False}, 0, 0),
        ('empty path', {'path': ''}, 0, 0), ('relative path', {'path': 'MD\\Music\\Track.mp3', 'free_bytes': 0}, 0, 1),
    )
    traces = []
    for name, config, old_result, new_result in cases:
        pair = []
        for content, expected in ((original, old_result), (candidate, new_result)):
            g = Seeking(content)
            for field, value in config.items():
                if field == 'path': put(g.vm, UI+0x1088, (value+'\0').encode('utf-16le'))
                else: setattr(g, field, value)
            assert g.run_resume(42) == expected
            assert len(g.targets) == expected
            pair.append(g.snapshot())
        if old_result == new_result and not ('free_bytes' in config and not config.get('graph_ok', True)):
            assert pair[0] == pair[1], (name, pair)
        traces.append(dict(name=name, before=pair[0], after=pair[1]))
    for position in (0, 1, 299):
        g = Seeking(candidate); g.free_bytes = 0
        assert g.run_resume(position) == 1
        assert g.targets == [position*UNIT] and g.vm.read(UI+0xE7C) == position
        traces.append(dict(name='saved position retained', position=position, after=g.snapshot()))
    target = ('Track.mp3', 'MD\\Music')
    for tracks, index in (([target], 0), ([('Added.mp3', 'MD\\Music'), target], 1),
                          ([('Track.mp3', 'MD\\Other'), ('Other.mp3', 'MD\\Music'), target], 2),
                          ([('Track.mp3', 'MD\\Other')], 0xFFFFFFFF), ([], 0xFFFFFFFF)):
        assert rematch(original, tracks) == rematch(candidate, tracks) == index
        traces.append(dict(name='library rematch unchanged', tracks=tracks, index=index))
    m = Seeking(candidate).vm; point = 0x54000000
    for offset in range(4):
        put(m, point, b'abcdefgh'); m.reg[4] = point+offset; m.reg[8] = 0x12345678
        m.plain((0x22 << 26) | (4 << 21) | (8 << 16) | 3)
        m.plain((0x26 << 26) | (4 << 21) | (8 << 16))
        assert m.reg[8] == int.from_bytes(b'abcdefgh'[offset:offset+4], 'little')
        m.reg[8] = 0x12345678
        m.plain((0x2A << 26) | (4 << 21) | (8 << 16) | 3)
        m.plain((0x2E << 26) | (4 << 21) | (8 << 16))
        expected = bytearray(b'abcdefgh'); expected[offset:offset+4] = bytes.fromhex('78563412')
        assert data(m, point, 8) == bytes(expected)
    return dict(cases=len(traces), traces=traces, actual_seek_instructions=True,
                supersedes_historical_zero_result_seek_stub=True, unaligned_merge_cases=4)


def verify(previous, candidate, recipe):
    traces = reproduce(previous); checks = structure(previous, candidate, recipe)
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        raw = relocated(candidate, delta) if delta else candidate
        for requested, hr in itertools.product((0, 42, 90, 400), (0, 1)):
            pairs = []
            for content in (old, raw):
                g = Seeking(content, delta=delta, seek_hr=hr)
                pairs.append((g.run_resume(requested), parity_snapshot(g)))
            assert pairs[0] == pairs[1]
            traces.append(dict(name='healthy saved resume unchanged', base_delta=delta, requested=requested, hr=hr))
        for hr, observed in itertools.product((E_FAIL, 0x80004001, 0x80070057), (0, 42*UNIT, 89*UNIT+8_500_000)):
            g = Seeking(raw, delta=delta, seek_hr=hr, position=((0, observed),))
            assert g.run_resume() == 1 and len(g.targets) == 1
            expected = (observed+1_500_000)//UNIT
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == expected
            assert g.position_index == 1 and g.vm.read(UI+0x292A) == 1 and len(g.published) == 1
            traces.append(dict(name='failed saved seek queries confirmed position', base_delta=delta, hr=hr,
                               observed=observed, **g.snapshot()))
        for failure in ('position', 'duration', 'interface'):
            kwargs = {'seek_hr': E_FAIL}
            if failure == 'position': kwargs['position'] = ((E_FAIL, 123*UNIT),)
            elif failure == 'duration': kwargs['duration'] = ((E_FAIL, 123*UNIT),)
            else: kwargs['interface'] = False
            g = Seeking(raw, delta=delta, **kwargs)
            assert g.run_resume() == 1 and g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 0
            assert g.vm.read(UI+0x292A) == 1 and g.cookie_frees == [COOKIE]
            traces.append(dict(name='unknown resume position uses explicit zero fallback', failure=failure,
                               base_delta=delta, **g.snapshot()))
        for gate in ('disk_ok', 'file_ok', 'info_ok', 'graph_ok'):
            pairs = []
            for content in (old, raw):
                g = Seeking(content, delta=delta); setattr(g, gate, False)
                pairs.append((g.run_resume(), parity_snapshot(g)))
                assert not g.targets and not g.vm.progress_writes
            assert pairs[0] == pairs[1] and pairs[0][0] == 0
            traces.append(dict(name='resume rejection and cleanup unchanged', gate=gate, base_delta=delta))
        for direction, factor, position, hr in itertools.product((1, 2), (0, 1, 4), (0, 42*UNIT, 299*UNIT), (0, 1)):
            pairs = []
            for content in (old, raw):
                g = Seeking(content, delta=delta, seek_hr=hr, position=((0, position),))
                g.vm.write(UI+0x2930, direction); g.vm.write(UI+0xE60, factor)
                pairs.append((g.run_timing('held'), parity_snapshot(g)))
            assert pairs[0] == pairs[1], (direction, factor, position, hr, pairs)
            if direction == 1 and position == 299*UNIT:
                assert next(e['api'] for e in g.events if e['api'] in ('SetPositions', 'native_finish_seek')) == 'SetPositions'
            traces.append(dict(name='healthy held seek unchanged; end completion follows success',
                               direction=direction, factor=factor, position=position, hr=hr, base_delta=delta))
        for direction, factor, position, hr in itertools.product((1, 2), (0, 1, 4), (0, 42*UNIT, 299*UNIT),
                                                                (E_FAIL, 0x80004001, 0x80070057)):
            g = Seeking(raw, delta=delta, seek_hr=hr, position=((0, position),))
            g.vm.write(UI+0x2930, direction); g.vm.write(UI+0xE60, factor)
            g.run_timing('held')
            assert len(g.targets) == 1 and not g.vm.progress_writes and not g.published
            assert not g.notifications and not g.end_actions and g.timer_ids == [1000]
            # Original backward arithmetic clears its factor at the beginning,
            # before calling SetPositions. Do not undo that pre-seek clamp.
            expected_factor = 0 if direction == 2 and position == 0 else factor
            assert g.vm.read(UI+0x2930) == direction and g.vm.read(UI+0xE60) == expected_factor
            assert g.vm.read(UI+0x2940) == g.vm.read(UI+0xE7C) == 37
            traces.append(dict(name='failed held seek preserves progress and repeat state', direction=direction,
                               factor=factor, position=position, hr=hr, base_delta=delta, **g.snapshot()))
        for requested, hr in itertools.product((0, 42, 90, 400), (0, 1)):
            pairs = []
            for content in (old, raw):
                g = Seeking(content, delta=delta, seek_hr=hr)
                pairs.append((g.run_dispatched('ipc', requested), parity_snapshot(g)))
            assert pairs[0] == pairs[1]
            if g.targets:
                assert next(e['api'] for e in g.events if e['api'] in ('SetPositions', 'native_progress_set')) == 'SetPositions'
            traces.append(dict(name='healthy IPC result/progress unchanged; update follows success',
                               requested=requested, hr=hr, base_delta=delta))
        for requested, hr in itertools.product((0, 90, 400), (E_FAIL, 0x80004001, 0x80070057)):
            g = Seeking(raw, delta=delta, seek_hr=hr)
            assert g.run_dispatched('ipc', requested) == 1 and len(g.targets) == 1
            assert not g.vm.progress_writes and not g.published and not g.notifications
            assert g.vm.read(UI+0x2940) == g.vm.read(UI+0xE7C) == 37
            traces.append(dict(name='failed IPC seek preserves progress and own return', requested=requested,
                               hr=hr, base_delta=delta, **g.snapshot()))
        g = Seeking(raw, delta=delta, samples=((0, 2),)); g.action_hr = E_FAIL
        assert g.run_dispatched('ipc') == 1 and not g.targets and not g.vm.progress_writes
        traces.append(dict(name='failed IPC pause also skips premature progress', base_delta=delta, **g.snapshot()))
        for kind in ('ipc', 'held'):
            g = Seeking(raw, delta=delta, seek_hr=E_FAIL)
            g.vm.write(UI+0x2930, 1)
            run = (lambda: g.run_dispatched('ipc')) if kind == 'ipc' else (lambda: g.run_timing('held'))
            run(); assert not g.vm.progress_writes
            g.seek_hr = 0; run()
            assert len(g.targets) == 2 and g.vm.progress_writes
            traces.append(dict(name='seek error followed by successful retry', kind=kind, base_delta=delta, **g.snapshot()))
        for direction, position, state in itertools.product((1, 2), (0, 42*UNIT, 299*UNIT), (0, 1, 2)):
            g = Seeking(raw, delta=delta, seek_hr=E_FAIL, position=((0, position),))
            g.vm.write(UI+0x2930, direction); g.vm.write(UI+0xE60, 4)
            g.run_timing('held'); targets = g.targets.copy()
            g.release_without_play(state, int(state == 1))
            assert g.timer_ids == [1000, 1001, 1002]
            assert g.vm.read(UI+0x2930) == g.vm.read(UI+0xE60) == 0
            assert g.targets == targets and not g.vm.progress_writes and not g.notifications and not g.end_actions
            traces.append(dict(name='actual held release clears state/timers; no-play branches',
                               direction=direction, position=position, state=state, base_delta=delta, **g.snapshot()))
        # The window owner refreshes actual progress; it is deliberately unchanged.
        for hr in (0, E_FAIL):
            pairs = []
            for content in (old, raw):
                g = Seeking(content, delta=delta, seek_hr=hr)
                pairs.append((g.run_dispatched('window'), parity_snapshot(g)))
            assert pairs[0] == pairs[1]
            traces.append(dict(name='window refresh and owned-buffer cleanup unchanged', hr=hr, base_delta=delta))
    return dict(cases=len(traces)+checks['cases'], structure=checks, traces=traces,
                limits='Actual MIPS instructions with COM/file/UI/library fixtures; supplied dispatcher entry states. No native CE, audio, concurrency, unwind or performance validation.')


def retained_timing(initialization, timing, candidate, timing_recipe, completion_recipe):
    """Original behavior suite in an isolated namespace, with cumulative structure.

    The suite never asserts failed setter publication in the newly fixed owners;
    its healthy comparisons and previous error cases remain applicable.
    """
    import verify_usb_seek_timing as prior
    class RetainedSeeking(Seeking):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, follow_position=False, **kwargs)
        def snapshot(self):
            result = Timing.snapshot(self)
            result['progress_writes'] = [w['value'] for w in self.vm.progress_writes]
            return result
    def cumulative_structure(previous, written, _recipe):
        assert previous == initialization and written == candidate
        first = prior.structure(initialization, timing, timing_recipe)
        second = structure(timing, candidate, completion_recipe)
        return dict(cases=first['cases']+second['cases'], timing=first, completion=second)
    namespace = dict(prior.verify.__globals__, structure=cumulative_structure, Timing=RetainedSeeking)
    adapted = FunctionType(prior.verify.__code__, namespace, 'verify_cumulative_timing')
    return adapted(initialization, candidate, timing_recipe)


def retained_initialization(state, initialization, timing, candidate, init_recipe, timing_recipe, completion_recipe):
    import verify_usb_graph_init as prior
    import verify_usb_seek_timing as timing_prior
    def cumulative_structure(previous, written, _recipe):
        assert previous == state and written == candidate
        checks = [prior.structure(state, initialization, init_recipe),
                  timing_prior.structure(initialization, timing, timing_recipe),
                  structure(timing, candidate, completion_recipe)]
        return dict(cases=sum(c['cases'] for c in checks), stages=checks)
    namespace = dict(prior.verify.__globals__, structure=cumulative_structure)
    adapted = FunctionType(prior.verify.__code__, namespace, 'verify_cumulative_initialization')
    return adapted(state, candidate, init_recipe)
