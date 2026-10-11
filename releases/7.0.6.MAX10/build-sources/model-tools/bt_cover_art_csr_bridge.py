"""Interpreter-only CSR SDP query bridge at the proved remote-target call site.

Preserves the original service-name query and adds attribute 0x000d. No Blue.exe
is written; wrapper placement, loader/unwind, SDP extraction and task hooks remain open.
"""
import hashlib
import struct

import pefile

from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame, end

ENTRY, SITE, QUERY = 0x230000, 0x58bec, 0x67be0
CODE = f'''
{frame(0x30, ['s0', 's1', 's2'])}
move s0, a0
move s1, a1
# Copy the caller's fifth argument into this frame's o32 argument area.
lhu t0, 0x40(sp)
sh t0, 0x10(sp)
jal {hex(QUERY)}
nop
move s2, v0
move a0, s0
move a1, s1
addiu a2, zero, 13
move a3, zero
sh zero, 0x10(sp)
jal {hex(QUERY)}
nop
# Additional discovery is optional; retain the original call's return value.
move v0, s2
{end(0x30, ['s0', 's1', 's2'])}
'''


def bridge(raw):
    if hashlib.sha256(raw).hexdigest() != BASE_SHA:
        raise ValueError('Expected exact retained MAX04/MAX05 Blue.exe')
    pe = pefile.PE(data=raw)
    before = pe.get_data(SITE-pe.OPTIONAL_HEADER.ImageBase, 4)
    if before != struct.pack('<I', 0x0c019ef8):
        raise ValueError('Unexpected remote-target service-name query call')
    code, recipe, relocations = assemble(CODE, ENTRY, 0x100)
    if recipe['used_bytes'] > 0x100:
        raise ValueError('Query bridge exceeds export capacity')
    word = 0x0c000000 | (ENTRY >> 2)
    return code, dict(base_sha256=BASE_SHA, site=hex(SITE), before_hex=before.hex(),
                      interpreter_after_hex=struct.pack('<I',word).hex(), entry=hex(ENTRY),
                      assembly=recipe, relocation_recipe=relocations,
                      executable_written=False, firmware_patched=False, native_executed=False,
                      limits=['Wrapper address is only an interpreter fixture, not a selected PE region',
                              'Preserve original query then request additional protocol lists on the remote TG record',
                              'No new profile advertisement, connection, decoder, UI or SDP receive hook']), word
