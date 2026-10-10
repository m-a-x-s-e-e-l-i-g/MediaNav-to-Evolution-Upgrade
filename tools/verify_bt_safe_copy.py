"""Bounded native-byte traces for the separate eight-record safe-copy draft.

Failure/shrink matrices, native UI store witnesses, list callback and coupled
HFP paths. API/heap/OS fixtures stay explicit; no CE/radio/firmware execution.
"""
import hashlib
import json
import re
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import OBJECT, MANAGER, STACK, abi, put, data
from inspect_wave_queue import STOP
from verify_bt_pairing_ui import UIVM, SHARED, STATE, COORDINATOR, DIALOG, COOKIE
import verify_bt_pairing_ui as ui
from verify_bt_data_lifecycle import Life, LifeVM, Witness
from verify_bt_list_publication import APP_RANGES as CALLBACK_RANGES, MESSAGE, ERROR_API
from verify_bt_list_ack import ConfirmedSnapshot, snapshot
from draft_bt_list_ack import app_ack, blue_ack, ACK
from draft_bt_safe_copy import app_safe_copy


class AuditVM(LifeVM):
    def __init__(self, pe):
        super().__init__(pe)
        self.reads, self.writes = [], []
    def read(self, at, size=4):
        if self.native_access and SHARED <= at < SHARED + 0x1000:
            self.reads.append(dict(pc=hex(self.pc), address=hex(at), bytes=size))
        return super().read(at, size)
    def write(self, at, value, size=4):
        if self.native_access and OBJECT <= at < OBJECT + 0x600:
            self.writes.append(dict(pc=hex(self.pc), address=hex(at), bytes=size))
        super().write(at, value, size)


def bank(active=(), media=False):
    raw = bytearray(512)
    for i in range(8):
        rec = bytearray(((i * 71 + j * 17) & 255) for j in range(64))
        rec[0:2] = bytes([int(i in active and not media), int(i in active and media)])
        raw[i * 64:(i + 1) * 64] = rec
    return bytes(raw)


def initialize(vm, count, null, active=(), media=False):
    put(vm, OBJECT + 0x230, bytes([0xa5]) * (0x5e0 - 0x230))
    vm.write(OBJECT + 0x26c, count)
    vm.write(OBJECT + 0xc, 0 if null else SHARED)
    vm.write(OBJECT + 0x5a4, 7)
    vm.write(OBJECT + 0x5c0, SHARED + 448)
    vm.write(OBJECT + 0x5ac, 1)
    raw = bank(active, media); put(vm, SHARED, raw)
    return raw


def invoke(vm, entry, arg):
    vm.native_access = True
    try: abi(vm, entry, arg)
    finally: vm.native_access = False


def copied(vm, count, null, active, raw):
    ok = count <= 8 and (count == 0 or not null)
    n = count if ok else 0
    expected = raw[:n * 64] + bytes((8 - n) * 64)
    assert data(vm, OBJECT + 0x270, 512) == expected
    found = max((i for i in active if i < n), default=None)
    assert vm.read(OBJECT + 0x26c) == n
    assert vm.read(OBJECT + 0x5a4) == (0xffffffff if found is None else found)
    assert vm.read(OBJECT + 0x5c0) == (0 if found is None else SHARED + found * 64)
    assert vm.read(OBJECT + 0x5ac) == int(found is not None)
    assert vm.reg[2] == int(ok) and vm.reg[4] == OBJECT
    assert all(SHARED <= int(r["address"], 16) and int(r["address"], 16) + r["bytes"] <= SHARED + n * 64 for r in vm.reads)
    allowed = [(OBJECT + 0x270, OBJECT + 0x470), (OBJECT + 0x5a4, OBJECT + 0x5a8),
               (OBJECT + 0x5c0, OBJECT + 0x5c4), (OBJECT + 0x5ac, OBJECT + 0x5b0)]
    if not ok: allowed += [(OBJECT + 0x26c, OBJECT + 0x270)]
    assert all(any(a <= int(w["address"], 16) and int(w["address"], 16) + w["bytes"] <= b for a, b in allowed) for w in vm.writes)
    return dict(input_count=count, null_shared=null, active=list(active), copy_success=ok,
                output_count=n, selected_index=found, bank_read_count=len(vm.reads),
                max_read_end=hex(max((int(r["address"], 16) + r["bytes"] for r in vm.reads), default=0)),
                output_sha256=hashlib.sha256(expected).hexdigest(), abi_preserved=True, a0_preserved=True)


def copy_case(pe, count, null=False, active=(), media=False):
    vm = AuditVM(pe); raw = initialize(vm, count, null, active, media)
    invoke(vm, 0x110708, OBJECT)
    return dict(**copied(vm, count, null, active, raw), media_flags=media)


def shrink_case(pe, count, null=False):
    vm = AuditVM(pe); initialize(vm, 8, False, (7,))
    invoke(vm, 0x110708, OBJECT)
    assert vm.read(OBJECT + 0x5a4) == 7
    vm.reads.clear(); vm.writes.clear()
    vm.write(OBJECT + 0x26c, count); vm.write(OBJECT + 0xc, 0 if null else SHARED)
    # Old active flag in physical slot seven remains beyond the new count.
    invoke(vm, 0x110708, OBJECT)
    trace = copied(vm, count, null, (7,), bank((7,)))
    return dict(previous_count=8, **trace)


def callback_case(pe, count, null):
    vm = AuditVM(pe); vm.ranges = CALLBACK_RANGES
    raw = initialize(vm, 8, null, (0,))
    for at, val in [(0x187be4, MANAGER), (MANAGER + 0xa0, OBJECT), (MANAGER + 0xa8, STATE),
                    (STATE + 0x618, 1), (STATE + 0x614, 1), (STATE + 0x174, 1),
                    (STATE + 0x628, 1), (COORDINATOR + 0x18, 2), (MESSAGE + 8, 0x4010702),
                    (MESSAGE + 0xc, count), (0x186100, 0), (0x1852bc, ERROR_API)]: vm.write(at, val)
    renders = []
    def render(machine): renders.append(machine.reg[4:8].copy()); return 0
    vm.hooks.update({ERROR_API: lambda _: 0, 0x1f0a4: lambda _: 0x56000000,
                     0xd0794: render, 0xcfcb8: render})
    vm.reg[5] = MESSAGE; invoke(vm, 0x121630, COORDINATOR)
    ok = count <= 8 and (count == 0 or not null); n = count if ok else 0
    assert vm.read(STATE + 0x628) == int(ok)
    assert vm.read(OBJECT + 0x26c) == n
    assert data(vm, OBJECT + 0x270, 512) == raw[:n * 64] + bytes((8 - n) * 64)
    assert vm.read(STATE + 0x618) == int(count != 0)
    if not n: assert vm.read(OBJECT + 0x5c0) == vm.read(OBJECT + 0x5ac) == 0
    return dict(message_count=count, null_shared=null, copy_ready=bool(vm.read(STATE + 0x628)),
                output_count=n, hfp_connected=vm.read(STATE + 0x618), render_hooks=len(renders), abi_preserved=True)


def refresh_witness(pe, status, transition):
    """Reuse UI API fixtures, stop after the native post-copy status-store path.

    Input publication changes at the second copy entry. This deliberately
    models a new snapshot, not a proven concurrent CE scheduling sequence.
    """
    instances = []
    class RefreshVM(UIVM):
        def __init__(self, image, ranges):
            super().__init__(image, ranges); self.copies = 0; self.stores = []; instances.append(self)
        def word(self, pc):
            if pc == 0x110708:
                self.copies += 1
                if self.copies == 2:
                    if transition == "empty": self.write(OBJECT + 0x26c, 0)
                    elif transition == "no-active":
                        self.write(SHARED, 0, 2); self.write(SHARED + 64, 0, 2)
                    elif transition == "null": self.write(OBJECT + 0xc, 0)
                    else: raise AssertionError(transition)
            if pc == 0xd0708 and self.copies == 2:
                raise Witness(dict(kind="post-status-path", pc=hex(pc)))
            return super().word(pc)
        def write(self, at, value, size=4):
            if self.copies == 2 and 0xd0684 <= self.pc < 0xd0708:
                self.stores.append(dict(pc=hex(self.pc), address=hex(at), bytes=size, value=value))
            super().write(at, value, size)
        def read(self, at, size=4):
            if self.copies == 2 and at < 0x10000:
                raise Witness(dict(kind="low-read", pc=hex(self.pc), address=hex(at)))
            return super().read(at, size)
    old = ui.UIVM; ui.UIVM = RefreshVM
    witness = None
    try: ui.case(pe, 2, 0, 1, draw=1, connected_status=status)
    except Witness as error: witness = error.event
    finally: ui.UIVM = old
    assert witness is not None and len(instances) == 1
    vm = instances[0]
    return dict(status_before_reload=status, transition=transition, witness=witness,
                indexed_stores=vm.stores, active_index=hex(vm.read(OBJECT + 0x5a4)),
                scope="Native renderer prefix and copy; stop at continuation, API/input publication fixtures; not full-return ABI proof")


def mapping_failure(pe, mode):
    f = Life(pe, mapping=mode != "mapping", view=mode != "view")
    f.vm.write(0x186560, 0); f.call(0x1103a4, 0)
    assert f.vm.read(OBJECT + 0xc) == 0
    f.vm.write(OBJECT + 0x26c, 8); f.vm.write(OBJECT + 0x5ac, 1)
    f.call(0x110708, OBJECT)
    assert f.vm.reg[2] == 0 and f.vm.read(OBJECT + 0x26c) == 0
    assert data(f.vm, OBJECT + 0x270, 512) == bytes(512)
    assert f.vm.read(OBJECT + 0x5c0) == f.vm.read(OBJECT + 0x5ac) == 0
    return dict(failure=mode, initialization_events=f.events, copy_success=False, abi_preserved=True,
                scope="Native singleton/mapping failure then injected later count eight, native copy returns")


def null_hfp(blue, app, count, popup, transport):
    f = ConfirmedSnapshot(blue, app, count, popup=popup, transport=transport)
    f.vm.write(OBJECT + 0xc, 0); f.vm.write(OBJECT + 0x5ac, 1)
    trace = f.indication(0x3040101)
    assert trace["active_index"] == "0xffffffff" and trace["active_pointer"] == "0x0"
    assert f.vm.read(OBJECT + 0x26c) == f.vm.read(OBJECT + 0x5ac) == f.vm.read(STATE + 0x664) == 0
    assert data(f.vm, OBJECT + 0x270, 512) == bytes(512)
    assert not any(e["kind"] in ("file-open", "phonebook-path", "sleep") for e in trace["events"])
    assert trace["hf_connected"] == 1 and trace["progress_window"] == "0x0"
    if transport == "success": assert f.vm.read(STATE + 0x628) == 0
    return dict(count=count, popup=popup, notification_transport=transport, trace=trace,
                output_count=0, phonebook_opened=False, abi_preserved=True)


def caller_suffix(pe, route, count, old_count, target="Empty", name="Other", null=False):
    """Native suffix starting at copy/list search, stop before outer epilogue.

    Count, desired-name and preceding caller registers are explicit fixtures;
    native helpers/copy/scan/PB/name comparison execute, command receiver stubbed.
    """
    vm = AuditVM(pe)
    vm.ranges += [(0x111d84, 0x111e08), (0x111364, 0x1115fc), (0x1109d4, 0x110b50),
                  (0x11d230, 0x11d304), (0x115c60, 0x115c9c)]
    initialize(vm, count, null)
    vm.write(OBJECT + 0x5c0, 0)
    for i in range(8):
        put(vm, SHARED + i * 64 + 12, (name + "\0").encode("utf-8") + bytes(49 - len(name)))
    for at, val in [(0x187be4, MANAGER), (MANAGER + 0xa0, OBJECT), (MANAGER + 0xa8, STATE),
                    (MANAGER + 0x28, old_count), (STATE + 0x630, 1),
                    (0x1853f4, COOKIE), (0x185088, 0xf00b0010)]: vm.write(at, val)
    put(vm, MANAGER + 0x2c, (target + "\0").encode("utf-16le"))
    put(vm, 0x176848, pe.get_data(0x176848 - pe.OPTIONAL_HEADER.ImageBase, 12))
    names, commands = [], []
    def memset(machine):
        at, value, n = machine.reg[4:7]; put(machine, at, bytes([value & 255]) * n); return at
    def convert(machine):
        raw = data(machine, machine.reg[6], machine.reg[7]).split(b"\0")[0].decode("utf-8")
        put(machine, machine.read(machine.reg[29] + 0x10), (raw + "\0").encode("utf-16le")); return len(raw)
    def connect(machine):
        commands.append(dict(command=hex(machine.reg[6]), parameter=machine.reg[7])); return 0
    vm.hooks.update({0x140de4: memset, 0x140298: lambda _: 0, 0xf00b0010: convert, 0x11b464: connect})
    original_word = vm.word
    def word(pc):
        if pc == 0x1109d4: names.append(vm.reg[5])
        return original_word(pc)
    vm.word = word
    vm.reg[29], vm.reg[31] = STACK, STOP
    if route == "profile":
        vm.reg[16], vm.reg[20], vm.reg[22] = MANAGER, COORDINATOR, 0x180000
        start, stop = 0x11d230, 0x11e33c
    else:
        vm.reg[18] = MANAGER
        start, stop = 0x115c60, 0x115ed0
    witness = None
    vm.native_access = True
    try: vm.run(start, {stop}, limit=10000)
    except Witness as error: witness = error.event
    finally: vm.native_access = False
    return dict(route=route, input_count=count, previous_manager_count=old_count, null_shared=null,
                desired_name=target, record_name=name, actual_count=vm.read(OBJECT + 0x26c),
                name_indices=names, commands=commands, witness=witness,
                pending_search=vm.read(STATE + 0x630), stop_pc=hex(vm.pc),
                scope="Native caller suffix with input/argument and API fixtures; not full caller entry/epilogue or receiver behavior")


def main():
    modules = {m["name"]: m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8")) if m["origin"] == "705md"}
    raw = (ROOT / modules["AppMain.exe"]["path"]).read_bytes()
    bb, bp = blue_ack((ROOT / modules["Blue.exe"]["path"]).read_bytes())
    old, _ = app_ack(raw); new, patch = app_safe_copy(raw)
    before, app, blue = pefile.PE(data=old), pefile.PE(data=new), pefile.PE(data=bb)
    copies = [copy_case(app, n, null, active, media) for n in range(9)
              for null in (False, True) for active in [(), *[(i,) for i in range(8)], tuple(range(8))] for media in (False, True)]
    copies += [copy_case(app, n, null, (0,)) for n in (9, 16, 0x80000000, 0xffffffff) for null in (False, True)]
    shrinks = [shrink_case(app, n, null) for n in range(9) for null in (False, True)]
    callbacks = [callback_case(app, n, null) for n in (0, 1, 5, 8, 9, 0xffffffff) for null in (False, True)]
    refreshes = []
    for status in (4, 7):
        for transition in ("empty", "no-active", "null"):
            baseline = refresh_witness(before, status, transition); repaired = refresh_witness(app, status, transition)
            if transition == "null": assert baseline["witness"]["kind"] == "low-read"
            else:
                assert baseline["indexed_stores"] == [dict(pc="0xd0704" if status == 4 else "0xd06a8", address=hex(OBJECT + 0x232), bytes=1, value=status)]
            assert repaired["witness"]["kind"] == "post-status-path" and not repaired["indexed_stores"]
            refreshes.append(dict(before=baseline, repaired=repaired))
    ui_cases = [ui.case(app, n, page, active) for n in range(1, 9) for page in range((n + 3) // 4) for active in (None, *range(n))]
    ui_cases += [ui.case(app, 8, page, active, 1, status) for page in (0, 1) for active in range(8) for status in (0, 4, 7)]
    mapping = [mapping_failure(app, mode) for mode in ("mapping", "view")]
    hf_valid = [snapshot(blue, app, n, i, popup=popup, transport=transport) for n in range(1, 9) for i in range(n) for popup in (False, True) for transport in ("success", "timeout", "retry")]
    hf_valid += [snapshot(blue, app, 0, popup=popup, transport=transport) for popup in (False, True) for transport in ("success", "timeout", "retry")]
    hf_null = [null_hfp(blue, app, n, popup, transport) for n in (1, 5, 8) for popup in (False, True) for transport in ("success", "timeout", "retry")]
    hf_invalid = [snapshot(blue, app, 8, popup=popup, fault=fault) for popup in (False, True) for fault in ("header", "bulk-partial", "bulk-false-full", "seek")]
    hf_invalid += [snapshot(blue, app, 8, popup=popup, status_override=status) for popup in (False, True) for status in (0, 0xffffffff, ACK | 9)]
    profile_pairs = []
    for n, target, name, null in [(0, "Empty", "Other", False), (0, "Missing", "Other", False),
                                 (1, "Empty", "Other", False), (1, "Missing", "Other", False),
                                 (1, "Empty", "Empty", False), (8, "Empty", "Other", True)]:
        baseline = caller_suffix(before, "profile", n, 8, target, name, null)
        repaired = caller_suffix(app, "profile", n, 8, target, name, null)
        assert repaired["witness"] is None and repaired["pending_search"] == 0
        expected = [dict(command="0x1010804", parameter=1)] if n == 1 and target == name and not null else []
        assert repaired["commands"] == expected
        assert repaired["name_indices"] == ([0] if n == 1 and not null else [])
        if null: assert baseline["witness"]["kind"] == "low-read"
        elif target == "Empty" and name != "Empty":
            assert baseline["commands"] == [dict(command="0x1010804", parameter=n + 1)]
        profile_pairs.append(dict(before=baseline, repaired=repaired))
    connect_suffixes = [caller_suffix(app, "connect", n, 8, null=null) for n in (0, 1, 8, 9, 0xffffffff)
                        for null in (False, True) if n == 0 or n > 8 or null]
    assert all(t["witness"] is None and t["actual_count"] == 0 and not t["commands"] and t["stop_pc"] == "0x115ed0" for t in connect_suffixes)
    asm = (ROOT / "analysis/disassembly/AppMain.exe.asm").read_text(encoding="utf-8")
    callers = [line for line in asm.splitlines() if re.match(r"[0-9a-f]{8}\s", line) and re.search(r"\bjal\s+0x110708\b", line)]
    assert [int(s[:8], 16) for s in callers] == [0xd067c, 0x115c60, 0x11d250, 0x11fac0, 0x121694]
    app_ranges = [(0x110708, 0x1108f0), (0xcfcb8, 0xd0794), (0x121630, 0x12186c), (0x11589c, 0x115ee8), (0x11cb00, 0x11f7d4)]
    sources, _ = source(modules["AppMain.exe"], [a for a, _ in app_ranges] +
                        [0x1103a4, 0x11b06c, 0x11afcc, 0x1109d4, 0x111d84, 0x111364, 0x11f7d4], {})
    deps = ["verify_bt_safe_copy.py", "draft_bt_safe_copy.py", "verify_bt_data_lifecycle.py", "draft_bt_list_ack.py", "verify_bt_list_ack.py", "verify_bt_ipc_roundtrip.py", "verify_bt_list_publication.py", "verify_bt_connection_success.py", "verify_bt_reconnect.py", "verify_bt_send_status.py", "verify_bt_pairing_confirmation.py", "verify_bt_database_io.py", "verify_bt_pairing_ui.py", "verify_bt_pairing_storage.py", "draft_bt_pairing_storage.py", "draft_bt_database_io.py", "patch_bt_playback.py", "inspect_bt_pairing.py", "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="Separate safe-copy variant interpreted; original UI negative-index write reproduced and guarded",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  sources=sources, app_patch=patch, blue_patch=bp, direct_copy_callers=callers,
                  copy_cases=copies, shrink_cases=shrinks, callback_cases=callbacks, ui_refresh_pairs=refreshes,
                  ui_valid_cases=ui_cases, mapping_failure_cases=mapping, hf_valid_cases=hf_valid,
                  hf_null_cases=hf_null, hf_invalid_cases=hf_invalid,
                  profile_search_pairs=profile_pairs, connect_failure_suffixes=connect_suffixes,
                  limitations=["No on-unit/native CE execution, unwind, radio, scheduler or concurrent shared-bank mutation proof",
                               "Nonzero bank pointer is assumed mapped for count records; mapping length/lifetime not validated",
                               "No cache-alias absence, auxiliary heap/allocation failure or destructor repair",
                               "Last active wins copy, first active wins separate scan retained; no new physical link semantics",
                               "List-ready field628 has other writers and is not a general snapshot freshness signal",
                               "Native UI prefix witness uses fixture publication at second copy entry, not proven runtime scheduling",
                               "Direct callers115c60/11d250 suffixes followed, complete preceding connect/profile branches remain open",
                               "Count ACK lacks snapshot generation/locking; well-formed stale ACK remains accepted",
                               "Separate prototype, not merged into base/ACK/MAX02 or enabled in the LGU builder"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps})
    out = ROOT / "analysis/firmware/bt-safe-copy-draft"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], copy=len(copies), shrink=len(shrinks), callback=len(callbacks),
                         ui_refresh_pairs=len(refreshes), ui_valid=len(ui_cases), mapping=len(mapping),
                         hf_valid=len(hf_valid), hf_null=len(hf_null), hf_invalid=len(hf_invalid),
                         profile_pairs=len(profile_pairs), connect_suffixes=len(connect_suffixes),
                         app_sha256=patch["draft_sha256"]), indent=2))


if __name__ == "__main__": main()
