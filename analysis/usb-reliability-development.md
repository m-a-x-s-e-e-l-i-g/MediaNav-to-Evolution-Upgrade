# USB titles and recoverable playback-state saving

9 October 2026. Internal cumulative development, following Max's “continue work!” request. No release, LGU, version change, publication or native firmware execution.

The full [development payload](../build/usb-reliability-development-01/README.md) retains **all 1,918 previous paths**. Only `MgrUSB.exe` changes versus usb-input-safety-development-01; the other 1,917 files are byte-identical. Earlier Bluetooth/audio/navigation, English installer/DBoot, copy-safety, touch, menu, resume, metadata and playlist changes remain present. Published MAX03 and older development builds remain unchanged.

## What improves

| Behavior | Development change |
| --- | --- |
| Accented/non-Latin MP3 titles decode using the wrong encoding | ID3v2 handlers now pass the frame's declared encoding: Latin1, UTF16 with full BOM, UTF16BE, or UTF8. |
| Cached song information changes incorrectly after a language change | Each mutable 260-byte raw tag slot retains its encoding and bounded byte length; cached conversion uses them. |
| An ID3v1 fallback inherits stale v2 encoding or loses its genre | Legacy slots reset their provenance and retain their actual 30-byte length. A genre selected from the native Unicode table remains intact. |
| A failed save truncates the only saved playback position | Save to `.new`, require exact write/flush/close success, read back and compare every byte, then retain the previous validated file as `.bak` before publishing. |
| Missing/corrupt primary resume file leaves stale state | Load the validated canonical file or the backup, keeping original hidden-file/folder validation and terminating all six text slots. Failed loads clear the blob. Uncommitted `.new` files are never loaded. |

These are reliability repairs. Extra verification adds synchronous I/O; no faster playback or native timing result is claimed.

## Encoding implementation

New MIPS decoder at `3c000` bounds source length and destination to 199 UTF16 units plus NUL. Explicit raw slots reserve bytes 257–259 for a two-byte length and encoding marker; raw payload is capped at 257 bytes. Those slots were already internal mutable 260-byte buffers. File/tag formats and the image allocation remain unchanged. Full UTF8 BOMs are authoritative; UTF16 checks both BOM bytes, endian order and surrogate pairing. A truncated final unit or surrogate is excluded. Invalid explicit encodings clear the decoded text instead of choosing a locale heuristically.

UTF8 conversion queries the required count before writing. Oversized text is reduced to a valid bounded prefix. Latin1 and UTF16 paths do not depend on the locale conversion API. Generic ID3v1 keeps the original locale policy, including CP949 preference for language indices 2/28, with bounded reads. The new 32-entry fallback code-page table matches the original `24cf8` branch table. Native code-page availability and glyph rendering remain untested.

All eleven original direct calls to `24e04` were inventoried: three ID3v1 sites, four ID3v2 sites and four cache sites. The first seven are redirected; the cache block calls a new helper. The ID3v1 genre publication also clears stale raw genre provenance. Actual old parser/cache entry points are exercised, including ID3v1 fallback over stale v2 markers.

Reference encoding definitions: [ID3v2.4 structure](https://id3.org/id3v2.4.0-structure) and [text-frame definitions](https://id3.org/id3v2.4.0-frames). Unsupported compressed/encrypted/grouped frames remain skipped as in the prior development repair. Artwork, ASF and oversized playlist-line handling are separate work.

## Resume storage implementation

The existing **3,180-byte format** and checksum remain compatible. The normal path is `\Storage Card2\USBMusicResume.dat`; siblings are `.new` and `.bak`. Names are built with bounded UTF16 reads. A named mutex uses a zero-timeout wait; busy/failed acquisition returns failure rather than waiting on the UI thread. All five inventoried direct save calls and four direct load calls are redirected.

Save copies the live blob into a local buffer, computes its existing checksum there, and checks it before I/O. The live checksum byte is not mutated. It opens `.new` with CREATE_ALWAYS and exclusive write access, requires a successful WriteFile with exactly 3,180 bytes, then FlushFileBuffers and CloseHandle. Verification reads exactly a 3,180-byte file, checks its checksum and compares every byte with the local buffer, including a fixture where changed bytes deliberately preserve the weak checksum.

Only after verification does rotation change the canonical file. A valid canonical file becomes `.bak`; an invalid canonical file can be replaced when a valid backup is already available. A malformed canonical file without a valid backup is retained and the save fails. Permission/API errors do not masquerade as a missing file. A failed publish leaves the backup available; loading always prefers the canonical file and then `.bak`.

Load performs exact size/read/checksum/close checks and retains the previously repaired native validation for hidden paths, parent folder, six terminators and UI state. The retained loader now accepts any nonzero ReadFile BOOL and also requires successful close. Cleanup failures return failure and clear loaded state. Some existing higher-level save callers still ignore failure; this change protects retained files but does not add user-facing error feedback or retry scheduling.

FlushFileBuffers requests an OS flush; it does **not** establish power-loss durability of filesystem metadata or NAND. MoveFileW requires the destination to be absent; this prototype does not assume an atomic replace operation. Primary sources: [CE FlushFileBuffers](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms890238(v=msdn.10)), [CE MoveFile](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms891388(v=msdn.10)).

## Build and verification

- Input MgrUSB SHA256: `4e89e6dc0cf0130ae1320a19f9c06937f4a256896393ac8667ca1aa477a5ec5a`.
- Output MgrUSB SHA256: `9b2a87dbbef6e9e6d11fa66bd92a687331e7b5fd51104e5588dad157cf623518`.
- [Proof and assembly recipes](firmware/usb-reliability-development.json), [full readback manifest](../build/usb-reliability-development-01/manifest.json).
- [Pinned builder](../tools/build_usb_reliability_development.py), [MIPS construction](../tools/patch_usb_reliability.py), [actual-byte verifier](../tools/verify_usb_reliability.py).

The PE retains its original entry point, image base and old section bodies outside reviewed edits. Two sections, seven exception-function rows and three additional imports are added. The import ordinals are checked against the extracted 7.0.5.MD ROM: FlushFileBuffers 175, MoveFileW 163 and DeleteFileW 165. The original import descriptors remain present. Absolute code/data/pdata pointers have relocations; checks run at three alternate image bases. Restoring the reviewed original-section edits yields exact old section bytes.

Written-byte verification covers **309 new cases**: 119 encoding cases, 27 cache cases, 51 real ID3 parser/fallback cases and 112 persistence/failure/interruption/bounds cases. **419 retained cases** cover ID3 frame bounds, paths/attributes/suffixes, whole-unit copies, three playlist readers, relocation and resume/rematch. Structural PE/import/pdata and full-payload readback checks are additional. The interruption corpus stops execution at individual fixture API boundaries and loads retained file bytes in a fresh interpreter. It proves behavior of these bytes with the declared fixtures, not physical power-cut recovery.

## Remaining limits

Not an installable update. Native CE loader/unwind, code-page implementation, storage sharing/flush/rename, thread scheduling, display and timing need testing. The mutex serializes these save/load file operations; other live playback-state mutations are not newly locked, so the local copy is not a proven coherent cross-thread snapshot. The retained checksum is weak and does not establish content authenticity. Future/unknown malformed primary data is deliberately not deleted without a valid backup. Repeat/shuffle enum normalization, save-error feedback, artwork/ASF bounds and oversized playlist-line consumption remain open.

The carried-forward installer prototype still needs its own native recovery validation. Published main/guide and the MAX03 LGU are unchanged; this work creates complete development staging only.
