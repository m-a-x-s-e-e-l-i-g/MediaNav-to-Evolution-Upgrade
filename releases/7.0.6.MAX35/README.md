# MAXmade 7.0.6.MAX35

MAX35 is a complete prerelease based on the public MAX33 package. It targets first-generation MediaNav units originally running 4.x. This build focuses on [issue #74](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/74).

- **Driving Eco²** routes the original 4.x trip and coaching packets to the correct decoders and stops the Eco packet from clearing DSI configuration files.
- **Android Bluetooth cover art** updates the AVRCP controller record so compatible Android phones can offer cover art. Unpair and pair again so the phone reads the new record.
- **MICOM TEST** still needs investigation. If it restarts the unit, capture the USB debug logs from one stationary attempt and include the exact menu steps.

Thanks to [@darknessguto-wq](https://github.com/darknessguto-wq) for diagnosing both compatibility bugs, supplying the patches and testing them on a Renault Logan with a Galaxy S25+ and Spotify.

The reporter tested their patches on the car. This exact LGU has been verified offline and awaits vehicle confirmation.

The [technical notes](../../analysis/issue74-firmware-candidates.md) describe the modified instructions. The build sources capture the release-specific changes and generated installer manifest. They use the existing Windows MediaNav build workspace and its pinned MAX33 input, LGPL container tools, MIPS toolchain and WinCE fixtures. See the [vehicle test plan](REPORTER-TEST-PLAN.md) for checks on a physical unit.

Offline verification covered all **1,921 payload files** through two extraction paths. **1,914** match the public MAX33 package byte for byte, including the kernel and MCU firmware. All **187 installer and recovery checks** passed, along with the Eco and cover-art instruction checks.

`upgrade.lgu` is **52,493,736 bytes**. SHA-256 `29121ea3ac6c4a88f308de34ad1b58301c011f1ba8874d8b36a6a39cd1c6b857`.
