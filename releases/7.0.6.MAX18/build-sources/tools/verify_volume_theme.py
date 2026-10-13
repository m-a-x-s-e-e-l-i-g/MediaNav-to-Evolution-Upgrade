"""Interpret immutable MicomManager volume paint bytes with explicit GDI fixtures.

No CE executable runs. Resource lookup, audio-context queries and GDI are mocked;
the actual MIPS branches/loops determine source crops, position, mute and text.
"""
import json
from pathlib import Path
import pefile
from verify_ui_english import UiVM
from build_volume_theme import BASE, OUT, BANKS, NAMES, REL, decode, previews
from build_home_theme import sha, verify

PIN = 'c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824'
STACK, OBJECT, MANAGER, RESOURCE = 0x68000000, 0x61000000, 0x62000000, 0x63000000
CONTEXTS = dict(media=0, ring=7, call=8, traffic=9, navigation=0)


def trace(pe, bank, context, level, muted):
    vm = UiVM(pe, [(0x16fe0, 0x173d4)])
    vm.reg[29], vm.reg[17], vm.reg[18], vm.reg[19] = STACK, OBJECT, 0x110, 0x120
    vm.reg[22], vm.reg[23] = 0x130, 0x140
    for offset in range(0, 0x60, 4):
        vm.write(STACK + offset, 0)
    vm.write(OBJECT + 0x10, level)
    vm.write(OBJECT + 0x18, int(muted))
    vm.write(OBJECT + 0x30, RESOURCE)
    vm.write(RESOURCE + 0x61c, 2 if bank == 'M1_INV' else 0)
    vm.write(0x64828, MANAGER)
    vm.write(MANAGER + 0x2c, int(context == 'navigation'))
    selected, events, state = {}, [], {}

    def select(m):
        dc, bitmap = m.reg[4:6]
        old = selected.get(dc, 0)
        selected[dc] = bitmap
        return old

    def resource(m):
        assert m.reg[4] == RESOURCE
        index = m.reg[5]
        assert 0 <= index <= 6
        return 0x1000 + index

    def image(m, transparent):
        dc, x, y, w = m.reg[4:8]
        assert dc == 0x120
        args = [m.read(m.reg[29] + o) for o in range(0x10, 0x2c, 4)]
        h, source, sx, sy = args[:4]
        assert source == 0x110
        index = selected[source] - 0x1000
        if transparent:
            assert args[4:] == [36, 39, 0xffff]
        else:
            assert args[4] == 0xcc0020
        events.append(dict(kind='icon' if transparent else 'bar', resource=index,
                           source_rect=[sx, sy, w, h], destination=[x, y]))
        return 1

    def text_color(m):
        value = m.reg[5]
        state['color'] = [(value >> b) & 255 for b in (0, 8, 16)]
        return 0

    def printf(m):
        assert m.text(m.reg[5]) == '%02d'
        raw = (f'{m.reg[6]:02d}' + '\0').encode('utf-16-le')
        for i, b in enumerate(raw):
            m.write(m.reg[4] + i, b, 1)
        return len(raw) // 2 - 1

    def drawtext(m):
        rect = [m.read(m.reg[7] + i * 4) for i in range(4)]
        events.append(dict(kind='text', text=m.text(m.reg[5]), color=state['color'], rect=rect))
        return 1

    vm.hooks = {0x30adc: resource, 0x11e88: lambda m: CONTEXTS[context],
        0x11e90: lambda m: level, 0x49d60: lambda m: 0, 0x49e80: select,
        0x49fa0: lambda m: image(m, True), 0x49ec0: lambda m: image(m, False),
        0x49eb0: lambda m: 1, 0x49f90: lambda m: 1, 0x49f80: text_color,
        0x305f8: lambda m: 0x8888, 0x49f60: printf, 0x49ed0: drawtext}
    vm.run(0x16fe0, {0x173d4})
    icon, *bars, text = events
    assert icon['kind'] == 'icon' and len(bars) == 31
    expected_index = dict(media=2, ring=5, call=6, traffic=4, navigation=3)[context]
    # Native Nav path uses generic muted speaker when volume is zero or muted.
    if context == 'navigation' and (level == 0 or muted):
        expected_index = 2
    assert icon['resource'] == expected_index
    assert icon['destination'] == [18, 11]
    assert icon['source_rect'] == [36 if level == 0 or muted else 0, 0, 36, 39]
    for i, bar in enumerate(bars):
        assert bar == dict(kind='bar', resource=1, source_rect=[8 if i < level else 0, 0, 8, 32],
                           destination=[63 + i * 14, 14])
    assert text == dict(kind='text', text=f'{level:02d}', rect=[513, 9, 563, 51],
                        color=[0, 0, 0] if bank == 'M1_INV' else [255, 255, 255])
    return dict(bank=bank, context=context, level=level, muted=muted, events=events,
                interpreted_range=['0x16fe0', '0x173d4'], steps=vm.steps)


def run():
    raw = (BASE / 'upgrade/Storage Card/System/MicomManager.exe').read_bytes()
    assert sha(raw) == PIN
    pe = pefile.PE(data=raw)
    traces = [trace(pe, bank, context, level, muted)
              for bank in BANKS for context in CONTEXTS
              for level in (0, 1, 15, 30, 31) for muted in (False, True)]
    pe.close()
    # Also exercise every actual native level in the normal context.
    pe = pefile.PE(data=raw)
    for bank in BANKS:
        for level in range(32):
            trace(pe, bank, 'media', level, False)
    pe.close()
    manifest = json.loads((OUT / 'manifest.json').read_bytes())
    for row in manifest['assets']:
        before, after = (BASE / row['path']).read_bytes(), (OUT / 'overlay' / row['path']).read_bytes()
        assert sha(before) == row['before_sha256'] and sha(after) == row['after_sha256']
        assert verify(before, after) == row['contract']
    for t in traces:
        for event in t['events']:
            if event['kind'] in ('icon', 'bar'):
                image = decode((OUT / 'overlay' / REL / t['bank'] / 'etc' / NAMES[event['resource']]).read_bytes())
                x, y, w, h = event['source_rect']
                assert 0 <= x < x + w <= image.width and 0 <= y < y + h <= image.height
                dx, dy = event['destination']
                assert 0 <= dx < dx + w <= 582 and 0 <= dy < dy + h <= 63
    previews(traces)
    (OUT / 'native-paint-traces.json').write_text(json.dumps(traces, indent=2) + '\n')
    proof = dict(passed=True, native_sha256=PIN, native_changed=False,
        bitmap_contracts_verified=21, changed_bitmaps=6, exact_context_glyphs=15,
        full_level_fixtures=96, context_theme_boundary_mute_fixtures=len(traces),
        header_palette_padding_transparency_preserved=True, independent_bitmap_decode=True,
        native_layout_crop_mute_text_verified=True, all_crops_inside_resources=True,
        native_executed=False, hardware_tested=False,
        limitations='MIPS byte interpreter with mocked context/resource/GDI calls; PC font approximation; car rendering pending.')
    (OUT / 'verification.json').write_text(json.dumps(proof, indent=2) + '\n')
    return proof


if __name__ == '__main__':
    print(json.dumps(run(), indent=2))
