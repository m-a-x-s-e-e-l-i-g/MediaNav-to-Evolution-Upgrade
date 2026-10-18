"""Advertise the implemented CT thumbnail reader in the native SDP record.

The remote target still must advertise a valid cover service and OBEX endpoint.
No remote capability bit is forced and the target-role record stays unchanged.
"""
from artwork_probe25 import build as prior
from patch_updater_copy_safety import frame,end
from debug_clients23 import command

REGS=['s0','s1','s2','s3','s4','s5','s6','s7']


def extend(i,dbg,tick):
    # Native builder 5861c emits the reviewed 82-byte controller form only for
    # role2 and local version >=1.4. Strings, allocation and size remain native.
    # Feature bit9 = CT GetLinkedThumbnail, not TG CoverArt (bit8).
    patch=i.routine('''move v0, zero
addiu t0, zero, 2
bne a2, t0, done
nop
beqz a0, done
nop
sltiu t0, a1, 82
bnez t0, done
nop
addu t0, a0, a1
sltu t0, a0, t0
beqz t0, done
nop
'''+''.join(f'''lbu t0, {off}(a0)
addiu t1, zero, {val}
bne t0, t1, done
nop
''' for off,val in [(0,9),(1,0),(2,1),(3,0x35),(4,6),(5,0x19),(6,0x11),(7,0x0e),
                     (8,0x19),(9,0x11),(10,0x0f),
                     (0x37,9),(0x38,0),(0x39,9),(0x3a,0x35),(0x3b,8),
                     (0x3c,0x35),(0x3d,6),(0x3e,0x19),(0x3f,0x11),(0x40,0x0e),(0x41,9),
                     (0x44,9),(0x45,3),(0x46,0x11),(0x47,9)])+'''
lbu t0, 0x42(a0)
addiu t1, zero, 1
bne t0, t1, done
nop
lbu t0, 0x43(a0)
sltiu t1, t0, 4
bnez t1, done
nop
sltiu t1, t0, 7
beqz t1, done
nop
addiu t1, zero, 6
sb t1, 0x43(a0)
lbu t0, 0x48(a0)
ori t0, t0, 2
sb t0, 0x48(a0)
addiu v0, zero, 1
done:
jr ra
nop''',0x500)
    target,row=i.clone(0x5861c)
    # Original /GS-only handler and cookie-frame descriptor remain attached to
    # the byte-identical clone; neither uses an original instruction range.
    assert row[2:4]==(0x8abd8,0x10f1b0)
    assert i.p.get_data(row[3]-i.base,4)==bytes.fromhex('d4ffffff')
    save='\n'.join(f'lw t0, {0x90+j*4}(sp)\nsw t0, {0x10+j*4}(sp)' for j in range(9))
    wrapper=i.routine(f'''{frame(0x80,REGS)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
{save}
jal {hex(target)}
nop
move s6, v0
move s7, v1
la t8, {hex(i.last)}
lw t9, 0(t8)
jalr t9
nop
sw v0, 0x44(sp)
move s4, zero
addiu t0, zero, 2
bne s2, t0, finish
nop
beqz s1, finish
nop
lw a0, 0(s1)
move a1, s6
jal {hex(patch)}
move a2, s2
move s4, v0
{command(i,dbg,3)}
andi t0, v0, 1
beqz t0, finish
nop
addiu a1, zero, 3
addiu a2, zero, 967
la a3, 0x01060200
sw s4, 0x10(sp)
{command(i,dbg,4)}
finish:
lw a0, 0x44(sp)
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
move v0, s6
move v1, s7
{end(0x80,REGS)}''',0x500,0x80,REGS)
    i.hook(0x5861c,wrapper)
    return dict(entry=0x5861c,clone=target,wrapper=wrapper,patch=patch,role=2,
        profile_version=0x106,controller_features_added=0x200,
        remote_capability_checks_retained=True,target_role_unchanged=True,
        event=967,scope='Correct local controller profile/thumbnail capability advertisement; iPhone interoperability requires car test.')


def build(raw,pin):return prior(raw,pin,extend)
