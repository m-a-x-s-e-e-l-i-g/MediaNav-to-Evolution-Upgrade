# USB playback-position save failures

This development reports save failures through the existing debug logger and avoids a redundant save attempt after resume loading fails. The [full development payload](../build/usb-save-feedback-development-01/README.md) carries all 1,918 earlier paths and improvements. Only MgrUSB changes versus usb-resume-modes-development-01. No LGU, version bump, release or publication.

## What the caller trace established

The five existing save paths are playback (`1c9c8`), mode reset (`1ea80` in the old reset body), USB removal (`20c3c`), explicit save commands (`224b4`, shared by commands 73/78) and command 7c (`226b8`). They ignore the save result. The retained recoverable-save helper returns failure for write, verification, publication or cleanup errors, but these callers provide no failure diagnostic.

The dispatcher return is a **message-handled flag**. `2271c` discards the return from `21d00` and returns one; `229b8` discards that result too. Changing the inner flag would not notify AppMain that a save failed. This development preserves dispatch and its existing USB-ready/inactive gates. No new onscreen notification is added.

The old no-USB mode-reset path loads resume data, resets repeat/shuffle and calls save even when load failed and cleared the blob. Its existing checksum guard already rejects an entirely empty blob, so the reproduced case does **not** overwrite a file. It nevertheless performs another mutex acquisition, snapshot and validation before failing silently. The new reset helper retains the active mode changes, reports the failed load and skips that unnecessary save.

## Implementation

Four live direct save calls now use a checked outcome wrapper at `3c500` (88 bytes, 48-byte frame). The replacement reset helper at `3c680` (196 bytes, 48-byte frame) uses the same wrapper after successful loading. With a USB attached it retains the original mode reset without file I/O. Missing, damaged, uncommitted or inaccessible resume input leaves files unchanged and skips the save.

The wrapper calls the original recoverable-save algorithm exactly once, preserves its return and arguments, and logs only a zero result. It uses logger `23aac`, category 5, severity 3 and an English message with the caller return address. Severity 3 reaches the original logger's output path independently of its normal category-level filter. The text says “save or cleanup failed” because a release/close error can occur after a new file has already been published. It does not promise that every reported failure means the file was unwritten.

Playback and USB-removal cleanup continue after failure. There are no extra retries, waits or disk writes. The existing `.new`/readback/`.bak` recovery algorithm and saved format stay intact. The wrapper adds a small frame and a diagnostic call on failure; native performance is not measured.

The original reset entry at `1e9fc` tail-redirects to the replacement; its exception row now ends its prolog at the entry. Two new helper rows describe the real prologs. Sections, imports and entry point stay unchanged; all other helper code and exception rows are retained. Strings occupy previously zero data at `41800`/`41900`, outside imports, code-page data and active exception/relocation tables.

Input MgrUSB SHA256: `8c5ee4cec945284936557058da63804f2b3cc0402a814ecf14866329596b163e`. Written output SHA256: `04cdba62cd70a3fe02fc9f0f1c7ddfec79868e2ad500f93173a9e8b8243ff315`.

## Verification

**111 new + 72,386 retained written-byte cases pass.** The new cases comprise 16 wrapper/ABI cases, two original failure reproductions, 27 reset cases, 38 complete message-handler cases, 15 playback/removal cases, 12 alternate-base cases and one structural check. The [proof](firmware/usb-save-feedback-development.json) and [manifest](../build/usb-save-feedback-development-01/manifest.json) record results and member/tool hashes. All 1,917 other payload files are byte-identical to the previous development build.

New cases execute the wrapper, original/replacement reset functions, both real mode setters, the complete message handler, playback/removal save call-site slices and removal status/notification continuation. Fixtures cover primary/backup loading, missing and invalid input, permissions, short writes, flush/readback/rotation/publication failures, mutex failure and cleanup failure after publication. They check the exact return, register/stack preservation, one-save-attempt limit, unchanged live blob, remaining recoverable files, diagnostics and three alternate load addresses.

Earlier saved-mode, folder, sorting, WMA/shuffle, artwork, playlist, encoding, save/load and resume checks run against the new written executable. Original sorting timing-independent counts are carried from their hash-pinned proof while current ordering and workload run again. Earlier tools, proofs and staging remain preserved; public main and the MAX03 LGU stay unchanged.

A separate [nine-case state audit](firmware/usb-save-notification-state-audit.json), using [the audit tool](../tools/audit_usb_save_notification_state.py), covers the shared dialog flag at `+1c`. The legacy save sets it to one even before validating a blob. Skipping that save after failed loading now leaves an initially zero flag at zero. Attached resets and valid loading preserve their former values; the native constructor initializes this flag to one. With a later attached/audio-ready fixture, the original command 7a handler sends its notification once, sets the flag and suppresses a duplicate. The fixture explicitly supplies attachment and audio state; it does not prove the complete native source transition. Readiness notifications after failed reset remain a hardware test item.

Filesystem and logger calls use explicit fixtures. Native CE debug output, hardware playback, loading/unwind, real storage and full installation remain unverified. The existing snapshot is not newly locked against every other playback-state writer. Shared status ownership is a useful separate next investigation.

Build tools: `tools/patch_usb_save_feedback.py`, `tools/verify_usb_save_feedback.py`, `tools/build_usb_save_feedback_development.py`.
