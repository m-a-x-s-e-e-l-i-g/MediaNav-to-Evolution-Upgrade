"""Combine the complete pinned 7.0.5.MD payload, BT8T03 apps and existing nav fix.

Only the pinned x86 PC container tools run. No firmware runs or device writes.
Earlier builds and source packages are never overwritten.
"""
import argparse
import csv
import json
import re
import zipfile
from datetime import datetime, timezone
from pathlib import Path

import pefile
from build_review_update import (
    ROOT, BLUE_PATH, VERSION_PATH, NAV_PATH, NAV_HASH, WRITER_HASH,
    EXTRACTOR_HASH, sha, relative, run_pc_tool, verify_package,
)
from build_bt_eight_test import layout

APP_PATH = "upgrade/Storage Card/System/AppMain.exe"
CONTROL = ROOT / "build/bt-menu-audio-test-BT8T03"
BASE_LGU = ROOT / "sources/MediaNav-to-Evolution-Upgrade/Upgrade_705MD_FavreMod/upgrade.lgu"
NAV_LGU = ROOT / "sources/MediaNav-to-Evolution-Upgrade/File_Corruption_Fix/upgrade.lgu"
KNOWN_VERSIONS = ("4.0.6", "4.1.0", "7.0.5.MD", "7.0.5.MD.MAX01", "7.0.5.MD.MAX02")
BASE_LGU_HASH = "2f7e3a3e9c49cb033f8e7af4b63cfff095bf17c9100a45b154b7ca69af67cfdc"
NAV_LGU_HASH = "c24a5fdb521311ab1e5ef569d7096a7364dbbfae13506e750f270b7065178857"


def inputs():
    assert sha(BASE_LGU.read_bytes()) == BASE_LGU_HASH
    assert sha(NAV_LGU.read_bytes()) == NAV_LGU_HASH
    expected, sources = {}, {}
    for origin in ("705md", "corruption-fix"):
        with (ROOT / f"analysis/{origin}-inventory.csv").open(encoding="utf-8", newline="") as stream:
            rows = list(csv.DictReader(stream))
        assert len(rows) == (1917 if origin == "705md" else 1)
        for item in rows:
            name = relative(item["path"])
            assert name.casefold() not in {p.casefold() for p in expected}
            source = ROOT / "extracted" / origin / name
            raw = source.read_bytes()
            assert len(raw) == int(item["size"]) and sha(raw) == item["sha256"], name
            expected[name] = dict(bytes=len(raw), sha256=sha(raw), origin=origin)
            sources[name] = source
    assert len(expected) == 1918 and expected[NAV_PATH]["sha256"] == NAV_HASH
    assert sources[VERSION_PATH].read_bytes() == b"7.0.5.MD"
    assert all(name in expected for name in (
        "upgrade/firmware.hex", "upgrade/Storage Card/NK.bin",
        "upgrade/Storage Card/System/UpgradeManager.exe",
        "upgrade/Storage Card/System/MicomManager.exe", BLUE_PATH, APP_PATH,
    ))
    manifest_path = CONTROL / "manifest.json"
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    assert manifest["build_id"] == "BT8T03" and manifest["build_complete"]
    assert manifest["pairing_case_total"] == 824
    assert manifest["playback_checks"]["payload_packets"] == 64
    assert manifest["playback_checks"]["exact_submitted_bytes"] == 233472
    assert manifest["label_readback_checks"]["multi_unit_cases"] == 172
    assert manifest["label_exhaustive_evidence"]["checks"]["exhaustive_utf16_cases"] == 65536
    for name, digest in manifest["tool_sha256"].items():
        assert sha((ROOT / "tools" / name).read_bytes()) == digest, name
    label_proof = ROOT / manifest["label_exhaustive_evidence"]["path"]
    assert sha(label_proof.read_bytes()) == manifest["label_exhaustive_evidence"]["sha256"]
    apps, layouts = {}, {}
    for name, member in (("Blue.exe", BLUE_PATH), ("AppMain.exe", APP_PATH)):
        original, new = sources[member].read_bytes(), (CONTROL / "Test" / name).read_bytes()
        assert sha(original) == manifest["original_files"][name]["sha256"]
        assert sha(new) == manifest["files"][name]["sha256"]
        layouts[name] = layout(original, new)
        apps[member] = new
    writer, extractor = (ROOT / "tools/vendor/lgu-favremod" / n for n in ("dir2lgu.exe", "lgu2dir.exe"))
    assert sha(writer.read_bytes()) == WRITER_HASH and sha(extractor.read_bytes()) == EXTRACTOR_HASH
    assert all(pefile.PE(str(tool)).FILE_HEADER.Machine == 0x14c for tool in (writer, extractor))
    proof = dict(
        source_lgu=dict(path=str(BASE_LGU.relative_to(ROOT)), bytes=BASE_LGU.stat().st_size,
                        sha256=sha(BASE_LGU.read_bytes())),
        navigation_source_lgu=dict(path=str(NAV_LGU.relative_to(ROOT)), bytes=NAV_LGU.stat().st_size,
                                   sha256=sha(NAV_LGU.read_bytes())),
        app_build="BT8T03", app_manifest_sha256=sha(manifest_path.read_bytes()),
        app_layouts=layouts, pairing_cases=824, playback_checks=manifest["playback_checks"],
        label_readback_checks=manifest["label_readback_checks"],
        exhaustive_label_proof=manifest["label_exhaustive_evidence"],
        validation_reused_by_exact_app_and_tool_hashes=True,
    )
    return expected, sources, apps, proof, writer, extractor


def version_model(revision):
    # ASCII UTF16 values sort identically to these Python strings. The installed
    # updater uses wcscmp and accepts only a positive ordinary revision compare.
    assert re.fullmatch(r"7\.0\.(?:5\.(?:MAX|MX|MD\.MAX)|6\.MAX)[0-9]{2}", revision)
    assert len(revision) <= 19
    return [dict(current=v, offered=revision, ordinary_update_offered=revision > v,
                 native_installation_tested=False) for v in KNOWN_VERSIONS]


def readme(revision, digest, byte_count):
    return f"""# MediaNav MAXmade — {revision}

Experimental combined full update for the original MediaNav running the
7.0.5.MD conversion. Full LGU installation has not yet been tested on a unit.

## Based on the original package

All 1,917 files from [Upgrade_705MD_FavreMod](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/tree/main/Upgrade_705MD_FavreMod)
are retained. Blue.exe, AppMain.exe and Version_Info.txt are replaced.
The original OS, boot, MCU, resources and settings payloads are preserved byte
for byte. This follows the complete original update route, rather than the
two-file apps-only candidate route with a missing firmware.hex.

## MAXmade changes

- Blue.exe: eight saved Bluetooth devices, checked database I/O, list
  acknowledgement, delete guard and the Bluetooth audio buffer repair.
- AppMain.exe: eight-device list/two pages, bounded list copy, matching list
  acknowledgement, connection/reconnect guards and equivalent faster label scan.
- The existing File_Corruption_Fix nngnavi.exe is included unchanged at
  Storage Card4/NNG/nngnavi.exe. A second navigation patch is not needed to
  supply that file. Its internal changes were not authored by MAXmade.
- LGU header and displayed Version_Info.txt both read **{revision}**.

Eight refers to saved pairings, not simultaneous Bluetooth connections.
The audio repair has been reported working by Max after replacing the two
applications through Windows CE. That feedback does not validate this full
LGU installation, all eight slots or every vehicle function.
The original phone-type discovery filter remains: a laptop is not a useful
test of the new-phone list.

## Package checks

- **1,918 files:** the complete original payload plus the navigation executable.
- Only three original files changed; one file added.
- Both applications exactly match the checked BT8T03 pair.
- Header/size, encrypted ZIP CRCs, member hashes and separate PC extraction
  verified; original source files unchanged.
- `upgrade.lgu`: **{byte_count:,} bytes**, SHA-256 `{digest}`.

See build-manifest.json for all original/output member hashes and version
recognition checks. These checks validate the package bytes, not a physical
installation or recovery route.

## Before a hardware test

Keep your radio code, existing Windows CE/DBoot access and your own backup.
The package runs the full update, including the original OS/MCU payloads;
it is not a lightweight daily application swap.
It can overwrite source-package settings/resources as the original update does.
Keep your current Blue.exe, AppMain.exe and sc_db.db separately. Package-original
files are not a backup of your unit, and a full update rollback is unvalidated.

Use only hardware already covered by the original 7.0.5.MD conversion guide.
Native version recognition, installation/reboot, navigation, settings retention,
all eight pairings and vehicle controls must be checked before this becomes
the guide's recommended update. Existing updater copy/cleanup weaknesses are
preserved; they were not repaired by combining the files.

## Experimental installation test

1. Save the backups and radio code above. Prepare a FAT32 USB stick using the
   original guide's requirements. Copy only this folder's **upgrade.lgu** to
   the USB root, not inside a folder, and safely eject it from the PC.
2. Start the engine and wait for the normal MediaNav interface. Insert the USB.
   The proposed new version should be **{revision}**. If no update is offered
   or the displayed version differs, stop and report that before changing files.
3. Accept the update. Keep the engine running and USB connected until it has
   finished. The full original update can restart the unit several times and
   temporarily show Arabic text; follow the existing guide's completion steps.
4. Enter the radio code if prompted. Once normal operation returns, remove
   the USB. Check **Settings > System > System version**: **{revision}**.
5. Start navigation and check the map and a route. This package includes the
   existing corruption-fix executable; do not install its separate LGU afterward.
6. Check Bluetooth music/delay, a handsfree call, contacts, reconnect and both
   device pages. Test eight saved phones and retention after a normal restart.
   Also check radio, USB music, touch, volume, settings and vehicle controls.

Keep the original guide's older packages available. They are preserved for
reference and existing supported procedures; reinstalling an older version
after this build is not a verified rollback and can be rejected by version checks.

## Credits

Based on the original 7.0.5.MD conversion distributed in Upgrade_705MD_FavreMod
and its accompanying File_Corruption_Fix. Existing contributors retain credit.
MAXmade maintains this combined build and the Blue/AppMain changes listed above.
"""


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check-inputs", action="store_true")
    parser.add_argument("--revision")
    args = parser.parse_args()
    expected, sources, apps, proof, writer, extractor = inputs()
    if args.check_inputs:
        print(json.dumps(dict(status="inputs-verified", members=len(expected),
                              app_build=proof["app_build"], pairing_cases=proof["pairing_cases"],
                              app_layouts=proof["app_layouts"],
                              source_lgu=proof["source_lgu"],
                              navigation_source_lgu=proof["navigation_source_lgu"]), indent=2))
        return
    if not args.revision:
        parser.error("--revision is required; no release number is chosen implicitly")
    recognition = version_model(args.revision)
    if not all(x["ordinary_update_offered"] for x in recognition):
        raise ValueError("Chosen revision will not be offered from an existing MD build; choose an upgrade-compatible revision")
    out = ROOT / "build" / f"maxmade-{args.revision}"
    if out.exists():
        raise ValueError("Output already exists; do not overwrite earlier builds")
    baseline = {n: dict(item) for n, item in expected.items()}
    overrides = {**apps, VERSION_PATH: args.revision.encode("ascii")}
    out.mkdir(parents=True, exist_ok=False)
    payload = out / "payload"
    changes = []
    for name, item in expected.items():
        raw = overrides.get(name, sources[name].read_bytes())
        path = payload / name
        assert len(str(path)) < 240
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(raw)
        assert path.read_bytes() == raw
        if sha(raw) != item["sha256"]:
            changes.append(dict(path=name, before_sha256=item["sha256"], after_sha256=sha(raw)))
        item.update(bytes=len(raw), sha256=sha(raw))
    assert {c["path"] for c in changes} == {BLUE_PATH, APP_PATH, VERSION_PATH}
    assert (payload / VERSION_PATH).read_bytes() == args.revision.encode("ascii")
    print("Staged 1,918 verified files: complete 7.0.5.MD + BT8T03 + navigation fix", flush=True)
    candidate = out / "upgrade.lgu"
    writer_run = run_pc_tool(writer, ["-p", "m1", args.revision, payload, candidate], out / "dir2lgu.log")
    verification = verify_package(candidate, expected, args.revision)
    roundtrip = out / "roundtrip"
    extractor_run = run_pc_tool(extractor, [candidate, roundtrip], out / "lgu2dir.log")
    extracted = {relative(p.relative_to(roundtrip).as_posix()): p for p in roundtrip.rglob("*") if p.is_file()}
    assert set(extracted) == set(expected)
    for name, path in extracted.items():
        raw = path.read_bytes()
        assert len(raw) == expected[name]["bytes"] and sha(raw) == expected[name]["sha256"], name
    assert (roundtrip / VERSION_PATH).read_bytes().decode("ascii") == verification["content"]
    assert all(sha(path.read_bytes()) == baseline[name]["sha256"] for name, path in sources.items())
    # Store portable tool provenance, avoiding host-specific absolute commands.
    for run in (writer_run, extractor_run):
        run.pop("command")
    result = dict(
        generated_utc=datetime.now(timezone.utc).isoformat(), revision=args.revision,
        title=f"MediaNav MAXmade — {args.revision}", candidate_kind="EXPERIMENTAL FULL UPDATE",
        build_complete=True, installation_tested=False, recommended_public_update=False,
        firmware_native_execution=False, pc_tool_execution=True, flashed=False,
        source=proof, source_members=1917, output_members=len(expected),
        preserved_original_members=1914, changed_original_members=changes,
        added_members=[dict(path=NAV_PATH, bytes=expected[NAV_PATH]["bytes"], sha256=NAV_HASH)],
        includes_complete_original_os_boot_mcu_payload=True, changes_settings_as_original_payload=True,
        header_and_displayed_version_match=True, version_recognition_model=recognition,
        writer=writer_run, extractor=extractor_run, verification=verification,
        original_member_hashes=baseline, original_source_hashes_unchanged=True,
        pc_extractor_matches=len(extracted), builder_sha256=sha(Path(__file__).read_bytes()),
        user_feedback=dict(audio_delay="Reported fixed on Max's unit after CE application replacement",
                           full_lgu_installation_tested=False, eight_slot_hardware_test_complete=False),
        limitations=["Package validation is not a native installation or recovery test",
                     "Original updater copy/cleanup/settings-backup weaknesses are unchanged",
                     "Full original OS/MCU payload retained; original hardware restrictions apply",
                     "Navigation executable is reused unchanged; internal original fix not reconstructed",
                     "Eight slots, stability, settings retention and vehicle functions still require hardware tests"],
    )
    (out / "build-manifest.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    (out / "README.md").write_text(readme(args.revision, verification["lgu_sha256"], verification["bytes"]), encoding="utf-8")
    (out / "SHA256SUMS.txt").write_text(f"{verification['lgu_sha256']}  upgrade.lgu\n", encoding="ascii")
    archive = Path(str(out) + ".zip")
    assert not archive.exists()
    deliver = ("upgrade.lgu", "README.md", "build-manifest.json", "SHA256SUMS.txt")
    with zipfile.ZipFile(archive, "w", compression=zipfile.ZIP_DEFLATED) as zipped:
        for name in deliver:
            zipped.write(out / name, name)
    with zipfile.ZipFile(archive) as zipped:
        assert zipped.testzip() is None and set(zipped.namelist()) == set(deliver)
        assert all(zipped.read(n) == (out / n).read_bytes() for n in deliver)
    print(json.dumps(dict(status="roundtrip-passed", revision=args.revision,
                          lgu=str(candidate), zip=str(archive), bytes=verification["bytes"],
                          sha256=verification["lgu_sha256"], members=len(expected),
                          changed_original_members=3, added_members=1,
                          installation_tested=False), indent=2))


if __name__ == "__main__":
    main()
