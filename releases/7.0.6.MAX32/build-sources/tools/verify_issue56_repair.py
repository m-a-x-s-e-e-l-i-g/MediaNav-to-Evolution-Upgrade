"""Run the delivered MIPS PE in Unicorn against explicit CE/filesystem fixtures.

Full-manifest control tests accelerate hash_file with hashlib. Separate tests
execute the actual native file/SHA implementation over boundary vectors. Neither
emulates CE, a bootloader, flash durability, real power loss, or the car.
"""
import argparse, copy, hashlib, json, struct, time
from pathlib import Path
import pefile
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_0, UC_MIPS_REG_PC
from build_issue56_repair import ROOT, BASE, PIN, OLD_UPDATER

API_BASE=0x7e000000;RETURN=0x7f000000;STACK=0x600ff000
SCAN=r'\Storage Card2\scan_done_flag.bin';PENDING=r'\Storage Card3\MAX56-repair.pending'
STAGE=r'\Storage Card3\upgrade';QUAR=r'\Storage Card3\MAX56-interrupted-upgrade'
VERSION=r'\Storage Card\System\Version_Info.txt';UPDATER=r'\Storage Card\System\UpgradeManager.exe'
def norm(p):return p.lower().rstrip('\\')
def sha(b):return hashlib.sha256(b).digest()

class Fixture:
    def __init__(self,directory,files,dirs,fault=None,load=0x10000,accelerate=True):
        self.raw=(directory/'MAX56Repair.exe').read_bytes();self.pe=pefile.PE(data=self.raw)
        self.recipe=json.loads((directory/'build.json').read_bytes());self.delta=load-0x10000
        self.syms={k:v+self.delta for k,v in self.recipe['symbols'].items()}
        self.uc=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
        self.uc.mem_map(load,(self.pe.OPTIONAL_HEADER.SizeOfImage+4095)&~4095)
        self.uc.mem_write(load,self.pe.get_memory_mapped_image())
        if self.delta:self.relocate(load)
        self.uc.mem_map(0x60000000,0x100000);self.uc.mem_map(API_BASE,0x1000);self.uc.mem_map(RETURN,0x1000)
        self.files=dict(files);self.dirs=set(dirs);self.before=dict(files);self.fault=fault or {};self.error=0
        self.handles={};self.h=100;self.events=[];self.messages=[];self.processes=['nk.exe','filesys.exe','device.exe','gwes.exe','explorer.exe','ULC_launcher.exe']
        self.module=r'\MD\MAX56Repair.exe';self.free=500*1024*1024;self.process_at=0;self.hashcalls=0;self.installwrites=0
        self.fired=False;self.hash_cache={};self.locked=False;self.accelerate=accelerate;self.stop_at=None
        self.ordinals=[]
        for desc in self.pe.DIRECTORY_ENTRY_IMPORT:
            for imp in desc.imports:
                self.ordinals.append((desc.dll.decode().lower(),imp.ordinal));at=API_BASE+8*(len(self.ordinals)-1)
                self.write(imp.address+self.delta,at);self.uc.mem_write(at,struct.pack('<II',0x03e00008,0))
        self.uc.hook_add(UC_HOOK_CODE,self.api,begin=API_BASE,end=API_BASE+8*len(self.ordinals)-1)
        if accelerate:self.uc.hook_add(UC_HOOK_CODE,self.fast_hash,begin=self.syms['hash_file'],end=self.syms['hash_file'])
    def reg(self,n):return self.uc.reg_read(UC_MIPS_REG_0+n)
    def setreg(self,n,v):self.uc.reg_write(UC_MIPS_REG_0+n,v&0xffffffff)
    def write(self,a,v):self.uc.mem_write(a,struct.pack('<I',v&0xffffffff))
    def read(self,a):return struct.unpack('<I',self.uc.mem_read(a,4))[0]
    def text(self,a):
        if not a:return ''
        b=bytearray()
        for _ in range(1200):
            q=bytes(self.uc.mem_read(a,2));a+=2
            if q==b'\0\0':return b.decode('utf-16-le')
            b.extend(q)
        raise AssertionError('Unterminated string')
    def wide(self,a,s):self.uc.mem_write(a,(s+'\0').encode('utf-16-le'))
    def ret(self,value):self.setreg(2,value);self.uc.reg_write(UC_MIPS_REG_PC,self.reg(31))
    def args(self,n):return [self.reg(4+i)if i<4 else self.read(self.reg(29)+4*i)for i in range(n)]
    def fail(self,api,p=''):
        if self.fired or self.fault.get('api')!=api:return False
        if self.fault.get('path') and norm(self.fault['path'])!=norm(p):return False
        self.fired=True;return True
    def handle(self,data):self.h+=1;self.handles[self.h]=data;return self.h
    def relocate(self,load):
        p=self.pe;d=p.OPTIONAL_HEADER.DATA_DIRECTORY[5];b=p.get_data(d.VirtualAddress,d.Size);pos=0
        while pos<len(b):
            page,size=struct.unpack_from('<II',b,pos);values=struct.unpack_from('<'+'H'*((size-8)//2),b,pos+8);j=0
            while j<len(values):
                kind=values[j]>>12;at=load+page+(values[j]&4095);j+=1
                if kind==0:continue
                word=self.read(at)
                if kind==3:self.write(at,word+self.delta)
                elif kind==2:self.write(at,(word&0xffff0000)|((word+self.delta)&65535))
                elif kind==4:
                    low=values[j];j+=1;low=low if low<32768 else low-65536
                    result=(((word&65535)<<16)+low+self.delta+0x8000)>>16
                    self.write(at,(word&0xffff0000)|(result&65535))
                elif kind==5:self.write(at,(word&0xfc000000)|((((word&0x3ffffff)<<2)+self.delta)>>2&0x3ffffff))
                else:raise AssertionError(kind)
            pos+=size
    def digest(self,b):
        key=id(b)
        if key not in self.hash_cache:self.hash_cache[key]=(b,sha(b))
        return self.hash_cache[key][1]
    def fast_hash(self,uc,addr,size,user):
        p=norm(self.text(self.reg(4)));n=self.reg(5);digest=bytes(uc.mem_read(self.reg(6),32));self.hashcalls+=1
        b=self.files.get(p);ok=b is not None and len(b)==n and self.digest(b)==digest
        if self.fail('hash',p):ok=False
        if not ok:
            self.wide(self.syms['failed_path'],self.text(self.reg(4)));self.write(self.syms['failed_error'],23 if b is not None else 2)
        self.ret(int(ok))
    def api(self,uc,addr,size,user):
        dll,o=self.ordinals[(addr-API_BASE)//8];a=self.args(12);result=1
        if dll=='toolhelp.dll':
            if o==2:self.process_at=0;result=self.handle({'kind':'snapshot'})
            elif o in [10,11]:
                if o==11:self.process_at+=1
                if self.process_at>=len(self.processes):result=0;self.error=18
                else:
                    assert self.read(a[1])==564
                    self.wide(a[1]+36,self.processes[self.process_at])
            elif o==1:del self.handles[a[0]]
            else:raise AssertionError((dll,o))
        elif o==168:
            p=norm(self.text(a[0]));access,share,create=a[1],a[2],a[4]
            assert a[3]==0 and a[5]==0x80 and a[6]==0
            self.events.append(('open',p,access,create))
            if self.fail('open',p):self.error=5;result=0xffffffff
            elif create==1:
                assert access==0x40000000 and share==0
                if p in self.files or p in self.dirs:self.error=80;result=0xffffffff
                elif p.rsplit('\\',1)[0]not in self.dirs:self.error=3;result=0xffffffff
                else:self.files[p]=b'';result=self.handle(dict(kind='file',path=p,pos=0,access=access))
            elif create==3:
                assert access==0x80000000 and share==1
                if p not in self.files:self.error=2;result=0xffffffff
                else:result=self.handle(dict(kind='file',path=p,pos=0,access=access))
            else:raise AssertionError(create)
        elif o==170:
            h=self.handles[a[0]];p=h['path'];assert a[4]==0
            if self.fail('read',p):self.error=5;self.write(a[3],0);result=0
            else:
                n=min(a[2],self.fault.get('short_reads',a[2]));b=self.files[p][h['pos']:h['pos']+n];h['pos']+=len(b)
                if b:uc.mem_write(a[1],b)
                self.write(a[3],len(b))
        elif o==171:
            h=self.handles[a[0]];p=h['path'];assert h['access']==0x40000000 and a[4]==0
            b=bytes(uc.mem_read(a[1],a[2]));count=min(len(b),self.fault.get('short_writes',len(b)))
            fail=self.fail('write',p)
            if fail:count//=2;self.error=112;result=0
            old=self.files[p];self.files[p]=old[:h['pos']]+b[:count]+old[h['pos']+count:];h['pos']+=count;self.write(a[3],count)
            if not p.startswith('\\md\\'):self.installwrites+=1
            self.events.append(('write',p,count))
        elif o==553:
            h=self.handles.pop(a[0]);p=h.get('path','');self.events.append(('close',p))
            if self.fail('close',p):self.error=5;result=0
        elif o==172:
            h=self.handles[a[0]];self.write(a[1],0);result=len(self.files[h['path']])
            if self.fail('size',h['path']):result=0xffffffff;self.error=5
        elif o==166:
            p=norm(self.text(a[0]));result=16 if p in self.dirs else 128 if p in self.files else 0xffffffff
            if result==0xffffffff:self.error=2
            if self.fail('attrs',p):result=0xffffffff;self.error=5
        elif o==160:
            p=norm(self.text(a[0]));self.events.append(('mkdir',p));assert a[1]==0
            if self.fail('mkdir',p):self.error=5;result=0
            elif p in self.files or p.rsplit('\\',1)[0]not in self.dirs:self.error=3;result=0
            else:self.dirs.add(p)
        elif o==165:
            p=norm(self.text(a[0]));self.events.append(('delete',p))
            if self.fail('delete',p):self.error=5;result=0
            elif p not in self.files:self.error=2;result=0
            else:del self.files[p]
        elif o==163:
            src,dst=norm(self.text(a[0])),norm(self.text(a[1]));self.events.append(('move',src,dst))
            if self.fail('move',dst):self.error=5;result=0
            elif dst in self.files or dst in self.dirs:self.error=183;result=0
            elif src in self.files:self.files[dst]=self.files.pop(src)
            elif src in self.dirs:
                self.files.update({dst+k[len(src):]:v for k,v in list(self.files.items())if k.startswith(src+'\\')})
                self.files={k:v for k,v in self.files.items()if not k.startswith(src+'\\')}
                changed={d for d in self.dirs if d==src or d.startswith(src+'\\')};self.dirs-=changed;self.dirs|={dst+d[len(src):]for d in changed}
            else:self.error=2;result=0
        elif o==175:
            p=self.handles[a[0]]['path'];self.events.append(('flush',p))
            if self.fail('flush',p):self.error=5;result=0
        elif o==537:
            assert a[0]==0 and a[2]==260;self.wide(a[1],self.module);result=len(self.module)
        elif o==516:result=self.error
        elif o==184:
            for p in a[1:4]:uc.mem_write(p,struct.pack('<II',self.free,0))
        elif o==858:
            s=self.text(a[1]);self.messages.append(s);self.events.append(('message',s))
            result=self.fault.get('confirm',6) if a[3]==0x40024 else 1
        elif o==555:
            assert a[0:2]==[0,1];result=self.handle({'kind':'mutex'});self.error=183 if self.locked else 0
        elif o==556:pass
        elif o==535:result=123456
        elif o==246:assert self.text(a[1])=='STATIC';result=0x4444
        elif o in [256,267,265,870,859]:pass
        elif o==864:result=0
        else:raise AssertionError((dll,o,a))
        self.ret(result)
        if self.stop_at and self.stop_at(self):self.uc.emu_stop()
    def run(self,entry=None,args=(),timeout=60):
        self.setreg(29,STACK);self.setreg(31,RETURN)
        for i,x in enumerate(args):self.setreg(4+i,x)
        saved={r:0x12340000+r for r in range(16,24)};saved[30]=0x12340030
        for r,v in saved.items():self.setreg(r,v)
        started=time.monotonic();self.uc.emu_start(entry or self.syms['entry'],RETURN,timeout=int(timeout*1e6))
        pc=self.uc.reg_read(UC_MIPS_REG_PC)
        if not self.stop_at:
            assert pc==RETURN,('timeout or incomplete execution',hex(pc),time.monotonic()-started)
            assert self.reg(29)==STACK
            assert all(self.reg(r)==v for r,v in saved.items()),'callee-saved ABI'
            assert not self.handles,self.handles
        return self.reg(2)

def inputs():
    rows=json.loads((BASE/'member-plan.json').read_bytes())['members'];files={};dirs={norm('\\MD')}
    for r in rows:
        p='\\'+r['path'].removeprefix('upgrade/').replace('/','\\');b=(BASE/'payload'/r['path']).read_bytes()
        assert len(b)==r['after']['bytes']and sha(b).hex()==r['after']['sha256']
        files[norm('\\MD\\Payload'+p)]=b
        if p!=r'\firmware.hex':files[norm(p)]=b
    files[norm(SCAN)]=b'interrupted settings migration'
    files[norm(STAGE+'\\filecopy_success.bin')]=b'';files[norm(STAGE+'\\kept.bin')]=b'untouched pending payload'
    files[norm(r'\Storage Card2\vehicle-private.cfg')]=b'private settings'
    files[norm(r'\Storage Card3\TFAT\private.cfg')]=b'old migration backup'
    for p in files:
        parent=p.rsplit('\\',1)[0]
        while parent:dirs.add(parent);parent=parent.rsplit('\\',1)[0]
    dirs.add('');return rows,files,dirs

def verify(directory):
    checks=[];rows,files,dirs=inputs()
    # Real native SHA/file handling, with no hash acceleration.
    for n in [0,1,55,56,63,64,65,127,128,4095,4096,16383,16384,16385,32771]:
        b=bytes((i*37+11)&255 for i in range(n));f=Fixture(directory,{norm('\\vector'):b},{''},accelerate=False)
        p,h=0x60010000,0x60011000;f.wide(p,'\\vector');f.uc.mem_write(h,sha(b))
        assert f.run(f.syms['hash_file'],[p,n,h])==1;checks.append(f'native SHA256/file boundary {n}')
    for kind in ['mismatch','read','close','size']:
        b=b'native hashing failure';fault={'api':kind,'path':'\\vector'}if kind!='mismatch'else {}
        f=Fixture(directory,{norm('\\vector'):b},{''},fault,accelerate=False);f.wide(0x60010000,'\\vector');f.uc.mem_write(0x60011000,sha(b if kind!='mismatch'else b'wrong'))
        assert f.run(f.syms['hash_file'],[0x60010000,len(b),0x60011000])==0;checks.append('native hash rejects '+kind)
    for amount in [7,0]:
        b=bytes(range(255))*65;f=Fixture(directory,{norm('\\vector'):b},{''},{'short_reads':amount},accelerate=False)
        f.wide(0x60010000,'\\vector');f.uc.mem_write(0x60011000,sha(b))
        assert f.run(f.syms['hash_file'],[0x60010000,len(b),0x60011000])==bool(amount)
        checks.append('native hash short/zero read '+str(amount))
    print('PASS native SHA256/file boundary and failure checks',flush=True)
    # A small actual packaged file exercises the full native streaming-copy SHA.
    small=next('\\'+r['path'][8:].replace('/','\\')for r in rows if 30<r['after']['bytes']<200 and not r['path'].endswith('Version_Info.txt'))
    version=files[norm(VERSION)];files[norm(VERSION)]=b'7.0.6.MAX18'
    damaged=dict(files);damaged[norm(small)]=b'damaged'
    def intact(f):
        assert f.files[norm(r'\Storage Card2\vehicle-private.cfg')]==b'private settings'
        assert f.files[norm(r'\Storage Card3\TFAT\private.cfg')]==b'old migration backup'
        assert f.files[norm(r'\Storage Card\NK.bin')]==files[norm(r'\Storage Card\NK.bin')]
        assert all(f.files[k]==v for k,v in files.items()if k.startswith('\\md\\payload\\'))
        assert not any(e[0]=='open'and 'firmware.hex'in e[1]and e[2]==0x40000000 for e in f.events)
    for load in [0x10000,0x20000,0x210000,0x17000]:
        f=Fixture(directory,damaged,dirs,load=load);assert f.run()==0;intact(f)
        assert norm(SCAN)not in f.files and norm(PENDING)not in f.files and norm(STAGE)not in f.dirs
        assert f.files[norm(QUAR+'\\kept.bin')]==b'untouched pending payload'
        assert f.files[norm(small)]==files[norm('\\MD\\Payload'+small)]and f.files[norm(VERSION)]==version
        assert f.read(f.syms['phase'])==5
        # Version is never published before native staging is hidden / flag cleared.
        events=f.events;v=next(i for i,e in enumerate(events)if e[0]=='move'and e[2]==norm(VERSION))
        assert next(i for i,e in enumerate(events)if e[0]=='move'and e[1]==norm(STAGE))<v
        assert next(i for i,e in enumerate(events)if e[0]=='delete'and e[1]==norm(SCAN))<v
        checks.append(f'full 1919-member repair, verification/cleanup/version order, ABI and PE relocation at {load:x}')
    print('PASS complete-payload success, relocation and commit-order checks',flush=True)
    cases=[('cancel',{'confirm':7}),('corrupt USB',{'api':'hash','path':'\\MD\\Payload'+small}),
           ('source read',{'api':'read','path':'\\MD\\Payload'+small}),('partial temp write',{'api':'write','path':small+'.max56-new'}),
           ('temp flush',{'api':'flush','path':small+'.max56-new'}),('temp close',{'api':'close','path':small+'.max56-new'}),
           ('temp readback',{'api':'hash','path':small+'.max56-new'}),('delete target',{'api':'delete','path':small}),
           ('rename target',{'api':'move','path':small}),('quarantine',{'api':'move','path':QUAR}),
           ('scan deletion',{'api':'delete','path':SCAN}),('version rename',{'api':'move','path':VERSION}),
           ('receipt creation',{'api':'write','path':PENDING+'.new'}),('receipt flush',{'api':'flush','path':PENDING+'.new'}),
           ('receipt commit',{'api':'move','path':PENDING}),('receipt cleanup',{'api':'delete','path':PENDING}),
           ('USB log write',{'api':'write','path':r'\MD\repair-123456-0.log'})]
    for name,fault in cases:
        f=Fixture(directory,damaged,dirs,fault);assert f.run()==1,(name,f.messages);intact(f)
        assert f.files.get(norm(VERSION))!=version or name=='receipt cleanup'
        if name in ['cancel','corrupt USB','receipt creation','receipt flush','receipt commit','USB log write']:
            assert f.files[norm(small)]==b'damaged'
        else:
            assert f.fired,name
        if name not in ['cancel','corrupt USB']:
            again=Fixture(directory,f.files,f.dirs);assert again.run()==0,(name,again.messages)
            assert again.files[norm(VERSION)]==version and norm(SCAN)not in again.files
        checks.append(name+': failure stops, source/settings retained, retry succeeds when applicable')
    print('PASS injected file failures and retries',flush=True)
    for name in ['missing partition','unknown kernel','unknown updater','running updater','running app','no disk space','bad receipt','both staging dirs','USB absent file','internal launch','already running']:
        f=Fixture(directory,damaged,dirs)
        if name=='missing partition':f.dirs.remove(norm('\\Storage Card4'))
        elif name=='unknown kernel':f.files[norm(r'\Storage Card\NK.bin')]=b'foreign kernel'
        elif name=='unknown updater':f.files[norm(UPDATER)]=b'foreign updater'
        elif name=='running updater':f.processes.append('UpgradeManager.exe')
        elif name=='running app':f.processes.append('AppMain.exe')
        elif name=='no disk space':f.free=1
        elif name=='bad receipt':f.files[norm(PENDING)]=b'truncated'
        elif name=='both staging dirs':f.dirs.add(norm(QUAR))
        elif name=='USB absent file':del f.files[norm('\\MD\\Payload'+small)]
        elif name=='internal launch':f.module=r'\Storage Card\MAX56Repair.exe'
        elif name=='already running':f.locked=True
        assert f.run()==1,(name,f.messages);assert f.installwrites==0,name
        checks.append('preflight rejects '+name+' without internal writes')
    # Lost power after a target was removed: persistent receipt permits retry.
    f=Fixture(directory,damaged,dirs);f.stop_at=lambda x:any(e[0]=='delete'and e[1]==norm(small)for e in x.events)
    f.run();assert norm(small)not in f.files
    again=Fixture(directory,f.files,f.dirs);assert again.run()==0;checks.append('interruption between target delete/move resumes from original USB')
    resumed=dict(f.files);del resumed[norm(UPDATER)]
    again=Fixture(directory,resumed,f.dirs);assert again.run()==0
    assert again.files[norm(UPDATER)]==files[norm('\\MD\\Payload'+UPDATER)]
    checks.append('verified pending receipt permits repair when interrupted updater replacement left updater absent')
    # A resumed repair exercises successful partial writes independently of
    # initial receipt creation (which deliberately requires a complete write).
    again=Fixture(directory,f.files,f.dirs,{'short_reads':11,'short_writes':7});assert again.run()==0
    checks.append('resumed copy handles successful short reads/writes, with native streaming SHA')
    f=Fixture(directory,damaged,dirs);f.stop_at=lambda x:any(e[0]=='move'and e[1]==norm(STAGE)for e in x.events)
    f.run();assert norm(SCAN)in f.files and norm(STAGE)not in f.dirs
    again=Fixture(directory,f.files,f.dirs);assert again.run()==0;checks.append('interruption after staging quarantine and before scan deletion resumes')
    # Exercise two successful log creations with identical boot tick values.
    f=Fixture(directory,damaged,dirs,{'confirm':7});f.run();g=Fixture(directory,f.files,f.dirs,{'confirm':7});g.run()
    logs=[k for k in g.files if k.startswith('\\md\\repair-')];assert len(logs)==2 and logs[0]!=logs[1]
    checks.append('same-tick sessions create distinct logs without overwriting')
    report=dict(passed=True,cases=len(checks),checks=checks,exe_sha256=hashlib.sha256((directory/'MAX56Repair.exe').read_bytes()).hexdigest(),
                full_manifest_members=1919,physical_tested=False,
                limits='Delivered MIPS PE with explicit CE/API/filesystem fixtures; bulk hash_file accelerated with hashlib except native SHA boundary/failure vectors and copy streaming. No CE loader, actual partitions, power durability, USB boot or physical car validation.')
    (directory/'verification.json').write_text(json.dumps(report,indent=2)+'\n');print('PASS',len(checks),'native repair checks');return report

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);a=p.parse_args();verify(a.directory)
