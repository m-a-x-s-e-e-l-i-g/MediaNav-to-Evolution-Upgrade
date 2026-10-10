"""Preserve 54 PNG scatter helpers and verify converter arithmetic without firmware execution."""
import hashlib
import json
import struct
from fractions import Fraction
from io import BytesIO
from pathlib import Path
import pefile
from PIL import Image
from inspect_imaging_png import preserve
from inspect_usb_metadata import IMAGING_HASH
from parse_png_image import SIGNATURE,chunk,parse_png,reference_rgba,CHANNELS,PASSES
from png_pixel_models import BITS,pack_pixels,unpack_pixels,bgra_row,extended_row,scatter_native,selected_passes
import zlib

ROOT=Path(__file__).resolve().parents[1]


def make_png(width,color,depth,row,palette=b"",trns=b""):
    header=struct.pack(">IIBBBBB",width,1,depth,color,0,0,0)
    return SIGNATURE+chunk(b"IHDR",header)+(chunk(b"PLTE",palette) if palette else b"")+\
        (chunk(b"tRNS",trns) if trns else b"")+chunk(b"IDAT",zlib.compress(b"\0"+row))+chunk(b"IEND",b"")


def rgba(bgra):
    out=bytearray(bgra)
    out[0::4]=bgra[2::4];out[2::4]=bgra[0::4]
    return bytes(out)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module=next(m for m in modules if m["origin"]=="rom" and m["name"]=="imaging.dll")
    assert module["sha256"]==IMAGING_HASH
    pe=pefile.PE(str(ROOT/module["path"]));base=pe.OPTIONAL_HEADER.ImageBase
    table=struct.unpack("<54I",pe.get_data(0x404850d8-base,216));assert len(set(table))==54
    addresses=sorted(table);extras=[];dispatch=[]
    for group,bits in enumerate(BITS):
        for pas in range(1,7):
            va=table[group*6+pas-1];end=min(a for a in addresses+[0x404a87b4] if a>va)
            raw=pe.get_data(va-base,end-va);assert raw[-8:-4]==struct.pack("<I",0x03e00008)
            extras.append((va,end-va,"scatter leaf: final jr ra plus delay slot"))
            dispatch.append(dict(bits_per_pixel=bits,pass_number=pas,va=hex(va),bytes=end-va,
                start_x=PASSES[pas-1][0],pixel_step=PASSES[pas-1][2],byte_order_preserved=True))
    leaves=[(0x404981f8,0x2c4),(0x404984bc,0x16c),(0x404989b4,0xc4),
        (0x40498a78,0xe4),(0x40497c2c,0x118),(0x40497d44,0x16c)]
    for va,n in leaves:
        assert pe.get_data(va-base+n-8,4)==struct.pack("<I",0x03e00008)
        extras.append((va,n,"converter leaf: final jr ra plus delay slot"))
    extras.extend([(0x404850d8,216,"nine bits-per-pixel rows times six scatter pointers"),
        (0x404851b0,448,"twelve 16-entry packed-scatter lookup tables")])
    source=preserve(module,[0x404990c8,0x40498628,0x404991cc,0x404993f4,0x404a87b4,0x404a89b8,0x404a5248],extras)
    tables=pe.get_data(0x404851b0-base,448)
    # Compare original tables with bit positions, not another copy of their constants.
    lookup_checks=0
    for bits in [1,2]:
        for pas in range(1,7):
            start,_,step,_=PASSES[pas-1];entry_size=[4,2,1][(pas-1)//2]
            at=(bits-1)*224+[0,64,128,160,192,208][pas-1]
            for nibble in range(16):
                expected=bytearray(entry_size)
                for i in range(4//bits):
                    value=(nibble>>(4-bits-i*bits))&((1<<bits)-1);pixel=start+i*step
                    expected[pixel*bits//8]|=value<<(8-bits-pixel*bits%8)
                assert tables[at+nibble*entry_size:at+(nibble+1)*entry_size]==expected
                lookup_checks+=1
    scatter_checks=0;even_row_checks=0
    for bits in BITS:
        for width in range(1,129):
            pixels=[(i*7+3)&((1<<bits)-1) for i in range(width)] if bits<8 else [bytes((i*37+j*13)&255 for j in range(bits//8)) for i in range(width)]
            row_bytes=(width*bits+7)//8;allocation=(row_bytes+8)&~7
            for pas in range(1,7):
                start,_,step,_=PASSES[pas-1];samples=pixels[start::step];output=bytearray(allocation)
                scatter_native(pack_pixels(samples,bits),width,bits,pas,output,tables)
                expected=[0]*width if bits<8 else [bytes(bits//8)]*width
                for i,n in enumerate(samples):expected[start+i*step]=n
                assert unpack_pixels(output,width,bits)==expected;scatter_checks+=1
            for y in [0,2,4,6]:
                output=bytearray([0xa5]*allocation)
                for pas in selected_passes(y):
                    start,_,step,_=PASSES[pas-1]
                    scatter_native(pack_pixels(pixels[start::step],bits),width,bits,pas,output,tables)
                assert unpack_pixels(output,width,bits)==pixels;even_row_checks+=1
    # Arithmetic bounds over the entire followed positive width range; no large buffers.
    bound_checks=0;max_padding_write=0
    for bits in BITS:
        for width in range(1,65536):
            row_bytes=(width*bits+7)//8;allocation=(row_bytes+8)&~7
            for pas in range(1,7):
                start,_,step,_=PASSES[pas-1];count=max(0,(width-start+step-1)//step)
                if not count:end=0
                elif bits in [1,2]:end=((count*bits+7)//8)*2*[4,2,1][(pas-1)//2]
                elif bits==4:
                    source_bytes=(count+1)//2
                    end=source_bytes*2 if pas==6 else start//2+(source_bytes*2-1)*(step//2)+1
                else:end=(start+(count-1)*step+1)*(bits//8)
                assert end<=allocation
                max_padding_write=max(max_padding_write,end-row_bytes);bound_checks+=1
    cases=0;mismatches=0
    for key in [0,1]:
        for byte in range(256):
            data=bytes([byte]);native=bgra_row(data,8,0,1,trns=struct.pack(">H",key),native=True)
            reference=bgra_row(data,8,0,1,trns=struct.pack(">H",key))
            mismatches+=sum(a!=b for a,b in zip(native[3::4],reference[3::4]));cases+=8
    assert cases==4096 and mismatches==896
    gray16_pairs=0;gray16_false=0
    for key in [0,1,255,256,0x1234,65535]:
        for sample in range(65536):
            native=(sample>>8)==(key>>8);reference=sample==key
            gray16_false+=native and not reference;gray16_pairs+=1
    assert gray16_false==1530
    rgb_key=(0x1234,0x4567,0x89ab);rgb_false=0;rgb_pairs=0
    for channel in range(3):
        for low in range(256):
            samples=list(rgb_key);samples[channel]=(samples[channel]&0xff00)|low
            data=struct.pack(">3H",*samples);key=struct.pack(">3H",*rgb_key)
            a=bgra_row(data,1,2,16,trns=key,native=True)[3];b=bgra_row(data,1,2,16,trns=key)[3]
            rgb_false+=a!=b;rgb_pairs+=1
    assert rgb_false==765
    # Cross-check the extended scaling with exact rational rounding for every u16 value.
    for n in range(65536):
        exact=Fraction(n*8192,65535)+Fraction(1,2)
        assert (n*8192+32767)//65535==exact.numerator//exact.denominator
    extended=[]
    for color,samples in [(2,(0,32768,65535)),(6,(0x1234,0x4567,0x89ab,0xcdef))]:
        data=struct.pack(">"+"H"*len(samples),*samples);converted=extended_row(data,color)
        extended.append(dict(color_type=color,input_hex=data.hex(),output_hex=converted.hex(),channels=list(struct.unpack("<"+"H"*len(samples),converted))))
    fixtures=[]
    for color,depth in [(0,1),(0,2),(0,4),(0,8),(2,8),(3,1),(3,2),(3,4),(3,8),(4,8),(6,8)]:
        for transparent in [False,True] if color in [0,2,3] else [False]:
            width=17;channels=CHANNELS[color];palette=b"";trns=b""
            if color in [0,3]:
                values=[i%(1<<depth) for i in range(width)];data=bytes(values) if depth==8 else pack_pixels(values,depth)
                if color==3:palette=bytes((i*43+j*67)&255 for i in range(1<<depth) for j in range(3))
                if transparent:trns=bytes((i*31)&255 for i in range(1<<depth)) if color==3 else b"\0\0"
            else:
                data=bytes((i*41+j*23)&255 for i in range(width) for j in range(channels))
                if transparent:trns=struct.pack(">3H",*data[:3])
            raw=make_png(width,color,depth,data,palette,trns);meta,rows=parse_png(raw)
            model=bgra_row(data,width,color,depth,palette,trns,native=True)
            assert rgba(model)==reference_rgba(meta,rows)
            with Image.open(BytesIO(raw)) as im:assert im.convert("RGBA").tobytes()==rgba(model)
            fixtures.append(dict(color_type=color,depth=depth,trns=transparent,width=width,sha256=hashlib.sha256(raw).hexdigest(),pillow_matches=True))
    demonstrations=[]
    for label,color,depth,width,data,trns in [
        ("white transparency differs at seven bit positions",0,1,8,b"\xff",b"\0\1"),
        ("gray16 low-byte mismatch becomes transparent",0,16,2,bytes.fromhex("12341235"),bytes.fromhex("1234")),
        ("rgb16 low-byte mismatch becomes transparent",2,16,2,bytes.fromhex("1234456789ab1235456789ab"),bytes.fromhex("1234456789ab"))]:
        raw=make_png(width,color,depth,data,trns=trns);meta,rows=parse_png(raw)
        assert rows[0][2]==data
        native=bgra_row(data,width,color,depth,trns=trns,native=True);reference=bgra_row(data,width,color,depth,trns=trns)
        assert native!=reference
        if depth==1:
            assert reference_rgba(meta,rows)==rgba(reference)
            with Image.open(BytesIO(raw)) as im:assert im.convert("RGBA").tobytes()==rgba(reference)
        demonstrations.append(dict(label=label,color_type=color,depth=depth,width=width,png_hex=raw.hex(),
            native_model_bgra_hex=native.hex(),reference_bgra_hex=reference.hex(),
            independent_reference="Pillow plus exact samples" if depth==1 else "exact original sample comparison",
            scope="Arithmetic projection compared with exact original-sample transparency; firmware not executed"))
    fallback=bgra_row(b"\x02",1,3,8,b"\xff\0\0",b"\0",native=True)
    assert fallback==b"\0\0\0\xff"
    checks=dict(preserved_ranges=len(source["ranges"]),scatter_helpers=len(dispatch),original_lookup_entries=lookup_checks,
        individual_scatter_cases=scatter_checks,complete_even_row_cases=even_row_checks,
        positive_width_scatter_bound_cases=bound_checks,max_write_beyond_valid_row_bytes=max_padding_write,gray1_alpha_cases=cases,
        gray1_alpha_mismatches=mismatches,gray16_sample_key_pairs=gray16_pairs,gray16_false_transparent=gray16_false,
        rgb16_sample_key_pairs=rgb_pairs,rgb16_false_transparent=rgb_false,extended_scale_values=65536,
        png_converter_pillow_fixtures=len(fixtures),transparency_demonstrations=len(demonstrations))
    result=dict(binary_execution=False,source=source,scatter_dispatch=dispatch,checks=checks,fixtures=fixtures,
        transparency_demonstrations=demonstrations,extended_examples=extended,
        palette_fallback=dict(index=2,palette_entries=1,native_model_bgra_hex=fallback.hex()),
        limitations=["Arithmetic models are manually reconstructed from reviewed assembly, not native decoder execution",
            "Scatter pixel checks cover widths 1..128; arithmetic write bounds cover positive widths 1..65535",
            "Malformed dimensions, invalid color/depth dispatch and whole interlaced allocation arithmetic remain open",
            "Converter checks do not prove sink validation, premultiplication or display/runtime behavior",
            "16-bit transparency demonstrations compare full original samples; Pillow is not used as their oracle",
            "Extended output is the native numeric 0..8192 mapping; downstream extended sink semantics remain open"])
    (ROOT/"analysis/firmware/png-pixel-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**checks),indent=2))


if __name__=="__main__":main()
