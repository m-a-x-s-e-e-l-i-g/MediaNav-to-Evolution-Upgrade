"""Interpret Blue list-request publication and AppMain list-end copy.

Two separate byte interpreters, linked only by explicit shared-memory/message
fixtures. No firmware execution, scheduler, radio, or flashable output.
"""
import hashlib
import json
import re
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, MANAGER, put, data, abi
from verify_bt_database_io import Database, HEADER
from verify_bt_pairing_storage import records
from verify_bt_pairing_ui import UIVM, SHARED, STATE, COORDINATOR
from draft_bt_pairing_storage import draft_blue_storage, draft_app_pairing, PAIRS

HF, MEDIA, MESSAGE, ERROR_API = 0x53000000, 0x54000000, 0x55000000, 0xf0080010
EXTRA = [(0x2fec4, 0x2ff30), (0x32f00, 0x3307c), (0x344f4, 0x3453c),
         (0x34310, 0x3435c), (0x337dc, 0x33860), (0x33538, 0x336a8),
         (0x3184c, 0x31854)]
APP_RANGES = [(0x121630, 0x12186c), (0x110708, 0x1108f0), (0x11afcc, 0x11b044)]


def app_receive(pe, bank, count):
    vm = UIVM(pe, APP_RANGES)
    for address, value in [(0x187be4, MANAGER), (MANAGER + 0xa0, OBJECT),
                           (MANAGER + 0xa8, STATE), (OBJECT + 0xc, SHARED),
                           (OBJECT + 0x5c0, SHARED), (STATE + 0x618, 1),
                           (STATE + 0x614, 1), (STATE + 0x174, 1),
                           (COORDINATOR + 0x18, 2), (MESSAGE + 8, 0x4010702),
                           (MESSAGE + 0xc, count), (0x186100, 0),
                           (0x1852bc, ERROR_API)]: vm.write(address, value)
    put(vm, SHARED, bank)
    render_calls = []
    def render(machine):
        render_calls.append(machine.reg[4:8].copy()); return 0
    vm.hooks.update({ERROR_API: lambda _: 0, 0x1f0a4: lambda _: 0x56000000,
                     0xd0794: render, 0xcfcb8: render})
    vm.reg[5] = MESSAGE
    abi(vm, 0x121630, COORDINATOR)
    assert vm.read(OBJECT + 0x26c) == count and vm.read(STATE + 0x628) == 1
    assert data(vm, OBJECT + 0x270, count * 64) == bank[:count * 64]
    assert data(vm, OBJECT + 0x270 + count * 64, (PAIRS - count) * 64) == bytes((PAIRS - count) * 64)
    if count == 0:
        assert vm.read(OBJECT + 0x5c0) == 0
        assert all(vm.read(STATE + off) == 0 for off in (0x174, 0x614, 0x618))
        assert vm.read(COORDINATOR + 0x18) == 0
    return dict(count=count, active_index=vm.read(OBJECT + 0x5a4),
                active_pointer=hex(vm.read(OBJECT + 0x5c0)), rendered_hooks=len(render_calls),
                connected=vm.read(STATE + 0x618))


def case(blue, app, count, hf=True, media=False, read_error=False, transport="success", reload_guard=True, selected=None, write_fault=None, receiver=False, initial_selected=None, receiver_status=0):
    items = records(count)
    if initial_selected is not None:
        assert 0 <= initial_selected < count
        items = [items[initial_selected]] + items[:initial_selected] + items[initial_selected + 1:]
    db = Database(blue, HEADER + b"".join(items))
    if receiver:
        old = db.vm
        db.vm = UIVM(blue, old.ranges)
        db.vm.mem, db.vm.hooks = old.mem, old.hooks
    vm = db.vm; vm.ranges += EXTRA
    # The singleton +10 is the actual device object, not an unrelated fixture.
    vm.write(0x20e1e8, OBJECT - 0x10)
    vm.write(OBJECT - 0x10 + 0x264, HF); vm.write(OBJECT - 0x10 + 0x268, MEDIA)
    vm.write(HF + 0x54, 0, 1); vm.write(HF + 5, int(hf), 1)
    vm.write(HF + 0x4c, 3, 1); vm.write(MEDIA + 0xe, 0, 1)
    vm.write(MEDIA + 0x21, int(media), 1)
    vm.write(0x20e200, SHARED); vm.write(0x110cf0, 1)
    vm.write(OBJECT + 4, PAIRS, 1); vm.write(OBJECT + 5, PAIRS, 1)
    stale = bytes([0xa5]) * (PAIRS * 64)
    put(vm, SHARED, stale)
    vm.write(0x110060, ERROR_API); vm.write(0x110ce8, 0x7777)
    if read_error == "header" or read_error is True: db.header_read_bool = False
    elif read_error == "bulk-false-full": db.read_overrides[832] = (False, 832)
    elif read_error == "bulk-partial": db.read_overrides[832] = (True, 831)
    elif read_error == "seek": db.seek_fail = True
    if write_fault:
        assert selected is not None and count == PAIRS
        db.write_bool = write_fault == "partial"
        db.write_reported = {"false-full": 832, "partial": 831, "false-zero": 0}[write_fault]
    sends, copies = [], []
    def cstr(machine, address):
        return bytes(machine.read(address + i, 1) for i in range(50)).split(b"\0")[0]
    def string_source(machine): return machine.reg[4]
    def string_copy(machine):
        dest, src, cap = machine.reg[4:7]
        value = cstr(machine, src)[:cap]
        put(machine, dest, value + bytes(cap - len(value)))
        return dest
    def shared_copy(machine):
        dest, src, size = machine.reg[4:7]
        assert size == 64 and SHARED <= dest < SHARED + PAIRS * 64
        value = data(machine, src, size); put(machine, dest, value)
        copies.append(dict(index=(dest - SHARED) // 64, bytes_hex=value.hex()))
        return dest
    def send(machine):
        assert machine.reg[4:7] == [0x7777, 0x8066, 0x4010702]
        value = machine.reg[7]
        assert machine.read(machine.reg[29] + 0x14) == 1500
        success = transport == "success" or transport == "retry" and len(sends) % 2 == 1
        notification = dict(packed_count=hex(value), low_count=value & 0xffff,
                            high_count=value >> 16, published_before_send=len(copies),
                            transport_success=success)
        if success: notification["app"] = app_receive(app, data(machine, SHARED, PAIRS * 64), value & 0xffff)
        sends.append(notification)
        machine.write(machine.read(machine.reg[29] + 0x18), 0)
        for reg in (*range(2, 16), 24, 25): machine.reg[reg] = 0xcafe0000 + reg
        return int(success)
    def window(machine):
        machine.write(0x110ce8, 0x7777)
        return 0x110ce8
    vm.hooks.pop(0x32f00); vm.hooks.pop(0x337dc)
    vm.hooks.update({0x8ac14: db.memset, 0x8362c: string_source, 0x85834: string_copy,
                     0x8ac04: shared_copy, 0x33304: window,
                     0x8a920: send, ERROR_API: lambda _: 0x578,
                     0x8a7c0: lambda _: 0, 0x34264: lambda _: 0})
    if receiver:
        assert selected is None
        vm.ranges += [(0x33d34, 0x33f90), (0x31634, 0x31718), (0x30f08, 0x311c0),
                      (0x2e644, 0x2e67c), (0x30280, 0x302a8)]
        put(vm, 0x31670, blue.get_data(0x31670 - blue.OPTIONAL_HEADER.ImageBase, 32))
        vm.write(0x20e1f0, OBJECT); vm.write(OBJECT - 0x10 + 0x288, 1, 1)
        vm.reg[6:8] = [0x1010702, 0]
        db.call(0x33d34, 0x7777, 0x8070)
        assert vm.reg[2] == receiver_status
    elif selected is None:
        db.call(0x2fec4, OBJECT, 0)
    else:
        assert 0 <= selected < count
        put(vm, 0x57000000, items[selected][:8])
        db.call(0x3307c, OBJECT, 0x57000000)
    bank = data(vm, SHARED, PAIRS * 64)
    if read_error or write_fault:
        assert not copies and bank == stale
        assert len(sends) == (0 if reload_guard else 1 if transport == "success" else 2)
        assert all(s["low_count"] == PAIRS for s in sends)
        assert vm.read(OBJECT + 4, 1) == vm.read(OBJECT + 5, 1) == PAIRS
        if write_fault:
            reordered = b"".join([items[selected]] + items[:selected] + items[selected + 1:])
            transferred = db.write_reported
            assert bytes(db.contents) == HEADER + reordered[:transferred] + b"".join(items)[transferred:]
            assert vm.reg[2] == 0
    else:
        assert len(copies) == count
        reordered = items if selected is None else [items[selected]] + items[:selected] + items[selected + 1:]
        for index, item in enumerate(reordered):
            rec = bank[index * 64:(index + 1) * 64]
            assert rec[4:12] == item[:8] and rec[12:62].split(b"\0")[0] == item[0x1a:0x4c].split(b"\0")[0]
            assert rec[0] == int(hf and index == 0) and rec[1] == int(media and index == 0)
            assert rec[3] == (3 if index == 0 else 0)
        assert len(sends) == ((2 if transport == "success" else 4) if selected is None else
                              (1 if transport == "success" else 2))
        assert all(s["low_count"] == s["high_count"] == count for s in sends)
        assert all(s["published_before_send"] == count for s in sends)
        if selected is not None:
            assert bytes(db.contents) == HEADER + b"".join(reordered) + bytes((PAIRS - count) * 104)
            assert all(s["app"]["active_index"] == 0 and s["app"]["active_pointer"] == hex(SHARED)
                       for s in sends if s["transport_success"])
    return dict(count=count, hf=hf, media=media, read_error=read_error, transport=transport,
                copied_records=copies, notifications=sends, file_events=db.events,
                returned_status=vm.reg[2], bank_changed=bank != stale, reload_guard=reload_guard,
                selected_before_reorder=selected, reorder_write_fault=write_fault,
                receiver_entry=receiver, initial_selected=initial_selected)


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    modules = {m["name"]: m for m in modules if m["origin"] == "705md"}
    blue_raw = (ROOT / modules["Blue.exe"]["path"]).read_bytes()
    app_raw = (ROOT / modules["AppMain.exe"]["path"]).read_bytes()
    blue_bytes, bp = draft_blue_storage(blue_raw); app_bytes, ap = draft_app_pairing(app_raw)
    blue, app = pefile.PE(data=blue_bytes), pefile.PE(data=app_bytes)
    before_guard = bytearray(blue_bytes)
    offset = blue.get_offset_from_rva(0x2fee8 - blue.OPTIONAL_HEADER.ImageBase)
    before_guard[offset:offset + 0x34] = blue_raw[offset:offset + 0x34]
    baseline = pefile.PE(data=bytes(before_guard))
    checks = [case(blue, app, n, hf, media) for n in range(PAIRS + 1) for hf in (False, True) for media in (False, True)]
    original_checks = [case(baseline, app, n, hf, media, reload_guard=False)
                       for n in range(PAIRS + 1) for hf in (False, True) for media in (False, True)]
    for before, after in zip(original_checks, checks):
        assert {k: v for k, v in before.items() if k != "reload_guard"} == {
            k: v for k, v in after.items() if k != "reload_guard"}
    faults = [case(blue, app, n, read_error=fail, transport=mode)
              for n in (0, 5, 8) for fail in (False, "header", "bulk-false-full", "bulk-partial", "seek")
              for mode in ("success", "timeout", "retry")]
    original_faults = [case(baseline, app, n, read_error=fail, transport=mode, reload_guard=False)
                       for n in (0, 5, 8) for fail in ("header", "bulk-false-full", "bulk-partial", "seek")
                       for mode in ("success", "timeout", "retry")]
    reordered_checks = [case(blue, app, n, selected=index) for n in range(1, PAIRS + 1) for index in range(n)]
    reorder_failures = [case(blue, app, PAIRS, selected=index, write_fault=mode)
                        for index in range(PAIRS) for mode in ("false-full", "partial", "false-zero")]
    bs, _ = source(modules["Blue.exe"], [a for a, _ in EXTRA] +
                   [0x3307c, 0x31c84, 0x7a8a8, 0x7a974, 0x7a3d8, 0x860ac, 0x860f8], {0x3184c: 8})
    aps, _ = source(modules["AppMain.exe"], [a for a, _ in APP_RANGES], {})
    deps = ["verify_bt_list_publication.py", "verify_bt_database_io.py", "verify_bt_pairing_storage.py",
            "verify_bt_pairing_ui.py", "draft_bt_pairing_storage.py", "draft_bt_database_io.py",
            "patch_bt_playback.py", "inspect_bt_pairing.py", "inspect_bt_playback.py",
            "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="native list publication/copy fixtures passed; failed reload count notification suppressed",
                  native_execution=False, unit_tested=False, build_allowed=False,
                  blue_source=bs, app_source=aps, blue_patch_sha256=bp["draft_sha256"],
                  app_patch_sha256=ap["draft_sha256"], checks=checks, fault_cases=faults,
                  original_caller_fault_cases=original_faults, original_caller_valid_cases=original_checks,
                  reordered_device_cases=reordered_checks,
                  reorder_write_failure_cases=reorder_failures,
                  original_direct_call_sites=[line.strip() for line in
                     (ROOT / "analysis/disassembly/Blue.exe.asm").read_text(encoding="utf-8").splitlines()
                     if re.match(r"^[0-9a-f]{8}  jal\s+0x2fec4\b", line)],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps},
                  limitations=["String resolution/copy, file APIs and OS transport are explicit fixtures",
                               "Two VMs use an explicit shared snapshot/message bridge; no scheduler or reentrancy proof",
                               "App callback native count/copy/state updates; redraw/getters/debug are hooks",
                               "Native reload/move-to-front/persistence/publication is linked; whole CSR HF-handler entry remains unexecuted",
                               "Failed reload now retains old count/shared bank without claiming a refreshed list",
                               "Outer OS-request success still cannot prove DB refresh to the HFP callback; freshness protocol open"])
    out = ROOT / "analysis/firmware/bt-list-publication-draft"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(checks=len(checks), faults=len(faults), original_faults=len(original_faults),
                         reordered=len(reordered_checks), reorder_failures=len(reorder_failures),
                         blue_sha=bp["draft_sha256"], app_sha=ap["draft_sha256"])))


if __name__ == "__main__": main()
