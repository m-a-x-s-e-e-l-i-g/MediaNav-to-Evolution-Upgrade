# English updater and DBoot text

Inspected and implemented as development candidates on 9 October 2026. No firmware was executed or installed. The published full 7.0.6.MAX03 remains unchanged.

## Implemented development staging

[Complete development payload](../build/ui-english-development-01/README.md) retains all 1,918 members of the previous release; 1,914 files are byte-identical. Only UpgradeManager.exe, dboot.exe, dmenu.exe and cereboot.exe change. No LGU, release ZIP or version bump has been made, as requested.

[patch_ui_english.py](../tools/patch_ui_english.py) checks pinned preimages, preserves file sizes/PE structure and records every changed range. It translates 19 UTF16 text slots, changes the Cancel drawing count to six, and selects English index 2 inside the updater language loader. Main application language resources, settings, Blue/AppMain and the navigation fix remain byte-identical to MAX03.

[verify_ui_english.py](../tools/verify_ui_english.py) interprets the actual modified instructions: 114 language-loader cases, 77 English/LTR progress-warning cases, two Cancel draw cases and two library-load-failure cases. The unchanged original English path produces the same warning. Source changes are restricted to reviewed ranges; headers, imports, resource sections, unwind data and restart actions are preserved.

[build_ui_english_development.py](../tools/build_ui_english_development.py) validates every previous member against the published manifest before staging, checks the written payload, and repeats the candidate checks on read-back. [manifest.json](../build/ui-english-development-01/manifest.json) records all previous/output file hashes and the exact edit recipes.

## Update screen

The packaged `UpgradeManager.exe` loads language DLLs in function `0x14d58`. Its table at `0x37908` maps index 0 to `LangDllAra.dll`, 1 to Dutch, 2 to `LangDllEng.dll` and 3 to French. The loader reads update labels 1205–1211 and label 1434. The current language also controls right-to-left drawing, so switching only the Arabic strings without reviewing that state is insufficient.

Both language DLLs already contain the update text. English resource 1211 reads:

> Update in progress  
> Do not disconnect the USB  
> or turn off the engine

The Arabic counterpart contains the same USB/engine warning. A focused change to the updater's language-selection path can use the existing English resource and left-to-right rendering, without changing the main application's language or replacing the Arabic language DLL globally. The selection occurs during startup and on language-change messages. The current device's actual startup settings were not captured, so the reason it selects Arabic on that unit is not established.

The initial update confirmation may still belong to the previously installed software; the new updater can only control screens rendered after it starts. Check the actual installation sequence before claiming all stages are translated.

## DBoot and reboot helpers

The visible text is spread across three executables, not just dboot.exe:

| File | Source text/location | Intended English |
| --- | --- | --- |
| dboot.exe | `Redemarrer` at file offset `0x7ce4` | Restart |
| dboot.exe | `Redemarrer WinCE` at `0x7ca0` | Restart WinCE |
| dmenu.exe | `Souhaitez-vous redémarrer sur Windows CE ?` at `0x2618` | Restart into Windows CE? |
| dmenu.exe | `Annuler` at `0x28c8` | Cancel |
| dmenu.exe | `Patientez svp, redémarrage en cours` at `0x2904` | Please wait, restarting |
| cereboot.exe | `Etes-vous sûr de vouloir redémarrer ?` at `0x1ef4` | Are you sure you want to restart? |
| cereboot.exe | `Redémarrer` (starts at `0x1f40`) | Restart |

The menu question/waiting label uses wcslen before DrawTextW. The Cancel button currently has an explicit length of 7: replacing Annuler with Cancel also requires checking/updating that draw length. Inspect references and string capacities before editing. French serial diagnostic messages are also present in dmenu/cereboot.

The restart actions, boot gesture, StartWinCE marker and button hit areas should remain unchanged. Desktop shortcut names and guide instructions must agree; check whether old shortcut names persist on the unit.

## Next full release

Use all 1,918 members from 7.0.6.MAX03 as the baseline. Carry forward the exact Blue/AppMain improvements and navigation fix, then add the reviewed translations and matching version information. Compare every previous member path and hash, verify the complete LGU and independently extract it. Do not distribute translations as a separate patch LGU.

The implementation is staged for future integration. Native display, existing shortcut aliases and installation-stage coverage remain to be checked on hardware; no new release has been published.
