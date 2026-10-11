"""Interpret complete native artwork session flow with CSR instruction slices.

Metadata dispatch, clock delivery and GUI callbacks are fixtures. Publication uses
a real host JPEG decoder; no CE decoder, firmware task or physical unit is run.
"""
import argparse
from functools import lru_cache
import hashlib
from io import BytesIO
import json
from pathlib import Path
import struct

import pefile
from PIL import Image as PillowImage

import bt_cover_art_controller as controller
import bt_cover_art_task as task
import bt_cover_art_owner as owner
import bt_cover_art_framer as framer
import bt_cover_art_responses as responses
import bt_cover_art_client as host
from patch_bt_cover_attribute import BASE_SHA
from verify_bt_cover_task import TaskFixture, HOLDER, registration
from verify_bt_cover_responses import handshake, packet, sequence, fixed, CID as OBEX_CID
from inspect_bt_pairing import put, data
from verify_media_responsiveness import call

ROOT=Path(__file__).resolve().parents[1]
CHANNEL, TRACK, NOW = 7, 11, 100


@lru_cache(maxsize=1)
def assembled():return controller.assembled()+responses.assembled()


@lru_cache(maxsize=1)
def jpeg():
    stream=BytesIO()
    PillowImage.new('RGB',(200,200),(30,50,70)).save(stream,format='JPEG',quality=70)
    raw=stream.getvalue();host.decode_thumbnail(raw)
    return raw


def attributes(handle=b'0000001'):
    return b'\x01'+struct.pack('>IHH',8,106,len(handle))+handle


class SessionFixture(TaskFixture):
    def __init__(self, original, metadata_accept=True, image_accept=True, fail_allocation=None):
        super().__init__(original)
        replaced={r['address'] for r in assembled()}
        self.pe.helpers=[r for r in self.pe.helpers if r['address'] not in replaced]+assembled()
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in assembled()]
        self.hooks.pop(framer.PACKET)
        self.hooks.update({controller.MALLOC:self.allocate,controller.REQUEST_METADATA:self.request_metadata,
                           controller.PUBLISH:self.publish,controller.CLEAR:self.clear_image})
        self.metadata_accept,self.image_accept=metadata_accept,image_accept
        self.fail_allocation=fail_allocation
        self.metadata_requests,self.images,self.clears=[],[],[]
        self.visible=None

    def allocate(self,m):
        size=m.reg[4]
        assert 0<size<=host.MAX_IMAGE
        self.allocations.append(size)
        eligible=size in (host.MAX_IMAGE,controller.TASK_SIZE) or task.SEND<=m.pc<task.SEND+0x400
        if size==self.fail_allocation and eligible:
            self.fail_allocation=None  # Inject one selected failure; native constructors retain fatal OOM.
            return 0
        if size==host.MAX_IMAGE:
            # Owned, strict-bounds zeroed sparse fixture; avoids 128 KiB setup per case.
            address=self.next_heap;self.next_heap+=size
            self.heap[address]=(size,True)
            return address
        return self.new(bytes([0xcc])*size)

    def request_metadata(self,m):
        assert m.reg[4]==self.state
        self.metadata_requests.append(tuple(m.reg[5:7]))
        return int(self.metadata_accept)

    def publish(self,m):
        state,channel,track,pointer=m.reg[4:8]
        assert state==self.state
        assert self.phase==controller.READY and self.field(36)==1
        length=m.read(m.reg[29]+0x10)
        raw=data(m,pointer,length)
        try:host.decode_thumbnail(raw)
        except Exception:return 0
        self.images.append((channel,track,raw))
        if self.image_accept:self.visible=(channel,track,bytes(raw))
        return int(self.image_accept)

    def clear_image(self,m):
        assert m.reg[4]==self.state and self.field(36)==0
        body=self.field(64)
        assert body and self.heap[body][1], 'Clear must precede body release'
        self.clears.append(tuple(m.reg[5:7]))
        self.visible=None
        return 1

    def field(self,offset):return self.read(self.state+controller.OFFSET+offset)

    @property
    def phase(self):return self.field(0)

    def prepare(self,channel=CHANNEL,track=TRACK,now=NOW):
        return call(self,controller.PREPARE,[self.state,channel,track,now])

    def tick(self,now):return call(self,controller.TICK,[self.state,now])

    def flush(self):return call(self,controller.FLUSH,[self.state])

    def credit(self,context=None,result=0,supplier=12):
        self.enqueue(0x8204,context=self.read(self.state+30,2) if context is None else context,
                     result=result,supplier=supplier)
        self.handle()

    def metadata(self,raw=None,channel=CHANNEL,track=TRACK):
        raw=attributes() if raw is None else raw
        source=self.new(raw) if raw else 0
        status=call(self,controller.METADATA,[self.state,channel,track,source],stack_args=(len(raw),))
        if source:
            self.reg[4]=source;self.free(self)
        return status

    def receive(self,raw):
        self.enqueue(0x8205,payload=raw);self.handle()

    def begin(self,now=NOW,mtu=1024,queue=22):
        self.ready(queue=queue);assert self.prepare(now=now);assert self.open()
        assert self.phase==controller.OPENING
        self.connected(mtu=mtu)
        assert self.phase==controller.CONNECT and self.field(32)==1
        assert self.requests[-1]['bytes_hex']==host.connect_request().hex()

    def handshake(self,credit=True):
        self.receive(handshake())
        assert self.phase==controller.META
        assert self.metadata_requests==[(CHANNEL,TRACK)]
        if credit:self.credit()

    def get(self,credit=True):
        self.begin();self.handshake(credit)
        assert self.metadata();assert self.flush()
        if credit:
            assert self.phase==controller.GET and self.field(32)==1
            assert self.requests[-1]['bytes_hex']==host.thumbnail_request(OBEX_CID,'0000001',1024).hex()

    def finish_image(self,raw=None):
        raw=jpeg() if raw is None else raw
        chunks=[raw[i:i+900] for i in range(0,len(raw),900)]
        for index,chunk in enumerate(chunks):
            final=index==len(chunks)-1
            reply=packet(0xa0 if final else 0x90,(fixed(0xc3,len(raw)) if index==0 else b'')
                         +sequence(0x49 if final else 0x48,chunk))
            self.receive(reply)
            if not final:
                assert self.phase==controller.GET and self.field(28)==8 and self.field(32)==0
                previous_start=self.field(20)
                self.credit()
                assert self.field(20)==previous_start and self.field(32)==1
                assert self.requests[-1]['bytes_hex']==(b'\x83\0\x08'+fixed(0xcb,OBEX_CID)).hex()


def verify(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    original=pefile.PE(data=raw)
    traces=[]

    def record(name,m):
        phase=m.phase if m.state else None
        body=m.field(64) if m.state else 0
        images=[dict(channel=c,track=t,bytes=len(b),sha256=hashlib.sha256(b).hexdigest()) for c,t,b in m.images]
        sends=[r['bytes_hex'] for r in m.requests if r['kind']=='send']
        m.deinit()
        assert not m.visible and (not body or not m.heap[body][1])
        traces.append(dict(case=name,phase_before_shutdown=phase,metadata=m.metadata_requests,
                           images=images,clears=m.clears,sends=sends,steps=m.steps))

    m=SessionFixture(original);m.get();m.finish_image()
    assert m.phase==controller.READY and m.visible==(CHANNEL,TRACK,jpeg())
    record('complete_native_flow_real_jpeg',m)
    registry=registration(original,True,0)
    m=SessionFixture(original);m.begin(queue=registry['artwork_queue']);m.handshake();m.metadata();m.flush();m.finish_image()
    assert m.visible==(CHANNEL,TRACK,jpeg()) and registry['artwork_queue']==20
    record('registered_queue_complete_flow',m)
    m=SessionFixture(original,fail_allocation=controller.TASK_SIZE)
    assert m.init()==0 and not m.requests
    record('initial_allocation_failure',m)
    m=SessionFixture(original);m.begin();m.handshake()
    m.credit();m.fail_allocation=43
    assert m.metadata() and not m.flush() and m.phase==controller.FAILED
    record('get_copy_allocation_failure',m)
    m=SessionFixture(original,fail_allocation=26);m.ready();m.prepare();m.open();m.connected()
    assert m.phase==controller.FAILED and not any(r['kind']=='send' for r in m.requests)
    record('connect_copy_allocation_failure',m)
    m=SessionFixture(original);m.get();m.finish_image()
    m.enqueue(0x8206);m.handle()
    assert m.phase==controller.OFF and not m.visible and m.clears==[(CHANNEL,TRACK)]
    record('remote_disconnect_clears_and_frees_image',m)
    m=SessionFixture(original);m.ready()
    for entry,args in ((controller.CONNECTED,[0]),(controller.PROCESS,[0,0,0]),
                       (controller.METADATA,[0,0,0,0]),(controller.SELECT,[0,0,0,0]),
                       (controller.TICK,[0,0]),(controller.FLUSH,[0]),(controller.PREPARE,[0,0,0,0])):
        assert not call(m,entry,args,stack_args=(0,))
    record('null_owner_refusals',m)
    for split in range(1,len(handshake())):
        m=SessionFixture(original);m.begin()
        raw=handshake();m.receive(raw[:split]);m.receive(raw[split:])
        assert m.phase==controller.META and m.metadata_requests==[(CHANNEL,TRACK)]
        record('handshake_split_'+str(split),m)
    m=SessionFixture(original);m.get(False)
    sends=len(m.requests)
    assert m.field(28)==43 and m.field(32)==0
    assert m.flush() and len(m.requests)==sends
    m.credit(context=0,result=1)
    assert m.phase==controller.GET and m.field(28)==43 and m.field(32)==0
    m.credit(context=1)
    assert m.field(28)==0 and m.field(32)==1 and len(m.requests)==sends+1
    record('deferred_get_waits_matching_handshake_credit',m)
    m=SessionFixture(original);m.get(False)
    m.receive(packet(0xa0,sequence(0x49,b'unsolicited')))
    assert m.phase==controller.FAILED and not m.images
    record('reject_get_response_before_request_send',m)

    for raw in (b'\0',attributes(b'000000x'),attributes(b'000000'),b'',attributes()+b'x'):
        m=SessionFixture(original);m.begin();m.handshake()
        status=m.metadata(raw)
        assert status==int(raw==b'\0')
        assert m.phase==(controller.READY if raw==b'\0' else controller.FAILED)
        assert m.field(64)==0
        record('metadata_'+raw.hex(),m)
    for channel,track in ((CHANNEL-1,TRACK),(CHANNEL,TRACK-1),(CHANNEL+1,TRACK)):
        m=SessionFixture(original);m.begin();m.handshake()
        before=data(m,m.state+controller.OFFSET,controller.SIZE)
        assert not m.metadata(channel=channel,track=track)
        assert data(m,m.state+controller.OFFSET,controller.SIZE)==before
        record(f'stale_metadata_{channel}_{track}',m)
    m=SessionFixture(original);m.get()
    before=data(m,m.state+controller.OFFSET,controller.SIZE)
    assert not m.metadata() and data(m,m.state+controller.OFFSET,controller.SIZE)==before
    record('duplicate_metadata_during_get_is_ignored',m)
    m=SessionFixture(original);m.begin();m.handshake()
    call(m,owner.STOP,[m.state])
    assert not m.metadata() and not m.field(64)
    m.flush();assert m.phase==controller.FAILED
    record('metadata_refused_on_closing_channel',m)
    m=SessionFixture(original,fail_allocation=host.MAX_IMAGE);m.begin();m.handshake()
    assert not m.metadata() and m.phase==controller.FAILED
    record('body_allocation_failure',m)
    m=SessionFixture(original);m.get();m.credit()
    m.fail_allocation=8
    m.receive(packet(0x90,sequence(0x48,b'x')))
    assert m.phase==controller.FAILED and m.field(64)==0
    record('continuation_copy_allocation_failure',m)
    for result,supplier in ((1,12),(0,6)):
        m=SessionFixture(original);m.get();m.credit(result=result,supplier=supplier)
        assert m.phase==controller.FAILED and m.field(64)==0
        record(f'failed_send_{result}_{supplier}',m)
    m=SessionFixture(original,metadata_accept=False);m.begin();m.receive(handshake())
    assert m.phase==controller.FAILED
    record('metadata_dispatch_rejection',m)
    for accept,raw in ((False,None),(True,b'not a jpeg')):
        m=SessionFixture(original,image_accept=accept);m.get();m.finish_image(raw)
        assert m.phase==controller.FAILED and not m.visible and m.field(64)==0
        assert m.clears==[(CHANNEL,TRACK)]
        record('publication_or_decode_rejection_'+str(accept),m)
    m=SessionFixture(original);m.get();m.finish_image()
    m.receive(packet(0xa0,sequence(0x49,b'x')))
    assert m.phase==controller.FAILED and m.clears==[(CHANNEL,TRACK)]
    record('unsolicited_response_after_completion',m)

    for initial in (controller.OPENING,controller.CONNECT,controller.META,controller.GET,controller.READY):
        m=SessionFixture(original)
        if initial==controller.OPENING:
            m.ready();assert m.prepare();assert m.open()
        elif initial==controller.CONNECT:m.begin()
        elif initial==controller.META:m.begin();m.handshake()
        else:
            m.get()
            if initial==controller.READY:m.finish_image()
        result=call(m,controller.SELECT,[m.state,CHANNEL,TRACK+1,NOW+10])
        if initial in (controller.META,controller.READY):
            assert result==1 and m.phase==controller.META
            assert m.metadata_requests[-1]==(CHANNEL,TRACK+1)
            assert m.field(40)==OBEX_CID and m.field(44)==1024
            assert not m.metadata(track=TRACK)
            assert m.metadata(track=TRACK+1);m.flush()
        else:
            assert result==0 and m.phase==controller.FAILED
            assert m.field(64)==0
        record('track_change_'+str(initial),m)
    for track in (0,TRACK-1,TRACK):
        m=SessionFixture(original);m.get();before=data(m,m.state+controller.OFFSET,controller.SIZE)
        result=call(m,controller.SELECT,[m.state,CHANNEL,track,NOW])
        assert result==int(track==TRACK) and data(m,m.state+controller.OFFSET,controller.SIZE)==before
        record('same_or_old_track_'+str(track),m)
    m=SessionFixture(original);m.get();m.finish_image()
    call(m,controller.CANCEL,[m.state]);call(m,controller.CANCEL,[m.state])
    assert m.clears==[(CHANNEL,TRACK)] and sum(k=='disconnect' for k,_ in m.operations)==1
    assert not m.prepare(channel=CHANNEL+1)
    m.enqueue(0x8206);m.handle()
    assert m.phase==controller.OFF
    assert not m.prepare(channel=CHANNEL)
    assert m.prepare(channel=CHANNEL+1,track=TRACK+1)
    record('cancel_clear_once_close_ack_before_new_generation',m)
    m=SessionFixture(original);m.get();m.receive(packet(0x90,sequence(0x48,b'partial')))
    body=m.field(64)
    assert not call(m,controller.SELECT,[m.state,CHANNEL,TRACK+1,NOW+1])
    assert m.phase==controller.FAILED and not m.heap[body][1] and not m.field(64)
    assert not m.metadata(track=TRACK) and not m.images
    record('track_change_discards_partial_body',m)
    for phase in (controller.OFF,controller.FAILED):
        m=SessionFixture(original);m.ready()
        if phase==controller.FAILED:
            m.prepare();call(m,controller.CANCEL,[m.state])
        before=data(m,m.state+controller.OFFSET,controller.SIZE)
        assert not call(m,controller.SELECT,[m.state,m.field(8),m.field(12),NOW])
        assert data(m,m.state+controller.OFFSET,controller.SIZE)==before
        record('closed_session_rejects_selection_'+str(phase),m)

    for phase,timeout in ((controller.OPENING,2000),(controller.CONNECT,2000),(controller.META,3000),(controller.GET,10000)):
        for elapsed in (timeout-1,timeout):
            m=SessionFixture(original)
            if phase==controller.OPENING:
                m.ready();m.prepare();m.open()
            elif phase==controller.CONNECT:m.begin()
            elif phase==controller.META:m.begin();m.handshake()
            else:m.get()
            assert m.tick(NOW+elapsed)==int(elapsed<timeout)
            assert m.phase==(phase if elapsed<timeout else controller.FAILED)
            record(f'deadline_{phase}_{elapsed}',m)
    m=SessionFixture(original);m.begin(now=0xfffffff0)
    assert m.tick(0x10) and m.phase==controller.CONNECT
    assert not m.tick((0xfffffff0+2000)&0xffffffff)
    record('millisecond_clock_wrap',m)
    m=SessionFixture(original);m.begin()
    assert not m.tick(NOW-1) and m.phase==controller.FAILED
    record('clock_reversal',m)
    m=SessionFixture(original);m.get()
    assert m.tick(NOW+9000)
    m.receive(packet(0x90,sequence(0x48,b'x')));m.credit()
    assert m.field(20)==NOW
    assert not m.tick(NOW+10000)
    record('continuation_does_not_extend_deadline',m)
    m=SessionFixture(original);m.ready();m.prepare();m.open()
    assert not m.tick(NOW+2000)
    assert m.read(m.state)==owner.CANCELLED
    m.connected()
    assert m.phase==controller.FAILED and m.read(m.state)==owner.CLOSING
    assert not any(r['kind']=='send' for r in m.requests)
    record('late_open_after_timeout_is_closed',m)
    m=SessionFixture(original);m.get();m.finish_image()
    before=len(m.operations);m.deinit()
    assert all(kind not in ('ack','disconnect','post') for kind,_ in m.operations[before:])
    assert m.clears==[(CHANNEL,TRACK)] and not m.visible
    traces.append(dict(case='quiescent_shutdown_disposes_image_without_post',steps=m.steps))

    # Compare the original fatal wrapper with the new direct allocation path.
    m=SessionFixture(original);m.hooks.pop(0x85b70)
    m.ranges.append((0x85b70,0x85bb8))
    fatal=[]
    m.hooks[controller.MALLOC]=lambda _:0
    m.hooks[0x85f50]=lambda vm:fatal.append(tuple(vm.reg[4:7])) or 0
    assert call(m,0x85b70,[host.MAX_IMAGE])==0 and len(fatal)==1
    # The second route executes the proposed initial allocator call, no wrapper.
    call(m,task.INIT,[HOLDER])
    assert len(fatal)==1 and not m.read(HOLDER) and not m.requests
    allocator_reference=dict(original_fatal_calls=len(fatal),new_initial_extra_fatal_calls=0)
    traces.append(dict(case='original_fatal_wrapper_vs_new_checked_initial_allocation',steps=m.steps))

    names=('bt_cover_art_controller.py','verify_bt_cover_controller.py','bt_cover_art_task.py',
           'bt_cover_art_owner.py','bt_cover_art_framer.py','bt_cover_art_responses.py','bt_cover_art_native.py',
           'bt_cover_art_client.py','verify_bt_cover_task.py','verify_bt_cover_responses.py',
           'verify_bt_cover_owner.py','verify_bt_cover_csr_bridge.py','verify_bt_cover_attribute.py',
           'patch_bt_cover_attribute.py','patch_usb_seek_completion.py','patch_usb_folders.py',
           'patch_usb_reliability.py','patch_updater_copy_safety.py','inspect_wave_queue.py',
           'inspect_bt_lifecycle.py','inspect_bt_pairing.py','verify_media_responsiveness.py')
    return dict(cases=len(traces),traces=traces,binary_input_sha256=BASE_SHA,task_bytes=controller.TASK_SIZE,
                allocator_reference=allocator_reference,
                allocator_slices=[dict(start=hex(lo),end=hex(hi),sha256=hashlib.sha256(
                    original.get_data(lo-original.OPTIONAL_HEADER.ImageBase,hi-lo)).hexdigest()) for lo,hi in
                    ((0x85b70,0x85bb8),(0x85bb8,0x85bdc),(0x8ad6c,0x8ad8c),(0x85f50,0x85f84))],
                jpeg_fixture=dict(bytes=len(jpeg()),sha256=hashlib.sha256(jpeg()).hexdigest()),
                instruction_interpretation=True,firmware_patched=False,task_installed=False,lgu_built=False,
                helpers=[dict(address=hex(r['address']),purpose=r['purpose'],used_bytes=r['recipe']['used_bytes'],
                              bytes_hex=r['raw'].hex(),assembly=r['recipe'],relocation_recipe=r['relocations']) for r in controller.assembled()],
                limits=['Native controller/task/owner/framer/codecs/parsers execute; scheduler/allocations/posting remain fixtures',
                        'Clock samples, metadata dispatch and metadata tokens are externally delivered fixtures',
                        'Publication validates real JPEG on host; CE decoder, AppMain transfer/painting are not installed',
                        'Callbacks must not reenter; borrowed publication bytes must be copied before returning',
                        'Native capability/PSM/security selection, AVRCP response correlation and timer delivery remain unwired',
                        'Generation counters never wrap/reuse; external owner must enforce fresh channel/track tickets',
                        'New state/body/send-copy allocations call the paired underlying allocator with null checks; CRT remains a fixture',
                        'Original wrapper calls a fixture fatal handler on null; existing CSR constructors retain their fatal OOM contract',
                        'Interpreter placements only; no PE loader/relocation/unwind, hardware or Spotify testing'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in names})


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--report',type=Path,required=True)
    args=parser.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'],task_bytes=result['task_bytes'],task_installed=False),indent=2))
