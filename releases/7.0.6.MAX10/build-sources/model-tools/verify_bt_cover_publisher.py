"""Interpret controller body handoff, pointer-free wakes and Blue GUI publication.

The existing selected-track/channel/collector/lifecycle instructions execute.
Window delivery, CSR thread join, CRT allocation/free and CE APIs are fixtures.
AppMain reads an independent owned snapshot; this is not native installation.
"""
import argparse
from collections import deque
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_controller as controller
import bt_cover_art_lifecycle as lifecycle
import bt_cover_art_publisher as publisher
import bt_cover_art_transfer as transfer
from inspect_bt_pairing import data,put
from verify_bt_cover_lifecycle import Source
from verify_bt_cover_metadata import reply
from verify_bt_cover_controller import jpeg
from verify_bt_cover_transfer import World,Process,API,VIEWS,OUTPUT
from verify_bt_cover_image import Decoder,BITMAP
from verify_media_responsiveness import call,STACK

ROOT=Path(__file__).resolve().parents[1]
WINDOW=0x123456


@lru_cache(maxsize=1)
def helpers():return publisher.assembled()


class Publisher(Source):
    def __init__(self,original,world):
        self.world,self.module,self.config=world,'Blue.exe',publisher.CONFIG
        self.trigger=None
        self.window_messages=deque()
        self.window_effects=[]
        self.fail_post=self.fail_window_timer=self.fail_descriptor=False
        self.body_reads_on_owner=0
        self.body_writes_on_owner=0
        self.body_pointer=0
        self.worker_joined=False
        self.join_result=0
        self.fail_slot_claim=False
        super().__init__(original)
        self.pe.helpers=helpers()
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in helpers()]
        self.ranges += [(0x240c8,0x241e0)]
        self.patches[publisher.JOIN_SITE]=(3<<26)|(publisher.JOIN_WAIT>>2)
        self.allowed += [(publisher.PENDING,publisher.PENDING+publisher.STATE_SIZE),
                         (publisher.THREAD_HANDLE,publisher.THREAD_HANDLE+4),(0x20e350,0x20e354)]
        for at,raw in transfer.initial_data(self.module).items():
            self.allowed.append((at,at+len(raw)));put(self,at,raw)
        put(self,publisher.PENDING,bytes(publisher.STATE_SIZE))
        for name,iat in self.config.api.items():
            self.allowed.append((iat,iat+4));self.write(iat,API[name])
            self.hooks[API[name]]=lambda m,name=name:self.api(m,name)
        for at,hook,trap in ((publisher.POST_MESSAGE,self.post_window,0x46000000),
                             (publisher.SET_TIMER,self.start_window_timer,0x46000010),
                             (publisher.KILL_TIMER,self.stop_window_timer,0x46000020)):
            self.allowed.append((at,at+4));self.write(at,trap);self.hooks[trap]=hook
        self.hooks.pop(lifecycle.IMAGE_CALLBACK)
        self.hooks.pop(controller.CLEAR)
        self.hooks[publisher.ORIGINAL_WINDOW]=self.original_window
        self.write(publisher.THREAD_HANDLE,world.new(self,'thread'))
        self.write(0x20e350,0x46000030)
        self.hooks[0x46000030]=lambda m:self.request_exit()

    def shared_at(self,at,size):
        start=VIEWS[self.module]
        if start<=at and at+size<=start+transfer.SIZE:
            assert self.module in self.world.views and self.world.shared is not None
            return at-start
        return None

    def read(self,at,size=4):
        offset=self.shared_at(at,size)
        if offset is not None:return int.from_bytes(self.world.shared[offset:offset+size],'little')
        if self.body_pointer<=at<self.body_pointer+transfer.MAX_IMAGE and self.body_pointer:
            if publisher.HANDOFF<=self.pc<publisher.HANDOFF+0x1000:self.body_reads_on_owner+=1
        return super().read(at,size)

    def write(self,at,value,size=4):
        offset=self.shared_at(at,size)
        if offset is not None:
            if offset>=transfer.HEADER:
                assert self.current_segment==15,'CSR must not copy an artwork payload'
                self.body_writes_on_owner+=int(self.current_segment!=15)
            self.world.shared[offset:offset+size]=(value&((1<<(size*8))-1)).to_bytes(size,'little')
        else:super().write(at,value,size)
        if self.trigger is not None and self.trigger[0](at):
            callback=self.trigger[1];self.trigger=None;callback()

    def api(self,m,name):
        if name=='compare' and m.reg[4]==publisher.PENDING:
            self.world.trace.append((self.module,'slot_compare'))
            if self.fail_slot_claim and m.reg[5]:self.fail_slot_claim=False;return 0xffffffff
            old=self.read(publisher.PENDING)
            if old==m.reg[6]:self.write(publisher.PENDING,m.reg[5])
            return old
        if name=='wait' and publisher.JOIN_WAIT<=m.pc<publisher.JOIN_WAIT+0x400:
            self.world.checked(self,m.reg[4],'thread');assert m.reg[5]==0xffffffff
            self.window_effects.append('original_thread_wait')
            if self.join_result==0:self.quiesce_worker()
            return self.join_result
        if name in ('mutex','mapping','map','unmap','wait','release','close'):
            assert self.current_segment==15,'Mapping operations belong to the GUI'
        return self.world.invoke(m,name)

    def allocate(self,m):
        if self.fail_descriptor and publisher.HANDOFF<=m.pc<publisher.HANDOFF+0x1000 and m.reg[4]==16:
            self.fail_descriptor=False;return 0
        return super().allocate(m)

    def post_window(self,m):
        assert m.reg[4:8]==[WINDOW,publisher.MESSAGE,0,0]
        assert self.current_segment==0
        self.window_effects.append('post')
        if self.fail_post:return 0
        self.window_messages.append(tuple(m.reg[4:8]))
        return 1

    def start_window_timer(self,m):
        assert m.reg[4:8]==[WINDOW,publisher.TIMER,publisher.INTERVAL,0]
        assert self.current_segment==15
        self.window_effects.append('set_timer')
        return 0 if self.fail_window_timer else publisher.TIMER

    def stop_window_timer(self,m):
        assert m.reg[4:6]==[WINDOW,publisher.TIMER] and self.current_segment==15
        self.window_effects.append('kill_timer')
        return 1

    def original_window(self,m):
        args=tuple(m.reg[4:8]);self.window_effects.append(('original',args))
        if args[1]==2:
            assert self.read(publisher.ALIVE)==0
            self.native_call(0x240c8,[])
        return 0 if args[1] in (1,2) else 0x12340000^args[1]

    def request_exit(self):
        self.window_effects.append('original_exit_request')
        return 0

    def quiesce_worker(self):
        if not self.worker_joined:
            # Thread joining is an OS fixture. Execute the original CSR/task
            # cleanup on a separate register/stack snapshot, retaining the GUI's
            # independently owned descriptor/body until after the join.
            pointer=self.read(publisher.PENDING)
            detached=[pointer,self.read(pointer+8)] if pointer else []
            owned={p:self.heap.pop(p) for p in detached}
            registers=self.reg[:];pc=self.pc;hi,lo=self.hi,self.lo
            stack={at:v for at,v in self.mem.items() if STACK-0x600<=at<STACK+0x80}
            segment=self.current_segment
            try:
                self.current_segment=0;self.drain();self.worker_joined=True
            finally:
                self.heap.update(owned);self.reg[:]=registers;self.pc=pc;self.hi,self.lo=hi,lo
                for at in list(self.mem):
                    if STACK-0x600<=at<STACK+0x80:del self.mem[at]
                self.mem.update(stack);self.current_segment=segment

    def window(self,message,wparam=0,lparam=0):
        segment=self.current_segment;self.current_segment=15
        try:return call(self,publisher.WINDOW_PROC,[WINDOW,message,wparam,lparam],limit=2000000)
        finally:self.current_segment=segment

    def start(self):assert self.window(1)==0

    def tick_gui(self,now=100):
        self.at(now);return self.window(0x113,publisher.TIMER)

    def deliver_window(self):
        while self.window_messages:
            _,message,wp,lp=self.window_messages.popleft();assert self.window(message,wp,lp)==0

    def receive_image(self,raw=None):
        self.select_native();self.connect_native();self.response(reply())
        self.body_pointer=self.field(64)
        self.finish_image(jpeg() if raw is None else raw)

    def stop(self):
        assert self.window(2)==0 and self.worker_joined
        assert not self.read(publisher.PENDING) and not self.read(publisher.ALIVE)
        assert not self.read(publisher.HWND) and not self.read(self.config.state+12)
        self.assert_drained()


def verify(blue_raw,app_raw):
    contract=publisher.contracts(blue_raw)
    originals={'Blue.exe':pefile.PE(data=blue_raw),'AppMain.exe':pefile.PE(data=app_raw)}
    cases=[]
    def pair(start=True):
        w=World();b=Publisher(originals['Blue.exe'],w);a=Process(w,'AppMain.exe',originals['AppMain.exe'])
        if start:b.start()
        assert a.initialize()==1
        return w,b,a
    def record(name,w,b,a,**details):
        row=dict(case=name,api_calls=list(w.trace),window_effects=b.window_effects[:],
                 body_reads_on_owner=b.body_reads_on_owner,body_writes_on_owner=b.body_writes_on_owner,**details)
        assert b.body_reads_on_owner==b.body_writes_on_owner==0
        b.stop();b.deliver_window();a.run_helper('close')
        assert not w.handles and not w.views and w.shared is None and w.owner is None
        cases.append(row)

    w,b,a=pair();b.receive_image();descriptor=b.read(publisher.PENDING);body=b.body_pointer
    assert b.phase==controller.READY and b.field(64)==0
    assert b.heap[descriptor]==(16,True) and b.heap[body][1]
    assert not w.word(16) and not a.copy()
    token=b.read(descriptor);incarnation=b.read(descriptor+4)
    assert b.read(descriptor+8)==body and b.read(descriptor+12)==len(jpeg())
    before=b.operations[:];b.deliver_window()
    assert not b.read(publisher.PENDING) and not b.heap[descriptor][1] and not b.heap[body][1]
    assert a.copy()==1 and data(a,OUTPUT,len(jpeg()))==jpeg() and a.fresh(token)==1
    decoder=Decoder(originals['AppMain.exe'],data(a,OUTPUT,len(jpeg())))
    image=decoder.decode();assert image==BITMAP and a.fresh(token)==1;decoder.finish(image)
    record('native_selection_collection_handoff_gui_copy_app_owned_decode',w,b,a,decode_trace=decoder.trace,
           token=token,incarnation=incarnation)

    w,b,a=pair();b.fail_post=True;b.receive_image()
    assert b.phase==controller.READY and not b.window_messages and b.read(publisher.PENDING)
    b.tick_gui(500);assert not b.read(publisher.PENDING) and a.copy(500)==1
    record('lost_post_recovers_on_window_timer',w,b,a)

    w,b,a=pair();b.receive_image();descriptor=b.read(publisher.PENDING);body=b.body_pointer
    w.owner='AppMain.exe';b.deliver_window()
    assert b.read(publisher.PENDING)==descriptor and b.heap[body][1] and w.owner=='AppMain.exe'
    w.owner=None;b.tick_gui(500)
    assert not b.read(publisher.PENDING) and not b.heap[body][1] and a.copy(500)==1
    record('busy_mapping_retains_one_owned_job_for_timer_retry',w,b,a)

    for mode in ('source_stop_before_drain','disconnect_before_drain','source_stop_after_publish'):
        w,b,a=pair();b.receive_image();body=b.body_pointer
        descriptor=b.read(publisher.PENDING);token=b.read(descriptor)
        if mode=='source_stop_after_publish':b.deliver_window();assert a.copy()==1
        if mode=='disconnect_before_drain':b.disconnect_native();b.handle()
        else:b.command(0x1070505);b.handle()
        assert not w.word(12) and not a.fresh(token)
        b.deliver_window();b.tick_gui(500)
        assert not b.read(publisher.PENDING) and not b.heap[descriptor][1] and not b.heap[body][1]
        record(mode,w,b,a)

    w,b,a=pair();b.receive_image();old=b.read(publisher.PENDING);old_body=b.body_pointer
    # Complete a second controller generation while the old GUI slot is still
    # queued. The serialized controller refuses another descriptor, cancels its
    # current transfer and frees the new body; the old job remains GUI-owned.
    b.select_native(b'87654321')
    assert b.phase==controller.META and b.field(12)==2
    b.profile();b.response(reply());b.credit();new_body=b.field(64);b.body_pointer=new_body
    b.finish_image()
    assert b.phase==controller.FAILED and not b.heap[new_body][1]
    assert b.read(publisher.PENDING)==old and b.heap[old_body][1]
    b.deliver_window();assert not b.heap[old_body][1] and not a.copy()
    record('rapid_track_change_never_queues_a_second_body',w,b,a)

    w,b,a=pair();b.fail_descriptor=True;b.receive_image();body=b.body_pointer
    assert b.phase==controller.FAILED and not b.field(64) and not b.heap[body][1]
    assert not b.read(publisher.PENDING) and not b.window_messages
    record('recoverable_descriptor_allocation_failure',w,b,a)

    w,b,a=pair();b.fail_slot_claim=True;b.receive_image();body=b.body_pointer
    assert not b.fail_slot_claim and b.phase==controller.FAILED
    assert not b.read(publisher.PENDING) and not b.heap[body][1]
    record('failed_slot_claim_restores_controller_body_before_cancellation',w,b,a)

    for status in (0xffffffff,258):
        w,b,a=pair();b.receive_image();descriptor=b.read(publisher.PENDING);body=b.body_pointer
        b.join_result=status;assert b.window(2)==0
        assert not b.worker_joined and b.read(publisher.JOINED)==2
        assert b.read(publisher.PENDING)==descriptor and b.heap[body][1]
        assert b.read(b.config.state+12)==1 and b.module in w.views
        assert b.window(publisher.MESSAGE)==0 and b.read(publisher.PENDING)==descriptor
        assert b.window(2)==0 and b.read(publisher.JOINED)==2
        assert b.read(publisher.PENDING)==descriptor and b.heap[body][1] and b.module in w.views
        # Explicit later successful join permits cleanup; it is not inferred
        # from the original function's unconditional success return value.
        b.write(publisher.THREAD_HANDLE,w.new(b,'thread'));b.join_result=0
        record('failed_native_join_'+hex(status)+'_retains_body_and_mapping',w,b,a)

    for mode in ('mapping_failure','timer_failure'):
        w,b,a=pair(start=False)
        if mode=='mapping_failure':w.fail='mapping'
        else:b.fail_window_timer=True
        b.start();w.fail=None
        assert not b.read(publisher.ALIVE) and not b.read(b.config.state+12)
        assert not any(proc==b.module and kind!='thread' for proc,kind in w.handles.values())
        b.receive_image();assert b.phase==controller.FAILED and not b.read(publisher.PENDING)
        record(mode+'_does_not_change_original_window_result',w,b,a)

    for when in ('queued','published','busy'):
        w,b,a=pair();b.receive_image();body=b.body_pointer
        if when=='published':b.deliver_window()
        if when=='busy':w.owner='AppMain.exe';b.deliver_window();w.owner=None
        record('shutdown_'+when+'_joins_worker_before_body_and_view_cleanup',w,b,a)
        assert not b.heap[body][1]
        # Pointer-free stale wakeups/ticks after shutdown never read a freed body.
        assert b.window(publisher.MESSAGE)==b.tick_gui(600)==0

    w,b,a=pair();b.receive_image();b.deliver_window();token=w.word(12)
    b.tick_gui(4000);assert a.fresh(token,9000)==1 and not a.fresh(token,9001)
    b.current_segment=0;call(b,controller.CLEAR,[b.state,1,1])
    old=w.word(24);b.tick_gui(4500)
    assert w.word(24)==old and not b.read(publisher.DISPLAY_TOKEN) and not a.fresh(token,4500)
    record('heartbeat_is_current_and_stops_after_invalidation',w,b,a)

    w,b,a=pair()
    for message,wp,lp in ((0x8070,0x1234,0x5678),(0x4a,0x1111,0x2222),(0x113,0x19,0x4444),(0x82f0,5,6)):
        before=len(b.window_effects)
        assert b.window(message,wp,lp)==0x12340000^message
        assert b.window_effects[before:]==[('original',(WINDOW,message,wp,lp))]
    assert b.window(publisher.MESSAGE,0xdeadbeef,0xdeadbeef)==0
    record('legacy_messages_preserve_arguments_and_return_values',w,b,a)

    w,b,a=pair();b.receive_image();token=w.word(12)
    # Cancellation after the GUI's initial TOUCH but while it copies the body
    # uses a distinct serialized-owner VM's InterlockedExchange operation.
    aux=Process(w,'Blue.exe',originals['Blue.exe'])
    aux.setup=True;put(aux,aux.config.state,data(b,b.config.state,transfer.CONTEXT_SIZE));aux.setup=False
    b.trigger=(lambda at:at==VIEWS[b.module]+transfer.HEADER+17,lambda:aux.invalidate())
    b.deliver_window()
    assert b.trigger is None and not b.read(publisher.PENDING) and not a.fresh(token) and not a.copy()
    record('owner_invalidation_during_gui_copy_retires_without_publication',w,b,a)

    return dict(cases=len(cases),traces=cases,contracts=contract,
                helpers=[{k:v for k,v in r.items() if k!='raw'} for r in helpers()
                         if r.get('name','').startswith('image_')],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Original selected-track, channel, collector and source/disconnect cleanup execute in the MIPS interpreter',
                        'Original StopBtMain wait/call/close instructions execute; window dispatch/queue/timer, actual thread completion, CRT allocation/free and all named CE APIs are fixtures',
                        'Controller gives one immutable completed body to the GUI; no body copying or named-mutex wait runs on the owner',
                        'Busy slots refuse another artwork generation rather than building a body queue; a future track change can try again',
                        'Cleanup requires the original thread wait to return WAIT_OBJECT_0; failed waits retain owned storage/views until a proved join or process teardown',
                        'AppMain worker/painting and final PE/LGU installation remain open'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_publisher.py','verify_bt_cover_publisher.py','bt_cover_art_transfer.py',
                              'verify_bt_cover_transfer.py','bt_cover_art_lifecycle.py','verify_bt_cover_lifecycle.py',
                              'bt_cover_art_controller.py','verify_bt_cover_controller.py','bt_cover_art_image.py',
                              'verify_bt_cover_image.py','verify_bt_cover_binding.py','verify_bt_cover_metadata.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--blue',type=Path,required=True);p.add_argument('--app',type=Path,required=True)
    p.add_argument('--report',type=Path,required=True);args=p.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    report=verify(args.blue.read_bytes(),args.app.read_bytes());args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(report,indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=report['cases'],executable_written=False,lgu_built=False),indent=2))
