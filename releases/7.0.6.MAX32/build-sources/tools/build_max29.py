"""Build a full MAX28 successor with ROM fallback and startup recovery guards."""
import argparse,json,shutil,subprocess,struct
import pefile
from pathlib import Path
from debug_image import Image,sha
from debug_runtime28 import build_core
from boot_recovery29 import build_kernel,build_updater,build_dboot
from build_issue56_repair import linked_to_pe,wsl_path,ZIG_SHA,PLAN_PIN
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max28-installer-recovery-development-03'
ORIGINAL=ROOT/'build/max18-navigation-launch-development-01'
BASE_SHA='07dbebeba1dee814ab02b1d28d359285a14a2c1a72342a89a8685bbd52554f2d'
REVISION='7.0.6.MAX29'

def recovery(out):
    c=ROOT/'tools/recovery29.c';shutil.copyfile(c,out/c.name)
    link='ENTRY(entry)\nSECTIONS { . = 0x11000; .text : { *(.text*) } . = ALIGN(4096); .rdata : { *(.rodata*) } . = ALIGN(4096); .data : { *(.data*) *(.sdata*) } . = ALIGN(4096); .bss : { *(.bss*) *(.sbss*) *(COMMON) } /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.comment) *(.note*) *(.eh_frame*) *(.got*) } }'
    (out/'recovery.ld').write_text(link)
    zig=ROOT/'tools/vendor/zig-windows-x86_64-0.13.0/zig.exe';assert sha(Path(str(zig.parent)+'.zip').read_bytes())==ZIG_SHA
    cmd=[str(zig),'cc','-Xclang','-target-feature','-Xclang','+noabicalls','-target','mipsel-freestanding','-march=mips2','-mabi=32','-msoft-float','-mno-abicalls','-fno-pic','-G0','-ffreestanding','-fno-builtin','-fno-stack-protector','-fno-unwind-tables','-fno-asynchronous-unwind-tables','-fomit-frame-pointer','-fshort-wchar','-Os','-Wall','-Wextra','-Werror','-c',str(c),'-o',str(out/'recovery.o')]
    subprocess.run(cmd,check=True,cwd=ROOT)
    subprocess.run(['wsl','-d','Ubuntu','--','mipsel-linux-gnu-ld','-T',wsl_path(out/'recovery.ld'),'--emit-relocs','-o',wsl_path(out/'recovery.elf'),wsl_path(out/'recovery.o')],check=True)
    b,r=linked_to_pe((out/'recovery.elf').read_bytes(),(BASE/'UpgradeManager.exe').read_bytes(),[('COREDLL.dll',0,[858,493,553,166,165,516,555,556])])
    p=pefile.PE(data=b);value=bytearray(b);struct.pack_into('<I',value,p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),p.generate_checksum());b=bytes(value)
    r.update(output_sha256=sha(b),source_sha256=sha(c.read_bytes()),physical_tested=False)
    return b,r

def build(out):
    assert not out.exists()and sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    plan=(BASE/'member-plan.json').read_bytes();assert sha(plan)==PLAN_PIN
    prior={r['path']:r['after']for r in json.loads(plan)['members']};tree(BASE/'payload',prior)
    out.mkdir(parents=True);shutil.copytree(BASE/'payload',out/'payload');expected=dict(prior)
    for n in ['AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe','CmnDll.dll']:
        for suffix in ['', '.json']:shutil.copyfile(BASE/(n+suffix),out/(n+suffix))
    shutil.copytree(BASE/'nng',out/'nng')
    changed={}
    for name,fn in [('NK.bin',build_kernel),('System/UpgradeManager.exe',build_updater),('System/dboot.exe',build_dboot)]:
        path='upgrade/Storage Card/'+name;old=(BASE/'payload'/path).read_bytes()
        b,r=fn(old)if fn==build_kernel else fn(old,prior[path]['sha256'])
        if fn==build_updater:
            inherited=json.loads((BASE/'UpgradeManager.exe.json').read_bytes())
            r['recovery']=inherited['recovery'];r['helper_rows']=inherited['helper_rows']+r['helper_rows'];r['edits']=inherited['edits']+r['edits']
        changed[path]=b;filename=Path(name).name;(out/filename).write_bytes(b);write(out/(filename+'.json'),r)
    path='upgrade/Storage Card/System/CmnDll.dll';old={r['path']:r['after']for r in json.loads((ORIGINAL/'member-plan.json').read_bytes())['members']}
    i=Image((ORIGINAL/'payload'/path).read_bytes(),old[path]['sha256']);runtime=build_core(i)
    at=runtime['strings']['header']-i.text;a='\ufeffMAXmade 7.0.6.MAX28 diagnostics'.encode('utf-16-le');b='\ufeffMAXmade 7.0.6.MAX29 diagnostics'.encode('utf-16-le');assert i.body[at:at+len(a)]==a;i.body[at:at+len(b)]=b
    runtime['measurements_revision']=29;b,r=i.finish();changed[path]=b;(out/'CmnDll.dll').write_bytes(b);write(out/'CmnDll.dll.json',r);write(out/'runtime.json',runtime)
    changed['upgrade/Storage Card/System/Version_Info.txt']=REVISION.encode('ascii')
    b,r=recovery(out);changed['upgrade/Storage Card/Recovery.exe']=b;(out/'Recovery.exe').write_bytes(b);write(out/'Recovery.exe.json',r)
    for path,b in changed.items():(out/'payload'/path).write_bytes(b);expected[path]=dict(bytes=len(b),sha256=sha(b))
    tree(out/'payload',expected);tree(BASE/'payload',prior)
    write(out/'member-plan.json',dict(member_count=len(expected),prior_paths_retained=len(prior),retained_members=len(prior)-5,
          changed_members=sorted(k for k in changed if k in prior),added_members=sorted(set(expected)-set(prior)),missing_members=[],
          members=[dict(path=k,before=prior.get(k),after=expected[k])for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,full_previous_payload_retained=True,
          changed_members=sorted(changed),car_tested=False,rom_launcher_changed=True,bootloader_or_mcu_changed=False,
          universal_anti_brick_guarantee=False))
    print(out,flush=True)

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();build(a.output.resolve())
