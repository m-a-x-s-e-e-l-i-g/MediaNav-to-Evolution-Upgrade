"""Separate in-memory SC database iterator repair over the pinned Blue ACK.

Keep function frame/.pdata, original BOOL interface and cursor global. Drain
before restart and close failed seek; caller error reporting and atomic writes
remain open. The drain assumes the serialized global-cursor ownership model.
"""
from draft_bt_list_ack import blue_ack, apply_blocks

ACK_BLUE = "ddeca3721a3efdd908fac58ef5072071bd8c3bbbe3b9da5715ee16e985cda2e2"


def blue_key_iterator(raw):
    base, _ = blue_ack(raw)
    return apply_blocks(raw, base, [
        (0x7a810, 0x7a88c, """
            lui s2, 0x21
            lw s0, -0x1cfc(s2)
            move s1, a0
            beqz s0, iterator_closed
            addiu t0, zero, -1
            beq s0, t0, iterator_closed
            nop
        iterator_next:
            addiu a1, zero, 1
            addiu a2, zero, 0x68
            move a3, s0
            jal 0x860f8
            move a0, s1
            beqz v1, iterator_close
            addiu t0, zero, 0x68
            bne v0, t0, iterator_close
            nop
            lw t0, 0(s1)
            lhu t1, 6(s1)
            lbu t2, 4(s1)
            or t0, t0, t1
            or t0, t0, t2
            beqz t0, iterator_next
            nop
            b 0x7a88c
            addiu v0, zero, 1
        iterator_close:
            jal 0x86088
            move a0, s0
            sw zero, -0x1cfc(s2)
        iterator_closed:
            b 0x7a88c
            move v0, zero
        """, "Require ReadFile BOOL and exactly 104 bytes, skip empty BDADDRs, close once and make exhausted/invalid cursor idempotent"),
        (0x7ac38, 0x7ac9c, """
            jal 0xc2810
            move s0, a0
            jal 0x7a3d8
            lui s1, 0x21
            beqz v0, cursor_failed
            lui t0, 0x10
            lui a1, 0x8000
            jal 0x85f84
            addiu a0, t0, 0x39f0
            addiu t0, zero, -1
            beq v0, t0, cursor_failed
            sw v0, -0x1cfc(s1)
            move a2, zero
            addiu a1, zero, 4
            jal 0x86144
            move a0, v0
            andi t0, v0, 0xffff
            beqz t0, cursor_read
            lw a0, -0x1cfc(s1)
            jal 0x86088
            sw zero, -0x1cfc(s1)
        cursor_failed:
            b 0x7ac9c
            move v0, zero
        cursor_read:
            jal 0x7a7f8
            move a0, s0
        """, "Drain and close old global iterator before restart; close/clear fresh cursor on seek failure; original frame and magic/open checks retained")
    ], ACK_BLUE)
