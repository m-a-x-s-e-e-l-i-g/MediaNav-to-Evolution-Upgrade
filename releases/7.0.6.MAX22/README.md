# MAXmade 7.0.6.MAX22 — immediate Settings redraw

Full MAX21 successor: all 1,919 payload paths retained, 1,916 byte-exact.
Only AppMain.exe, CmnDll.dll and Version_Info.txt change. Blue and the other
instrumented managers, resources, navigation, DBoot, kernel and MCU input remain.

## Settings correction

MAX20/21's full-window erasure could clear native cached controls without
redrawing them. Debugging now uses the original immediate control-drawing path.
The status label enables the native background-restoration flag, so old text is
cleared only within its own rectangle. Both rows are presented through the
native rectangle-blit path, including cached-surface mode. Native paint finishes
before the two rows are refreshed. Hidden parent presentation stays subject to
the original native guards. Toggle draws immediately; writer state changes use
a non-erasing notification. No Version Info detour should be necessary.

The saved On/Off setting, asynchronous writer, unique CREATE_NEW log files,
lower-volume poll summaries and MAX21 artwork/RAM diagnostics are retained.
Allow two seconds after toggling before switching off the car. Log files remain
on external USB until you delete them; low space stops logging without deletion.

## New log findings

The supplied MAX21 captures have 1,435 valid records. All 11 tracked artwork
bitmap creations have successful deletion records; no failed create/delete or
accumulating bitmap imbalance is visible. A broader memory leak is not ruled out
by these shorter captures. Main-capture RAM settles around 94–95 MiB free after
startup. Artwork drawing is the largest decoder stage, up to 68 ms; total decode
is up to 114 ms. IPC calls are mostly 10–30 ms.

FM-to-Bluetooth switches take up to 906 ms. Native code has a 200 ms source wait,
a 50 ms navigation/audio wait, a 200 ms playback wait and a further 200 ms fade
wait on the observed path. MAX22 adds timings for the nested waits and fade IPC.
Their synchronization/order is retained; replacing them needs a validated native
readiness condition. No faster audio transition is claimed for this release.

The early Navigation Not ready messages precede completed navigation startup;
DAB destination failures still coincide with ACC OFF. They remain logged. The
restart capture logs managers and AppMain before menu interaction, supporting
restoration of the saved debugging setting. The 18-drop counter in the warm
capture is already present initially and stays constant; the restart has zero.

## Car verification

Confirm 7.0.6.MAX22 after the established full-update procedure. Open Settings
directly: the options and Debugging rows should appear immediately. Toggle
several times, change other settings, switch pages/themes and check Version Info
and return. Text should update immediately without overlap. Also check live
USB waiting/active/off transitions without navigating away.

Check music, artwork, navigation and source switches with debugging On and Off.
Collect a longer continuous capture with the same track versus track changes,
plus FM/Bluetooth switches and shutdown. The added wait timings establish the
unmeasured part of the transition. Copy all log chunks and run:
python analyze_debug_logs.py PATH_TO_LOGS --output summary.json

## Validation boundary

Actual label-renderer and rectangle-present MIPS instructions are exercised with
explicit background/text/BitBlt GDI boundaries in normal and cached modes. The
transparent-label fixture reproduces old glyph remnants; native opaque restore
clears them. Other written-byte fixtures cover first-page/toggle draw requests,
themes, post-paint ordering/ABI, all phase calls, persistent configuration,
non-overwriting files, polling, native bitmap lifetimes and navigation.
Actual screen behavior and timings still need the car check. Source/backup and
previous releases are retained; raw owner logs are excluded from the package.
