"""Run resumable candidate decompilation for every module in one inventory origin."""
from pathlib import Path
import sys
import json
import argparse
import run_ghidra

ROOT=Path(__file__).resolve().parents[1]


def main():
    parser=argparse.ArgumentParser();parser.add_argument("origin",choices=["705md","rom","remove-md","corruption-fix"])
    args=parser.parse_args()
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    selected=[m for m in modules if m["origin"]==args.origin]
    # Investigate services before repeating the identical language-loader code.
    selected.sort(key=lambda m:(m["name"].startswith("LangDll"),m["name"].lower()))
    sys.argv=["run_ghidra.py","--origin",args.origin]+[m["name"] for m in selected]
    run_ghidra.main()


if __name__=="__main__":main()
