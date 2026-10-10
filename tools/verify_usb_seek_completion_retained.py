"""Rerun historical USB suites with pinned local inputs and corrected resume fixture.

Requires the original ignored historical workspace; not part of CI. Historical
sources stay byte-for-byte intact. No native Windows CE or codec execution.
"""
import argparse
import ast
import hashlib
import inspect
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
REFERENCE = ROOT/'analysis/firmware/usb-seek-timing-retained.json'


def sha(raw): return hashlib.sha256(raw).hexdigest()


def cases(value):
    if not isinstance(value, dict): return 0
    if 'cases' in value: return value['cases']
    return sum(cases(v) for v in value.values())


def run(workspace, candidate_path, report):
    workspace, candidate_path, report = workspace.resolve(), candidate_path.resolve(), report.resolve()
    if report.exists(): raise ValueError('Existing evidence is never overwritten')
    reference = json.loads(REFERENCE.read_bytes())
    sources = reference['legacy_python_sources']
    for path, expected in sources.items():
        if sha((workspace/path).read_bytes()) != expected:
            raise ValueError('Changed historical source: '+path)
    for row in reference['baseline_inputs']:
        manifest = ROOT/row['manifest']
        if sha(manifest.read_bytes()) != row['manifest_sha256']:
            raise ValueError('Changed historical input manifest')
        if sha((workspace/'build'/row['stage']/'payload'/row['member']).read_bytes()) != row['sha256']:
            raise ValueError('Changed historical input: '+row['stage'])
    candidate = candidate_path.read_bytes()
    # Import historical fixtures first so their embedded input paths remain
    # accurate. New routines then load from this repository's tools directory.
    sys.path.insert(0, str(workspace/'tools'))
    import verify_usb_status_retained as prior
    import verify_artwork_playlist as artwork
    from verify_usb_save_feedback import verify as saves
    from verify_usb_resume_modes import verify as modes
    from verify_usb_folders import verify as folders, retained_sorting
    from verify_wma_shuffle_v2 import verify as wma
    from verify_usb_seek_completion import retained_resume_identity

    # Replace only the explicit old resume callback in an isolated function.
    # Its substitute SetPosition returned zero for success. The replacement
    # retains those same 25 scenarios and executes actual setter instructions.
    tree = ast.parse(inspect.getsource(artwork.regressions))
    replacements = 0
    for node in ast.walk(tree):
        if (isinstance(node, ast.Call) and isinstance(node.func, ast.Attribute) and
                isinstance(node.func.value, ast.Name) and node.func.value.id == 'previous' and
                node.func.attr == 'verify_usb'):
            node.func = ast.Name(id='retained_resume_identity', ctx=ast.Load()); replacements += 1
    if replacements != 1: raise ValueError('Historical resume callback changed')
    ast.fix_missing_locations(tree)
    namespace = dict(artwork.regressions.__globals__, retained_resume_identity=retained_resume_identity)
    exec(compile(tree, '<isolated historical regression callbacks>', 'exec'), namespace)
    regressions = namespace['regressions']
    suites = {}
    with prior.mutex_fixtures():
        for name, fn in (('saves', saves), ('modes', modes), ('folders', folders),
                         ('sorting', retained_sorting), ('wma', wma),
                         ('artwork', artwork.verify), ('earlier', regressions)):
            print('Retained USB '+name, flush=True); suites[name] = fn(candidate)
    for path, expected in sources.items():
        if sha((workspace/path).read_bytes()) != expected:
            raise ValueError('Historical source changed during verification: '+path)
    if candidate_path.read_bytes() != candidate: raise ValueError('Candidate changed during verification')
    result = dict(candidate_sha256=sha(candidate), cases=sum(cases(s) for s in suites.values()),
                  suites=suites, baseline_inputs=reference['baseline_inputs'], legacy_python_sources=sources,
                  corrected_resume_cases=25, native_executed=False, hardware_tested=False,
                  limits='Historical instruction/API suites using checked local inputs; 25 resume cases now execute actual seek instructions. No native or device testing.')
    report.parent.mkdir(parents=True, exist_ok=True)
    with report.open('x', encoding='utf-8', newline='\n') as output:
        output.write(json.dumps(result, indent=2)+'\n')
    print(json.dumps(dict(cases=result['cases'], candidate_sha256=result['candidate_sha256']), indent=2))
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--historical-workspace', type=Path, required=True)
    parser.add_argument('--candidate', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    run(args.historical_workspace, args.candidate, args.report)
