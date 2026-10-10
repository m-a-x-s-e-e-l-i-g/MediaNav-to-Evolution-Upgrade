"""Offline evidence/models for the three playlist readers and USB resume blob."""
import hashlib
import json
import struct
from pathlib import Path
import pefile
from inspect_usb_playlist import USB_HASH
from parse_usb_resume import self_test

ROOT=Path(__file__).resolve().parents[1]


def normalize(path,base):
    if len(path)<3:return path
    if path[0]=="\\":
        if path[1:3].lower()=="md":return path
        return "\\MD"+path
    if path[1:3]==":\\":return "\\MD\\"+path
    if base is None:return path
    return ("" if base.startswith("\\") else "\\")+base+"\\"+path


def extract_line(text,kind):
    if kind=="m3u":return text if text and not text.startswith("#") else None
    if kind=="pls":
        if text[:4].lower()!="file":return None
        at=text.find("=")
        return text[at+1:] if at>=4 else None
    if kind=="wpl":
        start=text.lower().find("<media src")
        if start<0:return None
        equals=text.find("=",start+10)
        quote=text.find('"',equals+1) if equals>=0 else -1
        end=text.find('"',quote+1) if quote>=0 else -1
        return text[quote+1:end] if 0<=quote<end<260 else None
    raise ValueError("unknown playlist kind")


def accepts(path,kind,attributes):
    # GetFileAttributes errors are 0xffffffff; native 16150 rejects only EXACT 0x10.
    return path[-4:].lower() in [".mp3",".wma"] and attributes!=0x10 and (kind!="wpl" or attributes&2==0)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    m=next(m for m in modules if m["origin"]=="705md" and m["name"]=="MgrUSB.exe")
    p=ROOT/m["path"];assert hashlib.sha256(p.read_bytes()).hexdigest()==USB_HASH
    pe=pefile.PE(str(p));base=pe.OPTIONAL_HEADER.ImageBase
    funcs=json.loads((ROOT/"analysis/functions/705md/MgrUSB.exe.json").read_text(encoding="utf-8"))["functions"]
    by_va={int(f["begin_va"],16):f["bytes"] for f in funcs}
    addresses=[0x1311c,0x14e4c,0x14fb8,0x15124,0x152a4,0x15b44,0x15ba0,0x15c00,
        0x15e4c,0x160d0,0x16104,0x16150,0x1618c,0x161b4,0x16340,0x1640c,0x164c0,
        0x1658c,0x165e8,0x168b4,0x16910,0x1a69c,0x1a7d0,0x1a9e4,0x1ab50,
        0x1abac,0x1b3b0,0x1b484,0x1ba3c,0x1be50,0x1c17c,0x1c2e8,0x1eac4,0x1fd6c]
    leaves={0x160d0:0x34,0x1ab50:0x5c,0x1abac:0x34}
    ranges=[(va,by_va[va] if va in by_va else leaves[va]) for va in addresses]
    tables=[]
    for va,kind,expected in [(0x27bfc,"m3u",0x15c00),(0x27c20,"pls",0x165e8),(0x27c34,"wpl",0x16910)]:
        ranges.append((va,8));slots=struct.unpack("<2I",pe.get_data(va-base,8));assert slots[1]==expected
        tables.append(dict(va=hex(va),kind=kind,destructor=hex(slots[0]),reader=hex(slots[1])))
    evidence=[]
    for va,size in ranges:
        raw=pe.get_data(va-base,size);assert len(raw)==size
        boundary="vtable" if va in [0x27bfc,0x27c20,0x27c34] else "pdata" if va in by_va else "bounded leaf span"
        evidence.append(dict(va=hex(va),size=size,boundary=boundary,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    paths=[("song.mp3","MD\\Music","\\MD\\Music\\song.mp3"),
        ("\\other\\song.mp3","ignored","\\MD\\other\\song.mp3"),
        ("\\MDfoo\\song.mp3","ignored","\\MDfoo\\song.mp3"),
        ("C:\\song.mp3","ignored","\\MD\\C:\\song.mp3"),
        ("http://a/song.mp3","MD","\\MD\\http://a/song.mp3"),
        ("../song.mp3","MD\\Music","\\MD\\Music\\../song.mp3"),
        ("x",None,"x"),("song.mp3",None,"song.mp3")]
    for path,parent,expected in paths:assert normalize(path,parent)==expected
    examples=[("m3u","#EXTINF:3,Title",None),("m3u"," song.mp3"," song.mp3"),
        ("m3u","\ufeffsong.mp3","\ufeffsong.mp3"),("pls","FileXYZ=song.mp3","song.mp3"),
        ("pls","File=song.mp3","song.mp3"),("pls"," File1=song.mp3",None),
        ("wpl",'<media src="song.mp3"/>',"song.mp3"),
        ("wpl","<media src='song.mp3'/>",None),("wpl",'<media\nsrc="song.mp3"/>',None),
        ("wpl",'<media src="a&amp;b.mp3"/>',"a&amp;b.mp3")]
    for kind,line,expected in examples:assert extract_line(line,kind)==expected
    attribute_cases=[]
    for kind in ["m3u","pls","wpl"]:
        for attr in [0,2,4,0x10,0x12,0x20,0xffffffff]:
            accepted=accepts("song.mp3",kind,attr)
            if attr==0x10:assert not accepted
            if attr==0xffffffff:assert accepted==(kind!="wpl")
            attribute_cases.append(dict(kind=kind,attributes=hex(attr),accepted=accepted))
    assert sum(count+1<1000 for count in range(1000))==999
    resume_checks=self_test()
    result=dict(binary_execution=False,source=dict(module=m["name"],path=m["path"],sha256=USB_HASH,evidence=evidence),
        playlist_vtables=tables,path_cases=[dict(input=p,parent=b,output=o) for p,b,o in paths],
        line_cases=[dict(kind=k,line=l,result=e) for k,l,e in examples],attributes=attribute_cases,
        playlist=dict(catalog_capacity=1000,per_playlist_accepted_limit=999,line_buffer_bytes=260,
            encoding_codepage=65001,encoding_flags=8,open_mode="rt",sorted_after_import=True,
            checks_file_attributes_against_exact_directory_value=True),
        resume=dict(bytes=3180,path="\\Storage Card2\\USBMusicResume.dat",checksum="sum(body) modulo 256; body sum must be nonzero",
            save_open_mode=4,delete_save_open_mode=2,load_open_mode=3,
            fingerprint=["file_size_low","volume_serial","disk_free_bytes","disk_total_bytes"]),
        checks=dict(preserved_ranges=len(evidence),playlist_vtables=len(tables),path_cases=len(paths),
            line_cases=len(examples),attribute_cases=len(attribute_cases),playlist_limit=999,resume=resume_checks),
        limitations=["Models operate on already-decoded single lines and do not emulate CRT text translation or filesystem",
            "Unbounded native path formatting is described but not reproduced",
            "No real resume file or stick snapshot was available; fixtures are synthetic",
            "Playback errors, XML entities beyond apos, concurrency and full locale sorting remain open"])
    (ROOT/"analysis/firmware/usb-media-input-contracts.json").write_text(json.dumps(result,indent=2,ensure_ascii=True),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"]),indent=2))


if __name__=="__main__":main()
