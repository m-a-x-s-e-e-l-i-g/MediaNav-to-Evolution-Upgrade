"""Read-only checks of a CE file backup and, optionally, a second copy.

This cannot establish that a backup matches the live device or restores it.
Run on the laptop, not on Windows CE. Uses only the Python standard library.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path

VOLUMES = ("Storage Card", "Storage Card2", "Storage Card3", "Storage Card4")
IMPORTANT = (
    "Storage Card/NK.bin",
    "Storage Card/System/Version_Info.txt",
    "Storage Card/System/Blue.exe",
    "Storage Card/System/AppMain.exe",
    "Storage Card/System/UpgradeManager.exe",
    "Storage Card4/NNG/nngnavi.exe",
)


def snapshot(root: Path) -> dict:
    files = {}
    errors = []
    volumes = {}
    for volume in VOLUMES:
        directory = root / volume
        volumes[volume] = {"present": directory.is_dir(), "files": 0}
        if not directory.is_dir():
            errors.append(f"Missing volume folder: {volume}")
            continue
        if directory.is_symlink() or directory.is_junction():
            errors.append(f"Linked volume folder refused: {volume}")
            continue
        try:
            for path in directory.walk(on_error=lambda error: errors.append(str(error))):
                parent, directories, names = path
                for name in list(directories):
                    child = parent / name
                    if child.is_symlink() or child.is_junction():
                        errors.append(f"Linked directory refused: {child.relative_to(root)}")
                        directories.remove(name)
                for name in names:
                    child = parent / name
                    relative = child.relative_to(root).as_posix()
                    try:
                        if child.is_symlink():
                            raise OSError("Linked file refused")
                        before = child.stat()
                        digest = hashlib.sha256()
                        with child.open("rb") as stream:
                            for block in iter(lambda: stream.read(1024 * 1024), b""):
                                digest.update(block)
                        after = child.stat()
                        if (before.st_size, before.st_mtime_ns) != (after.st_size, after.st_mtime_ns):
                            raise OSError("File changed during hashing")
                        files[relative] = {"bytes": after.st_size, "sha256": digest.hexdigest()}
                        volumes[volume]["files"] += 1
                    except OSError as error:
                        errors.append(f"{relative}: {error}")
        except OSError as error:
            errors.append(f"{volume}: {error}")
        if not volumes[volume]["files"]:
            errors.append(f"No readable files in: {volume}")
    for name in IMPORTANT:
        if name not in files or files[name]["bytes"] == 0:
            errors.append(f"Important file missing or empty: {name}")
    version = None
    version_file = root / IMPORTANT[1]
    if IMPORTANT[1] in files:
        try:
            with version_file.open("rb") as stream:
                data = stream.read(256)
            version = data.decode("ascii").strip("\x00\r\n ")
        except (OSError, UnicodeDecodeError) as error:
            errors.append(f"Cannot read version: {error}")
    return {"volumes": volumes, "version": version, "files": files, "errors": errors}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("backup", type=Path, help="Parent folder containing the four Storage Card folders")
    parser.add_argument("--compare", type=Path, help="Second backup copy; compare every file byte-for-byte by SHA-256")
    args = parser.parse_args()
    first_root = args.backup.resolve()
    if args.compare:
        second_root = args.compare.resolve()
        if first_root == second_root or first_root in second_root.parents or second_root in first_root.parents:
            parser.error("Use two separate, non-nested backup folders for the comparison")
    first = snapshot(first_root)
    result = {
        "scope": "File-copy checks only; not a live-device check, full flash backup, or recovery proof.",
        "version": first["version"],
        "volumes": first["volumes"],
        "files": len(first["files"]),
        "bytes": sum(item["bytes"] for item in first["files"].values()),
        "errors": first["errors"],
    }
    if args.compare:
        second = snapshot(args.compare.resolve())
        names = set(first["files"]) | set(second["files"])
        differences = sorted(name for name in names if first["files"].get(name) != second["files"].get(name))
        result["comparison"] = {"differences": differences, "errors": second["errors"]}
        failed = bool(first["errors"] or second["errors"] or differences)
    else:
        failed = bool(first["errors"])
    result["file_checks_passed"] = not failed
    print(json.dumps(result, indent=2))
    return 2 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
