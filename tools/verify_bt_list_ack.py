"""Interpret the separate count-acknowledgement prototype, never emit a PE.

Synchronous OS and shared-bank bridges are fixtures, not CE scheduling evidence.
The receiver, wrapper, HFP consumer and bounded scan execute actual MIPS bytes.
"""
import hashlib
import json
import re
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, MANAGER, abi, put, data
from verify_bt_pairing_ui import UIVM, COORDINATOR, STATE, SHARED
from verify_bt_ipc_roundtrip import HFSnapshot, APP_RANGES, ignored_message
from verify_bt_list_publication import case, APP_RANGES as CALLBACK_RANGES, EXTRA as BLUE_RANGES
from verify_bt_connection_success import EXTRA as HF_RANGES
from verify_bt_reconnect import RANGES as RECONNECT_RANGES
from verify_bt_send_status import run as legacy_send, SCENARIOS
from draft_bt_pairing_storage import draft_blue_storage, draft_app_pairing
from draft_bt_list_ack import blue_ack, app_ack, ACK

ERROR_API = 0xf0090010


def clobber(vm):
    for reg in (*range(2, 16), 24, 25): vm.reg[reg] = 0xcafe0000 + reg


def opt_in(app, statuses, outcomes, error=0x578, enabled=True, mode=2, command=0x1010702):
    """A failed OS attempt may write an out-value; later attempt may omit it."""
    vm = UIVM(app, APP_RANGES)
    for at, val in [(0x187be4, MANAGER), (MANAGER + 0xa8, STATE),
                    (STATE + 0x6d4, int(enabled)), (COORDINATOR + 0x14, 2),
                    (COORDINATOR + 8, 0x9876), (0x185020, ERROR_API), (0x1852bc, ERROR_API + 4)]: vm.write(at, val)
    sends, errors, debug = [], [], []
    def send(machine):
        assert machine.reg[4:8] == [0x9876, 0x8070, command, 0]
        out = machine.read(machine.reg[29] + 0x18)
        assert out == machine.reg[29] + 0x20 and machine.read(out) == 0
        index = len(sends)
        sends.append(dict(out_before=machine.read(out), receiver_status=statuses[index], os_result=outcomes[index]))
        if statuses[index] is not None: machine.write(out, statuses[index])
        clobber(machine); return outcomes[index]
    def get_error(machine):
        errors.append(error); clobber(machine); return error
    def print_debug(machine):
        debug.append(machine.reg[4:8].copy()); clobber(machine); return 0xaabbccdd
    vm.hooks.update({0x1400a8: send, ERROR_API: get_error, 0x140038: lambda _: 0x9876, ERROR_API + 4: print_debug})
    vm.reg[5:8] = [mode, command, 0]
    abi(vm, 0x11b464, COORDINATOR)
    expected = 0xffffffff if not enabled or not outcomes[-1] else (statuses[-1] or 0) if mode == 2 else 0
    assert vm.reg[2] == expected
    assert len(sends) == (len(outcomes) if enabled else 0)
    assert len(debug) == int(enabled and command == 0x1010501)
    return dict(mode=mode, command=hex(command), enabled=enabled, sends=sends, errors=errors,
                debug=debug, returned_status=hex(vm.reg[2]), abi_preserved=True)


class ConfirmedSnapshot(HFSnapshot):
    def __init__(self, blue, app, count, selected=0, fault=False, popup=False,
                 transport="success", status_override=None, outer="success"):
        super().__init__(blue, app, selected, fault, popup)
        self.new_count, self.transport, self.status_override, self.outer = count, transport, status_override, outer
        self.attempts = 0
        self.list_mode = "timeout" if outer in ("timeout", "retry", "retry-missing") else "error"
        if outer == "disabled": self.vm.write(STATE + 0x6d4, 0)

    def send(self, machine):
        assert machine.reg[4:6] == [0x9876, 0x8070]
        if machine.reg[6] == 0x1041401:
            machine.write(machine.read(machine.reg[29] + 0x18), 0)
            self.events.append(dict(kind="send", command="0x1041401", parameter=0, scope="Unexecuted profile-query receiver"))
            self.clobber(machine); return 1
        assert machine.reg[6:8] == [0x1010702, 0]
        self.attempts += 1
        out = machine.read(machine.reg[29] + 0x18)
        assert machine.read(out) == 0  # No previous attempt's ACK survives.
        os_success = self.outer == "success" or self.outer in ("retry", "retry-missing") and self.attempts == 2
        if self.status_override is None:
            expected = 0 if self.fault else ACK | self.new_count
            trace = case(self.blue, self.pe, self.new_count, read_error=self.fault, receiver=True,
                         receiver_status=expected, transport=self.transport,
                         initial_selected=self.selected if self.new_count else None)
            self.receiver_traces.append(trace)
            bank = b"".join(bytes.fromhex(rec["bytes_hex"]) for rec in trace["copied_records"])
            # Actual publication precedes notification attempts, even if all fail.
            if not self.fault: put(self.vm, SHARED, bank)
            for notification in trace["notifications"]:
                if notification["transport_success"]: self.list_callback(bank, notification["low_count"])
            status = trace["returned_status"]
        else:
            status = self.status_override
        # For retry-missing, the first failed attempt returns a valid ACK; the
        # second OS-success intentionally omits out entirely. It must be zero.
        if not (self.outer == "retry-missing" and self.attempts == 2): machine.write(out, status)
        self.events.append(dict(kind="send", command="0x1010702", parameter=0,
                                receiver_status=hex(status), os_success=os_success, attempt=self.attempts))
        self.list_requested = True
        self.clobber(machine); return int(os_success)


def snapshot(blue, app, count, selected=0, fault=False, popup=False, transport="success",
             status_override=None, outer="success"):
    f = ConfirmedSnapshot(blue, app, count, selected, fault, popup, transport, status_override, outer)
    before = data(f.vm, OBJECT + 0x270, 512)
    before_shared = data(f.vm, SHARED, 512)
    trace = f.indication(0x3040101)
    opens = [e["path"] for e in trace["events"] if e["kind"] == "file-open"]
    callbacks = sum(e["kind"] == "native-list-callback" for e in trace["events"])
    assert not any(e["kind"] == "sleep" for e in trace["events"])
    valid_status = status_override is None or status_override >> 16 == 0x4c53 and (status_override & 0xffff) <= 8
    successful = not fault and valid_status and outer in ("success", "retry")
    if successful and count:
        assert trace["active_index"] == "0x0" and trace["active_pointer"] == hex(SHARED)
        assert f.vm.read(OBJECT + 0x26c) == count
        expected_path = f"\\Storage Card2\\PB\\0000-00-{selected + 1:06x}.pbd" if status_override is None else "\\Storage Card2\\PB\\1200-40-000001.pbd"
        assert opens == [expected_path]
        assert trace["hf_connected"] == 1
        assert data(f.vm, OBJECT + 0x270 + count * 64, (8 - count) * 64) == bytes((8 - count) * 64)
    elif successful:
        assert trace["active_index"] == "0xffffffff" and trace["active_pointer"] == "0x0" and not opens
        assert f.vm.read(OBJECT + 0x26c) == 0 and data(f.vm, OBJECT + 0x270, 512) == bytes(512)
        # Native list callback clears HFP state for an empty list. A missing
        # notification leaves the already-confirmed HFP indication intact.
        assert trace["hf_connected"] == int(callbacks == 0)
    else:
        assert trace["active_index"] == "0xffffffff" and trace["active_pointer"] == "0x0" and not opens
        assert f.vm.read(OBJECT + 0x5ac) == f.vm.read(STATE + 0x664) == 0
        if fault or status_override is not None or outer == "disabled":
            assert data(f.vm, OBJECT + 0x270, 512) == before
            assert data(f.vm, SHARED, 512) == before_shared
        # A timeout does not imply undelivered request: callbacks may already
        # have refreshed count/data. Do not assert that these are unchanged.
        assert trace["hf_connected"] == int(not (count == 0 and callbacks))
    assert f.attempts == (0 if outer == "disabled" else 2 if outer in ("timeout", "retry", "retry-missing") else 1)
    return dict(count=count, selected=selected, database_fault=fault, popup=popup,
                notification_transport=transport, outer_transport=outer, supplied_status=status_override,
                hf_trace=trace, receiver_traces=f.receiver_traces, successful_list=successful,
                pb_open_paths=opens, actual_count=f.vm.read(OBJECT + 0x26c), abi_preserved=True)


class ScanVM(UIVM):
    def __init__(self, pe):
        super().__init__(pe, [(0x111d84, 0x111e08), (0x11afcc, 0x11b044)])
        self.bank_reads = []
    def read(self, at, size=4):
        if SHARED <= at < SHARED + 512: self.bank_reads.append(dict(address=hex(at), bytes=size))
        return super().read(at, size)


def scan(app, count, active, media=False, null=False, all_active=False):
    vm = ScanVM(app)
    vm.write(OBJECT + 0x26c, count); vm.write(OBJECT + 0xc, 0 if null else SHARED)
    vm.write(OBJECT + 0x5a4, 6); vm.write(OBJECT + 0x5c0, SHARED + 384)
    bank = bytearray(512)
    for i in range(8): bank[i * 64 + int(media)] = int(all_active or active == i)
    put(vm, SHARED, bank)
    abi(vm, 0x111d84, OBJECT)
    found = (0 if all_active else active) if not null and 1 <= count <= 8 and (all_active or active is not None and active < count) else None
    assert vm.read(OBJECT + 0x5a4) == (0xffffffff if found is None else found)
    assert vm.read(OBJECT + 0x5c0) == (0 if found is None else SHARED + found * 64)
    assert all(int(r["address"], 16) + r["bytes"] <= SHARED + min(count, 8) * 64 for r in vm.bank_reads)
    assert len(vm.bank_reads) == (0 if null or not 1 <= count <= 8 else count if found is None else found + 1)
    return dict(count=count, active=active, media=media, null_shared=null, all_active=all_active,
                found=found, bank_reads=vm.bank_reads, abi_preserved=True)


def ordinary_receiver(blue, message, command, ready=True, copydata=False, payload=False):
    """Native route/epilogue; command bodies and COPYDATA decode are hooks."""
    vm = UIVM(blue, [(0x33d34, 0x33f90), (0x31634, 0x31718), (0x30f08, 0x311c0),
                      (0x2e644, 0x2e67c), (0x30280, 0x302a8), (0x3061c, 0x30e80)])
    vm.write(0x20e1e8, MANAGER); vm.write(MANAGER + 0x288, int(ready), 1)
    vm.write(0x20e1f0, COORDINATOR)
    put(vm, 0x31670, blue.get_data(0x31670 - blue.OPTIONAL_HEADER.ImageBase, 32))
    handlers, frees = [], []
    def command_hook(at):
        def body(machine):
            handlers.append(hex(at)); clobber(machine); return ACK | 8
        return body
    def decode(machine):
        target = machine.reg[4]
        machine.write(target, 0x60000000 if payload else 0)
        machine.write(target + 8, command)
        clobber(machine); return 1
    def free(machine):
        assert machine.reg[4] == 0x60000000
        frees.append(hex(machine.reg[4])); clobber(machine); return 0xaabbccdd
    vm.hooks.update({0x2f5f0: command_hook(0x2f5f0), 0x2fec4: command_hook(0x2fec4),
                     **{at: command_hook(at) for at in (0x2ef90, 0x2f28c, 0x2efe0, 0x30350, 0x2f504, 0x2eb74, 0x3142c, 0x31fa0)},
                     0x8a940: lambda _: 0xface1234, 0x33a10: decode, 0x8aaf0: free})
    if copydata:
        vm.write(0x61000004, 20); vm.write(0x61000008, 0x62000000)
    vm.reg[5:8] = [0x4a if copydata else message, command, 0x61000000 if copydata else 0]
    abi(vm, 0x33d34, 0x7777)
    expected = 0xface1234 if not ready or not copydata and not 0x8000 <= message <= 0x8082 else (
        ACK | 8 if not copydata and message == 0x8070 and command == 0x1010702 else 0)
    assert vm.reg[2] == expected
    assert len(frees) == int(copydata and payload and ready)
    return dict(message=hex(0x4a if copydata else message), command=hex(command), ready=ready,
                copydata=copydata, allocated_payload=payload, handlers=handlers, frees=frees,
                return_value=hex(vm.reg[2]), abi_preserved=True,
                scope="Native dispatch/epilogues; selected command bodies, decode/free and default OS handler are hooks")


def main():
    modules = {m["name"]: m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8")) if m["origin"] == "705md"}
    raw_blue = (ROOT / modules["Blue.exe"]["path"]).read_bytes()
    raw_app = (ROOT / modules["AppMain.exe"]["path"]).read_bytes()
    bb, bp = blue_ack(raw_blue); ab, ap = app_ack(raw_app)
    blue, app = pefile.PE(data=bb), pefile.PE(data=ab)
    base_ab, _ = draft_app_pairing(raw_app); base_app = pefile.PE(data=base_ab)
    wrapper = [opt_in(app, [status], [os]) for status in (0, ACK, ACK | 8, 0xaabbccdd) for os in (1, 2, 0xffffffff)]
    wrapper += [opt_in(app, [ACK | 8, status], [0, os]) for status in (None, 0, ACK | 5) for os in (1, 0)]
    wrapper += [opt_in(app, [ACK | 8], [0], error=5), opt_in(app, [ACK | 8], [1], enabled=False)]
    wrapper += [opt_in(app, [ACK | 8], [1], mode=mode, command=command)
                for mode in (0, 1, 2, 3, 0xffffffff) for command in (0x1010702, 0x1010501)]
    legacy = []
    for kind in (0, 1, 2, 3):
        for scenario in SCENARIOS:
            before, after = legacy_send(base_app, kind, scenario), legacy_send(app, kind, scenario)
            assert before == after; legacy.append(dict(base=before, prototype=after))
        before, after = legacy_send(base_app, kind, "one", invalid_command=True), legacy_send(app, kind, "one", invalid_command=True)
        assert before == after; legacy.append(dict(base=before, prototype=after))
    valid = [snapshot(blue, app, n, i, popup=popup, transport=transport)
             for n in range(1, 9) for i in range(n) for popup in (False, True) for transport in ("success", "timeout", "retry")]
    valid += [snapshot(blue, app, 0, popup=popup, transport=transport) for popup in (False, True) for transport in ("success", "timeout", "retry")]
    failed = [snapshot(blue, app, n, fault=fault, popup=popup, transport=transport)
              for n in (0, 5, 8) for fault in ("header", "bulk-false-full", "bulk-partial", "seek")
              for popup in (False, True) for transport in ("success", "timeout", "retry")]
    malformed = [snapshot(blue, app, 8, popup=popup, status_override=status)
                 for popup in (False, True) for status in (0, 1, 0xffffffff, 0x4c520008, 0x4c540008, ACK | 9, ACK | 0xffff)]
    outer = [snapshot(blue, app, n, popup=popup, outer=mode)
             for n in (0, 5, 8) for popup in (False, True) for mode in ("error", "timeout", "retry", "retry-missing", "disabled")]
    stale_ack = snapshot(blue, app, 8, status_override=ACK | 8)
    assert stale_ack["pb_open_paths"] == ["\\Storage Card2\\PB\\1200-40-000001.pbd"]
    scan_cases = [scan(app, n, active, media=media) for n in range(9) for active in [None, *range(8)] for media in (False, True)]
    scan_cases += [scan(app, n, 0, null=null) for n in (0, 1, 8, 9, 0xffffffff) for null in (False, True)]
    scan_cases += [scan(app, n, None, all_active=True) for n in range(1, 9)]
    old_vm = UIVM(base_app, [(0x111d84, 0x111e08), (0x11afcc, 0x11b044)])
    old_vm.write(OBJECT + 0x26c, 1); old_vm.write(OBJECT + 0xc, SHARED); old_vm.write(SHARED + 7 * 64, 1, 1)
    abi(old_vm, 0x111d84, OBJECT); assert old_vm.read(OBJECT + 0x5a4) == 7
    receivers = [ordinary_receiver(blue, mid, cmd, ready) for mid in (0x8065, 0x8070, 0x8082, 0x8000, 0x8083)
                 for cmd in (0x1010804, 0xdeadbeef, 0x2010000, 0x1010702) for ready in (False, True)]
    receivers += [ordinary_receiver(blue, 0x4a, 0x1010702, copydata=True, payload=payload) for payload in (False, True)]
    receivers += [ordinary_receiver(blue, 0x8070, module << 16) for module in range(18)]
    receivers += [ordinary_receiver(blue, 0x8082, 0x1010e01)]
    ignored_message(blue)
    bs, _ = source(modules["Blue.exe"], list(dict.fromkeys([a for a, _ in BLUE_RANGES] +
                   [0x33d34, 0x31634, 0x30f08, 0x3061c, 0x2e644, 0x3307c, 0x7a8a8, 0x7a3d8, 0x860ac])), {0x30280: 40, 0x3184c: 8})
    app_ranges = list(dict.fromkeys(APP_RANGES + HF_RANGES + RECONNECT_RANGES + CALLBACK_RANGES))
    aps, _ = source(modules["AppMain.exe"], [a for a, _ in app_ranges if a != 0x12a174], {0x12a174: 8})
    # Inventoried pseudocode calls all pass one. This is not an indirect-caller proof.
    code = (ROOT / "analysis/decompiled/705md/AppMain.exe/decompiled.c").read_text(encoding="utf-8")
    direct_modes = re.findall(r"FUN_0011b464\([^\n]+", code)
    calls = [s for s in direct_modes if not s.startswith("FUN_0011b464(int ")]
    assert len(calls) == 152 and all(re.match(r"FUN_0011b464\([^,]+,\s*1\s*,", s) for s in calls)
    asm = (ROOT / "analysis/disassembly/AppMain.exe.asm").read_text(encoding="utf-8")
    locals_uses = [line for line in asm.splitlines() if re.match(r"[0-9a-f]{8}\s", line)
                  and 0x11f7d4 <= int(line[:8], 16) < 0x120318
                  and re.search(r"(?:0x(?:44|48)\(\$sp\)|\$sp, 0x(?:44|48)\b)", line)]
    assert len(locals_uses) == 4 and all(int(line[:8], 16) >= 0x11fb0c for line in locals_uses)
    deps = ["verify_bt_list_ack.py", "draft_bt_list_ack.py", "verify_bt_ipc_roundtrip.py", "verify_bt_list_publication.py",
            "verify_bt_connection_success.py", "verify_bt_reconnect.py", "verify_bt_send_status.py", "verify_bt_pairing_confirmation.py",
            "verify_bt_database_io.py", "verify_bt_pairing_ui.py", "verify_bt_pairing_storage.py", "draft_bt_pairing_storage.py",
            "draft_bt_database_io.py", "patch_bt_playback.py", "inspect_bt_pairing.py", "inspect_bt_playback.py",
            "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Separate count-ACK prototype interpreted; logical failure guarded, snapshot concurrency unproved",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  blue_sources=bs, app_sources=aps, blue_patch=bp, app_patch=ap,
                  wrapper_cases=wrapper, legacy_wrapper_pairs=legacy, coupled_valid_cases=valid,
                  coupled_database_fault_cases=failed, malformed_ack_cases=malformed, outer_transport_cases=outer,
                  stale_well_formed_ack_counterexample=stale_ack, bounded_scan_cases=scan_cases,
                  old_scan_count_one_selects_stale_slot=7, ordinary_receiver_cases=receivers,
                  decompiler_legacy_mode_inventory=dict(calls=len(calls), modes=[1], sha256=hashlib.sha256(code.encode("utf-8")).hexdigest()),
                  original_hf_local_uses=locals_uses,
                  limitations=["Synchronous OS/shared-bank bridge; CE reentrancy, locking, scheduling and snapshot lifetime unproved",
                               "Well-formed stale/forged ACK is accepted; no generation or immutable snapshot",
                               "Callback count zero clears HFP state by native behavior; notification loss changes this state outcome",
                               "Scan rejects NULL shared pointer, but preceding copy still dereferences nonempty NULL shared bank",
                               "Mode-one callers inventoried in decompiler; indirect mode callers remain unproved",
                               "Phonebook files missing fixtures and extra profile-query receiver remains a hook",
                               "Selected command-body hooks only establish dispatch return normalization; not complete command semantics",
                               "No native unwind, CSR eight-device key capacity, cache aliases or unit behavior proof"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps})
    out = ROOT / "analysis/firmware/bt-list-ack-draft"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], wrapper_cases=len(wrapper), legacy_pairs=len(legacy),
                         valid=len(valid), db_faults=len(failed), malformed=len(malformed), outer=len(outer),
                         scan=len(scan_cases), ordinary_receivers=len(receivers),
                         blue_sha256=bp["draft_sha256"], app_sha256=ap["draft_sha256"]), indent=2))


if __name__ == "__main__": main()
