# MediaNav MAXmade 7.0.6.MAX18

[Download the complete upgrade.lgu](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX18/upgrade.lgu)

**The owner tested MAX18 in the car, reported that everything looks good, and
approved publication on 13 October 2026.** Bluetooth artwork was confirmed
working in MAX15 and is retained. The [test-device profile](../../docs/test-device.md)
records the development hardware and reported phone setup.

## Features

- **Bluetooth album art sync:** current-track covers from the phone appear in
  the large artwork area, with the USB-style player layout and title/artist information.
- **Direct navigation launch:** Navigation and Map open without the recurring
  caution screen and Agree button, including after restarting the application.
- **Redesigned UI throughout:** Navigation joins Home, Settings, Radio, Phone
  and Media, together with the volume popup. Both dark and light system themes
  use matching styling; the light theme keeps its light background.
- All earlier Bluetooth audio/title/playback-state, selected-label, USB,
  navigation-corruption, updater and DBoot improvements remain included.

## Changes since MAX15

MAX16 introduced the navigation skin, validated against the owner's installed
archive and engine. MAX17 redesigned the volume popup in both themes. MAX18
makes the existing navigation caution acceptance state default to accepted and
retains it through native stop/restart paths. Nine AppMain instructions and its
checksum implement that final change; the existing launch handlers remain.

The navigation engine, map road schemes and safety symbols are retained.
No newer maps, licenses, routes, phonebook contents or other private backup
data are added. The navigation resource input is reproduced from the identical,
hash-pinned public 4.1.0 archive. The system's light/dark styling and Nav skin
are separate resource banks; this release does not recolor the map's road schemes.

## Complete package and validation

- **1,919 payload files.** Every one of the 1,918 MAX15 paths is retained:
  1,910 files are identical, eight change, and the navigation skin is added.
- Compared with MAX17, all 1,919 paths are retained and 1,917 are byte-exact;
  only AppMain and the version file change.
- LGU size: **51,933,394 bytes**.
- SHA256: `d474cd4e80d12c868837eb71d0251b6089cc3d0c4cc3a1163fd098bd96fd58d1`.
- Independent full LGU decoding, a separate pinned PC extraction, full payload
  hashes and delivery ZIP checks passed before the owner's car test.
- Offline native-instruction checks cover direct Navigation/Map launch,
  constructor failure and acceptance reset paths at three image bases.
  Volume/skin checks cover graphics, labels and archive contracts.

The owner's report approves the installed build on this test unit. It does not
establish a separately enumerated cold-boot/GPS/guidance test matrix, broader
hardware compatibility or rollback. Use the [main installation guide](../../README.md).

Original pre-test records remain unchanged. Their historical pending-test and
publication flags are supplemented by [device status](device-status.json) and
[publication status](publication-status.json), rather than rewritten.
The [build manifest](build-manifest.json), [member plan](member-plan.json),
[packaging verification](packaging-verification.json) and
[checksum](SHA256SUMS.txt) pin the exact tested LGU.

## Source and reproduction

[The MAX18 plan](../../src/patches/max18.json) records every output hash and
guarded changes from MAX15. [The source manifest](source-manifest.json) pins
the exact cumulative source/evidence snapshots delivered with the build,
including Nav and volume generators and the navigation acceptance patch.
Prior release sources and feedback remain preserved.

Use **Windows Python 3.14.2**, with zlib runtime **1.3.1.zlib-ng**, for exact
navigation archive reproduction. Other deflaters can produce identical skin
contents with different ZIP bytes; the tool refuses that substitution.
Source checks remain compatible with Python 3.12 or newer. Input preparation reads the pinned historical MAX04
LGU from Git history and applies the published MAX15 recipe. Navigation input
preparation downloads and verifies the public 4.1.0 backup, then extracts only
its identical navigation skin. These are build inputs, not installation steps:

```powershell
python tools/check_max18_release.py
python tools/release_max18_payload.py --prepare-input .inputs/max18-baseline
python tools/release_max18_payload.py --prepare-nav .inputs/max18-navigation.zip
python tools/release_max18_payload.py --baseline .inputs/max18-baseline --navigation .inputs/max18-navigation.zip --out build/max18-reproduced
```

Reproduction verifies every one of the 1,919 payload files and all 1,921 skin
members, including 274 authored resource edits and 1,647 untouched members.
It refuses changed inputs and writes to a fresh output directory. This
reproduces the payload, not the vendor application source or a guaranteed
byte-identical LGU container after repacking. Raw phone logs, received covers,
song metadata and private device backup files are excluded from publication.
