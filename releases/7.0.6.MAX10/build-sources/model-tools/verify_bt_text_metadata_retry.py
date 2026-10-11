"""Execute delayed text retries with native timers, factories and profile cleanup."""
import argparse
import hashlib
import json
from pathlib import Path
import bt_text_metadata_retry as retry
import bt_text_metadata_owner as owner
import bt_cover_art_selection as selection
from verify_bt_text_metadata_shutdown import Shutdown
from verify_bt_text_metadata_receive import AVRCP,PREVIOUS,attribute,reply
from verify_bt_cover_metadata_ticket import PROFILE
from verify_media_responsiveness import call
from inspect_bt_pairing import data,put

ROOT=Path(__file__).resolve().parents[1]


class Retrying(Shutdown):
    def __init__(self,raw):
        self.fail_retry=False
        super().__init__(raw)
        rows=retry.assembled()+[r for r in selection.assembled() if r['address']==selection.REQUEST]
        self.pe.helpers+=rows;self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in rows]
        self.allowed += [(retry.STATE-4,retry.STATE+retry.SIZE+4),
                         (selection.REQUEST_TABLE,selection.REQUEST_TABLE+4)]
        put(self,retry.STATE-4,b'RET0'+bytes(retry.SIZE)+b'RET1')
        self.write(AVRCP+0x20c,1,1);self.write(self.peer+0x1e,3,1)
        self.patches.update(retry.sites(raw));self.write(selection.REQUEST_TABLE,retry.PROFILE)

    def allocate(self,m):
        if self.fail_retry and retry.WAKE<=m.pc<retry.WAKE+0xc00 and m.reg[4]==20:
            self.fail_retry=False;return 0
        return super().allocate(m)

    def profile(self):
        self.enter_queue(12)
        while self.profile_requests:
            request=self.profile_requests.popleft();self.write(PROFILE+12,request)
            at=retry.PROFILE if self.read(request,2)==0x20c else owner.ACK_PROFILE
            call(self,at,[PROFILE],limit=30000)
            self.reg[4]=request;self.free(self)

    def drop(self):
        token=self.read(retry.STATE+16);result=super().drop(retry.DROP)
        assert not self.read(retry.STATE) and not self.read(retry.STATE+12)
        assert not self.read(retry.STATE+20) and not self.read(retry.STATE+24)
        assert self.read(retry.STATE+16)==token
        return result

    def conclude(self):
        self.profile();self.enter_queue(7);call(self,retry.STOP,[])
        self.finish_pending()
        assert not self.read(retry.STATE+20)
        assert data(self,retry.STATE-4,4)==b'RET0' and data(self,retry.STATE+retry.SIZE,4)==b'RET1'
        super().conclude()


def verify(raw,fixture=Retrying):
    cases=[];good=attribute(1,b'Fresh title')
    def fail(m,parent,empty=False):
        packet=reply(body=attribute(1,b'') if empty else good,ctype=9 if empty else 10)
        row=m.respond(parent,packet)
        assert m.deliver(row)==int(empty)
        assert not m.pending and not m.read(owner.STATE+4)
        return row
    def record(name,m,details=None):
        cases.append(dict(case=name,attempts=m.read(retry.STATE+8),queued=len(m.profile_requests),
                          fields=m.fields(),posts=len(m.ordinary_posts),details=details,steps=m.steps,
                          native_reads=getattr(m,'installed_reads',None),native_writes=getattr(m,'installed_writes',None)))
        m.conclude()

    for empty in (False,True):
        m=fixture(raw);parent=m.ordinary(bytes(8));fail(m,parent,empty)
        node=m.nodes()[0];assert node['queue']==7 and node['due']==600000
        m.due(599,599999);assert not m.profile_requests
        m.due(600,600000);assert len(m.profile_requests)==1 and m.read(retry.STATE+8)==1
        m.profile();assert m.read(owner.STATE)==2 and m.read(retry.STATE)==2 and m.read(retry.STATE+8)==1
        assert not m.read(retry.STATE+20)
        parent=m.serialized[-1]['confirmation'];row=m.respond(parent,reply(body=good))
        assert m.deliver(row)==1 and m.fields()==['Fresh title','',''] and not m.nodes()
        record('failed_or_empty_reply_recovers_without_restart_'+str(empty),m)

    m=fixture(raw);parent=m.ordinary(bytes(8));fail(m,parent)
    for now in (600,2100):
        m.due(now,now*1000);assert len(m.profile_requests)==1;m.profile()
        parent=m.serialized[-1]['confirmation'];fail(m,parent)
    assert m.read(retry.STATE+8)==2 and len(m.ordinary_posts)==2 and not m.nodes()
    m.due(10000,10000000);assert not m.profile_requests
    record('two_failed_retries_exhaust_budget_without_loop',m)

    # Allocation failure consumes an attempt and schedules only the remaining
    # attempt; it never sends a null request or starts an unbounded OOM loop.
    m=fixture(raw);parent=m.ordinary(bytes(8));fail(m,parent);m.fail_retry=True
    m.due(600,600000);assert not m.profile_requests and m.read(retry.STATE+8)==1 and len(m.nodes())==1
    m.due(2100,2100000);assert len(m.profile_requests)==1 and m.read(retry.STATE+8)==2
    m.profile();parent=m.serialized[-1]['confirmation'];fail(m,parent)
    assert not m.nodes();record('retry_allocation_failure_preserves_bounded_budget',m)

    for mode in ('changed_UID','disconnected_live_row','native_gate_off','source_queue_changed'):
        m=fixture(raw);parent=m.ordinary(bytes(8));fail(m,parent)
        if mode=='changed_UID':m.live(b'NextUID!')
        elif mode=='disconnected_live_row':m.live(bytes(8),connected=False)
        elif mode=='native_gate_off':m.write(AVRCP+0x20c,0,1)
        else:m.write(AVRCP+0x60,9,2)
        m.due(600,600000);assert not m.profile_requests and not m.nodes() and not m.read(retry.STATE)
        record('live_change_cancels_retry_'+mode,m)

    # Queue a real ordinary request before retry wakeup. The retry is appended
    # behind it; actual FIFO consumption must discard the now-stale retry.
    m=fixture(raw);parent=m.ordinary(bytes(8));fail(m,parent);m.queue_ordinary()
    m.due(600,600000);assert len(m.profile_requests)==2
    m.profile();assert m.read(owner.STATE)==2 and len(m.serialized)==2
    assert not m.read(retry.STATE+20) and m.read(retry.STATE+8)==0
    parent=m.serialized[-1]['confirmation'];row=m.respond(parent,reply(body=good))
    assert m.deliver(row)==1 and not m.nodes()
    record('native_producer_FIFO_drops_stale_retry_after_new_request',m)

    m=fixture(raw);parent=m.ordinary(bytes(8));fail(m,parent)
    m.due(600,600000);queued=m.read(retry.STATE+20);assert queued
    m.begin_disconnect();assert not m.read(retry.STATE) and m.read(retry.STATE+20)==queued
    m.profile();assert len(m.serialized)==1 and not m.read(retry.STATE+20)
    record('disconnect_retains_queued_identity_until_stale_request_is_consumed',m)

    m=fixture(raw);parent=m.ordinary(bytes(8));fail(m,parent)
    m.begin_disconnect();assert not m.nodes() and not m.read(retry.STATE)
    m.due(1000,1000000);assert not m.profile_requests
    record('disconnect_cancels_armed_retry_timer',m)

    for field,value in ((16,0xffff),(8,2)):
        m=fixture(raw);parent=m.ordinary(bytes(8));m.write(retry.STATE+field,value)
        fail(m,parent);assert not m.nodes() and not m.profile_requests
        record('exhausted_retry_counter_refuses_new_timer_'+str(field),m)

    m=fixture(raw);m.write(owner.STATE,0xfffffffe)
    parent=m.ordinary(bytes(8));assert m.read(owner.STATE)==0xffffffff and not m.read(retry.STATE)
    fail(m,parent);assert not m.nodes();record('generation_saturation_disables_retry',m)

    for mode in ('armed_timer','queued_retry'):
        m=fixture(raw);parent=m.ordinary(bytes(8));fail(m,parent)
        if mode=='queued_retry':m.due(600,600000)
        queued=list(m.profile_requests);token=m.read(retry.STATE+16)
        m.drop();assert all(not m.heap[p][1] for p in queued)
        assert not m.nodes() and not m.read(retry.STATE+20) and m.read(retry.STATE+16)==token
        m.finish()
        cases.append(dict(case='native_profile_shutdown_'+mode,token_preserved=token,queued_freed=len(queued),steps=m.steps))

    names=('bt_text_metadata_retry.py','verify_bt_text_metadata_retry.py','bt_text_metadata_shutdown.py',
           'verify_bt_text_metadata_shutdown.py','bt_text_metadata_owner.py','bt_text_metadata_receive.py')
    return dict(cases=len(cases),traces=cases,max_retries=2,delays_ms=[500,1500],hardware_tested=False,
                executable_written=False,lgu_built=False,
                limits=['Native timer creation/delivery/cancellation, metadata producer/factory/parser and pending/profile teardown execute',
                        'Clock, allocator/OOM injection, wire, peer/CID lookup, manager state and publication are fixtures',
                        'Internal requests bypass artwork selection while retaining the original ordinary metadata handler',
                        'Installed PE/full artwork integration and LGU packaging remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True);p.add_argument('--report',type=Path,required=True);a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    r=verify(a.input.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode());print(json.dumps(dict(cases=r['cases']),indent=2))
