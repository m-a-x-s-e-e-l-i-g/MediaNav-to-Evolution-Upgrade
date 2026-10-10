"""BT8T02: requested application test of eight slots plus MAX02 playback repair.

No full firmware update, native execution or device write. BT8T01 is retained
as the comparison/control; AppMain bytes are identical between these builds.
"""
import hashlib
import json
import random
import sys
import zipfile
from datetime import datetime, timezone
from pathlib import Path

import pefile
from build_bt_eight_test import ROOT, compose, layout, verify, GUIDE
from patch_bt_playback import patch_blue, BLOCK_BYTES
from verify_bt_patch import Playback
from inspect_bt_lifecycle import CTX, INPUT


def sha(raw): return hashlib.sha256(raw).hexdigest()


def playback_checks(raw):
    pe = pefile.PE(data=raw)
    rng = random.Random(70503); p = Playback(pe); incoming = bytearray()
    for _ in range(64):
        payload = rng.randbytes(rng.choice((1, 511, 4095, 4096, 4097, 8192)))
        incoming.extend(payload); p.packet(payload)
        while len(p.queued) > 1:
            slot = next(iter(p.queued)); p.done(slot); p.done(slot)
    submitted = b"".join(p.submitted)
    assert submitted == incoming[:len(incoming) // BLOCK_BYTES * BLOCK_BYTES]
    assert p.data(p.vm.read(CTX + 0x330), p.vm.read(CTX + 0x334)) == incoming[len(submitted):]
    assert len(p.free) == len(p.next_calls) == 64
    p = Playback(pe); p.packet(bytes(8192))
    assert len(p.queued) == 2 and p.restarts == [dict(pending=2, result=0)]
    p = Playback(pe); p.packet(bytes(16384)); queued = dict(p.queued); copies = len(p.copies)
    for _ in range(8): p.packet(bytes(8192))
    assert p.queued == queued and len(p.copies) == copies
    p = Playback(pe); p.packet(bytes([9]) * 1000); p.lifecycle(0x26d2c)
    assert p.vm.read(CTX + 0x334) == 0
    p.lifecycle(0x26c68); p.packet(bytes([7]) * 4096)
    assert p.submitted == [bytes([7]) * 4096]
    p = Playback(pe); p.restart_result = 1; p.packet(bytes(8192))
    assert p.vm.read(CTX + 0x338, 1) == 0
    p.restart_result = 0; p.packet(bytes(4096))
    assert p.vm.read(CTX + 0x338, 1) == 1
    return dict(payload_packets=64, exact_submitted_bytes=len(submitted), start_after_two_blocks=True,
                saturation_packets=8, stop_start=True, restart_failure_retry=True,
                duplicate_completion=True, abi_preserved=True, native_execution=False)


TEST = r"""Audio delay comparison - BT8T01 versus BT8T02

BT8T01 = eight-device test, original audio buffering.
BT8T02 = same eight-device test + MAX02 playback-buffer repair.
AppMain.exe is identical. Blue.exe is the only changed application between them.
This patch targets Bluetooth MUSIC (A2DP), not microphone/handsfree call delay.

1. In the parked car, test BT8T01 first using the same phone, player, volume,
   connection and local video file for all runs. Use a video with repeated
   visible claps, or a flash synchronized with a short beep in the file.
2. Note how late the clap/beep sounds relative to the visible marker.
   Repeat at least three times. If available, use a SECOND phone to record
   the first phone's screen and the sound from the car speakers together.
   A second phone avoids mixing the player's own screen capture/audio timing.
3. Stop the applications using your established CE replacement procedure.
   Save your current Blue.exe; replace it with this Test/Blue.exe and return
   through your known normal restart procedure. If starting from the original
   7.0.5.MD instead of BT8T01, use both files in Test as a matched pair.
4. Repeat exactly the same three runs with BT8T02. Record before/after delay,
   and any stutter, missing sound, clicks or dropouts. The measured result is
   for this particular phone/player; it is not the software-buffer calculation.
5. Test pause/resume, next track, disconnect/reconnect and a normal restart.
   Listen for 15 minutes, including music while navigation is active.
6. If playback gets worse, stop the apps and restore your saved BT8T01 Blue.exe.
   AppMain can remain unchanged when comparing these two test builds.

Do not use the large MAX02 upgrade.lgu for this application comparison.
Keep the existing CE access/return tools and unit backup. No unit recovery
mechanism is added by this test set. Follow READ-ME-FIRST.txt for full rollback.

Report: phone + player, original/BT8T01 delay, BT8T02 delay, and whether music
stays continuous during pause/resume/reconnect/navigation.
"""


def main():
    out = ROOT / "build/bt-eight-audio-test-BT8T02"; archive = out.with_suffix(".zip")
    if out.exists() or archive.exists(): raise ValueError("Existing build is never overwritten")
    control = ROOT / "build/bt-eight-test-BT8T01"
    manifest = json.loads((control / "manifest.json").read_text(encoding="utf-8"))
    originals = {n: (ROOT / info["source"]).read_bytes() for n, info in manifest["original_files"].items()}
    assert all(sha(raw) == manifest["original_files"][n]["sha256"] for n, raw in originals.items())
    eight, app, recipe = compose(originals["Blue.exe"], originals["AppMain.exe"])
    assert eight == (control / "Test/Blue.exe").read_bytes()
    assert app == (control / "Test/AppMain.exe").read_bytes()
    patched, audio_meta = patch_blue(originals["Blue.exe"])
    known_audio = ROOT / "build/review-max02/payload/upgrade/Storage Card/System/Blue.exe"
    assert patched == known_audio.read_bytes(), "Audio patch differs from MAX02"
    blue = bytearray(eight)
    for edit in audio_meta["patch_ranges"]:
        at = int(edit["file_offset"], 16)
        before, after = bytes.fromhex(edit["before_hex"]), bytes.fromhex(edit["after_hex"])
        assert blue[at:at + len(before)] == before, "Audio/eight-device patch conflict"
        blue[at:at + len(after)] = after
    blue = bytes(blue)
    candidates = {"Blue.exe": blue, "AppMain.exe": app}
    checked = {n: layout(originals[n], raw) for n, raw in candidates.items()}
    (out / "Test").mkdir(parents=True); (out / "Original").mkdir()
    for n, raw in candidates.items(): (out / "Test" / n).write_bytes(raw)
    for n, raw in originals.items(): (out / "Original" / n).write_bytes(raw)
    readback = {n: (out / "Test" / n).read_bytes() for n in candidates}
    assert readback == candidates
    playback = playback_checks(readback["Blue.exe"])
    print("Written BT8T02: MAX02 audio ranges and playback checks passed", flush=True)
    traces = verify(readback["Blue.exe"], readback["AppMain.exe"])
    guide = GUIDE.replace("BT8T01", "BT8T02").replace(
        "list ACK and delete-persistence guard.", "list ACK, delete guard and MAX02 audio repair.").replace(
        "No playback-buffer change, navigation file, Version_Info, OS,",
        "MAX02 playback-buffer repair is included. No navigation file, Version_Info, OS,")
    (out / "READ-ME-FIRST.txt").write_text(guide, encoding="utf-8")
    (out / "TEST-AUDIO-DELAY.txt").write_text(TEST, encoding="utf-8")
    counts = {k: len(v) for k, v in traces.items()}
    result = dict(build_id="BT8T02", created_utc=datetime.now(timezone.utc).isoformat(),
                  build_complete=True, native_execution=False, unit_tested=False, lgu_written=False,
                  files=checked, original_files=manifest["original_files"], control_build="BT8T01",
                  appmain_identical_to_control=True, audio_ranges_identical_to_MAX02=True,
                  pairing_case_total=sum(counts.values()), pairing_checks=counts, playback_checks=playback,
                  pairing_recipe=recipe, playback_patch=audio_meta,
                  tool_sha256={p.name: sha(p.read_bytes()) for p in {
                      Path(m.__file__).resolve() for m in sys.modules.values()
                      if getattr(m, "__file__", None) and Path(m.__file__).resolve().parent == ROOT / "tools"}},
                  limitations=manifest["limitations"] + ["Real audio latency/jitter/dropouts unmeasured; queue saturation skips incoming PCM"])
    (out / "manifest.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    (out / "offline-traces.json").write_text(json.dumps(traces, indent=2) + "\n", encoding="utf-8")
    assert all((ROOT / manifest["original_files"][n]["source"]).read_bytes() == raw for n, raw in originals.items())
    with zipfile.ZipFile(archive, "w", compression=zipfile.ZIP_DEFLATED) as zipped:
        for path in sorted(out.rglob("*")):
            if path.is_file(): zipped.write(path, path.relative_to(out).as_posix())
    with zipfile.ZipFile(archive) as zipped:
        expected = {p.relative_to(out).as_posix(): p.read_bytes() for p in out.rglob("*") if p.is_file()}
        assert set(zipped.namelist()) == set(expected) and zipped.testzip() is None
        assert all(zipped.read(n) == raw for n, raw in expected.items())
    print(json.dumps(dict(build="BT8T02", archive=str(archive), archive_sha256=sha(archive.read_bytes()),
                         files=checked, pairing_case_total=sum(counts.values()), playback=playback), indent=2))


if __name__ == "__main__": main()
