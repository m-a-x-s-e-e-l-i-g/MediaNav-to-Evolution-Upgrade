"""Regression fixtures over actual patched MIPS bytes, payloads and original WAM.

This executes a bounded Python instruction interpreter, never native firmware.
"""
import hashlib
import itertools
import json
import random
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent/'python-libs'))
import capstone
import pefile

from inspect_bt_playback import ROOT,BLUE_HASH,source,prefill
from inspect_bt_lifecycle import CTX,PCM,STACK,INPUT,HOLDER,SLOT,COUNT,unprepare
from inspect_wave_queue import BytesVM,STOP,WaveFixture,HASHES,WAM_RANGES,CORE_RANGES
from patch_bt_playback import patch_blue,BLOCK_BYTES,START_BUFFERS,QUEUE_LIMIT

TABLE,FILTER,NEXT_FILTER,NEXT=0x46000000,0x46001000,0x46002000,0x46003000


class Playback:
    def __init__(self,pe):
        self.vm=BytesVM(pe,[(0x26e14,0x270f4),(0x26400,0x26550),
                           (0x26d2c,0x26e14),(0x26c68,0x26d2c)])
        self.queued={};self.copies=[];self.writes=[];self.submitted=[];self.restarts=[]
        self.free=[];self.next_calls=[];self.pauses=0;self.lock_depth=0
        self.write_result=0;self.restart_result=0;self.failure_owned=False;self.gates=True
        self.manager=None
        vm=self.vm
        vm.write(TABLE,FILTER);vm.write(TABLE+4,NEXT_FILTER);vm.write(FILTER+8,CTX)
        vm.write(NEXT_FILTER+0x24,NEXT);vm.write(HOLDER,CTX);vm.write(0x110f9c,CTX)
        vm.write(CTX+8,0x1234);vm.write(CTX+4,2,1)
        vm.write(CTX+0x339,2,1);vm.write(CTX+0x33a,16,1);vm.write(CTX+0x33c,44100,2)
        for i in range(COUNT):
            h=CTX+0x10+i*32;vm.write(h,PCM+i*SLOT);vm.write(h+4,SLOT);vm.write(h+0x10,2)
        vm.hooks.update({0x19410:lambda _:0x123456,0x18220:lambda _:int(self.gates),
            0x18260:lambda _:int(self.gates),0x8a820:self.enter,0x8a810:self.leave,
            0x85758:self.copy,0x8a8e0:self.submit,0x8a8d0:self.restart,
            0x8a830:self.pause,0x85bb8:self.release_input,NEXT:self.next,
            0x8a7c0:lambda _:0,0x34264:lambda _:0,0x8a8c0:lambda _:0,
            0x193b4:self.format})

    def enter(self,vm):
        assert vm.reg[4]==0x110f84 and self.lock_depth==0
        self.lock_depth=1;return 0

    def leave(self,vm):
        assert vm.reg[4]==0x110f84 and self.lock_depth==1
        self.lock_depth=0;return 0

    def data(self,at,n):return bytes(self.vm.read(at+i,1) for i in range(n))

    def copy(self,vm):
        at,src,n=vm.reg[4:7];assert self.lock_depth==1 and 0<n<=BLOCK_BYTES
        slot=(at-PCM)//SLOT;assert 0<=slot<COUNT
        start=PCM+slot*SLOT;assert start<=at and at+n<=start+BLOCK_BYTES
        h=CTX+0x10+slot*32
        assert vm.read(h+0xc)==0 and vm.read(h+0x10)&0x12==2
        assert slot not in self.queued
        payload=self.data(src,n)
        for i,b in enumerate(payload):vm.write(at+i,b,1)
        self.copies.append(dict(slot=slot,offset=at-start,bytes=n));return at

    def submit(self,vm):
        h=vm.reg[5];i=(h-CTX-0x10)//32;assert 0<=i<COUNT and vm.reg[6]==32
        assert self.lock_depth==1 and vm.read(h)==PCM+i*SLOT
        assert vm.read(h+4)==BLOCK_BYTES and vm.read(h+0xc)==1 and i not in self.queued
        result=self.manager.write(h) if self.manager else self.write_result
        retained=result==0 or self.failure_owned
        payload=self.data(vm.read(h),BLOCK_BYTES)
        if retained:
            self.queued[i]=payload;self.submitted.append(payload)
            vm.write(h+0x10,(vm.read(h+0x10)|0x10)&~1)
        self.writes.append(dict(slot=i,result=result,bytes=BLOCK_BYTES,retained_ownership=retained))
        return result

    def restart(self,vm):
        assert self.lock_depth==1 and vm.reg[4]==0x1234
        assert self.vm.read(CTX+0x338,1)==0
        self.restarts.append(dict(pending=self.vm.read(CTX+5,1),result=self.restart_result))
        return self.restart_result

    def pause(self,_vm):self.pauses+=1;return 0
    def release_input(self,vm):self.free.append(vm.reg[4]);return 0
    def next(self,vm):
        assert vm.reg[4:8]==[1,TABLE,0,0] and vm.read(vm.reg[29]+0x10)==0
        self.next_calls.append(1);return 0
    def format(self,vm):
        vm.write(vm.reg[4],2,1);vm.write(vm.reg[5],16,1);vm.write(vm.reg[6],44100,2);return 0

    def packet(self,payload,owned_input=True):
        vm=self.vm
        for i,b in enumerate(payload):vm.write(INPUT+i,b,1)
        vm.reg[29]=STACK;vm.reg[31]=STOP;vm.write(STACK+0x10,len(payload))
        saved={i:0x12340000+i for i in (*range(16,24),30)}
        for i,v in saved.items():vm.reg[i]=v
        vm.reg[4:8]=[0,TABLE,int(owned_input),INPUT]
        vm.run(0x26e14,{STOP},limit=12000)
        assert vm.reg[29]==STACK and all(vm.reg[i]==v for i,v in saved.items())
        assert self.lock_depth==0
        assert vm.read(CTX+5,1)==len(self.queued)<=QUEUE_LIMIT
        assert vm.read(CTX+0x334)<BLOCK_BYTES
        assert 0<=vm.read(CTX+6,1)<COUNT
        for i in range(COUNT):assert bool(vm.read(CTX+0x1c+i*32))==(i in self.queued)

    def done(self,i):
        vm=self.vm;h=CTX+0x10+i*32
        self.queued.pop(i,None);vm.write(h+0x10,(vm.read(h+0x10)&~0x10)|1)
        vm.reg[29]=STACK;vm.write(STACK+0x1c,h);vm.reg[20]=0x110000;vm.reg[16]=0x110f84
        self.lock_depth=1;vm.run(0x26484,{0x264f0})
        assert self.lock_depth==0 and vm.read(CTX+5,1)==len(self.queued)

    def lifecycle(self,va):
        self.vm.reg[29]=STACK;self.vm.reg[4]=HOLDER;self.vm.reg[31]=STOP
        self.vm.run(va,{STOP})


def main():
    modules=json.loads((ROOT/'analysis/corpus/modules.json').read_text(encoding='utf-8'))
    blue=next(m for m in modules if m['origin']=='705md' and m['name']=='Blue.exe')
    item,original=source(blue,[0x26e14,0x26400,0x26d2c,0x26c68,0x26a8c],{})
    raw=(ROOT/blue['path']).read_bytes();patched,patch=patch_blue(raw);pe=pefile.PE(data=patched)
    checks={};cases=[]
    randomizer=random.Random(70502)
    # Continuous payload identity, partial appends, two-block splitting, repeated
    # producer wrap, late/duplicate completion and all preserved callee registers.
    p=Playback(pe);incoming=bytearray()
    for _ in range(400):
        size=randomizer.choice((1,3,4,511,512,1024,2048,4095,4096,4097,6656,8192))
        packet=randomizer.randbytes(size);incoming.extend(packet);p.packet(packet)
        while len(p.queued)>1:
            i=next(iter(p.queued));p.done(i);p.done(i)
    submitted=b''.join(p.submitted)
    assert submitted==incoming[:len(incoming)//BLOCK_BYTES*BLOCK_BYTES]
    partial=p.vm.read(CTX+0x334)
    assert p.data(p.vm.read(CTX+0x330),partial)==incoming[len(submitted):]
    assert len(p.free)==len(p.next_calls)==400
    checks['continuous_payload_packets']=400;checks['identity_checked_output_bytes']=len(submitted)
    cases.append(dict(kind='continuous_payload',input_bytes=len(incoming),submitted_bytes=len(submitted),
        partial_bytes=partial,producer_wraps=len(p.submitted)//COUNT,output_sha256=hashlib.sha256(submitted).hexdigest()))
    # Saturation cannot overwrite any of the four owned slots, or reset pending.
    p=Playback(pe);p.packet(bytes(16384));snapshot=dict(p.queued);before=len(p.copies)
    for _ in range(100):p.packet(bytes(8192))
    assert p.queued==snapshot and len(p.copies)==before and p.vm.read(CTX+5,1)==4
    p.done(0);p.packet(bytes([7])*4096);assert len(p.queued)==4 and p.writes[-1]['slot']==4
    checks['saturated_packets']=100
    # Prepared/OS ownership and producer dwUser are independent copy prerequisites.
    for flags,user in itertools.product((0,1,2,3,0x10,0x12,0x13),(0,1)):
        p=Playback(pe);p.vm.write(CTX+0x20,flags);p.vm.write(CTX+0x1c,user)
        if user:p.queued[0]=b'';p.vm.write(CTX+5,1,1)
        p.packet(bytes(4096))
        assert bool(p.copies)==(flags&0x12==2 and user==0)
    checks['header_ownership_cases']=14
    for result,owned in itertools.product((1,6,11,33,34),(False,True)):
        p=Playback(pe);p.write_result=result;p.failure_owned=owned;p.packet(bytes(8192))
        assert len(p.writes)==1 and len(p.restarts)==0
        assert p.vm.read(CTX+5,1)==int(owned) and p.vm.read(CTX+6,1)==int(owned)
        if owned:p.done(0)
        p.write_result=0;p.failure_owned=False;p.packet(bytes(8192))
        assert len(p.queued)==2 and p.vm.read(CTX+0x338,1)==1
    checks['write_failure_recovery_cases']=10
    p=Playback(pe);p.restart_result=1;p.packet(bytes(8192))
    assert len(p.queued)==2 and p.vm.read(CTX+0x338,1)==0 and len(p.restarts)==1
    p.packet(bytes(4096));assert len(p.copies)==2 and len(p.restarts)==2
    p.restart_result=0;p.packet(bytes(4096))
    assert len(p.restarts)==3 and p.vm.read(CTX+0x338,1)==1 and len(p.queued)==3
    checks['restart_failure_retry_sequences']=1
    for size in (0,1,4095,4096,4097,6656,8192,16384,65536,65537):
        p=Playback(pe);p.packet(bytes(size))
        assert len(p.submitted)==(min(size//4096,4) if size<=65536 else 0)
        assert p.free==[INPUT] and p.next_calls==[1]
    checks['input_boundary_cases']=10
    p=Playback(pe);p.gates=False;p.packet(bytes(4096));assert not p.copies
    p=Playback(pe);p.packet(bytes([9])*1000);p.lifecycle(0x26d2c)
    assert p.vm.read(CTX+0x334)==0
    p.packet(bytes([8])*4096);assert not p.writes
    p.lifecycle(0x26c68);p.packet(bytes([7])*4096)
    assert p.submitted==[bytes([7])*4096]
    checks['gate_stop_start_sequences']=2
    cleanup=[]
    for first_success in range(26):
        results=[1 if i<first_success else 0 for i in range(25)]
        assert unprepare(pe,results)==list(range(25))
        cleanup.append(first_success)
    checks['unprepare_return_classes']=len(cleanup)
    # Original WAM length/identity checks and its two completion queues are linked
    # to the actual patched Process/callback bytes, rather than a success-only API.
    sources=[item];rom={}
    for name,ranges in [('waveapi.dll',WAM_RANGES),('coredll.dll',CORE_RANGES)]:
        module=next(m for m in modules if m['origin']=='rom' and m['name']==name)
        assert module['sha256']==HASHES[name]
        s,q=source(module,[lo for lo,_ in ranges],{lo:hi-lo for lo,hi in ranges});sources.append(s);rom[name]=q
    for driver_result in (0,1,6,8,33):
        p=Playback(pe);wf=WaveFixture(rom['waveapi.dll'],rom['coredll.dll'],header_count=25,driver_result=driver_result)
        p.vm.mem.update(wf.mem);wf.mem=p.vm.mem;wf.vm=wf.wam_vm();p.manager=wf
        p.packet(bytes([5])*8192)
        if driver_result==0:
            assert len(p.queued)==2 and wf.vm.read(0x41000000+0x58)==2
            wf.complete(1);wf.drain_proxy();assert len(wf.app_queue)==1
            notification=wf.app_queue.pop(0);assert notification['header']==CTX+0x10
            p.done(0);assert p.vm.read(CTX+5,1)==1
            cases.append(dict(kind='patched_Blue_original_WAM_CORE',submitted_lengths=[w['bytes'] for w in p.writes],
                callback_header=hex(notification['header']),blue_pending_after_callback=1))
        else:assert not p.queued and p.vm.read(CTX+5,1)==0 and wf.vm.read(0x41000000+0x58)==0
    checks['linked_WAM_driver_return_cases']=5
    pcm=[]
    for rate in (44100,48000):
        old=prefill(8192,20481,11,rate)
        pcm.append(dict(rate=rate,channels=2,bits=16,original_start_pcm_ms=old['queued_duration_ms'],
            patched_start_pcm_ms=8192*1000/(rate*4),maximum_queue_pcm_ms=16384*1000/(rate*4),
            scope='Queued PCM duration; no measured wall-clock/device latency'))
    output=ROOT/'analysis/firmware/bt-patch';output.mkdir(parents=True,exist_ok=True)
    engine=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
    assembly=[]
    for r in patch['patch_ranges']:
        data=bytes.fromhex(r['after_hex']);va=int(r['va'],16)
        instructions=list(engine.disasm(data,va));assert sum(i.size for i in instructions)==len(data)
        assembly.append(f"; {r['reason']}\n")
        assembly.extend(f'{i.address:08x}  {i.mnemonic:10} {i.op_str}\n' for i in instructions)
    (output/'patched-paths.asm').write_text(''.join(assembly),encoding='utf-8')
    evidence=dict(status='passed',checks=checks,sources=sources,patch=patch,cases=cases,pcm=pcm,
        producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        patcher_sha256=hashlib.sha256((ROOT/'tools/patch_bt_playback.py').read_bytes()).hexdigest(),
        dependency_sha256={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest()
            for name in ('inspect_bt_playback.py','inspect_bt_lifecycle.py','inspect_wave_queue.py')},
        libraries=dict(capstone=capstone.__version__,pefile=pefile.__version__),
        native_execution=False,unit_tested=False,limitations=[
            'OS allocation/copy/write/restart/locks are explicit fixtures; payload identity is real fixture data',
            'No native scheduler, actual phone transport, jitter/underruns or device latency measurements',
            'Queue saturation drops excess incoming PCM; device tolerance requires listening/measurement',
            'CE completion-postloss, callback generation/lifetime, close-thread teardown and driver/kernel faults remain open'])
    (output/'contracts.json').write_text(json.dumps(evidence,indent=2),encoding='utf-8')
    print(json.dumps(dict(status='passed',checks=checks,output_sha256=patch['output_sha256'],pcm=pcm),indent=2))


if __name__=='__main__':main()
