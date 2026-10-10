"""Build a complete MAX04-based development payload and verify written graph bytes.

No firmware is executed natively; no LGU, version change or public release.
"""
import argparse
import hashlib
import json
from pathlib import Path

from patch_usb_graph_state import patch
from release_payload import ROOT, PLAN, member, plan_at
from verify_usb_graph_state import verify

USB = "upgrade/Storage Card/System/MgrUSB.exe"


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def build(baseline, output):
    baseline, output = baseline.resolve(), output.resolve()
    if output.exists():
        raise ValueError("Existing development output is never overwritten")
    if output.is_relative_to(baseline) or baseline.is_relative_to(output):
        raise ValueError("Input and output must be separate directories")
    plan = plan_at(PLAN)
    expected = {row["path"]: row for row in plan["members"]}
    actual = {p.relative_to(baseline).as_posix() for p in baseline.rglob("*") if p.is_file()}
    if actual != set(expected):
        raise ValueError("Full MAX04 inventory required; missing/extra files are refused")
    before = {}
    for path, row in expected.items():
        member(path)
        raw = (baseline/path).read_bytes()
        if (len(raw), sha(raw)) != (row["after_bytes"], row["after_sha256"]):
            raise ValueError(f"Changed MAX04 input: {path}")
        before[path] = raw
    candidate, recipe = patch(before[USB])
    output.mkdir(parents=True, exist_ok=False)
    payload = output/"payload"
    for path, raw in before.items():
        destination = payload/path
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(candidate if path == USB else raw)
    actual = {p.relative_to(payload).as_posix() for p in payload.rglob("*") if p.is_file()}
    if actual != set(expected):
        raise ValueError("Written payload inventory changed")
    members = []
    for path in sorted(expected):
        raw = (payload/path).read_bytes()
        target = candidate if path == USB else before[path]
        if raw != target:
            raise ValueError(f"Written payload mismatch: {path}")
        members.append(dict(path=path, bytes=len(raw), sha256=sha(raw),
                            max04_sha256=expected[path]["after_sha256"]))
    print("All 1,918 members written and verified; checking written graph instructions", flush=True)
    checks = verify(before[USB], (payload/USB).read_bytes(), recipe)
    sources = {name:sha((ROOT/"tools"/name).read_bytes()) for name in (
        "patch_usb_graph_state.py", "verify_usb_graph_state.py", "build_usb_graph_state_development.py")}
    proof = dict(recipe=recipe, checks=checks, tools=sources,
                 native_executed=False, hardware_tested=False, native_timing_measured=False)
    proof_raw = (json.dumps(proof, indent=2)+"\n").encode("utf-8")
    (output/"evidence.json").write_bytes(proof_raw)
    manifest = dict(kind="Complete MAX04-based development payload; not an installable release",
                    previous_release="7.0.6.MAX04", previous_lgu_sha256="94bb17ac6df670eb17927a7be627620a2a04cd2d64e92c042fb49c650a6187b0",
                    source_plan_sha256=sha(PLAN.read_bytes()), previous_members=len(expected),
                    output_members=len(members), missing_members=[], added_members=[],
                    changed_from_max04=[USB], unchanged_from_max04=len(members)-1,
                    members=members, tools=sources, recipe=recipe,
                    proof=dict(path="evidence.json",sha256=sha(proof_raw)), cases=checks["cases"],
                    native_executed=False, hardware_tested=False, native_timing_measured=False,
                    installation_ready=False, version_bumped=False, release_built=False)
    # Recheck inputs, then write completion metadata last. Failed attempts remain
    # incomplete outputs and must never be mistaken for a verified build.
    for path, raw in before.items():
        if (baseline/path).read_bytes() != raw:
            raise ValueError(f"Input changed during build: {path}")
    (output/"README.md").write_text(
        "# USB graph-state development\n\n"
        "- Complete MAX04 payload: all 1,918 members retained; only MgrUSB changes.\n"
        "- Checked, nonblocking state polling; failures skip dependent seek, notification, teardown and replacement work.\n"
        f"- {checks['cases']} instruction/API-fixture checks passed.\n"
        "- No LGU, version bump, native timing measurement or device validation.\n"
        "- See analysis/usb-graph-state-development.md, evidence.json and manifest.json.\n",
        encoding="utf-8")
    (output/"manifest.json").write_text(json.dumps(manifest,indent=2)+"\n",encoding="utf-8")
    return dict(output=str(output),members=len(members),cases=checks['cases'],
                candidate_sha256=sha(candidate),release_built=False)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline',type=Path,required=True,help='Verified complete MAX04 payload directory')
    parser.add_argument('--out',type=Path,required=True,help='Fresh development directory')
    args=parser.parse_args()
    print(json.dumps(build(args.baseline,args.out),indent=2))


if __name__=='__main__':main()
