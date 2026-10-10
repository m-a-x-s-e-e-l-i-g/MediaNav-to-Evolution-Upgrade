"""Strict offline FDF decoding from the MediaNav filesys.dll reader contract."""
import argparse
import collections
import hashlib
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROOTS = {0: "HKEY_CLASSES_ROOT", 1: "HKEY_CURRENT_USER",
         2: "HKEY_LOCAL_MACHINE", 3: "HKEY_USERS"}
MAGIC = bytes.fromhex("b274831d")


def text_field(raw, label):
    if not raw:
        return ""
    text = raw.decode("utf-16-le", errors="strict")
    if not text.endswith("\0") or "\0" in text[:-1]:
        raise ValueError(f"{label}: expected one trailing UTF-16 NUL")
    return text[:-1]


def decode(raw):
    if len(raw) < 8 or raw[:4] != MAGIC:
        raise ValueError("Invalid FDF header")
    if struct.unpack_from("<I", raw, 4)[0] != len(raw):
        raise ValueError("Declared file size does not match bytes")
    records, offset, current = [], 8, None
    while offset < len(raw):
        if offset + 4 > len(raw):
            raise ValueError(f"Truncated record header at {offset:#x}")
        size, kind = struct.unpack_from("<HH", raw, offset)
        end = offset + 4 + size
        if size >= 0x2202 or end > len(raw):
            raise ValueError(f"Invalid record size at {offset:#x}")
        body = raw[offset + 4:end]
        record = dict(offset=offset, payload_bytes=size, record_type=kind,
                      raw_hex=raw[offset:end].hex())
        if kind == 1:
            if size < 4:
                raise ValueError(f"Short key at {offset:#x}")
            root, reserved, chars, class_chars = struct.unpack_from("4B", body)
            if root not in ROOTS or reserved:
                raise ValueError(f"Unknown root/reserved field at {offset:#x}")
            if size != 4 + 2 * (chars + class_chars):
                raise ValueError(f"Key field lengths differ at {offset:#x}")
            path = text_field(body[4:4 + chars * 2], "key")
            class_name = text_field(body[4 + chars * 2:], "key class")
            current = (ROOTS[root], path)
            record.update(root_id=root, root_handle=hex(0x80000000 + root),
                          root=current[0], path=path, path_chars=chars,
                          class_chars=class_chars, class_name=class_name)
        elif kind == 2:
            if size < 6 or current is None:
                raise ValueError(f"Short/orphan value at {offset:#x}")
            value_type, chars, reserved, data_bytes = struct.unpack_from("<HBBH", body)
            data_start = 6 + chars * 2
            if reserved or size != data_start + data_bytes:
                raise ValueError(f"Value field lengths/reserved differ at {offset:#x}")
            name = text_field(body[6:data_start], "value name")
            data = body[data_start:]
            record.update(root=current[0], path=current[1], stored_name=name,
                          reg_name="" if name.casefold() == "default" else name,
                          value_type=value_type, name_chars=chars,
                          data_bytes=data_bytes, data_hex=data.hex())
            if value_type == 4 and len(data) == 4:
                record["decoded_dword"] = struct.unpack("<I", data)[0]
            elif value_type == 1:
                try:
                    record["decoded_string"] = text_field(data, "REG_SZ")
                except (ValueError, UnicodeDecodeError):
                    record["string_warning"] = "Noncanonical UTF-16 REG_SZ; raw bytes retained"
        else:
            raise ValueError(f"Unknown record type {kind} at {offset:#x}")
        records.append(record)
        offset = end
    # Prove the full framing consumes every original byte, including the header.
    rebuilt = MAGIC + struct.pack("<I", len(raw)) + b"".join(
        bytes.fromhex(record["raw_hex"]) for record in records)
    if rebuilt != raw:
        raise AssertionError("Byte round-trip failed")
    return records


def escaped(text):
    return text.replace("\\", "\\\\").replace('"', '\\"')


def reg_text(records):
    lines = ["Windows Registry Editor Version 5.00", "",
             "; Offline research export of firmware defaults; not a live unit registry.", ""]
    for record in records:
        if record["record_type"] == 1:
            suffix = "\\" + record["path"] if record["path"] else ""
            lines.extend(["", f'[{record["root"]}{suffix}]'])
        else:
            name = "@" if not record["reg_name"] else '"' + escaped(record["reg_name"]) + '"'
            data = bytes.fromhex(record["data_hex"])
            if "decoded_dword" in record:
                value = f'dword:{record["decoded_dword"]:08x}'
            elif "decoded_string" in record and not any(c in record["decoded_string"] for c in "\r\n"):
                value = '"' + escaped(record["decoded_string"]) + '"'
            else:
                prefix = "hex:" if record["value_type"] == 3 else f'hex({record["value_type"]:x}):'
                value = prefix + ",".join(f"{byte:02x}" for byte in data)
            lines.append(name + "=" + value)
    return "\r\n".join(lines) + "\r\n"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", type=Path, default=ROOT / "extracted/705md-rom/Registry/default.fdf")
    parser.add_argument("--out", type=Path, default=ROOT / "analysis/firmware/boot-registry")
    args = parser.parse_args()
    raw = args.input.read_bytes()
    records = decode(raw)
    summary = dict(source=str(args.input.resolve()), source_sha256=hashlib.sha256(raw).hexdigest(),
                   source_bytes=len(raw), records=len(records),
                   keys_by_root=dict(collections.Counter(r["root"] for r in records if r["record_type"] == 1)),
                   values_by_root=dict(collections.Counter(r["root"] for r in records if r["record_type"] == 2)),
                   value_types=dict(collections.Counter(r["value_type"] for r in records if r["record_type"] == 2)),
                   byte_round_trip=True, interpretation="Firmware defaults; original root IDs mapped by filesys.dll 0xc0112024 reader; no live registry claim")
    args.out.mkdir(parents=True, exist_ok=True)
    (args.out / "records.json").write_text(json.dumps(dict(summary=summary, records=records), ensure_ascii=False, indent=2), encoding="utf-8")
    # Explicit encoding avoids Windows text-mode translating CRLF into CRCRLF.
    (args.out / "default.validated.reg").write_bytes(b"\xff\xfe" + reg_text(records).encode("utf-16le"))
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()
