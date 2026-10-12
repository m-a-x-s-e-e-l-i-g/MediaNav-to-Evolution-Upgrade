"""Independent mutation boundaries, unwind ownership and helper relocation audit."""
import json
import struct
import build_max14 as p
import pefile
from patch_shared_mapping_checks import reloc_records
from verify_usb_input_safety import relocated
from verify_bt_cover_layout import moved_words

def audit():
    before=(p.BASELINE/'payload'/p.APP).read_bytes()
    after=(p.OUT/'payload'/p.APP).read_bytes()
    recipe=json.loads((p.OUT/'recipe.json').read_bytes())
    old,new=pefile.PE(data=before),pefile.PE(data=after)
    allowed=set()
    for e in recipe['edits']:allowed.update(range(e['offset'],e['offset']+len(bytes.fromhex(e['after_hex']))))
    pd,rd=(old.OPTIONAL_HEADER.DATA_DIRECTORY[n] for n in (3,5))
    for d in (pd,rd):allowed.update(range(d.get_file_offset(),d.get_file_offset()+8))
    for name in ('CheckSum','SizeOfImage','SizeOfCode'):
        off=old.OPTIONAL_HEADER.get_field_absolute_offset(name);allowed.update(range(off,off+4))
    for name in ('Misc_VirtualSize','SizeOfRawData'):
        off=old.sections[-1].get_field_absolute_offset(name);allowed.update(range(off,off+4))
    start=old.get_offset_from_rva(pd.VirtualAddress)
    assert all(a==b or i in allowed for i,(a,b) in enumerate(zip(before[:start],after[:start])))
    # Each write is guarded against the pinned complete MAX13 input.
    for e in recipe['edits']:
        at=e['offset'];b=bytes.fromhex(e['before_hex']);a=bytes.fromhex(e['after_hex'])
        assert before[at:at+len(b)]==b and after[at:at+len(a)]==a
    expected=[]
    old_rows=list(struct.iter_unpack('<5I',old.get_data(pd.VirtualAddress,pd.Size)))
    new_pd=new.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    new_rows=list(struct.iter_unpack('<5I',new.get_data(new_pd.VirtualAddress,new_pd.Size)))
    assert len(new_rows)==len(old_rows)+4
    replaced={r['address'] for r in recipe['routines']}
    assert [r for r in old_rows if r[0] not in replaced]==[r for r in new_rows if r[0] not in replaced]
    rebases=[]
    for delta in (0x1000,0x8000,0x123000):
        moved=pefile.PE(data=relocated(after,delta))
        for row in recipe['routines']:
            r=dict(row,raw=new.get_data(row['address']-p.BASE,row['capacity']))
            assert moved.get_data(row['address']-p.BASE,row['capacity'])==moved_words(r,delta),(hex(row['address']),delta)
            assert set(map(tuple,row['relocations']))<=set(reloc_records(new))
        # Read-only caption strings and lookup bytes are literals, not pointers.
        for at,size in ((p.STRINGS,0x400),(0x33fa00,0x200)):
            assert new.get_data(at-p.BASE,size)==moved.get_data(at-p.BASE,size)
        rebases.append(delta)
    result=dict(app_sha256=p.sha(after),before_sha256=p.sha(before),mutation_boundaries_pass=True,
                all_other_unwind_rows_retained=True,helpers=len(recipe['routines']),new_function_rows=4,
                literal_banks_not_relocated=True,helper_rebase_deltas=rebases,native_executed=False)
    (p.OUT/'image-audit.json').write_text(json.dumps(result,indent=2)+'\n')
    return result

if __name__=='__main__':print(json.dumps(audit(),indent=2))
