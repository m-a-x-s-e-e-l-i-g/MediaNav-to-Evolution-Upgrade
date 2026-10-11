"""Quiescent AVRCP profile shutdown for ordinary text reply ownership.

Invalidate replies before the original profile deinit drains queued requests and
destroys peers. Keep queued ACK tags until that drain finishes, then clear them.
Preserve the non-wrapping generation. This entry is global shutdown only, never a
runtime cancellation API; GUI producers must already be quiescent.
"""
import hashlib
import struct
import pefile
import bt_text_metadata_owner as owner
import bt_cover_art_selection as selection
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

DROP=0x28b800


def code():return f'''
{frame(0x20,['s0','s1'])}
move s0, a0
la t0, {hex(owner.STATE)}
sw zero, 4(t0)
sw zero, 24(t0)
sw zero, 28(t0)
addiu t0, t0, 32
la t1, {hex(owner.STATE+owner.INTERIM_END)}
interims:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, interims
nop
move a0, s0
jal {hex(selection.DROP)}
nop
move s1, v0
# Native deinit has now freed all queued four-byte ACK envelopes. Their side
# tags can no longer alias a live request, including after a scheduler restart.
la t0, {hex(owner.STATE+owner.INTERIM_END)}
la t1, {hex(owner.STATE+owner.SIZE)}
acks:
sw zero, 0(t0)
addiu t0, t0, 4
bne t0, t1, acks
nop
move v0, s1
{end(0x20,['s0','s1'])}
'''


def assembled():
    raw,recipe,relocations=assemble(code(),DROP,0x400)
    return [dict(name='text_profile_shutdown',address=DROP,raw=raw,recipe=recipe,relocations=relocations)]


def sites(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    p=pefile.PE(data=raw)
    for at,word in ((selection.DROP_HIGH,0x3c0a0004),(selection.DROP_LOW,0x2546bb6c)):
        assert p.get_data(at-p.OPTIONAL_HEADER.ImageBase,4)==struct.pack('<I',word)
    return {selection.DROP_HIGH:0x3c0a0000|((DROP+0x8000)>>16),
            selection.DROP_LOW:0x25460000|(DROP&65535)}
