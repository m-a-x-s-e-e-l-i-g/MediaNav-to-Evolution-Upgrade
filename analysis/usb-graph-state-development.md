# USB playback state — development candidate

Based on the complete **7.0.6.MAX04** payload. This candidate is for review and later device testing; it is not a new release.

## Problem

- Stop, RealPause and Pause call `IMediaControl::GetState(INFINITE)` and ignore its HRESULT. An individual call can block even though the surrounding loop has an iteration limit.
- Stop can report success and cache stopped state after reaching that limit without observing a stopped graph.
- Teardown ignores Stop's result. RenderFile then ignores teardown's result before initializing a replacement graph.
- Seek and notification callers also continue after failed state transitions.

The verifier reproduces these behaviors using original MAX04 MIPS instructions and simulated COM responses. Their frequency on a real unit is unknown.

## Changes

- Poll with `GetState(0)`, a wrap-safe 5,000-ms deadline and a separate 1,001-poll limit for a stalled clock.
- Check failed, pending, completed and cannot-cue results. A pending result's output is a target state, not proof of completion.
- Initialize each state output before the call; reject missing/invalid output and changed control pointers.
- Request Pause/Stop once per observed state, avoiding repeated commands while waiting for a transition.
- Preserve the two existing pause behaviors: RealPause accepts paused/stopped; ordinary Pause waits for stopped but retains the original paused UI state.
- Update cached state and reset Stop's position only after confirmed completion. Completed states return without the old extra sleep or per-poll logging.
- Failed transitions skip dependent seek work, timer setup, position updates and Stop completion notification.
- Failed teardown retains interface pointers and the graph flag. RenderFile refuses replacement; detach skips subsequent save/completion work.
- Write one debug diagnostic on a transition failure.

API references: [GetState](https://learn.microsoft.com/en-us/windows/win32/api/control/nf-control-imediacontrol-getstate), [HRESULT values](https://learn.microsoft.com/en-us/windows/win32/directshow/error-and-success-codes).

## Evidence

- [Instruction report](firmware/usb-graph-state-development.json): **378 cases**, including five original-defect reproductions, completed/pending/failed transitions, frozen clocks, tick wraparound, absent/replaced interfaces, caller failure gates and three alternate load addresses.
- [Retained USB checks](firmware/usb-graph-state-retained.json): **72,212 passing cases** for save/resume settings, folders, sorting, WMA/shuffle, artwork, playlists and earlier input/encoding behavior. Historical inputs match the published stage manifests; 224 legacy Python source snapshots were hash-checked.
- [Complete member manifest](firmware/usb-graph-state-members.json): all **1,918 files** retained; **1,917 unchanged** from MAX04. Only `MgrUSB.exe` changes; version and release assets stay unchanged.
- Original PE sections, imports, entry point, routine stack frames and prior function-table rows are preserved. Nine helper rows and their relocations occupy checked existing space.
- Every declared edit reverses byte-for-byte to the pinned MAX04 input. Earlier USB helper code remains unchanged.

## Reproduce

Install the [research dependencies](../docs/development.md#research-dependencies), then run from the repository root:

```powershell
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
python tools/build_usb_graph_state_development.py --baseline build/max04-reproduced/payload --out build/usb-graph-state-development
```

- The builder requires the exact complete MAX04 input and refuses missing/extra members, changed bytes, overlapping directories and existing outputs.
- It verifies all written members, executes the written candidate's fixture checks and writes completion metadata last.
- Outputs contain the complete payload, edit recipe, evidence and member hashes. No LGU or version bump is produced.
- `python -m unittest discover -s tools -p test_usb_graph_state.py` checks refusal behavior.
- GitHub Actions reproduces MAX04 and builds/checks this candidate.
- The retained report uses the historical local stage inputs. The new candidate's 378-case suite and complete member checks run in CI; the full historical suite is not claimed to run there.

## Device validation still needed

- This bounds the polling policy; Pause, Stop, Seek, Release and logging APIs can still block internally. It is not a universal deadlock repair.
- COM calls, clocks and scheduling are fixtures. Native CE loading/unwind, codec behavior, timing and concurrent ownership remain unverified.
- Existing caller intent changes before Stop/Pause are retained. Skipping follow-up work is not an atomic rollback of the entire request.
- Failed teardown retains resources intentionally. Retry behavior and USB removal/reinsertion need device testing.
- Test ordinary playback, pause/resume, held seek, source switching, track changes and USB removal/reinsertion. Confirm later playback can recover after a reported failure.
- Keep MAX04 as the comparison baseline. This candidate has no installation or recovery claim.
