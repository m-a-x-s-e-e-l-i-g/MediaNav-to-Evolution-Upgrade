"""Static analysis only. Never executes extracted MediaNav binaries or writes firmware."""
from pathlib import Path
import argparse
import csv
import hashlib
import io
import json
import re
import struct
import zipfile

import pefile

ROOT = Path(__file__).resolve().parents[1]
PACKAGES = {
    "705md": "Upgrade_705MD_FavreMod",
    "corruption-fix": "File_Corruption_Fix",
    "remove-md": "remove_md_super_evo",
}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def strings(data):
    found = [(m.start(), "ascii", m.group().decode("ascii"))
             for m in re.finditer(rb"[\x20-\x7e]{6,}", data)]
    found += [(m.start(), "utf16le", m.group().decode("utf-16le"))
              for m in re.finditer(rb"(?:[\x20-\x7e]\x00){6,}", data)]
    return sorted(found)


def pe_info(data):
    pe = pefile.PE(data=data)
    pe.parse_data_directories()
    decode = lambda value: value.decode("ascii", errors="replace") if value else None
    imports = [{"dll": decode(d.dll), "symbols": [
        {"name": decode(s.name), "ordinal": s.ordinal, "iat_va": hex(s.address)}
        for s in d.imports]} for d in getattr(pe, "DIRECTORY_ENTRY_IMPORT", [])]
    exports = [{"name": decode(s.name), "ordinal": s.ordinal,
                "rva": hex(s.address), "forwarder": decode(s.forwarder)}
               for s in getattr(getattr(pe, "DIRECTORY_ENTRY_EXPORT", None), "symbols", [])]
    info = {"machine": hex(pe.FILE_HEADER.Machine),
            "machine_name": pefile.MACHINE_TYPE.get(pe.FILE_HEADER.Machine, "unknown"),
            "subsystem": pe.OPTIONAL_HEADER.Subsystem,
            "subsystem_name": pefile.SUBSYSTEM_TYPE.get(pe.OPTIONAL_HEADER.Subsystem, "unknown"),
            "image_base": hex(pe.OPTIONAL_HEADER.ImageBase),
            "entry_rva": hex(pe.OPTIONAL_HEADER.AddressOfEntryPoint),
            "entry_va": hex(pe.OPTIONAL_HEADER.ImageBase + pe.OPTIONAL_HEADER.AddressOfEntryPoint),
            "sections": [{"name": decode(s.Name.rstrip(b"\0")), "rva": hex(s.VirtualAddress),
                          "raw_offset": s.PointerToRawData, "raw_size": s.SizeOfRawData}
                         for s in pe.sections],
            "imports": imports, "exports": exports, "parser_warnings": pe.get_warnings()}
    pe.close()
    return info


def nk_info(data):
    """Read CE B000FF record framing; validate every additive record checksum."""
    if not data.startswith(b"B000FF\n"):
        return {"format": "unrecognized", "prefix_hex": data[:16].hex()}
    start, length = struct.unpack_from("<II", data, 7)
    pos, records, terminal = 15, [], None
    while pos + 12 <= len(data):
        addr, size, checksum = struct.unpack_from("<III", data, pos)
        pos += 12
        if addr == 0:
            terminal = {"launch_address": hex(size), "checksum": checksum}
            break
        if pos + size > len(data):
            raise ValueError("NK record exceeds file length")
        payload = data[pos:pos+size]
        records.append({"address": hex(addr), "size": size, "file_offset": pos,
                        "checksum": checksum, "checksum_valid": sum(payload) & 0xffffffff == checksum})
        pos += size
    return {"format": "Windows CE B000FF", "image_start": hex(start), "image_length": length,
            "records": records, "terminal": terminal, "trailing_bytes": len(data)-pos,
            "all_checksums_valid": all(r["checksum_valid"] for r in records)}


def verify_lgu(package, directory):
    data = package.read_bytes()
    magic = data[:4].decode("ascii")
    key_name, password = {"LGU0": ("xorArrLGU0", b"I_LOVE_LG^^"),
                          "ULC2": ("xorArrULC2", b"u8u8l^-^8@E4g_H2kq8X_pack")}[magic]
    header = (ROOT / "sources/MediaNavMods/pc/lgutool/lgu2dir/xorArray.h").read_text()
    body = re.search(key_name + r"\[\]\s*=\s*\{(.*?)\}", header, re.S).group(1)
    key = bytes(int(x, 16) for x in re.findall(r"0x([0-9a-fA-F]+)", body))
    if len(key) != 1024:
        raise ValueError("Expected 1024-byte upstream XOR table")
    payload = bytearray(data[1024:])
    # Translate each key position across the payload without a slow per-byte Python loop.
    for i, value in enumerate(key):
        payload[i::1024] = payload[i::1024].translate(bytes(x ^ value for x in range(256)))
    verified = []
    with zipfile.ZipFile(io.BytesIO(payload)) as archive:
        for entry in archive.infolist():
            if entry.is_dir():
                continue
            name = entry.filename.replace("\\", "/")
            target = directory / name
            target.resolve().relative_to(directory.resolve())
            # Reading to EOF checks ZIP CRC and decrypts using the published tool password.
            original = archive.read(entry, pwd=password)
            if sha(original) != sha(target.read_bytes()):
                raise ValueError(f"Extraction mismatch: {name}")
            verified.append(name)
    actual = {p.relative_to(directory).as_posix() for p in directory.rglob("*") if p.is_file()}
    if actual != set(verified):
        raise ValueError("Extracted file set differs from ZIP file set")
    return {"magic": magic, "header_bytes": 1024, "size": len(data), "sha256": sha(data),
            "verified_files": len(verified), "all_crc_and_extracted_hashes_match": True}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--verify-lgu", action="store_true", help="Independent archive CRC + hash verification")
    args = parser.parse_args()
    out = ROOT / "analysis"
    out.mkdir(exist_ok=True)
    result = {"pefile_version": pefile.__version__, "packages": {}}
    for label, folder in PACKAGES.items():
        directory = ROOT / "extracted" / label
        package = ROOT / "sources/MediaNav-to-Evolution-Upgrade" / folder / "upgrade.lgu"
        inventory, binaries = [], []
        for path in sorted(directory.rglob("*")):
            if not path.is_file():
                continue
            data = path.read_bytes()
            name = path.relative_to(directory).as_posix()
            inventory.append({"path": name, "size": len(data), "sha256": sha(data)})
            if data[:2] == b"MZ":
                entry = {"path": name, "size": len(data), "sha256": sha(data)}
                try:
                    entry.update(pe_info(data))
                except pefile.PEFormatError as error:
                    entry["parse_error"] = str(error)
                binaries.append(entry)
                string_dir = out / "strings" / label
                string_dir.mkdir(parents=True, exist_ok=True)
                (string_dir / (path.name + ".txt")).write_text(
                    "\n".join(f"{offset:08x}\t{encoding}\t{text}" for offset, encoding, text in strings(data)),
                    encoding="utf-8")
            if path.name.lower() == "nk.bin":
                (out / (label + "-nk.json")).write_text(json.dumps(nk_info(data), indent=2))
        with (out / (label + "-inventory.csv")).open("w", newline="", encoding="utf-8") as stream:
            writer = csv.DictWriter(stream, fieldnames=["path", "size", "sha256"])
            writer.writeheader()
            writer.writerows(inventory)
        (out / (label + "-pe.json")).write_text(json.dumps(binaries, indent=2), encoding="utf-8")
        data = package.read_bytes()
        summary = {"files": len(inventory), "total_bytes": sum(x["size"] for x in inventory),
                   "pe_files": len(binaries), "package_sha256": sha(data), "package_bytes": len(data),
                   "magic": data[:4].decode("ascii")}
        if args.verify_lgu:
            summary["verification"] = verify_lgu(package, directory)
        result["packages"][label] = summary
        print(label, json.dumps(summary), flush=True)
    (out / "summary.json").write_text(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
