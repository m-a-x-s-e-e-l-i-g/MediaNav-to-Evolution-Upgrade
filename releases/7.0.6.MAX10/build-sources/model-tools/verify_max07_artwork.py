"""Exercise the new artwork placeholder together with retained MAX06 overlays.

Native candidate/background/cleanup/copy instructions execute. GDI and CE use
explicit host pixel/handle fixtures; the preview is not a device screenshot.
"""
import hashlib
import json
import struct
from pathlib import Path
from PIL import ImageDraw, ImageFont
import pefile
from verify_bt_cover_install import App as OriginalApp, World
from verify_bt_text_recovery_install import ArtworkBlue
from verify_bt_cover_app_paint import DIALOG,SURFACE,DRAW_RESULT,CACHE_DC
from inspect_bt_pairing import put,data
import bt_cover_art_worker as worker
import layout_bt_cover_native as layout
import patch_max07_bluetooth as bluetooth
import max07_bt_helpers as bt_helpers

ROOT=Path(__file__).resolve().parents[1]
HOST=ROOT.parents[1]
APP=HOST/'build/max07-app-development-03'
BLUE=ROOT/'build/max07-bluetooth-development-03'
PREVIOUS=ROOT/'build/maxmade-7.0.6.MAX05-local/payload/upgrade/Storage Card/System'
OS=(0x1850dc,0x1850f0,0x185240,0x185284,0x18509c)


class App(OriginalApp):
    def __init__(self,raw,candidate,w,recipe):
        super().__init__(pefile.PE(data=raw),candidate,w)
        r=recipe['artwork'];self.frame=r;self.draw_caption=[];self.textcolor=0xeeeeee;self.bkmode=2
        self.stock_failure=False;self.fill_failure=False
        self.ranges.append((r['address'],r['address']+0x1000))
        at=r['text_va'];caption='Album art\0'.encode('utf-16-le')
        self.allowed.append((at,at+len(caption)))
        # Use the shipped UTF-16 bytes, not a substituted caption.
        put(self,at,self.candidate.get_data(at-0x10000,len(caption)))
        for index,iat in enumerate(OS):
            target=0x48006000+index*16
            self.allowed.append((iat,iat+4));self.write(iat,target)
            self.hooks[target]=lambda m,iat=iat:self.frame_api(iat)
        # Native WM_PAINT restores the cached bitmap through a direct
        # SelectObject import. The old fixture only covered its initial stub.
        self.allowed.append((0x185068,0x18506c));self.write(0x185068,0x48006200)
        self.hooks[0x48006200]=self.restore_cache

    def restore_cache(self,m):
        assert m.reg[4]==CACHE_DC and m.reg[5] in (0x9002,0x9003) and self.cached_alive
        return 0x9003 if m.reg[5]==0x9002 else 0x9002

    def word(self,pc):
        if pc==0x48006200:
            self.reg[2]=self.restore_cache(self);return 0x03e00008
        if pc==0x48006204:return 0
        return super().word(pc)

    def frame_api(self,iat):
        a0,a1,a2,a3=self.reg[4:8]
        if iat==0x1850dc:
            assert a0 in (2,4)
            return 0 if self.stock_failure else 0x9900+a0
        assert self.role=='gui' and a0==SURFACE
        if iat==0x1850f0:
            rect=tuple(self.read(a1+4*i) for i in range(4))
            assert rect in ((24,116,152,244),(25,117,151,243))
            assert a2 in (0x9902,0x9904)
            if self.fill_failure:return 0
            self.surface.paste((128,128,128) if a2==0x9902 else (0,0,0),rect)
            return 1
        if iat==0x185240:
            before=self.textcolor;self.textcolor=a1;return before
        if iat==0x185284:
            before=self.bkmode;self.bkmode=a1;return before
        assert iat==0x18509c and a2==9
        text=data(self,a1,a2*2).decode('utf-16-le')
        assert text=='Album art' and self.read(self.reg[29]+0x10)==0x25
        assert self.bkmode==1 and self.textcolor==0xaaaaaa
        rect=tuple(self.read(a3+i*4) for i in range(4))
        assert rect==(25,117,151,243)
        self.draw_caption.append(text)
        draw=ImageDraw.Draw(self.surface)
        draw.text((88,180),text,fill=(170,170,170),font=ImageFont.load_default(size=15),anchor='mm')
        return 18


def verify():
    candidate=(APP/'AppMain.exe').read_bytes();recipe=json.loads((APP/'recipe.json').read_bytes())
    blue,_=bluetooth.patch(bluetooth.SOURCE.read_bytes())
    app_raw=(PREVIOUS/'AppMain.exe').read_bytes();blue_raw=(PREVIOUS/'Blue.exe').read_bytes()
    traces=[]
    def pair():
        w=World();b=ArtworkBlue(pefile.PE(data=blue_raw),blue,w);a=App(app_raw,candidate,w,recipe)
        b.ranges += [(r['address'],r['address']+len(r['raw'])) for r in bt_helpers.assembled()]
        b.start();assert a.start()==1
        return w,b,a
    def record(name,w,b,a):
        assert a.textcolor==0xeeeeee and a.bkmode==2
        traces.append(dict(case=name,captions=len(a.draw_caption),copies=a.blit_count,
                           steps=a.steps+b.steps,native_reads=a.installed_reads+b.installed_reads))
        a.finish();b.stop();b.deliver_window()
        assert not w.handles and not w.views and w.shared is None

    w,b,a=pair();assert a.draw()==DRAW_RESULT
    assert a.window(15)==0x12345678
    assert a.screen.getpixel((24,116))==(128,128,128)
    assert a.screen.getpixel((30,125))==(0,0,0) and len(a.draw_caption)>=1
    assert a.screen.getpixel((200,140))==(230,230,230)
    assert a.screen.getpixel((23,180))==a.screen.getpixel((152,180))==(8,12,14)
    out=ROOT/'build/max07-artwork-verification-01';out.mkdir(exist_ok=True)
    a.screen.save(out/'player-placeholder.png')
    record('placeholder_is_visible_without_a_download_and_native_controls_remain',w,b,a)

    w,b,a=pair();a.write(DIALOG+0x78,DIALOG+0x80)
    assert a.draw()==DRAW_RESULT and not a.draw_caption
    assert a.surface.getpixel((88,180))==(120,80,40)
    record('popup_child_is_not_covered_by_placeholder',w,b,a)

    for mode in ('accepted','source_stop','disconnect','heartbeat_expired','stretch_failed','stock_failure'):
        w,b,a=pair()
        if mode=='stock_failure':
            a.stock_failure=True
            assert a.draw()==DRAW_RESULT and not a.draw_caption
        else:
            b.receive_image();b.deliver_window();assert a.run_worker()==0
            if mode=='stretch_failed':a.paint_fail='stretch_failed'
            assert a.window(worker.MESSAGE)==0
            if mode=='accepted':
                assert a.field(20) and a.screen.getpixel((88,180)) not in ((0,0,0),(8,12,14))
                a.screen.save(out/'player-fixture-cover.png')
            elif mode=='stretch_failed':
                assert a.screen.getpixel((30,125))==(0,0,0)
            else:
                if mode=='source_stop':b.command(0x1070505);b.handle()
                elif mode=='disconnect':b.disconnect_native();b.handle()
                else:a.now=5101
                assert a.window(15)==0x12345678 and not a.field(20) and not a.bitmaps
                assert a.screen.getpixel((24,116))==(128,128,128) and a.screen.getpixel((30,125))==(0,0,0)
        record('retained_cover_'+mode,w,b,a)
    report=dict(cases=len(traces),traces=traces,app_sha256=hashlib.sha256(candidate).hexdigest(),
                blue_sha256=hashlib.sha256(blue).hexdigest(),rectangle=[24,116,128,128],
                hardware_tested=False,native_executed=False,
                preview='Native instruction path with fixture GDI/font/control pixels; not device output',
                limits=['Phone cover support and physical CE font/rendering remain unverified'])
    (out/'verification.json').write_text(json.dumps(report,indent=2)+'\n')
    return report


if __name__=='__main__':
    r=verify();print(json.dumps(dict(cases=r['cases'],app_sha256=r['app_sha256']),indent=2))
