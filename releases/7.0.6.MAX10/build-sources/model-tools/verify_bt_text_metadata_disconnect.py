"""Execute the native disconnect prefix and guarded text ownership invalidation."""
import argparse
import hashlib
import json
from pathlib import Path
import bt_text_metadata_disconnect as disconnect
import bt_text_metadata_owner as owner
from verify_bt_text_metadata_receive import Receiver,reply,AVRCP,PREVIOUS,attribute
from verify_bt_cover_metadata_ticket import PROFILE
from inspect_bt_pairing import data

ROOT=Path(__file__).resolve().parents[1]


class Disconnect(Receiver):
    def __init__(self,raw):
        super().__init__(raw)
        rows=disconnect.assembled();self.pe.helpers+=rows
        self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in rows]
        self.ranges += [(0x51b74,0x51e34)]
        self.patches.update(disconnect.sites(raw))
        self.hooks[disconnect.ORIGINAL]=self.lookup_cid
        self.found=self.peer;self.cid=0x45

    def lookup_cid(self,m):
        assert m.reg[4:6]==[PROFILE,self.cid]
        m.write(m.reg[6],self.found+0x18 if self.found else 0)
        return self.found

    def begin_disconnect(self,peer_id=3,queue=12,found=True):
        incoming=self.new(bytes(20));self.write(incoming+4,self.cid)
        self.write(PROFILE+12,incoming);self.write(self.peer+0x10,peer_id,1)
        self.found=self.peer if found else 0
        self.enter_queue(queue);saved=list(self.reg)
        self.reg[4]=PROFILE;self.reg[31]=0xbeef0000
        self.run(0x51b74,{0x51bb4,0xbeef0000},limit=10000)
        assert self.reg[2]==self.found
        if found:
            assert self.pc==0x51bb4 and self.reg[16]==self.peer
            assert self.read(self.reg[29]+0x30)==self.peer+0x18
        self.reg[:]=saved;self.reg[4]=incoming;self.free(self)


def verify(raw):
    traces=[];body=attribute(1,b'New title')
    for mode in ('selected','other_peer','missing_peer','foreign_segment'):
        m=Disconnect(raw);parent=m.ordinary(bytes(8))
        row=m.respond(parent,reply(1,body=body[:7]));assert not m.deliver(row)
        # Keep its acknowledgement queued while the disconnect prefix runs.
        tags=data(m,owner.STATE+owner.INTERIM_END,owner.SIZE-owner.INTERIM_END)
        assert any(tags)
        delayed=m.respond(parent,reply(2,body=b'x')) if mode=='selected' else None
        m.begin_disconnect(peer_id=4 if mode=='other_peer' else 3,
                           queue=0x800 if mode=='foreign_segment' else 12,
                           found=mode!='missing_peer')
        invalidated=mode=='selected'
        assert (m.read(owner.STATE+4)==0)==invalidated
        assert data(m,owner.STATE+owner.INTERIM_END,owner.SIZE-owner.INTERIM_END)==tags
        if delayed:
            assert not m.deliver(delayed) and len(m.profile_requests)==1
            assert data(m,AVRCP+0xee,260)==PREVIOUS
        m.profile();assert len(m.continuations)==int(not invalidated)
        final=m.respond(parent,reply(3,body=body[7:]));published=m.deliver(final)
        assert published==int(not invalidated)
        if invalidated:assert data(m,AVRCP+0xee,260)==PREVIOUS
        else:assert m.fields()==['New title','','']
        # A fresh request after reconnection must work even with the same zero UID.
        m.live(bytes(8));parent=m.ordinary(bytes(8))
        final=m.respond(parent,reply(body=body));assert m.deliver(final)==1
        assert m.fields()==['New title','','']
        m.conclude()
        traces.append(dict(case=mode,ownership_invalidated=invalidated,
                           old_reply_published=bool(published),new_request_published=True,
                           queued_ACK_tags_preserved=True,steps=m.steps))
    names=('bt_text_metadata_disconnect.py','verify_bt_text_metadata_disconnect.py',
           'bt_text_metadata_owner.py','bt_text_metadata_receive.py','verify_bt_text_metadata_receive.py')
    return dict(cases=len(traces),traces=traces,baseline_sha256=hashlib.sha256(raw).hexdigest(),
                helpers=[dict(name=r['name'],address=hex(r['address']),bytes=r['recipe']['used_bytes'],
                              sha256=hashlib.sha256(r['raw']).hexdigest()) for r in disconnect.assembled()],
                hardware_tested=False,executable_written=False,lgu_built=False,
                limits=['Native disconnect prefix executes up to the first subsequent use of the returned peer',
                        'CID lookup and channel output, queues, allocation, wire, publication and live manager state are fixtures',
                        'Remaining disconnect body, scheduler shutdown, deadlines/retry and PE/LGU installation remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True);p.add_argument('--report',type=Path,required=True);a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    r=verify(a.input.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode());print(json.dumps(dict(cases=r['cases']),indent=2))
