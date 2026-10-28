"""Exercise the actual MIPS completion program with explicit CE API fixtures.

Full-payload scenarios accelerate native digest/hash_file with hashlib. Separate
vectors execute native SHA and one real native chunk installation. No physical
car, CE loader, storage durability or MCU behavior is emulated.
"""
import argparse,hashlib,json,struct,time
from pathlib import Path
from unicorn import UC_HOOK_CODE
from verify_issue56_repair import Fixture,norm,sha
from build_issue59_finish import BASE,PIN

SCAN=r'\Storage Card2\scan_done_flag.bin';PENDING=r'\Storage Card3\MAX59-repair.pending'
STAGE=r'\Storage Card3\upgrade';QUAR=r'\Storage Card3\MAX59-interrupted-upgrade'
VERSION=r'\Storage Card\System\Version_Info.txt';UPDATER=r'\Storage Card\System\UpgradeManager.exe'
BOOT=r'\Storage Card3\MAXboot.flag';CE=r'\Storage Card3\StartWinCE'
SLOTS=[r'\Storage Card3\MAX59-progress-0.bin',r'\Storage Card3\MAX59-progress-1.bin']
USB=r'\MD\Issue59Repair';NK=r'\Storage Card\NK.bin'

class Finish(Fixture):
    def __init__(self,directory,files,dirs,fault=None,load=0x10000,fast_digest=True):
        super().__init__(directory/'fixture',files,dirs,fault,load,accelerate=True)
        self.module=USB+r'\MAX59Finish.exe';self.error_code=5001;self.updater_phase=3007
        self.remote_reads=[];self.terminated=[];self.digest_calls=0;self.snapshots={}
        if fast_digest:self.uc.hook_add(UC_HOOK_CODE,self.fast_digest,begin=self.syms['digest'],end=self.syms['digest'])
    def fast_digest(self,uc,addr,size,user):
        self.digest_calls+=1;n=self.reg(5);b=bytes(uc.mem_read(self.reg(4),n)) if n else b''
        uc.mem_write(self.reg(6),hashlib.sha256(b).digest());self.ret(0)
    def api(self,uc,addr,size,user):
        dll,o=self.ordinals[(addr-0x7e000000)//8];a=self.args(8)
        if dll=='toolhelp.dll':
            if o==2:
                h=self.handle({'kind':'snapshot'});self.snapshots[h]=dict(names=list(self.processes),at=0);self.ret(h);return
            if o in [10,11]:
                s=self.snapshots[a[0]]
                if o==10:s['at']=0
                else:s['at']+=1
                if s['at']>=len(s['names']):self.error=18;self.ret(0);return
                assert self.read(a[1])==564
                name=s['names'][s['at']];self.wide(a[1]+36,name);self.write(a[1]+8,1000+s['at']);self.ret(1);return
            if o==1:del self.snapshots[a[0]];del self.handles[a[0]];self.ret(1);return
        if dll=='coredll.dll' and o==168 and a[4]==3 and a[1]==0x40000000:
            p=norm(self.text(a[0]));assert a[2]==0 and a[3]==0 and a[5]==0x80 and a[6]==0
            self.events.append(('open',p,a[1],a[4]))
            if self.fail('open',p) or p not in self.files:self.error=2;self.ret(0xffffffff)
            else:self.ret(self.handle(dict(kind='file',path=p,pos=0,access=a[1])))
            return
        if dll=='coredll.dll' and o==173:
            h=self.handles[a[0]];assert a[2:4]==[0,0]
            if self.fail('seek',h['path']):self.error=5;self.ret(0xffffffff)
            else:h['pos']=a[1];self.ret(a[1])
            return
        if dll=='coredll.dll' and o==509:
            assert a[0:2]==[0x11,0]
            if self.fail('openprocess'):self.error=5;self.ret(0);return
            self.ret(self.handle(dict(kind='process',pid=a[2])));return
        if dll=='coredll.dll' and o==506:
            assert self.handles[a[0]]['kind']=='process' and a[3]==4
            self.remote_reads.append(a[1])
            if self.fail('readprocess'):self.error=5;self.write(a[4],0);self.ret(0);return
            value={0x41000:self.error_code,0x3784c:self.updater_phase}[a[1]]
            self.write(a[2],value);self.write(a[4],4);self.ret(1);return
        if dll=='coredll.dll' and o==544:
            assert self.handles[a[0]]['kind']=='process' and self.error_code==5001 and self.updater_phase==3007
            assert a[1]==0
            if self.fail('terminate'):self.error=5;self.ret(0);return
            self.terminated.append(self.handles[a[0]]['pid']);self.events.append(('terminate-updater',))
            self.processes=[p for p in self.processes if p.lower().rsplit('\\',1)[-1]!='upgrademanager.exe'];self.ret(1);return
        if dll=='coredll.dll' and o==497:
            assert a[1]==5000;self.ret(258 if self.fail('wait') else 0);return
        super().api(uc,addr,size,user)

def inputs():
    rows=json.loads((BASE/'member-plan.json').read_bytes())['members'];files={};dirs={norm(USB),norm(r'\MD'),''}
    for r in rows:
        p='\\'+r['path'].removeprefix('upgrade/').replace('/','\\');b=(BASE/'payload'/r['path']).read_bytes()
        assert len(b)==r['after']['bytes'] and sha(b).hex()==r['after']['sha256']
        files[norm(USB+'\\Payload'+p)]=b
        if p!=r'\firmware.hex':files[norm(p)]=b
    files[norm(VERSION)]=b'4.1.0'
    files[norm(STAGE+r'\Storage Card\System\Version_Info.txt')]=b'7.0.6.MAX30'
    files[norm(SCAN)]=b'';files[norm(STAGE+r'\filecopy_success.bin')]=b''
    files[norm(STAGE+r'\kept.bin')]=b'pending files retained'
    files[norm(r'\Storage Card2\private.cfg')]=b'private settings unchanged'
    files[norm(r'\Storage Card3\TFAT\private.cfg')]=b'old settings backup unchanged'
    files[norm(BOOT)]=b'';files[norm(CE)]=b''
    for p in files:
        parent=p.rsplit('\\',1)[0]
        while parent:dirs.add(parent);parent=parent.rsplit('\\',1)[0]
    return rows,files,dirs

def verify(directory):
    checks=[];rows,files,dirs=inputs();start=time.monotonic()
    small=r'\Storage Card\Recovery.exe';target=norm(small);source=norm(USB+'\\Payload'+small)
    def intact(f):
        assert f.files[norm(r'\Storage Card2\private.cfg')]==files[norm(r'\Storage Card2\private.cfg')]
        assert f.files[norm(r'\Storage Card3\TFAT\private.cfg')]==files[norm(r'\Storage Card3\TFAT\private.cfg')]
        assert f.files[norm(NK)]==files[norm(NK)]
        assert all(f.files[k]==v for k,v in files.items() if k.startswith(norm(USB+'\\Payload')+'\\'))
        assert not any(e[0]=='open' and ('firmware.hex' in e[1] or e[1]==norm(NK)) and e[2]==0x40000000 for e in f.events)
    def complete(f):
        assert f.run(timeout=180)==0,f.messages[-1:];intact(f)
        assert f.files[norm(VERSION)]==b'7.0.6.MAX30'
        assert all(norm(p)not in f.files for p in [SCAN,PENDING,BOOT,CE])
        assert norm(STAGE)not in f.dirs and norm(QUAR)in f.dirs
        for r in rows:
            if r['path'] in ['upgrade/Storage Card/NK.bin','upgrade/firmware.hex']:continue
            p='\\'+r['path'].removeprefix('upgrade/').replace('/','\\')
            assert sha(f.files[norm(p)]).hex()==r['after']['sha256'],p
    # Full actual 1,920-member payload path set, all final bytes independently checked.
    f=Finish(directory,files,dirs);f.processes.append('UpgradeManager.exe');complete(f)
    assert f.terminated and f.remote_reads[:2]==[0x41000,0x3784c]
    events=f.events
    version=next(i for i,e in enumerate(events) if e[0]=='move' and e[2]==norm(VERSION))
    quarantine=next(i for i,e in enumerate(events) if e[0]=='move' and e[1]==norm(STAGE))
    scan=next(i for i,e in enumerate(events) if e[0]=='delete' and e[1]==norm(SCAN))
    boot=next(i for i,e in enumerate(events) if e[0]=='delete' and e[1]==norm(BOOT))
    assert quarantine<scan<version<boot
    checks.append('complete 1920-member/MAX30 byte verification; guarded 5001 updater stop; settings/kernel/MCU preserved; version and boot cleanup ordering')
    print('PASS full MAX30 completion',flush=True)
    # Relocation and native SHA/block-copy use early real payload bytes.
    early={}
    for load in [0x10000,0x20000,0x17000,0x210000]:
        g=Finish(directory,files,dirs,load=load);g.stop_at=lambda x:any(e[0]=='move'and e[2]==target for e in x.events)
        g.run(timeout=30);assert g.files[target]==files[source];intact(g);early[load]=g
        checks.append(f'native entry, block publish and relocation {load:x}')
    g=Finish(directory,files,dirs,fast_digest=False);g.stop_at=lambda x:any(e[0]=='move'and e[2]==target for e in x.events)
    g.run(timeout=60);assert g.files[target]==files[source];checks.append('actual native SHA source/readback and real Recovery.exe chunk publication')
    for n in [0,1,55,56,63,64,65,4096,16385,262144]:
        g=Finish(directory,files,dirs,fast_digest=False);b=bytes((j*37+11)&255 for j in range(n))
        if b:g.uc.mem_write(0x60010000,b)
        g.run(g.syms['digest'],[0x60010000,n,0x60080000],timeout=60)
        assert bytes(g.uc.mem_read(0x60080000,32))==sha(b)
        checks.append(f'native chunk SHA boundary {n}')
    print('PASS native SHA, chunks and relocation',flush=True)
    # Interrupted copy at real 3 MB AppMain chunk boundaries resumes using receipts.
    app=r'\Storage Card\System\AppMain.exe';temp=norm(app+'.max59-new')
    app_index=next(i for i,r in enumerate(rows)if r['path']=='upgrade/Storage Card/System/AppMain.exe')
    g=Finish(directory,files,dirs)
    def midchunk(x):
        if not x.events or x.events[-1][0]!='flush' or x.events[-1][1]not in [norm(p)for p in SLOTS]:return False
        b=x.files[x.events[-1][1]]
        return len(b)==84 and hashlib.sha256(b[:-32]).digest()==b[-32:] and struct.unpack('<5I',b[:20])[2:]==(0,app_index,1)
    g.stop_at=midchunk;g.run(timeout=45);assert 0<len(g.files[temp])<len(files[norm(app)])
    prior=len(g.files[temp]);resumed=Finish(directory,g.files,g.dirs)
    resumed.stop_at=lambda x:any(e[0]=='move'and e[2]==norm(app)for e in x.events)
    resumed.run(timeout=45);assert resumed.files[norm(app)]==files[norm(USB+'\\Payload'+app)]
    assert not any(e[0]=='delete'and e[1]==temp for e in resumed.events)
    checks.append('reboot during multi-block AppMain preserves earlier chunks and resumes before publication')
    # Rename interruption: program can survive an absent live file.
    g=Finish(directory,files,dirs);g.stop_at=lambda x:any(e[0]=='delete'and e[1]==target for e in x.events)
    g.run(timeout=30);assert target not in g.files
    resumed=Finish(directory,g.files,g.dirs);resumed.stop_at=lambda x:any(e[0]=='move'and e[2]==target for e in x.events)
    resumed.run(timeout=30);assert resumed.files[target]==files[source]
    checks.append('power interruption between target delete and temp rename resumes')
    # Interrupted final cleanup resumes directly from verification-complete journal.
    final_files=dict(f.files);final_dirs=set(f.dirs)
    package=b'MAXmade issue59 MAX30 completion 01 / '+PIN.encode()+b'\r\n'
    final_files[norm(PENDING)]=package;final_files[norm(SCAN)]=b'';final_files[norm(BOOT)]=b'';final_files[norm(CE)]=b''
    g=Finish(directory,final_files,final_dirs);complete(g)
    assert not any(e[0]=='open'and e[2]==0x40000000 and e[1].endswith('.max59-new') and e[1]!=norm(VERSION+'.max59-new')for e in g.events)
    checks.append('final-cleanup retry uses completed verification journal without reinstalling application files')
    # A separate verification pass also saves block-level progress. Seed a valid
    # receipt at the second AppMain block and stop after the following commit.
    def seed_progress(state,seq,pass_,index,block):
        header=struct.pack('<5I',0x59333031,seq,pass_,index,block)+hashlib.sha256(package).digest()
        state[norm(SLOTS[seq&1])]=header+hashlib.sha256(header).digest()
    vf=dict(final_files)
    for p in SLOTS:vf.pop(norm(p),None)
    seed_progress(vf,1,1,app_index,1)
    g=Finish(directory,vf,final_dirs)
    def verifying_piece(x):
        if not x.events or x.events[-1][0]!='flush' or x.events[-1][1]not in [norm(p)for p in SLOTS]:return False
        b=x.files[x.events[-1][1]]
        return len(b)==84 and struct.unpack('<5I',b[:20])[2:]==(1,app_index,2)
    g.stop_at=verifying_piece;g.run(timeout=30)
    assert not any(e[0]=='open'and e[2]==0x40000000 and e[1].endswith('.max59-new')for e in g.events)
    checks.append('verification resumes at saved AppMain block without copying the application set again')
    # A failed verification can never authorize checkpoint cleanup.
    bad=dict(final_files)
    for p in SLOTS:bad.pop(norm(p),None)
    small_index=next(i for i,r in enumerate(rows)if r['path']=='upgrade/Storage Card/Recovery.exe')
    seed_progress(bad,1,1,small_index,0);bad[target]=b'corrupt target'
    g=Finish(directory,bad,final_dirs);assert g.run(timeout=30)==1
    assert norm(SCAN)in g.files and norm(PENDING)in g.files and norm(BOOT)in g.files
    assert not any(e[0]=='delete'and e[1]in [norm(SCAN),norm(PENDING),norm(BOOT)]for e in g.events)
    resumed=Finish(directory,g.files,g.dirs);complete(resumed)
    checks.append('failed verification keeps recovery/checkpoint and schedules recopy before a new complete verification pass')
    # An oversized partial temp is discarded, not retried forever.
    oversized=dict(files);oversized[norm(PENDING)]=package
    oversized[norm(temp)]=b'x'*(len(files[norm(app)])+1)
    seed_progress(oversized,1,0,app_index,1)
    g=Finish(directory,oversized,dirs);g.stop_at=lambda x:any(e[0]=='move'and e[2]==norm(app)for e in x.events)
    g.run(timeout=45);assert g.files[norm(app)]==files[norm(USB+'\\Payload'+app)]
    checks.append('oversized interrupted temporary restarts only that file and publishes verified blocks')
    # A resumed large temporary already occupies disk space. Reserve only its
    # remaining bytes, so a reboot does not demand a second complete temporary.
    low=dict(files);low[norm(PENDING)]=package
    app_bytes=files[norm(USB+'\\Payload'+app)];last_block=(len(app_bytes)-1)//262144
    low[norm(temp)]=app_bytes[:last_block*262144]
    seed_progress(low,1,0,app_index,last_block)
    g=Finish(directory,low,dirs);g.free=131072
    g.stop_at=lambda x:any(e[0]=='move'and e[2]==norm(app)for e in x.events)
    g.run(timeout=45);assert g.files[norm(app)]==app_bytes
    checks.append('low-free-space resume accounts for the existing verified large temporary')
    # No unsafe action on unsupported or actively flashing states.
    cases=['unknown kernel','missing scan','missing extract marker','wrong staged version','missing card','running AppMain','running MICOM','running active updater','wrong updater error','unknown running updater','unreadable updater state','terminate failure','wait timeout','cancel','no disk space','bad repair receipt','unsafe USB path']
    for name in cases:
        g=Finish(directory,files,dirs)
        if name=='unknown kernel':g.files[norm(NK)]=b'unknown'
        elif name=='missing scan':del g.files[norm(SCAN)]
        elif name=='missing extract marker':del g.files[norm(STAGE+r'\filecopy_success.bin')]
        elif name=='wrong staged version':g.files[norm(STAGE+r'\Storage Card\System\Version_Info.txt')]=b'foreign package'
        elif name=='missing card':g.dirs.remove(norm(r'\Storage Card4'))
        elif name=='running AppMain':g.processes.append('AppMain.exe')
        elif name=='running MICOM':g.processes.append('MicomManager.exe')
        elif name=='no disk space':g.free=1
        elif name=='bad repair receipt':g.files[norm(PENDING)]=b'foreign receipt'
        elif name=='unsafe USB path':g.module=r'\MD\..\Storage Card\MAX59Finish.exe'
        elif name=='cancel':g.fault={'confirm':7}
        else:
            g.processes.append('UpgradeManager.exe')
            if name=='running active updater':g.updater_phase=3000
            elif name=='wrong updater error':g.error_code=5002
            elif name=='unknown running updater':g.files[norm(UPDATER)]=b'unknown updater'
            elif name=='unreadable updater state':g.fault={'api':'readprocess'}
            elif name=='terminate failure':g.fault={'api':'terminate'}
            elif name=='wait timeout':g.fault={'api':'wait'}
        before=dict(g.files);assert g.run(timeout=30)==1,(name,g.messages)
        assert all(g.files[k]==v for k,v in before.items()),name
        assert g.installwrites==0,name
        if name not in ['wait timeout']:assert not g.terminated,name
        checks.append('preflight stops without internal writes: '+name)
    print('PASS safe preflight and live-process gates',flush=True)
    # Injected short reads/writes and file faults stop before publishing unchecked bytes.
    faults=[('source read',{'api':'read','path':USB+'\\Payload'+small}),
            ('source seek',{'api':'seek','path':USB+'\\Payload'+small}),
            ('temp partial write',{'api':'write','path':small+'.max59-new'}),
            ('temp readback',{'api':'read','path':small+'.max59-new'}),
            ('temp flush',{'api':'flush','path':small+'.max59-new'}),
            ('publish rename',{'api':'move','path':small}),
            ('first progress slot write',{'api':'write','path':SLOTS[1]}),
            ('progress readback',{'api':'read','path':SLOTS[1]}),
            ('USB log write',{'api':'write','path':USB+r'\finish-123456-0.log'})]
    for name,fault in faults:
        g=Finish(directory,files,dirs,fault);assert g.run(timeout=30)==1,(name,g.messages)
        assert norm(SCAN)in g.files and g.files[norm(VERSION)]==b'4.1.0'
        intact(g)
        if name!='USB log write':
            resumed=Finish(directory,g.files,g.dirs)
            resumed.stop_at=lambda x:any(e[0]=='move'and e[2]==target for e in x.events)
            resumed.run(timeout=45);assert resumed.files[target]==files[source]
        checks.append(name+': retained checkpoint/source and retry succeeds')
    # A single short-write case exercises both journal and copy loops.
    g=Finish(directory,files,dirs,{'short_reads':17,'short_writes':13})
    g.stop_at=lambda x:any(e[0]=='move'and e[2]==target for e in x.events)
    g.run(timeout=60);assert g.files[target]==files[source]
    checks.append('native receipt, journal and chunk loops accept successful short reads/writes')
    # Corrupt progress cannot cause an unsafe jump; own package receipt permits recopy.
    g=Finish(directory,files,dirs);g.files[norm(PENDING)]=package
    g.files[norm(SLOTS[0])]=b'partial';g.files[norm(SLOTS[1])]=b'partial'
    g.stop_at=lambda x:any(e[0]=='move'and e[2]==target for e in x.events)
    g.run(timeout=30);assert g.files[target]==files[source];checks.append('damaged progress slots with verified own receipt restart safe application copy')
    # Same boot tick never overwrites a prior attempt's log.
    g=Finish(directory,files,dirs,{'confirm':7});g.run();h=Finish(directory,g.files,g.dirs,{'confirm':7});h.run()
    assert len([p for p in h.files if p.startswith(norm(USB+r'\finish-'))])==2
    checks.append('same-tick retries preserve all USB logs')
    result={'passed':True,'cases':len(checks),'checks':checks,'exe_sha256':hashlib.sha256((directory/'MAX59Finish.exe').read_bytes()).hexdigest(),
            'full_manifest_members':1920,'physical_tested':False,'seconds':round(time.monotonic()-start,2),
            'limits':'MIPS execution with CE API fixtures. Full-file and chunk SHA accelerated in bulk flows; native SHA boundary vectors and a real native chunk independently executed. No hardware, CE loader, real process memory, power durability or MCU proof.'}
    (directory/'verification.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2));return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);verify(p.parse_args().directory.resolve())
