# Upgrade stalls: issues 7 and 15

Follow-up: after Max approved pursuing the fix, a [bounded installer copy-safety prototype](updater-copy-safety-development.md) was implemented in complete internal development staging. The two reports still have no confirmed root cause or validated unit recovery. No release was changed.

Investigated 2026-10-09. Read live issue bodies, comments and attached photographs. No issue comments posted, firmware executed, unit changed or new release created. Local snapshots and photographs are in `issue-upgrade-stalls/`.

## What the reports establish

| Report | Starting version | Observed sequence | Photograph |
| --- | --- | --- | --- |
| [#7](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/7) | 4.1.0, Clio IV 2014 MN1 | Update screen remains for about 30 minutes. A second FAT32 USB stick also failed. Reporter found no log on USB. No completed first stage/restart reported. | Older blue interface, Croatian warning, ten apparently unfilled progress boxes. |
| [#15](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/15) | 4.0.2 | Initial progress completes, unit restarts, then remains on update screen. LGU alone, recovery DLL plus LGU and Naviextras recovery did not recover it. | Flat pink/magenta background, white Arabic title/warning, no visible progress boxes. |

#15 is below the current documented minimum 4.0.3. This is a compatibility concern, not proof that the version difference caused the stall. No controlled 4.0.2 versus 4.0.3 installation comparison is available.

The two reports have the same broad symptom but do not establish a shared cause. #7 visibly retains the older interface; #15 explicitly reports a restart and has text matching the 7.0.5 updater's Arabic string resources. A photograph cannot establish the complete installed version or whether background work is still running.

The related [#8 discussion](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/8) describes a similar second-stage screen. One reporter recovered using a USB-root `uiodrv.dll`; other reporters did not, including the #15 reporter. Relevant recovery suggestion: [comment](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/8#issuecomment-3200199657). #15 reporter's unsuccessful attempts: [comment](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/8#issuecomment-4638893821), [later comment](https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/issues/8#issuecomment-4661315279).

## Confirmed drawing weakness, not a confirmed cause of either stall

Original 7.0.5.MD `UpgradeManager.exe`, SHA256 `4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87`, paint function `0x18e88..0x19714`:

- Background and progress graphics are loaded from `\Storage Card\system\Img\{m0,m1,m1_inv}\common\etc_bg.bmp` and `popup\popup_update_gage.bmp`.
- Neither `SHLoadDIBitmap` return is checked. Null handles reach `SelectObject`; the background-copy and progress-copy results are also ignored.
- The warning/title are drawn separately with a font. Thus text drawing can continue when the graphics fail to load or copy.
- The background images actually supplied in the complete package are dark or light themes; none is a flat magenta background.
- Progress boxes are drawn for phase values 3001 through 3006. Phase 3000 does not draw any boxes in this function. Progress-screen display mode and phase are separate state fields.
- This proves that missing graphics or certain phase state can leave a screen with text and no usable progress display. It does **not** prove that missing files explain the photograph's precise colour, or that the real unit is stuck in this function.

`tools/verify_upgrade_progress_screen.py` executes the original MIPS paint bytes with explicit API fixtures: **210 passing cases**, three themes, English/Arabic, seven phases, normal/missing background/missing gauge/both missing/failed BitBlt. All failure cases continue through title/warning and final screen-copy attempts without error feedback. Caller-saved state, stack restoration and callee-saved registers are checked. API fixtures do not render CE pixels, model NAND or reproduce the actual installation. Evidence: `issue-upgrade-stalls/progress-screen-traces.json`.

Original configuration loading in window creation `0x13db8` reads 128 bytes of `\Storage Card2\MgrSys.cfg`. A successful short read is logged as an error but is still interpreted. Its zero-filled language field can select Arabic index 0. The reporter's file and its old-version layout are unavailable, so neither short read nor configuration incompatibility is established for #15. The existing internal English development change forces updater English; it does not repair installation or graphics loading.

## Confirmed installation weaknesses relevant to investigating #15

The conversion has a restart boundary: the updater replaces the OS/updater before the startup path moves the remaining staged application files. Startup `0x12d80` invokes staged installation `0x14eb0` before launching MicomManager. Detailed original-byte and fault-model evidence remains in [updater recovery contracts](updater-recovery-contracts.md).

1. Final-copy helper `0x181b4` ignores `CopyFileW`'s result at `0x1837c`, counts attempted bytes and then deletes the staged source at `0x1839c`.
2. Its caller does not require success before deleting the whole staging directory. Guarding only the per-file delete would therefore leave the later destructive cleanup unchanged.
3. The extraction marker is an ordinary staged member. It can be moved/deleted before all application files have been installed; an interrupted retry can then discard remaining staging.
4. The visible version file can be copied before other required files. An incomplete installation can report the new version and prevent a normal same-version update offer.
5. Configuration backup/format/restore has independent unchecked operations and interruption hazards.

These are actionable defects in the installer retained in MAX03, not evidence that either reporter experienced a specific copy error. Possible resulting states include a new updater/OS with old or missing applications/resources. Internal storage faults, free-space exhaustion, mount problems and a stalled firmware/controller phase remain hypotheses requiring unit evidence.

The first stage on #7 runs the installed 4.1.0 software. Changing the updater carried inside our next LGU cannot be assumed to repair a failure before that replacement runs. The supplied desktop 4.1.0 reference package remains a file-layout reference; its binaries were not reverse engineered for this investigation.

## What the recovery DLL is

The binary linked in #8 was downloaded only for static inspection:

- URL: `https://paste.c-net.org/HartfordBilly`
- Size: 13,312 bytes; SHA256 `6263590645b534720a1a0e5b5adc440605a1800ae9ea03c7f814aaf0beae440f`
- MIPS Windows CE DLL; exports `UIO_Init`, `UIO_IOControl`, read/write/open/close and power callbacks.
- Imported APIs concern physical-memory mapping/allocation, interrupts, events/threads and runtime support. There are no imported file-copy/delete or updater-repair APIs. Debug strings identify a hardware-access driver, including camera interrupt handling.

This is not evidence for a universal conversion-recovery routine. The way a particular stalled unit loads or responds to this USB-root file has not been established. Do not bundle it into the next release on the basis of one success report. Import/export/string evidence is in `issue-upgrade-stalls/recovery-uiodrv-static.json`; the DLL has never been executed here.

## Concrete next repair and diagnostic requirements

Prioritize the installer over cosmetic changes: propagate copy errors to the caller, retain recoverable staging, validate backup before formatting, keep a durable pending-install state, verify installed files and publish the version only at commit. Provide visible phase/error information and a graphics fallback that works while the new image files are unavailable. This must follow the complete [installation contract](update-repair-plan.md); neither a forced reboot nor changing progress values is a repair.

To select a recovery for already affected units, obtain a **read-only** internal file listing/backup if an existing CE/recovery route is accessible. Compare:

- Active `Storage Card/System/UpgradeManager.exe`, `OLD_UpgradeManager.exe`, `MicomManager.exe`, `Version_Info.txt` and graphics/language resources.
- `Storage Card/NK.bin` and any `NA.bin`/`NB.bin` present.
- `Storage Card3/upgrade/` and `filecopy_success.bin`, plus the remaining staged file list.
- `Storage Card2/MgrSys.cfg`, `scan_done_flag.bin` and `Storage Card3/TFAT/` backup presence.
- Actual unit free space and any failed reads/copies, separately from the free space of a PC backup folder.

Do not infer that a unit has CE access, tell it to delete markers, or advise repeated flashing until its actual boot/storage state is known. No USB log is not diagnostic by itself: the inspected updater uses `NKDbgPrintfW`, which does not imply a USB log file.

No LGU was built or published. Future release remains a complete successor to all 1,918 members of 7.0.6.MAX03, carrying existing Bluetooth, audio and navigation changes forward. Neither issue is marked fixed.
