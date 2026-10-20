"""Written-MIPS observation/ABI, periodic recovery and parser regression cases."""
import json,struct
from pathlib import Path
import pefile
from verify_max21 import fixture,call,STACK
from verify_issues24 import vm
from debug_image import sha
from package_max16 import write


def targeted(root,revision=25):
    raw=(root/'Blue.exe').read_bytes();recipe=json.loads((root/'Blue.exe.json').read_bytes())
    info=recipe['artwork_diagnostics'];checks=[]
    # Every observer executes, with the actual clone used as a native boundary.
    # Probe argument objects are owned and valid; sentinel fields identify any
    # accidental telemetry writes to original application objects.
    for delta in (0,0x1200000,0x2400000):
        for row in info['hooks']:
            for on in (0,1):
                m,last,tick,records=vm(raw,on,delta)
                args=[0x62000000,0x63000000,0x64000000,0x65000000]
                owner=0x66000000
                for obj in args+[owner]:
                    for n in range(0,0x500,4):m.write(obj+n,0)
                m.write(args[0],owner);m.write(owner+24,2)
                m.write(args[0]+0x424,3);m.write(args[0]+24,2)
                m.write(args[2]+0xc8,0x104,2);m.write(args[2]+0xca,0x100,2)
                m.write(args[2]+0x120,1);m.write(args[2]+0x11c,owner)
                m.write(0x300000+delta,12,2)
                m.write(0x300204+delta,args[0]);m.write(0x300240+delta,1)
                before={a+n:m.read(a+n) for a in args+[owner] for n in range(0,0x500,4)}
                def original(v):
                    assert v.reg[4:8]==args and last[0]==77
                    assert [v.read(v.reg[29]+16+4*j) for j in range(9)]==list(range(100,109))
                    last[0]=1234;v.reg[3]=0x4321
                    for r in (4,5,6,7,8,9,10,11,12,13,14,15,24,25):v.reg[r]=0xeeee
                    return 0x1234
                m.hooks[row['clone']+delta]=original
                result=call(m,row['wrapper']+delta,args)
                assert result==[0x1234,0x4321] and last[0]==1234
                assert all(m.read(a)==v for a,v in before.items())
                assert len(records)==on
                if on:assert records[0][:2]==(3,row['event'])
                else:
                    assert tick[0]==5000
                    assert not any(m.read(info['state']+delta+n) for n in range(0,17*32,4))
                checks.append(f"{row['label']}: original object/13-arg ABI, v0/v1, LastError, on={on}, rebase={delta:x}")
    # Actual scalar observer and changed-state throttle, including a failed
    # queue emission: retry comes from a periodic snapshot, never a spin/wait.
    for delta in (0,0x1200000):
        m,last,tick,records=vm(raw,1,delta)
        record=info['record']+delta;snapshot=info['snapshot']+delta;D=info['state']+delta
        tick[0]=5000;call(m,record,[7,0x001f10a0,1,0]);assert records[-1]==(3,957,0x001f10a0,1)
        tick[0]=5100;call(m,record,[7,0x001f10c0,0,0]);assert len(records)==1
        assert m.read(D+7*32+4)==0x001f10c0 and m.read(D+7*32+8)==0
        tick[0]=6200;call(m,record,[7,0x001f10c0,0,0]);assert len(records)==2
        tick[0]=8000;call(m,record,[7,0x001f10c0,0,0]);assert len(records)==2
        records.clear();tick[0]=9000;call(m,snapshot,[0,0,0,0])
        assert records==[(3,987,0x001f10c0,0),(3,979,1<<7,25)]
        tick[0]=9500;call(m,snapshot,[0,0,0,0]);assert len(records)==2
        # Odd sequence and changed sequence are skipped immediately.
        m.write(D+7*32,3);records.clear();tick[0]=20000
        call(m,snapshot,[0,0,0,0]);assert records==[(3,979,0,25)]
        m.write(D+7*32,4);records.clear();tick[0]=31000
        call(m,snapshot,[0,0,0,0]);assert records==[(3,987,0x001f10c0,0),(3,979,1<<7,25)]
        records.clear();tick[0]=42000;original_read=m.read;sequence_reads=[0]
        def racing_read(at,*args):
            value=original_read(at,*args)
            if at==D+7*32:
                sequence_reads[0]+=1
                if sequence_reads[0]==2:return value+2
            return value
        m.read=racing_read
        call(m,snapshot,[0,0,0,0]);m.read=original_read
        assert records==[(3,979,0,25)]
        checks.append(f'bounded changed-state logging and distinct periodic recovery; odd slot never spins; rebase={delta:x}')
    # Observe real refusal paths; callback boundaries are not replaced by a
    # synthetic always-successful parser. Parsers and malformed bytes execute.
    rows={r['event']:r for r in info['hooks']}
    for version,features,birth,context,queue,expected in [(0x103,0x100,1,1,12,3),(0x104,0,1,1,12,4),
            (0x104,0x100,0,1,12,2),(0x104,0x100,1,0,12,5),(0x104,0x100,1,1,65535,6)]:
        m,last,tick,records=vm(raw);peer=0x62000000
        for n in range(0,0x140,4):m.write(peer+n,0)
        m.write(peer+0xc8,version,2);m.write(peer+0xca,features,2)
        m.write(peer+0x120,birth);m.write(peer+0x11c,0x63000000 if context else 0)
        m.write(0x63000000+0x9a,0,2);m.write(0x300000,queue,2)
        assert call(m,0x270400,[0,0,peer,0])[0]==0
        assert records[-1]==(3,950,(version<<16)|features,expected)
        checks.append(f'actual discovery refusal class {expected} preserves native result')
    # Parser/codec original bytes must remain exact in their new clones.
    # Image.clone only rewrites location-dependent code operands, so compare
    # through the emitted clone recipe plus independent restored-prefix audit.
    p=pefile.PE(data=raw)
    for event in (957,959,960,961):
        row=rows[event];m,last,tick,records=vm(raw)
        buf=0x62000000;out=0x63000000
        for a in (buf,out):
            for n in range(0,128,4):m.write(a+n,0)
        if event==957:args=[buf,0,out,0]
        elif event==959:args=[buf,0,out,8]
        elif event==960:args=[out,0,1,buf]
        else:args=[out,buf,0,0]
        result=call(m,row['entry'],args)[0]
        assert records[-1][1]==event
        assert result in (0,0xffffffff)
        checks.append(f'actual empty/malformed parser/encoder {event} retains refusal and emits checkpoint')
    from build_max25 import BASE
    baseline_blue=(BASE/'Blue.exe').read_bytes()
    connect=bytes.fromhex('a0001f10000400cb000000014a00137163dd544a7e11e2b47c0050c2490048')
    handle=b'\x01\x00\x00\x00\x08\x00\x6a\x00\x07'+b'0000001'
    body=b'\xff\xd8\xff\xd9' # Transport fixture only, not a decoded JPEG.
    packet=b'\xa0\x00\x0f\xc3\x00\x00\x00\x04\x49\x00\x07'+body
    for event in (957,959,960,961):
        for on in (0,1):
            results=[]
            for candidate in (baseline_blue,raw):
                m,last,tick,records=vm(candidate,on)
                buf,out,dest=0x62000000,0x63000000,0x64000000
                for obj in (buf,out,dest):
                    for n in range(0,256,4):m.write(obj+n,0)
                data=connect if event==957 else handle if event==959 else b'0000001\0' if event==960 else packet
                for n,b in enumerate(data):m.write(buf+n,b,1)
                if event==957:args=[buf,len(data),out,0]
                elif event==959:args=[buf,len(data),out,8]
                elif event==960:args=[out,64,1,buf]
                else:
                    m.write(out,dest);m.write(out+4,64);m.write(out+24,1)
                    args=[out,buf,len(data),0]
                result=call(m,rows[event]['entry'],args)[0]
                output=bytes(m.read(out+n,1) for n in range(128))
                collected=bytes(m.read(dest+n,1) for n in range(8))
                results.append((result,output,collected,last[0]))
            assert results[0]==results[1]
            assert results[1][0]==(2 if event==961 else 1) or (event==960 and results[1][0]>1)
            checks.append(f'actual successful parser/encoder {event} preserves MAX24 result/output/error on={on}')
    # All source bytes outside declared hooks/header edits remain exact. No
    # base gameplay, music metadata, audio or protocol command edits are hidden.
    original=Path(__file__).resolve().parents[1]/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System/Blue.exe'
    baseline=original.read_bytes();allowed=set()
    for row in recipe['edits']:
        allowed.update(range(row['offset'],row['offset']+len(bytes.fromhex(row['after_hex']))))
    cs=p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum');allowed.update(range(cs,cs+4))
    assert all(a==b or n in allowed for n,(a,b) in enumerate(zip(baseline,raw)))
    extra={recipe['iphone_advertisement']['entry']} if 'iphone_advertisement'in recipe else set()
    assert all(e['va'] in {0x1ace4,0x280400}|{r['entry'] for r in info['hooks']}|extra
               for e in recipe['edits'] if e['va'] is not None)
    checks.append('all original bytes differ only at reviewed diagnostic entries and PE metadata')
    before=(BASE/'CmnDll.dll').read_bytes();after=(root/'CmnDll.dll').read_bytes()
    cp=pefile.PE(data=after);cs=cp.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    header='\ufeffMAXmade 7.0.6.MAX24 diagnostics'.encode('utf-16-le')
    at=before.index(header)+len('\ufeffMAXmade 7.0.6.MAX2'.encode('utf-16-le'))
    assert revision in (25,26,27,28,29,30)
    assert ('\ufeffMAXmade 7.0.6.MAX'+str(revision)+' diagnostics').encode('utf-16-le') in after
    if revision<30:
        assert len(before)==len(after) and before[at]==ord('4') and after[at]==ord(str(revision)[-1])
        assert all(a==b or n==at or cs<=n<cs+4 for n,(a,b) in enumerate(zip(before,after)))
        checks.append('MAX24 logger instructions and queue policy are byte-identical except version/checksum')
    else:
        from verify_quiet_logging30 import runtime_scope
        runtime_scope(root)
        runtime=json.loads((root/'runtime.json').read_bytes());assert runtime['measurements_revision']==30
        assert runtime['quiet_logging']['normal_records_per_second']==96 and cp.verify_checksum()
        checks.append('MAX30 explicitly changes queue policy; dedicated native quiet-logging suite validates it')
    return checks


def analyzer_cases(root):
    from analyze_debug_logs25 import analyze
    folder=root/'artwork-fixture-logs';folder.mkdir(exist_ok=True)
    header=['\ufeffMAXmade 7.0.6.MAX25 diagnostics','ms\tmodule\tevent\tduration_ms\tresult\tlevel\tmessage',
            'session\t2026-10-16T00:00:00.000\t0']
    records=[(10,950,0x01040100,0),(11,957,0x001f10a0,1),(12,959,9,0xffffffff),
             (13,961,33,2),(14,962,0x00040005,1),(10000,987,0x001f10a0,1),(10001,979,1<<7,25),
             (10002,957,0x001f10c0,0xffffffff)]
    path=folder/'debug-artwork-fixture.log'
    path.write_bytes(('\r\n'.join(header+[f'{ms}\t3\t{event}\t{v}\t{r}\t0\t' for ms,event,v,r in records])+'\r\n').encode('utf-16-le'))
    s=analyze([path])['sessions'][0];a=s['artwork_acquisition']
    assert not s['timings'] and a[0]['version_hex']=='0104' and a[0]['reason']=='accepted'
    assert a[1]['accepted'] and a[1]['obex_version']==16 and a[1]['response_code']==160
    assert a[2]['handle_result']=='invalid' and a[3]['image_result']=='complete'
    assert a[4]['phase_before']=='image transfer' and a[4]['phase_after']=='ready'
    assert a[5]['repeated_snapshot'] and a[5]['checkpoint']==957
    assert a[6]['available_events']==[957]
    assert not a[7]['accepted'], 'Native -1 is refusal, not a successful nonzero BOOL'
    write(root/'artwork-fixture-analysis.json',s)
    return ['analyzer separates scalar events from timings, labels repeats and decodes discovery/parser/controller results']
