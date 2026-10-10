"""Evidence and bounded projection of candidate MCU normal-frame reception.

Does not emulate MCU execution, RAM ownership, ring collisions or hardware.
"""
from pathlib import Path
from functools import reduce
from operator import xor
import hashlib
import json

from micom_protocol import parse_capture
from inspect_micom_flow import decoder, operand

ROOT = Path(__file__).resolve().parents[1]
IMAGE_SHA = "4c5a45266f11cbd2a408c3b9880008a819091e61c61a7283f51949244bd76512"


def packet(route, command, payload, channel=0):
    assert 0 <= route < 256 and 0 <= command < 256 and len(payload) < 256
    assert channel == 0 or route == 0
    prefix = bytes((0xaa,route,command,len(payload)))
    check = reduce(xor,prefix+payload,0)
    return (prefix if channel == 0 else bytes((0xaa,command,len(payload)))) + payload + bytes((check,))


class RxProjection:
    """Seven-state byte parser only, with unlimited hypothetical storage.

    Time ticks are supplied by caller. This deliberately omits finite queue,
    pointer collisions, producer/consumer interleavings and actual interrupts.
    """
    def __init__(self, channel):
        assert channel in (0,1)
        self.channel, self.state, self.last = channel, 0, 0
        self.route, self.command, self.length = 0, 0, 0
        self.payload = bytearray()
        self.accepted = []

    def feed(self, byte, tick=0, reset=False):
        assert 0 <= byte < 256
        if reset or (self.state and ((tick-self.last)&0xffff) >= 0x65):
            self.state = 0
        if self.state == 0:
            if byte == 0xaa:
                self.route = 0
                self.state = 1 if self.channel == 0 else 2
        elif self.state == 1:
            self.route = byte
            self.state = 2
        elif self.state == 2:
            self.command = byte
            self.state = 3
        elif self.state == 3:
            self.length = byte
            self.payload = bytearray()
            self.state = 4 if byte else 5
        elif self.state == 4:
            self.payload.append(byte)
            if len(self.payload) == self.length:
                self.state = 5
        elif self.state == 5:
            expected = reduce(xor,bytes((0xaa,self.route,self.command,self.length))+self.payload,0)
            if byte == expected:
                self.accepted.append(dict(route=self.route,command=self.command,payload_hex=self.payload.hex()))
            self.state = 0 if self.channel == 0 else 6
        elif self.state == 6:
            self.state = 0  # channel one discards this byte, even if it is AA
        self.last = tick & 0xffff

    def consume(self, data):
        for b in data: self.feed(b)
        return self.accepted


def verify():
    valid, bad, alternate = 0,0,0
    for length in range(256):
        payload=bytes((i*73+length)&255 for i in range(length))
        raw=packet(0x11,5,payload)
        got=RxProjection(0).consume(raw)
        host=parse_capture(raw)
        assert len(got)==1 and len(host)==1 and host[0]["checksum_valid"]
        assert got[0]==dict(route=(host[0]["manager_nibble"]<<4)|host[0]["type_nibble"],
                           command=host[0]["command"],payload_hex=host[0]["payload_hex"])
        valid+=1
        damaged=raw[:-1]+bytes((raw[-1]^1,))
        assert RxProjection(0).consume(damaged)==[]
        bad+=1
        alt=packet(0,5,payload,1)
        assert RxProjection(1).consume(alt)==[dict(route=0,command=5,payload_hex=payload.hex())]
        alternate+=1
    raw=packet(0x11,5,b"")
    assert len(RxProjection(0).consume(raw+raw))==2
    alt=packet(0,5,b"",1)
    assert len(RxProjection(1).consume(alt+alt))==1
    assert len(RxProjection(1).consume(alt+b"\0"+alt))==2
    for delay, accepted in ((100,True),(101,False)):
        parser=RxProjection(0)
        parser.feed(raw[0],0)
        for b in raw[1:]: parser.feed(b,delay)
        assert bool(parser.accepted)==accepted
    parser=RxProjection(0); parser.feed(0xaa,0xfff0); parser.feed(0x11,0x10)
    assert parser.state==2  # uint16 clock wrap, interval 32
    parser=RxProjection(0); parser.consume(raw[:-1]); assert parser.accepted==[] and parser.state==5
    parser.feed(0xaa,reset=True); assert parser.state==1
    return dict(host_frame_comparisons=valid,invalid_checksum_cases=bad,channel_one_cases=alternate,
                edge_cases=8,scope="Bounded framing projection only; not native execution")


def main():
    source=ROOT/"analysis/firmware"
    image=(source/"micom-image.bin").read_bytes()
    assert hashlib.sha256(image).hexdigest()==IMAGE_SHA
    listing=json.loads((source/"flow-expanded/rl78-instructions.json").read_text(encoding="utf-8"))
    indexed={int(i["address"],16):i for i in listing}
    expected={0xeb6:"fcb64d01",0xef0:"fcb64d01",0x14e30:"61f8",0x14e32:"ee8f00",0x14e35:"91",
              0x14e52:"4caa",0x14f3f:"d1",0x150ee:"61e8",0x150f0:"ee3901",0x150f3:"8c08",0x15255:"8c08"}
    for ea,raw in expected.items(): assert indexed[ea]["bytes"]==raw
    ranges=[]
    for label,start,end in (("channel zero interrupt",0xe8c,0xed4),("channel one interrupt",0xed4,0xf0e),
                            ("candidate indexed arithmetic helper",0x473,0x484),
                            ("candidate context reset",0x14ce2,0x14db6),("receive state machine",0x14db6,0x1527c)):
        raw=image[start:end]
        ranges.append(dict(label=label,start=hex(start),end_exclusive=hex(end),bytes=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    example=packet(0x11,5,b"")
    # A raw immediate-looking byte pair is not a rooted instruction. Preserve
    # a separately aligned local candidate decode rather than claiming reachability.
    local=[]
    ea=0x14303
    while ea<0x1430e:
        ins=decoder.decode_one(image,ea)
        assert ins is not None
        local.append(dict(address=hex(ea),bytes=ins.raw.hex(),mnemonic=ins.mnem,
                          operands=[operand(o) for o in ins.ops]))
        ea+=ins.size
    assert next(i for i in local if i["address"]=="0x1430a")["bytes"]=="ac4c"
    assert image[0x1430b:0x1430d]==bytes.fromhex("4ca1")
    result=dict(image_sha256=IMAGE_SHA,producer_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
                exact_cpu_identified=False,binary_execution=False,source_ranges=ranges,preimages={hex(a):b for a,b in expected.items()},
                decoder_comparison=json.loads((source/"flow-expanded/decoder-comparison.json").read_text(encoding="utf-8")),
                projection_checks=verify(),ordinary_update_control=dict(frame_hex=example.hex(),
                    parsed=RxProjection(0).consume(example),meaning="Framing acceptance only; command 5 handler, boot transfer and flash semantics unresolved"),
                unrooted_a1_hit=dict(raw_offset="0x1430b",raw_bytes="4ca1",local_candidate_decode=local,
                    scope="Local alignment hypothesis from 0x14303 prologue; no rooted reachability or independent Ghidra export",
                    conclusion="Raw pair alone is not evidence for CMP A,#A1 or ULC handler"),
                context_candidate=dict(base="0xfdd62",stride="0x244",index_helper="0x473",state_offset="0x0",timestamp_offset="0x2",
                    working_payload_pointer="0x4",remaining_length="0x6",header_ring_candidate=["0x8","0x38"],
                    header_end="0x38",consumer_header_pointer="0x3a",producer_header_pointer="0x3c",
                    payload_ring_candidate=["0x3e","0x23e"],payload_end="0x23e",consumer_payload_boundary="0x240",next_payload_start="0x242"),
                limitations=["Candidate ISA, register/memory map and indexed arithmetic need exact-chip validation",
                    "Finite ring ownership, full-queue policy and interrupt timing omitted from projection",
                    "101 is a uint16 tick threshold, not a proven millisecond value",
                    "Normal AA reception does not establish ULC/A1 parser or restart/flash behavior"])
    (source/"micom-rx-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(result["projection_checks"],indent=2))
    print("Ordinary AA5:",example.hex(),"candidate acceptance only")


if __name__=="__main__":main()
