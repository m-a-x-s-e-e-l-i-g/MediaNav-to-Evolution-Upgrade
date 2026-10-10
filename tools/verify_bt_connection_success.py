"""Native AppMain HF-success/auto-success handlers with shared-list fixtures.

Radio indications, list publication, filesystem and GUI APIs are explicit hooks.
No executable is written or executed natively.
"""
import hashlib
import json
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, MANAGER, STACK, put, data, abi
from verify_bt_pairing_ui import UIVM, SHARED, NAMES, wide, VTABLE, CONTROL_API
from verify_bt_pairing_confirmation import POPUP, pe_string
from verify_bt_reconnect import Reconnect, RANGES, STATE, COORDINATOR, MESSAGE, DIALOG, PROGRESS, GUI, APP_CONTEXT
from draft_bt_pairing_storage import draft_app_pairing, PAIRS

EXTRA = [(0x1276b0, 0x1278e8), (0x11f7d4, 0x120318), (0x110708, 0x1108f0),
         (0x111d84, 0x111e08), (0x11afcc, 0x11b044), (0x111364, 0x1115fc),
         (0x1143a0, 0x114400), (0x114400, 0x114460), (0x12ce18, 0x12d0c4),
         (0x127fc0, 0x1281a8), (0x12e48, 0x12f38)]
SLEEP_API, ATTR_API, FILE_API = 0xf0070010, 0xf0070020, 0xf0070030
CALL_POPUP = 0x63000000


def blue_success_emit(pe):
    vm = UIVM(pe, [(0x1734c, 0x17380), (0x332b0, 0x33304)])
    events = []

    def emit(machine):
        events.append(dict(destination=machine.reg[4], command=hex(machine.reg[5]), parameter=machine.reg[6]))
        for reg in (*range(2, 16), 24, 25): machine.reg[reg] = 0xcafe0000 + reg
        return 0

    vm.hooks[0x33390] = emit
    vm.reg[19] = OBJECT
    vm.reg[29] = STACK
    vm.run(0x1734c, {0x17380})
    assert events == [dict(destination=3, command="0x3040101", parameter=0),
                      dict(destination=2, command="0x3040101", parameter=0),
                      dict(destination=2, command="0x4010506", parameter=0)]
    assert vm.read(OBJECT + 0x229, 1) == 1 and vm.reg[29] == STACK
    return dict(events=events, range_start="0x1734c", range_end="0x17380",
                scope="Native confirmed-success emission block and status helper; emitter API is a hook, delivery order unproved")


class Success(Reconnect):
    def __init__(self, pe, count, selected, list_success=True, nav_ready=False, call_popup=False, list_mode=None):
        super().__init__(pe, count, initial=selected + 1)
        self.pe, self.count, self.selected = pe, count, selected
        self.list_mode = list_mode or ("success" if list_success else "error")
        self.list_success, self.list_requested = self.list_mode in ("success", "recovered"), False
        self.vm.ranges += EXTRA
        vm = self.vm
        for at, val in [(OBJECT + 0xc, SHARED), (OBJECT + 0x5a4, 0), (OBJECT + 0x5c0, SHARED),
                        (OBJECT + 0x5ac, 0xabcdef01), (STATE + 0x61c, 1), (STATE + 0x10, 0),
                        (APP_CONTEXT + 0x240c, 1), (APP_CONTEXT + 0x23cc, 1),
                        (APP_CONTEXT + 0xdc, int(nav_ready)), (APP_CONTEXT + 0xd8, 0xaaaa),
                        (APP_CONTEXT + 0xcc, 0xbbbb), (APP_CONTEXT + 0xe8, 0),
                        (0x188424, POPUP), (PROGRESS + 0x1ecc, 0x1010804),
                        (0x18503c, SLEEP_API), (0x185070, ATTR_API), (0x185084, FILE_API)]:
            vm.write(at, val)
        if self.list_mode == "disabled": vm.write(STATE + 0x6d4, 0)
        put(vm, 0x17b12c, pe.get_data(0x17b12c - pe.OPTIONAL_HEADER.ImageBase, 0x6c))
        self.records = []
        for index in range(count):
            rec = bytearray(64)
            rec[0] = int(index == 0)  # Deliberately stale previous active device.
            rec[4:8] = (index + 1).to_bytes(4, "little")
            rec[8] = 0x40 + index; rec[10:12] = (0x1200 + index).to_bytes(2, "little")
            name = NAMES[index].encode("utf-8"); rec[12:12 + len(name)] = name
            self.records.append(rec)
        put(vm, SHARED, b"".join(self.records))
        put(vm, OBJECT + 0x270, b"".join(self.records))
        if call_popup:
            vm.write(DIALOG + 0x74, CALL_POPUP)
            vm.write(PROGRESS + 0x50, 0)
        vm.hooks.update({0x1400a8: self.send, SLEEP_API: self.sleep, ATTR_API: self.attributes,
                         FILE_API: self.open, 0x13ffc8: self.phonebook_format, 0x140de4: self.memset,
                         0x137d84: self.api(0x137d84), 0x13ff88: self.post,
                         0x13ff68: self.api(0x13ff68), 0x12d58: lambda _: CALL_POPUP,
                         0x1f508: lambda _: 0, 0x128e4: lambda _: 0,
                         0x1f0a4: lambda _: 0x60000000, 0x1f140: lambda _: 0x61000000,
                         0xb85f4: lambda _: 0x62000000})

    def send(self, machine):
        assert machine.reg[4:6] == [0x9876, 0x8070]
        command, parameter = machine.reg[6:8]
        self.events.append(dict(kind="send", command=hex(command), parameter=parameter))
        machine.write(machine.read(machine.reg[29] + 0x18), 0)
        if command == 0x1010702: self.list_requested = True
        if command == 0x1010702:
            attempts = sum(e["kind"] == "send" and e["command"] == "0x1010702" for e in self.events)
            result = int(self.list_mode == "success" or self.list_mode == "recovered" and attempts == 2)
        else:
            result = 1
        self.clobber(machine); return result

    def error(self, machine):
        self.clobber(machine); return 0x578 if self.list_mode in ("timeout", "recovered") else 5

    def sleep(self, machine):
        assert machine.reg[4] == 300
        self.events.append(dict(kind="sleep", ms=300, list_requested=self.list_requested, shared_publication=self.list_success))
        if self.list_success:
            for index, rec in enumerate(self.records): rec[0] = int(index == self.selected)
            put(machine, SHARED, b"".join(self.records))
        self.clobber(machine); return 0

    def timer(self, machine):
        if machine.reg[5] == 0x3fd:
            assert machine.reg[4:8] == [0x7777, 0x3fd, 8000, 0]
            self.events.append(dict(kind="timer", timer="0x3fd", ms=8000, return_value=0x3fd))
            self.clobber(machine); return 0x3fd
        return super().timer(machine)

    def memset(self, machine):
        dest, value, count = machine.reg[4:7]
        put(machine, dest, bytes([value & 255]) * count)
        return dest

    def phonebook_format(self, machine):
        assert pe_string(self.pe, machine.reg[5]) == "%s\\%04x-%02x-%06x.pbd"
        base = pe_string(self.pe, machine.reg[6])
        high, middle, low = machine.reg[7], machine.read(machine.reg[29] + 0x10), machine.read(machine.reg[29] + 0x14)
        text = f"{base}\\{high:04x}-{middle:02x}-{low:06x}.pbd"
        self.events.append(dict(kind="phonebook-path", path=text))
        put(machine, machine.reg[4], (text + "\0").encode("utf-16le")); return len(text)

    def attributes(self, machine):
        self.events.append(dict(kind="file-attributes", path=wide(machine, machine.reg[4]), result="missing"))
        self.clobber(machine); return 0xffffffff

    def open(self, machine):
        self.events.append(dict(kind="file-open", path=wide(machine, machine.reg[4]), result="missing"))
        self.clobber(machine); return 0xffffffff

    def post(self, machine):
        assert machine.reg[4:6] == [0xaaaa, 0xbbbb]
        self.events.append(dict(kind="navigation-post", event=hex(machine.reg[6]), parameter=machine.reg[7]))
        self.clobber(machine); return 1

    def indication(self, command):
        start = len(self.events)
        for n, value in enumerate((0, 0, command, 0, 0)):
            self.vm.write(MESSAGE + n * 4, value)
        self.vm.reg[5] = MESSAGE
        abi(self.vm, 0x11cb00, COORDINATOR)
        return dict(command=hex(command), events=self.events[start:], state=self.state(),
                    hf_connected=self.vm.read(STATE + 0x618), profile_flags=hex(self.vm.read(STATE + 0x10)),
                    active_index=hex(self.vm.read(OBJECT + 0x5a4)), active_pointer=hex(self.vm.read(OBJECT + 0x5c0)),
                    progress_window=hex(self.vm.read(PROGRESS + 0x50)), abi_preserved=True)


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    ranges = list(dict.fromkeys(RANGES + EXTRA))
    sources, original = source(module, [a for a, _ in ranges if a != 0x12a174], {0x12a174: 8})
    raw = (ROOT / module["path"]).read_bytes(); draft, patch = draft_app_pairing(raw)
    pe = pefile.PE(data=draft)
    blue = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    blue_sources, blue_pe = source(blue, [0x17288, 0x332b0, 0x33390], {})
    blue_emission = blue_success_emit(blue_pe)
    cases = []
    for selected in range(PAIRS):
        for nav_ready in (False, True):
            fixture = Success(pe, PAIRS, selected, nav_ready=nav_ready)
            trace = fixture.indication(0x3040101)
            assert trace["hf_connected"] == 1 and trace["profile_flags"] == "0x1"
            assert trace["active_index"] == hex(selected) and trace["active_pointer"] == hex(SHARED + selected * 64)
            assert fixture.vm.read(OBJECT + 0x5ac) == 0
            assert trace["progress_window"] == "0x0"
            expected_path = f"\\Storage Card2\\PB\\{0x1200 + selected:04x}-{0x40 + selected:02x}-{selected + 1:06x}.pbd"
            assert [e["path"] for e in trace["events"] if e["kind"] == "file-open"] == [expected_path]
            assert [e["event"] for e in trace["events"] if e["kind"] == "navigation-post"] == (["0x7dc", "0x7dd", "0x7e2"] if nav_ready else [])
            cases.append(dict(selected=selected, nav_ready=nav_ready, hf_trace=trace,
                              auto_success_trace=fixture.indication(0x4010506)))
    alternate_entries = []
    for selected in range(PAIRS):
        for nav_ready in (False, True):
            fixture = Success(pe, PAIRS, selected, nav_ready=nav_ready, call_popup=True)
            trace = fixture.indication(0x3040101)
            assert trace["hf_connected"] == 1 and trace["active_index"] == hex(selected)
            assert trace["active_pointer"] == hex(SHARED + selected * 64)
            assert not any(e["kind"] == "api" and e["va"] == "0x137d84" for e in trace["events"])
            alternate_entries.append(dict(selected=selected, nav_ready=nav_ready, trace=trace))
    before_guard = bytearray(draft)
    guard_edits = [e for e in patch["edits"] if int(e["va"], 16) in (0x11f9b0, 0x11fa60)]
    assert len(guard_edits) == 2
    for edit in guard_edits:
        at = int(edit["offset"], 16)
        before_guard[at:at + edit["bytes"]] = bytes.fromhex(edit["before_hex"])
    baseline = pefile.PE(data=bytes(before_guard))
    failures = []
    for selected in range(PAIRS):
        for call_popup in (False, True):
            for mode in ("error", "timeout", "disabled"):
                fixture = Success(baseline, PAIRS, selected, call_popup=call_popup, list_mode=mode)
                old = fixture.indication(0x3040101)
                assert old["hf_connected"] == 1 and old["active_index"] == "0x0"
                assert any(e["kind"] == "file-open" for e in old["events"])
                fixture = Success(pe, PAIRS, selected, call_popup=call_popup, list_mode=mode)
                before = data(fixture.vm, OBJECT + 0x270, PAIRS * 64)
                repaired = fixture.indication(0x3040101)
                assert repaired["hf_connected"] == 1 and repaired["profile_flags"] == "0x1"
                assert repaired["active_index"] == "0xffffffff" and repaired["active_pointer"] == "0x0"
                assert fixture.vm.read(OBJECT + 0x5ac) == fixture.vm.read(STATE + 0x664) == 0
                assert not any(e["kind"] in ("file-open", "phonebook-path", "sleep") for e in repaired["events"])
                assert data(fixture.vm, OBJECT + 0x270, PAIRS * 64) == before
                failures.append(dict(selected=selected, call_popup=call_popup, mode=mode, before_guard=old, draft=repaired,
                                     finding="Failed list request no longer copies stale active record or opens its phonebook"))
    recovered_requests = []
    for selected in range(PAIRS):
        for call_popup in (False, True):
            fixture = Success(pe, PAIRS, selected, call_popup=call_popup, list_mode="recovered")
            trace = fixture.indication(0x3040101)
            assert trace["active_index"] == hex(selected)
            assert sum(e["kind"] == "send" and e["command"] == "0x1010702" for e in trace["events"]) == 2
            recovered_requests.append(dict(selected=selected, call_popup=call_popup, trace=trace))
    ordering_cases = []
    for selected in range(PAIRS):
        fixture = Success(pe, PAIRS, selected)
        early = fixture.indication(0x4010506)
        assert not any(e["kind"] == "send" for e in early["events"])
        late = fixture.indication(0x3040101)
        assert late["active_index"] == hex(selected) and late["hf_connected"] == 1
        ordering_cases.append(dict(selected=selected, coordinator_counter=0, synthetic_reverse_order=[early, late]))
    legacy_helper_cases = []
    for count in (2, 3, PAIRS):
        for counter in range(4):
            fixture = Success(pe, count, 0)
            fixture.vm.write(COORDINATOR + 0x18, counter)
            trace = fixture.indication(0x4010506)
            sends = [e for e in trace["events"] if e["kind"] == "send"]
            expected = counter + 2 if 1 <= counter <= 2 and counter + 1 <= count else None
            assert [e["parameter"] for e in sends] == ([] if expected is None else [expected])
            legacy_helper_cases.append(dict(count=count, coordinator_counter=counter, trace=trace,
                                            index_outside_count=expected is not None and expected > count,
                                            scope="Synthetic nonzero coordinator counter; producer and live reachability not yet established"))
    out = ROOT / "analysis/firmware/bt-connection-success-draft"; out.mkdir(parents=True, exist_ok=True)
    dependencies = ["verify_bt_connection_success.py", "verify_bt_reconnect.py", "verify_bt_pairing_confirmation.py",
                    "verify_bt_pairing_ui.py", "verify_bt_database_io.py", "verify_bt_pairing_storage.py",
                    "draft_bt_pairing_storage.py", "draft_bt_database_io.py", "patch_bt_playback.py",
                    "inspect_bt_pairing.py", "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Native HF success/active record and failed-list stale-reference guard passed in interpreter",
                  native_execution=False, unit_tested=False, build_allowed=False, sources=sources,
                  patch_sha256=patch["draft_sha256"], hf_success_cases=cases, alternate_copy_entries=alternate_entries,
                  list_request_failures=failures, before_guard_sha256=hashlib.sha256(before_guard).hexdigest(),
                  recovered_list_requests=recovered_requests,
                  blue_sources=blue_sources, blue_success_emission=blue_emission,
                  synthetic_reverse_order_cases=ordering_cases, legacy_helper_cases=legacy_helper_cases,
                  limitations=["Shared-list publication during Sleep is a fixture, not a proven radio/scheduler timing guarantee",
                               "Phonebook files are missing fixtures; filesystem success/read paths are not executed",
                               "Initial GUI delegation and some getters/renderers remain hooks",
                               "Only HFP success, with no connected-profile-switch or other active profile, is covered",
                               "Blue's native emission order is HF then auto-success; OS delivery/races are not proved",
                               "Legacy helper can issue count+1 under synthetic nonzero counters; counter producers/live reachability remain open"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], hf_success_cases=len(cases), alternate_copy_entries=len(alternate_entries),
                         list_request_failures=len(failures), synthetic_reverse_order_cases=len(ordering_cases),
                         recovered_list_requests=len(recovered_requests),
                         legacy_helper_cases=len(legacy_helper_cases)), indent=2))


if __name__ == "__main__": main()
