"""Verify the updater's ZIP cipher/CRC contracts against local LGUs, without extraction.

Firmware code is never loaded or executed. Independent Python models use the
literal table/algorithm from the original MIPS instructions and read-only inputs.
"""
import hashlib
import io
import json
import struct
import zipfile
import zlib
from collections import Counter
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
UPDATER_HASH="4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87"
PACKAGES={"705md":"Upgrade_705MD_FavreMod","corruption-fix":"File_Corruption_Fix",
          "remove-md":"remove_md_super_evo"}


class ZipCipher:
    def __init__(self,password,table):
        self.table=table;self.keys=[0x12345678,0x23456789,0x34567890]
        for byte in password:self.update(byte)

    def update(self,byte):
        a,b,c=self.keys;t=self.table
        a=t[(a^byte)&255]^(a>>8)
        b=((b+(a&255))*0x08088405+1)&0xffffffff
        c=t[(c^(b>>24))&255]^(c>>8)
        self.keys=[a,b,c]

    def decrypt(self,data):
        out=bytearray()
        for byte in data:
            value=(self.keys[2]&65535)|2
            plain=byte^(((value*(value^1))>>8)&255)
            out.append(plain);self.update(plain)
        return bytes(out)


def updater_crc(data,tables,initial=0):
    """Four-table little-endian word step and byte tail from 00026ecc."""
    value=(~initial)&0xffffffff;t0,t1,t2,t3=tables;pos=0
    while pos+4<=len(data):
        value^=int.from_bytes(data[pos:pos+4],"little")
        value=t1[(value>>16)&255]^t2[(value>>8)&255]^t0[value>>24]^t3[value&255]
        pos+=4
    for byte in data[pos:]:value=t0[(value^byte)&255]^(value>>8)
    return (~value)&0xffffffff


def audit_package(origin,folder,key,password,tables):
    path=ROOT/"sources/MediaNav-to-Evolution-Upgrade"/folder/"upgrade.lgu"
    source=path.read_bytes();payload=bytearray(source[1024:])
    if source[:4]!=b"LGU0":raise ValueError("Unexpected LGU kind")
    for i,value in enumerate(key):
        payload[i::1024]=payload[i::1024].translate(bytes(x^value for x in range(256)))
    methods=Counter();flags=Counter();headers=0;samples=[];names=[];counts=Counter()
    with zipfile.ZipFile(io.BytesIO(payload))as archive:
        for entry in archive.infolist():
            offset=entry.header_offset
            h=struct.unpack_from("<4s5H3I2H",payload,offset)
            signature,version,local_flags,method,time,date,crc,csize,usize,nlen,xlen=h
            if signature!=b"PK\x03\x04":raise ValueError("Bad local header")
            names.append(dict(name=entry.filename,method=method,flags=hex(local_flags),
                              compressed_bytes=entry.compress_size,uncompressed_bytes=entry.file_size,
                              local_header_offset=offset,raw_name_hex=bytes(payload[offset+30:offset+30+nlen]).hex()))
            methods[method]+=1;flags[hex(local_flags)]+=1
            begin=offset+30+nlen+xlen
            cipher=None
            if local_flags&1:
                if entry.compress_size<12:raise ValueError("Encrypted member shorter than 12 bytes")
                cipher=ZipCipher(password,tables[0])
                crypt_header=cipher.decrypt(payload[begin:begin+12]);begin+=12
                check=(time>>8)&255 if local_flags&8 else (entry.CRC>>24)&255
                if crypt_header[-1]!=check:raise ValueError("Original updater cipher rejected real member header")
                headers+=1
            if not entry.is_dir()and entry.compress_size<=8192 and entry.file_size<=65536 and counts[method]<8:
                end=offset+30+nlen+xlen+entry.compress_size
                compressed=bytes(payload[begin:end])
                if cipher is not None:compressed=cipher.decrypt(compressed)
                if method==0:decoded=compressed
                elif method==8:decoded=zlib.decompress(compressed,-15)
                else:raise ValueError(f"Unsupported observed compression method {method}")
                if len(decoded)!=entry.file_size or updater_crc(decoded,tables)!=entry.CRC:
                    raise ValueError("Independent decoded sample size/CRC mismatch")
                if decoded!=archive.read(entry,pwd=password):raise ValueError("Independent ZIP read mismatch")
                target=ROOT/"extracted"/origin/entry.filename.replace("\\","/")
                target.resolve().relative_to((ROOT/"extracted"/origin).resolve())
                if decoded!=target.read_bytes():raise ValueError("Independent sample differs from extracted source")
                samples.append(dict(name=entry.filename,bytes=len(decoded),method=method,
                                    sha256=hashlib.sha256(decoded).hexdigest(),crc=hex(entry.CRC)))
                counts[method]+=1
    return dict(lgu_sha256=hashlib.sha256(source).hexdigest(),zip_members=len(names),
                method_counts=dict(methods),flag_counts=dict(flags),verified_cipher_headers=headers,
                independent_small_file_samples=samples,members=names,
                scope="All encryption header check bytes; bounded small-file payload samples, not all payloads")


def main():
    updater=ROOT/"extracted/705md/upgrade/Storage Card/System/UpgradeManager.exe"
    if hashlib.sha256(updater.read_bytes()).hexdigest()!=UPDATER_HASH:raise ValueError("Updater source changed")
    pe=pefile.PE(str(updater));base=pe.OPTIONAL_HEADER.ImageBase
    tables=[struct.unpack("<256I",pe.get_data(va-base,1024))for va in (0x2c198,0x2c598,0x2c998,0x2cd98)]
    for size in range(100):
        data=bytes((i*37+size)&255 for i in range(size))
        for seed in (0,0x98765432):
            if updater_crc(data,tables,seed)!=zlib.crc32(data,seed):raise ValueError("CRC instruction model differs")
    password=pe.get_data(0x346bc-base,12).split(b"\0")[0]
    if password!=b"I_LOVE_LG^^":raise ValueError("Recorded firmware password changed")
    key=pe.get_data(0x373dc-base,1024)
    packages={origin:audit_package(origin,folder,key,password,tables)for origin,folder in PACKAGES.items()}
    evidence=[]
    for va,size,role in [(0x1ff3c,0x12c,"ZIP vtable and CRC-table constructor"),
                         (0x34aac,0x54,"ZIP archive vtable"),(0x349a8,0x2c,"Async output-stream vtable"),
                         (0x21de0,0x168,"Stored/deflate dispatcher"),(0x25ac0,0x314,"Stored copy/CRC"),
                         (0x25dd4,0x430,"Decrypt/raw-inflate/CRC"),(0x26894,0x124,"12-byte encryption header"),
                         (0x269b8,0xb8,"Cipher byte loop"),(0x26a70,0xfc,"Cipher password seeds"),
                         (0x26b6c,0x2e4,"Cipher header/checkbyte"),(0x26ecc,0x498,"Four-table CRC32"),
                         (0x27364,0x138,"Raw inflate init/reset"),(0x1fc10,0x224,"Member name validation/conversion"),
                         (0x247a0,0x148,"Bounded root/name join"),(0x1e854,0x1a8,"Async write and exact byte-count check"),
                         (0x266c4,0x1d0,"Output close/size verification"),(0x12d80,0x20c,"Startup staging before Micom launch"),
                         (0x15dbc,0x18c,"Synctool handle close before monitor-thread creation"),
                         (0x12b50,0xa4,"Synctool wait thread"),(0x2c198,0x1000,"CRC32 tables")]:
        raw=pe.get_data(va-base,size)
        if len(raw)!=size:raise ValueError("Truncated evidence")
        evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    result=dict(updater_sha256=UPDATER_HASH,binary_execution=False,crc_model_crosschecks=200,
                packages=packages,evidence=evidence)
    (ROOT/"analysis/firmware/updater-zip-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps({origin:{k:v[k]for k in ("zip_members","method_counts","flag_counts","verified_cipher_headers")}
                      |{"small_file_samples":len(v["independent_small_file_samples"])}for origin,v in packages.items()},indent=2))


if __name__=="__main__":main()
