"""Install the recorded portable Ghidra/JDK packages without changing research pins."""
import hashlib
import json
from pathlib import Path
import urllib.request
import zipfile

ROOT = Path(__file__).resolve().parents[1]
DEST = ROOT / "tools/vendor"


def install(package):
    filename = package["file"]
    if Path(filename).name != filename or "\\" in filename:
        raise ValueError("Invalid package filename")
    target = DEST / filename
    directory = (ROOT / package["directory"].replace("\\", "/")).resolve()
    directory.relative_to(DEST.resolve())
    if not target.exists():
        partial = target.with_suffix(target.suffix + ".partial")
        request = urllib.request.Request(package["url"], headers={"User-Agent": "MediaNav-MAXmade"})
        digest = hashlib.sha256()
        with urllib.request.urlopen(request, timeout=60) as source, partial.open("wb") as output:
            while block := source.read(1024 * 1024):
                output.write(block)
                digest.update(block)
        if digest.hexdigest() != package["sha256"]:
            raise ValueError(f"Downloaded package checksum mismatch: {filename}")
        partial.rename(target)
    digest = hashlib.sha256()
    with target.open("rb") as source:
        while block := source.read(1024 * 1024):
            digest.update(block)
    if digest.hexdigest() != package["sha256"]:
        raise ValueError(f"Cached package checksum mismatch: {filename}")
    marker = directory / ".medianav-extraction-complete"
    if marker.exists() and marker.read_text(encoding="ascii") == package["sha256"]:
        print(f"Already installed: {directory.name}", flush=True)
        return
    if directory.exists():
        raise FileExistsError(f"Inspect the existing/partial installation first: {directory}")
    with zipfile.ZipFile(target) as archive:
        for entry in archive.infolist():
            resolved = (DEST / entry.filename).resolve()
            resolved.relative_to(directory)
            if entry.external_attr >> 16 & 0o170000 == 0o120000:
                raise ValueError("Unexpected archive symlink")
        archive.extractall(DEST)
    marker.write_text(package["sha256"], encoding="ascii")
    print(f"Installed pinned package: {directory.name}", flush=True)


def main():
    recorded = json.loads((ROOT / "analysis/re-toolchain.json").read_bytes())
    DEST.mkdir(parents=True, exist_ok=True)
    for name in ("ghidra", "jdk"):
        install(recorded[name])


if __name__ == "__main__":
    main()
