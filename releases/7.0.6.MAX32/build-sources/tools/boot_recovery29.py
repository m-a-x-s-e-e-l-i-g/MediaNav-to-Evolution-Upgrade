"""Layered boot/installer escape paths for the exact MAX28 CE application set."""
import hashlib,struct
from debug_image import Image
from patch_updater_copy_safety import frame,end,STOP,CODE
from patch_usb_reliability import assemble
from build_issue56_usb_recovery import SOURCE_SHA,parse,launcher_objects,read_va

FLAG=r'\Storage Card3\MAXboot.flag'
RECOVERY=r'\Storage Card\Recovery.exe'
DESKTOP=r'\Windows\explorer.exe'

def build_kernel(raw):
    assert hashlib.sha256(raw).hexdigest()==SOURCE_SHA
    img=parse(raw);objects=launcher_objects(raw,img)
    # ROM storage pointers are not execution addresses. CE maps this EXE's
    # text at o32_realaddr (0x11000), with imports at its ordinary process VAs.
    physical=objects[0][3]-objects[0][1];base=objects[0][4]-objects[0][1]
    main=base+0x13f4;marker=base+0x1048;desktop=base+0x1180;recovery=base+0x11c0
    recovery_bytes=(RECOVERY+'\0').encode('utf-16-le');dboot=recovery+len(recovery_bytes)
    guard=base+0x1084
    code=f'''addiu sp, sp, -0x28
sw ra, 0x20(sp)
sw s3, 0x10(sp)
sw s2, 0x14(sp)
sw s1, 0x18(sp)
sw s0, 0x1c(sp)
jal {hex(base+0x134c)}
addiu s0, zero, 200
la s1, {hex(dboot)}
probe:
move a0, s1
lui a1, 0x8000
jal {hex(base+0x1268)}
addiu a2, zero, 3
bnez v0, marker
nop
la t8, {hex(base+0x2010)}
lw t9, 0(t8)
jalr t9
addiu a0, zero, 10
addiu s0, s0, -1
bnez s0, probe
nop
marker:
la a0, {hex(marker)}
lui a1, 0x8000
jal {hex(base+0x1268)}
addiu a2, zero, 3
bnez v0, recovery
nop
move a0, s1
jal {hex(base+0x12d8)}
addiu a1, zero, 1
bnez v0, done
nop
la a0, {hex(base+0x112c)}
jal {hex(base+0x12d8)}
addiu a1, zero, 1
bnez v0, done
nop
recovery:
la a0, {hex(recovery)}
jal {hex(base+0x12d8)}
move a1, zero
bnez v0, done
nop
la a0, {hex(desktop)}
jal {hex(base+0x12d8)}
move a1, zero
done:
lw s3, 0x10(sp)
lw s2, 0x14(sp)
lw s1, 0x18(sp)
lw s0, 0x1c(sp)
lw ra, 0x20(sp)
jr ra
addiu sp, sp, 0x28'''
    binary,recipe,_=assemble(code,main,0xec)
    # The ROM wrapper marks startup before even an old DBoot can run. Recovery
    # and Explorer never depend on creating that marker. Former log strings
    # provide bounded executable storage; no object is moved or enlarged.
    marker_code=f'''{frame(0x38,['s0','s1'])}
move s1, a1
move a1, zero
addiu a2, zero, 16
jal {hex(base+0x1934)}
addiu s0, zero, 20
beqz s1, success
nop
try:
la a0, {hex(marker)}
lui a1, 0x4000
jal {hex(base+0x1268)}
addiu a2, zero, 2
bnez v0, done
nop
addiu s0, s0, -1
beqz s0, done
nop
la t8, {hex(base+0x2010)}
lw t9, 0(t8)
jalr t9
addiu a0, zero, 100
b try
nop
success:
addiu v0, zero, 1
done:
{end(0x38,['s0','s1'])}'''
    marked,mark_recipe,_=assemble(marker_code,guard,0xa8)
    wrapper=f'''{frame(0x40,['s0'])}
move s0, a0
jal {hex(guard)}
addiu a0, sp, 0x28
bnez v0, launch
nop
la s0, {hex(desktop)}
launch:
addiu t0, sp, 0x28
sw t0, 0x24(sp)
move a0, s0
move a1, zero
move a2, zero
move a3, zero
sw zero, 0x20(sp)
sw zero, 0x1c(sp)
sw zero, 0x18(sp)
sw zero, 0x14(sp)
jal {hex(base+0x150c)}
sw zero, 0x10(sp)
sltu v0, zero, v0
{end(0x40,['s0'])}'''
    wrapped,wrap_recipe,_=assemble(wrapper,base+0x12d8,0x74)
    opened=f'''{frame(0x28,['s0'])}
sw a2, 0x10(sp)
move a2, zero
move a3, zero
sw zero, 0x14(sp)
sw zero, 0x18(sp)
la t8, {hex(base+0x2004)}
lw t9, 0(t8)
jalr t9
move s0, zero
addiu t0, zero, -1
beq v0, t0, done
nop
move a0, v0
la t8, {hex(base+0x2000)}
lw t9, 0(t8)
jalr t9
nop
sltu s0, zero, v0
done:
move v0, s0
{end(0x28,['s0'])}'''
    opened,open_recipe,_=assemble(opened,base+0x1268,0x70)
    edits=[(main,binary,'ROM launch selection and load-failure fallbacks'),(guard,marked,'Zero PI and bounded startup marker before DBoot/updater'),(base+0x1268,opened,'Checked read/write open-and-close primitive'),(base+0x12d8,wrapped,'Native launch wrapper fails to ROM Explorer if marker cannot be created')]
    for at,capacity,text in [(marker,56,FLAG),(desktop,64,DESKTOP)]:
        b=(text+'\0').encode('utf-16-le');assert len(b)<=capacity;edits.append((at,b.ljust(capacity,b'\0'),text))
    paths=recovery_bytes+(r'\Storage Card\System\dboot.exe'+'\0').encode('utf-16-le');assert len(paths)<=120
    edits.append((recovery,paths.ljust(120,b'\0'),'Recovery and DBoot paths in former startup log storage'))
    out=bytearray(raw);changed=set();allowed=set();records=[]
    for at,value,reason in edits:
        stored=physical+at-base
        assert any(o[3]<=stored<stored+len(value)<=o[3]+o[2]and not o[5]&0x2000 for o in objects)
        r=next(r for r in img['records']if r['address']<=stored<stored+len(value)<=r['address']+r['length'])
        off=r['offset']+stored-r['address'];old=bytes(out[off:off+len(value)])
        out[off:off+len(value)]=value;changed.add(r['header']);allowed.update(range(off,off+len(value)))
        records.append(dict(va=at,storage_va=stored,offset=off,bytes=len(value),before_sha256=hashlib.sha256(old).hexdigest(),reason=reason))
    for r in img['records']:
        if r['header']in changed:
            struct.pack_into('<I',out,r['header']+8,sum(out[r['offset']:r['offset']+r['length']])&0xffffffff)
            allowed.update(range(r['header']+8,r['header']+12))
    assert parse(out)==img
    assert all(a==b or i in allowed for i,(a,b)in enumerate(zip(raw,out)))
    return bytes(out),dict(source_sha256=SOURCE_SHA,output_sha256=hashlib.sha256(out).hexdigest(),
        base=base,physical_base=physical,main=main,marker=marker,desktop=desktop,recovery=recovery,guard=guard,dboot=dboot,edits=records,assembly=recipe,mark_assembly=mark_recipe,launch_assembly=wrap_recipe,
        changed_modules=['ULC_launcher.exe'],kernel_layout_unchanged=True,physical_tested=False)

def imports(i):
    i.apis={}
    for name,ordinal in [('process',493),('close',553),('open',168),('flush',175),('sleep',496),('delete',165),('show',266)]:
        try:i.apis[name]=i.import_at(ordinal)
        except StopIteration:i.apis[name]=i.add_import('COREDLL.dll',ordinal)

def helpers(i):
    imports(i);flag=i.string(FLAG);recovery=i.string(RECOVERY);desktop=i.string(DESKTOP)
    launch=i.routine(f'''{frame(0x70,['s0','s1'])}
move s0, zero
la s1, {hex(recovery)}
try:
sw zero, 0x40(sp)
sw zero, 0x44(sp)
sw zero, 0x48(sp)
sw zero, 0x4c(sp)
move a0, s1
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
bnez v0, success
nop
bnez s0, failed
nop
addiu s0, zero, 1
la s1, {hex(desktop)}
b try
nop
success:
lw a0, 0x40(sp)
{i.api('close')}
lw a0, 0x44(sp)
{i.api('close')}
addiu v0, zero, 1
b done
nop
failed:
move v0, zero
done:
{end(0x70,['s0','s1'])}''',0x300,0x70,['s0','s1'])
    mark=i.routine(f'''{frame(0x40,['s0','s1'])}
addiu s1, zero, 20
try:
la a0, {hex(flag)}
lui a1, 0x4000
addiu a2, zero, 3
move a3, zero
addiu t0, zero, 2
sw t0, 0x10(sp)
addiu t0, zero, 0x80
sw t0, 0x14(sp)
sw zero, 0x18(sp)
{i.api('open')}
move s0, v0
addiu t0, zero, -1
bne s0, t0, opened
nop
addiu s1, s1, -1
beqz s1, failed
nop
addiu a0, zero, 100
{i.api('sleep')}
b try
nop
opened:
move a0, s0
{i.api('flush')}
move s1, v0
move a0, s0
{i.api('close')}
beqz v0, failed
nop
sltu v0, zero, s1
b done
nop
failed:
move v0, zero
done:
{end(0x40,['s0','s1'])}''',0x300,0x40,['s0','s1'])
    old=i.base+i.p.OPTIONAL_HEADER.AddressOfEntryPoint
    entry=i.routine(f'''{frame(0x38,[])}
sw a0, 0x20(sp)
sw a1, 0x24(sp)
sw a2, 0x28(sp)
sw a3, 0x2c(sp)
jal {hex(mark)}
nop
beqz v0, recover
nop
lw a0, 0x20(sp)
lw a1, 0x24(sp)
lw a2, 0x28(sp)
lw a3, 0x2c(sp)
lw ra, 0x34(sp)
addiu sp, sp, 0x38
j {hex(old)}
nop
recover:
jal {hex(launch)}
nop
move v0, zero
{end(0x38,[])}''',0x200,0x38,[])
    i.file_edit(i.p.OPTIONAL_HEADER.get_field_absolute_offset('AddressOfEntryPoint'),struct.pack('<I',entry-i.base),'Mark startup before the original CRT or open independent recovery')
    return dict(flag=flag,launch=launch,mark=mark,entry=entry,original_entry=old)

def build_updater(raw,pin):
    i=Image(raw,pin);h=helpers(i)
    # The old visible error paint and button remain; recover after painting,
    # at the specific installer worker ExitThread call, not at every thread exit.
    exiting=i.routine(f'''{frame(0x30,['s0'])}
move s0, a0
jal {hex(h['launch'])}
nop
beqz v0, exit
nop
la t0, 0x38efc
lw a0, 0(t0)
beqz a0, exit
nop
move a1, zero
{i.api('show')}
exit:
move a0, s0
la t8, 0x37020
lw t9, 0(t8)
jalr t9
nop
park:
b park
nop''',0x180,0x30,['s0'])
    clone,row=i.clone(STOP);assert row[2:4]==(0,0)
    code=i.body[clone-i.text:clone-i.text+row[1]-row[0]]
    offsets=[j for j in range(0,len(code),4)if struct.unpack_from('<I',code,j)[0]==0x0320f809]
    assert len(offsets)==1
    at=clone+offsets[0];struct.pack_into('<I',i.body,at-i.text,(3<<26)|(exiting>>2));i.reloc.append((at-i.base,5,None));i.hook(STOP,clone)
    # Preserve the native KillTimer and its already-executed ready-flag store.
    ready=i.routine(f'''{frame(0x30,['s0'])}
jal 0x2a2e0
nop
move s0, v0
la t0, {hex(CODE)}
lw t0, 0(t0)
bnez t0, done
nop
la t0, 0x38f10
lw t0, 0(t0)
bnez t0, done
nop
la a0, {hex(h['flag'])}
{i.api('delete')}
done:
move v0, s0
{end(0x30,['s0'])}''',0x100,0x30,['s0'])
    assert i.p.get_data(0x13f2c-i.base,8)==struct.pack('<II',(3<<26)|(0x2a2e0>>2),0xaef08f44)
    i.hook(0x13f2c,ready,call=True)
    from first_phase29 import add
    first_phase=add(i,h)
    out,recipe=i.finish();recipe['boot_recovery']=dict(**h,exit=exiting,stop_clone=clone,ready=ready,
       ready_call=0x13f2c,automatic_recovery=True,format=False,flag_path=FLAG,first_phase=first_phase)
    return out,recipe

def build_dboot(raw,pin):
    i=Image(raw,pin);h=helpers(i)
    # Clone the complete native file-exists + ShellExecuteEx wrapper, so an
    # absent executable is handled as well as a refused shell launch.
    thunk=0x1119c;original,row=i.clone(thunk);assert row[2:4]==(0,0)
    wrapper=i.routine(f'''{frame(0x28,[])}
jal {hex(original)}
nop
bnez v0, done
nop
jal {hex(h['launch'])}
nop
done:
{end(0x28,[])}''',0x100,0x28,[])
    i.hook(thunk,wrapper)
    out,recipe=i.finish();recipe['boot_recovery']=dict(**h,shell_thunk=thunk,shell_wrapper=wrapper,shell_clone=original,flag_path=FLAG)
    return out,recipe
