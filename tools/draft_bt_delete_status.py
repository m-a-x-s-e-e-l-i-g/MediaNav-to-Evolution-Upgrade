"""Separate memory-only delete-result repair over the eight-record draft.

Keep the earlier combined-fixture exclusions. Expose BOOL in v1, preserving the
legacy cookie-call result in v0 for existing callers. Preserve frames/epilogues;
no executable, LGU, native CE call or device write is emitted.
"""
from draft_bt_pairing_storage import draft_blue_storage
from draft_bt_list_ack import apply_blocks, BASE_BLUE


def blue_delete_status(raw):
    base, _ = draft_blue_storage(raw)
    return apply_blocks(raw, base, [
        (0x7aa64, 0x7ab34, """
            move s1, zero
            sltiu t0, s0, 8
            beqz t0, compact_done
            nop
            addiu a0, sp, 0x78
            move a1, zero
            jal 0x3a750
            addiu a2, zero, 0x340
            addiu a0, sp, 0x78
            jal 0x7a8a8
            addiu a1, zero, 8
            beqz v0, compact_done
            nop
            sw zero, 0x10(sp)
            sw zero, 0x14(sp)
            addiu t0, zero, 0x68
            multu s0, t0
            mflo t0
            addiu s2, sp, 0x78
            addu s2, s2, t0
            addiu s0, s0, 1
        shift_next:
            sltiu t0, s0, 8
            beqz t0, clear_last
            addiu s2, s2, 0x68
            move a0, s2
            jal 0x3ac90
            addiu a1, sp, 0x10
            bnez v0, clear_last
            nop
            addiu a0, s2, -0x68
            move a1, s2
            jal 0x85758
            addiu a2, zero, 0x68
            b shift_next
            addiu s0, s0, 1
        clear_last:
            addiu a0, s2, -0x68
            move a1, zero
            jal 0x3a750
            addiu a2, zero, 0x68
            addiu a0, sp, 0x78
            jal 0x7a974
            addiu a1, zero, 8
            move s1, v0
        compact_done:
            jal 0x8ac24
            lw a0, 0x3b8(sp)
            b 0x7ab34
            move v1, s1
        """, "Expose bounded compaction/write BOOL in v1 through cookie check; retain legacy v0, enlarged frame and original epilogue"),
        (0x7ab70, 0x7ac10, """
            move s1, zero
            jal 0x7a3d8
            nop
            beqz v0, delete_done
            nop
            addiu a1, zero, 1
            jal 0x7a4d0
            move a0, s0
            move s0, v0
            sltiu t0, s0, 8
            beqz t0, delete_done
            nop
            jal 0x7aa40
            move a0, s0
            move s1, v1
        delete_done:
            jal 0x8ac24
            lw a0, 0x78(sp)
            b 0x7ac10
            move v1, s1
        """, "Propagate real deletion BOOL in v1; missing address/header/scan/compaction/write failure exposes zero after cookie check, legacy v0 unchanged"),
        (0x2fff8, 0x30008, """
            beqz v1, 0x300e4
            addiu s6, zero, 1
            bne s5, s6, 0x3008c
            lbu t0, 0xe(s4)
        """, "Stop GUI delete before profile disconnect, security cancellation and state updates when database deletion fails; retain successful path")
    ], BASE_BLUE)
