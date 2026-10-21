"""Integrate the application transaction into the exact MAX32 native updater.

Keep native healthy settings migration and firmware preparation. Bootstrap the
independent recovery components before entering pending-install processing.
"""
import struct
from debug_image import Image
from patch_updater_copy_safety import frame,end,STARTUP,STAGE,ERROR,STOP,CODE

PIN='df4651042416b1a0008b0ec4dd04630ac71782737cec35fc749dc3c91e97340c'
PENDING=r'\Storage Card3\MAX33-repair.pending'
COMPLETE=r'\Storage Card3\MAX33-applications.complete'
COMPLETION=b'MAXmade MAX33 applications verified\r\n'

def build(raw,prior):
    i=Image(raw,PIN)
    i.apis={}
    for name,ordinal in [('attrs',166),('last',516),('process',493),('close',553),('wait',497),('exitcode',519),('event',494),('open',168),('size',172),('read',170),('show',266),('message',858)]:
        try:i.apis[name]=i.import_at(ordinal)
        except StopIteration:i.apis[name]=i.add_import('COREDLL.dll',ordinal)
    paths={k:i.string(v)for k,v in dict(stage=r'\Storage Card3\upgrade',receipt=r'\Storage Card3\upgrade\filecopy_success.bin',
        version_source=r'\Storage Card3\upgrade\Storage Card\System\Version_Info.txt',version_target=r'\Storage Card\System\Version_Info.txt',
        engine=r'\Storage Card\InstallResume.exe',pending=PENDING,complete=COMPLETE,
        stage_kernel=r'\Storage Card3\upgrade\Storage Card\NK.bin',stage_updater=r'\Storage Card3\upgrade\Storage Card\System\UpgradeManager.exe',
        install='-MAX33Install',resume='-MAX33Resume',repair='-MAX33Repair').items()}
    expected_version=i.string('7.0.6.MAX33',False)
    expected_complete=i.string(COMPLETION.decode(),False)
    # Compare a bounded ASCII file with a literal, not existence-only success.
    valid=i.routine(f'''{frame(0x90,['s0','s1','s2','s3'])}
move s1, a1
move s2, a2
lui a1, 0x8000
addiu a2, zero, 1
move a3, zero
addiu t0, zero, 3
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{i.api('open')}
move s0, v0
move s3, zero
addiu t0, zero, -1
beq s0, t0, done
nop
move a0, s0
addiu a1, sp, 0x28
sw zero, 0x28(sp)
{i.api('size')}
bne v0, s2, close
nop
lw t0, 0x28(sp)
bnez t0, close
nop
move a0, s0
addiu a1, sp, 0x30
move a2, s2
addiu a3, sp, 0x2c
sw zero, 0x10(sp)
{i.api('read')}
beqz v0, close
nop
lw t0, 0x2c(sp)
bne t0, s2, close
nop
addiu t0, sp, 0x30
move t1, s1
move t2, s2
check:
beqz t2, yes
nop
lbu t3, 0(t0)
lbu t4, 0(t1)
bne t3, t4, close
nop
addiu t0, t0, 1
addiu t1, t1, 1
b check
addiu t2, t2, -1
yes:
addiu s3, zero, 1
close:
move a0, s0
{i.api('close')}
bnez v0, done
nop
move s3, zero
done:
move v0, s3
{end(0x90,['s0','s1','s2','s3'])}''',0x400,0x90,['s0','s1','s2','s3'])
    replace=prior['boot_recovery']['first_phase']['replace']
    boot_pairs=[]
    for name in ['InstallResume.exe','Recovery.exe']:
        boot_pairs.append([i.string(p)for p in [r'\Storage Card3\upgrade\Storage Card'+'\\'+name,r'\Storage Card'+'\\'+name,r'\Storage Card'+'\\'+name+'.MAX33-old',r'\Storage Card'+'\\'+name+'.MAX33-new']])
    boot_code='\n'.join(f'''la a0, {hex(s)}
la a1, {hex(t)}
la a2, {hex(b)}
la a3, {hex(n)}
jal {hex(replace)}
nop
beqz v0, failed
nop'''for s,t,b,n in boot_pairs)
    bootstrap=i.routine(f'''{frame(0x28,[])}
la a0, {hex(paths['version_source'])}
la a1, {hex(expected_version)}
addiu a2, zero, 11
jal {hex(valid)}
nop
beqz v0, failed
nop
la a0, {hex(paths['receipt'])}
{i.api('attrs')}
addiu t0, zero, -1
beq v0, t0, failed
nop
andi t0, v0, 16
bnez t0, failed
nop
{boot_code}
addiu v0, zero, 1
{end(0x28,[])}
failed:
move v0, zero
{end(0x28,[])}''',0x400,0x28,[])
    # A software stop in this boot must not immediately auto-retry a persistent
    # failure. ROM boot still starts Recovery without this flag and can resume.
    noauto=i.string('-MAX33NoAuto');recovery_path=i.string(r'\Storage Card\Recovery.exe');desktop=i.string(r'\Windows\explorer.exe')
    recover=i.routine(f'''{frame(0x60,[])}
sw zero, 0x50(sp)
sw zero, 0x40(sp)
sw zero, 0x44(sp)
sw zero, 0x48(sp)
sw zero, 0x4c(sp)
la a0, {hex(recovery_path)}
la a1, {hex(noauto)}
b spawn
nop
fallback:
la a0, {hex(desktop)}
move a1, zero
spawn:
move a2, zero
move a3, zero
sw zero, 0x10(sp)
sw zero, 0x14(sp)
sw zero, 0x18(sp)
sw zero, 0x1c(sp)
sw zero, 0x20(sp)
addiu t0, sp, 0x40
sw t0, 0x24(sp)
{i.api('process')}
bnez v0, opened
nop
la t0, {hex(desktop)}
# Preserve a bounded single fallback: s0 is not available in this frame, use
# a stack flag initialized before the first launch.
lw t1, 0x50(sp)
bnez t1, done
nop
addiu t1, zero, 1
sw t1, 0x50(sp)
b fallback
nop
opened:
lw a0, 0x40(sp)
{i.api('close')}
lw a0, 0x44(sp)
{i.api('close')}
addiu v0, zero, 1
done:
{end(0x60,[])}''',0x300,0x60,[])
    i.hook(prior['boot_recovery']['launch'],recover)
    # Wait for a separate process; normal manager startup remains behind success.
    delegate=i.routine(f'''{frame(0x80,['s0','s1'])}
move s1, a0
la t0, {hex(CODE)}
addiu t1, zero, 6001
sw t1, 0(t0)
la t0, 0x3784c
addiu t1, zero, 3008
sw t1, 0(t0)
# Stop the old five-minute monitor through its existing success event. The
# native controller still owns/closes COM2 on its ordinary return path.
la t0, 0x38f34
lw a0, 0(t0)
beqz a0, spawn
nop
addiu a1, zero, 3
{i.api('event')}
spawn:
sw zero, 0x40(sp)
sw zero, 0x44(sp)
sw zero, 0x48(sp)
sw zero, 0x4c(sp)
la a0, {hex(paths['engine'])}
move a1, s1
move a2, zero
move a3, zero
sw zero, 0x10(sp)
sw zero, 0x14(sp)
sw zero, 0x18(sp)
sw zero, 0x1c(sp)
sw zero, 0x20(sp)
addiu t0, sp, 0x40
sw t0, 0x24(sp)
{i.api('process')}
beqz v0, failed
nop
lw a0, 0x44(sp)
{i.api('close')}
lw a0, 0x40(sp)
addiu a1, zero, -1
{i.api('wait')}
move s0, v0
lw a0, 0x40(sp)
addiu a1, sp, 0x50
{i.api('exitcode')}
beqz v0, child_failed
nop
bnez s0, child_failed
nop
lw t0, 0x50(sp)
bnez t0, child_failed
nop
lw a0, 0x40(sp)
{i.api('close')}
la a0, {hex(paths['pending'])}
{i.api('attrs')}
addiu t0, zero, -1
bne v0, t0, failed
nop
{i.api('last')}
addiu t0, zero, 2
beq v0, t0, check_stage
nop
addiu t0, zero, 3
bne v0, t0, failed
nop
check_stage:
la a0, {hex(paths['stage'])}
{i.api('attrs')}
addiu t0, zero, -1
bne v0, t0, failed
nop
{i.api('last')}
addiu t0, zero, 2
beq v0, t0, check_commit
nop
addiu t0, zero, 3
bne v0, t0, failed
nop
check_commit:
la a0, {hex(paths['complete'])}
la a1, {hex(expected_complete)}
addiu a2, zero, {len(COMPLETION)}
jal {hex(valid)}
nop
beqz v0, failed
nop
la a0, {hex(paths['version_target'])}
la a1, {hex(expected_version)}
addiu a2, zero, 11
jal {hex(valid)}
nop
beqz v0, failed
nop
la t0, {hex(CODE)}
sw zero, 0(t0)
la t0, 0x3784c
addiu t1, zero, 3000
sw t1, 0(t0)
addiu v0, zero, 1
{end(0x80,['s0','s1'])}
child_failed:
lw a0, 0x40(sp)
{i.api('close')}
failed:
la t0, {hex(CODE)}
sw zero, 0(t0)
addiu a0, zero, 5005
la a1, {hex(paths['engine'])}
jal {hex(ERROR)}
nop
jal {hex(STOP)}
nop
move v0, zero
{end(0x80,['s0','s1'])}''',0x700,0x80,['s0','s1'])
    startup=i.routine(f'''{frame(0x28,[])}
la a0, {hex(paths['pending'])}
{i.api('attrs')}
addiu t0, zero, -1
bne v0, t0, resume
nop
{i.api('last')}
addiu t0, zero, 2
beq v0, t0, stage
nop
addiu t0, zero, 3
bne v0, t0, failed
nop
stage:
la a0, {hex(paths['stage'])}
{i.api('attrs')}
addiu t0, zero, -1
beq v0, t0, native
nop
la a0, {hex(paths['version_source'])}
la a1, {hex(expected_version)}
addiu a2, zero, 11
jal {hex(valid)}
nop
beqz v0, other_package
nop
jal {hex(bootstrap)}
nop
beqz v0, failed
nop
b native
nop
other_package:
# A full later upgrade must reach its original first stage so it can replace
# this updater. Do not bootstrap the MAX33 worker into a different package.
# Require both first-stage boot sources; a foreign application-only remainder
# is stopped rather than processed with MAX33's settings/worker assumptions.
la a0, {hex(paths['stage_kernel'])}
{i.api('attrs')}
addiu t0, zero, -1
beq v0, t0, failed
nop
andi t0, v0, 16
bnez t0, failed
nop
la a0, {hex(paths['stage_updater'])}
{i.api('attrs')}
addiu t0, zero, -1
beq v0, t0, failed
nop
andi t0, v0, 16
bnez t0, failed
nop
native:
jal {hex(STARTUP)}
nop
{end(0x28,[])}
resume:
la a0, {hex(paths['resume'])}
jal {hex(delegate)}
nop
{end(0x28,[])}
failed:
addiu a0, zero, 5004
la a1, {hex(paths['stage'])}
jal {hex(ERROR)}
nop
jal {hex(STOP)}
nop
{end(0x28,[])}''',0x400,0x28,[])
    copy=i.routine(f'''la a0, {hex(paths['install'])}
j {hex(delegate)}
nop''',0x40)
    assert i.p.get_data(0x12e4c-i.base,4)==struct.pack('<I',(3<<26)|(STARTUP>>2))
    assert i.p.get_data(0x15304-i.base,4)==struct.pack('<I',(3<<26)|(STAGE>>2))
    i.hook(0x12e4c,startup,True);i.hook(0x15304,copy,True)
    # Existing desktop rectangle/click remains as an independent escape. Add
    # a second, separate repair action rather than repurpose the desktop button.
    repair_open=i.routine(f'''{frame(0x60,[])}
sw zero, 0x40(sp)
sw zero, 0x44(sp)
sw zero, 0x48(sp)
sw zero, 0x4c(sp)
la a0, {hex(paths['engine'])}
la a1, {hex(paths['repair'])}
move a2, zero
move a3, zero
sw zero, 0x10(sp)
sw zero, 0x14(sp)
sw zero, 0x18(sp)
sw zero, 0x1c(sp)
sw zero, 0x20(sp)
addiu t0, sp, 0x40
sw t0, 0x24(sp)
{i.api('process')}
beqz v0, failed
nop
lw a0, 0x40(sp)
{i.api('close')}
lw a0, 0x44(sp)
{i.api('close')}
b done
nop
failed:
move a0, zero
la a1, {hex(i.string('Repair could not start. Use Open recovery desktop; files and checkpoints are retained.'))}
la a2, {hex(i.string('Installation recovery'))}
lui a3, 4
ori a3, a3, 0x10
{i.api('message')}
done:
move v0, zero
{end(0x60,[])}''',0x300,0x60,[])
    old_click=prior['recovery']['click'];old_paint=prior['recovery']['paint']
    paint_clone,row=i.clone(old_paint);assert row[2:4]==(0,0)
    click=i.routine(f'''la t0, {hex(CODE)}
lw t0, 0(t0)
beqz t0, old
nop
la t0, 0x3784c
lw t0, 0(t0)
addiu t1, zero, 3007
bne t0, t1, old
nop
sltiu t0, a0, 40
bnez t0, old
nop
sltiu t0, a0, 760
beqz t0, old
nop
sltiu t0, a1, 290
bnez t0, old
nop
sltiu t0, a1, 365
beqz t0, old
nop
j {hex(repair_open)}
nop
old:
j {hex(old_click)}
nop''',0x200)
    label=i.string('Repair / resume update')
    paint=i.routine(f'''{frame(0x50,['s0'])}
move s0, a1
jal {hex(paint_clone)}
nop
la t0, {hex(CODE)}
lw t0, 0(t0)
beqz t0, done
nop
la t0, 0x3784c
lw t0, 0(t0)
addiu t1, zero, 3007
bne t0, t1, done
nop
addiu t0, zero, 40
sw t0, 0x20(sp)
addiu t0, zero, 290
sw t0, 0x24(sp)
addiu t0, zero, 760
sw t0, 0x28(sp)
addiu t0, zero, 365
sw t0, 0x2c(sp)
jal 0x2a1e0
addiu a0, zero, 2
move a2, v0
move a0, s0
jal 0x2a200
addiu a1, sp, 0x20
move a0, s0
la a1, {hex(label)}
addiu a2, zero, -1
addiu a3, sp, 0x20
addiu t0, zero, 37
jal 0x2a400
sw t0, 0x10(sp)
done:
{end(0x50,['s0'])}''',0x300,0x50,['s0'])
    i.hook(0x14c34,click,True);i.hook(old_paint,paint)
    out,recipe=i.finish();recipe['resume33']=dict(bootstrap=bootstrap,startup=startup,delegate=delegate,copy=copy,valid=valid,recovery_noauto=recover,
        repair_open=repair_open,click=click,paint=paint,prior_paint=old_paint,prior_paint_clone=paint_clone,prior_click=old_click,
        repair_rectangle=[40,290,760,365],desktop_rectangle=[40,380,760,460],paths=paths,
        delegated_error=6001,delegated_phase=3008,settings_migration_preserved=True,first_stage_unchanged=True)
    return out,recipe
