"""Preserve source ranges supporting partial DAB station/list layouts."""
import hashlib
import json
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    evidence=[]
    sources={}
    for name,ranges in [
        ("MgrDAB.exe",[(0x1925c,0x197c8),(0x268bc,0x26a7c),(0x2784c,0x27968),
                       (0x27d58,0x28200),(0x285b4,0x287c0),(0x28f8c,0x29138)]),
        ("AppMain.exe",[(0x96184,0x966cc),(0x971ac,0x97250),(0x99678,0x99708)])]:
        m=next(x for x in modules if x["origin"]=="705md" and x["name"]==name)
        path=ROOT/m["path"]
        digest=hashlib.sha256(path.read_bytes()).hexdigest()
        if digest != m["sha256"]:
            raise ValueError("Source differs from inventory")
        sources[name]=digest
        pe=pefile.PE(str(path))
        for start,end in ranges:
            raw=pe.get_data(start-pe.OPTIONAL_HEADER.ImageBase,end-start)
            if len(raw)!=end-start:
                raise ValueError("Incomplete evidence range")
            evidence.append(dict(module=name,start_va=hex(start),end_va_exclusive=hex(end),
                                 raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    result=dict(source_hashes=sources,evidence=evidence,
                layouts=dict(station=dict(bytes=0x66c),presets=dict(bytes=0x4d14,capacity=12,stride=0x66c,selected_index_offset=0x4d10),
                             scan=dict(bytes=0x714c,capacity=250,stride=0x74,count_offset=0x7148),
                             epg=dict(bytes=0x19cc,capacity=100,stride=0x42,count_offset=0x19c8)),
                unverified="Partial field semantics; no runtime capture from physical unit")
    (ROOT/"analysis/firmware/dab-shared-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(result["layouts"],indent=2))


if __name__=="__main__":main()
