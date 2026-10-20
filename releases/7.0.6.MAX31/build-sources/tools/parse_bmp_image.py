"""Bounded BMP core/info-header reference reader; no native firmware or GDI execution."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

MAX_BYTES=64*1024*1024
MAX_PIXELS=4*1024*1024


def parse_bmp(raw):
    if len(raw)<26 or len(raw)>MAX_BYTES or raw[:2]!=b"BM":raise ValueError("missing/oversize BMP")
    file_size,_,_,offset=struct.unpack_from("<IHHI",raw,2)
    size=struct.unpack_from("<I",raw,14)[0]
    if size==12:
        width,height,planes,bpp=struct.unpack_from("<4H",raw,18)
        comp=used=0;palunit=3
    elif size==40:
        if len(raw)<54:raise ValueError("truncated info header")
        width,height,planes,bpp,comp,_,_,_,used,_=struct.unpack_from("<iiHHIIiiII",raw,18)
        palunit=4
    else:raise ValueError("only 12/40-byte BMP headers supported")
    if planes!=1 or width<=0 or height==0 or width*abs(height)>MAX_PIXELS:raise ValueError("invalid/oversize dimensions or planes")
    if size==12 and bpp not in [1,4,8,24]:raise ValueError("unsupported CORE bit depth")
    if bpp not in [1,4,8,16,24,32] or comp not in [0,3]:raise ValueError("unsupported bit depth/compression")
    if comp==3 and (size!=40 or bpp not in [16,32]):raise ValueError("invalid bitfields layout")
    palette_count=0 if bpp>8 else (used or 1<<bpp)
    if palette_count>1<<bpp:raise ValueError("palette exceeds bit depth")
    palette_offset=14+size;cursor=palette_offset
    masks=[0x7c00,0x3e0,0x1f] if bpp==16 else [0xff0000,0xff00,0xff]
    if comp==3:
        if cursor+12>len(raw):raise ValueError("truncated bitfields masks")
        masks=list(struct.unpack_from("<3I",raw,cursor));cursor+=12
        for mask in masks:
            if not mask or mask>=1<<bpp:raise ValueError("invalid bitfield mask")
            aligned=mask//(mask&-mask)
            if aligned&(aligned+1):raise ValueError("noncontiguous bitfield mask")
        if masks[0]&masks[1] or masks[0]&masks[2] or masks[1]&masks[2]:raise ValueError("overlapping masks")
    cursor+=palette_count*palunit
    stride=((width*bpp+31)//32)*4;pixel_bytes=stride*abs(height)
    if offset<cursor or cursor>len(raw) or offset+pixel_bytes>len(raw):raise ValueError("truncated/overlapping BMP ranges")
    return dict(format="BMP",header_bytes=size,width=width,height=abs(height),signed_height=height,
        top_down=height<0,planes=planes,bpp=bpp,compression=comp,file_size_field=file_size,
        actual_file_bytes=len(raw),file_size_matches=file_size==len(raw),pixel_offset=offset,
        pixel_stride=stride,pixel_bytes=pixel_bytes,palette_offset=palette_offset,palette_count=palette_count,
        palette_entry_bytes=palunit,color_masks=[hex(m) for m in masks],binary_execution=False)


def reference_rgb(raw,meta=None):
    meta=meta or parse_bmp(raw);width=meta["width"];height=meta["height"];bpp=meta["bpp"]
    colors=[]
    for i in range(meta["palette_count"]):
        at=meta["palette_offset"]+i*meta["palette_entry_bytes"];blue,green,red=raw[at:at+3]
        colors.append(bytes([red,green,blue]))
    masks=[int(m,16) for m in meta["color_masks"]];out=bytearray()
    for y in range(height):
        row=y if meta["top_down"] else height-1-y
        at=meta["pixel_offset"]+row*meta["pixel_stride"]
        for x in range(width):
            if bpp<=8:
                index=raw[at+x] if bpp==8 else (raw[at+x//2]>>(4*(1-x%2)))&15 if bpp==4 else (raw[at+x//8]>>(7-x%8))&1
                if index>=len(colors):raise ValueError("palette index outside declared table")
                out.extend(colors[index])
            elif bpp==24:
                blue,green,red=raw[at+3*x:at+3*x+3];out.extend([red,green,blue])
            else:
                n=bpp//8;pixel=int.from_bytes(raw[at+n*x:at+n*x+n],"little")
                for mask in masks:
                    least=mask&-mask;maximum=mask//least;value=(pixel&mask)//least
                    out.append(value*255//maximum)
    return bytes(out)


def fixture(bpp=24,top=False,core=False,bitfields=False):
    width=height=2;stride=((width*bpp+31)//32)*4
    palette=[(255,0,0),(0,255,0),(0,0,255),(255,255,255)]
    indices=[0,1,2,3] if bpp!=1 else [0,1,1,0]
    if bpp==1:palette=[(255,0,0),(0,0,255)]
    count=1<<bpp if bpp<=8 else 0;unit=3 if core else 4
    table=b"".join(bytes([blue,green,red])+b"\0"*(unit-3) for red,green,blue in
        (palette+[(0,0,0)]*count)[:count])
    masks=struct.pack("<3I",0xf800,0x7e0,0x1f) if bitfields else b""
    header=struct.pack("<I4H",12,width,height,1,bpp) if core else struct.pack("<IiiHHIIiiII",40,width,-height if top else height,1,bpp,3 if bitfields else 0,stride*height,0,0,0,0)
    rows=[];expected=b"".join(bytes(palette[i]) for i in indices)
    for row in [indices[:2],indices[2:]]:
        if bpp==1:packed=bytes([(row[0]<<7)|(row[1]<<6)])
        elif bpp==4:packed=bytes([(row[0]<<4)|row[1]])
        elif bpp==8:packed=bytes(row)
        elif bpp==16:
            values=[0xf800,0x7e0,0x1f,0xffff] if bitfields else [0x7c00,0x3e0,0x1f,0x7fff]
            packed=b"".join(struct.pack("<H",values[i]) for i in row)
        else:packed=b"".join(bytes(palette[i][::-1])+(b"\x5a" if bpp==32 else b"") for i in row)
        rows.append(packed+b"\0"*(stride-len(packed)))
    offset=14+len(header)+len(masks)+len(table);pixels=b"".join(rows if top else reversed(rows))
    return b"BM"+struct.pack("<IHHI",offset+len(pixels),0,0,offset)+header+masks+table+pixels,expected


def self_test():
    from io import BytesIO
    from PIL import Image
    cases=[]
    for bpp in [1,4,8,16,24,32]:
        for top in [False,True]:cases.append(fixture(bpp,top))
    for bpp in [1,4,8,24]:cases.append(fixture(bpp,core=True))
    cases.append(fixture(16,bitfields=True))
    for raw,expected in cases:
        meta=parse_bmp(raw);assert reference_rgb(raw,meta)==expected
        with Image.open(BytesIO(raw)) as im:assert im.convert("RGB").tobytes()==expected
    raw,_=fixture();invalid=[raw[:-1],b"ZZ"+raw[2:],raw[:14]+struct.pack("<I",108)+raw[18:],
        raw[:18]+struct.pack("<i",0)+raw[22:],raw[:26]+struct.pack("<H",2)+raw[28:],
        fixture(16,core=True)[0],fixture(32,core=True)[0]]
    rejected=0
    for bad in invalid:
        try:parse_bmp(bad)
        except ValueError:rejected+=1
        else:raise AssertionError("invalid BMP accepted")
    return dict(status="passed",rgb_fixtures=len(cases),independent_pillow_matches=len(cases),rejected_inputs=rejected)


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument("path",nargs="?")
    ap.add_argument("--self-test",action="store_true");ap.add_argument("--rgb-hash",action="store_true")
    args=ap.parse_args()
    if args.self_test:result=self_test()
    elif args.path:
        with Path(args.path).open("rb") as stream:raw=stream.read(MAX_BYTES+1)
        result=parse_bmp(raw)
        if args.rgb_hash:result["reference_rgb_sha256"]=hashlib.sha256(reference_rgb(raw,result)).hexdigest()
    else:ap.error("provide a local BMP or --self-test")
    print(json.dumps(result,indent=2))


if __name__=="__main__":main()
