"""Execute installed text, retry, shutdown and retained artwork paths.

Only fixture accesses alias symbolic state to the RW bank. Native instruction
access to the old text state, and writes to RX/RO sections, fail closed.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import pefile
import patch_bt_text_recovery_install as install
import bt_text_metadata_retry as retry
import bt_cover_art_selection as selection
import verify_bt_text_metadata_retry as retry_proof
import verify_bt_text_metadata_shutdown as shutdown_proof
from verify_media_responsiveness import call
import layout_bt_cover_native as layout
import bt_text_metadata_owner as owner
import bt_text_metadata_receive as receive
from verify_bt_text_metadata_retry import Retrying
from verify_bt_text_metadata_receive import AVRCP,PREVIOUS,attribute,reply
from verify_bt_cover_install import CandidateImage,Installed,Blue,App,World
import bt_cover_art_publisher as publisher
import bt_cover_art_worker as worker
from verify_bt_cover_task import SCHED
from inspect_bt_pairing import data

ROOT=Path(__file__).resolve().parents[1]


class Text(Installed,Retrying):
    def __init__(self,raw,candidate):
        super().__init__(raw)
        self.maps=layout.STATE['Blue.exe']+install.STATE
        self.installed_module='Blue.exe';self.native_memory=False
        self.candidate=pefile.PE(data=candidate)
        bank=bytearray(self.candidate.get_data(layout.DATA_BASE-0x10000,layout.DATA_SIZE))
        for old,n,new,_ in self.maps:
            bounds=range(-4,n+4) if (old,n,new,_) in install.STATE else range(n)
            for i in bounds:
                if old+i in self.mem:bank[new-layout.DATA_BASE+i]=self.mem[old+i]
        self.allowed.append((layout.DATA_BASE,layout.DATA_BASE+layout.DATA_SIZE))
        for i,b in enumerate(bank):self.mem[layout.DATA_BASE+i]=b
        self.pe=CandidateImage(pefile.PE(data=raw),self.candidate,[])
        p=layout.plan('Blue.exe',raw);rows=p['helpers']+install.helpers()
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in rows]
        self.patches.clear()
        # Native dispatch reads the table's bytes from memory, unlike instruction
        # fetch. Populate the installed pointer rather than a fixture substitute.
        for at in (receive.PROFILE_TABLE,selection.REQUEST_TABLE):
            for i,b in enumerate(self.candidate.get_data(at-0x10000,4)):self.mem[at+i]=b
        self.installed_reads=self.installed_writes=0
        for at,fn in list(self.hooks.items()):self.hooks[at]=self.fixture_api(fn)
        self.alias_enabled=True

    def inverse(self,value):
        for old,n,new,_ in self.maps:
            if new<=value<=new+n:return old+value-new
        return value

    def access(self,at,write=False):
        if not getattr(self,'alias_enabled',False):return at
        if self.native_memory:
            assert not any(old<=at<old+n for old,n,_,_ in self.maps),('Native old-state access',hex(at))
            if write:
                s=self.candidate.get_section_by_rva(at-0x10000)
                assert s is None or s.Characteristics&0x80000000,('Native write to RX/RO',hex(at))
                self.installed_writes+=1
            else:self.installed_reads+=1
            return at
        # Include text allocation guards in fixture aliasing. This detects a
        # native overrun against the new bank rather than an untouched old copy.
        for old,n,new,_ in install.STATE:
            if old-4<=at<old+n+4:return new+at-old
        return install.mapped(at)


class ArtworkBlue(Blue):
    def __init__(self,original,candidate,world):
        super().__init__(original,candidate,world)
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in install.helpers()]


def inspect(raw,candidate):
    expected,recipe=install.patch(raw);assert candidate==expected
    p=pefile.PE(data=candidate);base,_=install.cover.patch('Blue.exe',raw);base=pefile.PE(data=base)
    assert p.OPTIONAL_HEADER.CheckSum==p.generate_checksum()
    assert p.get_overlay_data_start_offset() is None
    for a,b in zip(base.sections[:-3],p.sections[:-3]):assert a.__pack__()==b.__pack__()
    allowed=set()
    for row in recipe['hooks']:
        off=base.get_offset_from_rva(row['address']-0x10000);allowed.update(range(off,off+4))
    for section in base.sections[:-3]:
        for off in range(section.PointerToRawData,section.PointerToRawData+section.SizeOfRawData):
            assert base.__data__[off]==candidate[off] or off in allowed
    imports=lambda q:[(d.dll,i.name,i.ordinal,i.address) for d in q.DIRECTORY_ENTRY_IMPORT for i in d.imports]
    assert imports(base)==imports(p)
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    functions=list(struct.iter_unpack('<5I',p.get_data(d.VirtualAddress,d.Size)))
    rows=layout.plan('Blue.exe',raw)['helpers']+install.helpers()
    for row in rows:
        assert p.get_data(row['address']-0x10000,len(row['raw']))==row['raw']
        assert (row['address'],row['address']+row['recipe']['used_bytes'],0,0,layout.prolog_end(row)) in functions
    assert all(a[1]<=b[0] for a,b in zip(functions,functions[1:]))
    return dict(candidate_sha256=hashlib.sha256(candidate).hexdigest(),helpers=len(rows),
                new_helpers=27,function_rows=len(functions),state_remaps=install.STATE,
                retained_artwork_bytes_equal=True,imports_equal=True,checksum=p.OPTIONAL_HEADER.CheckSum)


def verify(raw,candidate,app_raw=None,app_candidate=None):
    inspection=inspect(raw,candidate);traces=[];body=attribute(1,b'Fresh title')+attribute(2,b'Artist')+attribute(3,b'Album')
    def record(name,m):
        row=dict(case=name,fields=m.fields(),publications=len(m.publications),
                 native_reads=m.installed_reads,native_writes=m.installed_writes)
        m.conclude();row['steps']=m.steps;traces.append(row)
    for split in (None,0,1,7,8,19,len(body)):
        m=Text(raw,candidate);parent=m.ordinary(bytes(8))
        if split is None:
            row=m.respond(parent,reply(body=body,count=3))
        else:
            row=m.respond(parent,reply(1,body=body[:split],count=3));assert not m.deliver(row);m.profile()
            row=m.respond(parent,reply(3,body=body[split:],count=3))
        assert m.deliver(row)==1 and m.fields()==['Fresh title','Album','Artist']
        assert not m.pending and not m.nodes();record('installed_text_split_'+str(split),m)
    m=Text(raw,candidate);parent=m.ordinary(bytes(8))
    row=m.respond(parent,reply(1,body=body[:7],count=3));assert not m.deliver(row);m.profile()
    m.due(1800,1800000);assert not m.deliver_final()
    assert data(m,AVRCP+0xee,260)==PREVIOUS and not m.pending
    assert len(m.nodes())==1 and m.nodes()[0]['callback']==retry.WAKE
    record('installed_native_timeout_preserves_text_and_drains',m)
    m=Text(raw,candidate);parent=m.ordinary(bytes(8))
    row=m.respond(parent,reply(1,body=body[:7],count=3));assert not m.deliver(row)
    m.begin_disconnect();m.profile();assert not m.continuations
    m.due(1800,1800000);assert not m.deliver_final()
    assert data(m,AVRCP+0xee,260)==PREVIOUS;record('installed_disconnect_refuses_queued_ACK_and_final',m)
    artwork=[]
    if app_raw is not None:
        assert app_candidate is not None
        expected,_=install.cover.patch('AppMain.exe',app_raw);assert app_candidate==expected
        bo,ao=pefile.PE(data=raw),pefile.PE(data=app_raw)
        for mode in ('normal','lost_wakeup','source_stop','disconnect','heartbeat_expired','window_stop'):
            w=World();b=ArtworkBlue(bo,candidate,w);a=App(ao,app_candidate,w)
            b.start();assert a.start()==1
            if mode=='lost_wakeup':b.fail_post=True
            b.receive_image();assert b.read(publisher.PENDING)
            if mode=='lost_wakeup':b.tick_gui(500);a.now=500
            else:b.deliver_window()
            if mode=='window_stop':a.stop_inside_draw=True
            assert a.run_worker()==0
            if mode=='window_stop':
                assert not a.field(12) and not a.bitmaps and a.reap()==1
            else:
                assert a.window(worker.MESSAGE)==0 and a.field(20)
                assert a.screen.getpixel((88,180))!=(8,12,14)
                if mode=='source_stop':b.command(0x1070505);b.handle()
                elif mode=='disconnect':b.disconnect_native();b.handle()
                elif mode=='heartbeat_expired':a.now=5101
                if mode in ('source_stop','disconnect','heartbeat_expired'):
                    assert a.window(15)==0x12345678 and not a.field(20) and not a.bitmaps
                    assert a.screen.getpixel((88,180))==(8,12,14)
            assert b.body_reads_on_owner==b.body_writes_on_owner==0
            a.finish();b.stop();b.deliver_window()
            assert not w.handles and not w.views and w.shared is None
            artwork.append(dict(case=mode,blue_native_reads=b.installed_reads,
                                app_native_reads=a.installed_reads,decode_count=a.decode_count,steps=b.steps+a.steps))
    retries=retry_proof.verify(raw,lambda original:Text(original,candidate))
    shutdown=shutdown_proof.verify(raw,lambda original:Text(original,candidate))
    names=('patch_bt_text_recovery_install.py','verify_bt_text_recovery_install.py',
           'bt_text_metadata_retry.py','verify_bt_text_metadata_retry.py',
           'bt_text_metadata_shutdown.py','verify_bt_text_metadata_shutdown.py','verify_bt_text_metadata_timeout.py',
           'bt_text_metadata_stream.py','bt_text_metadata_owner.py','bt_text_metadata_receive.py','bt_text_metadata_disconnect.py')
    return dict(cases=len(traces)+len(artwork)+retries['cases']+shutdown['cases'],
                text_traces=traces,artwork_traces=artwork,retry_traces=retries['traces'],
                shutdown_traces=shutdown['traces'],inspection=inspection,
                app_candidate_sha256=hashlib.sha256(app_candidate).hexdigest() if app_candidate is not None else None,
                hardware_tested=False,lgu_built=False,
                limits=['Text and timeout/disconnect instruction fetch comes directly from the inspected candidate PE',
                        'Clock, allocation, wire, CID/peer lookup, application publication and selected manager state remain fixtures',
                        'Artwork cases use actual Blue/AppMain helper bytes with CE threads, COM/GDI and screen pixels as fixtures',
                        'Native retry and quiescent shutdown execute; CE loader/device testing and LGU packaging remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('input','candidate','report'):p.add_argument('--'+name,type=Path,required=True)
    p.add_argument('--app',type=Path);p.add_argument('--app-candidate',type=Path)
    a=p.parse_args()
    if bool(a.app)!=bool(a.app_candidate):p.error('Supply both AppMain arguments')
    if a.report.exists():raise FileExistsError('Use fresh report')
    r=verify(a.input.read_bytes(),a.candidate.read_bytes(),a.app.read_bytes() if a.app else None,
             a.app_candidate.read_bytes() if a.app_candidate else None);a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode());print(json.dumps(dict(cases=r['cases'],inspection=r['inspection']),indent=2))
