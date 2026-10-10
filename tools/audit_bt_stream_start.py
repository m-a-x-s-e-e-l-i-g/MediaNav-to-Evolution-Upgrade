"""Read-only StartInd audit: interpret bytes; filter outcomes are explicit fixtures.

Never executes firmware natively or changes an executable/build/release.
"""
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools/python-libs"))
import pefile
from inspect_wave_queue import BytesVM, STOP

ENTRY, END = 0x1ace4, 0x1b088
ORIGINAL_HASH = "5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b"
CURRENT_HASH = "86db75416ce9196412a3c46c1036da3aa151eacc409f7c22db3461e81fe3308a"
GLOBAL, AV, REMOTE, IND, IDS, RESPONSE = [0x47000000 + i * 0x1000 for i in range(6)]


class StartVM(BytesVM):
    def plain(self, word):
        op, fn = word >> 26, word & 63
        rs, rt = (word >> 21) & 31, (word >> 16) & 31
        if op == 0 and fn == 0x18:
            # Both actual multiplications here are bounded unsigned stream indices.
            assert self.reg[rs] < 0x80000000 and self.reg[rt] < 0x80000000
            product = self.reg[rs] * self.reg[rt]
            self.lo, self.hi = product & 0xffffffff, product >> 32
        elif op == 0 and fn == 0x12:
            self.reg[(word >> 11) & 31] = self.lo
        elif op == 0x29:
            imm = word & 65535
            signed = imm if imm < 32768 else imm - 65536
            self.write((self.reg[rs] + signed) & 0xffffffff, self.reg[rt], 2)
        else:
            super().plain(word)


def case(pe, name, outcomes, gate=1, state=2):
    vm = StartVM(pe, [(ENTRY, END)])
    vm.write(0x20e1e8, GLOBAL)
    vm.write(GLOBAL + 0x268, AV)
    vm.write(GLOBAL + 0x26c, REMOTE)
    vm.write(AV + 0x27, 7, 1)
    vm.write(AV + 0x21, state, 1)
    vm.write(AV + 0x11c, gate, 1)
    vm.write(IND + 2, 9, 1)
    vm.write(IND + 3, 1, 1)
    vm.write(IND + 4, IDS)
    vm.write(IDS, 7, 1)
    stack = vm.reg[29]
    saved = {i: 0x12340000 + i for i in (*range(16, 24), 30)}
    for i, value in saved.items():
        vm.reg[i] = value
    vm.reg[4:7] = [GLOBAL, AV, IND]
    calls, messages, responses = [], [], []

    def wrapped(fn):
        def hook(machine):
            result = fn(machine)
            for i in (1, *range(3, 16), 24, 25):
                machine.reg[i] = 0xaabb0000 + i
            return result
        return hook

    def filters(machine):
        opcode = machine.reg[6]
        assert machine.reg[4:6] == [0x47100000, AV]
        assert opcode in (5, 3, 2, 4)
        calls.append(dict(opcode=opcode, result=outcomes.get(opcode, 1)))
        return outcomes.get(opcode, 1)

    def emit(machine):
        messages.append(list(machine.reg[4:7]))
        return 1

    def respond(machine):
        assert machine.reg[4] == RESPONSE
        responses.append(dict(type=machine.read(RESPONSE, 2),
                              error=machine.read(RESPONSE + 0xc, 1)))
        return 0

    def allocate(machine):
        assert machine.reg[4] == 16
        return RESPONSE

    vm.hooks = {address: wrapped(fn) for address, fn in {
        0x259f8: lambda _: 0x47100000,
        0x25a5c: filters, 0x8a7c0: lambda _: 0,
        0x34264: lambda _: 0, 0x85b70: allocate,
        0x7815c: respond, 0x33538: emit,
    }.items()}
    vm.run(ENTRY, {STOP}, limit=3000)
    assert vm.reg[29] == stack
    assert all(vm.reg[i] == value for i, value in saved.items())
    rejected = state != 2
    assert calls == ([] if not gate or rejected else [
        dict(opcode=op, result=outcomes.get(op, 1)) for op in (5, 3, 2, 4)])
    assert responses == [dict(type=0x1a, error=0x31 if rejected else 0)]
    assert vm.read(AV + 0x21, 1) == (state if rejected else 3)
    assert vm.read(AV + 0x11d, 1) == int(bool(gate) and not rejected)
    assert messages == ([] if rejected else [[2, 0x3070801, 0], [2, 0x3071101, 1]])
    return dict(name=name, audio_requested=gate, filter_calls=calls,
                response=responses, app_messages=messages,
                av_state=vm.read(AV + 0x21, 1),
                output_flag=vm.read(AV + 0x11d, 1),
                play_state=vm.read(REMOTE + 0x218, 1),
                instructions=vm.steps)


def main():
    paths = {
        "original": ROOT / "extracted/705md/upgrade/Storage Card/System/Blue.exe",
        "published_MAX03": ROOT / "build/maxmade-7.0.6.MAX03/payload/upgrade/Storage Card/System/Blue.exe",
        "current_development": ROOT / "build/usb-option-snapshot-development-01/payload/upgrade/Storage Card/System/Blue.exe",
    }
    result, original_slice = {}, None
    for label, path in paths.items():
        raw = path.read_bytes()
        digest = hashlib.sha256(raw).hexdigest()
        assert digest == (ORIGINAL_HASH if label == "original" else CURRENT_HASH)
        pe = pefile.PE(data=raw)
        block = pe.get_data(ENTRY - pe.OPTIONAL_HEADER.ImageBase, END - ENTRY)
        assert len(block) == END - ENTRY
        if original_slice is None:
            original_slice = block
        assert block == original_slice, "Audited routine changed from original"
        traces = [case(pe, name, outcomes, gate, state) for name, outcomes, gate, state in [
            ("success", {}, 1, 2),
            ("open_and_start_failure", {2: 0, 4: 0}, 1, 2),
            ("start_failure", {4: 0}, 1, 2),
            ("stop_failure", {5: 0}, 1, 2),
            ("close_failure", {3: 0}, 1, 2),
            ("audio_not_requested", {}, 0, 2),
            ("wrong_stream_state", {}, 1, 1),
        ]]
        result[label] = dict(path=str(path.relative_to(ROOT)), sha256=digest,
                             routine_sha256=hashlib.sha256(block).hexdigest(), cases=traces)
    report = dict(scope="Read-only bounded MIPS StartInd interpretation. Filter/API/transport outcomes are fixtures, not hardware evidence or an incident reproduction.",
                  conclusion="Open/start failure still reaches successful start response, AV state 3, shared output flag 1 and AppMain stream notifications when audio is requested. Original, published and development routine bytes are identical.",
                  cases=21, modules=result,
                  tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    out = ROOT / "analysis/firmware/bt-stream-start-audit.json"
    out.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(cases=report["cases"], report=str(out), conclusion=report["conclusion"])))


if __name__ == "__main__":
    main()
