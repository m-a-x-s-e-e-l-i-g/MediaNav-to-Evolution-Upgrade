# MediaNav MAXmade 7.0.6.MAX30

[Download the complete upgrade.lgu](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX30/upgrade.lgu)

The owner installed MAX30 from MAX26, reports normal operation as far as known,
and approved publication on **18 October 2026**. **iPhone album art has not yet
been tested.** The individual checklist results were not separately reported.
The exact tested LGU is published without rebuilding it.

## Changes since the public MAX18 release

- Saved Debugging On/Off in System Settings; automatic USB logging after normal
  startup when enabled, with separate session filenames.
- Corrected Settings row redraw and Bluetooth source-settling timing.
- Artwork acquisition/display diagnostics and a local AVRCP thumbnail-capability
  advertisement change intended to improve iPhone negotiation. Physical iPhone
  success remains unconfirmed; this is not advertised as a solved iPhone bug.
- Navigation action and five-second RAM/native-pool measurements; inactive cache
  fields are no longer interpreted as valid cache usage.
- Quieter GPS/native-text logging and omission of empty navigation UI summaries,
  with reserved queue capacity against routine diagnostic flooding.
- Service-window allocation and failed RVC/GPS configuration-write guards. These
  do not establish that the reporter's MICOM restart problem is fixed.
- Independent recovery selection in the ROM launcher, DBoot/updater startup
  guards, a desktop action on installer errors, and readback/backup checks when
  publishing first-stage NK/updater files.
- Previous UI, navigation, Bluetooth and media changes remain included.

## Complete payload and exact download

The public MAX18 baseline has 1,919 files: all remain, 1,907 byte-exact and 12
changed; Recovery.exe is added, giving **1,920 files**. The
[complete public-baseline comparison](public-baseline-comparison.json) explains
every changed hash. MAX30 also retains all 1,920 immediate MAX29 paths, with
1,917 byte-exact and only CmnDll.dll, nngnavi.exe and Version_Info.txt changed.

- Size: **52,306,828 bytes**.
- SHA-256: `5e649714c20503cd9fb738d54aa836577d73714f888b05d718c06a2acc6550d7`.
- [Checksum](SHA256SUMS.txt), [full build manifest](build-manifest.json) and
  [immediate predecessor plan](member-plan.json).
- GitHub Releases contains only upgrade.lgu; sources/evidence are in this folder.
- Follow the [normal installation guide](../../README.md#before-you-start).
  Intermediate MAX versions are not required. The physical test reported here
  was from MAX26; first-install and other hardware routes are not separately
  certified by that result. Do not interrupt installation to test recovery.

## Validation and what remains open

[Device status](device-status.json) records the owner's exact release approval
and the untested iPhone case separately from [996 offline checks](verification.json).
The [inherited verification](inherited-verification.json),
[boot verification](boot-recovery-verification.json),
[quiet-logging verification](quiet-logging-verification.json) and
[final runtime regression](final-runtime-regression.json) record which tests
were run and which results were reused for byte-identical components.

[Package verification](package-verification.json) and
[final delivery verification](final-delivery-verification.json) record independent
LGU decoding/extraction and all member hashes. The
[source manifest](source-manifest.json) pins all 110 build-source snapshots.
Build-time fields such as car_tested=false and car_test_pending=true remain
unchanged historical records; device-status.json records the later owner report.

The [recorded-data replay](recorded-metadata-replay.json) predicts 46.75% fewer
retained records for GPS/empty-UI filtering in the earlier eight-session input.
That is not a physical CPU, speed or RAM improvement measurement. Raw owner logs,
private backups and locations are not included in these release records.

### Known installer and hardware limits

The normal owner test does not exercise deliberate failure recovery. First
installation still begins in the previously installed updater. Separate NK
rename/publication operations are not power-loss atomic, and restoration may
fail on damaged storage. Bootloader/MCU or a nonbooting kernel can prevent CE
recovery from running.

Automatic Card2 maintenance above saved counter 175 still uses unchecked native
backup/format/restore calls; a prior scan marker can select formatting without a
verified backup. The native formatter can report success after format/mount
failure, and some extraction/worker waits lack deadlines. These audit findings
are **not fixed by MAX30**. Independent recovery does not make those operations
transactional and does not guarantee that every hang selects recovery next boot.

The reporter's approximately ten-second MICOM restart remains unresolved.
GPS antenna/reception trouble is suspected for that report, not proven repaired
by software. iPhone artwork, broader device compatibility, rollback and injected
installer-failure recovery remain unverified. See the
[test device](../../docs/test-device.md) and [open issues](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues).

The earlier issue #56 USB repair kit pins its own original kernel/payload;
it is not a MAX30 repair kit.

## Developer material

The [frozen MAX30 packager](build-sources/tools/package_max30.py),
[build recipe](build-sources/tools/build_max30.py),
[native boot/recovery edits](build-sources/tools/boot_recovery29.py),
[first-stage replacement guards](build-sources/tools/first_phase29.py) and
[log analyzer](build-sources/tools/analyze_debug_logs30.py) preserve the tested
source dependency set. These are cumulative development recipes requiring
their pinned earlier input stages and native PC packing tools, not a claim
that one command from a clean checkout reconstructs every intermediate LGU.
