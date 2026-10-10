"""Follow original SC primitive 0xc dispatch with explicit queue/profile fixtures.

No live CSR scheduler or radio. Native dispatch and DB code are interpreted;
queue operations and unreviewed profile/confirmation helpers are hooks.
"""
import hashlib
import json
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import put, data
from verify_bt_database_io import Database, HEADER
from verify_bt_pairing_storage import records
from verify_bt_pairing_ui import UIVM
from draft_bt_pairing_storage import draft_blue_storage, PAIRS

CONTEXT, MESSAGE, QUEUED, ALLOCATION = 0x54000000, 0x55000000, 0x56000000, 0x57000000
SC_RANGES = [(0xbb80c, 0xbbd68), (0xc53f0, 0xc5468),
             (0xc4870, 0xc4924), (0xc4924, 0xc4b28)]


def case(pe, index, scenario, read_error=False):
    items = records(PAIRS)
    db = Database(pe, HEADER + b"".join(items))
    old = db.vm
    vm = UIVM(pe, [*old.ranges, *SC_RANGES])
    vm.mem = old.mem
    vm.hooks = old.hooks
    db.vm = vm
    if read_error:
        assert scenario == "queued"
        db.read_overrides[104] = (False, 0)
    # Signed halfword jump table is data, not generated fixture branches.
    put(vm, 0xbb84c, pe.get_data(0xbb84c - pe.OPTIONAL_HEADER.ImageBase, 68))
    put(vm, MESSAGE, bytes(16)); vm.write(MESSAGE, 0xc, 2)
    vm.write(MESSAGE + 2, 0x323, 2); put(vm, MESSAGE + 4, items[index][:8])
    vm.write(MESSAGE + 0xc, 0, 1)  # Actual GUI sender explicitly stores this byte.
    vm.write(CONTEXT + 0x1c, MESSAGE); vm.write(CONTEXT, 0x323, 2)
    state = {"active": 2, "wrong-address": 2, "wrong-phase": 2,
             "queued": 2, "state-one": 1, "state-three": 3}[scenario]
    vm.write(CONTEXT + 4, state, 1)
    put(vm, CONTEXT + 0x44, items[index][:8] if scenario != "wrong-address" else items[(index + 1) % PAIRS][:8])
    vm.write(CONTEXT + 0x13d, 1 if scenario in ("active", "wrong-address") else 0, 1)
    vm.write(CONTEXT + 0x29, 5, 1)
    vm.write(CONTEXT + 0x80, 0xa5, 1); vm.write(CONTEXT + 0x82, 0xa5, 1)
    put(vm, QUEUED, bytes(16)); vm.write(QUEUED, 1, 2)
    vm.write(QUEUED + 2, 0x323, 2); put(vm, QUEUED + 4, items[index][:8])
    pending = [QUEUED] if scenario == "queued" else []
    actions, freed, queue_reads = [], [], []

    def queue_read(machine):
        assert machine.reg[4] == CONTEXT + 0x20
        queue_reads.append(len(pending))
        if not pending: return 0
        machine.write(machine.reg[5], 0x102, 2)
        machine.write(machine.reg[6], pending.pop(0))
        return 1

    def allocate(machine):
        assert machine.reg[4] in (16, 36)
        put(machine, ALLOCATION, bytes(machine.reg[4]))
        return ALLOCATION

    def forward(machine):
        payload = data(machine, machine.reg[4], 16)
        assert int.from_bytes(payload[:2], "little") == 0x218
        assert payload[4:12] == items[index][:8] and payload[12:14] == b"\x01\x00"
        actions.append(dict(helper="0x782a8", payload_hex=payload.hex()))
        return 0

    def service_discovery(machine):
        payload = data(machine, machine.reg[4], 36)
        assert int.from_bytes(payload[:2], "little") == 0x11
        assert payload[4:12] == items[index][:8]
        actions.append(dict(helper="0x7998c", payload_hex=payload.hex()))
        return 0

    def action(at):
        def hooked(machine):
            actions.append(dict(helper=hex(at), arguments=machine.reg[4:8].copy()))
            return 0
        return hooked

    def free(machine):
        freed.append(machine.reg[4]); return 0

    vm.hooks.update({0x82b44: queue_read, 0x85b70: allocate, 0x85bb8: free,
                     0x782a8: forward, 0x7998c: service_discovery,
                     **{at: action(at) for at in (0xc85b8, 0xc2248, 0xc20f0, 0xc2df8,
                                                  0xc2c3c, 0xc66a0, 0x85d4c)}})
    db.call(0xbb80c, CONTEXT)
    if scenario == "active":
        assert [a["helper"] for a in actions] == ["0x782a8", "0xc85b8", "0xc2248", "0xc20f0", "0xc2df8"]
        assert vm.read(CONTEXT + 0x13d, 1) == 2
        assert vm.read(CONTEXT + 0x80, 1) == vm.read(CONTEXT + 0x82, 1) == 0
        assert not queue_reads and not freed
        assert bytes(db.contents) == HEADER + b"".join(items)
    elif scenario == "queued":
        assert [a["helper"] for a in actions] == ["0x7998c", "0xc2c3c", "0xc66a0"]
        assert freed == [QUEUED] and queue_reads == [1, 0]
        expected = items if read_error else items[:index] + items[index + 1:] + [bytes(104)]
        assert bytes(db.contents) == HEADER + b"".join(expected)
        assert len([e for e in db.events if e["kind"] == "write"]) == int(not read_error)
    else:
        assert [a["helper"] for a in actions] == ([] if state == 1 else ["0x85d4c"])
        assert queue_reads == [0] and not freed
        assert bytes(db.contents) == HEADER + b"".join(items)
    assert not db.handles
    return dict(index=index, scenario=scenario, read_error=read_error, sc_state=state, actions=actions,
                freed=freed, queue_reads=queue_reads, file_events=db.events,
                scope="Original SC dispatch/branches and patched DB chain; queue/profile/confirmation helpers are explicit fixtures")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "Blue.exe")
    src, _ = source(module, [a for a, _ in SC_RANGES], {})
    raw = (ROOT / module["path"]).read_bytes()
    draft, patch = draft_blue_storage(raw)
    pe = pefile.PE(data=draft)
    checks = [case(pe, index, scenario) for index in range(PAIRS)
              for scenario in ("active", "wrong-address", "wrong-phase", "queued", "state-one", "state-three")]
    failures = [case(pe, index, "queued", True) for index in range(PAIRS)]
    table = raw[pe.get_offset_from_rva(0xbb84c - pe.OPTIONAL_HEADER.ImageBase):][:68]
    assert int.from_bytes(table[24:26], "little", signed=True) + 0xbb84c == 0xbbbe4
    out = ROOT / "analysis/firmware/bt-security-cancel-draft"
    out.mkdir(parents=True, exist_ok=True)
    dependencies = ["verify_bt_security_cancel.py", "verify_bt_pairing_ui.py", "verify_bt_database_io.py",
                    "verify_bt_pairing_storage.py", "draft_bt_pairing_storage.py", "draft_bt_database_io.py",
                    "patch_bt_playback.py", "inspect_bt_pairing.py", "inspect_bt_playback.py",
                    "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="SC primitive 0xc conditional paths passed in explicit fixtures",
                  source=src, patch_sha256=patch["draft_sha256"], native_execution=False,
                  unit_tested=False, build_allowed=False, checks=checks, persistence_failure_traces=failures,
                  switch_table=dict(va="0xbb84c", hex=table.hex(), sha256=hashlib.sha256(table).hexdigest()),
                  limitations=["Queue operations and unreviewed profile/confirmation helpers are explicit hooks",
                               "Independent receiver fixtures; no asynchronous scheduler or end-to-end combined connection proof",
                               "Queued matching type-1 request can lead to persistence deletion even though HFP lookup is separately guarded",
                               "Queued path performs its notification/cleanup calls before deletion and ignores a failed deletion scan",
                               "Other queued classes/requests, helper internals and radio cancellation outcome remain open"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], checks=len(checks), persistence_failure_traces=len(failures),
                          report=str(out / "contracts.json")), indent=2))


if __name__ == "__main__":
    main()
