# USB worker ownership prototype

- **Purpose:** prevent a scan or shuffle result from surviving a newer reset/request, without waiting for a long worker in the UI handler.
- **Status:** unwired MIPS prototype. Existing worker/reset entries and the shipped release are unchanged. This is a foundation for the fix, not a finished firmware fix.
- **Evidence:** [540 instruction-fixture cases](firmware/usb-lifecycle-protocol.json), including requests between completion instructions at four load addresses.
- **Context:** [scan overlap](usb-scan-coordination.md) and [shuffle publication races](usb-shuffle-lifecycle.md).

## Protocol

| Operation | Behaviour |
| --- | --- |
| Submit | Accept a reset, normal scan, boot scan or shuffle request; coalesce the latest request of each kind. |
| Claim | Grant one active lease. A pending reset takes priority over other work. |
| Finish | Check token, media generation and request sequence while holding the gate through the publication callback. Discard stale completion. |
| Close | Reject future work, clear pending requests and retain an active lease until it drains. |

- One `InterlockedCompareExchange` attempts the gate; contention returns `BUSY`. There is no spin loop or wait.
- `BUSY` means **not accepted**. A caller must retain the input and retry later. The native retry/defer adapter is not implemented yet.
- Long-running work owns a lease but releases the short protocol gate. Requests can invalidate that lease during the work.
- Reset advances the media generation and drops pending requests from the older generation. Subsequent requests belong to the new generation.
- Each kind has its own sequence: a newer shuffle invalidates old shuffle, while an unrelated pending scan does not invalidate it.
- Token, generation and sequence counters stop at `0xffffffff`; exhaustion closes the protocol instead of wrapping into an older identity.
- Wrong or duplicate completion cannot release another owner. Callback failure drains its owner and returns an explicit failure; external writes are not rolled back.
- A callback must return and must not depend on a reentrant protocol call succeeding. Such calls return `BUSY`.

## Binary and ABI

- [Patcher](../tools/patch_usb_lifecycle_protocol.py) requires exact PR #40 input SHA256 `a9f0bf2266932d5574abd67c0a6444a27ada6e80064d6ee334db93e14e6d7ec8`.
- Six helpers occupy existing zero space at `4b400..4bf00`; 52 zero state bytes start at `9a820` in an existing writable section.
- Uses existing imports: compare-exchange at `2f1c4` (ordinal 1492), exchange at `2f1b8` (ordinal 12). No new imports or sections.
- Helper exception rows and relocations are generated and checked. Original executable text and import directory remain identical.
- Output SHA256: `2ec74e90a8b89388d210c4bbe08e465fa39e97379b0059c02d550ca5b15ee0e8`. This single ignored executable is a test artifact, not a release payload.
- Submit takes kind in `a0`; claim takes kind/output-token pointer in `a0/a1`; finish takes token/callback/context in `a0/a1/a2`. Callback receives context in `a0`, returning zero for success. Close takes no arguments.

## Verification

- [Verifier](../tools/verify_usb_lifecycle_protocol.py) executes the written helper instructions with separate stacks/registers and shared protocol memory.
- Tests stale completion, coalescing, reset priority, old/duplicate tokens, close/drain, callback failure, input rejection, single-attempt contention and counter exhaustion.
- Injects reset requests before every reached non-control completion instruction, including branch delay slots and atomic wrappers. Requests accepted before publication reject old results; requests during publication return `BUSY` and are explicitly retried by the test caller.
- A leased callback executes the real USB/artwork/catalog reset paths from the shuffle reproducer. Other reset APIs and large-buffer prefixes retain that fixture's limits.
- Atomic APIs deliberately clobber volatile registers. Returning helpers preserve saved registers, stack and state canaries at four load addresses. Input bytes remain unchanged and the patch is reproducible.

These are instruction fixtures. They do not prove Windows CE scheduling or memory ordering, device latency, native filesystem behaviour, or integrated worker safety. The atomic APIs are fixtures; the ownership comparisons and stores are actual prototype MIPS instructions.

## Remaining integration

- Wire all three workers and every relevant reset/cancel path into the same protocol; existing entry points currently bypass it.
- Retain request parameters and retry `BUSY` submissions through a native deferred-work adapter. A pending bit alone cannot retain payloads or modes.
- Build results privately and publish all related fields/status in one owned completion; shared catalog mutation during work also needs ownership.
- Keep existing cancellation, list limits and yielding behaviour.
- Handle object/process lifetime, stop/join timeouts and thread-exit receipts. An empty active token is not proof that a thread has exited.
- Re-run retained behaviour and full-release checks after integration, then test the candidate on the unit before making performance or stability claims.
