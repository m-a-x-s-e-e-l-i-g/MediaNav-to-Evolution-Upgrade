"""Preserve MICOM updater bytes and reproduce its first transfer pass offline."""
import hashlib
import json
from pathlib import Path
import pefile
from parse_micom_flash import encode_frame

ROOT = Path(__file__).resolve().parents[1]


def next_block(counter, response=0xab):
    if response in (0x21, 0x22):
        counter -= 1
    source = min((counter+255) & 255, 223)
    tag = source+8 if source < 8 else source
    flags = 4 if source == 223 else 0
    return source, tag, flags, counter+(9 if source == 7 else 1)


def main():
    relative = "extracted/705md/upgrade/Storage Card/System/MicomManager.exe"
    path = ROOT/relative
    source_hash = hashlib.sha256(path.read_bytes()).hexdigest()
    if source_hash != "c56e8e08600cd69a656ec487779d3dbb0cea672ae2c5cb2da685b9217e6f8824":
        raise ValueError("Source changed; manually review the recovered contracts")
    image = (ROOT/"analysis/firmware/micom-image.bin").read_bytes()
    if hashlib.sha256(image).hexdigest() != "4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512":
        raise ValueError("Firmware image changed")
    pe = pefile.PE(str(path))
    evidence = []
    for va, size, role in [(0x1d750, 0x1cc, "OnRequest: retry and block selection"),
                            (0x22cfc, 0x168, "Update entry and normal AA command"),
                            (0x25cac, 0x170, "Receive thread drops second AB byte"),
                            (0x27a98, 0x54, "WndProc 0x402 forwards low wParam byte"),
                            (0x283b0, 0x138, "Four WriteFile calls and additive checksum"),
                            (0x528e8, 0x10, "CMicom vtable, absolute VA, four entries")]:
        raw = pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase, size)
        if len(raw) != size:
            raise ValueError("Incomplete source range")
        evidence.append(dict(start_va=hex(va), size=size, role=role, raw_hex=raw.hex(), sha256=hashlib.sha256(raw).hexdigest()))
    counter = 1
    frames = []
    while True:
        source, tag, flags, following = next_block(counter)
        payload = image[source*1024:(source+1)*1024]
        frame = encode_frame(flags, tag, payload)
        frames.append(dict(sequence=len(frames), counter_before=counter, source_block=source,
                           source_offset=hex(source*1024), tag=tag, flags=flags,
                           counter_after=following, displayed_percent=counter*100//224,
                           payload_sha256=hashlib.sha256(payload).hexdigest(),
                           payload_non_ff_bytes=sum(b != 255 for b in payload),
                           checksum=frame[-1], frame_sha256=hashlib.sha256(frame).hexdigest()))
        counter = following
        if flags == 4:
            break
    sent = {f["source_block"] for f in frames}
    omitted = [dict(source_block=b, source_offset=hex(b*1024),
                    non_ff_bytes=sum(v != 255 for v in image[b*1024:(b+1)*1024]))
               for b in range(256) if b not in sent]
    result = dict(scope="Static first pass through terminal A4 frame; does not imply confirmed MCU completion",
                  source_path=relative, source_sha256=source_hash, evidence=evidence,
                  first_pass_frame_count=len(frames), payload_bytes=len(frames)*1024,
                  wire_bytes=len(frames)*1030, frames=frames, omitted_blocks=omitted,
                  omitted_non_ff_bytes=sum(b["non_ff_bytes"] for b in omitted),
                  following_request=next_block(counter),
                  caveats=["No serial capture or MCU write-address mapping",
                           "OnRequest does not clear update flag at terminal frame",
                           "Receive thread forwards AB marker rather than status byte"])
    (ROOT/"analysis/firmware/micom-update-contracts.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps({k: result[k] for k in ("first_pass_frame_count", "payload_bytes", "wire_bytes", "omitted_non_ff_bytes", "following_request")}, indent=2))


if __name__ == "__main__":
    main()
