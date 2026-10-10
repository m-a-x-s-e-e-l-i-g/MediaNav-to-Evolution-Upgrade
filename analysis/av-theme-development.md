# Radio, Media and Phone charcoal skin

The approved skin is now included in the complete local [7.0.6.MAX04 build](maxmade-max04-full-update.md), combined with the latest cumulative bugfixes. Its 271 M1 BMPs are unchanged from candidate09. The old skin-only executable is retained as historical preview staging; MAX04 applies the color edits to the newest bugfix executable and moves 30 loader relocations with the scheduled address instructions. The combined constructor checks and full package roundtrip pass. Native unit validation remains open.

9–10 October 2026. The user selected these three applications and explicitly excluded
navigation, with existing positions retained. Baseline: original **7.0.5.MD**.

Latest complete candidate: `build/av-theme-development-09/payload`, based on the
complete `home-theme-development-07` payload. The browser workbench at
`http://127.0.0.1:8766/` has a **Radio / Media / Phone** tab. Default choices cover
FM/AM/DAB, station lists, presets, options, source selection, USB/Bluetooth/iPod,
contacts, the phone keypad/call page and name search. Advanced constructor views
are available with the constructor-controls checkbox.

Candidate 09 closes the DAB border in `fm radio/fmradio_fulldown_bottom_btn.bmp`.
The 576 x 92 native sheet contains four 144 x 65 visible faces and 27 keyed
padding rows below each face. As with AUX, the original painter placed the
lower rim into those transparent rows. The shared source-menu painter now
handles both bottom sheets at their native 65px visible height, retaining all
stored dimensions, exact transparency and original control rectangles.
`tools/check_source_menu_buttons.py` verifies all eight encoded DAB/AUX states:
lower rims stay visible and both original alpha masks remain identical.
Normal and selected DAB were visually checked in the browser; screenshots and
`source-menu-state-proof.json` are in the candidate directory.
All 1,917 members are carried forward; only the radio bottom sheet changes,
and the other 1,916 files are byte-identical to candidate 08, including AppMain.
Reproduce with:

```powershell
py tools/update_radio_source_menu.py --from build/av-theme-development-08 --out build/av-theme-development-NEW
py tools/check_source_menu_buttons.py build/av-theme-development-NEW/payload
```

Candidate 08 closes the AUX border in `media/media_fulldown_bottom_btn.bmp`.
The native 600 x 76 sheet has four 150 x 65 visible faces followed by eleven
keyed padding rows. Previously the 76px panel put its bottom rim inside that
transparent padding. The face is now painted at 65px; all original sheet bytes,
dimensions, transparency and control positions remain under the same contracts.
All four encoded states have a visible bottom rim and retain the eleven keyed
rows; see `media-source-state-proof.json` and `renders/media-source-bottom-states.png`.
The selected AUX appearance was visually checked in the browser.

The narrow source-header fixture in the browser uses the existing compact name
BT to leave space for its native up-arrow. This changes example preview text
only; firmware dynamic labels and text colors are unchanged. All 1,917 payload
members are carried forward; only this BMP changes, with the other 1,916 files
byte-identical to candidate 07. Reproduce with:

```powershell
py tools/update_media_source_menu.py --from build/av-theme-development-07 --out build/av-theme-development-NEW
```

The Bluetooth play/pause correction after candidate 08 changes the **viewer only**.
The original `media_bt_control_play_pause_btn.bmp` is 748 x 83: four complete
187 x 83 frames with a combined play/pause glyph. The bounded constructor has
a variant argument of two, but this does not imply two image banks for this
resource. The earlier viewer incorrectly sliced eight 93.5px frames and
stretched half-icons in both original and themed previews. The viewer now
requires a full native-width bank layout before selecting an alternate bank.
Call and search toggles retain their actual eight-frame layouts. The shared
`tools/av_sprite_layout.mjs` helper is tested against all three original BMPs:
24 selections covering four states and both alternate-checkbox values.
Run `node tools/check_av_sprite_layout.mjs`. Device payloads and candidate 08
hashes are untouched. Browser evidence is saved in
`build/ui-theme-preview-01/renders/bt-preview-fix/`.

Candidate 07 fixes `Phone/phone_keyboard_search_results_list_down_btn.bmp`.
Its native 1280 x 85 sheet contains two banks of four 160 x 85 frames, with
separate list/down and list/up glyphs. The previous painter assumed a single
four-frame bank and painted 320-pixel frames; the native 160-pixel slices then
lost glyphs and cut borders. Both banks are now painted separately with the
Phone blue accent. Calling-only green/red bank colors stay restricted to the
call button. The native blank second-bank disabled frame remains transparent.

All eight native slices were checked against their original glyph positions
and required state colors after indexed BMP encoding; see
`search-results-state-proof.json` and `renders/search-results-states.png`.
Selected down/up variants were visually verified in the browser. Exact BMP
contracts are retained. All 1,917 members are present, and the other 1,916 files
remain byte-identical to candidate 06, including AppMain. Reproduce with:

```powershell
py tools/update_search_results_button.py --from build/av-theme-development-06 --out build/av-theme-development-NEW
```

Candidate 06 carries forward the complete candidate 05 and adds a low-contrast
caller silhouette behind the existing dynamic timer in `Phone/phone_call_time_area.bmp`.
The native 220 x 220 bitmap and [554, 169, 220, 220] control rectangle are retained.
Both the keypad/call and outgoing-call pages share this bitmap. The time remains
native foreground text. Only one payload file changes; the other 1,916 files,
including AppMain and the previous Smartphone/album refinements, are byte-identical.
The original BMP contracts and independent decoding are verified. Reproduce with:

```powershell
py tools/update_call_avatar.py --from build/av-theme-development-05 --out build/av-theme-development-NEW
```

Candidate 05 copies all 1,917 members of candidate 04 and replaces only the M1
278 x 278 no-album placeholder with a smaller slate-gray music note on charcoal.
The bright purple ring is removed. All 1,916 other files, including AppMain,
remain byte-identical to candidate 04. The BMP headers, dimensions, bit depth,
transparency mask, padding and trailer are verified; an independent decoder
agrees with Pillow. USB playback was visually checked in the browser, using
the decoded candidate bitmap at its original [27, 98, 278, 278] rectangle.
Reproduce with:

```powershell
py tools/update_no_album_placeholder.py --from build/av-theme-development-04 --out build/av-theme-development-NEW
```

Candidate 04 copies every member of candidate 03 and replaces only the two M1
Smartphone home button sheets. The icon now uses the original speaking-profile
and sound-wave meaning instead of a headset. All 1,915 other files, including
AppMain and the AV artwork, remain byte-identical to candidate 03. All four
button states and the original BMP contracts are verified. Reproduce with:

```powershell
py tools/update_smartphone_icon.py --from build/av-theme-development-03 --out build/av-theme-development-NEW
```

## Result and scope

- 257 M1 bitmap resources: all 41 radio, 83 media and 130 phone resources,
  plus their three common backgrounds. The existing home skin is retained.
- Normal surfaces use charcoal gradients; pressed/selected controls use black
  surfaces and function-colored borders. Radio is turquoise, Media purple,
  Phone blue. Calling and ending a call retain green/red meanings.
- Native baked glyph positions and the transparency-key mask are retained.
  The album placeholder is redrawn; actual covers and content data are untouched.
- The complete payload has **1,917 files**: 272 differ from the original,
  including 271 BMPs and AppMain; **1,645 remain byte-identical**.
- Navigation application resources, touch/event routing, version fields,
  managers, OS/MCU firmware, DLLs, dictionaries and fonts are unchanged.
  Existing navigation shortcuts inside the AV applications retain their meaning.

Candidate 01 is incomplete: the initial encoder assumed every palette had a
yellow-key entry. Nine opaque assets have none. Candidate 02 corrected that
without changing palette capacity or introducing transparency. Candidate 03
also retains the progress-bar baseline at its original opaque pixel rows.
Prior outputs are preserved; candidate 04 is the current full candidate.

## Geometry and cosmetic text colors

`tools/inspect_av_layouts.py` reconstructs 53 bounded screen initializers with
explicit external-call fixtures. Constructor loops are completed so all six
preset tiles are captured. The media seek bar's expanded touch rectangle is
recorded separately from its sprite rectangle. Phone calling/ending uses two
banks of four button states, at the original 142 Ã— 147 dimensions.

Dark active surfaces require white labels where the native initializers stored
black. `tools/patch_av_text_colors.py` changes 136 initializer words, totalling
278 bytes relative to home-07. Most changes select an already-live white
register. A small number schedule local color stores while that register is
still live; original branch/call opcodes stay at their exact addresses.
The inherited home patch adds its existing two changed bytes.

The proof covers **106 bounded cases**, both UI-type fixtures for every mapped
initializer. Constructor geometry, event IDs, fonts, text, flags and source
identities compare equal except the allowed active text colors. Final registers
and explicitly modelled fixture memory compare equal except live color slots.
No arbitrary read fallback is used: missing reads are restricted to enumerated
zeroed fixtures and the PE loader's unbacked virtual-section tail.

The BMP writer verifies identical headers, sizes, dimensions, bit depth,
compression, palette capacity/reserved bytes, row padding, trailing bytes and
the exact transparency mask. An independent BMP decoder agrees with Pillow.
The full member list and hashes are compared with the previous complete payload;
original extracted files are checked against their inventory hashes.

Evidence: candidate `manifest.json`, `av-text-color-proof.json`,
`analysis/firmware/av-layouts.json`, and browser screenshots in `renders/`.
All 17 named preview screens loaded successfully in the browser with no console
errors. FM, presets, USB playback, contacts, the keypad and name-search keyboard
were visually inspected; selected/pressed examples use the intended black
surfaces and colored borders. `browser-*-full.jpg` captures are the review evidence.
Rebuild with a fresh output directory:

```powershell
py tools/inspect_av_layouts.py
py tools/patch_av_text_colors.py
py tools/build_av_theme.py --out build/av-theme-development-NEW
```

## Practical limits

This is a **development preview**, not an installable update or a working device
emulator. The browser uses decoded candidate BMPs and recorded positions.
Dynamic station/contact/music data and visibility are explicit examples; host
Tahoma approximates native glyph metrics. Initializer fixtures do not prove
native loader behavior, later relayout, timers or hardware services.

Only M1 artwork is redesigned. The cosmetic text-color arrays are shared with
other profiles, whose M0/inverse artwork still needs a contrast review. The
unit's actual file overrides and active profile remain unverified. No LGU is
built, no version is changed, and no device installation/flashing is performed.
