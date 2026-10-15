# MAX24 — issue #53 Micom/RVC and issue #54 GPS diagnostics

15 October 2026. Reporter: 2014 Captur, originally 4.0.6, now MAX18. The owner
cannot reproduce the unit-specific problems locally and requested targeted test
versions. This candidate is one complete MAX23 successor, with two concrete
failure-path corrections and read-only GPS observation. It is not a confirmed
resolution of either reporter issue.

## Native Micom findings

The AppMain service-code handler sends IPC 21→3 command C6 with the final digit
of 3740..3749 while TEST_MODE is enabled. Micom's C6 branch distinguishes 4, 5,
6 and 8. Value 6 calls `3f01c`, the service tool; value 8 calls `213f0` with power
state 2, which ultimately invokes the separate service screen `49c34`. The
original code-selection and power policy remain unchanged. These are different
paths, and neither the report nor an identification screenshot establishes
which exact entry sequence was used. It would be incorrect to call 3748 a
universal shutdown-only command or recommend 3746 as an equivalent replacement.

Both `3f01c` and `49c34` explicitly handle failed allocation by publishing NULL
but then unconditionally call `44b7c`. That native creator increments its window
stack and stores the instance/parent through object+4/+8. With NULL, these become
low-address stores. MAX24 guards just those two creation call sites. A NULL
instance avoids calling the creator and sets error 8; successful arguments,
native creation and native exception-handler scopes stay intact. This is a
verified failure path, not proof that allocation failure caused this report.

The native DSI panel has separate controls: RVC event 56, GPS-fitted event 57,
DSI_Config event 6. RVC/GPS events toggle bits 04/08 in local configuration byte
object+11, then call `14db0` with group D, command 6, two bytes and timeout 100.
That sender returns zero on blocked test writes or exhausted native response
waits. Its caller ignores the result and redraws the already-toggled local bit.
Thus the old UI can imply an applied change after a rejected command.

MAX24 restores only the bit toggled by that button if the native sender returns
zero. Successful writes, all command bytes, native retries/timeouts and other
configuration bits remain exact. No automatic retry, forced RVC enable or MCU
configuration rewrite is added. An acknowledgement is still not proof of
persistence after a shutdown.

DSI_Config calls `15158` with group 1/type 1/command A and one zero byte: a CAN
configuration request, not a generic Save action. The candidate records its
duration/return without replacing it or changing the synchronization policy.

## GPS observation

The inherited NNG profile `config/devices/lge_ulc.ini` selects COM4/9600 and allows
GGA/RMC time. SYS.TXT is not shipped in the successor payload; the reporter's
installed overrides and saved navigation state remain unknown. The owner's
separate private MAX15 backup has only the device selector in SYS.TXT and is not
assumed to represent the reporter's unit.

NNG routine `22bd00..22be4c` receives an ANSI string object with pointer +4 and
signed byte count +10. It tries six native sentence recognizers and returns the
selected parser object on successful parse, or zero otherwise. Its pdata has no
exception handler. MAX24 clones this exact routine and wraps it; the existing
dispatcher runs before telemetry, with original arguments, data and result/error
state preserved. Its GPS transport remains the sole serial-port owner.

A bounded leaf observer reads at most 128 bytes. It emits packed sentence/talker
identifiers and raw RMC active/void, GGA quality/used-satellite count, GSA mode and
GSV visible-satellite count. No coordinates, dates or raw NMEA text are copied
into the diagnostic records. The observer is not a second checksum validator.
Native parser acceptance is logged separately from the raw markers; neither
alone certifies the displayed vehicle position.

Unchanged markers are sampled approximately every five seconds in six buckets;
marker or native-acceptance changes emit sooner. This can distinguish, for
example, visible GSV satellites from GGA no-fix, or an active GN sentence rejected
by the engine. Neither situation has yet been captured from the reporter's car.
No talker normalization, receiver configuration, date correction, position
override, map/cache replacement or saved-home reset is applied speculatively.

NNG resolves DbgDebugPrint dynamically from the absolute existing system CmnDll
path. Its static DLL dependency families remain COREDLL/toolhelp. Resolution
uses a no-wait compare/exchange guard, caches the live handle/function and retries
lookup failure no more often than every five seconds. Failed symbol lookup
releases its temporary library reference. Logging Off produces no GPS records;
the initial backend lookup may load the existing system library once per process.
The native parse result and LastError survive all backend failure paths.

## Image and logging boundaries

Micom and NNG are originally fixed-base executables with RELOCS_STRIPPED; that
policy is preserved. New metadata relocation entries do not establish native
rebasing support. NNG's large original pdata needs a larger RX metadata bank than
the manager images; the private RW state follows the full 1 MiB reserved RX bank.
No writable executable section is added. Earlier AppMain/source-switch rebasing
tests remain part of the inherited suite.

Micom events 400–406 have begin/end records and command results. RVC/GPS begin
records include the requested configuration bits and native test-write block
flag. GPS module 8 events 940/941 are metadata, not durations. The analyzer keeps
these separate from timings and distinguishes satellites visible/used, raw
status, selected parser and command acknowledgement. Missing end records remain
ambiguous with queue drops, rotation and abrupt shutdown; they are not labelled
as confirmed crashes.

## Verification and delivery

The targeted suite executes the written native button blocks with successful
and failed command fixtures. It reproduces the old failed-write UI and confirms
rollback without reverting unrelated bits. Original and candidate service entry
instructions execute under allocation success/failure; the original's native
low-address store is reproduced, and the candidate avoids it. API boundaries,
argument forwarding, 13 stack/register arguments, v0/v1, nonvolatiles, LastError,
native delay slots and service selection are checked.

GPS tests cover GP/GN raw markers, all GGA truncations, NULL/negative lengths,
the 128-byte scan bound, unchanged input/native results, logging Off, backend
load/symbol failure, competing resolution and five-second/change sampling.
Original engine parser/CE and UART response outcomes are explicit fixtures.
These tests do not reproduce native loader scheduling, electrical camera/GPS
behavior or this reporter's complete navigation state.

Full delivery starts from MAX23: all 1,919 prior payload paths remain, with 1,915
byte-exact. Only MicomManager, nngnavi, CmnDll's diagnostics header/checksum and
Version_Info change. AppMain, Blue, managers, images/skin, kernel, DBoot and
firmware.hex input stay exact. Previous delivery files are retained. Full LGU
decode, a separate pinned PC extraction, complete hashes, ZIP CRC and source pins
must pass before sharing. Raw owner data and the reporter identification image
are excluded.

The [reporter test plan](issue52-reporter-test-plan.md) asks for one combined
capture: navigation first, one existing service-menu entry attempt, then a normal
restart/readback. It does not ask for destructive service-menu experiments. Both
GitHub issues stay open until the affected unit confirms the required behavior.

Scripts: `build_max24.py`, `micom_diag24.py`, `gps_probe24.py`, `debug_runtime24.py`,
`verify_max24.py`, `verify_issues24.py`, `analyze_debug_logs24.py`, `package_max24.py`.
Use fresh build/output paths. No CE executable is run natively or flashed by
these tools.

## Final local result

Stage `build/max24-micom-gps-development-03` passes **402 checks** (330 inherited,
70 targeted native Micom/GPS checks and two analyzer checks). Full container
decode/extraction, complete payload hashes, ZIP CRC and 66 frozen source pins
pass. The LGU is **52,273,945 bytes**, SHA256
`268ff9abd6ce262bce7e347228bfe5c705c460e61f6dcdf35b33e87312b31d83`.
The full ZIP and standalone LGU are under `build/maxmade-7.0.6.MAX24*`.
Physical reporter testing remains pending; no issue is closed by this result.
