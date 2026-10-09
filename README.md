# MediaNav MAXmade — 7.0.6.MAX03

A combined update for the original Renault / Dacia MediaNav, based on the **7.0.5.MD** conversion. MAXmade includes the new Bluetooth and AppMain applications and the existing navigation corruption fix in one **upgrade.lgu**.

[Download upgrade.lgu](Upgrade_706MAX03_MAXmade/upgrade.lgu) · [Package details and checksum](Upgrade_706MAX03_MAXmade/README.md) · [Previous FavreMod guide](Upgrade_705MD_FavreMod/README.md)

**Experimental release:** Max reports the audio-delay repair working after replacing the applications through Windows CE. The complete USB update, all eight saved devices, navigation and vehicle functions still need hardware testing. The archive checks have passed; that does not establish a successful installation on every unit.

## What changes?

- **Bluetooth audio:** includes the buffer repair that resolved the delay in Max's application test.
- **Eight saved Bluetooth devices:** the saved-device list supports eight pairings across two pages. This means eight remembered devices, not eight simultaneous connections.
- **Bluetooth reliability:** includes checked database/list handling and guards for connection, reconnect and deletion.
- **Menus and labels:** reduces repeated work when displaying text while preserving the same text-direction behavior. Overall menu speed has not been measured on the unit.
- **Navigation corruption fix:** includes the unchanged navigation executable from `File_Corruption_Fix`. You do not need to install that separate patch after this update.

All original 7.0.5.MD package paths are retained. The complete original OS, boot, MCU, settings and resources payloads remain included. Blue.exe, AppMain.exe and Version_Info.txt are replaced, and the navigation executable is added. The LGU header and displayed system version both use **7.0.6.MAX03**.

## Compatibility

This project targets the **original MediaNav hardware** covered by the [FavreMod conversion guide](Upgrade_705MD_FavreMod/README.md#confirmed-working-on). Its historical compatibility reports apply to that older package; they are not confirmation that MAXmade has been tested on the same vehicles.

The first full MAXmade installation test is intended for a unit already running **7.0.5.MD**. This package's naming does not make it an official Renault release or firmware for later MediaNav hardware generations.

Check the [open issues](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues) before an installation test.

## Before you start

1. Record your current **Settings > System > System version** and keep your [radio unlock code](Radio_Code.md).
2. Keep your own backup and working Windows CE/DBoot access. At minimum, copy your current `Blue.exe` and `AppMain.exe` from `\Storage Card\System\`, plus `\Storage Card2\DATA\BLUE\sc_db.db`, to your PC. These files preserve the application/pairing state; they are not a complete OS/MCU recovery backup.
3. Save your vehicle settings and radio presets. This full update includes the original settings/resources and can replace them.
4. Use the original guide's USB requirements: **64 MB to 4 GB, formatted FAT32**. Formatting erases the stick, so copy anything you need off it first.
5. Download [upgrade.lgu from Upgrade_706MAX03_MAXmade](Upgrade_706MAX03_MAXmade/upgrade.lgu). Copy **only that upgrade.lgu** to the USB root, not inside a folder. Keep the filename `upgrade.lgu` and safely eject the stick from your PC.

This is a full software update, including the original OS/MCU payloads. A full MAXmade installation and rollback have not yet been validated on the unit.

## Install 7.0.6.MAX03

1. Start the engine and wait for the normal MediaNav interface.
2. Insert the prepared USB stick. The offered update should identify the new version as **7.0.6.MAX03**. If there is no dialog or a different version appears, check the troubleshooting section before proceeding.
3. Accept the update by pressing **Update**.
4. Keep the engine running and leave the USB connected until the update has finished. The original full-update process can restart the unit several times and temporarily display Arabic text while installation continues.
5. Enter your radio code if prompted.
6. Once normal operation returns, remove the USB stick. Open **Settings > System > System version** and confirm **7.0.6.MAX03**.

## Check after installation

- **Navigation:** open the map, confirm GPS and calculate a route. The corruption-fix executable is already included.
- **Bluetooth music:** check play/pause, track changes, audio delay and reconnect after a restart.
- **Calls and contacts:** test a handsfree call, microphone, call audio and your phonebook.
- **Saved devices:** add up to eight phones, check both pages and select each device. Restart normally and check that the entries remain saved. Check deletion/re-pairing too.
- **Other functions:** check radio/presets, USB music, touch, volume, settings and any fitted steering-wheel controls or camera.

When reporting a problem, include your vehicle, previous/current version, phone model and the exact action that failed.

## Access Windows CE with DBoot

The package retains **DBoot 2.0** from the original update. Use it after installation is complete and the update USB has been removed.

1. Start from a **full boot** and watch the Renault/Dacia logo. Waking from standby can skip this screen.
2. When **DBOOT 2.0 - 2017** appears, swipe horizontally across **more than half the screen's width** in one continuous movement. Either direction works.
3. Press **OK** in the Windows CE prompt; **Annuler** cancels it.
4. Wait for the restart into the Windows CE desktop.

The boot-screen gesture window lasts about **five seconds**. If you miss it, retry on the next full boot. If the text never appears, check that DBoot is installed and the unit is not merely resuming from standby. Swiping in the normal interface depends on the installed `dboot.ini` configuration.

To return to MediaNav, double-tap **Redemarrer** and confirm. **Redemarrer WinCE** opens the prompt for another CE restart. The CE boot choice is one-time.

### USB and backup locations in CE

The USB mount is normally **MD**, under **My Device**. If it is missing, try **Start > Programs > USB PHY On**, then reconnect the stick and reopen My Device. The four **Storage Card** volumes are internal storage.

- Applications: `\Storage Card\System\Blue.exe` and `\Storage Card\System\AppMain.exe`.
- Bluetooth pairing database: `\Storage Card2\DATA\BLUE\sc_db.db`.

Copy backups from the unit to USB/PC and check that the copied files are readable.

## Troubleshooting

### No update dialog

Confirm the stick is FAT32, recognized by the unit and contains `upgrade.lgu` directly at its root. Check for an accidental extra extension such as `upgrade.lgu.lgu`. The version should be **7.0.6.MAX03**, which sorts above existing **7.0.5.MD** versions. If the installed version is equal or newer, the normal updater may not offer it. Report the current version if the correct package still does not appear.

### Bluetooth search shows an empty list

Test with a **phone that is not already saved**, keeping its Bluetooth pairing/settings screen open. The original discovery filter favors phone-type devices and excludes already-paired addresses; laptops normally do not appear in this list. Pairing initiated from the phone is a separate useful check.

### Navigation still reports corruption

MAXmade already contains the executable from the old corruption-fix package. Record the exact error and system version and report it in the issues. Including that executable does not guarantee that every map, license or storage problem is resolved.

### Returning to an older version

The [previous FavreMod guide](Upgrade_705MD_FavreMod/README.md) and older packages are preserved for their existing procedures. They are not a verified rollback from MAXmade. The ordinary updater can reject older version numbers; restoring applications alone does not restore the full OS/MCU update.

## Package verification

The [package manifest](Upgrade_706MAX03_MAXmade/build-manifest.json) records all **1,918 member hashes**, the source packages and the matching Bluetooth/AppMain test build. Container CRCs, encrypted ZIP members and extraction with a separate PC tool were checked. All original source files remain unchanged.

`upgrade.lgu` is **38,352,671 bytes**. SHA-256:

```text
6b00c5a0807f1b6f6ad7f211a5a65fdc416232d8176bdcdb93227acf21122145
```

See [SHA256SUMS.txt](Upgrade_706MAX03_MAXmade/SHA256SUMS.txt). Packaging checks validate the file contents; full hardware installation remains experimental.

## Previous release and credits

The original **7.0.5.MD** instructions are preserved in [Upgrade_705MD_FavreMod/README.md](Upgrade_705MD_FavreMod/README.md), alongside the original LGU. The separate [File_Corruption_Fix](File_Corruption_Fix) and [remove_md_super_evo](remove_md_super_evo) packages remain available for the legacy guide.

MAXmade builds on the original [Upgrade_705MD_FavreMod](Upgrade_705MD_FavreMod) conversion and its accompanying navigation fix. Their original contributions remain credited. Special thanks to [KwidTechsolutions](https://www.youtube.com/@KwidTechsolutions1).

The MAXmade changes are listed above and in the [package notes](Upgrade_706MAX03_MAXmade/README.md#maxmade-changes).
