"""Pinned AppMain constructor/send -> Blue WndProc/list -> OS out-status.

The bridge is a synchronous OS fixture, not a CE scheduling/reentrancy test.
Firmware instructions are interpreted; no executable or update is emitted.
"""
import hashlib
import json
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import MANAGER, OBJECT, STACK, abi, put, data
from inspect_wave_queue import STOP
from verify_bt_pairing_ui import UIVM, STATE, COORDINATOR, SHARED
from verify_bt_pairing_confirmation import pe_string
from verify_bt_list_publication import case, APP_RANGES as LIST_CALLBACK_RANGES, EXTRA as PUBLICATION_RANGES
from verify_bt_connection_success import Success, EXTRA as SUCCESS_RANGES
from verify_bt_reconnect import DEBUG_API, RANGES as RECONNECT_RANGES
from draft_bt_pairing_storage import draft_blue_storage, draft_app_pairing

APP_RANGES = [(0x11b39c, 0x11b464), (0x11b464, 0x11b5c8), (0x1144b4, 0x114518)]
ERROR_API = 0xf0090010


def request(blue, app, count, fault=False):
    vm = UIVM(app, APP_RANGES)
    allocations, sends, windows = [], [], []
    def clobber(machine):
        for reg in (*range(2, 16), 24, 25): machine.reg[reg] = 0xcafe0000 + reg
    def allocate(machine):
        assert machine.reg[4] == 0x48
        allocations.append(0x48); clobber(machine); return COORDINATOR
    def find(machine):
        assert (pe_string(app, machine.reg[4]), machine.reg[5]) == ("BLUE", 0)
        windows.append("BLUE"); clobber(machine); return 0x7777
    def send(machine):
        assert machine.reg[4:8] == [0x7777, 0x8070, 0x1010702, 0]
        assert machine.read(machine.reg[29] + 0x14) == 1500
        outcome = case(blue, app, count, read_error=fault, receiver=True)
        assert outcome["returned_status"] == 0
        machine.write(machine.read(machine.reg[29] + 0x18), outcome["returned_status"])
        sends.append(dict(window_message="0x8070", command="0x1010702", receiver=outcome))
        clobber(machine); return 1
    vm.write(0x186780, 0)
    vm.hooks.update({0x1402f0: allocate, 0x140038: find, 0x1400a8: send,
                     ERROR_API: lambda _: 5})
    abi(vm, 0x11b39c, 0)
    assert vm.reg[2] == COORDINATOR and vm.read(0x186780) == COORDINATOR
    assert vm.read(COORDINATOR + 0x14) == 2
    vm.write(0x187be4, MANAGER); vm.write(MANAGER + 0xa8, STATE)
    vm.write(STATE + 0x6d4, 1); vm.write(0x185020, ERROR_API)
    vm.reg[5:8] = [1, 0x1010702, 0]
    abi(vm, 0x11b464, COORDINATOR)
    assert vm.reg[2] == 0 and len(sends) == 1
    return dict(count=count, database_fault=fault, manager_kind=2, wrapper_status=0,
                constructor_allocations=allocations, window_lookups=windows, sends=sends,
                finding="OS/wrapper/LRESULT are zero-success regardless of whether DB refresh published a list")


def ignored_message(blue):
    vm = UIVM(blue, [(0x33d34, 0x33f90), (0x2e644, 0x2e67c), (0x30280, 0x302a8)])
    vm.write(0x20e1e8, MANAGER); vm.write(MANAGER + 0x288, 1, 1)
    vm.write(0x20e1f0, COORDINATOR)
    vm.reg[5:8] = [0x8065, 0x1010702, 0]
    abi(vm, 0x33d34, 0x7777)
    assert vm.reg[2] == 0
    return dict(window_message="0x8065", returned_status=0,
                finding="Original Blue WndProc does not dispatch this ordinary message; interpreted with no GUI/list hooks")


class HFSnapshot(Success):
    def __init__(self, blue, app, selected, fault=False, call_popup=False):
        super().__init__(app, 8, selected, call_popup=call_popup)
        self.blue, self.fault = blue, fault
        self.list_success = False  # Sleep never fabricates publication here.
        self.vm.write(COORDINATOR + 0x14, 2)
        self.receiver_traces = []

    def list_callback(self, bank, count):
        put(self.vm, SHARED, bank)
        vm = UIVM(self.pe, LIST_CALLBACK_RANGES)
        vm.mem = self.vm.mem
        message = 0x65000000
        vm.write(message + 8, 0x4010702); vm.write(message + 0xc, count)
        vm.hooks = {DEBUG_API: lambda _: 0, 0x1f0a4: lambda _: 0x60000000,
                    0xd0794: lambda _: 0, 0xcfcb8: lambda _: 0,
                    0x1291c0: lambda _: 0x66000000}
        # A distinct fixture stack emulates saved CPU context during OS callback;
        # the interrupted VM registers and outer message remain untouched.
        vm.reg[4:6] = [COORDINATOR, message]
        vm.reg[29] = STACK - 0x10000; vm.reg[31] = STOP
        saved = {r: 0xa5000000 + r for r in (*range(16, 24), 28, 30)}
        for r, value in saved.items(): vm.reg[r] = value
        vm.run(0x121630, {STOP})
        assert vm.reg[29] == STACK - 0x10000
        assert all(vm.reg[r] == value for r, value in saved.items())
        self.events.append(dict(kind="native-list-callback", count=count,
                                active_index=vm.read(OBJECT + 0x5a4)))

    def send(self, machine):
        assert machine.reg[4:6] == [0x9876, 0x8070]
        if machine.reg[6] == 0x1041401:
            assert machine.reg[7] == 0
            self.events.append(dict(kind="send", command="0x1041401", parameter=0,
                                    scope="Additional profile query transport fixture; receiver unexecuted"))
            machine.write(machine.read(machine.reg[29] + 0x18), 0)
            self.clobber(machine); return 1
        assert machine.reg[6:8] == [0x1010702, 0], [hex(x) for x in machine.reg[4:8]]
        trace = case(self.blue, self.pe, 8, read_error=self.fault, receiver=True,
                     initial_selected=self.selected)
        self.receiver_traces.append(trace)
        self.events.append(dict(kind="send", command="0x1010702", parameter=0,
                                receiver_status=trace["returned_status"], logical_failure=bool(self.fault)))
        # Coupled message/shared-memory bridge: callback only when actual Blue
        # publication instructions reached a successful notification fixture.
        bank = b"".join(bytes.fromhex(rec["bytes_hex"]) for rec in trace["copied_records"])
        for notification in trace["notifications"]:
            if notification["transport_success"]:
                assert len(bank) == notification["low_count"] * 64
                self.list_callback(bank, notification["low_count"])
        machine.write(machine.read(machine.reg[29] + 0x18), trace["returned_status"])
        self.list_requested = True
        self.clobber(machine); return 1  # OS transport success, despite DB failure.


def hf_snapshot(blue, app, selected, fault=False, call_popup=False):
    f = HFSnapshot(blue, app, selected, fault, call_popup)
    before = data(f.vm, SHARED, 8 * 64)
    trace = f.indication(0x3040101)
    opens = [e["path"] for e in trace["events"] if e["kind"] == "file-open"]
    assert trace["hf_connected"] == 1 and len(f.receiver_traces) == 1
    if fault:
        assert not f.receiver_traces[0]["notifications"]
        assert data(f.vm, SHARED, 8 * 64) == before
        assert trace["active_index"] == "0x0" and opens == ["\\Storage Card2\\PB\\1200-40-000001.pbd"]
    else:
        assert trace["active_index"] == "0x0" and trace["active_pointer"] == hex(SHARED)
        assert opens == [f"\\Storage Card2\\PB\\0000-00-{selected + 1:06x}.pbd"]
        assert sum(e["kind"] == "native-list-callback" for e in trace["events"]) == 2
    return dict(selected=selected, fault=fault, call_popup=call_popup, hf_trace=trace,
                receiver_traces=f.receiver_traces,
                finding="Native callback uses stale PB after logical DB failure despite successful OS transport" if fault else
                        "Native Blue refresh/list callback makes selected address reach HF phonebook path")


def main():
    modules = {m["name"]: m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
               if m["origin"] == "705md"}
    blue_raw = (ROOT / modules["Blue.exe"]["path"]).read_bytes()
    app_raw = (ROOT / modules["AppMain.exe"]["path"]).read_bytes()
    bb, bp = draft_blue_storage(blue_raw); ab, ap = draft_app_pairing(app_raw)
    blue, app = pefile.PE(data=bb), pefile.PE(data=ab)
    cases = [request(blue, app, n, fault) for n in (0, 5, 8)
             for fault in (False, "header", "bulk-false-full", "bulk-partial", "seek")]
    hf_cases = [hf_snapshot(blue, app, selected, fault, popup) for selected in range(8)
                for popup in (False, True) for fault in (False, "header", "bulk-false-full", "bulk-partial", "seek")]
    status_fixture = Success(app, 8, 0)
    status_fixture.vm.write(STATE + 0x628, 0)
    alias_trace = status_fixture.indication(0x4010504)
    assert status_fixture.vm.read(STATE + 0x628) == 1
    bs, _ = source(modules["Blue.exe"], list(dict.fromkeys([a for a, _ in PUBLICATION_RANGES] +
                   [0x33d34, 0x31634, 0x30f08, 0x2e644, 0x3307c, 0x7a8a8, 0x7a3d8, 0x860ac])),
                   {0x30280: 40, 0x3184c: 8, 0x3337c: 20})
    app_ranges = list(dict.fromkeys(APP_RANGES + SUCCESS_RANGES + RECONNECT_RANGES + LIST_CALLBACK_RANGES))
    aps, _ = source(modules["AppMain.exe"], [a for a, _ in app_ranges if a != 0x12a174], {0x12a174: 8})
    dependencies = ["verify_bt_ipc_roundtrip.py", "verify_bt_list_publication.py", "verify_bt_database_io.py",
                    "verify_bt_pairing_storage.py", "verify_bt_pairing_ui.py", "verify_bt_pairing_confirmation.py",
                    "verify_bt_connection_success.py", "verify_bt_reconnect.py", "draft_bt_pairing_storage.py",
                    "draft_bt_database_io.py", "patch_bt_playback.py", "inspect_bt_pairing.py",
                    "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="constructor-type-two native receiver route and lost logical status proved in fixtures",
                  native_execution=False, unit_tested=False, build_allowed=False, blue_sources=bs, app_sources=aps,
                  blue_patch_sha256=bp["draft_sha256"], app_patch_sha256=ap["draft_sha256"], cases=cases,
                  hf_snapshot_cases=hf_cases, ambiguous_state_628_indication=alias_trace,
                  ignored_type_one_message=ignored_message(blue),
                  limitations=["OS synchronous transport bridge is a fixture; no real window/thread/reentrancy tested",
                               "Blue receiver readiness, shared bank and database are fixtures; list publication instructions execute",
                               "No firmware patch in this verifier; preserving receiver-LRESULT alone cannot solve freshness"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    out = ROOT / "analysis/firmware/bt-ipc-roundtrip-draft"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(cases=len(cases), hf_snapshot_cases=len(hf_cases), constructor_kind=2,
                         message="0x8070", wrapper_and_receiver_status=0)))


if __name__ == "__main__": main()
