# MAXmade 7.0.6.MAX33 — resumable application installation

**Hardware validation: UNCONFIRMED.** No MAX33 physical installation or runtime
test has been reported. The owner authorized publication as the main normal
release on 22 October 2026 before hardware testing. The checks below are offline.

Complete successor to MAX32, including the contributor's iPhone artwork fix and
all earlier features. [Download upgrade.lgu](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX33/upgrade.lgu).

**Validation:** 185 offline MIPS/API-fixture checks passed, with independent
LGU decoding and separate pinned-PC-tool extraction. All 1,921 member hashes
match. Size: **52,493,724 bytes**. SHA-256:
`a61665ad388720d24171d84d986bbb93dbfa354c8f4ecaaaf1be9f51840a6b67`.

MAX33 addresses the stopped application-install path inherited by MAX32.
Physical confirmation that it resolves the reported installation problem remains
pending. The initial firmware stage is outside this application transaction.

## What changes

After extraction, the native updater installs a verified copy of the independent
InstallResume.exe worker and Recovery.exe before settings processing. A healthy
install keeps the existing native settings migration. Its application-copy phase
then delegates to the worker, which copies from retained internal staging.
A different full package retaining both native first-stage boot files is handed
back to the original first-stage handler, so this prelude does not reject later
upgrades just because their version is different. A foreign application-only
remainder is stopped before native migration; its worker is not MAX33's.

Application blocks are checked against the compiled package manifest, written to
a temporary, flushed and read back before publication. Two alternating checked
progress slots record copy and verification progress every 256 KiB. A package
receipt permits automatic resume on the next boot, without replaying settings
formatting. Version_Info is installed last, after separate application verification.
The native updater requires child success AND the completion receipt, matching
version, removed stage and removed pending receipt before normal startup.

For an ambiguous settings checkpoint, the error screen has two separate actions:
Repair / resume update, and Open recovery desktop. Recovery offers explicit repair
or Windows CE. An existing worker transaction resumes automatically once per boot;
software errors open recovery with auto-retry suppressed. Explicit repair preserves
the settings currently present and the old TFAT backup; it cannot prove those
settings were fully restored before the original interruption.

Only the exact known stopped updater may be quiesced. A delegated parent is held,
never killed; active firmware work, running applications, mismatched active boot
components and foreign receipts block the worker. The worker does not flash the
kernel or MCU and has no settings-format action.

Known public source members are removed only after commit. Cleanup is resumable
even after source deletion has begun. Unknown extras and settings backups are
retained; nonempty directories are never recursively removed. Housekeeping errors
may leave public source files behind without blocking a verified installation.
The boot-attempt marker stays until the existing native readiness path clears it.

## Scope and limits

This protects the application transaction once the new updater/recovery/worker
are available. It does not retroactively protect the first legacy extraction,
kernel/self replacement, MCU flashing, native healthy settings migration or every
native maintenance/wait path. The worker's parent wait requires the child to exit;
a hung CE storage call is not cured by journaling. Sudden power loss can still
damage TFAT metadata or storage. This is not a universal anti-brick guarantee.
Offline MIPS/API fixtures do not test CE loading, actual screen rendering, car
power/watchdog behavior, real flash durability or registry/MCU compatibility.

This full upgrade does not replace the separate issue59 completion kit for an
already-incomplete MAX30 installation. That kit and its guide remain unchanged;
no hardware confirmation of that recovery has been received.

## Full payload retained

All 1,920 MAX32 members remain: 1,916 exact, four changed, one added = 1,921.
Changed: UpgradeManager.exe, Recovery.exe, Version_Info.txt and the diagnostic
revision/checksum in CmnDll.dll. Added: InstallResume.exe. Kernel, DBoot, MCU,
Blue.exe including the contributor iPhone fix, navigation and all media/resources
are byte-identical to MAX32. Every previous delivery file is retained as well.

## Unconfirmed hardware checks

Use stable power and leave the USB connected through both normal install stages.
Do not deliberately remove power, corrupt files or erase markers to provoke recovery
in the daily car. Fault injection belongs on a recoverable bench unit.

1. Check the offered version is MAX33, allow the complete install, then confirm
   Settings > System > System version shows 7.0.6.MAX33.
2. Confirm normal startup, radio/Bluetooth/USB, navigation and saved settings.
3. Enter Windows CE via the normal DBoot route and return to MediaNav; check that
   a healthy session does not create a false unfinished-installation prompt.
4. Check USB logging still starts when enabled and older log sessions remain.
5. On a recoverable bench: interrupt only the application transaction, restart,
   verify automatic progress resume and final byte receipts; separately test the
   explicit Repair action and independent Windows CE action after a copy failure.

The LGU has independent Python verification and separate native-tool extraction.
The frozen build-manifest and development records retain their build-time
candidate/unpublished state; device-status.json records the later owner release
authorization. Neither record claims physical validation.
See installer-resume-evidence for tests, manifests, source pins and generated C
headers. Full-payload tests accelerate hashes; native SHA boundaries and actual
native chunk publication are tested separately. Reused baseline helper evidence
is accepted only with exact instruction-byte comparisons.
