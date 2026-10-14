"""Native Settings controls and bounded event hooks, retaining MAX18 routines."""
import struct
from debug_image import Image
from debug_runtime20 import MAGIC
from debug_metrics23 import app_metrics,poll_wrapper,sample_call
from patch_updater_copy_safety import frame,end

EVENTS={
 'AppMain.exe':[(0x130e50,1,100,'media_manager_startup'),(0xd9f04,1,101,'source_switch_request'),
                (0xd95a8,1,102,'overlay_source_restore'),(0xd6270,1,103,'navigation_launch'),
                (0x222000,1,310,'artwork_decode')],
 'MgrUSB.exe':[(0x13894,2,200,'usb_scan'),(0x13d88,2,201,'usb_sort'),
              (0x11f78,2,202,'usb_render_file'),(0x14720,2,203,'usb_next_folder')],
 'Blue.exe':[(0x1ace4,3,300,'bluetooth_audio_start'),(0x280400,3,301,'artwork_publish')],
}


def command(i, dbg,op,delay='nop'):
    return f'lui a0, 0x4d58\nori a0, a0, {0x4400+op}\nla t8, {hex(dbg)}\nlw t9, 0(t8)\njalr t9\n{delay}'


def instrument(i,dbg,tick,entry,module,event,label,before='',after='',threshold=0,emit_begin=True):
    target,row=i.clone(entry)
    # Only cookie-only exception handlers are retained for the reviewed AppMain entries.
    assert row[2] in (0,0x140db8,0x254e4)
    regs=['s0','s1','s2','s3','s4','s5','s6','s7']
    save='\n'.join(f'lw t0, {0x90+j*4}(sp)\nsw t0, {0x10+j*4}(sp)' for j in range(9))
    begin=f'''addiu a1, zero, {module}
lui a2, 0x8000
ori a2, a2, {event}
move a3, zero
sw zero, 0x10(sp)
{command(i,dbg,4)}''' if emit_begin else ''
    code=f'''{frame(0x80,regs)}
move s0, a0
move s1, a1
move s2, a2
move s3, a3
la t8, {hex(i.last)}
lw t9, 0(t8)
jalr t9
nop
sw v0, 0x44(sp)
{before}
{command(i,dbg,3)}
andi s4, v0, 1
beqz s4, original
nop
la t8, {hex(tick)}
lw t9, 0(t8)
jalr t9
nop
move s5, v0
{begin}
{sample_call(i,dbg,902) if event==310 else ""}
original:
{save}
lw a0, 0x44(sp)
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
move a0, s0
move a1, s1
move a2, s2
jal {hex(target)}
move a3, s3
move s6, v0
move s7, v1
la t8, {hex(i.last)}
lw t9, 0(t8)
jalr t9
nop
sw v0, 0x44(sp)
beqz s4, finish
nop
la t8, {hex(tick)}
lw t9, 0(t8)
jalr t9
nop
subu a3, v0, s5
sltiu t0, a3, {threshold}
bnez t0, finish
nop
addiu a1, zero, {module}
addiu a2, zero, {event}
sw s6, 0x10(sp)
{command(i,dbg,4)}
finish:
{sample_call(i,dbg,903) if event==310 else ""}
{after}
lw a0, 0x44(sp)
la t8, {hex(i.setlast)}
lw t9, 0(t8)
jalr t9
nop
move v0, s6
move v1, s7
{end(0x80,regs)}'''
    wrapper=i.routine(code,0x800,0x80,regs);i.hook(entry,wrapper)
    return dict(entry=entry,clone=target,wrapper=wrapper,module=module,event=event,label=label,minimum_duration_ms=threshold,begin_logged=emit_begin)


def settings(i,dbg):
    button=0x214400; label=0x214980; state=0x214c40
    assert not any(i.p.get_data(button-i.base,0x880))
    strings={k:i.string(v) for k,v in {
        'off':'Debugging: Off','on':'Debugging: On','wait':'Waiting for USB',
        'active':'Logging active','error':'USB write error','full':'USB full',
        'failed':'Logger could not start','disabled':'Logging off','save':'Setting could not be saved',
    }.items()}
    # Static rectangles and copied native colors are immutable read-only data.
    rect=i.text+0x1f000
    i.body[0x1f000:0x1f030]=struct.pack('<12I',10,247,694,69,72,318,610,65,62,0,554,69)
    ctor=i.text+0x10000;refresh=i.text+0x11000;page=i.text+0x11800;event=i.text+0x12000;paint=i.text+0x12800
    code=f'''{frame(0x90,['s0','s1','s2'])}
move s0, a0
# Native Settings array must already have two spare slots; never reallocate for diagnostics.
lw t0, 8(s0)
beqz t0, done
nop
lw t0, 12(s0)
addiu t0, t0, 2
lw t1, 16(s0)
sltu t2, t1, t0
bnez t2, done
nop
la a0, {hex(button)}
jal 0x13ea5c
nop
la a0, {hex(label)}
jal 0x139458
nop
la t0, {hex(state)}
sw s0, 0(t0)
la t0, {hex(rect)}
lw t1, 0(t0)
sw t1, 0x38(sp)
lw t1, 4(t0)
sw t1, 0x3c(sp)
lw t1, 8(t0)
sw t1, 0x40(sp)
lw t1, 12(t0)
sw t1, 0x44(sp)
lw t1, 16(t0)
sw t1, 0x58(sp)
lw t1, 20(t0)
sw t1, 0x5c(sp)
lw t1, 24(t0)
sw t1, 0x60(sp)
lw t1, 28(t0)
sw t1, 0x64(sp)
la t0, 0x187b38
lw t0, 0(t0)
lw t0, 0x2464(t0)
bnez t0, positioned
nop
addiu t0, zero, 177
sw t0, 0x3c(sp)
addiu t0, zero, 248
sw t0, 0x5c(sp)
positioned:
addiu a0, s0, 4
la a1, {hex(button)}
addiu a2, zero, 303
addiu a3, sp, 0x38
addiu t0, zero, 0x4d58
sw t0, 0x10(sp)
addiu t0, zero, 9
sw t0, 0x14(sp)
la t0, {hex(strings['off'])}
sw t0, 0x18(sp)
addiu t0, sp, 0x48
lw t1, 0x1b64(s0)
sw t1, 0x48(sp)
lw t1, 0x1b68(s0)
sw t1, 0x4c(sp)
lw t1, 0x1b6c(s0)
sw t1, 0x50(sp)
lw t1, 0x1b70(s0)
sw t1, 0x54(sp)
la t1, {hex(rect+32)}
sw t1, 0x1c(sp)
sw t0, 0x20(sp)
addiu t0, zero, 0x824
sw t0, 0x24(sp)
sw zero, 0x28(sp)
addiu t0, zero, 1
sw t0, 0x2c(sp)
sw zero, 0x30(sp)
jal 0x13d488
nop
la t0, {hex(button)}
lw t1, 0x2c(t0)
ori t1, t1, 0x400
sw t1, 0x2c(t0)
addiu a0, s0, 8
la a1, {hex(label)}
jal 0x138e90
nop
la t0, {hex(label)}
lw t1, 0x2c(t0)
ori t1, t1, 0x400
sw t1, 0x2c(t0)
la a0, {hex(label)}
addiu a1, zero, -1
addiu a2, sp, 0x58
addiu a3, s0, 4
la t0, {hex(label)}
lw t1, 0(t0)
lw t9, 0x18(t1)
jalr t9
nop
la t0, 0x186538
lw t0, 0(t0)
lw a1, 0x20(t0)
la a0, {hex(label)}
jal 0x139528
addiu a2, zero, 6
la a0, {hex(label)}
la a1, {hex(strings['disabled'])}
jal 0x139668
move a2, zero
done:
{end(0x90,['s0','s1','s2'])}'''
    i.routine_at(ctor,code,0x1000,0x90,['s0','s1','s2'])
    # Refresh happens on native Settings initialization/page changes and painting.
    i.routine_at(refresh,f'''{frame(0x40,['s0','s1','s2','s3'])}
la t0, {hex(state)}
lw s0, 0(t0)
beqz s0, done
nop
{command(i,dbg,3)}
move s1, v0
andi t0, s1, 1
la t1, {hex(button)}
sw t0, 0x34(t1)
la a1, {hex(strings['off'])}
beqz t0, caption
nop
la a1, {hex(strings['on'])}
caption:
la a0, {hex(button+0x74)}
jal 0x139668
move a2, zero
andi t0, s1, 0x8000
bnez t0, save_error
nop
srl t0, s1, 8
andi t0, t0, 0x7f
la a1, {hex(strings['disabled'])}
beqz t0, text
nop
addiu t1, zero, 1
la a1, {hex(strings['wait'])}
beq t0, t1, text
nop
addiu t1, zero, 2
la a1, {hex(strings['active'])}
beq t0, t1, text
nop
addiu t1, zero, 4
la a1, {hex(strings['full'])}
beq t0, t1, text
nop
addiu t1, zero, 5
la a1, {hex(strings['failed'])}
beq t0, t1, text
nop
la a1, {hex(strings['error'])}
b text
nop
save_error:
la a1, {hex(strings['save'])}
text:
la a0, {hex(label)}
jal 0x139668
move a2, zero
la t0, 0x186538
lw t0, 0(t0)
lw t0, 0x6d8(t0)
addiu t1, zero, 3
lui t2, 0xff
ori t2, t2, 0xffff
bne t0, t1, color
nop
move t2, zero
color:
la t0, {hex(label)}
sw t2, 0x60(t0)
lw t0, 0x5260(s0)
sltu s2, zero, t0
la a0, {hex(button)}
move a1, s2
jal 0x1393e0
move a2, zero
la a0, {hex(label)}
move a1, s2
jal 0x1393e0
move a2, zero
lw a1, 0x50(s0)
{command(i,dbg,6)}
beqz s2, done
nop
la a0, {hex(button)}
jal 0x139020
nop
la a0, {hex(label)}
jal 0x139020
nop
addiu a0, s0, 4
la a1, {hex(button+8)}
jal 0x13d220
move a2, zero
addiu a0, s0, 4
la a1, {hex(label+8)}
jal 0x13d220
move a2, zero
done:
{end(0x40,['s0','s1','s2','s3'])}''',0x800,0x40,['s0','s1','s2','s3'])
    # Delegate all original events directly, without changing the native GS frame.
    i.routine_at(event,f'''addiu t0, zero, 0x4d58
beq a1, t0, toggle
nop
j 0xc78ec
nop
toggle:
{frame(0x30,['s0','s1'])}
{command(i,dbg,3)}
andi a1, v0, 1
xori a1, a1, 1
{command(i,dbg,2)}
{command(i,dbg,1)}
jal {hex(refresh)}
nop
move v0, zero
{end(0x30,['s0','s1'])}''',0x800,0x30,['s0','s1'])
    # Event dispatch's branch prefix has no frame.
    r=next(r for r in i.rows if r[0]==event);i.rows.remove(r)
    i.rows.extend([(event,event+20,0,0,event),(event+20,r[1],0,0,event+20+16)])
    assert i.p.get_data(0x16f99c-i.base,4)==struct.pack('<I',0xc78ec)
    i.edit(0x16f99c,struct.pack('<I',event),'System settings debugging event; other native events retained')
    tick=i.import_at(535)
    ctor_after=f'move a0, s0\njal {hex(ctor)}\nnop\njal {hex(refresh)}\nnop'
    instrumentation=[instrument(i,dbg,tick,0xc6988,1,110,'settings_construct',after=ctor_after)]
    for entry,name in [(0xc76ac,'settings_initialize'),(0xc818c,'settings_page')]:
        instrumentation.append(instrument(i,dbg,tick,entry,1,111 if entry==0xc76ac else 112,name,after=f'jal {hex(refresh)}\nnop'))
    # Paint callbacks retain the original exception metadata; wrap direct callers only.
    paint_code=f'''{frame(0x30,['s0','s1'])}
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
{end(0x30,['s0','s1'])}'''
    i.routine_at(paint,paint_code,0x800,0x30,['s0','s1'])
    section=i.p.sections[0];data=section.get_data();calls=[]
    for off in range(0,len(data)-3,4):
        if int.from_bytes(data[off:off+4],'little')==(3<<26)|(0x134d28>>2):
            at=i.base+section.VirtualAddress+off;i.hook(at,paint,True);calls.append(at)
    assert calls
    return dict(button_va=button,status_label_va=label,context_va=state,event=0x4d58,
                rect=[10,247,694,69],status_rect=[72,318,610,65],rect_without_eco=[10,177,694,69],status_rect_without_eco=[72,248,610,65],refresh=refresh,constructor=ctor,
                strings=strings,paint_wrapper=paint,paint_calls=calls,extra_hooks=instrumentation)


def build_client(raw,pin,name):
    i=Image(raw,pin,writable=name!='AppMain.exe')
    # Capture both ordinary debug strings and formatted panic/error diagnostics.
    i.replace_imports={(b'coredll.dll',541):('CmnDll.dll','MxOutputDebugStringW'),
                       (b'coredll.dll',545):('CmnDll.dll','MxNKDbgPrintfW')}
    try:dbg=i.import_at('DbgDebugPrint')
    except StopIteration:dbg=i.add_import('CmnDll.dll','DbgDebugPrint')
    i.last=i.import_at(516)
    try:i.setlast=i.import_at(517)
    except StopIteration:i.setlast=i.add_import('COREDLL.dll',517,0x214c60 if name=='AppMain.exe' else None)
    tick=i.import_at(535) if name!='Blue.exe' else i.add_import('COREDLL.dll',535)
    if name=='AppMain.exe':
        i.apis={'memory':i.add_import('COREDLL.dll',88,0x214c68),
                'increment':i.add_import('COREDLL.dll',10,0x214c6c)}
    hooks=[]
    for entry,module,event,label in EVENTS.get(name,[]):
        hooks.append((poll_wrapper if name=='Blue.exe' and event==301 else instrument)(i,dbg,tick,entry,module,event,label))
    ui=None
    if name=='AppMain.exe':
        # Keep low helper bank for event wrappers; Settings bank begins at +0x10000.
        hooks.append(instrument(i,dbg,tick,0x134948,1,99,'app_main',
                                before=command(i,dbg,1)))
        i.invalidate=i.add_import('COREDLL.dll',250,0x214c64)
        ui=settings(i,dbg)
        hooks.append(instrument(i,dbg,tick,0x134d28,1,104,'screen_paint',threshold=16,emit_begin=False))
        assert i.code_cursor<0x10000,'Generated hooks must not overlap fixed Settings bank'
    metrics=app_metrics(i,dbg,tick,hooks) if name=='AppMain.exe' else None
    out,recipe=i.finish()
    recipe.update(binary=name,events=hooks,settings=ui,capture_native_output=True,metrics=metrics)
    return out,recipe

