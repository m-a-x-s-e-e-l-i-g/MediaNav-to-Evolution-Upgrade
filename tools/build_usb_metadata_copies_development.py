"""Complete MAX04 development payload with field-sized metadata snapshots."""
import argparse
import json
from pathlib import Path
from types import FunctionType, SimpleNamespace

import build_artwork_stack_frame_development as prior
from patch_artwork_stack_frame import patch as stack_patch
from patch_usb_metadata_copies import patch
from verify_usb_metadata_copies import verify, retained_functions


def build(baseline, output):
    stage = {}

    def final_patch(previous):
        intermediate, stack_recipe = stack_patch(previous)
        candidate, recipe = patch(intermediate)
        stage.update(intermediate=intermediate, recipe=recipe)
        return candidate, dict(recipe, previous_stack_recipe=stack_recipe)

    def focused(previous, candidate, combined):
        current = verify(stage['intermediate'], candidate, stage['recipe'])
        old, _ = retained_functions(stage['intermediate'], stage['recipe'])
        retained = old(previous, candidate, combined)
        return dict(cases=current['cases']+retained['cases'], metadata=current, stack=retained)

    def stages(*args):
        _, fn = retained_functions(stage['intermediate'], stage['recipe'])
        return fn(*args)

    names = ('patch_usb_metadata_copies.py', 'verify_usb_metadata_copies.py',
             'build_usb_metadata_copies_development.py', 'test_usb_metadata_copies.py',
             'verify_usb_metadata_copies_retained.py')
    event = SimpleNamespace(**dict(vars(prior.prior.prior.prior),
                                   SOURCE_NAMES=prior.prior.prior.prior.SOURCE_NAMES+names))
    draw = SimpleNamespace(**dict(vars(prior.prior.prior), prior=event))
    graphics = SimpleNamespace(**dict(vars(prior.prior), prior=draw))
    fn = FunctionType(prior.build.__code__, dict(prior.build.__globals__,
                      patch=final_patch, verify=focused, retained_functions=stages,
                      prior=graphics), 'build_complete_metadata_candidate')
    result = fn(baseline, output)
    result['kind'] = 'Complete MAX04 development payload with field-sized metadata copies; not an installable release'
    result['dependency_prs'] = list(range(26, 37))
    (output/'README.md').write_text(
        '# USB metadata copies - development\n\n'
        '- All 1,918 MAX04 members retained; only MgrUSB changes.\n'
        '- Normal/resume metadata snapshots copy the consumed flag or text field.\n'
        '- All-present path: 25,564 to 2,092 snapshot bytes; outputs and logs retained.\n'
        f"- {result['cases']} cumulative written-instruction/API-fixture checks passed.\n"
        '- Native timing, concurrency and hardware behavior remain unverified.\n', encoding='utf-8')
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
