"""Check actual MAX12 selected-label painter bytes and produce native asset previews."""
import json
from pathlib import Path
import pefile
from PIL import Image, ImageDraw, ImageFont
from build_max12_settings import OUT, BASELINE, ROOT, APP, REL, BG, KEY, sha
from build_home_theme import transparent
from verify_selected_label_contrast import setup, colors, BUTTON, RES, call
from verify_usb_input_safety import relocated

FONT = 'C:/Windows/Fonts/tahoma.ttf'


def verify_labels():
    raw = (OUT / 'payload' / APP).read_bytes()
    recipe = json.loads((OUT / 'label-recipe.json').read_bytes())
    assert sha(raw) == recipe['sha256']
    pe = pefile.PE(data=raw)
    table = pe.get_data(recipe['lookup_va'] - pe.OPTIONAL_HEADER.ImageBase, 0x800)
    catalog = json.loads((ROOT / 'analysis/firmware/appmain-startup-contracts.json').read_bytes())['resources']
    vm, events = setup(pe, recipe)
    count = 0
    for ident in range(len(catalog)):
        vm.write(BUTTON + 0x28, ident)
        for profile in range(4):
            vm.write(RES + 0x6d8, profile)
            for state in range(4):
                for painter in (0x13ecec, 0x13f258):
                    colors(vm, [0] * 4)
                    events.clear()
                    call(vm, painter, [BUTTON, state])
                    expected = 0xffffff if profile == 1 and state in (1, 3) and table[ident] else 0
                    assert all(e[2] == expected for e in events if e[0] == 'text')
                    assert all(vm.read(BUTTON + a) == 0 for a in (0x54c, 0x550, 0x554, 0x558))
                    count += 1
    semantics = 0
    for change in recipe['changes']:
        vm.write(BUTTON + 0x28, change['image_id'])
        for value in (0xffffff, 0x53595c, 0x46494c, 0xb6f8, 0x75787a):
            for state in range(4):
                colors(vm, [value] * 4)
                events.clear()
                call(vm, 0x13f258, [BUTTON, state])
                assert all(e[2] == value for e in events if e[0] == 'text')
                semantics += 1
    old_raw = (BASELINE / 'payload' / APP).read_bytes()
    allowed = {c['offset'] for c in recipe['changes']}
    checksum = pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    allowed.update(range(checksum, checksum + 4))
    rebases = 0
    for delta in (0x1000, 0x8000, 0x123000):
        old = relocated(old_raw, delta)
        moved = relocated(raw, delta)
        assert len(old) == len(moved)
        assert all(a == b or i in allowed for i, (a, b) in enumerate(zip(old, moved)))
        vm, events = setup(pefile.PE(data=moved), recipe, delta)
        vm.write(BUTTON + 0x28, recipe['changes'][0]['image_id'])
        vm.write(RES + 0x6d8, 1)
        colors(vm, [0] * 4)
        call(vm, 0x13f258 + delta, [BUTTON, 3])
        assert all(e[2] == 0xffffff for e in events if e[0] == 'text')
        rebases += 1
    return dict(catalog_profile_state_painter_cases=count, semantic_cases=semantics,
                whole_image_rebases_and_painter_cases=rebases,
                retained_BT_radio_memberships=True, native_execution=False, hardware_tested=False)


def sprite(image, root, r, state):
    name = r.get('filename')
    if not name:
        return
    path = root / REL / name.replace('\\', '/')
    src = Image.open(path).convert('RGB')
    x, y, w, h = r['rect']
    button = '_btn' in name or name.endswith('_press.bmp') or 'changekey_' in name
    # Generic image helpers sometimes put an event ID in the tracer's optional
    # stack slot. The sheet's actual native control width determines slicing.
    count = 4 if button else src.width // w if src.width % w == 0 and src.width // w <= 8 else 1
    assert count > 0 and src.width % count == 0, (name, src.size, count)
    fw = src.width // count
    chosen = state if button else 0
    crop = transparent(src.crop((fw * chosen, 0, fw * chosen + min(w, fw), min(h, src.height))))
    image.paste(crop, (x, y), crop.getchannel('A'))


def render(case, root, after=False):
    image = Image.open(root / REL / 'common/setting_bg.bmp').convert('RGB')
    # Constructor snapshots include controls for alternate pages; these
    # fixture choices show the primary page rather than overlaying both.
    chosen = {'0xb69a0': {1003, 1008}, '0xbabc8': {1003, 1005, 1013, 1010},
              '0xc8cd8': {1003, 1004, 1006}, '0xcbe48': {1002}}
    layout = case['entry']
    seen = set()
    for r in case['controls']:
        rect = r['rect']
        x, y, w, h = rect
        if w <= 0 or h <= 0 or x >= 800 or y >= 480:
            continue
        if layout == '0xbabc8' and r['object_offset'] in ('0xec8', '0x6d3c', '0x67cc'):
            continue
        if layout == '0xb87e0' and r['object_offset'] in ('0x3e94', '0x38d0', '0x3e40'):
            continue
        if layout == '0xc6988' and r['object_offset'] == '0x1618':
            continue
        if layout == '0xbfab4' and tuple(rect) in seen:
            continue
        seen.add(tuple(rect))
        state = 3 if r.get('event') in chosen.get(layout, set()) else 0
        name = r.get('filename') or ''
        if name.endswith('softkey_4_1_btn.bmp') and layout == '0xb69a0': state = 3
        if name.endswith('softkey_4_2_btn.bmp') and layout == '0xbabc8': state = 3
        if name.endswith('softkey_4_3_btn.bmp') and layout == '0xb87e0': state = 3
        if name.endswith('softkey_4_4_btn.bmp') and layout == '0xc6988': state = 3
        sprite(image, root, r, state)
        text = r.get('text', '')
        if not text or text == ' ':
            continue
        if '\r\n' in text:
            text = text.replace('\r\n', '\n')
        area = r.get('label_rect', rect)
        tx, ty, tw, th = area
        values = r.get('colors') or [0xffffff] * 4
        color = values[state] if state < len(values) else values[0]
        if after and color == 0 and state in (1, 3) and name:
            color = 0xffffff
        rgb = (color & 255, (color >> 8) & 255, (color >> 16) & 255)
        size = 26 if y < 80 else 24
        font = ImageFont.truetype(FONT, size)
        layer = image.crop((tx, ty, tx + tw, ty + th))
        d = ImageDraw.Draw(layer)
        centered = bool(name and ('_btn' in name or 'changekey_' in name))
        d.multiline_text((tw / 2 if centered else 0, th / 2), text, font=font, fill=rgb,
                         anchor='mm' if centered else 'lm', spacing=2, align='center' if centered else 'left')
        image.paste(layer, (tx, ty))
    return image


def main():
    verification = verify_labels()
    cases = json.loads((OUT / 'settings-layouts.json').read_bytes())['scenarios']
    preview = OUT / 'previews'
    preview.mkdir(exist_ok=True)
    selected = ['0xb69a0', '0xbabc8', '0xb87e0', '0xc6988', '0xc8cd8', '0xc49ec']
    sheet = Image.new('RGB', (1640, len(selected) * 530 + 90), BG)
    d = ImageDraw.Draw(sheet)
    font = ImageFont.truetype(FONT, 23)
    for i, entry in enumerate(selected):
        case = next(c for c in cases if c['entry'] == entry)
        y = 45 + i * 530
        d.text((10, y - 33), case['name'] + ' - MAX11', fill='white', font=font)
        d.text((830, y - 33), case['name'] + ' - MAX12', fill='white', font=font)
        for x, root, after, suffix in ((10, BASELINE / 'payload', False, 'before'),
                                      (830, OUT / 'payload', True, 'after')):
            screen = render(case, root, after)
            screen.save(preview / f'{entry}-{suffix}.png')
            sheet.paste(screen, (x, y))
    d.text((10, sheet.height - 35), 'Native resources/constructor positions; sample state and PC font. Not car screenshots.',
           fill=(153, 166, 175), font=ImageFont.truetype(FONT, 18))
    sheet.save(preview / 'comparison.png')
    # Full native state sheets for every changed resource, including keyboard,
    # checkboxes, mute icons, diagrams and popup confirmation controls.
    changes = json.loads((OUT / 'manifest.json').read_bytes())['changed_images']
    for row in changes:
        target = preview / 'assets' / Path(row['path']).relative_to(REL).with_suffix('.png')
        target.parent.mkdir(parents=True, exist_ok=True)
        transparent(Image.open(OUT / 'payload' / row['path']).convert('RGB')).save(target)
    # Both checked checkbox banks retain their actual non-key tick pixels.
    checked = Image.open(OUT / 'payload' / REL / 'setting/setting_checkbox.bmp').convert('RGB')
    for bank in (3, 4):
        assert sum(min(checked.getpixel((bank * 38 + x, y))) > 160
                   for x in range(9, 29) for y in range(9, 29)) >= 40
    grid = Image.new('RGB', (1640, 1640), BG)
    gd = ImageDraw.Draw(grid)
    for index, entry in enumerate(selected):
        case = next(c for c in cases if c['entry'] == entry)
        x, y = 10 + index % 2 * 820, 45 + index // 2 * 530
        gd.text((x, y - 32), case['name'], font=font, fill='white')
        grid.paste(Image.open(preview / f'{entry}-after.png'), (x, y))
    gd.text((10, 1610), 'Native resources; sample state and PC font. Car testing pending.',
            fill=(153, 166, 175), font=ImageFont.truetype(FONT, 18))
    grid.save(preview / 'settings-overview.png')
    verification.update(app_sha256=sha((OUT / 'payload' / APP).read_bytes()),
                        asset_contracts_verified=len(changes), screenshots_are_reconstructions=True)
    (OUT / 'verification.json').write_text(json.dumps(verification, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(verification, indent=2))


if __name__ == '__main__': main()
