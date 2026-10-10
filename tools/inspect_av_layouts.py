"""Recover radio/media/phone constructor geometry with explicit offline fixtures.

All external calls are enumerated from the bounded initializer and stubbed;
dynamic content/lists and later runtime layout changes are not simulated.
"""
import hashlib
import json
import sys
from pathlib import Path
import pefile
sys.path.insert(0,str(Path(__file__).parent/'python-libs'))
import capstone
from verify_ui_english import UiVM, strings
from inspect_home_layout import ROOT,SYSTEM,APP_SHA,OBJECT,STATUS,RES,MAIN,PHONE,STACK,STOP

CATALOG=json.loads((ROOT/'analysis/firmware/appmain-startup-contracts.json').read_text())['resources']
FUNCTIONS=json.loads((ROOT/'analysis/functions/705md/AppMain.exe.json').read_text())['functions']
SIZES={int(f['begin_va'],16):f['bytes'] for f in FUNCTIONS}
CS=capstone.Cs(capstone.CS_ARCH_MIPS,capstone.CS_MODE_MIPS32|capstone.CS_MODE_LITTLE_ENDIAN)
ENTRIES={
 'radio':[0x89128,0x8b1cc,0x8c8f8,0x8e2d8,0x908d8,0x93ecc,0x956d4,0x97a84,0x99f04,0x9c278,0x9efe4,0xa11dc,0xa4054,0xa79b8,0xaa42c],
 'media':[0x29388,0x2b8b0,0x3055c,0x33ee0,0x381b4,0x3b05c,0x3ca0c,0x3e820,0x421ec,0x441c8,0x47bc0,0x49374,0x4c26c,0x4ebd8],
 'phone':[0x55548,0x58670,0x5d870,0x62458,0x66abc,0x682b8,0x6aabc,
          0x6c51c,0x6ddf0,0x6f954,0x70f2c,0x724e8,0x74094,0x75dd0,
          0x77990,0x7918c,0x7aca8,0x7c8dc,0x7e33c,0x80218,0x81de8,
          0x84104,0x860dc,0x878c8],
}

class LayoutVM(UiVM):
    def __init__(self,pe,ranges):
        super().__init__(pe,ranges)
        self.stores={};self.zero_reads=set()
    def read(self,at,size=4):
        if all(at+i in self.mem for i in range(size)):
            return super().read(at,size)
        if 0 <= at-self.base < self.pe.OPTIONAL_HEADER.SizeOfImage:
            data=self.pe.get_data(at-self.base,size)
            if len(data)==size:return int.from_bytes(data,'little')
            section=self.pe.get_section_by_rva(at-self.base)
            assert section and section.VirtualAddress+section.SizeOfRawData<=at-self.base
            return 0  # PE loader zeroes the unbacked tail of a virtual section.
        # Explicit zeroed fixture allocations, not arbitrary address fallbacks.
        assert any(lo<=at and at+size<=hi for lo,hi in [
            (OBJECT,OBJECT+0x60000),(STATUS,STATUS+0x60000),(RES,RES+0x1000),(MAIN,MAIN+0x1000),
            (PHONE,PHONE+0x2000),(STACK-0x10000,STACK+0x100),
            (0x46000000,0x46040000),(0,0x1000)]),hex(at)
        self.zero_reads.add(at)
        return 0
    def plain(self,word):
        if word>>26==0 and word&63==3:
            rt,rd,shift=(word>>16)&31,(word>>11)&31,(word>>6)&31
            value=self.reg[rt];value=value if value<0x80000000 else value-0x100000000
            self.reg[rd]=(value>>shift)&0xffffffff
            self.reg[0]=0
            return
        if word>>26==43:
            rs,rt=(word>>21)&31,(word>>16)&31
            imm=word&65535;imm=imm if imm<32768 else imm-65536
            at=(self.reg[rs]+imm)&0xffffffff
            self.stores[at]=dict(pc=hex(self.pc),word=hex(word),value=self.reg[rt],
                white_registers=[i for i,v in enumerate(self.reg) if v==0xffffff],
                register_values=self.reg[:],
                old_register=rt,base_register=rs)
        super().plain(word)

def trace(entry,group,raw=None,ui=1,capture_state=False):
    raw=raw or (SYSTEM/'AppMain.exe').read_bytes()
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase
    vm=LayoutVM(pe,[(entry,entry+SIZES[entry])])
    vm.write(0x186538,RES);vm.write(RES+0x6d8,1)
    vm.write(0x187b38,STATUS)
    for at in (0x186ce8,0x187be4):vm.write(at,MAIN)
    vm.write(MAIN+0xa8,PHONE);vm.write(MAIN+0xa4,PHONE)
    records={};text_records={};language=strings(SYSTEM/'data/LangDllEng.dll')
    def words(at):
        return [v if v<0x80000000 else v-0x100000000 for v in [vm.read(at+i*4) for i in range(4)]]
    def text(at):
        if 0x50000000<=at<0x51000000:return language.get((at-0x50000000)//0x400,'')
        return vm.text(at) if at else ''
    def construct(m,kind='image',helper=False):
        _,obj,ident,area=m.reg[4:8]
        rect=words(area)
        assert all(abs(v)<10000 for v in rect),rect
        for i,v in enumerate(rect):m.write(obj+8+i*4,v&0xffffffff)
        m.write(obj+0x2c,0x183 if kind=='button' else 0x181)
        r=dict(object=hex(obj),object_offset=hex(obj-OBJECT),image_id=ident,
               rect=rect,kind=kind,embedded_text=kind=='button' and not helper,
               constructor=hex(m.pc-4),filename=CATALOG[ident]['filename'] if ident<len(CATALOG) else None)
        if helper and r['filename'] and r['filename'].lower().endswith('_btn.bmp'):
            r.update(kind='button',event=m.read(m.reg[29]+0x10),text='',font_index=0,
                     colors=None,label_rect=rect,text_flags=0,frame_count=4)
        elif kind=='button':
            args=[m.read(m.reg[29]+0x10+i*4) for i in range(9)]
            event,font,txt,txtarea,colors,flags=args[:6]
            rel=words(txtarea) if txtarea else [0,0,rect[2],rect[3]]
            label=[rect[0]+rel[0],rect[1]+rel[1],*rel[2:]]
            r.update(event=event,font_index=font,text=text(txt),label_rect=label,
                     colors=words(colors) if colors else None,colors_address=hex(colors),text_flags=flags,
                     color_stores=[m.stores.get(colors+i*4) for i in range(4)] if colors else [])
        else:r['frame_count']=m.read(m.reg[29]+0x10)
        records[obj]=r
        return 0
    pool=[0x46000000]
    def allocate(m):
        pool[0]+=0x1000;at=pool[0];m.write(at+4,1);m.write(at+0x20,1);m.write(at+0x38,1)
        return at
    def cache(m):
        at=allocate(m);m.write(m.reg[5],at);return at
    def set_text(m):
        obj=m.reg[4] if m.reg[4] in records else m.reg[4]-0x74
        value=text(m.reg[5])
        text_records.setdefault(m.reg[4],{})['text']=value
        if obj in records and (obj==m.reg[4] or records[obj].get('embedded_text')):records[obj]['text']=value
        return 0
    def set_font(m):
        text_records.setdefault(m.reg[4],{})['font_index']=m.reg[6]
        return 0
    def list_control(m):
        saved=list(m.reg[4:8]);_,obj,ident,area=saved
        construct(m)
        r=records[obj];args=[m.read(m.reg[29]+0x10+i*4) for i in range(12)]
        event,font,labelarea,colors=args[0],args[3],args[7],args[9]
        rel=words(labelarea) if labelarea else [0,0,r['rect'][2],r['rect'][3]]
        r.update(kind='list',embedded_text=True,event=event,font_index=font,text='',
            label_rect=[r['rect'][0]+rel[0],r['rect'][1]+rel[1],*rel[2:]],
            colors=words(colors) if colors else None,colors_address=hex(colors),text_flags=m.read(m.reg[29]+0x3c),
            color_stores=[m.stores.get(colors+i*4) for i in range(4)] if colors else [])
        area2,colors2=args[8],args[10]
        rel2=words(area2) if area2 else [0,0,r['rect'][2],r['rect'][3]]
        r['secondary_label']=dict(font_index=args[4],text=text(args[6]),
            label_rect=[r['rect'][0]+rel2[0],r['rect'][1]+rel2[1],*rel2[2:]],
            colors=words(colors2) if colors2 else None,colors_address=hex(colors2),
            text_flags=m.read(m.reg[29]+0x40),
            color_stores=[m.stores.get(colors2+i*4) for i in range(4)] if colors2 else [])
        return 0
    def variant_button(m):
        construct(m,helper=True)
        r=records[m.reg[5]]
        r.update(kind='button',event=m.read(m.reg[29]+0x10),frame_count=4,
                 variant_count=m.read(m.reg[29]+0x14),text='',colors=None)
        return 0
    def progress(m):
        construct(m)
        records[m.reg[5]].update(kind='progress',frame_count=2,event=1001)
        return 0
    def enlarge_progress_touch(m):
        obj=m.reg[4];r=records[obj];r['sprite_rect']=r['rect'][:]
        x,y,w,h=r['rect']
        for i,v in enumerate([x-15,y-15,w+30,h+40]):m.write(obj+8+i*4,v)
        return 0
    def virtual_image(m):
        obj,ident,area,parent=m.reg[4:8]
        if ident==area==0:
            return 0  # Explicit no-data fixture callback, no geometry evidence.
        if area in (0,1) and ident in (0,1):
            return 0  # No-data property fixture, not an image constructor.
        assert (ident<len(CATALOG) or ident==0xffffffff) and STACK-0x10000<=area<STACK, (hex(m.pc),hex(ident),hex(area))
        saved=m.reg[4:8]
        m.reg[4:8]=[parent,obj,ident,area]
        construct(m,helper=True)
        m.reg[4:8]=saved
        return 0
    instructions=list(CS.disasm(pe.get_data(entry-base,SIZES[entry]),entry))
    calls=sorted({int(i.op_str,16) for i in instructions if i.mnemonic=='jal'})
    vm.hooks={at:(lambda m:0) for at in calls}
    vm.hooks.update({0x137a68:lambda m:ui,0x13ff38:cache,0x13dde0:lambda m:1,
        0x14638:lambda m:1,0x1402f0:allocate,0x1f8e0:lambda m:1,
        0x1fa44:lambda m:0x50000000+m.reg[5]*0x400,
        0x13d488:lambda m:construct(m,'button'),0x13d2ec:construct,
        0x135d30:lambda m:construct(m,helper=True),0x139668:set_text,
        0x135e90:variant_button,0x135f30:progress,0x13f7f8:enlarge_progress_touch,
        0x139528:set_font,0x13d958:list_control,0:virtual_image})
    vm.reg[4],vm.reg[29],vm.reg[31]=OBJECT,STACK,STOP
    creators=[i.address for i in instructions if i.mnemonic=='jal' and int(i.op_str,16) in (0x13d488,0x13d2ec,0x135d30,0x13d958,0x135e90,0x135f30)]
    snapshot_stop=max(creators)+8
    # Finish loops containing the last constructor; stopping immediately after
    # its first invocation would silently omit the remaining preset tiles.
    backwards=[i.address+8 for i in instructions if i.address>=snapshot_stop and
               i.mnemonic.startswith('b') and i.op_str.split(',')[-1].strip().startswith('0x') and
               int(i.op_str.split(',')[-1].strip(),16)<=max(creators)]
    if backwards:snapshot_stop=max(snapshot_stop,max(backwards))
    vm.run(entry,{snapshot_stop},limit=18000)
    result=list(records.values())
    for r in result:
        r['rect']=words(int(r['object'],16)+8)
        r['flags']=vm.read(int(r['object'],16)+0x2c)
        addresses=[int(r['object'],16)]
        if r.get('embedded_text'):addresses.append(int(r['object'],16)+0x74)
        for at in addresses:
            if at in text_records:r.update(text_records[at])
    result=dict(entry=hex(entry),snapshot_stop=hex(snapshot_stop),group=group,ui_type=ui,controls=result,
                fixture_calls=[hex(c) for c in calls],zero_fixture_reads=len(vm.zero_reads),
                native_execution=False)
    if capture_state:result['machine_state']={'registers':vm.reg[:],'memory':vm.mem.copy()}
    return result

def main():
    raw=(SYSTEM/'AppMain.exe').read_bytes();assert hashlib.sha256(raw).hexdigest()==APP_SHA
    cases=[];failures=[]
    for group,entries in ENTRIES.items():
        for entry in entries:
            try:
                case=trace(entry,group);cases.append(case)
                print(group,hex(entry),len(case['controls']),flush=True)
            except Exception as e:
                failures.append(dict(group=group,entry=hex(entry),error=str(e)))
                print('FAILED',group,hex(entry),str(e),flush=True)
    out=ROOT/'analysis/firmware/av-layouts.json'
    out.write_text(json.dumps(dict(app_sha256=APP_SHA,scenarios=cases,failures=failures,
        limitations=['Constructor snapshots with explicit external-call fixtures',
            'Runtime visibility, list data, later relayout and native font metrics not simulated']),indent=2)+'\n',encoding='utf-8')
    print('Mapped',len(cases),'failed',len(failures))

if __name__=='__main__':main()
