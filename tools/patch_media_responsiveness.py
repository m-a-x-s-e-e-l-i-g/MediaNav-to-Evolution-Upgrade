"""Small, pinned in-place changes layered over the complete MAX03 development payload.

No native execution, release packaging, version bump or publication.
Preserve PE layout, imports, function frames and exception metadata.
"""
import hashlib
from draft_bt_list_ack import apply_blocks

APP_SHA = 'bddf03995a63b41a1d6cc180be03e8b56b882d0989a5a73c60ed974f9790a4e3'
USB_SHA = 'bb435bc428664845a21ffe7bce7a813db06b7e7f92408d297dbbeade94507cd2'


def patch_app(raw):
    assert hashlib.sha256(raw).hexdigest() == APP_SHA
    return apply_blocks(raw, raw, [
        (0x13e654, 0x13e668, '''
            move a0, s0
            jal 0x13e6f8
            move a1, s1
            bnez v0, 0x13e6e0
            sw zero, 0x30(s0)
        ''', 'Run the existing move/cancel handler before clearing pressed state; an outside release cancels hold and returns without generating a tap'),
        (0x13e674, 0x13e678, 'beq a1, t0, 0x13e6cc',
         'An inside release with event -1 still clears active selection and hold timers, without dispatching a click'),
        (0x1397e8, 0x139880, '''
            move s1, zero
            move t2, s0
        scan:
            lhu t0, 0(t2)
            beqz t0, 0x139880
            addiu t2, t2, 2
            addiu t1, t0, -0x590
            sltiu t1, t1, 0x70
            beqz t1, scan
            nop
            b 0x139880
            addiu s1, zero, 1
        ''', 'Replace unused formatted copy and length-then-range passes with one equivalent Hebrew UTF16 range scan; keep frame and cookie check')
    ], APP_SHA)


def patch_usb(raw):
    assert hashlib.sha256(raw).hexdigest() == USB_SHA
    return apply_blocks(raw, raw, [
        (0x1bb70, 0x1bb78, 'b 0x1bb98\nnop',
         'Free bytes are not a track identity; retain full saved path, file size/volume serial, disk API success, total disk bytes and graph-load checks')
    ], USB_SHA)
