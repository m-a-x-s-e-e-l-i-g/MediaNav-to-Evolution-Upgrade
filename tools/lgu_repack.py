"""Repack an LGU0 upgrade package: XOR layer, ZipCrypto member replacement, header fix-up."""
import struct,zlib,io,json,hashlib
from pathlib import Path
R=Path(__file__).resolve().parents[1]
KEY=bytes.fromhex(json.loads((R/'src/container/lgu0.json').read_bytes())['xor_hex'])
PW=b'I_LOVE_LG^^'
if len(KEY)!=1024:
    raise ValueError('LGU XOR table must have 1024 bytes')

def canonical(name):
    """Match Windows/raw ZIP spellings without altering stored member names."""
    name=name.replace('\\','/')
    if any(p in ('','.','..') or ':' in p for p in name.split('/')):
        raise ValueError(f'Unsafe member name: {name!r}')
    return name

def zip_index(archive):
    result={};seen=set()
    for info in archive.infolist():
        name=canonical(info.filename)
        if name.casefold() in seen:
            raise ValueError(f'Duplicate member: {name}')
        seen.add(name.casefold());result[name]=info
    return result

def read_member(archive,name):
    return archive.read(zip_index(archive)[canonical(name)],pwd=PW)

def version_bytes(version):
    if not version or len(version)>19 or not all(c.isascii() and (c.isalnum() or c in '._-') for c in version):
        raise ValueError('Version must contain 1-19 ASCII letters, digits, dots, underscores or hyphens')
    return version.encode('ascii')
def xor(d):
    # The XOR table is symmetric, so the same call decodes and encodes the payload.
    d=bytearray(d)
    for i,v in enumerate(KEY):d[i::1024]=d[i::1024].translate(bytes(n^v for n in range(256)))
    return d
def crc_table():
    t=[]
    for n in range(256):
        v=n
        for _ in range(8):v=(v>>1)^(0xedb88320 if v&1 else 0)
        t.append(v)
    return t
T=crc_table()
class Cipher:
    # Traditional PKZIP encryption, keyed with the updater's fixed password.
    def __init__(s,pw):
        s.k=[0x12345678,0x23456789,0x34567890]
        for c in pw:s.up(c)
    def up(s,c):
        s.k[0]=((s.k[0]>>8)^T[(s.k[0]^c)&255])&0xffffffff
        s.k[1]=((s.k[1]+(s.k[0]&255))*134775813+1)&0xffffffff
        s.k[2]=((s.k[2]>>8)^T[(s.k[2]^(s.k[1]>>24))&255])&0xffffffff
    def stream(s):
        t=(s.k[2]|2)&0xffff
        return ((t*(t^1))>>8)&255
    def enc(s,data):
        out=bytearray()
        for c in data:
            out.append(c^s.stream());s.up(c)
        return bytes(out)
    def dec(s,data):
        out=bytearray()
        for c in data:
            p=c^s.stream();s.up(p);out.append(p)
        return bytes(out)
def parse(z):
    # EOCD
    e=z.rfind(b'PK\x05\x06')
    if e<0 or len(z)<e+22:
        raise ValueError('Missing ZIP directory')
    disk,cddisk,ondisk,n,cdsize,cdoff,comment=struct.unpack_from('<4HIIH',z,e+4)
    if disk or cddisk or ondisk!=n or n==65535 or cdoff+cdsize!=e or len(z)!=e+22+comment:
        raise ValueError('Unsupported ZIP layout')
    recs=[];p=cdoff
    for _ in range(n):
        assert z[p:p+4]==b'PK\x01\x02'
        nl,xl,cl=struct.unpack_from('<28xHHH',z,p)
        recs.append(dict(cd=p,cdlen=46+nl+xl+cl,name=z[p+46:p+46+nl].decode(),
            off=struct.unpack_from('<I',z,p+42)[0],csize=struct.unpack_from('<I',z,p+20)[0]))
        p+=46+nl+xl+cl
    assert p==cdoff+cdsize
    return recs,cdoff,e
def rebuild(z,replace):
    # Copy every ZIP member untouched, except the ones in `replace`, then rewrite the directory.
    """replace: {name: new_bytes}; returns new zip bytes."""
    recs,cdoff,e=parse(z);out=bytearray();cd=bytearray();pos=0
    normalized={canonical(n):v for n,v in replace.items()}
    names=[canonical(r['name']) for r in recs]
    if len(normalized)!=len(replace) or len({n.casefold() for n in names})!=len(names):
        raise ValueError('Duplicate replacement or archive member')
    missing=normalized.keys()-set(names)
    if missing:
        raise ValueError(f'Replacement members absent: {sorted(missing)}')
    for r in recs:
        if r['off']!=pos:
            raise ValueError('Noncontiguous ZIP members')
        nl,xl=struct.unpack_from('<26xHH',z,r['off'])
        total=30+nl+xl+r['csize'];loc=bytearray(z[r['off']:r['off']+total])
        crec=bytearray(z[r['cd']:r['cd']+r['cdlen']])
        if loc[:4]!=b'PK\x03\x04' or struct.unpack_from('<HH',loc,6)!=(1,8):
            raise ValueError('Expected encrypted DEFLATE member without data descriptor')
        pos+=total
        name=canonical(r['name'])
        if name in normalized:
            data=normalized[name];crc=zlib.crc32(data)&0xffffffff
            co=zlib.compressobj(9,zlib.DEFLATED,-15);comp=co.compress(data)+co.flush()
            hdr=bytearray(hashlib.sha256(r['name'].encode()+data).digest()[:12]);hdr[11]=crc>>24
            c=Cipher(PW);body=c.enc(bytes(hdr)+comp)
            loc=bytearray(loc[:30+nl+xl])+body
            struct.pack_into('<III',loc,14,crc,len(body),len(data))
            struct.pack_into('<III',crec,16,crc,len(body),len(data))
        struct.pack_into('<I',crec,42,len(out))
        out+=loc;cd+=crec
    if pos!=cdoff:
        raise ValueError('Unexpected bytes before ZIP directory')
    cdoff2=len(out);out+=cd
    eocd=bytearray(z[e:]);struct.pack_into('<HHII',eocd,8,len(recs),len(recs),len(cd),cdoff2)
    out+=eocd
    return bytes(out)
def pack(raw_header,zipdata,version=None):
    # Keep the original 1024-byte header; update the version label, total size and payload CRC.
    h=bytearray(raw_header[:1024])
    if version is not None:
        version_bytes(version)
        h[0x2dc:0x304]=(version.encode('utf-16le')+b'\0\0').ljust(0x28,b'\xfe')
    body=bytes(xor(zipdata))
    struct.pack_into('<Q',h,12,1024+len(body))
    struct.pack_into('<I',h,24,zlib.crc32(zipdata)&0xffffffff)
    return bytes(h)+body

def unpack(raw):
    if len(raw)<1024 or raw[:4]!=b'LGU0' or struct.unpack_from('<2I',raw,4)!=(7,1024):
        raise ValueError('Invalid LGU0 header')
    if struct.unpack_from('<Q',raw,12)[0]!=len(raw):
        raise ValueError('LGU size mismatch')
    z=bytes(xor(raw[1024:]))
    if zlib.crc32(z)&0xffffffff!=struct.unpack_from('<I',raw,24)[0]:
        raise ValueError('LGU payload CRC mismatch')
    parse(z)
    return z
def pe_checksum(data,cs_off):
    # Standard PE image checksum, computed with the checksum field zeroed.
    d=bytearray(data);d[cs_off:cs_off+4]=b'\0\0\0\0'
    if len(d)%2:d.append(0)
    s=0
    for i in range(0,len(d),2):
        s+=d[i]|(d[i+1]<<8);s=(s&0xffff)+(s>>16)
    s=(s&0xffff)+(s>>16)
    return (s+len(data))&0xffffffff
