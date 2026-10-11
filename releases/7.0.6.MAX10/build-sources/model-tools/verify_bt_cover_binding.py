"""Interpret native selection -> owned task -> channel -> metadata -> artwork.

Original request producer/dispatcher, CM constructors, metadata parser/cleanup,
and CSR timer instructions execute. Queue delivery, wire peers and JPEG/GUI
publication are fixtures. No executable or LGU is written.
"""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_binding as binding
import bt_cover_art_controller as controller
import bt_cover_art_discovery as discovery
import bt_cover_art_metadata_ticket as ticket
import bt_cover_art_selection as selection
import bt_cover_art_timers as timers
import bt_cover_art_owner as owner
from inspect_bt_pairing import data, put
from patch_bt_cover_attribute import BASE_SHA
from verify_bt_cover_controller import jpeg
from verify_bt_cover_metadata import IntegratedFixture, reply
from verify_bt_cover_responses import handshake
from verify_bt_cover_selection import Selected, CID, PROFILE
from verify_media_responsiveness import call

ROOT=Path(__file__).resolve().parents[1]


@lru_cache(maxsize=1)
def assembled():return binding.assembled()


class Bound(Selected):
    def __init__(self,original):
        super().__init__(original)
        self.pe.helpers=assembled()
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in assembled()]
        self.allowed += [(binding.BIND,binding.BIND+binding.SIZE)]
        put(self,binding.BIND,bytes(binding.SIZE))

    def profile_post(self,m):
        queue,event,pointer=m.reg[4:7]
        if event==discovery.CLASS:
            assert queue==self.queue_id
            n=32 if m.read(pointer,2)==selection.PRIMITIVE else 24
            self.private.append(dict(queue=queue,event=event,raw=data(m,pointer,n).hex()))
            self.messages.append((event,pointer))
            return 0
        if event==0x11b and m.read(pointer,2)==0x20c and m.read(pointer+16)==128:
            return IntegratedFixture.profile_post(self,m)
        return super().profile_post(m)

    def finish_legacy(self):
        # Drain the ordinary title transaction before returning cover metadata.
        self.enter_queue(12)
        pending=next(p for p in self.pending if self.read(p+0x18,2)==7)
        call(self,0x6a50c,[pending])
        self.cleanup_result(self.cfms[-1])

    def select_native(self,uid=b'12345678'):
        self.dispatch(self.produce(uid))
        self.finish_legacy()
        self.handle()

    def connect_native(self):
        assert self.phase==controller.OPENING
        self.connected()
        self.receive(handshake())
        self.credit()
        assert self.phase==controller.META
        self.profile()
        assert len(self.pending)==1 and self.read(ticket.SLOT+16)==2

    def ready_image(self):
        self.connect_native()
        self.response(reply())
        assert self.phase==controller.GET
        self.finish_image()
        assert self.phase==controller.READY and self.visible==(1,1,jpeg())

    def pump(self,queue=None):
        self.enter_queue(self.queue_id if queue is None else queue)
        return call(self,timers.PUMP,[self.state])


def verify(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw)
    traces=[]
    def record(name,m):
        row=dict(case=name,phase=m.phase,owner_phase=m.read(m.state),
                 selected_serial=m.read(selection.SNAPSHOT),binding=data(m,binding.BIND,binding.SIZE).hex(),
                 requests=list(m.requests),metadata=list(m.metadata_requests),images=len(m.images),steps=m.steps)
        m.drain()
        assert data(m,binding.BIND,binding.SIZE)==bytes(binding.SIZE)
        traces.append(row)
    m=Bound(pe)
    m.select_native()
    assert m.requests[-1]['kind']=='open'
    assert m.requests[-1]['peer']==data(m,m.peer+8,8).hex()
    assert m.requests[-1]['remote']==0x1003 and m.requests[-1]['security']==0x80
    assert m.field(8)==1 and m.field(12)==1
    m.ready_image()
    record('native_selected_track_through_image_transfer',m)
    # New request with repeated zero UID must refresh after completion. Its own
    # attribute-8 request must not generate a new selected-track event.
    m=Bound(pe)
    m.select_native(bytes(8))
    m.ready_image()
    assert m.read(selection.SNAPSHOT)==1
    m.select_native(bytes(8))
    assert m.phase==controller.META and m.field(12)==2
    assert len([r for r in m.requests if r['kind']=='open'])==1
    assert m.read(selection.SNAPSHOT)==2 and m.read(binding.BIND+4)==2
    m.profile()
    assert m.read(selection.SNAPSHOT)==2
    m.response(reply())
    # Last transfer's final send still owns transport credit until its CFM.
    assert m.field(28)>0 and m.field(32)==0
    m.credit()
    m.finish_image()
    assert m.visible==(1,2,jpeg())
    record('repeated_zero_uid_refresh_without_recursive_request',m)
    # Repeated same UID while CONNECT/GET is pending coalesces. A changed UID
    # cancels transfer and waits for CM close before the new open.
    for stage in ('opening','connect','get'):
        for changed in (False,True):
            m=Bound(pe)
            m.select_native()
            if stage!='opening':m.connected()
            if stage=='get':
                m.receive(handshake());m.credit();m.profile();m.response(reply())
            m.select_native(b'87654321' if changed else b'12345678')
            if changed:
                assert m.phase==controller.FAILED
                assert m.read(m.state)==(owner.CANCELLED if stage=='opening' else owner.CLOSING)
                assert len([r for r in m.requests if r['kind']=='open'])==1
                for _ in range(3):m.pump()
                assert len([r for r in m.requests if r['kind']=='open'])==1
                if stage=='opening':
                    m.connected()
                    assert m.read(m.state)==owner.CLOSING
                m.enqueue(0x8206);m.handle()
                assert m.phase==controller.OPENING and m.field(8)==2
                assert len([r for r in m.requests if r['kind']=='open'])==2
            else:
                assert m.phase in (controller.OPENING,controller.CONNECT,controller.GET)
                assert m.read(binding.BIND+4)==1 and m.read(selection.SNAPSHOT)==2
            record(f'{stage}_changed_uid_{changed}',m)
    # Native disconnect, profile disappearance, selection CID/birth changes,
    # changed capabilities: cancel before another packet can be sent.
    for case in ('disconnected','profile_dropped','cid_changed','birth_replaced','capabilities_changed'):
        m=Bound(pe);m.select_native();m.connected()
        sends=len([r for r in m.requests if r['kind']=='send'])
        if case=='disconnected':m.write(m.peer+0x1e,4,1)
        if case=='profile_dropped':m.write(selection.PROFILE,0)
        if case=='cid_changed':m.write(m.peer+0x18,CID+1)
        if case=='birth_replaced':m.write(m.peer+0x120,2)
        if case=='capabilities_changed':m.write(m.peer+0x124,0x1005,2)
        m.pump()
        assert m.phase==controller.FAILED and m.read(m.state)==owner.CLOSING
        assert len([r for r in m.requests if r['kind']=='send'])==sends
        record(case+'_cancels_before_send',m)
    # Capabilities may appear later; capture/post allocation may fail without
    # hiding the current native selection. No manual preparation/open calls.
    for case in ('late_capabilities','lost_optional_message','security_zero','wrong_queue','channel_exhausted'):
        m=Bound(pe)
        if case=='late_capabilities':m.write(m.peer+0x12c,0)
        if case=='lost_optional_message':m.fail_selection_alloc=True
        if case=='security_zero':m.write(m.peer+0x126,0,2)
        if case=='channel_exhausted':m.write(m.state+controller.OFFSET+8,0xffffffff)
        m.dispatch(m.produce());m.finish_legacy()
        if case=='wrong_queue':
            before=data(m,m.state,controller.TASK_SIZE)
            m.pump(13)
            assert data(m,m.state,controller.TASK_SIZE)==before
        else:m.handle()
        if case=='late_capabilities':
            assert not any(r['kind']=='open' for r in m.requests)
            m.write(m.peer+0x12c,1)
            # The flat capability message is just a wakeup: all fields are
            # re-resolved from current native state before opening.
            envelope=m.new(bytes(24));m.write(envelope,discovery.PRIMITIVE,2)
            m.messages.append((discovery.CLASS,envelope));m.handle()
        should_open=case in ('late_capabilities','lost_optional_message')
        assert sum(r['kind']=='open' for r in m.requests)==int(should_open)
        if case=='wrong_queue':m.handle()
        record(case,m)
    # An actual connect failure cannot make subsequent pumps spin/reopen.
    m=Bound(pe);m.select_native()
    m.connected(result=1,supplier=12)
    assert m.read(m.state)==owner.IDLE
    for _ in range(5):m.pump()
    assert len([r for r in m.requests if r['kind']=='open'])==1
    m.select_native()
    assert len([r for r in m.requests if r['kind']=='open'])==2
    record('one_open_attempt_per_selection_then_explicit_new_request',m)
    # Old metadata must actually drain, not just time out, before replacement.
    m=Bound(pe);m.select_native();m.connect_native()
    m.select_native(b'87654321')
    assert m.phase==controller.FAILED and m.read(ticket.SLOT+16)==2
    m.enqueue(0x8206);m.handle()
    assert m.read(m.state)==owner.IDLE
    assert len([r for r in m.requests if r['kind']=='open'])==1
    m.response(reply())
    assert m.phase==controller.OPENING and m.field(8)==2
    assert len([r for r in m.requests if r['kind']=='open'])==2
    record('replacement_waits_for_close_and_exact_metadata_result',m)
    # Two native requests queue two wakeups. The older envelope carries no
    # authority over the now-current snapshot and cannot open the old CID/UID.
    m=Bound(pe)
    m.dispatch(m.produce(b'12345678'));m.finish_legacy()
    m.write(m.peer+0x18,CID+1)
    m.write(m.peer+0x120,2)
    m.dispatch(m.produce(b'87654321'));m.finish_legacy()
    assert len(m.messages)==2
    m.handle();m.handle()
    assert len([r for r in m.requests if r['kind']=='open'])==1
    assert m.read(binding.BIND+4)==2 and m.read(binding.BIND+8)==2
    assert m.read(binding.BIND+12)==CID+1 and data(m,binding.BIND+20,8)==b'87654321'
    record('stale_queued_wakeup_uses_only_current_native_selection',m)
    # Invalid optional open arguments fail closed and get only one attempt.
    m=Bound(pe);m.write(m.peer+0x124,0x1002,2);m.select_native()
    assert m.phase==controller.FAILED and m.read(m.state)==owner.IDLE
    assert m.read(binding.BIND)==1
    for _ in range(5):m.pump()
    assert not any(r['kind']=='open' for r in m.requests)
    record('invalid_psm_refuses_open_without_retry_loop',m)
    pins=('bt_cover_art_binding.py','verify_bt_cover_binding.py','bt_cover_art_selection.py',
          'verify_bt_cover_selection.py','bt_cover_art_controller.py','bt_cover_art_metadata.py',
          'bt_cover_art_metadata_ticket.py','bt_cover_art_task.py','bt_cover_art_timers.py',
          'verify_bt_cover_metadata.py','verify_bt_cover_controller.py','verify_bt_cover_responses.py',
          'verify_bt_cover_owner.py','verify_media_responsiveness.py','inspect_bt_pairing.py',
          'patch_usb_seek_completion.py','patch_updater_copy_safety.py')
    return dict(cases=len(traces),traces=traces,
                helpers=[{k:v for k,v in r.items() if k!='raw'} for r in assembled()],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Native selection drives task requests in interpreter fixtures only',
                        'Actual source-off transitions are not wired; retry requires a new legacy track request',
                        'Private queue delivery, heap, wire peer and JPEG/GUI publication are fixtures',
                        'One globally quiescent task teardown and serialized CSR segment zero are required',
                        'PE placement, loader/unwind and CE/AppMain image publication remain open'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in pins})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True)
    p.add_argument('--report',type=Path,required=True)
    args=p.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=result['cases'],lgu_built=False),indent=2))
