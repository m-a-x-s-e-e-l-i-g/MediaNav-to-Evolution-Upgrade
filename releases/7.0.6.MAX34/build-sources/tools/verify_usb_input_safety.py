"""Exercise written MIPS instructions, strict buffers and explicit CE API fixtures.

No native firmware execution or durability/scheduler emulation.
"""
import hashlib
import json
import struct
from pathlib import Path
from verify_media_responsiveness import VM, parsed, call, STACK, COOKIE
from inspect_bt_pairing import put, data
from patch_usb_input_safety import patch

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'build/media-responsiveness-development-01/payload/upgrade/Storage Card/System/MgrUSB.exe'
OBJ, INPUT, FOLDER, OUTPUT = 0x41000000,0x42000000,0x43000000,0x44000000


def wide(m, at, value, capacity=None):
    raw=(value+'\0').encode('utf-16-le',errors='surrogatepass')
    put(m,at,raw if capacity is None else raw+bytes(capacity*2-len(raw)))


def common(m):
    def zero(v):put(v,v.reg[4],bytes([v.reg[5]&255])*v.reg[6]);return v.reg[4]
    def copy(v):put(v,v.reg[4],data(v,v.reg[5],v.reg[6]));return v.reg[4]
    def length(v):
        for n in range(260):
            if not v.read(v.reg[4]+n*2,2):return n
        raise AssertionError('Unbounded source string')
    m.hooks.update({0x253dc:zero,0x25668:copy,0x253bc:length,0x23aac:lambda v:0,
                    0x25510:lambda v:1})
    m.write(0x2f960,COOKIE)


def paths(raw):
    cases=0
    for name,base,expected in [
        ('song.mp3','MD\\Music','\\MD\\Music\\song.mp3'),
        ('song.wma','\\MD\\Music','\\MD\\Music\\song.wma'),
        ('\\MD\\song.mp3','MD\\Music','\\MD\\song.mp3'),
        ('\\md\\song.mp3','MD','\\md\\song.mp3'),
        ('\\MDfoo\\song.mp3','MD','\\MD\\MDfoo\\song.mp3'),
        ('\\other\\song.mp3','MD','\\MD\\other\\song.mp3'),
        ('C:\\song.mp3','MD','\\MD\\C:\\song.mp3'),
        ('song.mp3',None,'song.mp3'),
        ('', 'MD',None),(None,'MD',None),
        ('x'*250+'.mp3','MD', '\\MD\\'+'x'*250+'.mp3'),
        ('x'*252+'.mp3','MD',None),
        ('song.mp3','M'*250,None),
        ('\\MD\\'+'x'*252+'.mp3','MD',None),
        ('\\MD','MD','\\MD')]:
        m=VM(parsed(raw),[(0x161b4,0x16340)]);common(m)
        if name is not None:wide(m,INPUT,name)
        if base is not None:wide(m,FOLDER,base)
        put(m,0x2fefc,bytes([0xa5])*520)
        m.write(0x2fef8,0x11223344);m.write(0x30104,0x55667788)
        result=call(m,0x161b4,[OBJ,INPUT if name is not None else 0,FOLDER if base is not None else 0])
        assert result==0x2fefc
        assert (m.text(result) or None)==expected,(name,base,expected,result)
        assert m.read(0x2fef8)==0x11223344 and m.read(0x30104)==0x55667788
        cases+=1
    # Independent length cross product, including a full nonterminated base/input.
    for a in (0,1,4,128,250,259,260):
        for b in (1,4,128,250,259,260):
            m=VM(parsed(raw),[(0x161b4,0x16340)]);common(m)
            put(m,INPUT,('x'*a+'\0').encode('utf-16-le') if a<260 else b'x\0'*260)
            put(m,FOLDER,('M'*b+'\0').encode('utf-16-le') if b<260 else b'M\0'*260)
            put(m,0x2fefc,bytes(520));m.write(0x30104,0xa55aa55a)
            result=call(m,0x161b4,[OBJ,INPUT,FOLDER])
            assert result==0x2fefc and bool(m.text(result))==(a>0 and a+b+2<=259)
            assert m.read(0x30104)==0xa55aa55a
            cases+=1
    attrs=0
    for value in [*range(128),0xffffffff,0x10010,0x80000080]:
        m=VM(parsed(raw),[(0x16150,0x1618c)]);common(m)
        m.write(0x2f05c,0xf0000000);m.hooks[0xf0000000]=lambda v,n=value:n
        assert call(m,0x16150,[OBJ,INPUT])==int(not(value&0x10))
        attrs+=1
    suffix=0
    for name,expected in [('',0),('x',0),('xy',0),('xyz',0),('.mp3',1),('.wma',2),
                           ('a.MP3',1),('日.WmA',2),('mp3',0),('x.wav',0)]:
        m=VM(parsed(raw),[(0x16340,0x1640c)]);common(m);wide(m,INPUT,name)
        def copy_s(v):
            text=v.text(v.reg[6]);assert len(text)<v.reg[5]
            wide(v,v.reg[4],text);return 0
        m.hooks[0x25578]=copy_s
        m.hooks[0x255b8]=lambda v:int(v.text(v.reg[4]).lower()!=v.text(v.reg[5]).lower())
        assert call(m,0x16340,[OBJ,INPUT])==expected
        suffix+=1
    return dict(path_cases=cases,attribute_cases=attrs,suffix_cases=suffix)


def saves(raw):
    cases=0
    for va,disposition in ((0x1c17c,4),(0x1c2e8,2)):
        for opened,write_ok,count,close_ok in [(False,1,3180,1),(True,0,0,1),
            (True,0,3180,1),(True,1,0,1),(True,1,3179,1),(True,1,3181,1),
            (True,1,3180,0),(True,1,3180,1)]:
            m=VM(parsed(raw),[(va,0x1c2e8 if va==0x1c17c else 0x1c454)]);common(m)
            put(m,OBJ,bytes(0x3000));put(m,FOLDER,bytes(0x100));wide(m,INPUT,'\\Storage Card2\\USBMusicResume.dat')
            blob=bytes((n*11)%256 for n in range(3180));put(m,OBJ+0xe64,blob)
            events=[];m.hooks[0x231a4]=lambda v:FOLDER
            def create(v):
                assert v.text(v.reg[4]).endswith('USBMusicResume.dat')
                assert v.reg[5:8]==[0x40000000,2,0]
                assert v.read(v.reg[29]+0x10)==disposition
                events.append('open');return 0x5555 if opened else 0xffffffff
            def write(v):
                assert v.reg[4:7]==[0x5555,OBJ+0xe64,3180]
                assert v.read(v.reg[7])==0 and v.read(v.reg[29]+0x10)==0
                assert v.read(OBJ+0xe64,1)==sum(blob[1:])%256
                v.write(v.reg[7],count);events.append('write');return write_ok
            def close(v):assert v.reg[4]==0x5555;events.append('close');return close_ok
            for iat,hook in ((0x2f034,create),(0x2f098,write),(0x2f038,close),(0x2f020,lambda v:5)):
                address=0xf0000000+iat;m.write(iat,address);m.hooks[address]=hook
            result=call(m,va,[OBJ,INPUT],limit=60000)
            assert result==int(opened and write_ok and count==3180 and close_ok)
            assert events==(['open','write','close'] if opened else ['open'])
            cases+=1
    return dict(cases=cases,transactional=False)


def loads(raw):
    cases=0
    for attrs_ok,attrs,folder_ok,read_ok,count,valid in [
        (1,0x80,True,1,3180,True),(0,0,True,1,3180,True),
        (1,2,True,1,3180,True),(1,0x80,False,1,3180,True),
        (1,0x80,True,0,0,True),(1,0x80,True,1,3179,True),
        (1,0x80,True,1,3180,False)]:
        m=VM(parsed(raw),[(0x1be50,0x1c17c),(0x1ab50,0x1abac)]);common(m)
        put(m,OBJ,bytes(0x3000));put(m,FOLDER,bytes(0x100));wide(m,INPUT,'resume.dat')
        blob=bytearray(3180)
        for off,text in ((0x1c,'song.mp3'),(0x224,'\\MD\\song.mp3'),(0x42c,'Title'),
                         (0x634,'Album'),(0x83c,'Artist'),(0xa44,'\\MD')):
            encoded=(text+'\0').encode('utf-16-le');blob[off:off+len(encoded)]=encoded
            blob[off+518:off+520]=b'\xff\xff'
        blob[0]=sum(blob[1:])%256
        if not valid:blob[0]^=1
        events=[]
        def read(v):
            assert v.reg[4:7]==[0x5555,OBJ+0xe64,3180]
            put(v,v.reg[5],blob[:count]);v.write(v.reg[7],count);return read_ok
        def close(v):assert v.reg[4]==0x5555;events.append('close');return 1
        def attr_ex(v):
            events.append(('attributes',v.text(v.reg[4])))
            if attrs_ok:v.write(v.reg[6],attrs)
            return attrs_ok
        for iat,hook in ((0x2f034,lambda v:0x5555),(0x2f058,read),(0x2f038,close),
                         (0x2f094,attr_ex),(0x2f05c,lambda v:0x10 if folder_ok else 0xffffffff),
                         (0x2f020,lambda v:5)):
            address=0xf0000000+iat;m.write(iat,address);m.hooks[address]=hook
        m.hooks[0x231a4]=lambda v:FOLDER
        result=call(m,0x1be50,[OBJ,INPUT],limit=60000)
        expected=bool(attrs_ok and not attrs&2 and folder_ok and read_ok and count==3180 and valid)
        assert result==int(expected) and events.count('close')==1
        if expected:
            for off in (0x1c,0x224,0x42c,0x634,0x83c,0xa44):assert m.read(OBJ+0xe64+off+518,2)==0
        else:assert data(m,OBJ+0xe64,3180)==bytes(3180)
        cases+=1
    return dict(cases=cases)


def metadata(raw):
    # Execute all nine actual call-site slices, including filename and resume fallback.
    cases=0
    sites=[(0x19ea4,0x19eb0),(0x19f48,0x19f58),(0x19f9c,0x19fa8),
           (0x1a034,0x1a040),(0x1a090,0x1a09c),(0x1a1a0,0x1a1ac),
           (0x1a1f0,0x1a1fc),(0x1a288,0x1a294),(0x1a2e4,0x1a2f0)]
    for start,end in sites:
        for text in ('x'*64+'日','x'*64+'Ā','x'*128+'日','x'*258+'日','😀'*100,'Title'):
            m=VM(parsed(raw),[(start,end)]);common(m)
            wide(m,INPUT,text,260);put(m,OUTPUT,bytes(520));m.write(OUTPUT+520,0xa55aa55a)
            # a1 may be retained or replaced from v0; destination is in one of s3/s5/s6/s4.
            m.reg[4]=OUTPUT;m.reg[5]=INPUT;m.reg[2]=INPUT;m.reg[29]=STACK
            for r in (19,20,21,22):m.reg[r]=OUTPUT
            m.run(start,{end})
            assert m.text(OUTPUT)==text and m.read(OUTPUT+520)==0xa55aa55a
            cases+=1
    return dict(copy_cases=cases)


def id3(raw):
    cases=0
    def integer(n,version):
        return bytes((n>>shift)&127 for shift in (21,14,7,0)) if version==4 else n.to_bytes(4,'big')
    def test(version,size=6,padding=0,ext=None,truncated=0,compressed=False,flag=0,
             payload_override=None,bad_size_byte=None):
        ident=b'TT2' if version==2 else b'TIT2'
        size_bytes=integer(size,version)
        if bad_size_byte is not None:
            size_bytes=bytearray(size_bytes);size_bytes[bad_size_byte]|=128;size_bytes=bytes(size_bytes)
        header=ident+(size.to_bytes(3,'big') if version==2 else size_bytes+
                      (0x80 if compressed else flag).to_bytes(2,'big'))
        payload=payload_override if payload_override is not None else b'\x03Hello'+bytes(max(size-6,0))
        body=header+payload[:size]+bytes(padding)
        if ext is not None:body=integer(ext,version)+bytes(max(ext-(4 if version==4 else 0),0))+body
        if truncated:body=body[:-truncated]
        tag=b'ID3'+bytes([version,0,0x40 if ext is not None else 0])+integer(len(body),4)+body
        m=VM(parsed(raw),[(0x178bc,0x182ac)]);common(m)
        put(m,INPUT,tag);put(m,OUTPUT,bytes(0xe48));put(m,STACK-0x100,bytes(0x100))
        converters=[];allocations=[]
        m.hooks.update({0x209e0:lambda v:0,0x209d0:lambda v:0,
                        0x177c0:lambda v:len(tag),0x24c44:lambda v:1})
        def allocate(v):
            allocations.append(v.reg[4]);put(v,FOLDER,bytes(v.reg[4]));return FOLDER
        def convert(v):
            assert 0<v.reg[7]<=min(size,260)-1
            converters.append(data(v,v.reg[5],v.reg[7]))
            wide(v,v.reg[6],'Hello');return v.reg[6]
        m.hooks[0x24e04]=convert
        m.hooks[0x2538c]=allocate;m.hooks[0x2539c]=lambda v:0
        assert call(m,0x178bc,[OUTPUT,INPUT,OUTPUT,len(tag)],limit=25000) in (0,1)
        m.allocations=allocations
        return converters,m
    for ver in (2,3,4):
        for n in (6,127,128,129,255,256,512):
            for padding in (0,1,10):
                conv,m=test(ver,n,padding)
                assert len(conv)==1,(ver,n,padding)
                assert conv[0].startswith(b'Hello') and m.read(OUTPUT+0xe40)&1
                cases+=1
        for trunc in range(1,7):
            conv,m=test(ver,6,0,truncated=trunc);assert not conv
            cases+=1
    for ver in (3,4):
        for ext in (6,10,128):
            conv,m=test(ver,ext=ext);assert len(conv)==1
            cases+=1
    for ver,flags in ((3,(0x20,0x40,0x80)),(4,(1,4,8,0x40))):
        for flag in flags:
            conv,m=test(ver,flag=flag);assert not conv and not m.allocations;cases+=1
    for i in range(4):
        conv,m=test(4,bad_size_byte=i);assert not conv;cases+=1
    conv,m=test(4,size=5,flag=2,payload_override=b'\x03A\xff\0B')
    assert conv==[b'A\xffB'] and m.allocations==[5];cases+=1
    for ext in (0,1,2,3,4,5):
        conv,m=test(4,ext=ext);assert not conv;cases+=1
    conv,m=test(2,ext=6);assert not conv;cases+=1
    return dict(cases=cases,encoding_selection_unchanged=True)


def playlists(raw):
    cases=0
    readers=((0x15c00,0x15df4,lambda p:p),
             (0x165e8,0x1685c,lambda p:'File1='+p),
             (0x16910,0x16c80,lambda p:'<media src="'+p+'" />'))
    for start,end,format_line in readers:
        for name,base,attribute,accepted in [('song.mp3','MD',0x80,True),
            ('song.wma','MD',0x80,True),('日.mp3','MD',0x80,True),
            ('missing.mp3','MD',0xffffffff,False),('directory.mp3','MD',0x30,False),
            ('x','MD',0x80,False),('xy','MD',0x80,False),('xyz','MD',0x80,False),
            ('song.mp3','M'*250,0x80,False),('x.wav','MD',0x80,False)]:
            ranges=[(start,end),(0x161b4,0x16340),(0x16340,0x1640c),
                    (0x16150,0x1618c),(0x1618c,0x161b4),(0x1271c,0x12768)]
            m=VM(parsed(raw),ranges);common(m)
            put(m,OBJ,bytes(0x100));m.write(OBJ+8,1);wide(m,FOLDER,base)
            put(m,STACK-0x1000,bytes(0x1000));put(m,0x2fefc,bytes([0xa5])*520)
            lines=[format_line(name).encode('utf-8')];added=[]
            def line(v):
                if not lines:return 0
                rawline=lines.pop(0);assert len(rawline)<260
                put(v,v.reg[5],rawline+b'\0');return 1
            def strlen(v):
                n=0
                while v.read(v.reg[4]+n,1):n+=1;assert n<260
                return n
            def convert(v):
                assert v.reg[4:6]==[65001,8]
                text=data(v,v.reg[6],v.reg[7]).decode('utf-8')
                units=len(text.encode('utf-16-le'))//2
                destination=v.read(v.reg[29]+0x10)
                if destination:
                    assert units<=v.read(v.reg[29]+0x14)
                    put(v,destination,text.encode('utf-16-le'))
                return units
            def copy_n(v):
                units=[]
                for i in range(v.reg[6]):
                    ch=v.read(v.reg[5]+2*i,2);units.append(ch)
                    if not ch:units+=([0]*(v.reg[6]-len(units)));break
                put(v,v.reg[4],b''.join(ch.to_bytes(2,'little') for ch in units));return v.reg[4]
            def append(v):added.append(v.text(v.reg[5]));return 1
            def attrs(v):return attribute if v.text(v.reg[4]) else 0xffffffff
            m.hooks.update({0x15e4c:line,0x25568:strlen,0x16104:append,0x25558:copy_n,
                0x2593c:lambda v:int(v.text(v.reg[4])[:v.reg[6]].lower()!=v.text(v.reg[5])[:v.reg[6]].lower()),
                0x25588:lambda v:0,
                0x25578:lambda v:(wide(v,v.reg[4],v.text(v.reg[6])) or 0),
                0x255b8:lambda v:int(v.text(v.reg[4]).lower()!=v.text(v.reg[5]).lower())})
            for iat,hook in ((0x2f030,convert),(0x2f05c,attrs)):
                address=0xf0000000+iat;m.write(iat,address);m.hooks[address]=hook
            saved={r:0x12340000+r for r in (*range(16,24),28,30)}
            for r,n in saved.items():m.reg[r]=n
            m.reg[4:8]=[OBJ,FOLDER,0,0];m.reg[29]=STACK;m.reg[31]=0xdead0000
            m.write(STACK-0x1100,0xa55aa55a)
            m.run(start,{0xdead0000},limit=40000)
            assert m.reg[29]==STACK and all(m.reg[r]==n for r,n in saved.items())
            assert m.read(STACK-0x1100)==0xa55aa55a
            assert len(added)==int(accepted),(hex(start),name,base,added)
            if accepted:assert added==['\\'+base+'\\'+name]
            cases+=1
    return dict(reader_cases=cases,readers=['M3U','PLS','WPL'])


def relocated(raw,delta):
    """Architectural MIPS relocations, using raw HIGHADJ companion words."""
    pe=parsed(raw);out=bytearray(raw);d=pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    table=pe.get_data(d.VirtualAddress,d.Size);pos=0
    while pos<len(table):
        page,n=struct.unpack_from('<II',table,pos);vals=struct.unpack_from('<'+str((n-8)//2)+'H',table,pos+8)
        i=0
        while i<len(vals):
            entry=vals[i];kind=entry>>12;i+=1
            if kind==0:continue
            off=pe.get_offset_from_rva(page+(entry&4095));word=struct.unpack_from('<I',out,off)[0]
            if kind==2:struct.pack_into('<H',out,off,((word&65535)+delta)&65535)
            elif kind==3:struct.pack_into('<I',out,off,(word+delta)&0xffffffff)
            elif kind==4:
                companion=vals[i];i+=1
                signed=companion if companion<32768 else companion-65536
                high=(((word&65535)<<16)+signed+delta+32768)>>16
                struct.pack_into('<H',out,off,high&65535)
            elif kind==5:
                assert word>>26 in (2,3),f'Stale jump relocation at {off:x}'
                value=(((word&0x3ffffff)<<2)+delta)>>2
                struct.pack_into('<I',out,off,(word&0xfc000000)|(value&0x3ffffff))
            else:raise AssertionError(f'Unsupported relocation {kind}')
        pos+=n
    struct.pack_into('<I',out,pe.OPTIONAL_HEADER.get_field_absolute_offset('ImageBase'),0x10000+delta)
    return bytes(out)


def relocations(raw):
    cases=0
    for delta in (0x1000,0x10000,0x123000):
        moved=relocated(raw,delta)
        m=VM(parsed(moved),[(0x161b4+delta,0x16340+delta)])
        wide(m,INPUT,'song.mp3');wide(m,FOLDER,'MD')
        put(m,0x2fefc+delta,bytes(520))
        result=call(m,0x161b4+delta,[OBJ,INPUT,FOLDER])
        assert result==0x2fefc+delta and m.text(result)=='\\MD\\song.mp3'
        m=VM(parsed(moved),[(0x16340+delta,0x1640c+delta)])
        wide(m,INPUT,'song.mp3');m.write(0x2f960+delta,COOKIE)
        m.hooks.update({0x253bc+delta:lambda v:len(v.text(v.reg[4])),
            0x25510+delta:lambda v:1,
            0x25578+delta:lambda v:(wide(v,v.reg[4],v.text(v.reg[6])) or 0),
            0x255b8+delta:lambda v:int(v.text(v.reg[4]).lower()!=v.text(v.reg[5]).lower())})
        assert call(m,0x16340+delta,[OBJ,INPUT])==1
        cases+=2
    return dict(cases=cases,deltas=['0x1000','0x10000','0x123000'])


def verify(raw):
    return dict(paths=paths(raw),saves=saves(raw),loads=loads(raw),metadata=metadata(raw),id3=id3(raw),
                playlists=playlists(raw),relocations=relocations(raw))


if __name__=='__main__':
    raw,recipe=patch(SOURCE.read_bytes())
    result=dict(recipe=recipe,checks=verify(raw),native_executed=False)
    (ROOT/'analysis/firmware/usb-input-safety-development.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['checks'],indent=2))
