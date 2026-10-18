# Releases

## Download

- [7.0.6.MAX30](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/tag/7.0.6.MAX30) — current; owner upgraded from MAX26, reports normal operation and approved publication on 18 October 2026. iPhone artwork remains untested.
- [7.0.6.MAX18](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/tag/7.0.6.MAX18) — previous; owner tested in the car and approved publication on 13 October 2026.
- [7.0.6.MAX15](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/tag/7.0.6.MAX15) — previous; owner installed and confirmed Bluetooth album art works.
- [7.0.6.MAX10](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/tag/7.0.6.MAX10) — historical release; its original artwork failure record is retained.
- [7.0.6.MAX04](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/tag/7.0.6.MAX04)
- Releases contain one downloadable asset: **`upgrade.lgu`**.
- The [main guide](../README.md) explains compatibility, preparation and installation.
- MAX30 installation/general operation and MAX15 working artwork are reported by the owner on the [documented test device](test-device.md). MAX30 iPhone artwork, recovery fault scenarios, broader compatibility and rollback remain unverified; see its [known limits](../releases/7.0.6.MAX30/README.md#known-installer-and-hardware-limits). Historical feedback is preserved.

## Build and verify

1. Start from the complete previous release. Preserve every member unless a change is explicitly reviewed.
2. Apply hash-guarded code edits and approved native artwork. Keep navigation unchanged unless separately scoped.
3. Run the relevant instruction/loader, layout, resource and behavior checks on the written files.
4. Pack the entire payload with the pinned Windows PC `dir2lgu.exe`, profile `m1`, and the new version.
5. Independently decode the LGU; verify header/version, XOR/CRC, ZIP integrity and every member's size/hash.
6. Round-trip with the independently pinned PC `lgu2dir.exe` and compare all files.
7. Commit the recipe, complete member manifest, checksum, release notes and evidence; review them in a PR.
8. Tag the reviewed commit and upload only the complete `upgrade.lgu` to GitHub Releases. Verify the uploaded SHA256.

## Packing tools

- [LGU-file-tools](https://github.com/m-a-x-s-e-e-l-i-g/LGU-file-tools), pinned in [provenance.json](../analysis/provenance.json).
- Place local PC tools in ignored `tools/vendor/lgu-favremod/`.
- `dir2lgu.exe` SHA256: `d8424c16f6832a4f7b1e474e815fee5120cf5041d2d498dbafb030272ec1c9b0`.
- `lgu2dir.exe` SHA256: `89e1731808f3912bcfd40f0ef0dafddf1c04cdb16fc3cb4e7e6be44a0c16f54f`.
- The original packing/verification implementation is [build_review_update.py](../tools/build_review_update.py); it also needs the pinned upstream XOR header in `sources/MediaNavMods/pc/lgutool/lgu2dir/xorArray.h`.
- [build_cumulative_maxmade_update.py](../releases/7.0.6.MAX04/build-sources/build_cumulative_maxmade_update.py) records the original MAX04 integration and packaging process.
- Container bytes can vary when repacking. Payload reproduction must match all member hashes; an unchanged official download must match its published LGU checksum.

## Release records

- [MAX30 notes and device feedback](../releases/7.0.6.MAX30/README.md)
- [MAX30 full build manifest](../releases/7.0.6.MAX30/build-manifest.json)
- [MAX30 comparison with the public MAX18 baseline](../releases/7.0.6.MAX30/public-baseline-comparison.json)
- [MAX30 frozen source manifest](../releases/7.0.6.MAX30/source-manifest.json)
- [MAX30 device status and pending checks](../releases/7.0.6.MAX30/device-status.json)

- [MAX18 notes and device feedback](../releases/7.0.6.MAX18/README.md)
- [MAX18 complete build manifest](../releases/7.0.6.MAX18/build-manifest.json)
- [MAX18 cumulative edit plan and Nav addition](../src/patches/max18.json)
- [MAX18 exact source snapshots](../releases/7.0.6.MAX18/source-manifest.json)

- [MAX15 notes and device feedback](../releases/7.0.6.MAX15/README.md)
- [MAX15 complete build manifest](../releases/7.0.6.MAX15/build-manifest.json)
- [MAX15 cumulative edit plan](../src/patches/max15.json)
- [MAX15 exact source dependencies](../releases/7.0.6.MAX15/source-manifest.json)

- [MAX10 notes and device feedback](../releases/7.0.6.MAX10/README.md)
- [MAX10 complete build manifest](../releases/7.0.6.MAX10/build-manifest.json)
- [MAX10 cumulative edit plan](../src/patches/max10.json)
- [MAX10 code source snapshots](../releases/7.0.6.MAX10/source-manifest.json)

- [MAX04 notes and screenshots](../releases/7.0.6.MAX04/README.md)
- [Complete build manifest](../releases/7.0.6.MAX04/build-manifest.json)
- [Staging manifest](../releases/7.0.6.MAX04/staging-manifest.json)
- [Integration and retained-fix proof](../releases/7.0.6.MAX04/integration-proof.json)
- [Checksum](../releases/7.0.6.MAX04/SHA256SUMS.txt)

Keep hardware results separate from offline fixture results. Use a prerelease until the intended device installation/runtime has been checked.
