"""Execute ordinary request ownership and guarded native continuation dispatch."""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path
import pefile
import bt_text_metadata_owner as owner
import bt_cover_art_metadata as metadata
import bt_cover_art_metadata_ticket as ticket
from verify_bt_cover_metadata import IntegratedFixture,reply
from verify_bt_cover_metadata_ticket import PROFILE
from verify_bt_cover_controller import attributes
from verify_bt_metadata_status import attribute
from verify_media_responsiveness import call
from inspect_bt_pairing import data,put
from patch_bt_cover_attribute import BASE_SHA

ROOT=Path(__file__).resolve().parents[1]
MANAGER,AVRCP=0x4b200000,0x4b300000


@lru_cache(maxsize=1)
def helpers():return owner.assembled()


class Owned(IntegratedFixture):
    def __init__(self,original,enabled=True):
        self.fail_ack=False
        super().__init__(original,enabled=enabled)
        rows=helpers();self.pe.helpers+=rows
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in rows]
        self.allowed += [(owner.STATE-4,owner.STATE+owner.SIZE+4),(MANAGER,MANAGER+0x300),
                         (AVRCP,AVRCP+0x1000),(owner.ROOT_POINTER,owner.ROOT_POINTER+4)]
        put(self,owner.STATE-4,b'guar'+bytes(owner.SIZE)+b'TAIL')
        put(self,MANAGER,bytes(0x300));put(self,AVRCP,bytes(0x1000))
        self.write(owner.ROOT_POINTER,MANAGER);self.write(MANAGER+0x26c,AVRCP)
        self.owner_enabled=enabled;self.fail_ack=False
        if enabled:self.patches.update(owner.sites(original.__data__))
        self.live(bytes(8))

    def live(self,uid,peer=3,connected=True,queue=7,index=0):
        self.write(AVRCP+0x60,queue,2);self.write(AVRCP+0x5e,index,1)
        self.write(AVRCP+0x6c+index*24,peer,1)
        self.write(AVRCP+0x6d+index*24,2 if connected else 0,1)
        put(self,AVRCP+0x235,uid)

    def ordinary(self,uid,mask=127,scope=3,queue=7,peer=3,update_live=True):
        if update_live:self.live(uid,peer=peer)
        request=self.request(queue=queue,mask=mask,scope=scope,peer=peer,uid=uid)
        self.execute(request)
        return self.serialized[-1]['confirmation']

    def respond(self,parent,packet,length=None,pointer=None):
        pending=next(p for p in self.pending if self.read(p+16)==parent)
        source=self.new(packet);self.enter_queue(12)
        entry=owner.RESPONSE if self.owner_enabled else metadata.ORIGINAL_RESPONSE
        before=len(self.fragments)+len(self.results)
        call(self,entry,[self.peer,pending,len(packet) if length is None else length,
                         source if pointer is None else pointer],limit=30000)
        self.reg[4]=source;self.free(self)
        assert not self.read(owner.STATE+24) and not self.read(owner.STATE+28)
        assert len(self.fragments)+len(self.results)==before+1
        # Invalid single/start lengths produce a final through the native error
        # path, regardless of the packet's original kind.
        return self.results[-1] if self.read(parent,2)==0x820d and not any(self.read(p+16)==parent for p in self.pending) else self.fragments[-1]

    def claim(self,row,final=False,queue=7):
        self.enter_queue(queue)
        return call(self,owner.CLAIM,[row['pointer'],int(final)])

    def ack(self,row,generation,proceed=1):
        self.enter_queue(7)
        return call(self,owner.ACK_BUILD,[row['pointer'],proceed,generation])

    def allocate(self,m):
        if self.fail_ack and owner.ACK_BUILD<=m.pc<owner.ACK_BUILD+0x800:
            self.fail_ack=False;return 0
        return super().allocate(m)

    def serialize(self,m):
        # Extend the legacy fixture's destination set for a foreign-queue
        # comparison; retain its actual native record/peer checks.
        peer,pending,mask=m.reg[4:7]
        assert peer==self.peer and m.read(pending+0x1c)==peer
        assert m.read(pending+0x16,2)==0x17 and m.read(pending+0x18,2) in (7,9,20)
        self.pending.append(pending)
        self.serialized.append(dict(pending=pending,confirmation=m.read(pending+16),
                                    queue=m.read(pending+0x18,2),mask=mask))
        return 0

    def response(self,packet,handle=True):
        self.respond(self.read(self.pending[0]+16),packet)
        if handle:self.handle()

    def profile(self):
        self.enter_queue(12)
        while self.profile_requests:
            request=self.profile_requests.popleft();self.write(PROFILE+12,request)
            at=0x53728 if self.read(request,2)==0x20c else owner.ACK_PROFILE
            call(self,at,[PROFILE],limit=30000)
            self.reg[4]=request;self.free(self)

    def release(self,row):self.cleanup_result(row['pointer'])

    def finish_pending(self):
        for pending in list(self.pending):
            self.enter_queue(12)
            before=len(self.results);call(self,0x6a50c,[pending])
            assert len(self.results)==before+1
            self.claim(self.results[-1],True);self.release(self.results[-1])

    def conclude(self):
        self.profile();self.finish_pending();self.enter_queue(7)
        assert call(self,owner.INVALIDATE,[])
        assert data(self,owner.STATE+32,owner.SIZE-32)==bytes(owner.SIZE-32)
        assert data(self,owner.STATE-4,4)==b'guar' and data(self,owner.STATE+owner.SIZE,4)==b'TAIL'
        self.deinit()


def verify(raw):
    assert hashlib.sha256(raw).hexdigest()==BASE_SHA
    original=pefile.PE(data=raw);cases=[]
    text=attribute(1,b'Title')+attribute(2,b'Artist')+attribute(3,b'Album')
    def record(name,m,extra=None):
        row=dict(case=name,serial=m.read(owner.STATE),continuations=len(m.continuations),
                 fragments=len(m.fragments),finals=len(m.results),details=extra)
        m.conclude();row['steps']=m.steps;cases.append(row)

    for uid in (bytes(8),b'12345678',b'\0abcdefg'):
        for index in (0,1):
            m=Owned(original);m.live(uid,index=index)
            parent=m.ordinary(uid,update_live=False)
            assert m.read(owner.STATE+4)==parent
            row=m.respond(parent,reply(body=text,count=3))
            assert m.claim(row,True)==1 and not m.read(owner.STATE+4)
            assert m.claim(row,True)==0
            m.release(row);record('single_actual_factory_UID_'+uid.hex()+'_row_'+str(index),m)

    for split in (0,1,7,8,19,27,41,len(text)):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=text[:split],count=3))
        assert m.read(m.peer+0xf0)==m.pending[0]
        generation=m.claim(row);assert generation==1 and not m.claim(row)
        assert m.ack(row,generation)
        request=m.profile_requests[-1];assert data(m,request,4)==bytes.fromhex('0d020301')
        m.release(row);m.profile();assert len(m.continuations)==1
        row=m.respond(parent,reply(3,body=text[split:],count=3))
        assert m.claim(row,True)==1;m.release(row)
        record('native_fragment_ack_and_final_split_'+str(split),m)

    for mode in ('same_zero_UID','changed_UID'):
        m=Owned(original);first=m.ordinary(bytes(8))
        old=m.respond(first,reply(1,body=text[:7],count=3));g=m.claim(old)
        assert m.ack(old,g);m.release(old)
        uid=bytes(8) if mode=='same_zero_UID' else b'NewUID00'
        second=m.ordinary(uid);assert m.read(owner.STATE)==2
        m.profile();assert not m.continuations
        old_final=m.respond(first,reply(3,body=text[7:],count=3))
        assert not m.claim(old_final,True);m.release(old_final)
        current=m.respond(second,reply(body=text,count=3))
        assert m.claim(current,True)==2;m.release(current)
        record('queued_old_ack_and_final_refused_'+mode,m)

    m=Owned(original);first=m.ordinary(bytes(8))
    old=m.respond(first,reply(1,body=text[:7],count=3))
    second=m.ordinary(bytes(8));assert not m.claim(old);m.release(old)
    m.finish_pending();record('queued_old_interim_same_zero_UID_refused',m)

    for changed in ('uid','peer','connection','destination'):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=text,count=3))
        m.live(b'Changed0' if changed=='uid' else bytes(8),peer=4 if changed=='peer' else 3,
               connected=changed!='connection',queue=8 if changed=='destination' else 7)
        assert not m.claim(row,True);m.release(row)
        record('live_change_before_application_claim_'+changed,m)

    for changed in ('uid','peer','connection','pending','invalidation'):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=text[:7],count=3));g=m.claim(row)
        assert m.ack(row,g);m.release(row)
        if changed=='invalidation':assert call(m,owner.INVALIDATE,[])
        elif changed=='pending':m.write(m.peer+0xf0,0)
        else:m.live(b'Changed0' if changed=='uid' else bytes(8),peer=4 if changed=='peer' else 3,
                    connected=changed!='connection')
        m.profile();assert not m.continuations
        record('ack_rechecks_native_pending_and_live_state_'+changed,m)

    # The profile wrapper preserves actual four-byte untagged legacy ACKs.
    for proceed in (0,1):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=text[:7],count=3));assert m.claim(row)==1;m.release(row)
        request=m.new(bytes.fromhex('0d0203')+bytes([proceed]))
        m.profile_requests.append(request);m.profile()
        assert len(m.continuations)==1
        # Both continue and abort send a native wire request. This fixture
        # drains the pending confirmation afterward through the original path.
        record('untagged_four_byte_legacy_ack_'+str(proceed),m)

    m=Owned(original);parent=m.ordinary(bytes(8))
    row=m.respond(parent,reply(1,body=text[:7],count=3));g=m.claim(row)
    before=len(m.heap);m.fail_ack=True;assert not m.ack(row,g)
    assert len(m.heap)==before and not m.profile_requests
    assert m.ack(row,g);m.release(row);m.profile();assert len(m.continuations)==1
    record('ack_allocation_failure_preserves_identity_then_recovers',m)

    for field,kwargs in (('mask',dict(mask=128)),('scope',dict(scope=1)),('queue',dict(queue=9))):
        m=Owned(original);parent=m.ordinary(bytes(8),**kwargs)
        assert not m.read(owner.STATE+4) and not m.read(owner.STATE)
        row=m.respond(parent,reply(body=text,count=3));assert not m.claim(row,True);m.release(row)
        record('foreign_request_preserves_native_post_'+field,m)

    m=Owned(original);m.write(owner.STATE,0xffffffff)
    parent=m.ordinary(bytes(8));assert not m.read(owner.STATE+4) and m.read(owner.STATE)==0xffffffff
    row=m.respond(parent,reply(body=text,count=3));assert not m.claim(row,True);m.release(row)
    record('serial_saturation_never_reuses_zero',m)

    for queue in (8,0x807):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=text,count=3));before=data(m,owner.STATE,owner.SIZE)
        assert not m.claim(row,True,queue=queue) and data(m,owner.STATE,owner.SIZE)==before
        assert m.claim(row,True,queue=7)==1;m.release(row)
        record('foreign_application_claim_queue_'+str(queue),m)

    m=Owned(original);parent=m.ordinary(bytes(8));rows=[]
    for i in range(owner.TAGS+1):
        rows.append(m.respond(parent,reply(1 if i==0 else 2,body=b'',count=1)))
    assert not m.read(owner.STATE+4)
    for row in rows:assert not m.claim(row);m.release(row)
    assert not m.profile_requests
    record('interim_tag_capacity_fails_closed_and_drains',m)

    m=Owned(original);parent=m.ordinary(bytes(8))
    for i in range(owner.TAGS+1):
        row=m.respond(parent,reply(1 if i==0 else 2,body=b'',count=1));g=m.claim(row)
        before=len(m.heap);accepted=m.ack(row,g)
        assert accepted==int(i<owner.TAGS)
        if not accepted:assert len(m.heap)==before and len(m.profile_requests)==owner.TAGS
        m.release(row)
    assert call(m,owner.INVALIDATE,[])
    m.profile();assert not m.continuations
    record('queued_ACK_capacity_then_invalidation_preserves_tags_until_drain',m)

    for changed in ('confirmation','destination'):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=text[:7],count=3));g=m.claim(row)
        assert m.ack(row,g);m.release(row)
        pending=m.pending[0];off,n=(16,4) if changed=='confirmation' else (0x18,2)
        old=m.read(pending+off,n);m.write(pending+off,parent+4 if changed=='confirmation' else 9,n)
        m.profile();assert not m.continuations
        m.write(pending+off,old,n)
        record('ACK_checks_actual_pending_'+changed,m)

    m=Owned(original);m.start();body=attributes()[1:]
    m.response(reply(1,body=body[:7]));m.profile()
    assert len(m.continuations)==1 and not m.read(owner.STATE)
    m.response(reply(3,body=body[7:]));m.finish_image()
    assert m.visible is not None and not m.read(owner.STATE)
    record('existing_artwork_request_fragment_ACK_image_pipeline_preserved',m)

    fixtures=[('single',[reply(body=text,count=3)]),
              ('three_fragments',[reply(1,body=text[:7],count=3),reply(2,body=text[7:19],count=3),
                                  reply(3,body=text[19:],count=3)]),
              ('empty',[reply(body=b'',count=0)]),
              ('accepted_ctype12',[reply(body=text,count=3,ctype=12)]),
              ('rejected_ctype10',[reply(body=text,count=3,ctype=10)]),
              ('short_payload',[reply(body=text,count=3)[:12]])]
    for uid in (bytes(8),b'12345678',b'\0abcdefg'):
        for name,packets in fixtures:
            outputs=[]
            for enabled in (False,True):
                m=Owned(original,enabled=enabled);parent=m.ordinary(uid);rows=[]
                for packet in packets:
                    row=m.respond(parent,packet)
                    size=24 if m.read(row['pointer'],2)==0x8224 else 28
                    rows.append(dict(envelope=data(m,row['pointer'],size).hex(),
                                     payload=data(m,m.read(row['pointer']+16),m.read(row['pointer']+14,2)).hex()))
                    m.claim(row,size==28);m.release(row)
                outputs.append(rows)
                if not enabled:m.conclude()
            assert outputs[0]==outputs[1]
            record('byte_exact_original_native_posts_'+name+'_UID_'+uid.hex(),m)

    for lost in ('manager','status'):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=text,count=3))
        at=owner.ROOT_POINTER if lost=='manager' else MANAGER+0x26c
        m.write(at,0);assert not m.claim(row,True);m.release(row)
        record('cleared_global_'+lost+'_refuses_publication',m)

    for changed in ('zero_generation','old_generation','invalid_proceed','live_UID'):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=text[:7],count=3));g=m.claim(row)
        if changed=='live_UID':m.live(b'Changed0')
        g=0 if changed=='zero_generation' else g+1 if changed=='old_generation' else g
        before=len(m.heap);assert not m.ack(row,g,2 if changed=='invalid_proceed' else 1)
        assert len(m.heap)==before and not m.profile_requests;m.release(row)
        record('ACK_builder_refuses_before_allocation_'+changed,m)

    for kind in (0,1,2,3):
        m=Owned(original);parent=m.ordinary(bytes(8))
        packet=reply(kind,body=b'')[:13]
        row=m.respond(parent,packet);final=m.read(row['pointer'],2)==0x820d
        assert final==(kind!=2)
        assert m.claim(row,final)==1
        if kind<2:
            assert m.read(row['pointer']+20,2)!=0x8000
        m.release(row);record('thirteen_byte_packet_count_guard_kind_'+str(kind),m)

    for name,length,pointer in (('null_source',14,0),('wrapped_source',32,0xfffffff0),
                                ('over_16bit_length',65536,None)):
        m=Owned(original);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=b''),length=length,pointer=pointer)
        assert m.read(row['pointer']+20,2)!=0x8000 and m.claim(row,True)==1
        m.release(row);record('unsafe_borrowed_packet_refused_before_native_read_'+name,m)

    names=('bt_text_metadata_owner.py','verify_bt_text_metadata_owner.py','bt_cover_art_metadata.py',
           'bt_cover_art_metadata_ticket.py','verify_bt_cover_metadata.py','verify_bt_cover_metadata_ticket.py')
    return dict(cases=len(cases),baseline_sha256=BASE_SHA,traces=cases,state_bytes=owner.SIZE,
                helpers=[dict(name=r['name'],address=hex(r['address']),bytes=r['recipe']['used_bytes'],
                              sha256=hashlib.sha256(r['raw']).hexdigest()) for r in helpers()],
                hardware_tested=False,lgu_built=False,executable_written=False,
                limits=['Native request/factory/parser/interim/final and continuation instructions execute with strict allocation bounds',
                        'Old UID/generation acknowledgements are dropped before the unchanged native continuation handler',
                        'Untagged four-byte legacy ACKs delegate without extended-object reads',
                        'Short single/start packets and null/wrapped/oversized source ranges use the original short-response error path',
                        'Wire, selected manager status, timers, queue delivery, allocation and C operations remain fixtures',
                        'Streaming application dispatch, deadline/retry, actual lifecycle hooks and installed PE/LGU binding remain open',
                        'ACK side tags must survive invalidation until queued profile requests are consumed; shutdown queue drain is not yet bound'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True);p.add_argument('--report',type=Path,required=True);a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    r=verify(a.input.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode())
    print(json.dumps(dict(cases=r['cases'],state_bytes=r['state_bytes'],lgu_built=False),indent=2))
