MAX33 adds **resumable application installation** and an explicit **Repair / resume update** action for the stopped-installation path inherited by MAX32.

**Hardware validation: UNCONFIRMED.** MAX33 has not been installed or tested on a physical MediaNav. The owner authorized this as the main normal release on 22 October 2026 before hardware testing. The reported installation fix and recovery behavior remain physically unconfirmed; the results below are offline.

- Saves copy and final-verification progress in checked 256 KiB checkpoints and automatically resumes an existing application transaction after restart.
- Keeps current settings and the retained TFAT backup during explicit repair; does not replay settings formatting or flash kernel/MCU from the worker. Healthy native settings migration remains unchanged.
- Keeps **Repair / resume update** and **Windows CE access** as separate recovery actions. Version is installed last, and normal startup requires verified completion evidence.
- Cleans known installation sources only after commit, with interrupted cleanup resumable too. A later complete upgrade retains the native first-stage entry.
- Retains MAX32's contributor iPhone final-packet fix and all earlier media, navigation, UI, DBoot and saved USB-debugging features.

**Validation:** 185 offline MIPS/API-fixture checks passed. Independent LGU decoding and separate pinned-PC-tool extraction verify all **1,921 members**. All **1,920 MAX32 paths remain**, with **1,916 files byte-identical**. Kernel, DBoot, MCU, navigation and the contributor's Blue.exe are unchanged. Four existing files change and InstallResume.exe is added.

**Limits:** This covers the application transaction after its new components are installed. Initial legacy extraction, kernel/self replacement, MCU flashing, native settings migration and other maintenance/wait paths are outside this transaction. CE loading, real power/watchdog behavior, storage durability, rollback and broader compatibility are unconfirmed. Intermittent missing covers after track skips remain open. This is not a universal anti-brick guarantee. The separate issue59 MAX30 completion kit remains unchanged.

This is the **complete upgrade.lgu**, not a patch package. Intended for first-generation MediaNav originally running 4.x, including converted units; factory Evolution/later hardware is unsupported. Follow the [installation guide](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade#before-you-start) and keep power/USB connected until the full installation has finished. The first 100% screen can precede a restart and further installation; wait for the normal interface and confirm MAX33. Do not deliberately interrupt power to test recovery in a daily car.

[Full scope, evidence and unconfirmed checks](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/blob/7.0.6.MAX33/releases/7.0.6.MAX33/README.md).

Size: **52,493,724 bytes**. SHA-256:
`a61665ad388720d24171d84d986bbb93dbfa354c8f4ecaaaf1be9f51840a6b67`
