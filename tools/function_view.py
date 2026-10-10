"""Show one .pdata function or a bounded address range in already-generated assembly."""
from pathlib import Path
import argparse
import json
import re

ROOT=Path(__file__).resolve().parents[1]


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("module");parser.add_argument("address",type=lambda v:int(v,0))
    parser.add_argument("--origin",default="705md");parser.add_argument("--bytes",type=lambda v:int(v,0))
    args=parser.parse_args()
    indices=ROOT/"analysis/functions"/args.origin
    index=next((p for p in indices.glob("*.json") if p.stem.lower()==args.module.lower()),None)
    if index is None:parser.error("Module absent from function index")
    module=json.loads(index.read_text(encoding="utf-8"))
    name=index.stem
    containing=[f for f in module["functions"] if int(f["begin_va"],16)<=args.address<int(f["end_va"],16)]
    if args.bytes:lo,hi=args.address,args.address+args.bytes
    elif containing:lo,hi=int(containing[0]["begin_va"],16),int(containing[0]["end_va"],16)
    else:parser.error("Address outside recorded .pdata functions; supply --bytes for leaf code")
    path=ROOT/"analysis/disassembly"/("" if args.origin=="705md" else args.origin)/(name+".asm")
    print(name,hex(lo),hex(hi),"bytes",hi-lo)
    with path.open(encoding="utf-8") as stream:
        for line in stream:
            match=re.match(r"([0-9a-f]{8})  ",line)
            if match and lo<=int(match[1],16)<hi: print(line.rstrip())


if __name__=="__main__":main()
