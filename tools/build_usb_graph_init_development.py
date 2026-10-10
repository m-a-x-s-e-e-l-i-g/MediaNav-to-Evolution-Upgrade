"""Reproduce the full MAX04 payload with PR-26 state and failed-init cleanup."""
import argparse
import hashlib
import json
from pathlib import Path

from patch_usb_graph_state import patch as patch_state
from patch_usb_graph_init import patch, cumulative_recipe
from verify_usb_graph_state import verify as verify_state
from verify_usb_graph_init import verify
from release_payload import ROOT, PLAN, member, plan_at

USB = 'upgrade/Storage Card/System/MgrUSB.exe'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def build(baseline, output):
    baseline, output = baseline.resolve(), output.resolve()
    if output.exists():
        raise ValueError('Existing development output is never overwritten')
    if output.is_relative_to(baseline) or baseline.is_relative_to(output):
        raise ValueError('Input and output must be separate directories')
    plan = plan_at(PLAN)
    expected = {row['path']: row for row in plan['members']}
    actual = {p.relative_to(baseline).as_posix() for p in baseline.rglob('*') if p.is_file()}
    if actual != set(expected):
        raise ValueError('Full MAX04 inventory required; missing/extra files are refused')
    before = {}
    for path, row in expected.items():
        member(path)
        raw = (baseline/path).read_bytes()
        if (len(raw), sha(raw)) != (row['after_bytes'], row['after_sha256']):
            raise ValueError(f'Changed MAX04 input: {path}')
        before[path] = raw
    previous, state_recipe = patch_state(before[USB])
    candidate, recipe = patch(previous)
    output.mkdir(parents=True, exist_ok=False)
    payload = output/'payload'
    for path, raw in before.items():
        destination = payload/path
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(candidate if path == USB else raw)
    actual = {p.relative_to(payload).as_posix() for p in payload.rglob('*') if p.is_file()}
    if actual != set(expected):
        raise ValueError('Written inventory changed')
    members = []
    for path in sorted(expected):
        raw = (payload/path).read_bytes()
        if raw != (candidate if path == USB else before[path]):
            raise ValueError(f'Written payload mismatch: {path}')
        members.append(dict(path=path, bytes=len(raw), sha256=sha(raw), max04_sha256=expected[path]['after_sha256']))
    written = (payload/USB).read_bytes()
    print('All 1,918 members verified; checking failed-init instructions', flush=True)
    checks = verify(previous, written, recipe)
    print(f"Failed-init checks: {checks['cases']}; checking retained state transitions", flush=True)
    cumulative = cumulative_recipe(before[USB], written, state_recipe, recipe)
    retained = verify_state(before[USB], written, cumulative)
    print(f"Retained state-transition checks: {retained['cases']}", flush=True)
    sources = {name: sha((ROOT/'tools'/name).read_bytes()) for name in (
        'patch_usb_graph_init.py', 'verify_usb_graph_init.py', 'build_usb_graph_init_development.py',
        'patch_usb_graph_state.py', 'verify_usb_graph_state.py')}
    proof = dict(recipe=recipe, state_recipe=state_recipe, checks=checks, retained_graph_state=retained,
                 tools=sources, native_executed=False, hardware_tested=False, native_timing_measured=False)
    proof_raw = (json.dumps(proof, indent=2)+'\n').encode('utf-8')
    (output/'evidence.json').write_bytes(proof_raw)
    manifest = dict(kind='Complete MAX04-based development payload; not an installable release',
                    previous_release='7.0.6.MAX04', dependency_pr=26,
                    previous_lgu_sha256='94bb17ac6df670eb17927a7be627620a2a04cd2d64e92c042fb49c650a6187b0',
                    source_plan_sha256=sha(PLAN.read_bytes()), previous_members=len(expected),
                    output_members=len(members), missing_members=[], added_members=[],
                    changed_from_max04=[USB], unchanged_from_max04=len(members)-1,
                    members=members, tools=sources, recipe=recipe, state_recipe=state_recipe,
                    proof=dict(path='evidence.json', sha256=sha(proof_raw)),
                    cases=checks['cases']+retained['cases'], native_executed=False,
                    hardware_tested=False, native_timing_measured=False,
                    installation_ready=False, version_bumped=False, release_built=False)
    for path, raw in before.items():
        if (baseline/path).read_bytes() != raw:
            raise ValueError(f'Input changed during build: {path}')
    (output/'README.md').write_text(
        '# Failed USB graph initialization — development\n\n'
        '- Complete MAX04 payload: all 1,918 members retained; only MgrUSB changes.\n'
        '- Includes PR-26 state handling and cleanup after failed new acquisition.\n'
        f"- {manifest['cases']} instruction/API-fixture checks passed.\n"
        '- No LGU, version bump or device/performance validation.\n'
        '- See analysis/usb-graph-init-development.md, evidence.json and manifest.json.\n', encoding='utf-8')
    (output/'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n', encoding='utf-8')
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    result = build(args.baseline, args.out)
    print(json.dumps(dict(output_members=result['output_members'], cases=result['cases'],
                          sha256=result['recipe']['sha256'], hardware_tested=False), indent=2))


if __name__ == '__main__':
    main()
