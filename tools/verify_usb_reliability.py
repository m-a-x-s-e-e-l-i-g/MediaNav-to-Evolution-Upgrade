"""Actual written MIPS bytes; explicit CE conversion/filesystem fixtures only.

Does not emulate CE scheduling, code-page tables, NAND flush or atomic rename.
"""
import codecs
import hashlib
import inspect
import json
import struct
from pathlib import Path
from patch_usb_reliability import patch,DECODE,LEGACY,SAVE,READ,LOAD,CACHE_HELP,GENRE_HELP,DATA,EXTRA_IAT
from verify_media_responsiveness import VM,parsed,STACK,STOP,verify_usb
from verify_usb_input_safety import common,wide,paths,metadata,playlists,relocations,relocated
from inspect_bt_pairing import put,data

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'build/usb-input-safety-development-01/payload/upgrade/Storage Card/System/MgrUSB.exe'
OBJ,INPUT,OUTPUT,CTX,DIALOG=0x41000000,0x42000000,0x43000000,0x44000000,0x45000000
PATH='\\Storage Card2\\USBMusicResume.dat'


def invoke(m,va,args,limit=200000):
    saved={r:0x12340000+r for r in (*range(16,24),28,30)}
    for r,v in saved.items():m.reg[r]=v
    m.reg[4:8]=list(args)+[0]*(4-len(args));m.reg[29]=STACK;m.reg[31]=STOP
    m.write(STACK-0x4000,0xa55aa55a);m.write(STACK+0x30,0xa55aa55a)
    m.run(va,{STOP},limit=limit)
    assert m.reg[29]==STACK and m.reg[31]==STOP
    assert all(m.reg[r]==v for r,v in saved.items()),'Callee-saved registers'
    assert m.read(STACK-0x4000)==m.read(STACK+0x30)==0xa55aa55a
    return m.reg[2]


def machine(raw,delta=0):
    ranges=[(DECODE,DECODE+0x1000),(LEGACY,LEGACY+0x40),(GENRE_HELP,GENRE_HELP+0x40),(SAVE,SAVE+0xf00),
            (CACHE_HELP,READ),(READ,LOAD),(LOAD,0x41000),(0x1ab50,0x1abac),
            (0x1be50,0x1c17c),(0x17500,0x17790),(0x178bc,0x182ac),(0x19254,0x19448)]
    m=VM(parsed(raw),[(a+delta,b+delta) for a,b in ranges]);common(m)
    if delta:
        m.hooks={a+delta:h for a,h in m.hooks.items()};m.write(0x2f960+delta,0x1234abcd)
    put(m,OBJ,bytes(0x3000));put(m,OUTPUT,bytes(520));put(m,CTX,bytes(16));put(m,DIALOG,bytes(0x100))
    m.hooks[0x231a4+delta]=lambda v:DIALOG
    return m


def conversion(m,language=2,delta=0):
    calls=[]
    m.write(CTX+4,language)
    m.hooks.update({0x24ca4+delta:lambda v:1,
        0x209e0+delta:lambda v:(put(v,v.reg[4],bytes(8)) or v.write(v.reg[4]+4,language) or 0),
        0x209d0+delta:lambda v:0,0x24c44+delta:lambda v:int(bool(v.text(v.reg[5]).strip()))})
    def convert(v):
        cp,flags,src,n=v.reg[4:8];assert flags==8 and 0<n<260
        dest,cap=v.read(v.reg[29]+0x10),v.read(v.reg[29]+0x14)
        calls.append((cp,n,cap,bool(dest)))
        try:text=data(v,src,n).decode('utf-8' if cp==65001 else f'cp{cp}',errors='strict')
        except UnicodeError:return 0
        encoded=text.encode('utf-16-le');units=len(encoded)//2
        if dest:
            assert units<=cap<=199
            put(v,dest,encoded)
        return units
    def lead(v):
        assert v.reg[4]==949;return int(0x81<=v.reg[5]<=0xfe)
    for iat,hook in ((0x2f030,convert),(0x2f108,lead)):
        address=0xf0000000+iat;m.write(iat+delta,address);m.hooks[address]=hook
    return calls


def decoded(raw,payload,encoding,expected,language=2,va=DECODE,delta=0):
    m=machine(raw,delta);calls=conversion(m,language,delta)
    assert len(payload)<=260
    put(m,INPUT,payload+bytes(260-len(payload)))
    m.write(INPUT-4,0xa55aa55a);m.write(INPUT+260,0xa55aa55a)
    put(m,OUTPUT,b'\xa5'*520);m.write(OUTPUT+520,0xa55aa55a)
    assert invoke(m,va+delta,[encoding if encoding is not None else CTX,INPUT,OUTPUT,len(payload)])==OUTPUT
    assert m.text(OUTPUT)==expected,(encoding,payload[:30],m.text(OUTPUT),expected,calls)
    assert m.read(INPUT-4)==m.read(INPUT+260)==m.read(OUTPUT+520)==0xa55aa55a
    assert m.read(OUTPUT+398,2)==0 or len(expected.encode('utf-16-le'))<398
    return m,calls


def encodings(raw):
    cases=0
    samples=['Hello','Café déjà vu','Привет','موسيقى','日本語','한글 노래','😀 test']
    for text in samples:
        for enc,payload in ((1,b'\xff\xfe'+text.encode('utf-16-le')),
                            (1,b'\xfe\xff'+text.encode('utf-16-be')),
                            (2,text.encode('utf-16-be')),(3,text.encode('utf-8')),
                            (3,b'\xef\xbb\xbf'+text.encode('utf-8'))):
            m,_=decoded(raw,payload,enc,text)
            assert m.read(INPUT+259,1)==0x80|enc
            assert m.read(INPUT+257,2)==len(payload)
            cases+=1
    for lang in range(32):
        decoded(raw,b'Caf\xe9',0,'Café',language=lang);cases+=1
    for payload,enc,expected in [
        (b'',3,''),(b'\xff',3,''),(b'\xc0\xaf',3,''),(b'\xed\xa0\x80',3,''),
        (b'\xe2\x82',3,''),(b'\xff\xfe',1,''),(b'A\0',1,''),
        (b'\xff\xfeA',1,''),(b'\xfe\xff\0A\0',1,'A'),
        (b'\xd8\0',2,''),(b'\xdc\0',2,''),(b'\xd8\0\0A',2,''),
        (b'\xd8\0\xdc\0',2,'𐀀'),(b'\0A\0\0\0B',2,'A'),
        (b'\xff\xfe'+b'A\0'*128+b'A',1,'A'*127),
        (b'A'*259,0,'A'*199),
        (b'A'*198+'😀'.encode('utf-8'),3,'A'*198),
        (b'A'*197+'😀'.encode('utf-8'),3,'A'*197+'😀'),
        (b'A'*199+'é'.encode('utf-8'),3,'A'*199),
        (b'A'*256+'é'.encode('utf-8'),3,'A'*199),
        (b'A'*199+b'\xff',3,''),(b'\0A',5,'')]:
        decoded(raw,payload,enc,expected);cases+=1
    for lang,cp,text in ((7,1251,'Привет'),(0,1256,'موسيقى'),(13,932,'日本語'),
                          (2,949,'한글'),(28,949,'한글'),(14,1253,'Μουσική')):
        decoded(raw,text.encode(f'cp{cp}'),None,text,language=lang);cases+=1
    for lang in (0,2,7,13,28,31):
        for payload in (b'\xef\xbb\xbf'+'日本語 😀'.encode('utf-8'),
                        b'\xff\xfe'+'日本語 😀'.encode('utf-16-le'),
                        b'\xfe\xff'+'日本語 😀'.encode('utf-16-be')):
            decoded(raw,payload,None,'日本語 😀',language=lang);cases+=1
    for delta in (0x1000,0x10000,0x123000):
        moved=relocated(raw,delta)
        decoded(moved,'Привет 😀'.encode('utf-8'),3,'Привет 😀',delta=delta);cases+=1
        decoded(moved,b'Caf\xe9',None,'Café',delta=delta);cases+=1
    return dict(cases=cases,api_codepages_are_fixtures=True)


def cached(raw):
    cases=0
    fields=[(0,0x820,4),(0x208,0x924,2),(0x410,0xa28,1),(0x618,0xb2c,16)]
    samples=[(0,b'Caf\xe9','Café'),(1,b'\xff\xfe'+ '日本語'.encode('utf-16-le'),'日本語'),
             (2,'Привет'.encode('utf-16-be'),'Привет'),(3,'موسيقى 😀'.encode('utf-8'),'موسيقى 😀')]
    for lang in (0,2,7,13,28,31):
        for enc,payload,expected in samples:
            m=machine(raw);conversion(m,lang)
            for dst,src,_ in fields:
                put(m,OBJ+src,payload+bytes(260-len(payload)))
                invoke(m,DECODE,[enc,OBJ+src,OBJ+dst,len(payload)])
            m.write(OBJ+0xe40,23);wide(m,OBJ+0xc38,'same.mp3');wide(m,INPUT,'same.mp3')
            m.hooks[0x2597c]=lambda v:0
            invoke(m,0x19254,[OBJ,INPUT,1,1])
            assert all(m.text(OBJ+dst)==expected for dst,_,_ in fields)
            cases+=1
    # A legacy fallback replaces a failed v2 slot and resets cached provenance.
    for lang in (2,7,28):
        m=machine(raw);conversion(m,lang)
        put(m,OBJ+0xa28,b'Old'+bytes(257));m.write(OBJ+0xa28+259,0x83,1)
        legacy=b'Legacy title'+bytes(18);put(m,OBJ+0xa28,legacy)
        invoke(m,LEGACY,[CTX,OBJ+0xa28,OBJ+0x410,30])
        assert m.read(OBJ+0xa28+259,1)==0x84
        m.write(OBJ+0xe40,17);wide(m,OBJ+0x618,'Rock')
        invoke(m,CACHE_HELP,[OBJ])
        assert m.text(OBJ+0x410)=='Legacy title' and m.text(OBJ+0x618)=='Rock'
        cases+=1
    return dict(cases=cases)


def parser(raw):
    cases=0
    def sync(n):return bytes((n>>s)&127 for s in (21,14,7,0))
    fields=[(b'TPE1',b'TP1',0,0x820,4),(b'TALB',b'TAL',0x208,0x924,2),
            (b'TIT2',b'TT2',0x410,0xa28,1),(b'TCON',b'TCO',0x618,0xb2c,16)]
    for version in (2,3,4):
        for encoding,body,text in [(0,b'Caf\xe9','Café'),(1,b'\xff\xfe'+ '日本語'.encode('utf-16-le'),'日本語'),
                                   (2,'Привет'.encode('utf-16-be'),'Привет'),(3,'موسيقى'.encode('utf-8'),'موسيقى')]:
            for name,name2,dst,src,flag in fields:
                payload=bytes([encoding])+body
                frame=(name2+len(payload).to_bytes(3,'big') if version==2 else
                       name+(sync(len(payload)) if version==4 else len(payload).to_bytes(4,'big'))+b'\0\0')+payload
                tag=b'ID3'+bytes([version,0,0])+sync(len(frame))+frame
                m=machine(raw);conversion(m);put(m,INPUT,tag)
                m.hooks.update({0x177c0:lambda v:len(tag),0x2539c:lambda v:0,
                    0x2538c:lambda v:(put(v,CTX+0x1000,bytes(v.reg[4])) or CTX+0x1000)})
                assert invoke(m,0x178bc,[OBJ,INPUT,OBJ,len(tag)]) in (0,1)
                assert m.text(OBJ+dst)==text,(version,name,encoding,m.text(OBJ+dst))
                assert m.read(OBJ+0xe40)&flag
                assert m.read(OBJ+src+259,1)==encoding|128
                invoke(m,CACHE_HELP,[OBJ]);assert m.text(OBJ+dst)==text
                cases+=1
    # Actual ID3v1 fallback over stale v2 provenance; table-based genre survives.
    for language in (2,7,28):
        tag=bytearray(128);tag[:3]=b'TAG';tag[3:15]=b'Legacy title'
        tag[33:46]=b'Legacy artist';tag[63:75]=b'Legacy album';tag[127]=17
        m=machine(raw);conversion(m,language);put(m,INPUT,tag)
        for _,_,_,src,_ in fields:m.write(OBJ+src+259,0x83,1)
        invoke(m,0x17500,[OBJ,INPUT,OBJ])
        assert [m.text(OBJ+off) for off in (0,0x208,0x410,0x618)]==[
            'Legacy artist','Legacy album','Legacy title','Rock']
        # V1 genre had no raw bytes; the stale marker must be cleared as well.
        invoke(m,CACHE_HELP,[OBJ])
        assert [m.text(OBJ+off) for off in (0,0x208,0x410,0x618)]==[
            'Legacy artist','Legacy album','Legacy title','Rock']
        cases+=1
    return dict(cases=cases)


def prior_frames(raw):
    # Reuse the immutable prior boundary corpus, changing only the inventoried
    # converter call target. Decoder semantics are exercised separately above.
    import verify_usb_input_safety as prior
    code=inspect.getsource(prior.id3).replace('def id3(', 'def framed(')
    code=code.replace('m.hooks[0x24e04]=convert','m.hooks[DECODE]=convert')
    scope=dict(vars(prior),DECODE=DECODE);exec(code,scope)
    result=scope['framed'](raw);result.pop('encoding_selection_unchanged')
    return result


def blob(title,position):
    b=bytearray(3180);struct.pack_into('<I',b,4,position)
    for off,text in ((0x1c,'song.mp3'),(0x224,'\\MD\\song.mp3'),(0x42c,title),
                     (0x634,'Album'),(0x83c,'Artist'),(0xa44,'\\MD')):
        encoded=(text+'\0').encode('utf-16-le');b[off:off+len(encoded)]=encoded
    b[0]=sum(b[1:])%256;return bytes(b)


class PowerCut(Exception):pass


class Files:
    def __init__(self,files=None,fault=None,cut=None):
        self.files=dict(files or {});self.fault=fault;self.cut=cut
        self.events=[];self.handles={};self.last=0;self.next=0x5500;self.owned=False
    def event(self,op,path=''):
        self.events.append((op,path))
        if self.cut==len(self.events):raise PowerCut()
    def bind(self,m,delta=0):
        def opened(v):
            path=v.text(v.reg[4]);access,share,security=v.reg[5:8]
            disposition=v.read(v.reg[29]+0x10)
            assert security==0 and v.read(v.reg[29]+0x14)==0x80 and v.read(v.reg[29]+0x18)==0
            if access==0x40000000:
                assert path.endswith('.new') and share==0 and disposition==2
                if self.fault=='open_write':self.last=5;self.event('open_fail',path);return 0xffffffff
                self.files[path]=b''
            else:
                assert access==0x80000000 and share==1 and disposition==3
                if self.fault=='primary_access' and path==PATH:
                    self.last=5;self.event('open_fail',path);return 0xffffffff
                if path not in self.files:self.last=2;self.event('open_missing',path);return 0xffffffff
            handle=self.next;self.next+=1;self.handles[handle]=(path,access)
            self.event('open',path);return handle
        def write(v):
            path,access=self.handles[v.reg[4]];assert access==0x40000000 and v.reg[6]==3180
            assert v.read(v.reg[7])==0 and v.read(v.reg[29]+0x10)==0
            b=data(v,v.reg[5],3180);assert b[0]==sum(b[1:])%256
            n={'short_write':3179,'zero_write':0,'overcount':3181}.get(self.fault,3180)
            self.files[path]=b[:min(n,3180)];v.write(v.reg[7],n)
            self.event('write',path);return 0 if self.fault=='write_false' else 2
        def flush(v):
            path,access=self.handles[v.reg[4]];assert access==0x40000000
            self.event('flush',path);return 0 if self.fault=='flush' else 2
        def close(v):
            if v.reg[4]==0x7777:
                self.event('close_mutex');return 0 if self.fault=='close_mutex' else 2
            path,access=self.handles.pop(v.reg[4]);self.event('close',path)
            second=sum(op=='close' and p==path for op,p in self.events)==2
            return 0 if (self.fault==('close_write' if access==0x40000000 else 'close_read') or
                         self.fault=='native_close' and second) else 2
        def size(v):
            path,_=self.handles[v.reg[4]];assert v.read(v.reg[5])==0
            self.event('size',path)
            if self.fault=='size_high' and path.endswith('.new'):v.write(v.reg[5],1)
            return 0xffffffff if self.fault=='size_api' and path.endswith('.new') else len(self.files[path])
        def read(v):
            path,_=self.handles[v.reg[4]];assert v.reg[6]==3180 and v.read(v.reg[7])==0
            b=self.files[path]
            if path.endswith('.new') and self.fault=='corrupt_read':
                b=bytearray(b);b[4]=(b[4]+1)&255;b[5]=(b[5]-1)&255;b=bytes(b)
                assert b[0]==sum(b[1:])%256,'Preserve weak checksum to test exact compare'
            n=3179 if self.fault=='short_read' and path.endswith('.new') else min(len(b),3180)
            put(v,v.reg[5],b[:n]);v.write(v.reg[7],n);self.event('read',path)
            return 0 if self.fault=='read_false' and path.endswith('.new') else 2
        def delete(v):
            path=v.text(v.reg[4]);assert self.owned
            if self.fault=='delete_backup' and path.endswith('.bak'):
                self.last=5;self.event('delete_fail',path);return 0
            if path not in self.files:self.last=2;self.event('delete_missing',path);return 0
            del self.files[path];self.event('delete',path);return 2
        def move(v):
            src,dst=v.text(v.reg[4]),v.text(v.reg[5]);assert self.owned
            if self.fault==('publish' if src.endswith('.new') else 'rotate'):
                self.last=5;self.event('move_fail',src);return 0
            assert src in self.files and dst not in self.files
            self.files[dst]=self.files.pop(src);self.event('move',src);return 2
        def mutex(v):
            assert v.reg[4:6]==[0,0] and v.text(v.reg[6])=='MediaNavMAX_USBResume'
            self.event('mutex');return 0 if self.fault=='mutex' else 0x7777
        def wait(v):
            assert v.reg[4:6]==[0x7777,0]
            self.owned=self.fault not in ('timeout','wait_failed')
            self.event('wait')
            return {'timeout':258,'wait_failed':0xffffffff,'abandoned':128}.get(self.fault,0)
        def release(v):
            assert v.reg[4]==0x7777 and self.owned;self.owned=False
            self.event('release');return 0 if self.fault=='release' else 2
        for at,hook in ((0x2f034,opened),(0x2f098,write),(0x2f038,close),(0x2f058,read),
                         (0x2f064,size),(EXTRA_IAT,flush),(EXTRA_IAT+4,move),(EXTRA_IAT+8,delete),
                         (0x2f0cc,mutex),(0x2f048,wait),(0x2f0c4,release),(0x2f020,lambda v:self.last)):
            address=0xf0000000+at;m.write(at+delta,address);m.hooks[address]=hook
        def attrs(v):
            if self.fault=='attributes':return 0
            v.write(v.reg[6],2 if self.fault=='hidden' else 0x80);return 2
        for at,hook in ((0x2f094,attrs),(0x2f05c,lambda v:0xffffffff if self.fault=='folder' else 0x10)):
            address=0xf0000000+at;m.write(at+delta,address);m.hooks[address]=hook


def saving(raw,fs,current,delta=0):
    m=machine(raw,delta);wide(m,INPUT,PATH);put(m,OBJ+0xe64,current);fs.bind(m,delta)
    answer=invoke(m,SAVE+delta,[OBJ,INPUT])
    assert data(m,OBJ+0xe64,3180)==current,'Snapshot must not modify live state'
    assert not fs.handles and not fs.owned
    return answer,m


def loading(raw,fs,delta=0):
    m=machine(raw,delta);wide(m,INPUT,PATH);put(m,OBJ+0xe64,b'\xa5'*3180);fs.bind(m,delta)
    answer=invoke(m,LOAD+delta,[OBJ,INPUT])
    assert not fs.handles and not fs.owned
    saved=data(m,OBJ+0xe64,3180)
    if not answer:assert saved==bytes(3180),'Failed load must clear stale state'
    return answer,saved


def persistence(raw):
    old,new,older=blob('Old',10),blob('New',20),blob('Older',5);cases=0
    success=Files({PATH:old,PATH+'.bak':older});assert saving(raw,success,new)[0]==1
    assert success.files=={PATH:new,PATH+'.bak':old}
    assert loading(raw,Files(success.files))==(1,new);cases+=1
    for initial in ({},{PATH+'.bak':old},{PATH:b'broken',PATH+'.bak':old}):
        fs=Files(initial);assert saving(raw,fs,new)[0]==1 and fs.files[PATH]==new
        if PATH+'.bak' in initial:assert fs.files[PATH+'.bak']==old
        cases+=1
    for fault in ('open_write','write_false','short_write','zero_write','overcount','flush','close_write',
                  'size_high','size_api','short_read','read_false','corrupt_read','close_read',
                  'delete_backup','rotate','publish','mutex','timeout','wait_failed','primary_access'):
        fs=Files({PATH:old,PATH+'.bak':older},fault=fault)
        assert saving(raw,fs,new)[0]==0,fault
        assert old in (fs.files.get(PATH),fs.files.get(PATH+'.bak')),fault
        assert loading(raw,Files(fs.files))==(1,old),fault
        cases+=1
    for fault in ('abandoned','release','close_mutex'):
        fs=Files({PATH:old},fault=fault);answer,_=saving(raw,fs,new)
        assert answer==int(fault=='abandoned') and fs.files[PATH]==new
        assert loading(raw,Files(fs.files))==(1,new);cases+=1
    for malformed in (b'',old[:-1],old+b'\0',bytes(3180),bytes([old[0]^1])+old[1:]):
        fs=Files({PATH:malformed,PATH+'.bak':old});assert loading(raw,fs)==(1,old);cases+=1
        fs=Files({PATH:malformed});assert saving(raw,fs,new)[0]==0 and fs.files[PATH]==malformed
        assert loading(raw,Files(fs.files))[0]==0;cases+=1
    assert loading(raw,Files({PATH+'.new':new}))[0]==0;cases+=1
    for fault in ('close_read','native_close','attributes','hidden','folder','mutex','timeout',
                  'wait_failed','release','close_mutex','primary_access'):
        assert loading(raw,Files({PATH:old},fault=fault))[0]==0,fault
        cases+=1
    for name in ('','x'*255,'x'*260):
        for va in (SAVE,LOAD):
            m=machine(raw);wide(m,INPUT,name);put(m,OBJ+0xe64,new)
            fs=Files({PATH:old});fs.bind(m)
            assert invoke(m,va,[OBJ,INPUT])==0 and fs.events==[] and fs.files=={PATH:old}
            cases+=1
    for initial in ({PATH:old,PATH+'.bak':older},{PATH+'.bak':old},{PATH:b'broken',PATH+'.bak':old}):
        baseline=Files(initial);assert saving(raw,baseline,new)[0]==1
        for cut in range(1,len(baseline.events)+1):
            fs=Files(initial,cut=cut)
            try:saving(raw,fs,new)
            except PowerCut:pass
            else:raise AssertionError('Cut not reached')
            answer,recovered=loading(raw,Files(fs.files))
            assert answer==1 and recovered in (old,new),(cut,baseline.events[cut-1],fs.files.keys())
            cases+=1
    for delta in (0x1000,0x10000,0x123000):
        moved=relocated(raw,delta);fs=Files({PATH:old});assert saving(moved,fs,new,delta)[0]==1
        assert loading(moved,Files(fs.files),delta)==(1,new);cases+=1
    return dict(cases=cases,api_boundary_interruptions=True,physical_power_cut_tested=False)


def layout(raw,recipe):
    p=parsed(raw);assert p.FILE_HEADER.NumberOfSections==7
    old=parsed(SOURCE.read_bytes())
    assert p.OPTIONAL_HEADER.AddressOfEntryPoint==old.OPTIONAL_HEADER.AddressOfEntryPoint
    assert p.OPTIONAL_HEADER.SizeOfHeaders==old.OPTIONAL_HEADER.SizeOfHeaders
    new=[d for d in p.DIRECTORY_ENTRY_IMPORT if d.struct.FirstThunk==EXTRA_IAT-0x10000]
    assert len(new)==1 and [i.ordinal for i in new[0].imports]==[175,163,165]
    rom=parsed((ROOT/'extracted/705md-rom/fs/Windows/coredll.dll').read_bytes())
    exports={s.ordinal:s.name for s in rom.DIRECTORY_ENTRY_EXPORT.symbols}
    assert [exports[o] for o in (175,163,165)]==[b'FlushFileBuffers',b'MoveFileW',b'DeleteFileW']
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=p.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    assert rows==sorted(rows) and all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    for address in (DECODE,LEGACY,SAVE,READ,LOAD,CACHE_HELP,GENRE_HELP):
        assert any(row[0]==address for row in rows)
    for delta in (0x1000,0x10000,0x123000):
        r=parsed(relocated(raw,delta));d=r.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        moved=[struct.unpack_from('<5I',r.get_data(d.VirtualAddress,d.Size),i) for i in range(0,d.Size,20)]
        assert moved==[tuple(n+delta if n else 0 for n in row) for row in rows]
    # Exact original body/data/sections retained after undoing reviewed code edits.
    restored=bytearray(raw[:len(SOURCE.read_bytes())])
    for e in recipe['edits']:
        at=int(e['offset'],16);restored[at:at+e['bytes']]=bytes.fromhex(e['before_hex'])
    for section in old.sections:
        a=section.PointerToRawData;b=a+section.SizeOfRawData
        assert restored[a:b]==SOURCE.read_bytes()[a:b]
    return dict(sections=7,added_import_ordinals=[175,163,165],added_pdata_rows=recipe['added_pdata_rows'],
                old_section_bytes_restored=True,rom_sha256=hashlib.sha256((ROOT/'extracted/705md-rom/fs/Windows/coredll.dll').read_bytes()).hexdigest())


def verify(raw,recipe):
    checks={}
    for name,fn in [('encodings',encodings),('cached',cached),('id3_parser',parser),
                    ('persistence',persistence),('previous_frames',prior_frames),
                    ('previous_paths',paths),('previous_metadata',metadata),
                    ('previous_playlists',playlists),('previous_relocations',relocations)]:
        checks[name]=fn(raw);print(name,json.dumps(checks[name]),flush=True)
    checks['layout']=layout(raw,recipe)
    checks['previous_resume']=verify_usb((ROOT/'extracted/705md/upgrade/Storage Card/System/MgrUSB.exe').read_bytes(),raw)
    return checks


if __name__=='__main__':
    raw,recipe=patch(SOURCE.read_bytes());checks=verify(raw,recipe)
    proof=dict(recipe=recipe,checks=checks,native_executed=False,hardware_tested=False)
    (ROOT/'analysis/firmware/usb-reliability-development.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(checks,indent=2))
