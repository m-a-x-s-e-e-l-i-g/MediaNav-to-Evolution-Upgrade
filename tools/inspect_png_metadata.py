"""Preserve PNG metadata/ownership code and check bounded fixtures and real assets."""
import hashlib
import json
import struct
import zlib
from collections import Counter
from io import BytesIO
from pathlib import Path
import pefile
from PIL import Image
from inspect_imaging_png import preserve,ZLIB_HASH
from inspect_usb_metadata import IMAGING_HASH
from parse_png_image import SIGNATURE,chunk,parse_png
from parse_png_metadata import parse_metadata,MAX_METADATA,inflate_bounded
from png_metadata_models import TEXT_FIELDS,classify_keyword,compressed_storage,time_string,lazy_property_fault

ROOT=Path(__file__).resolve().parents[1]


def fixture(parts,indexed=False):
    header=struct.pack(">IIBBBBB",1,1,8,3 if indexed else 2,0,0,0)
    palette=chunk(b"PLTE",b"\x01\x02\x03\x04\x05\x06") if indexed else b""
    row=b"\0\0" if indexed else b"\0\x01\x02\x03"
    return SIGNATURE+chunk(b"IHDR",header)+palette+b"".join(chunk(k,d) for k,d in parts)+chunk(b"IDAT",zlib.compress(row))+chunk(b"IEND",b"")


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    imaging=next(m for m in modules if m["origin"]=="rom" and m["name"]=="imaging.dll")
    provider=next(m for m in modules if m["origin"]=="rom" and m["name"].lower()=="zlib.dll")
    assert imaging["sha256"]==IMAGING_HASH and provider["sha256"]==ZLIB_HASH
    addresses=[0x404a4a3c,0x404a4b28,0x404a4c60,0x404a4cac,0x404a4f28,0x404a5248,
        0x404a643c,0x404a64ec,0x40490480,0x404904d0,0x4049654c,0x40496600,
        0x40496ab0,0x40496bd4,0x4049729c,0x40497300,0x404973c8,0x40497480,
        0x40497594,0x40497620,0x40497730,0x404977f8,0x40497eb0,0x40497938,
        0x40497fac,0x40498bbc,0x40498c10]
    sources=[preserve(imaging,addresses,[(0x40485034,8,"PNG parser destructor/chunk-handler vtable")]),
        preserve(provider,[0x40145ae8,0x40145284,0x401452a8,0x4014509c],[])]
    pe=pefile.PE(str(ROOT/imaging["path"]))
    assert struct.unpack("<2I",pe.get_data(0x40485034-pe.OPTIONAL_HEADER.ImageBase,8))==(0x404a4c60,0x404a5248)
    # Every range is reread and hashed; preserved raw bytes are the evidence anchor.
    for source in sources:
        original=pefile.PE(str(ROOT/source["path"]))
        for record in source["ranges"]:
            data=original.get_data(int(record["va"],16)-original.OPTIONAL_HEADER.ImageBase,record["bytes"])
            assert data.hex()==record["raw_hex"] and hashlib.sha256(data).hexdigest()==record["sha256"]
    exact=zlib.compress(b"A"*48);assert len(exact)==12
    large=zlib.compress(b"A"*4096)
    cases=[("plain",[(b"tEXt",b"Title\0Hello")],False),
        ("compressed_exact_capacity",[(b"zTXt",b"Title\0\0"+exact)],False),
        ("compressed_large",[(b"zTXt",b"Title\0\0"+large)],False),
        ("utf8",[(b"iTXt",b"Description\0\0\0nl\0Omschrijving\0"+"Hoës".encode())],False),
        ("utf8_compressed",[(b"iTXt",b"Title\0\1\0\0\0"+zlib.compress("Hé".encode()))],False),
        ("profile_envelope",[(b"iCCP",b"Profile\0\0"+large)],False),
        ("keywords_78_79",[(b"tEXt",b"Title"+b"x"*73+b"\0ok"),(b"tEXt",b"Title"+b"x"*74+b"\0ok")],False),
        ("empty_text",[(b"tEXt",b"Title\0")],False),
        ("color_resolution_time",[(b"pHYs",struct.pack(">IIB",2835,3780,1)),
            (b"cHRM",struct.pack(">8I",31270,32900,64000,33000,30000,60000,15000,6000)),
            (b"gAMA",struct.pack(">I",45455)),(b"sRGB",b"\0"),(b"sBIT",b"\x08\x08\x08"),
            (b"tIME",struct.pack(">H5B",2026,10,8,12,34,60))],False),
        ("palettes",[(b"hIST",struct.pack(">2H",1,2)),(b"sPLT",b"Palette\0\x08\x01\x02\x03\xff\0\1")],True)]
    fixtures=[];oracle_checks=0
    for name,parts,indexed in cases:
        raw=fixture(parts,indexed);parsed=parse_metadata(raw);parse_png(raw)
        with Image.open(BytesIO(raw)) as im:
            im.load()
            for text in parsed["text"]:
                # Duplicate keys are a separate native aggregation question.
                if name=="keywords_78_79":continue
                assert im.info[text["keyword"]]==text["text"];oracle_checks+=1
            if name=="profile_envelope":assert im.info["icc_profile"]==b"A"*4096;oracle_checks+=1
        fixtures.append(dict(name=name,png_hex=raw.hex(),metadata=parsed,
            scope="Reference/Pillow parsing only; profile internals and native decoding not validated"))
    bad=[(b"tEXt",b"Title"),(b"tEXt",b"x"*80+b"\0text"),
        (b"zTXt",b"Title\0\1"+exact),(b"zTXt",b"Title\0\0bad"),
        (b"iTXt",b"Title\0\2\0\0\0x"),(b"iTXt",b"Title\0\0\0\0\0\xff"),
        (b"iCCP",b"Profile\0\1"+large),(b"pHYs",struct.pack(">IIB",1,1,2)),
        (b"tIME",b"\0"*6),(b"tIME",struct.pack(">H5B",2026,13,1,0,0,0)),
        (b"sBIT",b"\0\x08\x08"),(b"sPLT",b"Palette\0\x08\0"),
        (b"hIST",b"\0\1"),(b"gAMA",b"\0"*4),(b"sRGB",b"\4")]
    rejected=[]
    for kind,data in bad:
        try:parse_metadata(fixture([(kind,data)]))
        except (ValueError,UnicodeError,zlib.error) as error:rejected.append(dict(type=kind.decode(),payload_hex=data.hex(),error=str(error)))
        else:raise AssertionError((kind,data))
    corrupt=bytearray(fixture([(b"tEXt",b"Title\0Hello")]));corrupt[45]^=1
    try:parse_metadata(bytes(corrupt))
    except ValueError as error:rejected.append(dict(type="CRC",error=str(error)))
    else:raise AssertionError("CRC accepted")
    try:inflate_bounded(zlib.compress(b"A"*(MAX_METADATA+1)))
    except ValueError as error:rejected.append(dict(type="metadata_limit",error=str(error)))
    else:raise AssertionError("metadata bound accepted")
    try:parse_metadata(fixture([(b"zTXt",b"Title\0\0"+zlib.compress(b"A"*MAX_METADATA))]*9))
    except ValueError as error:rejected.append(dict(type="aggregate_metadata_limit",error=str(error)))
    else:raise AssertionError("aggregate metadata bound accepted")
    models=dict(first_exact=compressed_storage(exact),first_too_large=compressed_storage(large),
        append_too_large=compressed_storage(large,b"old\0"),append_success=compressed_storage(exact,b"old\0"),
        profile_too_large=compressed_storage(large,profile=True),
        keyword_cases=[dict(keyword_hex=k.hex(),**classify_keyword(k)) for k in [b"TitleSuffix",b"Title"+b"x"*73,b"Title"+b"x"*74,b"Creation Time",b"Tit",b""]],
        lazy_properties=lazy_property_fault([6,18],1,2),
        duplicate_histogram=dict(palette_entries=2,allocations=[4,4],freed_latest_on_destructor=4,earlier_unreleased_bytes=4),
        time_cases=[dict(fields=list(fields),output_hex=time_string(*fields).hex()) for fields in [(2026,10,8,12,34,60),(10000,1,1,0,0,0),(65535,255,255,255,255,255)]])
    assert models["first_exact"]["null_write_outside_requested_allocation"]
    assert models["first_too_large"]["projected_provider_status"]==-5
    assert models["append_too_large"]["old_buffer_after_initial_mutation_hex"]==b"old ".hex()
    assert models["lazy_properties"]["skipped_node_and_payload_bytes"]==60
    for year in range(65536):
        native=time_string(year,1,1,0,0,0)
        if year<=9999:assert native==f"{year:04}:01:01 00:00:00\0".encode()
        else:assert native[0]>ord("9")
    for n in range(256):
        value=time_string(2026,n,n,n,n,n)
        assert (value[5:7]==f"{n:02}".encode())==(n<=99)
    manifest=json.loads((ROOT/"analysis/firmware/imaging-png-contracts.json").read_text(encoding="utf-8"))
    assets=[];counts=Counter();keywords=Counter();physical=Counter();coordinates=Counter();gamma=Counter()
    for record in manifest["real_assets"]:
        path=ROOT/record["path"];raw=path.read_bytes();assert hashlib.sha256(raw).hexdigest()==record["sha256"]
        parsed=parse_metadata(raw);counts.update(parsed["chunk_counts"])
        for entry in parsed["metadata"]:
            if entry["type"] in ["tEXt","zTXt","iTXt"]:keywords[(entry["type"],entry["keyword"])]+=1
            if entry["type"]=="pHYs":physical[(entry["x"],entry["y"],entry["unit"])]+=1
            if entry["type"]=="cHRM":coordinates[tuple(entry["scaled_coordinates"])]+=1
            if entry["type"]=="gAMA":gamma[entry["gamma_times_100000"]]+=1
        assets.append(dict(path=record["path"],**parsed))
    assert len(assets)==377 and counts["iTXt"]==372 and counts["tEXt"]==8
    checks=dict(preserved_ranges=sum(len(s["ranges"]) for s in sources),real_assets=len(assets),
        reference_fixtures=len(fixtures),pillow_metadata_matches=oracle_checks,rejected_reference_cases=len(rejected),
        native_time_year_values=65536,native_time_byte_values=256)
    evidence=dict(binary_execution=False,sources=sources,checks=checks,fixtures=fixtures,rejected_reference_cases=rejected,
        native_models=models,real_chunk_counts=dict(counts),
        real_keywords=[dict(type=t,keyword=k,count=n) for (t,k),n in keywords.items()],
        real_physical=[dict(x=x,y=y,unit=u,dpi_x=x*254/10000 if u==1 else None,dpi_y=y*254/10000 if u==1 else None,count=n) for (x,y,u),n in physical.items()],
        real_chromaticities=[dict(values=list(k),count=n) for k,n in coordinates.items()],
        real_gamma=[dict(value=k,count=n) for k,n in gamma.items()],
        native_text_properties=[dict(keyword=k.decode(),pointer_offset=hex(p),count_offset=hex(p+4),tag=hex(t),type=2) for k,p,t in TEXT_FIELDS],
        real_assets=assets,limitations=["Native firmware and allocator failures were not executed",
            "Capacity/status traces assume valid bounded streams and successful allocations",
            "Reference metadata reader is stricter than native code but is not a full PNG validator",
            "Profile envelope parsing does not validate ICC internals; XMP content remains opaque",
            "iCCP/zTXt/tIME/hIST/sBIT/sRGB findings are fixture/static based; none occur in the 377 real assets",
            "Native malformed chunk extents, sink conversion, complete SetProperty failure paths and color management remain open"])
    (ROOT/"analysis/firmware/png-metadata-contracts.json").write_text(json.dumps(evidence,indent=2,ensure_ascii=False),encoding="utf-8")
    print(json.dumps(dict(status="passed",**checks,keywords=evidence["real_keywords"],physical=evidence["real_physical"]),indent=2))


if __name__=="__main__":main()
