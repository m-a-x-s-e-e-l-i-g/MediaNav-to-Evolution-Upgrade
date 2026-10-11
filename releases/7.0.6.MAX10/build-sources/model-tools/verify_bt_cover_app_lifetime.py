"""Execute AppMain artwork window startup, priority, worker stop and checked join.

Thread creation/scheduling and CE APIs are fixtures. Worker, decoder, ownership,
draw and lifetime instructions execute. No installed executable or LGU is claimed.
"""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_app_lifetime as life
import bt_cover_art_app_paint as paint
import bt_cover_art_image as image
import bt_cover_art_worker as worker
from verify_bt_cover_app_paint import PaintApp,DIALOG,LEGACY_RESULT
from verify_bt_cover_transfer import World,Process
from verify_bt_cover_image import jpeg
from verify_media_responsiveness import call

ROOT=Path(__file__).resolve().parents[1]
OS={at:0x48000300+i*16 for i,at in enumerate((life.CREATE_THREAD,life.CREATE_EVENT,life.PRIORITY,
    life.RESUME,life.SET_TIMER,life.KILL_TIMER,life.EVENT_MODIFY))}
WORKER_STACK,GUI_STACK=0x69000000,0x6a000000


@lru_cache(maxsize=1)
def helpers():return life.assembled()


class LifetimeApp(PaintApp):
    def __init__(self,w,original):
        self.lifetime_trace=[]
        self.failure=None
        self.join_result=None
        self.thread_handle=0
        self.thread_suspended=False
        self.thread_completed=False
        self.priority_confirmed=False
        self.worker_result=None
        self.immediate_worker=False
        self.stop_inside_draw=False
        self.timers=set()
        self.legacy_create_result=LEGACY_RESULT
        super().__init__(w,original)
        self.pe.helpers=helpers()
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in helpers() if r['address']>=life.START]
        self.allowed += [(WORKER_STACK-0x1000,WORKER_STACK+0x80),(GUI_STACK-0x1000,GUI_STACK+0x80)]
        for at,target in OS.items():
            self.allowed.append((at,at+4));self.write(at,target)
            self.hooks[target]=lambda m,at=at:self.lifetime_api(at)

    def core(self,m,name):
        if name=='wait' and self.world.handles.get(m.reg[4])==(self.module,'thread'):
            assert self.role=='gui' and m.reg[5]==0
            self.lifetime_trace.append(('join',self.thread_completed,self.join_result))
            if self.join_result is not None:return self.join_result
            return 0 if self.thread_completed else 258
        if name=='wait' and self.world.handles.get(m.reg[4])==(self.module,'event'):
            assert self.role=='worker' and m.reg[5] in (0,worker.PERIOD)
            self.trace.append(('wait_stop',m.reg[5]))
            if self.fail_wait:return 0xffffffff
            if self.stop_signaled:return 0
            if m.reg[5]:
                self.periodic_waits+=1
                if self.periodic_waits>=self.max_periodic_waits:
                    self.stop_signaled=True;return 0
            return 258
        if name=='close' and self.world.handles.get(m.reg[4],(None,None))[1] in ('thread','event'):
            kind=self.world.handles[m.reg[4]][1]
            assert kind!='thread' or self.thread_completed,'Unjoined thread handle closed'
            assert not self.thread_handle or self.thread_completed,'Live worker event closed'
            self.lifetime_trace.append(('close',kind))
            if kind=='thread':self.thread_handle=0
        if name in ('unmap','close') and self.thread_handle:
            assert self.thread_completed,'Worker resources retired before actual join'
        return super().core(m,name)

    def lifetime_api(self,at):
        assert self.role=='gui'
        a=self.reg[4:8];self.lifetime_trace.append((hex(at),*a))
        if at==life.CREATE_EVENT:
            assert a==[0,1,0,0]
            if self.failure=='event':return 0
            self.stop_signaled=False;self.periodic_waits=0
            return self.world.new(self,'event')
        if at==life.SET_TIMER:
            assert a==[0x123456,paint.TIMER,worker.PERIOD,0]
            if self.failure=='timer':return 0
            actual=paint.TIMER+1 if self.failure=='timer_id' else paint.TIMER
            self.timers.add((a[0],actual));return actual
        if at==life.KILL_TIMER:
            assert (a[0],a[1]) in self.timers
            self.timers.remove((a[0],a[1]));return 1
        if at==life.CREATE_THREAD:
            assert a==[0,0,worker.THREAD,worker.STATE]
            assert self.read(self.reg[29]+0x10)==life.CREATE_SUSPENDED and self.read(self.reg[29]+0x14)==0
            assert self.field(12)==1 and self.field(68)==0 and self.field(60)==0
            if self.failure=='thread':return 0
            assert not self.thread_handle
            self.thread_handle=self.world.new(self,'thread');self.thread_suspended=True
            self.thread_completed=False;self.priority_confirmed=False;self.worker_result=None
            return self.thread_handle
        if at==life.PRIORITY:
            assert a[:2]==[self.thread_handle,life.BELOW_NORMAL&0xffffffff] and self.thread_suspended
            if self.failure in ('priority','priority_resume'):return 0
            self.priority_confirmed=True;return 1
        if at==life.RESUME:
            assert a[0]==self.thread_handle and self.thread_suspended
            if self.failure in ('resume','priority_resume'):return 0xffffffff
            self.thread_suspended=False
            # Priority failure resumes only a disabled entry to release resources.
            if self.immediate_worker or not self.field(12):self.run_worker()
            return 1
        assert at==life.EVENT_MODIFY and a[:2]==[self.field(4),life.EVENT_SET]
        self.world.checked(self,a[0],'event')
        if self.failure=='signal':return 0
        self.stop_signaled=True;return 1

    def word(self,pc):
        value=super().word(pc)
        if pc==image.DECODE and self.stop_inside_draw:
            d=self.decoder;draw=d.draw
            def stop_borrowed(m):
                result=draw(m)
                assert d.resources['image'] and self.buffer_live
                view=self.read(worker.CONFIG.state+8);event=self.field(4);thread=self.field(8)
                assert self.gui_native(life.STOP)==0
                assert d.resources['image'] and self.buffer_live and self.read(worker.CONFIG.state+8)==view
                assert self.field(4)==event and self.field(8)==thread
                self.lifetime_trace.append('stop_retained_borrowed_source_and_unjoined_resources')
                return result
            d.draw=stop_borrowed;self.stop_inside_draw=False
        return value

    def native_role(self,at,args,role,stack):
        saved=self.reg[:],self.pc,self.role
        self.role=role;self.reg[4:8]=list(args)+[0]*(4-len(args))
        self.reg[29]=stack;self.reg[31]=0xbeef0000
        try:
            self.run(at,{0xbeef0000},limit=4000000)
            assert self.reg[29]==stack
            return self.reg[2]
        finally:self.reg[:],self.pc,self.role=saved

    def run_worker(self):
        assert self.thread_handle and not self.thread_suspended and not self.thread_completed
        assert self.priority_confirmed or not self.field(12)
        self.worker_result=self.native_role(worker.THREAD,[worker.STATE],'worker',WORKER_STACK)
        assert not self.buffer_live and not self.com_count
        self.thread_completed=True;self.lifetime_trace.append(('worker_exited',self.worker_result))
        return self.worker_result

    def gui_native(self,at,args=()):return self.native_role(at,args,'gui',GUI_STACK)

    def generic_window(self,m):
        result=super().generic_window(m)
        if m.reg[6]==1:return self.legacy_create_result
        return result

    def start(self,hwnd=0x123456,dialog=DIALOG):
        self.role='gui';return call(self,life.START,[hwnd,dialog],limit=4000000)

    def stop(self):
        self.role='gui';return call(self,life.STOP,[],limit=4000000)

    def reap(self):
        self.role='gui';return call(self,life.REAP,[],limit=4000000)

    def window(self,msg,wp=0,lp=0,hwnd=0x123456):
        self.role='gui';return call(self,life.WND,[hwnd,msg,wp,lp],limit=4000000)

    def finish(self):
        self.join_result=None
        self.failure=None
        if self.thread_handle and not self.thread_completed:
            # A failed ResumeThread retains the suspended thread. Resolve it
            # explicitly in the fixture before proving final cleanup.
            self.thread_suspended=False;self.set_field(12,0);self.run_worker()
        assert self.stop()==1 and not self.thread_handle and not self.timers
        super().finish()


def verify(blue_raw,app_raw):
    contract=life.contracts(app_raw)
    bp,ap=pefile.PE(data=blue_raw),pefile.PE(data=app_raw)
    rows=[]
    def pair():
        w=World();b=Process(w,'Blue.exe',bp);a=LifetimeApp(w,ap)
        assert b.initialize()==1
        token=b.token();assert b.publish(token,jpeg())==1
        return w,b,a,token
    def record(name,w,b,a,**extra):
        rows.append(dict(case=name,lifetime=a.lifetime_trace[:],legacy_calls=a.legacy_calls[:],**extra))
        a.finish();b.run_helper('close')
        assert not w.handles and not w.views and w.shared is None

    w,b,a,t=pair();assert a.start()==1 and a.field(12)==a.field(68)==1 and a.field(44)==1
    assert a.field(8)==a.thread_handle and not a.thread_suspended and a.timers
    assert a.start()==1 and len([v for v in a.lifetime_trace if v[0]==hex(life.CREATE_THREAD)])==1
    assert a.run_worker()==0 and a.field(16) and a.window(worker.MESSAGE)==0 and a.field(24)==t
    assert a.window(15)==LEGACY_RESULT and a.blit_count==2
    assert a.stop()==1 and not a.field(16) and not a.field(20) and not a.bitmaps
    assert not a.thread_handle and not a.field(4) and not a.read(worker.CONFIG.state+8)
    record('suspended_start_checked_priority_native_worker_display_and_joined_stop',w,b,a)

    w,b,a,t=pair();a.immediate_worker=True
    assert a.window(1)==LEGACY_RESULT and a.thread_completed and a.field(16)
    assert a.window(worker.MESSAGE)==0 and a.window(2)==LEGACY_RESULT and not a.thread_handle
    assert a.legacy_calls[0]==[0x123456,1,0,0] and a.legacy_calls[-1]==[0x123456,2,0,0]
    record('legacy_create_then_worker_start_and_stop_before_legacy_destroy',w,b,a)

    for mode in ('mapping','event','timer','timer_id','thread','priority','resume','priority_resume'):
        w,b,a,t=pair()
        if mode=='mapping':w.fail='mapping'
        else:a.failure=mode
        assert a.start()==0 and a.field(12)==0 and not a.timers
        if mode in ('resume','priority_resume'):
            assert a.field(8) and a.field(4) and a.read(worker.CONFIG.state+8) and a.thread_suspended
            assert a.start()==0 and not a.thread_completed
        else:assert not a.field(8) and not a.field(4) and not a.read(worker.CONFIG.state+8)
        assert not a.decode_count
        w.fail=None;record('startup_failure_'+mode,w,b,a)

    w,b,a,t=pair();a.stop_inside_draw=True;assert a.start()==1 and a.run_worker()==0
    assert 'stop_retained_borrowed_source_and_unjoined_resources' in a.lifetime_trace
    assert not a.field(12) and not a.field(16) and not a.bitmaps
    assert a.field(8) and a.read(worker.CONFIG.state+8)
    assert a.reap()==1 and not a.field(8) and not a.read(worker.CONFIG.state+8)
    record('close_during_borrowed_decode_retains_storage_until_real_worker_exit',w,b,a)

    for join in (258,0xffffffff,128):
        w,b,a,t=pair();assert a.start()==1 and a.run_worker()==0
        a.join_result=join;view=a.read(worker.CONFIG.state+8);handle=a.field(8);event=a.field(4)
        assert a.stop()==0 and a.field(8)==handle and a.field(4)==event and a.read(worker.CONFIG.state+8)==view
        assert a.start()==0 and a.field(44)==1
        a.join_result=0;assert a.reap()==1 and not a.field(8) and not a.read(worker.CONFIG.state+8)
        record('unproved_join_retains_resources_'+hex(join),w,b,a)

    w,b,a,t=pair();assert a.start()==1 and a.stop()==0 and not a.thread_completed
    assert a.start()==0 and a.field(44)==1
    assert a.run_worker()==4 and a.reap()==1
    assert a.start()==1 and a.field(44)==2 and a.field(68)==1
    assert a.run_worker()==0 and a.window(worker.MESSAGE)==0 and a.field(24)==t
    record('rapid_window_reopen_waits_for_old_worker_before_new_generation',w,b,a)

    w,b,a,t=pair();assert a.start()==1;a.failure='signal'
    assert a.stop()==0 and a.field(8) and not a.field(12) and not a.stop_signaled
    assert a.run_worker()==4 and a.reap()==1
    record('failed_event_signal_still_blocks_early_resource_retirement',w,b,a)

    for result in (0,1,0xffffffff):
        w,b,a,t=pair();a.legacy_create_result=result
        assert a.window(1)==result
        assert bool(a.field(8))==(result!=0xffffffff)
        record('original_create_result_'+hex(result)+'_is_preserved',w,b,a)

    w,b,a,t=pair();a.set_field(44,0xffffffff)
    assert a.start()==0 and not a.field(8) and not a.timers and a.field(44)==0xffffffff
    record('window_generation_saturation_disables_without_wrap',w,b,a)

    for hwnd,dialog in ((0,DIALOG),(0x123456,0),(0x123456,DIALOG+4)):
        w,b,a,t=pair();assert a.start(hwnd,dialog)==0 and not a.field(8) and not a.timers
        record('invalid_start_binding_'+hex(hwnd)+'_'+hex(dialog),w,b,a)

    w,b,a,t=pair();assert a.start()==1
    assert a.window(2,hwnd=0x123457)==LEGACY_RESULT and a.field(12)==1 and a.timers
    record('foreign_destroy_preserves_current_worker',w,b,a)

    return dict(cases=len(rows),traces=rows,contracts=contract,
                helpers=[{k:v for k,v in r.items() if k!='raw'} for r in helpers() if r['address']>=life.START],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Assembled startup, checked priority, window hooks, worker/decoder/drawing, stop and nonblocking join instructions execute',
                        'CE API calls and thread scheduling are explicit fixtures; no actual device scheduling, codec or GDI execution',
                        'Pending/failed joins retain the event, thread handle, mapping and any late result until a later actual successful join',
                        'A failed ResumeThread may retain a suspended worker until process teardown; the feature stays disabled without native termination',
                        'Window registration and draw-slot executable edits, section permissions, relocations/unwind and complete LGU packaging remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in
                             ('bt_cover_art_app_lifetime.py','verify_bt_cover_app_lifetime.py',
                              'bt_cover_art_app_paint.py','verify_bt_cover_app_paint.py',
                              'bt_cover_art_worker.py','verify_bt_cover_worker.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--blue',type=Path,required=True);p.add_argument('--app',type=Path,required=True)
    p.add_argument('--report',type=Path,required=True);args=p.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    report=verify(args.blue.read_bytes(),args.app.read_bytes());args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(report,indent=2)+'\n').encode())
    print(json.dumps(dict(cases=report['cases'],executable_written=False,lgu_built=False),indent=2))
