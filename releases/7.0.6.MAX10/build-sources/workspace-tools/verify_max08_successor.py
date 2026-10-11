"""Execute successor bindings, native BlueEarth publication and popup painter.

Wire/CE/GDI/phone support are fixtures. Native reply dispatch, shared-map address
calculation, AppMain metadata reader and popup child visibility walker execute.
"""
import json
import struct
import sys
from pathlib import Path
from functools import lru_cache

import patch_max08_successor as patcher
sys.path.insert(0,str(patcher.REPO/'tools'))
import pefile
import layout_bt_cover_native as layout
layout.plan = lru_cache(maxsize=4)(layout.plan)
from verify_max07_bluetooth import Text
from verify_max07_artwork import App
from verify_bt_cover_install import World
from verify_bt_cover_app_paint import DIALOG, VTABLE, DRAW_RESULT
from verify_bt_cover_metadata_ticket import PROFILE
from verify_bt_text_metadata_receive import AVRCP, APP_ID, attribute, reply
from verify_media_responsiveness import call, VM, STACK
from inspect_bt_pairing import put, data
from inspect_av_layouts import LayoutVM
import bt_cover_art_worker as worker

BANK = 0x4c000000


class NativeText(Text):
    def __init__(self,raw,candidate):
        super().__init__(raw,candidate)
        self.ranges += [(0x1eb50,0x1eca8),(0x348d4,0x3496c),(0x34310,0x3435c)]
        self.allowed += [(0x20e1f8,0x20e208),(BANK+0xcf0e8,BANK+0xcf0e8+260)]
        self.write(0x20e200,BANK)
        put(self,BANK+0xcf0e8,bytes(260))
        self.hooks.pop(0x1eb50)
        self.hooks[0x8ac04] = self.copy
        self.hooks[0x8acbc] = lambda m:int(self.cstring(m.reg[4],m.reg[6])!=self.cstring(m.reg[5],m.reg[6]))
        self.hooks[0x33538] = self.notify

    def plain(self,word):
        if word>>26==0 and word&63==0x19:
            rs,rt=(word>>21)&31,(word>>16)&31
            product=(self.reg[rs]&0xffffffff)*(self.reg[rt]&0xffffffff)
            self.hi,self.lo=product>>32,product&0xffffffff
        else:super().plain(word)

    def notify(self,m):
        assert m.reg[4:7]==[2,0x1070f02,0]
        self.publications.append(data(self,BANK+0xcf0e8,260).hex())
        return 0

    def profile(self):
        self.enter_queue(12)
        while self.profile_requests:
            request=self.profile_requests.popleft()
            self.write(PROFILE+12,request)
            table=0x101eb0 if self.read(request,2)==0x20c else 0x101eb4
            target=int.from_bytes(self.candidate.get_data(table-0x10000,4),'little')
            call(self,target,[PROFILE],limit=30000)
            self.reg[4]=request;self.free(self)

    def respond(self,parent,packet):
        pending=next(p for p in self.pending if self.read(p+16)==parent)
        source=self.new(packet);self.enter_queue(12)
        word=int.from_bytes(self.candidate.get_data(0x712a0-0x10000,4),'little')
        assert word>>26==3
        entry=(word&0x3ffffff)<<2
        call(self,entry,[self.peer,pending,len(packet),source],limit=30000)
        self.reg[4]=source;self.free(self)
        return self.results[-1] if not any(self.read(p+16)==parent for p in self.pending) else self.fragments[-1]


def consume(app_raw,metadata):
    m=LayoutVM(pefile.PE(data=app_raw),[(0x1137d0,0x113920),(0x11afcc,0x11b044)])
    obj=0x46003000
    m.write(obj+12,BANK)
    put(m,BANK+0xcf0e8,metadata)
    m.write(0x185088,0xf0000040);m.write(0x1852bc,0xf0000050)
    conversions=[]
    def zero(vm):
        at,value,n=vm.reg[4:7];put(vm,at,bytes([value&255])*n);return at
    def convert(vm):
        assert vm.reg[4:6]==[65001,8] and vm.reg[7]==50
        dest,n=vm.read(vm.reg[29]+16),vm.read(vm.reg[29]+20)
        assert n==50
        text=data(vm,vm.reg[6],50).decode('utf-8')
        encoded=text.encode('utf-16-le')
        assert len(encoded)<=100
        put(vm,dest,encoded);conversions.append(text.split('\0')[0]);return len(encoded)//2
    m.hooks.update({0x140de4:zero,0xf0000040:convert,0xf0000050:lambda _:0})
    call(m,0x1137d0,[obj],limit=10000)
    assert len(conversions)==3
    return conversions,m.steps


class PopupApp(App):
    def plain(self,word):
        if word>>26==0 and word&63==0x2a:
            rs,rt,rd=(word>>21)&31,(word>>16)&31,(word>>11)&31
            signed=lambda v:v if v<0x80000000 else v-0x100000000
            self.reg[rd]=int(signed(self.reg[rs])<signed(self.reg[rt]));self.reg[0]=0
        else:super().plain(word)

    def run(self,start,stops,limit=5000):
        # Same bounded runner as the existing fixture, plus architectural BLEZ
        # used by native container drawing. Read original candidate instructions.
        self.pc=start;initial=self.steps
        while self.pc not in stops:
            assert self.steps-initial<limit
            pc=self.pc;word=self.word(pc)
            op,rs,rt,fn=word>>26,(word>>21)&31,(word>>16)&31,word&63
            if not (op in (2,3,4,5,6) or op==0 and fn in (8,9)):
                self.plain(word);self.pc+=4;self.steps+=1;continue
            hook=None
            if op in (4,5,6):
                offset=word&65535
                if offset>=32768:offset-=65536
                value=self.reg[rs];value=value if value<0x80000000 else value-0x100000000
                taken=value<=0 if op==6 else (self.reg[rs]==self.reg[rt])==(op==4)
                target=pc+4+offset*4 if taken else pc+8
            elif op==0:
                target=self.reg[rs]
                if fn==9:
                    self.reg[(word>>11)&31]=pc+8;hook=self.hooks.get(target)
                    assert hook or self.internal_call(target),hex(target)
            else:
                target=((pc+4)&0xf0000000)|((word&0x3ffffff)<<2)
                if op==3:
                    self.reg[31]=pc+8;hook=self.hooks.get(target)
                    assert hook or self.internal_call(target),hex(target)
            self.pc=pc+4;self.plain(self.word(pc+4));self.steps+=2
            if hook is not None:
                self.reg[2]=hook(self)&0xffffffff;self.pc=pc+8
            else:self.pc=target
        return self.pc

    def __init__(self,raw,candidate,w,recipe):
        super().__init__(raw,candidate,w,recipe)
        self.ranges += [(0x13d164,0x13d220),(0x14638,0x146a4),(0x3b170,0x3b198),(0x134e80,0x134ed0)]
        self.allowed += [(0x18630c,0x186310),(DIALOG+0x200,DIALOG+0x300)]
        self.write(VTABLE+0x24,int.from_bytes(self.candidate.get_data(0x150c44-0x10000,4),'little'))
        self.popup_draws=0
        self.hooks[0x13d164]=self.visible_children
        self.hooks[0x20020]=self.popup_control
        # Follow the real cached popup singleton and constructor assignment.
        self.write(0x18630c,DIALOG+0x80)
        self.reg[29]=STACK;self.reg[19]=DIALOG
        self.run(0x3b170,{0x3b198},limit=2000)
        assert self.read(DIALOG+0x78)==DIALOG+0x80
        self.write(DIALOG+0x88,DIALOG+0x200)
        self.write(DIALOG+0x8c,1)
        self.write(DIALOG+0x200,DIALOG+0x220)
        self.write(DIALOG+0x220,DIALOG+0x280)
        self.write(DIALOG+0x280+0x1c,0x20020)
        self.show_popup(False)

    def show_popup(self,visible): self.write(DIALOG+0x220+0x2c,0x80 if visible else 0)

    def visible_children(self,m):
        if m.reg[4]==DIALOG+4:return super().children(m)
        assert m.reg[4]==DIALOG+0x84
        hook=self.hooks.pop(0x13d164)
        try:return self.native(0x13d164,[m.reg[4],0,0,0])
        finally:self.hooks[0x13d164]=hook

    def popup_control(self,m):
        assert m.reg[4]==DIALOG+0x220
        self.surface.paste((120,80,40),(0,80,800,260))
        self.popup_draws+=1
        return 0

    def initial_draw(self):
        self.role='gui'
        return call(self,0x134e80,[DIALOG],limit=2000000)


def verify():
    out=patcher.OUT
    recipes=json.loads((out/'recipe.json').read_bytes())
    blue=(out/'Blue.exe').read_bytes();app=(out/'AppMain.exe').read_bytes()
    raw=(patcher.NATIVE/patcher.SYSTEM/'Blue.exe').read_bytes()
    native_text=[]
    cases=[('single-title',attribute(1,b'Native Spotify title'),1,['Native Spotify title','','']),
           ('all-text',attribute(7,b'123456')+attribute(2,b'Artist')+attribute(1,b'Title')+attribute(3,b'Album'),4,['Title','Album','Artist']),
           ('empty-optional-fields',attribute(1,b'Playing')+attribute(2,b'')+attribute(3,b''),3,['Playing','','']),
           ('unicode',attribute(1,'Muziek \u266b'.encode())+attribute(2,'Bj\u00f6rk'.encode()),2,['Muziek \u266b','','Bj\u00f6rk']),
           ('native-charset-tolerance',attribute(1,b'Title').replace(b'\x00\x6a',b'\x00\x00'),1,['Title','',''])]
    for name,body,count,expected in cases:
        m=NativeText(raw,blue);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(body=body,count=count));assert m.deliver(row)==1,(name,m.fields(),row)
        assert m.fields()==expected
        metadata=data(m,BANK+0xcf0e8,260)
        text,steps=consume(app,metadata);assert text==expected
        assert not m.pending and not m.profile_requests and not m.nodes()
        native_text.append(dict(case=name,fields=text,steps=m.steps+steps,native_publication=True))
        m.conclude()
    m=NativeText(raw,blue);parent=m.ordinary(bytes(8))
    first=m.respond(parent,reply(1,body=attribute(1,b'First')))
    assert m.deliver(first)==1;m.profile()
    final=m.respond(parent,reply(3,body=attribute(1,b'Next')))
    assert m.deliver(final)==1 and m.fields()[0]=='Next'
    assert consume(app,data(m,BANK+0xcf0e8,260))[0][0]=='Next'
    assert not m.pending and not m.profile_requests and not m.nodes()
    native_text.append(dict(case='native-interim-ACK-final-drain',fields=m.fields(),steps=m.steps))
    m.conclude()
    m=NativeText(raw,blue);put(m,AVRCP+0xee,bytes(260))
    for uid,title in ((bytes(8),b'First track'),(b'12345678',b'Skipped track'),(b'\0abcdefg',b'Another player')):
        m.live(uid);m.queue_ordinary();m.profile()
        parent=m.serialized[-1]['confirmation']
        row=m.respond(parent,reply(body=attribute(1,title)+attribute(2,b'')+attribute(3,b''),count=3))
        assert m.deliver(row)==1
        assert consume(app,data(m,BANK+0xcf0e8,260))[0]==[title.decode(),'','']
    assert not m.pending and not m.profile_requests and not m.nodes()
    native_text.append(dict(case='initial-empty-title-native-producer-and-three-track-updates',fields=m.fields(),steps=m.steps))
    m.conclude()
    # A failed native result preserves the previous title and drains resources.
    m=NativeText(raw,blue);before=m.fields();parent=m.ordinary(bytes(8))
    row=m.respond(parent,reply(body=attribute(1,b'Bad'),ctype=10));assert not m.deliver(row)
    assert m.fields()==before and not m.pending
    native_text.append(dict(case='failed-result-preserves-text',fields=m.fields(),steps=m.steps));m.conclude()
    art=[]
    app_original=(patcher.NATIVE/patcher.SYSTEM/'AppMain.exe').read_bytes()
    for binary_name,binary in (('MAX07', (patcher.PREVIOUS/patcher.SYSTEM/'AppMain.exe').read_bytes()),('MAX08',app)):
        w=World();a=PopupApp(app_original,binary,w,recipes['AppMain.exe'])
        assert a.start()==1
        a.initial_draw();a.window(15)
        visible=a.screen.getpixel((24,116))==(128,128,128)
        assert visible==(binary_name=='MAX08')
        art.append(dict(case='persistent-hidden-popup-'+binary_name,placeholder_visible=visible,
                        native_constructor_popup_assignment=True,native_child_visibility=True))
        if binary_name=='MAX08':
            a.screen.save(out/'player-placeholder.png')
            a.show_popup(True);assert a.draw()==DRAW_RESULT;a.window(15)
            assert a.screen.getpixel((88,180))==(120,80,40) and a.popup_draws
            a.show_popup(False);assert a.draw()==DRAW_RESULT;a.window(15)
            assert a.screen.getpixel((24,116))==(128,128,128)
            art.append(dict(case='popup-visible-then-hidden',popup_draws=a.popup_draws,placeholder_returns=True))
        a.finish();assert not w.handles and not w.views
    # Real installed worker/mapping/decoder path; phone cover is an injected fixture.
    from verify_bt_text_recovery_install import ArtworkBlue
    for mode in ('accepted','stale','stretch-failure'):
        w=World();b=ArtworkBlue(pefile.PE(data=raw),blue,w)
        a=PopupApp(app_original,app,w,recipes['AppMain.exe'])
        b.start();assert a.start()==1
        b.receive_image();b.deliver_window();assert a.run_worker()==0
        if mode=='stretch-failure':a.paint_fail='stretch_failed'
        assert a.window(worker.MESSAGE)==0
        if mode=='accepted':
            assert a.screen.getpixel((88,180)) not in ((0,0,0),(8,12,14))
            a.screen.save(out/'player-fixture-cover.png')
        elif mode=='stale':
            a.now=5101;a.window(15)
            assert not a.field(20) and a.screen.getpixel((30,125))==(0,0,0)
        else: assert a.screen.getpixel((30,125))==(0,0,0)
        art.append(dict(case='cover-'+mode,hidden_popup_pointer_present=True,steps=a.steps+b.steps))
        a.finish();b.stop();b.deliver_window();assert not w.handles and not w.views
    # AppMain relocation must preserve both literal colors and modified pointers.
    from verify_usb_input_safety import relocated
    from patch_shared_mapping_checks import reloc_records
    p=pefile.PE(data=app);before=pefile.PE(data=(patcher.PREVIOUS/patcher.SYSTEM/'AppMain.exe').read_bytes())
    for delta in (0x1000,0x8000,0x10000,0x123000):
        q=pefile.PE(data=relocated(app,delta));old=pefile.PE(data=relocated(before.__data__,delta))
        for at,n in ((0x33f000,0x1000),(0x13ed30,8),(0x13ed54,8),(0x13f29c,8)):
            assert q.get_data(at-0x10000,n)==old.get_data(at-0x10000,n)
        d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        rows=list(struct.iter_unpack('<5I',p.get_data(d.VirtualAddress,d.Size)))
        assert list(struct.iter_unpack('<5I',q.get_data(d.VirtualAddress,d.Size)))==[tuple(v+delta if v else 0 for v in r) for r in rows]
        for f in recipes['AppMain.exe']['functions']:
            for at,kind,_ in f['relocations']:
                assert any(r[0]==at and r[1]==kind for r in reloc_records(p))
    report=dict(blue_sha256=patcher.sha(blue),app_sha256=patcher.sha(app),native_text=native_text,artwork=art,
                rebases=4,label_helpers_lookup_hooks_equal_MAX07=True,audio_equal_MAX07=True,
                hardware_tested=False,native_executed=False,
                limits=['Native instructions run in a bounded interpreter; CE, wire and GDI are fixtures',
                        'No phone trace: native text route restoration is a compatibility experiment',
                        'Phone cover server support and real Bluetooth artwork delivery remain unverified'])
    (out/'verification.json').write_text(json.dumps(report,indent=2)+'\n')
    return dict(text_cases=len(native_text),artwork_cases=len(art),rebases=4)


if __name__=='__main__':print(json.dumps(verify(),indent=2))
