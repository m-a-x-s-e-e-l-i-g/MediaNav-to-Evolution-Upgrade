"""Interpret native source commands, external-thread posts and disconnects.

Original GUI dispatch/source flags, CSR MessagePut queue linking/locking route,
profile CM dispatch/lookup/state updates and native peer destruction execute.
OS locks/events/timers, filters, callback construction, wire and GUI images are
fixtures. No firmware is written or installed.
"""
import argparse
from collections import deque
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_binding as binding
import bt_cover_art_controller as controller
import bt_cover_art_discovery as discovery
import bt_cover_art_lifecycle as lifecycle
import bt_cover_art_metadata_ticket as ticket
import bt_cover_art_selection as selection
import bt_cover_art_task as task
import bt_cover_art_owner as owner
from inspect_bt_pairing import data, put
from verify_bt_cover_binding import Bound
from verify_bt_cover_controller import jpeg
from verify_bt_cover_metadata import PROFILE, reply
from verify_bt_cover_selection import HOLDER as PROFILE_HOLDER, CID
from verify_bt_cover_responses import packet, fixed, sequence, handshake
from verify_bt_cover_task import HOLDER, SCHED
from verify_bt_cover_timers import TimerFixture
from verify_media_responsiveness import call
from patch_bt_cover_attribute import BASE_SHA

ROOT=Path(__file__).resolve().parents[1]
MANAGER,AUDIO,GUI_INPUT,WINDOW,QUEUES=0x49000000,0x49001000,0x49002000,0x49003000,0x49004000
NATIVE=[(0x31634,0x31718),(0x2efe0,0x2f28c),(0x1816c,0x181e0),
        (0x181e0,0x18220),(0x18220,0x18234),(0x18234,0x1824c),
        (0x1824c,0x18260),(0x18260,0x18274),
        (0x1cb6c,0x1ccac),(0x1ccac,0x1cdf8),(0x1ee0c,0x1ef64),(0x1f11c,0x1f164),(0x20a08,0x20a50),
        (0x84ec8,0x84ee8),(0x83efc,0x841a0),
        (0x51b74,0x51e34),(0x5675c,0x567dc),(0x567dc,0x56854),
        (0x8145c,0x81478),(0x814a0,0x8151c),(0x81598,0x8161c),
        (0x6a630,0x6a6a4),(0x6a8d8,0x6a968),(0x6a9d8,0x6aa30),(0x6aa30,0x6aaa8),
        (0x818ac,0x818e8),(0x818e8,0x81940)]


@lru_cache(maxsize=1)
def assembled():return lifecycle.assembled()


class Source(Bound):
    def __init__(self,original,enabled=True):
        self.queue_events,self.filter_calls,self.gui_effects,self.cm_effects=[],[],[],[]
        self.fail_wake_alloc=False
        self.lifecycle_ready=False
        self.publish_interleave=False
        super().__init__(original)
        self.pe.helpers=assembled()
        self.ranges+=NATIVE+[(r['address'],r['address']+len(r['raw'])) for r in assembled()]
        self.allowed += [(lifecycle.STATE,lifecycle.STATE+4),(lifecycle.MANAGER_GLOBAL,lifecycle.MANAGER_GLOBAL+4),
                         (MANAGER,MANAGER+0x290),(AUDIO,AUDIO+0x140),(GUI_INPUT,GUI_INPUT+20),
                         (WINDOW,WINDOW+4),(QUEUES,QUEUES+21*12),(0x31670,0x31690),
                         (lifecycle.DISCONNECT_TABLE,lifecycle.DISCONNECT_TABLE+4),(0x1030e0,0x103110)]
        for at,n in ((MANAGER,0x290),(AUDIO,0x140),(GUI_INPUT,20),(WINDOW,4),(QUEUES,21*12)):
            put(self,at,bytes(n))
        self.write(lifecycle.MANAGER_GLOBAL,MANAGER)
        self.write(MANAGER+0x268,AUDIO)
        self.write(MANAGER+0x26c,0x48000000)
        self.write(AUDIO+0x21,1,1)
        self.flags(1,1)
        self.write(lifecycle.STATE,2)
        self.write(WINDOW,0x123456)
        self.write(SCHED+0x66,21,2);self.write(SCHED+0x68,1,1)
        self.write(SCHED+0x18,QUEUES)
        put(self,0x31670,original.get_data(0x31670-original.OPTIONAL_HEADER.ImageBase,32))
        self.write(lifecycle.DISCONNECT_TABLE,lifecycle.DISCONNECT if enabled else lifecycle.ORIGINAL_DISCONNECT)
        if enabled:self.patches[lifecycle.GUI_SITE]=lifecycle.sites(original.__data__)[lifecycle.GUI_SITE]
        self.hooks.update({0x1ed70:lambda _:0x48000000,0x19410:lambda _:AUDIO,
                           0x259f8:lambda _:0x49100000,0x33304:lambda _:WINDOW,
                           0x8a7c0:lambda _:0,0x34264:lambda _:0,
                           0x8a7d0:self.kill_timer,0x8a7e0:self.set_timer,
                           0x25a5c:self.filter,0x31f48:self.focus,0x31f40:lambda _:1,
                           0x207f4:self.play,0x87b80:self.lock,0x87bbc:self.unlock,0x87a94:self.signal,
                           0x50e0c:self.release_channel,0x56ebc:self.app_disconnected,
                           0x566a4:lambda _:0})
        self.hooks.pop(controller.PUBLISH)
        self.hooks[lifecycle.IMAGE_CALLBACK]=self.publish
        # Native init/DEINIT execute with lifecycle globals already mapped.
        # The profile peer remains alive; this replaces only the fresh task owner.
        self.lifecycle_ready=True
        self.enter_queue()
        call(self,task.DEINIT,[HOLDER])
        assert self.read(lifecycle.STATE)==2 and not self.read(HOLDER)
        assert self.init(queue=20)
        assert self.read(lifecycle.STATE)==2
        self.enqueue(0x8200,psm=0x1001);self.handle()
        assert self.read(self.state+24)==2 and self.read(lifecycle.STATE)==1
        self.write(PROFILE+0x90,0x567dc)  # Original peer-list destructor callback.
        # Retained pending-list initialization, allocation/linking, status setter
        # and destructor now execute, including the failure CFM on disconnect.
        put(self,0x1030e0,original.get_data(0x1030e0-original.OPTIONAL_HEADER.ImageBase,48))
        self.hooks.pop(0x814a0)
        self.hooks.pop(0x6a8d8)
        self.hooks.pop(0x81598)
        call(self,0x6aa30,[self.peer+0xc8])
        self.write(self.peer+0xc8,0x106,2)

    def allocate(self,m):
        if self.fail_wake_alloc and lifecycle.WAKE<=m.pc<lifecycle.WAKE+0x200 and m.reg[4]==24:
            self.fail_wake_alloc=False
            return 0
        return super().allocate(m)

    def flags(self,focus,output):
        self.write(AUDIO+0x11c,focus,1);self.write(AUDIO+0x11d,output,1)

    def word(self,pc):
        if pc==controller.PUBLISH and self.publish_interleave:
            # A Windows GUI-thread store can occur after the owning pre-pump
            # checked the flags but before publication. Execute the real guard.
            self.publish_interleave=False
            self.flags(0,0)
        return super().word(pc)

    def kill_timer(self,m):
        self.gui_effects.append(('kill_timer',tuple(m.reg[4:6])))
        return 1

    def set_timer(self,m):
        self.gui_effects.append(('set_timer',tuple(m.reg[4:8])))
        return m.reg[5]

    def filter(self,m):
        assert m.reg[4:6]==[0x49100000,AUDIO]
        self.filter_calls.append(m.reg[6])
        return 1

    def focus(self,m):
        assert m.reg[4:6]==[MANAGER+0x10,1]
        self.gui_effects.append(('focus',tuple(m.reg[4:6])))
        return 0

    def play(self,m):
        self.gui_effects.append(('original_play',tuple(m.reg[4:8])))
        return 0

    def lock(self,m):
        assert m.reg[4]==SCHED+0x1c
        self.queue_events.append('lock')
        return 0

    def unlock(self,m):
        assert m.reg[4]==SCHED+0x1c
        self.queue_events.append('unlock')
        return 0

    def signal(self,m):
        assert m.reg[4:6]==[SCHED+0x2c,0x40000]
        self.queue_events.append('signal')
        return 0

    def release_channel(self,m):
        self.cm_effects.append(('release',tuple(m.reg[4:8])))
        p=self.new(bytes(20));self.write(p,0x10e,2)
        return p

    def post(self,m):
        if self.read(m.reg[4],2)==0x10e:
            self.free(m);return 0
        return super().post(m)

    def app_disconnected(self,m):
        self.cm_effects.append(('app_disconnected',tuple(m.reg[4:8]),self.read(m.reg[29]+0x10,1)))
        return 0

    def free(self,m):
        pointer=m.reg[4]
        result=super().free(m)
        if isinstance(getattr(self,'pending',None),list) and pointer in self.pending:
            self.pending.remove(pointer)
        return result

    def profile_post(self,m):
        queue,event,pointer=m.reg[4:7]
        if event!=discovery.CLASS:return super().profile_post(m)
        assert queue==self.queue_id
        primitive=m.read(pointer,2)
        n=32 if primitive==selection.PRIMITIVE else 24
        self.private.append(dict(queue=queue,event=event,raw=data(m,pointer,n).hex()))
        # Execute the real MessagePut wrapper and same/external segment paths.
        # The queue node still uses the retained fatal allocator contract.
        hook=self.hooks.pop(selection.POST)
        try:self.native_call(selection.POST,[queue,event,pointer])
        finally:self.hooks[selection.POST]=hook
        return 0

    def deliver(self):
        self.current_segment=0
        # OS scheduling delivery is a fixture. Native node construction and
        # locking/linking above execute; transfer each owned envelope once.
        q=QUEUES+self.queue_id*12
        chains=[self.read(q+4),self.read(SCHED+0x20)]
        self.write(q+4,0);self.write(q+8,0)
        self.write(SCHED+0x20,0);self.write(SCHED+0x24,0)
        for chain in chains:
            while chain:
                node=chain;chain=self.read(node)
                assert self.read(node+16,2)==discovery.CLASS
                self.messages.append((discovery.CLASS,self.read(node+8)))
                self.reg[4]=node;self.free(self)

    def handle(self):
        if self.lifecycle_ready:self.deliver()
        return super().handle()

    def command(self,code,group=7):
        self.write(GUI_INPUT+8,code)
        assert self.read(GUI_INPUT+10,1)==group  # Command high byte is native group.
        parent_before=data(self,GUI_INPUT,20)
        serialized_before=(data(self,selection.SNAPSHOT,32),data(self,binding.BIND,binding.SIZE),data(self,ticket.SLOT,32))
        self.current_segment=15  # Actual external/Windows thread route, not CSR0.
        result=call(self,0x31634,[0,GUI_INPUT],limit=40000)
        assert data(self,GUI_INPUT,20)==parent_before
        assert serialized_before==(data(self,selection.SNAPSHOT,32),data(self,binding.BIND,binding.SIZE),data(self,ticket.SLOT,32))
        self.current_segment=0
        return result

    def disconnect_native(self,cid=CID):
        p=self.new(bytes(32));self.write(p,0x8206,2);self.write(p+4,cid)
        self.write(p+8,1,1);self.write(p+10,0,2);self.write(p+12,12,2)
        self.enter_queue(12)
        self.profile_inbox=deque([(0x104,p)])
        try:result=call(self,0x3bcc0,[PROFILE_HOLDER],limit=40000)
        finally:self.profile_inbox=None
        assert not self.heap[p][1]
        return result

    def drain(self):
        self.deliver()
        if self.heap[self.peer][1]:
            super().drain()
        else:
            assert not self.pending and not self.profile_requests
            TimerFixture.deinit(self)
        assert self.read(lifecycle.STATE)==2
        assert data(self,binding.BIND,binding.SIZE)==bytes(binding.SIZE)


def verify(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw)
    comparisons,traces,disconnects=[],[],[]
    for code in (0x1070502,0x1070503,0x1070504,0x1070505,0x1070501):
        for active in (False,True):
            sides=[]
            for enabled in (False,True):
                m=Source(pe,enabled)
                m.flags(int(active),int(active))
                result=m.command(code)
                sides.append(dict(result=result,audio=data(m,AUDIO,0x140).hex(),
                                  filters=m.filter_calls,effects=m.gui_effects,
                                  private=m.private,locking=m.queue_events))
                if enabled and code!=0x1070501:
                    assert m.queue_events==['lock','unlock','signal']
                    assert bytes.fromhex(m.private[-1]['raw'])==b'\x03\x00'+bytes(22)
                else:assert not m.private and not m.queue_events
                m.drain()
            for k in ('result','audio','filters','effects'):assert sides[0][k]==sides[1][k],(hex(code),k)
            comparisons.append(dict(command=hex(code),initially_active=active,original=sides[0],candidate=sides[1]))
    def record(name,m):
        row=dict(case=name,phase=m.phase,owner=m.read(m.state),serial=m.read(selection.SNAPSHOT),
                 requests=list(m.requests),source_state=m.read(lifecycle.STATE),images=len(m.images),
                 clears=m.clears,locking=m.queue_events,steps=m.steps)
        m.drain();traces.append(row)
    m=Source(pe);m.select_native();m.ready_image()
    m.command(0x1070505)
    assert m.visible is not None  # GUI thread cannot mutate the artwork owner.
    m.handle()
    assert m.visible is None and m.phase==controller.FAILED and m.read(m.state)==owner.CLOSING
    assert not m.timer_id
    m.enqueue(0x8206);m.handle()
    assert m.read(m.state)==owner.IDLE
    m.command(0x1070504);m.handle()
    assert m.phase==controller.OPENING and m.field(8)==2
    assert len([r for r in m.requests if r['kind']=='open'])==2
    record('native_source_stop_clears_ready_image_then_resume_reopens',m)
    m=Source(pe);m.select_native();m.ready_image()
    m.command(0x1070505);m.command(0x1070504)
    assert lifecycle_gate(m)==1
    m.handle();m.handle()
    assert m.visible is None and m.phase==controller.FAILED and m.read(m.state)==owner.CLOSING
    assert len([r for r in m.requests if r['kind']=='open'])==1
    m.enqueue(0x8206);m.handle()
    assert m.phase==controller.OPENING and m.field(8)==2
    record('rapid_off_on_before_art_task_runs_still_invalidates_old_session',m)
    for stage in ('opening','metadata','get'):
        m=Source(pe);m.select_native()
        if stage!='opening':m.connect_native()
        if stage=='get':m.response(reply())
        m.command(0x1070505);m.handle()
        assert m.phase==controller.FAILED and not m.visible
        if stage=='opening':m.connected()
        m.enqueue(0x8206);m.handle()
        m.command(0x1070504);m.handle()
        if stage=='metadata':
            assert m.read(ticket.SLOT+16)==2 and m.read(m.state)==owner.IDLE
            m.response(reply())
        assert m.phase==controller.OPENING and m.field(8)==2
        record('source_boundary_'+stage,m)
    # Gate refusal never commits output or sends queued packets. Exact flag and
    # pointer boundaries also cover startup/teardown absence and nonboolean data.
    for case in ('focus_off','output_off','focus_two','manager_absent','audio_absent','lost_wake'):
        m=Source(pe);m.select_native();m.connected()
        if case=='focus_off':m.flags(0,1)
        if case=='output_off':m.flags(1,0)
        if case=='focus_two':m.flags(2,1)
        if case=='manager_absent':m.write(lifecycle.MANAGER_GLOBAL,0)
        if case=='audio_absent':m.write(MANAGER+0x268,0)
        if case=='lost_wake':m.fail_wake_alloc=True;m.command(0x1070505)
        sends=sum(r['kind']=='send' for r in m.requests)
        m.pump()
        assert m.phase==controller.FAILED and sum(r['kind']=='send' for r in m.requests)==sends
        record(case+'_fails_closed_before_send',m)
    for case in ('queue_unregistered','scheduler_absent','receiver_inactive','receiver_count_small','bad_primitive'):
        m=Source(pe)
        if case=='queue_unregistered':m.write(task.QUEUE,0xffff,2)
        if case=='scheduler_absent':m.write(lifecycle.SCHEDULER_GLOBAL,0)
        if case=='receiver_inactive':m.write(SCHED+0x68,0,1)
        if case=='receiver_count_small':m.write(SCHED+0x66,20,2)
        m.current_segment=15
        assert call(m,lifecycle.WAKE,[9 if case=='bad_primitive' else 3])==0
        assert not m.private and not m.queue_events
        m.write(task.QUEUE,20,2);m.write(lifecycle.SCHEDULER_GLOBAL,SCHED)
        m.write(SCHED+0x68,1,1);m.write(SCHED+0x66,21,2);m.current_segment=0
        record(case,m)
    for cid in (CID,CID+1):
        sides=[]
        for enabled in (False,True):
            m=Source(pe,enabled);m.select_native();m.ready_image()
            result=m.disconnect_native(cid)
            side=dict(result=result,effects=list(m.cm_effects),peer_live=m.heap[m.peer][1],
                      profile=data(m,PROFILE,0xa0).hex(),private=list(m.private))
            if enabled:
                m.handle()
                assert (m.phase==controller.FAILED)==(cid==CID)
                assert (m.visible is None)==(cid==CID)
            if cid==CID:assert not m.heap[m.peer][1] and m.read(PROFILE+0x7c)==0
            sides.append(side);m.drain()
        for k in ('result','effects','peer_live','profile'):assert sides[0][k]==sides[1][k],k
        disconnects.append(dict(cid=hex(cid),original=sides[0],candidate=sides[1]))
    for stage in ('queued_request','pending_metadata','pending_fragment','queued_final','get'):
        m=Source(pe);m.select_native()
        if stage=='queued_request':
            m.connected();m.receive(handshake());m.credit()
            assert len(m.profile_requests)==1 and m.read(ticket.SLOT+16)==1
        else:
            m.connect_native()
            if stage=='pending_fragment':m.response(reply(1,b'ab'),handle=False)
            if stage=='queued_final':m.response(reply(),handle=False)
            if stage=='get':m.response(reply())
        m.disconnect_native()
        assert not m.heap[m.peer][1] and not m.pending
        if stage=='queued_request':
            # Actual request dispatcher now resolves no peer, constructs the
            # original failure confirmation and drains the queued identity.
            m.profile()
        while m.messages or m.read(SCHED+0x20) or m.read(QUEUES+20*12+4):m.handle()
        if m.profile_requests:m.profile()
        assert not m.read(ticket.SLOT+16) and not m.images and not m.visible
        assert m.phase==controller.FAILED
        record('native_disconnect_'+stage+'_drains_without_publication',m)
    m=Source(pe);m.select_native();m.connect_native()
    m.response(reply())
    m.publish_interleave=True
    # Finish via original receive/collector instructions, without assuming a
    # successful final publication as the base fixture helper does.
    raw_image=jpeg()
    chunks=[raw_image[i:i+900] for i in range(0,len(raw_image),900)]
    for i,chunk in enumerate(chunks):
        final=i==len(chunks)-1
        m.receive(packet(0xa0 if final else 0x90,(fixed(0xc3,len(raw_image)) if i==0 else b'')+sequence(0x49 if final else 0x48,chunk)))
        if not final:m.credit()
    assert not m.publish_interleave and m.phase==controller.FAILED
    assert not m.images and not m.visible and not m.field(64)
    record('GUI_source_change_between_pre_pump_and_publication_is_rejected',m)
    for case in ('wrong_channel','wrong_track','new_selection','inactive_owner','inactive_controller','unpublished','wrong_queue'):
        m=Source(pe);m.select_native();m.ready_image()
        channel,track=m.field(8),m.field(12)
        if case=='wrong_channel':channel+=1
        if case=='wrong_track':track+=1
        if case=='new_selection':m.write(selection.SNAPSHOT,m.read(selection.SNAPSHOT)+1)
        if case=='inactive_owner':m.write(m.state,owner.CLOSING)
        if case=='inactive_controller':m.write(m.state+controller.OFFSET,controller.FAILED)
        if case=='unpublished':m.write(m.state+controller.OFFSET+36,0)
        m.enter_queue(13 if case=='wrong_queue' else m.queue_id)
        before=len(m.images)
        assert not call(m,controller.PUBLISH,[m.state,channel,track,m.field(64)],stack_args=(m.field(72),))
        assert len(m.images)==before
        record('publication_'+case,m)
    pins=('bt_cover_art_lifecycle.py','verify_bt_cover_lifecycle.py','bt_cover_art_binding.py',
          'verify_bt_cover_binding.py','bt_cover_art_selection.py','verify_bt_cover_selection.py',
          'bt_cover_art_metadata.py','bt_cover_art_timers.py','bt_cover_art_task.py',
          'verify_bt_cover_metadata.py','verify_bt_cover_task.py','verify_bt_cover_owner.py',
          'verify_bt_cover_timers.py','verify_bt_cover_responses.py',
          'verify_media_responsiveness.py','inspect_bt_pairing.py','patch_bt_cover_attribute.py',
          'patch_usb_seek_completion.py','patch_updater_copy_safety.py')
    return dict(source_comparisons=len(comparisons),cases=len(traces),disconnect_comparisons=len(disconnects),
                source=comparisons,traces=traces,disconnects=disconnects,
                sites={hex(k):hex(v) for k,v in lifecycle.sites(raw).items()},
                helpers=[{k:v for k,v in r.items() if k!='raw'} for r in assembled()],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Original GUI source commands, flags and CSR external-thread queue linking execute',
                        'Original CM dispatch, CID lookup, unlink, peer/pending destructors and failure confirmation posting execute',
                        'OS locks/events/timers, filters, callback constructors, scheduler delivery, wire and images are fixtures',
                        'MessagePut retains its existing fatal internal queue-node allocation contract',
                        'Global shutdown must quiesce GUI producers before task/profile destruction',
                        'A lost optional wakeup is caught on the next owning pump; READY has no periodic watchdog',
                        'Executable placement, loader/unwind, actual CE image decoding and AppMain publication remain open'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in pins})


def lifecycle_gate(m):return call(m,lifecycle.GATE,[])


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True);p.add_argument('--report',type=Path,required=True)
    args=p.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'))
    print(json.dumps({k:v for k,v in result.items() if k.endswith('cases') or k.endswith('comparisons')},indent=2))
