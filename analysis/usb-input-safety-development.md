# USB save/load, metadata and playlist development

9 October 2026. Max asked to work on the next recommended bugs. This implements the first three priorities in a complete cumulative development payload. No LGU, new version or release is created; no firmware has been run natively.

## Complete payload

[Development directory](../build/usb-input-safety-development-01/README.md), [manifest](../build/usb-input-safety-development-01/manifest.json), [instruction recipes and checks](firmware/usb-input-safety-development.json).

- Previous development: `media-responsiveness-development-01`.
- All **1,918** published MAX03 paths retained, with no missing or added members. **1,917** files are byte-identical to the previous development; only `MgrUSB.exe` changes.
- Bluetooth eight-device/audio-delay changes, navigation repair, English updater/DBoot text, installer copy-safety prototype, touch cancellation, USB library resume and menu processing are carried forward unchanged.
- MgrUSB SHA256: `4e89e6dc0cf0130ae1320a19f9c06937f4a256896393ac8667ca1aa477a5ec5a`.
- PE size, image base, entry point, section layout, imports, original function frames and exception table are unchanged. Reviewed code edits and associated MIPS relocation edits reconstruct the exact input when undone. No new sections or helper entry points.
- The published MAX03 LGU and guide checkout are untouched. This full internal staging is **not an installable update**; the carried-forward updater prototype still requires native loader/storage/display validation.

## Save and load checks

Both resume writers (`1c17c`, `1c2e8`) initialize the output count and require WriteFile success, **exactly 3,180 written bytes** and successful CloseHandle before reporting success. Each opened handle is closed even after a failed or short write. Normal OPEN_ALWAYS and the existing CREATE_ALWAYS variant remain unchanged.

Loader `1be50` closes the read handle once, terminates all six 260-unit text slots after checksum verification and rejects failed GetFileAttributesExW calls before their output can affect acceptance. The attribute word read in the branch delay slot is initialized. Missing saved-folder and attribute failures clear the saved blob. Original read-count, checksum, hidden-file and parent checks remain.

**Limits:** this is failure detection and safer loading, not atomic/durable saving. An interrupted in-place write can still destroy the previous file; there is no new temporary-file commit or FlushFileBuffers. Some callers ignore save failure. The original missing-resume-file path can leave an existing in-memory blob, trailing file bytes remain permitted, and resume repeat/shuffle enum validation is separate work. Power-cut behavior and concurrent restore threads have not been tested.

## Song information

The nine status/fallback copy sites use **518 bytes = 259 complete UTF16 units**, leaving the last unit in the pre-cleared 260-unit destination as NUL. This removes the original 129/259-byte half-character copies and their early truncation. Title, artist, album and filename/resume fallback sites are covered.

The existing ID3 frame parser now:

- Reads ID3v2.4 frame sizes with seven-bit shifts and rejects high bits in the size bytes, following the [ID3v2.4 structure specification](https://id3.org/id3v2.4.0-structure).
- Uses version-dependent extended-header consumption, so a v2.4 header does not skip four additional bytes. It checks length before moving the cursor; compressed v2.2 tags are skipped.
- Checks that the frame header fits, then compares the payload against the remaining bytes **after** that header. Oversized frames stop parsing.
- Dispatches a recognized final frame even when there is no padding afterward.
- Skips unsupported v2.3/v2.4 frame transformations using the declared frame extent. It no longer decodes an unfilled allocation as a compressed payload. Supported v2.4 per-frame unsynchronisation is retained and checked.

**Limits:** this does not replace the shared `24e04` text-encoding converter. Explicit ID3 encoding, BOM/overread behavior, ID3v1/codepage/cache behavior, APIC/PIC artwork and ASF descriptor parsing remain further work. Copy-site checks start with supplied decoded text and do not prove the original converter produces correct text for every encoding. Malformed surrogate sequences are not normalized. Source-file short reads and full ID3 conformance are not claimed.

## Playlist loading

The shared path builder replaces unbounded swprintf with bounded copies into the existing 260-unit buffer. It permits at most **259 units including the combined prefix, folder and filename**, and rejects longer combinations without writing outside the buffer. Rejection returns a fully cleared, non-NULL shared buffer: this keeps the existing WPL wcsncpy caller and the M3U/PLS copy helper safe. An MD absolute-root match now requires a separator or end after `MD`; `\MDfoo` is no longer mistaken for `\MD`.

The suffix helper requires at least four units before subtracting four. The existence helper rejects every DIRECTORY bit combination; INVALID_FILE_ATTRIBUTES also contains that bit and is rejected. Actual M3U, PLS and WPL readers skip missing files, directories, short names and rejected path combinations, while still accepting supported MP3/WMA paths and UTF8 names in the conversion fixture.

**Limits:** this does not redesign the readers' 260-byte fgets splitting, UTF8-only decoding, playlist sorting/count limits, drive prefixes, URLs, slash/dot-component canonicalization or XML entity handling. The original shared-buffer concurrency contract remains. Large real libraries and filesystem behavior require unit testing.

## Verification

`py tools/verify_usb_input_safety.py` interprets the actual candidate MIPS bytes, with strict initialized memory, explicit file/CRT/conversion fixtures and ABI checks. Unknown calls/opcodes fail closed. The build runs the same checks again against written/read-back bytes.

| Checks | Cases |
| --- | ---: |
| Combined paths and boundaries, including nonterminated inputs | 57 |
| File attributes | 131 |
| Short and normal suffixes | 10 |
| Both save writers, partial/failed writes, close failures | 16 |
| Resume loader, exact reads, checksum and attribute failures | 7 |
| Nine actual metadata-copy slices | 54 |
| ID3 versions, length boundaries, final frames, extended headers and flags | 106 |
| Actual M3U/PLS/WPL reader functions | 30 |
| Relocated path/suffix functions at three alternate bases | 6 |
| **New cases** | **417** |

The **25 previous USB resume/rematch checks** also pass on the new written MgrUSB. Unchanged AppMain/Blue/updater and other payload hashes retain the previous checks; those are inherited evidence rather than new native executions.

MIPS relocation verification reads raw relocation words, respecting HIGHADJ's extra companion word. Relocations belonging to removed instructions are replaced by ABSOLUTE entries without resizing blocks; the moved suffix WCSLEN call gets its relocation at the new call site. The strict relocation harness checks actual jump opcodes and runs path/suffix functions at image-base deltas `0x1000`, `0x10000` and `0x123000`. This is not the CE loader or its unwind implementation.

Hardware checks before a release: normal shutdown/restart resume; a realistic mixed MP3/WMA library and long/Unicode names; real tags of each version; all three playlist formats with missing entries; native CE loader/display and the cumulative updater prototype. No on-unit result is claimed.
