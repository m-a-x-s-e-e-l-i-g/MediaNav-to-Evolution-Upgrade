"""Interpret complete AppMain WndProc entry/exit for reconnect timers.

OS, GUI delegation and radio are fixtures. No CE binary is executed or written.
"""
import hashlib
import json
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, MANAGER, abi, put
from verify_bt_pairing_ui import UIVM, COORDINATOR, STATE, COOKIE, DIALOG, VTABLE, CONTROL_API
from verify_bt_pairing_confirmation import PROGRESS, GUI, DIALOG_LIST
from draft_bt_pairing_storage import draft_app_pairing, PAIRS

RANGES = [(0x13120c, 0x1347ec), (0x127654, 0x1276b0),
          (0x11b464, 0x11b5c8), (0x1144b4, 0x114518), (0x12c10, 0x12cf8),
          (0x130a70, 0x130ab0), (0x1362c4, 0x136494), (0x1356a8, 0x135778),
          (0x134c50, 0x134d28), (0x12d294, 0x12d2c8), (0x12a174, 0x12a17c)]
RANGES += [(0x11cb00, 0x11e370)]
APP_CONTEXT = 0x5e000000
MESSAGE = 0x5f000000
ERROR_API, DEBUG_API, PARENT_API = 0xf0060010, 0xf0060020, 0xf0060030
FIELDS = (0x174, 0x17c, 0x5a4, 0x5a8, 0x5ac, 0x5fc, 0x66c, 0x698)


class Reconnect:
    def __init__(self, pe, count, initial=1, phase=0, counter=0, connected=False,
                 active=True, outcome="success", timer_success=True):
        self.vm = UIVM(pe, RANGES)
        self.original_retry_id = pe.get_data(0x11b57c - pe.OPTIONAL_HEADER.ImageBase, 4) == bytes.fromhex("65800534")
        self.events, self.outcome, self.timer_success = [], outcome, timer_success
        vm = self.vm
        for at, val in [(0x187be4, MANAGER), (MANAGER + 0xa0, OBJECT),
                        (MANAGER + 0xa4, COORDINATOR), (MANAGER + 0xa8, STATE),
                        (0x186ce8, GUI), (GUI + 4, 0x7777), (0x187b38, APP_CONTEXT),
                        (0x1860fc, DIALOG_LIST), (0x186100, 1), (DIALOG_LIST, DIALOG),
                        (DIALOG, VTABLE), (DIALOG + 0x74, PROGRESS), (0x188420, PROGRESS),
                        (VTABLE, CONTROL_API), (VTABLE + 0x64, PARENT_API),
                        (DIALOG + 0x50, 0x9999), (DIALOG + 0x80, 1),
                        (PROGRESS, 0x17b12c), (PROGRESS + 0x50, 0x8888),
                        (PROGRESS + 0x2c8, DIALOG), (PROGRESS + 0x2cc, 3),
                        (PROGRESS + 0x4c, 0x8889), (PROGRESS + 0x54, 0x888a), (PROGRESS + 0x58, 0x888b),
                        (OBJECT + 0x26c, count),
                        (STATE + 0x618, int(connected)), (STATE + 0x174, 1),
                        (STATE + 0x17c, int(active)), (STATE + 0x5a4, counter),
                        (STATE + 0x5a8, initial), (STATE + 0x5ac, phase),
                        (STATE + 0x5fc, 1), (STATE + 0x698, 1), (STATE + 0x66c, 1),
                        (STATE + 0x6d4, int(outcome != "disabled")),
                        (COORDINATOR + 8, 0x9876), (COORDINATOR + 0x14, 2),
                        (0x1853f4, COOKIE), (0x185020, ERROR_API), (0x1852bc, DEBUG_API),
                        (APP_CONTEXT + 0xe8, 0xabcdef01)]:
            vm.write(at, val)
        put(vm, 0x17b12c, pe.get_data(0x17b12c - pe.OPTIONAL_HEADER.ImageBase, 0x68))
        vm.hooks.update({0x14638: lambda _: 0, 0x1103c: lambda _: 0,
                         0x13fef8: self.kill, 0x13ff08: self.timer,
                         0x1400a8: self.send, 0x140038: self.find, ERROR_API: self.error,
                         DEBUG_API: lambda _: 0, CONTROL_API: self.parent_close,
                         PARENT_API: self.parent_callback, 0x140298: self.cookie,
                         **{at: self.api(at) for at in (0x140c44, 0x140018, 0x140198, 0x140138, 0x1400e8, 0xe7c90)}})

    def state(self):
        return {hex(off): hex(self.vm.read(STATE + off)) for off in FIELDS}

    def clobber(self, machine):
        for reg in (*range(2, 16), 24, 25): machine.reg[reg] = 0xcafe0000 + reg

    def kill(self, machine):
        assert machine.reg[4] in (0x7777, 0x8888, 0x9999)
        self.events.append(dict(kind="kill", hwnd=hex(machine.reg[4]), timer=hex(machine.reg[5])))
        self.clobber(machine); return 1

    def timer(self, machine):
        assert machine.reg[4] == 0x7777 and machine.reg[7] == 0
        assert (machine.reg[5], machine.reg[6]) in ((0x416, 25000), (0x417, 25000),
                                                  (0x416, 10), (0x417, 1000), (0x41a, 10000))
        result = machine.reg[5] if self.timer_success else 0
        self.events.append(dict(kind="timer", timer=hex(machine.reg[5]), ms=machine.reg[6], return_value=result))
        self.clobber(machine); return result

    def send(self, machine):
        retry = bool(self.events and self.events[-1]["kind"] == "find")
        message_id = 0x8065 if self.original_retry_id and retry else 0x8070
        assert machine.reg[4:7] == [0x9876, message_id, 0x1010804]
        assert machine.read(machine.reg[29] + 0x14) == 1500
        parameter = machine.reg[7]
        self.events.append(dict(kind="send", index=parameter, message_id=hex(message_id), state=self.state()))
        machine.write(machine.read(machine.reg[29] + 0x18), 0xaabbccdd)
        attempt = sum(e["kind"] == "send" and e["index"] == parameter for e in self.events)
        result = int(self.outcome == "success" or self.outcome == "recovered" and attempt % 2 == 0)
        self.clobber(machine); return result

    def find(self, machine):
        self.events.append(dict(kind="find")); self.clobber(machine); return 0x9876

    def error(self, machine):
        result = 5 if self.outcome == "error" else 0x578
        self.events.append(dict(kind="error", code=hex(result)))
        self.clobber(machine); return result

    def parent_close(self, machine):
        assert machine.reg[4] == DIALOG
        self.events.append(dict(kind="parent-close", scope="GUI virtual method hook")); return 0

    def parent_callback(self, machine):
        assert machine.reg[4:6] == [DIALOG, 0]
        self.events.append(dict(kind="parent-callback", scope="GUI virtual method hook")); return 0

    def api(self, at):
        def hooked(machine):
            self.events.append(dict(kind="api", va=hex(at), arguments=machine.reg[4:6].copy()))
            self.clobber(machine); return 1
        return hooked

    def cookie(self, machine):
        assert machine.reg[4] == COOKIE
        self.events.append(dict(kind="cookie")); return 0

    def tick(self, timer):
        before, start = self.state(), len(self.events)
        self.vm.reg[5:8] = [0x113, timer, 0]
        abi(self.vm, 0x13120c, 0x7777)
        assert self.vm.reg[2] == 0
        events = self.events[start:]
        assert sum(e["kind"] == "cookie" for e in events) == 1
        return dict(timer=hex(timer), before=before, after=self.state(), events=events,
                    progress_window=hex(self.vm.read(PROGRESS + 0x50)), parent_popup=hex(self.vm.read(DIALOG + 0x74)),
                    abi_preserved=True)

    def response(self):
        before, start = self.state(), len(self.events)
        for off, value in enumerate((0, 0, 0x4010507, 0, 0)):
            self.vm.write(MESSAGE + off * 4, value)
        self.vm.reg[5] = MESSAGE
        abi(self.vm, 0x11cb00, COORDINATOR)
        events = self.events[start:]
        assert sum(e["kind"] == "cookie" for e in events) == 1
        return dict(command="0x4010507", before=before, after=self.state(), events=events,
                    abi_preserved=True, scope="Native FAIL_IND dispatch with synthetic radio indication")


def chain(pe, timer, count, initial=1, counter=0, outcome="success", timer_success=True, with_responses=False):
    fixture = Reconnect(pe, count, initial=initial, counter=counter, outcome=outcome, timer_success=timer_success)
    traces = []
    response_traces = []
    if with_responses:
        assert timer == 0x417
        fixture.vm.write(STATE + 0x174, 0)
        fixture.vm.write(STATE + 0x61c, 1)
        fixture.vm.write(APP_CONTEXT + 0xe8, 0)
        response_traces.append(fixture.response())
        assert any(e["kind"] == "timer" and e["timer"] == "0x417" and e["ms"] == 1000
                   for e in response_traces[0]["events"])
    for _ in range(PAIRS + 2):
        trace = fixture.tick(timer); traces.append(trace)
        if not any(e["kind"] == "timer" and e["return_value"] for e in trace["events"]):
            break
        if with_responses:
            response_traces.append(fixture.response())
            assert not any(e["kind"] == "timer" for e in response_traces[-1]["events"])
    else:
        raise AssertionError("Reconnect did not stop within the eight-slot bound")
    attempts = [e["index"] for trace in traces for e in trace["events"] if e["kind"] == "send"]
    result = dict(timer=hex(timer), count=count, initial=initial, counter=counter, outcome=outcome,
                  timer_success=timer_success, attempts=attempts, ticks=traces, final_state=fixture.state(),
                  response_traces=response_traces)
    return result


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    sources, original = source(module, [a for a, _ in RANGES if a != 0x12a174], {0x12a174: 8})
    raw = (ROOT / module["path"]).read_bytes()
    draft, patch = draft_app_pairing(raw)
    pe = pefile.PE(data=draft)
    original_416, original_417, draft_416, draft_417 = [], [], [], []
    for count in range(PAIRS + 1):
        for counter in (0, 1):
            before = chain(original, 0x416, count, counter=counter)
            assert before["attempts"] == list(range(counter + 1, min(count, 5) + 1))
            original_416.append(before)
            repaired = chain(pe, 0x416, count, counter=counter)
            assert repaired["attempts"] == list(range(counter + 1, count + 1))
            assert repaired["final_state"]["0x174"] == "0x0"
            draft_416.append(repaired)
        for initial in range(1, count + 1):
            before = chain(original, 0x417, count, initial)
            expected = ([] if count < 2 else [3 - initial] if count == 2 else
                        [2, 3] if initial == 1 else [3, 1] if initial == 2 else [1, 2])
            assert before["attempts"] == expected, before
            original_417.append(before)
            repaired = chain(pe, 0x417, count, initial)
            assert repaired["attempts"] == [*range(initial + 1, count + 1), *range(1, initial)]
            assert len(set(repaired["attempts"])) == max(0, count - 1)
            assert all(repaired["final_state"][hex(off)] == "0x0" for off in (0x17c, 0x5a8, 0x5ac, 0x5fc, 0x698))
            assert repaired["ticks"][-1]["progress_window"] == "0x0"
            assert repaired["ticks"][-1]["parent_popup"] == "0x0"
            draft_417.append(repaired)
    original_failures = [chain(original, timer, PAIRS, initial=1, outcome=mode)
                         for timer in (0x416, 0x417) for mode in ("error", "timeout", "disabled")]
    failure_traces = []
    for timer in (0x416, 0x417):
        for initial in range(1, PAIRS + 1):
            for mode in ("error", "timeout", "disabled", "recovered"):
                repaired = chain(pe, timer, PAIRS, initial=initial, counter=initial - 1, outcome=mode)
                if mode != "recovered":
                    assert len(repaired["ticks"]) == 1
                    assert len(repaired["attempts"]) == (0 if mode == "disabled" else 2 if mode == "timeout" else 1)
                    assert not any(e["kind"] == "timer" for e in repaired["ticks"][0]["events"])
                assert repaired["final_state"]["0x174"] == "0x0"
                if timer == 0x417:
                    assert repaired["final_state"]["0x17c"] == "0x0"
                else:
                    assert any(e["kind"] == "parent-close" for e in repaired["ticks"][-1]["events"])
                failure_traces.append(repaired)
    timer_failures = [chain(pe, timer, PAIRS, initial=initial, counter=initial - 1, timer_success=False)
                      for timer in (0x416, 0x417) for initial in range(1, PAIRS + 1)]
    for trace in timer_failures:
        assert len(trace["ticks"]) == len(trace["attempts"]) == 1
        assert trace["final_state"]["0x174"] == "0x0"
        if trace["timer"] == "0x417": assert trace["final_state"]["0x17c"] == "0x0"
        else: assert any(e["kind"] == "parent-close" for e in trace["ticks"][-1]["events"])
    guard_cases = []
    for count, initial, phase in [(0, 0, 0), (9, 1, 0), (0xffffffff, 1, 0),
                                  (8, 0, 0), (8, 9, 0), (8, 0xffffffff, 0),
                                  (8, 1, 9), (8, 1, 0xffffffff), (8, 1, 1)]:
        fixture = Reconnect(pe, count, initial, phase)
        trace = fixture.tick(0x417)
        assert not any(e["kind"] in ("send", "timer") for e in trace["events"])
        assert trace["after"]["0x17c"] == "0x0"
        guard_cases.append(dict(count=hex(count), initial=hex(initial), phase=hex(phase), trace=trace))
    for counter in (8, 9, 0x7fffffff, 0xffffffff):
        fixture = Reconnect(pe, PAIRS, counter=counter)
        trace = fixture.tick(0x416)
        assert not any(e["kind"] in ("send", "timer") for e in trace["events"])
        assert trace["after"]["0x174"] == "0x0"
        guard_cases.append(dict(counter=hex(counter), trace=trace))
    for count in (9, 0xffffffff):
        fixture = Reconnect(pe, count)
        trace = fixture.tick(0x416)
        assert not any(e["kind"] in ("send", "timer") for e in trace["events"])
        assert trace["after"]["0x174"] == "0x0"
        guard_cases.append(dict(timer="0x416", count=hex(count), trace=trace))
    passive_traces = []
    for connected in (False, True):
        for active in (False, True):
            fixture = Reconnect(pe, PAIRS, connected=connected, active=active)
            trace = fixture.tick(0x417)
            assert any(e["kind"] == "send" for e in trace["events"]) == (active and not connected)
            if not active: assert trace["before"] == trace["after"]
            passive_traces.append(dict(connected=connected, active=active, trace=trace))
    for counter in (0, 7):
        fixture = Reconnect(pe, PAIRS, counter=counter, connected=True)
        trace = fixture.tick(0x416)
        assert not any(e["kind"] in ("send", "timer") for e in trace["events"])
        assert trace["after"]["0x174"] == "0x0"
        passive_traces.append(dict(timer="0x416", connected=True, counter=counter, trace=trace))
    abort_sentinel = dict(va="0x11e0cc", original_hex=original.get_data(0x11e0cc - original.OPTIONAL_HEADER.ImageBase, 8).hex(),
                          draft_hex=pe.get_data(0x11e0cc - pe.OPTIONAL_HEADER.ImageBase, 8).hex())
    assert abort_sentinel["original_hex"] == "06000a24a4050aad"
    assert abort_sentinel["draft_hex"] == "09000a24a4050aad"
    response_chains = [chain(pe, 0x417, count, initial, with_responses=True)
                       for count in range(1, PAIRS + 1) for initial in range(1, count + 1)]
    for trace in response_chains:
        assert trace["attempts"] == [*range(trace["initial"] + 1, trace["count"] + 1), *range(1, trace["initial"])]
        assert len(trace["response_traces"]) == trace["count"]
    response_gates = []
    for phase in range(PAIRS + 1):
        for ready in (0, 1):
            for connected in (False, True):
                for active in (False, True):
                    fixture = Reconnect(pe, PAIRS, phase=phase, connected=connected, active=active)
                    fixture.vm.write(STATE + 0x61c, ready)
                    fixture.vm.write(STATE + 0x174, 0)
                    trace = fixture.response()
                    timers = [e for e in trace["events"] if e["kind"] == "timer"]
                    assert bool(timers) == (ready == 1 and not connected and active and phase == 0)
                    assert trace["before"]["0x5ac"] == trace["after"]["0x5ac"]
                    response_gates.append(dict(phase=phase, ready=ready, connected=connected, active=active, trace=trace))
    response_abort_pairs = []
    for flag in (0, 1):
        traces = []
        for test_pe, sentinel in ((original, 6), (pe, 9)):
            fixture = Reconnect(test_pe, PAIRS, counter=1)
            fixture.vm.write(STATE + 0x61c, 1)
            fixture.vm.write(APP_CONTEXT + 0xe8, flag)
            trace = fixture.response()
            assert trace["after"]["0x5a4"] == hex(sentinel if flag else 1)
            assert [e["timer"] for e in trace["events"] if e["kind"] == "timer"] == ["0x41a" if flag else "0x416"]
            followup = fixture.tick(0x416)
            sends = [e["index"] for e in followup["events"] if e["kind"] == "send"]
            assert sends == ([] if flag else [2])
            trace["timer_416_followup"] = followup
            traces.append(trace)
        response_abort_pairs.append(dict(app_flag=flag, original=traces[0], draft=traces[1]))
    out = ROOT / "analysis/firmware/bt-reconnect-draft"; out.mkdir(parents=True, exist_ok=True)
    dependencies = ["verify_bt_reconnect.py", "verify_bt_pairing_confirmation.py", "verify_bt_pairing_ui.py",
                    "verify_bt_database_io.py", "verify_bt_pairing_storage.py", "draft_bt_pairing_storage.py",
                    "draft_bt_database_io.py", "patch_bt_playback.py", "inspect_bt_pairing.py",
                    "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Timer-416/eight-index cyclic timer-417 and transport/timer failure guards passed in interpreter",
                  native_execution=False, unit_tested=False, build_allowed=False, sources=sources,
                  patch_sha256=patch["draft_sha256"], original_416=original_416, original_417=original_417,
                  draft_416=draft_416, draft_417=draft_417, original_failures=original_failures,
                  failure_traces=failure_traces, timer_creation_failures=timer_failures,
                  guard_cases=guard_cases, passive_traces=passive_traces, abort_sentinel=abort_sentinel,
                  response_chains=response_chains, response_gates=response_gates, response_abort_pairs=response_abort_pairs,
                  limitations=["OS/timers, initial GUI delegation and parent virtual method are explicit hooks",
                               "No radio, scheduler, popup constructor, firmware write or end-to-end reconnect",
                               "Native FAIL_IND routing is covered; success/profile callbacks and concurrent record-order changes remain open",
                               "Timer-416 completion's parent virtual method is a hook; its real popup cleanup remains open"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], original_416=len(original_416), original_417=len(original_417),
                         draft_416=len(draft_416), draft_417=len(draft_417), failure_traces=len(failure_traces),
                         timer_creation_failures=len(timer_failures), guard_cases=len(guard_cases),
                         response_chains=len(response_chains), response_gates=len(response_gates)), indent=2))


if __name__ == "__main__": main()
