"""Separate memory-only BCSP/H4 cleanup repair over the pinned iterator draft.

Reuse the existing BCSP drain as a head-pointer helper; update its sole known
BCSP caller and H4 caller. Frames, epilogues and .pdata remain unchanged.
"""
from draft_bt_key_iterator import blue_key_iterator
from draft_bt_list_ack import apply_blocks

ITERATOR_BLUE = "5b2d11baa5788e548b7cf0fb07fbfdf81f3d718de7c27680097577e106cc9ddd"


def blue_transport_cleanup(raw):
    base, _ = blue_key_iterator(raw)
    return apply_blocks(raw, base, [
        (0x7d6f4, 0x7d730, """
            move s2, a0
            move s1, zero
        drain_next:
            lw s0, 0(s2)
            beqz s0, 0x7d730
            nop
            lw t0, 0(s0)
            sw t0, 0(s2)
            jal 0x85bb8
            lw a0, 4(s0)
            jal 0x85bb8
            move a0, s0
            b drain_next
            addiu s1, s1, 1
        """, "Drain caller-supplied descriptor queue; unlink before freeing payload then descriptor; preserve counter/frame/epilogue"),
        (0x7d6ac, 0x7d6cc, """
            addiu a0, s0, -0x4800
            jal 0x7d6e0
            addiu a0, a0, -0x48cc
            jal 0x7cbf4
            nop
            jal 0x85bb8
            lw a0, 0x1168(s0)
            sw zero, 0x1168(s0)
        """, "Pass BCSP head 20e314 from context 2173e0; retain subsequent ring cleanup and staging-buffer free/clear"),
        (0x7ebe8, 0x7ebec, "jal 0x7d6e0",
         "H4 cleanup drains descriptor list instead of freeing global head address through mismatched helper"),
        (0x7cc50, 0x7cc54, "sw s1, 0xd8(s0)",
         "Commit oldest reliable slot after each cleanup step, including final empty state; repeated cleanup cannot free stale payloads again")
    ], ITERATOR_BLUE)
