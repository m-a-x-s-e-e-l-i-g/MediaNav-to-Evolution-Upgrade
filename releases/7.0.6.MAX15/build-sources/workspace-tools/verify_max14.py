"""Execute installed successor instructions with bounded CE/GDI fixtures."""
import json
import struct
from pathlib import Path
import build_max14 as p
import pefile
from PIL import Image,ImageDraw,ImageFont
from verify_media_responsiveness import VM,call,STACK
from inspect_bt_pairing import put,data
from inspect_wave_queue import STOP
from verify_usb_input_safety import relocated
from verify_selected_label_contrast import setup,colors,BUTTON,RES,native_refresh
import inspect_av_layouts as av
import inspect_settings_layouts as settings
import inspect_home_layout as home
from verify_bt_usb_player import Player as PreviousPlayer,scene,NATIVE
import verify_bt_usb_player as previous
from verify_bt_cover_install import World
from verify_bt_text_recovery_install import ArtworkBlue
from verify_bt_cover_app_paint import DIALOG,SURFACE
import bt_cover_art_worker as worker
import bt_cover_art_image as imaging
from verify_bt_cover_image import jpeg
from build_home_theme import transparent
av.SYSTEM=settings.SYSTEM=home.SYSTEM=p.ROOT/'extracted/705md/upgrade/Storage Card/System'
home.ROOT=av.ROOT=settings.ROOT=p.ROOT
settings.trace.__globals__['SYSTEM']=av.SYSTEM

def refresh_manifest():
    report=json.loads((p.OUT/'manifest.json').read_bytes())
    for r in report['members']:
        raw=(p.OUT/'payload'/r['path']).read_bytes();r.update(bytes=len(raw),sha256=p.sha(raw))
    (p.OUT/'manifest.json').write_text(json.dumps(report,indent=2)+'\n')

def pause_checks(raw,recipe):
    old=(p.BASELINE/'payload'/p.APP).read_bytes();pe=pefile.PE(data=raw)
    native_blue=pefile.PE(data=(p.BASELINE/'payload'/p.SYSTEM/'Blue.exe').read_bytes())
    context,msg,dialog=0x44000000,0x45000000,0x46000000
    native_messages=[]
    # Actual installed Blue notification primitive -> existing playing/paused
    # message, including unknown/stopped states. External logging/queue fixtures.
    for status in (0,1,2,3,4,255):
        m=VM(native_blue,[(0x1dc40,0x1dcc4)])
        put(m,context,bytes(0x2500));put(m,msg,bytes(16));m.write(msg+3,status,1)
        seen=[]
        m.hooks[0x33538]=lambda m:seen.append(m.reg[5]) or 1
        m.hooks[0x8a7c0]=lambda m:0
        m.hooks[0x34264]=lambda m:0
        call(m,0x1dc40,[0,context,msg])
        assert m.read(context+0x218,1)==status and seen==[0x3070801 if status==1 else 0x3070901],(status,seen)
        native_messages.append((status,seen[0]))
    cases=[]
    for delta in (0,0x1000,0x8000,0x123000):
        image=pefile.PE(data=raw if not delta else relocated(raw,delta))
        m=VM(image,[(p.CAPTURE+delta,p.CAPTURE+0x300+delta),(p.ICON+delta,p.ICON+0x200+delta),(0x11cb8c+delta,0x11cb94+delta)])
        put(m,msg,bytes(16));put(m,dialog,bytes(0x3000));put(m,p.STATE+delta,bytes(0x40))
        m.write(0x188270+delta,dialog);m.write(dialog+0x50,0x123456);m.write(dialog+0x1458+0x28,120)
        m.write(dialog+0x1458+0x48,1002)
        posted=[];changes=[];draws=[]
        m.write(0x185040+delta,0xf0010000)
        def post(m):
            posted.append(m.reg[4:8][:]);return 1
        def select(m):
            assert m.reg[4]==dialog+0x1458 and m.reg[5] in (120,121)
            changes.append(m.reg[5]);m.write(m.reg[4]+0x28,m.reg[5]);return 0
        m.hooks[0xf0010000]=post
        m.hooks[0x139104+delta]=select
        m.hooks[0x139020+delta]=lambda m:draws.append(m.reg[4]) or 0
        for status,message in native_messages+[(2,0x3070901),(1,0x3070801),(1,0x3070801),(0,0x3010806),(99,0x12345678)]:
            m.write(msg+8,message)
            for r in range(1,32):m.reg[r]=0x11220000+r
            m.reg[18]=msg;m.reg[29]=STACK;m.reg[31]=STOP
            saved=m.reg[:];prior=m.read(p.STATE+delta);before=len(posted)
            m.run(0x11cb8c+delta,{0x11cb94+delta},limit=10000)
            assert m.reg[8]==0x3070000 and m.reg[4]==message
            assert all(m.reg[r]==saved[r] for r in range(32) if r not in (4,8,31)),r
            state=1 if message==0x3070801 else 2 if message==0x3070901 else 0 if message==0x3010806 else prior
            assert m.read(p.STATE+delta)==state
            assert len(posted)-before==int(message in (0x3070801,0x3070901,0x3010806))
            if len(posted)>before:assert posted[-1]==[0x123456,0x82f3,0,0]
            redrawbefore=len(draws);was=m.read(dialog+0x1458+0x28)
            call(m,p.ICON+delta,[1])
            wanted=121 if state==1 else 120
            assert m.read(dialog+0x1458+0x28)==wanted and len(draws)-redrawbefore==int(was!=wanted)
            assert m.read(dialog+0x1458+0x48)==1002
            cases.append(dict(delta=delta,status=status,message=hex(message),image=wanted))
        # Absent, unopened, invalid control: selector fails closed.
        for global_value,hwnd,resource in ((0,0,120),(dialog,0,120),(dialog,0x123456,116)):
            m.write(0x188270+delta,global_value);m.write(dialog+0x50,hwnd);m.write(dialog+0x1458+0x28,resource)
            n=len(changes);call(m,p.ICON+delta,[1]);assert len(changes)==n
    # Touch command and USB/iPod functions are identical. Constructors and
    # their widget/event identity are unchanged from the physical MAX13 build.
    geometry=[]
    for ui in range(4):
        for entry in av.ENTRIES['media']:
            assert pe.get_data(entry-p.BASE,av.SIZES[entry])==pefile.PE(data=old).get_data(entry-p.BASE,av.SIZES[entry])
        geometry.append(dict(ui=ui,all_media_constructor_bytes_retained=True))
    return dict(native_notification_cases=len(native_messages),installed_binding_cases=cases,geometry=geometry)

def label_checks(raw,recipe):
    pe=pefile.PE(data=raw);prior=pefile.PE(data=(p.BASELINE/'payload'/p.APP).read_bytes())
    dark=prior.get_data(0x33f800-p.BASE,0x200);light=pe.get_data(0x33fa00-p.BASE,0x200)
    assert pe.get_data(0x33f800-p.BASE,0x200)==dark
    cases=0;rebases=[]
    for delta in (0,0x1000,0x123000):
        moved=pefile.PE(data=raw if not delta else relocated(raw,delta))
        m,events=setup(moved,recipe,delta)
        for ident in list(range(len(p.CATALOG)))+[0xffffffff,len(p.CATALOG),0x80000000]:
            m.write(BUTTON+0x28,ident)
            for profile in range(4):
                m.write(RES+0x6d8,profile)
                for state in range(4):
                    for painter in (0x13ecec,0x13f258):
                        for value in (0,0xffffff,0x46494c,0xff00):
                            colors(m,[value]*4);events.clear();call(m,painter+delta,[BUTTON,state])
                            expected=value
                            if profile==1 and ident<len(dark) and dark[ident] and state in (1,3) and value==0:expected=0xffffff
                            if profile==3:
                                if ident==0xffffffff and (value&255)==((value>>8)&255)==((value>>16)&255):expected=0x72685f if state==2 else 0x2d261c
                                elif ident<len(light) and light[ident]:expected=0xffffff if state in (1,3) else 0x72685f if state==2 else 0x2d261c
                            drawn=[e for e in events if e[0]=='text'];assert all(e[2]==expected for e in drawn),(ident,profile,state,value,drawn)
                            assert [m.read(BUTTON+a) for a in (0x54c,0x550,0x554,0x558)]==[value]*4
                            cases+=1
        rebases.append(delta)
    # Radio late-refresh black must become visible in both dark and light.
    m,events=setup(pe,recipe);m.write(BUTTON+0x28,87);colors(m,[0xffffff]*4);native_refresh(m,pe)
    for profile in (1,3):
        m.write(RES+0x6d8,profile)
        for state in (1,3):
            events.clear();call(m,0x13f258,[BUTTON,state]);assert all(e[2]==0xffffff for e in events if e[0]=='text')
    return dict(catalog_profile_state_painter_color_cases=cases,rebases=rebases,radio_late_black_labels_readable=True)

class Player(PreviousPlayer):
    def __init__(self,raw,candidate,w,recipe):
        compatible=dict(recipe,artwork=dict(address=0x340000,text_va=0x341000))
        super().__init__(raw,candidate,w,compatible)
        self.ranges += [(r['address'],r['address']+r['capacity']) for r in recipe['routines']]
        self.allowed += [(DIALOG+0x100,DIALOG+0x3000),(0x46003000,0x46003800),(p.STRINGS,p.STRINGS+0x400)]
        put(self,p.STRINGS,self.candidate.get_data(p.STRINGS-p.BASE,0x400))
        put(self,0x46003000,bytes(0x800));self.write(0x46003000+0x6d8,1)
        self.write(DIALOG+0x1458+0x28,120)
        self.hooks[0x139104]=self.select_icon
        self.hooks[0x139020]=lambda m:0
        self.capture_status=[]

    def select_icon(self,m):
        assert self.role=='gui' and m.reg[4]==DIALOG+0x1458
        self.write(m.reg[4]+0x28,m.reg[5]);return 0

    def frame_api(self,iat):
        if iat!=0x18509c:return super().frame_api(iat)
        assert self.role=='gui' and self.reg[4]==SURFACE and self.reg[6]==0xffffffff
        text=self.cstring16(self.reg[5]);assert text in p.CAPTIONS
        rect=tuple(self.read(self.reg[7]+i*4) for i in range(4));assert rect==(31,325,301,373)
        assert self.bkmode==1
        self.capture_status.append(text)
        d=ImageDraw.Draw(self.surface)
        d.text((166,347),text,font=ImageFont.truetype('C:/Windows/Fonts/tahoma.ttf',15),fill=(136,124,104),anchor='mm')
        return 20

    def cstring16(self,at):
        units=[]
        for i in range(32):
            c=self.read(at+i*2,2)
            if not c:return b''.join(v.to_bytes(2,'little') for v in units).decode('utf-16-le')
            units.append(c)
        raise AssertionError('Caption not terminated')

def artwork_checks(raw,recipe,modes=None):
    native_app=(NATIVE/'AppMain.exe').read_bytes();native_blue=(NATIVE/'Blue.exe').read_bytes()
    blue=(p.OUT/'payload'/p.SYSTEM/'Blue.exe').read_bytes()
    previous.SCENE=previous.scene(av.trace(0x3b05c,'media',raw,1),p.OUT/'payload')
    previous.FALLBACK_PIXELS=Image.open(p.OUT/'payload'/p.SYSTEM/'Img/M1/media/media_album_case_noalbum_img.bmp').convert('RGB')
    preview=p.OUT/'previews';preview.mkdir(exist_ok=True)
    cases=[]
    modes=modes or ['captured0','captured1','captured2','factory','image','info','dc','dib','draw','com','startup_recovery','startup_bounded','popup','stale','disconnect','priority','resume']
    for mode in modes:
        w=World();b=ArtworkBlue(pefile.PE(data=native_blue),blue,w);a=Player(native_app,raw,w,recipe)
        b.start()
        if mode in ('startup_recovery','startup_bounded'):
            a.failure='event';assert a.start()==0
            assert a.gui_native(p.RECOVER)==0
            if mode=='startup_recovery':
                a.failure=None;a.now=1100;assert a.gui_native(p.RECOVER)==0 and a.field(12)==1
            else:
                for now in (100,100,1099,1100,2100,3100,4100):a.now=now;a.gui_native(p.RECOVER)
                assert a.read(p.STATE+8)==3 and a.field(12)==0
        else:
            if mode in ('priority','resume'):a.failure=mode
            assert a.start()==(0 if mode in ('priority','resume') else 1)
        a.draw();a.window(15)
        if mode not in ('startup_bounded','priority','resume'):
            if mode=='com':a.fail_com=0x80004005
            if mode in ('factory','image','info','dc','dib','draw'):
                a.fail_decode={'factory':'factory_error','image':'image_error','info':'info_error','dc':'dc_null','dib':'dib_null','draw':'draw_error'}[mode]
            if mode.startswith('captured'):
                encoded=(p.ROOT/'build/max13-phone-artwork-local'/f'cover-{mode[-1]}.jpg').read_bytes()
            else:encoded=jpeg()
            b.receive_image(encoded);b.deliver_window();assert a.run_worker()==(1 if mode=='com' else 0)
            a.window(worker.MESSAGE);a.window(0x113,0x4d42)
            if mode.startswith('captured'):
                assert a.field(20) and a.read(p.STAGE)==9
                assert not any(v for k,v in a.decoder.resources.items() if k!='bitmap'),(mode,a.decoder.resources)
                assert a.screen.getpixel((100,200))!=previous.FALLBACK_PIXELS.getpixel((100,200))
            if mode in ('factory','image','info','dc','dib','draw','com'):
                assert not a.field(20) and len(a.capture_status)>0,(mode,a.field(20),a.capture_status,a.read(p.STAGE))
                expected={'factory':2,'image':3,'info':4,'dc':5,'dib':6,'draw':8}.get(mode)
                if expected:assert a.read(p.STAGE)==expected,(mode,a.read(p.STAGE))
                assert a.capture_status[-1]==p.CAPTIONS[2 if mode=='com' else expected+2]
                n=len(a.capture_status);a.window(0x113,0x4d42);assert len(a.capture_status)==n
            if mode=='popup':
                a.show_popup(True);a.draw();a.window(15);assert a.screen.getpixel((100,150))==(120,80,40)
            if mode=='stale':a.now=5101;a.window(15);assert not a.field(20)
            if mode=='disconnect':b.disconnect_native();b.handle();a.window(15);assert not a.field(20)
        # Captured images remain private, so preview only synthetic no-cover.
        if mode=='factory':a.screen.save(preview/'bluetooth-cover-diagnostic.png')
        cases.append(dict(case=mode,decoder_stage=a.read(p.STAGE),captions=a.capture_status[-1:],steps=a.steps+b.steps))
        a.finish();b.stop();b.deliver_window();assert not w.handles and not w.views and not a.paint_dcs
        print('Artwork/lifetime:',mode,flush=True)
    return cases

def previews(raw):
    dest=p.OUT/'previews';dest.mkdir(exist_ok=True)
    font=ImageFont.truetype('C:/Windows/Fonts/tahoma.ttf',24)
    def render(layout,family,name,selected=set(),playing=False):
        rel=p.SYSTEM/'Img/M1_INV'
        img=Image.open(p.OUT/'payload'/rel/'common'/f'{family}_bg.bmp').convert('RGB')
        d=ImageDraw.Draw(img)
        for r in layout['controls']:
            x,y,w,h=r['rect'];resource=r.get('filename') or ''
            if w<=0 or h<=0 or x>=800 or y>=480:continue
            if name=='radio-options-light' and r['object_offset'] in ('0x14e0','0x4dec','0x535c','0x58cc','0x5b78'):
                continue  # Alternate page controls share first-page positions.
            state=3 if r.get('event') in selected else 0
            if name=='settings-light' and resource.endswith('softkey_4_1_btn.bmp'):state=3
            if resource:
                if playing and r.get('image_id')==120:resource=p.CATALOG[121]['filename']
                src=Image.open(p.OUT/'payload'/rel/resource.replace('\\','/')).convert('RGB')
                button='_btn' in resource or resource.endswith('_press.bmp') or 'changekey_' in resource
                count=4 if button else r.get('frame_count',1)
                fw=src.width//count
                crop=transparent(src.crop((fw*state if button else 0,0,(fw*state if button else 0)+min(fw,w),min(h,src.height))))
                img.paste(crop,(x,y),crop.getchannel('A'))
            text=r.get('text') or ''
            if name=='bluetooth-light' and r['object_offset']=='0x8e0':text='A track from your phone'
            if name=='bluetooth-light' and r['object_offset']=='0xb8c':text='Artist name'
            if text and text!=' ':
                tx,ty,tw,th=r.get('label_rect',r['rect'])
                color='white' if state in (1,3) and resource else p.INK
                d.text((tx+tw/2,ty+th/2),text.replace('\r\n',' '),font=font,fill=color,anchor='mm')
        if name=='bluetooth-light':img.paste(Image.open(p.OUT/'payload'/rel/'media/media_album_case_noalbum_img.bmp'),(27,98))
        img.save(dest/(name+'.png'));return img
    images=[render(av.trace(0x3b05c,'media',raw,3),'media','bluetooth-light',{1005},True),
            render(av.trace(0x4c26c,'media',raw,3),'media','usb-light',{1005}),
            render(home.trace(1,0,0,3,raw=raw),'home','home-light')]
    # Same native constructor positions as MAX13, sample page/state choices.
    cases=settings.layouts(raw,ui=3)['scenarios']
    case=next(c for c in cases if c['entry']=='0xb69a0')
    case=dict(case,controls=[r for r in case['controls'] if r.get('object_offset') not in ('0x6d3c','0x67cc')])
    images.append(render(case,'setting','settings-light',{1003,1008}))
    images.append(render(av.trace(0x3ca0c,'media',raw,3),'media','bluetooth-options-light',{1001,1005,1009}))
    images.append(render(av.trace(0xa4054,'radio',raw,3),'fmradio','radio-options-light',{1002,1003,1006,1007,1018}))
    sheet=Image.new('RGB',(1620,1480),p.LIGHT_BG)
    for i,im in enumerate(images):sheet.paste(im,(10+(i%2)*810,10+(i//2)*490))
    sheet.save(dest/'light-theme-overview.png')
    return len(images)

def main():
    raw=(p.OUT/'payload'/p.APP).read_bytes();recipe=json.loads((p.OUT/'recipe.json').read_bytes())
    deterministic=p.patch((p.BASELINE/'payload'/p.APP).read_bytes(),json.loads((p.ROOT/'analysis/firmware/max14-light-resource-plan.json').read_bytes()))[0]
    assert raw==deterministic
    pe=pefile.PE(data=raw);old=pefile.PE(data=(p.BASELINE/'payload'/p.APP).read_bytes())
    assert pe.OPTIONAL_HEADER.CheckSum==pe.generate_checksum() and pe.FILE_HEADER.Machine==0x166
    assert [(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in pe.DIRECTORY_ENTRY_IMPORT]==[(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in old.DIRECTORY_ENTRY_IMPORT]
    assert all(not(s.Characteristics&0x20000000 and s.Characteristics&0x80000000) for s in pe.sections)
    pd=pe.OPTIONAL_HEADER.DATA_DIRECTORY[3];rows=list(struct.iter_unpack('<5I',pe.get_data(pd.VirtualAddress,pd.Size)))
    for delta in (0x1000,0x8000,0x123000):
        moved=pefile.PE(data=relocated(raw,delta))
        assert list(struct.iter_unpack('<5I',moved.get_data(pd.VirtualAddress,pd.Size)))==[tuple(v+delta if v else 0 for v in r) for r in rows]
    proof=dict(app_sha256=p.sha(raw),playback=pause_checks(raw,recipe))
    print('Native notification/playback checks passed.',flush=True)
    proof['labels']=label_checks(raw,recipe);print('Shared label and relocation checks passed.',flush=True)
    proof['artwork']=artwork_checks(raw,recipe)
    proof.update(previews=previews(raw),light_asset_contracts=len(json.loads((p.OUT/'light-assets.json').read_bytes())),native_executed=False,hardware_tested=False,
                 artwork_issue_status='Unresolved until car test; phone sends valid images, CE decoder/display stage needs real-device evidence',privacy='Captured artwork and snoop contents excluded from deliverables')
    refresh_manifest()
    (p.OUT/'verification.json').write_text(json.dumps(proof,indent=2)+'\n')
    print(json.dumps(dict(app_sha256=proof['app_sha256'],labels=proof['labels'],artwork_cases=len(proof['artwork']),previews=proof['previews']),indent=2))

if __name__=='__main__':main()
