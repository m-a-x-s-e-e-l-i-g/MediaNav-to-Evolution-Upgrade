"""Separate in-memory bounded list-copy experiment over the count-ACK draft.

No executable or container is emitted. Preserve frames, .pdata and byte size.
The leaf body deliberately preserves a0 for the revised adjacent UI guard.
"""
from draft_bt_list_ack import app_ack, apply_blocks

ACK_APP = "c89f3b16c2f3a62b12e66501966957d38c4a0c4a04088f37b5596ae67d306d4a"


def app_safe_copy(raw):
    base, _ = app_ack(raw)
    return apply_blocks(raw, base, [
        (0x110730, 0x1108c4, """
            move s2, a0
            addiu v0, zero, 1
            addiu t0, zero, -1
            sw t0, 0x5a4(s2)
            sw zero, 0x5c0(s2)
            lw s3, 0x26c(s2)
            lw s4, 0xc(s2)
            sltiu t0, s3, 9
            beqz t0, copy_failed
            nop
            beqz s3, copy_start
            nop
            bnez s4, copy_start
            nop
        copy_failed:
            move s3, zero
            sw zero, 0x26c(s2)
            move v0, zero
        copy_start:
            move s0, zero
            addiu s1, s2, 0x270
        record_loop:
            sltu t0, s0, s3
            beqz t0, zero_record
            move t2, s1
            lhu t0, 0(s4)
            beqz t0, copy_record
            move t1, s4
            sw s0, 0x5a4(s2)
            sw s4, 0x5c0(s2)
        copy_record:
            addiu t3, zero, 16
        word_loop:
            lw t0, 0(t1)
            sw t0, 0(t2)
            addiu t1, t1, 4
            addiu t3, t3, -1
            bnez t3, word_loop
            addiu t2, t2, 4
            b next_record
            addiu s4, s4, 0x40
        zero_record:
            addiu t3, zero, 16
        zero_loop:
            sw zero, 0(t2)
            addiu t3, t3, -1
            bnez t3, zero_loop
            addiu t2, t2, 4
        next_record:
            addiu s0, s0, 1
            sltiu t0, s0, 8
            bnez t0, record_loop
            addiu s1, s1, 0x40
            lw t0, 0x5c0(s2)
            bnez t0, 0x1108c4
            nop
            b 0x1108c4
            sw zero, 0x5ac(s2)
        """, "Copy/zero exactly eight raw records; reject invalid count or missing nonempty bank, clear stale active/PB references, return BOOL; keep a0 unchanged"),
        (0x1216a8, 0x1216ac, "sw v0, 0x628(t0)",
         "Record actual copy result rather than unconditional list readiness; physical HFP clearing still follows original message count"),
        (0x11d26c, 0x11d27c, """
            lw a0, 0xa0(s0)
            lw s2, 0x26c(a0)
            beqz s2, 0x11d2f8
            move s1, zero
        """, "Profile name search uses count normalized by copy, skips empty/failed lists; s0 manager remains callee-preserved across native PB helper"),
        (0xd0684, 0xd06ac, """
            b 0xd06e8
            nop
        guarded_status_store:
            lw t0, 0x5a4(a0)
            sltiu t1, t0, 8
            beqz t1, 0xd0708
            sll t0, t0, 6
            addu t2, a0, t0
            b 0xd0708
            sb t7, 0x272(t2)
        """, "Both reload status writes use the preserved object argument and reject cleared/invalid active index before indexed byte store"),
        (0xd06e8, 0xd0708, """
            addiu t0, zero, 2
            beq s0, t0, 0xd068c
            move t7, s5
            bne s0, s2, 0xd0708
            move t7, s4
            b 0xd068c
            nop
        """, "Select original status seven/four and share the guarded post-copy store")
    ], ACK_APP)
