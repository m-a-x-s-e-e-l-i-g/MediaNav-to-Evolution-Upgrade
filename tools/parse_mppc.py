"""Bounded offline MPPC decoder; firmware code, devices and sockets are never opened."""
import argparse
import json
from pathlib import Path


class FormatError(ValueError): pass


class Bits:
    def __init__(self,data): self.data=data; self.position=0
    @property
    def remaining(self): return len(self.data)*8-self.position
    def read(self,n):
        if self.remaining<n: raise FormatError("Truncated bit token")
        value = 0
        for _ in range(n):
            value = value*2+((self.data[self.position//8]>>(7-self.position%8))&1)
            self.position += 1
        return value


def read_length(bits,vendor=True):
    ones = 0
    while bits.read(1):
        ones += 1
        if ones>(9 if vendor else 11): raise FormatError("Match length exceeds decoder prefix range")
    if ones==0: return 3
    width = ones+1
    return (1<<width)+bits.read(width)


def decode_tokens(data,vendor=True):
    bits = Bits(data); tokens=[]
    while bits.remaining>=8:
        if bits.read(1)==0:
            tokens.append(dict(literal=bits.read(7))); continue
        if bits.read(1)==0:
            tokens.append(dict(literal=128+bits.read(7))); continue
        if bits.read(1)==0: offset=320+bits.read(13)
        elif bits.read(1)==0: offset=64+bits.read(8)
        else: offset=bits.read(6)
        if not 1<=offset<=8191: raise FormatError("Invalid copy offset")
        tokens.append(dict(offset=offset,length=read_length(bits,vendor)))
    if bits.remaining and bits.read(bits.remaining)!=0: raise FormatError("Nonzero trailing padding")
    return tokens


class Decoder:
    def __init__(self): self.history=bytearray(8192); self.position=0
    def reset(self): self.history[:]=b"\0"*8192; self.position=0
    def decode(self,data,at_front=False,flushed=False,vendor=True):
        if flushed: self.reset()
        elif at_front: self.position=0
        start=self.position; tokens=decode_tokens(data,vendor)
        for token in tokens:
            if "literal" in token:
                if self.position>=8192: raise FormatError("Literal exceeds history capacity")
                self.history[self.position]=token["literal"]; self.position+=1
            else:
                length=token["length"]; end=self.position+length
                if end>8192 or (vendor and end==8192): raise FormatError("Copy reaches decoder history boundary")
                source=(self.position-token["offset"])&8191
                if source+length>8192: raise FormatError("Copy source crosses linear history boundary")
                for i in range(length):
                    self.history[self.position]=self.history[source+i]; self.position+=1
        return bytes(self.history[start:self.position]),tokens


def pack_bits(text):
    text += "0"*((-len(text))%8)
    return bytes(int(text[i:i+8],2) for i in range(0,len(text),8))


def literal_bits(byte): return format(byte,"08b") if byte<128 else "10"+format(byte&127,"07b")


def tuple_bits(offset,length):
    if not 1<=offset<=8191 or not 3<=length<=8191: raise FormatError("Invalid synthetic tuple")
    prefix = ("1111"+format(offset,"06b")) if offset<64 else (
        "1110"+format(offset-64,"08b") if offset<320 else "110"+format(offset-320,"013b"))
    if length==3: return prefix+"0"
    width=length.bit_length()-1
    return prefix+"1"*(width-1)+"0"+format(length-(1<<width),f"0{width}b")


def self_test():
    counts=dict(literals=0,offsets=0,lengths=0,negative_cases=0)
    for byte in range(256):
        wire=pack_bits(literal_bits(byte)); output,tokens=Decoder().decode(wire)
        assert output==bytes([byte]) and tokens==[dict(literal=byte)]
        counts["literals"]+=1
    for offset in range(1,8192):
        assert decode_tokens(pack_bits(tuple_bits(offset,3)))==[dict(offset=offset,length=3)]
        counts["offsets"]+=1
    for length in range(3,8192):
        wire=pack_bits(tuple_bits(1,length))
        assert decode_tokens(wire,vendor=False)==[dict(offset=1,length=length)]
        if length<2048: assert decode_tokens(wire)==[dict(offset=1,length=length)]
        else:
            try: decode_tokens(wire)
            except FormatError: pass
            else: raise AssertionError("Vendor length should reject this prefix")
        counts["lengths"]+=1
    # Public RFC2118 token example; no native compressor runs here.
    prefix=b"for whom the bell tolls,"
    text="".join(literal_bits(b) for b in prefix)+tuple_bits(16,15)+literal_bits(32)+tuple_bits(40,4)+tuple_bits(19,3)+literal_bits(101)+literal_bits(46)
    output,tokens=Decoder().decode(pack_bits(text))
    assert output==b"for whom the bell tolls, the bell tolls for thee."
    for bad in (b"\x80",b"\xff",pack_bits("1111"+"000000"+"0")):
        try: decode_tokens(bad)
        except FormatError: counts["negative_cases"]+=1
        else: raise AssertionError("Malformed token accepted")
    d=Decoder(); d.position=8191
    try: d.decode(pack_bits(literal_bits(65)+literal_bits(66)))
    except FormatError: counts["negative_cases"]+=1
    else: raise AssertionError("Unsafe literal output accepted")
    return dict(status="passed",**counts,rfc_example_payload=pack_bits(text).hex(),rfc_example_output=output.hex())


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("path",nargs="?",type=Path,help="Local compressed payload file")
    p.add_argument("--hex",help="Compressed payload bytes, without PPP/CCP headers")
    p.add_argument("--standard",action="store_true",help="Permit standard lengths through8191, unlike the observed vendor decoder")
    p.add_argument("--self-test",action="store_true")
    args=p.parse_args()
    if args.self_test: print(json.dumps(self_test(),indent=2)); return
    if bool(args.path)==bool(args.hex): p.error("Provide one local path or --hex")
    try:
        data=args.path.read_bytes() if args.path else bytes.fromhex(args.hex)
        if len(data)>65536: raise FormatError("Offline input limit65536")
        output,tokens=Decoder().decode(data,vendor=not args.standard,flushed=True)
        print(json.dumps(dict(input_bytes=len(data),output_bytes=len(output),output_hex=output.hex(),tokens=tokens),indent=2))
    except (FormatError,ValueError,OSError) as e: p.error(str(e))


if __name__=="__main__": main()
