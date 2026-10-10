"""Add approved artwork/color stores to the latest cumulative bugfix executable."""
import copy
import hashlib
import json
import struct
from pathlib import Path
import pefile
from build_home_theme import BASE, ROOT, REL, verify as verify_bmp
from patch_home_text_colors import PATCHES
from inspect_home_layout import trace as home_trace
from inspect_av_layouts import trace as av_trace, ENTRIES, CS, SIZES
from patch_shared_mapping_checks import reloc_records
from verify_usb_input_safety import relocated

APP='upgrade/Storage Card/System/AppMain.exe'

def sha(raw):return hashlib.sha256(raw).hexdigest()

def read_manifest(path):return json.loads(path.read_text(encoding='utf-8'))

def audit_development(directory):
    """Verify current bytes and the hash-linked history of completed fixes."""
    manifest=read_manifest(directory/'manifest.json')
    members={r['path']:r for r in manifest['members']}
    assert len(members)==1918 and len(manifest['members'])==1918
    assert {p.relative_to(directory/'payload').as_posix() for p in (directory/'payload').rglob('*') if p.is_file()}==set(members)
    for name,row in members.items():
        raw=(directory/'payload'/name).read_bytes()
        assert len(raw)==row['bytes'] and sha(raw)==row['sha256'],name
    indexed={sha(p.read_bytes()):p for p in (ROOT/'build').glob('*/manifest.json')}
    history=[];current=directory/'manifest.json';seen=set();pins={}
    while current not in seen:
        seen.add(current);data=read_manifest(current)
        for name,digest in data.get('tools',{}).items():
            assert sha((ROOT/'tools'/name).read_bytes())==digest,(current,name)
            pins[name]=digest
        evidence=[]
        for key in ('proof','exhaustive_hebrew_evidence','original_scalar_audit'):
            record=data.get(key)
            if isinstance(record,dict) and 'path' in record and 'sha256' in record:
                path=ROOT/record['path'];assert sha(path.read_bytes())==record['sha256'],path
                evidence.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=record['sha256']))
        rows={r['path']:r for r in data['members']};assert len(rows)==1918 and set(rows)==set(members)
        previous_digest=data.get('carried_forward_manifest_sha256')
        if previous_digest:
            previous_path=indexed[previous_digest];previous=read_manifest(previous_path)
            previous_rows={r['path']:r for r in previous['members']}
            actual_changes={n for n in rows if rows[n]['sha256']!=previous_rows[n]['sha256']}
            assert actual_changes==set(data['changed_from_development']),current
            for name in actual_changes:
                assert sha((current.parent/'payload'/name).read_bytes())==rows[name]['sha256']
                assert sha((previous_path.parent/'payload'/name).read_bytes())==previous_rows[name]['sha256']
        else:previous_path=None
        history.append(dict(staging=current.parent.name,manifest_sha256=sha(current.read_bytes()),evidence=evidence,
                            previous_manifest_sha256=previous_digest))
        if previous_path is None:break
        current=previous_path
    assert history[-1]['staging']=='updater-copy-safety-development-02'
    return manifest,dict(current_manifest_sha256=sha((directory/'manifest.json').read_bytes()),
                         history=history,tool_pins=pins,current_members_verified=1918)

def overlay_app(before,skin):
    proof=read_manifest(skin/'av-text-color-proof.json')
    manifest=read_manifest(skin/'manifest.json')
    assert sha((skin/'av-text-color-proof.json').read_bytes())==manifest['av_text_color_proof_sha256']
    assert proof['bounded_cases_verified']==106
    assert sha((ROOT/'analysis/firmware/av-layouts.json').read_bytes())==proof['layout_sha256']
    edits=[dict(va=hex(at),before=hex(old),after=hex(new),reason='White active home labels') for at,old,new in PATCHES]+proof['edits']
    original=(BASE/APP).read_bytes();skin_app=(skin/'payload'/APP).read_bytes()
    old_pe=pefile.PE(data=original);pe=pefile.PE(data=before);base=pe.OPTIONAL_HEADER.ImageBase
    output=bytearray(before);check_skin=bytearray(original);offsets=set();records=[]
    assert base==old_pe.OPTIONAL_HEADER.ImageBase
    for edit in edits:
        at=int(edit['va'],16);old=int(edit['before'],16).to_bytes(4,'little');new=int(edit['after'],16).to_bytes(4,'little')
        offset=pe.get_offset_from_rva(at-base);old_offset=old_pe.get_offset_from_rva(at-base)
        assert original[old_offset:old_offset+4]==old,(edit,'original mismatch')
        assert before[offset:offset+4]==old,(edit,'bugfix conflict')
        assert skin_app[old_offset:old_offset+4]==new,(edit,'skin mismatch')
        assert not offsets.intersection(range(offset,offset+4))
        offsets.update(range(offset,offset+4));output[offset:offset+4]=new;check_skin[old_offset:old_offset+4]=new
        records.append(dict(**edit,file_offset=offset))
    assert bytes(check_skin)==skin_app,'Unexpected unapproved skin executable change'
    # Five initializers move image-address instructions while scheduling colors.
    # Move each loader relocation with its unchanged instruction, preserving the
    # HIGHADJ companion and every unrelated cumulative relocation byte.
    moved={}
    for start in (0x891e8,0x9092c,0x99fc0,0x9f0a4,0xa4110):
        for delta in (0,4,8,12,20,24):
            source=start+delta;target=source+8
            if start==0x9092c and delta==24:target=source+12
            old_off=pe.get_offset_from_rva(source-base);new_off=pe.get_offset_from_rva(target-base)
            assert before[old_off:old_off+4]==output[new_off:new_off+4]
            moved[source-base]=target-base
    directory=pe.OPTIONAL_HEADER.DATA_DIRECTORY[5]
    table_offset=pe.get_offset_from_rva(directory.VirtualAddress)
    table=pe.get_data(directory.VirtualAddress,directory.Size);pos=0;relocation_edits=[]
    while pos<len(table):
        page,size=struct.unpack_from('<II',table,pos);cursor=pos+8
        while cursor<pos+size:
            entry=struct.unpack_from('<H',table,cursor)[0];kind=entry>>12;rva=page+(entry&4095)
            if kind and rva in moved:
                target=moved[rva];assert target&~4095==page and kind in (2,4)
                offset=table_offset+cursor;replacement=(kind<<12)|(target&4095)
                output[offset:offset+2]=struct.pack('<H',replacement)
                relocation_edits.append(dict(file_offset=offset,before=hex(entry),after=hex(replacement),
                                             source_va=hex(base+rva),target_va=hex(base+target),kind=kind))
            elif kind:
                assert not offsets.intersection(range(pe.get_offset_from_rva(rva),pe.get_offset_from_rva(rva)+4)),hex(base+rva)
            cursor+=4 if kind==4 else 2
        assert cursor==pos+size;pos+=size
    assert len(relocation_edits)==30
    result=bytes(output);restored=bytearray(result)
    for edit in records:restored[edit['file_offset']:edit['file_offset']+4]=int(edit['before'],16).to_bytes(4,'little')
    for edit in relocation_edits:
        offset=edit['file_offset'];restored[offset:offset+2]=int(edit['before'],16).to_bytes(2,'little')
    assert bytes(restored)==before
    code_changes=sum(before[i]!=result[i] for i in offsets)
    for edit in relocation_edits:offsets.update(range(edit['file_offset'],edit['file_offset']+2))
    assert {i for i,(a,b) in enumerate(zip(before,result)) if a!=b}<=offsets
    assert len(result)==len(before) and pefile.PE(data=result).OPTIONAL_HEADER.CheckSum==pe.OPTIONAL_HEADER.CheckSum
    original_records=reloc_records(pe);actual_records=reloc_records(pefile.PE(data=result))
    assert sorted(actual_records)==sorted((moved.get(rva,rva),kind,companion) for rva,kind,companion in original_records)
    load_deltas=(0x1000,0x10000,0x123000,0x500000)
    for delta in load_deltas:
        old_loaded=relocated(before,delta);new_loaded=relocated(result,delta);expected=bytearray(old_loaded)
        for edit in records:
            offset=edit['file_offset'];expected[offset:offset+4]=int(edit['after'],16).to_bytes(4,'little')
        for source,target in moved.items():
            old_offset=pe.get_offset_from_rva(source);new_offset=pe.get_offset_from_rva(target)
            expected[new_offset:new_offset+4]=old_loaded[old_offset:old_offset+4]
        expected[table_offset:table_offset+directory.Size]=result[table_offset:table_offset+directory.Size]
        assert bytes(expected)==new_loaded,hex(delta)
    print('Color relocation repair: 30 moved references; four alternate load-address comparisons passed',flush=True)
    return result,dict(before_sha256=sha(before),after_sha256=sha(result),edits=records,
                       changed_bytes=sum(a!=b for a,b in zip(before,result)),
                       color_instruction_changed_bytes=code_changes,relocation_edits=relocation_edits,
                       relocation_record_count=len(original_records),alternate_load_deltas=[hex(d) for d in load_deltas],
                       relocated_images_exactly_match_same_instruction_schedule=True,
                       exact_reversal_recovers_all_cumulative_bugfix_bytes=True,unrelated_relocations_unchanged=True)

def verify_home(before,after):
    scenarios=[]
    for ui,profile in ((0,0),(1,1),(1,3)):
        for eco in (0,1):
            for layout in (0,1):
                for smart in (False,True):
                    old=home_trace(ui,eco,layout,profile,smart,raw=before)
                    new=home_trace(ui,eco,layout,profile,smart,raw=after)
                    expected=copy.deepcopy(old)
                    for r in expected['controls']:
                        if r.get('event') in (1001,1002,1003,1004,1005,1006,1008):
                            r['colors']=[r['colors'][0],0xffffff,r['colors'][2],0xffffff]
                    assert new==expected,(ui,profile,eco,layout,smart)
                    scenarios.append(new)
    return dict(cases=len(scenarios),geometry_events_fonts_labels_preserved=True,scenarios=scenarios)

def verify_av(before,after):
    def normalize(case):
        result=copy.deepcopy(case);result.pop('machine_state',None)
        for r in result['controls']:
            r.pop('color_stores',None)
            if r.get('secondary_label'):r['secondary_label'].pop('color_stores',None)
        return result
    before_pe=pefile.PE(data=before);after_pe=pefile.PE(data=after);base=before_pe.OPTIONAL_HEADER.ImageBase
    for group,entries in ENTRIES.items():
        for entry in entries:
            current={i.address:i for i in CS.disasm(after_pe.get_data(entry-base,SIZES[entry]),entry)}
            for i in CS.disasm(before_pe.get_data(entry-base,SIZES[entry]),entry):
                if i.mnemonic.startswith(('b','j')):assert current[i.address].bytes==i.bytes
    count=0;changes=0;scenarios=[]
    for ui in (0,1):
        for group,entries in ENTRIES.items():
            for entry in entries:
                old=av_trace(entry,group,before,ui,capture_state=True)
                new=av_trace(entry,group,after,ui,capture_state=True)
                expect=normalize(old);memory=old['machine_state']['memory'].copy()
                triples=list(zip(old['controls'],new['controls'],expect['controls']))
                triples += [(a['secondary_label'],b['secondary_label'],c['secondary_label']) for a,b,c in triples[:] if a.get('secondary_label')]
                for a,b,c in triples:
                    if a.get('colors')==b.get('colors'):continue
                    assert a.get('colors') and b.get('colors') and a['colors'][0]==b['colors'][0] and a['colors'][2]==b['colors'][2]
                    for state in (1,3):
                        assert b['colors'][state] in (a['colors'][state],0xffffff)
                        if b['colors'][state]==a['colors'][state]:continue
                        assert a['colors'][state]==0;changes+=1
                        at=int(a['colors_address'],16)+state*4
                        if all(new['machine_state']['memory'].get(at+n)==(0xffffff>>(n*8))&255 for n in range(4)):
                            assert all(memory.get(at+n)==0 for n in range(4)) or all(memory.get(at+n)==(0xffffff>>(n*8))&255 for n in range(4))
                            for n in range(4):memory[at+n]=(0xffffff>>(n*8))&255
                    c['colors']=b['colors']
                assert expect==normalize(new),(hex(entry),ui,'constructor difference')
                assert old['machine_state']['registers']==new['machine_state']['registers'],(hex(entry),ui,'register difference')
                assert memory==new['machine_state']['memory'],(hex(entry),ui,'fixture memory difference')
                new.pop('machine_state');count+=1
                if ui==1:scenarios.append(new)
                if count%10==0:print(f'Combined AppMain: {count}/106 AV constructor cases passed',flush=True)
    assert count==106
    return dict(cases=count,allowed_color_changes=changes,branch_and_call_opcodes_identical=True,
                geometry_events_fonts_flags_preserved=True,registers_and_fixture_memory_preserved_except_color_slots=True,scenarios=scenarios)

def artwork(skin,development_manifest):
    manifest=read_manifest(skin/'manifest.json');development={r['path']:r for r in development_manifest['members']}
    original_inventory={r['path']:r for r in read_manifest(ROOT/'build/home-theme-development-07/manifest.json')['members']}
    assert len(manifest['members'])==1917
    changes=[]
    for row in manifest['members']:
        name=row['path'];raw=(skin/'payload'/name).read_bytes()
        assert len(raw)==row['bytes'] and sha(raw)==row['sha256'],name
        original=(BASE/name).read_bytes()
        if raw==original:continue
        if name==APP:continue
        assert name.startswith(REL.as_posix()+'/') and name.endswith('.bmp'),name
        assert development[name]['sha256']==sha(original),(name,'development resource changed')
        proof=verify_bmp(original,raw)
        changes.append(dict(path=name,sha256=sha(raw),bytes=len(raw),original_sha256=sha(original),verification=proof))
        if len(changes)%30==0:print(f'Approved native artwork: {len(changes)}/271 BMP contracts passed',flush=True)
    assert len(changes)==271
    return changes,dict(manifest_sha256=sha((skin/'manifest.json').read_bytes()),candidate=skin.name,
                        image_count=271,profile='M1',navigation_resources_excluded=True)
