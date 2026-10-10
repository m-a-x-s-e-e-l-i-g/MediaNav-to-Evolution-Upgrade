# USB playback start - development candidate

Builds on the [seek completion candidate](usb-seek-completion-development.md) and the complete **7.0.6.MAX04** payload. Draft for review; device testing is pending.

## Problems reproduced

- **Ordinary play:** `0x1c910` calls manager `Run`, but `0x1c918` ignores failure and continues through the success path. Progress timer 1000 stays active and the caller returns success.
- **Failed COM start:** manager `0x114a0` returns failure, but leaves readiness and progress polling intact. Its three direct callers are ordinary play, `remainPlay` and timer 1007.
- A failed start can leave some filters running. Microsoft describes tearing down the graph and reporting an error in this case. `S_FALSE` is an accepted pending transition, not a failure. See the [Run contract](https://learn.microsoft.com/en-us/windows/win32/api/control/nf-control-imediacontrol-run).

The [instruction report](firmware/usb-playback-start-development.json) reproduces the preceding candidate's behavior. Device frequency and impact remain unmeasured.

## Changes

- On a negative COM start HRESULT, invalidate readiness and cancel progress timer 1000 when its window handle exists.
- Reuse bounded graph teardown: release interfaces only after stopping is confirmed. Failed/pending state checks, rejected commands and timeouts retain owned interfaces. A control pointer lost after `Run` skips teardown and retains references.
- Publish stopped status only after confirmed teardown, and only when the UI pointer exists. Keep the saved timestamp for the existing reload fallback.
- Ordinary play routes a failed manager start through its existing error handling. Preserve its error notification and asynchronous skip policy.
- Preserve healthy starts, accepted nonnegative results, the already-running shortcut, call blocking and timer 1007's direct start. No extra seek is added to that timer.
- Keep `remainPlay`'s reload fallback. A failed start followed by successful reload restores the saved timestamp.

## Evidence

- **255 new checks:** before/after normal behavior, failed/partial start, bounded cleanup, missing handles, pointer loss, command failures, tick wrap, poll cap, owned aliases, actual ordinary-play/error handling, timed start and reload fallback.
- **622 retained seek-completion checks**, **791 timing checks**, **363 initialization checks** and **431 graph-state checks**. Full builder: **2,462 checks**, including the explicit cumulative structure checks.
- Four load addresses, actual caller entries/returns, adversarial API clobbers and stack/register checks. Status setter, timer control, fade request and stack-cookie comparison execute their actual instructions.
- Two helpers use verified zero padding. Earlier helper bodies, exception rows, sections, imports and entry point remain intact. Cleanup metadata includes all three prologue instructions; edits reverse exactly to the pinned input.
- [Complete member manifest](firmware/usb-playback-start-members.json): **1,918 members retained**, **1,917 unchanged** from MAX04; only `MgrUSB.exe` changes.
- [Historical USB report](firmware/usb-playback-start-retained.json): **72,212 passing cases** in a separate local run; 224 historical sources and eight stage inputs retain their recorded hashes.

## Reproduce

Install the [research dependencies](../docs/development.md#research-dependencies), then run:

```powershell
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
python tools/build_usb_playback_start_development.py --baseline build/max04-reproduced/payload --out build/usb-playback-start-development
python -m unittest discover -s tools -p test_usb_playback_start.py
```

- Five pinned stages, full output readback and checks against the written executable. Completion metadata is written last.
- Refuses changed input, missing/extra files, overlapping directories and existing output. CI runs the complete builder.
- Retained behavior suites use isolated namespaces and explicit cumulative structure checks; previous published sources stay byte-exact.
- The separate historical run uses `verify_usb_seek_completion_retained.py` with this candidate and the original ignored workspace. It is outside CI and never overwrites evidence.
- No LGU, version bump or replacement of a published release.

## Remaining validation

- Fixtures supply COM, catalog, metadata, LoadFile and OS responses. They do not run CE, codecs, audio, real scheduling or native unwinding. Concurrency, blocking API calls and performance remain unverified.
- The existing error/skip policy can publish logical playing status while a skip is pending. This change does not make every UI state equivalent to physical graph state.
- Ordinary play's earlier Stop result, ignored resume/reset seek results and actual asynchronous auto-next execution remain separate work. The existing load-replacement refusal is checked in retained initialization tests.
- A failed start can add bounded cleanup latency. UI error appearance and recovery after an unconfirmed stop need device testing; retaining references is intentional.
- Test normal play, pause/resume, corrupt or unsupported tracks, failed starts, auto-next, USB removal/reinsertion, timed resume and Bluetooth call interruption before release.
