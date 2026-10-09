# MediaNav MAXmade — 7.0.6.MAX03

Upgrade the original Renault / Dacia **MediaNav 4.1.0** to Evolution software, with the MAXmade improvements included in **one USB update**.

[Download upgrade.lgu](Upgrade_706MAX03_MAXmade/upgrade.lgu) · [Package details and checksum](Upgrade_706MAX03_MAXmade/README.md) · [Previous FavreMod guide](Upgrade_705MD_FavreMod/README.md)

## Why upgrade from 4.1.0 to 7.0.6.MAX03?

Compared with 4.1.0, the original upgrade to Evolution software brought these improvements on Max's unit:

- **Smoother Bluetooth music:** less stuttering, quicker phone connection and less waiting when changing songs.
- **Better touch response:** the screen reacts more quickly to taps.
- **Remembered volume:** the unit keeps your volume level when you turn off the car.
- **The Evolution interface:** newer software on your existing MediaNav.

MAXmade builds on that upgrade and adds:

- **Less Bluetooth audio delay:** reduces the lag between playback on your phone and sound from the speakers.
- **Eight saved phones instead of five:** remember more phones without deleting an old one first. The list has two pages; you still connect one phone at a time.
- **The navigation fix included:** the fix for the **“File corruption detected”** error is part of this update. You do not need to install a second update for it.

## Compatibility

This community-made update is intended for the **original MediaNav**, including units running 4.1.0. Use it only on the hardware covered by the original conversion guide.

The [previous guide lists vehicles and versions tested with the original upgrade](Upgrade_705MD_FavreMod/README.md#confirmed-working-on). Those reports do not yet confirm MAXmade compatibility.

Check the [open issues](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues) before an installation test.

## Before you start

1. Record your current **Settings > System > System version** and keep your [radio unlock code](Radio_Code.md).
2. Back up your unit and keep access to its Windows CE desktop through DBoot (see below). Save your current Bluetooth and main application files, plus your saved-phone database. Their locations are listed under [USB and backup locations](#usb-and-backup-locations-in-ce). These copies alone are not a full system backup.
3. Write down your vehicle settings and radio presets; the update can replace them.
4. Use a USB stick of **64 MB to 4 GB, formatted FAT32**. Formatting erases the stick, so copy anything you need off it first.
5. Download [upgrade.lgu](Upgrade_706MAX03_MAXmade/upgrade.lgu) using GitHub's **Download raw file** button. Copy **only that upgrade.lgu** directly onto the USB stick, not inside a folder. Keep the filename `upgrade.lgu` and safely eject the stick from your PC.

This updates the system software as well as the apps. Installing MAXmade and returning to an older version have not yet been tested on the unit.

## Install 7.0.6.MAX03

1. Start the engine and wait for the normal MediaNav interface.
2. Insert the prepared USB stick. The offered update should identify the new version as **7.0.6.MAX03**. If there is no dialog or a different version appears, check the troubleshooting section before proceeding.
3. Accept the update by pressing **Update**.
4. Keep the engine running and leave the USB connected until the update has finished. The original full-update process can restart the unit several times and temporarily display Arabic text while installation continues.
5. Enter your radio code if prompted.
6. Once normal operation returns, remove the USB stick. Open **Settings > System > System version** and confirm **7.0.6.MAX03**.

## Check after installation

- **Navigation:** open the map, confirm GPS and calculate a route.
- **Bluetooth music:** check play/pause, track changes, audio delay and reconnect after a restart.
- **Calls and contacts:** test a handsfree call, microphone, call audio and your phonebook.
- **Saved devices:** add up to eight phones, check both pages and select each device. Restart normally and check that the entries remain saved. Check deletion/re-pairing too.
- **Other functions:** check radio/presets, USB music, touch, volume, settings and any fitted steering-wheel controls or camera.

When reporting a problem, include your vehicle, previous/current version, phone model and the exact action that failed.

## Access Windows CE with DBoot

**Windows CE** is the desktop underneath the normal MediaNav interface. **DBoot 2.0**, included in this update, lets you open it to copy files and make backups. Use it after installation is complete and the update USB has been removed.

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

The navigation fix is already included. If you still see an error, record the exact message and system version and report it in the issues. Other map, license or storage problems may need a different solution.

### Returning to an older version

Returning from MAXmade to an older version has not been tested. The updater may refuse an older version number, and copying back the apps alone does not undo the full system update. The [previous FavreMod guide](Upgrade_705MD_FavreMod/README.md) keeps the older instructions for reference.

## Technical details

For the download checksum, what is included and how the update was checked, see the [package notes](Upgrade_706MAX03_MAXmade/README.md) and [SHA256SUMS.txt](Upgrade_706MAX03_MAXmade/SHA256SUMS.txt).

## Previous release and credits

The original **7.0.5.MD** instructions are preserved in [Upgrade_705MD_FavreMod/README.md](Upgrade_705MD_FavreMod/README.md), alongside the original LGU. The separate [File_Corruption_Fix](File_Corruption_Fix) and [remove_md_super_evo](remove_md_super_evo) packages remain available for the legacy guide.

MAXmade builds on the original [Upgrade_705MD_FavreMod](Upgrade_705MD_FavreMod) conversion and its accompanying navigation fix. Their original contributions remain credited. Special thanks to [KwidTechsolutions](https://www.youtube.com/@KwidTechsolutions1).

The improvements are listed above; the [package notes](Upgrade_706MAX03_MAXmade/README.md#maxmade-changes) describe the individual file changes.
