"""Preserve original PPP/Unimodem/AsyncMac bytes; exercise offline framing models."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
SOURCES = {
    "ppp.dll": "b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5",
    "unimodem.dll": "449c155df69cef56e7588e7d5b2edcba40b55f4ccf943d0ad76f1148a7fd9e6b",
    "asyncmac.dll": "fd946d5a3a1d60f4bef958333c49eae0ed6cd6f2515e87dd03461d86aa3fbe8b",
}
FUNCTIONS = {
    "ppp.dll": [0xc0433b14,0xc0433764,0xc043422c,0xc0439fb8,0xc0443e08,
        0xc0445bd0,0xc044603c,0xc0446860,0xc044721c,0xc04474e8,0xc044764c,
        0xc04476cc,0xc0447ab8,0xc0447b8c,0xc0447c6c,0xc0447cf8,0xc0448c34],
    "unimodem.dll": [0xc0693a04,0xc06952d8,0xc0695998,
        0xc0695a60,0xc0695c18,0xc0698848],
    "asyncmac.dll": [0xc0461330,0xc0461af0,0xc0461d54,0xc04620f4,
        0xc04622d8,0xc04623d8,0xc0462ce8,0xc0462e00,0xc0462fd4,
        0xc0463308,0xc046345c,0xc0463584,0xc0463814,0xc04638c4],
}


def crc_bitwise(data, initial=0xffff):
    crc = initial
    for byte in data:
        crc ^= byte
        for _ in range(8):
            crc = (crc >> 1) ^ (0x8408 if crc & 1 else 0)
    return crc


def encode_ppp(data, accm):
    checked = data + struct.pack("<H", crc_bitwise(data) ^ 0xffff)
    out = bytearray([0x7e])
    for byte in checked:
        if byte in (0x7d,0x7e) or (byte < 32 and accm & (1 << byte)):
            out.extend((0x7d,byte ^ 0x20))
        else:
            out.append(byte)
    return bytes(out + b"\x7e")


def encode_slip(data):
    return b"\xc0" + data.replace(b"\xdb",b"\xdb\xdd").replace(b"\xc0",b"\xdb\xdc") + b"\xc0"


class Receiver:
    """Model exactly the observed flag/escape/discard checks, including malformed input."""
    def __init__(self, ppp=True, capacity=1556):
        self.ppp = ppp
        self.capacity = capacity
        self.data = bytearray()
        self.escape = False
        self.discard = True
        self.frames = []
        self.bad_crc = self.oversize = 0

    def feed(self, chunk):
        flag, escape = (0x7e,0x7d) if self.ppp else (0xc0,0xdb)
        for byte in chunk:
            if byte == flag:
                if self.data and not self.discard:
                    data = bytes(self.data)
                    if not self.ppp:
                        self.frames.append(data)
                    elif len(data) >= 3:
                        if crc_bitwise(data[:-2]) == (int.from_bytes(data[-2:],"little") ^ 0xffff):
                            self.frames.append(data[:-2])
                        else:
                            self.bad_crc += 1
                self.data.clear()
                self.escape = False
                self.discard = False
            elif byte == escape:
                self.escape = True
            elif len(self.data) < self.capacity:
                if self.escape:
                    byte = (byte ^ 0x20) if self.ppp else {0xdd:0xdb,0xdc:0xc0}.get(byte,byte)
                    self.escape = False
                self.data.append(byte)
            elif not self.discard:
                self.discard = True
                self.oversize += 1


def main():
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources = []; pes = {}
    for name,digest in SOURCES.items():
        module = next(m for m in modules if m["origin"] == "rom" and m["name"] == name)
        path = ROOT/module["path"]
        assert hashlib.sha256(path.read_bytes()).hexdigest() == digest
        pe = pefile.PE(str(path)); pes[name] = pe
        index = json.loads((ROOT/"analysis/functions/rom"/(name+".json")).read_text(encoding="utf-8"))
        functions = {int(f["begin_va"],16):f for f in index["functions"]}
        ranges = [(va,int(functions[va]["end_va"],16)-va,"Original .pdata function") for va in FUNCTIONS[name]]
        if name == "asyncmac.dll":
            ranges += [(0xc04633e4,0x78,"SLIP encoder leaf"),
                       (0xc0463c04,0x48,"CRC leaf; original v0 return"),
                       (0xc0465240,512,"All 256 original CRC16 table entries")]
        if name == "unimodem.dll":
            ranges += [(0xc0693fa8,0x1cc,"Leaf TSPI procedure-table initializer"),
                       (0xc06958d4,0xc4,"Leaf DCB field setup")]
        evidence = []
        for va,size,role in ranges:
            raw = pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase,size)
            assert len(raw) == size
            evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        sources.append(dict(name=name,sha256=digest,evidence=evidence))
    pe = pes["asyncmac.dll"]
    table = struct.unpack("<256H",pe.get_data(0xc0465240-pe.OPTIONAL_HEADER.ImageBase,512))
    assert tuple(crc_bitwise(bytes([i]),0) for i in range(256)) == table
    def crc_table(data):
        crc = 0xffff
        for byte in data:
            crc = table[(crc ^ byte)&255] ^ (crc >> 8)
        return crc
    assert crc_bitwise(b"123456789") == 0x6f91
    framing = []
    payloads = [b"\x21",b"123456789",bytes(range(256)),b"\x7d\x7e\x00\x11\x13",b"\x7e"*1502]
    split_checks = 0
    for payload in payloads:
        assert crc_table(payload) == crc_bitwise(payload)
        assert crc_table(payload+struct.pack("<H",crc_table(payload)^0xffff)) == 0xf0b8
        for accm in (0,0x000a0000,0xffffffff):
            wire = encode_ppp(payload,accm)
            # Every boundary includes splitting directly after the escape byte.
            for split in range(len(wire)+1):
                rx = Receiver(); rx.feed(wire[:split]); rx.feed(wire[split:])
                assert rx.frames == [payload]; split_checks += 1
            rx = Receiver()
            for byte in wire: rx.feed(bytes([byte]))
            assert rx.frames == [payload]
            framing.append(dict(payload_bytes=len(payload),accm=hex(accm),wire_bytes=len(wire),wire_sha256=hashlib.sha256(wire).hexdigest()))
    slip = encode_slip(bytes(range(256)))
    rx = Receiver(ppp=False)
    for byte in slip: rx.feed(bytes([byte]))
    assert rx.frames == [bytes(range(256))]
    good = encode_ppp(b"example",0)
    malformed = good[:-1]+b"\x7d\x7e"
    rx = Receiver(); rx.feed(malformed)
    assert rx.frames == [b"example"]  # Flag path does not test pending escape.
    bad = bytearray(good); bad[1] ^= 1
    rx = Receiver(); rx.feed(bad)
    assert rx.frames == [] and rx.bad_crc == 1
    rx = Receiver(capacity=4); rx.feed(encode_ppp(b"too long",0)+encode_ppp(b"x",0))
    assert rx.frames == [b"x"] and rx.oversize == 1
    buffers = []
    for frame in (1,64,1502,4096):
        header = (frame+4)&~3; tail = 5
        stride = (((frame*9+7)>>3)+header+tail+12)&~3
        max_wire = 2*(frame+2)+2
        assert max_wire <= stride
        # Input begins header bytes into the same allocation: two output bytes per input.
        assert all(1+2*(i+1) <= header+i+1 for i in range(frame-1))
        buffers.append(dict(max_frame=frame,header=header,tail=tail,stride=stride,max_encoded=max_wire,
                            pool_bytes=(stride+56)*17))
    registry = (ROOT/"analysis/firmware/boot-registry/default.validated.reg").read_text(encoding="utf-16")
    selected = [b for b in registry.split("\n\n") if "HKEY_LOCAL_MACHINE\\Comm\\AsyncMac" in b]
    result = dict(binary_execution=False,sources=sources,crc=dict(table_va="0xc0465240",entries=list(table),
        reflected_polynomial="0x8408",initial="0xffff",final_xor="0xffff",fcs_order="little endian",good_residue="0xf0b8"),
        framing_models=framing,split_boundary_checks=split_checks,slip_model=dict(payload_bytes=256,wire_bytes=len(slip)),
        buffer_models=buffers,registry_blocks=selected,
        malformed_models=[dict(case="escape immediately before closing flag",accepted=True),
            dict(case="one payload bit altered",bad_crc=1),dict(case="oversize then valid frame",oversize=1,recovered=True)],
        open_questions=["Actual TAPI registration timing and FriendlyName-to-device mapping on the physical unit",
            "Complete PPP LCP/IPCP/authentication state machines and negotiated link flags/ACCM",
            "All WAN OID payload schemas and error/lifetime paths","Runtime failures and persisted configuration"])
    destination = ROOT/"analysis/firmware/ppp-transport-contracts.json"
    destination.write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(f"Verified {len(sources)} source hashes, {sum(len(s['evidence']) for s in sources)} byte ranges, 256 CRC entries, {split_checks} split boundaries, {len(buffers)} buffer models")


if __name__ == "__main__":
    main()
