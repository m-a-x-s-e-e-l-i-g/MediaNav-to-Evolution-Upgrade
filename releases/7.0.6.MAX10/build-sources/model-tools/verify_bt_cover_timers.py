"""Interpret artwork deadlines with original CSR timer set/cancel/delivery code.

The owning queue and OS clock values are fixtures. Original timer nodes, ordering,
callback delivery, queue restoration and cancellation execute as MIPS. The ROM
GetTickCount stub executes up to a fixture kernel trap. No firmware is installed.
"""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_timers as timers
import bt_cover_art_controller as controller
import bt_cover_art_task as task
import bt_cover_art_owner as owner
import bt_cover_art_responses as responses
from patch_bt_cover_attribute import BASE_SHA
from verify_bt_cover_controller import SessionFixture, CHANNEL, TRACK, attributes, jpeg
from verify_bt_cover_task import SCHED, HOLDER
from verify_bt_cover_responses import handshake, packet, sequence
from verify_media_responsiveness import call, STACK
from inspect_bt_pairing import put, data

ROOT = Path(__file__).resolve().parents[1]
NATIVE = [(0x85008, 0x85130), (0x85130, 0x8517c), (0x85418, 0x85628), (0x84660, 0x84724)]
SCHED_GLOBAL = 0x20e36c


@lru_cache(maxsize=1)
def assembled():
    return timers.assembled()+responses.assembled()


class TimerFixture(SessionFixture):
    def __init__(self, original, **kwargs):
        super().__init__(original, **kwargs)
        replaced = {row['address'] for row in assembled()}
        self.pe.helpers = [row for row in self.pe.helpers if row['address'] not in replaced]+assembled()
        self.ranges += NATIVE+[(row['address'],row['address']+len(row['raw'])) for row in assembled()]
        self.allowed += [(SCHED_GLOBAL,SCHED_GLOBAL+4)]
        self.current_segment, self.now, self.wall_us = 0, 100, 100000
        self.clock_reads, self.timer_sets = 0, []
        put(self,SCHED_GLOBAL,SCHED.to_bytes(4,'little'))
        self.hooks.update({0x83e60:lambda m:self.current_segment,
                           0x85bdc:self.wall_clock, timers.GET_TICK_TRAP:self.tick_clock})

    def wall_clock(self,m):
        assert m.reg[4]==0
        return self.wall_us

    def tick_clock(self,m):
        self.clock_reads += 1
        return self.now

    def at(self,now,wall_us=None):
        self.now = now & 0xffffffff
        self.wall_us = ((now*1000) if wall_us is None else wall_us) & 0xffffffff

    def enter_queue(self,queue=None):
        self.write(SCHED+self.current_segment*0x70+2,self.queue_id if queue is None else queue,2)

    def init(self,queue=20):
        self.enter_queue(queue)
        return super().init(queue)

    def handle(self):
        self.enter_queue()
        super().handle()

    def prepare(self,channel=CHANNEL,track=TRACK,now=None):
        if now is not None:self.at(now)
        self.enter_queue()
        return call(self,controller.PREPARE,[self.state,channel,track,0xbad00000])

    def metadata(self,raw=None,channel=CHANNEL,track=TRACK):
        self.enter_queue()
        return super().metadata(raw,channel,track)

    def flush(self):
        self.enter_queue()
        return call(self,timers.PUMP,[self.state])

    def select(self,track=TRACK+1,channel=CHANNEL):
        self.enter_queue()
        return call(self,controller.SELECT,[self.state,channel,track,0xbad00000])

    @property
    def timer_id(self):return self.field(48)

    @property
    def token(self):return self.field(52)

    def nodes(self):
        rows=[]
        node=self.read(SCHED+self.current_segment*0x70+0x4c)
        seen=set()
        while node:
            assert node not in seen, 'Timer list cycle'
            seen.add(node)
            rows.append(dict(node=node,id=self.read(node+0x14),callback=self.read(node+4),
                             owner=self.read(node+8),due=self.read(node+0xc),epoch=self.read(node+0x10),
                             queue=self.read(node+0x18,2),token=self.read(node+0x1a,2)))
            node=self.read(node)
        return rows

    def due(self,now,wall_us=None):
        self.at(now,wall_us)
        before=self.nodes()
        self.enter_queue(0xffff)
        self.reg[17],self.reg[21],self.reg[29]=SCHED+self.current_segment*0x70,0xffffffff,STACK
        # Exact original due-test/pop/callback/recycle loop, ending before idle/thread wait.
        self.run(0x84718,{0x84724},limit=30000)
        assert self.read(SCHED+self.current_segment*0x70+2,2)==0xffff
        self.timer_sets.append(dict(before=before,after=self.nodes(),now=self.now,wall_us=self.wall_us))

    def pending(self):
        nodes=self.nodes()
        assert len(nodes)==int(bool(self.timer_id))
        if nodes:
            assert nodes[0]['id']==self.timer_id and nodes[0]['owner']==self.state
            assert nodes[0]['callback']==timers.WAKEUP and nodes[0]['queue']==self.queue_id
            assert nodes[0]['token']==self.token
        assert self.read(SCHED+self.current_segment*0x70+0x54,2)==len(nodes)
        return nodes

    def deinit(self):
        self.enter_queue()
        old=self.state
        call(self,task.DEINIT,[HOLDER],limit=50000)
        assert self.read(HOLDER)==0 and not self.heap[old][1]
        assert not self.nodes() and self.read(SCHED+self.current_segment*0x70+0x54,2)==0
        # TimerCancel/delivery retain native nodes in the shared scheduler free pool.
        # Its process-lifetime destruction is an explicit fixture, not a task free.
        pool=self.read(SCHED+self.current_segment*0x70+0x50)
        seen=set()
        while pool:
            assert pool not in seen
            seen.add(pool)
            assert self.heap[pool]==(28,True)
            next_node=self.read(pool)
            self.reg[4]=pool;self.free(self)
            pool=next_node
        self.write(SCHED+self.current_segment*0x70+0x50,0)
        self.write(SCHED+self.current_segment*0x70+0x56,0,1)
        self.assert_drained()


def core_evidence(raw=None):
    contract=timers.CORE_CONTRACT
    if raw is not None:
        if hashlib.sha256(raw).hexdigest()!=contract['sha256']:
            raise ValueError('Expected original 705md ROM coredll.dll')
        core=pefile.PE(data=raw)
        exported=[e for e in core.DIRECTORY_ENTRY_EXPORT.symbols
                  if e.ordinal==contract['ordinal'] and e.name==contract['export'].encode()]
        assert len(exported)==1 and exported[0].address==contract['rva']
        assert core.get_data(exported[0].address,contract['bytes']).hex()==contract['bytes_hex']
    return dict(**contract,original_rom_checked=raw is not None,
                interpretation='Exact export instructions; kernel clock call uses an OS fixture')


def verify(raw,core=None):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:
        raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    original=pefile.PE(data=raw)
    traces=[]

    def record(name,m):
        nodes=m.pending()
        row=dict(case=name,phase=m.phase,timer_id=m.timer_id,callback_token=m.token,
                 clock_reads=m.clock_reads,pending=nodes,deliveries=m.timer_sets,
                 metadata_requests=list(m.metadata_requests),images=len(m.images),
                 operations_before_shutdown=list(m.operations))
        m.deinit()
        row['steps']=m.steps
        traces.append(row)

    m=TimerFixture(original);m.get();m.pending()
    m.finish_image()
    assert m.phase==controller.READY and m.images[0][2]==jpeg()
    assert not m.timer_id and not m.nodes()
    record('complete_native_transfer_cancels_wakeup',m)

    for phase,timeout in ((controller.OPENING,2000),(controller.CONNECT,2000),
                          (controller.META,3000),(controller.GET,10000)):
        m=TimerFixture(original)
        if phase==controller.OPENING:
            m.ready(queue=20);assert m.prepare();assert m.open()
        elif phase==controller.CONNECT:m.begin(queue=20)
        elif phase==controller.META:m.begin(queue=20);m.handshake()
        else:m.get()
        assert m.field(16)==100 and m.field(20)==100
        for elapsed in range(100,timeout,100):
            m.due(100+elapsed);m.pending()
            assert m.phase==phase and m.timer_id
        m.due(100+timeout)
        assert m.phase==controller.FAILED and not m.timer_id and not m.nodes()
        assert not m.field(64)
        record('idle_scheduler_deadline_'+str(phase),m)

    for phase in (controller.CONNECT,controller.META,controller.GET):
        m=TimerFixture(original);m.begin()
        if phase in (controller.META,controller.GET):m.handshake()
        if phase==controller.GET:assert m.metadata();m.flush()
        timeout=m.field(24)
        m.at(100+timeout)
        # Incoming events must expire before dispatch even when no idle timer ran.
        if phase==controller.CONNECT:m.receive(handshake())
        elif phase==controller.META:assert not m.metadata()
        else:m.receive(packet(0xa0,sequence(0x49,jpeg())))
        assert m.phase==controller.FAILED and not m.timer_id and not m.images
        record('late_input_rejected_without_timer_delivery_'+str(phase),m)

    m=TimerFixture(original);m.begin()
    m.at(1000);m.handshake()
    assert m.field(20)==1000 and m.field(24)==3000
    m.at(2000);assert m.metadata();m.flush()
    assert m.field(20)==2000 and m.field(24)==10000
    m.at(11999);m.receive(packet(0x90,sequence(0x48,b'x')));m.credit()
    assert m.field(20)==2000
    m.due(12000)
    assert m.phase==controller.FAILED and not m.timer_id
    record('fresh_phase_start_but_continuation_keeps_total_deadline',m)

    m=TimerFixture(original);m.begin()
    first=m.timer_id
    for _ in range(30):assert m.flush() and m.timer_id==first
    assert len(m.nodes())==1
    record('repeated_pump_does_not_accumulate_timers',m)

    m=TimerFixture(original);m.get()
    body=m.field(64);timer=m.timer_id
    m.enqueue(0x8206);m.handle()
    assert m.phase==controller.OFF and not m.timer_id and not m.heap[body][1]
    assert not m.nodes() and call(m,timers.CANCEL_TIMER,[timer,0,0])==0
    record('disconnect_unlinks_timer_and_frees_body',m)

    m=TimerFixture(original);m.get()
    assert not m.select()
    assert m.phase==controller.FAILED and not m.timer_id
    record('track_change_during_transfer_cancels_timer',m)
    m=TimerFixture(original);m.get();m.finish_image();old=m.token
    m.at(1000);assert m.select()
    assert m.metadata_requests==[(CHANNEL,TRACK),(CHANNEL,TRACK+1)]
    assert m.phase==controller.META and m.token>old and m.timer_id
    record('ready_track_refresh_rearms_with_fresh_clock_and_token',m)

    m=TimerFixture(original);m.begin();m.handshake()
    before=data(m,m.state+controller.OFFSET,controller.SIZE)
    assert not m.metadata(channel=CHANNEL-1)
    assert data(m,m.state+controller.OFFSET,controller.SIZE)==before
    record('stale_metadata_keeps_live_timer',m)

    m=TimerFixture(original);m.begin();old=m.token
    m.due(200);assert m.token==old+1
    snapshot=data(m,m.state+controller.OFFSET,controller.SIZE)
    m.enter_queue();call(m,timers.WAKEUP,[old,m.state])
    assert data(m,m.state+controller.OFFSET,controller.SIZE)==snapshot
    record('old_callback_token_cannot_consume_new_timer',m)

    for entry in (controller.PREPARE,controller.SELECT,controller.METADATA,timers.PUMP,timers.ARM):
        m=TimerFixture(original);m.begin()
        before=data(m,m.state+controller.OFFSET,controller.SIZE)
        m.enter_queue(m.queue_id+1)
        args=[m.state,CHANNEL+1,TRACK+1,0]
        assert not call(m,entry,args,stack_args=(0,))
        assert data(m,m.state+controller.OFFSET,controller.SIZE)==before
        record('foreign_queue_refused_'+hex(entry),m)
    m=TimerFixture(original);m.begin()
    before=data(m,m.state+controller.OFFSET,controller.SIZE)
    m.enter_queue(m.queue_id+1)
    call(m,timers.WAKEUP,[m.token,m.state])
    assert data(m,m.state+controller.OFFSET,controller.SIZE)==before
    record('foreign_queue_callback_does_not_consume_timer',m)

    m=TimerFixture(original);m.ready(queue=20)
    m.write(m.state+timers.TOKEN,0xffff)
    assert not m.prepare()
    assert m.phase==controller.FAILED and not m.timer_id and not m.nodes()
    record('callback_token_exhaustion_refuses_without_wrap',m)
    m=TimerFixture(original);m.ready(queue=20)
    m.write(SCHED+0x28,0x0ffffffe)
    assert m.prepare() and m.timer_id==0x0fffffff
    m.due(200)
    assert m.phase==controller.FAILED and not m.timer_id and not m.nodes()
    record('native_zero_timer_id_wrap_preempted_before_posting',m)

    for count in (98,99):
        m=TimerFixture(original);m.ready(queue=20)
        foreign=[]
        for _ in range(count):
            foreign.append(call(m,timers.SET_TIMER,[100000000,0xf1234000,0,0]))
        before=[dict(node) for node in m.nodes()]
        assert m.prepare()==int(count<99)
        assert m.phase==(controller.OPENING if count<99 else controller.FAILED)
        after=[node for node in m.nodes() if node['callback']!=timers.WAKEUP]
        assert after==before, 'Unrelated native timers changed'
        call(m,controller.CANCEL,[m.state])
        for ident in foreign:assert call(m,timers.CANCEL_TIMER,[ident,0,0])==1
        assert not m.nodes()
        record('native_timer_limit_prechecked_'+str(count),m)

    m=TimerFixture(original);m.begin();old=m.token
    call(m,controller.CANCEL,[m.state])
    m.enter_queue();snapshot=data(m,m.state+controller.OFFSET,controller.SIZE)
    call(m,timers.WAKEUP,[old,m.state])
    assert data(m,m.state+controller.OFFSET,controller.SIZE)==snapshot
    m.enqueue(0x8206);m.handle()
    assert m.prepare(channel=CHANNEL+1,track=TRACK+1)
    assert m.token>old and m.timer_id
    snapshot=data(m,m.state+controller.OFFSET,controller.SIZE)
    call(m,timers.WAKEUP,[old,m.state])
    assert data(m,m.state+controller.OFFSET,controller.SIZE)==snapshot
    record('cancelled_callback_cannot_consume_new_channel_timer',m)

    m=TimerFixture(original);m.begin(now=0xfffffff0)
    # Wall and monotonic clocks wrap independently; callback uses the monotonic tick.
    m.due(0x54,wall_us=(0xfffffff0*1000+100000)&0xffffffff)
    assert m.phase==controller.CONNECT and m.timer_id
    m.due((0xfffffff0+2000)&0xffffffff,wall_us=(0xfffffff0*1000+2000000)&0xffffffff)
    assert m.phase==controller.FAILED and not m.timer_id
    record('monotonic_millisecond_wrap',m)
    m=TimerFixture(original);m.begin()
    # Reset wall time before arming a timer which crosses its native epoch.
    call(m,timers.STOP_TIMER,[m.state]);m.at(100,wall_us=0xfffffff0)
    m.flush();m.due(200,wall_us=99984)
    assert m.phase==controller.CONNECT and m.timer_id
    record('original_scheduler_microsecond_epoch_wrap',m)

    m=TimerFixture(original);m.begin();m.at(99);assert not m.flush()
    assert m.phase==controller.FAILED and not m.timer_id
    record('reversed_monotonic_sample_fails_closed',m)
    m=TimerFixture(original);m.begin();m.due(200,wall_us=0)
    assert m.phase==controller.CONNECT and m.timer_id
    # CSR wall-clock correction can delay idle delivery. Current input still expires.
    m.at(2100,wall_us=0);m.receive(handshake())
    assert m.phase==controller.FAILED and not m.timer_id
    record('wall_clock_delay_does_not_accept_expired_input',m)

    m=TimerFixture(original);m.get();m.finish_image()
    m.at(1000);assert m.select()
    body_before_shutdown=m.field(64)
    before=len(m.operations);m.deinit()
    assert not body_before_shutdown
    assert all(kind not in ('ack','disconnect','post') for kind,_ in m.operations[before:])
    # No queued timer remains to deliver a callback to the freed owner.
    m.due(100000)
    traces.append(dict(case='quiescent_shutdown_no_late_timer_callback',steps=m.steps))

    m=TimerFixture(original);m.get()
    body=m.field(64);before=len(m.operations)
    m.deinit();assert not m.heap[body][1]
    assert all(kind not in ('ack','disconnect','post') for kind,_ in m.operations[before:])
    traces.append(dict(case='active_transfer_shutdown_unlinks_before_owner_free',steps=m.steps))

    names=('bt_cover_art_timers.py','verify_bt_cover_timers.py','bt_cover_art_controller.py',
           'verify_bt_cover_controller.py','bt_cover_art_task.py','verify_bt_cover_task.py',
           'bt_cover_art_owner.py','bt_cover_art_framer.py','bt_cover_art_responses.py',
           'bt_cover_art_native.py','bt_cover_art_client.py','verify_bt_cover_responses.py',
           'verify_bt_cover_owner.py','verify_bt_cover_csr_bridge.py','verify_bt_cover_attribute.py',
           'patch_bt_cover_attribute.py','patch_usb_seek_completion.py','patch_usb_folders.py',
           'patch_usb_reliability.py','patch_updater_copy_safety.py','inspect_wave_queue.py',
           'inspect_bt_lifecycle.py','inspect_bt_pairing.py','verify_media_responsiveness.py')
    return dict(cases=len(traces),traces=traces,binary_input_sha256=BASE_SHA,
                core_contract=core_evidence(core),period_ms=timers.PERIOD_MS,
                native_slices=[dict(start=hex(lo),end=hex(hi),sha256=hashlib.sha256(
                    original.get_data(lo-original.OPTIONAL_HEADER.ImageBase,hi-lo)).hexdigest()) for lo,hi in NATIVE],
                helpers=[dict(address=hex(row['address']),purpose=row['purpose'],used_bytes=row['recipe']['used_bytes'],
                              bytes_hex=row['raw'].hex(),assembly=row['recipe'],relocation_recipe=row['relocations'])
                         for row in timers.assembled()],
                instruction_interpretation=True,firmware_patched=False,task_installed=False,lgu_built=False,
                limits=['Original timer set/cancel/current-queue/due-delivery/recycle instructions execute; OS clocks and scheduler thread identity are fixtures',
                        'GetTickCount stub is pinned to the original ROM export; kernel trap and physical tick rate are not executed',
                        'Deadline comparisons use monotonic millisecond samples; original scheduler timer ordering still uses wall-clock microseconds',
                        'Wall-clock changes or delayed scheduling can delay idle wakeups; incoming events still check the current deadline',
                        'All entry points require serialized owning queue; no concurrent or reentrant calls are supported',
                        'Callbacks already unlinked by scheduler clear their ID before rearming; cancellation occurs before owner/body free',
                        'Cancelled/delivered timer nodes remain in original shared scheduler pool; final pool destruction is a fixture',
                        'CSR constructors/timer allocation retain original fatal OOM contract; metadata and GUI delivery remain fixtures',
                        'Capability/security/AVRCP correlation/PE placement/relocation/unwind/physical Bluetooth and Spotify testing remain incomplete'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in names})


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--core',type=Path,help='Optional exact original ROM coredll.dll to recheck export provenance')
    parser.add_argument('--report',type=Path,required=True)
    args=parser.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes(),args.core.read_bytes() if args.core else None)
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'],period_ms=result['period_ms'],task_installed=False),indent=2))
