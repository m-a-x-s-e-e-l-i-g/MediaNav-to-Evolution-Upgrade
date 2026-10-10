"""Preserve DAB update/SPI evidence and inspect optional offline firmware files."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
import pefile
from parse_dab_frames import crc_mpeg2

ROOT = Path(__file__).resolve().parents[1]


def buffer_layout(bc_size, uc_size):
    """Describe writes, without inventing bytes for uninitialized allocation areas."""
    total = bc_size + uc_size + 0x4000c
    writes = [(0, 4), (0, bc_size+4), (0x40000, 0x40000+uc_size+8)]
    cursor = 0
    holes = []
    for start, end in sorted(writes):
        if start > cursor:
            holes.append([cursor, start])
        cursor = max(cursor, end)
    if cursor < total:
        holes.append([cursor, total])
    return dict(total_bytes=total, initialized_ranges=[list(x) for x in writes],
                uninitialized_ranges=holes, uninitialized_bytes=sum(b-a for a,b in holes),
                bc_overlaps_uc_header=bc_size+4 > 0x40000,
                dword_allocation_overflow=total > 0xffffffff)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bc", type=Path)
    parser.add_argument("--uc", type=Path)
    args = parser.parse_args()
    path = ROOT/"extracted/705md/upgrade/Storage Card/System/MgrDAB.exe"
    source_hash = hashlib.sha256(path.read_bytes()).hexdigest()
    if source_hash != "375e9ff4da532c5e4090e3beaad28c894772bc1a6fb6f5174fb1afee1bde4e27":
        raise ValueError("Source changed; review saved DAB contracts")
    pe = pefile.PE(str(path))
    base = pe.OPTIONAL_HEADER.ImageBase
    table = struct.unpack("<256I", pe.get_data(0x67070-base,1024))
    expected = []
    for byte in range(256):
        crc = byte << 24
        for _ in range(8):
            crc = ((crc << 1) ^ (0x04c11db7 if crc & 0x80000000 else 0)) & 0xffffffff
        expected.append(crc)
    if list(table) != expected:
        raise ValueError("CRC table differs from reconstructed polynomial")
    evidence = []
    for start, end, role in [
        (0x15cf4,0x15d44,"Leaf CRC function; Ghidra pseudocode is incorrect"),
        (0x15d44,0x16b44,"Firmware layout, boot recovery, erase/program and unconditional zero return"),
        (0x1895c,0x18be4,"Staged BC/UC file lookup and unconditional updater notification"),
        (0x34704,0x34758,"Normal-frame additive checksum"),
        (0x34758,0x34b84,"Register and SDRAM FIFO transport"),
        (0x34c38,0x34e50,"Recovery register writes and update response decoding"),
        (0x34e50,0x34f6c,"Command handshake and fixed 16-word payload"),
        (0x35034,0x35244,"Odd address and byte count SDRAM read/write"),
        (0x355c4,0x35898,"Mode-0/mode-1 framing and polling"),
        (0x358e4,0x35ef8,"Receive checksum, sequence and fragmentation"),
        (0x36658,0x368bc,"Normal SPI command transfer"),
        (0x38584,0x38c2c,"Low-level SPI reads, bursts, open/close and writes"),
        (0x67070,0x67470,"256-entry MSB CRC table"),
    ]:
        raw = pe.get_data(start-base,end-start)
        if len(raw) != end-start:
            raise ValueError("Incomplete evidence range")
        evidence.append(dict(start_va=hex(start),end_va_exclusive=hex(end),role=role,
                             sha256=hashlib.sha256(raw).hexdigest(),raw_hex=raw.hex()))
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    spi_references = [dict(origin=m["origin"],name=m["name"]) for m in modules
                      if "SPI1:".encode("utf-16le") in Path(m["path"]).read_bytes()]
    registry = json.loads((ROOT/"analysis/firmware/boot-registry/records.json").read_text(encoding="utf-8"))
    spi_registry = [r for r in registry["records"]
                    if "spi" in json.dumps({k:v for k,v in r.items() if k != "raw_hex"},ensure_ascii=False).casefold()]
    result = dict(source_sha256=source_hash,evidence=evidence,
                  crc=dict(poly="04c11db7",init="ffffffff",refin=False,refout=False,xorout=0,
                           check_123456789=f"{crc_mpeg2(b'123456789'):08x}",table_matches=True),
                  spi=dict(device="SPI1:",ioctl="80002000",literal_references=spi_references,
                           default_registry_spi_matches=spi_registry),
                  update_commands={"2f02":"boot running", "2f03":"request SDRAM update address",
                                   "2f10":"erase/check CRC", "2f11":"program", "2f01":"finish"},
                  response_commands={"4f02":"running WORD +8", "4f03":"SDRAM address WORDs +8/+10",
                                     "4f10":"CRC result WORD +8", "4f13":"sector progress WORDs +8/+10"},
                  example_layout=buffer_layout(0x20000,0x100000),
                  open_points=["Actual BC/UC images absent from available packages", "SPI1 driver/provider absent from default registry",
                               "Exact DAB chip and boot firmware semantics", "Full tuner/service/UI behavior and runtime timing"])
    (ROOT/"analysis/firmware/dab-update-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps({k:result[k]for k in ("crc","spi","example_layout")},indent=2))
    if bool(args.bc) != bool(args.uc):
        parser.error("Supply both --bc and --uc")
    if args.bc:
        bc,uc = args.bc.read_bytes(),args.uc.read_bytes()
        print(json.dumps(dict(bc_bytes=len(bc),uc_bytes=len(uc),uc_crc=f"{crc_mpeg2(uc):08x}",
                              bc_header_hex=struct.pack(">I",(len(bc)-1)&0xffffffff).hex(),
                              uc_header_hex=struct.pack(">II",crc_mpeg2(uc),(len(uc)-1)&0xffffffff).hex(),
                              layout=buffer_layout(len(bc),len(uc))),indent=2))


if __name__ == "__main__":
    main()
