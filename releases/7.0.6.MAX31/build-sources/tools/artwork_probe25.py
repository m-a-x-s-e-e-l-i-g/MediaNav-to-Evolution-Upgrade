"""Read-only scalar observation of the retained Blue artwork acquisition path.

Only synchronous callers inspect their borrowed arguments. The GUI-side poll
copies private scalar slots using a non-spinning sequence check; no CSR object
or received packet pointer escapes its owning callback. Firmware is never run.
"""
from debug_image import Image
from debug_clients23 import instrument, command
from debug_metrics21 import poll_wrapper as previous_poll
from patch_updater_copy_safety import frame, end

REGS=['s0','s1','s2','s3','s4','s5','s6','s7']
FIRST=950
COUNT=17
CONTROLLER=0x424  # owner 32 + framer 1028


def load_phase(arg='s0', dest='t0'):
    return f'''move {dest}, zero
beqz {arg}, phase_done
nop
lw {dest}, {CONTROLLER}({arg})
phase_done:'''


def helpers(i,dbg,tick):
    state=i.rw+0x400
    # Each slot: sequence/value/result/emitted tick/emitted value/result/present.
    record=i.routine(f'''{frame(0x40,['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
move s2, a2
sll t0, s0, 5
la s3, {hex(state)}
addu s3, s3, t0
lw t0, 0(s3)
addiu t0, t0, 1
sw t0, 0(s3)
sync
sw s1, 4(s3)
sw s2, 8(s3)
lw t1, 24(s3)
addiu t2, zero, 1
sw t2, 24(s3)
sync
addiu t0, t0, 1
sw t0, 0(s3)
sw t1, 0x20(sp)
la t8, {hex(tick)}
lw t9, 0(t8)
jalr t9
nop
lw t1, 0x20(sp)
beqz t1, emit
nop
lw t0, 16(s3)
bne t0, s1, changed
nop
lw t0, 20(s3)
beq t0, s2, done
nop
changed:
lw t0, 12(s3)
subu t0, v0, t0
sltiu t0, t0, 1000
bnez t0, done
nop
emit:
sw v0, 12(s3)
sw s1, 16(s3)
sw s2, 20(s3)
addiu a1, zero, 3
addiu a2, s0, {FIRST}
move a3, s1
sw s2, 0x10(sp)
{command(i,dbg,4)}
done:
{end(0x40,['s0','s1','s2','s3'])}''',0x800,0x40,['s0','s1','s2','s3'])
    # One private scalar snapshot per 10s, including availability mask. This is
    # not an atomic snapshot across different operations or a retry policy.
    snapshot=i.routine(f'''{frame(0x50,['s0','s1','s2','s3','s4','s5','s6'])}
la s0, {hex(state)}
la t8, {hex(tick)}
lw t9, 0(t8)
jalr t9
nop
lw t0, {COUNT*32}(s0)
lw t1, {COUNT*32+4}(s0)
beqz t1, due
nop
subu t1, v0, t0
sltiu t1, t1, 10000
bnez t1, done
nop
due:
sw v0, {COUNT*32}(s0)
addiu t0, zero, 1
sw t0, {COUNT*32+4}(s0)
move s1, zero
move s5, zero
addiu s6, zero, 1
loop:
lw s2, 0(s0)
andi t0, s2, 1
bnez t0, next
nop
lw t0, 24(s0)
beqz t0, next
nop
sync
lw s3, 4(s0)
lw s4, 8(s0)
sync
lw t0, 0(s0)
bne s2, t0, next
nop
or s5, s5, s6
addiu a1, zero, 3
addiu a2, s1, 980
move a3, s3
sw s4, 0x10(sp)
{command(i,dbg,4)}
next:
sll s6, s6, 1
addiu s0, s0, 32
addiu s1, s1, 1
sltiu t0, s1, {COUNT}
bnez t0, loop
nop
addiu a1, zero, 3
addiu a2, zero, 979
move a3, s5
addiu t0, zero, 25
sw t0, 0x10(sp)
{command(i,dbg,4)}
done:
{end(0x50,['s0','s1','s2','s3','s4','s5','s6'])}''',0x800,0x50,['s0','s1','s2','s3','s4','s5','s6'])
    return dict(state=state,record=record,snapshot=snapshot,slots=COUNT,
                first_event=FIRST,summary_event=979,minimum_change_interval_ms=1000,
                summary_interval_ms=10000)


def observe(i,dbg,info,entry,event,label,before='',after='',result='s6'):
    target,row=i.clone(entry)
    assert row[2]==0, 'Only handler-free optional artwork helpers are wrapped'
    # Original 13-argument ABI and both return registers/LastError survive.
    save='\n'.join(f'lw t0, {0xa0+j*4}(sp)\nsw t0, {0x10+j*4}(sp)' for j in range(9))
    code=f'''{frame(0x90,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
la t8, {hex(i.last)}
lw t9, 0(t8)
jalr t9
nop
sw v0, 0x44(sp)
{command(i,dbg,3)}
andi s4, v0, 1
beqz s4, original
nop
sw zero, 0x50(sp)
sw zero, 0x54(sp)
{before}
original:
{save}
lw a0, 0x44(sp)
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
move a0, s0
move a1, s1
move a2, s2
jal {hex(target)}
move a3, s3
move s6, v0
move s7, v1
la t8, {hex(i.last)}
lw t9, 0(t8)
jalr t9
nop
sw v0, 0x44(sp)
beqz s4, finish
nop
{after}
addiu a0, zero, {event-FIRST}
lw a1, 0x50(sp)
move a2, {result}
jal {hex(info['record'])}
nop
finish:
lw a0, 0x44(sp)
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
move v0, s6
move v1, s7
{end(0x90,REGS)}'''
    wrapper=i.routine(code,0x800,0x90,REGS);i.hook(entry,wrapper)
    return dict(entry=entry,clone=target,wrapper=wrapper,event=event,label=label,
                before=before,after=after,result_register=result)


def probes(i,dbg,tick):
    info=helpers(i,dbg,tick);rows=[]
    def hook(entry,event,label,**kw):rows.append(observe(i,dbg,info,entry,event,label,**kw))
    # Original capture dereferences this peer synchronously; do not retain it.
    hook(0x270400,950,'discovery',before='''addiu t0, zero, 1
sw t0, 0x54(sp)
beqz s2, captured
nop
lhu t0, 0xc8(s2)
lhu t1, 0xca(s2)
sll t2, t0, 16
or t2, t2, t1
sw t2, 0x50(sp)
addiu t2, zero, 2
lw t3, 0x120(s2)
beqz t3, reason
nop
addiu t2, zero, 3
sltiu t3, t0, 0x104
bnez t3, reason
nop
addiu t2, zero, 4
andi t3, t1, 0x100
beqz t3, reason
nop
addiu t2, zero, 5
lw t3, 0x11c(s2)
beqz t3, reason
nop
addiu t2, zero, 6
la t3, 0x300000
lhu t3, 0(t3)
ori t4, zero, 0xffff
beq t3, t4, reason
nop
addiu t2, zero, 7
reason:
sw t2, 0x54(sp)
captured:''',after='''move t7, zero
bnez s6, accepted
nop
lw t7, 0x54(sp)
accepted:''',result='t7')
    hook(0x268000,951,'SDP record extraction',after='sltu t7, zero, s6',result='t7')
    hook(0x267000,952,'cover endpoint parsing',before='sw s1, 0x50(sp)')
    hook(0x275400,953,'selected peer resolution',before='''la t0, 0x300204
lw t0, 0(t0)
sltu t0, zero, t0
la t1, 0x300240
lw t1, 0(t1)
sltu t1, zero, t1
sll t1, t1, 1
or t0, t0, t1
sw t0, 0x50(sp)''',after='sltu t7, zero, s6',result='t7')
    hook(0x274400,954,'owner and controller state',after=f'''beqz s0, sampled
nop
lw t0, 0(s0)
andi t0, t0, 255
lw t1, 24(s0)
andi t1, t1, 255
sll t1, t1, 8
or t0, t0, t1
lw t1, {CONTROLLER}(s0)
andi t1, t1, 255
sll t1, t1, 16
or t0, t0, t1
sw t0, 0x50(sp)
sampled:''')
    hook(0x246400,955,'cover channel open',before='sw s2, 0x50(sp)')
    hook(0x251000,956,'cover channel opened',before=load_phase()+'\nsw t0, 0x50(sp)')
    hook(0x249000,957,'OBEX CONNECT parsing',before='''andi t0, s1, 65535
sll t0, t0, 16
sw t0, 0x50(sp)
beqz s0, header_done
nop
sltiu t1, s1, 1
bnez t1, header_done
nop
lbu t1, 0(s0)
or t0, t0, t1
sltiu t1, s1, 4
bnez t1, header_store
nop
lbu t1, 3(s0)
sll t1, t1, 8
or t0, t0, t1
header_store:
sw t0, 0x50(sp)
header_done:''')
    hook(0x263400,958,'cover handle request')
    hook(0x24f800,959,'cover handle parsing',before='sw s1, 0x50(sp)')
    hook(0x24f400,960,'image request encoding',before='sw s1, 0x50(sp)')
    hook(0x24a000,961,'image response parsing',before='sw s2, 0x50(sp)')
    hook(0x252000,962,'controller response',before=load_phase()+'\nsw t0, 0x50(sp)',
         after=f'''beqz s0, process_done
nop
lw t0, 0x50(sp)
sll t0, t0, 16
lw t1, {CONTROLLER}(s0)
andi t1, t1, 65535
or t0, t0, t1
sw t0, 0x50(sp)
process_done:''')
    hook(0x257000,963,'controller cancellation',before=load_phase()+'\nsw t0, 0x50(sp)')
    hook(0x255000,964,'controller deadline check',before=load_phase()+'\nsw t0, 0x50(sp)')
    hook(0x245400,965,'cover task initialization',after='''beqz s0, init_done
nop
lw t0, 0(s0)
beqz t0, init_done
nop
lw t0, 24(t0)
sw t0, 0x50(sp)
init_done:''')
    hook(0x271800,966,'legacy track request',after='''la t0, 0x300240
lw t0, 0(t0)
sltu t0, zero, t0
sw t0, 0x50(sp)
sltu t7, zero, s6''',result='t7')
    info['hooks']=rows
    return info


def build(raw,pin,extension=None):
    i=Image(raw,pin)
    i.replace_imports={(b'coredll.dll',541):('CmnDll.dll','MxOutputDebugStringW'),
                       (b'coredll.dll',545):('CmnDll.dll','MxNKDbgPrintfW')}
    try:dbg=i.import_at('DbgDebugPrint')
    except StopIteration:dbg=i.add_import('CmnDll.dll','DbgDebugPrint')
    i.last=i.import_at(516)
    try:i.setlast=i.import_at(517)
    except StopIteration:i.setlast=i.add_import('COREDLL.dll',517)
    tick=i.add_import('COREDLL.dll',535)
    events=[instrument(i,dbg,tick,0x1ace4,3,300,'bluetooth_audio_start')]
    poll=previous_poll(i,dbg,tick,0x280400,3,301,'artwork_publish')
    # Preserve the previous poll metric implementation verbatim, adding only
    # one gated observer call after its original function and metric work.
    r=i.routines[-1];assert r['address']==poll['wrapper']
    source=r['assembly'];needle='finish:\nlw a0, 0x44(sp)';assert source.count(needle)==1
    info=probes(i,dbg,tick)
    source=source.replace(needle,f'''finish:
beqz s4, restore_error
nop
jal {hex(info['snapshot'])}
nop
restore_error:
lw a0, 0x44(sp)''')
    i.rows=[r for r in i.rows if r[0]!=poll['wrapper']]
    i.routines=[r for r in i.routines if r['address']!=poll['wrapper']]
    i.reloc=[r for r in i.reloc if not poll['wrapper']-i.base<=r[0]<poll['wrapper']-i.base+0x800]
    i.routine_at(poll['wrapper'],source,0x800,0x80,REGS)
    events.append(poll)
    extra=extension(i,dbg,tick) if extension else None
    candidate,recipe=i.finish()
    recipe.update(binary='Blue.exe',events=events,settings=None,metrics=None,
                  capture_native_output=True,artwork_diagnostics=info)
    if extra is not None:recipe['iphone_advertisement']=extra
    return candidate,recipe
