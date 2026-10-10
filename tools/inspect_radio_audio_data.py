"""Decode locally verified station records and package radio/audio transfer blocks."""
import hashlib
import json
import struct
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def sha(data):
    return hashlib.sha256(data).hexdigest()


def station_records(data):
    if len(data) % 10:
        raise ValueError("Station list must contain complete 10-byte records")
    entries = []
    ids = defaultdict(list)
    for offset in range(0, len(data), 10):
        station_id = struct.unpack_from("<H", data, offset)[0]
        raw = data[offset + 2:offset + 10]
        record = dict(offset=offset, station_id=station_id, station_id_hex=f"0x{station_id:04x}",
                      name_bytes_hex=raw.hex(), name_ascii_preview=raw.decode("ascii", errors="backslashreplace"))
        entries.append(record)
        ids[station_id].append(record)
    return dict(schema="MediaNav-7.0.5.MD-station-list-v1", byte_count=len(data), sha256=sha(data),
                record_size=10, record_count=len(entries), unique_id_count=len(ids),
                charset="Unresolved; ASCII preview is not a full RDS character conversion",
                lookup="First matching little-endian 16-bit ID; copy exactly 8 name bytes",
                duplicate_ids={f"0x{k:04x}": v for k, v in ids.items() if len(v) > 1}, entries=entries)


def arkamys_bytes(data):
    if len(data) == 0x395:
        return data, "raw"
    if len(data) == 0x72a:
        text = data.decode("ascii")
        if any(ch not in "0123456789abcdefABCDEF" for ch in text):
            raise ValueError("Expected contiguous ASCII hex pairs")
        return bytes.fromhex(text), "ascii-hex"
    raise ValueError("Expected 917 raw bytes or 1834 ASCII hex characters")


def transfer_blocks(data, manager, first_address):
    if len(data) != 1024:
        raise ValueError("Expected exactly 1024 transfer bytes")
    return [dict(index=i, manager=manager, address=first_address + i,
                 address_hex=hex(first_address + i), data_length=128,
                 payload_length=132, sha256=sha(data[i * 128:(i + 1) * 128]),
                 data_hex=data[i * 128:(i + 1) * 128].hex()) for i in range(8)]


def main():
    system = ROOT / "extracted/705md/upgrade/Storage Card/System"
    output = ROOT / "analysis/firmware"
    output.mkdir(parents=True, exist_ok=True)
    stations = station_records((system / "psnlist.dbf").read_bytes())
    (output / "radio-station-names.json").write_text(json.dumps(stations, ensure_ascii=False, indent=2), encoding="utf-8")
    arkamys_source = (system / "arkamys_default.dat").read_bytes()
    arkamys, encoding = arkamys_bytes(arkamys_source)
    radio = (system / "radparam.bin").read_bytes()
    padded = arkamys.ljust(1024, bytes([0]))
    report = dict(scope="Offline package decoding and static transfer layout; coefficient meanings unresolved",
                  write_protocol=dict(type=6, command="data length", address="32-bit little-endian logical field"),
                  arkamys=dict(source_sha256=sha(arkamys_source), encoding=encoding,
                               decoded_length=len(arkamys), decoded_sha256=sha(arkamys),
                               zero_padding=1024-len(arkamys), blocks=transfer_blocks(padded, 15, 0x21)),
                  radio=dict(source_length=len(radio), source_sha256=sha(radio),
                             blocks=transfer_blocks(radio, 3, 0xe0)))
    old = ROOT / "extracted/remove-md/upgrade/Storage Card/System"
    report["downgrade_comparison"] = {
        name: dict(present=(old/name).exists(), byte_identical=(old/name).read_bytes() == (system/name).read_bytes()
                   if (old/name).exists() else None)
        for name in ("arkamys_default.dat", "radparam.bin", "psnlist.dbf")}
    (output / "radio-audio-blocks.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(dict(station_records=stations["record_count"], unique_ids=stations["unique_id_count"],
                          duplicates=stations["duplicate_ids"], arkamys_decoded=len(arkamys),
                          padding=1024-len(arkamys), comparison=report["downgrade_comparison"]), ensure_ascii=False))


if __name__ == "__main__":
    main()
