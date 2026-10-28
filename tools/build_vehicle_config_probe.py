"""Build a standalone read-only CE/MIPS collector; never a firmware payload."""
import argparse, hashlib, json, sys
from pathlib import Path
import pefile
ROOT=Path(__file__).resolve().parents[1]
FROZEN=ROOT/'releases/7.0.6.MAX34/build-sources/tools'
if FROZEN.is_dir():sys.path.append(str(FROZEN))
import build_max34 as compiler
compiler.ROOT=ROOT
compiler.BASE=ROOT/'build/max33-resumable-installer-development-05'

PIN='b93cb55a66c843e1bb5ea34fd58642e451e6b07afcf9f8ccd1fbc762d627e629'
ORDINALS=[168,170,171,553,172,166,160,175,516,858,535,496,461,463,455,509,506]

def build(out,module):
    assert not out.exists(), 'Use a new output directory'
    raw=module.read_bytes();assert hashlib.sha256(raw).hexdigest()==PIN
    out.mkdir(parents=True)
    common_path=ROOT/'tools/issue56_repair.c'
    if not common_path.is_file():common_path=FROZEN/'issue56_repair.c'
    assert hashlib.sha256(common_path.read_bytes()).hexdigest()=='32359ebba0b3c9e86925a0d4e9a6408bd6c8cd50934410cbd85fdc81d05b1e52'
    common=common_path.read_text()
    sha=common[common.index('/* SHA-256'):common.index('static U hash_file')]
    (out/'probe_sha.h').write_text(sha,encoding='ascii')
    pe=pefile.PE(data=raw);sig=pe.get_data(0x14090-pe.OPTIONAL_HEADER.ImageBase,32)
    cbytes=lambda b:'{'+','.join(str(x)for x in b)+'}'
    (out/'probe_pin.h').write_text(f'#define MICOM_BYTES {len(raw)}\nstatic const B micom_hash[32]='+cbytes(bytes.fromhex(PIN))+';\nstatic const B micom_signature[32]='+cbytes(sig)+';\n',encoding='ascii')
    binary,info=compiler.compile_c(out,'MAXConfigProbe.exe',ROOT/'tools/vehicle_config_probe.c',[
        ('COREDLL.dll',0,ORDINALS),('toolhelp.dll',len(ORDINALS),[2,10,11,1])])
    info.update(kind='standalone read-only diagnosis; not firmware',micom_pin=PIN,
                generated_headers={p.name:hashlib.sha256(p.read_bytes()).hexdigest()for p in out.glob('probe_*.h')})
    (out/'build.json').write_text(json.dumps(info,indent=2)+'\n')
    print(out/'MAXConfigProbe.exe')
    return binary,info

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--micom',type=Path,required=True);a=p.parse_args();build(a.output.resolve(),a.micom.resolve())
