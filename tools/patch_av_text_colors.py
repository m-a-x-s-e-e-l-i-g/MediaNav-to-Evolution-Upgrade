"""Cosmetic AV label stores; no branch/call changes. Verify bounded state equality."""
import copy
import hashlib
import json
from pathlib import Path
import pefile
from inspect_av_layouts import ROOT, ENTRIES, trace, CS, SIZES

def patch(raw):
    previous=json.loads((ROOT/'build/home-theme-development-07/manifest.json').read_text())
    member=next(m for m in previous['members'] if m['path'].endswith('/AppMain.exe'))
    assert hashlib.sha256(raw).hexdigest()==member['sha256']
    pe=pefile.PE(data=raw);base=pe.OPTIONAL_HEADER.ImageBase;output=bytearray(raw);edits={}
    def read(pc):return int.from_bytes(raw[pe.get_offset_from_rva(pc-base):pe.get_offset_from_rva(pc-base)+4],'little')
    def edit(pc,word,reason):
        before=read(pc)
        if word==before:return
        if pc in edits:assert edits[pc]['after']==hex(word),(hex(pc),edits[pc],hex(word))
        edits[pc]=dict(va=hex(pc),before=hex(before),after=hex(word),reason=reason)
        off=pe.get_offset_from_rva(pc-base);output[off:off+4]=word.to_bytes(4,'little')
    def with_register(word,reg):
        assert word>>26==43 and (word>>16)&31==0
        return (word&~(31<<16))|(reg<<16)
    layouts=json.loads((ROOT/'analysis/firmware/av-layouts.json').read_text())
    arrays={}
    for case in layouts['scenarios']:
        for r in case['controls']:
            filename=(r['filename'] or '').lower()
            if filename.startswith(('fm radio\\','media\\','phone\\')):
                for label in [r]+([r['secondary_label']] if r.get('secondary_label') else []):
                    if label.get('colors'):arrays[(case['entry'],label['colors_address'])]=label
    deferred=[]
    for key,r in arrays.items():
        targets=[i for i in (1,3) if r['colors'][i]==0]
        if not targets:continue
        stores=r['color_stores'];assert all(stores[i] for i in targets)
        if all(stores[i]['white_registers'] for i in targets):
            for i in targets:
                st=stores[i];edit(int(st['pc'],16),with_register(int(st['word'],16),st['white_registers'][0]),'Use existing white register for active label')
        else:deferred.append((key,r,targets))
    # Initializer-local store scheduling: move the two active-color stores to
    # immediately after the normal white store, while its register is live.
    # Five arrays have a branch between stores; its address and opcode stay exact.
    for (entry,address),r,targets in deferred:
        stores=r['color_stores'];normal=stores[0];reg=normal['old_register'];start=int(normal['pc'],16)
        bad=[int(stores[i]['pc'],16) for i in targets]
        if min(bad)>start:
            end=max(bad);pcs=list(range(start+4,end+4,4));words=[read(pc) for pc in pcs]
            assert len(targets)==2 and all(read(pc)>>26==43 for pc in bad)
            instructions=list(CS.disasm(pe.get_data(start+4-base,end-start),start+4))
            branches=[i for i in instructions if i.mnemonic.startswith('b')]
            assert len(branches)<=1
            scheduled=[with_register(read(int(stores[i]['pc'],16)),reg) for i in targets]
            scheduled += [read(pc) for pc in pcs if pc not in bad]
            if branches:
                branch=branches[0];index=pcs.index(branch.address);newindex=scheduled.index(read(branch.address))
                assert newindex==index+1 and newindex==len(scheduled)-1
                scheduled[index],scheduled[newindex]=scheduled[newindex],scheduled[index]
            for pc,word in zip(pcs,scheduled):edit(pc,word,'Schedule active-color stores while normal white register is live')
        else:
            # Source dropdowns write pressed black before completing white ORI.
            first=min(bad);white_ori=int(stores[0]['pc'],16)-8
            assert read(white_ori)>>26==13 and ((read(white_ori)>>16)&31)==reg
            assert white_ori>first
            edit(first,read(white_ori),'Complete white constant before pressed-color store')
            edit(white_ori,with_register(read(first),reg),'Store pressed label white')
            for i in targets:
                pc=int(stores[i]['pc'],16)
                if pc==first:continue
                st=stores[i]
                if st['white_registers']:edit(pc,with_register(read(pc),st['white_registers'][0]),'Store selected label white')
                else:
                    # Popup: r8 is repurposed for width immediately after colors.
                    clobber=int(stores[2]['pc'],16)+4
                    assert read(clobber)>>26==9 and (read(clobber)>>16)&31==reg
                    edit(clobber,with_register(read(pc),reg),'Store selected label before width constant')
                    edit(pc,read(clobber),'Retain width constant and final register value')
    after=bytes(output)
    # Explicitly disallow any control-flow instruction difference.
    for group,entries in ENTRIES.items():
        for entry in entries:
            original=list(CS.disasm(pe.get_data(entry-base,SIZES[entry]),entry))
            changed=pefile.PE(data=after)
            current={i.address:i for i in CS.disasm(changed.get_data(entry-base,SIZES[entry]),entry)}
            for i in original:
                if i.mnemonic.startswith(('b','j')):assert current[i.address].bytes==i.bytes
    cases=[];checked=0;allowed_changes=0
    def normalize(case):
        result=copy.deepcopy(case);result.pop('machine_state',None)
        for r in result['controls']:
            r.pop('color_stores',None)
            if r.get('secondary_label'):r['secondary_label'].pop('color_stores',None)
        return result
    for ui in (0,1):
        for group,entries in ENTRIES.items():
            for entry in entries:
                before=trace(entry,group,raw,ui,capture_state=True)
                current=trace(entry,group,after,ui,capture_state=True)
                expect=normalize(before);expected_memory=before['machine_state']['memory'].copy()
                triples=list(zip(before['controls'],current['controls'],expect['controls']))
                triples += [(old['secondary_label'],new['secondary_label'],expected['secondary_label']) for old,new,expected in triples[:] if old.get('secondary_label')]
                for old,new,expected in triples:
                    if old.get('colors')!=new.get('colors'):
                        assert old.get('colors') and new.get('colors')
                        assert old['colors'][0]==new['colors'][0] and old['colors'][2]==new['colors'][2]
                        for i in (1,3):
                            assert new['colors'][i] in (old['colors'][i],0xffffff)
                            if new['colors'][i]!=old['colors'][i]:
                                assert old['colors'][i]==0;allowed_changes+=1
                                at=int(old['colors_address'],16)+i*4
                                # The initializer may reuse a stack color array
                                # for later geometry. Only update a color slot
                                # that still contains the changed color at stop.
                                if all(current['machine_state']['memory'].get(at+byte)==(0xffffff>>(byte*8))&255 for byte in range(4)):
                                    assert all(expected_memory.get(at+byte)==0 for byte in range(4)) or all(expected_memory.get(at+byte)==(0xffffff>>(byte*8))&255 for byte in range(4)),(hex(entry),ui,hex(at))
                                    for byte in range(4):expected_memory[at+byte]=(0xffffff>>(byte*8))&255
                        expected['colors']=new['colors']
                assert expect==normalize(current),(hex(entry),ui,'constructor mismatch')
                assert before['machine_state']['registers']==current['machine_state']['registers'],(hex(entry),ui,'register mismatch')
                differences=[(hex(at),expected_memory.get(at),current['machine_state']['memory'].get(at)) for at in set(expected_memory)|set(current['machine_state']['memory']) if expected_memory.get(at)!=current['machine_state']['memory'].get(at)]
                assert not differences,(hex(entry),ui,'memory mismatch',differences[:20])
                current.pop('machine_state');checked+=1
                if ui==1:cases.append(current)
                print('Verified',group,hex(entry),'profile',ui,flush=True)
    assert len(raw)==len(after) and checked==106
    return after,dict(before_sha256=hashlib.sha256(raw).hexdigest(),after_sha256=hashlib.sha256(after).hexdigest(),
        layout_sha256=hashlib.sha256((ROOT/'analysis/firmware/av-layouts.json').read_bytes()).hexdigest(),
        edits=list(sorted(edits.values(),key=lambda x:int(x['va'],16))),changed_bytes=sum(a!=b for a,b in zip(raw,after)),
        bounded_cases_verified=checked,allowed_color_changes=allowed_changes,scenarios=cases,
        constructor_geometry_events_fonts_flags_identical=True,registers_and_fixture_memory_identical_except_color_slots=True,
        branch_and_call_opcodes_identical=True,native_execution=False,hardware_tested=False)

if __name__=='__main__':
    raw=(ROOT/'build/home-theme-development-07/payload/upgrade/Storage Card/System/AppMain.exe').read_bytes()
    after,proof=patch(raw)
    target=ROOT/'build/av-text-color-proof.json';target.write_text(json.dumps(proof,indent=2)+'\n')
    print(len(proof['edits']),proof['changed_bytes'],proof['bounded_cases_verified'])
