# MediaNav MAXmade 7.0.6.MAX15

[Download the complete upgrade.lgu](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX15/upgrade.lgu)

**Bluetooth album art works in the owner's MAX15 car test.** The owner installed
MAX15, confirmed artwork and authorized this release on 12 October 2026.
The [test-device profile](../../docs/test-device.md) records the exact supplied
specifications, OS readings and reported phone setup.

## Changes since the public MAX10 release

- Bluetooth artwork: accept the phone's valid OBEX 1.0 CONNECT response while
  retaining protocol/ownership checks, and correct the AppMain worker's thread
  priority for Windows CE. This unit rejects desktop priority -1; CE priority 4
  allows the background artwork worker to start.
- Bluetooth player uses USB's large artwork slot, title/artist presentation and
  playback layout, with native Bluetooth commands and menus retained.
- Bluetooth play/pause icon follows native playback notifications.
- Settings use the redesigned style; the light theme stays light and adopts
  matching Home, Settings, Radio, Phone and Media styling.
- All earlier audio/title, selected-button, USB, navigation-corruption, updater
  and DBoot improvements are retained. Navigation skin redesign and new maps
  are not included.

Temporary empty-slot diagnostics remain: S0/S1/S2 and D1–D9, plus S3 startup
blocked, S4 timer failed, S5 priority failed and S6 resume failed. Accepted
artwork hides the caption. These are last-paint snapshots for troubleshooting.

## Complete package and validation

- **1,918 payload files**, with no missing or added paths.
- Complete MAX14 successor: **1,916 byte-exact files**; only AppMain and version
  change from MAX14. Changes since MAX10 also include the Settings/light assets
  and Bluetooth acquisition fix described above.
- LGU size: **34,584,883 bytes**.
- SHA256: `ee416cfd77687448b94d046b79049793353cd40288a1675bfcf5a15504c28a98`.
- Independent LGU decoding and a separate PC extractor verify every member.
- Actual unit kernel instructions reproduce the MAX14 priority rejection/S0.
  The corrected installed window route reaches artwork display offline. Six
  startup failures and 17 artwork/lifetime cases pass, including three received
  covers, decoder failures, stale/disconnected artwork and popup ordering.
- Mutation, import, unwind, section and relocation audits pass. MAX14's playback
  and theme checks apply to unchanged helpers/assets. Full payload reproduction
  from the pinned historical MAX04 input is checked separately.

Offline CE scheduling, COM and GDI responses remain fixtures. The newer physical
confirmation is in [device status](device-status.json). The owner's MAX15 report
confirms cover display; it does not claim a completed cross-device, rollback or
full track-skip/reconnect test matrix.

The [build manifest](build-manifest.json), [member plan](member-plan.json),
[native recipe](recipe.json), [offline verification](verification.json) and
[checksum](SHA256SUMS.txt) preserve the exact tested package. Build records are
immutable evidence produced before car testing; their historical `hardware_tested`
and `published` flags are superseded by [device status](device-status.json) and
[publication status](publication-status.json), rather than rewritten.

## Source and reproduction

[The complete MAX15 plan](../../src/patches/max15.json) contains all 1,918 member
hashes and guarded changes from the historical MAX04 input. Authored native BMPs
are in `src/ui/max15/` or referenced unchanged assets. The [source manifest](source-manifest.json)
pins cumulative MAX11–MAX15 patch constructors, builders and verifiers, including
identical dependencies retained from earlier releases. Historical builders keep
their original workspace paths; use the portable plan for reproduction:

```powershell
python tools/check_max15_release.py
python tools/release_max15_payload.py --prepare-input .inputs/max15-baseline
python tools/release_max15_payload.py --baseline .inputs/max15-baseline --out build/max15-reproduced
```

This reproduces every payload byte; repacking may produce a different LGU
container. Raw phone logs, received covers, song metadata and phone identifiers
are excluded from source publication. Follow the [main guide](../../README.md)
for compatibility and installation.
