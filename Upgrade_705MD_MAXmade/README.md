# MediaNav MAXmade — 7.0.6.MAX03

Experimental combined full update for the original MediaNav running the
7.0.5.MD conversion. Full LGU installation has not yet been tested on a unit.

## Based on the original package

All 1,917 files from [Upgrade_705MD_FavreMod](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/tree/main/Upgrade_705MD_FavreMod)
are retained. Blue.exe, AppMain.exe and Version_Info.txt are replaced.
The original OS, boot, MCU, resources and settings payloads are preserved byte
for byte. This follows the complete original update route, rather than the
two-file apps-only candidate route with a missing firmware.hex.

## MAXmade changes

- Blue.exe: eight saved Bluetooth devices, checked database I/O, list
  acknowledgement, delete guard and the Bluetooth audio buffer repair.
- AppMain.exe: eight-device list/two pages, bounded list copy, matching list
  acknowledgement, connection/reconnect guards and equivalent faster label scan.
- The existing File_Corruption_Fix nngnavi.exe is included unchanged at
  Storage Card4/NNG/nngnavi.exe. A second navigation patch is not needed to
  supply that file. Its internal changes were not authored by MAXmade.
- LGU header and displayed Version_Info.txt both read **7.0.6.MAX03**.

Eight refers to saved pairings, not simultaneous Bluetooth connections.
The audio repair has been reported working by Max after replacing the two
applications through Windows CE. That feedback does not validate this full
LGU installation, all eight slots or every vehicle function.
The original phone-type discovery filter remains: a laptop is not a useful
test of the new-phone list.

## Package checks

- **1,918 files:** the complete original payload plus the navigation executable.
- Only three original files changed; one file added.
- Both applications exactly match the checked BT8T03 pair.
- Header/size, encrypted ZIP CRCs, member hashes and separate PC extraction
  verified; original source files unchanged.
- `upgrade.lgu`: **38,352,671 bytes**, SHA-256 `6b00c5a0807f1b6f6ad7f211a5a65fdc416232d8176bdcdb93227acf21122145`.

See build-manifest.json for all original/output member hashes and version
recognition checks. These checks validate the package bytes, not a physical
installation or recovery route.

## Before a hardware test

Keep your radio code, existing Windows CE/DBoot access and your own backup.
The package runs the full update, including the original OS/MCU payloads;
it is not a lightweight daily application swap.
It can overwrite source-package settings/resources as the original update does.
Keep your current Blue.exe, AppMain.exe and sc_db.db separately. Package-original
files are not a backup of your unit, and a full update rollback is unvalidated.

Use only hardware already covered by the original 7.0.5.MD conversion guide.
Native version recognition, installation/reboot, navigation, settings retention,
all eight pairings and vehicle controls must be checked before this becomes
the guide's recommended update. Existing updater copy/cleanup weaknesses are
preserved; they were not repaired by combining the files.

## Experimental installation test

1. Save the backups and radio code above. Prepare a FAT32 USB stick using the
   original guide's requirements. Copy only this folder's **upgrade.lgu** to
   the USB root, not inside a folder, and safely eject it from the PC.
2. Start the engine and wait for the normal MediaNav interface. Insert the USB.
   The proposed new version should be **7.0.6.MAX03**. If no update is offered
   or the displayed version differs, stop and report that before changing files.
3. Accept the update. Keep the engine running and USB connected until it has
   finished. The full original update can restart the unit several times and
   temporarily show Arabic text; follow the existing guide's completion steps.
4. Enter the radio code if prompted. Once normal operation returns, remove
   the USB. Check **Settings > System > System version**: **7.0.6.MAX03**.
5. Start navigation and check the map and a route. This package includes the
   existing corruption-fix executable; do not install its separate LGU afterward.
6. Check Bluetooth music/delay, a handsfree call, contacts, reconnect and both
   device pages. Test eight saved phones and retention after a normal restart.
   Also check radio, USB music, touch, volume, settings and vehicle controls.

Keep the original guide's older packages available. They are preserved for
reference and existing supported procedures; reinstalling an older version
after this build is not a verified rollback and can be rejected by version checks.

## Credits

Based on the original 7.0.5.MD conversion distributed in Upgrade_705MD_FavreMod
and its accompanying File_Corruption_Fix. Existing contributors retain credit.
MAXmade maintains this combined build and the Blue/AppMain changes listed above.
