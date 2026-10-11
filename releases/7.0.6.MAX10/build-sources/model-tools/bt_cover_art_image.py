"""Checked AppMain JPEG-thumbnail decoder using its retained CE Imaging ABI.

Interpretation helpers only. Borrow bytes during one call; release IImage before
returning, so the caller can release its source copy. Return one unselected GDI
bitmap on success, owned by the caller. COM/GDI execution and PE installation
still require native integration and device validation.
"""
import hashlib
import struct

import pefile

from inspect_bt_cover_ui_route import APP_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

PREFLIGHT, DECODE = 0x220000, 0x222000
MAX_IMAGE, EDGE = 128*1024, 200
CLSID, IID, CO_CREATE = 0x14cab4, 0x14caa4, 0x1853e8
CREATE_DC, CREATE_DIB, SELECT, DELETE_DC, DELETE_OBJECT = 0x140178, 0x140188, 0x140018, 0x140198, 0x140138
REGS = ['s0','s1','s2','s3','s4','s5','s6','s7']


def preflight():
    # This is a bounded structural gate, not an entropy decoder. The actual
    # decoder must still reject invalid Huffman tables and compressed content.
    return f'''
{frame(0x40, REGS)}
move s0, a0
beqz s0, bad
nop
sltiu t0, a1, 4
bnez t0, bad
nop
la t0, {hex(MAX_IMAGE+1)}
sltu t0, a1, t0
beqz t0, bad
nop
addu s1, s0, a1
sltu t0, s0, s1
beqz t0, bad
nop
lbu t0, 0(s0)
addiu t1, zero, 0xff
bne t0, t1, bad
nop
lbu t0, 1(s0)
addiu t1, zero, 0xd8
bne t0, t1, bad
nop
addiu s2, s0, 2
move s4, zero
move s5, zero
move s6, zero
addiu s7, zero, 1024
marker:
beq s2, s1, bad
nop
lbu t0, 0(s2)
addiu t1, zero, 0xff
bne t0, t1, bad
nop
fill:
addiu s2, s2, 1
beq s2, s1, bad
nop
lbu t7, 0(s2)
beq t7, t1, fill
nop
addiu s2, s2, 1
addiu t0, zero, 0xd9
beq t7, t0, complete
nop
beqz s7, bad
nop
addiu s7, s7, -1
subu t0, s1, s2
sltiu t1, t0, 2
bnez t1, bad
nop
lbu s3, 0(s2)
lbu t1, 1(s2)
sll s3, s3, 8
or s3, s3, t1
sltiu t1, s3, 2
bnez t1, bad
nop
sltu t1, t0, s3
bnez t1, bad
nop
addu t6, s2, s3
addiu t0, zero, 0xc0
beq t7, t0, sof
nop
addiu t0, zero, 0xda
beq t7, t0, sos
nop
addiu t0, zero, 0xc4
beq t7, t0, skip
nop
addiu t0, zero, 0xdb
beq t7, t0, skip
nop
addiu t0, zero, 0xdd
beq t7, t0, dri
nop
addiu t0, zero, 0xfe
beq t7, t0, skip
nop
addiu t0, t7, -0xe0
sltiu t0, t0, 16
beqz t0, bad
nop
skip:
move s2, t6
b marker
nop
dri:
addiu t0, zero, 4
bne s3, t0, bad
nop
b skip
nop
sof:
bnez s4, bad
nop
sltiu t0, s3, 11
bnez t0, bad
nop
lbu t0, 2(s2)
addiu t1, zero, 8
bne t0, t1, bad
nop
lbu t0, 3(s2)
bnez t0, bad
nop
lbu t0, 4(s2)
addiu t1, zero, {EDGE}
bne t0, t1, bad
nop
lbu t0, 5(s2)
bnez t0, bad
nop
lbu t0, 6(s2)
bne t0, t1, bad
nop
lbu s6, 7(s2)
addiu t0, zero, 1
beq s6, t0, components
nop
addiu t0, zero, 3
bne s6, t0, bad
nop
components:
sll t0, s6, 1
addu t0, t0, s6
addiu t0, t0, 8
bne s3, t0, bad
nop
move t2, zero
addiu t3, s2, 8
component:
lbu t0, 0(t3)
move t4, zero
unique:
beq t4, t2, store_id
nop
sll t5, t4, 2
addu t5, t5, sp
lw t5, 0x10(t5)
beq t5, t0, bad
nop
addiu t4, t4, 1
b unique
nop
store_id:
sll t4, t2, 2
addu t4, t4, sp
sw t0, 0x10(t4)
lbu t0, 1(t3)
srl t4, t0, 4
addiu t4, t4, -1
sltiu t4, t4, 4
beqz t4, bad
nop
andi t0, t0, 15
addiu t0, t0, -1
sltiu t0, t0, 4
beqz t0, bad
nop
lbu t0, 2(t3)
sltiu t0, t0, 4
beqz t0, bad
nop
addiu t2, t2, 1
addiu t3, t3, 3
bne t2, s6, component
nop
addiu s4, zero, 1
b skip
nop
sos:
beqz s4, bad
nop
sltiu t0, s3, 8
bnez t0, bad
nop
lbu t2, 2(s2)
beqz t2, bad
nop
sltu t0, s6, t2
bnez t0, bad
nop
sll t0, t2, 1
addiu t0, t0, 6
bne s3, t0, bad
nop
lbu t0, -3(t6)
bnez t0, bad
nop
lbu t0, -2(t6)
addiu t1, zero, 63
bne t0, t1, bad
nop
lbu t0, -1(t6)
bnez t0, bad
nop
# Validate scan component membership, uniqueness and baseline table numbers.
move t4, zero
move t5, zero
addiu t3, s2, 3
scan_component:
lbu t0, 0(t3)
move t1, zero
scan_lookup:
sll t7, t1, 2
addu t7, t7, sp
lw t7, 0x10(t7)
beq t7, t0, scan_found
nop
addiu t1, t1, 1
bne t1, s6, scan_lookup
nop
b bad
nop
scan_found:
move t5, zero
scan_unique:
beq t5, t4, scan_tables
nop
sll t7, t5, 1
addu t7, t7, s2
lbu t7, 3(t7)
beq t7, t0, bad
nop
addiu t5, t5, 1
b scan_unique
nop
scan_tables:
lbu t0, 1(t3)
srl t1, t0, 4
sltiu t1, t1, 4
beqz t1, bad
nop
andi t0, t0, 15
sltiu t0, t0, 4
beqz t0, bad
nop
addiu t4, t4, 1
addiu t3, t3, 2
bne t4, t2, scan_component
nop
addiu s5, zero, 1
move s0, zero
move s2, t6
entropy:
beq s2, s1, bad
nop
lbu t0, 0(s2)
addiu s2, s2, 1
addiu t1, zero, 0xff
beq t0, t1, entropy_fill
nop
addiu s0, zero, 1
b entropy
nop
entropy_fill:
beq s2, s1, bad
nop
lbu t0, 0(s2)
addiu s2, s2, 1
beq t0, t1, entropy_fill
nop
bnez t0, entropy_marker
nop
addiu s0, zero, 1
b entropy
nop
entropy_marker:
addiu t2, t0, -0xd0
sltiu t2, t2, 8
bnez t2, entropy
nop
beqz s0, bad
nop
addiu s2, s2, -2
b marker
nop
complete:
beqz s4, bad
nop
beqz s5, bad
nop
bne s2, s1, bad
nop
addiu v0, zero, 1
b done
nop
bad:
move v0, zero
done:
{end(0x40, REGS)}
'''


def decode():
    return f'''
{frame(0xe0, REGS)}
move s0, a0
move s1, a1
move s2, zero
move s3, zero
move s4, zero
move s5, zero
move s6, zero
move s7, zero
sw zero, 0x20(sp)
sw zero, 0x24(sp)
sw zero, 0x28(sp)
jal {hex(PREFLIGHT)}
nop
beqz v0, cleanup
nop
la a0, {hex(CLSID)}
move a1, zero
addiu a2, zero, 1
la a3, {hex(IID)}
addiu t0, sp, 0x20
sw t0, 0x10(sp)
la t0, {hex(CO_CREATE)}
lw t9, 0(t0)
jalr t9
nop
lw s2, 0x20(sp)
bnez v0, cleanup
nop
beqz s2, cleanup
nop
move a0, s2
move a1, s0
move a2, s1
move a3, zero
addiu t0, sp, 0x24
sw t0, 0x10(sp)
lw t0, 0(s2)
lw t9, 0x14(t0)
jalr t9
nop
lw s3, 0x24(sp)
bnez v0, cleanup
nop
beqz s3, cleanup
nop
addiu t0, sp, 0x70
addiu t1, sp, 0x98
zero_info:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, zero_info
nop
move a0, s3
addiu a1, sp, 0x70
lw t0, 0(s3)
lw t9, 0x10(t0)
jalr t9
nop
bnez v0, cleanup
nop
lw t0, 0x84(sp)
addiu t1, zero, {EDGE}
bne t0, t1, cleanup
nop
lw t0, 0x88(sp)
bne t0, t1, cleanup
nop
jal {hex(CREATE_DC)}
move a0, zero
move s4, v0
beqz s4, cleanup
nop
addiu t0, sp, 0x40
addiu t1, sp, 0x6c
zero_bmi:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, zero_bmi
nop
addiu t0, zero, 40
sw t0, 0x40(sp)
addiu t0, zero, {EDGE}
sw t0, 0x44(sp)
sw t0, 0x48(sp)
addiu t0, zero, 1
sh t0, 0x4c(sp)
addiu t0, zero, 24
sh t0, 0x4e(sp)
move a0, s4
addiu a1, sp, 0x40
move a2, zero
addiu a3, sp, 0x28
sw zero, 0x10(sp)
sw zero, 0x14(sp)
jal {hex(CREATE_DIB)}
nop
move s5, v0
beqz s5, cleanup
nop
lw t0, 0x28(sp)
beqz t0, cleanup
nop
move a0, s4
jal {hex(SELECT)}
move a1, s5
beqz v0, cleanup
nop
addiu t0, zero, -1
beq v0, t0, cleanup
nop
move s6, v0
sw zero, 0x30(sp)
sw zero, 0x34(sp)
addiu t0, zero, {EDGE}
sw t0, 0x38(sp)
sw t0, 0x3c(sp)
move a0, s3
move a1, s4
addiu a2, sp, 0x30
move a3, zero
lw t0, 0(s3)
lw t9, 0x18(t0)
jalr t9
nop
bnez v0, cleanup
nop
addiu s7, zero, 1
cleanup:
# Restore the previous selection before returning or deleting the new bitmap.
beqz s6, image_release
nop
move a0, s4
jal {hex(SELECT)}
move a1, s6
beq v0, s5, image_release
nop
move s7, zero
image_release:
beqz s3, factory_release
nop
move a0, s3
lw t0, 0(s3)
lw t9, 8(t0)
jalr t9
nop
factory_release:
beqz s2, dc_release
nop
move a0, s2
lw t0, 0(s2)
lw t9, 8(t0)
jalr t9
nop
dc_release:
beqz s4, bitmap_release
nop
jal {hex(DELETE_DC)}
move a0, s4
bnez v0, bitmap_release
nop
move s7, zero
bitmap_release:
beqz s5, result
nop
bnez s7, result
nop
jal {hex(DELETE_OBJECT)}
move a0, s5
move s5, zero
result:
move v0, s5
{end(0xe0, REGS)}
'''


def assembled():
    rows=[]
    for name,at,capacity,source in (('thumbnail_preflight',PREFLIGHT,0x2000,preflight()),
                                    ('thumbnail_decode',DECODE,0x1000,decode())):
        raw,recipe,relocations=assemble(source,at,capacity)
        rows.append(dict(name=name,address=at,raw=raw,recipe=recipe,relocations=relocations))
    return rows


def contracts(raw):
    if hashlib.sha256(raw).hexdigest()!=APP_SHA:raise ValueError('Expected exact retained MAX05 AppMain.exe')
    pe=pefile.PE(data=raw)
    base=pe.OPTIONAL_HEADER.ImageBase
    expected={SELECT:0x185068,DELETE_OBJECT:0x1850d4,CREATE_DC:0x1850e4,
              CREATE_DIB:0x1850e8,DELETE_DC:0x1850ec}
    imports={i.address:i for d in pe.DIRECTORY_ENTRY_IMPORT for i in d.imports}
    pins=[]
    for thunk,iat in expected.items():
        code=pe.get_data(thunk-base,16)
        # Exact existing LUI/LW/JR/NOP tail stub, through its retained import.
        words=struct.unpack('<IIII',code)
        assert words==((15<<26)|(8<<16)|0x18,(35<<26)|(8<<21)|(8<<16)|(iat&0xffff),0x1000008,0)
        assert iat in imports
        pins.append(dict(thunk=hex(thunk),iat=hex(iat),ordinal=imports[iat].ordinal,sha256=hashlib.sha256(code).hexdigest()))
    assert imports[CO_CREATE].name==b'CoCreateInstance'
    return dict(appmain_sha256=APP_SHA,imports=pins,co_create_iat=hex(CO_CREATE),
                factory_iid_hex=pe.get_data(IID-base,16).hex(),factory_clsid_hex=pe.get_data(CLSID-base,16).hex())
