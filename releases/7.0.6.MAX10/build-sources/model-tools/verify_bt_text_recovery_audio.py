"""Verify packaged PCM ownership across gated stop/restart and delayed callbacks.

Execute full original PCM/start/stop/completion functions from the actual PE.
Source gates, wave reset/completion delivery, driver results and format are
fixtures. This does not emulate Radio switching or measure audible stutter.
"""
import argparse
import hashlib
import json
from pathlib import Path
import pefile
from patch_bt_text_recovery_install import patch
from patch_bt_pcm_bursts import patch as pcm_patch
from verify_bt_patch import Playback as OriginalPlayback,TABLE
from inspect_bt_lifecycle import CTX,PCM,STACK,INPUT,COUNT,SLOT
from inspect_wave_queue import STOP

ROOT=Path(__file__).resolve().parents[1]


class Playback(OriginalPlayback):
    def __init__(self,raw,limit):
        super().__init__(pefile.PE(data=raw));self.limit=limit;self.reset_requests=[]
        self.vm.hooks[0x8a8c0]=self.reset

    def reset(self,m):
        assert m.reg[4]==0x1234
        self.reset_requests.append(list(self.queued))
        return 0 # Completion messages are delivered explicitly, never fabricated by Stop.

    def packet(self,payload,owned_input=True):
        m=self.vm
        for i,b in enumerate(payload):m.write(INPUT+i,b,1)
        m.reg[29]=STACK;m.reg[31]=STOP;m.write(STACK+0x10,len(payload))
        saved={i:0x12340000+i for i in (*range(16,24),30)}
        for i,v in saved.items():m.reg[i]=v
        m.reg[4:8]=[0,TABLE,int(owned_input),INPUT]
        m.run(0x26e14,{STOP},limit=20000)
        assert m.reg[29]==STACK and all(m.reg[i]==v for i,v in saved.items())
        assert self.lock_depth==0 and m.read(CTX+5,1)==len(self.queued)<=self.limit
        assert m.read(CTX+0x334)<4096 and 0<=m.read(CTX+6,1)<COUNT
        for i in range(COUNT):assert bool(m.read(CTX+0x1c+i*32))==(i in self.queued)


def verify(original,candidate):
    expected,_=patch(original);assert candidate==expected
    audio,_=pcm_patch(original);p=pefile.PE(data=candidate);q=pefile.PE(data=audio)
    spans=((0x25a5c,0x25e84),(0x26400,0x26550),(0x266a4,0x270f4))
    for lo,hi in spans:assert p.get_data(lo-0x10000,hi-lo)==q.get_data(lo-0x10000,hi-lo)
    traces=[]
    def record(name,player):
        traces.append(dict(case=name,capacity=player.limit,queue=len(player.queued),
                           submissions=len(player.submitted),restarts=player.restarts,
                           resets=player.reset_requests,instructions=player.vm.steps,
                           submitted_sha256=hashlib.sha256(b''.join(player.submitted)).hexdigest()))
    for raw,limit,label in ((original,4,'MAX05'),(candidate,8,'MAX06')):
        # More than two ring wraps, mixed partial packets, real payload copies.
        m=Playback(raw,limit);m.lifecycle(0x26c68);incoming=bytearray()
        for i in range(80):
            size=(512,1024,2048,4096,8192)[i%5]
            body=bytes((i+j*7)&255 for j in range(size));incoming.extend(body);m.packet(body)
            while len(m.queued)>1:m.done(next(iter(m.queued)))
        assert b''.join(m.submitted)==incoming[:len(incoming)//4096*4096]
        tail=m.vm.read(CTX+0x334)
        assert m.data(m.vm.read(CTX+0x330),tail)==incoming[len(m.submitted)*4096:]
        record(label+'_mixed_packets_preserve_payload_across_ring_wraps',m)

        for timing in ('before_start','after_start','split_after_new_submission'):
            m=Playback(raw,limit);m.lifecycle(0x26c68);m.packet(b'A'*(limit*4096))
            old=list(m.queued);assert len(old)==limit
            m.lifecycle(0x26d2c);assert m.vm.read(CTX+4,1)==1 and m.reset_requests==[old]
            snapshot=dict(m.queued);copies=len(m.copies);m.gates=False
            m.packet(b'X'*8192);assert m.queued==snapshot and len(m.copies)==copies
            if timing=='before_start':
                for h in old:m.done(h)
            m.gates=True;m.lifecycle(0x26c68)
            if timing!='before_start':
                m.packet(b'Y'*8192);assert m.queued==snapshot and len(m.copies)==copies
                count=len(old) if timing=='after_start' else 2
                for h in old[:count]:m.done(h)
            m.packet(b'B'*8192)
            assert m.submitted[-2:]==[b'B'*4096,b'B'*4096]
            for h in old:
                # Old reset acknowledgements may arrive after new submissions.
                # No old header has been reused yet; duplicates cannot decrement
                # the count or release one of the newly owned headers.
                if h in m.queued:m.done(h)
                pending=m.vm.read(CTX+5,1);m.done(h)
                assert m.vm.read(CTX+5,1)==pending
            assert len(m.queued)==2 and all(body==b'B'*4096 for body in m.queued.values())
            record(label+'_stop_restart_completion_'+timing,m)

        m=Playback(raw,limit);m.lifecycle(0x26c68);m.packet(b'C'*(limit*4096))
        assert len(m.queued)==limit
        m.lifecycle(0x26d2c);m.lifecycle(0x26c68);m.restart_result=1
        snapshot=dict(m.queued);m.packet(b'D'*4096)
        assert m.queued==snapshot and not m.vm.read(CTX+0x338,1)
        m.restart_result=0;m.packet(b'D'*4096)
        assert m.queued==snapshot and m.vm.read(CTX+0x338,1)==1
        for h in list(m.queued):m.done(h)
        m.packet(b'E'*8192);assert m.submitted[-2:]==[b'E'*4096,b'E'*4096]
        record(label+'_full_queue_retries_restart_without_overwrite',m)
    names=('verify_bt_text_recovery_audio.py','verify_bt_patch.py','inspect_bt_lifecycle.py',
           'patch_bt_text_recovery_install.py','patch_bt_pcm_bursts.py','inspect_wave_queue.py')
    return dict(cases=len(traces),traces=traces,candidate_sha256=hashlib.sha256(candidate).hexdigest(),
                original_sha256=hashlib.sha256(original).hexdigest(),hardware_tested=False,
                executable_changed=False,lgu_changed=False,retained_audio_spans=[list(s) for s in spans],
                limits=['Full PCM, completion, Stop and same-format Start instructions come from actual PE bytes',
                        'Source gates, wave reset, completion timing, driver/lock outcomes and format are fixtures',
                        'Successful reset can temporarily leave the software queue full until its completion messages arrive',
                        'No extra buffer reuse or duplicate-completion count loss occurs in these bounded sequences',
                        'Radio command routing, SBC decoding, native scheduling and physical stutter remain unverified'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in names})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for n in ('input','candidate','report'):p.add_argument('--'+n,type=Path,required=True)
    a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    r=verify(a.input.read_bytes(),a.candidate.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(r,indent=2)+'\n').encode())
    print(json.dumps(dict(cases=r['cases'],lgu_changed=False),indent=2))
