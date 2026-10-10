"""Execute required-storage recovery and native scan routing with API fixtures."""
import hashlib
import itertools
import struct
from types import FunctionType

from inspect_bt_pairing import data, put
from verify_media_responsiveness import parsed, call, COOKIE
from verify_usb_input_safety import relocated
import verify_usb_catalog_initialization as prior
import verify_usb_catalog_readiness as investigation
from patch_usb_catalog_recovery import BASE_SHA, GATE, ALLOCATE, COUNTERS, HELPERS

USB, SYSTEM, CATALOG = investigation.USB, investigation.SYSTEM, investigation.CATALOG
SONGS, PLAYLIST, TEMP, DIRECTORIES = (investigation.SONGS, investigation.PLAYLIST,
                                     investigation.TEMP, investigation.DIRECTORIES)


def structure(previous, candidate, recipe):
    assert hashlib.sha256(previous).hexdigest() == BASE_SHA == recipe['base_sha256']
    assert hashlib.sha256(candidate).hexdigest() == recipe['sha256']
    restored = bytearray(candidate)
    for edit in recipe['edits']:
        off, size = edit['offset'], edit['bytes']
        assert candidate[off:off+size] == bytes.fromhex(edit['after_hex'])
        restored[off:off+size] = bytes.fromhex(edit['before_hex'])
    assert restored == previous
    a, b = parsed(previous), parsed(candidate)
    assert [(s.Name, s.VirtualAddress, s.SizeOfRawData, s.Characteristics) for s in a.sections] == [
            (s.Name, s.VirtualAddress, s.SizeOfRawData, s.Characteristics) for s in b.sections]
    assert a.OPTIONAL_HEADER.AddressOfEntryPoint == b.OPTIONAL_HEADER.AddressOfEntryPoint
    def rows(pe):
        d = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        return [struct.unpack_from('<5I', pe.get_data(d.VirtualAddress, d.Size), i) for i in range(0, d.Size, 20)]
    before, after = rows(a), rows(b)
    assert after == sorted(before+[tuple(r) for r in recipe['added_pdata_rows']])
    for at, n, _, _, prologue in HELPERS:
        assert a.get_data(at-0x10000, n) == bytes(n)
        assert any(r[0] == at and r[4] == at+prologue for r in after)
    assert a.get_data(COUNTERS-0x10000, 12) == b.get_data(COUNTERS-0x10000, 12) == bytes(12)
    assert a.get_section_by_rva(COUNTERS-0x10000).Characteristics & 0x80000000
    assert a.get_data(0x1ef48-0x10000, 0x8c) == b.get_data(0x1ef48-0x10000, 0x8c)
    assert a.get_data(0x1efdc-0x10000, 0x370) == b.get_data(0x1efdc-0x10000, 0x370)
    for delta in (0x1000, 0x10000, 0x123000):
        assert rows(parsed(relocated(candidate, delta))) == [tuple(v+delta if v else 0 for v in row) for row in after]
    return dict(cases=1, exact_reversal=True, previous_frames_and_exception_rows_preserved=True,
                original_scan_notification_and_cleanup_bytes_unchanged=True, writable_counters_initially_zero=True)


class Scan:
    def __init__(self, raw, delta=0, missing=0, fail=0, cancel=0, ready=1, high=False,
                 tracking=6, cancel_after=None):
        self.delta, self.missing, self.fail = delta, missing, fail
        self.addresses = [p+0x40000000 if high else p for p in (SONGS, DIRECTORIES, TEMP)]
        self.slots = (CATALOG+0x18, CATALOG+0x38, 0x2fea0+delta)
        self.sizes = (0x284880, 0x298100, 0x298100)
        self.bits = (1, 8, 4)
        self.cancel_after = cancel_after
        self.allocations, self.clears, self.notifications, self.dispatch, self.copies = [], [], [], [], []
        self.m = investigation.setup(raw, ((0x1ef48, 0x1f34c), (0x131c8, 0x132a0)), delta)
        m = self.m
        m.ranges.extend((at+delta, at+n+delta) for at, n, *_ in HELPERS)
        for i, slot in enumerate(self.slots):
            put(m, self.addresses[i], bytes(0x440))
            m.write(slot, 0 if missing & self.bits[i] else self.addresses[i])
            m.write(COUNTERS+delta+i*4, 0)
        if missing & 2: m.write(CATALOG+0x3c, 0)
        m.write(SYSTEM+0x18, cancel); m.write(SYSTEM+0x38, ready)
        m.write(0x2fe98+delta, tracking)
        m.write(CATALOG-4, 0x13579bdf); m.write(CATALOG+0x275c, 0x2468ace0)
        m.hooks.update({0x12844+delta: self.allocate, 0x253dc+delta: self.zero,
                        0x2599c+delta: self.copy, 0x25578+delta: self.bounded_copy,
                        0x15620+delta: self.enumerate, 0x15a94+delta: self.finish,
                        0x23aac+delta: self.log, 0x2511c+delta: self.log,
                        0x25510+delta: self.cookie, 0x12604+delta: self.no_device,
                        0x23580+delta: self.notify})

    @staticmethod
    def clobber(m):
        for r in (*range(3, 16), 24, 25): m.reg[r] = 0xdead0000+r

    def allocate(self, m):
        i = self.slots.index(m.reg[16])
        assert m.reg[4] == self.sizes[i] and m.read(self.slots[i]) == 0
        count = m.read(0x2fe98+self.delta)
        assert count < 100
        m.write(0x2fe98+self.delta, count+1)  # Actual allocator accounting established by PR39.
        pointer = 0 if self.fail & self.bits[i] else self.addresses[i]
        self.allocations.append(dict(buffer=i, bytes=m.reg[4], pointer=pointer))
        if pointer: put(m, pointer, bytes([0xa5])*0x440)
        if self.cancel_after == len(self.allocations): m.write(SYSTEM+0x18, 1)
        self.clobber(m)
        return pointer

    def zero(self, m):
        at, fill, size = m.reg[4:7]
        assert fill == 0
        if size in self.sizes:
            i = self.addresses.index(at)
            assert size == self.sizes[i]
            assert m.read(self.slots[i]) == 0, 'New buffer exposed before initialization'
            assert any(a['pointer'] == at for a in self.allocations)
            self.clears.append(dict(buffer=i, bytes=size))
            put(m, at, bytes(0x440))  # API length checked; only record prefixes materialized.
        else:
            assert size in (4, 0x40e)
            put(m, at, bytes(size))
        self.clobber(m)
        return at

    def copy(self, m):
        assert m.text(m.reg[5]) == 'MD'
        at = m.reg[4]; put(m, at, b'M\0D\0\0\0'); self.clobber(m)
        return at

    def bounded_copy(self, m):
        assert m.reg[4] == self.addresses[1] and m.reg[5] == 260 and m.text(m.reg[6]) == 'MD'
        put(m, m.reg[4], b'M\0D\0\0\0'); self.copies.append('root'); self.clobber(m)
        return 0

    def enumerate(self, m):
        assert m.reg[4] == CATALOG and m.text(m.reg[5]) == 'MD' and m.reg[6:8] == [0, 0]
        assert all(m.read(slot) != 0 for slot in self.slots)
        assert m.read(SYSTEM+0x18) == 0
        self.dispatch.append('enumeration'); self.clobber(m)
        return 0

    def finish(self, m):
        assert m.reg[4] == CATALOG
        self.dispatch.append('postprocess'); self.clobber(m)
        return 0

    def notify(self, m):
        assert m.reg[4:8] == [5, 1, 9, 4]
        self.notifications.append(m.read(m.read(m.reg[29]+0x10)))
        self.clobber(m)
        return 1

    def cookie(self, m):
        assert m.reg[4] == COOKIE
        self.clobber(m)
        return 0

    def log(self, m):
        self.clobber(m)
        return 0

    def no_device(self, m):
        self.clobber(m)
        return 0

    def run(self, mode=(1, 0)):
        before = tuple(map(len, (self.allocations, self.clears, self.notifications, self.dispatch, self.copies)))
        call(self.m, 0x1ef48+self.delta, [USB, *mode])
        assert self.m.read(USB+4) == 0
        assert self.m.read(CATALOG-4) == 0x13579bdf and self.m.read(CATALOG+0x275c) == 0x2468ace0
        assert self.m.read(CATALOG+0x3c) == (0 if self.missing & 2 else PLAYLIST)
        values = [v[n:] for v, n in zip((self.allocations, self.clears, self.notifications, self.dispatch, self.copies), before)]
        return dict(allocations=values[0], clears=values[1], notifications=values[2], dispatch=values[3], root_copies=len(values[4]),
                    pointers=[self.m.read(slot) for slot in self.slots],
                    attempts=[self.m.read(COUNTERS+self.delta+i*4) for i in range(3)],
                    tracking_count=self.m.read(0x2fe98+self.delta), final_busy=0, abi_and_canaries_checked=True)


def verify(previous, candidate, recipe):
    checks, traces = structure(previous, candidate, recipe), []
    # Preserve the original low-store reproducer, rather than asserting only the fix.
    original = investigation.scan(previous, 0, 8, 1, 0)
    for delta in (0, 0x1000, 0x10000, 0x123000):
        raw = relocated(candidate, delta) if delta else candidate
        old = relocated(previous, delta) if delta else previous
        for mode, ready, high in itertools.product(((0, 0), (1, 0), (0, 1), (1, 1)), (0, 1), (False, True)):
            a, b = Scan(old, delta, ready=ready, high=high), Scan(raw, delta, ready=ready, high=high)
            assert a.run(mode) == b.run(mode)
            assert data(a.m, CATALOG, 0x275c) == data(b.m, CATALOG, 0x275c)
            traces.append(dict(delta=hex(delta), healthy_parity=True, mode=mode, ready=ready, high=high))
        for missing, fail, cancel, ready, high in itertools.product(range(16), (0, 1, 4, 8, 13), (0, 1), (0, 1), (False, True)):
            s = Scan(raw, delta, missing, fail, cancel, ready, high)
            a = s.run()
            needed = missing & 13
            successful = not (needed & fail)
            assert len(a['allocations']) == (0 if cancel else needed.bit_count())
            assert len(a['clears']) == (0 if cancel else (needed & ~fail).bit_count())
            assert bool(a['dispatch']) == bool(not cancel and successful)
            assert a['root_copies'] == int(not cancel and successful)
            assert a['notifications'] == ([0x2013] if not cancel and not successful and ready else [])
            assert all(x <= 1 for x in a['attempts'])
            traces.append(dict(delta=hex(delta), missing=missing, fail=fail, cancel=cancel, ready=ready, high=high, result=a))
        for mode in ((0, 0), (0, 1), (1, 1)):
            s = Scan(raw, delta, missing=13, fail=13)
            a = s.run(mode)
            assert not a['dispatch'] and a['notifications'] == ([0x2033] if any(mode) else [])
            traces.append(dict(delta=hex(delta), mode=mode, exhausted_response=a))
        for missing in range(16):
            s = Scan(raw, delta, missing=missing, fail=13)
            runs = [s.run() for _ in range(4)]
            needed = missing & 13
            assert [len(r['allocations']) for r in runs] == [needed.bit_count(), needed.bit_count(), 0, 0]
            assert runs[-1]['attempts'] == [2 if missing & bit else 0 for bit in s.bits]
            traces.append(dict(delta=hex(delta), missing=missing, retry_exhaustion=runs))
            s = Scan(raw, delta, missing=missing, fail=13)
            a = s.run(); s.fail = 0; b = s.run()
            assert b['dispatch'] == ['enumeration', 'postprocess']
            assert len(b['allocations']) == needed.bit_count()
            c = s.run()
            assert not c['allocations'] and not c['clears']
            traces.append(dict(delta=hex(delta), missing=missing, retry_then_success=[a, b, c]))
        for count in (98, 99, 100, 101, 0xffffffff):
            s = Scan(raw, delta, missing=13, tracking=count)
            a = s.run()
            assert len(a['allocations']) == (max(0, 100-count) if count < 100 else 0)
            assert not a['dispatch'] and a['tracking_count'] == max(count, 100)
            traces.append(dict(delta=hex(delta), tracking_limit=count, result=a))
        for cancel_after in (1, 2, 3):
            s = Scan(raw, delta, missing=13, cancel_after=cancel_after)
            a = s.run()
            assert len(a['allocations']) == cancel_after and not a['dispatch'] and not a['notifications']
            s.m.write(SYSTEM+0x18, 0); s.cancel_after = None
            b = s.run()
            assert len(b['allocations']) == 3-cancel_after and b['dispatch'] == ['enumeration', 'postprocess']
            traces.append(dict(delta=hex(delta), cancellation_between_buffers=[a, b]))
        s = Scan(raw, delta, missing=13)
        s.run()
        s.m.ranges.append((0x14390+delta, 0x146ec+delta))
        flatten = FunctionType(investigation.flatten.__code__,
                    dict(investigation.flatten.__globals__, setup=lambda *args: s.m), 'flatten_recovered_catalog')
        result = flatten(raw, delta, True, 3)
        assert result['failure'] is None and result['result'] == 1
        traces.append(dict(delta=hex(delta), deep_folder_after_recovery=result))
    return dict(cases=checks['cases']+1+len(traces), structure=checks, original_null_write=original, traces=traces,
                native_executed=False, hardware_tested=False,
                limits=['Actual recovery helpers, root insertion, existing notification and busy-field cleanup instructions',
                        'Allocator, memset, CRT, registry, enumeration, postprocessing, logs and cookie checks are explicit fixtures',
                        'Large clear lengths are checked; only record prefixes are materialized',
                        'No native concurrency, driver, loader/unwind, UI delivery, speed or memory measurements'])


def retained_functions(intermediate, recipe):
    def cumulative(previous, candidate, combined):
        a = prior.structure(previous, intermediate, combined['previous_catalog_recipe'])
        b = structure(intermediate, candidate, recipe)
        return dict(cases=a['cases']+b['cases'], stages=[a, b])
    verifier = FunctionType(prior.verify.__code__, dict(prior.verify.__globals__, structure=cumulative), 'retained_catalog_initialization')
    stages = FunctionType(prior.retained_functions.__code__, dict(prior.retained_functions.__globals__, structure=cumulative), 'retained_recovery_stages')
    return verifier, stages
