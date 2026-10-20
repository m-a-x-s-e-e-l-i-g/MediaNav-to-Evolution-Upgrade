"""Execute written MAX19 MIPS bytes with explicit CE/filesystem/GDI fixtures."""
import argparse,json,re,struct
from pathlib import Path
import pefile
from verify_ui_english import UiVM
from inspect_wave_queue import STOP
from debug_runtime import MAGIC,MAP_BYTES,RECORD,CAPACITY,ORDINALS
from debug_image import sha
from package_max16 import write

STACK=0x68000000;SHARED=0x61000000;INPUT=0x62000000


class VM(UiVM):
    def __init__(self,raw):
        p=pefile.PE(data=raw)
        super().__init__(p,[(p.OPTIONAL_HEADER.ImageBase+s.VirtualAddress,p.OPTIONAL_HEADER.ImageBase+s.VirtualAddress+s.Misc_VirtualSize) for s in p.sections if s.Characteristics&0x20000000])
    def internal_call(self,at): return any(a<=at<b for a,b in self.ranges)
    def word(self,at):
        if at in self.hooks and at>=0xf1000000:
            self.reg[2]=self.hooks[at](self)&0xffffffff
            return 0x03e00008 # Reviewed tail call into an explicit API fixture.
        if at-4 in self.hooks and at>=0xf1000000:return 0
        return super().word(at)
    def plain(self,w):
        if w==15: return # Memory barrier; no native cache/scheduler simulation.
        if w>>26==14:
            self.reg[(w>>16)&31]=self.reg[(w>>21)&31]^(w&65535);self.reg[0]=0;return
        super().plain(w)


class Yield(Exception): pass


class Fixture:
    def __init__(self,root):
        self.root=root; self.raw=(root/'CmnDll.dll').read_bytes();self.vm=VM(self.raw)
        self.recipe=json.loads((root/'CmnDll.dll.json').read_bytes());self.runtime=json.loads((root/'runtime.json').read_bytes())
        self.A=self.runtime['addresses']; self.D=self.recipe['state_va']; self.calls=[]
        self.vm.write(self.D+0x38,1) # Explicit fixture: successful library initialization already returned.
        self.last=77;self.tick=5000;self.wait_result=0;self.fail=None;self.enabled=0
        self.usb=False;self.space=100*1024*1024;self.files={};self.handles={};self.handle=100
        self.write_fail=False;self.short_write=False;self.flush_fail=False;self.reg_fail=False
        self.output=[];self.sleeps=0;self.stop_after=4;self.reg_type=4;self.reg_size=4
        self.map_initialized=False;self.initial_magic=0;self.thread_priority=1;self.resume_result=1;self.queue_held=False
        self.on_sleep=None
        for d in self.vm.pe.DIRECTORY_ENTRY_IMPORT:
            for s in d.imports:
                assert d.dll.lower()==b'coredll.dll' and s.ordinal is not None
                target=0xf1000000+s.ordinal*16
                self.vm.write(s.address,target)
                self.vm.hooks[target]=lambda m,ordinal=s.ordinal:self.api(ordinal,m)
    def text(self,at):return self.vm.text(at)
    def put(self,at,text):
        for j,b in enumerate((text+'\0').encode('utf-16-le')):self.vm.write(at+j,b,1)
    def api(self,o,m):
        args=m.reg[4:8];self.calls.append((o,list(args)))
        if o==516:return self.last
        if o==517:self.last=args[0];return 0
        self.last=1000+o
        if self.fail==o:return 0 if o not in [168,166] else 0xffffffff
        if o==535:return self.tick
        if o==555:return 2 if 'Queue' in self.text(args[2]) else 3
        if o==497:
            if args[0]==2 and self.wait_result in [0,128]:self.queue_held=True
            return self.wait_result
        if o==556:
            if args[0]==2:assert self.queue_held;self.queue_held=False
            return 1
        if o in [553,550,160,250]:return 1
        if o==548:return 4
        if o==549:
            if not self.map_initialized:
                for j in range(MAP_BYTES):m.write(SHARED+j,0,1)
                m.write(SHARED,self.initial_magic);self.map_initialized=True
            return SHARED
        if o==10:
            v=(m.read(args[0])+1)&0xffffffff;m.write(args[0],v);return v
        if o==541:self.output.append(self.text(args[0]));return 0
        if o==545:
            # The adapter must restore the caller's original varargs and stack.
            self.output.append(('nk',self.text(args[0]),args[1:],m.read(m.reg[29]+16)));return 0
        if o==2666:
            assert args[1]==256
            fmt=self.text(args[2]);values=[m.read(args[3]+4*j) for j in range(len(re.findall(r'%0?\d*[us]',fmt)))]
            self.put(args[0],self.format(fmt,values)[:255]);return len(self.text(args[0]))
        if o==56:
            fmt=self.text(args[1]);n=len(re.findall(r'%0?\d*[us]',fmt))
            values=args[2:]+[m.read(m.reg[29]+16+4*j) for j in range(max(0,n-2))]
            text=self.format(fmt,values);self.put(args[0],text);return len(text)
        if o==461:m.write(m.read(m.reg[29]+16),5);return 2 if self.reg_fail else 0
        if o==456:m.write(m.read(m.reg[29]+28),5);return 5 if self.reg_fail else 0
        if o==463:
            m.write(args[3],self.reg_type);m.write(m.read(m.reg[29]+16),self.enabled)
            m.write(m.read(m.reg[29]+20),self.reg_size);return 0
        if o==464:
            if self.reg_fail:return 5
            assert args[3]==4 and m.read(m.reg[29]+20)==4
            self.enabled=m.read(m.read(m.reg[29]+16));return 0
        if o in [455,1152]:return 5 if self.reg_fail else 0
        if o==492:
            assert m.read(m.reg[29]+16)==4 and args[2]==self.A['worker'];return 6
        if o==514:assert args==[6,4, args[2],args[3]];return self.thread_priority
        if o==500:return self.resume_result
        if o==166:return 16 if self.usb else 0xffffffff
        if o==184:
            m.write(args[1],self.space&0xffffffff);m.write(args[1]+4,self.space>>32);return 1
        if o==168:
            assert self.text(args[0]).startswith('\\MD\\MAXmade\\logs\\debug-')
            assert args[1]==0x40000000 and m.read(m.reg[29]+16)==2
            self.handle+=1;path=self.text(args[0]);self.handles[self.handle]=path;self.files[path]=bytearray();return self.handle
        if o==171:
            assert not self.queue_held,'USB write while holding producer mutex'
            assert args[0] in self.handles
            raw=bytes(m.read(args[1]+j,1) for j in range(args[2]))
            size=len(raw)-(2 if self.short_write else 0)
            m.write(args[3],size);self.files[self.handles[args[0]]]+=raw[:size]
            return 0 if self.write_fail else 1
        if o==175:return 0 if self.flush_fail else 1
        if o==88:
            assert m.read(args[0])==32;m.write(args[0]+4,32);m.write(args[0]+12,12345678);return 0
        if o==23:
            for j,v in enumerate([2026,10,2,13,12,30,45,123]):m.write(args[0]+2*j,v,2)
            return 0
        if o==496:
            assert args[0]==500;self.tick+=500;self.sleeps+=1
            if self.on_sleep:self.on_sleep(self)
            if self.sleeps>=self.stop_after:raise Yield()
            return 0
        if o in [167,180]:raise AssertionError('Unexpected directory enumeration')
        raise AssertionError(('API',o))
    def format(self,fmt,values):
        values=iter(values)
        def sub(m):
            n=next(values);v=self.text(n) if m.group(2)=='s' else str(n)
            return v.zfill(int(m.group(1) or 0))
        return re.sub(r'%0?(\d*)([us])',sub,fmt)
    def call(self,at,args,extra=(),limit=100000):
        m=self.vm;m.reg[4:8]=list(args)+[0]*(4-len(args));m.reg[29]=STACK;m.reg[31]=STOP
        for j,v in enumerate(extra):m.write(STACK+16+j*4,v)
        saved={r:0x12340000+r for r in range(16,24)}
        for r,v in saved.items():m.reg[r]=v
        m.run(at,{STOP},limit)
        assert m.reg[29]==STACK and m.reg[31]==STOP
        assert all(m.reg[r]==v for r,v in saved.items()),('ABI',hex(at))
        return m.reg[2]
    def command(self,op,a1=0,a2=0,a3=0,result=0):return self.call(self.A['control'],[MAGIC+op,a1,a2,a3],[result])
    def init(self,on=1):
        self.call(self.A['ensure'],[]);self.vm.write(SHARED+0x10,on)
    def event(self,text='test',event=200):
        self.put(INPUT,text);return self.call(self.A['enqueue'],[2,event,15,7],[INPUT,3])
    def worker(self,n=4):
        self.stop_after=n
        try:self.vm.reg[29]=STACK;self.vm.reg[31]=STOP;self.vm.run(self.A['worker'],{STOP},1000000)
        except Yield:pass


def core_cases(root):
    cases=[]
    for status in [0,128,258,0xffffffff]:
        f=Fixture(root);f.wait_result=status;r=f.call(f.A['ensure'],[])
        assert bool(r)==(status in [0,128]);cases.append('mapping wait '+str(status))
    for ordinal in [555,548,549]:
        f=Fixture(root);f.fail=ordinal;assert f.call(f.A['ensure'],[])==0;cases.append('mapping failure '+str(ordinal))
    f=Fixture(root);f.initial_magic=123;assert f.call(f.A['ensure'],[])==0
    assert any(c[0]==550 for c in f.calls);cases.append('incompatible mapping releases view')
    f=Fixture(root);f.vm.write(f.D+0x38,0);f.put(INPUT,'DLL initialization')
    f.call(f.A['raw'],[INPUT]);assert f.output==['DLL initialization']
    assert not any(c[0] in [555,548,549] for c in f.calls);cases.append('DLL initialization bypasses shared queue')
    for enabled in [0,1]:
        f=Fixture(root);f.enabled=enabled;f.last=0xabc
        r=f.command(1);assert r&1==enabled and f.last==0xabc
        assert any(c[0]==492 for c in f.calls);cases.append('startup setting '+str(enabled))
    for failure in ['create','priority','resume']:
        f=Fixture(root);f.enabled=1
        if failure=='create':f.fail=492
        if failure=='priority':f.thread_priority=0
        if failure=='resume':f.resume_result=0xffffffff
        f.command(1);assert f.vm.read(SHARED+0x1c)==5
        if failure=='priority':f.worker();assert not f.files
        if failure=='resume':assert f.vm.read(f.D+12)==6 and f.vm.read(f.D+0x28)==1
        cases.append('thread failure '+failure)
    for typ,size,val in [(4,4,1),(4,4,0),(1,4,1),(4,3,1),(4,4,2),(4,4,0xffffffff)]:
        f=Fixture(root);f.enabled=val;f.reg_type=typ;f.reg_size=size
        assert f.call(f.A['readconfig'],[])==int((typ,size,val)==(4,4,1));cases.append('config validation')
    for wanted in [0,1]:
        f=Fixture(root);f.init();f.last=88;assert f.command(2,wanted)==1
        assert f.vm.read(SHARED+16)==wanted and f.last==88
        assert not any(c[0] in [168,171,464] for c in f.calls);cases.append('nonblocking toggle')
    for on in [0,1]:
        f=Fixture(root);f.init(on);f.event('hello\tthere\r\nend')
        assert f.vm.read(SHARED+12)==on
        if on:
            assert f.call(f.A['drain'],[])==1
            assert f.text(f.D+0x420)=='hello there  end'
        cases.append('capture on/off')
    f=Fixture(root);f.init();f.event('x'*500);f.call(f.A['drain'],[])
    assert len(f.text(f.D+0x420))==255;cases.append('bounded text')
    f=Fixture(root);f.init();f.wait_result=258;f.event();assert f.vm.read(SHARED+0x24)==1;cases.append('contended producer')
    for head,tail,count in [(300,1,1),(1,2,500),(2,4,1)]:
        f=Fixture(root);f.init();f.vm.write(SHARED+4,head);f.vm.write(SHARED+8,tail);f.vm.write(SHARED+12,count)
        f.event('repaired');assert f.vm.read(SHARED+12)==1 and f.vm.read(SHARED+4)==0 and f.vm.read(SHARED+0x20)>0
        cases.append('abandoned/inconsistent queue recovery')
    f=Fixture(root);f.init()
    for n in range(130):f.event(str(n))
    assert f.vm.read(SHARED+12)==128 and f.vm.read(SHARED+0x20)==2;cases.append('rate limit')
    f.tick+=1000
    for n in range(128):f.event(str(n+128))
    f.tick+=1000;f.event('full')
    assert f.vm.read(SHARED+12)==256 and f.vm.read(SHARED+0x20)==3
    for n in range(256):assert f.call(f.A['drain'],[])==1
    assert f.call(f.A['drain'],[])==0 and f.vm.read(SHARED+4)==0;cases.append('full queue wrap')
    for on in [0,1]:
        f=Fixture(root);f.init(on);f.put(INPUT,'native error');f.last=91
        f.call(f.A['raw'],[INPUT]);assert f.output==['native error']
        assert f.vm.read(SHARED+12)==on;cases.append('native output forwarding')
        f=Fixture(root);f.init(on);f.put(INPUT,'error %u');f.vm.write(STACK+16,456)
        f.call(f.A['nk'],[INPUT,123,234,345],[456])
        assert f.output[-1]==('nk','error %u',[123,234,345],456)
        assert f.vm.read(SHARED+12)==on;cases.append('native printf varargs')
    for usb,space,expected in [(False,100000000,1),(True,100000000,2),(True,100,4)]:
        f=Fixture(root);f.init();f.usb=usb;f.space=space
        assert f.call(f.A['openfile'],[])==expected;cases.append('USB destination state')
    for kind in ['boolean','short','flush','registry']:
        f=Fixture(root);f.init();f.usb=True;f.event('error test')
        if kind=='boolean':f.write_fail=True
        if kind=='short':f.short_write=True
        if kind=='flush':f.flush_fail=True
        if kind=='registry':f.reg_fail=True;f.vm.write(SHARED+0x14,1)
        f.worker(6)
        if kind=='registry':assert f.vm.read(SHARED+0x40)!=0
        else:assert f.vm.read(SHARED+0x1c) in [3,4]
        cases.append('writer failure '+kind)
    f=Fixture(root);f.init(0);f.worker(4);assert not f.files
    assert not any(c[0] in [166,168,171,88] for c in f.calls);cases.append('off has no USB I/O or sampling')
    f=Fixture(root);f.init();f.usb=True;f.event('record');f.worker(4)
    text=next(iter(f.files.values())).decode('utf-16-le');assert 'record' in text and '200' in text;cases.append('worker writes queued record')
    f=Fixture(root);f.init();f.usb=True;assert f.call(f.A['openfile'],[])==2
    for j,v in enumerate([2026,10,2,13,12,30,45,123]):f.vm.write(f.D+0x1520+j*2,v,2)
    f.vm.write(f.D+0x2c,1234)
    f.vm.write(f.D+0x18,4*1024*1024-4);f.event('rotation');f.call(f.A['drain'],[])
    assert f.call(f.A['record'],[])==1 and len(f.files)==2;cases.append('rotation before size cap')
    f=Fixture(root);f.init();f.event('late USB');f.on_sleep=lambda w:setattr(w,'usb',w.sleeps>=2);f.worker(7)
    assert f.vm.read(SHARED+0x1c)==2 and 'late USB' in next(iter(f.files.values())).decode('utf-16-le')
    cases.append('late USB insertion starts automatically')
    f=Fixture(root);f.init();f.usb=True;f.event('remove');f.on_sleep=lambda w:setattr(w,'usb',w.sleeps<3);f.worker(7)
    assert f.vm.read(SHARED+0x1c)==1 and f.vm.read(f.D+0x14)==0xffffffff;cases.append('USB removal closes writer')
    f=Fixture(root);f.init();f.usb=True;f.event('sample');f.worker(25)
    folder=root/'fixture-logs';folder.mkdir(exist_ok=True)
    for path,data in f.files.items():(folder/Path(path.replace('\\','/')).name).write_bytes(data)
    from analyze_debug_logs import analyze
    summary=analyze(sorted(folder.glob('*.log')))
    assert summary['sessions'] and summary['sessions'][0]['memory_samples']
    assert summary['sessions'][0]['dropped_records_latest'] is not None
    write(root/'fixture-log-analysis.json',summary);cases.append('actual writer output parsed with RAM/drop samples')
    return cases


def image_checks(root):
    from patch_shared_mapping_checks import reloc_records
    cases=[]
    for path in root.glob('*.exe'):
        p=pefile.PE(str(path));assert p.FILE_HEADER.Machine==0x166 and p.verify_checksum()
        recipe=json.loads((root/(path.name+'.json')).read_bytes());assert sha(path.read_bytes())==recipe['output_sha256']
        original=(Path(__file__).resolve().parents[1]/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System'/path.name).read_bytes()
        allowed=set()
        for edit in recipe['edits']:allowed.update(range(edit['offset'],edit['offset']+len(bytes.fromhex(edit['after_hex']))))
        cs=p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum');allowed.update(range(cs,cs+4))
        assert all(a==b or j in allowed for j,(a,b) in enumerate(zip(original,path.read_bytes())))
        assert not any(s.Characteristics&0x20000000 and s.Characteristics&0x80000000 for s in p.sections)
        for d in p.DIRECTORY_ENTRY_IMPORT:
            for s in d.imports:
                if d.dll.lower()==b'cmndll.dll' and s.name in [b'MxNKDbgPrintfW',b'MxOutputDebugStringW',b'DbgDebugPrint']:
                    assert s.address # Original IAT address retained or explicit new IAT.
        for at,kind,comp in reloc_records(p):
            if kind==5:assert int.from_bytes(p.get_data(at,4),'little')>>26 in [2,3]
        cases.append('PE, imports, checksum and jump relocations '+path.name)
    core=pefile.PE(str(root/'CmnDll.dll'));assert core.verify_checksum()
    exports={x.name for x in core.DIRECTORY_ENTRY_EXPORT.symbols if x.name}
    assert {b'MxOutputDebugStringW',b'MxNKDbgPrintfW',b'DbgDebugPrint'}<=exports
    cases.append('core exports and checksum')
    return cases


def client_cases(root):
    cases=[]
    for path in root.glob('*.exe'):
        recipe=json.loads((root/(path.name+'.json')).read_bytes())
        for event in recipe['events']:
            for on in [0,1]:
                m=VM(path.read_bytes());last=[77];tick=[1000];commands=[];expected=[11,22,33,44]
                for d in m.pe.DIRECTORY_ENTRY_IMPORT:
                    for s in d.imports:
                        target=0xf2000000+len(m.hooks)*16;m.write(s.address,target)
                        if s.ordinal==516:m.hooks[target]=lambda v:last[0]
                        elif s.ordinal==517:m.hooks[target]=lambda v:last.__setitem__(0,v.reg[4]) or 0
                        elif s.ordinal==535:
                            def clock(v):tick[0]+=25;last[0]=99;return tick[0]
                            m.hooks[target]=clock
                        elif s.name==b'DbgDebugPrint':
                            def dbg(v):
                                assert v.reg[4]&0xffffff00==MAGIC
                                commands.append(tuple(v.reg[4:8]));return on if v.reg[4]==MAGIC+3 else 1
                            m.hooks[target]=dbg
                def original(v):
                    assert v.reg[4:8]==expected
                    assert [v.read(v.reg[29]+16+j*4) for j in range(9)]==list(range(100,109))
                    assert last[0]==77
                    last[0]=1234;v.reg[3]=0x5678
                    for r in [4,5,6,7,8,9,10,11,12,13,14,15,24,25]:v.reg[r]=0xeeee
                    return 0x1234
                m.hooks[event['clone']]=original
                # Before-hook starts the logger for WinMain; no actual worker in this wrapper fixture.
                m.reg[4:8]=expected;m.reg[29]=STACK;m.reg[31]=STOP
                for j in range(9):m.write(STACK+16+j*4,100+j)
                saved={r:0xaaaa0000+r for r in range(16,24)}
                for r,v in saved.items():m.reg[r]=v
                m.run(event['wrapper'],{STOP},100000)
                assert m.reg[29]==STACK and m.reg[31]==STOP and m.reg[2:4]==[0x1234,0x5678]
                assert last[0]==1234 and all(m.reg[r]==v for r,v in saved.items())
                if on:assert len([c for c in commands if c[0]==MAGIC+4])==(2 if event.get('begin_logged',True) else 1)
                else:assert not any(c[0]==MAGIC+4 for c in commands)
                cases.append(path.name+' '+event['label']+' on='+str(on)+' arguments/results/error/ABI')
    return cases


def inherited_cases(root):
    from verify_nav_caution import construct,launch
    from verify_usb_input_safety import relocated
    raw=(root/'AppMain.exe').read_bytes();cases=[]
    for delta in [0,0x10000,0x123000]:
        moved=relocated(raw,delta) if delta else raw
        construct(moved,delta);construct(moved,delta,existing=True);construct(moved,delta,fail=True)
        for map_button in [False,True]:launch(moved,delta,1,map_button)
        cases.append('MAX18 Nav constructors and direct launch rebase '+hex(delta))
    return cases


def switch_table_cases(root):
    raw=(root/'AppMain.exe').read_bytes();recipe=json.loads((root/'AppMain.exe.json').read_bytes())
    event=next(e for e in recipe['events'] if e['entry']==0xd9f04);shift=event['clone']-event['entry']
    table=0xda058;original=pefile.PE(str(Path(__file__).resolve().parents[1]/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System/AppMain.exe'))
    cases=[]
    for ident in range(5,52):
        m=VM(raw);m.reg[8]=0x65000000;m.write(0x650002c0,ident)
        byte=original.get_data(table-original.OPTIONAL_HEADER.ImageBase+ident-5,1)[0]
        offset=byte if byte<128 else byte-256
        target=table+offset+shift
        m.run(0xda028+shift,{target},1000)
        assert m.pc==target
        cases.append('source switch inline table '+str(ident))
    return cases


def settings_cases(root):
    raw=(root/'AppMain.exe').read_bytes();ui=json.loads((root/'AppMain.exe.json').read_bytes())['settings']
    cases=[];OBJ=0x65000000;RES=0x65010000;VT=0x65020000;SYS=0x65030000
    for profile in [0,1,3]:
        for page in [0,1]:
            for status in [0,1,2,3,4,5,0x80]:
                m=VM(raw);labels={};visibility={};flags=[1];display=[status];draw=[]
                m.write(0x186538,RES);m.write(RES+0x20,0x7777);m.write(RES+0x6d8,profile)
                m.write(0x187b38,SYS);m.write(SYS+0x2464,0)
                m.write(OBJ+8,0x11110000);m.write(OBJ+12,23);m.write(OBJ+16,32)
                m.write(OBJ+0x5260,page);m.write(OBJ+0x50,0x2222)
                for j,v in enumerate([0x46494c,0xffffff,0x53595c,0xffffff]):m.write(OBJ+0x1b64+4*j,v)
                def button(v):
                    assert v.reg[4]==ui['button_va'];v.write(v.reg[4],VT);return v.reg[4]
                def label(v):v.write(v.reg[4],VT);return v.reg[4]
                def ctor(v):
                    assert v.reg[4]==OBJ+4 and v.reg[5]==ui['button_va'] and v.reg[6]==303
                    assert [v.read(v.reg[7]+4*j) for j in range(4)]==[10,177,694,69]
                    assert v.read(v.reg[29]+16)==0x4d58
                    assert v.read(v.reg[29]+20)==9
                    assert [v.read(v.read(v.reg[29]+28)+j*4) for j in range(4)]==[62,0,554,69]
                    v.write(ui['button_va']+0x2c,0x183);return 0
                def virtual(v):
                    assert v.reg[4]==ui['status_label_va']
                    assert [v.read(v.reg[6]+4*j) for j in range(4)]==[72,248,610,65];return 0
                def settext(v):labels[v.reg[4]]=v.text(v.reg[5]);assert v.reg[6]==0;return 0
                def visible(v):visibility[v.reg[4]]=v.reg[5];return 0
                def dbg(v):
                    op=v.reg[4]-MAGIC
                    if op==3:return flags[0]|(display[0]<<8)
                    if op==2:flags[0]=v.reg[5];return 1
                    if op in [1,6]:return 1
                    raise AssertionError(op)
                dbg_at=next(s.address for d in m.pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.name==b'DbgDebugPrint')
                m.write(dbg_at,0xf2000010);m.hooks[0xf2000010]=dbg
                m.write(VT+0x18,0xf2000020);m.hooks[0xf2000020]=virtual
                m.hooks.update({0x13ea5c:button,0x139458:label,0x13d488:ctor,0x138e90:lambda v:0,
                                0x139528:lambda v:0,0x139668:settext,0x1393e0:visible,
                                0x139020:lambda v:draw.append(v.reg[4]) or 0})
                def call(at,args):
                    m.reg[4:8]=args+[0]*(4-len(args));m.reg[29]=STACK;m.reg[31]=STOP
                    saved={r:0xaaaa0000+r for r in range(16,24)}
                    for r,val in saved.items():m.reg[r]=val
                    m.run(at,{STOP},100000)
                    assert m.reg[29]==STACK and m.reg[31]==STOP and all(m.reg[r]==val for r,val in saved.items())
                call(ui['constructor'],[OBJ]);call(ui['refresh'],[])
                assert labels[ui['button_va']+0x74]=='Debugging: On'
                assert visibility=={ui['button_va']:page,ui['status_label_va']:page}
                assert m.read(ui['status_label_va']+0x60)==(0 if profile==3 else 0xffffff)
                event_ptr=m.pe.get_data(0x16f99c-m.base,4);handler=int.from_bytes(event_ptr,'little')
                call(handler,[OBJ,0x4d58]);assert flags[0]==0 and labels[ui['button_va']+0x74]=='Debugging: Off'
                # Other menu actions retain the original event handler.
                m.hooks[0xc78ec]=lambda v:0
                cases.append('Settings page='+str(page)+' theme='+str(profile)+' status='+str(status))
    return cases


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--build',type=Path,required=True);a=parser.parse_args()
    cases=[]
    for name,fn in [('queue/writer',core_cases),('PE integrity',image_checks),('event hooks',client_cases),('native Settings',settings_cases),('inline source switch table',switch_table_cases),('inherited navigation',inherited_cases)]:
        print('Checking '+name,flush=True);cases+=fn(a.build)
    result=dict(passed=True,cases=len(cases),checks=cases,firmware_executed_natively=False,
        limits=['CE APIs, scheduling, USB filesystems and registry persistence are explicit fixtures.',
               'No physical USB timing, actual loader, audio or touchscreen behavior was measured.'])
    write(a.build/'verification.json',result);print(json.dumps(result,indent=2))

if __name__=='__main__':main()
