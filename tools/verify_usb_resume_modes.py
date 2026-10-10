"""Written MIPS restore guards, checksum-valid file fixtures and real call sites."""
import hashlib
import random
import struct
from pathlib import Path
from patch_usb_resume_modes import BASE_SHA,RESTORE
from verify_media_responsiveness import VM,parsed
from verify_usb_input_safety import relocated,wide
from verify_usb_reliability import machine,Files,blob,OBJ,INPUT,DIALOG,PATH,STACK
from verify_wma_shuffle import invoke
from inspect_bt_pairing import put,data

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'build/usb-folders-development-01/payload/upgrade/Storage Card/System/MgrUSB.exe'
OFFSETS=(0x291a,0x2934,0x291e,0x2938)

def cached_words(m):
    original=m.word;words={}
    def word(pc):
        if pc not in words:words[pc]=original(pc)
        return words[pc]
    m.word=word;return m

def mode_vm(raw,delta=0):
    m=VM(parsed(raw),[(0x1abac+delta,0x1abe0+delta),(RESTORE+delta,RESTORE+0x180+delta)])
    put(m,OBJ,b'\xa5'*0x3000);m.reg[2]=0xabcdef42
    return cached_words(m)

def fields(m):return tuple(m.read(OBJ+o) for o in OFFSETS)

def publish(m,repeat,shuffle,delta=0):
    m.write(OBJ+0x1ab0,repeat);m.write(OBJ+0x1ab4,shuffle)
    before=m.reg[2];assert invoke(m,0x1abac+delta,[OBJ])==before
    expected=(repeat if repeat<4 else 0,shuffle if shuffle<2 else 0)
    assert fields(m)==(expected[0],expected[0],expected[1],expected[1])
    assert m.read(OBJ+0x1ab0)==repeat and m.read(OBJ+0x1ab4)==shuffle
    assert m.read(OBJ+0x2919,1)==m.read(OBJ+0x2922,1)==m.read(OBJ+0x2933,1)==m.read(OBJ+0x293c,1)==0xa5

def exhaustive(raw):
    cases=0;m=mode_vm(raw)
    for n in range(65536):publish(m,n,n^3);cases+=1
    rng=random.Random(706)
    values=[0,1,2,3,4,255,256,65535,65536,0x10001,0x7fffffff,0x80000000,0xfffffffe,0xffffffff]
    pairs=[(a,b) for a in values for b in values]+[(rng.getrandbits(32),rng.getrandbits(32)) for _ in range(256)]
    for a,b in pairs:publish(m,a,b);cases+=1
    old=mode_vm(SOURCE.read_bytes());new=mode_vm(raw)
    for a in range(4):
        for b in range(2):
            for v in (old,new):
                v.write(OBJ+0x1ab0,a);v.write(OBJ+0x1ab4,b);before=data(v,OBJ,0x3000)
                assert invoke(v,0x1abac,[OBJ])==0xabcdef42
                after=data(v,OBJ,0x3000)
                assert all(x==y or any(o<=i<o+4 for o in OFFSETS) for i,(x,y) in enumerate(zip(before,after)))
            assert data(old,OBJ,0x3000)==data(new,OBJ,0x3000);cases+=1
    for delta in (0x1000,0x10000,0x123000):
        m=mode_vm(relocated(raw,delta),delta)
        for a,b in [(3,1),(4,2),(0xffffffff,0xffffffff),(1,0x10001)]:publish(m,a,b,delta);cases+=1
    return dict(cases=cases,all_low16_values=65536,full_dword_boundaries_and_random_values=True,
                valid_modes_byte_identical_to_previous=True,unaligned_active_stores_preserve_neighbors=True,
                saved_blob_unchanged=True,void_return_and_callee_registers_preserved=True,relocated_bases=3)

def original_defect(raw):
    old=mode_vm(SOURCE.read_bytes());old.write(OBJ+0x1ab0,0xffffffff);old.write(OBJ+0x1ab4,0x10001)
    invoke(old,0x1abac,[OBJ]);assert fields(old)==(0xffffffff,0xffffffff,0x10001,0x10001)
    new=mode_vm(raw);publish(new,0xffffffff,0x10001)
    assert fields(new)==(0,0,0,0)
    return dict(cases=1,original_invalid_values_reach_active_and_shared_fields=True,
                invalid_saved_values_now_off=True,native_crash_or_incident_claimed=False)

def saved_blob(repeat,shuffle):
    b=bytearray(blob('Resume title',123));struct.pack_into('<II',b,0xc4c,repeat,shuffle)
    b[0]=sum(b[1:])%256;return bytes(b)

def caller_vm(raw,fs,delta=0):
    m=machine(raw,delta);wide(m,INPUT,PATH);fs.bind(m,delta)
    m.ranges.extend((a+delta,b+delta) for a,b in [(0x1abac,0x1abe0),(RESTORE,RESTORE+0x180),
        (0x1eb30,0x1eb48),(0x1fed0,0x1fef4),(0x20118,0x2013c)])
    m.write(DIALOG+0x4c,OBJ-8);m.reg[16]=OBJ;m.reg[5]=INPUT;m.reg[29]=STACK
    for o in OFFSETS:m.write(OBJ+o,0x77777777)
    return cached_words(m)

def call_sites(raw):
    cases=0
    for delta in (0,0x1000,0x10000,0x123000):
        moved=relocated(raw,delta) if delta else raw
        for start,success,failed in [(0x1eb30,0x1eb48,0x1ebf8),(0x1fed0,0x1fef4,0x1ff88),
                                     (0x20118,0x2013c,0x20210)]:
            for repeat,shuffle in [(0,0),(1,1),(2,0),(3,1),(4,2),(0xffffffff,0x10001)]:
                for backup in (False,True):
                    b=saved_blob(repeat,shuffle)
                    source={PATH:b} if not backup else {PATH:b'bad',PATH+'.bak':b}
                    fs=Files(source);m=caller_vm(moved,fs,delta)
                    m.run(start+delta,{success+delta,failed+delta},limit=300000)
                    assert m.pc==success+delta
                    expected=(repeat if repeat<4 else 0,shuffle if shuffle<2 else 0)
                    assert fields(m)==(expected[0],expected[0],expected[1],expected[1])
                    assert data(m,OBJ+0xe64,3180)==b and fs.files==source
                    assert not fs.handles and not fs.owned and m.reg[29]==STACK;cases+=1
            for source in ({},{PATH:b'bad'},{PATH+'.new':saved_blob(3,1)}):
                fs=Files(source);m=caller_vm(moved,fs,delta)
                m.run(start+delta,{success+delta,failed+delta},limit=300000)
                assert m.pc==failed+delta and fields(m)==(0x77777777,)*4
                assert data(m,OBJ+0xe64,3180)==bytes(3180) and not fs.handles and not fs.owned;cases+=1
    return dict(cases=cases,actual_attach_and_two_resume_call_sites=3,actual_checked_loader_executed=True,
                primary_and_backup_checksum_valid_bad_modes=True,failed_load_never_publishes=True,
                file_bytes_and_loaded_checksum_unchanged=True,relocated_bases=3,filesystem_is_fixture=True)

def structure(raw,recipe):
    old=SOURCE.read_bytes();a=parsed(old);b=parsed(raw)
    assert hashlib.sha256(old).hexdigest()==BASE_SHA and len(old)==len(raw)
    assert [s.__pack__() for s in a.sections]==[s.__pack__() for s in b.sections]
    imports=lambda p:[(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in p.DIRECTORY_ENTRY_IMPORT]
    assert imports(a)==imports(b) and a.OPTIONAL_HEADER.AddressOfEntryPoint==b.OPTIONAL_HEADER.AddressOfEntryPoint
    allowed=[(int(e['offset'],16),int(e['offset'],16)+e['bytes']) for e in recipe['edits']]
    for i in (3,5):
        off=a.OPTIONAL_HEADER.DATA_DIRECTORY[i].get_file_offset()+4;allowed.append((off,off+4))
    assert all(x==y or any(lo<=i<hi for lo,hi in allowed) for i,(x,y) in enumerate(zip(old,raw)))
    d=b.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=b.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    assert (RESTORE,RESTORE+88,0,0,RESTORE) in rows
    old_dir=a.OPTIONAL_HEADER.DATA_DIRECTORY[3];old_table=a.get_data(old_dir.VirtualAddress,old_dir.Size)
    old_rows=[struct.unpack_from('<5I',old_table,i) for i in range(0,len(old_table),20)]
    assert len(rows)==len(old_rows)+1 and set(old_rows).issubset(rows)
    assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    for delta in (0x1000,0x10000,0x123000):
        q=parsed(relocated(raw,delta));d=q.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=q.get_data(d.VirtualAddress,d.Size)
        assert [struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]==[
            tuple(n+delta if n else 0 for n in row) for row in rows]
    return dict(cases=1,only_declared_bytes_changed=True,earlier_code_and_helpers_preserved=True,
                sections_imports_entry_unchanged=True,leaf_pdata_and_all_relocated_rows_valid=True)

def verify(raw):
    results={}
    for name,fn in [('original_defect',original_defect),('exhaustive',exhaustive),('call_sites',call_sites)]:
        results[name]=fn(raw);print(name,results[name],flush=True)
    return results
