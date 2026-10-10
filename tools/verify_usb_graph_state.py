"""Execute original/candidate MIPS graph transitions with explicit COM/time fixtures.

No real graph, decoder, scheduling, device, audio or elapsed-time measurement.
"""
import argparse
import hashlib
import itertools
import json
from pathlib import Path
import struct

import pefile

from inspect_bt_pairing import put, data
from patch_usb_graph_state import BASE, BASE_SHA, POLL, TEARDOWN, RENDER_INIT, GATES, MAX_POLLS, TIMEOUT_MS, patch
from verify_media_responsiveness import VM, call
from verify_usb_input_safety import relocated
from inspect_wave_queue import STOP

ROOT = Path(__file__).resolve().parents[1]
OBJECT, CONTROL, AUDIO, INSTANCE = 0x45000000, 0x46000000, 0x47000000, 0x48000000
VTABLE, API = 0x49000000, 0xF0600000
ROUTINES = {"stop": 0x11568, "real_pause": 0x11790, "pause": 0x11918}
INTERMEDIATE, CANT_CUE, E_FAIL = 0x40237, 0x40268, 0x80004005
OLD_HELD_GATE = bytes.fromhex(
    '05004010000000000100193c4c14392708002003000000000200193c30db3927'
    '0800200300000000000000000000000000000000000000000000000000000000')


class InfiniteWait(Exception):
    pass


class Graph:
    """COM object/output and clock fixture, with adversarial caller-saved clobbers."""
    def __init__(self, raw, samples=((0, 0),), cached=2, delta=0, ready=True,
                 clock=0, sleep_ms=5, tick_step=0, control=True, audio=True,
                 action_hr=0, mute_hr=0, mutate=None, refuse_infinite=True):
        pe = pefile.PE(data=raw)
        self.vm = VM(pe, [(a+delta, b+delta) for a, b in (
            (0x11568, 0x11AB0), (0x11E7C, 0x12264),
            (0x11790, 0x11918), (0x11918, 0x11AB0),
            (POLL, POLL+0x600), (TEARDOWN, TEARDOWN+0x200),
            (RENDER_INIT, RENDER_INIT+0x100), (0x40900, 0x40A80), (0x20BE4, 0x20CB8),
            # Optional PR-27 cleanup: execute its actual bytes on cumulative builds.
            (0x40B00, 0x40C00))])
        self.vm.ranges.extend((at+delta, at+0x40+delta) for at, *_ in GATES)
        self.delta, self.clock = delta, clock
        self.samples, self.index = list(samples), 0
        self.sleep_ms, self.tick_step = sleep_ms, tick_step
        self.action_hr, self.mute_hr, self.mutate = action_hr, mute_hr, mutate
        self.refuse_infinite = refuse_infinite
        self.events, self.released, self.seeks, self.logs = [], [], [], []
        self.initialized = 0
        m = self.vm
        for at, n in ((OBJECT, 0x40), (CONTROL, 0x20), (AUDIO, 0x20),
                      (INSTANCE, 0x100), (VTABLE, 0x100)):
            put(m, at, bytes(n))
        m.write(CONTROL, VTABLE); m.write(AUDIO, VTABLE+0x40)
        m.write(OBJECT+4, CONTROL if control else 0)
        for n, off in enumerate((8, 0xC, 0x10, 0x18)):
            at = CONTROL + 0x100 + 0x20*n
            put(m, at, bytes(0x20)); m.write(at, VTABLE)
            m.write(OBJECT+off, at)
        m.write(OBJECT+0x14, AUDIO if audio else 0)
        m.write(OBJECT+0x24, cached); m.write(INSTANCE+0x28, 1)
        m.write(0x2F96C+delta, int(ready))
        for off, fn in ((0x28, self.get_state), (0x20, self.pause), (0x24, self.stop),
                        (8, self.release)):
            m.write(VTABLE+off, API+off); m.hooks[API+off] = fn
        m.write(VTABLE+0x40+0x1C, API+0x50); m.hooks[API+0x50] = self.mute
        m.write(VTABLE+0x40+8, API+8)
        for address, target, fn in ((0x2F008, API+0x60, self.sleep),
                                    (0x2F00C, API+0x64, self.tick)):
            m.write(address+delta, target); m.hooks[target] = fn
        m.hooks.update({0x2511C+delta: self.log, 0x23AAC+delta: self.log,
                        0x1111C+delta: self.seek, 0x231A4+delta: self.instance,
                        0x11054+delta: self.initialize})

    @staticmethod
    def clobber(m):
        for reg in (*range(3, 16), 24, 25):
            m.reg[reg] = 0xDEAD0000+reg

    def get_state(self, m):
        obj, timeout, out = m.reg[4:7]
        assert obj == CONTROL
        self.events.append(dict(api="GetState", timeout=timeout))
        if timeout == 0xFFFFFFFF and self.refuse_infinite:
            raise InfiniteWait("Original code supplied an infinite wait")
        hr, state = self.samples[min(self.index, len(self.samples)-1)]
        self.index += 1
        if state is not None:
            m.write(out, state & 0xFFFFFFFF)
        if self.mutate == "during_get":
            m.write(OBJECT+4, 0)
        self.clobber(m)
        return hr

    def pause(self, m):
        assert m.reg[4] == CONTROL
        self.events.append(dict(api="Pause")); self.clobber(m)
        return self.action_hr

    def stop(self, m):
        assert m.reg[4] == CONTROL
        self.events.append(dict(api="Stop")); self.clobber(m)
        return self.action_hr

    def mute(self, m):
        assert m.reg[4:6] == [AUDIO, (-10000) & 0xFFFFFFFF]
        self.events.append(dict(api="Mute"))
        if self.mutate == "after_mute":
            m.write(OBJECT+4, 0)
        self.clobber(m); return self.mute_hr

    def sleep(self, m):
        assert m.reg[4] == 5
        self.events.append(dict(api="Sleep", ms=m.reg[4]))
        self.clock = (self.clock+self.sleep_ms) & 0xFFFFFFFF
        self.clobber(m); return 0

    def tick(self, m):
        value = self.clock
        self.clock = (self.clock+self.tick_step) & 0xFFFFFFFF
        self.clobber(m); return value

    def log(self, m):
        self.logs.append(m.reg[4:8].copy()); self.clobber(m); return 0

    def seek(self, m):
        assert m.reg[4:6] == [OBJECT, 0]
        self.seeks.append(0); self.clobber(m); return 1

    def release(self, m):
        self.released.append(m.reg[4]); self.clobber(m); return 0

    def instance(self, m):
        self.clobber(m); return INSTANCE

    def initialize(self, m):
        assert m.reg[4] == OBJECT
        self.initialized += 1; self.clobber(m); return 1

    def run(self, name, reset=True):
        va = ROUTINES.get(name, {"teardown": 0x11E7C, "render": 0x11F78}.get(name))
        args = [OBJECT, int(reset)] if name == "stop" else [OBJECT]
        return call(self.vm, va+self.delta, args, limit=200000)

    def summary(self):
        return dict(cached=self.vm.read(OBJECT+0x24), calls=self.index,
                    commands=[e["api"] for e in self.events if e["api"] in ("Pause", "Stop")],
                    sleeps=sum(e["api"]=="Sleep" for e in self.events),
                    seeks=len(self.seeks), released=len(self.released), logs=len(self.logs))


def structure(original, candidate, recipe):
    a, b = pefile.PE(data=original), pefile.PE(data=candidate)
    assert hashlib.sha256(original).hexdigest() == BASE_SHA
    assert len(original) == len(candidate)
    assert [s.__pack__() for s in a.sections] == [s.__pack__() for s in b.sections]
    assert a.OPTIONAL_HEADER.AddressOfEntryPoint == b.OPTIONAL_HEADER.AddressOfEntryPoint
    imports = lambda p: [(d.dll, [(i.name, i.ordinal) for i in d.imports]) for d in p.DIRECTORY_ENTRY_IMPORT]
    assert imports(a) == imports(b)
    restored = bytearray(candidate)
    occupied = set()
    for row in recipe["edits"]:
        off, n = row["offset"], row["bytes"]
        span = set(range(off, off+n))
        assert not occupied & span
        occupied |= span
        assert candidate[off:off+n] == bytes.fromhex(row["after_hex"])
        restored[off:off+n] = bytes.fromhex(row["before_hex"])
    assert restored == original
    read_rows = lambda p: [struct.unpack_from("<5I", p.get_data(p.OPTIONAL_HEADER.DATA_DIRECTORY[3].VirtualAddress,
                                                             p.OPTIONAL_HEADER.DATA_DIRECTORY[3].Size), i)
                           for i in range(0, p.OPTIONAL_HEADER.DATA_DIRECTORY[3].Size, 20)]
    old_rows, rows = read_rows(a), read_rows(b)
    assert set(old_rows).issubset(rows) and len(rows) == len(old_rows)+len(recipe['added_pdata_rows'])
    assert all(x[1] <= y[0] for x, y in zip(rows, rows[1:]))
    owner = lambda at: next(row for row in rows if row[0] <= at < row[1])
    for gate, sites, success, failure, label in GATES:
        for site in sites:
            assert owner(site) == owner(failure), f'{label}: failure exit belongs to another function'
    for delta in (0x1000, 0x10000, 0x123000):
        q = pefile.PE(data=relocated(candidate, delta))
        assert read_rows(q) == [tuple(x+delta if x else 0 for x in row) for row in rows]
    # Existing function prologues/epilogues and previously shipped helpers stay intact.
    for lo, hi in ((0x11568, 0x11594), (0x1175C, 0x11790),
                   (0x11790, 0x117B4), (0x118EC, 0x11918),
                   (0x11918, 0x1193C), (0x11A84, 0x11AB0),
                   (0x3C000, POLL)):
        assert a.get_data(lo-BASE, hi-lo) == b.get_data(lo-BASE, hi-lo)
    return dict(cases=1,declared_edits_reverse_exactly=True,
                original_sections_imports_entry_and_pdata_rows_preserved=True,
                three_alternate_load_bases=True,previous_usb_helpers_unchanged=True)


def caller_failure_return(raw, site, delta=0):
    """Execute the original prologue, actual gate and cleanup through JR return.

    Supply the state at the gate; earlier caller work is not simulated as real.
    The window dispatcher owns a temporary buffer at this point.
    """
    g = Graph(raw, delta=delta)
    m = g.vm
    directory = m.pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows = [struct.unpack_from('<5I', m.pe.get_data(directory.VirtualAddress, directory.Size), i)
            for i in range(0, directory.Size, 20)]
    row = next(row for row in rows if row[0] <= site+delta < row[1])
    m.ranges.append((row[0], row[1]))
    saved = {r: 0x12340000+r for r in (*range(16, 24), 28, 30)}
    for r, value in saved.items(): m.reg[r] = value
    stack = 0x68000000
    m.reg[29], m.reg[31] = stack, STOP
    m.write(stack-0x2000, 0xA55AA55A); m.write(stack+0x40, 0xA55AA55A)
    m.run(row[0], {row[4]}, limit=1000)
    m.reg[2] = 0
    prologue = m.pe.get_data(row[0]-m.pe.OPTIONAL_HEADER.ImageBase, row[4]-row[0])
    saved_here = {(word >> 16) & 31 for (word,) in struct.iter_unpack('<I', prologue)
                  if word >> 26 == 0x2B and (word >> 21) & 31 == 29}
    if 17 in saved_here: m.reg[17] = 1
    released = []
    def free(v):
        assert v.reg[4] == 0x55000000
        released.append(v.reg[4]); Graph.clobber(v); return 0
    if site == 0x22424:
        m.write(m.reg[29]+0xA60, 0x55000000)
        m.hooks[0x25510+delta] = free
    m.run(site+delta, {STOP}, limit=1000)
    assert m.reg[29] == stack and m.reg[31] == STOP
    assert all(m.reg[r] == value for r, value in saved.items())
    assert m.read(stack-0x2000) == m.read(stack+0x40) == 0xA55AA55A
    assert len(released) == int(site == 0x22424)
    return g


def held_failure(raw, direction=1, delta=0, previous_gate=False):
    """Run the complete held-seek entry through its failed RealPause and return."""
    g = Graph(raw, ((E_FAIL, 0),), delta=delta)
    m = g.vm; ui = 0x51000000
    put(m, ui, bytes(0x2940)); m.write(ui+0x2930, direction)
    m.write(INSTANCE+0x3C, 0x6666)
    m.ranges.append((0x1D880+delta, 0x1DACC+delta))
    timers = []
    def manager(v): Graph.clobber(v); return OBJECT
    def kill(v):
        assert v.reg[4:6] == [0x6666, 1000]
        timers.append(1000); Graph.clobber(v); return 1
    m.hooks[0x1144C+delta] = manager
    m.hooks[0x2517C+delta] = kill
    if previous_gate:
        # Actual 64-byte gate published in PR-26 revision 0e5645e. Its failure
        # lands in the next function and attempts to use the caller's FP as SP.
        m.overrides.update({0x409C0+delta+i: struct.unpack_from('<I', OLD_HELD_GATE, i)[0]
                            for i in range(0, len(OLD_HELD_GATE), 4)})
        m.ranges.append((0x1DACC+delta, 0x1DB4C+delta))
    result = call(m, 0x1D880+delta, [ui], limit=200000)
    assert timers == [1000] and g.index == 1 and not g.seeks and not g.released
    assert m.read(ui+0x2930) == direction
    return g, result


def verify(original, candidate, recipe):
    traces = []

    def record(name, graph, result):
        traces.append(dict(name=name, result=result, **graph.summary()))

    try:
        held_failure(candidate, previous_gate=True)
    except AssertionError as error:
        assert '1234002e' in str(error), str(error)
        traces.append(dict(name='previous draft held-seek failure restores another function frame',
                           wrong_target='0x1db30', correct_target='0x1dab0',
                           original_gate_hex=OLD_HELD_GATE.hex(),
                           failure=str(error), complete_original_caller_entry_executed=True))
    else:
        raise AssertionError('Previous draft wrong-frame defect not reproduced')

    # Execute original instructions, rather than a Python approximation of them.
    for name in ROUTINES:
        g = Graph(original)
        try:
            g.run(name)
        except InfiniteWait:
            record("original infinite GetState: "+name, g, "infinite wait argument")
        else:
            raise AssertionError("Original infinite-wait defect not reproduced")
    g = Graph(original, ((0, 2),), refuse_infinite=False)
    assert g.run("stop") == 1 and g.vm.read(OBJECT+0x24) == 3 and g.index == 1001
    record("original falsely successful Stop after poll limit", g, 1)
    g = Graph(original, ((E_FAIL, 0),), refuse_infinite=False)
    assert g.run("teardown") == 1 and len(g.released) == 6
    record("original teardown accepts failed GetState output", g, 1)

    for delta in (0, 0x1000, 0x10000, 0x123000):
        raw = relocated(candidate, delta) if delta else candidate
        for site in [site for _, sites, *_ in GATES for site in sites]+[0x20C00]:
            g = caller_failure_return(raw, site, delta)
            record(f'caller prologue/failure cleanup/ABI return +{site:x} base +{delta:x}', g, 'returned')
        for direction in (1, 2):
            g, result = held_failure(raw, direction, delta)
            record(f'complete held-seek failed pause direction={direction} base +{delta:x}', g, result)
        g = Graph(raw, ((E_FAIL, 0),), delta=delta)
        assert g.run('render') == 0 and not g.initialized and not g.released
        record(f'complete RenderFile refused replacement returns base +{delta:x}', g, 0)
        for name, samples in (("stop", ((0, 2), (INTERMEDIATE, 1), (0, 1), (INTERMEDIATE, 0), (0, 0))),
                              ("pause", ((0, 2), (0, 1), (0, 0))),
                              ("real_pause", ((0, 2), (INTERMEDIATE, 1), (0, 1)))):
            g = Graph(raw, samples, delta=delta)
            assert g.run(name) == 1
            assert g.vm.read(OBJECT+0x24) == (3 if name=="stop" else 1)
            assert g.summary()["commands"] == (["Pause"] if name=="real_pause" else ["Pause", "Stop"])
            assert all(e["timeout"] == 0 for e in g.events if e["api"]=="GetState")
            assert not g.logs
            assert len(g.seeks) == int(name=="stop")
            record(f"completed {name} base +{delta:x}", g, 1)
        for name, failure in itertools.product(ROUTINES, ("error", "missing_output", "invalid_state",
                                                        "pending", "unchanged_running", "unknown_success",
                                                        "command_error", "after_mute", "during_get")):
            samples = {"error": ((E_FAIL, 0),), "missing_output": ((0, None),),
                       "invalid_state": ((0, 3),), "pending": ((INTERMEDIATE, 0),),
                       "unchanged_running": ((0, 2),), "unknown_success": ((1, 0),)}
            g = Graph(raw, samples.get(failure, ((0, 2),)), delta=delta,
                      action_hr=E_FAIL if failure=="command_error" else 0,
                      mutate=failure if failure in ("after_mute", "during_get") else None)
            assert g.run(name) == 0 and g.vm.read(OBJECT+0x24) == 2
            assert not g.seeks and not g.released and len(g.logs)==1
            if failure=="pending":
                assert not g.summary()["commands"]
            if failure=="unchanged_running":
                assert g.summary()["commands"] == ["Pause"]
            assert g.index <= MAX_POLLS
            record(f"{name} {failure} base +{delta:x}", g, 0)
        for name in ROUTINES:
            for samples in (((0, 0),), ((CANT_CUE, 1), (0, 0))):
                g = Graph(raw, samples, delta=delta)
                assert g.run(name) == 1
                record(f"{name} stopped/cannot-cue base +{delta:x}", g, 1)
            for cached in (0, 1, 3, 0xFFFFFFFF):
                g = Graph(raw, ((0, 0),), cached=cached, delta=delta)
                result = g.run(name)
                assert result == int(name=="stop" or cached!=0xFFFFFFFF)
                if name != "stop":
                    assert g.vm.read(OBJECT+0x24)==cached
                    assert g.index == (0 if cached==0xFFFFFFFF else 1)
                record(f"{name} cached={cached:x} base +{delta:x}", g, result)
        for name, stable in (('real_pause',1),('pause',0)):
            g=Graph(raw,((0,2),(0,1),(0,stable)),delta=delta)
            assert g.run(name)==1 and g.vm.read(OBJECT+0x24)==1
            commands=g.summary()['commands'].copy()
            assert g.run(name)==1 and g.run(name)==1
            assert g.vm.read(OBJECT+0x24)==1 and g.summary()['commands']==commands
            record(f'repeated {name} keeps held seeking available base +{delta:x}',g,1)
        for failure in (False, True):
            g = Graph(raw, ((E_FAIL, 0),) if failure else ((0, 0),), delta=delta)
            refs = data(g.vm, OBJECT+4, 0x18)
            assert g.run("teardown") == int(not failure)
            if failure:
                assert not g.released and data(g.vm, OBJECT+4, 0x18)==refs
                assert g.vm.read(INSTANCE+0x28)==1
            else:
                assert len(g.released)==6 and data(g.vm,OBJECT+4,0x18)==bytes(0x18)
                assert g.vm.read(INSTANCE+0x28)==0
            record(f"teardown failure={failure} base +{delta:x}", g, int(not failure))
        g = Graph(raw, control=False, delta=delta)
        assert g.run("teardown") == 1 and len(g.released)==5
        record(f"partial-object teardown base +{delta:x}", g, 1)
        # Execute the actual RenderFile caller until it selects success/failure.
        for failure in (False, True):
            g = Graph(raw, ((E_FAIL, 0),) if failure else ((0, 0),), delta=delta)
            m=g.vm; m.reg[4:6]=[OBJECT,0x50000000]; m.reg[29]=0x68000000
            m.run(0x11F78+delta,{0x11FBC+delta,0x12248+delta},limit=200000)
            assert g.initialized == int(not failure)
            assert m.pc == (0x12248 if failure else 0x11FBC)+delta
            if failure:
                assert not g.released and m.reg[16]==0
            record(f"RenderFile refuses failed teardown={failure} base +{delta:x}",g,int(not failure))
        # Actual detach instructions select failure before save/status publication.
        for active, failed, attached in itertools.product((False, True), repeat=3):
            g=Graph(raw,((E_FAIL,0),) if failed else ((0,0),),delta=delta)
            m=g.vm; m.reg[2]=INSTANCE; m.reg[17]=1; m.reg[29]=0x68000000
            m.write(INSTANCE+0x28,int(active));m.write(INSTANCE+0x38,int(attached));m.write(INSTANCE+4,1)
            m.hooks[0x1144C+delta]=lambda v:OBJECT
            m.run(0x20BE4+delta,{0x20C28+delta,0x20C44+delta,0x20E88+delta},limit=200000)
            expected_failed=active and failed
            assert m.reg[17]==int(not expected_failed)
            assert m.pc==(0x20E88 if expected_failed else (0x20C28 if attached else 0x20C44))+delta
            if expected_failed: assert not g.released and m.read(INSTANCE+0x38)==int(attached)
            if not active: assert g.index==0 and not g.released
            record(f'detach active/failure/attached={active}/{failed}/{attached} base +{delta:x}',g,int(not expected_failed))
        # Every post-transition caller gate tail-calls the original successful
        # operation, preserving argument registers, return address and stack args.
        # Failure reaches the original caller's existing exit before that operation.
        for gate, sites, success, failure, label in GATES:
            for site, ok in itertools.product(sites,(False,True)):
                g=Graph(raw,delta=delta);m=g.vm
                m.ranges.append((site+delta,site+8+delta))
                m.reg[2]=int(ok);m.reg[4:8]=[0x11111111,0x22222222,0x33333333,0x44444444]
                m.reg[29]=0x68000000;m.write(m.reg[29]+0x10,0x55555555)
                # VM hooks implement JAL/JALR, while gates use JR tail calls.
                # Stop at the actual target and inspect the tail-call ABI.
                m.run(site+delta,{success+delta,failure+delta},limit=1000)
                assert m.pc==(success if ok else failure)+delta
                assert m.reg[29]==0x68000000 and m.reg[31]==site+8+delta
                assert m.read(m.reg[29]+0x10)==(0 if site==0x1C650 else 0x55555555)
                if ok:
                    assert m.reg[4:8]==[0 if site==0x1B398 else 0x11111111,0x22222222,0x33333333,0x44444444]
                record(f'{label} caller +{site:x} success={ok} base +{delta:x}',g,int(ok))
    for name, clock, sleep_ms, tick_step in itertools.product(ROUTINES,(0,0xFFFFFFF0),(0,1,5,37),(0,1)):
        g=Graph(candidate,((INTERMEDIATE,0),),clock=clock,sleep_ms=sleep_ms,tick_step=tick_step)
        assert g.run(name)==0 and not g.summary()["commands"] and g.index<=MAX_POLLS
        if sleep_ms==0 and tick_step==0:
            assert g.index==MAX_POLLS
        record(f"{name} deadline/wrap/frozen clock {clock:x}/{sleep_ms}/{tick_step}",g,0)
    for name in ROUTINES:
        for control, audio, ready in itertools.product((False,True),repeat=3):
            g=Graph(candidate,control=control,audio=audio,ready=ready)
            expected=int(control and (ready or name!='stop'))
            assert g.run(name)==expected
            if not expected:
                assert g.vm.read(OBJECT+0x24)==2 and not g.seeks
            record(f"{name} control/audio/ready={control}/{audio}/{ready}",g,expected)
    checks=structure(original,candidate,recipe)
    return dict(cases=len(traces)+checks['cases'],traces=traces,structure=checks,
                limits="Actual MIPS instructions; COM, clocks and scheduling are fixtures. No native or device testing.")


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline',type=Path,required=True,help='Exact MAX04 MgrUSB.exe')
    parser.add_argument('--out',type=Path,help='Optional new report file')
    args=parser.parse_args()
    original=args.baseline.read_bytes();candidate,recipe=patch(original)
    result=verify(original,candidate,recipe)
    if args.out:
        if args.out.exists(): raise ValueError('Existing evidence is never overwritten')
        args.out.parent.mkdir(parents=True,exist_ok=True)
        args.out.write_text(json.dumps(dict(recipe=recipe,**result),indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'],candidate_sha256=recipe['sha256'],native_executed=False),indent=2))


if __name__=='__main__':main()
