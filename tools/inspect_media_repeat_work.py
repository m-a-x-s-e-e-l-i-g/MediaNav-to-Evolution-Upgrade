"""Pin repeated media work in current development without changing its timing."""
import hashlib
import json
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
def inspect(raw):
    original=(ROOT/'extracted/705md/upgrade/Storage Card/System/MgrUSB.exe').read_bytes()
    a=pefile.PE(data=original);b=pefile.PE(data=raw)
    evidence=[]
    for start,end,label in [(0x135f0,0x13630,'sort comparator dispatch'),
          (0x173d8,0x17464,'two temporary sort representations'),
          (0x14720,0x1487c,'linear folder-table next lookup'),
          (0x1b17c,0x1b1c0,'500 ms progress timer setup'),
          (0x1b3b0,0x1b484,'graph position and complete shared status update'),
          (0x20340,0x203a4,'timer 1000 dispatch'),
          (0x24094,0x240b0,'shared writer forwarding'),(0x23c44,0x23cd8,'shared memcpy without mutex')]:
        old=a.get_data(start-0x10000,end-start);new=b.get_data(start-0x10000,end-start)
        assert old==new
        evidence.append(dict(start=hex(start),end=hex(end),meaning=label,bytes=len(new),sha256=hashlib.sha256(new).hexdigest()))
    words=lambda va,n:int.from_bytes(b.get_data(va-0x10000,n),'little')
    assert words(0x1b1a8,4)==0x240601f4 and words(0x1b1b0,4)==0x240503e8
    assert words(0x20380,2)==0x14 # first timer slot targets 20394.
    assert words(0x1b434,4)==0x24070e56
    assert words(0x173f8,4)==words(0x1740c,4)==0x2406040c
    return dict(usb_sha256=hashlib.sha256(raw).hexdigest(),evidence=evidence,
        status=dict(nominal_timer_ms=500,bytes_per_full_copy=3670,writer_has_mutex=False,
                    skip_or_partial_copy_not_implemented=True),
        sorting=dict(memset_bytes_per_compare=2072,other_zero_store_bytes=8,
                     key_build_calls_per_compare=2,normalization_cache_not_implemented=True),
        folders=dict(next_lookup='linear scan with per-entry Sleep(1)',iterator_not_changed=True),
        next_work='Measure and cache filename sort representations per catalog generation/locale; trace folder iterator and snapshot ownership before further optimizations.',
        native_executed=False,native_timing_measured=False)

if __name__=='__main__':
    result=inspect((ROOT/'build/wma-shuffle-development-02/payload/upgrade/Storage Card/System/MgrUSB.exe').read_bytes())
    (ROOT/'analysis/firmware/media-repeat-work-audit.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in result.items() if k!='evidence'},indent=2))
