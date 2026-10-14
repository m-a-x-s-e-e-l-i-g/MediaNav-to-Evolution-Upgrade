# MAXmade 7.0.6.MAX23 — Bluetooth source-switch settling budget

Complete successor to MAX22: all 1,919 payload paths retained, 1,916 byte-exact.
AppMain.exe, CmnDll.dll and Version_Info.txt change. Existing Settings redraw,
saved debugging On/Off, unique log sessions, artwork, Bluetooth, navigation,
USB, volume and manager behavior are retained. Kernel/MCU/DBoot remain exact.

## Source-switch change

A2DPPlay previously issued a successful Bluetooth play request, performed native
source lookup/logging, slept 200 ms and then slept another 200 ms in the shared
fade helper. MAX23 counts elapsed work toward the same settling windows:
200 ms before the playback continuation, 400 ms before the fade IPC. Scheduling
or logging work between these points no longer adds another full delay.
The native play command, UI notifications and fade IPC stay in their original
order. The separate source-selection 200 ms, navigation/audio 50 ms, overlay
500 ms and other audio paths retain their native waits.

The timestamp belongs to this invocation's unused stack word; no shared mutable
timer or background request can supply a stale deadline. GetTickCount unsigned
subtraction handles wraparound. Failed play requests, absent timestamps and
other fade callers keep the original waits. A shortened request is bounded
between 0 and the original 200 ms. Logging remains available with requested
remaining milliseconds in event 134/135 results.

This is a limited optimization, not a claim that the 650 ms synchronization
budget disappeared. Interpreter examples with 10/30/100 ms of intervening work
remove exactly that added time; scheduler lateness also counts toward the second
wait. The supplied older car logs do not measure MAX23. Actual speed/audio,
phone/navigation interruption and repeated rapid switching need a car check.
A successful command return is used only as the start of a retained time budget;
it is not treated as proof that the hardware is ready.

## Car check

Confirm version 7.0.6.MAX23. Compare repeated FM-to-Bluetooth and back switches
with MAX22, with debugging On and Off. Test a phone already playing, paused
playback, absent/disconnected phone, USB, navigation prompts and phone calls.
Listen for missing audio, a clipped beginning or clicks. Confirm Settings rows
and toggles are visible immediately, and saved debugging returns after restart.
Allow two seconds after a debugging toggle before switching off the car.
Collect every USB log chunk; sessions remain until you delete them. Low free
space stops logging without deletion. Analyze using:
python analyze_debug_logs.py PATH_TO_LOGS --output summary.json

## Verification and preservation

Written MIPS tests compare the full native A2DPPlay/fade path in MAX22 and MAX23,
including success/failure, logging On/Off, intervening work, scheduler delays,
relocated code, tick wrap, caller ownership, stack/register/error preservation.
Inherited Settings rendering, persistent config, non-overwriting files, bitmap
lifetimes, navigation and source jump-table tests are also retained. Full LGU
verification uses an independent decoder and separately pinned PC extractor,
complete payload hashes, frozen source pins and ZIP CRC checks.

No firmware executes natively on the PC. Native CE scheduling/audio/display and
the car acceptance check remain outstanding. Prior complete packages and sources
remain available. Private owner logs are excluded. No device flash or public
publication is performed by the builder.
