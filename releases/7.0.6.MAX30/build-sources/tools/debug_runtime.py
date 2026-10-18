"""MAX19 USB diagnostics: bounded shared queue and separate CE writer thread."""
from debug_image import Image
from patch_updater_copy_safety import frame,end

MAGIC=0x4d584400
MAP_BYTES=0x23000
RECORD=544
CAPACITY=256
REGS=['s0','s1','s2','s3','s4','s5','s6','s7']
ORDINALS={'last':516,'setlast':517,'mutex':555,'wait':497,'release':556,'mapping':548,'view':549,
    'close':553,'unview':550,'tick':535,'printf':56,'format':2666,'out':541,'nk':545,'thread':492,
    'priority':514,'resume':500,'sleep':496,'attrs':166,'mkdir':160,'open':168,'write':171,
    'flush':175,'first':167,'findclose':180,'space':184,'memory':88,'invalidate':250,
    'regopen':461,'regcreate':456,'regquery':463,'regset':464,'regclose':455,'increment':10,'regflush':1152,'time':23}


def build_core(image):
    i=image; T=i.text; D=i.rw
    i.apis={name:i.add_import('COREDLL.dll',ordinal) for name,ordinal in ORDINALS.items()}
    S={name:i.string(value) for name,value in {
        'mapping':'MAXmade_Debug_19_v1','mutex':'MAXmade_Debug_19_Queue',
        'owner':'MAXmade_Debug_19_Writer','key':'Software\\MAXmade\\Debug','enabled':'Enabled',
        'md':'\\MD','folder':'\\MD\\MAXmade','logs':'\\MD\\MAXmade\\logs',
        'path':'\\MD\\MAXmade\\logs\\debug-%u.log',
        'header':'\ufeffMAXmade 7.0.6.MAX19 diagnostics\r\nms\tmodule\tevent\tduration_ms\tresult\tlevel\tmessage\r\n',
        'line':'%u\t%u\t%u\t%u\t%u\t%u\t%s\r\n',
        'session':'session\t%04u-%02u-%02uT%02u:%02u:%02u.%03u\t%u\r\n',
        'empty':'','badformat':'[message formatting failed or truncated]',
    }.items()}
    A={name:T+off for name,off in {'ensure':0,'enqueue':0x800,'raw':0x1000,'nk':0x1400,
        'control':0x1c00,'readconfig':0x2c00,'persist':0x3400,'drain':0x3c00,
        'openfile':0x4400,'record':0x5400,'worker':0x5c00,'status':0x7000,'repair':0x7400}.items()}
    api=i.api
    def put(name,code,cap=0x800,n=0x60,regs=REGS):
        return i.routine_at(A[name],code,cap,n,regs)
    put('repair',f'''lw t0, 4(a0)
lw t1, 8(a0)
lw t2, 12(a0)
sltiu t3, t0, 256
beqz t3, reset
nop
sltiu t3, t1, 256
beqz t3, reset
nop
sltiu t3, t2, 257
beqz t3, reset
nop
subu t3, t1, t0
andi t3, t3, 255
andi t4, t2, 255
beq t3, t4, done
nop
reset:
sltiu t3, t2, 257
bnez t3, count
nop
addiu t2, zero, 256
count:
addiu t2, t2, 1
lw t3, 0x20(a0)
addu t3, t3, t2
sw t3, 0x20(a0)
sw zero, 4(a0)
sw zero, 8(a0)
sw zero, 12(a0)
done:
jr ra
nop''',cap=0x400,n=0,regs=[])
    put('ensure',f'''{frame(0x50,['s0','s1','s2','s3'])}
la s0, {hex(D)}
lw v0, 0(s0)
bnez v0, done
nop
move a0, zero
move a1, zero
la a2, {hex(S['mutex'])}
{api('mutex')}
beqz v0, fail
move s1, v0
move a0, s1
move a1, zero
{api('wait')}
beqz v0, owned
addiu t0, zero, 128
bne v0, t0, close_mutex
nop
owned:
addiu a0, zero, -1
move a1, zero
addiu a2, zero, 4
move a3, zero
lui t0, 2
ori t0, t0, 0x3000
sw t0, 0x10(sp)
la t0, {hex(S['mapping'])}
sw t0, 0x14(sp)
{api('mapping')}
beqz v0, release_fail
move s2, v0
move a0, s2
addiu a1, zero, 6
move a2, zero
move a3, zero
sw zero, 0x10(sp)
{api('view')}
beqz v0, close_map
move s3, v0
lw t0, 0(s3)
lui t1, 0x4d58
ori t1, t1, 0x1919
beq t0, t1, publish
nop
bnez t0, unmap_fail
nop
sw t1, 0(s3)
publish:
sw s1, 4(s0)
sw s2, 8(s0)
sync
sw s3, 0(s0)
move a0, s1
{api('release')}
move v0, s3
b done
nop
unmap_fail:
move a0, s3
{api('unview')}
close_map:
move a0, s2
{api('close')}
release_fail:
move a0, s1
{api('release')}
close_mutex:
move a0, s1
{api('close')}
fail:
move v0, zero
done:
{end(0x50,['s0','s1','s2','s3'])}''',n=0x50,regs=['s0','s1','s2','s3'])
    put('enqueue',f'''{frame(0x60,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
lw s4, 0x70(sp)
lw s5, 0x74(sp)
la s6, {hex(D)}
lw s7, 0(s6)
beqz s7, done
nop
lw t0, 0x10(s7)
beqz t0, done
nop
move a1, zero
lw a0, 4(s6)
{api('wait')}
beqz v0, owned
addiu t0, zero, 128
beq v0, t0, owned
nop
addiu a0, s7, 0x24
{api('increment')}
b done
nop
owned:
lw t0, 0x10(s7)
beqz t0, unlock
nop
jal {hex(A['repair'])}
move a0, s7
lw t0, 0xc(s7)
sltiu t1, t0, 256
beqz t1, dropped
nop
{api('tick')}
lw t0, 0x38(s7)
subu t1, v0, t0
sltiu t2, t1, 1000
bnez t2, quota
nop
sw v0, 0x38(s7)
sw zero, 0x3c(s7)
quota:
lw t0, 0x3c(s7)
sltiu t1, t0, 128
beqz t1, dropped
addiu t0, t0, 1
sw t0, 0x3c(s7)
lw t0, 8(s7)
sll t1, t0, 9
sll t2, t0, 5
addu t1, t1, t2
addu t1, t1, s7
addiu t1, t1, 0x100
sw v0, 0(t1)
sw s0, 4(t1)
sw s1, 8(t1)
sw s2, 12(t1)
sw s3, 16(t1)
sw s5, 20(t1)
sw zero, 24(t1)
sw zero, 28(t1)
addiu t2, t1, 32
move t3, zero
beqz s4, sealed
nop
copy:
lhu t4, 0(s4)
beqz t4, sealed
nop
sltiu t5, t3, 255
beqz t5, sealed
nop
sltiu t5, t4, 32
beqz t5, printable
nop
addiu t4, zero, 32
printable:
sh t4, 0(t2)
addiu s4, s4, 2
addiu t2, t2, 2
b copy
addiu t3, t3, 1
sealed:
sh zero, 0(t2)
sw t3, 24(t1)
addiu t0, t0, 1
andi t0, t0, 255
sw t0, 8(s7)
lw t0, 0xc(s7)
addiu t0, t0, 1
sw t0, 0xc(s7)
lw t0, 0x30(s7)
addiu t0, t0, 1
sw t0, 0x30(s7)
b unlock
nop
dropped:
lw t0, 0x20(s7)
addiu t0, t0, 1
sw t0, 0x20(s7)
unlock:
lw a0, 4(s6)
{api('release')}
done:
move v0, zero
{end(0x60,REGS)}''')
    put('raw',f'''{frame(0x38,['s0','s1','s2'])}
move s0, a0
{api('last')}
move s1, v0
la t0, {hex(D+0x38)}
lw t0, 0(t0)
beqz t0, forward
nop
jal {hex(A['ensure'])}
nop
beqz v0, forward
nop
move a0, zero
move a1, zero
move a2, zero
move a3, zero
sw s0, 0x10(sp)
sw zero, 0x14(sp)
jal {hex(A['enqueue'])}
nop
forward:
move a0, s1
{api('setlast')}
move a0, s0
{api('out')}
{end(0x38,['s0','s1','s2'])}''',cap=0x400,n=0x38,regs=['s0','s1','s2'])
    put('nk',f'''sw a1, 4(sp)
sw a2, 8(sp)
sw a3, 12(sp)
{frame(0x250,['s0','s1','s2'])}
move s0, a0
{api('last')}
move s1, v0
la t0, {hex(D+0x38)}
lw t0, 0(t0)
beqz t0, forward
nop
jal {hex(A['ensure'])}
nop
beqz v0, forward
nop
lw t0, 0x10(v0)
beqz t0, forward
nop
addiu a0, sp, 0x28
addiu a1, zero, 256
move a2, s0
addiu a3, sp, 0x254
{api('format')}
sh zero, 0x226(sp)
addiu s2, sp, 0x28
bgez v0, formatted
nop
la s2, {hex(S['badformat'])}
formatted:
move a0, zero
addiu a1, zero, 1
move a2, zero
move a3, zero
sw s2, 0x10(sp)
addiu t0, zero, 3
sw t0, 0x14(sp)
jal {hex(A['enqueue'])}
nop
forward:
move a0, s1
{api('setlast')}
move a0, s0
lw a1, 0x254(sp)
lw a2, 0x258(sp)
lw a3, 0x25c(sp)
lw s0, 0x248(sp)
lw s1, 0x244(sp)
lw s2, 0x240(sp)
lw ra, 0x24c(sp)
addiu sp, sp, 0x250
la t8, {hex(i.apis['nk'])}
lw t9, 0(t8)
jr t9
nop''',n=0x250,regs=['s0','s1','s2'])
    put('readconfig',f'''{frame(0x50,['s0','s1'])}
sw zero, 0x28(sp)
sw zero, 0x2c(sp)
lui a0, 0x8000
ori a0, a0, 2
la a1, {hex(S['key'])}
move a2, zero
addiu a3, zero, 1
addiu t0, sp, 0x28
sw t0, 0x10(sp)
{api('regopen')}
bnez v0, off
move s0, zero
lw a0, 0x28(sp)
la a1, {hex(S['enabled'])}
move a2, zero
addiu a3, sp, 0x30
addiu t0, sp, 0x2c
sw t0, 0x10(sp)
addiu t0, zero, 4
sw t0, 0x34(sp)
addiu t0, sp, 0x34
sw t0, 0x14(sp)
{api('regquery')}
bnez v0, close
nop
lw t0, 0x30(sp)
addiu t1, zero, 4
bne t0, t1, close
nop
lw t0, 0x34(sp)
bne t0, t1, close
nop
lw t0, 0x2c(sp)
addiu t1, zero, 1
beq t0, t1, one
nop
b close
nop
one:
addiu s0, zero, 1
close:
lw a0, 0x28(sp)
{api('regclose')}
off:
move v0, s0
{end(0x50,['s0','s1'])}''',n=0x50,regs=['s0','s1'])
    put('persist',f'''{frame(0x50,['s0','s1','s2'])}
move s0, a0
sw s0, 0x30(sp)
sw zero, 0x2c(sp)
lui a0, 0x8000
ori a0, a0, 2
la a1, {hex(S['key'])}
move a2, zero
move a3, zero
sw zero, 0x10(sp)
addiu t0, zero, 3
sw t0, 0x14(sp)
sw zero, 0x18(sp)
addiu t0, sp, 0x2c
sw t0, 0x1c(sp)
sw zero, 0x20(sp)
{api('regcreate')}
bnez v0, done
move s1, v0
beqz s1, flush_key
nop
b close_key
nop
flush_key:
lw a0, 0x2c(sp)
{api('regflush')}
move s1, v0
close_key:
lw a0, 0x2c(sp)
la a1, {hex(S['enabled'])}
move a2, zero
addiu a3, zero, 4
addiu t0, sp, 0x30
sw t0, 0x10(sp)
addiu t0, zero, 4
sw t0, 0x14(sp)
{api('regset')}
move s1, v0
lw a0, 0x2c(sp)
{api('regclose')}
done:
move v0, s1
{end(0x50,['s0','s1','s2'])}''',n=0x50,regs=['s0','s1','s2'])
    put('drain',f'''{frame(0x40,['s0','s1','s2'])}
la s0, {hex(D)}
lw s1, 0(s0)
lw a0, 4(s0)
addiu a1, zero, 10
{api('wait')}
beqz v0, owned
addiu t0, zero, 128
bne v0, t0, empty
nop
owned:
jal {hex(A['repair'])}
move a0, s1
lw t0, 0xc(s1)
beqz t0, unlock_empty
nop
lw t0, 4(s1)
sll t1, t0, 9
sll t2, t0, 5
addu t1, t1, t2
addu t1, t1, s1
addiu t1, t1, 0x100
la t2, {hex(D+0x400)}
addiu t3, zero, 136
copy:
lw t4, 0(t1)
sw t4, 0(t2)
addiu t1, t1, 4
addiu t2, t2, 4
addiu t3, t3, -1
bnez t3, copy
nop
addiu t0, t0, 1
andi t0, t0, 255
sw t0, 4(s1)
lw t0, 0xc(s1)
addiu t0, t0, -1
sw t0, 0xc(s1)
lw a0, 4(s0)
{api('release')}
addiu v0, zero, 1
b done
nop
unlock_empty:
lw a0, 4(s0)
{api('release')}
empty:
move v0, zero
done:
{end(0x40,['s0','s1','s2'])}''',n=0x40,regs=['s0','s1','s2'])
    # Rotation uses eight exclusively owned names. Never writes to internal cards.
    put('openfile',f'''{frame(0x290,['s0','s1','s2','s3','s4'])}
la s0, {hex(D)}
la a0, {hex(S['md'])}
{api('attrs')}
addiu t0, zero, -1
beq v0, t0, absent
nop
andi t0, v0, 16
beqz t0, absent
nop
la a0, {hex(S['md'])}
addiu a1, sp, 0x28
move a2, zero
move a3, zero
{api('space')}
beqz v0, failure
nop
lw t0, 0x2c(sp)
bnez t0, has_space
nop
lw t0, 0x28(sp)
lui t1, 0x100
sltu t2, t0, t1
bnez t2, full
nop
has_space:
la a0, {hex(S['folder'])}
move a1, zero
{api('mkdir')}
la a0, {hex(S['logs'])}
move a1, zero
{api('mkdir')}
lw s1, 0x1c(s0)
andi s1, s1, 7
la a0, {hex(D+0x1200)}
la a1, {hex(S['path'])}
move a2, s1
{api('printf')}
la a0, {hex(D+0x1200)}
lui a1, 0x4000
addiu a2, zero, 1
move a3, zero
addiu t0, zero, 2
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{api('open')}
addiu t0, zero, -1
beq v0, t0, failure
move s2, v0
sw s2, 0x14(s0)
sw zero, 0x18(s0)
addiu s1, s1, 1
andi s1, s1, 7
sw s1, 0x1c(s0)
move a0, s2
la a1, {hex(S['header'])}
addiu a2, zero, {len(('\ufeffMAXmade 7.0.6.MAX19 diagnostics\r\nms\tmodule\tevent\tduration_ms\tresult\tlevel\tmessage\r\n').encode('utf-16-le'))}
addiu a3, sp, 0x30
sw zero, 0x10(sp)
{api('write')}
beqz v0, close_failed
nop
lw t0, 0x30(sp)
addiu t1, zero, {len(('\ufeffMAXmade 7.0.6.MAX19 diagnostics\r\nms\tmodule\tevent\tduration_ms\tresult\tlevel\tmessage\r\n').encode('utf-16-le'))}
bne t0, t1, close_failed
nop
sw t0, 0x18(s0)
la a0, {hex(D+0x1700)}
la a1, {hex(S['session'])}
la t0, {hex(D+0x1520)}
lhu a2, 0(t0)
lhu a3, 2(t0)
lhu t1, 6(t0)
sw t1, 0x10(sp)
lhu t1, 8(t0)
sw t1, 0x14(sp)
lhu t1, 10(t0)
sw t1, 0x18(sp)
lhu t1, 12(t0)
sw t1, 0x1c(sp)
lhu t1, 14(t0)
sw t1, 0x20(sp)
lw t1, 0x2c(s0)
sw t1, 0x24(sp)
{api('printf')}
sll s3, v0, 1
move a0, s2
la a1, {hex(D+0x1700)}
move a2, s3
addiu a3, sp, 0x30
sw zero, 0x10(sp)
{api('write')}
beqz v0, close_failed
nop
lw t0, 0x30(sp)
bne t0, s3, close_failed
nop
lw t1, 0x18(s0)
addu t0, t0, t1
sw t0, 0x18(s0)
move a0, s2
{api('flush')}
beqz v0, close_failed
nop
addiu v0, zero, 2
b done
nop
close_failed:
move a0, s2
{api('close')}
addiu t0, zero, -1
sw t0, 0x14(s0)
failure:
addiu v0, zero, 3
b done
nop
full:
addiu v0, zero, 4
b done
nop
absent:
addiu v0, zero, 1
done:
{end(0x290,['s0','s1','s2','s3','s4'])}''',cap=0x1000,n=0x290,regs=['s0','s1','s2','s3','s4'])
    put('record',f'''{frame(0x50,['s0','s1','s2'])}
la s0, {hex(D)}
la s1, {hex(D+0x400)}
la a0, {hex(D+0x800)}
la a1, {hex(S['line'])}
lw a2, 0(s1)
lw a3, 4(s1)
lw t0, 8(s1)
sw t0, 0x10(sp)
lw t0, 12(s1)
sw t0, 0x14(sp)
lw t0, 16(s1)
sw t0, 0x18(sp)
lw t0, 20(s1)
sw t0, 0x1c(sp)
addiu t0, s1, 32
sw t0, 0x20(sp)
{api('printf')}
sll s2, v0, 1
lw t0, 0x18(s0)
addu t0, t0, s2
lui t1, 0x40
sltu t2, t1, t0
beqz t2, write_line
nop
lw a0, 0x14(s0)
{api('flush')}
lw a0, 0x14(s0)
{api('close')}
addiu t0, zero, -1
sw t0, 0x14(s0)
jal {hex(A['openfile'])}
nop
addiu t0, zero, 2
bne v0, t0, failed
nop
write_line:
lw a0, 0x14(s0)
la a1, {hex(D+0x800)}
move a2, s2
addiu a3, sp, 0x28
sw zero, 0x10(sp)
{api('write')}
beqz v0, failed
nop
lw t0, 0x28(sp)
bne t0, s2, failed
nop
lw t0, 0x18(s0)
addu t0, t0, s2
sw t0, 0x18(s0)
lw t0, 0(s0)
lw t1, 0x34(t0)
addiu t1, t1, 1
sw t1, 0x34(t0)
addiu v0, zero, 1
b done
nop
failed:
move v0, zero
done:
{end(0x50,['s0','s1','s2'])}''',n=0x50,regs=['s0','s1','s2'])
    put('status',f'''{frame(0x20,['s0'])}
la t0, {hex(D)}
lw s0, 0(t0)
lw t0, 0x1c(s0)
beq t0, a0, done
nop
sw a0, 0x1c(s0)
lw a0, 0x2c(s0)
beqz a0, done
nop
move a1, zero
move a2, zero
{api('invalidate')}
done:
{end(0x20,['s0'])}''',cap=0x400,n=0x20,regs=['s0'])
    put('worker',f'''{frame(0x70,REGS)}
la s0, {hex(D)}
lw s1, 0(s0)
move a0, zero
move a1, zero
la a2, {hex(S['owner'])}
{api('mutex')}
beqz v0, exit
move s7, v0
move a0, s7
move a1, zero
{api('wait')}
beqz v0, owner
addiu t0, zero, 128
bne v0, t0, close_owner
nop
owner:
lw t0, 0x24(s0)
bnez t0, release_owner
nop
addiu t0, zero, -1
sw t0, 0x14(s0)
{api('tick')}
sw v0, 0x2c(s0)
la a0, {hex(D+0x1520)}
{api('time')}
move s2, zero
move s3, zero
loop:
lw t0, 0x14(s1)
lw t1, 0x18(s1)
beq t0, t1, configured
nop
move s4, t0
lw a0, 0x10(s1)
jal {hex(A['persist'])}
nop
sw v0, 0x40(s1)
bnez v0, configured
nop
sw s4, 0x18(s1)
configured:
lw t0, 0x10(s1)
lw t1, 0x14(s0)
addiu t2, zero, -1
beq t1, t2, no_file
nop
la a0, {hex(S['md'])}
{api('attrs')}
addiu t0, zero, -1
beq v0, t0, close_file
nop
lw t0, 0x18(s0)
lui t1, 0x40
sltu t2, t0, t1
beqz t2, close_file
nop
addiu s5, zero, 64
drain_loop:
jal {hex(A['drain'])}
nop
beqz v0, drained
nop
jal {hex(A['record'])}
nop
beqz v0, write_failed
nop
addiu s5, s5, -1
bnez s5, drain_loop
nop
drained:
lw t0, 0x10(s1)
bnez t0, active
nop
lw t0, 0xc(s1)
bnez t0, sleep
nop
b close_file
nop
active:
nop
addiu a0, zero, 2
jal {hex(A['status'])}
nop
b sample
nop
write_failed:
{api('last')}
sw v0, 0x28(s1)
addiu a0, s1, 0x24
{api('increment')}
addiu a0, zero, 3
jal {hex(A['status'])}
nop
close_file:
lw a0, 0x14(s0)
{api('flush')}
lw a0, 0x14(s0)
{api('close')}
addiu t0, zero, -1
sw t0, 0x14(s0)
b sleep
nop
no_file:
lw t0, 0x10(s1)
beqz t0, disabled
nop
jal {hex(A['openfile'])}
nop
move a0, v0
jal {hex(A['status'])}
nop
b sample
nop
disabled:
move a0, zero
jal {hex(A['status'])}
nop
b sleep
nop
sample:
{api('tick')}
subu t0, v0, s3
sltiu t1, t0, 10000
bnez t1, flush_check
nop
move s3, v0
la a0, {hex(D+0x1500)}
addiu t0, zero, 32
sw t0, 0(a0)
{api('memory')}
addiu a0, zero, 1
addiu a1, zero, 900
la t0, {hex(D+0x1500)}
lw a2, 12(t0)
lw a3, 4(t0)
sw zero, 0x10(sp)
sw zero, 0x14(sp)
jal {hex(A['enqueue'])}
nop
lw t0, 0x20(s1)
lw t1, 0x24(s1)
addu a3, t0, t1
addiu a0, zero, 1
addiu a1, zero, 901
move a2, zero
sw zero, 0x10(sp)
sw zero, 0x14(sp)
jal {hex(A['enqueue'])}
nop
flush_check:
{api('tick')}
subu t0, v0, s2
sltiu t1, t0, 2000
bnez t1, sleep
nop
move s2, v0
lw a0, 0x14(s0)
addiu t0, zero, -1
beq a0, t0, sleep
nop
{api('flush')}
bnez v0, sleep
nop
addiu a0, zero, 3
jal {hex(A['status'])}
nop
b close_file
nop
sleep:
addiu a0, zero, 500
{api('sleep')}
b loop
nop
release_owner:
move a0, s7
{api('release')}
close_owner:
move a0, s7
{api('close')}
exit:
move v0, zero
{end(0x70,REGS)}''',cap=0x1400,n=0x70)
    # Reserved command IDs coexist with the native DbgDebugPrint ABI.
    i.code_cursor=0x8000
    native,row=i.clone(0x100013e8)
    # The clone's ordinary output goes through the same bounded adapter.
    offset=native-T+(0x1000158c-0x100013e8)
    import struct
    struct.pack_into('<I',i.body,offset,(3<<26)|((A['raw']>>2)&0x3ffffff))
    put('control',f'''lui t0, 0x4d58
ori t0, t0, 0x4400
andi t1, a0, 0xff
subu t2, a0, t1
beq t2, t0, command
nop
j {hex(native)}
nop
command:
{frame(0x70,REGS)}
move s0, t1
move s1, a1
move s2, a2
move s3, a3
{api('last')}
move s4, v0
jal {hex(A['ensure'])}
nop
beqz v0, failed
move s5, v0
addiu t0, zero, 1
beq s0, t0, start
nop
addiu t0, zero, 2
beq s0, t0, toggle
nop
addiu t0, zero, 3
beq s0, t0, query
nop
addiu t0, zero, 4
beq s0, t0, event
nop
addiu t0, zero, 6
beq s0, t0, window
nop
b failed
nop
query:
lw t0, 0x1c(s5)
sll t0, t0, 8
lw t1, 0x10(s5)
or s6, t0, t1
lw t0, 0x40(s5)
beqz t0, return
nop
ori s6, s6, 0x8000
b return
nop
event:
move a0, s1
move a1, s2
move a2, s3
lw a3, 0x80(sp)
sw zero, 0x10(sp)
sw zero, 0x14(sp)
jal {hex(A['enqueue'])}
nop
addiu s6, zero, 1
b return
nop
window:
sw s1, 0x2c(s5)
addiu s6, zero, 1
b return
nop
toggle:
la t0, {hex(D)}
lw a0, 4(t0)
move a1, zero
{api('wait')}
beqz v0, set
addiu t0, zero, 128
bne v0, t0, failed
nop
set:
sltu t0, zero, s1
sw t0, 0x10(s5)
lw t0, 0x14(s5)
addiu t0, t0, 1
sw t0, 0x14(s5)
la t0, {hex(D)}
lw a0, 4(t0)
{api('release')}
addiu s6, zero, 1
b return
nop
start:
la s7, {hex(D)}
lw t0, 0x44(s5)
bnez t0, thread
nop
jal {hex(A['readconfig'])}
nop
sw v0, 0x10(s5)
addiu t0, zero, 1
sw t0, 0x44(s5)
thread:
lw t0, 12(s7)
beqz t0, create_thread
nop
move s6, t0
lw t0, 0x28(s7)
bnez t0, set_priority
nop
move a0, s6
move a1, zero
{api('wait')}
addiu t0, zero, 258
beq v0, t0, query
nop
bnez v0, thread_failed
nop
move a0, s6
{api('close')}
sw zero, 12(s7)
create_thread:
sw zero, 0x24(s7)
move a0, zero
move a1, zero
la a2, {hex(A['worker'])}
move a3, zero
addiu t0, zero, 4
sw t0, 0x10(sp)
sw zero, 0x14(sp)
{api('thread')}
beqz v0, thread_failed
move s6, v0
sw s6, 12(s7)
set_priority:
sw zero, 0x24(s7)
move a0, s6
addiu a1, zero, 4
{api('priority')}
bnez v0, resume
nop
addiu t0, zero, 1
sw t0, 0x24(s7)
addiu t0, zero, 5
sw t0, 0x1c(s5)
resume:
move a0, s6
{api('resume')}
addiu t0, zero, -1
beq v0, t0, thread_failed
nop
sw zero, 0x28(s7)
b query
nop
thread_failed:
addiu t0, zero, 1
sw t0, 0x28(s7)
addiu t0, zero, 5
sw t0, 0x1c(s5)
failed:
move s6, zero
addiu t0, zero, 3
bne s0, t0, return
nop
addiu s6, zero, 0x500
return:
move a0, s4
{api('setlast')}
move v0, s6
{end(0x70,REGS)}''',cap=0x1000,n=0x70)
    # Entry dispatch is frameless; its framed command body gets its own row.
    r=next(r for r in i.rows if r[0]==A['control']);i.rows.remove(r)
    command_at=A['control']+32
    i.rows.extend([(A['control'],command_at,0,0,A['control']),
                  (command_at,r[1],0,0,command_at+8+len(REGS)*4)])
    for j,row in enumerate(i.rows):
        if row[0]==A['nk']:i.rows[j]=(row[0],row[1],row[2],row[3],row[0]+32)
    i.hook(0x100013e8,A['control'])
    # Native common debug calls also flow through the asynchronous queue.
    section=i.p.sections[0]
    for x in range(0,len(section.get_data())-3,4):
        w=int.from_bytes(section.get_data()[x:x+4],'little')
        if w==(3<<26)|((0x10003a30>>2)&0x3ffffff):i.hook(i.base+section.VirtualAddress+x,A['raw'],True)
    i.exports={'MxOutputDebugStringW':A['raw'],'MxNKDbgPrintfW':A['nk']}
    # Suppress lazy mapping/queue work during native DLL initialization/teardown.
    # Ordinary initialization debug output still reaches the original CE channel.
    dll_native,dll_row=i.clone(0x10001000)
    dll_wrapper=i.routine(f'''{frame(0x38,['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
move s2, a2
la t0, {hex(D+0x38)}
lw s3, 0(t0)
sw zero, 0(t0)
native:
move a0, s0
move a1, s1
jal {hex(dll_native)}
move a2, s2
sw v0, 0x14(sp)
beqz s1, detached
nop
addiu t1, zero, 1
bne s1, t1, restored
nop
beqz v0, restored
nop
addiu s3, zero, 1
b restored
nop
detached:
move s3, zero
restored:
la t0, {hex(D+0x38)}
sw s3, 0(t0)
done:
lw v0, 0x14(sp)
{end(0x38,['s0','s1','s2','s3'])}''',0x400,0x38,['s0','s1','s2','s3'])
    i.hook(0x10001000,dll_wrapper)
    A['dll_native']=dll_native;A['dll_wrapper']=dll_wrapper
    return dict(addresses=A,strings=S,record_bytes=RECORD,queue_records=CAPACITY,mapping_bytes=MAP_BYTES,
        max_records_per_second=128,log_slots=8,max_file_bytes=4*1024*1024,minimum_free_bytes=16*1024*1024)
