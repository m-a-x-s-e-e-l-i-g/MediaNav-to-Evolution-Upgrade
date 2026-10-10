"""Preserve static updater/NOR-driver contracts and package file presence; never flash."""
import hashlib
import json
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
KNOWN_HASHES = {
    "UpgradeManager.exe": "4d6ffa36bc0e42945ba1ebce79de48d82030894e0e1f9c9e05165d3c33735f87",
    "Physical_Manager.dll": "bc22a6977ae5822a868e76fdc855689cb5c5521c87b19937b0fd4f8168601fce",
}


def main():
    modules = []
    for origin, name, relative, ranges in [
        ("705md", "UpgradeManager.exe", "extracted/705md/upgrade/Storage Card/System/UpgradeManager.exe",
         [(0x17530, 0x434, "Prepare firmware layers, NK copy and DAB/MICOM dispatch"),
          (0x19d78, 0x3d4, "NOR file writer"), (0x1a14c, 0x258, "NOR driver open and retry wrapper")]),
        ("rom", "Physical_Manager.dll", "extracted/705md-rom/fs/Windows/Physical_Manager.dll",
         [(0xc09e178c, 0x74, "Bank/sector lookup"), (0xc09e1800, 0x26c, "NOR command writes"),
          (0xc09e1a6c, 0x70, "Erase command sequence"), (0xc09e1adc, 0xfc, "Toggle-bit status poll"),
          (0xc09e1bd8, 0xa4, "Sector erase/status wrapper"), (0xc09e1c7c, 0x210, "Buffer-program helper"),
          (0xc09e1e8c, 0x140, "Two halfword programming helper"), (0xc09e1fcc, 0x14c, "Erase-range wrapper"),
          (0xc09e2118, 0x1e4, "Program-range wrapper"), (0xc09e22fc, 0xa0, "DWORD-count memory read"),
          (0xc09e239c, 0xb0, "All four PHM_IOControl commands")]),
    ]:
        path = ROOT / relative
        source_hash = hashlib.sha256(path.read_bytes()).hexdigest()
        if source_hash != KNOWN_HASHES[name]:
            raise ValueError(f"{name} source changed; contract constants require new review")
        pe = pefile.PE(str(path))
        evidence = []
        for va, size, meaning in ranges:
            raw = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, size)
            if len(raw) != size:
                raise ValueError((name, hex(va), "Missing evidence bytes"))
            evidence.append(dict(start_va=hex(va), size=size, role=meaning, raw_hex=raw.hex(), sha256=hashlib.sha256(raw).hexdigest()))
        modules.append(dict(origin=origin, name=name, source_path=relative,
                            source_sha256=source_hash, ranges=evidence))
        pe.close()
    package_presence = {}
    for origin in ("705md", "remove-md", "corruption-fix"):
        root = ROOT / "extracted" / origin
        files = [p for p in root.rglob("*") if p.is_file()]
        package_presence[origin] = {
            name: [str(p.relative_to(root)).replace("\\", "/") for p in files if p.name.lower() == name.lower()]
            for name in ("booter_standalone.bin", "NK.bin", "firmware.hex", "ulc_dab_bc_LGe.bin", "ulc_dab_uc_LGe.bin")}
    result = dict(scope="Static source-byte evidence and extracted-package presence, no device access or firmware writes",
                  nor_base="0xbfc00000", bank_stride=0x400000, erase_sector_stride=0x8000,
                  updater_transfer_block=0x10000, updater_max_file=0x3e0000,
                  phm_record_size=12, phm_record_fields={"0": "source/destination caller pointer; unused for erase",
                                                      "4": "flash address", "8": "bytes for erase/write, DWORD count for read"},
                  ioctls={"0": "erase range", "1": "write range", "2": "read memory in DWORDs",
                          "3": "erase first 64 KiB (driver label: delete touch calibration data)"},
                  modules=modules, package_presence=package_presence)
    (ROOT / "analysis/firmware/boot-update-contracts.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps({"modules": [m["name"] for m in modules], "package_presence": package_presence}, indent=2))


if __name__ == "__main__":
    main()
