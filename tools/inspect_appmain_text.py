"""Preserve AppMain text/font contracts and ROM loading evidence; offline models only."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT = Path(__file__).resolve().parents[1]
SOURCES = {
    ("705md", "AppMain.exe"): ("6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8",
        [0x139528, 0x139668, 0x139718, 0x1397c8, 0x139918, 0x139ac0,
         0x139b94, 0x13bc9c, 0x13bbb4, 0x6c39c]),
    ("rom", "gwes.dll"): ("30db135596c2b76fd9f1650afd4f5fe6c258a59af62ca4dc5afca44c5859c734",
        [0xc016e724, 0xc01735d8, 0xc0173808, 0xc017dbac, 0xc017f89c, 0xc01caa40,
         0xc01ca86c, 0xc01ca968]),
    ("rom", "mgtt_o.dll"): ("8807037ca5eb8feb2ec00453260797afeb54e5e21d3c794be1a63b4fe5ae6daf",
        [0xc0261ab8, 0xc0262288, 0xc0263a94, 0xc026a788, 0xc026d9dc, 0xc026dc4c, 0xc026e150]),
}


def rtl(units, table):
    text = units[:units.index(0)] if 0 in units else units
    arabic = any(0x600 <= c <= 0x6ff for c in text)
    return any(c in table for c in text) or arabic or any(0x590 <= c <= 0x5ff for c in text)


def fit(main_width, fallback_widths, width):
    if main_width < width: return "main"
    for i, measured in enumerate(fallback_widths[:10]):
        if measured is None: break
        if measured < width: return i
    return "main"


def compare(old, new, capacity=128):
    i = 0; remaining = capacity - 1
    while new[i] and remaining > 0 and old[i] == new[i] and old[i]:
        i += 1; remaining -= 1
    return old[i] != new[i]


def copy_native(memory, capacity=128):
    # The assembly reads the NEXT source unit before testing remaining capacity.
    output = []; i = 0; remaining = capacity
    while True:
        output.append(memory[i]); i += 1
        next_unit = memory[i]; remaining -= 1
        if next_unit == 0 or remaining <= 0: break
    return output + [0], i


def main():
    modules = json.loads((ROOT / "analysis/corpus/modules.json").read_text(encoding="utf-8"))
    sources = []; app = None
    for (origin, name), (expected, addresses) in SOURCES.items():
        module = next(m for m in modules if m["origin"] == origin and m["name"] == name)
        path = ROOT / module["path"]
        assert hashlib.sha256(path.read_bytes()).hexdigest() == expected
        pe = pefile.PE(str(path)); base = pe.OPTIONAL_HEADER.ImageBase
        index = json.loads((ROOT / f"analysis/functions/{origin}/{name}.json").read_text(encoding="utf-8"))["functions"]
        ranges = [(va, next(f["bytes"] for f in index if int(f["begin_va"],16)==va)) for va in addresses]
        if name == "AppMain.exe":
            ranges += [(0x139458,0xd0), (0x1398a0,0x78), (0x1381c8,0x64), (0x151c44,66),
                       (0x17cba8,64), (0x17cc60,60)]
            app = pe
        if name == "gwes.dll": ranges += [(0xc0228544,10)]
        evidence = []
        for va, size in ranges:
            raw = pe.get_data(va-base,size); assert len(raw)==size
            evidence.append(dict(va=hex(va),size=size,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
        sources.append(dict(module=name, origin=origin, path=module["path"], sha256=expected, evidence=evidence))
    table = struct.unpack("<33H", app.get_data(0x151c44-app.OPTIONAL_HEADER.ImageBase,66))
    assert table[-1]==0 and all(0x600<=c<=0x6ff for c in table[:32])
    positives = 0
    for c in range(65536):
        expected = 0x590 <= c <= 0x6ff
        assert rtl([c],table[:32]) == expected
        positives += expected
    assert not rtl([65,0,0x600],table[:32])
    assert rtl([65,0x600,0],table[:32])
    cases = [(99,[98],100,"main"), (100,[100,99],100,1),
             (101,[None,99],100,"main"), (101,[100]*10+[99],100,"main"),
             (101,[101,102],100,"main"), (101,[99],100,0)]
    for main_width, fallback, width, expected in cases:
        assert fit(main_width,fallback,width)==expected
    for length in (0,1,127,128,129,200):
        source=[65]*length+[0,0]
        copied,read_index=copy_native(source)
        assert copied[:min(length,128)]==[65]*min(length,128)
        assert copied[-1]==0 and len(copied)<=129
        assert read_index==min(max(length,1),128)
    for length in (0,1,269,270,271,400):
        copied,read_index=copy_native([65]*length+[0,0],270)
        assert copied[:min(length,270)]==[65]*min(length,270)
        assert copied[-1]==0 and len(copied)<=271
        assert read_index==min(max(length,1),270)
    # The first empty-string unit is copied before a lookahead; trailing storage is observable.
    assert copy_native([0,66,0])[0]==[0,66,0]
    old=[65]*128+[0]; new=[65]*128+[66,0]
    assert not compare(old,new)
    for i in range(128):
        new=old.copy();new[i]=66
        assert compare(old,new)
    offscreen_vtable=struct.unpack("<15I",app.get_data(0x17cc60-app.OPTIONAL_HEADER.ImageBase,60))
    assert offscreen_vtable[13:15]==(0x13bc9c,0x139718)
    font=json.loads((ROOT/"analysis/firmware/ac3-font/manifest.json").read_text(encoding="utf-8"))
    assert all(c["matches"] for c in font["checksums"] if c["tag"] in ("EBDT","loca","cmap"))
    assert sum(b.get("rac3",{}).get("verified_intervals",0) for b in font["blocks"])==51056
    bad_tables=[dict(face=f["names"]["1"],tag=t["tag"],offset=t["offset"],length=t["length"])
                for f in font["faces"] for t in f["tables"] if not t["within_physical_file"]]
    assert len(bad_tables)==4 and {t["tag"] for t in bad_tables}=={"act3","glyf"}
    registry_path=ROOT/"analysis/firmware/boot-registry/default.validated.reg"
    registry=registry_path.read_text(encoding="utf-16")
    keys=["HKEY_LOCAL_MACHINE\\System\\GDI\\FontFiles\\TrueType",
          "HKEY_LOCAL_MACHINE\\System\\GDI\\FontDrivers\\Microsoft TrueType",
          "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\FontPath",
          "HKEY_LOCAL_MACHINE\\Software\\Microsoft\\FontLink\\SystemLink"]
    sections={key:next(section for section in registry.split("\n[") if key.lower() in section.lower()).strip() for key in keys}
    result=dict(binary_execution=False,sources=sources,
        registry=dict(path=str(registry_path.relative_to(ROOT)),sha256=hashlib.sha256(registry_path.read_bytes()).hexdigest(),sections=sections),
        label=dict(text_offset="0x70",text_max_code_units=128,forced_terminator_offset="0x170",
            extended_setter=dict(va="0x139718",capacity=270,forced_terminator_offset="0x28c"),
            offscreen_label_vtable=[hex(v) for v in offscreen_vtable],
            font_offset="0x30",fallback_offsets=[hex(i) for i in range(0x34,0x5c,4)],
            autofit_offset="0x5c",color_offset="0x60",format_offset="0x64",default_format="0x824",
            fit_comparison="measured width strictly less than label width",
            main_draw_limit=10,offscreen_draw_limit="zero handle only; no explicit 10-slot bound",
            rtl_ranges=["0590..05ff","0600..06ff"],arabic_table=[hex(c) for c in table],
            rtl_format_bit="0x20000"),
        direct_font_validation=dict(failed_tables=bad_tables,
            conclusion="Unchanged AC3 bytes fail followed mgtt_o SFNT table-range validator",
            runtime_unknown="Installed filename/content and any prior transformation"),
        checks=dict(preserved_ranges=sum(len(s["evidence"]) for s in sources),rtl_code_units=65536,
            rtl_positive_units=positives,rtl_multi_cases=2,fit_cases=len(cases),copy_length_cases=12,
            changed_prefix_cases=128,empty_lookahead_cases=1),
        limitations=["No font rendering or native executable execution",
            "Offscreen label fallback overrun is conditional; specific screen reachability remains open",
            "CTF glyph representation and any installation conversion remain open"])
    (ROOT/"analysis/firmware/appmain-text-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**result["checks"]),indent=2))


if __name__=="__main__": main()
