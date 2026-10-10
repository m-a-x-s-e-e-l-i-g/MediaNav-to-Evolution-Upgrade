"""Retain the peer/source routing contract while keeping the startup audio fix.

The first finished development attempted to publish local readiness through a
source-routing intent flag. Undo those two edits: successful later filter reopen
must not stay muted. Open/Start/dispatcher readiness/retry fixes remain identical.
"""
import copy
import hashlib
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent/'python-libs'))
import pefile

INPUT_HASH='75357cf39127631927bd40f4871d60dabf793ce436629465aa51ae32f5c8794c'
RESTORE={0x1aebc,0x1aeec}

def patch(raw,previous_recipe):
    assert hashlib.sha256(raw).hexdigest()==INPUT_HASH==previous_recipe['output_sha256']
    out=bytearray(raw);edits=[]
    for row in previous_recipe['edits']:
        if row['start'] not in RESTORE:continue
        at=row['offset'];before=bytes.fromhex(row['after_hex']);after=bytes.fromhex(row['before_hex'])
        assert raw[at:at+len(before)]==before
        out[at:at+len(after)]=after
        edits.append(dict(start=row['start'],end=row['end'],offset=at,before_hex=before.hex(),after_hex=after.hex()))
    assert {r['start'] for r in edits}==RESTORE
    result=bytes(out)
    old,new=pefile.PE(data=raw),pefile.PE(data=result)
    assert len(raw)==len(result) and old.FILE_HEADER.__pack__()==new.FILE_HEADER.__pack__()
    assert old.OPTIONAL_HEADER.__pack__()==new.OPTIONAL_HEADER.__pack__()
    for a,b in zip(old.sections,new.sections):
        assert a.__pack__()==b.__pack__()
        if a.Name.rstrip(b'\0')!=b'.text':assert a.get_data()==b.get_data()
    active=copy.deepcopy(previous_recipe)
    active['output_sha256']=hashlib.sha256(result).hexdigest()
    active['edits']=[r for r in active['edits'] if r['start'] not in RESTORE]
    active['assembly']=[r for r in active['assembly'] if r['start'] not in RESTORE]
    active['changed_bytes']=sum(a!=b for r in active['edits'] for a,b in zip(bytes.fromhex(r['before_hex']),bytes.fromhex(r['after_hex'])))
    return result,dict(input_sha256=INPUT_HASH,output_sha256=active['output_sha256'],edits=edits,
        changed_bytes=sum(a!=b for a,b in zip(raw,result)),active_recipe=active,
        source_routing_intent_preserved=True,native_executed=False)
