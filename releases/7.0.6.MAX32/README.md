# MediaNav MAXmade 7.0.6.MAX32

[Download the complete upgrade.lgu](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX32/upgrade.lgu)

MAX32 adds the iPhone final-cover-packet fix from [PR #60](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/pull/60),
contributed by [Emanuel / emstoica](https://github.com/emstoica). He reports
working artwork with Spotify and Apple Music in a real car. The release contains
his exact patched Blue.exe hash. **The complete MAX32 has not yet been tested in
the maintainer's car.** The owner authorized this normal release on 20 October 2026.

## Change and complete payload

Six rejecting GET branches become NOPs in the original and active instrumented
validator copies. This permits the tested final-packet/header-Length variations
while retaining packet/header bounds, connection identity, response opcode,
capacity, nonempty-result and image-decoder checks. The
[native patch record](../../docs/cover-art-iphone-fixes.md) gives addresses and attribution.

All **1,920 MAX31 files remain**; **1,917 are byte-identical**. Only:

- System/Blue.exe: six validator words and PE checksum.
- System/CmnDll.dll: diagnostic revision string/checksum only.
- System/Version_Info.txt: 7.0.6.MAX32.

The [baseline comparison](public-baseline-comparison.json) explains every changed
hash. AppMain/display, DBoot, NK, recovery, updater/MCU, audio and navigation are
unchanged. Saved USB logging and all earlier UI/media changes remain included.
The optional corners/bitmap-resize/retry experiment is excluded.

Size: **52,310,397 bytes**. SHA-256: `2c657ec6056b003681a5c4c77ee3f1b4a6c0cf5e7a5bd8c7ce3b4ab92d1998bb`.
[Checksum](SHA256SUMS.txt), [full build manifest](build-manifest.json),
[member plan](member-plan.json), [frozen sources](source-manifest.json).
The only downloadable release asset is upgrade.lgu. Follow the
[installation guide](../../README.md#before-you-start); no intermediate MAX
versions are required. Do not interrupt installation to exercise recovery.

## Verification and device evidence

[Package verification](package-verification.json) records independent LGU
decoding/header/ZIP checks and a second extraction with the hash-pinned native
PC tool, comparing every member against the expected full payload.
[Native-byte verification](verification.json) records **20 actual packet cases**,
**six omitted-edit negatives** and **three relocation-preservation cases**.
The latter establish equivalence of unchanged relocated code, not whole-image
loader correctness. No replacement GET model is assembled for these tests.
All 132 source pins match the build snapshots.

The portable PR60 recipe runs on Linux/Windows CI with nine input/name/retention
tests and full member verification. The MAX32 release checker validates this
manifest, payload comparison, source pins and the physical-status distinction.
Earlier MAX31 boot/application evidence is retained in the frozen baseline
inputs. Its 1,137 cases are **historical baseline evidence**, not a claimed
combined suite rerun against this changed Bluetooth validator.

[Device status](device-status.json) distinguishes the contributor's iPhone car
report from complete MAX32 testing. The original contribution was AI-assisted
with Claude Code; the contributor's device test and maintainer offline review
are separate evidence sources. No raw/private car logs or backups are published.

## Known installer and hardware limits

Intermittent missing covers after skipping tracks remain unresolved. Other
iPhones/apps, the maintainer's iPhone and complete MAX32 installation/runtime
need car testing. Normal boot, DBoot desktop/return, the reported quick CE reboot,
injected installer failure, rollback and broader hardware remain unverified.

The inherited active GET clone has an unrelocated HEADER call. Full alternate-base
clone execution remains unsupported by the fixtures for both MAX31 and MAX32;
this release adds no absolute native address/frame and does not repair that
separate limitation. Three relocation-preservation cases are not a claim of
successful whole-clone rebased execution.

Inherited Card2 maintenance above saved counter175 has unchecked backup/format/
restore calls; native formatting may report success after failures, and some
worker waits lack deadlines. First installation begins in the old updater.
Kernel publication is not power-loss atomic. Damaged storage, a nonbooting
kernel, bootloader or MCU fault can prevent recovery. These known gaps remain;
this is not universal protection against lockout. The reporter's MICOM restart
also remains unresolved. The issue56 repair kit retains its original payload
and is not a MAX32 repair kit.

## Developer reproduction

The [frozen complete-release builder](build-sources/tools/build_max32.py)
starts from the exact public MAX31 LGU and its recorded 1,920-member manifest,
patches the guarded Blue.exe plus diagnostic/version labels, and uses the pinned
Windows PC dir2lgu/lgu2dir tools. From this repository on Windows:

```console
python -m pip install -r tools/requirements-cover.txt
python tools/verify_cover_patches.py --prepare-input .inputs/cover/MAX31.lgu
python tools/build_max32.py --baseline .inputs/cover/MAX31.lgu --tools-dir path/to/pinned-PC-tools --output build/max32-fresh
```

See [packing-tool pins](../../docs/releases.md#packing-tools). Repacking can change
container bytes; payload member hashes must match. The official published LGU
must match the exact release checksum above.
