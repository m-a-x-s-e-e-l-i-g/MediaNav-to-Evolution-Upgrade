"""Reproduce a complete release payload from a hash-guarded binary edit plan."""
import argparse
import hashlib
import io
import json
from pathlib import Path, PurePosixPath
import subprocess
import tempfile
import zipfile
import zlib

ROOT = Path(__file__).resolve().parents[1]
PLAN = ROOT / "src/patches/max04.json"


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def member(name):
    path = PurePosixPath(name)
    if (not name or "\\" in name or ":" in name or path.is_absolute()
            or any(part in ("", ".", "..") for part in name.split("/"))):
        raise ValueError(f"Unsafe member path: {name}")
    return path


def plan_at(path):
    plan = json.loads(path.read_bytes())
    if plan["format"] != 1:
        raise ValueError("Unsupported edit-plan format")
    names = [row["path"] for row in plan["members"]]
    changes = [row["path"] for row in plan["changes"]]
    for name in names:
        member(name)
    if len(set(names)) != len(names) or len({n.casefold() for n in names}) != len(names):
        raise ValueError("Duplicate payload members")
    if len(set(changes)) != len(changes) or not set(changes) <= set(names):
        raise ValueError("Invalid changed-member list")
    for row in plan["changes"]:
        if ("asset" in row) == ("edits" in row):
            raise ValueError("Each change needs either an asset or binary edits")
        if "asset" in row:
            asset = member(row["asset"])
            if not asset.is_relative_to("src/ui"):
                raise ValueError("Artwork must live under src/ui")
        else:
            end = 0
            for edit in row["edits"]:
                if edit["offset"] < end:
                    raise ValueError("Overlapping or unordered binary edits")
                before, after = bytes.fromhex(edit["before"]), bytes.fromhex(edit["after"])
                end = edit["offset"] + len(before)
                if not before and not after:
                    raise ValueError("Empty edit")
    return plan


def extract_lgu(raw, plan, destination):
    """Decode pinned LGU0 using the published upstream XOR table; no PC executable."""
    import struct
    if sha(raw) != plan["baseline_lgu_sha256"]:
        raise ValueError("Baseline LGU checksum does not match the edit plan")
    if raw[:4] != b"LGU0" or struct.unpack_from("<Q", raw, 12)[0] != len(raw):
        raise ValueError("Invalid LGU0 header")
    key = bytes.fromhex(json.loads((ROOT / "src/container/lgu0.json").read_bytes())["xor_hex"])
    if len(key) != 1024:
        raise ValueError("Invalid XOR table")
    data = bytearray(raw[1024:])
    for index, value in enumerate(key):
        data[index::1024] = data[index::1024].translate(bytes(n ^ value for n in range(256)))
    if zlib.crc32(data) != struct.unpack_from("<I", raw, 24)[0]:
        raise ValueError("LGU payload CRC mismatch")
    expected = {r["path"]: r for r in plan["members"]}
    with zipfile.ZipFile(io.BytesIO(data)) as archive:
        entries = archive.infolist()
        if len(entries) != len(expected) or {e.filename for e in entries} != set(expected):
            raise ValueError("Baseline package member set changed")
        for entry in entries:
            name = member(entry.filename)
            if entry.is_dir():
                raise ValueError("Unexpected directory member")
            value = archive.read(entry, pwd=b"I_LOVE_LG^^")
            row = expected[entry.filename]
            if len(value) != row["before_bytes"] or sha(value) != row["before_sha256"]:
                raise ValueError(f"Baseline member mismatch: {name}")
            target = destination / str(name)
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(value)


def prepare(plan, destination):
    """Recover a historical build input locally; it is not an offered upgrade."""
    if destination.exists():
        raise FileExistsError(f"Use a fresh input directory: {destination}")
    destination.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="maxmade-input-", dir=destination.parent) as temp:
        raw = subprocess.run(["git", "show", f"{plan['baseline_commit']}:{plan['baseline_git_path']}"],
                             cwd=ROOT, check=True, stdout=subprocess.PIPE).stdout
        extract_lgu(raw, plan, Path(temp))
        Path(temp).rename(destination)


def reproduce(plan, baseline, destination):
    if destination.exists():
        raise FileExistsError(f"Use a fresh output directory: {destination}")
    rows = {row["path"]: row for row in plan["members"]}
    actual = {p.relative_to(baseline).as_posix() for p in baseline.rglob("*") if p.is_file()}
    if actual != set(rows):
        raise ValueError("Full baseline inventory changed; missing/extra files are refused")
    changes = {row["path"]: row for row in plan["changes"]}
    destination.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="maxmade-payload-", dir=destination.parent) as temp:
        payload = Path(temp) / "payload"
        for name, row in rows.items():
            before = (baseline / name).read_bytes()
            if len(before) != row["before_bytes"] or sha(before) != row["before_sha256"]:
                raise ValueError(f"Baseline bytes changed: {name}")
            result = before
            change = changes.get(name)
            if change:
                if "asset" in change:
                    result = (ROOT / change["asset"]).read_bytes()
                else:
                    result = bytearray(before)
                    for edit in reversed(change["edits"]):
                        at = edit["offset"]
                        old, new = bytes.fromhex(edit["before"]), bytes.fromhex(edit["after"])
                        if at > len(result) or result[at:at + len(old)] != old:
                            raise ValueError(f"Edit precondition failed: {name}@{at}")
                        result[at:at + len(old)] = new
                    result = bytes(result)
            if len(result) != row["after_bytes"] or sha(result) != row["after_sha256"]:
                raise ValueError(f"Reproduced member mismatch: {name}")
            target = payload / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(result)
            if target.read_bytes() != result:
                raise ValueError(f"Written member mismatch: {name}")
        result = {"revision": plan["revision"], "members_verified": len(rows),
                  "changed_members": len(changes), "unchanged_members": len(rows) - len(changes),
                  "missing_members": [], "added_members": [], "native_executed": False,
                  "payload_matches_published_release": True, "edit_plan_sha256": sha(PLAN.read_bytes())}
        (Path(temp) / "reproduction.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
        Path(temp).rename(destination)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--prepare-input", type=Path, help="Extract pinned input from this repository's Git history")
    parser.add_argument("--baseline", type=Path, help="Complete extracted baseline payload")
    parser.add_argument("--out", type=Path, help="Fresh directory for the reproduced full payload")
    args = parser.parse_args()
    if args.prepare_input and (args.baseline or args.out):
        parser.error("Use input preparation and payload reproduction as separate commands")
    plan = plan_at(PLAN)
    if args.prepare_input:
        prepare(plan, args.prepare_input.resolve())
        print(f"Verified and extracted {len(plan['members'])} baseline members")
    elif args.baseline and args.out:
        print(json.dumps(reproduce(plan, args.baseline.resolve(), args.out.resolve()), indent=2))
    else:
        parser.error("Supply --prepare-input, or both --baseline and --out")


if __name__ == "__main__":
    main()
