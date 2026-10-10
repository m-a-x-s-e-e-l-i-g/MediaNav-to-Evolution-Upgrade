"""One-pass Arabic direction detection in AppMain 7.0.5.MD.

Preserve function prologue, NULL path, cookie check, epilogue and PE layout.
The old 32-letter table is wholly inside 0600..06ff; its inner full-string
scan therefore makes no additional contribution to the boolean result.
"""
import hashlib
import struct
import pefile
from draft_bt_list_ack import apply_blocks

APP_SHA = "6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8"
START, END = 0x139964, 0x139a34


def patch_label_scan(raw):
    assert hashlib.sha256(raw).hexdigest() == APP_SHA
    pe = pefile.PE(data=raw)
    table = struct.unpack("<33H", pe.get_data(0x151c44 - pe.OPTIONAL_HEADER.ImageBase, 66))
    assert table[-1] == 0 and all(0x600 <= u < 0x700 for u in table[:-1])
    return apply_blocks(raw, raw, [(START, END, """
        move s0, zero
        move t2, s3
    scan:
        lhu t0, 0(t2)
        beqz t0, 0x139a34
        addiu t2, t2, 2
        addiu t1, t0, -0x600
        sltiu t1, t1, 0x100
        beqz t1, scan
        nop
        b 0x139a34
        addiu s0, zero, 1
    """, "Replace repeated Arabic-table/full-string scans and unused local copies with one equivalent UTF16 range scan")], APP_SHA)


def compose_label_scan(original, base):
    _, recipe = patch_label_scan(original)
    out = bytearray(base)
    for edit in recipe["edits"]:
        at = int(edit["offset"], 16)
        before, after = bytes.fromhex(edit["before_hex"]), bytes.fromhex(edit["after_hex"])
        assert out[at:at + len(before)] == before, "Label/Bluetooth patch conflict"
        out[at:at + len(after)] = after
    return bytes(out), recipe
