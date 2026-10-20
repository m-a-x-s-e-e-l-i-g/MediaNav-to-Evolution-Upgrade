"""Bounded NNG action/UI timings and native GTMC accounting, not process RSS.

Only synchronous allocator arguments are read; periodic samples use private
scalars. No routes, coordinates, filenames, handles or message arguments log.
"""
from gps_probe24 import build as gps_build
from patch_updater_copy_safety import frame,end
from debug_runtime20 import MAGIC

REGS=['s0','s1','s2','s3','s4','s5','s6','s7']
ACTIONS={1000:(0x417df4,'route recalculation request handler'),
         1001:(0x417ecc,'abort calculation request handler'),
         1002:(0x418b70,'refresh navigated route parameters handler')}
CATEGORIES=['paint window handler','other window handler',
            'message preprocessing','repaint request / synchronous UpdateWindow']


def extend(i,resolver,backend,safe_cache=False,compact=False):
    D=i.rw+0x400
    i.apis['memory']=i.import_at(88)
    def debug(cmd):
        return f'''la t8, {hex(backend)}
lw t9, 0(t8)
la a0, {hex(MAGIC+cmd)}
jalr t9
nop'''
    def emit(event,value,result):
        return f'''addiu a1, zero, 8
la a2, {hex(event)}
{value}
{result}
{debug(4)}'''
    # Shared scalar lock. Never spin or hold across logging/native calls.
    def lock():
        return f'''la a0, {hex(D)}
addiu a1, zero, 1
move a2, zero
{i.api('cas')}
bnez v0, done
nop'''
    unlock=f'''sync
la t0, {hex(D)}
sw zero, 0(t0)'''
    # One common helper updates interval count/total/max/>=50ms by category.
    update=i.routine(f'''{frame(0x40,['s0','s1'])}
move s0, a0
move s1, a1
{lock()}
sll t0, s0, 4
la t1, {hex(D+0x40)}
addu t1, t1, t0
lw t0, 0(t1)
addiu t0, t0, 1
sw t0, 0(t1)
lw t0, 4(t1)
addu t0, t0, s1
sw t0, 4(t1)
lw t0, 8(t1)
sltu t2, t0, s1
beqz t2, maximum
nop
sw s1, 8(t1)
maximum:
sltiu t0, s1, 50
bnez t0, counted
nop
lw t0, 12(t1)
addiu t0, t0, 1
sw t0, 12(t1)
counted:
{unlock}
done:
{end(0x40,['s0','s1'])}''',0x400,0x40,['s0','s1'])
    # Copy only scalar native fields while the original allocator's caller
    # still owns a valid manager. Peak is a lower bound of observations.
    pool=i.routine(f'''{frame(0x40,['s0'])}
move s0, a0
{lock()}
lw t1, 0(s0)
la t0, {hex(D)}
sw t1, 0x10(t0)
{'''lw t2, 12(s0)
beqz t2, cache_disabled
nop
lw t2, 0x14(s0)
b cache_ready
nop
cache_disabled:
move t2, zero
cache_ready:''' if safe_cache else 'lw t2, 0x14(s0)'}
sw t2, 0x14(t0)
lw t2, 0x18(t0)
sltu t3, t2, t1
beqz t3, peak
nop
sw t1, 0x18(t0)
peak:
addiu t1, zero, 1
sw t1, 0x1c(t0)
{unlock}
done:
{end(0x40,['s0'])}''',0x400,0x40,['s0'])
    # A stack-local OS snapshot plus a locked copy of native-pool accounting.
    # Event 1040/1041: action id / available physical bytes.
    # 1020: available / total physical bytes; 1021: load % / 0.
    # 1022: native pages / native cache bytes; 1023: peak / observed bit.
    # 1024: action id (0 periodic) / snapshot phase event.
    memory=i.routine(f'''{frame(0x70,['s0','s1','s2','s3'])}
move s0, a0
move s1, a1
addiu a0, sp, 0x20
addiu t0, zero, 32
sw t0, 0(a0)
{i.api('memory')}
{emit(1020,'lw a3, 0x2c(sp)','lw t0, 0x28(sp)\nsw t0, 0x10(sp)')}
{emit(1021,'lw a3, 0x24(sp)','sw zero, 0x10(sp)')}
beqz s0, pool_copy
nop
addiu a1, zero, 8
move a2, s0
move a3, s1
lw t0, 0x2c(sp)
sw t0, 0x10(sp)
{debug(4)}
pool_copy:
{lock()}
la t0, {hex(D)}
lw s2, 0x10(t0)
lw s3, 0x14(t0)
lw t1, 0x18(t0)
sw t1, 0x40(sp)
lw t1, 0x1c(t0)
sw t1, 0x44(sp)
{unlock}
lw t0, 0x44(sp)
beqz t0, unavailable
nop
{emit(1022,'move a3, s2','sw s3, 0x10(sp)')}
unavailable:
{emit(1023,'lw a3, 0x40(sp)','lw t0, 0x44(sp)\nsw t0, 0x10(sp)')}
done:
{emit(1024,'move a3, s1','sw s0, 0x10(sp)')}
{end(0x70,['s0','s1','s2','s3'])}''',0x800,0x70,['s0','s1','s2','s3'])
    # Called only when the existing reactor returns: no new timer/thread, no
    # idle wait included in work timings. Delayed reactors delay samples too.
    copy='\n'.join(f'lw t1, {0x40+j*4}(t0)\nsw t1, {0x20+j*4}(sp)\nsw zero, {0x40+j*4}(t0)' for j in range(16))
    emissions='\n'.join((f'lw t0, {0x20+c*16}(sp)\nbeqz t0, empty_{c}\nnop\n' if compact else '')+
        emit(1010+c*2,f'lw a3, {0x20+c*16}(sp)',f'lw t0, {0x24+c*16}(sp)\nsw t0, 0x10(sp)')+'\n'+
        emit(1011+c*2,f'lw a3, {0x28+c*16}(sp)',f'lw t0, {0x2c+c*16}(sp)\nsw t0, 0x10(sp)')+
        (f'\nempty_{c}:' if compact else '') for c in range(4))
    periodic=i.routine(f'''{frame(0x80,['s0'])}
{i.api('tick')}
move s0, v0
{lock()}
la t0, {hex(D)}
lw t1, 4(t0)
beqz t1, sample
nop
lw t1, 8(t0)
subu t1, s0, t1
sltiu t2, t1, 5000
bnez t2, early
nop
sample:
sw s0, 8(t0)
addiu t1, zero, 1
sw t1, 4(t0)
{copy}
{unlock}
{emissions}
move a0, zero
move a1, zero
jal {hex(memory)}
nop
b done
nop
early:
{unlock}
done:
{end(0x80,['s0'])}''',0xc00,0x80,['s0'])
    rows=[]
    def observe(entry,label,kind,event=0,category=0):
        target,row=i.clone(entry);assert row[2]==0
        save='\n'.join(f'lw t0, {0x90+j*4}(sp)\nsw t0, {0x10+j*4}(sp)' for j in range(9))
        before='';after=''
        if kind=='action':
            before=f'''addiu a0, zero, 1040
addiu a1, zero, {event}
jal {hex(memory)}
nop
{emit(0x80000000|event,'move a3, zero','sw zero, 0x10(sp)')}
{i.api('tick')}
move s5, v0'''
            after=f'''{i.api('tick')}
subu s5, v0, s5
{emit(event,'move a3, s5','sw zero, 0x10(sp)')}
addiu a0, zero, 1041
addiu a1, zero, {event}
jal {hex(memory)}
nop'''
        elif kind=='ui':
            before=f'''{i.api('tick')}
move s5, v0'''
            classify=f'''addiu a0, zero, {category}'''
            if entry==0x254140:
                classify='''move a0, zero
addiu t0, zero, 15
beq s1, t0, classified
nop
addiu a0, zero, 1
classified:'''
            after=f'''{i.api('tick')}
subu a1, v0, s5
{classify}
jal {hex(update)}
nop'''
        elif kind=='pool':
            after=f'''move a0, s0
jal {hex(pool)}
nop'''
        elif kind=='periodic':after=f'jal {hex(periodic)}\nnop'
        code=f'''{frame(0x80,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
{i.api('last')}
sw v0, 0x44(sp)
{f'jal {hex(resolver)}' if kind!='pool' else 'nop'}
nop
move s4, zero
la t0, {hex(backend)}
lw t0, 0(t0)
beqz t0, original
nop
{debug(3)}
andi s4, v0, 1
beqz s4, original
nop
{before}
original:
{save}
lw a0, 0x44(sp)
{i.api('setlast')}
move a0, s0
move a1, s1
move a2, s2
move a3, s3
jal {hex(target)}
nop
move s6, v0
move s7, v1
{i.api('last')}
sw v0, 0x44(sp)
beqz s4, finish
nop
{after}
finish:
lw a0, 0x44(sp)
{i.api('setlast')}
move v0, s6
move v1, s7
{end(0x80,REGS)}'''
        wrapper=i.routine(code,0x800,0x80,REGS);i.hook(entry,wrapper)
        rows.append(dict(entry=entry,clone=target,wrapper=wrapper,label=label,kind=kind,event=event,category=category))
    for event,(entry,label) in ACTIONS.items():observe(entry,label,'action',event)
    for entry,label,category in [(0x254140,'native window procedure',0),(0x250484,CATEGORIES[2],2),(0x252b84,CATEGORIES[3],3)]:
        observe(entry,label,'ui',category=category)
    observe(0x250100,'existing message reactor returns','periodic')
    observe(0x241b0,'GTMC page commit accounting','pool')
    observe(0x242f8,'GTMC page release accounting','pool')
    return dict(revision=30 if compact else 27 if safe_cache else 26,compact_empty_ui=compact,cache_mode_checked=safe_cache,state_va=D,update=update,pool_capture=pool,memory=memory,periodic=periodic,
        backend_pointer=backend,hooks=rows,categories=CATEGORIES,period_ms=5000,page_bytes=4096,
        allocator_shadow_only=True,nonblocking=True,logs_routes=False,
        scope='Global physical RAM and native GTMC page/cache accounting; not per-process working set. Counts may omit contention. Peak is an observed lower bound. Action duration is synchronous handler time, not route calculation completion. UI totals include nested synchronous work, not frame rate or end-to-end touch latency.')


def build(raw,pin):return gps_build(raw,pin,extend)
