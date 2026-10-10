"""Catalog data/assets as well as binaries; recognize headers without executing code."""
from pathlib import Path
from collections import Counter, defaultdict
import hashlib
import json
import struct
import csv

ROOT=Path(__file__).resolve().parents[1]
INPUTS={"705md":ROOT/"extracted/705md","remove-md":ROOT/"extracted/remove-md",
        "corruption-fix":ROOT/"extracted/corruption-fix","rom":ROOT/"extracted/705md-rom/fs/Windows"}


def identify(data):
    result={"format":"unknown","header_hex":data[:24].hex()}
    if data[:2]==b"MZ":result["format"]="PE candidate"
    elif data.startswith(b"BM") and len(data)>=54:
        result.update(format="BMP",width=struct.unpack_from("<i",data,18)[0],height=struct.unpack_from("<i",data,22)[0],
                      bits_per_pixel=struct.unpack_from("<H",data,28)[0],compression=struct.unpack_from("<I",data,30)[0])
    elif data.startswith(bytes([137,80,78,71,13,10,26,10])) and len(data)>=24:
        result.update(format="PNG",width=struct.unpack_from(">I",data,16)[0],height=struct.unpack_from(">I",data,20)[0])
    elif data[:4] in (b"OTTO",b"ttcf",bytes([0,1,0,0])):result["format"]="OpenType/TrueType signature candidate"
    elif data.startswith(b"B000FF\n"):result["format"]="Windows CE BIN record stream"
    elif data.startswith(b"RIFF") and len(data)>=12:result.update(format="RIFF",riff_type=data[8:12].decode("ascii",errors="replace"))
    elif data.startswith(b"PK\x03\x04"):result["format"]="ZIP"
    elif data.startswith(bytes([255,216,255])):result["format"]="JPEG"
    elif not data:result["format"]="empty"
    else:
        odd=data[1:400:2]
        if len(data)%2==0 and (data.startswith(bytes([255,254])) or (len(odd)>10 and sum(b==0 for b in odd)>.9*len(odd))):
            try:
                text=data.decode("utf-16le").lstrip(chr(0xfeff))
                if "\0" not in text and sum(c.isprintable() or c in "\r\n\t" for c in text)>=len(text)*.98:
                    result.update(format="UTF-16LE text",text_prefix=text[:240]);return result
            except UnicodeDecodeError:pass
        try:
            text=data.decode("utf-8-sig")
            if "\0" not in text and sum(c.isprintable() or c in "\r\n\t" for c in text)>=len(text)*.98:
                result.update(format="UTF-8/ASCII text",text_prefix=text[:240])
        except UnicodeDecodeError:pass
    return result


def main():
    records=[];duplicates=defaultdict(list)
    for origin,base in INPUTS.items():
        for path in sorted(base.rglob("*")):
            if not path.is_file():continue
            data=path.read_bytes();sha=hashlib.sha256(data).hexdigest()
            record=dict(origin=origin,path=path.relative_to(ROOT).as_posix(),name=path.name,bytes=len(data),suffix=path.suffix.lower(),
                        sha256=sha,**identify(data))
            records.append(record);duplicates[sha].append(record["path"])
    out=ROOT/"analysis/corpus"
    (out/"data-files.json").write_text(json.dumps(records,ensure_ascii=False,indent=2),encoding="utf-8")
    with (out/"data-files.csv").open("w",encoding="utf-8",newline="") as file:
        writer=csv.DictWriter(file,fieldnames=["origin","path","bytes","suffix","format","sha256"]);writer.writeheader()
        writer.writerows({k:r[k] for k in writer.fieldnames} for r in records)
    summary={"scope":"Header identification is not a decoded proprietary format",
             "files":len(records),"counts_by_origin":dict(Counter(r["origin"] for r in records)),
             "format_counts":dict(Counter(r["format"] for r in records)),"suffix_counts":dict(Counter(r["suffix"] for r in records)),
             "duplicate_sha256_groups":{sha:paths for sha,paths in duplicates.items() if len(paths)>1}}
    (out/"data-summary.json").write_text(json.dumps(summary,indent=2),encoding="utf-8")
    print(json.dumps({k:v for k,v in summary.items() if k!="duplicate_sha256_groups"},ensure_ascii=False,indent=2))


if __name__=="__main__":main()
