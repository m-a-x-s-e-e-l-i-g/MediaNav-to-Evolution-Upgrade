from verify_max20 import Fixture,config_record,reboot
import json
from pathlib import Path

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
    return cases
