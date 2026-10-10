"""Actual renderer with stateful DC/bitmap ownership and failing selection fixtures."""
import itertools
from types import FunctionType

import inspect_artwork_render_failures as diagnosis
import verify_artwork_draw_failure as draw
from patch_artwork_gdi_guards import BASE_SHA, SITE, CAPACITY
from verify_usb_input_safety import relocated


def structure(previous, candidate, recipe):
    fn = FunctionType(draw.structure.__code__, dict(draw.structure.__globals__,
                      BASE_SHA=BASE_SHA, SITE=SITE, CAPACITY=CAPACITY), 'gdi_structure')
    return fn(previous, candidate, recipe)


def native_machine(raw, delta=0):
    m = diagnosis.vm(raw, delta)
    m.ranges.extend(((0x1a500+delta, 0x1a528+delta),
                     (0x1a528+delta, 0x1a540+delta)))
    return m


compatible_trace = FunctionType(diagnosis.trace.__code__,
                               dict(diagnosis.trace.__globals__, vm=native_machine),
                               'retained_renderer', diagnosis.trace.__defaults__)


def trace(raw, options, previous=0, delta=0):
    state = dict(live={previous} if previous else set(), selected=None,
                 dc_alive=False, selects=0, calls=[], pixels=[])
    bitmap, dc = options.get('bitmap', 0x8888), options.get('dc', 0x6666)
    stock = options.get('stock', 0x7777)

    class Hooks(dict):
        def __setitem__(self, address, original):
            if address == 0x251cc+delta:
                def wrapped(v):
                    result = original(v)
                    state['dc_alive'] = bool(result)
                    state['selected'] = stock if result else None
                    state['calls'].append(['create_dc', result])
                    return result
            elif address == 0x251bc+delta:
                def wrapped(v):
                    result = original(v)
                    if result: state['live'].add(result)
                    state['calls'].append(['dib', result])
                    return result
            elif address == 0x251ac+delta:
                def wrapped(v):
                    original(v)
                    initial = state['selects'] == 0
                    state['selects'] += 1
                    fail = options.get('select_fail' if initial else 'restore_fail', False)
                    result = 0 if fail or not state['dc_alive'] or not v.reg[5] else state['selected']
                    if result: state['selected'] = v.reg[5]
                    state['calls'].append(['select', v.reg[5], result])
                    return result or 0
            elif address == 0xf1000050:
                def wrapped(v):
                    result = original(v)
                    if not state['dc_alive']: result = diagnosis.E_FAIL
                    state['calls'].append(['draw', state['selected'], result])
                    return result
            elif address == 0x2518c+delta:
                def wrapped(v):
                    result = original(v)
                    if result:
                        state['dc_alive'] = False
                        state['selected'] = None
                    state['calls'].append(['delete_dc', v.reg[4], result])
                    return result
            elif address == 0x2516c+delta:
                def wrapped(v):
                    original(v)
                    handle = v.reg[4]
                    # CE refuses a bitmap that is still selected into a live DC.
                    result = int(handle in state['live'] and not (
                        state['dc_alive'] and state['selected'] == handle))
                    if result: state['live'].remove(handle)
                    state['calls'].append(['delete_bitmap', handle, result])
                    return result
            else:
                wrapped = original
            super().__setitem__(address, wrapped)

    def machine(content, relocation=0):
        m = native_machine(content, relocation)
        m.hooks = Hooks(m.hooks)
        return m

    def capture(m, at, size):
        value = diagnosis.data(m, at, size)
        if at == diagnosis.BITS: state['pixels'].append(value.hex())
        return value

    fn = FunctionType(diagnosis.trace.__code__, dict(diagnosis.trace.__globals__,
                      vm=machine, data=capture), 'stateful_render', diagnosis.trace.__defaults__)
    result = fn(raw, options, previous, delta)
    return dict(result, gdi_calls=state['calls'], live_bitmaps=sorted(state['live']),
                dc_alive=state['dc_alive'], selected=state['selected'], pixel_bytes=state['pixels'])


def verify(previous, candidate, recipe):
    checks = structure(previous, candidate, recipe)
    records = []
    initial, cleaned, _ = diagnosis.pixel_fixture(5, 3)
    hrs = (0, 1, 0x7fffffff, 0x80000000, diagnosis.E_FAIL, 0xffffffff)
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        new = relocated(candidate, delta) if delta else candidate
        for dc, bitmap, selection, restoration, stock, hr, prior in itertools.product(
                (0, 0x6666), (0, 0x8888), (False, True), (False, True),
                (0x7777, 0x80001000), hrs, (0, 0x9999)):
            options = dict(dc=dc, bitmap=bitmap, select_fail=selection,
                           restore_fail=restoration, stock=stock, draw_hr=hr)
            before, after = trace(old, options, prior, delta), trace(new, options, prior, delta)
            healthy = bool(dc and bitmap and not selection and not restoration and hr < 0x80000000)
            assert after['published_bitmap'] == (bitmap if healthy else 0)
            assert after['live_bitmaps'] == ([bitmap] if healthy else [])
            assert not after['dc_alive'] and after['selected'] is None
            assert after['pixel_cleanup_ran'] == healthy
            if after['pixel_bytes']:
                assert after['pixel_bytes'] == [(cleaned if healthy else initial).hex()]
            operations = [row[0] for row in after['gdi_calls']]
            if not dc:
                assert 'dib' not in operations and 'select' not in operations and 'draw' not in operations
            elif bitmap and selection:
                assert operations.count('select') == 1 and 'draw' not in operations
            elif bitmap and restoration:
                delete_dc = next(i for i, row in enumerate(after['gdi_calls']) if row[0] == 'delete_dc')
                delete_bitmap = next(i for i, row in enumerate(after['gdi_calls'])
                                     if row[:2] == ['delete_bitmap', bitmap])
                assert delete_dc < delete_bitmap
            assert all(row[2] == 1 for row in after['gdi_calls'] if row[0] == 'delete_bitmap')
            if dc and not selection and not restoration:
                assert {k: v for k, v in before.items() if k != 'interpreted_instructions'} == {
                    k: v for k, v in after.items() if k != 'interpreted_instructions'}
            records.append(dict(delta=hex(delta), previous_bitmap=prior, options=options,
                                before=before, after=after))
    # Explicitly demonstrate the old draw-failure/restore-failure orphan.
    example = trace(previous, dict(draw_hr=diagnosis.E_FAIL, restore_fail=True))
    assert example['published_bitmap'] == 0 and example['live_bitmaps'] == [0x8888]
    return dict(cases=checks['cases']+len(records)+1, structure=checks,
                original_orphan=example, traces=records, native_executed=False,
                hardware_tested=False, timing_measured=False,
                limits=['Single-threaded successful mutex and DC deletion fixtures',
                        'Synthetic immediate Draw result and DIB bytes',
                        'Native GDI, decoder and shared readers remain unverified'])


def retained_functions(intermediate, recipe):
    """Retain prior checks except the two intentionally repaired failure fixtures."""
    def cumulative(previous, candidate, combined):
        a = draw.structure(previous, intermediate, combined['previous_draw_recipe'])
        b = structure(intermediate, candidate, recipe)
        return dict(cases=a['cases']+b['cases'], stages=[a, b])

    namespace = dict(draw.verify.__globals__, structure=cumulative, trace=compatible_trace,
                     CASES=tuple(row for row in diagnosis.CASES if row[0] not in (
                         'compatible DC failure', 'bitmap selection failure')))
    focused = FunctionType(draw.verify.__code__, namespace, 'retained_draw_checks')
    stages = FunctionType(draw.retained_functions.__code__,
                         dict(draw.retained_functions.__globals__, structure=cumulative),
                         'retained_gdi_stages')
    return focused, stages
