"""Execute written MAX33 updater hooks and recovery-menu MIPS with CE fixtures."""
import argparse,itertools,json,struct
from pathlib import Path
import pefile
from inspect_bt_pairing import put
from verify_boot_recovery29 import BootFixture
import verify_updater_recovery28 as ui
import verify_updater_copy_safety as safety
from verify_issue56_repair import Fixture,norm
from installer_resume33 import COMPLETION
from verify_installer33 import STAGE,PENDING,COMPLETE,VERSION,ENGINE,RECOVERY,BOOT
from package_max16 import write

class Native(BootFixture):
    def __init__(self,*args,**kw):
        super().__init__(*args,**kw);self.child_exit=0;self.wait_result=0;self.commit=True;self.bad_commit=None;self.waited=False;self.command_launches=[]
        for desc in self.vm.pe.DIRECTORY_ENTRY_IMPORT:
            for imp in desc.imports:
                methods={497:self.wait,519:self.exitcode,494:self.event}
                if imp.ordinal in methods:
                    address=0xf5010000+imp.ordinal*4;self.vm.write(imp.address,address);self.vm.hooks[address]=methods[imp.ordinal]
    def api_read(self,m):
        if m.reg[6]==4096:return super().api_read(m)
        assert m.reg[6]in [11,len(COMPLETION)] and m.read(m.reg[29]+16)==0
        h=self.handles[m.reg[4]];b=self.files[h['path']][h['pos']:h['pos']+m.reg[6]];put(m,m.reg[5],b);m.write(m.reg[7],len(b));h['pos']+=len(b);return 1
    def process(self,m):
        p,cmd=m.text(m.reg[4]),(m.text(m.reg[5])if m.reg[5]else'');self.command_launches.append((p,cmd));self.launches.append(p)
        assert p in [ENGINE,RECOVERY,r'\Windows\explorer.exe']
        assert m.reg[6:8]==[0,0] and all(m.read(m.reg[29]+i)==0 for i in range(16,36,4))
        pi=m.read(m.reg[29]+36);assert all(m.read(pi+i)==0 for i in [0,4,8,12])
        if not self.launch_ok or(p==RECOVERY and not self.recovery_ok)or(p==r'\Windows\explorer.exe'and not self.desktop_ok):self.error=2;return 0
        self.process_handles.update([0xaaaa0001,0xaaaa0002])
        for j,v in enumerate([0xaaaa0001,0xaaaa0002,123,456]):m.write(pi+j*4,v)
        if p==ENGINE and cmd in ['-MAX33Install','-MAX33Resume']:
            assert m.read(safety.patcher.CODE)==6001 and m.read(0x3784c)==3008
        return 1
    def wait(self,m):
        assert m.reg[4]==0xaaaa0001 and m.reg[5]==0xffffffff;self.waited=True
        if self.commit:
            self.files[norm(COMPLETE)]=COMPLETION;self.files[norm(VERSION)]=b'7.0.6.MAX33';self.files.pop(norm(PENDING),None)
            self.files={p:b for p,b in self.files.items()if not p.startswith(norm(STAGE)+'\\')};self.dirs={p for p in self.dirs if p!=norm(STAGE)and not p.startswith(norm(STAGE)+'\\')}
            if self.bad_commit=='receipt':self.files[norm(COMPLETE)]=b'wrong'
            elif self.bad_commit=='version':self.files[norm(VERSION)]=b'7.0.6.MAX32'
            elif self.bad_commit=='pending':self.files[norm(PENDING)]=b'not removed'
            elif self.bad_commit=='stage':self.dirs.add(norm(STAGE))
        return self.wait_result
    def exitcode(self,m):assert m.reg[4]==0xaaaa0001;m.write(m.reg[5],self.child_exit);return 1
    def event(self,m):assert m.reg[4]==0x8888 and m.reg[5]==3;self.log('monitor-success-event');return 1
    def message(self,m):self.log('MessageBox',text=m.text(m.reg[5]));return 1

class Menu(Fixture):
    def __init__(self,directory,files=None,answers=None,command=''):
        super().__init__(directory/'menu/fixture',files or {},{''},accelerate=False)
        self.answers=list(answers or []);self.command=command;self.launches=[];self.failed_launches=set()
    def api(self,uc,addr,size,user):
        dll,o=self.ordinals[(addr-0x7e000000)//8];a=self.args(12)
        if o==1231:self.wide(0x60090000,self.command);self.ret(0x60090000);return
        if o==493:
            p,cmd=self.text(a[0]),self.text(a[1]);assert a[2:9]==[0]*7;self.launches.append((p,cmd))
            if p in self.failed_launches:self.error=2;self.ret(0);return
            for j,v in enumerate([self.handle({'kind':'process'}),self.handle({'kind':'thread'}),9,10]):self.write(a[9]+4*j,v)
            self.ret(1);return
        if o==858:
            self.messages.append(self.text(a[1]));self.ret(self.answers.pop(0)if a[3]==0x40123 else 1);return
        super().api(uc,addr,size,user)

def verify(directory):
    raw=(directory/'UpgradeManager.exe').read_bytes();r=json.loads((directory/'UpgradeManager.exe.json').read_bytes());ui.RECIPE=r;h=r['resume33'];checks=[]
    # Baseline original settings/MCU paths stay byte exact. Only reviewed entry
    # hooks, appended helpers, PE metadata/import additions may differ.
    baseline=(directory.parents[0]/'max32-iphone-release-01/payload/upgrade/Storage Card/System/UpgradeManager.exe').read_bytes()
    old=pefile.PE(data=baseline);new=pefile.PE(data=raw)
    for a,b,label in [(0x14eb0,0x15304,'native settings migration before application handoff'),(0x1530c,0x154b0,'native controller after application handoff'),(0x17538,0x178d0,'first-stage firmware/controller body')]:
        assert old.get_data(a-0x10000,b-a)==new.get_data(a-0x10000,b-a),label;checks.append('unchanged baseline instructions: '+label)
    files={STAGE+r'\filecopy_success.bin':b'',STAGE+VERSION:b'7.0.6.MAX33',STAGE+r'\Storage Card\InstallResume.exe':b'worker bootstrap bytes',STAGE+r'\Storage Card\Recovery.exe':b'recovery bootstrap bytes',ENGINE:b'old worker',RECOVERY:b'old recovery',BOOT:b''}
    f=Native(raw,files);assert f.run(h['bootstrap'],[])==1
    assert f.files[norm(ENGINE)]==b'worker bootstrap bytes' and f.files[norm(RECOVERY)]==b'recovery bootstrap bytes'
    assert all(f.files[norm(p)]==v for p,v in files.items()if p.startswith(STAGE))
    checks.append('native bootstrap verifies exact candidate version and extraction marker then copies/readbacks worker and recovery with backups, retaining source')
    for name in ['wrong version','missing extraction','copy failure','rename failure']:
        state=dict(files);fault={}
        if name=='wrong version':state[STAGE+VERSION]=b'7.0.6.MAX32'
        elif name=='missing extraction':del state[STAGE+r'\filecopy_success.bin']
        elif name=='copy failure':fault=dict(api='copy',path=STAGE+r'\Storage Card\InstallResume.exe')
        else:fault=dict(api='move',path=ENGINE)
        f=Native(raw,state,fault=fault);value=f.run(h['bootstrap'],[])
        assert f.stopped or value==0;assert f.files[norm(ENGINE)]==b'old worker' and f.files[norm(RECOVERY)]==b'old recovery'
        assert not f.original_format;checks.append('bootstrap refuses/rolls back without settings migration: '+name)
    for staged in [False,True]:
        f=Native(raw,files if staged else{});assert f.run(h['startup'],[])==1 and f.original_called
        assert not f.original_format;checks.append('healthy native settings entry preserved staged='+str(staged))
    for entry,cmd in [(h['delegate'],'-MAX33Install'),(h['startup'],'-MAX33Resume')]:
        for failure in ['none','child error','wait timeout','no commit','receipt','version','pending','stage','spawn failure']:
            f=Native(raw,{PENDING:b'own receipt',BOOT:b'',STAGE+r'\filecopy_success.bin':b''});f.before={};f.vm.write(0x38f34,0x8888)
            if failure=='child error':f.child_exit=1
            elif failure=='wait timeout':f.wait_result=258
            elif failure=='no commit':f.commit=False
            elif failure=='spawn failure':f.launch_ok=False
            elif failure!='none':f.bad_commit=failure
            value=f.run(entry,[cmd]if entry==h['delegate']else[])
            if failure=='none':assert value==1 and not f.stopped and f.vm.read(safety.patcher.CODE)==0 and f.vm.read(0x3784c)==3000
            else:assert f.stopped and f.vm.read(safety.patcher.CODE)==5005 and f.vm.read(0x3784c)==3007
            assert not f.original_called and not f.original_format and not f.process_handles
            assert f.command_launches[0]==(ENGINE,cmd);checks.append('native '+cmd+' success contract / failure stop: '+failure)
    for rec,desktop in itertools.product([False,True],repeat=2):
        f=Native(raw,{BOOT:b''});f.recovery_ok=rec;f.desktop_ok=desktop;f.run(h['recovery_noauto'],[])
        assert f.command_launches==([(RECOVERY,'-MAX33NoAuto')]if rec else[(RECOVERY,'-MAX33NoAuto'),(r'\Windows\explorer.exe','')])
        assert not f.process_handles;checks.append(f'bounded NoAuto recovery/fallback rec={rec} desktop={desktop}')
    for x,y,expected in [(40,290,ENGINE),(759,364,ENGINE),(40,380,r'\Windows\explorer.exe'),(759,459,r'\Windows\explorer.exe'),(39,300,None),(760,300,None),(400,365,None),(400,460,None)]:
        f=Native(raw);f.vm.write(safety.patcher.CODE,5001);f.vm.write(0x3784c,3007);f.run(h['click'],[x,y])
        assert f.launches==([expected]if expected else[])
        if expected==ENGINE:assert f.command_launches==[(ENGINE,'-MAX33Repair')]
        checks.append(f'independent repair/desktop touch boundary {x},{y}')
    for error in [0,5001,5005]:
        f=Native(raw);f.vm.write(safety.patcher.CODE,error);f.vm.write(0x3784c,3007 if error else 3000)
        f.run(safety.patcher.PAINT,[safety.OBJECT,0x5555]);labels=[e['text']for e in f.events if e['api']=='DrawTextW']
        assert ('Repair / resume update'in labels)==bool(error) and('Open recovery desktop'in labels)==bool(error)
        checks.append('native repaint includes both recovery controls error='+str(error))
    # Real new menu control flow including cancel/retry and no automatic retry on software failure.
    for pending,command,answers,expected in [
        (True,'',[],[(ENGINE,'-MAX33Resume')]),
        (True,'-MAX33NoAuto',[6],[(ENGINE,'-MAX33Repair')]),
        (True,'-MAX33NoAuto',[2,7],[(r'\Storage Card\System\dboot.exe','-MAXmadeRecoveryCE')]),
        (False,'',[6],[(r'\Storage Card\System\dboot.exe','-MAXmadeRecoveryCE')]),
        (False,'',[7],[(r'\Storage Card\System\dboot.exe','-MAXmadeRecoveryCE')])]:
        f=Menu(directory,{norm(PENDING):b'receipt',norm(BOOT):b''}if pending else{norm(BOOT):b''},answers,command);assert f.run()==0 and f.launches==expected
        assert (norm(BOOT)not in f.files)==(not pending and answers==[6]);checks.append(f'recovery menu pending={pending}, command={command}, answers={answers}')
    f=Menu(directory,{norm(PENDING):b'receipt',norm(BOOT):b''},[7]);f.failed_launches={ENGINE,r'\Storage Card\System\dboot.exe'};assert f.run()==0
    assert f.launches==[(ENGINE,'-MAX33Resume'),(r'\Storage Card\System\dboot.exe','-MAXmadeRecoveryCE'),(r'\Windows\explorer.exe','')]
    assert norm(BOOT)in f.files;checks.append('automatic worker launch failure still permits native DBoot/ROM desktop fallback without clearing pending boot marker')
    previous=safety.Fixture;safety.Fixture=Native
    try:inherited=safety.verify(baseline)
    finally:safety.Fixture=previous
    start=safety.patcher.COPY;end=safety.patcher.TEXT+safety.patcher.TEXT_BYTES
    assert old.get_data(start-0x10000,end-start)==new.get_data(start-0x10000,end-start)
    checks += ['byte-identical inherited installer helpers: '+c['name']for c in inherited['traces']]
    report=dict(passed=True,cases=len(checks),checks=checks,physical_tested=False,limits='Written MIPS and explicit CE/file/process/GDI fixtures; no CE loader, pixels, MCU or power-loss durability proof')
    write(directory/'native-verification.json',report);print('PASS',len(checks),'native updater/recovery checks',flush=True);return report

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--stage',type=Path,required=True);verify(p.parse_args().stage.resolve())
