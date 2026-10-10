"""Linked MIPS audit of a failed first audio open and subsequent silence.

Real filter dispatcher/open/close/start/process bytes; explicit OS/thread fixtures.
No native firmware execution, executable modifications or release creation.
"""
import hashlib
import json
from pathlib import Path
from audit_bt_stream_start import ROOT, StartVM, ORIGINAL_HASH, CURRENT_HASH
import pefile
from inspect_wave_queue import STOP

AV, CTX, PCM, INPUT, LIST, NEXT = (0x48000000 + i * 0x100000 for i in range(6))
WIN, SINK = 0x110330, 0x110298
RANGES = [(0x25a5c, 0x25e84), (0x2639c, 0x26400), (0x266a4, 0x26e14), (0x26e14, 0x270f4)]


class VM(StartVM):
    def internal_call(self, va):
        return va in (0x25a5c, 0x266a4, 0x26a8c, 0x26c68, 0x26d2c, 0x26e14)

    def plain(self, word):
        op, fn = word >> 26, word & 63
        rs, rt, rd, sh = (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, (word >> 6) & 31
        if op == 0 and fn == 0x19:
            product = self.reg[rs] * self.reg[rt]
            self.lo, self.hi = product & 0xffffffff, product >> 32
        elif op == 0 and fn in (2, 3):
            value = self.reg[rt]
            if fn == 3 and value >= 0x80000000:
                value -= 0x100000000
            self.reg[rd] = (value >> sh) & 0xffffffff
        elif op == 0 and fn == 0x2a:
            signed = lambda x: x if x < 0x80000000 else x - 0x100000000
            self.reg[rd] = int(signed(self.reg[rs]) < signed(self.reg[rt]))
        else:
            super().plain(word)


def run_case(pe, failure):
    vm = VM(pe, RANGES)
    # Preserve real readonly switch offsets and the actual WinPlay vtable.
    for lo, hi in ((0x25b78, 0x25b88), (WIN, WIN + 0x3c), (SINK, SINK + 0x3c)):
        for i, value in enumerate(pe.get_data(lo - vm.base, hi - lo)):
            vm.write(lo + i, value, 1)
    vm.write(AV + 0x48, WIN)
    vm.write(AV + 0x70, CTX)
    vm.write(AV + 0x98, 1, 1)  # Explicit isolated WinPlay filter fixture.
    vm.write(AV + 0x11c, 1, 1)
    vm.write(AV + 0x11d, 1, 1)
    vm.write(WIN + 7, 1, 1)
    vm.write(WIN + 8, CTX)
    vm.write(CTX + 0x10, PCM)
    vm.write(0x110f9c, CTX)
    vm.write(LIST, WIN)
    vm.write(LIST + 4, SINK)
    vm.write(SINK + 0x24, NEXT)
    events = []
    phase = "first_open"
    attempts = 0
    opened_handles = set()
    active_threads = set()
    copies = []
    prepared = set()

    def hook(fn):
        def wrapped(machine):
            result = fn(machine)
            for i in (1, *range(3, 16), 24, 25):
                machine.reg[i] = 0xfabc0000 + i
            return result
        return wrapped

    def format(machine):
        for pointer, value, size in zip(machine.reg[4:7], (2, 16, 44100), (1, 1, 2)):
            machine.write(pointer, value, size)
        return 0

    def thread(machine):
        if phase == "first_open" and failure == "thread":
            events.append(dict(phase=phase, call="CreateThread", success=False))
            return 0
        handle = 0x9000 + len(events)
        active_threads.add(handle)
        machine.write(machine.read(machine.reg[29] + 0x14), handle + 0x100)
        events.append(dict(phase=phase, call="CreateThread", handle=handle))
        return handle

    def wave_open(machine):
        nonlocal attempts
        attempts += 1
        error = 4 if phase == "first_open" and failure == "wave" else 0
        handle = 0 if error else 0xb000 + attempts
        assert machine.reg[4] == CTX + 8
        machine.write(machine.reg[4], handle)
        if handle:
            opened_handles.add(handle)
        events.append(dict(phase=phase, call="waveOutOpen", error=error, handle=handle))
        return error

    def prepare(machine):
        assert machine.reg[4] in opened_handles and machine.reg[6] == 32
        prepared.add(machine.reg[5])
        machine.write(machine.reg[5] + 0x10, 2)
        return 0

    def pause(machine):
        assert machine.reg[4] in opened_handles
        events.append(dict(phase=phase, call="waveOutPause", handle=machine.reg[4]))
        return 0

    def memset(machine):
        assert machine.reg[4:7] == [PCM, 0, 640000]
        # PCM contents irrelevant before the explicit next packet copy.
        return PCM

    def copy(machine):
        copies.append(dict(phase=phase, bytes=machine.reg[6]))
        return machine.reg[4]

    def exit_code(machine):
        assert machine.reg[4] in active_threads
        machine.write(machine.reg[5], 259)
        return 1

    def terminate(machine):
        assert machine.reg[4] in active_threads
        events.append(dict(phase=phase, call="TerminateThread", handle=machine.reg[4]))
        active_threads.remove(machine.reg[4])
        return 1

    def write(machine):
        assert machine.reg[4] in opened_handles and machine.reg[5] in prepared
        machine.write(machine.reg[5] + 0x10, 0x12)
        return 0

    apis = {0x193b4: format, 0x8a7c0: lambda _: 0, 0x34264: lambda _: 0,
            0x8a7f0: thread, 0x8a880: wave_open, 0x8a870: prepare,
            0x8a830: pause, 0x3a750: memset, 0x85758: copy,
            0x8a890: terminate, 0x85bb8: lambda _: 0, NEXT: lambda _: 0,
            0x19410: lambda _: AV, 0x18220: lambda _: 1, 0x18260: lambda _: 1,
            0x8a820: lambda _: 0, 0x8a810: lambda _: 0, 0x8a8e0: write,
            0x8a8d0: lambda _: 0, 0x8a8c0: lambda _: 0,
            0xf0000001: lambda _: 1, 0xf0000002: lambda _: 0,
            0xf0000003: lambda _: 1, 0xf0000004: lambda _: 0,
            0xf0000005: exit_code, 0xf0000006: lambda _: 1,
            0xf0000007: lambda _: 8}
    vm.hooks = {address: hook(fn) for address, fn in apis.items()}
    for address, target in ((0x11005c, 0xf0000001), (0x110024, 0xf0000002),
                            (0x110058, 0xf0000003), (0x110010, 0xf0000004),
                            (0x110068, 0xf0000005), (0x110020, 0xf0000006),
                            (0x110060, 0xf0000007)):
        vm.write(address, target)

    def invoke(entry, args, size=None):
        stack = vm.reg[29]
        saved = {i: 0x12340000 + i for i in (*range(16, 24), 30)}
        for i, value in saved.items():
            vm.reg[i] = value
        vm.reg[31] = STOP
        vm.reg[4:4 + len(args)] = args
        if size is not None:
            vm.write(stack + 0x10, size)
        vm.run(entry, {STOP}, limit=20000)
        assert vm.reg[29] == stack and all(vm.reg[i] == value for i, value in saved.items())
        return vm.reg[2]

    first_open = invoke(0x25a5c, [0, AV, 2])
    first_start = invoke(0x25a5c, [0, AV, 4])
    stranded = dict(open_result=first_open, start_result=first_start,
                    filter_state=vm.read(WIN + 7, 1), context_state=vm.read(CTX + 4, 1),
                    handle=vm.read(CTX + 8), thread_handle=vm.read(CTX + 0xc))
    assert first_open == int(failure == "none") and first_start == 1
    assert stranded["filter_state"] == 3
    assert stranded["handle"] == 0 if failure != "none" else stranded["handle"] != 0
    phase = "later_play_request"
    before = len(events)
    later_open = invoke(0x25a5c, [0, AV, 2])
    later_start = invoke(0x25a5c, [0, AV, 4])
    assert later_open == later_start == 1 and len(events) == before
    # All first packets are 4096 bytes: original accumulates, current submits one.
    invoke(0x26e14, [0, LIST, 1, INPUT], 4096)
    if failure != "none":
        assert not copies and vm.read(CTX + 8) == 0
        phase = "explicit_close_reopen"
        assert invoke(0x25a5c, [0, AV, 3]) == 1
        assert not active_threads
        assert invoke(0x25a5c, [0, AV, 2]) == 1
        assert invoke(0x25a5c, [0, AV, 4]) == 1
        assert vm.read(CTX + 4, 1) == 2 and vm.read(CTX + 8) != 0
        invoke(0x26e14, [0, LIST, 1, INPUT], 4096)
    assert copies == [dict(phase=phase, bytes=4096)]
    return dict(failure=failure, first_state=stranded, later_play=dict(open_result=later_open,
                start_result=later_start, new_api_calls=0), events=events, copies=copies,
                final_filter_state=vm.read(WIN + 7, 1), final_context_state=vm.read(CTX + 4, 1),
                final_handle=vm.read(CTX + 8), instructions=vm.steps)


def main():
    paths = {
        "original": "extracted/705md/upgrade/Storage Card/System/Blue.exe",
        "published_MAX03": "build/maxmade-7.0.6.MAX03/payload/upgrade/Storage Card/System/Blue.exe",
        "current_development": "build/usb-option-snapshot-development-01/payload/upgrade/Storage Card/System/Blue.exe",
    }
    modules = {}
    for label, path in paths.items():
        raw = (ROOT / path).read_bytes()
        digest = hashlib.sha256(raw).hexdigest()
        assert digest == (ORIGINAL_HASH if label == "original" else CURRENT_HASH)
        pe = pefile.PE(data=raw)
        modules[label] = dict(path=path, sha256=digest,
                             cases=[run_case(pe, failure) for failure in ("none", "wave", "thread")])
    proof = dict(cases=9, modules=modules, native_execution=False,
                 scope="Real linked MIPS FiltersRun, WinPlayOpen, WinPlayStart, WinPlayClose and WinPlayProcess, isolated WinPlay-filter fixture. OS/thread outcomes are explicit fixtures. Explicit close/reopen is not an emulation of the full phone reconnect handler.",
                 conclusion="Transient wave/thread open failure advances table to started despite no output handle. A later open/start request makes no API attempt; PCM is discarded. Explicit native filter close/reopen/start recovers when APIs subsequently succeed.",
                 dependencies={name: hashlib.sha256((ROOT / "tools" / name).read_bytes()).hexdigest()
                               for name in (Path(__file__).name, "audit_bt_stream_start.py",
                                            "inspect_wave_queue.py", "inspect_bt_lifecycle.py", "inspect_bt_playback.py")})
    out = ROOT / "analysis/firmware/bt-startup-silence-audit.json"
    out.write_text(json.dumps(proof, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(cases=proof["cases"], report=str(out), conclusion=proof["conclusion"])))


if __name__ == "__main__":
    main()
