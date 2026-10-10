"""Interpret bounded WAM/runtime queue paths with explicit driver, table and OS fixtures.

No firmware is executed natively. These slices test header bounds, automatic close
cleanup and two separate callback queues, not all driver/kernel scheduling.
"""
import hashlib
import json
import struct
from pathlib import Path

from inspect_bt_lifecycle import SliceVM, Playback, CTX, PCM, SLOT
from inspect_bt_playback import BLUE_HASH, ROOT, source

OWNER, STREAM, DEVICE, VTABLE, DRIVER = 0x43000000, 0x41000000, 0x44000000, 0x44000100, 0x44000200
COREOBJ, MANAGER, STOP = 0x45000000, 0x45001000, 0xdead0000
HANDLE, PROXY_THREAD, BLUE_THREAD, EVENT = 0x1234, 0xf003, 0xf002, 0xf001
WAM_RANGES = [(0xc03fa2f0, 0xc03fa5f0), (0xc03f2aa4, 0xc03f2b3c),
              (0xc03fa128, 0xc03fa2e4), (0xc03f85bc, 0xc03f86bc),
              (0xc03f86bc, 0xc03f88d4), (0xc03f88d4, 0xc03f8a58),
              (0xc03f10b0, 0xc03f1174), (0xc03f1000, 0xc03f1070)]
CORE_RANGES = [(0x4009e7c4, 0x4009e854), (0x4009ebf0, 0x4009ec18),
               (0x4009ea98, 0x4009ebe4), (0x4009e854, 0x4009e9a8),
               (0x40031e5c, 0x40031ecc), (0x40031ecc, 0x40031ef4),
               (0x4009e768, 0x4009e7c4)]
HASHES = {
    "waveapi.dll": "75dda3a4642c385b50c71e262c0676e61d7ee28e736d2093270dbabcf8fbc975",
    "coredll.dll": "1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c",
    "audevman.dll": "9991a8b5f195c29aff63fee1c5fd034e1295b84cef43a37463f93863dfdd3d65",
}
GUARDS = {
    "waveapi.dll": {
        0xc03f2b04: 0x0169402b, 0xc03f2b08: 0x15000006, 0xc03f2b1c: 0x11490002,
        0xc03fa3d4: 0x31480002, 0xc03fa3f8: 0x24100021, 0xc03f8740: 0x1540003e,
        0xc03f8750: 0xadac0010, 0xc03f867c: 0x01094024, 0xc03f8690: 0x0c0fe14b,
    },
    "coredll.dll": {
        0x4009e80c: 0xafa90010, 0x4009e82c: 0x14440002, 0x4009e834: 0x00008025,
        0x4009eb94: 0x0c027a15, 0x40031ea4: 0xae300000,
    },
}


class BytesVM(SliceVM):
    def __init__(self, pe, ranges, mem=None):
        super().__init__(pe)
        self.ranges = ranges
        if mem is not None: self.mem = mem
        self.reg[29], self.reg[31] = 0x68000000, STOP

    def word(self, pc):
        assert any(lo <= pc < hi for lo, hi in self.ranges), hex(pc)
        raw = self.pe.get_data(pc - self.base, 4)
        assert len(raw) == 4
        return struct.unpack("<I", raw)[0]

    def internal_call(self, va):
        return any(lo == va for lo, _ in self.ranges)

    def plain(self, word):
        op, rs, rt = word >> 26, (word >> 21) & 31, (word >> 16) & 31
        imm = word & 65535
        signed = imm if imm < 32768 else imm - 65536
        address = (self.reg[rs] + signed) & 0xffffffff
        if op in (0x22, 0x26, 0x2a, 0x2e):
            # All interpreted WAM header fixtures are word-aligned. Check the
            # architectural aligned LWL/LWR/SWL/SWR pair, not an unaligned approximation.
            is_left = op in (0x22, 0x2a)
            assert address % 4 == (3 if is_left else 0), "Unmodeled unaligned header"
            address = address & ~3
            if op in (0x22, 0x26): self.reg[rt] = self.read(address)
            else: self.write(address, self.reg[rt])
            self.reg[0] = 0
        elif op == 0 and word & 63 == 0x26:
            self.reg[(word >> 11) & 31] = self.reg[rs] ^ self.reg[rt]
            self.reg[0] = 0
        else:
            super().plain(word)


class WaveFixture:
    def __init__(self, wam_pe, core_pe, blue_pe=None, header_count=25, driver_result=0,
                 runtime_post_result=1, app_post_result=1):
        self.wam_pe, self.core_pe, self.blue_pe = wam_pe, core_pe, blue_pe
        self.mem = {}
        self.proxies = {}
        self.runtime_queue = []
        self.app_queue = []
        self.events = []
        self.driver_result = driver_result
        self.runtime_post_result, self.app_post_result = runtime_post_result, app_post_result
        self.barrier_event = False
        self.alive = True
        self.vm = self.wam_vm()
        vm = self.vm
        vm.write(STREAM + 0x34, DEVICE)
        vm.write(STREAM + 0x24, COREOBJ)
        vm.write(DEVICE, VTABLE); vm.write(VTABLE + 4, DRIVER)
        vm.write(COREOBJ + 0x10, EVENT); vm.write(COREOBJ + 0x14, BLUE_THREAD)
        vm.write(COREOBJ + 0x1c, 0x20000); vm.write(COREOBJ + 0x20, HANDLE)
        vm.write(COREOBJ + 0x28, MANAGER); vm.write(MANAGER + 0x28, PROXY_THREAD)
        vm.write(COREOBJ + 0xc, 1)
        for i in range(header_count):
            original, proxy = CTX + 0x10 + i * 32, 0x48000000 + i * 64
            self.proxies[i + 1] = proxy
            vm.write(original, PCM + i * SLOT); vm.write(original + 4, SLOT)
            vm.write(original + 0x10, 2); vm.write(original + 0x1c, i + 1)
            vm.write(proxy, PCM + i * SLOT); vm.write(proxy + 4, SLOT)
            vm.write(proxy + 0x10, 2); vm.write(proxy + 0x20, HANDLE)
            vm.write(proxy + 0x24, original); vm.write(proxy + 0x28, PCM + i * SLOT)
            vm.write(proxy + 0x2c, SLOT)

    def atomic(self, vm, decrement=False):
        at = vm.reg[4]
        old = vm.read(at)
        value = old - 1 if decrement else old + vm.reg[5]
        vm.write(at, value)
        return value & 0xffffffff if decrement else old

    def wam_vm(self):
        vm = BytesVM(self.wam_pe, WAM_RANGES, self.mem)
        for address in (0xc03fa830, 0xc03f28a8, 0xc03fb9c0, 0xc03fa7c0, 0xc03fb204, 0xc03f81cc):
            vm.hooks[address] = lambda _vm: 0
        vm.hooks[0xc03fa760] = lambda _vm: STREAM
        vm.hooks[0xc03f8000] = lambda machine: self.proxies.get(machine.reg[5], 0)
        vm.hooks[0xc03f1070] = lambda _vm: 0  # Ordinary device fixture, not the special software-mixer globals.
        vm.hooks[0xc03ffbcc] = lambda machine: self.atomic(machine)
        vm.hooks[0xc03ff92c] = lambda machine: self.atomic(machine, True)
        vm.hooks[DRIVER] = self.driver
        def map_header(machine):
            assert machine.reg[6] == 32
            machine.write(machine.reg[4], machine.reg[5])
            return 0
        vm.hooks[0xc03f48c0] = map_header
        def remove(machine):
            token = machine.reg[5]
            self.proxies.pop(token, None)
            self.events.append(dict(kind="unmap", token=token))
            return 0
        vm.hooks[0xc03f852c] = remove
        def begin(machine):
            self.iterator = 0
            return machine.reg[4]
        vm.hooks[0xc03f8450] = begin
        vm.hooks[0xc03f8240] = lambda _vm: setattr(self, "iterator", 0) or 0
        def next_header(machine):
            tokens = sorted(t for t in self.proxies if t > self.iterator)
            if not tokens: return 0
            token = tokens[0]; self.iterator = token
            machine.write(machine.reg[7], self.proxies[token])
            token_pointer = machine.read(machine.reg[29] + 0x10)
            if token_pointer: machine.write(token_pointer, token)
            return 1
        vm.hooks[0xc03f82a0] = next_header
        def post(machine):
            data = [machine.read(machine.reg[5] + i * 4) for i in range(5)]
            assert machine.reg[6] == 20
            if self.runtime_post_result: self.runtime_queue.append(data)
            self.events.append(dict(kind="runtime_post", message=data[0], result=self.runtime_post_result))
            return self.runtime_post_result
        vm.hooks[0xc03ff93c] = post
        # Explicit fixture for the failure branch's imported GetLastError pointer.
        vm.write(0xc0401150, DRIVER + 4)
        vm.hooks[DRIVER + 4] = lambda _vm: 6
        return vm

    def driver(self, vm):
        message = vm.reg[5]
        self.events.append(dict(kind="driver", message=message, header=hex(vm.reg[7]), result=self.driver_result))
        if message == 9 and self.driver_result == 0:
            vm.write(vm.reg[7] + 0x10, vm.read(vm.reg[7] + 0x10) | 0x10)
        return self.driver_result

    def call(self, va, args, stack_args=()):
        vm = self.wam_vm()
        vm.reg[4:8] = list(args) + [0] * (4 - len(args))
        for i, arg in enumerate(stack_args): vm.write(vm.reg[29] + 0x10 + i * 4, arg)
        vm.run(va, {STOP})
        return vm.reg[2]

    def write(self, original):
        return self.call(0xc03fa2f0, (OWNER, 2, HANDLE, original), (32,))

    def unprepare(self, original):
        return self.call(0xc03fa128, (OWNER, 2, HANDLE, original), (32,))

    def close(self):
        return self.call(0xc03f88d4, (OWNER, 2, HANDLE))

    def complete(self, token):
        proxy = self.proxies[token]
        self.vm.write(proxy + 0x10, (self.vm.read(proxy + 0x10) & ~0x10) | 1)
        self.call(0xc03f10b0, (STREAM, 0x3bd, 0, proxy), (0,))

    def core_vm(self, stack):
        vm = BytesVM(self.core_pe, CORE_RANGES, self.mem)
        vm.reg[29] = stack
        vm.hooks[0x40030a84] = lambda _vm: BLUE_THREAD  # Current thread differs from proxy.
        def write_queue(machine):
            assert machine.reg[6] == 20
            frame = [machine.read(machine.reg[5] + i * 4) for i in range(5)]
            self.runtime_queue.append(frame)
            self.events.append(dict(kind="barrier_post", message=frame[0], object=hex(frame[1])))
            return 1
        vm.hooks[0x4002cb1c] = write_queue
        def read_queue(machine):
            if not self.runtime_queue: return 0
            frame = self.runtime_queue.pop(0)
            for i, word in enumerate(frame): machine.write(machine.reg[5] + i * 4, word)
            machine.write(machine.reg[7], 20)
            return 1
        vm.hooks[0x4002cab8] = read_queue
        def post_thread(machine):
            if self.app_post_result:
                self.app_queue.append(dict(thread=machine.reg[4], message=machine.reg[5],
                                           handle=machine.reg[6], header=machine.reg[7]))
            self.events.append(dict(kind="app_post", message=machine.reg[5], result=self.app_post_result))
            return self.app_post_result
        vm.hooks[0x4002837c] = post_thread
        def signal(machine):
            assert machine.reg[4] == EVENT and machine.reg[5] == 3
            self.barrier_event = True
            self.events.append(dict(kind="barrier_signal", object_alive=self.alive))
            return 1
        vm.hooks[0x4002aacc] = signal
        return vm

    def drain_proxy(self):
        vm = self.core_vm(0x69000000)
        vm.reg[4] = MANAGER
        vm.run(0x4009ea98, {STOP})

    def barrier(self, wait_result=0, drain=False):
        vm = self.core_vm(0x6a000000)
        vm.reg[4], vm.reg[5] = COREOBJ, 100
        def wait(machine):
            assert machine.reg[4] == EVENT and machine.reg[5] == 100
            if drain: self.drain_proxy()
            self.events.append(dict(kind="wait", result=wait_result, event_signaled=self.barrier_event))
            if wait_result == 0: self.barrier_event = False  # Auto-reset event fixture.
            return wait_result
        vm.hooks[0x4002abe0] = wait
        vm.run(0x4009e7c4, {STOP})
        return vm.reg[2]


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    addresses = {
        "waveapi.dll": [0xc03f3410, 0xc03f1000, 0xc03f10b0, 0xc03f2aa4, 0xc03f97f0,
                        0xc03fa128, 0xc03fa2f0, 0xc03f85bc, 0xc03f86bc, 0xc03f88d4,
                        0xc03f8c0c, 0xc03f852c, 0xc03f8000, 0xc03f8450, 0xc03f81cc, 0xc03fa760,
                        0xc03f9428],
        "coredll.dll": [0x4009e7c4, 0x4009e854, 0x4009ea98, 0x4009ebf0, 0x4009edf4,
                        0x4007fb08, 0x4007fcfc, 0x4007fe84, 0x4009e630, 0x4009ec18,
                        0x4009ec88, 0x4009ece8, 0x4009e768, 0x4009e9a8, 0x4009e668,
                        0x4009e6c0, 0x40031e5c, 0x40031ecc, 0x40031960],
        "audevman.dll": [0xc0412900],
    }
    sources, pes = [], {}
    for name, vas in addresses.items():
        module = next(m for m in modules if m["origin"] == "rom" and m["name"] == name)
        assert module["sha256"] == HASHES[name]
        item, pe = source(module, vas, {0x4009e630: 0x38, 0x40031ecc: 0x28})
        sources.append(item); pes[name] = pe
    blue = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    assert blue["sha256"] == BLUE_HASH
    blue_source, blue_pe = source(blue, [0x2639c, 0x26400, 0x26e14], {})
    sources.append(blue_source)
    wam, core = pes["waveapi.dll"], pes["coredll.dll"]
    preimages = []
    for name, guards in GUARDS.items():
        pe = pes[name]
        for va, expected in guards.items():
            actual = struct.unpack("<I", pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, 4))[0]
            assert actual == expected, (name, hex(va), hex(actual))
            preimages.append(dict(module=name, va=hex(va), word=hex(actual)))
    boundary_cases = []
    for size in (0, 4, 20480, 20481, 24576, 25600, 25601, 26624, 0xffffffff):
        for identity in ("valid", "wrong_original_header", "wrong_pcm_pointer", "missing_proxy"):
            w = WaveFixture(wam, core, header_count=1)
            hdr = CTX + 0x10
            w.vm.write(hdr + 4, size)
            if identity == "wrong_original_header": w.vm.write(w.proxies[1] + 0x24, hdr + 32)
            elif identity == "wrong_pcm_pointer": w.vm.write(hdr, PCM + 4)
            elif identity == "missing_proxy": w.proxies.clear()
            result = w.write(hdr)
            expected = 0 if identity == "valid" and size <= SLOT else 0xb
            assert result == expected
            calls = [e for e in w.events if e["kind"] == "driver"]
            assert len(calls) == int(expected == 0)
            assert w.vm.read(hdr + 0x10) & 0x10 == (0x10 if expected == 0 else 0)
            boundary_cases.append(dict(bytes=size, identity=identity, result=result, driver_calls=len(calls)))
    flag_cases = []
    for flags in range(32):
        for driver_result in (0, 1):
            w = WaveFixture(wam, core, header_count=1, driver_result=driver_result)
            w.vm.write(CTX + 0x20, flags)
            result = w.write(CTX + 0x10)
            expected = 0x22 if not flags & 2 else 0x21 if flags & 0x10 else driver_result
            assert result == expected
            if flags & 2 and not flags & 0x10 and driver_result:
                assert not w.vm.read(CTX + 0x20) & 0x10 and w.vm.read(STREAM + 0x58) == 0
            flag_cases.append(dict(flags=flags, driver_result=driver_result, result=result))
    cleanup_cases = []
    for queued in list(range(25)) + [None]:
        w = WaveFixture(wam, core)
        if queued is not None: w.vm.write(w.proxies[queued + 1] + 0x10, 0x12)
        before = {token: w.vm.read(proxy + 0x10) for token, proxy in w.proxies.items()}
        result = w.close()
        if queued is None:
            assert result == 0 and not w.proxies
            assert len([e for e in w.events if e["kind"] == "unmap"]) == 25
        else:
            assert result == 0x21 and not w.events
            assert {token: w.vm.read(proxy + 0x10) for token, proxy in w.proxies.items()} == before
        cleanup_cases.append(dict(queued_header=queued, result=result, remaining_proxies=len(w.proxies)))
    w = WaveFixture(wam, core)
    assert w.unprepare(CTX + 0x10) == 0 and len(w.proxies) == 24
    assert w.close() == 0 and not w.proxies
    compensated = dict(blue_explicit_unprepare=1, wam_automatic_unprepares=24,
                       required_condition="No queued proxy flags; fixture driver cleanup/close succeed")
    ignored_errors = []
    for result in (0, 1, 8, 0x21):
        w = WaveFixture(wam, core, header_count=1, driver_result=result)
        actual = w.unprepare(CTX + 0x10)
        assert actual == (0 if result == 8 else result) and not w.proxies
        ignored_errors.append(dict(driver_unprepare=result, return_value=actual, remaining_proxies=0))
    linked = Playback(blue_pe)
    w = WaveFixture(wam, core, header_count=1)
    # Both interpreters share the actual caller/header memory. Preserve Blue context,
    # but restore this fixture's registered original header including its reserved token.
    w.mem.update(linked.vm.mem)
    w.vm.write(CTX + 0x2c, 1)
    linked.vm.mem = w.mem
    linked.vm.hooks[0x8a8e0] = lambda vm: w.write(vm.reg[5])
    for _ in range(4): linked.packet(6656)
    assert w.vm.read(CTX + 5, 1) == 1 and w.vm.read(CTX + 0x1c) == 1
    assert not w.vm.read(CTX + 0x20) & 0x10
    assert not any(e["kind"] == "driver" for e in w.events)
    combined = dict(incoming_bytes=6656, accumulated_bytes=26624, wave_result=0xb,
                    driver_calls=0, blue_pending=1, blue_dwUser=1, original_WHDR_INQUEUE=False)
    w = WaveFixture(wam, core, header_count=1)
    assert w.write(CTX + 0x10) == 0
    w.complete(1)
    assert len(w.runtime_queue) == 1 and not w.app_queue
    assert w.barrier(drain=True) == 1 and not w.runtime_queue and len(w.app_queue) == 1
    assert w.app_queue[0]["header"] == CTX + 0x10
    assert w.vm.read(CTX + 0x20) & 0x10 == 0 and w.vm.read(CTX + 0x20) & 1
    barrier_trace = list(w.events)
    failed_posts = []
    for gate in ("runtime", "app"):
        w = WaveFixture(wam, core, header_count=1, runtime_post_result=int(gate != "runtime"),
                        app_post_result=int(gate != "app"))
        w.vm.write(CTX + 5, 1, 1); w.vm.write(CTX + 0x1c, 1)
        assert w.write(CTX + 0x10) == 0
        w.complete(1)
        assert w.barrier(drain=True) == 1 and not w.runtime_queue and not w.app_queue
        assert w.vm.read(STREAM + 0x58) == 0
        expected_inqueue = gate == "runtime"
        assert bool(w.vm.read(CTX + 0x20) & 0x10) == expected_inqueue
        assert w.vm.read(CTX + 5, 1) == 1 and w.vm.read(CTX + 0x1c) == 1
        if gate == "app":
            callback_vm = w.core_vm(0x6b000000)
            callback_vm.reg[4:8] = [COREOBJ, 0x3bd, CTX + 0x10, 0]
            callback_vm.run(0x4009e854, {STOP})
            assert callback_vm.reg[2] == 1  # PostThreadMessage returned zero but s0 remains one.
        failed_posts.append(dict(failed_queue=gate, wam_pending=0, blue_pending=1, blue_dwUser=1,
                                 original_WHDR_INQUEUE=expected_inqueue, barrier_return=1,
                                 callback_dispatch_return=1 if gate == "app" else None,
                                 events=list(w.events), scope="Injected queue failure; no later recovery modeled"))
    w = WaveFixture(wam, core, header_count=1)
    assert w.barrier(wait_result=0x102) == 0 and len(w.runtime_queue) == 1
    w.drain_proxy()  # The expired wait's marker arrives after its caller has returned.
    assert w.barrier_event and not w.runtime_queue
    assert w.barrier(wait_result=0, drain=False) == 1 and len(w.runtime_queue) == 1
    stale_barrier = dict(second_wait_return=1, second_marker_still_queued=True, events=list(w.events),
                         scope="Sequential waits on the same auto-reset event, with a late first marker; scheduler is a fixture")
    waits = []
    for result in (0, 0x102, 0xffffffff, 0x80):
        w = WaveFixture(wam, core, header_count=1)
        actual = w.barrier(wait_result=result)
        expected = 0 if result == 0x102 else 1
        assert actual == expected
        waits.append(dict(wait_result=hex(result), barrier_return=actual,
                          scope="Injected API return; invalid handle cause is not established"))
    alloc_vm = BytesVM(core, CORE_RANGES)
    alloc_vm.hooks[0x40031960] = lambda vm: vm.reg[5]
    alloc_vm.reg[4:8] = [0x46000000, PCM, SLOT, 0x80000004]
    alloc_vm.run(0x40031e5c, {STOP})
    assert alloc_vm.reg[2] == 0 and alloc_vm.read(0x46000000) == PCM
    evidence = dict(sources=sources,
        producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        interpreter_sha256=hashlib.sha256((ROOT / "tools/inspect_bt_lifecycle.py").read_bytes()).hexdigest(),
        checks=dict(original_ranges=sum(len(s["ranges"]) for s in sources),
                    exact_preimages=len(preimages),
                    registered_header_boundary_cases=len(boundary_cases), write_flag_error_cases=len(flag_cases),
                    close_preflight_cases=len(cleanup_cases), unprepare_driver_returns=len(ignored_errors),
                    blue_wam_rejection_traces=1, proxy_app_barrier_traces=1, barrier_wait_returns=len(waits),
                    async_pointer_identity_traces=1, failed_queue_posts=len(failed_posts), stale_barrier_traces=1),
        native_execution=False, os_driver_calls="Mocked; table ownership and aligned headers are explicit fixtures",
        exact_preimages=preimages, boundary_cases=boundary_cases, write_flags=flag_cases, close_preflight=cleanup_cases,
        close_compensates_blue_loop=compensated, unprepare_cleanup_on_error=ignored_errors,
        linked_blue_wam=combined, two_queues=barrier_trace, barrier_returns=waits,
        queue_failure_traces=failed_posts, late_marker_trace=stale_barrier,
        async_mapping=dict(va="0x40031e5c", result="validated PCM pointer returned unchanged",
                           helper="0x40031960 accepts nonzero length for descriptor 4/8/c; allocator does not copy PCM"),
        message_record=dict(bytes=20, dwords=["message", "client runtime object", "original caller header",
                                             "callback parameter", "bytes recorded"], sentinel="ffffffff + client object; remaining words not initialized by barrier slice"),
        limitations=["No native scheduler, kernel message ordering or physical driver/DMA execution",
                     "WAM table enumeration/device/OS helpers are fixtures, not complete implementations",
                     "No proof that Max's negotiated SBC transport produces 6656-byte decoded packets",
                     "Software mixer, actual queued driver reset, object lifetime and real callback-loss incidence remain open"])
    out = ROOT / "analysis/firmware/wave-queue"
    out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(evidence, indent=2), encoding="utf-8")
    lines = []
    for item in sources:
        ranges = [(int(r["va"], 16), int(r["va"], 16) + r["bytes"]) for r in item["ranges"]]
        path = ROOT / "analysis/disassembly" / ("rom" if item["origin"] == "rom" else "") / (item["module"] + ".asm")
        lines.append(f"; {item['module']} {item['sha256']}\n")
        for line in path.read_text(encoding="utf-8").splitlines(keepends=True):
            try: va = int(line[:8], 16)
            except ValueError: continue
            if any(lo <= va < hi for lo, hi in ranges): lines.append(line)
    (out / "reviewed-paths.asm").write_text("".join(lines), encoding="utf-8")
    print(json.dumps(dict(status="passed", **evidence["checks"], linked_blue_wam=combined,
                         barrier_returns=waits), indent=2))


if __name__ == "__main__":
    main()
