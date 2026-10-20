"""Recognize intentional DBoot CE sessions without disabling installer recovery."""
import hashlib,struct
from debug_image import Image,sha
from patch_updater_copy_safety import frame,end
from boot_recovery29 import FLAG,RECOVERY,DESKTOP,imports
from patch_usb_reliability import assemble
from build_issue56_usb_recovery import parse,launcher_objects,read_va

CE=r'\Storage Card3\StartWinCE'
DBOOT=r'\Storage Card\System\dboot.exe'
RECOVERY_COMMAND='-MAXmadeRecoveryCE'
KERNEL_PIN='14e80fb6c83be1ccfebcf76fa84c39a745c25b34917f2cf062e36cdb37f89724'

def build_kernel(raw):
    assert sha(raw)==KERNEL_PIN
    img=parse(raw);objects=launcher_objects(raw,img)
    physical=objects[0][3]-objects[0][1];base=objects[0][4]-objects[0][1]
    main=base+0x13f4;intent=base+0x1234;dboot=base+0x11f6
    # The original CodeView/PDB locator is inert debug data, not executable code,
    # an import or unwind record. Reuse its 52 bytes for the native CE marker.
    assert read_va(raw,img,physical+0x123c,4)==b'RSDS'
    text=(CE+'\0').encode('utf-16-le');assert len(text)<=0x34
    code=f'''addiu sp, sp, -0x28
sw ra, 0x20(sp)
sw s0, 0x1c(sp)
sw s1, 0x18(sp)
jal {hex(base+0x134c)}
addiu s0, zero, 200
la s1, {hex(dboot)}
probe:
move a0, s1
lui a1, 0x8000
jal {hex(base+0x1268)}
addiu a2, zero, 3
bnez v0, intent
nop
la t8, {hex(base+0x2010)}
lw t9, 0(t8)
jalr t9
addiu a0, zero, 10
addiu s0, s0, -1
bnez s0, probe
nop
intent:
addiu a0, s1, {intent-dboot}
lui a1, 0x8000
jal {hex(base+0x1268)}
addiu a2, zero, 3
bnez v0, normal
nop
addiu a0, s1, {base+0x1048-dboot}
lui a1, 0x8000
jal {hex(base+0x1268)}
addiu a2, zero, 3
bnez v0, recovery
nop
normal:
move a0, s1
jal {hex(base+0x12d8)}
addiu a1, zero, 1
bnez v0, done
nop
addiu a0, s1, {base+0x112c-dboot}
jal {hex(base+0x12d8)}
addiu a1, zero, 1
bnez v0, done
nop
recovery:
addiu a0, s1, {base+0x11c0-dboot}
jal {hex(base+0x12d8)}
move a1, zero
bnez v0, done
nop
addiu a0, s1, {base+0x1180-dboot}
jal {hex(base+0x12d8)}
move a1, zero
done:
lw s1, 0x18(sp)
lw s0, 0x1c(sp)
lw ra, 0x20(sp)
jr ra
addiu sp, sp, 0x28'''
    binary,recipe,_=assemble(code,main,0xec)
    out=bytearray(raw);allowed=set();changed=set();edits=[]
    for at,value,reason in [(main,binary,'Native StartWinCE request precedes stale startup marker'),
                           (intent,text.ljust(0x34,b'\0'),'Native CE path in former CodeView debug locator')]:
        stored=physical+at-base
        record=next(r for r in img['records']if r['address']<=stored<stored+len(value)<=r['address']+r['length'])
        off=record['offset']+stored-record['address'];out[off:off+len(value)]=value
        allowed.update(range(off,off+len(value)));changed.add(record['header'])
        edits.append(dict(va=at,offset=off,bytes=len(value),reason=reason))
    for r in img['records']:
        if r['header']in changed:
            struct.pack_into('<I',out,r['header']+8,sum(out[r['offset']:r['offset']+r['length']])&0xffffffff)
            allowed.update(range(r['header']+8,r['header']+12))
    assert parse(out)==img and all(a==b or j in allowed for j,(a,b)in enumerate(zip(raw,out)))
    return bytes(out),dict(source_sha256=sha(raw),output_sha256=sha(out),base=base,physical_base=physical,
        main=main,intent=intent,dboot=dboot,edits=edits,assembly=recipe,physical_tested=False,
        changed_modules=['ULC_launcher.exe'],kernel_layout_unchanged=True,bootloader_or_mcu_changed=False)

def build_dboot(raw,pin):
    i=Image(raw,pin);imports(i);flag=i.string(FLAG);command=i.string(RECOVERY_COMMAND);mode=i.rw
    # s3 is the original WinMain command-line pointer at this exact call site.
    assert i.p.get_data(0x17b20-i.base,8)==struct.pack('<II',0x0c004453,0x25049120)
    select=i.routine(f'''{frame(0x30,['s0','s1'])}
la t0, {hex(mode)}
sw zero, 0(t0)
jal 0x1114c
nop
bnez v0, intentional
nop
move s0, s3
beqz s0, normal
nop
la s1, {hex(command)}
compare:
lhu t0, 0(s0)
lhu t1, 0(s1)
bne t0, t1, normal
nop
beqz t0, recovery
nop
addiu s0, s0, 2
b compare
addiu s1, s1, 2
intentional:
addiu v0, zero, 1
b store
nop
recovery:
addiu v0, zero, 2
store:
la t0, {hex(mode)}
sw v0, 0(t0)
b done
nop
normal:
move v0, zero
done:
{end(0x30,['s0','s1'])}''',0x200,0x30,['s0','s1'])
    original,row=i.clone(0x113d4);assert row[2:4]==(0,0)
    enter=i.routine(f'''{frame(0x28,[])}
la t0, {hex(mode)}
lw t0, 0(t0)
addiu t1, zero, 1
bne t0, t1, native
nop
# Clear only the startup-attempt marker for the user's native CE request.
# Recovery-command entry keeps it; install receipts/scan flags are untouched.
la a0, {hex(flag)}
{i.api('delete')}
native:
jal {hex(original)}
nop
{end(0x28,[])}''',0x100,0x28,[])
    old_entry=i.base+i.p.OPTIONAL_HEADER.AddressOfEntryPoint
    # CE's CRT forwards its four entry arguments to WinMain unchanged (native
    # 0x181b4 -> 0x180e0 -> 0x17998). A recovery-only command must not require a
    # marker write: damaged/read-only Card3 must still permit desktop setup.
    entry=i.routine(f'''beqz a2, normal
nop
lui t0, 1
sltu t0, a2, t0
bnez t0, normal
nop
move t0, a2
la t1, {hex(command)}
compare:
lhu t2, 0(t0)
lhu t3, 0(t1)
bne t2, t3, normal
nop
beqz t2, recovery
nop
addiu t0, t0, 2
b compare
addiu t1, t1, 2
recovery:
j 0x181b4
nop
normal:
j {hex(old_entry)}
nop''',0x100)
    i.file_edit(i.p.OPTIONAL_HEADER.get_field_absolute_offset('AddressOfEntryPoint'),struct.pack('<I',entry-i.base),
                'Recovery-only DBoot entry permits native CE initialization without marker writes')
    i.hook(0x17b20,select,call=True);i.hook(0x113d4,enter)
    out,recipe=i.finish();recipe['desktop_intent']=dict(select=select,enter=enter,native_desktop=original,
        mode=mode,command=command,flag=flag,ce_path=CE,recovery_command=RECOVERY_COMMAND,
        selector_call=0x17b20,winmain=0x17998,entry=entry,prior_entry=old_entry,native_entry=0x181b4,native_gpio_init_retained=True,
        intentional_ce_clears_startup_attempt=True,recovery_ce_keeps_startup_attempt=True)
    return out,recipe
