"""Second decoder for candidate ISA, portable Ghidra with inspected SLEIGH extension."""
from pathlib import Path
import json
import os
import shutil
import subprocess
import hashlib
import argparse

ROOT=Path(__file__).resolve().parents[1]


def main():
    parser=argparse.ArgumentParser();parser.add_argument("--compare-only",action="store_true")
    group=parser.add_mutually_exclusive_group()
    group.add_argument("--flow-expanded",action="store_true",help="Separate project and output for skip-aware traversal")
    group.add_argument("--flow-tables",action="store_true",help="Separate project and output for explicit candidate callback slots")
    group.add_argument("--flow-startup",action="store_true",help="Separate project and output for initial-RAM and timer pointer candidates")
    group.add_argument("--flow-update",action="store_true",help="Separate project and output for AA5/ULC candidate chain")
    group.add_argument("--flash-library",action="store_true",help="Separate decode-only project for the 61-byte RAM template")
    group.add_argument("--flash-marker",action="store_true",help="Separate decode-only project for MCU persistent marker paths")
    group.add_argument("--boot-notifications",action="store_true",help="Separate decode-only project for mutable bootnotification dispatch")
    args=parser.parse_args()
    chain=json.loads((ROOT/"analysis/re-toolchain.json").read_text())
    ghidra=ROOT/chain["ghidra"]["directory"]
    source=ROOT/"sources/ghidra-rl78/RL78"
    target=ghidra/"Ghidra/Processors/RL78"
    if not target.exists():shutil.copytree(source,target)
    for file in source.rglob("*"):
        if file.is_file():
            actual=target/file.relative_to(source)
            if actual.name=="rl78.slaspec" and (ROOT/"analysis/firmware/rl78-local-decoder.json").exists():
                patch=json.loads((ROOT/"analysis/firmware/rl78-local-decoder.json").read_text())
                assert hashlib.sha256(actual.read_bytes()).hexdigest()==patch["local_sha256"]
            else:assert file.read_bytes()==actual.read_bytes()
    env=os.environ.copy();env["JAVA_HOME"]=str(ROOT/chain["jdk"]["directory"])
    env["PATH"]=str(Path(env["JAVA_HOME"])/"bin")+os.pathsep+env["PATH"]
    env["GHIDRA_HEADLESS_MAXMEM"]="2G"
    candidate_dir="flow-expanded" if args.flow_expanded else ("flow-tables" if args.flow_tables else ("flow-startup" if args.flow_startup else ("flow-update" if args.flow_update else None)))
    if args.flash_library:candidate_dir="flash-library"
    if args.flash_marker:candidate_dir="flash-marker"
    if args.boot_notifications:candidate_dir="boot-notifications"
    suffix="micom-"+candidate_dir if candidate_dir else "micom"
    project=ROOT/"analysis/ghidra-projects"/suffix;project.mkdir(parents=True,exist_ok=True)
    out=ROOT/"analysis/firmware"
    if candidate_dir:out=out/candidate_dir
    command=[str(ghidra/"support/analyzeHeadless.bat"),str(project),"MicomCandidate",
             "-import",str(out/"micom-image.bin"),"-overwrite","-loader","BinaryLoader","-loader-baseAddr","0",
             "-processor","RL78:LE:16:default","-cspec","default","-max-cpu","2","-analysisTimeoutPerFile","180",
             "-scriptPath",str(ROOT/"tools/ghidra"),"-preScript","SeedMicom.java",str(out/"micom-cpu-candidates.json"),
             "-postScript","ExportMicom.java",str(out)]
    if args.flash_library or args.flash_marker or args.boot_notifications:command.append("-noanalysis")
    if not args.compare_only:
        (out/"ghidra-rl78-instructions.json").unlink(missing_ok=True)
        with (out/"ghidra-rl78.log").open("w",encoding="utf-8") as log:
            process=subprocess.run(command,env=env,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
        if process.returncode!=0 or not (out/"ghidra-rl78-instructions.json").exists():
            raise SystemExit("Ghidra candidate decoder failed; see analysis/firmware/ghidra-rl78.log")
    gh=json.loads((out/"ghidra-rl78-instructions.json").read_text(encoding="utf-8"))
    py=json.loads((out/"rl78-instructions.json").read_text(encoding="utf-8"))
    # Older exports included Ghidra's explicit ram-space prefix.
    indexed={int(i["address"].removeprefix("0x").split(":")[-1],16):i for i in gh}
    equal=[];different=[];not_seen=[]
    for ins in py:
        other=indexed.get(int(ins["address"],16))
        if other is None:not_seen.append(ins["address"])
        elif other["bytes"]==ins["bytes"]:equal.append(ins["address"])
        else:different.append(dict(address=ins["address"],python_bytes=ins["bytes"],ghidra=other))
    result=dict(scope="Independent candidate instruction lengths; equal bytes do not prove semantics or exact chip",
                exact_cpu_identified=False,sha256=hashlib.sha256((out/"micom-image.bin").read_bytes()).hexdigest(),
                ghidra_instructions=len(gh),python_instructions=len(py),equal_lengths=len(equal),
                different_lengths=different,not_seen_by_ghidra=not_seen)
    (out/"decoder-comparison.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print("Candidate decoder comparison:",len(equal),"equal lengths;",len(different),"different;",len(not_seen),"not seen")


if __name__=="__main__":main()
