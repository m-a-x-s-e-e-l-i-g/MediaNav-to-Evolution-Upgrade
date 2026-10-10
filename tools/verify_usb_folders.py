"""Written MIPS traversal with explicit catalog, cancellation and Sleep fixtures."""
import hashlib
import json
import random
import struct
from pathlib import Path
from patch_usb_folders import ITER,CHECK,BASE_SHA
from verify_media_responsiveness import VM,parsed
from verify_usb_input_safety import relocated
from verify_wma_shuffle import invoke
from inspect_bt_pairing import put

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'build/usb-sorting-development-01/payload/upgrade/Storage Card/System/MgrUSB.exe'
OBJ,FOLDERS,DIALOG=0x47000000,0x48000000,0x49000000

class FolderVM(VM):
    def __init__(self,raw,ids,tracks,delta=0,count=None,buffer=FOLDERS):
        ranges=[(0x14720,0x14884),(0x14884,0x149e0),(ITER,ITER+0x300),
                (CHECK,CHECK+0x100),(0x3e780,0x3e7b0)]
        super().__init__(parsed(raw),[(a+delta,b+delta) for a,b in ranges])
        self.words={};self.ids=ids;self.tracks=tracks;self.delta=delta
        self.sleeps=[];self.dialogs=0;self.table_reads=0;self.record_reads=[]
        self.cancel_check=None;self.sleep_fault=None;self.null_dialog=False
        self.valid_count=len(ids) if count is None else count
        put(self,OBJ,bytes(0x3000));put(self,DIALOG,bytes(0x20))
        self.write(OBJ+0x38,buffer+delta if buffer==0x275c4 else buffer)
        self.write(OBJ+0x2750,self.valid_count&65535,2)
        for i,n in enumerate(ids):self.write(OBJ+0x40+i*2,n&65535,2)
        for n,value in tracks.items():self.write(FOLDERS+n*544+0x214,value&65535,2)
        self.hooks[0x231a4+delta]=self.dialog
        self.write(0x2f008+delta,0xf2000000);self.hooks[0xf2000000]=self.sleep
    def word(self,pc):
        if pc not in self.words:self.words[pc]=super().word(pc)
        return self.words[pc]
    def read(self,at,size=4):
        if OBJ+0x40<=at<OBJ+0x2750:
            assert at+size<=OBJ+0x40+max(0,min(len(self.ids),self.valid_count))*2,'Read outside live folder-order table'
            self.table_reads+=1
        if FOLDERS<=at<FOLDERS+5000*544:
            assert size==2 and (at-FOLDERS)%544==0x214
            self.record_reads.append((at-FOLDERS)//544)
        return super().read(at,size)
    def dialog(self,m):
        self.dialogs+=1
        if self.dialogs==self.cancel_check:self.write(DIALOG+0x18,1)
        return 0 if self.null_dialog else DIALOG
    def sleep(self,m):
        assert m.reg[4] in (0,1);self.sleeps.append(m.reg[4])
        if self.sleep_fault:self.sleep_fault(self,len(self.sleeps))
        return 0
    def select(self,current,direction=1,obj=OBJ,limit=3000000):
        return invoke(self,(0x14720 if direction==1 else 0x14884)+self.delta,
                      [obj,current&0xffffffff],limit=limit)

def expected(ids,tracks,current,direction):
    if not ids:return 0
    index=ids.index(current) if current in ids else 0
    for k in range(1,len(ids)+1):
        n=ids[(index+direction*k)%len(ids)]
        if n==-1:indexed=0
        elif 0<=n<5000:indexed=n
        else:
            if n==current:return current&0xffffffff
            continue
        if 0<tracks.get(indexed,0)<=5000:return n&0xffffffff
        if n==current:return current&0xffffffff
    return current&0xffffffff

def traversal(raw):
    previous=SOURCE.read_bytes();assert hashlib.sha256(previous).hexdigest()==BASE_SHA
    rng=random.Random(706);cases=0;old_pairs=0
    configs=[([-1,2,7],{0:1,2:0,7:5}),([7,4,1],{7:0,4:0,1:1}),
             ([2,8,4],{2:0,8:0,4:0}),([7],{7:2}),([7],{7:0}),([4,4,9],{4:0,9:1})]
    for _ in range(60):
        ids=rng.sample(range(1,80),rng.randrange(1,12));configs.append((ids,{n:rng.choice([0,0,1,3]) for n in ids}))
    for ids,tracks in configs:
        for current in [*ids,1234]:
            for direction in (1,-1):
                m=FolderVM(raw,ids,tracks)
                assert m.select(current,direction)==expected(ids,tracks,current,direction),(ids,tracks,current,direction)
                assert m.table_reads<=2*len(ids) and len(m.record_reads)<=len(ids)
                assert len(m.sleeps)<=2*len(ids);cases+=1
        # Baseline parity for ordinary forward traversal with known IDs.
        for current in ids[:2]:
            old=FolderVM(previous,ids,tracks);new=FolderVM(raw,ids,tracks)
            assert old.select(current)==new.select(current);old_pairs+=1
        # Both original directions agree when every folder is playable.
        full={max(0,n):2 for n in ids}
        for direction in (1,-1):
            old=FolderVM(previous,ids,full);new=FolderVM(raw,ids,full)
            assert old.select(ids[-1],direction)==new.select(ids[-1],direction);old_pairs+=1
    return dict(cases=cases+old_pairs,baseline_parity_cases=old_pairs,
                cyclic_order_root_and_unknown_current_retained=True,bounded_empty_folder_scan=True,
                selection_oracle_independent=True)

def failures(raw):
    cases=0
    for direction in (1,-1):
        for count in (0,-1,-32768,5001,32767):
            m=FolderVM(raw,[],{},count=count);assert m.select(7,direction)==0
            assert m.table_reads==0 and not m.record_reads and not m.sleeps;cases+=1
        for buffer in (0,0x275c4):
            m=FolderVM(raw,[7],{7:2},buffer=buffer);assert m.select(7,direction)==0
            assert not m.table_reads and not m.sleeps;cases+=1
        m=FolderVM(raw,[],{});assert m.select(7,direction,obj=0)==0;cases+=1
        m=FolderVM(raw,[7,9],{7:0,9:2});m.null_dialog=True
        assert m.select(7,direction)==0 and not m.table_reads;cases+=1
        for ids in ([7,5000,-2,32767,-32768,9],[7,-1,9]):
            m=FolderVM(raw,ids,{0:0,7:0,9:1});assert m.select(7,direction)==expected(ids,m.tracks,7,direction)
            assert set(m.record_reads)<={0,7,9};cases+=1
        for amount in (-1,0,5001,32767):
            m=FolderVM(raw,[7,9],{7:amount,9:1});assert m.select(9,direction)==9;cases+=1
        ids=[10,3,8,1,7];tracks={n:0 for n in ids};tracks[10]=1
        baseline=FolderVM(raw,ids,tracks);baseline.select(10,direction)
        for at in range(1,len(baseline.sleeps)+1):
            for fault in ('cancel','count','buffer'):
                m=FolderVM(raw,ids,tracks)
                def mutate(v,n,at=at,fault=fault):
                    if n==at:
                        if fault=='cancel':v.write(DIALOG+0x18,1)
                        elif fault=='count':v.write(OBJ+0x2750,0,2)
                        else:v.write(OBJ+0x38,0)
                m.sleep_fault=mutate
                assert m.select(10,direction)==0 and len(m.sleeps)==at;cases+=1
        for at in range(1,baseline.dialogs+1):
            m=FolderVM(raw,ids,tracks);m.cancel_check=at
            assert m.select(10,direction)==0 and m.dialogs==at;cases+=1
    return dict(cases=cases,cancellation_before_and_after_every_yield=True,
                null_empty_oversized_and_changed_catalogs_rejected=True,invalid_folder_ids_not_dereferenced=True,
                general_concurrent_atomicity_proven=False)

def original_defects(raw):
    previous=SOURCE.read_bytes();cases=0
    old=FolderVM(previous,[],{},count=0)
    try:old.select(7)
    except AssertionError as error:assert 'Read outside live folder-order table' in str(error)
    else:raise AssertionError('Original empty list must attempt invalid table read')
    assert FolderVM(raw,[],{}).select(7)==0;cases+=1
    old=FolderVM(previous,[7,9],{7:0,9:0})
    try:old.select(7,-1,limit=5000)
    except AssertionError:assert len(old.sleeps)>20
    else:raise AssertionError('Expected original unbounded backwards loop')
    m=FolderVM(raw,[7,9],{7:0,9:0});assert m.select(7,-1)==7 and len(m.sleeps)==3;cases+=1
    # The old backwards stop compares folder ID to table index, skipping a playable folder.
    ids=[8,7,1];tracks={8:1,7:0,1:0}
    assert FolderVM(previous,ids,tracks).select(1,-1)==1
    assert FolderVM(raw,ids,tracks).select(1,-1)==8;cases+=1
    return dict(cases=cases,original_empty_table_read_reproduced=True,
                original_backwards_nontermination_reproduced=True,original_early_stop_reproduced=True)

def callers(raw):
    from verify_usb_reliability import OBJ as PLAYER,STACK
    from verify_wma_shuffle import vm as shuffle_vm,Catalog,BUILD
    cases=0
    # Execute the complete existing previous-track selector through the real iterator.
    for ids,counts,first,current,want in [([8,7,1],{8:3,7:0,1:2},{8:0,7:3,1:3},1,2),
                                          ([7,1,8],{7:2,1:2,8:0},{7:0,1:2,8:4},7,3)]:
        m=FolderVM(raw,ids,counts)
        m.ranges.extend([(0x19564,0x196c4),(0x3fc00,0x3fc64)])
        put(m,PLAYER,bytes(0x3000));m.write(DIALOG+0x48,OBJ)
        m.hooks[0x209e0]=lambda v:(put(v,v.reg[4],bytes(8)) or 0)
        m.hooks[0x209d0]=lambda v:0
        m.hooks[0x132fc]=lambda v:current
        m.hooks[0x1355c]=lambda v:first[v.reg[5]]
        m.hooks[0x12ed8]=lambda v:counts[v.reg[5]]
        assert invoke(m,0x19564,[PLAYER,first[current],0])==want;cases+=1
    # Execute the original next-folder call site and following first/count selection.
    m=FolderVM(raw,[7,1,8],{7:2,1:3,8:0});m.ranges.append((0x1b0b0,0x1b0f4))
    m.write(DIALOG+0x48,OBJ);m.hooks[0x1355c]=lambda v:{7:0,1:2,8:5}[v.reg[5]]
    m.hooks[0x12ed8]=lambda v:{7:2,1:3,8:0}[v.reg[5]]
    m.reg[21]=7;m.reg[29]=STACK;m.run(0x1b0b0,{0x1b0f4})
    assert m.reg[16:19]==[1,2,4];cases+=1
    # Complete rewritten shuffle builder, using the actual next-folder implementation.
    for cancel in (False,True):
        m=shuffle_vm(raw);c=Catalog(m,{8:(0,3),2:(3,0),1:(3,2)})
        m.ranges.extend([(0x14720,0x14884),(ITER,ITER+0x300),(CHECK,CHECK+0x100)])
        del m.hooks[0x14720]
        put(m,OBJ,bytes(0x3000));m.write(OBJ+0x38,FOLDERS);m.write(OBJ+0x2750,3,2)
        for i,n in enumerate(c.ids):
            m.write(OBJ+0x40+2*i,n,2);m.write(FOLDERS+544*n+0x214,c.folders[n][1],2)
        from verify_usb_reliability import DIALOG as SHUFFLE_DIALOG
        m.write(SHUFFLE_DIALOG+0x48,OBJ);m.write(PLAYER+0x2916,0);m.write(PLAYER+0x291e,1)
        original_dialog=m.hooks[0x231a4]
        def get(v):
            if cancel and v.reg[31]==CHECK+0x30:v.write(SHUFFLE_DIALOG+0x18,1)
            return original_dialog(v)
        m.hooks[0x231a4]=get
        result=invoke(m,BUILD,[PLAYER])
        if cancel:
            assert result==0xffffffff and m.read(PLAYER+0xe4c)==m.read(PLAYER+0xe5c)==0
        else:
            assert result==0 and m.read(PLAYER+0xe4c)==5
            pointer=m.read(PLAYER+0xe5c);order=[m.read(pointer+4*i) for i in range(5)]
            assert order[0]==0 and set(order[:3])=={0,1,2} and set(order[3:])=={3,4}
        cases+=1
    return dict(cases=cases,previous_track_selector_executed=True,next_track_call_site_executed=True,
                shuffle_builder_uses_actual_iterator=True,cancellation_propagation_retained=True)

def retained_sorting(raw):
    import verify_usb_sorting as s
    from functools import cmp_to_key
    previous=SOURCE.read_bytes();a=parsed(previous);b=parsed(raw)
    for start,end in [(0x135f0,0x13630),(0x13d88,0x13f10),(0x16cd8,0x17468),(0x3d610,0x3d800)]:
        assert a.get_data(start-0x10000,end-start)==b.get_data(start-0x10000,end-start)
    checks=dict(table_parser=s.table_parser(raw),equivalence=s.equivalence(raw),integration=s.integration(raw),
                structure=dict(cases=1,all_previous_sorting_code_unchanged=True))
    # The original baseline was verified already and is carried in the pinned manifest.
    baseline=json.loads((SOURCE.parents[4]/'manifest.json').read_text())['readback_checks']['performance']
    rng=random.Random(705);names=[f'{rng.choice(["Björk","Album","Music","Track","Radio"])} {i:03} '+
                               'long filename with artist and title.mp3' for i in range(256)]
    m=s.SortVM(raw);comparisons=0
    def cmp(a,b):
        nonlocal comparisons
        comparisons+=1;return m.compare(a,b,callback=True)
    assert sorted(names,key=cmp_to_key(cmp))==sorted(names,key=s.key)
    metrics=dict(comparisons=comparisons,interpreted_steps=m.steps,mapper_calls=m.mapper_calls,
                 memset_bytes=m.zero_bytes,name_unit_reads=m.name_reads)
    assert metrics==baseline['new']
    checks['performance']=dict(cases=1,new_workload_rerun=True,metrics=metrics,
        original_baseline_carried_from_verified_manifest=True,native_timing_measured=False)
    return checks

def large_and_relocations(raw):
    cases=0;previous=SOURCE.read_bytes();results={}
    ids=list(range(5000));tracks={n:0 for n in ids};tracks[1]=1
    for direction in (1,-1):
        metrics={}
        for name,b in [('previous',previous),('new',raw)]:
            m=FolderVM(b,ids,tracks);result=m.select(4999,direction)
            assert result==1
            metrics[name]=dict(sleep1_calls=m.sleeps.count(1),sleep0_calls=m.sleeps.count(0),
                               table_reads=m.table_reads,record_reads=len(m.record_reads),interpreted_steps=m.steps)
        assert metrics['new']['sleep1_calls']<metrics['previous']['sleep1_calls']/25
        results['next' if direction==1 else 'previous']=metrics;cases+=1
    m=FolderVM(raw,ids,{n:0 for n in ids});assert m.select(32767,-1)==32767
    assert len(m.sleeps)==10000 and m.table_reads==10000;cases+=1
    for delta in (0x1000,0x10000,0x123000):
        moved=relocated(raw,delta)
        for direction in (1,-1):
            ids=[-1,7,4];tracks={0:1,7:0,4:2};m=FolderVM(moved,ids,tracks,delta)
            assert m.select(4,direction)==expected(ids,tracks,4,direction);cases+=1
        m=FolderVM(moved,[7],{7:1},delta,buffer=0x275c4);assert m.select(7)==0;cases+=1
    return dict(cases=cases,folders=5000,metrics=results,unknown_no_playable_max_visits=10000,
                relocated_bases=3,native_timing_measured=False,scheduler_is_fixture=True)

def structure(raw,recipe):
    old=SOURCE.read_bytes();p=parsed(raw);before=parsed(old)
    allowed=[(int(e['offset'],16),int(e['offset'],16)+e['bytes']) for e in recipe['edits']]
    for i in (3,5):
        off=before.OPTIONAL_HEADER.DATA_DIRECTORY[i].get_file_offset()+4;allowed.append((off,off+4))
    assert len(old)==len(raw)
    assert all(a==b or any(lo<=i<hi for lo,hi in allowed) for i,(a,b) in enumerate(zip(old,raw)))
    d=p.OPTIONAL_HEADER.DATA_DIRECTORY[3];data=p.get_data(d.VirtualAddress,d.Size)
    rows=[struct.unpack_from('<5I',data,i) for i in range(0,len(data),20)]
    assert all(a[1]<=b[0] for a,b in zip(rows,rows[1:]))
    assert (ITER,ITER+440,0,0,ITER+40) in rows and (CHECK,CHECK+168,0,0,CHECK+24) in rows
    assert all(next(r for r in rows if r[0]==n)[4]==n for n in (0x14720,0x14884))
    for delta in (0x1000,0x10000,0x123000):
        q=parsed(relocated(raw,delta));d=q.OPTIONAL_HEADER.DATA_DIRECTORY[3];data=q.get_data(d.VirtualAddress,d.Size)
        assert [struct.unpack_from('<5I',data,i) for i in range(0,len(data),20)]==[
            tuple(n+delta if n else 0 for n in r) for r in rows]
    return dict(cases=1,only_declared_code_tables_and_directory_sizes_changed=True,
                all_previous_helper_used_bytes_preserved=True,pdata_and_relocations_checked=True)

def verify(raw):
    results={}
    for name,fn in [('traversal',traversal),('failures',failures),('original_defects',original_defects),('callers',callers),
                    ('large_and_relocations',large_and_relocations)]:
        results[name]=fn(raw);print(name,results[name],flush=True)
    return results
