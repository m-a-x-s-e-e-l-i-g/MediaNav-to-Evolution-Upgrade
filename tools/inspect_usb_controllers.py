"""Offline USB host/device controller and mass-storage evidence from original ROM bytes."""
import hashlib
import json
import re
import struct
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
SOURCES={
    "USBware.dll":"85dd9e9a711d356111fc592072fd7507205d18e0a56b0ec5d5396509384d0ef2",
    "USBware2.dll":"ca083a856a7aa6b7a74792f9775e534a84583c01a48760a09a51266c4136eaab",
}
FUNCTIONS={
    "USBware.dll":[0xc09f3be8,0xc09f3fdc,0xc09f41c4,0xc09f44c0,0xc09f4650,
                   0xc09f46f0,0xc09f49e8,0xc09f4b88,0xc09f4d80,0xc09f4f60,
                   0xc09f50c4,0xc09f53cc,0xc09f5468,0xc09f5690,0xc09f67b4,
                   0xc09f8c18],
    "USBware2.dll":[0xc08220d0,0xc08222f8,0xc0822320,0xc08223e4,0xc08224d0,
                    0xc082273c,0xc0822b58,0xc0822e18,0xc082327c,0xc0823844,
                    0xc0823ab0,0xc0823e90,0xc0825818,0xc08308e8,0xc0832630,
                    0xc0836900,0xc08374ac,0xc0837664],
}


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources=[];pes={}
    for name,digest in SOURCES.items():
        module=next(m for m in modules if m["origin"]=="rom" and m["name"]==name)
        path=ROOT/module["path"]
        if hashlib.sha256(path.read_bytes()).hexdigest()!=digest:raise ValueError("Source changed")
        pe=pefile.PE(str(path));pes[name]=pe
        index=json.loads((ROOT/"analysis/functions/rom"/(name+".json")).read_text(encoding="utf-8"))
        functions={int(f["begin_va"],16):f for f in index["functions"]}
        evidence=[]
        ranges=[(va,int(functions[va]["end_va"],16)-va,"Original .pdata function") for va in FUNCTIONS[name]]
        if name=="USBware.dll":
            ranges += [(0xc09facf4,0xa4,"Host hardware initialization"),
                       (0xc09fad98,24,"Original leaf: two host-controller entries"),
                       (0xc09fadc4,12,"Original leaf: profile suffix"),
                       (0xc0a34178,0xf8,"Host MMIO/resource/controller/profile tables"),
                       (0xc09f1830,8,"RMD UTF16 prefix"),
                       (0xc09f1e34,6,"MD UTF16 suffix and folder")]
        else:
            ranges += [(0xc08390d0,0x68,"Controller filter and default device configuration"),
                       (0xc0839214,18,"Device descriptor template")]
        for va,size,role in ranges:
            raw=pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase,size)
            if len(raw)!=size:raise ValueError("Truncated evidence")
            evidence.append(dict(va=hex(va),size=size,role=role,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        sources.append(dict(name=name,sha256=digest,evidence=evidence))
    host=pes["USBware.dll"];base=host.OPTIONAL_HEADER.ImageBase
    controllers=[]
    for i in range(2):
        va=0xc0a34248+i*16
        kind,resources,count,unused=struct.unpack("<4I",host.get_data(va-base,16))
        resource_list=[]
        for j in range(count):
            rva=resources+j*12
            identifier,rtype,pointer=struct.unpack("<3I",host.get_data(rva-base,12))
            size=12 if rtype==2 else 4
            values=struct.unpack("<"+"I"*(size//4),host.get_data(pointer-base,size))
            resource_list.append(dict(identifier=identifier,type=rtype,pointer=hex(pointer),values=[hex(v) for v in values]))
        controllers.append(dict(table_va=hex(va),type=hex(kind),resources=resource_list,unused=unused))
    dev=pes["USBware2.dll"]
    supported=struct.unpack("<2I",dev.get_data(0xc08390d0-dev.OPTIONAL_HEADER.ImageBase,8))
    assert supported==(0x2012,0)
    registry=(ROOT/"analysis/firmware/boot-registry/default.validated.reg").read_text(encoding="utf-16")
    records=[]
    for i in range(5):
        pattern=r"\[HKEY_LOCAL_MACHINE\\Drivers\\BuiltIn\\UDD\\Controller"+str(i)+r"\]\s*(.*?)(?=\n\[)"
        block=re.search(pattern,registry,re.S)[1]
        values={m[1]:int(m[2],16) for m in re.finditer(r'"([^"]+)"=dword:([0-9a-fA-F]+)',block)}
        desc=re.search(r'"Desc"="([^"]+)"',block)[1]
        records.append(dict(index=i,description=desc,values=values,
                            selected_by_this_binary=values["Type"] in supported))
    assert [r["index"] for r in records if r["selected_by_this_binary"]]==[1]
    result=dict(binary_execution=False,sources=sources,host_controllers=controllers,
        device_controller_filter=[hex(x) for x in supported],device_registry_controllers=records,
        device_identity=dict(vendor=0x045e,product=0x00ce,release=0),
        mass_storage=dict(prefix="RMD",profile_suffix="MD",folder="MD",
                          profiles=["UWHD_Profile_MD","UWCD_Profile_MD","UWFD_Profile_MD"],
                          read_codes=[2,0x75c08],write_codes=[3,0x79c0c],
                          scsi_packet_codes=[0x4d004,0x4d014]),
        caveat="Controller register labels, USB role exposure and active unit states require further evidence")
    (ROOT/"analysis/firmware/usb-controller-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(source_modules=2,evidence_ranges=sum(len(s["evidence"]) for s in sources),
                         host_controllers=len(controllers),selected_device_controllers=[r["index"] for r in records if r["selected_by_this_binary"]]),indent=2))


if __name__=="__main__":main()
