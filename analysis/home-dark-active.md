# Black active home tiles — development candidate 07

The user requested black backgrounds when clicking, with outlines in the icon
color. `build/home-theme-development-07` implements black pressed/selected M1
tiles, unchanged function-colored icons, matching outlines and white labels.
Normal and disabled tile treatment remains charcoal. The previous verified
resource-only candidate, development-06, is retained unchanged.

## Exact scope

The complete 1,917-file 7.0.5.MD payload is retained. Fourteen M1 image resources
change with the same verified BMP dimensions, frame order, file size, headers,
palette capacity, padding, trailing bytes and transparent-key masks. All other
image resources remain original.

Unlike the earlier resource-only version, this candidate also changes exactly
**two bytes in AppMain.exe**, to set white pressed/selected home labels. The
original black native labels would be unreadable on black. There is no LGU,
version change or device installation. The other **1,902 files are byte-identical**.

| Address | Before | After | Effect |
| --- | --- | --- | --- |
| 0x21d10 | 0xafa0004c | 0xafa8004c | Store white for pressed home labels |
| 0x21d18 | 0xafa00054 | 0xafa80054 | Store white for selected home labels |

These are existing MIPS stores to the existing local home color array. Only the
source-register field changes, from zero to $t0. The surrounding original bytes
are pinned and verified; $t0 contains 0x00ffffff at both stores. No register value,
branch, call, instruction count, PE layout, event ID or control rectangle changes.

`tools/patch_home_text_colors.py` verifies the original AppMain SHA256, the exact
instruction context, exact two-byte diff and unchanged file length. It then
interprets original and patched home setup/layout instructions across all 24
profile/eco/layout/phone combinations. Their control records match exactly except
the intended two text colors. Normal and disabled colors, labels, fonts, geometry
and events remain identical. The full proof is stored in the candidate directory.

## Preview and limitations

The original preview uses original text colors; the themed preview uses colors
recovered from the patched instructions. It is not a cosmetic preview-only color
override. Main active states are inspected in the browser with black surfaces and
function-colored borders. No firmware actions execute in the browser.

The home color array is shared across M0, M1 and inverse profiles. White active
text therefore also affects their home labels, while this candidate only changes
M1 artwork. M0/inverse active-state appearance must be reviewed and themed before
installation. Set Time and moon controls use separate color arrays and are
unchanged by the two instruction changes.

This remains a development candidate. Bounded instruction interpretation and BMP
checks do not establish Windows CE loading, native text metrics, cache behavior,
signed-image acceptance, or device responsiveness. Hardware validation is pending.

```powershell
py tools/build_home_theme.py --out build/home-theme-development-08 --white-active-labels
```

Omit the flag to reproduce the earlier lighter amber selection with unchanged
executables. Always use a fresh output directory.
