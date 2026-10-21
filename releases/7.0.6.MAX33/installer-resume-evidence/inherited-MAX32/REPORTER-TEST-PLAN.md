# MAX24 reporter test for issues #53 and #54

This candidate adds focused diagnostics and two native failure-path guards. We
still need your unit to determine why the camera setting is not retained and
why navigation stays in London. One combined capture should cover both issues.

## Before the test

Please record how you currently enter Micom: the exact buttons/codes, and any
activation filenames used. If possible, photograph the current navigation GPS
status screen before updating. Note whether GPS worked before the MAX18 upgrade.
There is no need to reinstall an older version just to answer these questions.

Use the complete MAX24 package with the established update procedure. Confirm
`7.0.6.MAX24`. Keep your radio code available: the originally reported entry path
may still restart the radio. The allocation guard addresses a demonstrated code
defect, not every possible reason for a restart.

## 1. Start logging

Insert your USB stick, open Settings and set Debugging to On. Wait until the
status says Logging active, then leave it for another five seconds. Keep logging
enabled throughout the following steps. Existing log files can stay on the stick.

## 2. Navigation first — about 10 minutes

With the vehicle stationary and a clear view of the sky, open Navigation and show
the map's current vehicle position. Distinguish this from the saved Home address
or a selected destination. Leave Navigation running for about ten minutes.

Photograph its GPS status screen and the map position. Record approximately when
you opened Navigation and when/if the position became correct. If available,
include fix status, satellites used/visible and displayed GPS date/time. You do
not need to change the saved Home address, clear navigation data or drive to
collect this first diagnostic capture.

The new observer logs sentence types and status without coordinates. If there
are no GPS records, that alone does not prove the receiver is silent: navigation
startup, the active data path or the diagnostic backend may also explain it.

## 3. One service-menu attempt

Return to the main interface, then use the same Micom entry method as in your
original report. Please note the method and take a short video if practical.
The `3746` and `3748` entries select different service paths; do not substitute
codes or repeatedly try unrelated service options to make this test work.

If the radio blanks/restarts, stop this part of the test and note the approximate
time. After normal startup, allow Logging active to return and wait five seconds.
The logs can help distinguish a selected power-state path, rejected write or
allocation failure. A missing end record alone is not conclusive.

If the menu opens, photograph its current RVC and GPS states. If RVC is Off and
you want to enable your installed camera, tap RVC once to On and wait five
seconds. Record whether the display stays On or returns to Off. If it returns
to Off, the new guard indicates that the write was rejected; do not keep retrying.
If RVC is already On, leave it unchanged and report that state.

**Do not press DSI_Config as a Save action.** Its native command requests CAN
configuration. Do not use Clear Virgin, ClrCnf, factory reset, firmware update,
other configuration toggles or diagnostic write/import buttons for this test.
Leave the GPS-fitted setting as it was.

## 4. Normal shutdown and restart

Exit the menu normally if possible. Leave Debugging On, then switch the car off
normally and let the unit fully shut down. Restart once with the USB connected.
Check that logging resumes and photograph RVC state again if the menu can be
opened normally. If a compatible camera is installed and RVC remained enabled,
check whether selecting reverse shows its image while stationary.

Also note whether navigation returns to the correct position after this restart.

## Return

Send every file/chunk from `MAXmade/logs`, plus the entry method, approximate
event times, screenshots and these results:

1. Navigation: still London, corrected itself, or receiver fix shown but map wrong?
2. Service menu: opened, blanked/restarted, or nothing happened?
3. RVC toggle: stayed On, returned to Off immediately, or changed only after reboot?
4. Camera: image, black screen, no reverse-camera screen, or not yet installed?

Share raw logs and location-bearing screenshots privately. Existing native logs
may include device details; the new GPS observer deliberately omits coordinates.
Please do not publish VIN, radio security details or a precise home location.
