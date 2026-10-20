"""Actual written ROM/MIPS paths with explicit CE APIs, not a device emulator."""
import argparse,itertools,json,shutil,struct
from pathlib import Path
import pefile
from boot_recovery29 import FLAG,RECOVERY,DESKTOP,build_kernel
from build_issue56_usb_recovery import parse,read_va,SOURCE_SHA
from analyze_firmware import nk_info
from verify_ui_english import UiVM
from inspect_bt_pairing import put
import verify_updater_copy_safety as safety
import verify_updater_recovery28 as ui
from verify_issue56_repair import Fixture as UCFixture,norm,API_BASE

ROOT=Path(__file__).resolve().parents[1]
class RomVM(UiVM):
    def word(self,pc):
        assert any(a<=pc<b for a,b in self.ranges),hex(pc)
        return self.read(pc)

class BootFixture(ui.RecoveryFixture):
    def __init__(self,*a,**kw):
        super().__init__(*a,**kw);self.mark_handles=set();self.mark_failures=0;self.flush_ok=True;self.mark_close_ok=True;self.mark_attempts=0
        self.recovery_ok=True;self.desktop_ok=True;self.shell_ok=True;self.shell_calls=0;self.launches=[]
        methods={168:self.api_open,175:self.flush,496:self.sleep,165:self.delete,163:self.move,493:self.process,553:self.api_close,480:self.shell,166:self.api_attrs}
        for d in self.vm.pe.DIRECTORY_ENTRY_IMPORT:
            for e in d.imports:
                if e.ordinal in methods:
                    address=0xf7010000+e.ordinal*4;self.vm.write(e.address,address);self.vm.hooks[address]=methods[e.ordinal]
        if any(e.ordinal==480 for d in self.vm.pe.DIRECTORY_ENTRY_IMPORT for e in d.imports):
            self.vm.ranges.append((0x1114c,0x1119c));self.vm.hooks[0x17d64]=self.zero
    def api_open(self,m):
        p=m.text(m.reg[4])
        if p!=FLAG:return super().api_open(m)
        assert m.reg[5:8]==[0x40000000,3,0]
        assert [m.read(m.reg[29]+i)for i in [16,20,24]]==[2,0x80,0]
        self.mark_attempts+=1;self.log('mark-open')
        if self.mark_attempts<=self.mark_failures:return 0xffffffff
        self.files[norm(FLAG)]=b'';h=self.new_handle();self.mark_handles.add(h);return h
    def api_close(self,m):
        if m.reg[4]in self.mark_handles:self.mark_handles.remove(m.reg[4]);self.log('mark-close');return int(self.mark_close_ok)
        return super().api_close(m)
    def flush(self,m):assert m.reg[4]in self.mark_handles;self.log('mark-flush');return int(self.flush_ok)
    def sleep(self,m):assert m.reg[4]==100;self.log('mark-wait');return 0
    def delete(self,m):
        p=m.text(m.reg[4]);self.log('marker-delete'if p==FLAG else'delete-file',path=p)
        if self.fail('delete',p):self.error=5;return 0
        if norm(p)not in self.files:self.error=2;return 0
        self.files.pop(norm(p));return 1
    def move(self,m):
        a,b=m.text(m.reg[4]),m.text(m.reg[5]);self.log('move-file',source=a,target=b)
        if self.fail('move',b):self.error=5;return 0
        if norm(a)not in self.files:self.error=2;return 0
        if norm(b)in self.files:self.error=183;return 0
        self.files[norm(b)]=self.files.pop(norm(a))
        if self.fail('move_corrupt',b):self.files[norm(b)]=b'corrupt after rename'
        return 1
    def process(self,m):
        p=m.text(m.reg[4]);assert p in [RECOVERY,DESKTOP]
        self.launches.append(p)
        assert m.reg[5:8]==[0,0,0]and all(m.read(m.reg[29]+i)==0 for i in range(16,36,4))
        info=m.read(m.reg[29]+36);assert all(m.read(info+i)==0 for i in [0,4,8,12])
        ok=self.launch_ok and(self.recovery_ok if p==RECOVERY else self.desktop_ok)
        self.log('CreateProcess',application=p,success=ok)
        if not ok:self.error=2;return 0
        self.process_handles.update([0xaaaa0001,0xaaaa0002])
        for j,v in enumerate([0xaaaa0001,0xaaaa0002,123,456]):m.write(info+j*4,v)
        return 1
    def shell(self,m):self.shell_calls+=1;self.log('ShellExecuteEx');return int(self.shell_ok)

def rom_cases(directory):
    source=(ROOT/'extracted/705md/upgrade/Storage Card/NK.bin').read_bytes();raw=(directory/'NK.bin').read_bytes()
    rebuilt,r=build_kernel(source);assert rebuilt==raw
    independent=nk_info(raw);assert independent['all_checksums_valid']and len(independent['records'])==114
    img=parse(raw);base=r['base'];pe=pefile.PE(str(ROOT/'extracted/705md-rom/fs/Windows/ULC_launcher.exe'))
    checks=['ROM image has all 114 independent checksums, unchanged layout and exact deterministic rebuild']
    for flag,present,db,up,rec,desktop,writable in itertools.product([False,True],repeat=7):
        v=RomVM(pe,[(r['guard'],r['guard']+0xa8),(base+0x1268,base+0x12d8),(base+0x12d8,base+0x134c),(base+0x13f4,base+0x14e0),(base+0x150c,base+0x151c)])
        put(v,base+0x1000,read_va(raw,img,r['physical_base']+0x1000,0xc00));launches=[];probes=[];sleep=[];handles=set();counter=[100];marked=[flag];writes=[]
        def openfile(m):
            p=m.text(m.reg[4]);probes.append(p)
            assert m.reg[6:8]==[0,0]and m.read(m.reg[29]+20)==0 and m.read(m.reg[29]+24)==0
            if m.reg[5]==0x40000000:
                assert p==FLAG and m.read(m.reg[29]+16)==2;writes.append(p)
                if not writable:return 0xffffffff
                marked[0]=True;exists=True
            else:
                assert m.reg[5]==0x80000000 and m.read(m.reg[29]+16)==3
                exists=marked[0]if p==FLAG else present
            assert p in [FLAG,r'\Storage Card\System\dboot.exe']
            if not exists:return 0xffffffff
            counter[0]+=1;handles.add(counter[0]);return counter[0]
        def close(m):handles.discard(m.reg[4]);return int(m.reg[4]!=0xffffffff)
        def process(m):
            p=m.text(m.reg[4]);launches.append(p)
            assert m.reg[5:8]==[0,0,0]and all(m.read(m.reg[29]+i)==0 for i in range(16,36,4))
            pi=m.read(m.reg[29]+36);assert all(m.read(pi+i)==0 for i in [0,4,8,12])
            return int({r'\Storage Card\System\dboot.exe':db,r'\Storage Card\System\UpgradeManager.exe':up,RECOVERY:rec,DESKTOP:desktop}[p])
        for i,fn in [(0,close),(4,openfile),(8,process),(16,lambda m:sleep.append(m.reg[4])or 0)]:
            va=0xf7100000+i;v.write(base+0x2000+i,va);v.hooks[va]=fn
        v.hooks[base+0x134c]=lambda m:0
        v.hooks[base+0x150c]=process # unchanged leaf import dispatch to CreateProcessW
        v.hooks[base+0x1934]=lambda m:put(m,m.reg[4],bytes(m.reg[6]))or m.reg[4]
        v.reg[29]=safety.STACK;v.reg[31]=safety.RETURN;saved={n:0x12340000+n for n in range(16,24)}
        for n,x in saved.items():v.reg[n]=x
        v.run(r['main'],{safety.RETURN},limit=2000000)
        assert v.reg[29]==safety.STACK and all(v.reg[n]==x for n,x in saved.items())and not handles
        expected=[]
        if not flag and not writable:
            expected=[DESKTOP]
            if not desktop:expected+=[DESKTOP,RECOVERY]+([]if rec else[DESKTOP])
        elif not flag:
            expected.append(r'\Storage Card\System\dboot.exe')
            if not db:expected.append(r'\Storage Card\System\UpgradeManager.exe')
        if flag or(writable and not(db or up)):
            expected.append(RECOVERY)
            if not rec:expected.append(DESKTOP)
        assert launches==expected,(flag,db,up,rec,desktop,launches,expected)
        assert sleep.count(10)==(0 if present else 200)
        assert sleep.count(100)==(0 if flag or writable else 19*(1 if desktop else 2))
        assert marked[0]==(flag or writable)
        checks.append(f'ROM flag={flag} dboot present={present}/loads={db} updater={up} recovery={rec} desktop={desktop} marker write={writable}: bounded selection/ABI')
    return checks

def application_cases(directory):
    checks=[]
    for filename in ['UpgradeManager.exe','dboot.exe']:
        raw=(directory/filename).read_bytes();recipe=json.loads((directory/(filename+'.json')).read_bytes());ui.RECIPE=recipe;h=recipe['boot_recovery']
        for failures,flush,closed in [(0,True,True),(2,True,True),(20,True,True),(0,False,True),(0,True,False)]:
            f=BootFixture(raw);f.mark_failures=failures;f.flush_ok=flush;f.mark_close_ok=closed
            f.vm.reg[29]=safety.STACK;f.vm.reg[31]=safety.RETURN;f.vm.reg[4:8]=[11,22,33,44]
            saved={n:0x12340000+n for n in [*range(16,24),30]}
            for n,v in saved.items():f.vm.reg[n]=v
            f.vm.run(h['entry'],{h['original_entry'],safety.RETURN},limit=2000000)
            good=failures<20 and flush and closed
            assert f.vm.pc==(h['original_entry']if good else safety.RETURN)
            assert f.vm.reg[29]==safety.STACK and all(f.vm.reg[n]==v for n,v in saved.items())
            if good:assert f.vm.reg[4:8]==[11,22,33,44]and not f.launches
            else:assert f.launches==[RECOVERY]
            assert not f.mark_handles and not f.process_handles
            assert f.mark_attempts==min(failures+1,20)
            checks.append(f'{filename}: marker entry retries={failures}, flush={flush}, close={closed}, old CRT gated/ABI')
        for rec,desktop in itertools.product([False,True],repeat=2):
            f=BootFixture(raw);f.recovery_ok=rec;f.desktop_ok=desktop
            assert f.run(h['launch'],[])==int(rec or desktop)
            assert f.launches==([RECOVERY]if rec else[RECOVERY,DESKTOP])and not f.process_handles
            checks.append(f'{filename}: independent launch rec={rec} desktop={desktop}, initialized PI/arguments, handles closed')
        if filename=='dboot.exe':
            for exists,shell in itertools.product([False,True],repeat=2):
                f=BootFixture(raw,{r'\Storage Card\System\UpgradeManager.exe':b'EXE'}if exists else{});f.shell_ok=shell
                value=f.run(h['shell_wrapper'],[r'\Storage Card\System\UpgradeManager.exe',0])
                assert value==1 and bool(f.launches)==(not(exists and shell))
                assert f.shell_calls==int(exists)
                checks.append(f'DBoot actual exists/shell wrapper missing={not exists}, shell={shell}: recovery fallback')
        else:
            # Old copy/error/paint/touch tests now run the changed executable.
            old=safety.Fixture;safety.Fixture=BootFixture
            try:prior=safety.verify(raw)
            finally:safety.Fixture=old
            checks += ['inherited installer: '+x['name']for x in prior['traces']]
            for code,rec,desktop in itertools.product([112,5001,5002,5003],[False,True],[False,True]):
                f=BootFixture(raw,{FLAG:b'',r'\Storage Card3\TFAT\saved.cfg':b'kept'});f.recovery_ok=rec;f.desktop_ok=desktop;f.vm.write(safety.patcher.CODE,code)
                before=dict(f.files);f.run(safety.patcher.STOP,[])
                assert f.stopped and f.files==before and not f.process_handles
                assert f.launches==([RECOVERY]if rec else[RECOVERY,DESKTOP])
                assert bool([e for e in f.events if e['api']=='ShowWindow'])==(rec or desktop)
                checks.append(f'installer stop {code}: automatic recovery rec={rec} desktop={desktop}; files intact')
            for code,delete_ok,busy in itertools.product([0,5001],[False,True],[False,True]):
                f=BootFixture(raw,{FLAG:b''},fault={}if delete_ok else{'api':'delete'});f.vm.write(safety.patcher.CODE,code)
                f.vm.write(0x38f10,int(busy))
                calls=[];f.vm.hooks[0x2a2e0]=lambda m:calls.append(tuple(m.reg[4:6]))or 77
                f.vm.ranges.append((0x13f2c,0x13f34));f.vm.reg[29]=safety.STACK;f.vm.reg[16]=1;f.vm.reg[23]=0x40000;f.vm.reg[4:6]=[0x5555,1002]
                f.vm.run(0x13f2c,{0x13f34},limit=2000000)
                assert calls==[(0x5555,1002)]and f.vm.read(0x38f44)==1 and f.vm.reg[2]==77
                assert (norm(FLAG)not in f.files)==(code==0 and delete_ok and not busy)
                checks.append(f'actual ready delay-slot store and KillTimer preserved; flag clear code={code}, delete={delete_ok}, busy={busy}')
    return checks

def first_phase_cases(directory):
    raw=(directory/'UpgradeManager.exe').read_bytes();r=json.loads((directory/'UpgradeManager.exe.json').read_bytes());ui.RECIPE=r;h=r['boot_recovery']['first_phase'];checks=[]
    src=r'\Storage Card3\upgrade\Storage Card\NK.bin';dst=r'\Storage Card\NK.bin';bak=r'\Storage Card\NA.bin';temp=r'\Storage Card\NK.MAX29-new'
    for exists,fault in itertools.product([False,True],[{},dict(api='copy',path=src),dict(api='copy',path=dst),dict(api='delete',path=bak),dict(api='move',path=dst),dict(api='move_corrupt',path=dst)]):
        if not exists and (fault==dict(api='copy',path=dst)or fault==dict(api='delete',path=bak)):continue
        files={src:b'new NK bytes',FLAG:b''}
        if exists:files[dst]=b'old NK bytes'
        f=BootFixture(raw,files,fault=fault);f.before={}
        result=f.run(h['replace'],[src,dst,bak,temp])
        if not fault:assert result==1 and not f.stopped and f.files[norm(dst)]==b'new NK bytes'
        else:
            assert f.stopped and f.files[norm(src)]==b'new NK bytes'
            if exists:assert f.files[norm(dst)]==b'old NK bytes'
        if exists and not(fault.get('api')=='copy'):assert f.files[norm(bak)]==b'old NK bytes'
        assert not f.original_format and not f.handles
        checks.append(f'boot-file temporary/backup/readback/rollback exists={exists} fault={fault}')
    upsrc=r'\Storage Card3\upgrade\Storage Card\System\UpgradeManager.exe';uptgt=r'\Storage Card\System\UpgradeManager.exe';upbak=r'\Storage Card\System\OLD_UpgradeManager.exe'
    for fault in [{},dict(api='copy',path=src),dict(api='move',path=dst),dict(api='move',path=uptgt),dict(api='copy',path=upsrc),dict(api='copy',path=uptgt),dict(api='delete',path=src),dict(api='delete',path=upsrc),dict(api='delete',path=FLAG)]:
        f=BootFixture(raw,{src:b'new NK',dst:b'old NK',upsrc:b'new updater',uptgt:b'old updater',upbak:b'older updater'},fault=fault)
        f.vm.hooks[0x2a320]=lambda m:1;f.vm.hooks[0x2a250]=lambda m:0;f.vm.hooks[0x2a0d0]=lambda m:0
        f.vm.hooks[0x17454]=lambda m:int(norm(m.text(m.reg[5]))in f.files)
        f.vm.ranges.append((0x17530,0x17538))
        f.vm.reg[4]=safety.OBJECT;f.vm.reg[29]=safety.STACK;f.vm.reg[31]=safety.RETURN
        boundary=h['native_clone']+0x17778-0x17530
        try:f.vm.run(0x17530,{boundary},limit=2000000)
        except safety.WorkerStopped:pass
        assert (norm(FLAG)in f.files)==bool(fault) and not f.original_format
        if not fault:
            assert f.vm.pc==boundary and f.files[norm(dst)]==b'new NK'and f.files[norm(bak)]==b'old NK'
            assert f.files[norm(uptgt)]==b'new updater'and f.files[norm(upbak)]==b'old updater'
            assert norm(src)not in f.files and norm(upsrc)not in f.files
        else:
            assert f.stopped
            assert f.files[norm(uptgt)]==(b'new updater'if fault in [dict(api='delete',path=upsrc),dict(api='delete',path=FLAG)]else b'old updater')
            if fault.get('path')==dst or fault==dict(api='copy',path=src):assert f.files[norm(dst)]==b'old NK'and norm(src)in f.files
            if fault.get('api')=='delete':assert norm(fault['path'])in f.files
        checks.append(f'actual first-phase native controller: verified NK/self replacement and stop-before-MCU fault={fault}')
    return checks

def manual_cases(directory):
    raw=(directory/'UpgradeManager.exe').read_bytes();recipe=json.loads((directory/'UpgradeManager.exe.json').read_bytes());ui.RECIPE=recipe;checks=[]
    for code in [112,5001]:
        f=BootFixture(raw,{FLAG:b''});f.vm.write(safety.patcher.CODE,code);f.recovery_ok=f.desktop_ok=False
        f.run(safety.patcher.STOP,[]);assert not any(e['api']=='ShowWindow'for e in f.events)
        f.desktop_ok=True;f.run(recipe['recovery']['click'],[400,420])
        assert f.launches==[RECOVERY,DESKTOP,DESKTOP]and not f.process_handles
        assert any(e['api']=='ShowWindow'for e in f.events)and norm(FLAG)in f.files
        checks.append(f'manual desktop retry remains usable after automatic recovery and ROM desktop launch failed, error={code}')
    f=BootFixture(raw);f.vm.reg[4:6]=[400,420];f.vm.reg[29]=safety.STACK;f.vm.reg[31]=safety.RETURN
    f.vm.run(recipe['recovery']['click'],{0x16394,safety.RETURN},limit=100000)
    assert f.vm.pc==0x16394 and f.vm.reg[4:6]==[400,420]and not f.launches
    checks.append('healthy touch continues to original installer handler')
    f=BootFixture(raw);f.vm.write(safety.patcher.CODE,5001);f.vm.write(0x3784c,3007);f.vm.ranges.append((0x14c2c,0x14c3c))
    f.vm.reg[18]=(420<<16)|400;f.vm.reg[29]=safety.STACK;f.vm.run(0x14c2c,{0x14c3c},limit=100000)
    assert f.launches==[DESKTOP]and not f.process_handles
    checks.append('actual native mouse-up reaches independent desktop after hardened boot/installer changes')
    return checks

class MenuFixture(UCFixture):
    def __init__(self,*a,answers=None,desktop=True,mutex=True,**kw):
        super().__init__(*a,accelerate=False,**kw);self.answers=list(answers or[7]);self.desktop_ok=desktop;self.questions=0;self.mutex_ok=mutex
    def api(self,uc,addr,size,user):
        dll,o=self.ordinals[(addr-API_BASE)//8];a=self.args(10)
        if o==555 and not self.mutex_ok:self.ret(0);return
        if o==858:
            text=self.text(a[1]);self.messages.append(text)
            if a[3]==0x40123:
                assert self.answers,'Unexpected repeated recovery prompt';self.questions+=1;value=self.answers.pop(0)
            else:value=1
            self.ret(value);return
        if o==493:
            assert self.text(a[0])==DESKTOP and a[1:9]==[0]*8
            assert [self.read(a[9]+j*4)for j in range(4)]==[0]*4
            if self.desktop_ok:
                x=self.handle(dict(kind='process'));y=self.handle(dict(kind='thread'))
                for j,v in enumerate([x,y,123,456]):self.write(a[9]+4*j,v)
            else:self.desktop_ok=True
            self.ret(int(self.desktop_ok and 'x'in locals()));return
        return super().api(uc,addr,size,user)

def menu_cases(directory):
    view=directory/'menu-view';view.mkdir(exist_ok=True);shutil.copyfile(directory/'Recovery.exe',view/'MAX56Repair.exe');shutil.copyfile(directory/'Recovery.exe.json',view/'build.json')
    checks=[]
    for answers,faildelete,desktop in [([7],False,True),([6],False,True),([2,7],False,True),([6,7],True,True),([7,7],False,False)]:
        f=MenuFixture(view,{norm(FLAG):b''},{'',norm(r'\Storage Card3')},fault={'api':'delete','path':FLAG}if faildelete else{},answers=answers,desktop=desktop)
        assert f.run()==0
        assert(norm(FLAG)not in f.files)==(answers[0]==6 and not faildelete)
        assert not f.handles
        checks.append(f'native recovery menu answers={answers}, delete failure={faildelete}, desktop={desktop}: no installer launch')
    for mutex,answers in [(False,[7]),(True,[0])]:
        f=MenuFixture(view,{norm(FLAG):b''},{'',norm(r'\Storage Card3')},answers=answers,mutex=mutex)
        assert f.run()==(0 if mutex else 1)and norm(FLAG)in f.files and not f.handles
        checks.append(f'recovery menu initialization/UI failure mutex={mutex} answers={answers}: requests ROM desktop without a busy loop')
    return checks

def verify(directory):
    checks=rom_cases(directory);print('PASS ROM fallback cases',flush=True)
    checks+=application_cases(directory);print('PASS application guards and inherited installer',flush=True)
    checks+=first_phase_cases(directory);print('PASS first-phase boot-file replacement/rollback',flush=True)
    checks+=manual_cases(directory)
    checks+=menu_cases(directory)
    result=dict(passed=True,cases=len(checks),checks=checks,physical_tested=False,
                limits='Actual MIPS instructions with explicit CE/filesystem/process/GDI fixtures. ROM boot, mount timing, menu pixels, physical durability, MCU/power and normal startup remain untested. All CreateProcess failures or a nonbooting CE kernel cannot be guaranteed recoverable.')
    (directory/'boot-recovery-verification.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS',len(checks),'boot/recovery cases',flush=True);return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);a=p.parse_args();verify(a.directory.resolve())
