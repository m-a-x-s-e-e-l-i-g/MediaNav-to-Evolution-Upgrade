"""Carry forward a complete candidate and replace only its M1 radio source-menu bottom sheet."""
import argparse
import copy
import json
import shutil
from pathlib import Path
from PIL import Image
from build_home_theme import ROOT, BASE, REL, sha, encode_like, verify, transparent
from build_av_theme import paint_button, COLORS

NAME='fm radio/fmradio_fulldown_bottom_btn.bmp'

def update(previous,out):
    assert not out.exists(),'Use a fresh output directory'
    source=previous/'payload'
    manifest=json.loads((previous/'manifest.json').read_text(encoding='utf-8'))
    for member in manifest['members']:
        assert sha((source/member['path']).read_bytes())==member['sha256']
    assert len(manifest['members'])==1917
    payload=out/'payload';shutil.copytree(source,payload)
    relative=REL/NAME;original=(BASE/relative).read_bytes()
    painted=paint_button(Image.open(BASE/relative).convert('RGB'),Path(NAME).name,COLORS['radio'])
    result=encode_like(original,painted);(payload/relative).write_bytes(result)
    change=dict(path=relative.as_posix(),previous_sha256=sha((source/relative).read_bytes()),
                sha256=sha(result),verification=verify(original,result))
    assert change['previous_sha256']!=change['sha256']
    members=[]
    for member in manifest['members']:
        raw=(payload/member['path']).read_bytes()
        if member['path']!=relative.as_posix():assert sha(raw)==member['sha256']
        members.append(dict(path=member['path'],bytes=len(raw),sha256=sha(raw)))
    assert {p.relative_to(payload).as_posix() for p in payload.rglob('*') if p.is_file()}=={m['path'] for m in members}
    updated=copy.deepcopy(manifest)
    image_entry=next(row for row in updated['changed_images'] if row['path']==relative.as_posix())
    image_entry.update(sha256=change['sha256'],verification=change['verification'])
    updated.update(previous=previous.name,members=members,radio_source_bottom_update=change,
                   changed_files_from_previous=1,unchanged_files_from_previous=1916)
    (out/'manifest.json').write_text(json.dumps(updated,indent=2)+'\n',encoding='utf-8')
    shutil.copyfile(previous/'av-text-color-proof.json',out/'av-text-color-proof.json')
    preview=ROOT/'build/ui-theme-preview-01'
    decoded=transparent(Image.open(payload/relative).convert('RGB'))
    decoded.save(preview/'av/themed'/Path(NAME).with_suffix('.png'))
    renders=out/'renders';renders.mkdir();decoded.save(renders/'radio-source-bottom.png')
    for name in ['home.json','av.json']:
        data=json.loads((preview/name).read_text(encoding='utf-8'));data['candidate']=out.name
        if name=='av.json':data['asset_revision']=change['sha256']
        (preview/name).write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
    (out/'README.md').write_text('# Radio source-menu bottom border fix\n\n'
        f'Full 1,917-file candidate copied from {previous.name}. Only the M1 '
        '576 x 92 source-menu bottom sheet changes: each 144 x 65 visible face gets a complete border above its 27 native transparent padding rows. '
        'Native BMP dimensions, headers, format, transparency, padding and trailer are verified. '
        'All other 1,916 payload files, including AppMain and the previous Smartphone, album, caller-avatar, search-toggle and media source-menu corrections, '
        'remain byte-identical. Development preview; no device installation performed.\n',encoding='utf-8')
    print(json.dumps(dict(candidate=out.name,members=len(members),changed=1,unchanged=1916,
                         verification=change['verification']),indent=2))

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--from',dest='previous',type=Path,required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args();update(args.previous.resolve(),args.out.resolve())
