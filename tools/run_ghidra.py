"""Headless Ghidra per module, isolated projects; no firmware binary execution."""
from pathlib import Path
import argparse
import json
import os
import subprocess
import hashlib
from datetime import datetime, timezone

ROOT=Path(__file__).resolve().parents[1]


def main():
    parser=argparse.ArgumentParser();parser.add_argument("modules",nargs="+");parser.add_argument("--origin",default="705md")
    parser.add_argument("--force",action="store_true")
    args=parser.parse_args()
    toolchain=json.loads((ROOT/"analysis/re-toolchain.json").read_text(encoding="utf-8"))
    catalog=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    providers={}
    for item in catalog:
        if item["origin"] in ("705md","rom"):providers.setdefault(item["name"].lower(),[]).append(item)
    env=os.environ.copy();env["JAVA_HOME"]=str(ROOT/toolchain["jdk"]["directory"])
    env["GHIDRA_HEADLESS_MAXMEM"]="2G"
    env["PATH"]=str(Path(env["JAVA_HOME"])/"bin")+os.pathsep+env["PATH"]
    launcher=ROOT/toolchain["ghidra"]["directory"]/"support/analyzeHeadless.bat"
    code_hash=hashlib.sha256(b"".join(path.read_bytes() for path in
        [Path(__file__), ROOT/"tools/ghidra/SeedMediaNav.java", ROOT/"tools/ghidra/ExportMediaNav.java"])).hexdigest()
    failures=[]
    for name in args.modules:
        item=next(m for m in catalog if m["origin"]==args.origin and m["name"].lower()==name.lower())
        out=ROOT/"analysis/decompiled"/args.origin/item["name"];out.mkdir(parents=True,exist_ok=True)
        seed={"sha256":item["sha256"],"functions":item["functions"],"imports":[]}
        for dependency in item["imports"]:
            options=providers.get(dependency["dll"].lower(),[])
            for symbol in dependency["symbols"]:
                match=next((e for e in options[0]["exports"] if e["ordinal"]==symbol["ordinal"]),None) if len(options)==1 else None
                seed["imports"].append(dict(symbol,dll=dependency["dll"],resolved_name=match["name"] if match else None))
        seed_path=out/"seed.json";seed_path.write_text(json.dumps(seed,indent=2),encoding="utf-8")
        signature=hashlib.sha256((code_hash+json.dumps(seed,sort_keys=True)+json.dumps(toolchain,sort_keys=True)).encode()).hexdigest()
        manifest_path=out/"run.json"
        previous=json.loads(manifest_path.read_text()) if manifest_path.exists() else {}
        if not args.force and previous.get("signature")==signature and previous.get("status")=="exported" and (out/"summary.json").exists() and (out/"decompiled.c").exists():
            print("Cached",args.origin,item["name"],flush=True);continue
        manifest={"signature":signature,"status":"running","started_utc":datetime.now(timezone.utc).isoformat(),"sha256":item["sha256"]}
        manifest_path.write_text(json.dumps(manifest,indent=2))
        # Remove only stale generated summaries, so a failed run cannot look successful.
        (out/"summary.json").unlink(missing_ok=True)
        project=ROOT/"analysis/ghidra-projects"/args.origin/item["name"];project.mkdir(parents=True,exist_ok=True)
        command=[str(launcher),str(project),"MediaNav", "-import",str(ROOT/item["path"]), "-overwrite",
                 "-processor","MIPS:LE:32:default","-cspec","windows","-max-cpu","2", "-analysisTimeoutPerFile","240",
                 "-scriptPath",str(ROOT/"tools/ghidra"),"-preScript","SeedMediaNav.java",str(seed_path),
                 "-postScript","ExportMediaNav.java",str(out)]
        print("Ghidra analyzing",args.origin,item["name"],flush=True)
        with (out/"headless.log").open("w",encoding="utf-8") as log:
            process=subprocess.run(command,env=env,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT)
        manifest.update(exit_code=process.returncode,finished_utc=datetime.now(timezone.utc).isoformat())
        if process.returncode==0 and (out/"summary.json").exists():
            summary=json.loads((out/"summary.json").read_text(encoding="utf-8"));assert summary["executable_sha256"].lower()==item["sha256"]
            print("Exported",item["name"],summary["functions_decompiled"],"/",summary["functions_attempted"],"functions",flush=True)
            manifest["status"]="exported"
        else:
            manifest["status"]="failed";failures.append(item["name"])
            print("Ghidra failed",item["name"],"exit",process.returncode,"inspect",out/"headless.log",flush=True)
        manifest_path.write_text(json.dumps(manifest,indent=2))
    if failures:raise SystemExit("Failed modules: "+", ".join(failures))


if __name__=="__main__":main()
