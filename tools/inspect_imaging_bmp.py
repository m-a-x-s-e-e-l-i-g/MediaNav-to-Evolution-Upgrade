"""Preserve BMP decoder ranges and compare bounded image layouts with real firmware assets."""
import hashlib
import json
import struct
from collections import Counter
from pathlib import Path
import pefile
from PIL import Image
from inspect_usb_metadata import IMAGING_HASH
from parse_bmp_image import parse_bmp,reference_rgb,self_test

ROOT=Path(__file__).resolve().parents[1]


def palette_count(bpp,compression,used):
    if compression==3:return 3 if bpp in [16,32] else 0
    if bpp in [1,4,8]:return used if 0<used<=1<<bpp else 1<<bpp
    return 0


def pixel_format(bpp,compression):
    if compression:return 0x22009
    return {1:0x30101,4:0x30402,8:0x30803,16:0x21005,24:0x21808,32:0x22009,64:0x34400d}.get(bpp,0)


def png_format(color,depth,transparent):
    fmt=0x26200a
    if color==0:pass
    elif color==2:
        if depth==8:fmt=0x21808
        elif depth==16:fmt=0x10300c
        else:return 0
    elif color==3:
        if depth==1:fmt=0x30101
        elif depth==2:pass
        elif depth==4:fmt=0x30402
        elif depth==8:fmt=0x30803
        else:return 0
    elif color==4:
        if depth not in [8,16]:return 0
    elif color==6:
        if depth==16:fmt=0x34400d
        elif depth!=8:return 0
    else:return 0
    return 0x26200a if transparent else fmt


def signed(n):
    n&=0xffffffff;return n if n<0x80000000 else n-0x100000000


def native_stride(width,bpp):
    product=signed(width*bpp);plus=signed(product+7)
    if plus<0:plus=signed(product+14)
    return ((plus>>3)+3)&0xfffffffc


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module=next(m for m in modules if m["origin"]=="rom" and m["name"]=="imaging.dll")
    path=ROOT/module["path"];assert hashlib.sha256(path.read_bytes()).hexdigest()==IMAGING_HASH
    pe=pefile.PE(str(path));base=pe.OPTIONAL_HEADER.ImageBase
    fs=json.loads((ROOT/"analysis/functions/rom/imaging.dll.json").read_text(encoding="utf-8"))["functions"]
    by_va={int(f["begin_va"],16):f["bytes"] for f in fs}
    addresses=[0x404a2028,0x404a22b4,0x404a23a4,0x404a2400,0x404a2478,0x404a2500,0x404a2608,
        0x404a2840,0x404a28a4,0x404a2918,0x404a29dc,0x404a2b2c,0x404a3234,0x404a33fc,
        0x404a3614,0x404a3760,0x404a3888,0x404a3ac4,0x4049654c,0x4049675c,0x40499734,
        0x404998d0,0x4049d1dc,0x4049d3c4,0x40498c10,0x404980a0,0x4049a634,0x404a1a14,0x4048fac8,
        0x404a6a18,0x404a5248]
    leaves={0x404a2478:0x88,0x404a2608:0xcc,0x404980a0:0x158}
    ranges=[(a,by_va[a] if a in by_va else leaves[a],"pdata" if a in by_va else "bounded leaf span") for a in addresses]
    vtables=[]
    for name,va in [("BMP",0x40484d88),("PNG",0x40484038),("GIF",0x404849dc),("JPEG",0x40484bcc)]:
        ranges.append((va,68,"first 17 codec vtable slots"))
        slots=struct.unpack("<17I",pe.get_data(va-base,68))
        vtables.append(dict(codec=name,va=hex(va),slots=[hex(x) for x in slots],initialize=hex(slots[3]),
            begin_decode=hex(slots[5]),decode=hex(slots[6]),end_decode=hex(slots[7]),image_info=hex(slots[12])))
    evidence=[]
    for va,n,boundary in ranges:
        raw=pe.get_data(va-base,n);assert len(raw)==n
        evidence.append(dict(va=hex(va),bytes=n,boundary=boundary,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    palettes=[]
    for bpp in range(65):
        for compression in range(5):
            for used in [0,1,2,16,255,256,257,0xffffffff]:
                count=palette_count(bpp,compression,used);assert 0<=count<=256
                palettes.append(dict(bpp=bpp,compression=compression,clr_used=used,count=count))
    stride_checks=0;row_checks=0
    for bpp in [1,4,8,16,24,32,64]:
        for width in range(1,1025):
            expected=((width*bpp+31)//32)*4;assert native_stride(width,bpp)==expected;stride_checks+=1
            for height in [1,2,8]:
                for top in [False,True]:
                    offsets=[(row if top else height-1-row)*expected for row in range(height)]
                    assert sorted(offsets)==[row*expected for row in range(height)];row_checks+=1
    overflow=[]
    for width,bpp in [(0x8000000,32),(0x4000000,64),(0x10000000,16),(0x20000000,8)]:
        actual=native_stride(width,bpp);reference=((width*bpp+31)//32)*4
        assert actual==0 and reference==0x20000000
        overflow.append(dict(width=width,bpp=bpp,native_row_allocation=actual,reference_stride=reference))
    assets=[];stats=Counter();samples={}
    for path in sorted((ROOT/"extracted/705md").rglob("*.bmp")):
        raw=path.read_bytes();meta=parse_bmp(raw);stats[(meta["header_bytes"],meta["bpp"],meta["compression"],meta["top_down"])]+=1
        assets.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=hashlib.sha256(raw).hexdigest(),**meta))
        samples.setdefault(meta["bpp"],(path,raw,meta))
    compared=[]
    for bpp,(path,raw,meta) in samples.items():
        own=reference_rgb(raw,meta)
        with Image.open(path) as im:other=im.convert("RGB").tobytes()
        assert own==other
        compared.append(dict(path=path.relative_to(ROOT).as_posix(),bpp=bpp,width=meta["width"],height=meta["height"],
            reference_rgb_sha256=hashlib.sha256(own).hexdigest(),independent_decoder="Pillow",matches=True))
    png=[dict(color_type=c,bit_depth=d,trns=t,pixel_format=hex(png_format(c,d,t)))
        for c in [0,2,3,4,6] for d in [1,2,4,8,16] for t in [False,True]]
    assert png_format(2,16,False)==0x10300c and png_format(2,16,True)==0x26200a
    png_dimensions=[]
    for w,h,expected in [(65535,1,True),(65536,1,False),(1,65535,True),(1,65536,False),
            (4096,16384,True),(4096,16385,False),(8192,8192,True),(8192,8193,False),
            (65535,65535,False)]:
        passed=w<=65535 and h<=65535 and w*h<=0x4000000;assert passed==expected
        png_dimensions.append(dict(width=w,height=h,passes_followed_dimension_guard=passed))
    checks=dict(preserved_ranges=len(evidence),codec_vtables=len(vtables),palette_cases=len(palettes),
        stride_cases=stride_checks,row_order_cases=row_checks,overflow_examples=len(overflow),
        real_bmp_layouts=len(assets),real_rgb_pillow_matches=len(compared),png_format_cases=len(png),
        png_dimension_cases=len(png_dimensions),fixtures=self_test())
    result=dict(binary_execution=False,source=dict(module=module["name"],path=module["path"],sha256=IMAGING_HASH,ranges=evidence),
        codec_vtables=vtables,palette_cases=palettes,bmp_pixel_formats={str(n):hex(pixel_format(n,0)) for n in [1,4,8,16,24,32,64]},
        usb_bitfields_example=dict(width=2,height=2,bpp=16,bf_off_bits=66,actual_fixture_bytes=74,
            actual_pixel_bytes=8,reported_stream_bytes=0x800000,native_scratch_allocation=0x800000-66),
        row_overflow_examples=overflow,png_format_cases=png,png_dimension_cases=png_dimensions,
        real_asset_formats=[dict(header=h,bpp=b,compression=c,top_down=t,count=n) for (h,b,c,t),n in stats.items()],
        real_assets=assets,real_rgb_comparisons=compared,checks=checks,
        limitations=["Reference parser/decoder is bounded and stricter than native header parsing",
            "Arithmetic overflow examples are calculated only; no huge allocation or native GDI call is performed",
            "PNG format model describes the mapper; earlier parser acceptance and PNG pixel decoding remain open",
            "Pillow comparisons prove independent reference RGB agreement, not native device rendering",
            "Four vtable excerpts contain first 17 slots, not the complete interfaces"])
    (ROOT/"analysis/firmware/imaging-bmp-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**checks),indent=2))


if __name__=="__main__":main()
