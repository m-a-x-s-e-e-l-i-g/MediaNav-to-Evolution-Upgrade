"""Preserve native metadata/graph evidence and test bounded arithmetic models offline."""
import hashlib
import json
import struct
import uuid
from pathlib import Path
import pefile
from inspect_usb_playlist import USB_HASH
from parse_usb_tags import parse_id3, parse_asf, self_test, ASF_HEADER, ASF_EXTENDED

ROOT=Path(__file__).resolve().parents[1]
IMAGING_HASH="f7592cc3360d97674a189c60b7d56e75a15ad2bceafe5eef6da47e8f20b70908"


def syn(n):
    return bytes((n>>s)&127 for s in (21,14,7,0))


def byte_copy(text,count):
    source=text.encode("utf-16le",errors="surrogatepass")+b"\0"*520
    target=bytearray(520);target[:count]=source[:count]
    units=struct.unpack("<260H",target)
    end=next((i for i,v in enumerate(units) if v==0),len(units))
    return bytes(target[:end*2]).decode("utf-16le",errors="surrogatepass")


def graph_states(kind,states):
    # Pure projection of VALID GetState output only. Never performs COM calls or waits.
    calls=[];done=False
    for state in states[:1001]:
        if state==2:calls.append("Pause")
        elif state==1:
            if kind=="real_pause":done=True
            else:calls.append("Stop")
        elif state==0:done=True
        else:raise ValueError("invalid FilterState")
        if done:break
    success=done or (kind=="stop" and len(states)>=1001)
    return dict(calls=calls,observed_target=done,success=success,
        cached_state=(3 if kind=="stop" else 1) if success else None)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    evidence=[];readers={}
    specifications=[("705md","MgrUSB.exe",USB_HASH,
        [0x11054,0x114a0,0x11568,0x11790,0x11918,0x11ab0,0x11e20,0x11e7c,0x11f78,0x12264,
        0x12844,0x129c8,0x24a90,
        0x17468,0x174f8,0x17500,0x177c0,0x178bc,0x182dc,0x18f84,0x19254,0x19478,0x19508,
        0x19d3c,0x1a0d4,0x1a318,0x20a38,0x24b90,0x24c44,0x24ca4,0x24cf8,0x24e04,0x245f0],
        {0x174f8:8,0x177c0:0xbc,0x24c44:0x60},
        [(0x2884c,48),(0x2887c,72),(0x288c4,96),(0x28e70,32)]),
        ("rom","imaging.dll",IMAGING_HASH,[0x40486d98],{},[(0x404810d0,16),(0x4048127c,16)])]
    for origin,name,expected,addresses,leaves,tables in specifications:
        module=next(m for m in modules if m["origin"]==origin and m["name"]==name)
        path=ROOT/module["path"];assert hashlib.sha256(path.read_bytes()).hexdigest()==expected
        pe=pefile.PE(str(path));base=pe.OPTIONAL_HEADER.ImageBase
        funcs=json.loads((ROOT/f"analysis/functions/{origin}/{name}.json").read_text(encoding="utf-8"))["functions"]
        by_va={int(f["begin_va"],16):f["bytes"] for f in funcs}
        ranges=[(a,by_va[a] if a in by_va else leaves[a]) for a in addresses]+tables
        records=[]
        for va,size in ranges:
            raw=pe.get_data(va-base,size);assert len(raw)==size
            records.append(dict(va=hex(va),bytes=size,boundary="pdata" if va in by_va else
                "bounded leaf span" if va in leaves else "data table",
                raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        evidence.append(dict(module=name,origin=origin,path=module["path"],sha256=expected,ranges=records))
        readers[name]=lambda va,n,pe=pe,base=base:pe.get_data(va-base,n)
    usb=readers["MgrUSB.exe"];imaging=readers["imaging.dll"]
    frame_tables=[]
    for va,n in [(0x2887c,8),(0x288c4,11)]:
        records=[]
        for i in range(n):
            ident,key=struct.unpack("<4sI",usb(va+i*8,8))
            records.append(dict(id=ident.decode("ascii"),handler=hex(key)))
        assert usb(va+n*8,8)==b"\0"*8
        frame_tables.append(dict(va=hex(va),frames=records))
    guid=lambda raw:str(uuid.UUID(bytes_le=raw))
    guids={hex(va):guid(usb(va,16)) for va in [0x2884c,0x2885c,0x2886c,0x28e70,0x28e80]}
    assert guids["0x28e70"]==guid(imaging(0x404810d0,16))==guid(imaging(0x4048127c,16))
    assert guids["0x2884c"]==guid(ASF_HEADER)
    # V4 sizes: a finite exhaustive range spanning all low-byte transitions.
    length_cases=[];disagree=0
    for n in range(4097):
        raw=syn(n);be=int.from_bytes(raw,"big");disagree+=be!=n
        assert (be==n)==(n<128)
        if n in [0,1,127,128,255,256,4095,4096]:
            length_cases.append(dict(reference=n,size_hex=raw.hex(),native=be))
    bounds=[]
    for header in [6,10]:
        for remaining in range(header,65):
            for size in range(1,65):
                accepted=size<=remaining;correct=size<=remaining-header
                wrapped=(remaining-header-size)&0xffffffff
                if accepted and not correct:assert wrapped>0xffffff00
                bounds.append((accepted,correct,remaining==header+size))
    copy_cases=[]
    for count,index in [(129,64),(259,128)]:
        for char in ["A","\u65e5","\u0100","\U0001f600"]:
            src="x"*index+char+"rest";result=byte_copy(src,count)
            assert result[:index]=="x"*index
            copy_cases.append(dict(bytes=count,input=src,output=result))
    assert copy_cases[1]["output"].endswith("\u00e5")
    stride_cases=[];widths_correct=0
    for width in range(1,801):
        actual=(3*width+3)&~3;native=3*width+2
        assert (native==actual)==(width%4==2)
        widths_correct+=native==actual
        for height in [1,2,278,480]:
            last_end=(height-1)*native+3*width;allocated=actual*height
            if width in [1,2,3,4,277,278,279,280,800]:
                stride_cases.append(dict(width=width,height=height,dib_stride=actual,native_stride=native,
                    access_end=last_end,allocated=allocated,overrun_bytes=max(0,last_end-allocated)))
    events=[]
    for code in [1,2,3,6,7,10,0x49,255]:
        for active in [False,True]:
            for param2 in [0,1]:
                for elapsed in [0,1,299,300,301,0xffffffff]:
                    for resume in [False,True]:
                        accepted=code==1 and active and param2==0 and elapsed>=300
                        action=("seek_zero" if resume else "self_command_6c") if accepted else "log_only"
                        events.append(dict(code=code,active=active,param2=param2,elapsed=elapsed,
                            resume=resume,action=action,event_parameters_freed=True))
    # Unsigned tick wrap is accepted at exactly 300 ms.
    assert ((0x1c-0xfffffef0)&0xffffffff)==300
    states=[]
    for kind in ["stop","real_pause","pause"]:
        for seq in [[2,1,0],[1,0],[0],[2]*1001,[1]*1001]:
            r=graph_states(kind,seq)
            if seq==[2]*1001:assert r["success"]==(kind=="stop")
            if kind=="real_pause" and seq[0]==1:assert r["calls"]==[] and r["success"]
            states.append(dict(kind=kind,state_prefix=seq[:4],state_count=len(seq),
                result={**r,"calls":r["calls"][:4],"call_count":len(r["calls"])}))
    # A long descriptor is harmless in this bounded reference parser; native diagnostics flag its size.
    name=("N"*130+"\0").encode("utf-16le");value=b"\0\0"
    body=struct.pack("<HH",1,len(name))+name+struct.pack("<HH",0,len(value))+value
    obj=ASF_EXTENDED+struct.pack("<Q",24+len(body))+body
    asf=ASF_HEADER+struct.pack("<QI2B",30+len(obj),1,1,2)+obj
    long_name=parse_asf(asf)["objects"][0]["descriptors"][0]
    assert long_name["native_name_overruns_destination"] and long_name["native_name_copy_bytes"]==262
    checks=dict(preserved_ranges=sum(len(e["ranges"]) for e in evidence),frame_tables=2,
        frame_length_cases=4097,frame_length_disagreements=disagree,frame_bounds_cases=len(bounds),
        native_bounds_false_accepts=sum(a and not c for a,c,_ in bounds),
        exact_final_frame_skips=sum(s for _,_,s in bounds),utf16_byte_copy_cases=len(copy_cases),
        cover_widths=800,cover_widths_matching_dib=widths_correct,event_cases=len(events),
        graph_state_traces=len(states),parser=self_test(),long_asf_descriptor_fixture=True)
    result=dict(binary_execution=False,evidence=evidence,frame_tables=frame_tables,guids=guids,
        metadata_object=dict(zeroed_bytes=0xe44,cover_buffer_bytes=0x800000,
            fields={"artist":0,"album":0x208,"title":0x410,"genre":0x618,
                "raw_artist":0x820,"raw_album":0x924,"raw_title":0xa28,"raw_genre":0xb2c,
                "cover_format":0xc30,"cover_bytes":0xc34,"cached_path":0xc38,
                "flags":0xe40,"cover_buffer_pointer":0xe44},
            flags={"title":1,"album":2,"artist":4,"cover":8,"genre":16,"normal_exit_or_error":128}),
        id3_v4_lengths=length_cases,utf16_byte_copies=copy_cases,cover_stride_cases=stride_cases,
        events=events,graph_state_traces=states,long_asf_descriptor=long_name,checks=checks,
        limitations=["Arithmetic models do not execute firmware, COM, image codecs or filesystem operations",
            "Event timestamp inputs are deltas; queued events, dispatcher concurrency and sleep scheduling are excluded",
            "Graph-state model assumes valid GetState output; HRESULT failures and null-control branches are excluded",
            "Reference parser limitations are explicit in its ID3 result; it is not a complete ID3/ASF conformance validator",
            "Native overflow and uninitialized-read paths are evidenced statically; exploitability/runtime symptoms were not tested"])
    (ROOT/"analysis/firmware/usb-metadata-contracts.json").write_text(json.dumps(result,indent=2,ensure_ascii=True),encoding="utf-8")
    print(json.dumps(dict(status="passed",**checks),indent=2))


if __name__=="__main__":main()
