"""Execute the existing artwork owner with explicit failing COM/GDI fixtures.

Read-only diagnosis: no firmware patch, native decoding, or device timing.
"""
import argparse
import hashlib
import json
from pathlib import Path

from inspect_bt_pairing import put, data
from verify_artwork_playlist import (vm, pixel_fixture, OBJ, DIALOG, STACK,
                                     FACTORY, IMAGE, VTABLE, POOL, BITS)
from verify_usb_input_safety import relocated
from verify_usb_reliability import invoke

INPUTS = {
    'cac3d40f5d54de681b1aad8c99fe79df5b430d3ee3d668616b63970f02ca1a2c': 'MAX04',
    '390c9858832add05a16b3a0760383080f1ce9bfc34359c8538ddb9f7d00557c8': 'PR33',
}
E_FAIL = 0x80004005
CASES = (
    ('healthy', {}),
    ('factory failure', {'factory_hr': E_FAIL}),
    ('image creation failure', {'image_hr': E_FAIL}),
    ('image info failure', {'info_hr': E_FAIL}),
    ('compatible DC failure', {'dc': 0}),
    ('DIB allocation failure', {'bitmap': 0}),
    ('bitmap selection failure', {'selection': 0}),
    ('draw failure', {'draw_hr': E_FAIL}),
    ('draw negative boundary', {'draw_hr': 0x80000000}),
    ('draw positive status', {'draw_hr': 1}),
)


def trace(raw, options, previous=0, delta=0):
    m = vm(raw, delta)
    # Execute both actual bitmap publication/deletion wrappers. Mutex operations
    # are declared single-threaded fixtures; shared readers are not simulated.
    m.ranges.extend((a+delta, b+delta) for a, b in
                    ((0x4a500, 0x4a5c8), (0x4a800, 0x4a85c)))
    put(m, STACK-0xf18, bytes(0xf18))
    m.write(OBJ+0xc38, 7)
    m.write(OBJ+0xe48, POOL)
    m.write(OBJ+0x2926, previous)
    for at, count in ((FACTORY, 16), (IMAGE, 16), (VTABLE, 0x80)):
        put(m, at, bytes(count))
    m.write(FACTORY, VTABLE)
    m.write(IMAGE, VTABLE+0x40)
    m.write(DIALOG+0x7c, 5)
    m.write(DIALOG+0x80, 3)
    events = []
    bitmap = options.get('bitmap', 0x8888)
    dc = options.get('dc', 0x6666)
    initial, expected, _ = pixel_fixture(5, 3)

    def log(name, *args):
        events.append([name, *args])

    def create(v):
        hr = options.get('factory_hr', 0)
        v.write(v.read(v.reg[29]+0x10), FACTORY if hr < 0x80000000 else 0)
        log('factory', hr)
        return hr

    m.write(0x2f1e0+delta, 0xf1000010)
    m.hooks[0xf1000010] = create

    def image(v):
        assert v.reg[4:8] == [FACTORY, POOL, 7, 0]
        hr = options.get('image_hr', 0)
        v.write(v.read(v.reg[29]+0x10), IMAGE if hr < 0x80000000 else 0)
        log('image', hr)
        return hr

    def release(v):
        assert v.reg[4] in (IMAGE, FACTORY)
        log('release', v.reg[4])
        return 0

    def info(v):
        assert v.reg[4] == IMAGE
        hr = options.get('info_hr', 0)
        # Deliberately leave ImageInfo unwritten: the actual owner never reads it.
        log('info', hr)
        return hr

    def draw(v):
        assert v.reg[4] == IMAGE and v.reg[5] == dc
        hr = options.get('draw_hr', 0)
        log('draw', hr, dc)
        # A failing decoder produces no pixels. The DIB fixture's pattern remains.
        return hr

    for off, address, hook in ((0x14, 0xf1000020, image), (8, 0xf1000030, release),
                               (0x48, 0xf1000030, release), (0x50, 0xf1000040, info),
                               (0x58, 0xf1000050, draw)):
        m.write(VTABLE+off, address)
        m.hooks[address] = hook

    def make_dc(v):
        assert v.reg[4] == 0
        log('create_dc', dc)
        return dc

    def dib(v):
        assert v.read(v.reg[5]+4) == 5 and v.read(v.reg[5]+8) == 3
        if bitmap:
            put(v, BITS, initial)
            v.write(v.reg[7], BITS)
            v.write(BITS-4, 0xa55aa55a)
            v.write(BITS+len(initial), 0xa55aa55a)
        log('dib', bitmap, v.reg[4])
        return bitmap

    def select(v):
        assert v.reg[4] == dc
        log('select', v.reg[5], dc)
        return options.get('selection', 0x7777)

    def delete_dc(v):
        assert v.reg[4] == dc
        log('delete_dc', dc)
        return int(bool(dc))

    def delete_bitmap(v):
        log('delete_bitmap', v.reg[4])
        return 1

    def notify(v):
        assert v.reg[4:8] == [5, 0x15, 0x67, 0]
        log('notify', v.reg[6])
        return 0

    def cookie(v):
        assert v.reg[4] == m.read(0x2f960+delta)
        log('cookie_checked')
        return 0

    for at, hook in ((0x251cc, make_dc), (0x251bc, dib), (0x251ac, select),
                     (0x2519c, lambda v: 1), (0x2518c, delete_dc),
                     (0x2516c, delete_bitmap), (0x23580, notify),
                     (0x4a000, lambda v: 0x1111), (0x4a100, lambda v: 1),
                     (0x25510, cookie)):
        m.hooks[at+delta] = hook
    answer = invoke(m, 0x1a318+delta, [OBJ], limit=100000)
    cleaned = False
    if bitmap and any(e[0] == 'dib' for e in events):
        cleaned = data(m, BITS, len(initial)) == expected
        assert m.read(BITS-4) == m.read(BITS+len(initial)) == 0xa55aa55a
    assert answer == 0xffffffff
    assert events[-2:] == [['notify', 0x67], ['cookie_checked']]
    return dict(events=events, published_bitmap=m.read(OBJ+0x2926),
                pixel_cleanup_ran=cleaned, interpreted_instructions=m.steps,
                abi_and_canaries_verified=True)


def verify(raw):
    sha = hashlib.sha256(raw).hexdigest()
    if sha not in INPUTS:
        raise ValueError('Expected exact MAX04 or PR33 MgrUSB input')
    results = []
    for delta in (0, 0x1000, 0x10000, 0x123000):
        moved = relocated(raw, delta) if delta else raw
        for previous in (0, 0x9999):
            for name, options in CASES:
                result = trace(moved, options, previous, delta)
                failed_creation = name in ('factory failure', 'image creation failure')
                expected = 0 if failed_creation or name == 'DIB allocation failure' else 0x8888
                assert result['published_bitmap'] == expected
                assert result['pixel_cleanup_ran'] == (expected != 0)
                deleted = [e[1] for e in result['events'] if e[0] == 'delete_bitmap']
                assert deleted == ([previous] if previous else [])
                results.append(dict(name=name, relocated_base=hex(0x10000+delta),
                                    previous_bitmap=previous, **result))
    return dict(input=INPUTS[sha], sha256=sha, cases=len(results), traces=results,
                native_executed=False, hardware_tested=False,
                performance_measured=False, firmware_modified=False,
                limitations=['Synthetic COM/GDI output and bitmap bytes',
                             'Single-threaded mutex fixture; no shared reader races',
                             'Failed decode is returned immediately, not native pending polling'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--candidate', required=True, type=Path)
    parser.add_argument('--report', required=True, type=Path)
    args = parser.parse_args()
    if args.report.exists():
        raise FileExistsError('Refusing to overwrite previous evidence')
    result = verify(args.candidate.read_bytes())
    result['runner_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    args.report.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in result.items() if k != 'traces'}, indent=2))
