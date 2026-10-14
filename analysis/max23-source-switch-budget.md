# MAX23 Bluetooth source-switch elapsed settling budget

14 October 2026. Owner asked for actual source-switch optimization after MAX22
added timing phases without changing native waits. This candidate changes the
Bluetooth playback path; it does not merely add another measurement.

## Change and scope

Native `A2DPPlay` sends `01070502` through `11b464`, then reads/logs the source,
sleeps 200 ms and calls `requestMediaFadeOut`, which sleeps another 200 ms before
IPC `IpcSendMsg(21,3,8b,4,&zero)`. There are no intervening hardware commands
between those two sleeps. MAX23 retains a minimum elapsed window of 200 ms from
successful play-command return to the first continuation and 400 ms from that
same return to fade IPC. Work already performed after the request, including
native logging and scheduler lateness, counts toward these windows rather than
adding to both full sleeps.

This is a limited improvement. The supplied MAX21 captures show up to 906 ms for
FM-to-Bluetooth, including separate 200 ms source selection and 50 ms navigation
waits plus the playback/fade waits. MAX23 preserves the source-selection, 50 ms,
overlay 500 ms and all other fade callers' waits. It does not remove the entire
650 ms synchronization budget or establish a new hardware readiness signal.
Actual speed benefit is not measured until a MAX23 car capture exists.

The native helper returns 0 after a successful mode-1 command and -1 for failed
delivery/not-ready; `11b584..11b5a4` establishes this return contract. Success
starts a time budget only; transport success is not treated as audio readiness.
The [prior readiness counterexamples](media-readiness-contracts.md) still apply.

## Implementation boundaries

- Request hook `1156c0` preserves native arguments, return values and LastError,
  captures GetTickCount after success and stores it in A2DPPlay's unused +14
  stack word. Failed requests clear it. Zero tick uses the original-wait fallback.
- Wait hook `115718` subtracts elapsed time from 200 ms. Fade hook `d4e50` uses
  400 ms only when its native parent return address is exactly `115728`, proving
  the timestamp belongs to that A2DPPlay invocation. Both remaining sleeps are
  bounded to 0..200 ms, including unexpected early invocation.
- Timestamp state is per invocation. There is no process-global/shared deadline
  that a different or nested request could replace. Unsigned subtraction handles
  GetTickCount wraparound; absolute deadline comparison is avoided.
- Original GUI notifications, playback state writes, commands, fade IPC and
  logging remain in their original order. The new helpers occupy proven-unused
  RX bank `+c000..+d400`. Original delay slots remain byte-exact. New address
  references and calls participate in cumulative MIPS relocation/pdata metadata.
- Existing events 134/135 record actual remaining sleep in the result field.
  This optimization operates with debugging Off as well as On.

## Verification

`verify_source23.py` interprets the full written native A2DPPlay and fade paths
in MAX22 and MAX23. CE clock/Sleep, IPC and GUI operations are explicit fixtures.
Comparisons cover native work 0/10/30/100/250 ms, success/failure and logging
Off/On. Command sequence and playback state writes must match, with first
continuation no earlier than 200 ms and fade no earlier than 400 ms after the
request. Failed requests retain the predecessor trace exactly.

Further cases cover relocated executables, tick wraparound, scheduling lateness,
fade caller ownership, missing timestamp, native argument/result/error/register
and stack preservation. Independent inherited tests cover Settings rendering,
durable config, unique log sessions/chunks, artwork lifetimes, navigation and
the original inline source-dispatch table. Evidence is in the stage JSON files.

The final stage passes **330 checks**, including **65 source-budget checks**.
With 10/30/100 ms of work after request return, the interpreted post-request
fade timing changes from 410/430/500 ms to 400 ms respectively. These are
controlled clock examples, not measured car improvements. Failed-request traces
remain identical. The separate first continuation remains at least 200 ms.

Reproduce in a fresh directory using the project's Python libraries:

```powershell
$env:PYTHONPATH="$PWD/tools/python-libs;$PWD/tools"
& 'C:/Users/maxom/AppData/Local/Python/pythoncore-3.14-64/python.exe' tools/build_max23.py --output build/max23-source-budget-development-04
& 'C:/Users/maxom/AppData/Local/Python/pythoncore-3.14-64/python.exe' tools/verify_max23.py --build build/max23-source-budget-development-04
& 'C:/Users/maxom/AppData/Local/Python/pythoncore-3.14-64/python.exe' tools/package_max23.py --stage build/max23-source-budget-development-04
```

## Delivery and car check

Full MAX22 successor: 1,919 previous payload paths retained, 1,916 byte-exact;
AppMain/Cmn/version change. Blue, managers, resources, navigation, kernel, MCU
and DBoot stay exact. Previous complete delivery files remain in the new package.
An independent LGU decoder and separately pinned PC extractor verify the full
payload; delivery checks include source pins and ZIP CRC. Raw owner logs are
excluded. No firmware is executed natively, flashed or publicly published.

Compare repeated FM/Bluetooth switches with MAX22 on the same phone/track and
debugging setting. Check already playing and paused music, disconnected phone,
USB, navigation prompts, calls and rapid repeated source switches. Confirm
immediate Settings redraw, persisted debugging and unique log files. Missing
audio, clipping/clicks or a timing regression remain car acceptance failures;
offline fixture results cannot establish physical audio behavior.

Final LGU: **52,145,586 bytes**, SHA256
`b753379d1d911c7b211813fa41079423774235270e8698862872240b38a69ee7`. Independent decoding/extraction, all member hashes, ZIP
CRC, 60 source pins, retained predecessor sources and delivered analyzer smoke
passed. Local branch `codex/max23-source-switch-budget`; car testing pending.
