"""Check rebased AppMain IPC retries, including image globals and protocol IDs."""
import hashlib
import json
from pathlib import Path
from verify_media_responsiveness import VM, parsed, call, STACK
from verify_usb_input_safety import relocated
from inspect_bt_pairing import put

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'build/shared-mapping-development-01'
MANAGER, STATE, COORD, WINDOW = 0x43000000,0x44000000,0x45000000,0x46000000
ERROR_API = 0xf0220000


def check(raw,delta,kind,mode,scenario):
    image=raw if not delta else relocated(raw,delta)
    m=VM(parsed(image),[(0x11b464+delta,0x11b5c8+delta)])
    for at,n in ((MANAGER,0xc0),(STATE,0x700),(COORD,0x40),(WINDOW,4)):put(m,at,bytes(n))
    m.write(0x187be4+delta,MANAGER);m.write(MANAGER+0xa8,STATE)
    m.write(STATE+0x6d4,int(scenario!='disabled'));m.write(COORD+0x14,kind)
    m.write(WINDOW,0x9876);m.write(0x185020+delta,ERROR_API)
    sends=[];finds=[]
    command=0 if scenario=='invalid' else 0x1010804
    responses={'success':[1],'error':[0],'timeout':[0,0],'retry':[0,1]}.get(scenario,[])
    def clobber(v):
        for r in (*range(3,16),24,25):v.reg[r]=0xcafe0000+r
    def find(v):
        assert v.reg[4:6]==[COORD+4,1]
        finds.append(1);clobber(v);return WINDOW
    def send(v):
        assert v.reg[4:8]==[0x9876,0x8065 if kind==1 else kind+0x806e,command,8]
        assert v.read(v.reg[29]+0x10)==0 and v.read(v.reg[29]+0x14)==1500
        assert v.read(v.reg[29]+0x18)==v.reg[29]+0x20
        answer=responses[len(sends)];sends.append(answer)
        v.write(v.reg[29]+0x20,0x4c530008);clobber(v);return answer
    def error(v):clobber(v);return 0x578 if scenario in ('retry','timeout') else 5
    m.hooks={0x1144b4+delta:find,0x1400a8+delta:send,ERROR_API:error}
    result=call(m,0x11b464+delta,[COORD,mode,command,8])
    failed=scenario in ('error','timeout','disabled','invalid')
    expected=0xffffffff if failed else 0 if mode==1 else 0x4c530008
    assert result==expected and sends==responses
    assert len(finds)==len(sends)
    return dict(delta=hex(delta),kind=kind,mode=mode,scenario=scenario,
                return_value=hex(result),send_results=sends,abi_preserved=True)


def main():
    manifest=json.loads((OUT/'manifest.json').read_bytes())
    raw=(OUT/'payload/upgrade/Storage Card/System/AppMain.exe').read_bytes()
    digest=hashlib.sha256(raw).hexdigest()
    assert digest==next(r['sha256'] for r in manifest['members'] if r['path'].endswith('/AppMain.exe'))
    traces=[check(raw,delta,kind,mode,scenario)
            for delta in (0,0x10000,0x120000,0x500000)
            for kind in (1,2) for mode in (1,2)
            for scenario in ('success','error','timeout','retry','disabled','invalid')]
    assert len(traces)==96
    proof=dict(cases=len(traces),output_sha256=digest,traces=traces,
               actual_wrapper_instructions_executed=True,preferred_and_three_aligned_bases=True,
               image_global_and_import_addresses_rebased=True,
               retry_message_ids_and_mode_contract_preserved=True,
               window_lookup_and_send_apis_are_fixtures=True,native_loader_tested=False,
               tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    target=ROOT/'analysis/firmware/appmain-relocation-runtime-audit.json'
    target.write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=len(traces),output_sha256=digest,native_loader_tested=False)))


if __name__=='__main__':main()
