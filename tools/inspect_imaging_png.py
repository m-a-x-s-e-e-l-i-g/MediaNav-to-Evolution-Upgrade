"""Preserve native PNG ranges and verify bounded reference decoding independently."""
import hashlib
import json
from collections import Counter
from pathlib import Path
import pefile
from PIL import Image
from inspect_usb_metadata import IMAGING_HASH
from parse_png_image import parse_png,reference_rgba,self_test,geometry,paeth

ROOT=Path(__file__).resolve().parents[1]
ZLIB_HASH="1b3ef3cb314b72f188fadfb19cffe961b028d20d3fefc5350a3221e9879d43e8"


def preserve(module,addresses,extras):
    path=ROOT/module["path"];raw=path.read_bytes();assert hashlib.sha256(raw).hexdigest()==module["sha256"]
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase
    fs=json.loads((ROOT/"analysis/functions/rom"/(module["name"]+".json")).read_text(encoding="utf-8"))["functions"]
    sizes={int(f["begin_va"],16):f["bytes"] for f in fs}
    ranges=[]
    for va in addresses:
        assert va in sizes;ranges.append((va,sizes[va],"pdata"))
    ranges.extend(extras)
    evidence=[]
    for va,n,boundary in ranges:
        data=pe.get_data(va-base,n);assert len(data)==n
        evidence.append(dict(va=hex(va),bytes=n,boundary=boundary,raw_hex=data.hex(),sha256=hashlib.sha256(data).hexdigest()))
    return dict(module=module["name"],path=module["path"],sha256=module["sha256"],ranges=evidence)


def native_geometry(w,h):
    return [((w+7)//8,(h+7)//8),((w+3)//8,(h+7)//8),((w+3)//4,(h+3)//8),
        ((w+1)//4,(h+3)//4),((w+1)//2,(h+1)//4),(w//2,(h+1)//2)]


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    imaging=next(m for m in modules if m["origin"]=="rom" and m["name"]=="imaging.dll")
    zlib_module=next(m for m in modules if m["origin"]=="rom" and m["name"].lower()=="zlib.dll")
    assert imaging["sha256"]==IMAGING_HASH and zlib_module["sha256"]==ZLIB_HASH
    addresses=[0x404962c4,0x404901e4,0x4049035c,0x404979c8,0x40497ad8,0x404991cc,0x404993f4,
        0x404a4a3c,0x404a5248,0x404a5c70,0x404a5cc8,0x404a5cf8,0x404a5f98,0x404a6118,
        0x404a63ec,0x404a643c,0x404a655c,0x404a6a18,0x404a6cb0,0x404a6e9c,0x404a6f3c,
        0x404a6f68,0x404a70ec,0x404a87b4,0x404a89b8,0x404a8a6c]
    sources=[preserve(imaging,addresses,[(0x404a5abc,0x1b4,"leaf: final jr ra plus delay slot"),
        (0x404a13f4,8,"leaf: always returns 1"),(0x404aa1a4,8,"leaf: returns a1"),
        (0x4048401c,12,"warning interface vtable"),(0x4048537c,8,"PNG signature"),
        (0x404850d0,6,"inflateInit2_ version argument including terminator")]),
        preserve(zlib_module,[0x40145110,0x401452a8,0x4014509c],
            [(0x40145b94,12,"zlibVersion leaf"),(0x4014104c,6,"zlibVersion string including terminator")])]
    geometry_checks=0;prefix_checks=0
    for w in range(1,65):
        for h in range(1,65):
            own=native_geometry(w,h);standard=[(p[4],p[5]) for p in geometry(w,h,1)][:6]
            assert own==standard;geometry_checks+=1
            for bits in [1,2,4,8,16,24,32,48,64]:
                for count in range(1,7):
                    actual=sum(((pw*bits+7)//8+int(pw>0))*ph for pw,ph in own[:count])
                    expected=sum(((pw*bits+7)//8+1)*ph for pw,ph in standard[:count] if pw and ph)
                    assert actual==expected;prefix_checks+=1
    # Exhaustive predictor comparison is arithmetic only, never native execution.
    paeth_checks=0
    for a in range(256):
        for b in range(256):
            for c in range(256):
                da=abs(b-c);db=abs(a-c);dc=abs(a+b-2*c)
                native=(b if db<=dc else c) if db<da else (a if da<=dc else c)
                assert native==paeth(a,b,c);paeth_checks+=1
    print("Native arithmetic models passed; checking real PNG assets",flush=True)
    assets=[];stats=Counter()
    for path in sorted((ROOT/"extracted/705md").rglob("*.png")):
        raw=path.read_bytes();meta,rows=parse_png(raw);own=reference_rgba(meta,rows)
        with Image.open(path) as im:other=im.convert("RGBA").tobytes()
        assert own==other,path
        stats[(meta["depth"],meta["color_type"],meta["interlace"])]+=1
        assets.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=hashlib.sha256(raw).hexdigest(),
            reference_rgba_sha256=hashlib.sha256(own).hexdigest(),independent_decoder="Pillow",matches=True,**meta))
        if len(assets)%50==0:print(f"PNG assets checked: {len(assets)}",flush=True)
    fixtures=self_test()
    checks=dict(preserved_ranges=sum(len(s["ranges"]) for s in sources),adam7_dimension_cases=geometry_checks,
        adam7_prefix_size_cases=prefix_checks,paeth_byte_triples=paeth_checks,real_png_rgba_matches=len(assets),fixtures=fixtures)
    result=dict(binary_execution=False,sources=sources,checks=checks,real_assets=assets,
        real_asset_formats=[dict(depth=d,color_type=c,interlace=i,count=n) for (d,c,i),n in stats.items()],
        native_models=dict(invalid_filter=dict(filter=5,input_hex="010203",output_hex="010203",error_flag_set=False,
            scope="Followed filter routine falls through without touching the bytes"),
            missing_row_tail=dict(requested_bytes=5,available_hex="000102",result_hex="0001020000",parser_error_flag="+7e",
                scope="Arithmetic projection of the fill helper; full malformed native decoding not executed"),
            callback=dict(continue_return=1,warning_returns_second_argument=True),
            zlib=dict(provider_reported_version="1.1.4",stream_struct_bytes=56,header_check=True,adler_check=True,
                scope="Followed wrapper/provider state machine, not a complete audit of DEFLATE")),
        limitations=["Reference parsing is bounded and stricter than the native PNG chunk parser",
            "Real RGBA agreement verifies reference interpretation, not native device output",
            "Native Adam7 scatter helpers and PNG sample converters are followed in png-pixel-contracts.json",
            "General sink conversion, text metadata, invalid dispatch and malformed chunk arithmetic remain open",
            "Missing-tail and invalid-filter models are local arithmetic projections; no native malformed-input execution",
            "Provider reports 1.1.4; no claim that all code is identical to an upstream release or all vulnerabilities apply"])
    (ROOT/"analysis/firmware/imaging-png-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",**checks),indent=2))


if __name__=="__main__":main()
