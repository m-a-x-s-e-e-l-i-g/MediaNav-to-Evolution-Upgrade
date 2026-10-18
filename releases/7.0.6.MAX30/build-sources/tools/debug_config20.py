"""Power-cycle durable settings using two independently validated CE files.

Writes only the inactive slot. A torn write leaves the previously valid slot.
Logging stays on external MD; this directory holds only two 16-byte settings.
"""
from patch_updater_copy_safety import frame, end


def install(i, A, S):
    D=i.rw; api=i.api
    i.apis['read']=i.add_import('COREDLL.dll',170)
    S['config_dir']=i.string('\\Storage Card2\\MAXmade')
    S['config_paths']=[i.string('\\Storage Card2\\MAXmade\\debug-'+str(n)+'.cfg') for n in range(2)]
    A['readslot']=i.text+0xa000
    # Return v0=valid, v1=enabled, a1=sequence. Read 17 bytes to reject excess data.
    i.routine_at(A['readslot'],f'''{frame(0x60,['s0','s1'])}
lui a1, 0x8000
addiu a2, zero, 1
move a3, zero
addiu t0, zero, 3
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{api('open')}
move s0, v0
addiu t0, zero, -1
beq s0, t0, invalid
move s1, zero
move a0, s0
addiu a1, sp, 0x30
addiu a2, zero, 17
addiu a3, sp, 0x28
sw zero, 0x10(sp)
{api('read')}
beqz v0, close
nop
lw t0, 0x28(sp)
addiu t1, zero, 16
bne t0, t1, close
nop
lw t0, 0x30(sp)
lui t1, 0x4d58
ori t1, t1, 0x4420
bne t0, t1, close
nop
lw t1, 0x38(sp)
sltiu t2, t1, 2
beqz t2, close
nop
lw t2, 0x34(sp)
addu t0, t0, t2
addu t0, t0, t1
lui t1, 0xa55a
ori t1, t1, 0x5aa5
addu t0, t0, t1
lw t1, 0x3c(sp)
bne t0, t1, close
nop
addiu s1, zero, 1
close:
move a0, s0
{api('close')}
invalid:
move v0, s1
beqz s1, done
nop
lw v1, 0x38(sp)
lw a1, 0x34(sp)
done:
{end(0x60,['s0','s1'])}''',0x800,0x60,['s0','s1'])
    # Preserve registry reader only for one-time migration from MAX19.
    A['registryconfig']=i.text+0xa800
    old=next(r for r in i.routines if r['address']==A['readconfig'])
    oldcode=old['assembly']
    for name in ['readconfig','persist']:
        at=A[name]
        i.routines=[r for r in i.routines if r['address']!=at]
        i.rows=[r for r in i.rows if r[0]!=at]
        i.reloc=[r for r in i.reloc if not at-i.base<=r[0]<at-i.base+0x800]
    i.routine_at(A['registryconfig'],oldcode,0x800,0x50,['s0','s1'])
    i.routine_at(A['readconfig'],f'''{frame(0x50,['s0','s1','s2','s3'])}
la s0, {hex(D)}
sw zero, 0x3c(s0)
addiu t0, zero, 1
sw t0, 0x40(s0)
move s1, zero
move s2, zero
move s3, zero
la a0, {hex(S['config_paths'][0])}
jal {hex(A['readslot'])}
nop
beqz v0, second
nop
move s1, v1
move s2, a1
addiu s3, zero, 1
sw zero, 0x40(s0)
second:
la a0, {hex(S['config_paths'][1])}
jal {hex(A['readslot'])}
nop
beqz v0, selected
nop
beqz s3, newer
nop
subu t0, a1, s2
blez t0, selected
nop
newer:
move s1, v1
move s2, a1
addiu s3, zero, 1
addiu t0, zero, 1
sw t0, 0x40(s0)
selected:
sw s2, 0x3c(s0)
bnez s3, done
nop
jal {hex(A['registryconfig'])}
nop
move s1, v0
done:
move v0, s1
{end(0x50,['s0','s1','s2','s3'])}''',0x800,0x50,['s0','s1','s2','s3'])
    i.routine_at(A['persist'],f'''{frame(0x70,['s0','s1','s2','s3','s4'])}
move s1, a0
la s0, {hex(D)}
lw s2, 0x3c(s0)
addiu s2, s2, 1
lw s3, 0x40(s0)
xori s3, s3, 1
la a0, {hex(S['config_dir'])}
move a1, zero
{api('mkdir')}
la s4, {hex(S['config_paths'][0])}
beqz s3, path
nop
la s4, {hex(S['config_paths'][1])}
path:
move a0, s4
lui a1, 0x4000
move a2, zero
move a3, zero
addiu t0, zero, 2
sw t0, 0x10(sp)
lui t0, 0x8000
ori t0, t0, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{api('open')}
addiu t0, zero, -1
beq v0, t0, failed
move t0, v0
sw t0, 0x28(sp)
lui t0, 0x4d58
ori t0, t0, 0x4420
sw t0, 0x30(sp)
sw s2, 0x34(sp)
sw s1, 0x38(sp)
addu t0, t0, s2
addu t0, t0, s1
lui t1, 0xa55a
ori t1, t1, 0x5aa5
addu t0, t0, t1
sw t0, 0x3c(sp)
lw a0, 0x28(sp)
addiu a1, sp, 0x30
addiu a2, zero, 16
addiu a3, sp, 0x2c
sw zero, 0x10(sp)
{api('write')}
beqz v0, close_failed
nop
lw t0, 0x2c(sp)
addiu t1, zero, 16
bne t0, t1, close_failed
nop
lw a0, 0x28(sp)
{api('flush')}
beqz v0, close_failed
nop
lw a0, 0x28(sp)
{api('close')}
beqz v0, failed
nop
move a0, s4
jal {hex(A['readslot'])}
nop
beqz v0, failed
nop
bne a1, s2, failed
nop
bne v1, s1, failed
nop
sw s2, 0x3c(s0)
sw s3, 0x40(s0)
move v0, zero
b done
nop
close_failed:
lw a0, 0x28(sp)
{api('close')}
failed:
addiu v0, zero, 5
done:
{end(0x70,['s0','s1','s2','s3','s4'])}''',0x800,0x70,['s0','s1','s2','s3','s4'])
    # Leave clones above the new helper bank.
    i.code_cursor=max(i.code_cursor,0xb000)
