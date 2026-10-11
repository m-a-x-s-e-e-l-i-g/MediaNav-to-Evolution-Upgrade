"""Original SDP-query instructions plus the proposed bridge, with CSR calls as fixtures."""
import argparse
import hashlib
import json
from pathlib import Path

import pefile

import bt_cover_art_csr_bridge as bridge
from inspect_bt_pairing import put
from verify_bt_cover_attribute import SerializerVM
from verify_media_responsiveness import call

ROOT = Path(__file__).resolve().parents[1]
OWNER, CONNECTION = 0x41000000, 0x41001000


class BridgeImage:
    def __init__(self, original, code):
        self.original, self.code = original, code
        self.OPTIONAL_HEADER = original.OPTIONAL_HEADER

    def get_data(self, rva, size):
        address = rva+self.OPTIONAL_HEADER.ImageBase
        offset = address-bridge.ENTRY
        if 0 <= offset and offset+size <= len(self.code):
            return self.code[offset:offset+size]
        return self.original.get_data(rva,size)


class VM(SerializerVM):
    def word(self, pc):
        return self.patches[pc] if pc in self.patches else super().word(pc)

    def plain(self, word):
        if word >> 26 == 0x29:
            rs,rt,imm = (word >> 21)&31,(word >> 16)&31,word&65535
            if imm&32768: imm-=65536
            self.write((self.reg[rs]+imm)&0xffffffff,self.reg[rt],2)
        else:
            super().plain(word)


def verify(raw):
    code,recipe,word = bridge.bridge(raw)
    original = pefile.PE(data=raw)
    traces=[]
    for busy in (0,1):
        for local_tg in (0,1):
            for local_ct in (0,1):
                for optional_ok in (False,True):
                    sides=[]
                    for enabled in (False,True):
                        vm=VM(BridgeImage(original,code),[(0x58aac,0x58c34),(bridge.ENTRY,bridge.ENTRY+len(code))])
                        if enabled: vm.patches[bridge.SITE]=word
                        put(vm,OWNER,bytes(0x90));put(vm,CONNECTION,bytes(0x70))
                        vm.write(OWNER+0x20,busy,1)
                        vm.write(OWNER+0x40,local_tg);vm.write(OWNER+0x70,local_ct)
                        vm.write(OWNER+0x24,0x44000000)
                        vm.write(CONNECTION+8,0x11223344);vm.write(CONNECTION+12,0x55667788)
                        constructions,queries,starts=[],[],[]
                        def construct(m):
                            assert m.reg[5] in (0x110e,0x110c)
                            record=3 if m.reg[5]==0x110e else 4
                            constructions.append((m.reg[4],m.reg[5],record))
                            m.write(m.reg[6],record,2)
                            return 0x43000000+record*0x100
                        def query(m):
                            fifth=m.read(m.reg[29]+0x10,2)
                            assert m.reg[7]==fifth==0
                            row=dict(list=hex(m.reg[4]),record=m.reg[5],attribute=m.reg[6])
                            queries.append(row)
                            return int(optional_ok or m.reg[6]!=13)
                        def start(m):
                            starts.append((tuple(m.reg[4:8]),m.read(m.reg[29]+0x10)))
                            return 0
                        vm.hooks.update({0x673c8:construct,bridge.QUERY:query,0x4f2a4:start})
                        call(vm,0x58aac,[OWNER,CONNECTION])
                        assert vm.read(OWNER+0x20,1)==1
                        assert vm.read(CONNECTION+0x60,1)==(0 if busy else 1)
                        expected=[]
                        if not busy:
                            if local_tg: expected += [(3,n) for n in (9,0x311,0x102,0x100)]
                            if local_ct: expected += [(4,n) for n in (9,0x311,0x102,0x100,*((13,) if enabled else ()))]
                        assert [(q['record'],q['attribute']) for q in queries]==expected
                        sides.append(dict(constructions=constructions,queries=queries,starts=starts,steps=vm.steps))
                    assert sides[0]['constructions']==sides[1]['constructions']
                    assert sides[0]['starts']==sides[1]['starts']
                    assert sides[0]['queries']==[q for q in sides[1]['queries'] if q['attribute']!=13]
                    traces.append(dict(busy=busy,local_target=local_tg,local_controller=local_ct,
                                       extra_query_success=optional_ok,original=sides[0],bridge=sides[1]))
    return dict(cases=len(traces),instruction_executions=2*len(traces),recipe=recipe,traces=traces,
                native_executed=False,executable_written=False,lgu_built=False,
                limits=['Original discovery constructor/request serializer and physical SDP delivery are fixtures',
                        'Successful/failed extra attribute allocation does not prove complete resource cleanup',
                        'Discovery receive hooks, cover-channel owner and AppMain delivery are not implemented'],
                source_pins={name:hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest() for name in
                             ('bt_cover_art_csr_bridge.py','verify_bt_cover_csr_bridge.py','verify_bt_cover_attribute.py',
                              'patch_usb_seek_completion.py','patch_usb_folders.py','patch_usb_reliability.py',
                              'patch_updater_copy_safety.py','inspect_bt_lifecycle.py','inspect_wave_queue.py',
                              'verify_media_responsiveness.py')})


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input',type=Path,required=True)
    parser.add_argument('--report',type=Path,required=True)
    args=parser.parse_args()
    if args.report.exists(): raise FileExistsError('Use a fresh report')
    result=verify(args.input.read_bytes())
    args.report.parent.mkdir(parents=True,exist_ok=True)
    args.report.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(cases=result['cases'],instruction_executions=result['instruction_executions'],executable_written=False),indent=2))
