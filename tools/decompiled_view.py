"""Stream one exported pseudocode function without loading the full corpus into memory."""
import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def main():
    sys.stdout.reconfigure(encoding="utf-8")
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("module")
    parser.add_argument("address", type=lambda value: int(value, 0))
    parser.add_argument("--origin", default="705md")
    parser.add_argument("--max-lines", type=int, default=180)
    args = parser.parse_args()
    path = ROOT / "analysis/decompiled" / args.origin / args.module / "decompiled.c"
    active = False
    count = 0
    with path.open(encoding="utf-8") as stream:
        for line in stream:
            marker = re.fullmatch(r"/\* ([0-9a-f]{8}) [^\n]* \*/\s*", line)
            if marker:
                if active: break
                active = int(marker[1], 16) == args.address
            if active:
                print(line.rstrip())
                count += 1
                if count >= args.max_lines:
                    print("/* Truncated display; original export contains the remainder. */")
                    break
    if not active: parser.error("Function address absent from export")


if __name__ == "__main__": main()
