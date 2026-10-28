"""Bounded MIPS byte interpretation of Blue's queue/cleanup; all OS calls are stubs.

This is not native firmware execution or a scheduler/driver emulator. Entry states,
API failures and callback delivery are explicit fixtures. Unknown opcodes/calls fail.
"""
import hashlib
import json
import struct
from pathlib import Path

from inspect_bt_playback import BLUE_HASH, ROOT, prefill, source

CTX, PCM, STACK, INPUT, HOLDER = 0x40000000, 0x50000000, 0x60000000, 0x70000000, 0x40001000
SLOT, COUNT = 25600, 25
SOURCES = {
    "reset": "https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452459(v=msdn.10)",
    "unprepare": "https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452465(v=msdn.10)",
    "prepare": "https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452457(v=msdn.10)",
    "close": "https://learn.microsoft.com/en-us/previous-versions/windows/embedded/aa452443(v=msdn.10)",
    "thread": "https://learn.microsoft.com/en-us/previous-versions/ms913243(v=msdn.10)",
}


class SliceVM:
    """Only the instruction subset encountered in these reviewed, bounded slices."""
    def __init__(self, pe, patches=None):
        self.pe = pe
        self.base = pe.OPTIONAL_HEADER.ImageBase
        self.patches = patches or {}
        self.reg = [0] * 32
        self.mem = {}
        self.hi = self.lo = 0
        self.hooks = {}
        self.events = []
        self.steps = 0
        self.pc = 0

    def read(self, at, size=4):
        return sum(self.mem.get(at + i, 0) << (8 * i) for i in range(size))

    def write(self, at, value, size=4):
        for i in range(size):
            self.mem[at + i] = (value >> (8 * i)) & 255

    def word(self, pc):
        if pc in self.patches:
            return self.patches[pc]
        # Fail closed: no fetch outside the specifically reviewed Blue functions.
        assert (0x2574c <= pc < 0x25794 or 0x37140 <= pc < 0x37148 or
                0x2639c <= pc < 0x26400 or 0x26484 <= pc < 0x264e8 or
                0x269f8 <= pc < 0x26a38 or 0x26acc <= pc < 0x26b0c or
                0x26b58 <= pc < 0x26b70 or 0x26c68 <= pc < 0x27088), hex(pc)
        data = self.pe.get_data(pc - self.base, 4)
        assert len(data) == 4
        return struct.unpack("<I", data)[0]

    def plain(self, word):
        op, rs, rt = word >> 26, (word >> 21) & 31, (word >> 16) & 31
        rd, sh, fn = (word >> 11) & 31, (word >> 6) & 31, word & 63
        imm = word & 65535
        signed = imm if imm < 32768 else imm - 65536
        r = self.reg
        if op == 0:
            if fn == 0: r[rd] = r[rt] << sh
            elif fn == 0x21: r[rd] = r[rs] + r[rt]
            elif fn == 0x23: r[rd] = r[rs] - r[rt]
            elif fn == 0x25: r[rd] = r[rs] | r[rt]
            elif fn == 0x24: r[rd] = r[rs] & r[rt]
            elif fn == 0x2b: r[rd] = int(r[rs] < r[rt])
            elif fn == 0x10: r[rd] = self.hi
            elif fn == 0x1a:
                # This slice only divides positive producer-index+1 by 25.
                assert r[rs] < 0x80000000 and 0 < r[rt] < 0x80000000
                self.lo, self.hi = divmod(r[rs], r[rt])
            else: raise ValueError(f"Unsupported SPECIAL {word:08x} at {self.pc:08x}")
        elif op == 9: r[rt] = r[rs] + signed
        elif op == 0xb: r[rt] = int(r[rs] < (signed & 0xffffffff))
        elif op == 0xc: r[rt] = r[rs] & imm
        elif op == 0xd: r[rt] = r[rs] | imm
        elif op == 0xf: r[rt] = imm << 16
        elif op in (0x20, 0x21, 0x23, 0x24, 0x25):
            size = 4 if op == 0x23 else 2 if op in (0x21, 0x25) else 1
            value = self.read((r[rs] + signed) & 0xffffffff, size)
            if op in (0x20, 0x21) and value >= 1 << (size * 8 - 1): value -= 1 << (size * 8)
            r[rt] = value
        elif op in (0x2b, 0x28): self.write((r[rs] + signed) & 0xffffffff, r[rt], 4 if op == 0x2b else 1)
        else: raise ValueError(f"Unsupported opcode {word:08x} at {self.pc:08x}")
        for i in range(1, 32): r[i] &= 0xffffffff
        r[0] = 0

    def run(self, start, stops, limit=5000):
        self.pc = start
        initial_steps = self.steps
        while self.pc not in stops:
            assert self.steps - initial_steps < limit, "Slice step limit"
            pc = self.pc
            word = self.word(pc)
            op, rs, rt, fn = word >> 26, (word >> 21) & 31, (word >> 16) & 31, word & 63
            control = op in (2, 3, 4, 5) or (op == 0 and fn in (8, 9))
            if not control:
                self.plain(word)
                self.pc += 4
                self.steps += 1
                continue
            hook = None
            if op in (4, 5):
                offset = word & 65535
                if offset >= 32768: offset -= 65536
                equal = self.reg[rs] == self.reg[rt]
                target = pc + 4 + offset * 4 if equal == (op == 4) else pc + 8
            elif op == 0:
                target = self.reg[rs]
                if fn == 9:
                    self.reg[(word >> 11) & 31] = pc + 8
                    hook = self.hooks.get(target)
                    assert hook is not None or getattr(self, "internal_call", lambda _va: False)(target), f"Unstubbed indirect call {target:x}"
            else:
                target = ((pc + 4) & 0xf0000000) | ((word & 0x3ffffff) << 2)
                if op == 3:
                    self.reg[31] = pc + 8
                    hook = self.hooks.get(target)
                    assert hook is not None or target == 0x2639c or getattr(self, "internal_call", lambda _va: False)(target), f"Unstubbed call {target:x}"
            self.pc = pc + 4
            self.plain(self.word(pc + 4))  # Architectural delay slot, also on untaken branch.
            self.steps += 2
            if hook is not None:
                self.reg[2] = hook(self) & 0xffffffff
                self.pc = pc + 8
            else:
                self.pc = target
        return self.pc


def fixture(pe, patches=None):
    vm = SliceVM(pe, patches)
    vm.reg[29] = STACK
    vm.write(HOLDER, CTX)
    vm.write(CTX + 8, 0x1234)
    vm.write(CTX + 0x330, PCM)
    vm.write(0x110f9c, CTX)
    for i in range(COUNT):
        vm.write(CTX + 0x10 + i * 32, PCM + i * SLOT)
        vm.write(CTX + 0x14 + i * 32, SLOT)
        vm.write(CTX + 0x20 + i * 32, 2)  # Prepared fixture; actual driver calls are not executed.
    for address in (0x8a820, 0x8a810, 0x8a7c0, 0x34264):
        vm.hooks[address] = lambda _vm: 0
    return vm


class Playback:
    def __init__(self, pe, threshold=11, write_result=0, restart_result=0):
        self.vm = fixture(pe, {0x27010: 0x2d2a0000 | threshold})
        self.threshold, self.write_result, self.restart_result = threshold, write_result, restart_result
        self.queued = {}
        self.copy_events = []
        self.write_events = []
        self.restart_events = []
        self.vm.hooks.update({0x85758: self.copy, 0x8a8e0: self.submit,
                              0x8a8d0: self.restart, 0x8a830: lambda _vm: 0})

    def copy(self, vm):
        dest, size = vm.reg[4], vm.reg[6]
        overlaps = [i for i, (lo, hi) in self.queued.items() if dest < hi and lo < dest + size]
        event = dict(destination_offset=dest - PCM, bytes=size, overlaps_queued_headers=overlaps,
                     outside_allocation=dest < PCM or dest + size > PCM + SLOT * COUNT)
        self.copy_events.append(event)
        # The copy wrapper returns its destination; payload bytes are represented by intervals.
        return dest

    def submit(self, vm):
        i = (vm.reg[5] - CTX - 0x10) // 32
        assert 0 <= i < COUNT and vm.reg[6] == 32
        start, size = vm.read(vm.reg[5]), vm.read(vm.reg[5] + 4)
        result = self.write_result
        self.write_events.append(dict(header=i, bytes=size, result=result,
                                      header_data_offset=start - PCM,
                                      copied_buffer_offset=vm.read(CTX + 0x330) - PCM,
                                      exceeds_prepared_length=size > SLOT))
        if result == 0:
            self.queued[i] = (start, start + size)
        return result

    def restart(self, vm):
        self.restart_events.append(dict(pending=vm.read(CTX + 5, 1), result=self.restart_result))
        return self.restart_result

    def packet(self, size):
        assert 0 < size <= 8192
        vm = self.vm
        vm.reg[16], vm.reg[18] = CTX, INPUT
        vm.write(STACK + 0x50, size)
        vm.run(0x26e98, {0x27088})  # Wave handle and both AV gates are explicit true prerequisites.

    def done(self, i):
        vm = self.vm
        self.queued.pop(i, None)
        vm.write(STACK + 0x1c, CTX + 0x10 + i * 32)
        vm.reg[20] = 0x110000
        vm.run(0x26484, {0x264e8})


def unprepare(pe, results, patched=False):
    vm = fixture(pe, {0x26ad4: 0} if patched else None)
    vm.reg[17], vm.reg[16] = CTX, 1
    calls = []
    def api(machine):
        i = (machine.reg[5] - CTX - 0x10) // 32
        assert machine.reg[6] == 32
        calls.append(i)
        return results[i]
    vm.hooks[0x8a8b0] = api
    vm.run(0x26acc, {0x26b0c})
    return calls


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    blue = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    core = next(m for m in modules if m["origin"] == "rom" and m["name"] == "coredll.dll")
    assert blue["sha256"] == BLUE_HASH
    assert core["sha256"] == "1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c"
    current, pe = source(blue, [0x2639c, 0x26400, 0x26550, 0x26628, 0x266a4, 0x26a8c,
                               0x26c68, 0x26d2c, 0x26e14, 0x85758, 0x3a750, 0x25a30,
                               0x25a5c, 0x1ace4, 0x1b87c, 0x1b1dc, 0x1cb6c, 0x1ef64,
                               0x207f4, 0x18220, 0x18260, 0x25fc8, 0x183a8, 0x2574c, 0x37140],
                              {0x25a30: 0x2c, 0x18220: 0x14, 0x18260: 0x14, 0x2574c: 0x48, 0x37140: 8})
    rom, _ = source(core, [0x4007f774, 0x4007fcfc, 0x4007fdec, 0x4007fe84, 0x4007ff3c,
                          0x40080030, 0x40080064, 0x4009e7c4, 0x4009e854, 0x4009e768], {})
    guards = {0x263cc: 0x8d49001c, 0x263d0: 0x15200004, 0x263dc: 0xae0a0330,
              0x26488: 0xac80000c, 0x264b0: 0x252a00ff, 0x264bc: 0xa1680005,
              0x26ad4: 0x1200000d, 0x26af8: 0x00408025, 0x26b6c: 0xae200008,
              0x26c18: 0x0c022a24, 0x26d54: 0xa2000338, 0x26f94: 0xad4b001c,
              0x26fb8: 0xa2090005, 0x26fd8: 0x12200009, 0x27044: 0xa2080338,
              0x27064: 0xae000334, 0x27084: 0xa2000005}
    for va, word in guards.items():
        assert struct.unpack("<I", pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == word
    table = pe.get_data(0x110330 - pe.OPTIONAL_HEADER.ImageBase, 0x4c)
    filter_slots = {12: 0x26550, 16: 0x26628, 20: 0x266a4, 24: 0x26a8c,
                    28: 0x26c68, 32: 0x26d2c, 36: 0x26e14}
    for slot, va in filter_slots.items(): assert struct.unpack_from("<I", table, slot)[0] == va
    assert struct.unpack_from("<I", table, 0x38)[0] == 0x37140
    assert struct.unpack("<I", pe.get_data(0x11031c - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x2574c
    assert struct.unpack("<I", pe.get_data(0x1102d0 - pe.OPTIONAL_HEADER.ImageBase, 4))[0] == 0x37140
    qos_cases = []
    for pool in (2, 4, 32, 53):
        for level in range(256):
            q = fixture(pe)
            q.write(CTX + 0x10, pool, 1); q.write(CTX + 0x11, 2, 1); q.write(CTX + 0x12, 53, 1)
            q.reg[4], q.reg[5], q.reg[31] = HOLDER, level, 0xdead0000
            q.run(0x2574c, {0xdead0000})
            expected = min(53, max(2, (pool - level + 4) % 256))
            assert q.read(CTX + 0x10, 1) == expected
            qos_cases.append(dict(initial=pool, level=level, updated=expected))
    for level in range(65536):
        assert (53 - level + 4) % 256 == (53 - (level & 255) + 4) % 256
    cleanup = []
    for first_success in range(26):
        results = [1 if i < first_success else 0 for i in range(25)]
        native = unprepare(pe, results)
        draft = unprepare(pe, results, True)
        # Independent first-zero oracle, including the all-errors equivalence class.
        expected = list(range(min(first_success + 1, 25)))
        assert native == expected and draft == list(range(25))
        cleanup.append(dict(first_success=first_success if first_success < 25 else None,
                            original_calls=native, draft_calls=draft))
    callbacks = []
    for pending in range(256):
        p = Playback(pe)
        p.vm.write(CTX + 5, pending, 1)
        p.vm.write(CTX + 0x1c, 1)
        p.done(0)
        actual = p.vm.read(CTX + 5, 1)
        assert actual == (pending - 1) % 256 and p.vm.read(CTX + 0x1c) == 0
        callbacks.append(dict(before=pending, after=actual))
    prefills, bursts = [], []
    for threshold in (11, 3):
        for size in (512, 1024, 2048, 4096, 8192):
            p = Playback(pe, threshold)
            while not p.restart_events: p.packet(size)
            expected = prefill(size, 20481, threshold, 44100)
            assert [r["bytes"] for r in p.write_events] == expected["queued_buffers"]
            prefills.append(dict(threshold=threshold, incoming=size, submissions=p.write_events,
                                 pcm_bytes=expected["total_pcm_bytes"]))
            while len(p.write_events) < 25: p.packet(size)
            assert p.vm.read(CTX + 5, 1) == 25 and p.vm.read(CTX + 6, 1) == 0
            p.packet(4)
            copy = p.copy_events[-1]
            assert copy["overlaps_queued_headers"] == [24] and not copy["outside_allocation"]
            assert p.vm.read(CTX + 5, 1) == 0
            p.done(0)
            assert p.vm.read(CTX + 5, 1) == 255
            for _ in range(3): p.packet(8192)
            mismatched = p.write_events[-1]
            assert mismatched["header"] == 0 and mismatched["bytes"] == 24580
            assert mismatched["header_data_offset"] == 0 and mismatched["copied_buffer_offset"] == SLOT * 24
            bursts.append(dict(threshold=threshold, incoming=size, submitted_headers=25,
                               prerequisites="No WOM_DONE handled before 25 submits and one further packet",
                               offending_copy=copy, pending_after_extra_packet=0, pending_after_done=255,
                               continuation="Only header 0 completes, then three additional 8192-byte packets",
                               mismatched_next_submission=mismatched))
    failures = []
    for threshold in (11, 3):
        p = Playback(pe, threshold, write_result=1)
        for _ in range(threshold * 3): p.packet(8192)
        assert not p.queued and len(p.write_events) == threshold
        assert len(p.restart_events) == 1 and p.vm.read(CTX + 5, 1) == threshold
        assert all(p.vm.read(CTX + 0x1c + i * 32) == 1 for i in range(threshold))
        failures.append(dict(threshold=threshold, kind="write_error_without_callback",
                             failed_writes=threshold, real_queued_headers=0, reported_pending=threshold,
                             restart_attempts=1, unreleased_dwUser_headers=list(range(threshold))))
        p = Playback(pe, threshold, restart_result=1)
        for _ in range((threshold + 2) * 3): p.packet(8192)
        assert len(p.restart_events) == 1 and p.vm.read(CTX + 0x338, 1) == 1
        failures.append(dict(threshold=threshold, kind="restart_error_without_callback",
                             successful_writes=threshold + 2, restart_attempts=1,
                             restarted_flag=1, actual_restart_result=1))
    overlap = Playback(pe)
    for _ in range(4): overlap.packet(6656)
    assert overlap.write_events[0]["bytes"] == 26624
    assert overlap.write_events[0]["exceeds_prepared_length"]
    assert not any(e["outside_allocation"] for e in overlap.copy_events)
    partial = Playback(pe)
    partial.packet(8192)
    vm = partial.vm
    vm.reg[4], vm.reg[31] = HOLDER, 0xdead0000
    vm.hooks[0x8a8c0] = lambda _vm: 0  # Successful reset, no submitted headers in this fixture.
    vm.run(0x26d2c, {0xdead0000})
    assert vm.read(CTX + 0x334) == 8192
    def format_getter(machine):
        machine.write(machine.reg[4], 2, 1)
        machine.write(machine.reg[5], 16, 1)
        machine.write(machine.reg[6], 44100, 2)
        return 0
    vm.hooks[0x193b4] = format_getter
    vm.write(CTX + 0x339, 2, 1); vm.write(CTX + 0x33a, 16, 1); vm.write(CTX + 0x33c, 44100, 2)
    vm.reg[4], vm.reg[31] = HOLDER, 0xdead0000
    vm.run(0x26c68, {0xdead0000})
    partial.packet(8192); partial.packet(8192)
    assert partial.write_events[0]["bytes"] == 24576
    close = fixture(pe)
    close.reg[17] = CTX
    close.hooks[0x8a8a0] = lambda _vm: 1
    close.run(0x26b58, {0x26b70})
    assert close.read(CTX + 8) == 0 and close.read(STACK + 0x10) == 1
    raw = (ROOT / blue["path"]).read_bytes()
    offset = pe.get_offset_from_rva(0x26ad4 - pe.OPTIONAL_HEADER.ImageBase)
    draft = bytearray(raw)
    assert draft[offset:offset + 4] == struct.pack("<I", guards[0x26ad4])
    draft[offset:offset + 4] = bytes(4)
    changed = [i for i, (a, b) in enumerate(zip(raw, draft)) if a != b]
    assert changed == [offset, offset + 3]
    evidence = dict(sources=[current, rom], documentation=SOURCES,
        scope="Bounded byte interpretation with mocked OS, memcpy intervals and explicit callback scheduling; no native execution",
        checks=dict(original_ranges=len(current["ranges"]) + len(rom["ranges"]),
                    exact_preimages=len(guards), filter_function_slots=len(filter_slots), unprepare_return_classes=26,
                    qos_byte_interpretation_cases=len(qos_cases), qos_word_periodicity_cases=65536,
                    callback_byte_values=256, prefill_oracle_cases=10, full_ring_witnesses=10,
                    error_witnesses=4, partial_stop_start_witnesses=1, failed_close_witnesses=1),
        cleanup=cleanup, callbacks=callbacks, prefills=prefills, full_ring=bursts, errors=failures,
        qos=dict(winplay_and_sink="0x37140 jr ra / nop: no adjustment", sbc="0x2574c",
                 sbc_formula="updated = clamp((old - WORDlevel + 4) modulo 256, min, max), for valid min <= max",
                 decoder_use="Field +10 consumption in the negotiated decoder is not established here",
                 cases=qos_cases),
        filter_table=dict(va="0x110330", bytes=len(table), raw_hex=table.hex(),
                          sha256=hashlib.sha256(table).hexdigest(), slots={hex(k): hex(v) for k, v in filter_slots.items()},
                          chain_installer="0x25a30: SBC decoder -> WinPlay -> sink terminator",
                          lifecycle="0 init; 1 deinit; 2 open; 3 close (stops first when running); 4 start; 5 stop",
                          incoming_start="0x1ace4: gate +11d=0; stop/close/open/start; gate +11d=1",
                          reconfigure="0x1b87c: gate +11d=0; opcode 3 (close despite STOP log); open; gate +11d=1",
                          playback_gates="0x18220/0x18260 read shared AV +11c/+11d, not WinPlay state +4"),
        prepared_length_witness=dict(incoming_pcm_bytes=6656, submitted_bytes=26624, prepared_bytes=25600,
                                     within_total_allocation=True, decoded_packet_reachability="Not established for this negotiated SBC/transport"),
        partial_stop_start=dict(unsubmitted_before_stop=8192, after_stop=8192, after_same_format_start=8192,
                                next_submission_bytes=24576, includes_pre_stop_pcm_bytes=8192,
                                outer_lifecycle="Incoming StartInd 0x1ace4 explicitly closes/reopens; this isolated stop/start trace does not prove stale PCM on the normal phone-resume path"),
        failed_close=dict(result=1, context_handle_after=0, original_handle=0x1234,
                          driver_state="Unmodeled; code loses handle regardless of the nonzero close result"),
        unprepare_draft=dict(binary_written=False, integrated_into_MAX01=False, va="0x26ad4", offset=hex(offset),
                             before_hex=struct.pack("<I", guards[0x26ad4]).hex(), after_hex="00000000",
                             memory_only_sha256=hashlib.sha256(draft).hexdigest(), changed_byte_offsets=changed,
                             effect="Remove premature success exit; attempt each of 25 headers once",
                             limitations="WAM close can automatically clean remaining prepared proxies when none is queued; this branch-only draft does not repair failed unprepare, close, reset, forced thread termination or queue ownership"),
        open_points=["All filter lifecycle callers and real AV gate transitions",
                     "Full wave manager and OEM queue completion, lock and timeout paths",
                     "Actual unit scheduling, errors, negotiated SBC packet lengths and audio measurements",
                     "Cooperative thread shutdown and definitive repair bytes remain to design/validate"])
    out = ROOT / "analysis/firmware/bt-lifecycle"
    out.mkdir(parents=True, exist_ok=True)
    evidence["producer_sha256"] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    (out / "contracts.json").write_text(json.dumps(evidence, indent=2), encoding="utf-8")
    lines = []
    for item in (current, rom):
        starts = [(int(r["va"], 16), int(r["va"], 16) + r["bytes"]) for r in item["ranges"]]
        path = ROOT / "analysis/disassembly" / ("rom" if item["origin"] == "rom" else "") / (item["module"] + ".asm")
        lines.append(f"; {item['module']} {item['sha256']}\n")
        for line in path.read_text(encoding="utf-8").splitlines(keepends=True):
            try: address = int(line[:8], 16)
            except ValueError: continue
            if any(lo <= address < hi for lo, hi in starts): lines.append(line)
    (out / "reviewed-paths.asm").write_text("".join(lines), encoding="utf-8")
    print(json.dumps(dict(status="passed", **evidence["checks"], unprepare_draft=evidence["unprepare_draft"]), indent=2))


if __name__ == "__main__":
    main()
