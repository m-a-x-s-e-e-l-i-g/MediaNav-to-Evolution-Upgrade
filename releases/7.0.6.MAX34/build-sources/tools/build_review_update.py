"""Build and round-trip a local MediaNav research candidate. Never executes firmware.

Runs the pinned Windows PC LGU tools against a fresh local directory. The
result is an untested research artifact; no device is opened or flashed.
"""
import argparse
import csv
import hashlib
import io
import json
import re
import struct
import subprocess
import time
import zipfile
import zlib
from datetime import datetime,timezone
from pathlib import Path
import pefile
from inspect_bt_playback import BLUE_HASH
from inspect_updater_zip import ZipCipher
from patch_bt_playback import patch_blue

ROOT=Path(__file__).resolve().parents[1]
BLUE_PATH="upgrade/Storage Card/System/Blue.exe"
VERSION_PATH="upgrade/Storage Card/System/Version_Info.txt"
NAV_PATH="upgrade/Storage Card4/NNG/nngnavi.exe"
NAV_HASH="d91544ef3ed2d7f2243e53956fa58cd48afda466aa2e9aeb4b6548fb009040c9"
EXTRACTOR_HASH="89e1731808f3912bcfd40f0ef0dafddf1c04cdb16fc3cb4e7e6be44a0c16f54f"
WRITER_HASH="d8424c16f6832a4f7b1e474e815fee5120cf5041d2d498dbafb030272ec1c9b0"


def sha(raw):return hashlib.sha256(raw).hexdigest()


def relative(name):
    name=name.replace("\\","/");parts=name.split("/")
    if not parts or any(p in ["",".",".."] or ":" in p for p in parts):
        raise ValueError("Unsafe relative member path")
    return name


def xor_key():
    raw=(ROOT/"sources/MediaNavMods/pc/lgutool/lgu2dir/xorArray.h").read_text(encoding="utf-8")
    block=re.search(r"xorArrLGU0\[\]\s*=\s*\{(.*?)\}",raw,re.S).group(1)
    result=bytes(int(x,16) for x in re.findall(r"0x([0-9a-fA-F]+)",block));assert len(result)==1024
    return result


def run_pc_tool(tool,args,log):
    start=time.monotonic()
    with log.open("wb") as output:
        process=subprocess.run([str(tool),*map(str,args)],cwd=ROOT,stdout=output,stderr=subprocess.STDOUT,
            timeout=300,creationflags=getattr(subprocess,"CREATE_NO_WINDOW",0))
    if process.returncode:raise ValueError(f"PC tool failed with exit {process.returncode}; inspect {log}")
    return dict(command=[str(tool),*map(str,args)],sha256=sha(tool.read_bytes()),returncode=process.returncode,
        duration_seconds=round(time.monotonic()-start,3),log=str(log.relative_to(ROOT)))


def crc_table():
    table=[]
    for n in range(256):
        value=n
        for _ in range(8):value=(value>>1)^(0xedb88320 if value&1 else 0)
        table.append(value)
    return table


def verify_package(path,expected,version):
    raw=path.read_bytes();assert raw[:4]==b"LGU0"
    assert struct.unpack_from("<2I",raw,4)==(7,1024)
    assert struct.unpack_from("<Q",raw,12)[0]==len(raw)
    label=raw[0x2a0:0x2dc].decode("utf-16le").split("\0")[0]
    content=raw[0x2dc:0x304].decode("utf-16le").split("\0")[0]
    assert label=="*MEDIA-NAV*" and content==version
    payload=bytearray(raw[1024:]);key=xor_key()
    for i,value in enumerate(key):payload[i::1024]=payload[i::1024].translate(bytes(n^value for n in range(256)))
    assert zlib.crc32(payload)==struct.unpack_from("<I",raw,24)[0]
    records=[];names=set();headers=0;table=crc_table()
    with zipfile.ZipFile(io.BytesIO(payload)) as archive:
        entries=archive.infolist();assert len(entries)==len(expected)
        for i,entry in enumerate(entries):
            assert not entry.is_dir()
            name=relative(entry.filename);assert name in expected and name.casefold() not in names
            names.add(name.casefold());record=expected[name]
            assert entry.file_size==record["bytes"] and entry.compress_type==8 and entry.flag_bits==1
            local=struct.unpack_from("<4s5H3I2H",payload,entry.header_offset)
            sig,_,flags,method,_,_,crc,csize,usize,nlen,xlen=local
            assert sig==b"PK\x03\x04" and flags==1 and method==8
            assert (crc,csize,usize)==(entry.CRC,entry.compress_size,entry.file_size)
            begin=entry.header_offset+30+nlen+xlen;assert csize>=12
            cipher=ZipCipher(b"I_LOVE_LG^^",table)
            assert cipher.decrypt(payload[begin:begin+12])[-1]==entry.CRC>>24;headers+=1
            decoded=archive.read(entry,pwd=b"I_LOVE_LG^^")
            assert len(decoded)==record["bytes"] and sha(decoded)==record["sha256"],name
            records.append(dict(path=name,bytes=len(decoded),sha256=sha(decoded),crc32=hex(entry.CRC),
                compressed_bytes=entry.compress_size,method=8,flags=1))
            if (i+1)%100==0:print(f"Independent ZIP payloads verified: {i+1}/{len(entries)}",flush=True)
    assert names=={k.casefold() for k in expected}
    return dict(lgu_sha256=sha(raw),bytes=len(raw),magic="LGU0",label=label,content=content,
        decoded_zip_crc32=hex(zlib.crc32(payload)),header_crc_valid=True,member_crc_sizes_hashes_valid=True,
        independent_cipher_headers=headers,members=records)


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--output-dir",default="build/review-max01")
    ap.add_argument("--scope",choices=["full","apps"],default="full")
    ap.add_argument("--revision",default="7.0.5.MD.MAX01")
    ap.add_argument("--restart-buffers",type=int,default=3)
    ap.add_argument("--bluetooth-fixes",action="store_true",help="Use verified BT02 bounded playback repair; requires --restart-buffers 2")
    args=ap.parse_args()
    if not re.fullmatch(r"7\.0\.5\.MD\.[A-Z0-9]{1,8}",args.revision) or len(args.revision)>19:
        raise ValueError("Expected a <=19-character 7.0.5.MD research revision")
    if not 2<=args.restart_buffers<=11:raise ValueError("Restart count outside reviewed range 2..11")
    out=(ROOT/args.output_dir).resolve();out.relative_to((ROOT/"build").resolve())
    if out.exists():raise ValueError("Output already exists; originals and prior candidates are never overwritten")
    expected={};original_sources={}
    for origin in ["705md","corruption-fix"]:
        with (ROOT/f"analysis/{origin}-inventory.csv").open(encoding="utf-8",newline="") as stream:rows=list(csv.DictReader(stream))
        for record in rows:
            name=relative(record["path"])
            if args.scope=="apps" and name not in [BLUE_PATH,VERSION_PATH,NAV_PATH]:continue
            if name in expected or name.casefold() in {n.casefold() for n in expected}:raise ValueError("Conflicting source members")
            path=ROOT/"extracted"/origin/name;raw=path.read_bytes()
            assert len(raw)==int(record["size"]) and sha(raw)==record["sha256"]
            expected[name]=dict(bytes=len(raw),sha256=sha(raw),origin=origin,source=str(path.relative_to(ROOT)))
            original_sources[name]=path
    assert len(expected)==(1918 if args.scope=="full" else 3)
    assert expected[BLUE_PATH]["sha256"]==BLUE_HASH and expected[NAV_PATH]["sha256"]==NAV_HASH
    blue=original_sources[BLUE_PATH].read_bytes();pe=pefile.PE(data=blue);base=pe.OPTIONAL_HEADER.ImageBase
    assert pe.FILE_HEADER.Machine==0x166 and pe.OPTIONAL_HEADER.CheckSum==0
    assert pe.OPTIONAL_HEADER.DATA_DIRECTORY[4].Size==0
    if args.bluetooth_fixes:
        if args.restart_buffers!=2:raise ValueError("BT02 uses exactly two 4096-byte startup blocks")
        patched,patch_info=patch_blue(blue)
        proof_path=ROOT/"analysis/firmware/bt-patch/contracts.json"
        proof=json.loads(proof_path.read_text(encoding="utf-8"))
        assert proof["status"]=="passed" and proof["native_execution"] is False
        assert proof["patch"]["output_sha256"]==sha(patched)
        assert proof["producer_sha256"]==sha((ROOT/"tools/verify_bt_patch.py").read_bytes())
        assert proof["patcher_sha256"]==sha((ROOT/"tools/patch_bt_playback.py").read_bytes())
        for name,digest in proof["dependency_sha256"].items():assert sha((ROOT/"tools"/name).read_bytes())==digest
        patch_info.update(verification_evidence=str(proof_path.relative_to(ROOT)),verification_evidence_sha256=sha(proof_path.read_bytes()))
    else:
        va=0x27010;offset=pe.get_offset_from_rva(va-base);before=0x2d2a000b;after=(before&0xffff0000)|args.restart_buffers
        assert blue[offset:offset+4]==struct.pack("<I",before)
        patched=bytearray(blue);patched[offset:offset+4]=struct.pack("<I",after)
        differences=[i for i,(a,b) in enumerate(zip(blue,patched)) if a!=b]
        assert len(differences)==(0 if args.restart_buffers==11 else 1)
        patch_info=dict(module=BLUE_PATH,va=hex(va),file_offset=hex(offset),before_hex=struct.pack("<I",before).hex(),
            after_hex=struct.pack("<I",after).hex(),changed_byte_offsets=[hex(i) for i in differences],
            source_sha256=BLUE_HASH,output_sha256=sha(patched),pe_checksum=0,checksum_preserved=True)
    assert pefile.PE(data=bytes(patched)).OPTIONAL_HEADER.CheckSum==0
    old_version=original_sources[VERSION_PATH].read_bytes();assert old_version==b"7.0.5.MD"
    revised_version=args.revision.encode("ascii");assert args.revision>old_version.decode("ascii")
    overrides={BLUE_PATH:bytes(patched),VERSION_PATH:revised_version}
    writer=ROOT/"tools/vendor/lgu-favremod/dir2lgu.exe";extractor=ROOT/"tools/vendor/lgu-favremod/lgu2dir.exe"
    assert sha(extractor.read_bytes())==EXTRACTOR_HASH
    assert sha(writer.read_bytes())==WRITER_HASH
    for tool in [writer,extractor]:assert pefile.PE(str(tool)).FILE_HEADER.Machine==0x14c
    out.mkdir(parents=True,exist_ok=False);payload=out/"payload";payload.mkdir()
    changes=[]
    for name,record in expected.items():
        raw=overrides.get(name)
        if raw is None:raw=original_sources[name].read_bytes()
        path=payload/name;assert len(str(path))<240
        path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(raw)
        if sha(raw)!=record["sha256"]:
            changes.append(dict(path=name,before_bytes=record["bytes"],before_sha256=record["sha256"],
                after_bytes=len(raw),after_sha256=sha(raw)))
        record.update(bytes=len(raw),sha256=sha(raw))
    candidate=out/"research-candidate.lgu"
    print(f"Staged {len(expected)} checked files; building {args.scope} research candidate",flush=True)
    writer_run=run_pc_tool(writer,["-p","m1",args.revision,payload,candidate],out/"dir2lgu.log")
    verification=verify_package(candidate,expected,args.revision)
    native_extract=out/"roundtrip"
    assert not native_extract.exists()
    print("Independent ZIP checks passed; running separate PC extractor roundtrip",flush=True)
    extractor_run=run_pc_tool(extractor,[candidate,native_extract],out/"lgu2dir.log")
    extracted={relative(p.relative_to(native_extract).as_posix()):p for p in native_extract.rglob("*") if p.is_file()}
    assert set(extracted)==set(expected)
    for name,path in extracted.items():
        raw=path.read_bytes();assert len(raw)==expected[name]["bytes"] and sha(raw)==expected[name]["sha256"]
    # Recheck all original source files to prove that staging did not modify them.
    for name,path in original_sources.items():
        raw=path.read_bytes()
        baseline=next((c["before_sha256"] for c in changes if c["path"]==name),expected[name]["sha256"])
        assert sha(raw)==baseline
    result=dict(generated_utc=datetime.now(timezone.utc).isoformat(),binary_execution=False,
        firmware_binary_execution=False,pc_tool_execution=True,
        candidate_kind="UNTESTED LOCAL RESEARCH BUILD",scope=args.scope,revision=args.revision,
        unit_tested=False,flashed=False,source_firmware="7.0.5.MD",restart_buffers=args.restart_buffers,
        patch=patch_info,
        nav=dict(path=NAV_PATH,sha256=NAV_HASH,bytes=expected[NAV_PATH]["bytes"],copied_unchanged=True),
        changes=changes,writer=writer_run,extractor=extractor_run,verification=verification,
        pc_extractor_matches=len(extracted),original_source_hashes_unchanged=True,
        limitations=["Roundtrip validates packaging and intended bytes, not runtime or device installation",
            "Actual installed module hashes, update free space and restart/recovery remain unverified",
            "BT02 uses two 4096-byte start blocks and a four-block queue; older profile uses the configured large-buffer threshold" if args.bluetooth_fixes else "Configured start threshold is a research candidate; end-to-end latency and jitter/underruns are not measured",
            "End-to-end device latency, underruns, reconnect and native callback/shutdown behavior remain unmeasured",
            "The existing navi-fix is reused; its exact internal patch remains unknown",
            "Full scope includes unchanged original OS/MCU update payloads; apps scope excludes them",
            "Apps scope still reaches the original MICOM load-error/control path; its MCU/restart semantics are unverified",
            "Payload is reproducible from pinned sources; LGU tool timestamps/cipher randomness can change container hash"])
    (out/"build-manifest.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    summary=dict(status="roundtrip-passed",candidate=str(candidate.relative_to(ROOT)),manifest=str((out/"build-manifest.json").relative_to(ROOT)),
        revision=args.revision,scope=args.scope,members=len(expected),changes=len(changes),lgu_sha256=verification["lgu_sha256"],
        unit_tested=False,flashed=False)
    print(json.dumps(summary,indent=2))


if __name__=="__main__":main()
