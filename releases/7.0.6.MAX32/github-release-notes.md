MAX32 adds the **iPhone Bluetooth artwork final-packet fix**, contributed by [Emanuel (@emstoica)](https://github.com/emstoica) in [PR #60](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/pull/60). He reports working covers with **Spotify and Apple Music** in his car. MAX32 carries the exact same patched Blue.exe; the complete MAX32 release has not yet been tested in the maintainer's car.

- Accepts the iPhone final cover-art packets previously rejected after transfer began. Packet/header bounds, connection identity, response opcodes, buffer capacity and image decoding checks remain.
- Keeps the MAX31 DBoot/CE recovery correction and all previous UI, navigation, media and saved USB-debugging features.
- Retains all **1,920 MAX31 files**: **1,917 are byte-identical**. Only Blue.exe, the diagnostic revision/checksum and version text change. Display corners, bitmap resizing and the unsuccessful retry experiment are not included.

**Validation:** all member hashes/CRCs, independent LGU decoding and separate pinned-PC-tool extraction passed. The actual patched validator passes 20 packet cases, six omitted-edit negative cases and three relocation-preservation checks. Windows/Linux CI covers the portable recipe. Historical MAX31 checks are preserved as baseline evidence, not claimed as a fresh full MAX32 test suite.

**Still open:** intermittent missing covers after skipping tracks; maintainer iPhone testing; inherited whole-clone relocation, DBoot quick-reboot, installer-failure, rollback and broader hardware validation. These changes do not guarantee recovery from every failure. [Details and evidence](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/blob/7.0.6.MAX32/releases/7.0.6.MAX32/README.md).

This is the **complete upgrade.lgu**, not a patch-only package. Follow the [installation guide](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade#before-you-start); intermediate MAX versions are not required. Intended for first-generation MediaNav originally running 4.x, including converted units; factory Evolution/later hardware is unsupported.

Size: **52,310,397 bytes**. SHA-256:
`2c657ec6056b003681a5c4c77ee3f1b4a6c0cf5e7a5bd8c7ce3b4ab92d1998bb`
