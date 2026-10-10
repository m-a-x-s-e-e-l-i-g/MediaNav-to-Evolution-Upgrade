"""Interpret actual release/candidate MIPS bytes with explicit GUI/file/graph fixtures.

Not Windows CE, touchscreen, scheduler, audio or elapsed-time testing.
"""
import hashlib
import json
import random
import struct
from functools import lru_cache
from pathlib import Path
import pefile
from verify_ui_english import UiVM
from inspect_bt_pairing import put, data
from inspect_wave_queue import STOP
from patch_media_responsiveness import patch_app, patch_usb, APP_SHA, USB_SHA

ROOT = Path(__file__).resolve().parents[1]
SYSTEM = ROOT/'build/updater-copy-safety-development-02/payload/upgrade/Storage Card/System'
STACK, BUTTON, DIALOG, POINT, VTABLE = 0x68000000, 0x41000000, 0x42000000, 0x43000000, 0x44000000
COOKIE = 0x1234abcd


@lru_cache(maxsize=4)
def parsed(raw):return pefile.PE(data=raw)


class VM(UiVM):
    def plain(self, word):
        # Architectural little-endian merge operations, including the original
        # unaligned CPlayControl state DWORD at +292a. Other opcodes fail closed.
        op, rs, rt = word >> 26, (word >> 21)&31, (word >> 16)&31
        if op in (0x22, 0x26, 0x2a, 0x2e):
            imm = word&65535
            if imm&32768: imm -= 65536
            at = (self.reg[rs]+imm)&0xffffffff
            aligned, n = at&~3, at&3
            if op == 0x22:
                bits = (n+1)*8; shift = (3-n)*8
                value = int.from_bytes(data(self, aligned, n+1), 'little')
                self.reg[rt] = (self.reg[rt]&((1<<shift)-1)) | (value<<shift)
            elif op == 0x26:
                bits = (4-n)*8
                value = int.from_bytes(data(self, at, 4-n), 'little')
                self.reg[rt] = (self.reg[rt]&(~((1<<bits)-1)&0xffffffff)) | value
            elif op == 0x2a:
                self.write(aligned, self.reg[rt]>>((3-n)*8), n+1)
            else:
                self.write(at, self.reg[rt], 4-n)
            self.reg[0] = 0
        else:
            super().plain(word)


def call(vm, va, args, stack_args=(), limit=10000):
    saved={r:0x12340000+r for r in (*range(16,24),28,30)}
    for r,v in saved.items(): vm.reg[r]=v
    vm.reg[4:8] = list(args)+[0]*(4-len(args))
    vm.reg[29],vm.reg[31]=STACK,STOP
    for i,v in enumerate(stack_args): vm.write(STACK+0x10+4*i,v)
    vm.write(STACK-0x500,0xa55aa55a);vm.write(STACK+0x30,0xa55aa55a)
    vm.run(va,{STOP},limit=limit)
    assert vm.reg[29]==STACK and vm.reg[31]==STOP
    assert all(vm.reg[r]==v for r,v in saved.items()),'Callee-saved register changed'
    assert vm.read(STACK-0x500)==vm.read(STACK+0x30)==0xa55aa55a
    return vm.reg[2]


class Touch:
    def __init__(self, raw, repeat=True, event=0x3ea, enabled=True):
        self.vm=VM(parsed(raw),[(0x13e554,0x13e620),(0x13e620,0x13e6f8),
                                      (0x13e6f8,0x13e7ec),(0x13e17c,0x13e1d4),
                                      (0x13cf30,0x13d004),(0x134ed0,0x135370)])
        m=self.vm
        for p,n in ((BUTTON,0x600),(DIALOG,0x300),(VTABLE,0x80),(POINT,8)):put(m,p,bytes(n))
        m.write(BUTTON,0x17ce10);m.write(BUTTON+4,DIALOG+4)
        for off,val in ((8,361),(12,293),(16,139),(20,83),(0x2c,0x183 if enabled else 0x83),
                        (0x38,int(repeat)),(0x48,event)):
            m.write(BUTTON+off,val)
        m.write(DIALOG,VTABLE);m.write(DIALOG+0x20,DIALOG)
        m.write(DIALOG+0x50,0x5555);m.write(DIALOG+0x84,700);m.write(DIALOG+0x88,200)
        self.actions=[];self.events=[];self.timers=set();self.redraws=0
        for off,name in ((0x44,'action'),(0x48,'down'),(0x4c,'up'),(0x50,'cancel')):
            address=0xf0100000+off;m.write(VTABLE+off,address)
            m.hooks[address]=lambda m,name=name:self.callback(m,name)
        m.hooks.update({0x139020:self.redraw,0x13ff08:self.set_timer,0x13fef8:self.kill_timer,
                        0x140c54:lambda m:1,0x13ff78:lambda m:0})

    def callback(self,m,name):
        assert m.reg[4]==DIALOG
        self.events.append((name,m.reg[5],m.reg[6]))
        if name=='action':self.actions.append(m.reg[6])
        return 0

    def redraw(self,m):
        assert m.reg[4]==BUTTON
        self.redraws+=1;return 0

    def set_timer(self,m):
        assert m.reg[4]==0x5555 and m.reg[5] in (0x3f6,0x3f7)
        assert m.reg[6]==(700 if m.reg[5]==0x3f6 else 200) and m.reg[7]==0
        self.timers.add(m.reg[5]);return m.reg[5]

    def kill_timer(self,m):
        assert m.reg[4]==0x5555 and m.reg[5] in (0x3f6,0x3f7)
        self.timers.discard(m.reg[5]);return 1

    def pointer(self,kind,xy=(400,320),window=False):
        for i,v in enumerate(xy):self.vm.write(POINT+4*i,v&0xffffffff)
        if window:
            return call(self.vm,0x134ed0,[DIALOG,0x5555,0x202,0],[(xy[0]&65535)|((xy[1]&65535)<<16)])
        return call(self.vm,{'down':0x13e554,'up':0x13e620,'move':0x13e6f8}[kind],[BUTTON,POINT])

    def timer(self,n):return call(self.vm,0x134ed0,[DIALOG,0x5555,0x113,n],[0])

    def snapshot(self):
        return dict(actions=self.actions.copy(),selected=self.vm.read(DIALOG+0x24),
                    pressed=self.vm.read(BUTTON+0x30),repeat=self.vm.read(DIALOG+0x44),timers=sorted(self.timers))


def usb_screen_actions(raw,event,actions):
    m=VM(parsed(raw),[(0x4d00c,0x4d460)])
    system,errors=0x45000000,0x46000000
    put(m,DIALOG,bytes(0x3000));put(m,system,bytes(0x2500));put(m,errors,bytes(0x100))
    m.write(0x187b38,system);m.write(0x186ce8,errors);m.write(errors+4,0x5555)
    commands=[]
    def send(vm):
        assert vm.reg[4:6]==[21,5] and vm.reg[7]==0 and vm.read(vm.reg[29]+0x10)==0
        commands.append(vm.reg[6]);return 1
    m.write(0x1852c4,0xf0300000);m.hooks[0xf0300000]=send
    m.write(0x1852bc,0xf0300004);m.hooks[0xf0300004]=lambda vm:0
    m.hooks[0x13fef8]=lambda vm:1
    for action in actions:call(m,0x4d00c,[DIALOG,event,action])
    return commands


def verify_touch(old,new):
    traces=[]
    # Actual original timers demonstrate the defect; a Python Hold model is not used.
    a=Touch(old);a.pointer('down');a.pointer('up',(350,320));a.timer(0x3f6);a.timer(0x3f7)
    assert a.actions==[3,4] and a.vm.read(DIALOG+0x24)==BUTTON
    traces.append(dict(name='original outside release then queued timers',old=a.snapshot()))
    outside=[(360,320),(501,320),(400,292),(400,377),(0,0),(799,479),(-1,-1)]
    for event in (0x3ea,0x3ec):
        for repeat in (False,True):
            for held in (False,True):
                for xy in outside:
                    t=Touch(new,repeat,event);t.pointer('down')
                    expected=[]
                    if held and repeat:
                        t.timer(0x3f6);t.timer(0x3f7);expected=[3,4,5]
                    t.pointer('up',xy)
                    t.timer(0x3f6);t.timer(0x3f7)
                    assert t.actions==expected and t.snapshot()['selected']==0 and not t.timers
                    assert t.snapshot()['pressed']==t.snapshot()['repeat']==0
                    traces.append(dict(name='outside release',event=event,repeat=repeat,held=held,xy=xy,new=t.snapshot()))
    # Inclusive edges, ordinary taps/holds and move cancellation remain equivalent.
    inside=[(361,293),(500,376),(361,376),(500,293),(400,320)]
    for repeat in (False,True):
        for xy in inside:
            for events in (['up'],[0x3f6,'up',0x3f7],['move','up',0x3f6],
                           [0x3f6,0x3f7,'move','up',0x3f7],['up','up',0x3f6]):
                pair=[]
                for raw in (old,new):
                    t=Touch(raw,repeat);t.pointer('down',xy)
                    for e in events:
                        if isinstance(e,int):t.timer(e)
                        else:t.pointer(e,(350,320) if e=='move' else xy)
                    pair.append(t.snapshot())
                assert pair[0]==pair[1],(repeat,xy,events,pair)
                traces.append(dict(name='unchanged inside/move behavior',events=events,xy=xy,repeat=repeat,new=pair[1]))
    for repeat in (False,True):
        t=Touch(new,repeat,event=-1);t.pointer('down');t.pointer('up')
        assert not t.actions and not t.timers and t.snapshot()['selected']==0
        traces.append(dict(name='invalid-event release',repeat=repeat,new=t.snapshot()))
    for enabled in (False,True):
        t=Touch(new,enabled=enabled);t.pointer('up');t.timer(0x3f6);t.timer(0x3f7)
        assert not t.actions and not t.timers
        traces.append(dict(name='release without down',enabled=enabled,new=t.snapshot()))
    # Original WM_MOUSEUP -> virtual up slot -> repaired release -> original timers.
    for held in (False,True):
        for xy in ((350,320),(799,479)):
            t=Touch(new);t.pointer('down')
            if held:t.timer(0x3f6)
            t.pointer('up',xy,window=True);t.timer(0x3f6);t.timer(0x3f7)
            assert t.actions==([3,5] if held else []) and not t.timers
            traces.append(dict(name='window-up caller',held=held,xy=xy,new=t.snapshot()))
    for event,start,stop in ((0x3ea,0x68,0x69),(0x3ec,0x66,0x67)):
        t=Touch(new,event=event);t.pointer('down');t.timer(0x3f6);t.timer(0x3f7)
        t.pointer('up',(350,320));t.timer(0x3f7)
        commands=usb_screen_actions(new,event,t.actions)
        assert commands==[start,stop]
        traces.append(dict(name='actual USB screen seek-start and seek-stop IPC',event=event,commands=commands,new=t.snapshot()))
    return dict(cases=len(traces),traces=traces,native_touch_event_order_observed=False)


class Resume:
    def __init__(self,raw,free=2**32+123,total=2**33,serial=0x12345678,size=123456,
                 saved_free=2**32+123,saved_total=2**33,saved_serial=0x12345678,saved_size=123456,
                 disk_ok=True,file_ok=True,info_ok=True,graph_ok=True,path='\\MD\\Music\\Track.mp3',position=42):
        self.vm=VM(parsed(raw),[(0x1ba3c,0x1be50),(0x1a69c,0x1a7d0)])
        m=self.vm;self.events=[];self.handles=set();self.seeks=[]
        self.free,self.total,self.serial,self.size=free,total,serial,size
        self.disk_ok,self.file_ok,self.info_ok,self.graph_ok=disk_ok,file_ok,info_ok,graph_ok
        put(m,BUTTON,bytes(0x3000));put(m,DIALOG,bytes(0x100))
        put(m,BUTTON+0x1088,(path+'\0').encode('utf-16le'))
        m.write(BUTTON+0xe78,1);m.write(BUTTON+0xe7c,position)
        put(m,BUTTON+0x1ab8,struct.pack('<QQII',saved_free,saved_total,saved_size,saved_serial))
        m.write(DIALOG+0x3c,0x5555);m.write(DIALOG+0x4c,BUTTON-8);m.write(DIALOG+0x74,0xffffffff)
        m.write(0x2f960,COOKIE)
        m.hooks.update({0x253bc:lambda m:len(m.text(m.reg[4])),0x231a4:lambda m:DIALOG,
            0x2517c:lambda m:1,0x25668:self.copy,0x253dc:self.zero,0x253cc:self.format,
            0x251fc:self.compare,0x251dc:self.disk,0x2511c:lambda m:0,0x23aac:lambda m:0,
            0x25510:self.cookie,0x19254:self.metadata,0x1a318:lambda m:0,
            0x1144c:lambda m:POINT,0x12264:self.graph,0x1137c:lambda m:300,
            0x197e4:lambda m:0,0x1111c:self.seek,0x19864:lambda m:0,
            0x1ae54:lambda m:0,0x1dc00:lambda m:0,0x1a9e4:lambda m:0,
            0x1b670:lambda m:0})
        for i,(iat,hook) in enumerate(((0x2f034,self.open),(0x2f084,self.info),
                                      (0x2f038,self.close),(0x2f020,lambda m:2))):
            at=0xf0200000+4*i;m.write(iat,at);m.hooks[at]=hook

    def copy(self,m):put(m,m.reg[4],data(m,m.reg[5],m.reg[6]));return m.reg[4]
    def zero(self,m):put(m,m.reg[4],bytes([m.reg[5]&255])*m.reg[6]);return m.reg[4]
    def format(self,m):
        assert m.text(m.reg[5])=='\\%s'
        put(m,m.reg[4],('\\'+m.text(m.reg[6])+'\0').encode('utf-16le'));return 0
    def cookie(self,m):assert m.reg[4]==COOKIE;return 0
    def compare(self,m):return int(data(m,m.reg[4],8)!=data(m,m.reg[5],8))
    def disk(self,m):
        assert m.text(m.reg[4])=='MD'
        self.events.append('disk')
        if self.disk_ok:
            for ptr,v in zip(m.reg[5:8],(self.free,self.total,self.free)):put(m,ptr,struct.pack('<Q',v))
        return int(self.disk_ok)
    def open(self,m):
        self.events.append(('open',m.text(m.reg[4])))
        assert m.reg[5:8]==[0x80000000,1,0] and m.read(m.reg[29]+0x10)==3
        if not self.file_ok:return 0xffffffff
        self.handles.add(0x6666);return 0x6666
    def info(self,m):
        assert m.reg[4] in self.handles
        self.events.append('file-info')
        if self.info_ok:
            put(m,m.reg[5],bytes(52));m.write(m.reg[5]+0x1c,self.serial);m.write(m.reg[5]+0x24,self.size)
        return int(self.info_ok)
    def close(self,m):assert m.reg[4] in self.handles;self.handles.remove(m.reg[4]);return 1
    def metadata(self,m):
        self.events.append(('metadata',m.text(m.reg[5]),m.reg[6]));return 0
    def graph(self,m):
        self.events.append(('graph',m.text(m.reg[5]),m.reg[6]));return int(self.graph_ok)
    def seek(self,m):self.seeks.append(m.reg[5]);return 0
    def run(self):
        result=call(self.vm,0x1ba3c,[BUTTON]);assert not self.handles
        return dict(result=result,seeks=self.seeks,events=self.events)


def rematch(raw,tracks,filename='Track.mp3',folder='MD\\Music'):
    m=VM(parsed(raw),[(0x1e8cc,0x1e9fc)])
    put(m,DIALOG,bytes(0x100));m.write(DIALOG+0x48,BUTTON)
    m.write(0x2f960,COOKIE)
    put(m,POINT,(filename+'\0').encode('utf-16le'));put(m,POINT+0x208,(folder+'\0').encode('utf-16le'))
    for i,(name,parent) in enumerate(tracks):put(m,VTABLE+i*0x208,(name+'\0').encode('utf-16le'))
    def name(vm):
        assert vm.reg[4]==BUTTON and 0<=vm.reg[5]<len(tracks)
        return VTABLE+vm.reg[5]*0x208
    def folder_path(vm):
        assert vm.reg[4]==BUTTON and 0<=vm.reg[5]<len(tracks)
        put(vm,vm.reg[6],(tracks[vm.reg[5]][1]+'\0').encode('utf-16le'));return 1
    def zero(vm):put(vm,vm.reg[4],bytes(vm.reg[6]));return vm.reg[4]
    def cookie(vm):assert vm.reg[4]==COOKIE;return 0
    m.hooks={0x231a4:lambda vm:DIALOG,0x12ebc:lambda vm:len(tracks),0x13318:name,
             0x25658:lambda vm:int(vm.text(vm.reg[4])!=vm.text(vm.reg[5])),
             0x253dc:zero,0x132fc:lambda vm:vm.reg[5],0x13f10:folder_path,0x25510:cookie}
    return call(m,0x1e8cc,[BUTTON,POINT,POINT+0x208])


def verify_usb(old,new):
    scenarios=[('unchanged',{},1,1),('added small file',{'free':2**32+100},0,1),
               ('removed file',{'free':2**32+500},0,1),('changed free high DWORD',{'free':2**31},0,1),
               ('USB nearly full',{'free':0},0,1),('other volume',{'serial':99},0,0),
               ('same capacity other volume',{'serial':99,'free':2**32+100},0,0),
               ('track changed size',{'size':123457},0,0),('track removed',{'file_ok':False},0,0),
               ('file-info failure',{'info_ok':False},0,0),('disk API failure',{'disk_ok':False},0,0),
               ('changed capacity low',{'total':2**33+1},0,0),
               ('changed capacity high',{'total':2**34},0,0),('graph rejects track',{'graph_ok':False},0,0),
               ('changed free and graph rejects',{'free':0,'graph_ok':False},0,0),
               ('empty path',{'path':''},0,0),('relative path',{'path':'MD\\Music\\Track.mp3','free':0},0,1)]
    traces=[]
    for name,kwargs,expected_old,expected_new in scenarios:
        a,b=Resume(old,**kwargs).run(),Resume(new,**kwargs).run()
        assert a['result']==expected_old and b['result']==expected_new,(name,a,b)
        assert b['seeks']==([42] if expected_new else [])
        # With changed free space the new path can reach a rejecting graph;
        # the original stopped at the free-space gate. Both must still fail.
        if expected_old==expected_new and not ('free' in kwargs and not kwargs.get('graph_ok',True)):
            assert a==b,(name,a,b)
        traces.append(dict(name=name,old=a,new=b))
    for position in (0,1,299):
        b=Resume(new,free=0,position=position).run();assert b['seeks']==[position]
        traces.append(dict(name='preserved position',position=position,new=b))
    target=('Track.mp3','MD\\Music')
    libraries=[([target],0),([('Added.mp3','MD\\Music'),target],1),
               ([('Track.mp3','MD\\Other'),('Other.mp3','MD\\Music'),target],2),
               ([('Track.mp3','MD\\Other')],0xffffffff),([],0xffffffff)]
    for tracks,index in libraries:
        a,b=rematch(old,tracks),rematch(new,tracks)
        assert a==b==index
        traces.append(dict(name='original post-scan filename and folder rematch',tracks=tracks,index=index))
    # Unaligned merge sanity independent from resume flow.
    m=VM(pefile.PE(data=new),[])
    for offset in range(4):
        put(m,POINT,b'abcdefgh');m.reg[4]=POINT+offset;m.reg[8]=0x12345678
        m.plain((0x22<<26)|(4<<21)|(8<<16)|3);m.plain((0x26<<26)|(4<<21)|(8<<16))
        assert m.reg[8]==int.from_bytes(b'abcdefgh'[offset:offset+4],'little')
        m.reg[8]=0x12345678
        m.plain((0x2a<<26)|(4<<21)|(8<<16)|3);m.plain((0x2e<<26)|(4<<21)|(8<<16))
        expected=bytearray(b'abcdefgh');expected[offset:offset+4]=bytes.fromhex('78563412')
        assert data(m,POINT,8)==bytes(expected)
    return dict(cases=len(traces),traces=traces,unaligned_merge_cases=4,
                scan_order='Resume loads the saved path before library scanning; the existing search then rematches the live track index',
                identity_limit='Existing size/serial/capacity checks are retained; equal-size content changes and cloned volume serials are not newly detected')


class HebrewVM(VM):
    def __init__(self,raw):
        super().__init__(parsed(raw),[(0x1397c8,0x1398a0)])
        self.words={va:int.from_bytes(self.pe.get_data(va-self.base,4),'little') for va in range(0x1397c8,0x1398a0,4)}
    def word(self,pc):return self.words[pc]
    def read(self,at,size=4):
        if POINT<=at<POINT+0x10000:
            assert size==2 and at<=self.end,'Read beyond first NUL'
            self.reads+=1
        return super().read(at,size)


def hebrew(m,units):
    m.mem.clear();m.reg[:]=[0]*32;m.reads=0;m.steps=0;m.end=POINT+2*units.index(0)
    put(m,POINT,struct.pack('<'+'H'*len(units),*units));m.write(0x1853f4,COOKIE)
    copies=[]
    def zero(vm):
        assert vm.reg[4:7]==[STACK-0x230+0x12,0,0x206]
        put(vm,vm.reg[4],bytes(vm.reg[6]));copies.append('memset');return vm.reg[4]
    def fmt(vm):
        assert vm.reg[4:8]==[STACK-0x230+0x10,0x103,0x14f640,POINT]
        # Explicit CRT fixture; its internal cost is excluded from read/instruction counts.
        prefix=units[:units.index(0)][:0x103]
        put(vm,vm.reg[4],struct.pack('<'+'H'*(len(prefix)+1),*prefix,0));copies.append('_snwprintf');return len(prefix)
    def cookie(vm):assert vm.reg[4]==COOKIE;return 0
    m.hooks={0x140de4:zero,0x140320:fmt,0x140298:cookie}
    result=call(m,0x1397c8,[POINT])
    assert all(STACK-0x230<=at<STACK or POINT<=at<POINT+2*len(units) or
               0x1853f4<=at<0x1853f8 or at in range(STACK-0x500,STACK-0x4fc) or
               at in range(STACK+0x30,STACK+0x34) for at in m.mem),'Out-of-frame write'
    return dict(result=result,text_reads=m.reads,instructions=m.steps,unused_crt_calls=copies)


def verify_performance(old,new,exhaustive=True):
    a,b=HebrewVM(old),HebrewVM(new)
    n=65536 if exhaustive else 0
    for unit in range(n):
        x,y=hebrew(a,[unit,0]),hebrew(b,[unit,0])
        assert x['result']==y['result']==int(0x590<=unit<0x600)
        if unit and unit%16384==0:print(f'Hebrew differential checks: {unit}/65536',flush=True)
    cases=[[0],[65,0,0x590,0],[0xd800,0xdc00,0],[0x58f,0x600,0]]
    for length in (1,8,32,128,270,400):
        for u in (0x590,0x5ff,0x58f,0x600):
            for p in (0,length//2,length-1):
                s=[65]*length+[0];s[p]=u;cases.append(s)
    rng=random.Random(70603)
    cases += [[rng.randrange(1,65536) for _ in range(rng.randrange(1,100))]+[0] for _ in range(64)]
    for units in cases:
        x,y=hebrew(a,units),hebrew(b,units)
        assert x['result']==y['result']==int(any(0x590<=u<0x600 for u in units[:units.index(0)]))
        assert y['unused_crt_calls']==[]
    benchmarks=[dict(length=n,old=hebrew(a,[65]*n+[0]),new=hebrew(b,[65]*n+[0])) for n in (0,8,32,128,270)]
    assert all(r['new']['text_reads']==r['length']+1 for r in benchmarks)
    assert all(r['new']['instructions']<r['old']['instructions'] for r in benchmarks)
    # Both original/added detection helpers retain their real caller sites.
    sites=(0x139ec8,0x13a7ec,0x13b7c0,0x13bac0,0x13bf74,0x13c600,0x13c70c,0x13cd58)
    pe=pefile.PE(data=new)
    for site in sites:
        word=int.from_bytes(pe.get_data(site-pe.OPTIONAL_HEADER.ImageBase,4),'little')
        assert word==((3<<26)|(0x1397c8>>2))
    return dict(exhaustive_utf16_cases=n,mixed_cases=len(cases),benchmarks=benchmarks,
                unchanged_draw_call_sites=[hex(s) for s in sites],
                measurement='Interpreted instruction/read counts only; CRT internals and native elapsed time excluded',
                startup_wait_changed=False,audio_switch_waits_changed=False)


def verify(old_app,new_app,old_usb,new_usb,exhaustive=True):
    assert hashlib.sha256(old_app).hexdigest()==APP_SHA
    assert hashlib.sha256(old_usb).hexdigest()==USB_SHA
    return dict(touch=verify_touch(old_app,new_app),usb_resume=verify_usb(old_usb,new_usb),
                performance=verify_performance(old_app,new_app,exhaustive),
                native_execution=False,hardware_tested=False)


def main():
    app=(SYSTEM/'AppMain.exe').read_bytes();usb=(SYSTEM/'MgrUSB.exe').read_bytes()
    a,ar=patch_app(app);u,ur=patch_usb(usb)
    result=verify(app,a,usb,u)
    out=ROOT/'analysis/firmware/media-responsiveness-development.json'
    out.write_text(json.dumps(dict(app_recipe=ar,usb_recipe=ur,checks=result),indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(touch_cases=result['touch']['cases'],usb_cases=result['usb_resume']['cases'],
                          performance=result['performance']),indent=2))


if __name__=='__main__':main()
