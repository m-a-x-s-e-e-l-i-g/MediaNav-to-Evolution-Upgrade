"""Written MIPS bytes with bounded media/CRT/GDI fixtures. Not native CE."""
import hashlib
import inspect
import json
import random
import struct
from pathlib import Path
from patch_artwork_playlist import patch,ART,PIXELS,LINE,EOF_IAT,ERROR_IAT
from verify_usb_reliability import machine,invoke,conversion,OBJ,INPUT,CTX,DIALOG,STACK,STOP
from verify_media_responsiveness import VM,parsed
from verify_usb_input_safety import common,wide,relocated
from inspect_bt_pairing import put,data

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'build/usb-reliability-development-01/payload/upgrade/Storage Card/System/MgrUSB.exe'
POOL,FACTORY,IMAGE,VTABLE,BITS=0x46000000,0x47000000,0x48000000,0x49000000,0x4a000000


def vm(raw,delta=0):
    m=machine(raw,delta)
    m.ranges.extend((a+delta,b+delta) for a,b in [(ART,ART+0x800),(PIXELS,PIXELS+0x600),
                    (LINE,LINE+0x800),(0x1a318,0x1a60c),(0x15c00,0x15df4),
                    (0x165e8,0x1685c),(0x16910,0x16c80),(0x161b4,0x16340),
                    (0x16340,0x1640c),(0x16150,0x1618c),(0x1618c,0x161b4),(0x1271c,0x12768)])
    return m


def call_art(m,payload,version=4,capacity=None,destination=POOL):
    put(m,INPUT,payload);m.write(INPUT-4,0xa55aa55a);m.write(INPUT+len(payload),0xa55aa55a)
    put(m,POOL,b'\xa5'*max(64,len(payload)));m.write(POOL-4,0xa55aa55a)
    m.write(POOL+max(64,len(payload)),0xa55aa55a)
    copied=[]
    def copy(v):
        dest,src,n=v.reg[4:7]
        assert dest==POOL and INPUT<=src<=INPUT+len(payload) and src+n<=INPUT+len(payload)
        assert n<=0x800000;copied.append(data(v,src,n));put(v,dest,copied[-1]);return dest
    m.hooks[0x25668]=copy
    # Helper's fifth argument is at the standard MIPS stack home slot.
    m.write(STACK+0x10,destination)
    answer=invoke(m,ART,[OBJ,INPUT,len(payload) if capacity is None else capacity,version])
    assert m.read(INPUT-4)==m.read(INPUT+len(payload))==m.read(POOL-4)==m.read(POOL+max(64,len(payload)))==0xa55aa55a
    return answer,copied


def cover_payload(version,encoding,mime='image/jpeg',description='',image=b'\xff\xd8image',ptype=3):
    desc=(description.encode('utf-16-be')+b'\0\0' if encoding==2 else
          b'\xff\xfe'+description.encode('utf-16-le')+b'\0\0' if encoding==1 else
          description.encode('utf-8' if encoding==3 else 'latin1')+b'\0')
    format=(mime.encode('ascii')+b'\0') if version!=2 else mime.encode('ascii')
    return bytes([encoding])+format+bytes([ptype])+desc+image


def artwork(raw):
    cases=0
    for version,formats in ((2, [('JPG',16),('PNG',23),('BMP',21),('GIF',22),('XYZ',0)]),
                            (3,[('image/jpg',16),('image/jpeg',18),('image/png',23),('image/bmp',21),('image/gif',22),('image/x',0)]),
                            (4,[('image/jpeg',18),('IMAGE/PNG',23),('image/webp',0)])):
        for encoding in range(4):
            for mime,fmt in formats:
                for desc in ('','Front cover'):
                    b=cover_payload(version,encoding,mime,desc);m=vm(raw)
                    answer,copies=call_art(m,b,version)
                    assert answer==1 and copies==[b'\xff\xd8image'],(version,encoding,mime,desc,copies)
                    assert m.read(OBJ+0xc30)==fmt and m.read(OBJ+0xc34)==7 and m.read(OBJ+0xe40)&8
                    cases+=1
    # Unicode descriptions, an aligned UTF16 terminator, and ordinary malformed prefixes.
    for enc in (1,2,3):
        m=vm(raw);b=cover_payload(4,enc,description='日本語 😀')
        assert call_art(m,b)==(1,[b'\xff\xd8image']);cases+=1
    good=cover_payload(4,0)
    for b in [b'',b'\0',b'\0image/jpeg',b'\0image/jpeg\0',b'\0image/jpeg\0\x03',
              b'\0image/jpeg\0\x03unterminated',b'\4image/jpeg\0\x03\0img',
              b'\0-->\0\3\0http://url',b'\0wrong/jpeg\0\3\0img',
              b'\1image/jpeg\0\3\0',b'\2image/jpeg\0\3\0A\0',
              b'\0image/jpeg\0\x15\0img',good[:-7]]:
        m=vm(raw);m.write(OBJ+0xc34,99);m.write(OBJ+0xe40,8)
        assert call_art(m,b)==(0,[]);assert m.read(OBJ+0xc34)==99 and m.read(OBJ+0xe40)==8
        cases+=1
    for cut in range(len(good)-7):
        m=vm(raw);assert call_art(m,good[:cut])==(0,[]);cases+=1
    m=vm(raw);assert call_art(m,good,destination=0)==(0,[]);cases+=1
    m=vm(raw);assert call_art(m,cover_payload(2,0,'-->'),2)==(0,[]);cases+=1
    # The size gate is exercised before any read of the declared oversized image.
    m=vm(raw);assert call_art(m,good,capacity=0x800000+len(good)-7+1)==(0,[]);cases+=1
    # Actual ID3 parser dispatch and a following text frame share the same tag.
    def sync(n):return bytes((n>>s)&127 for s in (21,14,7,0))
    for version in (2,3,4):
        for encoding in range(4):
            b=cover_payload(version,encoding,'PNG' if version==2 else 'image/png','Description')
            frames=[]
            for ident,payload in [(b'PIC' if version==2 else b'APIC',b),
                                  (b'TT2' if version==2 else b'TIT2',b'\3Title')]:
                frames.append((ident+len(payload).to_bytes(3,'big') if version==2 else
                               ident+(sync(len(payload)) if version==4 else len(payload).to_bytes(4,'big'))+b'\0\0')+payload)
            body=b''.join(frames);tag=b'ID3'+bytes([version,0,0])+sync(len(body))+body
            m=vm(raw);conversion(m);put(m,INPUT,tag);put(m,POOL,bytes(64));m.write(OBJ+0xe44,POOL)
            m.hooks.update({0x177c0:lambda v:len(tag),0x2539c:lambda v:0})
            assert invoke(m,0x178bc,[OBJ,INPUT,OBJ,len(tag)]) in (0,1)
            assert m.read(OBJ+0xc34)==7 and data(m,POOL,7)==b'\xff\xd8image'
            assert m.read(OBJ+0xe40)&8 and m.text(OBJ+0x410)=='Title'
            cases+=1
    return dict(cases=cases)


def pixel_fixture(width,height):
    stride=(width*3+3)&~3;b=bytearray(b'\xa5'*(stride*height));expected=b.copy();changed=0
    colors=[(8,0,0),(15,3,7),(7,0,0),(16,0,0),(10,4,0),(10,0,8),(255,255,255)]
    for y in range(height):
        for x in range(width):
            color=colors[(x+3*y)%len(colors)];at=y*stride+x*3;b[at:at+3]=bytes(color)
            expected[at:at+3]=bytes(3) if 8<=color[0]<16 and color[1]<4 and color[2]<8 else bytes(color)
            changed+=int(expected[at:at+3]!=bytes(color))
    return bytes(b),bytes(expected),changed


def pixels(raw):
    cases=0
    for w in [*range(1,33),63,64,127,128,277,278,279,280,479,480,799,800]:
        for h in (1,2,3):
            b,expected,n=pixel_fixture(w,h);m=vm(raw)
            put(m,BITS,b);m.write(BITS-4,0xa55aa55a);m.write(BITS+len(b),0xa55aa55a)
            assert invoke(m,PIXELS,[BITS,w,h])==n
            assert data(m,BITS,len(b))==expected
            assert m.read(BITS-4)==m.read(BITS+len(b))==0xa55aa55a;cases+=1
    for w,h,p in ((0,2,BITS),(2,0,BITS),(0xffffffff,2,BITS),(2,0xffffffff,BITS),(2,2,0)):
        m=vm(raw);assert invoke(m,PIXELS,[p,w,h])==0;cases+=1
    # Compare the original exact loop with the replacement where old stride was valid.
    old=SOURCE.read_bytes();stats={}
    for label,binary in [('before',old),('after',raw)]:
        b,expected,n=pixel_fixture(278,3);m=VM(parsed(binary),[(0x1a4ac,0x1a540),(PIXELS,PIXELS+0x600)])
        common(m);put(m,BITS,b);m.reg[29]=STACK
        m.write(STACK+0x20,BITS);m.write(STACK+0x2c,278);m.write(STACK+0x30,3)
        memset_calls=[]
        def zero(v):memset_calls.append(v.reg[6]);put(v,v.reg[4],bytes(v.reg[6]));return v.reg[4]
        m.hooks[0x253dc]=zero;m.run(0x1a4ac,{0x1a540},limit=60000)
        assert data(m,BITS,len(b))==expected
        stats[label]=dict(instructions=m.steps,pixel_memset_calls=len(memset_calls))
    assert stats['after']['instructions']<stats['before']['instructions']
    assert stats['after']['pixel_memset_calls']==0
    return dict(cases=cases,comparison_278x3=stats,native_timing_measured=False)


class Stream:
    def __init__(self,contents):
        self.contents=contents;self.position=0;self.calls=0;self.error=False;self.eof=False;self.fail_at=None
    def fgets(self,m):
        dest,cap,handle=m.reg[4:7];assert handle==0x5555 and 2<=cap<=260
        self.calls+=1
        if self.calls==self.fail_at:self.error=True;return 0
        if self.position==len(self.contents):self.eof=True;return 0
        limit=min(len(self.contents),self.position+cap-1)
        newline=self.contents.find(b'\n',self.position,limit)
        if newline>=0:limit=newline+1
        b=self.contents[self.position:limit];self.position=limit
        put(m,dest,b+b'\0');return dest


def attach_stream(m,contents,delta=0):
    s=Stream(contents);m.hooks[0x258fc+delta]=s.fgets;m.write(OBJ+4,0x5555);m.write(OBJ+8,1)
    for at,hook in ((EOF_IAT,lambda v:2 if s.eof else 0),(ERROR_IAT,lambda v:2 if s.error else 0)):
        address=0xf1000000+at;m.write(at+delta,address);m.hooks[address]=hook
    return s


def readlines(raw,contents,capacity=260,delta=0):
    m=vm(raw,delta);s=attach_stream(m,contents,delta)
    lines=[];put(m,INPUT,b'\xa5'*capacity);m.write(INPUT-4,0xa55aa55a);m.write(INPUT+capacity,0xa55aa55a)
    while invoke(m,LINE+delta,[OBJ,INPUT,capacity]):
        b=bytes(m.read(INPUT+i,1) for i in range(capacity));lines.append(b.split(b'\0',1)[0])
        assert len(lines)<100
    assert m.read(INPUT,1)==0 and s.position==len(contents)
    assert m.read(INPUT-4)==m.read(INPUT+capacity)==0xa55aa55a
    return lines,s.calls


def lines(raw):
    cases=0
    for contents,expected in [(b'',[]),(b'a.mp3',[b'a.mp3']),(b'a.mp3\n',[b'a.mp3']),
                              (b'a.mp3\r\nb.wma\n',[b'a.mp3',b'b.wma']),
                              (b'\n\r\n',[b'',b'']),(b'\xef\xbb\xbf#EXTM3U\na.mp3\n',[b'#EXTM3U',b'a.mp3']),
                              ('\ufeff日.mp3\n'.encode('utf-8'),['日.mp3'.encode('utf-8')])]:
        assert readlines(raw,contents)[0]==expected;cases+=1
    for length in (257,258,259,260,261,262,518,519,520,777,4096):
        for ending in (b'',b'\n',b'\r\n'):
            content=b'x'*length+ending
            expected=[b'x'*length] if length<=259 else []
            if ending:content+=b'song.mp3\n';expected+=[b'song.mp3']
            assert readlines(raw,content)[0]==expected,(length,ending,readlines(raw,content))
            cases+=1
    for cap in (2,3,4,32,128,260):
        for length in (cap-2,cap-1,cap,cap*3):
            expected=[b'x'*length] if 0<length<cap else []
            assert readlines(raw,b'x'*length,cap)[0]==expected;cases+=1
    for cap in (0,1,261,0xffffffff):
        m=vm(raw);put(m,INPUT,b'\xa5'*260);s=attach_stream(m,b'song.mp3\n')
        assert invoke(m,LINE,[OBJ,INPUT,cap])==0 and s.calls==0;cases+=1
    for content in (b'x'*259,b'x'*300+b'\n'):
        m=vm(raw);s=attach_stream(m,content);s.fail_at=2;put(m,INPUT,bytes(260))
        assert invoke(m,LINE,[OBJ,INPUT,260])==0 and m.read(INPUT,1)==0 and s.error
        cases+=1
    for delta in (0x1000,0x10000,0x123000):
        moved=relocated(raw,delta)
        assert readlines(moved,b'x'*300+b'\n\xef\xbb\xbfok.mp3\n',delta=delta)[0]==[b'ok.mp3'];cases+=1
    return dict(cases=cases,utf8_bom_removed=True,oversized_lines_skipped=True)


def readers(raw):
    cases=0
    for start,format_line in [(0x15c00,lambda p:p),(0x165e8,lambda p:'File1='+p),
                              (0x16910,lambda p:'<media src="'+p+'" />')]:
        for prefix in (b'',b'\xef\xbb\xbf'):
            m=vm(raw);conversion(m);wide(m,CTX,'MD')
            contents=prefix+format_line('one.mp3').encode()+b'\n'+b'x'*259+format_line('fake.mp3').encode()+b'\n'+format_line('日.wma').encode()+b'\n'
            stream=attach_stream(m,contents);put(m,STACK-0x1000,bytes(0x1000));put(m,0x2fefc,bytes(520))
            added=[]
            def ncopy(v):
                units=[]
                for i in range(v.reg[6]):
                    ch=v.read(v.reg[5]+2*i,2);units.append(ch)
                    if not ch:units.extend([0]*(v.reg[6]-len(units)));break
                put(v,v.reg[4],b''.join(ch.to_bytes(2,'little') for ch in units));return v.reg[4]
            m.hooks.update({0x25568:lambda v:len(bytes(v.read(v.reg[4]+i,1) for i in range(260)).split(b'\0',1)[0]),
                           0x16104:lambda v:(added.append(v.text(v.reg[5])) or 1),
                           0x25558:ncopy,0x2593c:lambda v:int(v.text(v.reg[4])[:v.reg[6]].lower()!=v.text(v.reg[5])[:v.reg[6]].lower()),
                           0x25588:lambda v:0,
                           0x25578:lambda v:(wide(v,v.reg[4],v.text(v.reg[6])) or 0),
                           0x255b8:lambda v:int(v.text(v.reg[4]).lower()!=v.text(v.reg[5]).lower())})
            m.write(0x2f05c,0xf1000000);m.hooks[0xf1000000]=lambda v:0x80
            invoke(m,start,[OBJ,CTX],limit=120000)
            assert added==['\\MD\\one.mp3','\\MD\\日.wma'],(hex(start),added)
            assert stream.position==len(contents);cases+=1
    return dict(cases=cases,readers=['M3U','PLS','WPL'])


def renderer(raw):
    cases=0
    for length in (7,0,0x800001):
        m=vm(raw);m.write(OBJ+0xc38,length);m.write(OBJ+0xe48,POOL)
        put(m,FACTORY,bytes(16));put(m,IMAGE,bytes(16));put(m,VTABLE,bytes(0x80))
        m.write(FACTORY,VTABLE);m.write(IMAGE,VTABLE+0x40)
        m.write(DIALOG+0x7c,5);m.write(DIALOG+0x80,3)
        events=[]
        def create(v):v.write(v.read(v.reg[29]+0x10),FACTORY);return 0
        m.write(0x2f1e0,0xf1000010);m.hooks[0xf1000010]=create
        def image(v):
            assert v.reg[4:8]==[FACTORY,POOL,length,0]
            v.write(v.read(v.reg[29]+0x10),IMAGE);events.append(('image_length',length));return 0
        m.write(VTABLE+0x14,0xf1000020);m.hooks[0xf1000020]=image
        m.write(VTABLE+8,0xf1000030);m.write(VTABLE+0x48,0xf1000030)
        m.hooks[0xf1000030]=lambda v:0
        m.write(VTABLE+0x50,0xf1000040);m.hooks[0xf1000040]=lambda v:0
        m.write(VTABLE+0x58,0xf1000050);m.hooks[0xf1000050]=lambda v:0
        b,expected,n=pixel_fixture(5,3)
        def dib(v):
            assert v.read(v.reg[5]+4)==5 and v.read(v.reg[5]+8)==3
            put(v,BITS,b);v.write(v.reg[7],BITS);return 0x8888
        for at,hook in [(0x251cc,lambda v:0x6666),(0x251bc,dib),(0x251ac,lambda v:0x7777),
                        (0x2519c,lambda v:1),(0x2518c,lambda v:1),(0x2516c,lambda v:1),
                        (0x23580,lambda v:0)]:m.hooks[at]=hook
        copies=[]
        def copy(v):copies.append(v.reg[6]);put(v,v.reg[4],data(v,v.reg[5],v.reg[6]));return v.reg[4]
        m.hooks[0x25668]=copy
        invoke(m,0x1a318,[OBJ],limit=100000)
        assert copies==[],'Redundant whole metadata copy must be gone'
        assert events==([('image_length',length)] if 0<length<=0x800000 else [])
        if length==7:assert data(m,BITS,len(b))==expected
        cases+=1
    return dict(cases=cases,metadata_bytes_not_copied_per_call=3652)


def structure(raw,recipe):
    p=parsed(raw);old=parsed(SOURCE.read_bytes())
    assert p.FILE_HEADER.NumberOfSections==old.FILE_HEADER.NumberOfSections==7
    assert len(raw)==len(SOURCE.read_bytes())
    assert p.OPTIONAL_HEADER.AddressOfEntryPoint==old.OPTIONAL_HEADER.AddressOfEntryPoint
    assert [s.__pack__() for s in p.sections]==[s.__pack__() for s in old.sections]
    oldimports=[(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in old.DIRECTORY_ENTRY_IMPORT]
    newimports=[(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in p.DIRECTORY_ENTRY_IMPORT]
    assert newimports[:-1]==oldimports[:-1]
    assert newimports[-1]==(oldimports[-1][0],oldimports[-1][1]+[(None,1125),(None,1126)])
    rom=parsed((ROOT/'extracted/705md-rom/fs/Windows/coredll.dll').read_bytes())
    exports={s.ordinal:s.name for s in rom.DIRECTORY_ENTRY_EXPORT.symbols}
    assert exports[1125]==b'feof' and exports[1126]==b'ferror'
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];table=p.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',table,i) for i in range(0,len(table),20)]
    assert rows==sorted(rows) and all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    prior=json.loads((ROOT/'build/usb-reliability-development-01/manifest.json').read_text())
    for routine in prior['recipe']['routines']:
        va=int(routine['start'],16);n=routine['used_bytes']
        assert p.get_data(va-0x10000,n)==old.get_data(va-0x10000,n)
    for delta in (0x1000,0x10000,0x123000):
        q=parsed(relocated(raw,delta));qd=q.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        moved=[struct.unpack_from('<5I',q.get_data(qd.VirtualAddress,qd.Size),i) for i in range(0,qd.Size,20)]
        assert moved==[tuple(n+delta if n else 0 for n in row) for row in rows]
        m=vm(relocated(raw,delta),delta);put(m,BITS,b'\x08\0\0\xa5')
        assert invoke(m,PIXELS+delta,[BITS,1,1])==1 and data(m,BITS,4)==b'\0\0\0\xa5'
    restored=bytearray(raw)
    for e in recipe['edits']:
        off=int(e['offset'],16);assert restored[off:off+e['bytes']].hex()==e['after_hex']
        restored[off:off+e['bytes']]=bytes.fromhex(e['before_hex'])
    for index in (3,5):
        d=p.OPTIONAL_HEADER.DATA_DIRECTORY[index]
        struct.pack_into('<I',restored,d.get_file_offset()+4,old.OPTIONAL_HEADER.DATA_DIRECTORY[index].Size)
    assert bytes(restored)==SOURCE.read_bytes()
    return dict(sections_unchanged=True,old_helper_bytes_unchanged=True,exact_input_restored=True,
                added_pdata_rows=3,added_imports=['COREDLL!feof@1125','COREDLL!ferror@1126'],relocated_bases=3)


def regressions(raw):
    import verify_usb_reliability as previous
    import verify_usb_input_safety as inputs
    checks={}
    for name,fn in [('encodings',previous.encodings),('cached',previous.cached),('id3_parser',previous.parser),
                    ('persistence',previous.persistence),('previous_frames',previous.prior_frames),
                    ('previous_paths',inputs.paths),('previous_metadata',inputs.metadata),
                    ('previous_relocations',inputs.relocations)]:
        checks[name]=fn(raw);print('retained',name,flush=True)
    # Existing parser/input cases retain their reader fixture, at the inventoried
    # new call target. Whole-stream LINE behavior is covered by our six readers.
    code=inspect.getsource(inputs.playlists).replace('def playlists(', 'def prior_readers(')
    code=code.replace('0x15e4c:line','LINE:line');scope=dict(vars(inputs),LINE=LINE);exec(code,scope)
    checks['previous_playlists']=scope['prior_readers'](raw)
    checks['previous_resume']=previous.verify_usb((ROOT/'extracted/705md/upgrade/Storage Card/System/MgrUSB.exe').read_bytes(),raw)
    return checks


def verify(raw):
    checks={}
    for name,fn in [('artwork',artwork),('pixels',pixels),('lines',lines),('readers',readers),('renderer',renderer)]:
        checks[name]=fn(raw);print(name,json.dumps(checks[name]),flush=True)
    return checks


if __name__=='__main__':
    raw,recipe=patch(SOURCE.read_bytes());checks=verify(raw);checks['structure']=structure(raw,recipe)
    (ROOT/'analysis/firmware/artwork-playlist-development.json').write_text(json.dumps(dict(recipe=recipe,checks=checks),indent=2)+'\n',encoding='utf-8')
