# MAX33 Driving Eco², Android cover art and MICOM TEST

[Issue #74](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/74) reports a first-generation MediaNav in a Brazilian 2014/2015 Renault Logan. The reporter tested MCU versions `4.0.6.0413(C2)` and `4.1.0.0414(C2)` and confirmed that their candidate restored Eco scoring and trip recording on a 1.6 km drive with 4.1.0.

## Driving Eco²

The MAX33 type-2 dispatcher uses `e/g/h/j`. Both the 4.0.6 removal and official 4.1.0 MicomManager binaries use `d/f/g/i`. The MAX33 comparison sends the 4.x coaching packet `g` to the trip decoder and skips the real trip packet `f`. In the shared type-2 handler, `d` also takes a path that rewrites `DSI_config.bsd` and deletes the Eco and voice-recognition DSI files.

The candidate uses the four 4.x IDs and skips the single clear-data path for `d`. Its other nearby DSI routes still reach their original handlers. Use this candidate for the reported first-generation 4.x setup. An MCU that uses the Evolution IDs or genuinely sends the `d` clear-data notification requires a separate compatibility decision. The two-byte `d` field and configuration readback still need hardware coverage.

## Android Bluetooth cover art

The reporter's [Galaxy S25+ and Spotify test](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/74#issuecomment-7088802704) showed that Android enabled its cover-art service after the controller record changed from `0x0241` to `0x03C1` and the devices were paired again. AOSP's SDP handling checks the peer controller feature mask before enabling cover art. [AOSP SDP implementation](https://android.googlesource.com/platform/packages/modules/Bluetooth/+/4c1664bcb9199db8d3e6dd60bec818ecf9379760/system/stack/sdp/sdp_utils.cc)

The separate candidate applies the reporter's SDP change. The client still requests linked thumbnails while the record also advertises GetImageProperties and GetImage. Keep this as an independent compatibility test until Android and iPhone results are available for a release candidate.

## MICOM TEST restart

MAX33 retains the earlier guarded window-creation call at `0x49ca4`. The restart still occurs on the affected unit with that guard in place. The next evidence is one stationary attempt with USB debugging enabled and a recoverable copy of the logs, including the preceding normal startup and the exact menu path.

Compare event 406 begin/end with the last native power-state and MICOM messages. A persisted begin with no end narrows the investigation to window creation or later calls on that path. An absent begin is ambiguous because a restart can interrupt the log flush. The security code and vehicle identifiers can be omitted. Leave DSI options alone during this capture. [Related restart report in #53](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/53)

## Offline reproduction

With `pefile` and `unicorn` installed, point the verifier at the extracted MAX33 system directory:

```sh
python tools/verify_issue74.py "/path/to/payload/upgrade/Storage Card/System"
python tools/patch_issue74.py eco "/path/to/MicomManager.exe" "/new/path/MicomManager.exe"
python tools/patch_issue74.py android-cover "/path/to/Blue.exe" "/new/path/Blue.exe"
```

The verifier executes the original and modified MIPS dispatch and SDP instructions, verifies PE checksums and checks for changes outside the listed instruction words and the checksum. The MAX33 LGU matches the published asset's SHA-256, and both executable inputs also match the local MAX34 candidate byte for byte.

| Output | SHA-256 |
| --- | --- |
| MicomManager.exe | `f842c1d04ed88f2a9006815b1136a0ecf69bb59bea333385a536a174eeb71130` |
| Blue.exe | `d71251758c44796a70768303b7491d3c32745743185f6e46c5ce1e1629c18e5c` |

The Blue.exe hash matches the prefix reported in the issue. The outputs are for offline testing and integration into a future full LGU. A full installer needs a matching transaction manifest for the final binaries.
