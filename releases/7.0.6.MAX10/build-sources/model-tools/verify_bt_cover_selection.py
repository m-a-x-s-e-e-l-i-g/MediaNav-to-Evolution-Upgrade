"""Interpret legacy request producer/dispatcher and selected-peer resolution.

Actual legacy 1d3c4, table-based 3bcc0 dispatch, 53728 metadata request handling,
8186c peer lookup and original 3bb6c profile shutdown execute. Allocators, wire
serialization, queue delivery, SDP shutdown and copying remain explicit fixtures.
No executable, LGU, device installation or image publication is produced.
"""
import argparse
from collections import deque
from functools import lru_cache
import hashlib
import json
from pathlib import Path
import struct

import pefile

import bt_cover_art_selection as selection
import bt_cover_art_discovery as discovery
import bt_cover_art_peer_identity as identity
import bt_cover_art_task as task
from inspect_bt_pairing import data, put
from patch_bt_cover_attribute import BASE_SHA
from verify_bt_cover_metadata import IntegratedFixture, PROFILE
from verify_bt_cover_owner import PEER_BYTES
from verify_bt_cover_task import TaskFixture, SCHED, TABLE
from verify_bt_cover_peer_identity import Lifetime, CONTEXT, CID
from verify_media_responsiveness import call

ROOT = Path(__file__).resolve().parents[1]
APP, HOLDER, OUTPUT = 0x48000000, 0x48001000, 0x48002000
NATIVE = [(0x1d3c4, 0x1d47c), (0x3bcc0, 0x3bf90), (0x8186c, 0x818ac)]


@lru_cache(maxsize=1)
def assembled():
    return selection.assembled()


class Selected(IntegratedFixture):
    def __init__(self, original, enabled=True, serial=0):
        self.fail_selection_alloc = False
        super().__init__(original, bind=False)
        helpers = assembled()
        self.pe.helpers = helpers
        self.ranges += NATIVE+[(r['address'], r['address']+len(r['raw'])) for r in helpers]
        self.allowed += [(selection.PROFILE, selection.SERIAL+4),
                         (selection.SNAPSHOT, selection.SNAPSHOT+selection.SNAPSHOT_SIZE),
                         (APP, APP+0x250), (HOLDER, HOLDER+4), (OUTPUT, OUTPUT+40),
                         (selection.REQUEST_TABLE, selection.REQUEST_TABLE+4)]
        for at, n in ((selection.PROFILE, 8), (selection.SNAPSHOT,32), (APP,0x250), (HOLDER,4)):
            put(self,at,bytes(n))
        self.write(selection.SERIAL, serial)
        self.write(selection.REQUEST_TABLE, selection.REQUEST if enabled else selection.ORIGINAL_REQUEST)
        put(self,OUTPUT,bytes([0xa5])*40)
        self.hooks.pop(0x8186c)
        self.write(PROFILE+0x7c,self.peer)
        self.write(PROFILE+0x80,self.peer)
        self.write(PROFILE+0x84,1)
        self.write(self.peer,0)
        self.write(self.peer+4,0)
        put(self,self.peer+8,PEER_BYTES)
        self.write(self.peer+0x10,3,1)
        self.write(self.peer+0x18,CID)
        self.write(self.peer+0x1e,3,1)
        self.write(self.peer+0x120,1)
        self.write(self.peer+0x124,0x1003,2)
        self.write(self.peer+0x126,0x80,2)
        self.write(self.peer+0x128,0x106,2)
        self.write(self.peer+0x12a,0x100,2)
        self.write(self.peer+0x12c,1)
        self.write(HOLDER,PROFILE)
        self.private, self.legacy, self.generated = [], [], []
        self.fail_selection_alloc = False
        self.hooks[selection.MALLOC] = self.allocate

    def allocate(self,m):
        if self.fail_selection_alloc and selection.REQUEST <= m.pc < selection.RESOLVE and m.reg[4]==32:
            self.fail_selection_alloc=False
            return 0
        return super().allocate(m)

    def profile_post(self,m):
        queue,event,pointer=m.reg[4:7]
        if event==discovery.CLASS:
            assert queue==self.queue_id and m.read(pointer,2)==selection.PRIMITIVE
            self.private.append(dict(queue=queue,event=event,raw=data(m,pointer,32).hex()))
            m.reg[4]=pointer
            self.free(m)  # Explicit task queue sink owns the posted envelope.
            return 0
        assert event==0x11b
        primitive=m.read(pointer,2)
        if primitive==0x20c:
            assert queue==12
            self.generated.append(data(m,pointer,20).hex())
            self.profile_requests.append(pointer)
            return 0
        return super().profile_post(m)

    def produce(self,uid=b'12345678',index=0):
        self.write(APP+0x5e,index,1)
        self.write(APP+0x60,7,2)
        self.write(APP+0x6c+index*0x18,3,1)
        self.write(APP+0x6d+index*0x18,2,1)
        put(self,APP+0x235,uid)
        self.write(APP+0x246,0x2468,2)
        self.enter_queue(7)
        call(self,0x1d3c4,[0,APP])
        return self.profile_requests.popleft()

    def dispatch(self,request,queue=12):
        self.enter_queue(queue)
        # Model separate scheduler queues, including older artwork wakeups that
        # remain queued while the original AVRCP task handles a newer request.
        assert getattr(self,'profile_inbox',None) is None
        self.profile_inbox=deque([(0x11b,request)])
        try:
            result=call(self,0x3bcc0,[HOLDER],limit=40000)
            assert not self.profile_inbox
        finally:
            self.profile_inbox=None
        assert not self.heap[request][1], 'Original dispatcher must free the parent exactly once'
        return result

    def get_message(self,m):
        inbox=getattr(self,'profile_inbox',None)
        if inbox is None:return super().get_message(m)
        if not inbox:return 0
        event,pointer=inbox.popleft()
        m.write(m.reg[4],event,2)
        m.write(m.reg[5],pointer)
        return 1

    def resolve(self,queue=None,output=OUTPUT):
        self.enter_queue(self.queue_id if queue is None else queue)
        return call(self,selection.RESOLVE,[output],limit=20000)

    def drain(self):
        while self.pending:
            self.enter_queue(12)
            call(self,0x6a50c,[self.pending[0]])
        for pointer in list(self.cfms):
            if self.heap[pointer][1] and not any(p==pointer for _,p in self.messages):
                self.cleanup_result(pointer)
        self.deinit()
        self.assert_drained()


def registry(original, enabled, segment):
    m=TaskFixture(original)
    if enabled:
        edits=selection.sites(original.__data__)
        m.patches.update({at:edits[at] for at in (selection.DROP_HIGH,selection.DROP_LOW)})
    m.write(SCHED+0x778,segment,2)
    row=SCHED+0x70*segment
    m.write(row+0x64,1,1)
    call(m,0x244c8,[SCHED])
    count=m.read(row+0x66,2)
    queues=data(m,0x218620,0x40)
    m.write(row+0x66,0,2)
    m.write(row+0x64,0,1)
    m.write(row+0x14,TABLE)
    call(m,0x244c8,[SCHED])
    assert count==m.read(row+0x66,2)
    return dict(count=count, queues=queues.hex(), rows=[tuple(m.read(TABLE+16*i+j*4) for j in range(4)) for i in range(count)])


def shutdown(original, helpers, enabled, nested):
    m=Lifetime(original,helpers)
    # Make the real profile allocation owned so original DEINIT can free it.
    m.block(CONTEXT,0xa0)
    put(m,CONTEXT,bytes(0xa0))
    call(m,0x8145c,[CONTEXT+0x7c,0,0,0x567dc])
    call(m,0x8145c,[CONTEXT+0x48,0,0,0])
    peer=m.create()
    m.ready(peer)
    if nested:
        node=call(m,0x8151c,[peer+0x24,16])
        payload=m.next_heap
        m.next_heap+=0x100
        m.block(payload,5)
        m.write(node+12,payload)
    for at,raw in ((selection.PROFILE,struct.pack('<II',CONTEXT,19)),
                   (selection.SNAPSHOT,bytes([0x77])*32),(HOLDER,struct.pack('<I',CONTEXT))):
        m.map(at,raw)
    m.ranges += [(selection.DROP,selection.DROP+0x400),(0x3bb6c,0x3bcc0)]
    # No pending profile queue; these two OS/scheduler operations are fixtures.
    m.hooks.update({0x82b44:lambda _:0,0x84ee8:lambda _:0})
    checks=[]
    def sdp_shutdown(vm):
        assert vm.reg[4]==CONTEXT+0x24
        cleared=not vm.read(selection.PROFILE) and data(vm,selection.SNAPSHOT,32)==bytes(32)
        assert cleared==enabled
        checks.append(cleared)
        return 0
    m.hooks[0x4f214]=sdp_shutdown
    result=call(m,selection.DROP if enabled else selection.ORIGINAL_DROP,[HOLDER],limit=40000)
    assert all(not live for _,live in m.blocks.values())
    assert m.read(selection.SERIAL)==19
    return dict(result=result,frees=m.frees,cancelled=m.cancelled,cleared_before_sdp=checks,steps=m.steps)


def verify(raw):
    if hashlib.sha256(raw).hexdigest()!=BASE_SHA:raise ValueError('Expected exact retained MAX05 Blue.exe')
    pe=pefile.PE(data=raw)
    helpers=assembled()
    edits=selection.sites(raw)
    comparisons,traces,resolutions,registrations,drops=[],[],[],[],[]
    # Original app producer -> original profile table dispatcher -> wrapper ->
    # original request/CFM/pending handler, with native peer-list lookup.
    for uid in (bytes(8),b'12345678',bytes.fromhex('ffeeddccbbaa9988')):
        for index in (0,1):
            sides=[]
            for enabled in (False,True):
                m=Selected(pe,enabled)
                request=m.produce(uid,index)
                request_raw=data(m,request,20)
                peer_before=data(m,m.peer,0x140)
                result=m.dispatch(request)
                assert data(m,m.peer,0x140)==peer_before
                assert m.serialized[-1]['mask']==0x7f and m.serialized[-1]['queue']==7
                # Compare outputs before pending completion mutates the result.
                pending=m.pending[-1]
                cfm=m.read(pending+0x10)
                side=dict(request=request_raw.hex(),pending=data(m,pending,32).hex(),
                          confirmation=data(m,cfm,28).hex(),serialized=list(m.serialized),result=result)
                if enabled:
                    assert m.read(selection.SERIAL)==1 and m.read(selection.PROFILE)==PROFILE
                    assert data(m,selection.SNAPSHOT+24,8)==uid
                    assert len(m.private)==1
                    assert m.resolve()==1
                    assert data(m,OUTPUT+32,8)==uid
                    assert m.read(OUTPUT+24)==CID and m.read(OUTPUT+28)==1
                    side['snapshot']=data(m,selection.SNAPSHOT,32).hex()
                    side['message']=m.private[-1]
                else:
                    assert not m.private and not m.read(selection.PROFILE)
                m.drain()
                sides.append(side)
            for field in ('request','pending','confirmation','serialized','result'):
                assert sides[0][field]==sides[1][field],field
            comparisons.append(dict(uid=uid.hex(),app_slot=index,original=sides[0],candidate=sides[1]))
    # Unrelated/own artwork requests must never change selected identity.
    for case in ('own_artwork','wrong_scope','other_mask','wrong_reply_queue','wrong_scheduler',
                 'no_peer','disconnected','zero_cid','zero_birth','no_capabilities',
                 'optional_alloc_failure','unregistered_art_task','last_serial','exhausted_serial'):
        m=Selected(pe,serial=0xfffffffe if case=='last_serial' else 0xffffffff if case=='exhausted_serial' else 0)
        request=m.produce()
        if case=='own_artwork':m.write(request+2,m.queue_id,2);m.write(request+16,128)
        if case=='wrong_scope':m.write(request+5,1,1)
        if case=='other_mask':m.write(request+16,1)
        if case=='wrong_reply_queue':m.write(request+2,m.queue_id,2)
        if case=='no_peer':m.write(PROFILE+0x7c,0)
        if case=='disconnected':m.write(m.peer+0x1e,4,1)
        if case=='zero_cid':m.write(m.peer+0x18,0)
        if case=='zero_birth':m.write(m.peer+0x120,0)
        if case=='no_capabilities':m.write(m.peer+0x12c,0)
        if case=='optional_alloc_failure':m.fail_selection_alloc=True
        if case=='unregistered_art_task':m.write(task.QUEUE,0xffff,2)
        m.dispatch(request,13 if case=='wrong_scheduler' else 12)
        captured=case in ('no_capabilities','optional_alloc_failure','unregistered_art_task','last_serial')
        assert bool(m.read(selection.SNAPSHOT))==captured,case
        assert len(m.private)==int(case in ('no_capabilities','last_serial')),case
        if case=='no_capabilities':assert bytes.fromhex(m.private[0]['raw'])[12:20]==bytes(8)
        if captured and case not in ('no_capabilities','unregistered_art_task'):
            assert m.resolve()==m.read(selection.SERIAL)
        else:
            assert m.resolve()==0
            assert data(m,OUTPUT,40)==bytes([0xa5])*40
        traces.append(dict(case=case,serial=m.read(selection.SERIAL),captured=captured,posts=list(m.private)))
        m.write(task.QUEUE,m.queue_id,2)
        m.drain()
    # Snapshot is weak. Every read rechecks native peer identity and connection.
    for case in ('valid','peer_removed','birth_reused','cid_changed','address_changed','id_changed',
                 'state_changed','caps_invalid','security_zero','profile_cleared','snapshot_zero',
                 'wrong_queue','other_segment','null_output','unaligned_output','wrapping_output'):
        m=Selected(pe)
        m.dispatch(m.produce())
        if case=='peer_removed':m.write(PROFILE+0x7c,0)
        if case=='birth_reused':m.write(m.peer+0x120,2)
        if case=='cid_changed':m.write(m.peer+0x18,CID+1)
        if case=='address_changed':m.write(m.peer+8,m.read(m.peer+8)^1)
        if case=='id_changed':m.write(m.peer+0x10,4,1)
        if case=='state_changed':m.write(m.peer+0x1e,4,1)
        if case=='caps_invalid':m.write(m.peer+0x12c,0)
        if case=='security_zero':m.write(m.peer+0x126,0,2)
        if case=='profile_cleared':m.write(selection.PROFILE,0)
        if case=='snapshot_zero':m.write(selection.SNAPSHOT,0)
        q=13 if case=='wrong_queue' else 0x814 if case=='other_segment' else m.queue_id
        out=0 if case=='null_output' else OUTPUT+1 if case=='unaligned_output' else 0xfffffff0 if case=='wrapping_output' else OUTPUT
        before=data(m,OUTPUT,40)
        result=m.resolve(q,out)
        assert result==int(case=='valid'),case
        if case!='valid':assert data(m,OUTPUT,40)==before
        resolutions.append(dict(case=case,accepted=bool(result)))
        m.drain()
    # Same native connection: each original current-track request has a distinct
    # nonreused selection serial, even if the phone reports UID zero repeatedly.
    m=Selected(pe)
    for i,uid in enumerate((bytes(8),bytes(8),b'87654321'),1):
        m.dispatch(m.produce(uid))
        assert m.resolve()==i and data(m,OUTPUT+32,8)==uid
        assert len(m.private)==i
    traces.append(dict(case='repeat_zero_uid_then_new_uid',serial=m.read(selection.SERIAL),posts=m.private))
    m.drain()
    for segment in (0,1):
        old,new=registry(pe,False,segment),registry(pe,True,segment)
        assert old['queues']==new['queues'] and old['count']==new['count']
        changes=[]
        for a,b in zip(old['rows'],new['rows']):
            if a!=b:
                assert a[1]==selection.ORIGINAL_DROP and b[1]==selection.DROP
                assert a[0]==b[0] and a[2:]==b[2:]
                changes.append((a,b))
        assert len(changes)==(1 if segment==0 else 0)
        registrations.append(dict(segment=segment,original=old,candidate=new))
    for nested in (False,True):
        old,new=shutdown(pe,helpers,False,nested),shutdown(pe,helpers,True,nested)
        assert old['frees']==new['frees'] and old['cancelled']==new['cancelled'] and old['result']==new['result']
        drops.append(dict(nested=nested,original=old,candidate=new))
    pins=('bt_cover_art_selection.py','verify_bt_cover_selection.py','bt_cover_art_peer_identity.py',
          'verify_bt_cover_peer_identity.py','bt_cover_art_metadata.py','verify_bt_cover_metadata.py',
          'verify_bt_cover_metadata_ticket.py','verify_bt_cover_timers.py','verify_bt_cover_controller.py',
          'verify_bt_cover_task.py','verify_bt_cover_owner.py','verify_bt_cover_csr_bridge.py',
          'verify_media_responsiveness.py','inspect_bt_pairing.py','patch_bt_cover_attribute.py',
          'patch_usb_seek_completion.py','patch_updater_copy_safety.py')
    return dict(legacy_comparisons=len(comparisons),selection_cases=len(traces),resolve_cases=len(resolutions),
                registration_comparisons=len(registrations),shutdown_comparisons=len(drops),
                legacy=comparisons,selections=traces,resolutions=resolutions,registrations=registrations,shutdown=drops,
                sites={hex(k):hex(v) for k,v in edits.items()},
                helpers=[{k:v for k,v in r.items() if k!='raw'} for r in helpers],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Interpreter placements; no native PE/loader/unwind proof',
                        'Original app producer, profile dispatcher/request/peer lookup and profile DEINIT execute',
                        'Queue delivery, allocation, copying, wire serialization and SDP teardown are explicit fixtures',
                        'Snapshot and weak profile reference serialize in CSR segment zero; DEINIT requires global quiescence',
                        'Artwork task still needs consumer/action wiring, source transitions and retry policy',
                        'CE image decoding and AppMain publication remain open'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in pins})


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--report',type=Path,required=True)
    args=parser.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'))
    print(json.dumps({k:v for k,v in result.items() if k.endswith('cases') or k.endswith('comparisons')},indent=2))
