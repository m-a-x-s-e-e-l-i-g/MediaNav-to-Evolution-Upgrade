"""Complete MAX04-based development payload with checked artwork draw failure."""
import argparse
import json
from pathlib import Path
from types import FunctionType

import build_usb_completion_event_development as prior
from patch_usb_completion_event import patch as event_patch
from patch_artwork_draw_failure import patch
from verify_artwork_draw_failure import verify, retained_functions


def build(baseline, output):
    stage = {}

    def final_patch(duration):
        intermediate, event_recipe = event_patch(duration)
        candidate, draw_recipe = patch(intermediate)
        stage.update(duration=duration, intermediate=intermediate,
                     event_recipe=event_recipe, draw_recipe=draw_recipe)
        # The cumulative builder still needs the event's exception rows, which
        # this in-place renderer patch leaves unchanged.
        return candidate, dict(draw_recipe, completion_event_recipe=event_recipe,
                               added_pdata_rows=event_recipe['added_pdata_rows'])

    def checks(duration, candidate, recipe):
        focus = verify(stage['intermediate'], candidate, stage['draw_recipe'])
        event_verify, _, _ = retained_functions(duration, stage['intermediate'],
                                                stage['event_recipe'], stage['draw_recipe'])
        events = event_verify(duration, candidate, stage['event_recipe'])
        return dict(cases=focus['cases']+events['cases'], artwork=focus, completion_event=events)

    def retained(*args):
        _, fn, _ = retained_functions(stage['duration'], stage['intermediate'],
                                      stage['event_recipe'], stage['draw_recipe'])
        # Last argument belongs to the event stage; draw edits are checked by
        # the isolated cumulative structure function above.
        return fn(*args[:-1], stage['event_recipe'])

    source_names = prior.SOURCE_NAMES + (
        'inspect_artwork_render_failures.py', 'patch_artwork_draw_failure.py',
        'verify_artwork_draw_failure.py', 'build_artwork_draw_failure_development.py',
        'test_artwork_draw_failure.py')
    fn = FunctionType(prior.build.__code__, dict(prior.build.__globals__,
                      patch=final_patch, verify=checks, retained=retained,
                      SOURCE_NAMES=source_names), 'build_complete_artwork_candidate')
    result = fn(baseline, output)
    result['kind'] = 'Complete MAX04 development payload with checked album draw; not an installable release'
    result['dependency_prs'] = list(range(26, 34))
    (output/'README.md').write_text(
        '# Album-art draw failure - development\n\n'
        '- Complete MAX04 payload: all 1,918 members retained; only MgrUSB changes.\n'
        '- Includes preceding graph, playback, duration and completion-event repairs.\n'
        '- Failed image draws release the temporary bitmap and use the existing no-artwork fallback.\n'
        f"- {result['cases']} written-instruction and API-fixture checks passed.\n"
        '- No LGU, version bump, device validation or measured native speed claim.\n', encoding='utf-8')
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
