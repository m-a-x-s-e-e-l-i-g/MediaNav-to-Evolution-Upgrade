"""Interpret the complete options initializer and snapshot helper with CE fixtures."""
import hashlib
import struct
from verify_usb_status_consumers import Fixture,call,MAP,OBJ,UI,DIALOG
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put
from patch_shared_mapping_checks import reloc_records
from audit_usb_scalar_readers import menu as original_slice

FIELDS=(0xf14,0x1484,0x19f4,0x1f64,0x24d4,0x2a44)
DBG=0xf0a00000

def flags(repeat,shuffle):return [int(repeat==v) for v in range(4)]+[int(shuffle==0),int(shuffle!=0)]

class Menu:
    def __init__(self,raw,ar,delta=0,repeat=0,shuffle=0,initial=None,state=2,usb_enabled=1,
                 language=1,create=True,wait=0,null_obj=False,null_map=False,publish=None):
        self.f=Fixture(raw,ar,delta,create_ok=create,wait_result=wait);f=self.f;m=f.m
        m.ranges.append((0x4f754+delta,0x4f954+delta))
        put(m,DIALOG,bytes(0x4200));put(m,UI,bytes(0x2500))
        self.events=[];self.reads=[];self.writes=[];self.publish=publish;self.published=False;self.deferred=False
        self.initial=initial or [0]*6;self.before_state=state
        m.write(OBJ+0x7c,state);m.write(0x186314+delta,language);m.write(UI+0x2308,usb_enabled)
        m.write(0x1852bc+delta,DBG)
        for offset,value in zip(FIELDS,self.initial):m.write(DIALOG+offset,value)
        for offset,value in ((0x4074,9),(0x4075,1),(0x40c8,9),(0x40c9,1),(0x411c,9),(0x411d,4)):
            m.write(DIALOG+offset,value,1)
        put(m,MAP+0xe42,struct.pack('<II',repeat,shuffle))
        if null_obj:m.write(0x186ce8+delta,0)
        if null_map:m.write(OBJ+0xc4,0)
        def ui_call(name,args):
            def hook(v):
                assert not f.owned and v.reg[4:4+len(args)]==args,(name,v.reg[4:8])
                self.events.append(name);f.clobber();return 7
            return hook
        m.hooks.update({DBG:ui_call('debug',[0x17,3]),
            0x502c4+delta:ui_call('theme',[DIALOG]),0x5004c+delta:ui_call('labels',[DIALOG]),
            0xe7074+delta:ui_call('options registration',[UI+0x24,DIALOG]),
            0x139104+delta:ui_call('USB icon',[DIALOG+0x2f80,0x64 if usb_enabled else 0x63]),
            0x139020+delta:ui_call('redraw',[DIALOG+0x2f80])})
        old_wait=f.wait;old_release=f.release
        def mutate():
            assert not f.owned
            put(m,MAP+0xe42,struct.pack('<II',*publish['values']));self.published=True
        def wait_hook(v):
            if publish and publish['when']=='before wait':mutate()
            return old_wait(v)
        def release_hook(v):
            result=old_release(v)
            if self.deferred or (publish and publish['when']=='after snapshot'):mutate()
            return result
        m.hooks[0xf0900004]=wait_hook;m.hooks[0xf0900008]=release_hook
        old_read,old_write=m.read,m.write
        def read(at,size=4):
            if MAP<=at<MAP+0xe56:
                assert MAP+0xe42<=at and at+size<=MAP+0xe4a
                self.reads.extend(range(at,at+size))
                if publish and publish['when']=='during copy' and not self.deferred:
                    assert f.owned;self.deferred=True
            return old_read(at,size)
        def write(at,value,size=4):
            if at in [DIALOG+v for v in FIELDS] or at==OBJ+0x7c:
                assert not f.owned,'UI/completion state must update after unlocking'
                self.writes.append((at,value,size))
                if publish and publish['when']=='during UI' and not self.published:mutate()
            return old_write(at,value,size)
        m.read,m.write=read,write
    def run(self,entry=0x4f754):
        f=self.f;m=f.m
        self.events=[];self.reads=[];self.writes=[];f.events=[]
        result=call(m,entry+f.delta,[DIALOG]);f.complete()
        assert m.read(DIALOG+0x4074,1)==m.read(DIALOG+0x40c8,1)==0
        assert m.read(DIALOG+0x411c,1)==3
        assert m.read(DIALOG+0x2fb8)==int(m.read(UI+0x2308)!=0)
        assert self.events==['debug','theme']+(['labels'] if m.read(0x186314+f.delta) else [])+['options registration','USB icon','redraw']
        dialog=bytes(m.mem[DIALOG+i] for i in range(0x4200))
        return dict(flags=[m.read(DIALOG+v) for v in FIELDS],state=m.read(OBJ+0x7c),result=result,
            dialog_sha256=hashlib.sha256(dialog).hexdigest(),events=self.events,mutex_events=f.events,
            shared_byte_reads=len(self.reads),flag_writes=len(self.writes),published=self.published,instructions=m.steps)

def verify(before,after,old_ar,ar,r):
    traces=[]
    initials=[flags(rep,shuf) for rep in range(4) for shuf in range(2)]+[[0]*6,[1]*6]
    original_defects=[]
    for old,new,at in ((0,1,0x4f86c),(1,0,0x4f86c),(1,3,0x4f890),(3,2,0x4f8b4)):
        result=original_slice(before,0,old,0,dict(at=at,repeat=new,shuffle=0))
        assert result['flags'][:4] not in ([int(old==v) for v in range(4)],[int(new==v) for v in range(4)])
        original_defects.append(dict(name='original repeated repeat-read defect',old=old,new=new,flags=result['flags']))
    for old,new in ((0,1),(1,0)):
        result=original_slice(before,0,0,old,dict(at=0x4f904,repeat=0,shuffle=new))
        assert sum(result['flags'][4:])!=1
        original_defects.append(dict(name='original repeated shuffle-read defect',old=old,new=new,flags=result['flags']))
    traces+=original_defects
    for delta in (0,0x10000,0x120000,0x500000):
        a=before if not delta else relocated(before,delta);b=after if not delta else relocated(after,delta)
        for rep in range(4):
            for shuf in range(2):
                for idx,initial in enumerate(initials):
                    options=dict(delta=delta,repeat=rep,shuffle=shuf,initial=initial,language=idx%2,usb_enabled=idx%2)
                    old=Menu(a,old_ar,**options).run();new=Menu(b,ar,**options).run()
                    assert old['dialog_sha256']==new['dialog_sha256'] and old['events']==new['events']
                    assert old['flags']==new['flags']==flags(rep,shuf) and old['state']==new['state']==3
                    assert old['flag_writes']==new['flag_writes']
                    assert new['shared_byte_reads']==8
                    traces.append(dict(name='complete initializer parity, all valid settings',delta=delta,repeat=rep,shuffle=shuf,initial=idx))
        for rep,shuf in ((4,0),(0xffffffff,1),(3,0xffffffff),(2,2)):
            old=Menu(a,old_ar,delta,rep,shuf).run();new=Menu(b,ar,delta,rep,shuf).run()
            assert old['dialog_sha256']==new['dialog_sha256'] and old['state']==new['state']
            traces.append(dict(name='existing full DWORD predicates retained',delta=delta,repeat=rep,shuffle=shuf))
        for state in (0,1,3,0xffffffff):
            old=Menu(a,old_ar,delta,1,1,state=state).run();new=Menu(b,ar,delta,1,1,state=state).run()
            assert old['dialog_sha256']==new['dialog_sha256'] and old['state']==new['state']==state
            traces.append(dict(name='other completion states unchanged',delta=delta,state=state))
        for old_rep in range(4):
            for old_shuf in range(2):
                for new_rep in range(4):
                    for new_shuf in range(2):
                        for when in ('before wait','during copy','after snapshot','during UI'):
                            fixture=Menu(b,ar,delta,old_rep,old_shuf,initial=[9]*6,
                                publish=dict(when=when,values=(new_rep,new_shuf)))
                            outcome=fixture.run();expected=(new_rep,new_shuf) if when=='before wait' else (old_rep,old_shuf)
                            assert outcome['flags']==flags(*expected) and outcome['published']
                            assert outcome['shared_byte_reads']==8 and outcome['state']==3
                            traces.append(dict(name='one coherent pair during publication',delta=delta,old=[old_rep,old_shuf],new=[new_rep,new_shuf],when=when))
        for scenario,opts in (('create fails',dict(create=False)),('busy',dict(wait=0x102)),
                              ('wait fails',dict(wait=0xffffffff)),('NULL object',dict(null_obj=True)),('NULL mapping',dict(null_map=True))):
            fixture=Menu(b,ar,delta,3,1,initial=[1,0,1,0,1,0],**opts)
            outcome=fixture.run()
            assert outcome['flags']==fixture.initial and outcome['state']==2 and not outcome['shared_byte_reads'] and not outcome['flag_writes']
            if scenario.startswith('NULL'):assert not outcome['mutex_events']
            traces.append(dict(name='failure preserves choices and pending completion',delta=delta,scenario=scenario))
        fixture=Menu(b,ar,delta,3,1,initial=[1]*6,wait=0x80);outcome=fixture.run()
        assert outcome['flags']==flags(3,1) and outcome['state']==3
        traces.append(dict(name='abandoned mutex is owned and released',delta=delta))
        fixture=Menu(b,ar,delta,3,1,initial=[1]*6,wait=0x102);first=fixture.run()
        fixture.f.wait_result=0;second=fixture.run()
        assert first['flags']==[1]*6 and first['state']==2
        assert second['flags']==flags(3,1) and second['state']==3
        traces.append(dict(name='same initialized dialog recovers on next successful refresh',delta=delta))
        print('USB option initializer checks passed at '+hex(delta),flush=True)
    return dict(cases=len(traces),traces=traces,original_defect_cases=6,complete_initializer_interpreted=True,
        publication_mutex_and_UI_subfunctions_are_fixtures=True,native_executed=False,hardware_tested=False)

def structure(before,after,r):
    from verify_media_responsiveness import parsed
    restored=bytearray(after)
    for e in reversed(r['edits']):
        at=e['offset'];n=e['bytes'];assert restored[at:at+n]==bytes.fromhex(e['after_hex'])
        restored[at:at+n]=bytes.fromhex(e['before_hex'])
    assert bytes(restored)==before
    a,b=parsed(before),parsed(after)
    assert len(before)==len(after) and a.FILE_HEADER.__pack__()==b.FILE_HEADER.__pack__()
    assert [s.__pack__() for s in a.sections]==[s.__pack__() for s in b.sections]
    assert [(d.dll,[(s.address,s.ordinal,s.name) for s in d.imports]) for d in a.DIRECTORY_ENTRY_IMPORT]==[
        (d.dll,[(s.address,s.ordinal,s.name) for s in d.imports]) for d in b.DIRECTORY_ENTRY_IMPORT]
    aa,bb=bytearray(a.OPTIONAL_HEADER.__pack__()),bytearray(b.OPTIONAL_HEADER.__pack__())
    # Only the two metadata directory sizes change in the optional header.
    origin=a.OPTIONAL_HEADER.get_file_offset()
    for index in (3,5):
        ad,bd=a.OPTIONAL_HEADER.DATA_DIRECTORY[index],b.OPTIONAL_HEADER.DATA_DIRECTORY[index]
        assert ad.VirtualAddress==bd.VirtualAddress
        off=ad.get_file_offset()+4-origin;bb[off:off+4]=aa[off:off+4]
    assert aa==bb
    d=a.OPTIONAL_HEADER.DATA_DIRECTORY[3];e=b.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows=list(struct.iter_unpack('<5I',a.get_data(d.VirtualAddress,d.Size)))
    assert list(struct.iter_unpack('<5I',b.get_data(e.VirtualAddress,e.Size)))==rows+[tuple(r['helper_row'])]
    assert next(row for row in rows if row[0]==0x4f754)==(0x4f754,0x4f954,0,0,0x4f76c)
    original=set(reloc_records(a));current=set(reloc_records(b))
    keep=lambda row:not r['hook']-0x10000<=row[0]<r['hook_end']-0x10000
    assert current=={row for row in original if keep(row)}|{tuple(row) for row in r['relocations_added']}
    assert a.get_data(0x151900-0x10000,4)==b.get_data(0x151900-0x10000,4)==struct.pack('<I',0x4f754)
    for delta in (0,0x10000,0x120000,0x500000):
        p=parsed(after if not delta else relocated(after,delta));directory=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        rr=list(struct.iter_unpack('<5I',p.get_data(directory.VirtualAddress,directory.Size)))
        assert all(x[1]<=y[0] for x,y in zip(rr,rr[1:]))
        assert tuple(v+delta if v else 0 for v in r['helper_row']) in rr
    return dict(cases=1,exact_edit_reversal=True,original_entry_prolog_epilogue_vtable_retained=True,
        original_exception_rows_and_other_relocations_retained=True,sections_imports_entry_unchanged=True,
        new_helper_exception_row_and_relocations_checked=True)
