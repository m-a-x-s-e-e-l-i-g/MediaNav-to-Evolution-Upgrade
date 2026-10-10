"""Preserve static boot/reboot/desktop helper contracts; never run these binaries."""
import hashlib
import json
from functools import reduce
from operator import xor
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
SOURCES={
 "cereboot.exe":("705md","65785ef321ca4fbc89dce3d31bfb913b83cdf9d10e3458cad7b39a84c397f921",
 [(0x11000,0x5c,"Window enumeration"),(0x1105c,0xc4,"Close/terminate application"),
  (0x11120,0x2fc,"Confirmed reboot sequence"),(0x1146c,0x150,"COM2 configuration"),
  (0x116bc,0x1ac,"Response collection/XOR"),(0x11868,0x19c,"Normal AA sender"),
  (0x11a04,0x1a4,"AA memory-write sender"),(0x12000,0xf8,"CRT calls application entry")]),
 "dmenu.exe":("705md","351161c5ace16a88dc9737bfdb6b6905e33b0a87c217054366387d28c92f35b3",
 [(0x11020,0x150,"COM2 configuration"),(0x11270,0x1ac,"Response collection/XOR"),
  (0x1141c,0x19c,"Normal AA sender"),(0x115b8,0x1a4,"AA memory-write sender"),
  (0x11864,0xc4,"Close/terminate application"),(0x11928,0x2d0,"Reboot sequence"),
  (0x11c28,0x74,"StartWinCE marker before reboot"),(0x11c9c,0x800,"Window paint and button events"),
  (0x124ec,0xf4,"800x480 foreground window"),(0x125e0,0x68,"Message loop")]),
 "dboot.exe":("705md","a7cddff89aeed7970b332b2fb7f2c579e5fc68ce8c4d03875d7167cddb70546c",
 [(0x11240,0x118,"Desktop shortcut creation"),(0x113d4,0x68,"Consume marker and launch Explorer"),
  (0x175b8,0x238,"Horizontal drag opens dmenu"),(0x17998,0x22c,"Main boot selection")]),
 "USB_PHY_enable.exe":("rom","5a8d30fa17120919c7817c3d8cb42f9e38ce02472fe2ebe2e7c949742e221792",
 [(0x11074,0xac,"MGR1 code3 byte1"),(0x11478,0xf8,"CRT calls helper")]),
 "sdmemory.dll":("rom","001682ab63e2f3cdf5860b1fcc1a35b2ea90b08432950310cae7f31b78f76f3b",
 [(0xc07218f8,0x914,"DSK_IOControl incl sleep validation/result conversion"),
  (0xc0722f98,0x124,"Card command7 / standby check, max3 attempts"),
  (0xc07230bc,0xd4,"IOCTL preamble/state gate")])}


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"));out=[]
    for name,(origin,digest,ranges)in SOURCES.items():
        source=next(m for m in modules if m["name"]==name and m["origin"]==origin)
        path=ROOT/source["path"]
        if hashlib.sha256(path.read_bytes()).hexdigest()!=digest:raise ValueError(f"Source changed: {name}")
        pe=pefile.PE(str(path));evidence=[]
        for va,size,role in ranges:
            raw=pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase,size)
            if len(raw)!=size:raise ValueError("Truncated original evidence")
            evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        out.append(dict(name=name,origin=origin,sha256=digest,evidence=evidence))
    memory_header=bytes.fromhex("aa160206010000001700")
    normal_header=bytes.fromhex("aa010100")
    frames=[dict(role="Memory write address1 valueWORD17",hex=(memory_header+bytes([reduce(xor,memory_header,0)])).hex()),
            dict(role="Normal group0 command1 empty payload",hex=(normal_header+bytes([reduce(xor,normal_header,0)])).hex())]
    result=dict(binary_execution=False,sources=out,static_frame_models=frames,
                caveat="Models describe byte construction only; MCU interpretation and hardware reboot outcome remain unverified")
    (ROOT/"analysis/firmware/boot-helper-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(source_modules=len(out),static_frame_models=frames),indent=2))


if __name__=="__main__":main()
