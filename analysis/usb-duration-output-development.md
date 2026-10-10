# USB duration output - development candidate

Builds on the [playback recovery candidate](usb-playback-recovery-development.md) and the complete **7.0.6.MAX04** payload. Draft for review; device testing is pending.

## Problems reproduced

- **Duration getter `0x1137c`:** its output is never initialized. A success response without output can convert an old stack value into a track duration.
- **Seek setter `0x1111c`:** its separate duration output is also uninitialized. A requested 42-second seek becomes 6.85 seconds when a missing output leaves a stale seven-second duration. Negative duration can move the request to zero.
- These are instruction/API-fixture reproductions. No frequency or incident on the unit is established.

The [GetDuration contract](https://learn.microsoft.com/en-us/windows/win32/api/strmif/nf-strmif-imediaseeking-getduration) describes an output value in the current time format and an HRESULT result. A success response without the required output is an injected fault, not normal API behavior.

## Changes

- Initialize both duration DWORDs to an unavailable sentinel before each owner's original COM query.
- The public getter rejects wholly unwritten or negative duration through its existing failure return, before division.
- The seek setter treats negative/unwritten duration like an unsuccessful duration query: skip duration clamping and keep the existing nonnegative seek fallback. It still lets `SetPositions` decide whether the seek succeeds.
- Preserve valid zero, short-track and near-end bounds, conversion, failed-HRESULT handling, missing-interface behavior and seek return values.
- Reuse two checked areas of zero padding. No section resize, import change or new runtime dependency.

## Evidence

- **716 focused checks:** stale stack values, negative output, unwritten high DWORD, valid duration/seek boundaries, HRESULT failures, missing interfaces and held/IPC/window caller behavior.
- Four load addresses, adversarial API clobbers and stack/register checks. New window-dispatch cases execute the real cookie initialization/check; message selection remains an explicit entry-state fixture. Earlier fixtures supplied a buffer-like value in that cookie slot and remain historical evidence.
- **386 retained recovery checks**, **257 playback-start checks**, **624 completion checks**, **793 timing checks**, **365 initialization checks** and **431 graph-state checks**. Full builder: **3,572 checks**, including explicit cumulative structure verification against the written executable.
- [Instruction report](firmware/usb-duration-output-development.json), [complete member manifest](firmware/usb-duration-output-members.json) and [historical USB report](firmware/usb-duration-output-retained.json).
- **72,212 historical regression cases passed** in a separate local run. The 224 historical sources, eight stage inputs and checked runner sources retain their recorded hashes.
- Full payload: **1,918 members retained**, **1,917 unchanged** from MAX04; only `MgrUSB.exe` changes.

## Reproduce

Install the [research dependencies](../docs/development.md#research-dependencies), then run:

```powershell
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
python tools/build_usb_duration_output_development.py --baseline build/max04-reproduced/payload --out build/usb-duration-output-development
python -m unittest discover -s tools -p test_usb_duration_output.py
```

- Seven pinned stages, complete output readback, source hash checks before/after verification and completion metadata written last.
- Refuses changed inputs, missing/extra members, overlapping directories and existing output.
- Earlier published sources remain byte-exact. Retained functions use isolated namespaces and checked helper entry ranges.
- The separate historical run uses `verify_usb_duration_output_retained.py` and the original ignored workspace. It verifies the historical source/input hashes and its runner sources; it never overwrites reports and is outside CI.

## Remaining validation

- COM/OS responses are fixtures. Native CE, codecs, audio, scheduling, concurrency, unwinding and performance remain unverified.
- Sentinels detect wholly unwritten outputs and an unwritten high DWORD; they cannot identify every partial write.
- Existing fallback seeking does not promise the requested position was reached. The earlier recovery candidate checks progress after rejected seeks.
- No LGU, version bump or published release replacement. Before release, test normal playback, seeking near track ends, short tracks, unavailable duration, pause/resume and USB removal on the unit.
