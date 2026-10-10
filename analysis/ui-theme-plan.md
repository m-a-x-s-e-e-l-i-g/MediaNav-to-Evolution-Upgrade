# MediaNav charcoal theme — feasibility and preview

The user approved the generated charcoal/colored-icon home design and requested
a system-wide redesign that preserves existing behavior. On 9 October 2026 the
user confirmed that the installed version is **7.0.5.MD**. The initial skin
baseline is therefore `extracted/705md`, verified against
`analysis/705md-inventory.csv`, rather than the cumulative MAX development builds.

## What exists now

Radio, Media and Phone are now implemented as the M1 development candidate
`build/av-theme-development-09`, retaining the home skin and all 1,917 payload
members. Navigation is explicitly excluded. See [the AV report](av-theme-development.md)
for scope, geometry proof, cosmetic text-color changes and native-test limits.
The workbench now includes AV constructor previews with original/themed resources.

The latest black-active home candidate is `build/home-theme-development-07`;
see [its report](home-dark-active.md). Fourteen M1 images and two bytes in the
home text-color stores change; 1,902 other files remain identical. The previous
resource-only candidate, development-06, remains available. The workbench
compares original/themed home reconstructions. Its 1,902-file identity count
describes the home-only candidate; the cumulative AV candidate has 1,645 unchanged
files. Other applications and inverse/day artwork are still pending.

`tools/build_ui_theme_preview.py` builds `build/ui-theme-preview-01` with a
browser image workbench, the approved concept, and a resource catalog. It checks
all 1,917 original package-file hashes before generation and again afterwards.
All 1,857 generated viewer PNGs are compared against the decoded source pixels.
No executable, original image, version field, registry, LGU or device is changed.

Open `http://127.0.0.1:8766/` while the loopback preview server is running. To
restart the server from the workspace:

```powershell
py -m http.server 8766 --bind 127.0.0.1 --directory build/ui-theme-preview-01
```

Regeneration requires a fresh `--out` directory and optionally a `--concept`
image. The builder deliberately refuses to overwrite prior outputs.

The workbench browses actual image assets by profile/screen/name and inspects
full images or horizontal frames. Only the six main home buttons currently have
a mapped four-frame split in the resource browser. Other resource-browser frame
counts are manual inspection aids. The separate AV tab uses bounded constructor
snapshots and recorded frame-bank contracts. It does not execute AppMain,
simulate firmware actions or render its font engine. The concept tab shows
the generated reference, not an installed or executed screen.

| Resource group | Images |
| --- | ---: |
| M0 | 473 |
| M1 | 473 |
| M1_INV | 473 |
| COMMON | 70 |
| RVC | 366 |
| DMENU | 2 |
| Total | 1,857 |

Each main profile has home, radio, media, phone, settings, eco, popup, camera,
common and other resources. File groups are not counts of complete screens.
The installed profile and any unit-only image overrides are not yet confirmed;
version confirmation alone does not establish those bytes.

## Why a resource-only skin is plausible

The existing [startup/resource analysis](appmain-startup-contracts.md) follows
AppMain's external bitmap catalog and profile-relative loads. The
[GUI analysis](appmain-gui-contracts.md) follows the horizontal button painter:
normal 0, pressed 1, disabled 2, selected 3. The six home button sheets are
840 × 137, giving four 210 × 137 frames. Native dialogs use 800 × 480 GDI buffers.
Resource format/loading must follow the native loader; PNG viewer copies are
never proposed as replacements for AppMain BMPs.

Lowest-risk implementation boundary:

- Replace only reviewed image files at their existing names/paths.
- Preserve per-asset dimensions, frame count/order, BMP bit depth, compression,
  palette capacity/transparent-key behavior and decoded memory footprint.
- Keep all executables/DLLs, managers, OS/MCU firmware, fonts, languages, touch
  rectangles, control order, event IDs and screen workflows byte-identical.
- Produce normal, pressed, selected and disabled visuals; preserve icon meaning
  and the contrast expected by the existing runtime text colors.
- Use a narrow changed-file allowlist, a source/output hash manifest and
  non-image byte-identity checks. Never recolor all assets indiscriminately.
- Keep camera imagery, guide geometry and transparency intact; review overlays
  separately. Preserve warning meaning, keyboard legends and inactive states.

The generated reference is visual direction, not a promise of its exact grid or
font. Enlarging touch areas, moving controls or replacing the font/color engine
would need behavior/code changes and is outside this first skin approach.
Some text colors may be hardcoded; a dark selected tile may consequently be
incompatible with an existing dark label. The resource design must adapt to
those colors rather than silently patch the painter.

## Emulation findings

The local PE analysis identifies MIPS/Windows CE binaries; the ROM contains an
AU13xx LCD driver with device-specific display/overlay register operations.
This is not an ordinary Windows desktop application or a Qt-widget skin.

[QEMU's MIPS documentation](https://www.qemu.org/docs/master/system/target-mips.html)
documents other board models, with no MediaNav/AU13xx platform identified.
[QEMU's system-emulation overview](https://www.qemu.org/docs/master/system/introduction.html)
explains that emulating the CPU also requires the machine's devices.
[Microsoft's Device Emulator overview](https://download.microsoft.com/download/1/6/d/16d24ada-5317-4de1-b2b2-890b51813d6e/VS2005_DeviceDev_en-us.pdf)
describes an ARM instruction-set emulator, which does not run these MIPS binaries.
These primary sources were checked on 9 October 2026.

Conclusion: no verified turnkey emulator for this firmware was found. CPU-level
MIPS emulation alone is insufficient evidence of a working boot, graphics,
touchscreen, IPC, radio or Bluetooth environment. A custom board emulator or
AppMain loader with CE/GDI/IPC stubs would be substantial separate work and still
would not validate physical radio/audio/camera behavior.

A desktop compositor grounded in original screen constructors, resource IDs,
coordinates, fonts and state selection is a practical next visual tool. It can
show visual placement and state coverage, but must be labelled a reconstruction
and compared against screenshots from the actual unit. The home reconstruction
is now implemented with explicit fixtures; the other screens remain unmapped.

## Sequence for the redesign

1. Confirm the active unit profile and preserve its actual resource backup.
   Inventory any unit-only resources and compare against 7.0.5.MD.
2. Map home constructors, drawn text, image references and normal/pressed/
   selected/disabled/call-mode variants. Build a native-size original compositor
   and compare it with a unit screenshot before claiming render fidelity.
3. Author the home resources in the approved theme with the original control
   geometry. Review original/new side by side and verify exact file contracts.
4. Apply the same treatment to shared controls, radio, media and source selection,
   phone/pairing/call states, settings/audio, eco, dialogs and keyboards. Each
   screen needs asset/state mapping and visual evidence before completion.
5. Inspect navigation separately: the available package does not include a
   mapped navigation skin archive. Its renderer/resources must be located in an
   actual unit backup. The home Map/Nav launch buttons can be themed independently.
6. Prepare a resource-only candidate with an exact changed-file list, backups,
   restore plan and all other bytes unchanged. Evaluate existing loader, memory,
   font and transparency constraints before unit testing.
7. Validate native screens and touch/hold, selected/disabled, day/night, language,
   call interruption and camera-return behavior on the unit. Roll back assets if
   a mismatch appears. Native loading/rendering/responsiveness remain unverified
   until then; no zero-risk claim or install-ready LGU is justified by previews.

The whole-system skin is not complete. This pass establishes the matching source
baseline, a reviewable resource viewer and a behavior-preserving implementation
boundary. It deliberately does not install or bundle a firmware update.
