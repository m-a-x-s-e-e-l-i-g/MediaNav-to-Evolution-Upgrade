"""Execute the standalone collector MIPS PE against read-only CE fixtures."""
import argparse, hashlib, json, struct, sys, tempfile, zlib
from pathlib import Path
FROZEN=Path(__file__).resolve().parents[1]/'releases/7.0.6.MAX34/build-sources/tools'
if FROZEN.is_dir():sys.path.append(str(FROZEN))
from verify_issue56_repair import Fixture,norm,API_BASE
from inspect_vehicle_config import inspect
from unicorn import UC_HOOK_CODE

MICOM=norm(r'\Storage Card\System\MicomManager.exe')
DSI=norm(r'\Storage Card\System\DSI_config.bsd')
ECO=norm(r'\Storage Card2\EcoDrive.cfg')
MGR=norm(r'\Storage Card2\MgrSys.cfg')

class Probe(Fixture):
    def __init__(self,directory,raw,fault=None,load=0x10000,native_hash=False):
        b=bytearray(32);b[:8]=bytes([1,1,1,6,0,3,1,64]);b+=struct.pack('<I',zlib.crc32(b))
        mgr=bytearray(128);struct.pack_into('<I',mgr,96,1)
        files={MICOM:raw,DSI:bytes(b),ECO:bytes(9),MGR:bytes(mgr),norm(r'\Storage Card\System\Version_Info.txt'):b'7.0.6.MAX33'}
        dirs={'',norm(r'\MD'),norm(r'\Storage Card'),norm(r'\Storage Card\System'),norm(r'\Storage Card2')}
        super().__init__(directory,files,dirs,fault,load,accelerate=False)
        self.raw_micom=raw;self.sleep_count=0;self.processes=['MicomManager.exe'];self.regs={'UI_TYPE':1,'UI_INVERSE':1,'HMI_TEMP_CNF':1}
        self.openproc=[];self.rpm_calls=[]
        if not native_hash:self.uc.hook_add(UC_HOOK_CODE,self.fast_pin,begin=self.syms['pinned'],end=self.syms['pinned'])
    def fast_pin(self,uc,addr,size,user):self.ret(int(hashlib.sha256(self.files.get(MICOM,b'')).hexdigest()=='b93cb55a66c843e1bb5ea34fd58642e451e6b07afcf9f8ccd1fbc762d627e629'))
    def api(self,uc,addr,size,user):
        dll,o=self.ordinals[(addr-API_BASE)//8];a=self.args(12);result=1
        if dll=='toolhelp.dll'and o in [10,11]:
            if o==11:self.process_at+=1
            if self.process_at>=len(self.processes):result=0;self.error=18
            else:
                assert self.read(a[1])==564
                self.write(a[1]+8,1000);self.wide(a[1]+36,self.processes[self.process_at]);self.write(a[1]+556,0x10000 if not self.fault.get('bad_base')else 0x20000)
        elif dll=='coredll.dll'and o==168:
            p=norm(self.text(a[0]));access,share,create=a[1],a[2],a[4]
            if access==0x40000000:assert p.startswith('\\md\\maxmade\\vehicle-config-')and create==1
            else:
                assert access==0x80000000 and create==3 and share==3
                self.setreg(6,1) # base fixture expects FILE_SHARE_READ; log original sharing separately
            return super().api(uc,addr,size,user)
        elif dll=='coredll.dll'and o==461:
            assert a[0]==0x80000002 and self.text(a[1])=='LGE\\SystemInfo'and a[2]==0 and a[3]==0x20019
            result=5 if self.fault.get('registry_denied')else 0
            if not result:self.write(a[4],self.handle({'kind':'registry'}))
        elif dll=='coredll.dll'and o==463:
            assert self.handles[a[0]]['kind']=='registry'and a[2]==0 and self.read(a[5])==4
            name=self.text(a[1]);value=self.regs.get(name)
            if value is None:result=2
            else:self.write(a[3],1 if self.fault.get('wrong_reg_type')else 4);self.write(a[4],value);self.write(a[5],4)
        elif dll=='coredll.dll'and o==455:del self.handles[a[0]];result=0
        elif dll=='coredll.dll'and o==509:
            assert a[:3]==[0x10,0,1000];self.openproc.append(a[:3]);result=0 if self.fault.get('openprocess_denied')else self.handle({'kind':'process'})
        elif dll=='coredll.dll'and o==506:
            assert self.handles[a[0]]['kind']=='process';self.rpm_calls.append((a[1],a[3]));b=None
            if a[1]==0x14090 and a[3]==32:
                import pefile
                b=pefile.PE(data=self.raw_micom).get_data(0x4090,32)
                if self.fault.get('memory_mismatch'):b=bytes(32)
            elif a[1]==0x64888 and a[3]==4:b=struct.pack('<I',3 if self.fault.get('bad_pointer')else 0x50000000)
            elif a[1]==0x50000000 and a[3]==36:
                values=[0]*9;values[4]=3 if self.sleep_count<10 else 255;values[5]=59;values[6]=1;values[8]=1;b=struct.pack('<9I',*values)
            if b is None or self.fault.get('rpm_denied'):self.write(a[4],0);result=0
            else:uc.mem_write(a[2],b);self.write(a[4],len(b))
        elif dll=='coredll.dll'and o==496:assert a[0]==500;self.sleep_count+=1
        elif dll=='coredll.dll'and o==160:
            assert norm(self.text(a[0])).startswith('\\md\\maxmade')
            return super().api(uc,addr,size,user)
        else:return super().api(uc,addr,size,user)
        self.ret(result)

def verify(directory,module):
    raw=module.read_bytes();checks=[]
    cases=[('normal',{}),('relocated',{}),('short reads',{'short_reads':3}),('short writes',{'short_writes':3}),
        ('missing USB',{}),('file pin mismatch',{}),('missing process',{}),('wrong base',{'bad_base':True}),
        ('openprocess denied',{'openprocess_denied':True}),('memory pin mismatch',{'memory_mismatch':True}),
        ('RAM denied',{'rpm_denied':True}),('bad pointer',{'bad_pointer':True}),('registry denied',{'registry_denied':True}),
        ('wrong registry type',{'wrong_reg_type':True}),('USB log write failure',{'api':'write'}),('USB flush failure',{'api':'flush'}),
        ('DSI read failure',{'api':'read','path':DSI}),('oversized DSI',{}),('truncated MgrSys',{}),('native file/SHA pin',{})]
    for name,fault in cases:
        f=Probe(directory,raw,fault,load=0x210000 if name=='relocated'else 0x10000,native_hash=name=='native file/SHA pin')
        assert set(f.ordinals)=={('coredll.dll',o)for o in [168,170,171,553,172,166,160,175,516,858,535,496,461,463,455,509,506]}|{('toolhelp.dll',o)for o in [2,10,11,1]}
        if name=='missing USB':f.dirs.remove(norm(r'\MD'))
        if name=='file pin mismatch':f.files[MICOM]=b'foreign version'
        if name=='missing process':f.processes=[]
        if name=='oversized DSI':f.files[DSI]+=b'extra'
        if name=='truncated MgrSys':f.files[MGR]=bytes(97)
        before=dict(f.files);result=f.run(timeout=60)
        assert result==int(name in ['missing USB','USB log write failure','USB flush failure']),(name,result,f.messages)
        assert all(f.files[k]==v for k,v in before.items()),name
        assert all(k.startswith('\\md\\maxmade\\vehicle-config-')for k in set(f.files)-set(before)),name
        assert f.installwrites==0 and not f.handles,name
        # Output paths use CE separators, independent of host OS.
        outputs={k.rsplit('\\',1)[-1]:v for k,v in f.files.items()if k not in before}
        capture=outputs.get('capture.txt',b'').decode('ascii')
        if name in ['normal','relocated','short reads','short writes','native file/SHA pin']:
            assert 'current_raw=3'in capture and 'current_raw=255'in capture and capture.count('temp sample=')==20,name
            assert outputs['dsi_config.bsd']==before[DSI]and outputs['mgrsys.cfg']==before[MGR]
        if name in ['file pin mismatch','missing process','wrong base','openprocess denied','memory pin mismatch','RAM denied']:
            assert 'current_raw='not in capture and 'ram skipped_'in capture,name
        if name=='bad pointer':assert 'current_raw='not in capture and 'unavailable_pointer'in capture
        if name=='oversized DSI':assert 'dsi_config.bsd'not in outputs
        if name=='wrong registry type':assert ' value='not in capture
        if name=='normal':
            with tempfile.TemporaryDirectory()as temp:
                root=Path(temp)
                for n,b in outputs.items():
                    names={'dsi_config.bsd':'DSI_config.bsd','ecodrive.cfg':'EcoDrive.cfg','mgrsys.cfg':'MgrSys.cfg'}
                    (root/names.get(n,n)).write_bytes(b)
                r=inspect(root);assert r['dsi']['usable_by_native_loader']and r['dsi']['profile_bits']==1
                assert r['eco']['xor_valid']and r['mgrsys']['inverse_preference']==1
                assert r['capture_complete']and r['temperature_samples'][0]['native_celsius_if_units_1']==-37
                assert r['temperature_samples'][-1]['native_invalid_sentinel']
        checks.append(name+': delivered MIPS PE; internal files unchanged and output confined to fresh USB files')
        print('PASS',name,flush=True)
    # Repeat with the exact same tick: never overwrite previous captures.
    f=Probe(directory,raw);f.run();g=Probe(directory,raw);g.files=dict(f.files);g.dirs=set(f.dirs);g.run()
    assert all(g.files[k]==v for k,v in f.files.items());assert len([k for k in g.files if k.endswith('capture.txt')])==2
    checks.append('same-tick repeat uses a fresh directory and preserves previous output')
    report=dict(passed=True,cases=len(checks),checks=checks,exe_sha256=hashlib.sha256((directory/'MAX56Repair.exe').read_bytes()).hexdigest(),physical_tested=False,
        limits='Actual MIPS code with mocked CE APIs/filesystem/process RAM. Native file/SHA pin executed in one case; other cases accelerate only the exact file-hash comparison. No CE loader, physical device, firmware fix or original packet capture established.')
    return report

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);p.add_argument('--micom',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=verify(a.build/'fixture',a.micom);a.output.write_text(json.dumps(r,indent=2)+'\n');print('PASS',r['cases'],'collector cases')
