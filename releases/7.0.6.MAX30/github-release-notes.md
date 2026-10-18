MAX30 was installed in the owner's car from MAX26. The owner reports that everything works fine as far as known and approved this release on 18 October 2026. **The iPhone album-art change has not yet been tested in the car.**

- **USB debugging that stays enabled:** the Settings switch is saved across shutdowns; inserted USB storage receives separate log sessions without overwriting earlier sessions.
- **Settings and source switching:** retain the corrected immediate Settings redraw and Bluetooth source-settling improvements developed after MAX18.
- **More useful, quieter measurements:** navigation actions and RAM remain measured; repetitive GPS, empty UI and repeated native messages generate fewer log records. This is not a measured CPU or responsiveness improvement.
- **iPhone artwork negotiation change:** includes the local AVRCP thumbnail-capability advertisement and cover handoff diagnostics. iPhone/Spotify artwork remains **unverified**, not a confirmed fix.
- **Installer and boot recovery:** adds independent Windows CE recovery selection, an installer desktop action and verified first-stage boot-file replacement. Error-path/power-loss recovery has not been physically validated and is not a guarantee against lockout.

This is the **complete update**: all 1,919 MAX18 paths remain, plus Recovery.exe, for **1,920 files**. All intervening MAXmade changes are included; intermediate releases are not required. The LGU is exactly the file supplied for the owner's MAX30 test, without rebuilding.

Download **upgrade.lgu** and follow the [installation guide](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade#before-you-start). Intended for first-generation MediaNav hardware originally running 4.x, including converted units; factory Evolution and later units are unsupported. The reported physical upgrade was MAX26 to MAX30; this does not establish every starting-version or hardware combination.

**Known limits:** iPhone artwork and the reporter's MICOM restart are not confirmed resolved. Automatic storage maintenance, formatter error handling and stalled-update paths still have known gaps; do not treat the recovery changes as universal protection. [Details, device feedback and validation](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/blob/7.0.6.MAX30/releases/7.0.6.MAX30/README.md).

996 offline checks passed, with reused results for byte-identical inherited components documented separately from the owner's general test report. Size: **52,306,828 bytes**. SHA-256:
`5e649714c20503cd9fb738d54aa836577d73714f888b05d718c06a2acc6550d7`
