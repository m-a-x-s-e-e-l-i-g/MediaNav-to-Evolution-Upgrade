MAX31 corrects the false recovery prompt introduced in MAX29/MAX30 when intentionally entering Windows CE through DBoot. **The owner authorized release on 20 October 2026; MAX31 has not yet been tested in the car.**

- **Intentional DBoot desktop entry:** the ROM launcher recognizes the native one-shot Windows CE request before treating a leftover startup marker as a failed boot. The explicit desktop choice clears only that startup marker.
- **Recovery desktop initialization:** the recovery menu starts CE through DBoot's native initialization rather than launching Explorer directly. Genuine recovery retains its failure marker, and its desktop entry also handles read-only marker storage. This addresses a concrete difference in the old desktop path; **the reported quick reboot still needs a car test**.
- **Clearer recovery wording:** a leftover startup marker alone does not prove that an installation is incomplete. Actual installer STOP/error recovery remains in place.

This is the **complete update**, retaining all **1,920 MAX30 paths**: 1,915 files are byte-identical. Only NK.bin, dboot.exe, Recovery.exe, the shared diagnostic revision/checksum and version text change. Updater/MCU and Bluetooth, iPhone-artwork, audio and navigation behavior remain as in MAX30. Intermediate MAX versions are not required.

Download **upgrade.lgu** and follow the [installation guide](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade#before-you-start). Intended for first-generation MediaNav originally running 4.x, including converted units; factory Evolution and later hardware are unsupported.

**Validation:** 1,137 combined offline cases, with inherited results reused only for matching behavior bytes and their provenance recorded. Independent LGU decoding/extraction and all member hashes passed; 115 frozen source files accompany the evidence. This is the exact verified LGU, published without rebuilding.

**Still unverified:** physical MAX31 DBoot/recovery behavior, the quick CE reboot, iPhone/Spotify artwork, injected installer failures, rollback and broader hardware compatibility. Known automatic maintenance, formatter and stalled-update gaps remain; this does not guarantee recovery from every failure. [Detailed evidence and limits](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/blob/7.0.6.MAX31/releases/7.0.6.MAX31/README.md).

Size: **52,310,420 bytes**. SHA-256:
`521e9192c1dea4ae4d64d5346db0cc441c638e6156b7227af8a64eac162979b3`
