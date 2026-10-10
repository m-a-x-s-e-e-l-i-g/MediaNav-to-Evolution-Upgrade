"""Create a resource-only home skin with original BMP contracts and full baseline.

Vector drawing here authors code-native firmware resources. It does not edit the
generated concept image. An optional home text-color patch is verified separately;
no update container is built.
"""
import argparse
import csv
import hashlib
import json
import math
import shutil
from pathlib import Path

from PIL import Image, ImageChops, ImageDraw, ImageFont
from parse_bmp_image import parse_bmp, reference_rgb

ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / "extracted/705md"
REL = Path("upgrade/Storage Card/System/Img/M1")
KEY = (255, 255, 0)
BG = (12, 17, 20)
COLORS = {
    "radio": (15, 195, 205), "media": (174, 66, 240),
    "phone": (0, 157, 242), "map": (255, 173, 25),
    "navi": (247, 90, 91), "setting": (249, 190, 44),
    "smartphone": (40, 160, 229), "driving eco": (145, 187, 82),
}
MAIN_NAMES = [f"home_{name}_btn.bmp" for name in COLORS]
MAIN_NAMES += ["home_phone_second line_btn.bmp", "home_smartphone_second line_btn.bmp"]
ALLOWLIST = [REL / "common/home_bg.bmp", REL / "home/common_indi_line.bmp",
             REL / "home/home_dark_btn.bmp", REL / "home/home_set time_btn.bmp"]
ALLOWLIST += [REL / "home" / name for name in MAIN_NAMES]


def sha(data):
    return hashlib.sha256(data).hexdigest()


def mask_key(image):
    return Image.frombytes("L", image.size,
        bytes(255 if rgb == KEY else 0 for rgb in zip(*[c.tobytes() for c in image.split()])))


def encode_like(original, painted):
    """Change only palette RGB bytes and pixel indices; keep the entire contract."""
    meta = parse_bmp(original)
    assert meta["bpp"] == 8 and meta["compression"] == 0 and meta["header_bytes"] == 40
    assert painted.size == (meta["width"], meta["height"])
    palette_at, count = meta["palette_offset"], meta["palette_count"]
    key_indices = [i for i in range(count)
                   if tuple(original[palette_at+i*4:palette_at+i*4+3][::-1]) == KEY]
    assert len(key_indices) <= 1
    key_index = key_indices[0] if key_indices else None
    original_rgb = Image.frombytes("RGB", painted.size, reference_rgb(original, meta))
    original_mask = mask_key(original_rgb)
    quantized = painted.quantize(colors=count-bool(key_indices), method=Image.Quantize.MEDIANCUT,
                                dither=Image.Dither.NONE)
    generated = quantized.getpalette()
    generated += [0] * (768-len(generated))
    available = [i for i in range(count) if i != key_index]
    mapping = [available[min(i, len(available)-1)] for i in range(256)]
    indices = quantized.point(mapping)
    if key_index is not None:indices.paste(key_index, mask=original_mask)
    raw_indices = indices.tobytes()
    output = bytearray(original)
    for index, slot in enumerate(available):
        color = generated[index*3:index*3+3]
        # Never introduce the native transparency key in an opaque pixel.
        if tuple(color) == KEY:
            color[2] = 1
        output[palette_at+slot*4:palette_at+slot*4+3] = bytes(color[::-1])
    stride, offset, width, height = (meta[k] for k in
                                   ("pixel_stride", "pixel_offset", "width", "height"))
    for y in range(height):
        row = y if meta["top_down"] else height-1-y
        at = offset + row*stride
        output[at:at+width] = raw_indices[y*width:(y+1)*width]
    result = bytes(output)
    verify(original, result)
    return result


def verify(before, after):
    a, b = parse_bmp(before), parse_bmp(after)
    assert a == b and len(before) == len(after) and before[:54] == after[:54]
    start, count = a["palette_offset"], a["palette_count"]
    assert before[start+3:start+count*4:4] == after[start+3:start+count*4:4]
    end = a["pixel_offset"]+a["pixel_bytes"]
    assert before[end:] == after[end:]
    for row in range(a["height"]):
        at = a["pixel_offset"]+row*a["pixel_stride"]+a["width"]
        assert before[at:at+a["pixel_stride"]-a["width"]] == after[at:at+a["pixel_stride"]-a["width"]]
    rgb_before = Image.frombytes("RGB", (a["width"], a["height"]), reference_rgb(before, a))
    rgb_after = Image.frombytes("RGB", rgb_before.size, reference_rgb(after, b))
    assert mask_key(rgb_before).tobytes() == mask_key(rgb_after).tobytes()
    from io import BytesIO
    with Image.open(BytesIO(after)) as decoder:
        assert decoder.convert("RGB").tobytes() == rgb_after.tobytes()
    return dict(header_and_file_size_preserved=True, row_padding_and_trailer_preserved=True,
                palette_capacity_and_reserved_bytes_preserved=True,
                transparency_mask_preserved=True, independent_decoder_matches=True,
                width=a["width"], height=a["height"], bpp=a["bpp"], bytes=len(after))


def icon(draw, name, color, surface, scale=4, x=105, y=48):
    # Larger silhouettes fit entirely above the original native label rectangle.
    zoom = 1.12
    def pts(points):
        return [((x+a*zoom)*scale, (y+b*zoom)*scale) for a, b in points]
    def line(points, width=3):
        coordinates = pts(points)
        draw.line(coordinates, fill=color, width=width*scale, joint="curve")
        radius = width*scale/2
        for a,b in (coordinates[0],coordinates[-1]):
            draw.ellipse((a-radius,b-radius,a+radius,b+radius),fill=color)
    def ellipse(box, fill=None, width=3):
        rect = ((x+box[0]*zoom)*scale, (y+box[1]*zoom)*scale,
                (x+box[2]*zoom)*scale, (y+box[3]*zoom)*scale)
        draw.ellipse(rect, fill=fill, outline=color if fill is None else None, width=width*scale)
    def shade(factor):
        return tuple(round(c*factor) for c in color)
    if name == "radio":
        ellipse((-8, -8, 8, 8), fill=color)
        line([(0, 5), (0, 31)], 5)
        for r in (20, 32):
            for side in (-1, 1):
                line([(side*r*math.cos(t), r*math.sin(t))
                      for t in [(-0.85+i*1.7/36) for i in range(37)]], 4)
    elif name == "media":
        ellipse((-31, -31, 31, 31), width=5)
        draw.polygon(pts([(-9, -15), (18, 0), (-9, 15)]), fill=color)
    elif name == "phone":
        contour=[(-26,-24),(-17,-30),(-10,-28),(-4,-15),(-7,-10),(-13,-6),
            (-5,5),(6,13),(11,7),(17,5),(30,12),(31,18),(25,27),(18,30),
            (5,26),(-10,16),(-23,1),(-29,-13)]
        for _ in range(2):
            contour=[point for a,b in zip(contour,contour[1:]+contour[:1])
                     for point in [(a[0]*.75+b[0]*.25,a[1]*.75+b[1]*.25),
                                   (a[0]*.25+b[0]*.75,a[1]*.25+b[1]*.75)]]
        draw.polygon(pts(contour), fill=color)
    elif name == "map":
        for points, fill in [([(-30,-22),(-10,-30),(-10,21),(-30,30)], color),
                       ([(-8,-30),(12,-20),(12,30),(-8,21)], shade(.62)),
                       ([(14,-20),(34,-30),(34,21),(14,30)], color)]:
            draw.polygon(pts(points), fill=fill)
    elif name == "navi":
        draw.polygon(pts([(0,-33),(0,15),(-28,28)]), fill=color)
        draw.polygon(pts([(0,-33),(28,28),(0,15)]), fill=shade(.78))
    elif name == "setting":
        gear=[]
        for i in range(48):
            angle = 2*math.pi*i/48
            radius = 30 if i%6 in (1,2,3,4) else 24
            gear.append((math.cos(angle)*radius, math.sin(angle)*radius))
        draw.polygon(pts(gear), fill=color)
        ellipse((-15,-15,15,15), fill=surface)
        ellipse((-11,-11,11,11), fill=color)
    elif name == "smartphone":
        # Smartphone launches voice assistance: retain the original speaking
        # profile / sound-wave meaning, rather than suggesting a headset.
        line([(-30,-29),(-23,-25),(-17,-17),(-10,-5),(-5,3),
              (-14,3),(-14,14),(-17,21),(-24,25),(-32,25)],4)
        for radius in (16,26,36):
            line([(-6+radius*math.cos(t),3+radius*math.sin(t))
                  for t in [-.78+i*1.56/36 for i in range(37)]],4)
    elif name == "driving eco":
        draw.polygon(pts([(-28,17),(-25,-8),(-10,-22),(28,-29),(26,2),(12,24),(-9,28)]), fill=color)
        draw.line(pts([(-29,31),(19,-18)]),fill=surface,width=3*scale)


def vertical_gradient(size, stops):
    image = Image.new("RGB", size)
    draw = ImageDraw.Draw(image)
    for y in range(size[1]):
        position = y / max(1, size[1]-1)
        for (a, ca), (b, cb) in zip(stops, stops[1:]):
            if a <= position <= b:
                t = (position-a)/(b-a)
                t = t*t*(3-2*t)
                color = tuple(round(v+(w-v)*t) for v,w in zip(ca,cb))
                draw.line((0,y,size[0],y), fill=color)
                break
    return image


def paint_tile(name, size, dark_active=False):
    fw, height = size[0]//4, size[1]
    scale = 4
    out = Image.new("RGB", (size[0]*scale, height*scale), BG)
    for state in range(4):
        if state == 0:
            surface, border, color = (24, 30, 34), (65, 74, 80), COLORS[name]
            stops = [(0,(38,45,50)),(.65,surface),(1,(18,24,28))]
        elif state == 1:
            surface, border, color = (51, 40, 19), (222, 163, 32), (230, 166, 31)
            stops = [(0,(61,48,22)),(.40,surface),(.78,(183,145,67)),(1,(193,155,79))]
        elif state == 2:
            surface, border, color = (20, 26, 31), (42, 52, 59), (100, 113, 122)
            stops = [(0,(26,33,38)),(1,(17,23,27))]
        else:
            surface, border, color = (59, 46, 20), (255, 190, 43), COLORS[name]
            stops = [(0,(68,53,24)),(.40,surface),(.78,(217,180,103)),(1,(230,194,124))]
        if dark_active and state in (1,3):
            surface, border, color = (0,0,0), COLORS[name], COLORS[name]
            stops = [(0,(0,0,0)),(1,(0,0,0))]
        tile = Image.new("RGB", (fw*scale, height*scale), BG)
        bounds = (3*scale,3*scale,(fw-4)*scale,(height-4)*scale)
        mask = Image.new("L", tile.size)
        ImageDraw.Draw(mask).rounded_rectangle(bounds, radius=10*scale, fill=255)
        tile.paste(vertical_gradient(tile.size,stops), mask=mask)
        rim = Image.new("L", tile.size)
        ImageDraw.Draw(rim).rounded_rectangle(bounds, radius=10*scale, outline=255,
                               width=round((1.8 if state in (1,3) else 1.4)*scale))
        rim_top = border if dark_active and state in (1,3) else tuple(min(255,c+10) for c in border)
        rim_bottom = tuple(round(c*(.87 if state in (1,3) else .72)) for c in border)
        if dark_active and state in (1,3):
            rim_bottom = border
        tile.paste(vertical_gradient(tile.size,[(0,rim_top),(1,rim_bottom)]),mask=rim)
        # Keep the selected icon warm, matching the reference's gold selection.
        if state in (1,3) and not dark_active:
            color = (249,190,44) if state == 3 else (230,166,31)
        # Transparent cutouts show the actual shaded tile rather than a flat patch.
        icon_layer = Image.new("RGBA", tile.size)
        icon(ImageDraw.Draw(icon_layer), name, color, (0,0,0,0),
             scale=scale, x=fw//2, y=48)
        # Solid accents and explicit facets stay clean in the native 256-color
        # palette. Extra icon gradients lose shades when all four states share it.
        tile.paste(icon_layer.convert("RGB"),mask=icon_layer.getchannel("A"))
        out.paste(tile,(state*fw*scale,0))
    return out.resize(size, Image.Resampling.BICUBIC)


def paint_chrome(source, is_header=False, is_dark=False, is_time=False):
    width, height = source.size
    result = Image.new("RGB", source.size, BG)
    draw = ImageDraw.Draw(result)
    if is_header:
        draw.line((0,77,width,77),fill=(43,52,58))
    elif is_dark:
        # The moon remains a native sprite; remove the old boxed button treatment.
        draw.line((0,77,width,77),fill=(43,52,58))
    elif is_time:
        fw = width//4
        for state in range(4):
            fill = BG if state in (0,2) else (225,192,125)
            draw.rounded_rectangle((state*fw+3,4,(state+1)*fw-4,height-5),
                                   radius=8,fill=fill,
                                   outline=(69,81,88) if state==0 else (48,59,67))
    else:
        draw.line((0,77,width,77),fill=(43,52,58))
    return result


def transparent(image):
    rgba = image.convert("RGBA")
    rgba.putalpha(ImageChops.invert(mask_key(image.convert("RGB"))))
    return rgba


def render(payload, scenario, states, show_time=False):
    imgroot = payload / REL
    screen = Image.open(imgroot/"common/home_bg.bmp").convert("RGB")
    for record in scenario["controls"]:
        if record["image_id"] in (0x35,0x37) and not show_time:
            continue
        if record["image_id"] in (0x30,0x31) and scenario["map_layout"] == 1:
            continue
        x,y,w,h=record["rect"]
        if not w or not h:
            continue
        image=Image.open(imgroot/record["filename"].replace("\\","/")).convert("RGB")
        state=states.get(record.get("event"),0)
        screen.paste(transparent(image.crop((state*w,0,(state+1)*w,h))),(x,y),
                     transparent(image.crop((state*w,0,(state+1)*w,h))))
        if record["kind"] == "button" and record.get("text"):
            label=record["label_rect"]
            color=record["colors"][state]
            rgb=(color&255,(color>>8)&255,(color>>16)&255)
            font=ImageFont.truetype("C:/Windows/Fonts/tahoma.ttf",28 if record["font_index"]==9 else 26)
            draw=ImageDraw.Draw(screen)
            box=draw.textbbox((0,0),record["text"],font=font)
            draw.text((label[0]+(label[2]-(box[2]-box[0]))/2,
                       label[1]+(label[3]-(box[3]-box[1]))/2-box[1]),
                      record["text"],fill=rgb,font=font)
    # The clock uses original digit/semicolon resources at the native indicator
    # coordinates from 0x149xx. Runtime theme transforms and actual time are not simulated.
    digits=Image.open(imgroot/"common/common_indi_clock_number_img.bmp").convert("RGB")
    colon=Image.open(imgroot/"common/common_indi_semicolon_img.bmp").convert("RGB")
    for x,num in zip((686,708,744,766),(0,9,5,8)):
        frame=transparent(digits.crop((num*20,0,(num+1)*20,33)))
        screen.paste(frame,(x,16),frame)
    frame=transparent(colon);screen.paste(frame,(731,16),frame)
    return screen


def build(out, preview, white_active_labels=False):
    assert not out.exists(), "Use a fresh output directory; prior candidates are preserved"
    with (ROOT/"analysis/705md-inventory.csv").open(encoding="utf-8",newline="") as stream:
        baseline=list(csv.DictReader(stream))
    for row in baseline:
        assert sha((BASE/row["path"]).read_bytes()) == row["sha256"]
    payload=out/"payload"
    shutil.copytree(BASE/"upgrade",payload/"upgrade")
    changed=[]
    for relative in ALLOWLIST:
        before=(BASE/relative).read_bytes()
        original=Image.open(BASE/relative).convert("RGB")
        if relative.name in MAIN_NAMES:
            name=relative.stem.removeprefix("home_").removesuffix("_btn").replace("_second line","")
            painting=paint_tile(name,original.size,dark_active=white_active_labels)
        else:
            painting=paint_chrome(original,is_header=relative.name=="common_indi_line.bmp",
                                  is_dark=relative.name=="home_dark_btn.bmp",
                                  is_time=relative.name=="home_set time_btn.bmp")
        after=encode_like(before,painting)
        (payload/relative).write_bytes(after)
        readback=(payload/relative).read_bytes()
        changed.append(dict(path=relative.as_posix(),original_sha256=sha(before),sha256=sha(readback),
                            verification=verify(before,readback)))
    changed_names={r["path"] for r in changed}
    text_proof=None
    if white_active_labels:
        from patch_home_text_colors import patch
        app_relative=Path("upgrade/Storage Card/System/AppMain.exe")
        before=(BASE/app_relative).read_bytes()
        after,text_proof=patch(before)
        (payload/app_relative).write_bytes(after)
        assert (payload/app_relative).read_bytes()==after
        changed.append(dict(path=app_relative.as_posix(),original_sha256=sha(before),
                            sha256=sha(after),verification={k:v for k,v in text_proof.items() if k!='scenarios'}))
        changed_names.add(app_relative.as_posix())
        (out/"home-text-color-proof.json").write_text(json.dumps(text_proof,indent=2)+"\n",encoding="utf-8")
    members=[]
    for row in baseline:
        relative=row["path"]; data=(payload/relative).read_bytes()
        if relative not in changed_names:
            assert sha(data) == row["sha256"]
        assert sha((BASE/relative).read_bytes()) == row["sha256"]
        members.append(dict(path=relative,bytes=len(data),sha256=sha(data)))
    assert len(members)==1917 and len(changed_names)==len(ALLOWLIST)+bool(white_active_labels)
    assert {p.relative_to(payload).as_posix() for p in payload.rglob('*') if p.is_file()} == {r['path'] for r in baseline}
    layout=json.loads((ROOT/"analysis/firmware/home-layout.json").read_text(encoding="utf-8"))
    original_cases=[s for s in layout["scenarios"] if s["resource_profile"]==1]
    cases=[s for s in (text_proof or layout)["scenarios"] if s["resource_profile"]==1]
    home_dir=preview/"home"
    for variant,root in [("original",BASE),("themed",payload)]:
        for source in (root/REL).rglob("*.bmp"):
            if source.parent.name not in ("common","home"):
                continue
            image=Image.open(source).convert("RGB")
            if source.parent.name=="common" and source.name not in ("home_bg.bmp","common_indi_clock_number_img.bmp","common_indi_semicolon_img.bmp"):
                continue
            target=home_dir/variant/source.relative_to(root/REL).with_suffix(".png")
            target.parent.mkdir(parents=True,exist_ok=True)
            transparent(image).save(target)
    regular=next(s for s in cases if not s['eco'] and not s['map_layout'] and not s['smartphone'])
    renders=out/"renders";renders.mkdir()
    for variant,root in [("original",BASE),("themed",payload)]:
        for name,states in [("normal",{}),("selected",{1006:3}),("pressed",{1006:1}),
                            ("disabled",{1001:2,1002:2,1006:2})]:
            case=original_cases[0] if variant=="original" else regular
            render(root,case,states).save(renders/f"home-{variant}-{name}.png")
    (preview/"home.json").write_text(json.dumps(dict(scenarios=cases,
        baseline="7.0.5.MD / M1",changed_assets=len(ALLOWLIST),unchanged_files=1917-len(changed),
        original_scenarios=original_cases,white_active_labels=white_active_labels,
        font_heights=[16,18,20,21,22,23,24,25,26,28,29,30,32,34,36,39,40,42,45,50,60,65],
        font_preview="Host Tahoma approximation; native glyph metrics not validated",
        native_execution=False,hardware_tested=False),indent=2)+"\n",encoding="utf-8")
    result=dict(kind="Home-screen development; not an installable update",
        baseline="7.0.5.MD",profile="M1",changed=changed,changed_files=len(changed),
        unchanged_files=1917-len(changed),members=members,executables_unchanged=not white_active_labels,
        white_active_labels=white_active_labels,home_text_color_patch=bool(text_proof),
        byte_contracts_verified=True,native_execution=False,hardware_tested=False,
        installation_ready=False,version_changed=False,lgu_built=False,
        layout_proof_sha256=sha((ROOT/"analysis/firmware/home-layout.json").read_bytes()),
        limitations=["Home only; other screens and inverse profile remain original",
                     "Transparency mask is preserved but native key behavior remains unverified",
                     "Desktop Tahoma rendering approximates native text metrics"])
    (out/"manifest.json").write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8")
    (out/"README.md").write_text("# Charcoal home skin development\n\n"
        f"Complete 1,917-file original 7.0.5.MD payload. 14 M1 home images change; "
        f"{1917-len(changed)} files remain byte-identical. "
        "No LGU, version change or device installation.\n\n"
        "All original BMP headers, dimensions, bit depth, palette capacity, transparent-key "
        "mask, row padding, trailing bytes and file sizes are preserved. The independent BMP "
        "reference reader agrees with Pillow. No new text is baked into assets.\n\n"
        "See manifest.json, renders/ and the browser workbench's Home preview. Its fonts "
        "are an approximation. Native loading and rendering require unit checks. "
        "The full system theme and inverted/day profile are not yet implemented.\n",encoding="utf-8")
    if white_active_labels:
        with (out/"README.md").open('a',encoding='utf-8') as stream:
            stream.write("\nThis candidate uses black pressed/selected tile backgrounds, function-colored "
                         "borders/icons and white labels. AppMain.exe differs in exactly two bytes in "
                         "two home text-color store instructions. All 24 bounded layout cases match "
                         "the original except those two colors. The color array is shared across all "
                         "home profiles; M0/inverse artwork still needs review before installation. "
                         "This is no longer an executable-unchanged resource-only candidate.\n")
    print(json.dumps({"output":str(out),"changed_images":len(ALLOWLIST),
                      "unchanged_files":1917-len(changed),"layout_cases":len(cases),
                      "byte_contracts_verified":True,"home_text_color_patch":white_active_labels},indent=2))


if __name__=="__main__":
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out",type=Path,required=True,
                        help="Fresh development output directory; existing candidates are never overwritten")
    parser.add_argument("--preview",type=Path,default=ROOT/"build/ui-theme-preview-01")
    parser.add_argument("--white-active-labels",action="store_true",
                        help="Black active tiles with two verified home text-color store changes")
    args=parser.parse_args();build(args.out.resolve(),args.preview.resolve(),args.white_active_labels)
