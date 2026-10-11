"""Execute original profile queue drain and pending-peer destruction with text tags."""
import argparse
import hashlib
import json
from pathlib import Path
import bt_text_metadata_shutdown as shutdown
import bt_text_metadata_owner as owner
import bt_cover_art_selection as selection
from verify_bt_text_metadata_timeout import Timed
from verify_bt_text_metadata_receive import AVRCP,PREVIOUS,attribute,reply
from verify_bt_cover_metadata_ticket import PROFILE
from verify_bt_cover_timers import TimerFixture
from verify_media_responsiveness import call
from inspect_bt_pairing import data,put

ROOT=Path(__file__).resolve().parents[1]
HOLDER=0x4d200000


class Shutdown(Timed):
    def __init__(self,raw):
        super().__init__(raw)
        rows=shutdown.assembled()+[r for r in selection.assembled() if r['address']==selection.DROP]
        self.pe.helpers+=rows;self.ranges += [(r['address'],r['address']+len(r['raw'])) for r in rows]
        self.ranges += [(0x3bb6c,0x3bcc0),(0x567dc,0x56854),(0x818e8,0x81940),(0x5902c,0x59194)]
        self.allowed += [(HOLDER,HOLDER+4),(selection.PROFILE,selection.SNAPSHOT+32)]
        self.observed=[];self.dropping=False;self.expected_tags=None
        self.hooks.update({0x82b44:lambda _:0,0x84ee8:self.drain_request,0x4f214:self.sdp_stop})
        put(self,selection.PROFILE,bytes(selection.SNAPSHOT+32-selection.PROFILE))

    def plain(self,word):
        if word>>26==0xa:
            signed=lambda n:n if n<0x80000000 else n-0x100000000
            immediate=word&65535
            if immediate&32768:immediate-=65536
            self.reg[(word>>16)&31]=int(signed(self.reg[(word>>21)&31])<immediate)
            self.reg[0]=0
        else:super().plain(word)

    def drain_request(self,m):
        if not self.dropping:return super().get_message(m)
        if not self.profile_requests:return 0
        pointer=self.profile_requests.popleft()
        m.write(m.reg[4],0x11b,2);m.write(m.reg[5],pointer)
        return 1

    def sdp_stop(self,m):
        assert self.dropping and not self.profile_requests
        assert not self.read(owner.STATE+4)
        assert data(self,owner.STATE+owner.INTERIM_END,owner.SIZE-owner.INTERIM_END)==self.expected_tags
        self.observed.append(dict(stage='profile_queue_drained_before_peer_destruction',tags_preserved=True))
        return 0

    def drop(self,entry=shutdown.DROP):
        context=self.new(bytes(0xa0));self.write(HOLDER,context)
        self.write(context+0x7c,self.peer);self.write(context+0x80,self.peer)
        self.write(context+0x84,1);self.write(context+0x90,0x567dc)
        self.write(self.peer,0);self.write(self.peer+4,0)
        self.expected_tags=data(self,owner.STATE+owner.INTERIM_END,owner.SIZE-owner.INTERIM_END)
        serial=self.read(owner.STATE)
        self.enter_queue(0xffff) # Native global teardown need not have an owning queue.
        self.dropping=True
        try:call(self,entry,[HOLDER],limit=50000)
        finally:self.dropping=False
        assert not self.heap[context][1] and not self.heap[self.peer][1]
        assert not self.pending and not self.profile_requests and not self.nodes()
        assert self.read(owner.STATE)==serial
        assert data(self,owner.STATE+32,owner.SIZE-32)==bytes(owner.SIZE-32)
        assert self.read(owner.STATE+4)==self.read(owner.STATE+24)==self.read(owner.STATE+28)==0
        return serial

    def finish(self):
        for row in self.fragments+self.results:
            if self.heap[row['pointer']][1]:assert not self.deliver(row)
        assert data(self,AVRCP+0xee,260)==PREVIOUS
        assert data(self,owner.STATE-4,4)==b'guar' and data(self,owner.STATE+owner.SIZE,4)==b'TAIL'
        TimerFixture.deinit(self)


def verify(raw,fixture=Shutdown):
    edits=shutdown.sites(raw)
    hi,lo=edits[selection.DROP_HIGH],edits[selection.DROP_LOW]
    assert ((hi&65535)<<16)+(lo&65535)-65536==shutdown.DROP
    cases=[];body=attribute(1,b'New title')
    for mode in ('empty','pending_request','queued_interim','queued_ACK','two_queued_ACKs'):
        m=fixture(raw)
        if mode!='empty':
            parent=m.ordinary(bytes(8));m.schedule(parent)
            if mode!='pending_request':
                row=m.respond(parent,reply(1,body=body[:7]))
                if mode!='queued_interim':assert not m.deliver(row)
                if mode=='two_queued_ACKs':
                    row=m.respond(parent,reply(2,body=body[7:8]));assert not m.deliver(row)
        envelopes=list(m.profile_requests)
        serial=m.drop()
        assert all(not m.heap[p][1] for p in envelopes)
        assert not m.continuations and len(m.results)==int(mode!='empty')
        m.finish()
        cases.append(dict(case=mode,generation_preserved=serial,queued_ACKs_freed=len(envelopes),
                          native_destructors=m.visits[0x6a9d8],observed=m.observed,
                          old_reply_publications=len(m.publications),steps=m.steps))
    names=('bt_text_metadata_shutdown.py','verify_bt_text_metadata_shutdown.py','bt_text_metadata_owner.py',
           'verify_bt_text_metadata_timeout.py','verify_bt_text_metadata_receive.py')
    return dict(cases=len(cases),traces=cases,hardware_tested=False,executable_written=False,lgu_built=False,
                limits=['Native profile deinit drains queued ACKs, frees peers/pending records and cancels timers',
                        'Queue delivery, SDP shutdown, allocator, clocks, live manager state and text publication remain fixtures',
                        'Global shutdown assumes GUI producers are already quiescent; this is not runtime cancellation',
                        'Retry timer integration and installation in the candidate PE remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True);p.add_argument('--report',type=Path,required=True);a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    r=verify(a.input.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode());print(json.dumps(dict(cases=r['cases']),indent=2))
