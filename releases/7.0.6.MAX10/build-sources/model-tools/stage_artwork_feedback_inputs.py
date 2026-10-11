"""Compose guarded feedback repairs into all 1,918 retained MAX05 members.

This is input staging for the artwork integration, not a working-artwork LGU.
No container tool runs; no firmware, repository remote or existing build changes.
"""
import argparse
import hashlib
import json
from pathlib import Path

from build_max05_candidate import tree, RUNTIME_SHA, USB, VERSION
from release_payload import ROOT, PLAN, plan_at
from patch_aha_disable import patch as aha
from patch_ui_runtime_labels import patch as labels
from patch_bt_metadata_status import patch as metadata
from patch_bt_cover_attribute import patch as attribute
from patch_bt_pcm_bursts import patch as bursts

BLUE='upgrade/Storage Card/System/Blue.exe'
APP='upgrade/Storage Card/System/AppMain.exe'
LGU_SHA='ac5a6abc4d42a95fb1485150f4235bd9ab8f655465c3bc9eb22f4d53db8be51d'


def digest(raw):return hashlib.sha256(raw).hexdigest()


def expected_members():
    previous=plan_at(PLAN)
    expected={r['path']:dict(bytes=r['after_bytes'],sha256=r['after_sha256']) for r in previous['members']}
    assert len(expected)==1918
    expected[USB]=dict(expected[USB],sha256=RUNTIME_SHA)
    expected[VERSION]=dict(bytes=len(b'7.0.6.MAX05'),sha256=digest(b'7.0.6.MAX05'))
    return expected


def compose(raw,patches):
    out=bytearray(raw);used=set();recipes=[]
    for name,fn in patches:
        candidate,recipe=fn(raw)  # Every component checks the same original.
        assert len(candidate)==len(raw)
        changed={i for i,(a,b) in enumerate(zip(raw,candidate)) if a!=b}
        if changed&used:raise ValueError('Component edits overlap: '+name)
        for i in changed:out[i]=candidate[i]
        used|=changed;recipes.append(dict(component=name,recipe=recipe))
    return bytes(out),dict(before_sha256=digest(raw),after_sha256=digest(out),
                           changed_bytes=len(used),components=recipes)


def stage(baseline,out):
    baseline,out=baseline.resolve(),out.resolve()
    if out.exists():raise FileExistsError('Use a fresh output')
    if not out.is_relative_to(ROOT/'build') or out==ROOT/'build':
        raise ValueError('Output must be a fresh child of the ignored build directory')
    if out.is_relative_to(baseline) or baseline.is_relative_to(out):
        raise ValueError('Input and output must be separate')
    expected=expected_members();tree(baseline,expected)
    app,app_recipe=compose((baseline/APP).read_bytes(),[('active-labels',labels),('aha-gate',aha)])
    blue,blue_recipe=compose((baseline/BLUE).read_bytes(),[('metadata-final-status',metadata),
                            ('pcm-burst-reserve',bursts),('attribute-8-serialization',attribute)])
    replacements={APP:app,BLUE:blue}
    rows=[]
    for name,old in sorted(expected.items()):
        after=replacements.get(name)
        new=old if after is None else dict(bytes=len(after),sha256=digest(after))
        rows.append(dict(path=name,before=old,after=new))
    changed=[r['path'] for r in rows if r['before']!=r['after']]
    assert changed==[APP,BLUE]
    out.mkdir(parents=True)
    for name in expected:
        target=out/'payload'/name;target.parent.mkdir(parents=True,exist_ok=True)
        target.write_bytes(replacements[name] if name in replacements else (baseline/name).read_bytes())
    tree(out/'payload',{r['path']:r['after'] for r in rows});tree(baseline,expected)
    sources=['stage_artwork_feedback_inputs.py','patch_ui_runtime_labels.py','patch_aha_disable.py',
             'patch_bt_metadata_status.py','patch_bt_pcm_bursts.py','patch_bt_cover_attribute.py']
    report=dict(schema=1,kind='COMPLETE ARTWORK INTEGRATION INPUTS',baseline_revision='7.0.6.MAX05',
                baseline_lgu_sha256=LGU_SHA,members=rows,member_count=len(rows),changed_members=changed,
                retained_members=1916,recipes={APP:app_recipe,BLUE:blue_recipe},
                source_pins={n:digest((ROOT/'tools'/n).read_bytes()) for n in sources},
                lgu_built=False,artwork_enabled=False,published=False,hardware_tested=False,
                limits=['Feedback repairs and dormant attribute serializer only',
                        'Discovery/channel task/native image publication and complete feature binding are still missing',
                        'Existing MAX05 version and original LGU remain unchanged; this directory is not an installable upgrade'])
    (out/'manifest.json').write_bytes((json.dumps(report,indent=2)+'\n').encode())
    return report


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--baseline',type=Path,required=True);p.add_argument('--out',type=Path,required=True)
    a=p.parse_args();r=stage(a.baseline,a.out)
    print(json.dumps(dict(members=r['member_count'],retained_members=r['retained_members'],
                          changed_members=r['changed_members'],lgu_built=False,artwork_enabled=False)))
