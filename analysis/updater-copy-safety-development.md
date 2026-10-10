# Installer copy safety — development prototype

Implemented on 9 October 2026 following the [upgrade-stall investigation](upgrade-stall-investigation.md). This repairs specific post-restart copy/error-handling paths; neither GitHub #7 nor #15 is established as fixed. No firmware has been executed natively, unit changed, LGU created or release published.

Latest complete staging: [updater-copy-safety-development-02](../build/updater-copy-safety-development-02/README.md). It contains **all 1,918 previous-release paths**, including existing Bluetooth/audio/navigation improvements and English UI development. **1,914 files are byte-identical to published MAX03**; only UpgradeManager, dboot, dmenu and cereboot differ. Version stays 7.0.6.MAX03 because this is internal staging, not a release. Development-01 is superseded and lacks the final disabled-touch-target check.

## Implemented behavior

- Every application/settings copy checks CopyFileW, opens source and destination, compares file sizes and reads matching 4KiB chunks back. Failures, short/mismatched reads, unexpected EOF, different bytes, directory-creation errors and enumeration errors propagate to the worker.
- Staged payload and settings-backup files are not deleted during copying. Extraction receipt is excluded from ordinary copying and remains in staging. Version_Info is excluded from traversal and copied/verified only after the other staged files pass.
- Failure exits the installer worker before original staging cleanup or normal startup continuation. Main UI remains available to display an English error and failed path. The existing monitor/power behavior is retained; this is not a new forced reboot or controller timeout.
- The error screen fills its own black background and draws text without external images or language resources. Dedicated phase 3007 disables the original hidden Start/Cancel hit targets, including failures before copying begins.
- Existing `scan_done_flag.bin` during pending-install startup fails closed with error 5001. It no longer triggers the original branch that formats settings and deletes the backup. This is a recovery pause, not proof that the backup is complete or permission to resume automatically.
- Missing extraction receipt stops with error 5002 instead of discarding staging. Reported formatter failure stops with error 5003; unavailable storage-volume directories stop before the copy helper can create substitute ordinary directories.
- Destructive pre-copy navigation deletion is skipped. Verified overwrites install replacements while retaining current files until copying starts. Failed CopyFile can still partially mutate a destination; no atomic rollback is claimed.
- Final-copy progress draws exactly ten cells, replacing the original eleven-cell/off-by-one loop. Only verified bytes advance progress; it is capped below completion until the version file also passes readback.

## Code and validation

[Patch generator](../tools/patch_updater_copy_safety.py), [instruction verifier](../tools/verify_updater_copy_safety.py), [full development builder](../tools/build_updater_copy_safety_development.py).

Pinned English input updater SHA256: `bb6989e2446e95c6d93500ba27d1df7c3450697146c181afe581521dbad17676`. Latest candidate SHA256: `22ebd96233a121935ac985ae7b667ed8a2f11cc8a47757c3d3ea25753fb06e73`. Original fixed ImageBase, entry point, imports, original sections and their non-text contents remain. Reviewed call sites and one progress-draw range change; two PE sections and thirteen new function-table rows are appended. Independent restoration of every reviewed original-body edit matches the input exactly. Native CE loader and unwind behavior remain untested.

**93 passing instruction/API-fixture cases** on the written updater cover chunk boundaries, successful copies with corrupted/truncated output, failed copies with partial destination changes, both read/open/close directions, directory faults, original caller cleanup, real backup→format→restore caller bytes, fresh-process retries, missing receipts/mounts, ambiguous settings state, persistent error drawing, disabled error-screen touch targets, ten-cell progress, path/recursion bounds and Unicode names. All **1,918 real previous-release pathnames** traverse successfully using small representative contents; this is a layout smoke test, not an end-to-end copy of those files' complete contents.

Six additional late navigation/version failure cases and six fresh-process retries pass against the written output: [late-failure evidence](firmware/updater-copy-safety-late-failures.json). A late version failure still retains staging and prevents caller cleanup; a retry after the fixture fault clears succeeds.

Existing English validation also passes: 114 loader cases, 19 UTF16 translation slots, 77 English/LTR warning cases, two Cancel draws and two load-failure cases. Full staging hashes and exact previous-member preservation pass. Fixture EOF handling follows Microsoft's [Windows CE FindNextFile contract](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms889873%28v%3Dmsdn.10%29); the [CE find-data layout](https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms892378%28v%3Dmsdn.10%29) agrees with the inspected original offsets.

The [manifest](../build/updater-copy-safety-development-02/manifest.json) stores exact edit recipes, traces and all before/after member hashes. To build a fresh internal staging, set PYTHONPATH to tools/python-libs and run `py tools/build_updater_copy_safety_development.py --output updater-copy-safety-development-03`; existing directories are never overwritten. This command creates no LGU or public release.

## Remaining gates

This is a concrete bounded safety improvement, **not the complete [installation transaction](update-repair-plan.md)**. Physical CE load/display/sharing locks and storage faults remain untested. Readback can reflect filesystem cache and does not prove NAND durability. API calls that never return can still stall. The old five-minute monitor and underlying formatter's unreliable return semantics remain. Merely finding a volume directory is not proof of a mounted partition; a real storage-manager check still needs implementation.

The zero-byte extraction receipt still lacks a validated full manifest. Settings backups have no durable per-file manifest/commit; ambiguous interruption pauses for recovery rather than automatically formatting/retrying. Retained TFAT backups can remain after success and consume space. Skipping pre-delete can leave obsolete navigation files; controlled cleanup needs review after native testing. OS/updater replacement and MCU/NOR/DAB phases keep original behavior. A bug in #7 before the new updater runs remains outside this change.

No install instructions or release artifact are provided for this prototype. The next full release must retain every previous-release file and pass native installer/recovery tests before this is presented as a fix for affected units.
