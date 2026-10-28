"""Extract only the USB test input from the hash-pinned public MAX33 LGU."""
import argparse,hashlib,io,urllib.request,zipfile
from pathlib import Path
from lgu_repack import unpack,read_member
LGU_SHA='a61665ad388720d24171d84d986bbb93dbfa354c8f4ecaaaf1be9f51840a6b67'
USB_SHA='6783bad9aef974545de7da2b44514c42e96a30a8c031ac3f88573dad9858fda3'
URL='https://github.com/m-a-x-s-e-e-l-i-g/MediaNav-to-Evolution-Upgrade/releases/download/7.0.6.MAX33/upgrade.lgu'

def prepare(lgu,output):
    if output.exists():raise ValueError('Choose a fresh output file')
    if not lgu.exists():
        lgu.parent.mkdir(parents=True,exist_ok=True)
        with urllib.request.urlopen(URL,timeout=120)as response:raw=response.read()
        if hashlib.sha256(raw).hexdigest()!=LGU_SHA:raise ValueError('Public MAX33 LGU hash differs')
        lgu.write_bytes(raw)
    raw=lgu.read_bytes()
    if hashlib.sha256(raw).hexdigest()!=LGU_SHA:raise ValueError('Expected the exact public MAX33 LGU')
    with zipfile.ZipFile(io.BytesIO(unpack(raw)))as archive:
        usb=read_member(archive,'upgrade/Storage Card/System/MgrUSB.exe')
    if hashlib.sha256(usb).hexdigest()!=USB_SHA:raise ValueError('MAX33 USB member hash differs')
    output.parent.mkdir(parents=True,exist_ok=True);output.write_bytes(usb)
    print('Verified exact public MAX33 LGU and USB member; no firmware executed')

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--lgu',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();prepare(a.lgu,a.output)
