# MAXmade 7.0.6.MAX24 — Micom/RVC and GPS diagnostic candidate

Full MAX23 successor: all 1,919 previous payload paths retained; 1,915 byte-exact.
Changes: MicomManager.exe, nngnavi.exe, CmnDll.dll diagnostic header and version.
AppMain, Bluetooth/audio/artwork, Settings redraw, source-switch optimization,
USB managers, resources, maps/licenses/user saves and all previous improvements
are retained. Kernel, DBoot and firmware.hex inputs stay byte-exact.

## Purpose and limits

This is a targeted reporter test for GitHub issues #52/#53/#54 on a 2014 Captur
originally running 4.0.6. It contains two verified native failure-path guards:

- Native RVC/GPS-fitted buttons previously left their local bit toggled even when
  the native write returned failure. MAX24 restores that bit before native redraw
  on failure; successful commands and the native retry policy remain unchanged.
- Both service-window creation paths previously passed NULL into the native
  window creator after failed allocation. MAX24 stops that call and reports the
  allocation error instead. The observed reporter restart is not yet attributed
  to allocation failure; a successful allocation keeps the original behavior.

DSI_Config sends a CAN-configuration request; it is not a generic Save button.
The 3746 and 3748 service entries select different native paths. 3748 requests
power state 2 and then a separate service screen. MAX24 records those paths and
retains their power policy rather than changing a service code blindly.

GPS diagnosis is read-only: observe sentences already passed into NNG's existing
NMEA dispatcher. No additional COM4 handle is opened, and no GPS receiver
configuration, date, maps, home address, routing or navigation save is changed.
Logs include talker (GP/GN/etc), raw RMC validity, GGA fix/satellites used, GSA
mode, GSV satellites visible and native parser acceptance. No coordinates or raw
sentence text are copied by this observer. Unchanged observations are sampled
roughly every five seconds per bucket; marker/acceptance changes emit sooner.
Raw status and parser acceptance do not independently certify a valid GPS fix.

Micom structured events 400-406 capture entry, native command duration/return,
requested RVC/GPS bits and test-write blocking. Missing end events may result
from rotation, dropped records or power loss; they do not alone prove a crash.

## Reporter procedure

Use REPORTER-TEST-PLAN.md. Enable Debugging in Settings with a USB stick inserted,
wait for Logging active, and capture navigation first, then one service-menu
attempt. Reboot normally and confirm RVC state only if its write succeeds.
Keep every log chunk. Share logs privately; existing native diagnostics may
contain device details even though the new GPS observer omits coordinates.

Do not treat the candidate as a confirmed GPS or camera fix for the reporter.
The user-visible result, installed camera and receiver behavior need that unit's
physical test. The added logs are intended to choose a narrow follow-up fix.

## Validation

Written-MIPS tests reproduce the predecessor's stale RVC/GPS bits after rejected
writes and native low-address stores after NULL allocations; candidate branches
restore the bit and avoid the invalid call. Success paths, native command bytes,
arguments/stack/registers/v0/v1/LastError and delay slots remain covered. GPS
fixtures cover every GGA truncation, bounded scanning, metadata/throttling,
backend load/symbol failures and concurrent-resolution no-wait behavior.
Inherited MAX23 tests retain Settings, persistence, log uniqueness, Bluetooth,
artwork, navigation and source-switch coverage. Both Micom and NNG preserve
stock RELOCS_STRIPPED/fixed-base policy; no native firmware runs on the PC.

The full LGU is independently decoded, separately extracted by the pinned PC
tool, and compared by complete member hashes. ZIP CRC and source pins are
verified. Prior full delivery files are retained. No owner's maps, navigation
history, phonebook, GPS locations or raw car logs are included in this package.

Analyze logs with:
python analyze_debug_logs.py PATH_TO_LOGS --output summary.json
