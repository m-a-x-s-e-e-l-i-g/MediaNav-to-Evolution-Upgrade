"""Prepare the full successor packager, preserving the previous delivery tree."""
from pathlib import Path
P=Path(__file__).resolve().parent
GUIDE='''# MAXmade 7.0.6.MAX20 — debugging fixes

Full MAX19 successor: all 1,919 firmware paths retained, 1,916 byte-exact.
Only CmnDll.dll, AppMain.exe and Version_Info.txt change. Every previous
media/navigation fix, image, font, kernel, DBoot and MCU input is inherited.

Settings > System > page 2 > Debugging: On/Off now saves to two validated
16-byte files in \\Storage Card2\\MAXmade\\debug-0.cfg and debug-1.cfg.
The background worker writes the inactive file, flushes, closes and reads it
back before accepting the save. At boot the newest valid file wins. A damaged
inactive file leaves the older valid setting available. MAX19's registry value
is used only to migrate when neither file is valid. Both On and Off are saved.
Allow two seconds after changing the setting before switching off the car.
A failed save is reported as "Setting could not be saved" and retried.

Settings redraw uses the native page/background paint. It no longer draws the
new status directly over old glyphs. Status changes request a full repaint.

USB logs remain in MAXmade/logs/ on the external native \\MD mount. Every new
chunk has a date/time, session-start tick and counter in its filename. Creation
uses CREATE_NEW: even a wrong clock or duplicate filename cannot overwrite an
existing file. MAX19's debug-0.log through debug-7.log are also preserved.
Files split at 4 MiB; all sessions/chunks stay saved until you delete them.
Below 16 MiB free, logging stops and shows USB full. No files are automatically
deleted. Collision retries are bounded per worker iteration.

The original bounded shared queue, native error capture, timings, RAM/drop
samples, periodic flush, late USB detection and disabled fast path remain.
Logs can still lose buffered records at abrupt power loss; this is separate
from preserving existing sessions. Logs never fall back to internal cards.
Only the small setting files are written there. Logs contain native diagnostic
text and media/device context; inspect them before sharing.

## Car verification

1. Install the complete update using the established procedure and confirm
   7.0.6.MAX20. Test existing music/navigation with debugging Off.
2. Enable debugging, wait two seconds and turn the car fully off. Restart with
   USB inserted: Debugging should still be On and logging should start.
3. Toggle On/Off repeatedly in light/dark themes and leave/return to Settings.
   The status should show one clean line. Save Off and check another restart.
4. Capture two ignition sessions and more than eight chunks. Earlier files,
   including MAX19 logs, must remain unchanged. Try USB removal/reinsertion.

Copy the entire logs folder and run:
python analyze_debug_logs.py PATH_TO_LOGS --output summary.json
Existing tools understand the new debug-*.log names. A raw result or missing
end event is not proof of completed hardware action or a crash.

Written MIPS instructions are tested in explicit OS/filesystem/GDI fixtures.
Native storage durability, touchscreen repaint and sustained car operation
still require the physical checks above. This is a local test candidate.
Previous releases and the supplied four-card backup remain untouched.
'''


def main():
    s=(P/'package_max19.py').read_text()
    s=s.replace('Full MAX18 successor,','Full MAX19 successor,')
    start=s.index("GUIDE='''");end=s.index("\n\n\ndef dependencies",start)
    s=s[:start]+'GUIDE='+repr(GUIDE)+s[end:]
    s=s.replace('from build_max19 import','from build_max20 import')
    s=s.replace('maxmade-7.0.6.MAX19','maxmade-7.0.6.MAX20')
    s=s.replace('maxmade-7.0.6.MAX18','maxmade-7.0.6.MAX19')
    s=s.replace('1911','1916').replace('Packing full MAX19','Packing full MAX20')
    s=s.replace("['build_max19.py','debug_image.py','debug_runtime.py','debug_clients.py',\n        'verify_max19.py','analyze_debug_logs.py','preview_debug_settings.py','package_max19.py']", "['build_max20.py','debug_image.py','debug_config20.py','debug_runtime20.py','debug_clients20.py',\n        'verify_max20.py','verify_settings20.py','analyze_debug_logs.py','prepare_debug20.py','prepare_package20.py','package_max20.py']")
    s=s.replace("evidence=delivery/'debugging-evidence'","evidence=delivery/'debugging-fixes-evidence'")
    s=s.replace("    previews=ROOT/'build/max19-debugging-previews-01'\n    shutil.copytree(previews,delivery/'previews/debugging')\n",'')
    (P/'package_max20.py').write_text(s,encoding='utf-8')
    v=(P/'verify_max19.py').read_text()
    start=v.index('def settings_cases(');end=v.index('\n\n\ndef main()',start)
    v=v[start:end].replace("                cases.append('Settings page='", "                assert not draw, 'Refresh must not draw over old status'\n                assert len(m.invalidations)==1, 'Toggle must request background repaint'\n                cases.append('Settings page='")
    (P/'verify_settings20.py').write_text('from verify_max19 import VM,STACK,MAGIC\nfrom inspect_wave_queue import STOP\nimport json\n\n'+v,encoding='utf-8')


if __name__=='__main__':main()
