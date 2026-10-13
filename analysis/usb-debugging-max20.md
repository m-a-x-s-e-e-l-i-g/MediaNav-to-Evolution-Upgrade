# MAX20 debugging corrections

Owner reports against MAX19: Debugging resets at ignition, old/new status text
overlaps, and eight rotating names overwrite preceding sessions. The supplied
photo shows overlapping status glyphs below Debugging: On.

MAX19's generated persistence routine flushed a registry key before setting its
value. Registry persistence itself was not established on the car. MAX20 uses
two 16-byte files on Storage Card2 instead, independent of the USB stick and
of reconstructed registry state. Each includes magic/version, sequence, exact
boolean and an additive check word. The writer writes only the inactive slot,
flushes, closes and reads it back before updating its active sequence/slot.
Startup selects the newest valid sequence with wrap handling. Truncated,
extended or invalid records are ignored; MAX19's registry is a migration-only
fallback if neither slot is valid. Logging writes remain restricted to MD.
The zero-wait UI toggle performs no filesystem writes. Allow two seconds before
powering off; failures are reported and retried by the background worker.

Status refresh changes native controls without calling their direct draw
method. Toggle and writer status changes invalidate the whole Settings window
with background erase enabled. The existing native paint routine at 0x134d28
paints the background through 0x13d220 and draws page children afterward.
This addresses the direct transparent text overlay seen in the owner's photo;
hardware repaint confirmation still requires the new car build.

New log names contain the session's calendar time, start tick and chunk counter.
Every open uses CREATE_NEW, including after rotation, restart or USB insertion.
Both ERROR_FILE_EXISTS and ERROR_ALREADY_EXISTS retry with another counter.
Retries are bounded to 64 per worker iteration. Files split at 4 MiB and remain
until owner deletion; below 16 MiB free the writer stops without deleting logs.
Existing MAX19 debug-0.log through debug-7.log are never truncated.

The full build inherits MAX19's 1,919 member paths and retains 1,916 hashes.
Only CmnDll.dll, AppMain.exe and Version_Info.txt change. The five remaining
instrumented applications, kernel, MCU input, DBoot, images, fonts and navigation
payload stay byte-exact. Source modules and original MAX19 packages remain
available. The owner's four-card backup has not been written to.

Verification interprets the actual emitted MIPS, with explicit CE/filesystem
fixtures. It covers fresh processes with erased registry, both boolean values,
failed/torn saves, sequence wrap, rebasing, repeated clocks, more than eight
chunks, bounded collisions, low free space, native repaint requests and inherited
MAX19 logger/source/navigation behavior. The added ReadFile ordinal 170 is
verified against the actual extracted ROM export. Physical flash durability,
touchscreen output and sustained car operation remain unverified.

Final development/package stage: `build/max20-debugging-development-04`.
All 198 written-byte checks pass. Independent LGU decoding, separate pinned PC
extraction, all 1,919 payload hashes, ZIP CRCs and 44 source pins pass. Full LGU:
52,144,163 bytes, SHA256
`98fff7cf8d16e3a78d2355ed933096ce23b79cd57db374c9349a537fea2e1980`.
Deliveries: `build/maxmade-7.0.6.MAX20/upgrade.lgu` and
`build/maxmade-7.0.6.MAX20.zip`. No device flash or public release was performed.

Build from the established authoring workspace:

```powershell
$env:PYTHONPATH="$PWD/tools/python-libs;$PWD/tools"
python tools/build_max20.py --output build/max20-debugging-development-FRESH
python tools/verify_max20.py --build build/max20-debugging-development-FRESH
python tools/package_max20.py --stage build/max20-debugging-development-FRESH
```

Use a fresh stage and preserve the existing delivery. The packager checks the
entire prior payload, independently decodes the LGU, extracts it with the pinned
PC tool, compares all hashes and checks the final delivery ZIP CRCs.
