"""Full MAX30 successor: intentional CE boots no longer become failed starts."""
import argparse,json,shutil,struct,subprocess
from pathlib import Path
import pefile
from debug_image import sha
from boot_recovery31 import build_kernel,build_dboot
from build_issue56_repair import linked_to_pe,wsl_path,ZIG_SHA
from package_max16 import tree,write

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max30-quieter-logging-development-03'
BASE_SHA='5e649714c20503cd9fb738d54aa836577d73714f888b05d718c06a2acc6550d7'
REVISION='7.0.6.MAX31'

def recovery(out):
    c=ROOT/'tools/recovery31.c';shutil.copyfile(c,out/c.name)
    link='ENTRY(entry)\nSECTIONS { . = 0x11000; .text : { *(.text*) } . = ALIGN(4096); .rdata : { *(.rodata*) } . = ALIGN(4096); .data : { *(.data*) *(.sdata*) } . = ALIGN(4096); .bss : { *(.bss*) *(.sbss*) *(COMMON) } /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.comment) *(.note*) *(.eh_frame*) *(.got*) } }'
    (out/'recovery.ld').write_text(link)
    zig=ROOT/'tools/vendor/zig-windows-x86_64-0.13.0/zig.exe';assert sha(Path(str(zig.parent)+'.zip').read_bytes())==ZIG_SHA
    cmd=[str(zig),'cc','-Xclang','-target-feature','-Xclang','+noabicalls','-target','mipsel-freestanding','-march=mips2','-mabi=32','-msoft-float','-mno-abicalls','-fno-pic','-G0','-ffreestanding','-fno-builtin','-fno-stack-protector','-fno-unwind-tables','-fno-asynchronous-unwind-tables','-fomit-frame-pointer','-fshort-wchar','-Os','-Wall','-Wextra','-Werror','-c',str(c),'-o',str(out/'recovery.o')]
    subprocess.run(cmd,check=True,cwd=ROOT)
    subprocess.run(['wsl','-d','Ubuntu','--','mipsel-linux-gnu-ld','-T',wsl_path(out/'recovery.ld'),'--emit-relocs','-o',wsl_path(out/'recovery.elf'),wsl_path(out/'recovery.o')],check=True)
    raw,r=linked_to_pe((out/'recovery.elf').read_bytes(),(BASE/'UpgradeManager.exe').read_bytes(),[('COREDLL.dll',0,[858,493,553,166,165,516,555,556])])
    p=pefile.PE(data=raw);value=bytearray(raw);struct.pack_into('<I',value,p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),p.generate_checksum())
    r.update(output_sha256=sha(value),source_sha256=sha(c.read_bytes()),physical_tested=False)
    return bytes(value),r

def build(out):
    assert not out.exists()and sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']}
    tree(BASE/'payload',prior);out.mkdir(parents=True);shutil.copytree(BASE/'payload',out/'payload');expected=dict(prior)
    for n in ['AppMain.exe','Blue.exe','MgrUSB.exe','MicomManager.exe','MgrIpod.exe','MgrDAB.exe','CmnDll.dll','UpgradeManager.exe','dboot.exe','NK.bin','Recovery.exe']:
        for suffix in ['', '.json']:shutil.copyfile(BASE/(n+suffix),out/(n+suffix))
    shutil.copytree(BASE/'nng',out/'nng');shutil.copyfile(BASE/'runtime.json',out/'runtime.json')
    changed={}
    for n,fn in [('NK.bin',build_kernel),('System/dboot.exe',build_dboot)]:
        path='upgrade/Storage Card/'+n;raw=(BASE/'payload'/path).read_bytes()
        data,r=fn(raw)if fn==build_kernel else fn(raw,prior[path]['sha256'])
        if fn==build_dboot:
            old=json.loads((BASE/'dboot.exe.json').read_bytes());r['boot_recovery']=old['boot_recovery']
            r['boot_recovery']['entry']=r['desktop_intent']['entry']
            r['routines']=old['routines']+r['routines'];r['helper_rows']=old['helper_rows']+r['helper_rows']
        changed[path]=data;(out/Path(n).name).write_bytes(data);write(out/(Path(n).name+'.json'),r)
    raw,r=recovery(out);changed['upgrade/Storage Card/Recovery.exe']=raw;(out/'Recovery.exe').write_bytes(raw);write(out/'Recovery.exe.json',r)
    path='upgrade/Storage Card/System/CmnDll.dll';raw=(BASE/'CmnDll.dll').read_bytes();p=pefile.PE(data=raw)
    runtime=json.loads((BASE/'runtime.json').read_bytes());r=json.loads((BASE/'CmnDll.dll.json').read_bytes())
    before='\ufeffMAXmade 7.0.6.MAX30 diagnostics'.encode('utf-16-le');after='\ufeffMAXmade 7.0.6.MAX31 diagnostics'.encode('utf-16-le')
    off=p.get_offset_from_rva(runtime['strings']['header']-p.OPTIONAL_HEADER.ImageBase);assert raw[off:off+len(before)]==before
    data=bytearray(raw);data[off:off+len(after)]=after;cs=p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I',data,cs,0);q=pefile.PE(data=bytes(data));struct.pack_into('<I',data,cs,q.generate_checksum())
    assert all(a==b or off<=j<off+len(before)or cs<=j<cs+4 for j,(a,b)in enumerate(zip(raw,data)))
    changed[path]=bytes(data);r['output_sha256']=sha(data);r['revision_only_from_MAX30']=dict(header_offset=off,checksum_offset=cs)
    runtime['measurements_revision']=31;(out/'CmnDll.dll').write_bytes(data);write(out/'CmnDll.dll.json',r);write(out/'runtime.json',runtime)
    changed['upgrade/Storage Card/System/Version_Info.txt']=REVISION.encode('ascii')
    for path,data in changed.items():(out/'payload'/path).write_bytes(data);expected[path]=dict(bytes=len(data),sha256=sha(data))
    tree(out/'payload',expected);tree(BASE/'payload',prior)
    write(out/'member-plan.json',dict(member_count=len(expected),prior_paths_retained=len(prior),retained_members=len(prior)-len(changed),
        changed_members=sorted(changed),added_members=[],missing_members=[],members=[dict(path=k,before=prior[k],after=expected[k])for k in sorted(expected)]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,changed_members=sorted(changed),
        full_previous_payload_retained=True,car_tested=False,updater_and_all_application_behavior_unchanged=True,
        native_DBooT_CE_setup_retained=True,universal_recovery_guarantee=False))
    print(out,flush=True)

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);build(p.parse_args().output.resolve())
