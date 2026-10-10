# Binding USB payloads to their work

- **Purpose:** prevent an older queued payload from claiming a newer request's pending work.
- **Status:** unwired MIPS binding/claim/completion adapter, extending [deferred requests](usb-deferred-requests.md). Existing entry points and shipped firmware are unchanged.
- **Evidence:** [3,356 new instruction schedules and retained traces](firmware/usb-request-binding.json), at four load addresses.

## Record identity

The queue's first 32 bytes remain compatible. New adapters require a private, live **40-byte record**; the final two DWORDs store its media generation and request sequence. Old 32-byte/unbound admitted records cannot use the bound claim helper.

| Operation | Behaviour |
| --- | --- |
| Bind | Accept and capture the generation/sequence under the same ownership gate. Repeated binding does not advance either counter again. |
| Claim record | Compare that exact identity under the gate before allocating a lease or consuming a pending bit. Old records become stale without taking newer work. |
| Finish record | Reserve the record, then read its stored lease token and run protected completion. Busy attempts retain the lease; completed retries return the cached result. |

- A reset invalidates older media generations. A newer request of the same kind invalidates the older sequence.
- An unrelated request kind leaves a still-current record valid. A pending reset retains priority.
- Repeated claims return a distinct already-owned status without creating another lease or writing a second output token.
- A stale/rejected record keeps its terminal status. Callback failure is cached; it is not rollback of partial external writes.
- Output-token storage may not alias the record, preserving its immutable payload and binding.
- Receipts distinguish bound, claimed, changing, finishing, finished and dropped records. A receipt alone is not proof that a native thread has exited.

## Binary and verification

- [Patcher](../tools/patch_usb_request_binding.py) requires exact PR #44 input SHA256 `dbb3f81de76e2b102d6973fff1393bb3124c20cde5c241f69ef69c8a1ce6e3ae`.
- Helpers use existing zero space at `4a880`, `4ac00` and `4be50`, with generated exception rows and relocations. No imports, sections or existing entry hooks are added.
- Output SHA256: `77f231539594951d308892866d9cbceafe53c3504b7aa54c3ce342ba5e838f64`. A test executable, not a release payload.
- [Verifier](../tools/verify_usb_request_binding.py) reconstructs the earlier prototypes from PR #40 input before applying the new helpers.
- Tests all four kinds, older/newer payloads before and during a lease, legacy submissions, reset priority, busy retries, close/drain, saturation, invalid binding/output storage and callback failure.
- Injects reset admission and duplicate callers at reached non-control instruction boundaries, including delay slots and atomic wrappers. Duplicate callers cannot allocate a second identity/lease or publish twice.
- A duplicate-finish schedule caught an early token read racing with another completion's cached-result store. Token reading now follows successful receipt reservation.
- All **1,336 frozen queue/admission cases** and **540 frozen ownership cases** retain identical traces with the added helpers.
- Saved registers, stacks and 40-byte-record/queue canaries survive; atomic fixtures clobber volatile registers. Inputs stay unchanged and the patch is reproducible.

## Remaining integration

- Allocate/pool 40-byte records, handling failure and lifetime on real callers.
- Dispatch pending bound records, coalescing superseded work without executing an older payload.
- Wire boot scan, normal scan, shuffle and relevant reset/cancel paths; prepare results privately and publish them through owned completion.
- Retain busy requests/leases with native event-driven retry scheduling.
- Quiesce/join producers and workers on shutdown and verify exit receipts.
- Run retained/full-payload checks after integration, then validate device behaviour and performance.

Atomic operations, callbacks and CPU scheduling remain fixtures. This does not establish native CE memory ordering, live allocation, original-worker publication safety or device timing.
