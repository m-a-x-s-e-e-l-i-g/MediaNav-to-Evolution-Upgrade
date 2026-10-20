"""Execute written MIPS and the actual retained native SDP formatter."""
import argparse,json
from pathlib import Path
from verify_issues24 import vm
from verify_max21 import call
from verify_usb_input_safety import relocated
from package_max16 import write


def targeted(root):
    checks=[];raw=(root/'Blue.exe').read_bytes();recipe=json.loads((root/'Blue.exe.json').read_bytes())
    probe=recipe['iphone_advertisement']
    def formatter(role,version,on,candidate,delta=0,names=False):
        m,last,tick,recs=vm(raw,on,delta)
        config,out,buf,text=0x62000000,0x63000000,0x64000000,0x65000000
        for off in range(0,0x20,4):m.write(config+off,0)
        for off in range(256):m.write(buf+off,0xa5,1)
        m.write(config+8,version,2);m.write(config+10,0x4f,2);m.write(out,0)
        if names:
            for k,b in enumerate(b'Provider\0'):m.write(text+k,b,1)
            m.write(config+12,text);m.write(config+16,text)
        m.hooks[0x3a76c+delta]=lambda v:8 if v.reg[4] else 0
        m.hooks[0x85b70+delta]=lambda v:buf
        # The unchanged /GS check is a boundary, not an SEH/scheduler simulator.
        m.hooks[0x8ac24+delta]=lambda v:0
        def copy(v):
            for k in range(v.reg[6]):v.write(v.reg[4]+k,v.read(v.reg[5]+k,1),1)
            return v.reg[4]
        m.hooks[0x85758+delta]=copy
        ret=call(m,(probe['wrapper'] if candidate else probe['clone'])+delta,[config,out,role,44])
        assert m.read(out)==buf
        data=bytes(m.read(buf+k,1)for k in range(ret[0]))
        assert m.read(buf+ret[0],1)==0xa5
        return ret,last[0],data,recs
    for role in (1,2):
        for version in (0x100,0x103,0x104,0x105,0x106,0x107):
            for on in (0,1):
                for names in (False,True):
                    a=formatter(role,version,on,False,names=names);b=formatter(role,version,on,True,names=names)
                    assert a[:2]==b[:2]
                    patched=role==2 and 0x104<=version<=0x106
                    if patched:
                        assert int.from_bytes(b[2][0x42:0x44],'big')==0x106
                        assert int.from_bytes(b[2][0x48:0x4a],'big')==0x24f
                        assert all(x==y or n in (0x43,0x48)for n,(x,y)in enumerate(zip(a[2],b[2])))
                    else:assert a[2]==b[2]
                    assert len(b[3])==int(on and role==2)
                    if b[3]:assert b[3][0]==(3,967,0x01060200,int(patched))
                    checks.append(f'native SDP formatter preserves role={role} version={version:x} strings={names} enabled={on}; CT thumbnail only')
    # Original Blue is RELOCS_STRIPPED. Its cloned native formatter must run at
    # its fixed base; only the added leaf patch is independently rebased here.
    for delta in (0x1200000,0x2400000):
        data=formatter(2,0x104,0,False)[2];m,last,tick,recs=vm(raw,1,delta);buf=0x64000000
        for k,b in enumerate(data):m.write(buf+k,b,1)
        assert call(m,probe['patch']+delta,[buf,len(data),2,0])[0]==1
        assert m.read(buf+0x43,1)==6 and m.read(buf+0x48,1)==2
        checks.append('new SDP leaf patch relocates independently; native Blue retains fixed base '+hex(delta))
    # Refuse malformed layouts and partial records without any write or scan.
    canonical=formatter(2,0x104,0,False)[2]
    for offset in (0,3,6,7,9,10,0x37,0x39,0x3e,0x40,0x44,0x46,0x47):
        m,last,tick,recs=vm(raw);buf=0x64000000;data=bytearray(canonical);data[offset]^=1
        for k,b in enumerate(data):m.write(buf+k,b,1)
        assert call(m,probe['patch'],[buf,len(data),2,0])[0]==0
        assert bytes(m.read(buf+k,1)for k in range(len(data)))==data
        checks.append('SDP malformed layout unchanged offset='+hex(offset))
    for length in (0,1,79,81):
        m,last,tick,recs=vm(raw)
        assert call(m,probe['patch'],[0x64000000,length,2,0])[0]==0
        checks.append('SDP short record refused without dereference length='+str(length))
    app=(root/'AppMain.exe').read_bytes();ar=json.loads((root/'AppMain.exe.json').read_bytes())
    for row in ar['artwork_acceptance']['events']:
        for on in (0,1):
            for result in (0,1):
                m,last,tick,recs=vm(app,on);args=[11,22,33,44]
                m.write(0x300034,0x1234);m.write(0x300030,0);m.write(0x30002c,1)
                def native(v):
                    assert v.reg[4:8]==args and last[0]==77
                    assert [v.read(v.reg[29]+16+j*4)for j in range(9)]==list(range(100,109))
                    last[0]=1234;v.reg[3]=0x5678
                    for r in (4,5,6,7,8,9,10,11,12,13,14,15,24,25):v.reg[r]=0xeeee
                    return result
                m.hooks[row['clone']]=native
                assert call(m,row['wrapper'],args)==[result,0x5678] and last[0]==1234
                assert len(recs)==on*result
                if recs:assert recs[0][3]==(5 if row['event']==351 else 1)
                checks.append(f'acceptance observer {row["event"]} enabled={on} changed={result}: no idle flood, no pointers, 13-arg/error/ABI')
    # Execute the original TAKE body with explicit mapping freshness and heap
    # boundaries. Verify both the owned GUI assignment and rejection cleanup.
    take=next(r for r in ar['artwork_acceptance']['events']if r['event']==351)
    for alive,generation,fresh in [(1,7,1),(1,7,0),(0,7,1),(1,8,1)]:
        outcomes=[]
        for observed in (False,True):
            m,last,tick,recs=vm(app);D=0x300020;desc=0x62000000
            for off in range(0,80,4):m.write(D+off,0)
            m.write(D+12,alive);m.write(D+44,generation);m.write(D+16,desc)
            for j,v in enumerate([12,3,0x7777,7]):m.write(desc+j*4,v)
            m.hooks[0x227800]=lambda v:fresh
            freed=[];deleted=[]
            for d in m.pe.DIRECTORY_ENTRY_IMPORT:
                for imp in d.imports:
                    target=m.read(imp.address)
                    if imp.ordinal==1018:m.hooks[target]=lambda v:freed.append(v.reg[4])or 0
                    elif imp.ordinal==12:
                        def exchange(v):
                            old=m.read(v.reg[4]);m.write(v.reg[4],v.reg[5]);return old
                        m.hooks[target]=exchange
            m.hooks[0x140138]=lambda v:deleted.append(v.reg[4])or 1
            ret=call(m,take['wrapper']if observed else take['clone'])
            outcomes.append((ret,last[0],m.read(D+20),freed,deleted))
            if observed:
                event=[r for r in recs if r[1]==351]
                if alive and generation==7 and fresh:assert event and event[0][3]==5
                else:assert not event
        assert outcomes[0]==outcomes[1]
        checks.append(f'actual native GUI TAKE ownership/cleanup parity alive={alive} generation={generation} fresh={fresh}')
    # The cache-disabled constructor deliberately leaves +14 uninitialized.
    nng=(root/'nng/nngnavi.exe').read_bytes();nr=json.loads((root/'nng/nngnavi.exe.json').read_bytes())['navigation_measurements']
    assert nr['cache_mode_checked']
    from verify_issues24 import gps_fixture
    for mode in (0,1):
        m,last,tick,recs,loads=gps_fixture(nng);manager=0x62000000
        m.write(manager,2196);m.write(manager+12,mode)
        if mode:m.write(manager+20,8192)
        call(m,nr['pool_capture'],[manager,0,0,0])
        assert m.read(nr['state_va']+0x14)==(8192 if mode else 0)
        checks.append('NNG cache mode='+str(mode)+' only enabled cache dereferences initialized cache size')
    import pefile
    ap=pefile.PE(data=app)
    assert ap.get_data(ar['artwork_acceptance']['caption_address']-0x10000,64).decode('utf-16-le').rstrip('\0')=='Waiting for current cover'
    checks.append('historical D9 fallback no longer claims current cover decode/display')
    return checks


def analyzer_cases(root):
    from analyze_debug_logs27 import analyze
    d=root/'iphone-analyzer-fixture';d.mkdir(exist_ok=True)
    for revision in (26,27):
        lines=[f'MAXmade 7.0.6.MAX{revision} diagnostics',f'session\tfixture{revision}\t0',
            '10\t8\t1022\t2196\t10033464\t0\t','11\t1\t350\t45\t1\t0\t',
            '12\t1\t351\t2\t5\t0\t','13\t3\t967\t17170944\t1\t0\t']
        (d/f'debug-{revision}.log').write_text('\n'.join(lines)+'\n',encoding='utf-16')
    sessions=analyze(sorted(d.glob('*.log')))['sessions'];a,b=sessions
    assert a['navigation_measurements']['latest_observed_gtmc'][0]['cached_bytes']is None
    assert b['navigation_measurements']['latest_observed_gtmc'][0]['cached_bytes']==10033464
    assert b['artwork_delivery'][1]['owns_current_bitmap'] and b['local_cover_advertisement'][0]['patch_applied']
    return ['MAX27 analyzer invalidates historical MAX26 cache bytes and separates handoff, GUI ownership and local advertisement']


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args()
    checks=targeted(a.build)+analyzer_cases(a.build)
    write(a.build/'iphone-verification.json',dict(passed=True,cases=len(checks),checks=checks));print('Passed',len(checks),'iPhone negotiation/acceptance/cache checks',flush=True)
