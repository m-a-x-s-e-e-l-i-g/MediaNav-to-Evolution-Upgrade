"""Execute owned transfer helpers in two isolated MIPS address spaces.

Named CE mapping, mutex and interlocked APIs are strict fixtures. Distinct view
addresses alias one shared bank; encoded buffers and tickets stay process-local.
This does not execute CE, install PE hooks, schedule threads or paint a screen.
"""
import argparse
from functools import lru_cache
import hashlib
import json
from pathlib import Path
import struct

import pefile

import bt_cover_art_transfer as transfer
from inspect_bt_pairing import data, put
from verify_bt_cover_csr_bridge import VM
from verify_bt_cover_owner import Image
from verify_media_responsiveness import call, STACK
from verify_bt_cover_image import Decoder, jpeg, BITMAP

ROOT=Path(__file__).resolve().parents[1]
SOURCE,OUTPUT,TICKET=0x40000000,0x41000000,0x41020020
VIEWS={'Blue.exe':0x50000000,'AppMain.exe':0x51000000}
API={name:0x45000000+16*i for i,name in enumerate(transfer.ORDINALS)}


@lru_cache(maxsize=2)
def helpers(module):return transfer.assembled(module)


class World:
    def __init__(self):
        self.shared=None
        self.handles={}
        self.views=set()
        self.next_handle=0x1000
        self.owner=None
        self.abandoned=False
        self.fail=None
        self.trace=[]
        self.cas_interference=False
        self.before_commit=None

    def new(self,m,kind):
        self.next_handle+=1
        self.handles[self.next_handle]=(m.module,kind)
        return self.next_handle

    def checked(self,m,h,kind):assert self.handles.get(h)==(m.module,kind),(m.module,h,kind)

    def destroy_if_unused(self):
        if not self.views and not any(kind=='mapping' for _,kind in self.handles.values()):self.shared=None

    def name(self,m,at):
        values=[]
        for i in range(80):
            value=m.read(at+i*2,2)
            if not value:return ''.join(chr(v) for v in values)
            values.append(value)
        raise AssertionError('Unterminated name')

    def invoke(self,m,name):
        a=m.reg[4:8]
        self.trace.append((m.module,name))
        if name=='mutex':
            assert a[:2]==[0,0] and self.name(m,a[2])==transfer.MUTEX_NAME
            return 0 if self.fail==name else self.new(m,name)
        if name=='mapping':
            assert a==[0xffffffff,0,4,0]
            assert m.read(m.reg[29]+0x10)==transfer.SIZE
            assert self.name(m,m.read(m.reg[29]+0x14))==transfer.MAPPING_NAME
            if self.fail==name:return 0
            if self.shared is None:self.shared=bytearray(transfer.SIZE)
            return self.new(m,name)
        if name=='map':
            self.checked(m,a[0],'mapping')
            assert a[1:]==[6,0,0] and m.read(m.reg[29]+0x10)==transfer.SIZE
            if self.fail==name:return 0
            assert m.module not in self.views
            self.views.add(m.module)
            return VIEWS[m.module]
        if name=='unmap':
            assert a[0]==VIEWS[m.module] and m.module in self.views
            self.views.remove(m.module);self.destroy_if_unused()
            return 1
        if name=='wait':
            self.checked(m,a[0],'mutex');assert a[1]==0,'Artwork must never wait for a mutex'
            if self.fail=='wait':return 0xffffffff
            if self.owner is not None:return 258
            self.owner=m.module
            if self.abandoned:self.abandoned=False;return 128
            return 0
        if name=='release':
            self.checked(m,a[0],'mutex');assert self.owner==m.module,'Unowned mutex released'
            self.owner=None
            return 1
        if name=='close':
            assert self.handles.get(a[0],(None,))[0]==m.module,'Double/foreign handle close'
            del self.handles[a[0]];self.destroy_if_unused()
            return 1
        if name in ('exchange','compare'):
            assert VIEWS[m.module]+8<=a[0]<=VIEWS[m.module]+24 and a[0]%4==0
            if name=='exchange' and a[0]==VIEWS[m.module]+16 and a[1] and self.before_commit:
                callback=self.before_commit;self.before_commit=None;callback()
            if name=='compare' and self.cas_interference:
                self.cas_interference=False;m.write(a[0],m.read(a[0])+1)
            old=m.read(a[0])
            if name=='exchange' or old==a[2]:m.write(a[0],a[1])
            return old
        raise AssertionError(name)

    def word(self,offset):return struct.unpack_from('<I',self.shared,offset)[0]

    def set(self,offset,value):struct.pack_into('<I',self.shared,offset,value)

    def finish(self,*machines):
        for m in machines:m.run_helper('close')
        assert not self.handles and not self.views and self.owner is None and self.shared is None


class Process(VM):
    def __init__(self,world,module,original):
        self.world,self.module,self.config=world,module,transfer.CONFIGS[module]
        self.setup=True
        self.trigger=None
        self.source_live=True
        c=self.config
        self.allowed=[(c.state,c.state+transfer.CONTEXT_SIZE),
                      (c.state+0x100,c.state+0x100+len((transfer.MAPPING_NAME+'\0').encode('utf-16le'))),
                      (c.state+0x140,c.state+0x140+len((transfer.MUTEX_NAME+'\0').encode('utf-16le'))),
                      (SOURCE,SOURCE+transfer.MAX_IMAGE),(OUTPUT,OUTPUT+transfer.MAX_IMAGE),
                      (TICKET,TICKET+12),(STACK-0x600,STACK+0x80)]
        rows=helpers(module)
        super().__init__(Image(original,rows),[(r['address'],r['address']+len(r['raw'])) for r in rows])
        for at,raw in transfer.initial_data(module).items():put(self,at,raw)
        for name,iat in c.api.items():
            self.allowed.append((iat,iat+4));self.write(iat,API[name])
            self.hooks[API[name]]=lambda m,name=name:world.invoke(m,name)
        put(self,TICKET,bytes.fromhex('aabbccdd')*3)
        self.setup=False

    def permitted(self,at,size):return any(lo<=at and at+size<=hi for lo,hi in self.allowed)

    def shared_at(self,at,size):
        start=VIEWS[self.module]
        if start<=at and at+size<=start+transfer.SIZE:
            assert self.module in self.world.views and self.world.shared is not None,'Dead mapping access'
            return at-start
        return None

    def read(self,at,size=4):
        offset=self.shared_at(at,size)
        if offset is not None:return int.from_bytes(self.world.shared[offset:offset+size],'little')
        assert self.permitted(at,size),('Read outside process',self.module,hex(at),size)
        if SOURCE<=at<SOURCE+transfer.MAX_IMAGE:assert self.source_live,'Freed publisher buffer read'
        return super().read(at,size)

    def write(self,at,value,size=4):
        offset=self.shared_at(at,size)
        if offset is not None:
            self.world.shared[offset:offset+size]=(value&((1<<(size*8))-1)).to_bytes(size,'little')
        else:
            assert self.permitted(at,size),('Write outside process',self.module,hex(at),size)
            assert self.setup or not SOURCE<=at<SOURCE+transfer.MAX_IMAGE,'Immutable publisher buffer changed'
            super().write(at,value,size)
        if self.trigger is not None and self.trigger[0](at):
            callback=self.trigger[1];self.trigger=None;callback()

    def run_helper(self,name,args=None,extra=()):
        args=[self.config.state] if args is None else args
        return call(self,self.config.base+transfer.OFFSETS[name],args,extra,limit=2000000)

    def initialize(self):return self.run_helper('init')

    def incarnation(self):return self.read(self.config.state+16)

    def token(self,now=100):return self.run_helper('token',[self.config.state,now])

    def publish(self,token,raw,incarnation=None,at=SOURCE):
        self.setup=True;self.source_live=True;put(self,SOURCE,raw);self.setup=False
        return self.run_helper('publish',[self.config.state,token,at,len(raw)],
                               [self.incarnation() if incarnation is None else incarnation])

    def copy(self,now=100,capacity=transfer.MAX_IMAGE,at=OUTPUT,ticket=TICKET):
        return self.run_helper('copy',[self.config.state,at,capacity,ticket],[now])

    def fresh(self,token,now=100,incarnation=None):
        return self.run_helper('fresh',[self.config.state,token,now,
                               self.incarnation() if incarnation is None else incarnation])

    def touch(self,token,now,incarnation=None):
        return self.run_helper('touch',[self.config.state,token,now,
                               self.incarnation() if incarnation is None else incarnation])

    def invalidate(self):return self.run_helper('invalidate')

    def ticket(self):return [self.read(TICKET+i) for i in (0,4,8)]

    def auxiliary(self,original):
        # An interleaved serialized-owner call gets its own registers and stack;
        # only the process-local context snapshot and mapping view are shared.
        other=Process(self.world,self.module,original)
        other.setup=True;put(other,self.config.state,data(self,self.config.state,transfer.CONTEXT_SIZE))
        other.setup=False
        return other


def verify(blue_raw,app_raw):
    contracts=[transfer.contracts(module,raw) for module,raw in
               (('Blue.exe',blue_raw),('AppMain.exe',app_raw))]
    originals={'Blue.exe':pefile.PE(data=blue_raw),'AppMain.exe':pefile.PE(data=app_raw)}
    cases=[]
    def pair(order=('Blue.exe','AppMain.exe')):
        w=World();ms={n:Process(w,n,originals[n]) for n in originals}
        for n in order:assert ms[n].initialize()==1
        return w,ms['Blue.exe'],ms['AppMain.exe']
    def recorded(name,w,**details):cases.append(dict(case=name,api_calls=list(w.trace),**details))

    for order in (('Blue.exe','AppMain.exe'),('AppMain.exe','Blue.exe')):
        w,b,a=pair(order);token=b.token();body=jpeg()
        assert token==1 and b.publish(token,body)==1 and a.copy()==1
        assert VIEWS[b.module]!=VIEWS[a.module] and b.mem is not a.mem
        assert a.ticket()==[token,len(body),1] and data(a,OUTPUT,len(body))==body
        b.source_live=False
        assert a.fresh(token)==1
        decoder=Decoder(originals['AppMain.exe'],data(a,OUTPUT,len(body)))
        result=decoder.decode();assert result==BITMAP and a.fresh(token)==1
        decoder.finish(result)
        w.shared[transfer.HEADER:transfer.HEADER+len(body)]=bytes(len(body))
        assert data(a,OUTPUT,len(body))==body,'AppMain buffer must own its bytes'
        assert a.initialize()==b.initialize()==1 and a.incarnation()==b.incarnation()==1
        recorded('owned_jpeg_copy_and_decode_'+order[0],w,encoded_bytes=len(body),decode_trace=decoder.trace)
        w.finish(b,a)

    for length in (4,transfer.MAX_IMAGE):
        w,b,a=pair();token=b.token();body=bytes((i%251 for i in range(length)))
        assert b.publish(token,body)==a.copy()==1
        assert data(a,OUTPUT,length)==body and a.ticket()==[token,length,1]
        recorded('exact_encoded_boundary_'+str(length),w)
        w.finish(b,a)

    for module in originals:
        for failure in ('mutex','mapping','map','wait','busy'):
            w=World();m=Process(w,module,originals[module]);w.fail=failure
            if failure=='busy':w.owner='other'
            assert m.initialize()==0 and data(m,m.config.state,transfer.CONTEXT_SIZE)==bytes(transfer.CONTEXT_SIZE)
            assert not w.handles and not w.views and w.shared is None
            if failure=='busy':assert w.owner=='other';w.owner=None
            recorded(module+'_init_'+failure,w)
        for offset,value in ((0,0x1234),(4,2),(28,1)):
            w=World();other=Process(w,'AppMain.exe' if module=='Blue.exe' else 'Blue.exe',
                                  originals['AppMain.exe' if module=='Blue.exe' else 'Blue.exe'])
            assert other.initialize()==1
            w.set(0,0 if offset==28 else transfer.MAGIC);w.set(offset,value)
            before=bytes(w.shared);m=Process(w,module,originals[module])
            assert not m.initialize() and bytes(w.shared)==before
            assert not any(proc==module for proc,_ in w.handles.values())
            recorded(module+'_collision_'+str(offset),w)
            w.finish(other,m)

    w,b,a=pair();token=b.token();assert b.publish(token,b'1234')==1
    snapshot=bytes(w.shared);ticket=a.ticket()
    for m,name,invoke in ((b,'publish',lambda:b.publish(token,b'5678')),(a,'copy',lambda:a.copy())):
        w.owner='other';start=len(w.trace);assert invoke()==2
        assert bytes(w.shared)==snapshot and a.ticket()==ticket and w.owner=='other'
        assert not any(api=='release' for _,api in w.trace[start:]);w.owner=None
        recorded(name+'_busy_returns_without_waiting',w)
    w.owner='other';start=len(w.trace);assert b.invalidate()==1
    assert not any(api in ('wait','release') for _,api in w.trace[start:]) and w.owner=='other'
    w.owner=None;assert a.fresh(token)==0
    recorded('invalidate_bypasses_busy_mutex',w);w.finish(b,a)

    w,b,a=pair();old=b.token();assert b.publish(old,b'1234')==1
    w.owner='other';start=len(w.trace);new=b.token(101)
    assert new==old+1 and w.owner=='other' and not a.fresh(old,101)
    assert not any(api in ('wait','release') for _,api in w.trace[start:])
    w.owner=None
    recorded('new_generation_bypasses_busy_mutex',w);w.finish(b,a)

    for target in ('publish','copy','reader_init','writer_init'):
        w,b,a=pair();token=b.token();assert b.publish(token,b'abcdefgh')==1
        counter=w.word(8);w.abandoned=True;ticket=a.ticket()
        if target=='publish':assert b.publish(token,b'abcdefgh')==0
        elif target=='copy':assert a.copy()==0 and a.ticket()==ticket
        else:
            m=a if target=='reader_init' else b
            m.run_helper('close');assert m.initialize()==1
        assert w.word(8)==counter and w.word(12)==w.word(16)==w.word(20)==0
        assert not a.fresh(token)
        recorded('abandoned_'+target,w);w.finish(b,a)

    for target in ('publish','copy'):
        w,b,a=pair();token=b.token();body=b'abcdefgh'*20
        aux=b.auxiliary(originals[b.module])
        assert b.publish(token,body)==1
        ticket=a.ticket()
        m=b if target=='publish' else a
        destination=VIEWS[b.module]+transfer.HEADER if target=='publish' else OUTPUT
        def interrupt():
            assert w.owner==m.module
            start=len(w.trace);assert aux.invalidate()==1
            assert not any(api in ('wait','release') for _,api in w.trace[start:])
            assert w.owner==m.module
        m.trigger=(lambda at:at==destination+17,interrupt)
        result=b.publish(token,body) if target=='publish' else a.copy()
        assert result==0 and m.trigger is None and not a.fresh(token) and a.ticket()==ticket
        recorded('invalidate_during_'+target,w);w.finish(b,a)

    w,b,a=pair();token=b.token();aux=b.auxiliary(originals[b.module])
    w.before_commit=lambda:aux.invalidate()
    assert b.publish(token,b'1234')==1 and w.before_commit is None
    assert w.word(16)==token and w.word(12)==0 and not a.fresh(token) and not a.copy()
    recorded('invalidate_after_publisher_live_check_before_commit',w);w.finish(b,a)

    w,b,a=pair();token=b.token();aux=b.auxiliary(originals[b.module])
    assert b.publish(token,b'1234')==1
    a.trigger=(lambda at:at==TICKET,lambda:aux.invalidate())
    assert a.copy()==1 and a.trigger is None and a.ticket()==[token,4,a.incarnation()]
    assert not a.fresh(token),'Copy success alone must never authorize the GUI bitmap'
    recorded('invalidate_after_copy_live_check_before_ticket',w);w.finish(b,a)

    w,b,a=pair();token=b.token();assert b.publish(token,b'12345678')==1
    old=a.ticket();assert not a.copy(capacity=4) and a.ticket()==old
    recorded('copy_buffer_too_small_for_published_image',w);w.finish(b,a)

    w,b,a=pair();old=b.token();assert b.publish(old,jpeg())==a.copy()==1
    decoder=Decoder(originals['AppMain.exe'],data(a,OUTPUT,a.ticket()[1]))
    result=decoder.decode();assert result==BITMAP
    new=b.token(101);assert new==2 and not a.fresh(old,101)
    decoder.finish(result)
    assert b.publish(old,b'1234')==0 and b.publish(new,b'5678')==a.copy(101)==1
    assert a.fresh(new,101)==1
    recorded('track_change_after_decode_before_publication',w);w.finish(b,a)

    for stamp,now,expected in ((100,5100,1),(100,5101,0),(100,99,0),(0xffffff00,0x100,1),
                                (0xffffff00,0x2000,0)):
        w,b,a=pair();token=b.token(stamp);assert b.publish(token,b'1234')==1
        assert a.copy(now)==expected and a.fresh(token,now)==expected
        recorded('heartbeat_age_'+str(stamp)+'_'+str(now),w);w.finish(b,a)

    w,b,a=pair();token=b.token();assert b.publish(token,b'1234')==1
    before=bytes(w.shared);assert b.touch(token+1,500)==0 and bytes(w.shared)==before
    assert b.touch(token,500)==1 and w.word(24)==500
    assert a.fresh(token,5500)==1 and not a.fresh(token,5501)
    recorded('heartbeat_only_current_token',w);w.finish(b,a)

    for target in ('counter_saturation','cas_interference'):
        w,b,a=pair();token=b.token();assert b.publish(token,b'1234')==1
        if target=='counter_saturation':w.set(8,0xffffffff)
        else:w.cas_interference=True
        assert b.token()==0 and w.word(12)==0 and not a.fresh(token)
        recorded(target,w);w.finish(b,a)

    for module in originals:
        w,b,a=pair();m=b if module=='Blue.exe' else a;token=b.token()
        assert b.publish(token,b'1234')==a.copy()==1
        old_incarnation=m.incarnation();m.run_helper('close');assert m.initialize()==1
        assert m.incarnation()==old_incarnation+1 and w.word(8)==token
        if module=='Blue.exe':
            new=b.token();assert new==token+1
            assert b.publish(new,b'1234',old_incarnation)==0
            assert b.touch(new,101,old_incarnation)==0
            assert b.publish(new,b'1234')==1
        else:
            assert not a.fresh(token,100,old_incarnation)
            assert a.copy()==1 and a.fresh(token)==1
        recorded(module+'_reopen_rejects_old_incarnation',w);w.finish(b,a)

    w,b,a=pair();token=b.token();assert b.publish(token,b'1234')==a.copy()==1
    old=a.incarnation();w.finish(b,a)
    assert b.initialize()==a.initialize()==1 and b.token()==token
    assert b.publish(token,b'1234')==1
    assert not a.fresh(token,100,old) and a.copy()==1 and a.fresh(token)==1
    recorded('mapping_recreation_reuses_token_but_not_local_incarnation',w);w.finish(b,a)

    for module in originals:
        w=World();m=Process(w,module,originals[module]);m.write(m.config.state+16,0xffffffff)
        assert not m.initialize() and not w.trace and not w.handles
        recorded(module+'_incarnation_saturation',w)

    invalid_publish=[('zero_token',0,SOURCE,4),('null_source',1,0,4),('short',1,SOURCE,3),
                     ('oversize',1,SOURCE,transfer.MAX_IMAGE+1),('wrap',1,0xfffffffe,4),
                     ('mapping_header',1,VIEWS['Blue.exe'],4),
                     ('mapping_body',1,VIEWS['Blue.exe']+transfer.HEADER,4)]
    for name,token,at,length in invalid_publish:
        w,b,a=pair();b.token();before=bytes(w.shared);start=len(w.trace)
        assert b.run_helper('publish',[b.config.state,token,at,length],[b.incarnation()])==0
        assert bytes(w.shared)==before and len(w.trace)==start
        recorded('publish_invalid_'+name,w);w.finish(b,a)

    invalid_copy=[('null_output',0,4,TICKET),('null_ticket',OUTPUT,4,0),('unaligned_ticket',OUTPUT,4,TICKET+1),
                  ('short_capacity',OUTPUT,3,TICKET),('oversize',OUTPUT,transfer.MAX_IMAGE+1,TICKET),
                  ('output_wrap',0xfffffffe,4,TICKET),('ticket_wrap',OUTPUT,4,0xfffffffc),
                  ('output_ticket_overlap',OUTPUT,16,OUTPUT+8),('ticket_output_overlap',OUTPUT+4,16,OUTPUT),
                  ('output_context',transfer.CONFIGS['AppMain.exe'].state,4,TICKET),
                  ('ticket_context',OUTPUT,4,transfer.CONFIGS['AppMain.exe'].state+16),
                  ('output_mapping',VIEWS['AppMain.exe']+transfer.HEADER,4,TICKET),
                  ('ticket_mapping',OUTPUT,4,VIEWS['AppMain.exe'])]
    for name,at,capacity,ticket in invalid_copy:
        w,b,a=pair();token=b.token();assert b.publish(token,b'1234')==1
        before=bytes(w.shared);old=a.ticket();start=len(w.trace)
        assert a.copy(at=at,capacity=capacity,ticket=ticket)==0
        assert bytes(w.shared)==before and a.ticket()==old and len(w.trace)==start
        recorded('copy_invalid_'+name,w);w.finish(b,a)

    for offset,value in ((12,0),(16,99),(20,0),(20,3),(20,transfer.MAX_IMAGE+1)):
        w,b,a=pair();token=b.token();assert b.publish(token,b'1234')==1
        w.set(offset,value);old=a.ticket();assert a.copy()==0 and a.ticket()==old
        recorded('invalid_shared_header_'+str(offset)+'_'+str(value),w);w.finish(b,a)

    return dict(cases=len(cases),traces=cases,contracts=contracts,
                helpers={module:[{k:v for k,v in row.items() if k!='raw'} for row in helpers(module)] for module in originals},
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Assembled MIPS helpers execute in separate process-local memories with different shared view addresses',
                        'Named mapping, mutex, interlocked, COM and GDI are fixtures; CE cache coherence and scheduling remain untested',
                        'Publish source is owned, readable and immutable; close requires quiescent producers and consumers',
                        'Cleanup retains normal valid-handle UnmapViewOfFile, CloseHandle and ReleaseMutex contracts',
                        'Owner token binding, GUI heartbeat/publisher, AppMain worker, fresh GUI painting and PE installation remain open'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_transfer.py','verify_bt_cover_transfer.py','bt_cover_art_image.py',
                              'verify_bt_cover_image.py','verify_bt_cover_csr_bridge.py','verify_bt_cover_owner.py',
                              'verify_bt_cover_attribute.py','verify_media_responsiveness.py','inspect_bt_pairing.py',
                              'patch_usb_seek_completion.py','patch_updater_copy_safety.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--blue',type=Path,required=True);p.add_argument('--app',type=Path,required=True)
    p.add_argument('--report',type=Path,required=True);args=p.parse_args()
    if args.report.exists():raise FileExistsError('Use a fresh report')
    report=verify(args.blue.read_bytes(),args.app.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_bytes((json.dumps(report,indent=2)+'\n').encode('utf-8'))
    print(json.dumps(dict(cases=report['cases'],executable_written=False,lgu_built=False),indent=2))
