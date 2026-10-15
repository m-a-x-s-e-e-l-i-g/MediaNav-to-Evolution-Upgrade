# MAX24 — Micom/RVC and GPS diagnostic test candidate

Experimental prerelease for [#53](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/53) and [#54](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/54), split from [#52](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/52).

This is a complete cumulative update from MAX18 or the intervening test versions. It includes the Settings Debugging option, saved On/Off state, non-overwriting USB log sessions, Settings redraw corrections, lower-volume logging and the earlier Bluetooth settling-budget optimization.

The targeted changes are:

- Restore the local RVC/GPS-fitted bit before redraw when its native write fails or is blocked by test mode. Successful writes and native retry policy stay intact.
- Avoid passing NULL into either native service-window creator after allocation failure. This fixes a demonstrated failure path; the reporter's restart has not yet been attributed to it.
- Observe the existing navigation NMEA dispatcher: talker, raw RMC/GGA/GSA status, satellites visible/used, and native parser acceptance. The observer opens no extra GPS connection and records no coordinates or raw sentence text.
- Record service entry and DSI/RVC command results. DSI_Config is a CAN-configuration request, not a generic Save button. Existing 3746/3748 routing and power policy are retained.

**Neither reported problem is confirmed resolved on the affected car.** GPS receiver/configuration, saved home position, maps, licenses and user navigation data are not reset or replaced by these targeted changes.

Download the **full ZIP**, then follow **REPORTER-TEST-PLAN.md** inside it. One capture covers navigation, one service-menu entry attempt, a requested RVC change if appropriate, and a normal restart. Do not use unrelated service-menu reset/clear/write functions for the test.

402 written-MIPS/regression checks pass. The LGU has 1,919 payload paths; 1,915 members are byte-exact to MAX23. AppMain, Blue, other managers, resources, kernel, DBoot and firmware.hex input remain exact. The full LGU is independently decoded and separately PC-extracted, with complete member hashes, source pins and ZIP CRC verified.

The added GPS observer omits coordinates, but existing native logs may contain device details. Share raw logs privately and redact location-bearing screenshots before posting publicly.
