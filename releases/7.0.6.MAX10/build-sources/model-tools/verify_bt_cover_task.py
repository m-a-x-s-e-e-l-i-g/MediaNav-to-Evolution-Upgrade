"""Interpret CSR artwork task registration, lifecycle, ERTM open and owned sends.

Uses original registration/config/mblk/ACK/free instruction slices. Scheduler
delivery, allocators, primitive posting and the OBEX packet consumer are fixtures.
No native task is installed and no Bluetooth channel is opened on the machine.
"""
import argparse
from collections import deque
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_task as task
import bt_cover_art_owner as owner
import bt_cover_art_framer as framer
from patch_bt_cover_attribute import BASE_SHA
from inspect_bt_lifecycle import SliceVM
from inspect_bt_pairing import put, data
from verify_bt_cover_owner import Fixture, Image, STATE, PEER, CID, OLD_CID, PEER_BYTES
from verify_media_responsiveness import call

ROOT = Path(__file__).resolve().parents[1]
HOLDER, SCHED, TABLE, TX_SOURCE = 0x45000000, 0x45001000, 0x45002000, 0x46000000
LOCAL_PSM, REMOTE_PSM = 0x1001, 0x1003
QUEUE_ID = 22
NATIVE = [(0x244c8, 0x24714), (0x8517c, 0x85238), (0x5063c, 0x506a8),
          (0x8a230, 0x8a470), (0x8a470, 0x8a5a8),
          (0x50820, 0x50968), (0x55fb8, 0x56004), (0x69e5c, 0x69ed0),
          (0x69ed0, 0x69f18), (0x69fdc, 0x6a000), (0x6a000, 0x6a03c),
          (0x6a03c, 0x6a0c0), (0x6a17c, 0x6a228), (0x6a228, 0x6a2a4),
          (0x6a348, 0x6a4b0), (0x50c48, 0x50cd4), (0x82468, 0x824a0),
          (0x82378, 0x82468), (0x819ac, 0x819e0), (0x81940, 0x819ac),
          (0x824e8, 0x82530), (0xe1cf0, 0xe1d8c)]


@lru_cache(maxsize=1)
def helpers():
    return owner.assembled()+[framer.assembled(), framer.owner_adapter()]+task.assembled()


class TaskFixture(Fixture):
    def __init__(self, original, allocation_failure=None):
        super().__init__(original, helpers())
        self.ranges += NATIVE
        self.allowed += [(HOLDER, HOLDER+4), (SCHED, SCHED+0x77c), (TABLE, TABLE+16*64),
                         (task.QUEUE, task.NAME+16), (0x218620, 0x218660), (0x21721c,0x217220),
                         (0x10c904, 0x10c928)]
        self.messages = deque()
        self.requests, self.packets, self.allocations = [], [], []
        self.allocation_failure = allocation_failure
        self.state = 0
        self.queue_id = QUEUE_ID
        self.hooks.pop(owner.NOTIFY)
        self.hooks.update({0x84ee8:self.get_message, 0x3a750:self.clear, 0x857bc:self.clone,
                           framer.PACKET:self.packet, 0xc8660:self.confirm})
        for address, raw in task.initial_data().items():
            put(self, address, raw)
        put(self, HOLDER, bytes(4)); put(self, SCHED, bytes(0x77c)); put(self, TABLE, bytes(16*64))
        put(self, 0x218620, bytes(0x40))
        put(self, 0x10c904, original.get_data(0x10c904-original.OPTIONAL_HEADER.ImageBase, 36))
        self.hooks.update({at:lambda m:0 for at in (0x83998,0x8398c,0x839a4,0x839b0,0x83980,
                                                   0x7b75c,0x7b7bc,0x7b508,0x7ae94,
                                                   0x2e644)})

    def plain(self, word):
        if word >> 26 == 0 and word & 63 == 0x12:
            self.reg[(word >> 11)&31]=self.lo
            self.reg[0]=0
        elif word >> 26 == 0 and word & 63 == 0x18:
            rs, rt = (word >> 21)&31, (word >> 16)&31
            signed = lambda value:value if value < 0x80000000 else value-0x100000000
            product = signed(self.reg[rs])*signed(self.reg[rt]) & 0xffffffffffffffff
            self.hi, self.lo = product >> 32, product & 0xffffffff
        else:
            super().plain(word)

    def allocate(self, m):
        size = m.reg[4]
        assert 0 < size <= task.SIZE
        self.allocations.append(size)
        if size == self.allocation_failure:
            return 0
        return self.new(bytes([0xcc])*size)

    def clear(self, m):
        pointer, value, size = m.reg[4:7]
        assert value == 0
        put(m, pointer, bytes(size))
        return pointer

    def clone(self, m):
        return self.new(data(m, m.reg[4], m.reg[5]))

    def native_call(self, at, args):
        # Execute the actual mblk destructor from within the fixture CM sink.
        saved, pc = list(self.reg), self.pc
        self.reg[4:8] = list(args)+[0]*(4-len(args))
        self.reg[31] = 0xbeef0000
        self.run(at, {0xbeef0000}, limit=10000)
        self.reg, self.pc = saved, pc

    def post(self, m):
        pointer = m.reg[4]
        primitive = m.read(pointer, 2)
        if primitive == 0x108:
            row = dict(kind='register', queue=m.read(pointer+2,2), psm=m.read(pointer+4,2),
                       flags=m.read(pointer+6,2), context=m.read(pointer+10,2))
            assert m.read(pointer+8,2) == 0
        elif primitive == 0x109:
            config, count = m.read(pointer+24), m.read(pointer+20,2)
            row = dict(kind='open', queue=m.read(pointer+2,2), peer=data(m,pointer+4,8).hex(),
                       local=m.read(pointer+12,2), remote=m.read(pointer+14,2),
                       security=m.read(pointer+16,2), context=m.read(pointer+18,2),
                       config=[m.read(config+i*2,2) for i in range(count)])
            assert row['config'] == [0x8000,0x703,0xffff,0xffff,0,1,1,1024,
                                     0x12,0x300,0x313,1,1,0x315,0xff,0,0x21,0xffff,0xff00]
            assert self.heap[config][0] == count*2
            old_a0=m.reg[4];m.reg[4]=config;self.free(m);m.reg[4]=old_a0
        elif primitive == 0x204:
            block=m.read(pointer+12)
            length=m.read(block+14,2)
            source=m.read(block+16)
            row=dict(kind='send',cid=m.read(pointer+4),context=m.read(pointer+16,2),
                     bytes_hex=data(m,source,length).hex())
            assert m.read(pointer+8,2)==0 and source!=TX_SOURCE
            assert m.read(block+20)==source  # mblk owns a separate heap copy.
            self.native_call(0x819ac,[block])
            assert not self.heap[block][1] and not self.heap[source][1]
        else:
            return super().post(m)
        self.requests.append(row)
        self.operations.append(('post',primitive))
        self.free(m)
        return 0

    def get_message(self, m):
        if not self.messages:
            return 0
        event, pointer = self.messages.popleft()
        m.write(m.reg[4],event,2); m.write(m.reg[5],pointer)
        return 1

    def confirm(self,m):
        assert m.reg[4] == self.queue_id
        self.messages.append((0x104,m.reg[5]))
        return 0

    def packet(self,m):
        assert m.reg[4:6]==[self.state+owner.SIZE,self.state+owner.SIZE+4]
        self.packets.append(data(m,m.reg[5],m.reg[6]))
        return 1

    def init(self,queue=QUEUE_ID):
        self.queue_id = queue
        self.write(task.QUEUE,queue,2)
        call(self,task.INIT,[HOLDER])
        self.state=self.read(HOLDER)
        return self.state

    def enqueue(self,kind,cid=CID,psm=LOCAL_PSM,result=0,supplier=12,context=0,payload=b'',event=0x104):
        body=self.new(bytes(0x20))
        self.write(body,kind,2);self.write(body+4,cid)
        if kind==0x8200:
            self.write(body+2,psm,2);self.write(body+6,result,2);self.write(body+8,supplier,2)
        elif kind==0x8204:
            self.write(body+8,context,2);self.write(body+10,result,2);self.write(body+12,supplier,2)
        elif kind==0x8205:
            source=self.new(payload) if payload else 0
            self.write(body+8,len(payload),2);self.write(body+12,source)
        self.messages.append((event,body))
        return body

    def handle(self):
        call(self,task.HANDLE,[HOLDER],limit=20000)

    def ready(self,local=LOCAL_PSM,queue=QUEUE_ID):
        assert self.init(queue)
        self.enqueue(0x8200,psm=local);self.handle()
        assert self.read(self.state+24)==2 and self.read(self.state+20,2)==local

    def open(self,remote=REMOTE_PSM,security=100):
        return call(self,task.OPEN,[self.state,PEER,remote,security])

    def connected(self,psm=LOCAL_PSM,mtu=1024,result=0,supplier=12):
        # Actual original CM primitive factory produces the task's message.
        call(self,0xe1cf0,[self.queue_id,CID,psm,mtu],
             stack_args=(0,int.from_bytes(PEER_BYTES[:4],'little'),int.from_bytes(PEER_BYTES[4:],'little'),
                         result,supplier,0))
        self.handle()

    def send(self,packet=b'\x83\x00\x03',pointer=TX_SOURCE,size=None):
        self.allowed=[row for row in self.allowed if row[0]!=TX_SOURCE]
        self.allowed.append((TX_SOURCE,TX_SOURCE+len(packet)))
        put(self,TX_SOURCE,packet)
        before=data(self,TX_SOURCE,len(packet))
        result=call(self,task.SEND,[self.state,pointer,len(packet) if size is None else size],limit=20000)
        assert data(self,TX_SOURCE,len(packet))==before
        return result

    def deinit(self):
        call(self,task.DEINIT,[HOLDER],limit=50000)
        assert self.read(HOLDER)==0
        self.assert_drained()


def registration(original,enabled,segment):
    m=TaskFixture(original)
    if enabled:m.patches[task.SITE]=task.bridge(original.__data__)
    m.write(SCHED+0x778,segment,2)
    row=SCHED+0x70*segment
    # Count/queue pass, then registration-table pass using the resulting size.
    m.write(row+0x64,1,1)
    call(m,0x244c8,[SCHED])
    count=m.read(row+0x66,2)
    queue_ids=data(m,0x218620,0x40)
    new_id=m.read(task.QUEUE,2)
    m.write(row+0x66,0,2);m.write(row+0x64,0,1);m.write(row+0x14,TABLE)
    call(m,0x244c8,[SCHED])
    assert count==m.read(row+0x66,2)
    rows=[tuple(m.read(TABLE+16*i+4*j) for j in range(4)) for i in range(count)]
    assert data(m,0x218620,0x40)==queue_ids
    return dict(count=count,queues=queue_ids.hex(),artwork_queue=new_id,rows=rows,steps=m.steps)


def verify(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    original=pefile.PE(data=raw)
    traces=[]

    def record(name,m):
        requests=list(m.requests)
        phase=m.read(m.state) if m.state and m.heap[m.state][1] else None
        m.deinit()
        traces.append(dict(case=name,requests=requests,phase_before_shutdown=phase,steps=m.steps,
                           packet_lengths=[len(p) for p in m.packets]))

    registrations=[]
    for segment in (0,1):
        old=registration(original,False,segment);new=registration(original,True,segment)
        assert old['rows']==new['rows'][:len(old['rows'])] and old['queues']==new['queues']
        assert new['count']==old['count']+int(segment==0)
        if segment==0:
            assert new['rows'][-1]==(task.INIT,task.DEINIT,task.HANDLE,task.NAME)
            assert new['artwork_queue']==old['count']
        else:assert new['artwork_queue']==0xffff
        registrations.append(dict(segment=segment,original=old,bridge=new))

    for queue,fail in ((QUEUE_ID,None),(0xffff,None),(QUEUE_ID,task.SIZE)):
        m=TaskFixture(original,fail)
        state=m.init(queue)
        if fail:assert state==0 and not m.requests
        elif queue==0xffff:assert m.read(state+24)==3 and not m.requests
        else:
            assert m.requests==[dict(kind='register',queue=QUEUE_ID,psm=0,flags=1,context=0)]
            assert data(m,state,20)==bytes(20) and data(m,state+28,task.SIZE-28)==bytes(task.SIZE-28)
        record(f'init_{queue}_{fail}',m)
    m=TaskFixture(original)
    actual_queue=registrations[0]['bridge']['artwork_queue']
    m.ready(queue=actual_queue);assert m.open();m.connected()
    assert m.requests[-1]['queue']==actual_queue and m.read(m.state)==owner.ACTIVE
    record('registration_queue_to_actual_task_callbacks',m)
    for psm in (0,0x17,0x1000,0x1001,0x1003,0x1101):
        for result,supplier in ((0,12),(1,12),(0,6)):
            m=TaskFixture(original);m.init()
            m.enqueue(0x8200,psm=psm,result=result,supplier=supplier);m.handle()
            good=psm in (0x1001,0x1003) and (result,supplier)==(0,12)
            assert m.read(m.state+24)==(2 if good else 3)
            if not good:assert not m.open()
            snapshot=data(m,m.state,task.SIZE)
            m.enqueue(0x8200,psm=0x1005);m.handle()  # Ignore duplicate confirmation.
            assert data(m,m.state,task.SIZE)==snapshot
            record(f'psm_registration_{psm}_{result}_{supplier}',m)
    for local in (0x1001,0x1003,0x1011):
        for remote in (0x1001,0x1003,0x1015):
            for security in (100,0x8000,0xffff):
                m=TaskFixture(original);m.ready(local)
                assert m.open(remote,security)
                request=m.requests[-1]
                assert request['kind']=='open' and request['local']==local and request['remote']==remote
                assert request['queue']==QUEUE_ID and request['peer']==PEER_BYTES.hex() and request['security']==security
                assert m.read(m.state+8,2)==local and m.read(m.state)==owner.OPENING
                assert not m.open(remote,security)
                m.connected(local)
                assert m.read(m.state)==owner.ACTIVE and m.read(m.state+4)==CID
                record(f'open_{local}_{remote}_{security}',m)
    for remote,security in ((0x17,100),(0x1000,100),(0x1101,100),(0x10001,100),
                             (REMOTE_PSM,0),(REMOTE_PSM,0x10000)):
        m=TaskFixture(original);m.ready()
        assert not m.open(remote,security) and len(m.requests)==1
        record(f'refuse_open_{remote}_{security}',m)
    for cancelled in (False,True):
        m=TaskFixture(original);m.ready();assert m.open()
        if cancelled:call(m,owner.STOP,[m.state])
        m.connected()
        assert m.read(m.state)==(owner.CLOSING if cancelled else owner.ACTIVE)
        record('cancel_pending_'+str(cancelled),m)
    for result,supplier in ((1,12),(0,6)):
        m=TaskFixture(original);m.ready();assert m.open()
        m.connected(result=result,supplier=supplier)
        assert m.read(m.state)==owner.IDLE
        record(f'failed_open_{result}_{supplier}',m)
    m=TaskFixture(original);m.ready();assert m.open()
    m.connected(psm=REMOTE_PSM)
    assert m.read(m.state)==owner.OPENING
    assert ('disconnect',CID) in m.operations
    record('remote_psm_is_not_local_confirmation_identity',m)
    for phase in (owner.OPENING,owner.ACTIVE,owner.CLOSING,owner.CANCELLED):
        m=TaskFixture(original);m.ready();m.write(m.state,phase)
        assert not m.open() and len(m.requests)==1
        record('open_refuses_busy_phase_'+str(phase),m)

    for length in (3,26,43,255,1024):
        m=TaskFixture(original);m.ready();assert m.open();m.connected()
        packet=b'\x83'+length.to_bytes(2,'big')+bytes(length-3)
        assert m.send(packet)
        assert m.read(m.state+28,2)==m.read(m.state+30,2)==1
        assert m.requests[-1]['bytes_hex']==packet.hex()
        assert not m.send(packet)
        for context,cid in ((0,CID),(2,CID),(1,OLD_CID)):
            m.enqueue(0x8204,cid=cid,context=context,result=1);m.handle()
            assert m.read(m.state+28,2)==1 and m.read(m.state)==owner.ACTIVE
        m.enqueue(0x8204,context=1);m.handle()
        assert m.read(m.state+28,2)==0
        m.enqueue(0x8204,context=1,result=1);m.handle()  # Already acknowledged.
        assert m.read(m.state)==owner.ACTIVE
        assert m.send(packet)
        assert m.read(m.state+30,2)==2
        record('owned_send_'+str(length),m)
    for result,supplier in ((1,12),(0,6)):
        m=TaskFixture(original);m.ready();assert m.open();m.connected();assert m.send()
        m.enqueue(0x8204,context=1,result=result,supplier=supplier);m.handle()
        assert m.read(m.state)==owner.CLOSING and m.read(m.state+28,2)==0
        record(f'failed_send_{result}_{supplier}',m)
    for packet,pointer,size in ((b'\x83\0\x03',0,3),(b'\x83\0\x03',0xfffffffe,3),
                                (b'\x83\0\x04',TX_SOURCE,3),(b'abc',TX_SOURCE,2),
                                (bytes(1025),TX_SOURCE,1025)):
        m=TaskFixture(original);m.ready();assert m.open();m.connected()
        assert not m.send(packet,pointer,size) and len(m.requests)==2
        record(f'refuse_send_{pointer}_{size}_{packet[:3].hex()}',m)
    m=TaskFixture(original);m.ready();assert m.open();m.connected(mtu=255)
    assert not m.send(b'\x83\x01\x00'+bytes(253))
    record('send_exceeds_peer_mtu',m)
    m=TaskFixture(original);m.ready();assert m.open();m.connected()
    m.write(m.state+30,0xffff,2)
    assert not m.send() and m.read(m.state)==owner.CLOSING
    record('send_context_exhaustion_closes',m)
    m=TaskFixture(original);m.ready();assert m.open();m.connected()
    m.allocation_failure=3
    assert not m.send() and m.read(m.state+28,2)==0
    record('copy_allocation_failure',m)
    m=TaskFixture(original);m.ready();assert m.open();m.connected()
    m.write(m.state+4,0)
    assert not m.send() and len(m.requests)==2
    record('send_refuses_zero_cid',m)
    for phase in (owner.IDLE,owner.OPENING,owner.CLOSING,owner.CANCELLED):
        m=TaskFixture(original);m.ready();m.write(m.state,phase)
        assert not m.send() and len(m.requests)==1
        record('send_refuses_inactive_phase_'+str(phase),m)
    m=TaskFixture(original);m.ready();assert m.open();m.connected()
    for serial in range(1,21):
        assert m.send() and m.read(m.state+30,2)==serial
        m.enqueue(0x8204,context=serial);m.handle()
    assert m.read(m.state+28,2)==0 and m.read(m.state)==owner.ACTIVE
    record('sequential_send_credit_and_contexts',m)
    m=TaskFixture(original);m.ready();assert m.open();m.connected();assert m.send()
    m.enqueue(0x8206);m.handle()
    assert m.read(m.state)==owner.IDLE and m.read(m.state+28,2)==0
    assert m.open();m.connected();assert m.send()
    assert m.read(m.state+30,2)==2
    m.enqueue(0x8204,context=1,result=1);m.handle()
    assert m.read(m.state)==owner.ACTIVE and m.read(m.state+28,2)==1
    record('reused_cid_rejects_previous_send_context',m)
    m=TaskFixture(original);m.ready();assert m.open();m.connected()
    packet=b'\xa0\0\x03'
    m.enqueue(0x8205,payload=packet[:1]);m.handle()
    m.enqueue(0x8205,payload=packet[1:]);m.handle()
    assert m.packets==[packet]
    record('scheduled_owner_receive_to_framer',m)
    for phase in (owner.IDLE,owner.OPENING,owner.ACTIVE,owner.CLOSING,owner.CANCELLED):
        m=TaskFixture(original);m.ready()
        m.write(m.state,phase);m.write(m.state+4,CID)
        m.enqueue(0x8205,payload=b'x'*5);m.enqueue(0x8200);m.enqueue(1,event=0x999)
        before=len(m.operations)
        m.deinit()
        assert not m.messages and not m.packets
        assert all(kind not in ('ack','disconnect','post') for kind,_ in m.operations[before:])
        traces.append(dict(case='shutdown_drain_'+str(phase),steps=m.steps))

    return dict(cases=len(traces),registration_cases=len(registrations),registrations=registrations,traces=traces,
                binary_input_sha256=BASE_SHA,firmware_patched=False,native_executed=False,task_installed=False,lgu_built=False,
                helpers=[dict(address=hex(r['address']),purpose=r['purpose'],used_bytes=r['recipe']['used_bytes'],
                              bytes_hex=r['raw'].hex(),assembly=r['recipe'],relocation_recipe=r['relocations']) for r in task.assembled()],
                original_slices=[dict(start=hex(lo),end=hex(hi),sha256=hashlib.sha256(
                    original.get_data(lo-original.OPTIONAL_HEADER.ImageBase,hi-lo)).hexdigest()) for lo,hi in NATIVE],
                sources=['https://www.bluetooth.org/docman/handlers/DownloadDoc.ashx?doc_id=260870'],
                limits=['New task and original registration/configuration/mblk/destructor/CM factory instructions are interpreted',
                        'Allocator, clone/memset, startup configuration selection, scheduler get/post and physical CM/L2CAP delivery remain fixtures',
                        'Existing constructors retain native allocator-fatal behavior; only initial state/copy null failures are covered',
                        'DEINIT requires globally quiescent scheduler shutdown, not runtime destruction of a live channel',
                        'No native discovery/metadata binding, OBEX session, timer, decoder or GUI publication installed',
                        'Security argument must come from verified established stack policy; policy selection is not wired',
                        'One outstanding send; callers must defer further packets until the matching confirmation',
                        'TX contexts never wrap; exhaustion requires task restart after closure',
                        'No actual PE placement, relocation, loader/unwind, hardware Bluetooth or Spotify test'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_task.py','verify_bt_cover_task.py','bt_cover_art_owner.py','bt_cover_art_framer.py',
                              'verify_bt_cover_owner.py','verify_bt_cover_csr_bridge.py','verify_bt_cover_attribute.py',
                              'patch_bt_cover_attribute.py','patch_usb_seek_completion.py','patch_usb_folders.py',
                              'patch_usb_reliability.py','patch_updater_copy_safety.py','inspect_wave_queue.py',
                              'inspect_bt_lifecycle.py','verify_media_responsiveness.py')})


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--report',type=Path,required=True)
    args=parser.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'],registration_cases=result['registration_cases'],task_installed=False),indent=2))
