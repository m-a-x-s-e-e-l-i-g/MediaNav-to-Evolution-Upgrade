# Saved USB repeat and shuffle settings

This development validates saved playback settings before restoring them. Valid repeat and shuffle settings keep their exact behavior; invalid values fall back to off. Every earlier improvement and all 1,918 payload paths are carried into the [full development build](../build/usb-resume-modes-development-01/README.md). Only MgrUSB changes versus usb-folders-development-01. No LGU, version bump or release.

## Defect and repair

The original publication helper at `1abac` copies saved DWORDs from player offsets `1ab0` and `1ab4` into both the active packed fields (`291a`, `291e`) and aligned shared fields (`2934`, `2938`). It does not validate either value. A file can have a valid checksum while containing an invalid mode. The original-byte fixture reproduces publication of repeat `ffffffff` and shuffle `10001`; the replacement publishes zero for both.

Repeat values 0–3 mean off, repeat track, repeat folder and repeat all. Shuffle values 0 and 1 mean off and on. The new guard uses unsigned comparisons over the complete DWORD: repeat must be below 4 and shuffle below 2. Every other value becomes zero. Invalid shuffle is not treated as enabled merely because it is nonzero. The eight valid combinations produce exactly the same object bytes as the previous build.

Validation happens when settings are published, after the checked loader accepts the primary or backup resume file. It leaves the loaded blob, checksum and file bytes unchanged, keeping the existing backup/recovery contract. Failed loads do not publish settings. The native object is assumed DWORD-aligned; original unaligned active-field stores and aligned shared-field stores are retained.

The original leaf entry tail-redirects to an 88-byte, frame-free helper at `3fd80`, in previously zero code after READY and before the code section ends. It makes no calls and preserves the original void return and callee registers. No sections, imports or entry point change. The combined exception table retains every prior row and adds one leaf row; relocations are rebuilt and checked at three alternate bases.

Input MgrUSB SHA256: `f57cbfa38453cfac5c25a0d8db4376da5fa46a9ed838caa05985f5840512a6ba`. Written output SHA256: `8c5ee4cec945284936557058da63804f2b3cc0402a814ecf14866329596b163e`.

## Verification

**66,190 new + 6,196 retained written-byte checks pass.** The new checks comprise one original-defect reproduction, 66,008 value/parity/ABI cases, 180 loader/call-site cases and one structural check. The [proof](firmware/usb-resume-modes-development.json) and [manifest](../build/usb-resume-modes-development-01/manifest.json) record all results, output/tool hashes and payload members. All 1,917 other files are byte-identical to the previous development build; all earlier exception rows remain intact.

The new checks cover all 65,536 low-16-bit values, full-DWORD boundaries, 256 deterministic random pairs, all eight valid-mode combinations, neighboring-byte preservation, source-blob preservation, ABI and three alternate load addresses. Three real call-site slices—attach and both resume branches—execute the actual checked loader and new publication guard with primary/backup filesystem fixtures. Missing, damaged and uncommitted `.new` inputs follow the existing failure branches.

Retained folder, sorting, WMA/shuffle, artwork, playlist, encoding, save/load and resume checks run against the new written executable. The sorting suite reruns its current workload and carries the verified original baseline from its hash-pinned manifest. Previous staging, tool sources and proofs are preserved.

This is a saved-state publication repair. It does not change the legacy repeat IPC setter, other state writers or thread snapshot ownership, and does not establish a particular native crash cause. Filesystem calls use fixtures; hardware playback, native loading/unwind and full installation remain unverified. Save-error feedback is another useful reliability investigation.

Build tools: `tools/patch_usb_resume_modes.py`, `tools/verify_usb_resume_modes.py`, `tools/build_usb_resume_modes_development.py`.
