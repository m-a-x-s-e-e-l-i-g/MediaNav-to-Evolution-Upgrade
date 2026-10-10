# USB seek completion - development candidate

Builds on the [seek timing candidate](usb-seek-timing-development.md) and the complete **7.0.6.MAX04** payload. Draft for review; device testing is pending.

## Problems reproduced

- **Saved-track resume:** `0x1bc94` displays and publishes the saved timestamp after `SetPosition` returns `-1`. The track can load successfully while the seek fails.
- **Held seeking:** `0x1da8c` updates progress after a failed seek. Near the end, `0x1d920` sends completion notification `0x6c` and cancels repeat timers before the seek result is known; the failed seek then reaches the end controller.
- **Direct IPC seeking:** `0x21748` updates progress before pause and seek succeed. A failure leaves the requested timestamp on screen.

The [instruction report](firmware/usb-seek-completion-development.json) reproduces these behaviors using the executed previous candidate. Device frequency and impact remain unmeasured.

## Changes

- Require a positive manager seek result before updating held/IPC progress. The manager translates a failed COM HRESULT to `-1`.
- After a failed saved-resume seek, query the actual position and use that confirmed value. If the query also fails, use an explicit **zero fallback**; this is not a claim that the graph is at zero. Keep the successfully loaded track available.
- Move held-end completion until after successful seeking. Failure skips progress, publication and the end-controller call through the held owner's own epilogue.
- Keep held mode and repeat timers available for normal release handling. Preserve the original backward clamp, which can clear the repeat factor before seeking.
- Move IPC progress updating after successful seeking. Failed pause also avoids the premature update; the original handled return remains intact.
- Preserve normal values, API counts, file ownership and caller returns. The successful paths intentionally change notification/progress ordering.
- Keep the window seek owner unchanged: it already refreshes the queried position and frees its temporary buffer.

## Evidence

- **621 new checks:** failures, normal before/after comparisons, saved-resume fallback, file/load rejection, both held directions, end handling, IPC pause/seek failure, retry and original release cleanup.
- **790 retained timing checks**, **362 initialization checks** and **431 graph-state checks**. Full builder: **2,204 checks**.
- Four load addresses, actual caller entries/epilogues, stack/return-address/callee-register checks and adversarial API clobbers. Actual setters, converters, timer cancellation and thin UI wrappers execute.
- Two framed helpers use verified zero padding outside existing function bodies. All earlier helper bodies and exception rows remain intact; sections, imports and entry point are preserved. Edits reverse exactly to the pinned input.
- [Complete member manifest](firmware/usb-seek-completion-members.json): **1,918 members retained**, **1,917 unchanged** from MAX04; only `MgrUSB.exe` changes.
- [Historical USB report](firmware/usb-seek-completion-retained.json): **72,212 passing cases** from a separate local rerun; 224 historical sources and eight stage inputs match their recorded hashes. Its 25 resume/identity cases now execute actual seek instructions, correcting the historical substitute that returned zero for success. Historical source files remain byte-exact.

## Reproduce

Install the [research dependencies](../docs/development.md#research-dependencies), then run:

```powershell
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
python tools/build_usb_seek_completion_development.py --baseline build/max04-reproduced/payload --out build/usb-seek-completion-development
python -m unittest discover -s tools -p test_usb_seek_completion.py
```

- The builder applies four pinned stages, reads back every output member, runs the written executable's fixtures and writes completion metadata last.
- Refuses changed input, missing/extra files, overlapping directories and existing output. CI reproduces MAX04 and runs the combined builder.
- Previous behavior suites use isolated function namespaces with explicit cumulative structure checks; historical module globals stay intact.
- The separate `verify_usb_seek_completion_retained.py` requires the original local historical workspace, validates its recorded source/input hashes and never overwrites evidence. It is outside CI.
- No LGU, version bump or replacement of a published release.

## Remaining validation

- MIPS instruction fixtures simulate COM, files, UI/library calls and dispatcher entry state. They do not run CE, codecs, audio or real scheduling. Native loading/unwind, concurrency, blocking calls and performance remain unverified.
- The end controller is an explicit call fixture; auto-next internals are outside this change. Original held-release cleanup executes its non-playing/blocked branches; its playback-resume controller remains separate work.
- Failure can follow the original pause or timer cancellation. This does not roll those actions back. Ordinary play/reset setters and completion-event fallback remain separate follow-ups.
- Successful seeks retain the existing requested-time display and rounding/end-margin behavior; they do not promise an additional actual-position refresh.
- Test saved resume, held forward/backward near both ends, release after failure, short/corrupt files, IPC progress, USB removal/reinsertion and normal auto-next on the unit before release.
