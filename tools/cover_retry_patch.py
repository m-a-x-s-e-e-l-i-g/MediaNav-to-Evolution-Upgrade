"""Bounded cover-art retry for Blue.exe's selected-track binding action.

Two hooks inside the action routine at 0x273400 (live binding state at 0x300300):
  A (0x273574): channel idle/failed and this selection was already attempted.
  B (0x2734dc): selection already covered, controller READY, nothing published.
Each allows at most MAX_RETRIES repeats per selection, RETRY_MS apart. Counters
live in unused binding words +36 (stamp), +40 (retries), +44 (selection tag).
"""
import struct
from mips_mini import assemble

CAVE = 0x273690
CLOCK = 0x25a000
MAX_RETRIES, RETRY_MS = 3, 1500
HOOK_A, HOOK_B = 0x273574, 0x2734dc
WORD_A = 0x11140000 | ((0x273668 - 0x273574 - 4) // 4)   # beq t0, s4, refused
WORD_B = 0x11000000 | ((0x273634 - 0x2734dc - 4) // 4)   # beqz t0, accepted
RESUME_A, REFUSED = 0x27357c, 0x273668
NORMAL_B, ACCEPTED, REFRESH = 0x2734e4, 0x273634, 0x27351c
READY = 5


def code(at):
    src = f"""
retrygate:
addiu sp, sp, -0x20
sw ra, 0x1c(sp)
lw t1, 44(s1)
beq t1, s4, tagok
nop
sw s4, 44(s1)
sw zero, 36(s1)
sw zero, 40(s1)
tagok:
lw t1, 40(s1)
sltiu t2, t1, {MAX_RETRIES}
beqz t2, no
nop
jal {CLOCK}
nop
lw t3, 36(s1)
beqz t3, stamp
nop
subu t2, v0, t3
sltiu t2, t2, {RETRY_MS}
bnez t2, no
nop
lw t1, 40(s1)
addiu t1, t1, 1
sw t1, 40(s1)
sw v0, 36(s1)
addiu v0, zero, 1
beq zero, zero, out
nop
stamp:
sw v0, 36(s1)
no:
move v0, zero
out:
lw ra, 0x1c(sp)
addiu sp, sp, 0x20
jr ra
nop
cavea:
bne t0, s4, resume_a
nop
jal retrygate
nop
beqz v0, refused_a
nop
resume_a:
j {RESUME_A}
nop
refused_a:
j {REFUSED}
nop
caveb:
bnez t0, normal_b
nop
lw t1, 0(s3)
addiu t2, zero, {READY}
bne t1, t2, accepted_b
nop
lw t1, 36(s3)
bnez t1, accepted_b
nop
jal retrygate
nop
beqz v0, accepted_b
nop
j {REFRESH}
nop
normal_b:
j {NORMAL_B}
nop
accepted_b:
j {ACCEPTED}
nop
"""
    return assemble(src, at)


def build():
    blob, labels = code(CAVE)
    a = struct.pack("<I", (2 << 26) | (labels["cavea"] >> 2))
    b = struct.pack("<I", (2 << 26) | (labels["caveb"] >> 2))
    return blob, labels, a, b
