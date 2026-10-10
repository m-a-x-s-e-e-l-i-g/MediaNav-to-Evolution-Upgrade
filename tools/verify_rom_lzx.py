"""Compare compressed ROM sections using the independent Windows CAB/LZX decoder.

Every CE stream gets its own CAB folder. Strip only the CE wrapper and offset
table; preserve the compressed stream. Execute host expand.exe, no firmware.
"""
import hashlib
import json
import os
import struct
import subprocess
from datetime import datetime, timezone
from pathlib import Path
import pefile
from analyze_firmware import nk_info

ROOT = Path(__file__).resolve().parents[1]
def digest(data): return hashlib.sha256(data).hexdigest()


def ce_chunks(raw, label, pointer, maximum_size, chunks):
    total = int.from_bytes(raw[:3], "little")
    count = (total + 4095) // 4096 if total else 1
    previous = (count + 1) * 3
    ids = []
    for block_index in range(count):
        next_offset = int.from_bytes(raw[(block_index + 1)*3:(block_index + 2)*3], "little")
        if not previous < next_offset <= len(raw): raise ValueError((label, "bad CE offset table"))
        block = raw[previous:next_offset]
        window, output_size, compressed_size, fourth = struct.unpack_from("<4I", block)
        payload = block[16:]
        if not 15 <= window <= 21 or not 0 < output_size <= 4096 or len(payload) != compressed_size:
            raise ValueError((label, block_index, "unsupported CE block", window, output_size, len(payload), compressed_size))
        cid = len(chunks)
        ids.append(cid)
        chunks.append(dict(id=cid, filename=f"b{cid:06d}.dat", window_bits=window,
                           output_size=output_size, payload=payload, wrapper_word_3=fourth,
                           ce_source_va=hex(pointer + previous), compressed_sha256=digest(payload)))
        previous = next_offset
    actual = sum(chunks[cid]["output_size"] for cid in ids)
    if actual != total or actual > maximum_size: raise ValueError((label, "output length", total, actual, maximum_size))
    return total, ids


def cabinet(chunks):
    files = bytearray()
    for index, chunk in enumerate(chunks):
        files += struct.pack("<IIHHHH", chunk["output_size"], 0, index, 0, 0, 0)
        files += chunk["filename"].encode("ascii") + bytes([0])
    offset = 36 + len(chunks) * 8 + len(files)
    folders, blocks = bytearray(), bytearray()
    for chunk in chunks:
        payload = chunk["payload"]
        folders += struct.pack("<IHH", offset + len(blocks), 1, 3 | chunk["window_bits"] << 8)
        blocks += struct.pack("<IHH", 0, len(payload), chunk["output_size"]) + payload
    size = 36 + len(folders) + len(files) + len(blocks)
    header = struct.pack("<4sIIIII BB HHHHH", b"MSCF", 0, size, 0, 36 + len(folders), 0,
                         3, 1, len(chunks), len(chunks), 0, 0, 0)
    return header + folders + files + blocks


def main():
    source = (ROOT / "extracted/705md/upgrade/Storage Card/NK.bin").read_bytes()
    framing = nk_info(source)
    if not framing["all_checksums_valid"]: raise ValueError("Invalid source NK checksums")
    records = framing["records"]
    base = min(int(r["address"], 16) for r in records)
    end = max(int(r["address"], 16) + r["size"] for r in records)
    flat = bytearray(end - base)
    for record in records:
        address = int(record["address"], 16) - base
        offset = record["file_offset"]
        flat[address:address + record["size"]] = source[offset:offset + record["size"]]
    def read(va, size):
        if not base <= va <= va + size <= end: raise ValueError("ROM address outside image")
        return bytes(flat[va-base:va-base+size])
    hdr_va = struct.unpack_from("<I", flat, 0x44)[0]
    hdr = struct.unpack("<17I2HI2I", read(hdr_va, 84))
    chunks, sections, files = [], [], []
    for index in range(hdr[4]):
        toc = struct.unpack("<8I", read(hdr_va + 84 + index * 32, 32))
        name = read(toc[4], min(256, end - toc[4])).split(bytes([0]), 1)[0].decode("ascii")
        section_count = struct.unpack_from("<H", read(toc[5], 0x6c))[0]
        for section_index in range(section_count):
            vsize, rva, psize, pointer, real_address, flags = struct.unpack("<6I", read(toc[6] + section_index * 24, 24))
            if not flags & 0x2000: continue
            raw = read(pointer, psize)
            total, ids = ce_chunks(raw, (name, section_index), pointer, vsize, chunks)
            sections.append(dict(module=name, section_index=section_index, rva=hex(rva), source_va=hex(pointer),
                                 compressed_size=psize, declared_size=total, virtual_size=vsize, chunk_ids=ids))
    file_table = hdr_va + 84 + hdr[4] * 32
    for index in range(hdr[12]):
        attrs, time_lo, time_hi, real_size, stored_size, name_pointer, pointer = struct.unpack("<7I", read(file_table + index * 28, 28))
        name = read(name_pointer, min(256, end - name_pointer)).split(bytes([0]), 1)[0].decode("ascii")
        raw = read(pointer, stored_size)
        compressed = stored_size != real_size
        total, ids = ce_chunks(raw, name, pointer, real_size, chunks) if compressed else (real_size, [])
        if total != real_size: raise ValueError((name, "file output length", total, real_size))
        files.append(dict(name=name, original_size=real_size, stored_size=stored_size,
                          source_va=hex(pointer), compressed=compressed, chunk_ids=ids))
    now = datetime.now(timezone.utc)
    work = ROOT / "analysis/rom-verification-work" / now.strftime("%Y%m%d-%H%M%S-%f")
    work.mkdir(parents=True, exist_ok=False)
    expanded = work / "expanded"
    expanded.mkdir()
    expand = Path(os.environ["SystemRoot"]) / "System32/expand.exe"
    commands = []
    for first in range(0, len(chunks), 200):
        batch = chunks[first:first + 200]
        cab = work / f"batch-{first:06d}.cab"
        cab.write_bytes(cabinet(batch))
        result = subprocess.run([str(expand), "-R", str(cab), "-F:*", str(expanded)], capture_output=True, text=True)
        (work / f"batch-{first:06d}.log").write_text(result.stdout + result.stderr, encoding="utf-8")
        commands.append(dict(first_chunk=first, count=len(batch), exit_code=result.returncode, cabinet_sha256=digest(cab.read_bytes())))
        if result.returncode: raise RuntimeError(f"expand.exe failed for {cab.name}: {result.returncode}; inspect local log")
        for chunk in batch:
            output = (expanded / chunk["filename"]).read_bytes()
            if len(output) != chunk["output_size"]: raise ValueError((chunk["id"], "decoder output size"))
            chunk["decoded_sha256"] = digest(output)
        print(f"Decoded {min(first+200, len(chunks))}/{len(chunks)} independent LZX streams", flush=True)
    for section in sections:
        decoded = b"".join((expanded / chunks[cid]["filename"]).read_bytes() for cid in section["chunk_ids"])
        padded = decoded.ljust(section["virtual_size"], bytes([0]))
        pe = pefile.PE(str(ROOT / "extracted/705md-rom/fs/Windows" / section["module"]))
        extracted = pe.get_data(int(section["rva"], 16), section["virtual_size"])
        pe.close()
        section["matched"] = padded == extracted
        section["decoded_sha256"] = digest(decoded)
        section["zero_padding"] = section["virtual_size"] - len(decoded)
        if not section["matched"]: raise ValueError((section["module"], section["section_index"], "decompression differs"))
    for item in files:
        decoded = b"".join((expanded / chunks[cid]["filename"]).read_bytes() for cid in item["chunk_ids"]) if item["compressed"] else read(int(item["source_va"], 16), item["stored_size"])
        extracted = (ROOT / "extracted/705md-rom/fs/Windows" / item["name"]).read_bytes()
        item["matched"] = decoded == extracted
        item["decoded_sha256"] = digest(decoded)
        if not item["matched"]: raise ValueError((item["name"], "file bytes differ"))
    for chunk in chunks: del chunk["payload"]
    report = dict(generated_utc=now.isoformat(), source_nk_sha256=digest(source),
                  scope="Independent Windows CAB/LZX decoder agreement for compressed module sections and files; raw ROM files compared directly. No firmware execution or hardware validation",
                  decoder_path=str(expand), decoder_sha256=digest(expand.read_bytes()),
                  tool_sha256=digest(Path(__file__).read_bytes()), work_directory=str(work),
                  sections_matched=len(sections), streams_decoded=len(chunks), all_matched=True,
                  compressed_files_matched=sum(f["compressed"] for f in files), raw_files_matched=sum(not f["compressed"] for f in files),
                  commands=commands, sections=sections, files=files, chunks=chunks)
    (ROOT / "analysis/705md-rom-lzx-verification.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(dict(sections_matched=len(sections), streams_decoded=len(chunks),
                         compressed_files_matched=report["compressed_files_matched"], raw_files_matched=report["raw_files_matched"], all_matched=True)))


if __name__ == "__main__": main()
