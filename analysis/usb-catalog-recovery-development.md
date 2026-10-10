# Recover missing USB catalog storage

- **Stability:** check required buffers before root insertion or scan dispatch.
- **Recovery:** retry only missing song, directory and temporary-directory buffers; retain successful allocations.
- **Compatibility:** retain capacities, the playlist buffer, normal scan behavior and existing unavailable-media notification/cleanup instructions.
- **Scope:** application candidate in a complete MAX04-based payload. Native testing remains pending; no LGU or version bump.

## Behavior

[The allocation investigation](usb-catalog-readiness.md) reproduces invalid writes through missing catalog buffers. The constructor caches partial objects, so looking up the singleton again does not repair them.

[Patch](../tools/patch_usb_catalog_recovery.py) replaces the eight-byte setup at `1efd4` with a call to the readiness helper, before the first root insertion. The helper:

- Checks cancellation before allocating and between buffer attempts.
- Keeps existing pointers and retries each missing required buffer once per scan, allowing **two additional attempts per buffer per process** in sequential execution. Native overlap between scan workers remains unverified.
- Stops allocating when the existing tracking count reaches 100. Record 100 would begin at the allocator counter address (`2fb78 + 100 * 8 = 2fe98`). This protects that boundary in sequential fixtures; global allocation concurrency is not proven.
- Clears each successful new allocation with its original capacity, then publishes its pointer. This helper never publishes a pointer before clearing finishes.
- Enters the original root insertion and scan path only when all three required pointers are nonnull.
- On failure, uses the existing unavailable-media response for explicit/resume request modes when the manager is ready. Boot background mode returns through the original cleanup so its outer controller can finish its response. Cancellation returns without a new notification.

The original busy-field cleanup and notification fragment remain byte-identical. A failed buffer retains a null pointer and already allocated buffers remain available for the next scan. The playlist allocation is not retried or cleared by this patch; its existing guarded insertion remains intact. Two exhausted retries require a process restart before further allocation attempts.

Two helpers occupy previously zero executable capacity, with relocation and exception-table entries. Their runtime retry counters use 12 previously zero bytes in the existing writable section. No new imports or sections; no original stack frame or function exception record changes. This is a check once per scan, not a per-file operation. No measured speed or RAM claim.

## Verification

- [Focused verifier](../tools/verify_usb_catalog_recovery.py): the original null write remains a reproducer; new scans check allocation masks, individual/all required failures, cancellation, readiness, high-bit pointers and four relocated addresses.
- Normal scan outputs and catalog bytes match the previous candidate. Canceled scans skip the previously unconditional root write.
- Repeated scans cover failure, later success, no allocation after success and no allocation after retry exhaustion. Existing pointers and playlist state are preserved.
- Tracking boundaries 98, 99, 100, 101 and `ffffffff`; cancellation after each allocation; and actual deep-folder flattening after recovery are checked.
- API fixtures clobber volatile registers. Return paths preserve saved registers, stack/object canaries and clear the busy field.
- New pointers must still be null when the clearing fixture is called, testing publication order.
- [Allocator integration verifier](../tools/verify_usb_catalog_recovery_allocator.py): 48 additional cases execute the new allocation helper through the original allocation/accounting instructions, including heap/external success, failure and the tracking boundary. Driver and heap APIs remain fixtures.
- [Complete builder](../tools/build_usb_catalog_recovery_development.py) preserves all 1,918 MAX04 members and preceding candidates, then verifies the written bytes and frozen source hashes.
- [Refusal tests](../tools/test_usb_catalog_recovery.py) and [historical runner](../tools/verify_usb_catalog_recovery_retained.py) retain the existing input/output and regression checks.
- **2,802 focused checks**, **9,379 cumulative build checks**, **72,212 historical checks** and **48 allocator integration checks** passed locally on the exact candidate. Four refusal tests passed. These suites overlap; their counts are not a unique total.
- Published [complete-build evidence](firmware/usb-catalog-recovery-development.json), [member manifest](firmware/usb-catalog-recovery-members.json), [historical evidence](firmware/usb-catalog-recovery-retained.json) and [allocator integration evidence](firmware/usb-catalog-recovery-allocator.json).
- Candidate MgrUSB SHA256: `a9f0bf2266932d5574abd67c0a6444a27ada6e80064d6ee334db93e14e6d7ec8`.

## Limits and native validation

Allocations, large clears, CRT, registry, enumeration, postprocessing, diagnostics and cookie checks use explicit fixtures in the main suite. The additional integration suite executes the original allocator beneath the helper; its driver and heap APIs remain fixtures. Record prefixes are materialized; full multi-megabyte buffers are checked as API arguments. The original root write, helper logic, response construction and cleanup execute as MIPS instructions.

Native allocator/driver synchronization, UI delivery, boot-controller completion, loader/unwind and memory pressure still need validation. The generic unavailable-media response does not identify memory exhaustion to the user. Event-handle failure and recovery of the outer CFileMgr object are outside this candidate.

The boot and normal scan workers (`22bd8` and `22b40`) wait on separate events. The shared reset routine (`1db80`) clears state and artwork without waiting for either worker. These observations identify scan coordination as follow-up research; they do not prove that the device schedules overlapping scans. Retry counters and allocation tracking guards are checked sequentially, not as atomic synchronization.

On the unit, validate ordinary and repeated USB insertion, cold boot/resume, deep folders and cancellation first. Exercise allocation failure/recovery with a reversible application test before considering release packaging.
