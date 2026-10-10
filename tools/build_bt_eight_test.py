"""Build a numbered matched Blue/AppMain pair for explicitly requested CE tests.

This emits application files, not an LGU, installer, launcher or device write.
Checks run interpreted bytes read back from the output files. Existing prototype
build_allowed=false flags describe those prototypes, not this requested build.
"""
import argparse
import hashlib
import json
import sys
from datetime import datetime, timezone
from pathlib import Path
import zipfile

import pefile
from inspect_bt_playback import ROOT
from draft_bt_pairing_storage import draft_blue_storage
from draft_bt_list_ack import blue_ack
from draft_bt_delete_status import blue_delete_status
from draft_bt_safe_copy import app_safe_copy
from verify_bt_delete_status import direct, gui, FAULTS
from verify_bt_list_ack import snapshot
from verify_bt_safe_copy import copy_case, null_hfp
from verify_bt_pairing_ui import case as ui_case


GUIDE = r"""MediaNav 7.0.5.MD - BT8T01 application test

Use BOTH Test/Blue.exe and Test/AppMain.exe as a matched pair.
Eight means stored paired devices, not eight simultaneous connections.
These are experimental Windows CE MIPS files; they do not run on a PC.

Contents:
  Test/Blue.exe       - eight-record storage, checked database I/O,
                       list ACK and delete-persistence guard.
  Test/AppMain.exe    - eight-record UI/two pages, bounded list copy,
                       list ACK, existing connect/reconnect guards.
  Original/*.exe     - untouched files from our 7.0.5.MD source package.
                       These are not a backup of your particular unit.
  manifest.json      - exact file hashes, patch recipe and offline checks.

Target locations on the unit:
  \Storage Card\System\Blue.exe
  \Storage Card\System\AppMain.exe

Before replacement, keep YOUR current files and settings backup on USB/PC,
particularly both executables and \Storage Card2\DATA\BLUE\sc_db.db.
Keep your existing CE access/return tools. CE entry using the main application
has not been proved usable if that application fails to start.

Use your established CE file-replacement procedure with both applications
stopped. Replace both target executables, then use the known normal restart
procedure so the original startup arguments/dependencies are retained.
Simply double-clicking another copy is not a verified launch method: both
programs have startup/single-instance requirements. If the running files cannot
be replaced, do not force deletion or change autostart/registry settings.

Test in this order:
1. Normal startup and your existing paired devices/names are retained.
2. Add devices six, seven and eight. Check both pages and select each device.
3. Test music, a handsfree call and the selected phone's contacts.
4. Restart normally; all eight entries should still be present.
5. Delete/re-pair devices on both pages; verify the correct device disappears.
6. Verify reconnect, source switching, navigation and normal vehicle controls.
Record the exact failing action, phone, slot and whether reboot changes it.

Rollback: with the apps stopped, restore YOUR saved Blue.exe and AppMain.exe
together. Restore YOUR pre-test sc_db.db too if returning to the old five-slot
programs; later test pairings are then lost. Do not assume the original package
files restore your unit's other settings or provide boot/flash/MCU recovery.

Offline byte/fixture checks passed, but this pair has not run on a real unit.
Partial writes, snapshot races/cache aliases and controller/profile behavior
remain open. No playback-buffer change, navigation file, Version_Info, OS,
bootloader or MCU update is included. No upgrade.lgu or autorun is included.
"""


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def compose(raw_blue, raw_app):
    storage, storage_meta = draft_blue_storage(raw_blue)
    ack, ack_meta = blue_ack(raw_blue)
    _, delete_meta = blue_delete_status(raw_blue)
    out = bytearray(ack)
    # Check full instruction-range preimages, not just differing bytes. A
    # conflicting ACK edit must fail rather than be silently overwritten.
    for edit in delete_meta["edits"]:
        at = int(edit["offset"], 16)
        before, after = bytes.fromhex(edit["before_hex"]), bytes.fromhex(edit["after_hex"])
        assert storage[at:at + len(before)] == before
        assert bytes(out[at:at + len(before)]) == before, "Conflicting ACK/delete range"
        out[at:at + len(after)] = after
    app, app_meta = app_safe_copy(raw_app)
    return bytes(out), app, dict(storage=storage_meta, blue_ack=ack_meta,
                                 delete_status=delete_meta, app_safe_copy=app_meta)


def layout(original, candidate):
    old, new = pefile.PE(data=original), pefile.PE(data=candidate)
    assert len(original) == len(candidate)
    assert old.FILE_HEADER.__pack__() == new.FILE_HEADER.__pack__()
    assert old.OPTIONAL_HEADER.__pack__() == new.OPTIONAL_HEADER.__pack__()
    assert len(old.sections) == len(new.sections)
    for a, b in zip(old.sections, new.sections):
        assert a.__pack__() == b.__pack__()
        if a.Name.rstrip(b"\0") != b".text": assert a.get_data() == b.get_data()
    return dict(bytes=len(candidate), sha256=sha(candidate), machine="MIPS R4000 / 0x166",
                changed_bytes=sum(a != b for a, b in zip(original, candidate)),
                pe_headers_sections_and_nontext_preserved=True)


def verify(blue_bytes, app_bytes):
    blue, app = pefile.PE(data=blue_bytes), pefile.PE(data=app_bytes)
    valid = [direct(blue, n, i, address=address) for n in range(1, 9)
             for i in range(n) for address in (False, True)]
    failures = [direct(blue, 8, i, fault, address) for i in range(8)
                for fault in FAULTS[1:] for address in (False, True) if address or fault != "scan"]
    gui_valid = [gui(blue, n, i, connected=active) for n in range(1, 9)
                 for i in range(n) for active in (False, True)]
    gui_failed = [gui(blue, 8, i, fault, active) for i in range(8)
                  for fault in FAULTS[1:] for active in (False, True)]
    print("Written Blue: storage/delete and GUI checks passed", flush=True)
    coupled = [snapshot(blue, app, n, i, popup=popup, transport=transport)
               for n in range(1, 9) for i in range(n) for popup in (False, True)
               for transport in ("success", "timeout", "retry")]
    coupled += [snapshot(blue, app, 0, popup=popup, transport=transport)
                for popup in (False, True) for transport in ("success", "timeout", "retry")]
    coupled_faults = [snapshot(blue, app, 8, popup=popup, fault=fault)
                      for popup in (False, True) for fault in ("header", "bulk-partial", "bulk-false-full", "seek")]
    null = [null_hfp(blue, app, n, popup, transport) for n in (1, 5, 8)
            for popup in (False, True) for transport in ("success", "timeout", "retry")]
    copies = [copy_case(app, n, False, (i,)) for n in range(1, 9) for i in range(n)]
    copies += [copy_case(app, n, null, ()) for n in (0, 1, 5, 8, 9, 0xffffffff) for null in (False, True)]
    ui = [ui_case(app, n, i // 4, None, click=(base + i % 4, 2))
          for n in range(1, 9) for i in range(n) for base in (0x3e9, 0x3ed)]
    print("Written matched pair: list ACK/HFP/copy/UI checks passed", flush=True)
    return dict(valid_delete=valid, failed_delete=failures, gui_valid=gui_valid, gui_failed=gui_failed,
                list_hfp=coupled, list_hfp_failed=coupled_faults, null_hfp=null,
                bounded_copy=copies, ui=ui)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output-dir", default="build/bt-eight-test-BT8T01")
    args = parser.parse_args()
    out = (ROOT / args.output_dir).resolve(); out.relative_to((ROOT / "build").resolve())
    archive = out.with_suffix(".zip")
    if archive.exists() or (out / "manifest.json").exists():
        raise ValueError("Completed numbered output already exists; never overwrite a test build")
    modules = {m["name"]: m for m in json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8")) if m["origin"] == "705md"}
    originals = {name: (ROOT / modules[name]["path"]).read_bytes() for name in ("Blue.exe", "AppMain.exe")}
    assert all(sha(raw) == modules[name]["sha256"] for name, raw in originals.items())
    blue, app, recipe = compose(originals["Blue.exe"], originals["AppMain.exe"])
    candidates = {"Blue.exe": blue, "AppMain.exe": app}
    checked_layout = {name: layout(originals[name], raw) for name, raw in candidates.items()}
    if out.exists():
        # Recover our interrupted validation only if the existing tree contains
        # exactly the four identical application files and nothing else.
        expected_files = {**{f"Test/{n}": b for n, b in candidates.items()},
                          **{f"Original/{n}": b for n, b in originals.items()}}
        actual_files = {p.relative_to(out).as_posix(): p.read_bytes() for p in out.rglob("*") if p.is_file()}
        assert actual_files == expected_files, "Existing output differs; choose a fresh numbered directory"
    else:
        (out / "Test").mkdir(parents=True); (out / "Original").mkdir()
        for name, raw in candidates.items(): (out / "Test" / name).write_bytes(raw)
        for name, raw in originals.items(): (out / "Original" / name).write_bytes(raw)
    # Every behavioral trace uses bytes loaded from the actual supplied files.
    readback = {name: (out / "Test" / name).read_bytes() for name in candidates}
    assert readback == candidates
    traces = verify(readback["Blue.exe"], readback["AppMain.exe"])
    counts = {name: len(items) for name, items in traces.items()}
    assert all((ROOT / modules[name]["path"]).read_bytes() == raw for name, raw in originals.items())
    (out / "READ-ME-FIRST.txt").write_text(GUIDE, encoding="utf-8")
    manifest = dict(build_id="BT8T01", created_utc=datetime.now(timezone.utc).isoformat(),
                    purpose="Explicitly requested experimental eight-paired-device application files",
                    build_complete=True, native_execution=False, unit_tested=False, lgu_written=False,
                    files=checked_layout, original_files={name: dict(bytes=len(raw), sha256=sha(raw),
                           source=modules[name]["path"]) for name, raw in originals.items()},
                    included=["eight-slot storage/UI", "database BOOL/count guards", "list ACK",
                              "bounded copy", "delete-status GUI guard"],
                    prior_exclusions="No H4 timeout/power investigation or full controller/cache/scheduler/playback integration suite",
                    offline_checks=counts, offline_case_total=sum(counts.values()), patch_recipe=recipe,
                    tool_sha256={p.name: sha(p.read_bytes()) for p in {
                        Path(m.__file__).resolve() for m in sys.modules.values()
                        if getattr(m, "__file__", None) and Path(m.__file__).resolve().parent == ROOT / "tools"}},
                    limitations=["Experimental: native boot/radio/profile/vehicle behavior unverified",
                                 "Partial writes can corrupt persisted bytes; no atomic recovery",
                                 "Snapshot freshness/cache aliases and App delete-error feedback remain open"])
    (out / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    (out / "offline-traces.json").write_text(json.dumps(traces, indent=2) + "\n", encoding="utf-8")
    with zipfile.ZipFile(archive, "w", compression=zipfile.ZIP_DEFLATED) as zipped:
        for path in sorted(out.rglob("*")):
            if path.is_file(): zipped.write(path, path.relative_to(out).as_posix())
    with zipfile.ZipFile(archive) as zipped:
        assert zipped.testzip() is None
        expected = {p.relative_to(out).as_posix(): p.read_bytes() for p in out.rglob("*") if p.is_file()}
        assert set(zipped.namelist()) == set(expected)
        assert all(zipped.read(name) == raw for name, raw in expected.items())
    print(json.dumps(dict(build="BT8T01", output=str(out), archive=str(archive),
                         archive_sha256=sha(archive.read_bytes()), files=checked_layout,
                         offline_checks=counts, total=sum(counts.values())), indent=2))


if __name__ == "__main__": main()
