"""Identify local MAX06 Bluetooth variants without executing or changing firmware.

Hash existing LGUs against their build reports and both saved executable copies.
This binds existing container evidence to current bytes; it does not re-decode
the containers, inspect a connected device, or prove Bluetooth interoperability.
"""
import hashlib
import json
import struct
from datetime import datetime, timezone
from pathlib import Path

import pefile

ROOT = Path(__file__).resolve().parents[1]
REPO = ROOT / "sources/MediaNav-usb-seek-timing"
MODULES = ("AppMain.exe", "Blue.exe")
DRAW_SLOT, DRAW = 0x150c44, 0x235000
PCM_SPANS = ((0x25a5c, 0x25e84), (0x26400, 0x26550), (0x266a4, 0x270f4))


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def audio_audit():
    member = "upgrade/Storage Card/System/Blue.exe"
    latest = REPO / "build/maxmade-7.0.6.MAX06-artwork-text-local-01"
    baseline = REPO / "build/maxmade-7.0.6.MAX05-local"
    old = (baseline / "payload" / member).read_bytes()
    new = (latest / "payload" / member).read_bytes()
    recipe = json.loads((latest / "native-recipes.json").read_bytes())[member]
    assert sha(old) == recipe["before_sha256"]
    assert sha(new) == recipe["candidate_sha256"]
    original, candidate = pefile.PE(data=old), pefile.PE(data=new)
    changes = []
    for lo, hi in PCM_SPANS:
        before = original.get_data(lo - original.OPTIONAL_HEADER.ImageBase, hi - lo)
        after = candidate.get_data(lo - candidate.OPTIONAL_HEADER.ImageBase, hi - lo)
        assert len(before) == len(after) == hi - lo
        changes.extend(dict(address=hex(lo + i), before=a, after=b)
                       for i, (a, b) in enumerate(zip(before, after)) if a != b)
    assert changes == [dict(address="0x26f24", before=4, after=8)]
    assert candidate.get_data(0x26f24 - candidate.OPTIONAL_HEADER.ImageBase, 4) == bytes.fromhex("0800092d")
    assert candidate.get_data(0x26ef4 - candidate.OPTIONAL_HEADER.ImageBase, 4) == bytes.fromhex("0200092d")
    return dict(baseline_sha256=sha(old), candidate_sha256=sha(new),
                compared_spans=[[hex(lo), hex(hi)] for lo, hi in PCM_SPANS],
                changed_bytes=changes, queue_limit_before=4, queue_limit_after=8,
                restart_threshold=2,
                limits=["Only the listed PCM/start/stop/completion ranges are compared",
                        "No SBC decoding, native timing, driver output or waveform was measured",
                        "Reduced symptom frequency does not prove queue saturation caused the stuttering"])


def audit():
    variants = []
    for directory in sorted((REPO / "build").glob("maxmade-7.0.6.MAX06-*")):
        manifest = json.loads((directory / "build-manifest.json").read_bytes())
        recorded = manifest["verification"]
        raw = (directory / "upgrade.lgu").read_bytes()
        assert sha(raw) == recorded["lgu_sha256"]
        assert len(raw) == recorded["bytes"]
        assert raw[:4] == b"LGU0"
        version = raw[0x2dc:0x304].decode("utf-16le").split("\0")[0]
        assert version == manifest["revision"] == "7.0.6.MAX06"
        members = {row["path"]: row for row in recorded["members"]}
        assert len(members) == 1918
        recipes = json.loads((directory / "native-recipes.json").read_bytes())
        modules = {}
        for name in MODULES:
            member = "upgrade/Storage Card/System/" + name
            payload = (directory / "payload" / member).read_bytes()
            assert sha(payload) == members[member]["sha256"]
            assert len(payload) == members[member]["bytes"]
            assert (directory / "roundtrip" / member).read_bytes() == payload
            recipe = recipes[member]
            assert sha(payload) == recipe.get("after_sha256", recipe.get("candidate_sha256"))
            pe = pefile.PE(data=payload)
            base = pe.OPTIONAL_HEADER.ImageBase
            section_checks = []
            for section in recipe["sections"]:
                mapped = next(s for s in pe.sections if s.Name.rstrip(b"\0").decode() == section["name"])
                assert mapped.PointerToRawData == section["raw_offset"]
                assert mapped.SizeOfRawData == section["raw_bytes"]
                assert mapped.Misc_VirtualSize == section["virtual_bytes"]
                # Recipes hash meaningful section contents, excluding file padding.
                data = pe.get_data(mapped.VirtualAddress, section["virtual_bytes"])
                assert len(data) == section["virtual_bytes"]
                assert sha(data) == section["sha256"]
                section_checks.append(section["name"])
            for hook in recipe["hooks"]:
                actual = struct.unpack("<I", pe.get_data(hook["address"] - base, 4))[0]
                assert actual == hook["after"]
            modules[name] = dict(sha256=sha(payload), bytes=len(payload),
                                 sections_checked=section_checks, hooks_checked=len(recipe["hooks"]))
            if name == "AppMain.exe":
                assert struct.unpack("<I", pe.get_data(DRAW_SLOT - base, 4))[0] == DRAW
        variants.append(dict(package=str(directory.relative_to(ROOT)), version=version,
                             lgu_sha256=sha(raw), bytes=len(raw), modules=modules,
                             file_created_local=datetime.fromtimestamp((directory / "upgrade.lgu").stat().st_ctime).astimezone().isoformat(),
                             artwork_reported=manifest["artwork_helpers_in_lgu"],
                             text_recovery_reported=manifest.get("text_recovery_helpers_in_lgu", False)))
    assert len(variants) == 4
    return dict(generated_utc=datetime.now(timezone.utc).isoformat(), variants=variants,
                audio=audio_audit(),
                artwork_rectangle=dict(x=24, y=116, width=128, height=128),
                device_feedback=dict(version="7.0.6.MAX06", phone="Nothing Phone (1)",
                                     os="Android 15", music_app="Spotify",
                                     no_title_after_track_skip=True,
                                     artwork_absent_on_supplied_player_photo=True,
                                     user_package_timestamp="2026-10-11 00:02 Europe/Amsterdam",
                                     timestamp_matches_package="maxmade-7.0.6.MAX06-artwork-text-local-01",
                                     audio_stuttering_only_bluetooth=True,
                                     audio_stuttering_described_as="Stuttering, explicitly clarified by the user; less frequent but still present",
                                     earlier_audio_description="Noise on top of continuous music",
                                     audio_issue_absent_on_7_0_5MD=True,
                                     installed_device_bytes_verified=False),
                native_executed=False, hardware_tested=False,
                limits=["LGU hashes bind existing readback reports; containers were not decoded again",
                        "Executable copies, added section hashes and hook words checked directly",
                        "Displayed MAX06 does not identify the installed package",
                        "No phone traffic or device metadata/artwork state captured",
                        "Local artwork drawing code does not prove successful transfer or display"])


if __name__ == "__main__":
    report = audit()
    destination = ROOT / "analysis/firmware/max06-bt-feedback-audit.json"
    destination.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(variants=len(report["variants"]),
                          packages=[dict(path=v["package"], text_recovery=v["text_recovery_reported"],
                                         sha256=v["lgu_sha256"]) for v in report["variants"]]), indent=2))
