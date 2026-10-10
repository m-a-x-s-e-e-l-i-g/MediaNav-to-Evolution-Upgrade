"""Finish a timed-out analyzer on its existing isolated project, then re-export."""
from pathlib import Path
import argparse,json,os,subprocess
from datetime import datetime,timezone

ROOT=Path(__file__).resolve().parents[1]

def main():
    parser=argparse.ArgumentParser();parser.add_argument("module");parser.add_argument("--origin",default="705md")
    parser.add_argument("--timeout",type=int,default=900);args=parser.parse_args()
    chain=json.loads((ROOT/"analysis/re-toolchain.json").read_text())
    out=ROOT/"analysis/decompiled"/args.origin/args.module
    project=ROOT/"analysis/ghidra-projects"/args.origin/args.module
    original=json.loads((out/"run.json").read_text());assert original["status"]=="exported"
    previous=json.loads((out/"summary.json").read_text(encoding="utf-8"))
    (out/"initial-summary.json").write_text(json.dumps(previous,indent=2),encoding="utf-8")
    original.update(status="resuming_analysis",resume_started_utc=datetime.now(timezone.utc).isoformat())
    (out/"run.json").write_text(json.dumps(original,indent=2))
    env=os.environ.copy();env["JAVA_HOME"]=str(ROOT/chain["jdk"]["directory"])
    env["PATH"]=str(Path(env["JAVA_HOME"])/"bin")+os.pathsep+env["PATH"];env["GHIDRA_HEADLESS_MAXMEM"]="2G"
    launcher=ROOT/chain["ghidra"]["directory"]/"support/analyzeHeadless.bat"
    command=[str(launcher),str(project),"MediaNav","-process",args.module,"-max-cpu","2",
             "-analysisTimeoutPerFile",str(args.timeout),"-scriptPath",str(ROOT/"tools/ghidra"),
             "-postScript","ExportMediaNav.java",str(out)]
    print("Resuming",args.origin,args.module,flush=True);(out/"summary.json").unlink(missing_ok=True)
    with (out/"resume.log").open("w",encoding="utf-8") as log:
        result=subprocess.run(command,env=env,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
    log_text=(out/"resume.log").read_text(encoding="utf-8")
    if result.returncode!=0 or not (out/"summary.json").exists():original["status"]="resume_failed"
    else:
        summary=json.loads((out/"summary.json").read_text(encoding="utf-8"));assert summary["executable_sha256"].lower()==original["sha256"]
        original.update(status="exported",resume_analysis_timed_out="Analysis timed out" in log_text,
                        resume_finished_utc=datetime.now(timezone.utc).isoformat(),resume_timeout_seconds=args.timeout)
        print("Re-exported",summary["functions_decompiled"],"functions; analyzer timeout:",original["resume_analysis_timed_out"],flush=True)
    (out/"run.json").write_text(json.dumps(original,indent=2))
    if original["status"]!="exported":raise SystemExit("Resume failed; inspect resume.log")

if __name__=="__main__":main()
