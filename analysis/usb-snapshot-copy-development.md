# USB status copying: less work under the existing lock

Follow-up: the repeat/shuffle menu inconsistency identified below is repaired in the newer [USB option snapshot development](usb-option-snapshot-development.md). This report and its proof describe the preceding copy-optimization payload.

This development changes the AppMain snapshot helper used by the bounded USB title and artist consumers. Instead of copying one byte per iteration, it copies four bytes at a time. It uses ordinary word loads/stores when both buffers are aligned, and MIPS merge operations for other alignments. The final one to three bytes still use the byte loop.

The named mutex, nonblocking UI wait, source/destination lengths, NULL-source handling, success/failure return, stack frame and register contract are preserved. A destructive overlapping copy takes the old forward-byte path; other overlap directions produce the same bytes as before. No timer, IPC message, shared-memory layout or bitmap ownership behavior changes.

The complete [development payload](../build/usb-snapshot-copy-development-02/README.md) starts from USB status consumers development-01. It retains all 1,918 files and prior fixes. Only `AppMain.exe` changes; the other 1,917 files are byte-identical, including `MgrUSB.exe`. There is no LGU, version bump, release or GitHub publication.

## Measured work

Actual helper instructions are interpreted with the same mutex fixtures before and after:

| Copy | Previous instructions | New instructions | Reduction |
| --- | ---: | ---: | ---: |
| 520-byte title; source alignment 2, destination alignment 0 | 4,235 | 1,517 | 64.2% |
| 3,670-byte status; both buffers aligned | 29,435 | 8,356 | 71.6% |

These are instruction counts, **not native elapsed time or a measured improvement in screen response**. The aligned path reads and writes exactly 3,670 bytes. Some unaligned merge pairs access an architectural byte twice; every accessed byte remains inside the declared buffer. Physical bus transactions, cache effects and CE scheduling are outside the interpreter model.

## Validation

The new verifier compares old and new helper bytes across all 16 source/destination alignment combinations, short boundaries, the production lengths, tails, four image bases and both directions of overlap. It checks exact output bytes, buffer guards, the architectural read/write bounds, mutex ownership during access, abandoned-lock success, create/wait failure, zero length, NULL source, return values and preserved registers/stack. The updated exception row has the same prolog/frame and an end exactly at the following title helper. The lock/unlock call relocation records are rebuilt, moving the unlock record to its new instruction; all other relocation and exception records, sections, imports and directory locations stay unchanged. The declared edit recipe reverses to the exact prior executable.

Complete title/artist, cover, original-caller and AppMain startup/mapping/IPC/Bluetooth/touch/text checks run on the written payload. MgrUSB is unchanged: its previous hash-pinned 72,494-case regression proof is retained rather than rerun. Check counts and hashes are recorded in [the proof](firmware/usb-snapshot-copy-development.json) and the build manifest.

All **1,753 new copy/structure checks**, **375 retained consumer checks** and **32 original-caller checks** passed. Retained AppMain startup, mapping, relocation, IPC, Bluetooth, touch and mixed Hebrew/Arabic text checks also passed. The separate scalar-reader audit has **520 cases**. AppMain remains 2,010,112 bytes, with SHA-256 `996e318850e1f0da0d1969fae96f9b1f8b808d9e47c32f649cd9d329f646cd46`. MgrUSB retains SHA-256 `cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c`.

The original tools, completed builds and proofs are preserved. `usb-snapshot-copy-development-01-incomplete` contains a stopped verification attempt, has no completed manifest and is not a development baseline. The completed successor is development-02.

## Remaining readers

The [scalar reader audit](firmware/usb-scalar-readers-audit.json) examines six playback-status load sites and the repeat/shuffle menu. Valid single enum values remain in range during a simulated publication between the two merge-load instructions: their high bytes are zero. This does not prove global status coherence or safe mapping lifetime.

The repeat/shuffle menu has a separate reproducible inconsistency. `4f838..4f938` reads repeat four times and shuffle twice during one update. A simulated publication between those reads can leave two repeat choices selected, or no choice selected. Shuffle can similarly show both on and off, or neither. Stable input produces the expected selections for all eight valid combinations. The audit uses actual reader instructions at four image bases, with explicitly simulated publication; this is not an observed native scheduling trace.

That menu inconsistency is **identified, not repaired in this payload**. The next focused repair should take one coherent eight-byte snapshot of repeat and shuffle per menu refresh, release the lock before calling UI code, and preserve the current selection if the nonblocking snapshot fails. Producer metadata construction and other direct readers remain separate work.

Native CE loading/unwind, stack headroom, GDI cross-process handles, concurrency and user-visible performance still require unit testing.
