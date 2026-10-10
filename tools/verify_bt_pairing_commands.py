"""Follow Blue's original GUI dispatcher through eight-slot connect/delete paths.

Record I/O executes patched bytes. Radio calls and OS APIs are explicit fixtures;
no native firmware, real database or physical Bluetooth unit is used.
"""
import hashlib
import json
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import MANAGER, put, data
from verify_bt_database_io import Database, HEADER
from verify_bt_pairing_storage import records
from draft_bt_pairing_storage import draft_blue_storage, PAIRS, RECORD_BYTES

PHONE_BANK, HFP, A2DP, MESSAGE, HF_OBJECT = 0x4e000000, 0x4f000000, 0x50000000, 0x51000000, 0x52000000
COMMAND_RANGES = [(0x30f08, 0x311c0), (0x2f5f0, 0x2f870), (0x2ff30, 0x30110),
                  (0x3453c, 0x3459c), (0x34384, 0x343ec), (0x332b0, 0x33304),
                  (0x31f58, 0x31f64), (0x31ac0, 0x31ad4), (0x31ad4, 0x31ae8),
                  (0x31ae8, 0x31b40), (0x7963c, 0x79664)]


def case(pe, count, index, deleting=False, read_error=False, guard=True, radio_ok=True, connection_state=2):
    items = records(count)
    db = Database(pe, HEADER + b"".join(items))
    db.vm.ranges = [*db.vm.ranges, *COMMAND_RANGES]
    vm = db.vm
    vm.write(0x20e200, PHONE_BANK)  # CBlueShmem +8
    vm.write(MANAGER + 0x264, HFP); vm.write(MANAGER + 0x268, A2DP)
    vm.write(MANAGER + 0x278, connection_state)
    vm.write(0x218652, 0x322, 2); vm.write(0x218638, 0x323, 2)
    vm.write(0x110010, 0xf0030040)
    put(vm, MANAGER + 0x18, bytes([0xa5]) * 16)
    for n, item in enumerate(items):
        shared = bytearray(64)
        shared[4:12] = item[:8]; shared[12:21] = f"Device{n + 1}\0".encode()
        put(vm, PHONE_BANK + n * 64, shared)
    before_key = bytes([0xa5]) * RECORD_BYTES
    put(vm, 0x110efc, before_key)
    if read_error:
        if read_error == "header": db.header_read_bool = False
        else: db.read_overrides[104] = {True: (False, 0), "false-full": (False, 104), "partial": (True, 103)}[read_error]
    calls, security_requests, messages = [], [], []

    def connect(machine):
        assert machine.reg[4] == HF_OBJECT
        calls.append(dict(address_hex=data(machine, machine.reg[5], 8).hex(),
                          key_record_hex=data(machine, 0x110efc, RECORD_BYTES).hex()))
        return int(radio_ok)

    def notify(machine):
        messages.append(machine.reg[4:7].copy()); return 0

    def allocate(machine):
        assert machine.reg[4] == 0x10; return 0x53000000

    def enqueue(machine):
        assert machine.reg[4:6] == [0x322, 0x102]
        payload = data(machine, machine.reg[6], 16)
        assert payload[2:4] == (0x323).to_bytes(2, "little")
        assert payload[4:12] == items[index][:8]
        security_requests.append(dict(type=hex(int.from_bytes(payload[:2], "little")), payload_hex=payload.hex()))
        return 0

    def sleep(machine):
        assert machine.reg[4] == 5; return 0

    vm.hooks.update({0x8a7c0: lambda _: 0, 0x34264: lambda _: 0,
                     0x14174: lambda _: HF_OBJECT, 0x16f68: connect,
                     0x85b70: allocate, 0x84ec8: enqueue, 0xf0030040: sleep,
                     0x33390: notify, 0x33538: notify})
    put(vm, MESSAGE, bytes(0x14))
    vm.write(MESSAGE + 8, 0x1010701 if deleting else 0x1010804)
    vm.write(MESSAGE + 0xc, index + 1)
    before = bytes(db.contents)
    db.call(0x30f08, MANAGER, MESSAGE)
    assert not db.handles
    if deleting:
        assert not calls
        expected = items[:index] + items[index + 1:] + [bytes(RECORD_BYTES)] * (PAIRS - count + 1)
        if read_error:
            assert bytes(db.contents) == before and not any(e["kind"] == "write" for e in db.events)
        else:
            assert bytes(db.contents) == HEADER + b"".join(expected)
            writes = [e for e in db.events if e["kind"] == "write"]
            assert len(writes) == 1 and writes[0]["requested"] == 832
        assert len(security_requests) == 1 and security_requests[0]["type"] == "0x2"
        assert data(vm, MANAGER + 0x18, 16) == bytes([0xa5]) * 16
    else:
        assert bytes(db.contents) == before
        if read_error and guard:
            assert not calls
            assert data(vm, MANAGER + 0x18, 16) == bytes([0xa5]) * 16
            assert messages == [[2, 0x4010507, 0], [2, 0x4010504, 0]]
        else:
            assert len(calls) == 1 and calls[0]["address_hex"] == items[index][:8].hex()
            expected_key = before_key if read_error else items[index]
            assert calls[0]["key_record_hex"] == expected_key.hex()
            assert data(vm, MANAGER + 0x18, 16) == (items[index][:8] * 2 if radio_ok else bytes([0xa5]) * 16)
            assert messages == ([] if radio_ok else [[2, 0x4010507, 0], [2, 0x4010504, 0]])
        assert [r["type"] for r in security_requests] == (["0xc"] if connection_state == 4 else [])
    saved_addresses = [data(vm, MANAGER + 0x18 + offset, 8).hex() for offset in (0, 8)]
    return dict(count=count, index=index, command="delete" if deleting else "connect", read_error=read_error,
                radio_calls=calls, address_updates=saved_addresses, notifications=messages, file_events=db.events,
                security_requests=security_requests, connection_state=connection_state,
                caller_reacts_to_lookup_failure=guard if read_error and not deleting else False if read_error else None,
                original_connect_caller=not guard, radio_ok=radio_ok,
                scope="Actual dispatch/slot/address setters, failure reset and patched DB chain; HFP connection and CSR enqueue are fixtures")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    src, _ = source(module, [start for start, _ in COMMAND_RANGES], {0x31f58: 12, 0x31ac0: 20, 0x31ad4: 20})
    raw = (ROOT / module["path"]).read_bytes()
    draft, patch = draft_blue_storage(raw)
    pe = pefile.PE(data=draft)
    baseline = bytearray(draft)
    offset = pe.get_offset_from_rva(0x2f728 - pe.OPTIONAL_HEADER.ImageBase)
    baseline[offset:offset + 0x7c] = raw[offset:offset + 0x7c]
    baseline_pe = pefile.PE(data=bytes(baseline))
    checks = [case(pe, count, index, deleting) for count in range(1, PAIRS + 1)
              for index in range(count) for deleting in (False, True)]
    failures = [case(pe, PAIRS, index, deleting, True) for index in range(PAIRS) for deleting in (False, True)]
    failures += [case(pe, PAIRS, index, read_error=fault) for index in range(PAIRS)
                 for fault in ("header", "false-full", "partial")]
    security_state_cases = [case(pe, PAIRS, index, read_error=fault, connection_state=4)
                            for index in range(PAIRS) for fault in (False, True)]
    original_failures = [case(baseline_pe, PAIRS, index, False, True, guard=False) for index in range(PAIRS)]
    radio_failures = [case(pe, PAIRS, index, radio_ok=False) for index in range(PAIRS)]
    out = ROOT / "analysis/firmware/bt-pairing-command-draft"
    out.mkdir(parents=True, exist_ok=True)
    dependencies = ["verify_bt_pairing_commands.py", "verify_bt_database_io.py", "verify_bt_pairing_storage.py",
                    "draft_bt_pairing_storage.py", "draft_bt_database_io.py", "patch_bt_playback.py",
                    "inspect_bt_pairing.py", "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="eight-slot command and connection lookup-guard fixtures passed; delete status unresolved",
                  native_execution=False, unit_tested=False, build_allowed=False, source=src,
                  patch_sha256=patch["draft_sha256"], checks=checks, failure_traces=failures,
                  original_connect_caller_failure_traces=original_failures, radio_failure_traces=radio_failures,
                  security_state_cases=security_state_cases,
                  limitations=["HFP connection, CSR enqueue and OS APIs are explicit fixtures; address setters/reset use original bytes",
                               "Original connect caller failure reproduced and guarded; full CSR/HFP/profile behavior not executed",
                               "Original delete caller updates state despite a scan/read failure that prevents persistence",
                               "State 4 still enqueues SC primitive 0xc before lookup; the guard prevents HFP connect, not that earlier request",
                               "Popup confirmation, phone/profile protocol execution and native lifetime not proved"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], checks=len(checks), failure_traces=len(failures), report=str(out / "contracts.json")), indent=2))


if __name__ == "__main__":
    main()
