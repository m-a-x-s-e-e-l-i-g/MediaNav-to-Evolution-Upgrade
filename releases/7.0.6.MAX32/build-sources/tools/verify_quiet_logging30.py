"""Execute actual logger/GPS/UI code with CE boundaries and recorded metadata."""
import argparse,json,struct
from collections import Counter
from pathlib import Path
import pefile
from verify_max20 import Fixture
from verify_max19 import SHARED,INPUT,RECORD
from verify_issues24 import gps_fixture
from verify_max21 import call
from debug_image import sha

ROOT=Path(__file__).resolve().parents[1]


def runtime_scope(root):
    """Only reviewed routines/header and generated PE tables may change."""
    base=ROOT/'build/max29-boot-recovery-development-10'
    before=pefile.PE(str(base/'CmnDll.dll'));after=pefile.PE(str(root/'CmnDll.dll'))
    runtime=json.loads((root/'runtime.json').read_bytes());recipe=json.loads((root/'CmnDll.dll.json').read_bytes())
    assert before.OPTIONAL_HEADER.ImageBase==after.OPTIONAL_HEADER.ImageBase
    assert before.FILE_HEADER.Characteristics==after.FILE_HEADER.Characteristics
    def imports(p):return[(d.dll,[(x.ordinal,x.name,x.address)for x in d.imports])for d in p.DIRECTORY_ENTRY_IMPORT]
    assert imports(before)==imports(after)
    for old,new in zip(before.sections,after.sections):
        assert old.Name==new.Name and old.VirtualAddress==new.VirtualAddress and old.Characteristics==new.Characteristics
        if not old.Name.startswith(b'.mxdebug'):assert old.get_data()==new.get_data()
    old=next(s for s in before.sections if s.Name.startswith(b'.mxdebug')).get_data()
    new=next(s for s in after.sections if s.Name.startswith(b'.mxdebug')).get_data()
    code=recipe['code_va'];q=runtime['quiet_logging'];allowed=set()
    for address in [runtime['addresses']['enqueue'],runtime['addresses']['worker'],q['repeat'],q['remember'],q['priority']]:
        row=next(r for r in recipe['routines']if r['address']==address)
        allowed.update(range(address-code,address-code+row['capacity']))
    at=runtime['strings']['header']-code
    a='\ufeffMAXmade 7.0.6.MAX29 diagnostics'.encode('utf-16-le');b='\ufeffMAXmade 7.0.6.MAX30 diagnostics'.encode('utf-16-le')
    assert old[at:at+len(a)]==a and new[at:at+len(b)]==b
    allowed.update(at+n for n,(x,y)in enumerate(zip(a,b))if x!=y)
    assert all(x==y or n in allowed for n,(x,y)in enumerate(zip(old[:0x30000],new[:0x30000])))
    def rows(p):
        d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];return{r[0]:r for r in struct.iter_unpack('<5I',p.get_data(d.VirtualAddress,d.Size))}
    a=rows(before);b=rows(after)
    assert set(b)-set(a)=={q['repeat'],q['remember'],q['priority']}
    for address,row in a.items():
        if address not in [runtime['addresses']['enqueue'],runtime['addresses']['worker']]:assert b[address]==row
    assert all(p.verify_checksum()for p in [before,after])


def queue_cases(root):
    checks=[]
    def emit(f,module,event,value=0,result=0,text=None,level=0):
        if text is not None:f.put(INPUT,text)
        return f.call(f.A['enqueue'],[module,event,value,result],[INPUT if text is not None else 0,level])
    def count(f):return f.vm.read(SHARED+12)
    def repeats(f):return f.vm.read(SHARED+0x60)
    for delta in (0,0x10000,0x123000):
        f=Fixture(root)
        if delta:f.rebase(delta)
        f.init();f.put(INPUT,'native error');start=f.tick
        for _ in range(21):f.call(f.A['raw'],[INPUT])
        assert count(f)==1 and repeats(f)==20 and len(f.output)==21 and f.vm.read(SHARED+0x20)==0
        f.tick=start+9999;f.call(f.A['raw'],[INPUT]);assert count(f)==1 and repeats(f)==21
        f.tick=start+10000;f.call(f.A['raw'],[INPUT]);assert count(f)==2 and repeats(f)==21
        assert not f.queue_held
        checks.append(f'native full text forwarded on every call; exact repetition filtered until 10s; ABI and rebase={delta:x}')
    for text in ['','tab\tnewline\r\n','non-ASCII Ã© ä¸­','a'*254,'a'*255,'a'*400]:
        f=Fixture(root);f.init();emit(f,0,0,text=text);emit(f,0,0,text=text)
        expected=1 if len(text)<255 else 2
        assert count(f)==expected
        checks.append(f'native comparison uses bounded normalized full text, input length={len(text)}')
    f=Fixture(root);f.init()
    for message in ['same','different','same']:emit(f,0,0,text=message)
    assert count(f)==3 and repeats(f)==0
    for module,event,level in [(0,1,0),(0,1,3),(2,0,3)]:emit(f,module,event,text='same',level=level)
    assert count(f)==6
    checks.append('changed native text/adapter/level and structured records are not conflated')
    f=Fixture(root);f.init()
    emit(f,0,0,text='same');emit(f,0,0,value=123,text='same');emit(f,0,0,text='same')
    assert count(f)==3 and repeats(f)==0
    checks.append('native-shaped structured value/result records invalidate repetition cache; no new diagnostic value is hidden')
    f=Fixture(root);f.init(0);f.put(INPUT,'disabled')
    for _ in range(3):f.call(f.A['raw'],[INPUT])
    assert count(f)==0 and repeats(f)==0 and len(f.output)==3
    checks.append('Debugging Off retains native forwarding without queue/cache mutation')
    f=Fixture(root);f.init();f.wait_result=258;emit(f,0,0,text='contended')
    assert count(f)==0 and f.vm.read(SHARED+0x24)==1
    checks.append('producer mutex remains nonblocking under contention')
    for start in (1000,0xffffff00):
        f=Fixture(root);f.tick=start;f.init();emit(f,0,0,text='wrap')
        f.tick=(start+9999)&0xffffffff;emit(f,0,0,text='wrap');assert count(f)==1
        f.tick=(start+10000)&0xffffffff;emit(f,0,0,text='wrap');assert count(f)==2
        checks.append(f'native repeat heartbeat uses unsigned elapsed ticks start={start:x}')
    for module,event in [(8,940),(8,941),(8,1010),(8,1020),(3,302),(3,979),(3,987),(1,900),(1,906)]:
        f=Fixture(root);f.init()
        for _ in range(97):emit(f,module,event)
        assert count(f)==96 and f.vm.read(SHARED+0x20)==1
        for m,e in [(1,99),(1,101),(1,310),(3,301),(3,950),(4,401),(4,403),(8,1000),(8,1040),(0,0),(0,1)]:emit(f,m,e)
        assert count(f)==107
        checks.append(f'bulk quota reserves capacity for startup/source/artwork/MICOM/actions/native diagnostics; bulk={module}/{event}')
    f=Fixture(root);f.init()
    for _ in range(96):emit(f,8,940)
    f.tick+=1000
    for _ in range(96):emit(f,8,940)
    f.tick+=1000
    for _ in range(33):emit(f,8,940)
    assert count(f)==224
    for _ in range(32):emit(f,4,401)
    assert count(f)==256
    emit(f,4,401);assert count(f)==256
    for _ in range(256):assert f.call(f.A['drain'],[])==1
    assert f.call(f.A['drain'],[])==0
    checks.append('32 queue slots reserved; complete 256-entry ring drains/wraps and remains bounded when full')
    # Worker count is separate from drop count, produced at the existing 10s sample.
    f=Fixture(root);f.init();f.usb=True;emit(f,0,0,text='repeat');emit(f,0,0,text='repeat');f.tick+=10000
    f.worker(3)
    text=''.join(bytes(v).decode('utf-16-le',errors='replace')for v in f.files.values())
    assert '\t1\t906\t1\t0\t' in text and not f.queue_held
    checks.append('writer emits native-suppression total separately from dropped-record totals, outside producer lock')
    return checks


def gps_vm(root):
    raw=(root/'nng/nngnavi.exe').read_bytes();recipe=json.loads((root/'nng/nngnavi.exe.json').read_bytes());p=recipe['gps_probe']
    m,last,clock,records,loads=gps_fixture(raw);state=[0x524d43,0x475041ff,1]
    m.write(0x62000004,0x63000000);m.write(0x62000010,128)
    def scan(v):v.reg[3]=state[1];return state[0]
    def native(v):last[0]=303;v.reg[3]=0x4321;return 0x1234 if state[2]else 0
    m.hooks[p['scanner']]=scan;m.hooks[p['clone']]=native
    def run(ms,kind,meta,accepted=1):
        clock[0]=ms&0xffffffff;state[:]=[kind,meta,accepted]
        out=call(m,p['wrapper'],[11,0x62000000,33,44])
        assert out==[0x1234 if accepted else 0,0x4321] and last[0]==303
    return run,records,m,p


def gps_cases(root):
    checks=[]
    for start in (5000,0xffffff00):
        run,rows,m,p=gps_vm(root)
        run(start,0x524d43,0x475041ff);run(start+29999,0x524d43,0x475041ff);assert len(rows)==2
        run(start+30000,0x524d43,0x475041ff);assert len(rows)==4
        run(start+30001,0x524d43,0x475056ff);assert len(rows)==6
        run(start+30002,0x524d43,0x475056ff,0);assert len(rows)==8
        run(start+30003,0x524d43,0x474e56ff,0);assert len(rows)==10
        checks.append(f'RMC valid/void, acceptance and talker changes immediate; exact 30s heartbeat/wrap={start:x}')
    for kind,first,count_change,state_change in [(0x474741,0x47503108,0x47503109,0x47503000),(0x475341,0x475033ff,0x475033ff,0x475031ff)]:
        run,rows,m,p=gps_vm(root);run(5000,kind,first);run(5001,kind,count_change);assert len(rows)==2
        run(5002,kind,state_change);assert len(rows)==4
        checks.append(f'GPS fix-state changes remain immediate while count-only repetition is compact kind={kind:x}')
    run,rows,m,p=gps_vm(root)
    for ms,meta,accepted in [(5000,0x4750ff07,1),(5001,0x4750ff08,0),(5002,0x4750ff09,1)]:run(ms,0x475356,meta,accepted)
    assert len(rows)==2
    run(5003,0x475356,0x4750ff00,0);assert len(rows)==4
    run(5004,0x475356,0x4750ff01,0);assert len(rows)==6
    run(35004,0x475356,0x4750ff09,1);assert len(rows)==8
    checks.append('GSV count/fragment acceptance chatter compact; zero/nonzero visibility and heartbeat retained')
    run,rows,m,p=gps_vm(root)
    for kind in (0x565447,0x474c4c,0x545854):run(5000,kind,0x4750ffff)
    assert not rows
    checks.append('VTG/other routine sentence metadata omitted; native dispatcher results/error retained')
    # Old detailed GPS build path still reproduces the delivered MAX29 NNG.
    from navigation_probe27 import build
    original=ROOT/'build/max23-source-budget-development-03/payload/upgrade/Storage Card4/NNG/nngnavi.exe'
    b,r=build(original.read_bytes(),'d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9')
    assert b==(ROOT/'build/max29-boot-recovery-development-10/nng/nngnavi.exe').read_bytes()
    checks.append('historical detailed GPS/navigation defaults reproduce MAX29 NNG byte-for-byte')
    return checks


def navigation_cases(root):
    raw=(root/'nng/nngnavi.exe').read_bytes();nav=json.loads((root/'nng/nngnavi.exe.json').read_bytes())['navigation_measurements'];D=nav['state_va'];checks=[]
    for category in range(4):
        m,last,clock,records,loads=gps_fixture(raw);m.write(nav['backend_pointer'],0xf6000010)
        call(m,nav['periodic']);assert not any(1010<=r[1]<=1017 for r in records)
        assert {1020,1021,1023,1024}<={r[1]for r in records};records.clear()
        call(m,nav['update'],[category,0,0,0]);clock[0]+=5000;call(m,nav['periodic'])
        assert [r for r in records if 1010<=r[1]<=1017]==[(8,1010+2*category,1,0),(8,1011+2*category,0,0)]
        assert m.read(D+0x40+category*16)==0
        checks.append(f'empty UI categories omitted; real zero-ms activity and 5s RAM preserved category={category}')
    return checks


def analyzer_cases(root):
    from analyze_debug_logs30 import analyze
    d=root/'quiet-analyzer-fixture';d.mkdir(exist_ok=True)
    p=d/'debug-quiet.log';p.write_bytes(('MAXmade 7.0.6.MAX30 diagnostics\nsession\ttest\t0\n100\t1\t906\t25\t0\t0\t\n101\t1\t901\t0\t7\t0\t\n').encode('utf-16-le'))
    s=analyze([p])['sessions'][0]
    assert s['logging_suppression']==[dict(ms=100,suppressed_native_repeats_total=25)]and s['dropped_records_latest']==7
    return ['analyzer distinguishes deliberate native suppression from dropped records without inventing zero UI intervals']


def verify(root):
    runtime_scope(root);checks=['only reviewed logger routines/header and generated PE tables change; native sections/imports/state and other unwind rows exact']
    checks+=queue_cases(root);print('PASS quiet queue/native repetition cases',flush=True)
    checks+=gps_cases(root)+navigation_cases(root)+analyzer_cases(root)
    for name in ['CmnDll.dll','nng/nngnavi.exe']:
        p=pefile.PE(str(root/name));assert p.verify_checksum() and all(not(s.Characteristics&0x20000000 and s.Characteristics&0x80000000)for s in p.sections)
    checks.append('changed logger/NNG PE checksums and no writable executable sections')
    result=dict(passed=True,cases=len(checks),checks=checks,car_tested=False,limits='MIPS with CE fixtures, not physical speed/USB/GPS testing.')
    (root/'quiet-logging-verification.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS',len(checks),'quiet logging checks',flush=True);return result


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('root',type=Path);verify(p.parse_args().root.resolve())
