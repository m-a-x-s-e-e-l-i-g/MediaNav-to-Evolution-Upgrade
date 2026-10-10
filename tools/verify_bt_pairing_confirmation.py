"""Pairing name/address contracts and native popup confirmation fixtures.

All original/modified MIPS bytes are interpreted. No native CE/radio execution.
"""
import hashlib
import json
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, MANAGER, put, data, abi
from verify_bt_pairing_ui import UIVM, NAMES, COOKIE, CONVERT_API, wide, case as ui_case
from verify_bt_pairing_ui import DIALOG, COORDINATOR, STATE, SHARED, VTABLE, CONTROL_API
from draft_bt_pairing_storage import draft_app_pairing, PAIRS

OUTPUT = 0x58000000
POPUP, DESCRIPTOR, GUI, DIALOG_LIST = 0x59000000, 0x5a000000, 0x5b000000, 0x5c000000
PROGRESS = 0x5d000000
APP_RANGES = [(0x12db94, 0x12ddf0), (0x12ddf0, 0x12e24c), (0x11589c, 0x115f38),
              (0x1109d4, 0x110b50), (0x111d84, 0x111e08), (0x111364, 0x1115fc),
              (0x11b464, 0x11b5c8), (0x1144b4, 0x114518), (0x111a30, 0x111b00),
              (0x11679c, 0x1168b8), (0x11a8f4, 0x11a95c), (0x12c10, 0x12cf8),
              (0x130a70, 0x130ab0), (0x1362c4, 0x136494), (0x1356a8, 0x135778),
              (0x134c50, 0x134d28), (0x12d294, 0x12d2c8), (0x12a174, 0x12a17c)]


def pe_string(pe, address, unicode=True):
    raw = pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, 520)
    if not unicode: return raw.split(b"\0")[0].decode("ascii")
    units = [raw[n:n + 2] for n in range(0, len(raw), 2)]
    return b"".join(units[:units.index(b"\0\0")]).decode("utf-16le")


def address_text(index, separator):
    return f"{0x1200 + index:04x}{separator}{0x40 + index:02x}{separator}{index + 1:06x}"


def text_hooks(vm, pe, conversions, formats):
    def memset(machine):
        at, value, count = machine.reg[4:7]
        put(machine, at, bytes([value & 255]) * count); return at

    def convert(machine):
        assert machine.reg[4:6] == [65001, 8] and machine.reg[7] == 50
        origin = machine.reg[6]
        destination, capacity = machine.read(machine.reg[29] + 0x10), machine.read(machine.reg[29] + 0x14)
        assert capacity == 50
        text = data(machine, origin, 50).decode("utf-8")
        encoded = text.encode("utf-16le"); assert len(encoded) <= 100
        put(machine, destination, encoded)
        conversions.append(dict(source=hex(origin), destination=hex(destination), text=text.split("\0")[0]))
        return len(encoded) // 2

    def address_format(machine):
        assert machine.reg[5] == 50
        fmt = pe_string(pe, machine.reg[6], False)
        assert fmt in ("%04x-%02x-%06x", "%04x:%02x:%06x")
        high, middle, low = machine.reg[7], machine.read(machine.reg[29] + 0x10), machine.read(machine.reg[29] + 0x14)
        sep = "-" if "-" in fmt else ":"
        text = f"{high:04x}{sep}{middle:02x}{sep}{low:06x}"
        put(machine, machine.reg[4], (text + "\0").encode("ascii"))
        formats.append(dict(format=fmt, arguments=[high, middle, low], text=text))
        return len(text)

    vm.hooks.update({0x140de4: memset, CONVERT_API: convert, 0x1406d4: address_format,
                     0x140298: lambda m: 0 if m.reg[4] == COOKIE else (_ for _ in ()).throw(AssertionError("cookie"))})
    put(vm, 0x176848, pe.get_data(0x176848 - pe.OPTIONAL_HEADER.ImageBase, 12))


def helper_case(pe, count, index, mode, blank=False):
    vm = UIVM(pe, [(0x1109d4, 0x110b50)])
    vm.write(0x1853f4, COOKIE); vm.write(0x185088, CONVERT_API)
    vm.write(OBJECT + 0x26c, count)
    for n in range(count):
        rec = bytearray(64)
        rec[4:8] = (n + 1).to_bytes(4, "little")
        rec[8] = 0x40 + n; rec[10:12] = (0x1200 + n).to_bytes(2, "little")
        if not blank:
            name = NAMES[n].encode("utf-8"); rec[12:12 + len(name)] = name
        put(vm, OBJECT + 0x270 + n * 64, rec)
    conversions, formats = [], []
    text_hooks(vm, pe, conversions, formats)
    vm.reg[5:8] = [index, OUTPUT, mode]
    abi(vm, 0x1109d4, OBJECT)
    return dict(count=count, index=hex(index), mode=mode, blank=blank,
                text=wide(vm, OUTPUT), conversions=conversions, formats=formats, abi_preserved=True)


def confirmation_case(pe, count, index, deleting=False, duplicate=False, send_mode="success", message_kind=2, success_value=1, caller_fixed=True):
    def confirm(vm, selected):
        vm.ranges += APP_RANGES
        # Reuse the actual descriptor emitted by the list-click path; the native
        # popup initializer maps it to fields read by the native confirmation.
        descriptor = bytes.fromhex(selected["popup"]["descriptor_hex"])
        put(vm, DESCRIPTOR, descriptor)
        vm.write(POPUP, VTABLE); vm.write(POPUP + 0x2d4, VTABLE)
        vm.write(POPUP + 0x2d0, 1)  # Choose the native no-resource-lookup branch.
        vm.write(0x186ce8, GUI); vm.write(GUI + 4, 0x7777)
        vm.write(0x1860fc, DIALOG_LIST); vm.write(0x186100, 1); vm.write(DIALOG_LIST, DIALOG)
        vm.write(STATE + 0x6d4, int(send_mode != "disabled"))
        vm.write(COORDINATOR + 8, 0x9876); vm.write(COORDINATOR + 0x14, message_kind)
        vm.write(VTABLE + 0x40, CONTROL_API)
        vm.write(VTABLE + 0x64, CONTROL_API)
        # The progress dialog is a different singleton/class from confirmation.
        # Execute its actual getter's already-initialized path and native close.
        vm.write(0x188420, PROGRESS)
        put(vm, 0x17b12c, pe.get_data(0x17b12c - pe.OPTIONAL_HEADER.ImageBase, 0x68))
        vm.write(PROGRESS, 0x17b12c)
        for at in (0x150af4, 0x176848):
            put(vm, at, pe.get_data(at - pe.OPTIONAL_HEADER.ImageBase, 64))
        # Distinct full BDADDRs make wrong-record phonebook names observable.
        for n in range(count):
            for base in (SHARED + n * 64, OBJECT + 0x270 + n * 64):
                vm.write(base + 8, 0x40 + n, 1); vm.write(base + 10, 0x1200 + n, 2)
        conversions, formats, sends, paths, helpers, progress, send_states = [], [], [], [], [], [], []
        in_replay = False
        text_hooks(vm, pe, conversions, formats)

        def clobber(machine):
            for reg in (*range(2, 16), 24, 25):
                machine.reg[reg] = 0xcafe0000 + reg

        def text(machine, address):
            return pe_string(pe, address) if pe.OPTIONAL_HEADER.ImageBase <= address < 0x190000 else wide(machine, address)

        def snprintf(machine):
            assert machine.reg[5] == 0x103
            fmt = pe_string(pe, machine.reg[6])
            value = text(machine, machine.reg[7])
            if fmt == "%s %s%s":
                value += " " + text(machine, machine.read(machine.reg[29] + 0x10))
                value += text(machine, machine.read(machine.reg[29] + 0x14))
            else:
                assert fmt == "%s", fmt
            put(machine, machine.reg[4], (value + "\0").encode("utf-16le")); return len(value)

        def concat(machine):
            assert machine.reg[6] == 0x103
            value = wide(machine, machine.reg[4]) + wide(machine, machine.reg[5])
            put(machine, machine.reg[4], (value + "\0").encode("utf-16le")); return machine.reg[4]

        def send(machine):
            expected_id = 0x8065 if message_kind == 1 else (message_kind + 0x806e) & 0xffffffff
            assert machine.reg[4] == 0x9876 and machine.reg[5] == expected_id
            assert machine.read(machine.reg[29] + 0x10) == 0
            assert machine.read(machine.reg[29] + 0x14) == 1500
            sends.append(dict(command=hex(machine.reg[6]), parameter=machine.reg[7], message=hex(machine.reg[5])))
            send_states.append(dict(command=hex(machine.reg[6]),
                                    pending={hex(off): hex(machine.read(STATE + off)) for off in (0x17c, 0x5a8, 0x5fc, 0x698)}))
            if not deleting and not in_replay and machine.reg[6] == 0x1030403 and len(sends) == 1:
                assert machine.read(STATE + 0x5fc) == 1
            if not deleting and not in_replay and machine.reg[6] == 0x1010804:
                assert machine.read(STATE + 0x17c) == 1 and machine.read(STATE + 0x5a8) == index + 1
            machine.write(machine.read(machine.reg[29] + 0x18), 0)
            if send_mode == "recovered":
                attempts = sum(s["command"] == hex(machine.reg[6]) for s in sends)
                result = success_value if attempts == 2 else 0
            elif send_mode.startswith("connect-"):
                result = 0 if machine.reg[6] == 0x1010804 else success_value
            else:
                result = success_value if send_mode not in ("timeout", "error") else 0
            clobber(machine)
            return result

        def find_window(machine):
            helpers.append(dict(helper="FindWindowW", arguments=machine.reg[4:6].copy()))
            clobber(machine)
            return 0x9876

        def helper(at):
            def hooked(machine):
                helpers.append(dict(helper=hex(at), arguments=machine.reg[4:8].copy())); return 0
            return hooked

        def progress_popup(machine):
            assert machine.reg[4:6] == [DIALOG, PROGRESS]
            descriptor = machine.reg[6]
            progress.append(dict(page_code=hex(machine.read(descriptor + 0xc)),
                                 positive_command=hex(machine.read(descriptor + 0x1c)),
                                 timeout_ms=machine.read(descriptor + 0x14)))
            vm.write(PROGRESS + 0x50, 0x8888)
            vm.write(PROGRESS + 0x2c8, DIALOG)
            vm.write(PROGRESS + 0x2cc, 3)
            vm.write(PROGRESS + 0x4c, 0x8889)
            vm.write(PROGRESS + 0x54, 0x888a)
            vm.write(PROGRESS + 0x58, 0x888b)
            vm.write(DIALOG + 0x74, PROGRESS)
            vm.write(DIALOG + 0x50, 0x9999)
            vm.write(DIALOG + 0x80, 1)  # Native parent redraw branch excluded.
            return 0x8888

        def last_error(machine):
            clobber(machine)
            return 5 if send_mode in ("error", "connect-error") else 0x578

        def phonebook_format(machine):
            fmt = pe_string(pe, machine.reg[5]); assert fmt == "%s\\%s.pbd"
            value = pe_string(pe, machine.reg[6]) + "\\" + wide(machine, machine.reg[7]) + ".pbd"
            paths.append(value); put(machine, machine.reg[4], (value + "\0").encode("utf-16le"))
            return len(value)

        vm.write(0x185100, 0xf0040010); vm.write(0x185020, 0xf0040020)
        vm.hooks.update({0x140320: snprintf, 0x1403a0: concat, 0x1400a8: send,
                         0x140038: find_window, 0xf0040020: last_error,
                         0x140330: phonebook_format,
                         0xf0040010: lambda _: 0xffffffff,
                         0x135778: progress_popup,
                         **{at: helper(at) for at in (0x12e9a0, 0x12e778, 0x13ff08, 0x13fef8,
                                                     0x11663c, 0x1118a0, 0x127fc0,
                                                     0x140c44, 0x140018, 0x140198, 0x140138, 0x1400e8, 0xe7c90)}})
        vm.reg[5] = DESCRIPTOR
        abi(vm, 0x12db94, POPUP)
        assert vm.read(POPUP + 0x2168) == int(selected["popup"]["command"], 16)
        assert vm.read(POPUP + 0x216c) == selected["popup"]["parameter"]
        vm.reg[5] = 0x3e9
        abi(vm, 0x12ddf0, POPUP)
        expected_command = "0x1010704" if deleting and count == 1 else "0x1010701" if deleting else "0x1010804"
        expected_parameter = 0 if deleting and count == 1 else index + 1
        message_id = 0x8065 if message_kind == 1 else (message_kind + 0x806e) & 0xffffffff
        reset_failed = send_mode in ("disabled", "timeout", "error")
        final_failed = reset_failed or send_mode.startswith("connect-")
        attempts = 2 if send_mode in ("timeout", "recovered", "connect-timeout") else 1
        final_sends = [] if send_mode == "disabled" else [dict(command=expected_command, parameter=expected_parameter, message=hex(message_id))] * attempts
        reset_attempts = 2 if send_mode in ("timeout", "recovered") else 1
        reset_sends = [] if deleting or send_mode == "disabled" else [dict(command="0x1030403", parameter=1234 << 16, message=hex(message_id))] * reset_attempts
        early_exit = caller_fixed and not deleting and reset_failed
        expected_sends = reset_sends + ([] if early_exit else final_sends)
        assert sends == expected_sends
        if deleting:
            assert not progress
            assert paths == ([] if count == 1 else ["\\Storage Card2\\PB\\" + address_text(index, "-") + ".pbd"])
            if count == 1:
                assert vm.read(OBJECT + 0x26c) == 0
                assert [h["helper"] for h in helpers if h["helper"] in ("0x11663c", "0x1118a0")] == ["0x11663c", "0x1118a0"]
        else:
            assert progress == ([] if early_exit else [dict(page_code="0x1010804", positive_command="0x0", timeout_ms=45000)])
            assert vm.read(STATE + 0x620) == index
            assert vm.read(STATE + 0x5a8) == (0 if caller_fixed and final_failed else index + 1)
            assert vm.read(STATE + 0x17c) == (0 if caller_fixed and final_failed else 1)
            assert vm.read(STATE + 0x5fc) == (0 if caller_fixed and final_failed else 1)
            assert vm.read(STATE + 0x698) == (0 if caller_fixed and final_failed else 1)
            assert vm.read(STATE + 0x624) == 0
            assert len(conversions) == (0 if early_exit else index + 2)
            assert not paths
            destroyed = [h for h in helpers if h["helper"] == "0x1400e8"]
            late_exit = caller_fixed and send_mode.startswith("connect-")
            assert len(destroyed) == int(late_exit)
            if late_exit:
                assert destroyed[0]["arguments"][0] == 0x8888
                assert vm.read(PROGRESS + 0x50) == vm.read(PROGRESS + 0x4c) == vm.read(PROGRESS + 0x54) == 0
                assert vm.read(DIALOG + 0x74) == 0
                assert vm.read(PROGRESS + 0x2cc) == 1
                assert any(h["helper"] == "0x140c44" and h["arguments"][:2] == [0x9999, 1] for h in helpers)
                assert not any(h["helper"] == "0x13ff08" and h["arguments"][1] == 0x417 for h in helpers)
        # Observe the native send wrapper's own return independently of the
        # later cookie/epilogue and do not mix this replay with the click trace.
        caller_sends = sends.copy(); sends.clear()
        caller_send_states = send_states.copy(); send_states.clear()
        # The replay tests the wrapper alone after caller cleanup; its OS hook
        # must no longer assert the caller's pre-send state.
        in_replay = True
        vm.reg[5:8] = [1, int(expected_command, 16), expected_parameter]
        abi(vm, 0x11b464, COORDINATOR)
        assert vm.reg[2] == (0xffffffff if final_failed else 0)
        assert sends == final_sends
        return dict(sends=caller_sends, direct_send_replay=dict(return_value=hex(vm.reg[2]), sends=sends.copy()),
                    state_at_os_send=caller_send_states,
                    phonebook_paths=paths, helpers=helpers, conversions=conversions,
                    formats=formats, progress_popups=progress,
                    pending_state={hex(off): hex(vm.read(STATE + off)) for off in (0x17c, 0x5a8, 0x5ac, 0x5fc, 0x624, 0x698)},
                    progress_window=hex(vm.read(PROGRESS + 0x50)),
                    scope="Native popup init/confirmation/CMgrBt/getter/close; popup creation, widgets, parent callbacks and OS calls are fixtures")

    names = ["Same name"] * PAIRS if duplicate else NAMES
    result = ui_case(pe, count, index // 4, None,
                     click=((0x3ed if deleting else 0x3e9) + index % 4, 2),
                     after_click=confirm, names=names)
    return dict(count=count, index=index, deleting=deleting, duplicate_names=duplicate,
                send_mode=send_mode, message_kind=message_kind, os_success_value=hex(success_value), confirmation=result["confirmation"])


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    functions = json.loads((ROOT / "analysis/functions/705md/AppMain.exe.json").read_text(encoding="utf-8"))["functions"]
    direct_sites = {0xd2930: (0xd2928, 0), 0x115a70: (0x115a6c, 0),
                    0x116078: (0x116074, 0), 0x11d284: (0x11d27c, 0), 0x12dfec: (0x12dfe4, 1)}
    owners = {next(int(f["begin_va"], 16) for f in functions
                   if int(f["begin_va"], 16) <= at < int(f["end_va"], 16)) for at in direct_sites}
    sources = {a for a, _ in APP_RANGES} | owners | {0x110708, 0xcfcb8, 0xcf77c, 0xd0b60, 0xd0f24, 0xd08b0, 0x11afcc, 0x12e48}
    src, _ = source(module, sorted(sources), {0x12a174: 8})
    raw = (ROOT / module["path"]).read_bytes()
    draft, patch = draft_app_pairing(raw)
    original, pe = pefile.PE(data=raw), pefile.PE(data=draft)
    progress_table = original.get_data(0x17b12c - original.OPTIONAL_HEADER.ImageBase, 0x68)
    assert int.from_bytes(progress_table[0x40:0x44], "little") == 0x130a70
    assert original.get_data(0x12c24 - original.OPTIONAL_HEADER.ImageBase, 4).hex() == "2084308e"
    assert original.get_data(0x12e5c - original.OPTIONAL_HEADER.ImageBase, 4).hex() == "2484308e"
    direct_callers = []
    for at, (mode_at, mode) in direct_sites.items():
        call_word = int.from_bytes(original.get_data(at - original.OPTIONAL_HEADER.ImageBase, 4), "little")
        mode_word = int.from_bytes(original.get_data(mode_at - original.OPTIONAL_HEADER.ImageBase, 4), "little")
        assert call_word == (3 << 26) | (0x1109d4 >> 2)
        assert mode_word == 0x24070000 | mode
        direct_callers.append(dict(call_va=hex(at), mode_va=hex(mode_at), mode=mode,
                                   call_word=hex(call_word), mode_word=hex(mode_word)))
    traces = []
    for count in range(PAIRS + 1):
        for mode in (0, 1):
            for index in (*range(count + 2), 0xffffffff, 0x80000000):
                for blank in (False, True):
                    baseline = helper_case(original, count, index, mode, blank)
                    repaired = helper_case(pe, count, index, mode, blank)
                    valid = (0 <= index < count) if mode == 0 else (1 <= index <= count)
                    expected = (address_text(index - mode, "-" if mode else ":") if mode or blank
                                else NAMES[index]) if valid else "Empty"
                    assert repaired["text"] == expected
                    if mode == 0:
                        assert baseline["text"] == expected
                    elif 1 <= index < count:
                        assert baseline["text"] == expected
                    elif index == count:
                        assert baseline["text"] == "Empty"
                    traces.append(dict(original=baseline, draft=repaired, expected=expected,
                                       contract_matches=repaired["text"] == expected))
    out = ROOT / "analysis/firmware/bt-pairing-confirmation-draft"
    out.mkdir(parents=True, exist_ok=True)
    confirmation_traces = [confirmation_case(pe, count, index, deleting, duplicate)
                           for count in range(1, PAIRS + 1) for index in range(count)
                           for deleting in (False, True) for duplicate in (False, True)]
    failure_modes = ("disabled", "timeout", "error", "connect-timeout", "connect-error")
    send_failures = [confirmation_case(pe, PAIRS, index, send_mode=mode)
                     for index in range(PAIRS) for mode in failure_modes]
    before_caller = bytearray(draft)
    caller_edits = [e for e in patch["edits"] if int(e["va"], 16) in (0x115988, 0x115e60)]
    assert len(caller_edits) == 2
    for edit in caller_edits:
        at = int(edit["offset"], 16)
        before_caller[at:at + edit["bytes"]] = bytes.fromhex(edit["before_hex"])
    baseline_pe = pefile.PE(data=bytes(before_caller))
    caller_pairs = [dict(before_caller_guard=confirmation_case(baseline_pe, PAIRS, index, send_mode=mode, caller_fixed=False),
                         draft=send_failures[index * len(failure_modes) + failure_modes.index(mode)])
                    for index in range(PAIRS) for mode in failure_modes]
    retry_traces = [confirmation_case(pe, PAIRS, index, send_mode=mode, message_kind=kind, success_value=value)
                    for index in range(PAIRS) for mode in ("success", "recovered", "timeout")
                    for kind in (0, 2, 3) for value in (1, 2, 0xffffffff)]
    dependencies = ["verify_bt_pairing_confirmation.py", "verify_bt_pairing_ui.py", "verify_bt_database_io.py",
                    "verify_bt_pairing_storage.py", "draft_bt_pairing_storage.py", "draft_bt_database_io.py",
                    "patch_bt_playback.py", "inspect_bt_pairing.py", "inspect_bt_playback.py",
                    "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Helper/popup/send wrapper and disconnected-connect caller failure handling passed in interpreter",
                  sources=src, patch_sha256=patch["draft_sha256"], native_execution=False,
                  build_allowed=False, unit_tested=False, helper_traces=traces,
                  confirmation_traces=confirmation_traces, send_failure_traces=send_failures, retry_route_traces=retry_traces,
                  caller_failure_pairs=caller_pairs,
                  caller_baseline_sha256=hashlib.sha256(before_caller).hexdigest(),
                  progress_class=dict(vtable_va="0x17b12c", vtable_hex=progress_table.hex(), close_method="0x130a70",
                                      singleton_slot="0x188420", confirmation_singleton_slot="0x188424",
                                      initialized_getter_native=True, constructor_executed=False),
                  original_helper_direct_callers=direct_callers,
                  limitations=["Converter/formatter are explicit fixtures; no actual phonebook filesystem access",
                               "Original mode-one last index is rejected as Empty and zero index lacks a one-based guard",
                               "Malformed unterminated names and arbitrary count/argument values remain outside these contracts",
                               "Disconnected connect caller now handles reset/connect transport failure; other send callers and connected-profile branches remain open",
                               "Progress getter uses its initialized singleton path; constructor, showPopup and GUI callbacks remain fixtures",
                               "Native close tested with a parent window, GDI handles and no backing surface; nested popup and parent redraw branches remain open",
                               "Transport failure does not prove radio nonexecution or roll back a command already delivered",
                               "Synthetic alternate manager kinds exercise wrapper routing; actual Blue role/radio processing not proved",
                               "Connected-profile switch/disconnect paths and popup creation itself are not executed"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], helper_traces=len(traces),
                         mismatches=sum(not t["contract_matches"] for t in traces),
                         original_contract_mismatches=sum(t["original"]["text"] != t["expected"] for t in traces),
                         confirmation_traces=len(confirmation_traces), send_failure_traces=len(send_failures),
                         caller_failure_pairs=len(caller_pairs),
                         retry_route_traces=len(retry_traces)), indent=2))


if __name__ == "__main__":
    main()
