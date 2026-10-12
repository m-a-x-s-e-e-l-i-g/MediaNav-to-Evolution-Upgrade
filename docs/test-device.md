# Max's development and test device

MAXmade is developed and tested on Max's **first-generation Renault / Dacia
MediaNav**, converted to Evolution software. The owner supplied the following
device specifications and system readings on 12 October 2026.

| Component | Specification or reported reading |
| --- | --- |
| Display resolution | 800 × 480 pixels (WVGA) |
| Screen | 7-inch resistive touchscreen |
| CPU | NetLogic Au1320, 667 MHz (owner-supplied specification) |
| Processor label reported by the system | RMI MIPS32-Au13xx |
| Architecture | 32-bit MIPS / MIPS32 |
| Installed RAM | 256 MB (reported installed specification) |
| OS-reported RAM | 192,140 KB, displayed as approximately 187.6 MiB |
| Internal storage | 4 GB (owner-supplied specification) |
| Operating system | Windows CE 6.0 |
| Original navigation software | iGO Primo |

The installed-RAM specification and OS-reported reading are separate records.
They have not been independently measured, and the difference does not establish
how much memory any particular subsystem reserves. The CPU specification and
the broader processor-family label are also recorded separately. No board,
hardware revision or product-label part number has been provided.

## Bluetooth development setup

The reported phone setup during this work is a **Nothing Phone (1), Android 15**,
with **Spotify** and Bluetooth Developer Options set to **AVRCP 1.6**. Other
Android music apps were also used while investigating the earlier title issue.
This is the owner's reported test setup, not a compatibility certification for
every phone, player or AVRCP implementation.

## Hardware feedback

- MAX07: owner confirmed selected-button text fixes.
- MAX08: owner confirmed Bluetooth stuttering/delay and “No title” resolved.
- MAX14: owner reported “Cover starting (S0)” and no artwork.
- MAX15: owner installed it in the car and confirmed **Bluetooth album art works**,
  then authorized publication on 12 October 2026.

MAX15's precise track-skip/reconnect test matrix was not separately reported.
Offline fixture results are listed in the [MAX15 release notes](../releases/7.0.6.MAX15/README.md).
Results on this device do not establish support for factory Evolution or later
MediaNav hardware; see [compatibility](compatibility.md).
