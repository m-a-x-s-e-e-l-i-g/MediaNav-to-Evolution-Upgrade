"""Execute written MIPS consumer/cover paths, with owned-mutex and GDI fixtures."""
import hashlib
import struct
from verify_media_responsiveness import VM,parsed,STACK
from inspect_wave_queue import STOP
from inspect_bt_pairing import put,data
from verify_usb_input_safety import relocated
from patch_shared_mapping_checks import reloc_records

MAP,OBJ,UI,DIALOG,OWNER,CRITICAL,SOURCE,MANAGER,SHARED=0x43000000,0x41000000,0x44000000,0x45000000,0x46000000,0x47000000,0x48000000,0x49000000,0x4a000000
CREATE,WAIT,RELEASE,CLOSE=0xf0900000,0xf0900004,0xf0900008,0xf090000c
OLD,NEW,DEFAULT=0x12340001,0x56780002,0x12340075

def call(m,va,args,limit=100000):
    saved={r:0x12340000+r for r in (*range(16,24),28,30)}
    for r,v in saved.items():m.reg[r]=v
    m.reg[4:8]=list(args)+[0]*(4-len(args));m.reg[29]=STACK;m.reg[31]=STOP
    m.write(STACK-0x4000,0xa55aa55a);m.write(STACK+0x30,0xa55aa55a)
    m.run(va,{STOP},limit=limit)
    assert m.reg[29]==STACK and m.reg[31]==STOP and all(m.reg[r]==v for r,v in saved.items())
    assert m.read(STACK-0x4000)==m.read(STACK+0x30)==0xa55aa55a
    return m.reg[2]

class Fixture:
    def __init__(self,raw,recipe=None,delta=0,create_ok=True,wait_result=0,publish_at_read=False):
        self.p=parsed(raw);self.delta=delta;self.recipe=recipe
        self.app=recipe is None or recipe['code_va']>0x100000
        ranges=[(0x1def8+delta,0x1e174+delta),(0x4dcc8+delta,0x4e22c+delta),
                (0x4e22c+delta,0x4e3bc+delta),(0x138d60+delta,0x138e90+delta),
                (0x138860+delta,0x138ba4+delta),(0x138ba4+delta,0x138d60+delta),
                (0x1386e8+delta,0x13878c+delta)] if self.app else [(0x23c44+delta,0x23ce0+delta),(0x24094+delta,0x240b0+delta)]
        if recipe:
            ranges += [(r[0]+delta,r[1]+delta) for r in recipe['helper_rows']]
        self.m=VM(self.p,ranges);self.owned=False;self.open=False;self.create_ok=create_ok;self.wait_result=wait_result
        self.events=[];self.shown=[];self.texts=[];self.draws=[];self.alive={OLD,NEW,DEFAULT};self.pending=False
        self.publish_at_read=publish_at_read;self.selected=None
        m=self.m
        for at,n in ((MAP,0xe56),(OBJ,0x138),(UI,0x2400),(DIALOG,0x2800),(OWNER,0x40),(CRITICAL,0x30),
                     (SOURCE,0xe56),(MANAGER,0x50),(SHARED,0x20)):put(m,at,bytes(n))
        put(m,MAP+0xe4e,OLD.to_bytes(4,'little'));put(m,SOURCE+0xe4e,OLD.to_bytes(4,'little'))
        m.write(OBJ+0xc4,MAP);m.write(SHARED+8,MAP);m.write(MANAGER+0x40,SHARED)
        if self.app:
            m.write(0x186ce8+delta,OBJ);m.write(0x187b38+delta,UI);m.write(0x186538+delta,1)
            m.write(0x188294+delta,DIALOG);m.write(0x186100+delta,0);m.write(0x186ce0+delta,CRITICAL)
            m.write(CRITICAL+0x14,0x9900);m.write(CRITICAL+0x18,0x9901)
            m.write(DIALOG+0x8e0+4,OWNER);m.write(OWNER+0x24,0x9902)
            m.hooks.update({0x140310+delta:self.compare,0x140de4+delta:self.memset,
                0x140298+delta:lambda v:0,0xe5f58+delta:self.special,0xe6464+delta:self.standard,
                0x139668+delta:self.assign_text,0x140048+delta:self.get_object,0x13dde0+delta:self.default,
                0x139020+delta:lambda v:0,0x13fe40+delta:self.dc,
                0x140cf4+delta:self.blit,0x140ce4+delta:self.blit,0x140c34+delta:self.blit,
                0x140d04+delta:self.blit,0x140018+delta:lambda v:0,0x140c14+delta:lambda v:0})
        else:
            m.hooks.update({0x231a4+delta:lambda v:MANAGER,0x2516c+delta:self.delete,0x25668+delta:self.memcpy})
        if recipe:
            state=recipe['state_va']+delta
            close=0x185028 if self.app else next(s.address-delta for d in self.p.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.ordinal==553)
            wait=0x1850a0 if self.app else 0x2f048
            for at,value in ((state+0x100,CREATE),(state+0x104,RELEASE),(close+delta,CLOSE),(wait+delta,WAIT)):m.write(at,value)
            m.hooks.update({CREATE:self.create,WAIT:self.wait,RELEASE:self.release,CLOSE:self.close})
        original_plain=m.plain
        def plain(word):
            if self.publish_at_read and word>>26==0x22 and m.reg[(word>>21)&31]==MAP+0xe4e:
                assert self.owned
                self.pending=True;self.publish_at_read=False;self.events.append('publication deferred during handle load')
            original_plain(word)
        m.plain=plain
    def clobber(self):
        for r in (*range(3,16),24,25):self.m.reg[r]=0xdead0000+r
    def create(self,m):
        assert m.reg[4:6]==[0,0] and m.text(m.reg[6])=='MAXmade_USB_Status_v1'
        assert not self.open;self.open=self.create_ok;self.events.append('create');self.clobber();return 0x7777 if self.open else 0
    def wait(self,m):
        assert m.reg[4]==0x7777 and self.open and m.reg[5] in (0,0xffffffff)
        self.owned=self.wait_result in (0,0x80);self.events.append('wait');self.clobber();return self.wait_result
    def release(self,m):
        assert m.reg[4]==0x7777 and self.owned
        self.owned=False;self.events.append('release')
        if self.pending:
            self.alive.discard(OLD);put(m,MAP+0xe4e,NEW.to_bytes(4,'little'));self.pending=False
            self.events.append('deferred publication/delete completes')
        self.clobber();return 1
    def close(self,m):
        assert m.reg[4]==0x7777 and self.open and not self.owned
        self.open=False;self.events.append('close');self.clobber();return 1
    def compare(self,m):
        a,b=m.text(m.reg[4]),m.text(m.reg[5]);self.clobber();return 0 if a.casefold()==b.casefold() else 1
    def memset(self,m):
        put(m,m.reg[4],bytes([m.reg[5]&255])*m.reg[6]);value=m.reg[4];self.clobber();return value
    def standard(self,m):return self.show(m,'standard')
    def special(self,m):return self.show(m,'special')
    def show(self,m,kind):
        assert m.reg[4]==UI+0xc4 and m.reg[6]==6
        self.shown.append((kind,m.text(m.reg[5])));self.clobber();return 7
    def assign_text(self,m):
        self.texts.append(m.text(m.reg[5]));self.clobber();return 0
    def default(self,m):
        assert m.reg[4:6]==[1,0x75] and self.owned
        self.clobber();return DEFAULT
    def get_object(self,m):
        assert self.owned and m.reg[5]==24
        if m.reg[4] not in self.alive:
            self.events.append('GetObject failure under lock');self.clobber();return 0
        put(m,m.reg[6],struct.pack('<4I2HI',0,64,32,192,1,24,0))
        self.events.append('GetObject under lock');self.clobber();return 24
    def dc(self,m):
        assert m.reg[4] in self.alive
        if m.reg[4] in (OLD,NEW):assert self.owned
        self.selected=m.reg[4];self.clobber();return 0x9910
    def blit(self,m):
        assert self.selected in self.alive
        if self.selected in (OLD,NEW):assert self.owned
        self.draws.append(self.selected);self.clobber();return 1
    def memcpy(self,m):
        assert self.owned
        dst=m.reg[4];put(m,dst,data(m,m.reg[5],m.reg[6]));self.events.append('publish under lock');self.clobber();return dst
    def delete(self,m):
        assert self.owned and m.reg[4] in self.alive
        handle=m.reg[4]
        assert int.from_bytes(data(m,MAP+0xe4e,4),'little')!=handle
        assert int.from_bytes(data(m,SOURCE+0xe4e,4),'little')!=handle
        self.alive.remove(handle);self.events.append('delete after invalidation');self.clobber();return 1
    def complete(self):assert not self.open and not self.owned

def verify(old_app,new_app,new_usb,ar,ur):
    traces=[]
    for mode in (0,2,3):
        for title in ('','A','ABCD','Song.mp3','Song.WMA','Other.wav','A'*259,'A'*255+'.Mp3','\u0627\u0644\u0645\u0648\u0633\u064a\u0642\u0649.mp3'):
            outcomes=[]
            for raw,recipe in ((old_app,None),(new_app,ar)):
                f=Fixture(raw,recipe);put(f.m,MAP+0x20e,(title+'\0').encode('utf-16-le'))
                f.m.write(UI+0xac,1 if mode else 0);f.m.write(UI+0x88,mode)
                call(f.m,0x1def8,[]);f.complete();outcomes.append(f.shown)
            assert outcomes[0]==outcomes[1]
            traces.append(dict(name='title display parity',mode=mode,title=title,result=outcomes[1]))
    for length in range(260):
        f=Fixture(new_app,ar);put(f.m,MAP+0x20e,('A'*length+'\0').encode('utf-16-le'))
        call(f.m,0x1def8,[]);assert f.shown==[('standard','A'*length)];f.complete()
        traces.append(dict(name='every title boundary',length=length))
    for title,artist in (('Track.mp3','Artist'),('Track.WMA','\u0627\u0644\u0641\u0646\u0627\u0646'),('A'*259,'B'*259),('','')):
        for flag in (0,1):
            outcomes=[]
            for raw,recipe in ((old_app,None),(new_app,ar)):
                f=Fixture(raw,recipe);put(f.m,MAP+0x20e,(title+'\0').encode('utf-16-le'))
                put(f.m,MAP+0x416,(artist+'\0').encode('utf-16-le'))
                call(f.m,0x4dcc8,[DIALOG,MAP,flag]);outcomes.append(f.texts);f.complete()
            assert outcomes[0]==outcomes[1]
            traces.append(dict(name='complete title/artist display parity',title=title,artist=artist,flag=flag))
    print('Title boundaries and original display parity passed',flush=True)
    for delta in (0,0x10000,0x120000,0x500000):
        app=new_app if not delta else relocated(new_app,delta);usb=new_usb if not delta else relocated(new_usb,delta)
        for title,artist in (('A'*260,'B'*260),('Track.mp3','Artist'),('',''),('X'*259,'Y'*259)):
            f=Fixture(app,ar,delta);put(f.m,MAP+0x20e,title.encode('utf-16-le'));put(f.m,MAP+0x416,artist.encode('utf-16-le'))
            call(f.m,0x1def8+delta,[]);assert f.shown[0][1]==title[:259].removesuffix('.mp3')
            call(f.m,0x4dcc8+delta,[DIALOG,MAP,1]);f.complete()
            assert len(f.texts)==2 and all(len(v)<=259 for v in f.texts)
            traces.append(dict(name='bounded title/artist consumers',delta=delta,title_length=len(title),artist_length=len(artist),shown=f.shown,texts=f.texts))
        for create_ok,wait in ((True,0),(True,0x80),(False,0),(True,0x102),(True,0xffffffff)):
            f=Fixture(app,ar,delta,create_ok=create_ok,wait_result=wait)
            put(f.m,MAP+0x20e,'Track\0'.encode('utf-16-le'));call(f.m,0x1def8+delta,[])
            call(f.m,0x4dcc8+delta,[DIALOG,MAP,0]);f.complete()
            success=create_ok and wait in (0,0x80)
            assert bool(f.shown)==bool(f.texts)==success
            traces.append(dict(name='snapshot mutex success/failure',delta=delta,create=create_ok,wait=wait,events=f.events))
        for stale in (False,True):
            f=Fixture(app,ar,delta,publish_at_read=stale)
            call(f.m,0x4e22c+delta,[DIALOG,MAP,1]);f.complete()
            assert f.m.read(DIALOG+0x8e0+0x3c)==OLD
            for draw in (0x138860,0x138ba4):
                put(f.m,OWNER+0x10,bytes(0x10));call(f.m,draw+delta,[DIALOG+0x8e0,0,OWNER+0x10])
            f.complete();assert f.draws==([] if stale else [OLD,OLD])
            traces.append(dict(name='cover acquisition and both paint paths',delta=delta,publication_between_loads=stale,draws=f.draws,events=f.events))
        f=Fixture(app,ar,delta);call(f.m,0x4e22c+delta,[DIALOG,MAP,0]);f.publish_at_read=True
        call(f.m,0x138860+delta,[DIALOG+0x8e0,0]);f.complete()
        call(f.m,0x138860+delta,[DIALOG+0x8e0,0]);f.complete();assert f.draws==[OLD] and OLD not in f.alive
        traces.append(dict(name='delete waits through complete paint then stale paint skipped',delta=delta,events=f.events))
        f=Fixture(app,ar,delta);f.alive.remove(OLD)
        call(f.m,0x4e22c+delta,[DIALOG,MAP,0]);call(f.m,0x138860+delta,[DIALOG+0x8e0,0]);f.complete()
        assert f.m.read(DIALOG+0x8e0+0x3c)==0 and not f.draws
        traces.append(dict(name='GetObject failure clears widget and prevents invalid paint',delta=delta))
        f=Fixture(app,ar,delta);call(f.m,0x4e22c+delta,[DIALOG,MAP,0]);f.alive.remove(OLD)
        call(f.m,0x138860+delta,[DIALOG+0x8e0,0]);f.complete();assert not f.draws
        traces.append(dict(name='draw revalidates handle after external process teardown',delta=delta))
        f=Fixture(app,ar,delta);f.m.write(0x186538+delta,0);put(f.m,MAP+0xe4e,bytes(4))
        call(f.m,0x4e22c+delta,[DIALOG,MAP,0]);call(f.m,0x138860+delta,[DIALOG+0x8e0,0]);f.complete()
        assert f.m.read(DIALOG+0x8e0+0x3c)==0 and not f.draws
        traces.append(dict(name='missing resource manager never shows modal dialog while locked',delta=delta))
        for create_ok,wait in ((False,0),(True,0x102),(True,0xffffffff)):
            f=Fixture(usb,ur,delta,create_ok=create_ok,wait_result=wait)
            assert call(f.m,ur['code_va']+0x500+delta,[OLD,SOURCE+0xe4e])==0
            assert call(f.m,0x24094+delta,[SHARED,SOURCE,0,0xe56])==0
            call(f.m,ur['code_va']+0x800+delta,[SOURCE+0xe4e,NEW]);f.complete()
            assert OLD in f.alive and data(f.m,MAP+0xe4e,4)==data(f.m,SOURCE+0xe4e,4)==OLD.to_bytes(4,'little')
            traces.append(dict(name='writer/delete/install lock failure retains valid original handle',delta=delta,create=create_ok,wait=wait))
        f=Fixture(app,ar,delta);put(f.m,MAP+0xe4e,bytes(4))
        call(f.m,0x4e22c+delta,[DIALOG,MAP,0]);call(f.m,0x138860+delta,[DIALOG+0x8e0,0]);f.complete()
        assert f.m.read(DIALOG+0x8e0+0x3c)==DEFAULT and f.draws==[DEFAULT]
        call(f.m,0x1386e8+delta,[DIALOG+0x8e0]);assert f.m.read(ar['state_va']+delta+0x200)==0
        traces.append(dict(name='default cover and reused widget tracking reset',delta=delta))
        f=Fixture(usb,ur,delta);call(f.m,ur['code_va']+0x500+delta,[OLD,SOURCE+0xe4e]);f.complete()
        assert OLD not in f.alive and data(f.m,SOURCE+0xe4e,4)==data(f.m,MAP+0xe4e,4)==bytes(4)
        call(f.m,0x24094+delta,[SHARED,SOURCE,0,0xe56]);assert data(f.m,MAP+0xe4e,4)==bytes(4)
        call(f.m,ur['code_va']+0x800+delta,[SOURCE+0xe4e,NEW]);f.complete()
        call(f.m,0x24094+delta,[SHARED,SOURCE,0,0xe56]);f.complete()
        assert int.from_bytes(data(f.m,MAP+0xe4e,4),'little')==NEW
        traces.append(dict(name='delete clears local/published handle before free then install/publish',delta=delta,events=f.events))
        print('USB consumer/cover checks passed at delta '+hex(delta),flush=True)
    return dict(cases=len(traces),traces=traces,actual_text_cover_writer_delete_draw_instructions=True,
                mutex_gdi_scheduler_are_fixtures=True,native_executed=False,hardware_tested=False)

def structure(before,after,r):
    a,b=parsed(before),parsed(after);prefix=bytearray(after[:len(before)])
    for e in reversed(r['edits']):
        at=e['offset'];assert after[at:at+e['bytes']].hex()==e['after_hex'];prefix[at:at+e['bytes']]=bytes.fromhex(e['before_hex'])
    assert bytes(prefix)==before
    assert len(b.sections)==len(a.sections)+2
    assert all(x.__pack__()==y.__pack__() for x,y in zip(a.sections,b.sections))
    oldimports=[(d.dll,[(s.address,s.ordinal,s.name) for s in d.imports]) for d in a.DIRECTORY_ENTRY_IMPORT]
    assert [(d.dll,[(s.address,s.ordinal,s.name) for s in d.imports]) for d in b.DIRECTORY_ENTRY_IMPORT][:-1]==oldimports
    assert [s.ordinal for s in b.DIRECTORY_ENTRY_IMPORT[-1].imports]==[555,556]
    assert a.OPTIONAL_HEADER.AddressOfEntryPoint==b.OPTIONAL_HEADER.AddressOfEntryPoint
    spans=[(e['va']-0x10000,e['va']-0x10000+e['bytes']) for e in r['edits'] if e['va']]
    current=set(reloc_records(b))
    assert all(v in current for v in reloc_records(a) if not any(lo<=v[0]<hi for lo,hi in spans))
    for delta in (0,0x10000,0x120000,0x500000):
        pe=parsed(after if not delta else relocated(after,delta));d=pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        rows=list(struct.iter_unpack('<5I',pe.get_data(d.VirtualAddress,d.Size)))
        assert all(x[1]<=y[0] for x,y in zip(rows,rows[1:]))
        for row in r['helper_rows']:assert tuple(v+delta if v else 0 for v in row) in rows
    return dict(cases=1,old_prefix_recipe_reversible=True,old_sections_and_imports_retained=True,
                helper_exception_rows_and_relocations_checked=True)
