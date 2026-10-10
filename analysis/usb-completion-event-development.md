# USB completion event - development candidate

Builds on the [duration output candidate](usb-duration-output-development.md) and the complete **7.0.6.MAX04** payload. Draft for review; device testing is pending.

## Problems reproduced

- DirectShow event owner `0x11ab0` handles track completion with two position queries, followed by two standalone duration queries. The first standalone duration is checked, but the second result is displayed without checking it.
- An injected failure in the second duration query replaces a checked 300-second duration with a false zero on the display.
- A failed first position query is passed to the clock setter as `-1`. The existing converter clamps it to zero, so an unavailable position resets the display before the next query.
- The [instruction report](firmware/usb-completion-event-development.json) reproduces both faults in the preceding candidate. No incident frequency on the unit is established.

## Changes

- Skip the first clock update when position is unavailable. Preserve a valid position of zero.
- Reuse the already checked duration for the final completion display; remove the redundant standalone duration query and conversion.
- Preserve the 100 ms wait, second position query, repeat path, 300 ms debounce, completion notification, logging and event-parameter cleanup.
- One leaf helper uses verified zero padding. The original event-owner frame and cleanup remain intact.

## Evidence

- **304 focused checks:** healthy before/after behavior, valid zero, unavailable position, changing duration responses, non-completion codes, repeat/active/debounce guards, empty queue, missing interface, mixed queues and one cleanup call per dequeued event.
- Healthy completion's total duration queries fall from **four to three**: two position getters still query duration internally, and the final display uses one standalone query. One duration conversion/division is also removed.
- These are instruction/API counts, not measured device speed. Sleep duration and IPC notifications are unchanged.
- Four load addresses, adversarial API clobbers, full event-owner entry/return, register/stack checks and actual progress/publication wrappers.
- **717 retained duration checks**, **387 recovery checks**, **258 playback-start checks**, **625 completion checks**, **794 timing checks**, **366 initialization checks** and **431 graph-state checks**. Full builder: **3,882 checks**, including cumulative structure verification against the written candidate.
- [Complete member manifest](firmware/usb-completion-event-members.json): **1,918 members retained**, **1,917 unchanged** from MAX04; only `MgrUSB.exe` changes.
- [Historical USB report](firmware/usb-completion-event-retained.json): **72,212 passing cases** in a separate run; the 224 historical sources, eight stage inputs and checked runner sources retain their recorded hashes.

## Reproduce

Install the [research dependencies](../docs/development.md#research-dependencies), then run:

```powershell
python tools/release_payload.py --prepare-input .inputs/max04-baseline
python tools/release_payload.py --baseline .inputs/max04-baseline --out build/max04-reproduced
python tools/build_usb_completion_event_development.py --baseline build/max04-reproduced/payload --out build/usb-completion-event-development
python -m unittest discover -s tools -p test_usb_completion_event.py
```

- Eight pinned stages, complete output readback, source hashes checked before/after verification and completion metadata written last.
- Refuses changed inputs, missing/extra members, overlapping directories and existing output.
- Previous published sources remain byte-exact; retained checks use isolated function namespaces.
- The separate historical run uses `verify_usb_duration_output_retained.py` with this candidate and the original ignored workspace. It is outside CI and never overwrites reports.

## Remaining validation

- COM queue, time and IPC are fixtures. Native CE, codecs, audio, concurrent callbacks, object lifetime, native unwinding and elapsed performance remain unverified.
- Event query outputs and the event interface are supplied as valid owned data. This change does not establish a general event-queue concurrency or malformed-output contract.
- The existing completion/auto-next policy remains. The candidate avoids a false zero but does not make every displayed clock equal to a physical position.
- No LGU, version bump or published release replacement. Before release, test track endings, repeat modes, short/unsupported tracks, USB removal during completion, and queued errors on the unit.
