"""Check published source hashes, release inventory, Python syntax and local links."""
import ast
import hashlib
import json
from pathlib import Path
import re
from urllib.parse import unquote, urlsplit
from release_payload import ROOT, PLAN, plan_at


def main():
    manifest = json.loads((ROOT / "docs/publication-manifest.json").read_bytes())
    for row in manifest["files"]:
        path = ROOT / row["path"]
        raw = path.read_bytes()
        if len(raw) != row["bytes"] or hashlib.sha256(raw).hexdigest() != row["sha256"]:
            raise ValueError(f"Published evidence/source changed: {row['path']}")
    scripts = list((ROOT / "tools").glob("*.py"))
    for path in scripts:
        ast.parse(path.read_text(encoding="utf-8"), filename=str(path), feature_version=(3, 12))
    plan = plan_at(PLAN)
    release = json.loads((ROOT / "releases/7.0.6.MAX04/build-manifest.json").read_bytes())
    expected = {r["path"]: r for r in release["verification"]["members"]}
    if len(plan["members"]) != 1918 or len(plan["changes"]) != 279:
        raise ValueError("MAX04 complete-release inventory changed")
    for row in plan["members"]:
        recorded = expected[row["path"]]
        if (recorded["bytes"], recorded["sha256"]) != (row["after_bytes"], row["after_sha256"]):
            raise ValueError(f"Release recipe mismatch: {row['path']}")
    for change in plan["changes"]:
        if "asset" in change:
            raw = (ROOT / change["asset"]).read_bytes()
            if hashlib.sha256(raw).hexdigest() != expected[change["path"]]["sha256"]:
                raise ValueError(f"Artwork changed: {change['asset']}")
    # Historical research notes retain original local artifact references. Check active docs.
    docs = [ROOT / "README.md", ROOT / "CONTRIBUTING.md", ROOT / "tools/README.md",
            ROOT / "analysis/README.md", ROOT / "src/README.md"]
    docs += list((ROOT / "docs").glob("*.md"))
    docs += list((ROOT / "releases").glob("*/README.md"))
    links = 0
    for path in docs:
        for match in re.finditer(r"\]\(([^\s)]+)(?:\s+\"[^\"]*\")?\)", path.read_text(encoding="utf-8")):
            url = urlsplit(match[1].strip("<>"))
            if url.scheme or not url.path:
                continue
            target = path.parent / unquote(url.path)
            if not target.exists():
                raise ValueError(f"Broken link in {path.relative_to(ROOT)}: {match[1]}")
            links += 1
    forbidden = {".lgu", ".exe", ".dll", ".zip", ".pyc"}
    for row in manifest["files"]:
        if Path(row["path"]).suffix.lower() in forbidden:
            raise ValueError(f"Unexpected binary in publication: {row['path']}")
    print(json.dumps({"source_and_evidence_hashes": len(manifest["files"]),
                      "python_syntax": len(scripts), "active_document_links": links,
                      "release_members": len(expected), "release_changes": len(plan["changes"])}, indent=2))


if __name__ == "__main__":
    main()
