"""Execute native metadata timer delivery, pending-list removal and text cleanup.

Use original timer nodes, ordering, callbacks, queue restoration and pending
destructors. Host clock, allocator, wire, peer lookup and application publication
are fixtures. No retry helper, installed executable or LGU is produced here.
"""
import argparse
import hashlib
import json
from pathlib import Path
import bt_text_metadata_owner as owner
import bt_text_metadata_receive as receive
from verify_bt_text_metadata_disconnect import Disconnect
from verify_bt_text_metadata_receive import AVRCP,PREVIOUS,attribute,reply
from verify_bt_cover_task import SCHED
from verify_media_responsiveness import call
from inspect_bt_pairing import data,put

ROOT=Path(__file__).resolve().parents[1]
NATIVE=[(0x6a5ec,0x6a630),(0x6a7c0,0x6a858),(0x6a858,0x6a8d8),
        (0x6a630,0x6a6a4),(0x6a9d8,0x6aa30),(0x6aa30,0x6aaa8),
        (0x8145c,0x81478),(0x814a0,0x8151c),(0x81598,0x8161c)]


class Timed(Disconnect):
    def __init__(self,raw):
        super().__init__(raw)
        self.ranges+=NATIVE
        self.allowed += [(0x1030e0,0x103110)]
        put(self,0x1030e0,self.pe.original.get_data(0x1030e0-0x10000,48))
        for at in (0x6a858,0x814a0,0x81598):self.hooks.pop(at)
        call(self,0x6aa30,[self.peer+0xc8])
        assert self.read(self.peer+0x10c)==0x6a9d8

    def plain(self,word):
        # Original transaction-label rotation uses signed DIV/MFHI. Decode the
        # actual instructions; all unsupported opcodes still fail closed.
        if word>>26==0 and word&63==0x1a:
            signed=lambda n:n if n<0x80000000 else n-0x100000000
            a=signed(self.reg[(word>>21)&31]);b=signed(self.reg[(word>>16)&31])
            assert b!=0 and not (a==-0x80000000 and b==-1)
            q=(abs(a)//abs(b))*(-1 if (a<0)!=(b<0) else 1)
            self.lo=q&0xffffffff;self.hi=(a-q*b)&0xffffffff
        elif word>>26==0 and word&63==0x10:
            self.reg[(word>>11)&31]=self.hi;self.reg[0]=0
        else:super().plain(word)

    def free(self,m):
        pointer=m.reg[4];result=super().free(m)
        if isinstance(getattr(self,'pending',None),list) and pointer in self.pending:self.pending.remove(pointer)
        return result

    def schedule(self,parent,extra_us=200000):
        pending=next(p for p in self.pending if self.read(p+16)==parent)
        self.enter_queue(12);call(self,0x6a858,[self.peer+0x18,pending,extra_us])
        assert self.read(pending+12)!=0
        return pending

    def deliver_final(self):
        assert self.results
        return self.deliver(self.results[-1])

    def conclude(self):
        super().conclude()
        assert self.visits[0x81598] and self.visits[0x6a9d8]


def verify(raw):
    traces=[];body=attribute(1,b'Fresh title')
    def record(name,m,details):
        row=dict(case=name,details=details,fields=m.fields(),publications=len(m.publications),
                 failure_generation=m.read(receive.STATE+20),remaining_pending=len(m.pending),
                 timers=m.nodes(),callbacks=m.visits[0x6a5ec],destructors=m.visits[0x6a9d8])
        m.conclude();row['steps']=m.steps;traces.append(row)

    # The native setter adds 1.5 seconds to its argument: 200 ms is not the
    # complete timeout. Callback delivery must wait until the full 1.7 seconds.
    m=Timed(raw);parent=m.ordinary(bytes(8));pending=m.schedule(parent)
    nodes=m.nodes();assert len(nodes)==1
    assert nodes[0]['callback']==0x6a5ec and nodes[0]['owner']==pending
    assert nodes[0]['queue']==12 and nodes[0]['due']==1800000
    m.due(1799,1799999);assert pending in m.pending and not m.results
    m.due(1800,1800000);assert not m.pending and len(m.results)==1 and not m.nodes()
    assert m.read(owner.STATE+4)==parent and not m.deliver_final()
    assert data(m,AVRCP+0xee,260)==PREVIOUS and m.read(receive.STATE+20)==1
    record('native_timeout_posts_failure_then_application_drains',m,dict(timeout_us=1700000))

    for abort in (False,True):
        m=Timed(raw);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=body[:7]));assert len(m.nodes())==1
        if abort:m.write(AVRCP+0x248,0,1)
        assert not m.deliver(row);m.profile()
        assert len(m.nodes())==1 and m.acks[-1]['proceed']==int(not abort)
        m.due(1800,1800000);assert not m.pending and not m.nodes()
        assert not m.deliver_final() and data(m,AVRCP+0xee,260)==PREVIOUS
        record('native_fragment_timeout_'+('abort' if abort else 'continue'),m,None)

    m=Timed(raw);parent=m.ordinary(bytes(8))
    row=m.respond(parent,reply(1,body=body[:7]));assert not m.deliver(row);m.profile()
    timer=m.nodes()[0]['id']
    row=m.respond(parent,reply(3,body=body[7:]));assert not m.pending and not m.nodes()
    assert m.deliver(row)==1 and m.fields()==['Fresh title','','']
    before=len(m.results);m.due(1800,1800000);assert len(m.results)==before
    record('successful_final_cancels_timer_before_freeing_pending',m,dict(cancelled_timer=timer))

    m=Timed(raw);first=m.ordinary(bytes(8));m.schedule(first)
    m.at(500,500000);second=m.ordinary(bytes(8));m.schedule(second)
    m.write(AVRCP+0x248,0,1);m.due(1800,1800000)
    assert len(m.pending)==1 and len(m.nodes())==1 and not m.deliver_final()
    assert m.read(owner.STATE+4)==second and m.read(AVRCP+0x248,1)==0
    row=m.respond(second,reply(body=body));assert m.deliver(row)==1
    assert not m.nodes() and m.fields()==['Fresh title','','']
    record('old_timeout_cannot_reset_new_request_or_its_timer',m,None)

    m=Timed(raw);parent=m.ordinary(bytes(8));m.schedule(parent)
    m.begin_disconnect();assert not m.read(owner.STATE+4)
    m.due(1800,1800000);assert not m.deliver_final() and not m.pending
    assert data(m,AVRCP+0xee,260)==PREVIOUS
    record('invalidated_request_still_drains_via_native_timeout',m,None)

    # Native list destruction posts failure for a still-owned confirmation and
    # cancels the timer. It does not leave a callback pointing at freed storage.
    m=Timed(raw);parent=m.ordinary(bytes(8));pending=m.schedule(parent)
    m.enter_queue(12);call(m,0x81598,[m.peer+0xf8,pending])
    assert not m.pending and not m.nodes() and len(m.results)==1
    assert m.read(parent+20,2)==0x8007 and not m.deliver_final()
    record('native_pending_destructor_posts_failure_and_cancels_timer',m,None)

    # A timer replacement cancels the old node. It must not deliver a failure
    # at the earlier due time, or deliver two final confirmations later.
    m=Timed(raw);parent=m.ordinary(bytes(8));m.schedule(parent)
    old=m.nodes()[0]['id'];m.at(500,500000);m.schedule(parent)
    new=m.nodes()[0]['id'];assert old!=new and len(m.nodes())==1
    m.due(1800,1800000);assert not m.results and len(m.pending)==1
    m.due(2200,2200000);assert len(m.results)==1 and not m.pending
    assert not m.deliver_final();record('native_timer_replacement_delivers_once',m,dict(old=old,new=new))

    names=('verify_bt_text_metadata_timeout.py','verify_bt_text_metadata_receive.py',
           'verify_bt_text_metadata_disconnect.py','bt_text_metadata_owner.py',
           'bt_text_metadata_receive.py','bt_text_metadata_disconnect.py')
    return dict(cases=len(traces),traces=traces,baseline_sha256=hashlib.sha256(raw).hexdigest(),
                hardware_tested=False,executable_written=False,lgu_built=False,
                limits=['Native timer setter/canceller/delivery, timeout callback and pending-list allocation/removal/destructor execute',
                        'Clock values, allocation, wire serialization, peer lookup and application publication remain fixtures',
                        'Initial wire serialization is not executed: the no-response case explicitly invokes the original timer setter',
                        'Bounded retry, full disconnect/profile shutdown and PE/LGU installation remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True);p.add_argument('--report',type=Path,required=True);a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    r=verify(a.input.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode());print(json.dumps(dict(cases=r['cases']),indent=2))
