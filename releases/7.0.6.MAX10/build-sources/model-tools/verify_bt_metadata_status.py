"""Compare native final metadata handlers and attribute walkers on MAX05 bytes."""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path
import pefile

from inspect_av_layouts import LayoutVM, OBJECT, STATUS, PHONE, MAIN, STACK
from inspect_bt_pairing import put, data
from verify_media_responsiveness import call
from patch_bt_metadata_status import patch

ROOT=Path(__file__).resolve().parents[1]
COOKIE=0x1234abcd
PREVIOUS=b'Previous title\0'.ljust(50,b'\0')+b'Previous album\0'.ljust(50,b'\0')+b'Previous artist\0'.ljust(160,b'\0')


@lru_cache(maxsize=2)
def image(raw):return pefile.PE(data=raw)


def attribute(ident,text):
    return ident.to_bytes(4,'big')+b'\x00\x6a'+len(text).to_bytes(2,'big')+text


def execute(raw,result,supplier,payload,count,offset=14):
    m=LayoutVM(image(raw),[(0x1fa44,0x1fce8),(0x79258,0x79364),(0x85bb8,0x85bdc)])
    m.write(0x110ea4,COOKIE);m.write(0x20e1e8,OBJECT);m.write(OBJECT+0x26c,STATUS)
    put(m,STATUS+0xee,PREVIOUS);put(m,MAIN,bytes(0x300));put(m,PHONE,bytes(28))
    packet=bytes(offset)+payload
    pointer=PHONE+0x100 if packet else 0
    if pointer:put(m,pointer,packet)
    m.write(PHONE,0x820d,2);m.write(PHONE+2,3,1);m.write(PHONE+4,0x11223344)
    m.write(PHONE+12,count,1);m.write(PHONE+14,len(packet),2);m.write(PHONE+16,pointer)
    m.write(PHONE+20,result,2);m.write(PHONE+22,supplier,2);m.write(PHONE+24,offset,2)
    # Nonzero continuation flag must be reset by the original cleanup path.
    m.write(MAIN+0x248,0x55,1)
    frees=[];published=[]
    def memset(v):
        dest,value,size=v.reg[4:7];put(v,dest,bytes([value&255])*size);return dest
    def memcpy(v):
        dest,source,size=v.reg[4:7];put(v,dest,data(v,source,size));return dest
    def compare(v):
        a,b,n=v.reg[4:7];return int(data(v,a,n)!=data(v,b,n))
    def cstring(at,limit):
        out=bytearray()
        for i in range(limit):
            x=m.read(at+i,1)
            if not x:break
            out.append(x)
        return bytes(out)
    def strcat(v):
        dest,size,source,limit=v.reg[4:8]
        old=cstring(dest,size);incoming=cstring(source,min(limit,size-1-len(old)))
        put(v,dest,old+incoming+b'\0');return 0
    def publish(v):
        assert v.reg[5]==1
        published.append(data(v,STATUS+0xee,260).hex());return 0
    def free(v):
        assert v.reg[4]==pointer and pointer not in frees
        frees.append(v.reg[4]);return 0
    def cookie(v):assert v.reg[4]==COOKIE;return 0
    m.hooks={0x8ac14:memset,0x3a750:memset,0x85758:memcpy,0x857a0:compare,
             0x8accc:strcat,0x1eb50:publish,0x8ad6c:free,0x8ac24:cookie}
    call(m,0x1fa44,[0x1234,MAIN,PHONE],limit=5000)
    assert m.read(PHONE+16)==0 and m.read(MAIN+0x248,1)==1
    assert frees==([pointer] if pointer else [])
    return dict(text=data(m,STATUS+0xee,260).hex(),published=published,
                free_count=len(frees),uid=data(m,STATUS+0x219,8).hex(),steps=m.steps)


def verify(raw):
    candidate,recipe=patch(raw);cases=[]
    fixtures=[('title',attribute(1,b'Fresh title'),1,True),
              ('all-text',attribute(1,b'Fresh title')+attribute(2,b'Album')+attribute(3,b'Artist'),3,True),
              ('long-title',attribute(1,b'x'*80),1,True),
              ('empty-list',b'',0,False),('short-header',b'\0'*7,1,False),
              ('partial-list',attribute(1,b'Fresh title')+b'\0'*7,2,False)]
    for name,payload,count,valid in fixtures:
        for result in (0,0x8000,0x8001,0x800b,0x800c,0xffff):
            for supplier in (0,0x11,0x12,0xffff):
                for offset in (13,14):
                    old=execute(raw,result,supplier,payload,count,offset)
                    new=execute(candidate,result,supplier,payload,count,offset)
                    accepted=result==0x8000 and supplier==0x11 and valid
                    if accepted:
                        assert all(new[k]==old[k] for k in ('text','published','free_count','uid')),(name,result,supplier,new,old)
                    else:
                        assert new['text']==PREVIOUS.hex() and new['published']==[]
                    assert new['free_count']==old['free_count']==1
                    cases.append(dict(fixture=name,result=result,supplier=supplier,offset=offset,accepted=accepted,
                                      old_published=len(old['published']),new_published=len(new['published']),
                                      text_preserved=new['text']==PREVIOUS.hex(),free_count=new['free_count']))
    for result in (0x8000,0x800c):
        for supplier in (0,0x11):
            old=execute(raw,result,supplier,b'',0,0);new=execute(candidate,result,supplier,b'',0,0)
            assert new['text']==PREVIOUS.hex() and new['published']==[]
            assert new['free_count']==old['free_count']==0
            cases.append(dict(fixture='null-empty-list',result=result,supplier=supplier,offset=0,
                              accepted=False,old_published=len(old['published']),new_published=0,
                              text_preserved=True,free_count=0))
    return dict(schema=1,cases=len(cases),recipe=recipe,traces=cases,
                limits=['Original final handler, native 79258 attribute walker and null-safe payload-free wrapper execute',
                        'C string/memory operations, cookie check, allocator free and IPC publication are explicit fixtures',
                        'Valid title/album/artist and title clamping match original output; failed/empty/short lists preserve previous text and still clean up',
                        'The original walker clamps declared string lengths; this patch does not add a strict attribute/charset parser',
                        'Interim fragments, missing track notifications and bounded metadata retry remain separate outstanding work',
                        'No device, installed LGU, Bluetooth timing or actual title recovery is demonstrated'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('patch_bt_metadata_status.py','verify_bt_metadata_status.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--input',type=Path,required=True)
    p.add_argument('--report',type=Path,required=True);a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    result=verify(a.input.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(result,indent=2)+'\n').encode())
    print(json.dumps(dict(cases=result['cases'],changed_bytes=result['recipe']['changed_bytes'],lgu_ready=False)))
