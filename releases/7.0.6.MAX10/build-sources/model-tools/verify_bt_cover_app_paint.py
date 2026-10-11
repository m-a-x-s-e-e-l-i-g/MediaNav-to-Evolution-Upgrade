"""Execute artwork drawing, retained Bluetooth thunk, native draw and buffer copy.

Generic window-message dispatch, background/child drawing, CE and GDI are strict
fixtures. Native helper instructions and retained draw/copy instructions execute;
pixels use a host image surface. No installed screen or LGU is claimed.
"""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile
from PIL import Image as PillowImage

import bt_cover_art_image as image
import bt_cover_art_worker as worker
import bt_cover_art_app_paint as paint
from inspect_bt_pairing import data,put
from verify_bt_cover_worker import App
from verify_bt_cover_transfer import World,Process
from verify_bt_cover_image import BITMAP,OLD,jpeg
from verify_media_responsiveness import call

ROOT=Path(__file__).resolve().parents[1]
DIALOG,VTABLE,CACHE=0x46000000,0x46001000,0x46002000
SURFACE,WINDOW_DC,PAINT_DC,CACHE_DC=0x7001,0x7002,0x8001,0x9001
DRAW_RESULT,LEGACY_RESULT=0xabcdef42,0x12345678
OS={paint.STRETCH:0x48000200,0x185248:0x48000210,0x1852a0:0x48000220,
    0x185280:0x48000230,0x185278:0x48000240}


@lru_cache(maxsize=1)
def helpers():return paint.assembled()


class PaintApp(App):
    def __init__(self,w,original):
        self.ui_trace=[]
        self.legacy_calls=[]
        self.paint_dcs={}
        self.paint_fail=None
        self.invalidate_at=None
        self.next_window_args=None
        self.surface=PillowImage.new('RGB',(800,480))
        self.screen=PillowImage.new('RGB',(800,480))
        self.blit_count=0
        self.cached_alive=False
        super().__init__(w,original)
        self.pe.helpers=helpers()
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in helpers() if r['address']>=paint.DRAW]
        self.ranges += [(paint.LEGACY_DRAW,0x134e80),(paint.LEGACY_WND,0x3c934),
                        (paint.BLIT,0x13d2ec),(0x134d28,0x134e1c),(0x140d04,0x140d14),
                        (0x140c14,0x140c24),(0x140c94,0x140ca4),(0x140cb4,0x140cc4)]
        self.allowed += [(DIALOG,DIALOG+0x100),(VTABLE,VTABLE+0x80),(CACHE,CACHE+0x20),
                         (paint.BT_GLOBAL,paint.BT_GLOBAL+4),(0x185400,0x185404),
                         (0x186ce0,0x186ce4),(0x1867a8,0x1867ac),(0x1853f4,0x1853f8)]
        put(self,DIALOG,bytes(0x100));put(self,VTABLE,bytes(0x80));put(self,CACHE,bytes(0x20))
        self.write(DIALOG,VTABLE);self.write(VTABLE+0x2c,0x2000c);self.write(VTABLE+0x30,0x20010)
        self.write(DIALOG+0x20,DIALOG);self.write(DIALOG+0x28,SURFACE)
        self.write(DIALOG+0x2c,WINDOW_DC);self.write(DIALOG+0x50,0x123456)
        self.write(DIALOG+0x68,1);self.write(DIALOG+0x6c,1)
        self.write(paint.BT_GLOBAL,DIALOG);self.write(0x185400,1)
        self.write(0x186ce0,CACHE);self.write(CACHE+0x14,CACHE_DC);self.write(CACHE+0x18,0x9002)
        self.write(0x1867a8,0);self.write(0x1853f4,0x11223344)
        self.hooks.update({0x13d098:self.background,0x13d164:self.children,0x2000c:self.draw_end,
                           0x20010:lambda m:0,0x134ed0:self.generic_window,
                           0x13fe40:self.cache_begin,0x140298:self.cookie})
        for at,target in OS.items():
            self.allowed.append((at,at+4));self.write(at,target)
            self.hooks[target]=lambda m,target=target:self.os_api(target)

    def activate(self,window=7,buffer=True):
        super().activate(window,buffer);self.set_field(64,DIALOG)

    def word(self,pc):
        if pc==paint.LEGACY_WND:
            self.next_window_args=self.reg[4:8][:]
            self.legacy_calls.append(self.next_window_args)
        if pc in OS.values():
            self.reg[2]=self.os_api(pc)&0xffffffff;return 0x03e00008
        if pc-4 in OS.values():return 0
        return super().word(pc)

    def background(self,m):
        assert self.role=='gui' and m.reg[4:6]==[DIALOG+4,0]
        self.ui_trace.append('background');self.surface.paste((8,12,14),(0,0,800,480))
        return 0

    def children(self,m):
        assert self.role=='gui' and m.reg[4] in (DIALOG+4,DIALOG+0x84)
        self.ui_trace.append('popup_children' if m.reg[4]==DIALOG+0x84 else 'children')
        if m.reg[4]==DIALOG+0x84:
            self.surface.paste((120,80,40),(0,80,800,260))
        else:
            # Fixed native controls outside the cover rectangle. Their pixels
            # provide evidence that the overlay and partial copy stay bounded.
            self.surface.paste((230,230,230),(163,132,637,182))
            self.surface.paste((120,120,120),(163,185,637,230))
            self.surface.paste((180,40,240),(163,256,637,325))
        return 0

    def draw_end(self,m):
        assert m.reg[4]==DIALOG;self.ui_trace.append('draw_end');return DRAW_RESULT

    def native(self,at,args):
        saved=self.reg[:],self.pc
        # Nested generic dispatch is a fixture. Allocate its stack below the
        # retained thunk's frame, preserving that caller's live arguments.
        self.reg[29]-=0x200
        self.reg[4:8]=args;self.reg[31]=0xbeef0000
        try:
            self.run(at,{0xbeef0000},limit=2000000)
            assert self.reg[29]==saved[0][29]-0x200
            return self.reg[2]
        finally:self.reg[:],self.pc=saved

    def generic_window(self,m):
        assert m.reg[4]==DIALOG
        args=[m.reg[5],m.reg[6],m.reg[7],m.read(m.reg[29]+0x10)]
        assert args==self.next_window_args,'Original Bluetooth thunk changed message arguments'
        self.ui_trace.append(('legacy',*args))
        if args[1]==15:
            self.native(0x134d28,[DIALOG,args[0],args[2],args[3]])
        return LEGACY_RESULT

    def cache_begin(self,m):
        assert m.reg[4]==0 and not self.cached_alive
        self.cached_alive=True;self.ui_trace.append('copy_cache_begin');return CACHE

    def cookie(self,m):
        assert m.reg[4]==0x11223344;return 0

    def gdi(self,pc):
        from verify_bt_cover_image import API
        which=next(at for at,target in API.items() if target==pc)
        if self.role=='worker' or which==image.DELETE_OBJECT:return super().gdi(pc)
        if which==image.CREATE_DC:
            assert self.reg[4]==0 and not self.paint_dcs
            self.ui_trace.append('paint_dc_create')
            if self.paint_fail=='dc_null':return 0
            self.paint_dcs[PAINT_DC]=None;return PAINT_DC
        if which==image.SELECT:
            dc,h=self.reg[4:6]
            if dc==CACHE_DC:
                assert self.cached_alive and h==0x9002;return 0x9003
            assert dc==PAINT_DC and dc in self.paint_dcs
            if h in self.bitmaps:
                assert self.paint_dcs[dc] is None and self.bitmaps[h].selected==OLD
                self.ui_trace.append('paint_select')
                if self.paint_fail=='select_null':return 0
                if self.paint_fail=='select_invalid':return 0xffffffff
                self.paint_dcs[dc]=h;self.bitmaps[h].selected=BITMAP
                if self.invalidate_at and self.invalidate_at[0]=='selected':
                    _,fn=self.invalidate_at;self.invalidate_at=None;fn()
                return 0x9003
            assert h==0x9003 and self.paint_dcs[dc] in self.bitmaps
            self.ui_trace.append('paint_restore')
            if self.paint_fail=='restore_null':return 0
            old=self.paint_dcs[dc];self.bitmaps[old].selected=OLD;self.paint_dcs[dc]=None
            return old
        assert which==image.DELETE_DC and self.reg[4]==PAINT_DC
        h=self.paint_dcs.pop(PAINT_DC)
        if h:self.bitmaps[h].selected=OLD
        self.ui_trace.append('paint_dc_delete');return 1

    def os_api(self,pc):
        at=next(at for at,target in OS.items() if target==pc)
        if at==paint.STRETCH:
            assert self.role=='gui'
            args=self.reg[4:8]+[self.read(self.reg[29]+i) for i in range(0x10,0x2c,4)]
            assert args==[SURFACE,*paint.RECT,PAINT_DC,0,0,200,200,0xcc0020]
            h=self.paint_dcs[PAINT_DC];assert h in self.bitmaps
            self.ui_trace.append('cover_stretch')
            if self.paint_fail=='stretch_failed':
                self.surface.paste((255,0,0),(24,116,88,244));return 0
            pixels=self.bitmaps[h].dib_pixels;assert pixels
            self.surface.paste(PillowImage.frombytes('RGB',(200,200),pixels).resize((128,128)),paint.RECT[:2])
            if self.invalidate_at and self.invalidate_at[0]=='stretched':
                _,fn=self.invalidate_at;self.invalidate_at=None;fn()
            return 1
        if at==0x185248:
            args=self.reg[4:8]+[self.read(self.reg[29]+i) for i in range(0x10,0x24,4)]
            dc,x,y,w,h,src,sx,sy,rop=args
            assert dc==WINDOW_DC and src==SURFACE and (sx,sy)==(x,y) and rop==0xcc0020
            assert self.cached_alive
            self.screen.paste(self.surface.crop((x,y,x+w,y+h)),(x,y))
            self.blit_count+=1;self.ui_trace.append(('native_buffer_copy',x,y,w,h));return 1
        if at==0x1852a0:
            assert self.reg[4]==CACHE and self.cached_alive
            self.cached_alive=False;self.ui_trace.append('copy_cache_free');return 0
        if at==0x185280:
            assert self.reg[4]==0x123456
            # Actual native WM_PAINT reads this fixture PAINTSTRUCT's rectangle.
            put(self,self.reg[5],bytes(64))
            for i,v in enumerate((0,0,800,480)):self.write(self.reg[5]+8+4*i,v)
            self.ui_trace.append('BeginPaint');return WINDOW_DC
        assert at==0x185278 and self.reg[4]==0x123456
        self.ui_trace.append('EndPaint');return 1

    def draw(self):
        self.role='gui';return call(self,paint.DRAW,[DIALOG],limit=2000000)

    def refresh(self):
        self.role='gui';return call(self,paint.REFRESH,[],limit=2000000)

    def window(self,msg,wp=0,lp=0,hwnd=0x123456):
        self.role='gui';return call(self,paint.WND,[hwnd,msg,wp,lp],limit=2000000)

    def finish(self):
        super().finish();assert not self.paint_dcs and not self.cached_alive


def verify(blue_raw,app_raw):
    contract=paint.contracts(app_raw)
    bp,ap=pefile.PE(data=blue_raw),pefile.PE(data=app_raw)
    rows=[]
    def pair():
        w=World();b=Process(w,'Blue.exe',bp);a=PaintApp(w,ap)
        assert b.initialize()==a.initialize()==1;a.activate()
        token=b.token();assert b.publish(token,jpeg())==1 and a.step()==1
        return w,b,a,token
    def record(name,w,b,a):
        rows.append(dict(case=name,native_copies=a.blit_count,trace=a.ui_trace[:],legacy_calls=a.legacy_calls[:]))
        a.finish();b.run_helper('close')
        assert not w.handles and not w.views and w.shared is None
    def cover(surface):return surface.getpixel((88,180))

    w,b,a,t=pair();assert a.take()==1 and a.draw()==DRAW_RESULT
    assert cover(a.surface)!=(8,12,14) and not a.paint_dcs
    assert a.surface.getpixel((200,140))==(230,230,230)
    assert a.surface.getpixel((200,200))==(120,120,120)
    assert a.surface.getpixel((200,280))==(180,40,240)
    assert a.surface.getpixel((23,180))==a.surface.getpixel((152,180))==(8,12,14)
    record('native_draw_return_and_cover_rectangle_preserve_existing_controls',w,b,a)

    w,b,a,t=pair();assert a.window(worker.MESSAGE)==0 and a.blit_count==1
    assert cover(a.screen)!=(8,12,14) and not a.legacy_calls and not a.field(16)
    count=len(a.ui_trace);assert a.window(0x113,paint.TIMER)==0 and len(a.ui_trace)==count
    record('pointer_free_wakeup_accepts_and_native_partial_copy_without_repeat_redraw',w,b,a)

    w,b,a,t=pair();a.fail_post=True;assert a.window(0x113,paint.TIMER)==0
    assert a.blit_count==1 and a.field(24)==t
    record('private_timer_accepts_an_owned_result',w,b,a)

    for mode in ('expired','invalidated'):
        w,b,a,t=pair();assert a.take()==1 and a.draw()==DRAW_RESULT
        if mode=='expired':a.now=5101
        else:b.invalidate()
        assert a.window(15)==LEGACY_RESULT
        assert cover(a.screen)==(8,12,14) and not a.field(20) and not a.bitmaps
        assert 'BeginPaint' in a.ui_trace and 'EndPaint' in a.ui_trace
        record('native_wm_paint_clears_'+mode+'_cached_cover_before_copy',w,b,a)

    for when in ('selected','stretched'):
        w,b,a,t=pair();assert a.take()==1
        a.invalidate_at=(when,b.invalidate)
        assert a.window(15)==LEGACY_RESULT
        assert cover(a.screen)==(8,12,14) and not a.field(20) and not a.bitmaps
        assert not a.paint_dcs
        record('generation_invalidated_after_'+when,w,b,a)

    w,b,a,t=pair();assert a.take()==1;a.write(DIALOG+0x78,DIALOG+0x80)
    assert a.window(15)==LEGACY_RESULT and cover(a.screen)==(120,80,40)
    assert 'cover_stretch' not in a.ui_trace and a.field(20)
    a.write(DIALOG+0x78,0);assert a.window(15)==LEGACY_RESULT and 'cover_stretch' in a.ui_trace
    record('original_popup_hierarchy_is_not_overpainted',w,b,a)

    for failure in ('dc_null','select_null','select_invalid','stretch_failed','restore_null'):
        w,b,a,t=pair();assert a.take()==1;a.paint_fail=failure
        assert a.window(15)==LEGACY_RESULT and not a.paint_dcs and len(a.bitmaps)==1
        assert cover(a.screen)==((8,12,14) if failure!='restore_null' else cover(a.surface))
        record('paint_failure_'+failure,w,b,a)

    for mode in ('inactive','wrong_window','no_surface','no_dialog'):
        w,b,a,t=pair();assert a.take()==1
        if mode=='inactive':a.set_field(12,0)
        if mode=='wrong_window':a.set_field(0,0x111111)
        if mode=='no_surface':a.write(DIALOG+0x28,0)
        if mode=='no_dialog':a.set_field(64,0)
        assert a.draw()==DRAW_RESULT and 'cover_stretch' not in a.ui_trace
        record('overlay_refused_'+mode,w,b,a)

    for at in (DIALOG+0x50,DIALOG+0x68,0x185400):
        w,b,a,t=pair();a.write(at,0)
        assert a.refresh()==1 and not a.blit_count and not a.cached_alive
        record('retained_native_copy_visibility_guard_'+hex(at),w,b,a)

    for msg,wp,lp,hwnd in ((0x113,0x3e9,0,0x123456),(worker.MESSAGE,1,0,0x123456),
                           (worker.MESSAGE,0,1,0x123456),(worker.MESSAGE,0,0,0x123457),
                           (5,77,0x11223344,0x123456)):
        w,b,a,t=pair();assert a.window(msg,wp,lp,hwnd)==LEGACY_RESULT
        assert a.legacy_calls==[[hwnd,msg,wp,lp]] and not a.blit_count and a.field(16)
        record('legacy_message_preserved_'+hex(msg)+'_'+hex(wp)+'_'+hex(lp)+'_'+hex(hwnd),w,b,a)

    return dict(cases=len(rows),traces=rows,contracts=contract,
                helpers=[{k:v for k,v in r.items() if k!='raw'} for r in helpers() if r['address']>=paint.DRAW],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Assembled overlay/refresh/window helpers and retained Bluetooth thunk, original draw and buffer-copy instructions execute',
                        'Generic window-message selection, background/child rendering, CE/COM/GDI and image pixels are explicit fixtures',
                        'Valid-object GDI destruction follows the retained decoder contract; actual CE codec or device paint is not executed',
                        'Existing controls retain their positions and dialog memory layout; the cover uses the blank title-side rectangle',
                        'Private timer creation and native thread startup/priority/shutdown/join bindings remain unimplemented',
                        'Executable permissions, relocations, unwind records and complete LGU installation remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in
                             ('bt_cover_art_app_paint.py','verify_bt_cover_app_paint.py','bt_cover_art_worker.py',
                              'verify_bt_cover_worker.py','bt_cover_art_image.py','verify_bt_cover_image.py',
                              'bt_cover_art_transfer.py','verify_bt_cover_transfer.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--blue',type=Path,required=True);p.add_argument('--app',type=Path,required=True)
    p.add_argument('--report',type=Path,required=True);args=p.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    report=verify(args.blue.read_bytes(),args.app.read_bytes());args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(report,indent=2)+'\n').encode())
    print(json.dumps(dict(cases=report['cases'],executable_written=False,lgu_built=False),indent=2))
