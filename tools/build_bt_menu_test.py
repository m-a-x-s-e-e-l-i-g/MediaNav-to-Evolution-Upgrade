"""BT8T03: carry BT8T02 forward and add the equivalent label scan optimization."""
import hashlib
import json
import sys
import zipfile
from datetime import datetime, timezone
from pathlib import Path
import pefile
from build_bt_eight_test import ROOT, layout, verify
from build_bt_audio_test import playback_checks
from patch_appmain_label_scan import compose_label_scan, START, END
from verify_appmain_label_scan import verify as verify_labels


def sha(raw): return hashlib.sha256(raw).hexdigest()


TEST = """BT8T03 - menu / startup / Bluetooth comparison

This build carries forward all BT8T02 eight-device and audio-buffer patches.
Blue.exe is identical to BT8T02. AppMain.exe additionally uses one equivalent
scan for Arabic text direction instead of repeated full-text scans/copies.
It retains the same Unicode range, NULL behavior and function frame.
No startup wait or Bluetooth transport-cleanup change is included.

1. Before replacement, record BT8T02 menu behavior on the same screens:
   home -> settings -> Bluetooth device list -> contacts -> back, several times.
   Include long device/contact names. Note touch-to-visible-response timing.
2. Keep your current executables and sc_db.db backup. With the apps stopped,
   use the established CE replacement and normal restart procedure from
   READ-ME-FIRST.txt. Use both Test files together. From an already-installed
   BT8T02 only AppMain changes; Blue is byte-identical.
3. Repeat those screens in the same order. Check label text, clipping, font
   size, scrolling and alignment. If available check an Arabic/Hebrew locale
   and mixed names; their direction decisions should remain the same.
4. Record normal-startup time separately. This build removes label work; it
   does not shorten startup's fixed waits or promise a measurable boot gain.
5. While parked, test radio -> Bluetooth music -> radio repeatedly, a call,
   pause/resume, disconnect/reconnect and 15 minutes of continuous music.
   Follow TEST-AUDIO-DELAY.txt for measuring audio delay. Bluetooth behavior
   should match BT8T02 because Blue has no additional changes here.
6. Test both device-list pages, deletion/re-pairing and normal restart with
   all eight paired devices. Return using your saved matching files if any
   behavior regresses; follow the rollback instructions for five-slot apps.

Report: screen/action, before/after response time, phone/player, audio delay,
and any text/font/reconnect/dropout difference. Instruction-count savings in
the manifest are offline helper measurements, not whole-unit speed gains.
"""


def main():
    out = ROOT / "build/bt-menu-audio-test-BT8T03"; archive = out.with_suffix(".zip")
    if out.exists() or archive.exists(): raise ValueError("Existing build is never overwritten")
    control = ROOT / "build/bt-eight-audio-test-BT8T02"
    previous = json.loads((control / "manifest.json").read_text(encoding="utf-8"))
    original = {n: (ROOT / item["source"]).read_bytes() for n, item in previous["original_files"].items()}
    assert all(sha(raw) == previous["original_files"][n]["sha256"] for n, raw in original.items())
    base = {n: (control / "Test" / n).read_bytes() for n in original}
    assert all(sha(raw) == previous["files"][n]["sha256"] for n, raw in base.items())
    app, recipe = compose_label_scan(original["AppMain.exe"], base["AppMain.exe"])
    candidates = {"Blue.exe": base["Blue.exe"], "AppMain.exe": app}
    files = {n: layout(original[n], raw) for n, raw in candidates.items()}
    # Full domain was checked on the standalone patch. Exact function-byte
    # identity transfers that result; combined readback receives additional
    # multi-unit/ABI/guard checks, rather than repeating the exhaustive run.
    evidence_path = ROOT / "analysis/firmware/appmain-label-scan/contracts.json"
    evidence = json.loads(evidence_path.read_text(encoding="utf-8"))
    assert evidence["checks"]["exhaustive_utf16_cases"] == 65536
    assert evidence["patch"] == recipe
    pe = pefile.PE(data=app)
    at = pe.get_offset_from_rva(START - pe.OPTIONAL_HEADER.ImageBase)
    assert app[at:at + END - START].hex() == recipe["edits"][0]["after_hex"]
    (out / "Test").mkdir(parents=True); (out / "Original").mkdir()
    for n, raw in candidates.items(): (out / "Test" / n).write_bytes(raw)
    for n, raw in original.items(): (out / "Original" / n).write_bytes(raw)
    readback = {n: (out / "Test" / n).read_bytes() for n in candidates}
    assert readback == candidates
    labels = verify_labels(original["AppMain.exe"], readback["AppMain.exe"], exhaustive=False)
    pairing = verify(readback["Blue.exe"], readback["AppMain.exe"])
    audio = playback_checks(readback["Blue.exe"])
    guide = (control / "READ-ME-FIRST.txt").read_text(encoding="utf-8").replace("BT8T02", "BT8T03")
    guide = guide.replace("list ACK, existing connect/reconnect guards.",
                          "list ACK, connect/reconnect guards and label-scan optimization.")
    guide += "\nThis build also includes the one-pass AppMain label scan; see TEST-PERFORMANCE.txt.\n"
    (out / "READ-ME-FIRST.txt").write_text(guide, encoding="utf-8")
    (out / "TEST-AUDIO-DELAY.txt").write_bytes((control / "TEST-AUDIO-DELAY.txt").read_bytes())
    (out / "TEST-PERFORMANCE.txt").write_text(TEST, encoding="utf-8")
    counts = {k: len(v) for k, v in pairing.items()}
    result = dict(build_id="BT8T03", created_utc=datetime.now(timezone.utc).isoformat(),
                  build_complete=True, native_execution=False, unit_tested=False, lgu_written=False,
                  files=files, original_files=previous["original_files"], control_build="BT8T02",
                  blue_identical_to_control=True, carried_forward_manifest_sha256=sha((control / "manifest.json").read_bytes()),
                  pairing_case_total=sum(counts.values()), pairing_checks=counts, playback_checks=audio,
                  label_patch=recipe, label_readback_checks=labels,
                  label_exhaustive_evidence=dict(path=str(evidence_path.relative_to(ROOT)), sha256=sha(evidence_path.read_bytes()),
                                                 checks=evidence["checks"]),
                  tool_sha256={p.name: sha(p.read_bytes()) for p in {
                      Path(m.__file__).resolve() for m in sys.modules.values()
                      if getattr(m, "__file__", None) and Path(m.__file__).resolve().parent == ROOT / "tools"}},
                  limitations=previous["limitations"] + ["Menu/startup responsiveness unmeasured on hardware; no startup-wait or transport-cleanup patch"])
    (out / "manifest.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    (out / "offline-traces.json").write_text(json.dumps(pairing, indent=2) + "\n", encoding="utf-8")
    assert all((ROOT / previous["original_files"][n]["source"]).read_bytes() == raw for n, raw in original.items())
    with zipfile.ZipFile(archive, "w", compression=zipfile.ZIP_DEFLATED) as z:
        for path in sorted(out.rglob("*")):
            if path.is_file(): z.write(path, path.relative_to(out).as_posix())
    with zipfile.ZipFile(archive) as z:
        expected = {p.relative_to(out).as_posix(): p.read_bytes() for p in out.rglob("*") if p.is_file()}
        assert set(z.namelist()) == set(expected) and z.testzip() is None
        assert all(z.read(n) == raw for n, raw in expected.items())
    print(json.dumps(dict(build="BT8T03", archive=str(archive), archive_sha256=sha(archive.read_bytes()),
                         files=files, pairing_cases=sum(counts.values()), label_checks=labels), indent=2))


if __name__ == "__main__": main()
