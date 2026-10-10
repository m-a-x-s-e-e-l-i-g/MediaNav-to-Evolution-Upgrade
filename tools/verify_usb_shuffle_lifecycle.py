"""Trace the current shuffle worker publishing across an actual USB reset.

Separate MIPS contexts share memory. Folder access, RNG, scheduling and status
delivery are fixtures; the builder, reset and publication instructions execute.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random

from inspect_bt_pairing import put
from inspect_wave_queue import STOP
from patch_wma_shuffle import BUILD, GATE, YIELD, WRAP, READY
from verify_media_responsiveness import parsed
from verify_usb_input_safety import relocated
from verify_usb_catalog_recovery import Scan, USB, SYSTEM
from verify_usb_scan_coordination import Fixture as Previous, SHA, BASE_SHA, ThreadExit

PLAY, SHUFFLE = USB+8, 0x7003
EXTRA = ((0x22a8c, 0x22b40), (0x22f54, 0x22f80), (0x1dd94, 0x1ddb0),
         (0x1ddb0, 0x1ddcc), (0x19ae0, 0x19af8), (0x1b5b0, 0x1b670),
         (0x198e4, 0x19ae0), (0x1ad84, 0x1ae54), (BUILD, BUILD+0x600),
         (GATE, GATE+0x180), (YIELD, YIELD+0x80), (WRAP, WRAP+0x180),
         (READY, READY+0x180))


class Fixture(Previous):
    def __init__(self, raw, delta):
        self.rng = random.Random(17)
        self.sleeps, self.publications = [], []
        super().__init__(raw, delta)
        m = self.control
        put(m, USB, bytes(0x3000))
        put(m, 0x30108+delta, bytes([0xa5])*20000)
        m.write(0x30104+delta, 0xa55aa55a); m.write(0x34f28+delta, 0xa55aa55a)
        m.write(0x34f40+delta, SHUFFLE); m.write(0x34f30+delta, 0)
        m.write(SYSTEM+0x40, 0x6666)

    def machine(self, name):
        m = super().machine(name)
        d = self.delta
        m.ranges.extend((a+d, b+d) for a, b in EXTRA)
        del m.hooks[0x1ad84+d]  # Execute the complete reset, including shuffle fields.
        m.hooks.update({a+d: fn for a, fn in (
            (0x132fc, lambda v: 0), (0x12f10, lambda v: 0),
            (0x12f48, lambda v: 4), (0x14720, lambda v: 0),
            (0x2598c, self.random), (0x24094, self.publish))})
        api = 0xf1000008
        m.write(0x2f008+d, api); m.hooks[api] = self.sleep
        return m

    def zero(self, m):
        if m.reg[6] == 0xc6c:
            assert m.reg[4:6] == [PLAY+0xe64, 0]
            put(m, m.reg[4], bytes(0xc6c))
            self.trace.append(dict(context=m.name, api='memset', at=hex(m.reg[4]), bytes=0xc6c))
            at = m.reg[4]; Scan.clobber(m); return at
        return super().zero(m)

    def signal(self, m):
        if m.reg[4] == SHUFFLE:
            assert m.reg[5] == 3
            self.events.add(SHUFFLE)
            self.trace.append(dict(context=m.name, api='EventModify', event=SHUFFLE))
            Scan.clobber(m); return 1
        return super().signal(m)

    def wait(self, m):
        if m.reg[4] == SHUFFLE:
            assert m.reg[5] == 0xffffffff and SHUFFLE in self.events
            self.events.remove(SHUFFLE)
            self.waits.append(dict(context=m.name, event=SHUFFLE))
            Scan.clobber(m); return 0
        return super().wait(m)

    def sleep(self, m):
        assert m.reg[4] in (0, 1)
        self.sleeps.append(m.reg[4]); Scan.clobber(m); return 0

    def random(self, m):
        m.write(m.reg[4], self.rng.getrandbits(32))
        Scan.clobber(m); return 0

    def publish(self, m):
        assert m.reg[4:8] == [0x6666, PLAY+0x1ad8, 0, 0xe56]
        self.publications.append(self.snapshot())
        Scan.clobber(m); return 1

    def snapshot(self):
        m = self.control
        return dict(count=m.read(PLAY+0xe4c), pointer=m.read(PLAY+0xe5c),
                    enabled=m.read(PLAY+0x291e), saved=m.read(PLAY+0x1ab4),
                    mode=m.read(PLAY+0x2938), canceled=m.read(SYSTEM+0x18),
                    pending=sorted(self.events))


def commit_points(raw):
    pe = parsed(raw)
    word = bytes.fromhex('4c0e14ae')  # sw s4, 0xe4c(s0), the final count publication.
    code = pe.get_data(BUILD-0x10000, 0x600)
    offsets = [i for i in range(0, len(code), 4) if code[i:i+4] == word]
    assert len(offsets) == 1
    at = BUILD+offsets[0]
    assert pe.get_data(at+4-0x10000, 4) == bytes.fromhex('5c0e12ae')
    wrapper = pe.get_data(WRAP-0x10000, 0x180)
    modes = [i for i in range(0, len(wrapper), 4) if wrapper[i:i+4] == bytes.fromhex('382908ae')]
    assert len(modes) == 1
    check = int.from_bytes(pe.get_data(at-0x24-0x10000, 4), 'little')
    delta = pe.OPTIONAL_HEADER.ImageBase-0x10000
    assert check >> 26 == 3 and (check & 0x3ffffff)*4 == 0x231a4+delta
    return dict(before_final_check=at-0x24, before_count=at,
                between_count_pointer=at+4, before_mode=WRAP+modes[0])


def case(raw, delta, stage, reset_before_commit, reenable):
    f, pause = Fixture(raw, delta), commit_points(raw)[stage]+delta
    m = f.control
    f.invoke(0x1ddb0, [USB, 1]); f.invoke(0x22f54, [])
    worker = f.machine('shuffle')
    f.prime(worker, 0x68000000, [])
    worker.write(0x68000000-0x6000, 0xa55aa55a)
    worker.run(0x22a8c+delta, {pause}, limit=100000)
    before = f.snapshot()
    assert before['enabled'] == 1
    assert before['count'] == (0 if stage in ('before_final_check', 'before_count') else 4)
    assert before['pointer'] == (0x30108+delta if stage == 'before_mode' else 0)
    if stage != 'before_mode': assert worker.reg[20] == 4
    cached_order = [m.read(0x30108+delta+i*4) for i in range(4)]
    reset_state = None
    if reset_before_commit:
        f.invoke(0x1db80, [USB]); f.invoke(0x12e80, [m.read(SYSTEM+0x48)])
        reset_state = f.snapshot()
        assert reset_state['enabled'] == reset_state['count'] == reset_state['pointer'] == 0
        if reenable:
            f.invoke(0x1ddb0, [USB, 1]); f.invoke(0x22f54, [])
    worker.run(worker.pc, {0x22b0c+delta}, limit=100000)
    committed = f.snapshot()
    rejected = reset_before_commit and not reenable and stage == 'before_final_check'
    expected_count = 0 if rejected or reset_before_commit and stage in ('between_count_pointer', 'before_mode') else 4
    expected_pointer = 0 if rejected or reset_before_commit and stage == 'before_mode' else 0x30108+delta
    assert committed['count'] == expected_count and committed['pointer'] == expected_pointer
    assert committed['mode'] == committed['saved'] == int(not rejected)
    assert committed['enabled'] == int(not reset_before_commit or reenable)
    ready = f.invoke(READY, [PLAY])
    assert ready == int(bool(expected_count and expected_pointer and committed['enabled']))
    order = [m.read(0x30108+delta+i*4) for i in range(4)]
    assert order == cached_order
    assert order[0] == 0 and sorted(order) == list(range(4))
    assert m.read(0x30104+delta) == m.read(0x34f28+delta) == 0xa55aa55a
    if not reset_before_commit:
        f.invoke(0x1db80, [USB]); f.invoke(0x12e80, [m.read(SYSTEM+0x48)])
        assert f.snapshot()['count'] == f.snapshot()['pointer'] == f.snapshot()['enabled'] == 0
    m.write(0x34f30+delta, 1)
    try: worker.run(worker.pc, {STOP})
    except ThreadExit: pass
    else: raise AssertionError('Shuffle worker did not reach the ExitThread fixture')
    assert worker.read(0x68000000-0x6000) == worker.read(0x68000000+0x30) == 0xa55aa55a
    return dict(delta=hex(delta), stage=stage, reset_before_commit=reset_before_commit, reenable=reenable,
                pause=hex(pause), before=before, after_reset=reset_state,
                cached_order=cached_order, committed=committed, ready=ready, after=f.snapshot(), order=order, waits=f.waits,
                sleeps=f.sleeps, status_publications=f.publications, calls=f.trace)


def verify(raw, baseline):
    assert hashlib.sha256(raw).hexdigest() == SHA
    assert hashlib.sha256(baseline).hexdigest() == BASE_SHA
    suites = {}
    for label, source in (('max04', baseline), ('pr40', raw)):
        traces = []
        for delta in (0, 0x1000, 0x10000, 0x123000):
            moved = relocated(source, delta) if delta else source
            for stage in ('before_final_check', 'before_count', 'between_count_pointer', 'before_mode'):
                for reset, reenable in ((False, False), (True, False), (True, True)):
                    traces.append(case(moved, delta, stage, reset, reenable))
        suites[label] = traces
    assert suites['max04'] == suites['pr40']
    return dict(candidate_sha256=SHA, baseline_sha256=BASE_SHA, cases=sum(map(len, suites.values())), suites=suites,
                native_executed=False, hardware_tested=False,
                limits=['Controlled instruction-boundary schedule, not observed Windows CE scheduling',
                        'One four-track folder and its getters/iterator are fixtures; no filesystem or full IPC dispatcher',
                        'Actual shuffle worker, rewritten builder/pool, readiness, USB/artwork/catalog resets and publication execute',
                        'Timer/event/thread, RNG, status delivery and cookie operations remain fixtures',
                        'Large buffer-clear lengths checked; only prefixes materialized',
                        'Second shuffle event remains pending at the observation point; this is a stale-publication window, not a claim that queued rebuilding never runs'])


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--candidate', required=True, type=Path)
    p.add_argument('--baseline', required=True, type=Path)
    p.add_argument('--report', required=True, type=Path)
    args = p.parse_args()
    raw, baseline = args.candidate.read_bytes(), args.baseline.read_bytes()
    result = verify(raw, baseline)
    assert args.candidate.read_bytes() == raw and args.baseline.read_bytes() == baseline
    result['verifier_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_bytes((json.dumps(result, indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=result['cases'], candidate_sha256=SHA)))
