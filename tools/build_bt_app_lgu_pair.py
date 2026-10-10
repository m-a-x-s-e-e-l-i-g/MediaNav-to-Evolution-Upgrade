"""Build REVIEW-ONLY two-application LGUs from BT8T03 and pinned 7.0.5.MD.

No firmware/device execution. The stock installer's missing-HEX MCU route
remains unresolved; packaging validation must not become installation approval.
Version_Info and Bluetooth database are deliberately not members.
"""
import hashlib
import json
import zipfile
from datetime import datetime, timezone
from pathlib import Path
import pefile
from build_review_update import ROOT, WRITER_HASH, EXTRACTOR_HASH, run_pc_tool, verify_package


def sha(raw): return hashlib.sha256(raw).hexdigest()


GUIDE = """MediaNav BT8T03 / original-application LGU pair - REVIEW ONLY

NOT READY TO INSTALL. These are checked containers, not validated installers.
The original 7.0.5.MD UpgradeManager enters MICOM/MCU update handling even
without firmware.hex. The missing-image branch constructs an A1/tag08 frame
containing 1024 zero bytes; the followed MCU path has no demonstrated reboot-
only bypass before its programming routine. A smaller LGU does not avoid it.
The same updater also has unverified copy/cleanup and settings-backup behavior.
An application-update path that avoids this must be validated first.

Packages:
  Test-BT8T03/BT8T03-apps.candidate.lgu
    AppMain.exe and Blue.exe EXACTLY from the checked BT8T03 test pair.
    Includes eight-device changes, the audio buffer repair and label scan.
    Header revision: 7.0.5.MD.T03.
  Restore-705MD/restore705-apps.candidate.lgu
    AppMain.exe and Blue.exe EXACTLY from the original 7.0.5.MD source package.
    Header revision: 7.0.5.MD.Z03.

Each LGU has EXACTLY these two members:
  upgrade/Storage Card/System/AppMain.exe
  upgrade/Storage Card/System/Blue.exe

No Version_Info.txt, database, navigation, NK, booter, firmware.hex, updater,
autorun or settings file is included. Installed Version_Info therefore stays
unchanged. Header labels are used for the existing version recognition only.
Both labels sort above 7.0.5.MD and 7.0.5.MD.MAX02. Starting from either of
those installed labels, test -> original -> test can be recognized repeatedly
because neither package replaces Version_Info. Other installed labels must
be checked separately; recognition is not evidence of installation success.
Leaving the same USB attached can offer this update again.

Restore means ORIGINAL APPLICATION CODE, not whole-unit recovery or a backup
of your particular unit. Original applications support five stored devices.
Keep your pre-test Blue.exe, AppMain.exe and sc_db.db backup. Exact old pairing
restoration needs your saved database, which is not available in this pair.
These LGUs cannot recover a unit that cannot reach its update interface.

After the installer path has been validated, the intended workflow is selecting
ONE package per USB/update session. Do not install or rename these candidates
to upgrade.lgu now. No unit has been changed by creating this bundle.

manifest.json includes each header revision, exact members and hashes, complete
container checks and extraction results from the independent PC lgu2dir tool.
"""


def build_one(directory, filename, header, applications, writer, extractor):
    directory.mkdir(parents=True, exist_ok=False)
    payload = directory / "payload"; expected = {}
    for name, raw in applications.items():
        member = "upgrade/Storage Card/System/" + name
        target = payload / member; target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(raw)
        expected[member] = dict(bytes=len(raw), sha256=sha(raw))
    candidate = directory / filename
    writing = run_pc_tool(writer, ["-p", "m1", header, payload, candidate], directory / "dir2lgu.log")
    verification = verify_package(candidate, expected, header)
    roundtrip = directory / "roundtrip"
    extracting = run_pc_tool(extractor, [candidate, roundtrip], directory / "lgu2dir.log")
    extracted = {p.relative_to(roundtrip).as_posix(): p for p in roundtrip.rglob("*") if p.is_file()}
    assert set(extracted) == set(expected)
    for member, path in extracted.items():
        assert path.stat().st_size == expected[member]["bytes"]
        assert sha(path.read_bytes()) == expected[member]["sha256"]
    return dict(path=str(candidate.relative_to(ROOT)), header_revision=header,
                members=expected, writer=writing, extractor=extracting,
                verification=verification, independent_pc_extractor_matches=len(extracted))


def main():
    control = ROOT / "build/bt-menu-audio-test-BT8T03"
    evidence = control / "manifest.json"
    manifest = json.loads(evidence.read_text(encoding="utf-8"))
    assert manifest["build_complete"] and manifest["pairing_case_total"] == 824
    test = {n: (control / "Test" / n).read_bytes() for n in ("AppMain.exe", "Blue.exe")}
    original = {n: (ROOT / manifest["original_files"][n]["source"]).read_bytes() for n in test}
    for name in test:
        assert sha(test[name]) == manifest["files"][name]["sha256"]
        assert sha(original[name]) == manifest["original_files"][name]["sha256"]
    assert manifest["label_exhaustive_evidence"]["checks"]["exhaustive_utf16_cases"] == 65536
    label_evidence = ROOT / manifest["label_exhaustive_evidence"]["path"]
    assert sha(label_evidence.read_bytes()) == manifest["label_exhaustive_evidence"]["sha256"]
    for name, digest in manifest["tool_sha256"].items():
        assert sha((ROOT / "tools" / name).read_bytes()) == digest
    writer = ROOT / "tools/vendor/lgu-favremod/dir2lgu.exe"
    extractor = ROOT / "tools/vendor/lgu-favremod/lgu2dir.exe"
    assert sha(writer.read_bytes()) == WRITER_HASH and sha(extractor.read_bytes()) == EXTRACTOR_HASH
    assert all(pefile.PE(str(tool)).FILE_HEADER.Machine == 0x14c for tool in (writer, extractor))
    out = ROOT / "build/bt-app-lgu-pair-BT8T03"; archive = out.with_suffix(".zip")
    if out.exists() or archive.exists(): raise ValueError("Prior output is never overwritten")
    out.mkdir()
    packages = {}
    for kind, folder, filename, header, apps in (
            ("test", "Test-BT8T03", "BT8T03-apps.candidate.lgu", "7.0.5.MD.T03", test),
            ("restore", "Restore-705MD", "restore705-apps.candidate.lgu", "7.0.5.MD.Z03", original)):
        assert len(header) <= 19
        packages[kind] = build_one(out / folder, filename, header, apps, writer, extractor)
    versions = []
    for installed in ("7.0.5.MD", "7.0.5.MD.MAX01", "7.0.5.MD.MAX02"):
        for action in ("test", "restore", "test"):
            offered = packages[action]["header_revision"]
            assert offered > installed
            versions.append(dict(current=installed, action=action, offered=offered,
                                 recognized_by_lexical_model=True, installed_version_unchanged=True))
    report = dict(created_utc=datetime.now(timezone.utc).isoformat(), build_complete=True,
                  candidate_kind="REVIEW ONLY - NOT READY TO INSTALL", installation_ready=False,
                  firmware_native_execution=False, pc_tool_execution=True, unit_tested=False, flashed=False,
                  control_manifest=str(evidence.relative_to(ROOT)), control_manifest_sha256=sha(evidence.read_bytes()),
                  packages=packages, version_sequence_model=versions,
                  changes_installed_version=False, includes_database=False,
                  source_originals_unchanged=True,
                  builder_sha256=sha(Path(__file__).read_bytes()),
                  limitations=["Original updater reaches missing-HEX MICOM/MCU path; programming/reset behavior unvalidated",
                               "Stock staged installer copy/marker/settings-backup failures are not repaired",
                               "Package-original binaries are not a unit-specific rollback backup",
                               "Original five-slot applications need saved pre-test database for exact pairing rollback",
                               "Header recognition model is not a tested USB/install/reboot workflow"])
    for n, raw in original.items(): assert (ROOT / manifest["original_files"][n]["source"]).read_bytes() == raw
    for n, raw in test.items(): assert (control / "Test" / n).read_bytes() == raw
    (out / "manifest.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    (out / "READ-ME-FIRST.txt").write_text(GUIDE, encoding="utf-8")
    with zipfile.ZipFile(archive, "w", compression=zipfile.ZIP_DEFLATED) as zipped:
        # Deliver only candidates, logs, manifest and guide. Payload/roundtrip
        # trees stay in the workspace for byte-level review.
        for p in sorted(out.rglob("*")):
            if p.is_file() and not any(part in ("payload", "roundtrip") for part in p.relative_to(out).parts):
                zipped.write(p, p.relative_to(out).as_posix())
    with zipfile.ZipFile(archive) as zipped:
        assert zipped.testzip() is None
        expected_names = {p.relative_to(out).as_posix() for p in out.rglob("*") if p.is_file()
                          and not any(part in ("payload", "roundtrip") for part in p.relative_to(out).parts)}
        assert set(zipped.namelist()) == expected_names
        assert all(zipped.read(n) == (out / n).read_bytes() for n in expected_names)
    print(json.dumps(dict(bundle=str(archive), bundle_sha256=sha(archive.read_bytes()),
        installation_ready=False, packages={k:dict(path=v["path"], bytes=v["verification"]["bytes"],
        sha256=v["verification"]["lgu_sha256"], members=len(v["members"])) for k,v in packages.items()}), indent=2))


if __name__ == "__main__": main()
