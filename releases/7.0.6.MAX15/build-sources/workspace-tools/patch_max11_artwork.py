"""Exact MAX10 successor: accept the captured Android OBEX 1.0 CONNECT reply."""
import hashlib
import json
import struct
import sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
REPO=ROOT/'sources/MediaNav-usb-seek-timing'
sys.path.insert(0,str(REPO/'tools'))
import pefile
import layout_bt_cover_native as layout
import bt_cover_art_responses as responses
BASE=0x10000
SYSTEM=Path('upgrade/Storage Card/System')
PREVIOUS=REPO/'build/maxmade-7.0.6.MAX10-local-01/roundtrip'
NATIVE=REPO/'build/maxmade-7.0.6.MAX05-local/payload'
OUT=ROOT/'build/max11-artwork-development-01'
PINS={'Blue.exe':'13b6590ac561e9a5244186336ec62909cbcfd80786f032a41bff9aa151529d66',
      'AppMain.exe':'49d4a9a2e3d746c4e5e0a9a7d1f92baa51e53d7dd65a7e5f25636d6cf89a3350'}
def sha(raw):return hashlib.sha256(raw).hexdigest()
def blue(raw):
    assert sha(raw)==PINS['Blue.exe'];pe=pefile.PE(data=raw)
    row=next(r for r in layout.plan('Blue.exe',(NATIVE/SYSTEM/'Blue.exe').read_bytes())['helpers']
             if r['address']==responses.CONNECT)
    assert pe.get_data(row['address']-BASE,len(row['raw']))==row['raw']
    matches=[i for i in range(0,len(row['raw']),4) if row['raw'][i:i+4]==struct.pack('<I',0x2d080015)]
    assert len(matches)==1
    at=row['address']+matches[0];offset=pe.get_offset_from_rva(at-BASE)
    out=bytearray(raw);before=raw[offset:offset+4];out[offset:offset+4]=struct.pack('<I',0x2d080010)
    check=pe.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum')
    struct.pack_into('<I',out,check,0)
    struct.pack_into('<I',out,check,pefile.PE(data=bytes(out)).generate_checksum())
    result=bytes(out);allowed=set(range(offset,offset+4))|set(range(check,check+4))
    assert len(raw)==len(result) and all(a==b or i in allowed for i,(a,b) in enumerate(zip(raw,result)))
    return result,dict(input_sha256=sha(raw),sha256=sha(result),
                       edits=[dict(address=at,offset=offset,before_hex=before.hex(),after_hex=out[offset:offset+4].hex(),
                                   purpose='Accept actual Android OBEX 1.0 success response; retain all header/CID/WHO/MTU checks')],
                       audio_title_UI_and_all_other_bytes_equal_MAX10=True,hardware_tested=False)
def app(raw):
    assert sha(raw)==PINS['AppMain.exe']
    return raw,dict(input_sha256=sha(raw),sha256=sha(raw),edits=[],byte_identical_MAX10=True,hardware_tested=False)
def build():
    OUT.mkdir(parents=True,exist_ok=False);report={}
    for name,fn in (('Blue.exe',blue),('AppMain.exe',app)):
        result,recipe=fn((PREVIOUS/SYSTEM/name).read_bytes());(OUT/name).write_bytes(result);report[name]=recipe
    (OUT/'recipe.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    return dict(output=str(OUT),modules={n:r['sha256'] for n,r in report.items()})
if __name__=='__main__':print(json.dumps(build(),indent=2))
