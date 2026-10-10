"""Interpret the complete AppMain mapping initializer with failure-injected APIs.

Real MIPS instructions, fixture handles/views. No native CE or concurrency claim.
"""
import hashlib
import struct
from pathlib import Path
import pefile
from verify_media_responsiveness import VM, call, STACK, parsed
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put, data
from patch_shared_mapping_checks import BASE_SHA, EDITS, SPANS, HIGHS, LOWS, reloc_records

ROOT = Path(__file__).resolve().parents[1]
OBJ = 0x41000000
MAPS = (
    ('MgrMcmShm', 0xb70, 4),
    ('ShmFmMgrIpodAppMain', 0xc5c, 4),
    ('ShmFmMgrIpodAppMainList', 0x13d628, 4),
    ('ShmFmMgrIpodAppMainListUID', 0x9c54, 4),
    ('ShmFmMgrUsbAppMain', 0xe56, 4),
    ('ShmFmMgrUsbAppMainList', 0x977fc, 4),
    ('ShmFmMgrDABCurrentStation', 0x66c, 4),
    ('ShmFmMgrDABScanList', 0x714c, 4),
    ('ShmFmMgrDABPresetList', 0x4d14, 0xf001f),
    ('ShmFmMgrDABOption', 0x30, 4),
    ('ShmFmMgrDABAnnInfo', 0x28, 4),
    ('ShmFmMgrDABEPG', 0x19cc, 4),
    ('SppDataInFileMapName', 0x7dfa8, 0xf001f),
    ('SppDataOutFileMapName', 0x7dfa8, 0xf001f),
)
CREATE, CLOSE, ERROR = 0xf0200000, 0xf0200004, 0xf0200008


class Initializer:
    def __init__(self, raw, fail=None, delta=0, high_views=False, close_result=1):
        pe = parsed(raw)
        self.m = m = VM(pe, [(0x13234 + delta, 0x13d28 + delta)])
        self.fail, self.high_views, self.close_result = fail, high_views, close_result
        self.events, self.live = [], set()
        self.created, self.views = 0, 0
        put(m, OBJ, bytes(0x138))
        m.write(OBJ - 4, 0xa55aa55a); m.write(OBJ + 0x138, 0xa55aa55a)
        for at, hook in ((0x185024, CREATE), (0x185028, CLOSE), (0x185020, ERROR)):
            m.write(at + delta, hook)
        m.hooks = {CREATE: self.create, CLOSE: self.close, ERROR: self.error,
                   0x13ff18 + delta: self.map_view, 0x13ff38 + delta: self.warning}

    def clobber(self):
        # API callees may overwrite caller-saved registers, but not the result.
        for r in (*range(3, 16), 24, 25):
            self.m.reg[r] = 0xdead0000 + r

    def create(self, m):
        index = self.created; self.created += 1
        assert index < len(MAPS)
        name, size, _ = MAPS[index]
        assert m.reg[4:8] == [0xffffffff, 0, 4, 0]
        assert m.read(m.reg[29] + 0x10) == size
        assert m.text(m.read(m.reg[29] + 0x14)) == name
        handle = 0 if self.fail == ('create', index) else 0x1000 + index * 4
        if handle: self.live.add(handle)
        self.events.append(dict(kind='create', index=index, name=name, handle=handle))
        self.clobber()
        return handle

    def map_view(self, m):
        index = (m.reg[4] - 0x1000) // 4
        assert m.reg[4] in self.live
        name, size, access = MAPS[index]
        assert m.reg[5:8] == [access, 0, 0]
        assert m.read(m.reg[29] + 0x10) == (0 if index == 13 else size)
        self.views += 1
        ptr = 0 if self.fail == ('view', index) else (
            (0x83000000 if self.high_views else 0x43000000) + index * 0x200000)
        self.events.append(dict(kind='view', index=index, name=name, pointer=ptr))
        self.clobber()
        return ptr

    def close(self, m):
        handle = m.reg[4]
        assert handle in self.live, 'CloseHandle must receive the real owned handle'
        self.live.remove(handle)
        self.events.append(dict(kind='close', handle=handle, result=self.close_result))
        self.clobber()
        return self.close_result

    def error(self, m):
        self.events.append(dict(kind='error'))
        self.clobber()
        return 8

    def warning(self, m):
        assert m.reg[4] == m.reg[7] == 0 and m.text(m.reg[6]) == 'Warning'
        self.events.append(dict(kind='warning', text=m.text(m.reg[5])))
        self.clobber()
        return 1

    def run(self, delta=0):
        result = call(self.m, 0x13234 + delta, [OBJ], limit=10000)
        assert self.m.read(OBJ - 4) == self.m.read(OBJ + 0x138) == 0xa55aa55a
        # Original preset initialization is the only write outside object/stack.
        preset = (0x83000000 if self.high_views else 0x43000000) + 8 * 0x200000
        assert all(OBJ - 4 <= at < OBJ + 0x13c or STACK - 0x500 <= at < STACK or
                   STACK + 0x30 <= at < STACK + 0x34 or
                   0x185020 + delta <= at < 0x18502c + delta or
                   preset <= at < preset + 0x4d14 for at in self.m.mem)
        return dict(result=result, events=self.events, live_handles=sorted(self.live),
                    object_hex=data(self.m, OBJ, 0x138).hex(), instructions=self.m.steps)


def verify(original, candidate):
    assert hashlib.sha256(original).hexdigest() == BASE_SHA
    traces = []
    # First reproduce both defects against the input executable.
    for index in (4, 11):
        old = Initializer(original, ('view', index)).run()
        assert old['result'] == 1 and len(old['live_handles']) == 14
        assert not any(e['kind'] in ('close', 'warning') for e in old['events'])
        traces.append(dict(name='original undetected failed view', index=index, old=old))
    # Every branch, healthy path and ABI at four load addresses.
    for delta in (0, 0x1000, 0x10000, 0x123000):
        new_code = candidate if delta == 0 else relocated(candidate, delta)
        for high in (False, True):
            old = Initializer(original, high_views=high).run()
            new = Initializer(new_code, delta=delta, high_views=high).run(delta)
            assert old == new and new['result'] == 1
            traces.append(dict(name='healthy parity', delta=hex(delta), high_views=high, result=new))
        for kind in ('create', 'view'):
            for index in range(14):
                new = Initializer(new_code, (kind, index), delta=delta).run(delta)
                assert new['result'] == 0
                assert len(new['live_handles']) == index
                assert len([e for e in new['events'] if e['kind'] == 'create']) == index + 1
                assert len([e for e in new['events'] if e['kind'] == 'warning']) == 1
                offset = 0xa0 + index * 8
                assert bytes.fromhex(new['object_hex'])[offset:offset + 8] == bytes(8)
                if kind == 'view':
                    assert [e['handle'] for e in new['events'] if e['kind'] == 'close'] == [0x1000 + index * 4]
                else:
                    assert not any(e['kind'] == 'close' for e in new['events'])
                if kind == 'create' or index not in (4, 11):
                    old = Initializer(original, (kind, index)).run()
                    assert old == new
                traces.append(dict(name='failed mapping returns failure and stops', kind=kind,
                                   index=index, delta=hex(delta), result=new))
    for index in (4, 11):
        new = Initializer(candidate, ('view', index), close_result=0).run()
        assert new['result'] == 0 and any(e['kind'] == 'warning' for e in new['events'])
        traces.append(dict(name='cleanup API result cannot mask view failure', index=index, result=new))
    return dict(cases=len(traces), traces=traces, full_initializer_executed=True,
                api_calls_are_fixtures=True, native_executed=False,
                end_to_end_startup_recovery_tested=False, concurrency_tested=False)


def structure(original, candidate, recipe):
    before, after = pefile.PE(data=original), pefile.PE(data=candidate)
    restored = bytearray(candidate)
    for edit in recipe['edits']:
        offset = int(edit['offset'], 16); n = edit['bytes']
        assert candidate[offset:offset+n].hex() == edit['after_hex']
        restored[offset:offset+n] = bytes.fromhex(edit['before_hex'])
    assert bytes(restored) == original
    assert len(original) == len(candidate)
    assert before.FILE_HEADER.__pack__() == after.FILE_HEADER.__pack__()
    for a, b in zip(before.sections, after.sections):
        assert a.__pack__() == b.__pack__()
        if a.Name.rstrip(b'\0') not in (b'.text', b'.reloc'): assert a.get_data() == b.get_data()
    d = before.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    table = before.get_data(d.VirtualAddress, d.Size); pos = 0
    targets = {va - before.OPTIONAL_HEADER.ImageBase for va, _, _, _ in EDITS}
    while pos < len(table):
        page, size = struct.unpack_from('<II', table, pos)
        vals = struct.unpack_from('<' + str((size - 8) // 2) + 'H', table, pos + 8)
        i = 0
        while i < len(vals):
            value = vals[i]; i += 1
            if value >> 12: assert page + (value & 4095) not in targets
            if value >> 12 == 4: i += 1
        pos += size
    inside = lambda at: any(a <= at + 0x10000 < b for a,b in SPANS)
    old, new = reloc_records(before), reloc_records(after)
    assert [r for r in old if not inside(r[0])] == [r for r in new if not inside(r[0])]
    for at, kind, _ in new:
        if kind == 5:
            assert int.from_bytes(after.get_data(at,4),'little') >> 26 in (2,3)
        elif kind == 4 and 0x1000 <= at < 0x130000:
            assert int.from_bytes(after.get_data(at,4),'little') >> 26 == 15
    return dict(cases=1, only_three_reviewed_code_words_changed=True,
                resources_imports_sections_exception_rows_unchanged=True,
                changed_check_instructions_have_no_relocation_entries=True,
                relocation_records_outside_prior_edits_exactly_preserved=True)


def relocation_contracts(candidate):
    pe = parsed(candidate); records = reloc_records(pe)
    reviewed = {at+0x10000:(kind,extra) for at,kind,extra in records
                if any(a <= at+0x10000 < b for a,b in SPANS)}
    cases = 0
    for delta in (0x10000,0x120000,0x500000):
        moved = parsed(relocated(candidate,delta))
        for a,b in SPANS:
            for va in range(a,b,4):
                old = int.from_bytes(pe.get_data(va-0x10000,4),'little')
                new = int.from_bytes(moved.get_data(va-0x10000,4),'little')
                record = reviewed.get(va)
                if not record: expected = old
                elif record[0] == 5:
                    expected = (old & 0xfc000000) | ((((old & 0x3ffffff)<<2)+delta)>>2)
                elif record[0] == 4: expected = (old & 0xffff0000) | (((old & 65535)+(delta>>16))&65535)
                elif record[0] == 2: expected = old  # 64KiB-aligned load delta
                else: raise AssertionError(record)
                assert new == expected,hex(va)
                cases += 1
    # Execute formerly corrupted bounded eight-record copy and text helpers
    # at the preferred and three aligned alternate image bases.
    traces = []
    for delta in (0,0x10000,0x120000,0x500000):
        raw = candidate if not delta else relocated(candidate,delta)
        p = parsed(raw)
        for count in (0,1,5,8,9,0xffffffff):
            for null in (False,True):
                m = VM(p,[(0x110708+delta,0x1108f8+delta)])
                shared=0x42000000
                put(m,OBJ,bytes(0x700));put(m,shared,bytes([0x17])*512)
                m.write(OBJ+0x26c,count);m.write(OBJ+0xc,0 if null else shared)
                assert call(m,0x110708+delta,[OBJ]) == int(count<=8 and (count==0 or not null))
                n=count if count<=8 and (count==0 or not null) else 0
                assert data(m,OBJ+0x270,512)==bytes([0x17])*n*64+bytes((8-n)*64)
                traces.append(dict(function='eight-record copy',delta=hex(delta),count=count,null=null))
        for va,end,low,high in ((0x139918,0x139a64,0x600,0x700),(0x1397c8,0x1398a0,0x590,0x600)):
            for units in ([0],[65,0],[low,0],[high-1,0],[high,0],[65]*270+[low,0]):
                m=VM(p,[(va+delta,end+delta)])
                ptr=0x42000000;put(m,ptr,struct.pack('<'+'H'*len(units),*units))
                cookie=0x1234abcd;m.write(0x1853f4+delta,cookie)
                def check(v): assert v.reg[4]==cookie;return 0
                m.hooks[0x140298+delta]=check
                args=[OBJ,ptr] if va==0x139918 else [ptr]
                expected=int(any(low<=u<high for u in units[:units.index(0)]))
                assert call(m,va+delta,args,limit=10000)==expected
                traces.append(dict(function='text direction',va=hex(va),delta=hex(delta),length=len(units)-1))
    return dict(instruction_cases=cases, execution_cases=len(traces),traces=traces,
                aligned_alternate_deltas=['0x10000','0x120000','0x500000'],
                object_offsets_protocol_constants_branches_unchanged_after_rebase=True,
                arbitrary_unaligned_rebases_supported=False,native_loader_tested=False)
