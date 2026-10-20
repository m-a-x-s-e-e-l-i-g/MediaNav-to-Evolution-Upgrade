import json
from verify_max20 import VM
from verify_max19 import MAGIC,STACK
from inspect_wave_queue import STOP

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
                        elif s.ordinal==88:
                            def memory(v):
                                assert v.read(v.reg[4])==32
                                for j,value in enumerate([32,50,0,104857600,0,0,0,0]):v.write(v.reg[4]+j*4,value)
                                return 0
                            m.hooks[target]=memory
                        elif s.ordinal==10:
                            def increment(v):
                                value=(v.read(v.reg[4])+1)&0xffffffff;v.write(v.reg[4],value);return value
                            m.hooks[target]=increment
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
                if on:assert len([c for c in commands if c[0]==MAGIC+4 and c[2] in [event['event'],event['event']|0x80000000]])==(2 if event.get('begin_logged',True) else 1)
                else:assert not any(c[0]==MAGIC+4 for c in commands)
                cases.append(path.name+' '+event['label']+' on='+str(on)+' arguments/results/error/ABI')
    return cases