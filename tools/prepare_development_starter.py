"""Prepare instructions and a laptop backup checker; no device executable or LGU."""
from pathlib import Path
import shutil
import zipfile

ROOT = Path(__file__).resolve().parents[1]
DEST = ROOT / "build" / "development-starter"

INSTRUCTIONS = """MediaNav development - first session

This folder is preparation for a file backup and a normal CE entry/return test.
It contains no firmware update, no launcher, and no Windows CE executable.
The Python checker runs on your laptop (Python 3.12 or newer), not on MediaNav.

Your current baseline: 7.0.5.MD; CE entry through a screen gesture or menu.
This entry method has not been proved independent of the main application.

1. Use a USB stick with sufficient free space. Inspect the entire stick and
   remove any update/install/autorun files before inserting it in the unit.
   Do not format a stick containing your only backup or CE access tools.
   Copy this folder's contents onto the prepared stick.

2. Enter CE using your existing gesture/menu. Record the exact steps and note
   any desktop shortcuts, particularly Redemarrer WinCE / Redemarrer.
   Do not change startup files, registry settings, or run a patched app yet.

3. In CE Explorer, copy the CONTENTS of each corresponding internal volume
   into Backup/Storage Card, Backup/Storage Card2, Backup/Storage Card3, and
   Backup/Storage Card4 on the USB stick. Keep the four volumes separate.
   Enable display of hidden/system files if your Explorer supports it.
   Record skipped files and copy errors. Do not copy the USB volume into itself.

4. Return to your normal MediaNav using your already-known return procedure.
   If you do not know that procedure, stop and report the desktop shortcuts
   before trying a reboot command. Verify normal startup, Bluetooth and nav.
   This checks the existing route; it does not simulate or prove brick recovery.

5. On your laptop, copy Backup from the USB to a separate PC folder.
   Leave the USB copy intact. Example laptop command, replacing E: with the
   actual USB drive letter and using the actual PC backup path:

   py check_unit_backup.py "E:/Backup" --compare "C:/MediaNav-backup-7.0.5MD"

   Exit 0 means the expected files are present/readable and the two copies
   have matching sizes/hashes. Exit 2 means review the reported errors or
   differences. Important paths reflect our known 7.0.5 package; a difference
   on your unit needs investigation, not automatic replacement.
   Hashing can take several minutes for maps. The checker only reads files.

These checks cannot detect a file omitted from BOTH copies unless it is one
of the listed important files. They do not compare against the running unit.
The backup is not a full flash, registry, bootloader, or MCU backup.
It does not guarantee recovery from a failed boot or hardware problem.

Next development milestone:
- establish a CE return route that does not require the experimental app;
- try an unmodified original app from a separate location, with its original
  startup arguments and dependencies, before any patched app;
- account for single-instance processes, automatic relaunches and shared
  settings before selecting a launch/rollback mechanism;
- prove that the known-good app can be restored/restarted;
- then use numbered application builds and logs for daily testing.

We have not supplied a test launcher or a modified app in this starter.
The laptop USB/remote-access route is still unverified. Do not connect the
two USB-host ports with a plain USB-A-to-A cable.
"""


def main() -> None:
    DEST.mkdir(parents=True, exist_ok=True)
    (DEST / "READ-ME-FIRST.txt").write_text(INSTRUCTIONS, encoding="utf-8")
    shutil.copyfile(ROOT / "tools" / "check_unit_backup.py", DEST / "check_unit_backup.py")
    for volume in ("Storage Card", "Storage Card2", "Storage Card3", "Storage Card4"):
        (DEST / "Backup" / volume).mkdir(parents=True, exist_ok=True)
    files = [path for path in DEST.rglob("*") if path.is_file()]
    expected = {"READ-ME-FIRST.txt", "check_unit_backup.py"}
    actual = {path.relative_to(DEST).as_posix() for path in files}
    if actual != expected:
        raise SystemExit(f"Unexpected files in starter; refusing to package: {sorted(actual - expected)}")
    archive = DEST.with_suffix(".zip")
    with zipfile.ZipFile(archive, "w", compression=zipfile.ZIP_DEFLATED) as output:
        for path in sorted(DEST.rglob("*")):
            output.write(path, path.relative_to(DEST).as_posix())
    print(f"Prepared {archive}; two files, four empty backup volume folders; no LGU or executable.")


if __name__ == "__main__":
    main()
