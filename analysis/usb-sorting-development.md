# USB filename sorting

Follow-up: [USB folder traversal](usb-folders-development.md) carries this complete build forward and implements the next-folder investigation described below. Earlier sorting code and ordering are retained.

The verified full development payload is [usb-sorting-development-01](../build/usb-sorting-development-01/README.md). It contains all 1,918 previous paths, including every earlier improvement. Only MgrUSB changes versus wma-shuffle-development-02; the other 1,917 files are identical. No LGU, version change or release is being created.

The intended benefit is less work while sorting USB folders and songs. The original comparator builds complete temporary keys for both names on every comparison, even when their first characters already decide the order. It also initializes two 1,040-byte arrays each time.

The replacement reads the two names together. Equal UTF16 units advance directly; at the first difference it uses the unchanged original weight lookup for those two units and returns the same three-way result. An empty name or the end of a prefix stops comparison immediately. The temporary frame falls from 2,112 to 80 bytes. There is no key allocation, persistent cache, or catalog invalidation change.

## Ordering contract

The original order is a lexicographic comparison of unsigned 32-bit words, each `(mapped_weight << 16) | raw_UTF16_unit`. The low half is significant: case and accented characters still break ties using their original UTF16 values. This does not introduce natural/numeric sorting or case-insensitive ordering.

The existing mapper, language flag and deployed LatinSortData.txt remain unchanged. Its signed table search, inclusive upper bound and fallback behavior are preserved. Fixtures use the real table; the original text parser confirms the in-memory layout. Comparisons use an unchanged, loaded singleton fixture. A stable mapping table during sorting is assumed, as required for a consistent comparator in the existing sort path.

Catalog names have 260-unit slots. The unchanged ordering contract covers terminated names of up to 259 units. The new comparator also stops after 260 units for malformed, unterminated slots; equivalence with the original out-of-bounds behavior is not claimed.

## Implementation and verification

The 256-song workload uses the same host sort and 1,418 comparisons on both versions, with identical output:

| Comparator work | Previous | New |
| --- | ---: | ---: |
| Original character-weight lookup calls | 138,964 | 2,836 |
| Interpreted instructions, excluding API implementation | 24,865,859 | 655,807 |
| Bytes passed to temporary-buffer memset | 2,938,096 | 0 |
| Filename unit reads | 419,728 | 10,918 |
| Comparator stack frame, bytes | 2,112 | 80 |

This fixture has 97.96% fewer weight lookups and 97.36% fewer interpreted instructions. The memset count excludes the old comparator's additional two zero-word stores per comparison. Long common prefixes and equal names remain covered separately; no claim is made that every input saves the same percentage. The verifier caches immutable instruction bytes but still counts every executed instruction and lookup.

**3,484 new + 1,488 retained written-byte cases pass**, including 3,469 ordering cases, eight original table-parser cases, five catalog integrations, the workload comparison and structural preservation. The [proof](firmware/usb-sorting-development.json) and [manifest](../build/usb-sorting-development-01/manifest.json) record the exact changes, input hashes, all member hashes and verification results. MgrUSB SHA256: `3b1aabd180c9cc5a681f2e0146535e8cef83f1df564aa0bc1f9f0703f61f4fce`.

The old entry at `173d8` tail-redirects to a 312-byte helper at `3d610`. Its old stack frame is not created. This occupies previously zero bytes after the retained seek helper and before the artwork helper. No sections or imports are added. The combined MIPS relocation and exception tables retain prior entries; the redirected entry describes no old prologue, and the new row describes its own frame.

The unchanged callback and CFileMgr sort dispatch use the same 544-byte folder and 528-byte song records. Byte fixtures execute that dispatch, callback, comparator and subsequent folder-index/parent bookkeeping. The qsort API uses a stable host sorting fixture on both versions; identical duplicate record order in that fixture is not a guarantee about native CE qsort stability.

Ordering checks compare old and new executable bytes to a separate packed-key oracle, including every deployed mapping entry, both mapping states, an alternate trailing table slot, empty/null names, prefixes, maximum lengths, embedded terminators, accents, Cyrillic, Arabic, Korean, Japanese, surrogate units and emoji. Three alternate load addresses are exercised. All previous WMA, shuffle, artwork, playlist, encoding, storage and resume byte suites are run on the written executable.

Device timing, native CE loading/unwinding, real qsort/API behavior, scheduling and full installation still need hardware verification. Offline instruction and lookup counts measure removed work, not a measured device speedup.

The previous [repeated-work audit](firmware/media-repeat-work-audit.json) remains a historical snapshot. Its sorting candidate is superseded by this change; its next-folder scan and shared status ownership observations remain useful. The next performance investigation is the next-folder iterator's linear scans and per-entry timed waits, with cancellation and wraparound retained.

Reproduction tooling: `tools/patch_usb_sorting.py`, `tools/verify_usb_sorting.py`, and `tools/build_usb_sorting_development.py`. The builder verifies all previous member/tool/proof hashes, refuses to overwrite a prior build, and verifies written bytes before producing its manifest. The published guide and MAX03 LGU are preserved.
