"""Run native label-renderer bytes with explicit background/text GDI boundaries."""
import json
from verify_max21 import VM,call,fixture
from verify_max19 import STACK,STOP


def native_label_cases(root):
    raw=(root/'AppMain.exe').read_bytes();ui=json.loads((root/'AppMain.exe.json').read_bytes())['settings']
    cases=[]
    for opaque in [False,True]:
        for y in [248,318]:
            for cached in [False,True]:
                m=VM(raw);label=ui['status_label_va'];parent=0x65000000;window=0x65010000
                # Real native constructor/vtable, visibility, opaque-background flag.
                call(m,0x139458,[label,0,0,0]);m.write(label+4,parent)
                m.write(label+0x2c,0x181|(0x400 if opaque else 0));m.write(label+0x30,1)
                for j,v in enumerate([72,y,610,65]):m.write(label+8+j*4,v)
                m.write(parent+0x1c,window);m.write(window+0x74,int(cached));m.write(parent+0x24,0x7777)
                m.write(parent+0x28,0x8888);m.write(window+0x50,0x2222);m.write(window+0x68,1);m.write(window+0x6c,1)
                pool=0x65020000;m.write(0x1865400,1);m.write(0x186ce0,pool);m.write(pool+0x14,0x4444);m.write(pool+0x18,0)
                pixels=[' ']*610;screen=[' ']*610;sequence=[]
                def restore(v):
                    assert v.reg[4]==parent
                    assert [v.read(v.reg[5]+j*4) for j in range(4)]==[72,y,610,65]
                    pixels[:]=[' ']*610;sequence.append('background');return 1
                def draw(v):
                    assert v.reg[4]==0x7777
                    text=v.text(v.reg[5]);pixels[:len(text)]=text;sequence.append('text');return 20
                def present(v):
                    assert v.reg[4:8]==[0x8888,72,y,610]
                    assert v.read(v.reg[29]+16)==65 and v.read(v.reg[29]+20)==0x7777
                    screen[:]=pixels;sequence.append('present');return 1
                m.hooks.update({0x13fe40:lambda v:0x4444,0x140d04:present,0x140c14:lambda v:0,
                                0x13d098:restore,0x139228:lambda v:0,0x140018:lambda v:0,
                                0x140d24:lambda v:0,0x139918:lambda v:0,0x1397c8:lambda v:0,
                                0x140098:draw})
                texts=['Logging off','Logging active','Waiting for USB','Logging off']
                for n,text in enumerate(texts):
                    for j,b in enumerate((text+'\0').encode('utf-16-le')):m.write(label+0x70+j,b,1)
                    call(m,0x139020,[label,0,0,0])
                    call(m,0x13d220,[parent,label+8,0,0])
                    if opaque:assert ''.join(screen).rstrip()==text
                if not opaque:assert ''.join(screen).rstrip()!=texts[-1] # Reproduce MAX19 stale suffix.
                else:assert sequence==(['background','text']+['present']*(1 if cached else 2))*4
                cases.append('actual native label '+('clears prior glyphs' if opaque else 'reproduces transparent overlay')+' y='+str(y)+' cached='+str(cached))
    # Cached-mode WM_PAINT must happen before direct row draw. Return/error ABI stays.
    for is_settings in [False,True]:
        m,last,tick,records=fixture(raw);ui=json.loads((root/'AppMain.exe.json').read_bytes())['settings']
        obj=0x65000000;m.write(ui['context_va'],obj);order=[]
        def native(v):order.append('native paint');last[0]=1234;v.reg[3]=0x5678;return 0x1234
        def refresh(v):order.append('rows');last[0]=999;return 0
        m.hooks[0x134d28]=native;m.hooks[ui['refresh']]=refresh
        result=call(m,ui['paint_wrapper'],[obj if is_settings else obj+4,77,0,0])
        assert result==[0x1234,0x5678] and last[0]==1234
        assert order==(['native paint','rows'] if is_settings else ['native paint'])
        cases.append('paint precedes explicit controls and preserves ABI settings='+str(is_settings))
    return cases
