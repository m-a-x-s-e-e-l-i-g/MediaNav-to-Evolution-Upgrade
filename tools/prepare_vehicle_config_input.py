"""Extract unchanged MICOM from the exact public MAX33 LGU; never execute it."""
import argparse,hashlib,io,urllib.request,zipfile
from pathlib import Path
from lgu_repack import unpack,read_member
from prepare_usb_transition34 import URL,LGU_SHA

MICOM_SHA='b93cb55a66c843e1bb5ea34fd58642e451e6b07afcf9f8ccd1fbc762d627e629'

def prepare(lgu,output):
    if output.exists():raise ValueError('Choose a fresh output file')
    if not lgu.exists():
        with urllib.request.urlopen(URL,timeout=120)as response:raw=response.read()
        if hashlib.sha256(raw).hexdigest()!=LGU_SHA:raise ValueError('Public MAX33 LGU hash differs')
        lgu.parent.mkdir(parents=True,exist_ok=True);lgu.write_bytes(raw)
    raw=lgu.read_bytes()
    if hashlib.sha256(raw).hexdigest()!=LGU_SHA:raise ValueError('Expected the exact public MAX33 LGU')
    with zipfile.ZipFile(io.BytesIO(unpack(raw)))as archive:module=read_member(archive,'upgrade/Storage Card/System/MicomManager.exe')
    if hashlib.sha256(module).hexdigest()!=MICOM_SHA:raise ValueError('MAX33 MICOM member hash differs')
    output.parent.mkdir(parents=True,exist_ok=True);output.write_bytes(module)
    print('Verified public MAX33 LGU and unchanged MICOM input; no native execution')

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--lgu',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();prepare(a.lgu,a.output)
