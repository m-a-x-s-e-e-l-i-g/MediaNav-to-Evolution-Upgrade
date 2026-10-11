"""Finalize MAX07 AppMain with hash-bound retained label evidence and new rebases."""
import json
import struct
from pathlib import Path
import pefile
import patch_max07_labels as p
import verify_selected_label_contrast as proof
from patch_shared_mapping_checks import reloc_records


def build():
    raw=(p.MAX06/'payload'/p.labels.APP).read_bytes()
    candidate,recipe=p.patch(raw,visible_artwork=True)
    previous=p.ROOT/'build/max07-app-development-02'
    prior=(previous/'AppMain.exe').read_bytes()
    evidence=json.loads((previous/'verification.json').read_bytes())
    assert evidence['candidate_sha256']==p.sha(prior)
    old,new=pefile.PE(data=prior),pefile.PE(data=candidate)
    for at in recipe['helpers']:assert old.get_data(at-p.BASE,0x200)==new.get_data(at-p.BASE,0x200)
    assert old.get_data(recipe['lookup_va']-p.BASE,0x800)==new.get_data(recipe['lookup_va']-p.BASE,0x800)
    for site,_,_ in p.labels.HOOKS:assert old.get_data(site-p.BASE,8)==new.get_data(site-p.BASE,8)
    records=reloc_records(new)
    for delta in (0x1000,0x8000,0x10000,0x123000):
        moved=proof.relocated(candidate,delta);baseline=proof.relocated(raw,delta)
        allowed={i for e in recipe['edits'] for i in range(e['offset'],e['offset']+len(bytes.fromhex(e['before_hex'])))}
        assert all(a==b or i in allowed for i,(a,b) in enumerate(zip(baseline,moved)))
        # Every LA is an image pointer; the literal COLORREF has no relocations.
        art=recipe['artwork'];pc=art['address'];pointer_count=0
        rebased=pefile.PE(data=moved)
        for line in art['recipe']['source_assembly'].splitlines():
            line=line.split('#')[0].strip()
            if not line or line.endswith(':'):continue
            if line.startswith('la '):
                assert any(at==pc-p.BASE and kind==4 for at,kind,_ in records)
                pointer_count+=1;pc+=8
            else:
                if line=='lui a1, 0xaa':
                    assert not any(pc-p.BASE<=at<pc-p.BASE+8 for at,_,_ in records)
                    assert rebased.get_data(pc-p.BASE,8)==new.get_data(pc-p.BASE,8)
                pc+=4
        assert pointer_count==10,pointer_count
        d=new.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        rows=list(struct.iter_unpack('<5I',new.get_data(d.VirtualAddress,d.Size)))
        moved_rows=list(struct.iter_unpack('<5I',rebased.get_data(d.VirtualAddress,d.Size)))
        assert moved_rows==[tuple(x+delta if x else 0 for x in row) for row in rows]
    out=p.ROOT/'build/max07-app-development-03';out.mkdir(exist_ok=False)
    (out/'AppMain.exe').write_bytes(candidate)
    evidence.update(retained_behavior_evidence_sha256=p.sha((previous/'verification.json').read_bytes()),
                    label_helpers_lookup_and_hooks_exact=True,artwork_constant_and_pointer_rebases=4,
                    input_sha256=p.sha(raw),candidate_sha256=p.sha(candidate))
    for name,value in (('recipe',recipe),('verification',evidence)):
        (out/(name+'.json')).write_text(json.dumps(value,indent=2)+'\n')
    return dict(sha256=p.sha(candidate),bytes=len(candidate),output=str(out))


if __name__=='__main__':print(json.dumps(build(),indent=2))
