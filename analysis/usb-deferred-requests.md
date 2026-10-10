# Retaining deferred USB requests

- **Purpose:** preserve full requests while the [ownership protocol](usb-lifecycle-protocol.md) is busy; retain the worker's parameters instead of using only a pending bit.
- **Status:** unwired MIPS queue and receiver admission bridge. Existing worker/reset entries and shipped firmware are unchanged.
- **Evidence:** [1,336 new cases](firmware/usb-deferred-requests.json), plus identical traces from all 540 frozen ownership cases.

## Queue and admission

| Operation | Behaviour |
| --- | --- |
| Init | Initialize once, before producers start. Optional event handle enables a wake after publication. |
| Push | Transfer a private record into the queue. Preserve insertion order and all parameters; reject duplicate posting. |
| Pop | Transfer the next record to the consumer. A single atomic attempt serializes consumers; unfinished producer links return `BUSY`. |
| Accept | Submit the dequeued record's kind to the ownership protocol. `BUSY` retains the record for another attempt; successful retries admit it only once. |

- Each caller supplies a live, aligned **32-byte record**: next pointer, kind, three arguments, caller ID, receipt and terminal rejection code.
- Queue-owned payloads are immutable. The caller cannot free/reuse a queued record. A successful pop transfers it to the receiver; reuse is allowed only after that receiver has finished with it.
- Receipt states distinguish new, queued, dequeued, submitting, admitted and rejected records. Concurrent admission attempts cannot submit the same record twice.
- Push/Pop/Accept have no native spin loop or wait. Atomic operations and event notification still have unmeasured native latency.
- A failed wake reports **accepted ownership** with a separate status. The record remains queued; reposting or freeing it would be wrong. A polling/retry fallback still needs integration.
- A paused producer can prevent consumption until it publishes its predecessor link. Producers must not be forcibly terminated in that interval.
- A record being admitted is not yet bound to a particular lease. The dispatcher must bind payload, generation and sequence before claiming/executing it; this patch does not implement dispatch.

The queue structure follows [Dmitry Vyukov's intrusive multi-producer queue](https://sites.google.com/site/1024cores/home/lock-free-algorithms/queues/intrusive-mpsc-node-based-queue). This MIPS prototype uses the existing compare-exchange/exchange imports for pointer publication and reads, and adds a try-only consumer gate. It makes no claim of native memory-ordering proof or guaranteed consumer progress if a producer stops.

## Binary and verification

- [Patcher](../tools/patch_usb_deferred_requests.py) requires PR #43 output SHA256 `2ec74e90a8b89388d210c4bbe08e465fa39e97379b0059c02d550ca5b15ee0e8`.
- Five helpers use existing zero space at `4c100..4cd80`; 24 writable zero state bytes start at `9a860`. No new sections/imports or existing entry-site edits.
- Output SHA256: `dbb3f81de76e2b102d6973fff1393bb3124c20cde5c241f69ef69c8a1ce6e3ae`. A test executable, not a release payload.
- [Verifier](../tools/verify_usb_deferred_requests.py) reconstructs PR #43 from PR #40 input, patches the queue, then executes the written MIPS helpers at four load addresses.
- **284 producer-boundary cases:** another producer and consumer interleave while a producer is paused; records remain in head-exchange order.
- **472 consumer-boundary cases:** a producer arrives during pop; retired records are removed from fixture memory to detect later access.
- **492 admission-boundary cases:** another attempt to admit the same dequeued record interleaves; its request sequence increments once.
- Additional cases cover 1–32 records, payload preservation, record reuse, contention, duplicate posting, wake failure, repeated admission retries, closed/exhausted rejection and real event-woken worker argument loads.
- Normal scan retains `(USB, 1, 0)`, boot retains `(USB, resume, 0)`, and shuffle retains `(USB, folder, 0)`. The original worker instructions load these values before the fixture queues them; their long bodies are not dispatched here.
- Atomic fixtures clobber volatile registers; saved registers, stack and node/queue canaries survive. Frozen ownership traces match before/after the addition.
- Published traces keep per-case schedules/results and atomic call counts/digests. Use verifier option `--full-atomics` to reproduce the complete atomic log locally.

## Remaining integration

- Allocate/pool private records, handle allocation failure and enforce their lifetime on real callers.
- Bind each admitted payload to its exact media generation/request sequence; coalesce obsolete records safely before any lease executes.
- Wire all three workers and relevant reset/cancel paths, preserving private result construction and owned publication.
- Add event-driven dispatch and a bounded retry mechanism for busy gates, unfinished producer links and failed wakes.
- Quiesce/join producers and workers during shutdown; queue emptiness alone is not a shutdown receipt.
- Run retained/full-payload validation after integration, then test the candidate on the device.

Atomic/event APIs, CPU scheduling and memory-ordering behaviour remain fixtures. No hardware timing, live allocation, native cancellation or device behaviour is established by these tests.
