"""Full normal/resume metadata owners with bounded strings and snapshot footprints."""
import hashlib
import struct
from types import FunctionType

import verify_artwork_stack_frame as prior
from inspect_bt_pairing import data, put
from inspect_wave_queue import STOP
from patch_usb_metadata_copies import BASE_SHA, SITES, block
from verify_media_responsiveness import VM, parsed, STACK
from verify_usb_input_safety import relocated, wide

OBJECT, MANAGER, FILES, PATH, COOKIE = 0x41000000, 0x42000000, 0x43000000, 0x44000000, 0xabcd
OWNERS = ((0x19d3c, 0x1a0d4, 0x2908), (0x1a0d4, 0x1a318, 0x1cc8))


def structure(previous, candidate, recipe):
    assert hashlib.sha256(previous).hexdigest() == BASE_SHA == recipe['base_sha256']
    assert hashlib.sha256(candidate).hexdigest() == recipe['sha256']
    pe = parsed(previous)
    expected = {pe.get_offset_from_rva(at-0x10000): block(dest+field, field, count)
                for at, dest, field, count in SITES}
    restored = bytearray(candidate)
    assert len(recipe['edits']) == len(expected) == 14
    for edit in recipe['edits']:
        at = edit['offset']
        assert edit['bytes'] == 16 and bytes.fromhex(edit['after_hex']) == expected[at]
        assert candidate[at:at+16] == expected[at]
        assert bytes.fromhex(edit['before_hex']) == previous[at:at+16]
        # The call word and its MIPS_JMPADDR relocation remain unchanged.
        assert candidate[at+8:at+12] == previous[at+8:at+12]
        restored[at:at+16] = previous[at:at+16]
    assert restored == previous
    return dict(cases=1, snapshot_sites=14, only_reviewed_blocks_changed=True,
                calls_relocations_frames_and_exception_rows_unchanged=True)


def trace(raw, owner, flags, text, filename, media_type=1, mutate=False,
          delta=0, poison=0xa5):
    entry, end, frame = owner
    m = VM(parsed(raw), [(entry+delta, end+delta)])
    put(m, OBJECT, bytes([0x6d])*0x2940)
    put(m, MANAGER, bytes(0x100)); m.write(MANAGER+0x48, FILES)
    put(m, STACK-frame, bytes([poison])*frame)
    m.write(STACK-frame-4, 0x13579bdf); m.write(STACK, 0x2468ace0)
    m.write(0x2f960+delta, COOKIE)
    wide(m, PATH, filename, 1040)
    wide(m, OBJECT+0x1290, filename, 260)
    snapshots, logs, parsed_tags, updates = [], [], [], []

    def tag(mask, suffix=''):
        for offset, value in ((0, 'Artist '+text+suffix), (0x208, 'Album '+text+suffix),
                              (0x410, text+suffix)):
            value = value[:259]
            wide(m, OBJECT+4+offset, value, 260)
        m.write(OBJECT+4+0xe40, mask)
    tag(flags)
    initial_tag = data(m, OBJECT+4, 0xe48)

    def copy(v):
        destination, source, count = v.reg[4:7]
        if OBJECT+4 <= source < OBJECT+4+0xe44:
            assert source+count <= OBJECT+4+0xe44
            assert STACK-frame <= destination and destination+count <= STACK
            snapshots.append(dict(field=source-OBJECT-4, bytes=count,
                                  stack_offset=destination-(STACK-frame)))
        put(v, destination, data(v, source, count))
        return destination

    def bounded_copy(v):
        destination, capacity = v.reg[4], v.reg[5]
        source = v.reg[6]
        for n in range(capacity):
            unit = v.read(source+2*n, 2); v.write(destination+2*n, unit, 2)
            if not unit: return 0
        raise AssertionError('String exceeds existing destination')

    def count_copy(v):
        destination, source, count = v.reg[4:7]
        for n in range(count):
            value = v.read(source+2*n, 2)
            v.write(destination+2*n, value, 2)
            if not value:
                for j in range(n+1, count): v.write(destination+2*j, 0, 2)
                break
        return destination

    def length(v):
        for n in range(1040):
            if not v.read(v.reg[4]+2*n, 2): return n
        raise AssertionError('Unterminated filename')

    def parse(v):
        assert v.reg[4] == OBJECT+4 and v.reg[6] == media_type
        parsed_tags.append(dict(path=v.text(v.reg[5]), media_type=v.reg[6], language=v.reg[7]))
        return 0

    def log(v):
        item = dict(level=v.reg[5])
        if v.reg[5] == 0:
            item['line'] = v.read(v.reg[29]+0x10)
            value = v.read(v.reg[29]+0x14)
            item['text'] = v.text(value)
            assert len(item['text'].encode('utf-16-le')) <= 518
            if mutate:
                # Each later snapshot must still observe changes after logging.
                tag(flags ^ 6, ' changed')
                updates.append(data(v, OBJECT+4, 0xe48))
        logs.append(item)
        return 0

    def cookie(v):
        assert v.reg[4] == COOKIE
        return 1

    m.hooks.update({at+delta: fn for at, fn in (
        (0x231a4, lambda v: MANAGER), (0x13334, lambda v: media_type),
        (0x13350, lambda v: (wide(v, v.reg[6], filename, 1040) or 0)),
        (0x13318, lambda v: PATH), (0x19254, parse),
        (0x253dc, lambda v: (put(v, v.reg[4], bytes([v.reg[5]&255])*v.reg[6]) or v.reg[4])),
        (0x25668, copy), (0x253bc, length), (0x25578, bounded_copy),
        (0x25558, count_copy), (0x23aac, log), (0x25510, cookie))})
    saved = {r: 0x12340000+r for r in (*range(16, 24), 28, 30)}
    for r, value in saved.items(): m.reg[r] = value
    m.reg[4:8] = [OBJECT, PATH if entry == 0x1a0d4 else 17, media_type if entry == 0x1a0d4 else 3, 0]
    m.reg[29], m.reg[31] = STACK, STOP
    m.run(entry+delta, {STOP}, limit=15000)
    assert m.reg[29] == STACK and m.reg[31] == STOP
    assert all(m.reg[r] == value for r, value in saved.items())
    assert m.read(STACK-frame-4) == 0x13579bdf and m.read(STACK) == 0x2468ace0
    assert data(m, OBJECT+4, 0xe48) == (updates[-1] if updates else initial_tag)
    outputs = [data(m, OBJECT+offset, 520).hex() for offset in (0x1ce6, 0x1eee, 0x20f6)]
    return dict(result=m.reg[2], outputs=outputs, logs=logs, parsed_tags=parsed_tags,
                snapshots=snapshots, metadata_bytes_copied=sum(s['bytes'] for s in snapshots),
                abi_and_canaries_verified=True, tag_unchanged_except_fixture_update=True)


def verify(previous, candidate, recipe):
    checks = structure(previous, candidate, recipe)
    records = []
    texts = ('Title', '', '日Āé', '😀'*80, 'x'*259)
    for delta in (0, 0x1000, 0x10000, 0x123000):
        old = relocated(previous, delta) if delta else previous
        new = relocated(candidate, delta) if delta else candidate
        for owner in OWNERS:
            for flags in range(8):
                for text in texts:
                    for mutate in (False, True):
                        filename = '\\MD\\Folder\\fallback 日.mp3' if flags & 1 else 'fallback 日.mp3'
                        pair = [trace(content, owner, flags, text, filename, mutate=mutate,
                                      delta=delta, poison=0xa5 if mutate else 0x5a)
                                for content in (old, new)]
                        before, after = pair
                        for name in ('result', 'outputs', 'logs', 'parsed_tags'):
                            assert before[name] == after[name], name
                        if not mutate:
                            expected = (text[:259] if flags & 1 else filename,
                                        ('Artist '+text)[:259] if flags & 4 else 'No Artist',
                                        ('Album '+text)[:259] if flags & 2 else 'No Album')
                            for actual, value in zip(after['outputs'], expected):
                                wanted = (value+'\0').encode('utf-16-le')
                                assert bytes.fromhex(actual) == wanted+bytes(520-len(wanted))
                        assert before['metadata_bytes_copied'] > after['metadata_bytes_copied']
                        assert all(s['bytes'] in (4, 520) for s in after['snapshots'])
                        if not mutate and flags == 7:
                            assert (before['metadata_bytes_copied'], after['metadata_bytes_copied']) == (25564, 2092)
                        records.append(dict(owner=hex(owner[0]), delta=hex(delta), flags=flags,
                                            text_case=texts.index(text), mutation_after_log=mutate,
                                            before_bytes=before['metadata_bytes_copied'],
                                            after_bytes=after['metadata_bytes_copied'],
                                            output_sha256=hashlib.sha256(bytes.fromhex(''.join(after['outputs']))).hexdigest()))
            for media_type in (0, 2, 3):
                pair = [trace(content, owner, 7, 'Title', 'fallback.mp3',
                              media_type=media_type, delta=delta) for content in (old, new)]
                for name in ('result', 'outputs', 'logs', 'parsed_tags'): assert pair[0][name] == pair[1][name]
                records.append(dict(owner=hex(owner[0]), delta=hex(delta), media_type=media_type,
                                    before_bytes=pair[0]['metadata_bytes_copied'], after_bytes=pair[1]['metadata_bytes_copied']))
            for filename in ('\\MD\\Folder\\fallback 日.mp3', 'x'*255+'.mp3'):
                pair = [trace(content, owner, 0, 'Unused', filename, delta=delta)
                        for content in (old, new)]
                for name in ('result', 'outputs', 'logs', 'parsed_tags'): assert pair[0][name] == pair[1][name]
                wanted = filename.rsplit('\\', 1)[-1] if owner[0] == 0x19d3c else filename
                encoded = (wanted+'\0').encode('utf-16-le')
                assert bytes.fromhex(pair[1]['outputs'][0]) == encoded+bytes(520-len(encoded))
                records.append(dict(owner=hex(owner[0]), delta=hex(delta), filename=filename,
                                    before_bytes=pair[0]['metadata_bytes_copied'], after_bytes=pair[1]['metadata_bytes_copied']))
    return dict(cases=checks['cases']+len(records), structure=checks, traces=records,
                maximum_path_snapshot_bytes_before=25564, maximum_path_snapshot_bytes_after=2092,
                native_executed=False, hardware_tested=False, native_timing_measured=False,
                limits=['Actual normal/resume owner instructions; parser, file manager, CRT and logger are fixtures',
                        'Copy-byte counts are not device latency or process-RAM measurements',
                        'Original frames and snapshot order retained; native concurrency not emulated'])


def retained_functions(intermediate, recipe):
    def cumulative(previous, candidate, combined):
        a = prior.structure(previous, intermediate, combined['previous_stack_recipe'])
        b = structure(intermediate, candidate, recipe)
        return dict(cases=a['cases']+b['cases'], stages=[a, b])
    verifier = FunctionType(prior.verify.__code__, dict(prior.verify.__globals__, structure=cumulative),
                            'retained_stack_checks')
    stages = FunctionType(prior.retained_functions.__code__,
                          dict(prior.retained_functions.__globals__, structure=cumulative),
                          'retained_metadata_stages')
    return verifier, stages
