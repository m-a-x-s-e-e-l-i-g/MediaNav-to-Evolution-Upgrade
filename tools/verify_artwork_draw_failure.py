"""Native renderer failure/healthy parity, ABI, cleanup and relocation evidence."""
import hashlib
from types import FunctionType

from inspect_artwork_render_failures import CASES, trace
from patch_artwork_draw_failure import BASE_SHA, SITE, CAPACITY
from verify_media_responsiveness import parsed
from verify_usb_input_safety import relocated


def structure(previous, candidate, recipe):
    assert hashlib.sha256(previous).hexdigest() == BASE_SHA
    assert hashlib.sha256(candidate).hexdigest() == recipe['sha256']
    assert len(previous) == len(candidate)
    p, q = parsed(previous), parsed(candidate)
    assert [s.__pack__() for s in p.sections] == [s.__pack__() for s in q.sections]
    assert p.OPTIONAL_HEADER.AddressOfEntryPoint == q.OPTIONAL_HEADER.AddressOfEntryPoint
    for index in (1, 3):
        a, b = p.OPTIONAL_HEADER.DATA_DIRECTORY[index], q.OPTIONAL_HEADER.DATA_DIRECTORY[index]
        assert (a.VirtualAddress, a.Size) == (b.VirtualAddress, b.Size)
        assert p.get_data(a.VirtualAddress, a.Size) == q.get_data(b.VirtualAddress, b.Size)
    assert SITE+CAPACITY == 0x1a540  # Rejoin original DC/COM release path.
    restored = bytearray(candidate)
    for edit in recipe['edits']:
        off, size = edit['offset'], edit['bytes']
        assert candidate[off:off+size].hex() == edit['after_hex']
        restored[off:off+size] = bytes.fromhex(edit['before_hex'])
    assert bytes(restored) == previous
    return dict(cases=1, exact_input_restored=True, imports_and_exception_table_unchanged=True,
                sections_unchanged=True, original_frame_and_cleanup_preserved=True)


def verify(previous, candidate, recipe):
    checks = structure(previous, candidate, recipe)
    traces = []
    scenarios = CASES + tuple((f'Draw HRESULT {hr:08x}', {'draw_hr': hr})
                              for hr in (0, 1, 0x7fffffff, 0x80000000, 0x80004005, 0xffffffff))
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        new = relocated(candidate, delta) if delta else candidate
        for prior in (0, 0x9999):
            for name, options in scenarios:
                before, after = trace(old, options, prior, delta), trace(new, options, prior, delta)
                rejected = options.get('draw_hr', 0) >= 0x80000000
                if rejected:
                    assert before['published_bitmap'] == 0x8888 and before['pixel_cleanup_ran']
                    assert after['published_bitmap'] == 0 and not after['pixel_cleanup_ran']
                    deletes = [e[1] for e in after['events'] if e[0] == 'delete_bitmap']
                    assert deletes == [0x8888]+([prior] if prior else [])
                    expected = list(before['events'])
                    cleanup = next(i for i, event in enumerate(expected) if event[0] == 'delete_dc')
                    expected.insert(cleanup, ['delete_bitmap', 0x8888])
                    assert after['events'] == expected
                else:
                    assert {k: v for k, v in before.items() if k != 'interpreted_instructions'} == {
                        k: v for k, v in after.items() if k != 'interpreted_instructions'}
                traces.append(dict(name=name, delta=hex(delta), previous_bitmap=prior,
                                   rejected_failed_draw=rejected, before=before, after=after))
    return dict(cases=checks['cases']+len(traces), structure=checks, traces=traces,
                native_executed=False, hardware_tested=False, performance_measured=False)


def retained_functions(duration, intermediate, recipe, draw_recipe):
    """Isolate older verifiers; keep original sources and module globals untouched."""
    import verify_usb_completion_event as prior

    def cumulative(previous, candidate, ignored):
        a = prior.structure(previous, intermediate, recipe)
        b = structure(intermediate, candidate, draw_recipe)
        return dict(cases=a['cases']+b['cases'], stages=[a, b])

    def clone(fn):
        return FunctionType(fn.__code__, dict(fn.__globals__, structure=cumulative), fn.__name__)

    return clone(prior.verify), clone(prior.retained), prior.retained_graph_state
