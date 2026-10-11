"""Execute MAX07 polling, text receiver, retries, shutdown and native CM open.

Actual candidate instructions run in bounded interpreters. Phone responses,
A2DP activity, clocks, allocators and Windows CE remain explicit fixtures.
"""
import hashlib
import json
import struct
import inspect
from functools import lru_cache
from pathlib import Path
from types import FunctionType
import pefile
import max07_bt_helpers as h
import patch_max07_bluetooth as patcher
import layout_bt_cover_native as layout
import bt_cover_art_task as task
import bt_text_metadata_owner as owner
import bt_text_metadata_retry as retry
from verify_bt_text_recovery_install import Text as OriginalText
import verify_bt_text_metadata_receive as receive_proof
import verify_bt_text_metadata_shutdown as shutdown_proof
from verify_bt_text_metadata_receive import AVRCP, attribute, reply
from verify_bt_cover_metadata_ticket import PROFILE
from verify_bt_cover_install import Installed
from verify_bt_cover_task import TaskFixture
from verify_media_responsiveness import call
from inspect_bt_pairing import put, data
from verify_max07_audio import verify as verify_audio

ROOT=Path(__file__).resolve().parents[1]
ORIGINAL=ROOT/'build/maxmade-7.0.6.MAX05-local/payload/upgrade/Storage Card/System/Blue.exe'
# These plans contain immutable encoded bytes; each fixture copies the bank.
# Avoid reassembling the identical 90-helper placement for every wire split.
layout.plan=lru_cache(maxsize=4)(layout.plan)


class Text(OriginalText):
    def __init__(self, raw, candidate):
        super().__init__(raw,candidate)
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in h.assembled()]
        self.source_active=True;self.fail_poll=False
        self.hooks[0x274800]=lambda _:int(self.source_active)
        self.hooks[0x8ad7c]=self.fixture_api(self.poll_allocate)

    def poll_allocate(self,m):
        if self.fail_poll:return 0
        return self.allocate(m)

    def profile(self):
        self.enter_queue(12)
        while self.profile_requests:
            request=self.profile_requests.popleft();self.write(PROFILE+12,request)
            at=h.REQUEST if self.read(request,2)==0x20c else owner.ACK_PROFILE
            call(self,at,[PROFILE],limit=30000)
            self.reg[4]=request;self.free(self)

    def arm_poll(self,empty=True,registered=False):
        self.write(h.STATE,PROFILE);self.write(h.STATE+4,1)
        self.write(AVRCP+0x20c,int(registered),1)
        if empty:put(self,AVRCP+0xee,bytes(260))
        self.enter_queue(12)
        assert call(self,h.ARM,[]) and len(self.nodes())==1

    def cancel_poll(self):
        timer=self.read(h.STATE+8)
        if timer:
            self.enter_queue(12);call(self,0x85008,[timer,0,0])
        self.write(h.STATE+8,0);self.write(h.STATE+4,0)


class Channel(Installed,TaskFixture):
    def __init__(self,original,candidate):
        super().__init__(original)
        self.enable_candidate('Blue.exe',original,candidate)
        self.hooks[0x8ad7c]=self.fixture_api(self.allocate)

    def ready_open(self):
        # The installed publisher has a larger task initializer than the old
        # isolated transport fixture. OPEN only consumes the owner header.
        # Supply that validated header; full task startup/shutdown is exercised
        # in the separate installed cross-process artwork suite.
        self.state=self.new(bytes(task.SIZE))
        self.write(self.state+20,0x1001,2);self.write(self.state+22,22,2)
        self.write(self.state+24,2);self.write(task.QUEUE,22,2)


def inspection(before, candidate, recipe):
    p,q=pefile.PE(data=before),pefile.PE(data=candidate)
    allowed={}
    for edit in recipe['edits']:
        at=int(edit['address'],16);old=bytes.fromhex(edit['before_hex']);new=bytes.fromhex(edit['after_hex'])
        assert p.get_data(at-0x10000,len(old))==old
        assert q.get_data(at-0x10000,len(new))==new
        for i,(a,b) in enumerate(zip(old,new)):allowed[at+i]=b
    retained=0
    for s in p.sections:
        if s.Name.rstrip(b'\0')==b'.mxartm':continue # copied/sorted exception rows below
        a=p.get_data(s.VirtualAddress,s.Misc_VirtualSize)
        b=q.get_data(s.VirtualAddress,s.Misc_VirtualSize)
        assert len(a)==len(b)
        for i,(x,y) in enumerate(zip(a,b)):
            if x!=y:assert allowed.get(0x10000+s.VirtualAddress+i)==y
            else:retained+=1
    imports=lambda t:[(d.dll,i.name,i.ordinal,i.address) for d in t.DIRECTORY_ENTRY_IMPORT for i in d.imports]
    assert imports(p)==imports(q)
    def functions(t):
        d=t.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        return list(struct.iter_unpack('<5I',t.get_data(d.VirtualAddress,d.Size)))
    assert set(functions(p))<=set(functions(q))
    assert all(a[1]<=b[0] for a,b in zip(functions(q),functions(q)[1:]))
    assert q.OPTIONAL_HEADER.CheckSum==q.generate_checksum() and q.get_overlay_data_start_offset() is None
    assert all(not(s.Characteristics&0x20000000 and s.Characteristics&0x80000000) for s in q.sections)
    return dict(retained_equal_bytes=retained,original_function_rows_preserved=True,
                imports_preserved=True,edits=len(recipe['edits']),candidate_sha256=patcher.sha(candidate))


def verify():
    before=patcher.SOURCE.read_bytes();candidate,recipe=patcher.patch(before);raw=ORIGINAL.read_bytes()
    checks=inspection(before,candidate,recipe);traces=[]
    def record(name,m):
        traces.append(dict(case=name,fields=m.fields(),posts=len(m.ordinary_posts),
                           polls_queued=len(m.profile_requests),steps=m.steps))

    # CSR bindings preserve the native task arguments and return values; ARM
    # then uses the real timer implementation under that same owning queue.
    m=Text(raw,candidate);m.enter_queue(12);calls=[]
    def native_init(vm):
        assert vm.reg[4]==PROFILE
        vm.write(PROFILE,PROFILE);calls.append('init');return 0x12345678
    m.hooks[0x3b9b8]=native_init
    assert call(m,h.INIT,[PROFILE])==0x12345678
    assert m.read(h.STATE)==PROFILE and m.read(h.STATE+4)==1
    def native_profile(vm):
        assert vm.reg[4]==PROFILE;calls.append('profile');return 0xabcdef01
    m.hooks[0x3bcc0]=native_profile
    assert call(m,h.PROFILE,[PROFILE])==0xabcdef01 and calls==['init','profile']
    assert len(m.nodes())==1 and m.nodes()[0]['queue']==12
    m.cancel_poll();parent=m.ordinary(bytes(8))
    row=m.respond(parent,reply(body=attribute(1,b'Native task bindings retained')))
    assert m.deliver(row)==1
    record('native_CSR_init_handler_arguments_and_results_retained',m);m.conclude()

    for registered,empty in ((False,True),(True,True),(False,False)):
        m=Text(raw,candidate);m.arm_poll(empty,registered)
        original_art=data(m,layout.DATA_BASE,0x480)
        m.due(2099,2099999);assert not m.profile_requests
        m.due(2100,2100000);assert len(m.profile_requests)==1
        # A second callback cannot duplicate a still queued request.
        m.due(4100,4100000);assert len(m.profile_requests)==1
        m.profile();assert not m.read(h.STATE+16)
        parent=m.serialized[-1]['confirmation']
        row=m.respond(parent,reply(body=attribute(1,b'MAX07 Spotify title')+attribute(2,b'Artist'),count=2))
        assert m.deliver(row)==1 and m.fields()==['MAX07 Spotify title','','Artist']
        assert data(m,layout.DATA_BASE,0x480)==original_art,'Text polls restarted artwork state'
        # Healthy notification mode stops querying once a title is present.
        # Without notifications a subsequent poll updates a changed title.
        m.due(6100,6100000)
        assert len(m.profile_requests)==int(not registered)
        if not registered:
            m.profile();parent=m.serialized[-1]['confirmation']
            row=m.respond(parent,reply(body=attribute(1,b'Next track title')))
            assert m.deliver(row)==1 and m.fields()[0]=='Next track title'
        record('notification_registration_'+str(registered)+'_empty_'+str(empty),m)
        m.cancel_poll();m.conclude()

    for mode in ('inactive','disconnected','owner_pending','poll_OOM','wrong_queue','queued_UID_changed','queued_source_stopped'):
        m=Text(raw,candidate);m.arm_poll()
        if mode=='inactive':m.source_active=False
        elif mode=='disconnected':m.live(bytes(8),connected=False)
        elif mode=='owner_pending':m.write(owner.STATE+4,0x1234)
        elif mode=='poll_OOM':m.fail_poll=True
        elif mode=='wrong_queue':m.write(0x218656,14,2)
        m.due(2100,2100000)
        if mode.startswith('queued_'):
            assert len(m.profile_requests)==1
            if mode=='queued_UID_changed':m.live(b'NEW_UID!')
            else:m.source_active=False
            m.profile();assert not m.serialized and not m.read(h.STATE+16)
        else:assert not m.profile_requests and not m.serialized
        record('poll_refuses_'+mode,m)
        if mode=='owner_pending':m.write(owner.STATE+4,0)
        m.cancel_poll()
        # A normal request must still recover after any refused poll. Exercise
        # its real pending destructor before the existing strict final audit.
        m.source_active=True;m.fail_poll=False;m.write(0x218656,12,2)
        parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=attribute(1,b'Recovery after refused poll')))
        assert m.deliver(row)==1
        m.conclude()

    m=Text(raw,candidate);m.write(AVRCP+0x20c,0,1)
    parent=m.ordinary(bytes(8));row=m.respond(parent,reply(body=attribute(1,b'')))
    assert m.deliver(row)==1 and len(m.nodes())==1
    m.due(600,600000);assert len(m.profile_requests)==1
    m.profile();parent=m.serialized[-1]['confirmation']
    row=m.respond(parent,reply(body=attribute(1,b'Recovered without registration')))
    assert m.deliver(row)==1 and m.fields()[0]=='Recovered without registration'
    record('existing_empty_title_retry_works_with_registration_gate_zero',m);m.conclude()

    for mode in ('armed','queued'):
        m=Text(raw,candidate);m.arm_poll()
        if mode=='queued':m.due(2100,2100000)
        shutdown_proof.Shutdown.drop(m,h.DROP)
        assert not m.read(h.STATE+4) and not m.read(h.STATE+8) and not m.read(h.STATE+16)
        assert not m.nodes() and not m.profile_requests
        record('new_poll_shutdown_'+mode,m)
        FunctionType(shutdown_proof.Shutdown.finish.__code__,
                     dict(shutdown_proof.Shutdown.finish.__globals__,PREVIOUS=bytes(260)))(m)

    # Keep the receiver's full malformed/fragmented/freshness regression suite,
    # but instantiate an interpreter fetching the actual MAX07 PE instead.
    source=inspect.getsource(receive_proof.verify)
    start=source.index('    # Text hooks share the original request/parser bridges')
    stop=source.index("    for mode in ('final_offset'",start)
    # That one historical fixture has no installed lifecycle setup. It fails
    # in phase6 on unchanged MAX06 too. The installed cross-process artwork
    # suite exercises the real lifecycle/transfer/decoder/draw path instead.
    source=source[:start]+source[stop:]
    environment=dict(receive_proof.verify.__globals__,Receiver=lambda original:Text(original,candidate))
    exec(compile(source,'<MAX07-installed-text-suite>','exec'),environment)
    receive=environment['verify'](raw)
    receive['executed_candidate_sha256']=patcher.sha(candidate)
    receive['uninstalled_art_fixture_replaced_by_installed_artwork_suite']=True
    shutdown=shutdown_proof.verify(raw,lambda source:Text(source,candidate))
    # Persist completed checks before the separate native CM transport cases.
    progress=ROOT/'build/max07-bluetooth-verified-text.json'
    progress.write_text(json.dumps(dict(candidate_sha256=patcher.sha(candidate),inspection=checks,
                                       traces=traces,receiver=receive,shutdown=shutdown),indent=2)+'\n')
    transport=[]
    for security in (0,100,0x8000,0xffff,0x10000):
        m=Channel(pefile.PE(data=raw),candidate)
        m.ready_open();result=m.open(security=security)
        assert bool(result)==(security<=0xffff)
        if result:assert m.requests[-1]['security']==security
        transport.append(dict(security=security,opened=bool(result),steps=m.steps))
        m.reg[4]=m.state;m.free(m)
        assert not any(live for _,live in m.heap.values())
    audio=verify_audio(candidate)
    return dict(candidate_sha256=patcher.sha(candidate),inspection=checks,poll_and_retry_traces=traces,
                receiver=receive,shutdown=shutdown,transport=transport,audio=audio,
                cases=len(traces)+receive['cases']+shutdown['cases']+len(transport)+audio['cases'],
                hardware_tested=False,native_executed=False,
                limitations=['Instruction execution with explicit CE, source/wire/peer/clock fixtures',
                             'No physical Nothing phone, AVRCP trace, measured stutter or installed-unit result'])


if __name__=='__main__':
    report=verify();out=ROOT/'build/max07-bluetooth-development-03';out.mkdir(exist_ok=False)
    candidate,recipe=patcher.patch(patcher.SOURCE.read_bytes())
    (out/'Blue.exe').write_bytes(candidate)
    for name,value in (('recipe',recipe),('verification',report)):
        (out/(name+'.json')).write_text(json.dumps(value,indent=2)+'\n')
    print(json.dumps(dict(cases=report['cases'],sha256=report['candidate_sha256']),indent=2))
