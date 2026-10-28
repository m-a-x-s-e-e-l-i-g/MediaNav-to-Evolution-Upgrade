"""Execute unchanged MAX33/MAX34 DSI loading and temperature conversion bytes.

Filesystem/MCU reads are fixtures; proves failure behavior, not this car's cause.
"""
import argparse,hashlib,json,sys
from pathlib import Path
FROZEN=Path(__file__).resolve().parents[1]/'releases/7.0.6.MAX34/build-sources/tools'
if FROZEN.is_dir():sys.path.append(str(FROZEN))
import pefile
from verify_media_responsiveness import VM,call,STACK
from inspect_bt_pairing import put,data

PIN='b93cb55a66c843e1bb5ea34fd58642e451e6b07afcf9f8ccd1fbc762d627e629'
BUFFER=0x45000000


class Loader:
    def __init__(self,raw,cached=None,first=12,second=20):
        self.vm=VM(pefile.PE(data=raw),[(0x1ee1c,0x1ef7c)])
        self.cached=cached;self.first=first;self.second=second;self.reads=[];self.saved=[]
        put(self.vm,BUFFER,bytes(36));self.vm.write(0x648e4,0x46000000)
        self.vm.hooks.update({0x330b0:self.cache,0x153dc:self.read,0x33294:self.save,
            0x4a48c:self.copy,0x49d60:lambda m:0,0x4a3f4:lambda m:0})
    def cache(self,m):
        if self.cached is None:return 0xffffffff
        put(m,m.reg[4],self.cached);return 0
    def read(self,m):
        manager,address,output=m.reg[5:8];count=m.read(m.reg[29]+16,1)
        assert manager==13 and (address,count)in [(0xf1,12),(0xf2,20)]
        actual=min(count,self.first if address==0xf1 else self.second)
        self.reads.append((address,actual))
        fixture=bytearray(32);fixture[7]=0x40
        put(m,output,fixture[(0 if address==0xf1 else 12):][:actual]);return actual
    def save(self,m):self.saved.append(data(m,m.reg[4],m.reg[5]));return 1
    def copy(self,m):put(m,m.reg[4],data(m,m.reg[5],m.reg[6]));return m.reg[4]
    def run(self):
        call(self.vm,0x1ee1c,[0x47000000,BUFFER]);b=data(self.vm,BUFFER,32)
        return dict(reads=self.reads,writes=len(self.saved),config_hex=b.hex(),ui_type=b[7]>>6)


def verify(raw):
    assert hashlib.sha256(raw).hexdigest()==PIN
    cases=[]
    # Execute caller initialization from poisoned stack, up to the real loader call.
    m=VM(pefile.PE(data=raw),[(0x1f444,0x1f638)])
    put(m,STACK-0x880,bytes([0xa5])*0x880)
    put(m,BUFFER,bytes(0x100));put(m,BUFFER+0x1000,bytes(8))
    m.reg[4:6]=[BUFFER,BUFFER+0x1000];m.reg[29]=STACK
    m.write(0x648e4,0x46000000);m.write(0x67fa4,0,1)
    def clear(v):put(v,v.reg[4],bytes([v.reg[5]&255])*v.reg[6]);return v.reg[4]
    m.hooks.update({0x4a290:clear,0x3006c:lambda v:0,0x153dc:lambda v:0,0x49d60:lambda v:0})
    m.run(0x1f444,{0x1f630},limit=1000)
    assert m.reg[5]==STACK-0x880+0xc8 and data(m,m.reg[5],36)==bytes(36)
    cases.append(dict(name='actual startup caller initializes 36-byte loader buffer to zero',buffer_hex=data(m,m.reg[5],36).hex()))
    for first,second in [(0,20),(11,20),(12,0),(12,19),(12,20)]:
        f=Loader(raw,first=first,second=second);r=f.run();ok=first==12 and second==20
        assert r['ui_type']==int(ok)and r['writes']==int(ok)
        cases.append(dict(name=f'uncached read sizes {first}/{second}',**r))
    for ui in range(4):
        b=bytearray(32);b[7]=ui<<6
        r=Loader(raw,cached=bytes(b)).run();assert r['ui_type']==ui and not r['reads']and not r['writes']
        cases.append(dict(name=f'validated cached profile {ui}',**r))
    for raw_temp,expected in [(0,-40),(3,-37),(59,19),(255,418)]:
        m=VM(pefile.PE(data=raw),[(0x14090,0x14198)])
        put(m,BUFFER,bytes(0x50));m.write(BUFFER+0x10,999);m.write(BUFFER+0x18,1);m.write(BUFFER+0x20,1)
        m.write(0x6488c,0);messages=[]
        m.hooks.update({0x36de8:lambda v:messages.append((v.reg[4],v.reg[5]))or 0})
        assert call(m,0x14090,[BUFFER,raw_temp,1])==1
        value=messages[-1][1]>>8
        if value&0x800000:value-=1<<24
        assert value==expected
        cases.append(dict(name='native Celsius conversion',raw=raw_temp,converted=value,invalid=value==418))
    return dict(passed=True,cases=len(cases),checks=cases,micom_sha256=PIN,
        limits='Unchanged packaged MIPS with explicit cache/MCU/IPC fixtures. No reporter configuration or actual received temperature byte is available; no hardware resolution established.')

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--module',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    r=verify(a.module.read_bytes());a.output.write_text(json.dumps(r,indent=2)+'\n',encoding='utf-8');print(json.dumps(r,indent=2))
