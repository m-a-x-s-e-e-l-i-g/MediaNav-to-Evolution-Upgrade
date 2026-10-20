"""Interpret native response parsers against host client and malformed wire fixtures.

Strict mapped buffers, byte guards and ABI checks; no firmware or OS execution.
"""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path
import random
import struct
from types import SimpleNamespace

import bt_cover_art_responses as native
import bt_cover_art_client as host
from inspect_bt_lifecycle import SliceVM
from inspect_bt_pairing import data
from verify_bt_cover_attribute import SerializerVM
from verify_media_responsiveness import call, STACK

ROOT = Path(__file__).resolve().parents[1]
INPUT, OUTPUT, BODY, CID = 0x47000001, 0x48000000, 0x49000003, 0x12345678
GUARD = bytes.fromhex('a55aa55a')


@lru_cache(maxsize=1)
def helpers():
    return native.assembled()


class Image:
    OPTIONAL_HEADER = SimpleNamespace(ImageBase=0)

    def get_data(self, rva, size):
        for row in helpers():
            offset = rva-row['address']
            if 0 <= offset and offset+size <= len(row['raw']):
                return row['raw'][offset:offset+size]
        raise AssertionError('Instruction fetch outside assembled helpers')


class VM(SerializerVM):
    def __init__(self, packet, context=None, body=b''):
        super().__init__(Image(), [(r['address'], r['address']+len(r['raw'])) for r in helpers()])
        self.readable = [(INPUT, INPUT+len(packet)), (OUTPUT-4, OUTPUT+36),
                         (STACK-0x600, STACK+0x80)]
        self.writable = [(OUTPUT, OUTPUT+32), (STACK-0x600, STACK+0x80)]
        self.capacity = context[1] if context else 0
        if context:
            if context[0] == BODY and 0 < self.capacity <= host.MAX_IMAGE:
                self.readable.append((BODY-4, BODY+self.capacity+4))
                self.writable.append((BODY, BODY+self.capacity))
                self.put(BODY-4, GUARD); self.put(BODY+self.capacity, GUARD)
            self.put(OUTPUT, struct.pack('<8I', *context))
            self.put(BODY, body)
        else:
            self.put(OUTPUT, b'\xcc'*32)
        self.put(INPUT, packet)
        self.put(OUTPUT-4, GUARD); self.put(OUTPUT+32, GUARD)
        self.packet = packet

    def put(self, at, raw):
        for i, byte in enumerate(raw):
            SliceVM.write(self, at+i, byte, 1)

    def read(self, at, size=4):
        assert any(lo <= at and at+size <= hi for lo, hi in self.readable), ('Read outside buffers', hex(at), size)
        if size == 4: assert at%4 == 0, ('Unaligned DWORD read', hex(at))
        return super().read(at, size)

    def write(self, at, value, size=4):
        assert any(lo <= at and at+size <= hi for lo, hi in self.writable), ('Write outside buffers', hex(at), size)
        if size == 4: assert at%4 == 0, ('Unaligned DWORD write', hex(at))
        super().write(at, value, size)

    def owned(self):
        return {at:value for at,value in self.mem.items() if not STACK-0x600 <= at < STACK+0x80}

    def guards(self):
        assert data(self, OUTPUT-4, 4)==data(self, OUTPUT+32, 4)==GUARD
        assert data(self, INPUT, len(self.packet))==self.packet
        if (BODY-4, BODY+self.capacity+4) in self.readable:
            assert data(self, BODY-4, 4)==data(self, BODY+self.capacity, 4)==GUARD


def sequence(header, value):
    return bytes([header])+struct.pack('>H', len(value)+3)+value


def fixed(header, value):
    return bytes([header])+value.to_bytes(4,'big')


def packet(opcode, payload=b''):
    return bytes([opcode])+struct.pack('>H', len(payload)+3)+payload


def handshake(extra=b'', who=host.TARGET, cid=CID, mtu=1024):
    return packet(0xa0, b'\x15\0'+struct.pack('>H',mtu)+fixed(0xcb,cid)
                  +(sequence(0x4a,who) if who is not None else b'')+extra)


def connect_reference(raw):
    c=host.CoverArtClient()
    request=c.connect(0x106,0x100,0x1001,0)
    try:
        c.receive(request.ticket,raw,0)
        return c.connection_id,c.peer_mtu
    except host.ArtworkError:
        return None


def get_reference(raw, body=b'', declared=None, frames=0, cid=CID):
    c=host.CoverArtClient(decoder=lambda _:None)
    c.session=1;c.state='get';c.active=host.Ticket(1,1,1)
    c.connection_id=cid;c.body=bytearray(body);c.frames=frames
    c.declared_size=declared;c.deadline=10
    try:
        result=c.receive(c.active,raw,0)
        return (2 if result.cover is not None else 1,
                result.cover if result.cover is not None else bytes(c.body),c.declared_size,c.frames)
    except host.ArtworkError:
        return None


def verify():
    cases=[]

    def connect(raw, args=None):
        vm=VM(raw); before=vm.owned()
        expected=connect_reference(raw) if args is None else None
        status=call(vm,native.CONNECT,args or [INPUT,len(raw),OUTPUT],limit=50000)
        assert status==(1 if expected else 0xffffffff), (raw.hex(),hex(status),expected)
        if expected:
            assert data(vm,OUTPUT,8)==struct.pack('<2I',*expected)
            assert data(vm,OUTPUT+8,24)==b'\xcc'*24
        else: assert vm.owned()==before, 'Rejected handshake mutated buffers'
        vm.guards();cases.append(dict(kind='connect',status=hex(status),steps=vm.steps))
        return vm

    def get(raw, body=b'', declared=None, frames=0, cid=CID, context=None, args=None, expected=None):
        state=context or [BODY,host.MAX_IMAGE,len(body),declared or 0,int(declared is not None),frames,cid,0]
        vm=VM(raw,state,body);before=vm.owned()
        result=get_reference(raw,body,declared,frames,cid) if context is None and args is None else expected
        status=call(vm,native.GET,args or [OUTPUT,INPUT,len(raw)],limit=50000)
        assert status==(result[0] if result else 0xffffffff),(raw[:60].hex(),hex(status),result)
        if result:
            _,collected,new_declared,new_frames=result
            assert vm.read(OUTPUT+8)==len(collected)
            assert vm.read(OUTPUT+12)==(new_declared or 0)
            assert vm.read(OUTPUT+16)==int(new_declared is not None)
            assert vm.read(OUTPUT+20)==new_frames
            assert data(vm,BODY,len(collected))==collected
            for offset in (0,4,24,28):assert vm.read(OUTPUT+offset)==state[offset//4]
        else:assert vm.owned()==before,'Rejected GET mutated context/body'
        vm.guards();cases.append(dict(kind='get',status=hex(status),steps=vm.steps))
        return vm

    valid=handshake()
    for n in range(len(valid)):connect(valid[:n])
    for cid in (0,1,CID,0xffffffff):
        for mtu in (0,254,255,1024,65535):
            for who in (None,host.TARGET,b'wrong',host.TARGET[:-1]+b'x'):
                connect(handshake(cid=cid,mtu=mtu,who=who))
    for header in range(256):
        kind=header>>6
        extra=(sequence(header,b'\0\0' if kind==0 else b'xyz') if kind<2 else
               bytes([header,1]) if kind==2 else fixed(header,CID))
        connect(handshake(extra))
        get(packet(0x90,extra))
    for extra in (b'\x42',b'\x42\0',b'\x42\0\x02',b'\x42\x04\0',b'\x80',b'\xc0\0\0',
                  sequence(0x01,b'x'),sequence(0x01,b'xy'),fixed(0xcb,CID),sequence(0x4a,host.TARGET)):
        connect(handshake(extra));get(packet(0x90,extra))
    for pos, value in ((0,0x90),(3,0x14),(4,1),(1,1),(2,0)):
        bad=bytearray(valid);bad[pos]=value;connect(bytes(bad))
    connect(handshake(sequence(0x42,bytes(1024-len(valid)-3))))  # Exactly 1,024 bytes.
    connect(handshake(sequence(0x42,bytes(1025-len(valid)-3))))
    for args in ([0,len(valid),OUTPUT],[0xfffffff0,len(valid),OUTPUT],[INPUT,1025,OUTPUT],
                 [INPUT,len(valid),0],[INPUT,len(valid),0xfffffffc],[INPUT,len(valid),OUTPUT+1],
                 [INPUT,len(valid),INPUT-1],[INPUT,len(valid),INPUT+3]):
        connect(valid,args)

    for raw in (packet(0x90),packet(0xa0),packet(0xa0,sequence(0x49,b'abc')),
                packet(0x90,sequence(0x48,b'abc')),packet(0xa0,sequence(0x48,b'abc')),
                packet(0x90,sequence(0x49,b'abc')),packet(0xa0,sequence(0x49,b'')),
                packet(0xa0,sequence(0x49,b'a')+sequence(0x48,b'b')),
                packet(0xa0,sequence(0x49,b'a')+sequence(0x49,b'b')),
                packet(0xa0,fixed(0xcb,CID)+fixed(0xcb,CID)+sequence(0x49,b'a')),
                packet(0xa0,fixed(0xcb,CID+1)+sequence(0x49,b'a')),
                packet(0xa0,sequence(0x49,b'a')+b'\x80')):
        get(raw)
    complete=packet(0xa0,fixed(0xc3,5)+fixed(0xcb,CID)+sequence(0x48,b'ab')+sequence(0x49,b'cde'))
    for n in range(len(complete)):get(complete[:n])
    for n in (0,1,5,6,host.MAX_IMAGE,host.MAX_IMAGE+1,0xffffffff):
        get(packet(0xa0,fixed(0xc3,n)+sequence(0x49,b'abcde')))
        get(packet(0x90,fixed(0xc3,n)+fixed(0xc3,n)))
    for declared in (None,0,3,4,host.MAX_IMAGE):
        get(packet(0xa0,sequence(0x49,b'abc')),declared=declared)
        get(packet(0x90,fixed(0xc3,3)),declared=declared)
    get(packet(0x90,fixed(0xc3,3)+fixed(0xc3,4)))
    get(packet(0xa0,sequence(0x49,b'new')+b'\x80'),body=b'previous',declared=11,frames=3)
    for frames in (1023,1024,0xffffffff):get(packet(0xa0,sequence(0x49,b'x')),frames=frames)
    for used in (host.MAX_IMAGE-1,host.MAX_IMAGE):
        get(packet(0xa0,sequence(0x49,b'x')),body=bytes(used))
    for length in (3,255,1024,1025):
        raw=packet(0xa0,sequence(0x49,bytes(max(0,length-6)))) if length>=6 else packet(0x90)
        get(raw)
    good=packet(0xa0,sequence(0x49,b'abc'))
    for field,value in ((0,0),(0,0xfffffff0),(0,OUTPUT),(0,INPUT),(1,0),(1,host.MAX_IMAGE+1),
                        (8//4,host.MAX_IMAGE+1),(16//4,2),(20//4,1024),(16//4,0xffffffff)):
        ctx=[BODY,host.MAX_IMAGE,0,0,0,0,CID,0];ctx[field]=value
        get(good,context=ctx)
    for args in ([0,INPUT,len(good)],[OUTPUT+1,INPUT,len(good)],
                 [0xfffffff0,INPUT,len(good)],[OUTPUT,0,len(good)],
                 [OUTPUT,0xfffffff0,32],[OUTPUT,INPUT,1025],
                 [OUTPUT,OUTPUT+1,len(good)],[OUTPUT,BODY+1,len(good)]):get(good,args=args)
    # Exact small capacity; a failed final packet leaves the earlier body intact.
    get(good,context=[BODY,2,0,0,0,0,CID,0])
    get(good,context=[BODY,3,0,0,0,0,CID,0],expected=(2,b'abc',None,1))

    rng=random.Random(41)
    for _ in range(300):
        seed=rng.choice((valid,complete,packet(0x90,sequence(0x48,b'abc'))))
        mutated=bytearray(seed)
        for _ in range(rng.randrange(1,4)):mutated[rng.randrange(len(mutated))]=rng.randrange(256)
        (connect if seed is valid else get)(bytes(mutated))
    for _ in range(100):
        chunks=[rng.randbytes(rng.randrange(1,30)) for _ in range(rng.randrange(1,8))]
        headers=b''.join(sequence(0x48 if i<len(chunks)-1 else 0x49,chunk) for i,chunk in enumerate(chunks))
        get(packet(0xa0,fixed(0xc3,sum(map(len,chunks)))+headers))

    # Persistent native context across responses, not recreated per fragment.
    vm=VM(packet(0x90,sequence(0x48,b'ab')),[BODY,host.MAX_IMAGE,0,0,0,0,CID,0])
    for raw,status in ((packet(0x90,fixed(0xc3,5)+sequence(0x48,b'ab')),1),
                       (packet(0x90,sequence(0x48,b'cd')),1),
                       (packet(0xa0,sequence(0x49,b'e')),2)):
        vm.readable=[row for row in vm.readable if row[0]!=INPUT]+[(INPUT,INPUT+len(raw))]
        vm.put(INPUT,raw);vm.packet=raw
        assert call(vm,native.GET,[OUTPUT,INPUT,len(raw)])==status
        vm.guards()
    assert data(vm,BODY,5)==b'abcde' and vm.read(OUTPUT+20)==3
    cases.append(dict(kind='persistent_collection',steps=vm.steps))

    return dict(cases=len(cases),counts={kind:sum(r['kind']==kind for r in cases) for kind in
                                       ('connect','get','persistent_collection')},traces=cases,
                instruction_interpretation=True,firmware_patched=False,task_installed=False,lgu_built=False,
                helpers=[dict(address=hex(r['address']),purpose=r['purpose'],used_bytes=r['recipe']['used_bytes'],
                              bytes_hex=r['raw'].hex(),assembly=r['recipe'],relocation_recipe=r['relocations']) for r in helpers()],
                limits=['Import-free assembled parser instructions only; mapped buffers and execution are fixtures',
                        'Reference client decoder replaced with acceptance to compare collection, not JPEG validity',
                        'Complete packets only; task/framer/native protocol state, timers, metadata and GUI remain unwired',
                        'Collection context is serialized, mapped, owned and reset by caller before a new GET',
                        'Error preserves buffers; native session must close/invalidate before accepting further responses',
                        'Export addresses are interpreter placements, not verified PE allocations/loader/unwind'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_responses.py','verify_bt_cover_responses.py','bt_cover_art_client.py',
                              'verify_bt_cover_attribute.py','patch_usb_seek_completion.py','patch_usb_folders.py',
                              'patch_usb_reliability.py','patch_updater_copy_safety.py','inspect_wave_queue.py',
                              'inspect_bt_lifecycle.py','verify_media_responsiveness.py')})


def verify_route(raw):
    """Real task/owner/framer/parser instructions; protocol phase remains a fixture."""
    import pefile
    import bt_cover_art_task as task
    import bt_cover_art_owner as owner
    import bt_cover_art_framer as framer
    from patch_bt_cover_attribute import BASE_SHA
    from verify_bt_cover_task import TaskFixture
    from inspect_bt_pairing import put

    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact MAX04/MAX05 Blue.exe')
    original=pefile.PE(data=raw)

    class Route(TaskFixture):
        def __init__(self):
            super().__init__(original)
            self.pe.helpers=list(self.pe.helpers)+helpers()
            self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in helpers()]
            self.allowed += [(OUTPUT,OUTPUT+32),(BODY,BODY+host.MAX_IMAGE)]
            put(self,OUTPUT,bytes(32))
            self.phase='connect';self.statuses=[];self.completed=None

        def parse(self, address, args):
            saved,pc=list(self.reg),self.pc
            self.reg[4:8]=list(args)+[0]*(4-len(args))
            self.reg[31]=0xbeef0000
            self.run(address,{0xbeef0000},limit=50000)
            result=self.reg[2]
            self.reg,self.pc=saved,pc
            return result

        def packet(self,m):
            assert m.reg[4:6]==[self.state+owner.SIZE,self.state+owner.SIZE+4]
            if self.phase=='connect':
                status=self.parse(native.CONNECT,[m.reg[5],m.reg[6],OUTPUT])
                if status==1:
                    cid=self.read(OUTPUT)
                    put(self,OUTPUT,struct.pack('<8I',BODY,host.MAX_IMAGE,0,0,0,0,cid,0))
                    self.phase='get'  # Explicit fixture; native session binding remains absent.
            elif self.phase=='get':
                status=self.parse(native.GET,[OUTPUT,m.reg[5],m.reg[6]])
                if status==2:
                    self.completed=data(self,BODY,self.read(OUTPUT+8))
                    self.phase='done'
            else:status=0xffffffff
            self.statuses.append(status)
            return int(status!=0xffffffff)

    start=handshake()
    chunks=(packet(0x90,fixed(0xc3,9)+sequence(0x48,b'foo')),
            packet(0x90,sequence(0x48,b'bar')),packet(0xa0,sequence(0x49,b'baz')))
    rows=[]

    def route(name,fragments,statuses,completed=None,preserved=None):
        m=Route();m.ready();assert m.open();m.connected()
        for fragment in fragments:
            m.enqueue(0x8205,payload=fragment);m.handle()
        assert m.statuses==statuses,(name,m.statuses,statuses)
        assert m.completed==completed
        assert sum(kind=='ack' for kind,_ in m.operations)==len(fragments)
        closing=bool(statuses and statuses[-1]==0xffffffff)
        assert m.read(m.state)==(owner.CLOSING if closing else owner.ACTIVE)
        if preserved is not None:
            assert data(m,BODY,m.read(OUTPUT+8))==preserved
        if closing:assert sum(kind=='disconnect' for kind,_ in m.operations)==1
        # Receive heaps have already been freed; the copied body remains readable.
        m.enqueue(0x8206);m.handle();m.deinit()
        rows.append(dict(case=name,indications=len(fragments),statuses=statuses,
                         completed_bytes=len(completed or b''),steps=m.steps))

    for split in range(1,len(start)):
        route('handshake_split_'+str(split),[start[:split],start[split:]]+list(chunks),[1,1,1,2],b'foobarbaz')
    route('all_responses_coalesced',[start+b''.join(chunks)],[1,1,1,2],b'foobarbaz')
    route('one_byte_indications',[bytes([b]) for b in start+b''.join(chunks)],[1,1,1,2],b'foobarbaz')
    for split in range(1,len(chunks[-1])):
        route('final_split_'+str(split),[start]+list(chunks[:2])+[chunks[-1][:split],chunks[-1][split:]],
              [1,1,1,2],b'foobarbaz')
    for bad in (handshake(who=b'wrong'),handshake(fixed(0xcb,CID)),handshake(mtu=254)):
        route('invalid_handshake_'+bad.hex(),[bad],[0xffffffff])
    for bad in (packet(0xa0,sequence(0x49,b'x')),packet(0xa0,sequence(0x49,b'baz')+b'\x80'),
                packet(0xa0,fixed(0xcb,CID+1)+sequence(0x49,b'baz')),
                packet(0x90,sequence(0x49,b'baz'))):
        route('reject_after_partial_'+bad.hex(),[start]+list(chunks[:2])+[bad],
              [1,1,1,0xffffffff],preserved=b'foobar')
    return dict(cases=len(rows),traces=rows,binary_input_sha256=BASE_SHA,
                limits=['Original scheduler get/post/allocator and protocol-phase callback remain fixtures',
                        'Task HANDLE, owner dispatch, framing and native response parsing execute together',
                        'Handshake-to-GET transition and collection buffer are fixture-owned, not a native session',
                        'No CONNECT/GET request scheduling, deadlines, metadata correlation, JPEG decode or GUI'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_task.py','verify_bt_cover_task.py','bt_cover_art_owner.py',
                              'bt_cover_art_framer.py','verify_bt_cover_owner.py','verify_bt_cover_csr_bridge.py',
                              'patch_bt_cover_attribute.py','inspect_bt_pairing.py')})


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--report',type=Path,required=True)
    parser.add_argument('--input',type=Path,help='Also interpret task/owner/framer/parser route using exact Blue.exe')
    args=parser.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    result=verify()
    if args.input:result['receive_route']=verify_route(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'],counts=result['counts'],
                          receive_routes=result.get('receive_route',{}).get('cases',0),task_installed=False),indent=2))
