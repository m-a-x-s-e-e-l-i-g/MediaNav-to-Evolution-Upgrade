"""Check complete startup/audio recovery while preserving source routing intent."""
import hashlib
import json
from pathlib import Path
from patch_bt_startup_audio_v2 import patch
from verify_bt_startup_audio import Fixture as BaseFixture,structure,retained_playback,AV,CTX,WIN,GLOBAL,IND,ROOT

class Fixture(BaseFixture):
    def pause(self,vm):
        if vm.read(CTX+4,1)==0:
            # Native Close also pauses a partially prepared output. It has no
            # submitted PCM; starting it still requires all 25 preparations.
            assert vm.reg[4] in self.wave_handles
            self.events.append(dict(phase=self.phase,call='cleanup_pause',handle=vm.reg[4]))
            return 0
        return super().pause(vm)

def verify(original,candidate,after,recipe,previous_proof):
    active=recipe['active_recipe']
    assert hashlib.sha256(original).hexdigest()==active['input_sha256']
    assert hashlib.sha256(candidate).hexdigest()==recipe['input_sha256']
    assert previous_proof['recipe']['output_sha256']==recipe['input_sha256']
    for row in active['edits']:
        at=row['offset'];n=row['end']-row['start']
        assert after[at:at+n]==candidate[at:at+n]==bytes.fromhex(row['after_hex'])
    # Preserve the full incoming handler, including routing intent, peer
    # responses and logs. Physical readiness lives in WinPlay/table status.
    import pefile
    a,b=pefile.PE(data=original),pefile.PE(data=after)
    assert a.get_data(0x1ace4-a.OPTIONAL_HEADER.ImageBase,0x3a4)==b.get_data(0x1ace4-b.OPTIONAL_HEADER.ImageBase,0x3a4)
    structural=structure(original,after,active)
    cases=[]
    for chain in (1,3):
        for entry in (0x1ace4,0x1ab90):
            for name,params,ok in (('normal',{},True),('wave_once',dict(wave=(4,0)),True),
                ('thread_once',dict(thread=(False,True)),True),('both_once',dict(thread=(False,True),wave=(4,0)),True),
                ('wave_persistent',dict(wave=(4,)),False),('thread_persistent',dict(thread=(False,)),False),
                ('partial_prepare',dict(prep_fail=24),False),('ambiguous',dict(wave=(4,),ambiguous=True),False)):
                f=Fixture(after,chain=chain,**params)
                if entry==0x1ab90:
                    f.invoke(0x25a5c,[0,AV,2])
                    f.vm.write(IND+6,0x8000,2);f.vm.write(IND+8,0x14,2)
                f.invoke(entry,[GLOBAL,AV,IND])
                assert f.vm.read(WIN+7,1)==(3 if ok else 2)
                assert f.vm.read(CTX+4,1)==(2 if ok else 0)
                assert f.vm.read(AV+0x11d,1)==1  # Original routing intent, not readiness.
                if entry==0x1ace4:
                    assert f.responses==[dict(type=0x1a,error=0)]
                    assert f.messages==[[2,0x3070801,0],[2,0x3071101,1]]
                f.packet()
                assert bool(f.writes)==ok
                assert len(f.threads)<=1 and f.thread_calls<=2 and f.wave_calls<=2
                cases.append(f.result(f'handler-{hex(entry)}-{name}-chain{chain}'))
        # Same linked sequence that caught the first development regression:
        # peer stream stays running, first opening fails, a later normal source
        # lifecycle closes/reopens the filters. Routing must permit real PCM.
        for name,params in (('thread',dict(thread=(False,))),('wave',dict(wave=(4,))),
            ('partial',dict(prep_fail=24)),('ambiguous',dict(wave=(4,),ambiguous=True))):
            f=Fixture(after,chain=chain,**params)
            f.invoke(0x1ace4,[GLOBAL,AV,IND]);f.packet();assert not f.writes
            f.thread_results=[True];f.wave_results=[0];f.prep_fail=None;f.ambiguous=False
            assert f.invoke(0x25a5c,[0,AV,3])==1
            assert f.open_start()==(1,1)
            f.packet()
            assert b''.join(f.writes)==bytes(i*17&255 for i in range(8192))
            assert f.vm.read(AV+0x11d,1)==1 and len(f.threads)==1
            cases.append(f.result(f'later-reopen-{name}-chain{chain}'))
    # Exact before/after reproducer for the discarded routing modification.
    comparisons=[]
    for raw,label in ((candidate,'development01'),(after,'development02')):
        f=Fixture(raw,chain=3,thread=(False,))
        f.invoke(0x1ace4,[GLOBAL,AV,IND]);f.thread_results=[True]
        assert f.invoke(0x25a5c,[0,AV,3])==1 and f.open_start()==(1,1)
        f.packet()
        assert len(f.writes)==(0 if label=='development01' else 2)
        comparisons.append(f.result(label))
    # Non-audio source intent remains a gate even with a ready wave device.
    f=Fixture(after);assert f.open_start()==(1,1)
    f.vm.write(AV+0x11d,0,1);f.packet();assert not f.copies
    cases.append(f.result('unselected-source-stays-gated'))
    carried=previous_proof['new_checks']['behavior']
    carried_cases=sum(not row['name'].startswith('handler-') for row in carried['traces'])+len(carried['counterexamples'])
    return dict(structure=structural,cases=len(cases)+1,traces=cases,counterexample=comparisons,
        preserved_retry_readiness_checks=dict(cases=carried_cases,
            reason='Open/Start/START-dispatcher bytes unchanged; prior proof pinned, 16 superseded handler cases excluded. Native startup handlers rerun.'),
        retained_playback=retained_playback(after),native_executed=False,hardware_tested=False,
        limitations=['OS, scheduler, driver and phone messages remain fixtures',
            'Existing close failure/lifetime semantics unchanged',
            'Explicit filter reopen is not a complete native source switch or phone reconnect emulation'])

if __name__=='__main__':
    base=ROOT/'build/bt-startup-audio-development-01'
    m=json.loads((base/'manifest.json').read_text(encoding='utf-8'))
    proof=json.loads((ROOT/m['proof']['path']).read_text(encoding='utf-8'))
    name='upgrade/Storage Card/System/Blue.exe'
    before=(base/'payload'/name).read_bytes()
    original=(ROOT/'build/usb-option-snapshot-development-01/payload'/name).read_bytes()
    after,r=patch(before,m['recipes']['bluetooth_startup'])
    checks=verify(original,before,after,r,proof)
    print(json.dumps(dict(cases=checks['cases'],sha256=r['output_sha256'])))
