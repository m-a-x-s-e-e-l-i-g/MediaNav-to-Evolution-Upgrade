"""Copy a complete candidate and replace only its two M1 Smartphone home sheets."""
import argparse
import copy
import json
import shutil
from pathlib import Path
from PIL import Image
from build_home_theme import ROOT, BASE, REL, sha, paint_tile, encode_like, verify, transparent, render

NAMES=['home_smartphone_btn.bmp','home_smartphone_second line_btn.bmp']

def update(previous,out):
    assert not out.exists(),'Use a fresh output directory'
    source=previous/'payload';manifest=json.loads((previous/'manifest.json').read_text())
    for member in manifest['members']:assert sha((source/member['path']).read_bytes())==member['sha256']
    assert len(manifest['members'])==1917
    payload=out/'payload';shutil.copytree(source,payload)
    changes=[]
    for name in NAMES:
        relative=REL/'home'/name;original=(BASE/relative).read_bytes()
        painted=paint_tile('smartphone',Image.open(BASE/relative).size,dark_active=True)
        result=encode_like(original,painted);(payload/relative).write_bytes(result)
        changes.append(dict(path=relative.as_posix(),previous_sha256=sha((source/relative).read_bytes()),
            sha256=sha(result),verification=verify(original,result)))
        target=ROOT/'build/ui-theme-preview-01/home/themed/home'/Path(name).with_suffix('.png')
        transparent(Image.open(payload/relative).convert('RGB')).save(target)
    allowed={r['path'] for r in changes};members=[]
    for member in manifest['members']:
        data=(payload/member['path']).read_bytes()
        if member['path'] not in allowed:assert sha(data)==member['sha256']
        members.append(dict(path=member['path'],bytes=len(data),sha256=sha(data)))
    assert {p.relative_to(payload).as_posix() for p in payload.rglob('*') if p.is_file()}=={m['path'] for m in members}
    result=copy.deepcopy(manifest);result.update(previous=previous.name,members=members,
        smartphone_icon_update=changes,changed_files_from_previous=2,
        unchanged_files_from_previous=1915)
    (out/'manifest.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    for name in ['av-text-color-proof.json']:
        if (previous/name).exists():shutil.copyfile(previous/name,out/name)
    preview=ROOT/'build/ui-theme-preview-01';home=json.loads((preview/'home.json').read_text())
    home['candidate']=out.name;home['smartphone_icon']='Speaking profile and sound waves'
    (preview/'home.json').write_text(json.dumps(home,indent=2)+'\n',encoding='utf-8')
    av=json.loads((preview/'av.json').read_text());av['candidate']=out.name
    (preview/'av.json').write_text(json.dumps(av,indent=2)+'\n',encoding='utf-8')
    case=next(c for c in home['scenarios'] if c['smartphone'] and not c['eco'] and not c['map_layout'])
    renders=out/'renders';renders.mkdir()
    event=next(c['event'] for c in case['controls'] if c.get('text')=='Smartphone')
    for state in range(4):render(payload,case,{event:state}).save(renders/f'smartphone-state-{state}.png')
    (out/'README.md').write_text('# Voice-assistant Smartphone icon\n\n'
        f'Full 1,917-file candidate copied from {previous.name}. Only two M1 Smartphone home BMPs change. '
        'Speaking profile and sound waves replace the headset. Native dimensions, all four states, '
        'BMP contracts and transparency masks are retained. All other 1,915 files, including '
        'AppMain and every radio/media/phone resource, remain byte-identical to the previous candidate. '
        'Development only; no installation, LGU, flashing or hardware validation.\n',encoding='utf-8')
    print(json.dumps(dict(candidate=out.name,members=len(members),changed=2,unchanged=1915,
        executable_unchanged_from_previous=True),indent=2))

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--from',dest='previous',type=Path,required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args();update(args.previous.resolve(),args.out.resolve())
