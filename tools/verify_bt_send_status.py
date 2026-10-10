"""Interpret original/patched SendMessageTimeout wrapper with ABI-clobber fixtures."""
import hashlib
import json
import re
import pefile
from inspect_bt_playback import ROOT, source
from inspect_bt_pairing import MANAGER, abi
from verify_bt_pairing_ui import UIVM, COORDINATOR, STATE
from draft_bt_pairing_storage import draft_app_pairing

SEND_API, ERROR_API = 0x1400a8, 0xf0050010
RANGES = [(0x11b464, 0x11b5c8), (0x1144b4, 0x114518)]
SCENARIOS = {
    "one": ([1], 5, True, False), "two": ([2], 5, True, False),
    "all-bits": ([0xffffffff], 5, True, False),
    "error": ([0], 5, True, False), "timeout": ([0, 0], 0x578, True, False),
    "retry-one": ([0, 1], 0x578, True, False), "retry-two": ([0, 2], 0x578, True, False),
    "disabled": ([], 5, False, False), "missing-window": ([0], 0x578, True, True),
}


def run(pe, kind, scenario, original=False, invalid_command=False):
    values, error, enabled, missing = SCENARIOS[scenario]
    vm = UIVM(pe, RANGES)
    vm.write(0x187be4, MANAGER); vm.write(MANAGER + 0xa8, STATE)
    vm.write(STATE + 0x6d4, int(enabled)); vm.write(COORDINATOR + 0x14, kind)
    vm.write(COORDINATOR + 8, 0 if missing else 0x9876)
    vm.write(0x185020, ERROR_API)
    sends, errors, finds = [], [], []
    command = 0 if invalid_command else 0x1010804

    def clobber(machine):
        for reg in (*range(2, 16), 24, 25): machine.reg[reg] = 0xcafe0000 + reg

    def send(machine):
        first_id = 0x8065 if kind == 1 else (kind + 0x806e) & 0xffffffff
        expected_id = 0x8065 if original and sends else first_id
        assert machine.reg[4:8] == [0 if missing else 0x9876, expected_id, command, 8]
        assert machine.read(machine.reg[29] + 0x10) == 0
        assert machine.read(machine.reg[29] + 0x14) == 1500
        assert machine.read(machine.reg[29] + 0x18) == machine.reg[29] + 0x20
        sends.append(dict(message_id=hex(machine.reg[5]), hwnd=hex(machine.reg[4]), command=hex(command)))
        result = 0 if missing else values[len(sends) - 1]
        # An arbitrary receiver LRESULT must not define transport success.
        machine.write(machine.reg[29] + 0x20, 0xaabbccdd)
        clobber(machine)
        return result

    def last_error(machine):
        errors.append(error); clobber(machine); return error

    def find(machine):
        finds.append(machine.reg[4:6].copy()); clobber(machine); return 0 if missing else 0x9876

    vm.hooks.update({SEND_API: send, ERROR_API: last_error, 0x140038: find})
    vm.reg[5:8] = [1, command, 8]
    abi(vm, 0x11b464, COORDINATOR)
    failed = not enabled or invalid_command or scenario in ("error", "timeout", "missing-window")
    expected = 0xffffffff if (not enabled or invalid_command or failed and not original) else 0
    assert vm.reg[2] == expected
    expected_calls = 0 if not enabled or invalid_command else 2 if error == 0x578 and not values[0] else 1
    assert len(sends) == expected_calls
    return dict(kind=hex(kind), scenario=scenario, invalid_command=invalid_command,
                return_value=hex(vm.reg[2]), sends=sends, errors=errors, window_finds=finds,
                abi_preserved=True, scope="Native wrapper/window lookup with OS fixtures that clobber all caller-saved registers")


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "705md" and m["name"] == "AppMain.exe")
    src, original_pe = source(module, [a for a, _ in RANGES], {})
    raw = (ROOT / module["path"]).read_bytes(); draft, patch = draft_app_pairing(raw)
    pe = pefile.PE(data=draft)
    pairs = [dict(original=run(original_pe, kind, scenario, True), draft=run(pe, kind, scenario))
             for kind in (0, 1, 2, 3) for scenario in SCENARIOS]
    pairs += [dict(original=run(original_pe, kind, "one", True, True), draft=run(pe, kind, "one", False, True))
              for kind in (0, 1, 2, 3)]
    # Preserve every original direct edge. This is an inventory, not proof that
    # the callers propagate status, nor proof that no indirect caller exists.
    edges = []
    functions = json.loads((ROOT / "analysis/functions/705md/AppMain.exe.json").read_text(encoding="utf-8"))["functions"]
    for line in (ROOT / "analysis/disassembly/AppMain.exe.asm").read_text(encoding="utf-8").splitlines():
        match = re.match(r"([0-9a-f]{8})\s+jal\s+0x11b464\b", line)
        if not match: continue
        va = int(match[1], 16)
        word = int.from_bytes(original_pe.get_data(va - original_pe.OPTIONAL_HEADER.ImageBase, 4), "little")
        assert word == (3 << 26) | (0x11b464 >> 2)
        owner = next((f["begin_va"] for f in functions if int(f["begin_va"], 16) <= va < int(f["end_va"], 16)), None)
        edges.append(dict(va=hex(va), caller=owner, word=hex(word), scope="Original direct JAL only"))
    out = ROOT / "analysis/firmware/bt-send-status-draft"; out.mkdir(parents=True, exist_ok=True)
    dependencies = ["verify_bt_send_status.py", "verify_bt_pairing_ui.py", "verify_bt_database_io.py", "verify_bt_pairing_storage.py",
                    "draft_bt_pairing_storage.py", "draft_bt_database_io.py", "patch_bt_playback.py", "inspect_bt_pairing.py",
                    "inspect_bt_playback.py", "inspect_wave_queue.py", "inspect_bt_lifecycle.py"]
    result = dict(status="OS send failure status and retry message ID repaired in memory-only draft",
                  native_execution=False, unit_tested=False, build_allowed=False, sources=src,
                  patch_sha256=patch["draft_sha256"], traces=pairs, original_direct_caller_edges=edges,
                  limitations=["SendMessageTimeout/windowlookup/GetLastError are fixtures; no native OS or radio",
                               "Zero means OS transport success, not receiver/radio success; receiver LRESULT is not propagated",
                               "Higher caller reactions, early key-reset failure, popup lifetime and asynchronous scheduler remain open",
                               "Direct-edge inventory does not establish return-value consumption or absence of indirect callers"],
                  dependencies={p: hashlib.sha256((ROOT / "tools" / p).read_bytes()).hexdigest() for p in dependencies})
    (out / "contracts.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(status=result["status"], original_draft_pairs=len(pairs), direct_callers=len(edges)), indent=2))


if __name__ == "__main__": main()
