"""Account for work between Bluetooth request and two native settling waits.

Keep 200 ms to the first continuation and 400 ms to fade IPC after a successful
play-command return. No readiness is inferred from transport success. The
timestamp lives in the caller's unused stack word, never in shared/global state.
"""
from patch_updater_copy_safety import frame,end
from debug_metrics21 import patch_call
import struct

REGS=['s0','s1','s2','s3','s4','s5','s6','s7']


def install(i,tick,metrics):
    T=i.text;stamp=T+0xc000;first=T+0xc400;fade=T+0xcc00
    for at,cap in [(stamp,0x400),(first,0x800),(fade,0x800)]:
        assert not any(i.body[at-T:at-T+cap]),'Source helpers need unused code bank'
        assert not any(a<at+cap and b>at for a,b,*_ in i.rows)
    # A2DPPlay's +14 is unused by the native function; +10 is its outgoing arg.
    assert i.p.get_data(0x115594-i.base,4)==struct.pack('<I',0x27bdffd0)
    assert i.p.get_data(0x1156c0-i.base,8)==struct.pack('<II',0x0c046d19,0x24050001)
    save='\n'.join(f'lw t0, {0x90+j*4}(sp)\nsw t0, {0x10+j*4}(sp)' for j in range(9))
    last=f'la t8, {hex(i.last)}\nlw t9, 0(t8)\njalr t9\nnop'
    setlast=f'la t8, {hex(i.setlast)}\nlw t9, 0(t8)\njalr t9\nnop'
    clock=f'la t8, {hex(tick)}\nlw t9, 0(t8)\njalr t9\nnop'
    prefix=f'''{frame(0x80,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
sw t0, 0x48(sp)
{last}
sw v0, 0x44(sp)'''
    invoke_args=f'''{save}
lw a0, 0x44(sp)
{setlast}
move a0, s0
move a1, s1
move a2, s2
move a3, s3
lw t0, 0x48(sp)'''
    i.routine_at(stamp,f'''{prefix}
{invoke_args}
jal 0x11b464
nop
move s6, v0
move s7, v1
{last}
sw v0, 0x44(sp)
sw zero, 0x94(sp)
bnez s6, done
nop
{clock}
sw v0, 0x94(sp)
done:
lw a0, 0x44(sp)
{setlast}
move v0, s6
move v1, s7
{end(0x80,REGS)}''',0x400,0x80,REGS)
    rows={r['event']:r for r in metrics['calls']}
    info=[]
    for at,event,budget,offset in [(first,134,200,0x94),(fade,135,400,0xbc)]:
        # Fade is a shared native entry. Restrict its shortened wait to precisely
        # the A2DPPlay caller, with its own stamp, and keep all other paths exact.
        guard=f'''lw t0, 0xa0(sp)
la t1, 0x115728
bne t0, t1, original
nop''' if event==135 else ''
        code=f'''{prefix}
addiu t0, zero, 200
bne s0, t0, original
nop
{guard}
lw s4, {hex(offset)}(sp)
beqz s4, original
nop
{clock}
subu t0, v0, s4
addiu t1, zero, {budget}
sltu t2, t0, t1
beqz t2, expired
nop
subu s0, t1, t0
sltiu t2, s0, 201
bnez t2, original
nop
addiu s0, zero, 200
b original
nop
expired:
move s0, zero
original:
{invoke_args}
jal {hex(rows[event]['wrapper'])}
nop
{end(0x80,REGS)}'''
        i.routine_at(at,code,0x800,0x80,REGS)
        patch_call(i,rows[event]['site'],at)
        info.append(dict(event=event,site=rows[event]['site'],wrapper=at,
                         measured_wrapper=rows[event]['wrapper'],budget_ms=budget))
    patch_call(i,0x1156c0,stamp)
    return dict(request_site=0x1156c0,stamp_wrapper=stamp,caller_stack_offset=0x14,
        native_request=0x11b464,successful_request_result=0,waits=info,
        site_wrappers={str(r['site']):r['wrapper'] for r in info},
        minimum_first_continuation_ms=200,minimum_fade_ms=400,
        fallback='Unsuccessful request, absent stamp or another fade caller keeps native waits',
        clock='Unsigned GetTickCount subtraction handles wraparound',shared_state=False)
