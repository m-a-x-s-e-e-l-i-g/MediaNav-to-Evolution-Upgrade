"""Check native artwork layout, state boundaries and AppMain pointer relocations.

Execute moved query/reset/clear helpers. Check all AppMain LA/JAL operands under
image-base changes. This writes reports only, not a PE or an LGU.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

import pefile

import layout_bt_cover_native as layout
from inspect_bt_pairing import data,put
from verify_bt_cover_csr_bridge import VM
from verify_bt_cover_owner import Image
from verify_media_responsiveness import call,STACK

ROOT=Path(__file__).resolve().parents[1]


class DataVM(VM):
    def __init__(self,original,p):
        self.allowed=[(layout.DATA_BASE,layout.DATA_BASE+layout.DATA_SIZE),(STACK-0x600,STACK+0x80)]
        super().__init__(Image(original,p['helpers']),[(r['address'],r['address']+len(r['raw'])) for r in p['helpers']])
        put(self,layout.DATA_BASE,p['data'])

    def read(self,at,size=4):
        assert any(lo<=at and at+size<=hi for lo,hi in self.allowed),('Layout read outside RW/stack',hex(at))
        return super().read(at,size)

    def write(self,at,value,size=4):
        assert any(lo<=at and at+size<=hi for lo,hi in self.allowed),('Layout write outside RW/stack',hex(at))
        super().write(at,value,size)


def moved_words(row,delta):
    raw=bytearray(row['raw'])
    for rva,kind,companion in row['relocations']:
        off=rva+layout.IMAGE_BASE-row['address'];word=struct.unpack_from('<I',raw,off)[0]
        if kind==2:struct.pack_into('<H',raw,off,((word&65535)+delta)&65535)
        elif kind==4:
            signed=companion if companion<32768 else companion-65536
            hi=(((word&65535)<<16)+signed+delta+32768)>>16
            struct.pack_into('<H',raw,off,hi&65535)
        elif kind==5:
            assert word>>26 in (2,3)
            target=(((word&0x3ffffff)<<2)+delta)>>2
            struct.pack_into('<I',raw,off,(word&0xfc000000)|(target&0x3ffffff))
        else:raise AssertionError(kind)
    return bytes(raw)


def operands(row,raw):
    pc=row['address'];result=[]
    for line in row['recipe']['source_assembly'].splitlines():
        line=line.strip()
        if not line or line.endswith(':'):continue
        off=pc-row['address']
        if line.startswith('la '):
            expected=int(line.rsplit(',',1)[1].strip(),0)
            high,low=struct.unpack_from('<II',raw,off)
            assert high>>26==15 and low>>26==9
            assert (high>>16)&31==(low>>21)&31==(low>>16)&31
            signed=(low&65535) if low&65535<32768 else (low&65535)-65536
            actual=(((high&65535)<<16)+signed)&0xffffffff
            result.append((pc,'la',expected,actual))
        elif line.startswith(('jal ','j ')):
            expected=int(line.split()[1],0);word=struct.unpack_from('<I',raw,off)[0]
            assert word>>26 in (2,3)
            result.append((pc,'jump',expected,(word&0x3ffffff)<<2))
        pc+=8 if line.startswith('la ') else 4
    return result


def verify(blue_raw,app_raw):
    ps={n:layout.plan(n,r) for n,r in (('Blue.exe',blue_raw),('AppMain.exe',app_raw))}
    rows=[];summary={}
    for name,p in ps.items():
        covered=set()
        for r in p['helpers']:
            for at,kind,expected,actual in operands(r,r['raw']):assert expected==actual
            covered.update(r['changed_instructions'])
            assert p['code'][r['address']-p['code_address']:r['address']-p['code_address']+len(r['raw'])]==r['raw']
        assert len(covered)==sum(len(r['changed_instructions']) for r in p['helpers'])
        # Native code is not allowed to materialize an old mutable pointer.
        for r in p['helpers']:
            for at,kind,expected,actual in operands(r,r['raw']):
                assert not any(old<=actual<=old+n for old,n,_,_ in layout.STATE[name]),(name,hex(at),hex(actual))
        summary[name]=dict(helpers=len(p['helpers']),code_address=hex(p['code_address']),code_bytes=len(p['code']),
                           code_sha256=hashlib.sha256(p['code']).hexdigest(),data_address=hex(p['data_address']),
                           data_bytes=len(p['data']),data_sha256=hashlib.sha256(p['data']).hexdigest(),
                           operand_changes=sum(len(r['operand_changes']) for r in p['helpers']),
                           changed_instructions=len(covered),state_remaps=p['state_remaps'],code_moves=p['code_moves'],
                           permissions=p['permissions'],function_rows=len(p['pdata']),
                           section_headers_available=p['section_headers_available'])
        rows.append(dict(case='all_helpers_reassembled_with_only_reviewed_operand_changes_'+name))

    p=ps['Blue.exe'];m=DataVM(pefile.PE(data=blue_raw),p)
    put(m,layout.DATA_BASE,bytes([0xa5])*layout.DATA_SIZE)
    assert call(m,0x264400,[])==1
    after=data(m,layout.DATA_BASE,layout.DATA_SIZE)
    expected=bytearray([0xa5])*layout.DATA_SIZE
    slot=layout.mapped('Blue.exe',0x261000)-layout.DATA_BASE
    expected[slot+32:slot+52]=bytes(20);expected[slot+64:slot+320]=bytes(256)
    assert after==bytes(expected),'Moved collector clear escaped its own ranges'
    rows.append(dict(case='native_metadata_reset_uses_moved_one_past_end_and_preserves_neighbor_state'))

    for extra_ok in (False,True):
        m=DataVM(pefile.PE(data=blue_raw),p);queries=[]
        def query(vm):
            a=vm.reg[4:8];fifth=vm.read(vm.reg[29]+0x10,2)
            queries.append((a[:],fifth))
            return int(extra_ok) if len(queries)==2 else 0x12345678
        m.hooks[0x67be0]=query
        assert call(m,0x233000,[10,20,1,0],[0x11])==0x12345678
        assert queries==[([10,20,1,0],0x11),([10,20,13,0],0)]
        rows.append(dict(case='relocated_query_preserves_original_and_optional_result_'+str(extra_ok)))

    p=ps['AppMain.exe'];m=DataVM(pefile.PE(data=app_raw),p)
    put(m,layout.DATA_BASE,bytes([0xa5])*layout.DATA_SIZE)
    display=layout.mapped('AppMain.exe',0x234014);m.write(display,0)
    before=data(m,layout.DATA_BASE,layout.DATA_SIZE)
    assert call(m,0x233800,[])==0
    expected=bytearray(before);off=display-layout.DATA_BASE;expected[off:off+12]=bytes(12)
    assert data(m,layout.DATA_BASE,layout.DATA_SIZE)==bytes(expected)
    rows.append(dict(case='native_gui_clear_writes_only_moved_display_fields'))

    for delta in (0x1000,0x10000,0x123000):
        pointers=constants=0
        for r in p['helpers']:
            raw=moved_words(r,delta);rel={rva+layout.IMAGE_BASE for rva,_,_ in r['relocations']}
            for at,kind,expected,actual in operands(r,raw):
                if at in rel:assert actual==expected+delta;pointers+=1
                else:
                    assert expected in layout.CONSTANTS and actual==expected
                    constants+=1
        assert pointers and constants
        rows.append(dict(case='all_AppMain_pointer_operands_rebase_without_capacity_or_ROP_changes',
                         delta=delta,pointers=pointers,constants=constants))

    for name,p in ps.items():
        ends=[layout.mapped(name,old+n) for old,n,_,_ in layout.STATE[name]]
        assert ends==[new+n for _,n,new,_ in layout.STATE[name]]
        for old,n,new,_ in layout.STATE[name]:
            assert new+n<=layout.DATA_BASE+layout.DATA_SIZE
        rows.append(dict(case='all_state_start_and_one_past_end_addresses_share_RW_bank_'+name))

    return dict(cases=len(rows),traces=rows,modules=summary,executable_written=False,lgu_built=False,hardware_tested=False,
                limits=['No executable has these sections or hooks yet; bank bytes and new function rows are only a prepared layout',
                        'All helper instructions are byte-compared; only reviewed address operands change',
                        'Moved metadata reset, GUI clear and optional SDP query instructions execute with strict RW/stack boundaries',
                        'AppMain pointer operands are checked at three image-base deltas; actual PE relocation-directory construction and CE loader execution remain open',
                        'Native unwind/exception dispatch, integrated remapped pipeline, complete PE/LGU composition and hardware validation remain open'],
                source_pins={n:hashlib.sha256((ROOT/'tools'/n).read_bytes()).hexdigest() for n in
                             ('layout_bt_cover_native.py','verify_bt_cover_layout.py','bt_cover_art_publisher.py',
                              'bt_cover_art_app_lifetime.py','bt_cover_art_app_paint.py','bt_cover_art_worker.py',
                              'bt_cover_art_csr_bridge.py','patch_usb_seek_completion.py','patch_usb_folders.py','patch_usb_reliability.py')})


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--blue',type=Path,required=True);p.add_argument('--app',type=Path,required=True)
    p.add_argument('--report',type=Path,required=True);a=p.parse_args()
    if a.report.exists():raise FileExistsError('Use a fresh report')
    report=verify(a.blue.read_bytes(),a.app.read_bytes());a.report.parent.mkdir(parents=True,exist_ok=True)
    a.report.write_bytes((json.dumps(report,indent=2)+'\n').encode())
    print(json.dumps(dict(cases=report['cases'],modules=report['modules'],executable_written=False,lgu_built=False),indent=2))
