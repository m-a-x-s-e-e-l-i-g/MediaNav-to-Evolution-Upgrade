# USB playback recovery - development candidate

Builds on the [playback start candidate](usb-playback-start-development.md) and the complete **7.0.6.MAX04** payload. Draft for review; device testing is pending.

## Problems reproduced

- **Stop status:** controller `0x1af28` publishes stopped status before checking manager Stop. Failed Stop leaves the graph's cached running state and owned interfaces intact, but the UI reports stopped.
- **Resume:** `remainPlay` ignores its initial seek result. A failed seek can leave the requested timestamp on screen while playback continues elsewhere.
- **Reload:** the same controller seeks after a failed reload. It also ignores a failed seek after successful reload.
- **Position output:** getter `0x11230` initializes outputs to zero. Unwritten or negative current time, and an unwritten duration, can become a false position of zero.

The [instruction report](firmware/usb-playback-recovery-development.json) reproduces the preceding candidate's behavior. Frequency and impact on the unit remain unmeasured.

## Changes

- Publish stopped status and reset the display only after manager Stop confirms completion. On failure, retain the last logical status, clock and owned references. Original timer cancellation remains.
- After failed resume seeking, refresh progress through the checked position getter. Keep the original requested timestamp in an unused caller stack slot for the existing reload fallback.
- Skip the subsequent seek when reload fails. After successful reload with failed seeking, refresh confirmed progress; if querying also fails, retain the display and align the private resume cache to it. This fallback does not assert a physical playback position.
- Initialize getter outputs with unavailable sentinels. Reject negative or wholly unwritten current time and an unwritten duration before conversion. Preserve valid zero, rounding and duration clamping.
- Preserve the actual loader's retry and refusal paths after an initial Stop failure. A first failure can recover during loading; aborting immediately would remove that recovery.
- Keep the previous nonnegative seek-result policy. The [SetPositions contract](https://learn.microsoft.com/en-us/windows/win32/api/strmif/nf-strmif-imediaseeking-setpositions) defines HRESULT results and positioning flags; these fixes handle rejected seeks without changing successful positioning behavior.

## Evidence

- **385 focused checks:** Stop failure/status ordering, failed seeks, actual reload construction and rejection, unavailable output, retained clocks, valid getter boundaries and healthy before/after behavior.
- **256 retained playback-start checks**, **623 seek-completion checks**, **792 timing checks**, **364 initialization checks** and **431 graph-state checks**. Full builder: **2,851 checks**, including cumulative structure verification against the final written executable.
- The 12 older clock-only Stop leaf cases are replaced by full Stop-controller cases: the changed publication order is intentional. All other graph-state cases remain.
- Four load addresses, adversarial API clobbers, owned-reference checks, original controller entries/returns, register and stack checks, and the actual stack-cookie comparison.
- Six helpers use checked zero padding. Sections, imports, entry point, previous helper bodies and exception rows remain intact. Helper prologues include register saves; edits reverse exactly to the pinned input.
- [Complete member manifest](firmware/usb-playback-recovery-members.json): **1,918 members retained**, **1,917 unchanged** from MAX04; only `MgrUSB.exe` changes.
- [Historical USB report](firmware/usb-playback-recovery-retained.json): **72,212 passing cases** in a separate run; 224 historical sources and eight stage inputs retain their recorded hashes.

## Reproduce

Install the [research dependencies](../docs/development.md#research-dependencies), then run:

```powershell
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
python tools/build_usb_playback_recovery_development.py --baseline build/max04-reproduced/payload --out build/usb-playback-recovery-development
python -m unittest discover -s tools -p test_usb_playback_recovery.py
```

- Six pinned stages, full output readback and verification of the written executable. Completion metadata is written last.
- Refuses changed input, missing/extra members, overlapping directories and existing output. Source hashes are checked before and after verification.
- Previous published sources remain byte-exact; retained suites use isolated function namespaces.
- The separate historical run uses `verify_usb_seek_completion_retained.py` with this candidate and the original ignored workspace. It is outside CI and never overwrites evidence.
- No LGU, version bump or replacement of a published release.

## Remaining validation

- Actual MIPS controllers, loader and graph construction execute with explicit COM, metadata, catalog and OS responses. Fixtures do not execute CE, codecs, audio, concurrent scheduling or native unwinding. Performance remains unmeasured.
- Failed Stop still cancels timers. Preserving the previous logical state does not establish the physical state after an API error.
- Sentinel checks catch wholly unwritten outputs and negative time; they cannot identify every possible partial write.
- The standalone duration getter and the seek setter's separate duration query remain follow-up work. Existing asynchronous skip/error policy is unchanged.
- Before release, test normal play, pause/resume, failed seeking, corrupt/unsupported tracks, USB removal/reinsertion, failed Stop/reload and Bluetooth call interruption on the unit.
