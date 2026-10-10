"""Actual constructor, mapping initializer and CRT table traversal, with CE fixtures."""
import hashlib
import struct
from pathlib import Path
from verify_media_responsiveness import VM, parsed, call, STACK
from verify_shared_mapping_checks import Initializer, OBJ, MAPS, CREATE, CLOSE, ERROR
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put, data
from patch_startup_failure import BASE_SHA, CHECK, FAIL, TEXT, SIZE
from patch_shared_mapping_checks import reloc_records

ROOT=Path(__file__).resolve().parents[1]


class Terminated(Exception): pass


class Startup(Initializer):
    def __init__(self,raw,fail=None,delta=0,alloc=True,cached=False,cleanup_fault=None,terminate_failures=0):
        super().__init__(raw,fail,delta)
        self.delta=delta;self.alloc=alloc;self.cached=cached
        self.cleanup_fault=cleanup_fault;self.terminate_failures=terminate_failures
        self.m.ranges=[(0x13234+delta,0x13d28+delta),(0x140fb8+delta,0x1411e8+delta),
                       (0x1407f8+delta,0x140854+delta),(0x140724+delta,0x1407b8+delta),
                       (0x140b18+delta,0x140b54+delta),(0x140ac4+delta,0x140b18+delta),
                       (CHECK+delta,FAIL+delta),(FAIL+delta,TEXT+SIZE+delta)]
        self.views_live=set();self.registry=[];self.table_calls=[]
        self.free_count=0;self.terminations=0;self.sleeps=[];self.gui_calls=[]
        self.freed=False;self.freed_object=None
        m=self.m
        put(m,OBJ,bytes([0xa5])*0x138)
        m.write(0x186308+delta,OBJ if cached else 0)
        m.write(0x186ce8+delta,0)
        self.initial_object=data(m,OBJ,0x138)
        m.hooks.update({0x1402f0+delta:self.allocate,0x1402e0+delta:self.free,
            0x13ff28+delta:self.unmap,0x137a68+delta:self.registry_number,
            0x137b80+delta:self.registry_bytes,0x140108+delta:self.terminate,
            0x134948+delta:self.gui,0x140a58+delta:self.normal_exit,
            0x140a78+delta:self.normal_exit,0x140864+delta:lambda v:0,
            0x18503c+delta:self.sleep})
        # Sleep is an imported indirect call, not an image-code address.
        m.write(0x18503c+delta,0xf0300000);m.hooks[0xf0300000]=self.sleep
        self.table=[int.from_bytes(m.pe.get_data(va-0x10000,4),'little')
                    for va in range(0x143000,0x1430f8,4)]
        assert self.table[2]==0x140fb8+delta
        for target in self.table:
            if target and target!=0x140fb8+delta:
                m.hooks[target]=lambda v,target=target:self.other_constructor(v,target)

    def allocate(self,m):
        assert m.reg[4]==0x138
        self.events.append(dict(kind='allocate',success=self.alloc));self.clobber()
        return OBJ if self.alloc else 0

    def warning(self,m):
        if self.alloc:return super().warning(m)
        assert m.reg[4]==m.reg[7]==0 and m.text(m.reg[6])=='MediaNav startup'
        assert m.text(m.reg[5])=='MediaNav could not start: not enough memory. Restart the unit.'
        self.events.append(dict(kind='warning',text=m.text(m.reg[5])))
        self.clobber();return 1

    def map_view(self,m):
        result=super().map_view(m)
        if result:self.views_live.add(result)
        return result

    def close(self,m):
        handle=m.reg[4];assert handle in self.live
        index=(handle-0x1000)//4
        failed=self.cleanup_fault==('close',index)
        if not failed:self.live.remove(handle)
        self.events.append(dict(kind='close',handle=handle,result=int(not failed)))
        self.clobber();return int(not failed)

    def unmap(self,m):
        ptr=m.reg[4];assert ptr in self.views_live
        index=(ptr-0x43000000)//0x200000
        failed=self.cleanup_fault==('unmap',index)
        if not failed:self.views_live.remove(ptr)
        self.events.append(dict(kind='unmap',pointer=ptr,result=int(not failed)))
        self.clobber();return int(not failed)

    def free(self,m):
        assert m.reg[4]==OBJ and not self.freed
        self.freed_object=data(m,OBJ,0x138);self.freed=True;self.free_count+=1
        self.events.append(dict(kind='free',object=OBJ));self.clobber();return 0

    def registry_number(self,m):
        assert m.reg[4]==0x80000002 and m.text(m.reg[5])=='LGE\\SystemInfo' and m.reg[7]==0
        name=m.text(m.reg[6]);assert name in ('UI_TYPE','BOOT_LOGO')
        self.registry.append(name);self.clobber();return 4 if name=='UI_TYPE' else 2

    def registry_bytes(self,m):
        name=m.text(m.reg[4]);assert name in ('UUID','VIN_INFO')
        count=m.reg[6];assert count==(15 if name=='UUID' else 17)
        put(m,m.reg[5],bytes([0x31])*count)
        self.registry.append(name);self.clobber();return 1

    def other_constructor(self,m,target):
        self.table_calls.append(target-self.delta);self.clobber();return 0

    def gui(self,m):
        assert m.reg[4:8]==[0x8888,0x9999,0x42000000,3]
        self.gui_calls.append(1);self.clobber();return 12

    def normal_exit(self,m):
        assert m.reg[4]==12;self.clobber();return 0

    def terminate(self,m):
        assert m.reg[4:6]==[0x42,1]
        assert m.read(0x186308+self.delta)==m.read(0x186ce8+self.delta)==0
        self.terminations+=1
        self.events.append(dict(kind='terminate',attempt=self.terminations))
        if self.terminations<=self.terminate_failures:self.clobber();return 0
        raise Terminated()

    def sleep(self,m):
        assert m.reg[4]==1000
        self.sleeps.append(1000);self.clobber();return 0

    def run(self,ctor_only=False):
        terminated=False
        try:call(self.m,(0x140fb8 if ctor_only else 0x1407f8)+self.delta,
                 [] if ctor_only else [0x8888,0x9999,0x42000000,3],limit=40000)
        except Terminated:terminated=True
        assert self.m.read(OBJ-4)==self.m.read(OBJ+0x138)==0xa55aa55a
        return dict(terminated=terminated,events=self.events,registry=self.registry,
            subsequent_constructors=len(self.table_calls)-(0 if ctor_only else 1),
            gui_calls=len(self.gui_calls),free_count=self.free_count,
            live_handles=sorted(self.live),live_views=sorted(self.views_live),
            published=self.m.read(0x186ce8+self.delta),cached=self.m.read(0x186308+self.delta),
            terminations=self.terminations,sleeps=self.sleeps,
            object_hex=data(self.m,OBJ,0x138).hex(),instructions=self.m.steps)


def verify(original,candidate):
    assert hashlib.sha256(original).hexdigest()==BASE_SHA
    traces=[]
    for failure,alloc in ((('view',4),True),(('view',11),True),(None,False)):
        old=Startup(original,failure,alloc=alloc).run(ctor_only=True)
        assert not old['terminated'] and old['published']==(OBJ if alloc else 0)
        if alloc:assert len(old['registry'])==4
        traces.append(dict(name='original constructor ignores failure',old=old))
    for delta in (0,0x10000,0x120000,0x500000):
        image=candidate if not delta else relocated(candidate,delta)
        # Baseline healthy/cached constructor results and normal CRT flow are unchanged.
        for cached in (False,True):
            old=Startup(original,cached=cached).run()
            new=Startup(image,delta=delta,cached=cached).run()
            if not cached:
                obj=bytearray.fromhex(old['object_hex'])
                assert int.from_bytes(obj[:4],'little')==0x14db08
                obj[:4]=(0x14db08+delta).to_bytes(4,'little')
                old['object_hex']=obj.hex()
            assert {k:v for k,v in old.items() if k!='instructions'}=={k:v for k,v in new.items() if k!='instructions'}
            assert not new['terminated'] and new['gui_calls']==1 and new['published']==OBJ
            traces.append(dict(name='healthy/cached startup parity',delta=hex(delta),cached=cached,result=new))
        for kind in ('create','view'):
            for index in range(14):
                s=Startup(image,(kind,index),delta=delta);new=s.run()
                assert new['terminated'] and not new['registry'] and not new['published'] and not new['cached']
                assert new['subsequent_constructors']==new['gui_calls']==0
                assert new['free_count']==1 and not new['live_handles'] and not new['live_views']
                assert new['terminations']==1 and not new['sleeps']
                assert len([e for e in new['events'] if e['kind']=='warning'])==1
                assert not any(s.freed_object[at:at+8]!=bytes(8) for at in range(0xa0,0x110,8))
                traces.append(dict(name='partial mapping failure stops CRT',delta=hex(delta),kind=kind,index=index,result=new))
        s=Startup(image,delta=delta,alloc=False);new=s.run()
        assert new['terminated'] and new['free_count']==0 and new['subsequent_constructors']==new['gui_calls']==0
        assert not new['registry'] and not new['live_handles'] and not new['live_views']
        assert len([e for e in new['events'] if e['kind']=='warning'])==1
        traces.append(dict(name='allocation failure stops CRT',delta=hex(delta),result=new))
        s=Startup(image,('view',4),delta=delta,terminate_failures=3);new=s.run()
        assert new['terminated'] and new['terminations']==4 and new['sleeps']==[1000]*3
        assert new['free_count']==1 and not new['registry'] and new['subsequent_constructors']==0
        traces.append(dict(name='unexpected termination return never resumes startup',delta=hex(delta),result=new))
    # Cleanup failures retain resources for process teardown, never resume app startup.
    for kind in ('unmap','close'):
        for index in range(13):
            s=Startup(candidate,('view',13),cleanup_fault=(kind,index));new=s.run()
            assert new['terminated'] and new['free_count']==1 and new['gui_calls']==0 and not new['registry']
            remaining=new['live_views'] if kind=='unmap' else new['live_handles']
            assert len(remaining)==1
            assert len(new['live_handles'])==int(kind=='close') and len(new['live_views'])==int(kind=='unmap')
            traces.append(dict(name='cleanup failure proceeds only to process teardown',kind=kind,index=index,result=new))
    return dict(cases=len(traces),traces=traces,actual_constructor_initializer_crt_loop_entry_executed=True,
        remaining_59_static_initializers_are_hooks=True,gui_and_os_calls_are_fixtures=True,
        hardware_tested=False,native_process_teardown_tested=False)


def structure(original,candidate,recipe):
    a,b=parsed(original),parsed(candidate)
    restored=bytearray(candidate[:len(original)])
    for e in reversed(recipe['edits']):
        at=int(e['offset'],16);n=e['bytes'];assert candidate[at:at+n].hex()==e['after_hex']
        restored[at:at+n]=bytes.fromhex(e['before_hex'])
    assert bytes(restored)==original
    assert len(b.sections)==len(a.sections)+1 and b.sections[-1].Name.rstrip(b'\0')==b'.mxboot'
    assert b.sections[-1].Characteristics==0x60000020
    assert b.OPTIONAL_HEADER.AddressOfEntryPoint==a.OPTIONAL_HEADER.AddressOfEntryPoint
    assert a.sections[1].get_data()==b.sections[1].get_data() and a.sections[2].get_data()==b.sections[2].get_data()
    assert all(x.__pack__()==y.__pack__() for x,y in zip(a.sections,b.sections))
    for idx in (1,2,12):assert a.OPTIONAL_HEADER.DATA_DIRECTORY[idx].__pack__()==b.OPTIONAL_HEADER.DATA_DIRECTORY[idx].__pack__()
    old=reloc_records(a);new=reloc_records(b)
    assert all(r in new for r in old if not (0x14111c-0x10000<=r[0]<0x141120-0x10000 or
                                           0x1411b0-0x10000<=r[0]<0x1411c4-0x10000))
    for delta in (0,0x10000,0x120000,0x500000):
        moved=parsed(candidate if not delta else relocated(candidate,delta))
        d=moved.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        rows=[struct.unpack_from('<5I',moved.get_data(d.VirtualAddress,d.Size),i) for i in range(0,d.Size,20)]
        assert all(x[1]<=y[0] for x,y in zip(rows,rows[1:]))
        for row in recipe['added_pdata_rows']:
            expected=tuple(v+delta if v else 0 for v in row);assert expected in rows
        oldd=a.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        before=[struct.unpack_from('<5I',a.get_data(oldd.VirtualAddress,oldd.Size),i) for i in range(0,oldd.Size,20)]
        assert rows[:len(before)]==[tuple(v+delta if v else 0 for v in row) for row in before]
    return dict(cases=1,full_recipe_reversible=True,only_two_original_code_spans_changed=True,
        existing_imports_resources_data_exception_rows_preserved=True,new_helper_exception_rows_rebased=True,
        old_relocations_outside_hooks_preserved=True,new_section_read_execute_only=True)
