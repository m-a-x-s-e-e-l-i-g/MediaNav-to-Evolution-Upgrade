"""Bounded poll summaries and call-site diagnostics; preserve native operations."""
import struct
from patch_updater_copy_safety import frame,end
from debug_clients20 import command

REGS=['s0','s1','s2','s3','s4','s5','s6','s7']
APP_STATE=0x214d00
MEMORY_HELPER_OFFSET=0x13000


def timed_call(i,dbg,tick,target,module,event,label,register=None,result_argument=False,counter=None):
    """Keep original 13 arguments, dynamic target, v0/v1, nonvolatiles and LastError."""
    save='\n'.join(f'lw t0, {0x90+j*4}(sp)\nsw t0, {0x10+j*4}(sp)' for j in range(9))
    invoke=f'lw t9, 0x48(sp)\njalr t9\nnop' if register else f'jal {hex(target)}\nnop'
    count=''
    if counter is not None:
        count=f'''beqz s6, counted
nop
la a0, {hex(APP_STATE+counter)}
{i.api('increment')}
counted:'''
    code=f'''{frame(0x80,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
{f'sw {register}, 0x48(sp)' if register else ''}
la t8, {hex(i.last)}
lw t9, 0(t8)
jalr t9
nop
sw v0, 0x44(sp)
{command(i,dbg,3)}
andi s4, v0, 1
beqz s4, original
nop
la t8, {hex(tick)}
lw t9, 0(t8)
jalr t9
nop
move s5, v0
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
move a3, s3
{invoke}
move s6, v0
move s7, v1
la t8, {hex(i.last)}
lw t9, 0(t8)
jalr t9
nop
sw v0, 0x44(sp)
beqz s4, finish
nop
{count}
la t8, {hex(tick)}
lw t9, 0(t8)
jalr t9
nop
subu a3, v0, s5
addiu a1, zero, {module}
addiu a2, zero, {event}
sw {'s0' if result_argument else 's6'}, 0x10(sp)
{command(i,dbg,4)}
finish:
lw a0, 0x44(sp)
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
move v0, s6
move v1, s7
{end(0x80,REGS)}'''
    at=i.routine(code,0x400,0x80,REGS)
    return dict(wrapper=at,target=target,target_register=register,module=module,event=event,label=label,
                result_is_argument0=result_argument,counter_offset=counter)


def patch_call(i,site,wrapper):
    word=(3<<26)|((wrapper>>2)&0x3ffffff)
    if i.text<=site<i.text+len(i.body):
        struct.pack_into('<I',i.body,site-i.text,word)
        i.reloc=[r for r in i.reloc if r[0]!=site-i.base]
        i.reloc.append((site-i.base,5,None))
    else:i.hook(site,wrapper,True)


def sample_call(i,dbg,event):
    return f'''{command(i,dbg,3)}
andi t0, v0, 1
beqz t0, sampled_{event}
nop
addiu a0, zero, {event}
jal {hex(i.text+MEMORY_HELPER_OFFSET)}
nop
sampled_{event}:'''


def app_metrics(i,dbg,tick,hooks):
    assert not any(i.p.get_data(APP_STATE-i.base,0x100))
    i.code_cursor=MEMORY_HELPER_OFFSET
    i.routine(f'''{frame(0x40,['s0','s1'])}
move s0, a0
la s1, {hex(APP_STATE)}
addiu a0, s1, 0x10
addiu t0, zero, 32
sw t0, 0(a0)
{i.api('memory')}
addiu a1, zero, 1
move a2, s0
lw a3, 0x1c(s1)
lw t0, 0x14(s1)
sw t0, 0x10(sp)
{command(i,dbg,4)}
addiu a1, zero, 1
addiu a2, zero, 904
lw a3, 0(s1)
lw t0, 4(s1)
sw t0, 0x10(sp)
{command(i,dbg,4)}
{end(0x40,['s0','s1'])}''',0x400,0x40,['s0','s1'])
    calls=[]
    src=next(h for h in hooks if h['entry']==0xd9f04)
    shift=src['clone']-src['entry']
    # Verified three distinct conditional waits; no wait value/order is changed.
    for event,site in [(120,0xda13c),(121,0xda22c),(122,0xda364)]:
        assert i.p.get_data(site-i.base,4)==struct.pack('<I',0x0100f809)
        row=timed_call(i,dbg,tick,None,1,event,'source_sleep_'+str(event),register='t0',result_argument=True)
        row.update(original_site=site,site=site+shift);patch_call(i,row['site'],row['wrapper']);calls.append(row)
    # IpcSendMsg includes zero-result retries and mode readiness calls.
    for register,sites,event,label in [
        ('t0',[0xda104,0xda12c,0xda1d4,0xda1f4,0xda21c,0xda30c,0xda32c,0xda354,0xda830],130,'source_ipc_send'),
        ('t1',[0xdaa94],130,'source_ipc_send'),
        ('t0',[0xd9f74,0xda3e0,0xda50c,0xda560,0xda7cc,0xda980],131,'source_ipc_get'),
        ('t0',[0xda894,0xdaaf0],132,'source_ipc_post')]:
        row=timed_call(i,dbg,tick,None,1,event,label,register=register)
        for site in sites:
            r=dict(row,original_site=site,site=site+shift)
            assert i.p.get_data(site-i.base,4)==struct.pack('<I',0x0100f809 if register=='t0' else 0x0120f809)
            patch_call(i,r['site'],r['wrapper']);calls.append(r)
    art=next(h for h in hooks if h['entry']==0x222000);shift=art['clone']-art['entry']
    for event,sites,target,reg,label,count in [
        (320,[0x222064],0x220000,None,'artwork_jpeg_validate',None),
        (321,[0x2220b0],None,'t9','artwork_factory_create',None),
        (322,[0x2220fc],None,'t9','artwork_image_from_buffer',None),
        (323,[0x222150],None,'t9','artwork_image_info',None),
        (324,[0x222204],0x140188,None,'artwork_bitmap_create',0),
        (325,[0x222294],None,'t9','artwork_image_draw',None),
        (326,[0x2222dc,0x2222f8],None,'t9','artwork_object_release',None),
        (327,[0x22232c],0x140138,None,'artwork_bitmap_delete',4)]:
        row=timed_call(i,dbg,tick,target,1,event,label,register=reg,counter=count)
        for site in sites:
            expected=0x0320f809 if reg else (3<<26)|((target>>2)&0x3ffffff)
            assert i.p.get_data(site-i.base,4)==struct.pack('<I',expected)
            r=dict(row,original_site=site,site=site+shift);patch_call(i,r['site'],r['wrapper']);calls.append(r)
    delete=next(r for r in calls if r['event']==327)
    for site in [0x23129c,0x233160,0x233828]:
        assert i.p.get_data(site-i.base,4)==struct.pack('<I',(3<<26)|(0x140138>>2))
        r=dict(delete,original_site=site,site=site);patch_call(i,site,r['wrapper']);calls.append(r)
    assert i.code_cursor<=0x18000
    return dict(calls=calls,state_va=APP_STATE,memory_helper=i.text+MEMORY_HELPER_OFFSET,
                memory_before_event=902,memory_after_event=903,bitmap_counts_event=904,
                scope='Global RAM snapshots and successful artwork bitmap operations while debugging is enabled; not per-process allocation ownership.')


def poll_wrapper(i,dbg,tick,entry,module,event,label):
    target,row=i.clone(entry);D=i.rw+0x100
    save='\n'.join(f'lw t0, {0x90+j*4}(sp)\nsw t0, {0x10+j*4}(sp)' for j in range(9))
    code=f'''{frame(0x80,REGS)}
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
la t8, {hex(tick)}
lw t9, 0(t8)
jalr t9
nop
move s5, v0
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
beqz s4, disabled
nop
la t8, {hex(tick)}
lw t9, 0(t8)
jalr t9
nop
subu t2, v0, s5
sw t2, 0x4c(sp)
la t0, {hex(D)}
lw t1, 0(t0)
addiu t1, t1, 1
sw t1, 0(t0)
lw t1, 4(t0)
sltu t3, t1, t2
beqz t3, maximum
nop
sw t2, 4(t0)
maximum:
lw t1, 8(t0)
bnez t1, interval
nop
sw s5, 8(t0)
move t1, s5
interval:
subu t1, v0, t1
sltiu t3, t1, 10000
bnez t3, changed
nop
sw v0, 8(t0)
addiu a1, zero, 3
addiu a2, zero, 302
lw a3, 0(t0)
lw t1, 4(t0)
sw t1, 0x10(sp)
sw zero, 0(t0)
sw zero, 4(t0)
{command(i,dbg,4)}
changed:
lw a3, 0x4c(sp)
bnez s6, emit
nop
sltiu t0, a3, 16
bnez t0, finish
nop
emit:
addiu a1, zero, 3
addiu a2, zero, 301
sw s6, 0x10(sp)
{command(i,dbg,4)}
b finish
nop
disabled:
la t0, {hex(D)}
sw zero, 0(t0)
sw zero, 4(t0)
sw zero, 8(t0)
finish:
lw a0, 0x44(sp)
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
move v0, s6
move v1, s7
{end(0x80,REGS)}'''
    wrapper=i.routine(code,0x800,0x80,REGS);i.hook(entry,wrapper)
    return dict(entry=entry,clone=target,wrapper=wrapper,module=module,event=event,label=label,
                minimum_duration_ms=16,begin_logged=False,poll_summary_event=302,poll_state=D,
                summary_interval_ms=10000,emit_nonzero_result=True)
