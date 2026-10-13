"""Create successor authoring modules without changing the MAX19 snapshots."""
from pathlib import Path
P=Path(__file__).resolve().parent


def replace(s, old, new):
    assert old in s, old[:80]
    return s.replace(old,new)


def main():
    s=(P/'debug_runtime.py').read_text()
    s=s.replace('MAX19 USB diagnostics:', 'MAX20 USB diagnostics:')
    s=s.replace('# Rotation uses eight exclusively owned names. Never writes to internal cards.', '# Archive log chunks with CREATE_NEW; logs stay exclusively on external MD.')
    s=replace(s,'from debug_image import Image','from debug_image import Image\nfrom debug_config20 import install')
    s=replace(s,"'path':'\\\\MD\\\\MAXmade\\\\logs\\\\debug-%u.log',", "'path':'\\\\MD\\\\MAXmade\\\\logs\\\\debug-%04u%02u%02u-%02u%02u%02u-%03u-%u-%u.log',")
    s=s.replace('MAX19 diagnostics','MAX20 diagnostics')
    s=replace(s,"    put('drain',", "    install(i,A,S)\n    put('drain',")
    s=replace(s,'    i.code_cursor=0x8000','    i.code_cursor=0xb000')
    s=replace(s,'lw s1, 0x1c(s0)\nandi s1, s1, 7', 'addiu s4, zero, 64\nunique:\nlw s1, 0x1c(s0)')
    s=replace(s,"move a2, s1\n{api('printf')}\nla a0, {hex(D+0x1200)}", """la t0, {hex(D+0x1520)}
lhu a2, 0(t0)
lhu a3, 2(t0)
lhu t1, 6(t0)
sw t1, 0x10(sp)
lhu t1, 8(t0)
sw t1, 0x14(sp)
lhu t1, 10(t0)
sw t1, 0x18(sp)
lhu t1, 12(t0)
sw t1, 0x1c(sp)
lhu t1, 14(t0)
sw t1, 0x20(sp)
lw t1, 0x2c(s0)
sw t1, 0x24(sp)
sw s1, 0x28(sp)
{api('printf')}
addiu s1, s1, 1
sw s1, 0x1c(s0)
la a0, {hex(D+0x1200)}""")
    # CREATE_NEW makes preservation atomic even with wrong clocks or another writer.
    s=replace(s,"addiu t0, zero, 2\nsw t0, 0x10(sp)\naddiu t0, zero, 0x80", "addiu t0, zero, 1\nsw t0, 0x10(sp)\naddiu t0, zero, 0x80")
    s=replace(s,"beq v0, t0, failure\nmove s2, v0", """bne v0, t0, created
move s2, v0
{api('last')}
addiu t0, zero, 80
beq v0, t0, collision
nop
addiu t0, zero, 183
bne v0, t0, failure
nop
collision:
addiu s4, s4, -1
bnez s4, unique
nop
b failure
nop
created:""")
    s=replace(s,'addiu s1, s1, 1\nandi s1, s1, 7\nsw s1, 0x1c(s0)','')
    # Full invalidation includes clearing the native background before new glyphs.
    s=replace(s,"move a1, zero\nmove a2, zero\n{api('invalidate')}","move a1, zero\naddiu a2, zero, 1\n{api('invalidate')}")
    # Even an initial migrated/default setting gets a durable background save.
    s=replace(s,'sw v0, 0x10(s5)\naddiu t0, zero, 1\nsw t0, 0x44(s5)', 'sw v0, 0x10(s5)\naddiu t0, zero, 1\nsw t0, 0x14(s5)\nsw t0, 0x44(s5)')
    s=replace(s,'log_slots=8,','log_slots=None,retains_all_sessions=True,config_format="two validated 16-byte slots",')
    (P/'debug_runtime20.py').write_text(s,encoding='utf-8')
    s=(P/'debug_clients.py').read_text().replace('from debug_runtime import MAGIC','from debug_runtime20 import MAGIC')
    s=replace(s,'la a0, {hex(button)}\njal 0x139020\nnop\nla a0, {hex(label)}\njal 0x139020\nnop', '# The native Settings paint clears its background and draws these children.')
    s=replace(s,'jal {hex(refresh)}\nnop\nmove v0, zero', '''jal {hex(refresh)}
nop
la t0, {hex(state)}
lw t0, 0(t0)
beqz t0, toggle_done
nop
lw a0, 0x50(t0)
move a1, zero
addiu a2, zero, 1
la t8, {hex(i.invalidate)}
lw t9, 0(t8)
jalr t9
nop
toggle_done:
move v0, zero''')
    s=replace(s,"        ui=settings(i,dbg)","        i.invalidate=i.add_import('COREDLL.dll',250,0x214c64)\n        ui=settings(i,dbg)")
    (P/'debug_clients20.py').write_text(s,encoding='utf-8')


if __name__=='__main__':main()
