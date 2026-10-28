"""Execute MAX34 MIPS worker/menu/native hooks against explicit CE API fixtures.

Bulk hashing is accelerated; native SHA vectors and a real chunk run separately.
This is not a Windows CE/device/power-loss emulator or proof of flash durability.
"""
import argparse,hashlib,json,struct,time
from pathlib import Path
from verify_issue59_finish import Finish
from verify_issue56_repair import Fixture,norm,sha
from build_issue56_repair import ROOT
from package_max16 import write

STAGE=r'\Storage Card3\upgrade';QUAR=r'\Storage Card3\MAX34-retained-upgrade'
PENDING=r'\Storage Card3\MAX34-repair.pending';COMPLETE=r'\Storage Card3\MAX34-applications.complete'
SCAN=r'\Storage Card2\scan_done_flag.bin';BOOT=r'\Storage Card3\MAXboot.flag';CE=r'\Storage Card3\StartWinCE'
VERSION=r'\Storage Card\System\Version_Info.txt';UPDATER=r'\Storage Card\System\UpgradeManager.exe'
NK=r'\Storage Card\NK.bin';ENGINE=r'\Storage Card\InstallResume.exe';RECOVERY=r'\Storage Card\Recovery.exe'
SLOTS=[r'\Storage Card3\MAX34-progress-0.bin',r'\Storage Card3\MAX34-progress-1.bin']

class Worker(Finish):
    def __init__(self,directory,files,dirs,*args,**kw):
        super().__init__(directory/'engine',files,dirs,*args,**kw)
        self.module=ENGINE;self.command='-MAX34Install';self.error_code=6001;self.updater_phase=3008;self.busy=0;self.launches=[]
        self.processes.append('UpgradeManager.exe')
    def api(self,uc,addr,size,user):
        dll,o=self.ordinals[(addr-0x7e000000)//8];a=self.args(12)
        if dll=='coredll.dll' and o==1231:
            self.wide(0x60090000,self.command);self.ret(0x60090000);return
        if dll=='coredll.dll' and o==506:
            assert self.handles[a[0]]['kind']=='process' and a[3]==4
            self.remote_reads.append(a[1]);value={0x41000:self.error_code,0x3784c:self.updater_phase,0x38f10:self.busy}[a[1]]
            if self.fail('readprocess'):self.write(a[4],0);self.error=5;self.ret(0)
            else:self.write(a[2],value);self.write(a[4],4);self.ret(1)
            return
        if dll=='coredll.dll' and o==493:
            p,cmd=self.text(a[0]),self.text(a[1]);assert p in [UPDATER,RECOVERY] and cmd==('' if p==UPDATER else '-MAX34NoAuto')
            assert a[2:9]==[0]*7;self.launches.append((p,cmd));self.events.append(('launch',p,cmd))
            if self.fail('process',p):self.ret(0);return
            for j,v in enumerate([self.handle({'kind':'process'}),self.handle({'kind':'thread'}),9,10]):self.write(a[9]+j*4,v)
            self.ret(1);return
        if dll=='coredll.dll' and o==161:
            p=norm(self.text(a[0]));self.events.append(('rmdir',p));ok=p in self.dirs and not any(k.startswith(p+'\\')for k in self.files) and not any(k.startswith(p+'\\')for k in self.dirs)
            if ok:self.dirs.remove(p)
            else:self.error=145
            self.ret(int(ok))
            if self.stop_at and self.stop_at(self):self.uc.emu_stop()
            return
        super().api(uc,addr,size,user)

def inputs(directory):
    rows=json.loads((directory/'member-plan.json').read_bytes())['members'];files={};dirs={''}
    for r in rows:
        p='\\'+r['path'].removeprefix('upgrade/').replace('/','\\');b=(directory/'payload'/r['path']).read_bytes()
        assert sha(b).hex()==r['after']['sha256'];files[norm(STAGE+p)]=b
        if p!=r'\firmware.hex':files[norm(p)]=b
    files[norm(VERSION)]=b'7.0.6.MAX32';files[norm(SCAN)]=b'';files[norm(BOOT)]=b'';files[norm(CE)]=b''
    files[norm(STAGE+r'\filecopy_success.bin')]=b''
    files[norm(r'\Storage Card2\private.cfg')]=b'private settings unchanged'
    files[norm(r'\Storage Card3\TFAT\private.cfg')]=b'original migration backup unchanged'
    files[norm(r'\Storage Card2\pwr_count.bin')]=b'200'
    for p in files:
        parent=p.rsplit('\\',1)[0]
        while parent:dirs.add(parent);parent=parent.rsplit('\\',1)[0]
    return rows,files,dirs

def worker_cases(directory):
    checks=[];rows,files,dirs=inputs(directory);package=json.loads((directory/'engine/build.json').read_bytes())['package_id'].encode()
    def intact(f):
        for p in [NK,UPDATER,RECOVERY,ENGINE,r'\Storage Card2\private.cfg',r'\Storage Card3\TFAT\private.cfg']:
            assert f.files[norm(p)]==files[norm(p)],p
        assert not any(e[0]=='open' and e[2]==0x40000000 and(e[1]==norm(NK)or 'firmware.hex' in e[1])for e in f.events)
    def complete(f):
        assert f.run(timeout=240)==0,f.messages[-1:];intact(f)
        for p in [PENDING,SCAN,CE,r'\Storage Card2\pwr_count.bin']:assert norm(p)not in f.files,p
        assert norm(BOOT)in f.files and norm(STAGE)not in f.dirs
        for r in rows:
            if r['path']=='upgrade/firmware.hex':continue
            p='\\'+r['path'].removeprefix('upgrade/').replace('/','\\');assert sha(f.files[norm(p)]).hex()==r['after']['sha256'],p
        assert not any(k.startswith(norm(QUAR)+'\\')for k in f.files if not k.endswith('unknown.bin'))
    f=Worker(directory,files,dirs);complete(f)
    assert not f.terminated and not f.launches and not any('Repair / resume the pending' in m for m in f.messages)
    assert norm(QUAR)not in f.dirs
    events=f.events;version=next(i for i,e in enumerate(events)if e[0]=='move'and e[2]==norm(VERSION));commit=next(i for i,e in enumerate(events)if e[0]=='move'and e[2]==norm(COMPLETE));clean=next(i for i,e in enumerate(events)if e[0]=='delete'and e[1].startswith(norm(QUAR)+'\\'));pending=next(i for i,e in enumerate(events)if e[0]=='delete'and e[1]==norm(PENDING))
    assert version<commit<clean<pending
    checks.append('full 1921-member final hashes; 1915 application copies plus version last; source cleanup after commit; boot flag retained; delegated parent never killed')
    print('PASS full MAX34 install and cleanup',flush=True)
    # Completed/partial MAX33 metadata belongs to the old protocol namespace.
    # A new MAX34 full install must neither consume nor erase these files.
    old_state=dict(files)
    prior_markers={norm(r'\Storage Card3\MAX33-progress-0.bin'):b'previous package journal',
        norm(r'\Storage Card3\MAX33-applications.complete'):b'MAXmade MAX33 applications verified\r\n'}
    old_state.update(prior_markers)
    g=Worker(directory,old_state,dirs);complete(g)
    assert all(g.files[p]==b for p,b in prior_markers.items())
    checks.append('MAX33 metadata remains separate: MAX34 completes without reading/erasing old journals')
    def seed(state,seq,pass_,index,block):
        b=struct.pack('<5I',0x59333031,seq,pass_,index,block)+sha(package);state[norm(SLOTS[seq&1])]=b+sha(b)
    def resume(g):
        h=Worker(directory,g.files,g.dirs);h.command='-MAX34Resume';h.processes.remove('UpgradeManager.exe');return h
    app=r'\Storage Card\System\AppMain.exe';idx=next(i for i,r in enumerate([r for r in rows if r['path']!='upgrade/Storage Card/InstallResume.exe'])if r['path']=='upgrade/Storage Card/System/AppMain.exe')
    def at_cursor(pass_,index,block):
        def hit(x):
            if not x.events or x.events[-1][0]!='flush' or x.events[-1][1]not in list(map(norm,SLOTS)):return False
            b=x.files[x.events[-1][1]];return len(b)==84 and sha(b[:-32])==b[-32:] and struct.unpack('<5I',b[:20])[2:]==(pass_,index,block)
        return hit
    g=Worker(directory,files,dirs);g.stop_at=at_cursor(0,idx,1);g.run(timeout=80)
    assert len(g.files[norm(app+'.max34-new')])==262144
    h=resume(g);h.stop_at=at_cursor(0,idx+1,0);h.run(timeout=60)
    assert h.files[norm(app)]==files[norm(STAGE+app)] and not any(e[0]=='delete'and e[1]==norm(app+'.max34-new')for e in h.events)
    checks.append('reboot during AppMain resumes saved 256KiB blocks without replaying settings migration')
    small=r'\Storage Card\Background.bmp';smallrow=next(r for r in rows if r['path']=='upgrade/Storage Card/Background.bmp') if any(r['path']=='upgrade/Storage Card/Background.bmp'for r in rows)else None
    # Use the first copied manifest member, independently of filename ordering.
    action2={NK.lower(),UPDATER.lower(),RECOVERY.lower(),r'\firmware.hex'}
    first=next(r for r in rows if norm('\\'+r['path'].removeprefix('upgrade/').replace('/','\\'))not in action2 and r['path']!='upgrade/Storage Card/InstallResume.exe')
    small='\\'+first['path'].removeprefix('upgrade/').replace('/','\\')
    for point in ['delete','move']:
        g=Worker(directory,files,dirs);g.stop_at=lambda x,p=point:any(e[0]==p and e[1 if p=='delete' else 2]==norm(small)for e in x.events);g.run(timeout=60)
        h=resume(g);h.stop_at=lambda x:any(e[0]=='move'and e[2]==norm(small)for e in x.events)or any(e[0]=='flush'and e[1]in list(map(norm,SLOTS))and len(x.files[e[1]])==84 and struct.unpack('<5I',x.files[e[1]][:20])[3]>1 for e in x.events)
        h.run(timeout=60);assert h.files[norm(small)]==files[norm(STAGE+small)]
        checks.append('reboot after target '+point+' retains verified temporary/receipt and resumes')
    # Committed cleanup has no source dependency, including a reboot after every source was removed.
    verified=dict(f.files)
    for k,v in files.items():
        if k.startswith(norm(STAGE)+'\\')or k in list(map(norm,[SCAN,CE,VERSION,r'\Storage Card2\pwr_count.bin'])):verified[k]=v
    verified[norm(PENDING)]=package
    for cut in ['first source','source root removed','pending cleanup']:
        g=Worker(directory,verified,dirs)
        if cut=='first source':g.stop_at=lambda x:bool(x.events)and x.events[-1][0]=='delete'and x.events[-1][1].startswith(norm(QUAR)+'\\')
        elif cut=='source root removed':g.stop_at=lambda x:bool(x.events)and x.events[-1]==('rmdir',norm(QUAR))
        else:g.stop_at=lambda x:bool(x.events)and x.events[-1]==('delete',norm(CE))
        g.run(timeout=240);assert norm(PENDING)in g.files
        h=resume(g);complete(h);assert h.launches==[(UPDATER,'')] and not any(e[0]=='write'and e[1].endswith('.max34-new')for e in h.events)
        checks.append('committed automatic resume without deleted source dependency: '+cut)
    print('PASS interrupted copy/publication/cleanup',flush=True)
    final=dict(f.files);final[norm(PENDING)]=package
    for p in SLOTS:final.pop(norm(p),None)
    seed(final,1,1,idx,1)
    # Verification journal must retain its source: use the original extracted set.
    for k,v in files.items():
        if k.startswith(norm(STAGE)+'\\'):final[k]=v
    g=Worker(directory,final,dirs);g.command='-MAX34Resume';g.stop_at=at_cursor(1,idx,2);g.run(timeout=60)
    assert not any(e[0]=='write'and e[1].endswith('.max34-new')for e in g.events);checks.append('verification pass resumes at saved block without recopy')
    # Manual repair of the issue59-style ambiguous checkpoint; no format or backup removal API exists.
    g=Worker(directory,files,dirs);g.command='-MAX34Repair';g.error_code=5001;g.updater_phase=3007;complete(g)
    assert g.terminated and g.launches==[(UPDATER,'')];checks.append('explicit ambiguous settings repair quiesces pinned stopped updater, keeps TFAT/private settings, finishes and starts native updater')
    for name in ['unknown kernel','unknown updater','wrong Recovery','bad receipt','wrong staged version','missing extract receipt','modified worker','running AppMain','busy updater','active updater','delegation absent','resume receipt absent','source read','temporary write','journal write','commit publish','scan cleanup']:
        g=Worker(directory,files,dirs)
        if name=='unknown kernel':g.files[norm(NK)]=b'foreign'
        elif name=='unknown updater':g.files[norm(UPDATER)]=b'foreign'
        elif name=='wrong Recovery':g.files[norm(RECOVERY)]=b'foreign'
        elif name=='bad receipt':g.files[norm(PENDING)]=b'foreign'
        elif name=='wrong staged version':g.files[norm(STAGE+VERSION)]=b'7.0.6.MAX32'
        elif name=='missing extract receipt':del g.files[norm(STAGE+r'\filecopy_success.bin')]
        elif name=='modified worker':g.files[norm(ENGINE)]=b'foreign'
        elif name=='running AppMain':g.processes.append('AppMain.exe')
        elif name=='busy updater':g.busy=1
        elif name=='active updater':g.updater_phase=3000
        elif name=='delegation absent':g.processes.remove('UpgradeManager.exe')
        elif name=='resume receipt absent':g.command='-MAX34Resume';g.processes.remove('UpgradeManager.exe')
        elif name=='source read':g.fault={'api':'read','path':STAGE+small}
        elif name=='temporary write':g.fault={'api':'write','path':small+'.max34-new'}
        elif name=='journal write':g.fault={'api':'write','path':SLOTS[1]}
        elif name=='commit publish':g=Worker(directory,verified,dirs,{'api':'move','path':COMPLETE})
        elif name=='scan cleanup':g=Worker(directory,verified,dirs,{'api':'delete','path':SCAN})
        before=dict(g.files);assert g.run(timeout=240)==1,(name,g.messages)
        assert (UPDATER,'')not in g.launches and g.launches==[(RECOVERY,'-MAX34NoAuto')],name
        assert norm(BOOT)in g.files,name
        if name!='commit publish':assert norm(SCAN)in g.files,name
        assert g.files[norm(r'\Storage Card2\private.cfg')]==files[norm(r'\Storage Card2\private.cfg')]
        if name not in ['source read','temporary write','journal write','commit publish','scan cleanup']:assert all(g.files[k]==v for k,v in before.items()),name
        checks.append('reject/retain recovery without normal startup: '+name)
    # Do not delete arbitrary material in staging; cleanup failure must not lock out a verified install.
    g=Worker(directory,verified,dirs,{'api':'delete','path':QUAR+small});g.files[norm(STAGE+r'\unknown.bin')]=b'unknown extra';assert g.run(timeout=240)==0
    assert g.files[norm(QUAR+r'\unknown.bin')]==b'unknown extra' and norm(QUAR+small)in g.files
    checks.append('bounded nonrecursive source cleanup preserves unknown extras and tolerates known-source housekeeping failure')
    print('PASS process gates, fault retention and explicit repair',flush=True)
    for load in [0x10000,0x20000,0x17000,0x210000]:
        g=Worker(directory,files,dirs,load=load);g.stop_at=at_cursor(0,idx+1,0);g.run(timeout=60)
        assert any(e[0]=='move'and e[2]==norm(small)for e in g.events);checks.append(f'actual worker entry/relocation/native file path {load:x}')
    for n in [0,1,55,56,63,64,65,4096,262144]:
        g=Worker(directory,files,dirs,fast_digest=False);b=bytes((i*37+11)&255 for i in range(n))
        if b:g.uc.mem_write(0x60010000,b)
        g.run(g.syms['digest'],[0x60010000,n,0x60080000],timeout=60);assert bytes(g.uc.mem_read(0x60080000,32))==sha(b)
        checks.append(f'native SHA256 boundary {n}')
    g=Worker(directory,files,dirs,fast_digest=False);g.stop_at=at_cursor(0,idx+1,0);g.run(timeout=120)
    assert g.files[norm(small)]==files[norm(STAGE+small)];checks.append('unaccelerated native chunk digest/readback/publication')
    return checks

def verify(directory):
    start=time.monotonic();checks=worker_cases(directory)
    result=dict(passed=True,cases=len(checks),checks=checks,seconds=round(time.monotonic()-start,2),physical_tested=False,limitations='Explicit CE APIs; bulk hashlib acceleration; native SHA checked separately; no CE loader, MCU, flash durability or actual power loss emulation')
    write(directory/'worker-verification.json',result);print(json.dumps({k:v for k,v in result.items()if k!='checks'},indent=2),flush=True);return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);verify(p.parse_args().stage.resolve())
