"""Inspect radio-code UI contracts and an optional local attempt-counter file."""
import argparse
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]


def decode_counter(data):
    if len(data) != 4:
        return dict(bytes=len(data), valid_record=False, effective_count=0)
    value = struct.unpack("<i", data)[0]
    return dict(bytes=4, valid_record=True, raw_signed_count=value, effective_count=max(0,min(8,value)))


def micom_delay(count):
    if count == 0:
        return 60
    if 1 <= count <= 3:
        return 120
    return {4:240,5:480,6:960}.get(count,1920)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--counter", type=Path, help="Read an offline Antitheft.cfg copy; no registry/code extraction")
    args = parser.parse_args()
    path = ROOT/"extracted/705md/upgrade/Storage Card/System/CodeChecker.exe"
    source_hash = hashlib.sha256(path.read_bytes()).hexdigest()
    if source_hash != "3746a195cb1a0121fdf55359b0c36672d07735b9bff793c7635342b1a13d1e6a":
        raise ValueError("Source changed; review the saved UI contracts")
    pe = pefile.PE(str(path))
    evidence = []
    for va,size,role in [(0x111fc,0xcc,"Registry binary read with original sixth size argument"),
                         (0x18b8c,0x64,"Persist attempt counter"),
                         (0x18bf0,8,"Reset in-memory attempt counter"),
                         (0x18c3c,0xbc,"Read signed counter and clamp 0..8"),
                         (0x18cf8,0x60,"Read FACTORY_TYPE"),
                         (0x1995c,0x2e0,"Result dialog and factory wait table"),
                         (0x19da0,0x70,"Countdown timer"),
                         (0x1aa64,0xf0,"Initialize UI and request four registry bytes"),
                         (0x1ab54,0x300,"Keypad and comparison"),
                         (0x1ae54,0xc8,"Factory startup wait"),
                         (0x1b2dc,0x78,"Single-instance mutex"),
                         (0x1b574,0x18c,"Destroy persists counter and notifies MICOM"),
                         (0x1b758,0xe4,"Launch argument and message loop"),
                         (0x25a58,36,"Nine-entry wait table in seconds")]:
        raw = pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase,size)
        if len(raw) != size:
            raise ValueError("Incomplete source range")
        evidence.append(dict(start_va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    waits = struct.unpack("<9I",pe.get_data(0x25a58-pe.OPTIONAL_HEADER.ImageBase,36))
    result = dict(scope="Static UI, attempt counter and IPC; no actual unit code read or validation", source_sha256=source_hash,
                  evidence=evidence, factory_dialog_delay_seconds=waits,
                  micom_delay_seconds_by_count={str(i):micom_delay(i)for i in range(9)},
                  counter_path="/Storage Card2/Antitheft.cfg",counter_format="One signed little-endian DWORD; load clamps 0..8",
                  success_ipc=dict(window="MGRMCM",message="0x8064",wparam="0xb40300",lparam="count == 0"),
                  open_points=["Registry/MICOM code provisioning and changes on the physical unit",
                               "Global GUI widget lifecycle, resource theme and malformed registry behavior"])
    (ROOT/"analysis/firmware/codechecker-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps({k:result[k]for k in ("factory_dialog_delay_seconds","micom_delay_seconds_by_count")},indent=2))
    if args.counter:
        print(json.dumps(decode_counter(args.counter.read_bytes()),indent=2))


if __name__ == "__main__":
    main()
