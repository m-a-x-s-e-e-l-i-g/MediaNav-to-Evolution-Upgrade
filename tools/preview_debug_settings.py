"""Native-resource PC reconstruction of MAX19 Settings; not a device screenshot."""
import argparse,json
from pathlib import Path
from PIL import Image,ImageDraw,ImageFont
from build_home_theme import transparent

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'build/max18-navigation-launch-development-01/payload/upgrade/Storage Card/System/Img'
FONT='C:/Windows/Fonts/tahoma.ttf'


def render(bank,on):
    cases=json.loads((ROOT/'build/settings-nav-design/layouts.json').read_bytes())['scenarios']
    controls=next(c['controls'] for c in cases if c['name']=='System settings')
    folder=BASE/bank;image=Image.open(folder/'common/setting_bg.bmp').convert('RGB')
    ink=(28,38,45) if bank=='M1_INV' else (255,255,255)
    for r in controls:
        off=r['object_offset'];event=r.get('event')
        if event in [1001,1002,1003,1005,1012,1013] or off=='0x4140':continue
        x,y,w,h=r['rect'];name=r.get('filename')
        state=3 if event==1009 else 0
        if name:
            src=Image.open(folder/name.replace('\\','/')).convert('RGB')
            frames=4 if '_btn' in name or name.endswith('_press.bmp') else max(1,src.width//w)
            fw=src.width//frames;crop=transparent(src.crop((state*fw,0,state*fw+min(w,fw),min(h,src.height))))
            image.paste(crop,(x,y),crop.getchannel('A'))
        text=r.get('text') or ''
        if off=='0x44d4':text='2/2'
        if text:
            tx,ty,tw,th=r.get('label_rect',r['rect']);center=event is not None and event>=1006
            fill=(255,255,255) if state==3 else ink
            ImageDraw.Draw(image).text((tx+tw/2 if center else tx,ty+th/2),text,
                font=ImageFont.truetype(FONT,26 if y<80 else 24),fill=fill,anchor='mm' if center else 'lm')
    row=next(r for r in controls if r.get('event')==1001)
    src=Image.open(folder/row['filename'].replace('\\','/')).convert('RGB');fw=src.width//4
    crop=transparent(src.crop((fw*(3 if on else 0),0,fw*(3 if on else 0)+694,69)))
    image.paste(crop,(10,177),crop.getchannel('A'))
    draw=ImageDraw.Draw(image);font=ImageFont.truetype(FONT,24)
    draw.text((72,211.5),'Debugging: On' if on else 'Debugging: Off',font=font,fill=(255,255,255) if on else ink,anchor='lm')
    draw.text((72,280.5),'Logging active' if on else 'Logging off',font=font,fill=ink,anchor='lm')
    return image


def build(out):
    out.mkdir(parents=True,exist_ok=True)
    overview=Image.new('RGB',(1600,960))
    for j,(bank,on) in enumerate([('M1',False),('M1',True),('M1_INV',False),('M1_INV',True)]):
        image=render(bank,on);image.save(out/f'debugging-{bank}-{int(on)}.png');overview.paste(image,((j%2)*800,(j//2)*480))
    overview.save(out/'debugging-overview.png')
    return out/'debugging-overview.png'

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();print(build(a.output))
