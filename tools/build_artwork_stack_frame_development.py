"""Complete development payload with a compact album-art renderer stack frame."""
import argparse
import json
from pathlib import Path
from types import FunctionType, SimpleNamespace

import build_artwork_gdi_guards_development as prior
from patch_artwork_gdi_guards import patch as graphics_patch
from patch_artwork_stack_frame import patch
from verify_artwork_stack_frame import verify, retained_functions


def build(baseline, output):
    stage = {}

    def final_patch(previous):
        intermediate, graphics_recipe = graphics_patch(previous)
        candidate, recipe = patch(intermediate)
        stage.update(intermediate=intermediate, recipe=recipe)
        return candidate, dict(recipe, previous_graphics_recipe=graphics_recipe)

    def focused(previous, candidate, combined):
        current = verify(stage['intermediate'], candidate, stage['recipe'])
        retained, _ = retained_functions(stage['intermediate'], stage['recipe'])
        old = retained(previous, candidate, combined)
        return dict(cases=current['cases']+old['cases'], stack=current, graphics=old)

    def stages(*args):
        _, fn = retained_functions(stage['intermediate'], stage['recipe'])
        return fn(*args)

    sources = ('patch_artwork_stack_frame.py', 'verify_artwork_stack_frame.py',
               'build_artwork_stack_frame_development.py', 'test_artwork_stack_frame.py',
               'verify_artwork_stack_frame_retained.py')
    inner = SimpleNamespace(**dict(vars(prior.prior.prior),
                            SOURCE_NAMES=prior.prior.prior.SOURCE_NAMES+sources))
    proxy = SimpleNamespace(**dict(vars(prior.prior), prior=inner))
    fn = FunctionType(prior.build.__code__, dict(prior.build.__globals__,
                      patch=final_patch, verify=focused, retained_functions=stages,
                      prior=proxy), 'build_complete_stack_candidate')
    result = fn(baseline, output)
    result['kind'] = 'Complete MAX04 development payload with compact artwork stack; not an installable release'
    result['dependency_prs'] = list(range(26, 36))
    (output/'README.md').write_text(
        '# Album-art stack frame - development\n\n'
        '- All 1,918 MAX04 files retained; only MgrUSB changes.\n'
        '- Renderer frame: 3,864 to 216 bytes; 3,648 fewer reserved stack bytes.\n'
        '- Keeps ImageInfo, saved-register locations, GS cookie and preceding repairs.\n'
        f"- {result['cases']} cumulative written-instruction/API-fixture checks passed.\n"
        '- Native loader/unwind, hardware rendering and process memory remain unverified.\n', encoding='utf-8')
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
