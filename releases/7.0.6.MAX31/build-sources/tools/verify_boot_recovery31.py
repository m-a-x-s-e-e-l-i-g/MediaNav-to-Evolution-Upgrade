"""Exercise intentional CE round trips, real DBoot init and retained error paths."""
import argparse,itertools,json,shutil
from functools import lru_cache
from pathlib import Path
import pefile
from boot_recovery31 import CE,FLAG,DBOOT,RECOVERY,DESKTOP,RECOVERY_COMMAND,build_kernel
from build_max31 import BASE,ROOT
from verify_boot_recovery29 import (RomVM,BootFixture,MenuFixture,application_cases,
    first_phase_cases,manual_cases,UCFixture,API_BASE,safety,ui,norm)
from build_issue56_usb_recovery import parse,read_va
from analyze_firmware import nk_info
from inspect_bt_pairing import put
from debug_image import sha

@lru_cache(maxsize=1)
def rom_input(directory):
    raw=(directory/'NK.bin').read_bytes();r=json.loads((directory/'NK.bin.json').read_bytes())
    base=r['base'];img=parse(raw);pe=pefile.PE(str(ROOT/'extracted/705md-rom/fs/Windows/ULC_launcher.exe'))
    return r,pe,read_va(raw,img,r['physical_base']+0x1000,0xc00)

def rom_one(directory,flag=False,intent=False,present=True,db=True,up=True,rec=True,desktop=True,writable=True):
    r,pe,text=rom_input(directory);base=r['base']
    v=RomVM(pe,[(base+0x1084,base+0x112c),(base+0x1268,base+0x12d8),(base+0x12d8,base+0x134c),
        (base+0x13f4,base+0x14e0),(base+0x150c,base+0x151c)])
    put(v,base+0x1000,text)
    launches=[];sleeps=[];handles=set();counter=[100];marked=[flag]
    def opened(m):
        p=m.text(m.reg[4]);assert p in [FLAG,CE,DBOOT]
        assert m.reg[6:8]==[0,0]and m.read(m.reg[29]+20)==0 and m.read(m.reg[29]+24)==0
        if m.reg[5]==0x40000000:
            assert p==FLAG and m.read(m.reg[29]+16)==2
            if not writable:return 0xffffffff
            marked[0]=True;exists=True
        else:
            assert m.reg[5]==0x80000000 and m.read(m.reg[29]+16)==3
            exists=marked[0]if p==FLAG else intent if p==CE else present
        if not exists:return 0xffffffff
        counter[0]+=1;handles.add(counter[0]);return counter[0]
    def close(m):handles.discard(m.reg[4]);return int(m.reg[4]!=0xffffffff)
    def process(m):
        p=m.text(m.reg[4]);launches.append(p)
        assert m.reg[5:8]==[0,0,0]and all(m.read(m.reg[29]+k)==0 for k in range(16,36,4))
        pi=m.read(m.reg[29]+36);assert all(m.read(pi+k)==0 for k in [0,4,8,12])
        return int({DBOOT:db,r'\Storage Card\System\UpgradeManager.exe':up,RECOVERY:rec,DESKTOP:desktop}[p])
    for off,fn in [(0,close),(4,opened),(8,process),(16,lambda m:sleeps.append(m.reg[4])or 0)]:
        addr=0xf7100000+off;v.write(base+0x2000+off,addr);v.hooks[addr]=fn
    v.hooks[base+0x134c]=lambda m:0;v.hooks[base+0x150c]=process
    v.hooks[base+0x1934]=lambda m:put(m,m.reg[4],bytes(m.reg[6]))or m.reg[4]
    v.reg[29]=safety.STACK;v.reg[31]=safety.RETURN
    saved={k:0x12340000+k for k in range(16,24)}
    for k,x in saved.items():v.reg[k]=x
    v.run(r['main'],{safety.RETURN},limit=2000000)
    assert not handles and v.reg[29]==safety.STACK and all(v.reg[k]==x for k,x in saved.items())
    expected=[]
    def request(path,mark):
        actual=DESKTOP if mark and not writable else path;expected.append(actual)
        return {DBOOT:db,r'\Storage Card\System\UpgradeManager.exe':up,RECOVERY:rec,DESKTOP:desktop}[actual]
    normal=intent or not flag
    if not normal or not(request(DBOOT,True)or request(r'\Storage Card\System\UpgradeManager.exe',True)):
        request(RECOVERY,False)or request(DESKTOP,False)
    assert launches==expected,(flag,intent,launches,expected)
    assert marked[0]==(flag or(normal and writable))
    assert sleeps.count(10)==(0 if present else 200)
    return launches,marked[0]

def rom_cases(directory):
    source=(BASE/'NK.bin').read_bytes();raw=(directory/'NK.bin').read_bytes()
    assert build_kernel(source)[0]==raw
    independent=nk_info(raw);assert independent['all_checksums_valid']and len(independent['records'])==114
    checks=['deterministic ROM patch, all 114 checksums, layout and bytes outside declared ULC edits preserved']
    for args in itertools.product([False,True],repeat=8):
        rom_one(directory,*args)
        checks.append('ROM startup/intent/load/write outcome '+str(args))
    # The same native-marker setup that selected Recovery in MAX30 must select
    # DBoot now. The fallback remains for a marker without explicit CE intent.
    assert rom_one(directory,flag=True,intent=True)[0]==[DBOOT]
    assert rom_one(directory,flag=True,intent=False)[0]==[RECOVERY]
    checks.append('reported stale MAXboot plus StartWinCE false-alarm case takes DBoot; genuine unfinished normal startup still recovers')
    return checks

class DBootFixture(BootFixture):
    def __init__(self,raw,recipe,files=None,**kw):
        ui.RECIPE=recipe;super().__init__(raw,files,**kw);self.gpio=[];self.shortcuts=[];self.shell_paths=[];self.registry=[]
        self.vm.ranges.extend([(0x17998,0x17bc4),(0x1119c,0x111a4),(0x113d4,0x113dc),(0x17f80,0x17f90)])
        self.device_handle=0x81234567
        self.vm.hooks[0x11240]=self.shortcut;self.vm.hooks[0x17850]=lambda m:0
        self.vm.hooks[0x17f80]=lambda m:len(m.text(m.reg[4]))
        methods={456:self.regcreate,464:self.regset,455:lambda m:0,63:lambda m:len(m.text(m.reg[4])),179:self.ioctl}
        for d in self.vm.pe.DIRECTORY_ENTRY_IMPORT:
            for e in d.imports:
                if e.ordinal in methods:
                    addr=0xf7020000+e.ordinal*4;self.vm.write(e.address,addr);self.vm.hooks[addr]=methods[e.ordinal]
    def regcreate(self,m):
        assert m.text(m.reg[5])==r'ControlPanel\Comm'
        m.write(m.read(m.reg[29]+28),0x6666);return 0
    def regset(self,m):self.registry.append(m.text(m.reg[5]));return 0
    def api_open(self,m):
        if m.text(m.reg[4])=='MGR1:':return self.device_handle
        return super().api_open(m)
    def api_close(self,m):
        if m.reg[4]==self.device_handle:return 1
        return super().api_close(m)
    def ioctl(self,m):
        assert m.reg[4:6]==[self.device_handle,2]and m.reg[7]==2
        self.gpio.append([m.read(m.reg[6],1),m.read(m.reg[6]+1,1)]);return 1
    def shortcut(self,m):self.shortcuts.append(m.text(m.reg[4]));return 1
    def shell(self,m):
        path=m.text(m.read(m.reg[4]+16));self.shell_paths.append(path)
        return super().shell(m)

def dboot_cases(directory):
    raw=(directory/'dboot.exe').read_bytes();recipe=json.loads((directory/'dboot.exe.json').read_bytes());h=recipe['desktop_intent']
    checks=[]
    for intent,recovery,oldflag in itertools.product([False,True],repeat=3):
        files={r'\Windows\explorer.exe':b'ROM',r'\Storage Card\System\UpgradeManager.exe':b'UPDATER',
               r'\Storage Card3\upgrade\filecopy_success.bin':b'',r'\Storage Card2\scan_done_flag.bin':b'kept'}
        if intent:files[CE]=b''
        if oldflag:files[FLAG]=b''
        f=DBootFixture(raw,recipe,files);f.vm.reg[29]=safety.STACK;f.vm.reg[31]=safety.RETURN
        put(f.vm,safety.INPUT,(RECOVERY_COMMAND+'\0'if recovery else '\0').encode('utf-16-le'))
        f.vm.reg[4:8]=[0x1234,0,safety.INPUT,5]
        saved={k:0x12340000+k for k in range(16,24)}
        for k,v in saved.items():f.vm.reg[k]=v
        f.vm.run(0x17998,{safety.RETURN},limit=2000000)
        assert f.gpio==[[0,1]]and f.registry==['Cnct','AutoCnct']
        assert f.vm.reg[29]==safety.STACK and all(f.vm.reg[k]==v for k,v in saved.items())
        assert norm(FLAG)in f.files if oldflag and not intent else norm(FLAG)not in f.files
        assert norm(r'\Storage Card2\scan_done_flag.bin')in f.files and norm(r'\Storage Card3\upgrade\filecopy_success.bin')in f.files
        if intent or recovery:
            assert norm(CE)not in f.files and len(f.shortcuts)==2 and f.shell_paths==[DESKTOP]
            assert not f.launches
        else:assert f.shell_paths==[r'\Storage Card\System\UpgradeManager.exe']and not f.shortcuts
        checks.append(f'actual DBoot WinMain intent={intent} recovery-command={recovery} flag={oldflag}: native registry/GPIO before desktop; receipts preserved')
    # Full desktop-to-normal round trip, including the real entry marker guard.
    f=DBootFixture(raw,recipe,{FLAG:b'',CE:b'',DESKTOP:b'ROM'})
    entry=recipe['boot_recovery'];f.vm.reg[29]=safety.STACK;f.vm.reg[31]=safety.RETURN
    f.vm.run(entry['entry'],{entry['original_entry'],safety.RETURN},limit=2000000)
    assert f.vm.pc==entry['original_entry']and norm(FLAG)in f.files
    f.vm.reg[29]=safety.STACK;f.vm.reg[31]=safety.RETURN;put(f.vm,safety.INPUT,b'\0\0');f.vm.reg[4:8]=[0x1234,0,safety.INPUT,5]
    f.vm.run(0x17998,{safety.RETURN},limit=2000000)
    assert norm(FLAG)not in f.files and norm(CE)not in f.files
    assert rom_one(directory,flag=False,intent=False)[0]==[DBOOT]
    checks.append('entry marking -> intentional DBoot desktop -> return boot selects normal DBoot without recovery')
    for failures,flush,closed in [(20,True,True),(0,False,True),(0,True,False)]:
        f=DBootFixture(raw,recipe,{FLAG:b'',DESKTOP:b'ROM'})
        f.mark_failures=failures;f.flush_ok=flush;f.mark_close_ok=closed
        f.vm.reg[29]=safety.STACK;f.vm.reg[31]=safety.RETURN
        put(f.vm,safety.INPUT,(RECOVERY_COMMAND+'\0').encode('utf-16-le'))
        f.vm.reg[4:8]=[0x1234,0,safety.INPUT,5]
        f.vm.run(h['entry'],{h['native_entry'],safety.RETURN},limit=2000000)
        assert f.vm.pc==h['native_entry']and f.mark_attempts==0 and not f.launches
        assert f.vm.reg[4:8]==[0x1234,0,safety.INPUT,5]and f.vm.reg[29]==safety.STACK
        checks.append(f'recovery-only PE entry bypasses marker I/O failures={failures} flush={flush} close={closed}; native CRT args intact')
    for failures,flush,closed in [(0,True,True),(2,True,True),(20,True,True),(0,False,True),(0,True,False)]:
        f=DBootFixture(raw,recipe);f.mark_failures=failures;f.flush_ok=flush;f.mark_close_ok=closed
        f.vm.reg[29]=safety.STACK;f.vm.reg[31]=safety.RETURN;f.vm.reg[4:8]=[11,22,33,44]
        f.vm.run(h['entry'],{h['native_entry'],safety.RETURN},limit=2000000)
        good=failures<20 and flush and closed
        assert f.vm.pc==(h['native_entry']if good else safety.RETURN)
        assert f.vm.reg[29]==safety.STACK and f.mark_attempts==min(failures+1,20)
        if good:assert f.vm.reg[4:8]==[11,22,33,44]and not f.launches
        else:assert f.launches==[RECOVERY]
        checks.append(f'actual updated PE entry retains normal marker gating retries={failures} flush={flush} close={closed}')
    return checks

class Menu31(MenuFixture):
    def __init__(self,*a,dboot=True,**kw):super().__init__(*a,**kw);self.dboot_ok=dboot;self.paths=[]
    def api(self,uc,addr,size,user):
        dll,o=self.ordinals[(addr-API_BASE)//8];a=self.args(10)
        if o==493:
            path=self.text(a[0]);self.paths.append(path)
            assert path in [DBOOT,DESKTOP]and a[2:9]==[0]*7
            assert (self.text(a[1])if a[1]else'')==(RECOVERY_COMMAND if path==DBOOT else'')
            assert [self.read(a[9]+j*4)for j in range(4)]==[0]*4
            ok=self.dboot_ok if path==DBOOT else self.desktop_ok
            if ok:
                for j,v in enumerate([self.handle(dict(kind='process')),self.handle(dict(kind='thread')),123,456]):self.write(a[9]+j*4,v)
            self.ret(int(ok));return
        return super().api(uc,addr,size,user)

def menu_cases(directory):
    view=directory/'menu-view';view.mkdir(exist_ok=True)
    shutil.copyfile(directory/'Recovery.exe',view/'MAX56Repair.exe');shutil.copyfile(directory/'Recovery.exe.json',view/'build.json')
    checks=[]
    for answers,faildelete,db,desktop in [([7],False,True,True),([7],False,False,True),
        ([6],False,True,True),([2,7],False,True,True),([6,7],True,True,True),([0],False,True,True)]:
        f=Menu31(view,{norm(FLAG):b''},{'',norm(r'\Storage Card3')},fault={'api':'delete','path':FLAG}if faildelete else{},
                 answers=answers,dboot=db,desktop=desktop)
        assert f.run()==0 and not f.handles
        assert(norm(FLAG)not in f.files)==(answers[0]==6 and not faildelete)
        assert f.paths==([DBOOT]if db else[DBOOT,DESKTOP])
        checks.append(f'native recovery answers={answers} delete-failure={faildelete} DBoot={db}: desktop uses native DBoot, no updater dispatch')
    return checks

def inherited(directory):
    # Unchanged feature/runtime code is reused only with byte-level proof;
    # Cmn differs solely in the revision string and its PE checksum.
    plan=json.loads((directory/'member-plan.json').read_bytes());old=json.loads((BASE/'verification.json').read_bytes())
    assert old['passed']and old['cases']==996
    for row in plan['members']:
        if row['path']not in plan['changed_members']:assert row['before']==row['after']
    a=(BASE/'CmnDll.dll').read_bytes();b=(directory/'CmnDll.dll').read_bytes()
    r=json.loads((directory/'CmnDll.dll.json').read_bytes())['revision_only_from_MAX30'];off=r['header_offset'];cs=r['checksum_offset']
    assert len(a)==len(b)and all(x==y or off<=j<off+64 or cs<=j<cs+4 for j,(x,y)in enumerate(zip(a,b)))
    for n in ['AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe','UpgradeManager.exe','nng/nngnavi.exe']:
        assert sha((BASE/n).read_bytes())==sha((directory/n).read_bytes())
    checks=[]
    for name in ['inherited-verification.json','quiet-logging-verification.json']:
        r=json.loads((BASE/name).read_bytes());assert r['passed'];checks+=r['checks']
    return dict(passed=True,cases=len(checks),checks=checks,reused_from=str(BASE),
        scope='Application, navigation and quiet logging bytes exact except diagnostic revision/checksum. Changed boot/menu have new tests.')

def verify(directory,reuse=None):
    if reuse:
        old=json.loads((reuse/'boot-recovery-verification.json').read_bytes());assert old['passed']
        before=pefile.PE(str(reuse/'dboot.exe'));after=pefile.PE(str(directory/'dboot.exe'))
        recipe=json.loads((reuse/'dboot.exe.json').read_bytes())
        for row in recipe['helper_rows']:
            assert before.get_data(row[0]-before.OPTIONAL_HEADER.ImageBase,row[1]-row[0])==after.get_data(row[0]-after.OPTIONAL_HEADER.ImageBase,row[1]-row[0])
        for section in before.sections[:5]:
            assert section.get_data()==after.get_data(section.VirtualAddress,section.SizeOfRawData)
        for name in ['NK.bin','Recovery.exe','UpgradeManager.exe','CmnDll.dll','nng/nngnavi.exe']:
            assert sha((reuse/name).read_bytes())==sha((directory/name).read_bytes()),name
        checks=[x for x in old['checks']if not x.startswith(('actual DBoot WinMain','entry marking ->','dboot.exe: marker entry'))]
        checks+=dboot_cases(directory)
        print('PASS unchanged ROM/menu/updater proof and updated actual DBoot/PE-entry checks',flush=True)
    else:
        checks=rom_cases(directory);print('PASS ROM intent/fallback',flush=True)
        checks+=dboot_cases(directory);print('PASS actual DBoot initialization and CE round trip',flush=True)
        checks+=application_cases(directory)+first_phase_cases(directory)+manual_cases(directory)
        print('PASS retained entry, updater, copy, rollback and desktop controls',flush=True)
        checks+=menu_cases(directory)
    for n in ['dboot.exe','Recovery.exe','CmnDll.dll']:
        p=pefile.PE(str(directory/n));assert p.verify_checksum()
        assert all(not(s.Characteristics&0x20000000 and s.Characteristics&0x80000000)for s in p.sections)
    if not reuse:checks.append('changed PE checksums and no writable executable sections')
    r=dict(passed=True,cases=len(checks),checks=checks,physical_tested=False,
        limits='Actual written MIPS with CE APIs as fixtures. Real CE mount timing, process loading, desktop power stability and round trip require the owner test.')
    if reuse:r.update(reused_from=str(reuse),reused_code_and_component_bytes_verified=True,
        new_checks='Actual updated PE entry, marker faults, recovery read-only path, native DBoot WinMain and desktop round trip')
    (directory/'boot-recovery-verification.json').write_text(json.dumps(r,indent=2)+'\n')
    previous=inherited(directory);(directory/'inherited-verification.json').write_text(json.dumps(previous,indent=2)+'\n')
    result=dict(passed=True,cases=len(checks)+previous['cases'],checks=previous['checks']+checks,car_tested=False,
                limits=[r['limits'],'iPhone artwork and remaining installer audit gaps are unchanged.'])
    (directory/'verification.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS',result['cases'],'combined checks',flush=True)
    return result

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--reuse-unchanged-from',type=Path)
    a=p.parse_args();verify(a.directory.resolve(),a.reuse_unchanged_from.resolve()if a.reuse_unchanged_from else None)
