# MediaNav MAXmade — {revision}

- **Full update:** all 1,918 files and earlier fixes included.
- **Hardware:** original MediaNav (4.x, minimum 4.0.3), including units converted to 7.0.5.MD. Factory Evolution is unsupported.
- **Status:** experimental; package checks passed, full installation and runtime on the unit remain untested.

## UI

- Dark Home, Radio, Media and Phone screens; existing control positions retained.
- Black active buttons, icon-colored outlines and white labels.
- Voice-assistant icon, subtle album placeholder and caller silhouette.
- Fixed phone search toggle and Radio/Media source-menu borders.
- Navigation layout unchanged; existing corruption fix retained.

## Bluetooth

- Eight saved phones; one connected phone at a time.
- Earlier audio-delay fix retained.
- One retry if the first audio opening fails after connecting.

## USB and system

- Improved playback resume and saved repeat/shuffle settings.
- Consistent option selections; safer titles, tags, artwork and playlists.
- Less repeated sorting, folder and status-copy work.
- Touch-release, startup and shared-memory error handling fixes.
- English updater/DBoot text; verified file copies and clearer update errors.

## Before and after

UI previews from original and updated assets, with sample data and approximate fonts; not device photos.

| Screen | Before · 7.0.5.MD | After · MAX04 |
| --- | --- | --- |
| Home | ![Original home](screenshots/home-before.jpg) | ![MAX04 home](screenshots/home-after.jpg) |
| Radio | ![Original radio](screenshots/radio-before.jpg) | ![MAX04 radio](screenshots/radio-after.jpg) |
| Media | ![Original media player](screenshots/media-before.jpg) | ![MAX04 media player](screenshots/media-after.jpg) |
| Phone | ![Original phone keypad](screenshots/phone-before.jpg) | ![MAX04 phone keypad](screenshots/phone-after.jpg) |

## Install

- Keep your radio code, unit backup and tested CE/DBoot recovery access.
- Use a FAT32 USB stick (64 MB–4 GB); copy only `upgrade.lgu` to its root.
- Start the engine, insert USB and confirm the offered version is **{revision}**.
- Accept the update; keep the engine running and USB connected until finished.
- Enter the radio code if asked; verify the system version and normal operation.
- This full update includes OS/boot/MCU files and can replace settings. Rollback is untested.

## Checks and files

- All 1,918 files verified by independent LGU decoding and PC extraction.
- Combined UI, USB and touch checks passed; native timing remains untested.
- M1 artwork approved; other color profiles still need contrast checks.
- [SHA256SUMS.txt](SHA256SUMS.txt) · [Build manifest](build-manifest.json) · [Integration proof](integration-proof.json).
- Based on the original 7.0.5.MD conversion and its existing navigation fix; original contributors retain credit.
