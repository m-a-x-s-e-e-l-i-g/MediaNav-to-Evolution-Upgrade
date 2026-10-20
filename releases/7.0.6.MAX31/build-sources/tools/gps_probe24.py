"""Observe the existing NNG NMEA dispatcher without accessing the serial port.

No coordinate/date strings are copied or logged. The original engine remains
fixed-base, as indicated by its original RELOCS_STRIPPED flag.
"""
from debug_image import Image
from patch_updater_copy_safety import frame,end
from debug_runtime20 import MAGIC

REGS=['s0','s1','s2','s3','s4','s5','s6','s7']


def build(raw,pin,extension=None,compact=False):
    i=Image(raw,pin)
    # NNG has 24k original pdata rows: copied rows plus their relocation records
    # exceed the smaller manager bank. Keep RX metadata clear of private RW state.
    i.body.extend(bytes(0x40000));i.rw=i.text+0x100000;D=i.rw
    assert i.p.FILE_HEADER.Characteristics&1 and not i.p.OPTIONAL_HEADER.DATA_DIRECTORY[5].Size
    i.last=i.import_at(516)
    try:i.setlast=i.import_at(517)
    except StopIteration:i.setlast=i.add_import('COREDLL.dll',517)
    i.apis={k:i.import_at(v) for k,v in [('last',516),('load',528),('proc',530),('tick',535)]}
    i.apis['setlast']=i.setlast
    for key,ordinal in [('cas',1492),('free',529)]:
        try:i.apis[key]=i.import_at(ordinal)
        except StopIteration:i.apis[key]=i.add_import('COREDLL.dll',ordinal)
    dll=i.string('\\Storage Card\\System\\CmnDll.dll');symbol=i.string('DbgDebugPrint')
    # Native string object has byte pointer +4 and signed byte length +10.
    target,row=i.clone(0x22bd00);assert row[2]==0
    # Leaf scanner: return kind (RMC/GGA/etc packed ASCII) and
    # talker[31:16]/raw status character[15:8]/satellites[7:0]. FF = absent.
    scanner=i.routine('''move v0, zero
move v1, zero
beqz a0, done
nop
blez a1, done
nop
sltiu t0, a1, 129
bnez t0, bounded
nop
addiu a1, zero, 128
bounded:
lbu t0, 0(a0)
addiu t1, zero, 36
bne t0, t1, prefix
nop
addiu a0, a0, 1
addiu a1, a1, -1
prefix:
sltiu t0, a1, 6
bnez t0, done
nop
lbu t0, 5(a0)
addiu t1, zero, 44
bne t0, t1, done
nop
lbu t0, 0(a0)
lbu t1, 1(a0)
sll a2, t0, 24
sll t1, t1, 16
or a2, a2, t1
lbu t0, 2(a0)
lbu t1, 3(a0)
lbu t2, 4(a0)
sll t0, t0, 16
sll t1, t1, 8
or v0, t0, t1
or v0, v0, t2
addiu t4, zero, 255
addiu t5, zero, 255
move t3, zero
addiu a0, a0, 5
addiu a1, a1, -5
scan:
beqz a1, pack
nop
lbu t0, 0(a0)
addiu a0, a0, 1
addiu a1, a1, -1
addiu t1, zero, 44
bne t0, t1, scan
nop
addiu t3, t3, 1
beqz a1, pack
nop
lui t1, 0x52
ori t1, t1, 0x4d43
bne v0, t1, gga
nop
addiu t1, zero, 2
bne t3, t1, scan
nop
lbu t4, 0(a0)
b scan
nop
gga:
lui t1, 0x47
ori t1, t1, 0x4741
bne v0, t1, other_kind
nop
addiu t1, zero, 6
bne t3, t1, sats
nop
lbu t4, 0(a0)
b scan
nop
sats:
addiu t1, zero, 7
bne t3, t1, scan
nop
b parse_sats
nop
other_kind:
lui t1, 0x47
ori t1, t1, 0x5341
bne v0, t1, gsv
nop
addiu t1, zero, 2
bne t3, t1, scan
nop
lbu t4, 0(a0)
b scan
nop
gsv:
lui t1, 0x47
ori t1, t1, 0x5356
bne v0, t1, scan
nop
addiu t1, zero, 3
bne t3, t1, scan
nop
parse_sats:
lbu t0, 0(a0)
addiu t0, t0, -48
sltiu t1, t0, 10
beqz t1, scan
nop
move t5, t0
sltiu t1, a1, 2
bnez t1, scan
nop
lbu t1, 1(a0)
addiu t1, t1, -48
sltiu t2, t1, 10
beqz t2, scan
nop
sll t2, t5, 3
sll t5, t5, 1
addu t5, t5, t2
addu t5, t5, t1
pack:
sll t4, t4, 8
or v1, a2, t4
or v1, v1, t5
done:
jr ra
nop''',0x800)
    # Delayed resolution avoids adding a CmnDll import/search dependency to NNG.
    # A failed lookup retries at most every 5s; a competing caller never waits.
    resolver=i.routine(f'''{frame(0x30,['s0','s1','s2','s3'])}
la s0, {hex(D+0x100)}
lw v0, 0(s0)
bnez v0, done
nop
addiu a0, s0, 8
addiu a1, zero, 1
move a2, zero
{i.api('cas')}
bnez v0, unavailable
nop
lw s1, 0(s0)
bnez s1, release
nop
{i.api('tick')}
move s2, v0
lw t0, 4(s0)
beqz t0, attempt
nop
subu t1, s2, t0
sltiu t2, t1, 5000
bnez t2, release
nop
attempt:
sw s2, 4(s0)
la a0, {hex(dll)}
{i.api('load')}
beqz v0, release
nop
move s3, v0
move a0, s3
la a1, {hex(symbol)}
{i.api('proc')}
move s1, v0
bnez s1, publish
nop
move a0, s3
{i.api('free')}
b release
nop
publish:
sw s3, 12(s0)
sync
sw s1, 0(s0)
release:
sync
sw zero, 8(s0)
move v0, s1
b done
nop
unavailable:
move v0, zero
done:
{end(0x30,['s0','s1','s2','s3'])}''',0x800,0x30,['s0','s1','s2','s3'])
    save='\n'.join(f'lw t0, {0x90+j*4}(sp)\nsw t0, {0x10+j*4}(sp)' for j in range(9))
    def debug(op):return f'lui a0, 0x4d58\nori a0, a0, {0x4400+op}\njalr s4\nnop'
    wrapper=i.routine(f'''{frame(0x80,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
{save}
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
jal {hex(resolver)}
nop
beqz v0, finish
nop
move s4, v0
{debug(3)}
andi t0, v0, 1
beqz t0, finish
nop
beqz s1, finish
nop
lw a0, 4(s1)
lw a1, 0x10(s1)
jal {hex(scanner)}
nop
beqz v0, finish
nop
move s2, v0
move s3, v1
# Six fixed buckets: RMC, GGA, GSA, GSV, VTG, other.
addiu s0, zero, 5
lui t0, 0x52
ori t0, t0, 0x4d43
beq s2, t0, bucket0
nop
lui t0, 0x47
ori t0, t0, 0x4741
beq s2, t0, bucket1
nop
lui t0, 0x47
ori t0, t0, 0x5341
beq s2, t0, bucket2
nop
lui t0, 0x47
ori t0, t0, 0x5356
beq s2, t0, bucket3
nop
lui t0, 0x56
ori t0, t0, 0x5447
beq s2, t0, bucket4
nop
b bucket
nop
bucket0:
move s0, zero
b bucket
nop
bucket1:
addiu s0, zero, 1
b bucket
nop
bucket2:
addiu s0, zero, 2
b bucket
nop
bucket3:
addiu s0, zero, 3
b bucket
nop
bucket4:
addiu s0, zero, 4
bucket:
{'''sltiu t0, s0, 4
beqz t0, finish
nop''' if compact else ''}
sll s0, s0, 2
la t0, {hex(D+0x120)}
addu s0, s0, t0
{i.api('tick')}
move s5, v0
lw t0, 0(s0)
beqz t0, emit
nop
lw t1, 0x20(s0)
{'''# Satellite-count changes alone wait for the heartbeat. Preserve fix/talker
# changes, and GSV transitions between zero and nonzero visibility.
lui t2, 0x47
ori t2, t2, 0x4741
beq s2, t2, counts
nop
lui t2, 0x47
ori t2, t2, 0x5356
bne s2, t2, compare
nop
andi t2, t1, 255
sltu t2, zero, t2
andi t3, s3, 255
sltu t3, zero, t3
bne t2, t3, emit
nop
counts:
lui t2, 0xffff
ori t2, t2, 0xff00
and t1, t1, t2
and t2, s3, t2
bne t1, t2, emit
nop
b acceptance
nop
compare:''' if compact else ''}
bne t1, s3, emit
nop
{'''acceptance:
lui t2, 0x47
ori t2, t2, 0x5356
beq s2, t2, elapsed
nop''' if compact else ''}
lw t1, 0x40(s0)
sltu t2, zero, s6
bne t1, t2, emit
nop
elapsed:
subu t1, s5, t0
sltiu t2, t1, {30000 if compact else 5000}
bnez t2, finish
nop
emit:
sw s5, 0(s0)
sw s3, 0x20(s0)
sltu t0, zero, s6
sw t0, 0x40(s0)
addiu a1, zero, 8
addiu a2, zero, 940
move a3, s2
sw s3, 0x10(sp)
{debug(4)}
addiu a1, zero, 8
addiu a2, zero, 941
move a3, s2
sltu t0, zero, s6
sw t0, 0x10(sp)
{debug(4)}
finish:
lw a0, 0x44(sp)
{i.api('setlast')}
move v0, s6
move v1, s7
{end(0x80,REGS)}''',0x1000,0x80,REGS)
    i.hook(0x22bd00,wrapper)
    navigation=extension(i,resolver,D+0x100) if extension else None
    out,recipe=i.finish()
    recipe.update(binary='nngnavi.exe',events=[],capture_native_output=False,
        gps_probe=dict(entry=0x22bd00,clone=target,wrapper=wrapper,scanner=scanner,resolver=resolver,
            state_va=D,backend_pointer=D+0x100,cache_va=D+0x120,minimum_repeat_ms=30000 if compact else 5000,
            compact=compact,
            metadata_events=[940,941],maximum_scanned_bytes=128,logs_coordinates=False,
            native_fixed_base=True,limits='Raw sentence markers and native parser acceptance; no independent checksum/fix certification.'))
    if navigation is not None:recipe['navigation_measurements']=navigation
    return out,recipe
