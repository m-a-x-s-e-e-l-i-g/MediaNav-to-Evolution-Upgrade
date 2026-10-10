"""Bounded interpreter checks for actual startup retry bytes and ownership guards.

OS/thread/semaphore/phone delivery remain fixtures. No native firmware execution.
"""
import hashlib
import json
from pathlib import Path
from audit_bt_startup_silence import VM, AV, CTX, PCM, INPUT, LIST, NEXT, WIN, SINK
from audit_bt_stream_start import ROOT
from inspect_wave_queue import STOP
from patch_bt_startup_audio import patch, INPUT_HASH
from verify_bt_patch import Playback
import pefile

GLOBAL, REMOTE, IND, IDS, RESPONSE, SBC = (0x4a000000 + i*0x1000 for i in range(6))
SBC_TABLE = 0x1102e4
PE_CACHE = {}


class StartupVM(VM):
    def internal_call(self, va):
        return super().internal_call(va) or va in (0x1ab90, 0x1ace4, 0x207f4)


class Fixture:
    def __init__(self, raw, *, wave=(0,), thread=(True,), prep_fail=None, wait=0,
                 release=1, priority=1, channels=2, rate=44100, bits=16,
                 ambiguous=False, zero_handle=False, zero_tid=False, chain=1,
                 late_owner=False):
        digest = hashlib.sha256(raw).hexdigest()
        if digest not in PE_CACHE:
            PE_CACHE[digest] = pefile.PE(data=raw)
        self.vm = StartupVM(PE_CACHE[digest], [(0x1ab90,0x1b088), (0x207f4,0x20a08),
            (0x25a5c,0x25e84), (0x2639c,0x26400), (0x266a4,0x26e14), (0x26e14,0x270f4)])
        self.wave_results, self.thread_results = list(wave), list(thread)
        self.prep_fail, self.wait_result, self.release_result, self.priority = prep_fail, wait, release, priority
        self.ambiguous, self.zero_handle, self.zero_tid, self.late_owner = ambiguous, zero_handle, zero_tid, late_owner
        self.format_value = (channels,bits,rate)
        self.chain = chain
        self.events, self.messages, self.responses, self.copies, self.writes = [], [], [], [], []
        self.threads, self.thread_ids, self.wave_handles, self.prepared = set(), {}, set(), set()
        self.wave_calls, self.thread_calls, self.prepare_calls, self.lock_depth = 0, 0, 0, 0
        self.phase = "fixture"
        vm = self.vm
        for lo,hi in ((0x25b78,0x25b88),(WIN,WIN+0x3c),(SINK,SINK+0x3c),(SBC_TABLE,SBC_TABLE+0x3c)):
            for i,b in enumerate(vm.pe.get_data(lo-vm.base,hi-lo)):
                vm.write(lo+i,b,1)
        tables = [WIN] if chain == 1 else [SBC_TABLE,WIN,SINK]
        for i,table in enumerate(tables):
            vm.write(AV+0x48+4*i,table)
            vm.write(AV+0x70+4*i,CTX if table == WIN else SBC+0x100*i)
            vm.write(table+7,1,1)
        vm.write(AV+0x98,chain,1)
        vm.write(AV+0x11c,1,1)
        vm.write(AV+0x11d,1,1)
        vm.write(WIN+8,CTX)
        vm.write(CTX+0x10,PCM)
        vm.write(0x110f9c,CTX)
        vm.write(0x110f98,0x77)
        vm.write(LIST,WIN)
        vm.write(LIST+4,SINK)
        vm.write(SINK+0x24,NEXT)
        vm.write(0x20e1e8,GLOBAL)
        vm.write(GLOBAL+0x268,AV)
        vm.write(GLOBAL+0x26c,REMOTE)
        vm.write(AV+0x27,7,1)
        vm.write(AV+0x21,2,1)
        vm.write(IND+2,9,1)
        vm.write(IND+3,1,1)
        vm.write(IND+4,IDS)
        vm.write(IDS,7,1)
        for i in range(16384):
            vm.write(INPUT+i,i*17&255,1)

        def simple_event(name,result=0):
            def fn(machine):
                self.events.append(dict(phase=self.phase,call=name,args=list(machine.reg[4:7])))
                return result
            return fn

        self.apis = {0x193b4:self.format, 0x8a7c0:lambda _:0, 0x34264:lambda _:0,
            0x8a7f0:self.create_thread, 0x8a880:self.wave_open, 0x8a870:self.prepare,
            0x8a830:self.pause, 0x8a8c0:simple_event('reset'), 0x8a8b0:simple_event('unprepare'),
            0x8a8a0:self.wave_close, 0x8a890:self.terminate, 0x3a750:self.memset,
            0x8a820:lambda _:0, 0x8a810:lambda _:0, 0x85758:self.copy,
            0x8a8e0:self.submit, 0x8a8d0:simple_event('restart'),
            0x85bb8:simple_event('free_input'), NEXT:lambda _:0,
            0x19410:lambda _:AV, 0x18220:lambda _:self.vm.read(AV+0x11c,1),
            0x18260:lambda _:self.vm.read(AV+0x11d,1),
            0x259f8:lambda _:0x1234, 0x85b70:lambda _:RESPONSE,
            0x7815c:self.respond, 0x33538:self.emit,
            0x31f40:lambda _:1, 0x31dd4:lambda _:0, 0x1eca8:simple_event('remote_play'),
            0x1d68c:simple_event('metadata'),
            0xf0000001:lambda _:self.priority, 0xf0000002:self.wait,
            0xf0000003:self.release, 0xf0000004:self.sleep,
            0xf0000005:self.exit_code, 0xf0000006:self.close_handle,
            0xf0000007:lambda _:8}
        for address,target in ((0x11005c,0xf0000001),(0x110024,0xf0000002),
            (0x110058,0xf0000003),(0x110010,0xf0000004),(0x110068,0xf0000005),
            (0x110020,0xf0000006),(0x110060,0xf0000007)):
            vm.write(address,target)
        # Real dispatcher traverses three tables; these two non-WinPlay filter
        # lifecycle callbacks remain explicit Boolean fixtures.
        if chain == 3:
            for table in (SBC_TABLE,SINK):
                for slot in (0x14,0x18,0x1c,0x20):
                    target = vm.read(table+slot)
                    assert target not in (0x266a4,0x26a8c,0x26c68,0x26d2c)
                    self.apis[target] = simple_event('other_filter',1)
        vm.hooks = {address:self.wrap(fn) for address,fn in self.apis.items()}

    def wrap(self,fn):
        def wrapped(vm):
            result = fn(vm)
            for i in (1,*range(3,16),24,25):
                vm.reg[i] = 0xfabc0000+i
            return result
        return wrapped

    def format(self,vm):
        for pointer,value,size in zip(vm.reg[4:7],self.format_value,(1,1,2)):
            vm.write(pointer,value,size)
        return 0

    def create_thread(self,vm):
        self.thread_calls += 1
        assert not self.threads, 'Duplicate live playback thread'
        assert vm.reg[4:8] == [0,0,0x26400,0] and vm.read(vm.reg[29]+0x10) == 0
        ok = self.thread_results[min(self.thread_calls-1,len(self.thread_results)-1)]
        self.events.append(dict(phase=self.phase,call='create_thread',attempt=self.thread_calls,ok=ok))
        if not ok:
            return 0
        handle,tid = 0x9000+self.thread_calls,0xa000+self.thread_calls
        self.threads.add(handle)
        self.thread_ids[handle] = tid
        vm.write(vm.read(vm.reg[29]+0x14),0 if self.zero_tid else tid)
        return handle

    def wait(self,vm):
        assert vm.reg[4:6] == [0x77,0xffffffff] and self.lock_depth == 0
        if self.wait_result == 0:
            self.lock_depth = 1
        self.events.append(dict(phase=self.phase,call='wait',result=self.wait_result))
        return self.wait_result

    def release(self,vm):
        assert vm.reg[4:7] == [0x77,1,0] and self.lock_depth == 1
        if self.release_result:
            self.lock_depth = 0
        self.events.append(dict(phase=self.phase,call='release',result=self.release_result))
        return self.release_result

    def sleep(self,vm):
        self.events.append(dict(phase=self.phase,call='sleep',ms=vm.reg[4],semaphore_owned=self.lock_depth))
        assert vm.reg[4] in (0,25)
        if self.late_owner and vm.reg[4] == 25 and self.wave_calls:
            self.wave_handles.add(0xc001)
            vm.write(CTX+8,0xc001)
        return 0

    def wave_open(self,vm):
        self.wave_calls += 1
        assert self.lock_depth == 1 and vm.reg[4:6] == [CTX+8,0xffffffff]
        assert vm.read(CTX+8) == 0, 'Overwriting an existing output owner'
        assert vm.reg[7] == self.thread_ids[vm.read(CTX+0xc)]
        assert vm.read(vm.reg[29]+0x14) == 0x20000 and vm.read(vm.reg[29]+0x10) == 0
        channels,bits,rate = self.format_value
        fmt = [vm.read(vm.reg[6]+offset,size) for offset,size in ((0,2),(2,2),(4,4),(8,4),(12,2),(14,2),(16,2))]
        assert fmt == [1,channels,rate,rate*channels*(bits//8),channels*(bits//8),bits,0]
        error = self.wave_results[min(self.wave_calls-1,len(self.wave_results)-1)]
        handle = 0 if (error and not self.ambiguous) or self.zero_handle else 0xb000+self.wave_calls
        vm.write(vm.reg[4],handle)
        if handle:
            self.wave_handles.add(handle)
        self.events.append(dict(phase=self.phase,call='wave_open',attempt=self.wave_calls,error=error,
            handle=handle,tid=vm.reg[7],format=fmt))
        return error

    def prepare(self,vm):
        index = (vm.reg[5]-CTX-0x10)//32
        assert 0<=index<25 and vm.reg[4] in self.wave_handles and vm.reg[6] == 32
        assert vm.read(vm.reg[5]) == PCM+index*25600 and vm.read(vm.reg[5]+4) == 25600
        assert self.lock_depth == 0 and vm.read(CTX+4,1) != 2
        self.prepare_calls += 1
        if index == self.prep_fail:
            self.events.append(dict(phase=self.phase,call='prepare_failure',index=index))
            return 1
        self.prepared.add(vm.reg[5])
        vm.write(vm.reg[5]+0x10,2)
        return 0

    def pause(self,vm):
        assert vm.reg[4] in self.wave_handles and len(self.prepared) == 25
        self.events.append(dict(phase=self.phase,call='pause',handle=vm.reg[4]))
        return 0

    def wave_close(self,vm):
        assert vm.reg[4] in self.wave_handles
        self.wave_handles.remove(vm.reg[4])
        self.prepared.clear()
        return 0

    def exit_code(self,vm):
        assert vm.reg[4] in self.threads
        vm.write(vm.reg[5],259)
        return 1

    def terminate(self,vm):
        assert vm.reg[4] in self.threads
        self.threads.remove(vm.reg[4])
        return 1

    def close_handle(self,vm):
        assert vm.reg[4] not in self.threads
        return 1

    def memset(self,vm):
        assert vm.reg[4:7] == [PCM,0,640000]
        return PCM

    def copy(self,vm):
        at,src,n = vm.reg[4:7]
        slot = (at-PCM)//25600
        header = CTX+0x10+32*slot
        assert 0<=slot<25 and header in self.prepared and vm.read(CTX+4,1) == 2
        assert vm.read(header+0xc) == 0 and vm.read(header+0x10)&0x12 == 2
        assert INPUT<=src and src+n<=INPUT+16384 and PCM+slot*25600<=at and at+n<=PCM+slot*25600+4096
        for i in range(n):
            vm.write(at+i,vm.read(src+i,1),1)
        self.copies.append(dict(bytes=n,slot=slot))
        return at

    def submit(self,vm):
        header = vm.reg[5]
        assert header in self.prepared and vm.reg[4] in self.wave_handles
        assert vm.read(header+4) == 4096 and vm.read(header+0xc) == 1
        at = vm.read(header)
        self.writes.append(bytes(vm.read(at+i,1) for i in range(4096)))
        vm.write(header+0x10,0x12)
        return 0

    def respond(self,vm):
        self.responses.append(dict(type=vm.read(vm.reg[4],2),error=vm.read(vm.reg[4]+0xc,1)))
        return 0

    def emit(self,vm):
        self.messages.append(list(vm.reg[4:7]))
        return 1

    def invoke(self,entry,args,size=None):
        vm = self.vm
        stack = vm.reg[29]
        saved = {i:0x12340000+i for i in (*range(16,24),30)}
        canaries = {stack-0x200:0xabcdef01,stack+0x80:0xabcdef02}
        for at,value in canaries.items():
            vm.write(at,value)
        for i,value in saved.items():
            vm.reg[i] = value
        vm.reg[31] = STOP
        vm.reg[4:4+len(args)] = args
        if size is not None:
            vm.write(stack+0x10,size)
        self.phase = hex(entry)
        vm.run(entry,{STOP},limit=20000)
        assert vm.reg[29] == stack and all(vm.reg[i] == value for i,value in saved.items())
        assert all(vm.read(at) == value for at,value in canaries.items())
        return vm.reg[2]

    def open_start(self):
        opened = self.invoke(0x25a5c,[0,AV,2])
        started = self.invoke(0x25a5c,[0,AV,4])
        return opened,started

    def packet(self,size=8192):
        self.invoke(0x26e14,[0,LIST,1,INPUT],size)

    def result(self,name):
        return dict(name=name,thread_calls=self.thread_calls,wave_calls=self.wave_calls,
            active_threads=len(self.threads),prepared=len(self.prepared),filter_state=self.vm.read(WIN+7,1),
            context_state=self.vm.read(CTX+4,1),handle=self.vm.read(CTX+8),events=self.events,
            messages=self.messages,responses=self.responses,pcm_bytes=sum(len(b) for b in self.writes),
            pcm_sha256=hashlib.sha256(b''.join(self.writes)).hexdigest(),instructions=self.vm.steps)


def structure(before,after,recipe):
    assert hashlib.sha256(before).hexdigest() == INPUT_HASH
    assert hashlib.sha256(after).hexdigest() == recipe['output_sha256']
    restored = bytearray(after)
    allowed = set()
    for row in recipe['edits']:
        at = row['offset']; old,new = bytes.fromhex(row['before_hex']),bytes.fromhex(row['after_hex'])
        assert before[at:at+len(old)] == old and after[at:at+len(new)] == new
        restored[at:at+len(old)] = old
        allowed.update(range(at,at+len(old)))
    assert bytes(restored) == before
    assert all(a==b or i in allowed for i,(a,b) in enumerate(zip(before,after)))
    a,b = pefile.PE(data=before),pefile.PE(data=after)
    assert a.FILE_HEADER.__pack__() == b.FILE_HEADER.__pack__() and a.OPTIONAL_HEADER.__pack__() == b.OPTIONAL_HEADER.__pack__()
    for old,new in zip(a.sections,b.sections):
        assert old.__pack__() == new.__pack__()
        if old.Name.rstrip(b'\0') != b'.text':
            assert old.get_data() == new.get_data()
    preserved = [(0x266a4,0x266c4),(0x26a64,0x26a8c),(0x26c68,0x26c78),
                 (0x26d14,0x26d20),(0x26d24,0x26d2c),(0x26400,0x26550),
                 (0x26d2c,0x26e14),(0x26e14,0x270f4),(0x25b78,0x25b88)]
    for lo,hi in preserved:
        assert a.get_data(lo-a.OPTIONAL_HEADER.ImageBase,hi-lo) == b.get_data(lo-b.OPTIONAL_HEADER.ImageBase,hi-lo)
    # Reject external direct calls/branches into removed interiors. Existing
    # switch-table entry for START is at the preserved case boundary 25db8.
    boundaries = [(0x266a4,0x26a8c),(0x26c68,0x26d2c),(0x25a5c,0x25e84),(0x1ace4,0x1b088)]
    interiors = [(0x266c4,0x26a64),(0x26c78,0x26d14),(0x25db8,0x25e04),(0x1aebc,0x1aee4)]
    import struct
    text = next(s for s in a.sections if s.Name.rstrip(b'\0') == b'.text')
    base = a.OPTIONAL_HEADER.ImageBase+text.VirtualAddress
    text_bytes = text.get_data()
    for offset in range(0,len(text_bytes)-3,4):
        pc = base+offset; word = struct.unpack_from('<I',text_bytes,offset)[0];op = word>>26
        if op in (2,3):
            target = (pc+4)&0xf0000000 | (word&0x3ffffff)<<2
        elif op in (4,5,6,7,1):
            imm = word&65535; signed = imm if imm<32768 else imm-65536
            target = pc+4+signed*4
        else:
            continue
        for lo,hi in interiors:
            if lo<=target<hi:
                owner = next((p for p in boundaries if p[0]<=lo<p[1]),None)
                assert owner and owner[0]<=pc<owner[1], (hex(pc),hex(target))
    return dict(cases=1,exact_reversal=True,headers_sections_unwind_and_prior_audio_bytes_preserved=True,
                external_direct_interior_references=0,indirect_references_not_proven=True)


def verify(before,after,recipe):
    cases = []
    for channels in (1,2):
        for rate in (16000,32000,44100,48000):
            f = Fixture(after,channels=channels,rate=rate)
            assert f.open_start() == (1,1)
            f.packet()
            assert len(f.threads) == 1 and f.thread_calls == f.wave_calls == 1
            assert not any(e['call']=='sleep' for e in f.events)
            assert b''.join(f.writes) == bytes(i*17&255 for i in range(8192))
            cases.append(f.result(f'normal-{channels}-{rate}'))
    good = [dict(name='wave_once',wave=(4,0)),dict(name='thread_once',thread=(False,True)),
            dict(name='both_once',thread=(False,True),wave=(4,0)),dict(name='priority_failure',priority=0)]
    for chain in (1,3):
        for spec in good:
            spec = spec.copy();name = spec.pop('name')
            f = Fixture(after,chain=chain,**spec)
            assert f.open_start() == (1,1)
            f.packet()
            assert len(f.threads) == 1 and f.thread_calls<=2 and f.wave_calls<=2
            assert b''.join(f.writes) == bytes(i*17&255 for i in range(8192))
            assert all(e['ms']==25 for e in f.events if e['call']=='sleep')
            cases.append(f.result(f'{name}-chain{chain}'))
    bad = [dict(name='wave_persistent',wave=(4,)),dict(name='thread_persistent',thread=(False,)),
        dict(name='ambiguous_wave',wave=(4,),ambiguous=True),dict(name='zero_success_handle',zero_handle=True),
        dict(name='zero_thread_id',zero_tid=True),dict(name='wait_failure',wait=0xffffffff),
        dict(name='wait_abandoned',wait=0x80),dict(name='release_failure',release=0),
        dict(name='late_owner',wave=(4,),late_owner=True)]
    bad += [dict(name=f'prepare_failure_{i}',prep_fail=i) for i in range(25)]
    for chain in (1,3):
        for spec in bad:
            spec = spec.copy();name = spec.pop('name')
            f = Fixture(after,chain=chain,**spec)
            assert f.open_start() == (0,0)
            assert f.vm.read(WIN+7,1) == 2 and f.vm.read(CTX+4,1) == 0
            f.packet()
            assert not f.copies and not f.writes and f.thread_calls<=2 and f.wave_calls<=2
            # A failed attempt's resources block duplicate allocation on another
            # request. Permanent CreateThread failure has no owner and may retry.
            if f.threads:
                counts = (f.thread_calls,f.wave_calls)
                later_open,later_start = f.open_start()
                assert later_start == 0 and counts == (f.thread_calls,f.wave_calls), name
            assert len(f.threads)<=1
            if name in ('ambiguous_wave','zero_success_handle','late_owner'):
                assert f.wave_calls == 1
            cases.append(f.result(f'{name}-chain{chain}'))
    # Existing owners, missing PCM and NULL arguments stop before new resources.
    for mode in ('wave_owner','worker_owner','missing_pcm','null_arg','null_ctx'):
        f = Fixture(after)
        if mode == 'wave_owner':
            f.vm.write(CTX+8,0xb999);f.vm.write(CTX+4,1,1)
        elif mode == 'worker_owner':
            f.vm.write(CTX+0xc,0x9999)
        elif mode == 'missing_pcm':
            f.vm.write(CTX+0x10,0)
        elif mode == 'null_ctx':
            f.vm.write(AV+0x70,0)
        assert f.invoke(0x266a4,[0 if mode=='null_arg' else AV+0x70]) == 0
        assert not f.events and f.thread_calls == f.wave_calls == 0
        if mode == 'wave_owner':
            assert f.vm.read(CTX+8)==0xb999 and f.vm.read(CTX+4,1)==1
        cases.append(f.result(mode))
    # The native incoming StartInd and outgoing StartCfm use the new routines.
    for entry in (0x1ace4,0x1ab90):
        for chain in (1,3):
            for label,params,ok in (('normal',{},True),('retry',dict(wave=(4,0)),True),
                                   ('persistent',dict(wave=(4,)),False),('partial',dict(prep_fail=24),False)):
                f = Fixture(after,chain=chain,**params)
                if entry == 0x1ab90:
                    f.invoke(0x25a5c,[0,AV,2])
                    f.vm.write(IND+6,0x8000,2);f.vm.write(IND+8,0x14,2)
                f.invoke(entry,[GLOBAL,AV,IND])
                assert f.vm.read(WIN+7,1) == (3 if ok else 2)
                assert f.vm.read(CTX+4,1) == (2 if ok else 0)
                if entry == 0x1ace4:
                    assert f.vm.read(AV+0x11d,1) == int(ok)
                    assert f.responses == [dict(type=0x1a,error=0)]  # Peer protocol stream accepted.
                f.packet()
                assert bool(f.writes) == ok
                cases.append(f.result(f'handler-{hex(entry)}-{label}-chain{chain}'))
    # A later real PlayReq cannot create an extra worker after permanent failure.
    for label,params,ok in (('normal',{},True),('retry',dict(wave=(4,0)),True),('persistent',dict(wave=(4,)),False)):
        f = Fixture(after,chain=3,**params)
        f.open_start();counts=(f.thread_calls,f.wave_calls)
        f.invoke(0x207f4,[GLOBAL])
        assert counts == (f.thread_calls,f.wave_calls)
        assert f.vm.read(WIN+7,1) == (3 if ok else 2)
        cases.append(f.result('play-request-'+label))
    # Check reconfiguration both succeeds and propagates a new open failure.
    for failing in (False,True):
        f = Fixture(after)
        assert f.open_start()==(1,1)
        f.format_value=(1,16,48000)
        if failing:
            f.wave_results=[0,4]
        result = f.invoke(0x26c68,[AV+0x70])
        assert result == int(not failing) and f.vm.read(CTX+4,1)==(0 if failing else 2)
        assert len(f.threads)==1
        cases.append(f.result('reconfigure-'+str(failing)))
    # Paired counterexamples execute the same real dispatcher with old bytes.
    comparisons=[]
    for failure,params in (('wave',dict(wave=(4,0))),('thread',dict(thread=(False,True)))):
        old,new = Fixture(before,**params),Fixture(after,**params)
        assert old.open_start()==(0,1) and old.vm.read(WIN+7,1)==3 and old.vm.read(CTX+8)==0
        old.packet();assert not old.copies
        assert new.open_start()==(1,1)
        new.packet();assert len(new.writes)==2
        comparisons.append(dict(failure=failure,old=old.result('old'),new=new.result('new')))
    return dict(cases=len(cases)+len(comparisons),traces=cases,counterexamples=comparisons,
                fixture_limitations=['OS/thread outcomes explicit; no scheduler/native phone or physical output',
                    'Three-filter dispatcher cases use fixtures for SBC/sink lifecycle callbacks',
                    'Existing WinPlayClose cleanup-failure semantics unchanged',
                    'waveOutPause failure handling unchanged; this targets opening/readiness'])


def retained_playback(raw):
    p = Playback(pefile.PE(data=raw))
    p.lifecycle(0x26c68)
    packets = [bytes((i*7+j)&255 for j in range(n)) for i,n in enumerate([512,1024,2048,4096,8192]*12+[8192]*4)]
    incoming = b''.join(packets)
    for data in packets:
        p.packet(data)
        # Deliver explicit completions before saturation, preserving real payload.
        while len(p.queued)>1:
            p.done(next(iter(p.queued)))
    combined = b''.join(p.submitted)
    assert combined == incoming[:len(combined)] and len(combined)==len(incoming)//4096*4096
    # Existing restart failure retry, saturated queue, duplicate callbacks, stop/start.
    q = Playback(pefile.PE(data=raw));q.lifecycle(0x26c68);q.restart_result=1
    q.packet(b'A'*8192)
    from inspect_bt_lifecycle import CTX as PLAY_CTX
    assert q.vm.read(PLAY_CTX+0x338,1)==0
    q.restart_result=0;q.packet(b'B'*8192)
    assert q.vm.read(PLAY_CTX+0x338,1)==1 and len(q.queued)==4
    previous=b''.join(q.submitted);q.packet(b'C'*8192);assert b''.join(q.submitted)==previous
    index=next(iter(q.queued));q.done(index);pending=q.vm.read(PLAY_CTX+5,1);q.done(index)
    assert q.vm.read(PLAY_CTX+5,1)==pending
    q.lifecycle(0x26d2c);q.queued.clear()
    # Reset outcomes are fixtures; start itself now runs the modified native bytes.
    for i in range(25):
        q.vm.write(PLAY_CTX+0x1c+32*i,0);q.vm.write(PLAY_CTX+0x20+32*i,2)
    q.vm.write(PLAY_CTX+5,0,1);q.lifecycle(0x26c68);q.packet(b'D'*8192)
    assert q.submitted[-2:] == [b'D'*4096,b'D'*4096]
    return dict(cases=6,packets=len(packets),submitted_bytes=len(combined),sha256=hashlib.sha256(combined).hexdigest(),
                two_block_start=True,restart_retry=True,saturation_ownership=True,double_callback=True,stop_start=True)


def main():
    before=(ROOT/'build/usb-option-snapshot-development-01/payload/upgrade/Storage Card/System/Blue.exe').read_bytes()
    after,r=patch(before)
    proof=dict(recipe=r,structure=structure(before,after,r),behavior=verify(before,after,r),
               retained_playback=retained_playback(after),native_executed=False,hardware_tested=False)
    print(json.dumps(dict(structure=proof['structure']['cases'],behavior=proof['behavior']['cases'],
                         playback=proof['retained_playback'],sha256=r['output_sha256'])))


if __name__=='__main__':main()
