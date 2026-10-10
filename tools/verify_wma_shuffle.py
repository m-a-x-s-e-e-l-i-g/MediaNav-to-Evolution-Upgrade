"""Written MIPS-byte checks with explicit file/catalog/scheduler fixtures."""
import hashlib
import json
import random
import struct
import uuid
from pathlib import Path
from patch_wma_shuffle import patch,EXACT,SEEK,FIELD,GATE,YIELD,BUILD,WRAP,READY
from verify_artwork_playlist import vm as previous_vm,verify as previous_verify,regressions
from verify_usb_reliability import conversion,OBJ,INPUT,OUTPUT,DIALOG,STACK,STOP
from verify_media_responsiveness import parsed
from verify_usb_input_safety import relocated,wide
from inspect_bt_pairing import put,data

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'build/artwork-playlist-development-01/payload/upgrade/Storage Card/System/MgrUSB.exe'
HEADER=uuid.UUID('75b22630-668e-11cf-a6d9-00aa0062ce6c').bytes_le
CONTENT=uuid.UUID('75b22633-668e-11cf-a6d9-00aa0062ce6c').bytes_le
EXTENDED=uuid.UUID('d2d0a440-e307-11d2-97f0-00a0c95ea850').bytes_le
UNKNOWN=uuid.UUID('11111111-2222-3333-4444-555555555555').bytes_le

def vm(raw,delta=0):
    m=previous_vm(raw,delta)
    m.ranges.extend((a+delta,b+delta) for a,b in [(EXACT,EXACT+0x200),(SEEK,SEEK+0x200),
        (FIELD,FIELD+0x400),(GATE,GATE+0x180),(YIELD,YIELD+0x80),(BUILD,BUILD+0x600),
        (WRAP,WRAP+0x180),(READY,READY+0x180),(0x182dc,0x18f54),(0x198e4,0x19ae0),
        (0x19af8,0x19c94),(0x1b5b0,0x1b670),(0x1dd94,0x1ddb0),
        (0x19564,0x196c4),(0x1cf38,0x1d158),(0x1d23c,0x1d78c),(0x1d78c,0x1d87c)])
    conversion(m,delta=delta)
    m.hooks[0x2594c+delta]=lambda v:int(data(v,v.reg[4],v.reg[6])!=data(v,v.reg[5],v.reg[6]))
    m.hooks[0x255b8+delta]=lambda v:int(v.text(v.reg[4]).lower()!=v.text(v.reg[5]).lower())
    return m

def invoke(m,at,args,stack_args=(),limit=1000000):
    saved={r:0x12340000+r for r in (*range(16,24),28,30)}
    for r,v in saved.items():m.reg[r]=v
    m.reg[4:8]=list(args)+[0]*(4-len(args));m.reg[29]=STACK;m.reg[31]=STOP
    for i,n in enumerate(stack_args):m.write(STACK+0x10+4*i,n)
    m.write(STACK-0x6000,0xa55aa55a);m.write(STACK+0x30,0xa55aa55a)
    m.run(at,{STOP},limit=limit)
    assert m.reg[29]==STACK and m.reg[31]==STOP
    assert all(m.reg[r]==v for r,v in saved.items()),'Callee-saved registers'
    assert m.read(STACK-0x6000)==m.read(STACK+0x30)==0xa55aa55a
    return m.reg[2]

def object_bytes(guid,body):return guid+struct.pack('<Q',24+len(body))+body
def content(title='Title',artist='Artist',others=('', '', '')):
    fields=[(s+'\0').encode('utf-16-le') if s else b'' for s in (title,artist,*others)]
    return object_bytes(CONTENT,struct.pack('<5H',*(len(x) for x in fields))+b''.join(fields))
def descriptor(name='WM/ALBUMTITLE',value='Album',kind=0,nul=True):
    name=(name+('\0' if nul else '')).encode('utf-16-le')
    value=(value+'\0').encode('utf-16-le') if isinstance(value,str) else value
    return struct.pack('<H',len(name))+name+struct.pack('<HH',kind,len(value))+value
def extended(entries):return object_bytes(EXTENDED,struct.pack('<H',len(entries))+b''.join(entries))
def asf(children):
    body=b''.join(children)
    return HEADER+struct.pack('<QI',30+len(body),len(children))+b'\1\2'+body+b'AUDIO'

class File:
    def __init__(self,m,b,delta=0):
        self.m=m;self.b=b;self.pos=0;self.events=[];self.reads=0;self.seeks=0;self.closes=0
        self.fail_read=None;self.short_read=None;self.fail_seek=None;self.open_fail=False;self.size_override=None
        for at,hook in [(0x2f034,self.open),(0x2f058,self.read),(0x2f060,self.seek),
                        (0x2f064,self.size),(0x2f038,self.close)]:
            target=0xf1100000+at;m.write(at+delta,target);m.hooks[target]=hook
        wide(m,INPUT,'\\MD\\song.wma');m.write(OBJ+0xe44,0xabcdef00)
        m.write(OBJ-4,0xa55aa55a);m.write(OBJ+0xe48,0xa55aa55a)
    def open(self,v):
        assert v.reg[4:8]==[INPUT,0x80000000,1,0]
        assert [v.read(v.reg[29]+i) for i in (0x10,0x14,0x18)]==[3,0x80,0]
        return 0xffffffff if self.open_fail else 0x7777
    def size(self,v):assert v.reg[4:6]==[0x7777,0];return len(self.b) if self.size_override is None else self.size_override
    def read(self,v):
        handle,dest,n,count=v.reg[4:8];assert handle==0x7777 and 0<=n<=260
        assert v.read(v.reg[29]+0x10)==0
        self.reads+=1;self.events.append(('read',self.pos,n))
        assert 0<=self.pos<=len(self.b)
        if self.reads==self.fail_read:return 0
        got=min(n,len(self.b)-self.pos)
        if self.reads==self.short_read:got=max(0,got-1)
        put(v,dest,self.b[self.pos:self.pos+got]);v.write(count,got);self.pos+=got
        return 7 # BOOL is nonzero, not necessarily 1.
    def seek(self,v):
        assert v.reg[4]==0x7777;self.seeks+=1
        if self.seeks==self.fail_seek:return 0xffffffff
        high=v.reg[6];distance=v.reg[5]
        if high:distance|=v.read(high)<<32
        pos=distance if v.reg[7]==0 else self.pos+distance
        self.events.append(('seek',pos));assert 0<=pos<=len(self.b)
        self.pos=pos;return pos
    def close(self,v):assert v.reg[4]==0x7777;self.closes+=1;return 1

def parse(raw,b,delta=0,**faults):
    m=vm(raw,delta);f=File(m,b,delta)
    for k,v in faults.items():setattr(f,k,v)
    assert invoke(m,0x182dc+delta,[OBJ,INPUT,OBJ])==0
    assert m.read(OBJ+0xe44)==0xabcdef00 and m.read(OBJ-4)==m.read(OBJ+0xe48)==0xa55aa55a
    assert f.closes==(0 if f.open_fail else 1)
    return m,f

def wma(raw):
    cases=0
    good=asf([content(),extended([descriptor()])])
    for title,artist,album in [('Title','Artist','Album'),('日本語 😀','Björk','Mañana'),
                               ('','Artist',''),('','', ''),('x'*29+'😀'+'tail','x'*500,'Album')]:
        for order in (0,1):
            children=[content(title,artist),extended([descriptor(value=album)])]
            if order:children.reverse()
            m,f=parse(raw,asf(children))
            for off,text,flag in ((0x410,title,1),(0x618,artist,4),(0x208,album,2)):
                prefix=text.encode('utf-16-le')[:60]
                if len(prefix)==60 and 0xd800<=int.from_bytes(prefix[-2:],'little')<=0xdbff:prefix=prefix[:-2]
                expected=prefix.decode('utf-16-le')
                assert m.text(OBJ+off)==expected
                assert bool(m.read(OBJ+0xe40)&flag)==bool(expected)
            assert m.read(OBJ+0xe40)&0x80;cases+=1
    for length in (0,1,10,12,49,50,51,127,128,129,256,300,32766):
        m,f=parse(raw,asf([content(),extended([descriptor('x'*length,b'\x99'*12,1),descriptor()])]))
        assert m.text(OBJ+0x208)=='Album' and m.text(OBJ+0x410)=='Title';cases+=1
    for nul in (False,True):
        m,f=parse(raw,asf([extended([descriptor('wm/albumtitle','Album',nul=nul)])]))
        assert m.text(OBJ+0x208)=='Album';cases+=1
    m,f=parse(raw,asf([extended([descriptor(kind=1,value=b'abc'),descriptor(value='Real')])]))
    assert m.text(OBJ+0x208)=='Real';cases+=1
    m,f=parse(raw,asf([object_bytes(UNKNOWN,b'x'*1024),content(),extended([descriptor()])]))
    assert m.text(OBJ+0x410)=='Title' and f.seeks;cases+=1
    # Every byte-prefix truncation, while the physical file may still contain data.
    for cut in range(len(good)-5):
        m,f=parse(raw,good[:cut])
        assert m.read(OBJ+0xe40)==0x80 and m.text(OBJ+0x410)=='' and m.text(OBJ+0x208)==''
        cases+=1
    # Length/count mutations cannot escape their enclosing object into audio bytes.
    malformed=[]
    for off,value,fmt in [(0,0,'I'),(16,29,'I'),(16,len(good)+1,'I'),(20,1,'I'),
                           (24,0,'I'),(24,17,'I'),(28,0,'B'),(29,0,'B'),
                           (46,23,'I'),(46,len(good),'I'),(50,1,'I'),(54,65535,'H'),(54,1,'H')]:
        b=bytearray(good);struct.pack_into('<'+fmt,b,off,value);malformed.append(bytes(b))
    malformed += [asf([extended([struct.pack('<H',65534)+b'xx'])]),
                  asf([extended([struct.pack('<H',1)+b'x'+struct.pack('<HH',0,0)])]),
                  asf([extended([descriptor(value=b'x')])]),
                  asf([content()+object_bytes(UNKNOWN,b'bad')])[:30]]
    for b in malformed:
        m,f=parse(raw,b);assert m.read(OBJ+0xe40)==0x80;cases+=1
    base_m,base_f=parse(raw,good)
    for fault in ('fail_read','short_read'):
        for i in range(1,base_f.reads+1):
            m,f=parse(raw,good,**{fault:i});assert m.read(OBJ+0xe40)==0x80
            assert f.reads==i;cases+=1
    seek_blob=asf([content('x'*300,'y'*300),object_bytes(UNKNOWN,b'x'*40),
                   extended([descriptor('x'*300,b'ab',1),descriptor(value='z'*300)])])
    _,f=parse(raw,seek_blob)
    for i in range(1,f.seeks+1):
        m,g=parse(raw,seek_blob,fail_seek=i);assert m.read(OBJ+0xe40)==0x80 and g.seeks==i;cases+=1
    for size in (0,29,0xffffffff):
        m,f=parse(raw,good,size_override=size);assert m.read(OBJ+0xe40)==0x80 and not f.reads;cases+=1
    m,f=parse(raw,good,open_fail=True);assert not f.reads;cases+=1
    for delta in (0x1000,0x10000,0x123000):
        m,f=parse(relocated(raw,delta),good,delta);assert m.text(OBJ+0x208)=='Album';cases+=1
    # The original implementation's long name copy exceeds its 256-byte array.
    m=vm(SOURCE.read_bytes());f=File(m,asf([extended([descriptor('x'*150)])]))
    copies=[];native_copy=m.hooks[0x25668]
    def checked(v):
        if v.reg[4]==STACK-0x2b8+0x188:
            copies.append(v.reg[6]);assert v.reg[6]<=256,'Original descriptor-name array overflow'
        return native_copy(v)
    m.hooks[0x25668]=checked
    try:invoke(m,0x182dc,[OBJ,INPUT,OBJ])
    except AssertionError as error:assert str(error)=='Original descriptor-name array overflow'
    else:raise AssertionError('Expected original long-name defect')
    assert copies==[302]
    return dict(cases=cases,original_overflow_copy_bytes=302,bounded_read_counts=True,
                containing_object_limits=True,display_limit_utf16_units=30)

class Catalog:
    def __init__(self,m,folders,delta=0,seed=1):
        self.m=m;self.folders=folders;self.ids=list(folders);self.delta=delta
        self.rng=random.Random(seed);self.sleeps=[];self.randoms=0;self.gets=0;self.nexts=0;self.published=[]
        self.cancel_at=None;self.cancel_kind='off';self.cancel_next=None;self.invalid_next=None
        self.check_building=False
        put(m,OUTPUT,b'\xa5'*20000);m.write(OUTPUT-4,0xa55aa55a);m.write(OUTPUT+20000,0xa55aa55a)
        # The builder uses the actual global array, exactly 5,000 DWORDs.
        put(m,0x30108+delta,b'\xa5'*20000);m.write(0x30104+delta,0xa55aa55a);m.write(0x34f28+delta,0xa55aa55a)
        m.write(DIALOG+0x48,0x5555);m.write(DIALOG+0x40,0x6666)
        for at,hook in [(0x132fc,self.folder),(0x12f10,self.first),(0x12f48,self.count),
                        (0x12ed8,self.count),(0x14720,self.next),(0x2598c,self.random),(0x24094,self.publish)]:
            m.hooks[at+delta]=hook
        m.write(0x2f008+delta,0xf1200000);m.hooks[0xf1200000]=self.sleep
    def folder(self,v):
        for k,(first,n) in self.folders.items():
            if first<=v.reg[5]<first+n:return k
        return 0xffffffff
    def first(self,v):self.gets+=1;return self.folders[v.reg[5]][0]
    def count(self,v):return self.folders[v.reg[5]][1]
    def cancel(self):
        if self.cancel_kind=='off':self.m.write(OBJ+0x291e,0)
        else:self.m.write(DIALOG+0x18,1)
    def sleep(self,v):
        assert v.reg[4] in (0,1);self.sleeps.append(v.reg[4])
        if self.cancel_at==len(self.sleeps):self.cancel()
        # During the builder, no list may be marked readable before completion.
        if self.check_building:assert self.m.read(OBJ+0xe4c)==0 and self.m.read(OBJ+0xe5c)==0
        return 0
    def next(self,v):
        self.nexts+=1
        if self.cancel_next==self.nexts:self.cancel()
        if self.invalid_next is not None:return self.invalid_next
        return self.ids[(self.ids.index(v.reg[5])+1)%len(self.ids)]
    def random(self,v):self.randoms+=1;v.write(v.reg[4],self.rng.getrandbits(32));return 0
    def publish(self,v):
        assert v.reg[4:8]==[0x6666,OBJ+0x1ad8,0,0xe56]
        self.published.append(v.read(OBJ+0x291e));return 0

def shuffle(raw):
    cases=0;baseline=None
    for n in (1,2,3,5,31,32,33,64,100,5000):
        for anchor in (0,n-1):
            old=vm(SOURCE.read_bytes());a=Catalog(old,{1:(0,n)})
            old.write(OBJ+0x291e,1)
            assert invoke(old,0x198e4,[OBJ,OUTPUT,0,n-1],[1,1,anchor])==0
            new=vm(raw);b=Catalog(new,{1:(0,n)})
            new.write(OBJ+0x291e,1)
            assert invoke(new,GATE,[OBJ,OUTPUT,0,n-1],[1,1,anchor])==0
            assert data(new,OUTPUT,n*4)==data(old,OUTPUT,n*4)
            result=[new.read(OUTPUT+i*4) for i in range(n)]
            assert result[0]==anchor and sorted(result)==list(range(n))
            assert new.read(OUTPUT-4)==new.read(OUTPUT+20000)==0xa55aa55a
            if n==5000:baseline=dict(tracks=n,old_sleep1_calls=sum(a.sleeps),new_sleep1_calls=sum(b.sleeps),
                                      new_sleep0_calls=len(b.sleeps)-sum(b.sleeps),same_order=True)
            cases+=1
    for start,last,anchor in [(0,5000,-1),(0,0,1),(2,3,1),(0xffffffff,4,-1),(4,3,-1),(0,1,0xfffffffe)]:
        m=vm(raw);c=Catalog(m,{1:(0,3)});m.write(OBJ+0x291e,1)
        assert invoke(m,GATE,[OBJ,OUTPUT,start,last],[1,1,anchor&0xffffffff])==0xffffffff
        assert not c.sleeps and not c.randoms and data(m,OUTPUT,20000)==b'\xa5'*20000;cases+=1
    folders={2:(3,4),1:(0,3),4:(7,5)}
    for seed in range(10):
        m=vm(raw);c=Catalog(m,folders,seed=seed);c.check_building=True;m.write(OBJ+0x2916,5)
        assert invoke(m,0x1dd94,[OBJ-8,1])==0
        assert m.read(OBJ+0xe4c)==12 and m.read(OBJ+0xe5c)==0x30108
        result=[m.read(0x30108+i*4) for i in range(12)]
        assert result[0]==5 and sorted(result[:4])==list(range(3,7))
        assert sorted(result[4:7])==list(range(3)) and sorted(result[7:])==list(range(7,12))
        assert c.published==[1] and m.read(OBJ+0x1ab4)==1
        assert invoke(m,READY,[OBJ])==1;cases+=1
    # Cancellation at every yielding boundary, during fill and selection.
    total_sleeps=2*sum(n for _,n in folders.values())-len(folders)
    for kind in ('off','removed'):
        for at in range(1,total_sleeps+1):
            m=vm(raw);c=Catalog(m,folders);c.cancel_at=at;c.cancel_kind=kind;m.write(OBJ+0x2916,5)
            assert invoke(m,0x1b5b0,[OBJ,1])==0xffffffff
            assert all(m.read(OBJ+off)==0 for off in (0xe4c,0xe5c,0xe58,0xe50,0xe54,0x291e,0x2938,0x1ab4))
            assert c.published==[0] and len(c.sleeps)==at and invoke(m,READY,[OBJ])==0
            cases+=1
        for at in (1,2,3):
            m=vm(raw);c=Catalog(m,folders);c.cancel_next=at;c.cancel_kind=kind;m.write(OBJ+0x2916,5)
            assert invoke(m,0x1b5b0,[OBJ,1])==0xffffffff
            assert not m.read(OBJ+0xe4c) and not m.read(OBJ+0xe5c) and not m.read(OBJ+0x291e)
            cases+=1
    # Original bytes publish a full folder count after the pool cancels midway.
    m=vm(SOURCE.read_bytes());c=Catalog(m,folders);c.cancel_at=2;m.write(OBJ+0x2916,5)
    invoke(m,0x1b5b0,[OBJ,1]);assert m.read(OBJ+0xe4c)==4 and m.read(OBJ+0xe5c)==0x30108
    # Invalid input, catalog ranges and cycles are bounded before array writes.
    for mode in (0,2,0xffffffff,0x80000000):
        m=vm(raw);c=Catalog(m,folders);m.write(OBJ+0x2916,5)
        assert invoke(m,0x1b5b0,[OBJ,mode])==0 and c.published==[0] and not c.sleeps;cases+=1
    for folder_map,track,bad_next in [({-1:(0,2)},0,None),({1:(0,0)},0,None),
             ({1:(0,5001)},0,None),({1:(4999,2)},4999,None),({1:(0,3000),2:(3000,3000)},0,None),
             ({1:(0,2)},0,5000)]:
        m=vm(raw);c=Catalog(m,folder_map);m.write(OBJ+0x2916,track);c.invalid_next=bad_next
        assert invoke(m,0x1b5b0,[OBJ,1])==0xffffffff and not m.read(OBJ+0xe5c);cases+=1
    # Readiness rejects empty/incomplete lists, bad cursor/count, malformed flag.
    for count,cursor,pointer,flag in [(0,0,0,1),(1,0,0,1),(5001,0,OUTPUT,1),
                                    (1,1,OUTPUT,1),(2,0xffffffff,OUTPUT,1),(2,0,OUTPUT,2),(2,0,OUTPUT,0x10001)]:
        m=vm(raw);m.write(OBJ+0xe4c,count);m.write(OBJ+0xe58,cursor);m.write(OBJ+0xe5c,pointer);m.write(OBJ+0x291e,flag)
        assert invoke(m,READY,[OBJ])==0;cases+=1
    for delta in (0x1000,0x10000,0x123000):
        m=vm(relocated(raw,delta),delta);c=Catalog(m,folders,delta);m.write(OBJ+0x2916,5)
        assert invoke(m,0x1b5b0+delta,[OBJ,1])==0 and m.read(OBJ+0xe5c)==0x30108+delta;cases+=1
    return dict(cases=cases,baseline=baseline,original_cancel_published_count=4,
                cancellation_checked_per_track=True,native_timing_measured=False)

def selectors(raw):
    cases=0
    # Execute the five patched selector sites through their real conditional branch.
    for at,objreg,fall,yes in [(0x19598,16,0x195ac,0x1965c),(0x1cf60,16,0x1cf74,0x1cfbc),
                             (0x1d338,17,0x1d34c,0x1d408),(0x1d55c,17,0x1d570,0x1d6f8),
                             (0x1d7b4,16,0x1d7c8,0x1d810)]:
        for count,cursor,ptr,flag,accepted in [(0,0,0,1,False),(2,0,OUTPUT,1,True),
             (2,1,OUTPUT,1,True),(2,2,OUTPUT,1,False),(5001,0,OUTPUT,1,False),
             (2,0,0,1,False),(2,0,OUTPUT,0,False)]:
            m=vm(raw);m.write(OBJ+0xe4c,count);m.write(OBJ+0xe58,cursor);m.write(OBJ+0xe5c,ptr);m.write(OBJ+0x291e,flag)
            m.reg[objreg]=OBJ;m.reg[29]=STACK;m.reg[31]=STOP
            m.run(at,{fall,yes},limit=1000)
            assert m.pc==(yes if accepted else fall);cases+=1
    return dict(cases=cases,selector_sites=5,incomplete_list_uses_sequential_path=True)

def structure(raw,recipe):
    p=parsed(raw);old=parsed(SOURCE.read_bytes())
    assert len(raw)==len(SOURCE.read_bytes()) and [s.__pack__() for s in p.sections]==[s.__pack__() for s in old.sections]
    assert p.OPTIONAL_HEADER.AddressOfEntryPoint==old.OPTIONAL_HEADER.AddressOfEntryPoint
    imports=lambda q:[(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in q.DIRECTORY_ENTRY_IMPORT]
    assert imports(p)==imports(old)
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];rows=[struct.unpack_from('<5I',p.get_data(d.VirtualAddress,d.Size),i) for i in range(0,d.Size,20)]
    assert rows==sorted(rows) and all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    previous=json.loads((ROOT/'build/artwork-playlist-development-01/manifest.json').read_text())
    for e in previous['recipe']['edits']:
        if 'assembly' not in e:continue
        at=int(e['va'],16);n=e['assembly']['used_bytes']
        if at>=0x3c000:assert p.get_data(at-0x10000,n)==old.get_data(at-0x10000,n)
    # Original ASF frame, context construction, destructor and cookie are exact.
    for a,b in ((0x182dc,0x18328),(0x18f08,0x18f84)):
        assert p.get_data(a-0x10000,b-a)==old.get_data(a-0x10000,b-a)
    for delta in (0x1000,0x10000,0x123000):
        q=parsed(relocated(raw,delta));d=q.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        moved=[struct.unpack_from('<5I',q.get_data(d.VirtualAddress,d.Size),i) for i in range(0,d.Size,20)]
        assert moved==[tuple(n+delta if n else 0 for n in row) for row in rows]
    restored=bytearray(raw)
    for e in recipe['edits']:
        off=int(e['offset'],16);assert restored[off:off+e['bytes']].hex()==e['after_hex']
        restored[off:off+e['bytes']]=bytes.fromhex(e['before_hex'])
    for index in (3,5):struct.pack_into('<I',restored,p.OPTIONAL_HEADER.DATA_DIRECTORY[index].get_file_offset()+4,old.OPTIONAL_HEADER.DATA_DIRECTORY[index].Size)
    assert bytes(restored)==SOURCE.read_bytes()
    return dict(sections_imports_entry_unchanged=True,previous_helpers_unchanged=True,asf_frame_cleanup_unchanged=True,
                exact_input_restored=True,added_pdata_rows=8,relocated_bases=3)

def verify(raw):
    checks={}
    for name,fn in [('wma',wma),('shuffle',shuffle),('selectors',selectors)]:
        checks[name]=fn(raw);print(name,json.dumps(checks[name]),flush=True)
    return checks

if __name__=='__main__':
    raw,recipe=patch(SOURCE.read_bytes());checks=verify(raw);checks['structure']=structure(raw,recipe)
    print(json.dumps(checks,indent=2))
