"""Inventory the full available PE corpus; inventory coverage is not behavioral understanding."""
from pathlib import Path
import bisect
import collections
import csv
import hashlib
import json
import re
import struct

import pefile
from analyze_firmware import pe_info, strings

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "analysis/corpus"
INPUTS = {"705md": ROOT / "extracted/705md", "rom": ROOT / "extracted/705md-rom/fs/Windows",
          "remove-md": ROOT / "extracted/remove-md", "corruption-fix": ROOT / "extracted/corruption-fix"}


def functions(pe):
    """Microsoft PE 32-bit MIPS .pdata: five DWORD VAs, not RVAs."""
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    result, errors = [], []
    if not directory.VirtualAddress or not directory.Size:
        return result, errors
    data = pe.get_data(directory.VirtualAddress, directory.Size)
    if len(data) != directory.Size or len(data) % 20:
        return [], ["Exception directory is not a complete 20-byte-entry table"]
    executable = [(pe.OPTIONAL_HEADER.ImageBase+s.VirtualAddress,
                   pe.OPTIONAL_HEADER.ImageBase+s.VirtualAddress+max(s.Misc_VirtualSize, s.SizeOfRawData))
                  for s in pe.sections if s.Characteristics & 0x20000000]
    last = -1
    for index in range(0, len(data), 20):
        begin, end, handler, handler_data, prolog = struct.unpack_from("<5I", data, index)
        if not any(lo <= begin < end <= hi for lo,hi in executable) or not begin <= prolog <= end or begin < last:
            errors.append({"index": index//20, "raw": [hex(v) for v in (begin,end,handler,handler_data,prolog)]})
            continue
        result.append({"begin_va": hex(begin), "end_va": hex(end), "bytes": end-begin,
                       "handler_va": hex(handler), "handler_data_va": hex(handler_data), "prolog_end_va": hex(prolog)})
        last = begin
    return result, errors


def resources(pe):
    leaves, texts = [], []
    root = getattr(pe, "DIRECTORY_ENTRY_RESOURCE", None)
    if not root:
        return leaves, texts
    def walk(node, path):
        for entry in node.entries:
            component = str(entry.name) if entry.name else entry.id
            current = path+[component]
            if hasattr(entry, "directory"):
                walk(entry.directory, current)
            elif hasattr(entry, "data"):
                item = entry.data.struct
                leaves.append({"key": current, "rva": hex(item.OffsetToData), "bytes": item.Size})
                if current[0] == 6 and isinstance(current[1], int):
                    data, pos = pe.get_data(item.OffsetToData, item.Size), 0
                    for i in range(16):
                        if pos+2 > len(data): break
                        count = struct.unpack_from("<H", data, pos)[0]; pos += 2
                        if pos+count*2 > len(data): break
                        text = data[pos:pos+count*2].decode("utf-16le", errors="replace"); pos += count*2
                        if text: texts.append({"id": (current[1]-1)*16+i, "language": current[-1], "text": text})
    walk(root, [])
    return leaves, texts


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    modules, rows = [], []
    meaningful = re.compile(r"(?:[A-Z]:\\|\\Storage Card|(?:Shm|Mutex|COM\d:|MGR\d:)|LGE\\|Software\\|Drivers\\|\.exe\b|\.dll\b|::|IOCTL_|IDM_|A2DP|AVRCP|GPS|MICOM|Bluetooth)", re.I)
    for label, directory in INPUTS.items():
        for path in sorted(directory.rglob("*")):
            if not path.is_file(): continue
            data = path.read_bytes()
            if data[:2] != b"MZ": continue
            name = path.relative_to(directory).as_posix()
            item = {"id": label+"/"+name, "origin": label, "path": str(path.relative_to(ROOT)),
                    "name": path.name, "bytes": len(data), "sha256": hashlib.sha256(data).hexdigest(),
                    "understanding": "inventory only; behavior not fully reconstructed"}
            try:
                item.update(pe_info(data))
                pe = pefile.PE(data=data)
                item["functions"], item["function_table_anomalies"] = functions(pe)
                item["resources"], item["resource_strings"] = resources(pe)
                item["version_strings"] = [{k.decode(errors="replace"):v.decode(errors="replace") for k,v in table.entries.items()}
                                           for group in getattr(pe,"FileInfo",[]) for info in group
                                           for table in getattr(info,"StringTable",[])]
                data_strings = []
                for section in pe.sections:
                    if section.Characteristics & 0x20000000: continue
                    if section.Name.startswith(b".cerom"): continue
                    for offset, encoding, text in strings(section.get_data()):
                        data_strings.append({"file_offset": hex(section.PointerToRawData+offset),
                                             "va": hex(pe.OPTIONAL_HEADER.ImageBase+section.VirtualAddress+offset),
                                             "encoding": encoding, "text": text})
                item["semantic_string_candidates"] = [s for s in data_strings if meaningful.search(s["text"])]
                strings_dir = OUT / "strings" / label
                strings_dir.mkdir(parents=True, exist_ok=True)
                (strings_dir/(path.name+".json")).write_text(json.dumps(data_strings, ensure_ascii=False, indent=2), encoding="utf-8")
                pe.close()
            except (pefile.PEFormatError, ValueError, struct.error) as error:
                item["analysis_error"] = str(error)
            modules.append(item)
            rows.append({"origin": label, "name": path.name, "bytes": len(data),
                         "imports": len(item.get("imports",[])), "exports": len(item.get("exports",[])),
                         "pdata_functions": len(item.get("functions",[])),
                         "pdata_anomalies": len(item.get("function_table_anomalies",[])),
                         "resource_strings": len(item.get("resource_strings",[])), "sha256": item["sha256"]})
        print(label, sum(m["origin"]==label for m in modules), "PE modules", flush=True)

    # Resolve only against the available 7.0.5.MD payload + its ROM, not the older comparison.
    available = collections.defaultdict(list)
    for item in modules:
        if item["origin"] in ("705md","rom"):
            available[item["name"].lower()].append(item)
    edges, missing, ordinal_misses = [], collections.Counter(), []
    for item in modules:
        for dependency in item.get("imports",[]):
            targets = available[dependency["dll"].lower()]
            edges.append({"source": item["id"], "import_dll": dependency["dll"], "targets": [t["id"] for t in targets],
                          "symbol_count": len(dependency["symbols"]), "scope": "candidate provider set; static imports only"})
            if item["origin"] not in ("705md","rom","corruption-fix"): continue
            if not targets:
                missing[dependency["dll"]] += 1; continue
            if len(targets) == 1:
                exported = {s["ordinal"] for s in targets[0].get("exports",[])}
                for symbol in dependency["symbols"]:
                    if symbol["ordinal"] is not None and symbol["ordinal"] not in exported:
                        ordinal_misses.append({"source": item["id"], "dll": dependency["dll"], "ordinal": symbol["ordinal"]})
    summary = {"counts": dict(collections.Counter(m["origin"] for m in modules)), "total_pes": len(modules),
               "unique_hashes": len({m["sha256"] for m in modules}),
               "pdata_functions": sum(len(m.get("functions",[])) for m in modules),
               "analysis_errors": [{"id":m["id"],"error":m["analysis_error"]} for m in modules if "analysis_error" in m],
               "missing_import_providers": dict(missing), "missing_ordinal_candidates": ordinal_misses,
               "scope": "Full inventory of recognized MZ/PE files in available packages and reconstructed ROM, not every executable on the unit"}
    (OUT/"modules.json").write_text(json.dumps(modules, ensure_ascii=False, indent=2), encoding="utf-8")
    (OUT/"dependencies.json").write_text(json.dumps(edges, indent=2), encoding="utf-8")
    (OUT/"summary.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")
    with (OUT/"modules.csv").open("w",newline="",encoding="utf-8") as f:
        writer=csv.DictWriter(f,fieldnames=list(rows[0]));writer.writeheader();writer.writerows(rows)
    lines=["# Beschikbare MediaNav-binaries — volledige inventaris", "",
           "Inventarisdekking betekent geen volledige gedragsanalyse. Elke component blijft open totdat codepaden en runtimegedrag zijn onderzocht.", "",
           "| Herkomst | Module | Bytes | Imports (DLLs) | Exports | .pdata-functies | Tabelafwijkingen | Tekstresources |",
           "| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |"]
    lines += [f"| {r['origin']} | {r['name']} | {r['bytes']} | {r['imports']} | {r['exports']} | {r['pdata_functions']} | {r['pdata_anomalies']} | {r['resource_strings']} |" for r in rows]
    lines += ["", "Functiegrenzen volgen de [Microsoft PE-specificatie voor 32-bit MIPS](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format). Leaf functions kunnen ontbreken; ROM-reconstructie heeft aanvullende beperkingen.",
              "", "Machineleesbare evidence: [modules](modules.json), [dependencies](dependencies.json), [summary](summary.json)."]
    (OUT/"index.md").write_text("\n".join(lines)+"\n",encoding="utf-8")
    print(json.dumps(summary),flush=True)


if __name__ == "__main__":
    main()
