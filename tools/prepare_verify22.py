"""Extend the immutable prior fixtures with native immediate-redraw expectations."""
from pathlib import Path
P=Path(__file__).resolve().parent


def main():
    s=(P/'verify_settings20.py').read_text()
    s=s.replace('draw=[]','draw=[];present=[]')
    s=s.replace('0x139020:lambda v:', '0x13d220:lambda v:present.append(tuple(v.reg[4:7])) or 1,\n                                0x139020:lambda v:')
    s=s.replace("                assert not draw, 'Refresh must not draw over old status'", "                assert draw==([ui['button_va'],ui['status_label_va']]*2 if page else [])\n                assert m.read(ui['status_label_va']+0x2c)&0x400, 'Native background restore must be enabled'")
    s=s.replace("assert len(m.invalidations)==1, 'Toggle must request background repaint'", "assert len(m.invalidations)==0, 'Toggle redraw must not erase the whole window'")
    s=s.replace("                cases.append('Settings page='", "                assert present==([(OBJ+4,ui['button_va']+8,0),(OBJ+4,ui['status_label_va']+8,0)]*2 if page else [])\n                cases.append('Settings page='")
    (P/'verify_settings22.py').write_text(s,encoding='utf-8')
    s=(P/'verify_max20.py').read_text();a=s.index('def regression_cases(');b=s.index('\n\n\ndef main()',a);s=s[a:b]
    a=s.index('    # Native refresh');s=s[:a]+'    return cases\n'
    (P/'verify_persistence22.py').write_text('from verify_max20 import Fixture,config_record,reboot\nimport json\nfrom pathlib import Path\n\n'+s,encoding='utf-8')
    s=(P/'verify_max21.py').read_text();a=s.index('def targeted(');b=s.index('\n\n\ndef native_lifetime_cases',a);s=s[a:b]
    s=s.replace("all(n==at or cs<=n<cs+4 for n in differences)","all(n==at or cs<=n<cs+4 or status_begin<=n<status_end for n in differences)")
    needle="    assert len(before)==len(after)"
    s=s.replace(needle,"    r=next(r for r in json.loads((root/'CmnDll.dll.json').read_bytes())['routines'] if r['address']==json.loads((root/'runtime.json').read_bytes())['addresses']['status'])\n    status_begin=cp.get_offset_from_rva(r['address']-cp.OPTIONAL_HEADER.ImageBase);status_end=status_begin+r['bytes']\n"+needle)
    s=s.replace("'entire MAX20 runtime remains byte-exact except diagnostic version and PE checksum'", "'MAX20 runtime differs only in diagnostics header, status notification and checksum'")
    (P/'verify_metrics22.py').write_text('from verify_max21 import fixture,call,STACK,STOP\nfrom verify_max20 import VM\nfrom pathlib import Path\nimport json,struct,pefile\n\n'+s,encoding='utf-8')


if __name__=='__main__':main()
