"""Stage the complete previous release with English UI edits; no LGU/release/flash."""
import json
from datetime import datetime, timezone
from pathlib import Path
from patch_ui_english import patch, LABELS, sha
from verify_ui_english import verify

ROOT = Path(__file__).resolve().parents[1]
PREVIOUS = ROOT / "sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade"
BASE = ROOT / "build/maxmade-7.0.6.MAX03/roundtrip"
SYSTEM = "upgrade/Storage Card/System/"


def main():
    out = ROOT / "build/ui-english-development-01"
    assert not out.exists(), "Existing development staging is never overwritten"
    manifest = json.loads((PREVIOUS / "build-manifest.json").read_text(encoding="utf-8"))
    assert sha((PREVIOUS / "upgrade.lgu").read_bytes()) == manifest["verification"]["lgu_sha256"]
    members = manifest["verification"]["members"]
    assert len(members) == 1918
    before = {}
    for item in members:
        name = item["path"]
        assert name.startswith("upgrade/") and ".." not in Path(name).parts
        raw = (BASE / name).read_bytes()
        assert len(raw) == item["bytes"] and sha(raw) == item["sha256"], name
        before[name] = raw
    assert set(before) == {p.relative_to(BASE).as_posix() for p in BASE.rglob("*") if p.is_file()}
    originals = {name: before[SYSTEM + name] for name in LABELS}
    changed, recipes = {}, []
    for name, raw in originals.items():
        changed[name], recipe = patch(name, raw)
        recipes.append(recipe)
    # Verify before creating any output, then verify read-back too.
    checks = verify(originals, changed)
    for name, raw in before.items():
        destination = out / "payload" / name
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(changed.get(name.removeprefix(SYSTEM), raw) if name.startswith(SYSTEM) else raw)
    after = {p.relative_to(out / "payload").as_posix(): p.read_bytes()
             for p in (out / "payload").rglob("*") if p.is_file()}
    assert set(after) == set(before), "Every previous release member must remain present"
    modified = [name for name in before if before[name] != after[name]]
    assert set(modified) == {SYSTEM + name for name in LABELS}
    readback = {name: after[SYSTEM + name] for name in LABELS}
    assert verify(originals, readback) == checks
    rows = [dict(path=name, bytes=len(after[name]), previous_sha256=sha(before[name]),
                 sha256=sha(after[name]), changed=name in modified) for name in sorted(before)]
    result = dict(generated_utc=datetime.now(timezone.utc).isoformat(),
                  kind="Development staging, not a release or installable update",
                  previous_release="7.0.6.MAX03", previous_lgu_sha256=sha((PREVIOUS / "upgrade.lgu").read_bytes()),
                  previous_members=len(before), output_members=len(after),
                  missing_members=[], added_members=[], modified_members=modified,
                  unchanged_members=len(before) - len(modified), edits=recipes, checks=checks,
                  release_built=False, version_bumped=False, firmware_executed=False,
                  members=rows)
    (out / "manifest.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    (out / "README.md").write_text(
        "# English UI development staging\n\n"
        "Complete 7.0.6.MAX03 payload with four English UI development candidates. "
        "All 1,918 previous members remain; 1,914 files are unchanged.\n\n"
        "No LGU, ZIP release or new version has been made. Do not copy the payload "
        "onto the unit as a release. A future full release needs its new version, "
        "container verification and independent extraction.\n\n"
        "Updater text uses the existing English language DLL, including left-to-right "
        "drawing. DBoot menu/reboot prompts, diagnostic messages and generated desktop "
        "shortcut names use English. Existing old shortcut aliases may persist; native "
        "display and update-stage coverage still need checking.\n", encoding="utf-8")
    assert sha((PREVIOUS / "upgrade.lgu").read_bytes()) == result["previous_lgu_sha256"]
    print(json.dumps({k: result[k] for k in ("previous_members", "output_members", "unchanged_members",
                                            "modified_members", "checks", "release_built")}, indent=2))


if __name__ == "__main__":
    main()
