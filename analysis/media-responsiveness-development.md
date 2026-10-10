# USB resume, touch release and menu processing

Implemented on 9 October 2026 after Max requested items 2, 3 and 4. The [complete internal payload](../build/media-responsiveness-development-01/README.md) carries forward every file from 7.0.6.MAX03, English updater/DBoot work and the installer copy-safety prototype. This is development work: no LGU, release ZIP, version bump, publication or unit operation.

## Changes and practical benefit

| Change | Expected benefit | Evidence boundary |
| --- | --- | --- |
| USB resume ignores changed free space | Adding or removing unrelated files no longer rejects resuming an unchanged saved song and position | Actual MgrUSB instructions with file/volume/graph fixtures; native resume and library scanning still need testing |
| Outside button release uses the existing cancel route | Lifting a finger outside a held seek button stops the hold and sends seek-stop | Actual button, window-up, timer and USB screen instructions; physical touch-driver ordering is unobserved |
| One-pass Hebrew text-direction detection | Less work when drawing labels, including labels containing no Hebrew text | Exhaustive UTF16 comparison and instruction/read counts; native menu speed is unmeasured |

## USB resume: a narrow change

`MgrUSB.exe` still loads the full saved path and checks the existing file-size/volume-serial pair, successful disk-information lookup and total disk capacity. A playback graph must still load successfully before restoring the saved position. Only the free-byte comparison is bypassed: `1bb70` branches to `1bb98`.

This keeps both high and low DWORD checks for total capacity and the existing identity fields. It does not introduce a stronger content fingerprint: equal-size content replacements or cloned volume serials can still pass the original checks. Resume-file layout, checksum, repeat/shuffle and save routines are unchanged.

Ordering was followed through attach `1eac4` and boot `1fd6c`: resume uses the saved path before the full library scan. Search `1ef48` subsequently uses `1e8cc` to rematch the saved filename and folder to the new index. Five actual rematcher cases cover added preceding songs, the same filename in another folder, missing matches and an empty catalog. The scan and its concurrency are not fully emulated.

Twenty resume scenarios cover changed free-space low/high values, full sticks, another volume, changed/deleted tracks, file-information/disk API failures, capacity changes, graph failure, empty/relative paths and preserved positions. Together with five rematcher cases: **25 checks**. File APIs and graph loading are explicit fixtures, not real media playback. Original unaligned MIPS merge operations receive four separate architectural checks.

## Button release: preserve the ordinary gesture paths

Original `13e620` clears pressed-state before testing the release point. An outside-up without a previous outside-move leaves selection/timers active. Actual original timer dispatch then produces actions 3 and 4 after release.

The five-instruction change at `13e654..13e668` calls the existing `13e6f8` move/cancel routine while pressed-state still exists. An outside release therefore takes the established cancel callback, sends action 5 if a hold started, redraws and clears selection/timers. An inside release proceeds through the original up/click callback. An inside release with event -1 now clears selection/timers without sending a click.

**117 actual-byte cases** cover both seek events, repeat/non-repeat controls, releases before/after hold, queued timers, inclusive rectangle edges, repeated up, move cancellation, invalid events and release without down. The original WM_MOUSEUP router is exercised as a caller. Actual `CUSBMainDlg::onBtnClick` bytes translate the held-release sequence into IPC 21→5 commands `68→69` for rewind and `66→67` for fast-forward; no continued hold event follows cancellation. IPC delivery and the native seek engine are not run.

The scope is enabled buttons with valid object lifetimes. Disabling or destroying a control during an active gesture, callback reentrancy, switching dialogs and losing capture remain separate lifetime questions.

## Performance: implemented rendering optimization and startup investigation

The previous Arabic scan improvement remains intact. Hebrew detector `1397c8` originally initializes a 518-byte unused buffer, formats an unused text copy, measures the full text length, then scans for `0590..05ff`. The replacement inside `1397e8..139880` makes one range scan, ending at the first NUL or matching code unit. The function frame, saved registers, cookie check, epilogue and all eight drawing call sites remain unchanged.

All **65,536 UTF16 values** and **140 mixed/long-string cases** match the previous result. The written AppMain receives additional checks of both the new scan and the existing Arabic scan.

| Latin label length | Previous source-unit reads | New reads | Previous interpreted instructions | New instructions |
| --- | ---: | ---: | ---: | ---: |
| 8 | 17 | 9 | 144 | 77 |
| 32 | 65 | 33 | 456 | 245 |
| 128 | 257 | 129 | 1,704 | 917 |
| 270 | 541 | 271 | 3,550 | 1,911 |

These counts exclude CRT hook internals and all GDI/rendering time. The 46% instruction reduction for the 128-unit helper is not a 46% improvement to whole-screen or boot time. There is no measured elapsed-time claim.

[`inspect_media_performance.py`](../tools/inspect_media_performance.py) also follows actual startup/launch-selection instructions across **48 cases** of USB/iPod insertion, last source and DAB presence. Existing order is media-manager launch → fixed 600 ms wait → Blue launch → boot-status IPC → optional DAB launch. Process creation, registry values, controller/GDI initialization and IPC are explicit fixtures; this proves call ordering under those fixtures, not native readiness.

The source-selection routine `d9f04` contains three separate 200 ms sleep sites; overlay restoration `d95a8` contains a 500 ms site. Synchronous IPC calls and zero-result retries precede some waits. These are different conditional paths, not delays to add together. The audit records original function hashes and verifies they remain byte-identical in development. Startup and source-switch waits are unchanged: a manager process existing is insufficient evidence that its media/audio state is ready.

Next performance evidence required: matched unit measurements of ignition-to-usable-home, first/warm menu transitions, and radio↔USB↔Bluetooth switching, plus readiness tracing before shortening any wait. The previously excluded broad Bluetooth timeout/power/controller/cache investigation was not resumed.

## Complete payload and verification

The [builder](../tools/build_media_responsiveness_development.py) hashes all 1,918 inputs, writes every file and verifies every output. Compared with the previous installer development staging, only AppMain and MgrUSB change; **1,916 files are identical**. Compared with published MAX03, six executables differ and **1,912 files are identical**. Blue, the navigation fix, OS/MCU/boot payload, version file, translations and installer prototype are retained.

Each new PE edit is restored independently to reconstruct its exact input. File sizes, original headers, section layout, imports, non-text sections and exception metadata are unchanged by these new edits. Callee-saved registers, stack restoration and guard bytes are checked in interpreted routines. The exhaustive performance evidence is transferred only when its exact patch recipe and output hash match the written file. The [manifest](../build/media-responsiveness-development-01/manifest.json) records every file hash, recipe, readback check and tool hash.

Written AppMain SHA256: `236ef346d273b3529a3318b17219b8135eb8bb5184bd34178337e8a72df5902c`. Written MgrUSB SHA256: `408783c05921a92d885c63f9ccecee0c18c5e1725790cb623f8fa124ddb8085e`.

Reproduce with Python and `tools/python-libs` on PYTHONPATH:

```powershell
py tools/verify_media_responsiveness.py
py tools/inspect_media_performance.py
py tools/build_media_responsiveness_development.py --output media-responsiveness-development-02
```

Existing build directories are never overwritten. The published LGU and previous staging are checked unchanged after the build. No new patch-only package is produced.

## Before hardware testing or release

The cumulative updater still requires the native CE loader/storage/display checks described in [installer development](updater-copy-safety-development.md). Full development staging is not installation-ready. The new application edits are offline-verified development binaries, with no claim of native validation.

After a validated test path is available, the combined unit checks should include resume after adding/removing unrelated songs, moved/deleted/replaced tracks, another USB, normal restart and source switching; held rewind/fast-forward released inside/outside and ordinary track taps; mixed-script labels and matched first/warm menu timings. Actual startup/source-switch speed remains open. No release is requested yet.
