"""Author native indexed volume resources without changing any CE code.

The native MicomManager painter is interpreted separately to capture its actual
crop/layout contract. PC previews replay those calls with an approximate font.
"""
from pathlib import Path
from io import BytesIO
import json
from PIL import Image, ImageDraw, ImageFont
from build_home_theme import encode_like, verify, sha, KEY
from parse_bmp_image import parse_bmp, reference_rgb

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / 'build/max16-navigation-development-01/payload'
OUT = ROOT / 'build/volume-overlay-development-01'
REL = Path('upgrade/Storage Card/System/Img')
BANKS = ('M0', 'M1', 'M1_INV')
ICONS = ('etc_volume_icon.bmp', 'etc_navi_icon.bmp', 'etc_ta_icon.bmp',
         'etc_ring_icon.bmp', 'etc_call_icon.bmp')
NAMES = ('etc_volume_bg.bmp', 'etc_volume_bar.bmp', *ICONS)


def decode(raw):
    meta = parse_bmp(raw)
    return Image.frombytes('RGB', (meta['width'], meta['height']), reference_rgb(raw, meta))


def colors(bank):
    if bank == 'M1_INV':
        return dict(surface=(240, 242, 242), edge=(151, 159, 163),
                    inactive=(195, 201, 203), active=(177, 110, 12), text=(0, 0, 0))
    return dict(surface=(20, 26, 30), edge=(79, 90, 97),
                inactive=(57, 68, 75), active=(249, 190, 44), text=(255, 255, 255))


def paint(original, bank, name):
    c = colors(bank)
    if name in ICONS:
        # Reuse native glyph silhouettes, antialiasing and the red mute slash.
        # Quantization/encoding preserves the exact yellow transparency mask.
        return decode(original)
    if name == 'etc_volume_bar.bmp':
        image = Image.new('RGB', (16, 32), c['surface'])
        draw = ImageDraw.Draw(image)
        for x, state in ((0, 'inactive'), (8, 'active')):
            draw.rounded_rectangle((x + 1, 2, x + 6, 29), radius=2, fill=c[state])
        return image
    image = Image.new('RGB', (582, 63), c['surface'] if bank == 'M1_INV' else (0, 0, 0))
    draw = ImageDraw.Draw(image)
    draw.rounded_rectangle((1, 1, 580, 61), radius=9, fill=c['surface'], outline=c['edge'], width=1)
    # Separate the native numeric readout without competing with the level bars.
    draw.line((503, 15, 503, 46), fill=c['edge'])
    return image


def build():
    assert not (OUT / 'overlay').exists(), 'Keep previous design outputs immutable'
    rows = []
    for bank in BANKS:
        for name in NAMES:
            relative = REL / bank / 'etc' / name
            raw = (BASE / relative).read_bytes()
            # Glyphs already have matching high-contrast light/dark versions;
            # retain them exactly, including context and mute symbols.
            candidate = raw if name in ICONS else encode_like(raw, paint(raw, bank, name))
            contract = verify(raw, candidate)
            target = OUT / 'overlay' / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(candidate)
            rows.append(dict(path=relative.as_posix(), before_sha256=sha(raw),
                after_sha256=sha(candidate), changed=raw != candidate, contract=contract))
    manifest = dict(baseline='7.0.6.MAX16', resource_only=True, assets=rows,
                    changed_assets=sum(r['changed'] for r in rows), native_code_changed=False,
                    glyphs_byte_exact=True, native_font_and_text_colors_unchanged=True,
                    hardware_tested=False)
    assert manifest['changed_assets'] == 6
    (OUT / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    return manifest


def replay(bank, trace, original=False):
    source = BASE if original else OUT / 'overlay'
    assets = {i: decode((source / REL / bank / 'etc' / name).read_bytes())
              for i, name in enumerate(NAMES)}
    # NAMES indices match MicomManager's native 0..6 resource lookup.
    canvas = assets[0].copy()
    for event in trace['events']:
        if event['kind'] in ('icon', 'bar'):
            image = assets[event['resource']]
            sx, sy, w, h = event['source_rect']
            crop = image.crop((sx, sy, sx + w, sy + h))
            assert sx + w <= image.width and sy + h <= image.height
            x, y = event['destination']
            if event['kind'] == 'icon':
                mask = Image.frombytes('L', crop.size,
                    bytes(0 if p == KEY else 255 for p in crop.get_flattened_data()))
                canvas.paste(crop, (x, y), mask)
            else:
                canvas.paste(crop, (x, y))
        elif event['kind'] == 'text':
            # Approximate PC Tahoma only; firmware's actual font is unchanged.
            font = ImageFont.truetype('C:/Windows/Fonts/tahoma.ttf', 32)
            ImageDraw.Draw(canvas).text((event['rect'][0], event['rect'][1]),
                event['text'], fill=tuple(event['color']), font=font)
    return canvas


def previews(traces):
    directory = OUT / 'previews'
    directory.mkdir(exist_ok=True)
    font = ImageFont.truetype('C:/Windows/Fonts/tahoma.ttf', 18)
    samples = [('M1', 'media', 15, False), ('M1_INV', 'media', 15, False),
               ('M1', 'media', 0, False), ('M1_INV', 'media', 31, False),
               ('M1', 'media', 15, True), ('M1_INV', 'navigation', 15, False),
               ('M1', 'call', 15, False), ('M1_INV', 'traffic', 15, False)]
    sheet = Image.new('RGB', (800, 100 + len(samples) * 102), (12, 17, 20))
    draw = ImageDraw.Draw(sheet)
    draw.text((26, 19), 'MAX17 · native volume resources', fill='white', font=font)
    draw.text((26, 48), 'Actual asset pixels and captured native layout · PC font approximation',
              fill=(163, 173, 181), font=font)
    for i, (bank, context, level, muted) in enumerate(samples):
        trace = next(t for t in traces if (t['bank'], t['context'], t['level'], t['muted'])
                     == (bank, context, level, muted))
        y = 90 + i * 102
        draw.text((26, y), f'{"Light" if bank == "M1_INV" else "Dark"} · {context} · {"muted" if muted else level}',
                  fill=(180, 189, 195), font=font)
        canvas = replay(bank, trace)
        canvas.save(directory / f'{bank}-{context}-{level}-{"mute" if muted else "normal"}.png')
        sheet.paste(canvas, (109, y + 29))
    sheet.save(directory / 'volume-overview.png')
    comparison = Image.new('RGB', (800, 340), (12, 17, 20))
    draw = ImageDraw.Draw(comparison)
    for i, bank in enumerate(('M1', 'M1_INV')):
        trace = next(t for t in traces if (t['bank'], t['context'], t['level'], t['muted'])
                     == (bank, 'media', 15, False))
        for j, old in enumerate((True, False)):
            y = 10 + i * 164 + j * 82
            draw.text((26, y), f'{bank} · {"before" if old else "MAX17"}', fill='white', font=font)
            comparison.paste(replay(bank, trace, old), (109, y + 21))
    comparison.save(directory / 'volume-before-after.png')


if __name__ == '__main__':
    print(json.dumps(build(), indent=2))
