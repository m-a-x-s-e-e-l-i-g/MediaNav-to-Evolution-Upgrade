# MAX21: measured optimization from the owner's MAX19 captures

The two supplied files were analysed read-only and copied privately to
`build/usb-log-analysis-20261013-01`. They contain 13,439 valid records, with
46.6 minutes in the longer surviving chunk. Raw logs are not in release/source
snapshots. MAX19 observations do not establish MAX20's behavior on the car.

## Poll logging optimization

The Blue helper runs roughly twice per second. The longer capture contains
5,592 calls: 5,562 return zero and 30 report publication. Their begin/end records
are 84.3% of records and 65.1% of log bytes. MAX21 keeps the polling schedule,
publication and retry logic, but logs nonzero returns, calls of at least 16 ms,
and a ten-second poll-count/maximum-duration summary. Emitted native errors are
not filtered. The total decode, source and USB events remain enabled.

Feeding the captured results/timings through the written MIPS wrapper produces
308 records, including 278 summaries and all 30 publication results, instead
of 11,184 poll records: a 97.25% reduction in this replay. The publication body
is an explicit fixture in that replay, not hardware. Separate original-body
instruction tests cover pending/missing/stale/publication/retry cases and verify
equal return, ack and cleanup behavior. No car CPU or audio-latency gain is claimed.

## Source timing

The measured source switches take 9, 343, 859 and 280 ms; 859 ms is FM to
Bluetooth. Original d9f04 has three conditional 200 ms sleep sites and IPC
with zero-result retries. New events measure each sleep independently (120–122),
IPC sends/retries (130), gets (131) and posts (132). Targets, arguments, delay
slots, native waits/readiness and the cloned inline source jump table remain.
The aim is to isolate the delay before changing synchronization.

## Artwork and memory

There are 28 decoder calls, median 46.5 ms, worst 206 ms. New phases measure
JPEG validation (320), COM factory creation (321), image-from-buffer (322),
image information (323), bitmap allocation (324), drawing (325), COM release
(326) and bitmap deletion (327). Native ownership remains unchanged.

Events 902/903 sample global free RAM/load before/after decoding. Event 904
reports cumulative successful artwork bitmap creation/deletion operations
during enabled logging, using atomic increments. The analyzer exposes failed
allocation/deletion results separately. Counters are not a complete live-handle
inventory across disabled intervals or handles predating logging. RAM values
do not identify per-process allocations.

The capture loses 9.39 MiB free during playback and releases 18.86 MiB during
shutdown/disconnection. Static review found cleanup for replacement, rejected
results and retirement. A failed deletion is a possible retention path: the
original clear routine discards display state regardless of DeleteObject's
result. That result was not captured previously, so this is not established as
the cause. The new trace records it without changing ownership based on a
hypothesis. No memory leak resolution is claimed.

DAB IPC failures follow ACC OFF; navigation media-text failures follow power-off
and Bluetooth disconnect. Their active-session impact is unproven, and they are
not suppressed. Mixed narrow/wide Micom prefixes remain an unresolved logging
readability issue; no heuristic conversion of native argument pointers was added.

## Full successor and checks

All 1,919 MAX20 paths remain; 1,915 are byte-exact. Only AppMain, Blue, CmnDll
and version change. CmnDll's runtime instructions remain byte-exact: only one
UTF16 header character and checksum change. Saved settings, background repaint,
CREATE_NEW session files, kernel, MCU input, DBoot and all earlier fixes remain.

Actual MIPS tests cover arguments/dynamic targets, original delay slots, v0/v1,
nonvolatiles, LastError, disabled paths, failed GDI calls, native bitmap
retirement, source table, inherited navigation, durable config/rebase, file
preservation and counter-aware analysis. Native storage, touchscreen output,
actual overhead and sustained RAM behavior still need a car capture.

Use fresh stages in the established authoring workspace:

```powershell
$env:PYTHONPATH="$PWD/tools/python-libs;$PWD/tools"
python tools/prepare_debug21.py
python tools/prepare_verify21.py
python tools/prepare_package21.py
python tools/build_max21.py --output build/max21-metrics-development-FRESH
python tools/verify_max21.py --build build/max21-metrics-development-FRESH
python tools/package_max21.py --stage build/max21-metrics-development-FRESH
```

Owner comparison: continuously enabled logging for five minutes on the same
track, five minutes of track changes, several source switches, then disconnect
and shutdown. Compare decode phases, RAM snapshots and successful create/delete
counts relative to that continuous interval. Original packages/backup are intact.

Final stage: `build/max21-metrics-development-01`. All 247 checks pass, including
seven native lifetime parity cases supplementing the main 240-case suite.
Independent LGU decoding, separate pinned PC extraction, all member hashes,
ZIP CRCs and 53 frozen source pins pass. The delivered analyzer CLI also passes
a smoke test separating poll counts, global memory and elapsed timings.
LGU: 52,145,390 bytes; SHA256
`59d69239fb82f74b9bd42ae4b31cdf98aeeed18e191983d06ac0bea47d67e704`.
Deliveries: `build/maxmade-7.0.6.MAX21/upgrade.lgu` and
`build/maxmade-7.0.6.MAX21.zip`. No car flash or public release was performed.
