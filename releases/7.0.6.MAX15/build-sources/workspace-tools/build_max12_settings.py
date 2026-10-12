"""Author Settings resources on the complete MAX11 payload; preserve native contracts."""
import argparse
import json
import shutil
import struct
from pathlib import Path
from PIL import Image, ImageDraw
import pefile
from build_home_theme import ROOT, REL, BG, COLORS, KEY, encode_like, sha, verify
from build_av_theme import panel, paint_button, glyph_mask
from inspect_settings_layouts import layouts

BASELINE = ROOT / 'sources/MediaNav-usb-seek-timing/build/maxmade-7.0.6.MAX11-local-01'
OUT = ROOT / 'build/max12-settings-development-03'
APP = Path('upgrade/Storage Card/System/AppMain.exe')
APP_SHA = '49d4a9a2e3d746c4e5e0a9a7d1f92baa51e53d7dd65a7e5f25636d6cf89a3350'
ACCENT = COLORS['setting']


def paint(source, name):
    if name == 'setting_surround_center_btn.bmp':
        # The original equalizer-reset bars are gray/gold and are lost by the
        # white-only AV glyph extractor. Author the same reset-bar meaning.
        width = source.width // 4
        out = Image.new('RGB', source.size, BG)
        for state in range(4):
            frame = panel((width, source.height), ACCENT, state)
            d = ImageDraw.Draw(frame)
            for index, fraction in enumerate((.23, .36, .5, .64, .77)):
                x = round(width * fraction)
                height = 25 if index == 2 else 15
                color = (91, 105, 114) if state == 2 else ACCENT if index == 2 else (238, 243, 247)
                d.rounded_rectangle((x - 1, (source.height - height) // 2,
                                     x + 1, (source.height + height) // 2), radius=1, fill=color)
            out.paste(frame, (state * width, 0))
        return out
    if '_btn' in name or name.endswith('_press.bmp') or 'changekey_' in name:
        out = paint_button(source, name, ACCENT)
        if name in ('setting_tem_c_btn.bmp', 'setting_tem_f_btn.bmp'):
            width = source.width // 4
            mask = glyph_mask(source.crop((0, 0, width, source.height)))
            for state in range(4):
                out.paste((91, 105, 114) if state == 2 else (238, 243, 247),
                          (state * width, 0), mask)
        return out
    if name == 'setting_checkbox.bmp':
        assert source.size == (190, 38)
        out = Image.new('RGB', source.size, BG)
        for state in range(5):
            original = source.crop((state * 38, 0, (state + 1) * 38, 38))
            # This resource contains keyed outlines/ticks, not solid faces.
            # Keep their exact native silhouette; recolor the gold tick white
            # too rather than discarding it through a grayscale glyph mask.
            frame = Image.new('RGB', original.size, KEY)
            for y in range(38):
                for x in range(38):
                    rgb = original.getpixel((x, y))
                    if rgb == KEY: continue
                    tick = state >= 3 and 8 <= x <= 29 and 8 <= y <= 29
                    color = (238, 243, 247) if tick else ACCENT if state in (0, 4) else (90, 105, 115)
                    factor = max(.25, max(rgb) / 255)
                    frame.putpixel((x, y), tuple(round(c * factor) for c in color))
            out.paste(frame, (state * 38, 0))
        return out
    if name.endswith('_bg.bmp') and source.size == (800, 480):
        out = Image.new('RGB', source.size, BG)
        ImageDraw.Draw(out).line((0, 77, 799, 77), fill=(37, 46, 52))
        return out
    if name.startswith('popup_') and name.endswith('_bg.bmp'):
        return panel(source.size, ACCENT, 0)
    if name in ('setting_scrollnumber_bg.bmp', 'etc_authentication_key_inputbox.bmp'):
        return panel(source.size, ACCENT, 0)
    if name in ('setting_sound_bar_bg.bmp', 'setting_surround_bar_bg.bmp'):
        out = Image.new('RGB', source.size, BG)
        d = ImageDraw.Draw(out)
        step = 13 if 'sound' in name else 16
        for x in range(1, source.width, step):
            d.rounded_rectangle((x, 5, min(x + step - 3, source.width - 1), source.height - 6),
                                radius=2, fill=(37, 46, 52))
        return out
    if name in ('setting_sound_bar_f.bmp', 'setting_surround_bar_f.bmp'):
        out = Image.new('RGB', source.size, BG)
        ImageDraw.Draw(out).rounded_rectangle((1, 5, source.width - 2, source.height - 6),
                                             radius=2, fill=ACCENT)
        return out
    if name == 'setting_indi_line.bmp':
        out = Image.new('RGB', source.size, BG)
        ImageDraw.Draw(out).line((0, 77, source.width - 1, 77), fill=(37, 46, 52))
        return out
    if name in ('setting_list_line.bmp', 'setting_parting_line.bmp'):
        out = Image.new('RGB', source.size, BG)
        d = ImageDraw.Draw(out)
        if source.width <= 4:
            d.line((1, 0, 1, source.height - 1), fill=(41, 51, 57))
        else:
            for y in range(0, source.height, 70):
                d.line((0, y, source.width - 1, y), fill=(41, 51, 57))
        return out
    # Keep all native icon banks and semantic red mute/caution pixels. This
    # changes their palette only, retaining every pixel index and silhouette.
    out = Image.new('RGB', source.size, BG)
    pixels = []
    for rgb in source.getdata():
        r, g, b = rgb
        if rgb == KEY:
            pixels.append(KEY)
        elif name == 'setting_direction_image.bmp':
            value = max(rgb) * .24
            pixels.append(tuple(round(c + value) for c in BG))
        elif r > 120 and r > g * 1.65 and r > b * 1.65:
            pixels.append(rgb)
        elif r > 80 and r > b * 1.45 and g > b * 1.2:
            factor = max(rgb) / 255
            color = (58, 69, 77) if name == 'setting_direction_image.bmp' else ACCENT
            pixels.append(tuple(round(v * factor) for v in color))
        elif min(rgb) > 175:
            pixels.append((238, 243, 247))
        elif max(rgb) < 45:
            pixels.append(BG)
        else:
            # Retain instructional diagrams, silhouettes and disabled icons.
            pixels.append(tuple(round(BG[i] + v * .52) for i, v in enumerate(rgb)))
    out.putdata(pixels)
    return out


def patch_labels(raw, ids):
    """Extend MAX07's existing M1 selected-label table; no instruction edits."""
    assert sha(raw) == APP_SHA
    recipe = json.loads((ROOT / 'build/max07-app-development-03/recipe.json').read_bytes())
    pe = pefile.PE(data=raw)
    lookup = recipe['lookup_va']
    before_table = pe.get_data(lookup - pe.OPTIONAL_HEADER.ImageBase, 0x800)
    assert len(before_table) == 0x800 and all(v in (0, 1) for v in before_table)
    out = bytearray(raw)
    changes = []
    for ident in sorted(ids):
        assert ident < 0x800
        at = pe.get_offset_from_rva(lookup - pe.OPTIONAL_HEADER.ImageBase + ident)
        if not out[at]:
            out[at] = 1
            changes.append(dict(image_id=ident, offset=at, before=0, after=1))
    checksum = pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    out[checksum:checksum + 4] = bytes(4)
    out[checksum:checksum + 4] = struct.pack('<I', pefile.PE(data=bytes(out)).generate_checksum())
    candidate = bytes(out)
    allowed = {r['offset'] for r in changes} | set(range(checksum, checksum + 4))
    assert all(a == b or i in allowed for i, (a, b) in enumerate(zip(raw, candidate)))
    assert pefile.PE(data=candidate).verify_checksum()
    return candidate, dict(lookup_va=lookup, helpers=recipe['helpers'], changes=changes,
                           before_sha256=sha(raw), sha256=sha(candidate),
                           instructions_imports_relocations_artwork_unchanged=True,
                           selected_black_to_white_policy='M1 pressed/selected only; existing leaf helpers')


def build(out=OUT):
    assert not out.exists(), 'Use a fresh output directory'
    previous = {r['path']: r['after'] for r in json.loads((BASELINE / 'member-plan.json').read_bytes())['members']}
    assert len(previous) == 1918
    for name, row in previous.items():
        assert sha((BASELINE / 'payload' / name).read_bytes()) == row['sha256']
    shutil.copytree(BASELINE / 'payload', out / 'payload')
    files = sorted((BASELINE / 'payload' / REL / 'setting').glob('*.bmp'))
    files += [BASELINE / 'payload' / REL / 'common/setting_bg.bmp']
    files += [BASELINE / 'payload' / REL / 'etc/etc_authentication_key_inputbox.bmp']
    # Settings reset/confirmation dialogs reuse these global M1 popup resources.
    files += [BASELINE / 'payload' / REL / 'popup' / n for n in
              ('popup_confirm_btn.bmp', 'popup_confirm2_btn.bmp', 'popup_list2_btn.bmp',
               'popup_list_press.bmp', 'popup_list2_bg.bmp', 'popup_list3_bg.bmp',
               'popup_list4_bg.bmp', 'popup_list_bg.bmp')]
    changes = []
    button_names = set()
    for file in files:
        relative = file.relative_to(BASELINE / 'payload')
        before = file.read_bytes()
        source = Image.open(file).convert('RGB')
        after = encode_like(before, paint(source, file.name))
        (out / 'payload' / relative).write_bytes(after)
        changes.append(dict(path=relative.as_posix(), before_sha256=sha(before),
                            sha256=sha(after), verification=verify(before, after)))
        if '_btn' in file.name or file.name.endswith('_press.bmp') or 'changekey_' in file.name:
            button_names.add(relative.relative_to(REL).as_posix().replace('/', '\\').lower())
    catalog = json.loads((ROOT / 'analysis/firmware/appmain-startup-contracts.json').read_bytes())['resources']
    ids = {r['id'] for r in catalog if r['filename'].lower() in button_names}
    before = (BASELINE / 'payload' / APP).read_bytes()
    after, recipe = patch_labels(before, ids)
    (out / 'payload' / APP).write_bytes(after)
    cases = layouts(after)
    # Resource-only styling and the lookup must preserve constructor output.
    assert cases == layouts(before)
    members = []
    changed_names = {r['path'] for r in changes} | {APP.as_posix()}
    for name, row in sorted(previous.items()):
        raw = (out / 'payload' / name).read_bytes()
        if name not in changed_names:
            assert sha(raw) == row['sha256']
        members.append(dict(path=name, bytes=len(raw), sha256=sha(raw)))
    assert {p.relative_to(out / 'payload').as_posix() for p in (out / 'payload').rglob('*') if p.is_file()} == set(previous)
    report = dict(baseline='7.0.6.MAX11', members=members, changed_images=changes,
                  changed_image_count=len(changes), changed_files=len(changed_names),
                  added_members=[], missing_members=[], constructor_cases=len(cases['scenarios']),
                  baseline_unchanged=True, control_geometry_events_labels_fonts_unchanged=True,
                  bluetooth_and_radio_images_identical=True, blue_and_navigation_executables_identical=True,
                  native_execution=False, hardware_tested=False, navigation_skin_included=False,
                  navigation_blocker='Installed Storage Card4/NNG/data.zip or branding.zip absent',
                  limits=cases['limits'])
    for name, value in (('manifest', report), ('label-recipe', recipe), ('settings-layouts', cases)):
        (out / (name + '.json')).write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')
    return dict(output=str(out), changed_images=len(changes), members=len(members),
                selected_label_ids_added=len(recipe['changes']), constructor_cases=len(cases['scenarios']))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, default=OUT)
    print(json.dumps(build(parser.parse_args().out), indent=2))
