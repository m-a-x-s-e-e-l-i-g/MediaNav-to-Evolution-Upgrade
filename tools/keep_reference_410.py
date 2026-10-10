"""Preserve user-supplied 4.1.0 LGU and inventory files only; no code analysis.

Reads the container with the already-known LGU/ZIP format. No firmware or PC
executable is run. Reference files are kept outside the reverse-engineering
corpus inputs. Desktop input and existing candidates are never modified.
"""
import argparse
import csv
import hashlib
import io
import json
import re
import shutil
import struct
import zipfile
import zlib
from collections import Counter
from pathlib import Path, PurePosixPath

ROOT = Path(__file__).resolve().parents[1]


def sha(raw): return hashlib.sha256(raw).hexdigest()


def safe_name(name):
    name = name.replace("\\", "/").rstrip("/")
    parts = name.split("/")
    if not name or name.startswith("/") or any(p in ("", ".", "..") or ":" in p for p in parts):
        raise ValueError(f"Unsafe member: {name}")
    for part in parts:
        if part.endswith((" ", ".")) or re.search(r'[<>"|?*\x00-\x1f]', part):
            raise ValueError(f"Invalid Windows path: {name}")
        if part.split(".")[0].upper() in {"CON", "PRN", "AUX", "NUL", *[f"{x}{n}" for x in ("COM", "LPT") for n in range(1, 10)]}:
            raise ValueError(f"Reserved Windows path: {name}")
    return name


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    args = parser.parse_args()
    original = args.source.resolve(); raw = original.read_bytes(); digest = sha(raw)
    assert raw[:4] == b"LGU0" and struct.unpack_from("<2I", raw, 4) == (7, 1024)
    assert struct.unpack_from("<Q", raw, 12)[0] == len(raw)
    label = raw[0x2a0:0x2dc].decode("utf-16le").split("\0")[0]
    version = raw[0x2dc:0x304].decode("utf-16le").split("\0")[0]
    assert label == "*MEDIA-NAV*" and version == "4.1.0"
    text = (ROOT / "sources/MediaNavMods/pc/lgutool/lgu2dir/xorArray.h").read_text(encoding="utf-8")
    block = re.search(r"xorArrLGU0\[\]\s*=\s*\{(.*?)\}", text, re.S).group(1)
    key = bytes(int(x, 16) for x in re.findall(r"0x([0-9a-fA-F]+)", block)); assert len(key) == 1024
    payload = bytearray(raw[1024:])
    for i, value in enumerate(key):
        payload[i::1024] = payload[i::1024].translate(bytes(n ^ value for n in range(256)))
    header_crc = struct.unpack_from("<I", raw, 24)[0]
    encoded_crc, decoded_crc = zlib.crc32(raw[1024:]), zlib.crc32(payload)
    # Supplied 4.1.0 covers the encoded container payload. Record that scope
    # instead of assuming the decoded-payload scope used by local candidates.
    assert header_crc in (encoded_crc, decoded_crc)
    crc_scope = "encoded_payload" if header_crc == encoded_crc else "decoded_payload"
    dest = ROOT / "extracted/reference-410"; saved = ROOT / "sources/reference-410/upgrade.lgu"
    report = ROOT / "analysis/reference-410"
    if dest.exists() or saved.exists() or report.exists():
        raise ValueError("Reference output exists; refusing to overwrite it")
    with zipfile.ZipFile(io.BytesIO(payload)) as archive:
        entries = archive.infolist(); names = [safe_name(e.filename) for e in entries]
        assert len(set(n.casefold() for n in names)) == len(names)
        assert sum(e.file_size for e in entries) < 2 * 1024 ** 3
        for entry, name in zip(entries, names):
            target = (dest / name).resolve(); target.relative_to(dest.resolve())
            # Reject symlinks instead of following any archived link semantics.
            assert (entry.external_attr >> 16) & 0o170000 != 0o120000
            assert not entry.is_dir() or entry.file_size == 0
        saved.parent.mkdir(parents=True); shutil.copyfile(original, saved)
        assert sha(saved.read_bytes()) == digest
        dest.mkdir(); records = []
        for index, (entry, name) in enumerate(zip(entries, names), 1):
            path = dest / name
            if entry.is_dir(): path.mkdir(parents=True, exist_ok=True); continue
            data = archive.read(entry, pwd=b"I_LOVE_LG^^")
            assert len(data) == entry.file_size and zlib.crc32(data) == entry.CRC
            path.parent.mkdir(parents=True, exist_ok=True); path.write_bytes(data)
            assert sha(path.read_bytes()) == sha(data)
            records.append(dict(path=name, size=len(data), sha256=sha(data)))
            if index % 100 == 0: print(f"Reference files checked: {index}/{len(entries)}", flush=True)
    assert sha(original.read_bytes()) == digest and sha(saved.read_bytes()) == digest
    report.mkdir()
    with (report / "inventory.csv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=("path", "size", "sha256")); writer.writeheader(); writer.writerows(records)
    with (ROOT / "analysis/705md-inventory.csv").open(encoding="utf-8", newline="") as stream:
        baseline = {r["path"].replace("\\", "/").casefold(): r for r in csv.DictReader(stream)}
    current = {r["path"].casefold(): r for r in records}
    same = []; changed = []; only_reference = []; only_705 = []
    for name in sorted(current.keys() | baseline.keys()):
        a, b = current.get(name), baseline.get(name)
        if a is None: only_705.append(b["path"])
        elif b is None: only_reference.append(a["path"])
        elif a["sha256"] == b["sha256"]: same.append(a["path"])
        else: changed.append(dict(path=a["path"], reference_bytes=a["size"],
                                  bytes_705md=int(b["size"]), reference_sha256=a["sha256"], sha256_705md=b["sha256"]))
    location_counts = Counter("/".join(PurePosixPath(r["path"]).parts[:2]) for r in records)
    versions = {r["path"]: (dest / r["path"]).read_text(encoding="ascii", errors="replace").strip()
                for r in records if PurePosixPath(r["path"]).name.lower() == "version_info.txt"}
    result = dict(purpose="File-layout reference only; user explicitly excluded reverse engineering",
                  source=str(original), retained_copy=str(saved.relative_to(ROOT)),
                  bytes=len(raw), sha256=digest, lgu_label=label, lgu_version=version,
                  version_files=versions, file_count=len(records), unpacked_bytes=sum(r["size"] for r in records),
                  extracted_root=str(dest.relative_to(ROOT)), inventory=str((report / "inventory.csv").relative_to(ROOT)),
                  location_counts=dict(sorted(location_counts.items())), original_source_unchanged=True,
                  lgu_crc_and_all_member_crc_sizes_valid=True, lgu_header_crc_scope=crc_scope,
                  lgu_header_crc=hex(header_crc), encoded_payload_crc=hex(encoded_crc),
                  decoded_payload_crc=hex(decoded_crc), firmware_execution=False,
                  reverse_engineering=False, added_to_analysis_corpus=False,
                  comparison=dict(baseline="7.0.5.MD", same_bytes=same, changed_same_path=changed,
                                  only_reference=only_reference, only_705md=only_705),
                  producer_sha256=sha(Path(__file__).read_bytes()))
    (report / "manifest.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(dict(version=version, files=len(records), locations=result["location_counts"],
                         same_bytes=len(same), changed_same_path=len(changed), only_reference=len(only_reference),
                         only_705md=len(only_705), sha256=digest, version_files=versions), indent=2))


if __name__ == "__main__": main()
