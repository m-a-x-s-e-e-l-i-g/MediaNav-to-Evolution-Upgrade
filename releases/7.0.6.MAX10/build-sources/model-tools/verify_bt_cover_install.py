"""Inspect candidate PE metadata and execute its installed artwork bytes.

Legacy fixture setup still uses symbolic original state addresses; only fixture
accesses alias those to the new bank. Native accesses to old state or writes to
read-only image sections fail. CE/wire/COM/GDI remain explicit fixtures.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

import pefile

import layout_bt_cover_native as layout
import patch_bt_cover_install as install
import bt_cover_art_publisher as publisher
import bt_cover_art_worker as worker
import bt_cover_art_app_lifetime as life
import bt_cover_art_app_paint as paint
import bt_cover_art_transfer as transfer
from inspect_bt_pairing import data,put
from verify_bt_cover_publisher import Publisher
from verify_bt_cover_app_lifetime import LifetimeApp,WORKER_STACK
from verify_bt_cover_transfer import World
from verify_bt_cover_metadata import reply
from patch_shared_mapping_checks import reloc_records

ROOT=Path(__file__).resolve().parents[1]


class CandidateImage:
    def __init__(self,original,candidate,helpers):
        self.original=original;self.candidate=candidate;self.helpers=helpers
        self.OPTIONAL_HEADER=candidate.OPTIONAL_HEADER
    def get_data(self,rva,n):return self.candidate.get_data(rva,n)


class Installed:
    def enable_candidate(self,module,original,candidate):
        self.installed_module=module;self.native_memory=False
        p=layout.plan(module,original.__data__)
        bank=bytearray(p['data'])
        for old,n,new,_ in layout.STATE[module]:
            for i in range(n):
                if old+i in self.mem:bank[new-layout.DATA_BASE+i]=self.mem[old+i]
        self.allowed.append((layout.DATA_BASE,layout.DATA_BASE+layout.DATA_SIZE))
        for i,b in enumerate(bank):self.mem[layout.DATA_BASE+i]=b
        self.candidate=pefile.PE(data=candidate)
        self.pe=CandidateImage(original,self.candidate,p['helpers'])
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in p['helpers']]
        self.patches.clear()
        # Populate native dispatch tables from the candidate, not constructor
        # substitutions. Instruction reads come directly from CandidateImage.
        for row in install.bindings(module,original.__data__):
            at=row['address']
            if self.permitted(at,4):
                raw=self.candidate.get_data(at-layout.IMAGE_BASE,4)
                for i,b in enumerate(raw):self.mem[at+i]=b
        self.installed_reads=0;self.installed_writes=0
        # Fixture APIs retain symbolic assertions; native instructions always
        # see the new pointer values. Restore raw argument registers afterward.
        for at,fn in list(self.hooks.items()):self.hooks[at]=self.fixture_api(fn)
        self.alias_enabled=True

    def inverse(self,value):
        for old,n,new,_ in layout.STATE[self.installed_module]:
            if new<=value<=new+n:return old+value-new
        return value

    def fixture_api(self,fn):
        def wrapped(m):
            saved=m.reg[4:8][:]
            m.reg[4:8]=[self.inverse(v) for v in saved]
            try:return fn(m)
            finally:m.reg[4:8]=saved
        return wrapped

    def plain(self,word):
        if not getattr(self,'alias_enabled',False):return super().plain(word)
        self.native_memory=True
        try:return super().plain(word)
        finally:self.native_memory=False

    def access(self,at,write=False):
        if not getattr(self,'alias_enabled',False):return at
        if self.native_memory:
            assert not any(old<=at<old+n for old,n,_,_ in layout.STATE[self.installed_module]),('Native old-state access',hex(at))
            if write:
                s=self.candidate.get_section_by_rva(at-layout.IMAGE_BASE)
                assert s is None or s.Characteristics&0x80000000,('Native write to read-only image',hex(at))
                self.installed_writes+=1
            else:self.installed_reads+=1
            return at
        return layout.mapped(self.installed_module,at)

    def read(self,at,size=4):return super().read(self.access(at),size)
    def write(self,at,value,size=4):return super().write(self.access(at,True),value,size)

    def run_helper(self,name,args=None,extra=()):
        args=[layout.mapped(self.installed_module,self.config.state)] if args is None else list(args)
        args[0]=layout.mapped(self.installed_module,args[0])
        return super().run_helper(name,args,extra)


class Blue(Installed,Publisher):
    def __init__(self,original,candidate,w):
        super().__init__(original,w);self.enable_candidate('Blue.exe',original,candidate)


class App(Installed,LifetimeApp):
    def __init__(self,original,candidate,w):
        super().__init__(w,original);self.enable_candidate('AppMain.exe',original,candidate)

    def run_worker(self):
        assert self.thread_handle and not self.thread_suspended and not self.thread_completed
        result=self.native_role(worker.THREAD,[layout.mapped('AppMain.exe',worker.STATE)],'worker',WORKER_STACK)
        assert not self.buffer_live and not self.com_count
        self.thread_completed=True;self.worker_result=result
        self.lifetime_trace.append(('worker_exited',result));return result


def inspect(module,original,candidate):
    expected,recipe=install.patch(module,original)
    assert candidate==expected,'Candidate differs from deterministic constructor'
    old,new=pefile.PE(data=original),pefile.PE(data=candidate)
    assert new.OPTIONAL_HEADER.CheckSum==new.generate_checksum()
    assert new.FILE_HEADER.Machine==old.FILE_HEADER.Machine==0x166
    assert new.OPTIONAL_HEADER.Subsystem==old.OPTIONAL_HEADER.Subsystem
    for a,b in zip(old.sections,new.sections):assert a.__pack__()==b.__pack__()
    assert new.get_overlay_data_start_offset() is None
    sections=new.sections[-3:]
    assert [s.Characteristics for s in sections]==[0x60000020,0xc0000040,0x40000040]
    assert all(not(s.Characteristics&0x20000000 and s.Characteristics&0x80000000) for s in sections)
    assert all(s.PointerToRawData%new.OPTIONAL_HEADER.FileAlignment==0 and s.VirtualAddress%4096==0 for s in sections)
    assert all(a.VirtualAddress+max(a.Misc_VirtualSize,a.SizeOfRawData)<=b.VirtualAddress for a,b in zip(new.sections,new.sections[1:]))
    d=new.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    functions=list(struct.iter_unpack('<5I',new.get_data(d.VirtualAddress,d.Size)))
    assert len(functions)==recipe['retained_function_rows']+recipe['added_function_rows']
    assert all(a[1]<=b[0] for a,b in zip(functions,functions[1:]))
    p=layout.plan(module,original)
    for r in p['helpers']:
        assert new.get_data(r['address']-layout.IMAGE_BASE,len(r['raw']))==r['raw']
        assert (r['address'],r['address']+r['recipe']['used_bytes'],0,0,layout.prolog_end(r)) in functions
    imports=lambda p:[(d.dll,i.name,i.ordinal,i.address) for d in p.DIRECTORY_ENTRY_IMPORT for i in d.imports]
    assert imports(old)==imports(new)
    # Original resources and every retained section byte outside guarded fixes
    # and native bindings stay exact. Header/metadata additions are separate.
    feedback=recipe['feedback'];allowed=set()
    for component in feedback['components']:
        # Component recipes describe guarded instructions; derive the exact set
        # independently by running each original-input repair.
        fn={'metadata-final-status':install.metadata,'metadata-interim-progress':install.interim,'metadata-uid-width':install.uid_width,'pcm-burst-reserve':install.bursts,
            'attribute-8':install.attribute,'active-labels':install.labels,'aha-gate':install.aha}[component['component']]
        changed,_=fn(original)
        allowed.update(i for i,(a,b) in enumerate(zip(original,changed)) if a!=b)
    for hook in recipe['hooks']:
        off=old.get_offset_from_rva(hook['address']-layout.IMAGE_BASE);allowed.update(range(off,off+4))
    retained=0
    for s in old.sections:
        for off in range(s.PointerToRawData,s.PointerToRawData+s.SizeOfRawData):
            if original[off]!=candidate[off]:assert off in allowed,(module,'Unapproved retained byte',hex(off))
            else:retained+=1
        if s.Name.rstrip(b'\0')==b'.rsrc':assert s.get_data()==new.get_data(s.VirtualAddress,s.SizeOfRawData)
    if module=='AppMain.exe':
        rel=reloc_records(new)
        assert (0x3c81c-layout.IMAGE_BASE,4,life.WND&65535) in rel
        high,low=struct.unpack('<II',new.get_data(0x3c81c-layout.IMAGE_BASE,4)+new.get_data(0x3c824-layout.IMAGE_BASE,4))
        signed=(low&65535) if low&65535<32768 else (low&65535)-65536
        assert ((high&65535)<<16)+signed==life.WND
    else:
        # The separate 96-case interim proof must apply to the whole installed
        # function, not only its five edited words.
        fixed,_=install.interim(original)
        assert new.get_data(0x1fce8-layout.IMAGE_BASE,0x258)==pefile.PE(data=fixed).get_data(0x1fce8-layout.IMAGE_BASE,0x258)
        # Bind the separately executed UID comparisons to complete installed
        # notification and final-handler functions, including their callees.
        fixed,_=install.compose(original,[('status',install.metadata),('uid-width',install.uid_width)])
        fixed=pefile.PE(data=fixed)
        for at,n in ((0x1fa44,0x2a4),(0x20028,0xdc),(0x1d3c4,0xb8)):
            assert new.get_data(at-layout.IMAGE_BASE,n)==fixed.get_data(at-layout.IMAGE_BASE,n)
    return dict(module=module,candidate_sha256=hashlib.sha256(candidate).hexdigest(),retained_equal_bytes=retained,
                added_helpers=len(p['helpers']),function_rows=len(functions),relocation_records=len(reloc_records(new)),
                checksum=new.OPTIONAL_HEADER.CheckSum,sections=recipe['sections'],hooks=recipe['hooks'])


def verify(blue_raw,app_raw,blue_candidate,app_candidate):
    inspections=[inspect(n,b,c) for n,b,c in [('Blue.exe',blue_raw,blue_candidate),('AppMain.exe',app_raw,app_candidate)]]
    bo,ao=pefile.PE(data=blue_raw),pefile.PE(data=app_raw);cases=[]
    # Use the complete PE directory, including the retained HIGHADJ records,
    # rather than applying the helper layout's relocation list in isolation.
    from verify_usb_input_safety import relocated
    from verify_bt_cover_layout import moved_words,operands
    original=pefile.PE(data=app_candidate);p=layout.plan('AppMain.exe',app_raw)
    d=original.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    original_functions=list(struct.iter_unpack('<5I',original.get_data(d.VirtualAddress,d.Size)))
    for delta in (0x1000,0x10000,0x123000):
        rebased=pefile.PE(data=relocated(app_candidate,delta));pointers=constants=0
        for row in p['helpers']:
            actual=rebased.get_data(row['address']-layout.IMAGE_BASE,len(row['raw']))
            assert actual==moved_words(row,delta),'PE directory failed helper rebase'
            rel={rva+layout.IMAGE_BASE for rva,_,_ in row['relocations']}
            for at,kind,expected,value in operands(row,actual):
                if at in rel:assert value==expected+delta;pointers+=1
                else:assert expected in layout.CONSTANTS and value==expected;constants+=1
        high=struct.unpack('<I',rebased.get_data(0x3c81c-layout.IMAGE_BASE,4))[0]
        low=struct.unpack('<I',rebased.get_data(0x3c824-layout.IMAGE_BASE,4))[0]&65535
        assert ((high&65535)<<16)+(low if low<32768 else low-65536)==life.WND+delta
        assert struct.unpack('<I',rebased.get_data(paint.VTABLE_SLOT-layout.IMAGE_BASE,4))[0]==paint.DRAW+delta
        moved_functions=list(struct.iter_unpack('<5I',rebased.get_data(d.VirtualAddress,d.Size)))
        assert moved_functions==[tuple(v+delta if v else 0 for v in row) for row in original_functions]
        cases.append(dict(case='actual_AppMain_PE_directory_rebases_helpers_hooks_and_all_function_rows',
                          delta=delta,pointers=pointers,constants=constants,function_rows=len(moved_functions)))
    def pair():
        w=World();b=Blue(bo,blue_candidate,w);a=App(ao,app_candidate,w)
        b.start();assert a.start()==1;return w,b,a
    def record(name,w,b,a):
        cases.append(dict(case=name,blue_native_reads=b.installed_reads,blue_native_writes=b.installed_writes,
                          app_native_reads=a.installed_reads,app_native_writes=a.installed_writes,
                          body_reads_on_owner=b.body_reads_on_owner,body_writes_on_owner=b.body_writes_on_owner,
                          app_decode_count=a.decode_count,app_window_copies=a.blit_count))
        assert b.body_reads_on_owner==b.body_writes_on_owner==0
        a.finish();b.stop();b.deliver_window()
        assert not w.handles and not w.views and w.shared is None

    w,b,a=pair();b.receive_image();assert b.read(publisher.PENDING)
    b.deliver_window();assert a.run_worker()==0 and a.field(16)
    assert a.window(worker.MESSAGE)==0 and a.field(20) and a.blit_count==1
    assert a.window(15)==0x12345678 and a.blit_count==2
    assert a.screen.getpixel((88,180))!=(8,12,14)
    record('installed_selection_channel_collection_mapping_worker_and_native_screen_copy',w,b,a)

    w,b,a=pair();b.fail_post=True;b.receive_image();b.tick_gui(500);a.now=500
    assert a.run_worker()==0 and a.window(0x113,0x4d42)==0 and a.field(20)
    record('installed_lost_Blue_wakeup_recovers_through_timer_and_AppMain',w,b,a)

    for mode in ('source_stop','disconnect','heartbeat_expired'):
        w,b,a=pair();b.receive_image();b.deliver_window();assert a.run_worker()==0
        assert a.window(worker.MESSAGE)==0 and a.field(20)
        if mode=='source_stop':b.command(0x1070505);b.handle()
        elif mode=='disconnect':b.disconnect_native();b.handle()
        else:a.now=5101
        assert a.window(15)==0x12345678 and not a.field(20) and not a.bitmaps
        assert a.screen.getpixel((88,180))==(8,12,14)
        record('installed_cached_cover_cleared_'+mode,w,b,a)

    w,b,a=pair();b.receive_image();b.deliver_window();a.stop_inside_draw=True
    assert a.run_worker()==0 and not a.field(12) and not a.bitmaps
    assert a.field(8) and a.reap()==1
    record('installed_window_shutdown_retains_borrowed_buffer_until_worker_exit',w,b,a)

    return dict(cases=len(cases),inspections=inspections,traces=cases,executable_written=True,lgu_built=False,
                hardware_tested=False,published=False,
                limits=['Instruction bytes come from the exact candidate PE files, not helper overlays or instruction patches',
                        'Fixture symbolic globals alias installed banks only outside native instruction memory accesses',
                        'Native old-state accesses and writes to read-only candidate sections are rejected',
                        'Wire peers, CE threads, COM/GDI, generic window dispatch and pixels remain fixtures',
                        'Actual CE loader and native exception dispatch, device display/audio and complete LGU packing/readback remain unverified'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in
                             ('patch_bt_cover_install.py','verify_bt_cover_install.py','layout_bt_cover_native.py',
                              'verify_bt_cover_publisher.py','verify_bt_cover_app_lifetime.py',
                              'patch_bt_metadata_interim.py','verify_bt_metadata_interim.py',
                              'patch_bt_metadata_uid_width.py','verify_bt_metadata_uid_width.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('blue','app','blue-candidate','app-candidate','report'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    report=verify(a.blue.read_bytes(),a.app.read_bytes(),a.blue_candidate.read_bytes(),a.app_candidate.read_bytes())
    a.report.parent.mkdir(parents=True,exist_ok=True);a.report.write_bytes((json.dumps(report,indent=2)+'\n').encode())
    print(json.dumps(dict(cases=report['cases'],executable_written=True,lgu_built=False),indent=2))
