"""Interpret separate eight-slot deletion-status repair and GUI failure guard.

File APIs and profile/CSR boundaries are fixtures. Partial writes can modify the
file even when rejected; this is not rollback, native execution or integration.
"""
import hashlib
import json

import pefile
from draft_bt_delete_status import blue_delete_status
from draft_bt_pairing_storage import draft_blue_storage, PAIRS, RECORD_BYTES
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import MANAGER, data, put
from verify_bt_database_io import Database, HEADER
from verify_bt_pairing_storage import records
from verify_bt_pairing_commands import COMMAND_RANGES, PHONE_BANK, HFP, A2DP, MESSAGE


FAULTS = (None, "header", "scan", "bulk", "open", "seek",
          "write-false-zero", "write-false-full", "write-short", "write-zero", "write-long")


def configure(db, fault):
    if fault == "header": db.header_read_bool = False
    elif fault == "scan": db.read_overrides[104] = (False, 104)
    elif fault == "bulk": db.read_overrides[832] = (True, 831)
    elif fault == "open": db.bulk_open_fail = True
    elif fault == "seek": db.seek_fail = True
    elif fault == "write-false-zero": db.write_bool, db.write_reported = False, 0
    elif fault == "write-false-full": db.write_bool, db.write_reported = False, 832
    elif fault == "write-short": db.write_reported = 831
    elif fault == "write-zero": db.write_reported = 0
    elif fault == "write-long": db.write_reported = 833
    else: assert fault is None


def direct(pe, count, index, fault=None, address=False, missing=False):
    items = records(count)
    db = Database(pe, HEADER + b"".join(items))
    configure(db, fault)
    # Both delete functions must retain status across a call-clobbering cookie
    # helper. The ordinary fixture returned zero and exposed this lost result.
    cookie = db.vm.hooks[0x8ac24]
    def clobber_cookie(vm):
        cookie(vm)
        vm.reg[3] = 0xdeadc0de
        return 0xa5a5a5a5
    db.vm.hooks[0x8ac24] = clobber_cookie
    before = bytes(db.contents)
    target = 0x57000000
    if address:
        put(db.vm, target, bytes.fromhex("abcdef1234005634") if missing else items[index][:8])
    legacy = db.call(0x7ab4c if address else 0x7aa40, target if address else index)
    returned = db.vm.reg[3]
    assert legacy == 0xa5a5a5a5, "Legacy cookie return in v0 changed"
    success = fault is None and not missing and 0 <= index < min(count, PAIRS)
    # Compactor takes a slot, not a logical record count. Invalid logical slots
    # are intentionally not exercised here; raw DWORD/index bounds are below.
    assert returned == int(success), (count, index, fault, address, missing, hex(returned))
    writes = [e for e in db.events if e["kind"] == "write"]
    if success:
        expected = items[:index] + items[index + 1:] + [bytes(RECORD_BYTES)] * (PAIRS - count + 1)
        assert bytes(db.contents) == HEADER + b"".join(expected)
        assert len(writes) == 1 and writes[0]["requested"] == 832
    elif not (fault and fault.startswith("write-")):
        assert not writes and bytes(db.contents) == before
    return dict(records=count, index=index, by_address=address, missing=missing, fault=fault,
                returned_v1=returned, legacy_v0=hex(legacy), file_changed=bytes(db.contents) != before,
                before_sha256=hashlib.sha256(before).hexdigest(),
                after_sha256=hashlib.sha256(db.contents).hexdigest(),
                events=db.events, abi_preserved=True,
                scope="Native delete/helper/wrapper/cookie chain; file and cookie APIs are fixtures")


def gui(pe, count, index, fault=None, connected=False, repaired=True):
    items = records(count)
    db = Database(pe, HEADER + b"".join(items)); configure(db, fault)
    vm = db.vm
    vm.ranges = [*vm.ranges, *COMMAND_RANGES]
    vm.write(0x20e200, PHONE_BANK)
    vm.write(MANAGER + 0x264, HFP); vm.write(MANAGER + 0x268, A2DP)
    vm.write(MANAGER + 0x278, 2); vm.write(MANAGER + 0x2e4, 0x5a, 1)
    vm.write(0x218652, 0x322, 2); vm.write(0x218638, 0x323, 2)
    vm.write(A2DP + 0xe, 0, 1); vm.write(A2DP + 0x21, int(connected), 1)
    vm.write(HFP + 0x54, 0, 1); vm.write(HFP + 5, int(connected), 1)
    for n, item in enumerate(items):
        shared = bytearray(64); shared[4:12] = item[:8]
        put(vm, PHONE_BANK + n * 64, shared)
    put(vm, MANAGER + 0x18, bytes([0xa5]) * 16)
    requests, disconnects = [], []
    def enqueue(machine):
        assert machine.reg[4:6] == [0x322, 0x102]
        payload = data(machine, machine.reg[6], 16)
        assert payload[4:12] == items[index][:8]
        requests.append(payload.hex()); return 0
    def disconnect(machine):
        disconnects.append(machine.reg[4:6].copy()); return 0
    vm.hooks.update({0x8a7c0: lambda _: 0, 0x34264: lambda _: 0,
                     0x85b70: lambda _: 0x53000000, 0x84ec8: enqueue,
                     0x2fbd8: disconnect})
    put(vm, MESSAGE, bytes(0x14))
    vm.write(MESSAGE + 8, 0x1010701); vm.write(MESSAGE + 0xc, index + 1)
    before = bytes(db.contents)
    db.call(0x30f08, MANAGER, MESSAGE)
    final_state = vm.read(MANAGER + 0x278)
    final_pending = vm.read(MANAGER + 0x2e4, 1)
    if fault and repaired:
        assert not requests and not disconnects
        assert (final_state, final_pending) == (2, 0x5a)
    else:
        if index == 0 and connected:
            assert disconnects == [[MANAGER, 7], [MANAGER, 4]]
            assert not requests and (final_state, final_pending) == (2, 1)
        else:
            assert len(requests) == 1 and not disconnects
            assert (final_state, final_pending) == (11, 0)
    writes = [e for e in db.events if e["kind"] == "write"]
    if fault is None:
        expected = items[:index] + items[index + 1:] + [bytes(RECORD_BYTES)] * (PAIRS - count + 1)
        assert bytes(db.contents) == HEADER + b"".join(expected) and len(writes) == 1
    elif not fault.startswith("write-"):
        assert not writes and bytes(db.contents) == before
    return dict(records=count, index=index, fault=fault, connected=connected,
                repaired=repaired, state=final_state, delete_pending=final_pending,
                security_requests=requests, profile_disconnect_calls=disconnects,
                file_changed=bytes(db.contents) != before, events=db.events, abi_preserved=True,
                scope="GUI dispatcher and delete/storage chain; profile disconnect and CSR queue APIs are hooks")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    raw = (ROOT / module["path"]).read_bytes()
    old, _ = draft_blue_storage(raw); new, patch = blue_delete_status(raw)
    before, after = pefile.PE(data=old), pefile.PE(data=new)
    sources, _ = source(module, [0x7aa40, 0x7ab4c, 0x2ff30], {})
    valid = [direct(after, n, i, address=address) for n in range(1, 9)
             for i in range(n) for address in (False, True)]
    failures = [direct(after, 8, i, fault, address) for i in range(8)
                for fault in FAULTS[1:] for address in (False, True)
                if address or fault != "scan"]
    missing = [direct(after, n, 0, address=True, missing=True) for n in range(1, 9)]
    bounds = [direct(after, 8, i) for i in (8, 16, 0x80000000, 0xffffffff)]
    normal = [gui(after, n, i, connected=active) for n in range(1, 9)
              for i in range(n) for active in (False, True)]
    guarded = [gui(after, 8, i, fault, active) for i in range(8)
               for fault in FAULTS[1:] for active in (False, True)]
    baseline = [gui(before, 8, i, fault, active, repaired=False)
                for i in (0, 7) for fault in ("scan", "bulk", "write-short") for active in (False, True)]
    funcs = json.loads((ROOT / "analysis/functions/705md/Blue.exe.json").read_text(encoding="utf-8"))["functions"]
    callers = [dict(function=f["begin_va"], call=c["va"], target=c["target_va"])
               for f in funcs for c in f.get("direct_calls", []) if c["target_va"] in ("0x7ab4c", "0x7aa40")]
    assert len(callers) == 10 and [c["call"] for c in callers if c["target"] == "0x7aa40"] == ["0x7ac00"]
    original = pefile.PE(data=raw)
    for edge in callers:
        at = int(edge["call"], 16)
        saved = original.get_data(at - original.OPTIONAL_HEADER.ImageBase, 8)
        word = int.from_bytes(saved[:4], "little")
        assert word >> 26 == 3 and ((word & 0x3ffffff) << 2) == int(edge["target"], 16)
        edge["original_call_and_delay_hex"] = saved.hex()
    deps = ("draft_bt_delete_status.py", "verify_bt_delete_status.py", "draft_bt_pairing_storage.py",
            "draft_bt_database_io.py", "draft_bt_list_ack.py", "verify_bt_database_io.py",
            "verify_bt_pairing_commands.py", "verify_bt_pairing_storage.py", "inspect_bt_pairing.py",
            "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py", "patch_bt_playback.py")
    result = dict(status="Separate eight-slot delete-result repair and GUI persistence-failure guard passed",
                  native_execution=False, executable_written=False, unit_tested=False, build_allowed=False,
                  source=sources, patch=patch, direct_callers=callers, valid_cases=valid,
                  failure_cases=failures, missing_cases=missing, bounds_cases=bounds,
                  gui_valid_cases=normal, gui_failure_cases=guarded, baseline_cases=baseline,
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in deps},
                  limitations=["Separate storage variant; combined fixture remains excluded pending user steering",
                               "No CE/radio/profile/controller/concurrency/native unwind validation",
                               "Recognized partial or false-full writes can still mutate the file; no atomic rollback",
                               "Eight other direct address-delete callers keep their existing result handling",
                               "GUI failure now preserves prior state; no new error notification or App progress cleanup",
                               "Cookie, file, profile disconnect and CSR queue boundaries are explicit fixtures"])
    out = ROOT / "analysis/firmware/bt-delete-status-draft"; out.mkdir(parents=True, exist_ok=True)
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], valid=len(valid), failures=len(failures),
                         missing=len(missing), bounds=len(bounds), gui_valid=len(normal),
                         gui_failures=len(guarded), baseline=len(baseline),
                         blue_sha256=patch["draft_sha256"]), indent=2))


if __name__ == "__main__": main()
