"""Compile a freestanding CE/MIPS application repair kit from the full MAX28.

Zig's pinned clang emits ELF; GNU MIPS ld resolves it with retained relocations.
The small converter below emits PE32/MIPS with standard HIGHADJ/LOW/JMPADDR/
HIGHLOW fixups. It does not run the application or any supplied firmware.
"""
import argparse, hashlib, io, json, shutil, struct, subprocess, zipfile
from pathlib import Path, PurePosixPath
import pefile
from elftools.elf.elffile import ELFFile

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max28-installer-recovery-development-03'
PIN='07dbebeba1dee814ab02b1d28d359285a14a2c1a72342a89a8685bbd52554f2d'
PLAN_PIN='14542a88c3b364d5e48194aea1b8ee2b445a9533b8d7385bb013a6392d41a9e5'
NK='8b2bd9944565f2b9ec2af6e2e1f0aa8620db9456c4b36329a140f70835db6de1'
RESCUE='3bfafaa6d17216481c6ac30dbd847c07d75537d2d8e32b9a4e3639acf82c7a65'
OLD_UPDATER='22ebd96233a121935ac985ae7b667ed8a2f11cc8a47757c3d3ea25753fb06e73'
ZIG_SHA='d859994725ef9402381e557c60bb57497215682e355204d754ee3df75ee3c158'
CORE=[168,170,171,553,172,166,160,165,163,175,537,516,184,858,555,556,535]
TAIL=[246,256,267,265,864,870,859]
ORDINALS=CORE+[2,10,11,1]+TAIL
BASE_ADDRESS=0x10000

def sha(b):return hashlib.sha256(b).hexdigest()
def align(x,n=4096):return (x+n-1)&-n
def cstr(s):return 'L'+json.dumps(s)
def cbytes(b):return '{'+','.join(str(x)for x in b)+'}'
def manifest(rows,out):
    package=b'MAXmade issue56 application repair 01 / '+PIN.encode()+b'\r\n'
    text=['#define ITEM_COUNT '+str(len(rows)), '#define PACKAGE_BYTES '+str(len(package)),
          'static const unsigned char package_id[]='+cbytes(package)+';',
          'static const unsigned char package_hash[32]='+cbytes(bytes.fromhex(sha(package)))+';',
          'static const Item items[]={']
    for r in rows:
        path='\\'+r['path'].removeprefix('upgrade/').replace('/','\\')
        action=2 if path in [r'\Storage Card\NK.bin',r'\firmware.hex'] else 1 if path==r'\Storage Card\System\Version_Info.txt' else 0
        vol=3 if path.startswith('\\Storage Card4\\')else 0
        text.append('{'+f'{cstr(path)},{r["after"]["bytes"]},{cbytes(bytes.fromhex(r["after"]["sha256"]))},{vol},{action}'+'},')
    text+=['};',f'#define NK_BYTES 16775587', 'static const unsigned char nk_hash[32]='+cbytes(bytes.fromhex(NK))+';']
    upgrade=next(r for r in rows if r['path'].endswith('/System/UpgradeManager.exe'))
    text+=['#define UPDATER_COUNT 2','static const unsigned updater_sizes[]={197120,'+str(upgrade['after']['bytes'])+'};',
           'static const unsigned char updater_hashes[2][32]={'+cbytes(bytes.fromhex(OLD_UPDATER))+','+cbytes(bytes.fromhex(upgrade['after']['sha256']))+'};']
    (out/'manifest.h').write_text('\n'.join(text)+'\n')

def linked_to_pe(raw, template, api_groups=None):
    e=ELFFile(io.BytesIO(raw)); assert e.little_endian and e.elfclass==32 and e['e_machine']=='EM_MIPS'
    syms=e.get_section_by_name('.symtab'); symbols={s.name:int(s['st_value'])for s in syms.iter_symbols()if s.name}
    sections=[]
    for name,flags in [('.text',0x60000020),('.rdata',0x40000040),('.data',0xc0000040),('.bss',0xc0000040)]:
        s=e.get_section_by_name(name)
        if s and s['sh_size']:
            sections.append([name,int(s['sh_addr']),bytearray(s.data()),flags])
    assert sections[0][1]==0x11000
    records=[]
    for sec in e.iter_sections():
        if sec['sh_type']!='SHT_REL':continue
        target=e.get_section(sec['sh_info'])
        if not target['sh_flags']&2:continue
        pending={}
        for r in sec.iter_relocations():
            at=int(r['r_offset']); kind=int(r['r_info_type']);symbol=int(r['r_info_sym'])
            s=next(s for s in sections if s[1]<=at<s[1]+len(s[2]))
            word=struct.unpack_from('<I',s[2],at-s[1])[0]
            if kind==5:pending.setdefault(symbol,[]).append(at)
            elif kind==6:
                records.append((at-BASE_ADDRESS,2,None))
                for h in pending.pop(symbol,[]):records.append((h-BASE_ADDRESS,4,word&65535))
            elif kind==4:records.append((at-BASE_ADDRESS,5,None))
            elif kind==2:records.append((at-BASE_ADDRESS,3,None))
            elif kind!=0:raise ValueError(('unsupported ELF relocation',kind,hex(at)))
        assert not pending,pending
    # A single writable IAT, in enum order, is populated by three descriptors.
    at=align(max(a+len(b)for _,a,b,_ in sections));idata=bytearray(4096)
    cursor=80;descs=[]
    groups=api_groups or [('COREDLL.dll',0,CORE),('toolhelp.dll',len(CORE),[2,10,11,1]),('COREDLL.dll',len(CORE)+4,TAIL)]
    assert len(groups)<=3
    for dll,first,ords in groups:
        lookup=at+cursor;v=struct.pack('<'+'I'*(len(ords)+1),*[0x80000000|o for o in ords],0);idata[cursor:cursor+len(v)]=v;cursor+=len(v)
        name=at+cursor;v=dll.encode()+b'\0';idata[cursor:cursor+len(v)]=v;cursor=align(cursor+len(v),4)
        descs.append(struct.pack('<5I',lookup-BASE_ADDRESS,0,0,name-BASE_ADDRESS,symbols['imports']+first*4-BASE_ADDRESS))
    idata[:20*len(descs)]=b''.join(descs);sections.append(['.idata',at,idata[:align(cursor,512)],0xc0000040]);import_va=at-BASE_ADDRESS
    # Standard MIPS RUNTIME_FUNCTION records, with clang's simple o32 prologues.
    functions=[];pdata=bytearray()
    text=sections[0]
    for s in syms.iter_symbols():
        if s['st_info']['type']!='STT_FUNC' or not s['st_size']:continue
        start=int(s['st_value']);end=start+int(s['st_size']);prolog=start
        w=struct.unpack_from('<I',text[2],start-text[1])[0]
        if w>>16==0x27bd:
            prolog+=4
            while prolog<end:
                w=struct.unpack_from('<I',text[2],prolog-text[1])[0]
                if w>>26!=43 or (w>>21)&31!=29:break
                prolog+=4
        functions.append((start,end,0,0,prolog))
    pdata_at=align(at+len(sections[-1][2]));functions.sort()
    for j,row in enumerate(functions):
        pdata.extend(struct.pack('<5I',*row))
        for k,v in enumerate(row):
            if v:records.append((pdata_at-BASE_ADDRESS+j*20+k*4,3,None))
    sections.append(['.pdata',pdata_at,pdata,0x40000040])
    pages={}
    for addr,kind,extra in sorted(records):
        vals=pages.setdefault(addr&~4095,[]);vals.append((kind<<12)|(addr&4095))
        if kind==4:vals.append(extra)
    reloc=bytearray()
    for page,vals in sorted(pages.items()):
        if len(vals)%2:vals.append(0)
        reloc.extend(struct.pack('<II',page,8+2*len(vals))+struct.pack('<'+'H'*len(vals),*vals))
    reloc_at=align(pdata_at+len(pdata));sections.append(['.reloc',reloc_at,reloc,0x42000040])
    p=pefile.PE(data=template);h=bytearray(template[:p.OPTIONAL_HEADER.get_file_offset()+224]);h[0x40:p.DOS_HEADER.e_lfanew]=bytes(p.DOS_HEADER.e_lfanew-0x40)
    fh=p.FILE_HEADER;oh=p.OPTIONAL_HEADER
    def field(obj,key,fmt,value):struct.pack_into(fmt,h,obj.get_field_absolute_offset(key),value)
    field(fh,'NumberOfSections','<H',len(sections));field(fh,'TimeDateStamp','<I',0);field(fh,'Characteristics','<H',0x102)
    field(fh,'PointerToSymbolTable','<I',0);field(fh,'NumberOfSymbols','<I',0)
    vals={'SizeOfCode':align(len(sections[0][2]),512),'SizeOfInitializedData':sum(align(len(x[2]),512)for x in sections[1:]),
          'SizeOfUninitializedData':0,'AddressOfEntryPoint':symbols['entry']-BASE_ADDRESS,'BaseOfCode':0x1000,
          'BaseOfData':sections[1][1]-BASE_ADDRESS,'ImageBase':BASE_ADDRESS,'SectionAlignment':4096,'FileAlignment':512,
          'SizeOfImage':align(reloc_at+len(reloc))-BASE_ADDRESS,'SizeOfHeaders':1024,'CheckSum':0,
          'SizeOfStackReserve':0x10000,'SizeOfStackCommit':0x1000,'SizeOfHeapReserve':0x10000,'SizeOfHeapCommit':0x1000}
    for k,v in vals.items():field(oh,k,'<I',v)
    field(oh,'Subsystem','<H',9);field(oh,'DllCharacteristics','<H',0)
    for d in oh.DATA_DIRECTORY:struct.pack_into('<II',h,d.get_file_offset(),0,0)
    for n,va,size in [(1,import_va,80),(3,pdata_at-BASE_ADDRESS,len(pdata)),(5,reloc_at-BASE_ADDRESS,len(reloc))]:struct.pack_into('<II',h,oh.DATA_DIRECTORY[n].get_file_offset(),va,size)
    off=1024;headers=bytearray()
    for name,addr,value,flags in sections:
        size=align(len(value),512);headers.extend(struct.pack('<8s8I',name.encode(),len(value),addr-BASE_ADDRESS,size,off,0,0,0,flags));off+=size
    h.extend(headers);assert len(h)<=1024;h.extend(bytes(1024-len(h)))
    for _,_,value,_ in sections:h.extend(value);h.extend(bytes(align(len(h),512)-len(h)))
    out=bytes(h);p=pefile.PE(data=out)
    assert p.FILE_HEADER.Machine==0x166 and p.OPTIONAL_HEADER.Subsystem==9
    imported=[i.ordinal for d in p.DIRECTORY_ENTRY_IMPORT for i in d.imports];assert imported==[o for dll,start,ords in groups for o in ords],imported
    assert len(set(a for a,k,c in records))==len(records)
    return out,dict(symbols={k:v for k,v in symbols.items()if not k.startswith('$')},relocations=len(records),functions=len(functions),section_count=len(sections))

def wsl_path(p):
    p=str(p.resolve()).replace('\\','/');return '/mnt/'+p[0].lower()+p[2:]

def build(out):
    out.mkdir(exist_ok=False,parents=True)
    assert sha((BASE/'upgrade.lgu').read_bytes())==PIN
    plan=(BASE/'member-plan.json').read_bytes();assert sha(plan)==PLAN_PIN
    rows=json.loads(plan)['members'];assert len(rows)==1919
    assert {p.relative_to(BASE/'payload').as_posix()for p in (BASE/'payload').rglob('*')if p.is_file()}=={r['path']for r in rows}
    seen=set()
    for r in rows:
        path=PurePosixPath(r['path']);assert not path.is_absolute() and '..'not in path.parts and r['path'].startswith('upgrade/')
        assert r['path']=='upgrade/firmware.hex' or r['path'].startswith(('upgrade/Storage Card/','upgrade/Storage Card4/'))
        assert r['path'].lower()not in seen;seen.add(r['path'].lower())
        raw=(BASE/'payload'/r['path']).read_bytes();assert len(raw)==r['after']['bytes'] and sha(raw)==r['after']['sha256']
        assert len('\\'+r['path'].removeprefix('upgrade/').replace('/','\\'))+len('.max56-new')<260
    # Cross-check every imported ordinal against the actual reference ROM DLLs.
    for filename,ords in [('coredll.dll',CORE+TAIL),('toolhelp.dll',[2,10,11,1])]:
        p=pefile.PE(str(ROOT/'extracted/705md-rom/fs/Windows'/filename));exports={s.ordinal:s.name.decode()for s in p.DIRECTORY_ENTRY_EXPORT.symbols if s.name}
        names=(['CreateFileW','ReadFile','WriteFile','CloseHandle','GetFileSize','GetFileAttributesW','CreateDirectoryW','DeleteFileW','MoveFileW','FlushFileBuffers','GetModuleFileNameW','GetLastError','GetDiskFreeSpaceExW','MessageBoxW','CreateMutexW','ReleaseMutex','GetTickCount','CreateWindowExW','SetWindowTextW','UpdateWindow','DestroyWindow','PeekMessageW','TranslateMessage','DispatchMessageW'] if filename=='coredll.dll' else ['CreateToolhelp32Snapshot','Process32First','Process32Next','CloseToolhelp32Snapshot'])
        assert [exports[o]for o in ords]==names
        (out/(filename+'-imports.json')).write_text(json.dumps({o:exports[o]for o in ords},indent=2)+'\n')
    manifest(rows,out);shutil.copyfile(ROOT/'tools/issue56_repair.c',out/'issue56_repair.c')
    linker='ENTRY(entry)\nSECTIONS { . = 0x11000; .text : { *(.text*) } . = ALIGN(4096); .rdata : { *(.rodata*) } . = ALIGN(4096); .data : { *(.data*) *(.sdata*) } . = ALIGN(4096); .bss : { *(.bss*) *(.sbss*) *(COMMON) } /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.comment) *(.note*) *(.eh_frame*) *(.got*) } }'
    (out/'link.ld').write_text(linker)
    zig=ROOT/'tools/vendor/zig-windows-x86_64-0.13.0/zig.exe';assert sha(Path(str(zig.parent)+'.zip').read_bytes())==ZIG_SHA
    cmd=[str(zig),'cc','-target','mipsel-freestanding','-march=mips2','-mabi=32','-msoft-float','-mno-abicalls','-fno-pic','-G0','-ffreestanding','-fno-builtin','-fno-stack-protector','-fno-unwind-tables','-fno-asynchronous-unwind-tables','-fomit-frame-pointer','-fshort-wchar','-Os','-Wall','-Wextra','-Werror','-Wno-unused-variable','-c',str(out/'issue56_repair.c'),'-o',str(out/'repair.o')]
    # Zig 0.13 appends a target feature which cancels the driver noabicalls flag.
    # Set the clang feature last; no GP-relative accesses are accepted downstream.
    cmd[2:2]=['-Xclang','-target-feature','-Xclang','+noabicalls']
    subprocess.run(cmd,check=True,cwd=ROOT)
    subprocess.run(['wsl','-d','Ubuntu','--','mipsel-linux-gnu-ld','-T',wsl_path(out/'link.ld'),'--emit-relocs','-o',wsl_path(out/'repair.elf'),wsl_path(out/'repair.o')],check=True)
    raw,info=linked_to_pe((out/'repair.elf').read_bytes(),(BASE/'UpgradeManager.exe').read_bytes())
    (out/'MAX56Repair.exe').write_bytes(raw)
    info.update(exe_sha256=sha(raw),exe_bytes=len(raw),payload_lgu_sha256=PIN,member_count=len(rows),
                payload_bytes=sum(r['after']['bytes']for r in rows),source_sha256=sha((out/'issue56_repair.c').read_bytes()),
                physical_tested=False,compiler_archive_sha256=ZIG_SHA)
    (out/'build.json').write_text(json.dumps(info,indent=2)+'\n')
    return info

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();info=build(a.output.resolve());print(json.dumps({k:v for k,v in info.items()if k!='symbols'},indent=2))
