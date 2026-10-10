# Dispatching bound USB requests

- **Purpose:** turn queued requests into one owned lease, retaining conflicting work and returning obsolete/completed records for reclamation.
- **Status:** unwired MIPS dispatcher over [payload binding](usb-request-binding.md). It selects work but does not launch the original scan/shuffle bodies. Shipped firmware is unchanged.
- **Evidence:** [3,124 new controlled instruction schedules and retained traces](firmware/usb-request-dispatch.json).

## Request lifecycle

| Operation | Behaviour |
| --- | --- |
| Pump | Process at most eight queued records, bind/coalesce pending work, then select one lease. Return its record pointer and token together. |
| Complete | Check active pointer and expected token, run owned completion, retire the record once and wake pending work. |
| Collect | Transfer one retired record to the caller for reclamation. Busy/empty attempts leave output untouched. |

- Queue producers remain independent of the dispatcher gate. The receiver never waits for a long worker.
- A busy admission retains the record in an inbox. Pending records remain available while another lease runs.
- The latest bound payload of each kind replaces an older pending payload. Superseded records get a stale status and enter the retired list.
- Selection gives reset priority, then normal scan, boot scan and shuffle. Stale bindings cannot consume newer pending work.
- A drain-budget result requests another bounded call; it does not launch work before the current queue batch has been drained.
- Completion takes both **pointer and expected lease token**. An old completion cannot act on a new lease at a reused record address.
- Failed wake-ups leave work/records intact and set an observable failure flag. A real retry/polling fallback still needs integration.
- Retired records are tracked until collected. Collection permits caller reclamation under this API's lifetime contract; it is not a native thread-exit receipt.

## ABI and binary

- Pump receives a pointer to separate, writable eight-byte output storage in `a0`. Success writes `{record, token}`; other statuses preserve both words.
- Complete receives record, expected token, completion callback and callback context in `a0..a3`. The worker must retain its own token snapshot. Callback failure keeps its original status; partial external writes are not rolled back.
- Collect receives a separate writable output-pointer address in `a0`. A successful call transfers the returned record; completed callers must not continue accessing records that have been collected/reused.
- [Patcher](../tools/patch_usb_request_dispatch.py) requires PR #45 input SHA256 `77f231539594951d308892866d9cbceafe53c3504b7aa54c3ce342ba5e838f64`.
- Five helpers fit existing zero space; 40 writable zero state bytes start at `9a880`. Existing sections/imports/entry hooks remain unchanged. Exception rows and relocations are generated and checked.
- Output SHA256: `c5355412e3d29203b0715c8e84f13af672b8aa78a8ece0065f55a2c27c037d31`. A test executable, not a release payload.

## Verification

- [Verifier](../tools/verify_usb_request_dispatch.py) reconstructs the previous prototypes from PR #40 input before executing the dispatcher at four load addresses.
- Tests selection, per-kind coalescing, reset priority, active cancellation, eight-record budgeting, core contention, failed wakes, address reuse, closed ownership and callback failure.
- A lifecycle ledger accounts for every private, queued, inbox, pending, active, retired and collected record across seeded mixed workloads.
- Producers, dispatch and reclamation interleave at reached non-control instruction boundaries. Collected bodies are removed from fixture memory to detect later access.
- A producer can pause between head exchange and link publication. Pump returns promptly and retains records; a later bounded call sees the completed link. A conservative busy snapshot does not authorize dropping queued work.
- Producers can enqueue during publication; reentrant dispatch/collection returns busy. Callback publication remains under the ownership gate.
- All **3,356 frozen binding cases**, **1,336 queue/admission cases** and **540 ownership cases** retain identical traces.
- Saved registers, stack and record/state canaries survive. Atomic fixtures clobber volatile registers; inputs remain unchanged and the patch is reproducible.

## Remaining integration

- Allocate/pool private 40-byte records and handle exhaustion without losing ownership.
- Add native retry scheduling for gate contention, unfinished producer links, drain budgeting and failed wakes.
- Wire all worker/reset/cancel callers into this dispatcher; build results privately and publish them through owned completion.
- Make worker context/token lifetime and producer/worker shutdown explicit, including join/exit receipts before releasing their other resources.
- Validate the full payload after integration, then test device functionality, stability, latency and memory use.

Atomic/event APIs, callbacks, scheduling and reclamation are controlled fixtures. Original long worker bodies, live allocation, native retry timers and thread shutdown are not exercised by this dispatcher prototype.
