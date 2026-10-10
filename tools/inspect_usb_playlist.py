"""Preserve USB catalog/shuffle/repeat and DirectShow evidence, offline only."""
import hashlib
import itertools
import json
import struct
import uuid
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
USB_HASH = "bb435bc428664845a21ffe7bce7a813db06b7e7f92408d297dbbeade94507cd2"
CORE_HASH = "1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c"
# Bounded leaf spans to the next export entry; these leaves have no .pdata record.
LEAF_SPANS={0x12b2c:0x38,0x12ba8:0x44,0x12bec:0x44,0x12c30:0x38,
    0x12c68:0x44,0x12cac:0x50,0x12cfc:0x50,0x12ed8:0x38,0x12f10:0x38,
    0x12f48:0x38,0x146ec:0x34,0x14ab8:0x48,0x19ae0:0x18}
GUIDS = {
    0x2d2bc:("CLSID_FilterGraph","e436ebb3-524f-11ce-9f53-0020af0ba770"),
    0x2e32c:("IGraphBuilder","56a868a9-0ad4-11ce-b03a-0020af0ba770"),
    0x2cbcc:("IMediaControl","56a868b1-0ad4-11ce-b03a-0020af0ba770"),
    0x2cbec:("IMediaEventEx","56a868c0-0ad4-11ce-b03a-0020af0ba770"),
    0x2e25c:("IMediaSeeking","36b73880-c2c8-11cf-8b46-00805f6cef60"),
    0x2cc0c:("IBasicAudio","56a868b3-0ad4-11ce-b03a-0020af0ba770"),
    0x2cbfc:("IMediaPosition","56a868b2-0ad4-11ce-b03a-0020af0ba770"),
}


def shuffle_pool(tracks, choices, anchor=None):
    """Native swap-with-last selection, bounded to the scanner's valid domain."""
    pool=list(tracks)
    if len(pool)>5000 or len(set(pool))!=len(pool): raise ValueError("invalid pool")
    if anchor is not None and anchor not in pool: raise ValueError("missing anchor")
    choices=iter(choices); result=[]
    while len(pool)>1:
        selected=pool.index(anchor) if not result and anchor is not None else next(choices)%len(pool)
        result.append(pool[selected]); pool[selected]=pool[-1]; pool.pop()
    return result+pool


def auto_next(groups, current, repeat, shuffled=False):
    """Valid catalog/no BT-call/no COM-failure projection of 1d23c and 1cf38."""
    order=[t for group in groups for t in group]
    if not order or any(not g for g in groups) or len(set(order))!=len(order):
        raise ValueError("invalid catalog")
    cursor=order.index(current)
    group=next(g for g in groups if current in g)
    if repeat==1: return current
    if repeat==2: return group[(group.index(current)+1)%len(group)]
    if repeat==3: return order[(cursor+1)%len(order)]
    if cursor==len(order)-1: return None
    return order[cursor+1]


def music_record(raw):
    if len(raw)!=0x210: raise ValueError("record must be 528 bytes")
    units=struct.unpack("<260H",raw[:0x208])
    if 0 not in units: raise ValueError("unterminated UTF16 name")
    stop=units.index(0)*2
    return dict(name=raw[:stop].decode("utf-16le",errors="surrogatepass"),
        parent_folder=struct.unpack_from("<h",raw,0x208)[0],
        absolute_path_flag=struct.unpack_from("<I",raw,0x20a)[0],
        media_type=struct.unpack_from("<h",raw,0x20e)[0])


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    specs=[("705md","MgrUSB.exe",USB_HASH,[0x11000,0x11054,0x1111c,0x11f78,0x12264,
        0x12aa4,0x12b2c,0x12b64,0x12ba8,0x12bec,0x12c30,0x12c68,0x12cac,0x12cfc,
        0x12e1c,0x12ed8,0x12f10,0x12f48,0x12f80,0x131c8,0x13350,0x13894,
        0x13d88,0x14390,0x146ec,0x14720,0x14ab8,0x14b00,0x15a94,
        0x198e4,0x19ae0,0x19af8,0x19c94,0x1afbc,0x1b544,0x1b5b0,
        0x1cf38,0x1d23c,0x1ddb0,0x1dd94,0x1ddcc,0x20eac,0x21d00,0x22a8c,0x22f54]),
        ("rom","coredll.dll",CORE_HASH,[0x4007d638,0x400346c8])]
    sources=[]; guids=[]
    for origin,name,expected,addresses in specs:
        m=next(m for m in modules if m["origin"]==origin and m["name"]==name)
        p=ROOT/m["path"]; assert hashlib.sha256(p.read_bytes()).hexdigest()==expected
        pe=pefile.PE(str(p)); base=pe.OPTIONAL_HEADER.ImageBase
        funcs=json.loads((ROOT/f"analysis/functions/{origin}/{name}.json").read_text(encoding="utf-8"))["functions"]
        by_va={int(f["begin_va"],16):f["bytes"] for f in funcs}
        ranges=[(va,by_va[va] if va in by_va else LEAF_SPANS[va]) for va in addresses]
        if name=="MgrUSB.exe":
            ranges += [(va,16) for va in GUIDS]
            for va,(meaning,expected_guid) in GUIDS.items():
                value=str(uuid.UUID(bytes_le=pe.get_data(va-base,16)))
                assert value==expected_guid
                guids.append(dict(va=hex(va),meaning=meaning,guid=value))
        evidence=[]
        for va,size in ranges:
            raw=pe.get_data(va-base,size); assert len(raw)==size
            boundary="GUID" if name=="MgrUSB.exe" and va in GUIDS else "pdata" if va in by_va else "bounded leaf span"
            evidence.append(dict(va=hex(va),size=size,boundary=boundary,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        sources.append(dict(module=name,origin=origin,path=m["path"],sha256=expected,evidence=evidence))
    # Enumerate every rank-choice sequence; compare with an independent permutation set.
    permutations=0
    for n in range(1,8):
        tracks=tuple(range(n)); reference=set(itertools.permutations(tracks))
        sequences=itertools.product(*(range(k) for k in range(n,1,-1)))
        actual={tuple(shuffle_pool(tracks,choice)) for choice in sequences}
        assert actual==reference; permutations+=len(actual)
        for anchor in tracks:
            sequences=itertools.product(*(range(k) for k in range(n-1,1,-1)))
            actual={tuple(shuffle_pool(tracks,choice,anchor)) for choice in sequences}
            expected={p for p in reference if p[0]==anchor}
            assert actual==expected; permutations+=len(actual)
    groups=[[0,1,2],[3],[4,5]]; shuffled=[[2,0,1],[3],[5,4]]
    cases=[]
    for order,is_shuffled in [(groups,False),(shuffled,True)]:
        flat=sum(order,[])
        for current in flat:
            for repeat in [-1,0,1,2,3,4]:
                result=auto_next(order,current,repeat,is_shuffled)
                if repeat==1: assert result==current
                elif repeat==2: assert result in next(g for g in order if current in g)
                elif repeat==3: assert result==flat[(flat.index(current)+1)%len(flat)]
                else: assert result==(None if current==flat[-1] else flat[flat.index(current)+1])
                cases.append(dict(current=current,repeat=repeat,shuffle=is_shuffled,next=result))
    raw=bytearray(0x210); name="Muziek\U0001f600.mp3"
    encoded=name.encode("utf-16le"); raw[:len(encoded)]=encoded
    struct.pack_into("<hIh",raw,0x208,4999,1,2)
    parsed=music_record(raw); assert parsed==dict(name=name,parent_folder=4999,absolute_path_flag=1,media_type=2)
    rejected=0
    for bad in [raw[:-1],raw+b"\0",b"A\0"*264]:
        try: music_record(bad)
        except ValueError: rejected+=1
        else: raise AssertionError("invalid record accepted")
    for tracks,anchor in [([1,1],None),(list(range(5001)),None),([0,1],2)]:
        try: shuffle_pool(tracks,[],anchor)
        except ValueError: rejected+=1
        else: raise AssertionError("invalid pool accepted")
    registry=ROOT/"analysis/firmware/boot-registry/default.validated.reg"
    sections=registry.read_text(encoding="utf-16").split("\n\n")
    selected=[s for s in sections if any(k in s.lower() for k in ["e436ebb3","extensions\\.wma","classes_root\\.mp3","classes_root\\.wma"])]
    assert any('@="quartz.dll"' in s and "e436ebb3" in s for s in selected)
    result=dict(binary_execution=False,sources=sources,com_guids=guids,
        catalog=dict(max_tracks=5000,max_directories=5000,music_stride=528,directory_stride=544,
            music_fields={"name":"0x0 UTF16[260]","parent_folder":"0x208 int16",
                "absolute_path_flag":"0x20a uint32 unaligned","media_type":"0x20e int16"},
            directory_fields={"kind":"0x208 uint32","parent":"0x20c int16","first_child":"0x20e int16",
                "child_count":"0x210 int16","first_track":"0x212 int16","track_count":"0x214 int16",
                "display_parent":"0x216 int16","display_index":"0x218 int16","sorted_folder_id":"0x21a int16",
                "content_kind":"0x21c uint32"}),
        repeat={"0":"off","1":"one track","2":"folder","3":"all"},
        shuffle=dict(grouped_by_folder=True,current_track_first=True,
            algorithm="select random%remaining, output selected, replace with last",
            failure_status_ignored=True,random_provider="coredll.rand_s -> CeGenRandom -> syscall 0xfffe6aa6"),
        registry=dict(path=str(registry.relative_to(ROOT)),sha256=hashlib.sha256(registry.read_bytes()).hexdigest(),sections=selected),
        traces=cases,record_fixture=parsed,
        checks=dict(preserved_ranges=sum(len(s["evidence"]) for s in sources),guids=len(guids),
            enumerated_permutations=permutations,repeat_cases=len(cases),record_fixtures=1,rejected_invalid_inputs=rejected),
        limitations=["Model assumes valid contiguous per-folder tracks, no BT call, no concurrent mutation or COM failure",
            "Native shuffle ignores worker return and can advance its count after cancellation",
            "CeGenRandom kernel output/failure and actual DirectShow filter graph remain open",
            "Playlist parsers, metadata, resume file and remaining media lifecycle remain open"])
    output=ROOT/"analysis/firmware/usb-playlist-contracts.json"
    output.write_text(json.dumps(result,indent=2,ensure_ascii=True),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"]),indent=2))


if __name__=="__main__": main()
