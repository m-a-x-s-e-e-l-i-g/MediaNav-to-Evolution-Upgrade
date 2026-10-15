"""Written-byte issue 53/54 tests. CE, UART responses and GPS parser are boundaries."""
import argparse,json,struct
from pathlib import Path
import pefile
from verify_max21 import fixture,call,STACK,STOP
from verify_usb_input_safety import relocated
from debug_image import sha
from package_max16 import write

ROOT=Path(__file__).resolve().parents[1]
ORIGINAL=ROOT/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System/MicomManager.exe'


def vm(raw,on=1,delta=0):
    if delta:
        p=pefile.PE(data=raw);moved=bytearray(relocated(raw,delta))
        struct.pack_into('<I',moved,p.OPTIONAL_HEADER.get_field_absolute_offset('ImageBase'),p.OPTIONAL_HEADER.ImageBase+delta)
        raw=bytes(moved)
    m,last,tick,records=fixture(raw,on)
    for at in range(STACK-0x1000,STACK+0x200,4):m.write(at,0)
    return m,last,tick,records


def micom_cases(root):
    cases=[];raw=(root/'MicomManager.exe').read_bytes();before=ORIGINAL.read_bytes()
    recipe=json.loads((root/'MicomManager.exe.json').read_bytes())
    rows=recipe['issue_diagnostics'];base=pefile.PE(data=before)
    for row in rows:
        p=pefile.PE(data=raw)
        assert p.get_data(row['site']-0x10000+4,4)==base.get_data(row['site']-0x10000+4,4)
        for on in (0,1):
            m,last,tick,records=vm(raw,on)
            obj,setting=0x62000000,0x63000000
            m.write(obj+0xc4,0);m.write(setting,0x9aa5,2)
            args=[obj,22,33,setting]
            def native(v):
                assert v.reg[4:8]==args and last[0]==77
                assert [v.read(v.reg[29]+16+j*4)for j in range(9)]==list(range(100,109))
                last[0]=1234;v.reg[3]=0x4321
                for r in (4,5,6,7,8,9,10,11,12,13,14,15,24,25):v.reg[r]=0xeeee
                return 0x1234
            m.hooks[row['target']]=native
            assert call(m,row['wrapper'],args)==[0x1234,0x4321] and last[0]==1234
            assert len(records)==2*on
            if on:
                assert records[0][1]==0x80000000|row['event'] and records[1][1]==row['event']
                assert records[0][2]==(0x9aa5 if row['rollback_mask'] else 22 if row['begin_metadata']=='argument1' else 0)
            cases.append(f"{row['label']} arguments, 13-arg ABI, result/error preservation, begin/end on={on}")
    # Execute native button blocks, including original bit manipulation and the
    # exact command arguments, through native redraw continuation.
    # Micom is a stock RELOCS_STRIPPED executable, not a relocatable image.
    assert pefile.PE(data=raw).FILE_HEADER.Characteristics==base.FILE_HEADER.Characteristics
    assert base.FILE_HEADER.Characteristics&1
    for delta in (0,):
        for on in (0,1):
            for event,start,mask in [(403,0x427d8,4),(404,0x42838,8)]:
                for initial in (0,1):
                    for ack in (0,1):
                        m,last,tick,records=vm(raw,on,delta)
                        obj,cmd=0x62000000,0x63000000
                        original=0xa2|(mask if initial else 0)
                        m.write(obj+0x10,0x55,1);m.write(obj+0x11,original,1);m.write(cmd+0xc4,0)
                        m.write(0x648e4+delta,cmd);m.reg[17]=obj;m.reg[29]=STACK;m.reg[31]=STOP
                        sent=[]
                        def send(v):
                            assert v.reg[4:8]==[cmd,13,6,obj+0x10],(delta,on,event,initial,ack,list(map(hex,v.reg[4:8])))
                            assert v.read(v.reg[29]+16,1)==2 and v.read(v.reg[29]+20)==100
                            sent.append((v.read(obj+0x10,1),v.read(obj+0x11,1)))
                            last[0]=123;return ack
                        m.hooks[0x14db0+delta]=send
                        m.run(start+delta,{0x424b0+delta},100000)
                        assert sent==[(0x55,original^mask)]
                        assert m.read(obj+0x11,1)==(original^mask if ack else original)
                        assert m.read(obj+0x10,1)==0x55 and last[0]==123
                        if on:
                            assert records[-1][1]==event and records[-1][3]==ack
                        cases.append(f'native {event} rollback only on failure, base={delta:x}, on={on}, bit={initial}, ack={ack}')
    # Reproduce the old misleading state on a rejected write.
    for start,mask in [(0x427d8,4),(0x42838,8)]:
        m,last,tick,records=vm(before);obj=0x62000000
        m.reg[17]=obj;m.reg[29]=STACK;m.write(obj+0x11,0,1);m.write(0x648e4,0x63000000)
        m.hooks[0x14db0]=lambda v:0
        m.run(start,{0x424b0},100000)
        assert m.read(obj+0x11,1)==mask
        cases.append(f'predecessor reproduces rejected-write UI bit remaining set mask={mask}')
    # Actual service entry allocates then calls the native window creator even
    # after a NULL allocation. Detect its first low-address store explicitly.
    for entry,global_va,ctor in [(0x3f01c,0x68594,0x3d55c),(0x49c34,0x68670,0x46f38)]:
        for candidate in (False,True):
            for allocated in (False,True):
                m,last,tick,records=vm(raw if candidate else before)
                m.write(global_va,0);m.write(0x64aac,0x2222);m.write(0x6481c,0)
                m.hooks[0x450c0]=lambda v:0
                obj=0x62000000;m.hooks[0x4a49c]=lambda v:obj if allocated else 0
                m.hooks[ctor]=lambda v:obj
                created=[]
                if allocated:
                    def creator(v):
                        assert v.reg[4:7]==[obj,0x2222,0x3333];created.append(v.reg[4]);return 1
                    m.hooks[0x44b7c]=creator
                else:
                    original_write=m.write
                    def checked_write(at,value,size=4):
                        if at<0x10000:raise RuntimeError('native low-address store')
                        return original_write(at,value,size)
                    m.write=checked_write
                try:
                    call(m,entry,[0x3333,0,0,0])
                    assert candidate or allocated
                except RuntimeError as e:
                    assert str(e)=='native low-address store' and not candidate and not allocated
                assert created==([obj] if allocated else [])
                if candidate and not allocated:assert last[0]==8 and m.read(global_va)==0
                cases.append(f'native service window allocation entry={entry:x}, candidate={candidate}, allocated={allocated}')
    # Native code routing: exact C6 branches differ; do not recommend 3746/3748
    # as interchangeable or patch power policy to hide the owner's symptom.
    p=pefile.PE(data=raw)
    assert p.get_data(0x23dd4-0x10000,0x23e0c-0x23dd4)==base.get_data(0x23dd4-0x10000,0x23e0c-0x23dd4)
    assert p.get_data(0x213f0-0x10000,0x21540-0x213f0)==base.get_data(0x213f0-0x10000,0x21540-0x213f0)
    cases.append('native service-code selection and power-state setter remain exact')
    return cases


def gps_fixture(raw,on=1,load_ok=True,proc_ok=True):
    m,last,tick,records=vm(raw,on);clock=[5000];calls=[];backend=0xf6000010
    def dbg(v):
        if v.reg[4]==0x4d584403:return on
        assert v.reg[4]==0x4d584404
        records.append((v.reg[5],v.reg[6],v.reg[7],v.read(v.reg[29]+16)));return 1
    m.hooks[backend]=dbg
    for d in m.pe.DIRECTORY_ENTRY_IMPORT:
        for s in d.imports:
            at=m.read(s.address)
            if s.ordinal==535:m.hooks[at]=lambda v:clock[0]&0xffffffff
            elif s.ordinal==528:
                def load(v):
                    assert m.text(v.reg[4])=='\\Storage Card\\System\\CmnDll.dll'
                    calls.append('load');last[0]=528;return 0x1234 if load_ok else 0
                m.hooks[at]=load
            elif s.ordinal==530:
                def proc(v):
                    assert v.reg[4]==0x1234 and m.text(v.reg[5])=='DbgDebugPrint'
                    calls.append('proc');last[0]=530;return backend if proc_ok else 0
                m.hooks[at]=proc
            elif s.ordinal==529:m.hooks[at]=lambda v:calls.append('free') or 1
            elif s.ordinal==1492:
                def cas(v):
                    old=m.read(v.reg[4])
                    if old==v.reg[6]:m.write(v.reg[4],v.reg[5])
                    return old
                m.hooks[at]=cas
    return m,last,clock,records,calls


def gps_cases(root):
    cases=[];raw=(root/'nng/nngnavi.exe').read_bytes()
    recipe=json.loads((root/'nng/nngnavi.exe.json').read_bytes());probe=recipe['gps_probe']
    p=pefile.PE(data=raw);prior=(ROOT/'build/max23-source-budget-development-03/payload/upgrade/Storage Card4/NNG/nngnavi.exe').read_bytes()
    assert p.FILE_HEADER.Characteristics==pefile.PE(data=prior).FILE_HEADER.Characteristics
    assert p.OPTIONAL_HEADER.ImageBase==0x10000 and p.FILE_HEADER.Characteristics&1
    assert p.verify_checksum() and all(not(s.Characteristics&0x20000000 and s.Characteristics&0x80000000)for s in p.sections)
    allowed=set()
    for e in recipe['edits']:allowed.update(range(e['offset'],e['offset']+len(bytes.fromhex(e['after_hex']))))
    cs=p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum');allowed.update(range(cs,cs+4))
    assert all(a==b or k in allowed for k,(a,b)in enumerate(zip(prior,raw)))
    assert b'CmnDll.dll' not in [d.dll for d in p.DIRECTORY_ENTRY_IMPORT]
    assert all(d.dll.lower() in (b'coredll.dll',b'toolhelp.dll')for d in p.DIRECTORY_ENTRY_IMPORT)
    cases.append('NNG fixed base/native bytes, PE checksum, W^X and original DLL dependency families retained')
    # Leaf scanning: explicit memory ends at the supplied byte length.
    m,last,tick,records=vm(raw)
    samples=[('$GPRMC,123519,A,4807.038,N,01131.000,E,0,0,230394,,*00',0x524d43,0x475041ff),
             ('$GNRMC,123519,V,,,,,,,230394,,*00',0x524d43,0x474e56ff),
             ('$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*00',0x474741,0x47503108),
             ('$GNGGA,123519,,,,,0,00,,,,,,*00',0x474741,0x474e3000),
             ('GPGSA,A,3,04,05,09,12,,,,,,,,1.8,1.0,1.5*00',0x475341,0x475033ff),
             ('$GPGSV,3,1,12,04,77,123,45*00',0x475356,0x4750ff0c),
             ('',0,0),('$',0,0),('$GPGGA',0,0),('garbage',0,0)]
    for n,(text,kind,meta) in enumerate(samples):
        data=text.encode();at=0x62000000+n*0x1000
        for k,b in enumerate(data):m.write(at+k,b,1)
        assert call(m,probe['scanner'],[at,len(data),0,0])==[kind,meta]
        cases.append('bounded raw sentence marker scan '+(text[:6] or 'empty'))
    full=samples[2][0].encode()
    for n in range(len(full)+1):
        at=0x63000000+n*0x100
        for k,b in enumerate(full[:n]):m.write(at+k,b,1)
        call(m,probe['scanner'],[at,n,0,0])
    cases.append('every GGA truncation stops within the supplied memory interval')
    for length in (0,0xffffffff):assert call(m,probe['scanner'],[0,length,0,0])==[0,0]
    cases.append('NULL and negative/zero lengths are inert')
    at=0x64000000;data=('$GPGGA,'+'x'*121).encode()
    assert len(data)==128
    for k,b in enumerate(data):m.write(at+k,b,1)
    call(m,probe['scanner'],[at,4096,0,0]);cases.append('large input scans no more than 128 bytes')
    for on in (0,1):
        for accepted in (0,1):
            for load_ok,proc_ok in ((True,True),(False,True),(True,False)):
                m,last,clock,records,api_calls=gps_fixture(raw,on,load_ok,proc_ok)
                obj,buffer=0x62000000,0x63000000;text=samples[0][0].encode()
                m.write(obj+4,buffer);m.write(obj+0x10,len(text))
                for k,b in enumerate(text):m.write(buffer+k,b,1)
                def native(v):
                    assert v.reg[4:8]==[11,obj,33,44] and last[0]==77
                    assert [v.read(v.reg[29]+16+j*4)for j in range(9)]==list(range(100,109))
                    last[0]=303;v.reg[3]=0x4321;return 0x65000000 if accepted else 0
                m.hooks[probe['clone']]=native
                expected=[0x65000000 if accepted else 0,0x4321]
                assert call(m,probe['wrapper'],[11,obj,33,44])==expected and last[0]==303
                assert bytes(m.read(buffer+k,1)for k in range(len(text)))==text
                expected_records=2 if on and load_ok and proc_ok else 0
                assert len(records)==expected_records
                if records:assert records==[(8,940,0x524d43,0x475041ff),(8,941,0x524d43,accepted)]
                if load_ok and not proc_ok:assert api_calls==['load','proc','free']
                if not load_ok:assert api_calls==['load']
                cases.append(f'GPS native args/results/error/data exact, on={on}, accepted={accepted}, backend={load_ok}/{proc_ok}')
    # Repeated identical observations are low volume; state/result changes emit.
    m,last,clock,records,api_calls=gps_fixture(raw)
    obj,buffer=0x62000000,0x63000000;text=samples[0][0].encode();accepted=[1]
    m.write(obj+4,buffer);m.write(obj+0x10,len(text))
    for k,b in enumerate(text):m.write(buffer+k,b,1)
    def native(v):last[0]=303;v.reg[3]=123;return accepted[0]
    m.hooks[probe['clone']]=native
    for n in range(10):clock[0]=5000+n*100;call(m,probe['wrapper'],[11,obj,33,44])
    assert len(records)==2 and api_calls==['load','proc']
    clock[0]=10000;call(m,probe['wrapper'],[11,obj,33,44]);assert len(records)==4
    accepted[0]=0;clock[0]=10001;call(m,probe['wrapper'],[11,obj,33,44]);assert len(records)==6
    m.write(buffer+14,ord('V'),1);clock[0]=10002;call(m,probe['wrapper'],[11,obj,33,44]);assert len(records)==8
    cases.append('unchanged NMEA observations sampled every 5s; acceptance/status changes emit immediately')
    # Failed or competing backend resolution never blocks GPS dispatch.
    for locked in (False,True):
        m,last,clock,records,api_calls=gps_fixture(raw,load_ok=False)
        if locked:m.write(probe['backend_pointer']+8,1)
        m.hooks[probe['clone']]=lambda v:0x1234
        for n in range(10):clock[0]=5000+n*100;call(m,probe['wrapper'])
        assert len(api_calls)==(0 if locked else 1) and not records
        if not locked:
            clock[0]=10000;call(m,probe['wrapper']);assert len(api_calls)==2
        cases.append(f'backend unavailable/competing: GPS retained, no wait, bounded retries locked={locked}')
    return cases


def issue_cases(root):
    print('Checking native Micom failure paths',flush=True)
    cases=micom_cases(root)
    print('Checking bounded GPS observer and backend failure paths',flush=True)
    cases+=gps_cases(root)
    write(root/'issue-diagnostics-verification.json',dict(passed=True,cases=len(cases),checks=cases,
        micom_sha256=sha((root/'MicomManager.exe').read_bytes()),
        nng_sha256=sha((root/'nng/nngnavi.exe').read_bytes()),
        limits=['Native MIPS executes with explicit CE/UART/parser boundaries; no hardware claim.',
                'GPS metadata is raw markers and native acceptance, not a standalone checksum validator.',
                'NULL guards do not establish that allocation failure caused the reported restart.']))
    return cases


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True)
    a=p.parse_args();print('Passed',len(issue_cases(a.build)),'issue diagnostics checks')
