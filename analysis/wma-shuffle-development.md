# WMA metadata, shuffle cancellation and waiting

Follow-up: [USB sorting development](usb-sorting-development.md) now carries this complete payload forward and implements the filename-processing candidate through streaming comparison. The audit below remains a snapshot of this WMA/shuffle build.

The current full development payload is [development-02](../build/wma-shuffle-development-02/README.md). It retains all **1,918** previous paths and earlier improvements. Only `MgrUSB.exe` changes versus artwork-playlist-development-01; the other 1,917 files are identical. No LGU, release, version change, GitHub publication or native firmware execution.

Intended benefits: damaged WMA song information is handled safely, cancelling shuffle discards the unfinished list, and shuffle spends less time deliberately sleeping while building that list. Actual device speed and behavior still need hardware testing.

## WMA metadata

The original ASF reader limits a name read to 100 bytes but subsequently copies the **original declared length** into a 256-byte temporary array. The new byte fixture reproduces a 302-byte copy. It also accepts successful short `ReadFile` results and does not consistently check seeks or containment within individual metadata objects.

The rewritten body at `18328..18f08` uses explicit position/limit state:

- Header GUID, reserved bytes, size and child count are checked before traversing metadata. Each child must fit inside the ASF header; each field must fit inside its child.
- Reads require both a nonzero API result and the exact requested byte count. Seeks use checked absolute positions and must return that position. A failed or short operation stops parsing and clears incomplete metadata.
- Descriptor names are compared only when they have the appropriate bounded length for `WM/ALBUMTITLE`. Other names are skipped within the current object. There is no large name copy or unterminated name comparison.
- Title, artist and album use complete UTF16 units and the existing **30-unit WMA limit**, with an explicit terminator. Cutting a longer field between surrogate halves omits the dangling high surrogate. This is not a new general Unicode validator.
- Existing tag flags, context construction, stack frame, cookie, destructor and destructor funclet are retained. The C++ exception IP map now has two ranges: constructed context throughout the new body, then no cleanup ownership at the explicit destructor call. These addresses relocate with the image.

The reader retains the previous maximum of 16 header children and does not add new ASF metadata types, codecs or artwork support. Header positions are limited to signed 32-bit seek offsets; large/high-QWORD headers are rejected. This is a bounded metadata reader, not a general ASF decoder. Microsoft's [ASF structure documentation](https://learn.microsoft.com/en-us/windows/win32/medfound/asf-file-structure) describes its containing header/object structure.

## Shuffle

The original pool returns -1 when shuffle is switched off or USB is removed. Its builder ignores this result, adds the full folder count and leaves a partial array published. The original-byte fixture retains count four after cancellation in the first folder.

The new builder and wrapper:

- Validate folder and track ranges, total capacity (5,000), anchor and traversal budget before using the pool. All remaining direct pool calls use the same guard.
- Stop immediately on pool failure, propagate failure and clear partial count, cursor, pointer and folder range. The wrapper also resets active/requested shuffle state and publishes the outcome afterward using the existing shared-memory writer.
- Publish the array pointer/count only after all folders complete, with an additional cancellation check after the final folder-iterator call.
- Guard five next/previous/repeat selection sites with active flag, pointer, count and cursor checks. An incomplete list follows the existing sequential path.
- Retain the same random-selection algorithm, current-song anchor and contiguous folder groups. A seeded original/new fixture produces exactly the same order.

The shared writer is a plain memcpy, **not a mutex-protected transaction**. These checks address observed control flow and partial-list exposure; they do not prove thread-atomic publication or eliminate check/use races under arbitrary native interleavings. Native worker/scan/audio-event interaction remains open.

## Performance

The pool previously calls `Sleep(1)` on every fill and selection iteration. It now calls `Sleep(1)` once per 32 iterations and `Sleep(0)` otherwise. All per-track cancellation tests remain. [Microsoft's CE Sleep documentation](https://learn.microsoft.com/en-us/previous-versions/ms913106%28v%3Dmsdn.10%29) describes a zero-duration sleep as relinquishing the remainder of the time slice; periodic timed sleeps are retained.

| 5,000-song fixture | Previous | Current |
| --- | ---: | ---: |
| `Sleep(1)` calls | 9,999 | 313 |
| `Sleep(0)` calls | 0 | 9,686 |
| Song order | Same seeded order | Same seeded order |

This is roughly 97% fewer **timed wait requests**, not a measured 97% speedup. Scheduler resolution, random generation, scanning, decoding and other threads affect actual elapsed time. The builder also reuses the folder count it already queried instead of querying it again after each pool.

The [repeated-work audit](firmware/media-repeat-work-audit.json) pins unchanged code for the next performance work:

- Sorting builds two filename representations for every comparison, clears 2,072 bytes through memset and another eight bytes through stores. Caching those representations per catalog generation and locale is a concrete next target.
- The next-folder iterator repeatedly scans the folder table and calls `Sleep(1)` within that scan. Its traversal/mutation contract needs checking before changing it.
- The progress timer requests 500 ms intervals and each update copies 3,670 bytes of shared status. The same routine is called by other playback paths. Skipping or narrowing that copy requires a freshness/ownership contract; its interval and copy remain unchanged.

## Verification and artifacts

**384 new and 1,104 retained written-byte cases pass** on the complete payload readback. New checks cover Unicode/long WMA fields, every header-prefix truncation, object/field boundary mutations, all read/short-read failures, seek failures, cancellation at each yield and after each folder, invalid counts/anchors/modes, five actual selection branches, original defect reproduction and three alternate image bases. Four exception-map checks verify the original and relocated metadata; they do not execute native exception unwinding.

The previous artwork, pixel processing, playlist reader, ID3, encoding/cache, resume persistence and input/resume checks are rerun. PE sections, imports and entry point stay unchanged. Eight helper unwind rows are added, combined relocations rebuilt, previous helper bytes preserved, and restoring the recorded edits/directories produces the exact prior input.

- [Full manifest](../build/wma-shuffle-development-02/manifest.json)
- [Byte evidence](firmware/wma-shuffle-development-v2.json)
- Current MgrUSB SHA256: `1a9b713e873f5669174b483771445dcd3a4d4613dba844ebe45085beaee29110`
- AppMain SHA256 remains `236ef346d273b3529a3318b17219b8135eb8bb5184bd34178337e8a72df5902c`.
- The public MAX03 LGU remains unchanged, SHA256 `6b00c5a0807f1b6f6ad7f211a5a65fdc416232d8176bdcdb93227acf21122145`.

Reproduce in a fresh output directory with `py tools/build_wma_shuffle_development_v2.py`; the script refuses to overwrite a prior build. `py tools/inspect_media_repeat_work.py` regenerates the repeated-work audit. Native CE loading/unwinding, scheduler/concurrency, decoder/display and the carried-forward storage/installer work still require device checks.

Development-01 is superseded because it retained the old exception IP map. Its normal tests passed, but it is not the current payload. Development-02 is built directly from the verified artwork-playlist input with the corrected map; previous files and evidence are retained.
