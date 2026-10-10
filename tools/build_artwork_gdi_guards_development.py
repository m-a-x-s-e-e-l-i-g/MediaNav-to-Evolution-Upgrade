"""Complete development payload with checked album-art graphics ownership."""
import argparse
import json
from pathlib import Path
from types import FunctionType, SimpleNamespace

import build_artwork_draw_failure_development as prior
from patch_artwork_draw_failure import patch as draw_patch
from patch_artwork_gdi_guards import patch
from verify_artwork_gdi_guards import verify, retained_functions


def build(baseline, output):
    stage = {}

    def final_patch(previous):
        intermediate, draw_recipe = draw_patch(previous)
        candidate, recipe = patch(intermediate)
        stage.update(intermediate=intermediate, recipe=recipe)
        return candidate, dict(recipe, previous_draw_recipe=draw_recipe)

    def focused(previous, candidate, combined):
        current = verify(stage['intermediate'], candidate, stage['recipe'])
        retained, _ = retained_functions(stage['intermediate'], stage['recipe'])
        old = retained(previous, candidate, combined)
        return dict(cases=current['cases']+old['cases'], graphics=current, draw=old,
                    replaced_prior_fixture_cases=16,
                    replacement='Null context and initial-selection fixtures replaced by full stateful ownership matrix')

    def stages(*args):
        _, fn = retained_functions(stage['intermediate'], stage['recipe'])
        return fn(*args)

    extra_sources = ('patch_artwork_gdi_guards.py', 'verify_artwork_gdi_guards.py',
                     'build_artwork_gdi_guards_development.py', 'test_artwork_gdi_guards.py',
                     'verify_artwork_gdi_guards_retained.py')
    proxy = SimpleNamespace(**dict(vars(prior.prior),
                            SOURCE_NAMES=prior.prior.SOURCE_NAMES+extra_sources))
    fn = FunctionType(prior.build.__code__, dict(prior.build.__globals__,
                      patch=final_patch, verify=focused, retained_functions=stages,
                      prior=proxy), 'build_complete_gdi_candidate')
    result = fn(baseline, output)
    result['kind'] = 'Complete MAX04 development payload with checked graphics owner; not an installable release'
    result['dependency_prs'] = list(range(26, 35))
    (output/'README.md').write_text(
        '# Album-art graphics guards - development\n\n'
        '- All 1,918 MAX04 files retained; only MgrUSB changes.\n'
        '- Check context creation and initial bitmap selection before drawing.\n'
        '- Delete the DC before disposing a bitmap whose deselection failed.\n'
        '- Includes every preceding playback and artwork candidate.\n'
        f"- {result['cases']} cumulative written-instruction/API-fixture checks passed.\n"
        '- Native graphics, hardware rendering and performance remain unverified.\n', encoding='utf-8')
    (output/'manifest.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    result = build(args.baseline, args.out)
    print(json.dumps(dict(output_members=result['output_members'], cases=result['cases'],
                          sha256=result['recipe']['sha256'], hardware_tested=False), indent=2))
