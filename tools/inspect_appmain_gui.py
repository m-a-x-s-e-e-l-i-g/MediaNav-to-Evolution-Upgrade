"""Preserve native GUI drawing/touch contracts and check bounded offline models."""
import hashlib
import json
import struct
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parents[1]
HASH="6a03280b71b49701766e47709802a190eca48a4a73406b27e18ad8618d5603c8"
FUNCTIONS=[0x134ed0,0x135aec,0x135bcc,0x134d28,0x13d220,0x13d098,0x13d164,
           0x13e554,0x13e620,0x13e6f8,0x13e444,0x13e7ec,0x13ecec,0x13ec34,
           0x13cf30,0x139020,0x13ea5c,0x135548,0x13fe40,0x13ce98]


def signed32(value):
    value &= 0xffffffff
    return value if value < 0x80000000 else value-0x100000000


def native_hit(area,point):
    x,y=point
    right=signed32(area["x"]+area["width"])
    bottom=signed32(area["y"]+area["height"])
    return area["x"] <= x <= right and area["y"] <= y <= bottom


def hit_route(areas,point):
    return next((a["event"] for a in reversed(areas) if native_hit(a,point)),None)


def selection_trace(nested):
    selected,previous="original",None
    log=[]
    def begin(bitmap):
        nonlocal selected,previous
        previous=selected;selected=bitmap;log.append(["begin",selected,previous])
    def end():
        nonlocal selected
        selected=previous;log.append(["end",selected,previous])
    begin("sprite")
    if nested:
        begin("background");end()
    end()
    return dict(selected=selected,log=log)


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    m=next(m for m in modules if m["origin"]=="705md" and m["name"]=="AppMain.exe")
    path=ROOT/m["path"];assert hashlib.sha256(path.read_bytes()).hexdigest()==HASH
    pe=pefile.PE(str(path));base=pe.OPTIONAL_HEADER.ImageBase
    functions=json.loads((ROOT/"analysis/functions/705md/AppMain.exe.json").read_text(encoding="utf-8"))["functions"]
    evidence=[]
    ranges=[(va,next(f["bytes"] for f in functions if int(f["begin_va"],16)==va)) for va in FUNCTIONS]
    ranges += [(0x13e17c,0x58),(0x13e1d4,0xb4),(0x17ce10,64)]
    for va,size in ranges:
        raw=pe.get_data(va-base,size);assert len(raw)==size
        evidence.append(dict(va=hex(va),size=size,raw_hex=raw.hex(),sha256=hashlib.sha256(raw).hexdigest()))
    startup=json.loads((ROOT/"analysis/firmware/appmain-startup-contracts.json").read_text(encoding="utf-8"))
    assert next(s["sha256"] for s in startup["sources"] if s["module"]=="AppMain.exe")==HASH
    areas=startup["diagnostics"]["entry_screen"]["areas"]
    # Materialized integer sets independently verify the inclusive rectangle model.
    regions=[(a["event"],set(range(a["x"],a["x"]+a["width"]+1)),
              set(range(a["y"],a["y"]+a["height"]+1))) for a in areas]
    counts={str(a["event"]):0 for a in areas};counts["none"]=0
    for y in range(480):
        for x in range(800):
            expected=next((event for event,xs,ys in reversed(regions) if x in xs and y in ys),None)
            actual=hit_route(areas,(x,y));assert actual==expected
            counts[str(actual) if actual is not None else "none"]+=1
    edges=[((200,150),1001),((310,480),1002),((800,150),1003),((500,150),1004),((800,480),1005),((801,480),None)]
    for point,expected in edges:assert hit_route(areas,point)==expected
    overlap=[dict(event=1,x=0,y=0,width=100,height=100),dict(event=2,x=100,y=0,width=100,height=100)]
    assert hit_route(overlap,(100,0))==2
    simple,nested=selection_trace(False),selection_trace(True)
    assert simple["selected"]=="original" and nested["selected"]=="sprite"
    table=struct.unpack("<16I",pe.get_data(0x17ce10-base,64))
    assert table[1:4]==(0x13e554,0x13e620,0x13e6f8)
    result=dict(binary_execution=False,module=m["path"],sha256=HASH,evidence=evidence,
        control_vtable=[dict(offset=hex(i*4),target=hex(v)) for i,v in enumerate(table)],
        drawing=dict(width=800,height=480,bit_depth=24,uncompressed_pixel_bytes=800*480*3,
                     state_frames="horizontal; source x=control width*state",transparent_argument="0xffff",
                     states={"0":"normal","1":"pressed","2":"disabled","3":"selected"}),
        touch=dict(window_messages={"0x200":"move","0x201":"down","0x202":"up"},
                   low_word_unsigned_x=True,high_word_unsigned_y=True,hit_edges="inclusive",
                   control_order="reverse insertion order",regions=areas,pixel_counts=counts),
        checks=dict(screen_points=800*480,boundary_cases=len(edges),overlap_cases=1,selection_cases=2),
        selection_traces=dict(simple=simple,nested=nested),
        limitations=["Static code and models; no Windows CE rendering or native MIPS execution",
                     "Nested shared previous-bitmap slot does not model GDI runtime failure or cached handle lifetime",
                     "Text, font fallback, list scrolling, image scaling and all screen callbacks remain open"])
    (ROOT/"analysis/firmware/appmain-gui-contracts.json").write_text(json.dumps(result,indent=2),encoding="utf-8")
    print(json.dumps(dict(status="passed",preserved_ranges=len(evidence),**result["checks"],pixel_counts=counts),indent=2))


if __name__=="__main__":main()
