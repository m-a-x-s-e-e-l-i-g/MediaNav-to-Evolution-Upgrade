"""Pin startup ordering and blocking audio-switch sites without changing waits.

Actual AppMain MIPS control flow plus explicit manager/registry/IPC fixtures.
No native boot, audio-focus readiness, IPC timing or hardware measurements.
"""
import hashlib
import json
from pathlib import Path
from verify_media_responsiveness import VM, parsed, call, put, BUTTON, DIALOG, VTABLE, ROOT, SYSTEM

FUNCTIONS={0x130e50:'manager startup',0xd9114:'USB/iPod resume launch selection',
           0xd9f04:'requestChangeAudioSource',0xd95a8:'requestChangeOverlayAudioSource'}


def startup(raw,ipod,usb,history,dab):
    m=VM(parsed(raw),[(0x130e50,0x13107c),(0xd9114,0xd925c)])
    put(m,BUTTON,bytes(0x3000));put(m,DIALOG,bytes(0x100));put(m,VTABLE,bytes(0x80))
    m.write(DIALOG,VTABLE);m.write(VTABLE+0x1c,0xf0400000)
    # Already-created GUI fixture avoids modeling heap/GDI constructors.
    for at in (0x188240,0x1882ac,0x1882b0):m.write(at,DIALOG)
    m.write(0x187b38,BUTTON);m.write(BUTTON+0xac,int(history!=0))
    m.write(BUTTON+0x88,history);m.write(BUTTON+0x245c,int(dab))
    m.write(BUTTON+0x236c,0);m.write(0x185498,0x409)
    events=[]
    def registry(vm):
        assert vm.reg[4]==0x80000002 and vm.text(vm.reg[6])=='Inserted'
        path=vm.text(vm.reg[5]);assert path in ('LGE\\SystemStatus\\USB\\iPod','LGE\\SystemStatus\\USB\\MassStorage')
        return int(ipod if path.endswith('iPod') else usb)
    def launch(name):
        def f(vm):events.append(dict(operation='launch',manager=name,resume=bool(vm.reg[5])));return 0
        return f
    def blue(vm):events.append(dict(operation='launch',manager='Blue'));return 0
    def sleep(vm):events.append(dict(operation='fixed wait',milliseconds=vm.reg[4]));return 0
    def post(vm):
        assert vm.reg[4:8]==[21,3,0xb7,0] and vm.read(vm.reg[29]+0x10)==0
        assert m.read(BUTTON+0x23e0)==1
        events.append(dict(operation='boot-status IPC',sender=21,receiver=3,command=0xb7));return 1
    m.hooks.update({0x136494:lambda vm:0,0xf0400000:lambda vm:0,
                    0x12d58:lambda vm:DIALOG,0x1e1d4:lambda vm:DIALOG,
                    0xdaf98:lambda vm:0,0xe5e28:lambda vm:0,0x137a68:registry,
                    0xd5dcc:launch('MgrIpod'),0xd5eec:launch('MgrUSB'),
                    0xd925c:lambda vm:events.append(dict(operation='restore other audio source')) or 0,
                    0xd5c98:blue,0xe4c9c:lambda vm:0,
                    0xd602c:lambda vm:events.append(dict(operation='launch',manager='MgrDAB')) or 0})
    m.write(0x18503c,0xf0400004);m.hooks[0xf0400004]=sleep
    m.write(0x1852b8,0xf0400008);m.hooks[0xf0400008]=post
    assert call(m,0x130e50,[])==0
    wait=next(i for i,r in enumerate(events) if r['operation']=='fixed wait')
    assert events[wait]['milliseconds']==600 and events[wait+1]['manager']=='Blue'
    assert events[wait+2]['operation']=='boot-status IPC'
    launches=[r for r in events[:wait] if r['operation']=='launch']
    expected='MgrIpod' if ipod and history==3 else 'MgrUSB' if usb and history==2 else None
    assert len(launches)==2 and [r['manager'] for r in launches]==(
        ['MgrUSB','MgrIpod'] if expected=='MgrUSB' else ['MgrIpod','MgrUSB'])
    assert [r['manager'] for r in launches if r['resume']]==([expected] if expected else [])
    return dict(ipod_inserted=ipod,usb_inserted=usb,last_source=history,dab=dab,events=events)


def inspect(raw):
    rows=json.loads((ROOT/'analysis/functions/705md/AppMain.exe.json').read_text())['functions']
    original=(ROOT/'extracted/705md/upgrade/Storage Card/System/AppMain.exe').read_bytes()
    assert hashlib.sha256(original).hexdigest()=='6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8'
    a,b=parsed(original),parsed(raw);evidence=[]
    for va,label in FUNCTIONS.items():
        f=next(r for r in rows if int(r['begin_va'],16)==va)
        n=int(f['end_va'],16)-va
        old,new=a.get_data(va-a.OPTIONAL_HEADER.ImageBase,n),b.get_data(va-b.OPTIONAL_HEADER.ImageBase,n)
        assert old==new,'Startup/source-switch code changed without analysis'
        imports=[]
        for r in f['imports']:
            if 'Sleep@' not in r['symbol'] and 'IpcSendMsg' not in r['symbol']:continue
            at=int(r['va'],16);word=int.from_bytes(b.get_data(at-b.OPTIONAL_HEADER.ImageBase,4),'little')
            assert word>>26==0 and word&63==9,'Expected actual indirect import call'
            row=dict(va=r['va'],symbol=r['symbol'],call_hex=hex(word))
            if 'Sleep@' in r['symbol']:
                delay=int.from_bytes(b.get_data(at+4-b.OPTIONAL_HEADER.ImageBase,4),'little')
                assert delay>>16==0x2404 and delay&65535==r['constant_arg_candidates']['$a0']
                row['milliseconds']=delay&65535
            imports.append(row)
        evidence.append(dict(function=hex(va),meaning=label,bytes=n,sha256=hashlib.sha256(new).hexdigest(),
                             blocking_sites=imports))
    traces=[startup(raw,i,u,h,d) for i,u in ((False,False),(False,True),(True,False),(True,True))
            for h in (0,1,2,3,4,7) for d in (False,True)]
    return dict(app_sha256=hashlib.sha256(raw).hexdigest(),evidence=evidence,startup_cases=len(traces),startup_traces=traces,
                conclusion='The 600 ms startup sleep follows media-manager launches and precedes Blue/boot-status publication. Source selection contains three separate 200 ms sleep sites; overlay restoration has a separate 500 ms site. Branches are not additive latency measurements.',
                next_measurement='Compare ignition to usable home screen, first/warm screen changes, and radio/USB/Bluetooth switch-to-audio with a matched original/candidate on the same unit. Trace media-manager readiness before shortening waits.',
                waits_changed=False,native_execution=False,elapsed_time_measured=False,
                excluded_scope='No broad Bluetooth RX timeout/power/controller/cache work resumed')


def main():
    raw=(SYSTEM/'AppMain.exe').read_bytes();result=inspect(raw)
    (ROOT/'analysis/firmware/media-performance-audit.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in result.items() if k!='startup_traces'},indent=2))


if __name__=='__main__':main()
