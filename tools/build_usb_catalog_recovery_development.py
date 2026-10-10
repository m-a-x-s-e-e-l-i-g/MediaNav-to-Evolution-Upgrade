"""Complete MAX04 payload with bounded catalog storage recovery."""
import argparse
import json
from pathlib import Path
from types import FunctionType, SimpleNamespace

import build_usb_catalog_initialization_development as prior
from patch_usb_catalog_initialization import patch as catalog_patch
from patch_usb_catalog_recovery import patch
from verify_usb_catalog_recovery import verify, retained_functions


def build(baseline, output):
    stage = {}
    def final_patch(previous):
        intermediate, catalog_recipe = catalog_patch(previous)
        candidate, recipe = patch(intermediate)
        stage.update(intermediate=intermediate, recipe=recipe)
        return candidate, dict(recipe, previous_catalog_recipe=catalog_recipe)
    def focused(previous, candidate, combined):
        current = verify(stage['intermediate'], candidate, stage['recipe'])
        old, _ = retained_functions(stage['intermediate'], stage['recipe'])
        retained = old(previous, candidate, combined)
        return dict(cases=current['cases']+retained['cases'], recovery=current, catalog=retained)
    def stages(*args):
        _, fn = retained_functions(stage['intermediate'], stage['recipe'])
        return fn(*args)
    names = ('patch_usb_catalog_recovery.py', 'verify_usb_catalog_recovery.py',
             'build_usb_catalog_recovery_development.py', 'test_usb_catalog_recovery.py',
             'verify_usb_catalog_recovery_retained.py', 'verify_usb_catalog_readiness.py')
    chain, module = [], prior
    while hasattr(module, 'prior'):
        module = module.prior
        chain.append(module)
    core = chain[-1]
    def graph_recipe(original, candidate, state_recipe, remaining):
        extra = dict(remaining, added_pdata_rows=remaining['added_pdata_rows']+stage['recipe']['added_pdata_rows'])
        return core.cumulative_recipe(original, candidate, state_recipe, extra)
    core_build = FunctionType(core.build.__code__, dict(core.build.__globals__,
                              cumulative_recipe=graph_recipe), 'build_recovery_graph_recipe')
    proxy = SimpleNamespace(**dict(vars(core), SOURCE_NAMES=core.SOURCE_NAMES+names,
                                   build=core_build, cumulative_recipe=graph_recipe))
    for module in reversed(chain[:-1]):
        proxy = SimpleNamespace(**dict(vars(module), prior=proxy))
    fn = FunctionType(prior.build.__code__, dict(prior.build.__globals__, patch=final_patch,
        verify=focused, retained_functions=stages, prior=proxy), 'build_complete_catalog_recovery')
    result = fn(baseline, output)
    result['kind'] = 'Complete MAX04 development payload with bounded catalog recovery; not an installable release'
    result['dependency_prs'] = list(range(26, 40))
    (output/'README.md').write_text('# USB catalog recovery - development\n\n'
        '- All 1,918 MAX04 members retained; only MgrUSB changes.\n'
        '- Retry missing required catalog buffers, retain successful allocations and bound attempts.\n'
        '- Check storage and cancellation before root insertion; preserve existing unavailable-media routing.\n'
        f"- {result['cases']} cumulative instruction/API-fixture checks passed.\n"
        '- Native concurrency, UI delivery and device behavior remain unverified.\n', encoding='utf-8')
    (output/'manifest.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', required=True, type=Path)
    parser.add_argument('--out', required=True, type=Path)
    args = parser.parse_args()
    result = build(args.baseline, args.out)
    print(json.dumps(dict(output_members=result['output_members'], cases=result['cases'], sha256=result['recipe']['sha256'])))
