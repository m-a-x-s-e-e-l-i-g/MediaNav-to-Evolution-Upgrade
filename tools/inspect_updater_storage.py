"""Record updater storage/header contracts from source bytes; no disk operations."""
import hashlib
import json
import re
import struct
import zlib
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]


def format_options(index, extended=False, transactional=False):
    return dict(cluster_bytes=8192 if index == 3 else 512, root_entries=512,
                fat_version=64 if extended else 32, fat_count=2 if transactional else 1,
                flags=(16 if extended else 0) | (2 if transactional else 0))


def main():
    path = ROOT/"extracted/705md/upgrade/Storage Card/System/UpgradeManager.exe"
    source_hash = hashlib.sha256(path.read_bytes()).hexdigest()
    if source_hash != "4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87":
        raise ValueError("Source changed; manually review the recorded contracts")
    pe = pefile.PE(str(path))
    base = pe.OPTIONAL_HEADER.ImageBase
    evidence = []
    for va, size, role in [(0x1189c,0x1a4,"Open LGU and compute unused preliminary CRC"),
                           (0x11a40,0x144,"Extract worker retains output root in a1 across virtual call"),
                           (0x11c50,0x168,"CRC streaming from configurable file offset"),
                           (0x12014,0x134,"Optional post-extraction CRC verification"),
                           (0x13b20,0x11c,"Strict four-byte power-counter reader"),
                           (0x14eb0,0x7b0,"Pending staging, config preservation and final file copies"),
                           (0x15660,0x220,"Package-mode formatting and extract dispatch"),
                           (0x15880,0x7c,"Event-gated firmware phase"),
                           (0x16b6c,0x590,"Boot-time empty-volume format helper"),
                           (0x170fc,0x358,"Config partition scan"),
                           (0x17964,0x470,"Header discovery and lexical version gate"),
                           (0x181b4,0x2ac,"Copy then delete staging files"),
                           (0x18460,0x238,"Recursive config backup"),
                           (0x197a8,0x5a0,"Extraction retries and success marker"),
                           (0x1a3a4,0x45c,"Explicit formatter and imperfect error propagation"),
                           (0x1aa94,0x1a4,"LGU header validation"),
                           (0x2e1c8,1024,"CRC32 table"),
                           (0x346bc,12,"ZIP password bytes"),
                           (0x373dc,1024,"LGU0 XOR table"),
                           (0x377e8,32,"Four partition and volume name pointers")]:
        raw = pe.get_data(va-base,size)
        if len(raw) != size:
            raise ValueError((hex(va),"Missing evidence bytes"))
        evidence.append(dict(start_va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    key = pe.get_data(0x373dc-base,1024)
    upstream = (ROOT/"sources/MediaNavMods/pc/lgutool/lgu2dir/xorArray.h").read_text()
    body = re.search(r"xorArrLGU0\[\]\s*=\s*\{(.*?)\}",upstream,re.S).group(1)
    upstream_key = bytes(int(v,16) for v in re.findall(r"0x([0-9a-fA-F]+)",body))
    if key != upstream_key:
        raise ValueError("Actual updater XOR key differs from extracted upstream LGU0 key")
    packages = {}
    for origin, relative in [("705md","Upgrade_705MD_FavreMod/upgrade.lgu"),
                              ("corruption-fix","File_Corruption_Fix/upgrade.lgu"),
                              ("remove-md","remove_md_super_evo/upgrade.lgu")]:
        data = (ROOT/"sources/MediaNav-to-Evolution-Upgrade"/relative).read_bytes()
        words = struct.unpack_from("<6I",data)
        packages[origin] = dict(bytes=len(data),header_words=[hex(v)for v in words],
                                crc_after_header=hex(zlib.crc32(data[1024:])),
                                size_field_matches=words[3]+(words[4]<<32)==len(data))
    modes = {str(mode):dict(format_indices=[],options=[]) for mode in range(-1,13)}
    for mode in modes:
        number = int(mode)
        if number == -1:
            indices = [2]
        elif number == 0 or number >= 8:
            indices = []
        else:
            indices = [3,1]
        modes[mode]["format_indices"] = indices
        modes[mode]["options"] = [format_options(i,number==3 and i==3,number==3 and i==3)for i in indices]
    micom_path=ROOT/"extracted/705md/upgrade/Storage Card/System/MicomManager.exe"
    micom_hash=hashlib.sha256(micom_path.read_bytes()).hexdigest()
    if micom_hash!="c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824":
        raise ValueError("MICOM source changed")
    micom_pe=pefile.PE(str(micom_path));micom_evidence=[]
    for va,size,role in [(0x1dbb0,0x218,"SavePwrCount read/increment/write"),
                         (0x22e64,0x4a4,"PowerOff caller and shutdown ordering"),
                         (0x2113c,0x2b4,"Reset deletes persistent power counter")]:
        raw=micom_pe.get_data(va-micom_pe.OPTIONAL_HEADER.ImageBase,size)
        if len(raw)!=size:raise ValueError("Truncated MICOM counter evidence")
        micom_evidence.append(dict(start_va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    result = dict(scope="Static partition/header evidence, source binaries unchanged", source_sha256=source_hash,
                  micom_sha256=micom_hash,micom_power_counter_evidence=micom_evidence,
                  evidence=evidence, xor_key_matches_upstream=True, xor_key_sha256=hashlib.sha256(key).hexdigest(),
                  partitions={"0":"PART00 / Storage Card","1":"PART01 / Storage Card2",
                              "2":"PART02 / Storage Card3","3":"PART03 / Storage Card4"},
                  format_options_default=[format_options(i)for i in range(4)],mode_formatting=modes,
                  packages=packages,open_points=["Complete ZIP directory/ZIP64 parsing and malformed-input behavior",
                                                "Actual unit partition sizes and mount attributes",
                                                "Actual restart/bootloader execution after MICOM upgrade and interrupted-update recovery"])
    (ROOT/"analysis/firmware/updater-storage-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps({"xor_key_matches_upstream":True,"partitions":result["partitions"],"packages":packages},indent=2))


if __name__ == "__main__":
    main()
