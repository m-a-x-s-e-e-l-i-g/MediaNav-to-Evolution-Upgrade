"""Join .pdata boundaries with disassembly candidates; labels remain hypotheses."""
from pathlib import Path
import bisect
import collections
import json
import re

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/"analysis/functions"


def main():
    modules=json.loads((ROOT/"analysis/corpus/modules.json").read_text(encoding="utf-8"))
    summary=[]
    label=re.compile(r"^[A-Za-z_]\w*(?:::\~?[A-Za-z_]\w*)+$")
    for module in modules:
        directory=ROOT/"analysis/disassembly"/("" if module["origin"]=="705md" else module["origin"])
        candidate_path=directory/(module["name"]+"-candidates.json")
        if not candidate_path.exists():
            summary.append({"id":module["id"],"status":"disassembly pending"});continue
        candidates=json.loads(candidate_path.read_text(encoding="utf-8"))
        assert candidates["sha256"]==module["sha256"], module["name"]
        fs=[dict(f, label_candidates=[], imports=[], direct_calls=[], indirect_calls=[], strings=[]) for f in module["functions"]]
        starts=[int(f["begin_va"],16) for f in fs]
        unmapped=[]
        def owner(va):
            n=bisect.bisect_right(starts,va)-1
            return fs[n] if n>=0 and va<int(fs[n]["end_va"],16) else None
        for export in module["exports"]:
            f=owner(int(module["image_base"],16)+int(export["rva"],16))
            if f and export["name"]:f["label_candidates"].append({"source":"export","name":export["name"]})
        for c in candidates["candidates"]:
            f=owner(int(c["va"],16))
            if f is None:
                if c["kind"] in ("direct_call","import_call","indirect_call"):unmapped.append(c)
                continue
            if c["kind"]=="string":
                f["strings"].append(c)
                if label.fullmatch(c["text"]):f["label_candidates"].append({"source":"debug string; may name a called helper", "name":c["text"],"xref_va":c["va"]})
            elif c["kind"]=="import_call":f["imports"].append(c)
            elif c["kind"]=="direct_call":f["direct_calls"].append(c)
            elif c["kind"]=="indirect_call":f["indirect_calls"].append(c)
        output=OUT/module["origin"];output.mkdir(parents=True,exist_ok=True)
        (output/(module["name"]+".json")).write_text(json.dumps({"module":module["id"],"sha256":module["sha256"],
            "scope":"Function boundaries from .pdata; labels and call edges are static candidates, not proved behavior",
            "functions":fs,"unmapped_calls":unmapped},ensure_ascii=False,indent=2),encoding="utf-8")
        named=sum(bool(f["label_candidates"]) for f in fs)
        counts=collections.Counter(c["symbol"].split("!",1)[1].split("@",1)[0] for f in fs for c in f["imports"])
        summary.append({"id":module["id"],"status":"static index generated; behavior open", "functions":len(fs),
                        "functions_with_label_candidates":named,"unmapped_calls":len(unmapped),
                        "indirect_call_candidates":sum(len(f["indirect_calls"]) for f in fs),"top_import_calls":counts.most_common(15)})
    OUT.mkdir(exist_ok=True)
    (OUT/"summary.json").write_text(json.dumps(summary,indent=2),encoding="utf-8")
    print("Indexed",sum("functions" in s for s in summary),"modules; pending",sum("functions" not in s for s in summary),flush=True)


if __name__=="__main__":main()
