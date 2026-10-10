"""Renderer stack bounds, full ImageInfo writes and actual GS cookie handler."""
import hashlib
import struct
from types import FunctionType

import inspect_artwork_render_failures as diagnosis
import verify_artwork_gdi_guards as graphics
from patch_artwork_stack_frame import BASE_SHA, FRAME, OLD_FRAME, INFO, CHANGES
from verify_media_responsiveness import VM, parsed, call
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put
from inspect_wave_queue import STOP

COOKIE, HANDLER_STACK = 0xabcd, 0x69000000


class FrameVM(VM):
    def bounds(self, at, size):
        if 0x1a318+self.delta <= getattr(self, 'pc', 0) < 0x1a60c+self.delta:
            if diagnosis.STACK-0x4000 <= at < diagnosis.STACK+0x4000:
                assert diagnosis.STACK-self.frame <= at and at+size <= diagnosis.STACK, 'Owner access outside frame'

    def read(self, at, size=4):
        self.bounds(at, size)
        return super().read(at, size)

    def write(self, at, value, size=4):
        self.bounds(at, size)
        return super().write(at, value, size)


def machine(raw, delta=0):
    m = graphics.native_machine(raw, delta)
    m.__class__ = FrameVM
    m.delta = delta
    word = struct.unpack('<I', parsed(raw).get_data(0x1a318-0x10000, 4))[0]
    m.frame = 0x10000-(word & 0xffff)
    m.write(0x2f960+delta, COOKIE)
    return m


bounded_trace = FunctionType(diagnosis.trace.__code__,
                            dict(diagnosis.trace.__globals__, vm=machine),
                            'bounded_renderer', diagnosis.trace.__defaults__)
bounded_graphics_trace = FunctionType(graphics.trace.__code__,
                                     dict(graphics.trace.__globals__, native_machine=machine),
                                     'bounded_graphics_owner', graphics.trace.__defaults__)


def cookie_handler(raw, delta, cookie):
    m = VM(parsed(raw), [(0x25490+delta, 0x254e4+delta),
                          (0x254e4+delta, 0x25510+delta),
                          (0x25510+delta, 0x25534+delta)])
    dispatcher, row_address = 0x51000000, 0x52000000
    put(m, dispatcher, bytes(32)); put(m, row_address, bytes(20))
    m.write(dispatcher+4, row_address)
    m.write(row_address+0xc, 0x2e758+delta)
    m.write(diagnosis.STACK-0x28, cookie)
    m.write(0x2f960+delta, COOKIE)
    if cookie == COOKIE:
        fn = FunctionType(call.__code__, dict(call.__globals__, STACK=HANDLER_STACK),
                          'actual_gs_handler', call.__defaults__)
        assert fn(m, 0x254e4+delta, [0, diagnosis.STACK, 0, dispatcher]) == 1
        return dict(cookie=cookie, result='handler returns continue-search', abi_verified=True)
    m.reg[4:8] = [0, diagnosis.STACK, 0, dispatcher]
    m.reg[29], m.reg[31] = HANDLER_STACK, STOP
    m.run(0x254e4+delta, {STOP, 0x25534+delta})
    assert m.pc == 0x25534+delta
    return dict(cookie=cookie, result='actual cookie-failure branch reached', abi_verified=False)


def structure(previous, candidate, recipe):
    assert hashlib.sha256(previous).hexdigest() == BASE_SHA
    assert hashlib.sha256(candidate).hexdigest() == recipe['sha256']
    assert len(previous) == len(candidate)
    p, q = parsed(previous), parsed(candidate)
    assert [s.__pack__() for s in p.sections] == [s.__pack__() for s in q.sections]
    for i in range(16):
        a, b = p.OPTIONAL_HEADER.DATA_DIRECTORY[i], q.OPTIONAL_HEADER.DATA_DIRECTORY[i]
        assert a.__pack__() == b.__pack__()
    directory = p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    row = next(struct.unpack_from('<5I', p.get_data(directory.VirtualAddress, directory.Size), i)
               for i in range(0, directory.Size, 20)
               if struct.unpack_from('<I', p.get_data(directory.VirtualAddress, directory.Size), i)[0] == 0x1a318)
    assert row == (0x1a318, 0x1a60c, 0x254e4, 0x2e758, 0x1a338)
    assert p.get_data(0x2e758-0x10000, 4) == q.get_data(0x2e758-0x10000, 4) == struct.pack('<i', -0x28)
    assert p.get_data(0x25490-0x10000, 0xc8) == q.get_data(0x25490-0x10000, 0xc8)
    restored = bytearray(candidate)
    for e in recipe['edits']:
        off = e['offset']
        assert candidate[off:off+4].hex() == e['after_hex']
        assert previous[off:off+4][:2] != candidate[off:off+4][:2]
        assert previous[off:off+4][2:] == candidate[off:off+4][2:]
        restored[off:off+4] = bytes.fromhex(e['before_hex'])
    assert bytes(restored) == previous
    for at, old, new in CHANGES:
        if at not in (0x1a318, 0x1a608):
            assert old-OLD_FRAME == new-FRAME, 'Saved slots and ImageInfo keep their caller-relative addresses'
    return dict(cases=1, edited_immediates=len(CHANGES), exception_and_relocation_tables_unchanged=True,
                handler_and_cookie_offset_unchanged=True, saved_slots_same_caller_addresses=True,
                frame_before=OLD_FRAME, frame_after=FRAME, reserved_stack_bytes_removed=OLD_FRAME-FRAME)


def verify(previous, candidate, recipe):
    checks = structure(previous, candidate, recipe)
    results = []
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        new = relocated(candidate, delta) if delta else candidate
        for hr in (0, diagnosis.E_FAIL):
            for options in ({}, {'draw_hr': diagnosis.E_FAIL}, {'dc': 0}, {'selection': 0}):
                options = dict(options, info_hr=hr)
                snapshots = []
                for raw in (old, new):
                    seen = []
                    def buffer_machine(content, offset=0):
                        m = machine(content, offset)
                        original_hooks = m.hooks
                        class Hooks(dict):
                            def __setitem__(self, at, hook):
                                if at == 0xf1000040:
                                    def info(v, original=hook):
                                        result = original(v)
                                        out = v.reg[5]
                                        expected = diagnosis.STACK-0x68
                                        assert out == expected and out % 8 == 0
                                        before = v.read(out+64)
                                        assert before == COOKIE
                                        for i in range(64): v.write(out+i, (i*17+3)&255, 1)
                                        assert v.read(out+64) == before
                                        seen.append(dict(bytes=64, caller_relative_offset=-0x68,
                                                         buffer_end_is_cookie=True, cookie_intact=True))
                                        return result
                                    hook = info
                                super().__setitem__(at, hook)
                        m.hooks = Hooks(original_hooks)
                        return m
                    fn = FunctionType(diagnosis.trace.__code__,
                                      dict(diagnosis.trace.__globals__, vm=buffer_machine),
                                      'full_image_info', diagnosis.trace.__defaults__)
                    value = fn(raw, options, 0x9999, delta)
                    assert seen and value['abi_and_canaries_verified']
                    snapshots.append(dict(trace=value, info=seen))
                assert snapshots[0] == snapshots[1]
                results.append(dict(delta=hex(delta), options=options, before=snapshots[0], after=snapshots[1]))
        for cookie in (COOKIE, COOKIE-1, 0x1234abcd):
            results.append(dict(delta=hex(delta), exception_cookie=cookie_handler(new, delta, cookie)))
    return dict(cases=checks['cases']+len(results), structure=checks, traces=results,
                native_executed=False, hardware_tested=False, native_memory_measured=False,
                limits=['Synthetic 64-byte ImageInfo and GDI/COM responses',
                        'Actual GS handler instructions; no native exception dispatch or unwinder',
                        'Stack reservation reduction is not a measured process-RAM or speed improvement'])


def retained_functions(intermediate, recipe):
    def cumulative(previous, candidate, combined):
        a = graphics.structure(previous, intermediate, combined['previous_graphics_recipe'])
        b = structure(intermediate, candidate, recipe)
        return dict(cases=a['cases']+b['cases'], stages=[a, b])
    verifier = FunctionType(graphics.verify.__code__,
        dict(graphics.verify.__globals__, structure=cumulative, trace=bounded_graphics_trace),
        'retained_graphics_matrix')
    stages = FunctionType(graphics.retained_functions.__code__,
        dict(graphics.retained_functions.__globals__, structure=cumulative,
             compatible_trace=bounded_trace), 'retained_stack_stages')
    return verifier, stages
