"""Interpret bounded JPEG gating and the checked AppMain CE-image call contract.

Execute assembled helpers and retained AppMain import thunks. COM/GDI are strict
fixtures; Pillow supplies image-info, pixels and decode failures. This is not CE
codec execution, GUI painting, cross-process delivery or firmware installation.
"""
import argparse
from functools import lru_cache
import hashlib
from io import BytesIO
import json
from pathlib import Path
import struct

import pefile
from PIL import Image as PillowImage

import bt_cover_art_image as image
from inspect_bt_pairing import data, put
from verify_bt_cover_csr_bridge import VM
from verify_bt_cover_owner import Image
from verify_media_responsiveness import call, STACK

ROOT=Path(__file__).resolve().parents[1]
SOURCE,FACTORY,FVT,IM,IIVT=0x41000000,0x42000000,0x42001000,0x42002000,0x42003000
DC,BITMAP,OLD,BITS=0x1001,0x2001,0x3001,0x44000000
CREATE_FACTORY,CREATE_IMAGE,INFO,DRAW,RELEASE_IMAGE,RELEASE_FACTORY=range(0x45000000,0x45000060,16)
API={image.CREATE_DC:0x45000100,image.CREATE_DIB:0x45000110,
     image.SELECT:0x45000120,image.DELETE_DC:0x45000130,image.DELETE_OBJECT:0x45000140}


@lru_cache(maxsize=1)
def assembled():return image.assembled()


def jpeg(mode='RGB',subsampling=2,progressive=False):
    stream=BytesIO()
    PillowImage.new(mode,(200,200),80 if mode=='L' else (30,50,70)).save(
        stream,format='JPEG',quality=70,subsampling=subsampling,progressive=progressive)
    return stream.getvalue()


class Decoder(VM):
    def __init__(self,original,raw,fail=None,width=200,height=200):
        self.allowed=[(SOURCE,SOURCE+len(raw)),(STACK-0x600,STACK+0x80),
                      (FACTORY,FACTORY+4),(FVT,FVT+0x18),(IM,IM+4),(IIVT,IIVT+0x1c),
                      (image.CLSID,image.CLSID+16),(image.IID,image.IID+16),
                      (image.CO_CREATE,image.CO_CREATE+4)]
        self.resources,self.trace={},[]
        self.raw,self.fail,self.dimensions=raw,fail,(width,height)
        self.selected=OLD
        self.dib_pixels=None
        self.reads=0
        self.source_writes=0
        ranges=[(r['address'],r['address']+len(r['raw'])) for r in assembled()]
        ranges += [(at,at+16) for at in API]
        super().__init__(Image(original,assembled()),ranges)
        self.setup=True
        put(self,SOURCE,raw)
        put(self,image.CLSID,original.get_data(image.CLSID-original.OPTIONAL_HEADER.ImageBase,16))
        put(self,image.IID,original.get_data(image.IID-original.OPTIONAL_HEADER.ImageBase,16))
        self.write(image.CO_CREATE,CREATE_FACTORY)
        self.write(FACTORY,FVT);self.write(FVT+8,RELEASE_FACTORY);self.write(FVT+0x14,CREATE_IMAGE)
        self.write(IM,IIVT);self.write(IIVT+8,RELEASE_IMAGE)
        self.write(IIVT+0x10,INFO);self.write(IIVT+0x18,DRAW)
        if not hasattr(original,'cover_image_contract'):
            original.cover_image_contract=image.contracts(original.__data__)
        for row in original.cover_image_contract['imports']:
            iat=int(row['iat'],16);at=int(row['thunk'],16)
            self.allowed.append((iat,iat+4));self.write(iat,API[at])
        self.hooks={CREATE_FACTORY:self.factory,CREATE_IMAGE:self.create_image,INFO:self.info,DRAW:self.draw,
                    RELEASE_IMAGE:self.release_image,RELEASE_FACTORY:self.release_factory,
                    API[image.CREATE_DC]:self.create_dc,API[image.CREATE_DIB]:self.create_dib,
                    API[image.SELECT]:self.select,API[image.DELETE_DC]:self.delete_dc,
                    API[image.DELETE_OBJECT]:self.delete_object}
        self.setup=False

    def read(self,at,size=4):
        assert any(lo<=at and at+size<=hi for lo,hi in self.allowed),('Read outside fixture',hex(at),size)
        if SOURCE<=at<SOURCE+len(self.raw):self.reads+=1
        if at==FACTORY and not self.setup:assert self.resources.get('factory')
        if at==IM and not self.setup:assert self.resources.get('image')
        return super().read(at,size)

    def write(self,at,value,size=4):
        assert any(lo<=at and at+size<=hi for lo,hi in self.allowed),('Write outside fixture',hex(at),size)
        if SOURCE<=at<SOURCE+len(self.raw) and not self.setup:
            self.source_writes+=1;raise AssertionError('Borrowed source changed')
        super().write(at,value,size)

    def word(self,pc):
        # Execute actual retained import tail stubs. Their bound OS target is a
        # fixture, returning through JR RA just as the imported function does.
        if pc in API.values():
            self.reg[2]=self.hooks[pc](self)&0xffffffff
            return 0x03e00008
        if pc-4 in API.values():return 0
        return super().word(pc)

    def factory(self,m):
        assert m.reg[4:8]==[image.CLSID,0,1,image.IID]
        assert self.read(self.read(m.reg[29]+0x10))==0
        self.trace.append('CoCreateInstance')
        if self.fail=='factory_error':return 0x80004005
        if self.fail=='factory_null':return 0
        self.resources['factory']=True
        self.write(self.read(m.reg[29]+0x10),FACTORY)
        return 0x80004005 if self.fail=='factory_error_with_object' else 0

    def create_image(self,m):
        assert m.reg[4:8]==[FACTORY,SOURCE,len(self.raw),0]
        assert self.resources['factory']
        assert self.read(self.read(m.reg[29]+0x10))==0
        self.trace.append('CreateImageFromBuffer')
        if self.fail=='image_error':return 0x80004005
        if self.fail=='image_null':return 0
        self.resources['image']=True
        self.write(self.read(m.reg[29]+0x10),IM)
        return 0x80004005 if self.fail=='image_error_with_object' else 0

    def info(self,m):
        assert m.reg[4]==IM and self.resources['image']
        assert data(self,m.reg[5],40)==bytes(40)
        self.trace.append('GetImageInfo')
        if self.fail=='info_error':return 0x80004005
        self.write(m.reg[5]+16,0x21808)
        self.write(m.reg[5]+20,self.dimensions[0]);self.write(m.reg[5]+24,self.dimensions[1])
        return 0

    def create_dc(self,m):
        assert m.reg[4]==0
        assert self.resources['image']
        self.trace.append('CreateCompatibleDC')
        if self.fail=='dc_null':return 0
        self.resources['dc']=True
        return DC

    def create_dib(self,m):
        assert m.reg[4]==DC and m.reg[6]==0 and self.resources['dc']
        assert self.read(m.reg[29]+0x10)==self.read(m.reg[29]+0x14)==0
        expected=struct.pack('<IiiHHIIIIII',40,200,200,1,24,0,0,0,0,0,0)+bytes(4)
        assert data(self,m.reg[5],44)==expected
        self.trace.append('CreateDIBSection')
        if self.fail=='dib_null':return 0
        self.resources['bitmap']=True
        if self.fail!='dib_bits_null':self.write(m.reg[7],BITS)
        return BITMAP

    def select(self,m):
        assert m.reg[4]==DC and self.resources['dc']
        h=m.reg[5]
        self.trace.append('SelectObject:'+('new' if h==BITMAP else 'restore'))
        if h==BITMAP:
            assert self.resources['bitmap'] and self.selected==OLD
            if self.fail=='select_null':return 0
            if self.fail=='select_invalid':return 0xffffffff
            self.selected=BITMAP;return OLD
        assert h==OLD and self.selected==BITMAP
        if self.fail=='restore_null':return 0
        if self.fail=='restore_invalid':return 0xffffffff
        self.selected=OLD;return BITMAP

    def draw(self,m):
        assert m.reg[4:6]==[IM,DC] and m.reg[7]==0
        assert data(self,m.reg[6],16)==struct.pack('<iiii',0,0,200,200)
        assert self.selected==BITMAP and self.resources['image']
        assert data(self,SOURCE,len(self.raw))==self.raw
        self.trace.append('Draw')
        if self.fail=='draw_error':return 0x80004005
        if self.fail=='draw_pending':return 0x8000000a
        try:
            decoded=PillowImage.open(BytesIO(self.raw));decoded.load()
            assert decoded.size==(200,200)
            self.dib_pixels=decoded.convert('RGB').tobytes()
        except Exception:return 0x80004005
        return 0

    def release_image(self,m):
        assert m.reg[4]==IM and self.resources['image']
        assert data(self,SOURCE,len(self.raw))==self.raw,'Borrowed source must live until IImage release'
        self.trace.append('IImage.Release')
        self.resources['image']=False
        return 0

    def release_factory(self,m):
        assert m.reg[4]==FACTORY and self.resources['factory']
        assert not self.resources.get('image'), 'Release image before factory/source disposal'
        self.trace.append('Factory.Release');self.resources['factory']=False
        return 0

    def delete_dc(self,m):
        assert m.reg[4]==DC and self.resources['dc']
        self.trace.append('DeleteDC');self.resources['dc']=False
        self.selected=OLD
        return 1

    def delete_object(self,m):
        assert m.reg[4]==BITMAP and self.resources['bitmap'] and self.selected!=BITMAP
        self.trace.append('DeleteObject');self.resources['bitmap']=False
        return 1

    def preflight(self,at=SOURCE,length=None):
        return call(self,image.PREFLIGHT,[at,len(self.raw) if length is None else length],limit=2000000)

    def decode(self):return call(self,image.DECODE,[SOURCE,len(self.raw)],limit=2000000)

    def finish(self,result):
        assert self.selected==OLD
        assert not self.resources.get('image') and not self.resources.get('factory') and not self.resources.get('dc')
        if result:
            assert result==BITMAP and self.resources['bitmap'] and self.dib_pixels
            self.reg[4]=result;self.delete_object(self)
        assert not any(self.resources.values()) and not self.source_writes


def segments(raw):
    p=2;rows=[]
    while raw[p+1]!=0xda:
        length=int.from_bytes(raw[p+2:p+4],'big')
        rows.append((raw[p+1],p,length));p+=2+length
    rows.append((0xda,p,int.from_bytes(raw[p+2:p+4],'big')))
    return rows


def verify(raw):
    contract=image.contracts(raw);pe=pefile.PE(data=raw)
    valid,invalid,failures=[],[],[]
    body=jpeg()
    for mode,ss in (('RGB',0),('RGB',1),('RGB',2),('L',2)):
        content=jpeg(mode,ss);m=Decoder(pe,content)
        assert m.preflight()==1
        result=m.decode();assert result==BITMAP
        decoded=PillowImage.open(BytesIO(content));decoded.load()
        assert m.dib_pixels==decoded.convert('RGB').tobytes()
        m.finish(result)
        valid.append(dict(mode=mode,subsampling=ss,trace=m.trace,pixels_sha256=hashlib.sha256(m.dib_pixels).hexdigest()))
    # Exact encoded-size and segment-count boundaries, with real JPEG content.
    def pad(content,size):
        extra=size-len(content);prefix=b''
        while extra:
            n=min(extra,65537)
            if 0<extra-n<4:n-=4-(extra-n)
            assert n>=4
            prefix+=b'\xff\xef'+(n-2).to_bytes(2,'big')+bytes(n-4)
            extra-=n
        return content[:2]+prefix+content[2:]
    for label,content,wanted in (
            ('encoded_size_exact_limit',pad(body,image.MAX_IMAGE),1),
            ('encoded_size_exceeds_limit',pad(body,image.MAX_IMAGE+1),0),
            ('segment_budget_exact_limit',body[:2]+b'\xff\xef\x00\x02'*(1024-len(segments(body)))+body[2:],1),
            ('segment_budget_exceeds_limit',body[:2]+b'\xff\xef\x00\x02'*(1025-len(segments(body)))+body[2:],0)):
        m=Decoder(pe,content);assert m.preflight()==wanted,label
        m.finish(0)
        (valid if wanted else invalid).append(dict(case=label,steps=m.steps))
    # Every prefix must reject before any COM/GDI call or out-of-bounds read.
    truncations=[]
    for n in range(len(body)):
        m=Decoder(pe,body[:n]);assert not m.decode() and not m.trace
        m.finish(0);truncations.append(n)
    sof=next(p for marker,p,_ in segments(body) if marker==0xc0)
    sos=next(p for marker,p,_ in segments(body) if marker==0xda)
    mutations={'non_jpeg':b'PNG!','bad_soi':b'xx'+body[2:],'trailing':body+b'x',
               'progressive':jpeg(progressive=True),'repeat_soi':body[:2]+b'\xff\xd8'+body[2:]}
    for name,at,value in (('precision',sof+4,12),('height',sof+6,199),('width',sof+8,199),
                           ('components',sof+9,4),('sample_zero',sof+11,0),('quant_table',sof+12,4),
                           ('duplicate_frame_id',sof+13,body[sof+10]),('scan_zero',sos+4,0),
                           ('scan_foreign',sos+5,99),('scan_duplicate',sos+7,body[sos+5]),
                           ('scan_tables',sos+6,0x44),('spectral_start',sos+11,1),
                           ('spectral_end',sos+12,62),('refinement',sos+13,1)):
        value_body=bytearray(body);value_body[at]=value;mutations[name]=bytes(value_body)
    for name,content in mutations.items():
        m=Decoder(pe,content);assert not m.decode() and not m.trace,name
        m.finish(0);invalid.append(dict(case=name,source_sha256=hashlib.sha256(content).hexdigest(),steps=m.steps))
    for name,at,length in (('null',0,20),('wrap',0xfffffff0,100),('too_large',SOURCE,image.MAX_IMAGE+1)):
        m=Decoder(pe,body);assert not m.preflight(at,length) and not m.trace
        m.finish(0);invalid.append(dict(case=name,steps=m.steps))
    for name in ('factory_error','factory_null','factory_error_with_object','image_error','image_null',
                 'image_error_with_object','info_error','dc_null','dib_null','dib_bits_null',
                 'select_null','select_invalid','draw_error','draw_pending','restore_null','restore_invalid'):
        m=Decoder(pe,body,fail=name);result=m.decode();assert not result,name
        m.finish(result);failures.append(dict(case=name,trace=m.trace,steps=m.steps))
    for width,height in ((0,200),(200,0),(199,200),(200,201),(0xffffffff,200),(200,0xffffffff)):
        m=Decoder(pe,body,width=width,height=height);assert not m.decode()
        assert 'CreateCompatibleDC' not in m.trace
        m.finish(0);failures.append(dict(case='info_dimensions',width=width,height=height,trace=m.trace,steps=m.steps))
    # A structural gate must not substitute for decoding compressed pixels.
    entropy=sos+2+int.from_bytes(body[sos+2:sos+4],'big')
    content=body[:entropy]+b'\xff\xd9'
    m=Decoder(pe,content);assert not m.preflight() and not m.decode() and not m.trace
    m.finish(0);invalid.append(dict(case='empty_entropy_scan',steps=m.steps))
    dht=next(p for marker,p,_ in segments(body) if marker==0xc4)
    content=bytearray(body);content[dht+4]=0xff
    m=Decoder(pe,bytes(content));assert m.preflight()==1
    assert not m.decode();m.finish(0)
    failures.append(dict(case='structural_jpeg_with_invalid_huffman_table_requires_decoder',trace=m.trace,steps=m.steps))
    return dict(valid_decodes=4,valid_gate_cases=len(valid)-4,truncation_cases=len(truncations),invalid_cases=len(invalid),failure_cases=len(failures),
                contracts=contract,valid=valid,invalid=invalid,failures=failures,
                helpers=[{k:v for k,v in row.items() if k!='raw'} for row in assembled()],
                executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['Assembled helpers and retained AppMain import thunks execute in the instruction interpreter',
                        'COM/GDI are strict fixtures; Pillow supplies decoded pixels and failures, not the CE codec',
                        'Baseline 200x200 grayscale/RGB structural gate; compressed content still requires successful Draw',
                        'Source must be an owned readable buffer, unchanged throughout the synchronous decode call',
                        'COM Release and GDI destruction retain their normal valid-object/handle contracts',
                        'Cross-process delivery, fresh publication at paint, PE loader/unwind and physical screen checks remain open'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_image.py','verify_bt_cover_image.py','inspect_bt_cover_ui_route.py',
                              'verify_bt_cover_attribute.py','verify_bt_cover_csr_bridge.py','verify_bt_cover_owner.py','verify_media_responsiveness.py',
                              'patch_usb_seek_completion.py','patch_updater_copy_safety.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input',type=Path,required=True);p.add_argument('--report',type=Path,required=True)
    a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    report=verify(a.input.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(report,indent=2)+'\n').encode('utf-8'))
    print(json.dumps({k:v for k,v in report.items() if k.endswith('cases') or k=='valid_decodes'},indent=2))
