"""Owned Blue/AppMain artwork transfer with a persistent generation authority.

Named mapping/mutex are separate from legacy metadata. The serialized Blue
owner creates tokens and invalidates them without taking a mutex. Its GUI-side
publisher copies immutable bytes under a zero-timeout mutex; AppMain copies into
its own buffer and checks freshness after decoding. No native hooks are installed.
"""
from dataclasses import dataclass
import hashlib

import pefile

from inspect_bt_cover_ui_route import APP_SHA
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

MAGIC,VERSION,HEADER,MAX_IMAGE,MAX_AGE=0x3141424d,1,64,128*1024,5000
SIZE=HEADER+MAX_IMAGE
# Header: magic0, version4, persistent counter8, live token12, committed token16,
# encoded length20, monotonic heartbeat24. Reserved28..63 remain zero.
# Local context: mutex0, mapping4, view8, ready12, incarnation16, reserved20.
# Incarnation survives close/reopen, preventing a retained bitmap from matching
# a new named mapping whose generation counter has restarted. No wrap allowed.
CONTEXT_SIZE=24
MAPPING_NAME='MAXmade_BT_Artwork_V1'
MUTEX_NAME='MAXmade_BT_Artwork_Lock_V1'
REGS=['s0','s1','s2','s3','s4','s5','s6','s7']
OFFSETS={'init':0,'token':0x1000,'invalidate':0x1400,'publish':0x1800,
         'copy':0x2800,'fresh':0x3800,'touch':0x3c00,'close':0x4000}


@dataclass(frozen=True)
class Config:
    module:str
    sha256:str
    base:int
    state:int
    writer:bool
    api:dict


CONFIGS={
    'Blue.exe':Config('Blue.exe',BASE_SHA,0x278000,0x27f000,True,
        dict(mutex=0x1100e8,mapping=0x1100f8,map=0x1100f4,unmap=0x1100f0,
             wait=0x110024,release=0x1100c0,close=0x110020,exchange=0x11013c,compare=0x110214)),
    'AppMain.exe':Config('AppMain.exe',APP_SHA,0x224000,0x229000,False,
        dict(mutex=0x214100,mapping=0x185024,map=0x18500c,unmap=0x185010,
             wait=0x1850a0,release=0x214104,close=0x185028,exchange=0x18529c,compare=0x1852a8))}
ORDINALS=dict(mutex=555,mapping=548,map=549,unmap=550,wait=497,release=556,
              close=553,exchange=12,compare=1492)


def api(c,name,delay='nop'):
    return f'la t0, {hex(c.api[name])}\nlw t9, 0(t0)\njalr t9\n{delay}'


def guard(label='bad'):
    return f'''
beqz s0, {label}
nop
lw t0, 12(s0)
addiu t1, zero, 1
bne t0, t1, {label}
nop
lw s4, 8(s0)
beqz s4, {label}
nop
lw t0, 16(s0)
beqz t0, {label}
nop
lw t0, 0(s4)
la t1, {hex(MAGIC)}
bne t0, t1, {label}
nop
lw t0, 4(s4)
addiu t1, zero, {VERSION}
bne t0, t1, {label}
nop
'''


def recover(c):
    # Called only with the mutex owned. An abandoned writer may have left a
    # partial image. Keep the counter forever; invalidate all image authority.
    return f'''
addiu a0, s4, 12
move a1, zero
{api(c,'exchange')}
sw zero, 16(s4)
sw zero, 20(s4)
'''


def init(c):
    clear=recover(c) if c.writer else ''
    return f'''
{frame(0x40,REGS)}
move s0, a0
move s2, zero
move s3, zero
move s4, zero
move s7, zero
beqz s0, done
nop
lw t0, 12(s0)
addiu t1, zero, 1
beq t0, t1, existing
nop
# Accept only a fresh local context; never overwrite owned handles.
lw t0, 0(s0)
lw t1, 4(s0)
or t0, t0, t1
lw t1, 8(s0)
or t0, t0, t1
lw t1, 12(s0)
or t0, t0, t1
lw t1, 20(s0)
or t0, t0, t1
bnez t0, done
nop
lw t0, 16(s0)
addiu t1, zero, -1
beq t0, t1, done
nop
move a0, zero
move a1, zero
la a2, {hex(c.state+0x140)}
{api(c,'mutex')}
move s2, v0
beqz s2, cleanup
nop
addiu a0, zero, -1
move a1, zero
addiu a2, zero, 4
move a3, zero
la t0, {hex(SIZE)}
sw t0, 0x10(sp)
la t0, {hex(c.state+0x100)}
sw t0, 0x14(sp)
{api(c,'mapping')}
move s3, v0
beqz s3, cleanup
nop
move a0, s3
addiu a1, zero, 6
move a2, zero
move a3, zero
la t0, {hex(SIZE)}
sw t0, 0x10(sp)
{api(c,'map')}
move s4, v0
beqz s4, cleanup
nop
move a0, s2
move a1, zero
{api(c,'wait')}
beqz v0, locked
nop
addiu t0, zero, 128
bne v0, t0, cleanup
nop
addiu s7, zero, 1
locked:
lw t0, 0(s4)
beqz t0, initialize
nop
la t1, {hex(MAGIC)}
bne t0, t1, unlock_bad
nop
lw t0, 4(s4)
addiu t1, zero, {VERSION}
bne t0, t1, unlock_bad
nop
bnez s7, abandoned
nop
b accepted
nop
initialize:
# A new page-backed mapping is zeroed. Refuse a colliding nonzero header.
move t0, s4
addiu t1, s4, {HEADER}
zeros:
lw t2, 0(t0)
bnez t2, unlock_bad
nop
addiu t0, t0, 4
bne t0, t1, zeros
nop
la t0, {hex(MAGIC)}
sw t0, 0(s4)
addiu t0, zero, {VERSION}
sw t0, 4(s4)
b accepted
nop
abandoned:
{recover(c)}
accepted:
{clear}
move a0, s2
{api(c,'release')}
beqz v0, cleanup
nop
sw s2, 0(s0)
sw s3, 4(s0)
sw s4, 8(s0)
lw t0, 16(s0)
addiu t0, t0, 1
sw t0, 16(s0)
addiu t0, zero, 1
sw t0, 12(s0)
addiu v0, zero, 1
b finish
nop
unlock_bad:
move a0, s2
{api(c,'release')}
cleanup:
beqz s4, mapping_close
nop
move a0, s4
{api(c,'unmap')}
mapping_close:
beqz s3, mutex_close
nop
move a0, s3
{api(c,'close')}
mutex_close:
beqz s2, done
nop
move a0, s2
{api(c,'close')}
done:
move v0, zero
b finish
nop
existing:
{guard('done')}
addiu v0, zero, 1
finish:
{end(0x40,REGS)}
'''


def token(c):
    # Blue serialized owner only. A failed CAS or saturation leaves live zero.
    return f'''
{frame(0x30,['s0','s1','s4','s5'])}
move s0, a0
move s1, a1
{guard()}
addiu a0, s4, 12
move a1, zero
{api(c,'exchange')}
lw s5, 8(s4)
addiu t0, zero, -1
beq s5, t0, bad
nop
addiu a0, s4, 8
addiu a1, s5, 1
move a2, s5
{api(c,'compare')}
bne v0, s5, bad
nop
addiu s5, s5, 1
addiu a0, s4, 24
move a1, s1
{api(c,'exchange')}
addiu a0, s4, 12
move a1, s5
{api(c,'exchange')}
move v0, s5
b done
nop
bad:
move v0, zero
done:
{end(0x30,['s0','s1','s4','s5'])}
'''


def invalidate(c):
    return f'''
{frame(0x20,['s0','s4'])}
move s0, a0
{guard()}
addiu a0, s4, 12
move a1, zero
{api(c,'exchange')}
addiu v0, zero, 1
b done
nop
bad:
move v0, zero
done:
{end(0x20,['s0','s4'])}
'''


def publish(c):
    # GUI publisher only. 2 means mutex busy; keep the owned source for retry.
    return f'''
{frame(0x40,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
{guard()}
lw t0, 0x50(sp)
lw t1, 16(s0)
bne t0, t1, bad
nop
beqz s1, bad
nop
beqz s2, bad
nop
sltiu t0, s3, 4
bnez t0, bad
nop
la t0, {hex(MAX_IMAGE+1)}
sltu t0, s3, t0
beqz t0, bad
nop
addu s5, s2, s3
sltu t0, s2, s5
beqz t0, bad
nop
# Reject overlap with the mapping, including its header.
la t0, {hex(SIZE)}
addu t0, s4, t0
sltu t0, s2, t0
beqz t0, lock
nop
sltu t0, s4, s5
bnez t0, bad
nop
lock:
lw s6, 0(s0)
beqz s6, bad
nop
move a0, s6
move a1, zero
{api(c,'wait')}
beqz v0, locked
nop
addiu t0, zero, 128
beq v0, t0, abandoned
nop
addiu t0, zero, 258
bne v0, t0, bad
nop
addiu v0, zero, 2
b done
nop
locked:
lw t0, 12(s4)
bne t0, s1, unlock_bad
nop
addiu a0, s4, 16
move a1, zero
{api(c,'exchange')}
addiu t0, s4, {HEADER}
move t1, s2
copy_bytes:
lbu t2, 0(t1)
sb t2, 0(t0)
addiu t1, t1, 1
addiu t0, t0, 1
bne t1, s5, copy_bytes
nop
lw t0, 12(s4)
bne t0, s1, unlock_bad
nop
sw s3, 20(s4)
addiu a0, s4, 16
move a1, s1
{api(c,'exchange')}
move a0, s6
{api(c,'release')}
beqz v0, bad
nop
addiu v0, zero, 1
b done
nop
abandoned:
{recover(c)}
unlock_bad:
move a0, s6
{api(c,'release')}
bad:
move v0, zero
done:
{end(0x40,REGS)}
'''


def copy(c):
    # Context, owned buffer, capacity<=128KiB, aligned 12-byte ticket, NOW.
    # No output ticket is committed on refusal; temporary bytes may be copied.
    return f'''
{frame(0x40,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
{guard()}
beqz s1, bad
nop
beqz s3, bad
nop
andi t0, s3, 3
bnez t0, bad
nop
sltiu t0, s2, 4
bnez t0, bad
nop
la t0, {hex(MAX_IMAGE+1)}
sltu t0, s2, t0
beqz t0, bad
nop
addu t2, s1, s2
sltu t0, s1, t2
beqz t0, bad
nop
addiu t3, s3, 12
sltu t0, s3, t3
beqz t0, bad
nop
# All output ranges must be disjoint from one another, context and mapping.
sltu t0, s1, t3
beqz t0, context_overlap
nop
sltu t0, s3, t2
bnez t0, bad
nop
context_overlap:
addiu t1, s0, {CONTEXT_SIZE}
sltu t0, s1, t1
beqz t0, ticket_context
nop
sltu t0, s0, t2
bnez t0, bad
nop
ticket_context:
sltu t0, s3, t1
beqz t0, mapping_overlap
nop
sltu t0, s0, t3
bnez t0, bad
nop
mapping_overlap:
la t1, {hex(SIZE)}
addu t1, s4, t1
sltu t0, s1, t1
beqz t0, ticket_mapping
nop
sltu t0, s4, t2
bnez t0, bad
nop
ticket_mapping:
sltu t0, s3, t1
beqz t0, lock
nop
sltu t0, s4, t3
bnez t0, bad
nop
lock:
lw s6, 0(s0)
beqz s6, bad
nop
move a0, s6
move a1, zero
{api(c,'wait')}
beqz v0, locked
nop
addiu t0, zero, 128
beq v0, t0, abandoned
nop
addiu t0, zero, 258
bne v0, t0, bad
nop
addiu v0, zero, 2
b done
nop
locked:
lw s5, 12(s4)
beqz s5, unlock_bad
nop
lw t0, 16(s4)
bne t0, s5, unlock_bad
nop
lw t0, 24(s4)
lw t1, 0x50(sp)
subu t0, t1, t0
sltiu t0, t0, {MAX_AGE+1}
beqz t0, unlock_bad
nop
lw s7, 20(s4)
sltiu t0, s7, 4
bnez t0, unlock_bad
nop
sltu t0, s2, s7
bnez t0, unlock_bad
nop
addiu t0, s4, {HEADER}
move t1, s1
addu t3, t1, s7
copy_bytes:
lbu t2, 0(t0)
sb t2, 0(t1)
addiu t0, t0, 1
addiu t1, t1, 1
bne t1, t3, copy_bytes
nop
lw t0, 12(s4)
bne t0, s5, unlock_bad
nop
sw s5, 0(s3)
sw s7, 4(s3)
lw t0, 16(s0)
sw t0, 8(s3)
move a0, s6
{api(c,'release')}
beqz v0, bad
nop
addiu v0, zero, 1
b done
nop
abandoned:
{recover(c)}
unlock_bad:
move a0, s6
{api(c,'release')}
bad:
move v0, zero
done:
{end(0x40,REGS)}
'''


def fresh(c):
    # Read-only nonblocking gate. The last live-token read is its linearization
    # point; GUI must call it again immediately before bitmap assignment/paint.
    return f'''
{frame(0x30,['s0','s1','s2','s4'])}
move s0, a0
move s1, a1
move s2, a2
{guard()}
lw t0, 16(s0)
bne t0, a3, bad
nop
beqz s1, bad
nop
lw t0, 12(s4)
bne t0, s1, bad
nop
lw t0, 16(s4)
bne t0, s1, bad
nop
lw t0, 24(s4)
subu t0, s2, t0
sltiu t0, t0, {MAX_AGE+1}
beqz t0, bad
nop
lw t0, 12(s4)
bne t0, s1, bad
nop
addiu v0, zero, 1
b done
nop
bad:
move v0, zero
done:
{end(0x30,['s0','s1','s2','s4'])}
'''


def touch(c):
    return f'''
{frame(0x30,['s0','s1','s2','s4'])}
move s0, a0
move s1, a1
move s2, a2
{guard()}
lw t0, 16(s0)
bne t0, a3, bad
nop
beqz s1, bad
nop
lw t0, 12(s4)
bne t0, s1, bad
nop
addiu a0, s4, 24
move a1, s2
{api(c,'exchange')}
lw t0, 12(s4)
bne t0, s1, bad
nop
addiu v0, zero, 1
b done
nop
bad:
move v0, zero
done:
{end(0x30,['s0','s1','s2','s4'])}
'''


def close(c):
    inv=f'''move a0, s0\njal {hex(c.base+OFFSETS['invalidate'])}\nnop''' if c.writer else ''
    return f'''
{frame(0x30,['s0','s1'])}
move s0, a0
beqz s0, done
nop
{inv}
lw s1, 8(s0)
sw zero, 12(s0)
sw zero, 8(s0)
beqz s1, mapping_close
nop
move a0, s1
{api(c,'unmap')}
mapping_close:
lw s1, 4(s0)
sw zero, 4(s0)
beqz s1, mutex_close
nop
move a0, s1
{api(c,'close')}
mutex_close:
lw s1, 0(s0)
sw zero, 0(s0)
beqz s1, done
nop
move a0, s1
{api(c,'close')}
done:
move v0, zero
{end(0x30,['s0','s1'])}
'''


def assembled(module):
    c=CONFIGS[module]
    specs={'init':(0x1000,init),'close':(0x400,close)}
    if c.writer:specs.update(token=(0x400,token),invalidate=(0x400,invalidate),
                             publish=(0x1000,publish),touch=(0x400,touch))
    else:specs.update(copy=(0x1000,copy),fresh=(0x400,fresh))
    rows=[]
    for name,(capacity,make) in specs.items():
        at=c.base+OFFSETS[name]
        raw,recipe,relocations=assemble(make(c),at,capacity)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    ordered=sorted(rows,key=lambda r:r['address'])
    assert all(a['address']+len(a['raw'])<=b['address'] for a,b in zip(ordered,ordered[1:]))
    return rows


def initial_data(module):
    c=CONFIGS[module]
    return {c.state:bytes(CONTEXT_SIZE),c.state+0x100:(MAPPING_NAME+'\0').encode('utf-16le'),
            c.state+0x140:(MUTEX_NAME+'\0').encode('utf-16le')}


def contracts(module,raw):
    c=CONFIGS[module]
    if hashlib.sha256(raw).hexdigest()!=c.sha256:raise ValueError('Expected exact retained MAX05 '+module)
    pe=pefile.PE(data=raw)
    imports={i.address:(d.dll,i) for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
    rows=[]
    for name,address in c.api.items():
        dll,item=imports[address]
        assert dll.lower()==b'coredll.dll' and item.ordinal==ORDINALS[name],name
        rows.append(dict(api=name,iat=hex(address),ordinal=item.ordinal))
    return dict(module=module,sha256=c.sha256,imports=rows,mapping_bytes=SIZE,
                mapping_name=MAPPING_NAME,mutex_name=MUTEX_NAME,header_bytes=HEADER)
