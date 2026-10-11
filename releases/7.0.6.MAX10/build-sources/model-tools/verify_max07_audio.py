"""Exercise the complete MAX07 PCM functions and added leaf helpers as MIPS.

Payload bytes and original queue ownership execute; clocks, gates and wave
driver outcomes remain fixtures. This does not measure audible stuttering.
"""
import hashlib
import json
from pathlib import Path
import max07_bt_helpers as helper
from patch_max07_bluetooth import SOURCE, patch
from verify_bt_text_recovery_audio import Playback as Original
from inspect_bt_lifecycle import CTX

ROOT = Path(__file__).resolve().parents[1]


class Playback(Original):
    def __init__(self, raw, limit=22):
        super().__init__(raw, limit)
        self.vm.ranges += [(r['address'], r['address'] + len(r['raw'])) for r in helper.assembled()]

    def reserve(self):
        return self.vm.read(helper.AUDIO + 4)


def verify(raw):
    traces = []
    def record(name, m):
        traces.append(dict(case=name, submitted=len(m.submitted), remaining=len(m.queued),
                           reserve=m.reserve(), drains=m.vm.read(helper.AUDIO+8),
                           restarts=m.restarts, bytes_sha256=hashlib.sha256(b''.join(m.submitted)).hexdigest()))

    m=Playback(raw);m.lifecycle(0x26c68)
    incoming=bytearray()
    for i in range(100):
        n=(1,511,512,1024,4095,4096,8192,16384,32768,65536)[i%10]
        b=bytes((i*31+j*7)&255 for j in range(n));incoming.extend(b);m.packet(b)
        while len(m.queued)>1:m.done(next(iter(m.queued)))
    submitted=b''.join(m.submitted)
    assert submitted==incoming[:len(incoming)//4096*4096]
    tail=m.vm.read(CTX+0x334)
    assert m.data(m.vm.read(CTX+0x330),tail)==incoming[len(submitted):]
    assert m.reserve()==2
    record('mixed_payloads_and_ring_wraps_preserve_every_PCM_byte',m)

    # Equal burst that overflows MAX06 fits MAX07 without resetting ownership.
    m=Playback(raw);m.lifecycle(0x26c68)
    a=bytes((i*11)&255 for i in range(65536));b=bytes((i*13)&255 for i in range(24576))
    m.packet(a);m.packet(b)
    assert len(m.queued)==22 and b''.join(m.submitted)==a+b
    snapshot=dict(m.queued);copies=len(m.copies)
    m.packet(b'X'*8192)
    assert m.queued==snapshot and len(m.copies)==copies
    m.done(0);m.packet(b'Z'*4096)
    assert len(m.queued)==22 and m.submitted[-1]==b'Z'*4096
    record('22_block_burst_then_saturation_never_overwrites_owned_PCM',m)

    m=Playback(raw);m.lifecycle(0x26c68)
    for expected in (4,6,8,8):
        n=m.reserve();m.packet(b'D'*(n*4096))
        assert m.vm.read(CTX+0x338,1)==1
        old=list(m.queued)
        for h in old:m.done(h)
        assert m.reserve()==expected and not m.vm.read(CTX+0x338,1)
        for h in old:m.done(h)
        assert m.reserve()==expected
        m.packet(b'E'*((expected-1)*4096))
        assert not m.vm.read(CTX+0x338,1)
        m.packet(b'F'*4096)
        assert m.vm.read(CTX+0x338,1)==1
        # Drain on the next iteration and verify no unexpected extra growth.
        if expected != 8 or m.vm.read(helper.AUDIO+8)<4:
            m.lifecycle(0x26d2c)
            for h in list(m.queued):m.done(h)
            # Stop suppresses adaptive growth; restore started state as a fixture
            # without normal Start, to continue the same adaptation sequence.
            m.vm.write(CTX+4,2,1)
    assert m.reserve()==8
    record('live_drain_adapts_2_4_6_8_and_duplicate_completion_does_not',m)
    m.lifecycle(0x26d2c)
    for h in list(m.queued):m.done(h)
    assert m.reserve()==8
    m.lifecycle(0x26c68)
    assert m.reserve()==2 and m.vm.read(helper.AUDIO+8)==0
    record('normal_source_stop_start_resets_to_fast_two_block_startup',m)

    for timing in ('before_start','after_start','split_after_new_submission'):
        m=Playback(raw);m.lifecycle(0x26c68);m.packet(b'A'*65536);m.packet(b'A'*24576)
        old=list(m.queued);m.lifecycle(0x26d2c)
        assert m.reset_requests==[old]
        m.gates=False;snapshot=dict(m.queued);copies=len(m.copies)
        m.packet(b'X'*8192);assert m.queued==snapshot and len(m.copies)==copies
        if timing=='before_start':
            for h in old:m.done(h)
        m.gates=True;m.lifecycle(0x26c68)
        if timing!='before_start':
            m.packet(b'Y'*8192);assert m.queued==snapshot and len(m.copies)==copies
            for h in old[:len(old) if timing=='after_start' else 2]:m.done(h)
        m.packet(b'B'*8192)
        assert m.submitted[-2:]==[b'B'*4096]*2
        for h in old:
            if h in m.queued:m.done(h)
            pending=m.vm.read(CTX+5,1);m.done(h)
            assert m.vm.read(CTX+5,1)==pending
        assert len(m.queued)==2 and set(m.queued.values())=={b'B'*4096}
        record('stop_restart_delayed_completion_'+timing,m)

    for result in (1,6,11,33,34):
        for owned in (False,True):
            m=Playback(raw);m.lifecycle(0x26c68);m.write_result=result;m.failure_owned=owned
            m.packet(b'G'*8192)
            assert len(m.queued)==int(owned) and not m.restarts
            if owned:m.done(next(iter(m.queued)))
            m.write_result=0;m.failure_owned=False;m.packet(b'H'*8192)
            assert len(m.queued)==2 and m.vm.read(CTX+0x338,1)==1
            record('write_failure_ownership_'+str(result)+'_'+str(owned),m)
    return dict(cases=len(traces), traces=traces, candidate_sha256=hashlib.sha256(raw).hexdigest(),
                hardware_tested=False, native_executed=False,
                limits=['Actual candidate PCM/Start/Stop/completion and new helper instructions execute',
                        'Wave/lock/gate outcomes and delivery order are fixtures',
                        'Saturation beyond 22 blocks still drops bounded excess; no audible/device timing evidence'])


if __name__=='__main__':
    raw,_=patch(SOURCE.read_bytes());r=verify(raw)
    out=ROOT/'build/max07-bluetooth-development-02/audio-verification.json'
    out.write_text(json.dumps(r,indent=2)+'\n')
    print(json.dumps(dict(cases=r['cases'],sha256=r['candidate_sha256']),indent=2))
