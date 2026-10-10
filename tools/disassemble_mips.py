"""Disassemble CE MIPS PE files; comments are local linear-flow candidates, not a decompiler."""
from pathlib import Path
import argparse
import hashlib
import json
import re
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent / "python-libs"))
import capstone
import pefile

ROOT = Path(__file__).resolve().parents[1]


def string_at(pe, address):
    rva = address - pe.OPTIONAL_HEADER.ImageBase
    if rva < 0 or rva >= pe.OPTIONAL_HEADER.SizeOfImage:
        return None
    try:
        data = pe.get_data(rva, 200)
        if len(data) > 2 and data[1] == 0:
            text = data[:len(data) // 2 * 2].decode("utf-16le", errors="replace").split("\0")[0]
        else:
            text = data.split(b"\0")[0].decode("ascii", errors="replace")
        if len(text) >= 5 and all(32 <= ord(c) < 127 for c in text):
            return text
    except (pefile.PEFormatError, ValueError):
        pass
    return None


def disassemble(path):
    data = path.read_bytes()
    pe = pefile.PE(data=data)
    if pe.FILE_HEADER.Machine != 0x166:
        raise ValueError("Expected IMAGE_FILE_MACHINE_R4000")
    base = pe.OPTIONAL_HEADER.ImageBase
    imports = {symbol.address: (desc.dll.decode() + "!" +
               (symbol.name.decode() if symbol.name else "ordinal_" + str(symbol.ordinal)))
               for desc in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) for symbol in desc.imports}
    core_path = ROOT / "extracted/705md-rom/fs/Windows/coredll.dll"
    if core_path.exists():
        core = pefile.PE(str(core_path))
        core_names = {s.ordinal: s.name.decode() for s in core.DIRECTORY_ENTRY_EXPORT.symbols if s.name}
        for address, symbol in list(imports.items()):
            if symbol.lower().startswith("coredll.dll!ordinal_"):
                ordinal = int(symbol.rsplit("_", 1)[1])
                if ordinal in core_names:
                    imports[address] = "COREDLL.dll!" + core_names[ordinal] + "@" + str(ordinal)
        core.close()
    catalog_path = ROOT / "analysis/corpus/modules.json"
    if catalog_path.exists() and "remove-md" not in path.parts:
        providers = {}
        for module in json.loads(catalog_path.read_text(encoding="utf-8")):
            if module["origin"] in ("705md", "rom"):
                providers.setdefault(module["name"].lower(), []).append(module)
        for address, symbol in list(imports.items()):
            dll, name = symbol.split("!", 1)
            options = providers.get(dll.lower(), [])
            if name.startswith("ordinal_") and len(options) == 1:
                ordinal = int(name.removeprefix("ordinal_"))
                entry = next((s for s in options[0]["exports"] if s["ordinal"] == ordinal and s["name"]), None)
                if entry:
                    imports[address] = dll+"!"+entry["name"]+"@"+str(ordinal)
    exports = {base+s.address: s.name.decode() for s in
               getattr(getattr(pe, "DIRECTORY_ENTRY_EXPORT", None), "symbols", []) if s.name}
    function_starts = set()
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    if directory.VirtualAddress and directory.Size % 20 == 0:
        pdata = pe.get_data(directory.VirtualAddress, directory.Size)
        for offset in range(0, len(pdata)-19, 20):
            begin, end, _handler, _data, prolog = struct.unpack_from("<5I", pdata, offset)
            if base <= begin < end <= base+pe.OPTIONAL_HEADER.SizeOfImage and begin <= prolog <= end:
                function_starts.add(begin)
    decoder = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)
    decoder.skipdata = True
    thunks = {}
    for section in pe.sections:
        if not section.Characteristics & 0x20000000:
            continue
        decoded = list(decoder.disasm_lite(section.get_data(), base+section.VirtualAddress))
        for first, second, third in zip(decoded, decoded[1:], decoded[2:]):
            if first[2] != "lui" or second[2] != "lw" or third[2] != "jr":
                continue
            hi = first[3].split(", ")
            load = re.fullmatch(r"(\$\w+), (-?(?:0x[0-9a-f]+|\d+))\((\$\w+)\)", second[3])
            if load and hi[0] == load[3] and third[3] == load[1]:
                address = ((int(hi[1], 0) << 16) + int(load[2], 0)) & 0xffffffff
                if address in imports:
                    thunks[first[0]] = imports[address]
    lines, candidates = [], []
    for section in pe.sections:
        if not section.Characteristics & 0x20000000:
            continue
        lines.append("\n; section " + section.Name.rstrip(b"\0").decode())
        constants = {"$zero": 0}
        targets = {}
        pending_clear = False
        pending_call = None
        for addr, size, mnemonic, operands in decoder.disasm_lite(section.get_data(), base+section.VirtualAddress):
            if addr in exports:
                lines.append("\n; export " + exports[addr])
                constants, targets = {"$zero": 0}, {}
            if addr in function_starts:
                lines.append("\n; .pdata function " + hex(addr))
                constants, targets = {"$zero": 0}, {}
            op = [x.strip() for x in operands.split(",")]
            notes = []
            current_call = None
            try:
                if mnemonic in ("jal", "j") and int(op[0], 0) in thunks:
                    notes.append("import thunk " + thunks[int(op[0], 0)])
                    current_call = {"va": hex(addr), "kind": "import_call", "symbol": thunks[int(op[0], 0)]}
                    candidates.append(current_call)
                elif mnemonic == "jal":
                    candidates.append({"va": hex(addr), "kind": "direct_call", "target_va": hex(int(op[0], 0))})
                if mnemonic == "lui":
                    constants[op[0]] = (int(op[1], 0) << 16) & 0xffffffff
                    targets.pop(op[0], None)
                elif mnemonic in ("addiu", "addi", "ori") and op[1] in constants:
                    value = int(op[2], 0)
                    constants[op[0]] = ((constants[op[1]] | value) if mnemonic == "ori" else
                                         (constants[op[1]] + value)) & 0xffffffff
                    targets.pop(op[0], None)
                    text = string_at(pe, constants[op[0]])
                    if text:
                        notes.append("string candidate " + repr(text))
                        candidates.append({"va": hex(addr), "kind": "string", "target_va": hex(constants[op[0]]), "text": text})
                elif mnemonic == "move":
                    previous_constant = constants.get(op[1])
                    previous_target = targets.get(op[1])
                    constants.pop(op[0], None)
                    targets.pop(op[0], None)
                    if previous_constant is not None:
                        constants[op[0]] = previous_constant
                    if previous_target is not None:
                        targets[op[0]] = previous_target
                elif mnemonic == "lw":
                    match = re.fullmatch(r"(-?(?:0x[0-9a-f]+|\d+))\((\$\w+)\)", op[1])
                    previous_constant = constants.get(match[2]) if match else None
                    constants.pop(op[0], None)
                    targets.pop(op[0], None)
                    if match and previous_constant is not None:
                        value = (previous_constant + int(match[1], 0)) & 0xffffffff
                        if value in imports:
                            targets[op[0]] = imports[value]
                            notes.append("IAT " + imports[value])
                            candidates.append({"va": hex(addr), "kind": "iat_load", "iat_va": hex(value), "symbol": imports[value]})
                elif mnemonic == "jalr" and op[-1] in targets:
                    notes.append("call candidate " + targets[op[-1]])
                    current_call = {"va": hex(addr), "kind": "import_call", "symbol": targets[op[-1]]}
                    candidates.append(current_call)
                elif mnemonic == "jalr":
                    candidates.append({"va": hex(addr), "kind": "indirect_call", "register": op[-1]})
                elif mnemonic not in ("nop", "sw", "sh", "sb", "jal", "jalr", "jr", "j", "b") and not mnemonic.startswith("b") and op:
                    constants.pop(op[0], None)
                    targets.pop(op[0], None)
            except (IndexError, ValueError):
                constants, targets = {"$zero": 0}, {}
            lines.append(f"{addr:08x}  {mnemonic:<9} {operands}" + (" ; " + "; ".join(notes) if notes else ""))
            if pending_clear:
                if pending_call is not None:
                    pending_call["constant_arg_candidates"] = {
                        register: constants[register] for register in ("$a0", "$a1", "$a2", "$a3")
                        if register in constants}
                constants, targets = {"$zero": 0}, {}
                pending_clear = False
                pending_call = None
            # Include the MIPS delay slot, then discard speculative linear register state.
            if mnemonic in ("jal", "jalr", "jr", "j", "b") or mnemonic.startswith("b"):
                pending_clear = True
                pending_call = current_call
    return {"path": str(path.relative_to(ROOT)), "sha256": hashlib.sha256(data).hexdigest(),
            "image_base": hex(base), "capstone_version": capstone.__version__,
            "candidate_limit": "local linear state only; inspect raw instructions and control flow before conclusions",
            "candidates": candidates}, "\n".join(lines)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("paths", nargs="+")
    parser.add_argument("--label", default="", help="Separate outputs for identically named files")
    args = parser.parse_args()
    if args.label and (Path(args.label).name != args.label or args.label in (".", "..")):
        parser.error("label must be a directory name")
    out = ROOT / "analysis/disassembly" / args.label
    out.mkdir(parents=True, exist_ok=True)
    for name in args.paths:
        path = Path(name).resolve()
        report, text = disassemble(path)
        (out / (path.name + ".asm")).write_text(text, encoding="utf-8")
        (out / (path.name + "-candidates.json")).write_text(json.dumps(report, indent=2), encoding="utf-8")
        print(path.name, len(report["candidates"]), "local candidates")


if __name__ == "__main__":
    main()
