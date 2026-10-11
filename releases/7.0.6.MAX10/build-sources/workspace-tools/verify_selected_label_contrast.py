"""Execute written MIPS painter bytes with explicit memory/GDI fixtures.

Includes the original radio refresh color stores, all catalog IDs/profiles/states,
secondary label paths, nonblack semantic colors, layout offsets and relocations.
This is an offline interpreter, not CE/native/device validation.
"""
import json
import struct
from pathlib import Path
import pefile
from patch_selected_label_contrast import ROOT, RELEASE, APP, HOOKS, patch, resources, sha
from verify_media_responsiveness import VM as BoundedVM, call, STACK
from inspect_bt_pairing import put
from inspect_wave_queue import STOP
from verify_usb_input_safety import relocated

BUTTON, RES, TABLE, DRAW = 0x41000000, 0x42000000, 0x43000000, 0xf0000010

class VM(BoundedVM):
    def __init__(self,pe,ranges):
        super().__init__(pe,ranges)
        self.words={}
    def word(self,pc):
        assert any(lo<=pc<hi for lo,hi in self.ranges),hex(pc)
        if pc not in self.words:self.words[pc]=super().word(pc)
        return self.words[pc]

def setup(pe, recipe=None, delta=0):
    ranges=[(0x13ecec+delta,0x13ee10+delta),(0x13f258+delta,0x13f35c+delta)]
    if recipe:ranges += [(a+delta,a+0x200+delta) for a in recipe['helpers']]
    m=VM(pe,ranges)
    put(m,BUTTON,bytes(0x900));put(m,RES,bytes(0x700));put(m,TABLE,bytes(0x40))
    for off in (0x74,0x570):m.write(BUTTON+off,TABLE)
    m.write(TABLE+0x1c,DRAW)
    m.write(0x186538+delta,RES)
    m.write(RES+0x6d8,1)
    for base,values in [(0x53c,[23,46,90,50]),(0x81c,[143,16,30,20])]:
        for i,value in enumerate(values):m.write(BUTTON+base+4*i,value)
    events=[]
    m.hooks[0x13e7ec+delta]=lambda m:events.append(('sprite',m.reg[4],m.reg[5])) or 0
    def draw(m):
        obj=m.reg[4]
        events.append(('text',obj,m.read(obj+0x60),[m.read(obj+8+i*4) for i in range(4)],m.read(BUTTON+0x320)))
        return 1
    m.hooks[DRAW]=draw
    return m,events

def colors(m,values):
    for base in (0x54c,0x55c,0x82c):
        for i,value in enumerate(values):m.write(BUTTON+base+4*i,value)

def resolved(value,ident,state,profile,ids):
    return 0xffffff if value==0 and state in (1,3) and profile==1 and ident in ids else value

def native_refresh(m,pe):
    """Occupied preset: actual late-refresh slice sets selected/pressed black."""
    m.ranges.append((0x8f72c,0x8f798))
    data_at=0x45000000;put(m,data_at-8,bytes(0x80));m.write(data_at-8,95000)
    m.reg[16]=BUTTON+0x34;m.reg[20]=data_at
    m.reg[23]=m.reg[21]=0xffffff;m.reg[19]=0x46494c
    m.reg[29]=STACK;m.write(STACK+0x1c,0x46494c)
    m.hooks[0x139668]=lambda m:0
    m.run(0x8f72c,{0x8f798})
    assert [m.read(BUTTON+a) for a in (0x550,0x558,0x830,0x838)]==[0]*4

def verify(before,after,recipe):
    old=pefile.PE(data=before);new=pefile.PE(data=after)
    catalog,ids=resources()
    count=0;reproductions=[]
    # Reproduce the station title/number loss after original refresh on both images.
    for raw,p,r,label in [(before,old,None,'MAX04'),(after,new,recipe,'candidate')]:
        m,events=setup(p,r);m.write(BUTTON+0x28,87);colors(m,[0xffffff]*4)
        native_refresh(m,p)
        for state in (1,3):
            call(m,0x13f258,[BUTTON,state])
            drawn=[e[2] for e in events if e[0]=='text'][-2:]
            assert drawn==([0,0] if label=='MAX04' else [0xffffff]*2),(label,drawn)
            reproductions.append(dict(image=label,state=state,primary=drawn[0],preset_number=drawn[1]))
    # All native resources, all four profiles and states, both foreground families.
    m,events=setup(new,recipe)
    for ident in range(len(catalog)):
        m.write(BUTTON+0x28,ident)
        for profile in range(4):
            m.write(RES+0x6d8,profile)
            for state in range(4):
                for painter in (0x13ecec,0x13f258):
                    colors(m,[0,0,0,0]);m.write(BUTTON+0x56c,0x40000)
                    events.clear();call(m,painter,[BUTTON,state])
                    text=[e for e in events if e[0]=='text']
                    value=resolved(0,ident,state,profile,ids)
                    assert all(e[2]==value for e in text) and text[0][4]==value,(ident,profile,state,text)
                    assert len(text)==(1 if painter==0x13ecec else 2)
                    assert events[0]==('sprite',BUTTON,state)
                    assert text[0][3]==[23,46,90,50]
                    if len(text)==2:assert text[1][3]==[143,16,30,20]
                    assert all(m.read(BUTTON+a)==0 for base in (0x54c,0x55c,0x82c) for a in range(base,base+16,4))
                    count+=1
    # Real nonblack foregrounds stay exact; offset flags and repeated redraws.
    extra=0
    for ident in ids:
        m.write(BUTTON+0x28,ident);m.write(RES+0x6d8,1)
        for value in (0xffffff,0x46494c,0xa2a2a2,0x12b3ed,0x308cf6,0xff00,0xffffffff):
            for state in range(4):
                colors(m,[value]*4);events.clear();call(m,0x13f258,[BUTTON,state])
                assert all(e[2]==value and e[4]==value for e in events if e[0]=='text')
                extra+=1
    for flags in (0,0x40000,0x10000|0x402,0x20000|0x402,0x70000|0x402):
        for state in range(4):
            colors(m,[0]*4);m.write(BUTTON+0x56c,flags);events.clear()
            call(m,0x13f258,[BUTTON,state])
            offset=(flags&0xff,(flags>>8)&0xff) if (state==1 and flags&0x10000) or (state==3 and flags&0x20000) else (0,0)
            text=[e for e in events if e[0]=='text']
            assert text[0][3]==[23+offset[0],46+offset[1],90,50]
            assert text[1][3]==[143+offset[0],16+offset[1],30,20]
            extra+=1
    # Null resource manager, sentinel and out-of-catalog IDs must bypass lookup.
    for null,ident in [(True,87),(False,len(catalog)),(False,0xffffffff),(False,0x80000000)]:
        m.write(0x186538,0 if null else RES);m.write(BUTTON+0x28,ident)
        for state in (1,3):
            colors(m,[0]*4);events.clear();call(m,0x13f258,[BUTTON,state])
            assert all(e[2]==0 for e in events if e[0]=='text');extra+=1
    # Helpers restore every scratch register except the replayed destination.
    helper_checks=0
    for n,(hook,state,replay) in enumerate(HOOKS):
        for active in (False,True):
            m,events=setup(new,recipe);colors(m,[0]*4);m.write(BUTTON+0x28,87)
            for reg in range(1,32):m.reg[reg]=0x11220000+reg
            m.reg[17]=BUTTON;m.reg[10]=BUTTON+0x54c;m.reg[13 if state=='t5' else 12]=3 if active else 0
            m.reg[29]=STACK;m.reg[31]=STOP;registers=m.reg[:]
            m.run(recipe['helpers'][n],{STOP})
            allowed={11}|({14} if n==0 else {13} if n==2 else set())
            assert all(m.reg[r]==registers[r] for r in range(32) if r not in allowed)
            assert m.reg[11]==(0xffffff if active else 0)
            helper_checks+=1
    relocation_checks=0
    # Rebase actual bytes, run both painter families and all three hooks.
    for delta in (0x1000,0x8000,0x10000,0x123000):
        moved=relocated(after,delta);p=pefile.PE(data=moved)
        for ident in (87,79,154,194,303,392,0xffffffff):
            for profile in range(4):
                for state in range(4):
                    m,events=setup(p,recipe,delta);m.write(BUTTON+0x28,ident);m.write(RES+0x6d8,profile)
                    colors(m,[0]*4);m.write(BUTTON+0x56c,0x40000)
                    call(m,0x13f258+delta,[BUTTON,state])
                    value=resolved(0,ident,state,profile,ids)
                    assert all(e[2]==value and e[4]==value for e in events if e[0]=='text')
                    relocation_checks+=1
        # All preexisting imports and relocated code outside explained edits persist.
        previous=relocated(before,delta)
        allowed=set(i for e in recipe['edits'] for i in range(e['offset'],e['offset']+len(bytes.fromhex(e['before_hex']))))
        assert all(a==b or i in allowed for i,(a,b) in enumerate(zip(previous,moved)))
    return dict(native_execution=False,hardware_tested=False,radio_refresh_reproduction=reproductions,
        catalog_resources=len(catalog),themed_button_resources=len(ids),resource_profile_state_painter_cases=count,
        semantic_layout_boundary_cases=extra,leaf_register_cases=helper_checks,relocated_painter_cases=relocation_checks,
        relocated_whole_image_comparisons=4,profiles=['M0','M1','M0_INV','M1_INV'],
        coverage='AppMain shared text-button primary/alternate and two-text/list secondary painters',
        limitations=['Offline MIPS interpreter with explicit sprite/text draw fixtures',
                     'No physical MediaNav, CE loader, navigation GUI or external application execution'])

if __name__=='__main__':
    before=(RELEASE/'payload'/APP).read_bytes();after,recipe=patch(before)
    result=verify(before,after,recipe)
    path=ROOT/'analysis/firmware/selected-label-contrast-proof.json'
    path.write_text(json.dumps(dict(**result,input_sha256=sha(before),sha256=sha(after)),indent=2)+'\n')
    print(json.dumps(result,indent=2))
