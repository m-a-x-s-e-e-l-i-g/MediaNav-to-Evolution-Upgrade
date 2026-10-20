"""Bounded repetition suppression and reserved admission for diagnostic events.

No USB writes/waits are added to producers. Unknown native text stays eligible
for reserved admission: text severity cannot be reliably inferred from words.
"""
from debug_runtime28 import build_core as prior
from patch_updater_copy_safety import frame,end

NATIVE_CACHE=0x22200
SUPPRESSED=0x60


def replace(i,at,source):
    old=next(r for r in i.routines if r['address']==at)
    i.routines.remove(old);i.rows=[r for r in i.rows if r[0]!=at]
    i.reloc=[r for r in i.reloc if not at-i.base<=r[0]<at-i.base+old['capacity']]
    i.routine_at(at,source,old['capacity'],old['frame_bytes'],old['registers'])


def build_core(i):
    runtime=prior(i);A=runtime['addresses'];S=runtime['strings'];D=i.rw
    at=S['header']-i.text
    old='\ufeffMAXmade 7.0.6.MAX28 diagnostics'.encode('utf-16-le')
    new='\ufeffMAXmade 7.0.6.MAX30 diagnostics'.encode('utf-16-le')
    assert i.body[at:at+len(old)]==old;i.body[at:at+len(new)]=new
    # These private leaf helpers run under the existing queue mutex. Only
    # volatile registers change. The cache owns a bounded text copy, no pointer.
    repeat=i.routine(f'''bnez s0, emit
nop
sltiu t0, s1, 2
beqz t0, emit
nop
beqz s4, emit
nop
or t0, s2, s3
bnez t0, emit
nop
lui t0, {NATIVE_CACHE>>16}
ori t0, t0, {NATIVE_CACHE&65535}
addu t0, t0, s7
lw t1, 0(t0)
beqz t1, emit
nop
lw t1, 4(t0)
bne t1, s1, emit
nop
lw t1, 8(t0)
bne t1, s5, emit
nop
lw t1, 12(t0)
subu t1, a0, t1
sltiu t1, t1, 10000
beqz t1, emit
nop
addiu t0, t0, 16
move t1, s4
move t2, zero
loop:
sltiu t3, t2, 255
beqz t3, emit
nop
lhu t3, 0(t1)
lhu t4, 0(t0)
# Compare the same normalized representation that the queue stores.
beqz t3, compare
nop
sltiu t5, t3, 32
beqz t5, compare
nop
addiu t3, zero, 32
compare:
bne t3, t4, emit
nop
beqz t3, suppressed
nop
addiu t0, t0, 2
addiu t1, t1, 2
b loop
addiu t2, t2, 1
suppressed:
lw t0, {SUPPRESSED}(s7)
addiu t1, zero, -1
beq t0, t1, done
nop
addiu t0, t0, 1
sw t0, {SUPPRESSED}(s7)
done:
jr ra
move v0, zero
emit:
jr ra
addiu v0, zero, 1''',0x400)
    remember=i.routine(f'''bnez s0, done
nop
sltiu t0, s1, 2
beqz t0, done
nop
beqz s4, done
nop
lui t0, {NATIVE_CACHE>>16}
ori t0, t0, {NATIVE_CACHE&65535}
addu t0, t0, s7
sw zero, 0(t0)
or t1, s2, s3
bnez t1, done
nop
sltiu t1, t3, 255
beqz t1, done
nop
sw s1, 4(t0)
sw s5, 8(t0)
lw t1, 0x20(sp)
sw t1, 12(t0)
addiu t1, a0, 32
addiu t2, t0, 16
copy:
lhu t3, 0(t1)
sh t3, 0(t2)
beqz t3, sealed
nop
addiu t1, t1, 2
b copy
addiu t2, t2, 2
sealed:
addiu t1, zero, 1
sw t1, 0(t0)
done:
jr ra
nop''',0x200)
    priority=i.routine('''# All unclassified diagnostics retain reserved admission.
addiu v0, zero, 1
addiu t0, zero, 900
beq s1, t0, routine
nop
addiu t0, zero, 901
beq s1, t0, routine
nop
addiu t0, zero, 906
beq s1, t0, routine
nop
addiu t0, zero, 8
bne s0, t0, bluetooth
nop
addiu t0, zero, 940
beq s1, t0, routine
nop
addiu t0, zero, 941
beq s1, t0, routine
nop
sltiu t0, s1, 1010
bnez t0, done
nop
sltiu t0, s1, 1025
bnez t0, routine
nop
b done
nop
bluetooth:
addiu t0, zero, 3
bne s0, t0, done
nop
addiu t0, zero, 302
beq s1, t0, routine
nop
sltiu t0, s1, 979
bnez t0, done
nop
sltiu t0, s1, 992
bnez t0, routine
nop
done:
jr ra
nop
routine:
jr ra
move v0, zero''',0x300)
    source=next(r['assembly'] for r in i.routines if r['address']==A['enqueue'])
    start=source.index('lw t0, 0xc(s7)');stop=source.index('lw t0, 8(s7)',start)
    source=source[:start]+f'''{i.api('tick')}
sw v0, 0x20(sp)
move a0, v0
jal {hex(repeat)}
nop
beqz v0, unlock
nop
lw t0, 0xc(s7)
sltiu t1, t0, 256
beqz t1, dropped
nop
lw v0, 0x20(sp)
lw t0, 0x38(s7)
subu t1, v0, t0
sltiu t2, t1, 1000
bnez t2, quota
nop
sw v0, 0x38(s7)
sw zero, 0x3c(s7)
quota:
jal {hex(priority)}
nop
bnez v0, important
nop
lw t0, 0xc(s7)
sltiu t1, t0, 224
beqz t1, dropped
nop
lw t0, 0x3c(s7)
sltiu t1, t0, 96
beqz t1, dropped
nop
important:
lw t0, 0x3c(s7)
sltiu t1, t0, 128
beqz t1, dropped
addiu t0, t0, 1
sw t0, 0x3c(s7)
lw v0, 0x20(sp)
'''+source[stop:]
    # remember uses volatile t0/t1, so reload the write index afterward.
    needle='sh zero, 0(t2)\nsw t3, 24(t1)'
    assert source.count(needle)==1
    source=source.replace(needle,needle+f'\nmove a0, t1\njal {hex(remember)}\nnop\nlw t0, 8(s7)')
    replace(i,A['enqueue'],source)
    worker=next(r['assembly'] for r in i.routines if r['address']==A['worker'])
    needle='flush_check:\n'
    assert worker.count(needle)==1
    worker=worker.replace(needle,f'''# Suppression is deliberate filtering, separate from dropped records.
lw a2, {SUPPRESSED}(s1)
beqz a2, flush_check
nop
addiu a0, zero, 1
addiu a1, zero, 906
move a3, zero
sw zero, 0x10(sp)
sw zero, 0x14(sp)
jal {hex(A['enqueue'])}
nop
flush_check:
''')
    replace(i,A['worker'],worker)
    runtime.update(measurements_revision=30,quiet_logging=dict(
        normal_records_per_second=96,reserved_records_per_second=32,
        routine_queue_limit=224,queue_capacity=256,native_repeat_ms=10000,
        native_cache_offset=NATIVE_CACHE,suppressed_count_offset=SUPPRESSED,
        suppressed_event=906,repeat=repeat,remember=remember,priority=priority,
        limits='Reserved admission remains bounded; contention, full queue and the total 128/s limit can still drop diagnostics. Native severity is not guessed from text.'))
    return runtime
