"""Build a review-only navigation resource candidate from the verified 4.1.0 ZIP.

No executable, map, license, behavior script or firmware container is replaced.
Use apply_navigation_theme.py on an installed archive backup to verify contracts
before preparing a device package. The full reference ZIP is not an installer.
"""
import argparse
import hashlib
import json
import re
import zipfile
from collections import Counter, defaultdict
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont
from nng_rl_bitmap import decode, encode_like

SOURCE_SHA = '862ff497fcab8ec80a87a0b9e494f6f6bbb5ea1b33dea063d794a97f7cd7a548'
PREFIX = 'ui_lg_renault/800_480/'
BG = (12, 17, 20)
ACCENT = (247, 90, 91)
WHITE = (244, 247, 248)

BUTTON_TYPES = {'btn_main', 'btn_main_sel', 'btn_sec', 'btn_inv', 'btn_ad',
                'btn_sel', 'btn_suggestion', 'btn_keyboard', 'footer', 'wb_wb',
                'e_input', 'e_input_unit', 'e1_list', 'list', 'pagenum',
                'map_main', 'map_inv', 'inf_cockpit'}
STATIC = {'default_skincol.bmp', 'local_panel_bg.bmp', 'local_panel_bg_oneitem.bmp',
          'msgbox_bg_skincol.bmp', 'keyboard_inputfield.bmp', 'key_popup.bmp',
          'scroll_bg.bmp', 'listitem_whereami.bmp'}
ICON_STARTS = ('ico_address_', 'ico_favorites_', 'ico_places_', 'ico_settings_',
               'ico_editroute_', 'ico_deleteroute_', 'ico_itinerary_',
               'ico_showmap_', 'ico_findonmap_', 'ico_overview_',
               'ico_mapsettings_', 'ico_routesettings_', 'ico_routealternatives_',
               'ico_deletefavorite_', 'ico_deleteall_', 'ico_rename_',
               'ico_resetto', 'ico_sortby', 'ico_done_', 'ico_cancel_',
               'ico_coordinates_', 'ico_coordinatessettings_',
               'ico_coordinatesutm_', 'ico_datafields_', 'ico_simulatenavigation_',
               'ico_reorder_', 'ico_showall_', 'ico_showcurrentposition_',
               'ico_showcursorposition_', 'ico_footer_', 'ico_footermap_',
               'ico_scroll', 'ico_browsemap_zoom', 'ico_browsemap_restore',
               'ico_kbd_', 'ico_del_', 'ico_add', 'mapdragrot', 'mapdragtilt')


def sha(data):
    return hashlib.sha256(data).hexdigest()


def strip_references(members):
    refs = defaultdict(set)
    for name, raw in members.items():
        if name.endswith(('.ui', '.css', '.lua')):
            for asset, count in re.findall(rb'([a-zA-Z0-9_-]+)(?:@\d+x\d+)?\.bmp#(\d+)', raw):
                refs[asset.decode() + '.bmp'].add(int(count))
    return refs


def panel(source, phases):
    assert source.height % phases == 0
    height = source.height // phases
    result = Image.new('RGBA', (source.width, source.height), (*BG, 255))
    draw = ImageDraw.Draw(result)
    alpha = source.image().getchannel('A')
    for state in range(phases):
        top = state * height
        active = state == 1
        disabled = state == 2
        fill = (0, 0, 0) if active else (22, 28, 32) if disabled else (28, 35, 40)
        rim = ACCENT if active else (53, 63, 69) if disabled else (111, 121, 127)
        frame_alpha = alpha.crop((0, top, source.width, top + height))
        threshold = max(1, min(220, frame_alpha.getextrema()[1]))
        # Some map chrome intentionally has partial alpha even at its center.
        # Locate that native surface instead of assuming an opaque mask.
        bounds = frame_alpha.point(lambda value: 255 if value >= threshold else 0).getbbox()
        if source.width < 4 or height < 5 or not bounds:
            draw.rectangle((0, top, source.width - 1, top + height - 1), fill=(*fill, 255))
        elif bounds[2]-bounds[0] < 4 or bounds[3]-bounds[1] < 4:
            left, upper, right, lower = bounds
            draw.rectangle((left, top+upper, right-1, top+lower-1), fill=(*rim, 255))
        else:
            left, upper, right, lower = bounds
            radius = min(9, (right-left) // 4, (lower-upper) // 4)
            draw.rounded_rectangle((left+1, top+upper+1, right-2, top+lower-2),
                                   radius=radius, fill=(*fill, 255), outline=(*rim, 255), width=2)
            if not active and not disabled:
                draw.line((left+radius+2, top+upper+4, right-radius-3, top+upper+4),
                          fill=(42, 50, 56, 255))
    result.putalpha(alpha)
    return encode_like(source, result)


def icon(source, phases):
    original = source.image()
    result = original.copy()
    height = source.height // phases
    mixed = []
    for state in range(phases):
        opaque = [max(r, g, b) for r, g, b, a in original.crop(
            (0, state*height, original.width, (state+1)*height)).get_flattened_data() if a >= 220]
        mixed.append(bool(opaque) and sum(v < 40 for v in opaque) > len(opaque)*0.1
                     and sum(v > 180 for v in opaque) > len(opaque)*0.1)
    pixels = []
    for i, (r, g, b, a) in enumerate(original.get_flattened_data()):
        state = (i // source.width) // height
        # Keep semantic silhouette and antialiasing; remove the black pressed
        # glyph which otherwise disappears on the new black active panel.
        target = WHITE if state == 1 else (103, 112, 118) if state == 2 else ACCENT
        if mixed[state]:
            # Preserve opaque cutouts/lines (for example the wrench within
            # the map-settings icon), rather than flattening their meaning.
            shade = 0.18 + 0.82 * max(r, g, b) / 255
        else:
            shade = 1 if state == 1 else 0.72 + 0.28 * max(r, g, b) / 255
        pixels.append((*[round(c * shade) for c in target], a))
    result.putdata(pixels)
    return encode_like(source, result)


def static_surface(source, name):
    def transform(rgb, index):
        brightness = max(rgb)
        if name == 'default_skincol.bmp':
            # Keep the source's separator/texture, remove the red/yellow glow.
            lift = round(brightness / 255 * 5)
            return tuple(c + lift for c in BG)
        lift = round(brightness / 255 * 12)
        return (24 + lift, 31 + lift, 36 + lift)
    return source.recolor(transform)


def label_colors(raw):
    def replace(match):
        name = match[1].decode()
        if name not in BUTTON_TYPES:
            return match[0]
        def attribute(attr):
            key = attr[1]
            color = b'#77838B' if key in (b'color3', b'emptycolor') else b'#F4F7F8'
            return key + b'=' + color
        return re.sub(rb'(color[23]?|valuecolor|emptycolor)=#[0-9a-fA-F]{6}', attribute, match[0])
    result = re.sub(rb'<FONTTYPE\s+(\w+)\b[^>]*>', replace, raw)
    assert re.sub(rb'#[0-9a-fA-F]{6}', b'#COLOR', result) == re.sub(rb'#[0-9a-fA-F]{6}', b'#COLOR', raw)
    return result


def author(members):
    refs = strip_references(members)
    output = {}
    contracts = []
    for path, raw in members.items():
        if not path.startswith(PREFIX):
            continue
        relative = path[len(PREFIX):]
        if '/' in relative and not (relative.startswith('m1/') and relative.count('/') == 1):
            continue
        name = relative.rsplit('/', 1)[-1]
        if name == 'main_scheme.ui':
            changed = label_colors(raw)
            output[path] = changed
            contracts.append(dict(path=path, kind='label-colors', before=sha(raw), after=sha(changed)))
            continue
        if not name.endswith('.bmp') or raw[:2] != b'RL':
            continue
        original = decode(raw)
        counts = refs.get(name, set())
        inferred_icon_strip = False
        if not counts and name.lower().startswith(ICON_STARTS) and original.height % 3 == 0:
            # Menu icons are sometimes named dynamically by the engine rather
            # than literal #3 references. Accept only a visual three-phase
            # contract: matching normal/pressed silhouettes and a dimmed third
            # phase. This remains reference evidence, not device validation.
            image = original.image()
            height = original.height // 3
            alpha_frames = [list(image.crop((0, i*height, image.width, (i+1)*height))
                                 .getchannel('A').get_flattened_data()) for i in range(3)]
            masks = [set(i for i, a in enumerate(frame) if a > 32) for frame in alpha_frames]
            overlap = len(masks[0] & masks[1]) / max(1, len(masks[0] | masks[1]))
            if overlap >= 0.65 and sum(alpha_frames[2]) < sum(alpha_frames[0]) * 0.85:
                counts = {3}
                inferred_icon_strip = True
        kind = None
        if name in STATIC:
            kind = 'surface'
            changed = static_surface(original, name)
        elif len(counts) == 1 and next(iter(counts)) in (2, 3, 4):
            phases = next(iter(counts))
            if original.height % phases:
                raise ValueError(f'Nondivisible native strip: {path}')
            if name.startswith(('button', 'btn_', 'key', 'footer', 'listitem',
                                'betweenlistitem', 'mapsetradio', 'mapsidebutton', 'mapbutton')):
                kind = 'panel'
                changed = panel(original, phases)
            elif name.lower().startswith(ICON_STARTS) or name.lower() in ('ico_home.bmp', 'ico_bullet.bmp'):
                kind = 'action-icon'
                changed = icon(original, phases)
        if kind:
            output[path] = changed
            written = decode(changed)
            assert (original.flags, original.width, original.height, original.chunks) == (
                written.flags, written.width, written.height, written.chunks)
            assert original.image().getchannel('A').tobytes() == written.image().getchannel('A').tobytes()
            contracts.append(dict(path=path, kind=kind, phases=next(iter(counts)) if len(counts) == 1 else 1,
                                  dynamic_icon_strip_inferred=inferred_icon_strip,
                                  flags=original.flags, width=original.width, height=original.height,
                                  before=sha(raw), after=sha(changed)))
    # Coordinate fields explicitly override the shared input font colors.
    coord = 'ui_lg_renault/common/ui/coord.ui'
    output[coord] = members[coord].replace(b'#000000', b'#F4F7F8')
    assert members[coord].count(b'#000000') == 12
    contracts.append(dict(path=coord, kind='coordinate-label-colors', before=sha(members[coord]), after=sha(output[coord])))
    return output, contracts


def write_archive(source, path, edits):
    with zipfile.ZipFile(source) as original, zipfile.ZipFile(path, 'w') as result:
        result.comment = original.comment
        for entry in original.infolist():
            result.writestr(entry, edits.get(entry.filename, original.read(entry.filename)))
    with zipfile.ZipFile(path) as check, zipfile.ZipFile(source) as original:
        assert check.testzip() is None and check.namelist() == original.namelist()
        for name in check.namelist():
            assert check.read(name) == edits.get(name, original.read(name))


def preview(members, out):
    """Reconstruct review states from written resources; PC fonts, sample data.

    Menu grid is from advmenu.ui; footer/dialog dimensions from native CSS.
    Other sample views illustrate assets without claiming device rendering.
    """
    def resource(name, state=0, phases=1):
        path = PREFIX + 'm1/' + name
        if path not in members:
            path = PREFIX + name
        image = decode(members[path]).image()
        height = image.height // phases
        return image.crop((0, state * height, image.width, (state + 1) * height))
    font_path = 'C:/Windows/Fonts/tahoma.ttf'
    font = lambda size: ImageFont.truetype(font_path, size)
    def label(im, xy, text, size=27, fill=WHITE, anchor='mm'):
        ImageDraw.Draw(im).text(xy, text, font=font(size), fill=fill, anchor=anchor)
    def paste(im, name, xy, state=0, phases=3, size=None):
        r = resource(name, state, phases)
        if size:
            r = r.resize(size)
        im.alpha_composite(r, xy)
    def base(title):
        im = resource('default_skincol.bmp')
        label(im, (35, 41), title, 32, anchor='lm')
        label(im, (728, 40), '00:47', 27)
        paste(im, 'footerhome.bmp', (13, 401))
        paste(im, 'ico_home.bmp', (74, 423))
        return im
    screens = []
    for title, entries in [
        ('Destination', [('Address', 'ico_address_big.bmp'), ('Places', 'ico_places_big.bmp'),
                         ('Favourites', 'ico_favorites_big.bmp'), ('Find on map', 'ico_findonmap_big.bmp'),
                         ('Coordinates', 'ico_Coordinates_mid.bmp'), ('Settings', 'ico_settings_big.bmp')]),
        ('Route', [('Edit route', 'ico_EditRoute_big.bmp'), ('Delete route', 'ico_DeleteRoute_big.bmp'),
                   ('Overview', 'ico_Overview_big.bmp'), ('Itinerary', 'ico_Itinerary_mid.bmp'),
                   ('Alternatives', 'ico_RouteAlternatives_mid.bmp'), ('Settings', 'ico_settings_big.bmp')])]:
        im = base(title)
        for i, (text, ico) in enumerate(entries):
            x, y = 90 + (i % 3) * 208, 108 + (i // 3) * 142
            active = i == 0
            paste(im, 'button.bmp', (x, y), int(active))
            image = resource(ico, int(active), 3)
            # Respect native center alignment; never scale the menu glyphs.
            im.alpha_composite(image, (x + (204 - image.width) // 2, y + 6))
            label(im, (x + 102, y + 103), text, 24)
        for i, text in enumerate(('Destination', 'Route', 'Options')):
            paste(im, 'footerthird.bmp', (175 + 201 * i, 401), int(i == (0 if title == 'Destination' else 1)))
            label(im, (275 + 201 * i, 438), text, 24)
        screens.append((title, im))
    im = base('Navigation settings')
    for i, (text, ico) in enumerate([('Route settings', 'ico_RouteSettings_sml.bmp'),
                                   ('Map settings', 'ico_MapSettings_sml.bmp'),
                                   ('Data fields', 'ico_DataFields_sml.bmp'),
                                   ('Coordinates', 'ico_CoordinatesSettings_sml.bmp')]):
        y = 84 + 77 * i
        paste(im, 'listitem.bmp', (13, y), int(i == 1))
        image = resource(ico, int(i == 1), 3)
        im.alpha_composite(image, (23, y + (77 - image.height) // 2))
        label(im, (127, y + 38), text, 28, anchor='lm')
    paste(im, 'button_scrollup.bmp', (675, 84))
    paste(im, 'button_scrolldown.bmp', (675, 238))
    paste(im, 'ico_scrollup.bmp', (710, 137))
    paste(im, 'ico_scrolldown.bmp', (710, 291))
    screens.append(('Navigation settings', im))
    im = base('Route options')
    for i, (title, values, current) in enumerate([('Route method', ['Fast', 'Short', 'Eco'], 0),
                                               ('Motorways', ['Off', 'On'], 1),
                                               ('Toll roads', ['Off', 'On'], 0),
                                               ('Ferries', ['Off', 'On'], 1)]):
        y = 98 + i * 74
        label(im, (42, y + 32), title, 28, anchor='lm')
        for j, value in enumerate(values):
            x = 400 + j * 120
            name = 'mapsetradio_left.bmp' if j == 0 else 'mapsetradio_right.bmp' if j == len(values) - 1 else 'mapsetradio_center.bmp'
            paste(im, name, (x, y), int(j == current), 2)
            label(im, (x + 60, y + 35), value, 26)
    screens.append(('Route options', im))
    im = base('Enter street')
    paste(im, 'keyboard_inputfield.bmp', (28, 89), 0, 1, (644, 69))
    label(im, (50, 123), 'Stationsstraat', 30, anchor='lm')
    for row, text in enumerate(('QWERTYUIOP', 'ASDFGHJKL', 'ZXCVBNM')):
        for column, letter in enumerate(text):
            x, y = 28 + 76 * column, 167 + 76 * row
            paste(im, 'key.bmp', (x, y), int(letter == 'S'))
            label(im, (x + 37, y + 36), letter, 31)
    screens.append(('Keyboard', im))
    im = base('Route')
    paste(im, 'msgbox_bg_skincol.bmp', (0, 0), 0, 1)
    label(im, (400, 211), 'Delete the current route?', 30)
    for i, text in enumerate(('Cancel', 'Delete')):
        paste(im, 'btn_dialog_2.bmp', (136 + i * 266, 326), i)
        label(im, (267 + i * 266, 361), text, 28)
    screens.append(('Dialog', im))
    out.mkdir(parents=True, exist_ok=True)
    overview = Image.new('RGB', (1600, 3 * 518), BG)
    for i, (title, im) in enumerate(screens):
        im.convert('RGB').save(out / (title.lower().replace(' ', '-') + '.png'))
        x, y = (i % 2) * 800, (i // 2) * 518
        ImageDraw.Draw(overview).text((x + 15, y + 7), title, font=font(22), fill=WHITE)
        overview.paste(im.convert('RGB'), (x, y + 38))
    overview.save(out / 'navigation-overview.png')
    controls = [('Menu tile', 'button.bmp', None), ('Keyboard / delete', 'key_backspace.bmp', 'ico_kbd_backspace.bmp'),
                ('Dialog', 'btn_dialog_2.bmp', None), ('Map zoom', 'mapsidebutton_drag.bmp', 'ico_browsemap_zoomin.bmp'),
                ('Map rotation', 'mapsidebutton_top_drag.bmp', 'mapdragrotleft_ico.bmp')]
    sheet = Image.new('RGBA', (920, 130*len(controls)+40), (*BG, 255))
    for i, (caption, bmp, ico) in enumerate(controls):
        y = 40+i*130
        label(sheet, (12, y+55), caption, 21, anchor='lm')
        for state, heading in enumerate(('Normal', 'Selected', 'Disabled')):
            x = 240+220*state
            if i == 0:
                label(sheet, (x+85, 20), heading, 22)
            image = resource(bmp, state, 3)
            if ico:
                glyph = resource(ico, state, 3)
                image.alpha_composite(glyph, ((image.width-glyph.width)//2, (image.height-glyph.height)//2))
            scale = min(190/image.width, 110/image.height, 1)
            image = image.resize((round(image.width*scale), round(image.height*scale)))
            sheet.alpha_composite(image, (x+(190-image.width)//2, y+(110-image.height)//2))
    sheet.convert('RGB').save(out / 'native-control-states.png')


def build(source, out):
    assert sha(source.read_bytes()) == SOURCE_SHA, 'Unidentified reference archive'
    assert not out.exists(), 'Use a fresh staging directory'
    with zipfile.ZipFile(source) as archive:
        assert archive.testzip() is None
        entries = archive.infolist()
        assert len({e.filename.casefold() for e in entries}) == len(entries)
        members = {e.filename: archive.read(e) for e in entries}
    formats = Counter()
    for path, raw in members.items():
        if path.endswith('.bmp') and raw[:2] == b'RL':
            image = decode(raw)
            formats[image.flags] += 1
    edits, contracts = author(members)
    out.mkdir(parents=True)
    for name, raw in edits.items():
        target = out / 'overlay' / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(raw)
    candidate = out / 'reference-nav-data.zip'
    write_archive(source, candidate, edits)
    # Guard all scripts/styles/sprite declarations, and every replaced member.
    # Untouched map/media members may differ in an installed backup.
    dependencies = {name: sha(raw) for name, raw in members.items()
                    if name.startswith('ui_lg_renault/') and name.endswith(('.ui', '.css', '.lua', '.spr'))}
    dependencies.update({c['path']: c['before'] for c in contracts})
    manifest = dict(status='reference-development-only', source_sha256=SOURCE_SHA,
                    supplied_lgu_sha256='435776c3305b344431ad294c25edcb3ca23c70d033d6e18464e9fc1c2bab3f3c',
                    source_engine='9.4.6.619758', current_engine='9.4.6.398870',
                    candidate_sha256=sha(candidate.read_bytes()), members=len(members),
                    changed=len(edits), unchanged=len(members)-len(edits),
                    decoded_rl_formats=dict(formats), changes=contracts, dependencies=dependencies,
                    all_layouts_and_callbacks_exact=True, alpha_and_strip_geometry_exact=True,
                    lua_maps_licenses_executables_exact=True, physical_validation=False,
                    preview='Written native resources, PC Tahoma, sample data; not unit screenshots')
    (out / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n', encoding='utf-8')
    preview({**members, **edits}, out / 'previews')
    (out / 'README.txt').write_text(
        'Navigation resource development candidate, based on the supplied 4.1.0 archive.\n'
        'This directory is not an LGU installer. Do not replace the car data.zip with the reference ZIP.\n'
        'Use tools/apply_navigation_theme.py with an installed data.zip backup to verify native contracts\n'
        'and write a separate, complete archive which retains that backup\'s untouched files.\n'
        'The installed archive, native text behavior and car testing are still required.\n'
        'MAX12 Settings and Bluetooth behavior are untouched. No firmware executable runs.\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in manifest.items() if k not in ('changes', 'dependencies')}, indent=2))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, default=Path('extracted/reference-410/upgrade/Storage Card4/NNG/data.zip'))
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    build(args.source, args.out)
