# UI development

## Scope

- Home, Radio, Media and Phone use the approved dark theme.
- Active controls have black backgrounds and icon-colored outlines.
- Native control positions, labels, touch events and image contracts stay intact.
- Navigation redesign is excluded.

## Source and assets

- [Home resource authoring](../tools/build_home_theme.py), [AV resource authoring](../tools/build_av_theme.py).
- [Home layout fixtures](../tools/inspect_home_layout.py), [AV layout fixtures](../tools/inspect_av_layouts.py).
- [Color and loader integration](../tools/integrate_approved_skin.py).
- [Approved native M1 artwork](../src/ui/M1), [complete MAX04 edit plan](../src/patches/max04.json).
- [Before/after gallery](../releases/7.0.6.MAX04/README.md#before-and-after).

## Preview

With original 7.0.5.MD files at the paths in the [module inventory](../analysis/corpus/modules.json):

```powershell
python tools/build_ui_theme_preview.py --out build/ui-preview
python -m http.server 8766 --directory build/ui-preview --bind 127.0.0.1
```

- The asset browser reads actual firmware images. The published Home/AV preview code includes the scenario renderers used during design.
- Theme-generation scripts require their recorded prior stages; see the [development guide](development.md).
- Browser layouts use sample content and approximate fonts. They are a visual workbench, not a Windows CE emulator.
- Check native BMP dimensions, padding, frame states, color keys, label colors and loader relocations before packaging.
- M1 artwork is approved; other color profiles still need contrast/device checks.
