"""Read offline DAB option records and preserve cross-process source evidence."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
FIELDS = ["DLS", "Transport", "Warning", "News", "Weather", "Event", "Special Event",
          "Program Info", "Sport", "Financial", "TA", "unknown_last_dword"]


def normalize(values):
    # Firmware uses signed SLTI value,2: negative integers survive.
    return [0 if v > 1 else v for v in values]


def decode_options(data):
    if len(data) < 48:
        return dict(bytes=len(data), valid_record=False, reason="Loader requires a successful 48-byte read")
    raw = list(struct.unpack("<12i",data[:48]))
    values = normalize(raw)
    return dict(bytes=len(data),ignored_trailing_bytes=len(data)-48,valid_record=True,raw=dict(zip(FIELDS,raw)),
                after_load=dict(zip(FIELDS,values)),negative_values_survive=any(v<0 for v in values))


def config_payload(values, korea=False):
    """Nine wire payload bytes built by ApplyDABConfig + SetConfig, not a full frame."""
    if len(values) != 12:
        raise ValueError("Expected twelve option DWORDs")
    mask = 0x2001 | (2 if values[10] else 0)
    for index in range(1,10):
        if values[index]:
            mask |= 1 << (index+1)
    return bytes([2 | (0x18 if values[0] else 0), 200, 4 if korea else 1,
                  mask >> 8, mask & 255, 1, 1, 2, 0])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config",type=Path,help="Read a local DABinfo.cfg; never overwrite it")
    args = parser.parse_args()
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    evidence = []
    sources = {}
    for name,ranges in [
        ("MgrDAB.exe",[(0x119ec,0x11c3c),(0x123f4,0x1242c),(0x1d548,0x1db44),
                       (0x1e2b8,0x1ea9c),(0x26620,0x267d0),(0x2697c,0x269bc),
                       (0x2a834,0x2a92c),(0x36650,0x36658)]),
        ("AppMain.exe",[(0x908d8,0x92358),(0x92358,0x92eec),(0x99f04,0x9ae3c),
                       (0x9ae3c,0x9b144),(0x9b528,0x9b5c0)])]:
        module = next(m for m in modules if m["origin"]=="705md" and m["name"]==name)
        path = ROOT/module["path"]
        source_hash = hashlib.sha256(path.read_bytes()).hexdigest()
        if source_hash != module["sha256"]:
            raise ValueError("Source hash differs from inventory")
        sources[name] = source_hash
        pe = pefile.PE(str(path))
        for start,end in ranges:
            raw = pe.get_data(start-pe.OPTIONAL_HEADER.ImageBase,end-start)
            if len(raw) != end-start:
                raise ValueError("Incomplete evidence range")
            evidence.append(dict(module=name,start_va=hex(start),end_va_exclusive=hex(end),
                                 raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    english = next(m for m in modules if m["origin"]=="705md" and m["name"]=="LangDllEng.dll")
    english_hash = hashlib.sha256((ROOT/english["path"]).read_bytes()).hexdigest()
    if english_hash != english["sha256"]:
        raise ValueError("Language source changed")
    sources["LangDllEng.dll"] = english_hash
    labels = [s for s in english["resource_strings"] if s["id"]in range(0xbb8,0xbc4) or s["id"]in (0x456,0x581,0x582)]
    option_routes = [dict(file_offset=i*4,field=field,
                          app_to_dab_command=hex(0x6b if i==0 else 0x6c if i==10 else 0x6c+i) if i<11 else None)
                     for i,field in enumerate(FIELDS)]
    result = dict(source_hashes=sources,evidence=evidence,record_bytes=48,
                  signed_normalization="value > 1 becomes zero; negative integers are retained",
                  reset="Reset writes zeros to first eleven DWORDs; final DWORD preserved; constructor initially zeroes all twelve",
                  option_routes=option_routes,english_labels=labels,
                  shared_memory=[dict(name=name,bytes=size) for name,size in [
                      ("ShmFmMgrDABCurrentStation",0x66c),("ShmFmMgrDABPresetList",0x4d14),
                      ("ShmFmMgrDABScanList",0x714c),("ShmFmMgrDABOption",0x30),
                      ("ShmFmMgrDABEPG",0x19cc),("ShmFmMgrDABAnnInfo",0x28),("ShmFmMgrDABDsiInfo",0x1c)]],
                  zero_option_wire_payload=config_payload([0]*12).hex(),
                  all_option_wire_payload=config_payload([1]*12).hex(),
                  open_points=["Final option DWORD meaning", "Announcement receive priority/audio switching",
                               "All shared station/list/EPG field semantics", "Driver and unit runtime validation"])
    (ROOT/"analysis/firmware/dab-options-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps({k:result[k]for k in ("option_routes","zero_option_wire_payload","all_option_wire_payload")},indent=2))
    if args.config:
        print(json.dumps(decode_options(args.config.read_bytes()),indent=2))


if __name__=="__main__":
    main()
