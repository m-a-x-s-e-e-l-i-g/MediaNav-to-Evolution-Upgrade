"""Verify ROM extraction against source records and emit narrowly scoped research evidence."""
from pathlib import Path
import collections
import hashlib
import json
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent / "python-libs"))
import capstone
import pefile
from analyze_firmware import nk_info, strings

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "analysis"


def digest(data):
    return hashlib.sha256(data).hexdigest()


def inspect_rom():
    data = (ROOT / "extracted/705md/upgrade/Storage Card/NK.bin").read_bytes()
    framing = nk_info(data)
    assert framing["all_checksums_valid"] and framing["trailing_bytes"] == 0 and framing["terminal"]
    records = framing["records"]
    start = min(int(r["address"], 16) for r in records)
    end = max(int(r["address"], 16) + r["size"] for r in records)
    flat = bytearray(end-start)
    for record in records:
        addr, size, off = int(record["address"], 16), record["size"], record["file_offset"]
        flat[addr-start:addr-start+size] = data[off:off+size]

    def read(va, size):
        assert start <= va and va+size <= end, (hex(va), size)
        return bytes(flat[va-start:va-start+size])

    def name_at(va):
        return read(va, min(256, end-va)).split(b"\0")[0].decode("ascii")

    assert flat[0x40:0x44] == b"ECEC"
    hdr_va, relative = struct.unpack_from("<II", flat, 0x44)
    assert hdr_va-start == relative
    hdr = struct.unpack("<17I2HI2I", read(hdr_va, 84))
    modules, files, checks, skipped = [], [], [], []
    rom_dir = ROOT / "extracted/705md-rom/fs/Windows"
    for index in range(hdr[4]):
        toc_va = hdr_va+84+index*32
        fields = struct.unpack("<8I", read(toc_va, 32))
        attrs, time_lo, time_hi, file_size, name_va, e32_va, o32_va, load_va = fields
        name = name_at(name_va)
        e32 = read(e32_va, 0x6c)
        count, _flags, entry, vbase = struct.unpack_from("<HHII", e32)
        sections = [struct.unpack("<6I", read(o32_va+j*24, 24)) for j in range(count)]
        pe = pefile.PE(str(rom_dir/name))
        counts = collections.Counter(s[1] for s in sections)
        for j, (vsize, rva, psize, dataptr, realaddr, flags) in enumerate(sections):
            item = {"module": name, "section_index": j, "rva": hex(rva), "source_va": hex(dataptr), "source_bytes": psize}
            if flags & 0x2000:
                item["reason"] = "compressed section; decompression not independently verified"
                skipped.append(item)
            elif counts[rva] != 1:
                item["reason"] = "shared RVA; compare shadow bytes separately"
                skipped.append(item)
            elif not psize:
                item["reason"] = "no source bytes"
                skipped.append(item)
            else:
                source = read(dataptr, psize)
                reconstructed = pe.get_data(rva, psize)
                assert source == reconstructed, (name, j, hex(rva))
                item["sha256"] = digest(source)
                checks.append(item)
        modules.append({"name": name, "toc_va": hex(toc_va), "e32_va": hex(e32_va),
                        "o32_va": hex(o32_va), "load_va": hex(load_va), "image_base": hex(vbase),
                        "entry_rva": hex(entry), "section_count": count, "original_file_size": file_size})
        pe.close()
    file_start = hdr_va+84+hdr[4]*32
    for index in range(hdr[12]):
        # FILESentry = attrs, FILETIME(lo/hi), original size, compressed size, name VA, data VA.
        values = struct.unpack("<7I", read(file_start+index*28, 28))
        files.append({"name": name_at(values[5]), "original_size": values[3],
                      "stored_size": values[4], "source_va": hex(values[6])})
    meta = json.loads((ROOT / "extracted/705md-rom/rom_meta.json").read_text())
    assert {m["name"] for m in modules} == {m["name"] for m in meta["modules"]}
    assert len(files) == len(meta["files"])
    result = {"source_nk_sha256": digest(data), "romhdr_va": hex(hdr_va),
              "cpu_type": hex(hdr[17]), "module_count": len(modules), "file_count": len(files),
              "matched_uncompressed_sections": len(checks), "skipped_sections": skipped,
              "section_checks": checks, "modules": modules, "files": files,
              "scope": "Independent record framing, TOC counts/names and uncompressed PE section bytes; compressed sections and registry semantics remain best-effort"}
    (OUT / "705md-rom-verification.json").write_text(json.dumps(result, indent=2))
    core = pefile.PE(str(rom_dir/"coredll.dll"))
    exports = {str(s.ordinal): s.name.decode() for s in core.DIRECTORY_ENTRY_EXPORT.symbols if s.name}
    (OUT / "705md-coredll-ordinals.json").write_text(json.dumps(exports, indent=2))
    return result


def inspect_hex():
    path = ROOT / "extracted/705md/upgrade/firmware.hex"
    memory, types, starts = {}, collections.Counter(), []
    base, eof, dos_eof = 0, False, False
    lines = path.read_text().splitlines()
    for number, line in enumerate(lines, 1):
        if line == "\x1a" and eof and number == len(lines):
            dos_eof = True
            continue
        assert line.startswith(":"), number
        raw = bytes.fromhex(line[1:])
        assert len(raw) == raw[0]+5 and sum(raw) & 0xff == 0, number
        assert not eof, "record after EOF"
        size, offset, kind = raw[0], int.from_bytes(raw[1:3], "big"), raw[3]
        payload = raw[4:4+size]
        types[kind] += 1
        if kind == 0:
            for i, value in enumerate(payload):
                address = base+offset+i
                assert address not in memory or memory[address] == value, (number, address)
                memory[address] = value
        elif kind == 1:
            assert size == 0
            eof = True
        elif kind in (2, 4):
            assert size == 2
            base = int.from_bytes(payload, "big") << (4 if kind == 2 else 16)
        elif kind in (3, 5):
            assert size == 4
            starts.append({"type": kind, "hex": payload.hex()})
        else:
            raise ValueError(f"Unknown Intel HEX record type: {kind}")
    assert eof
    result = {"sha256": digest(path.read_bytes()), "all_record_checksums_valid": True,
              "record_types": dict(types), "unique_data_bytes": len(memory),
              "lowest_address": hex(min(memory)), "highest_address": hex(max(memory)),
              "start_records": starts, "trailing_dos_eof": dos_eof,
              "cpu": "not identified from Intel HEX framing"}
    ordered=bytes(memory[address] for address in range(min(memory),max(memory)+1))
    firmware_dir=OUT/"firmware"
    firmware_dir.mkdir(exist_ok=True)
    (firmware_dir/"micom-image.bin").write_bytes(ordered)
    result["flat_image_sha256"]=digest(ordered)
    result["flat_image_bytes"]=len(ordered)
    result["ascii_build_markers"]=[{"offset":hex(off),"text":text} for off,encoding,text in strings(ordered)
                                   if encoding=="ascii" and (text=="SK0RT03N200GV101" or text.startswith("4.0.6.0413"))]
    (OUT / "705md-firmware-hex.json").write_text(json.dumps(result, indent=2))
    return result


def inspect_navigation():
    path = ROOT / "extracted/corruption-fix/upgrade/Storage Card4/NNG/nngnavi.exe"
    data = path.read_bytes()
    pe = pefile.PE(data=data)
    base = pe.OPTIONAL_HEADER.ImageBase
    pattern = "File corruption detected, Navigation stops.".encode("utf-16le")
    off = data.index(pattern)
    target = base+pe.get_rva_from_offset(off)
    xrefs, dumps = [], []
    decoder = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32 | capstone.CS_MODE_LITTLE_ENDIAN)
    decoder.skipdata = True
    # Narrow LUI + ADDIU/ORI address materialization search; candidates require control-flow review.
    for section in pe.sections:
        if not section.Characteristics & 0x20000000:
            continue
        raw = section.get_data()
        words = struct.unpack("<"+"I"*(len(raw)//4), raw[:len(raw)//4*4])
        for i, word in enumerate(words):
            if word >> 26 != 15:
                continue
            reg, high = (word >> 16) & 31, (word & 0xffff) << 16
            for j in range(i+1, min(i+17, len(words))):
                other = words[j]
                opcode, src, imm = other >> 26, (other >> 21) & 31, other & 0xffff
                if opcode not in (9, 13) or src != reg:
                    continue
                value = high | imm if opcode == 13 else (high+(imm if imm < 0x8000 else imm-0x10000)) & 0xffffffff
                if value != target:
                    continue
                address = base+section.VirtualAddress+j*4
                xrefs.append({"lui_va": hex(base+section.VirtualAddress+i*4), "address_load_va": hex(address)})
                lo, hi = max(0, i*4-96), min(len(raw), j*4+160)
                dumps.append("\n; error-string address candidate " + hex(address))
                dumps.extend(f"{addr:08x} {mnemonic:<9} {operands}" for addr, _size, mnemonic, operands
                             in decoder.disasm_lite(raw[lo:hi], base+section.VirtualAddress+lo))
    versions = [entry.entries for group in pe.FileInfo for item in group
                for entry in getattr(item, "StringTable", [])]
    version = [{k.decode(): v.decode() for k,v in entry.items()} for entry in versions]
    result = {"sha256": digest(data), "version_resources": version,
              "error_string_file_offset": hex(off), "error_string_va": hex(target),
              "error_string_xref_candidates": xrefs,
              "patch_proven": False, "reason": "No matching original unmodified nngnavi.exe for byte comparison"}
    (OUT / "navigation-fix.json").write_text(json.dumps(result, indent=2))
    (OUT / "disassembly/nngnavi-error-xrefs.asm").write_text("\n".join(dumps))
    return result


def inspect_ipc():
    path = ROOT / "extracted/705md/upgrade/Storage Card/System/CmnDll.dll"
    pe = pefile.PE(str(path))
    # Table location and 32-byte stride verified in IntGetProcessName assembly.
    table = pe.get_data(0x7144, 42*32)
    targets = [{"id": i, "name": table[i*32:(i+1)*32].decode("utf-16le").split("\0")[0]}
               for i in range(42)]
    calls = json.loads((OUT / "disassembly/AppMain.exe-candidates.json").read_text())["candidates"]
    usb_calls = [c for c in calls if c["kind"] == "import_call" and "!Ipc" in c["symbol"]
                 and c.get("constant_arg_candidates", {}).get("$a1") == 5]
    usb = pefile.PE(str(ROOT / "extracted/705md/upgrade/Storage Card/System/MgrUSB.exe"))
    table_va = 0x21dd4
    offsets = struct.unpack("<25h", usb.get_data(table_va-usb.OPTIONAL_HEADER.ImageBase, 50))
    names = {100: "previous track", 101: "next track", 106: "shuffle", 107: "repeat", 108: "play status"}
    dispatch = [{"command": 100+i, "receiver_case_va": hex(table_va+offset),
                 "meaning": names.get(100+i, "not yet traced")}
                for i, offset in enumerate(offsets)]
    result = {"targets": targets, "AppMain_to_USB_call_candidates": usb_calls,
              "usb_dispatch_table_va": hex(table_va), "usb_dispatch": dispatch,
              "usb_status_mapping_name": "ShmFmMgrUsbAppMain", "usb_status_mapping_bytes": 0xe56,
              "ipc_getmsg": {
                  "dll_rva": "0x32b8",
                  "fourth_argument": "Address of LPARAM storage, not LPARAM value",
                  "caller_evidence_va": ["0x170cc", "0x170e4", "0x170f0"],
                  "small_message": "Stores fourth argument as payload pointer at output +0xc",
                  "copydata_message": "Dereferences fourth argument to obtain COPYDATASTRUCT pointer",
                  "output_fields": {"0x0": "source, 16-bit store", "0x4": "command, 16-bit store",
                                    "0x8": "payload size, 32-bit store", "0xc": "payload pointer, 32-bit store"},
                  "scope": "Manually traced CmnDll and AppMain calling convention; no runtime test"
              },
              "candidate_scope": "Locally known argument constants; verify function meaning and receiver behavior before use"}
    (OUT / "705md-ipc.json").write_text(json.dumps(result, indent=2))
    return result


def main():
    rom = inspect_rom()
    print("ROM verified:",rom["module_count"],"modules,",rom["matched_uncompressed_sections"],"uncompressed sections",flush=True)
    print("HEX:",json.dumps(inspect_hex()),flush=True)
    print("Navigation:",json.dumps(inspect_navigation()),flush=True)
    ipc = inspect_ipc()
    print("IPC:",len(ipc["targets"]),"targets,",len(ipc["AppMain_to_USB_call_candidates"]),"USB call candidates",flush=True)


if __name__ == "__main__":
    main()
