"""Invalidate text reply ownership before native AVRCP disconnect uses the peer.

Wrap only the disconnect handler's existing CID lookup. Preserve its result and
output pointer. Reject stale selected-peer replies without reading GUI state or
freeing native pending records; queued ACK tags survive until profile dispatch.
This component is not installed in a PE or LGU.
"""
import hashlib
import struct
import pefile
import bt_text_metadata_owner as owner
from patch_bt_cover_attribute import BASE_SHA
from patch_usb_seek_completion import assemble
from patch_updater_copy_safety import frame,end

LOOKUP,SITE,ORIGINAL=0x28b400,0x51ba0,0x5675c


def code():return f'''
{frame(0x20,['s0'])}
jal {hex(ORIGINAL)}
nop
move s0, v0
beqz s0, done
nop
la t0, {hex(owner.STATE)}
lw t1, 4(t0)
beqz t1, done
nop
lw t1, 12(t0)
lbu t2, 0x10(s0)
bne t1, t2, done
nop
jal {hex(owner.INVALIDATE)}
nop
done:
move v0, s0
{end(0x20,['s0'])}
'''


def assembled():
    raw,recipe,relocations=assemble(code(),LOOKUP,0x400)
    return [dict(name='text_disconnect_lookup',address=LOOKUP,raw=raw,
                 recipe=recipe,relocations=relocations)]


def sites(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    p=pefile.PE(data=raw)
    assert p.get_data(SITE-p.OPTIONAL_HEADER.ImageBase,8)==struct.pack('<II',(3<<26)|(ORIGINAL>>2),0x02202025)
    return {SITE:(3<<26)|(LOOKUP>>2)}
