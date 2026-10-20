"""Verify temporary/backup boot files before replacing NK or the updater.

This is not an atomic power-loss transaction or an A/B bootloader. All sources
and a verified prior target remain available on software-detected failure.
"""
import struct
from patch_updater_copy_safety import frame,end,COPY,ERROR,STOP

def add(i,h):
    for name,ordinal in [('attrs',166),('last',516),('move',163)]:
        try:i.apis[name]=i.import_at(ordinal)
        except StopIteration:i.apis[name]=i.add_import('COREDLL.dll',ordinal)
    compare,row=i.clone(COPY);assert row[2:4]==(0,0)
    # Copy/readback becomes readback-only: suppress precisely its CopyFile call.
    original=i.p.get_data(COPY-i.base,row[1]-row[0]);needle=struct.pack('<5I',0x3c180003,0x371870dc,0x8f190000,0x0320f809,0)
    assert original.count(needle)==1
    off=original.index(needle)+12;struct.pack_into('<I',i.body,compare-i.text+off,0x24020001)
    replacing=i.routine(f'''{frame(0x50,['s0','s1','s2','s3','s4','s5'])}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
move s4, zero
# Complete new content before touching the live file.
move a1, s3
jal {hex(COPY)}
nop
beqz v0, stop
nop
move a0, s1
{i.api('attrs')}
addiu t0, zero, -1
beq v0, t0, absent
nop
andi t0, v0, 16
bnez t0, bad_path
nop
move a0, s1
move a1, s2
jal {hex(COPY)}
nop
beqz v0, stop
nop
addiu s4, zero, 1
move a0, s2
{i.api('delete')}
beqz v0, api_error
nop
# Keep the native updater's rename semantics for a running executable. The
# verified backup copy can be removed while the live source is still intact;
# rename then puts that same old file at the backup path without deleting it.
move a0, s1
move a1, s2
{i.api('move')}
beqz v0, api_error
nop
b publish
nop
absent:
{i.api('last')}
addiu t0, zero, 2
beq v0, t0, publish
nop
addiu t0, zero, 3
bne v0, t0, api_error
nop
publish:
move a0, s3
move a1, s1
{i.api('move')}
beqz v0, rollback_api
nop
move a0, s0
move a1, s1
jal {hex(compare)}
nop
beqz v0, rollback
nop
addiu v0, zero, 1
{end(0x50,['s0','s1','s2','s3','s4','s5'])}
rollback_api:
{i.api('last')}
move a0, v0
move a1, s1
jal {hex(ERROR)}
nop
rollback:
beqz s4, stop
nop
# No automatic retry/reboot. Restore from the verified old file if publication
# failed; retain the staged new image and old backup regardless.
move a0, s2
move a1, s1
jal {hex(COPY)}
nop
b stop
nop
bad_path:
addiu a0, zero, 267
b record
nop
api_error:
{i.api('last')}
move a0, v0
record:
move a1, s1
jal {hex(ERROR)}
nop
stop:
jal {hex(STOP)}
nop''',0x400,0x50,['s0','s1','s2','s3','s4','s5'])
    paths={k:i.string(v)for k,v in {
        'kernel_backup':r'\Storage Card\NA.bin','kernel_temp':r'\Storage Card\NK.MAX29-new',
        'updater_source':r'\Storage Card3\upgrade\Storage Card\System\UpgradeManager.exe',
        'updater_target':r'\Storage Card\System\UpgradeManager.exe',
        'updater_backup':r'\Storage Card\System\OLD_UpgradeManager.exe',
        'updater_temp':r'\Storage Card\System\UpgradeManager.MAX29-new'}.items()}
    consumed=i.routine(f'''{frame(0x28,['s0'])}
move s0, a0
{i.api('delete')}
bnez v0, done
nop
{i.api('last')}
move a0, v0
move a1, s0
jal {hex(ERROR)}
nop
jal {hex(STOP)}
nop
done:
{end(0x28,['s0'])}''',0x100,0x28,['s0'])
    nk=i.routine(f'''{frame(0x28,[])}
la a2, {hex(paths['kernel_backup'])}
la a3, {hex(paths['kernel_temp'])}
jal {hex(replacing)}
nop
{end(0x28,[])}''',0x100,0x28,[])
    updater=i.routine(f'''{frame(0x28,[])}
la a0, {hex(paths['updater_source'])}
la a1, {hex(paths['updater_target'])}
la a2, {hex(paths['updater_backup'])}
la a3, {hex(paths['updater_temp'])}
jal {hex(replacing)}
nop
la a0, {hex(paths['updater_source'])}
jal {hex(consumed)}
nop
{end(0x28,[])}''',0x100,0x28,[])
    old,row=i.clone(0x17530);assert row[2:4]==(0,0)
    def patch(at,data):
        addr=old+at-0x17530;start=addr-i.base;end=start+len(data)
        i.body[addr-i.text:addr-i.text+len(data)]=data;i.reloc=[r for r in i.reloc if not start<=r[0]<end]
    assert i.p.get_data(0x176c8-i.base,4)==struct.pack('<I',0x0100f809)
    patch(0x176c8,struct.pack('<I',0x24020001)) # backup is now verified inside replacing
    assert i.p.get_data(0x176f0-i.base,4)==struct.pack('<I',0x0100f809)
    patch(0x176f0,struct.pack('<I',(3<<26)|(nk>>2)));i.reloc.append((old+0x176f0-0x17530-i.base,5,None))
    assert i.p.get_data(0x17704-i.base,4)==struct.pack('<I',0x0100f809)
    patch(0x17704,struct.pack('<I',(3<<26)|(consumed>>2)));i.reloc.append((old+0x17704-0x17530-i.base,5,None))
    # Replace the unchecked active->OLD and staged->active moves; preserve the
    # existing staged-file predicate and its missing-file branch.
    at=old+0x1773c-0x17530;target=old+0x1776c-0x17530;delta=(target-(at+8)-4)//4
    block=struct.pack('<4I',(3<<26)|(updater>>2),0,(4<<26)|(delta&65535),0).ljust(0x30,b'\0')
    patch(0x1773c,block);i.reloc.append((at-i.base,5,None))
    committed=i.routine(f'''{frame(0x28,[])}
la a0, {hex(h['flag'])}
{i.api('delete')}
bnez v0, done
nop
{i.api('last')}
addiu t0, zero, 2
beq v0, t0, done
nop
addiu t0, zero, 3
beq v0, t0, done
nop
move a0, v0
la a1, {hex(h['flag'])}
jal {hex(ERROR)}
nop
jal {hex(STOP)}
nop
done:
{end(0x28,[])}''',0x100,0x28,[])
    # The next reboot is expected only after both boot files and cleanup are
    # verified. Clear the startup marker at that boundary, before MCU dispatch,
    # so a healthy update proceeds to its guarded post-restart application copy.
    patch(0x1776c,struct.pack('<3I',(3<<26)|(committed>>2),0,0));i.reloc.append((old+0x1776c-0x17530-i.base,5,None))
    guarded=i.routine(f'''{frame(0x28,['s0'])}
move s0, a0
la t0, 0x38f10
addiu t1, zero, 1
sw t1, 0(t0)
jal {hex(h['mark'])}
nop
beqz v0, failed
nop
move a0, s0
jal {hex(old)}
nop
{end(0x28,['s0'])}
failed:
addiu a0, zero, 5050
la a1, {hex(h['flag'])}
jal {hex(ERROR)}
nop
jal {hex(STOP)}
nop''',0x100,0x28,['s0'])
    i.hook(0x17530,guarded)
    return dict(compare=compare,replace=replacing,kernel=nk,updater=updater,consume=consumed,commit=committed,controller=guarded,native_clone=old,paths=paths,
                kernel_rollback=True,atomic_power_loss_transaction=False)
