"""Execute AppMain transfer, decoder, worker loop and GUI bitmap ownership.

Thread scheduling and CE/COM/GDI calls are fixtures. Actual assembled instructions
run through owned source snapshots and retained image import thunks. No native
window hooks, priority setup, screen paint or executable installation is claimed.
"""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_image as image
import bt_cover_art_worker as worker
import bt_cover_art_transfer as transfer
from inspect_bt_pairing import data,put
from verify_bt_cover_transfer import World,Process,OUTPUT
from verify_bt_cover_image import (Decoder,API as IMAGE_API,CREATE_FACTORY,CREATE_IMAGE,INFO,DRAW,
    RELEASE_IMAGE,RELEASE_FACTORY,BITMAP,SOURCE)
from verify_media_responsiveness import call

ROOT=Path(__file__).resolve().parents[1]
STOP_EVENT=0x6001
CORE_API={name:0x48000000+16*i for i,name in enumerate(transfer.ORDINALS)}
EXTRA_API={worker.MALLOC:0x48000100,worker.FREE:0x48000110,worker.CO_INIT:0x48000120,
           worker.CO_UNINIT:0x48000130,worker.CLOCK:0x48000140,worker.POST_MESSAGE:0x48000150}


@lru_cache(maxsize=1)
def helpers():return worker.assembled()


class App(Process):
    def __init__(self,w,original):
        self.original=original
        self.role='gui'
        self.decoder=None
        self.bitmaps={}
        self.heap={}
        self.buffer_live=False
        self.next_heap=0x43000000
        self.next_bitmap=0x2001
        self.trace=[]
        self.now=100
        self.fail_allocation=0
        self.fail_decode=None
        self.fail_com=0
        self.fail_post=False
        self.fail_claim=False
        self.immediate_take=False
        self.after_decode=None
        self.decode_count=0
        self.com_count=0
        self.stop_signaled=False
        self.periodic_waits=0
        self.max_periodic_waits=1
        self.fail_wait=False
        super().__init__(w,'AppMain.exe',original)
        self.pe.helpers=helpers()
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in helpers()]
        self.ranges += [(at,at+16) for at in IMAGE_API]
        self.allowed.append((worker.STATE,worker.STATE+worker.SIZE))
        put(self,worker.STATE,bytes(worker.SIZE))
        for name,iat in self.config.api.items():
            self.write(iat,CORE_API[name]);self.hooks[CORE_API[name]]=lambda m,name=name:self.core(m,name)
        for at,target in EXTRA_API.items():
            self.allowed.append((at,at+4));self.write(at,target)
        self.hooks.update({EXTRA_API[worker.MALLOC]:self.allocate,EXTRA_API[worker.FREE]:self.free,
                           EXTRA_API[worker.CO_INIT]:self.co_init,EXTRA_API[worker.CO_UNINIT]:self.co_uninit,
                           EXTRA_API[worker.CLOCK]:lambda m:self.now,EXTRA_API[worker.POST_MESSAGE]:self.post})

    def permitted(self,at,size):
        for lo,(n,alive) in self.heap.items():
            if lo<=at and at+size<=lo+n:
                assert alive,'Freed result descriptor accessed';return True
        return super().permitted(at,size)

    def read(self,at,size=4):
        if OUTPUT<=at<OUTPUT+transfer.MAX_IMAGE and not self.setup:
            assert self.buffer_live,'Freed encoded buffer read'
        return super().read(at,size)

    def write(self,at,value,size=4):
        if OUTPUT<=at<OUTPUT+transfer.MAX_IMAGE and not self.setup:
            assert self.buffer_live,'Freed encoded buffer written'
            if self.decoder and (self.decoder.resources.get('image') or self.decoder.resources.get('factory')):
                raise AssertionError('Decoder source mutated while borrowed')
        super().write(at,value,size)

    def field(self,offset):return self.read(worker.STATE+offset)

    def set_field(self,offset,value):self.write(worker.STATE+offset,value)

    def activate(self,window=7,buffer=True):
        self.set_field(0,0x123456);self.set_field(4,STOP_EVENT);self.set_field(12,1)
        self.set_field(44,window);self.set_field(68,1);self.set_field(72,window)
        if buffer:self.buffer_live=True;self.set_field(60,OUTPUT)

    def core(self,m,name):
        if name=='wait' and m.reg[4]==STOP_EVENT:
            assert self.role=='worker' and m.reg[5] in (0,worker.PERIOD)
            self.trace.append(('wait_stop',m.reg[5]))
            if self.fail_wait:return 0xffffffff
            if self.stop_signaled:return 0
            if m.reg[5]:
                self.periodic_waits+=1
                if self.periodic_waits>=self.max_periodic_waits:
                    self.stop_signaled=True;return 0
            return 258
        if name in ('compare','exchange') and m.reg[4]==worker.PENDING:
            self.trace.append(('result_'+name,self.role))
            old=self.read(worker.PENDING)
            if name=='compare' and self.fail_claim:
                self.fail_claim=False;return 0xffffffff
            if name=='exchange' or old==m.reg[6]:self.write(worker.PENDING,m.reg[5])
            if name=='compare' and m.reg[5] and self.immediate_take:
                self.immediate_take=False;self.gui_interleave()
            return old
        return self.world.invoke(m,name)

    def allocate(self,m):
        assert self.role=='worker'
        size=m.reg[4];assert size in (16,image.MAX_IMAGE)
        self.trace.append(('malloc',size))
        if self.fail_allocation==size:self.fail_allocation=0;return 0
        if size==image.MAX_IMAGE:
            assert not self.buffer_live;self.buffer_live=True;return OUTPUT
        at=self.next_heap;self.next_heap+=0x100;self.heap[at]=(16,True)
        put(self,at,bytes(16));return at

    def free(self,m):
        at=m.reg[4];self.trace.append(('free',hex(at),self.role))
        if at==OUTPUT:
            assert self.buffer_live and self.role=='worker'
            assert not self.decoder or not self.decoder.resources.get('image')
            self.buffer_live=False
        else:
            assert self.heap[at]==(16,True)
            self.heap[at]=(16,False)
        return 0

    def co_init(self,m):
        assert self.role=='worker' and m.reg[4:6]==[0,0] and not self.com_count
        self.trace.append(('CoInitializeEx',self.fail_com))
        if self.fail_com in (0,1):self.com_count=1
        return self.fail_com

    def co_uninit(self,m):
        assert self.role=='worker' and self.com_count==1
        self.com_count=0;self.trace.append('CoUninitialize');return 0

    def post(self,m):
        assert self.role=='worker' and m.reg[4:8]==[0x123456,worker.MESSAGE,0,0]
        self.trace.append('PostMessage');return int(not self.fail_post)

    def word(self,pc):
        if pc==image.DECODE:
            assert self.role=='worker' and self.buffer_live
            self.decode_count+=1
            encoded=data(self,SOURCE,self.field(52))
            d=Decoder(self.original,encoded,fail=self.fail_decode)
            self.decoder=d
            for lo,hi in d.allowed:
                if not SOURCE<=lo<SOURCE+image.MAX_IMAGE:self.allowed.append((lo,hi))
            for at,value in d.mem.items():
                if not SOURCE<=at<SOURCE+image.MAX_IMAGE:self.mem[at]=value
            d.read=self.read;d.write=self.write
            for at,name in ((CREATE_FACTORY,'factory'),(CREATE_IMAGE,'create_image'),(INFO,'info'),(DRAW,'draw'),
                            (RELEASE_IMAGE,'release_image'),(RELEASE_FACTORY,'release_factory')):
                self.hooks[at]=lambda m,name=name:getattr(self.decoder,name)(m)
        # Execute retained import tail stubs up to the strict GDI fixture.
        if pc in IMAGE_API.values():
            self.reg[2]=self.gdi(pc)&0xffffffff;return 0x03e00008
        if pc-4 in IMAGE_API.values():return 0
        if pc in (worker.STEP,worker.STEP+4):pass
        if self.after_decode and self.decoder and self.decoder.resources.get('bitmap') and worker.STEP<=pc<worker.STEP+0x2000:
            if not self.decoder.resources.get('factory') and not self.decoder.resources.get('dc'):
                fn=self.after_decode;self.after_decode=None;fn()
        return super().word(pc)

    def gdi(self,pc):
        which=next(at for at,target in IMAGE_API.items() if target==pc)
        if which==image.DELETE_OBJECT:
            handle=self.reg[4];d=self.bitmaps[handle]
            assert d.selected!=BITMAP,'Deleting selected bitmap'
            self.reg[4]=BITMAP
            try:result=d.delete_object(self)
            finally:self.reg[4]=handle
            del self.bitmaps[handle];self.trace.append(('DeleteObject',hex(handle),self.role))
            return result
        assert self.role=='worker' and self.decoder
        d=self.decoder
        name={image.CREATE_DC:'create_dc',image.CREATE_DIB:'create_dib',image.SELECT:'select',image.DELETE_DC:'delete_dc'}[which]
        if which==image.CREATE_DIB:
            result=d.create_dib(self)
            if result:
                d.native_bitmap=self.next_bitmap;self.next_bitmap+=1
                self.bitmaps[d.native_bitmap]=d;return d.native_bitmap
            return 0
        if which==image.SELECT:
            old=self.reg[5]
            if old==getattr(d,'native_bitmap',None):self.reg[5]=BITMAP
            try:result=d.select(self)
            finally:self.reg[5]=old
            return d.native_bitmap if result==BITMAP else result
        return getattr(d,name)(self)

    def gui_interleave(self):
        regs,pc,role=self.reg[:],self.pc,self.role
        self.role='gui';self.reg[31]=0xbeef0000
        try:self.run(worker.TAKE,{0xbeef0000},limit=2000000)
        finally:self.reg[:]=regs;self.pc=pc;self.role=role

    def step(self,window=None):
        self.role='worker'
        return call(self,worker.STEP,[self.field(44) if window is None else window],limit=2000000)

    def take(self):
        self.role='gui';return call(self,worker.TAKE,[],limit=2000000)

    def thread(self):
        self.role='worker';return call(self,worker.THREAD,[worker.STATE],limit=4000000)

    def finish(self):
        self.set_field(12,0);self.take()
        self.role='gui';call(self,worker.CLEAR,[])
        assert not self.field(16) and not self.field(20) and not self.bitmaps
        assert all(not live for _,live in self.heap.values())
        assert not self.com_count
        # Direct STEP tests model an already-owned worker buffer; actual THREAD
        # tests execute its allocation and free, so none remains after return.
        if self.buffer_live:
            self.role='worker';self.reg[4]=OUTPUT;self.free(self);self.set_field(60,0)
        self.run_helper('close')


def verify(blue_raw,app_raw):
    contract=worker.contracts(app_raw)
    originals={'Blue.exe':pefile.PE(data=blue_raw),'AppMain.exe':pefile.PE(data=app_raw)}
    rows=[]
    def pair(buffer=True):
        w=World();b=Process(w,'Blue.exe',originals['Blue.exe']);a=App(w,originals['AppMain.exe'])
        assert b.initialize()==a.initialize()==1;a.activate(buffer=buffer)
        return w,b,a
    def publish(b,raw=None,now=100):
        from verify_bt_cover_image import jpeg
        token=b.token(now);assert b.publish(token,jpeg() if raw is None else raw)==1;return token
    def record(name,w,b,a,**extra):
        row=dict(case=name,trace=a.trace[:],decode_count=a.decode_count,**extra)
        a.finish();b.run_helper('close')
        assert not w.handles and not w.views and w.shared is None
        rows.append(row)

    w,b,a=pair();token=publish(b);assert a.step()==1
    pending=a.field(16);h=a.read(pending+8)
    assert a.field(20)==0 and h in a.bitmaps and not a.bitmaps[h].resources['image']
    assert a.take()==1 and a.field(20)==h and a.field(24)==token and not a.field(16)
    assert a.step()==0 and a.decode_count==1 and a.take()==0
    record('owned_snapshot_decode_gui_acceptance_and_same_generation_coalescing',w,b,a)

    w,b,a=pair();token=publish(b);a.fail_post=True;assert a.step()==1 and a.field(16)
    assert a.take()==1 and a.field(24)==token
    record('lost_wakeup_result_remains_owned_for_gui_timer',w,b,a)

    w,b,a=pair();publish(b);w.owner='Blue.exe';assert a.step()==0 and not a.decode_count
    w.owner=None;assert a.step()==1 and a.take()==1
    record('busy_mapping_retry_without_decode_or_owned_result_growth',w,b,a)

    w,b,a=pair();publish(b);assert a.step()==1;old=a.field(16)
    assert a.step()==0 and a.field(16)==old and a.decode_count==1
    assert a.take()==1;record('one_pending_result_blocks_additional_decoding',w,b,a)

    w,b,a=pair();publish(b);assert a.step()==a.take()==1;first=a.field(20)
    second=publish(b,now=101);a.now=101;assert a.step()==a.take()==1
    assert first not in a.bitmaps and a.field(24)==second and len(a.bitmaps)==1
    record('replacement_deletes_previous_unselected_gui_bitmap',w,b,a)

    for when in ('after_decode','queued','displayed'):
        w,b,a=pair();publish(b)
        if when=='after_decode':a.after_decode=lambda:b.invalidate();assert a.step()==0
        else:
            assert a.step()==1
            if when=='displayed':assert a.take()==1
            b.invalidate()
        changed=a.take()
        assert not a.field(20) and not a.field(16) and not a.bitmaps
        record('invalidation_'+when,w,b,a,gui_changed=changed)

    w,b,a=pair();publish(b);assert a.step()==1;a.set_field(44,8)
    assert a.take()==0 and not a.bitmaps and not a.field(20)
    record('old_window_generation_result_is_deleted',w,b,a)

    w,b,a=pair();publish(b);assert a.step()==a.take()==1;a.now=5101
    assert a.take()==1 and not a.field(20) and not a.bitmaps
    record('expired_heartbeat_clears_owned_display_bitmap',w,b,a)

    for failure in ('bad_encoding','draw_error','descriptor_allocation','slot_claim'):
        w,b,a=pair();publish(b,b'nope' if failure=='bad_encoding' else None)
        if failure=='draw_error':a.fail_decode='draw_error'
        if failure=='descriptor_allocation':a.fail_allocation=16
        if failure=='slot_claim':a.fail_claim=True
        assert a.step()==0 and not a.bitmaps and not a.field(16)
        if failure in ('bad_encoding','draw_error'):
            assert a.step()==0 and a.decode_count==1
        else:
            assert a.step()==1 and a.decode_count==2 and a.take()==1
        record('failed_'+failure,w,b,a)

    w,b,a=pair();publish(b);a.immediate_take=True;assert a.step()==1
    assert not a.field(16) and a.field(20) and len(a.bitmaps)==1
    record('gui_consumes_descriptor_before_slot_cas_returns',w,b,a)

    for com in (0,1,0x80004005,0x80010106):
        w,b,a=pair(buffer=False);publish(b);a.fail_com=com
        result=a.thread()
        assert result==(0 if com in (0,1) else 1) and not a.buffer_live and not a.com_count
        if com in (0,1):assert a.field(16) and a.decode_count==1 and a.take()==1
        else:assert not a.decode_count and not a.field(16)
        record('thread_com_result_'+hex(com),w,b,a)

    for mode in ('allocation','wait','priority_unconfirmed','inactive','window_zero','no_event'):
        w,b,a=pair(buffer=False);publish(b)
        expected=4
        if mode=='allocation':a.fail_allocation=image.MAX_IMAGE;expected=2
        if mode=='wait':a.fail_wait=True;expected=3
        if mode=='priority_unconfirmed':a.set_field(68,0)
        if mode=='inactive':a.set_field(12,0)
        if mode=='window_zero':a.set_field(44,0)
        if mode=='no_event':a.set_field(4,0)
        assert a.thread()==expected and not a.buffer_live and not a.com_count and not a.decode_count
        record('thread_refusal_'+mode,w,b,a)

    return dict(cases=len(rows),traces=rows,contracts=contract,
                helpers=[{k:v for k,v in r.items() if k!='raw'} for r in helpers() if r['address']>=worker.THREAD],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Assembled AppMain mapping, checked decoder, worker loop and GUI ownership helpers execute in the MIPS interpreter',
                        'COM/GDI, allocation/free, clocks, stop-event waits and thread scheduling are strict fixtures; pixels are host decoded',
                        'A confirmed lower priority is a caller precondition; native thread creation/priority setup and joining remain unimplemented',
                        'GUI timer/window hooks and fresh paint remain unimplemented; no physical bitmap display is claimed',
                        'Source is owned until IImage release; GUI owns at most one displayed bitmap and one pending result descriptor',
                        'Cleanup retains normal valid-object and handle destruction contracts; PE permissions/relocations/unwind and LGU installation remain open'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_worker.py','verify_bt_cover_worker.py','bt_cover_art_transfer.py','verify_bt_cover_transfer.py',
                              'bt_cover_art_image.py','verify_bt_cover_image.py','verify_bt_cover_csr_bridge.py',
                              'verify_media_responsiveness.py','verify_bt_cover_owner.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--blue',type=Path,required=True);p.add_argument('--app',type=Path,required=True)
    p.add_argument('--report',type=Path,required=True);args=p.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    report=verify(args.blue.read_bytes(),args.app.read_bytes());args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(report,indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=report['cases'],executable_written=False,lgu_built=False),indent=2))
