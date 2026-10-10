"""Retry a failed pseudocode function from a saved isolated project, read-only."""
import argparse
import json
import os
import subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("module");parser.add_argument("address",type=lambda value:int(value,0))
    parser.add_argument("--origin",default="705md");args=parser.parse_args()
    chain=json.loads((ROOT/"analysis/re-toolchain.json").read_text(encoding="utf-8"))
    directory=ROOT/"analysis/decompiled"/args.origin/args.module
    original=json.loads((directory/"summary.json").read_text(encoding="utf-8"))
    if not any(int(f["address"],16)==args.address for f in original["functions"]): raise ValueError("Address absent from module export")
    out=directory/"recovered-functions";out.mkdir(exist_ok=True)
    result_file=out/f"{args.address:08x}.json"
    result_file.unlink(missing_ok=True)
    env=os.environ.copy();env["JAVA_HOME"]=str(ROOT/chain["jdk"]["directory"])
    env["PATH"]=str(Path(env["JAVA_HOME"])/"bin")+os.pathsep+env["PATH"];env["GHIDRA_HEADLESS_MAXMEM"]="2G"
    launcher=ROOT/chain["ghidra"]["directory"]/"support/analyzeHeadless.bat"
    project=ROOT/"analysis/ghidra-projects"/args.origin/args.module
    command=[str(launcher),str(project),"MediaNav","-process",args.module,"-readOnly","-noanalysis",
             "-max-cpu","1","-scriptPath",str(ROOT/"tools/ghidra"),"-postScript","ExportOneMediaNav.java",str(out),f"{args.address:08x}"]
    with (out/f"{args.address:08x}.log").open("w",encoding="utf-8") as log:
        run=subprocess.run(command,env=env,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
    if run.returncode or not result_file.exists(): raise RuntimeError("Retry failed; inspect recovery log")
    result=json.loads(result_file.read_text(encoding="utf-8"))
    if result["executable_sha256"].lower()!=original["executable_sha256"].lower(): raise ValueError("Wrong project binary")
    print(json.dumps(result,indent=2))
    if not result["decompiled"]: raise SystemExit(1)


if __name__=="__main__":main()
