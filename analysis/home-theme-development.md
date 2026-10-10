# Charcoal home skin — first resource implementation

Verified candidate: `build/home-theme-development-06`. The complete original
7.0.5.MD package has 1,917 files. **14 M1 home image resources change; the other
1,903 files are byte-identical**, including every executable, DLL, language,
font, OS/MCU and navigation file. No version field or LGU changes. Nothing was
installed on the unit. Other screens and M0/M1_INV remain original.

The normal home tiles use shaded charcoal surfaces, stronger rounded borders and
larger saturated icons. The moon has no outline; a fine header divider runs
beneath it. Map folds and the navigation arrow use darker facets.
Pressed/selected tiles have dark amber icon areas and fade to lighter amber
behind the label. This fits
the existing native **black pressed/selected text**, confirmed from the original
initialization instructions. A dark selected tile with white labels, as in the
generated concept, would require code changes. No labels are baked into BMPs.

## Layout evidence

`tools/inspect_home_layout.py` interprets the original AppMain instructions at
`0x21c50` and `0x23a0c` using explicit registry/language/GUI/timer fixtures. It
preserves the known AppMain SHA256 and records 24 combinations of profile,
eco/non-eco, layout branch and phone/smartphone. `analysis/firmware/home-layout.json`
contains the source-derived control IDs, event IDs, rectangles, label areas,
font indices and per-state colors. Eight M1 cases feed the preview.

| Main control | x | y | Width | Height | Event |
| --- | ---: | ---: | ---: | ---: | ---: |
| Radio | 76 | 114 | 210 | 137 | 1001 |
| Media | 295 | 114 | 210 | 137 | 1002 |
| Phone | 514 | 114 | 210 | 137 | 1003 |
| Map | 76 | 262 | 210 | 137 | 1004 |
| Nav | 295 | 262 | 210 | 137 | 1005 |
| Settings | 514 | 262 | 210 | 137 | 1006 |

The existing runtime layout branches move controls and labels; those branches
are reconstructed rather than redesigned. Hidden map/nav controls are omitted
from the reduced-layout preview. Original clock digit sprites are used with a
fixed sample time of 09:58. The host Tahoma font approximates the native renderer;
this is not a pixel-perfect execution of Windows CE or a device screenshot.

The call-interruption checkbox is an explicitly labelled visual fixture derived
from the control IDs disabled in `0x23f0c`. It does not reproduce call lifecycle,
scheduler timing or all runtime system-state conditions. Set Time is optional in
the preview; its unit visibility remains governed by the untouched native code.

## Asset verification

`tools/build_home_theme.py` authors vector-style bitmap resources and writes
them with a contract-preserving indexed BMP encoder. Each actual read-back file
is checked for:

- Identical 54-byte header, dimensions, orientation, bit depth and compression.
- Identical palette capacity and reserved palette bytes.
- Identical file size, pixel offset, row padding and trailing bytes.
- Identical per-pixel mask for the original yellow transparency key.
- Agreement between the independent BMP reference decoder and Pillow.
- Exact allowlisted changed-file set, complete original path set, hashes of
  every unchanged output and hashes of every untouched baseline file.

The native transparency color interpretation remains unverified; preserving its
original mask avoids introducing a new dependency on a different key treatment.
The file contracts and decoded pixel-memory footprint remain the same. The skin
changes no control geometry, touch routing, timers, cache logic or event behavior.

The first output directory is marked incomplete after a caught palette-writer
failure. The second passed byte checks; the third refines the handset silhouette
and carries the corrected smartphone label into the preview. Prior outputs are
preserved. The fourth matches the approved reference more closely. The fifth/sixth refine
the surface easing, top-to-bottom border highlights and rounded radio strokes.
The final icons use solid accents and explicit facets to avoid gradient banding
in the shared indexed palette; transparent icon cutouts show the actual tile
surface. No controls or native text colors changed. The manifest in development-06
is the current candidate record.

## Review and remaining work

The live workbench at `http://127.0.0.1:8766/` now opens **Home preview** and can
compare original/themed resources, four states, reduced/eco/smartphone layouts,
call interruption, Set Time and touch rectangles. Browser interactions and
static 800×480 renders are checked before delivering this phase.

Browser verification covered all eight M1 layout choices, all four Settings
states, call interruption, Set Time and touch overlays. The normal themed screen
was inspected visually after those checks. Revision 06 was inspected in all four states in the browser. Static render
inspection also checked the selected surface. The entire native label rectangle
retains at least 4.5:1 contrast against black in pressed and selected Settings
states; the other tiles share the same surface paint. No native
firmware action was run.

Reproduce into a **fresh** output directory:

```powershell
py tools/inspect_home_layout.py
py tools/build_home_theme.py --out build/home-theme-development-07
```

The builder refuses to overwrite any earlier candidate and updates the existing
workbench's home-resource copies to the newly verified candidate.

The full-system theme remains pending. Radio, media/source menus, phone screens,
settings, dialogs/keyboards and day/inverse resources need the same native
resource/text/state mapping before replacement. The available package does not
include a mapped navigation skin archive; navigation needs an actual unit backup.
Camera pictures and guide geometry must be preserved.

Native unit checks remain necessary for font metrics, transparency, image loading,
theme/cache transitions, button states and responsiveness. No install-ready or
zero-risk claim follows from the desktop preview or the offline byte checks.
