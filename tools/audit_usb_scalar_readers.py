"""Audit remaining scalar readers and reproduce mixed repeat/shuffle UI state."""
import hashlib
import json
from pathlib import Path
from verify_media_responsiveness import VM,parsed
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put

ROOT=Path(__file__).resolve().parents[1]
BUILD=ROOT/'build/usb-snapshot-copy-development-02'
MAP,OBJ,DIALOG=0x43000000,0x41000000,0x44000000
FIELDS=(0xf14,0x1484,0x19f4,0x1f64,0x24d4,0x2a44)
SITES=((0x4cfb0,9,10,0xe4a,4),(0x4da18,8,9,0xe4a,4),
       (0x4e504,9,10,0xe4a,4),(0xd7a5c,8,9,0xe4a,4),
       (0xd7da4,9,10,0xe4a,4),(0xdaa1c,8,9,0xe4a,4),
       (0x4f848,10,8,0xe42,4),(0x4f8e0,10,9,0xe46,2))

def menu(raw,delta,repeat,shuffle,flip=None):
    m=VM(parsed(raw),[(0x4f838+delta,0x4f938+delta)])
    put(m,MAP,bytes(0xe56));put(m,OBJ,bytes(0x138));put(m,DIALOG,bytes(0x3000))
    m.write(0x186ce8+delta,OBJ);m.write(OBJ+0xc4,MAP);m.write(OBJ+0x7c,0)
    put(m,MAP+0xe42,repeat.to_bytes(4,'little'));put(m,MAP+0xe46,shuffle.to_bytes(4,'little'))
    m.reg[17:20]=[DIALOG,1,3]
    reads=[];publications=[];plain=m.plain
    def execute(word):
        at=m.pc-delta
        if flip and at==flip['at']:
            put(m,MAP+0xe42,flip['repeat'].to_bytes(4,'little'))
            put(m,MAP+0xe46,flip['shuffle'].to_bytes(4,'little'))
            publications.append(dict(before_instruction=hex(at),repeat=flip['repeat'],shuffle=flip['shuffle']))
        if word>>26==0x22 and at in (0x4f848,0x4f86c,0x4f890,0x4f8b4,0x4f8e0,0x4f904):
            reads.append(dict(instruction=hex(at),repeat=int.from_bytes(bytes(m.mem[MAP+0xe42+i] for i in range(4)),'little'),
                shuffle=int.from_bytes(bytes(m.mem[MAP+0xe46+i] for i in range(4)),'little')))
        plain(word)
    m.plain=execute;m.run(0x4f838+delta,{0x4f938+delta})
    return dict(flags=[m.read(DIALOG+off) for off in FIELDS],reads=reads,publications=publications,instructions=m.steps)

def verify(raw):
    traces=[]
    for delta in (0,0x10000,0x120000,0x500000):
        image=raw if not delta else relocated(raw,delta)
        # Valid small enums have zero high bytes: a merge-pair interleave does
        # not, by itself, manufacture an out-of-range value at these sites.
        for at,rs,rt,offset,maximum in SITES:
            for old in range(maximum):
                for new in range(maximum):
                    m=VM(parsed(image),[(at+delta,at+delta+8)])
                    put(m,MAP,bytes(0xe56));put(m,MAP+offset,old.to_bytes(4,'little'));m.reg[rs]=MAP+offset
                    plain=m.plain
                    def execute(word):
                        if m.pc==at+delta+4:put(m,MAP+offset,new.to_bytes(4,'little'))
                        plain(word)
                    m.plain=execute;m.run(at+delta,{at+delta+8})
                    assert m.reg[rt]==new
                    traces.append(dict(name='valid scalar merge pair',site=hex(at),delta=delta,old=old,new=new,observed=m.reg[rt]))
        for repeat in range(4):
            for shuffle in range(2):
                result=menu(image,delta,repeat,shuffle)
                expected=[int(repeat==v) for v in range(4)]+[int(shuffle==0),int(shuffle!=0)]
                assert result['flags']==expected and len(result['reads'])==6
                traces.append(dict(name='stable repeat/shuffle UI',delta=delta,repeat=repeat,shuffle=shuffle,**result))
        for old,new,at in ((0,1,0x4f86c),(1,0,0x4f86c),(1,3,0x4f890),(3,2,0x4f8b4)):
            # Earlier repeat buttons use old; later buttons use new.
            result=menu(image,delta,old,0,dict(at=at,repeat=new,shuffle=0))
            coherent=[[int(v==i) for i in range(4)] for v in (old,new)]
            assert result['flags'][:4] not in coherent
            traces.append(dict(name='repeat controls disagree after publication',delta=delta,old=old,new=new,**result))
        for old,new in ((0,1),(1,0)):
            result=menu(image,delta,0,old,dict(at=0x4f904,repeat=0,shuffle=new))
            assert sum(result['flags'][4:])!=1
            traces.append(dict(name='shuffle controls disagree after publication',delta=delta,old=old,new=new,**result))
    return dict(cases=len(traces),traces=traces,field_offsets=[hex(v) for v in FIELDS],
        actual_reader_instructions=True,interleaved_publication_is_fixture=True,
        native_scheduling_observed=False,scalar_readers_fixed=False,
        conclusion='Valid single enums did not tear out of range; repeated UI reads can select both or neither option. Use one coherent snapshot per menu update.')

def main():
    manifest=json.loads((BUILD/'manifest.json').read_bytes())
    raw=(BUILD/'payload/upgrade/Storage Card/System/AppMain.exe').read_bytes()
    digest=hashlib.sha256(raw).hexdigest()
    assert digest==next(r['sha256'] for r in manifest['members'] if r['path'].endswith('/AppMain.exe'))
    result=verify(raw);result.update(app_sha256=digest,tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    path=ROOT/'analysis/firmware/usb-scalar-readers-audit.json';assert not path.exists()
    path.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'],conclusion=result['conclusion'],scalar_readers_fixed=False)))

if __name__=='__main__':main()
