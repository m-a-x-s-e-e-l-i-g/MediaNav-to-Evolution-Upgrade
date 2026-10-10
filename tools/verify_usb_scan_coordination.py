"""Trace original USB worker activation and controlled shared-state overlap.

Actual MIPS instructions with separate register/stack contexts and shared memory.
Events, timers, files, enumeration and scheduling remain explicit fixtures.
"""
import argparse
import hashlib
import json
from pathlib import Path

from inspect_bt_pairing import put
from inspect_wave_queue import STOP
from verify_usb_catalog_recovery import Scan, USB, SYSTEM, CATALOG, DIRECTORIES
from verify_usb_input_safety import relocated

SHA = 'a9f0bf2266932d5574abd67c0a6444a27ada6e80064d6ee334db93e14e6d7ec8'
BASE_SHA = 'cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c'
NORMAL, BOOT = 0x7001, 0x7002
RANGES = ((0x22b40, 0x22c7c), (0x22f80, 0x22fac), (0x22fac, 0x22fd8), (0x229b8, 0x22a40),
          (0x20a38, 0x20eac), (0x1fc8c, 0x1fcd0), (0x1eac4, 0x1ec88),
          (0x1fd6c, 0x20340), (0x1db80, 0x1dc00), (0x12af0, 0x12b2c),
          (0x12e1c, 0x12e80), (0x12e80, 0x12eb4))


class ThreadExit(Exception):
    pass


class Fixture:
    def __init__(self, raw, delta):
        self.raw, self.delta = raw, delta
        self.mem = Scan(raw, delta).m.mem
        self.events, self.timers, self.trace = set(), set(), []
        self.waits = []
        self.control = self.machine('control')
        self.control.write(SYSTEM+0x4c, USB)
        self.control.write(SYSTEM+0x3c, 0x6666)
        self.control.write(USB+0x9a358, 0)
        for at, value in ((0x34f3c, NORMAL), (0x34f44, BOOT), (0x34f34, 0), (0x34f38, 0)):
            self.control.write(at+delta, value)

    def machine(self, name):
        s = Scan(self.raw, self.delta)
        m, d = s.m, self.delta
        m.mem = self.mem
        m.ranges.extend((a+d, b+d) for a, b in RANGES)
        m.hooks.update({a+d: fn for a, fn in (
            (0x253dc, self.zero), (0x1ad84, self.artwork_reset),
            (0x13630, lambda v: 1), (0x3f800, lambda v: 0), (0x1be50, lambda v: 0),
            (0x2517c, self.kill_timer), (0x251ec, self.set_timer),
            (0x2522c, self.signal), (0x2524c, self.exit_thread),
            (0x12eb4, lambda v: 0), (0x12ebc, lambda v: 0))})
        api = 0xf1000000
        m.write(0x2f048+d, api)
        m.hooks[api] = self.wait
        m.write(0x2f00c+d, api+4)
        m.hooks[api+4] = lambda v: 100
        m.name = name
        return m

    def zero(self, m):
        at, fill, size = m.reg[4:7]
        assert fill == 0
        assert size in (4, 0x20a, 0x40e, 0x2712, 0x977fc, 0x284880, 0x298100), hex(size)
        # Full call lengths checked; materialize only prefixes of large buffers.
        n = 0x440 if size in (0x284880, 0x298100) else 0x40 if size == 0x977fc else size
        put(m, at, bytes(n))
        self.trace.append(dict(context=m.name, api='memset', at=hex(at), bytes=size))
        Scan.clobber(m)
        return at

    def artwork_reset(self, m):
        assert m.reg[4] == USB+8
        self.trace.append(dict(context=m.name, fixture='artwork reset'))
        Scan.clobber(m)
        return 0

    def kill_timer(self, m):
        assert m.reg[4] == 0x6666
        self.timers.discard(m.reg[5])
        Scan.clobber(m)
        return 1

    def set_timer(self, m):
        assert m.reg[4] == 0x6666 and m.reg[7] == 0
        assert m.reg[5:7] == [0x3eb, 1000]
        self.timers.add(m.reg[5])
        self.trace.append(dict(context=m.name, api='SetTimer', timer=m.reg[5], interval=m.reg[6]))
        Scan.clobber(m)
        return 0x3eb

    def signal(self, m):
        assert m.reg[4] in (NORMAL, BOOT) and m.reg[5] == 3
        self.events.add(m.reg[4])
        self.trace.append(dict(context=m.name, api='EventModify', event=m.reg[4]))
        Scan.clobber(m)
        return 1

    def wait(self, m):
        handle = m.reg[4]
        assert handle in (NORMAL, BOOT) and m.reg[5] == 0xffffffff
        assert handle in self.events, 'Fixture never invents a wake without a preceding signal'
        self.events.remove(handle)
        self.waits.append(dict(context=m.name, event=handle))
        Scan.clobber(m)
        return 0

    @staticmethod
    def exit_thread(m):
        assert m.reg[4] == 0
        raise ThreadExit

    @staticmethod
    def prime(m, stack, args, extra=()):
        saved = {r: 0x12340000+r for r in (*range(16, 24), 28, 30)}
        for r, value in saved.items(): m.reg[r] = value
        m.reg[4:8] = list(args)+[0]*(4-len(args))
        m.reg[29], m.reg[31] = stack, STOP
        for i, value in enumerate(extra): m.write(stack+0x10+4*i, value)
        m.write(stack-0x600, 0xa55aa55a); m.write(stack+0x30, 0xa55aa55a)
        return saved

    def invoke(self, entry, args, extra=()):
        m, stack = self.control, 0x68200000
        saved = self.prime(m, stack, args, extra)
        m.run(entry+self.delta, {STOP})
        assert m.reg[29] == stack and m.reg[31] == STOP
        assert all(m.reg[r] == value for r, value in saved.items())
        assert m.read(stack-0x600) == m.read(stack+0x30) == 0xa55aa55a
        return m.reg[2]

    def snapshot(self):
        m = self.control
        return dict(busy=m.read(USB+4), boot_active=m.read(USB+0x9a358),
                    canceled=m.read(SYSTEM+0x18), directories=m.read(CATALOG+0x1c),
                    root_parent=m.read(DIRECTORIES+0x20c, 2),
                    events=sorted(self.events), timers=sorted(self.timers))

    def normal_scan(self, paused_boot=None):
        assert self.invoke(0x229b8, [0, 0, 0x8002, 1], [0]) == 1
        intermediate = self.snapshot()
        assert intermediate['directories'] == intermediate['root_parent'] == intermediate['busy'] == 0
        assert intermediate['canceled'] == 0 and self.timers == {0x3eb}
        self.invoke(0x1eac4, [USB])
        assert self.events == {NORMAL} and not self.timers
        normal = self.machine('normal')
        self.prime(normal, 0x68100000, [])
        normal.run(0x22b40+self.delta, {0x1ef48+self.delta})
        assert normal.reg[4:7] == [USB, 1, 0]
        normal.run(normal.pc, {0x1f02c+self.delta})
        if paused_boot is not None:
            assert paused_boot.pc == normal.pc == 0x1f02c+self.delta
        assert self.control.read(USB+4) == 1 and self.control.read(CATALOG+0x1c) == 1
        self.control.write(0x34f34+self.delta, 1)
        try: normal.run(normal.pc, {STOP})
        except ThreadExit: pass
        else: raise AssertionError('Normal worker did not reach ExitThread fixture')
        done = self.snapshot()
        assert done['busy'] == 0
        if paused_boot is not None: assert paused_boot.pc == 0x1f02c+self.delta
        assert normal.read(0x68100000-0x600) == normal.read(0x68100000+0x30) == 0xa55aa55a
        return intermediate, done


def schedule(raw, delta, resume, mode):
    f = Fixture(raw, delta)
    m = f.control
    m.write(SYSTEM+0x10, 0); m.write(SYSTEM+0xc, resume)
    # The actual message caller forwards device attach (a3=1, fifth argument=0).
    assert f.invoke(0x229b8, [0, 0, 0x8002, 1], [0]) == 1
    assert f.events == {BOOT} and m.read(SYSTEM+0x10) == 1
    boot = f.machine('boot')
    f.prime(boot, 0x68000000, [])
    boot.run(0x22bd8+delta, {0x1fd6c+delta})
    assert boot.reg[4:6] == [USB, resume]
    # Observe the native boot flag before the native reset erases it.
    boot.run(boot.pc, {0x1fdc0+delta})
    assert m.read(USB+0x9a358) == 1
    boot.run(boot.pc, {0x1f02c+delta})
    before = f.snapshot()
    assert before['busy'] == 1 and before['boot_active'] == 0
    assert before['directories'] == 1 and before['root_parent'] == 0xffff
    intermediate, normal_done = None, None
    if mode == 'overlap':
        intermediate, normal_done = f.normal_scan(boot)
    m.write(0x34f38+delta, 1)
    try: boot.run(boot.pc, {STOP})
    except ThreadExit: pass
    else: raise AssertionError('Boot worker did not reach ExitThread fixture')
    after = f.snapshot()
    assert after['busy'] == after['boot_active'] == 0
    assert boot.read(0x68000000-0x600) == boot.read(0x68000000+0x30) == 0xa55aa55a
    sequential = None
    if mode == 'sequential':
        reset, done = f.normal_scan()
        sequential = dict(after_attach=reset, after_normal=done)
    return dict(delta=hex(delta), resume=resume, mode=mode, before=before,
                after_attach=intermediate, normal_completed_while_boot_paused=normal_done,
                after_boot=after, sequential_control=sequential, waits=f.waits, calls=f.trace)


def verify(raw, baseline):
    assert hashlib.sha256(raw).hexdigest() == SHA, 'Expected exact PR40 catalog-recovery candidate'
    assert hashlib.sha256(baseline).hexdigest() == BASE_SHA, 'Expected exact MAX04 baseline'
    suites = {}
    for label, source in (('max04', baseline), ('pr40', raw)):
        traces = []
        for delta in (0, 0x1000, 0x10000, 0x123000):
            candidate = relocated(source, delta) if delta else source
            for resume in (0, 1):
                for mode in ('boot_only', 'overlap', 'sequential'):
                    traces.append(schedule(candidate, delta, resume, mode))
        suites[label] = traces
    assert suites['max04'] == suites['pr40'], 'Candidate changed the observed lifecycle behavior'
    return dict(candidate_sha256=SHA, baseline_sha256=BASE_SHA, cases=sum(map(len, suites.values())), suites=suites,
                native_executed=False, hardware_tested=False,
                limits=['Controlled instruction-boundary schedule, not the Windows CE scheduler or observed device ordering',
                        'Event, timer, file, enumeration, postprocess, notification, artwork reset and cookie APIs are fixtures',
                        'Real workers, message caller, attach handler, boot controller, catalog reset, scan root insertion and cleanup execute',
                        'Large clear lengths checked; only buffer prefixes materialized',
                        'Proves admitted overlap and lost busy state under the stated schedule, not its frequency on the unit'])


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--candidate', required=True, type=Path)
    p.add_argument('--baseline', required=True, type=Path)
    p.add_argument('--report', required=True, type=Path)
    args = p.parse_args()
    raw = args.candidate.read_bytes()
    baseline = args.baseline.read_bytes()
    report = verify(raw, baseline)
    assert args.candidate.read_bytes() == raw
    assert args.baseline.read_bytes() == baseline
    report['verifier_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_bytes((json.dumps(report, indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=report['cases'], candidate_sha256=SHA)))
