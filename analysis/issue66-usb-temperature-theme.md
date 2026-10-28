# Issue 66 investigation and USB correction

28 October 2026. [Issue](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/66),
[log attachment comment](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/66#issuecomment-6470926885).

Read all seven UTF-16 logs, grouped into five sessions: 15,303 valid records,
no malformed records. Original ZIP SHA256:
`f35197d5a1bc7b3f0b82c5b4dd76932811e0afad74860491907dcc59a7c3515e`.
Reporter-provided card dumps were not attached here; their claimed comparison
has not been independently repeated. MAX33's published manifest has 1,921
members; the issue's 1,920 count needs clarification, not a corruption diagnosis.

## USB: confirmed failing guard, underlying native filter still unknown

There are 31 graph-transition failures, all `pause=0 reason=3 hr=00040237`.
Twenty-four selected-file failures have RenderFile durations of 5,004–5,027 ms,
then the unsupported-format message and FILE_LOAD_FAIL. Two other recorded
render calls succeed, in 220 and 947 ms. Thus a transition error is not itself
proof that that particular call failed, and the final session is not error-free.

Microsoft documents `0x00040237` as a pending transition, not a failed HRESULT:
[IMediaControl::GetState](https://learn.microsoft.com/en-us/windows/win32/api/control/nf-control-imediacontrol-getstate).
The reporter's proposed mechanism needs refinement: the guard explicitly
recognizes that result and retries; reason 3 is its five-second/poll deadline.
While GetState stays pending, it never issues Pause/Stop. RenderFile's replacement
guard then refuses teardown/reinitialization, and the caller reports the generic
unsupported-codec message. Re-encoding tracks cannot repair that state machine.

The exact 696-byte transition helper in MAX18 and MAX33 is identical. The helper
matches the historical `patch_usb_graph_state.transition` source. In an actual
MIPS instruction fixture, a graph pending until Stop receives **zero commands**
and fails after 1,000 polls/5,000 ms. This occurs even when the returned pending
target is Stopped, Paused or Running. The physical capture does not record that
target or identify which native filter prevents completion; that part remains
unproven. The owner subsequently confirmed the USB folder-player changes have
never received a physical acceptance test, including the MAX18 baseline.

Correction: allow Stop to cancel the pending graph; wait for a confirmed stopped
state before committing cached state, seeking, releasing interfaces or replacing
the graph. RealPause may request Pause once while pending; it does not revive a
pending stop. Preserve completed Running -> Pause -> Stop ordering. Remember the
command issued so a stale Running observation cannot undo an issued Stop.
Retain pointer-change checks, negative HRESULT handling, five-second bound,
failure propagation and ownership on an unconfirmed stop. Never accept pending
as successful completion or release an active graph merely to suppress an error.

The patched helper uses 764 existing bytes, with no new section/import/allocation
or executable growth. Actual packaged LoadFile, instrumentation wrapper, graph
creation/render/query/notification, old reference release and retry paths execute
in the new fixture. Eight repeated pending-graph track replacements and native
Run requests succeed at four load addresses, with debugging Off and On. Real simulated decoder failures
remain failures and permit a later retry. All 182 USB cases pass; COM/codec/time/
registry/diagnostic APIs are explicit fixtures, not CE/hardware execution.

## Temperature: distinct vehicle-data path, no confirmed sensor failure

Native Micom functions 0x14090 and 0x1439c consume vehicle data and convert Celsius
as `raw - 40`. A raw value 3 would produce -37 C; 19 C would require raw 59.
Raw 255 takes the invalid-data path (internal value 418, displayed as dashes).
These observations explain how the reported values can arise, not which actual
bytes this car sent. The logs do not contain those bytes or the current profile.
Native HMI_TEMP_CNF and saved EcoDrive settings also gate display/conversion.

ULC_TEMP uses a separate group-9/address-6 two-byte board reading and conversion
in Micom 0x4753c; it does not establish that outside temperature is valid.
The displayed `MICOM MANAGER VERSION 7.0.5.0220` is a hardcoded software caption
in Micom 0x46f88, not proof of an incomplete MAX33 install or the MCU revision.
The relevant outside-temperature and ULC conversion instructions are byte-exact
MAX18 -> MAX33. A wrong vehicle-data layout/profile, retained configuration or
communication problem is plausible; choosing one requires the original/current
configuration or raw vehicle messages. No temperature patch is justified yet.

There are 11 SendReadCmd timeout lines: ten in 10:19 (one is cmd 4/len 4), and
one in 10:32 (cmd 2/len 2). Nine cmd-2 lines in 10:19 chunk 1 match the report.
The printed stItem comes from the receive buffer read after a timeout, rather
than an explicit echo of the requested address; it must not be assumed to be an
outside-temperature request. 0x102 here comes from WaitForSingleObject.

## Theme: configuration selection strongly fits, value not captured

AppMain 0x1fbfc reads HKLM/LGE/SystemInfo `UI_TYPE` and `UI_INVERSE` to select
M0/M1/M0_INV/M1_INV. Display-settings constructor 0xbabc8 and initialization
0xbc684 conditionally build/update the inverse/theme controls according to
UI_TYPE. An M0/profile fallback fits the stock-looking UI plus missing theme
choice better than losing the installed image files. All 1,857 image members,
the resource-bank constructor and both display-settings functions are exact
MAX18 -> MAX33. This is a hypothesis; the capture contains no UI_TYPE snapshot.
Micom's startup configuration writes UI_TYPE and HMI_TEMP_CNF from vehicle/
configuration information, so a common configuration problem is plausible.
Do not force another car's profile or assume debugging changed this registry.

## Additional findings and limitations

| Session | USB transition failures | Selected-file failures | ECO reset messages | DSI sync messages | Dropped records, latest |
| --- | ---: | ---: | ---: | ---: | ---: |
| 08:50 | 4 | 4 | 2,786 | 1,475 | 3,757 |
| 09:22, both chunks | 7 | 3 | 1,203 | 897 | 55 |
| 09:54 | 9 | 9 | 44 | 0 | 0 |
| 10:19, both chunks | 10 | 8 | 334 | 0 | 414 |
| 10:32 | 1 | 0 | 0 | 0 | 0 |

The 2,372 DSI-sync records enter a native Micom handler that writes DSI_config.bsd,
deletes DSI_EC_config.bsd/DSI_VR_config.bsd and requests CAN configuration again.
This is active configuration synchronization, not just a repeated UI redraw.
It does not prove 2,372 successful durable writes. The logs lack the triggering
packet/configuration bytes, so they do not distinguish a vehicle/firmware mismatch
from service-tool activity or another request loop. The reporter says the first
storm predates opening service tools; the capture cannot independently verify it.
Missing reset-completion messages cannot establish a permanent reset because
records were dropped. ECO reset messages alone merely change an AppMain flag.

09:54 has ten Bluetooth liveness failures, seven reinitialize-failed lines,
five process-restart messages and two process-down failures. That is not proof
of ten completed process restarts or a shared USB cause. The other captures lack
this liveness sequence. Free RAM is not exhausted (lowest recorded value about
61.5 MiB), but global free memory does not rule out other resource/IPC failures.

## Next physical checks

Test the complete USB candidate stationary: resume, select a different track,
return to the first track, next/previous, folder changes, end-of-track, pause/play,
seek, source switch away/back and USB removal/reinsertion. Test debugging Off,
then repeat a short capture with it On. Keep the real MP3 and reduced test files.
An installed candidate is not a confirmed repair until this passes in the car.

For temperature/theme, inspect the already-created backups first: DSI_config.bsd,
DSI_EC_config.bsd, DSI_VR_config.bsd, EcoDrive.cfg, MgrSys.cfg and relevant registry
values (UI_TYPE, UI_INVERSE, HMI_TEMP_CNF, HMI_ECO_CNF, boot/region/profile values).
Compare with this unit's 4.0.3 backup if available. Take a read-only current MICOM
configuration snapshot; do not press clear/virgin/DSI_Config to obtain one.

A full rollback to MAX18 is not an established fix: it retains the same USB
helper and changes kernel/updater components as well. Existing documentation says
MAXmade downgrades are untested. Preserve current settings and logs before any
hardware experiment. This investigation makes no temperature/theme correction.

## Reproduction artifacts

- `inspect_logs.py`, `log-summary.json`, `targeted-context.txt`: complete counts and line-addressed context.
- `replay_usb.py`, `usb-replay.json`: old MAX33/MAX18 byte identity and pending-stop reproduction.
- `native-range-comparison.json`: inspected native functions exact across MAX18/MAX33.
- `../../tools/patch_usb_transition34.py`, `../../tools/verify_usb_transition34.py`: guarded fix and actual-instruction fixtures.
- `usb-fix-verification.json`: 182 passing USB checks and explicit simulation limits.
