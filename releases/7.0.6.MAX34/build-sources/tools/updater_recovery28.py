"""Add an independent desktop action to the retained-files installer error UI."""
import struct
from debug_image import Image
from patch_updater_copy_safety import frame, end, CODE, PAINT

PIN = '22ebd96233a121935ac985ae7b667ed8a2f11cc8a47757c3d3ea25753fb06e73'


def build(raw):
    i = Image(raw, PIN)
    i.apis = {name: i.import_at(ordinal) for name, ordinal in
              [('process', 493), ('close', 553), ('last', 516), ('show', 266)]}
    try:
        i.apis['message'] = i.import_at(858)
    except StopIteration:
        i.apis['message'] = i.add_import('COREDLL.dll', 858)
    desktop = i.string(r'\Windows\explorer.exe')
    label = i.string('Open recovery desktop')
    title = i.string('Recovery desktop')
    failure = i.string('Could not open the desktop (error %u).\nFiles remain kept. You can try the recovery button again.')
    # Clone the existing safe paint. Healthy behavior and existing error text
    # remain intact; the original function has no unwind handler to move.
    old_paint, row = i.clone(PAINT)
    assert row[2:4] == (0, 0)
    opening = i.routine(f'''{frame(0x80, ['s0','s1'])}
la t0, {hex(CODE)}
lw t0, 0(t0)
beqz t0, done
nop
la t0, 0x3784c
lw t0, 0(t0)
addiu t1, zero, 3007
bne t0, t1, done
nop
# All ten CreateProcess arguments and PROCESS_INFORMATION start initialized.
sw zero, 0x40(sp)
sw zero, 0x44(sp)
sw zero, 0x48(sp)
sw zero, 0x4c(sp)
la a0, {hex(desktop)}
move a1, zero
move a2, zero
move a3, zero
sw zero, 0x10(sp)
sw zero, 0x14(sp)
sw zero, 0x18(sp)
sw zero, 0x1c(sp)
sw zero, 0x20(sp)
addiu t0, sp, 0x40
sw t0, 0x24(sp)
{i.api('process')}
beqz v0, failed
nop
lw a0, 0x40(sp)
{i.api('close')}
lw a0, 0x44(sp)
{i.api('close')}
# Keep the updater/monitor alive; hide only after successful process creation.
la t0, 0x38efc
lw a0, 0(t0)
move a1, zero
{i.api('show')}
b done
nop
failed:
{i.api('last')}
move s0, v0
la a0, {hex(i.rw)}
addiu a1, zero, 256
la a2, {hex(failure)}
move a3, s0
jal 0x2a86c
nop
la t0, 0x38efc
lw a0, 0(t0)
la a1, {hex(i.rw)}
la a2, {hex(title)}
lui a3, 4
ori a3, a3, 0x10
{i.api('message')}
done:
move v0, zero
{end(0x80, ['s0','s1'])}''', 0x500, 0x80, ['s0','s1'])
    click = i.routine(f'''la t0, {hex(CODE)}
lw t0, 0(t0)
beqz t0, native
nop
la t0, 0x3784c
lw t0, 0(t0)
addiu t1, zero, 3007
bne t0, t1, ignored
nop
# Only the visible recovery rectangle consumes a failed-install mouse-up.
sltiu t0, a0, 40
bnez t0, ignored
nop
sltiu t0, a0, 760
beqz t0, ignored
nop
sltiu t0, a1, 380
bnez t0, ignored
nop
sltiu t0, a1, 460
beqz t0, ignored
nop
j {hex(opening)}
nop
ignored:
move v0, zero
jr ra
nop
native:
j 0x16394
nop''', 0x200)
    painting = i.routine(f'''{frame(0x50, ['s0'])}
move s0, a1
jal {hex(old_paint)}
nop
la t0, {hex(CODE)}
lw t0, 0(t0)
beqz t0, done
nop
la t0, 0x3784c
lw t0, 0(t0)
addiu t1, zero, 3007
bne t0, t1, done
nop
addiu t0, zero, 40
sw t0, 0x20(sp)
addiu t0, zero, 380
sw t0, 0x24(sp)
addiu t0, zero, 760
sw t0, 0x28(sp)
addiu t0, zero, 460
sw t0, 0x2c(sp)
jal 0x2a1e0
addiu a0, zero, 2
move a2, v0
move a0, s0
jal 0x2a200
addiu a1, sp, 0x20
move a0, s0
la a1, {hex(label)}
addiu a2, zero, -1
addiu a3, sp, 0x20
addiu t0, zero, 37
jal 0x2a400
sw t0, 0x10(sp)
done:
{end(0x50, ['s0'])}''', 0x300, 0x50, ['s0'])
    assert i.p.get_data(0x14c34-i.base, 4) == struct.pack('<I', (3 << 26) | (0x16394 >> 2))
    i.hook(0x14c34, click, call=True)
    i.hook(PAINT, painting)
    output, recipe = i.finish()
    recipe.update(events=[],binary='UpgradeManager.exe',recovery=dict(open=opening, click=click, paint=painting, prior_paint=old_paint,
                                rectangle=[40,380,760,460], desktop_path=r'\Windows\explorer.exe',
                                automatic_format=False, automatic_retry=False, needs_dboot=False))
    return output, recipe
