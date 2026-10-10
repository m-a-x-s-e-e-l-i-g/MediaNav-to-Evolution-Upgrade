"""Preserve EAP/plugin contracts and check pure Python models; never execute firmware."""
import hashlib
import json
import re
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
SOURCES = {"eap.dll":"89fb0a5396b9063ce548434207b763c24fa4f11640367167b50777842ae87e20",
           "eapchap.dll":"01173e78734f818078914c152286716fdd3d46be38725ed87f52a825242a9a98"}
FUNCTIONS = {
    "eap.dll":[0xc05d17f0,0xc05d19ac,0xc05d2098,0xc05d210c,0xc05d22dc,
        0xc05d2384,0xc05d242c,0xc05d24c0,0xc05d29c4,0xc05d2c84,0xc05d2e20,
        0xc05d2e80,0xc05d2fe8,0xc05d3070,0xc05d32c8,0xc05d3370,0xc05d34e0,
        0xc05d36e0,0xc05d3748,0xc05d3c84,0xc05d3d28,0xc05d3f24,0xc05d411c,
        0xc05d42d8,0xc05d4508,0xc05d45d0,0xc05d478c,0xc05d4824],
    "eapchap.dll":[0xc05e15dc,0xc05e1668,0xc05e1714,0xc05e17d0,0xc05e1818,
        0xc05e199c,0xc05e1c5c,0xc05e2038,0xc05e2090,0xc05e2104,0xc05e2148,
        0xc05e2270,0xc05e28bc,0xc05e2a74,0xc05e2fe8,0xc05e3394],
}


def parse_eap(data):
    if len(data) < 4: return None
    code = data[0]; length = int.from_bytes(data[2:4],"big")
    if length < 4 or length > len(data) or code not in (1,2,3,4): return None
    if code in (3,4): return dict(code=code,length=length) if length==4 else None
    if length==4: return None
    kind = data[4]; body = data[5:length]
    if kind==3 and (code==1 or len(body)!=1 or body[0]<4): return None
    return dict(code=code,length=length,type=kind,body=body.hex())


def obscure(data,key):
    """Original reversal followed by signed-byte comparison and low-byte XOR."""
    out = bytearray(data)
    end = out.index(0) if 0 in out else len(out)
    out[:end] = out[:end][::-1]
    for i in range(end):
        signed = out[i] if out[i]<128 else out[i]-256
        if signed != key: out[i] = (signed ^ key)&255
    return bytes(out)


def main():
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources = []
    for name,digest in SOURCES.items():
        m = next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        path = ROOT/m["path"]; assert hashlib.sha256(path.read_bytes()).hexdigest()==digest
        pe = pefile.PE(str(path)); base = pe.OPTIONAL_HEADER.ImageBase
        fs = json.loads((ROOT/"analysis/functions/rom"/(name+".json")).read_text(encoding="utf-8"))["functions"]
        index = {int(f["begin_va"],16):f for f in fs}
        ranges = [(va,int(index[va]["end_va"],16)-va,"Original .pdata function") for va in FUNCTIONS[name]]
        if name=="eap.dll": ranges.append((0xc05d4364,0x104,"Packet-parser leaf, excluding import thunks"))
        if name=="eapchap.dll": ranges.append((0xc05e3678,0x30,"MSV2 outer-success state leaf"))
        evidence = []
        for va,size,role in ranges:
            raw = pe.get_data(va-base,size); assert len(raw)==size
            evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        sources.append(dict(name=name,sha256=digest,evidence=evidence))
    registry = (ROOT/"analysis/firmware/boot-registry/default.validated.reg").read_text(encoding="utf-16")
    selected = [b for b in re.split(r"(?=\[HKEY)",registry) if "Comm\\EAP\\Extension\\" in b]
    assert len(selected)==2 and all('"Path"="eapchap.dll"' in b for b in selected)
    assert any("Extension\\26]" in b for b in selected) and any("Extension\\4]" in b for b in selected)
    packet_count = 0; accepted = 0
    for code in range(6):
        for actual in range(16):
            for declared in range(16):
                for kind in (1,2,3,4,26):
                    data = (bytes([code,42])+declared.to_bytes(2,"big")+bytes([kind,26])+b"x"*16)[:actual]
                    parsed = parse_eap(data)
                    valid_header = 4<=declared<=actual and code in (1,2,3,4)
                    expected = valid_header and ((code>=3 and declared==4) or
                        (code<3 and declared>=5 and (kind!=3 or (code==2 and declared==6))))
                    assert (parsed is not None)==expected
                    packet_count += 1; accepted += parsed is not None
    notification_buffer = bytes.fromhex("022a000402")
    assert parse_eap(notification_buffer[:4]) is None
    assert parse_eap(notification_buffer) is None
    assert parse_eap(bytes.fromhex("022a000502")) is not None
    failures = []; obfuscation_count = 0
    for key in range(1,251):
        for byte in range(1,256):
            original = bytes([byte,0]); encoded = obscure(original,key)
            decoded = obscure(encoded,key)
            if decoded!=original: failures.append(dict(key=key,input_byte=byte,encoded=encoded.hex(),decoded=decoded.hex()))
            obfuscation_count += 1
    assert len(failures)==123
    assert all(f["key"]==f["input_byte"] and f["key"]>=128 for f in failures)
    md5_models = []
    for capacity in (16,17,20,21,64):
        identity = b"user"; secret = b"password"; challenge = b"challenge"; identifier = 42
        if capacity<17:
            md5_models.append(dict(capacity=capacity,error=8)); continue
        digest = hashlib.md5(bytes([identifier])+secret+challenge).digest()
        name = identity if capacity-17>=len(identity) else b""
        body = b"\x10"+digest+name
        wire = bytes([2,identifier])+(len(body)+5).to_bytes(2,"big")+b"\x04"+body
        assert parse_eap(wire) is not None and len(body)<=capacity
        md5_models.append(dict(capacity=capacity,payload_bytes=len(body),identity_included=bool(name),wire=wire.hex()))
    inner = []
    for actual in (4,5,21):
        for declared in (0,1,2,3,4,5,21,22):
            gate = actual>=4 and declared<=actual
            body = (declared-4)&65535
            inner.append(dict(actual=actual,declared=declared,header_gate=gate,derived_body_bytes=body,
                derived_length_exceeds_available=gate and body>actual-4))
    assert sum(x["derived_length_exceeds_available"] for x in inner)==12
    key_models = []
    for actual in (8,9,24,25):
        for length in (0,16,17,255):
            accepted_key = actual>8 and length+9<=actual
            key_models.append(dict(attribute_bytes=actual,key_length_byte=length,source_bounded=accepted_key,
                                   caller_capacity_checked=False))
    result = dict(binary_execution=False,sources=sources,registry_blocks=selected,
        plugin_types={"4":"MD5-Challenge","26":"MSV2-Challenge"},
        session=dict(base_bytes=336,default_timer_ms=5000,default_retransmit_limit=10),
        packet_models=dict(cases=packet_count,accepted=accepted),
        notification_model=dict(buffer=notification_buffer.hex(),declared_length=4,parsed=False,corrected_example="022a000502"),
        password_obfuscation=dict(cases=obfuscation_count,failed_single_byte_roundtrips=failures),
        md5_response_models=md5_models,msv2_inner_length_models=inner,mppe_attribute_models=key_models,
        static_observations=["Notification response declares/sends 4 bytes although it writes a fifth Type byte",
            "MSV2 inner lengths below 4 wrap to a large body length before challenge parsing",
            "Password conversion checks destination pointer rather than API return value",
            "Reversal/XOR obfuscation loses a non-ASCII byte equal to a key in 128..250",
            "MPPE extraction validates source length but has no output-capacity check"],
        open_questions=["Full MSV2 crypto, password-change, MPPE key derivation", "Complete interactive UI/event/lifetime behavior",
            "Registry utility exports and error/cleanup paths", "Caller capacity guarantees and physical unit behavior"])
    (ROOT/"analysis/firmware/eap-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(f"Verified {len(sources)} sources, {sum(len(s['evidence']) for s in sources)} byte ranges, {packet_count} packet cases, {obfuscation_count} signed-byte roundtrips, {len(inner)} inner-length cases")


if __name__=="__main__": main()
