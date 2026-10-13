# MAXmade 7.0.6.MAX19 — USB diagnostics test build

Complete MAX18 successor. All 1,919 payload paths retained; 1,911 byte-exact.
Only seven application/library binaries and Version_Info.txt change. Navigation
engine/skin, images, fonts, DBoot, kernel, MCU input and all previous fixes remain.

## Use

Open Settings > System > page 2. Tap "Debugging: Off" to enable it.
The row becomes "Debugging: On". Logging is off by default. The choice is saved
through a dedicated registry value and RegFlushKey by the background worker.
Check that it remains enabled after a later ignition cycle; physical persistence
has not yet been verified. The item keeps the original conditional Eco slot.

With a readable/writable USB stick mounted at the native \MD path, logs start
automatically in MAXmade/logs/. Without a stick, the status is "Waiting for USB".
It detects later insertion/removal. USB/full/write/thread/configuration errors
are shown in the status line. Tap again to turn it off. Allow the pending records
to finish and the status to change to "Logging off" before copying the files.

There are eight rotating debug-0.log through debug-7.log files, each at most
4 MiB. An open starts only with at least 16 MiB free. These eight names are
owned by the logger; they are overwritten as it rotates. No log fallback writes
to the four internal Storage Cards. The configuration is the only persisted
internal setting. No PCM, artwork image payloads or packet dumps are logged.

## Measurements

- AppMain lifecycle, media manager initialization, source-switch requests and
  overlay restoration. Existing 600/200/500 ms waits are retained.
- Navigation launch, USB scanning/sorting/file rendering/folder changes.
- Bluetooth audio-start request, artwork publication and decoding.
- Screen paints of at least 16 ms. Actual first audible sound, full hardware
  source completion and navigation-engine internals are not established here.
- OS memory samples every ten seconds: free physical bytes and reported load.
  This build does not report per-process CPU utilization.
- Emitted debug strings and NKDbgPrintfW messages from AppMain, Blue, MgrUSB,
  MicomManager, MgrIpod and MgrDAB, plus the shared library. Existing native
  log filters remain; this does not activate every dormant vendor debug branch.

Records use the device millisecond clock, module/event IDs, elapsed interval,
raw return value, level and bounded text. A session header records device calendar
time and its start tick. Calendar time can be unset. A raw return/IPC delivery
does not establish successful playback or settled hardware.

The shared queue has 256 records of 544 bytes and a 128-record/second cap.
Producers use a zero-duration mutex attempt and never write or wait for USB.
The independent writer uses confirmed CE thread priority 4, releases the queue
before I/O and flushes periodically. Records can be dropped under load or lost
on abrupt power loss; drop counters are sampled. Logging has a small observer
cost. Real USB-driver contention and actual performance require car testing.

## Car test

Use the established full-update procedure and confirm 7.0.6.MAX19. First check
the original media/navigation functionality with debugging off. Enable without
USB and confirm the waiting status, insert the stick and confirm logging active.
Try source switches, Bluetooth track changes/artwork, USB scan/playback, both
themes and Settings page navigation. Turn it off and inspect MAXmade/logs/.
Then enable again, allow the setting to save, and test a cold ignition cycle
with USB inserted. Compare responsiveness/audio with logging off versus on.
Run at least 30 seconds per capture to include memory/drop samples.

Copy the whole logs folder for analysis before a later long session overwrites
its oldest chunks. Logs contain emitted native text and device/media context;
they are local diagnostic data and are excluded from this release.

Python analysis: python analyze_debug_logs.py PATH_TO_LOGS --output summary.json
It groups sessions, lists slowest measured spans, RAM samples and partial lines.
Missing end events can also result from rotation, lost records or power loss;
they are not automatically classified as a crash or hang.

## Verification and scope

Written MIPS instructions are interpreted with explicit OS/filesystem/GDI
fixtures. Native loading, touch, real audio, USB timing, registry durability
and sustained operation have not been tested on the physical device.
This is a local test build; MAX18 remains the owner-tested baseline.
The package does not prove rollback/recovery. Original builds and backup are
untouched. Preview images use native resources and PC Tahoma/sample state.
