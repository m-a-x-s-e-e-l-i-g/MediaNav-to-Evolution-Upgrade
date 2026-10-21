"""Build a full MAX32 successor with native application transaction integration."""
import argparse,hashlib,json,shutil,struct,subprocess
from pathlib import Path
import pefile
from build_issue56_repair import ROOT,CORE,TAIL,ZIG_SHA,linked_to_pe,wsl_path,cbytes,cstr
from installer_resume33 import build as patch_updater,COMPLETION
from package_max16 import tree,write

BASE=ROOT/'build/max32-iphone-release-01'
BASE_SHA='2c657ec6056b003681a5c4c77ee3f1b4a6c0cf5e7a5bd8c7ce3b4ab92d1998bb'
REVISION='7.0.6.MAX33'
EXTRA=[173,509,506,544,497,1231,493,161]

def sha(b):return hashlib.sha256(b).hexdigest()

def compile_c(out,name,source,groups):
    out.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,out/source.name)
    link='ENTRY(entry)\nSECTIONS { . = 0x11000; .text : { *(.text*) } . = ALIGN(4096); .rdata : { *(.rodata*) } . = ALIGN(4096); .data : { *(.data*) *(.sdata*) } . = ALIGN(4096); .bss : { *(.bss*) *(.sbss*) *(COMMON) } /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.comment) *(.note*) *(.eh_frame*) *(.got*) } }'
    (out/'link.ld').write_text(link)
    zig=ROOT/'tools/vendor/zig-windows-x86_64-0.13.0/zig.exe';assert sha(Path(str(zig.parent)+'.zip').read_bytes())==ZIG_SHA
    for dll,start,ords in groups:
        p=pefile.PE(str(ROOT/'extracted/705md-rom/fs/Windows'/dll.lower()));exports={s.ordinal for s in p.DIRECTORY_ENTRY_EXPORT.symbols}
        assert set(ords)<=exports
    cmd=[str(zig),'cc','-Xclang','-target-feature','-Xclang','+noabicalls','-target','mipsel-freestanding','-march=mips2','-mabi=32','-msoft-float','-mno-abicalls','-fno-pic','-G0','-ffreestanding','-fno-builtin','-fno-stack-protector','-fno-unwind-tables','-fno-asynchronous-unwind-tables','-fomit-frame-pointer','-fshort-wchar','-Os','-Wall','-Wextra','-Werror','-Wno-unused-function','-Wno-unused-variable','-c',str(out/source.name),'-o',str(out/'program.o')]
    subprocess.run(cmd,check=True,cwd=ROOT)
    subprocess.run(['wsl','-d','Ubuntu','--','mipsel-linux-gnu-ld','-T',wsl_path(out/'link.ld'),'--emit-relocs','-o',wsl_path(out/'program.elf'),wsl_path(out/'program.o')],check=True)
    raw,info=linked_to_pe((out/'program.elf').read_bytes(),(BASE/'payload/upgrade/Storage Card/System/UpgradeManager.exe').read_bytes(),groups)
    p=pefile.PE(data=raw);b=bytearray(raw);struct.pack_into('<I',b,p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),p.generate_checksum());raw=bytes(b)
    info.update(exe_sha256=sha(raw),exe_bytes=len(raw),source_sha256=sha(source.read_bytes()),physical_tested=False)
    (out/name).write_bytes(raw);write(out/'build.json',info)
    view=out/'fixture';view.mkdir();(view/'MAX56Repair.exe').write_bytes(raw);write(view/'build.json',info)
    return raw,info

def engine(stage,rows):
    out=stage/'engine';out.mkdir()
    identity=json.dumps(rows,sort_keys=True).encode()+(ROOT/'tools/install_resume33.c').read_bytes()+Path(__file__).read_bytes()
    package=b'MAXmade MAX33 application transaction 01 / '+sha(identity).encode()+b'\r\n'
    lines=['#define ITEM_COUNT '+str(len(rows)),'#define CHUNK_BYTES 262144',f'#define PACKAGE_BYTES {len(package)}',
           'static const B package_id[]='+cbytes(package)+';','static const B package_hash[32]='+cbytes(hashlib.sha256(package).digest())+';',
           'typedef struct {U bytes; B hash[32];} Block;','static const Item items[]={']
    blocks=[]
    for r in rows:
        p='\\'+r['path'].removeprefix('upgrade/').replace('/','\\');b=(stage/'payload'/r['path']).read_bytes()
        assert len(b)==r['after']['bytes'] and sha(b)==r['after']['sha256']
        action=2 if p in [r'\Storage Card\NK.bin',r'\firmware.hex',r'\Storage Card\Recovery.exe',r'\Storage Card\System\UpgradeManager.exe']else 1 if p==r'\Storage Card\System\Version_Info.txt'else 0
        first=len(blocks)
        for j in range(0,max(len(b),1),262144):v=b[j:j+262144];blocks.append((len(v),hashlib.sha256(v).digest()))
        lines.append('{'+','.join([cstr(p),str(len(b)),cbytes(hashlib.sha256(b).digest()),'3'if p.startswith('\\Storage Card4\\')else'0',str(action),str(first),str(len(blocks)-first)])+'},')
    lines+=['};','static const Block blocks[]={']+['{'+str(n)+','+cbytes(h)+'},'for n,h in blocks]+['};']
    parents={''}
    for r in rows+[{'path':'upgrade/Storage Card/InstallResume.exe'}]:
        p='\\'+r['path'].removeprefix('upgrade/').replace('/','\\')
        while '\\' in p:
            p=p.rsplit('\\',1)[0];parents.add(p)
    dirs=sorted(parents,key=lambda p:(-p.count('\\'),p))
    lines += [f'#define SOURCE_DIR_COUNT {len(dirs)}','static const W *source_dirs[]={'+','.join(cstr(p)for p in dirs)+'};']
    for name,path in [('NK','upgrade/Storage Card/NK.bin'),('UPDATER','upgrade/Storage Card/System/UpgradeManager.exe'),('RECOVERY','upgrade/Storage Card/Recovery.exe'),('VERSION','upgrade/Storage Card/System/Version_Info.txt')]:
        r=next(r['after']for r in rows if r['path']==path)
        lines += [f'#define {name}_BYTES {r["bytes"]}',f'static const B {name.lower()}_hash[32]='+cbytes(bytes.fromhex(r['sha256']))+';']
    lines += [f'#define COMPLETION_BYTES {len(COMPLETION)}','static const B completion_text[]='+cbytes(COMPLETION)+';','static const B completion_hash[32]='+cbytes(hashlib.sha256(COMPLETION).digest())+';']
    (out/'manifest.h').write_text('\n'.join(lines)+'\n')
    old=(ROOT/'tools/issue56_repair.c').read_bytes();assert sha(old)=='32359ebba0b3c9e86925a0d4e9a6408bd6c8cd50934410cbd85fdc81d05b1e52'
    common=old.decode().split('typedef struct {U size,usage,pid')[0]
    common=common.replace('DISPATCH, API_COUNT','DISPATCH, SEEK, OPENPROC, RPM, TERM, WAIT, CMDLINE, PROCESS, RMDIR, API_COUNT')
    common=common.replace('U volume; U action;','U volume; U action; U first; U count;')
    common=common.replace('MAX56','MAX33').replace('.max56-new','.max33-new').replace('MAX33-interrupted-upgrade','MAX33-retained-upgrade')
    common=common.replace('join(src,root,L"Payload")','join(src,root,L"")')
    common=common.replace('A detailed log is being saved on USB.','A detailed log is saved on internal Storage Card3.')
    common=common.replace('No CRT, registry, formatter, firmware flasher, reboot, or process-kill API.','No CRT, registry, formatter, firmware flasher or reboot API.\n * Only the pinned stopped application updater may be quiesced.')
    common=common.replace('2 = verify source only.','2 = never written by this worker (active boot files pinned separately).')
    (out/'common.h').write_text(common)
    groups=[('COREDLL.dll',0,CORE),('toolhelp.dll',len(CORE),[2,10,11,1]),('COREDLL.dll',len(CORE)+4,TAIL+EXTRA)]
    raw,info=compile_c(out,'InstallResume.exe',ROOT/'tools/install_resume33.c',groups)
    info.update(package_id=package.decode(),manifest_members=len(rows),block_count=len(blocks),manifest_sha256=sha((out/'manifest.h').read_bytes()))
    write(out/'build.json',info);write(out/'fixture/build.json',info)
    return raw,info

def build(out):
    assert not out.exists() and sha((BASE/'upgrade.lgu').read_bytes())==BASE_SHA
    prior={r['path']:r['after']for r in json.loads((BASE/'member-plan.json').read_bytes())['members']};tree(BASE/'payload',prior)
    out.mkdir(parents=True);shutil.copytree(BASE/'payload',out/'payload');expected=dict(prior)
    def publish(path,b):
        (out/'payload'/path).write_bytes(b);expected[path]=dict(bytes=len(b),sha256=sha(b))
    # Stable dependency order: Recovery menu and updater contain paths/protocol,
    # then the worker embeds those final hashes. Its own file is a bootstrap,
    # compared with retained source, outside its own compiled manifest.
    recovery,info=compile_c(out/'menu','Recovery.exe',ROOT/'tools/recovery33.c',[('COREDLL.dll',0,[858,493,553,166,165,516,555,556,1231])])
    publish('upgrade/Storage Card/Recovery.exe',recovery)
    old=json.loads((ROOT/'build/max30-quieter-logging-development-03/UpgradeManager.exe.json').read_bytes());assert old['output_sha256']==prior['upgrade/Storage Card/System/UpgradeManager.exe']['sha256']
    updater,recipe=patch_updater((BASE/'payload/upgrade/Storage Card/System/UpgradeManager.exe').read_bytes(),old)
    recipe['helper_rows']=old['helper_rows']+recipe['helper_rows'];recipe['routines']=old['routines']+recipe['routines'];recipe['boot_recovery']=old['boot_recovery'];recipe['recovery']=old['recovery']
    (out/'UpgradeManager.exe').write_bytes(updater);write(out/'UpgradeManager.exe.json',recipe);publish('upgrade/Storage Card/System/UpgradeManager.exe',updater)
    runtime=json.loads((BASE/'runtime.json').read_bytes());cmn=(BASE/'payload/upgrade/Storage Card/System/CmnDll.dll').read_bytes();p=pefile.PE(data=cmn)
    off=p.get_offset_from_rva(runtime['strings']['header']-p.OPTIONAL_HEADER.ImageBase)
    before='\ufeffMAXmade 7.0.6.MAX32 diagnostics'.encode('utf-16-le');after='\ufeffMAXmade 7.0.6.MAX33 diagnostics'.encode('utf-16-le')
    assert cmn[off:off+len(before)]==before
    b=bytearray(cmn);b[off:off+len(before)]=after;cs=p.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum');struct.pack_into('<I',b,cs,0);struct.pack_into('<I',b,cs,pefile.PE(data=bytes(b)).generate_checksum())
    publish('upgrade/Storage Card/System/CmnDll.dll',bytes(b));publish('upgrade/Storage Card/System/Version_Info.txt',REVISION.encode())
    runtime['measurements_revision']=33;write(out/'runtime.json',runtime)
    core_rows=[dict(path=k,after=v)for k,v in sorted(expected.items())]
    raw,info=engine(out,core_rows);publish('upgrade/Storage Card/InstallResume.exe',raw)
    tree(out/'payload',expected)
    changed=sorted(k for k in prior if prior[k]!=expected[k]);added=sorted(set(expected)-set(prior))
    assert len(changed)==4 and added==['upgrade/Storage Card/InstallResume.exe']
    write(out/'member-plan.json',dict(member_count=len(expected),prior_paths_retained=len(prior),retained_members=len(prior)-len(changed),changed_members=changed,added_members=added,missing_members=[],members=[dict(path=k,before=prior.get(k),after=v)for k,v in sorted(expected.items())]))
    write(out/'development.json',dict(revision=REVISION,baseline_lgu_sha256=BASE_SHA,full_previous_payload_retained=True,car_tested=False,
        healthy_settings_migration_preserved=True,application_transaction_integrated=True,ambiguous_settings_requires_explicit_repair=True,
        kernel_dboot_MCU_and_media_bytes_unchanged=True,legacy_first_stage_not_retroactively_protected=True))
    print(out,flush=True)

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);build(p.parse_args().output.resolve())
