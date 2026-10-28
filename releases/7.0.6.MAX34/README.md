# MAXmade 7.0.6.MAX34 — USB track transition candidate

Local candidate; USB audio still needs physical car confirmation. MAX33 remains
the public download. Complete MAX33 successor, with every prior payload path.

## USB correction

A pending DirectShow pause can now be cancelled by Stop. Completion must still
be confirmed before state publication, seeking, interface release or a new graph.
Preserve the native completed Running -> Pause -> Stop sequence. Stop/Pause are
issued at most once per transition stage; a stale Running response cannot undo
an issued Stop. The five-second bound, failed-HRESULT checks, pointer guards,
failure cleanup and ownership on an unconfirmed stop stay active.

This corrects the reproducible issue66 guard failure; COM/codec/time calls in
the offline checks are simulated. Native MP3 decoding and audible playback have
not been tested. No claim that every USB/folder-player feature is now proven.
Temperature, profile/theme changes and Bluetooth liveness remain unresolved.

## Installation and inherited behavior

This is the complete update, not a USB patch kit. Use the normal full-update
procedure with stable power and leave USB inserted through installation.
The existing resumable installer is regenerated for this exact payload and uses
MAX34 progress/receipt names, keeping MAX33 metadata separate. Its native healthy
settings migration and recovery algorithm stay the same. All prior features,
kernel, MCU input, DBoot, Bluetooth, navigation, UI assets and settings behavior
are retained. MAX33's first-stage, storage and hardware limitations still apply.

Changed payload: MgrUSB.exe; installer UpgradeManager.exe/Recovery.exe/
InstallResume.exe for the new package identity; diagnostic header/checksum;
Version_Info.txt. There are 1,921 members, six changed and 1,915 byte-exact.
No maps, licenses or private settings are supplied.

## Stationary car acceptance

1. Confirm 7.0.6.MAX34 after the complete install. Start with Debugging Off.
2. Resume a track, pick another from the list, then select the first again.
   Include the reporter's originals, 44.1 kHz/no-cover and small-JPG files.
3. Next/previous track, next/previous folder, end-of-track auto advance,
   pause/play, seeking, source switch away/back and USB unplug/reinsert.
4. Repeat a short test with Debugging On. Turn it Off, wait for Logging off,
   then retain the entire MAXmade/logs folder and identify what was playing.
5. Confirm normal radio/Bluetooth/navigation and saved settings still work.

Report actual audible playback and any unsupported-format popup, delay or
stuck UI. Logs alone do not confirm audio. Do not use clear/virgin/profile
configuration buttons to try to fix temperature or theme behavior.
