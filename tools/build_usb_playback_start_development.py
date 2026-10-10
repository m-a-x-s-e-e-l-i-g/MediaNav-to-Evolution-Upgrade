"""Full MAX04 development payload with checked ordinary playback start failures."""
import argparse
import hashlib
import json
from pathlib import Path

from patch_usb_graph_state import patch as patch_state
from patch_usb_graph_init import patch as patch_init, cumulative_recipe
from patch_usb_seek_timing import patch as patch_timing
from patch_usb_seek_completion import patch as patch_completion
from patch_usb_playback_start import patch
from verify_usb_graph_state import verify as verify_state
from verify_usb_playback_start import verify, retained
from release_payload import ROOT, PLAN, member, plan_at

USB = 'upgrade/Storage Card/System/MgrUSB.exe'
SOURCE_NAMES = (
    'patch_usb_playback_start.py', 'verify_usb_playback_start.py', 'build_usb_playback_start_development.py',
    'patch_usb_seek_completion.py', 'verify_usb_seek_completion.py',
    'patch_usb_seek_timing.py', 'verify_usb_seek_timing.py',
    'patch_usb_graph_init.py', 'verify_usb_graph_init.py', 'patch_usb_graph_state.py', 'verify_usb_graph_state.py')


def sha(raw): return hashlib.sha256(raw).hexdigest()


def build(baseline, output):
    baseline, output = baseline.resolve(), output.resolve()
    if output.exists(): raise ValueError('Existing development output is never overwritten')
    if output.is_relative_to(baseline) or baseline.is_relative_to(output):
        raise ValueError('Input and output must be separate directories')
    sources = {name: sha((ROOT/'tools'/name).read_bytes()) for name in SOURCE_NAMES}
    expected = {r['path']: r for r in plan_at(PLAN)['members']}
    actual = {p.relative_to(baseline).as_posix() for p in baseline.rglob('*') if p.is_file()}
    if actual != set(expected): raise ValueError('Full MAX04 inventory required; missing/extra files are refused')
    before = {}
    for path, row in expected.items():
        member(path); raw = (baseline/path).read_bytes()
        if (len(raw), sha(raw)) != (row['after_bytes'], row['after_sha256']):
            raise ValueError('Changed MAX04 input: '+path)
        before[path] = raw
    state, state_recipe = patch_state(before[USB])
    initialization, init_recipe = patch_init(state)
    timing, timing_recipe = patch_timing(initialization)
    completion, completion_recipe = patch_completion(timing)
    candidate, recipe = patch(completion)
    output.mkdir(parents=True, exist_ok=False)
    payload = output/'payload'
    for path, raw in before.items():
        destination = payload/path; destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(candidate if path == USB else raw)
    actual = {p.relative_to(payload).as_posix() for p in payload.rglob('*') if p.is_file()}
    if actual != set(expected): raise ValueError('Written inventory changed')
    members = []
    for path in sorted(expected):
        raw = (payload/path).read_bytes()
        if raw != (candidate if path == USB else before[path]): raise ValueError('Written payload mismatch: '+path)
        members.append(dict(path=path, bytes=len(raw), sha256=sha(raw), max04_sha256=expected[path]['after_sha256']))
    written = (payload/USB).read_bytes()
    print('All 1,918 members verified; checking playback-start instructions', flush=True)
    checks = verify(completion, written, recipe)
    print(f"Playback-start checks: {checks['cases']}", flush=True)
    suites = retained(state, initialization, timing, completion, written,
                      init_recipe, timing_recipe, completion_recipe, recipe)
    cumulative = cumulative_recipe(before[USB], written, state_recipe,
        dict(added_pdata_rows=init_recipe['added_pdata_rows']+timing_recipe['added_pdata_rows']+
             completion_recipe['added_pdata_rows']+recipe['added_pdata_rows']))
    print('Retained USB graph state', flush=True)
    suites['graph_state'] = verify_state(before[USB], written, cumulative)
    for name, result in suites.items(): print(f"Retained {name}: {result['cases']}", flush=True)
    if sources != {name: sha((ROOT/'tools'/name).read_bytes()) for name in SOURCE_NAMES}:
        raise ValueError('Source changed during verification')
    cases = checks['cases']+sum(result['cases'] for result in suites.values())
    recipes = dict(recipe=recipe, state_recipe=state_recipe, initialization_recipe=init_recipe,
                   timing_recipe=timing_recipe, completion_recipe=completion_recipe)
    proof = dict(**recipes, checks=checks, retained=suites, tools=sources,
                 native_executed=False, hardware_tested=False, native_timing_measured=False)
    proof_raw = (json.dumps(proof, indent=2)+'\n').encode('utf-8')
    (output/'evidence.json').write_bytes(proof_raw)
    manifest = dict(kind='Complete MAX04-based development payload; not an installable release',
                    previous_release='7.0.6.MAX04', dependency_prs=[26, 27, 28, 29],
                    previous_lgu_sha256='94bb17ac6df670eb17927a7be627620a2a04cd2d64e92c042fb49c650a6187b0',
                    source_plan_sha256=sha(PLAN.read_bytes()), previous_members=len(expected),
                    output_members=len(members), missing_members=[], added_members=[],
                    changed_from_max04=[USB], unchanged_from_max04=len(members)-1,
                    members=members, tools=sources, **recipes,
                    proof=dict(path='evidence.json', sha256=sha(proof_raw)), cases=cases,
                    native_executed=False, hardware_tested=False, native_timing_measured=False,
                    installation_ready=False, version_bumped=False, release_built=False)
    for path, raw in before.items():
        if (baseline/path).read_bytes() != raw: raise ValueError('Input changed during build: '+path)
    if (payload/USB).read_bytes() != written: raise ValueError('Candidate changed during verification')
    (output/'README.md').write_text(
        '# USB playback start - development\n\n'
        '- Complete MAX04 payload: all 1,918 members retained; only MgrUSB changes.\n'
        '- Includes graph-state, initialization, timing and seek-completion candidates.\n'
        f'- {cases} instruction/API-fixture checks passed.\n'
        '- No LGU, version bump or device/performance validation.\n'
        '- See analysis/usb-playback-start-development.md, evidence.json and manifest.json.\n', encoding='utf-8')
    (output/'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n', encoding='utf-8')
    return manifest


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    result = build(args.baseline, args.out)
    print(json.dumps(dict(output_members=result['output_members'], cases=result['cases'],
                          sha256=result['recipe']['sha256'], hardware_tested=False), indent=2))
