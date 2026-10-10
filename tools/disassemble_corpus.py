"""Resume corpus disassembly per source; PC-side static parsing only."""
from pathlib import Path
import argparse
import hashlib
import json
from disassemble_mips import disassemble, ROOT


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("origins", nargs="+", choices=["705md","rom","remove-md","corruption-fix"])
    args=parser.parse_args()
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    script_hash=hashlib.sha256((ROOT/"tools/disassemble_mips.py").read_bytes()).hexdigest()
    results=[]
    for module in modules:
        if module["origin"] not in args.origins: continue
        out=ROOT/"analysis/disassembly"/("" if module["origin"]=="705md" else module["origin"])
        out.mkdir(parents=True,exist_ok=True)
        report_path=out/(module["name"]+"-candidates.json")
        asm_path=out/(module["name"]+".asm")
        if report_path.exists() and asm_path.exists():
            previous=json.loads(report_path.read_text(encoding="utf-8"))
            if previous.get("sha256")==module["sha256"] and previous.get("tool_sha256")==script_hash:
                results.append({"id":module["id"],"cached":True}); continue
        try:
            report,assembly=disassemble(ROOT/module["path"])
            report["tool_sha256"]=script_hash
            report_path.write_text(json.dumps(report,indent=2),encoding="utf-8")
            asm_path.write_text(assembly,encoding="utf-8")
            results.append({"id":module["id"],"candidates":len(report["candidates"]),"asm_bytes":asm_path.stat().st_size})
            print(module["origin"],module["name"],len(report["candidates"]),"candidates",flush=True)
        except Exception as error:
            results.append({"id":module["id"],"error":str(error)})
            print("ERROR",module["name"],str(error),flush=True)
    destination=ROOT/"analysis/corpus"/("disassembly-"+"-".join(args.origins)+".json")
    destination.write_text(json.dumps(results,indent=2),encoding="utf-8")
    print("Finished",len(results),"files; errors",sum("error" in r for r in results),flush=True)


if __name__=="__main__": main()
