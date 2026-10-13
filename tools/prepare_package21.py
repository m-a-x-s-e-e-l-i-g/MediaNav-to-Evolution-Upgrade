"""Full MAX20 delivery inheritance and a versioned analyzer with its old parser."""
from pathlib import Path
P=Path(__file__).resolve().parent
GUIDE='''# MAXmade 7.0.6.MAX21 â€” measured performance and lower log volume

Full MAX20 successor. All 1,919 firmware paths remain; 1,915 are byte-exact.
Only AppMain.exe, Blue.exe, CmnDll.dll and Version_Info.txt change. CmnDll's
runtime instructions are byte-exact to MAX20: only its diagnostic header and
PE checksum change. The saved Debugging setting, background repaint and
non-overwriting session files from MAX20 are retained.

## What changes

The frequent Blue artwork check still runs on its original schedule and follows
the original publication/retry path. Idle checks no longer write begin/end pairs.
A ten-second summary reports poll count and maximum elapsed call time. Nonzero
results (publication/retry) and calls taking at least 16 ms are still recorded.
The existing native error/debug text is not filtered. In the instruction fixture,
120 idle checks produce five summaries rather than 240 records.

Source switching now measures each of the three conditional 200 ms wait sites,
synchronous IPC sends (including retries), IPC gets and IPC posts. Arguments,
delay slots, native waits, manager readiness and audio behavior are retained.
These measurements establish where the aggregate 859 ms delay is spent; this
build does not claim faster source switching or shorten waits.

Artwork measurements separate JPEG validation, factory creation, image-from-
buffer, image information, bitmap allocation, image drawing and object release.
There are global RAM snapshots before/after decoding and counters for successful
artwork bitmap creation/deletion while debugging is enabled. Failed allocation
or deletion has an explicit raw result. These counts are not a complete inventory
of handles predating logging or operations occurring while debugging is Off.
RAM snapshots are OS totals, not per-process allocation ownership.

The MAX19 capture showed about 9.4 MiB of memory growth during playback, followed
by about 18.9 MiB released during shutdown/disconnection. That does not establish
or rule out a leak. Native bitmap ownership/cleanup stays unchanged while the
new trace helps identify missing deletions versus other retained resources.

## Use and comparison

Install the full LGU using the established procedure and confirm 7.0.6.MAX21.
Settings > System > page 2 > Debugging enables external USB captures in
MAXmade/logs/. Allow two seconds after changing the setting before cutting power.
Sessions use CREATE_NEW names and remain until owner deletion; USB full stops
logging without deleting earlier files. Config uses the two small internal-card
slots from MAX20. No log data is written to internal cards.

Capture the following separately with logging continuously On:

1. Five minutes playing the same Bluetooth track without interaction.
2. Five minutes with repeated Bluetooth track/artwork changes.
3. Several FM/Bluetooth/USB source switches and Settings page changes.
4. The end of playback and shutdown/disconnection.

Check media/artwork/navigation and Settings with debugging both On and Off.
The inherited MAX20 fixes still need cold-ignition and real screen confirmation.
Copy the entire logs folder and run:
python analyze_debug_logs.py PATH_TO_LOGS --output summary.json
The updated analyzer separates poll counts and memory/bitmap snapshots from
elapsed timings. It also accepts surviving MAX19 and MAX20 logs.

## Verification boundary

Actual emitted MIPS instructions are interpreted with explicit CE/clock/file/GDI
fixtures. Arguments, dynamic call targets, original delay slots, v0/v1, LastError,
nonvolatile registers, rebasing and inherited functionality are checked.
The package is independently decoded and separately extracted by pinned PC
tools. Actual overhead, source responsiveness, bitmap failure rates and sustained
RAM behavior still require the car capture. No leak or car performance fix is
claimed from offline measurements. Original releases and backup remain intact.
'''


def main():
    s=(P/'package_max20.py').read_text()
    start=s.index('GUIDE=');end=s.index('\n\n\ndef dependencies',start)
    s=s[:start]+'GUIDE='+repr(GUIDE)+s[end:]
    s=s.replace('from build_max20 import','from build_max21 import')
    s=s.replace('maxmade-7.0.6.MAX20','maxmade-7.0.6.MAX21').replace('maxmade-7.0.6.MAX19','maxmade-7.0.6.MAX20')
    s=s.replace('1916','1915').replace('Packing full MAX20','Packing full MAX21')
    a=s.index('    pending=[ROOT/');b=s.index('\n    seen=set()',a)
    s=s[:a]+"    pending=[ROOT/'tools'/n for n in ['build_max21.py','debug_metrics21.py','debug_runtime21.py','debug_clients21.py',\n        'verify_max21.py','verify_clients21.py','analyze_debug_logs21.py','analyze_debug_logs_legacy.py',\n        'prepare_debug21.py','prepare_verify21.py','replay_poll_logs21.py','prepare_package21.py','package_max21.py']]"+s[b:]
    s=s.replace("evidence=delivery/'debugging-fixes-evidence'","evidence=delivery/'metrics-evidence'")
    a="    for name in ['analyze_debug_logs.py']:\n        shutil.copyfile(ROOT/'tools'/name,delivery/name)"
    assert a in s
    s=s.replace(a,"    for name in ['analyze_debug_logs21.py','analyze_debug_logs_legacy.py']:\n        shutil.copyfile(ROOT/'tools'/name,delivery/name)\n    shutil.copyfile(ROOT/'tools/analyze_debug_logs21.py',delivery/'analyze_debug_logs.py')")
    (P/'package_max21.py').write_text(s,encoding='utf-8')


if __name__=='__main__':main()
