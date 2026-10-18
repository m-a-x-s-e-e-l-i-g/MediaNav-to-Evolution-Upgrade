from verify_max19 import VM,STACK,MAGIC
from inspect_wave_queue import STOP
import json

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
                assert not draw, 'Refresh must not draw over old status'
                assert len(m.invalidations)==1, 'Toggle must request background repaint'
                cases.append('Settings page='+str(page)+' theme='+str(profile)+' status='+str(status))
    return cases