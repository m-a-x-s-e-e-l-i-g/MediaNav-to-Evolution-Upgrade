"""Actual AppMain reader slices with explicit interleaving, not native scheduling."""
import hashlib
import json
from pathlib import Path
from verify_media_responsiveness import VM, parsed, call
from inspect_bt_pairing import put

ROOT=Path(__file__).resolve().parents[1]
BUILD=ROOT/'build/startup-failure-development-01'
MAP,OBJ,WIDGET=0x43000000,0x41000000,0x44000000

class Reader(VM):
    def __init__(self,raw,ranges,flip=False):
        super().__init__(parsed(raw),ranges);self.flip=flip;self.loads=[]
    def plain(self,word):
        op=word>>26
        if op==0x25:
            at=(self.reg[(word>>21)&31]+(word&65535))&0xffffffff
            if MAP<=at<MAP+0xe56:self.loads.append(at-MAP)
        super().plain(word)
        if self.flip and self.pc==0x4e26c:
            # A publication after LWL and before LWR. API scheduling is a fixture.
            put(self,MAP+0xe4e,(0x56780002).to_bytes(4,'little'))

def verify(raw):
    traces=[]
    for unterminated in (False,True):
        m=Reader(raw,[(0x1df10,0x1df4c)])
        put(m,MAP,bytes(0xe56));m.write(0x186ce8,OBJ);m.write(OBJ+0xc4,MAP)
        text=('A'*260 if unterminated else 'Music')
        put(m,MAP+0x20e,text.encode('utf-16-le'))
        if unterminated:put(m,MAP+0x416,'Z\0'.encode('utf-16-le'))
        m.run(0x1df10,{0x1df4c})
        expected=261 if unterminated else 5
        assert m.reg[17]==expected
        assert (max(m.loads)>=0x416)==unterminated
        traces.append(dict(name='title length reader',unterminated_title=unterminated,
                           measured_characters=expected,last_read_offset=hex(max(m.loads)),
                           crosses_title_slot=unterminated))
    for flip in (False,True):
        m=Reader(raw,[(0x4e268,0x4e274)],flip=flip)
        put(m,MAP,bytes(0xe56));m.reg[5]=MAP
        put(m,MAP+0xe4e,(0x12340001).to_bytes(4,'little'))
        m.run(0x4e268,{0x4e274})
        expected=0x12340002 if flip else 0x12340001
        assert m.reg[16]==expected
        traces.append(dict(name='packed cover-handle reader',interleaved_publication=flip,
                           observed_handle=hex(expected),old_handle='0x12340001',new_handle='0x56780002',
                           torn_handle=flip))
    m=Reader(raw,[(0x138d60,0x138e90)])
    put(m,WIDGET,bytes(0x40));m.write(0x186538,1);objects=[]
    def get_object(v):
        assert v.reg[4]==0x12340001 and v.reg[5]==24
        objects.append(v.reg[4]);put(v,v.reg[6],bytes(24));return 24
    m.hooks[0x140048]=get_object
    call(m,0x138d60,[WIDGET,0x12340001,64,32])
    assert m.read(WIDGET+0x3c)==0x12340001 and objects==[0x12340001]
    traces.append(dict(name='widget retains borrowed bitmap handle',stored_offset='0x3c',
                       stored_handle=hex(m.read(WIDGET+0x3c)),get_object_calls=len(objects),
                       bitmap_not_duplicated=True))
    return dict(cases=len(traces),traces=traces,actual_reader_instructions=True,
                publication_and_gdi_are_fixtures=True,real_scheduler_interleaving_observed=False,
                native_cover_handle_lifetime_tested=False,concurrency_fixed=False)

def main():
    manifest=json.loads((BUILD/'manifest.json').read_bytes())
    raw=(BUILD/'payload/upgrade/Storage Card/System/AppMain.exe').read_bytes();digest=hashlib.sha256(raw).hexdigest()
    assert digest==next(r['sha256'] for r in manifest['members'] if r['path'].endswith('/AppMain.exe'))
    proof=verify(raw);proof.update(output_sha256=digest,tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    path=ROOT/'analysis/firmware/usb-status-reader-audit.json';assert not path.exists()
    path.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=proof['cases'],output_sha256=digest,concurrency_fixed=False)))

if __name__=='__main__':main()
