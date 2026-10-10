"""Preserve CCP handlers and model negotiation, counters and stateful MPPE offline."""
import hashlib
import json
import struct
from pathlib import Path
from inspect_mschap_crypto import ARC4, mppe_new_key

ROOT = Path(__file__).resolve().parents[1]
HASH = "b5f6bd4f0d8295e9203b3f92bd23a2920ecc086804f76caadb2e18d9e6d05df5"
FUNCTIONS = [0xc043b678,0xc043ef34,0xc043eff0,0xc043f058,0xc043f190,0xc043f1f8,
    0xc043f2f4,0xc043f318,0xc043f364,0xc043f5b0,0xc043f7b8,0xc043fbd8,
    0xc043fc60,0xc043fde4,0xc043fea4,0xc0440000,0xc04400a4,0xc0440138,
    0xc04402d8,0xc0440360,0xc0440440,0xc04405c0]
LEAVES = [(0xc043f900,0x54,"Initialize local supported proposal"),
          (0xc043f954,0x54,"Serialize local four-byte option"),
          (0xc043f9a8,0x54,"Configure-Ack handler"),
          (0xc043f9fc,0xa4,"Configure-Nak handler"),
          (0xc043faa0,0x138,"Peer Configure-Request handler")]


def peer_request(offered,entry,supported):
    proposed = (offered & 1) if entry&0x200 else 0
    proposed |= supported & offered
    if proposed&0x60==0x60: proposed &= ~0x20
    if entry&0x1800==0x1800 and proposed&0x60==0: proposed |= supported
    return dict(code=2 if offered==proposed else 3,proposal=proposed,
                payload=proposed.to_bytes(4,"big").hex())


def rx_gate(expected,waiting,header,encrypted_options=True,compression=False):
    count = header&0xfff
    if header&0x8000:
        if encrypted_options and ((header-expected)&0xfff)>=0xf00:
            return dict(action="drop_stale_flush",expected=expected,waiting=waiting)
        expected = count; waiting = False
    if waiting or expected!=count:
        return dict(action="reset_request",expected=expected,waiting=True)
    expected = (expected+1)&0xfff
    if header&0x2000 and not compression:
        return dict(action="drop_unnegotiated_compression",expected=expected,waiting=False)
    return dict(action="route",expected=expected,waiting=False,
                decrypt=bool(header&0x1000 and encrypted_options))


class Cipher:
    def __init__(self,start,strength):
        self.strength = strength; self.start = start[:8 if strength==40 else 16]
        self.current = bytearray(mppe_new_key(self.start,self.start))
        if strength==40: self.current[:3]=bytes.fromhex("d1269e")
        self.reset(); self.updates = 0

    def reset(self): self.rc4 = ARC4.new(bytes(self.current))

    def update(self):
        next_key = mppe_new_key(self.start,bytes(self.current))
        self.current = bytearray(ARC4.new(next_key).encrypt(next_key))
        if self.strength==40: self.current[:3]=bytes.fromhex("d1269e")
        self.updates += 1; self.reset()


def transport_check(start,strength,packet_count,drop_at=None):
    tx = Cipher(start,strength); rx = Cipher(start,strength)
    expected = 0; waiting = False; rx_key_epoch = 0; need_flush = True
    delivered = resets = 0
    for sequence in range(packet_count):
        count = sequence&0xfff
        next_count = (count+1)&0xfff
        if need_flush: tx.reset()
        if next_count&255==0: tx.update()
        payload = b"\x00\x21"+sequence.to_bytes(4,"big")+bytes((sequence+i)%256 for i in range(sequence%47))
        header = count|0x1000|(0x8000 if need_flush else 0)
        need_flush = False
        wire = tx.rc4.encrypt(payload)
        if sequence==drop_at: continue
        gate = rx_gate(expected,waiting,header)
        expected,waiting = gate["expected"],gate["waiting"]
        if gate["action"]=="reset_request":
            resets += 1; need_flush = True; continue
        assert gate["action"]=="route"
        if header&0x8000: rx.reset()
        epoch = expected>>8
        while rx_key_epoch!=epoch:
            rx.update(); rx_key_epoch = (rx_key_epoch+1)&15
        assert rx.rc4.decrypt(wire)==payload
        assert tx.current==rx.current
        delivered += 1
    return dict(strength=strength,packets=packet_count,dropped_sequence=drop_at,
                delivered=delivered,reset_requests=resets,tx_keyupdates=tx.updates,rx_keyupdates=rx.updates)


def main():
    import pefile
    modules = json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    module = next(m for m in modules if m["origin"]=="rom" and m["name"]=="ppp.dll")
    path = ROOT/module["path"]; assert hashlib.sha256(path.read_bytes()).hexdigest()==HASH
    pe = pefile.PE(str(path)); base = pe.OPTIONAL_HEADER.ImageBase
    fs = json.loads((ROOT/"analysis/functions/rom/ppp.dll.json").read_text(encoding="utf-8"))["functions"]
    index = {int(f["begin_va"],16):f for f in fs}
    ranges = [(va,index[va]["bytes"],"Original .pdata function") for va in FUNCTIONS]+LEAVES
    ranges += [(0xc044d760,32,"CCP option18 descriptor"),(0xc044d6d8,36,"Extra-code descriptor list"),
               (0xc044d6fc,44,"CCP FSM descriptor")]
    evidence = []
    for va,size,role in ranges:
        raw = pe.get_data(va-base,size); assert len(raw)==size
        evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    option = struct.unpack("<8I",pe.get_data(0xc044d760-base,32))
    assert option[0]==0x412 and option[2:]==(0xc043f954,0xc043f9a8,0xc043f9fc,0,0xc043faa0,0xc043f7b8)
    option_cases = 0
    for low in range(256):
        for high in (0,0x1000000,0x80000000):
            for entry in (0,0x200,0x1800,0x1a00):
                for supported in (0,0x20,0x40,0x60):
                    answer = peer_request(low|high,entry,supported)
                    assert answer["proposal"]&~0x61==0
                    if high or low&~0x61: assert answer["code"]==3
                    assert int.from_bytes(bytes.fromhex(answer["payload"]),"big")==answer["proposal"]
                    option_cases += 1
    assert peer_request(0x60,0,0x60)==dict(code=3,proposal=0x40,payload="00000040")
    assert peer_request(0x80,0,0x60)["proposal"]==0
    assert peer_request(0x1000040,0,0x60)["proposal"]==0x40
    assert peer_request(0,0x1800,0x60)["proposal"]==0x60
    flush_cases = 0
    for expected in range(4096):
        for delta in (0,1,255,256,3839,3840,4095):
            count = (expected+delta)%4096
            answer = rx_gate(expected,True,0x9000|count)
            assert (answer["action"]=="drop_stale_flush")== (delta>=3840)
            if delta<3840: assert answer["expected"]==(count+1)%4096 and not answer["waiting"]
            flush_cases += 1
    assert rx_gate(7,False,0x1008)["action"]=="reset_request"
    assert rx_gate(7,False,7)["action"]=="route" and not rx_gate(7,False,7)["decrypt"]
    assert rx_gate(7,False,0x2007)["action"]=="drop_unnegotiated_compression"
    keys = json.loads((ROOT/"analysis/firmware/mschap-crypto-contracts.json").read_text(encoding="utf-8"))["rfc3079"]
    start = bytes.fromhex(keys["client_receive_server_send"])
    streams = []
    for strength in (40,128):
        for dropped in (None,255,300,4095):
            streams.append(transport_check(start,strength,9000,dropped))
    assert all(s["tx_keyupdates"]==35 and s["rx_keyupdates"]==35 for s in streams)
    assert all(s["reset_requests"]==int(s["dropped_sequence"] is not None) for s in streams)
    result = dict(binary_execution=False,module=module["path"],sha256=HASH,evidence=evidence,
        references=["https://www.rfc-editor.org/rfc/rfc3078.html"],
        checks=dict(preserved_ranges=len(evidence),option_cases=option_cases,flush_cases=flush_cases,
                    synthetic_streams=len(streams),synthetic_packets=sum(s["packets"] for s in streams)),
        streams=streams,
        examples=dict(only56=peer_request(0x80,0,0x60),stateless128=peer_request(0x1000040,0,0x60),
                      both40and128=peer_request(0x60,0,0x60),required_missing=peer_request(0,0x1800,0x60)),
        eap_key_chain=dict(attribute16=dict(session_key_offset="0xae0",length_offset="0xb00",ccp_direction="TX"),
                           attribute17=dict(session_key_offset="0xb04",length_offset="0xb24",ccp_direction="RX")),
        limits=["Protocol-faithful Python models plus assembly review; firmware never executed",
                "EAP direction convention versus client/server role remains a discrepancy to resolve",
                "Full MPPC compression/decompression and all FSM/lifetime paths remain open"])
    out = ROOT/"analysis/firmware/ppp-ccp-contracts.json"
    out.write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"]),indent=2))


if __name__=="__main__": main()
