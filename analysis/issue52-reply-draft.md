Thanks for the details. I've prepared a **MAX24 diagnostic test build** for the two problems, now tracked separately in #53 (Micom/RVC) and #54 (GPS).

**Test release:** https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/tag/7.0.6.MAX24

It is a complete update, so there is no need to install MAX19–MAX23 first. This is an experimental test candidate, not a confirmed fix for your particular radio.

The build corrects two failure paths: a rejected RVC configuration write no longer leaves the control showing an applied change, and service-menu allocation failure no longer passes a null object to the window creator. It also adds focused GPS diagnostics without changing your maps, saved home position or receiver settings.

Would you be willing to try one capture? The ZIP contains **REPORTER-TEST-PLAN.md**:

1. Enable **Debugging** in Settings with a USB stick inserted; wait for **Logging active**.
2. Open Navigation with a clear view of the sky and leave it running for about ten minutes. Photograph its GPS status and current-position screen.
3. Try your existing Micom entry method once and record the exact buttons/codes. If it restarts the radio, stop that part and note when it happened.
4. If the menu opens and RVC is Off, try enabling RVC once and note whether it stays On or returns to Off. **DSI_Config is a CAN-configuration request, not a general Save button**; please do not use it or the clear/reset buttons for this test. Leave the GPS-fitted option unchanged.
5. Restart normally, then check whether the RVC state and navigation position are retained/correct.

Please keep all log chunks from `MAXmade/logs` and note the approximate event times. We can arrange a private transfer of the raw folder; existing native logs can contain device details. The new GPS records deliberately omit coordinates. Please keep VIN, radio security information and a precise home location out of public screenshots.

The extra trace should help us distinguish satellites merely being visible from usable positioning data, and separate a service-menu entry problem from a rejected configuration command. Both issues will remain open until your unit confirms the result.
