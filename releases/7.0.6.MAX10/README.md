# MediaNav MAXmade 7.0.6.MAX10

[Download the complete upgrade.lgu](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX10/upgrade.lgu)

MAX10 is the newest cumulative release. The owner installed it in the car and
reports it as the best version so far. Earlier car tests confirmed corrected
selected-button labels, Bluetooth audio stuttering/delay and Bluetooth track
titles. Those changes are retained in MAX10.

**Bluetooth album art is still an open issue.** MAX10 shows the empty Album art
square after track skips and Bluetooth reconnect. It must not be described as a
working cover-art release. A new phone capture is available for follow-up research.

## Included changes

- All earlier MAXmade system, navigation, USB, UI and Bluetooth changes retained.
- Selected-button text remains visible in Bluetooth options, radio presets and options.
- Bluetooth buffering corrections and the restored native metadata path retain
  the audio and title improvements confirmed in MAX08.
- Artwork placeholder and acquisition code included. MAX09 accepts native zero
  transport policy; MAX10 accepts a captured AVRCP 1.4 advertisement only when
  explicit cover capability and a valid OBEX endpoint are present. These changes
  have not produced actual artwork in the car.

## Complete package and verification

All **1,918 payload files** are included. MAX10 retains the complete local MAX09
release; **1,916 files are byte-identical**. Only Blue.exe and Version_Info.txt
change. AppMain.exe and the audio, title and UI code are unchanged from MAX09.

- LGU: 37,508,996 bytes.
- SHA256: `87f61836ceb3ddf733ecb0d2e9fc4a2ea8e7a0ab5a3c07a3b15b0f59c601243f`.
- Independent LGU decoding and separate PC extractor readback match all 1,918 files.
- Seven artwork and two native title cases pass offline. Artwork success beyond
  captured SDP values uses fixtures, and does not supersede the failed car test.

The immutable [build manifest](build-manifest.json) and [verification](verification.json)
describe validation before installation. [Device status](device-status.json)
records the newer physical feedback. [Member plan](member-plan.json),
[native recipes](native-recipes.json), [checksum](SHA256SUMS.txt) and
[source snapshot manifest](source-manifest.json) preserve the release provenance.

## Code and reproduction

[src/patches/max10.json](../../src/patches/max10.json) contains the complete guarded
MAX04-to-MAX10 edit plan. It reproduces all payload hashes, including four changed
files, from the historical MAX04 LGU pinned in Git history. The original Python
patch constructors, builders and verifier dependencies are byte-exact snapshots
under `build-sources/workspace-tools/` and `build-sources/model-tools/`; unchanged dependencies reference their identical files in `tools/` through the source manifest. The snapshots retain
their original developer-workspace paths; use the compact plan for reproduction
from a normal repository checkout.

```powershell
python tools/check_max10_release.py
python tools/release_max10_payload.py --prepare-input .inputs/max10-baseline
python tools/release_max10_payload.py --baseline .inputs/max10-baseline --out build/max10-reproduced
```

This reproduces the full payload, not a byte-identical repacked LGU or original
vendor C source. Decompiled code remains research material. Raw Bluetooth logs,
phone identifiers and song metadata are not published.

## Installation and limits

Follow the [main installation guide](../../README.md). Copy the downloaded
upgrade.lgu to the USB root and confirm 7.0.6.MAX10 after installation.
The existing first-generation hardware scope remains: units originally on 4.x,
including those already converted to 7.0.5.MD. Factory Evolution hardware is
outside this package's scope. Owner testing covers one unit and phone; broader
compatibility and rollback remain unverified.

Original FavreMod/conversion, DBoot and navigation-fix contributors retain credit.
