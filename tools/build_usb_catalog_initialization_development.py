"""Complete MAX04 development payload with initialized catalog reset pointer."""
import argparse
import json
from pathlib import Path
from types import FunctionType, SimpleNamespace

import build_usb_metadata_copies_development as prior
from patch_usb_metadata_copies import patch as metadata_patch
from patch_usb_catalog_initialization import patch
from verify_usb_catalog_initialization import verify, retained_functions


def build(baseline, output):
    stage = {}

    def final_patch(previous):
        intermediate, metadata_recipe = metadata_patch(previous)
        candidate, recipe = patch(intermediate)
        stage.update(intermediate=intermediate, recipe=recipe)
        return candidate, dict(recipe, previous_metadata_recipe=metadata_recipe)

    def focused(previous, candidate, combined):
        current = verify(stage['intermediate'], candidate, stage['recipe'])
        old, _ = retained_functions(stage['intermediate'], stage['recipe'])
        retained = old(previous, candidate, combined)
        return dict(cases=current['cases']+retained['cases'], catalog=current, metadata=retained)

    def stages(*args):
        _, fn = retained_functions(stage['intermediate'], stage['recipe'])
        return fn(*args)

    names = ('patch_usb_catalog_initialization.py', 'verify_usb_catalog_initialization.py',
             'build_usb_catalog_initialization_development.py', 'test_usb_catalog_initialization.py',
             'verify_usb_catalog_initialization_retained.py')
    event = SimpleNamespace(**dict(vars(prior.prior.prior.prior.prior),
                                   SOURCE_NAMES=prior.prior.prior.prior.prior.SOURCE_NAMES+names))
    draw = SimpleNamespace(**dict(vars(prior.prior.prior.prior), prior=event))
    graphics = SimpleNamespace(**dict(vars(prior.prior.prior), prior=draw))
    stack = SimpleNamespace(**dict(vars(prior.prior), prior=graphics))
    fn = FunctionType(prior.build.__code__, dict(prior.build.__globals__,
                      patch=final_patch, verify=focused, retained_functions=stages,
                      prior=stack), 'build_complete_catalog_candidate')
    result = fn(baseline, output)
    result['kind'] = 'Complete MAX04 development payload with initialized catalog pointer; not an installable release'
    result['dependency_prs'] = list(range(26, 38))
    (output/'README.md').write_text(
        '# USB catalog initialization - development\n\n'
        '- All 1,918 MAX04 members retained; only MgrUSB changes.\n'
        '- Initialize the directory pointer before the constructor resets its buffers.\n'
        '- Removes a 2,720,000-byte clear through a reused-memory pointer in fixtures.\n'
        f"- {result['cases']} cumulative written-instruction/API-fixture checks passed.\n"
        '- Partial-catalog scan readiness and native heap behavior remain unresolved.\n', encoding='utf-8')
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
