"""Inventory the complete AppMain catalog and shared active foreground routes."""
import bisect
import json
import struct
from patch_selected_label_contrast import ROOT, RELEASE, APP, resources, sha
import pefile

def audit(raw):
    p=pefile.PE(data=raw);base=p.OPTIONAL_HEADER.ImageBase
    directory=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    pdata=p.get_data(directory.VirtualAddress,directory.Size)
    rows=[struct.unpack_from('<5I',pdata,i) for i in range(0,len(pdata),20)]
    starts=[r[0] for r in rows]
    def owner(pc):
        row=rows[bisect.bisect_right(starts,pc)-1]
        return hex(row[0]) if row[0]<=pc<row[1] else None
    targets={0x13ecec:[],0x13f258:[],0x13f378:[]};stores=[]
    s=p.sections[0]
    for off in range(0,s.Misc_VirtualSize,4):
        pc=base+s.VirtualAddress+off;word=struct.unpack_from('<I',raw,s.PointerToRawData+off)[0]
        op=word>>26
        if op==3:
            target=((pc+4)&0xf0000000)|((word&0x3ffffff)<<2)
            if target in targets:targets[target].append(dict(va=hex(pc),function=owner(pc)))
        if op==43 and (word>>16)&31==0 and word&65535 in (0x550,0x558,0x560,0x568,0x830,0x838):
            stores.append(dict(va=hex(pc),function=owner(pc),offset=hex(word&65535)))
    # Catalog every read-only vtable that uses the text/list state painter.
    vtables=[]
    r=p.sections[1]
    for off in range(0,r.Misc_VirtualSize-4,4):
        value=struct.unpack_from('<I',raw,r.PointerToRawData+off)[0]
        if value in targets:
            at=base+r.VirtualAddress+off-0x34
            previous=struct.unpack_from('<15I',raw,r.PointerToRawData+off-0x34)
            if previous[7]==0x13e444:vtables.append(dict(vtable=hex(at),painter=hex(value)))
    catalog,ids=resources()
    members=json.loads((RELEASE/'staging-manifest.json').read_text())['members']
    resources_audit=[]
    for row in catalog:
        path='upgrade/Storage Card/System/Img/M1/'+row['filename'].replace('\\','/')
        # Native catalog is case-insensitive; actual release member case persists.
        actual=next((n for n in members if n.lower()==path.lower()),None)
        resources_audit.append(dict(id=row['id'],filename=row['filename'],present=actual is not None,
            dark_active_label_correction=row['id'] in ids,
            family=row['filename'].split('\\')[0],sha256=members[actual]['sha256'] if actual else None))
    assert targets[0x13ecec] and any(r['function']=='0x13f258' for r in targets[0x13ecec])
    assert any(r['function']=='0x13f378' for r in targets[0x13f258])
    assert {v['painter'] for v in vtables}=={'0x13ecec','0x13f258','0x13f378'}
    return dict(input_sha256=sha(raw),direct_callers={hex(k):v for k,v in targets.items()},
        text_painter_vtables=vtables,direct_black_state_store_inventory=stores,
        catalog=resources_audit,independent_gui_modules_unchanged=['nngnavi.exe','UpgradeManager.exe','DBoot'],
        scope='Shared AppMain controls, including Home, Radio, Media, Phone, Settings and popups; separate GUIs retain baseline bytes',
        native_execution=False,hardware_tested=False)

if __name__=='__main__':
    result=audit((RELEASE/'payload'/APP).read_bytes())
    (ROOT/'analysis/firmware/selected-label-path-audit.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k not in ('catalog','direct_black_state_store_inventory')},indent=2))
    print('Catalog',len(result['catalog']),'direct black state stores',len(result['direct_black_state_store_inventory']))
