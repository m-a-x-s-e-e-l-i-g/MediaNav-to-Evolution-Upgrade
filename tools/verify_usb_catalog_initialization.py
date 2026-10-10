"""Execute catalog construction/reset and the ROM allocation argument path."""
import hashlib
import struct
from pathlib import Path
from types import FunctionType

import pefile
import verify_usb_metadata_copies as prior
from inspect_bt_pairing import data, put
from patch_usb_catalog_initialization import BASE_SHA, SITE, WORD
from verify_media_responsiveness import VM, parsed, call
from verify_usb_input_safety import relocated

ROOT = Path(__file__).resolve().parents[1]
OBJECT, FOREIGN = 0x41000000, 0x47000000
SIZES = (0x284880, 0x4536c0, 0x298100, 0x298100)


def structure(previous, candidate, recipe):
    assert hashlib.sha256(previous).hexdigest() == BASE_SHA == recipe['base_sha256']
    assert hashlib.sha256(candidate).hexdigest() == recipe['sha256']
    assert len(recipe['edits']) == 1
    edit = recipe['edits'][0]
    offset = parsed(previous).get_offset_from_rva(SITE-0x10000)
    assert edit == dict(va=hex(SITE), offset=offset, bytes=4,
                        before_hex='00000000', after_hex=struct.pack('<I', WORD).hex())
    restored = bytearray(candidate)
    assert restored[offset:offset+4] == struct.pack('<I', WORD)
    restored[offset:offset+4] = bytes(4)
    assert restored == previous
    return dict(cases=1, one_delay_slot_initialized=True,
                calls_frames_relocations_and_exception_records_unchanged=True)


def constructor(raw, delta=0, missing=0, event_ok=True, old_pointer=0, high=False):
    m = VM(parsed(raw), [(start+delta, end+delta) for start, end in
                        ((0x14b00, 0x14c54), (0x12aa4, 0x12af0),
                         (0x12e1c, 0x12e80), (0x12af0, 0x12b2c))])
    put(m, OBJECT, bytes([0xa5])*0x275c)
    m.write(OBJECT+0x38, old_pointer)
    m.write(OBJECT-4, 0x13579bdf); m.write(OBJECT+0x275c, 0x2468ace0)
    put(m, FOREIGN, bytes([0x5a])*32)
    allocations, clears, logs, events = [], [], [], []
    buffers = {}

    def allocate(v):
        index = len(allocations)
        assert index < 4 and v.reg[4] == SIZES[index]
        address = (0x8f000000 if high else 0x51000000)+index*0x01000000
        if missing & (1 << index): address = 0
        if address: buffers[address] = SIZES[index]
        allocations.append(dict(bytes=SIZES[index], pointer=address))
        return address

    def zero(v):
        address, fill, size = v.reg[4:7]
        assert fill == 0
        if address == OBJECT+0x40:
            assert size == 0x2712
            put(v, address, bytes(size))
        elif address == FOREIGN:
            assert size == 0x298100
            put(v, address, bytes(32))
        else:
            assert address in buffers and buffers[address] == size, 'Clear through unallocated pointer'
        clears.append(dict(pointer=address, bytes=size))
        return address

    def mutex(v):
        assert v.reg[4] == OBJECT+0x2754
        put(v, v.reg[4], bytes(8))
        return v.reg[4]

    def event(v):
        assert v.reg[4:8] == [0, 0, 0, 0]
        events.append('CreateEventW')
        return 0x7777 if event_ok else 0

    def log(v):
        logs.append(dict(level=v.reg[5], format=v.text(v.reg[6])))
        return 0

    event_api = 0xf1000040
    m.write(0x2f054+delta, event_api)
    m.hooks.update({0x12844+delta: allocate, 0x253dc+delta: zero,
                    0x209e0+delta: mutex, 0x23aac+delta: log, event_api: event})
    result = call(m, 0x14b00+delta, [OBJECT], limit=4000)
    assert result == OBJECT
    assert m.read(OBJECT-4) == 0x13579bdf and m.read(OBJECT+0x275c) == 0x2468ace0
    assert m.read(OBJECT+0x18) == allocations[0]['pointer']
    assert m.read(OBJECT+0x3c) == allocations[1]['pointer']
    assert m.read(0x2fea0+delta) == allocations[2]['pointer']
    assert m.read(OBJECT+0x38) == allocations[3]['pointer']
    assert m.read(OBJECT+4) == (0x7777 if event_ok else 0)
    assert len(events) == 1
    assert all(m.read(OBJECT+offset) == 0 for offset in (0xc, 0x10, 0x14, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34))
    assert data(m, OBJECT+0x40, 0x2712) == bytes(0x2712)
    return dict(result=result, object_sha256=hashlib.sha256(data(m, OBJECT, 0x275c)).hexdigest(),
                allocations=allocations, clears=clears, logs=logs, events=events,
                foreign_prefix_sha256=hashlib.sha256(data(m, FOREIGN, 32)).hexdigest(),
                abi_and_canaries_verified=True)


def allocator_contract(workspace):
    path = workspace/'extracted/705md-rom/fs/Windows/coredll.dll'
    raw = path.read_bytes(); pe = pefile.PE(data=raw)
    assert hashlib.sha256(raw).hexdigest() == '1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c'
    export = next(s for s in pe.DIRECTORY_ENTRY_EXPORT.symbols if s.ordinal == 1095)
    assert export.name == b'??2@YAPAXI@Z'
    base = pe.OPTIONAL_HEADER.ImageBase
    assert base+export.address == 0x40019304
    local = next(s for s in pe.DIRECTORY_ENTRY_EXPORT.symbols if s.name == b'LocalAlloc')
    results = []
    for success in (True, False):
        m = VM(pe, [(0x40019304, 0x40019324), (0x400739cc, 0x40073a44)])
        calls = []
        def allocate(v):
            calls.append(dict(flags=v.reg[4], bytes=v.reg[5]))
            return OBJECT if success else 0
        m.hooks.update({base+local.address: allocate, 0x400236c8: lambda v: 0})
        result = call(m, 0x40019304, [0x275c])
        assert calls == [dict(flags=0, bytes=0x275c)]
        assert result == (OBJECT if success else 0)
        results.append(dict(success=success, local_alloc=calls, result=result))
    return dict(cases=2, rom_sha256=hashlib.sha256(raw).hexdigest(),
                operator_new_export_ordinal=1095, operator_new_va='0x40019304',
                argument_helper_va='0x400739cc', local_alloc_flags=0, traces=results,
                local_alloc_and_new_handler_are_fixtures=True)


def verify(previous, candidate, recipe):
    checks = structure(previous, candidate, recipe)
    records = []
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        new = relocated(candidate, delta) if delta else candidate
        for missing in range(16):
            for event_ok in (False, True):
                for high in (False, True):
                    before = constructor(old, delta, missing, event_ok, 0, high)
                    after = constructor(new, delta, missing, event_ok, 0, high)
                    assert before == after
                    reused = constructor(new, delta, missing, event_ok, FOREIGN, high)
                    assert after == reused
                    records.append(dict(delta=hex(delta), missing_allocations=missing,
                                        event_ok=event_ok, high_pointers=high,
                                        zeroed_and_reused_storage_identical=True,
                                        constructor=after))
        before = constructor(old, delta, old_pointer=FOREIGN)
        after = constructor(new, delta, old_pointer=FOREIGN)
        assert dict(pointer=FOREIGN, bytes=0x298100) in before['clears']
        assert not any(c['pointer'] == FOREIGN for c in after['clears'])
        assert before['object_sha256'] == after['object_sha256']
        assert before['foreign_prefix_sha256'] != after['foreign_prefix_sha256']
        records.append(dict(delta=hex(delta), original_foreign_clear_reproduced=True,
                            previous_clear=before['clears'], candidate_clear=after['clears']))
    return dict(cases=checks['cases']+len(records), structure=checks, traces=records,
                native_executed=False, hardware_tested=False,
                limits=['Actual constructor and reset instructions; allocations, memset, mutex, event and logs are fixtures',
                        'Large clears are checked as API arguments; only object bytes and a foreign-buffer prefix are materialized',
                        'Failed allocations still leave a partial catalog; subsequent scan readiness is unresolved',
                        'No native heap reuse or incident frequency measurement'])


def retained_functions(intermediate, recipe):
    def cumulative(previous, candidate, combined):
        a = prior.structure(previous, intermediate, combined['previous_metadata_recipe'])
        b = structure(intermediate, candidate, recipe)
        return dict(cases=a['cases']+b['cases'], stages=[a, b])
    verifier = FunctionType(prior.verify.__code__, dict(prior.verify.__globals__, structure=cumulative),
                            'retained_metadata_checks')
    stages = FunctionType(prior.retained_functions.__code__,
                          dict(prior.retained_functions.__globals__, structure=cumulative),
                          'retained_catalog_stages')
    return verifier, stages
