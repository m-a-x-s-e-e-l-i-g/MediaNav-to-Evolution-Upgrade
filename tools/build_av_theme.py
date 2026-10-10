"""Author AV skin resources at native geometry, retaining the complete home-07 payload."""
import argparse
import csv
import json
import shutil
from pathlib import Path
from PIL import Image, ImageDraw, ImageChops
from build_home_theme import ROOT, BASE, REL, BG, COLORS, KEY, sha, encode_like, verify, transparent, vertical_gradient

FAMILIES={'fm radio':'radio','media':'media','Phone':'phone'}
PREVIOUS=ROOT/'build/home-theme-development-07/payload'
PREVIEW=ROOT/'build/ui-theme-preview-01'

def glyph_mask(frame):
    """Keep native baked glyph pixels; exclude the old rectangular rim."""
    w,h=frame.size
    data=[]
    for y in range(h):
        for x in range(w):
            rgb=frame.getpixel((x,y));hi=max(rgb);lo=min(rgb)
            data.append(round(max(0,min(1,(lo-125)/95))*255)
                        if 5<=x<w-5 and 5<=y<h-5 and hi-lo<65 and rgb!=KEY else 0)
    return Image.frombytes('L',frame.size,bytes(data))

def panel(size,accent,state=0,soft=False):
    w,h=size;s=3
    out=Image.new('RGB',(w*s,h*s),BG)
    mask=Image.new('L',out.size);d=ImageDraw.Draw(mask)
    inset=2 if soft else 3
    radius=min(10,h/5)
    box=(inset*s,inset*s,(w-inset-1)*s,(h-inset-1)*s)
    d.rounded_rectangle(box,radius=radius*s,fill=255)
    active=state in (1,3)
    stops=[(0,(0,0,0)),(1,(0,0,0))] if active else [(0,(34,41,46)),(1,(18,24,28))]
    if state==2:stops=[(0,(23,29,33)),(1,(15,20,24))]
    out.paste(vertical_gradient(out.size,stops),mask=mask)
    rim=Image.new('L',out.size)
    ImageDraw.Draw(rim).rounded_rectangle(box,radius=radius*s,outline=255,width=(2 if active else 1)*s)
    out.paste(accent if active else (48,58,64) if state!=2 else (33,42,47),mask=rim)
    return out.resize(size,Image.Resampling.LANCZOS)

def paint_button(source,name,accent):
    call=name=='phone_dial_btn_call.bmp'
    banks=2 if call or name=='phone_keyboard_search_results_list_down_btn.bmp' else 1
    count=4*banks;fw=source.width//count;assert fw*count==source.width
    out=Image.new('RGB',source.size,BG)
    for bank in range(banks):
        normal=source.crop((bank*4*fw,0,(bank*4+1)*fw,source.height))
        mask=glyph_mask(normal)
        # Source-menu bottom sheets have keyed padding below their 65px faces.
        # Keep the rim inside the visible face; encoding restores the key mask.
        source_bottom=name in ('media_fulldown_bottom_btn.bmp','fmradio_fulldown_bottom_btn.bmp')
        face_height=65 if source_bottom else source.height
        if source_bottom:
            assert source.height>65 and transparent(normal).getbbox()==(0,0,fw,65)
        local_accent=(65,205,139) if call and bank==0 else (239,96,105) if call else accent
        number='dial_num_' in name
        for state in range(4):
            frame=Image.new('RGB',(fw,source.height),BG)
            frame.paste(panel((fw,face_height),local_accent,state,soft='softkey' in name),(0,0))
            color=(91,105,114) if state==2 else (238,243,247) if number or 'softkey' in name or 'keyboard' in name else local_accent
            frame.paste(color,mask=mask)
            out.paste(frame,((bank*4+state)*fw,0))
    return out

def paint_no_album(size):
    """Quiet neutral artwork; preserve the native album slot and BMP contract."""
    w,h=size;s=4
    out=Image.new('RGB',(w*s,h*s),BG)
    d=ImageDraw.Draw(out)
    box=(3*s,3*s,(w-4)*s,(h-4)*s)
    d.rounded_rectangle(box,radius=10*s,fill=(18,24,28),outline=(37,46,52),width=s)
    cx,cy=w/2,h/2
    # A small paired note, optically centered, with generous negative space.
    ink=(69,81,89)
    def rect(coords):return tuple(round(v*s) for v in coords)
    d.rounded_rectangle(rect((cx-18,cy-28,cx-12,cy+22)),radius=3*s,fill=ink)
    d.rounded_rectangle(rect((cx+20,cy-36,cx+26,cy+14)),radius=3*s,fill=ink)
    d.polygon([((cx-18)*s,(cy-28)*s),((cx+26)*s,(cy-36)*s),
               ((cx+26)*s,(cy-25)*s),((cx-18)*s,(cy-17)*s)],fill=ink)
    d.ellipse(rect((cx-37,cy+10,cx-12,cy+29)),fill=ink)
    d.ellipse(rect((cx+1,cy+2,cx+26,cy+21)),fill=ink)
    return out.resize(size,Image.Resampling.LANCZOS)

def paint_call_time_area(size):
    """A low-contrast caller silhouette behind the native dynamic time label."""
    w,h=size
    out=Image.new('RGB',size,BG)
    ImageDraw.Draw(out).ellipse((5,5,w-6,h-6),fill=(20,27,31),outline=(48,60,68),width=2)
    s=4;cx=w/2
    silhouette=Image.new('RGBA',(w*s,h*s))
    d=ImageDraw.Draw(silhouette);ink=(32,43,50,255)
    def rect(coords):return tuple(round(v*s) for v in coords)
    d.ellipse(rect((cx-25,h*.20,cx+25,h*.20+50)),fill=ink)
    d.ellipse(rect((cx-53,h*.48,cx+53,h*.48+66)),fill=ink)
    d.rounded_rectangle(rect((cx-53,h*.65,cx+53,h*.81)),radius=6*s,fill=ink)
    silhouette=silhouette.resize(size,Image.Resampling.LANCZOS)
    out.paste(silhouette,mask=silhouette.getchannel('A'))
    return out

def paint_static(source,name,accent):
    w,h=source.size
    if name.endswith('_bg.bmp') and source.size==(800,480):
        out=Image.new('RGB',source.size,BG);d=ImageDraw.Draw(out)
        d.line((0,77,799,77),fill=(37,46,52));return out
    if 'fulldown' in name or 'indi_line' in name:
        out=Image.new('RGB',source.size,BG)
        ImageDraw.Draw(out).line((0,77,w,77),fill=(43,52,58))
        return out
    if 'album_case_noalbum' in name:
        return paint_no_album(source.size)
    if 'progress_bar' in name:
        # Native mask: the baseline occupies the last two rows, while the
        # filled half occupies rows 1..5. Paint the existing opaque pixels.
        out=Image.new('RGB',source.size,BG)
        for y in range(h):
            for x in range(w):
                if source.getpixel((x,y))!=KEY:
                    out.putpixel((x,y),(66,77,84) if y>=h-2 else accent)
        return out
    if 'call_time_area' in name:
        return paint_call_time_area(source.size)
    if 'line' in name:
        out=Image.new('RGB',source.size,BG);d=ImageDraw.Draw(out)
        if w<=4:d.line((1,0,1,h),fill=(41,51,57))
        else:
            for y in range(0,h,70):d.line((0,y,w,y),fill=(41,51,57))
        return out
    if name.endswith('_press.bmp'):
        return paint_button(source,name,accent)
    if 'scrollnumber' in name or 'presest_number' in name or 'folder_name' in name or 'search_type_bg' in name:
        return panel(source.size,accent)
    # Keyed icon strips keep every frame's silhouette and location, including
    # semantic call-log types and animation frames. Opaque images retain texture.
    out=Image.new('RGB',source.size,BG)
    pixels=[]
    keyed=any(rgb==KEY for rgb in source.getdata())
    for rgb in source.getdata():
        if rgb==KEY:pixels.append(KEY);continue
        hi,lo=max(rgb),min(rgb)
        if keyed:
            factor=.68+.32*hi/255
            pixels.append(tuple(round(c*factor) for c in accent))
        elif hi-lo>45 and hi>55:
            factor=.55+.45*hi/255
            pixels.append(tuple(round(c*factor) for c in accent))
        elif hi>180:pixels.append((229,237,242))
        else:pixels.append(tuple(round(BG[i]+rgb[i]*.13) for i in range(3)))
    out.putdata(pixels);return out

def build(out):
    assert not out.exists(),'Use a fresh output directory'
    previous=json.loads((PREVIOUS.parent/'manifest.json').read_text())
    for member in previous['members']:assert sha((PREVIOUS/member['path']).read_bytes())==member['sha256']
    payload=out/'payload';shutil.copytree(PREVIOUS,payload)
    files=[p for folder in FAMILIES for p in (BASE/REL/folder).glob('*.bmp')]
    files += [BASE/REL/'common'/f'{prefix}_bg.bmp' for prefix in ('fmradio','media','phone')]
    changed=[]
    for file in files:
        relative=file.relative_to(BASE);before=file.read_bytes();source=Image.open(file).convert('RGB')
        name=file.name;family=FAMILIES.get(file.parent.name,{'fmradio_bg.bmp':'radio','media_bg.bmp':'media','phone_bg.bmp':'phone'}[name] if file.parent.name=='common' else '')
        assert family in COLORS
        painted=paint_button(source,name,COLORS[family]) if '_btn' in name else paint_static(source,name,COLORS[family])
        after=encode_like(before,painted);(payload/relative).write_bytes(after)
        changed.append(dict(path=relative.as_posix(),original_sha256=sha(before),sha256=sha(after),verification=verify(before,after)))
    # AV text colors are separately bounded and verified, never inferred from images.
    from patch_av_text_colors import patch
    app_relative=Path('upgrade/Storage Card/System/AppMain.exe')
    raw=(PREVIOUS/app_relative).read_bytes()
    cached=ROOT/'build/av-text-color-proof.json'
    proof=json.loads(cached.read_text()) if cached.exists() else None
    if proof and proof['before_sha256']==sha(raw) and proof['bounded_cases_verified']==106 and proof.get('layout_sha256')==sha((ROOT/'analysis/firmware/av-layouts.json').read_bytes()):
        import pefile
        pe=pefile.PE(data=raw);buffer=bytearray(raw)
        for edit in proof['edits']:
            off=pe.get_offset_from_rva(int(edit['va'],16)-pe.OPTIONAL_HEADER.ImageBase)
            assert int.from_bytes(raw[off:off+4],'little')==int(edit['before'],16)
            buffer[off:off+4]=int(edit['after'],16).to_bytes(4,'little')
        after=bytes(buffer);assert sha(after)==proof['after_sha256']
    else:after,proof=patch(raw)
    (payload/app_relative).write_bytes(after)
    (out/'av-text-color-proof.json').write_text(json.dumps(proof,indent=2)+'\n')
    with (ROOT/'analysis/705md-inventory.csv').open(encoding='utf-8',newline='') as stream:baseline=list(csv.DictReader(stream))
    names={r['path'] for r in changed}|{app_relative.as_posix()};previous_changes={r['path'] for r in previous['changed']}
    members=[]
    for row in baseline:
        data=(payload/row['path']).read_bytes();assert sha((BASE/row['path']).read_bytes())==row['sha256']
        if row['path'] not in names:assert sha(data)==sha((PREVIOUS/row['path']).read_bytes())
        members.append(dict(path=row['path'],bytes=len(data),sha256=sha(data)))
    assert len(members)==1917
    assert {p.relative_to(payload).as_posix() for p in payload.rglob('*') if p.is_file()}=={r['path'] for r in baseline}
    total_names=names|previous_changes
    result=dict(kind='Radio/media/phone development skin; not an installable update',baseline='7.0.5.MD',profile='M1',
        previous='home-theme-development-07',changed_images=changed,changed_image_count=len(changed),
        changed_files_from_original=len(total_names),unchanged_files_from_original=1917-len(total_names),
        members=members,byte_contracts_verified=True,positions_unchanged=True,navigation_excluded=True,
        av_text_color_stores=len(proof['edits']),native_execution=False,hardware_tested=False,
        installation_ready=False,version_changed=False,lgu_built=False,
        limitations=['Bounded constructor snapshots use external-call fixtures, not native execution',
                     'M0 and inverse artwork remains original; shared text colors require profile review',
                     'Native glyph metrics, runtime visibility and loading require unit verification'])
    (out/'manifest.json').write_text(json.dumps(result,indent=2)+'\n')
    # Export decoded images of the actual payload, not alternate web artwork.
    asset_names={p.relative_to(BASE/REL).as_posix() for p in files}
    layouts=json.loads((ROOT/'analysis/firmware/av-layouts.json').read_text())
    for case in layouts['scenarios']:
        asset_names.update(r['filename'].replace('\\','/') for r in case['controls'] if r['filename'])
    asset_names.update(['common/common_indi_clock_number_img.bmp','common/common_indi_semicolon_img.bmp','common/common_indi_fulldown_img.bmp'])
    for variant,root in [('original',BASE),('themed',payload)]:
        for name in sorted(asset_names):
            source=root/REL/name
            if not source.exists():continue
            target=PREVIEW/'av'/variant/Path(name).with_suffix('.png');target.parent.mkdir(parents=True,exist_ok=True)
            transparent(Image.open(source).convert('RGB')).save(target)
    import copy
    def browser_cases(cases):
        result=copy.deepcopy(cases)
        for case in result:
            for control in case['controls']:
                control.pop('color_stores',None)
                if control.get('secondary_label'):control['secondary_label'].pop('color_stores',None)
        return result
    (PREVIEW/'av.json').write_text(json.dumps(dict(scenarios=browser_cases(proof['scenarios']),original_scenarios=browser_cases(layouts['scenarios']),
        changed_assets=len(changed),unchanged_files=result['unchanged_files_from_original'],
        text_color_edits=len(proof['edits']),native_execution=False,hardware_tested=False,
        font_heights=[16,18,20,21,22,23,24,25,26,28,29,30,32,34,36,39,40,42,45,50,60,65]),indent=2)+'\n')
    (out/'README.md').write_text('# Radio / Media / Phone development skin\n\n'
        'Full 1,917-file payload based on home-theme-development-07. Native control positions and BMP contracts retained. '
        'Navigation excluded. No LGU, flashing, installation or version change.\n\n'
        'See manifest.json, av-text-color-proof.json and the local browser preview. This is a development candidate: '
        'external calls are fixture stubs, fonts are approximate, and native rendering/visibility is not verified. '
        'M0/inverse profiles need review because cosmetic text-color arrays are shared.\n',encoding='utf-8')
    print(json.dumps({k:result[k] for k in ['changed_image_count','changed_files_from_original','unchanged_files_from_original','av_text_color_stores']},indent=2))

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--out',type=Path,required=True)
    build(parser.parse_args().out.resolve())
