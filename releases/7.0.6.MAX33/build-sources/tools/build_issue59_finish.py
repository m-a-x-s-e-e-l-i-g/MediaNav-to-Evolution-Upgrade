"""Build the MAX30 application completion program with block-resumable writes.

No reporter-specific inputs, settings, kernel changes or MCU flashing.
"""
import argparse, hashlib, json, shutil, subprocess
from pathlib import Path,PurePosixPath
import pefile
from build_issue56_repair import ROOT,ZIG_SHA,CORE,TAIL,cstr,cbytes,linked_to_pe,wsl_path

BASE=ROOT/'build/max30-quieter-logging-development-03'
PIN='5e649714c20503cd9fb738d54aa836577d73714f888b05d718c06a2acc6550d7'
PLAN_PIN='35a48c980f4c5623b2b124a5170c550cce9203f77c0fa3d91755588bd8566ecb'
COMMON_PIN='32359ebba0b3c9e86925a0d4e9a6408bd6c8cd50934410cbd85fdc81d05b1e52'
BLOCK=262144
EXTRA=[173,509,506,544,497]

def sha(b):return hashlib.sha256(b).hexdigest()

def manifest(out):
    assert sha((BASE/'upgrade.lgu').read_bytes())==PIN
    plan=(BASE/'member-plan.json').read_bytes();assert sha(plan)==PLAN_PIN
    rows=json.loads(plan)['members'];assert len(rows)==1920
    paths={r['path']for r in rows}
    assert {p.relative_to(BASE/'payload').as_posix()for p in (BASE/'payload').rglob('*')if p.is_file()}==paths
    package=b'MAXmade issue59 MAX30 completion 01 / '+PIN.encode()+b'\r\n'
    chunks=[];items=[];seen=set()
    for r in rows:
        p=PurePosixPath(r['path']);assert not p.is_absolute() and '..'not in p.parts
        assert r['path'].startswith(('upgrade/Storage Card/','upgrade/Storage Card4/')) or r['path']=='upgrade/firmware.hex'
        assert r['path'].lower() not in seen;seen.add(r['path'].lower())
        raw=(BASE/'payload'/r['path']).read_bytes();assert len(raw)==r['after']['bytes'] and sha(raw)==r['after']['sha256']
        path='\\'+r['path'].removeprefix('upgrade/').replace('/','\\');assert len(path)+len('.max59-new')<260
        action=2 if path in [r'\Storage Card\NK.bin',r'\firmware.hex'] else 1 if path==r'\Storage Card\System\Version_Info.txt' else 0
        first=len(chunks)
        for start in range(0,max(len(raw),1),BLOCK):
            b=raw[start:start+BLOCK];chunks.append((len(b),hashlib.sha256(b).digest()))
        items.append((path,len(raw),bytes.fromhex(r['after']['sha256']),3 if path.startswith('\\Storage Card4\\')else 0,action,first,len(chunks)-first))
    lines=['#define ITEM_COUNT 1920',f'#define CHUNK_BYTES {BLOCK}',f'#define PACKAGE_BYTES {len(package)}',
           'static const B package_id[]='+cbytes(package)+';',
           'static const B package_hash[32]='+cbytes(hashlib.sha256(package).digest())+';',
           'typedef struct {U bytes; B hash[32];} Block;',
           'static const Item items[]={']
    for p,n,h,v,a,f,c in items:lines.append('{'+','.join([cstr(p),str(n),cbytes(h),str(v),str(a),str(f),str(c)])+'},')
    lines+=['};','static const Block blocks[]={']+[ '{'+str(n)+','+cbytes(h)+'},'for n,h in chunks]+['};']
    for name,member in [('NK','upgrade/Storage Card/NK.bin'),('UPDATER','upgrade/Storage Card/System/UpgradeManager.exe'),('VERSION','upgrade/Storage Card/System/Version_Info.txt')]:
        r=next(r['after']for r in rows if r['path']==member)
        lines += [f'#define {name}_BYTES {r["bytes"]}',f'static const B {name.lower() if name!="UPDATER" else "updater"}_hash[32]='+cbytes(bytes.fromhex(r['sha256']))+';']
    (out/'manifest.h').write_text('\n'.join(lines)+'\n')
    return rows,dict(package_lgu_sha256=PIN,member_plan_sha256=PLAN_PIN,full_manifest_members=len(rows),
                     application_files=sum(r[4]==0 for r in items),block_count=len(chunks),block_bytes=BLOCK,
                     payload_bytes=sum(r['after']['bytes']for r in rows),nk_sha256=next(r['after']['sha256']for r in rows if r['path'].endswith('/NK.bin')))

def build(out):
    out.mkdir(parents=True,exist_ok=False)
    rows,info=manifest(out)
    old=(ROOT/'tools/issue56_repair.c').read_bytes();assert sha(old)==COMMON_PIN
    common=old.decode().split('typedef struct {U size,usage,pid')[0]
    common=common.replace('DISPATCH, API_COUNT','DISPATCH, SEEK, OPENPROC, RPM, TERM, WAIT, API_COUNT')
    common=common.replace('U volume; U action;','U volume; U action; U first; U count;')
    common=common.replace('MAX56','MAX59').replace('.max56-new','.max59-new')
    (out/'common.h').write_text(common)
    shutil.copyfile(ROOT/'tools/issue59_finish.c',out/'issue59_finish.c')
    groups=[('COREDLL.dll',0,CORE),('toolhelp.dll',len(CORE),[2,10,11,1]),('COREDLL.dll',len(CORE)+4,TAIL+EXTRA)]
    for filename,ords,names in [('coredll.dll',CORE+TAIL+EXTRA,['CreateFileW','ReadFile','WriteFile','CloseHandle','GetFileSize','GetFileAttributesW','CreateDirectoryW','DeleteFileW','MoveFileW','FlushFileBuffers','GetModuleFileNameW','GetLastError','GetDiskFreeSpaceExW','MessageBoxW','CreateMutexW','ReleaseMutex','GetTickCount','CreateWindowExW','SetWindowTextW','UpdateWindow','DestroyWindow','PeekMessageW','TranslateMessage','DispatchMessageW','SetFilePointer','OpenProcess','ReadProcessMemory','TerminateProcess','WaitForSingleObject']),
                                 ('toolhelp.dll',[2,10,11,1],['CreateToolhelp32Snapshot','Process32First','Process32Next','CloseToolhelp32Snapshot'])]:
        p=pefile.PE(str(ROOT/'extracted/705md-rom/fs/Windows'/filename));exports={s.ordinal:s.name.decode()for s in p.DIRECTORY_ENTRY_EXPORT.symbols if s.name}
        assert [exports[o]for o in ords]==names
    # Runtime error/phase addresses are valid only for this exact fixed-base updater.
    updater=pefile.PE(str(BASE/'UpgradeManager.exe'));assert updater.OPTIONAL_HEADER.ImageBase==0x10000
    assert updater.get_data(0x41000-0x10000,4)==bytes(4)
    linker='ENTRY(entry)\nSECTIONS { . = 0x11000; .text : { *(.text*) } . = ALIGN(4096); .rdata : { *(.rodata*) } . = ALIGN(4096); .data : { *(.data*) *(.sdata*) } . = ALIGN(4096); .bss : { *(.bss*) *(.sbss*) *(COMMON) } /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.comment) *(.note*) *(.eh_frame*) *(.got*) } }'
    (out/'link.ld').write_text(linker)
    zig=ROOT/'tools/vendor/zig-windows-x86_64-0.13.0/zig.exe';assert sha(Path(str(zig.parent)+'.zip').read_bytes())==ZIG_SHA
    cmd=[str(zig),'cc','-Xclang','-target-feature','-Xclang','+noabicalls','-target','mipsel-freestanding','-march=mips2','-mabi=32','-msoft-float','-mno-abicalls','-fno-pic','-G0','-ffreestanding','-fno-builtin','-fno-stack-protector','-fno-unwind-tables','-fno-asynchronous-unwind-tables','-fomit-frame-pointer','-fshort-wchar','-Os','-Wall','-Wextra','-Werror','-Wno-unused-function','-Wno-unused-variable','-c',str(out/'issue59_finish.c'),'-o',str(out/'finish.o')]
    subprocess.run(cmd,check=True,cwd=ROOT)
    subprocess.run(['wsl','-d','Ubuntu','--','mipsel-linux-gnu-ld','-T',wsl_path(out/'link.ld'),'--emit-relocs','-o',wsl_path(out/'finish.elf'),wsl_path(out/'finish.o')],check=True)
    raw,recipe=linked_to_pe((out/'finish.elf').read_bytes(),(BASE/'UpgradeManager.exe').read_bytes(),groups)
    (out/'MAX59Finish.exe').write_bytes(raw)
    info.update(recipe);info.update(exe_sha256=sha(raw),exe_bytes=len(raw),physical_tested=False,common_source_sha256=COMMON_PIN,
                                   source_sha256=sha((out/'issue59_finish.c').read_bytes()),manifest_sha256=sha((out/'manifest.h').read_bytes()),
                                   compiler_archive_sha256=ZIG_SHA,source_only_members=['upgrade/Storage Card/NK.bin','upgrade/firmware.hex'])
    (out/'build.json').write_text(json.dumps(info,indent=2)+'\n')
    fixture=out/'fixture';fixture.mkdir();shutil.copyfile(out/'MAX59Finish.exe',fixture/'MAX56Repair.exe');shutil.copyfile(out/'build.json',fixture/'build.json')
    print(json.dumps({k:v for k,v in info.items()if k!='symbols'},indent=2))

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);build(p.parse_args().output.resolve())
