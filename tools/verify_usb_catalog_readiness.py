"""Trace partial USB catalogs in actual MIPS instructions, without patching them."""
import argparse
import hashlib
import json
from pathlib import Path

from inspect_bt_pairing import data, put
from verify_media_responsiveness import VM, call, parsed, COOKIE
from verify_usb_input_safety import relocated

SHA = '5f34249de2ec66a9cc3f22a6dc35e063eefc885faee58b3b12d8a5e56a29c234'
USB, SYSTEM, CATALOG = 0x41000000, 0x42000000, 0x43000000
SONGS, PLAYLIST, TEMP, DIRECTORIES = (0x51000000, 0x52000000, 0x53000000, 0x54000000)


class LowWrite(AssertionError):
    pass


class TraceVM(VM):
    def __init__(self, raw, ranges, delta):
        super().__init__(parsed(raw), [(a+delta, b+delta) for a, b in ranges])
        self.cancel_reads = 0

    def plain(self, word):
        if word >> 26 == 0 and word & 63 == 3:  # SRA, signed 32-bit arithmetic shift.
            rt, rd, shift = (word >> 16)&31, (word >> 11)&31, (word >> 6)&31
            value = self.reg[rt]
            if value & 0x80000000: value -= 0x100000000
            self.reg[rd] = (value >> shift) & 0xffffffff
            self.reg[0] = 0
        else:
            super().plain(word)

    def write(self, at, value, size=4):
        if at < 0x10000:
            raise LowWrite(f'write {hex(at)} at {hex(self.pc)}')
        super().write(at, value, size)

    def read(self, at, size=4):
        if at == SYSTEM+0x18:
            self.cancel_reads += 1
        return super().read(at, size)


def setup(raw, ranges, delta=0):
    m = TraceVM(raw, ranges, delta)
    for at, size in ((USB, 0x100), (SYSTEM, 0x80), (CATALOG, 0x275c),
                     (SONGS, 0x210), (PLAYLIST, 0x11b8), (TEMP, 0x440),
                     (DIRECTORIES, 0x440)):
        put(m, at, bytes(size))
    m.write(SYSTEM+0x48, CATALOG)
    m.write(CATALOG+0x18, SONGS)
    m.write(CATALOG+0x3c, PLAYLIST)
    m.write(CATALOG+0x38, DIRECTORIES)
    m.write(0x2fea0+delta, TEMP)
    m.write(0x2f960+delta, COOKIE)
    m.hooks[0x231a4+delta] = lambda v: SYSTEM
    return m


def scan(raw, delta, missing, cancel, ready, inserted=False, mode=(1, 0)):
    m = setup(raw, ((0x1ef48, 0x1f34c), (0x131c8, 0x132a0)), delta)
    for bit, at in enumerate((CATALOG+0x18, CATALOG+0x3c, 0x2fea0+delta, CATALOG+0x38)):
        if missing & (1 << bit):
            m.write(at, 0)
    m.write(SYSTEM+0x18, cancel); m.write(SYSTEM+0x38, ready)
    calls, notifications = [], []

    def zero(v):
        assert v.reg[5] == 0
        put(v, v.reg[4], bytes(v.reg[6]))
        return v.reg[4]

    def copy(v):
        assert v.text(v.reg[5]) == 'MD'
        put(v, v.reg[4], b'M\0D\0\0\0')
        return v.reg[4]

    def bounded_copy(v):
        assert v.reg[5] == 260 and v.text(v.reg[6]) == 'MD'
        calls.append(dict(api='root-copy', destination=v.reg[4], cancel_reads=m.cancel_reads))
        if not v.reg[4]:
            return 22  # Explicit secure-CRT EINVAL fixture, not native CRT behavior.
        put(v, v.reg[4], b'M\0D\0\0\0')
        return 0

    def enumerate_files(v):
        assert v.reg[4] == CATALOG and v.text(v.reg[5]) == 'MD' and v.reg[6:8] == [0, 0]
        calls.append(dict(api='enumeration', missing=missing))
        return 0

    def finish(v):
        assert v.reg[4] == CATALOG
        calls.append(dict(api='postprocess', missing=missing))
        return 0

    def notify(v):
        assert v.reg[4:8] == [5, 1, 9, 4]
        notifications.append(m.read(m.read(v.reg[29]+0x10)))
        return 1

    def cookie(v):
        assert v.reg[4] == COOKIE
        return 0

    m.hooks.update({0x253dc+delta: zero, 0x2599c+delta: copy,
                    0x25578+delta: bounded_copy, 0x23aac+delta: lambda v: 0,
                    0x2511c+delta: lambda v: 0, 0x25510+delta: cookie,
                    0x15620+delta: enumerate_files, 0x15a94+delta: finish,
                    0x12604+delta: lambda v: int(inserted),
                    0x12ebc+delta: lambda v: 0, 0x23580+delta: notify})
    failure = None
    try:
        call(m, 0x1ef48+delta, [USB, *mode])
    except LowWrite as e:
        failure = str(e)
    if missing & 8:
        assert failure == f'write 0x20c at {hex(0x13250+delta)}'
        assert m.cancel_reads == 0 and m.read(USB+4) == 1
        assert calls == [dict(api='root-copy', destination=0, cancel_reads=0)]
    else:
        assert failure is None and m.read(USB+4) == 0
        assert m.read(CATALOG+0x1c) == 1
        assert m.read(DIRECTORIES+0x20c, 2) == 0xffff
        assert [c['api'] for c in calls] == (['root-copy'] if cancel else
                                           ['root-copy', 'enumeration', 'postprocess'])
        expected = [0x2000 | (0x33 if mode[1] else 0x13)] if (inserted and ready and not cancel and any(mode)) else []
        assert notifications == expected
    return dict(delta=hex(delta), missing=missing, cancel=cancel, ready=ready,
                inserted=inserted, mode=mode, calls=calls, failure=failure,
                notifications=notifications, final_busy=m.read(USB+4),
                cancel_reads=m.cancel_reads, abi_checked=failure is None)


def playlist(raw, delta, present):
    m = setup(raw, ((0x1311c, 0x131c8),), delta)
    if not present: m.write(CATALOG+0x3c, 0)
    source = USB+0x20
    put(m, source, b'l\0i\0s\0t\0\0\0')
    copies = []
    def copy(v):
        assert v.reg[4:7] == [PLAYLIST, 260, source]
        copies.append('copy')
        put(v, PLAYLIST, data(v, source, 10))
        return 0
    m.hooks[0x25578+delta] = copy
    result = call(m, 0x1311c+delta, [CATALOG, 0, source, 7], [3])
    assert result == int(present) and len(copies) == int(present)
    if present:
        assert m.read(PLAYLIST+0x20c, 2) == 7 and m.read(PLAYLIST+0x20a, 2) == 3
    return dict(delta=hex(delta), present=present, result=result, copy_calls=len(copies))


def song(raw, delta, present):
    m = setup(raw, ((0x12ba8, 0x12bec),), delta)
    if not present: m.write(CATALOG+0x18, 0)
    failure = None
    try:
        call(m, 0x12ba8+delta, [CATALOG+8, 0, 7])
    except LowWrite as e:
        failure = str(e)
    assert failure == (None if present else f'write 0x208 at {hex(0x12bdc+delta)}')
    if present: assert m.read(SONGS+0x208, 2) == 7
    return dict(delta=hex(delta), present=present, failure=failure)


def flatten(raw, delta, present, depth):
    m = setup(raw, ((0x14390, 0x146ec),), delta)
    if not present: m.write(0x2fea0+delta, 0)
    m.write(DIRECTORIES+0x20e, 1, 2); m.write(DIRECTORIES+0x210, 1, 2)
    child = DIRECTORIES+0x220
    m.write(child+0x21c, 1); m.write(child+0x214, 1, 2); m.write(child+0x21a, 1, 2)
    copies = []
    def copy(v):
        assert v.reg[5:7] == [child, 520]
        copies.append(dict(destination=v.reg[4], bytes=v.reg[6]))
        if v.reg[4]: put(v, v.reg[4], data(v, child, 520))
        return v.reg[4]  # Null copy is suppressed to expose the following native store.
    m.write(0x2f008+delta, 0xf0010000)
    m.hooks.update({0xf0010000: lambda v: 0, 0x25668+delta: copy,
                    0x140b0+delta: lambda v: 0})
    failure, result = None, None
    try:
        result = call(m, 0x14390+delta, [CATALOG, 0, 0, depth])
    except LowWrite as e:
        failure = str(e)
    assert failure == (f'write 0x208 at {hex(0x1451c+delta)}' if depth == 3 and not present else None)
    if failure is None: assert result == 1
    assert len(copies) == int(depth == 3)
    return dict(delta=hex(delta), present=present, depth=depth, copies=copies, failure=failure, result=result)


def singleton(raw, delta, outer_fail):
    m = setup(raw, ((0x14db0, 0x14e1c),), delta)
    m.write(0x2fe9c+delta, 0)
    allocations, constructions = [], []
    def allocate(v):
        assert v.reg[4] == 0x275c
        allocations.append('allocate-object')
        return 0 if outer_fail and len(allocations) == 1 else CATALOG
    def construct(v):
        assert v.reg[4] == CATALOG
        constructions.append('construct-partial-catalog')
        m.write(CATALOG+0x38, 0)
        return CATALOG
    m.hooks.update({0x2538c+delta: allocate, 0x14b00+delta: construct})
    results = [call(m, 0x14db0+delta, []) for _ in range(3)]
    assert results == ([0, CATALOG, CATALOG] if outer_fail else [CATALOG]*3)
    assert len(allocations) == (2 if outer_fail else 1) and len(constructions) == 1
    assert m.read(CATALOG+0x38) == 0
    return dict(delta=hex(delta), first_object_allocation_fails=outer_fail,
                allocations=len(allocations), constructions=len(constructions), results=results,
                inner_constructor_is_explicit_fixture=True)


def allocator(raw, delta, external):
    m = setup(raw, ((0x12844, 0x129c8), (0x129c8, 0x12aa4)), delta)
    m.write(0x2f1e8+delta, 0x7777); m.write(0x2fe98+delta, 0)
    calls, frees = [], []
    outputs = [0, 0, SONGS]
    def ioctl(v):
        assert v.reg[4] == 0x7777 and v.reg[5] in (0x15, 0x16)
        if v.reg[5] == 0x15:
            assert v.reg[7] == 4 and v.read(v.reg[6]) == 528
            assert v.read(v.reg[29]+0x14) == 16
            pointer = outputs[len(calls)] if external else 0
            dest = v.read(v.reg[29]+0x10)
            v.write(dest, pointer); v.write(dest+4, pointer)
            calls.append('ioctl-allocate')
        else:
            assert external and v.read(v.reg[6]) == SONGS
            frees.append('ioctl-free')
        return 1
    def heap(v):
        assert v.reg[4] == 528
        if external:
            assert len(calls) <= 2
            return 0
        return outputs[len(calls)-1]
    def delete(v):
        assert not external and v.reg[4] == SONGS
        frees.append('heap-free')
        return 0
    m.write(0x2f03c+delta, 0xf0020000)
    m.hooks.update({0xf0020000: ioctl, 0x2538c+delta: heap, 0x2539c+delta: delete,
                    0x253dc+delta: lambda v: (put(v, v.reg[4], bytes(v.reg[6])) or v.reg[4]),
                    0x12540+delta: lambda v: 0, 0x127f4+delta: lambda v: 0})
    results = [call(m, 0x12844+delta, [528]) for _ in outputs]
    records = [(m.read(0x2fb78+delta+i*8), m.read(0x2fb7c+delta+i*8)) for i in range(3)]
    assert results == outputs and m.read(0x2fe98+delta) == 3
    assert records == [(0, 0), (0, 0), (SONGS, int(external))]
    call(m, 0x129c8+delta, [])
    assert frees == [('ioctl-free' if external else 'heap-free')]
    assert m.read(0x2fe98+delta) == 0
    assert all(m.read(0x2fb78+delta+i*8) == 0 for i in range(3))
    return dict(delta=hex(delta), successful_buffer_external=external,
                results=results, tracking_count_before_cleanup=3, records=records, frees=frees)


def verify(raw):
    assert hashlib.sha256(raw).hexdigest() == SHA, 'Expected exact PR38 candidate'
    groups = {name: [] for name in ('scan', 'playlist', 'song', 'flatten', 'singleton', 'allocator', 'opcode')}
    m = setup(raw, ())
    for value, expected in ((0, 0), (0x7fff0000, 0x7fff), (0x80000000, 0xffff8000), (0xffff0000, 0xffffffff)):
        m.reg[12] = value; m.plain(0x000c6403)
        assert m.reg[12] == expected
        groups['opcode'].append(dict(value=value, shifted=expected))
    for delta in (0, 0x1000, 0x10000, 0x123000):
        loaded = relocated(raw, delta) if delta else raw
        for missing in range(16):
            for cancel in (0, 1):
                for ready in (0, 1):
                    groups['scan'].append(scan(loaded, delta, missing, cancel, ready))
        for mode in ((1, 0), (0, 1), (1, 1)):
            groups['scan'].append(scan(loaded, delta, 0, 0, 1, True, mode))
        groups['scan'].append(scan(loaded, delta, 0, 0, 1, False, (0, 0)))
        for present in (False, True):
            groups['playlist'].append(playlist(loaded, delta, present))
            groups['song'].append(song(loaded, delta, present))
            for depth in (0, 3): groups['flatten'].append(flatten(loaded, delta, present, depth))
        for fail in (False, True): groups['singleton'].append(singleton(loaded, delta, fail))
        # Failed external allocation falls through to operator new. Only the successful
        # third allocation differs; failed heap results remain identical in both runs.
        for external in (False, True):
            groups['allocator'].append(allocator(loaded, delta, external))
    return dict(candidate_sha256=SHA, cases=sum(map(len, groups.values())), traces=groups,
                missing_mask_bits=dict(songs=1, playlists=2, temporary_directories=4, directories=8),
                native_executed=False, hardware_tested=False,
                limits=['Instruction interpreter with explicit CRT, allocation, driver, registry, scan and logging fixtures',
                        'Enumeration and postprocessing are dispatch fixtures; selected storage primitives execute separately',
                        'Null CRT returning EINVAL and null memcpy suppression expose subsequent native stores; no OS crash claim',
                        'Constructor inside singleton is a partial-object fixture; real constructor covered by PR38',
                        'No native scheduler, allocation-frequency, elapsed-time or device-memory measurements',
                        'No catalog allocation recovery implemented'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--candidate', required=True, type=Path)
    parser.add_argument('--report', required=True, type=Path)
    args = parser.parse_args()
    raw = args.candidate.read_bytes()
    source = Path(__file__).read_bytes()
    result = verify(raw)
    assert args.candidate.read_bytes() == raw
    assert Path(__file__).read_bytes() == source
    result['verifier_sha256'] = hashlib.sha256(source).hexdigest()
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'], sha256=SHA)))


if __name__ == '__main__':
    main()
