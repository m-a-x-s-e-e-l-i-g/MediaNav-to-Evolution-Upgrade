"""Reproduce CE priority rejection using the unit's actual kernel instructions.

Native MIPS is interpreted; privileged scheduling, CE handles and imaging remain
explicit fixtures. This is not physical artwork-display validation.
"""
import json
import struct
import build_max15 as p
import verify_max14 as v
from verify_max14 import pefile, VM, call, put, data, World, ArtworkBlue, NATIVE, DIALOG
import bt_cover_art_app_lifetime as life
from patch_shared_mapping_checks import reloc_records
from verify_usb_input_safety import relocated
from verify_bt_cover_layout import moved_words

KERNEL=p.ROOT/'extracted/705md-rom/fs/Windows/kernel.dll'
ENTRY=0x8013b900
TABLE=0x815362b4

class KernelPriority:
    def __init__(self):
        self.raw=KERNEL.read_bytes();self.pe=pefile.PE(data=self.raw)
        assert self.pe.get_data(ENTRY-self.pe.OPTIONAL_HEADER.ImageBase,16)==bytes.fromhex('e8ffbd271400bfaf1000b0af0800a82c')
        self.table=self.pe.get_data(0x8014f2b4-self.pe.OPTIONAL_HEADER.ImageBase,8)
        assert self.table==bytes(range(248,256))
        self.calls=[]

    def run(self,handle,priority):
        m=VM(self.pe,[(ENTRY,ENTRY+0x70)])
        put(m,TABLE,self.table)
        m.write(0x8153b4cc,0x46001000);m.write(0x46001094,0x46002000)
        m.write(0x46002038,0)
        requested=[]
        def schedule(vm):
            assert vm.reg[4]==0x80124c98 and vm.reg[5]==handle
            requested.append(vm.reg[6]);return 1
        m.hooks[0x80112238]=schedule
        result=call(m,ENTRY,[handle,priority&0xffffffff])
        error=m.read(0x46002038)
        if not 0<=priority<8:assert result==0 and error==87 and requested==[]
        else:assert result==1 and error==0 and requested==[248+priority]
        row=dict(input=priority,result=result,last_error=error,scheduler_priorities=requested)
        self.calls.append(row)
        return result

kernel=KernelPriority()

class Player(v.Player):
    def lifetime_api(self,at):
        if at!=life.PRIORITY:return super().lifetime_api(at)
        assert self.role=='gui' and self.reg[4]==self.thread_handle and self.thread_suspended
        raw=self.reg[5];priority=raw if raw<0x80000000 else raw-0x100000000
        self.lifetime_trace.append(('real_kernel_priority',priority))
        result=kernel.run(self.thread_handle,priority)
        if self.failure in ('priority','priority_resume'):return 0
        self.priority_confirmed=bool(result)
        return result

def audit(raw,recipe):
    baseline=(p.BASELINE/'payload'/p.APP).read_bytes();old,new=pefile.PE(data=baseline),pefile.PE(data=raw)
    allowed=set()
    for e in recipe['edits']:
        at=e['offset'];before=bytes.fromhex(e['before_hex']);after=bytes.fromhex(e['after_hex'])
        assert baseline[at:at+len(before)]==before and raw[at:at+len(after)]==after
        allowed.update(range(at,at+len(after)))
    pd,rd=(old.OPTIONAL_HEADER.DATA_DIRECTORY[n] for n in (3,5))
    for d in (pd,rd):allowed.update(range(d.get_file_offset(),d.get_file_offset()+8))
    for name in ('CheckSum','SizeOfCode','SizeOfImage'):
        at=old.OPTIONAL_HEADER.get_field_absolute_offset(name);allowed.update(range(at,at+4))
    for name in ('Misc_VirtualSize','SizeOfRawData'):
        at=old.sections[-1].get_field_absolute_offset(name);allowed.update(range(at,at+4))
    cut=old.get_offset_from_rva(pd.VirtualAddress)
    assert all(a==b or i in allowed for i,(a,b) in enumerate(zip(baseline[:cut],raw[:cut])))
    oldrows=list(struct.iter_unpack('<5I',old.get_data(pd.VirtualAddress,pd.Size)))
    nd=new.OPTIONAL_HEADER.DATA_DIRECTORY[3];newrows=list(struct.iter_unpack('<5I',new.get_data(nd.VirtualAddress,nd.Size)))
    changed={r['address'] for r in recipe['changed_routines']}
    assert len(oldrows)==len(newrows) and [r for r in oldrows if r[0] not in changed]==[r for r in newrows if r[0] not in changed]
    assert all(a[1]<=b[0] for a,b in zip(newrows,newrows[1:]))
    assert new.OPTIONAL_HEADER.CheckSum==new.generate_checksum()
    assert [(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in old.DIRECTORY_ENTRY_IMPORT]==[(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in new.DIRECTORY_ENTRY_IMPORT]
    assert all(not(s.Characteristics&0x20000000 and s.Characteristics&0x80000000) for s in new.sections)
    for delta in (0x1000,0x8000,0x123000):
        moved=pefile.PE(data=relocated(raw,delta))
        for row in recipe['routines']:
            r=dict(row,raw=new.get_data(row['address']-p.BASE,row['capacity']))
            assert moved.get_data(row['address']-p.BASE,row['capacity'])==moved_words(r,delta),(hex(row['address']),delta)
            assert set(map(tuple,row['relocations']))<=set(reloc_records(new))
        assert moved.get_data(p.STRINGS-p.BASE,0x400)==new.get_data(p.STRINGS-p.BASE,0x400)
        assert list(struct.iter_unpack('<5I',moved.get_data(nd.VirtualAddress,nd.Size)))==[tuple(x+delta if x else 0 for x in r) for r in newrows]
    return dict(mutation_boundaries=True,imports_unchanged=True,unwind_rows_retained=True,rebases=[0x1000,0x8000,0x123000],helper_count=len(recipe['routines']))

def setup(raw,recipe):
    world=World();blue=ArtworkBlue(pefile.PE(data=(NATIVE/'Blue.exe').read_bytes()),(p.OUT/'payload'/p.SYSTEM/'Blue.exe').read_bytes(),world)
    app=Player((NATIVE/'AppMain.exe').read_bytes(),raw,world,recipe)
    blue.start();return world,blue,app

def cleanup(world,blue,app):
    app.finish();blue.stop();blue.deliver_window()
    assert not world.handles and not world.views and not app.paint_dcs

def api_contract(raw):
    app_pe=pefile.PE(data=raw)
    priority_import=next((d.dll,i.ordinal) for d in app_pe.DIRECTORY_ENTRY_IMPORT for i in d.imports if i.address==life.PRIORITY)
    assert priority_import==(b'COREDLL.dll',514)
    core_path=p.ROOT/'extracted/705md-rom/fs/Windows/coredll.dll'
    core_raw=core_path.read_bytes();core=pefile.PE(data=core_raw)
    exported=next(s for s in core.DIRECTORY_ENTRY_EXPORT.symbols if s.ordinal==514)
    assert exported.name==b'SetThreadPriority' and core.OPTIONAL_HEADER.ImageBase+exported.address==0x4002d23c
    # The exported wrapper forwards a1 unchanged to the thread API trap. The
    # unit kernel supplies the rejecting 0..7 gate and the exact mapping table.
    assert core.get_data(0x4002d26c-core.OPTIONAL_HEADER.ImageBase,12)==bytes.fromhex('f2b7082409f8000125280002')
    return dict(coredll_sha256=p.sha(core_raw),priority_import_ordinal=514)

def main():
    v.p=p;v.Player=Player
    raw=(p.OUT/'payload'/p.APP).read_bytes();recipe=json.loads((p.OUT/'recipe.json').read_bytes())
    contract=api_contract(raw)
    assert raw==p.patch((p.BASELINE/'payload'/p.APP).read_bytes())[0]
    for value in (-15,-2,-1,0,1,2,3,4,5,6,7,8,252):kernel.run(0x12345,value)
    proof=dict(app_sha256=p.sha(raw),audit=audit(raw,recipe))
    v.previous.SCENE=v.previous.scene(v.av.trace(0x3b05c,'media',raw,1),p.OUT/'payload')
    v.previous.FALLBACK_PIXELS=v.Image.open(p.OUT/'payload'/p.SYSTEM/'Img/M1/media/media_album_case_noalbum_img.bmp').convert('RGB')
    oldraw=(p.BASELINE/'payload'/p.APP).read_bytes()
    oldrecipe=json.loads((p.ROOT/'build/max14-development-02/recipe.json').read_bytes())
    world,blue,app=setup(oldraw,oldrecipe)
    # Actual installed window wrapper drives START, rather than direct helper calls.
    app.window(1);assert app.field(12)==0 and not app.priority_confirmed
    app.draw();app.window(15);assert app.capture_status[-1]=='Cover starting (S0)'
    assert ('real_kernel_priority',-1) in app.lifetime_trace
    cleanup(world,blue,app)
    proof['max14_S0_reproduced']=True
    print('MAX14 S0 reproduced using actual kernel priority validation.',flush=True)
    world,blue,app=setup(raw,recipe)
    app.window(1);assert app.field(12)==1 and app.priority_confirmed and app.read(p.FAIL)==0
    assert ('real_kernel_priority',4) in app.lifetime_trace
    app.draw();app.window(15)
    blue.receive_image(v.jpeg());blue.deliver_window();assert app.run_worker()==0
    app.window(v.worker.MESSAGE);app.window(0x113,0x4d42)
    assert app.field(20) and app.read(p.STAGE)==9
    cleanup(world,blue,app)
    proof['window_create_to_display_pass']=True
    failures=[]
    for failure,caption,stage in (('event','Startup blocked (S3)',1),('timer','Timer failed (S4)',2),
        ('timer_id','Timer failed (S4)',2),('thread','Startup blocked (S3)',1),
        ('priority','Priority failed (S5)',3),('resume','Resume failed (S6)',4)):
        world,blue,app=setup(raw,recipe);app.failure=failure
        app.window(1);assert app.field(12)==0 and app.read(p.FAIL)==stage
        app.draw();app.window(15);assert app.capture_status[-1]==caption,(failure,app.capture_status)
        failures.append(dict(failure=failure,caption=caption));cleanup(world,blue,app)
    proof['window_startup_faults']=failures
    proof['artwork']=v.artwork_checks(raw,recipe)
    # MAX14's complete skin/state proof is inherited only because every resource,
    # native constructor, playback helper and label helper is byte-exact.
    proof['inherited_max14_verification_sha256']=p.sha((p.ROOT/'build/max14-development-02/verification.json').read_bytes())
    proof['kernel_priority_calls']=kernel.calls
    proof['kernel_sha256']=p.sha(kernel.raw)
    proof.update(contract)
    proof['kernel_priority_table_hex']=kernel.table.hex()
    proof.update(native_executed=False,hardware_tested=False,artwork_issue_status='Open: MAX14 failure confirmed; MAX15 startup correction awaits car display test')
    (p.OUT/'verification.json').write_text(json.dumps(proof,indent=2)+'\n')
    print(json.dumps(dict(app_sha256=proof['app_sha256'],artwork_cases=len(proof['artwork']),startup_faults=len(failures),kernel_sha256=proof['kernel_sha256']),indent=2))

if __name__=='__main__':main()
