MAX35 is a **complete test release** for first-generation MediaNav units originally running 4.x. It carries forward the public MAX33 payload and adds two fixes for issue #74.

- **Driving Eco²** uses the 4.x packet IDs, restoring trip and coaching routing and preventing an Eco packet from clearing DSI settings.
- **Android Bluetooth cover art** updates the AVRCP controller record. Unpair and pair again after updating so the phone reads the new record.

Thanks to [@darknessguto-wq](https://github.com/darknessguto-wq) for diagnosing both bugs, providing the patches, and testing them on a Renault Logan with a Galaxy S25+ and Spotify.

**MICOM TEST** is still under investigation. The contributor tested their patches on the vehicle. This exact LGU passed offline verification and awaits its first vehicle test. Follow the [normal installation guide](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade#before-you-start) and leave power and USB connected until normal startup and the version screen confirm MAX35.

Offline verification covered all **1,921 payload files** through two extraction paths. **1,914** match the public MAX33 package byte for byte, including the kernel and MCU firmware. All **187 installer and recovery checks** passed, along with the Eco and cover-art instruction checks.

`upgrade.lgu` is **52,493,736 bytes**. SHA-256 `29121ea3ac6c4a88f308de34ad1b58301c011f1ba8874d8b36a6a39cd1c6b857`.
