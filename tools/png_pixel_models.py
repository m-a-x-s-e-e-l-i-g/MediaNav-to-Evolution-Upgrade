"""Bounded arithmetic projections of reviewed ROM PNG converters/scatter helpers.

These functions do not execute firmware instructions. Caller supplies reviewed lookup
table bytes. Reference transparency compares original samples before reduction.
"""
import struct
from parse_png_image import CHANNELS,PASSES

BITS=[1,2,4,8,16,24,32,48,64]


def unpack_pixels(data,count,bits):
    if bits<8:return [(data[i*bits//8]>>(8-bits-i*bits%8))&((1<<bits)-1) for i in range(count)]
    size=bits//8;return [data[i*size:(i+1)*size] for i in range(count)]


def pack_pixels(pixels,bits):
    if bits>=8:return b"".join(pixels)
    raw=bytearray((len(pixels)*bits+7)//8)
    for i,n in enumerate(pixels):raw[i*bits//8]|=n<<(8-bits-i*bits%8)
    return bytes(raw)


def bgra_row(data,width,color,depth,palette=b"",trns=b"",native=False):
    if width<0 or width>1024 or color not in CHANNELS:raise ValueError("unsupported/bounded row")
    channels=CHANNELS[color];bits=channels*depth
    if depth not in ([1,2,4,8] if color==3 else [1,2,4,8,16] if color==0 else [8,16]):raise ValueError("unsupported sample depth")
    if len(data)<(width*bits+7)//8:raise ValueError("short row")
    output=bytearray()
    for i in range(width):
        if depth<8:samples=[(data[i*depth//8]>>(8-depth-i*depth%8))&((1<<depth)-1)]
        elif depth==8:samples=list(data[i*channels:(i+1)*channels])
        else:samples=list(struct.unpack_from(">"+"H"*channels,data,i*channels*2))
        alpha=255
        if color==3:
            index=samples[0]
            if index>=len(palette)//3:
                if not native:raise ValueError("palette index out of range")
                rgb=b"\0\0\0"
            else:
                rgb=palette[index*3:index*3+3];alpha=trns[index] if index<len(trns) else 255
        elif color==0:
            sample=samples[0];gray=sample>>8 if depth==16 else sample*255//((1<<depth)-1);rgb=bytes([gray]*3)
            if trns:
                key=int.from_bytes(trns,"big")
                if native and depth==1:equal=(data[i//8]&(1<<(7-i%8)))==(key&1)
                elif native and depth==16:equal=(sample>>8)==(key>>8)
                else:equal=sample==key
                alpha=0 if equal else 255
        elif color==2:
            rgb=bytes(s>>8 if depth==16 else s for s in samples)
            if trns:
                key=struct.unpack(">3H",trns)
                equal=tuple(s>>8 for s in samples)==tuple(k>>8 for k in key) if native and depth==16 else tuple(samples)==key
                alpha=0 if equal else 255
        elif color==4:
            gray=samples[0]>>8 if depth==16 else samples[0];rgb=bytes([gray]*3)
            alpha=samples[1]>>8 if depth==16 else samples[1]
        else:
            rgb=bytes(s>>8 if depth==16 else s for s in samples[:3]);alpha=samples[3]>>8 if depth==16 else samples[3]
        output.extend(rgb[::-1]+bytes([alpha]))
    return bytes(output)


def extended_row(data,color):
    if color not in [2,6]:raise ValueError("extended path is RGB/RGBA16")
    channels=CHANNELS[color]
    if len(data)%(channels*2):raise ValueError("short extended pixel")
    output=bytearray()
    for at in range(0,len(data),channels*2):
        samples=struct.unpack_from(">"+"H"*channels,data,at)
        scaled=[(n*8192+32767)//65535 for n in samples]
        ordered=scaled[2::-1]+scaled[3:]
        output.extend(struct.pack("<"+"H"*channels,*ordered))
    return bytes(output)


def scatter_native(source,width,bits,pass_number,output,tables):
    if width<1 or width>1024 or bits not in BITS or pass_number not in range(1,7):raise ValueError("bounded scatter only")
    start,_,step,_=PASSES[pass_number-1];count=max(0,(width-start+step-1)//step)
    if not count:return
    needed=(count*bits+7)//8
    if len(source)!=needed:raise ValueError("wrong pass byte count")
    def write(at,value,merge=False):
        if at+len(value)>len(output):raise AssertionError("scatter exceeded row allocation")
        for j,v in enumerate(value):output[at+j]=(output[at+j]|v) if merge else v
    if bits in [1,2]:
        pair=(pass_number-1)//2;entry_size=[4,2,1][pair]
        offset=(0 if bits==1 else 224)+[0,64,128,160,192,208][pass_number-1]
        for i,n in enumerate(source):
            for half,index in enumerate([n>>4,n&15]):
                table_at=offset+index*entry_size;value=tables[table_at:table_at+entry_size]
                write((i*2+half)*entry_size,value,pass_number%2==0)
    elif bits==4:
        dest_step=step//2
        for i,n in enumerate(source):
            if pass_number==6:
                write(i*2,bytes([n>>4]),True);write(i*2+1,bytes([n&15]),True)
            else:
                at=start//2+i*2*dest_step
                write(at,bytes([n&240]));write(at+dest_step,bytes([(n<<4)&255]))
    else:
        size=bits//8
        for i in range(count):write((start+i*step)*size,source[i*size:(i+1)*size])


def selected_passes(row):
    if row%2:raise ValueError("seventh pass supplies odd rows separately")
    return [1,2,4,6] if row&6==0 else [3,4,6] if row&6==4 else [5,6]
