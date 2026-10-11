"""Interpret native AVRCP metadata request/CFM identity capture and draining.

Original request handler, CFM constructor, pending record construction and result
posting execute as MIPS. Peer lookup/support, list allocation/removal, copying and
wire serialization/delivery are fixtures. No payload parser/controller is wired.
"""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_metadata_ticket as ticket
from patch_bt_cover_attribute import BASE_SHA
from verify_bt_cover_timers import TimerFixture
from verify_media_responsiveness import call
from inspect_bt_pairing import data,put

ROOT=Path(__file__).resolve().parents[1]
PROFILE,OUTPUT=0x47000000,0x47001000
NATIVE=[(0x53728,0x5382c),(0x52a5c,0x52aec),(0x6a968,0x6a9d8),
        (0x6a50c,0x6a54c),(0x56ad4,0x56af4)]


@lru_cache(maxsize=1)
def assembled():return ticket.assembled()


class MetadataFixture(TimerFixture):
    def __init__(self,original,enabled=True,success=True):
        super().__init__(original)
        self.pe.helpers+=assembled()
        self.ranges+=NATIVE+[(r['address'],r['address']+len(r['raw'])) for r in assembled()]
        self.allowed += [(PROFILE,PROFILE+0xa0),(OUTPUT,OUTPUT+16),(ticket.SLOT,ticket.SLOT+ticket.SIZE)]
        for at,size in ((PROFILE,0xa0),(OUTPUT,16),(ticket.SLOT,ticket.SIZE)):put(self,at,bytes(size))
        self.ready(queue=20)
        self.peer=self.new(bytes(0x140))
        self.success=success
        self.pending,self.serialized,self.results=[],[],[]
        self.hooks.update({0x8186c:self.lookup,0x6a8d8:lambda _:0x8000,
                           0x814a0:self.allocate_record,0x81598:self.remove_record,
                           0x85758:self.copy,0x6f568:self.serialize,0x84ec8:self.profile_post})
        if enabled:self.patches[ticket.SITE]=ticket.site_word(original.__data__)

    def copy(self,m):
        pointer,source,size=m.reg[4:7]
        assert size==8
        put(m,pointer,data(m,source,size))
        return pointer

    def lookup(self,m):
        assert m.reg[4:6]==[PROFILE+0x7c,0x10]
        return self.peer if self.success else 0

    def allocate_record(self,m):
        assert m.reg[4:6]==[self.peer+0xf8,32]
        return self.new(bytes(32))

    def remove_record(self,m):
        pointer=m.reg[5]
        assert m.reg[4]==self.peer+0xf8 and not m.read(pointer+0x10)
        m.reg[4]=pointer;self.free(m)
        self.pending.remove(pointer)
        return 0

    def serialize(self,m):
        peer,pending,mask=m.reg[4:7]
        assert peer==self.peer and m.read(pending+0x1c)==peer
        assert m.read(pending+0x16,2)==0x17
        assert m.read(pending+0x18,2) in (20,7)
        self.pending.append(pending)
        self.serialized.append(dict(pending=pending,confirmation=m.read(pending+0x10),
                                    queue=m.read(pending+0x18,2),mask=mask))
        return 0

    def profile_post(self,m):
        queue,event,pointer=m.reg[4:7]
        assert event==0x11b and m.read(pointer,2)==0x820d
        self.results.append(dict(queue=queue,event=event,pointer=pointer,
                                 bytes_hex=data(m,pointer,28).hex()))
        return 0

    def request(self,queue=20,mask=128,peer=3,scope=3,uid=b'12345678'):
        p=self.new(bytes(20))
        self.write(p,0x20c,2);self.write(p+2,queue,2)
        self.write(p+4,peer,1);self.write(p+5,scope,1)
        put(self,p+6,uid);self.write(p+14,0x2468,2);self.write(p+16,mask)
        return p

    def begin_request(self,p,channel=7,track=11):
        self.enter_queue()
        return call(self,ticket.BEGIN,[p,channel,track])

    def execute(self,p):
        self.enter_queue(12)  # Original AVRCP profile and artwork share segment 0.
        self.write(PROFILE+0xc,p)
        call(self,0x53728,[PROFILE],limit=20000)
        self.reg[4]=p;self.free(self)

    def finish(self):
        if self.pending:
            self.enter_queue(12)
            call(self,0x6a50c,[self.pending[0]])
        return self.results[-1]['pointer']

    def take(self,p,output=OUTPUT):
        self.enter_queue()
        return call(self,ticket.TAKE,[p,output])

    def invalidate(self):
        self.enter_queue()
        return call(self,ticket.INVALIDATE,[])

    def release_result(self,p):
        self.reg[4]=p;self.free(self)

    def deinit(self):
        assert not self.pending and not self.read(ticket.SLOT+16), 'Metadata identity must drain before slot teardown'
        self.reg[4]=self.peer;self.free(self)
        super().deinit()


def verify(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    original=pefile.PE(data=raw)
    traces=[]

    def record(name,m):
        assert data(m,ticket.SLOT,ticket.SIZE)==bytes(ticket.SIZE)
        results=list(m.results);serialized=list(m.serialized)
        m.deinit()
        traces.append(dict(case=name,results=results,serialized=serialized,steps=m.steps))

    comparisons=[]
    for success in (False,True):
        for peer in (0,3,255):
            sides=[]
            for enabled in (False,True):
                m=MetadataFixture(original,enabled,success)
                p=m.request(queue=7,mask=127,peer=peer)
                m.execute(p);cfm=m.finish()
                assert data(m,ticket.SLOT,ticket.SIZE)==bytes(ticket.SIZE)
                sides.append(dict(results=list(m.results),serialized=list(m.serialized)))
                m.release_result(cfm);record(f'legacy_{success}_{peer}_{enabled}',m)
            assert sides[0]==sides[1], 'Existing metadata route changed'
            comparisons.append(dict(success=success,peer=peer,original=sides[0],bridge=sides[1]))

    for success in (False,True):
        for peer in (0,3,255):
            m=MetadataFixture(original,success=success)
            p=m.request(peer=peer);assert m.begin_request(p)
            m.execute(p);cfm=m.finish()
            assert m.read(ticket.SLOT+4)==cfm and not m.read(ticket.SLOT)
            assert m.read(cfm+2,1)==peer and data(m,cfm+4,8)==b'12345678'
            # Confirm the actual original constructor status/supplier/offset fields.
            assert m.read(cfm+20,2)==(0x800a if success else 0x8007)
            assert m.read(cfm+22,2)==0x11 and m.read(cfm+24,2)==0
            assert m.take(cfm)==1 and data(m,OUTPUT,8)==(7).to_bytes(4,'little')+(11).to_bytes(4,'little')
            assert m.take(cfm)==0
            m.release_result(cfm);record(f'actual_confirmation_ticket_{success}_{peer}',m)

    for stage in ('queued','captured'):
        m=MetadataFixture(original)
        p=m.request();assert m.begin_request(p)
        if stage=='captured':m.execute(p)
        assert m.invalidate()
        next_request=m.request(uid=b'nextUID!')
        before=data(m,ticket.SLOT,ticket.SIZE)
        assert not m.begin_request(next_request,8,12)
        assert data(m,ticket.SLOT,ticket.SIZE)==before
        if stage=='queued':m.execute(p)
        cfm=m.finish();before=data(m,OUTPUT,8)
        assert m.take(cfm)==2 and data(m,OUTPUT,8)==before
        m.release_result(cfm)
        assert m.begin_request(next_request,8,12)
        m.execute(next_request);cfm=m.finish()
        assert m.take(cfm)==1 and m.read(OUTPUT)==8 and m.read(OUTPUT+4)==12
        m.release_result(cfm);record('invalidated_'+stage+'_drains_before_new_ticket',m)

    m=MetadataFixture(original)
    p=m.request();assert m.begin_request(p)
    other=m.request(queue=7,mask=127,uid=b'otherUID')
    before=data(m,ticket.SLOT,ticket.SIZE)
    m.execute(other);foreign=m.finish()
    assert data(m,ticket.SLOT,ticket.SIZE)==before and m.take(foreign)==0
    m.release_result(foreign)
    m.execute(p);cfm=m.finish();assert m.take(cfm)==1
    m.release_result(cfm);record('unrelated_profile_request_and_reply_leave_ticket_armed',m)

    for malformed in ('type','scope','mask','queue','zero_channel','zero_track','wrong_context'):
        m=MetadataFixture(original)
        p=m.request()
        if malformed=='type':m.write(p,0x20e,2)
        if malformed=='scope':m.write(p+5,1,1)
        if malformed=='mask':m.write(p+16,127)
        if malformed=='queue':m.write(p+2,7,2)
        m.enter_queue(12 if malformed=='wrong_context' else 20)
        before=data(m,ticket.SLOT,ticket.SIZE)
        assert call(m,ticket.BEGIN,[p,0 if malformed=='zero_channel' else 7,0 if malformed=='zero_track' else 11])==0
        assert data(m,ticket.SLOT,ticket.SIZE)==before
        m.reg[4]=p;m.free(m);record('arm_refused_'+malformed,m)

    for output in (0,OUTPUT+1,0xfffffffc,ticket.SLOT):
        m=MetadataFixture(original);p=m.request();assert m.begin_request(p)
        m.execute(p);cfm=m.finish();before=data(m,ticket.SLOT,ticket.SIZE)
        assert m.take(cfm,output)==0 and data(m,ticket.SLOT,ticket.SIZE)==before
        assert m.take(cfm)==1
        m.release_result(cfm);record('ticket_output_guard_'+hex(output),m)
    m=MetadataFixture(original);p=m.request();assert m.begin_request(p)
    m.execute(p);cfm=m.finish();before=data(m,cfm,28)
    assert not m.take(cfm,cfm) and data(m,cfm,28)==before
    assert m.take(cfm)==1;m.release_result(cfm);record('ticket_output_cannot_overwrite_confirmation',m)

    m=MetadataFixture(original);p=m.request();assert m.begin_request(p)
    m.execute(p);cfm=m.finish();before=data(m,ticket.SLOT,ticket.SIZE)
    m.enter_queue(12)
    assert not call(m,ticket.TAKE,[cfm,OUTPUT]) and not call(m,ticket.INVALIDATE,[])
    assert data(m,ticket.SLOT,ticket.SIZE)==before
    assert m.take(cfm)==1;m.release_result(cfm);record('foreign_queue_cannot_drain_or_invalidate_ticket',m)

    m=MetadataFixture(original);p=m.request();assert m.begin_request(p)
    before=data(m,ticket.SLOT,ticket.SIZE)
    m.current_segment=1;m.enter_queue(0x80c)
    # An original factory result in another segment is retained unchanged.
    foreign=call(m,ticket.CAPTURE,[3,3,p+6])
    assert m.read(foreign,2)==0x820d and data(m,foreign+4,8)==b'12345678'
    assert data(m,ticket.SLOT,ticket.SIZE)==before
    m.release_result(foreign)
    m.current_segment=0;m.execute(p);cfm=m.finish()
    assert m.take(cfm)==1;m.release_result(cfm)
    record('foreign_segment_factory_does_not_capture',m)

    for pointer in (0,0x47000001,0xfffffff0):
        m=MetadataFixture(original)
        assert not m.begin_request(pointer)
        record('invalid_request_pointer_'+hex(pointer),m)

    names=('bt_cover_art_metadata_ticket.py','verify_bt_cover_metadata_ticket.py',
           'bt_cover_art_timers.py','verify_bt_cover_timers.py','bt_cover_art_controller.py',
           'verify_bt_cover_controller.py','bt_cover_art_task.py','verify_bt_cover_task.py',
           'bt_cover_art_owner.py','bt_cover_art_framer.py','bt_cover_art_responses.py',
           'bt_cover_art_native.py','bt_cover_art_client.py','verify_bt_cover_responses.py',
           'verify_bt_cover_owner.py','verify_bt_cover_csr_bridge.py','verify_bt_cover_attribute.py',
           'patch_bt_cover_attribute.py','patch_usb_seek_completion.py','patch_usb_folders.py',
           'patch_usb_reliability.py','patch_updater_copy_safety.py','inspect_wave_queue.py',
           'inspect_bt_lifecycle.py','inspect_bt_pairing.py','verify_media_responsiveness.py')
    return dict(cases=len(traces),legacy_comparisons=comparisons,traces=traces,binary_input_sha256=BASE_SHA,
                native_slices=[dict(start=hex(lo),end=hex(hi),sha256=hashlib.sha256(
                    original.get_data(lo-original.OPTIONAL_HEADER.ImageBase,hi-lo)).hexdigest()) for lo,hi in NATIVE],
                call_site=dict(address=hex(ticket.SITE),proposed_word=hex(ticket.site_word(raw)),
                               original_bytes=original.get_data(ticket.SITE-original.OPTIONAL_HEADER.ImageBase,8).hex()),
                confirmation_layout=dict(bytes=28,primitive='0x820d',peer=2,scope=3,uid=[4,8],count=12,
                                         data_size=14,data_pointer=16,result=20,supplier=22,data_offset=24),
                instruction_interpretation=True,firmware_patched=False,controller_bound=False,lgu_built=False,
                helpers=[dict(address=hex(r['address']),purpose=r['purpose'],used_bytes=r['recipe']['used_bytes'],
                              bytes_hex=r['raw'].hex(),assembly=r['recipe'],relocation_recipe=r['relocations']) for r in assembled()],
                limits=['Original request handler/factory/pending-record/final-post instructions execute; profile lookup/support/list operations/copy/serialization/delivery remain fixtures',
                        'CFM constructor status/supplier/offset fields are observed; successful raw metadata payload and continuation behavior remain untraced',
                        'One static slot: BEGIN before posting; queued request retains ownership until original profile handler consumes it',
                        'Exact response object identity is drained before slot reuse; invalidation alone must not reset pending identity',
                        'Artwork/profile callbacks must share serialized CSR segment 0 and remain non-reentrant',
                        'No real request-posting/controller lifecycle/payload parsing/shutdown integration is wired to this slot',
                        'The original seven-attribute serializer needs its separately verified attribute-8 patch before any such request is used on firmware',
                        'No PE placement/relocation/unwind, Bluetooth transport, AppMain image path or phone support is validated'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--report',type=Path,required=True)
    args=parser.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'],legacy_comparisons=len(result['legacy_comparisons']),controller_bound=False),indent=2))
