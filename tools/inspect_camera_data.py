"""Catalog camera mode table from the ROM; decode offline RVC config snapshots."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]


def decode_config(data):
    if len(data) != 32:
        raise ValueError("RVC_CFG_PARAM.DAT must contain exactly 32 bytes")
    values = struct.unpack("<iIIiiiii", data)
    names = ("guide_flag", "brightness_index", "contrast_index", "guide_rotation",
             "guide_x1", "guide_y1", "guide_x2", "guide_y2")
    fields = dict(zip(names, values))
    # Match signed/unsigned checks observed in RVC, not an assumed stricter schema.
    bad = []
    if values[0] >= 2: bad.append("guide_flag")
    for i in (1, 2):
        if values[i] > 14: bad.append(names[i])
    if not -45 <= values[3] <= 45: bad.append(names[3])
    for i in (4, 6):
        if not -31 <= values[i] <= 69: bad.append(names[i])
    for i in (5, 7):
        if not -21 <= values[i] <= 179: bad.append(names[i])
    return dict(schema="MediaNav-7.0.5.MD-RVC-static-v1", fields=fields,
                fields_reset_by_observed_loader_checks=bad,
                note="Coordinate names describe paired guideline adjustments; physical units unresolved. Negative guide_flag is not rejected by the observed upper-bound-only check.")


def catalog():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "rom" and m["name"] == "camera.dll")
    pe = pefile.PE(str(ROOT / module["path"]))
    entries = []
    for index in range(18):
        va = 0xc097101c + index * 0x18c
        raw = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, 0x18c)
        if len(raw) != 0x18c: raise ValueError("Incomplete camera table")
        words = struct.unpack("<99I", raw)
        entries.append(dict(index=index, va=hex(va), mode_id=words[0x23], mode_id_hex=hex(words[0x23]),
                            width=words[0], height=words[1], selector_88=words[0x22],
                            selector_90=words[0x24], selector_94=words[0x25],
                            dma_channels=words[0x26], sha256=hashlib.sha256(raw).hexdigest(),
                            raw_hex=raw.hex()))
    report = dict(scope="Static table, not camera capabilities verified on hardware", module_sha256=module["sha256"],
                  base_va="0xc097101c", stride=396, entries=entries,
                  rvc_selected_mode=0x1c, rvc_frame_buffer_length=0xa8c00,
                  ioctl={"0x101a004": "Select mode ID: 4 input bytes", "0x1012000": "Read selected mode: 80 output bytes",
                         "0x101a008": "Capture frame into output buffer"})
    out = ROOT / "analysis/firmware/camera-modes.json"
    out.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(dict(modes=len(entries), rvc_mode=next(e for e in entries if e["mode_id"] == 0x1c)), indent=2))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config", type=Path, help="Offline RVC_CFG_PARAM.DAT; does not access a device")
    args = parser.parse_args()
    if args.config:
        print(json.dumps(decode_config(args.config.read_bytes()), indent=2))
    else:
        catalog()


if __name__ == "__main__": main()
