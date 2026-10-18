"""Execute the delivered error-paint/click/desktop paths with explicit CE fixtures."""
import argparse
import json
from pathlib import Path
import pefile
import verify_updater_copy_safety as prior
from inspect_bt_pairing import put
from updater_recovery28 import build
from patch_updater_copy_safety import CODE, PAINT

RECIPE = None


class RecoveryFixture(prior.Fixture):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.vm.ranges.extend((r[0], r[1]) for r in RECIPE['helper_rows'])
        self.launch_ok = True
        self.process_handles = set()
        self.vm.write(0x38efc, 0x5555)
        apis = {493: self.process, 858: self.message, 266: self.show}
        for d in self.vm.pe.DIRECTORY_ENTRY_IMPORT:
            for entry in d.imports:
                if entry.ordinal in apis:
                    address = 0xf6010000 + entry.ordinal * 4
                    self.vm.write(entry.address, address)
                    self.vm.hooks[address] = apis[entry.ordinal]

    def process(self, vm):
        assert vm.text(vm.reg[4]) == r'\Windows\explorer.exe'
        assert vm.reg[5:8] == [0, 0, 0]
        assert [vm.read(vm.reg[29] + 16 + j * 4) for j in range(5)] == [0] * 5
        info = vm.read(vm.reg[29] + 0x24)
        assert [vm.read(info + j * 4) for j in range(4)] == [0] * 4
        self.log('CreateProcess', application=r'\Windows\explorer.exe', success=self.launch_ok)
        if not self.launch_ok:
            self.error = 2
            return 0
        self.process_handles.update([0xaaaa0001, 0xaaaa0002])
        for n, value in enumerate([0xaaaa0001, 0xaaaa0002, 123, 456]):vm.write(info + n * 4, value)
        return 1

    def api_close(self, vm):
        if vm.reg[4] in self.process_handles:
            self.process_handles.remove(vm.reg[4]);self.log('CloseProcessHandle');return 1
        return super().api_close(vm)

    def message(self, vm):
        assert vm.reg[4] == 0x5555
        self.log('MessageBox', text=vm.text(vm.reg[5]), flags=vm.reg[7])
        return 1

    def format(self, vm):
        value=vm.text(vm.reg[6])
        if value.startswith('Could not open the desktop (error %u).'):
            value=value % vm.reg[7]
            assert len(value)+1<=vm.reg[5]
            put(vm,vm.reg[4],(value+'\0').encode('utf-16-le'))
            return len(value)
        return super().format(vm)

    def show(self, vm):
        assert vm.reg[4:6] == [0x5555, 0]
        self.log('ShowWindow', command=vm.reg[5])
        return 1


def verify(directory):
    global RECIPE
    raw = (directory / 'UpgradeManager.exe').read_bytes()
    RECIPE = json.loads((directory / 'UpgradeManager.exe.json').read_text())
    checks = []
    previous_class = prior.Fixture
    prior.Fixture = RecoveryFixture
    try:
        inherited = prior.verify(raw)
    finally:
        prior.Fixture = previous_class
    checks += [f"Inherited installer: {x['name']}" for x in inherited['traces']]
    for code in (5, 8, 112, 5001, 5002, 5003):
        for ok in (True, False):
            f = RecoveryFixture(raw, {r'\Storage Card2\scan_done_flag.bin': b'',
                                      r'\Storage Card3\TFAT\MgrSys.cfg': b'backup'})
            f.vm.write(CODE, code);f.vm.write(0x3784c, 3007);f.launch_ok = ok
            before = dict(f.files)
            f.run(RECIPE['recovery']['click'], [400, 420])
            f.run(RECIPE['recovery']['click'], [400, 420])
            assert len([e for e in f.events if e['api'] == 'CreateProcess']) == 2
            assert not f.process_handles and f.files == before and not f.original_format
            assert f.vm.read(CODE) == code and f.vm.read(0x3784c) == 3007
            messages = [e for e in f.events if e['api'] == 'MessageBox']
            assert len(messages) == (0 if ok else 2)
            if not ok:assert all('error 2' in x['text'] for x in messages)
            assert bool([e for e in f.events if e['api'] == 'ShowWindow']) == ok
            checks.append(f'Error {code}: desktop success={ok}, retry available, handles closed, no file or phase mutation')
    for x, y, hit in [(39,420,False),(40,380,True),(759,459,True),(760,420,False),
                       (400,379,False),(400,460,False),(50,440,True),(0xffffffff,420,False)]:
        f = RecoveryFixture(raw);f.vm.write(CODE,5001);f.vm.write(0x3784c,3007)
        f.run(RECIPE['recovery']['click'], [x,y])
        assert bool([e for e in f.events if e['api']=='CreateProcess']) == hit
        checks.append(f'Recovery rectangle x={x} y={y} hit={hit}')
    for code, phase in [(0,3000),(0,3007),(5001,3000),(5001,3001)]:
        f=RecoveryFixture(raw);f.vm.write(CODE,code);f.vm.write(0x3784c,phase)
        f.vm.reg[4:6]=[400,420];f.vm.reg[29]=prior.STACK;f.vm.reg[31]=prior.RETURN
        f.vm.run(RECIPE['recovery']['click'],{0x16394,prior.RETURN},limit=100000)
        assert f.vm.pc==(0x16394 if code==0 else prior.RETURN)
        assert f.vm.reg[4:6]==[400,420]and f.vm.reg[29]==prior.STACK
        assert not any(e['api']=='CreateProcess'for e in f.events)
        checks.append(f'Healthy click delegates; pending error blocks native actions code={code} phase={phase}')
    for code, phase in [(0,3000),(5001,3007),(112,3007),(5002,3007),(5003,3007)]:
        f=RecoveryFixture(raw);f.vm.write(CODE,code);f.vm.write(0x3784c,phase)
        put(f.vm,prior.patcher.PATH,(r'\Storage Card2\scan_done_flag.bin'+'\0').encode('utf-16-le'))
        f.run(PAINT,[prior.OBJECT,0x5555])
        buttons=[e for e in f.events if e['api']=='DrawTextW'and e['text']=='Open recovery desktop']
        assert bool(buttons)==bool(code)
        if buttons:assert buttons[0]['flags']==37
        checks.append(f'Persistent error repaint includes recovery button code={code}')
    # The actual WM_LBUTTONUP call site, not a hypothetical UI event route.
    f=RecoveryFixture(raw);f.vm.write(CODE,5001);f.vm.write(0x3784c,3007)
    f.vm.ranges.append((0x14c2c,0x14c3c))
    f.vm.reg[18]=(420<<16)|400;f.vm.reg[29]=prior.STACK
    f.vm.run(0x14c2c,{0x14c3c},limit=100000)
    assert any(e['api']=='CreateProcess'for e in f.events)
    checks.append('Actual native mouse-up call site reaches recovery action')
    report=dict(passed=True,cases=len(checks),checks=checks,physical_tested=False,
                limits='Native MIPS with explicit CE/file/process/GDI fixtures; no physical CE pixels, Explorer startup, boot, storage/power recovery or universal anti-brick guarantee.')
    (directory/'updater-recovery-verification.json').write_text(json.dumps(report,indent=2)+'\n')
    print('PASS',len(checks),'installer/recovery checks')
    return report


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);a=p.parse_args();verify(a.directory)
