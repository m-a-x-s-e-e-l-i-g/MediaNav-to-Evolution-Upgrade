"""Minimal documented fixes to the portable extension, preserving upstream sources.

SFR address bytes, byte displacements, word alignment and CMPW opcodes are patched.
Call/return p-code and other operands remain unsuitable for trusted decompilation.
"""
from pathlib import Path
import json
import hashlib
import difflib

ROOT=Path(__file__).resolve().parents[1]


def main():
    chain=json.loads((ROOT/"analysis/re-toolchain.json").read_text())
    source=ROOT/"sources/ghidra-rl78/RL78/data/languages/rl78.slaspec"
    target=ROOT/chain["ghidra"]["directory"]/"Ghidra/Processors/RL78/data/languages/rl78.slaspec"
    old=source.read_text(encoding="utf-8");new=old
    replacements={
        "sfr: val is jimm8 [val = 0xfff00 + jimm8;]":"sfr: val is data8 [val = 0xfff00 + data8;]",
        "sfrp: val is jimm8 & data0_1=0 [val = 0xfff00 + jimm8;]":"sfrp: val is data8 & data0_1=0 [val = 0xfff00 + data8;]",
        "is op=0x5E & addr8_hl_rel & A":"is op=0x5E & A; addr8_hl_rel",
        "is op=0x7E & addr8_hl_rel & A":"is op=0x7E & A; addr8_hl_rel",
        "\tdata0_1 = (0, 1)":"\tdata0_1 = (0, 1)\n\tdata_lsb = (0, 0)",
        ":cmpw AX, BC is op=0x45 & AX & BC":":cmpw AX, BC is op=0x43 & AX & BC",
        ":cmpw AX, DE is op=0x46 & AX & DE":":cmpw AX, DE is op=0x45 & AX & DE",
    }
    for opcode in ("0E","1E","2E","3E","4E","6E"):
        replacements[f"is op=0x{opcode} & addr8_hl_rel & A"]=f"is op=0x{opcode} & A; addr8_hl_rel"
    for before,after in replacements.items():
        assert new.count(before)==1,before
        new=new.replace(before,after)
    # Word operands and CALLT entries require even addresses, not multiples of four.
    new=new.replace("data0_1=0","data_lsb=0")
    target.write_text(new,encoding="utf-8")
    out=ROOT/"analysis/firmware"
    diff="".join(difflib.unified_diff(old.splitlines(True),new.splitlines(True),fromfile="upstream/rl78.slaspec",tofile="local/rl78.slaspec"))
    (out/"rl78-local-decoder.patch").write_text(diff,encoding="utf-8")
    report=dict(upstream_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),local_sha256=hashlib.sha256(target.read_bytes()).hexdigest(),
                patch="analysis/firmware/rl78-local-decoder.patch",scope="Instruction-only repairs, not a corrected CPU emulator or decompiler",
                specification="https://www.renesas.com/en/document/mas/78k0r-microcontrollers-users-manual-instructions",
                pages=[27,63,64,65,66],remaining_issues=["CALL modeled as GOTO, terminating fall-through", "Incorrect stack/address p-code",
                                                "Short direct addressing and register operands need separate verification"])
    (out/"rl78-local-decoder.json").write_text(json.dumps(report,indent=2))
    print("Applied verified instruction-only source repairs; original checkout unchanged")


if __name__=="__main__":main()
