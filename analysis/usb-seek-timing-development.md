# USB seek timing — development candidate

Based on the complete **7.0.6.MAX04** payload and the [initialization candidate](usb-graph-init-development.md). Review only; device validation is pending.

## Problems reproduced

- The position getter ignores a failed duration query. Initialized zero or partially written output becomes a valid-looking playback position.
- The periodic timer converts a failed position query to displayed zero and publishes it.
- Held forward/backward seeks and IPC/window seeks consume failed position queries. Forward seek also consumes a failed duration query.
- Seeking to the end subtracts a 150 ms margin. A track shorter than that produces a negative absolute target, including a reset seek to zero.
- A negative duration reported with a successful HRESULT becomes a large positive duration through the original conversion.

The [instruction report](firmware/usb-seek-timing-development.json) executes the previous candidate to reproduce these cases. Frequency and impact on the device have not been measured.

## Changes

- Reject failed duration queries and negative durations through the existing error returns.
- Preserve the last displayed/cached position after a failed timer query. A later successful tick updates it normally.
- Skip seek arithmetic, progress publication and end handling after timing errors in held and dispatched seeks. Window dispatch still frees its temporary buffer.
- Clamp negative absolute seek targets to zero. Preserve normal rounding, the end margin and the existing positive-target fallback after a failed duration query.
- Keep duration queries in their original order. No duration cache: [GetDuration](https://learn.microsoft.com/en-us/windows/win32/api/strmif/nf-strmif-imediaseeking-getduration) can return an estimate for variable-bitrate streams. [GetCurrentPosition](https://learn.microsoft.com/en-us/windows/win32/api/strmif/nf-strmif-imediaseeking-getcurrentposition) returns an HRESULT and a separate time output.
- Retain the graph-state and initialization candidates. Completion-event fallback and auto-next behavior are outside this change.

## Evidence

- **544 timing checks**, including original defects, healthy before/after parity, 850 ms rounding, tiny tracks, API errors, retry, both held directions and IPC/window cleanup.
- **431 retained graph-state checks** and **359 retained initialization behavior cases**, plus two cumulative structural checks. Total: **1,336** checks in the full builder.
- Three alternate load addresses; actual caller prologues, cleanup and returns; stack, return address and callee-saved registers checked with adversarial API clobbers.
- Eight leaf helpers use checked zero padding. Sections, imports, entry point, previous graph helpers and previous exception rows stay intact. Table growth stays within existing raw section capacity; edits reverse exactly to the checked input.
- [Complete member manifest](firmware/usb-seek-timing-members.json): all **1,918 members**, **1,917 unchanged** from MAX04; only `MgrUSB.exe` changes.
- [Historical USB checks](firmware/usb-seek-timing-retained.json): **72,212 passing cases** from a separate rerun; all 224 local historical source snapshots and eight stage inputs match their recorded hashes.

## Reproduce

Install the [research dependencies](../docs/development.md#research-dependencies), then run:

```powershell
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
python tools/build_usb_seek_timing_development.py --baseline build/max04-reproduced/payload --out build/usb-seek-timing-development
python -m unittest discover -s tools -p test_usb_seek_timing.py
```

- The builder verifies the full MAX04 input, applies three pinned stages, reads back every member and tests the written executable before writing completion metadata.
- Refuses wrong input bytes, missing/extra members, overlapping directories and existing output. Historical tools and their published evidence remain unchanged.
- The initialization behavior suite uses an isolated function namespace with explicit cumulative structural checks. Its historical single-stage check correctly refuses additional timing edits; its module globals are never changed.
- CI reproduces MAX04 and runs the combined builder. The separate historical suite requires local stage inputs and is not claimed to run in CI.
- No LGU, version bump or replacement of a published release.

## Device validation still needed

- These are MIPS instruction fixtures with simulated COM, integer-library and OS calls. Dispatch arms use supplied message state; this is not a CE or codec emulator.
- Real loading/unwind, audio, concurrency, failure frequency, memory consumption and elapsed time remain unverified. Individual COM calls can still block.
- Held-seek failure may follow timer cancellation and pause; this does not promise rollback of those earlier actions. Very long duration overflow remains outside scope.
- Test ordinary playback, seeking near both ends, short files, failed/corrupt media, auto-next and USB removal/reinsertion. Compare with MAX04 on the unit before release.
