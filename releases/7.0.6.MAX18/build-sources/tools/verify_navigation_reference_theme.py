"""Independently check written RL pixels, archive inheritance and apply guards."""
import argparse
import json
import re
import struct
import tempfile
import zipfile
from collections import Counter
from pathlib import Path

from apply_navigation_theme import apply
from build_navigation_reference_theme import ACCENT, BUTTON_TYPES, PREFIX, sha
from nng_rl_bitmap import decode, encode_like, pack565, rgb565


def independent_pixels(raw):
    """Separate streaming interpreter; returns stored RGB565/alpha tuples."""
    assert raw[:2] == b'RL'
    mode, width, height, colors, count = struct.unpack('<5H', raw[2:12])
    assert mode in (0, 1, 2, 3)
    palette = struct.unpack('<' + 'H' * colors, raw[12:12 + 2 * colors])
    cursor = 12 + 2 * colors
    if mode % 2:
        alpha = raw[cursor:cursor + colors]
        assert len(alpha) == colors and max(alpha) <= 32
        cursor += colors
    else:
        alpha = bytes([32] * colors)
    sizes = []
    for _ in range(count):
        size = raw[cursor]
        cursor += 1
        if size == 255:
            size = raw[cursor] * 256 + raw[cursor + 1]
            cursor += 2
        sizes.append(size)
    assert sum(sizes) + cursor == len(raw)
    offset = 0
    output = []
    for size in sizes:
        chunk = memoryview(raw)[cursor:cursor + size]
        cursor += size
        if mode >= 2:
            offset = 0
        i = 0
        while i < len(chunk):
            token = chunk[i]
            i += 1
            if token == 253:
                offset = chunk[i] | chunk[i + 1] << 8
                i += 2
                continue
            if token == 254:
                slot, length = chunk[i] + offset, chunk[i + 1]
                i += 2
            elif token == 255:
                slot, length = 0, chunk[i]
                i += 1
            else:
                slot, length = (token + offset if token else 0), 1
            assert slot < colors and length
            pixel = (palette[slot], 0 if palette[slot] == 0xf81f else alpha[slot] * 255 // 32)
            output.extend([pixel] * length)
        assert i == len(chunk)
    assert len(output) == width * height
    return output


def verify(source, development):
    manifest = json.loads((development / 'manifest.json').read_text(encoding='utf-8'))
    source_raw = source.read_bytes()
    assert sha(source_raw) == manifest['source_sha256']
    candidate = development / 'reference-nav-data.zip'
    assert sha(candidate.read_bytes()) == manifest['candidate_sha256']
    edits = {c['path']: c for c in manifest['changes']}
    assert len(edits) == manifest['changed']
    formats = Counter()
    assertions = Counter()
    with zipfile.ZipFile(source) as old, zipfile.ZipFile(candidate) as new:
        assert old.namelist() == new.namelist() and new.testzip() is None
        for name in old.namelist():
            before, after = old.read(name), new.read(name)
            if name not in edits:
                assert before == after
                assertions['exact_untouched_members'] += 1
                continue
            contract = edits[name]
            assert sha(before) == contract['before'] and sha(after) == contract['after']
            assert before != after
            if name.endswith('.bmp'):
                source_bmp, target_bmp = decode(before), decode(after)
                assert (source_bmp.flags, source_bmp.width, source_bmp.height, source_bmp.chunks) == (
                    target_bmp.flags, target_bmp.width, target_bmp.height, target_bmp.chunks)
                expected = independent_pixels(after)
                decoded = list(target_bmp.image().get_flattened_data())
                assert decoded == [(*rgb565(color), alpha) for color, alpha in expected]
                assert [a for _, a in independent_pixels(before)] == [a for _, a in expected]
                assertions['independent_rewritten_bitmap_checks'] += 1
                if contract['kind'] == 'panel' and contract['phases'] > 1:
                    center = (target_bmp.width // 2, target_bmp.height // contract['phases'] * 3 // 2)
                    pixel = target_bmp.image().getpixel(center)
                    if pixel[3]:
                        assert pixel[:3] == (0, 0, 0), (name, pixel)
                    if contract['width'] > 50 and contract['height'] // contract['phases'] > 50:
                        height = contract['height'] // contract['phases']
                        active = expected[target_bmp.width*height:target_bmp.width*height*2]
                        rim = [(i % target_bmp.width, i // target_bmp.width) for i, (c, a) in enumerate(active)
                               if c == pack565(ACCENT) and a >= 220]
                        source_alpha = source_bmp.image().crop((0, height, source_bmp.width, height*2)).getchannel('A')
                        opaque_bounds = source_alpha.point(lambda a: 255 if a >= 220 else 0).getbbox()
                        if opaque_bounds and opaque_bounds[3]-opaque_bounds[1] > height*0.65:
                            assert rim, name
                            assert max(y for x, y in rim)-min(y for x, y in rim) > height*0.65, name
                            assertions['full_height_active_rims'] += 1
                        else:
                            assertions['sparse_source_masks_retained'] += 1
                    assertions['black_active_faces'] += 1
                if contract['kind'] == 'surface':
                    assert after[:12] == before[:12]
                    assert after[12 + 2 * len(source_bmp.palette):] == before[12 + 2 * len(source_bmp.palette):]
                    assertions['palette_only_surface_checks'] += 1
            else:
                strip_colors = lambda b: re.sub(rb'#[0-9a-fA-F]{6}', b'#COLOR', b)
                assert strip_colors(before) == strip_colors(after)
                assertions['color_only_text_files'] += 1
                if name.endswith('main_scheme.ui'):
                    before_fonts = dict(re.findall(rb'<FONTTYPE\s+(\w+)\b([^>]*)>', before))
                    after_fonts = dict(re.findall(rb'<FONTTYPE\s+(\w+)\b([^>]*)>', after))
                    assert before_fonts.keys() == after_fonts.keys()
                    for font, fields in after_fonts.items():
                        if font.decode() in BUTTON_TYPES:
                            colors = dict(re.findall(rb'(color[23]?|valuecolor|emptycolor)=(#[0-9a-fA-F]{6})', fields))
                            assert all(colors[k] == b'#F4F7F8' for k in (b'color', b'color2', b'valuecolor') if k in colors)
                        else:
                            assert fields == before_fonts[font]
        # Validate all source format families using both parsers.
        for name in old.namelist():
            raw = old.read(name)
            if name.endswith('.bmp') and raw[:2] == b'RL':
                bitmap = decode(raw)
                formats[bitmap.flags] += 1
                assert list(bitmap.image().get_flattened_data()) == [(*rgb565(c), a) for c, a in independent_pixels(raw)]
        assert dict(formats) == {int(k): v for k, v in manifest['decoded_rl_formats'].items()}
        # An original complex format-3 asset exercises high palette offsets in
        # the writer; authored action icons exercise alpha on all three phases.
        bitmap = decode(old.read(PREFIX + 'ico_places_big.bmp'))
        encoded = encode_like(bitmap, bitmap.image())
        original_pixels, rewritten_pixels = independent_pixels(bitmap.raw), independent_pixels(encoded)
        assert all(a == b and (a == 0 or color_a == color_b)
                   for (color_a, a), (color_b, b) in zip(original_pixels, rewritten_pixels))
        assert len(decode(encoded).palette) > 252
        assertions['complex_palette_roundtrip'] += 1
    with tempfile.TemporaryDirectory(prefix='nav-theme-check-') as temp:
        folder = Path(temp)
        positive = folder / 'compatible-with-extra-content.zip'
        positive.write_bytes(source_raw)
        with zipfile.ZipFile(positive, 'a') as z:
            z.writestr('retained-user-content.txt', 'keep this exact')
        result = apply(positive, development, folder / 'complete.zip')
        with zipfile.ZipFile(folder / 'complete.zip') as z:
            assert z.read('retained-user-content.txt') == b'keep this exact'
            assert len(z.namelist()) == manifest['members'] + 1
        assertions['compatible_full_archive_with_extra_content'] += 1
        # Replaced assets, scripts, missing contracts and new overrides must
        # refuse output without changing the installed backup.
        for label, changed, added, missing in [
            ('changed-asset', next(iter(edits)), None, None),
            ('changed-script', 'ui_lg_renault/common/ui/advmenu.lua', None, None),
            ('new-override', None, 'ui_lg_renault/common/ui/custom-override.lua', None),
            ('missing-contract', None, None, 'ui_lg_renault/common/ui/templates.css')]:
            bad = folder / (label + '.zip')
            with zipfile.ZipFile(source) as original, zipfile.ZipFile(bad, 'w') as z:
                for entry in original.infolist():
                    if entry.filename == missing:
                        continue
                    b = original.read(entry.filename)
                    z.writestr(entry, b + b' altered' if entry.filename == changed else b)
                if added:
                    z.writestr(added, b'custom override')
            before_hash = sha(bad.read_bytes())
            target = folder / (label + '-output.zip')
            try:
                apply(bad, development, target)
                raise AssertionError('An incompatible archive was accepted')
            except ValueError as error:
                assert 'contracts differ' in str(error)
            assert not target.exists() and sha(bad.read_bytes()) == before_hash
            assertions['incompatible_archives_refused_without_output'] += 1
    # Truncation and unsupported-format rejection, before any bitmap edit.
    for raw in [b'RL', bitmap.raw[:-1], bitmap.raw[:2] + b'\x04\x00' + bitmap.raw[4:]]:
        try:
            decode(raw)
            raise AssertionError('Malformed bitmap accepted')
        except ValueError:
            assertions['malformed_bitmaps_refused'] += 1
    report = dict(passed=True, source_formats=dict(formats), checks=dict(assertions),
                  native_execution=False, physical_validation=False,
                  source_sha256=manifest['source_sha256'], candidate_sha256=manifest['candidate_sha256'])
    (development / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, default=Path('extracted/reference-410/upgrade/Storage Card4/NNG/data.zip'))
    parser.add_argument('--development', type=Path, required=True)
    args = parser.parse_args()
    verify(args.source, args.development)
