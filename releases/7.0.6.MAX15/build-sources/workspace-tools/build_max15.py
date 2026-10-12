"""Full MAX14 successor correcting the CE artwork-worker priority contract.

Only AppMain and Version_Info change. No CE module is executed on the PC.
"""
import json
import shutil
import struct
import build_max14 as old
from build_max14 import ROOT, REPO, BASE, APP, SYSTEM, sha, assemble, pefile, layout
from patch_shared_mapping_checks import reloc_records
from patch_bt_cover_install import relocation_table

BASELINE=REPO/'build/maxmade-7.0.6.MAX14-light-player-local-01'
OUT=ROOT/'build/max15-development-02'
APP_SHA='eec6afb447689c0f2ab70b6a4deef1bbcc8595f3d4e7cfaca095f3182a6001ed'
BASE_LGU_SHA='f69662a533616db4fac33c59c7f51475e2fbf7300d0db65b12e0c399a2042002'
STATE,STAGE,STRINGS,DIAGNOSTIC,RECOVER=old.STATE,old.STAGE,old.STRINGS,old.DIAGNOSTIC,old.RECOVER
FAIL=0x3000a4
CE_BELOW_NORMAL=4
CAPTIONS=old.CAPTIONS+['Startup blocked (S3)','Timer failed (S4)',
                     'Priority failed (S5)','Resume failed (S6)']

def start_source():
    row=layout.rewrite('AppMain.exe',next(r for r in layout.originals('AppMain.exe') if r['address']==0x238000))
    source=row['recipe']['source_assembly']
    assert source.count('addiu a1, zero, -1')==1
    source=source.replace('addiu a1, zero, -1',f'addiu a1, zero, {CE_BELOW_NORMAL}')
    # Store a last-startup result in previously unused RW padding. Successful
    # startup clears it; failures retain their stage after STOP/REAP cleanup.
    def marker(value):return f'la t0, {hex(FAIL)}\naddiu t1, zero, {value}\nsw t1, 0(t0)'
    source=source.replace('move s2, a1\n',f'move s2, a1\n{marker(1)}\n',1)
    source=source.replace('move a0, s1\nori a1, zero, 19778',f'{marker(2)}\nmove a0, s1\nori a1, zero, 19778',1)
    assert marker(2) in source
    source=source.replace('addiu s3, s3, 1',f'{marker(1)}\naddiu s3, s3, 1',1)
    source=source.replace('move a0, v0\naddiu a1, zero, 4',f'{marker(3)}\nmove a0, v0\naddiu a1, zero, 4',1)
    source=source.replace('sw t0, 68(s0)\n',f'sw t0, 68(s0)\n{marker(4)}\n',1)
    source=source.replace('addiu v0, zero, 1\nb done',f'{marker(0)}\naddiu v0, zero, 1\nb done')
    return source

def diagnostic_source():
    source=old.diagnostic_source().replace('beqz t1, chosen\nnop\naddiu s4, zero, 2',
        'beqz t1, startup_status\nnop\naddiu s4, zero, 2',1)
    return source.replace('chosen:\n',f'''b chosen
nop
startup_status:
la t0, {hex(FAIL)}
lw t1, 0(t0)
beqz t1, chosen
nop
sltiu t2, t1, 5
beqz t2, chosen
nop
addiu s4, t1, 11
chosen:
''',1)

def patch(raw):
    assert sha(raw)==APP_SHA
    pe=pefile.PE(data=raw);out=bytearray(raw);edits=[];routines=[];ranges=[];newrel=[]
    prior=json.loads((ROOT/'build/max14-development-02/recipe.json').read_bytes())
    original_start=layout.rewrite('AppMain.exe',next(r for r in layout.originals('AppMain.exe') if r['address']==0x238000))
    assert pe.get_data(0x238000-BASE,0x1000)==original_start['raw']
    refresh=next(r for r in prior['routines'] if r['address']==0x236000)['recipe']['source_assembly']
    refresh=refresh.replace(f'la t0, {hex(STATE)}\nlw t2, 16(t0)',f'''la t0, {hex(FAIL)}
lw t2, 0(t0)
sll t2, t2, 20
or t1, t1, t2
la t0, {hex(STATE)}
lw t2, 16(t0)''',1)
    assert f'la t0, {hex(FAIL)}' in refresh
    for va,capacity,source,name in ((0x238000,0x1000,start_source(),'CE priority and precise startup outcomes'),
        (DIAGNOSTIC,0x500,diagnostic_source(),'Distinguish unattempted and failed startup'),
        (0x236000,0x800,refresh,'Include startup outcome in status refresh')):
        encoded,recipe,rel=assemble(source,va,capacity)
        # COLORREF operands are scalars, never relocated image pointers.
        pc=va;excluded=set()
        for line in recipe['source_assembly'].splitlines():
            line=line.split('#',1)[0].strip()
            if not line or line.endswith(':'):continue
            if line.startswith('la '):
                if int(line.rsplit(',',1)[1],0) in (0x687c88,0x2d261c):excluded.update((pc-BASE,pc-BASE+4))
                pc+=8
            else:pc+=4
        rel=[r for r in rel if r[0] not in excluded]
        at=pe.get_offset_from_rva(va-BASE)
        edits.append(dict(offset=at,before_hex=raw[at:at+capacity].hex(),after_hex=encoded.hex(),reason=name))
        out[at:at+capacity]=encoded;ranges.append((va-BASE,va-BASE+capacity));newrel+=rel
        routines.append(dict(address=va,capacity=capacity,recipe=recipe,relocations=rel,name=name))
    strings=b''.join((s+'\0').encode('utf-16-le').ljust(64,b'\0') for s in CAPTIONS)
    assert len(strings)==0x400 and pe.get_data(FAIL-BASE,4)==bytes(4)
    at=pe.get_offset_from_rva(STRINGS-BASE)
    edits.append(dict(offset=at,before_hex=raw[at:at+0x400].hex(),after_hex=strings.hex(),reason='Additional startup failure captions'))
    out[at:at+0x400]=strings
    pd,rd=(pe.OPTIONAL_HEADER.DATA_DIRECTORY[n] for n in (3,5))
    rows=list(struct.iter_unpack('<5I',pe.get_data(pd.VirtualAddress,pd.Size)))
    for routine in routines:
        va=routine['address'];index=next(i for i,r in enumerate(rows) if r[0]==va)
        prolog=layout.prolog_end(dict(address=va,recipe=routine['recipe'],raw=pefile.PE(data=bytes(out)).get_data(va-BASE,routine['capacity'])))
        rows[index]=(va,va+routine['recipe']['used_bytes'],0,0,prolog)
    records=[r for r in reloc_records(pe) if not pd.VirtualAddress<=r[0]<pd.VirtualAddress+pd.Size and not any(a<=r[0]<b for a,b in ranges)]
    records+=newrel
    for i,row in enumerate(rows):
        for j,value in enumerate(row):
            if value:records.append((pd.VirtualAddress+i*20+j*4,3,None))
    pdata=b''.join(struct.pack('<5I',*r) for r in rows);reloc=relocation_table(records)
    sec=pe.sections[-1];start=sec.PointerToRawData;at=pe.get_offset_from_rva(pd.VirtualAddress)
    tail=pdata+reloc;newsize=(at-start+len(tail)+511)&~511
    assert len(raw)==start+sec.SizeOfRawData
    out[at:]=tail+bytes(start+newsize-at-len(tail))
    for directory,value,size in ((pd,pd.VirtualAddress,len(pdata)),(rd,pd.VirtualAddress+len(pdata),len(reloc))):
        struct.pack_into('<II',out,directory.get_file_offset(),value,size)
    vs=at-start+len(tail)
    for offset,value in ((sec.get_field_absolute_offset('Misc_VirtualSize'),vs),
        (sec.get_field_absolute_offset('SizeOfRawData'),newsize),
        (pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfImage'),(sec.VirtualAddress+vs+4095)&~4095),
        (pe.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfCode'),pe.OPTIONAL_HEADER.SizeOfCode+newsize-sec.SizeOfRawData)):
        struct.pack_into('<I',out,offset,value)
    at=pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum');struct.pack_into('<I',out,at,0)
    struct.pack_into('<I',out,at,pefile.PE(data=bytes(out)).generate_checksum())
    final=bytes(out)
    # Include unchanged helpers as fixture metadata, without marking them edited.
    combined=[r for r in prior['routines'] if r['address'] not in {x['address'] for x in routines}]+routines
    return final,dict(input_sha256=sha(raw),sha256=sha(final),edits=edits,routines=combined,
        changed_routines=routines,helpers=prior['helpers'],lookup_va=prior['lookup_va'],light_lookup_va=prior['light_lookup_va'],
        captions=CAPTIONS,startup_result_va=FAIL,native_executed=False,hardware_tested=False)

def build():
    assert not OUT.exists()
    assert sha((BASELINE/'upgrade.lgu').read_bytes())==BASE_LGU_SHA
    shutil.copytree(BASELINE/'payload',OUT/'payload')
    raw,recipe=patch((BASELINE/'payload'/APP).read_bytes())
    (OUT/'payload'/APP).write_bytes(raw)
    (OUT/'recipe.json').write_text(json.dumps(recipe,indent=2)+'\n')
    print(json.dumps(dict(app_sha256=sha(raw),routines=[(hex(r['address']),r['recipe']['used_bytes']) for r in recipe['changed_routines']]),indent=2))

if __name__=='__main__':build()
