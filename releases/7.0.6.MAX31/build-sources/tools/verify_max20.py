"""Actual MIPS persistence, non-overwriting files and repaint regression fixtures."""
import argparse,json,struct
from pathlib import Path
import verify_max19 as old
from package_max16 import write


class Fixture(old.Fixture):
    def __init__(self,root):
        super().__init__(root)
        self.positions={};self.durable={};self.config_fail=None;self.collisions=0
    def rebase(self,delta):
        from verify_usb_input_safety import relocated
        import pefile
        pe=pefile.PE(data=self.raw);moved=bytearray(relocated(self.raw,delta))
        # Shared legacy helper assumes executable base 0x10000; restore DLL base.
        struct.pack_into('<I',moved,pe.OPTIONAL_HEADER.get_field_absolute_offset('ImageBase'),pe.OPTIONAL_HEADER.ImageBase+delta)
        self.vm=old.VM(bytes(moved));self.D+=delta
        self.A={k:v+delta for k,v in self.A.items()}
        self.vm.write(self.D+0x38,1)
        for d in self.vm.pe.DIRECTORY_ENTRY_IMPORT:
            for s in d.imports:
                target=0xf1000000+s.ordinal*16;self.vm.write(s.address,target)
                self.vm.hooks[target]=lambda m,o=s.ordinal:self.api(o,m)
    def api(self,o,m):
        a=m.reg[4:8];sp=m.reg[29]
        if o in [168,170,171,175,553]:
            self.calls.append((o,list(a)));self.last=1000+o
            if o==168:
                path=self.text(a[0]);mode=m.read(sp+16);cfg=path.startswith('\\Storage Card2\\MAXmade\\debug-')
                assert cfg or path.startswith('\\MD\\MAXmade\\logs\\debug-')
                if self.fail==o or (cfg and (self.reg_fail or self.config_fail=='open')):
                    self.last=5;return 0xffffffff
                if mode==3:
                    assert cfg and a[1]==0x80000000
                    if path not in self.files:self.last=2;return 0xffffffff
                elif cfg:
                    assert mode==2 and a[1]==0x40000000 and m.read(sp+20)==0x80000080
                    self.files[path]=bytearray()
                else:
                    assert mode==1 and a[1]==0x40000000
                    if self.collisions:
                        self.collisions-=1;self.last=80;return 0xffffffff
                    if path in self.files:self.last=183;return 0xffffffff
                    self.files[path]=bytearray()
                self.handle+=1;self.handles[self.handle]=path;self.positions[self.handle]=0
                return self.handle
            if o==553:
                self.handles.pop(a[0],None);return 1
            assert a[0] in self.handles
            path=self.handles[a[0]];cfg=path.endswith('.cfg')
            if o==170:
                assert cfg
                if self.config_fail=='read':return 0
                pos=self.positions[a[0]];data=self.files[path][pos:pos+a[2]]
                for j,b in enumerate(data):m.write(a[1]+j,b,1)
                self.positions[a[0]]+=len(data);m.write(a[3],len(data));return 1
            if o==171:
                assert not self.queue_held,'disk write while holding producer mutex'
                data=bytes(m.read(a[1]+j,1) for j in range(a[2]))
                short=self.short_write or (cfg and self.config_fail=='short')
                n=len(data)-(2 if short else 0)
                self.files[path]+=data[:n];m.write(a[3],n)
                return 0 if self.write_fail or (cfg and self.config_fail=='write') else 1
            if o==175:
                if self.flush_fail or (cfg and self.config_fail=='flush'):return 0
                self.durable[path]=bytearray(self.files[path]);return 1
        return super().api(o,m)


class VM(old.VM):
    def __init__(self,raw):
        super().__init__(raw);self.invalidations=[]
        for d in self.pe.DIRECTORY_ENTRY_IMPORT:
            for s in d.imports:
                if s.ordinal==250:
                    self.write(s.address,0xf3000010)
                    def invalidate(m):
                        assert m.reg[4:7]==[0x2222,0,1]
                        self.invalidations.append(tuple(m.reg[4:7]));return 1
                    self.hooks[0xf3000010]=invalidate


def config_record(seq,on):
    return bytearray(struct.pack('<4I',0x4d584420,seq,on,(0x4d584420+seq+on+0xa55a5aa5)&0xffffffff))


def reboot(f):
    n=Fixture(f.root);n.files={k:bytearray(v) for k,v in f.durable.items()};return n


def regression_cases(root):
    cases=[]
    for delta in [0,0x10000,0x123000]:
        f=Fixture(root)
        if delta:f.rebase(delta)
        assert f.call(f.A['readconfig'],[])==0
        assert f.call(f.A['persist'],[1])==0
        assert f.call(f.A['readconfig'],[])==1
        assert f.call(f.A['persist'],[0])==0
        assert f.call(f.A['readconfig'],[])==0
        cases.append('written config helpers preserve ABI and work rebased '+hex(delta))
    import pefile
    from debug_image import sha
    p=pefile.PE(str(root/'CmnDll.dll'));recipe=json.loads((root/'CmnDll.dll.json').read_bytes())
    assert p.FILE_HEADER.Machine==0x166 and p.verify_checksum()
    assert sha((root/'CmnDll.dll').read_bytes())==recipe['output_sha256']
    assert not any(s.Characteristics&0x20000000 and s.Characteristics&0x80000000 for s in p.sections)
    source=(Path(__file__).resolve().parents[1]/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System/CmnDll.dll').read_bytes()
    allowed=set()
    for edit in recipe['edits']:allowed.update(range(edit['offset'],edit['offset']+len(bytes.fromhex(edit['after_hex']))))
    at=p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum');allowed.update(range(at,at+4))
    assert all(a==b or j in allowed for j,(a,b) in enumerate(zip(source,(root/'CmnDll.dll').read_bytes())))
    rom=pefile.PE(str(Path(__file__).resolve().parents[1]/'extracted/705md-rom/fs/Windows/coredll.dll'))
    assert next(s.name for s in rom.DIRECTORY_ENTRY_EXPORT.symbols if s.ordinal==170)==b'ReadFile'
    cases.append('core checksum, import ordinal from actual ROM, section permissions and edit boundaries')
    for first in [0,1]:
        f=Fixture(root);f.init(first)
        assert f.call(f.A['persist'],[first])==0
        n=reboot(f);assert n.enabled==0 and n.call(n.A['readconfig'],[])==first
        assert n.call(n.A['persist'],[1-first])==0
        n=reboot(n);assert n.call(n.A['readconfig'],[])==1-first
        cases.append('on and off survive a new process with erased registry '+str(first))
    paths=['\\Storage Card2\\MAXmade\\debug-'+str(n)+'.cfg' for n in range(2)]
    for corrupt in [b'',b'x'*16,bytes(config_record(4,1)[:12]),bytes(config_record(4,1))+b'x',bytes(config_record(4,2))]:
        f=Fixture(root);f.files[paths[0]]=config_record(2,1);f.files[paths[1]]=bytearray(corrupt)
        assert f.call(f.A['readconfig'],[])==1;cases.append('torn or invalid inactive setting preserves previous slot')
    for seq0,seq1,on in [(5,6,0),(6,5,1),(0xffffffff,0,0),(0,0xffffffff,1)]:
        f=Fixture(root);f.files[paths[0]]=config_record(seq0,1);f.files[paths[1]]=config_record(seq1,0)
        assert f.call(f.A['readconfig'],[])==on;cases.append('latest setting selection including sequence wrap')
    for fault in ['open','short','write','flush','read']:
        f=Fixture(root);f.init();f.call(f.A['readconfig'],[]);assert f.call(f.A['persist'],[1])==0
        f.config_fail=fault;assert f.call(f.A['persist'],[0])!=0
        assert f.vm.read(f.D+0x3c)==1 and f.vm.read(f.D+0x40)==0
        n=reboot(f);assert n.call(n.A['readconfig'],[]) in [0,1]
        # Short/write/flush/open failures leave a durable previous setting.
        if fault!='read':assert n.call(n.A['readconfig'],[])==1
        cases.append('failed durable save retains active slot and reports error '+fault)
    f=Fixture(root);f.enabled=1;f.command(1);f.worker(1);n=reboot(f)
    assert n.command(1)&1==1;cases.append('MAX19 registry migrated by background worker')
    # Keep the exact same incorrect clock and tick in different processes.
    f=Fixture(root);f.init();f.usb=True;assert f.call(f.A['openfile'],[])==2
    first={k:bytes(v) for k,v in f.files.items()}
    n=Fixture(root);n.init();n.usb=True;n.files={k:bytearray(v) for k,v in first.items()}
    assert n.call(n.A['openfile'],[])==2
    assert len(n.files)==2 and all(bytes(n.files[k])==v for k,v in first.items())
    for _ in range(12):assert n.call(n.A['openfile'],[])==2
    assert len(n.files)==14 and all(bytes(n.files[k])==v for k,v in first.items())
    cases.append('same clock reboot and more than eight chunks preserve all earlier bytes')
    f=Fixture(root);f.init();f.usb=True;f.collisions=66
    assert f.call(f.A['openfile'],[])==3 and f.collisions==2
    assert f.call(f.A['openfile'],[])==2;cases.append('bounded collision search resumes next writer iteration')
    f.space=1;oldfiles={k:bytes(v) for k,v in f.files.items()}
    assert f.call(f.A['openfile'],[])==4 and oldfiles=={k:bytes(v) for k,v in f.files.items()}
    cases.append('USB full stops without deleting earlier sessions')
    # Native refresh must only mutate child state; drawing waits for background paint.
    recipe=json.loads((root/'AppMain.exe.json').read_bytes());ui=recipe['settings']
    refresh=next(r for r in recipe['routines'] if r['address']==ui['refresh'])
    assert 'jal 0x139020' not in refresh['assembly']
    event=next(r for r in recipe['routines'] if 'toggle_done:' in r['assembly'])
    assert 'addiu a2, zero, 1' in event['assembly']
    cases.append('native Settings background repaint replaces status instead of direct text overlay')
    return cases


def main():
    p=argparse.ArgumentParser();p.add_argument('--build',type=Path,required=True);a=p.parse_args()
    old.Fixture=Fixture;old.VM=VM
    from verify_settings20 import settings_cases
    cases=[]
    for name,fn in [('MAX19 regressions',old.core_cases),('PE integrity',old.image_checks),
                    ('event hooks',old.client_cases),('Settings redraw',settings_cases),
                    ('source switch',old.switch_table_cases),('navigation',old.inherited_cases),
                    ('power cycle and file preservation',regression_cases)]:
        print('Checking '+name,flush=True);cases+=fn(a.build)
    result=dict(passed=True,cases=len(cases),checks=cases,firmware_executed_natively=False,
        limits=['CE file durability and native repaint are emulated; physical car test remains required.'])
    write(a.build/'verification.json',result);print('Passed '+str(len(cases))+' checks')


if __name__=='__main__':main()
