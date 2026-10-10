"""Refresh MAX04 documentation and screenshots without changing its LGU."""
import hashlib
import json
import re
import shutil
import zipfile
from pathlib import Path
from PIL import Image

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'build/maxmade-7.0.6.MAX04'
REPO=ROOT/'sources/MediaNav-MAX04-PR'
PACKAGE=REPO/'Upgrade_706MAX04_MAXmade'
HASH='94bb17ac6df670eb17927a7be627620a2a04cd2d64e92c042fb49c650a6187b0'

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def read(path):return json.loads(path.read_text(encoding='utf-8'))
def write(path,value):path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')

def links(path):
    for reference in re.findall(r'!?\[[^\]]*\]\(([^)]+)\)',path.read_text(encoding='utf-8')):
        if reference.startswith(('https://','http://','#')):continue
        target=(path.parent/reference.split('#')[0]).resolve()
        assert target.exists(),(path,reference)

def main():
    assert sha(OUT/'upgrade.lgu')==HASH
    staging=read(OUT/'staging-manifest.json');manifest=read(OUT/'build-manifest.json')
    proof_hash=sha(OUT/'integration-proof.json')
    assert proof_hash==staging['integration_proof_sha256']==manifest['integration_proof_sha256']
    original=OUT/'build-sources/build_cumulative_maxmade_update.py'
    assert sha(original)==staging['tools']['build_cumulative_maxmade_update.py']
    previous_staging_hash=sha(OUT/'staging-manifest.json')
    staging['tool_sources']={'build_cumulative_maxmade_update.py':'build-sources/build_cumulative_maxmade_update.py'}
    staging['documentation_template_sha256']=sha(ROOT/'tools/maxmade_release_readme.md')
    write(OUT/'staging-manifest.json',staging)
    screenshots=[]
    expected={f'{screen}-{state}.jpg' for screen in ('home','radio','media','phone') for state in ('before','after')}
    assert {p.name for p in (OUT/'screenshots').glob('*.jpg')}==expected
    for photo in sorted((OUT/'screenshots').glob('*.jpg')):
        with Image.open(photo) as image:
            image.verify()
        screenshots.append(dict(path=photo.relative_to(OUT).as_posix(),sha256=sha(photo)))
    manifest['staging_manifest_sha256']=sha(OUT/'staging-manifest.json')
    manifest['tool_sources']=staging['tool_sources']
    manifest['documentation_refresh']=dict(language='English',format='Categorized bullets and before/after UI previews',
        lgu_unchanged=True,lgu_sha256=HASH,integration_proof_unchanged=True,
        previous_staging_manifest_sha256=previous_staging_hash,screenshots=screenshots,
        original_build_script_sha256=sha(original),
        refresh_tool_sha256=sha(Path(__file__)),
        current_builder_sha256=sha(ROOT/'tools/build_cumulative_maxmade_update.py'),
        english_template_sha256=sha(ROOT/'tools/maxmade_release_readme.md'))
    write(OUT/'build-manifest.json',manifest)
    note=(ROOT/'tools/maxmade_release_readme.md').read_text(encoding='utf-8').format(revision=manifest['revision'])
    (OUT/'README.md').write_text(note,encoding='utf-8')
    names=('upgrade.lgu','README.md','SHA256SUMS.txt','build-manifest.json','staging-manifest.json','integration-proof.json')
    for name in names:shutil.copy2(OUT/name,PACKAGE/name)
    for name in ('screenshots','build-sources'):
        shutil.copytree(OUT/name,PACKAGE/name,dirs_exist_ok=True)
    for path in (REPO/'README.md',PACKAGE/'README.md',OUT/'README.md'):links(path)
    members=list(names)+[r['path'] for r in screenshots]+['build-sources/build_cumulative_maxmade_update.py']
    archive=Path(str(OUT)+'.zip')
    with zipfile.ZipFile(archive,'w',compression=zipfile.ZIP_DEFLATED) as zipped:
        for name in members:zipped.write(OUT/name,name)
    with zipfile.ZipFile(archive) as zipped:
        assert zipped.testzip() is None and set(zipped.namelist())==set(members)
        assert all(zipped.read(name)==(OUT/name).read_bytes() for name in members)
    assert sha(OUT/'upgrade.lgu')==sha(PACKAGE/'upgrade.lgu')==HASH
    assert sha(OUT/'integration-proof.json')==proof_hash
    assert sha(ROOT/'sources/MediaNav-to-Evolution-Upgrade/Upgrade_706MAX03_MAXmade/upgrade.lgu')==manifest['previous_lgu_sha256']
    print(json.dumps(dict(status='English documentation and screenshots verified',screenshots=len(screenshots),
        local_links_valid=True,zip_integrity_valid=True,zip_members=len(members),
        lgu_unchanged=True,lgu_sha256=HASH,zip_sha256=sha(archive)),indent=2))

if __name__=='__main__':main()
