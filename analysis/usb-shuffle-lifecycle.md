# Shuffle results across USB reset

- **Finding:** the current shuffle worker can publish an old list or overwrite reset settings after a USB reset in a controlled instruction schedule.
- **Scope:** extends [scan coordination](usb-scan-coordination.md) to the third USB worker and the current rewritten shuffle implementation.
- **Status:** reproduced on MAX04 and PR #40; their traces match. Research only, with no firmware or release change.

## Current worker and publication

Shuffle worker `22a8c` consumes event `34f40` and calls `1dd94`, which reaches the rewritten wrapper through `1b5b0`. The wrapper at `3fa80` calls builder `3f200`.

The builder already checks cancellation per track, bounds its list and delays publication until the full list is built. It also has a final cancellation/enabled check. These existing protections remain useful; they do not make reset and publication atomic.

- Final check starts at `3f3b8`.
- Completed count and pointer are stored separately at `3f3dc` and `3f3e0`.
- The wrapper subsequently publishes mode and saved-shuffle fields, then calls the shared-status writer.
- USB reset `1db80` reaches the actual artwork/control reset `1ad84`, which clears shuffle enabled, count, pointer and cursor fields. Catalog reset `12e80` clears the catalog separately.

## Controlled schedules

[Verifier](../tools/verify_usb_shuffle_lifecycle.py) uses separate worker/control stacks and registers sharing one memory image. It runs the real worker, rewritten builder/pool, wrapper, readiness checks and full USB/artwork/catalog resets. A four-track folder, RNG and OS/status operations are explicit fixtures.

| Reset point | No new request | New shuffle request before old work resumes |
| --- | --- | --- |
| Before final check | Existing check rejects the old build. | Flag is 1 again; old four-track result passes the check and becomes readable after catalog reset. |
| After final check, before count store | Old count/pointer and saved mode are published with shuffle disabled. | Old count/pointer are published and readiness returns 1. |
| Between count and pointer stores | Count remains 0 but pointer and saved mode are republished. | Readiness still rejects the empty count; saved mode is overwritten. |
| After builder return, before wrapper mode store | Count/pointer remain empty but saved mode is overwritten. | Empty list stays unreadable, while the wrapper publishes its older successful mode. |

Serial controls complete old work before resetting and leave count, pointer and enabled cleared. Both reset and the new request execute original/current MIPS paths; the new request uses `1ddb0` and its actual event signal `22f54`. The full IPC dispatcher and filesystem are not simulated.

A second shuffle event remains pending at the observation point. The reproducer demonstrates a stale-publication window; it does not claim that queued rebuilding never runs. The fixture then requests worker exit to bound the trace.

## Verification

- **96 cases passed:** two pinned binaries, four load addresses, four publication boundaries, and three reset/request orders.
- MAX04 SHA256: `cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c`.
- PR #40 SHA256: `a9f0bf2266932d5574abd67c0a6444a27ada6e80064d6ee334db93e14e6d7ec8`.
- [Evidence](firmware/usb-shuffle-lifecycle.json) records the cached result, fields before/after reset, final readiness, pending event and shared-status publication inputs.
- Returning helper calls preserve their ABI; shuffle stack and 5,000-entry array canaries survive. Input files remain byte-identical.

These are controlled instruction-boundary schedules, not observed Windows CE timing. Folder getters, iterator, RNG, event/thread operations, status delivery and cookie checks are fixtures. Full large-clear arguments are checked; only prefixes of those buffers are materialized. Native scheduling frequency, filesystem/UI effects and driver behavior remain unmeasured.

## Requirements for the lifecycle fix

- Coordinate **boot scan, normal scan, shuffle and resets** under the same ownership protocol.
- A reset/new request must invalidate older work even when enabled changes from 1 to 0 and back to 1.
- Publish list count/pointer, mode, saved settings and status as one owned completion; prevent reset between checking ownership and storing results.
- Preserve current cancellation, range limits, normal shuffle order and bounded yielding.
- Defer conflicting work without waiting for a long worker in the UI/message handler. Include pending work and thread shutdown in validation.

Adding another cancellation check or an unprotected generation comparison would leave a check-to-store gap. The generation check and complete publication need synchronization with reset.
