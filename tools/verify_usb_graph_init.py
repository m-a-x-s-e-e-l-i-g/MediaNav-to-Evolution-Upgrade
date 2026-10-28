"""Execute creation, rendering, queries, cleanup, retry and LoadFile MIPS paths.

COM and registry/lock/time calls are fixtures; no Windows CE or codec execution.
"""
import hashlib
import itertools
import struct
from collections import Counter

import pefile

from inspect_bt_pairing import put, data
from patch_usb_graph_init import BASE_SHA, CLEANUP, CAPACITY
from verify_usb_graph_state import Graph, OBJECT, CONTROL, AUDIO, INSTANCE, VTABLE, API, E_FAIL
from verify_media_responsiveness import call
from verify_usb_input_safety import relocated

OFFSETS = (4, 8, 0xC, 0x14, 0x18)
STAGES = ('create', 'render', 'control', 'event', 'seeking', 'audio', 'position', 'notify')
FILE, WINDOW = 0x50000000, 0x7777


class Initialization(Graph):
    def __init__(self, raw, fail=None, hr=E_FAIL, delta=0, alias=False,
                 samples=((0, 0),), creator_output=True, query_success=0):
        super().__init__(raw, samples=samples, cached=0, delta=delta, control=False, audio=False)
        m = self.vm
        m.ranges.extend([(0x11054+delta, 0x1111C+delta), (0x11F78+delta, 0x12264+delta),
                         (0x12264+delta, 0x12444+delta),
                         (CLEANUP+delta, CLEANUP+CAPACITY+delta)])
        del m.hooks[0x11054+delta]
        put(m, OBJECT+4, bytes(0x18))
        put(m, VTABLE, bytes(0x300))
        m.write(OBJECT+0x1C, WINDOW)
        m.write(INSTANCE+0x28, 0)
        self.fail, self.hr, self.creator_output = fail, hr, creator_output
        self.query_success = query_success
        self.control = CONTROL
        self.pointers = {0x10: CONTROL+0x1000, 4: CONTROL, 8: CONTROL+0x1100,
                         0xC: CONTROL+0x1200, 0x14: AUDIO, 0x18: CONTROL+0x1300}
        if alias:
            self.pointers[0xC] = self.pointers[0x18] = self.pointers[8]
        self.refs, self.acquisitions, self.creations, self.notifications = {}, [], 0, 0
        self.lock_depth, self.locks = 0, []
        for off, ptr in self.pointers.items():
            put(m, ptr, bytes(0x20))
            table = VTABLE+(0x100 if off == 0x10 else 0x200 if off == 0x14 else 0)
            m.write(ptr, table)
            m.write(table+8, API+8)
        for offset, token, fn in ((0, 0x100, self.query), (0x34, 0x104, self.render_file)):
            m.write(VTABLE+0x100+offset, API+token); m.hooks[API+token] = fn
        for offset, token, fn in ((0x28, 0x28, self.get_state), (0x20, 0x20, self.pause),
                                  (0x24, 0x24, self.stop), (0x34, 0x108, self.notify)):
            m.write(VTABLE+offset, API+token); m.hooks[API+token] = fn
        m.write(VTABLE+0x200+0x1C, API+0x50); m.hooks[API+0x50] = self.mute
        m.write(0x2F1E0+delta, API+0x10C); m.hooks[API+0x10C] = self.create
        m.hooks.update({0x209E0+delta: self.lock, 0x209D0+delta: self.unlock,
                        0x12604+delta: self.inserted, 0x24B90+delta: self.valid_path})

    def acquire(self, m, off):
        ptr = self.pointers[off]
        self.refs[ptr] = self.refs.get(ptr, 0)+1
        self.acquisitions.append((off, ptr))
        m.write(OBJECT+off, ptr)

    def create(self, m):
        assert m.reg[4:8] == [0x2D2BC+self.delta, 0, 1, 0x2E32C+self.delta]
        assert m.read(m.reg[29]+0x10) == OBJECT+0x10
        assert not any(self.refs.values()), 'New graph before old references released'
        self.creations += 1
        if self.fail != 'create' or self.creator_output:
            self.acquire(m, 0x10)
        self.events.append(dict(api='CoCreateInstance', attempt=self.creations))
        self.clobber(m)
        return self.hr if self.fail == 'create' else 0

    def render_file(self, m):
        assert m.reg[4:7] == [self.pointers[0x10], FILE, 0]
        self.events.append(dict(api='RenderFile'))
        self.clobber(m)
        return self.hr if self.fail == 'render' else 0

    def query(self, m):
        graph, iid, output = m.reg[4:7]
        off = output-OBJECT
        assert graph == self.pointers[0x10] and off in OFFSETS
        stage = dict(zip(OFFSETS, STAGES[2:7]))[off]
        expected = dict(zip(OFFSETS, (0x2CBCC, 0x2CBEC, 0x2E25C, 0x2CC0C, 0x2CBFC)))
        assert iid == expected[off]+self.delta
        self.events.append(dict(api='QueryInterface', stage=stage))
        if self.fail == stage:
            m.write(output, 0)
        else:
            self.acquire(m, off)
        self.clobber(m)
        return self.hr if self.fail == stage else self.query_success

    def notify(self, m):
        assert m.reg[4:8] == [self.pointers[8], WINDOW, 0x8001, 0]
        self.notifications += 1
        self.events.append(dict(api='SetNotifyWindow'))
        self.clobber(m)
        return self.hr if self.fail == 'notify' else 0

    def release(self, m):
        ptr = m.reg[4]
        assert self.refs.get(ptr, 0) > 0, 'Release without an owned reference'
        self.released.append(ptr)
        self.refs[ptr] -= 1
        remaining = self.refs[ptr]
        self.events.append(dict(api='Release', pointer=hex(ptr), remaining=remaining))
        self.clobber(m)
        return remaining

    def mute(self, m):
        assert m.reg[4:6] == [self.pointers[0x14], (-10000)&0xFFFFFFFF]
        self.events.append(dict(api='Mute')); self.clobber(m); return 0

    def lock(self, m):
        assert self.lock_depth == 0
        self.lock_depth = 1; self.locks.append('lock')
        self.clobber(m); return 0

    def unlock(self, m):
        assert self.lock_depth == 1
        self.lock_depth = 0; self.locks.append('unlock')
        self.clobber(m); return 0

    def inserted(self, m):
        assert m.reg[4] == 0x80000002 and m.reg[7] == 0
        self.clobber(m); return 1

    def valid_path(self, m):
        assert m.reg[5] == FILE
        self.clobber(m); return 1

    def run_render(self):
        return call(self.vm, 0x11F78+self.delta, [OBJECT, FILE], limit=200000)

    def run_load(self, kind=1):
        return call(self.vm, 0x12264+self.delta, [OBJECT, FILE, kind], limit=200000)

    def live(self):
        return sum(self.refs.values())

    def record(self, label, result):
        # Preserve counts and both boundaries of long polling/retry traces;
        # publishing every identical iteration adds noise without new evidence.
        complete = len(self.events) <= 24
        trace = self.events.copy() if complete else self.events[:12]+self.events[-12:]
        return dict(name=label, result=result, live_references=self.live(),
                    slots=[self.vm.read(OBJECT+off) for off in (4, 8, 0xC, 0x10, 0x14, 0x18)],
                    acquisitions=len(self.acquisitions), releases=len(self.released),
                    graph_flag=self.vm.read(INSTANCE+0x28), creates=self.creations,
                    state_queries=self.index, notifications=self.notifications,
                    locks=self.locks.copy(), event_counts=dict(Counter(e['api'] for e in self.events)),
                    event_trace=trace, event_trace_complete=complete,
                    event_trace_omitted=len(self.events)-len(trace))


def structure(previous, candidate, recipe):
    assert hashlib.sha256(previous).hexdigest() == BASE_SHA
    a, b = pefile.PE(data=previous), pefile.PE(data=candidate)
    restored = bytearray(candidate)
    touched = set()
    for e in recipe['edits']:
        span = set(range(e['offset'], e['offset']+e['bytes']))
        assert not touched & span
        touched |= span
        assert candidate[e['offset']:e['offset']+e['bytes']] == bytes.fromhex(e['after_hex'])
        restored[e['offset']:e['offset']+e['bytes']] = bytes.fromhex(e['before_hex'])
    assert restored == previous
    assert [s.__pack__() for s in a.sections] == [s.__pack__() for s in b.sections]
    assert a.OPTIONAL_HEADER.AddressOfEntryPoint == b.OPTIONAL_HEADER.AddressOfEntryPoint
    imports = lambda p: [(d.dll, [(i.name, i.ordinal) for i in d.imports]) for d in p.DIRECTORY_ENTRY_IMPORT]
    assert imports(a) == imports(b)
    read_rows = lambda p: [struct.unpack_from('<5I', p.get_data(p.OPTIONAL_HEADER.DATA_DIRECTORY[3].VirtualAddress,
                                                             p.OPTIONAL_HEADER.DATA_DIRECTORY[3].Size), i)
                           for i in range(0, p.OPTIONAL_HEADER.DATA_DIRECTORY[3].Size, 20)]
    rows = read_rows(b)
    assert set(read_rows(a)).issubset(rows) and len(rows) == len(read_rows(a))+1
    for delta in (0x1000, 0x10000, 0x123000):
        q = pefile.PE(data=relocated(candidate, delta))
        assert read_rows(q) == [tuple(v+delta if v else 0 for v in row) for row in rows]
    # All previous helpers, caller gates and original acquisition body preserved.
    for lo, hi in ((0x11054, 0x1111C), (0x11FAC, 0x12248), (0x1224C, 0x12444),
                   (0x3C000, CLEANUP), (CLEANUP+CAPACITY, 0x41000)):
        assert a.get_data(lo-0x10000, hi-lo) == b.get_data(lo-0x10000, hi-lo)
    return dict(cases=1, exact_reversal=True, previous_helpers_preserved=True,
                sections_imports_entry_and_previous_pdata_rows_preserved=True,
                original_acquisition_body_and_epilogue_restores_preserved=True,
                three_alternate_load_bases=True)


def verify(previous, candidate, recipe):
    traces = []
    # Original instruction evidence: every post-create failure retains references.
    for stage in STAGES[1:]:
        g = Initialization(previous, fail=stage)
        result = g.run_render()
        assert result == (0 if stage == 'render' else E_FAIL)
        assert g.live() > 0 and not g.released and g.vm.read(INSTANCE+0x28) == 1
        traces.append(g.record('original retained acquisition: '+stage, result))
    for delta in (0, 0x1000, 0x10000, 0x123000):
        raw = relocated(candidate, delta) if delta else candidate
        for stage, hr, alias in itertools.product(STAGES, (E_FAIL, 0x80004002, 0x8007000E), (False, True)):
            g = Initialization(raw, fail=stage, hr=hr, alias=alias, delta=delta)
            result = g.run_render()
            assert result == (0 if stage in ('create', 'render') else hr)
            assert not g.live() and data(g.vm, OBJECT+4, 0x18) == bytes(0x18)
            assert len(g.released) == len(g.acquisitions)
            assert g.vm.read(INSTANCE+0x28) == 0
            g.fail = None
            assert g.run_render() == 1 and g.live() == 6
            assert g.vm.read(INSTANCE+0x28) == 1
            assert g.run('teardown') == 1 and not g.live()
            assert len(g.released) == len(g.acquisitions)
            traces.append(g.record(f'failure + retry {stage} hr={hr:x} alias={alias} base+{delta:x}', result))
        for stage in STAGES[3:]:
            for response in (((E_FAIL, 0),), ((0x40237, 0),)):
                g = Initialization(raw, fail=stage, delta=delta, samples=response)
                result = g.run_render()
                assert result == E_FAIL and not g.released and g.live() > 0
                held = data(g.vm, OBJECT+4, 0x18)
                creates, queries = g.creations, g.index
                assert g.run_render() == 0 and g.creations == creates and not g.released
                assert data(g.vm, OBJECT+4, 0x18) == held
                # Exactly one additional polling attempt, not another from the
                # RenderFile failure epilogue after replacement was refused.
                assert g.index-queries == (1 if response[0][0] == E_FAIL else 1000)
                g.samples, g.fail = [(0, 0)], None
                assert g.run_render() == 1 and g.live() == 6
                assert g.run('teardown') == 1 and not g.live()
                traces.append(g.record(f'cleanup blocked then recovered {stage} base+{delta:x}', result))
        for alias, hr in itertools.product((False, True), (0, 1)):
            g = Initialization(raw, alias=alias, query_success=hr, delta=delta)
            assert g.run_render() == 1 and g.live() == 6 and not g.released and not g.index
            assert g.vm.read(OBJECT+0x24) == 0 and g.notifications == 1
            traces.append(g.record(f'success unchanged alias={alias} hr={hr} base+{delta:x}', 1))
        for stage, kind in itertools.product(STAGES+(None,), (1, 2)):
            g = Initialization(raw, fail=stage, delta=delta)
            result = g.run_load(kind)
            assert result == (1 if stage is None else 3)
            assert g.vm.read(0x2F96C+delta) == int(stage is None)
            assert g.locks == ['lock', 'unlock'] and not g.lock_depth
            assert g.live() == (6 if stage is None else 0)
            traces.append(g.record(f'LoadFile kind={kind} fail={stage} base+{delta:x}', result))
        for kind in (0, 3, 0xFFFFFFFF):
            g = Initialization(raw, delta=delta)
            assert g.run_load(kind) == 4 and not g.creations and not g.live()
            assert g.locks == ['lock', 'unlock'] and not g.lock_depth
            traces.append(g.record(f'invalid LoadFile kind={kind} base+{delta:x}', 4))
        g = Initialization(raw, fail='create', creator_output=False, delta=delta)
        assert g.run_render() == 0 and not g.live() and not g.released
        traces.append(g.record(f'creator failure null output base+{delta:x}', 0))
        g = Initialization(raw, delta=delta, samples=((0, 2), (0, 1), (0, 0)))
        assert g.run_render() == 1 and not g.index and not g.released
        g.vm.write(OBJECT+0x24, 2)
        assert g.run_render() == 1 and g.live() == 6 and len(g.released) == 6
        assert g.index == 3 and g.summary()['commands'] == ['Pause', 'Stop']
        g.fail = 'notify'
        assert g.run_render() == E_FAIL and not g.live()
        g.fail = None
        assert g.run_render() == 1 and g.live() == 6
        traces.append(g.record(f'running graph replacement then failed/new track base+{delta:x}', 1))
        for kind in (1, 2):
            g = Initialization(raw, fail='notify', delta=delta, samples=((E_FAIL, 0),))
            assert g.run_load(kind) == 3 and g.live() == 6 and not g.released
            assert g.vm.read(0x2F96C+delta) == 0 and not g.lock_depth
            g.fail, g.samples = None, [(0, 0)]
            assert g.run_load(kind) == 1 and g.live() == 6
            assert g.vm.read(0x2F96C+delta) == 1 and not g.lock_depth
            assert len(g.released) == 6 and g.locks == ['lock', 'unlock']*2
            traces.append(g.record(f'LoadFile retry with readiness cleared kind={kind} base+{delta:x}', 1))
        g = Initialization(raw, delta=delta, alias=True)
        for stage in STAGES*4:
            g.fail = stage
            assert g.run_render() == (0 if stage in ('create', 'render') else E_FAIL)
            assert not g.live() and len(g.released) == len(g.acquisitions)
        g.fail = None
        assert g.run_render() == 1 and g.live() == 6
        traces.append(g.record(f'32 repeated failures then success base+{delta:x}', 1))
    checks = structure(previous, candidate, recipe)
    return dict(cases=len(traces)+checks['cases'], traces=traces, structure=checks,
                limits='Actual MIPS paths with simulated COM/registry/locks/clocks; not native or hardware testing.')
