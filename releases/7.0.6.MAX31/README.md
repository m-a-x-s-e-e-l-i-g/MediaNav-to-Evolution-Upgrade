# MediaNav MAXmade 7.0.6.MAX31

[Download the complete upgrade.lgu](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX31/upgrade.lgu)

The owner authorized publication on **20 October 2026**. **MAX31 has not yet
been installed/tested in the car.** This release targets the false recovery
prompt reported during DBoot use on MAX30. The quick CE reboot remains pending
physical validation. The exact verified LGU is published without rebuilding.

## DBoot recovery correction

MAX29/MAX30 set a startup marker before DBoot, but only normal application
readiness cleared it. Intentional CE desktop entry skips that readiness. The
next ROM launch therefore interpreted the remaining marker as startup failure
before DBoot could consume the native one-shot StartWinCE request. The prompt
alone does not establish incomplete installation or corrupt files.

MAX31 recognizes that intentional request before the stale marker. The native
DBoot desktop path retains its registry and MGR1 initialization, consumes the
one-shot desktop request, and clears only the startup marker. Genuine recovery
uses a separate exact desktop command and retains the failure marker. Its PE
entry bypasses marker I/O so read-only/damaged marker storage does not prevent
native desktop initialization. Missing DBoot falls back to ROM Explorer.

The recovery menu previously launched Explorer directly, skipping DBoot's
initialization. This is a concrete code difference that could contribute to the
reported quick reboot; **a car test is still required to establish the result**.
There is no new reboot, formatting operation, MCU command or watchdog bypass.
Actual installer STOP/error handling and readiness checks remain enabled.

## Complete payload and exact download

All **1,920 MAX30 paths remain**: 1,915 are byte-identical. Exactly five change:
NK.bin, System/dboot.exe, Recovery.exe, System/CmnDll.dll (diagnostic revision
and checksum only), and System/Version_Info.txt. The
[baseline comparison](public-baseline-comparison.json) records every changed
hash. Updater/MCU, audio, navigation and Bluetooth/iPhone artwork behavior are
unchanged from MAX30. All earlier MAXmade features are included.

- Size: **52,310,420 bytes**.
- SHA-256: `521e9192c1dea4ae4d64d5346db0cc441c638e6156b7227af8a64eac162979b3`.
- [Checksum](SHA256SUMS.txt), [build manifest](build-manifest.json),
  [member plan](member-plan.json) and [source manifest](source-manifest.json).
- GitHub Releases contains only the complete upgrade.lgu. Frozen developer
  sources/evidence are in this folder; no private logs/backups are published.
- Follow the [installation guide](../../README.md#before-you-start).
  Intermediate MAX versions are not required. MAX31's physical installation,
  starting-version routes and broader hardware compatibility remain unverified.

## Validation and physical test status

[Device status](device-status.json) records release authorization separately
from physical testing. [1,137 combined offline cases](verification.json)
include [439 boot cases](boot-recovery-verification.json) and inherited MAX30
feature cases. The [inherited verification](inherited-verification.json) records
which prior results were reused and their behavior-byte equivalence checks.
The final recovery-only entry edit reran native DBoot WinMain/CE round trips,
PE-entry and marker faults, and read-only recovery entry. Other unchanged
boot/menu/updater results retain explicit provenance rather than being claimed
as freshly executed against changed bytes.

[Package verification](package-verification.json) and
[final delivery verification](final-delivery-verification.json) record separate
LGU decoding/extraction, member hashes and ZIP readback. All **115 frozen source
pins** match. Build-time car_tested=false records remain accurate.

Physical testing must confirm intentional CE entry, return to normal MediaNav,
normal cold startup, absence of the false warning, and whether CE stays open.
No power-loss or intentional installation interruption is required for this test.

## Known installer and hardware limits

The quick CE reboot, iPhone/Spotify artwork and the reporter's approximately
ten-second MICOM restart are not confirmed resolved. Offline execution is not
hardware validation. Rollback, injected installer failures and compatibility
with other units remain unverified; see [test-device feedback](../../docs/test-device.md).

Automatic Card2 maintenance above saved counter 175 still has unchecked native
backup/format/restore calls; a prior scan marker can select formatting without
a verified backup. Native formatting may report success after failures, and
some extraction/worker waits have no deadline. These inherited gaps are **not
fixed by MAX31**. First installation begins in the previously installed
updater. Kernel publication is not power-loss atomic; damaged storage, a
nonbooting kernel, bootloader or MCU failure can prevent recovery. This release
does not guarantee protection from every lockout.

The issue #56 USB repair kit retains its own original pinned payload and is
not a MAX31 repair kit.

## Developer material

The frozen [build recipe](build-sources/tools/build_max31.py),
[packager](build-sources/tools/package_max31.py),
[native boot edits](build-sources/tools/boot_recovery31.py),
[recovery program](build-sources/tools/recovery31.c) and
[boot verifier](build-sources/tools/verify_boot_recovery31.py) preserve exact
build dependencies. Cumulative recipes require pinned earlier stages and native
PC tools; this is not a claim of a single-command clean-checkout reproduction.
