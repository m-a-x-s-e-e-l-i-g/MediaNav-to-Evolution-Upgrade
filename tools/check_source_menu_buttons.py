"""Regression check: lower borders must remain above native transparent padding."""
import argparse
import json
from pathlib import Path
from PIL import Image
from build_home_theme import BASE, REL, COLORS, KEY, transparent

def check(payload):
    results=[]
    for folder,name,family in [('fm radio','fmradio_fulldown_bottom_btn.bmp','radio'),
                               ('media','media_fulldown_bottom_btn.bmp','media')]:
        original=Image.open(BASE/REL/folder/name).convert('RGB')
        image=Image.open(payload/REL/folder/name).convert('RGB')
        assert image.size==original.size
        fw=image.width//4
        for state in range(4):
            frame=image.crop((state*fw,0,(state+1)*fw,image.height))
            native=original.crop((state*fw,0,(state+1)*fw,original.height))
            assert transparent(frame).getchannel('A').tobytes()==transparent(native).getchannel('A').tobytes()
            _,_,_,face_height=transparent(native).getbbox()
            assert face_height==65 and image.height>face_height
            expected=COLORS[family] if state in (1,3) else (33,42,47) if state==2 else (48,58,64)
            # Look for the lower rim in the visible face. Previously it was
            # drawn into the keyed rows and disappeared during BMP encoding.
            errors=[min(max(abs(frame.getpixel((x,y))[i]-expected[i]) for i in range(3))
                        for y in range(face_height-10,face_height)) for x in range(20,fw-20)]
            # Lanczos can overshoot the bright cyan rim before palette encoding.
            tolerance=32 if state in (1,3) else 16
            assert max(errors)<=tolerance,(name,state,max(errors))
            assert all(frame.getpixel((x,y))==KEY for y in range(face_height,image.height) for x in range(fw))
            results.append(dict(name=name,state=state,visible_height=face_height,
                                padding_rows=image.height-face_height,max_rim_error=max(errors)))
    return results

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('payload',type=Path)
    parser.add_argument('--proof',type=Path)
    args=parser.parse_args();results=check(args.payload)
    if args.proof:args.proof.write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8')
    print(f'{len(results)} source-menu button states passed; native transparency and visible lower rims retained.')
