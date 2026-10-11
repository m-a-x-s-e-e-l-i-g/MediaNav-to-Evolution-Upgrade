"""Execute native request/parser/application dispatch and owned text publication."""
import argparse
from collections import Counter
from functools import lru_cache
import hashlib
import json
from pathlib import Path
import pefile
import bt_text_metadata_receive as receive
import bt_text_metadata_stream as stream
import bt_text_metadata_owner as owner
from verify_bt_text_metadata_owner import Owned,AVRCP,MANAGER
from verify_bt_cover_metadata import reply
from verify_bt_metadata_status import attribute,PREVIOUS,COOKIE
from inspect_bt_pairing import data,put
from verify_media_responsiveness import call
from patch_bt_metadata_status import patch as status_patch
from patch_bt_metadata_interim import patch as interim_patch
from patch_bt_metadata_uid_width import patch as uid_patch
from stage_artwork_feedback_inputs import compose
from patch_bt_cover_attribute import BASE_SHA
from verify_bt_cover_controller import attributes

ROOT=Path(__file__).resolve().parents[1]
APP_ID,DISPATCH=0x1234,0x20c68
OLD_UID=b'OldUID00'


@lru_cache(maxsize=1)
def helpers():return stream.assembled()+receive.assembled()


class Receiver(Owned):
    def __init__(self,raw):
        self.publications=[];self.visits=Counter();self.borrowed=None;self.ordinary_posts=[]
        super().__init__(pefile.PE(data=raw))
        rows=helpers();self.pe.helpers+=rows
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in rows]
        self.ranges += [(DISPATCH,0x20ec4),(0x1fa44,0x1fce8),(0x1fce8,0x1ff40),
                        (0x79160,0x79258),(0x79258,0x79364),(0x85bb8,0x85bdc)]
        self.ranges += [(0x1d3c4,0x1d47c)]
        self.allowed += [(stream.STATE-4,stream.STATE+stream.SIZE+4),
                         (receive.STATE-4,receive.STATE+receive.SIZE+4),(0x20cb0,0x20cfc),
                         (0x110ea4,0x110ea8),(receive.PROFILE_TABLE,receive.PROFILE_TABLE+4)]
        put(self,stream.STATE-4,b'STR0'+bytes(stream.SIZE)+b'STR1')
        put(self,receive.STATE-4,b'RCV0'+bytes(receive.SIZE)+b'RCV1')
        self.write(AVRCP+0x248,1,1);put(self,AVRCP+0xee,PREVIOUS);put(self,AVRCP+0x219,OLD_UID)
        self.write(0x110ea4,COOKIE)
        self.patches.update(receive.sites(raw))
        self.write(receive.PROFILE_TABLE,owner.ACK_PROFILE)
        # The retained callbacks use the exact already-verified status/interim
        # and eight-byte UID repairs when a non-scope-3 route is delegated.
        patched,_=compose(raw,[('status',status_patch),('interim',interim_patch),('uid',uid_patch)])
        self.pe.original=pefile.PE(data=patched)
        put(self,0x20cb0,self.pe.original.get_data(0x20cb0-0x10000,0x4c))
        self.hooks.update({0x1eb50:self.publish_text,0x8ac14:self.zero,0x3a750:self.zero,
                           0x857a0:self.compare,0x8accc:self.concatenate,0x8ac24:self.cookie})

    def word(self,pc):self.visits[pc]+=1;return super().word(pc)

    def write(self,at,value,size=4):
        if self.borrowed is not None:
            lo,n=self.borrowed
            assert not (at<lo+n and lo<at+size),('Write to borrowed metadata payload',hex(at),size)
        return super().write(at,value,size)

    def publish_text(self,m):
        assert m.reg[4:6]==[APP_ID,1]
        self.publications.append(data(m,AVRCP+0xee,260).hex());return 0

    def zero(self,m):
        at,value,n=m.reg[4:7];put(m,at,bytes([value&255])*n);return at

    def compare(self,m):
        a,b,n=m.reg[4:7];return int(data(m,a,n)!=data(m,b,n))

    def cstring(self,at,n):
        out=bytearray()
        for i in range(n):
            x=self.read(at+i,1)
            if not x:break
            out.append(x)
        return bytes(out)

    def concatenate(self,m):
        at,capacity,source,n=m.reg[4:8]
        old=self.cstring(at,capacity);incoming=self.cstring(source,min(n,capacity-len(old)-1))
        put(m,at,old+incoming+b'\0');return 0

    def cookie(self,m):assert m.reg[4]==COOKIE;return 0

    def profile_post(self,m):
        queue,event,pointer=m.reg[4:7]
        if self.read(pointer,2)==0x20c and self.read(pointer+16)==127:
            assert queue==12 and event==0x11b and self.read(pointer+2,2)==7
            self.ordinary_posts.append(data(m,pointer,20).hex())
            self.profile_requests.append(pointer);return 0
        return super().profile_post(m)

    def queue_ordinary(self):
        self.enter_queue(7);before=len(self.profile_requests)
        call(self,0x1d3c4,[APP_ID,AVRCP])
        assert len(self.profile_requests)==before+1

    def finish_pending(self):
        for pending in list(self.pending):
            self.enter_queue(12);before=len(self.results)
            call(self,0x6a50c,[pending]);assert len(self.results)==before+1
            self.deliver(self.results[-1])

    def deliver(self,row,queue=7):
        pointer=row['pointer'];payload=self.read(pointer+16);n=self.read(pointer+14,2)
        self.borrowed=(payload,n) if payload else None
        before=len(self.publications);self.enter_queue(queue)
        try:call(self,DISPATCH,[APP_ID,AVRCP,pointer],limit=30000)
        finally:self.borrowed=None
        assert not self.read(pointer+16)
        if payload:assert not self.heap[payload][1]
        assert self.visits[receive.FINAL_SITE if self.read(pointer,2)==0x820d else receive.INTERIM_SITE]
        self.release(row);return len(self.publications)-before

    def fields(self):return [self.cstring(AVRCP+0xee+off,n).decode('utf8') for off,n in ((0,50),(50,50),(100,160))]

    def conclude(self):
        assert data(self,stream.STATE-4,4)==b'STR0' and data(self,stream.STATE+stream.SIZE,4)==b'STR1'
        assert data(self,receive.STATE-4,4)==b'RCV0' and data(self,receive.STATE+receive.SIZE,4)==b'RCV1'
        return super().conclude()


def verify(raw):
    assert hashlib.sha256(raw).hexdigest()==BASE_SHA;cases=[]
    body=attribute(1,b'Fresh title')+attribute(2,b'Artist')+attribute(3,b'Album')
    expected=['Fresh title','Album','Artist']
    def record(name,m,details=None):
        row=dict(case=name,fields=m.fields(),publications=len(m.publications),
                 successful_generation=m.read(receive.STATE+16),failed_generation=m.read(receive.STATE+20),
                 frames=m.read(receive.STATE+12),details=details)
        m.conclude();row['steps']=m.steps;cases.append(row)

    for uid in (bytes(8),b'12345678',b'\0abcdefg'):
        m=Receiver(raw);parent=m.ordinary(uid)
        row=m.respond(parent,reply(body=body,count=3));assert m.deliver(row)==1
        assert m.fields()==expected and m.read(AVRCP+0x248,1)==1
        assert data(m,AVRCP+0x219,8)==(uid if any(uid) else OLD_UID)
        assert m.read(receive.STATE+16)==1 and not m.read(receive.STATE+20)
        record('single_native_application_dispatch_UID_'+uid.hex(),m)

    for split in range(len(body)+1):
        m=Receiver(raw);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=body[:split],count=3));assert not m.deliver(row)
        assert data(m,AVRCP+0xee,260)==PREVIOUS and not m.publications
        m.profile();assert len(m.continuations)==1
        row=m.respond(parent,reply(3,body=body[split:],count=3));assert m.deliver(row)==1
        assert m.fields()==expected and len(m.publications)==1
        record('native_application_fragment_split_'+str(split),m)

    m=Receiver(raw);parent=m.ordinary(bytes(8))
    for i,(kind,part) in enumerate(((1,body[:7]),(2,body[7:19]),(3,body[19:]))):
        row=m.respond(parent,reply(kind,body=part,count=3));assert m.deliver(row)==int(i==2)
        if i<2:m.profile()
    assert m.fields()==expected and len(m.continuations)==2 and len(m.publications)==1
    record('three_native_fragments_publish_once',m)

    invalid=[('unknown_ID',attribute(8,b'x'),1),
             ('duplicate_ID',attribute(1,b'A')+attribute(1,b'B'),2),
             ('missing_title',attribute(2,b'Artist'),1),
             ('unsupported_charset',b'\0\0\0\x01\0\x65\0\x01x',1),
             ('extra_body_bytes',attribute(1,b'Title')+b'X',1),
             ('incomplete_final_value',attribute(1,b'Title')[:-1],1),
             ('empty_list',b'',0),
             ('invalid_UTF8',attribute(1,b'\xed\xa0\x80'),1)]
    for name,payload,count in invalid:
        m=Receiver(raw);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=payload,count=count));assert not m.deliver(row)
        assert data(m,AVRCP+0xee,260)==PREVIOUS and m.read(receive.STATE+20)==1
        parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=attribute(1,b'Next title')));assert m.deliver(row)==1
        assert m.fields()==['Next title','',''] and m.read(receive.STATE+16)==2
        record('refused_list_preserves_text_then_next_request_recovers_'+name,m)

    for ctype in (8,10,15):
        m=Receiver(raw);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=body,count=3,ctype=ctype));assert not m.deliver(row)
        assert data(m,AVRCP+0xee,260)==PREVIOUS and m.read(receive.STATE+20)==1
        assert m.read(AVRCP+0x248,1)==1
        record('failed_native_result_preserves_text_ctype_'+str(ctype),m)

    # Queue the next request through the original application producer BEFORE
    # delivering the old interim. Actual profile FIFO then executes the new
    # request before the old acknowledgement; no artificial reordering is used.
    m=Receiver(raw);first=m.ordinary(bytes(8))
    old=m.respond(first,reply(1,body=body[:7],count=3));m.queue_ordinary()
    assert not m.deliver(old);assert len(m.profile_requests)==2
    m.profile();assert not m.continuations and m.read(owner.STATE)==2
    second=m.serialized[-1]['confirmation']
    m.write(AVRCP+0x248,0,1);before=data(m,receive.STATE,receive.SIZE)
    old=m.respond(first,reply(3,body=body[7:],count=3));assert not m.deliver(old)
    assert m.read(AVRCP+0x248,1)==0 and data(m,receive.STATE,receive.SIZE)==before
    current=m.respond(second,reply(body=body,count=3));assert m.deliver(current)==1
    assert m.fields()==expected and m.read(AVRCP+0x248,1)==1
    record('real_profile_FIFO_drops_old_ACK_and_final_without_touching_new_state',m)

    m=Receiver(raw);first=m.ordinary(bytes(8))
    old=m.respond(first,reply(1,body=body[:7],count=3));second=m.ordinary(bytes(8))
    before=data(m,receive.STATE,receive.SIZE);assert not m.deliver(old)
    assert not m.profile_requests and data(m,receive.STATE,receive.SIZE)==before
    current=m.respond(second,reply(body=body,count=3));assert m.deliver(current)==1
    assert m.fields()==expected;record('old_interim_cannot_start_new_request_stream',m)

    for mode in ('cancel_flag','ACK_OOM','empty_continuation'):
        m=Receiver(raw);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=body[:7],count=3))
        if mode=='cancel_flag':m.write(AVRCP+0x248,0,1)
        if mode=='ACK_OOM':m.fail_ack=True
        assert not m.deliver(row)
        m.profile()
        if mode=='empty_continuation':
            row=m.respond(parent,reply(2,body=b'',count=3));assert not m.deliver(row);m.profile()
        assert data(m,AVRCP+0xee,260)==PREVIOUS and m.read(receive.STATE+20)==1
        m.finish_pending();assert m.read(AVRCP+0x248,1)==1 and not m.read(owner.STATE+4)
        parent=m.ordinary(bytes(8));row=m.respond(parent,reply(body=body,count=3))
        assert m.deliver(row)==1 and m.fields()==expected
        record('failed_fragment_drains_then_valid_request_recovers_'+mode,m)

    for name,mutate in (
            ('PDU_ID',lambda m,p:m.write(p+9,0x21,1)),
            ('declared_length',lambda m,p:m.write(p+12,0,1)),
            ('supplier',lambda m,p:None)):
        m=Receiver(raw);parent=m.ordinary(bytes(8));row=m.respond(parent,reply(body=body,count=3))
        if name=='supplier':m.write(row['pointer']+22,0,2)
        else:mutate(m,m.read(row['pointer']+16))
        assert not m.deliver(row) and data(m,AVRCP+0xee,260)==PREVIOUS
        record('malformed_owned_final_refused_'+name,m)

    for ident in (1,2,3):
        text=('A'*48+'\u00e9').encode()
        parts={1:b'Title',2:b'Artist',3:b'Album'};parts[ident]=text
        payload=b''.join(attribute(i,parts[i]) for i in (3,1,2))
        m=Receiver(raw);parent=m.ordinary(bytes(8));row=m.respond(parent,reply(body=payload,count=3))
        assert m.deliver(row)==1
        wanted=[parts[1].decode(),parts[3].decode(),parts[2].decode()]
        wanted[(1,3,2).index(ident)]='A'*48
        assert m.fields()==wanted;record('clamped_UTF8_character_boundary_ID_'+str(ident),m)

    m=Receiver(raw);parent=m.ordinary(bytes(8),scope=1)
    row=m.respond(parent,reply(body=body,count=3));assert m.deliver(row)==1
    assert m.fields()==expected and not m.read(receive.STATE+16)
    record('non_scope3_callback_retains_original_native_text_handler',m)

    # Text hooks share the original request/parser bridges with artwork. Run
    # the complete artwork path, not just a request-envelope comparison.
    m=Receiver(raw);m.start();art_body=attributes()[1:]
    m.response(reply(1,body=art_body[:7]));m.profile()
    assert len(m.continuations)==1 and not m.read(owner.STATE)
    m.response(reply(3,body=art_body[7:]));m.finish_image()
    assert m.visible is not None and not m.publications
    assert data(m,AVRCP+0xee,260)==PREVIOUS
    record('shared_bridges_preserve_complete_fragmented_artwork_pipeline',m)

    for mode in ('final_offset','interim_offset','CFM_count','wire_count'):
        m=Receiver(raw);parent=m.ordinary(bytes(8))
        interim=mode=='interim_offset'
        row=m.respond(parent,reply(1 if interim else 0,body=body,count=3))
        pointer=row['pointer']
        if mode.endswith('offset'):m.write(pointer+(20 if interim else 24),13,2)
        elif mode=='CFM_count':m.write(pointer+12,2,1)
        else:m.write(m.read(pointer+16)+13,2,1)
        assert not m.deliver(row) and not m.publications
        assert data(m,AVRCP+0xee,260)==PREVIOUS and m.read(receive.STATE+20)==1
        if interim:m.profile();assert m.acks[-1]['proceed']==0
        record('inconsistent_packet_state_refused_'+mode,m)

    # A refused request must not send repeated abort ACKs if additional interim
    # replies were already queued before the profile consumed the first abort.
    m=Receiver(raw);parent=m.ordinary(bytes(8))
    rows=[m.respond(parent,reply(1 if i==0 else 2,body=body[:7],count=3)) for i in range(3)]
    m.write(rows[0]['pointer']+20,13,2)
    for row in rows:assert not m.deliver(row)
    assert len(m.profile_requests)==1 and not m.publications
    assert data(m,AVRCP+0xee,260)==PREVIOUS
    m.profile();assert len(m.continuations)==1 and m.acks[0]['proceed']==0
    record('failed_phase_sends_one_abort_for_already_queued_interims',m)

    names=('bt_text_metadata_receive.py','verify_bt_text_metadata_receive.py','bt_text_metadata_owner.py',
           'bt_text_metadata_stream.py','verify_bt_text_metadata_owner.py','patch_bt_metadata_status.py',
           'patch_bt_metadata_interim.py','patch_bt_metadata_uid_width.py')
    return dict(cases=len(cases),traces=cases,baseline_sha256=BASE_SHA,hardware_tested=False,
                lgu_built=False,executable_written=False,
                helpers=[dict(name=r['name'],address=hex(r['address']),bytes=r['recipe']['used_bytes'],
                              sha256=hashlib.sha256(r['raw']).hexdigest()) for r in receive.assembled()],
                limits=['Actual native request/parser/factory/application dispatcher execute with substituted reviewed hook words and helper overlays',
                        'Payloads are read-only during delivery; original null-safe free and subsequent content cleanup reject leaks/double free',
                        'Text publication, C operations, allocator, selected manager state, queues, wire and timers remain fixtures',
                        'Deadline/retry, actual lifecycle hooks, generic profile-table dispatch and installed PE/LGU binding remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True);p.add_argument('--report',type=Path,required=True);a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    r=verify(a.input.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode())
    print(json.dumps(dict(cases=r['cases'],lgu_built=False),indent=2))
