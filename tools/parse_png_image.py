"""Bounded static PNG reader: CRC, zlib, filters and Adam7; no native codec execution."""
import argparse
import hashlib
import json
import struct
import zlib
from pathlib import Path

SIGNATURE=b"\x89PNG\r\n\x1a\n"
MAX_BYTES=32*1024*1024
MAX_PIXELS=4*1024*1024
PASSES=[(0,0,8,8),(4,0,8,8),(0,4,4,8),(2,0,4,4),(0,2,2,4),(1,0,2,2),(0,1,1,2)]
CHANNELS={0:1,2:3,3:1,4:2,6:4}


def geometry(width,height,interlace):
    result=[]
    for x,y,dx,dy in PASSES if interlace else [(0,0,1,1)]:
        w=max(0,(width-x+dx-1)//dx);h=max(0,(height-y+dy-1)//dy)
        result.append((x,y,dx,dy,w,h))
    return result


def paeth(a,b,c):
    p=a+b-c;da=abs(p-a);db=abs(p-b);dc=abs(p-c)
    return a if da<=db and da<=dc else b if db<=dc else c


def unfilter(data,previous,bpp,kind):
    if kind not in range(5):raise ValueError("invalid PNG filter")
    if kind==0 or kind==2 and previous is None:return bytes(data)
    if kind==2:return bytes((v+b)&255 for v,b in zip(data,previous))
    result=bytearray(data)
    for i,v in enumerate(result):
        a=result[i-bpp] if i>=bpp else 0;b=previous[i] if previous else 0
        c=previous[i-bpp] if previous and i>=bpp else 0
        predictor=a if kind==1 else (a+b)//2 if kind==3 else paeth(a,b,c)
        result[i]=(v+predictor)&255
    return bytes(result)


def parse_png(raw):
    if len(raw)>MAX_BYTES or raw[:8]!=SIGNATURE:raise ValueError("missing/oversize PNG")
    cursor=8;chunks=[];idat=[];palette=b"";trns=b"";header=None;ended=False;after_data=False
    while cursor<len(raw):
        if len(chunks)>=5000 or cursor+12>len(raw):raise ValueError("invalid chunk count/header")
        length,kind=struct.unpack_from(">I4s",raw,cursor);end=cursor+12+length
        if length>0x7fffffff or end>len(raw):raise ValueError("truncated/oversize chunk")
        data=raw[cursor+8:end-4];crc=struct.unpack_from(">I",raw,end-4)[0]
        if zlib.crc32(kind+data)!=crc:raise ValueError("PNG CRC mismatch")
        chunks.append(dict(type=kind.decode("ascii"),bytes=length,offset=cursor,crc=hex(crc)))
        if header is None and kind!=b"IHDR":raise ValueError("IHDR must be first")
        if kind==b"IHDR":
            if header is not None or length!=13:raise ValueError("invalid/duplicate IHDR")
            w,h,depth,color,compression,filter_method,interlace=struct.unpack(">IIBBBBB",data)
            valid={0:[1,2,4,8,16],2:[8,16],3:[1,2,4,8],4:[8,16],6:[8,16]}
            if not w or not h or w*h>MAX_PIXELS or depth not in valid.get(color,[]):raise ValueError("invalid/oversize PNG header")
            if compression or filter_method or interlace not in [0,1]:raise ValueError("unsupported PNG methods")
            header=(w,h,depth,color,interlace)
        elif kind==b"PLTE":
            if palette or idat or not length or length%3 or length>768:raise ValueError("invalid PLTE")
            palette=data
        elif kind==b"tRNS":
            if trns or idat:raise ValueError("invalid tRNS order")
            trns=data
        elif kind==b"IDAT":
            if after_data:raise ValueError("nonconsecutive IDAT")
            idat.append(data)
        elif kind==b"IEND":
            if length or not idat:raise ValueError("invalid IEND")
            ended=True;cursor=end;break
        elif kind in [b"acTL",b"fcTL",b"fdAT"]:raise ValueError("APNG not implemented")
        elif kind[0]&32==0:raise ValueError("unknown critical chunk")
        if idat and kind!=b"IDAT":after_data=True
        cursor=end
    if not ended or cursor!=len(raw):raise ValueError("missing IEND/trailing data")
    w,h,depth,color,interlace=header
    if color==3 and (not palette or len(palette)//3>1<<depth or len(trns)>len(palette)//3):raise ValueError("invalid indexed palette")
    if trns and ((color==0 and len(trns)!=2) or (color==2 and len(trns)!=6) or color in [4,6]):raise ValueError("invalid transparency")
    bits=CHANNELS[color]*depth;passes=geometry(w,h,interlace)
    expected=sum(((pw*bits+7)//8+1)*ph for _,_,_,_,pw,ph in passes if pw and ph)
    if expected>MAX_BYTES:raise ValueError("oversize scanline output")
    stream=zlib.decompressobj();decoded=stream.decompress(b"".join(idat),expected+1)
    if len(decoded)!=expected or not stream.eof or stream.unused_data or stream.unconsumed_tail:raise ValueError("invalid/truncated zlib output")
    rows=[];at=0
    for number,(x,y,dx,dy,pw,ph) in enumerate(passes):
        if not pw or not ph:continue
        size=(pw*bits+7)//8;previous=None
        for line in range(ph):
            kind=decoded[at];data=unfilter(decoded[at+1:at+1+size],previous,max(1,(bits+7)//8),kind)
            rows.append((number,line,data));previous=data;at+=size+1
    meta=dict(format="PNG",width=w,height=h,depth=depth,color_type=color,channels=CHANNELS[color],interlace=interlace,
        compressed_idat_bytes=sum(len(d) for d in idat),filtered_bytes=expected,scanlines=len(rows),chunks=chunks,
        palette_hex=palette.hex(),transparency_hex=trns.hex(),binary_execution=False,
        limitations=["Static PNG core only; APNG rejected; color management and text metadata are not interpreted",
            "RGBA reference conversion supports sample depths up to 8; 16-bit samples remain in unfiltered scanlines"])
    return meta,rows


def reference_rgba(meta,rows):
    w=meta["width"];h=meta["height"];depth=meta["depth"];color=meta["color_type"]
    if depth>8:raise ValueError("RGBA reference conversion requires depth <=8")
    channels=CHANNELS[color];palette=bytes.fromhex(meta["palette_hex"]);trns=bytes.fromhex(meta["transparency_hex"])
    output=bytearray(w*h*4);passes=geometry(w,h,meta["interlace"])
    for number,line,data in rows:
        x,y,dx,dy,pw,_=passes[number]
        if depth==8 and color in [2,6] and not trns:
            start=((y+line*dy)*w+x)*4;step=dx*4;end=start+pw*step
            for channel in range(3):output[start+channel:end+channel:step]=data[channel::channels]
            output[start+3:end+3:step]=data[3::4] if color==6 else bytes([255])*pw
            continue
        for i in range(pw):
            if depth==8:samples=data[i*channels:(i+1)*channels]
            else:samples=bytes([(data[(i*depth)//8]>>(8-depth-(i*depth)%8))&((1<<depth)-1)])
            alpha=255
            if color==3:
                index=samples[0]
                if index>=len(palette)//3:raise ValueError("palette index out of range")
                rgb=palette[3*index:3*index+3];alpha=trns[index] if index<len(trns) else 255
            elif color==0:
                gray=samples[0]*255//((1<<depth)-1);rgb=bytes([gray]*3)
                if trns and samples[0]==int.from_bytes(trns,"big"):alpha=0
            elif color==2:
                rgb=samples
                if trns and tuple(samples)==struct.unpack(">3H",trns):alpha=0
            elif color==4:rgb=bytes([samples[0]]*3);alpha=samples[1]
            else:rgb=samples[:3];alpha=samples[3]
            at=((y+line*dy)*w+x+i*dx)*4;output[at:at+4]=rgb+bytes([alpha])
    return bytes(output)


def chunk(kind,data):
    return struct.pack(">I",len(data))+kind+data+struct.pack(">I",zlib.crc32(kind+data))


def fixture(interlace=0,color=2,depth=8,filter_type=0):
    w,h=9,9;channels=CHANNELS[color];palette=bytes((i*71+j*49)&255 for i in range(1<<depth) for j in range(3)) if color==3 else b""
    samples=[];expected=bytearray()
    for y in range(h):
        row=[]
        for x in range(w):
            if color==3:
                s=bytes([(x+y)% (1<<depth)]);rgb=palette[3*s[0]:3*s[0]+3];alpha=255
            elif color==0:s=bytes([(x*23+y*11)&255]);rgb=s*3;alpha=255
            elif color==4:s=bytes([(x*23+y*11)&255,(x*31+y*7)&255]);rgb=s[:1]*3;alpha=s[1]
            elif color==6:s=bytes([(x*23)&255,(y*21)&255,(x+y)*13&255,(x*31+y*7)&255]);rgb=s[:3];alpha=s[3]
            else:s=bytes([(x*23)&255,(y*21)&255,(x+y)*13&255]);rgb=s;alpha=255
            row.append(s);expected.extend(rgb+bytes([alpha]))
        samples.append(row)
    filtered=bytearray();bits=channels*depth;bpp=max(1,(bits+7)//8)
    for x,y,dx,dy,pw,ph in geometry(w,h,interlace):
        if not pw or not ph:continue
        previous=None
        for line in range(ph):
            values=b"".join(samples[y+line*dy][x+i*dx] for i in range(pw))
            if depth<8:
                packed=bytearray((pw*depth+7)//8)
                for i,v in enumerate(values):packed[i*depth//8]|=v<<(8-depth-i*depth%8)
                values=bytes(packed)
            encoded=bytearray()
            for i,v in enumerate(values):
                a=values[i-bpp] if i>=bpp else 0;b=previous[i] if previous else 0;c=previous[i-bpp] if previous and i>=bpp else 0
                encoded.append((v-[0,a,b,(a+b)//2,paeth(a,b,c)][filter_type])&255)
            filtered.extend(bytes([filter_type])+encoded);previous=values
    compressed=zlib.compress(filtered);split=len(compressed)//2
    header=struct.pack(">IIBBBBB",w,h,depth,color,0,0,interlace)
    raw=SIGNATURE+chunk(b"IHDR",header)+(chunk(b"PLTE",palette) if palette else b"")+chunk(b"IDAT",compressed[:split])+chunk(b"IDAT",compressed[split:])+chunk(b"IEND",b"")
    return raw,bytes(expected)


def self_test():
    from io import BytesIO
    from PIL import Image
    count=0
    for interlace in [0,1]:
        for color,depth in [(0,8),(2,8),(3,1),(3,2),(3,4),(3,8),(4,8),(6,8)]:
            for kind in range(5):
                raw,expected=fixture(interlace,color,depth,kind);meta,rows=parse_png(raw)
                assert reference_rgba(meta,rows)==expected
                with Image.open(BytesIO(raw)) as im:assert im.convert("RGBA").tobytes()==expected
                count+=1
    raw,_=fixture();bad_crc=bytearray(raw);bad_crc[29]^=1
    invalid=[raw[:-1],bytes(bad_crc),raw+b"extra",SIGNATURE+chunk(b"IHDR",b"\0"*13)+chunk(b"IEND",b"")]
    rejected=0
    for bad in invalid:
        try:parse_png(bad)
        except (ValueError,zlib.error):rejected+=1
        else:raise AssertionError("invalid PNG accepted")
    try:unfilter(b"abc",None,1,5)
    except ValueError:rejected+=1
    else:raise AssertionError("invalid filter accepted")
    return dict(status="passed",rgba_fixtures=count,pillow_matches=count,rejected_inputs=rejected)


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument("path",nargs="?")
    ap.add_argument("--self-test",action="store_true");ap.add_argument("--rgba-hash",action="store_true")
    args=ap.parse_args()
    if args.self_test:result=self_test()
    elif args.path:
        with Path(args.path).open("rb") as stream:raw=stream.read(MAX_BYTES+1)
        result,rows=parse_png(raw)
        if args.rgba_hash:result["reference_rgba_sha256"]=hashlib.sha256(reference_rgba(result,rows)).hexdigest()
    else:ap.error("provide a local PNG or --self-test")
    print(json.dumps(result,indent=2))


if __name__=="__main__":main()
