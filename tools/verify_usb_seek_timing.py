"""USB timing instruction fixtures; COM, integer library and OS calls are simulated.

This does not execute Windows CE, codecs, audio or native elapsed time.
"""
import struct
import hashlib
import itertools
from types import FunctionType

import pefile

from inspect_bt_pairing import put, data
from verify_media_responsiveness import VM, call, STACK
from verify_usb_graph_state import Graph, OBJECT, INSTANCE, API, E_FAIL
from inspect_wave_queue import STOP
from verify_usb_input_safety import relocated
from patch_usb_seek_timing import BASE_SHA, HELPERS, CAPACITY, SITES

SEEK, SEEK_TABLE, UI = 0x4C000000, 0x4D000000, 0x51000000
UNIT = 10_000_000


def signed(value, bits=32):
    return value-(1 << bits) if value & (1 << (bits-1)) else value


def quotient(a, b):
    assert b
    return (abs(a)//abs(b)) * (-1 if (a < 0) != (b < 0) else 1)


class TimingVM(VM):
    def word(self, pc):
        word = super().word(pc)
        marker = getattr(self, 'native_markers', {}).get(pc)
        if marker:
            self.timing_events.append(dict(api=marker, value=self.reg[5]))
        return word

    def write(self, at, value, size=4):
        super().write(at, value, size)
        # Observe the actual converter's DWORD store without replacing it.
        if at == UI+0x2940 and size == 4 and hasattr(self, 'progress_writes'):
            self.progress_writes.append(dict(value=value & 0xFFFFFFFF,
                                             event_index=len(self.timing_events)))

    def run(self, start, stops, limit=10000):
        # Same reviewed branch/delay-slot semantics as StorageVM, with explicit
        # tail-called API fixtures. A JR to an unknown address still fails closed.
        self.pc, initial = start, self.steps
        while self.pc not in stops:
            assert self.steps-initial < limit, 'Timing fixture step limit'
            pc, word = self.pc, self.word(self.pc)
            op, rs, rt, fn = word >> 26, (word >> 21)&31, (word >> 16)&31, word & 63
            if not (op in (1, 2, 3, 4, 5, 6, 7) or (op == 0 and fn in (8, 9))):
                self.plain(word); self.pc += 4; self.steps += 1
                continue
            hook, tail = None, False
            if op in (1, 4, 5, 6, 7):
                offset, value = signed(word & 65535, 16), signed(self.reg[rs])
                if op == 1:
                    assert rt in (0, 1)
                    taken = value < 0 if rt == 0 else value >= 0
                elif op in (4, 5): taken = (self.reg[rs] == self.reg[rt]) == (op == 4)
                else:
                    assert rt == 0
                    taken = value <= 0 if op == 6 else value > 0
                target = pc+4+offset*4 if taken else pc+8
            elif op == 0:
                target = self.reg[rs]
                if fn == 9: self.reg[(word >> 11)&31] = pc+8
                hook = self.hooks.get(target)
                tail = fn == 8 and hook is not None
                if fn == 9: assert hook is not None or self.internal_call(target), hex(target)
            else:
                target = ((pc+4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
                if op == 3:
                    self.reg[31] = pc+8; hook = self.hooks.get(target)
                    assert hook is not None or self.internal_call(target), hex(target)
            self.pc = pc+4
            self.plain(self.word(pc+4)); self.steps += 2
            if hook is None: self.pc = target
            else:
                return_address = self.reg[31] if tail else pc+8
                self.reg[2] = hook(self) & 0xFFFFFFFF
                self.pc = return_address

    def plain(self, word):
        if word >> 26 == 0 and word & 63 == 3:
            rt, rd, shift = (word >> 16)&31, (word >> 11)&31, (word >> 6)&31
            self.reg[rd] = (signed(self.reg[rt]) >> shift) & 0xFFFFFFFF
            self.reg[0] = 0
        elif word >> 26 == 0 and word & 63 == 0x1A:
            rs, rt = (word >> 21)&31, (word >> 16)&31
            a, b = signed(self.reg[rs]), signed(self.reg[rt])
            q = quotient(a, b)
            self.lo, self.hi = q & 0xFFFFFFFF, (a-q*b) & 0xFFFFFFFF
            self.reg[0] = 0
        else:
            super().plain(word)


class Timing(Graph):
    def __init__(self, raw, duration=((0, 300*UNIT),), position=((0, 42*UNIT),),
                 delta=0, seek_hr=0, samples=((0, 0),), interface=True):
        super().__init__(raw, samples=samples, delta=delta)
        previous = self.vm
        self.vm = TimingVM(previous.pe, previous.ranges)
        self.vm.__dict__.update(previous.__dict__)
        m = self.vm
        m.ranges.extend((a+delta, b+delta) for a, b in (
            (0x1111C, 0x113E0), (0x19864, 0x19900), (0x1B3B0, 0x1B484),
            (0x1D880, 0x1DACC), (0x20EAC, 0x21BEC), (0x21D00, 0x2271C),
            (0x40C00, 0x40E00), (0x19760, 0x197BC),
            (0x1DD5C, 0x1DD78), (0x1ED30, 0x1ED4C),
            (0x1B484, 0x1B544), (0x1ED4C, 0x1ED68)))
        # Internal calls must land at actual entry points, including each leaf.
        m.ranges.extend((a+delta, b+delta) for a, b in (
            (0x11230, 0x1137C), (0x1137C, 0x113E0), (0x19864, 0x198DC)))
        m.ranges.extend((a+delta, a+0x40+delta) for a in range(0x40C00, 0x40E00, 0x40))
        del m.hooks[0x1111C+delta]
        self.duration, self.position = list(duration), list(position)
        self.duration_index = self.position_index = self.divisions = 0
        self.seek_hr, self.targets, self.published, self.notifications = seek_hr, [], [], []
        self.timer_ids, self.end_actions, self.freed = [], [], []
        for at, n in ((SEEK, 0x20), (SEEK_TABLE, 0x50), (UI, 0x3000)):
            put(m, at, bytes(n))
        m.write(OBJECT+0xC, SEEK if interface else 0)
        m.write(SEEK, SEEK_TABLE)
        for off, fn in ((0x28, self.get_duration), (0x30, self.get_position), (0x38, self.set_position)):
            m.write(SEEK_TABLE+off, API+0x200+off); m.hooks[API+0x200+off] = fn
        m.hooks.update({0x2537C+delta: self.divide, 0x1144C+delta: self.manager,
                        0x24094+delta: self.publish, 0x23580+delta: self.notify,
                        0x2517C+delta: self.kill_timer, 0x1D23C+delta: self.end_action,
                        0x1D1B0+delta: self.end_action, 0x1DC80+delta: self.no_more_work,
                        0x25510+delta: self.free})
        m.write(INSTANCE+0x3C, 0x6666); m.write(INSTANCE+0x40, 0x9900)
        m.write(INSTANCE+0x4C, UI-8); m.write(INSTANCE+0x84, 1)
        m.write(UI+0x2922, 2); m.write(UI+0xE7C, 37); m.write(UI+0x2940, 37)
        put(m, UI+0x1AD8, bytes((0, 37, 0)))
        m.native_markers = {at+delta: name for at, name in (
            (0x19760, 'native_finish_seek'), (0x1DD5C, 'native_progress_set'),
            (0x1ED30, 'native_progress_refresh'))}
        m.timing_events, m.progress_writes = self.events, []

    def output(self, m, responses, index, name):
        assert m.reg[4] == SEEK
        hr, value = responses[min(index, len(responses)-1)]
        if value is not None:
            put(m, m.reg[5], struct.pack('<Q', value & 0xFFFFFFFFFFFFFFFF))
        self.events.append(dict(api=name, hr=hr, value=value))
        self.clobber(m)
        return hr

    def get_duration(self, m):
        result = self.output(m, self.duration, self.duration_index, 'GetDuration')
        self.duration_index += 1
        return result

    def get_position(self, m):
        result = self.output(m, self.position, self.position_index, 'GetCurrentPosition')
        self.position_index += 1
        return result

    def set_position(self, m):
        assert m.reg[4] == SEEK and m.reg[6:8] == [1, 0]
        assert m.read(m.reg[29]+0x10) == 0
        target = signed(int.from_bytes(data(m, m.reg[5], 8), 'little'), 64)
        self.targets.append(target)
        self.events.append(dict(api='SetPositions', target=target))
        self.clobber(m)
        return self.seek_hr

    def divide(self, m):
        a = signed(m.reg[4] | (m.reg[5] << 32), 64)
        b = signed(m.reg[6] | (m.reg[7] << 32), 64)
        result = quotient(a, b) & 0xFFFFFFFFFFFFFFFF
        self.divisions += 1; self.clobber(m); m.reg[3] = result >> 32
        return result & 0xFFFFFFFF

    def manager(self, m):
        self.clobber(m); return OBJECT

    def publish(self, m):
        assert m.reg[4] == 0x9900 and m.reg[5] == UI+0x1AD8 and m.reg[6:8] == [0, 0xE56]
        self.published.append(data(m, m.reg[5], m.reg[7]).hex()); self.clobber(m); return 1

    def notify(self, m):
        self.notifications.append(m.reg[4:8].copy()); self.clobber(m); return 1

    def kill_timer(self, m):
        assert m.reg[4] == 0x6666
        self.timer_ids.append(m.reg[5]); self.clobber(m); return 1

    def end_action(self, m):
        self.end_actions.append(m.reg[4:8].copy()); self.clobber(m); return 1

    def no_more_work(self, m):
        self.clobber(m); return 0

    def free(self, m):
        self.freed.append(m.reg[4]); self.clobber(m); return 0

    def run_timing(self, name, requested=0):
        address = dict(position=0x11230, duration=0x1137C, seek=0x1111C,
                       timer=0x1B3B0, held=0x1D880)[name]
        args = [UI] if name in ('timer', 'held') else [OBJECT]
        if name == 'seek': args.append(requested & 0xFFFFFFFF)
        return call(self.vm, address+self.delta, args, limit=20000)

    def run_controller(self, requested=90, do_seek=1, wrapper=True):
        address, this = (0x1ED4C, UI-8) if wrapper else (0x1B484, UI)
        return call(self.vm, address+self.delta, [this, requested, do_seek], limit=20000)

    def run_dispatched(self, kind, requested=90):
        # Actual function prologue and return surround the established seek arm.
        # Message parsing/selection is an explicit entry-state fixture.
        m, delta = self.vm, self.delta
        saved = {r: 0x12340000+r for r in (*range(16, 24), 28, 30)}
        for r, value in saved.items(): m.reg[r] = value
        m.reg[29], m.reg[31] = STACK, STOP
        m.write(STACK-0x2000, 0xA55AA55A); m.write(STACK+0x40, 0xA55AA55A)
        begin, prologue, arm = ((0x20EAC, 0x20EC0, 0x21704) if kind == 'ipc'
                                else (0x21D00, 0x21D1C, 0x223D4))
        m.run(begin+delta, {prologue+delta})
        request, owned = UI+0x2F00, 0x12345678
        m.write(request, requested); m.reg[17] = 1
        if kind == 'ipc': m.write(m.reg[29]+0x40, request)
        else:
            m.reg[16] = request; m.write(m.reg[29]+0xA60, owned)
        m.run(arm+delta, {STOP}, limit=20000)
        assert m.reg[29] == STACK and m.reg[31] == STOP
        assert all(m.reg[r] == v for r, v in saved.items()), 'Dispatched seek corrupted caller registers'
        assert m.read(STACK-0x2000) == m.read(STACK+0x40) == 0xA55AA55A
        assert self.freed == ([] if kind == 'ipc' else [owned])
        return m.reg[2]

    def snapshot(self):
        return dict(targets=self.targets.copy(), duration_queries=self.duration_index,
                    position_queries=self.position_index, divisions=self.divisions,
                    cached_position=self.vm.read(UI+0xE7C),
                    displayed_position=self.vm.read(UI+0x2940),
                    clock_bytes=data(self.vm, UI+0x1AD8, 3).hex(),
                    publishes=len(self.published), notifications=len(self.notifications),
                    end_actions=len(self.end_actions),
                    progress_refreshes=sum(e['api'] == 'native_progress_refresh' for e in self.events),
                    progress_writes=self.vm.progress_writes.copy(), freed=self.freed.copy())


def reproduce(previous):
    traces = []
    for value in (None, 7*UNIT):
        g = Timing(previous, duration=((E_FAIL, value),))
        result = g.run_timing('position')
        assert result == (0 if value is None else 7)
        traces.append(dict(name='failed duration accepted as position', result=result, **g.snapshot()))
    for duration in (0, 1, 1_499_999):
        g = Timing(previous, duration=((0, duration),))
        assert g.run_timing('seek', 0) == 1 and g.targets == [duration-1_500_000]
        traces.append(dict(name='negative reset seek', duration=duration, **g.snapshot()))
    g = Timing(previous, position=((E_FAIL, None),))
    g.run_timing('timer')
    assert g.vm.read(UI+0x2940) == 0 and len(g.published) == 1
    traces.append(dict(name='failed timer query publishes zero', **g.snapshot()))
    g = Timing(previous, duration=((0, -UNIT),))
    result = g.run_timing('duration')
    assert result > 300 and result != 0xFFFFFFFF
    traces.append(dict(name='negative duration becomes positive seconds', result=result, **g.snapshot()))
    for direction in (1, 2):
        g = Timing(previous, position=((E_FAIL, None),))
        g.vm.write(UI+0x2930, direction); g.run_timing('held')
        assert g.targets == [(2 if direction == 1 else 0)*UNIT]
        traces.append(dict(name='held seek consumes failed position', direction=direction, **g.snapshot()))
    for kind in ('ipc', 'window'):
        g = Timing(previous, position=((E_FAIL, None),))
        assert g.run_dispatched(kind) == 1 and g.targets == [90*UNIT]
        traces.append(dict(name='dispatched seek consumes failed position', kind=kind, **g.snapshot()))
    g = Timing(previous, seek_hr=E_FAIL)
    g.run_controller(90)
    assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 90
    assert g.targets == [90*UNIT] and len(g.published) == len(g.notifications) == 1
    traces.append(dict(name='failed seek sentinel accepted as true; requested progress published', **g.snapshot()))
    return traces


def native_helper_checks(candidate):
    """Independent contracts for the three previously substituted wrappers."""
    traces = []
    for delta in (0, 0x1000, 0x10000, 0x123000):
        raw = relocated(candidate, delta) if delta else candidate
        for send in (0, 1):
            g = Timing(raw, delta=delta)
            g.vm.write(UI+0x2930, 2); g.vm.write(UI+0xE60, 4)
            call(g.vm, 0x19760+delta, [UI, send])
            assert g.timer_ids == [1001, 1002]
            assert g.notifications == ([[5, 0x15, 0x6C, 0]] if send else [])
            assert g.vm.read(UI+0x2930) == 2 and g.vm.read(UI+0xE60) == 4
            assert not g.targets and not g.published and not g.vm.progress_writes
            traces.append(dict(name='actual finish helper cancels timers; optional notification',
                               base_delta=delta, send=send, **g.snapshot()))
        g = Timing(raw, delta=delta)
        call(g.vm, 0x1DD5C+delta, [UI-8, 90])
        assert g.vm.read(UI+0x2940) == 90 and data(g.vm, UI+0x1AD8, 3) == bytes((1, 30, 0))
        assert not g.duration_index and not g.position_index and not g.targets and not g.published
        assert not g.notifications and g.vm.read(UI+0xE7C) == 37
        traces.append(dict(name='actual progress-set wrapper and converter', base_delta=delta, **g.snapshot()))
        g = Timing(raw, delta=delta)
        call(g.vm, 0x1ED30+delta, [UI-8])
        assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 42
        assert g.duration_index == g.position_index == 1 and len(g.published) == 1
        assert g.notifications == [[5, 0x15, 0x65, 0]]
        assert not g.targets and not any(e['api'] in ('Pause', 'Stop', 'Mute') for e in g.events)
        traces.append(dict(name='actual progress-refresh wrapper; not playback resume',
                           base_delta=delta, **g.snapshot()))
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
        assert not touched & span
        touched |= span
        assert candidate[e['offset']:e['offset']+e['bytes']] == bytes.fromhex(e['after_hex'])
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    assert restored == previous
    rows = lambda p: [struct.unpack_from('<5I', p.get_data(p.OPTIONAL_HEADER.DATA_DIRECTORY[3].VirtualAddress,
                                                          p.OPTIONAL_HEADER.DATA_DIRECTORY[3].Size), i)
                      for i in range(0, p.OPTIONAL_HEADER.DATA_DIRECTORY[3].Size, 20)]
    before, after = rows(a), rows(b)
    assert len(after) == len(before)+8 and set(before) <= set(after)
    assert after == sorted(after) and all(x[1] <= y[0] for x, y in zip(after, after[1:]))
    assert set(map(tuple, recipe['added_pdata_rows'])) == set(after)-set(before)
    # Original caller delay slots and all prior graph/initialization helpers survive.
    for at, cap, _ in SITES:
        next_at = at+cap
        assert a.get_data(next_at-0x10000, 4) == b.get_data(next_at-0x10000, 4)
    assert a.get_data(0x3C000-0x10000, 0x40C00-0x3C000) == b.get_data(0x3C000-0x10000, 0x40C00-0x3C000)
    assert a.get_data(0x40E00-0x10000, 0x200) == b.get_data(0x40E00-0x10000, 0x200)
    for source, target in ((0x112BC, 0x11258), (0x113AC, 0x11390),
                           (0x1D8E0, 0x1DAB0), (0x1D8F0, 0x1DAB0), (0x1DA44, 0x1DAB0),
                           (0x21728, 0x21028), (0x223F4, 0x226C0), (0x1B3F8, 0x1B470),
                           (0x1B4B4, 0x1B530)):
        owner = next(r for r in before if r[0] <= source < r[1])
        assert owner[0] <= target < owner[1], 'Cross-frame error exit'
    for index in (3, 5):
        d = b.OPTIONAL_HEADER.DATA_DIRECTORY[index]
        s = b.get_section_by_rva(d.VirtualAddress)
        assert d.VirtualAddress+d.Size <= s.VirtualAddress+s.SizeOfRawData
    return dict(cases=1, exact_reversal=True, prior_helpers_preserved=True,
                sections_imports_entry_preserved=True, prior_exception_rows_preserved=True,
                failure_exits_in_owning_functions=True, tables_within_existing_raw_sections=True)


def verify(previous, candidate, recipe):
    traces = reproduce(previous)
    traces.extend(native_helper_checks(candidate))
    checks = structure(previous, candidate, recipe)
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        raw = relocated(candidate, delta) if delta else candidate
        # Healthy behavior is compared against the executed previous instructions.
        for duration, position in itertools.product((0, 1_500_000, 2*UNIT, 300*UNIT+8_500_000),
                                                    (0, 1, 8_490_000, 8_500_000, 42*UNIT, 400*UNIT)):
            pair = []
            for content in (old, raw):
                g = Timing(content, duration=((0, duration),), position=((0, position),), delta=delta)
                result = g.run_timing('position'); pair.append((result, g.snapshot()))
            assert pair[0] == pair[1]
            traces.append(dict(name='unchanged healthy position rounding/clamp', base_delta=delta,
                               duration=duration, position=position, result=pair[1][0]))
        for duration, requested, hr in itertools.product((2*UNIT, 300*UNIT+5_000_000),
                                                         (0, 1, 42, 300, 400), (0, E_FAIL)):
            pair = []
            for content in (old, raw):
                g = Timing(content, duration=((0, duration),), delta=delta, seek_hr=hr)
                pair.append((g.run_timing('seek', requested), g.snapshot()))
            assert pair[0] == pair[1]
            traces.append(dict(name='unchanged normal/near-end seek and HRESULT', base_delta=delta,
                               duration=duration, requested=requested, result=pair[1][0]))
        for value, hr in itertools.product((None, 0, 7*UNIT, -UNIT), (E_FAIL, 0x80004002, 0x80070057)):
            g = Timing(raw, duration=((hr, value),), delta=delta)
            assert g.run_timing('position') == 0xFFFFFFFF and not g.divisions
            traces.append(dict(name='failed duration output never consumed', base_delta=delta, hr=hr, value=value))
        for name in ('duration', 'position'):
            g = Timing(raw, duration=((0, -UNIT),), delta=delta)
            assert g.run_timing(name) == 0xFFFFFFFF and not g.divisions
            traces.append(dict(name='negative duration rejected: '+name, base_delta=delta))
        for duration, requested in itertools.product((0, 1, 1_499_999, 1_500_000), (0, 1, 42, 0xFFFFFFFF)):
            g = Timing(raw, duration=((0, duration),), delta=delta)
            assert g.run_timing('seek', requested) == 1 and g.targets == [0]
            traces.append(dict(name='nonnegative tiny/reset seek', base_delta=delta,
                               duration=duration, requested=requested, **g.snapshot()))
        for name in ('position', 'duration', 'seek'):
            g = Timing(raw, interface=False, delta=delta)
            assert g.run_timing(name) == 0xFFFFFFFF and not g.duration_index and not g.position_index and not g.targets
            traces.append(dict(name='missing interface: '+name, base_delta=delta))
        for wrapper, requested, do_seek, hr in itertools.product((False, True), (0, 42, 90, 400), (0, 1), (0, 1)):
            pair = []
            for content in (old, raw):
                g = Timing(content, delta=delta, seek_hr=hr)
                pair.append((g.run_controller(requested, do_seek, wrapper), g.snapshot()))
            assert pair[0] == pair[1]
            if not do_seek: assert not g.targets and not g.duration_index
            traces.append(dict(name='unchanged controller seek/display-only behavior', wrapper=wrapper,
                               requested=requested, do_seek=do_seek, hr=hr, base_delta=delta))
        for wrapper, requested, hr in itertools.product((False, True), (0, 42, 400),
                                                         (E_FAIL, 0x80004001, 0x80070057)):
            g = Timing(raw, delta=delta, seek_hr=hr)
            before = g.snapshot()
            assert g.run_controller(requested, wrapper=wrapper) == 0xFFFFFFFF
            assert len(g.targets) == 1 and not g.vm.progress_writes and not g.published and not g.notifications
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 37
            assert g.snapshot()['clock_bytes'] == before['clock_bytes']
            traces.append(dict(name='failed controller seek preserves progress', wrapper=wrapper,
                               requested=requested, hr=hr, base_delta=delta, **g.snapshot()))
        for wrapper in (False, True):
            g = Timing(raw, delta=delta, interface=False)
            assert g.run_controller(wrapper=wrapper) == 0xFFFFFFFF
            assert not g.targets and not g.duration_index and not g.vm.progress_writes and not g.published
            traces.append(dict(name='controller missing seeking interface', wrapper=wrapper, base_delta=delta))
        for mapping, notification in itertools.product((False, True), repeat=2):
            g = Timing(raw, delta=delta, seek_hr=E_FAIL)
            g.vm.write(INSTANCE+0x40, 0x9900 if mapping else 0)
            g.vm.write(INSTANCE+0x84, int(notification))
            assert g.run_controller() == 0xFFFFFFFF and not g.vm.progress_writes and not g.published and not g.notifications
            traces.append(dict(name='controller error independent of mapping/notification flags',
                               mapping=mapping, notification=notification, base_delta=delta))
        g = Timing(raw, delta=delta, seek_hr=E_FAIL)
        assert g.run_controller() == 0xFFFFFFFF and not g.vm.progress_writes
        g.seek_hr = 0
        assert g.run_controller() == 1 and len(g.targets) == 2
        assert len(g.published) == len(g.notifications) == len(g.vm.progress_writes) == 1
        assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 90
        traces.append(dict(name='controller error then successful retry', base_delta=delta, **g.snapshot()))
        # Positive failed-duration seek fallback remains the original behavior.
        for output in (None, -UNIT, 7*UNIT):
            pair = []
            for content in (old, raw):
                g = Timing(content, duration=((E_FAIL, output),), delta=delta)
                pair.append((g.run_timing('seek', 42), g.targets))
            assert pair[0] == pair[1] == (1, [42*UNIT])
            traces.append(dict(name='preserved seek fallback after failed duration', base_delta=delta, value=output))
        for failure in ('position', 'duration'):
            kwargs = {failure: ((E_FAIL, None),)}
            g = Timing(raw, delta=delta, **kwargs)
            before = g.snapshot()
            g.run_timing('timer')
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 37
            assert g.snapshot()['clock_bytes'] == before['clock_bytes'] and not g.published and not g.notifications
            g.duration, g.position = [(0, 300*UNIT)], [(0, 43*UNIT)]
            g.run_timing('timer')
            assert g.vm.read(UI+0xE7C) == g.vm.read(UI+0x2940) == 43
            assert len(g.published) == len(g.notifications) == 1
            traces.append(dict(name='timer failure retains display; next tick recovers', failure=failure,
                               base_delta=delta, **g.snapshot()))
        for direction, factor in itertools.product((1, 2), (0, 1, 4)):
            for failure in ('position', 'duration', 'second_duration'):
                kwargs = ({'duration': ((0, 300*UNIT), (E_FAIL, None))} if failure == 'second_duration'
                          else {failure: ((E_FAIL, None),)})
                g = Timing(raw, delta=delta, **kwargs)
                g.vm.write(UI+0x2930, direction); g.vm.write(UI+0xE60, factor)
                # Backward uses only one duration query; fail that query instead.
                if direction == 2 and failure == 'second_duration': g.duration = [(E_FAIL, None)]
                g.run_timing('held')
                assert not g.targets and not g.published and not g.notifications and not g.end_actions
                assert g.vm.read(UI+0x2940) == 37 and g.timer_ids == [1000]
                traces.append(dict(name='held seek rejects timing error', direction=direction, factor=factor,
                                   failure=failure, base_delta=delta, **g.snapshot()))
            for position in (0, 42*UNIT, 299*UNIT):
                pair = []
                for content in (old, raw):
                    g = Timing(content, position=((0, position),), delta=delta)
                    g.vm.write(UI+0x2930, direction); g.vm.write(UI+0xE60, factor)
                    pair.append((g.run_timing('held'), g.snapshot(), g.timer_ids))
                assert pair[0] == pair[1], (direction, factor, position, pair)
                traces.append(dict(name='unchanged healthy held seek', direction=direction, factor=factor,
                                   position=position, base_delta=delta))
        for kind in ('ipc', 'window'):
            for failure in ('position', 'duration', 'second_duration'):
                kwargs = ({'duration': ((0, 300*UNIT), (E_FAIL, None))} if failure == 'second_duration'
                          else {failure: ((E_FAIL, None),)})
                g = Timing(raw, delta=delta, **kwargs)
                assert g.run_dispatched(kind) == 1 and not g.targets and not g.vm.progress_writes
                assert not any(e['api'] in ('native_progress_set', 'native_progress_refresh') for e in g.events)
                traces.append(dict(name='dispatched error exits and cleanup', kind=kind,
                                   failure=failure, base_delta=delta, **g.snapshot()))
            for requested in (0, 42, 90, 400):
                pair = []
                for content in (old, raw):
                    g = Timing(content, delta=delta)
                    pair.append((g.run_dispatched(kind, requested), g.snapshot()))
                assert pair[0] == pair[1]
                traces.append(dict(name='unchanged healthy dispatched seek', kind=kind,
                                   requested=requested, base_delta=delta))
        g = Timing(raw, duration=((0, 1),), samples=((0, 0),), delta=delta)
        assert g.run('stop') == 1 and g.targets == [0]
        traces.append(dict(name='actual Stop reset on tiny track', base_delta=delta, **g.snapshot()))
    return dict(cases=len(traces)+checks['cases'], structure=checks, traces=traces,
                limits='Actual MIPS with COM, integer-library and OS fixtures; dispatched entry states are supplied. No CE, codec, audio, hardware or elapsed-time validation.')


def retained_initialization(state, initialization, candidate, init_recipe, timing_recipe):
    """Rerun the historical behavior suite on the cumulative executable.

    Its old structural check correctly refuses extra timing edits. Bind a separate
    function namespace to the two exact stage checks; never edit historical tools
    or monkeypatch their module globals. Its original 359 behavior cases execute
    against the new bytes, with the same explicit Graph/API fixtures.
    """
    import verify_usb_graph_init as prior

    def cumulative_structure(previous, written, _recipe):
        assert previous == state and written == candidate
        first = prior.structure(state, initialization, init_recipe)
        second = structure(initialization, candidate, timing_recipe)
        return dict(cases=first['cases']+second['cases'], initialization=first, timing=second)

    namespace = dict(prior.verify.__globals__, structure=cumulative_structure)
    adapted = FunctionType(prior.verify.__code__, namespace, 'verify_cumulative_initialization')
    return adapted(state, candidate, init_recipe)
