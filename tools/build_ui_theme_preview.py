"""Build a read-only browser workbench from actual firmware image resources.

No firmware execution, patching, update container, or hardware access.
"""
import argparse
import csv
import hashlib
import json
import shutil
import struct
from collections import Counter
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_BASE = ROOT / "extracted/705md"
DEFAULT_OUT = ROOT / "build/ui-theme-preview-01"
HOME_BUTTONS = {
    "home_radio_btn.bmp", "home_media_btn.bmp", "home_phone_btn.bmp",
    "home_map_btn.bmp", "home_navi_btn.bmp", "home_setting_btn.bmp",
}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def build(base, out, concept=None):
    if out.exists():
        raise FileExistsError(f"Use a fresh output directory: {out}")
    if (base / "manifest.json").exists():
        manifest_bytes = (base / "manifest.json").read_bytes()
        manifest = json.loads(manifest_bytes)
        payload = base / "payload"
    elif base == (ROOT / "extracted/705md").resolve():
        inventory = ROOT / "analysis/705md-inventory.csv"
        manifest_bytes = inventory.read_bytes()
        with inventory.open(encoding="utf-8", newline="") as stream:
            manifest = {"members": [dict(path=r["path"], bytes=int(r["size"]),
                                        sha256=r["sha256"]) for r in csv.DictReader(stream)]}
        payload = base
    else:
        raise ValueError("A verified development manifest or original 705md inventory is required")
    baseline = {}
    for member in manifest["members"]:
        relative = Path(member["path"])
        if relative.is_absolute() or ".." in relative.parts:
            raise ValueError(f"Unsafe manifest path: {relative}")
        data = (payload / relative).read_bytes()
        if len(data) != member["bytes"] or sha(data) != member["sha256"]:
            raise ValueError(f"Baseline hash mismatch: {relative}")
        baseline[relative.as_posix()] = member["sha256"]
    print(f"Verified {len(baseline)} baseline files; decoding images", flush=True)
    image_root = payload / "upgrade/Storage Card/System/Img"
    images = sorted(p for p in image_root.rglob("*")
                    if p.is_file() and p.suffix.lower() in {".bmp", ".png"})
    records = []
    for index, source in enumerate(images):
        raw = source.read_bytes()
        relative = source.relative_to(image_root)
        target = out / "assets" / f"{index:04}.png"
        target.parent.mkdir(parents=True, exist_ok=True)
        with Image.open(source) as image:
            image.load()
            width, height = image.size
            mode = image.mode
            # PNG copies preserve alpha; BMP conversion only changes viewer copies.
            image.convert("RGBA").save(target)
        with Image.open(target) as copy, Image.open(source) as original:
            if copy.convert("RGBA").tobytes() != original.convert("RGBA").tobytes():
                raise ValueError(f"Preview pixel mismatch: {source}")
        home_four = (len(relative.parts) == 3 and relative.parts[1] == "home"
                     and source.name in HOME_BUTTONS and (width, height) == (840, 137))
        records.append({
            "id": index, "path": relative.as_posix(), "name": source.name,
            "profile": relative.parts[0],
            "screen": relative.parts[1] if len(relative.parts) > 2 else "shared",
            "width": width, "height": height, "mode": mode,
            "bits": struct.unpack_from("<H", raw, 28)[0] if raw[:2] == b"BM" else None,
            "bytes": len(raw), "sha256": sha(raw),
            "url": f"assets/{index:04}.png", "knownFrames": 4 if home_four else 1,
            "frameEvidence": "AppMain horizontal button painter + home strip dimensions"
                if home_four else "Full image; frame count not mapped",
        })
    shutil.copyfile(ROOT / "tools/ui_theme_preview.html", out / "index.html")
    shutil.copyfile(ROOT / "tools/home_theme_preview.js", out / "home_theme_preview.js")
    shutil.copyfile(ROOT / "tools/av_theme_preview.js", out / "av_theme_preview.js")
    shutil.copyfile(ROOT / "tools/av_sprite_layout.mjs", out / "av_sprite_layout.mjs")
    concept_url = None
    if concept:
        with Image.open(concept) as image:
            image.load()
        shutil.copyfile(concept, out / "approved-concept.png")
        concept_url = "approved-concept.png"
    result = {
        "kind": "Read-only image-resource workbench, not a firmware emulator",
        "baseline": base.relative_to(ROOT).as_posix() if base.is_relative_to(ROOT) else str(base),
        "baselineManifestSha256": sha(manifest_bytes), "baselineMembers": len(baseline),
        "images": records, "profiles": dict(Counter(r["profile"] for r in records)),
        "concept": concept_url, "firmwareModified": False, "hardwareTested": False,
        "fullScreenLayoutsMapped": False,
        "verification": {"allBaselineHashesMatched": True,
                         "allPreviewPixelsMatched": True, "originalsUnchanged": True},
    }
    # Re-read every baseline file after generation to establish no source writes.
    for relative, digest in baseline.items():
        if sha((payload / relative).read_bytes()) != digest:
            raise ValueError(f"Baseline changed while building: {relative}")
    (out / "catalog.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    (out / "README.md").write_text(
        "# MediaNav image workbench\n\n"
        "Serve this directory on loopback with Python's http.server and open index.html. "
        "Original images are decoded to pixel-verified PNG viewer copies. "
        "The existing firmware payload is read and hash-checked, never modified.\n\n"
        "Only the six main home buttons have a mapped four-state split. "
        "Other frame splits are manual inspection aids. The approved concept is a design "
        "reference, not an executed firmware screen. No radio, Bluetooth, navigation, "
        "camera, touch callbacks or Windows CE code are executed.\n", encoding="utf-8")
    print(json.dumps({"output": str(out), "images": len(records),
                      "profiles": result["profiles"], "baseline_files_verified": len(baseline),
                      "preview_pixels_verified": len(records), "firmware_modified": False}, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--base", type=Path, default=DEFAULT_BASE)
    parser.add_argument("--out", type=Path, default=DEFAULT_OUT)
    parser.add_argument("--concept", type=Path)
    args = parser.parse_args()
    build(args.base.resolve(), args.out.resolve(), args.concept.resolve() if args.concept else None)
