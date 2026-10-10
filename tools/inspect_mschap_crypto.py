"""Inspect original crypto call contracts and offline models, never run firmware."""
import hashlib
import json
import struct
import sys
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools/vendor/crypto-models"))
from Crypto.Hash import MD4
from Crypto.Cipher import DES, ARC4

SOURCES = {
    "eapchap.dll": "01173e78734f818078914c152286716fdd3d46be38725ed87f52a825242a9a98",
    "ppp.dll": "b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5",
    "rsaenh.dll": "f5877e9ec8b0771cf2d4f795ac19dcbabddd58146cf6ee751e1264cf05ab4e7e",
}
FUNCTIONS = {
    "eapchap.dll": [0xc05e23e0,0xc05e2484,0xc05e24f8,0xc05e25bc,
                    0xc05e2bd8,0xc05e2d6c,0xc05e3080,0xc05e321c],
    "ppp.dll": [0xc043e8ec,0xc043e960,0xc043e9a4,0xc043e9c4,0xc043ea38,
                0xc043eafc,0xc043edd4,0xc043fc60,0xc043fea4,0xc0440000,0xc04400a4,0xc0440138],
    "rsaenh.dll": [0x1001acf0,0x1001adfc,0x1001cbf8,0x1001d41c],
}
CONSTANTS = {
    "auth_magic1": (0xc05e50d4, b"Magic server to client signing constant"),
    "auth_magic2": (0xc05e50fc, b"Pad to make it do more than one iteration"),
    "mppe_magic1": (0xc05e5150, b"This is the MPPE Master Key"),
    "mppe_magic2": (0xc05e516c, b"On the client side, this is the send key; on the server side, it is the receive key."),
    "mppe_magic3": (0xc05e51c0, b"On the client side, this is the receive key; on the server side, it is the send key."),
    "sha_pad2": (0xc05e5128, b"\xf2"*40),
    "sha_pad1": (0xc05e5238, b"\0"*40),
}
IV = (0x67452301,0xefcdab89,0x98badcfe,0x10325476)


def rotate(value, bits):
    value &= 0xffffffff
    return ((value << bits) | (value >> (32-bits))) & 0xffffffff


def md4_block(state, block):
    """Standard MD4 compression; compare padded messages against independent MD4."""
    words = struct.unpack("<16I", block)
    a,b,c,d = state
    for round_id in range(3):
        order = list(range(16)) if round_id==0 else (
            [0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15] if round_id==1 else
            [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15])
        shifts = ((3,7,11,19),(3,5,9,13),(3,9,11,15))[round_id]
        constant = (0,0x5a827999,0x6ed9eba1)[round_id]
        for i,k in enumerate(order):
            f = ((b & c) | (~b & d)) if round_id==0 else (
                ((b & c) | (b & d) | (c & d)) if round_id==1 else b ^ c ^ d)
            a = rotate(a + f + words[k] + constant, shifts[i%4])
            a,b,c,d = d,a,b,c
    return tuple((x+y)&0xffffffff for x,y in zip(state,(a,b,c,d)))


def full_md4(data):
    padded = data + b"\x80"
    padded += b"\0"*((56-len(padded))%64) + struct.pack("<Q",len(data)*8)
    state = IV
    for i in range(0,len(padded),64): state = md4_block(state,padded[i:i+64])
    return struct.pack("<4I",*state)


def firmware_md4_wrapper(data):
    """MDbegin + one MDupdate(bit_length), then copy state despite return code."""
    if len(data)>64: return struct.pack("<4I",*IV), 1, False
    if len(data)==64: return struct.pack("<4I",*md4_block(IV,data)), 0, False
    return full_md4(data), 0, True


def expand_des_key(key7):
    assert len(key7)==7
    bits = int.from_bytes(key7,"big")
    key = bytearray()
    for i in range(8):
        byte = ((bits >> (49-7*i)) & 0x7f) << 1
        key.append(byte | (1 if byte.bit_count()%2==0 else 0))
    return bytes(key)


def challenge_response(challenge, pw_hash):
    padded = pw_hash + b"\0"*5
    return b"".join(DES.new(expand_des_key(padded[i:i+7]),DES.MODE_ECB).encrypt(challenge)
                    for i in (0,7,14))


def sha(data): return hashlib.sha1(data).digest()


def mppe_new_key(start,current):
    assert len(start)==len(current) and len(start) in (8,16)
    return sha(start+b"\0"*40+current+b"\xf2"*40)[:len(start)]


def rc4_reference(key,data):
    state = list(range(256)); j = 0
    for i in range(256):
        j = (j+state[i]+key[i%len(key)])&255
        state[i],state[j] = state[j],state[i]
    i = j = 0; out = bytearray()
    for byte in data:
        i = (i+1)&255; j = (j+state[i])&255
        state[i],state[j] = state[j],state[i]
        out.append(byte ^ state[(state[i]+state[j])&255])
    return bytes(out)


def main():
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    evidence_sources = []
    for name,digest in SOURCES.items():
        module = next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        path = ROOT/module["path"]
        assert hashlib.sha256(path.read_bytes()).hexdigest()==digest
        pe = pefile.PE(str(path)); base = pe.OPTIONAL_HEADER.ImageBase
        functions = json.loads((ROOT/"analysis/functions/rom"/(name+".json")).read_text(encoding="utf-8"))["functions"]
        index = {int(f["begin_va"],16):f for f in functions}
        ranges = [(va,index[va]["bytes"],"Original .pdata function") for va in FUNCTIONS[name]]
        if name=="rsaenh.dll": ranges += [(0x1001cbb8,64,"MDbegin leaf to next compression function"),
            (0x1001e884,0x68,"Odd-parity helper leaf, excluding following function"),
            (0x1001e990,0x94,"RC4 KSA leaf"),(0x1001ea24,0x6c,"RC4 PRGA leaf")]
        if name=="eapchap.dll": ranges += [(va,len(data),kind) for kind,(va,data) in CONSTANTS.items()]
        if name=="ppp.dll": ranges += [(0xc044d868,40,"PPP SHA zero pad"),(0xc044d780,40,"PPP SHA F2 pad")]
        evidence = []
        for va,size,role in ranges:
            raw = pe.get_data(va-base,size); assert len(raw)==size
            if name=="eapchap.dll" and role in CONSTANTS: assert raw==CONSTANTS[role][1]
            if role=="PPP SHA zero pad": assert raw==b"\0"*40
            if role=="PPP SHA F2 pad": assert raw==b"\xf2"*40
            evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        evidence_sources.append(dict(name=name,path=module["path"],sha256=digest,evidence=evidence))

    md4_comparisons = 0
    for length in range(257):
        data = bytes((i*73+length)%256 for i in range(length))
        assert full_md4(data)==MD4.new(data).digest()
        md4_comparisons += 1
    pw = "clientPass".encode("utf-16le")
    pw_hash,rc,finished = firmware_md4_wrapper(pw)
    assert rc==0 and finished and pw_hash.hex()=="44ebba8d5312b8d611474411f56989ae"
    pw_hash_hash = MD4.new(pw_hash).digest()
    assert pw_hash_hash.hex()=="41c00c584bd2d91c4017a2a12fa59f3f"
    peer = bytes.fromhex("21402324255e262a28295f2b3a337c7e")
    authenticator = bytes.fromhex("5b5d7c7d7b3f2f3e3c2c602132262628")
    challenge = sha(peer+authenticator+b"User")[:8]
    assert challenge.hex()=="d02e4386bce91226"
    response = challenge_response(challenge,pw_hash)
    assert response.hex()=="82309ecd8d708b5ea08faa3981cd83544233114a3d85d6df"
    auth_digest = sha(pw_hash_hash+response+CONSTANTS["auth_magic1"][1])
    auth_response = "S="+sha(auth_digest+challenge+CONSTANTS["auth_magic2"][1]).hex().upper()
    assert auth_response=="S=407A5589115FD0D6209F510FE9C04566932CDA56"
    for raw,expanded in (("fc156af7edcd6c","fd0b5b5e7f6e34d9"),("0edde3337d427f","0e6e796737ea08fe")):
        assert expand_des_key(bytes.fromhex(raw)).hex()==expanded

    master = sha(pw_hash_hash+response+CONSTANTS["mppe_magic1"][1])[:16]
    assert master.hex()=="fdece3717a8c838cb388e527ae3cdd31"
    directions = {kind:sha(master+b"\0"*40+CONSTANTS[kind][1]+b"\xf2"*40)[:16]
                  for kind in ("mppe_magic2","mppe_magic3")}
    server_send = directions["mppe_magic3"]
    assert server_send.hex()=="8b7cdc149b993a1ba118cb153f56dccb"
    session_vectors = []
    for strength,key_hex,cipher_hex in (
        (40,"d1269ec49fa62e3e","929137917e5803d668d75898"),
        (56,"d15c00c49fa62e3e","3f106833fa448da842bc5758"),
        (128,"405cb2247a7956e6e211007ae27b22d4","81848317df68846272fb5abe")):
        start = server_send[:16 if strength==128 else 8]
        session = bytearray(mppe_new_key(start,start))
        if strength==40: session[:3]=bytes.fromhex("d1269e")
        if strength==56: session[0]=0xd1
        assert session.hex()==key_hex
        cipher = ARC4.new(bytes(session)).encrypt(b"test message")
        assert cipher==rc4_reference(bytes(session),b"test message")
        # Preserve the published 56-bit discrepancy instead of silently changing its example.
        if strength==56: assert cipher.hex()=="3f106833fa448da842bc57b8" and cipher.hex()!=cipher_hex
        else: assert cipher.hex()==cipher_hex
        session_vectors.append(dict(strength=strength,start=start.hex(),initial_session=session.hex(),cipher=cipher.hex(),
                                    published_cipher=cipher_hex,cipher_matches_publication=cipher.hex()==cipher_hex))

    boundary = []
    for units in (0,1,27,28,31,32,33,64,128,256):
        data = ("A"*units).encode("utf-16le")
        actual,rc,finished = firmware_md4_wrapper(data)
        expected = MD4.new(data).digest()
        assert (actual==expected)==(units<32)
        boundary.append(dict(utf16_code_units=units,bytes=len(data),provider_return=rc,
                             finalized=finished,firmware_hash=actual.hex(),standard_hash=expected.hex(),matches=actual==expected))
    distinct_long = [firmware_md4_wrapper((v*33).encode("utf-16le"))[0] for v in ("A","B","C")]
    assert len(set(distinct_long))==1
    rolled = mppe_new_key(server_send,server_send)
    rolled = ARC4.new(rolled).encrypt(rolled)
    result = dict(binary_execution=False,sources=evidence_sources,
        references=["https://www.rfc-editor.org/rfc/rfc2759.html","https://www.rfc-editor.org/rfc/rfc3079.html"],
        independent_backend="PyCryptodome 3.23.0 (isolated tools/vendor/crypto-models)",
        checks=dict(md4_independent_comparisons=md4_comparisons,des_parity_vectors=2,
                    password_boundary_cases=len(boundary),rfc_mppe_session_keys_matched=3,
                    rfc_mppe_ciphertexts_matched=2,published_cipher_discrepancies=1,rc4_independent_comparisons=3,
                    preserved_ranges=sum(len(s["evidence"]) for s in evidence_sources)),
        rfc2759=dict(challenge=challenge.hex(),password_hash=pw_hash.hex(),password_hash_hash=pw_hash_hash.hex(),
                     nt_response=response.hex(),authenticator_response=auth_response),
        rfc3079=dict(master=master.hex(),client_send_server_receive=directions["mppe_magic2"].hex(),
                     client_receive_server_send=server_send.hex(),session_vectors=session_vectors),
        eap_plugin_attributes=dict(vendor_id=311,send_subtype=16,receive_subtype=17,
            send_key=server_send.hex(),receive_key=directions["mppe_magic2"].hex(),payload_length=34,
            layout="00 00 10 + key16 + zero15; full vendor attribute length40"),
        password_boundaries=boundary,
        synthetic_first_128bit_rekey=rolled.hex(),
        limits=["Independent calculations plus caller/provider instruction review, no firmware execution",
                "No observed unit credentials, authentication or encryption traffic",
                "Complete CCP key initialization, role dispatch and receive-state recovery remain open"])
    out = ROOT/"analysis/firmware/mschap-crypto-contracts.json"
    out.write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"]),indent=2))


if __name__=="__main__": main()
