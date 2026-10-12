"""Independent native geometry, metadata, GDI lifetime and full payload checks."""
import json
import struct
import sys
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont
import build_bt_usb_player as p
sys.path.insert(0,str(p.ROOT/'tools'))
from inspect_av_layouts import trace, ENTRIES, SIZES
import inspect_av_layouts
inspect_av_layouts.SYSTEM = p.ROOT/'extracted/705md/upgrade/Storage Card/System'
from verify_max08_successor import PopupApp, NativeText, consume, BANK
from verify_bt_cover_install import World
from verify_bt_cover_app_paint import DIALOG, SURFACE, PAINT_DC, OS
from verify_bt_cover_image import API
from verify_bt_text_recovery_install import ArtworkBlue
from verify_bt_text_metadata_receive import attribute, reply
from inspect_bt_pairing import data
from patch_shared_mapping_checks import reloc_records
from verify_usb_input_safety import relocated
import bt_cover_art_image as image
import bt_cover_art_worker as worker
import pefile

FALLBACK = 0x9900
SYSTEM = Path('upgrade/Storage Card/System')
NATIVE = p.REPO/'build/maxmade-7.0.6.MAX05-local/payload'/SYSTEM
SCENE = None
FALLBACK_PIXELS = None


class Player(PopupApp):
    def __init__(self, raw, candidate, world, recipe):
        super().__init__(raw,candidate,world,recipe)
        self.allowed.append((0x186538,0x18653c))
        self.write(0x186538,0x46003000)
        self.hooks[0x13dde0] = self.fallback
        # The existing fixture normally binds these IAT entries when its first
        # decoder worker runs. The new no-cover path uses GDI before that worker.
        for thunk,target in API.items():
            words=struct.unpack('<4I',self.candidate.get_data(thunk-p.BASE,16))
            assert words[0]>>26==15 and words[1]>>26==35
            lo=words[1]&65535
            if lo>=32768:lo-=65536
            iat=((words[0]&65535)<<16)+lo
            self.allowed.append((iat,iat+4));self.write(iat,target)
        self.fallback_loads=0
        self.control_rects=[]

    def fallback(self,m):
        assert self.role=='gui' and m.reg[4:6]==[0x46003000,117]
        self.fallback_loads+=1
        return 0 if self.paint_fail=='fallback_missing' else FALLBACK

    def children(self,m):
        if m.reg[4]==DIALOG+0x84: return super().children(m)
        assert m.reg[4]==DIALOG+4
        self.surface.paste(SCENE)
        return 0

    def visible_children(self,m):
        if m.reg[4]==DIALOG+4:return self.children(m)
        return super().visible_children(m)

    def gdi(self,pc):
        which=next(at for at,target in API.items() if target==pc)
        if self.role=='gui' and which==image.SELECT:
            dc,h=self.reg[4:6]
            if h==FALLBACK:
                assert dc==PAINT_DC and self.paint_dcs[dc] is None
                if self.paint_fail=='select_null':return 0
                if self.paint_fail=='select_invalid':return 0xffffffff
                self.paint_dcs[dc]=FALLBACK
                return 0x9003
            if dc==PAINT_DC and self.paint_dcs.get(dc)==FALLBACK:
                assert h==0x9003
                if self.paint_fail=='restore_null':return 0
                self.paint_dcs[dc]=None
                return FALLBACK
        if self.role=='gui' and which==image.DELETE_DC and self.paint_dcs.get(PAINT_DC)==FALLBACK:
            assert self.reg[4]==PAINT_DC
            self.paint_dcs.pop(PAINT_DC)
            return 1
        # A borrowed ResManager bitmap must never enter DeleteObject.
        if which==image.DELETE_OBJECT:assert self.reg[4]!=FALLBACK
        return super().gdi(pc)

    def os_api(self,pc):
        at=next(at for at,target in OS.items() if target==pc)
        if at!=0x185250:return super().os_api(pc)
        args=self.reg[4:8]+[self.read(self.reg[29]+i) for i in range(0x10,0x2c,4)]
        assert args[:8]==[SURFACE,27,98,278,278,PAINT_DC,0,0]
        assert args[-1]==0xcc0020
        h=self.paint_dcs[PAINT_DC]
        if h==FALLBACK:
            assert args[8:10]==[278,278]
            self.surface.paste(FALLBACK_PIXELS,(27,98))
            return 1
        assert h in self.bitmaps and args[8:10]==[200,200]
        if self.paint_fail=='stretch_failed':
            self.surface.paste((255,0,0),(27,98,150,376));return 0
        self.surface.paste(Image.frombytes('RGB',(200,200),self.bitmaps[h].dib_pixels).resize((278,278)),(27,98))
        if self.invalidate_at and self.invalidate_at[0]=='stretched':
            _,fn=self.invalidate_at;self.invalidate_at=None;fn()
        return 1


def scene(layout,payload,title='A track from your phone',artist='Artist name'):
    from build_home_theme import REL,BG,KEY,COLORS
    surface=Image.new('RGB',(800,480),BG)
    d=ImageDraw.Draw(surface)
    fonts={n:ImageFont.truetype('C:/Windows/Fonts/tahoma.ttf',n) for n in (20,24,28)}
    d.text((736,32),'00:47',font=fonts[24],fill=(238,243,247),anchor='mm')
    d.line((0,77,799,77),fill=(37,46,52))
    for control in layout['controls']:
        x,y,w,h=control['rect']
        name=control.get('filename')
        if name:
            resource=Image.open(payload/REL/name.replace('\\','/')).convert('RGB')
            state=3 if control.get('text')=='Player' else 0
            # Native constructor geometry picks the sprite frame; no web redraw.
            count=control.get('frame_count',1)
            sprite=resource.crop((state*w,0,(state+1)*w,h)) if count==4 else resource.crop((0,0,w,h))
            assert sprite.size==(w,h)
            mask=Image.new('L',sprite.size)
            mask.putdata([0 if rgb==KEY else 255 for rgb in sprite.getdata()])
            surface.paste(sprite,(x,y),mask)
        text=control.get('text') or ''
        offset=control['object_offset']
        if offset=='0x8e0' and name is None:text=title
        if offset=='0xb8c':text=artist
        if offset=='0x934':text=title
        if offset=='0xbe0':text=artist
        if text:
            font=fonts[28] if offset in ('0x8e0','0x934') and name is None else fonts[24] if control.get('kind')=='button' else fonts[20]
            d.text((x+w/2,y+h/2),text,font=font,fill=(238,243,247),anchor='mm')
    return surface


def verify():
    global SCENE,FALLBACK_PIXELS
    raw=(p.BASELINE/'payload'/p.APP).read_bytes()
    candidate=(p.OUT/'payload'/p.APP).read_bytes()
    assert candidate==p.patch(raw)[0]
    recipe=json.loads((p.OUT/'recipe.json').read_bytes())
    old,new=pefile.PE(data=raw),pefile.PE(data=candidate)
    assert new.OPTIONAL_HEADER.CheckSum==new.generate_checksum()
    assert [(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in old.DIRECTORY_ENTRY_IMPORT]==[(d.dll,[(i.name,i.ordinal) for i in d.imports]) for d in new.DIRECTORY_ENTRY_IMPORT]
    geometry=[]
    for ui in range(4):
        before=trace(0x3b05c,'media',raw,ui)
        after=trace(0x3b05c,'media',candidate,ui)
        usb=trace(0x4c26c,'media',candidate,ui)
        controls={r['object_offset']:r for r in after['controls']}
        reference={r['object_offset']:r for r in usb['controls']}
        for bt,us in (('0x8e0','0x934'),('0xb8c','0xbe0'),('0x13e4','0x148c'),('0x1458','0x1500'),('0x14d0','0x1578')):
            assert controls[bt]['rect']==reference[us]['rect']
            assert controls[bt].get('font_index')==reference[us].get('font_index')
            if bt.startswith('0x14') or bt=='0x13e4': assert controls[bt]['image_id']==reference[us]['image_id']
        for a,b in zip(before['controls'],after['controls']):
            assert a['object_offset']==b['object_offset'] and a.get('event')==b.get('event') and a.get('text')==b.get('text')
            if a['object_offset'] not in ('0x8e0','0xb8c','0x13e4','0x1458','0x14d0'): assert a==b
        for entry in ENTRIES['media']:
            if entry != 0x3b05c:assert old.get_data(entry-p.BASE,SIZES[entry])==new.get_data(entry-p.BASE,SIZES[entry])
        geometry.append(dict(ui=ui,USB_layout_matches=True,all_other_media_constructors_equal=True))
    layouts=trace(0x3b05c,'media',candidate,1)
    previews=p.OUT/'previews';previews.mkdir(exist_ok=True)
    SCENE=scene(layouts,p.OUT/'payload')
    FALLBACK_PIXELS=Image.open(p.OUT/'payload'/SYSTEM/'Img/M1/media/media_album_case_noalbum_img.bmp').convert('RGB')
    SCENE.save(previews/'bluetooth-layout.png')
    usbscene=scene(trace(0x4c26c,'media',candidate,1),p.OUT/'payload')
    usbscene.save(previews/'usb-reference.png')
    # Native reader + native dialog setter: changing geometry does not change
    # initial/next-track/no-artist/unicode delivery to the original widgets.
    blue=(p.OUT/'payload'/SYSTEM/'Blue.exe').read_bytes()
    native_blue=(NATIVE/'Blue.exe').read_bytes()
    titles=[]
    m=NativeText(native_blue,blue)
    for uid,title,artist in ((bytes(8),'Initial track','Artist'),(b'12345678','Skipped track',''),(b'87654321','Muziek ♫','Björk')):
        m.live(uid);m.queue_ordinary();m.profile();parent=m.serialized[-1]['confirmation']
        row=m.respond(parent,reply(body=attribute(1,title.encode())+attribute(2,artist.encode())+attribute(3,b''),count=3,ctype=12))
        assert m.deliver(row)==1
        assert consume(candidate,data(m,BANK+0xcf0e8,260))[0]==[title,'',artist]
        titles.append(dict(title=title,artist=artist,readback=True))
    m.conclude()
    art=[]
    native_app=(NATIVE/'AppMain.exe').read_bytes()
    for mode in ('empty','accepted','stale','source_stop','disconnect','stretch_failed','popup','dc_null','select_null','select_invalid','restore_null','fallback_missing'):
        w=World();b=ArtworkBlue(pefile.PE(data=native_blue),blue,w)
        a=Player(native_app,candidate,w,recipe)
        b.start();assert a.start()==1
        if mode in ('dc_null','select_null','select_invalid','restore_null','fallback_missing'):a.paint_fail=mode
        a.draw();a.window(15)
        if mode=='empty':
            assert a.screen.crop((27,98,305,376)).tobytes()==FALLBACK_PIXELS.tobytes()
            a.screen.save(previews/'bluetooth-no-cover.png')
        if mode in ('accepted','stale','source_stop','disconnect','stretch_failed','popup'):
            b.receive_image();b.deliver_window();assert a.run_worker()==0
            if mode=='stretch_failed':a.paint_fail=mode
            assert a.window(worker.MESSAGE)==0
            if mode=='accepted':
                assert a.screen.crop((27,98,305,376)).tobytes()!=FALLBACK_PIXELS.tobytes()
                a.screen.save(previews/'bluetooth-fixture-cover.png')
            if mode=='stale':a.now=5101
            if mode=='source_stop':b.command(0x1070505);b.handle()
            if mode=='disconnect':b.disconnect_native();b.handle()
            if mode in ('stale','source_stop','disconnect','stretch_failed'):
                a.window(15)
                assert a.screen.crop((27,98,305,376)).tobytes()==FALLBACK_PIXELS.tobytes()
            if mode=='popup':
                a.show_popup(True);a.draw();a.window(15)
                assert a.screen.getpixel((100,150))==(120,80,40)
                a.show_popup(False);a.draw();a.window(15)
                assert a.screen.getpixel((100,150))!=(120,80,40)
        assert a.screen.getpixel((320,300))==SCENE.getpixel((320,300)), mode
        art.append(dict(case=mode,steps=a.steps+b.steps,borrowed_fallback_not_deleted=True))
        a.finish();b.stop();b.deliver_window();assert not w.handles and not w.views and not a.paint_dcs
        print('Artwork/painter check passed:',mode,flush=True)
    # Rebase every new fallback operand and all retained unwind pointers.
    rebases=[]
    for delta in (0x1000,0x8000,0x123000):
        rebased=pefile.PE(data=relocated(candidate,delta))
        for at,kind,_ in recipe['frame_relocations']:assert (at,kind,_) in reloc_records(new)
        literal=struct.pack('<II',0x3c0800cc,0x25080020)
        assert literal in rebased.get_data(0x340000-p.BASE,0x1000)
        rd=new.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        rows=list(struct.iter_unpack('<5I',new.get_data(rd.VirtualAddress,rd.Size)))
        assert list(struct.iter_unpack('<5I',rebased.get_data(rd.VirtualAddress,rd.Size)))==[tuple(v+delta if v else 0 for v in r) for r in rows]
        rebases.append(delta)
    report=dict(app_sha256=p.sha(candidate),geometry=geometry,title_cases=titles,artwork=art,rebases=rebases,
                USB_and_iPod_player_bytes_preserved=True,Blue_byte_identical_MAX12=True,
                native_executed=False,hardware_tested=False,
                limits=['Native instructions interpreted with explicit phone/CE/GDI fixtures; previews use host fonts and sample metadata',
                        'Album-art receipt remains unconfirmed on hardware; MAX11 acquisition correction inherited',
                        'USB seek/time controls are not bound to Bluetooth without a verified timing/seek contract'])
    (p.OUT/'verification.json').write_text(json.dumps(report,indent=2)+'\n')
    return dict(geometry=len(geometry),titles=len(titles),artwork=len(art),rebases=len(rebases))


if __name__=='__main__':print(json.dumps(verify(),indent=2))
