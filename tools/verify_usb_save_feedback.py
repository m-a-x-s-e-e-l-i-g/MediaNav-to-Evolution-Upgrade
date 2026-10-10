"""Execute written save callers/reset/dispatch with explicit CE filesystem/logger fixtures."""
import hashlib
import json
import struct
from pathlib import Path
from patch_usb_save_feedback import BASE_SHA,WATCH,RESET,NOTE,MESSAGES
from patch_usb_reliability import SAVE
from patch_wma_shuffle import WRAP
from verify_usb_reliability import machine,Files,blob,OBJ,INPUT,DIALOG,STACK,STOP,loading
from verify_usb_input_safety import relocated,wide
from verify_usb_resume_modes import cached_words,saved_blob
from verify_wma_shuffle import invoke
from verify_media_responsiveness import parsed
from inspect_bt_pairing import put,data

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'build/usb-resume-modes-development-01/payload/upgrade/Storage Card/System/MgrUSB.exe'
PATH='\\Storage Card2\\USBMusicResume.dat'

def vm(raw,fs=None,delta=0,attached=1,current=None):
    m=machine(raw,delta)
    m.ranges.extend((a+delta,b+delta) for a,b in [(WATCH,WATCH+0x180),(RESET,RESET+0x180),
        (0x1e9fc,0x1ea9c),(0x1b544,0x1b5b0),(0x1b5b0,0x1b5c0),(WRAP,WRAP+0x180),
        (0x1c9b4,0x1c9d0),(0x20c28,0x20ccc),(0x21d00,0x2271c)])
    wide(m,INPUT,PATH);m.write(DIALOG+0x4c,OBJ-8);m.write(DIALOG+0x38,attached);m.write(DIALOG+4,1)
    put(m,OBJ+0xe64,current if current is not None else saved_blob(3,1))
    for off,val in [(0x291a,3),(0x2934,3),(0x291e,1),(0x2938,1)]:m.write(OBJ+off,val)
    logs=[]
    def log(v):
        if v.reg[6] in (NOTE+delta,NOTE+0x100+delta):
            assert v.reg[4:6]==[5,3]
            logs.append((v.text(v.reg[6]),v.reg[7]))
        return 0xfedcba98
    m.hooks[0x23aac+delta]=log
    if fs is not None:fs.bind(m,delta)
    return cached_words(m),logs

def modes_off(m):
    assert all(m.read(OBJ+off)==0 for off in (0x291a,0x291e,0x2934,0x2938,0x1ab0,0x1ab4))

def wrapper(raw):
    cases=0
    for delta in (0,0x1000,0x10000,0x123000):
        moved=relocated(raw,delta) if delta else raw
        for result in (0,1,2,0xffffffff):
            m,logs=vm(moved,delta=delta);before=data(m,OBJ,0x3000);calls=[]
            def save(v):
                assert v.reg[4:6]==[OBJ,INPUT];calls.append(1);return result
            m.hooks[SAVE+delta]=save
            assert invoke(m,WATCH+delta,[OBJ,INPUT])==result
            assert calls==[1] and data(m,OBJ,0x3000)==before
            assert logs==([(MESSAGES[0],STOP)] if not result else []);cases+=1
    return dict(cases=cases,actual_wrapper_bytes_executed=True,one_save_attempt=True,
        exact_bool_return_and_arguments_preserved=True,logging_does_not_replace_result=True,
        object_unchanged=True,callee_registers_stack_and_ra_preserved=True,relocated_bases=3)

def original_defect(raw):
    old=SOURCE.read_bytes();fs=Files({});m,_=vm(old,fs,attached=0)
    assert invoke(m,0x1e9fc,[OBJ-8])==0
    assert fs.files=={} and sum(op=='mutex' for op,_ in fs.events)==2
    fs=Files({});m,logs=vm(raw,fs,attached=0)
    assert invoke(m,0x1e9fc,[OBJ-8])==0
    assert fs.files=={} and not any(op=='write' for op,_ in fs.events)
    assert sum(op=='mutex' for op,_ in fs.events)==1
    modes_off(m);assert [s for s,_ in logs]==[MESSAGES[1]]
    fs=Files({PATH:blob('Old',10)},fault='open_write');m,_=vm(old,fs)
    seen=[];m.hooks[0x23aac]=lambda v:(seen.append(v.reg[6]) or 0)
    assert invoke(m,0x21d00,[OBJ-8,0x15,0x73,0],[0])==1
    assert seen==[] and any(op=='open_fail' for op,_ in fs.events)
    fs=Files({PATH:blob('Old',10)},fault='open_write');m,logs=vm(raw,fs)
    assert invoke(m,0x21d00,[OBJ-8,0x15,0x73,0],[0])==1
    assert [s for s,_ in logs]==[MESSAGES[0]]
    return dict(cases=2,original_failed_load_then_redundant_failed_save_reproduced=True,
        original_failed_explicit_save_has_no_logger_call=True,message_handling_contract_retained=True,
        earlier_checksum_guard_already_prevented_empty_write=True,
        replacement_skips_save_and_second_mutex_after_failed_load=True,active_modes_still_reset=True)

def reset(raw):
    cases=0;old=SOURCE.read_bytes();good=saved_blob(3,1)
    # Missing, malformed, uncommitted, inaccessible or native-invalid input cannot be resaved.
    failed=[({},None),({PATH:b'broken'},None),({PATH+'.new':good},None)]
    failed += [({PATH:good},fault) for fault in ('attributes','hidden','folder','mutex','timeout',
                 'wait_failed','primary_access','close_read','native_close','release','close_mutex')]
    for initial,fault in failed:
        fs=Files(initial,fault=fault);m,logs=vm(raw,fs,attached=0)
        assert invoke(m,0x1e9fc,[OBJ-8])==0
        assert fs.files==initial and not any(op=='write' for op,_ in fs.events)
        assert not fs.handles and not fs.owned;modes_off(m)
        assert [s for s,_ in logs]==[MESSAGES[1]];cases+=1
    for initial in ({PATH:good},{PATH+'.bak':good},{PATH:b'broken',PATH+'.bak':good}):
        fs=Files(initial);m,logs=vm(raw,fs,attached=0)
        assert invoke(m,0x1e9fc,[OBJ-8])==1;modes_off(m);assert logs==[]
        expected=bytearray(good);struct.pack_into('<II',expected,0xc4c,0,0);expected[0]=sum(expected[1:])%256
        assert fs.files[PATH]==bytes(expected) and fs.files[PATH+'.bak']==good
        assert not fs.handles and not fs.owned;cases+=1
    for fault in ('open_write','write_false','short_write','flush','close_write','rotate','publish'):
        fs=Files({PATH:good},fault=fault);m,logs=vm(raw,fs,attached=0)
        assert invoke(m,0x1e9fc,[OBJ-8])==0;modes_off(m)
        assert [s for s,_ in logs]==[MESSAGES[0]]
        assert good in (fs.files.get(PATH),fs.files.get(PATH+'.bak'))
        assert not fs.handles and not fs.owned;cases+=1
    for attached in (1,2,0xffffffff):
        states=[]
        for b in (old,raw):
            fs=Files({PATH:good});m,logs=vm(b,fs,attached=attached)
            invoke(m,0x1e9fc,[OBJ-8]);modes_off(m)
            assert fs.events==[] and fs.files=={PATH:good} and logs==[]
            states.append(data(m,OBJ,0x3000))
        assert states[0]==states[1];cases+=1
    return dict(cases=cases,actual_reset_and_mode_setters_executed=True,
        primary_backup_modes_and_position_preserved=True,no_write_after_any_failed_load=True,
        failed_save_is_reported_and_previous_state_recoverable=True,attached_path_no_io_and_byte_identical=True)

def dispatch(raw):
    cases=0;old=blob('Old',10);new=blob('New',20)
    faults=(None,'open_write','short_write','flush','corrupt_read','rotate','publish','timeout','release','close_mutex')
    # Entire callback, including original dispatch, guard conditions and epilogue.
    for command in (0x73,0x78,0x7c):
        for fault in faults:
            fs=Files({PATH:old},fault=fault);m,logs=vm(raw,fs,current=new)
            assert invoke(m,0x21d00,[OBJ-8,0x15,command,0],[0])==1
            assert len(logs)==int(fault is not None) and all(s==MESSAGES[0] for s,_ in logs)
            assert data(m,OBJ+0xe64,3180)==new and not fs.handles and not fs.owned
            if fault is None:assert fs.files[PATH]==new
            else:assert old in (fs.files.get(PATH),fs.files.get(PATH+'.bak'))
            assert sum(op=='write' for op,_ in fs.events)<=1;cases+=1
    for command,attached,ready in [(0x73,0,1),(0x73,1,0),(0x78,0,1),(0x7c,0,1),(0x74,1,1)]:
        fs=Files({PATH:old});m,logs=vm(raw,fs,attached=attached,current=new);m.write(DIALOG+4,ready)
        assert invoke(m,0x21d00,[OBJ-8,0x15,command,0],[0])==int(command not in (0x78,0x7c))
        assert fs.events==[] and fs.files=={PATH:old} and logs==[];cases+=1
    for attached,initial,expected_logs in [(0,{},[MESSAGES[1]]),(0,{PATH:saved_blob(3,1)},[]),(1,{PATH:old},[])]:
        fs=Files(initial);m,logs=vm(raw,fs,attached=attached)
        assert invoke(m,0x21d00,[OBJ-8,0x15,0x71,0],[0])==1
        modes_off(m);assert [s for s,_ in logs]==expected_logs and not fs.handles and not fs.owned;cases+=1
    return dict(cases=cases,entire_original_message_callback_executed=True,
        explicit_save_and_reset_failures_reported=True,message_handled_return_contract_retained=True,
        inactive_save_branches_and_neighbor_command_unchanged=True,no_retry_or_extra_save=True,
        cleanup_failure_can_follow_successful_publication=True)

def callers(raw):
    cases=0;old=blob('Old',10);new=blob('New',20)
    for at,stop in [(0x1c9b4,0x1c9d0),(0x20c28,0x20c44)]:
        for fault in (None,'open_write','short_write','flush','publish','timeout'):
            fs=Files({PATH:old},fault=fault);m,logs=vm(raw,fs,current=new);m.reg[29]=STACK
            m.run(at,{stop},limit=300000)
            assert m.pc==stop and m.reg[29]==STACK and data(m,OBJ+0xe64,3180)==new
            assert [s for s,_ in logs]==([] if fault is None else [MESSAGES[0]])
            if logs:assert logs[0][1]==(0x1c9d0 if at==0x1c9b4 else 0x20c44)
            assert not fs.handles and not fs.owned;cases+=1
    # USB-removal cleanup continues after both successful and failed saves.
    for fault in (None,'open_write','publish'):
        fs=Files({PATH:old},fault=fault);m,logs=vm(raw,fs,current=new);m.reg[29]=STACK;m.write(STACK+0x20,0)
        sent=[]
        for at in (0x237b4,0x23580):m.hooks[at]=lambda v,at=at:(sent.append((at,v.reg[4:8])) or 1)
        m.run(0x20c28,{0x20cb0},limit=300000)
        assert m.read(DIALOG+0x38)==0 and len(sent)==2
        assert [s for s,_ in logs]==([] if fault is None else [MESSAGES[0]])
        assert not fs.handles and not fs.owned;cases+=1
    return dict(cases=cases,actual_play_and_removal_save_call_sites_executed=True,
        caller_pc_reported=True,removal_status_and_two_notifications_continue_after_failed_save=True)

def relocation_calls(raw):
    cases=0
    for delta in (0x1000,0x10000,0x123000):
        moved=relocated(raw,delta)
        for fault in (None,'open_write'):
            fs=Files({PATH:blob('Old',10)},fault=fault);m,logs=vm(moved,fs,delta)
            assert invoke(m,0x21d00+delta,[OBJ-8,0x15,0x7c,0],[0])==1
            assert [s for s,_ in logs]==([] if fault is None else [MESSAGES[0]]);cases+=1
        for initial in ({},{PATH:saved_blob(3,1)}):
            fs=Files(initial);m,logs=vm(moved,fs,delta,attached=0)
            assert invoke(m,0x1e9fc+delta,[OBJ-8])==int(bool(initial))
            modes_off(m);assert [s for s,_ in logs]==([] if initial else [MESSAGES[1]]);cases+=1
    return dict(cases=cases,relocated_bases=3,real_save_dispatch_and_reset_at_alternate_bases=True)

def structure(raw,recipe):
    old=SOURCE.read_bytes();a=parsed(old);b=parsed(raw)
    assert hashlib.sha256(old).hexdigest()==BASE_SHA and len(old)==len(raw)
    assert [s.__pack__() for s in a.sections]==[s.__pack__() for s in b.sections]
    imports=lambda p:[(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in p.DIRECTORY_ENTRY_IMPORT]
    assert imports(a)==imports(b) and a.OPTIONAL_HEADER.AddressOfEntryPoint==b.OPTIONAL_HEADER.AddressOfEntryPoint
    allowed=[(int(e['offset'],16),int(e['offset'],16)+e['bytes']) for e in recipe['edits']]
    for i in (3,5):off=a.OPTIONAL_HEADER.DATA_DIRECTORY[i].get_file_offset()+4;allowed.append((off,off+4))
    assert all(x==y or any(lo<=i<hi for lo,hi in allowed) for i,(x,y) in enumerate(zip(old,raw)))
    def rows(p):
        d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];t=p.get_data(d.VirtualAddress,d.Size)
        return [struct.unpack_from('<5I',t,i) for i in range(0,len(t),20)]
    before=rows(a);after=rows(b)
    assert len(after)==len(before)+2 and all(x[1]<=y[0] for x,y in zip(after,after[1:]))
    assert set((x,y,h,v,x if x==0x1e9fc else pro) for x,y,h,v,pro in before).issubset(after)
    assert (WATCH,WATCH+88,0,0,WATCH+16) in after and (RESET,RESET+196,0,0,RESET+16) in after
    for lo,hi in [(0x21d00,0x224b4),(0x224b8,0x226b8),(0x226bc,0x2271c)]:
        assert b.get_data(lo-0x10000,hi-lo)==a.get_data(lo-0x10000,hi-lo)
    for at in (0x224b8,0x226bc):assert b.get_data(at-0x10000,4)==a.get_data(at-0x10000,4)
    for delta in (0x1000,0x10000,0x123000):assert rows(parsed(relocated(raw,delta)))==[
        tuple(n+delta if n else 0 for n in row) for row in after]
    return dict(cases=1,only_declared_bytes_changed=True,sections_imports_entry_unchanged=True,
        earlier_helpers_and_all_other_exception_rows_preserved=True,original_reset_row_now_tail_entry=True,
        two_wrapper_prologs_and_relocations_valid=True,original_save_path_delay_slots_unchanged=True)

def verify(raw):
    results={}
    for name,fn in [('wrapper',wrapper),('original_defect',original_defect),('reset',reset),('dispatch',dispatch),
                    ('callers',callers),('relocations',relocation_calls)]:
        results[name]=fn(raw);print(name,json.dumps(results[name]),flush=True)
    return results
