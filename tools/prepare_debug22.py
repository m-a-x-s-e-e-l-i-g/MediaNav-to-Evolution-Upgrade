"""Restore the native immediate Settings path without whole-window erasure."""
from pathlib import Path
P=Path(__file__).resolve().parent


def change(s,a,b):
    assert a in s,a[:80]
    return s.replace(a,b)


def main():
    s=(P/'debug_clients21.py').read_text()
    s=change(s,'from debug_metrics21 import app_metrics,poll_wrapper,sample_call',
             'from debug_metrics22 import app_metrics,poll_wrapper,sample_call')
    # The native label renderer uses bit 0x400 to restore its parent background
    # before drawing. Match the existing button's use of this native mechanism.
    s=change(s,'la a0, {hex(label)}\naddiu a1, zero, -1',
             'la t0, {hex(label)}\nlw t1, 0x2c(t0)\nori t1, t1, 0x400\nsw t1, 0x2c(t0)\nla a0, {hex(label)}\naddiu a1, zero, -1')
    s=change(s,'# The native Settings paint clears its background and draws these children.',
             'la a0, {hex(button)}\njal 0x139020\nnop\nla a0, {hex(label)}\njal 0x139020\nnop\naddiu a0, s0, 4\nla a1, {hex(button+8)}\njal 0x13d220\nmove a2, zero\naddiu a0, s0, 4\nla a1, {hex(label+8)}\njal 0x13d220\nmove a2, zero')
    # Toggle draws the controls synchronously; no whole-window invalidation.
    a=s.index('la t0, {hex(state)}\nlw t0, 0(t0)\nbeqz t0, toggle_done')
    b=s.index('toggle_done:\n',a)+len('toggle_done:\n')
    s=s[:a]+s[b:]
    # Native cached-surface paint must complete before we redraw our two controls.
    a=s.index("    paint_code=f'''");b=s.index("    i.routine_at(paint",a)
    s=s[:a]+'''    paint_code=f\'''{frame(0x30,['s0','s1'])}
move s0, a0
move s1, a1
move a0, s0
jal 0x134d28
move a1, s1
sw v0, 0x10(sp)
sw v1, 0x14(sp)
la t8, {hex(i.last)}
lw t9, 0(t8)
jalr t9
nop
sw v0, 0x18(sp)
la t0, {hex(state)}
lw t0, 0(t0)
bne s0, t0, done
nop
jal {hex(refresh)}
nop
done:
lw a0, 0x18(sp)
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
lw v0, 0x10(sp)
lw v1, 0x14(sp)
{end(0x30,['s0','s1'])}\'''
'''+s[b:]
    (P/'debug_clients22.py').write_text(s,encoding='utf-8')


if __name__=='__main__':main()
