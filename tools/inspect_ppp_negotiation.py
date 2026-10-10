"""Extract original PPP protocol/option/auth tables and validate offline packet models."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
DIGEST = "b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5"
FUNCTIONS = [0xc0432eac,0xc04335e0,0xc0436878,0xc0437040,0xc0437394,
    0xc0438c50,0xc0438e5c,0xc04397e8,0xc0439fb8,0xc043a528,0xc043a930,
    0xc043ab5c,0xc043ac90,0xc043aef8,0xc043b030,0xc043b840,0xc043bb08,
    0xc043bc98,0xc043c0b0,0xc043c4f4,0xc043c5d8,0xc043caf8,0xc043cd74,
    0xc043d230,0xc043d2fc,0xc043d3b8,0xc043d7b0,0xc043dc78,0xc043e0b4,
    0xc043e350,0xc043e3b0,0xc043e648,0xc043e764,0xc043f058,
    0xc0446f50,0xc044a470,0xc044a4d4,0xc044a6b8,0xc044a830,0xc044a990,
    0xc044abe8,0xc044acd4,0xc044adc0,0xc044afb0,0xc044b4e8,0xc044b690,
    0xc044b740,0xc044b868,0xc044b8e4,0xc044b984,0xc044bc4c,0xc044be50]


def control_packet(data):
    if len(data) < 4: return None
    length = int.from_bytes(data[2:4],"big")
    if length < 4 or length > len(data): return None
    return dict(code=data[0],identifier=data[1],declared_length=length,body=data[4:length])


def options(data):
    result = []; offset = 0
    while offset < len(data):
        if len(data)-offset < 2: return None
        size = data[offset+1]
        if size < 2 or size > len(data)-offset: return None
        result.append((data[offset],data[offset+2:offset+size]))
        offset += size
    return result


def protocol_header(data):
    offset = 0
    if len(data) > 1 and data[0] == 0xff:
        if data[1] != 3: return None
        offset = 2
    protocol = 0
    while offset < len(data):
        if protocol & 0xff00: return None
        byte = data[offset]; offset += 1
        protocol = ((protocol & 255)<<8) | byte
        if byte & 1: return protocol,offset,data[offset:]
    return None


def auth_mask(flags, eap_available=True, eap_type=1):
    mask = 0x1f
    if flags & 0x400: mask = 0x1e
    if flags & 0x1800: mask &= ~3
    for flag,bit in ((0x40000,0),(0x80000,1),(0x100000,2),(0x200000,3),(0x400000,4)):
        if flags & flag: mask &= ~(1<<bit)
    if not eap_available or not eap_type: mask &= ~16
    return mask


def main():
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"] == "rom" and m["name"] == "ppp.dll")
    path = ROOT/module["path"]
    assert hashlib.sha256(path.read_bytes()).hexdigest() == DIGEST
    pe = pefile.PE(str(path)); base = pe.OPTIONAL_HEADER.ImageBase
    def read(va,size):
        raw = pe.get_data(va-base,size); assert len(raw) == size
        return raw
    def string(va): return read(va,96).split(b"\x00")[0].decode("ascii")
    index = json.loads((ROOT/"analysis/functions/rom/ppp.dll.json").read_text(encoding="utf-8"))
    functions = {int(f["begin_va"],16):f for f in index["functions"]}
    ranges = [(va,int(functions[va]["end_va"],16)-va,"Original .pdata function") for va in FUNCTIONS]
    ranges += [(0xc0433158,0xe8,"Protocol parser leaf"),(0xc0439bb8,8,"Constant-false leaf"),
        (0xc043a8b4,0x7c,"Authentication selector leaf"),(0xc043aae0,0x7c,"Authentication priority leaf"),
        (0xc043ac00,0x90,"Authentication Nak construction leaf"),(0xc044b488,0x30,"Option-engine defaults leaf"),
        (0xc044d50c,48,"Authentication table including zero terminator")]
    descriptor_locations = {"LCP":0xc044d4c4,"IPCP":0xc044d2a4,"IPV6CP":0xc044d404,"CCP":0xc044d6fc}
    descriptors = []
    for name,va in descriptor_locations.items():
        values = struct.unpack("<11I",read(va,44)); ranges.append((va,44,name+" FSM descriptor"))
        descriptors.append(dict(name=name,va=hex(va),protocol=hex(values[1]),request_buffer_bytes=values[2],
            raw_words=[hex(v) for v in values],callbacks=[hex(v) for v in values[3:10]]))
    groups = {"LCP":[0xc044d53c+32*i for i in range(6)],
              "IPCP":[0xc044d344+32*i for i in range(6)],"IPV6CP":[0xc044d468]}
    records = []
    for group,locations in groups.items():
        for va in locations:
            raw = read(va,32); words = struct.unpack("<8I",raw)
            name = string(words[1]); length = raw[1]
            records.append(dict(group=group,va=hex(va),id=raw[0],payload_bytes=None if length==255 else length,
                name=name,raw_words=[hex(w) for w in words],callbacks=[hex(w) for w in words[2:]]))
            ranges.append((va,32,name+" option descriptor"))
    assert [(r["id"],r["payload_bytes"]) for r in records if r["group"]=="LCP"] == [(1,2),(2,4),(3,None),(5,4),(7,0),(8,0)]
    assert [r["id"] for r in records if r["group"]=="IPCP"] == [2,3,129,130,131,132]
    auth = []
    for i in range(5):
        pointer,protocol,algorithm,pad = struct.unpack("<IHBB",read(0xc044d50c+8*i,8))
        auth.append(dict(index=i,name=string(pointer),protocol=hex(protocol),algorithm=algorithm,padding=pad))
    assert [(int(a["protocol"],16),a["algorithm"]) for a in auth] == [(0xc023,0),(0xc223,5),(0xc223,128),(0xc223,129),(0xc227,0)]
    for va in (0xc044d63c,0xc044d654,0xc044d6c0): ranges.append((va,24,"CHAP algorithm callback record"))
    evidence = []
    for va,size,role in ranges:
        raw = read(va,size)
        evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    packet_models = []
    for actual in range(12):
        for declared in range(12):
            data = (bytes([1,42])+declared.to_bytes(2,"big")+b"x"*12)[:actual]
            parsed = control_packet(data)
            assert (parsed is not None) == (4 <= declared <= actual)
            packet_models.append(dict(actual=actual,declared=declared,accepted=parsed is not None))
    tlv_models = []
    for length in range(256):
        for actual in (0,1,2,6,255,256):
            data = (bytes([1,length])+b"x"*256)[:actual]
            parsed = options(data)
            # After the first option, each x/x pair denotes a 120-byte option.
            expected = actual == 0 or (length >= 2 and actual >= length and (actual-length)%120 == 0)
            assert (parsed is not None) == expected
            tlv_models.append(dict(actual=actual,option_length=length,accepted=parsed is not None))
    request = bytes.fromhex("012a000a010405dc0702")
    ack_models = []
    for received in (b"\x02"+request[1:],b"\x02\x2b"+request[2:],b"\x02"+request[1:-1]+b"\x03",b"\x02"+request[1:]+b"padding"):
        parsed = control_packet(received)
        matches = parsed is not None and parsed["declared_length"]==len(request) and received[1:len(request)]==request[1:]
        ack_models.append(dict(received=received.hex(),matches_outstanding_request=matches))
    assert [m["matches_outstanding_request"] for m in ack_models] == [True,False,False,True]
    prefixes = []
    for wire,expected in (("ff030021010203",0x21),("21010203",0x21),("c021010203",0xc021),
                          ("ff040021",None),("c020",None),("000021010203",0x21)):
        parsed = protocol_header(bytes.fromhex(wire))
        assert (parsed[0] if parsed else None) == expected
        prefixes.append(dict(wire=wire,protocol=hex(expected) if expected else None,consumed=parsed[1] if parsed else None))
    policy_models = []
    for flags in (0,0x208,0x400,0x800,0x1800,0x7c0000):
        for available in (False,True):
            mask = auth_mask(flags,available)
            priority = next((a["name"] for a in reversed(auth) if mask & (1<<a["index"])),None)
            policy_models.append(dict(flags=hex(flags),eap_available=available,mask=hex(mask),first_choice=priority))
    # Synthetic public values only; independent MD5 library checks raw-call input ordering.
    chap = []
    for identifier,secret,challenge in ((0,b"secret",bytes(range(16))),(42,b"password",b"challenge")):
        digest = hashlib.md5(bytes([identifier])+secret+challenge).hexdigest()
        chap.append(dict(identifier=identifier,secret_ascii=secret.decode(),challenge=challenge.hex(),response=digest))
    result = dict(binary_execution=False,source_sha256=DIGEST,evidence=evidence,protocol_descriptors=descriptors,
        options=records,authentication=auth,default_fsm=dict(restart_ms=3000,max_configure=10,max_terminate=2,max_failure=5),
        control_packet_models=packet_models,tlv_models=tlv_models,configure_ack_models=ack_models,
        protocol_prefix_models=prefixes,auth_policy_models=policy_models,chap_md5_models=chap,
        open_questions=["Complete side-effectful FSM transitions under concurrency", "Every option handler and retry/default constraint",
            "MS-CHAP crypto and MPPE/CCP", "Full external eap.dll implementation", "Actual peer and persisted RAS entry"])
    (ROOT/"analysis/firmware/ppp-negotiation-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(f"Verified source, {len(evidence)} byte ranges, {len(records)} option records, 5 auth records, {len(packet_models)} packet lengths, {len(tlv_models)} TLV cases, 4 ACK and 6 prefix models")


if __name__ == "__main__": main()
